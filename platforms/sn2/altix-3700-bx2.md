# Altix 3700 Bx2

The Bx2 replaces the C-brick with the **CR-brick**: one 4U enclosure holding up to four SHub nodes and two
router ASICs. The optional eight-port R-brick, the IX- and PX-bricks and the power bay stay. This page records what the guide prints. It holds no register
facts.

Sources: SGI, *SGI Altix 3700 Bx2 User's Guide*, `007-4377-002` (November 2004), printed pages; Linux v5.3. Grades:
see [the SN2 README](README.md). Read: contents, pp.24, 49, 50, 65, 67, 68, 71, 72, 74, 97, 101 to 103. The first revision (`007-4377-001`) was not.

## Established (007-4377-002)

- The architecture is "fourth-generation NUMAflex DSM ... NUMAlink-4"; the CR-brick holds up to four processor nodes,
  each a SHub and two processors, and "two router switches" (p.49). A single rack scales to 64 processors; the single
  system image is 256 processors at first release, and the guide gives "up to 6 TB" for a 512-processor system and
  says larger single-system-image configurations may be offered later (p.49).
- The CR-brick is 4U (6.67 in), 48 VDC and about 1300 W (p.74). It has up to eight Itanium 2 processors, 48 DIMM slots
  (12 per node), up to eight internal and up to eight external NUMAlink channels, two 1.2 GB/s (each direction) Xtown2 I/O
  channels, a USB port to the system controller, a serial console port, one L1 with an LCD display, and three
  hot-pluggable fans (pp.65, 67).
- Inside, the node electronics join two **NL4 router ASICs**; each router ASIC reaches four rear-panel connectors
  (the guide calls them "Dnet connectors"), eight in all. Two XIO ports, from node boards 1 and 3, come out at the rear (p.72). The rear-panel figure labels
  ports F, G, H and A in an upper and a lower row, and the two XIO outputs "Node 1 XIO" and "Node 3 XIO" (p.72
  Figure 5-4).
- Processors in a brick share a frequency; DIMMs go in groups of four per node board (p.74).
- The optional **R-brick** is an eight-port router (p.97) in the NUMAlink-4 fabric (p.49). The guide calls it a
  "metarouter" brick (p.55). Its ports are numbered 1 to 8 and lettered A to H (Figure 8-3, p.102). Ports 1, 6, 7 and 8
  (A, F, G, H) connect the R-brick to other R-bricks (p.101). Ports 2 to 5 (B to E) normally connect it to CR-bricks,
  and in larger systems to R-bricks (p.101). Each link runs at 3.2 GB/s each way (Table 8-2, p.103).
- The USB-to-Ethernet placement table (Table 2-2, p.24) lists R-brick slots at 128 processors (rack 001, U-23), 256
  (rack 002, U-17; rack 003, U-23) and 512 (rack 003, U-05 and U-35; rack 009, U-05 and U-35). Those rows are table
  entries. The table places adapters, so the router count is **inferred**: one R-brick at 128 processors, two at 256
  and four at 512.
- IX-brick, PX-brick, R-brick and power bay chapters follow (contents, p.viii); the L1 and L2 emulator operation is
  Chapter 2.

Brick contents are in [bricks.md](bricks.md); module ids and the hardware map in [brick-identity.md](brick-identity.md).

## Internal wiring (Figures 3-3 and 5-2)

Figure 5-2 (p.68, "CR-brick Block Diagram") is the drawing traced here. Figure 3-3 (p.50) shows the same wiring; I
compared the two by eye and did not trace 3-3 separately. Figure 5-4 (p.72) is the rear panel. No figure prints a link
speed or lane count. The layout as drawn:

- Node 0 (top left) and Node 1 (top right) sit on the top board. Node 3 (bottom left) and Node 2 (bottom right) sit on the
  bottom board.
- Router A is on the top board and router B on the bottom board, with a white midplane band between them.
- The band carries two rows of port boxes. The upper row holds Rtr A 0 to Rtr A 3, with XIO 0 at its right end. The
  lower row holds Rtr B 0 to Rtr B 3, with XIO 1 at its left end.
- Each router has ports A to H. Ports B, C, D and E carry node links. Ports A, F, G and H go to the midplane row.
- Each node has two NI pins, and each router reaches every node. Each node has one link to each router.
- No drawn line joins router A to router B, and none joins an Rtr A box to an Rtr B box.

TB1 to TB4 are labels added here for the two-cell connector boxes (TB1 and TB2 on the top board, TB3 and TB4 on the
bottom); the figure prints no names for them. Every link drawn, with its grade. "Unknown" marks the items I could not
settle from the figure.

| # | From | Port or pin | To | Figure, page | Grade |
|---|---|---|---|---|---|
| 1 | Node 0 | NI0 | Router A, port D | 5-2, p.68 | established |
| 2 | Node 0 | NI1 | Router B, port B, via top connector TB1 right cell, dashed midplane line (row 22), bottom connector TB3 right cell | 5-2, p.68 | endpoints observed; dashed segment unknown |
| 3 | Node 1 | NI0 | Router A, port C | 5-2, p.68 | established |
| 4 | Node 1 | NI1 | Router B, port E, via top connector TB2 right cell, dashed midplane line (row 24), bottom connector TB4 right cell | 5-2, p.68 | endpoints observed; dashed segment unknown |
| 5 | Node 2 | one bottom pin (side and NI label unknown) | Router A, port B, via TB2 left cell, dashed midplane line (row 23), TB4 left cell | 5-2, p.68 | endpoints observed; dashed segment unknown |
| 6 | Node 2 | one bottom pin (side and NI label unknown) | Router B, port D, direct to the bottom connector | 5-2, p.68 | endpoints observed; pin side unknown |
| 7 | Node 3 | one bottom pin (side and NI label unknown) | Router B, port C, direct to the bottom connector | 5-2, p.68 | endpoints observed; pin side unknown |
| 8 | Node 3 | one bottom pin (side and NI label unknown) | Router A, port E, via TB1 left cell, dashed midplane line (row 21), TB3 left cell | 5-2, p.68 | endpoints observed; dashed segment unknown |
| 9 | Router A | port A | Rtr A 3 | 5-2, p.68 | established |
| 10 | Router A | port F | Rtr A 0 | 5-2, p.68 | established |
| 11 | Router A | port G | Rtr A 1 | 5-2, p.68 | established |
| 12 | Router A | port H | Rtr A 2 | 5-2, p.68 | established |
| 13 | Router B | port A | Rtr B 3 | 5-2, p.68 | established |
| 14 | Router B | port F | Rtr B 0 | 5-2, p.68 | established |
| 15 | Router B | port G | Rtr B 1 | 5-2, p.68 | established |
| 16 | Router B | port H | Rtr B 2 | 5-2, p.68 | established |
| 17 | Node 1 | XIO (red) | XIO 0, right end of the upper midplane row | 5-2, p.68; rear p.72 | established; board connector path unknown |
| 18 | Node 3 | XIO (red) | XIO 1, left end of the lower midplane row, through a bottom-left board connector | 5-2, p.68; rear p.72 | established |
| 19 | Node 0 | XIO (red) | top board connector right of Node 0's pins; no further line drawn | 5-2, p.68 | unknown |
| 20 | Node 2 | XIO (red) | bottom board connector left of Node 2's pins; no further line drawn | 5-2, p.68 | unknown |
| 21 | top TB1 left cell | dashed | bottom TB3 left cell, same x | 5-2, p.68 | unknown (dashed line meaning) |
| 22 | top TB1 right cell | dashed | bottom TB3 right cell, same x | 5-2, p.68 | unknown (dashed line meaning) |
| 23 | top TB2 left cell | dashed | bottom TB4 left cell | 5-2, p.68 | unknown (dashed line meaning) |
| 24 | top TB2 right cell | dashed | bottom TB4 right cell | 5-2, p.68 | unknown (dashed line meaning) |
| 25 | Rear upper row: Port F, G, H, A upper | none drawn | no drawn element in 5-2 | 5-4, p.72 | unknown |
| 26 | Rear lower row: Port A, H, G, F lower | none drawn | no drawn element in 5-2 | 5-4, p.72 | unknown |

Notes on the table:

- Rows 21 to 24 are the four dashed verticals through the midplane. Each runs straight down at the x position of a top
  connector cell and the bottom cell beneath it. The figure has no legend for dashed lines and the text does not mention
  them. The dashed rows are read as midplane paths only because they are drawn that way. Rows 2, 4, 5 and 8 depend on this
  reading.
- The rear connectors (rows 25 and 26) are drawn but not joined to anything in 5-2. The guide does not say which router
  or which Rtr box feeds each one. The letters match the router port letters. p.72 calls the rear connectors "Dnet connectors", four per router ASIC.
  The guide does not say that the upper row is router A and the lower row is router B.
- p.67 gives up to eight external NUMAlink channels, two per node. Figure 5-2 draws no rear connector on a node. Every node pin
  goes to a router, and the rear connectors hang off router ports. How the eight rear connectors map onto "two per node"
  is unknown.
- Nodes 0 and 2 carry red XIO lines that end at board connectors (rows 19 and 20). p.71 and p.72 bring out only nodes 1
  and 3. What the two stubs connect to is unknown.
- Pin labels: the NI0 and NI1 labels on nodes 0 and 1 sit next to the pins in rows 1 to 4 and read as printed. The labels
  on nodes 2 and 3 could not be matched to pins with confidence, so which of those pins is NI0 or NI1 is unknown.
- Speeds, from the text only: the rear NUMAlink connectors run at 3.2 GB/s each direction (p.71). The two Xtown2 XIO
  channels run at 1.2 GB/s each direction (p.67, p.71). p.67 counts up to eight internal NUMAlink channels, two per node, which
  matches the eight node pins drawn.
- Not read for this section: the guide's cabling and R-brick chapters may show the rear mapping and the dashed lines.
  Check those before settling rows 21 to 26.

## Notes

- The "NL4 router ASIC" is named in the guide and is a separate part from the SHub; no document held gives its
  registers. Established that it exists in the CR-brick; unknown what its port registers look like.
- The CR-brick rear has NUMAlink connectors A, F, G and H, upper and lower, eight in all (p.71; Figure 5-4, p.72; the
  CR-brick overview on p.55 says eight NUMAlink-4 router ports). Which of them pairs with which R-brick port (B to E)
  is not stated. Unknown.
- The CR-brick is the first brick in these guides with two I/O ports (nodes 1 and 3) from four nodes; the other nodes
  have no external I/O port. Established as drawn.
- **SHub generation: SHub 1.2, established by the guide's own figure.** Figure 3-3 (printed p.50, "Functional Block Diagram of CR-brick", 007-4377-002; the same drawing is Figure 5-2 on p.68) labels all four nodes "SHUB 1.2" and "IP57 Node Card" and shows XIO and NI ports on each. The vendor's `README.snprom` (snprom 10.54) lists the Altix 3700 Bx2 for `shub1snprom.bin` and not for `shub2snprom.bin`, which agrees. Three more facts point the same way: the guide gives the CR-brick two XIO ports (nodes 1 and 3, p.72) and the SHub 2 PROM refuses XIO ("SHUB2 does not support XIO I/O."); the SHub 1 PROM image carries the NUMAlink 4 router code (`nl4r_*`), so SHub 1 plus NL4 routers is a shipped combination; and SGI's 1 December 2004 Linux patch that adds SHub 2 calls it "a future SGI chipset" (message `20041201203852.GA26131@sgi.com` on linux-ia64), while the Bx2 guide is dated November 2004. The earlier reading of the Bx2 as SHub 2 rested on dates only and is withdrawn. Not captured from a running machine; the generation flag the PROM returns to Linux would still confirm it (see [altix-3000.md](altix-3000.md#shub-generation)).

## L1 identity and PROM handling (firmware reading)

- **Type letter `@`, inferred.** The controller firmware (L1 1.34.2 to 1.62.1; sysco `software/firmware/l1/arm-brick-identity-1.62.1.md`) has one brick
  family that sets up four IP57 nodes (`SHUB N0` to `N3`) and two NL4 routers and eight processors: Vortix. Its identity routine (ARM `l1`, `brickInit` `0x31c40`
  in the 1.62.1 Linux L1) stores type `@` (0x40) when a second-pass board record names `VORTIX_PWR`; a `VORTIX_L1` record at `0xff` only sets the subtype byte and sends the routine to record `0xfe`; the ColdFire name table prints `@` as `C (Vortix)`.
  No string names a CR-brick, so the tie rests on the node and router counts matching Figure 3-3. A `c` or `5` answer is excluded for this brick (`5` is the two-node IP41 module).
- **No Bx2 image.** The L1 comes only in shared containers; the ARM packages carry Vortix, the ColdFire packages do not (the one IP57 caller there uses one node).
- **PROM.** SAL 5.04 has no IP57 or system-type branch found (the SHub-revision tests are listed in [the PROM section](../../software/firmware/snprom/boot-sequence.md#node-board-identification-ip41-ip57-others); they are not keyed on type); it folds `@` to `c` and, unlike an `o` brick, takes none of the type-keyed side paths. What differs from the
  Altix 350 is data (node count, slabs, routers present, the IX and PX bricks on the XIO ports). See [the PROM identification section](../../software/firmware/snprom/boot-sequence.md#node-board-identification-ip41-ip57-others).

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks against 007-4377-002 (printed pages): p.49 (fourth-generation NUMAflex, NUMAlink-4, two router switches per CR-brick, up to four nodes of SHub plus two processors, 64 processors per rack, 256 at first release, "up to 6 TB" for a 512-processor system), p.65 (4U), p.67 (eight processors, 48 DIMM slots, eight internal and eight external NUMAlink channels, two 1.2-GB/s Xtown2 channels, USB, console, L1 with LCD, three fans), p.72 (two NL4 router ASICs, XIO ports from nodes 1 and 3, Figure 5-4 labels), p.74 (4U 6.67 in, 48 VDC about 1300 W, groups of four DIMMs per node board, same processor frequency): all confirmed.

Findings:
1. The guide calls the eight rear connectors "Dnet connectors" (p.72); the page said "external NUMAlink connectors". Reworded to quote the guide (mechanical).
2. "6 TB described as the future limit" is a mild reading: p.49 gives 6 TB for a 512-processor system and says larger single-system-image configurations may be offered later; it does not call 512 a future limit. Not edited.

Cleared scope: the CR-brick facts and the notes. Not cleared: the wording in finding 2.

Findings addressed in 9995be1; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Checked against the printed pages in our holdings (SGI printed manuals); PDF page = printed page plus the offset noted per document. 

**Checked.** 007-4377-002 printed p.49 (PDF 73): "a maximum of 256 processors on a single-system image (SSI) at initial release. Larger SSI configurations may be offered in the future", and "up to 6 TB (terabytes) for a 512 processor system". The new wording reproduces this without calling 512 the future limit. Right.

**Findings.** None.

**Cleared:** the 6 TB wording.
