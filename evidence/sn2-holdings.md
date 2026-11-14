# SN2 and later: what the sources hold and what is missing

Scope: SGI's IA-64 Altix and Prism machines (the SN2 generation: SHub 1 and SHub 2, TIO, NUMAlink 3 and 4), the IA-64
bring-up on the SN1 Bedrock, and the x86 Altix UV hubs. This page lists the sources found on 2026-11-14 and the gaps
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
Bedrock-based IA-64 bring-up, including router, L1 and ELSC interfaces. These describe the same Bedrock chips covers
for the Origin 3000, seen from IA-64.

Altix UV (x86): `arch/x86/include/asm/uv/uv_hub.h` and `uv_mmrs.h`, `arch/x86/platform/uv/`, and
`drivers/misc/sgi-gru/`. The hub definitions cover UV2, UV3, UV4 and UV5; nothing for UV1 was found. The MMR header
has no UV5 section.

Shipped binaries: SGI ProPack 4 and 6 ia64 kernels and modules, some with debug information
([kudzu formats/xvm](https://github.com/jamesbraid/kudzu) reads one). No Altix PROM, SAL or system firmware image is
held.

Mail: the linux-ia64 list carries SN2 bring-up, SHub and TIO threads from 2003 to 2019, including the removal series.

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
- No firmware: a machine model needs a synthetic SAL implementing exactly the `sn_sal.h` calls its kernel makes.
- No manual describes SHub, TIO or NUMAlink 4 at register level; the Linux code is the main source.
- No manual found for the Altix 450, IA-64 on SN1, or UV hardware.
- Prism graphics boards per model are not yet identified.
- The system controller driver, the SHub timer driver, the TIOCX driver and the IOC4 driver were not readable through
  our search tools and will be read from Linux directly at the tags above.
