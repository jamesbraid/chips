# Origin 3000 D-brick

The D-brick is the Fibre Channel disk enclosure of the Origin 3000 and Onyx 3000 families. It is
storage on a Fibre Channel arbitrated loop, reached through a host bus adapter in an I-brick or
P-brick. This page records what the published SGI documents say about it: its disk bays, its
loop attachment, its lack of a system controller, and its enclosure services. It is a product
and topology reference, not a register contract. No retained capture of a D-brick's loop (a port
database or an INQUIRY transcript) exists in the sources this repository holds, so every loop
address, enclosure name and bay-to-loop detail below is either printed in a manual or marked
unknown. No register facts were added, so the register maps were not changed.

Each fact carries one of three labels, as in the rest of this repository. **Established** means
a published manual or a public hardware capture states it, with the citation. **Inferred** means
reasoned from established facts. **Unknown** means not settled, with the route that would settle
it.

## Sources

- **Origin 3000 Series Owner's Guide**, `007-4240-002`, chapter 8 (printed pp. 155 to 190) and
  the parts of the same guide cited below for numbering, L1 and L2. Cited as `007-4240-002 p. N`.
- **Onyx 3000 Series Graphics System Owner's Guide**, `007-4264-002`, printed pp. 4, 9, 62, 95,
  128, 134 and 144. Cited as `007-4264-002 p. N`. Its p. 128 is the only published statement
  that the D-brick has an enclosure controller and no L1.
- **Origin 3000 Series Technical Configuration Owner's Guide**, `007-4311-002`, printed pp. 4,
  26 to 27, 42, 48, 51 and 72 to 73. Cited as `007-4311-002 p. N`.
- **Fibre Channel PCI Option Board and XIO Option Board Owner's Guide**, `007-3633-004`, printed
  pp. 2 and 17. Cited as `007-3633-004 p. N`.
- **Origin 3000 Server Series System Architecture**, `108-0240-002`, pp. 2-34 and 2-49. Cited as
  `108-0240-002 p. N`.
- Public `hinv` captures of a QL2200A, described by their disk counts only (see below).

The guides do not name the loop resiliency circuit (LRC) or enclosure-services silicon, so no
public chip datasheet can be matched to them.

Printed page numbers are used throughout. The owner's guides also carry PDF pages that differ by a
fixed offset, so check the printed number against the page header before comparing with a PDF.

## Role and population

**Established** (`007-4240-002 p. 155`; `007-4311-002 pp. 4, 27`; `007-4264-002 p. 9`). The
D-brick adds JBOD (unmanaged disks) storage to Origin 3000 and Onyx 3000 systems. It is optional,
4 U high, rack-mounted and fixed in place.

**Established** (`007-4240-002 pp. 156, 172 to 173`). Twelve bays hold 3.5-inch Fibre Channel disk
modules in a grid four columns wide and three rows high. A fitted brick holds two to twelve disks.
Unused bays take filler modules.

**Established** (`007-4240-002 pp. 155 to 156`). The disks are hot-pluggable and dual-ported.

**Established** (`007-4240-002 pp. 158 to 159`). Each disk module has a green and an amber LED and
an anti-tamper lock that blocks the handle latch. The disk label carries its capacity, serial
number and worldwide name (p. 158). The guide's figures show one 9.17 GB disk. That is a picture
example, not a required model.

**Established** (`007-4240-002 pp. 156, 159, 166, 172 to 173`). Bays are numbered by column and
row: columns 1 to 4 left to right, rows 1 to 3 top to bottom. The disks in bays 1/3 and 4/3, both
bottom corners, must always be present. The guide says they serve "as conduits for information
from the D-brick to the ESI/ops panel module", so the operator-panel firmware needs them.

**Established** (`007-4240-002 pp. 156, 161 to 163`; `007-4264-002 pp. 95, 144`). The rear holds
two 550 W power and cooling modules, one operator-panel module and two FC loop resiliency circuit
(LRC) I/O modules. The brick takes power from a distribution strip over a Y cable and bypasses the
rack power bay.

**Established** (`007-4311-002 pp. 72 to 73`; `007-4240-002 p. 155`). Rack D-bricks are shipped as
factory-configured JBOD. The guides point RAID customers to separate storage products. One
configuration-guide passage (`007-4311-002 p. 26`) mentions RAID inside a rack's D-brick. The two
readings are not reconciled, and no source describes RAID in a D-brick.

## Fibre Channel attachment

**Established** (`007-4240-002 pp. 167 to 168`). Each LRC module has a gigabit interface converter
(GBIC) input, a DB-9 output that can feed the GBIC input of a second D-brick (a daisy chain), a
status LED for each port and an ID range selector with settings 1 to 7. One module is labelled
loop A and the other loop B.

**Established** (`007-4240-002 p. 168`). The selector sets the system ID, and the guide says "Disk
drive IDs are based on this ID". How a setting becomes a loop address is not stated (see Unknown).

**Established** (`007-4240-002 p. 156`). Each LRC "provides input and output connectors to all 12
disk drives".

**Established** (`007-4240-002 p. 168`; `007-4264-002 p. 62`). The GBIC input cables to a host bus
adapter card in an I-brick or P-brick.

**Established** (`007-4311-002 p. 48`; `007-4240-002 p. 156`; `007-4264-002 p. 9`). The twelve
dual-ported disks connect to two loops.

**Established** (`108-0240-002 p. 2-34`). The architecture guide says a D-brick supports two Fibre
Channel loops and is bought from an OEM vendor as a tested unit.

**Established, truncated** (`007-4240-002 p. 168`). The startup description says "each I/O module
controls a separate loop of six drives". The printed sentence ends there with no full stop, and
the next page opens a new heading, so the printed text is cut off at that point. Read with
`007-4240-002 p. 156`, the sentence says an LRC reaches all twelve disks but takes six of them
as its own loop at startup. The guides do not say which six, or whether the split holds after
startup.

**Established** (`007-4311-002 p. 51`; `007-4240-002 p. 32`). The supported Fibre Channel PCI cards
are single-port.

**Inferred.** One single-port adapter reaches one LRC input, so one adapter sees one loop of a
D-brick at a time. A second path to the same disks needs a second adapter on the other LRC. The
first configuration needs one path only.

**Conflict, unknown.** `108-0240-002 p. 2-34` draws one Fibre Channel disk controller card with
both loops leaving it, and each loop passing all twelve drives. `007-4311-002 p. 51` supports only
single-port cards. No source says whether the drawing shows one dual-port card, two cards drawn as
one, or a simplification. Whether the two loops of one brick join one adapter or two is unknown.

**Established** (`007-3633-004 p. 17`). An arbitrated loop allows 126 loop ports plus the fabric
port.

**Established** (`007-3633-004 pp. 2, 17`). One SGI PCI adapter loop controls up to 110 disks, and
SGI supports at most 110 disks in a single rack.

**Established** (`007-4311-002 p. 73`). The configuration guide gives 84 disks per JBOD loop. This
differs from the 110-disk figure above. The two guides do not reconcile the numbers.

**Established, from public captures.** Two public `hinv` captures of a QL2200A (the QLogic PCI
Fibre Channel part, not the XIO board in [xio-fibre-channel.md](xio-fibre-channel.md)) show four
disks in one machine and eleven in another. Neither reports an enclosure device or says which disks
sit in a D-brick. Neither establishes a D-brick.

**Unknown**, and what would settle each:

- how a selector setting from 1 to 7 becomes the loop address of each bay;
- whether each of the twelve bays has a fixed loop address;
- the enclosure's own worldwide names;
- which bays one attached LRC presents on its loop: all twelve, as `007-4240-002 p. 156` reads,
  or the six of the startup split on p. 168;
- which LRC owns which bays at power-on.

A port database or INQUIRY capture from a real D-brick on a QL2200A, or a published specification
for the LRC part, would settle these.

## No system controller

**Established** (`007-4240-002 pp. 69, 72`). The D-brick has no L1 controller. Page 72 says all
bricks except D-bricks have L1 controllers. `007-4264-002 p. 4` repeats the exception.

**Established** (`007-4264-002 p. 128`). The D-brick has an enclosure system interface and operator
panel (ESI/ops) module, with a microcontroller that monitors and controls every element.

**Established** (`007-4240-002 pp. 163, 180`). The ESI/ops microcontroller monitors power, cooling,
temperature and device status over an I2C bus. Each power-supply module carries its own power,
cooling and thermal sensors, and each is monitored independently.

**Established** (`007-4240-002 p. 70`; `007-4264-002 p. 134`). No L2 monitors the D-brick.

**Established** (`007-4240-002 p. 235`). The brick-type table of the L1 command set lists C, I, P,
R, X, N and G, and no D.

**Established** (`007-4240-002 p. 83`). The system-control network figure draws the D-brick's Fibre
Channel link with the legend "no system control signals".

**Inferred.** A D-brick has no module number. Page 13 of `007-4240-002` gives D-bricks a place in
the rack numbering. That is a rack number, and no source gives a D-brick a module number.

**Conflict, unknown.** The L2 rear panel is drawn with an RS-485 port labelled "RS-485 Port to D
Brick" (`007-4311-002 p. 42`), and that guide's text lists one RS-485 port capable of 19.2 Kbaud.
The architecture guide's L2 port table lists one RS-485 port, for ICMB, marked "Not used"
(`108-0240-002 p. 2-49`). The owner's guide labels the same connector "ICMB connector (RS-485)"
(`007-4240-002 p. 76`) and leaves it out of its port table (pp. 80 to 81). No source describes
traffic to a D-brick. Whether the port carries D-brick control is unknown. A photograph of the L2
rear panel or a captured exchange would settle it.

## Operator panel

**Established** (`007-4240-002 pp. 165 to 171, 183, 187 to 190`). The panel has a Run/Service key
switch, a standby button, system, drive, power/cooling and standby LEDs, an audible alarm with a
mute button, and a lamp and alarm test. Standby turns all drives off. Thermal shutdown powers the
brick off ten seconds after the temperature passes a threshold above the thermal alarm's. The
guides document none of these as host-visible.

**Inferred.** Standby and thermal shutdown remove disk power, so the disks drop off the loop. No
source states it.

## Enclosure services

**Established** (`007-4240-002 pp. 166, 180, 187`). The ESI/ops firmware includes SCSI enclosure
services (SES). It monitors the modules and drives the panel LEDs. The guide ties disk fault and
disk identify LED states to the "SES function".

**Inferred.** A host's SES requests might reach the microcontroller through the two conduit disks,
as an extra logical unit or a pass-through on them. An enclosure device at its own loop address
would also fit the guides. Neither is stated.

**Unknown.** The INQUIRY data, device type, address and logical unit of any enclosure service, the
diagnostic pages it implements, whether it accepts control pages, and any vendor-specific format.
A capture of an INQUIRY from a real D-brick, or a public specification for the actual ESI part,
would settle these.

**Established, negative.** The owner's guides present the panel as a local device that the operator
reads. The public `hinv` captures above show disks and no enclosure device. No published IRIX
document found says IRIX queries the D-brick's enclosure services or reads its element status.
That is a statement about what the sources include, not a proof that no guest asks.

**Unknown, not checked here.** Whether an IRIX userland enclosure client ships, and if so which
commands and pages it sends. The shipped IRIX binaries in a local install would settle it by
reading the objects. This page has not done that read.

## Product limits

**Established** (`007-4311-002 pp. 72 to 73`). The configuration guide and the owner's guide both
describe the rack D-brick as a JBOD enclosure. Other storage enclosures, such as the TP9100, are
different products and are not described here.

## What would settle the open items

| Open item | Evidence that would settle it |
| --- | --- |
| Bay population and loop addresses | A port database or INQUIRY capture from a real D-brick on a QL2200A, or a published LRC specification |
| One loop or two per adapter, and which bays each LRC presents | The same capture, read from each LRC in turn, or the LRC specification |
| Enclosure services | An IRIX read of the shipped client, or a published enclosure-services specification for the actual ESI part |
| L2 RS-485 port | A photograph of the L2 rear panel or a captured exchange on that port |
