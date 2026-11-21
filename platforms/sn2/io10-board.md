# Altix 350 IO10 base I/O card

Mode: board inventory. No board schematic or parts list is held, so each part below is graded from the manual text, the
SGI option note, or the Linux driver that expects it. The card's place in the PCI riser and the PROM's scan of it are on
[the base I/O page](altix-350-base-io.md). The IO9, which the same slot takes on the earlier machine, is on
[the IO9 board page](io9-board.md).

Labels follow [AGENTS.md](../../AGENTS.md): **established**, **inferred**, **unknown**. A fact about what a public Linux
driver does is established once its file is read; the same driver is only an inferred reading of the hardware.

Sources:

- SGI, *SGI Altix 350 System User's Guide*, `007-4660-002` (later revision, "-002"), printed pages 112 to 115, 119 and 122 (PDF pages 140 to 143,
  147 and 150; printed 112 is PDF 140, printed 115 is PDF 143).
- SGI, *Altix 350 System User's Guide*, `007-4660-001` (2004, "-001"), printed pages 71 and 105 (PDF pages 95 and 129).
  This revision predates the IO10 and names only the IO9.
- SGI, *Important Note: SGI IO10 PCI Option for Altix 350*, `007-4374-001` ("the option note"), page 1 (Figure 1 and the
  guidelines), page 2 (Table 1, the serial pinout) and page 3 (bus speed and the Ethernet interface).
- Linux v2.6.18 (git tag): `drivers/sn/ioc4.c` (`ioc4_variant`), `drivers/serial/ioc4_serial.c`,
  `drivers/ide/pci/sgiioc4.c`, `Documentation/sgi-ioc4.txt`, `drivers/scsi/sata_vsc.c`, `include/linux/pci_ids.h`.

## Short answer

| Question | Answer | Grade |
|---|---|---|
| Card | IO10, the standard base I/O card on the Altix 350 (the later machine). A full-size PCI board in the lowest PCI slot (PCI 1) of a base compute module. | established (`-002` p.112, p.113; option note p.1) |
| Chips on the card | An IOC4 (`10a9:100a`) and a Vitesse VSC 7174 SATA controller (`1725:7174`). No other chip is named by any held document. | IOC4 and VSC 7174 on the IO10: established (the Linux `ioc4_variant` rule in SGI's `ioc4.c` tests an IOC4 and a VSC 7174 together, graded as in the [SN2 README review](README.md)) |
| Ethernet | One RJ-45 port, 10/100/1000 Mbit/s: the option note p.3 says "the Ethernet interface on the IO10 (RJ-45 connector jack) runs at 10/100/1000 Mbits per second" and Figure 1 labels it on the card's bracket; `-002` p.119 lists the base I/O card's autonegotiating Ethernet port. The controller part and its PCI slot are unknown. | port and speed: established (option note p.1 Figure 1, p.3; `-002` p.119); controller: unknown |
| Serial | Four serial ports (S0 to S3) on a 36-pin MDR connector, split to four DB-9 by an optional cable | established (option note p.1 and Table 1, p.2) |
| Disks | One or two internal SATA drives; the card does not drive SCSI internal disks | established (`-002` p.115; option note p.1) |
| DVD-ROM | Needs a base I/O card; the card path to the DVD is not stated | established for the requirement; path unknown |
| RTC, NVRAM, flash | The manual gives NVRAM and a time-of-day clock for the IO9's IOC4 only. Nothing is stated for the IO10 or for flash on either card. | IO10: unknown |
| Revision of the card | not stated in any held document | unknown |

## Parts

| Part | PCI ID | Role on the card | Grade |
|---|---|---|---|
| IOC4 | `10a9:100a` | Serial ports (four), the IDE path, external interrupt; the IOC4 family's serial fit matches the four MDR ports | IOC4 presence on the IO10: established (the IO10 rule is `ioc4_variant`, computed for an IOC4). Which of its blocks reach the card edge: inferred. |
| VSC 7174 | `1725:7174` | Four-port SATA controller for the internal drives and the DVD, if the DVD sits on SATA | established (Linux 2.6.18 `ioc4_variant` tests for this ID on the IOC4's bus at slot 3). Revision and subsystem IDs: unknown. Chip page: [VSC 7174](../../devices/vsc7174/README.md). |
| Ethernet controller | unknown | 10/100/1000 RJ-45 port | port established (option note p.3); controller unknown. The Origin 350 IO9 has a BCM5701; no document says the Altix IO10 does. See the Ethernet section. |
| Serial connector | (36-pin MDR) | S0 to S3, DCD, RXD, TXD, DTR, DSR, RTS, CTS, RI per port | established (option note Table 1) |
| RT interrupt connectors | two, unlabelled on the left edge (option note Figure 1) | Real-time interrupt input and output | established as present; not supported under SGI Linux + ProPack (`-002` p.112; option note p.1) |

No other chip, oscillator, flash part, RTC, EEPROM or power-sequencing part is named by any held source.

## PCI position

- **Slot.** The card sits in PCI slot 1, the lowest of the module's four PCI slots (`-002` p.112 and p.113; option note p.1
  and Figure 1). One card per system module (`-002` p.112; option note p.1). Established. The guide says "lowest base compute module" only of the IO9 (`-002` p.114).
- **Bus.** The base I/O card is in bus 1 of the riser's PIC, slot 1 (the bottom slot). `-002` p.114 states this for the IO9;
  the IO10 section names only "PCI slot 1", so the bus is inferred from the same rule. See the
  [base I/O page](altix-350-base-io.md) for the PIC's two buses.
- **Devices on the card's bus, as Linux expects them.** Linux 2.6.18 picks the IO10 variant when a VSC 7174 is on the same
  bus as the IOC4, at PCI slot 3 (`drivers/sn/ioc4.c`, `ioc4_variant`, lines 254 to 266). Slot 3 is device number 3
  (`PCI_SLOT(devfn) == 3`). The rule is established as SGI's driver rule, not a measurement of a board. The IOC4 sits at device 1 on the bus, by
  the PROM's window rule on the [base I/O page](altix-350-base-io.md#devices-on-the-pics-buses); that placement is
  inferred, not established for the IO10.
- **Interrupts.** The INTx pins the IOC4 and VSC use, and the PIC pin each reaches, are unknown. The Origin 350 IO9 capture
  gives logical interrupt numbers that are not this card's routing (see the [IO9 page](io9-board.md#pci-position)).
- **Riser bus.** The option note and `-001` p.105 describe the riser's connector as "nonstandard" and "connects to the
  IO9 card" (`-001`), and `-002` p.115 says "the system's base I/O card". Whether the IO10 uses the same connector is
  unknown.

## Ethernet

Two held texts agree that the IO10 has a gigabit port:

- The option note says "The Ethernet interface on the IO10 (RJ-45 connector jack) runs at 10/100/1000 Mbits per second"
  and that the connector is the one shown in Appendix A of the Altix 350 user's guide (p.3). Figure 1 (p.1) shows an
  RJ-45 jack on the PCI 1 bracket, labelled "Ethernet port", beside two round connectors (the
  unlabelled RT interrupt pair) and the multi-port serial connector. The figure was viewed as an image.
- `-002` p.119 says the factory-installed base I/O card provides an autonegotiating 10/100/1000 twisted-pair Ethernet
  port, and Table 3-3 (p.122) lists one Ethernet port. The IO10 subsection (pp.112 to 113) does not mention it.

Grade: **established** that the IO10 carries one RJ-45 10/100/1000 port. The controller part, its PCI slot and its
interrupt are **unknown**; nothing held names them, and whether the port sits on a separate controller or on one of the
two chips above is not stated. The PROM types only Broadcom `1644`, `1645` and `16a7` as gigabit Ethernet and ships
only Broadcom's EFI network driver (see [the Ethernet verdict](altix-350-base-io.md#ethernet-verdict)), which makes a
Broadcom Tigon 3 part the likely candidate (inferred, exact device id unknown).

What would settle it: the IO10's parts list or a board photograph with the Ethernet chip's marking, a `lspci -vnn`
capture from an IO10 machine, or the PCI ID the Linux `tg3` driver binds on one.

## Serial and console path

- **Connector.** A 36-pin MDR on the IO10. The optional multi-port cable splits it into four 9-pin serial ports
  (`-002` p.112; option note p.1, which cites the cable's Figure 3). The cable's DB-9 connectors are "RS-232/RS-422
  compatible" (option note p.3). Leave the cable unplugged when unused
  (`-002` p.113). Established.
- **Pinout.** Each port S0 to S3 has DCD, RXD, TXD, DTR, DSR, RTS, CTS and RI, and the pins are grouped with GND at pins
  1, 10, 23 and 32 (option note Table 1). Established.
- **Which port is the console.** Unknown. The manual's console is the module's CONSOLE connector on the interface board,
  the L1 port (`-001` p.53, and the "CONSOLE L1 PORT" label on Figure 1 of the option note). The Linux and IRIX console
  sessions described there start from that system console, not from an IO10 serial port.
- **Linux expectation.** Linux 2.6.18 attaches the serial sub-driver to any IOC4 whose variant is not PCI-RT
  (`drivers/serial/ioc4_serial.c`, line 2787). An IO10 IOC4 therefore has four UARTs in Linux's model. Inferred (driver code established).
- **PROM console.** The PROM's console is not the IO10's serial port on the evidence held. See the
  [base I/O page](altix-350-base-io.md) for the PROM's console selection.

## Drives and DVD

- The IO10 drives one or two internal SATA disks (`-002` p.115). It does not drive SCSI internal disks (`-002` p.112; option
  note p.1). Established.
- The DVD-ROM requires a base I/O card (`-002` p.115). The held text does not say whether the DVD hangs off the VSC 7174's
  port or off the IOC4's IDE channel. Linux 2.6.18 attaches the IDE sub-driver to any non-PCI-RT IOC4 (`drivers/ide/pci/sgiioc4.c`,
  `ioc4_ide_attach_one`), which is an inferred expectation that an IDE channel exists on the IO10, not a statement about
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
  (`drivers/sn/ioc4.c`, lines 236 to 269). Established as driver code.
- The PROM's handling of the IO10's SATA controller is not read here. The base I/O page has the PROM's ID rules.

## Unknown, and what would settle each

- **Ethernet controller part, exact PCI device id and slot.** Settles: the IO10 parts list, a card photograph, or a
  capture from a running IO10 machine.
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
- The `-002` IO10 subsection omits the Ethernet port that the option note and `-002` p.119 give. Recorded above.

## Review

Independent review, 2026-11-21, by a reviewer who wrote none of these pages. Reviewed chips commits bff4d94, b2e30a2 and 80f1819.

Checked against 007-4374-001 (all four pages, Figure 1 viewed as an image), 007-4660-002 pp.112 to 122 and 007-4660-001 pp.71
and 105, and Linux v2.6.18 `ioc4.c`, `ioc4_serial.c`, `sgiioc4.c`, `sata_vsc.c`.

- Serial pinout, MDR connector, disks, slot, RT connectors, `ioc4_variant` rules and the line ranges: confirmed.
- **Fixed.** The Ethernet section said the IO10 text does not mention Ethernet and that wiring and speed were unknown. The option
  note p.3 states the IO10's RJ-45 interface runs at 10/100/1000 Mbit/s, and `-002` p.119 and Table 3-3 list the base I/O
  card's Ethernet port. Figure 1 does show an RJ-45 jack labelled "Ethernet port" on the PCI 1 bracket. The page now says so; the
  controller part stays unknown.
- **Fixed.** "Only in the lowest base compute module" is the guide's wording for the IO9 (p.114), not the IO10.
- **Fixed.** The label set was the six-rating set; chips AGENTS.md defines three, so the page now uses established, inferred,
  unknown. The chip rows follow the SN2 README review's ruling that SGI-written Linux `ioc4.c` facts are established.
