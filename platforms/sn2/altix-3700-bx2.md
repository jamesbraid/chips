# Altix 3700 Bx2

The Bx2 replaces the C-brick with the **CR-brick**: one 4U enclosure holding up to four SHub nodes and two
router ASICs. The optional eight-port R-brick, the IX- and PX-bricks and the power bay stay. This page records what the guide prints. It holds no register
facts.

Sources: SGI, *SGI Altix 3700 Bx2 User's Guide*, `007-4377-002` (November 2004), printed pages; Linux v5.3. Grades:
see [the SN2 README](README.md). Read: contents, pp.24, 49, 65, 67, 71, 72, 74, 97, 101 to 103. The first revision (`007-4377-001`) was not.

## Established (007-4377-002)

- The architecture is "fourth-generation NUMAflex DSM ... NUMAlink-4"; the CR-brick holds up to four processor nodes,
  each a SHub and two processors, and "two router switches" (p.49). A single rack scales to 64 processors; the single
  system image is 256 processors at first release, and the guide gives "up to 6 TB" for a 512-processor system and
  says larger single-system-image configurations may be offered later (p.49).
- The CR-brick is 4U (6.67 in), 48 VDC and about 1300 W (p.74). It has up to eight Itanium 2 processors, 48 DIMM slots
  (12 per node), eight internal and eight external NUMAlink channels, two 1.2 GB/s (each direction) Xtown2 I/O
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

## Notes

- The "NL4 router ASIC" is named in the guide and is a separate part from the SHub; no document held gives its
  registers. Established that it exists in the CR-brick; unknown what its port registers look like.
- The CR-brick rear has NUMAlink connectors A, F, G and H, upper and lower, eight in all (p.71; Figure 5-4, p.72; the
  CR-brick overview on p.55 says eight NUMAlink-4 router ports). Which of them pairs with which R-brick port (B to E)
  is not stated. Unknown.
- The CR-brick is the first brick in these guides with two I/O ports (nodes 1 and 3) from four nodes; the other nodes
  have no external I/O port. Established as drawn.
- **SHub generation: SHub 1.2, established by the guide's own figure.** Figure 3-3 (printed p.50, "Functional Block Diagram of CR-brick", 007-4377-002) labels all four nodes "SHUB 1.2" and "IP57 Node Card" and shows XIO and NI ports on each. The vendor's `README.snprom` (snprom 10.54) lists the Altix 3700 Bx2 for `shub1snprom.bin` and not for `shub2snprom.bin`, which agrees. Three more facts point the same way: the guide gives the CR-brick two XIO ports (nodes 1 and 3, p.72) and the SHub 2 PROM refuses XIO ("SHUB2 does not support XIO I/O."); the SHub 1 PROM image carries the NUMAlink 4 router code (`nl4r_*`), so SHub 1 plus NL4 routers is a shipped combination; and SGI's 1 December 2004 Linux patch that adds SHub 2 calls it "a future SGI chipset" (message `20041201203852.GA26131@sgi.com` on linux-ia64), while the Bx2 guide is dated November 2004. The earlier reading of the Bx2 as SHub 2 rested on dates only and is withdrawn. Not captured from a running machine; the generation flag the PROM returns to Linux would still confirm it (see [altix-3000.md](altix-3000.md#shub-generation)).

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
