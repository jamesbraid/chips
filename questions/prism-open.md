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
- **GPU part.** Partly answered 2026-11-21. X2PRO-256: R350 (FireGL X2, likely `1002:4e4b`), **inferred**: all four editions of
  the Prism user's guide (007-4701-001 to -004) print a sample `lspci` naming `Radeon R350 NG [FireGL X2]` and its
  `(Secondary)` function for the Prism graphics pipe, and the driver table's X2 row is R350 `4E4B` (no `X2PRO` string in
  the SP2, SP3 or SP4 build). The sample is a placeholder (`rev xx`), not a capture, and was not revised for the X3-256, so
  the PCI ID itself is unconfirmed. X3-256: R420 `4A4D` by the driver table's name row; that the Prism board carries it is
  inferred. The 2019 log's boot VGA device (0006:00:00.0, with a second function 0006:00:00.1) prints no device ID and
  its 128 MB prefetchable BAR per function does not separate R350 from R420, since the public ID list gives both chips
  a secondary function. Route to settle: `lspci -nn` on a Prism, or a boot log that prints `1002:` IDs.
- **PROM and SAL.** The 2026-11-21 scan of the snprom builds 4.20 to 10.54 is in
  [the Prism platform page](../platforms/sn2/prism.md#held-prom-images-and-prism-support). No held image names a Prism, IP57
  or XG2N (established, strings). SGI's README lists Prism Rackmount and Prism Deskside for `shub1snprom.bin` in every build
  from 10.20 to 10.54 (established as text; vendor intent, not a boot). Whether any of those images boots a Prism or accepts one
  is unknown. Snprom 10.15 (SAL 4.65) is the candidate PROM for the 2019 logs (inferred from the banner number alone). The one constraint known: TIOCA setup needs SAL
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
  string (same in the SP2 and SP3 builds); the X2PRO-256 chip rests on the guide sample (see GPU part above). The X3-256 to `4A4D` pairing is established in the driver. That
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
- **PROM gate.** Established: the 2.6.5-7.308 setup checks only the SAL revision (4.06 or later), with no SHub test. The mainline
  3.2.78 search index shows the SHub 1 test (`is_shub1()`, `arch/ia64/sn/pci/tioca_provider.c:592`), so "SHub 1 only" belongs to
  mainline. Which tree first added it is unknown; the v5.3 text is not re-read here.
- **Bring-up order and AGP binding (answered 2026-11-21, software expectation).** The eight register writes, the aperture
  word (0x80200007 at 16 KiB pages), the flush rules and the AGP bridge's device choice are on [the Prism platform page](../platforms/sn2/prism.md#tioca-kernel-expectations-265-7308-read-2026-11-21).
  The count per node stays unknown: the kernel makes one TIOCA per type-4 bus record and reads nothing else.
- **2019 128 MB BARs (unknown).** The 2.6.5 code does not place BARs and defines no host-bridge window that covers
  0x08000000 or 0x10000000. The 4.14.83 log cannot be tied to 2.6.5 code. Route: the PROM's bus record legacy memory field,
  and `/proc/iomem` or `lspci -v` from a booted Prism on the 2.6.5 kernel.
- **Open items 16 and 18 (TIOCA).** The question's referent, "items 16 and 18" of the TIOCA list, is not in any held page,
  the TIOCA device page or the inventory. It needs the owner to name the list before it can be answered.

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from ee45651 and a399d6d). Sources: the SGI printed manuals, printed pages; Linux v5.3 single files from raw.githubusercontent.com, `arch/ia64/include/asm/sn/{tioca.h,pcibus_provider_defs.h}`, `arch/ia64/sn/pci/tioca_provider.c`, `arch/ia64/sn/kernel/setup.c`, `drivers/char/agp/{sgi-agp.c,Kconfig}`; public github.com/jamesbraid/voyager `README.md`, `devices/README.md`, `questions/open-questions.md`.

Checked each entry against the pages it summarises. The SHub-label entry matches Figure 3-3 (p.60); the SAL 4.06 constraint matches `tioca_bus_fixup` (SHub 1 only); the minimum-build entry matches the Table 3-1 against text mismatch; the L1 entry matches 007-3938-004 Table 3-1 (brick types `c i p r x n g ?`, printed p.47). No entry claims a fact as established. Finding: the Team module-count mismatch (overview review, finding 4) is not listed as a question; the owner may add it. Cleared scope: all seven entries as questions.
