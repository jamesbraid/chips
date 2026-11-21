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
  held image has no log. Partly answered 2026-11-21 (one AGP bridge per PROM-reported TIOCA bus; the count is open); see the kernel-source section below.
- **GPU part.** The guides name "FireGL X2PRO-256" and "FireGL X3-256" only. Which ATI chip each board carries (R350-class for the
  X2PRO, R420-class for the X3 by external listings) and the PCI vendor and device IDs are not in any SGI source. Route: `lspci`
  output or `fglrx` device tables from a ProPack disk image; the held T2/Linux image has neither. The 2019 log's boot VGA
  device (0006:00:00.0) prints no device ID. The public pci.ids list names 1002:4a4d "R420 GL [FireGL X3-256]" and
  1002:4e4b "R350 GL [FireGL X2 AGP Pro]". That is an external name list, not SGI evidence, and no held capture prints
  a 1002 ID, so the mapping to a board stays unknown. The driver table on the 2026-11-21 disc gives IDs for the X2-256 and X3-256 names; see below.
- **PROM and SAL.** No snprom build is tied to the Prism, and no PROM is held. The one constraint known: TIOCA setup needs SAL
  revision 4.06 or later (`v5.3:arch/ia64/sn/pci/tioca_provider.c`; the same check in the 2.6.5 and 2.6.16 trees, which have no SHub test). Whether the Prism PROM emits a PCDP VGA entry for the
  AGP card, and whether graphics boards carry an option ROM, is unknown. Route: PROM image or the disk's `/usr/cpu/firmware`;
  boot capture of the EFI shell. The 2019 logs (kernels 3.8.13 and 4.14.83) print `PCDP: v3 at 0x31efead110`, the address of the
  EFI `HCDP=` entry, so the firmware passes a PCDP v3 table (observed, as posted). The dump does not show its entries,
  so whether one describes the graphics adapter is unknown.
- **Software versions.** `fglrx`, XFree86 and ProPack 4 SP2 kernel versions are not printed in any guide. Route: a ProPack disk
  image's `rpm -qa` and `/etc/sgi-release`. The held image is T2/Linux and has neither. Partly answered 2026-11-21
  from the ProPack 4SP4 extensions disc; see the evidence section below.
- **Minimum rackmount build.** Table 3-1 lists four processors as the minimum while the XG2N text allows zero CPUs. Route:
  a configuration list or an order guide; none held.
- **L1 for XG2N.** The L1 and L2 guide's brick-type table has no XG2N letter; `gfxtopology` reports `c`. Route: an L1 `config`
  capture or the `snxsc_firmware` package from a ProPack disk image; the held image has none of these files.

## Evidence from the ProPack 4SP4 extensions disc (2026-11-21)

Read: `propack-4SP4-cd3-extn.iso` from the local SGI mirror (SHA-256 `837cdfbf52bdad30e3fc524b41fef5850dbb4cf7b1401d7a0e2fa2b90e423a36`).
The disc is read-only and was unpacked into a scratch directory; nothing was run. The fglrx module and driver are not top-level
disc members. They sit inside the `km-rtgfx-fglrx` and `fglrx` RPMs. The disc's content file says ProPack "4SP4".

- **SHub generation.** Unknown. The `2.6.5-7.308-rtgfx` kernel's `System.map` has SHub 1 and SHub 2 handlers and a
  `shub_1_1_found` symbol, so it names no Prism SHub. Its patch `patches.rtgfx/dont-use-ptcga-for-shub1` says SHub 1 systems
  hit PIO machine checks when the X server stopped and started (established from the patch text). That suggests SHub 1
  graphics machines ran this kernel (inferred; no Prism named).
  Route: `/proc/sgi_sn/sn_topology` or `lspci` output from a running Prism.
- **TIOCA count and pipe wiring.** The count per XG2N is unknown. Software expectation: one AGP bridge per TIOCA instance, bound
  to the last VGA-class AGP device on that instance's device list (`patches.rtgfx/sgi-agp`, from the patch text). The
  2.6.5 and 2.6.16 `sgi-agp.c` read on 2026-11-21 bind to the last device on the list whatever its class; see the
  kernel-source section below. The disc's `sgi-agp.ko` imports `tioca_list`, `tioca_gart_found` and `tioca_fastwrite_enable` (observed with `nm -u`).
  `gfxtopology` reads one `pcibus` line per pipe and prints the brick and closest CPU brick for each pipe (script text,
  established), which does not give a count. The dual TIO riser, the AGP-5 and AGP-6 wiring, and any bridge on the deskside
  PCI-X buses are not described anywhere on the disc. The vizserver release notes say an SGC PCI-X card takes the first
  output of a pipe on Onyx4 and Prism (established). Unknown.
  Route: `/proc/sgi_sn/sn_topology`, `lspci -t` and the kernel's TIOCA lines from a booted Prism.
- **ATI part and IDs.** `fglrx_drv.o` (8.12.1) has a chip table of `name (family device-ID)` rows: `FireGL X2-256/X2-256t
  (R350 4E4B)`, `FireGL X3-256 (R420 4A4D)`, `FireGL X1 (R300 4E47)`, plus V-series and T2 rows. The table has no `X2PRO`
  string, so which chip SGI's X2PRO-256 is stays unknown. The X3-256 to `4A4D` pairing is established in the driver. That
  the Prism X3 board carries that device is inferred. Reading the second field as the PCI device ID is a software
  expectation. The public `pci.ids` agrees for `4A4D` and `4E4B`, but that list is external.
  Route: `lspci -nn` on a Prism, to read the board's own ID.
- **Driver and bridge.** Established from the modules: `sgi-agp.ko` (`CONFIG_AGP_SGI_TIOCA=m`) sits under `agpgart.ko`, and
  `fglrx.ko` depends on `agpgart` and `usbcore`. `fglrx.ko` has no PCI alias table, so the X server picks the board. Its
  strings `Provider is TIOCA = %d`, `firegl_snia_is_tioca` and `firegl_snia_closest_node` show that the driver asks which
  provider a pipe sits behind and where the closest node is (established from strings; the logic is not read).
- **Software versions.** Partly answered. Established from the disc: `fglrx` 8.12.1, kernel `2.6.5-7.308-rtgfx`, XFree86
  `4.3.99.902-43.91sgi404r1` (source RPM only), `sgi-vizserver` 3.5.2.1, `sgi-gfxtools` 1.0. Unknown: which service pack the
  disc matches (its label says 4SP4, its vizserver README says ProPack 4 Service Pack 3), and whether it matches the
  ProPack 4 SP2 editions the guides name.
  Route: `/etc/sgi-release` and `rpm -qa` from an installed ProPack disk.
- **PROM, SAL and PCDP.** Not answered. The disc has no PROM. The SAL 4.06 TIOCA constraint is unchanged.

## Evidence from the ProPack 4 SP3 and ProPack 6 SP3 kernel source (2026-11-21)

Read: `kernel-rtgfx-source-2.6.5-7.244` (ProPack 4 SP3 extensions disc, `propack-4SP3-cd3-extn.iso`) and
`kernel-sltdebug-source-2.6.16.60-0.21` (ProPack 6 SP3 tar), public GPL files only, paraphrased. Each row states what the
kernel expects; what the chip does is inferred. Full reading in [platforms/sn2/prism.md](../platforms/sn2/prism.md#graphics-attachment).

- **TIOCA count per XG2N.** Unknown. The kernel has no per-module count. Each PROM-reported PCI bus whose ASIC type is TIOCA
  gets one TIOCA instance (established). The part and manufacturer macros are not compared anywhere in these files.
  Route: a booted Prism's bus list, or the PROM's bus records.
- **Discovery.** Established: the kernel asks SAL for each bus by segment and number, then uses the XIO widget number and
  NASID the PROM returns. Unknown: how the PROM splits a TIO into TIOCA records.
- **SHub port per pipe.** Unknown. The per-bus record fields the kernel reads (NASID, widget number) carry no port number.
  The record's full definition is in a header not read here.
- **Pipe to bridge.** Established: `sgi_tioca_find_bridge` matches a bridge to a device by PCI bus. Unknown: which bus each
  pipe sits on.
- **Closest node.** Established: the PROM gives a closest NASID; the kernel uses its node for GART and AGP pages. 2.6.5
  leaves the PCI controller's node unset; 2.6.16 sets it. The fglrx query that reads the closest node is not in GPL
  source: unknown.
- **Dual TIO riser.** Unknown. The TIOCE header's two-port array (`TIOCE_NUM_PORTS 2`) is a chip property, not a riser.
- **Other TIO port.** TIOCE is present (`tioce.h`, `tioce_provider.c`; part `0xCE00`, manufacturer `0x36`). `tiocp.h` is
  present with no part macro. Which Prism shape uses either is unknown.
- **Prism constants.** None. No read file names Prism.
- **PROM gate.** Established: the TIOCA setup checks only the SAL revision (4.06 or later). The "SHub 1 only" wording from
  v5.3 is not confirmed by these trees; check it against v5.3 before citing it.
  Route: the v5.3 file or a Linux 2.6.x tree from `references/code/`.

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from ee45651 and a399d6d). Sources: the SGI printed manuals, printed pages; Linux v5.3 single files from raw.githubusercontent.com, `arch/ia64/include/asm/sn/{tioca.h,pcibus_provider_defs.h}`, `arch/ia64/sn/pci/tioca_provider.c`, `arch/ia64/sn/kernel/setup.c`, `drivers/char/agp/{sgi-agp.c,Kconfig}`; public github.com/jamesbraid/voyager `README.md`, `devices/README.md`, `questions/open-questions.md`.

Checked each entry against the pages it summarises. The SHub-label entry matches Figure 3-3 (p.60); the SAL 4.06 constraint matches `tioca_bus_fixup` (SHub 1 only); the minimum-build entry matches the Table 3-1 against text mismatch; the L1 entry matches 007-3938-004 Table 3-1 (brick types `c i p r x n g ?`, printed p.47). No entry claims a fact as established. Finding: the Team module-count mismatch (overview review, finding 4) is not listed as a question; the owner may add it. Cleared scope: all seven entries as questions.
