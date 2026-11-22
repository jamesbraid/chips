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
  revision for a Prism, and it agrees with the Altix 3700 Bx2 guide's own CR-brick figure (SHub 1.2, see [the README](README.md#which-chip-where)); see [the question page](../../questions/prism-open.md). The graphics kernel on the ProPack 4SP4 disc
  has SHub 1 and SHub 2 handlers and a patch, `patches.rtgfx/dont-use-ptcga-for-shub1`, for PIO machine checks on SHub 1
  systems when the X server stopped and started. That suggests SHub 1 graphics machines ran the kernel (**inferred**); the
  patch names no Prism, so the Prism SHub stays **unknown**.
- **Node board.** IP57 for the rackmount modules is inferred: the parts index lists "Altix 350/Prism CPU Board" as
  `030-2038-001` with the tag `IP57`, and the Altix 350 guide names IP57 ([altix-350.md](altix-350.md)); the Prism guides
  never print "IP57" for the 2U modules (they do in the Extreme figure, above).
- **Base I/O.** IO10 (SATA, DVD-ROM, Ethernet, real-time interrupt ports "not supported under SGI Linux + ProPack",
  serial) in the compute modules; the parts index lists it as "Altix 350/Prism IO10 Base I/O" (`030-1948-001`). IO9 is
  optional in Power and Team and standard in the Extreme IX-brick (007-4701-003 pp.31, 33, 53; 007-4774-001 p.66).
- **Compute-module slots.** The rear of a Prism compute module with ImageSync has four PCI/PCI-X slots, labelled PCI 1
  to 4 in the figure. PCI 1 is bus 1 slot 1 (IO10), PCI 2 is bus 1 slot 2 (ImageSync), PCI 3 is bus 2 slot 1, and PCI 4
  is bus 2 slot 2 (the four-port USB card) (`007-4701-003` p.7, Figure 1-6; p.31). Established as drawn. Whether a module
  without ImageSync uses bus 1 slot 2 differently is unknown.
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
- **The 2.6.5-7.308-rtgfx kernel (ProPack 4SP4 disc, read 2026-11-21).** `sgi-agp.ko` imports `tioca_list`,
  `tioca_gart_found` and `tioca_fastwrite_enable` (`nm -u`, observed). Its source patch `patches.rtgfx/sgi-agp` creates one AGP
  bridge per TIOCA instance on `tioca_list`. The patch text is not in the two source trees read below, and their
  `sgi-agp.c` does not match this wording: it sets the bridge device to the last device on the list whatever its class,
  and creates the bridge whether or not a VGA AGP device exists. The later `sgi-agp-empty-bus` patch skips
  instances with an empty device list (established from the patch text). The driver therefore assumes one AGP display
  device per TIOCA, a **software expectation**; the TIOCA count per XG2N stays **unknown**. `fglrx.ko` carries the strings
  `Provider is TIOCA = %d` and the functions `firegl_snia_is_tioca` and `firegl_snia_closest_node` (established from the
  binary; the logic is not read). Its modinfo depends are `agpgart,usbcore`, and it has no PCI alias table, so the X server
  picks the board. The same kernel builds the TIOCE provider (`tioce_bus_fixup` in `System.map`); which Prism shape uses
  TIOCE is **unknown**.
- SGI posted TIOCA support in early 2005 (patch series "altix: AGP bridge support for tioca chip", first posted
  2005-02-04, resent 2005-02-08 and 2005-03-10, message id `20050310215538.16305.1181.18064@attica.americas.sgi.com`);
  the ia64 maintainer's pull request of 2005-04-25 lists `tioca_provider.c` (message id
  `200504252131.j3PLVqP03282@unix-os.sc.intel.com`). The 2.4.21 ProPack 3 kernel the Prism shipped with is
  a different tree, so these files describe the later mainline form of the same hardware (inferred match).
- Linux selects the VGA console from the firmware's PCDP table, because the platform firmware passes too little ACPI data
  to find a VGA adapter (`v5.3:arch/ia64/sn/kernel/setup.c`, `sn_scan_pcdp`, comment above it). The Prism guide tells the
  user to put the Linux console monitor on pipe 0's left channel (007-4701-003 p.18). Established that the kernel needs
  PCDP; **inferred** that the Prism firmware publishes a PCDP VGA entry for that card. The 2019 boot logs show a PCDP v3
  table at the address of the EFI HCDP entry (observed, as posted); its entries are not printed.
- **Two more kernel trees (read 2026-11-21).** `kernel-rtgfx-source-2.6.5-7.244` (ProPack 4 SP3 extensions disc) and
  `kernel-sltdebug-source-2.6.16.60-0.21` (ProPack 6 SP3) carry the same TIO files. The kernel's expectations, established
  as code; what they imply for the chip is inferred:
  - Discovery is by PROM bus record, not by part number. `io_init.c` asks SAL for each PCI bus number and dispatches on the
    bus's ASIC type; a TIOCA is one such record, and its XIO widget number (`bs_xid`) and NASID come from that record. The
    part and manufacturer macros (`0xE020`, `0x24`) are declared but no read file compares them. Inferred: one TIOCA per
    record. **Unknown:** how many TIOCA records a TIO or XG2N produces, and what the PROM does with a second TIO.
  - Closest node: the PROM passes `ca_closest_nasid`; the kernel converts it to a node and allocates the GART table and AGP
    pages there. 2.6.5 leaves the PCI controller's node unset (the assignment is commented out); 2.6.16 sets it to the
    closest node. The fglrx "closest node" query is in the proprietary module, not these files: **unknown**.
  - Bridge lookup: `sgi_tioca_find_bridge` returns the AGP bridge whose device sits on the same PCI bus as the graphics
    device. So a pipe finds its bridge by bus number. Which bus a pipe sits on is **unknown** from these files.
  - GART: 2 GiB aperture at `0x80000000` with the 1 GiB AGP window below the 1 GiB PCI32 window; 4 MiB of table for 4 KiB
    pages or 1 MiB for 16 KiB pages (derived: entries times 8 bytes). PCI32 direct mode is disabled by a 2003 comment
    (the CA addressing glitch), so PCI32 DMA always goes through the GART.
  - Workaround IDs in `tioca_provider.h`: `PV907908`, `PV908234`, `PV895469`, `PV910244`, each a mask for revision A.
    `PV910244` forces an explicit TLB flush on revision A. The other IDs have no code in these files.
  - Prism: no file in `arch/ia64/sn`, `include/asm-ia64/sn` or `drivers/char/agp` names Prism. No Prism constant exists.
  - Other port: the same trees carry TIOCE (`tioce.h`, `tioce_provider.c`) with `TIOCE_PART_NUM 0xCE00`, `TIOCE_MFGR_NUM 0x36`,
    and `TIOCE_NUM_PORTS 2`, a per-port register array. `tiocp.h` is present with no part macro. Which Prism shape uses
    TIOCE or TIOCP is **unknown**; the two-port count is the chip's, not evidence of a dual TIO riser.

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

## TIOCA kernel expectations, 2.6.5-7.308 (read 2026-11-21)

Source: the 2.6.5-7.308 kernel source from the ProPack 4 SP4 extensions set, read with the build's own configuration
(IA64 SN2 on, 16 KiB pages, `CONFIG_AGP_SGI_TIOCA=m`). Each row is a software expectation: what the kernel does and what it
asks of the PROM. What the chip does with it is inferred. Line numbers are in that tree. The mainline comparison uses search
hits in the Library index for linux-3.2.78-ia64, not whole files.

- **Enumeration (established).** `sn_pci_init` asks SAL for every segment and bus number up to the hub's maximum
  (`arch/ia64/sn/kernel/io_init.c:509-512`). Each answer is a bus record carrying an ASIC type (`io_init.c:117-128`, SAL
  0x02000056). A record of type 4 goes to the TIOCA provider (`io_init.c:377-389`). Each such bus is one TIOCA. The kernel
  reads no part number, klconfig or count limit.
- **TIOCA count per node (unknown).** It is whatever the PROM puts in its bus records.
- **Record fields (established).** The provider copies the record and keeps its revision and closest NASID
  (`include/asm-ia64/sn/tioca_provider.h:93-98`, `pcibus_provider_defs.h:32-41`). It sets the uncached alias on the base
  (`tioca_provider.c:609`).
- **SAL gate (established).** `tioca_bus_fixup` refuses TIOCA below SAL revision 0x0406 (`tioca_provider.c:593-598`), with no
  SHub test. Mainline 3.2.78 adds `is_shub1()` to that test (`arch/ia64/sn/pci/tioca_provider.c:592`), so the "SHub 1 only"
  wording belongs to the mainline tree only.

### Bring-up order (established as the code order)

`tioca_gart_init` (`tioca_provider.c:34-204`) runs once per TIOCA bus, before any AGP device is probed. Before its register
writes it allocates and zeroes the GART table on the closest node. At 2 GiB and 16 KiB pages that is 131072 eight-byte
entries, 1 MiB (`:118-134`, derived). Then it writes, in order (offsets from `struct tioca`, `tioca.h:21-62`):

1. control1 (+0x008): set bit 42 (`tioca_provider.c:179-180`).
2. control2 (+0x010): clear bits 33:32, then write 2 into them (`:181-183`).
3. control2: clear bits 35:34, the write and read prefetch enables (`:185-186`).
4. int_status_alias (+0x058): write bit 4, the GART fetch error bit (`:192`).
5. mult_error_alias (+0x068): write bit 4 (`:193`).
6. int_mask (+0x078): clear bit 4, unmasking GART fetch errors (`:194`).
7. gart_aperature (+0x028): write the aperture word (`:200`).
8. gart_ptr_table (+0x200): write the table's coretalk address with bit 0 set (`:201`).

The aperture word for this build is 0x80200007 (derived, not read from a running system): size field 0x200 for 2 GiB at
bits 21:12 (`:83-85`), page-size bit 1 for 16 KiB (`:99-101`), AGP and PCI enable bits 0 and 2 (`:111`), and bus base
0x80000000 ORed in (`:112`). A 4 KiB-page build gives 0x80200005.

Aperture layout (established, `tioca.h:584-594`): one 2 GiB window at 0x80000000, the graphics part 0x80000000 to
0xBFFFFFFF and the PCI32 part 0xC0000000 to 0xFFFFFFFF, both GART-mapped. The AGP driver reports 1024 MB and 65536 entries
(`drivers/char/agp/sgi-agp.c:89-98`).

### AGP enable and TLB (established as the code)

- Fast-write (`tioca_provider.c:214-263`): every VGA-class AGP device on the bus must advertise FW, or the function returns
  before setting anything (`:240`). If they do, FW is set in each device's AGP command and control1 bit 6 is set (`:262`).
  With no VGA device on the bus, the bit is set anyway.
- TLB flush (`include/asm-ia64/sn/tioca_provider.h:161-207`): with a coherent table, no flush except on revision A
  (PV910244). Revision A clears the memory parameter, sets flush bit 36 (`tioca.h:126`), restores 2 and reads control2 back.
  With an uncached table the kernel sets flush bit 36 and reads back.

### Error interrupt and DMA (established as the code)

- Vector 0x35 (`intr.h`). Its handler makes one SAL call and reports the interrupt handled regardless (`tioca_provider.c:553-571`,
  `:642-644`).
- DMA: 64-bit direct for an all-ones mask. 48-bit direct when the mask is 48 bits and the address's node field matches the AGP
  DMA extension register (`:343-356`). Otherwise GART-mapped (`:370-456`). The kernel uses no 32-bit direct mode.

### AGP bridge (established as the code)

`agp_sgi_init` (`sgi-agp.c:257-312`) makes one bridge per TIOCA on the list (`:268-308`). The bridge's device is the last
device on that TIOCA's bus list, whatever its class (`:278-286`, device set at `:291`). The bridge uses a fixed mode word and
the 1 GiB graphics aperture. Its GART table is the TIOCA's own graphics table (`:100-110`), so there is no separate
configure step (`:79-82`). Insert and remove write entries straight into that table (`:117-209`). Neither the AGP driver nor
the fast-write path makes a SAL call (checked by search for SAL calls in both files).

### SAL calls for TIOCA (established as the code)

| SAL call | number | arguments | expected result | where |
|---|---|---|---|---|
| get PCI bus info | 0x02000056 | segment, bus, physical address of the out pointer | non-zero status means no bus; otherwise the record | `io_init.c:117-128, 351-352` |
| error interrupt | 0x02000051 | segment, bus, zeros | not checked | `tioca_provider.c:566-568` |
| SAL revision | none (system table field) | n/a | 0x0406 or higher | `sn_sal.h:159-165`, `tioca_provider.c:593` |

The TIOCA bus also goes through the generic get PCI device info call (0x02000057, `io_init.c:137-146`), which the TIOCA code
does not make itself.

### TIOCX is not the TIOCA path

`tiocx_init` (`arch/ia64/sn/kernel/tiocx.c:482-530`) scans odd NASIDs whose L1 brick type is SA, Athena or Daytona
(`:371-387`) for an FPGA mezzanine and skips the CE part. It never sees a TIOCA.

### Mainline 3.2.78 comparison (search hits only)

- SAL gate: mainline adds the SHub 1 test at line 592. This differs from 2.6.5.
- Aperture write (line 202), fast-write (line 264) and pointer-table write (line 203) sit where 2.6.5 has them (lines 200,
  262, 201). The register writes match at the points searched.
- AGP file: a search for `sgi-agp` in linux-3.2.78-ia64 returned no file. Unknown whether the index lacks it or the file is absent.
- Not compared: the rest of each function.

### 2019 128 MB BARs (v4.14.83 read, 2026-11-22)

The 4.14.83 boot in the 2019 public forum post (thread 849, post 12; full dmesg on page 1) runs the non-ACPI SN2 path. The
log prints `ACPI  DSDT OEM Rev 0x20001`, below the 0x20101 that selects the ACPI path, and its DSDT is a header-only stub
of 36 bytes. The reading uses the v4.14.83 tag (`1d4bd2e4e1d2`). Its SN2, AGP, PCI-bus and TIOCA files are identical to
mainline v4.14 (`e3d97e8db5c4`). The generic PCI files that differ change bus numbering, MPS, host-bridge release and OSC
control only.

What the log shows for segment 0006, bus 00: a root bus with one I/O window and one memory window of 1 MiB, mapped to bus
addresses 0x00000000 to 0x000fffff. Both 128 MB BARs fail to claim with "no compatible bridge window": 0006:00:00.0 BAR 0 at
0x08000000 (prefetchable) and 0006:00:00.1 BAR 0 at 0x10000000. Devices on segments 0001, 0003 and 0004 (tg3, IOC4, sata_vsc,
EHCI, OHCI) fail to enable with "BAR n [mem size ...] not assigned". The 0006 functions never reach enable in the log, since
no driver binds to the boot VGA device.

Established (what the code does):

- Claim order. For each bus the core claims the nonzero BARs first (v4.14.83:arch/ia64/pci/pci.c:372-373), then calls the
  platform fixup (v4.14.83:arch/ia64/pci/pci.c:374). The SN2 non-ACPI code sets the SAL addresses in that fixup (v4.14.83:arch/ia64/sn/kernel/io_init.c:177-190). So the claim
  message uses the base the core read from config space (v4.14.83:drivers/pci/probe.c:196-199, 283-287), and the SAL
  addresses are applied after it.
- SAL inputs. Bus records come from SN_SAL_IOIF_GET_PCIBUS_INFO (0x02000056; io_init.c:49-59, 229-233), called per segment
  and bus (io_init.c:298-307). Per-device BAR addresses come from SN_SAL_IOIF_GET_PCIDEV_INFO (0x02000057; io_init.c:64-78,
  168-172). A zero SAL address leaves the BAR unchanged (io_init.c:179-180).
- Root window. The root bus gets only two windows, both from the PROM's legacy bases: I/O of 64 KiB and memory of exactly
  1 MiB, starting at bus address zero (io_init.c:127-141, 248-257). The 1 MiB size is a constant in the kernel (io_init.c:139).
  It does not come from TIOCA or PIC, and it applies to every root bus on this path whatever its ASIC. The log does not print
  each bus's ASIC type, so the provider behind 0006 is unknown.
- Claim rule. A BAR is claimed only when a window contains its address after translation. An address outside every window
  translates at offset zero (v4.14.83:drivers/pci/host-bridge.c:74-98). Bus addresses at or above 0x00100000 find no window,
  and the claim fails (v4.14.83:drivers/pci/setup-res.c:153-159).
- Failure state. A failed claim sets IORESOURCE_UNSET on the BAR (v4.14.83:drivers/pci/setup-res.c:155-157). The SAL
  addresses do not clear that flag. Enable refuses an UNSET BAR with "not assigned" (setup-res.c:421-425).
- Path choice. The ACPI path needs DSDT OEM revision 0x20101 or higher (v4.14.83:arch/ia64/include/asm/sn/acpi.h:13), and the
  revision is read from the DSDT at boot (v4.14.83:arch/ia64/sn/kernel/io_common.c:462-469). Revision 0x20001 selects the
  non-ACPI path, so the ACPI _CRS windows never apply to this boot.

Inferred:

- The PROM wrote 0x08000000 and 0x10000000 into the BAR registers before the kernel ran. The SAL device-info values were not
  printed, so whether they match is unknown.
- The 128 MB BARs could not be claimed on this kernel under any firmware values. The only root window is 1 MiB, and a 128 MB
  BAR does not fit. The non-ACPI path creates no bridge window of its own. So on this boot the framebuffer and its second
  function were unusable, and the boot is not a working-graphics reference.
- One card, not two pipes. Both functions sit on bus 0 of one segment, and a pipe has its own TIOCA bus. The chip is
  unknown: the kernel names no device, and the log prints no vendor ID.

What an emulated PROM must return on this kernel:

- To reproduce the failure: a BAR whose bus address is at or above 0x00100000 gets "no compatible bridge window" and
  "not assigned" on enable, whatever the SAL address says. The 0006 BARs and the segment 0001 and 0004 devices show this.
- To avoid it: the BAR must sit inside the root's 1 MiB legacy window, so its bus address and size both fit below 0x00100000
  (the root's legacy memory base comes from the PROM's bus record). A 128 MB BAR can never meet that, so this kernel cannot
  make the framebuffer usable through this path.
- A PROM cannot repair an UNSET BAR through the SAL addresses, because the flag stays set after the failed claim.
- The other lever is the DSDT OEM revision, which selects the ACPI path. That path reads the root bridge's _CRS windows and
  was not exercised by this boot.

Changes from the 2.6.5 record (b04c657), v4.14.83 against 2.6.5:

- SAL gate: v4.14.83 adds the SHub 1 test (v4.14.83:arch/ia64/sn/pci/tioca_provider.c:592). Commit d3e5e1a1b4f4 (2006-06-28,
  in the linux-sn2 history) added it, so 2.6.5 lacks it (established). A v4.14.83 kernel therefore skips the SAL-revision
  check on an SHub 2 machine.
- Closest node: 2.6.5 left the controller node unset. v4.14.83 sets it (v4.14.83:arch/ia64/sn/pci/tioca_provider.c:656).
- GART setup: the same eight register writes in the same order as b04c657 recorded, two lines higher
  (v4.14.83:arch/ia64/sn/pci/tioca_provider.c:181-203). The 2.6.5 bodies were not re-read.
- AGP: one bridge per TIOCA with devices, and the bridge takes the last list entry. The VGA and AGP checks at
  v4.14.83:drivers/char/agp/sgi-agp.c:296-300 only skip. The mode word and 1 GiB aperture are unchanged
  (v4.14.83:drivers/char/agp/sgi-agp.c:104-105, 309-316). The AGP driver does not load on this boot.

### Same BAR path on linux-sn2 and 2.6.5-7.308 (read 2026-11-22)

linux-sn2 is the 7.3 SN2 tree (HEAD 641358e). Its SN2 port is one commit, b2907419d758 (2026-04-04), on top of the
upstream removal in cf07cb1ff4ea (2019), so its SN2 code is a port of the 4.14 code with local changes. Two later
commits touch the BAR path: 24d78bf62c12 (bridge claims) and 641358e (I/O space). The 2.6.5 side is the
kernel source RPM from the ProPack 4SP4 extensions disc.

| Step | v4.14.83 | linux-sn2 | 2.6.5-7.308 | Grade |
|---|---|---|---|---|
| Root windows | One 1 MiB legacy I/O and memory window (io_init.c:128-141, 248-257) | Same numbers (io_init.c:128-141, 265-271) | None built. The SN2 path sets no controller windows (io_init.c:341-434) | established |
| Device BAR claim | Needs a parent window, else UNSET (setup-res.c:153-161) | Same check (setup-res.c:156-160); device claims at pci.c:339-352 | Inserts under the global root with no window check (setup-res.c:94-118; pci.c:334-362) | established |
| Bridge window claim | Claimed (pci.c:344-359) | Skipped on the non-ACPI path (pci.c:371; commit 24d78bf62c12) | Not claimed (pci.c:368-376 loops over devices only) | established |
| SAL address | Raw address written, then inserted; UNSET kept (io_init.c:177-201) | Raw address written, UNSET cleared, inserted under the global root, parent forced on insert error (io_init.c:189-217; UNSET clear and fallback added by b2907419d758) | Written after the scan, through an uncached-region transform, in place, with no re-insert (io_init.c:284-301, 520-522) | established as the code; meaning of the 2.6.5 value unknown |
| Enable | Refuses UNSET or unclaimed BARs (setup-res.c:421-430) | Same two refusals (setup-res.c:510-520) | Refuses only a zero start with a nonzero end (pci.c:404-409) | established |
| ACPI path gate | DSDT OEM revision 0x20101 or higher (acpi.h:13) | Same gate (acpi.h:13); root windows from the _CRS walk (pci.c:164 onward) | Root windows from _CRS (pci.c:255-330) | established as the code |

Established (what the code does):

- The biggest difference is the claim itself. 2.6.5 has no parent-window test, so a BAR at its PROM address is inserted
  under the global memory root unless it collides. v4.14.83 and linux-sn2 both refuse a BAR that no window contains.
  The "no compatible bridge window" failure is therefore a product of the newer generic claim code, not of the SN2 path.
- linux-sn2 handles a refused BAR by clearing UNSET after the SAL address is applied and then inserting it directly
  under the global root (io_init.c:199-217). It does not add a window. So on the non-ACPI path the 1 MiB window is no
  longer what makes a BAR usable. The enable check then passes because the parent is set (setup-res.c:516).
- linux-sn2 skips the bridge-window claim on the non-ACPI path (pci.c:371). That stops a PROM-programmed window from
  being written back disabled. It does not change how device BARs get a parent.

Inferred:

- On the ACPI path (DSDT revision 0x20101 or higher), linux-sn2 builds real root windows from the root bridge's _CRS.
  A 128 MB BAR then fits a real window and claims normally. The commit that added the I/O space fix (641358e) reports a
  Prism with two FireGL X3 cards on DSDT 0x20101 with working BARs. That is the author's test, not a boot log we hold.
- The emulator observation (a newer SN2 tree that printed "no compatible bridge window" but still bound an R300 with a
  128 MB BAR0) fits linux-sn2's UNSET clear and global-root insert. It does not show which branch ran. Grade stays
  inferred; it is only the motivation for this comparison.
- 2.6.5 leaves a 128 MB PROM BAR usable when its address does not collide with another resource, since nothing checks a
  window and enable does not refuse it. The disc's fglrx package is built for this kernel's package set, so that is the
  path it would use. Whether the PROM's address for this BAR is correct is unknown (see the questions page).

Unknown:

- Whether the 2.6.5 uncached-region transform (io_init.c:294) yields a bus address. Its result is a CPU-side address, and
  the in-place rewrite does not re-insert the resource, so the resource tree may keep the PROM address. The code does not
  settle which one the device uses.
- Which path 2.6.5 takes on the 2019 PROM. Its DSDT revision was not read.
- The v4.14.83 ACPI window code. It sits in a separate file (io_acpi_init.c), which this comparison did not read.

## Graphics boards and outputs

- Boards named in the guides: **FireGL X2PRO-256** and **FireGL X3-256**. The -003 revision note says it "added FireGL
  X3-256 card" (007-4701-003 p.iii), and the -003 and -004 figure captions name the X2PRO-256 as the other board (Figures 1-1
  and 1-2, pp.3 and 4). The -001 (Oct 2004) and -002 (Feb 2005) guides name no board model at all: their rear-view captions
  say only "XG2N Graphics Module". Both boards are "ATI" FireGL boards (ATI and Radeon trademark notice, 007-4701-003
  p.ii). Established as names.
- **X2PRO-256 is an R350 board (inferred).** All four editions of the user's guide (007-4701-001 p.18, -002 p.20, -003 p.23,
  -004 p.23) print the same sample `lspci` output for the "verify system connections" step: per pipe a VGA-class function
  `ATI Technologies Inc Radeon R350 NG [FireGL X2]` and a second function `Radeon R350 [FireGL X2] (Secondary)`, at
  `11:01.0`/`11:01.1` and `12:01.0`/`12:01.1` with `(rev xx)` placeholders (established: SGI's own text names the
  R350 FireGL X2 as the part a Prism pipe shows; a documentation sample, not a capture). The first release had only one
  board, so that sample describes the board the later guides call X2PRO-256 (inferred: the guides never write "X2PRO-256"
  next to the sample). The sample was not updated when the X3-256 was added, so it says nothing about the X3. Supporting,
  not deciding: the driver table's X2 row is R350 `4E4B` (below), and the public `pci.ids` names `4E4B` "FireGL X2 AGP Pro",
  which fits the "PRO" in SGI's name (external list, inferred). Not R360: the only R360 row in the driver table is the
  Radeon 9800 XT (`4E4A`). Grade of the verdict: **inferred**, strong; it becomes established when a Prism `lspci -nn`
  prints `1002:4e4b`.
- The X3-256 as R420 (`4A4D`) is established as the driver's name-to-chip pairing only; ATI's FireGL X3-256 is R420-based
  per the driver table, and the sample lspci block in the guides does not cover it.
- **Chip table in the driver (table text established; board mapping not).** `fglrx_drv.o` (8.12.1) holds rows of the form
  `name (family device-ID)`: `FireGL X2-256/X2-256t (R350 4E4B)`, `FireGL X3-256 (R420 4A4D)`, `FireGL X1 (R300 4E47)`, and
  V-series and T2 rows for RV350 `4154`, RV370 `5B64`, RV380 `3E54`, RV410 `5E48` and R423 `5550`. The table has no `X2PRO`
  string (checked in the SP2, SP3 and SP4 builds of the extensions disc; the three tables list the same rows), so the
  chip of SGI's X2PRO-256 rests on the guide sample above, not on the driver. The X3-256 to R420 `4A4D` pairing is
  established in the driver; that the Prism X3 board is that device is **inferred**. Reading the second field as the PCI device ID is a software
  expectation. The public `pci.ids` names agree for `4A4D` and `4E4B`, but that list is external. SGI's `gfxtopology` maps
  the lspci names `R300`, `R350`, `RV350` and `R420` to board type `SG2` (script text, established).
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
  a boot of a Prism ([the qualification page](../../software/firmware/snprom/images.md) grades it). The only firmware requirement in Linux is generic: `tioca_bus_fixup` refuses to set up a TIOCA unless
  the SAL revision is at least `0x0406` ("SGI prom rev 4.06 or greater required for tioca support",
  `v5.3:arch/ia64/sn/pci/tioca_provider.c`). Established as the code. The 2.6.5-7.244 and 2.6.16.60-0.21 trees (read
  2026-11-21, below) gate only on that revision and have no SHub test, so the "SHub 1 only" and "skipped for SHub 2" wording
  from v5.3 is **unconfirmed** here. The SAL calls the kernel makes are on [the SAL page](../../software/sal/README.md).
- **Public boot logs.** Two serial-console boot logs in a 2019 public forum post (forums.irixnet.org, thread 849, post 12) are
  the only Prism kernel logs held. The poster calls the machine a deskside or rack Prism with two CPUs and one node. Both print
  `booting generic kernel on platform sn2`, `SAL 3.2: SGI SN2 version 4.65` and six ACPI tables with SGI SN2 OEM IDs
  (established, as posted). Neither names a SHub, a PROM build, a TIOCA or AGP device, or the shape; the raw HTML of page 2
  of the thread has no `tioca`, `shub` or `agp` text. The 4.14.83 log lists PCI host bridges 0001:00 to 0006:00 and a boot VGA device at 0006:00:00.0
  and a second function 0006:00:00.1; each function's prefetchable BAR 0 is 128 MB (0x08000000-0x0fffffff and 0x10000000-0x17ffffff) and neither could be placed by the kernel (corrected 2026-11-21: this page said one 256 MB BAR). The 3.8.13 log puts an SGI IOC4 (10a9:100a), a PCI-to-PCI bridge (104c:ac28,
  `PCI2050` in pci.ids), a Vitesse SATA controller (1725:7174) and a Broadcom NIC (14e4:1645) on domain 0001 bus 0. The 4.14.83
  log has USB functions (OHCI and EHCI drivers) at 0001:01:02.0 to 0001:01:02.2, behind that bridge. Whether the bridge is PCI-X
  is unknown: the log prints no bus mode. The shape stays unknown; this device set fits a rackmount base I/O module as well as
  the deskside.
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

## Held PROM images and Prism support

Scan of the snprom PROM images held in the software mirror and the chips root, checked 2026-11-21. Each shub1 image (`shub1snprom.bin`
from 10.20; `snprom.bin` before it, which the 10.20 README calls the old name) was read from its RPM's boot/efi payload, read-only.
The gzip components named by its FIT were expanded in memory and scanned with the image. FIT lengths are in 16-byte units; every gzip
component ends at its stream end. Nothing was disassembled or run. A string shows what the code can say, not what it does. Grades:
*established* means the string or README text is in the file, *inferred* a reading past it with the reason given, *unknown* not settled.

The holdings evidence lists 31 snprom RPMs (2004 to 2008). This scan reads 29 of them: the 28 in the mirror's ProPack 4 directory
(`yourepo.tar.gz`, 4.20 build 41216 to 10.54) and snprom 4.04 from the ProPack 4 CD 2 image in the same tarball. The 10.40 RPM on the
ProPack 4 SP4 CD 2 is byte-identical to the mirror copy (sha256 `84a0d30c...`). Snprom 4.20 build 41216 carries the same `snprom.bin`
as build 40503, so it has no row of its own. The 3.32 row is from the earlier scan; its RPM is not in the copy read here.

| Package | Image | SAL banner | Built | SAL 4.06 or later | sha256 (first 12) |
|---|---|---|---|---|---|
| snprom 3.32, build 30085 | `snprom.bin` | 3.32 rel040406 IP41 | 2004-04-06 | no | `cce7adf38c0b` |
| snprom 4.20, build 40503 | `snprom.bin` | 4.20 rel050614 IP41 | 2005-06-14 | yes | `0fdd129ecc2e` |
| snprom 4.31, build 41991 | `snprom.bin` | 4.31 rel050815 IP41 | 2005-08-15 | yes | `940d0572ae56` |
| snprom 4.32, build 42255 | `snprom.bin` | 4.32 rel050826 IP41 | 2005-08-26 | yes | `0d472fdf1662` |
| snprom 4.33, build 43044 | `snprom.bin` | 4.33 rel050928 IP41 | 2005-09-28 | yes | `d240e02343eb` |
| snprom 4.43, build 44607 | `snprom.bin` | 4.43 rel051202 IP41 | 2005-12-02 | yes | `035274812b50` |
| snprom 10.5, build 49047 | `snprom.bin` | 4.55 rel060605 IP41 | 2006-06-05 | yes | `e4b15c43dcc1` |
| snprom 10.6, build 49286 | `snprom.bin` | 4.56 rel060615 IP41 | 2006-06-15 | yes | `d2f1d33f3149` |
| snprom 10.11, build 52277 | `snprom.bin` | 4.61 rel061018 IP41 | 2006-10-18 | yes | `4429f5b1f496` |
| snprom 10.11, build 52277 | `ip65prom.bin` | 1.11 rel061018 IP65 | 2006-10-18 | no (SHub 2 series) | `372e74f7201d` |
| snprom 10.13, build 53000 | `snprom.bin` | 4.63 rel061117 IP41 | 2006-11-17 | yes | `99f6e19f18fe` |
| snprom 10.15, build 53414 | `snprom.bin` | 4.65 rel061204 IP41 | 2006-12-04 | yes | `c9fe5f03cae5` |
| snprom 10.20, build 54294 | `shub1snprom.bin` | 4.70 rel070110 IP41 | 2007-01-10 | yes | `c1eaa9c2f723` |
| snprom 10.23, build 55327 | `shub1snprom.bin` | 4.73 rel070222 IP41 | 2007-02-22 | yes | `ecc02724e066` |
| snprom 10.24, build 55786 | `shub1snprom.bin` | 4.74 rel070313 IP41 | 2007-03-13 | yes | `ee68afb2ca93` |
| snprom 10.30, build 56501 | `shub1snprom.bin` | 4.80 rel070412 IP41 | 2007-04-12 | yes | `716f71f8033b` |
| snprom 10.32, build 57173 | `shub1snprom.bin` | 4.82 rel070510 IP41 | 2007-05-10 | yes | `8f5e3e7cb545` |
| snprom 10.33, build 57534 | `shub1snprom.bin` | 4.83 rel070525 IP41 | 2007-05-25 | yes | `99224eb444de` |
| snprom 10.34, build 58301 | `shub1snprom.bin` | 4.84 rel070626 IP41 | 2007-06-26 | yes | `c696b3ef70ac` |
| snprom 10.35, build 58805 | `shub1snprom.bin` | 4.85 rel070717 IP41 | 2007-07-17 | yes | `6391dfe787f3` |
| snprom 10.36, build 59285 | `shub1snprom.bin` | 4.86 rel070806 IP41 | 2007-08-06 | yes | `fd3de49dfb64` |
| snprom 10.37, build 60198 | `shub1snprom.bin` | 4.87 rel070913 IP41 | 2007-09-13 | yes | `7ecf858d10d3` |
| snprom 10.39, build 62073 | `shub1snprom.bin` | 4.89 rel071130 IP41 | 2007-11-30 | yes | `a9b55ca3d5cb` |
| snprom 10.40, build 62478 | `shub1snprom.bin` | 4.90 rel071217 IP41 | 2007-12-17 | yes | `26170cc83c3d` |
| snprom 10.40, build 62478 | `shub2snprom.bin` | 1.40 rel071217 IP65 | 2007-12-17 | no (SHub 2 series) | `1c8144e3d318` |
| snprom 10.41, build 63582 | `shub1snprom.bin` | 4.91 rel080201 IP41 | 2008-02-01 | yes | `5a030c1e3ba9` |
| snprom 10.42, build 64020 | `shub1snprom.bin` | 4.92 rel080219 IP41 | 2008-02-19 | yes | `6af5afa691c9` |
| snprom 10.50, build 65357 | `shub1snprom.bin` | 5.00 rel080415 IP41 | 2008-04-15 | yes | `90d8e7c0e9f5` |
| snprom 10.52, build 67935 | `shub1snprom.bin` | 5.02 rel080731 IP41 | 2008-07-31 | yes | `f7e3a85ad527` |
| snprom 10.53, build 68395 | `shub1snprom.bin` | 5.03 rel080819 IP41 | 2008-08-20 | yes | `b6bebb02c50d` |
| snprom 10.54, build 70399 | `shub1snprom.bin` | 5.04 rel081111 IP41 | 2008-11-11 | yes | `51ccf9ad830b` |
| snprom 10.54, build 70399 | `shub2snprom.bin` | 1.54 rel081111 IP65 | 2008-11-11 | no (SHub 2 series) | `3ea833181fda` |

Build dates are the RPM header build times from the holdings evidence, not re-read here. The SAL 4.06 column compares the banner
version with the revision the Linux check reads, which is inferred to be the same number.

Marker counts, uncompressed image / expanded components. Counted from printable strings of four or more bytes, as `strings` would
print them: `AGP`, `TIO`, `ATI`, `FireGL` and `XG2N` as whole words, the rest as substrings.

| Image | TIOCA | TIOCE | AGP | `SHub 1.2` | TIO (word) | Board names in the bytes | IP57, Prism, XG2N, ATI, FireGL, IP53, IP67 |
|---|---|---|---|---|---|---|---|
| 3.32 `snprom.bin` | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 14 / 11 | IP41 | 0 |
| 4.04 `snprom.bin` | 3 / 0 | 0 / 0 | 8 / 0 | 0 / 1 | 22 / 13 | IP41 | 0 |
| 4.20 `snprom.bin` | 2 / 0 | 0 / 0 | 8 / 0 | 0 / 1 | 23 / 14 | IP41 | 0 |
| 4.31 `snprom.bin` | 3 / 0 | 0 / 0 | 9 / 0 | 0 / 1 | 23 / 14 | IP41 | 0 |
| 4.32 `snprom.bin` | 3 / 0 | 0 / 0 | 9 / 0 | 0 / 1 | 23 / 14 | IP41 | 0 |
| 4.33 `snprom.bin` | 3 / 0 | 0 / 0 | 9 / 0 | 0 / 1 | 23 / 14 | IP41 | 0 |
| 4.43 `snprom.bin` | 3 / 0 | 4 / 0 | 9 / 0 | 0 / 1 | 23 / 14 | IP41 | 0 |
| 10.5 `snprom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 14 / 5 | IP41 | 0 |
| 10.5 `ip65prom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 0 | 14 / 4 | IP41, IP65 | 0 |
| 10.6 `snprom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 14 / 5 | IP41 | 0 |
| 10.6 `ip65prom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 0 | 14 / 4 | IP41, IP65 | 0 |
| 10.11 `snprom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 14 / 5 | IP41 | 0 |
| 10.11 `ip65prom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 0 | 14 / 4 | IP41, IP65 | 0 |
| 10.13 `snprom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 14 / 5 | IP41 | 0 |
| 10.13 `ip65prom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 0 | 14 / 4 | IP41, IP65 | 0 |
| 10.15 `snprom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 14 / 5 | IP41 | 0 |
| 10.15 `ip65prom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 0 | 14 / 4 | IP41, IP65 | 0 |
| 10.20 to 10.36 `shub1snprom.bin` (each) | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 14 / 5 | IP41 | 0 |
| 10.37, 10.39, 10.41 to 10.53 `shub1snprom.bin` (each) | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 12 / 4 | IP41 | 0 |
| 10.40 `shub1snprom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 12 / 4 | IP41 | 0 |
| 10.40 `shub2snprom.bin` | 6 / 0 | 5 / 0 | 7 / 0 | 0 / 0 | 12 / 4 | IP41, IP65 | 0 |
| 10.54 `shub1snprom.bin` | 3 / 0 | 5 / 0 | 7 / 0 | 0 / 1 | 12 / 4 | IP41 | 0 |
| 10.54 `shub2snprom.bin` | 6 / 0 | 5 / 0 | 7 / 0 | 0 / 0 | 12 / 4 | IP41, IP65 | 0 |

The `SHub 1.2` column counts both `SHub 1.2` and `SHUB 1.2`. The TIOCE column counts the standalone five-byte string `TIOCE`; earlier
counts left it out and read one lower. Matching is case-sensitive: case-insensitive matching counts 69 in 4.43, 65 of them lower-case
`tioce` in the body. TIOCE cannot overlap itself, so overlapping matches do not change it.

- **TIOCA and AGP (established as strings).** `TIOCA commands`, `AGP GART Mapped` and `Could not find KLSTRUCT_TIOCA` are in the
  uncompressed body of 4.04 and every later build; 3.32 has none of them. `tioca_agp_func_init: Found AGP capability` appears from
  4.31 on, and TIOCE first appears in 4.43. What the code does with these strings is unknown.
- **Prism (none named).** No held image contains `Prism`, `IP57`, `XG2N`, `FireGL`, `ATI` as a word, `IP53` or `IP67`. The SHub 1
  images name IP41 only and the SHub 2 images IP65 only. `SHub 1.2` in mixed case is in the expanded components of every SHub 1 image
  scanned and in no uncompressed body; its context was not read.
- **README (10.20 onward).** `README.snprom` first ships in package 10.20 and is in no earlier build. Every README from 10.20 to 10.54
  lists, for `shub1snprom.bin`, the Altix 330, 350, 3300, 3700, 3700 Bx2, Prism Rackmount and Prism Deskside (established as the
  text; each README carries the two Prism lines). For `shub2snprom.bin` it lists the Altix 4700, and from 10.23 the Altix 450.
  Five README variants by sha256 prefix: 10.20 `322469680d4d` (870 bytes); 10.23 to 10.40 `afd8bc7587d8` (881); 10.41 and 10.42
  `d5f012760182` (2064); 10.50, 10.52 and 10.53 `d7a8d90bf7a1` (2064); 10.54 `00f0a21d82c4` (6112). The README is vendor intent, not a boot.

**Earliest build with TIOCA support.** Snprom 4.04 (build 35871, banner `4.04 reorg041203 IP41`): three TIOCA strings are present,
including `tioca_attach: TIOCA error`, which 4.20 does not have (established as strings). 3.32 has none. It is not a Prism build;
nothing in it names one.

**Earliest build whose README names Prism.** Snprom 10.20 (build 54294, 2007-01-10, README-1): its shub1 image is listed for Prism
Rackmount and Prism Deskside (established as text). No build before 10.20 has a README, so no held text before 10.20 names a Prism.

**Other shub1 builds that list Prism.** Every build from 10.20 to 10.53 (17 builds, with the same two Prism lines in each README).
Whether any of them accepts a Prism is unknown. No image contains a Prism string, and the PROM does not branch on the board name
(boot-path review), so the strings cannot settle acceptance.

**Earliest build that could boot a Prism.** No build can be shown to boot one. Inferred from SGI's list and the SHub 1 generation:
the 10.20 image (SAL 4.70) is the earliest held shub1 image the vendor lists for Prism, and the 10.54 image (SAL 5.04) the newest. The
SHub 2 images are not Prism images by SGI's list. The 2019 Prism logs print `SGI SAL version 4.65`. Snprom 10.15 (build 53414, banner
`4.65 rel061204`) is the only held image with that banner, so it is the candidate for those logs' PROM. That is inferred from the version
number alone; the log's build date would settle it, and the logs were not read again for this page.

**Unsure.**
- The 3.32 row comes from the earlier scan and was not run again here.
- The 4.06 column assumes the banner version is the revision the Linux check reads; that is inferred, not read from the revision field.
- The 1.x series fails the numeric check, but the Linux check runs only on the SHub 1 path, so it says nothing about SHub 2.
- The code behind the TIOCA strings was read for 4.65 and 5.04 only (next two sections); no other build was read.
- Build dates in the table are from the RPM headers, as recorded in the holdings evidence.


### SAL 4.65 against SAL 5.04 (Ghidra read, 2026-11-22)

Question: does an emulated Prism need the SAL 4.65 image the 2019 real-Prism logs print, or is SAL 5.04 enough? Both images were
loaded as flat IA-64 flash, analysed and decompiled whole in Ghidra, and the functions quoted below were cross-checked in
`ia64-linux-gnu-objdump` output (instruction text compared with registers and call targets masked: `ca_discover` and the type fold
identical; `tio_init` and `tioca_space_to_xtalk` differ in under 1 percent of instructions). Nothing was run. Cited as image@address; image names are the package
file, so `10.15 snprom.bin` is SAL 4.65 and `10.54 shub1snprom.bin` is SAL 5.04. Grades: *established* is read in both images,
*inferred* is reasoned from what was read, *unknown* is not settled. No firmware bytes or listings are recorded here.

**Image identity (established).** Package `snprom-10.15-53414.ia64.rpm` (6,279,820 bytes, from the ProPack 4 package tree) holds two files:
`snprom.bin` (6,291,456 bytes, sha256 `c9fe5f03cae5553a0ce9e5cbd33e3bfe36a064f761a013e7a53d02232ee4622e`, banner `SGI SAL Version 4.65
rel061204 IP41 built 02:16:27 PM Dec 4, 2006`) and `ip65prom.bin` (12,582,912 bytes, the SHub 2 series, not read here). The first
is the SHub 1 image. Like 4.43 it still embeds its compiler command line at `10.15 snprom.bin@0xffc1a328` and `@0xffc40588`, which defines
`CPUBOARD=IP41`, `IOBOARD=TIO`, `CONFIG_TIO`, `HWREGS_TIO`, `SHUB1`, `TIO_CX_CLOCK_RESET_WAR` and `IP41`; 5.04 has no command line.
That is why `IP41` counts 11 in the 4.65 body and 7 in 5.04 (4.65's extra four are the two copies of the command line).

**FIT and composition against 5.04 (established).**

| | 4.65 (10.15) | 5.04 (10.54) |
|---|---|---|
| PAL_B 7.79, 5.73, third | `0xffdc0000`, `0xffe70000`, `0xfff20000` (third 2.15) | `0xffdc8000`, `0xffe78000`, `0xfff28000` (third 2.25) |
| PAL_A 7.31, 5.37, 1.27 | `0xfffbafc0`, `0xfffc1ac0`, `0xfffc8280` | same bytes, `0xfffc2fc0`, `0xfffc9ac0`, `0xfffd0280` |
| SAL_A (16 KiB) | `0xffc3d000` | `0xffc4e000` |
| SAL_B | `0xffa01000`, 0x23b6d0 bytes | `0xffa01000`, 0x24cf90 bytes |
| SAL runtime (type 0x12, gzip) | `0xffc41000`, 1,019,168 bytes expanded | `0xffc52000`, 918,824 expanded |
| type 0x13 (gzip ELF) | absent | `0xffc8f410`, 619,440 expanded |
| EFI (type 0x1f, gzip) | `0xffc81b10`, 3,298,360 expanded | `0xffca5ec0`, 2,495,544 expanded |
| type 0x22 archive | `0xffd61440`, 860,160 expanded | `0xffd683d0`, 860,160 expanded |
| type 0x23 | absent | `0xffdc0820`, 672 bytes |

The three PAL_A images and the first two PAL_B images are byte-identical in the two builds (a matching sha256 for each). The third PAL_B
(the one for Itanium 2 family `0x1f` model 2, version 2.15 against 2.25) differs in 131,895 of its 634,816 bytes. Both builds' top-of-image
block, FIT head and SAL_A entry pointers have the same layout.

**Question 1: board names and marker counts (established).** Board names in the 4.65 image: `IP41` only. No `IP57`, `Prism`, `XG2N`,
`FireGL`, `IP53`, `IP67` or `IP65` string in the body or in any expanded component. The counts below use the page's method (printable
strings of four bytes or more; `AGP` and `TIO` as whole words). They equal the table above for 10.15. The 5.04 counts are the same except raw TIO word 12 and IP41 7 (4.65's two command-line copies account for both differences: two `TIO` words and four `IP41`) and, in the EFI, TIO word 0 and IP41 1:

| 4.65 | TIOCA | TIOCE | AGP | `SHub 1.2` | `SHub 1.1` | `SHub 1.x` | TIO (word) | IP41 |
|---|---|---|---|---|---|---|---|---|
| raw body (6 MiB file) | 3 | 5 | 7 | 0 | 0 | 0 | 14 | 11 |
| SAL runtime (type 0x12) | 0 | 0 | 0 | 1 | 1 | 1 | 4 | 0 |
| EFI (type 0x1f) | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 3 |
| archive (type 0x22) | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

The `SHub 1.2` string is in the SAL runtime only, with `SHub 1.1` and `SHub 1.x` next to it (the same three in 5.04's runtime). Its use was not
read, so no revision preference is claimed (unknown).

**Question 2: what each needs at reset (established unless marked).**

- *Reset entry and `main`.* SAL_A's normal reset-path constants are the same in the two builds. The 4.65 SAL_A `movl` set is the 5.04 set
  without four values, all in 5.04's fault paths: `0x8000008110030000` (the reason 1 and 2 read), `0x8000008120000000`,
  `0x1000100000000` and `0x28000000000` (the "PAL early self-test failed" block at `10.54 shub1snprom.bin@0xffc4e256`). The election, history and LED
  registers, the `0x81_101d_0100` bits 41:39 and the progress codes are shared. SAL_B's reset entry (`10.15@0xffa1dc40`,
  `10.54@0xffa1de00`) and `main` (`10.15@0xffa19880`, `10.54@0xffa19a20`) decompile to the same text. A model that satisfies the first-stage list in
  [the images page](../../software/firmware/snprom/images.md) satisfies both.
- *CPU tables in SAL_A.* The three-row first table (`10.15@0xffc40a70`, `10.54@0xffc51648`) has the same three keys `0x1f000404`,
  `0x1f010504` and `0x1f020104` and the same PAL_A words; the PAL_B word of the third row is `0x215` in 4.65 and `0x225` in 5.04, matching the third
  PAL_B. The second table (`10.15@0xffc40000`, 13 rows; `10.54@0xffc51000`, 15 rows) has seven family `0x1f` rows that are byte-identical in
  the two builds. The family `0x20` rows differ: 5.04 adds two rows (`0x20010004`, `0x20010104`) and changes the trailing words of three
  (`0x20000404`, `0x20000504`, `0x20000704`). A Prism's Itanium 2 parts, if family `0x1f`, meet the same rows in both; which CPU a Prism carries is not read (unknown).
- *System controller.* `sysctl_probe` is the same one-line test in both (`10.15@0xffa7f6b0`, `10.54@0xffa806d0`): it fails only for
  the `cpuid[2]` signature `0xaeeeeeee8badbeef` and touches no hardware, unlike 4.43. A missing L1 is fatal in both. 4.65 repeats the whole command up to ten times while the
  receive status is -0x18, prints a "PANIC: request ... failed" and "Disabling node" message, then ends in fatal `0x8d` (`10.15@0xffa81a40`); 5.04 ends in `0x8d` on the
  first -0x18 (`10.54@0xffa82a10`). Both send with 50 tries of 500 ticks (`10.15@0xffa81900`, `10.54@0xffa82a10`).
- *Brick-type fold.* The fold is the same code (`10.15@0xffa7bee0`, `10.54@0xffa7d510`; objdump text identical): `o`, `5`, `m`, `@` become `c`;
  `,` and `}` become `.`; `d` becomes `r`; and `f`, `l`, `b`, `{` become `c` when the slab reply is 0 or -1. So 4.65 folds the same characters.
- *L1 requests.* The set of request codes sent to task 6 is the same: `0x0001`, `0x0003`, `0x0006`, `0x0008`, `0x0009`, `0x000a`, `0x000e`, `0x0010`, `0x0012`,
  `0x0013`, `0x0015`, `0x1005`, `0x1007`, `0x100a`, `0x100b`, `0x200d`, `0x200e`, `0x200f` and the one routine that takes its code as a variable
  (`10.15@0xffb4c9f0`, `10.54@0xffb5ed50`), plus the task 3 text sends. No request is added or removed. 4.65 keeps separate copies of the
  `0x0003`, `0x000e` and `0x0013` routines (`10.15@0xffa7ba90` and `0xffa7d030`, `0xffa7c500` and `0xffa7d8c0`, `0xffa7c130` and `0xffa7d4c0`); 5.04 has one of
  each plus the `0x4ffff000` wrappers. The call order in `main` is the same.
- *SAL calls.* 4.65 serves PCI configuration read and write calls (`0x02000047`, `0x02000048`; `10.15@0xffb1beb0`, `@0xffb1c1c0`), which 5.04 has dropped. The I/O interface dispatcher
  covers `0x02000051` to `0x0200005a`, `0x0200005f`, `0x02000060` and `0x02000064` in 4.65 (`10.15@0xffb1f260`) and adds `0x0200005b` to `0x0200005e` in
  5.04 (`10.54@0xffb1e660`). `0x0200005d` in 5.04 selects the VGA device (`10.54@0xffb3e7b0`), and the 5.04 EFI carries `SnSelectVGAConsole` while the 4.65 EFI has no such
  string; so 4.65 has no PROM-side VGA console selection. 4.65 does have `SN_SAL_BTE_RECOVER`, the feature-set calls (`0x02000061`, `0x02000065`, `0x02000066`)
  and the I/O interface init (`0x0200005f`), which 4.43 lacks.
- *Base I/O bring-up.* 4.65's SAL_B and runtime carry the PCI scan and klconfig builders for the IOC4 and other base I/O
  functions (`kl_init_pci`, `init_klcfg_ioc4`, `early_ioc4_nvram_init`, `pci_discover`, `ioc4_discover`; `10.15@0xffabf570`, `@0xffaf24d0`, `@0xffaf26f0`).
  None of those strings is in 5.04. Both EFI images carry the `AltixPciDeviceInit` string. So 4.65 touches the base I/O PIC and IOC4 in the PROM, and 5.04 leaves that to EFI
  (inferred: the missing strings may only mean the code was renamed or stripped). Prism guests need the base I/O either way.
- *Closest node for a TIOCA.* `tioca_attach` records a closest NASID in the TIOCA object (offset `+0x34`). 4.65 (`10.15@0xffb4e5f0`) starts at -1 and picks the node, other than the TIOCA's own
  NASID, with the smallest positive distance; 5.04 (`10.54@0xffb60ea0`) starts at the executing node and also requires that the node has memory. Same result on any topology where the
  compute node is the only candidate (inferred); a case where they differ was not constructed (unknown). 5.04 also allocates a 0xb8-byte object where 4.65 allocates 0xa8, and makes two calls after
  the register set-up that 4.65 lacks (not read).
- *TIOCA bus fix-up.* 5.04 has a TIOCA-specific bus fix-up (`10.54@0xffb7d700`) that also maps three PCI memory windows (`0x100000` to `0xbfffffff`); 4.65's per-ASIC hook for a TIOCA is NULL and it has no such windows
  (detail in the next section). Whether this changes any value the PROM returns to the kernel was not traced (unknown).

**Question 3: TIO and TIOCA at reset (established for the code, unknown where marked).**

- *Same code in both.* `tio_init` (`10.15@0xffaadfd0`, `10.54@0xffaaf110`) and `ca_discover` (`10.15@0xffaf0e90`, `10.54@0xffaf23f0`) are the
  same logic, `tioca_attach` differs in the closest-node loop, an object one quadword larger and two trailing calls in 5.04, and `tioca_space_to_xtalk` (`10.15@0xffb6dcb0`,
  `10.54@0xffb7de00`) is identical.
- *Absence is tolerated.* With no TIO lboard (type `0x12`) for a NASID, `tio_init` prints `tio_init: No TIO lboard for NASID 0x%x found!` and returns; nothing is fatal.
  A TIOCA with no function answering is also tolerated: `tioca_pci_init` (`10.15@0xffb6b4c0`, `10.54@0xffb7a680`) reads the vendor ID through a
  fault-tolerant access (`10.15@0xffb6e860`) and skips a function that returns `0xffff`.
- *What presence needs.* The TIO's slot type from the L1 request `0x0013` (`10.15@0xffac0230`, `10.54@0xffac0420`) selects what is probed. The TIOCA
  corelet (chiplet part `0xe020`) is initialised only when that type is `l` (0x6c), `^` (0x5e) or `b` (0x62), in both builds (`tio_init` tests it, then `ca_discover` tests it again);
  for any other type `tioca_attach` prints "ignoring board type" and attaches nothing. So the L1 reply for the TIO's NASID must carry one of those three letters. Corelets 0 to 2 are found by reading the chiplet ID word at each base (`nasid << 38`, stride `0x10000000` bytes) and sorted by part (`0xe000` or `0xe010`, `0xe020`); corelet 3 (the CX port) is
  tested through `0x8000_0008_b000_be18` reading `0xf`. A failed CX port set-up prints "CX PORT init failed" and the loop carries on with the next corelet (not fatal). These loads are unguarded. What a missing chiplet returns is unknown, so whether the PROM
  tolerates an absent corelet on real hardware is unknown; the model must return a part word that matches nothing, or the CX test value.
- *Rev 1 TIOCA.* In both, a TIOCA klconfig record with revision below 2 is skipped with a printed message; a missing `KLSTRUCT_TIOCA` (type
  `0x33`) prints a message and the VGA probe continues.
- *How the TIO is found.* `tio_init` is entered through a function table (`10.54@0xffc4c210` holds its caller; inferred to be the TIO class methods) after the TIO lboard exists. Where the lboard is created was not traced; unknown
  for both builds. The SAL runtime's `tio_probe` (`10.15` runtime offset `0x10900`, `10.54` runtime offset `0x10cc0`) is only a part-number predicate (part `0x4422`) with no direct caller found, so no reset-time TIO probe was seen there.
- *Request check.* Neither build asks the L1 about a TIO beyond the shared `0x0013` and `0x000e` requests.

**Verdict (inferred; the grade is for the comparison, not for a boot).** SAL 5.04 is enough for a Prism model. The two builds need the same hardware at reset: the same L1 and requests, the same CPU rows for
family `0x1f`, the same TIO and TIOCA discovery and the same SHub 1 first stage. 5.04 adds only fault-path registers, and nothing in 4.65 asks for hardware that 5.04 lacks;
4.65's PIC and IOC4 bring-up in SAL_B is the same work as 5.04's EFI step. The case for 4.65 is fidelity to the 2019 logs: it prints the banner they show, assigns the TIOCA
BARs as the log shows (below; 5.04 assigns identically), has no PROM VGA selection and no `0x5b` to `0x5e` calls. A model that only
needs Prism guest boots can take 5.04. Neither image has been seen booting a Prism (unknown); both are SGI's stated `shub1snprom.bin` for Prism (vendor intent).

### What SAL 4.65 returns for a TIOCA bus and its devices (Ghidra read, 2026-11-22)

SAL calls `SN_SAL_IOIF_GET_PCIBUS_INFO` (`0x02000056`) and `SN_SAL_IOIF_GET_PCIDEV_INFO` (`0x02000057`) are cases of the I/O interface dispatcher
(`10.15@0xffb1f260`, `10.54@0xffb1e660`). Handlers are the same code in both builds (only a list offset in the node record moves).

- *`0x02000056` (established).* The dispatcher case is `10.15@0xffb1fcb0` (jump table `0xffb952a0`; call at `0xffb1fcdc`) and `10.54@0xffb1f300` (call at `0xffb1f32c`). It stores the lookup result through the
  out pointer and returns 0, or 1 when the result is NULL. The lookup helper is `10.15@0xffb29f10` (`10.54@0xffb2a140`): it walks the circular list at node `+0x78` (5.04: `+0x80`; each entry's record is at entry `+0x20`) and then the chain at node `+0x98`
  (5.04: `+0xa0`), matching segment at record `+0xc` and bus at `+0x8`. `tioca_attach` links its object on node `+0x88` (5.04: `+0x90`); the function that links the object onto `+0x78` or `+0x98` was not found, so how a TIOCA object
  reaches the lists the lookup walks is unknown. The returned record is the PROM's own object, not a copy. Its first 0x30 bytes match the
  published Linux `pcibus_bussoft` layout: ASIC type `+0x0`, XIO widget `+0x4`, bus `+0x8`, segment `+0xc`, legacy I/O base `+0x10`, legacy memory base `+0x18`, base `+0x20`, widget info `+0x28`
  (field names are Linux's; the offsets are read from the PROM stores and loads).
- *Provider fields for a TIOCA (established).* `tioca_attach` (`10.15@0xffb4e5f0`) stores ASIC type 4 at `+0x0` (Linux's TIOCA provider number), the corelet number at `+0x4`, the mapped TIOCA register base at `+0x20`
  and the corelet record at `+0x28`; it also stores the chip revision (ID register at `nasid << 38 | 0x8_9006_0e80`, bits 31:28) at `+0x30` and the closest NASID at `+0x34`. How the
  bus and segment words at `+0x8` and `+0xc` are filled was not traced (unknown).
- *Root window and the 5.04 difference (established).* No size field exists in the record. In 4.65 the generic `pciio_bus_fixup` (`10.15@0xffb3aab0`) maps, when the bases are zero, 0x10000 bytes (64 KiB) of PCI I/O space at offset 0 for the legacy I/O base
  and 0x100000 bytes (1 MiB) of PCI memory space at offset 0 for the legacy memory base, through the generic PIO map allocator (`10.15@0xffb37c70`). Its per-ASIC bus-fixup hook is NULL for a TIOCA (entry 1 of the type-4 operations table at `0xffc18e00`).
  5.04 has a TIOCA fix-up, `tioca_bus_fixup` at `10.54@0xffb7d700` (the function at `0xffb30330` that an earlier reading cited is `pcibr_bus_fixup`, the PIC one). It sets the same 64 KiB I/O base (record `+0x10`) and 1 MiB legacy memory base (`+0x18`), and also maps three memory windows
  up front: PCI `0x100000` to `0x3fffffff`, `0x40000000` to `0x7fffffff` and `0x80000000` to `0xbfffffff`. 4.65 has no such windows. Both builds still map each BAR in `pciio_device_setup` (4.65 `0xffb3a2f0`; 5.04 `0xffb3ef90`, whose three PIO-map calls are at `0xffb3f1bc`, `0xffb3f31c` and `0xffb3f54c`).
  Effect on the records (inferred): `0x02000056` has no field for the windows, so its fields and sizes are unchanged; the addresses chosen for the legacy bases come from the PIO allocator and were not compared. The windows may change the PIO address words `0x02000057`
  returns, and a BAR above `0xbfffffff` has no 5.04 window (the BAR pool reaches `0xffffffff`); neither was traced (unknown). `tioca_space_to_xtalk` (`10.15@0xffb6dcb0`, identical in 5.04 at `0xffb7de00`) maps TIOCA legacy memory (spaces 4 to 6) to window offset `0x8000000`
  when the range ends below 128 MiB, and refuses it (returns 0) when the offset field (bits 31:24) of the window control register at TIOCA base `+0x8` is non-zero; otherwise `0x40000000`. I/O maps to `0x3000000`, config to `0x1000000` (config limit 0xff), and a BAR (spaces 8 to 13) to its assigned PCI address plus
  `0x40000000` for memory. The kernel's 1 MiB root window equals the legacy memory size (inferred as the origin of the kernel's constant; the Linux side is the other section).
- *`0x02000057` (established).* `10.15@0xffb39670` and `10.54@0xffb3dbc0` are the same code. They find the device record by segment, bus and devfn, and rewrite quadword 7 as device and function bits, the parent bus number at bits 39:32 and the first argument shifted left 40 (the segment per the SAL README's call
  description; the earlier reading said the NASID, and the code shows only "first argument"). They copy 12 quadwords to the device buffer and, when quadword 11 (the interrupt record) is non-null, 10 quadwords from it to the interrupt buffer, and return 0.
  `pciio_device_setup` (`10.15@0xffb3a2f0`, "pciio_pio_addr: win %d is in space %s") fills the first seven: quadwords 0 to 5 are the PIO addresses of BAR 0 to 5 (PIO map of space `8 + i`, I/O BARs first, then memory BARs), and quadword 6 is the expansion ROM (space 1).
  The per-BAR table (type at `+0xa0`, flags `+0xa4`, PCI address `+0xa8`, size `+0xb0`, stride `0x38`) lies outside the copy, so no PCI address, size or flag is returned (established).
- *Where BAR values come from (established).* Not a copy of config space. `tioca_pci_init` (`10.15@0xffb6b4c0`, `10.54@0xffb7a680`, same pool constants) builds three first-fit pools per TIOCA:
  memory below 1 MiB `0xc0000` for `0x40000` bytes (used for BARs that say 'below 1 MiB'); other memory `0x100000` for `0xfff00000` bytes; I/O `0x1000` for `0xefff` bytes. For each function it writes `0xffffffff` to each BAR,
  reads the size mask, takes a block of that size aligned to its size from the pool, writes the address back (64-bit BARs get a zero upper half) and records flags, address and size. The expansion ROM is
  sized and placed the same way from the memory pool. A revision 1 CA gets function 0 only; other revisions probe up to eight functions when function 0 is multifunction. A function with an AGP
  capability then goes through `tioca_agp_func_init` (`10.15@0xffb6bf00`). 5.04 adds checks for allocation failure and for the ROM pool and is otherwise the same.
- *The 2019 addresses (inferred).* With a first-fit pool from `0x100000`, a 128 MiB BAR aligns up to `0x08000000`, which leaves `0x100000` to `0x07ffffff` free; a second 128 MiB BAR cannot use that block and lands at
  `0x10000000`. That matches the log's two BARs, so those values are what this allocator produces for two 128 MiB memory BARs on one TIOCA (the other BARs of the card are unknown, so the order of allocations
  is unknown). Smaller BARs take addresses from `0x100000` upward, also outside a 1 MiB window. The result depends on what was allocated before: a 128 MiB or larger BAR ahead of them, or two BARs of 64 MiB or more ahead of them, shifts both addresses (a 128 MiB BAR ahead takes `0x08000000`; two 64 MiB BARs take `0x04000000` and `0x08000000`); smaller BARs do not. Both builds assign identically, so the addresses do not separate 4.65 from 5.04.
- *Unknown.* The bus and segment numbering that `0x02000056` matches, how a TIOCA object reaches the lists the lookup walks, whether 5.04's three memory windows change the PIO addresses `0x02000057` returns, and the card's BAR set.

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
- **Package versions (ProPack 4SP4 extensions disc, read 2026-11-21).** `fglrx` 8.12.1 (`fglrx-4_3_99_8.12.1-sgi404r1`; the
  version string is in `fglrx_drv.o`), kernel `2.6.5-7.308-rtgfx` (`CONFIG_IA64_SGI_SN2=y`, `CONFIG_AGP_SGI_TIOCA=m`),
  XFree86 `4.3.99.902-43.91sgi404r1` (source RPM present, not read), `sgi-vizserver` 3.5.2.1 and `sgi-gfxtools` 1.0.
  Established as the package set on that disc. The disc is labelled ProPack "4SP4", but its vizserver README says Prism runs
  ProPack 4 Service Pack 3 (section 2.4.1). Which service pack the disc matches is **unknown**, and so is the ProPack 4 SP2
  kernel the guides name. The ATI device IDs are in [the chip table](#graphics-boards-and-outputs).

## What carries over from voyager

[voyager](https://github.com/jamesbraid/voyager) documents the ATI R300 (FireGL X1) and R350 (FireGL X2) as IRIX 6.5.30
drives them on the Onyx4 UltimateVision (IP35), and says it reads the IRIX binaries, IRIX software (source not cited), AMD register references and the
radeon drivers. This section uses only its public README, `devices/README.md` and `questions/open-questions.md`.

Could transfer, **inferred** only until a Prism board is identified:

- R3xx register behaviour (display, interrupt, engine, pipe-select and Z-buffer registers in voyager's `devices/display`
  and `devices/pipes`), because the Prism X2PRO is an R350-class part (inferred, see the boards section). The silicon would be the same; only the host bus differs.
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
- The X3-256 (R420 `4A4D` in the driver table) is outside voyager's chip list; voyager's page `devices/display/r350-r420-delta.md`
  lists what an R300-based model would have to add for R420, from public Linux and Mesa source only.
- voyager's open questions (bus clock and width behind a pipe, PIC topology) are Onyx4-specific; on Prism the answer is
  "AGP 8x on a TIOCA" for the bus, and the topology question becomes the TIOCA-per-pipe question here.

## The held Prism disk image (checked 2026-11-21)

The held image is a 4.18 GB ISO (SHA-256 `4fde2ed38816307ff1b33fbcb2a0cb4a97f80de13edfab0aabfa9f107d98d898`). It was copied,
checked against that hash, and its root filesystem read from the copy; nothing was run. It is a T2/Linux 26-svn community
build (`/etc/os-release` ID `t2sde`) with kernel `7.3.0-epic1-SN2-GPU`, not an SGI ProPack image (established, from the listing).

Absent from the root filesystem (established, from the listing): `/etc/sgi-release`; any PROM image, `/usr/cpu/firmware` tree,
`snxsc_firmware`, `flashsc` or `l1.bin`; `fglrx`; `XF86Config`; and every log or capture, including `dmesg`,
`/var/log/messages`, `/proc/sgi_sn` and `lspci` output. `/var/log` has only the faillog, lastlog, wtmp and sa entries and an
empty journal directory.

What it does hold (established, from the listing): the kernel's `sgi-agp` module, `tioca_bus_fixup`, `tioca_*` and `tioce_*`
symbols (a software expectation, not a chip count), and a modprobe file that sets `agpmode=8` for radeon on the TIO CA bridge.

Still wanted from a ProPack image; a listing of these would settle most of the unknowns:

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
2. Mechanical, fixed: the voyager section said voyager "reads only" binaries, radeon drivers and AMD references; its README also lists IRIX software (source not cited). It also said voyager's boards sit behind a PIC-fronted slot; voyager's open question says PIC against XBridge is unsettled (a PIC is established only as a case the IRIX kernel handles). The page now says PIC or XBridge, left open.
3. Not edited: `drivers/char/agp/sgi-agp.c` and its Kconfig sit outside the platform-code trees the evidence order ranks first, yet the AGP 8x-only statement is graded established. The SN2 README's recorded decision keeps the equivalent IOC4 driver rows established, so this follows precedent; the owner can relabel.
4. Not edited: the Team module count. Table 3-2 allows 1 compute plus 2 graphics (three modules) up to 5 plus 4 (nine), while the cabling text (p.65) says four to eight modules; prism-power-team.md quotes the text only.
5. Not checked: the 2005 mailing-list message ids and dates for the TIOCA patch series, the parts-index line numbers, the Prism XL page, 007-4663-002, 007-4784, 007-4796 (titles only) and the ATI external listings. Those statements stay as the author graded them (the external ones are not evidence).

Cleared scope: document identities and dates, the revision history, configuration limits, the SHub-label handling, board names, every v5.3 TIOCA statement, the firmware requirement, and the voyager carry-over after the fixes above. Not cleared: the parts-index and mailing-list citations (finding 5).
