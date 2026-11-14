# Altix 3700 Bx2

The Bx2 replaces the C-brick and R-brick with the **CR-brick**: one 4U enclosure holding up to four SHub nodes and two
router ASICs, and keeps the IX-, PX-brick and power bay. This page records what the guide prints. It holds no register
facts.

Sources: SGI, *SGI Altix 3700 Bx2 User's Guide*, `007-4377-002` (November 2004), printed pages; Linux v5.3. Grades:
see [the SN2 README](README.md). Read: contents, pp.49, 65, 67, 72, 74. The first revision (`007-4377-001`) was not.

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
- IX-brick, PX-brick, R-brick and power bay chapters follow (contents, p.viii); the L1 and L2 emulator operation is
  Chapter 2.

## Notes for a model

- The "NL4 router ASIC" is named in the guide and is a separate part from the SHub; no document held gives its
  registers. Established that it exists in the CR-brick; unknown what its port registers look like.
- The CR-brick is the first brick in these guides with two I/O ports (nodes 1 and 3) from four nodes; the other nodes
  have no external I/O port. Established as drawn.
- Whether the CR-brick's SHub is generation 2 is not stated (README: inferred from timing only).

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks against 007-4377-002 (printed pages): p.49 (fourth-generation NUMAflex, NUMAlink-4, two router switches per CR-brick, up to four nodes of SHub plus two processors, 64 processors per rack, 256 at first release, "up to 6 TB" for a 512-processor system), p.65 (4U), p.67 (eight processors, 48 DIMM slots, eight internal and eight external NUMAlink channels, two 1.2-GB/s Xtown2 channels, USB, console, L1 with LCD, three fans), p.72 (two NL4 router ASICs, XIO ports from nodes 1 and 3, Figure 5-4 labels), p.74 (4U 6.67 in, 48 VDC about 1300 W, groups of four DIMMs per node board, same processor frequency): all confirmed.

Findings:
1. The guide calls the eight rear connectors "Dnet connectors" (p.72); the page said "external NUMAlink connectors". Reworded to quote the guide (mechanical).
2. "6 TB described as the future limit" is a mild reading: p.49 gives 6 TB for a 512-processor system and says larger single-system-image configurations may be offered later; it does not call 512 a future limit. Not edited.

Cleared scope: the CR-brick facts and the model notes. Not cleared: the wording in finding 2.

