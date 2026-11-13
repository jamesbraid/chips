# Onyx 3000 G-brick: enclosure, pipe board sets and L1

The G-brick is the graphics enclosure of the Onyx 3000 family. It holds one or two InfiniteReality
pipes, the Ktown2 board that takes their cables, a midplane, a power supply and an L1 controller. It
has no processors and no memory. This page records what the manuals say about the enclosure, the
board sets that fill a pipe, the raster manager counts and the brick's management. The pipe's
Crosstalk identity, the Ktown2 board and the cabling from a C-brick are in
[onyx3000-graphics-topology.md](graphics-topology.md) and [crosstown-ktown.md](../../devices/crosstown-ktown/README.md),
and are not repeated here.

No register of the G-brick or its Ktown2 is named in any source read, so `devices/` has no register map for it.

Each fact carries one label. **Established** means the cited page states it, or the cited capture
shows it, for that capture only. **Inferred** means it follows from cited pages, and none of them says
it. **Unknown** means the sources do not settle it. The open items are listed in
[open-questions.md](../../questions/README.md).

## Sources

- SGI, *Onyx 3000 Series Graphics System Hardware Owner's Guide*, 007-4264-002, November 2001. Cited
  as the graphics guide.
- SGI, *Origin 3000 System Architecture*, 108-0240-002. Cited as the architecture manual, by printed
  page (2-nn for chapter 2). Its page legend reads "SGI Confidential"; [bedrock-io-interface.md](../../devices/bedrock_ii/README.md)
  already cites it.
- SGI, *InfiniteReality4 Addendum to Silicon Graphics Onyx2, SGI Onyx 3000 Series, and SGI Onyx 300
  Guides*, 007-4525-001, 2002. Cited as the IR4 addendum.
- SGI, *Onyx 300 Graphics System User's Guide*, 007-4509-002. Cited as the Onyx 300 guide.
- Public IRIX forum captures of an Onyx 350 with InfiniteReality4 (`gfxinfo`, plain, `-v` and `-vv`,
  posted 2021). Thread addresses were not recorded at import.

The page numbers below are the ones recorded when these facts were imported. The manuals were not
reopened for this page.

## Enclosure

- **Established** (graphics guide pp. 10, 35): the G-brick is an 18U brick. A system has G-bricks or
  V-bricks, not both (pp. 10, 63).
- **Established** (pp. 10, 39): one G-brick holds one or two pipes. A pipe is a geometry board (GE), one or
  more raster managers (RM) and a display generator (DG).
- **Established** (p. 39): the rear has 11 board slots. Ktown2 takes one, pipe 0 takes six on the right
  as seen from the rear, and pipe 1 takes four on the left.
- **Established** (p. 43): the DG is always the rightmost slot of its pipe.
- **Established** (pp. 39, 62; Onyx 300 guide p. 13): Ktown2 sits between the two pipes. Its top
  connector serves pipe 0 and its bottom connector serves pipe 1. Each connector is one Crosstown2
  connection.
- **Established** (p. 39): the G-brick plugs straight into 220 V and does not use the power bay. Its
  power switch brings up the L1 first. The on/off button then powers the boards.
- **Established** (p. 42, Figure 2-5): the midplane carries the boards, the L1, a USB connection to the
  L1, fan power and a power busbar.

## Cabling to the C-brick

The Ktown2 connectors reach a C-brick only through an I-, X- or N-brick. The C-brick reaches a V-brick
directly. These points are in [onyx3000-graphics-topology.md](graphics-topology.md), question 1.
Three points here are not:

- **Established** for the one-pipe case (graphics guide p. 15, Figure 1-4): the Ktown2 connector goes to
  an I-brick XIO port, and the brick's other port goes to the C-brick.
- **Established** for the two-pipe figure (graphics guide p. 16, Figure 1-5): pipe 0 goes to an I-brick
  port and pipe 1 goes to an X-brick port. Each of those bricks' other port goes to its own C-brick.
  Whether every two-pipe system splits its pipes this way, or two pipes may share one intermediary, is
  **unknown**.
- **Established** (graphics guide pp. 9, 58 to 60, 64, 68): an N-brick has four C-brick connectors and four
  pipe connectors. It takes up to four C-bricks and serves up to four pipes. Its rear panel labels the
  C-brick connectors 0 to 3 and the pipe connectors 0 to 3 (pp. 59 to 60). It is usable only with
  InfiniteReality pipes. Its pipes can sit in up to four G-bricks: two pipes in each of two G-bricks
  (p. 58), or one pipe in each of three G-bricks behind one N-brick (Figure 3-5, p. 68). Whether C-brick
  *n* serves pipe *n* inside the N-brick is **unknown**.

## Pipe board sets

### InfiniteReality3, the default set

- **Established** (architecture manual p. 2-38; Onyx 300 guide p. 12): each pipe has one Ktown2
  connection, one GE16-4, RM10 boards and one DG5. The Onyx 300 guide gives an RM9 for the IR2 set.
- **Established** (architecture manual p. 2-38; IR4 addendum p. 4): each RM10 board has 256 MB of texture
  memory. The addendum gives 80 MB of raster memory for IR3.
- **Established** for the rack capture: the Onyx2 rack capture reports the IR3 raster manager part
  `030-1402-001` and texture part `030-1588-001`, and the GE16-4 part `030-1398-001`.
- **Established** (graphics guide p. 43, Table 2-1): the DG5 comes as DG5-2 (two monitor outputs),
  DG5-8 (eight outputs, through a VIO5H daughterboard), DG5-2 with GVO, DG5-2 with TVO (HD-GVO) and
  DG5-2 with DPLEX. The output count does not decide the board's host-visible identity.
- **Established** (architecture manual p. 2-38): the G-brick also accepts the older InfiniteReality and
  InfiniteReality2 board sets. No source says how they pair with Ktown2, so that is **unknown**.

### InfiniteReality4

- **Established** (IR4 addendum pp. 3 to 4): an IR4 pipe is a GE16-4, a DG5 of at least two channels
  (DG5-2) and the RM11. It sits in the same enclosure, with the same Ktown2 between the pipes. Compared
  with IR3, texture memory per RM11 board grows from 256 MB to 1024 MB and raster memory per board from
  80 MB to 2.5 GB. Upgrading is done at the pipe-component level and needs IRIX 6.5.17 or later.
- **Inferred**: the addendum's 1024 MB figure is per RM11 board, as the IR3 figure is per RM10 board. So a
  pipe's texture total is the board count times 1024 MB. That product is not printed in any source.
- **Established for the Onyx 350 captures** (another topology, behind a Ktown2 on the Onyx 350):

  | Report | RM11 boards | Texture per board | Chip words |
  | --- | --- | --- | --- |
  | `gfxinfo` | 1 | 1024 MB | no |
  | `gfxinfo -v` | 2 | 1024 MB each | yes |
  | `gfxinfo -vv` | 4 | 1024 MB each | yes, with board name, revision and group |

  All three name the pipe KONAD with four GEs and a TVO option. The `-v` and `-vv` reports list the
  parts DG5 `030-1242-001`, GE16-4 `030-1398-002` rev B, Ktown2 `030-1593-001` rev H, texture
  `030-1650-004` and RM `030-1651-004`. The `-vv` report adds `030-1651-005` and `030-1650-005` on RM2.
  In `-vv` every RM identity record is named RM10, including the RM2 part, though the header calls the
  boards RM11. The record name therefore cannot tell RM10 from RM11.
- **Inferred**: one pipe was repopulated from two RM11 boards to four between the captures. Why the
  TVO capture shows one RM is **unknown**.
- **Unknown**: whether an IR3 and an IR4 pipe can share one G-brick, or share one pipe's boards. The
  addendum describes mixing only as a pipe-component upgrade.

### Raster manager counts per pipe

- **Established** (graphics guide p. 40, Figure 2-3; p. 39; Onyx 300 guide p. 15; IR4 addendum p. 3):
  pipe 0, on the right with six slots, takes one, two or four RMs. Pipe 1, on the left with four slots,
  takes one or two. Figure 2-3 labels pipe 0 with four RMs and pipe 1 with two. With four slots, pipe 1
  cannot hold four RMs.
- **Established as printed, conflicting** (architecture manual p. 2-38; graphics guide p. 10): these
  two say the first pipe takes one or two RMs and the second takes up to four. They do not tie "first"
  to a slot position. **Inferred**: they number the pipes the other way round from the slot rule above.
  A two-pipe `gfxinfo` with the RM count per pipe would settle it.

## L1 and management

- **Established** (graphics guide pp. 35 to 36, 129 to 130): the L1 has a two-line, 12-character display,
  an on/off switch, and service and failure LEDs.
- **Established** (graphics guide p. 129): the L1 logic is SRAM, NVRAM, flash, an MCU, an I2C bus, an ID
  EEPROM and a USB port.
- **Established** (architecture manual p. 2-40): the G-brick L1 reaches the L2 controller over USB. It
  shares the L1 family of the C-, R-, I-, P- and X-brick.
- **Established as printed** (graphics guide, configuration pages 63 to 68): every documented G-brick
  configuration includes an L2. A single rack connects the L1 to the L2's L1 port directly. A multirack
  system with two or more G-bricks goes through a USB hub. The page for the hub is not recorded at
  import.
- **Established** (graphics guide p. 127): the L2 is optional in an Onyx 3200 in a short rack and standard
  in tall racks with C-bricks.
- **Conflicting** (graphics guide Table 6-1, pp. 128 to 129; architecture manual Table 2-2, p. 2-42). Table
  6-1 says the G-brick L1 monitors voltage, controls fan speed, drives the LEDs and watches the on/off
  switch. It does not margin voltages, monitor temperature or the 48 V input, read ID PROMs, or watch
  the reset and NMI switches. Table 2-2 marks the G-brick for voltage margining, temperature and
  input-power monitoring, and ID PROM reads, and leaves VRM control and the reset and NMI switches
  unmarked. The two tables disagree on three G-brick rows: voltage margining, temperature and
  input-power monitoring, and ID PROM reads. Each is **unknown** for the G-brick.
- **Established as printed** (architecture manual p. 2-41, Figure 2-30): the Crosstown2 cable carries RS-422
  signals for the L1 links of I/O bricks to C-bricks. The same chapter shows the G-brick L1 linked to the
  L2 over USB. It shows no G-brick-to-I/O-brick management link, so whether one exists is **unknown**.
- **Unknown**: the G-brick L1's revision, brick type string, serial and module addressing, request and
  reply encoding, how USB enumerates it, and whether a Crosstown2 cable carries management signals for
  a pipe. How the G-brick L1 is managed in an Onyx 3200 with no L2 is also **unknown**.

The common L1 protocol is in [devices/l1/README.md](../../devices/l1/README.md).
