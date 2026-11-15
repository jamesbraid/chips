# Altix 350 base I/O cards: open points

Open points from [the base I/O card page](../platforms/sn2/altix-350-base-io.md). Each entry: question, routes tried,
next route. Route tags in brackets.

## Ethernet controller on the IO9 and IO10

[missing source] Neither guide (007-4660-001, -002) nor SGI's Linux platform code names the part behind the
10/100/1000BaseT port, or its PCI slot. Tried: both guides' base I/O pages; `v5.3:drivers/misc/ioc4.c` and the SN2
platform code (no mention); the strings of the held SHub 1 PROMs (4.43 and 10.40 carry a Tigon 3 klconfig builder, the
10.54 image no plain strings for it); the shipped SN2 kernel's configuration (the `tg3` driver is a module). Next:
the SAL runtime component of the 10.54 image, where the per-device record builders may live; a boot log or `lspci` from an
Altix 350 with either card; an Altix IO9 board manual.

## Slot numbers on the riser

[missing source] The PCI device (IDSEL) number of each of the riser's four slots, and of the IOC4 on the base card, are
not printed anywhere read. Only the SCSI or SATA controller (slot 3 of the card's bus) is fixed, by the Linux variant
test. The Origin 350's IO9 puts the IOC4, the ISP 12160 and a BCM5701 at configuration slots 1, 3 and 4 of the PIC's first
bus ([IO9 placement](ip35-io9-pci-wiring.md)); whether the Altix cards repeat that is inferred only. Next: a captured
`lspci` or `/proc/bus/pci/devices`; the PCI-X tables of the riser card in a service manual.

## INTx to PIC pin map on the Altix 350

[software now] The PIC pin an INTA to INTD of each slot raises, and the pin the base card's IOC4, SCSI or SATA and Ethernet
parts use, are chosen in the PROM's PCI device information call (`SN_SAL_IOIF_GET_PCIDEV_INFO`, 0x02000057), not in the
kernel. Its handler is in the compressed SAL runtime; the SAL_B table has no named function for it. Next: decompress
and load the runtime component of the 10.54 image (the repository's IA-64 module reads SAL_A and SAL_B only) and read
the handler for 0x02000057 and the interrupt allocator behind 0x0200004a.

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
