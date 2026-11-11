# Crosstown, KTOWN, Ktown2 and Xtown2: the XIO-over-cable conversion boards

What these four names are, which is a protocol, which a board, which a cable, how an XIO link
changes when it leaves the enclosure, which machines and graphics pipes use them, and what shipped
software can see of them. Labels follow [AGENTS.md](../AGENTS.md): **established**, **inferred**,
**unknown**. Each fact names its source. IRIX binaries are named by release, file and offset.
Shipped IRIX headers and scripts are named as provenance only; nothing is copied from them.
Manuals are cited by SGI document number and printed page. Public forum captures are cited by
title or URL.

Sources not used: the IRIX source tree was not opened for this page. Every IRIX fact below comes
from the shipped 6.5.30 and 6.5 base media, their headers and their binaries. The public Linux and
OpenBSD trees were searched for `crosstown`, `ktown` and `xtown` (Linux `arch/mips`, OpenBSD
`sys/arch/sgi`) and have no hit. They do carry the widget and board-type scaffolding used below
(Linux `asm/sn/klconfig.h`, `asm/xtalk/xwidget.h`; OpenBSD `xbow/xbowdevs`).

## Summary

| Name | What it is | Grade | Source |
|---|---|---|---|
| XIO | SGI's name for the I/O link. Crosstalk is very probably the same protocol under its other SGI name. | inferred. XIO is defined in 007-3439-002 p53 and 007-4311-002 p8; Crosstalk in 007-4311-002 p4. No cited page equates them: 007-3439-002 p28 labels the Hub's 8- and 16-bit I/O port rows "Crosstalk", and 007-4311-002 p9 calls Crosstalk an I/O system "compatible with some XIO boards". Public Linux calls the same thing xtalk | 007-3439-002 pp28, 53; 007-4311-002 pp4, 8, 9 |
| Crosstown | The XIO protocol carried outside an enclosure: STL levels converted to differential 3.45 V PECL and run over a cable of up to 3 m. Also the name of the board that does it. | established | 007-3439-002 pp53, 73, 93 |
| Crosstown Converter board | A host-side XIO-slot board: an XC chip plus external cable connectors. | established | 007-3439-002 p93 |
| XC (Crosstown Converter) chip | An ASIC that converts STL to PECL and back. | established (existence and function); register interface unknown. Settling test: none held; no census here covers an XC chip, and the manual pages cited describe the board, not registers. Test that would settle it: a converter-specific register access in the Xbow link bring-up of a PROM or kernel, found by the link census with the converter's widget or port; none is recorded, so the end state today is unknown, no software dependency | 007-3439-002 p92 |
| XTOWN | Short name, in the Onyx2 rack guide, for the compute-module XIO board that carries a pipe's cable out. | established | 007-3457-005 pp5, 14, 48 |
| KTOWN | The board in the graphics module that receives the cable and feeds the pipe boards. Origin2000/Onyx2 generation. NIC name `KTOWN`, part 030-1067. | established | 007-3457-005 pp14, 48; irsaudit; captures |
| Ktown2 | The same role for the Origin 3000 / Onyx 3000 / Onyx 350 generation. One per G-brick, two connectors, one per pipe. NIC name `KTOWN2`, part 030-1593. | established | 007-4264-001 pp8, 17, 20; 007-4264-002 pp10, 39; irsaudit |
| Xtown2 | The second-generation cable and port: a differential channel that carries the Crosstalk protocol between a C-brick and an I-, P-, X- or N-brick, and between those and a G-brick. Pronounced "Crosstown two". | established | 007-4311-002 p8; 007-4264-001 p20 |
| Crosstown2 | SGI's longer spelling of Xtown2 in the Origin 3000 and Origin 300 owner's guides. | established | 007-4240-002 pp125, 135; 007-4365-002 pp1, 8 |

The words split cleanly by kind. **Protocol:** none of the four is a new protocol. Crosstown and Xtown2
both carry XIO (Crosstalk) unchanged; the difference is the physical layer. **Board:** XTOWN
(host side) and KTOWN, Ktown2 (graphics side). **Cable:** the Crosstown cable (first generation) and the
Xtown2 cable (second). **Chip:** XC. The page keeps the manuals' spellings where it quotes them
and uses Xtown2 for the cable and Ktown2 for the board.

## The glossary entries in full

Established, 007-3439-002 printed pages 92 and 93 (glossary):

- "Crosstown Converter (XC) chip" is an ASIC that converts STL protocol to PECL, and back.
- "Crosstown Converter board" is an XIO board that connects the XIO interface to an external
  chassis, "required, for instance, to connect an Origin2000 module to a graphics chassis", and
  it contains an XC chip and connectors for external cabling.
- "Positive ECL (PECL)" is the differential signal level used in external cables for CrayLink
  Interconnect and XIO (Crosstown) interconnections (p98).

Established, 007-4311-002 printed page 4 (glossary): "Crosstown" is listed as "See Xtown". The
same glossary defines Crosstalk as a protocol name and as a single-ended channel that "transfers
data between Xbridge ASICs or between Xbridge and XC chips within a brick". That entry puts an XC chip
inside Origin 3000 bricks, on the single-ended side of Xtown2. It is the only place the second
generation names XC chips. 007-4240-002 p248 (the `ioport` command text) also says "the word XBridge refers to
the crosstown ASIC in the I-, P-, or X-brick", so SGI's own text calls the brick-side Xbridge a
"crosstown ASIC". Whether the Xtown2 converter is a separate XC part or is the Xbridge's own port
logic is therefore **unresolved**: the glossary says XC, the owner's guide says Xbridge. Page 8 defines Xtown2 as "a differential I/O channel that uses the
crosstalk channel protocol", 1.2 GB/s one direction and 2.4 GB/s both directions, "pronounced
Crosstown two".

## Electrical and encapsulation difference from in-enclosure XIO

### First generation (Origin 2000, Onyx2, Origin 200)

| Property | In-enclosure XIO | Crosstown | Grade and source |
|---|---|---|---|
| Signalling | STL, SGI's low-swing single-ended CMOS signalling, 2.5 ns cycle, ASIC to ASIC across a midplane | differential 3.45 V PECL on a cable | established, 007-3439-002 pp57, 73 |
| Converter | none | an STL-to-3.45 V PECL converter plus a cable attachment on an XIO board | established, p73 |
| Reach | one midplane | XIO devices "up to 3 meters away" | established, p73 |
| Protocol and width | XIO, 8 or 16 bits programmable per port | the same protocol; the converter changes levels, not the message format | width programmable: established, p53. "Not reframed": inferred (the manual says only that the STL link is converted to differential levels) |
| Use | any XIO widget | "primarily used to support graphics configurations" | established, p73 |

007-3439-002 p53 says "the electrical interface for XIO is the same as that used by CrayLink
Interconnect", and the PECL glossary entry (p98) says PECL is the differential level used in the
external cables of both CrayLink Interconnect and XIO (Crosstown). Both established. Neither says a
Crosstown cable can be plugged into a router port or the reverse.

Encapsulation. **Inferred** (from the glossary and the Onyx2 rack guide's block diagrams): the XC
chip appears on both ends. The compute-side XTOWN board converts STL to PECL for the cable; the
graphics-side KTOWN converts PECL back to STL for the pipe's boards. The manual states the
conversion direction for the compute-side board only; the reverse conversion on the pipe side is
needed because the pipe boards sit in a midplane enclosure of their own, but no page says so.
**Unknown:** whether the link is retimed or merely level-shifted at each end. The test is below.

### Second generation (Origin 300/350, Origin 3000, Onyx 350, Onyx 3000)

| Property | Value | Grade and source |
|---|---|---|
| Signalling | differential; carries the Crosstalk protocol | established, 007-4311-002 p8 |
| Cable | a NUMAlink 3 style cable. The Origin 300 guide says the Crosstown2 connection "is made with a NUMAlink 3 cable"; the Onyx 3000 guides draw Xtown2 and NUMAlink as separate cable kinds in the same figures. | established as printed; whether the cables are interchangeable is unknown. Settling test: compare the cable part numbers and connector drawings for NUMAlink 3 and Xtown2 in the Onyx 3000 and Origin 300 cabling chapters (007-4311-002, 007-4240-002); one part number for both settles it as interchangeable, distinct numbers with different connectors as not |
| Speed | 800 MB/s or 1.2 GB/s each direction. Ports "support two speeds, 800 MB/sec and 1200 MB/sec, which can be selected with software" | established, 007-4240-002 p135 |
| Speed readout | the L1 `ioport` command reports an I/O port at 400 MHz or 600 MHz; the C-brick (Bedrock) port falls back to 400 MHz when no I/O is attached | established, 007-4240-002 p248. 400 MHz and 600 MHz against 800 MB/s and 1200 MB/s is the inferred pairing (two bytes per clock) |
| Extra signals | the system-control figures label Xtown2 as carrying RS-422 signals: the L1 controllers of the C-brick and the I-, P- or X-brick talk over the same cable | established, 007-4240-002 p71, pp83-84; 007-4311-002 p43 |
| Hot plug | do not plug or unplug while the system runs; "this can hang or crash the entire graphics rack system" | established, 007-4264-001 p21 |
| Ground | a ground-potential difference above 0.5 V between chassis joined by NUMAlink or Xtown2 cables can cause severe damage | established, 007-4264-002 p99 |
| Host interface card | in the P-brick and X-brick a host interface card sits between the Xtown2 connector and the XBridge. Its function is not described. | established (presence, 007-4311-002 p34 figure 3-16); function unknown, see below. Settling test: the card's description in the P-brick and X-brick service chapters of 007-4311-002, or its part number in the one-wire record of a P-brick or X-brick capture; neither is held, so the function stays unknown |

The speed is not one number, and two guides for the same product disagree. The Origin 300 guide
(007-4365-002 p8) quotes 800 MB/s each direction for the Crosstown2 connector that serves a pipe.
For the Onyx 3000 I-brick, the graphics systems guide (007-4264-002 p8) gives two 800 MB/s ports (in each
direction) that reach a C-brick, G-brick or V-brick, while the owner's guide (007-4264-001 p2) gives
two 1200 MB/s Xtown2 ports. The Origin 3000 guides
give 1.2 GB/s for the C-brick and I-brick ports (007-4240-002 pp125, 135), and 007-4311-002 gives
the P-brick 1.2 GB/s and the X-brick 800 MB/s (pp31, 34). All established as printed. The
software-selected 800 or 1200 is a property of the port (p135 above).

## Which machines and pipes use them

| System | Host side | Graphics side | Grade and source |
|---|---|---|---|
| Origin 2000 / Onyx2 rackmount (one to eight pipes, "RealityMonster" multirack) | one XTOWN XIO board per pipe, in a compute-module XIO slot | a graphics module holding a KTOWN with two connectors for pipe 0 and pipe 1, GE, RM/TM and DG boards | established, 007-3457-005 pp5, 12-14, 29, 47-48. The slot rules (XTOWN and IO6G distributed across nodes and Crossbows, and no more than one pipe per node) are from the Hardware Quick-reference Booklet HMQ-380-C, "Configuring Xtown on Onyx2 Systems", printed p130 |
| Onyx2 deskside | none | the pipe sits in the deskside's own graphics slots; no Ktown | the manual's block diagram labels "Graphics slots" (007-3454-005 p9) and neither name occurs in that guide: established. No Ktown record in a deskside capture: inferred, only the guide was read |
| Origin 200 with a GIGAchannel cabinet | a Crosstown board (part 030-1264) plugged into the Origin 200 motherboard; the cabinet's own Crossbow carries a second XIO feed | not offered by SGI. An enthusiast build adds an Xtown XIO board and a KTOWN to an InfiniteReality2 module and reports the pipe in the PROM and IRIX `hinv` | the O200 Crosstown board and the cabinet: established by two public `hinv -vm` captures. The graphics build: reported (one forum thread), not reproduced |
| Origin 300 | a rear connector labelled XIO, the "Crosstown2 connector" | an InfiniteReality pipeline, "at 800 MB/s in each direction" | established, 007-4365-002 pp1, 8 |
| Onyx 350 | an Origin 350 compute module with the same style of external XIO connector | a graphics module with a Ktown2 board; the capture below shows the pipe behind an IX-brick | Ktown2 behind an IX-brick: established by the capture. That the compute module's connector is the Origin 300 one: inferred, no Onyx 350 manual was read |
| Origin 3000 / Onyx 3000 | C-brick `XIO (II)` Crosstown2 connector to an I-, P- or X-brick (or an N-brick) | a G-brick Ktown2 with two Crosstown2 connectors, one per pipe | established, 007-4240-002 pp125, 135; 007-4264-001 pp2, 17, 20; 007-4264-002 pp10, 39, 60, 62 |

Graphics pipes behind a Ktown: the InfiniteReality family (InfiniteReality, 2, 2E, 3 and 4). The
Onyx2 theory-of-operations figure (007-3439-002 p73) shows GE14 and RM7/TM7 boards behind the
KTOWN. The captures below show GE14-4 with KTOWN part 030-1067, GE16-4 (an InfiniteReality3 pipe)
with the same KTOWN, and GE16-4 with KTOWN2 part 030-1593. So the Ktown generation follows the host
generation, not the pipe generation: an InfiniteReality3 pipe has been seen behind either
(**established** for those captures; nothing was read for an InfiniteReality4 pipe on the older board).
`irsaudit` (below) accepts either part for any pipe. The InfinitePerformance V-brick is not a G-brick: 007-4264-002 p8 says the C-brick connects
to it directly and that an I-brick port can reach a C-brick, G-brick or V-brick. **Established**
that no Ktown2 is mentioned for it; **unknown** whether it uses an XC chip.
The MGRAS, Odyssey and other XIO graphics boards plug straight into an XIO slot and do not use
Crosstown (**inferred**: no manual or capture read ties them to a KTOWN).

### Captures read

- Onyx2 rack, InfiniteReality3, public forum thread "Onyx2: 24CPU: 8 x 500 MHz 16 x 400 MHz 37Gb of
  RAM" (<https://nekonomicon.irixnet.org/forum/14/16285/1.html>): `Location: /hw/module/1/slot/io3/kona`
  with records `GE16-4` (030-1398-001 rev E) and `KTOWN` (030-1067-001 rev F). **Established**
  for that machine; the board numbers are what the one-wire memory reports.
- Origin 200 with GIGAchannel and an InfiniteReality2 module (two public `hinv -vm` listings, a
  vintage wiki page for the Origin 200 and the forum thread "Building an Onyx 200. Success",
  17 June 2012): `/hw/module/1/slot/io1/MotherBoard` lists `XBOX_EXT` (030-1264-001 rev C) beside the
  `IP29` board; the cabinet at `io7/xbox_dualxtown` lists `XBOX_DUALXTOWN` (030-1252-001 rev F);
  the pipe at `io6/kona` lists `GE14-4` (030-1129-002 rev H) and `KTOWN` (030-1067-001 rev F).
  **Established** for those machines.
- Onyx 350 with an IX-brick, public thread "What to do with some lonely O350's?"
  (<https://forums.irixnet.org/thread-3009.html>): the pipe is
  `/hw/module/001c01/IXbrick/xtalk/10` with a `KTOWN2` record (030-1593-001 rev H). A second public
  Origin 3000 capture, "Onyx 3000, 12x600MHz, 6GB, dual-pipe IR3 with HD-GVO", puts the pipe at
  `/hw/module/001c07/Ibrick/xtalk/11` with `KTOWN2` (030-1593-001 rev H). **Established** for those
  machines: the pipe is a Crosstalk widget at port 10 or 11 of an I/O brick. 007-4240-002 p135
  labels the I-brick's two Crosstown2 connectors `XIO 10` and `XIO 11`, which fits those port numbers
  (inferred; the guide does not say the connector label equals the widget number).

## Part numbers

| Part | Name on the board | What it is | Grade and source |
|---|---|---|---|
| 030-1067-001 (rev F seen) | `KTOWN` | graphics-module Crosstown board, Origin2000/Onyx2 generation | established: the one-wire record in two captures; the prefix is in `irsaudit` 6.5.30 only (the 6.5 base `irsaudit` has the `KTOWN` name messages but no part string) and in a shipped graphics header (`sys/SN/SN0/klhwinit_gfx.h`, 6.5.30) |
| 030-1593-001 (rev H seen) | `KTOWN2` | G-brick Ktown2 board | established: two captures; the prefix is in `irsaudit` 6.5.30 offset `0x188968`. The 6.5 base `irsaudit` does not carry it |
| 030-1264-001 (rev C seen) | `XBOX_EXT` | Origin 200 motherboard's Crosstown (extension) board for a GIGAchannel cabinet | established: two captures. A public part list calls it "XBOX extension board, Gigachannel". The prefix is in the IP27 PROM (6.5.30 and 6.5 base) and a shipped header |
| 030-1252-001 (rev F seen) | `XBOX_DUALXTOWN` | the cabinet's XIO interface board (Bridge, four PCI openings, XIO A and XIO B connectors) | established: captures; part list "XBOX XTALK interface". Meaning of "DUAL": inferred (two Crosstown connectors; the cabinet photographs label XIO A and XIO B) |
| 030-1250 | not seen | the Origin 200 expansion cabinet's bridge board (030-1251 is its midplane, 030-1252 its Xtown board) | established as a PROM prefix, with the same board type as 030-1252. Role: the shipped IP27 header groups the three as the cabinet's bridge, midplane and Xtown parts; "backplane" in the community part list is not confirmed |
| 030-0846-001, 030-1280-001 | not seen | Origin 2000 XIO-to-Xtown adapters (host-side XTOWN) | **unknown**: third-party part list only ("XIO to XTOWN adapter"). Neither number appears in any shipped binary or manual read. They are candidates, not facts. Settling test: a second source for either number, such as a one-wire part-number capture from a host-side XTOWN adapter or an SGI parts list; a byte search of the held PROM images and the IP27 and IP30 kernels found neither |
| 030-1213-003, 030-1221-004 | not seen | Xtown to VME 9U and Xtown to VME 6U adapters | **inferred**: the full numbers (with revision suffix) and the 9U and 6U assignment come from the third-party list alone. The IP27 kernel's VME bridge data carries the prefixes `030-1213-` and `030-1221-` next to its "PCI Bridge on XIO-VME board is downrev" message (strings found by byte search; the code that uses them was not read), and the IRIX board name `VME_XTOWN_9U` (below) fits the 9U role. Neither establishes the suffixes or which prefix is 9U |
| 030-1566-002 | not seen | "X brick, Xtown" | third-party part list only: **unknown**. Settling test: as for the two adapters above, a second source for the number (a one-wire capture from an X-brick Xtown board or an SGI parts list); a byte search of the held PROM images and the IP27 and IP30 kernels finds it nowhere |
| 013-1839-001 | not seen | Onyx2 InfiniteReality (deskside) midplane | **unknown** beyond the list: one third-party source, and a byte search of the held PROM images and the IP27 and IP30 kernels finds neither this number nor its prefix. The list describes it as an Onyx2 InfiniteReality midplane, not a Crosstown part |

The third-party list is the community PCA table at <https://happy-yapph.github.io/sgi-pca-numbers/>. It is a
transcription and nothing in it is graded above inferred without a second source.

## What software sees

### Widget identity and where the pipe appears

- **Established.** The graphics pipe, not the converter, is the widget. IRIX registers its pipe
  driver for the Crosstalk widget with part 0xc102 and manufacturer 0x2aa (the XG widget on the
  geometry board; `kona.a` `kona_init`, 6.5.30). OpenBSD's table names the same identity `KONA 0xc102`.
  Neither the Crosstown XTOWN board nor Ktown2 has a widget part of its own in any shipped source or table read.
- **Established** (captures): the pipe appears in the hardware graph at the slot the cable was
  plugged into (`/hw/module/1/slot/io3/kona`), or at the XBridge port of the I/O brick the cable reaches
  (`.../Ibrick/xtalk/11`, `.../IXbrick/xtalk/10`). A host-side Xtown board gets no inventory line of its own
  (none of the Onyx2, Origin 200 or Origin 3000 `hinv -vm` listings above show one).
- **Reported** (one public forum post): in the Origin 200 build the BaseIO XIO feed goes through
  the cabinet's Crossbow and back, so a direct Origin 200 to pipe link was not usable there.
- **Inferred.** The link behaves as a transparent extension of one Crossbow or XBridge port: the
  widget behind the cable answers as if in the slot. The evidence is the missing inventory entry plus the
  widget identity above. The alternative (a widget answering for the board that the one-wire
  memory hides) is unknown; it is covered by the first unknown below.

### The one-wire (NIC) identity records

- **Established** (disassembly, 6.5.30 `kona.a` member `kona_edtinit_hip2.o`; the IP35 archive's copy
  carries the same string). The pipe's identity text (built by `nic_xg_vertex_info` from the XG
  one-wire port at widget offset `0x9c`) is a run of records with `Name:`, `Part:`, `Serial:`, `Group:`,
  `Revision:`, `Capability:`, `Variety:` and `Laser:` fields. The parser, `kona_extract_nic_info`
  (offset `0x69c`, 2104 bytes), compares each record's name against five characters `KTOWN` and, if
  it differs, two characters `GE`. A `KTOWN` match (the five-character compare also accepts `KTOWN2`)
  goes to its own slot, `0x788` bytes into the first argument; a `GE` match goes to a slot at `0x490`;
  every other record is skipped. The two slots hold the same field layout.
- **Inferred:** the first argument is the pipe's board state, so the Ktown record is kept next to the geometry-board record.
  Nothing in `kona.a` reads the Ktown slot back by that displacement. **Unknown:** what, if anything, consumes
  it; `gfxinit` (which `gfxinfo` is a link to, 6.5.30 `usr/gfx`) carries a bare `KT` string at `0x27d18`, in a run of pipe board labels (`RM0`..`RM3`, `TM0`..`TM3`, `BP`, `DG`, `DGOPT`).
  **Established** that the label exists; **inferred** that `gfxinfo -v` prints it for the Ktown record (the print path was not disassembled).
- **Established** (`hinv`, `configmon`, `icrash`, 6.5.30): the `KTOWN` string is in `configmon`
  (`0xa3c80`) and `icrash` (`0x1cf8d8`) and in the `kona` archive (`0x52230`), but not in `hinv`.
  `hinv` holds only the lower-case `xbox_dualxtown` name and a generic board line format (name, barcode,
  part, revision). **Inferred:** any `KTOWN Board: barcode ... part ... rev ...` line comes from the
  board record's own name, not from a string in `hinv`.
- **Established** (`gfxtopology`, 6.5.30, a shipped Perl script): it reads `hinv` output, keeps the
  `KTOWN` record per pipe location and prints it among the pipe's boards. It builds the location
  from the same two path shapes the captures show (`/hw/module/N/slot/ioK` on Onyx2; the brick type, `Ibrick`,
  `IXbrick`, `Xbrick` or `Nbrick`, with an `xtalk/<port>` part on Origin 3000). It does not refuse on a missing Ktown.
- **Established** (`irsaudit`, a shipped InfiniteReality audit program, 6.5 base `0x173da0`-`0x173df0`;
  6.5.30 `0x188958`-`0x18a1b8`): it checks the board's one-wire record. The message
  "NIC part number field must be 030-1067-XXX (KTOWN) or 030-1593-XXX (KTOWN2)" lists the two
  acceptable part families; further messages report the record "not programmed correctly" and print
  family, serial, part and name. The 6.5 base program has the name and "not programmed correctly"
  messages but no part-number check string; the two-family check is in 6.5.30.
- **Inferred:** the Ktown board holds its own one-wire identity memory and shares the pipe's
  one-wire chain with the geometry board. Basis: records appear under the pipe's own `Location`
  line in every capture, and the parser handles both in one pass. **Unknown:** the chain order
  and device family in hardware (the captures print only the family code `0b` for each memory).

### PROM classification of the Origin 200 Crosstown board

**Established** (disassembly, IP27 PROM 6.156 from the 6.5.30 media; the same strings are in the 6.5
base PROM 6.11). The routine at image address `0x1fc41538` (payload mapped at `0x1fc00000`, after
the 4 KB container header) parses a board's identity text record by record and compares each record's
part number against a list of nine-character prefixes. A match sets a board type and a later match overwrites an earlier one:

| Prefix | Board type returned | Meaning | Grade |
|---|---|---|---|
| 030-1250-, 030-1252- | `0x26` | PCI expansion cabinet board | established |
| 030-0734-, 030-1124-, 030-1025-, 030-1244-, 030-1291-, 030-1308-, 030-1389- | `0x21` | base I/O | established |
| 030-1264- | `0x21` | base I/O | established |
| 030-0872-, 030-1243-, 030-1281- | `0x22` | SCSI | established |
| 030-0873- | `0x23` | Ethernet | established |
| 030-0927- | `0x29` | Fibre Channel | established |
| 030-1062- | `0x26` | PCI shoebox | established |
| 030-9999- | `0x2a` | the LINC type (Linux `KLTYPE_LINC`) | established |
| 030-0956- | `0x27` | Linux `KLTYPE_VME` | established |
| 030-0880- | no type returned | sets bit 7 of a flag byte through the caller's pointer; the use of the flag was not traced | established |

The type values and names are the public Linux board types (`asm/sn/klconfig.h`: `KLTYPE_BASEIO` is
`0x21`, `KLTYPE_HAROLD` is `0x26`, `KLCLASS_IO` is `0x20`). The 030-1264 row is the Crosstown fact:
**established** that the PROM folds the Origin 200's Crosstown board into the base I/O board type, not a
separate one, and that in the captures its record (`XBOX_EXT`) arrives on the same hardware-graph
vertex as the `IP29` motherboard record (both under `io1/MotherBoard`). **Inferred:** that the
Crosstown board's identity memory shares the motherboard Bridge's one-wire chain.
**Unknown:** why the PROM treats it as base I/O; the identity of type `0x2a`.

### Names in IRIX's board tables

- **Established.** `hinv` carries the lower-case hardware-graph name `xbox_dualxtown` (6.5.30
  offset `0xc140`); a capture shows the slot vertex named after the board record lowered
  (`/hw/module/1/slot/io7/xbox_dualxtown`).
- **Established.** `configmon` (offsets `0x96ab8`, `0x96b58`) and `icrash` (offsets `0x19bd70`,
  `0x19be10`) carry a `vme_xtown_9u` / `VME_XTOWN_9U` pair in the same lower/upper-case table as
  `xtalk_pci`, `quad_atm`, `fibre_channel`, `hippi_serial`. The name reads as a 9U VME chassis
  behind an Xtown link. **Inferred**: the meaning. **Unknown:** the board's hardware identity records; the only supporting
  evidence is the third-party part list's "XTOWN to VME 9U" (030-1213-003).

### Kernel and PROM have no Crosstown-specific path

**Established** by string search over the whole 6.5.30 media tree (case variants of `xtown`, `crosstown`,
`KTOWN`): in the IP27 and IP35 kernel directories only `kona.a` matches. The two PROMs carry only the
part-number prefixes above. **Inferred** from that absence: no shipped binary has a Crosstown or Xtown
state machine, a link-training routine or an XC register name (strings are not the code; the
kernel's widget probe and the PROM's link bring-up were not traced for this page).

## Registers on the conversion boards

- **Established:** no register of an XC chip, of the XTOWN board, of KTOWN or of Ktown2 is named in a
  manual, header or binary read. Every register that software reaches over the link belongs to the widget
  behind it.
- **Established, on the far end (not on the conversion board):** the pipe's XG widget holds the link
  statistics that the InfiniteReality diagnostics read. `irsaudit` (6.5.30 `0x1b50f0`) prints
  "XTalk LLP Statistics" with the operating LLP size ("8-bit" or "16-bit") and the sequence-number and
  check-bit error counts, and its strings show a clear-and-check test of the transmit, receive and
  retry counters. The register offsets (status word at `0x0c`, control word at `0x24`, error log at
  `0xa4`) come from the diagnostic register table transcribed in the graphics RE repository for the pipe;
  they were not re-read here. These report the cable link as the pipe sees it.
- **Established:** the XTOWN or KTOWN identity memory is the only per-board state read by a driver (the one-wire records above).
- **Unknown:** whether the XC chip has any software-visible state (a lock status, an error latch, a
  loopback bit). Nothing shipped reads one. The test is below.

## Unknowns and the test that settles each

| Unknown | Why it matters | Discriminating test |
|---|---|---|
| Is the host-side XTOWN board electrically transparent, or does it present a widget or an identity memory? | Decides whether anything on the host side must be modelled. | `hinv -vm` and the PROM `hinv -v` of an Onyx2 rack with an XTOWN in a slot, first with the cable attached to a pipe and then with no cable. A board line for the XTOWN, or the Crossbow port reporting a live link with no cable, means it is not transparent. Only existing captures are used; the captures read here show no XTOWN line. |
| Is the first-generation link retimed or only level-shifted at each end? | Decides whether the converters add latency or state. The glossary says the XC chip converts "STL protocol to PECL", which suggests more than levels. | A published XC datasheet or SGI patent, or a measured uncached read round trip through an XTOWN and KTOWN pair against a pipe in a slot of the same Crossbow. |
| Link width and speed in the first generation (8 or 16 bit; clock) | Fixes what the pipe's LLP size bit should report. | Read the XG status word's LLP-size bit on a running Onyx2 pipe (`irsaudit` prints "8-bit" or "16-bit"), or a captured `irsaudit` LLP report. The manual says only that ports are programmable. |
| Does the XC chip have a control or status register? | If yes it is a device to model; if no, the converters are passive. | Compare a Crossbow port and widget register dump of a rack slot holding an XTOWN with the cable attached, against a slot holding an ordinary XIO board; a register that differs is XC state. Without hardware, a PROM or kernel store aimed at an XTOWN slot's address space that no listed widget owns. None was looked for in the code; only strings were searched. |
| What the P-brick and X-brick host interface card does to the Xtown2 link, and whether the brick-side converter is an XC chip or the Xbridge itself | Whether a second-generation converter has state of its own. 007-4311-002 names XC chips; 007-4240-002 p248 calls the Xbridge the "crosstown ASIC". | An X-brick or P-brick `hinv -vm` listing with the host interface card shown as a board, or an L1 `version`/`ioport` capture that names it. |
| How the 800 MB/s or 1.2 GB/s speed is selected | Which register or L1 setting changes the Xtown2 rate. | The L1 `ioport <speed>` command (007-4240-002 p248) writes it. A trace of the L1 firmware's handler (not read here) or the XBridge port speed bits after the command. |
| Part numbers of the host-side XTOWN boards | Needed to name them. | A shipped binary, manual or a captured one-wire record. The part list gives 030-0846-001 and 030-1280-001 as Origin 2000 XIO-to-Xtown adapters. Neither is a fact until a second source names it. |
| Whether `KTOWN` and `KTOWN2` differ in anything software sees | Does a generation check exist anywhere. | Only the name and part prefix are checked, in `irsaudit` and the five-character compare. A binary that compares six characters would be the counterexample; none found. |
| What consumes the stored Ktown record | Whether any user program depends on it. | Search `gfxinit`, `gfxinfo` and the kernel for loads from the Ktown slot offset. `kona.a` has none at the displacement. |
| Whether a direct Origin 200 to pipe link works | Topology of the unsupported Origin 200 graphics build. | A capture of an Origin 200 with a single module and a pipe cabled from the Crosstown board. The only report (one forum post) says the base I/O feed passes through the cabinet's Crossbow, so it does not work. |
| What the letters K and X stand for | Naming only. | A document that expands them. None read does. |

## Corrections and disagreements between sources

- The Origin 300 guide (007-4365-002 p8) says the Crosstown2 connection "is made with a NUMAlink
  3 cable at 800 MB/s". The Origin 3000 guide (007-4240-002 p135) says Crosstown2 ports support 800 MB/s and 1200 MB/s,
  and 007-4311-002 gives the X-brick 800 MB/s and the P-brick 1.2 GB/s. The Onyx 3000 owner's guide (007-4264-001 p2)
  gives the I-brick two 1200 MB/s ports, while the Onyx 3000 graphics systems guide (007-4264-002 p8) gives the same
  brick 800 MB/s ports: two guides for one product disagree, and the software-selectable speed is the likely reconciliation (inferred).
- 007-3439-002 p73 prints "(KTOWN)" after "Crosstown" for the conversion board in a sentence about an XIO slot being occupied, and its figure puts KTOWN on the graphics side. The Onyx2
  rack guide (007-3457-005 pp5, 14) names two boards: XTOWN on the compute side, KTOWN on the graphics side. This page follows the rack guide.
  The manual's single "(KTOWN)" can be read as the whole link.
- 007-4311-002 spells the second-generation channel Xtown2, 007-4240-002 and 007-4365-002 spell it
  Crosstown2, and 007-4264-001 uses Xtown2 for the cable and Ktown2 for the board. All are SGI usage for the
  same thing (007-4311-002 p8).
- The `ktown` row of the [naming audit](interconnect-naming.md) table still reads "inferred / unknown" and
  predates that page's own correction note. Published manuals (007-3439-002 p73, 007-3457-005 pp14, 48) and
  shipped binaries (`irsaudit`, `kona.a`, `configmon`, `icrash`) name it, so it is an SGI term.

## Corrections (2026-11-10)

A checker re-read the page against the primary sources. Six reports, of which six were confirmed (the second
and fifth partly in what they implied, noted below), and one unchecked item was partly confirmed:

- `hinv` does not carry the `KTOWN` string; only `configmon`, `icrash` and the `kona` archive do. Fixed in the
  software section. `hinv` prints whatever name the board record holds.
- The 030-1067 prefix is in the 6.5.30 `irsaudit` only. The 6.5 base program has no part string. The part table
  now says so, which also removes the contradiction with the `irsaudit` bullet.
- XIO equals Crosstalk was graded established on pages that do not say so. Regraded inferred, with the pages
  that define each name and the Hub bandwidth table that labels the port "Crosstalk".
- 030-1250 was called the cabinet's PCI backplane. The shipped header groups it as the cabinet's bridge board
  beside the midplane (030-1251) and the Xtown board (030-1252). Role corrected; the PROM type result is unchanged.
- 007-4240-002 p248 calls the brick-side Xbridge the "crosstown ASIC". Added to the XC discussion and the
  unknowns table; the XC-versus-Xbridge identity of the Xtown2 converter stays unresolved.
- The Onyx 3000 I-brick speed is 1200 MB/s in 007-4264-001 p2 and 800 MB/s in 007-4264-002 p8. The "agree per
  product" wording was wrong; both figures are now stated and listed under disagreements.
- Unchecked item: the `gfxinfo` `KT` claim. `gfxinfo` is a link to `gfxinit`, which holds a `KT` label among
  pipe board labels. The label is established; that it is printed from the Ktown record is inferred.

## Related pages

- [Crosstalk (XIO) link and widget](crosstalk-link.md) for the link layer that Crosstown and Xtown2 carry.
- [Interconnect naming audit](interconnect-naming.md) for the names used here.

## Sources

Manuals (SGI document number, printed pages):

- 007-3439-002, Origin and Onyx2 Theory of Operations: 53, 57-58, 73, 75-76, 84-85, 92-93, 98.
- 007-3457-005, Onyx2 rackmount owner's guide: 5, 8-9, 11-14, 29, 31, 47-48, 52.
- 007-3454-005, Onyx2 deskside owner's guide: 9 (graphics slots).
- 007-4264-001, Onyx 3000 series owner's guide: 2, 4-5, 8, 11, 17, 20-21, 58.
- 007-4264-002, Onyx 3000 series graphics systems guide: 8, 10, 18, 39, 60, 62, 99.
- 007-4240-002, Origin 3000 series owner's guide: 71, 83-84, 125, 135, 248.
- 007-4311-002, Origin 3000 technical guide: 4, 8, 34, 39-40, 43.
- 007-4365-002, Origin 300 owner's guide: 1, 8.
- 007-4377-001, IX-brick owner's guide: 67 (names the Xtown2 XIO ports and the PIC ASICs).
- HMQ-380-C, Hardware Quick-reference Booklet (Origin and Onyx2 Series): "Configuring Xtown on Onyx2 Systems", 130-131 (OCR text; table text is garbled and only the one-pipe-per-node rule is used).

IRIX 6.5.30 media (and 6.5 base where stated), by file: `sbin/hinv`, `usr/sbin/configmon`, `usr/bin/icrash`,
`usr/diags/IR/bin/irsaudit` (also 6.5 base), `usr/gfx/gfxtopology`, `usr/cpu/sysgen/IP27boot/kona.a` and
`IP35boot/kona.a` (member `kona_edtinit_hip2.o`), `usr/cpu/firmware/ip27prom.img` (PROM 6.156; 6.5 base PROM 6.11),
`usr/cpu/firmware/ip35prom.img`, shipped headers `sys/SN/SN0/klhwinit.h` and `klhwinit_gfx.h` (part-number prefixes only).
SHA-256 prefixes: `hinv` `4f430d6c`, `configmon` `10f3629b`, `icrash` `dbf12348`, `irsaudit` 6.5.30 `57830d1c`
and 6.5 base `00f0ddea`, `gfxtopology` `3ece1eb9`, IP27 `kona.a` `0b4e51c8`, IP35 `kona.a` `c2726515`, 6.5.30
`ip27prom.img` `0dbd5d5f`, 6.5 base `ip27prom.img` `2247a76e`.

Public trees: Linux `arch/mips/include/asm/sn/klconfig.h` (board types), OpenBSD `sys/arch/sgi/xbow/xbowdevs` (`KONA 0xc102`).

Public captures: the Onyx2 rack thread (Nekonomicon 16285), "Building an Onyx 200. Success" (Nekonomicon,
17 June 2012), the Higher Intellect vintage wiki page "SGI Origin 200", "What to do with some lonely O350's?"
(irixnet thread 3009), "Onyx 3000, 12x600MHz, 6GB, dual-pipe IR3 with HD-GVO" (Nekonomicon), the community
PCA list (happy-yapph.github.io/sgi-pca-numbers).
