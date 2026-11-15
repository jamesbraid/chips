# Source index

Every openly published source the project reads, in one place. Submodules sit under `references/code/` and are
pinned to the commit shown; they are shallow (`shallow = true` in `.gitmodules`), so
`git submodule update --init --depth 1 -- references/code/NAME` fetches only that commit. Initialise what you need: all of them
together are over ten gigabytes. Everything here is cited by file and version, never copied, and a driver is a
driver author's naming, not a hardware measurement (see [../published-sources.md](published-sources.md)).

## Submodules

| Path | Project | Pin | Public URL | What it covers and why |
|---|---|---|---|---|
| `linux` | Linux (current) | `c339f4010dea` | https://github.com/torvalds/linux | `arch/mips/sgi-ip27`, `sgi-ip30`, `sgi-ip32`, `arch/mips/include/asm/sn`, `arch/mips/pci/pci-xtalk-bridge.c` (Bridge, XBridge, PIC and TIOCP as one driver), `drivers/mfd/ioc3.c`, the IOC3 network, serial and keyboard drivers, `drivers/video/fbdev/gbefb.c`, `drivers/scsi/qla1280.c` and its header (the ISP1040 SCSI adapter on the BaseIO). The mainstream reading of Hub, HEART, Xbow, the Bridge family, IOC3, CRIME, MACE, GBE and the ISP1040. |
| `linux-5.3` | Linux v5.3 | `4d856f72c10e` | https://github.com/torvalds/linux | The last release with `arch/ia64/sn` (SN2: SHub and TIO register headers `shub_mmr.h`, `shubio.h`, `pic.h`, `tiocp.h`, `tioca.h`, `tioce.h`; the `pcibr` PCI provider; `sn_hwperf`; the `sgi-xp` partitioning driver). Current Linux deleted all of it with the ia64 port; the headers it carries are the only open description of the SHub and TIO side of the Bedrock family. |
| `linux-2.5.40` | Linux v2.5.40, from the kernel's historical repository | `7570df54ef8c` | https://git.kernel.org/pub/scm/linux/kernel/git/history/history.git | The first SN1 ia64 code (`arch/ia64/sn/io`: Xbow, Bridge, Hub and router helpers, `include/asm-ia64/sn`) and the 64-bit MIPS IP27 port (`arch/mips64/sgi-ip27`, `include/asm-mips64/sn`) before the trees were reorganised. Current Linux dropped SN1 and the early Hub headers. |
| `linux-2.4.37` | Linux v2.4.37, from a mirror of the linux-mips history | `e0dbf803698f` | https://github.com/xtreamerdev/linux-mips | The 2.4 IP27 code (`arch/mips/sgi-ip27`), the Hub headers under `include/asm-mips64/sn`, the 2.4 IOC3 network driver and the 2.4 SN ia64 tree. The mirror also holds the linux-mips branches and tags back to 1.x, which the canonical kernel.org trees do not. |
| `linux-ip30` | Out-of-tree Octane (IP30) port against Linux 3.6 | `bff2b6daa1d6` | https://github.com/jaaron/linux-mips-ip30 | `arch/mips/sgi-ip30` and its PCI glue as the linux-mips community carried it before the mainline port: an independent reading of HEART, Xbow and the PCI Bridge for the Octane. Branch `ip30-3.6`. |
| `openbsd` | OpenBSD | `7011342f6a72` | https://github.com/openbsd/src | `sys/arch/sgi/xbow` (`xbridgereg.h`, `xbow.c`, `xbridge.c`, `xheart.c`, `xheartreg.h`, `hub.h`, `widget.h`), `localbus` (CRIME, MACE, interrupt controllers), `hpc`, and the man pages. Origin (IP27), Octane (IP30) and Bedrock-class (IP35) machines. `sys/dev/ic/qlw.c` and `qlwreg.h` (the QLogic ISP1040 driver, its mailbox and IOCB definitions) and `sys/dev/pci/qlw_pci.c` (its PCI revision table). |
| `netbsd` | NetBSD | `0747dc050541` | https://github.com/NetBSD/src | `sys/arch/sgimips`: CRIME and MACE support and the O2 PCI and ISA glue, `ioc` and `xio` directories. `sys/dev/ic/isp.c` and `ispmbox.h`: the ISP family driver and its mailbox table, read for the ISP1040. |
| `linux-sn2` | Linux v7.3-rc3 with SN2 restored (community tree, tag `v7.3-rc3-epic1-sn2-gpu`) | `69571599c577` | https://github.com/nsafran1217/linux-sn2 | The EPIC tree below plus a patch set that restores SN2 (Altix and Prism) support, the `arch/ia64/sn` code `linux-5.3` is the last mainline release to carry, on a current kernel; the `-gpu` tag adds Prism graphics-card work. Supports the SN2 pages under `platforms/sn2/` and `devices/shub*`, `tio*` and `pic`, as a later reading of the `linux-5.3` code. Licence: GPL-2.0 with the Linux syscall exception. A community patch set: it shows what a driver author needed on real Altix and Prism hardware, not a hardware measurement. |
| `linux-ia64` | EPIC, the community Linux tree that keeps ia64 alive (branch `master-epic`) | `076c06dc04ba` | https://github.com/linux-ia64/linux-ia64 | Mainline `arch/ia64` after its removal in 6.7: the architecture code (`kernel/`, `mm/`, `include/asm/`: PAL and SAL calls, EFI runtime, the region and TLB set-up) that the `linux-sn2` machine code sits on. Read it for how the kernel reaches SAL and PAL on SN2 firmware. Licence: GPL-2.0 with the Linux syscall exception. |
| `ski` | Ski, HP's IA-64 instruction-set simulator (fork) | `dfc2902ea142` | https://github.com/trofi/ski | An independent IA-64 implementation: instruction semantics and the firmware-call environment a simulated IA-64 program sees. Used only to confirm how an IA-64 instruction or firmware call behaves when reading the SN2 PROM images; it models no SN2 hardware. Licence: GPL-2.0. |
| `elilo` | ELILO 3.16, the IA-64 EFI boot loader (git conversion of the CVS history) | `4e5817767696` | https://github.com/spinl0ck/elilo | The EFI-to-kernel handoff SN2 kernels used: how the loader finds the kernel, builds the boot parameters and hands over to the kernel entry (`ia64/`, `fs/`, `elilo.c`). Supports the pages that follow the SN2 boot path from the PROM to the kernel. Licence: GPL-2.0 or later. Upstream (SourceForge) is CVS and no git mirror carries release tags; this conversion carries the history. |
| `edk2` | EDK II, the UEFI reference firmware, at the last commit with IPF (Itanium) architecture code | `ba6037f8331d` | https://github.com/tianocore/edk2 | The IPF code before its removal: `MdePkg/Include/Ipf/` (`ProcessorBind.h`, `IpfMacro.i`), `MdePkg/Library/BaseLib/Ipf/` (PAL, SAL and EFI-runtime assembly), and the IPF parts of `BaseCpuLib`, `BaseSynchronizationLib`, `BasePeCoffLib` and the SAL libraries. The removal landed in `3cb0a311cb` (2018-07-02), between `edk2-stable201808` and `edk2-stable201811`. Licence: BSD-2-Clause. |
| `edk` | EDK I, the original EFI Development Kit (SVN history converted to git, branch `master`) | `321b15a55b94` | https://github.com/tianocore/edk | The IPF tree of EDK I at its last commit: `Foundation/Include/Ipf/`, `Foundation/Library/EdkIIGlueLib/Library/BaseLib/Ipf/` (access assembly), and the IPF platform, PEI and runtime code under `Foundation/` and `Sample/`. Pinned at the tip, 2010-05-27. Licence: BSD-3-Clause (`License.txt`). |
| `gnu-efi` | gnu-efi, the GNU EFI development library (SourceForge upstream, branch `master`) | `74bd9b60ba4b` | https://git.code.sf.net/p/gnu-efi/code | The IA-64 build and runtime support: `gnuefi/crt0-efi-ia64.S`, `gnuefi/reloc_ia64.S`, `gnuefi/elf_ia64_efi.lds`, `inc/ia64/` (EFI and SAL/PAL headers) and `lib/ia64/` (PAL and SAL calls, setjmp, platform initialisation). Pinned at the tip, 2024-03-22 (3.0.18). Licence: GPL-2.0-or-later OR BSD-3-Clause (`LICENSE`). |
| `gxemul` | GXemul (mirror) | `234a181a1711` | https://github.com/retroprom/gxemul | Device models for the O2 (`dev_sgi_ip32.c`: CRIME, MACE), the Octane (`dev_sgi_ip30.c`) and GBE (`dev_sgi_gbe.c`). An independent model to compare a reading against, never a fact source. |
| `mame` | MAME | `803a05bb5090` | https://github.com/mamedev/mame | `src/mame/sgi`: `crime.cpp`, `mace.cpp` and `o2.cpp` for the O2, the earlier SGI memory and I/O controllers (`mc.cpp`, `hpc3.cpp`, `ioc2.cpp`). Independent model, same caveat. |
| `arcboot` | arcboot | `15151b5e144d` | https://github.com/agx/arcboot | A published boot loader for IP22 and IP32 that calls the ARCS firmware interface (`arclib`): how a loader finds the machine through the PROM. |
| `irix-657m-src` | calmsacibis995, public IRIX 6.5.7m source tree | `822f4fcb9952` | https://github.com/calmsacibis995/irix-657m-src | The IRIX source the evidence order cites first, by path in the tree. An older release than the 6.5.30 and 6.5.22 binaries: a hint for the shipped images, never a fact for them on its own. |
| `m2c` | m2c (MIPS decompiler, fork with N32 support) | `b3e0876aca1c` | https://github.com/techomancer/m2c | Tool, not a hardware source: decompiles MIPS routines for the census. |
| `spimdisasm` | spimdisasm | `4b5d4c68eeb9` | https://github.com/Decompollaborate/spimdisasm | Tool, not a hardware source: MIPS disassembly used by the tools. |

Pins match the sibling repositories (`gr4`, `odsy`, `kona`, `crime`) wherever they carry the same tree:
`m2c`, `spimdisasm`, `netbsd`, `openbsd`, `gxemul` and `mame`. `linux-sn2`, `linux-ia64`, `ski` and `elilo` are the IA-64 trees: they are large or old, `tools/setup-clone.sh` leaves them alone like the other trees, and `tools/setup-clone.sh --submodules "linux-sn2"` (or `git submodule update --init --depth 1 -- references/code/linux-sn2`) fetches one on demand. `--submodules all` takes them with everything else. `edk2`, `edk` and `gnu-efi` are the EFI firmware trees with IA-64 code and are left out the same way; `--submodules "edk2"` fetches one. `linux` takes the pin the `crime` repository uses.
The `linux-*` entries are separate submodules of different releases because each holds code that a newer one
has dropped; use `linux` first.

## Recorded by URL only

Not vendored: the upstream is gone, is a tarball, or duplicates code that a submodule above already carries.

| Title | Project | Public URL | What it covers | Why it is not a submodule |
|---|---|---|---|---|
| arcload 0.5 | linux-mips community | https://www.linux-mips.org/pub/linux/mips/people/skylark/arcload-0.5.tar.bz2 ; Debian source: https://sources.debian.org/src/arcload/ ; wiki: https://web.archive.org/web/20221002210224/https://www.linux-mips.org/wiki/ARCLoad | An ARCS boot loader for IP27, IP28, IP30 and IP32: how a loader walks the firmware's component tree and memory descriptors on those boards. | Tarball on a dead site; the Debian source package keeps it. No upstream repository. |
| linux-mips.org wiki pages IP27, IP30, IP35 | linux-mips community | https://web.archive.org/web/2022/https://www.linux-mips.org/wiki/IP27 , https://web.archive.org/web/2022/https://www.linux-mips.org/wiki/IP30 , https://web.archive.org/web/2022/https://www.linux-mips.org/wiki/IP35 | Port status and notes for each board: what boots, what is missing, which trees to use. | Dead site, wiki pages. Wayback snapshots only. |
| IP27 patch set for 2.4 | linux-mips community | ftp://ftp.linux-mips.org/pub/linux/mips/people/ralf/ip27/ | The original IP27 port patches against 2.4. | Dead server. `linux-2.4.37` carries the merged result. |
| IP35 (Origin 350, Fuel, Tezro) Linux tree | linux-mips community | http://git.linux-mips.org/cgit/nyef/linux-ip35/ (branches `sgi-ip35-v4.2-2015-10-24`, `v4.2-ioc-changes`) | An IP35 port against 4.2: Bedrock-hub node handling, IOC4 serial, Bridge-family PCI for Fuel, Tezro and Origin 350. The only open IP35 code found. | Server is gone and no mirror was found. |
| Octane Linux patch set | Gentoo MIPS project | https://github.com/gentoo/gentoo/tree/master/sys-kernel/mips-sources and https://forums.gentoo.org/viewtopic-t-694837.html | The `ip30` USE flag applied an out-of-tree Octane patch (HEART, Xbow, Bridge, ImpactSR and Odyssey drivers) to later kernels. | The patches ship as distfile tarballs with no stable URL; `linux-ip30` is the same lineage at one version. |
| SGI ProPack source (SN2) | SGI | http://oss.sgi.com/projects/sgi_propack/ (kernel source RPMs under `download/`) | SGI's own Altix kernel for SN2, including `arch/ia64/sn/configs/defconfig-sn2`. | Dead site, source RPMs. `linux-5.3` and `linux-2.5.40` hold the code that reached mainline. |
| SGI Linux Device Driver Programmer's Guide, chapter 12 | SGI | https://techpubs.jurassic.nl/manuals/hdwr/developer/LX_DevDriver_PG/sgi_html/ch12.html | How the Altix kernel was built and where its sources were published. | Manual page, cited in place. |
| MIPS: SGI-IP27 "report a Bedrock machine as SGI IP35" and the series around it | Linux kernel mailing list, October 2026 | https://lkml.iu.edu/2610.0/01855.html | A posted series adding Bedrock-hub (IP35) support to the IP27 code and PIC widget recognition to the xtalk-bridge driver. Merge state not checked. | A mailing-list posting, not a tree. Check whether it landed before citing it as upstream. |
| linux-mips `linux-2.4` branch, SN2 code | linux-mips community (Ralf Baechle's tree) | https://git.kernel.org/pub/scm/linux/kernel/git/ralf/linux.git (branch `linux-2.4`, commit `8ef7d46c94d5`) | `arch/ia64/sn/io/sn2/pcibr` and `include/asm-ia64/sn/pci` (`pcibr_dvr.c`, `pcibr_intr.c`, `pic.h`, `bridge.h`, `pciio.h`): the SN2 PIC driver and header as of that commit, cited by the PIC page. | A branch of a tree no submodule carries; pinned by commit for the PIC citations. |
| `linux-ip35` at `9f613a321ea0` | linux-mips community | see the IP35 row above | `arch/mips/pci/pci-sgipic.c`: PIC slot set-up and Device register bits, cited by the PIC page. | Same dead server; the pin names the commit the citations were read at. |
| OpenBSD `sgi` tree at `2df91d80c104` | OpenBSD | https://github.com/the-machine-hall/openbsd-sgi | `sys/arch/sgi/xbow/xbridge.c` as of that commit, cited by the PIC page for Device register set-up. | Differs from the `openbsd` submodule pin; the submodule was not used for these citations. |

Considered and not added: `sgi-demos/sgi-docs` (the other repositories carry it) holds only IRIS GL manual pages,
nothing on these chips.

## SGI manuals for the SN2 machines (Altix and Prism)

Published SGI guides for the IA-64 Altix and Silicon Graphics Prism machines. None is a chip specification: they
describe enclosures, modules, cabling and operation, and the SHub, PIC, IOC4 and NUMAlink parts appear only by name
and block list. Cited by document number and revision with the printed page. "Read" says how much was opened; a
contents list read is not a content audit. The platform pages under [../../platforms/sn2/](../../platforms/sn2/README.md)
use them. The facts column is what the pages read state.

| Document (revision) | Title | Read | What it establishes |
|---|---|---|---|
| 007-4660-001 (001, 2004) | SGI Altix 350 System User's Guide | contents; printed pp. 53, 58, 67-72, 96-112, 197 | The Altix 350 module set (base compute, CPU expansion, CMPX), IP57 node board, SHub block list, PIC on the PCI riser, IO9 card with IOC4, ring of up to eight modules, 3.2 GB/s per direction NUMAlink, console and L1 ports. The only guide read that prints the node board name (IP57). |
| 007-4660-002 (002) | SGI Altix 350 System User's Guide | contents; printed pp.66 to 72, 105 to 107, 111 to 114 | Later and fuller than -001: the standard base I/O card is the IO10 (serial ATA, serial ports) and the IO9 (SCSI) is optional, the fabric is NUMAlink-4, one or two routers join up to sixteen modules and 32 processors, "Super Hub (SHub)". |
| 007-4417-001, -002 | SGI Altix 350 Quick Start Guide | not read | Setup card for the Altix 350. |
| 007-4374-001 | Important Note: SGI IO10 PCI Option for Altix 350 | pp.1 to 2 | The IO10: full-size PCI card for the lower slot, serial ATA disks and DVD-ROM, a 36-pin MDR connector carrying four modem-control serial ports (S0 to S3), one Ethernet port, two unlabeled RT interrupt connectors that Linux does not support; no SCSI disks. Names no chips. |
| 007-4579-001 (001, 2003) | SGI Altix 3000 User's Guide | contents; printed pp. 79-82, 99-100, 108 | The 3300 and 3700 models, C-brick (two nodes, 16 DIMM slots each), R-brick router, IX-, PX-brick, power bay, 40U rack, L2 touch display. Calls the node chip "Super-Bedrock" and its internal link "NUMAlink 4". |
| 007-4377-002 (002, Nov 2004) | SGI Altix 3700 Bx2 User's Guide | contents; printed pp. 49, 65, 67, 72, 74 | CR-brick (up to four SHub nodes, two NL4 routers), Xtown2 I/O ports on nodes 1 and 3, IX- and PX-brick, L1 and the L2 emulator. Names the fabric "NUMAlink-4". |
| 007-4377-001 (001) | SGI Altix 3700Bx2 User's Guide | not read | Earlier revision. |
| 007-4823-001 (001, Mar 2006) | SGI Altix 4700 System User's Guide | contents; printed pp. 44-47, 53-55, 87, 116 | IRU of ten blade slots, four routers per IRU, compute/memory blade (SHub with one or two sockets), memory-only blade, PCI-X and PCIe expansion blades, IA blade as base I/O, optional dense router, no hardware L2. |
| 007-4823-002, -003 | SGI Altix 4700 System User's Guide | not read | Later revisions. |
| 007-4857-001 (001), -002, -003 | SGI Altix 450 System User's Guide | contents; printed pp. 64, 66 (001) | Five-blade 5U IRU, two internal routers, SHub nodes of one or two sockets, NUMAlink 4, up to 76 cores in a rack. The only held Altix 450 guide. |
| 007-4954-001 | SGI Altix 4700 and Altix 450 3D Graphics Option User's Guide | not read | Graphics option shared by both. |
| 007-4790-001 (001, 2005) | SGI Altix 330 System User's Guide | contents; printed pp. 57-58, 70, 79 | 1U base compute module, one PCI/PCI-X slot, SAS or SATA disks, one NUMAlink-4 port, optional router for up to eight modules, SHub block list. |
| 007-4805-001 | Connecting a System Console to an SGI Altix 330 System | not read | Console connection note for the 330. |
| 007-4637-001 | Site Planning Guide for the Altix 3300 and the Altix 3700 Supercluster | not read | Site planning for the 3000 family. |
| 007-4520-006 (006, Jul 2005) | Linux Device Driver Programmer's Guide, Porting to SGI Altix Systems | contents; revision record; printed pp. 15-19 | SC-brick (two SHub nodes, four Itanium 2, sixteen DIMM slots per SHub), IX-brick as a PX-brick plus BaseIO card (IOC4, Ethernet, SCSI), PX-brick with six PCI-X buses; contents list the SHub physical address map, global MMR space and AMO space. Revisions 001 (Feb 2003) to 006 follow ProPack releases 2.2 to 3 SP6. |
| 007-4520-001, -003, -007 | same title (Altix 3000 in -001 and -003) | not read | Other revisions. |
| 007-4763-001 (001, Aug 2005) | SGI Altix Architecture Considerations for Linux Device Drivers | contents | Shorter driver note with the same chapter list as the porting guide. |
| 007-3938-005 (005, Apr 2006) | SGI L1 and L2 Controller Software User's Guide | contents; revision record; printed pp. 3, 48-51 | L1 and L2 operation and command list. Revision log: 003 May 2004 adds the Altix 350, 004 July 2005 adds the 3700 Bx2 and the Prism, 005 Apr 2006 adds the 4700. Brick naming (`003c01`), the valid blade types of the 4700 ("SHub 2.x based" compute blades), the 4700 L2 as an application. |
| 007-3938-001 to -004, -006 | same title | not read | -006 is cited by the Origin 3000 pages. |
| 007-4772-001 (001) | Silicon Graphics Prism Deskside Visualization System Hardware User's Guide | contents; printed pp. 19-21, 25, 27 | Deskside node board with one or two processors, base I/O board in PCI slot 1, two AGP graphics slots, eight PCI-X slots on four buses. |
| 007-4701-001 to -004 | Silicon Graphics Prism Visualization System User's Guide (Power and Team scalable in -003, -004) | -001 contents | The rackmount Prism with XG2N and compute modules. |
| 007-4774-001, -002 | Silicon Graphics Prism Visualization System User's Guide for Extreme Scalable Configurations | -001 contents | Large Prism configurations. |
| 007-4712-001 | SGI Altix PA Expansion Module User's Guide | not read | A PA expansion module for Altix systems (title only). |
| 007-4426-001 | Partitioning Guide for Systems That Contain Cx-bricks | not read | Cx-brick partitioning (Origin 3000, Altix 3000 not confirmed). |
| 007-4572-001 | Cx-brick Addendum | not read | Already cited by the Origin 3000 Cx-brick page. |
| 007-4604-001, 007-4605-001 | IX-brick Addendum, PX-brick Addendum | not re-read | Cited by the IX- and PX-brick pages. |

Not held as manuals: any guide for the Altix 3700 as a model apart from the 3000 guide, the
IR- and M-brick, a NUMAlink 3 or NUMAlink 4 specification, and any SHub, TIO or router datasheet. The Altix UV guides
and the RASC guide (007-4718-007) are outside this list.

## Published specifications held in this repository

Committed under [specs/](specs/), described with revisions and coverage in [../specs.md](specs.md): Bridge
(rev 4.0), XBridge (rev 0.5), Crossbow (rev 12.0, with the address map transcribed), CRIME 1.5 (rev 0.3, with the
CPU interface and memory controller map transcribed), MACE, GBE and the VICE design specification.
