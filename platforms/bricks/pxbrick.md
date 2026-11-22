# PX-brick: Origin 3000 and Onyx 3000 PCI-X I/O enclosure

The PX-brick is the later PCI and PCI-X I/O enclosure for Origin 3000 and Onyx 3000
systems. It holds three PIC chips, two Xtown2 XIO ports, six two-slot buses and twelve
card slots. The addendum names no on-board device. The PIC chip, its registers and the Xtown2 port
speeds are covered in [pic.md](../../devices/pic/facts-outside-census.md), [bridge-family.md](../../devices/bridge/family.md),
[crosstalk-link.md](../../devices/crosstalk/README.md) and `devices/pic/registers.toml`. The PX-brick is not the
Origin 350 compute module, which also carries a PIC. Nothing here moves the Origin 350's
one-PIC topology onto this three-PIC enclosure.

This page holds prose facts only, so there is no generated contract for it. The sibling
enclosure is [ixbrick.md](ixbrick.md). The predecessor is [pbrick.md](pbrick.md).

Grades: **established** (stated in a cited source, or drawn in one), **inferred** (a
reading of software expectations, a sibling platform or a driver constant), **unknown**
(with what would settle it). A figure read as extracted text, not rendered, is noted.

## Sources

- **ADD:** SGI, *PX-Brick Addendum*, `007-4605-001`, copyright 2003, printed pages 1 to 19.
  Figure 2 on p. 3 is the block diagram. Figure 4 on p. 6 is the rear panel.
- **U3900:** SGI, *Origin 3900 Server User's Guide*, `007-4653-001` (October 2003), chapter 5,
  printed pp. 79 to 88. Table 5-1 is on p. 88.
- **ALTIX:** SGI, *Altix 3000 User's Guide*, `007-4579-001` (January 2003), chapter 7,
  printed pp. 125 to 134. Table 7-1 is on p. 134. The Altix guide is for a different
  product line, so each use below carries a transfer caveat.
- **ALTIX-BX2:** SGI, *Altix 3700 Bx2 User's Guide*, `007-4377-002` (November 2004), chapter 7,
  printed pp. 87 to 96. Table 7-1 is on p. 96.
- **L1:** SGI, *L1 and L2 Controller Software User's Guide*, `007-3938-006`, Table 3-1 on
  printed p. 60, and Example 3-60 on pp. 96 and 97. The guide scopes `ioport` to Altix 3000,
  3700 and 3700 Bx2 systems.
- **P-brick:** SGI, *Origin 3000 Series Technical Configuration Owner's Guide*, `007-4311-002`,
  pp. 31 and 32, Figure 3-14. SGI, *Origin 3000 System Architecture*, `108-0240-002`, pp. 2-30
  and 2-31, Figure 2-24, for the predecessor's port labels.
- **IX:** SGI, *IX-Brick Addendum*, `007-4604-001`, Figure 2 on p. 4, for the shared drawing.
- **Linux:** public IA-64 SN headers and drivers in the Linux tree. The value checks below were
  read at torvalds/linux commit `4d856f72c10e`, the commit chips pins as `linux-5.3`.
  Items marked as not re-read cite an older Linux revision that was not checked here.

## Enclosure

Established (ADD pp. 1, 4, 6 to 7, 19): a 4U rack enclosure powered from +48 VDC through a rear
PWR connector. The front panel has an L1 controller with an LCD, an on/off switch with LED,
service-required and failure LEDs, and three hot-swap fans. The rear panel has a power switch
that powers only the L1 (12 VDC LED) and a 48 VDC LED that lights when the rest of the brick
is on. The brick powers on from the front switch, an L2 touch display or the system console.

**Physical size conflicts by source revision, not resolved.** ADD Table 1 (p. 19) gives 7.0 in
(177.8 mm) high, 17.5 in wide, 27.5 in (698.5 mm) deep, 60 lb (27.3 kg) and +48 VDC, with no
power figure. ALTIX Table 7-1, U3900 Table 5-1 and ALTIX-BX2 Table 7-1 give 6.64 in (168.65 mm)
high, 17.5 in wide, 27.74 in (704.59 mm) deep, 60 lb (27.2 kg), and +48 VDC at 225 W. Each is
correct for its own source. The addendum and ALTIX are both 2003, and the addendum has no
month, so which is later is **unknown**. Which table matches a production brick is **unknown**.
The ALTIX IX-brick table (p. 122) carries the same 6.64 in and 27.74 in figures, so the later
values may describe a chassis shared by the I/O bricks. That is **inferred** only. The IX
addendum (`007-4604-001` Table 1, p. 27) gives 6.64 in high and 27.5 in deep, so the two
addenda mix the later height with the addendum depth, so the difference between them is not
cleanly one between dates. [ixbrick.md](ixbrick.md) uses the IX
addendum's figures.

The later manuals add a 21-pin power connector and two 100-pin XIO connectors (U3900 Table 5-2,
ALTIX Table 7-2). The front and rear panel, fan and LED descriptions agree with the addendum.

## Topology

Established (ADD pp. 1 to 3, Figure 2 on p. 3): three PIC ASICs. Two Crosstown2 XIO ports, at
1200 or 800 MB/s, face the host. Twelve card slots form six buses of two slots each, numbered
bus 1 to bus 6, with slots 1 and 2 on each bus.

Established as drawn (ADD Figure 2, p. 3):

| PIC (as drawn) | Buses | Ports labelled in the drawing |
| --- | --- | --- |
| Lower | 1 and 2 | D |
| Middle | 3 and 4 | A, B, C and D |
| Upper | 5 and 6 | D |

- Each bus leaves its PIC through a port labelled F, so each PIC drives two buses.
- The two external Crosstown2 connectors are drawn at ports A and B of the middle PIC.
- Middle port D joins upper port D. Middle port C joins lower port D.
- The drawing shows no link between the upper and lower PICs.
- The drawing has one line between the middle PIC and each outer PIC. Whether that line is one
  link or several is **unknown**.

The later manuals reproduce the same labels (U3900 Figure 5-2, p. 81; ALTIX Figure 7-2;
ALTIX-BX2 Figure 7-2). Those figures were read as extracted text, so the wiring above rests on
the addendum's drawing.

Inferred: the middle PIC is the host-facing node. It takes host traffic on ports A and B and
forwards traffic for the outer buses over its internal ports. No cited source says whether the
PX-brick's middle PIC presents a widget-zero crossbar face, the question [crosstalk-link.md](../../devices/crosstalk/README.md)
raises for PXBOW, so none is assumed here. Whether the upper and lower PICs route and whether they can be reached without the middle PIC are
**unknown**. The three PICs are widgets 12 (lower), 15 (middle) and 13 (upper) on an Altix host (**established as
drawn**, 007-4520-006 pp.38, 52, 54), and the SAL 10.54 table at `0xffc2b2d8` gives the PX type byte `0x23` first buses
1, 5 and 3 for widgets 12, 13 and 15 (established, binary reading; sysco `software/firmware/ix-px-brick-topology.md`).
Whether an Origin 3000 compute brick assigns the same widget numbers is **unknown**.

### L1 evidence on the internal links

Established (L1 pp. 96 and 97, Example 3-60, headed "for the I/O brick (IX and PX)"): `ioport`
prints five items for an I/O brick: `PIC port A speed`, `PIC port B speed`, `PIC0 <-> PIC1 speed`,
`PIC0 <-> PIC2 speed` and `PIC UST clock source: port B`. The two port speeds read "from NVRAM
setting". The command forms are `ioport 400|600`, `ioport a|b 400|600` and `ioport clksrc a|b`.
The example prompt is generic, so it names no brick type beyond the guide's heading.

Inferred: PIC0 is the middle PIC, and the L1 keeps a separate speed for each outer PIC link, which
fits the single line per outer PIC in the drawing. One reported speed can cover several physical
links, so this does not give the link count. The 400 and 600 settings are not tied to the 800 and
1200 MB/s port figures. The meaning of the UST clock source choice is **unknown**.

### Predecessor comparison (does not transfer)

The P-brick drawing (`007-4311-002` Figure 3-14, p. 32) has the same middle-hub shape, with two
parallel links to each outer XBridge. `108-0240-002` Figure 2-24 labels the P-brick's middle
ports: its port C reaches the upper ASIC. The PX-brick drawing sends port C to the lower PIC.
Either the PX-brick halved its internal links or the addendum simplifies them. No cited source
says which, so the link count and port pairing stay **unknown**. The addendum does not say whether
the PX-brick has a P-brick-style host interface card. That is **unknown**.

### Bus-to-PIC mapping (software expectation)

Inferred from the Linux IA-64 SN tree (the I/O brick widget table, `io_brick_tab` in
`arch/ia64/sn/io/sn2/ml_iograph.c`, at the revision the source names; not confirmed at the pinned
commit): the PX-brick entry maps widget `0xc`, `0xd` and `0xf` to PCI buses 1, 5 and 3, with
widget `0xe` and every other widget from 8 to 15 mapped to no bus. That fits three PICs
whose first buses are 1, 5 and 3, and the addendum's bus pairs. The table is a software map for
an Altix host. It gives no head offsets and does not say which widgets an Origin 3000 compute
brick assigns. Those are **unknown**.

## Host attachment

Established (ADD p. 7): the rear panel has two connectors, labelled `XIO 10` and `XIO 11`. Each
can connect the PX-brick to a compute brick. As an option, the second connector can reach a
second compute brick, which makes a dual-ported PX-brick with more bandwidth. Each connector has
two LEDs. Yellow means the PX-brick and the attached brick are both powered. Green means the link
is up.

The later manuals repeat this. U3900 (p. 84) says "node board" where the addendum says "compute
brick", and ALTIX and ALTIX-BX2 use the addendum's wording. Figure 4 of the addendum (p. 6) and the
later rear-panel figures label the connectors `XIO 10` and `XIO 11` but do not say which PIC port
each one reaches.

Unknown: which of `XIO 10` and `XIO 11` reaches PIC port A and which reaches port B. The P-brick
hypothesis (`XIO 10` to port A, `XIO 11` to port B, from `108-0240-002` Figure 2-24) is a named
hypothesis for a later test. It does not carry over. What a single-attached or dual-attached
brick reports, and how the second link is arbitrated, are also **unknown**.

Link speed selection. U3900 (p. 80), ALTIX and ALTIX-BX2 say the 1200 or 800 MB/s setting is
selected with "the L1 controller command XIO" and refer to the L1 guide. The L1 guide has no `xio`
command in its 164 pages. Its `ioport` command sets 400 or 600 per port. Whether `xio` is an older
name for the same setting, a different setting, or a command the later guide dropped is
**unknown**, and so is the mapping between 400 and 600 and 800 and 1200 MB/s. The power-up
setting is also **unknown**.

## PCI and PCI-X buses and slots

Established (ADD pp. 1, 8 to 9): all twelve slots accept PCI or PCI-X cards, 32 or 64 bits wide,
at 33, 66, 100 or 133 MHz. Buses run independently, so different buses can run at different
speeds.

Established (ADD pp. 8 to 9):

- A PCI card and a PCI-X card on one bus force both into PCI mode. Cards of different speeds on
  one bus run at the lower speed.
- Recommended populations per bus: one 133 MHz PCI-X card (runs at 133 MHz), two 133 MHz PCI-X
  cards (run at 100 MHz), two 66 MHz PCI-X, two 66 MHz PCI, or two 33 MHz PCI.
- Changing a bus's mode or speed needs the brick powered off.
- Factory builds spread cards across all six buses.
- Each slot has a power LED and a fault LED (ADD p. 7).

Established for the addendum's date (ADD pp. 9, 11, 18): a PCI or PCI-X card with a certified
driver can be hot-plugged under IRIX by powering one slot with a documented IRIX command. It cannot
be hot-plugged under Linux.

**Hot-plug, conflict by source revision.** The later manuals do not repeat the hot-plug statement.
They say a card install needs the operating system shut down and the brick powered off (U3900
p. 87, and the same sentence in ALTIX and ALTIX-BX2). That is silence, not a contrary claim. The
addendum itself requires shut-down and power-off for cards that are not hot-pluggable and for all
cards under Linux. Only U3900, an IRIX server manual, omits the IRIX path.

Inferred from the Linux IA-64 SN tree (checked at the pinned commit): `sn_pci_bus_valid` in
`drivers/pci/hotplug/sgi_hotplug.c` registers slots only for I/O bricks that support hot-plug, and
its list includes the PX-brick type (`L1_BRICKTYPE_PX`). That code is a software expectation for
Altix systems, not a statement about an Origin 3000 PX-brick. So the brick's hot-plug behaviour is
**unknown** until a test settles it.

Unknown: the per-bus speed and mode strapping and its reset values, the slot-to-IDSEL and
interrupt wiring, 32-bit and 64-bit device behaviour, PCI-X split-transaction behaviour, whether
the PIC description in [pic.md](../../devices/pic/facts-outside-census.md) applies unchanged, and the slot power control path. The addendum
names no on-board device in the PX-brick. A PCI tree from a populated brick, with slot positions,
would settle the wiring and strapping.

## L1 and management

Established (ADD pp. 4, 6): the PX-brick has an L1 controller with a display. It powers on
independently of the rest of the brick through the rear switch and reports status and errors on
the LCD. The addendum refers the reader to the L1 guide.

Established (L1 p. 60, Table 3-1): the brick-letter table lists `c`, `i`, `p`, `r`, `x`, `n` and `g`
with no PX entry.

Inferred from the Linux IA-64 SN headers (checked at the pinned commit):

- The PX-brick is the I/O brick class `KLCLASS_IOBRICK` (`0x70`) plus `0x6`, so `KLTYPE_PXBRICK` is
  `0x76` (`arch/ia64/include/asm/sn/klconfig.h`). `KLCLASS_IOBRICK` is a different class from
  `KLCLASS_IO` (`0x20`), which the base I/O and PCI board types use in [crosstown-ktown.md](../../devices/crosstown-ktown/README.md).
- The module type `MODULE_PXBRICK` is `9` (`arch/ia64/include/asm/sn/module.h`).
- The L1 brick-type response `L1_BRICKTYPE_PX` is `0x23`, the character `#`
  (`arch/ia64/include/asm/sn/l1.h`).

Those are software constants. The L1 brick-type code is what software expects the brick to
answer, and this page cites no capture of a PX-brick's actual reply. The brick's module identifier letter is a
**conflict**. The Altix driver guide's Figure 5-1 (007-4520-006 p.52) draws a PX-brick as module `001#14`. Linux
`format_module_id` (`arch/ia64/sn/kernel/klconflib.c`, v5.3) maps `L1_BRICKTYPE_PX` to `p` (and IX to `i`) and says that is
the character the brick's LCD shows. The figure is a drawing, and the same guide's Figure 2-3 is mislabelled; the Linux
code is a software expectation. Both are graded **inferred**, and what a real LCD shows is **unknown**. The L1 guide's table
has no PX entry, and its `p` is the P-brick.

Unknown: L1 controller revision, board-area data, the real identity reply, request and reply
encodings, how the L1 reaches the compute brick's L1, and the slot-power control path.

### Slot power request codes (not imported)

A Linux IA-64 header, at a revision not re-read here, names `0x2001`, `0x2002` and `0x2003` as
"power up", "power down" and "reset" for a PCI slot or bus. The chips request table
([formats/l1_requests/format.toml](../../formats/l1_requests/format.toml)) already holds `0x2001` as the system-reset request
sent by the Origin 3000 kernel, with an established grade. The two readings disagree about one
value, so neither is imported here. The mapping from these codes to the PX-brick's slot power is
**unknown**.

## InfiniteReality pipe support

Established (ADD p. 1): as an enhancement over the P-brick, the PX-brick "can connect an
InfiniteReality graphics pipe to a compute brick". This is the addendum's only statement of the
feature. U3900 (p. 80) names the target as a Cx-brick, ALTIX (p. 126) as a C-brick, and
ALTIX-BX2 (p. 88) as a CR-brick. None of them gives a connector, card or cable.

Established as drawn (ADD p. 6, Figure 4): the rear panel labels only `PWR`, `XIO 10`, `XIO 11`
and the twelve slots.

Unknown: what hardware carries the pipe, whether the pipe takes one or more of the twelve slots or
a PIC port, which InfiniteReality board set is meant, how the brick presents it to the compute
brick, and which slot or bus it uses. The N-brick and G-brick route in `007-4264-002` p. 9 does not
describe this brick. No InfiniteReality attachment is described, and none may be implied.

## Unknowns summary

| Unknown | What would settle it |
| --- | --- |
| Whether each PIC-to-outer-PIC connection is one link or several; which PIC is PIC0; the UST clock meaning | A PIC port specification, or an L1 `ioport` capture on a populated brick with the link count known |
| Which of `XIO 10` and `XIO 11` reaches PIC port A and which port B | A widget scan from each compute-brick port |
| Which physical-size table matches a production brick | A measured brick |
| Meaning of the `xio` link-speed command, and the power-up speed | An L1 capture that runs `xio`, or a later L1 guide |
| Widget numbers the three PICs take under an Origin 3000 compute brick (12, 13, 15 on Altix), head offsets, and bus-to-slot numbering | A PCI tree from a populated brick |
| Strapping, IDSEL and interrupt wiring; slot power control | A board schematic or a PCI configuration capture |
| Hot-plug behaviour under IRIX and Linux | A test with a certified driver and a documented power command |
| L1 identity reply and request encodings | An L1 console capture from a PX-brick |
| What carries the InfiniteReality pipe | A PX-brick manual page, or a populated Onyx 3000 inventory |
