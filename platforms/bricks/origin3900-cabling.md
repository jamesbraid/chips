# Origin 3900 router cabling: what the held documents fix, and what a PROM replay accepts

Question. Which brick does each Cx-brick cable reach, and on which router port, at every size from 4 to 32 Cx-bricks?

Answer. The brick-level graph is drawn: *Partitioning for Systems that Contain Cx-bricks* (`007-4426-001`) Chapter 2
shows every cable between Cx-bricks and R-bricks at 4, 6, 8, 12, 16 and 32 Cx-bricks. With the R-brick counts of the 3900
guide's Table 2-1, the drawings and a PROM replay leave one brick-level graph at every size (sections 3 and 4). No held
document prints which R-brick port a cable uses. The PROM accepts every R-brick port assignment tried at 6 to 16
Cx-bricks; above 16 it requires the level-2 R-bricks to share one set of Cx ports, A/F partners on neighbouring ranks of
it, and (sufficient, not shown necessary) one column-to-port map per plane on the level-3 R-bricks (section 5). Within what it accepts, the port choice decides which
NASIDs each Cx-brick gets, so it is visible to the PROM and to the operating system.

Related: [size ladder](size-ladder.md), [Cx-brick](cxbrick.md), [R-brick](rbrick.md), [PROM on MetaRouter systems](../ip35/metarouter-route-and-roles.md).
Grades as in [AGENTS.md](../../AGENTS.md): **established** (a document says or draws it), **inferred** (reasoning,
arithmetic, or a PROM replay: the shipped code run over a graph built here, which says what the PROM accepts, not what
SGI shipped), **unknown**. The 16-processor "3900 hinv" in circulation is an emulator output and is not evidence.

## 1. Connector numbers are router port numbers

| Fact | Grade | Source |
| --- | --- | --- |
| The R-brick's rear connectors are labelled with numbers and letters together: 1, 6, 7, 8 are A, F, G, H, and 2, 3, 4, 5 are B, C, D, E. The drawing places `G 7`, `8 H`, `F 6`, `1 A`, `E 5`, `2 B`, `D 4`, `3 C`. So A=1, B=2, C=3, D=4, E=5, F=6, G=7, H=8. | established | `007-4579-001` Figure 8-4 (p. 141); `007-4653-001` Figure 7-4 (p. 101) |
| The Cx-brick's four external connectors are "NUMAlink 1 Port A", "8 Port H", "7 Port G", "6 Port F", and its router is "the same ASIC as used in the R-brick". By the numbering above they are router ports 1, 8, 7, 6. | established (labels, same ASIC); inferred that the Cx connector number is the router port number | `007-4572-001` pp. 4, 5, 11 and 13; `007-4653-001` p. 57 |
| The Cx router board has four internal links (one per node board) and four external. The internal ones are ports 2 to 5 (the PROM numbers the hubs of a router on ports 2 to 5). Which node board uses which of 2 to 5 is **unknown** here; the L1's port records suggest nodes 1, 2, 0, 3 on ports 2 to 5 (controller repository, `platforms/bricks/router-board-records.md`). | inferred | [PROM page](../ip35/metarouter-route-and-roles.md) |
| Every R-brick port may take a Cx-brick or an R-brick: both connector groups "connect the R-brick to other R-bricks or Cx-bricks in the network fabric". The chassis text ("R TO R", "C TO R") is the 3800 usage. A Cx-brick's L1 reaches the L2 through its own L1 port or through port F and its partner, not through an R-brick, so no management path fixes the R-brick port a Cx cable uses. | established | `007-4653-001` pp. 100 and 104 |
| Ports A and F connect to a single Cx-brick, and ports G and H each connect to a separate R-brick; with four Cx-bricks all four go to Cx-bricks. | established | `007-4572-001` pp. 13 and 14; `007-4653-001` p. 60 |

## 2. The constraints and their grades

| Constraint | Grade | Source |
| --- | --- | --- |
| R-bricks: 0 at 1 to 4 Cx-bricks, 2 at 6 and 8, 4 at 10 to 16, then 18, 18, 20, 20, 22, 22, 24, 24 at 18 to 32. Above 16 this is 8 + 2 x ceil(N / 4), the same numbers as 16 + 2 x ceil((N - 16) / 4). | established (table); inferred (the formula) | `007-4653-001` Table 2-1, p. 46 |
| R-bricks have eight link ports, one cable each, at 1.6 GB/s each direction; a NUMAlink cable carries 3.2 GB/s. | established | `007-4653-001` Table 7-2, p. 102; `007-4426-001` p. 2 |
| "The system topology supports a 200 MB/s per processor bisection bandwidth from 32 processors to 512 processors", in a fat tree with "two times the bandwidth" of the hypercube. | established | `007-4653-001` pp. 38 and 47 |
| Bisection bandwidth counts each cable crossing the cut at 3.2 GB/s (two cables between two routers give 6.4 GB/s). So 200 MB/s per processor needs at least N cables across any cut that splits N Cx-bricks into equal halves (16N processors x 0.2 GB/s / 3.2 GB/s). | established (the convention, Origin 3000 family); inferred (applying it to the 3900) | `108-0266-001` Table 4-11, p. 67 |
| The 512-processor system puts 12 R-bricks in each of racks 101 and 102, at U08, U10, U16, U18, U24, U26, U28, U30, U32, U34, U36 and U38. | established | `007-4426-001` Figure 1-2, p. 5 |
| The Chapter 2 drawings call every R-brick a metarouter: "level-2" at 6 to 16 Cx-bricks; at 32, 16 "level-2" and 8 "level-3". | established | `007-4426-001` Figures 2-11 to 2-39, pp. 28 to 56 |

## 3. The brick-level graph at each size

Cx numbers are the guide's (1 to N).

| Cx | Graph | Grade | Source |
| --- | --- | --- | --- |
| 4 | Pairs 1-2 and 3-4 on two cables each (A and F); single cables 1-3, 2-4, 1-4 and 2-3 | established | `007-4426-001` Figure 2-3, p. 20 |
| 6, 8 | Pairs (1,2), (3,4), ... on two cables; every Cx-brick has one cable to each of the two R-bricks | established | Figures 2-11 (p. 28) and 2-13 (p. 30) |
| 12, 16 | Pairs (1,2), (3,4), ...; each even-numbered Cx-brick cables to both R-bricks of one pair, each odd-numbered to both of the other pair. No R-brick to R-brick cable; at 12, two ports of each R-brick are empty | established | Figures 2-21 (12 Cx, p. 38) and 2-23 (16 Cx, p. 40) |
| 10, 14 | The same pattern with five or seven Cx-bricks per R-brick pair | inferred (no drawing; the 12 and 16 pattern, and section 4) | |
| 32 | Two planes. Cx-bricks 4j+1 to 4j+4 form column j (0 to 7). Each Cx-brick has one cable to its column's level-2 R-brick in each plane (8 level-2 per plane); each level-2 R-brick has one cable to each of its plane's four level-3 R-bricks. 16 level-2 and 8 level-3: 24 R-bricks, every port used | established | Figure 2-37 (p. 54); Figure 2-39 (p. 56) repeats it |
| 18 to 30 | The 32 graph with ceil(N / 4) columns: two level-2 R-bricks fewer per missing column, all eight level-3 R-bricks kept, the last column half full at 18, 22, 26 and 30 with its spare ports empty. This gives Table 2-1's count at every size | inferred (no drawing; arithmetic and section 4) | Table 2-1 |
| Racks at 512 processors | each plane is 8 level-2 + 4 level-3 = 12 R-bricks, one router rack each | inferred (the counts match; the figure does not label racks) | Figures 1-2 and 2-37 |

At 32 Cx-bricks A/F partners share a column, and a four-Cx partition is one column, an eight-Cx partition two, which fits
the rule that partitions of more than two Cx-bricks are "striped" across the compute racks (p. 5; inferred).

## 4. Enumeration from the text constraints alone, and the PROM's verdict

Scripts in [../ip35/replay/](../ip35/replay/): Unicorn replay of IP35 PROM 6.210 (unpacked segment
`554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`, loaded at 0x1fc00000; routines as on the
[PROM page](../ip35/metarouter-route-and-roles.md): number walk 0x1fc5d63c, route calculation 0x1fc5d450 with force-local
0x1fc23220 and the deadlock check 0x1fc22a58; the flag tests at 0x1fc21568, 0x1fc21788, 0x1fc23964, 0x1fc23a48 and
0x1fc23a98 were re-read in the image for this page). "Accepted" means the number walk numbers every hub, route calculation
and the deadlock check return 0, every hub pair forwards through the written tables, and the channel dependency graph has
no cycle. Every PROM verdict below is **inferred** (replay).

**10 to 16 Cx-bricks, four R-bricks.** A class is a graph up to relabelling R-bricks and Cx pairs and swapping within a
pair. A/F partners are fixed, each Cx-brick's G and H reach two different R-bricks, and R-brick to R-brick cables may fill
spare ports.

| Cx | Connected classes | Bisection at least N cables | of those, no R-R cable | PROM accepts: no R-R cable | with R-R cables | bisection below N |
| --- | --- | --- | --- | --- | --- | --- |
| 10 | 184,551 | 42,886 | 12 | 12 of 12 | 35 of 42,874 | 0 of 40 sampled |
| 12 | 110,773 | 1,056 | 7 | 7 of 7 | 0 of 1,049 | 0 of 40 sampled |
| 14 | 26,433 | 223 | 14 | 14 of 14 | 0 of 209 | 91 of the first 2,047 |
| 16 | 1,019 | 10 | 10 | 10 of 10 | none exist | 64 of 1,009 |

So the PROM does not enforce the bisection, and accepts every bisection-meeting class without R-brick to R-brick cables.
At 16 the ten classes are the ways of giving each pair one of the three splits of four R-bricks into two pairs (each
pair's two Cx-bricks on complementary R-brick pairs); Figure 2-23 is the class where every pair uses the same split. The
drawings, not the PROM, choose it. Refusals of R-R cables name the R-brick port ("type of N port P = 0x72, expected
ftptype: 0x42"). The R-R verdicts used one port convention per class (spare ports in order), so they bound, rather than
prove, the PROM's refusal.

**18 to 32 Cx-bricks.** With Figure 2-37's two planes and Table 2-1's count, the free choices are which column each
Cx-brick sits in (A/F partners together or split over two columns; every column holds 1 to 4), extra cables on spare
ports, and the role of the level-3 R-bricks.

| Cx | Column classes tried | PROM accepts |
| --- | --- | --- |
| 18 | 213 (all) | 1: columns of 4, 4, 4, 4, 2 Cx-bricks with partners together. A second form, 4, 4, 4, 3, 3 with one pair split between the two three-Cx columns, passes the number walk and fails route calculation ("routing cycle") |
| 20 | 56 (all) | 1: five full columns, partners together |
| 22, 26, 30 | 302 sampled at each, plus the two forms above | 1: the half-full form. The split form again passes the number walk and fails route calculation ("routing cycle") at each |
| 24, 28 | 89 and 139 sampled | the full-column form only |
| 32 | one form fills every port | the Figure 2-37 graph |

Every other column class fails the number walk ("please check NUMAlink cabling"). An extra cable from a half-full
level-2 R-brick to a level-3 one fails ("type of N port 3 = 0x62, expected ftptype: 0x42") at 18, 22, 26 and 30. The
level-3 R-bricks must carry the MetaRouter flag alone: ordinary fails ("expected ftptype: 0x72"), and MetaRouter plus
repeat fails ("type = 0x42, expected type: 0x62", or "unsupported express link" at 30 and 32). The canonical graph
(partners together, half-full column last, no extra cable, every R-brick a MetaRouter) is accepted at every size from 18
to 32, numbering the 4N hubs 0 to 4N - 1 in Cx order. At 32 the longest route is 5 routers and route calculation takes
about 20 minutes of replay.

The column tables above are number-walk verdicts; route calculation was run on the canonical graph at every size and on
the split form at 18, 22, 26 and 30. So the PROM leaves one brick-level graph at every size from 18 to 32: the 32-Cx figure cut
short, with the last column half full, which is also the one a two-Cx upgrade fills without moving a cable.

## 5. Port level: what the PROM sees

| Fact | Grade | Evidence |
| --- | --- | --- |
| A goes to A and F to F. A pair cabled A to F is refused ("express links are not supported in >128p systems", configuration error on port mask 0x1) at 16 Cx-bricks in every sample | inferred (replay) | samples with the partner cables crossed |
| 6 to 16 Cx-bricks: any R-brick port for any Cx cable, and either of G and H to either R-brick of the pair. 100 random port permutations with random G/H swaps at each of 10, 12, 14 and 16 Cx-bricks all pass the full route calculation; at 6 and 8 the earlier replays passed a shifted assignment | inferred (replay, sampled) | `ports N 100 full` |
| 18 to 32 Cx-bricks: the PROM constrains the level-2 R-brick ports. (1) Every level-2 R-brick, in both planes, takes its Cx-bricks on the same set S of four ports; one R-brick using another set fails ("type of N port P = 0x62, expected ftptype: 0x42"). S itself may be any four ports (1-4, 5-8, 2-5, {1,2,4,8}, {3,4,5,6} and others pass). (2) Number S's ports by rank 0 to 3; the two Cx-bricks of an A/F pair must sit on ranks that differ in one bit (0 and 1, 2 and 3, 0 and 2, or 1 and 3, not 0 and 3 or 1 and 2), or the walk fails ("please check NUMAlink cabling"); planes and columns choose independently. (3) The four other ports of a level-2 R-brick go to the plane's level-3 R-bricks in any order, and G or H to either plane. (4) Level-3 R-bricks: when the four of a plane take column j on the same port (any shared map) everything passes. Some unshared maps pass too; others pass the walk and route calculation but leave the tables incomplete (one level-3 R-brick with columns 0 and 1 swapped: 384 of 5,112 hub pairs at 18 Cx-bricks reach an unset turn or an unwired exit), so the PROM would misroute without reporting it. Which unshared maps work was not worked out | inferred (replay): 100 random assignments obeying (1) to (4) pass the number walk at each of 18, 24 and 32, and 12 of 12 at each of 18 and 24 pass route calculation with every hub pair forwarded; 20 random assignments ignoring (1) fail at each; all 24 orders of one column checked against (2) at 18 | `ports N 100`, `ports N 12 full`, `ports N 20 free`, 2026-11-21 |
| The port choice changes the NASIDs. At 10 to 16 the number walk numbers a Cx-brick 8 x (port - 1) from its port on one R-brick (the first the walk meets) and its partner 4 above; the other R-bricks' ports do not matter. Above 16 a Cx-brick on rank r of S gets its column's first NASID plus 4r (all 24 orders of column 0 at 18). Every one of the 100 samples per size gave a different NASID map. With the ports in Cx order (the script below) Cx-brick k holds hubs 4(k - 1) to 4k - 1 at every size | inferred (replay); which R-brick real discovery meets first is **unknown** (the replay's table order stands in for it) | same |
| At 12 and 16 Cx-bricks the PROM's routes leave half the Cx uplinks idle: the partner numbered 4 above never routes through its own G and H ("router N port 7 has no traffic", 16 cables at 16 Cx-bricks, in all ten classes); the earlier 6 and 8 Cx replays print the same notes. At 32 every cable carries traffic | inferred (replay); whether a real system routes the same way is **unknown** | same |

The isomorphism question. With the brick-level graph fixed, all accepted graphs at a size are the same graph up to R-brick
port permutation and G/H swap. At 6 to 16 the PROM accepts every permutation tried; above 16 it accepted every sampled
permutation obeying the four rules above and refused or misrouted every sampled one breaking rules (1), (2) or (4). Within those, the PROM still observes the port choice
through the NASID it gives each Cx-brick, so the choice is not unobservable. IRIX reads those NASIDs (its node tables are
indexed by NASID, [PROM page](../ip35/metarouter-route-and-roles.md#limits)), so a guest sees which Cx-brick has which
NASID (inferred); whether IRIX also reports router port numbers was not read here. The public Linux SN2 topology interface
reads each router port's far end and far port from the firmware (`arch/ia64/sn/kernel/sn2/sn_hwperf.c`,
`SN_HWPERF_ENUM_PORTS`, Linux 4.19) and builds no graph of its own (established for that interface; Altix, not the 3900).

## 6. Is the 3900 the 3800 with the rack router folded into the brick?

Test: is the 3900 graph isomorphic to the 3800 graph with the same hub count when a Cx-brick replaces a rack router and its
four C-bricks? Router for router the two match (hubs on ports 2 to 5, the partner on ports 1 and 6), so the in-rack part
carries over. The rest does not, at any size from 8 to 32 (graph comparison over the 3800 tables of the cabling draft,
inferred):

| Cx | 3900 routers / router cables | 3800 routers / router cables | Isomorphic |
| --- | --- | --- | --- |
| 8 | 10 / 24 | 8 / 16 | no |
| 10, 12, 14 | 14, 16, 18 / 30, 36, 42 | 14, 16, 18 / (tables not compared) | no (argument below) |
| 16 | 20 / 48 | 20 / 40 | no |
| 18 to 32 | 36 to 56 / 94 to 160 | 24 to 44 / 46 to 112 | no |

The difference is port 7. A 3800 rack router sends port 7 sideways to the neighbouring rack's router (a hypercube
dimension) and only port 8 up to a MetaRouter. A Cx-brick sends both G (7) and H (8) up, and no Cx-brick joins any
Cx-brick but its partner. An isomorphism that keeps hubs must map rack routers to Cx routers, and every 3800 table from 64
processors up joins hub routers to hub routers other than the partner; no 3900 graph above four Cx-bricks does. The 3900
therefore has twice the uplinks (the guide's "two times the bandwidth"), four R-bricks with 32 uplinks where the 3800 has
four MetaRouters with 16 at 256 processors, and above 16 Cx-bricks a second level (24 R-bricks at 512 processors against
12). The 3800 cable tables and their PROM verdicts do not transfer; the replays above are the 3900's own.

## 7. The cable table script

[`tools/origin3900-cabling/plan.py`](../../tools/origin3900-cabling/plan.py) writes the canonical graph for any even size
from 4 to 32, as a topology plan (`plan.py N`) or one line per cable (`plan.py N --table`). At 4, 6 and 8 it reproduces
the routers and links of the existing plans exactly. Its port choices (model choices, PROM-accepted): at 6 and 8,
Cx-brick i on port i + 1 of both R-bricks; at 10 to 16, pair k on port k + 1; above 16, Cx-bricks on level-2 ports 1 to 4
in column order, level-2 ports 5 to 8 to the plane's level-3 R-bricks 0 to 3, level-3 port j + 1 to column j, G to plane A
and H to plane B. [`cx3900_plan_check.py`](../ip35/replay/cx3900_plan_check.py) runs the PROM over exactly that output
(`--walk` stops after the number walk).

## 8. I/O and partitions

| Fact | Grade | Source |
| --- | --- | --- |
| Each partition needs one IX-brick; a server has at most eight I/O bricks; a 512-processor system divides into at most eight systems. The two eights agree: eight partitions with one IX each. | established (each statement); inferred (that the limit is the IX count) | `007-4653-001` p. 47; `007-4426-001` p. 3 |
| Partition IDs 1 to 63, whole Cx-bricks only, partitions of more than two Cx-bricks striped across the compute racks (1 to 8, 9 to 16, ... in the 4 x 128 example), the route between any two processors of a partition must stay inside it. | established | `007-4426-001` pp. 3 to 5, 9 |
| An I/O brick belongs to the partition of the Cx-brick it attaches to, and may attach to two Cx-bricks of that partition. | established | `007-4426-001` p. 3 |
| Cx XIO connector n goes to node board n; an IX-brick's XIO 10 and 11 each go to one IP53 node board. In the four-partition 512-processor figure, four "I or IX" bricks sit in the two router racks, two per rack (labels read as partitions 1 and 4 in rack 101, 2 and 3 in rack 102). | established (connectors, figure labels); inferred (label to brick order) | `007-4653-001` pp. 60, 72; `007-4426-001` Fig. 1-2 |
| Which XIO connector reaches which IX or PX-brick, and the number of PX-bricks per partition | **unknown** | no cable drawn |

## 9. What stays open

| Unknown | Why it cannot be derived | What would settle it |
| --- | --- | --- |
| The R-brick port of each cable | no held document prints one; the PROM accepts many (any at 6 to 16; the rules of section 5 above 16) | a 3900 `hinv` or `topology` listing with router ports, or an L2 `config` of a system with six or more Cx-bricks |
| Which unshared level-3 port maps the PROM routes correctly | not enumerated; a shared map per plane is enough | a reading of the next-hop routine 0x1fc22e70, or a sweep of the 120 maps of one level-3 R-brick |
| Which node board sits on which Cx router port 2 to 5 | the L1 records do not state port numbers | a Cx-brick `hinv -v`, or the router board's description |
| Which unit in racks 101 and 102 holds which level and plane | Figure 1-2 shows positions, not roles | a 512-processor `hinv` with module numbers |
| Whether real discovery hands the PROM the R-bricks in the order this replay does (and so the NASID map) | the replay builds the discovery table itself | a console capture of a 3900 boot with six or more Cx-bricks |
