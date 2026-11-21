# Altix 350 IO10 base I/O card

Mode: board inventory. No board schematic or parts list is held, so each part below is graded from the manual text, the
SGI option note, or the Linux driver that expects it. The card's place in the PCI riser and the PROM's scan of it are on
[the base I/O page](altix-350-base-io.md). The IO9, which the same slot takes on the earlier machine, is on
[the IO9 board page](io9-board.md).

Labels: **established** (a published document states it), **observed** (a measurement on a machine), **software
expectation** (a shipped driver relies on it), **inferred** (reasoned from the above), **approximation**, **unknown**.

Sources:

- SGI, *SGI Altix 350 System User's Guide*, `007-4660-002` (later revision, "-002"), printed pages 112 to 115 (PDF pages 140 to 143;
  printed 112 is PDF 140, printed 115 is PDF 143).
- SGI, *Altix 350 System User's Guide*, `007-4660-001` (2004, "-001"), printed pages 71 and 105 (PDF pages 95 and 129).
  This revision predates the IO10 and names only the IO9.
- SGI, *Important Note: SGI IO10 PCI Option for Altix 350*, `007-4374-001` ("the option note"), page 1 (Figure 1 and the
  guidelines) and page 2 (Table 1, the serial pinout).
- Linux v2.6.18 (git tag): `drivers/sn/ioc4.c` (`ioc4_variant`), `drivers/serial/ioc4_serial.c`,
  `drivers/ide/pci/sgiioc4.c`, `Documentation/sgi-ioc4.txt`, `drivers/scsi/sata_vsc.c`, `include/linux/pci_ids.h`.

## Short answer

| Question | Answer | Grade |
|---|---|---|
| Card | IO10, the standard base I/O card on the Altix 350 (the later machine). A full-size PCI board in the lowest PCI slot of the lowest base module. | established (`-002` p.112, p.113; option note p.1) |
| Chips on the card | An IOC4 (`10a9:100a`) and a Vitesse VSC 7174 SATA controller (`1725:7174`). No other chip is named by any held document. | IOC4 on the IO10: inferred; VSC 7174 on the IO10: software expectation (see below) |
| Ethernet | The option note's Figure 1 labels an "Ethernet port" on the IO10 board. The `-002` IO10 text does not mention Ethernet. The controller part, its speed and its slot are unknown. | established as a figure label; controller unknown |
| Serial | Four serial ports (S0 to S3) on a 36-pin MDR connector, split to four DB-9 by an optional cable | established (option note p.1 and Table 1, p.2) |
| Disks | One or two internal SATA drives; the card does not drive SCSI internal disks | established (`-002` p.115; option note p.1) |
| DVD-ROM | Needs a base I/O card; the card path to the DVD is not stated | established for the requirement; path unknown |
| RTC, NVRAM, flash | The manual gives NVRAM and a time-of-day clock for the IO9's IOC4 only. Nothing is stated for the IO10 or for flash on either card. | IO10: unknown |
| Revision of the card | not stated in any held document | unknown |

## Parts

| Part | PCI ID | Role on the card | Grade |
|---|---|---|---|
| IOC4 | `10a9:100a` | Serial ports (four), the IDE path, external interrupt; the IOC4 family's serial fit matches the four MDR ports | IOC4 presence on the IO10: inferred. The Linux IO10 rule (below) names no IOC4 directly. |
| VSC 7174 | `1725:7174` | Four-port SATA controller for the internal drives and the DVD, if the DVD sits on SATA | software expectation (Linux 2.6.18 `ioc4_variant` tests for this ID on the IOC4's bus at slot 3). Physical identity on a card: unknown. Chip page: [VSC 7174](../../devices/vsc7174/README.md). |
| Ethernet controller | unknown | 10/100/1000 port on the figure | unknown. The IO9 has a BCM5701; no document says the IO10 does. See the Ethernet section. |
| Serial connector | (36-pin MDR) | S0 to S3, DCD, RXD, TXD, DTR, DSR, RTS, CTS, RI per port | established (option note Table 1) |
| RT interrupt connectors | two, unlabelled on the left edge (option note Figure 1) | Real-time interrupt input and output | established as present; not supported under SGI Linux + ProPack (`-002` p.112; option note p.1) |

No other chip, oscillator, flash part, RTC, EEPROM or power-sequencing part is named by any held source.

## PCI position

- **Slot.** The card sits in PCI slot 1, the lowest of the module's four PCI slots (`-002` p.112 and p.113; option note p.1
  and Figure 1). One card per module, only in the lowest base compute module (`-002` p.112). Established.
- **Bus.** The base I/O card is in bus 1 of the riser's PIC, slot 1 (the bottom slot). `-002` p.114 states this for the IO9;
  the IO10 section names only "PCI slot 1", so the bus is inferred from the same rule. See the
  [base I/O page](altix-350-base-io.md) for the PIC's two buses.
- **Devices on the card's bus, as Linux expects them.** Linux 2.6.18 picks the IO10 variant when a VSC 7174 is on the same
  bus as the IOC4, at PCI slot 3 (`drivers/sn/ioc4.c`, `ioc4_variant`, lines 254 to 266). Slot 3 is device number 3
  (`PCI_SLOT(devfn) == 3`). This is a software expectation, not a board fact. The IOC4 sits at device 1 on the bus, by
  the PROM's window rule on the [base I/O page](altix-350-base-io.md#devices-on-the-pics-buses); that placement is
  inferred, not established for the IO10.
- **Interrupts.** The INTx pins the IOC4 and VSC use, and the PIC pin each reaches, are unknown. The Origin 350 IO9 capture
  gives logical interrupt numbers that are not this card's routing (see the [IO9 page](io9-board.md#pci-position)).
- **Riser bus.** The option note and `-001` p.105 describe the riser's connector as "nonstandard" and "connects to the
  IO9 card" (`-001`), and `-002` p.115 says "the system's base I/O card". Whether the IO10 uses the same connector is
  unknown.

## Ethernet

Two held documents disagree in coverage, not in fact:

- `-002` p.112 and p.113 list the IO10's external connectors in prose: the 36-pin MDR serial connector and the optional
  cable. No Ethernet is listed. The same revision lists a 10/100/1000BaseT connector for the IO9 (p.114).
- The option note's Figure 1 carries an "Ethernet port" label beside the IO10 PCI card (the figure's text layer; the
  image itself was not viewed).

Grade: **established** that the option note's figure labels an Ethernet port on the IO10, **unknown** whether that port is
wired on production cards, its speed, and its controller. Nothing held names a controller for it. The existing base I/O
page lists the IO10 with an Ethernet port and an unknown part, which matches this.

What would settle it: the IO10's parts list or a board photograph with the Ethernet chip's marking, a `lspci -vnn`
capture from an IO10 machine showing the device and its vendor ID, or the Linux `drivers/net` entry that binds to it.

## Serial and console path

- **Connector.** A 36-pin MDR on the IO10. The optional multi-port cable splits it into four 9-pin serial ports
  (`-002` p.112; option note p.1, which cites the cable's Figure 3). Leave the cable unplugged when unused
  (`-002` p.113). Established.
- **Pinout.** Each port S0 to S3 has DCD, RXD, TXD, DTR, DSR, RTS, CTS and RI, and the pins are grouped with GND at pins
  1, 10, 23 and 32 (option note Table 1). Established.
- **Which port is the console.** Unknown. The manual's console is the module's CONSOLE connector on the interface board,
  the L1 port (`-001` p.53, and the "CONSOLE L1 PORT" label on Figure 1 of the option note). The Linux and IRIX console
  sessions described there start from that system console, not from an IO10 serial port.
- **Linux expectation.** Linux 2.6.18 attaches the serial sub-driver to any IOC4 whose variant is not PCI-RT
  (`drivers/serial/ioc4_serial.c`, line 2787). An IO10 IOC4 therefore has four UARTs in Linux's model. Software
  expectation.
- **PROM console.** The PROM's console is not the IO10's serial port on the evidence held. See the
  [base I/O page](altix-350-base-io.md) for the PROM's console selection.

## Drives and DVD

- The IO10 drives one or two internal SATA disks (`-002` p.115). It does not drive SCSI internal disks (`-002` p.112; option
  note p.1). Established.
- The DVD-ROM requires a base I/O card (`-002` p.115). The held text does not say whether the DVD hangs off the VSC 7174's
  port or off the IOC4's IDE channel. Linux 2.6.18 attaches the IDE sub-driver to any non-PCI-RT IOC4 (`drivers/ide/pci/sgiioc4.c`,
  `ioc4_ide_attach_one`), which is a software expectation that an IDE channel exists on the IO10, not a statement about
  the DVD's wiring. Path: **unknown**.

## RTC, NVRAM and flash

- The `-002` text gives NVRAM and a time-of-day clock as features of the IO9 card's IOC4 (p.114). It gives nothing for the
  IO10. Whether the IO10's IOC4 has them, and whether the Altix 350 keeps its time on the card or on the L1, is **unknown**.
- Linux 2.6.18 has no consumer of an IOC4 NVRAM or time-of-day block: a search of the IOC4 users (`drivers/sn/`,
  `drivers/serial/`, `drivers/ide/pci/`, `include/linux/ioc4.h`, and every other file that names IOC4 in that tree) finds
  none. That is a negative result about this software, not evidence that the hardware lacks the block.
- No flash part is named for either card. **Unknown.**
- The L1 controller on the interface board stores identification and configuration information (`-001` p.105, for the CPU
  module). Whether the IO10's identity comes from the L1 or from the card is covered on the
  [base I/O page](altix-350-base-io.md).

## Linux and PROM expectations

- Linux 2.6.18 `ioc4_variant` returns the IO10 variant only when no ISP 12160 is found on the bus at slot 3 and a VSC 7174 is
  (`drivers/sn/ioc4.c`, lines 236 to 269). Software expectation.
- The PROM's handling of the IO10's SATA controller is not read here. The base I/O page has the PROM's ID rules.

## Unknown, and what would settle each

- **Ethernet controller part, speed, slot and whether it is wired on production cards.** Settles: the IO10 parts list,
  a card photograph, or a capture from a running IO10 machine.
- **IO10 chip revisions** (IOC4 and VSC 7174). Settles: `lspci -vnn` from an IO10 machine, or the chips' own documents.
- **INTx routing for the IOC4, VSC and any Ethernet part**, and the PIC pins they reach. Settles: a PIC routing capture on an
  IO10 machine, or the PROM's interrupt code for the IO10 read under the base I/O page's method.
- **Which serial port is the PROM's and the Linux console.** Settles: a console capture on an IO10 machine with the
  multi-port cable, or the PROM's console selector read on the [base I/O page](altix-350-base-io.md).
- **Whether the DVD is on SATA or IDE**, and whether the IO10's IOC4 has NVRAM and a time-of-day clock. Settles: the
  IO10 schematic, or a capture of the IDE and RTC accesses on a running machine.
- **Flash part on the card, if any.** Settles: a parts list or a board photograph.
- **Card revision.** Settles: the label on the card, or the production record.

## Discrepancies found while writing this page

- `-001` (2004) predates the IO10 and names only the IO9 for the riser connector and the DVD. `-002` adds the IO10. Read
  the two revisions together; the IO10 text is only in `-002` and the option note.
- `-002` IO10 text omits the Ethernet port that the option note's figure labels. Recorded above.
