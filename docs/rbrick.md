# Origin 3000 R-brick

The R-brick is the router enclosure of the Origin 3000 and Onyx 3000 families. It holds one router
ASIC with eight NUMAlink 3 ports, and it joins processor bricks into a larger system. This page records
what the published SGI documents say about it: the enclosure, the port letters and the USB rule, the
router's function, the L1 and management paths, the six-port limit, the routed configurations and what
is still open. It is a product and topology reference. It is not a register contract for the router
chip. The register facts that the shipped firmware and kernel use are in
`devices/router_origin3000_rbrick/registers.toml`, graded inferred.

The Cx-brick's router board carries the same ASIC family, which [the Cx-brick page](cxbrick.md#router-board-and-numalink)
covers. This page does not assume the two boards share a revision. The router register layout the census
found is on the [router unit page](../devices/router_origin3000/registers.md).

## Labels and sources

Each fact carries one of four labels, as elsewhere in this repository. **Established** means a published
manual states it, with the document number, revision and page. **Inferred** means it follows from
established facts, or comes from shipped firmware or kernel code or a public driver header, which show
what software expects and not what the hardware does. **Unknown** names what would settle the question.

Published manuals, all SGI:

- *Origin 3000 Series Technical Configuration Owner's Guide*, `007-4311-002`: R-brick at pp. 36 to 38,
  L1, L2 and L3 at pp. 41 to 43, interconnect drawings at pp. 55 to 58, base bundles at pp. 76 to 80,
  Appendices A to C at pp. 87 to 93.
- *Origin 3000 Series Owner's Guide*, `007-4240-002` (the `-001` revision is cited where noted):
  enclosure and operator view at pp. 14 to 20 and 191 to 197, cabling at pp. 218 to 219, the L1 control
  hierarchy at pp. 70 to 80, the `router` L1 command at pp. 262 to 263.
- *Origin 3000 System Architecture*, `108-0240-002`: pp. 2-18 to 2-25, 2-40 to 2-43, 2-47 and 2-48, 3-2.
- *Origin 3000 Series Service Procedures*, `108-0301-001`: pp. 2-1 to 2-15 and 3-1 to 3-12. Its footer
  marks it confidential. It is cited for the L1 commands and the serial-number rules.
- *Origin 3000 Series Internal Technical Configuration Manual*, `108-0266-001`: pp. 40 to 41 (the crossbar
  and the USB hub), p. 67 (the bisection-bandwidth table) and pp. 69 to 84 (interconnect drawings).
- *Onyx 3000 Series Graphics System Hardware Owner's Guide*, `007-4264-002`: pp. 4, 9 and 17.
- A preliminary cabling guide, `108-xxxx-PR2`, *System Cabling, SGI 3000 Series Systems*. It is marked
  preliminary and has at least one unresolved editor placeholder. Its statements are graded inferred here.
- Public sales material: the Origin 3000 data sheet (p. 4) and the NUMAflex white paper (pp. 8 and 9),
  used only to corroborate product-level facts.
- A public `hinv -vm` listing of a 20-processor Origin 3400, posted in 2009. It is a real-hardware capture
  by someone else, so its inventory lines are graded established. Its port pairing is inferred.

## Identity

- **Established.** One R-brick holds one router ASIC with eight NUMAlink 3 ports. It also holds a power
  board, an L1 controller with a two-line, 12-character display, a USB hub, and two single-speed fans. The
  fans are N+1 redundant, and only SGI support replaces them (`007-4240-002`, pp. 191 to 194;
  `007-4311-002`, p. 36).
- **Established.** It has no processors, memory or I/O. The architecture manual describes the ASIC as an
  arbiter with a crossbar between the ports (`108-0240-002`, pp. 2-19 and 2-21).
- **Established.** It is a 2U brick, 3.35 by 17.38 by 27.5 in, 18 lb, fed +48 Vdc at about 60 W from the
  power bay. It mounts from the front of a 19-inch rack in a fixed position (`007-4311-002`, p. 38 and
  Appendix G, p. 109). The internal configuration manual repeats these figures (`108-0266-001`, p. 41).
- **Conflict, unknown.** The owner's guide lists the height as 3.50 in (`007-4240-002`, p. 225). The
  technical guide and the internal manual give 3.35 in. The earlier `007-4240-001` table prints both 3.35 in
  and 3.3 in in the same cell. A measured brick would settle it.

The same design plays four roles. The role follows placement and cabling, not the board:

| Role | Where used | What its ports do |
|---|---|---|
| Ordinary router | Each group of up to four C-bricks | Four ports to C-bricks, four to other routers (`108-0240-002`, p. 2-23) |
| MetaRouter | Systems above 128 processors | Joins groups of 128 processors. Connects only to other R-bricks (`108-0240-002`, p. 2-24; `007-4240-002`, p. 192) |
| Repeat router | Systems above 256 processors | Joins MetaRouters to routers and to each other. All eight ports can connect to R-bricks (`108-0240-002`, pp. 2-24 and 2-25; `007-4311-002`, p. 36) |
| Six-port router | Origin 3400 only | See the next section |

The owner's guide says an eight-port router "supports up to 32 C-bricks". One router has four C-brick
ports, so that sentence describes a cluster of routers. **Inferred** from the port count.

## Six ports and eight ports

- **Established.** An Origin 3800 needs all eight ports. An Origin 3400 needs six, and its R-bricks have two
  ports disabled so that a system cannot be upgraded or merged illegally. The stated reasons are upgrade
  control and export compliance (`108-0240-002`, p. 2-20). Two six-port routers support at most eight
  C-bricks (`007-4240-002`, p. 191).
- **Established.** Every R-brick has eight router ports. Vendor-shipped R-bricks and router boards come with
  six enabled. The six-port router is the same hardware as the eight-port one with two ports switched off.
  The stated purpose is to stop modifications that would allow illegal installations, upgrades, merges or
  exports (`108-0301-001`, pp. 3-1 and 3-2).
- **Established.** Disabling is done from the L1: the `router 6 port` command, then `router 6 port confirm`.
  Enabling is `router 8 port` with an 18-character authenticator. The authenticator is tied to one brick's
  serial number and expires after 48 hours (`108-0301-001`, pp. 3-3, 3-7, 3-8 and 3-10).
- **Established.** The enabled-port count is non-volatile state set by L1 command. It is not a strap or a
  property of the silicon. Replacing the power board of an eight-port router, or an error that reverts an
  eight-port router to six ports, can leave the ports off until they are re-enabled (`108-0301-001`, p. 3-2).
- **Inferred.** The non-volatile memory is the L1's, since the same manual says it holds the serial numbers
  (`108-0301-001`, p. 2-1).
- **Unknown.** Whether that memory sits on the board the manual calls the power board or on the router board
  that carries the L1. How the L1 makes the ASIC refuse the two ports: an ASIC enable, a routing-table mask
  or a link-training block. What a cable plugged into a disabled port sees.

Which two ports are disabled:

- **Inferred.** The preliminary cabling guide says "router ports 7 and 8 are disabled in the R bricks" for
  Origin 3400 cabling (`108-xxxx-PR2`, p. 2-30). The same paragraph holds an editor placeholder, so the
  statement is graded inferred. The draft's own Origin 3400 tables join routers on ports 1 and 6 only, and
  its 3600 tables add ports 7 and 8.
- **Unknown.** Whether a shipped six-port brick always disables ports 7 and 8, or the L1 chooses them.

Labels in the manuals disagree. The service procedures print the six-port state as `3600 Series 6 port` in
one step and `3400 Series` in the next, and print an enabled eight-port brick as `3800 Series`. The cabling
draft calls its eight-port systems `3600 Series` and its exception list says `3400 Series`. No mapping from
the `Series` text to a product is taken from either document. Whether the text reports the enabled port
count, the product or both is open.

**Board identity.** **Established** from the public listing: both R-bricks report as `ROUTER Board`, part
`030-1634-002`, revision `-B`. The NUMAlink module of the Origin 300 and Origin 350 reports part
`030-1634-003`, revision `-A` (see [the Origin 300 NUMAlink module](origin300-numalink-module.md)). The
shared root and the matching software revision are the only links. IRIX reports `Revision 1` for the router
on both. That is a software label, not a silicon revision. Whether `-002` and `-003` carry the same ASIC
revision and port wiring is unknown.

## NUMAlink 3 ports

The rear panel has eight 100-pin link connectors, lettered A to H and numbered 1 to 8. The letters follow
the numbers in order (`007-4240-002`, pp. 194 to 196; `007-4311-002`, p. 37, Figures 3-18 and 3-19).

| Port | Letter | Carries USB in the cable | Documented use |
|---|---|---|---|
| 1 | A | No | R-brick to R-brick |
| 2 | B | Yes | C-brick, or R-brick in a MetaRouter |
| 3 | C | Yes | C-brick, or R-brick in a MetaRouter |
| 4 | D | Yes | C-brick, or R-brick in a MetaRouter |
| 5 | E | Yes | C-brick, or R-brick in a MetaRouter |
| 6 | F | No | R-brick to R-brick |
| 7 | G | No | R-brick to R-brick |
| 8 | H | No | R-brick to R-brick |

- **Established.** A C-brick connects to port 2, 3, 4 or 5, because only those ports carry the USB signals
  that reach the C-brick's L1 (`007-4311-002`, p. 36; `007-4240-002`, p. 196). Ports 1, 6, 7 and 8 are for
  R-brick to R-brick links only.
- **Established.** R-brick to R-brick links are normally on ports 1, 6, 7 and 8, "however, they are not
  restricted to these four ports". When such a link uses a port that carries USB, the USB signals are
  ignored. A MetaRouter uses all eight ports for R-bricks (`007-4311-002`, p. 36; `007-4240-002`, pp. 196
  and 197).
- **Established.** Each link connector has two LEDs. Green means the cable is connected properly. Yellow
  means packets are crossing the link (`007-4240-002`, p. 196). The signals that drive them are unknown.
- **Established.** A full configuration has four C-bricks per R-brick (`007-4240-002`, p. 191).
- **Established.** The crossbar has seven possible outputs per input. Ports 2 to 5 carry USB and take
  C-bricks, and ports 1, 6, 7 and 8 are R-brick to R-brick only (`108-0266-001`, pp. 40 and 41).
- **Inferred.** A C-brick on port 1, 6, 7 or 8 would have no management path to its L1. The guides do not say
  the link would fail electrically. They say only that the C-bricks "are cabled only to ports 2, 3, 4, and 5"
  (`007-4240-002`, p. 196).
- **Unknown.** Whether port letters, rear numbers and the chip's internal link numbers coincide. Whether a
  C-brick on port 1 passes data and fails only on management.

## Router function

These come from the architecture manual, `108-0240-002`, pp. 2-18 to 2-22. All are **established** as
product description. None is a register contract.

- A message is one or more 128-bit micropackets, each with an 8-bit sideband field. A tail bit marks the last
  one. The header micropacket carries the destination and routing information in its low 23 bits. These are
  a destination ID (one of 512 destinations), a direction field, an age field and a congestion-control field
  that selects the virtual channel.
- There is one static path between any two compute nodes, defined by distributed routing tables. Software can
  steer around a failed component by rewriting the tables.
- Each port has four virtual channels. Requests use channels 0 and 1 and responses use 2 and 3. The odd
  channels prevent deadlock inside a class.
- On entry the ASIC takes the exit port from the header's direction field and arbitrates for it. The age
  field runs from 0 to 240, where a higher value is more urgent, and it rises at a programmable rate while the
  message is inside the brick.
- Routing uses two tables. A register holds the brick's own ID. The low four bits of the destination index the
  local table, which has 16 entries. The upper five bits index the remote table, which has 32 entries. When the
  upper five bits equal the ID register the local table is used, otherwise the remote table is used. A
  remote-table entry names the port the message will use to leave the next R-brick, and the ASIC writes it into
  the direction field. For the local table the manual says only that the entry steers the message to the correct
  destination. **Inferred** that it has the same direction-field meaning.
- The crossbar connects any input to any of seven outputs, not eight. The crosspoint diagram has an empty
  diagonal (`007-4311-002`, pp. 36 and 37). A message never leaves by the port it came in on.
- Vector routing exists for network configuration and administration. A vector-routed message carries its whole
  path and bypasses the tables.
- The link layer uses a CCITT CRC and retransmits on error (`108-0240-002`, p. 2-18). The Bedrock side of the
  link moves 80 bits at 200 MHz and 20 bits at 800 MHz (`108-0240-002`, p. 2-14).

Unknown, and not set by any cited page: the register addresses and widths of the ID register and both tables;
whether a table entry or the direction field names an absolute port or a turn from the ingress port; reset
contents; how destination IDs map to NASIDs; the aging rate; the arbitration policy; credit and retry behaviour;
the vector-routing encoding; error and timeout replies. A public register specification for the fitted ASIC
revision, or a register capture from a matching system, would settle them.

## L1, USB hub and the management path

- **Established.** The R-brick's L1 sits on the router board. It monitors temperature, voltage margins and LEDs,
  reads the serial EEPROMs and drives the front display (`007-4240-002`, p. 194). It has no processor reset or
  NMI switch. Those exist on the C-brick only (`007-4240-002`, p. 75).
- **Established.** The L1 has two RS-232 ports, console and diagnostic. The architecture manual says another
  ASIC inside the brick can connect to the L1 through its serial ports, and names the router ASIC as one of
  them (`108-0240-002`, p. 2-47).
- **Established.** The L1 connects to the USB hub's internal port and reaches the L2 through the hub
  (`108-0240-002`, p. 2-40 and Figure 2-30). The rear L1 PORT carries the hub's upstream link to the L2
  (`007-4240-002`, p. 195; `108-0240-002`, p. 2-42).
- **Established.** The router board carries a USB hub with six master ports. One goes to the R-brick's own L1.
  Four go through the NUMAlink cables on ports 2 to 5 to the L1s of the attached C-bricks. One goes to the L2
  (`108-0240-002`, p. 2-42; `007-4240-002`, p. 73). A C-brick's L1 reaches the L2 only through this hub when an
  R-brick is present. Without an R-brick, a C-brick uses its own L1 USB port (`007-4240-002`, p. 70).
- **Established.** The internal configuration manual adds that the hub fans out the L2's USB to the R-brick's own
  L1 and to the four C-bricks. Each R-brick has a dedicated USB connection to the L2 on a four-pin rear
  connector, so R-bricks do not pass USB to each other (`108-0266-001`, p. 40).
- **Established.** In L1 commands the brick appears as a module such as `001r19`. The digits are the rack, `r`
  is the brick type and the last two digits are the slot. Only L1 index 0, the local brick, is valid for an
  R-brick (`007-4240-002`, pp. 234 and 262 to 269).
- **Established.** The `router` command pair shows or sets the router type: `ordinary`, `meta` or `repeater`,
  with `ord` and `rep` as short forms. It exists on R-bricks only (`007-4240-002`, pp. 262 and 263; the `-001`
  revision lists the same three types).
- **Established.** The meta and repeater types are for eight-port
  bricks. Ordinary is for six- or eight-port bricks. The type can be set regardless of how many ports are enabled,
  and a wrong type may affect system function. A change takes effect at power-up or reset (`108-0301-001`,
  pp. 3-3, 3-8 and 3-11). The report line is `<module>: <N> Series: router type is <type>`. A non-router brick
  answers that the command is not supported on its brick type.
- **Inferred.** Because the type takes effect at reset, something that runs at reset reads it, such as the L1,
  the ASIC setup or the PROM. **Unknown:** what the setting changes in the ASIC or the PROM path. A capture of the
  setting's effect on router status, on a matching brick, would settle it.
- **Established.** The rear panel has a PWR connector to the power bay, a power switch that turns on the L1 (the
  12 Vdc LED), a front On/Off switch that turns on the rest of the brick (the 48 Vdc LED), a circuit breaker
  labelled CB1, and the L1 PORT to the L2 (`007-4240-002`, pp. 194 and 195).

### Power and reset in the stock L1 (inferred)

These come from reading the L1 firmware shipped with a 6.5.30 IRIX release, for the packages that serve the
`R` brick letter. Every row is a software expectation.

- The L1 accepts `power up`, `power up hold`, `power down`, `reset` and `reset hold` from any request source. It
  cannot forward commands to another brick.
- Before every `power up` the L1 runs the serial-number check described below, for R-bricks and I-bricks alike.
  A nonzero value in a particular persistent setting skips the check.
- Two supplies have enable bits on one active-low expander: 48 V and a second supply. `power up` clears them in
  turn, with a wait between them. It then waits, runs a helper for router ports 0 to 5 when two settings allow it,
  and then issues `reset`. The meaning of those two settings was not read. `power down` holds reset and sets the
  enable bits in reverse.
- `reset hold` drives a router-control expander bit and clears a bit of the power expander. Release writes the
  router type first, then, if a supply is on, steps through a few more expander writes. The pins those bits reach
  are unknown.
- At L1 cold start both supplies are off and the brick is held in reset. No automatic power-up task exists for this
  letter. An R-brick at mains stays off until a `power up` request reaches its L1 or its front switch is pressed.
- **Established** (`007-4240-002`, pp. 192 and 195). The owner's guide says the On/Off switch turns on the rest of the
  R-brick.
- **Inferred.** A C-brick's `*` broadcast does not reach an R-brick when there is no L2. The R-brick's L1 opens no
  peer serial link to the C-bricks, and its router has no peer slot. So the R-brick takes `power` and `reset` only from
  its own console or from a USB host, and the L2 is that host. The published configurations always include an L2
  with the tall rack of C-bricks. No published configuration needs `*` to reach a router.

## Serial numbers and the L2

**Power-on serial checks.**

- **Established** (`108-0240-002`, p. 3-2). The R-brick refuses to power on unless the brick serial number in its
  L1 non-volatile memory matches the serial EEPROM, the system serial number has the form `Lnnnnnnn`, the number
  is not the disable value `L9999999`, and it matches the neighbouring bricks. The blank value `L0000000` makes the
  L1 copy a number from a neighbour.
- **Established** (`108-0301-001`, pp. 2-1, 2-2, 2-5 and 2-15). The system serial number is held in the L2's
  non-volatile memory and in each brick's L1. At power-on each brick's copy is compared with the hardware L2's. A
  C-, G-, I-, P- or X-brick whose copy differs adopts the L2's number and powers on. An R-brick whose copy differs
  does not power up until its number matches the L2's and it is reset with a brick-specific authenticator. The
  service text lists five error cases: brick serial mismatch (EEPROM against NVRAM), invalid format, brick disabled
  (`L9999999`), no serial assigned (brick and L2 both `L0000000`), and system serial mismatch (brick NVRAM against
  the L2's).
- **Conflict.** The architecture manual compares with neighbouring bricks, and a blank brick copies a neighbour's
  number. The service procedures compare with the hardware L2, and a blank R-brick takes the number of an L2 that
  holds one. Neither page says which L1 firmware it describes. **Unknown:** which comparison the stock L1 on an
  R-brick runs, and what a single isolated R-brick does.

**The L2 requirement.**

- **Established.** An L2 is optional in an Origin 3200 and standard in every Origin 3400 and 3800. It is **required
  in a rack that holds an R-brick**, and it is also needed for remote maintenance and for a rack display
  (`007-4311-002`, p. 42; `007-4240-002`, p. 75; `108-0240-002`, p. 2-48). Every compute rack of an Origin 3800 needs
  one (`007-4311-002`, Appendix C, p. 93).
- **Established.** The L2 has a four-port USB host controller, one 10/100 Ethernet port, two RS-232 ports, an RS-485
  port for D-bricks and a rack display connector. Its L1 ports connect to the R-bricks (`007-4311-002`, p. 42). The L2
  is a rack-level board, not a chip inside the R-brick.
- **Conflict.** The service procedures describe set-up steps with no hardware L2. They use a computer running L2
  controller software and the L3 software, joined over USB to the R-brick in systems of more than two C-bricks, or to
  the C-brick in smaller ones. The same manual says serial numbers "must be set manually" without a hardware L2, and
  that a system of more than 8 processors needs an L2 system controller (`108-0301-001`, pp. 2-1, 2-2, 2-4, 2-14 and
  3-4). It ties the no-L2 case to an Origin 3200 of eight processors or fewer. It does not say whether software L2
  controller can stand in for the hardware one.
- **Unknown, and the central open question for this brick.** Whether the stock PROM or IRIX needs an L2 to bring up a
  routed Origin 3000, or needs one only to carry management traffic that an unmanaged boot ignores. The guides describe
  supported operation, not boot dependencies. A traced boot of a routed system without an L2, and then with a
  behavioural L2, would settle it.

## Routed configurations

- **Origin 3200.** No R-brick. **Established.** The 3200 reaches eight processors by cabling its two C-bricks directly,
  and "the R-brick is not supported in SGI Origin 3200 systems" (`007-4311-002`, Appendix A, p. 87; `007-4240-002`,
  p. 191).
- **Origin 3400.** **Established.** A tall-rack system of one to eight C-bricks (4 to 32 processors), with two six-port
  R-bricks and a mandatory L2 in its standard bundles. The bundles list two R-bricks at 4, 8, 16 and 32 processors, one
  I-brick with a Fibre Channel PCI card, and one L2 (`007-4311-002`, pp. 76 to 78; `007-4240-002`, p. 191).
- **Origin 3800.** **Established.** Eight-port R-bricks, up to eight C-bricks and three R-bricks per compute rack, 4 to
  128 C-bricks, compute racks that hold only C- and R-bricks, and an I/O rack for the I, P, X and D bricks. The 16- and
  32-processor bundles list two R-bricks and one L2 per compute rack (`007-4311-002`, pp. 79 and 80 and Appendix C,
  p. 93). Above 128 processors the system adds MetaRouters, and above 256 it adds repeat routers (`108-0240-002`,
  pp. 2-24 and 2-25).
- **Onyx 3400 and Onyx 3800.** **Established.** They use R-bricks the same way. The Onyx 3000 guide shows a dual-rack
  system with two G-bricks, four C-bricks, two R-bricks, two I-bricks and an N-brick (`007-4264-002`, p. 17).

### Interconnect drawings

**Established** from the drawings in `007-4311-002`, pp. 55 to 58, and `108-0266-001`, pp. 69 to 84. The counts are
printed as numbers, not as ports.

| Processors | C-bricks | R-bricks | Router-to-router cables | Racks |
|---|---|---|---|---|
| 2 or 4 | 1 | 0 | 0 | 1 |
| 4 to 8 | 2 | 0 | 1 | 1 |
| 8 to 16 | 4 | 1 | 4 | 1 |
| 32 | 8 | 2 | 10 | 1 |
| 64 | 16 | 4 | 24 | 2 |
| 128 | 32 | 8 | 48 | 4 |
| 256 | 64 | 20 | 104 | 8 |

The drawings label routers 19, 27 and 38. **Inferred** that these are rack-unit positions, because the public
listing shows R-bricks at `001r19` and `001r25`. The cabling draft has a unit column and the same reading.

- **Conflict.** The 8-to-16-processor drawing uses one R-brick, but every Origin 3400 bundle from 4 processors up
  ships two. The one-router drawing appears in the generic Origin 3000 figure, which names no product. The cabling draft
  has a 3400 table for one router at 8, 12 and 16 processors. **Unknown:** whether a bundle's second router is redundant
  or required. The orderable bundles are the only configurations tied to a named product.
- **Established** (the drawings and the bandwidth table, `108-0266-001`, p. 67, Table 4-11). At 32 processors the
  standard system joins the two R-bricks with two NUMAlink cables, 6.4 Gbytes/s. A high-bandwidth option uses four
  cables, 12.8 Gbytes/s. The 32-processor bundles list ten 1-metre cables, eight to C-bricks and two between routers
  (`007-4311-002`, pp. 56, 78 and 80).
- **Inferred.** The standard system joins the two routers once on port 1 and once on port 6. The draft's port tables
  agree, but the shipped drawing prints no ports.
- **Established.** The shipped 256-processor drawing has R-bricks at unit 38 in four racks, each drawn with ports 3,
  4, 7 and 8 labelled (`007-4311-002`, p. 58). The draft places these above 128 processors. **Inferred** that no
  smaller system uses the unit-38 slot, because every 32-processor bundle ships two R-bricks and ten cables. **Unknown:**
  whether a one-rack 3800 accepts a MetaRouter-flagged R-brick that reaches only the two rack routers.

### Observed routed system (public listing)

**Established** from a public `hinv -vm` listing of a 20-processor Origin 3400, posted in 2009. It shows five C-bricks
(`001c07`, `001c10`, `001c13`, `001c16` and `001c27`) with 20 R12000 processors and two R-bricks (`001r19` and
`001r25`). Both report `ROUTER Board`, part `030-1634-002`, revision `-B`. The two `ROUTER` software entries read
`Module 001c07/Slot 0, Revision 1, Active Ports [1,2,3,4,5,6]` and `Module 001c27/Slot 0, Revision 1, Active Ports [1,4,6]`.

- **Inferred.** The first router has four C-bricks on ports 2 to 5 and links on ports 1 and 6. The second has one
  C-brick on port 4 and the same two links. This assumes the software's port numbers equal the rear numbers. The two
  links join the same pair of R-bricks, and they pair port 1 with port 1 and port 6 with port 6, as the draft's
  Origin 3400 tables do.
- **Conflict.** The draft's fill order puts a lone C-brick on port 2, not port 4. Three readings fit: the listing's port
  numbers are not the rear numbers, the C-brick was cabled to port 4, or the site did not cable to the draft's pattern.
  Which C-brick sits on which port, and the cable list, are unknown. The listing records no cable ends.
- **Inferred.** IRIX names each router by a C-brick module because the kernel's router record takes the module of the
  node whose setup built it.

### Preliminary cabling draft (inferred)

`108-xxxx-PR2` is a draft. Its statements are graded inferred, and its tables disagree with its figures in places.

- Eight C-bricks (32 processors): both products it draws put C-bricks on ports 2 to 5 only, filled in ascending
  rack-unit order. The draft has no Origin 3800 table below 128 processors.
- Rack routers sit at units 19 and 27. MetaRouters and repeat routers sit at unit 38. The same-port rule applies.
  Ports 1 and 6 join the two routers in a rack. Port 7 goes to the same unit in the adjacent rack. Port 8 goes to the
  same unit two racks away, or to a MetaRouter.
- Between MetaRouters the draft joins ports 1 to 1, 2 to 2, 5 to 5 and 6 to 6. Between a MetaRouter and a repeat
  router it pairs ports 1, 2, 5 and 6 with the repeat router's ports 4 and 8, 1 and 5, 2 and 6, and 3 and 7 as its
  tables give them.
- **Not shipped wiring.** The draft's 128-processor 3800 table has four unit-38 routers and 52 cables. The shipped
  drawing has eight routers and 48 cables. The draft's own figure and table also name different racks.

Where the draft and the shipped drawings disagree, the shipped drawing is the better guide:

| Processors | Draft | Shipped drawing | Status |
|---|---|---|---|
| 32, router cables | four (ports 1, 6, 7, 8) | two by default (ports 1, 6), four as a high-bandwidth option | Use two by default |
| 128, MetaRouters | 12 routers, 52 cables | 8 routers, 48 cables | Use the shipped drawing |
| 160 | 62 cables | 64 cables | Unknown, above 128 processors |
| 192 and 224 | 16 and 18 routers | 14 and 16 routers | Unknown |
| 416 | 184 cables | 204 cables, probably a misprint | Unknown |

The name "3600" appears in no shipped owner's or technical guide. The product lines are the 3200, 3400 and 3800
(`007-4240-002`, p. 15). It does appear in one L2 message in the service procedures (`108-0301-001`, p. 3-11).

### Rack numbering

**Established** (`007-4240-002`, p. 14, Figure 1-6). Compute racks are 001 to 008 in one row and 011 to 018 in a
second. I/O racks are numbered with a hundreds digit of 1, then the quadrant and the position. The shipped figure puts
the first I/O rack at 101.

## Shipped firmware and kernel readings (inferred)

Everything in this section comes from reading shipped firmware and kernel code, or from the public SN1 router header. It
describes what software expects. None of it is a measurement of the chip.

- **Identity.** The firmware asks the router's L1 for its module identity with the letter `R` forced, and for its serial
  number. If the identity query fails, the firmware uses its own node's module identity. If the serial query fails, it
  uses a random number.
- **Lock.** The firmware takes the router lock by reading the set-if-zero alias of scratch register 3, and it releases the
  lock by writing 0 to scratch register 3. Under the lock it writes the module identity to scratch register 1 and the
  serial to scratch register 0.
- **Router type.** Discovery reads the position word, inverts two bits and treats a clear bit as a metarouter or a
  repeat router. The type setting is the L1's persistent setting. Its upper nibble holds `0xf` for an ordinary router,
  `0xe` for a metarouter and `0xc` for a repeat router, and the firmware writes it to a router-control expander at
  reset. How the nibble reaches the PROM's register is inferred.
- **Kernel checks.** The kernel refuses a chip whose part field is not the router part, and it reads the revision from
  the top nibble of the status word. It marks port *p* active when its link-working bit is set. The kernel keeps router
  module identities in a table of at most 128 entries.
- **Hardware graph types.** The kernel's hardware-graph record for a router board uses type `0x31` for a router attached
  to a node, `0x33` for a metarouter, `0x34` for a repeat router and `0x32` for a null router with no component.
  The module field holds the router's module identity and the identity field holds the 48-bit serial.
- **Enabled-port count.** No routine examined reads an enabled-port count. The active-port list comes from the link bits.
  Whether a six-port brick reads as two ports without link bits is inferred.

### Partition fences and reset

- **Protection.** Each link has a reset-permit bit, the low bits of the protection configuration word. A clear bit
  blocks a reset that arrives on that link. Each link also has a reset mask, which the firmware writes at the link's
  address.
- **Link addresses.** The eight reset masks sit at the addresses listed in `devices/router_origin3000_rbrick/registers.toml`. Each
  link's error status word sits 16 bytes below its reset mask. The addresses are not linear in the link number.
- **Fence operation.** The firmware fences a router in two calls. A fence clears the bits of a port mask in the protection
  word and in the reset masks. A clear sets the complement of that mask, so the other bits end up set. It takes the lock
  first and releases it after. A failed access stops the sequence and returns an error. The firmware does not read the registers back to check
  its writes. It relies on each read returning the last value written.
- **Which ports get fenced.** Discovery marks a port whose link is down, and an up port whose permit bit is clear. A
  boundary pass then recomputes the marks of every router in the booting partition. A port with no neighbour, or with a
  node neighbour in another partition, is marked. The fence loop then fences that mask and clears its complement on every
  router in the partition, even when the mask is empty.
- **Warm reset.** The port reset word has a warm-reset bit, bit 9. No shipped software writes it with a constant. A
  node-originated port reset reaches a router as a received warm reset. **Unknown:** who sets the warm bit on hardware, and
  whether an accepted warm reset clears the permit bits and the masks.
- **Reset-mask direction.** The working reading is that bit *p* of mask *n* allows a reset arriving on port *p* to leave
  by port *n*. **Inferred,** from the firmware's combined policy. No specification states it.
- **Port status errors.** The error decoder prints power not applied at the far end for bit 38, output port deadlocked for
  bit 37, received warm reset for bit 36 and received link reset for bit 35. Bits 34 to 32 cover retry timeout, receiver
  overflow and illegal port, in an order the decoder does not settle. The decoder runs on a saved dump, not on a live read.
- **Link state.** The two-bit link state reads 0 for went down, 1 for reset failed, 2 for link up and 3 for not used. The
  routine that chooses the printed message was not traced.
- **Late links.** A port that is down at discovery and comes up later is not explored on that boot. Only a rediscovery
  revisits it, or the next boot does.

### Hub port numbers of the R-brick L1 (unknown)

- The router personality of the R-brick's L1 holds no USB hub port numbering. The L1 is a single USB device behind the hub,
  and nothing in its router code names a hub port for itself, for a C-brick or for the upstream link. Hub port numbers exist on
  the USB host side, which is the L2.
- The L1 lists its eight NUMAlink ports by letter, in rear-panel order. Its port table pairs ports through four expanders:
  H with A, B with C, D with E and F with G (**inferred**). That table is the L1's own numbering for status and control. It is
  not the hub's numbering and not the chip's link numbering.
- The R-brick's L1 opens no serial link to any C-brick's L1. Each C-brick's L1 reaches the L2 through the hub without going
  through the R-brick's L1 (**inferred**).
- **Unknown:** all three hub port numbers (the R-brick's own L1, each C-brick's L1, and the upstream link). The check that
  would settle them is an L2 log that lists the USB path of each attached L1 next to that L1's module identity.

## What is open

The questions that bound this page, each with what would settle it:

- Whether the stock PROM or IRIX needs an L2 to bring up a routed system. A traced boot without an L2, and then with one.
- Whether a six-port brick disables ports 7 and 8 always, and how the L1 makes the ASIC refuse them. A capture of the L1 and
  router status on a six-port brick.
- The register layout of the router ASIC on the fitted revision: the ID register, the routing tables, the port reset word and
  the masks. A public specification for that revision, or a register capture from a matching system.
- Whether an accepted warm reset clears the permit bits and the masks. A read of those registers before and after a warm reset.
- Which serial-number comparison the stock L1 runs, with neighbours or with the L2. Power-on with a blank, a mismatched and a
  disabled serial, with and without an L2.
- What the router-type setting changes in the ASIC or the PROM path. A capture of router status after each type is set, on a
  matching brick, taken at reset.
- The height of the brick, and the second router's role in the 8-to-16-processor bundles. A measured brick, and the bundle's
  own cabling guide.
- The wiring of a real Origin 3800 above 128 processors. A final cabling guide, or an inventory of such a system.
