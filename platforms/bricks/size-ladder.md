# Origin 3000 and Onyx 3000 size ladder

This sheet lists, for each size of the Origin 3000 family that SGI's manuals describe (Origin and Onyx 3200, 3400,
3800 and 3900), how many bricks of each type the manuals allow, how many routers sit in each rack, where MetaRouters
come in, how racks and bays are numbered, what an I/O rack may hold and the largest processor count. It is a
product and configuration reference. It holds no register facts and clears no model.

Labels follow the repository rules. **Established** means a published manual states it; the cell names the
document, its revision and the printed page. **Inferred** means nobody states it and the reasoning follows.
**Unknown** names what would settle it. Firmware readings appear only in the
[cross-check against the L1 and L2 firmware](#cross-check-against-the-l1-and-l2-firmware). Where two sources
disagree, both are given.

## Sources

All are SGI manuals. "p." is the printed page; the offset gives the PDF page.

| Short name | Document | Offset |
| --- | --- | --- |
| Config guide | *Origin 3000 Series Technical Configuration Owner's Guide*, `007-4311-002` | PDF = printed + 12 |
| Owner's guide | *Origin 3000 Series Owner's Guide*, `007-4240-002` | PDF = printed + 32 |
| Onyx guide | *Onyx 3000 Series Graphics System Hardware Owner's Guide*, `007-4264-002` (November 2001) | PDF = printed + 18 |
| 3900 guide | *Origin 3900 Server User's Guide*, `007-4653-001` | PDF = printed + 26 |
| 3900 site guide | *Origin 3900 Server Site Planning Guide*, `007-4603-001` | PDF = printed + 14 |
| Cx partitioning | *Partitioning Guide for Systems That Contain Cx-bricks*, `007-4426-001` | PDF = printed + 16 |
| Internal config | *Origin 3000 Series Internal Technical Configuration Manual*, `108-0266-001` | PDF = printed + 14 |
| Architecture | *Origin 3000 System Architecture*, `108-0240-002` | PDF = chapter page + 14 in chapter 2 |
| L1/L2 guide | *L1 and L2 Controller Software User's Guide*, `007-3938-006` | PDF = printed + 24 |

No manual titled for the Onyx 3900 was found; see [Onyx 3900](#onyx-3900). The preliminary cabling draft
`108-xxxx-PR2` is not a source for any number below. For the R-brick itself see [the R-brick page](rbrick.md); for
the Cx-brick see [the Cx-brick page](cxbrick.md).

## One-page summary

Processor counts are for the compute bricks. "R" counts R-bricks of every role.

| Model | Processors | Compute bricks | R-bricks | Racks | I/O bricks | Power bays | Maximum |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Origin 3200 | 2 to 8 | 1 to 2 C | none | one short (17U) rack, plus D-brick racks | 1 I, plus at most 1 more I/P/X | 1 | 8 |
| Origin 3400 | 4 to 32 | 1 to 8 C | 2 six-port | one tall (39U) rack; a second for I/O and disks | 1 I, up to 8 I/O bricks | 1 to 2 | 32 |
| Origin 3800 | 16 to 512 | 4 to 128 C | 2 per full compute rack, up to 44 at 512 | 1 to 16 compute racks, 1 to 8 I/O racks | 1 I, up to 64 I/O bricks | compute rack up to 2, I/O rack 1 | 512 |
| Origin 3900 | 4 to 512 | 1 to 32 Cx | 0 up to 4 Cx-bricks; 2 to 24 above | 1 to 4 compute racks, 2 router racks at the top size | 1 IX per partition, up to 8 I/O bricks | up to 2 per rack | 512 |
| Onyx 3200 | 4 to 8 | 1 to 2 C | none | one tall rack (G-brick) or one short rack (V-brick) | 1 I | 1 | 8 |
| Onyx 3400 | 4 or 6 to 32 | 1 to 8 C | 2 six-port | at least 2 tall racks (G-brick); at least 1 (V-brick) | 1 I or more | 1 or more | 32 |
| Onyx 3800 | 16 to 128 | 4 to 32 C | 2 eight-port at minimum | at least 3 tall racks (G-brick); at least 2 (V-brick) | 1 I or more (V-brick: also 1 P) | 1 or more per rack | 128 |
| Onyx 3900 | not stated | not stated | not stated | not stated | not stated | not stated | 128 is a weak inference |

Each figure is labelled in its model's table below.

## Origin 3200

| Item | Value | Basis |
| --- | --- | --- |
| Processors | 2, 4, 6 or 8; 4 offered as one 4-processor C-brick or two 2-processor C-bricks; grows in 2- or 4-processor steps | established, Config guide p. 70; Internal config p. 109 |
| C-bricks | 1 to 2 ("minimum of one C-brick (2 processors), maximum of two C-bricks (8 processors)") | established, Config guide App. A p. 87 |
| R-bricks | none: "The R-brick is not supported in SGI Origin 3200 systems"; two C-bricks are cabled to each other directly | established, Config guide p. 87; Owner's guide p. 191 |
| Routers per rack, MetaRouters | 0, 0 | established, as above |
| I/O bricks | at most 2, one of which must be an I-brick. The bundle includes the I-brick; one more I, P or X is a customer option | established, Config guide p. 87 and pp. 74 to 76 |
| P and X bricks | 0 to 1 combined | inferred: at most two I/O bricks, one of them the I-brick |
| PCI slots at the maximum | 17 with one I-brick and one P-brick | established, Config guide Table 3-3 p. 41 |
| D-bricks | up to 2 in the base rack, plus 1 to 2 extra disk racks | established, Config guide p. 87. Internal config p. 95 allows one optional I, P, X or D brick at U10 only; see [disagreements](#where-the-sources-disagree) |
| G-bricks | none in the Origin 3200 | inferred: no manual lists one; the Onyx 3200 is the graphics model |
| Power bays | 1, with three supplies, on a single power distribution strip | established, Config guide p. 87 and p. 74; Owner's guide p. 7 |
| Rack | short rack, 17U; rack 001 | established, Owner's guide pp. 7 and 13 |
| L2 controller | optional | established, Config guide p. 42; Owner's guide p. 15 |
| Bay rules | C-bricks at U04 and U07, I-brick at U14, one optional I, P, X or D brick at U10, power bay at U01 | established, Internal config p. 95 |
| Maximum processors | 8 | established, Config guide p. 10 and p. 87 |

The Internal config manual also defines an Origin 3200C: 8-processor nodes (two C-bricks and one I-brick), one to
three nodes in a tall rack, joined by a 16-port Myrinet switch, scaling by cluster (Internal config pp. 11 and 96, 109).
It is a cluster product, not a larger single system, and is outside the ladder.

## Origin 3400

| Item | Value | Basis |
| --- | --- | --- |
| Processors | 4, 8, 16 or 32; upgrades in 4-processor steps | established, Config guide p. 70 |
| C-bricks | 1 to 8, all 4-processor | established, Config guide App. B p. 89 and p. 83 |
| R-bricks | two six-port routers in every bundle (4, 8, 16, 32 processors). The eight-port router hardware has two ports switched off in a 3400. Two six-port routers support at most 8 C-bricks | established, Config guide pp. 76 to 78; Owner's guide p. 16 and p. 191; Architecture p. 2-20 |
| R-bricks in the drawings | the generic drawings show none up to 8 processors and one at 8 to 16 processors | established, Config guide p. 55; conflicts with the bundles, see [disagreements](#where-the-sources-disagree) |
| Routers per rack | 2 | established, Owner's guide p. 16; the bundles list two R-bricks in one tall rack |
| MetaRouters | none | inferred: MetaRouters are defined only above 128 processors (Architecture p. 2-24) |
| I/O bricks | at least 1 I-brick, at most 8 I/O bricks; one I-brick and seven P-bricks give 102 PCI slots. The number of I/O bricks may not exceed the number of C-bricks | established, Config guide App. B p. 89, Table 3-3 p. 41 and p. 84 |
| X-bricks | within the eight I/O bricks | inferred: the manual counts "I, P or X" together in the same limit |
| D-bricks | optional in the base rack; extra D-brick racks as needed | established, Config guide p. 89 |
| G-bricks | none in the Origin 3400 | inferred, as for the 3200 |
| Power bays | 1 to 2 (single-phase PDU for one, three-phase PDU for two) | established, Config guide p. 89; Owner's guide p. 9 and p. 16 |
| Racks | one tall rack for the standard system; a second tall rack for I/O and D bricks; further disk racks | established, Config guide p. 10; Owner's guide p. 17 |
| L2 controller | standard, one per tall rack that holds C-bricks, with a touch display | established, Config guide p. 42; Owner's guide p. 16 |
| Bay rules, one rack | C-bricks fill U07, U10, U13, U16, U27, U30, U33, U36 in that order; first R-brick U19, second U25 (unused until more than four C-bricks); first I-brick U21, up to three more I, P or X from U36 downward; power bays U01 and U04 | established, Internal config p. 97 |
| Bay rules, two racks | compute rack: C-bricks at U10, U13, U16, U21, U24, U29, U32, U35, R-bricks at U19 and U27, power bays at U04 and U07; I-brick at U20 of rack 101 | established, Internal config p. 98 to p. 99 |
| Maximum processors | 32 | established, Config guide p. 10 and p. 89 |

A public listing of a 20-processor Origin 3400 (five C-bricks at 001c07, c10, c13, c16 and c27, two R-bricks at
001r19 and 001r25) matches the one-rack rule. It is an observation of one machine, not a manual.

## Origin 3800

| Item | Value | Basis |
| --- | --- | --- |
| Processors | 16 to 512: steps of 4 up to 128, then steps of 32 | established, Config guide p. 70 and App. C p. 93 |
| C-bricks | 4 to 128, at most 8 per compute rack | established, Config guide p. 79, p. 83 and App. C p. 93 |
| Racks | at least two tall racks (one compute, one I/O); at most 16 compute racks and at most 8 I/O racks | established, Owner's guide p. 19; Config guide p. 10, p. 79 and App. C p. 93 |
| R-bricks | at least two eight-port routers; compute racks hold at most 3 R-bricks each. Totals by size are in the [ladder](#the-3800-ladder) | established, Owner's guide p. 19; Config guide App. C p. 93 |
| Routers per rack | 2, at U19 and U27 | established, Internal config p. 100; Config guide pp. 56 to 59 (drawings label the routers 19 and 27) |
| MetaRouters | none up to 128 processors. Above that, R-bricks that join two 128-processor groups, drawn at unit 38: 4 at 256 processors and 12 at 512 processors (Config guide pp. 58 to 59 label them). Architecture figures 2-20 and 2-21 draw them. The split at 288 to 480 processors is **unknown** | established for the rule (Architecture pp. 2-18 and 2-24), the 256 and 512 counts (Config guide pp. 58 to 59) and the drawn split at 512 (Architecture figures 2-20 and 2-21) |
| Repeat routers | R-bricks that join MetaRouters to routers and to each other. Architecture p. 2-18 gives repeat-router thresholds above 256 and above 384 processors. Owner's guide p. 192 says they are used on 512 processors. At 512 processors the drawings show 8 MetaRouters and 4 repeat routers among the 12 unit-38 R-bricks. The split at 288 to 480 processors is **unknown** | established, Architecture pp. 2-18, 2-20 and 2-21; Owner's guide p. 192; see [disagreements](#where-the-sources-disagree) |
| I/O bricks | 1 I-brick, and up to 63 P-bricks (761 PCI slots); at most 8 per I/O rack, so 64 across 8 I/O racks. The base I/O rack bundle lists a P-brick and a disk, not an I-brick (Config guide p. 80), with a power bay of five supplies. I/O bricks may not outnumber C-bricks | established, Config guide Table 3-3 p. 41, pp. 80 and 84, App. C p. 93 |
| D-bricks | I/O racks may hold D-bricks; a D-brick rack holds at most 9 and no power bay | established, Config guide App. C p. 93 |
| G-bricks | a tall rack holds one or two; the Config guide counts up to eight (pipes 1 to 8) | established, Config guide p. 39; the Onyx guide's own limit is in the Onyx 3800 section |
| Power bays | compute rack up to 2; I/O rack at most 1; D-brick rack 0 | established, Config guide App. C p. 93 |
| L2 controller | mandatory in every compute rack | established, Config guide App. C p. 93 |
| Ethernet hub | one hub serves at most seven compute racks plus an L3 controller; a 512-processor system uses several hubs | established, Config guide p. 44 |
| Bay rules, compute rack | as the 3400 two-rack compute rack above; a rack is filled before the next is added | established, Internal config p. 100 |
| Maximum processors | 512 (a single system image); above 256 processors the system runs in "coarse mode" with a minimum partition of four C-bricks | established, Config guide p. 10 and p. 63 |

### The 3800 ladder

Totals printed in the drawings of the Internal config manual (pp. 69 to 84; Config guide pp. 55 to 59 print the same
totals for 2 to 64, 128, 256 and 512 processors). "Rack routers" is two per full rack; "unit-38 R-bricks" is the
total minus the rack routers. The unit-38 counts at 256 and 512 processors are printed (Config guide pp. 58 to 59);
the others are **inferred** from the totals. Every other column is **established**.

| Processors | C-bricks | Racks | R-bricks | Cables (all NUMAlink) | Rack routers | Unit-38 R-bricks |
| --- | --- | --- | --- | --- | --- | --- |
| 4 | 1 | 1 | 0 | 0 | 0 | 0 |
| 8 | 2 | 1 | 0 | 1 | 0 | 0 |
| 16 | 4 | 1 | 1 | 4 | 1 | 0 |
| 32 | 8 | 1 | 2 | 10 | 2 | 0 |
| 64 | 16 | 2 | 4 | 24 | 4 | 0 |
| 96 | 24 | 3 | 6 | 36 | 6 | 0 |
| 128 | 32 | 4 | 8 | 48 | 8 | 0 |
| 160 | 40 | 5 | 14 | 64 | 10 | 4 |
| 192 | 48 | 6 | 14 | 78 | 12 | 2 |
| 224 | 56 | 7 | 16 | 90 | 14 | 2 |
| 256 | 64 | 8 | 20 | 104 | 16 | 4 |
| 288 | 72 | 9 | 24 | 118 | 18 | 6 |
| 320 | 80 | 10 | 26 | 132 | 20 | 6 |
| 352 | 88 | 11 | 30 | 148 | 22 | 8 |
| 384 | 96 | 12 | 32 | 164 | 24 | 8 |
| 416 | 104 | 13 | 36 | 204 | 26 | 10 |
| 448 | 112 | 14 | 38 | 200 | 28 | 10 |
| 480 | 120 | 15 | 42 | 222 | 30 | 12 |
| 512 | 128 | 16 | 44 | 240 | 32 | 12 |

The rows are not smooth. 160 processors has more unit-38 R-bricks than 192 and 224, and 416 has more cables than
448. The printed totals are reproduced as printed; the 416 row is probably a misprint, and the 160 row is
unexplained. At 192 and 224 processors the printed R-brick totals (14 and 16) are 2 below the drawn counts (16 and 18).
The table keeps the printed totals. If the drawings are right, both rows have 4 unit-38 R-bricks. The 16-processor row also conflicts with the 3400 bundles (one R-brick here, two in every bundle).
The shipped 8-processor drawing is generic: it shows two C-bricks and one cable, as the Origin 3200 has.

## Origin 3900

The Origin 3900 packs four node boards and a router board into one 4U Cx-brick (3900 guide p. 42 and pp. 52 to 54).
Racks, bays and counts differ from the 3000 family, so it has its own rules.

| Item | Value | Basis |
| --- | --- | --- |
| Processors | 4 to 512 in 4-processor steps; a Cx-brick holds 4, 8, 12 or 16 processors (four node boards of 0 or 4) | established, 3900 guide pp. 38, 42 and 46. The 3900 site guide says 2 to 8 per Cx-brick and a 2-processor system; see [disagreements](#where-the-sources-disagree) |
| Cx-bricks | 1 to 32; the sizes listed are 1, 2, 4 and then every second number; memory-only Cx-bricks (four zero-processor boards) must be paired with a Cx-brick of at least four processors | established, 3900 guide p. 46 (Table 2-1) and p. 47 |
| Cx-bricks per rack | 8, at U07, U11, U15, U19, U23, U27, U31 and U35; "up to 128 processors ... in a single rack" | established, 3900 guide p. 38; Cx partitioning pp. 5 and 9 |
| Routers inside a Cx-brick | one, on the router board; four internal and four external NUMAlink ports. Ports A and F join another Cx-brick, G and H join R-bricks; at four Cx-bricks all four join Cx-bricks | established, 3900 guide pp. 54 and 60 |
| Sizes, R-bricks and racks | see the table below | established, 3900 guide p. 46 (Table 2-1) |
| Router racks | the 512-processor system has 4 compute racks and 2 router racks. Router racks are 101 and 102; each holds 12 R-bricks at U08, U10, U16, U18, U24, U26, U28, U30, U32, U34, U36 and U38 and two I or IX bricks at U13 and U21 | established, 3900 guide p. 38 and Cx partitioning p. 5 (figure). That router racks first appear above 16 Cx-bricks is **inferred** from the jump in Table 2-1 from 4 to 18 R-bricks and from 3 or 4 to 5 or 6 racks; below that the figures put R-bricks in the compute racks |
| I/O bricks | each partition needs one IX-brick; up to 8 I/O bricks per server (IX, PX, X); I/O and storage bricks go above the Cx-bricks; an extra rack for them is a compute rack, not an I/O rack | established, 3900 guide pp. 44 and 47 |
| D-bricks | D-brick2, TP900, TP9100, TP9400 and TP9500 are listed; the site guide also names a D-brick (up to 12 drives) | established, 3900 guide p. 44; 3900 site guide p. 17 |
| G-bricks | 1 to 16 InfiniteReality pipes (G-brick holds one or two pipes, 18U); 1 to 8 InfinitePerformance pipes (V-brick holds one or two V12 boards). A system has one kind of graphics, not both | established, 3900 guide pp. 173 to 176 and 184 |
| Power bays | up to 2 per rack; in the 512-processor figure each compute rack and each router rack has two, at the bottom | established, 3900 site guide p. 33 (note to the power table, maximum 2 per rack); Cx partitioning p. 5 (figure) |
| L2 controller | required, one per rack | established, 3900 site guide p. 19 |
| Maximum processors | 512 in one system image, and clusters beyond that | established, 3900 guide p. 38 |

### The 3900 ladder

Table 2-1 of the 3900 guide (p. 46), complete. The R-bricks are what the guide calls metarouters; the racks column
excludes I/O and storage racks. All **established**.

| Cx-bricks | Processors | Memory (GB) | R-bricks | Racks |
| --- | --- | --- | --- | --- |
| 1 | 16 | 32 | 0 | 1 |
| 2 | 32 | 64 | 0 | 1 |
| 4 | 64 | 128 | 0 | 1 |
| 6 | 96 | 192 | 2 | 1 or 2 |
| 8 | 128 | 256 | 2 | 2 |
| 10 | 160 | 320 | 4 | 2 or 3 |
| 12 | 192 | 384 | 4 | 2 or 3 |
| 14 | 224 | 448 | 4 | 3 or 4 |
| 16 | 256 | 512 | 4 | 3 or 4 |
| 18 | 288 | 576 | 18 | 5 or 6 |
| 20 | 320 | 640 | 18 | 5 or 6 |
| 22 | 352 | 704 | 20 | 5 or 6 |
| 24 | 384 | 768 | 20 | 5 or 6 |
| 26 | 416 | 832 | 22 | 6 |
| 28 | 448 | 896 | 22 | 6 |
| 30 | 480 | 960 | 24 | 6 |
| 32 | 512 | 1024 | 24 | 6 |

### Router cabling above four Cx-bricks

Question: which router port joins which brick, per size. **No retained manual prints it.** The 3900 guide, the Cx
partitioning guide and the Cx-brick addendum give the facts below; their figures draw bricks and not cables, and the
cabling draft `108-xxxx-PR2` has no Cx-brick table (its 1,243 compute-to-router rows and 844 router-to-router rows are
all C-bricks and 3800 racks).

| Fact | Grade | Source |
| --- | --- | --- |
| The Cx-brick has four external NUMAlink connectors, labelled NUMAlink 1 (port A), 6 (F), 7 (G) and 8 (H). A and F go to one other Cx-brick; G and H each go to a separate R-brick; with four Cx-bricks all four go to Cx-bricks | established | `007-4572-001` pp. 4, 11; `007-4653-001` p. 60 |
| With 6 or 8 Cx-bricks there are exactly 2 R-bricks, so every Cx-brick has one cable to each. With 16 Cx-bricks there are 4 R-bricks: 32 cable ends fill all 32 R-brick ports, so no R-brick has a cable to another R-brick. With 8 Cx-bricks, 16 ends fill both R-bricks | inferred (arithmetic on Table 2-1, an eight-port R-brick and "separate R-brick") | `007-4653-001` p. 46 |
| The 512-processor system has 24 R-bricks in two router racks, 101 and 102, each holding 12 named "Metarouter" (labels 1nn in rack 101 and 2nn in rack 102, nn being the bays 08, 10, 16, 18, 24, 26, 28, 30, 32, 34, 36, 38 that the 3900 guide p. 38 lists) | established (figure labels) | `007-4426-001` p. 5, Figure 1-2 |
| The two racks hold the same twelve bays each, and a Cx-brick has two R-brick ports, which suggests plane 1 (rack 101) and plane 2 (rack 102) with G to one plane and H to the other. 12 per plane equals the 3800's 12 unit-38 routers at 512 processors (8 MetaRouters and 4 repeat routers) and 32 Cx-bricks equal that system's 32 rack-router uplinks, four per MetaRouter. This is a fit, not a statement: it fails at smaller sizes (Table 2-1 has 9 per plane at 288 processors against the 3800's 6) | inferred, weak | the same figure; [3800 ladder](#the-3800-ladder) |
| Cx-brick n sits in rack 001 + m/2 at bay 7 + 8q for even m and 11 + 8q for odd m, where q = (n - 1) / 8 and m = (n - 1) mod 8 (integer division): Cx 1 to 8 are bays 7 and 11 of racks 001 to 004, Cx 9 to 16 bays 15 and 19, 17 to 24 bays 23 and 27, 25 to 32 bays 31 and 35 | established (figure, and the L2 `part` command list that names slots 7, 11, 15, 19, 23, 27, 31, 35 of racks 1 to 4) | `007-4426-001` pp. 5, 9 |
| Above 18 Cx-bricks "specific bricks must reside in each partition" and the Cx-bricks are in three or four compute racks; partitions of more than two Cx-bricks are striped across the compute racks. Partitions must be topologically contiguous | established | `007-4426-001` pp. 4 to 5 |
| Which R-brick port each G and H cable reaches, which of A and F meets which, the split of the 24 R-bricks into roles, and which Cx-brick pairs as A and F partners | **unknown** | no retained source; a 3900 `hinv` with router ports or an L2 `config` from a six-Cx-brick or larger system would settle it |

The external connector numbers 1, 6, 7 and 8 match the four non-node router ports that the cabling draft names
("C to R: Links 2, 3, 4 or 5; Router to Router: Link 1, 6, 7, 8", Table 2-1, printed p. 2-19, which the draft itself
flags as needing update) and the PROM uses for routers of the 3600 and 3800 (node ports 2 to 5; see
[the PROM page](../ip35/metarouter-route-and-roles.md#why-the-pair-check-rejects-48-processors-and-the-deadlock-check-rejects-the-3800-128-processor-draft-table),
whose second error prints the mask of ports 8, 7, 6 and 1), and the Origin 300 NUMAlink module's published USB note
puts modules on router ports 2 to 5 and servers on 1, 6, 7 and 8. So the labels are very probably the router's port
numbers (**inferred**), and A and F would then be the ports 1 and 6 that rack routers use for their paired in-rack links.
That pairing is the draft's rule for racks; it is not stated for Cx-bricks.

## Onyx 3200, 3400 and 3800

The Onyx 3000 guide (revision `-002`, November 2001) gives the graphics models. A system has G-bricks
(InfiniteReality) or V-bricks (InfinitePerformance), never both (Onyx guide p. 21).

| Item | Onyx 3200 | Onyx 3400 | Onyx 3800 |
| --- | --- | --- | --- |
| Processors | 4 to 8 with a G-brick; 4 to 8 with a V-brick (two C-bricks) | 4 to 32 with a G-brick; 6 to 32 with a V-brick | 16 to 128 |
| C-bricks | 1 to 2 (G-brick); 2 (V-brick) | 1 to 8 (G-brick); 2 to 8 (V-brick) | 4 to 32 |
| R-bricks | none | 2 six-port | 2 eight-port (minimum) |
| G-bricks and pipes | 1 G-brick, 1 to 2 pipes | 1 to 8 G-bricks, 1 to 8 pipes | 1 to 16 G-bricks, 1 to 16 pipes |
| V-bricks and pipes | 1 V-brick, 1 pipe | 1 to 4 pipes | 1 to 4 pipes; each needs its own C-brick, as does the system I-brick |
| I/O bricks | 1 I-brick; I, X or P may be added | at least 1 system I-brick; further I, X, P or N depend on C-brick count | at least 1 I-brick (V-brick system: also 1 P-brick) |
| Power bays | 1 | 1 or more; the first rack has at least one | each rack has at least one |
| Racks | G-brick: one tall rack, one PDU. V-brick: one short rack, PDS | at least 2 tall racks (G-brick: second rack holds the G-brick); at least 1 tall rack (V-brick) | at least 3 tall racks (G-brick); at least 2 (V-brick) |
| L2 controller | G-brick system: an L2 with touch display. V-brick system (short rack): L2 optional, display "not optional" | standard in each tall rack with C-bricks | standard in each tall rack with C-bricks |
| Pages (Onyx guide) | pp. 22 and 24 | pp. 26 and 28 | pp. 30 and 32 |
| Basis | established | established | established |

One point is **inferred**, one is a note:

- The Onyx 3200 with a G-brick needs a tall rack because the G-brick is 18U (Config guide p. 39) and the short rack is
  17U (Config guide p. 16). The Onyx guide states the tall rack but gives no reason.
- The Onyx maximum of 128 processors (32 C-bricks) is stated by the Onyx guide and is lower than the Origin 3800's
  512. The guide gives no reason, so none is offered here.

The Onyx guide's N-brick (2U, up to four C-bricks to up to four pipes) may stand in for an I- or X-brick in the G-brick
paths (Onyx guide pp. 26 and 30).

## Onyx 3900

No retained manual carries "Onyx 3900" in its title. The sources are thin:

- The Cx partitioning guide says "the marketing codes for systems that contain eight Cx-bricks or less are also valid
  for Onyx 3900 graphics systems" (Cx partitioning p. 6). Established; that is a statement about partition codes, not a
  size limit.
- The 3900 guide's graphics chapters describe an Origin 3900 with V-bricks (1 to 8 pipes) or G-bricks (1 to 16 pipes),
  each pipe needing two or more processors and one node board (3900 guide pp. 173 to 176 and 184). Published for the
  Origin 3900; whether SGI sold that as "Onyx 3900" is not in these pages.
- The compositor guide `007-4602-002` mentions an "Onyx 3900 system" upstream of the compositor.

Maximum processors: a **weak inference**, 128 (eight Cx-bricks). The reasoning is the partition-code sentence plus the Onyx
3800's 128-processor limit. It is weak: the 3900 guide's graphics chapters carry no processor limit, so a larger Onyx
3900 is not excluded. **Unknown**: brick counts, racks and the maximum for the Onyx 3900. A system configuration
guide for the Onyx 3900, or a price list of its bundles, settles it.

## Rack numbering and bay rules

| Rule | Basis |
| --- | --- |
| A brick's name is `rrrTuu`: three-digit rack, brick-type letter, two-digit bay. The bay is the lowest rack unit the brick occupies; in a 39U rack a C-brick in U10, U11 and U12 is `c10`; in a 17U rack an I-brick in U10 to U13 is `i10`. Rack and bay are decimal in the hardware graph | established, Owner's guide p. 13; 3900 guide p. 134 |
| Rack numbers are three digits. Compute racks run `001` to `008` in one row and `011` to `018` in a second. I/O racks begin with 1: the first digit is the type (0 compute, 1 I/O), the second the quadrant, the third the position. The figure draws I/O racks `101`, `102`, `111`, `112` on the left and `121`, `122`, `131`, `132` on the right | established, Owner's guide p. 14 (Figure 1-6) |
| In a single-rack system (all 3200s and some 3400s) the compute rack is `001` even if it holds I/O or D bricks | established, Owner's guide p. 13 |
| The Internal config manual's cabling plans put the right-hand I/O racks at `111` and `112` instead | established, Internal config pp. 104 to 105; see [disagreements](#where-the-sources-disagree) |
| In the 3900, compute racks are `001` to `004` and router racks `101` and `102` | established, Cx partitioning p. 5 (figure) |
| A 39U rack's bays are 1 to 39; the L2 controller sits above them and takes no bay. A short rack has 17 | established, Config guide pp. 14 to 16; Owner's guide p. 76 |
| Commands name a brick as `rack <n> slot <n>` (decimal, `r` and `s` as short forms); ranges and lists are allowed, and multi-rack, multi-slot targets are discouraged | established, Owner's guide p. 46; 3900 guide pp. 134 to 135 |
| Compute racks are filled in order; the first C-brick is the global master and is cabled to the I-brick | established, Internal config p. 95 and p. 100 |
| Bay positions by model | the model sections above (3200: U04 and U07; 3400 single rack: U07 upward; 3400 and 3800 compute rack: U10 upward with routers U19 and U27 and power at U04 and U07; 3900: Cx U07 upward, power U01 and U04) |

Rack digits as the manual describes them reach 24 racks for a 512-processor Origin 3800 (16 compute and 8 I/O) and 6
for a 512-processor Origin 3900. That the I/O rack numbering would also cover D-brick-only racks is **inferred**: the
Internal config manual places D-bricks in "a separate rack" and the Owner's guide lists D-bricks among the I/O rack's
contents (p. 13), but no page numbers a D-only rack.

## I/O rack rules

| Rule | Basis |
| --- | --- |
| Origin 3800: compute racks hold only C-bricks and R-bricks; I/O racks hold I, P, X and D bricks; D-bricks may go in separate D-brick racks | established, Internal config p. 100; Config guide App. C p. 93 |
| An I/O rack holds at most 8 I/O bricks and at most one power bay; the 3800 allows at most 8 I/O racks | established, Config guide App. C p. 93; p. 10 |
| The first I-brick is at U20 of the first I/O rack (`101`) | established, Internal config p. 99 and p. 101 |
| Further I, P or X bricks sit above or below the I-brick, in the same horizontal plane as the C-brick they connect to, to keep cables short | established, Internal config p. 99 |
| D-bricks start in the first slot above the power bay (U04), then above the highest I/O brick; in a disk-only rack they start at U01 and go up. The power bay is at U01 | established, Internal config p. 99 |
| A D-brick rack holds at most 9 D-bricks and no power bay | established, Config guide App. C p. 93 |
| I/O bricks may not outnumber C-bricks; one more I/O brick needs one more C-brick once they are equal | established, Config guide p. 84 |
| Cable lengths: a 1 m NUMAlink cable inside a rack; 2 m from a C-brick to an I/O brick in its own or the adjacent rack (within 24U); 3 m across one full rack (within 24U) or two racks (within 2U); 4 m across two racks (within 24U) | established, Internal config pp. 102 to 103 |
| Compute rack to I/O rack cabling plans: with two compute and two I/O racks, 001 to 101 (2 m), 002 to 101 (3 m) and 002 to 102 (4 m); with three, rack 003 adds 003 to 111 (2 m); with four, 003 goes to 111 (3 m) and 112 (4 m) and 004 to 111 (2 m) | established, Internal config pp. 104 to 105 |
| Origin 3400: one I-brick at U21 of the single rack, up to three more I/O bricks from U36 downward (no utility shelf if three are fitted); two racks: I/O in rack `101` with I-brick at U20 | established, Internal config p. 97 and p. 99 |
| Origin 3200: one I-brick at U14, one optional I, P, X or D at U10 | established, Internal config p. 95 |
| Origin 3900: the IX-brick and I/O bricks go above the Cx-bricks in the compute racks (the 512-processor figure puts two I or IX bricks in each router rack); a third rack added for I/O is a compute rack | established, 3900 guide p. 47; Cx partitioning p. 5 |
| Origin 3900: an I/O brick belongs to the partition of the Cx-brick it attaches to, and may attach to two Cx-bricks if both are in that partition; each partition needs one IX-brick; a server has at most eight I/O bricks | established, Cx partitioning p. 4; 3900 guide p. 47 |
| I/O rack cabling for the large sizes: the Internal config manual's rack-to-rack plans stop at four compute and four I/O racks (3800 only). Which C-brick XIO port reaches which I-brick bay at 128 to 512 processors, for either model, and how many I-bricks each partition has at each size, are **unknown**; the cabling draft carries no I/O rows, and the only I/O cable data in it is that the C-brick I/O interface port goes to XIO 10 or XIO 11 of an I-, P- or X-brick (2 m within 24 U) | established (the plans and the XIO ports); unknown (the rest) | Internal config pp. 102 to 105; `108-xxxx-PR2` Table 2-1 (printed p. 2-19, flagged by the draft as unreliable) |
| One L2 controller serves each rack that holds C-bricks (Cx-bricks); the L2 has four USB ports; a rack with an R-brick needs an L2 | established, Config guide p. 42; Owner's guide p. 75; 3900 site guide p. 19 |

## Cross-check against the L1 and L2 firmware

Compared with readings of the L1 and L2 firmware 1.44.0 from the IRIX 6.5.30 media: the L2 image (SHA-256
`6bcfda07a24cb4d56850922dab17a98223abcd14221d307e3a8c3778434e8761`) and the L1 image (SHA-256
`c355c542554a41b23b69dca4c201c566e8352e8f9fb870d2365c74cdd8ab0c0f`). Neither controller carries a field indexed by
processors, so the counts above have no firmware check. What the firmware does fix (each firmware reading is
established unless marked):

| Subject | Firmware | Manual | Result |
| --- | --- | --- | --- |
| Rack range | L1 stores a 10-bit rack (0 to 1023) and prints it as three decimal digits; the L2's routing and power commands keep the low byte of the rack (1 to 255) and never match a rack above 255; the partition tables use a 6-bit rack field | racks 001 to 018 and 101 to 132 (3800), 001 to 004 and 101 to 102 (3900) | agrees: every manual rack number fits under 255 and the manuals never use more than 24 racks |
| Partition numbers | 0 to 63 | "unique ID between 1 and 63", 0 meaning unpartitioned (Cx partitioning p. 4) | agrees |
| Bay range | L1 console accepts 1 to 39; the L2 selects 1 to 63 | 39U rack, bays 1 to 39 | agrees (firmware is a superset) |
| Power-up order | routers first, in two passes over fixed slot lists that reach slot 51; then I/O and graphics bricks over slots 1 to 40; then compute bricks and the rest over slots 1 to 40; a final reset broadcast reaches everything | highest bay used by any manual is U38 (R-brick) and U36 (3400 optional C/D/I/P/X) | agrees: nothing in the manuals sits above U40. Whether a brick above U40 exists is unknown in the firmware readings too |
| Router role | a stored setting, one of ordinary, meta or repeater (default ordinary); set with the `router` command; "effective on power up or reset"; one image adds three meta levels but no level reaches the router pins | role "depends on location" (Config guide p. 7; Architecture p. 2-19) and the command is listed (L1/L2 guide p. 91; Owner's guide p. 263) | agrees; the location rule says what to set, the firmware stores it. Levels are firmware-only and are not needed for the shipped sizes |
| Six-port and eight-port | the L1 1.44.0 command table has `router 6 port`, `router 6 port confirm` and `router 8 port` for brick types that include the R-brick | the L1/L2 guide says these are "only used on Altix 3000 series systems with NUMAlink 4" (p. 92); Architecture p. 2-20 says the 3400's R-bricks have two ports disabled | **firmware and L1/L2 guide disagree**: the commands exist in an image that serves Origin 3000 R-bricks. The firmware reading supports the 3400 disablement mechanism; the guide's note is narrower than the image. Which two ports are disabled is not in the firmware readings either |
| Rack digits printed by the L2 | the L2's partition library prints a six-bit rack in a packed three-digit form: values 0 to 7 as `001` to `008`, 8 to 31 as `011` to `038`, 32 to 63 as `101` to `174`. The digits are not decimal | decimal rack numbers throughout | **unknown, possible disagreement**: typing `011` into the L2's partition parser gives the packed value 8, while the L1's decimal rack for the manual's `011` is 11, and decimal 101 does not fit six bits. The firmware readings do not say how the L2 converts the L1's decimal rack for partition use. A partitioned multi-rack 3800 or 3900 console session settles it |
| One L2 per rack | an L2 learns at most 40 ports per node; an L1 module table holds 10 records | one L2 per rack; four USB ports; at most three R-bricks per 3800 compute rack | agrees; no manual size reaches the firmware limits |

## Where the sources disagree

1. **Routers in a 3400.** The generic drawings show one R-brick at 8 to 16 processors and none up to 8; every 3400
   bundle ships two six-port R-bricks (Config guide p. 55 against pp. 76 to 78; Owner's guide p. 16). Unresolved.
   The bundles name a product; the drawings do not.
2. **Where repeat routers start.** Architecture p. 2-18 gives thresholds above 256 and above 384 processors. Owner's
   guide p. 192 says they are used on 512 processors. The manuals do not say which size first uses them. Unresolved.
3. **Right-hand I/O racks.** `121`, `122`, `131`, `132` (Owner's guide p. 14) against `111` and `112` (Internal config
   pp. 104 to 105). Unresolved. The firmware accepts both forms.
4. **D-bricks in a 3200.** Up to two in the base rack (Config guide p. 87) against one optional I, P, X or D brick at
   U10 (Internal config p. 95).
5. **G-brick limits.** The Config guide counts up to eight G-bricks and eight pipes (p. 39). The Onyx guide gives eight
   G-bricks and pipes for the Onyx 3400 and sixteen G-bricks and sixteen pipes for the Onyx 3800 (pp. 26 and 30),
   which is one pipe per G-brick although a G-brick holds one or two pipes. Reproduced as printed.
6. **Processors in a Cx-brick.** 4, 8, 12 or 16, system from 4 processors (3900 guide pp. 38 and 42) against "2 to 8
   processors per Cx-brick" and a 2-processor system (3900 site guide pp. 16 and 17).
7. **L2 display on short racks.** The Owner's guide says short racks have no touch display (p. 7) and that the
   display is not optional on a 3200 (p. 15); the Onyx guide repeats "L2 optional, display not" for the short-rack
   Onyx 3200 (p. 24).
8. **Six-port commands.** L1/L2 guide p. 92 against the L1 1.44.0 command table, as above. Firmware and manual.
9. **The 3800 totals.** The 416-processor drawing prints more cables than the 448-processor one (204 against 200) and
   the 160-processor row has more unit-38 R-bricks than the 192-processor one; probably misprints (Internal config
   pp. 73, 74, 81 and 82).

## Unknown, and what settles it

| Question | What settles it |
| --- | --- |
| Brick counts, racks and maximum processors for the Onyx 3900 | an Onyx 3900 owner's or configuration guide, or a bundle price list |
| The MetaRouter and repeat-router split of the unit-38 R-bricks at 288 to 480 processors | the Architecture drawings for those sizes, or a router listing (`hinv`) or L1 `router` output from one of them |
| Which two ports of a six-port R-brick are disabled | the L1's `router` handling traced to the router's port enable, or a six-port R-brick's `router` output |
| Whether racks above 018 or the packed rack form appear in a console session | a captured multi-rack `cfg` listing from an Origin 3800 or 3900 |
| Whether SGI shipped an Origin 3800 in a layout other than the printed ones between 128 and 512 processors | a system with 160 to 480 processors in a public `hinv` |
| Origin 3900 router port per cable above four Cx-bricks, and the role split of its R-bricks | a 3900 `hinv` with router ports, an L2 `config`, or a cabling guide for it |
| I/O rack cabling (XIO port to bay) and I-bricks per partition at 128 to 512 processors | a multi-rack `hinv` or L2 `config` |

## Sources not used

No IRIX source and no vendor source. The firmware readings are of shipped images. Manuals are cited by document
number, revision and printed page.
