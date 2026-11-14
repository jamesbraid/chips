# Silicon Graphics Prism, Power and Team

The rackmount Prism built from 2U modules on NUMAlink. "Power" is the ring topology and "Team" the routed topology
(007-4701-003 Tables 3-1 and 3-2, pp.60 and 61). The product line, documents and what every shape shares are on [the Prism
overview](prism.md); this page holds what is specific to these two.

Sources: SGI, *Silicon Graphics Prism Visualization System User's Guide*, `007-4701-003` (May 2005), printed pages, read
against -004 (Oct 2005, same chapters plus ProPack 4 Service Pack 2 text); SGI, *Obtaining Maximum Performance on Silicon
Graphics Prism Visualization Systems*, `007-4751-001`. Linux cites are `v5.3:path`. Grades: see [the SN2
README](README.md).

## Modules (established, 007-4701-003 pp.28, 30 to 38)

Every system is a combination of these, in one 17U rack, one 39U rack, or on a table top for small systems.

| Module | Contents | Boot I/O |
|---|---|---|
| Base compute module (2U, AC) | node board: 2 Itanium 2, 2 to 24 GB (4, 8 or 12 DIMMs), one SHUB; 4 PCI/PCI-X slots; 1 or 2 SATA disks; DVD-ROM; L1 | yes: IO10 card in the lowest slot, four-port USB card in the top slot |
| XG2N graphics module (2U, AC) | 0 or 2 Itanium 2, 0 to 24 GB, two graphics pipes, L1 | none; "may not be used as a standalone system" |
| CPU expansion module (2U) | 0, 1 or 2 Itanium 2, 2 to 24 GB, L1; no PCI slots, disks or media | none |
| CMPX module (2U) | like the expansion module plus four PCI/PCI-X slots; no IO10 or disks | none |
| Router module | eight-port NUMAlink router, Team only (two per system) | n/a |

Not found: any statement of the node-board number for these modules in this guide. The Altix 350 guide and the parts index
point to IP57 ([altix-350.md](altix-350.md), [overview](prism.md#hardware-that-every-shape-shares)); inferred, not stated.

"Each system or partition requires a minimum of base I/O card", which is an IO10 in the shipped build or an optional IO9;
the IO10's real-time interrupt in and out ports are "not supported under SGI Linux + ProPack" (p.31). The IO10 and IO9 detail is
on [the Altix 350 page](altix-350.md#io10-against-io9-established--002-pp72-112-to-114).

## Limits (established, Tables 3-1 and 3-2)

| | Power (ring) | Team (routed) |
|---|---|---|
| Compute and expansion modules | 1 to 3 | 1 to 5 |
| Graphics modules | 1 to 2 | 2 to 4 |
| NUMAlink routers | none | 2 |
| Processors | 4 to 8 | 8 to 16 |
| Memory | 2 GB to 96 GB | 8 GB to 192 GB |
| Internal SATA disks | 1 to 6 | 1 to 10 |
| PCI/PCI-X slots | 4 to 16 | 4 to 28 |
| Racks | one 17U or one 39U | one 17U and up to two 39U |
| L2 controller | optional, none to 1 | optional, none to 1 |

The two-module minimum quoted in the text is "two graphics pipes, up to 48 GB of memory, 4 PCI/PCI-X slots"; the maximum is
"16 processors, 192 GB local DIMM memory and 28 slots" (p.28). Table 3-1's note: each base compute module has four slots, but
one holds the base I/O card, one the ImageSync card and one USB, so fewer are free. The -003 revision removed references to
the optional L2 controller from the text, but the table rows still list it.

A base compute module plus one XG2N only: at most 4 processors and 48 GB (p.32).

## Topology (established)

- **Ring (Power).** Each module has two NUMAlink ports and connects to two neighbours; a message passes round the ring, in
  either direction, with an alternative path if a link fails (p.62). Bisection bandwidth per node: 3.2 GB/s for two
  modules, 2.13 GB/s for three (two pipes) or four (two pipes), 1.83 GB/s for three with four pipes, 1.6 GB/s for four with
  four pipes (Table 3-3). Figures 3-1 to 3-3 (pp.63, 64) show two-, three- and four-module rings; the base compute module is
  at the bottom, XG2N modules above it, and the ring runs `NUMALINK 0` to `NUMALINK 1` through each. NUMAlink channel:
  6.4 GB/s full duplex, 3.2 GB/s each direction (Table A-2, p.157).
- **Routed (Team).** Four to eight modules plus two routers; cabling for the smallest (four modules) and largest (eight
  modules) systems is on pp.65 to 70. The smaller figures were not read.
- The Altix 350 guide calls its ring and router NUMAlink-4 ([altix-350.md](altix-350.md#topology)); the Prism guide says only
  "NUMAlink" here and "fourth-generation NUMAflex ... NUMAlink-4" in the Extreme guide. Same-link inference for the Power
  and Team modules: **inferred**.

## Graphics (established unless marked)

- An XG2N carries two pipes; each pipe has two DVI-I outputs, a "left" and a "right channel" (Figures 1-1 to 1-4, pp.3 and 4).
  The first module's pipes are "Bus 1 slot 1 (Pipe 0)" and "Bus 2 slot 1 (Pipe 1)". Later modules number pipes upward,
  `pipe n` below `pipe n+1` (Figures 1-2, 1-4).
- Board generations: the early build (FireGL X2PRO-256) and, from May 2005, the FireGL X3-256 (p.iii). The rear panel differs
  (Figures 1-1 and 1-3). Both have a StereoSync connector and IS1, IS2 and Repeat DB9 ImageSync ports on the module.
- Card service: the board is held by two back-panel screws and a lower PCI/PCI-X support bracket, plugged into "the main connector
  on the riser board", and has a 7-pin keyed synchronization cable on its underside (pp.91 to 95).
- `gfxtopology -v` for a four-pipe system (two XG2N modules and a base module) prints, in 007-4751-001 p.18:

  ```
  pipe 0 g @ 001c02/1/agp/0a -> c @ 001c02/0 (cpu 2,3)   (PCI:23:0:0)  SG2
  pipe 1 g @ 001c02/2/agp/0a -> c @ 001c03/0 (cpu 4,5)   (PCI:27:0:0)  SG2
  pipe 2 g @ 001c03/1/agp/0a -> c @ 001c03/0 (cpu 4,5)   (PCI:39:0:0)  SG2
  pipe 3 g @ 001c03/2/agp/0a -> c @ 001c01/0 (cpu 0,1)   (PCI:43:0:0)  SG2
  ```

  Reading (the guide's field table, 007-4751-001 p.19): `001c02` is rack 1, slot 2, brick type `c`; `/1/agp/0a` is the port,
  bus type and device; after the arrow comes the brick and port holding the "logically closest CPUs". Bricks 001c02 and
  001c03 are the two XG2N modules (CPUs 2,3 and 4,5) and 001c01 is the base compute module (CPUs 0,1): inferred from the CPU
  numbers and the pipe order, since the guide does not label them. The printed line is established. One oddity is **unknown**: the pipes on port 2 of each XG2N (pipe 1,
  pipe 3) list a different brick's CPUs as closest, not their own host brick's. Either the script does not use the port, or
  that port's TIOCA is homed to another node (`ca_closest_nasid` is set by the PROM, see
  `v5.3:arch/ia64/sn/pci/tioca_provider.c`). The PCI bus numbers 23, 27, 39 and 43 are the system-wide bus numbers the X
  server uses (BusId `PCI:23:0:0` etc.).
- Linux and the AGP bridge: [the overview](prism.md#graphics-attachment). The pipe-to-XIO-port reading (port 1 and 2 of one
  XG2N) is inferred there.
- Pipe 0 carries the Linux console monitor (p.18). With an ImageSync card, the monitor must be on the left channel of the
  first pipe the card is cabled to (p.16). ImageSync cabling: base module IS card DB9 to the XG2N `IS1`, then the `Repeat`
  port to the next XG2N's `IS1` (p.16, Figure 1-11 on p.17); do not plug serial devices in, the DB9 ports are not serial.
- Compositor, genlock, framelock and stereo options: [the overview](prism.md#graphics-boards-and-outputs).

## Console and controllers (established)

- Each module has a front-panel L1 display, power button, reset, NMI and failure and service LEDs (p.5). The L1 console and
  L1 USB-B ports are on the rear of every module (Figure 1-1). The rear of the base module shows `CONSOLE`, `L1 PORT` and the
  two `NUMALINK` ports plus `CPU`.
- The optional L2 controller is "removed" from the text in -003 (revision note, p.iii) but Tables 3-1 and 3-2 still list it.
  L2 for Prism is described in the L1 and L2 guide (007-3938-004, not read for this page).

## Not covered

The chassis cabling chapters (pp.65 to 70) beyond the headline, the CR-brick-class I/O bricks (Extreme only), the L1 error
message list (pp.124 to 129) and the technical specification tables other than A-2 and A-3. Open questions:
[prism-open.md](../../questions/prism-open.md).

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from ee45651 and a399d6d). Sources: the `techpubs` Library root, printed pages; Linux v5.3 single files from raw.githubusercontent.com, `arch/ia64/include/asm/sn/{tioca.h,pcibus_provider_defs.h}`, `arch/ia64/sn/pci/tioca_provider.c`, `arch/ia64/sn/kernel/setup.c`, `drivers/char/agp/{sgi-agp.c,Kconfig}`; public github.com/jamesbraid/voyager `README.md`, `devices/README.md`, `questions/open-questions.md`.

Checks: Tables 3-1 and 3-2 (007-4701-003 pp.60 and 61: every limit in the page's table matches, including 17U and 39U rack counts and the optional L2 row), p.28 (two-module minimum, 16 processors, 192 GB, 28 slots), p.65 (routed systems have four to eight modules plus two routers), the record of revision (X3-256 added in -003, L2 references removed), the `gfxtopology -v` listing (007-4751-001 PDF 18, printed p.18: four lines, buses 23, 27, 39 and 43, `SG2`), and the page's reading of it (port 1 and 2 of 001c02 and 001c03; the second pipe of each XG2N lists a different brick's CPUs, correctly marked unknown). The IP57 and ring-is-NUMAlink-4 statements are inferred, not established, as graded. The TIOCA reference is to the overview, whose v5.3 facts were checked there.

Findings: the Team module count is stated only from the cabling text; the table limits give three to nine modules (see the overview's review, finding 4). No mechanical errors.

Cleared scope: modules, limits, topology, graphics-pipe numbering, the gfxtopology reading and its marked inferences. Not cleared: the cabling figures on pp.62 to 70 (the page says they were not read).
