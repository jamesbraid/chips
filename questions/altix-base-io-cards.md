# Altix 350 base I/O cards: open points

Open points from [the base I/O card page](../platforms/sn2/altix-350-base-io.md). Each entry: question, routes tried,
next route. Route tags in brackets.

## Ethernet controller on the IO9 and IO10

[missing source] Neither guide (007-4660-001, -002) nor SGI's Linux platform code names the part behind the
10/100/1000BaseT port, or its PCI slot. Tried: both guides' base I/O pages; `v5.3:drivers/misc/ioc4.c` and the SN2
platform code (no mention); the held SHub 1 PROMs (4.43 and 10.40 carry a Tigon 3 klconfig builder that types Broadcom 1644 (5700), 1645 (5701) and 16a7 (5703X) only; 10.54 has no builder; every build's EFI ships only Broadcom's UNDI driver, see [the per-device section](../platforms/sn2/altix-350-base-io.md#what-the-shub-1-firmware-does-per-device)); the shipped SN2 kernel's configuration (the `tg3` driver is a module). The IO10's 10/100/1000 RJ-45 port is stated by the option note 007-4374-001 p.3, so only the controller part is open. Narrowed to the exact Broadcom device id of the IO10 (inferred Tigon 3 family). Next: a boot log or `lspci` from an
Altix 350 with either card; an Altix IO9 board manual.

## Slot numbers on the riser

[missing source] The PCI device (IDSEL) number of each of the riser's four slots, and of the IOC4 on the base card, are
not printed anywhere read. Only the SCSI or SATA controller (slot 3 of the card's bus) is fixed, by the Linux variant
test. The Origin 350's IO9 puts the IOC4, the ISP 12160 and a BCM5701 at configuration slots 1, 3 and 4 of the PIC's first
bus ([IO9 placement](ip35-io9-pci-wiring.md)); whether the Altix cards repeat that is inferred only. Next: a captured
`lspci` or `/proc/bus/pci/devices`; the PCI-X tables of the riser card in a service manual.

## INTx to PIC pin map on the Altix 350

Answered. The PROM's PCI device information call (`SN_SAL_IOIF_GET_PCIDEV_INFO`, 0x02000057) returns a pin of `d - 1` for
INTA and INTC and `(d + 3) & 7` for INTB and INTD of PCI device `d`, read in snprom 10.54 and 4.43
([PIC page](../devices/pic/README.md#which-pic-pin-an-inta-to-intd-lands-on-and-what-sal-call-0x02000057-returns-snprom-1054-and-443-shub-1)). Remaining: the PCI device numbers themselves (above), and the rotation a bridge applies to a
device behind it (table at `0xffb43680`, not read).

## What the L1 returns for an Altix 350 module

[missing binary] Two reads decide the PROM's naming and record: the L1 module type byte the PROM caches (`0xffa80430`
and `0xffa80210` take it from an L1 reply), and the chassis and board areas of device 1. The PROM names a node
"onboardIO" for module type bytes 0x6d, 0x6f, 0x6c and 0x7b, and "WEIRDIO" for any byte not in its list, which includes
0x35, the code the Linux header gives the IP41 node. Which byte an Altix 350 L1 reports, and so which name the node
gets, is unknown. Next: the ARM L1 firmware for the 350 (in the system-controller repository), the L1 command that
answers the module query.

## Which device the PROM's I/O record comes from

[software now] For an even NASID the PROM reads the I/O manufacturing record from device 1 through the system
controller, the device id the node board reader also uses. Whether the L1 answers device 1 from the node board's
serial ID EEPROM, an interface board part or a riser part is unknown; no guide lists an EEPROM on the riser. Next: the L1
firmware's handler for command id 6 with selector 1 and 2 (the sysco repository's ARM IP57 readings).

## Where the IOC4's NVRAM and time-of-day clock are reached

[missing source] The guides list an NVRAM and a time-of-day clock on the IO9's IOC4. No Linux driver for the SN2 touches
them. The IRIX IOC4 page records a byte-bus strobe-width field and no NVRAM register. Next: SAL runtime strings and
handlers for the time-of-day and NVRAM SAL calls.

## IO9 and IO10 serial pins and the DVD-ROM channel

[missing source] That the IO10's S0 to S3 are the IOC4's four UARTs in port order, that its DVD-ROM sits on the IOC4's
IDE channel, and that the IO9 wires no serial connector, are readings from the guides, the Linux variant test and the
driver attach rules. None is stated. Next: an IO10 board manual or a boot log that lists the serial ports and the IDE
device.
