# Altix 350 IO9 base I/O card

Mode: board inventory. No IO9 schematic or parts list is held. The IO9 is the base I/O card of the earlier Altix 350 and the
standard card of the Origin 350 (a different product, with its own board). Chip facts that transfer are graded here;
topology and interrupt routing that do not transfer are marked as such. The card's slot and the PROM's scan are on
[the base I/O page](altix-350-base-io.md). The later IO10 is on [the IO10 board page](io10-board.md).

Labels follow [AGENTS.md](../../AGENTS.md): **established**, **inferred**, **unknown**. A fact about what a public Linux
driver does is established once its file is read; the same driver is only an inferred reading of the hardware. A capture
of the Origin 350 sibling is established for that machine and inferred for the Altix.

Sources:

- SGI, *SGI Altix 350 System User's Guide*, `007-4660-002` ("-002"), printed pages 112, 114, 115, 119 and 122 (PDF pages 140, 142,
  143, 147, 150). Page 112 gives the one-card-per-module rule, page 114 the IO9 connectors and IOC4 features, page 115 the disks
  and the DVD, page 119 the connectors of the factory base I/O card (Ethernet for both, serial for IO10 only, SCSI for IO9 only).
- SGI, *Altix 350 System User's Guide*, `007-4660-001` ("-001", 2004), printed pages 71 and 105 (PDF pages 95 and 129). The
  earlier revision names the IO9 as the riser's base card.
- Linux v2.6.18 (git tag): `drivers/sn/ioc4.c` (`ioc4_variant`, lines 236 to 269), `include/linux/pci_ids.h`,
  `drivers/scsi/qla1280.c` (the ISP 12160 entry), `drivers/ide/pci/sgiioc4.c` and `drivers/serial/ioc4_serial.c`. Linux
  current (`HEAD` `3eb40771c00a`): `drivers/net/ethernet/broadcom/tg3.c` (PCI table, line 242) and
  `include/linux/pci_ids.h`.
- This repository's [IO9 PCI wiring question](../../questions/ip35-io9-pci-wiring.md), which records an OpenBSD boot
  output from a real Origin 350. It is used as an observation of a sibling product, not of the Altix.

## Short answer

| Question | Answer | Grade |
|---|---|---|
| Card | IO9, the optional base I/O card of the Altix 350 (the earlier machine), in bus 1 slot 1, the bottom slot, of the lowest base module. One per module. | established (`-002` p.112, p.114; `-001` p.105) |
| Chips | An IOC4 (`10a9:100a`), a QLogic ISP 12160 Ultra3 SCSI host adapter (`1077:1216`) and a Broadcom BCM5701 gigabit Ethernet controller (`14e4:1645`) | IOC4 and ISP 12160 on the IO9: established (the Linux `ioc4_variant` rule in SGI's `ioc4.c`, graded as in the [SN2 README review](README.md)), with the Origin 350 capture as a sibling; BCM5701 on the Altix IO9: inferred |
| External connectors | One external VHDCI 68-pin SCSI connector, one 10/100/1000BaseT Ethernet connector, and the RTO and RTI real-time interrupt connectors | established (`-002` p.114) |
| Internal storage | Ultra3 SCSI disks, one or two, up to 160 MB/s, on the module's left front | established (`-002` p.115); `-001` p.71 gives SCSI disks for the Altix 350 but no transfer rate |
| DVD-ROM | One IDE channel from the IOC4 for the DVD (`-002` p.114). The DVD requires a base I/O card (`-002` p.115). | established |
| NVRAM and time-of-day clock | Both on the IOC4 (`-002` p.114) | established as the manual's statement; no shipped driver reads them (see below) |
| Serial connector | None on the IO9: the guide lists the multi-port serial connector as IO10 only (`-002` p.119). Whether the IOC4's serial lines reach the card edge: unknown. | no connector: established (`-002` p.114, p.119); serial lines at the edge: unknown |
| Revision | not stated in any held document | unknown |

## Parts

| Part | PCI ID | Role | Grade |
|---|---|---|---|
| IOC4 | `10a9:100a` | IDE channel for the DVD, NVRAM and time-of-day clock, serial and external interrupt blocks | established as the IO9's IOC4 (`-002` p.114); the PCI ID is from `pci_ids.h` at v2.6.18 (`PCI_DEVICE_ID_SGI_IOC4 0x100a`) |
| QLogic ISP 12160 | `1077:1216` | Dual-channel Ultra3 SCSI host adapter; the internal disks and the external VHDCI connector | ID established (`pci_ids.h` at v2.6.18 and HEAD; `qla1280.c` table). Its presence on the Altix IO9: established by the Linux IO9 rule (SGI's `ioc4.c`); the Origin 350 IO9 capture is a sibling. See the [ISP 12160 page](../../devices/isp12160/README.md). |
| Broadcom BCM5701 | `14e4:1645` | Single-port 10/100/1000 Ethernet MAC and PHY, to the RJ connector | ID established (`pci_ids.h`: `PCI_DEVICE_ID_TIGON3_5701 0x1645` at v2.6.18 and HEAD; `tg3.c` PCI table, HEAD line 242). Chip on the Altix IO9: inferred from the Origin 350 IO9 capture (a capture of the sibling). No BCM570x page is held in this repository. |

The Altix IO9's own part list is not held. The three chips above come from the Linux IO9 rule and the Origin 350
capture. Neither is a board document for the Altix.

Which SCSI channel of the ISP 12160 drives the external VHDCI connector, and which drives the internal disks, is
**unknown**. The manual lists both as IO9 connections and gives no channel map.

## PCI position

- **Slot and bus.** Bus 1 slot 1 of the lowest base module, the bottom slot (`-002` p.114). One card per system module
  (`-002` p.112). Established.
- **Linux IO9 rule.** Linux 2.6.18 `ioc4_variant` calls an IOC4 an IO9 when an ISP 12160 sits on the same PCI bus at PCI
  slot 3 (`PCI_SLOT(devfn) == 3`) (`drivers/sn/ioc4.c`, lines 241 to 252). Established as SGI's driver rule: the SCSI part is at
  device 3 on the card's bus.
- **Captured on the Origin 350 IO9 (sibling).** The OpenBSD boot output lists the IOC4 at logical device 0, the ISP 12160
  at logical device 2 and the BCM5701 at logical device 3 on the first bus of a PIC at widget 15 (per
  `questions/ip35-io9-pci-wiring.md`). Established for the sibling by the capture. That question reads the logical numbers as configuration
  devices 1, 3 and 4, because the PIC occupies device 0 and OpenBSD's logical numbers run one lower. That reading is
  **inferred**, and the Origin 350's PIC and bus are not the Altix 350's.
- **Altix placement.** The IOC4 at device 1, the ISP 12160 at device 3 and the BCM5701 at device 4 are the Altix's
  expected numbering, **inferred** from the sibling and from the PROM's window rule on
  [the base I/O page](altix-350-base-io.md#devices-on-the-pics-buses). Not established for the Altix.
- **Interrupts.** Captured on the Origin 350 as logical interrupt inputs 0 (IOC4), 2 (ISP 12160) and 3 (BCM5701). What
  each means on the Altix PIC is **unknown**; the question says the capture does not establish the pin or route.
- **Riser.** `-001` p.105 says the riser's nonstandard connector "connects to the IO9 card". `-002` p.115 says "the system's
  base I/O card". Whether the IO9 uses the same connector as the IO10 is **unknown**.

## Ethernet

- The external connector is 10/100/1000BaseT (`-002` p.114). **Established.**
- The controller is a BCM5701 on the Origin 350 IO9 (the sibling capture). For the Altix IO9 it is **inferred**. The Linux
  `tg3` driver binds `14e4:1645` as a BCM5701 (`tg3.c` line 242 at HEAD; the same ID at v2.6.18 line 154).
- The fitted IO9 EEPROM part and its contents are **unknown**. No BCM570x page or other document held here establishes
  a complete IO9 EEPROM image.
- The `-002` and `-001` texts do not name an Ethernet part. The Altix's Ethernet MAC address source (EEPROM or the
  board's own) is **unknown**.

What would settle the controller on the Altix: a board photograph with the chip's marking, or a `lspci -vnn` capture from
an IO9 machine. What would settle the EEPROM: a board-level read on a physical IO9, which is a last resort under the
repository's hardware rules.

## Linux expectations

- The IO9 variant enables the IDE and serial sub-drivers (`drivers/ide/pci/sgiioc4.c`, `ioc4_ide_attach_one`;
  `drivers/serial/ioc4_serial.c`, line 2787). These attach to any non-PCI-RT IOC4. Established as driver code; inferred for the card.
- The manual lists no serial connector on the IO9. Linux still attaches four UARTs, so whether the IOC4's serial lines
  reach the card edge is **unknown**.
- The RTO and RTI connectors are "not supported under SGI Linux + ProPack" (`-002` p.114). Established as the manual's
  statement.

## RTC, NVRAM and the DVD

- The manual gives the IOC4 NVRAM and a time-of-day clock on the IO9 (`-002` p.114). Established as the manual's statement.
  The clock's part, its battery and whether it is the Altix's system time source are **unknown**.
- Linux 2.6.18 has no consumer of an IOC4 NVRAM or time-of-day block. The only RTC use in `drivers/sn/ioc4.c` is the
  clock calibration of the IOC4's interrupt counter, which reads the system RTC (`rtc_time()`), not the card's.
- The DVD's IDE channel is the IOC4's (`-002` p.114). The DVD needs a base I/O card (`-002` p.115). Established.

## Differences from the IO10

- The IO9 drives SCSI disks; the IO10 drives SATA disks (`-002` p.112 and p.115). Established.
- The IO9 has an external SCSI connector and an Ethernet connector; the IO10 has a 36-pin serial connector and an
  Ethernet connector (`-002` p.119; the option note p.3 says the IO10's is 10/100/1000, see the [IO10 page](io10-board.md#ethernet)).
- `-001` (2004) predates the IO10. Its text describes only the IO9.

## Unknown, and what would settle each

- **Altix IO9 chip revisions** (IOC4, ISP 12160, BCM5701). Settles: a capture from an IO9 machine, or board markings.
- **ISP 12160 channel map** (external VHDCI versus internal disks). Settles: the card's schematic, or a SCSI bus scan from a
  running IO9 machine.
- **Whether the IOC4 serial lines reach the card edge**, and which of them the PROM or Linux uses. Settles: a schematic,
  or a probe of the card on a running machine.
- **The Altix PIC pins for the IOC4, ISP 12160 and BCM5701**, and the PCI device numbers on the Altix. Settles: the PROM's
  interrupt table for the IO9 read under the base I/O page's method, or a PIC routing capture on an Altix IO9.
- **Fitted EEPROM for the BCM5701** and whether the MAC address is read from it. Settles: a board-level read on a physical
  IO9, or a published SGI IO9 document that names the part.
- **Real-time interrupt connector behaviour under IRIX.** The manual says it is not supported under Linux. Settles: an IRIX
  driver read or a hardware test.
- **Card revision.** Settles: the label on the card, or the production record.

## Discrepancies

- The IO9's connectors and features are the same in `-002` and `-001` in substance. `-001` says the riser connector and the
  DVD belong to the IO9. `-002` adds the IO10 and says the DVD needs "a base I/O card" in general.
- The Origin 350 is a sibling product. Its IO9 supplies the chip identity used here, and its PCI numbering is not the Altix's.

## Review

Independent review, 2026-11-21, by a reviewer who wrote none of these pages. Reviewed chips commits bff4d94, b2e30a2 and 80f1819.

Checked against 007-4660-002 pp.112 to 122, 007-4660-001 pp.71 and 105, Linux v2.6.18 `ioc4.c`, `ioc4_serial.c`, `pci_ids.h`,
`qla1280.c`, `tg3.c`, and `questions/ip35-io9-pci-wiring.md`.

- Connectors, IOC4 features, disks, DVD, slot, `ioc4_variant` rule, PCI ids and table line numbers: confirmed. The Origin 350
  capture was not re-derived; it is quoted from the question page.
- **Fixed.** The serial row now cites `-002` p.119, which labels the multi-port serial connector "IO10 only".
- **Fixed.** Labels moved to the three-rating set of chips AGENTS.md; sibling captures are inferred for the Altix.
