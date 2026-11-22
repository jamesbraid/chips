# IX-brick: Origin 3000 and Onyx 3000 I/O enclosure

The IX-brick is a 4U I/O enclosure that holds three PIC chips, two Xtown2 XIO
ports, six PCI/PCI-X buses and a base I/O card (IO9). The PIC chip, its registers
and the Xtown2 port speeds are covered in [bridge-family.md](../../devices/bridge/family.md),
[crosstalk-link.md](../../devices/crosstalk/README.md) and `devices/pic/registers.toml`. This page covers what
the enclosure itself carries: slots, the IO9 card, power and management, the USB
card, physical size and the PIC wiring as drawn. It holds no register facts, so
there is no generated contract for it.

Grades: **established** (stated in a cited source, or drawn in one), **inferred**
(from established facts or from a sibling platform), **unknown** (with what would
settle it). The IX-brick is not the Origin 350 compute module, whose hardware graph
also prints `IXbrick`. See [interconnect-naming.md](../../references/interconnect-naming.md).

## Sources

- **IX:** SGI, *IX-Brick Addendum*, `007-4604-001`, printed page numbers.
- **PX:** SGI, *PX-Brick Addendum*, `007-4605-001`, page 3 (the same PIC drawing as IX Figure 2).
- **U3900:** SGI, *Origin 3900 Server User's Guide*, `007-4653-001`, printed pages 67 to 69 (IX chapter) and 80 (PX chapter).
- **ALTIX:** SGI, *Altix 3000 User's Guide*, `007-4579-001`, printed pages 105, 113 to 115, 118, 120 and 126. The IX-brick in this guide sits in an Altix 3000, so every use below carries a transfer caveat for Origin 3000 and Onyx 3000.
- **DRV:** SGI, *Linux Device Driver Programmer's Guide, Porting to SGI Altix Systems*, `007-4520-006`, printed pages 19, 38, 52 and 54 (figures 2-3, 3-1 and 5-1, and the widget numbers). Its figures are drawn for the PX-brick and the IX-brick with BaseIO card; see [the Altix 3000 wiring section](../sn2/altix-3000.md#ix-brick-wiring).
- **ARCH:** SGI, *Origin 3000 System Architecture*, `108-0240-002`, printed pages 2-27 and 2-31, used only for port naming.
- **NG-HINV:** a 2004 public newsgroup post with an Altix `hinv -v` and EFI listing. One user's report, not a capture of a specified machine.

## Enclosure and topology

| Fact | Grade | Source |
| --- | --- | --- |
| 4U enclosure with 12 PCI/PCI-X slot positions, arranged as six two-slot buses. The leftmost position holds a preinstalled IO9, leaving 11 positions for cards. | established | IX pp.1, 2, 10 |
| It serves both Origin 3000 servers and Onyx 3000 graphics systems. | established | IX pp.1-2 |
| It improves on the I-brick by adding PCI-X support, an optional second pair of serial ports and, on Onyx 3000, a preinstalled four-port USB card. | established | IX p.2 |
| Rear connectors are `XIO 10` and `XIO 11`. Each can connect to one compute brick. The second can optionally connect a different compute brick, so the enclosure can be dual-ported. | established | IX p.10 |
| The three PICs sit in the enclosure as drawn: the top PIC beside buses 6 and 5, the middle beside 4 and 3, the bottom beside 2 and 1. | established as drawn | IX p.4 (Figure 2) |
| The middle PIC is the host-facing chip. Its upper Crosstown2 XIO port connects to its port A and its lower one to its port B. | established as drawn | IX p.4; the same drawing in PX p.3, U3900 p.67, ALTIX p.113 |
| Each PIC drives its two buses through two separate lines from its `Port F`. A double-headed link joins the middle PIC's port D to the top PIC's port D, and another joins the middle PIC's port C to the bottom PIC's port D. Each downstream PIC has one link from the middle PIC. | established as drawn | IX p.4 |
| Port A is `XIO 10` and port B is `XIO 11`. | established as drawn for the PX-brick; inferred for the IX-brick | DRV Figure 5-1 (p.52): `XIO link to Port 'A'` over `XIO 10`, and `Port 'B'` over `XIO 11`, on a PX-brick back panel. The IX-brick reading carries that across from the shared PIC drawing (inferred). ARCH pp.2-27 and 2-31 label the ports the same way (not re-read for this change). Which Crosstown2 box is which connector is inferred; see [the Altix 3000 wiring section](../sn2/altix-3000.md#ix-brick-wiring). |

Unknown: what the single `Port F` label means when each PIC drives two bus lines.
The meaning is inferred (see the wiring section above) and no held text defines it.
A cabling test on a real enclosure would settle which Crosstown2 box is `XIO 10`.

## PCI and PCI-X buses

Established (IX pp.11-14):

- Each bus runs at its own frequency, so 133, 100, 66 and 33 MHz cards can share one enclosure.
- A bus carries 32-bit and 64-bit cards together.
- A PCI card and a PCI-X card on one bus both run in PCI mode. Cards of different speeds run at the lower speed.
- Recommended populations per bus: one 133 MHz PCI-X card (runs at 133 MHz), two 133 MHz PCI-X cards (run at 100 MHz), two 66 MHz PCI-X cards, two 66 MHz PCI cards, or two 33 MHz PCI cards.
- Changing a bus's mode or speed requires powering the enclosure off, fitting the card and powering on again.
- Hot-plug of a single slot works only under IRIX, with certified drivers, through a per-slot power command. It is not available under Linux.
- Bus 1 slot 2, beside the IO9, is reserved for the optional serial daughtercard. A card fitted there instead must run at 66 MHz or faster, so it does not slow the IO9's bus.
- Factory builds spread cards across all six buses.

Inferred: bus mode and speed are decided at power-on from the cards present. The
pages say what happens and when, not how the PIC learns it.

Unknown: PCI configuration device numbers per slot and bus, the mapping from bus and
slot to PIC head, INTx wiring from each slot to a PIC interrupt input, and the
host-visible bus numbering. A PCI tree capture from an IX-brick, or a board schematic,
would settle them.

## IO9 base I/O card

Established (IX pp.3, 5, 10, 27):

- One IO9 occupies bus 1 slot 1.
- Connectors: one external 68-pin VHDCI SCSI port, one internal SCSI port for the two front drive bays, one RJ-45 Gigabit Ethernet port, one RTO (output) and one RTI (input) real-time interrupt stereo jack.
- Through a standard daughtercard, two RS-232 DB-9 serial ports on the far right of the rear panel.
- An optional second daughtercard, fitted by a service engineer in bus 1 slot 2, adds two more RS-232 ports and uses no PCI bus resources of that slot.

Established as drawn (IX p.5, Figure 3): the IO9 has three chips. The QLogic block
has two lines, one to the external SCSI connector (labelled 160 MB/s) and one to the
internal port. The BCM5701 is tied to 10/100/1000 Ethernet. The IOC4 block has lines
to both RT jacks, and the four RS-232 lines run from the IOC4 through the two
daughtercards.

Established as drawn (U3900 p.69, Figure 4-3; ALTIX p.115, Figure 6-3): a DVD-ROM
joins the IOC4 block by a line labelled "IDE interface". The addendum's own Figure 3
has no DVD-ROM and no IDE label, so only the two guides show the drive. The Altix guide
calls the drive a CD-ROM in one figure and a DVD-ROM elsewhere. The register-level
behavior of that IDE channel is not shown.

Inferred, from a sibling platform: the QLogic part is an ISP12160 (PCI `1077:1216`).
NG-HINV names "QLogic 12160 Dual Channel Ultra3 SCSI" on an Altix IO9 at `pci01.03.0`,
with the IOC4 at `pci01.01.0` and the BCM5701 at `pci01.04.0`. Its EFI listing shows
the same vendor and device IDs. The 160 MB/s figure and the two-line drawing fit a
dual-channel Ultra160 part. The Altix report is weaker than a capture of this product:
the product revision of the IO9 is unknown, and the Altix report's revision is not
to be copied to this product.

Conflict, not settled: on that Altix IO9 the NG-HINV listing puts the SCSI at device 3
and the Ethernet at device 4 on bus 1. The Origin 350 IO9 capture agrees when its logical
numbers are read with the one-device offset ([the IO9 board page](../sn2/io9-board.md)).
The DRV Figure 2-3 (p.19) labels the Ethernet `Bus 1 Slot 3` and the SCSI `Bus 1 Slot 4`,
the reverse. Both readings stay inferred; see [the Altix 3000 wiring
section](../sn2/altix-3000.md#ix-brick-wiring).

Unknown: the QLogic revision and part for this product; the IOC4, BCM5701 and QLogic
subsystem IDs; which IOC4 pins or functions drive RTI and RTO; whether the DVD-ROM's
IDE link is the IOC4's ATA function. A PCI identification read from an Origin 3000 or
Onyx 3000 IX-brick, its `hinv` or a PROM device listing, or a parts list for the IO9
would settle these.

## Drives, USB and bays

Established:

- Front drive bays: one DVD-ROM drive, and two sled-mounted SCSI disk bays. One disk must go in the rightmost bay (IX pp.6-7, 23-25).
- USB card: a four-port USB card sits in bus 6 slot 2 (IX pp.2-3, 11). It is factory-fitted on Onyx 3000 and optional on Origin 3000. Without it there is no keyboard or mouse path.

## Management and power

Established:

- The L1 controller and its front display live on the IX-brick. The display shows status and error messages (IX p.6).
- The rear power switch powers the L1 controller first, and the 12 V LED lights. The front On/Off switch, an L2 or the system console then powers the rest of the internal components, and the 48 V LED lights (IX pp.7, 9).
- Three hot-swap fans (IX pp.6-7).
- The rear panel has a 48 VDC and a 12 VDC LED.

Unknown: L1 firmware, identity and board-area records, request and reply encodings,
the management address, and the management path to a compute brick through the XIO
cable. Settling them needs an L1 console capture from an IX-brick.

## Physical

Established (IX p.27): 6.64 in high, 17.5 in wide and 27.5 in deep (168.7, 444.5
and 698.5 mm). Weight 65 lb (29.5 kg). Power input +48 VDC on a 21-pin connector.

## Unknowns summary

| Unknown | What would settle it |
| --- | --- |
| Meaning of the single `Port F` label per PIC (inferred); which Crosstown2 box is `XIO 10` (inferred, the upper one) | A published PIC specification, or a cabling test |
| Widget numbers 12, 13 and 15 are established as drawn for the Altix IX-brick; their revisions and reset values are not | A capture from a real IX-brick |
| PCI device numbers of the IOC4, SCSI and Ethernet functions (conflicting readings) | A PCI listing from an IX-brick |
| Head-to-bus-to-slot mapping and INTx wiring | PCI tree capture or board schematic |
| QLogic revision and part for this product; IOC4 and BCM5701 revisions and subsystem IDs | PCI identification read, `hinv`, or an IO9 parts list |
| IOC4 pins or functions that drive RTI and RTO; whether the DVD-ROM's IDE link is the IOC4 ATA function | Board schematic or PCI function listing |
| Default port speed. The overview says 1200 or 800 MB/s (IX p.2) and the port table lists 1.2 GB/s each direction (IX p.27). The L1 `XIO` setting for the IX-brick | A configuration guide for the IX-brick, or an L1 capture |
| L1 identity and protocol | L1 console capture |
