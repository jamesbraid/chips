# Altix I/O cross-check questions

Open points from reading SGI's Altix Linux code (linux-5.3 pin 4d856f72c10e) against the PIC, IOC4 and TIO pages.
Each entry: question, routes tried, next route. Route tag in brackets.

## IOC4 error master id

[missing source] The IOC4 error address low word carries a master field in bits 4:1. SGI's Linux header
(`include/linux/ioc4.h`, `master_id`) numbers it 0 and 1 for serial port 0 TX and RX, up to 6 and 7 for port 3, and 8
for ATA. The IRIX reading in [devices/ioc4/README.md](../devices/ioc4/README.md) takes bits 4:2 as the port and bit 1 as
the word, which agrees for serial ports, but tests `(low & 0x1e) == 8` for an ATA error. In the Linux table 8 in that
field is `(low & 0x1e) == 0x10`; `(low & 0x1e) == 8` is serial port 2 TX. Also unchecked: the IRIX message builds the
port character from "twice the value in bits 4:2", which for port numbers 0 to 3 gives characters 1, 3, 5, 7 rather than 1 to 4.
Routes tried: both sources read. Next: re-read `ioc4_dma_error_intr` and `xide_intr_clear` against the mask constants
and the character arithmetic; a captured error word would settle the field.

## PIC 32-bit register writes

[software now] SGI's PIC header says the chip does not accept a write of only bits 31:0 of a 64-bit register
(erratum PV854697; software always writes all 64 bits). The IP35 PROM's bridge diagnostic and its interrupt-clearing
routine make 32-bit stores to the low word of PIC registers ([devices/pic/README.md](../devices/pic/README.md)), and the
Linux flush path stores a 32-bit 1 to a firmware-supplied force address. Either those paths run only on other bridge
chips or at revisions without the erratum, or the erratum is narrower than the header says. Next: find which
chip type and revision each PROM routine runs on; the erratum text names no revision.

## PIC versus TIO by product

[missing source] Which Altix models carry a PIC behind a SHub widget, which carry a TIO with a TIOCP, TIOCA or TIOCE,
and which carry the TIO FPGA port (TIOCX) is not stated by any SGI Linux file read; the code distinguishes by NASID parity
and by the type the firmware reports.

What is settled for the Altix 350 (Altix 350 System User's Guide 007-4660-002, printed pages 72 and 73): a base compute
module holds one SHub, one or two Itanium 2 processors, four PCI/PCI-X slots, and a factory-installed base I/O PCI card in the
lowest slot; the card has a real-time interrupt input and output, an Ethernet port, and either serial (IO10) or SCSI
(IO9). The pages read here give only the serial and SCSI split and do not say which board is standard (not checked beyond them). The guide does not name the bridge behind the four slots. SGI's Linux code supports both a PIC and a TIOCP there, so which the 350 uses is **unknown**.

What the Linux driver says about the boards ([IOC4 page](../devices/ioc4/README.md)): the master driver names IO9
(IOC4 plus a QLogic ISP12160 SCSI controller at slot 3 of the same bus), IO10 (IOC4 plus a Vitesse VSC7174 serial-ATA controller at slot 3) and
PCI-RT (IOC4 alone). So an IO10 carries an IOC4: the IO10 serial port and the real-time interrupt pins are IOC4 functions. The
IO9 is the board the Origin 350 also carries (the IOC4 page records its use there). Whether the IO10's IOC4 runs behind a PIC or a
TIOCP follows the bridge question above and is unknown.

Not read for I/O topology: Altix 3000 (007-4579-001), 3700 Bx2 (007-4377-002), 330 (007-4790-001), 4700 (007-4823-001) and
the IX-brick and PX-brick pages ([ixbrick](../platforms/bricks/ixbrick.md), [pxbrick](../platforms/bricks/pxbrick.md) already
tie the PIC to those bricks from the 3000 and Bx2 guides). A search of the Linux mail archive for TIOCP and Altix 350 returned nothing.
Next: the chapter on the base compute module in the 350 guide, and the 4700 guide's blade I/O sections.

## TIO chiplet field

[missing source] The SGI address header says the chiplet field of a TIO address is 0 for `LB` (MMR access) and 1 for `ICE`
(coretalk space). The kernel's TIO MMR accessor on SHub2 sets chiplet 1 for every MMR (identification word at an `LB`-looking
offset included), while the widget small windows it uses are built with chiplet 0. Either the comment names the chiplets the
other way round, or "MMR" and "coretalk" mean something finer than registers versus widgets. Next: a TIO register
specification, or the SHub2 TIO address macros in a later SGI tree.

## TIOCA AGP DMA extension overlap

[missing source] In the TIOCA header, `ca_agp_dma_addr_extn` has a 16-bit node-id field at bits 35:20 and a one-bit "PIO memory type" at bit 28 inside it, while a
comment says bits 27:26 are unused. The 48-bit direct AGP path compares the field with the target's upper node bits (at most 64, so seven bits). Either the node-id field
is narrower than the header says or the PIO memory type bit lives elsewhere. Next: a TIOCA register specification.

## TIOCE M40S window

[missing source] The TIOCE provider gives the 40-bit super-page mappings the bus window `0x8000000000` to `0xffffffffff` (512 GiB) but allocates 32 entries per port of 16 GiB and
computes the bus address as the window base plus the global entry index times 16 GiB. For port 2 (entries 32 to 63) that is at or past the end of the window. Either the window is
larger than the constants say, port 2 maps differently, or the allocation is wrong for port 2. Next: a TIOCE register specification.
