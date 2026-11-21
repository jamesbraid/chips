# Altix 350 base I/O cards: IO9, IO10 and the PCI riser

A base I/O card sits in the lowest slot of the PCI riser of the lowest base compute module of an Altix 350 (at most one
per module; the guides require it in the lowest module only). The card is either
the IO9 (the 2004 machine) or the IO10 (standard on the later machine, with the IO9 optional). This page records which
PCI devices each card carries, how the cards sit behind the PIC on the riser, what the SGI Linux platform code and the
held PROM say about the riser's identity record, which console the PROM expects, and how a device interrupt reaches the
SHub. It holds no register layouts: the IOC4 is on [the IOC4 page](../../devices/ioc4/README.md), the PIC on
[the PIC page](../../devices/pic/README.md), and the SAL calls the kernel makes on
[the SN2 SAL page](../../software/sal/README.md). The module as a whole is on [the Altix 350 page](altix-350.md).

Sources, each cited where used: SGI, *SGI Altix 350 System User's Guide*, `007-4660-001` (2004, "-001") and
`007-4660-002` ("-002"), printed pages; SGI, *Important Note: SGI IO10 PCI Option for Altix 350*, `007-4374-001`.
SGI's Linux platform and driver code at v5.3, cited `v5.3:path` (`v5.3:drivers/misc/ioc4.c` and the SN2 files under
`v5.3:arch/ia64/`; v5.3 still carries the IOC4 base driver). The held SNPROM 10.54 build 70399 image (SAL 5.04, SHub 1),
read in Ghidra with the repository's IA-64 module; addresses are the image's, as `0xffa00000 + file offset`, and
"decompiler output" below means a function whose C text was read beside its listing, which is navigation, not evidence by
itself. Everything graded here follows [AGENTS.md](../../AGENTS.md): **established**, **inferred**, **unknown**.

## Short answer

| Question | Answer | Grade |
|---|---|---|
| What is on the riser | One PIC with two PCI/PCI-X buses of two slots each, a nonstandard connector for the base I/O card, no other chip named | established (-001 p.105; -002 p.115) |
| What the IO9 carries | An IOC4, a QLogic ISP 12160 SCSI controller at PCI slot 3 of the card's bus, and a 10/100/1000 Ethernet port | established for the IOC4 and the ISP 12160 (`v5.3:drivers/misc/ioc4.c`, `ioc4_variant`); Ethernet controller part **unknown** (see below) |
| What the IO10 carries | An IOC4, a Vitesse VSC 7174 serial ATA controller at PCI slot 3 of the card's bus, a 36-pin serial connector and an Ethernet port | established for the IOC4 and the VSC 7174; Ethernet controller part **unknown** |
| Riser identity record | The PROM reads no record from the riser as such on an Altix 350. The record it reads for a base I/O node comes from the system controller (device 1), in the format of an IPMI board information area | established for the reader; which physical EEPROM device 1 is: **unknown** |
| Console the PROM expects | One of the PROM's system-controller console objects (named SysCt). Neither the IO9's nor the IO10's IOC4 is a boot console | established from the console selector; the Linux console calls reach the same device |
| Interrupt route | Device INTx pin, PIC interrupt pin (one of eight), crosstalk write to a SHub address chosen by the PROM, vector 0x3c to 0xe6 on a CPU | established as a chain; the pin each device uses on the 350: **unknown** (inferred from a sibling card, below) |

## The riser and where the card sits

The base compute module's PCI riser card provides the PIC, the connectors to the interface board, "a nonstandard
PCI/PCI-X connector that connects to the IO9 card" (-001 p.105; "the system's base I/O card" in -002 p.115) and four
PCI/PCI-X slots, 64-bit and 3.3 V, at speeds up to 133 MHz (-002 p.115). The logic diagram (-001 p.99; -002 p.107)
draws the PIC with two buses, "bus 1 slot 1 and 2" and "bus 2 slot 1 and 2", and the IO9 in bus 1 slot 1, below the
other slot of that bus. Both guides require the base I/O card in bus 1 slot 1, the bottom slot, of the lowest base
compute module (-001 p.104; -002 pp.112, 114). One card per module. The diagram also draws an "XIO" link from a block
labelled "system control" and "PCI riser control" on the riser to the SHub side, and does not describe it. All
established as printed.

What the guides do not say, and what stays **unknown**: whether the nonstandard connector is the bus 1 slot 1 connector
with extra pins (the IO9's SCSI, IDE and serial signals are not PCI signals), or a second connector next to it; how
many of the four drawn slots remain for add-in cards (the diagram shows four, the base card taking one); and the PCI device (IDSEL) number of each of the
four slots.

The PIC bus numbers the kernel sees come from the PROM, one per PIC bus (`sal_get_pcibus_info`, id
`SN_SAL_IOIF_GET_PCIBUS_INFO`; `v5.3:arch/ia64/sn/kernel/io_init.c`), and the kernel treats one bus specially only for hot plug: on an IX or IA brick, segment 1 bus 0, it refuses every
device number but 1 (`v5.3:drivers/pci/hotplug/sgi_hotplug.c`, `sn_pci_slot_valid`). Those are not the 350's brick
types, and nothing in the kernel names the 350's base card slot.
Established as a reading; no consequence for the 350.

## The IO9

The guide lists on the card: an external VHDCI 68-pin SCSI connector, a 10/100/1000BaseT Ethernet connector, and real
time interrupt output and input connectors (RTO and RTI), which "is not supported under SGI Linux + ProPack"; and an
IOC-4 ASIC that "supports one IDE channel for the DVD-ROM" and "NVRAM and time-of-day clock" (-001 p.104; -002 p.114).
The diagram draws the SCSI controller as "SCSI 160". The DVD-ROM needs the card (-001 p.105). Internal disks are
Ultra3 SCSI, not SATA (-002 pp.112, 115). All established as printed.

The chips behind those words come from SGI's Linux driver, which tells the card variants apart by the other devices on
the IOC4's PCI bus (`v5.3:drivers/misc/ioc4.c`, `ioc4_variant`, lines 225 to 267): an IOC4 whose bus has a **QLogic
ISP 12160 (vendor 0x1077, device 0x1216) at PCI slot 3** is an IO9
(`v5.3:include/linux/ioc4.h`, `IOC4_VARIANT_IO9`, value 0x0900; ids from `v5.3:include/linux/pci_ids.h`). The IOC4
itself is vendor 0x10a9, device 0x100a, matched on class code 0x0b4000 (`ioc4_id_table`, same file). Established. The
SCSI controller is the part SGI's `qla1280` driver supports (`v5.3:drivers/scsi/qla1280.c`, "QLA12160 (Ultra3)").

The IOC4 is the same part the IP35-class MIPS boards carry; its register contract is on
[the IOC4 page](../../devices/ioc4/README.md), read there from IRIX driver objects. The Linux driver's own register
header (`v5.3:include/linux/ioc4.h`) uses the same offsets. What this card adds to that page is wiring: which of the
IOC4's functions the card brings out. The guide lists the IDE channel (DVD-ROM), NVRAM and time of day, and the RT
interrupt pins, and does not list serial ports or a keyboard and mouse port on the IO9. The Linux serial driver still
registers four ports on an IO9, because it skips only the PCI-RT variant
(`v5.3:drivers/tty/serial/ioc4_serial.c`, `ioc4_serial_attach_one`, line 2788). So that the IO9 brings the serial
signals out to a connector is **unknown**; that the guide shows none is established.

NVRAM and the time-of-day clock are listed as IOC4 features. No Linux driver in the SN2 tree touches them (the kernel's
clock comes from the PROM through EFI), so they are firmware-only on this machine, and their access path (the IOC4
byte bus) is **unknown** here.

## The IO10

The Important Note describes the IO10 as a full-size PCI card for the lower slot that "connects to your system's
internal serial ATA hard drive(s) and DVD-ROM drive and provides optional external serial ports" (007-4374-001 p.1;
-002 p.113). Figure 1 there shows two unlabeled RT interrupt connectors, one Ethernet port and a multi-port serial
connector, and p.3 gives the Ethernet interface as an RJ-45 jack at 10/100/1000 Mbit/s; the RT connectors are not supported under Linux. The multi-port connector is a 36-pin MDR connector that a
cable converts to four 9-pin serial ports, S0 to S3, each with transmit, receive, DTR, DSR, DCD, RTS, CTS and ring (pin
table, 007-4374-001 p.2). Modules with an IO10 take no SCSI internal drives (007-4374-001 p.1). All established as
printed.

Chips, from the same driver function: an IOC4 whose bus has a **Vitesse VSC 7174 (vendor 0x1725, device 0x7174) at PCI
slot 3** is an IO10 (`IOC4_VARIANT_IO10`, 0x1000). The VSC 7174 is a four-port serial ATA controller
(`v5.3:drivers/ata/sata_vsc.c`, header comment "4 port DPA SATA"); the guide says one or two SATA disks (-002 p.115), so
at most two of the four ports are wired to drive sleds, and how the others are used is **unknown**. Established for the
IOC4 and the VSC 7174; inferred for the "at most two" reading from the sled count.

Two further statements are inferred, not read:

- **The IO10's serial ports are the IOC4's four UARTs.** The IOC4 has four serial ports with full modem control, the
  card's connector carries four full modem-control ports, and the driver registers four ports for any variant but
  PCI-RT. The port-to-pin mapping (which IOC4 port is S0) is **unknown**. The IOC4's general-purpose pins 4 to 7 select
  the transceiver of ports 0 to 3 and the driver sets them as outputs (`ioc4_serial_attach_one`, line 2844); whether the
  IO10 wires them to a transceiver switch is unknown.
- **The DVD-ROM on the IO10 is on the IOC4's IDE channel.** The IDE driver attaches to every variant but PCI-RT
  (`v5.3:drivers/ide/sgiioc4.c`, `ioc4_ide_attach_one`, line 609), the IO10 is not PCI-RT, and the VSC 7174 is a serial
  ATA controller that cannot drive an ATAPI DVD-ROM of the slim-line IDE kind the guide shows (a reasoned reading, not a
  statement of either guide). The -002 guide says only that the card "connects to ... DVD-ROM drive".

### IO10 facts from the manuals (established)

- The IO10 is the standard base I/O card of the Altix 350; the IO9 is the optional one. Each system takes one of the two,
  in PCI slot 1 of a module, and only one per module (007-4660-002 p.112; 007-4374-001 p.1).
- A module with an IO10 takes one or two SATA system disks and no SCSI internal drives (007-4660-002 pp.112, 115).
- The card has a full-size PCI board form, a 36-pin MDR multi-port serial connector that a cable splits into four DB-9 serial
  ports, two RT interrupt connectors that SGI Linux + ProPack does not support, and an Ethernet port (007-4374-001 p.1 and
  Figure 1; 007-4660-002 p.113).
- The 36-pin connector's pin assignments are in 007-4374-001 p.2, Table 1.
- Table 3-3 of 007-4660-002 (p.122) lists the SATA internal port and the 36-pin serial adapter connector as IO10 features.

## Ethernet and the PCI wiring

Both guides list one 10/100/1000BaseT port on each card and name no controller. The Linux driver tree names none
either, and the IO10's SATA and the IO9's SCSI controller are found by `ioc4_variant` at slot 3, which leaves slots
1, 2 and 4 of the card's bus for other parts. What SGI's shipped software expects:

- **The shipped SLES 9 SN2 kernel (2.6.5-7.244, held) builds `tg3` and the IOC4 IDE driver as modules and the Vitesse SATA
  driver as a module** (its `config`: `CONFIG_TIGON3=m`, `CONFIG_BLK_DEV_SGIIOC4=m`, `CONFIG_SCSI_SATA_VITESSE=m`,
  `CONFIG_SCSI_QLOGIC_1280=m`). That is a build setting, not a statement of the card's contents. Established as read;
  inferred as a hint for the Ethernet part.
- **The SHub 1 PROM images 4.43 and 10.40 carry a PCI inventory printer with typed components** QLFIBRE, GIGENET,
  QLSCSI, SATA, IOC3 and a Tigon 3 klconfig builder (`init_klcfg_tg3`); the 10.54 image has none of them, in SAL_B or in the
  runtime (see [what the firmware does per device](#what-the-shub-1-firmware-does-per-device))). The names are a taxonomy of what the PROM can type, so the
  gigabit controller is typed as a Tigon 3 on the PROM that has the strings. Established as strings in 4.43 and 10.40;
  inferred as the Altix 350 Ethernet part (a Broadcom BCM57xx part).
- **The MIPS-side sibling card.** On an Origin 350 IO9 (PCI-X behind a PIC, the same IOC4 and ISP 12160) public boot
  captures list the IOC4 at logical device 0, the ISP 12160 at 2 and a BCM5701 at 3 on the PIC's first bus, which are
  configuration slots 1, 3 and 4
  ([IO9 placement question](../../questions/ip35-io9-pci-wiring.md)). The Altix rule "SCSI at slot 3" agrees with the
  middle one. Inferred, not established, that the Altix IO9 repeats the placement: IOC4 at slot 1, ISP 12160 at slot 3, BCM
  Ethernet at slot 4. The IO10 would then keep slots 1 and 3 for the IOC4 and the VSC 7174, with the Ethernet part at
  slot 4 or elsewhere (unknown).

So: the Ethernet controller on the Altix IO9 and IO10 is **unknown**; a Broadcom Tigon 3 part is the better
hypothesis, inferred from the three items above and the sibling card. No Altix capture of `lspci` is held.

- If the Ethernet part is a BCM5701 (inferred above, not established), its register reference is the Broadcom "BCM57XX Host
  Programmer Interface Specification", 57XX-PG105-R, which we hold among its datasheets. No standalone BCM5701
  datasheet is public; the Linux `tg3` driver is the other reference.
- No public VSC 7174 datasheet exists: a search of held sources and the web (2026-11-15) found none. Linux `sata_vsc.c` is the only
  source for that part here.

## The riser identity record

The question is whether the PCI riser has an EEPROM that firmware reads. What the held PROM and the guides say:

- **The guides name a serial ID EEPROM only on the node board** ("contains component information", -001 p.100; -002
  p.108), and list the riser's contents without one (above). Established as printed; that the riser has none is not
  established, only that no document lists one.
- **Linux does not read any board or riser record.** The only I/O board query the kernel makes is the board type
  (`SAL_SYSCTL_OP_IOBOARD`, `ia64_sn_sysctl_ioboard_get`; `v5.3:arch/ia64/include/asm/sn/sn_sal.h`), which returns a
  16-bit type code the hot-plug driver compares with the L1 brick types (`L1_BRICKTYPE_IX` and others) and board types
  (`L1_BOARDTYPE_BASEIO` 0x0300, "IB", `L1_BOARDTYPE_PCIX3SLOT` 0x0500, "ID";
  `v5.3:arch/ia64/include/asm/sn/l1.h`). Established. The base I/O board type 0x0300 is a code for a board an L1 can
  report; no Altix 350 here is known to report it.
- **The PROM reads the record through the system controller, not I2C.** For each node with local I/O the bridge
  discoverer (`0xffabfb10`, decompiler output beside the listing) calls a manufacturing-string builder `io_mfg_info`
  (`0xffaf1ee0`) that picks a reader by the node's NASID parity: an odd NASID (a TIO) uses the reader at `0xffa84fd0`
  (open mask `0x0ffff000`), an even one (a SHub, the Altix 350) the reader at `0xffa85550` (open mask `0x4ffff000`). Both
  read first a chassis information area (selector 1) then a board information area (selector 2) of device 1; the second
  reader uses device 98 instead when the L1 module type byte is 0x6f ("o", the Prism family) and rewrites the mask to
  `0x0ffff000` for types 0x6d and 0x6f (`0xffa819c0`). Established (read in full).
- **The routine named for the riser is not the 350's.** The runtime symbol `sysctl_eeprom_io_riser` is at `0xffa85120`
  (placed from its neighbours, the node reader `sysctl_eeprom_node` at `0xffa84fd0` and the brick reader
  `sysctl_eeprom_iobrick` at `0xffa85550`, whose run-time offsets differ by the same distances as the image addresses:
  inferred). Its one caller is `0xffa85200`, the neighbouring `sysctl_p0_opus_tio_riser`: a board read of device 98,
  used for the Prism TIO riser. So the riser EEPROM the PROM names is the Prism's, and for the Altix 350 the I/O record
  is device 1, the same device id the node board reader uses. Established for the call graph; the symbol-to-address
  placement is inferred.

What the record looks like once read (established, `0xffa84990` read in full; agrees with the independent reading in
[the boot path page](../../software/firmware/snprom/boot-sequence.md)): an IPMI-style information area of `length` times
8 bytes. Byte 0 is the format version, byte 1 the length in 8-byte units (zero is an error), byte 2 the language, bytes 3
to 5 the manufacture time, then type/length-coded fields (low six bits the length): manufacturer, product name, serial
number, part number and a FRU file id, then further such fields to a terminator byte `0xc1`. The area's bytes sum to
zero modulo 256 or the read fails with "bad checksum". The PROM formats the fields as
`Part:..;Name:..;Serial:..;Revision:..;Group:..;Capability:..;Variety:..;Laser:..;`, and the only field it reads back is
`Laser:`, a 64-bit hexadecimal number stored in the bridge's klconfig record (`0xffabf570`). Established. What the L1 puts
in the fields for an Altix 350, and which of its EEPROMs device 1 is, is **unknown**: no L1 image for the 350 was read
for this page.

## Which card the PROM expects

- **No card-specific code.** The SHub 1 images carry no string naming an IO9 or an IO10. The PROM's I/O knowledge is by
  bridge part: the widget id register at widget 0 is read, a crossbar (part `0xd000` or `0xd100`) is walked, and a PIC
  (part `0xd102`, or `0xd112`, with manufacturer field 0x24; the second bus is checked the same way) is initialised through `0xffab0c00` once for each of its two buses, at the widget base and base
  `+ 0x80_0000` (`0xffab15c0`, `0xffab0f10`, `0xffabfb10`; established, read in full in
  [the boot path page](../../software/firmware/snprom/boot-sequence.md)). The kernel and the PROM tell the cards apart by
  contents only (the Linux `ioc4_variant` above).
- **Where the base I/O node is chosen.** `io_baseio_master_nasid_set` (`0xffb60bb0`, decompiler output) takes a node's
  L1 module id and keeps the node whose id, ignoring bits 15:8, is the lowest, with the lower NASID breaking ties; it
  stores the module id and NASID in the PROM's node data. That agrees with both guides ("the lowest base compute module",
  -001 p.104). The kernel's call for the answer, `SN_SAL_GET_MASTER_BASEIO_NASID` (id `0x0200003c`), has no caller in
  the files read, and the handler in this image (`0xffb60910`) returns status 0 and the 64-bit word the selection
  routine stores in the node data at offset 0x28, NASID in the low 16 bits and module id above (read in Ghidra and
  in an objdump listing). Established for the selection rule and for what the handler returns. The kernel header says the
  NASID is in the result; whether the stored word equals a bare NASID is not read.
- **The PCI walk that finds the IOC4 is not on the boot path.** The "IOC3/IOC4 devices must be located in one of the
  first 3 slots of a pci bus" check and the IOC4 byte-order setup sit in a driver block reached through the SAL
  procedure table, not from the code that runs before the EFI hand-off
  ([the boot path page](../../software/firmware/snprom/boot-sequence.md)). So the IOC4 is set up when the kernel asks
  (the SN SAL slot and device-info calls), and a machine model that boots Linux needs the IOC4 at one of slots 1 to 3
  of its PCI bus. Established as a string; the rule's trigger is inferred from the message.

### Console

- **The boot console is not on the base I/O card.** The console probe (`0xffa1fca0`) walks the specification string
  `rpd` (`0xffbba0a0`) and asks the console object for each letter in that order, `r` (`0xffaea490`), `p` (`0xffae9200`),
  `d` (`0xffaeaff0`). The console object table (`0xffbe8648`) names them "SysCt (RT)", "SysCt" and "SysCt(dir)"; none is
  the junk-bus UART. A fourth object, `e`, "EfiCB", is in the table but not in the string. The `p` probe
  ends in a test that the PROM is not running under a simulator (`0xffa806d0`, a signature compare on the processor's
  identification register; the middle call `0xffa805e0` was not read). The first object whose probe succeeds becomes the console (established, read in full).
  No IOC4 UART is on the list.
- **The operator's POD menu** names four UARTs a console can be moved to: an "IOC3" UART, the junk-bus UART, the system
  controller UART and a network UART (strings at `0xffbbf490` to `0xffbbf510`: `ioc3`, `junk`, `elsc`, `talk`). The
  heritage name is IOC3; an Altix 350 base card carries an IOC4, so the IOC3 entry has no part to act on here. Established
  as strings; inferred as unusable on a 350.
- **The kernel's console is the PROM's.** Linux does not drive the IOC4 UARTs as a console on this machine; it issues
  `SN_SAL_CONSOLE_PUTB`, `READC` and the other console calls, which the PROM forwards to the console object chosen above
  (`0xffb5c9c0`, `0xffb5ca20`, `0xffb5ccf0`, `0xffb5cb60`, `0xffb5ce70`, each a thin call through a function-table slot
  of the active console object, via `0xffae0f40`), and takes an interrupt on vector 0xe9
  (`v5.3:drivers/tty/serial/sn_console.c`). Established. The module's DB-9 console port belongs to the L1, per
  [the Altix 350 page](altix-350.md); it reaches the guest only through this path.
- **Consequence for the cards.** The IO10's serial connector (IOC4 UARTs) is for add-in serial devices that the kernel
  drives with the IOC4 serial driver, not a console path, and its absence on the IO9 does not stop the machine booting.
  Established for the PROM and kernel behaviour; inferred that an unattended IO9 system boots without the IO9's IOC4
  serial.

## Interrupt route to the SHub

The route, each step established from SGI's Linux code except where marked.

1. **The device raises INTx on the PCI bus.** Which of the PIC's eight interrupt pins an INTA to INTD of a slot lands
   on is decided by the PIC's wiring and its device-to-pin register, and is **unknown** for the 350. The Linux kernel
   never computes it: it receives the bit with the rest of the device's interrupt record from the PROM
   (`sn_irq_info.irq_int_bit`, "Bridge interrupt pin"; `v5.3:arch/ia64/include/asm/sn/intr.h`, filled by
   `sal_get_pcidev_info` in `sn_io_slot_fixup`, `v5.3:arch/ia64/sn/kernel/io_init.c`). The sibling card on the
   MIPS Origin 350 puts the IOC4 on pin 0, the ISP 12160 on pin 2 and the BCM5701 on pin 3 (same IO9 placement question
   as above); inferred, not established, that the Altix PROM assigns the same pins.
2. **The PIC latches the pin and sends a message.** It has eight pins (status register bits 7:0 at offset `0x100`),
   a per-pin host address register at `0x130 + 8n` holding a 48-bit crosstalk address, force registers at `0x180 + 8n`
   and `0x1c0 + 8n`, and an error interrupt view at `0x170` (`v5.3:arch/ia64/include/asm/sn/pic.h`; the PIC page has
   the same offsets from IRIX). When a pin is set it writes an interrupt packet to the address in that pin's register.
   The kernel retargets by clearing the pin's enable, rewriting the address and enabling it again
   (`pcibr_target_interrupt`, `v5.3:arch/ia64/sn/pci/pcibr/pcibr_provider.c`).
3. **The address is chosen by the PROM.** `SN_SAL_IOIF_INTERRUPT` (id `0x0200004a`) with operation 1 asks the PROM for a
   vector (0x3c to 0xe6, `IA64_SN2_FIRST_DEVICE_VECTOR` and `IA64_SN2_LAST_DEVICE_VECTOR`), a target NASID and slice, and
   returns the crosstalk address in `irq_xtalkaddr`; operation 2 frees and 3 redirects (`v5.3:arch/ia64/sn/kernel/irq.c`).
   In the held PROM the handler (`0xffb1f970`, decompiler output) dispatches the three operations to the provider kept per (NASID, widget) in the node record (`+0x958 + 0x30 * widget`) and fails with "NULL provider pointer" when none is registered. The
   SHub provider is in SAL_B, not the compressed runtime, and is read: it picks the target node and slice (the bridge's own node first, another node only if it has no processor), picks the vector, and returns `target nasid << 36 | 1 << 47 | SH_II_INT0` (slice 0) or `SH_II_INT1` as the address; the PIC's own registers are programmed at scan time (established; [SHub interrupts](../../devices/shub/interrupts.md#the-firmwares-interrupt-allocator-sn_sal_ioif_interrupt)). The packet lands on the SHub's I/O interface and becomes one of its interrupt events (inferred: the kernel clears an
   event register, below, and names no other path).
4. **The SHub delivers a vector.** The kernel acknowledges by reading the SHub event-occurred register and writing its
   alias (`sn_ack_irq`, `v5.3:arch/ia64/sn/kernel/irq.c`); the exact SHub register bits are with the SHub pages.
  
5. **Lost-interrupt workaround.** Because a PIC does not resend, on SHub 1 each CPU's timer interrupt polls the device interrupts of its range once every 100 ticks
   (`SN_LB_INT_WAR_INTERVAL`, `v5.3:arch/ia64/sn/kernel/sn2/timer_interrupt.c`): if the PIC status bit for a pin is set, the CPU has the vector neither pending nor in service, and the
   pin was already set at the previous poll, it forces an interrupt by writing the pin's force register
   (`sn_check_intr`, `sn_lb_int_war_check`). Established. A model must keep that register write observable: a PIC that
   ignores it leaves an IOC4 interrupt stuck if a packet is dropped.

Error interrupts are separate: the PIC raises vector 0x33 (`SGI_PCIASIC_ERROR`) and the SHub I/O interface 0x31, both
fixed in `v5.3:arch/ia64/include/asm/sn/intr.h`. The IOC4's own interrupt sources (serial, ATA, keyboard, external
input) share one PCI interrupt line through the IOC4's status registers
([IOC4 page](../../devices/ioc4/README.md)), so the IO9 and IO10 each use a single PIC pin for the IOC4. Established
for the IOC4 sharing; the same for the SCSI, SATA and Ethernet parts, one pin each, is inferred from the sibling card.

## Devices on the PIC's buses

What the PROM scan meets, by PIC bus and configuration window (window `n` is at `W + 0x20000 + n * 0x1000`; the PROM's slot is `n - 1`, and Linux's PCI device number is `n`). Scan order and the empty-slot rule are on [the PIC page](../../devices/pic/README.md#pci-scan-and-the-protected-read-stop-at-0xffb5cf50).

| Bus (widget 15) | Window | Device | Vendor:device | Grade |
|---|---|---|---|---|
| 0 (first scanned; windows 1 to 4 all read) | 1 (PROM slot 0) | IOC4 | `10a9:100a` | the part: established (Linux `ioc4_variant`, PROM rule "IOC3/IOC4 in slots 0 to 2"); window 1: inferred from the Origin 350 capture |
| 0 | 2 | none on an Origin 350; a TI PCI bridge `104c:ac28` on a Tezro | | unknown for the Altix |
| 0 | 3 | IO9: QLogic ISP 12160 SCSI; IO10: Vitesse VSC 7174 SATA | `1077:1216`; `1725:7174` | established (`ioc4_variant` tests PCI slot 3) |
| 0 | 4 | gigabit Ethernet | BCM5701 `14e4:1645` on the Origin 350 | inferred for the Altix; no manual names the part |
| 1 (also windows 1 to 4 read, at `W + 0x80_0000`) | 1, 2 | add-in slots | | which window is which slot: unknown; windows 3 and 4 on this bus: nothing known |

The PROM acts on IDs only for the IOC3 and IOC4 (slots 0 to 2; slot 3 or above prints "ERROR: IOC3/IOC4 devices must be located in one of the first 3 slots" and the allocation fails) and QLogic `1077:1240`, `1280`, `1216` (extra response buffers; "Unable to allocated RRBs for qlogic scsi" on failure). Every other device gets generic BAR sizing and interrupt handling. Nothing in the scan is an unbounded poll: the only wait is the 100000-tick lock spin in the protected-read wrapper. The code pins only the SCSI or SATA part (window 3, through Linux) and keeps an IOC4 within windows 1 to 3, so the IOC4 could be in window 1 or 2 and the Ethernet part is wherever is left; the window 1 and 4 rows rest on the Origin 350 capture. Every empty window on both buses (the PROM reads windows 1 to 4 of each) must return all-ones, or end as a recovered machine check; a window that returns zero is a device with vendor 0. An entirely empty bus is accepted: `pic_attach2` fails only on an allocation failure or an unknown ioboard halfword (established for the attach, inferred for the rest of the boot, as in the next section's item 5).

## What a machine model needs from this page

A model that boots the held SN2 kernel needs, in order of how much of it is established:

1. A PIC behind the SHub's I/O link with two buses, the card's four slots (device numbers unknown for the add-in slots)
   and eight interrupt pins whose targets the SAL interrupt call writes.
2. An IOC4 on the PIC's first bus (the guides' "bus 1", PCI bus 0 in the device table) at device 1 with the IDE channel; a SCSI (IO9) or SATA (IO10) controller at device 3. Both are
   established as what the Linux variant test wants. The Ethernet part and its slot are unknown.
3. A console delivered through the SAL console calls, not through an IOC4 UART.
4. An L1 that answers the module type and board reads of device 1 with an IPMI-style area, so the PROM's I/O record
   builds; a failed read is not fatal ("Could not retrieve EEPROM info", the record is emptied).

## What the PROM probes on a one-PIC base I/O card

Board-level reading of the SN2 PROM (snprom 10.54, SHub 1), in boot order. Register-level detail is in
[the SHub I/O interface page](../../devices/shub_ii/README.md#io-discovery-in-main_three-instruction-by-instruction-0xffab38b0) and
[the PIC page](../../devices/pic/README.md#sal-runtime-pic-attach-and-pci-scan-pic_attach2-0xffb6d9c0).

1. **Before "Loading EFI" (`main_three`): no PCI access at all.** The PROM reads the widget id words of widget 0 and of each valid
   link, sets the link and credit registers, and for a link whose id is part `0xd102` resets and initialises each of the PIC's two
   buses through the PIC's own registers (control, direct map, response buffers, LLP configuration, and on bus 0 the interrupt enable,
   reset and host error registers). It never issues a configuration cycle. Unless the L1 brick type is `0x23` or `0x3d`, it pulses the PCI reset pins
   and waits about one second for devices to settle. Established.
2. **At the first I/O SAL call (`0x55` or `0x5f`): the scan.** For each PIC bus the runtime attaches the bridge, then for each
   slot in the bus's range (slots 0 to 1, or 0 to 3 for the bus whose brick-bus word is 1 when the base I/O test holds; established for the
   stores, inferred for which PIC bus that is, see [the PIC page](../../devices/pic/README.md#sal-runtime-pic-attach-and-pci-scan-pic_attach2-0xffb6d9c0)) reads configuration register 0 of function 0. Slot `s` is at window offset `0x21000 + 0x1000 * s`.
3. **What a slot must return.** A present device returns its vendor and device ids. An empty slot may return `0xffffffff` (the
   vendor test `0xffff` skips it) or make the protected read fail (also skipped); neither prints anything. What the PIC does for an
   unclaimed configuration cycle on real hardware is unknown, as is whether the Altix 350 firmware path needs it.
4. **Devices it recognises.** IOC4 (`0x10a9:0x100a`) and IOC3 (`0x10a9:0x0003`) in slots 0 to 2 only; QLogic `0x1077` with device
   `0x1240`, `0x1280` or `0x1216` (the IO9's ISP 12160). Nothing recognises the IO10's Vitesse `0x1725:0x7174`: it is mapped as a
   generic device. A model needs the IOC4 at slot 1 and the SATA controller at slot 3 as the Linux variant test requires
   ([above](#the-io10)); the PROM places no further requirement. Established for the PROM's lack of a Vitesse constant; the
   slot numbers of the add-in slots stay unknown.
5. **No PCI devices at all is not fatal in the code read.** Every slot returns "absent", the attach carries on to the interrupt and
   error set-up, and the SAL calls still return their data with empty device lists. The only aborts in the attach are an allocation
   failure and an ioboard type outside `0x23`, `0x3d`, `0x6d`, `0x6f`, `0x76`. Inferred for the whole scan (the scan driver was read at its
   slot loops, not end to end); the kernel then finds no IOC4 and no disks.
6. **Brick type.** The ioboard type `pic_attach2` tests is the lower-cased type letter of the L1's reply to request `0x0013` (not the KLCONFIG
   board type, not the module word); accepted: `#` `=` `m` `o` `v` (`0x23`, `0x3d`, `0x6d`, `0x6f`, `0x76`). Any other letter, `F` (`0x66`) and `C` (`0x63`)
   included, prints "Unknown ioboard" and abandons the bus after the PIC registers, configuration space and BARs have been programmed
   ([trace](../../devices/pic/README.md#where-the-ioboard-type-comes-from-and-what-an-unaccepted-one-does)). A model must answer `O` to `0x0013`
   and `0x0003` (the PROM lower-cases it). Established for the path; inferred that a real 350's L1 says `O`: the one L1 firmware reading that fits an
   Altix 350 module with an IO10 reports `F`, which this PROM would reject, so a captured reply is still wanted.
7. **BARs.** For every function the PROM writes all-ones to each BAR, reads it back and takes the lowest set bit as the size (I/O `~3`, memory
   `~0xf`, 64-bit BARs skip the next), then writes an allocated base into the BAR and sets command bits 2:0; the expansion ROM is sized with
   `0xfffffffe`, except on IOC3 and IOC4. A model needs ordinary BAR behaviour and nothing device-specific for the IOC4 or the Vitesse controller; the BAR sizes are
   the devices'. Established ([PIC page](../../devices/pic/README.md#bar-sizing-and-window-assignment-0xffb36020-0xffb37520-0xffb37e70)).
8. **Interrupts.** Each device with an interrupt pin gets an irq (first free in `0x3c` to `0xe6`) written to its interrupt-line register, and the PIC
   line is the slot (pins A and C) or slot + 4 (B and D). Connecting a line writes the PIC `+0x120` (line to device), `+0x130 + 8n` (irq in bits
   55:48, address in 47:0) and `+0x108` (enable). The SHub address in that register was not read; the late set-up adds an error interrupt (irq `0x33`) on `+0x38`/`+0x128`. Established
   for the PIC side ([PIC page](../../devices/pic/README.md#interrupt-allocation-and-the-pic-registers-it-writes)).

### Review (what the PROM probes)

Independent re-read on 2026-11-16 of the list above against the Ghidra decompiles of snprom 10.54 (see [the PIC page review](../../devices/pic/README.md#review-sal-runtime-pic-attach-and-pci-scan)). At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.

- Items 1 to 3 and 4 hold: no configuration access before the first I/O SAL call; slot `s` at `0x21000 + 0x1000 * s`; an empty slot is a failed protected read or a low half of `0xffff`; IOC3 and IOC4 in slots 0 to 2 only; the QLogic IDs; no Vitesse constant in the functions read. Item 5 (no devices is not fatal) was read at the slot loops only and stays inferred.
- Item 2's slot ranges are incomplete. Slots 0 to 3 on the second bus need the record field at `+0xbc` to be 1 and `0xffb32470` true; other ioboard types (`0x6d`, `0x76`) have their own ranges (PIC page review).
- Item 6: the byte the PROM tests before the PCI reset (`main_three`) and the halfword `pic_attach2` checks come from different L1 requests (code 3 and `0x13`), the second falling back to the first when the L1 does not support it. So "do both read the same byte" is answered in part: they do when the L1 rejects request `0x13`, which is not settled for a 350. An `F` reply is lower-cased to `0x66`; the KLCONFIG board type that byte maps to is `0x7e`. The advice to answer `o` (`0x6f`) or the IX value `0x3d` stands as a model choice, not a finding.

## What the SHub 1 firmware does per device

Read for this section: `snprom-4.43-44607/boot/efi/snprom.bin` (sha256 `035274812b5065bde3f1b3227a23c05637d8a13f7cab7736ddde4718d46f02eb`),
`snprom-10.40-62478/.../shub1snprom.bin` (`26170cc8...`) by strings, and `snprom-10.54-70399/.../shub1snprom.bin` (`51ccf9ad...`).
Components were cut out by FIT entry and inflated; the 4.43 SAL runtime (FIT type 0x12) was read in Ghidra with its
dynamic symbols (addresses below are runtime link addresses, `rt:`; the Ghidra address adds `0x100000000`), and the 10.54 EFI
(type 0x1f) was decompiled (addresses are the Ghidra export's, as in [the EFI page](../../software/firmware/snprom/efi.md)).
Decompiler output is navigation; every constant below was checked in the function text, and the port table in a byte dump.
Nothing was run.

### Which builds carry the PCI inventory and klconfig builders

- **4.43:** the builders and the PCI scan are in the SAL runtime (`rt:pci_discover` `0x207c0`, `rt:bridge_discover` `0x1ed80`,
  `rt:init_klcfg_tg3` `0x325e0`, `rt:init_klcfg_qscsi` `0x327a0`, `rt:init_klcfg_ioc4` `0x32990`, `rt:ioc4_discover` `0x33050`,
  `rt:kl_init_pci` `0x1f6b0`). Established.
- **10.40:** the same builder strings are in SAL_B, not the runtime (strings only; functions not read). Established as strings.
- **10.54:** SAL_B and the runtime have none of the PCI-device builders (`init_klcfg_tg3`, `_qscsi`, `_ioc4`, `_usb`, `_pcigfx`; the
  node-level `init_klcfg_hub`, `_bridge`, `_cpu`, `_membnk` and `init_klcfg_vgagfx` strings are present) and none of the `GIGENET`, `QLSCSI`, `Tigon3`
  or `IOC4_ATA` strings; the scan is the later `pciio_*` code the PIC page reads. Established as absence of strings in both
  inflated components (the earlier statement that they might sit in the runtime is answered: they do not).

### The 4.43 scan and the typing table (established, read in full)

`bridge_discover` calls `pci_discover` once per PIC bus (bus 1 at the widget base plus `0x800000`) when the part is `0xd102` or
`0xd112` with manufacturer 0x24. `pci_discover` reads the id word of PCI device numbers **4, 3, 2, 1 in that order** (configuration
window `0x20000 + 0x1000 * n`, as in [the table above](#devices-on-the-pics-buses)), prints `%s Widget %x PCI bus %d slot %d pciid %08x`
and picks the record builder by the id word (device in the high half):

| id (vendor:device) | printed name | record built |
|---|---|---|
| `10a9:100a` IOC4 | IOC4 | `ioc4_discover`: `init_klcfg_ioc4` (struct type `0x29`, marks the board's base-I/O flag, calls the base-I/O master election) plus a second record of type `0x2e` "IOC4_ATA", one unit |
| `1077:1216` ISP 12160 | QLSCSI | type `0x25` (SCSI), subtype `0xb`, 2 unit slots |
| `1077:2200` | QLFIBRE | type `0x25`, subtype `0x20`, 1 unit |
| `1725:7174` Vitesse | SATA | type `0x25`, subtype `0x28`, 3 unit slots (why 3 for a four-port part is **unknown**) |
| `14e4:1644`, `14e4:1645`, `14e4:16a7` | GIGENET | `init_klcfg_tg3`: type `0x27` "Tigon3 GigE", PCI revision recorded |
| `11c1:5801`, `11c1:5802` | USB | `init_klcfg_usb` |
| `1002:4e44`, `1002:4e47` | PCI GFX | `init_klcfg_pcigfx` |
| `10a9:0003` IOC3 | IOC3 | generic record |
| anything else | UNKNOWN | generic record, no type |

Every record carries the slot, the PIC bus, the NASID and the PCI revision byte. The type numbers are the PROM's; the names are the strings of its `klcfg` dump command. The PROM has no IO9 or IO10
identity of its own: the card is the set of records the scan produced (IOC4 + ISP 12160 or IOC4 + Vitesse). Established for the
table; the type-number to name map is inferred from the order of the name table beside the dump command.
The only Ethernet ids typed are Broadcom 5700 (`1644`), 5701 (`1645`) and 5703X (`16a7`, the name in Linux 2.6.18 `pci_ids.h`); any other gigabit part prints UNKNOWN and gets no gigabit record.

### Per-device initialisation

For each recognised device `kl_init_pci` (`rt:0x1f6b0`) runs before the record is built (established):

1. Read the PCI command register, write it back with bits 2:1 (memory, bus master) set.
2. In the PIC Device register of the slot (device number minus 1): clear bits 12:0, then set the window offset (bits 11:0, the
   assigned address >> 20) and bit 12. Bit 29 is cleared too when the bridge part is `0xe000` or `0xe010` (not a PIC; irrelevant
   to the Altix 350).
3. Write BAR0 (config `0x10`) with the assigned base. `14e4:1645` and `14e4:16a7` also write the upper half of the address to config `0x14` (a 64-bit
   memory BAR); `1644` takes the plain BAR0 path. The ISP 12160 writes the same base to BAR0 and BAR1 (`0x14`). Other devices only BAR0.
4. **Vitesse only** (not under the simulator signature): write `0x4000` (32-bit) at BAR0 + `0x140 + 0x200 * (n + 1)` for the
   four ports n = 0 to 3 (the registers at offset `0x140` of each port block). Linux's `sata_vsc.c` has no name for that offset
   (its port block is `(n + 1) * 0x200` with task file at `0x00`, DMA at `0x64..0x70` and the SCRs at `0x100..0x108`), so the register's
   role is **unknown**; the value is a fixed constant.

The IOC4 record builder `ioc4_init` (`rt:0x32db0`) first reads config register `0x10` and returns without any set-up when it is already non-zero, then derives the chip's register window from the
bridge's device window (2 MiB windows for devices 1 and 2, 1 MiB for the others; the same derivation `get_pcilink_status` uses) and calls
the routine named in its own assert text `early_ioc4_nvram_init` (`rt:0x32bb0`), which does exactly this and nothing else
(skipped when the processor-id register holds the simulator signature):
PCI command |= 6, latency timer = `0xff`, IOC4 `0x20` <- 0 then |= `0xf`, `0x38` <- 0, `0x30` <- `0x1000f0`. Despite the name, **it touches no
NVRAM, no clock and no byte-bus register** (established, whole function read); the register values are the same ones the
IP35 PROM writes ([IOC4 page](../../devices/ioc4/README.md#what-the-altix-prom-does-to-the-ioc4)).

### IO9 and IO10 differences in the PROM (established as read; interpretation inferred)

| | IO9 | IO10 |
|---|---|---|
| Scan result | IOC4 (+ IOC4_ATA), ISP 12160 as QLSCSI | IOC4 (+ IOC4_ATA), Vitesse as SATA |
| Device-specific init | none beyond BARs; ISP 12160 buffers (10.x), EFI ISP driver ([EFI QLogic page](../../software/firmware/snprom/efi-qlogic.md)) | the `0x4000` writes to the Vitesse per-port `0x140` registers, in the 4.43 runtime and again in the 10.54 EFI (below) |
| Ethernet | Broadcom 5700/5701/5703X typed GIGENET if present | same table; no part named |
| Serial, RTC, NVRAM | none touched by the PROM on either card | same |

### The EFI side (10.54, 4.43 and 10.40 carry the same driver set)

- **Vitesse.** `AltixPciDeviceInit` (`0x285f40`) calls SAL `0x02000057` (the PCI device information call) for every device, gets the
  seven BAR addresses and the interrupt record, reads option-ROM information through config `0x30` (`GetOpRomInfo`, loads an image if one is found) and, outside the simulator, for `1725:7174` at PCI device number 3 writes `0x4000` to BAR0 + `0x200 * i + 0x140`, i = 1 to 4,
  the same writes as the runtime's `kl_init_pci`. Established. (The device-number test confirms slot 3 for the IO10's SATA part.)
- **SATA bus driver** (`SATABusDriverBindingSupported` `0x189b00`): accepts by PCI class 01, subclass 06 only (any vendor); vendor
  `0x1725` prints "Vitesse Serial ATA detected". Start enables PCI attributes `0x700`. Registers are reached with the PCI I/O
  protocol's memory read and write on **BAR 0**, byte, word or dword, from a four-entry table of 16-bit offsets at `0x200dc8`
  (ELF address, 38 bytes per port; port n: base `0x200 * (n + 1)`): task file as Linux, alternate status `+0x28`, device control
  `+0x29`, SStatus `+0x100`, SError `+0x104`, SControl `+0x108`, the `+0x140` register, interrupt status at chip offset 0, mask at 4.
  Established for the table; the role of the offsets follows Linux's names (inferred).
- **Port bring-up** (`DetectSATAController` `0x18c430`): SControl <- 0, wait 100 us, <- 1 (reset), 2 ms, <- 0, 20 ms; then up to 2000 times
  wait 200 us and read the interrupt status dword, taking the port's byte, until bits 1:0 are non-zero (link event); then up to 160000
  times wait 200 us and read alternate status until it is neither `0x7f` nor BSY-set; then `SataIntrClearSError` (`0x18beb0`) maps each
  set bit 6..0 of the port's interrupt byte to a write of a mask to SError (CRC `0x200000`, T `0x100`, P `0x400`, R `0x400000`,
  E `0x800`, M `0x2`, phy change `0x10000`). A model must raise a phy-change or message bit in the port's interrupt byte after
  SControl returns to 0 and present BSY clear, or the 2000-poll loop times out (what the caller does after that timeout was not traced).
  Identify and PIO data use the task-file registers; software reset writes device control `6`, waits 10 us, writes `2`, then waits for BSY clear (`0x18ed40`). No DMA, no interrupt: it polls.
- **IOC4 IDE** is the IO9 and IO10 DVD-ROM/ATAPI path; see [the EFI boot page](../../software/firmware/snprom/efi-boot.md) and
  [the IOC4 ATA page](../../devices/ioc4/ata.md).
- **Ethernet.** The type 0x22 archive carries three drivers: `drv_b57undi64.efi` (Broadcom NetXtreme UNDI, "Copyright (c) 2000-2005
  Broadcom"), `drv_lsisas.efi` (LSI SAS, for the Altix 4700 family) and `drv_fpswa.efi`. The EFI proper has the generic SNP and PXE
  base code and no other network driver (searched for e1000, Realtek, Marvell and Tigon strings in the inflated EFI: none; the only "Intel"
  strings that name a device are the SATA bus driver's, which also prints "Intel Serial ATA detected" for vendor `0x8086`). The
  UNDI driver's table lists the 5700 to 5714 families (`1644`, `1645`, `1646`, `1647`, `1648`, `16a6`, `16a7`, `16a8`, `16c6`, `16c7`,
  `1653`, `1654`, `165d`, `165e`, `1696`, `170d`, `170e`; read as vendor/device pairs in the data table, not decoded entry by entry), so
  it does not pick the card's exact part.

### Ethernet verdict

Both cards' gigabit port is a **Broadcom Tigon 3 family part** (inferred, strongly): the PROM types only Broadcom `1644`, `1645` and
`16a7` as gigabit Ethernet, the only network EFI driver shipped in every SHub 1 build is Broadcom's, the shipped kernel builds `tg3`,
and the Origin 350 IO9 capture has a BCM5701 (`14e4:1645`). Which exact device id the **IO10** carries is **unknown**; nothing in the
firmware distinguishes IO9 from IO10 for Ethernet. A model that presents `14e4:1645` on the IO10 is what every consumer here can
bind to, and is the same model the IO9 needs.

### Not found in the firmware (each is a negative over the images named)

- No PROM access to an IOC4 byte-bus device (NVRAM, time-of-day) on a base I/O card in the 4.43 runtime; the time of day the SAL calls
  return comes from the SHub's real-time counter (`chipset_rtc_time`, `rt:0xe160`, reads `0x81101c0000`) and the system controller
  (`sysctl_time_of_day_set`), not from a card. Established for the 4.43 runtime; not traced for 10.54.
- No serial console on an IOC4 UART (the earlier console section stands).
- The IO9's IOC4 has a **configuration EEPROM** that SGI's `flashioc4` script (held, `snxsc_firmware-1.62.1/usr/sbin/flashioc4`, version
  0.5) reprograms by shifting an SVF file through the system controller to the brick's JTAG chain; the script says it works only for PX and
  IX bricks with an IO9, and that the file's tag is "IOC4 PROM, Rev". Whether an Altix 350's IO9 carries the same part and the same
  JTAG path is **unknown**; no register of the chip depends on it.
- The INTx to PIC pin map: no function among the named 4.43 runtime symbols handles the device-information call `0x02000057` (its handler
  was not found there, not proven absent); the question stays open as in the interrupt section above.

## Open points

Filed in [the base I/O question page](../../questions/altix-base-io-cards.md): the Ethernet controller part and slot on
both cards, the PCI slot numbers of the riser's four slots, the INTx to PIC pin map on the 350, the module type byte an
Altix 350 L1 reports and so which brick name the PROM gives the node, what device 1 is, and where the SAL runtime builds
the per-device records.

## Changes needed outside this page

None to the SHub pages. Two additions to the SAL page, owned by another stream: the console calls' forwarding to the
active console object (`0xffb5c9c0` and the four other thin handlers above), and the master base I/O node rule.

## Review

Independent review of the page at commit `4d01e69`'s tree, by a reader who did not write it. Method: every cited Linux file
re-fetched at v5.3 and read at the cited lines; the guides re-read at the printed pages cited (007-4660-001 pp.99, 100,
104, 105; 007-4660-002 pp.108, 112 to 115; 007-4374-001 pp.1 and 2); the held SNPROM 10.54 build 70399 image re-read in
Ghidra with the repository's IA-64 module (decompiler output taken as navigation, each claim then checked against
constants and strings in the image), with an objdump listing only for the handler at `0xffb60910`; the PROM string
claims re-counted in the 4.43, 10.40 and 10.54 images; the shipped kernel's configuration lines re-read. About 45 facts
sampled.

### Confirmed

- Linux v5.3: `ioc4_variant` (QLogic 0x1077/0x1216 at slot 3 for IO9, Vitesse 0x1725/0x7174 at slot 3 for IO10, else
  PCI-RT); variant values 0x0900, 0x0901, 0x1000; IOC4 0x10a9/0x100a with class mask 0x0b4000; serial and IDE attach
  skip only PCI-RT (`ioc4_serial.c` 2788, `sgiioc4.c` 609); the mode-select pins 4 to 7 for the four UARTs; the Vitesse
  "4 port DPA SATA" comment; qla1280 supporting the 12160.
- Linux v5.3: `L1_BOARDTYPE_BASEIO` 0x0300 and `PCIX3SLOT` 0x0500, `ia64_sn_sysctl_ioboard_get`; SAL ids 0x02000028,
  0x0200002b, 0x0200003c, 0x0200004a, 0x02000056, 0x02000057; operations 1, 2, 3 of the interrupt call; vectors 0x3c to
  0xe6, 0x31, 0x33, 0xe9; ASIC types PIC 2, TIOCP 3, TIOCA 4, TIOCE 5; the PIC offsets (status 0x100, per-pin address
  0x130+8n, error view 0x170, force 0x180 and 0x1c0+8n); `pcibr_target_interrupt` order; `sn_ack_irq` event register and
  alias.
- Guides: IO9 connectors, IOC-4 features, "bus 1 slot 1" and lowest module (-001 p.104, -002 p.114); riser contents and
  the nonstandard connector (-001 p.105, -002 p.115); 133 MHz (-002 p.115); logic diagram (-001 p.99); node-board serial ID
  EEPROM only (-001 p.100, -002 p.108); SATA versus SCSI drives (-002 p.115); IO10 text, 36-pin MDR connector and its
  pinout (007-4374-001 pp.1 and 2). Both -002 p.112 and 007-4374-001 also say the card goes in PCI slot 1, the bottom
  slot, which the page's "lowest slot" already means.
- PROM 10.54: `io_mfg_info` (`0xffaf1ee0`) picks `0xffaeccd0` for an odd NASID and `0xffaecd80` for an even one, which call
  `0xffa84fd0` and `0xffa85550`; masks 0x0ffff000 and 0x4ffff000; device 98 for module type 0x6f; mask rewrite for 0x6d and
  0x6f in `0xffa819c0`; `0xffa85200` is the only caller of `0xffa85120` (device 98); the board area reader `0xffa84990`
  (version, length in 8-byte units with zero an error, language, time, type/length fields, 0xc1 terminator, zero sum);
  `io_baseio_master_nasid_set` selection rule and tie-break; interrupt handler `0xffb1f970` with the provider table and the
  "NULL provider pointer" message; the `rpd` string, the POD menu strings and the string counts in 4.43, 10.40 and 10.54.
- Shipped kernel configuration lines (`TIGON3`, `BLK_DEV_SGIIOC4`, `SCSI_SATA_VITESSE`, `SCSI_QLOGIC_1280` as modules).

### Review (PCI scan and the device table, 2026-11-16)

Independent re-read of the section "Devices on the PIC's buses" against `shub1snprom.bin` 10.54 in Ghidra (IA-64 module, listings checked) and our holdings sources named below; the PIC-side findings are in [the PIC page's review](../../devices/pic/README.md#review-pci-scan-and-the-protected-read).

**Confirmed.**
- The IOC3/IOC4 slot rule: the error string is printed by the bus-address allocator (`0xffb38260`) when the IOC's slot number is 3 or more, and the allocation returns 0 (the message says "Current slot is" slot + 1). The QLogic ids `0x1240`, `0x1280`, `0x1216` get 3 response buffers (`0xffb3ef90` calls `0xffb33880`); a failure only prints.
- Linux `ioc4_variant` (`drivers/misc/ioc4.c`, Linux history tree): QLogic ISP 12160 or Vitesse VSC 7174 on the IOC4's bus at PCI slot 3. `arch/ia64/include/asm/sn/pic.h` (same root) says device `n - 1` is configuration window `n` (windows `0x21000` to `0x24000`, external slots 1 to 4), so slot 3 is window 3. Both rows of window 3 stay established.
- No manual names the Ethernet part or a window. Re-read: *SGI Altix 350 System User's Guide* 007-4660-002 pp.112 and 122 (base I/O options and Table 3-3: only "SATA internal port" and the 36-pin serial connector with the IO10, SCSI ports with the IO9); the IO9 and IO10 pages cited above. The card goes in "PCI slot 1", the riser, which is not a PIC window. The BCM5701 window 4 row stays inferred.
- The only wait in the scan is the 100000-tick (microsecond clock) lock spin in the protected-read wrapper.

**Changed.**
- Bus 1 is also read at windows 1 to 4 (the ioboard-based range of 0 to 1 is applied later); the table and the empty-window rule are corrected.
- Vendor 0 is a present device, not an empty window; an empty window must read all-ones.
- Window 1 for the IOC4 and window 4 for the Ethernet part remain inferred; the code constrains the IOC4 to windows 1 to 3 only.

**Not checked.** Which of the two buses is the "widget 15" bus (the record word `+0xbc` comes from `pci_widget_to_bus`, `0xffb6adb0`, and was not traced); the Ethernet part's behaviour in the PROM (no code is specific to it); that the Altix 350 IO9 repeats the Origin 350 IO9 placement.

### Mechanical fixes (made in this commit)

- The opening sentence said every base compute module carries a base I/O card. The guides require one in the lowest module
  and allow at most one per module (-002 p.112, p.114); reworded.
- Hot plug: the kernel refuses every device number except 1 on segment 1 bus 0 of an IX or IA brick, not "the base card
  slot"; those brick types are not the 350's.
- Console: the spec string is walked `r`, `p`, `d`, not `p`, `r`, `d`; the console object table names all three
  "SysCt (RT)", "SysCt", "SysCt(dir)", so `d` is not the junk-bus UART (that name appears only in the POD menu), and `e`
  ("EfiCB") is in the table but not in the string. Short-answer row changed to match.
- Master base I/O node: the selection compares the module id with bits 15:8 ignored (the mask is `0xffffffffffff00ff`),
  not the low byte; the handler `0xffb60910` returns the word stored by the selection routine (NASID in the low 16 bits,
  module id above), now established from the listing instead of inferred.
- Lost-interrupt workaround: runs only on SHub 1, from each CPU's timer interrupt, once every 100 ticks and over that
  CPU's interrupt range, not once per tick (`timer_interrupt.c`, `SN_LB_INT_WAR_INTERVAL`).
- The bridge discoverer accepts PIC part 0xd112 as well as 0xd102 (manufacturer field 0x24 for both).

### Findings not fixed

- The kernel header says the master base I/O NASID is the call's result, while the PROM handler returns the whole stored
  word (NASID plus module id shifted by 16). Both agree only when the module id field is zero or a reader masks it. No
  caller was found in the files read; settling it needs the SAL runtime or a kernel that calls it.
- "The Altix rule slot 3 agrees with the middle one" of the Origin 350 captures compares a Linux PCI device number with a
  capture's "configuration window", whose offset from the logical device number the IO9 placement question itself leaves
  open. The agreement is weaker than the page's wording; it stays inferred.
- The `p` probe at `0xffae9200` only tests that the PROM is not running under a simulator and records a value; nothing
  read ties "SysCt" to a particular UART. "Console on the system controller" rests on the object names and the Altix 350
  page, not on a traced UART access.
- The riser-EEPROM paragraph still ends where the evidence does: no riser EEPROM is named by any guide or read by the
  PROM, and the symbol placement for `sysctl_eeprom_io_riser` (runtime symbol to image address) was not re-derived; the
  call-graph part (`0xffa85120` has one caller, device 98) was.

### Cleared scope

The page's wiring and identity claims at the grade given in the table above, with the corrections in this section: IO9 and
IO10 contents by the Linux variant test and the guides; the PIC-behind-riser layout; the board record format; the base I/O
node selection rule; the interrupt chain from the PIC pin to the SAL allocator. Not cleared: the Ethernet part and slots,
the INTx to pin map, and anything in the compressed SAL runtime, none of which was read.

### Review (PIC attach items 6 to 8, commit 043c9f6)

Item 6 holds with one correction: the PROM also passes `m` and `v`, and the ARM L1 answers `0x0013` for a single-slot `F` brick with the plain letter `F`, which is rejected (details in the PIC page's review). Item 7: only the IOC3 stops after its first BAR; the IOC4 does not. Item 8: the pin rule and registers re-read and confirmed.

### Review (what the SHub 1 firmware does per device, 2026-11-21)

Independent review by a reviewer who did not write the section, of chips commit 80f1819. Method: the 4.43 SAL runtime
(sha256 `03527481...`) and the 10.54 EFI (`51ccf9ad...` image, type `0x1f` component) decompiled in Ghidra, each constant
checked in the function text; the 10.40 and 10.54 components cut out by FIT entry, inflated and scanned for strings; the
SATA port table at ELF address `0x200dc8` dumped from the inflated 10.54 EFI and decoded; Linux v2.6.18 `ioc4.c`,
`sata_vsc.c`, `pci_ids.h`; `flashioc4` re-read.

- **Confirmed.** `pci_discover` scans device numbers 4, 3, 2, 1; every row of the id table (record type, subtype, unit count,
  `IOC4_ATA` type `0x2e` built through `init_klcfg_qscsi`); `kl_init_pci` steps 1 to 4 including the upper-half write to
  config `0x14` for `1645` and `16a7` only, the ISP 12160's two BAR writes, and the Vitesse `0x4000` write at
  `0x140 + 0x200 * n` for n = 1 to 4 (skipped on the simulator signature); `early_ioc4_nvram_init`'s register writes and
  that it touches nothing else; the 10.54 EFI `AltixPciDeviceInit` write (BAR 0, 32-bit, device 3, function 0) and the
  `DetectSATAController` sequence and `SataIntrClearSError` masks; the SATA port table; no Vitesse or PCI-device builder
  strings anywhere in 10.54, and the 10.40 builder strings in the SAL_B component; the three-driver archive (Broadcom UNDI,
  LSI SAS, FPSWA) in all three builds; `chipset_rtc_time` and `flashioc4`.
- **Fixed.** The 10.54 bullet said none of the `init_klcfg_*` strings are present; the node-level ones (`hub`, `bridge`, `cpu`,
  `membnk`, `vgagfx`) are, and only the PCI-device builders are absent.
- **Fixed.** `16a7` is Broadcom 5703X in Linux 2.6.18 `pci_ids.h`, not "5703C"; `1644` is 5700 and `1645` is 5701.
- **Fixed.** The EFI "no Intel strings" search was wrong as written: the SATA bus driver prints "Intel Serial ATA detected"
  for vendor `0x8086`. No Intel network driver strings exist.
- **Added.** `ioc4_init` returns without the PCI set-up when config register `0x10` is already non-zero.
- **Not re-checked.** The ISP 12160 buffer set-up in 10.x, the "slots 0 to 2 only" IOC4 rule in 10.40 and 10.54 (an earlier
  review item), the microsecond unit of the EFI stall calls, and the 4.43 and 10.40 EFI driver set beyond the SATA string.
  The Vitesse write in the runtime is addressed through the bridge window that the BAR 0 write also uses; it is read as
  "BAR 0 plus offset", which is inferred equality.
- **Not changed.** The Ethernet verdict ("Tigon 3 family, inferred") follows from the typed ids and the shipped driver; it is a
  reasonable inference, and the exact IO10 id stays unknown.
