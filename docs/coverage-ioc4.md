# IOC4 coverage

What the shipped software and the public drivers settle about the IOC4, and what stays open. Register tables and the
per-routine readings are on [the chip page](../chips/ioc4/README.md); this page grades the coverage questions that were
open. Labels follow [AGENTS.md](../AGENTS.md): **established**, **inferred**, **unknown**.

Sources: IRIX 6.5.30 IP35 objects `ioc4.o`, `sio_ioc4.o` (a member of `sduart.a`) and `ide.o`, read in full where a
routine is cited. A shipped development header of the IRIX 6.5.30 media (`usr/include/sys/PCI`) was read for the role of
one register and for the DMA control bits; it is cited as provenance only and nothing from it is copied. Public: the Linux
IOC4 driver files `include/linux/ioc4.h`, `drivers/misc/ioc4.c`, `drivers/ide/sgiioc4.c` and
`drivers/serial/ioc4_serial.c` (a 2.6.33-era history tree, merge commit `981a2edd1922`, and the out-of-tree Linux IP35 port
branch of 2015 for its `drivers/rtc/rtc-ioc4.c`). A driver is a driver author's naming, not a measurement.

## Settled by this pass

### `0x24`: a PCI bus speed field (inferred)

The attach routine clears bits 3:0 of this register when the chip is revision 79 or later and the bus-information
routine reports speed value 1 (the chip page reads that value as conventional PCI with the bridge speed field 0). The
shipped development header names the register a miscellaneous control register and defines one field in it: bits 3:0
are the PCI bus speed, 0 for 33 MHz and 1 for 66 MHz. The Linux register structure leaves the word unnamed.
Reading the two together: the clear programs the 33 MHz setting when the bridge reports a 33 MHz conventional bus.
That is **inferred**: the role comes from a header's naming, and the code's condition is consistent with it, but no
shipped string says so.
**Still unknown:** why the clear is gated on revision 79, what values 2 to 15 mean, and whether the chip leaves the
field alone when it is already 0.
Test that would settle it: on a revision below 79 and one at or above, read `0x24` after reset on a 33 MHz bus and on a
66 MHz bus; then write 1 and 0 with the bus at 33 MHz and watch the serial and ATA timing.

### The ATA DMA block `0x140 + 4n` (roles now established by a public driver; a header and the code agree)

The chip page graded these roles inferred from what the IRIX routines write. The Linux IDE driver names every word, and the
IRIX accesses match it word for word. Roles, all **established** (public driver file, with the IRIX access pattern in
`xide_pktDMA_start` `0x2d30` and `xide_pktDMA_complete` `0x30ac` as independent agreement):

| index | offset | role | what IRIX does |
|---:|---|---|---|
| 0 | `0x140` | timing | not touched on this chip by any IP35 `ide.o` routine |
| 1, 2 | `0x144`, `0x148` | address of the DMA list, low and high halves | `xide_pktDMA_start` writes the low 32 bits then the high 32 bits of the 64-bit address held at request +32 |
| 3, 4 | `0x14c`, `0x150` | current memory address, low and high | not touched on this chip |
| 5, 6 | `0x154`, `0x158` | byte count at the device and byte count at memory | `xide_pktDMA_complete` reads both and prints them |
| 7 | `0x15c` | control and status | below |
| 8 | `0x160` | address of the end-of-transfer area | `xide_pktDMA_start` clears 128 bytes at controller +392 and writes the 32-bit word at +388 here |

The correction to the chip page is the "table" in index 8. Linux allocates a 128-byte area, clears it, writes its bus
address here, and after a transfer polls it until the engine has written non-zero data into it; its comment says the engine
writes ones there to show the previous data DMA is finished, because register reads and DMA writes can be reordered. The
128 bytes equal the cache line the driver allocates. So index 8 is not a second descriptor table: it is a completion
flag area, and the IRIX code that clears 128 bytes before arming is the same pattern. What IRIX does after the transfer
with that area was not read (`xide_pktDMA_complete` does not poll it), so whether IRIX relies on it is **unknown**.
Linux describes each list entry as 16 bytes: a 64-bit address entry and a 64-bit entry holding a 16-bit byte count and an
end-of-list bit (bit 31), both big-endian; the IRIX list builder was not read, so that layout is **established as a
driver's statement** only.

### DMA control register `0x15c`, bits (established by agreement)

| bit | role | IRIX access |
|---:|---|---|
| 0 | start | `xide_pktDMA_start` ORs it with the direction bit and writes the result in one store at the end (Linux writes the direction first and sets start later) |
| 1 | stop | `xide_pktDMA_start` and `xide_pktDMA_complete` write 2, then poll it clear up to 100 times |
| 2 | direction: 1 copies ATA data to memory | `xide_pktDMA_start` writes 4 when bit 0 of a halfword in the record at request +144 is set, 0 otherwise |
| 3 | channel active | `xide_pktDMA_start` reads index 7 first; if bit 3 is set it stops the engine before arming |
| 4 | the engine met a PCI error | `xide_pktDMA_start` writes 2 when it is set; the same bit is the read-back in `xide_pktDMA_complete` |

The IRIX bit meanings follow from the tests the code makes, read in full; the names come from the Linux driver and the
header, which agree with each other. The direction convention (what IRIX's flag means for a read or a write) rests on
the Linux driver's comments and was not independently derived from the IRIX request structure: **inferred**.

### Interrupt and error words

- Other-interrupt bits: 0 ATA interrupt pass-through, 1 ATA DMA error, 2 to 5 serial port 0 to 3 DMA error, 6 keyboard and
  mouse, 23 real-time output pulse, 24 to 31 generic pins (Linux's field widths give the layout; IRIX's `ioc4_eiattach`
  writes the real-time and generic-pin bits and `xide_intr_clear` tests bits 1:0): **established** for the bits IRIX
  tests, **established as a driver's statement** for the rest.
- Error address low word, bits 4:1 name the requester: serial ports 0 to 3 are values 0 to 7 (even is the transmit side,
  odd the receive side), the ATA controller is 8. **Established as a driver's statement.** IRIX's serial error handler
  reads the port from bits 4:2 and RX or TX from bit 1 (chip page), the same split as the driver's four-bit field.
  **A disagreement the chip page did not have:** `xide_intr_clear` (`ide.o` `0x1634`) tests the masked word
  `(low & 0x1e) == 8` for its "ATA Error" line. Linux's table gives ATA as 8 in the four-bit field, which masks to `0x10`,
  not 8; a masked value of 8 is field value 4, serial port 2 transmit. Only a debug line depends on it. Which is right
  is **unknown**. Test: provoke an ATA DMA PCI error (a deliberately unmapped list address) and read the error address low
  word.
- Serial control `0x20`: Linux's fields are bits 3:0 byte-bus strobe width, bits 6:4 current PCI requester, bit 7 no
  serial request pending, bit 8 no ATA request pending, bit 9 the ATA request won. IRIX's attach stores `0xf` (the widest
  strobe, **inferred** from the field's width) and `hardware_init` polls bit 7. **Established** for the polled bit.

### Serial transceiver select (established)

`ioc4_set_proto` (`sio_ioc4.o` `0x33c4`, read in full) writes 0 or 1 to a general-purpose pin register whose index is a
byte kept in the port's record. The Linux serial driver writes 0 for RS-232 and 1 for RS-422 to pins 4, 5, 6 and 7 for
ports 0 to 3; the direction bits for those pins sit at `0x10`, `0x20`, `0x40` and `0x80` in the pin-direction field. The
IRIX per-port byte is static data and was not extracted, so the pin numbers on the IRIX side are **inferred** equal.

### The byte bus, the 8-bit window (public driver only)

The Linux IP35 port branch maps a 128 KB window at `0x80000` ("byte bus 0") on the IO9-variant board and reads a
real-time clock at offsets `0x7ff8` to `0x7fff` of it, with a control byte (`0x40` latch for read, `0x80` for write) and
BCD time fields, addressed with the low two address bits inverted (the same lane inversion the IOC3 serial ports show;
see [coverage-ioc3.md](coverage-ioc3.md)). The IOC4 census has no row between `0x400` and the configuration window, so
no IRIX access reaches the window. Whether the part's byte bus is used on the Origin 300 base I/O board at all is
**unknown**; the Linux branch restricts the attach to the IO9 variant. Valid end state: no shipped software read here
depends on it.

## Still open

| item | route | discriminating test |
|---|---|---|
| Reset values of every register | none from software: no routine reads one before writing it | read all of `0x0` to `0x160` immediately after a PCI reset, before any driver runs |
| Why `0x24` is gated on revision 79 | a published IOC4 erratum | see above |
| Whether IRIX waits on the end-of-transfer area | read `xide_pktDMA_complete`'s callers | trace a packet DMA on a model and check whether the guest reads the 128 bytes |
| Per-port pin and record tables (`ioc4_set_proto` pin byte, serial configuration records) | extract the data section through its relocations | none needed once extracted |
| `ioc4_error_handler`, `ioc4_intr`, `ioc4_intrd` | read in full: software work, not done here | n/a |
