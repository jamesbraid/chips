# Origin 3900 router cabling: what the held documents fix, and what a PROM replay accepts

Question. Which router port does each Cx-brick cable reach, how are 6, 8 and 16 Cx-bricks cabled onto the R-bricks, and what stays unknown? No held
document prints a port-level 3900 cabling table (searched: `007-4653-001`, `007-4426-001`, `007-4572-001`, `007-4603-001`, the draft cabling guide `108-xxxx-PR2`,
`007-4311-002`, the Origin 3000 and Altix guides `007-4579-001` and `007-4377-002`, the family reference guide). `007-4311-002` and the draft guide cover the
3800 only (no "3900" or "Cx" in either text). So the answer is built from facts, arithmetic, and a PROM replay that says which candidate graphs the stock 6.210 PROM accepts.
Related: [size ladder](size-ladder.md), [Cx-brick](cxbrick.md), [R-brick](rbrick.md), [PROM on MetaRouter systems](../ip35/metarouter-route-and-roles.md).
Grades: **established** (a document says it), **software expectation** (the shipped PROM's code run over a graph the author built: it says what the PROM accepts, not what SGI shipped),
**inferred**, **unknown**. The 16-processor "3900 hinv" in circulation is an emulator output and is not evidence.

## 1. Connector numbers are router port numbers (resolves the label contradiction)

| Fact | Grade | Source |
| --- | --- | --- |
| The R-brick's rear connectors are labelled with numbers and letters together: 1, 6, 7, 8 are A, F, G, H, and 2, 3, 4, 5 are B, C, D, E. The drawing places `G 7`, `8 H`, `F 6`, `1 A`, `E 5`, `2 B`, `D 4`, `3 C`. So A=1, B=2, C=3, D=4, E=5, F=6, G=7, H=8. | established | `007-4579-001` Figure 8-4 (p. 141); `007-4653-001` p. 100 |
| The Cx-brick's four external connectors are "NUMAlink 1 Port A", "8 Port H", "7 Port G", "6 Port F", and its router is "the same ASIC as used in the R-brick". By the numbering above they are router ports 1, 8, 7, 6. | established (labels, same ASIC); inferred that the Cx connector number is the router port number | `007-4572-001` pp. 4, 5, 11; `007-4653-001` p. 57 |
| The Cx router board has four internal links (one per node board) and four external. The internal ones are ports 2 to 5: the PROM numbers the hubs of a rack router on ports 2 to 5 (replay) and the family guide says an 8-port router has four channels to compute bricks and four to other routers. Which node board uses which of 2 to 5 is **unknown** (the NASID order 1, 2, 0, 3 is a hint, not a statement). | inferred | [PROM page](../ip35/metarouter-route-and-roles.md); family reference guide |
| The chassis text on the R-brick ("LINKS R TO R" at 1, 6, 7, 8 and "R TO R, C TO R" at 2 to 5) is the Origin 3800 usage. The 3900 guide says both groups "connect the R-brick to other R-bricks or Cx-bricks". The two statements are not in conflict for the 3900: all eight R-brick ports take Cx-bricks. | established (text) | `007-4579-001` Fig. 8-4; `007-4653-001` p. 100 |
| Cx ports A and F both go to one other Cx-brick (a double link); G and H each go to a different R-brick. With four Cx-bricks all four go to Cx-bricks. | established | `007-4572-001` p. 14; `007-4653-001` p. 60 |

## 2. How 6, 8 and 16 Cx-bricks reach the R-bricks

- **6 and 8 Cx-bricks, 2 R-bricks** (`007-4653-001` Table 2-1, established). Each Cx has one cable to each R-brick, so each R-brick takes 6 or 8 Cx cables (8 uses all eight ports on both): established count, inferred wiring (arithmetic on "G and H go to different R-bricks").
- **16 Cx-bricks, 4 R-bricks.** 32 Cx cable ends fill all 32 R-brick ports: no R-brick to R-brick cable (inferred, arithmetic). 10, 12 and 14 Cx-bricks also have 4 R-bricks.
- **Above 16 Cx-bricks.** Table 2-1's R-brick count is 16 + 2 x ceil((Cx - 16) / 4): 18, 18, 20, 20, 22, 22, 24, 24 for 18 to 32 Cx-bricks (arithmetic on the printed numbers, established). The 512-processor system has 24 in two router racks, 12 per rack, all in the bays the figure names (`007-4426-001` Figure 1-2, established). Which R-bricks link to which above 16 is **unknown**.
- Fat tree: the guide calls the topology a fat tree with "two times the bandwidth" of the hypercube (`007-4653-001` p. 38, established). Whether the upper network is two planes is **unknown**: the 12 + 12 split of the 512 racks suggests it (inferred, weak).

## 3. PROM replay of candidate graphs (software expectation)

Script [cx3900_wiring.py](../ip35/replay/cx3900_wiring.py) (with `route_diagnostics.py`), PROM 6.210 unpacked segment `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`,
objdump read, Unicorn replay. Each Cx is a router with four hubs on ports 2 to 5 and its partner on ports 1 and 6.

| Candidate graph | Number walk, route calculation and deadlock check | Pair check |
| --- | --- | --- |
| 4 Cx, no R-brick, ports 7 and 8 joining the pairs (straight or crossed) | accept | closes all squares (32 and 16) |
| 6 Cx, 2 R-bricks, every Cx port 7 to R-brick 1 and port 8 to R-brick 2 | accept with the R-bricks flagged MetaRouter | skipped for MetaRouters |
| 8 Cx, same | accept with MetaRouter; **reject** as ordinary routers or as repeaters (both flags) | skipped |
| 6 or 8 Cx with the Cx-to-R port permuted (port 8 on the next R port) | accept (the PROM does not fix which R port a Cx uses; "no traffic" notes only) | skipped |
| 10, 12, 14, 16 Cx, 4 R-bricks: the 3800 256-processor graph (Table 2-23) with every Cx also cabled on port 7 to the R-brick its neighbouring rack's router uses, on a free port among 1, 2, 5, 6 | accept | skipped |
| the same with fewer than 10 Cx kept | reject (an R-brick left unlinked) | |
| two disjoint R-brick pairs for 16 Cx | reject (the halves are unreachable) | |
| the 512-processor 3800 graph with a second copy of its 12 upper routers fed from every Cx's port 7 | number walk accepts, route calculation **fails** ("bad routing table") | |

So the stock PROM accepts the all-Cx-to-both-R-bricks wiring at 4, 6 and 8 Cx-bricks (MetaRouter flag required at 6 and 8), and a doubled-uplink 3800 256-processor graph at 10 to 16. It does not choose among port assignments and does not
confirm the 512-processor plane structure. These are acceptances, not shipped cabling.

## 4. I/O and partitions

| Fact | Grade | Source |
| --- | --- | --- |
| Each partition needs one IX-brick; a server has at most eight I/O bricks; a 512-processor system divides into at most eight systems. The two eights agree: eight partitions with one IX each. | established (each statement); inferred (that the limit is the IX count) | `007-4653-001` p. 47; `007-4426-001` p. 3 |
| Partition IDs 1 to 63, whole Cx-bricks only, partitions of more than two Cx-bricks striped across the compute racks (1 to 8, 9 to 16, ... in the 4 x 128 example), the route between any two processors of a partition must stay inside it. | established | `007-4426-001` pp. 3 to 5, 9 |
| An I/O brick belongs to the partition of the Cx-brick it attaches to, and may attach to two Cx-bricks of that partition. | established | `007-4426-001` p. 3 |
| Cx XIO connector n goes to node board n; an IX-brick's XIO 10 and 11 each go to one IP53 node board. In the four-partition 512-processor figure, four "I or IX" bricks sit in the two router racks, two per rack (labels read as partitions 1 and 4 in rack 101, 2 and 3 in rack 102). | established (connectors, figure labels); inferred (label to brick order) | `007-4653-001` pp. 60, 72; `007-4426-001` Fig. 1-2 |
| Which XIO connector reaches which IX or PX-brick, and the number of PX-bricks per partition | **unknown** | no cable drawn |

## 5. Minimal fact set to build 6, 8 and 16 Cx-bricks

| Needed fact | 6 and 8 Cx | 16 Cx | Status |
| --- | --- | --- | --- |
| Router ports of A, F, G, H | 1, 6, 7, 8 | same | established |
| Hub ports on the Cx router | 2 to 5 | same | inferred (which board on which port unknown) |
| R-brick count and role | 2, MetaRouter flag | 4, MetaRouter flag | count established; flag software expectation |
| Which R-brick each Cx G and H reach | each Cx to both | each Cx to two different R-bricks of four; which two | 6, 8: inferred; 16: **unknown** (one accepted candidate) |
| R-brick port for each Cx cable | any (PROM indifferent) | free ports | **unknown**; not needed to boot |
| A/F partner | adjacent pair assumed | same | **unknown** (not tested by the PROM: skipped) |
| 18 to 32 Cx upper network, meta and repeat split of 24 | out of scope | | **unknown** |
| Cx router role | ordinary | | the Cx L1 offers the `router` command; the pins are driven only by the R-brick release (controller repository), so a Cx router is not set to MetaRouter (inferred) |

What would settle the unknowns: a 3900 `topology` or `hinv` listing with router ports, an L2 `config` of a system with six or more Cx-bricks, or a 3900 cabling guide.
