# Altix 450 compared with the Altix 4700

The Altix 450 is a smaller relative of the [Altix 4700](altix-4700.md): the same blades, the same node chip and the
same NUMAlink 4 router ASIC, in a 5U chassis with two routers instead of a 10U chassis with four. This page answers
four questions: which node chip, what the chassis holds, how many routers a smallest system has, and how the router
wiring differs. It then records what the SHub 2 PROM does with board types and whether it can tell the two machines
apart. It holds no register facts.

Sources: SGI, *SGI Altix 450 System User's Guide*, `007-4857-001` (August 2006), `-002` and `-003` (printed pages; PDF
page is printed page plus 22; all three revisions were searched, -003 is the most complete); *SGI Altix 4700 System
User's Guide*, `007-4823-001` (PDF page is printed page plus 20); *SGI L1 and L2 Controller Software User's Guide*,
`007-3938-006` (the revision that names the 450); the SHub 2 PROM `shub2snprom.bin` from snprom 10.54 build 70399
(SAL 1.54 rel081111, sha256 `3ea833181fda8968a5297043f2260d2fc255983ecca1d418292ee008b5e2c793`, 12 MiB mapped at
`0xff400000`); sysco `software/firmware/l1/sn2-brick-packages.md`. Grades follow [AGENTS.md](../../AGENTS.md).

**Method for the PROM.** Every access, immediate, comparison and branch below was read in a flat
`ia64-linux-gnu-objdump -D -z -b binary -m ia64-elf64 --adjust-vma=0xff400000` listing of the image. Ghidra was not
needed for the claims. String addresses are global-pointer relative; the pointer for this component is `0xff7b8000`
(checked: with it the six I/O names below land on their strings). The 4700 guide revisions -002 and -003 were also searched (blade lists and the dense-router chapter).

## 1. What the 450 guide says

### Node chip: SHub 2 (established)

The guide calls the node chip the "Super-Hub (SHub) ASIC": a crossbar between one or two processors, local memory and
the network interface (the name on -001 p.64, the crossbar sentence on p.65). Its figures label it "SHUB 2": the DIMM-group diagram (-001 Figure 6-10, p.118;
the same in -002 and -003) and, in -003, the block diagram of a compute blade, titled "SHub 2.0 ASIC" with blocks PI,
XN, MD, LB and two NI ports, each "NUMAlink 4 3.2 GB/s each direction" (Figure 3-5, p.73). So the 450's generation is
stated by its own guide, which the [README](README.md) and the 4700 pages previously said it was not. The block list
is the same as the first-generation SHub's; the guide's own label is the evidence, not the block list.

### Blades and layout (established unless marked)

- The IRU is 5U with five slots, numbered 0 to 4. It "houses a maximum of four single-wide blades and one
  double-wide blade" (-001 p.62; Figure 3-3, p.64). Two routers are built in; a system "needs a minimum of one IA
  blade (base I/O)" (-001 p.62; -003 p.68 says IA/IA2).
- Blade types (-001 p.70, -003 pp.60 and 76): compute/memory (up to two Itanium 2 sockets, 4, 8 or 12 DIMMs), memory-only,
  single-wide two-slot PCI-X (a separate bus per card), double-wide three-slot PCI-X, single-wide PCIe (two cards in -001; one or two in -003, one if a 3D graphics card is fitted),
  double-wide PCIe plus PCI-X (two and two), and the double-wide IA base I/O blade (one or two disks, a DVD drive, two
  half-height PCI-X slots, two Ethernet, one SAS/SATA port, four USB). -003 adds an IA2 base I/O blade: RAID 1 and a DVD
  writer (-003 p.60, pp.76 to 77) and an optional 2D graphics card (p.58). The three-slot and the double-wide PCIe blades are "only used" in
  systems with more than one IRU (-003 p.60).
- The L1 guide's blade-type table (007-3938-006 Table 2-1, p.40: C1 and C2 "SHub 2.x based", M2, IA, I2E, I3X, I4E, RC) is headed "Altix 450
  or Altix 4700", one table for both. Its `blade` example (p.44, again as Example 3-3 on p.55) lists ten slots and two `DUAL_ROUTER` boards, which is a
  4700 IRU. The 450 guide prints no slot-by-slot listing, so which blade the guide's single-wide parts correspond to
  in that table is **inferred** (same slot counts), as on the [IRU page](altix-4700-iru.md#blade-types).
- Which slot takes the double-wide blade: **unknown**; the guide's figure shows five equal slots.

### IRU and chassis count (established)

An IRU is one 5U chassis with a system control board, an L1 controller panel on the front and two power supplies
(-001 Figure 3-4, 3-5, pp.65, 71). Racks: a 20U "short" rack holds up to four IRUs; a 42U "tall" rack holds up to eight,
with a 2U option space (-001 p.70). A single system image holds at most four IRUs, 76 cores and four base I/O blades;
two complete four-IRU systems fit in one tall rack (-003 Table A-1, p.155; footnote b). The 4700 allows four IRUs
per rack, 512 processors and eight base I/O blades (007-4823-001 Table A-1, p.113).

### Routers in the smallest printed configuration (established)

Table A-1 gives the minimum as one IRU and four cores (-001 p.149, -003 p.155); Chapter 3 says systems start at two
cores (-001 p.61). One IRU has **two** routers, one on each router board ("Slab 0" left, "Slab 1" right; -001
Figure 3-4, p.65). A one-IRU 4700, the smallest printed there (one IRU, 32 cores; 007-4823-001 p.113), has four. The 450 guide
describes no router box beyond the IRU's own (its L2 text mentions "Dense routers" only in wording shared with the 4700 guide): IRUs join through the NUMAlink connectors on the router
boards (-003 "NUMAlink Cabling the System IRUs", p.29, Figure 1-14, p.30). The 4700 guide has a chapter on an optional
"Dense Router Module" for larger systems (007-4823-001 Chapter 5); the 450 guide has no such chapter.

## 2. Topology: what differs from the 4700

Read from the two guides' IRU block diagrams (Figure 3-4 in each; -003 p.71 and 007-4823-001 p.48). Each router is
drawn as a box of eight ports A to H. Established as drawn:

| | Altix 450 | Altix 4700 |
|---|---|---|
| Blades | 5 (slots 0 to 4) | 10 (slots 1 to 10 in the figure) |
| Routers | 2: one per router board | 4: two per router board (upper and lower) |
| Blade to router links | every blade has one link to each router: ports F, E, D, C, B of the left router to slots 0 to 4, ports B, C, D, E, F of the right router to slots 0 to 4 | odd blades go to the upper router of each board, even blades to the lower router; each blade has one link to one router on each board |
| External NUMAlink ports | two per router (G and H): four per IRU | two per router: eight per IRU |
| Port A | not drawn connected | joins the two routers on the same board |
| Largest system | 4 IRUs, 76 cores | 512 processors, dense routers beyond one rack |

In effect a 4700 IRU is two 450 IRUs side by side (odd blades and even blades) whose routers are linked through port
A on each board. That sentence is **inferred**: the figures show the wiring but neither guide says it. Not shown:
whether every blade slot of the 450 is wired the same way in hardware, since the figure draws slot 0 over the top
of the routers, and which link of a blade's two network ports (NI0, NI1) goes to which router; **unknown** without a
capture or the board.

The two machines share the processor node (a blade holds the same SHub, up to two sockets) and the L1 identity form:
the 450 guide prints the IRU's L1 name as `001c01` (-003 p.86), the same rack, type letter `c` and slot layout as the
4700.

## 3. What the SHub 2 PROM does with board types

### The per-node board type (established unless marked)

The PROM asks the L1 for each node's type and keeps the answer in a 16-bit word. The routine at `0xff48ebb0` builds a
request with the constant 19 (`0xff48ec20`, `mov r43=19`) and destination word or-ed with 6 (`0xff494350`); the
second returned integer is the type. If it is at most 255 and an upper-case letter it is lower-cased (`0xff48ed10` to
`0xff48ed2c`); a value above 255 is stored as it came (`0xff48ed10` branches around the fold). A reply status of -101
takes a fallback path (`0xff48edb6`). The request is `0x0013`, the code the SHub 1 PROM sends for the same purpose:
the encoding matches, so it is **inferred** that the two are the same request, since the SHub 2 frame builder was not
read to the wire.

The type is then stored into the global-window word at `0x5003_1240` (routine `0xff4824e0`, the write helper called at
`0xff48271c`; routine `0xff4824e0` is called once, from `0xff4868dc`) and compared:

| Type | Compare site | What the PROM does |
|---|---|---|
| `0x0200` | `0xff482740` | goes on to check the DIMM records (`0xff4827a0`) |
| `0x007b` (`{`) | `0xff482766` | same: checks the DIMM records |
| `0x0a00` | `0xff4829ac` | returns to the caller without the DIMM check (`0xff482540`) |
| `0x0e00` | `0xff4829c0` | same: returns without the check |
| anything else | `0xff482770` | prints "UNABLE TO VERIFY DIMM CONFIGURATION: unknown board type" and returns |

Other routines read the stored word and branch on it (established as branches; their purpose is mostly untraced):

- `0xff481d20` computes 2 for `0x0e00` and `0x007b` and 3 for every other type (`0xff481d30` to `0xff481d50`).
- `0xff43fe30` acts only for `0x0e00`: at `0xff43fe86` the compare with 3584 falls through to `0xff43feb0`, which calls
  `0xff423920` and reads `0x8000_0002_1005_0708`; every other type returns at `0xff43feac`. It does not pair `0x0e00` with `0x7b`.
- `0xff491a70` returns 0 for `0x0200`, `0x007b`, `0x0300`, `0x0400`, `0x0a00` and `0x0d00` and 1 for any other type
  (`0xff491ab0` to `0xff491b10`; `0x0e00`, `0x0500` to `0x0800` give 1). It takes the type through the same L1 query
  routine (`0xff48f620`). Its four callers (`0xff4ade7c`, `0xff4adfbc`, `0xff4b08dc`, `0xff4b0a1c`) exclusive-or the
  result with a bit derived from the node and shift it left 33 into a value written to `0x2_1006_0700`, `SH2_GC_SRC_CTRL`,
  whose `SOURCE_SEL` field is bits 33:32 ([shub2.md](../../devices/shub/shub2.md)). So the type picks the polarity of
  one clock-source bit. That is all that was read; why `0x0a00` and `0x0d00` fall with the small boards and `0x0e00`
  with the larger ones does not identify any of them.
- `0xff4cbbc0` compares against `0x0800`, `0x0700`, `0x0300`, `0x0500`, `0x0d00`, `0x0600` and brick letters
  (`0xff4cbc70` to `0xff4cbd9c`); not traced.
- Eight more routines load `0x5003_1240` (`0xff41e396`, `0xff41e816`, `0xff476056`, `0xff476536`, `0xff477e46`,
  `0xff478036`, `0xff47e846`, `0xff480f86`); not all were read.

Two details of the first part: the type routine `0xff4824e0` returns at `0xff48250c` before any of this when `cpuid[2]` holds
the simulator marker `0xaeeeeeee8badbeef`, and in `0xff48ebb0` a reply above 255 first calls an unidentified routine
(`0xff4c9580`, from `0xff48ed9c`) before the 16-bit store.

**Which products those are.** `0x0200` is Linux's `L1_BOARDTYPE_IP63`, "CB", a 4700-generation compute board
(`v5.3:arch/ia64/include/asm/sn/l1.h`; established as the constant, the blade pairing is inferred, see the
[discovery page](altix-4700-discovery.md#board-and-brick-codes)). `{` is the controller firmware's display name "IP71"
(sysco `sn2-brick-packages.md`; established as a label in the shipped L1 firmware, not tied to a machine). `0x0a00` and
`0x0e00` have no name in the Linux v5.3 header, in this image's strings or in the sysco labels read: **unknown without a
capture or hardware**. The guide's `blade` example names a compute board `IP73_667` (007-3938-006 pp.44, 55), and sysco finds
IP73, IP75 and IP81 in the 1.62.1 controller firmware; that these three are `0x0a00`, `0x0e00` and one other is
**unknown**; nothing ties a number to a name.

### I/O blade names (established as a table; meaning inferred)

The routine at `0xff5682f0`, which feeds the "Altix IO Topology Information" print, maps a 16-bit type to a name by a
chain of compares (`0xff568300` to `0xff568630`):

| Type | Name in the image | Same code in Linux v5.3 |
|---|---|---|
| `0x0300` | `IBblade` | `L1_BOARDTYPE_BASEIO` ("IB") |
| `0x0400` | `P2Eblade` | `PCIE2SLOT` ("IC") |
| `0x0500` | `P3Xblade` | `PCIX3SLOT` ("ID") |
| `0x0600` | `P4XEblade` | `PCIXPCIE4SLOT` ("IE") |
| `0x0700` | `RAblade` | `ABACUS` ("AB", the RASC blade) |
| `0x0800` | `ADblade` | `DAYTONA` ("AD") |
| `0x0d00` | `P2Xblade` | none |
| `m`, `o`, `{` | `OPbrick` | |
| `b`, `+`, `#`, `=`, `^`, `j`, `f`, `k`, `l` | `GAbrick`, `Athena`, `PXbrick`, `IXbrick`, `SAbrick`, `PAbrick`, `OpusTiobrick`, `IAbrick`, `DORADO` | brick letters of the earlier family |

The six blade names agree with the codes the Linux header gives, which lifts the "IC to IE" pairing on the discovery
page from slot-count reasoning to a second source (the names are the PROM's own). Code `0x0d00`, "P2X", is a two-slot
PCI-X blade; the Linux header has no code for one, and of the guides read only the 450's lists a two-slot PCI-X blade
(-001 p.70, -003 p.60). The 4700 guide's blade lists in -001, -002 and -003 name only the three-slot double-wide PCI-X
blade, and the L1 guide table has I3X only. It is **inferred** that `0x0d00` is the 450's two-slot PCI-X blade and not
offered on the 4700 (absence from three 4700 guide revisions, not a statement).

### Can the PROM tell a 450 from a 4700?

No sign of it, in what was read. Routes tried:

- Strings in the whole image and in the four decompressed components: no "450", "4700", "IRU", "dense" or "Prism". The only
  "Altix" strings are the I/O topology title and the EFI driver names. The node board is named `IP65` in the KLCONFIG
  builder (`hwcfg_node_init`) and in the LBI device print: one name for both machines, a build target, not a model.
- The board-type tests found (the table and routines above) look at the node's own board, not at the chassis; no routine
  read compares a slot count, a router count or an IRU type. Not every reader of the type word was traced, so "no
  450/4700 switch" is **inferred**, not established.
- The topology is discovered: the interconnect phase prints "Found %d objects (%d chipsets, %d routers, %d
  iochipsets)" and builds fat-tree, meta-router and repeater-router objects from what answers, with no configured
  product (image offsets `0x1d47b8`, `0x1d4e10`, `0x1d3cb0`; routine bodies not traced).
- SGI's `README.snprom` lists the 4700 and, from 10.23, the 450 for this one image (see
  [holdings](../../references/sn2-holdings.md)); one image serves both, which fits the above.

So the two machines differ in what the router and blade discovery finds, not in a product switch in the PROM.
Whether the L1 passes the PROM a chassis code that changes any path (the controller firmware has chassis labels
`,` "1932", `.` "191010", `}` "1955" and "Quad Dense Router" `-`) is **unknown without a capture or hardware**; the PROM
paths that would read it were not traced to the end.

### Which L1 letters the 450's blades report

**Unknown without a capture or hardware.** What is established: the IRU's own L1 reports type `c` (the L1 name
`001c01`, -003 pp.86, 92); the guide's `config` example shows other units as `r` (`002r01`, `002r05`, -003 p.55), the
router form; the blade-type table is shared with the 4700. Tried: the three 450 guide revisions, the L1
guide revision 006, Linux v5.3 `l1.h`, the PROM's strings and name table, sysco's brick-letter pages. None assigns a
letter or board code to a 450 blade. A `blade` or `config` capture from a 450 would settle it; no hardware is assumed
online.

## Open

- Board codes `0x0a00` and `0x0e00`, and the code that `IP71` (`{`) maps to for a blade: which blades they are.
- Whether the 450's two-slot PCI-X blade is `0x0d00` and whether it is 450-only (supported, not shown, by the 4700 guides).
- Whether the L1 sends a chassis code that the PROM uses; which chassis label is the 450's.
- The 450 slot that takes the double-wide blade; the router port each slot uses.
