# SN2 and later: what the sources hold and what is missing

Scope: SGI's IA-64 Altix and Prism machines (the SN2 generation: SHub 1 and SHub 2, TIO, NUMAlink 3 and 4), the IA-64
platform on the SN1 Bedrock, and the x86 Altix UV hubs. This page lists the sources found on 2026-11-14 and the gaps
they leave. Nothing on it is a register contract yet; the device and platform pages are being written from these
sources. Grades below describe the sources, not hardware facts.

## How SN2 facts are graded here

These machines ran Linux, so no IRIX source exists for them. SGI's own Linux platform code is the vendor's software
source for SN2 and UV, and ranks where the IRIX source ranks for the MIPS machines: a fact it defines is established,
cited by tree, tag and path. SGI ProPack kernels and modules (shipped binaries) confirm what shipped. SGI manuals come
next. Other projects confirm only.

## Software sources

SGI's SN2 platform code in mainline Linux, last present at tag v5.3 (SN2 was removed in the v5.4 merge window):

| Path (Linux v5.3 unless noted) | What it describes |
|---|---|
| `arch/ia64/include/asm/sn/shub_mmr.h` | SHub 1 and SHub 2 memory-mapped registers |
| `arch/ia64/include/asm/sn/addrs.h`, `arch.h`, `nodepda.h` | node physical address layout, NASID encoding, per-node data |
| `arch/ia64/include/asm/sn/sn_sal.h` | the SN-specific SAL calls the kernel makes into firmware |
| `arch/ia64/include/asm/sn/bte.h` | the block transfer engine |
| `arch/ia64/include/asm/sn/intr.h` | interrupt vectors and error interrupt numbers |
| `arch/ia64/include/asm/sn/tioca.h`, `tioca_provider.h`, `tioce.h`, `tioce_provider.h`, `tiocp.h`, `tiocx.h` | the TIO I/O ASIC and its bridges |
| `arch/ia64/include/asm/sn/pcibr_provider.h`, `pic.h`, `pcidev.h` | PIC as the SN2 PCI-X bridge |
| `arch/ia64/include/asm/sn/klconfig.h`, `geo.h`, `module.h`, `l1.h` | firmware topology records, geographic IDs, the L1 controller interface |
| `arch/ia64/sn/kernel/` (`setup.c`, `irq.c`, `iomv.c`, `bte.c`, `sn2/timer.c`, `sn2/sn2_smp.c`, `sn2/ptc_deadlock.S`) | how the kernel programs SHub: boot, interrupts, I/O space, block transfer, timer, TLB purge |
| `arch/ia64/sn/pci/` (`pcibr/`, `tioca_provider.c`, `tioce_provider.c`) | PCI providers for PIC and the TIO bridges |
| `drivers/char/snsc.c`, `drivers/misc/sgi-xp/` | the system controller driver, cross-partition messaging |
| `drivers/char/mmtimer.c` (v4.9; gone by v5.3), `drivers/misc/ioc4.c` (v4.19) | the SHub RTC timer, IOC4 |

IA-64 on SN1: 2.4-era Linux (`arch/ia64/sn/io/`, `include/asm-ia64/sn/sn1/`) carries about 40 headers for the
Bedrock-based IA-64 platform, including router, L1 and ELSC interfaces. These describe the same Bedrock chips covers
for the Origin 3000, seen from IA-64.

Altix UV (x86): `arch/x86/include/asm/uv/uv_hub.h` and `uv_mmrs.h`, `arch/x86/platform/uv/`, and
`drivers/misc/sgi-gru/`. The hub definitions cover UV2, UV3, UV4 and UV5; nothing for UV1 was found. The MMR header
has no UV5 section.

Shipped binaries: SGI ProPack 4 and 6 ia64 kernels and modules, some with debug information
([kudzu formats/xvm](https://github.com/jamesbraid/kudzu) reads one), and SGI's SN2 system firmware. Corrected on
2026-11-14: an earlier version of this page said no Altix PROM was held. That came from a bounded search and was wrong.

## System firmware

SGI shipped the SN2 PROM (PAL, SAL and EFI in one flash image) as the `snprom` package on ProPack media. The images
below are read by [software/firmware/snprom](../software/firmware/snprom/README.md); the files are copied into `root/`
and never committed ([references/irix-files.md](irix-files.md) lists them with checksums).

| Image | snprom package | SAL build | Board named in the image | Size (bytes) | sha256 | Container |
|---|---|---|---|---:|---|---|
| `snprom.bin` | 4.43 build 44607 | 4.43 | IP41 (SHub 1) | 6291456 | `035274812b5065bde3f1b3227a23c05637d8a13f7cab7736ddde4718d46f02eb` | `snprom-4.43-44607.ia64.rpm`, ProPack 4 SP3 CD 2 |
| `shub1snprom.bin` | 10.40 build 62478 | 4.90 | IP41 (SHub 1) | 6291456 | `26170cc83c3db243601da8f55610bcdd6bb408136c3b3d19b7c4823e491b9a06` | `snprom-10.40-62478.ia64.rpm`, ProPack 4 SP4 CD 2 |
| `shub2snprom.bin` | 10.40 build 62478 | 1.40 | IP65 (SHub 2) | 12582912 | `1c8144e3d318f71a7633dddc268c3ebd0f64febb87c2f234a9a917df0673dd77` | as above |
| `ip65prom.bin` | 10.11 build 52277 | 1.11 | IP65 (SHub 2) | 12582912 | `372e74f7201d35e56ef871c330ccbd66fda9f921376ae5dd3045cf4ae6319199` | `snprom-10.11-52277.ia64.rpm`, a ProPack 4 package mirror |
| `snprom.bin` | 3.32 build 30085 | 3.32 | IP41 (SHub 1) | 6291456 | `cce7adf38c0bb5b50d7c48c571fa4194f5b714d5c46e0e6519b2a64b2b34e0d6` | `snprom-3.32-30085.ia64.rpm`, ProPack 3 proprietary CD |
| `snprom.bin` | 4.20 build 40503 | 4.20 | IP41 (SHub 1) | 6291456 | `0fdd129ecc2efdcfb875c873d67c9e18e57bc75b4500d6c1e72a1d9ca8dfa866` | `snprom-4.20-40503.ia64.rpm`, ProPack 3 SP6 proprietary CD |
| `shub1snprom.bin` | 10.54 build 70399 | 5.04 | IP41 (SHub 1) | 6291456 | `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617` | `snprom-10.54-70399.ia64.rpm`, a ProPack 4 package mirror |
| `shub2snprom.bin` | 10.54 build 70399 | not read | not read | | `3ea833181fda8968a5297043f2260d2fc255983ecca1d418292ee008b5e2c793` | as above |

Every SHub 1 image above is built for `CPUBOARD=IP41` (its build-flag and banner strings say so), from 3.32 in 2004 to
5.04 in 2008. That names the build target, not a single board. Which machines each image boots is stated by SGI's
`README.snprom`, shipped inside each snprom package from 10.20 (2007) on and identical in substance in every later
build: `shub1snprom.bin` supports the Altix 330, Altix 350, Altix 3300, Altix 3700, Altix 3700 Bx2, Prism Rackmount and
Prism Deskside; `shub2snprom.bin` supports the Altix 4700, and the Altix 450 from 10.23 on. The package's install script
keeps the SHub 1 image on nodes whose PROM version names IP41 and the SHub 2 image otherwise. This is vendor
documentation of intent, graded established for what SGI says each image is for; that a given image boots a given
machine is not yet shown. So the newest SHub 1 image held, SAL 5.04 from snprom 10.54, is the firmware for the Altix 350
and both Prism variants. The 3.x and 4.x packages predate the README and name no machine.

Published boot logs from real machines support the SHub 1 lineage. Two serial-console logs from an SGI Prism (one node,
two processors, about 8 GB), posted on the irixnet forum, thread 849, post 12, on 2019-01-27
(<https://forums.irixnet.org/thread-849.html>), both print EFI version 1.10, "SGI SAL version 4.65" with the SAL
revision 3.2 header, the SAL platform feature ITC_Drift, the console `ttySG0` as an "SGI SN L1", and ACPI tables with
OEM table ids XSDTSN2, APICSN2, SRATSN2, SLITSN2, FACPSN2 and DSDTSN2. Neither prints a PROM banner, SHub revision or
board number. Established as an observation of that machine. SAL 4.65 is a SHub 1 build number, and snprom 10.15 (build
53414, banner `SGI SAL Version 4.65 rel061204 IP41`) is held. The match to these logs rests on the version number alone, so it is
inferred ([the held-PROM section](../platforms/sn2/prism.md#held-prom-images-and-prism-support)). An Altix 350 owner's notes on
<https://nsafran.com/> state SHub 1.2 and SAL 4.56 for a one-node, two-processor machine; that is the owner's
statement, not a captured log, so it is graded inferred.

Still held but not extracted: snprom 4.04, 4.20 build 41216, 4.31 to 4.33 and the other 10.x builds. The Prism disk image
held turned out to be a recent community Linux build for IA-64, not a factory system, and carries no SGI firmware.

No L1, L2 or L3 controller firmware package for the SN2 bricks has been found under those names. sysco's readings of
the controller firmware shipped with IRIX include SN2 brick routines, so that firmware may cover some SN2 bricks.

The SN1 IA-64 prototype never shipped a PROM. The only firmware its Linux tree carries is SGI's simulator fake PROM
from the Linux 2.5 tree ([platforms/sn1-ia64/fake-prom.md](../platforms/sn1-ia64/fake-prom.md)).

## Manuals

SGI user's guides, none of them a chip specification:

| Document | Product |
|---|---|
| 007-4660-001 (2004) | Altix 350 System User's Guide |
| 007-4579-001 (2003) | Altix 3000 User's Guide |
| 007-4377-002 (2004) | Altix 3700 Bx2 User's Guide |
| 007-4823-001 (2006) | Altix 4700 System User's Guide |
| 007-4790-001 (2005) | Altix 330 System User's Guide |
| 007-4520-006 | Linux device driver porting guide for Altix: PCI-X resource addresses, a memory-ordering appendix |
| 007-3938-005 | L1 and L2 Controller Software User's Guide, including the Altix 4700 |
| 007-4718-007 (2008) | RASC User's Guide |
| 007-5636-006, 007-5629-005 | UV controller software and UV Linux configuration guides |

Prism guides (007-4772 deskside, 007-4701 Power and Team, 007-4774 Extreme) are being located by revision.

## What already exists in this repository and sysco

- [devices/tiocp](../devices/tiocp/README.md): 45 register entries, offsets established, names inferred. Not yet
  checked against the SN2 headers.
- [devices/pic](../devices/pic/README.md), [devices/ioc4](../devices/ioc4/README.md),
  [devices/l1](../devices/l1/README.md), the router pages: written for the MIPS Origin 300/3000 side. Altix uses PIC
  and IOC4 too; the SN2 cross-check is pending.
- sysco: readings of the ARM L1 firmware (1.34.2 to 1.44.0) include SHub 2 and TIO routines (reset, PCI-X set-up, link
  reset). Which bricks those packages serve is open.

## Gaps

- No contract yet for SHub, SHub 2, TIO, TIOCA, TIOCE, TIOCX or the NUMAlink 4 router, and no SN2 machine or brick page.
- Firmware: the SHub 1 image is SGI's stated PROM for the Altix 350 and Prism, but no read of its board handling yet shows how it treats an IP57 node.
- No manual describes SHub, TIO or NUMAlink 4 at register level; the Linux code is the main source.
- No manual found for the Altix 450, IA-64 on SN1, or UV hardware.
- Prism graphics boards per model are not yet identified.
- The system controller driver, the SHub timer driver, the TIOCX driver and the IOC4 driver were not readable through
  our search tools and will be read from Linux directly at the tags above.
