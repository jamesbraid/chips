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

[missing source] Which Altix models carry a PIC behind a SHub widget, which carry a TIO with a TIOCP, TIOCA or TIOCE, and
which carry the TIO FPGA port (TIOCX) is not stated by any SGI Linux file read; the code distinguishes by NASID parity
and by the type the firmware reports. The Library holds the Altix user's guides (007-4579-001, 007-4377-002, 007-4660-001,
007-4790-001, 007-4823-001) but its search does not index their text and none has been read for I/O topology. A search
of the Linux mail archive for TIOCP and Altix 350 returned nothing. Next: read the I/O blade and brick sections of those guides.
