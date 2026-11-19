# Silicon Graphics Prism: the product line

The Silicon Graphics Prism is SGI's Linux visualization system on the Itanium 2 Altix platform ([SN2](README.md)):
Altix compute nodes with ATI FireGL graphics boards attached over AGP. It shipped in three shapes, covered one page each:

| Shape | Page | What it is |
|---|---|---|
| Deskside | [prism-deskside.md](prism-deskside.md) | One node board in a tower, one or two AGP graphics pipes |
| Power and Team | [prism-power-team.md](prism-power-team.md) | 2U modules (base compute, XG2N graphics, CPU expansion, CMPX) on NUMAlink: a ring (Power) or two routers (Team) |
| Extreme | [prism-extreme.md](prism-extreme.md) | CR-bricks and I/O bricks in 40U racks with XG2N modules, 8 to 128 processors |

Sources, grades and page conventions are those of [the SN2 README](README.md). Nothing here is IRIX. Page numbers are
printed pages. The held PDFs are SGI printed manuals, filed by number under the 4000 series; 007-3938 is under `3000`. The extra page offset between PDF page and printed page is 22 for 007-4701 and 007-4772, 26 for 007-4774.

## Documents and revisions (established)

Each date is the guide's own revision record, so it dates the manual, not the first shipment.

| Number | Title (as printed) | Revisions | Read for this stream |
|---|---|---|---|
| 007-4701 | Silicon Graphics Prism Visualization System User's Guide; from -003 "for Power & Team Scalable Configurations" | -001 Oct 2004 first release; -002 Feb 2005 adds Team (routed NUMAlink), multi-Xserver, optional IO9 card; -003 May 2005 adds the FireGL X3-256 card, drops the optional L2 controller, updates XF86Config; -004 Oct 2005 adds ProPack 4 Service Pack 2 (007-4701-004 p.iii) | -003 in depth; -004 revision record and contents |
| 007-4772 | Silicon Graphics Prism Deskside Visualization System Hardware User's Guide | -001 Apr 2005; -002 Oct 2005 adds ProPack 4 Service Pack 2 (its contents list a diagnostics and an XF86Config chapter; the revision record does not say they are new) | -001 in depth; -002 contents and pp.120 to 122 |
| 007-4774 | Silicon Graphics Prism Visualization System User's Guide for Extreme Scalable Configurations | -001 May 2005; -002 Oct 2005 adds ProPack 4 Service Pack 2 | -001 chapters 2, 3, 5, 6 in part |
| 007-4751-001 | Obtaining Maximum Performance on Silicon Graphics Prism Visualization Systems | one revision, undated in the pages read; mentions ProPack 3 Service Pack 3 | pp.1, 5, 6, 18, 19 |
| 007-4602-003 | SGI Scalable Graphics Compositor User's Guide | -001 May 2003, -002 Dec 2003 adds Onyx4 UltimateVision, -003 Jul 2005 adds Prism | revision record only |
| 007-4663-002 | Silicon Graphics Scalable Graphics Capture PCI-X Option User's Guide | Prism XG2N and compute-module cabling figure (p.3) | one figure |
| 007-3938-004 | SGI L1 and L2 Controller Software User's Guide | -004 adds the Prism (revision note, p.iii) | revision note, brick-type table |
| 007-4784-001, 007-4796-001 | Notes on 018-1054-001 and 9470667 analog video cables for Prism systems | one revision each | titles only (held list) |
| 007-5707-001 | SGI Prism XL System Hardware User's Guide | -001 May 2011 | contents and p.24 only; see below |

The guides never print a model name or SKU list beyond the three shapes. "Power" and "Team" appear as table titles in
007-4701-003 (Tables 3-1 and 3-2, pp.60 and 61); "Extreme" and "Deskside" are in the titles. No other Prism variant
appears in the Itanium guides. The Silicon Graphics parts index in Origami's library lists shared parts named
"Altix 350/Prism" and "Onyx4/Prism" (below), but no further product name.

**Later "SGI Prism XL" (007-5707-001, May 2011) is a different machine.** It is a rack of dual-node "stick" enclosures
with BMCs, PCIe cards and a 2U head node, with InfiniBand and Gigabit Ethernet switches (printed pp.xiii, 24 and the
figure list). It is not Itanium 2 and not SN2. It is out of scope; only the name is shared. Grade: established that it is a
different architecture (the guide's own contents); what silicon it uses is not read.

## Configuration summary

| | Deskside | Power | Team | Extreme |
|---|---|---|---|---|
| Compute | one node board, 1 or 2 Intel 64-bit CPUs, 2 to 24 GB | 1 to 3 compute/expansion modules, 4 to 8 CPUs, 2 to 96 GB | 1 to 5 compute/expansion modules, 8 to 16 CPUs, 8 to 192 GB | 1 to 8 CR-bricks per rack (8 CPUs each), 8 to 128 CPUs |
| Graphics pipes | 1 or 2 (AGP-5, AGP-6) | 1 to 2 XG2N modules (2 or 4 pipes) | 2 to 4 XG2N modules (4 to 8 pipes) | XG2N modules, up to 8 pipes in a rack and in the system |
| Interconnect | none shown; node board on an interface board | NUMAlink ring | NUMAlink with 2 routers | NUMAlink-4 through CR-brick routers |
| Boot I/O | base I/O board in PCI slot | IO10 card in the base compute module | same | IX-brick with an IO9 card |

Sources: 007-4772-001 pp.7, 19 to 27; 007-4701-003 pp.60, 61; 007-4774-001 pp.55 to 66. Detail and the exceptions are on the
shape pages.

## Smallest documented configuration

**Deskside with one processor, four DIMMs (2 GB) and one graphics board.** The guide gives the floor as one or two
processors, four to twelve DIMMs and "one or (optionally) two graphics boards (pipes)" (007-4772-001 pp.7, 20, 32;
established). A one-processor, one-pipe, 2 GB deskside is therefore inside the documented ranges, though the
guide does not describe that exact build as a SKU.

The smallest **rackmount** system is a base compute module (two Itanium 2 CPUs, at least 2 GB, one SATA disk, DVD-ROM,
IO10 card, four-port USB card) cabled in a two-module ring to one XG2N graphics module (two pipes), with a 2-CPU XG2N
for four processors in all and at most 48 GB (007-4701-003 pp.28, 32, 33 to 35, 62; established). Table 3-1 lists
minimum 4 processors, which fits a two-CPU XG2N; the module text allows a zero-CPU XG2N, and the guide does not say what
that does to the minimum. No document read says which shipped.

## Hardware that every shape shares

- **Compute node.** Itanium 2, "each with integrated L1, L2 and L3 caches", on a node board with a Super-Hub
  ("SHUB") ASIC as the crossbar between processors, memory, network interface and I/O interface (007-4701-003 pp.31, 35).
  Established as the guide's words. The SHub generation is **unknown** for Deskside, Power and Team; the Extreme guide's
  CR-brick block diagram labels its four nodes "SHUB 1.2" and "IP57 Node Card" (007-4774-001 Figure 3-3, p.60) while its
  text calls the machine fourth-generation NUMAlink-4 (p.59). That label is the first place a manual names a SHub
  revision for a Prism, and it conflicts with the Altix 3700 Bx2 reading in [the README](README.md#which-chip-where)
  (inferred SHub 2); see [the question page](../../questions/prism-open.md).
- **Node board.** IP57 for the rackmount modules is inferred: the parts index lists "Altix 350/Prism CPU Board" as
  `030-2038-001` with the tag `IP57`, and the Altix 350 guide names IP57 ([altix-350.md](altix-350.md)); the Prism guides
  never print "IP57" for the 2U modules (they do in the Extreme figure, above).
- **Base I/O.** IO10 (SATA, DVD-ROM, Ethernet, real-time interrupt ports "not supported under SGI Linux + ProPack",
  serial) in the compute modules; the parts index lists it as "Altix 350/Prism IO10 Base I/O" (`030-1948-001`). IO9 is
  optional in Power and Team and standard in the Extreme IX-brick (007-4701-003 pp.31, 33, 53; 007-4774-001 p.66).
- **L1 controller** in every module, with the same four services in each guide (power sequencing, environment, reset,
  identification and configuration storage).
- **Graphics.** Two AGP pipes per XG2N and per deskside, ATI FireGL boards, DVI-I outputs, a 7-pin synchronization cable
  between the board and its riser (see the shape pages and [graphics attachment](#graphics-attachment)).

## Graphics attachment

Established, from SGI's Linux platform code (v5.3 tree). The TIO bridge chips themselves are described on the I/O pages:

- The AGP bridge is the **TIOCA** (part number `0xE020`, manufacturer `0x24`, revision A `1`:
  `v5.3:arch/ia64/include/asm/sn/tioca.h`). Linux registers it as PCI bus provider type 4
  (`PCIIO_ASIC_TYPE_TIOCA`, `v5.3:arch/ia64/include/asm/sn/pcibus_provider_defs.h`) and as its own TIO node with a "closest"
  node ID (`ca_closest_nasid`, `v5.3:arch/ia64/sn/pci/tioca_provider.c` `tioca_bus_fixup`).
- Linux sets up one 2 GiB aperture at bus base `0x80000000`: a 1 GiB AGP-mapped window and a 1 GiB PCI32-mapped window
  through the same GART, GART pages of 4 KiB or 16 KiB (the kernel's page size), with GART prefetching turned off (the 2005-03-16 patch cites an SGI bug
  number for the hardware fault; `tioca_gart_init`). The header comments label the two 0x40000000 windows "2GB"; the
  value is 1 GiB. Established as the code and header.
- The AGP backend for the kernel advertises AGP 3.0, 8x only, 64-bit addresses, sideband addressing and fast writes
  (`v5.3:drivers/char/agp/sgi-agp.c`, `agp_sgi_init`, mode word `(0x7d<<24)|(1<<9)|(1<<5)|(1<<4)|(1<<3)|2`), and
  `v5.3:drivers/char/agp/Kconfig` ties `AGP_SGI_TIOCA` to `IA64_SGI_SN2`. The Deskside guide says "AGP 4X/8X support"
  for its board (007-4772-001 p.26): the board may do 4x, the platform side offers 8x only. Established for both
  statements; their reconciliation is inferred (the board negotiates down, but a 4x-only card was not tested).
- SGI posted TIOCA support in early 2005 (patch series "altix: AGP bridge support for tioca chip", first posted
  2005-02-04, resent 2005-02-08 and 2005-03-10, message id `20050310215538.16305.1181.18064@attica.americas.sgi.com`);
  the ia64 maintainer's pull request of 2005-04-25 lists `tioca_provider.c` (message id
  `200504252131.j3PLVqP03282@unix-os.sc.intel.com`). The 2.4.21 ProPack 3 kernel the Prism shipped with is
  a different tree, so these files describe the later mainline form of the same hardware (inferred match).
- Linux selects the VGA console from the firmware's PCDP table, because the platform firmware passes too little ACPI data
  to find a VGA adapter (`v5.3:arch/ia64/sn/kernel/setup.c`, `sn_scan_pcdp`, comment above it). The Prism guide tells the
  user to put the Linux console monitor on pipe 0's left channel (007-4701-003 p.18). Established that the kernel needs
  PCDP; **inferred** that the Prism firmware publishes a PCDP VGA entry for that card.

How the AGP boards attach to a node, from the manuals plus the parts index (inferred where marked):

- A Prism XG2N module has two pipes. `gfxtopology -v` in SGI's performance guide prints one line per pipe, for example
  `pipe 0 g @ 001c02/1/agp/0a -> c @ 001c02/0 (cpu 2,3) (PCI:23:0:0) SG2`, and the guide explains the fields: the brick
  (`001c02`: rack 1, slot 2), the port in that brick (`1`), the bus type (`agp`), device `0a`; then the brick and port of
  the closest CPUs and the XFree86 bus ID (007-4751-001 pp.18, 19; established). In the four-pipe example the two pipes
  of one XG2N sit on ports 1 and 2 of the same brick. Each SHub has two I/O ports (007-4774-001 p.62), so the reading
  "each pipe is behind one of the node's two I/O ports" is **inferred**.
- Rear-view figures label the two pipe slots "Bus 1 slot 1 (Pipe 0)" and "Bus 2 slot 1 (Pipe 1)" (007-4701-003 Figure 1-1,
  p.3), which fits one bus per pipe.
- The parts index lists "AGP Riser for Prism Dual TIO Riser (2 Molex Connectors)" `030-2053-001` and "AGP Riser for
  Onyx4/Prism (1 Molex Connector)" `030-1872-005`, a riser power cable `018-1193-002`, "Onyx4/Prism FireGL sync cable"
  `015-0412-003`, "Prism XG2N image sync cable" `018-1191-001`, "Onyx4/Prism PCA PCI Image Sync 2" `030-1986-001` and
  "FireGL X3 AGP 256MB" `030-2071-002` (parts-index extract, no public copy
  lines 200, 201, 259, 260, 288, 390, 392, 393). These are index records, not SGI Linux code or a manual: they establish
  that the parts exist and are shared between Onyx4 and Prism; that the "dual TIO riser" carries two TIO chips (one per
  pipe) is **inferred** from the name and the one-bus-per-pipe labels.
- The graphics board and its riser are a card plus a connector, not a standard AGP slot on the node: the replacement
  procedure removes a "PCI/PCI-X support bracket", disconnects a 7-pin keyed synchronization cable from the card to the
  riser board, and pulls the card from "the main connector on the riser board" (007-4701-003 pp.91 to 94; established).

## Graphics boards and outputs

- Boards named in the guides: **FireGL X2PRO-256** and **FireGL X3-256**. The -003 revision note says it "added FireGL
  X3-256 card" (007-4701-003 p.iii), so X2PRO-256 is inferred to be the board of the earlier -001 and -002 text (not read). Both are "ATI" FireGL boards (ATI and Radeon trademark notice,
  007-4701-003 p.ii); the figures show the X2PRO and X3 rear panels as the two XG2N variants (Figures 1-1 to 1-4,
  pp.3 and 4). Established as names.
- The guides do not print the GPU part. External sources (not SGI, not evidence): ATI's FireGL X3-256 is the R420-based
  AGP 8x board with 256 MB, introduced August 2004; ATI's FireGL X2-256 is R350-based (some references say R360). SGI's
  "X2PRO" name was not found outside SGI. **Unknown** whether X2PRO is the X2-256 part; the X3-256 as R420 is inferred from
  external listings.
- Each board has 256 MB: 128 MB framebuffer plus 128 MB "retained-object" memory; the driver spills to system memory when
  that fills (007-4751-001 p.5; established). `/proc/dri/N/umm` reports a free AGP aperture of 1065091072 bytes, which is
  1 GiB minus 8.25 MiB, matching the 1 GiB AGP-mapped window above (inferred match).
- Per pipe: two DVI-I connectors ("left channel" and "right channel"), each carrying digital TMDS and the analog RGB, hsync and
  vsync pins (007-4701-003 p.166 Table A-13; 007-4772-002 p.166 lists the same connector for Deskside). Both channels of a
  pipe must run the same resolution; if any pipe of an X server runs both, every pipe of that server must
  (007-4701-003 p.138). Established.
- Pipe numbering: pipe 0 is normally in the XG2N directly above the base compute module; the display number is the pipe
  number (:0.n) (007-4701-003 p.18; 007-4751-001 p.19).
- **Genlock, framelock, stereo.** Optional SGI ImageSync (IS) boards; the XG2N has IS1, IS2 and Repeat DB9 connectors and a
  "StereoSync" connector, and a card in the base compute module daisy-chains to every XG2N (007-4701-003 pp.3, 16, 17).
  Stereo needs ImageSync; stereo works on one channel of a pipe, not both. Genlock and framelock are driven with
  `setmon -p<pipe> -g <format>` and `-L<video format> <format>`; Table 5-5 lists the framelock input formats (525, 625,
  720p, 1080i/p at 24 to 30 Hz) and the graphics timings that carry an `f` suffix (pp.141, 142). The Deskside has the
  ImageSync ports on its static I/O daughter card rather than a PCI card ([prism-deskside.md](prism-deskside.md)).
- **Compositor.** The SGI Scalable Graphics Compositor (007-4602-003, rev -003 July 2005 adds Prism) has four DVI inputs, a DVI
  output, an analog output, genlock in and loop, stereo sync and swap-ready lines (rear panel in 007-4663-002 p.3 and in
  007-4774-001 Figure 3-4, p.66). Its cable must go to the left connector of a pipe (007-4772-001 p.10; 007-4772-002 p.122).
  A Scalable Graphics Capture PCI-X card in the base compute module takes a Y cable from the compositor (007-4663-002
  p.3). Established as described; the compositor's internals are not read.

## Firmware

- **PROM and SAL.** No manual names a PROM version for any Prism. SGI's SHub 1 PROM images are held (snprom 4.43, 10.40 and
  10.54; [references/sn2-holdings.md](../../references/sn2-holdings.md)), no Prism-specific build is, and SGI's `README.snprom` in
  the 10.54 package lists Prism Rackmount and Prism Deskside among the machines `shub1snprom.bin` supports: vendor intent, not
  a boot of a Prism ([the qualification page](../../software/firmware/snprom/images.md) grades it). The only version requirement in Linux is generic: with a SHub 1, `tioca_bus_fixup` refuses to set up a TIOCA unless
  the SAL revision is at least `0x0406` ("SGI prom rev 4.06 or greater required for tioca support",
  `v5.3:arch/ia64/sn/pci/tioca_provider.c`). It is skipped for SHub 2. Established as the code. The SAL calls the kernel makes
  are on [the SAL page](../../software/sal/README.md).
- **L1.** Each module and brick has an L1 controller. The Extreme guide documents upgrading it through the `snxsc_firmware`
  package (example `snxsc_firmware-1.18.3-1`), with a boot image and two images A and B; the newer of A and B runs, and the
  other is overwritten; `flashsc --12 <addr> -p /usr/cpu/firmware/sysco/l1.bin all` updates every brick, and
  `...l1.bin <rack>.<slot>` one brick (007-4774-001 pp.52, 53; established). The L1 and L2 guide's brick-type table in
  -004 lists `c i p r x n g` only; there is no XG2N type letter, and `gfxtopology` reports an XG2N as a `c` brick
  (007-3938-004 p.47; 007-4751-001 p.19). Prism-specific L1 builds: **unknown**. The Altix 350 node board's L1 contains
  IP57 routines (see [altix-350.md](altix-350.md)); a Prism rackmount compute module is inferred to use the same.
- **Graphics option ROM.** Nothing in any Prism guide or Linux file names one. The IRIX Onyx4 boards ship three ROM images
  (voyager, below); whether the Prism boards carry the same is **unknown**.
- **NMI.** Pressing NMI on an XG2N sends an interrupt to the PROM, which captures CPU state to flash and the system log
  (007-4774-001 p.79; established).

## Software SGI shipped

Established, from the guides:

- SGI ProPack for Linux: Prism software "prior to SGI ProPack 3, Service Pack 3" had an older `gfxtopology`
  (007-4751-001 p.18); multi-Xserver configuration is described for ProPack 3 SP4 and for ProPack 4 SP2 (007-4701-004
  contents); the guides of October 2005 are the ProPack 4 SP2 editions. A deskside diagnostics example runs on
  `2.4.21-sgi305a8` (`ia64`), i.e. ProPack 3 (007-4772-002 p.120). ProPack release is read from `/etc/sgi-release`
  (007-4701-004 p.157).
- X server: the paths are `/usr/X11R6/bin/X` and `/etc/X11/XF86Config`, with gdm as the display manager; the file format is
  XFree86's. The Prism X driver is `fglrx` (ATI's proprietary driver), identifier "SGI SG-0", `BusId "PCI:23:0:0"`; the
  driver options the guides document are `Stereo`, `StereoSyncEnable`, `FSAAScale` (1 per-window, or 2, 4, 6 global),
  `DesktopSetup` (`0x100` clone, `0x200` and `0x300` scale by 2), `NoDDC`, and overlay-plane and monitor-type settings
  (007-4701-003 pp.134 to 145). Pipe numbers become screen numbers and the `gfxtopology` card-type string is `SG2`
  (007-4751-001 p.19).
- Diagnostics: `runalldiags -basic` runs `torpedo`, `olcmt` and `pandora` (007-4772-002 pp.120, 121).
- **Unknown:** the `fglrx` driver version, the XFree86 version, the kernel version of ProPack 4 SP2, and the ATI board
  device IDs. No guide states them.

## What carries over from voyager

[voyager](https://github.com/jamesbraid/voyager) documents the ATI R300 (FireGL X1) and R350 (FireGL X2) as IRIX 6.5.30
drives them on the Onyx4 UltimateVision (IP35), and says it reads the IRIX binaries, the public IRIX 6.5.7 source, AMD register references and the
radeon drivers. This section uses only its public README, `devices/README.md` and `questions/open-questions.md`.

Could transfer, **inferred** only until a Prism board is identified:

- R3xx register behaviour (display, interrupt, engine, pipe-select and Z-buffer registers in voyager's `devices/display`
  and `devices/pipes`), if the Prism X2PRO is an R350-class part. The silicon would be the same; only the host bus differs.
- Board-level facts shared by both products: the "FireGL sync cable" and AGP riser parts are listed as "Onyx4/Prism"
  parts, and the card-type string `SG2` printed by Prism's `gfxtopology` is the family name voyager reads in the IRIX
  driver ("'sg2' names the family"). Same card family on both machines is inferred.
- PCI subsystem IDs: voyager infers `1002:0152` for the X1 and X2 from ROMs and driver tables. A Prism board dump would
  confirm or reject it.

Cannot transfer:

- The bus path. voyager's Onyx4 boards sit behind a PIC- or XBridge-fronted slot (voyager leaves which bridge open); voyager records the AGP aperture words as set to
  size 0 and base -1 in the IRIX stub, so no AGP aperture is in use. A Prism pipe is AGP through a TIOCA with a GART and an
  8x-only mode (above), so the memory-controller and aperture programming differs.
- The driver. IRIX's `fglrx.o` and ATI's X server module are the IRIX side; Prism runs ATI's Linux `fglrx` with its own kernel
  module and DRI. The voyager ioctl and DRM tables do not apply.
- The X3-256 (an R420-class board per external listings) is outside voyager's chip list. R420 is a later R3xx-family
  descendant, but nothing in voyager covers it.
- voyager's open questions (bus clock and width behind a pipe, PIC topology) are Onyx4-specific; on Prism the answer is
  "AGP 8x on a TIOCA" for the bus, and the topology question becomes the TIOCA-per-pipe question here.

## Wanted from the held Prism disk image

Do not extract it here. A listing of these would settle most of the unknowns:

- `/etc/sgi-release`, `uname -r` strings, the kernel image and `/lib/modules/*/` (for `sgi-agp`, `agpgart`, the `fglrx`
  kernel module and its version string), the kernel's DWARF if present (structure layouts for `tioca`, `tioca_common`).
- `/etc/X11/XF86Config` (identifier, `BusId`, card strings), the `fglrx` X module and DRI library with versions, XFree86's
  version, `/usr/X11R6/lib/modules`, `/usr/sbin/gfxtopology`.
- `/usr/cpu/firmware/sysco/` (`l1.bin`, `flashsc`, the `snxsc_firmware` package version) and any PROM images or PROM
  flasher under `/usr/cpu/firmware`.
- The boot partition's EFI files (ELILO configuration, `efi/sgi`), kernel command lines, and any saved `dmesg`,
  `/var/log/messages` or `/proc/sgi_sn` captures, which give the SHub generation, PROM revision and TIOCA bus numbers.
- `rpm -qa` (ProPack service-pack level; ATI driver package name and version), and the `pci.ids`/`lspci` data if saved.

The open questions are in [questions/prism-open.md](../../questions/prism-open.md).

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from ee45651 and a399d6d). Sources: the SGI printed manuals, printed pages; Linux v5.3 single files from raw.githubusercontent.com, `arch/ia64/include/asm/sn/{tioca.h,pcibus_provider_defs.h}`, `arch/ia64/sn/pci/tioca_provider.c`, `arch/ia64/sn/kernel/setup.c`, `drivers/char/agp/{sgi-agp.c,Kconfig}`; public github.com/jamesbraid/voyager `README.md`, `devices/README.md`, `questions/open-questions.md`.

Checks, all confirmed unless listed under findings:
- Document identities and dates from each record of revision: 007-4701-003 and -004 (Oct 2004, Feb 2005, May 2005 with the FireGL X3-256 card and no L2 text, Oct 2005 ProPack 4 SP2), 007-4772-001 (Apr 2005) and -002 (Oct 2005), 007-4774-001 (May 2005) and -002 (Oct 2005), 007-4602-003 (Jul 2005 adds Prism), 007-3938-004 (p.iii adds the Prism). The 22 and 26 page offsets (007-4774-001 PDF 86 is printed p.60; 007-4772 PDF 7 is vii).
- Smallest configurations: 007-4701-003 p.28 ("two-module system with two graphics pipes, up to 48 GB, 4 PCI/PCI-X slots"), Table 3-1 (p.60: 1 compute, 1 graphics, 4 processors, 2 GB, one SATA disk) and Table 3-2 (p.61: 8 GB, 8 to 16 processors). The deskside floor (one or two processors, one optional second pipe) matches 007-4772-001 p.7 and the page's own caveat that no SKU is named.
- "SHUB 1.2" and "IP57 Node Card": 007-4774-001 Figure 3-3 (PDF 86, printed p.60) prints "SHUB 1.2" four times and "IP57 Node Card" four times, with `XIO` and `NI0/NI1` labels; the page grades the label as the figure's text and the generation as unknown, and records the conflict with the NUMAlink-4 text instead of resolving it. Right.
- Board names FireGL X2PRO-256 and X3-256 are as printed; the page claims no GPU part as established (R420 and R350 are labelled external, not SGI evidence, unknown or inferred). Right.
- TIOCA against v5.3: `TIOCA_PART_NUM 0xE020`, `TIOCA_MFGR_NUM 0x24`, `TIOCA_REV_A 1`; `PCIIO_ASIC_TYPE_TIOCA 4`; `CA_APERATURE_BASE 0x80000000` and size = `CA_AGP_MAPPED_SIZE + CA_PCI32_MAPPED_SIZE`, both `0x40000000` with the header comments saying "2GB" (the page's remark is right); 4 KiB or 16 KiB GART pages; GART prefetch disabled with the SGI bug number in the comment; AGP mode word `(0x7D<<24)|(1<<9)|(1<<5)|(1<<4)|(1<<3)|2` with "8x transfer only"; `is_shub1() && sn_sal_rev() < 0x0406` with the "4.06 or greater" message, so SHub 2 is skipped; `ca_closest_nasid`; PCDP scan comment in `setup.c`.
- voyager statements against the three public pages: R300 on the X1, R350 on the X2, subsystem pair `1002:0152` inferred, "sg2 names the family", aperture words set to size 0 and base -1, 256 MB split 128/128 for the X2.

Findings:
1. Mechanical, fixed: the held-PDF path pattern is wrong for 007-3938 (it is under `manuals/3000`, not `4000`); the -002 deskside row said the revision "adds" a diagnostics and XF86Config chapter, but the record of revision says only ProPack 4 SP2 (the contents do list the chapters), so the row now says that.
2. Mechanical, fixed: the voyager section said voyager "reads only" binaries, radeon drivers and AMD references; its README also lists the public IRIX 6.5.7 source. It also said voyager's boards sit behind a PIC-fronted slot; voyager's open question says PIC against XBridge is unsettled (a PIC is established only as a case the IRIX kernel handles). The page now says PIC or XBridge, left open.
3. Not edited: `drivers/char/agp/sgi-agp.c` and its Kconfig sit outside the platform-code trees the evidence order ranks first, yet the AGP 8x-only statement is graded established. The SN2 README's recorded decision keeps the equivalent IOC4 driver rows established, so this follows precedent; the owner can relabel.
4. Not edited: the Team module count. Table 3-2 allows 1 compute plus 2 graphics (three modules) up to 5 plus 4 (nine), while the cabling text (p.65) says four to eight modules; prism-power-team.md quotes the text only.
5. Not checked: the 2005 mailing-list message ids and dates for the TIOCA patch series, the parts-index line numbers, the Prism XL page, 007-4663-002, 007-4784, 007-4796 (titles only) and the ATI external listings. Those statements stay as the author graded them (the external ones are not evidence).

Cleared scope: document identities and dates, the revision history, configuration limits, the SHub-label handling, board names, every v5.3 TIOCA statement, the firmware requirement, and the voyager carry-over after the fixes above. Not cleared: the parts-index and mailing-list citations (finding 5).
