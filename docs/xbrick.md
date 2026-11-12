# Origin 3000 X-brick

The X-brick is the 4U XIO expansion enclosure of the Origin 3000 and Onyx 3000 families. It holds one XBridge
chip, two Crosstown2 host ports and four XIO slots. This page records what the manuals establish about its
topology, its slot and connector wiring as drawn, its rates, the XIO boards its manuals list, its place between a
C-brick and a G-brick, its L1, and the board identity the IRIX 6.5.30 kernel and PROM expect. It holds no register
facts, so there is no generated contract for it. The XBridge registers are in [bridge-family.md](bridge-family.md) and
`defs/bridge.xbridge.toml`. The Crosstown2 port is in [crosstown-ktown.md](crosstown-ktown.md). The one X-brick
inventory held here is the Onyx 3000 capture in [onyx3000-graphics-topology.md](onyx3000-graphics-topology.md).
No physical X-brick is identified, and no board part number or silicon revision is known for one.

Grades: **established** (stated in a cited published source, or drawn in one), **inferred** (reasoned from
established facts, or from a driver or a sibling platform), **unknown** (not settled, with the evidence that would
settle it). A software expectation from a shipped binary or a public driver is graded inferred: it says what software
does, not what the hardware does.

## Sources

- SGI, *Origin 3000 Server Series System Architecture*, `108-0240-002`, revision 002. Printed pp. 2-26, 2-27, 2-32,
  2-33 (Figure 2-25), 2-40, 2-41 and 2-42 (Table 2-2). Cited as `108-0240-002 p. N`.
- SGI, *Origin 3000 Series Owner's Guide*, `007-4240-002`, revision 002. Printed pp. 6, 15, 96, 106, 107, 149 to 154,
  217 and 233. Cited as `007-4240-002 p. N`.
- SGI, *Origin 3000 Series Technical Configuration Owner's Guide*, `007-4311-002`, revision 002. Printed pp. 34, 35,
  39, 40, 49 to 51. Cited as `007-4311-002 p. N`.
- SGI, *Origin 3000 Series Internal Technical Configuration Manual*, `108-0266-001`, original release October 2000,
  cover updated 03-21-01. Printed pp. 8, 38, 39, 59, 60, 62, 120 and 171. Cited as `108-0266-001 p. N`. It is a
  same-family manual of a different revision from `007-4311-002`; where they differ both are recorded.
- SGI, *Onyx 3000 Series Graphics System Hardware Owner's Guide*, `007-4264-002`, revision 002. Printed pp. 10, 16, 62
  and 144 to 145. Cited as `007-4264-002 p. N`.
- SGI, *System Cabling, SGI 3000 Series Systems*, preliminary classroom version, `108-xxxx-PR2` (2000). Printed pp.
  1-8, 1-11 to 1-13 (Table 1-7). A preliminary draft, graded accordingly. Cited as `108-xxxx-PR2 p. N`.
- SGI, *Service Procedures, SGI 3000 Series Systems*, `108-0301-001`, printed p. 2-1.
- SGI, *N-brick Overview*, revision 10/24/01, printed pp. 1 and 3.
- SGI, *SGI 3000 Family Reference Guide*, printed p. 10. A vendor overview, marketing grade.
- CERN HNF-Europe 2000 workshop slides, *GSN on SGI's new NUMAflex Architecture*, PDF pp. 5 to 8 and 12. A slide
  deck, less reliable than a manual.
- IRIX 6.5.30 IP35 kernel objects and the stock PROM 6.210 (shipped binaries, read by disassembly and symbol tables).
  Software expectations only.
- L1 firmware 1.44.0, from the IRIX 6.5.30 `l1.bin` composite (the Base 1MB and MIPS 2MB packages), read from the
  controller images. Read by a reader of the binary; not yet checked by a second reader.
- Public Linux SN1 and IA-64 headers and `ml_iograph.c` (linux-mips tree), and the OpenBSD SGI headers and
  `xbow.c` (pinned revision `2df91d80c104`). Software expectations, one port's or one kernel's. The line references
  below are as given by the import source. They were not re-read against the trees while this page was written.
- Usenet, unreviewed: `911aj8$8sude$1@fido.engr.sgi.com` and `a3nqjg$968ip$1@fido.engr.sgi.com`. Informal
  statements, cited only where noted. They quote no register or protocol.

## Topology

**Established** (`108-0240-002 p. 2-26`, `p. 2-27`, `p. 2-33`). The X-brick holds one XBridge ASIC. An XBridge has eight
ports. Ports A and B are Crosstown2 ports. Ports 8, 9, C and D are Crosstalk ports, and in the X-brick each one serves
one XIO slot. Ports E and F are PCI ports. The manual says the ASIC passes packets from a Crosstown2 port to an XIO
device with no protocol conversion. It converts protocol only toward PCI.

**Established** as drawn (`108-0240-002` Figure 2-25, p. 2-33; `108-xxxx-PR2` Table 1-7, p. 1-13). Each XIO slot has
one XBridge port:

| Slot | XBridge port |
|---|---|
| 1 | 8 |
| 2 | 9 |
| 3 | C |
| 4 | D |

The figure is a block diagram, so the table gives the port each slot is drawn on and no widget number. The cabling
draft states the same mapping in words, so two vendor documents agree on it. One of them is a classroom draft.

**Conflict, software side.** The IRIX 6.5.30 IP35 kernel's X-brick table maps widgets 8, 9, 12 and 13 to XIO slots 1,
3, 2 and 4. Read against the table above, widget 9 (port 9) is slot 3 in the software and slot 2 in the documents,
and widget 12 (port C) is slot 2 in the software and slot 3 in the documents. The public Linux SN1 table for the same
brick, `ml_iograph.c` in the linux-mips tree, gives 8 to slot 1, 9 to slot 3, C to slot 2 and D to slot 4, which
agrees with IRIX. The source record also reports a Linux v2.5.40 reading that differs from that table for widgets 9
and 12 (slots 1, 2, 3 and 4 for widgets 8, 9, 12 and 13). That reading is not re-checked here, and it disagrees with
the SN1 table within Linux. The IRIX table is an **inferred** expectation. The Onyx 3000 capture in
[onyx3000-graphics-topology.md](onyx3000-graphics-topology.md) puts an XIO card at widget 12, and it does not say which
slot that is. Either the documents number the slots differently from the
software, or one side is wrong. A board in a known slot, read back through the host port, would settle it.

**Established** (`007-4311-002 p. 34`, Figure 3-16; `108-0266-001 p. 38`, Figure 3-17). The host side has two
Crosstown2 ports, labelled Port A (10) and Port B (11). The figure draws one host interface card serving both ports.
The owner's guide draws the same single card (`007-4240-002 p. 152`, Figures 7-2 and 7-3). The P-brick, by
contrast, is drawn with one card per port (see [pbrick.md](pbrick.md)). **Unknown** whether the X-brick has one card
or two and what the card does (see [crosstown-ktown.md](crosstown-ktown.md)).

**Inferred.** The printed numbers 10 and 11 equal the decimal values of the port letters A and B. The labels therefore
agree with a hexadecimal widget numbering of 0x8 to 0xF, which matches the Crosstalk ports above.

**Conflict, connector side.** The Architecture manual's Figure 2-25 labels Port A as 10. The cabling draft's X-brick
row (Table 1-7) lists "XIO 11" as Port A and "XIO 10" as Port B. Its P-brick and I-brick tables list XIO 10 as Port A
(`108-xxxx-PR2` pp. 1-11, 1-12). The X-brick row therefore looks like a transposition in a preliminary draft, which is
**inferred**. The internal manual's rear view prints the two connectors as "XIO 10" and "XIO 11" beside the four slots
(`108-0266-001 p. 171`), and the printed order carries no mapping. No source settles the connector-to-port mapping,
so it stays **unknown**.

**Established** (`007-4240-002 pp. 153, 217`; `007-4311-002 p. 34`). One Crosstown2 connector is enough to attach one
C-brick. The second connector can go to another C-brick, which makes a dual-ported X-brick with more bandwidth. This
describes what the brick can do, not any one cabling. A connector LED lights yellow when the cable is seated and
green once the link negotiates (`007-4240-002 p. 154`).

**Inferred.** The Architecture manual's "two Crosstown2 ports" and the X-brick's two rear connectors are the same two
host ports, A and B. No released manual names the connector for port A (see the conflict above).

## Rates

**Established** (`108-0266-001 pp. 38, 39`; the glossary at `108-0266-001 p. 8`). The two Crosstown2 ports are
software-selectable at 800 or 1200 MB/s, each direction. Page 38 gives 800 MB/s as the standard configuration. The
glossary defines Crosstown2 as 1.2 GB/s in one direction, half duplex, and 2.4 GB/s in both directions, full duplex.
The SGI 3000 Family Reference Guide (p. 10) says 1.2 GB/s in each direction, and the CERN slide labels the links
800/1200 MB/s each direction.

**Inferred.** `007-4311-002 Table 4-5` (p. 49) lists both the 800 and 1200 modes. The prose on `007-4311-002 pp. 34 to
35` gives "800 MB/s each direction" and does not mention 1200, so that prose describes the standard mode. This
reconciles the 800 MB/s X-brick entry in [crosstown-ktown.md](crosstown-ktown.md), which records 800 as printed: 800 is
the standard mode, and 1200 is the selectable one.

**Established** (`007-4311-002 p. 49`, Table 4-5; Figure 3-16, p. 34; `108-0266-001 p. 59`, Table 4-5). Each XIO port
runs at 800 MB/s, full duplex.

**Inferred.** The family reference guide says the brick's aggregate is 2.4 GB/s, shared between the four XIO slots.
That equals the glossary's full-duplex rate for one Crosstown2 link, and the CERN slide draws one 2.4 GB/s link. The
guide does not say how many ports the figure covers.

**Established** (Figure 2-25, `108-0240-002 p. 2-33`). The slot side is drawn at 400 MHz, and the host side at 1200
MB/s.

**Unknown.** Which mode a power-on default or a register selects, and the sustained rate a real brick delivers. A
register or a measured transfer from a real X-brick would settle them.

## Physical and placement

**Established** (`007-4311-002 p. 35`; `007-4264-002 pp. 144 to 145`). 4U, rack hard-mounted, about 69 lb fully loaded,
48 V DC input at about 225 W, hot-swappable fans.

**Established** (`007-4240-002 p. 149`). The X-brick installs in the I/O rack of an Origin 3800, in the first rack of
an Origin 3400 if space allows, and in an Origin 3200. In an Origin 3200 it sits between the I-brick and the top
C-brick (`007-4240-002 p. 15`).

**Established** (`007-4240-002 p. 154`; `108-0266-001 p. 120`). Each XIO slot takes one card of at most 50 W.

**Established** (`108-0240-002 p. 2-32`). The X-brick slots are compatible with the XIO slots of Origin 2000 and Octane
systems. The configuration manual calls the X-brick "fully compatible" with those slots (`108-0266-001 p. 120`). That
is vendor wording. An informal Usenet reply says the HIPPI card does not fit Octane's XIO mounting
(`911aj8$8sude$1@fido.engr.sgi.com`). The reply does not address Origin 2000 cards in an X-brick.

## XIO boards

**Established** (`007-4240-002 p. 154`, Table 7-1; `007-4311-002 p. 50`, Table 4-6). The manuals list these boards as
supported in the X-brick. The owner's guide says other XIO boards exist and are supported in other systems, not in the
X-brick.

| Board | Marketing code | Notes in the configuration manuals |
|---|---|---|
| Single-port serial HIPPI | `XT-HIPPI-800-SER` | 100 MB/s peak, up to 4 per brick and per system |
| Dual-attach FDDI | `XT-FDDI-D` | Per-brick maximum printed as 6 (see conflicts below) |
| GSN, copper, one port | `XT-GSN-C-1XIO` | 800 MB/s peak, up to 2 |
| GSN, copper, two port | `XT-GSN-C-2XIO` | 1600 MB/s peak, a two-card set that uses two slots, up to 2 |
| Digital video | `XT-DIVO` | Bandwidth not given |
| Digital video with DVCPRO | `XT-DIVO-DVC` | Listed as "Digital video I/O DVC Onyx2" |
| High-definition video | `XT-HD` | Bandwidth not given |
| 6U VME adapter | `XT-VME-6U` | Up to 4 per brick |
| 9U VME adapter | `XT-VME-9U` | Up to 4 per brick |
| Four-port ATM OC3 | `XT-ATM-OC3C-4P` | 19 MB/s peak per port, 4 per brick, 16 per system |

The Architecture manual's examples (`108-0240-002 p. 2-32`) are copper GSN, serial HIPPI, digital video, FDDI,
high-definition video and XIO-to-VME adapters. They match the table.

**Conflicts, left open.**

- The FDDI card's per-brick maximum is printed as 6 in a brick with four slots. A limit above the slot count cannot be
  a slot limit, so the column means something else. `108-0266-001 p. 60` annotates the FDDI row "The FDDI card is a
  PCI card installed in a shoehorn adapter", which is **inferred** to be a different kind of board from the other rows.
  That does not explain the 6.
- The ATM OC3 board is in the October 2000 to January 2001 configuration manuals and absent from the December 2001
  owner's guide. The source record gives its code from `108-0266-001`, and does not confirm the code in
  `007-4311-002`. The revision order suggests the board was dropped, which no source says. ATM is not treated as
  supported here.
- `007-4311-002 p. 51` says its PCI card list applies to "I, P, and X-bricks". Every X-brick description shows XIO
  slots only (`108-0240-002 p. 2-32`, `007-4240-002 p. 149`). No manual shows a PCI slot on an X-brick. The FDDI
  shoehorn note and the CERN slide's "PCI not used in Xbrick" point to PCI cards reaching an X-brick only through an
  XIO slot, if at all. That reading is **inferred**.

**Inferred.** No graphics board is on the supported list, so no Origin 2000 graphics board is an X-brick product. The
owner's guide excludes unlisted XIO boards. Graphics reach a 3000 system through a G-brick or a V-brick
(`007-4264-002 pp. 10, 62`). The V-brick attaches to a C-brick through its own XIO connectors, not through an X-brick.

**Unknown.** Per-board identity and revision, how each board enumerates (widget part and manufacturer numbers,
interrupt wiring), which boards the Origin 3000 software drove in practice, and whether the 1200 and 800 MB/s modes
change what a board sees. A board's behaviour does not carry from the Origin 2000 or Octane to the X-brick by default.
An informal Usenet reply (`a3nqjg$968ip$1@fido.engr.sgi.com`) says the XBridge crossbar cannot be daisy-chained, so an
Origin 300 cannot host an X-brick. That is unreviewed and is not relied on here.

## Ports E and F

**Unknown.** Figure 2-25 draws no connection to ports E and F, and the text does not say they are unused. A CERN
workshop slide (PDF p. 7) says "PCI not used in Xbrick". It is a presentation, not a manual, and its second host label
reads "Port D(11)", an evident typo for B. Whether E and F are electrically unused or merely unwired is unknown. A
widget read of an X-brick would show whether anything answers on them.

## G-brick pass-through

The G-brick rule and the pipe's widget on an X-brick are on [gbrick.md](gbrick.md) and in
[onyx3000-graphics-topology.md](onyx3000-graphics-topology.md). The X-brick's two Crosstown2 connectors serve a pipe
differently from an I-brick's. One goes to a C-brick and the other to a graphics pipe. The Onyx 3000 guide draws this
with the X-brick's pipe connector marked "Pipe 1" (`007-4264-002 p. 16`, Figure 1-5). The capture shows the pipe at
widget 11 of the X-brick's XBridge.

**Inferred.** The pipe occupies one of the two Crosstown2 ports, so a pipe-carrying X-brick has one link left for its
host. The guide does not say whether one X-brick serves XIO boards and a pipe at the same time, but Figure 1-5 draws
an X-brick with its XIO slots and a pipe cable together.

**Established** (`108-0240-002 p. 2-40`; `007-4311-002 pp. 39 to 40`). The G-brick's L1 talks to the L2 over USB. It
does not go through the X-brick. The X-brick's L1 reaches its C-brick's L1 over RS-422 carried in the Crosstown2 cable.

**Established** (`N-brick Overview`, p. 3). The N-brick's four XBridge ASICs on null boards expose only ports A and B,
as 800 MB/s differential connectors. Ports 8, 9, C, D, E and F are "logically disconnected". The N-brick replaces up to
four I- or X-bricks in a multipipe Onyx 3000 (`007-4264-002 p. 58`).

**Unknown.** Which XBridge port (A or B) a pipe's cable lands on, how the pipe appears to the C-brick, how the XBridge
routes a request that enters one host port and leaves the other, the credit and error behaviour across the two hops,
and the protocol-version filtering that an informal Usenet reply (`3BCCC6C0.7040300@brussels.sgi.com`) mentions. A
widget inventory of a G-brick behind an X-brick, with the cable endpoints named, would settle the first three.

## L1 and management

**Established** (`108-0240-002 p. 2-40`, Table 2-2, p. 2-42; `007-4240-002 p. 6`). The X-brick has an L1 controller on
the power board, with a display on the front panel (`007-4240-002 pp. 150 to 152`). The X-brick column of Table 2-2
lists these functions: control of voltage regulator modules, voltage monitoring and margining, fan control and
monitoring, temperature and input-power monitoring, LED control, reading identity PROMs, monitoring the power switch,
reporting XIO slot power levels, and setting XIO termination margins. The X-brick does not monitor the reset or NMI
switches and has no PCI slot power function.

**Established** (`007-4264-002 p. 145`). The power board carries five voltage regulator modules, one DC-to-DC converter
and three voltage regulators.

**Established** (`007-4240-002 p. 150`). Front-panel items are an on/off switch with an LED, a service-required LED
(orange) and a failure LED (red).

**Established** (`108-0301-001 p. 2-1`). A system Secure Serial Number is stored in the hardware L2 controller and in
each brick's L1 NVRAM. If an X-brick's number does not match, the brick takes the number from the hardware L2 and powers
on. Systems without a hardware L2 set it by hand. The manual names the format nowhere, so the format is **unknown**.

**Established** (`007-4240-002 p. 106`). The I/O brick's L1 connections are numbered :0 for the local L1, :1 for the
C-brick on port A and :2 for the C-brick on port B. The bus address and wire format behind those numbers are
**unknown**.

**Established as example output only** (`007-4240-002 pp. 96, 107, 233`). A config listing shows the X-brick as module
`001x01`, and a `ctci` version request sent from a C-brick L1 gets an answer. The version string in those transcripts
is not an identity record. Pages 106 and 107 and page 233 print different build dates for the same version string, so
the string does not identify an image.

**Established from L1 firmware 1.44.0** (the Base 1MB and MIPS 2MB packages of the IRIX 6.5.30 `l1.bin` composite,
read from the controller images). The L1 takes its letter from the name field of its board EEPROMs. The power board
record (`0xa4`) is read first, then the logic board record (`0xa8`). A logic board named `XBRICK` gives the letter `X`
(`0x58`) in the `0x0003` reply, and the `brick` command reports the source as EEPROM. The X personality names its bridge
`XBridge`, registers one bridge entry and no PCI table, and has two EEPROM records, `POWER` and `LOGIC`, for `0x0006`.
Its I/O expanders are named `XBRIDGE CONTROL` and `XIO CONTROL`. It answers `0x000a` from settings 42 and 43, which are
the port A and B speeds that `ioport` prints, and it applies a minus-108 adjustment to the values it reports in replies `0x2007` and `0x2008`. The source gives no
more detail on that arithmetic.

**Inferred.** The firmware has no separate V-brick personality, and its `V` is the IP53 2U CG graphics brick (see
[onyx3000-graphics-topology.md](onyx3000-graphics-topology.md)). A V-brick would therefore run the X personality if its
logic board is named `XBRICK`.

**Unknown.** The L1 controller revision fitted, the serial format it returns, the board-area and EEPROM contents, the
X-brick's L1 address on the C-brick's controller bus, the XIO power report format, and the termination margin command
encoding. An X-brick L1 console trace or a controller specification would settle these.

## Board identity in the IRIX kernel and PROM

**Software expectation, inferred** (IRIX 6.5.30 IP35 kernel and PROM 6.210). The kernel asserts that a node with a live
widget on its crossbar has a class `0x70` board record. The PROM writes those records only for live Bridge, XBridge or
PIC widgets. An X-brick carrying only XIO boards, with no bridge, would therefore need its XBridge heads at widgets 14
and 15 to be visible. The Onyx 3000 capture lists `XBRICK` records at `xtalk/14` and `/15` on an X-brick that carries a
pipe and an XIO card. That shows the heads on that brick, and is the only evidence of it.

**Software expectation, inferred.** The X-brick's board type is `0x73`: class `0x70` with low nibble 3
(`mnode.h`, OpenBSD revision `2df91d80c104`, lines 195 to 240). Linux defines `KLCLASS_IOBRICK` as `0x70` and
`KLTYPE_XBRICK` as that class or `0x3`. The IRIX PROM's expected I/O-port speed for the brick is 400 MHz. The module
class letter is `x` (`001xNN`), the hardware-graph name is `Xbrick`, and the letter `Y` (the X2 brick) converts to it.

**Software expectation, inferred.** The IRIX 6.5.30 kernel's widget-to-slot table is in the Topology section. The
probe order that the OpenBSD kernel uses for the X-brick is in [xbow-family.md](xbow-family.md), and the XBridge heads at
widgets 14 and 15 are in [bridge-family.md](bridge-family.md).

## Unknowns and what would settle them

| Unknown | Grade | What would settle it |
|---|---|---|
| Slot-to-port mapping at widget level | unknown | A widget inventory of an X-brick, or a board drawing that maps each slot. A distinguishable board in each slot, read back through the host port, would confirm it |
| Connector-to-port mapping (A is 10 or 11) | unknown | A cable record or a connector drawing; one C-brick attached to each connector in turn |
| Fitted XBridge silicon revision and mode | unknown | Revision-matched board documentation, or register reads of the identity word |
| Whether PCI ports E and F are used | unknown | A widget read of the X-brick's ports E and F |
| One host interface card or two | unknown | A card drawing or a one-wire record of an X-brick |
| Default Crosstown2 mode and sustained rate | unknown | A register description or a measured transfer |
| FDDI per-brick limit of 6 | unknown | The column's definition in the configuration manual, or a second source |
| ATM OC3 support | unknown | A current support statement from a manual later than December 2001 |
| Pipe widget and routing behind an X-brick | unknown | A widget inventory of a G-brick behind an X-brick with the cable endpoints named |
| L1 revision, serial format and EEPROM contents | unknown | An X-brick L1 console trace or a controller specification |
| Whether the XBridge heads answer on an X-brick with XIO boards and no pipe | unknown | A widget scan of an X-brick with XIO boards and no pipe |
