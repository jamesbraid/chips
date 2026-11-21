# Silicon Graphics Prism: what the manuals and Linux do not settle

Question. Which SHub, which graphics bridge wiring, which ATI part and which firmware does each Prism shape use?

Status: **unknown** for everything below. What is established is on [the Prism overview](../platforms/sn2/prism.md).

- **SHub generation.** No Prism guide for the deskside, Power or Team states it. The Extreme guide's CR-brick figure labels its
  nodes "SHUB 1.2" and "IP57 Node Card" (007-4774-001 p.60) while the text says NUMAlink-4, which conflicts with the SHub 2
  reading of the Bx2 CR-brick. A boot log or `/proc/sgi_sn` capture, or the `shub2` flag the PROM returns to
  `ia64_sn_get_sn_info`, settles it per shape. Checked 2026-11-21: the two 2019 public boot logs (SAL 4.65) and the held T2/Linux image name no SHub.
- **TIOCA wiring.** How many TIOCA chips an XG2N has, which SHub I/O port each pipe's bridge uses, and why `gfxtopology` lists a
  different brick's CPUs as closest for the second pipe of each XG2N (007-4751-001 p.18). The parts index names a "dual TIO
  riser" (inferred two TIOCAs). The deskside's wiring of AGP-5 and AGP-6, and what bridges the four deskside PCI-X buses, are
  unstated. Route: kernel boot log of a Prism (PCI bus numbers and `TIOCA` lines), a ProPack disk image's `dmesg` or
  `/proc/bus/pci`, ProPack kernel DWARF. Checked 2026-11-21: the 2019 public logs enumerate no AGP or TIOCA device, and the
  held image has no log.
- **GPU part.** The guides name "FireGL X2PRO-256" and "FireGL X3-256" only. Which ATI chip each board carries (R350-class for the
  X2PRO, R420-class for the X3 by external listings) and the PCI vendor and device IDs are not in any SGI source. Route: `lspci`
  output or `fglrx` device tables from a ProPack disk image; the held T2/Linux image has neither. The 2019 log's boot VGA
  device (0006:00:00.0) prints no device ID. The public pci.ids list names 1002:4a4d "R420 GL [FireGL X3-256]" and
  1002:4e4b "R350 GL [FireGL X2 AGP Pro]". That is an external name list, not SGI evidence, and no held capture prints
  a 1002 ID, so the mapping to a board stays unknown.
- **PROM and SAL.** No snprom build is tied to the Prism, and no PROM is held. The one constraint known: SHub 1 needs SAL
  revision 4.06 or later for TIOCA (`v5.3:arch/ia64/sn/pci/tioca_provider.c`). Whether the Prism PROM emits a PCDP VGA entry for the
  AGP card, and whether graphics boards carry an option ROM, is unknown. Route: PROM image or the disk's `/usr/cpu/firmware`;
  boot capture of the EFI shell. The 2019 logs (kernels 3.8.13 and 4.14.83) print `PCDP: v3 at 0x31efead110`, the address of the
  EFI `HCDP=` entry, so the firmware passes a PCDP v3 table (observed, as posted). The dump does not show its entries,
  so whether one describes the graphics adapter is unknown.
- **Software versions.** `fglrx`, XFree86 and ProPack 4 SP2 kernel versions are not printed in any guide. Route: a ProPack disk
  image's `rpm -qa` and `/etc/sgi-release`. The held image is T2/Linux and has neither. Checked 2026-11-21: the Library
  search finds no ProPack 4 Service Pack 4 FireGL package set (the fglrx, km-rtgfx-fglrx and vizserver names return only a ProPack 4 Service Pack 3 CD1 README
  and RPM listing, which the reader cannot open), so no package list is read.
- **Minimum rackmount build.** Table 3-1 lists four processors as the minimum while the XG2N text allows zero CPUs. Route:
  a configuration list or an order guide; none held.
- **L1 for XG2N.** The L1 and L2 guide's brick-type table has no XG2N letter; `gfxtopology` reports `c`. Route: an L1 `config`
  capture or the `snxsc_firmware` package from a ProPack disk image; the held image has none of these files.

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from ee45651 and a399d6d). Sources: the SGI printed manuals, printed pages; Linux v5.3 single files from raw.githubusercontent.com, `arch/ia64/include/asm/sn/{tioca.h,pcibus_provider_defs.h}`, `arch/ia64/sn/pci/tioca_provider.c`, `arch/ia64/sn/kernel/setup.c`, `drivers/char/agp/{sgi-agp.c,Kconfig}`; public github.com/jamesbraid/voyager `README.md`, `devices/README.md`, `questions/open-questions.md`.

Checked each entry against the pages it summarises. The SHub-label entry matches Figure 3-3 (p.60); the SAL 4.06 constraint matches `tioca_bus_fixup` (SHub 1 only); the minimum-build entry matches the Table 3-1 against text mismatch; the L1 entry matches 007-3938-004 Table 3-1 (brick types `c i p r x n g ?`, printed p.47). No entry claims a fact as established. Finding: the Team module-count mismatch (overview review, finding 4) is not listed as a question; the owner may add it. Cleared scope: all seven entries as questions.
