# Source index

Every openly published source the project reads, in one place. Submodules sit at the repository root and are
pinned to the commit shown; they are shallow (`shallow = true` in `.gitmodules`), so
`git submodule update --init --depth 1 -- NAME` fetches only that commit. Initialise what you need: all of them
together are over ten gigabytes. Everything here is cited by file and version, never copied, and a driver is a
driver author's naming, not a hardware measurement (see [../published-sources.md](../published-sources.md)).

## Submodules

| Path | Project | Pin | Public URL | What it covers and why |
|---|---|---|---|---|
| `linux` | Linux (current) | `c339f4010dea` | https://github.com/torvalds/linux | `arch/mips/sgi-ip27`, `sgi-ip30`, `sgi-ip32`, `arch/mips/include/asm/sn`, `arch/mips/pci/pci-xtalk-bridge.c` (Bridge, XBridge, PIC and TIOCP as one driver), `drivers/mfd/ioc3.c`, the IOC3 network, serial and keyboard drivers, `drivers/video/fbdev/gbefb.c`. The mainstream reading of Hub, HEART, Xbow, the Bridge family, IOC3, CRIME, MACE and GBE. |
| `linux-ia64` | Linux v5.3 | `4d856f72c10e` | https://github.com/torvalds/linux | The last release with `arch/ia64/sn` (SN2: SHub and TIO register headers `shub_mmr.h`, `shubio.h`, `pic.h`, `tiocp.h`, `tioca.h`, `tioce.h`; the `pcibr` PCI provider; `sn_hwperf`; the `sgi-xp` partitioning driver). Current Linux deleted all of it with the ia64 port; the headers it carries are the only open description of the SHub and TIO side of the Bedrock family. |
| `linux-2.5.40` | Linux v2.5.40, from the kernel's historical repository | `7570df54ef8c` | https://git.kernel.org/pub/scm/linux/kernel/git/history/history.git | The first SN1 ia64 code (`arch/ia64/sn/io`: Xbow, Bridge, Hub and router helpers, `include/asm-ia64/sn`) and the 64-bit MIPS IP27 port (`arch/mips64/sgi-ip27`, `include/asm-mips64/sn`) before the trees were reorganised. Current Linux dropped SN1 and the early Hub headers. |
| `linux-2.4.37` | Linux v2.4.37, from a mirror of the linux-mips history | `e0dbf803698f` | https://github.com/xtreamerdev/linux-mips | The 2.4 IP27 code (`arch/mips/sgi-ip27`), the Hub headers under `include/asm-mips64/sn`, the 2.4 IOC3 network driver and the 2.4 SN ia64 tree. The mirror also holds the linux-mips branches and tags back to 1.x, which the canonical kernel.org trees do not. |
| `linux-ip30` | Out-of-tree Octane (IP30) port against Linux 3.6 | `bff2b6daa1d6` | https://github.com/jaaron/linux-mips-ip30 | `arch/mips/sgi-ip30` and its PCI glue as the linux-mips community carried it before the mainline port: an independent reading of HEART, Xbow and the PCI Bridge for the Octane. Branch `ip30-3.6`. |
| `openbsd` | OpenBSD | `7011342f6a72` | https://github.com/openbsd/src | `sys/arch/sgi/xbow` (`xbridgereg.h`, `xbow.c`, `xbridge.c`, `xheart.c`, `xheartreg.h`, `hub.h`, `widget.h`), `localbus` (CRIME, MACE, interrupt controllers), `hpc`, and the man pages. Origin (IP27), Octane (IP30) and Bedrock-class (IP35) machines. |
| `netbsd` | NetBSD | `0747dc050541` | https://github.com/NetBSD/src | `sys/arch/sgimips`: CRIME and MACE support and the O2 PCI and ISA glue, `ioc` and `xio` directories. |
| `gxemul` | GXemul (mirror) | `234a181a1711` | https://github.com/retroprom/gxemul | Device models for the O2 (`dev_sgi_ip32.c`: CRIME, MACE), the Octane (`dev_sgi_ip30.c`) and GBE (`dev_sgi_gbe.c`). An independent model to compare a reading against, never a fact source. |
| `mame` | MAME | `803a05bb5090` | https://github.com/mamedev/mame | `src/mame/sgi`: `crime.cpp`, `mace.cpp` and `o2.cpp` for the O2, the earlier SGI memory and I/O controllers (`mc.cpp`, `hpc3.cpp`, `ioc2.cpp`). Independent model, same caveat. |
| `arcboot` | arcboot | `15151b5e144d` | https://github.com/agx/arcboot | A published boot loader for IP22 and IP32 that calls the ARCS firmware interface (`arclib`): how a loader finds the machine through the PROM. |
| `m2c` | m2c (MIPS decompiler, fork with N32 support) | `b3e0876aca1c` | https://github.com/techomancer/m2c | Tool, not a hardware source: decompiles MIPS routines for the census. |
| `spimdisasm` | spimdisasm | `4b5d4c68eeb9` | https://github.com/Decompollaborate/spimdisasm | Tool, not a hardware source: MIPS disassembly used by `scripts/`. |

Pins match the sibling repositories (`gr4`, `odsy`, `kona`, `crime`) wherever they carry the same tree:
`m2c`, `spimdisasm`, `netbsd`, `openbsd`, `gxemul` and `mame`. `linux` takes the pin the `crime` repository uses.
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
| SGI ProPack source (SN2) | SGI | http://oss.sgi.com/projects/sgi_propack/ (kernel source RPMs under `download/`) | SGI's own Altix kernel for SN2, including `arch/ia64/sn/configs/defconfig-sn2`. | Dead site, source RPMs. `linux-ia64` and `linux-2.5.40` hold the code that reached mainline. |
| SGI Linux Device Driver Programmer's Guide, chapter 12 | SGI | https://techpubs.jurassic.nl/manuals/hdwr/developer/LX_DevDriver_PG/sgi_html/ch12.html | How the Altix kernel was built and where its sources were published. | Manual page, cited in place. |
| linux-sn2 | community | https://github.com/nsafran1217/linux-sn2 (branch `v5.10-sn2`) | Mainline SN2 support revived on kernels after the removal. | Code derived from `linux-ia64`, with later changes to the mainline trees around it rather than to the hardware description. |
| MIPS: SGI-IP27 "report a Bedrock machine as SGI IP35" and the series around it | Linux kernel mailing list, October 2026 | https://lkml.iu.edu/2610.0/01855.html | A posted series adding Bedrock-hub (IP35) support to the IP27 code and PIC widget recognition to the xtalk-bridge driver. Merge state not checked. | A mailing-list posting, not a tree. Check whether it landed before citing it as upstream. |

Considered and not added: `sgi-demos/sgi-docs` (the other repositories carry it) holds only IRIS GL manual pages,
nothing on these chips.

## Published specifications held in this repository

Committed under [specs/](specs/), described with revisions and coverage in [../specs.md](../specs.md): Bridge
(rev 4.0), XBridge (rev 0.5), Crossbow (rev 12.0, with the address map transcribed), CRIME 1.5 (rev 0.3, with the
CPU interface and memory controller map transcribed), MACE, GBE and the VICE design specification.
