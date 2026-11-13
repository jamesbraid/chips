# P-brick: Origin 3000 and Onyx 3000 PCI enclosure

The P-brick is an Origin 3000 and Onyx 3000 PCI enclosure with twelve PCI slots on six buses,
three XBridge chips and two Crosstown2 host ports. This page covers what the enclosure carries:
bus and slot layout, chip wiring as drawn, the guest's widget and bus numbering, host routing,
power, the L1 identity and what is unknown. It holds no register facts, so there is no generated
contract for it. The XBridge registers are in [bridge-family.md](../../devices/bridge/family.md) and
`devices/bridge/registers.xbridge.toml`. The Crosstown2 port and its speeds are in
[crosstown-ktown.md](../../devices/crosstown-ktown/README.md), and the host interface card's presence is recorded there
too.

The P-brick is not the Origin 300 PCI expansion module. The module has a Bedrock interface card and a
NUMAlink connector. The two share a PCI motherboard layout and a six-widget guest view, and nothing
here carries over to the module without saying so. See
[origin300-pci-expansion-module.md](origin300-pci-expansion-module.md). The IX-brick enclosure
([ixbrick.md](ixbrick.md)) is a different PIC-based brick with a similar slot count.

Grades: **established** (stated in a cited published source, or drawn in one), **inferred**
(reasoned from established facts, or from a driver or a sibling platform), **unknown** (not settled,
with the evidence that would settle it).

## Sources

- SGI, *Origin 3000 System Architecture*, `108-0240-002`, printed pp. 2-30 and 2-31, section 2.3.1.2
  and Figure 2-24. Cited as `108-0240-002 p. N`.
- SGI, *Origin 3000 Series Technical Configuration Owner's Guide*, `007-4311-002`, printed pp. 31 to 33,
  41, 42, 49 and 62. Cited as `007-4311-002 p. N`.
- SGI, *Origin 3000 Series Owner's Guide*, `007-4240-002`, printed pp. 121, 123, 125, 137, 140 to 142
  and 216. Cited as `007-4240-002 p. N`.
- SGI, *Onyx 3000 Series Owner's Guide*, `007-4264-002`, printed p. 145. Cited as `007-4264-002 p. N`.
- SGI, *L1 and L2 Controller Software User's Guide*, `007-3938-001`, printed pp. 42 and 67 to 69, and
  `007-3938-006`, printed pp. 60 and 82 to 84.
- Product literature: *Origin 3000 Series Family Reference Guide*, printed p. 9; the Origin 3000
  datasheet `2000-2774`, p. 4; and the product guide `2775`, p. 8.
- Linux, `arch/ia64/sn/io/sn1/pcibr.c` at tag `v2.5.40` (commit `7570df54ef8c`), lines 262 to 272, the
  widget-to-bus table. Checked against that commit for this page.
- OpenBSD, `sys/arch/sgi/xbow/xbow.c` (probe orders, lines 251 to 253), `sys/arch/sgi/xbow/xbridge.c`
  (lines 51 to 58 and 146 for the translation-entry comment, and the interrupt mapping block near
  lines 1242 to 1290), and `sys/arch/sgi/include/mnode.h` (lines 220 and 223). Line numbers checked
  against revision `7011342f6a72`, the revision in this checkout. The source record names
  `2df91d80c104`, and the lines match at this revision.
- SGI, *Online Diagnostics*, `108-0286-007` printed pp. 2-20, and `108-0286-005`, the same sample
  on printed p. 2-20. One `bridgeloc` listing.
- Usenet posts, cited by message id. Message `alg531$9tb$1@knossos.btinternet.com` (2002-09-08,
  "Re: P-brick slot #s to /hw addresses?") answers a question quoting device paths from a loaded
  P-brick, message `LgMe9.3719$HO4.336343@newsfeed.slurp.net`. A 2002 reply
  (`mjevg5fu06s.fsf@toby.pdc.kth.se`) and a 2003 SGI engineer's posts
  (`3E3875FB.6000800@brussels.sgi.com`, `3E390BBB.4010606@brussels.sgi.com`,
  `3E392983.7060905@brussels.sgi.com`) are one person's remarks. They support but do not establish.

The manuals and the Usenet posts are not held in this repository. A verification pass re-read these against the published manuals: the P-brick slot, bus and chip assignment (`108-0240-002` pp. 2-30 and 2-31), the PCI bandwidth table (`007-4311-002` p. 49), the 3.3-volt or universal wording (`007-4240-002` p. 137) and the L1 brick-type letter (`007-3938-001`). They matched. The Usenet posts, the datasheet and product-guide lines, the remaining page numbers and the figure-drawn wiring were not re-checked. The Linux and
OpenBSD line numbers above were checked against the public trees.

## Physical layout

Established (`108-0240-002 p. 2-30` to `p. 2-31`; `007-4311-002 p. 31` to `p. 33`;
`007-4240-002 p. 140` to `p. 142`):

- Twelve hot-pluggable PCI slots on six buses, two slots per bus. The slots are labelled bus 1 to 6
  and slot 1 and 2.
- Each slot takes a 33 or 66 MHz card with 32-bit or 64-bit addressing. If one card on a bus runs at
  33 MHz, both slots of that bus run at 33 MHz.
- A serial ID EEPROM on the PCI board holds component information. Power and the L1 controller are on
  a separate power board.

Established (`007-4311-002 p. 49`): peak PCI bandwidth per bus at 66 MHz is 256 MB/s in 32-bit mode
and 512 MB/s in 64-bit mode.

Slot signalling voltage. The sources do not say the same thing:

- `108-0240-002` says 3.3 V slot power and does not use the word "universal".
- `007-4240-002 p. 137` says "3.3-volt or universal" hot-pluggable cards. The Family Reference Guide
  (p. 9) says "3.3V or Universal PCI cards". The datasheet `2000-2774` says "3.3 V, and Universal".

Inferred: the slots signal at 3.3 V and accept 3.3 V and universal cards, not 5 V-only cards. No
source says how a universal card signals in these slots. The Origin 300 expansion module's later
guide adds 5.0 V support. That is the module, and nothing here says the P-brick gained it.

Unknown: whether the slots wire 64-bit data to every position. The guides speak of addressing. The
product text says "64-bit/66 MHz PCI" for the brick, which is a hint and not a pin map. The route to
an answer is a board wiring document or a transaction capture from a 64-bit card on each bus.

## Chips and wiring as drawn

Three XBridge chips, U0, U1 and U2. Established:

- U0 serves buses 3 and 4 and is also the Crosstown2 interface for U1 and U2.
- U1 serves buses 1 and 2.
- U2 serves buses 5 and 6.
- The two Crosstown2 ports are A (labelled 10) and B (labelled 11), at 1.2 GB/s each way
  (`007-4311-002 p. 31`; the bandwidth table on p. 49 says each port is software selectable at 800 or 1200 MB/s, as [crosstown-ktown.md](../../devices/crosstown-ktown/README.md) records). Each ends
  at a host interface card between the chip and the cable. The rear connectors are labelled XIO 10
  and XIO 11. Either can go to a C-brick, and the second can optionally go to another C-brick.

The figure draws these links. Lettered ports are hexadecimal. Established as drawn (`108-0240-002`
Figure 2-24):

| Endpoint | Connects to |
|---|---|
| Host interface card 1 | U0 port A (`0xa`) |
| Host interface card 2 | U0 port B (`0xb`) |
| U0 port D (`0xd`) | U2 port D (`0xd`) |
| U0 port C (`0xc`) | U2 port 8 (`0x8`) |
| U0 port 9 (`0x9`) | U1 port 8 (`0x8`) |
| U0 port 8 (`0x8`) | U1 port D (`0xd`) |
| U0 heads E and F | PCI buses 4 and 3 |
| U1 heads E and F | PCI buses 2 and 1 |
| U2 heads E and F | PCI buses 6 and 5 |

Inferred: U0's crossbar is widget `0x0`, ports `0xa` and `0xb` face the hosts, and widgets 1 to 7 have
nothing behind them. The crossbar at widget 0 follows the I-brick and V-brick, which carry an Xbridge
at widget 0 ([xbow-family.md](../../devices/xbow/family.md)). The figure shows no links on widgets 1 to 7.

The figure does not say which head of U1 or U2 rides which of its two links. The widget table below
implies: U1 port 8 carries head F and U1 port D carries head E. U2 port 8 carries head F and U2 port D
carries head E. That pairing is inferred, and it stands or falls with the widget table.

Three XBridge chips is the count the manuals give (`007-4240-002 p. 140`, Figure 2-24). OpenBSD's
`xbridge.c` mentions six XBridge chips on one Crossbow for a P-brick. That conflict is recorded in
[interconnect-naming.md](../../evidence/interconnect-naming.md) and is still open.

Unknown: the silicon revision of each XBridge, whether all three match, each chip's mode strap, and
reset values and reset propagation between chips. A P-brick part-number inventory or a register read
of the three chips would settle these.

## Widget numbering and bus map

The guest does not see U1 and U2 as chips. It sees U0's crossbar and six bridge widgets. Each widget
number is the U0 port that its chip hangs off.

Widget to bus map, inferred:

| Widget | PCI bus | Path |
|---|---|---|
| `0x8` | 2 | U0 port 8 to U1 port D, head E |
| `0x9` | 1 | U0 port 9 to U1 port 8, head F |
| `0xc` | 5 | U0 port C to U2 port 8, head F |
| `0xd` | 6 | U0 port D to U2 port D, head E |
| `0xe` | 4 | U0 head E, internal |
| `0xf` | 3 | U0 head F, internal |

Basis:

- Linux `pcibr.c` at `v2.5.40`, lines 262 to 272, maps widgets 8, 9, c, d, e and f to buses 2, 1, 5,
  6, 4 and 3. Its comment reads "kbrick widgetnum-to-bus layout". The table is an SN1 software
  expectation, not a board measurement.
- The Usenet answer `alg531$9tb$1@knossos.btinternet.com` lists buses 1 to 6 as widgets 9, 8, f, e, c
  and d. It agrees with the Linux table. The question it answers quotes device paths with the widgets
  8, 9, 12, 13, 14 and 15, in that order, not bus order.
- The `bridgeloc` listing in the online diagnostics guide shows P-brick bridge widgets 8, 9, 12, 13,
  14 and 15, under two module IDs. It gives no bus numbers.

The Linux table and the Usenet listing both come from SGI ia64 software, so they are not independent
of each other. The bus-to-port step matches the figure only where the figure gives a link. The bus
numbers themselves are not from a board.

Also inferred: widgets `0x8`, `0x9`, `0xc` and `0xd` each expose one PCI bus and no nested crossbar
window. The Usenet hardware graph puts PCI trees directly under six widget numbers, with no crossbar
level between them. That is one answer's graph, not a register read.

Unknown: the bus number that a physical slot answers to, and the PCI device number of each slot. The
device number and bus numbering a guest reads come from its configuration. A 2002 reply says the guest's
`ioconfig` assigns device unit numbers, and that they need not follow slot order. Device unit numbers
are therefore not slot evidence. A bus scan with a card moved across slots would settle the slot
numbering.

## Guest placement and host routing

Established: a C-brick has one XIO (II) connector (`007-4240-002 p. 125`, Table 4-2, and Figure 4-2 on
p. 123). So the two P-brick ports go to two different C-bricks. The owner's guide describes the
second connector as going to another C-brick (`007-4240-002 p. 142` and p. 216). The Family
Reference Guide (p. 9) says the rear connectors allow the unit "to be dual-hosted to two separate
C-bricks". The partition guide requires both C-bricks of a dual-attached I/O brick to be in one
partition (`007-4311-002 p. 62`).

Inferred: the P-brick's widgets appear in the guest under the C-brick it is cabled to, as the I-brick's
do. The Usenet question quotes device links of the form `/hw/module/Cbrick1/Pbrick/xtalk/8/pci/1`. A
Linux `pcibr.c` comment builds `/hw/module/001c02/Pbrick`. The `bridgeloc` listing places P-brick
vertices under `/hw/module/007c13/Pbrick` and `/hw/module/007c16/Pbrick`, with widgets 8, 13 and 14
under the first and 9, 12 and 15 under the second. Each side then holds one PCI head of each chip. An
I-brick is listed beside them under `/hw/module/007c10/Ibrick`. The listing fits two trimmed P-bricks
or one P-brick dual-hosted to two C-bricks. Which reading is right is unknown. The listing gives no
brick count.

Inferred: a processor access to a PCI card goes from the C-brick's Bedrock I/O interface, through the
host interface card to U0 port A or B, through U0's crossbar to the destination widget and, for widgets
8, 9, c and d, over a link to the downstream chip. DMA and interrupts take the reverse path to the
host widget that the guest programs into each bridge. The chip behaviour at each hop is in the
[bridge-family.md](../../devices/bridge/family.md) XBridge section.

Unknown: which host port carries a widget when both ports are cabled, whether the choice is per widget
or per transaction, and how a guest sees or selects it. A dual-ported P-brick capture or a published
routing rule would settle it.

## Interrupts

Software expectation, inferred: OpenBSD's default pin rule maps pins A and C of device `n` to interrupt
bit `n`, and pins B and D to bit `n` XOR 4 (`xbridge.c`, the interrupt mapping block near lines 1242 to
1290). The IOC3 special case does not apply to a P-brick. This is a driver convention and says nothing
about the board's wiring.

Unknown: which slot pin feeds which bit on this board, whether the default rule holds, and whether two
slots' pins share a bit. Interrupt routing from a slot to a pin is a board property, not a chip
property. A board drawing, or an interrupt trace with one card in each slot, would settle it.

## Translation resources

Inferred from one driver comment: OpenBSD's `xbridge.c` (lines 51 to 58) says a Crossbow has seven
I/O translation table entries, of which the seventh works around a hardware bug, leaving six usable
across all its widgets. Line 146 says allocation can fail, for example "on a P-Brick with 6 XBridge
chips on the same Crossbow". The chip-level translation entry count is a separate thing, covered in
[bridge-family.md](../../devices/bridge/family.md).

Unknown: whether the six entries are shared across all six P-brick widgets, and what a guest sees
when they run out. Chip documentation for the crossbar, or a guest test with six populated widgets,
would settle it.

## Power and management

Established (`108-0240-002 p. 2-30`; `007-4264-002 p. 145`):

- The L1 powers the PCI slots from the lowest-numbered slot, up to the power budget.
- The supply averages 17.5 W per slot. A card may draw up to 25 W.
- Two presence pins per slot let the L1 total the consumption.
- The L1 prints a console message when the budget is short.

Established (`007-4240-002 p. 121`): the C-brick's L1 talks to an I/O brick's L1 through the C-brick's
XIO (II) connector. An L2 is optional in an Origin 3200 and standard in larger systems
(`007-4311-002 p. 42`). The L1 logic is on the power board and its display is on the front
(`007-4240-002 p. 140`).

Established (`007-3938-001 p. 42`; `007-3938-006 p. 60`): the L1 manual lists `p` as the P-brick's type
letter. The identity prints as rack, type letter and bay.

Established (public capture, posted 2006-09-25): the Origin 300 PCI expansion module reports the same
type letter `p`, with its widgets under the same `Pbrick` hardware-graph label. Inferred: the type
letter and graph label do not tell the two enclosures apart. Board class does. OpenBSD's `mnode.h`
names the P-brick board class as brick type 2 (line 220), and the PE-brick class as brick type 5
(line 223). The Origin 300 module reports a PE-brick board. Applying the header to the P-brick is
inferred, since no P-brick inventory is held here.

Established as documented (`007-3938-001 pp. 67 to 69`; `007-3938-006 pp. 82 to 84`): the L1 `pci`
command reports status for each bus and slot of an I/O brick and an expansion module, powers slots,
buses or all slots up and down, and resets them. The sample output in both guides is an I-brick's.
Inferred: the P-brick output has the same form.

Unknown: the P-brick L1 firmware revision, its board-area record, the serial ID EEPROM layout, request
and reply encodings, the management address and the C-to-P management path. No P-brick L1 capture is
held here. A P-brick identity needs its own cited source before it reports anything.

## Differences from the Origin 300 PCI expansion module

| Item | Origin 3000 P-brick | Origin 300 expansion module |
|---|---|---|
| Host attachment | two Crosstown2 ports through host interface cards to U0 ports A and B | one NUMAlink connector to a Bedrock interface card, whose I/O interface reaches U0 port A |
| Host node identity | a C-brick's Bedrock; the P-brick has no node | the card is its own node with no processors or memory |
| Guest module | under the attached C-brick's module (inferred) | its own module with a node vertex |
| Board class | brick type 2 (inferred from the public header) | PE-brick board (public capture) |
| Evidence | published figure, driver tables, one Usenet answer, a diagnostics sample | published figure, public capture |

## Unknowns and what would settle them

| Unknown | Grade | What would settle it |
|---|---|---|
| Widget to bus map on this board | inferred | A P-brick hardware graph or PROM listing with bus and slot labels |
| Head to link pairing on U1 and U2 | inferred | A board drawing, or a bus scan with one card on each bus |
| Chip revisions, mode straps and reset values | unknown | Revision-matched board documentation, or register reads of each widget's identity |
| What the host interface card contains | unknown | A card drawing or a link capture |
| Routing when both ports are cabled | unknown | A dual-ported P-brick capture or a published rule |
| PCI device number and bus number of each slot | unknown | A bus scan with a card moved across slots |
| Slot-to-pin interrupt wiring | unknown | A board drawing, or an interrupt trace with one card per slot |
| Translation entries shared across six widgets | inferred | Crossbar documentation, or a guest test with six populated widgets |
| 64-bit data wiring per slot | unknown | A board wiring document or a transaction capture from each bus |
| P-brick board identity and EEPROM | unknown | A hardware inventory of a P-brick |
| P-brick L1 identity and replies | unknown | An L1 console transcript or a controller specification |
| Link mode selector | unknown | A register description or a guest trace (the 800 and 1200 MB/s modes are in [crosstown-ktown.md](../../devices/crosstown-ktown/README.md)) |

No P-brick is held here, and no physical test is proposed for this enclosure.

## Related pages

- [crosstown-ktown.md](../../devices/crosstown-ktown/README.md): the Crosstown2 port, its speeds and the host interface card.
- [bridge-family.md](../../devices/bridge/family.md): the XBridge chip, its registers and its interrupt delivery.
- [xbow-family.md](../../devices/xbow/family.md): the Crossbow family, including the per-brick probe orders.
- [cbrick.md](cbrick.md) and [ixbrick.md](ixbrick.md): the C-brick that hosts it and the IX-brick
  enclosure that has a similar slot count.
- [origin300-pci-expansion-module.md](origin300-pci-expansion-module.md): the Origin 300 module with
  the same six-widget view.
- [interconnect-naming.md](../../evidence/interconnect-naming.md): the open chip-count conflict.
