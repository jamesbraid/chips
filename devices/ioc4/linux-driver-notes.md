# IOC4: what the SGI Linux drivers add

Source: SGI-written Linux IOC4 support at tag v5.3 (the last tree that still carries it): `include/linux/ioc4.h`,
`drivers/misc/ioc4.c`, `drivers/tty/serial/ioc4_serial.c`, `drivers/ide/sgiioc4.c`. These are SGI's own platform code for the
IA-64 machines, so a layout they define is **established** by [AGENTS.md](../../AGENTS.md). Field tables are in
[registers-extra.md](registers-extra.md). Everything here is a driver's view: it shows what software does and expects, not
what the chip does when software does something else.

## Interrupts

- Two status words (`0x8` serial, `0xc` other), each with an enable-set and an enable-clear word. Status bits are raised by the
  source and cleared by writing a 1 to the bit. Enables are set and cleared by writing a 1; writing 0 changes nothing (established
  by use: the driver masks one port's bits without disturbing the others).
- Serial word: one byte per port, eight sources (see `SIO_IR_PORT_WORD`). Other word: bit 0 ATA interrupt, bit 1 ATA DMA error,
  bits 5:2 serial DMA error, bit 6 keyboard and mouse, bit 23 external interrupt output latch, bits 31:24 generic pins.
- No single read says an enabled interrupt is pending: the handler reads the status and the enable word and ANDs them under a
  lock, because an enable change between the two reads would hide a pending source. The ATA bits are left to the IDE driver
  when both drivers share the interrupt line.
- Handler pattern: on an interrupt, the top level masks the sources it owns by writing the enable-clear word, runs the handler,
  and the handler writes the enable-set word back with its saved mask. Level sources (receive high-water, transmit empty) cannot
  be acknowledged by a write and are masked until the ring is serviced.
- The driver reset path masks and acknowledges everything: all ones to both enable-clear words, then all ones to both status
  words (`ioc4_probe`). Reset values of these registers: **unknown**.

## Error capture

A PCI error during ring or ATA DMA latches the address (`0x0`, `0x4`) and raises the matching bit in the other status word; the
unit's DMA is halted. `master_id` names the unit. Software acknowledges the status bit first, then reads the address. The ATA
path also reads the PCI command word and writes `0x146` back to it (parity and system error reporting plus master and memory
enable) to clear the error indicator. The bit 5 multiple-error flag is read-only information. What the chip does with a second
error while the valid bit is still set: **unknown**.

## Arbitration and bus clock

- `0x20`: software writes 15 to the strobe width at attach. After a serial reset it polls bit 7 until no serial port holds a
  request. The requester field names the granted unit.
- The PCI clock is measured, not read: the driver programs the external interrupt output in toggle mode with count 63, watches
  bit 31 of `0x28` for rising edges and times 256 cycles against the host clock. One count is 520 PCI clocks, so the period is
  2 x 64 x 520 clocks. A result outside 25 to 75 MHz is replaced by an assumed 66 MHz. The serial driver then picks the UART
  input clock as 66.67 MHz when the period per PCI clock is under 20 ns, else 33.33 MHz, and computes divisors as
  (clock + 8 x baud) / (16 x baud). (established as driver behaviour; the 1/16000 s receive timer unit is stated in the header.)
- Board variant is found by looking for another device on the same PCI bus at slot 3 (a dual SCSI controller means one base I/O
  board, a SATA controller another, neither means a PCI card without ATA). The chip itself has no variant register.
  The serial driver reads a halfword at configuration offset 8 (the Linux constant it passes, PCI_COMMAND_SPECIAL, has that
  value) and requires 62 or more; the IDE driver reads the standard revision byte, at the same offset, and requires 46 or more.
  The driver calls the value a firmware revision, so the revision byte is a firmware revision (established as the driver's
  naming; the IRIX attach comparison against 79 is on the same byte, see [README.md](README.md)).

## Serial ring DMA

- Registers: ring base pairs for ports 0/1 (`0x300`, `0x304`) and 2/3 (`0x308`, `0x30c`); then seven words per port (control,
  transmit producer, transmit consumer, receive producer, receive consumer, receive timer, shadow). The UART registers follow at
  `0x380`, eight bytes per port.
- One 16 KB block (four 4 KB rings; 4 KB selected by base bit 0) per port pair, aligned to its own size, ordered transmit of the
  even port, receive of the even port, transmit of the odd port, receive of the odd port. 1 KB rings are a build option in the driver
  (size bit 0), unused by default.
- Entry: eight bytes, four data bytes then four status or control bytes, one per data byte (`RX_STATUS_BYTE_WORD`,
  `TX_CONTROL_BYTE_WORD`). The software producer on transmit and the chip producer on receive advance in whole entries.
- Transmit: software fills entries, setting each byte's control to valid (and `int_when_done` on one entry near the end of the
  ring), turns on DMA enable, then writes the producer. A ring with the consumer one entry ahead of the producer is full. The
  chip reports empty with the transmit-empty interrupt; the driver turns DMA off then if no receive is wanted.
- Receive: bytes collect in the chip until four arrive or the receive timer expires, then one entry is written and the producer
  moves. The timer starts only on the first byte after it is armed (consumer write with bit 31). Bytes left in the collector when
  the ring looks empty are flushed with the drain bit; the driver ignores the flush when any entry is already present, because
  with fewer than two free entries the drain would never complete. The producer can advance before entry data lands, so software
  checks the valid bits in each entry and backs off if none is set.
- Reset sequence (`port_init`): write reset, poll `0x20` bit 7, write 0, reload the cached pointers from the chip (transmit
  producer := transmit consumer, receive consumer := receive producer), program the UART, write the ring base (high word first),
  set the 10 ms timer and the threshold, enable DMA.
- Pause: set pause, poll pause state before touching UART line control or modem control; writing the saved control word clears pause.

**Unknown:** what happens to an entry in flight when DMA enable clears; whether the chip rewrites status bytes already
cleared by software; the receive-full interrupt (defined, never used); reset values of every port register.

## ATA

- The command block is eight task-file registers, one per 32-bit slot at `0x100`; the control block is at `0x120`; the DMA block
  at `0x140` (word indices as in [coverage.md](coverage.md)). Only one drive channel exists.
- Start: write the scatter list address to word 1 (low half; the driver writes no high half), clear the 128-byte end-of-transfer
  area and write its bus address to word 8, write the direction to word 7, program the drive command, then set start in word 7.
- Scatter entry: 16 bytes, big endian: zero, address, zero, length with bit 31 marking the last entry. The driver splits entries
  at 64 KB address boundaries and the table holds one fourth of a page of entries (256 on a 16 KB page, 64 on a 4 KB page).
- End: write stop, poll until it reads back clear, then wait for the chip to write non-zero data into the end area, because a
  register read can overtake the last DMA write. The IRIX driver does the same ([coverage.md](coverage.md)). The two byte
  counts (words 5 and 6) are compared; a difference of more than 8 is reported.
- Interrupt: status bits 0 and 1 of the other word (drive interrupt, DMA error). Reading the ATA status register while the drive
  is not busy clears the bits as a side effect when set (the driver writes 3 to the status word and rereads it); this makes the
  status read an interrupt acknowledge. At attach the driver writes 3 to the other enable-set word to enable both sources.
- The driver restricts the drive to multiword DMA mode 2 and ignores timing, so word 0 is never written.

**Unknown:** the meaning and reset value of word 0 (timing), the current-address words (3, 4), whether the high list-address word
must be written, what a length of 0x10000 means in a 16-bit field, and behaviour on a list that lacks the last-entry flag.

## Keyboard, mouse and generic pins

Pin 3 senses a keyboard and mouse connection; pins 0 and 1 are the external interrupt output and input; pins 4 to 7 select
RS-232 or RS-422. Direction bits are set through the set alias at `0x30`. The serial driver writes direction for pins 4 to 7 and
the clock calibration for pin 0. Edge mode value meanings and the keyboard controller are covered in [README.md](README.md).
