# BaseIO and BaseIO-G: the XIO I/O board of the Origin 2000 and Onyx2

Status: **research draft, not independently reviewed.** The board is an XIO board, not an ASIC, so this page
holds no register contract of its own. It records the board's composition, PCI placement, interrupt wiring,
panel connectors and the one-wire identity records that IRIX reads, and it says which of those facts the
[IOC3 page](../chips/ioc3/README.md) and the [Bridge page](../chips/bridge/README.md) already hold.

A BaseIO connects to a Crossbow through a Bridge. A 32-bit PCI bus behind the Bridge carries one IOC3 and two
SCSI controllers. The BaseIO-G, the Onyx2 variant, adds a MediaIO daughtercard (MIO) with a second IOC3 and a
RAD1 audio ASIC. The Origin 200 has no BaseIO card: its System Board is integrated, and nothing here applies to it.

Labels follow [AGENTS.md](../AGENTS.md): **established** (published manual page, public driver, or a hardware
listing printed by a real machine), **inferred** (a reading of a figure, a photograph, a name or a driver's
expectations), **unknown** (what would settle it is named in the open questions). Facts that come from
IRIX kernel disassembly are software expectations, so they are graded inferred unless a published source
states them directly.

## Sources

Numbered references are at the end of the page. The most-cited ones are the SGI Origin and Onyx2 Theory of
Operations (007-3439-002, cited as [1]), the Onyx2 Deskside owner's guide (007-3454-005, [2]), the Hardware
Quick-reference Booklet (HMQ-380-C, [3]), and owner `hinv` listings ([4], [5]).

## Assemblies and part numbers

| Assembly | Part and revision seen | Grade | Notes |
|---|---|---|---|
| Plain BaseIO, server version | base board 030-1124-002 rev J | established ([5]) | The Origin 2000 server board. One `hinv` board line, name `BASEIO`. |
| BaseIO-G (IO6G), graphics version | base board 030-0734-002 rev N | established ([4]) | Carries the MIO connection. Revisions K and N are both seen, with an earlier base board 030-0734-001 listed in a parts catalogue (community list, not a vendor document). |
| MediaIO (MIO) daughtercard | 030-0880-003, rev G on one owner's unit; silkscreen rev F and rev E on two photographed units | rev G established ([4]); the photographed revisions inferred | Fits only the BaseIO-G. Standard BaseIO has an MIO expansion connector but no MediaIO is fitted to it [1]. |
| Genlock daughtercard | 030-1101-001 | inferred (photograph) | Fitted on some units; the photographed stack carries one. |

The plain BaseIO and the BaseIO-G differ in more than the MIO: the plain board has no keyboard or mouse port
[3], so an Origin 2000 that runs a graphics pipe with a local console needs the BaseIO-G. Owner reports of
Origin 2000 IMPACT systems that fit a BaseIO-G beside the graphics board are inferred from those reports and
from the plain board's missing ports ([6]). One owner reports soldering PS/2 connectors onto a plain board
instead, which is a field modification and not a board revision.

## PCI placement on a BaseIO-G

The owner's `hinv -v` output for a BaseIO-G on an Origin 2000 gives the Bridge's PCI slots [4]:

| Bridge PCI slot | Function | PCI vendor:device | Grade |
|---|---|---|---|
| 0 and 1 | QLogic QL1040B SCSI controllers, rev 2, single-ended | `0x1077:0x1020` (ISP10x0 family) | established ([4]) |
| 2 | Board IOC3 | `0x10a9:0x0003` | established ([4]) |
| 4 | no function listed | none | established ([4]) |
| 6 | MediaIO IOC3 | `0x10a9:0x0003` | established ([4]) |
| 7 | RAD1 digital audio ASIC | `0x10a9:0x0005` | established ([4]) |

RAD1 sits at slot 7 on this listing. The register contract in `devices/rad1/registers.toml` names PCI device 5, but that
is the device number the IP30 driver registers for its own PCI audio board. It is not a slot number, and this
page does not change it.

The owner's `hinv` does not show a PCI function for the genlock card, so the listing does not say whether that
unit had one fitted. The listing shows no function at slot 4. The [IOC3 page](../chips/ioc3/README.md) covers
the chip's own functions behind each slot.

## Chips on the board

These come from published photographs of two MediaIO-bearing units and one base board [7]. Chip markings
read from photographs are inferred until a board is read directly.

- Board IOC3: LSI L2A0366, marked SGI 099-0126-003 rev C. The MediaIO carries a second IOC3 with the same mark.
- RAD1: LSI L2A0470, marked RAD1 REV B, SGI 099-0142-002. It sits beside the MediaIO's IOC3, not on the base board.
- Audio section on the MediaIO: a Cirrus Logic CS8412-CS AES3/S-PDIF receiver, a Texas Instruments TLC320AD58
  stereo codec, and a Cirrus Logic CS3310-KS digital volume control. One unit shows a single CS3310; a claim of
  three is not confirmed.
- Time-of-day part on the base board: ST M48T35Y Timekeeper NVRAM.
- Flash on the base board: AMD AM29LV800B, 1 MiB.
- Two HV51-100 crystal oscillators near the audio section, at 11.2896 MHz and 12.288 MHz. These are the usual
  master-clock rates for 48 kHz-family digital audio.
- An earlier revision of this section named a Cirrus CS4297 AC'97 codec on the MediaIO. No such marking is
  legible in any photograph, and that identification is wrong.
- Two Analog Devices SSM2142 balanced line drivers are claimed in one source but are not visible in either set of
  photographs. **Unknown.**
- The split of the AES3 and ADAT paths among RAD1, the CS8412 and the TLC320AD58 is **unknown**.

The SCSI controllers are QLogic parts, as in the placement table above. Figure 2-25 of [1] draws one controller
through a differential transceiver, but the owner's `hinv` and the Onyx2 guide [2] both give single-ended. The
difference may come from the standard BaseIO's drawing versus the BaseIO-G's hardware. No guest-visible effect
of it is known. **Unknown.**

## Interrupt paths

The Theory of Operations [1] draws the board's interrupt connections. Reading the figure gives these paths.

- The board IOC3's external-interrupt output (`INT_OUT`) goes to the Bridge directly. Grade: inferred (figure).
- The real-time interrupt input jack feeds the Bridge's interrupt input through an opto-isolator. Grade: inferred (figure).
- The Bridge drives the real-time interrupt output jack at the board edge. Grade: inferred (figure).
- The IOC3's real-time output is also a local source. A one-pulse strobe posts SuperIO status bit 27 on the rising
  edge of the outgoing signal, whether or not the external input is connected. Grade: inferred (IRIX driver
  expectation, [8]).
- On the board, the IOC3 presents its SuperIO sources on PCI interrupt pin D. Which numbered Bridge input standard
  BaseIO wires that pin to is **unknown** from the figure and text. IRIX's interrupt setup uses input 4 for the
  board IOC3 and input 6 for the MediaIO IOC3 [8]. Grade: inferred (kernel disassembly); the pin-to-input wiring
  itself is not measured.
- A loop-back cable from the output jack to the input jack makes the outgoing pulse reappear on the input side,
  visible on its falling edge. Internal-only use enables the IOC3 output-pulse source and disables the
  external-input source. Grade: inferred (figure and IRIX behavior, [8]).
- The jacks are 3.5 mm tip-ring-sleeve jacks. They are not BNC connectors. Grade: established ([2]).

IRIX creates an `ei` child below the IOC3's PCI vertex when real-time support is enabled, so the full path on a
standard BaseIO is `/hw/module/<module>/slot/io1/baseio/pci/2/ei`. The real-time tool takes the parent path that
ends in `/pci/2` and appends `/ei`. The interface next to the system console also has an alias at
`/hw/external_int/1`. Grade: inferred (IRIX names read from kernel disassembly [8]).

The IOC3 page holds the register, acknowledgement and pulse-timing contract for the IOC3 side of these paths.
The Bridge page holds interrupt aggregation and crosstalk delivery.

## Subdevice enable word (IRIX)

IRIX attaches each IOC3 function only when a bit in an eight-byte "subdevice-enable" word, kept with the IOC3's
PCI slot, is set. An absent word defaults to all ones, so every function attaches. The attach routines test
these bits [8]:

| Bit | Function |
|---|---|
| 0 | Ethernet |
| 3 | PS/2 keyboard and mouse, one bit for both |
| 4 | serial port A |
| 5 | serial port B |
| 7 | real-time (external) interrupt |

No attach routine tests bits 1, 2 or 6 by themselves. The interrupt check tests the word against `0xfa`, which
covers bits 1 and 3 to 7, so bits 0 and 2 fall outside it. A slot with no word counts as needing the interrupt.
Bit 6 appears only in the MediaIO value and is an unconfirmed candidate for the parallel port.

The word comes from the board's one-wire identity [8]:

- `0xbf` for the standard BaseIO's IOC3 at PCI device 2 (`0xb7` without the keyboard and mouse option). The
  [Bridge page](../chips/bridge/README.md) records the same two values as they reach the subdevice routine.
- `0x7a` for the MediaIO's IOC3 at PCI device 6, when the one-wire identity carries the `030-0880` part number.
  So device 6 does not get Ethernet, and IRIX attaches serial, keyboard and mouse there.
- A separate override writes `0x91` when the IOC3's hardware-graph name contains a particular string. That string
  is **unknown**, so it is not known whether the override reaches a real board.

The word lives in kernel memory, not in a register, and the values above are software expectations. No hardware
read confirms them.

## Board identity on the Bridge one-wire bus

Each board's Bridge carries a one-wire part that IRIX reads. The owner's `hinv -vm` on a BaseIO-G lists two
records at the Bridge's location: the MIO board (030-0880-003 rev G) and the BASEIO board (030-0734-002 rev N) [4].
On the plain BaseIO, one record names the base board (030-1124-002 rev J) [5]. The records use a fixed 64-byte
layout, in two 32-byte pages, each with a check value.

| Bytes | Field | Contents | Grade |
|---|---|---|---|
| 0 | format | `0x01` | inferred (software expectation from the Bridge records) |
| 1-10 | barcode | per-unit serial; this page records no unit's barcode | not a board fact |
| 11-29 | part number, first part | `030-0734-`, `030-0880-` or `030-1124-`, space padded | established (the `hinv` part strings); inferred (the field layout) |
| 30-31 | check value | CRC-16 check of bytes 0-29, see below | established (rule, verified below) |
| 32-37 | part number, dash number | `002` or `003`, space padded | inferred |
| 38-41 | revision | one letter, left aligned, space padded | inferred; alignment unknown |
| 42-47 | group, capability, variety | `0xff` in all six bytes | inferred |
| 48-61 | name | `BASEIO` or `MIO`, space padded | established (names from `hinv`); inferred (padding) |
| 62-63 | check value | CRC-16 check of the second page | established (rule, verified below) |

The check value is the ones' complement of a CRC-16 with reflected polynomial `0xa001`, initial value 0, computed
over the page's first thirty bytes and stored low byte first. A complete page leaves the residue `0xb001`. The
three records above recompute to their stored check values under this rule, and each page leaves that residue.
Linux assembles `030-0734-002` and `030-0880-003` from these pages and matches its BaseIO-G prefixes against
them [9]. OpenBSD also accepts both pages, but it reads such records only on the I/O controller's bus, not on
the Bridge's [10]. Both drivers are software, so the layout is an expectation about the software, not a
measurement of the silicon.

The name is also the slot's hardware-graph name, lower-cased. On `hinv` listings, `baseio` is the BaseIO-G's slot,
`menet` and `mscsi` the Origin 2000 option boards, `fibre_channel` the Fibre Channel board, and
`xbox_dualxtown` an Origin 200 board [4][11]. The name rule is inferred from those listings. Which of the two
BaseIO-G records names the slot is **unknown**: the owner's listing puts the MIO record first but names the slot
`baseio`. The listing order is also **unknown**. A raw dump of a real board's pages would settle both questions.

### Writes to the time-of-day part (IRIX)

The NVRAM write routines of the IRIX IP27 kernel find the Timekeeper through a hardware-graph path that contains
the slot name, `module/<M>/slot/io1/baseio/pci/2/ioc3`, falling back to a `MotherBoard` path. A module whose
lookup fails is skipped. The clock-write routine also updates a leap-cycle marker at NVRAM offset `0x3883`. Grade:
inferred (IRIX kernel disassembly [8]). The reads use a base address saved at boot and do not depend on the lookup.
A board whose slot name is not `baseio` would therefore skip NVRAM writes, but no real board has been tested this way.

## Panel connectors

These are the connectors of the BaseIO-G panel, as the Onyx2 Deskside owner's guide [2] and the theory manual [1] list them.
The plain BaseIO's panel is described only in part; its details are not in the sources reviewed.

| Connector | Count and kind | Driven by | Grade |
|---|---|---|---|
| 10/100 Ethernet, RJ-45 | one | Board IOC3 Ethernet, through an MII link to an MC34440 PHY [1] | established (connector, [2]); inferred (PHY) |
| Serial, `tty_1` (console) and `tty_2` | two | Board IOC3 UART | established ([1], [2]); which connector is which is inferred |
| Serial, `tty_3` and `tty_4` | two | MIO IOC3 UART through the MIO Super I/O | established (the connectors); inferred (the chip) |
| PS/2 keyboard | two six-pin mini-DIN | one on the MIO IOC3; the other on the board IOC3 | established (two connectors); inferred (which chip drives each) |
| PS/2 mouse | two six-pin mini-DIN | as the keyboard | as the keyboard |
| Parallel, IEEE 1284-C | one 36-pin half-pitch connector | MIO IOC3 parallel context, through the MIO Super I/O | established ([1], [2]); the connector is IEEE 1284-C, not DB25 |
| SCSI, external | one 68-pin, single-ended | one of the two SCSI controllers | established ([2]) |
| Audio | analog stereo in and out, AES3 digital in and out (BNC), ADAT optical in and out | RAD1, with the TLC320AD58 and CS8412 as above | established (connectors); inferred (the split) |
| BNC, video sync loop-through | two | genlock daughtercard, where fitted | established (connectors, [2]); inferred (the reach to RAD1) |
| BNC, AES3 digital | two, labelled "Digital" | RAD1 path | established (connectors); inferred (the path) |
| Real-time interrupt in and out | two 3.5 mm jacks | Bridge; see Interrupt paths | established (connector type) |

The keyboard and mouse ports are two pairs, with the primary pair on the right of the panel [2]. An IO6G in XIO
slot 1 supports two keyboard and mouse connections [3]. The MediaIO adds one keyboard port and one mouse port [1].

Owner reports fill in how the pairs behave in use [12]. One owner of a rack Onyx2 with three pipes ran three
keyboards as separate X server inputs from two assemblies. Using all four pairs worked for only one or two of
them, with keyboards and mice crossing between ports. Which chip drives which connector is not settled by any source, so the mapping
of the second keyboard and mouse pair to the board IOC3 is inferred.

The panel LEDs have no register: two on the Ethernet jack (transmit and any-packet activity) and four above it
(SCSI activity, 100 Mb/s, full duplex, link) [2]. Nothing in the sources gives them a software-visible contract.

The panel shows four BNC connectors, and none of them is a real-time interrupt path. The real-time interrupt jacks
are the two 3.5 mm jacks.

Both SCSI controllers report single-ended, as noted above.

## Facts this page leaves open

- Which numbered Bridge input standard BaseIO wires its pin D to. **Unknown.** Settled by the Bridge wiring
  drawing or by a live interrupt trace on a real board.
- Which record names the BaseIO-G slot, and the record order. **Unknown.** Settled by a raw dump of both records
  from a real BaseIO-G, or by an IRIX attach trace on a real board.
- The revision alignment in the four revision bytes. **Unknown.** A raw page dump settles it.
- The SSM2142 drivers and the AES3/ADAT split among RAD1, the CS8412 and the TLC320AD58. **Unknown.**
- Which keyboard and mouse connector is wired to which chip, beyond the panel-placement inference. **Unknown.**
  `ls -l /hw/input*` on a real BaseIO-G with a keyboard in one port would settle it.
- The override string that writes `0x91`. **Unknown.**
- Whether a multi-enclosure system fits one BaseIO per enclosure or one for the whole system. Configuration-dependent [1].

## References

[1] Silicon Graphics, *Origin and Onyx2 Theory of Operations Manual*, document 007-3439-002, revision 002.
    BaseIO on printed page 67, Figures 2-24 and 2-25 (pages 68 and 69), physical layout Figure 2-26 (page 70),
    MediaIO and Figure 2-27 (pages 71-72).

[2] Silicon Graphics, *Onyx2 Deskside Workstation Owner's Guide*, document 007-3454-005. The IO6G connector list
    (printed page 7), the panel figure and the connector table (pages 26-27), the keyboard and mouse pairs
    (page 61), the panel LED figure and descriptions (pages 55-56), and the loop-through and digital audio
    connectors (page 71).

[3] Silicon Graphics, *Hardware Quick-reference Booklet (Origin and Onyx2 Series)*, HMQ-380-C. The IO6G
    keyboard and mouse connections, the plain board's lack of a PS/2 port, and the IO6G pin assignments.

[4] An owner's `hinv` output for a populated BaseIO-G Origin 2000, quoted in a public forum thread on the
    Origin and Onyx2 hardware (nekonomicon forum, thread 17194). It gives the base board part and revision, the
    `hinv -v` PCI adapter lines and the `hinv -vm` board records.

[5] An owner's Origin 2000 `hinv -m` posted to comp.sys.sgi.hardware, December 2001, message
    `<9uhh6o$j75@dispatch.concentric.net>`. Its board lines include the plain BaseIO part 030-1124-002 rev J.

[6] Public forum threads on Origin 2000 IMPACT owners fitting a BaseIO-G (nekonomicon forum, threads 17194 and
    5749). They describe the replacement and the added PS/2 connectors.

[7] Published auction photographs of two BaseIO-G units with MediaIO daughtercards, and one photographed genlock
    stack. Chip markings and silkscreen read from these are inferred.

[8] IRIX 6.5.30 IP27 kernel disassembly: the subdevice-enable word and its attach tests, the board-identity
    dispatch that selects `0xbf`, `0xb7` and `0x7a`, the IOC3 interrupt setup with Bridge inputs 4 and 6, the
    `ei` hardware-graph child and the NVRAM write routines. These readings come from an earlier disassembly
    pass and have not been re-read in this repository. Treat them as software expectations until they are.

[9] Linux mainline `db2ddb871435`, `arch/mips/pci/pci-xtalk-bridge.c` (`bridge_setup_ip27_baseio6g`, selected by
    the Bridge board part `030-0734-` or `030-0880-`) and `drivers/mfd/ioc3.c` (`ip27_baseio6g_setup`,
    `ip27_mio_setup`). Software expectation.

[10] OpenBSD `2df91d80c104` (`sgi-is-alive-at-7.9`), `sys/arch/sgi/pci/ioc.c`. Software expectation.

[11] A public Origin 200 `hinv -vm` on the SGI preservation wiki's Origin 200 page, listing `xbox_dualxtown`, `mscsi`
     and `menet` slot names.

[12] Public Usenet post on comp.sys.sgi.graphics, July 1998, message `<35AB0320.794B@kyb.tuebingen.mpg.de>`,
     an owner's report of keyboard and mouse pairs on two BaseIO assemblies.
