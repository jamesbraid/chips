# Origin 3000 Cx-brick

The Cx-brick is the combined processor and router brick of the Origin 3000 and Onyx 3000
families. This page records what the published SGI documents say about it: its board
composition, the node boards and memory, the memory-only node, the router board, the XIO
connectors, and how the brick is named. It is a product and topology reference, not a
register contract. No retained capture of a Cx-brick (an `hinv`, a boot summary or an L1
transcript) exists in the sources this repository holds, so every wiring and numbering
detail below is either printed in a manual or marked unknown.

Each fact carries one of four labels, as in the rest of this repository. **Established**
means a published document, a shipped binary or a public driver states it, with the
citation. **Inferred** means reasoned from established facts. **Unknown** means not settled,
with the route that would settle it.

## Sources

- **Cx-brick Addendum**, `007-4572-001`, 2002, printed pp. 1 to 15. Product composition,
  node boards, memory, router, XIO and cabling. Cited as `007-4572-001 p. N`.
- **Partitioning Guide for Systems That Contain Cx-bricks**, `007-4426-001`, April 2003.
  Module identity, partitions and the L1. Cited as `007-4426-001 p. N`.
- **SGI Origin 3000** datasheet, form `3399` (10.08.2003), page 2, the Cx-brick block.
  Ratings only, with no wiring. Cited as `3399 p. 2`.
- **SGI Origin 3900 Server User's Guide**, `007-4653-001`, October 2003, the Cx-brick
  chapter and the system-control chapter. Cited as `007-4653-001 p. N`. It is the only
  published manual written for a Cx-brick system as a whole.
- **IP35 PROM 6.210** (built 26 Aug 2004), SHA-256
  `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`, and the **IRIX 6.5.30**
  IP35 kernel. Read by disassembly. Cited by PROM address where a routine is named.
- **Linux 5.3** `arch/ia64/include/asm/sn/l1.h`, a public header (the `references/code/linux-5.3`
  pin; the file was moved there from `include/asm-ia64/sn/l1.h`).

## Composition

**Established** (`007-4572-001` pp. 1, 3). The Cx-brick is equivalent to four C-bricks and one
R-brick. It holds one to four IP53 node boards, one router board and one power entry module.
It needs IRIX 6.5.18 or later (p. 2).

**Established** (`007-4572-001` p. 3, Table 1). Ratings of the Cx-brick:

| Item | Cx-brick |
| --- | --- |
| Processors | 0 to 16 |
| Processor boards | up to 4 IP53 node boards |
| Memory | 1 to 32 GB |
| DIMMs | 8 per node board |
| NUMAlink 3 ports | 4 internal, 4 external |
| XIO ports | 4 internal, 4 external |

**Established** (`3399 p. 2`). Up to 16 processors and 32 GB, ECC SDRAM with memory kits of
1 GB and 2 GB, a "5-port crossbar per node board" as the memory controller, a "maximum
12.8 GB/sec aggregate memory bandwidth", an "8 port" router, and processors "R16000 or
R16000A". The datasheet does not say how the bandwidth figure is derived, or what the five
crossbar ports connect.

**Established** (`007-4653-001` p. 46, Table 2-1). The smallest Origin 3900 server is one
Cx-brick with up to 16 processors and no R-brick. Its size table needs no R-brick for up to four
Cx-bricks (pp. 46 to 47).

## IP53 node board

**Established** (`007-4572-001` pp. 3 to 4, 13). There are two kinds of node board:

- a four-processor board with 8 MB of L2 per processor and up to eight DIMMs;
- a zero-processor board with no L2 cache and up to eight DIMMs, which serves as a memory node.

A brick may mix the two kinds.

**Established** (`007-4572-001` pp. 3 to 4). Each board carries one Bedrock ASIC, zero or four
processors (labelled A to D), one L2 cache per processor, two MegArray connectors to the router
board (one XIO, one NUMAlink 3) and up to eight DIMMs. The block diagram also shows a "System
control" element beside the Bedrock. The text does not describe it.

**Established** (`007-4572-001` pp. 3 to 4). Processors come in fours. A node board has no
two-processor form.

**Established** (`007-4653-001` p. 64). The four processors on one board run at one speed, and the
guide says the boards in one brick may carry processors of different speeds. **Unknown:** whether
boards may differ. The addendum's configuration rules say the opposite, "Processor speed must be the
same for each IP53 node board" (`007-4572-001` p. 13). Both are published. Which one governs a
shipped brick is not settled. Route: a Cx-brick `hinv` from a brick with mixed boards, or a later
revision of either document.

**Established** (`3399 p. 2`). The processor family is R16000 or R16000A. The datasheet gives
no clock, and the addendum says only that the brick "supports MIPS processors" (p. 2).

**Established as printed** (`007-4576-006` p. 17). System Controller Software 1.5 lists L1 firmware
support for "R16KA 700MHz and 800MHz" parts. The release also names Origin 3900 and Origin 350
bricks but gives no brick type for that line, so it does not establish a clock for the Cx-brick.

**Unknown.** The processor clock; which of the two parts a given board carries; whether the two
parts can be mixed in one brick; the processor revision. Route: a Cx-brick `hinv` or the ordering
guide for the matching IRIX release. The C-brick clock options and their part numbers are in
[the C-brick notes](cbrick.md).

**Memory.** Established (`007-4572-001` p. 4, Table 2, and p. 13):

- Local memory is 1 to 8 GB per node board, including directory memory.
- DIMMs are DDR SDRAM in 512 MB and 1 GB sizes, added in pairs. The first pair occupies DIMM
  slots 0 and 1. The two DIMMs of a pair match; different pairs may differ.
- The memory kits are 1 GB (512 MB DIMMs) and 2 GB (1 GB DIMMs). The board uses Origin 3000
  series DIMMs.

**Unknown.** What the five crossbar ports per node board are. Also whether the DIMM positions
map to the eight software `Bank` labels that an inventory prints. The addendum's bank-pair
wording (p. 13) hints at a link, but no source establishes it. Route: a board description of
the Cx node, or an inventory of a brick with a known partial DIMM population.

## Memory-only nodes

**Established** (`007-4572-001` pp. 4, 13; `007-4653-001` pp. 47, 58, 64). A zero-processor node
is a supported product. Four zero-processor boards form a "memory-only Cx-brick". Such a brick
must connect directly, through ports A and F, to another Cx-brick that has at least four
processors, and the server rules require that pairing. Its NMI switch is not used.

**Established** (`007-4572-001` p. 4, p. 6 Figure 2). A zero-processor node still has a Bedrock, a
NUMAlink 3 connection to the router and an XIO connection.

**Inferred.** A memory-only node is a full NUMAlink node whose memory and directory are homed
locally, with no processors. The basis is the Bedrock, NUMAlink and XIO connections above.

**Unknown.** Whether the stock PROM, the kernel and the L1 treat a Bedrock with memory and no
processors as a normal node. Route: a `hinv` or console capture of a memory-only Cx-brick.

**Unknown.** Whether the external XIO port of a memory-only node is cabled in practice. The
addendum does not exclude it. The Origin 3900 guide counts XIO ports by board, not by compute
board: "the number of available XIO ports is equivalent to the number of IP53 node boards"
(`007-4653-001` p. 64). That leans towards the port being usable, but does not say so.

### What the PROM prints for a node with no processors

**Established** (IP35 PROM 6.210, unpacked `ip35prom` segment, string search). The PROM carries the
text `hubii_link_good: No I/O brick attached to module %M.` (outer offset `0x85228`, nested
offset `0x10fe38`) and `Hub chip's llp interface is down.` (nested offset `0x10de20`).

**Inferred** (not re-read in the verification pass). For a hub with no processor, the master's setup
loop reads the node's I/O link status word, at the remote form of hub offset `0x400128`, the
link control and status register in [the Bedrock I/O interface](../../devices/bedrock_ii/README.md). It
then calls the I/O link probe. When the probe returns zero or less, the PROM stores `0x9b` in
the hub's diagnostic result if bit 13 of the link word is clear, and stores 0 if bit 13 is set.
The probe prints the "No I/O brick attached" line when bit 13 is clear. The text for `0x9b` is
the "llp interface is down" line. The strings exist, but the register offset, the bit, the stored
`0x9b` and the pairing of that value with its text were not traced through the routine's code in
this pass. Route: read the master setup loop and the probe in the nested image in full.

**Established** (IP35 PROM 6.210, nested image, string search). The strings `DIAG RESULTS:`
(nested offset `0xf2591`), `ALL DIAGS PASSED.` (`0xf27c8`) and `WARNING: Could not find brd_ptr
for nasid = %d` (`0xf2428`) are present.

**Inferred** (not re-read in the verification pass). The boot summary routine prints `ALL DIAGS
PASSED.` only when nothing was reported. A hub with a nonzero diagnostic result sets a flag that
prints nothing, so the summary reads `DIAG RESULTS:` and then the end line with no body. A node with
no processors counts as a node, finds no processor component and sets no flag. A node whose board
record is missing prints the `brd_ptr` warning, so an empty body cannot mean a missing record. The
earlier citation of a routine "near `0xc0000000130d6af0`" is dropped: that address is a function
entry, but this pass could not tie it to the three strings, so it was not confirmed as the summary
routine. Route: find the code that loads the three strings and read it in full.

**Unknown.** The real value of bit 13 on a memory-only Cx node with no I/O brick cabled, and so
whether its boot summary is empty on real hardware. Also unknown: which PROM test skips the probe
for a node that has processors. Route: a real boot summary or a read of the link status word on a
memory-only Cx-brick, under a read plan that names each register's side effects.

## Router board and NUMAlink

**Established** (`007-4572-001` pp. 4 to 5, 11). The router board has one router ASIC, which the
addendum calls "same ASIC as used in the R-brick". It has four internal NUMAlink 3 links, one to
each node board through its MegArray connector, with internal link LEDs numbered 0 to 3.

**Established** (`007-4572-001` pp. 4 to 5, 11). The four external NUMAlink 3 connectors are labelled,
left to right, NUMAlink 1 Port A, NUMAlink 8 Port H, NUMAlink 7 Port G and NUMAlink 6 Port F.

**Established** (`007-4572-001` p. 11, p. 4). Ports A and F both cable to one neighbouring Cx-brick.
In a router-based configuration, ports G and H each connect to a separate R-brick.

**Established** (`007-4653-001` p. 60). In a system of four Cx-bricks, all four NUMAlink ports
connect to Cx-bricks. So G and H do not always go to R-bricks. The figures in
`007-4426-001` (Figure 2-1, p. 18, and Figure 2-3, p. 20) draw two parallel links between paired
Cx routers and four Cx-bricks joined without an R-brick. The figures do not label the ports.

**Established** (`007-4572-001` p. 12, Table 4). The NUMAlink link rate is 1.6 GB/s each direction
(3.2 GB/s full duplex). This is a product rating, not a timing contract.

**Established** (`3399 p. 2`). The Cx-brick router is an "8 port" router.

**Established** (`007-4572-001` pp. 4 to 5, 11). A 48 V to 2.5 V converter on the router board
feeds the router ASIC.

**Inferred.** The connector labels number the external links 1, 8, 7 and 6, which leaves 2 to 5
for the node-facing links. The assignment itself is a guess from the labels.

**Unknown.** Which router link each node board uses, and whether node *n* uses link *n*+2 or some
other fixed order. Route: a router register dump or routing table from a real Cx-brick. Also
unknown: which of the two parallel links is port A and which is port F; which of G and H a
Cx-to-Cx link uses when no R-brick is present; and whether the Cx router silicon revision matches
the R-brick's. "Same ASIC" is established, the revision is not. The router's register layout is
on the [router unit page](../../devices/router_origin3000/registers.md), but nothing here shows that the Cx
router is that revision.

## XIO connectors

**Established** (`007-4572-001` pp. 4 to 5, 10, 12, 14). There are four external XIO (Crosstown2)
connectors, labelled left to right XIO 2, XIO 1, XIO 3 and XIO 0. Each corresponds to one node
board: XIO 0 to node 0, XIO 1 to node 1, XIO 2 to node 2 and XIO 3 to node 3. The rear panel also
labels the node boards N0 to N3 and NODE 0 to NODE 3.

**Established** (`007-4572-001` pp. 4 to 5, 10). Each node board's XIO MegArray connector reaches
the router board. The router board has two internal XIO connectors, each to a separate XIO
jumper board with two external XIO connectors.

**Established** (`007-4572-001` p. 12). The XIO port rate is 1.2 GB/s each direction (2.4 GB/s
full duplex).

**Established** (`007-4653-001` pp. 52, 54, 64). The Origin 3900 comparison table gives "1 to 4
external (1 per IP53 node board)" XIO ports, where the addendum gives four internal and four
external. The router board "transfers I/O and system control signals between I/O devices and the
IP53 node boards via XIO ports" (p. 52).

**Established** (`007-4572-001` pp. 2, 14). A Cx-brick attaches up to four I/O bricks. The
addendum lists I-, P-, X-, N-, IX- and PX-bricks as compatible, and names G-bricks and V-bricks as
graphics attachments.

**Inferred.** The XIO path crosses the router board's connectors only as cabling. The router ASIC
is a NUMAlink device, and the block diagram draws the XIO lines apart from it (`007-4572-001`
Figure 2, p. 6).

**Inferred.** No node board has an onboard I/O ASIC. The block diagram shows none and the addendum
describes none, so this rests on silence.

**Unknown.** How two internal jumper connectors carry four node XIO links. The text says two
connectors, and Table 1 says four internal XIO ports. Route: a photograph or schematic of a real
Cx-brick.

**Unknown.** Which Bedrock XIO widget numbers appear on each node. No Cx-brick source assigns them.
Route: a console `hinv` of an I-brick behind a Cx-brick, with the widget path printed.

## Module identity and node names

**Established** (`007-4426-001` pp. 4, 12; `007-4572-001` pp. 5, 10). The Cx-brick has one L1
controller, on the router board, with one front display, one DB-9 console connector and one USB
L1 port on the power entry module. The brick is assigned a module ID at boot, unique to that
brick. Its L1 keeps the module ID and a partition ID. Every Cx-brick in one partition shares the
partition ID, which is 1 to 63; 0 means unpartitioned. The console of the lowest-numbered Cx-brick
in a partition is the partition console (`007-4426-001` p. 4).

**Inferred.** The L1 and the module ID and partition ID it stores belong to the brick: up to four
Bedrock nodes share one L1. It differs from the C-brick, whose L1 sits on its single IP35 board, and
from the Origin 350, where one IP53 board is the whole module. The module ids the IP35 PROM puts in
its node board records are a different thing: it forms one per node board, with consecutive bay
numbers, and its duplicate-position check compares them per node board (see
[the PROM module-id page](../ip35/prom-module-ids.md)).

**Established** (`007-4653-001` pp. 21, 134, 144). A Cx-brick name carries the type letter `c`, the
same letter as a C-brick. The example `001c07` is a Cx-brick in rack 001, slot 07. The slot is the
lowest rack unit the brick occupies. A brick with no rack and slot set prints `---c--`.

**Established** (`007-4653-001` p. 62, Figure 3-5). The four boards of one brick take consecutive
NASIDs in a fixed order that is not the board order. Board 1 is NASID *n*, board 2 is *n*+1, board
0 is *n*+2 and board 3 is *n*+3. The figure prints the same values against the rear XIO
connectors: XIO-2 is *n*+1, XIO-1 is *n*, XIO-3 is *n*+3 and XIO-0 is *n*+2. So board 0, the L1's
default console node, is not the lowest NASID.

**Unknown.** The NASID base *n*, and the order when fewer than four boards are fitted. Route: a
PROM trace over a multi-node brick, checked against a real capture. The PROM's NASID calculation and
what IRIX does with the numbers are in [origin3000-nasid-numbering.md](../ip35/nasid-numbering.md).

**Unknown.** How the PROM names a node inside a module, and what a real Cx-brick L1 answers for
its node and router links. The Origin 350 and Origin 300 inventories print one node per module,
such as `001c01`, and nothing retained shows how the four Cx nodes appear in `hinv`, `klconfig`
or the module-and-slot path. Route: a Cx-brick inventory with the `slab` paths.

### Brick type letter 6 in the PROM and kernel

**Established** (public header). Linux 5.3 `arch/ia64/include/asm/sn/l1.h`, line 18, defines
`L1_BRICKTYPE_TWISTER` as `0x36` (letter `6`) with the comment "IP53 & ROUTER".

**Established** (IP35 PROM 6.210 and 6.211, read in full; see
[the PROM module-id page](../ip35/prom-module-ids.md)). When the controller answers the type letter
`6`, the PROM also sends request `0x000e`, adds the answer (low two bits, sign kept) to the bay, turns
an answer of 4 into the letter `R` and folds `6` to `c`. This restores what an earlier version said
and a later pass withdrew for want of the request routine.

**Unknown.** The kernel naming claim of that earlier version, that the node vertex is
`module/<id>/node` with an alias `module/<id>/slab/<n>/node`. The strings `slab` and
`module/<id>/node` do not occur in the shipped IP35 kernel members or in the unpacked PROM segment.
Route: read the kernel's module and slab naming code in full.

**Established** (IP35 PROM 6.210, in the brick-class question page). The letter `6` is not one of
the five letters `7`, `8`, `9`, `0` and `Q`. Those set a nonzero board class in the PROM's
classifier, so IP53 boards that answer `6` take the IP35 path. The classifier table is in
[the IP35 PROM brick-class question](../../questions/ip35-prom-l1-brick-class.md).

**Established** (PROM routines above; controller side in the sysco repository, marked unverified
there). The controller answers positions 0 to 3 for the four node boards and 4 for the router. The
PROM's sum gives the nodes bays *b* to *b* + 3 and the router bay *b* with the letter `r`: for a
brick at unit 7, boards `001c07` to `001c10` and a router `001r07`. That restores the earlier
inference.

**Unknown.** What a real Cx-brick controller sends on the wire. Route: an L1 transcript from a real
Cx-brick.

## What is not settled

These are the open items the sections above name, with the capture or document that would settle
each:

- Processor clock, part and revision for each board. Route: a Cx-brick `hinv`, or the ordering
  guide for the matching IRIX release.
- The five crossbar ports per node board, and the Bank label of each DIMM. Route: a node board
  description or an inventory with a partial DIMM population.
- The router link used by each node, its port order and the router silicon revision. Route: a
  router register dump or routing table from a real Cx-brick.
- The XIO widget numbers, the two-jumper-to-four-link arrangement and whether a memory-only node's
  XIO port is cabled. Route: an I-brick `hinv` behind a Cx-brick, and a board photograph or
  schematic.
- The real link status of a memory-only node, and its boot summary. Route: a real capture.
- The NASID base, the node names and the L1 answers for the node and router links. Route: a Cx-brick
  `hinv -v` with its `slab` paths and an L1 transcript.
