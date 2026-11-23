# National Semiconductor PC87307 Super I/O (marked NS87307) as wired in the Visual Workstation 320 and 540

Mode: **spec-backed**. The datasheet is held (see [documents](../../platforms/visws/documents.md)): *PC87307/PC97307 Plug and
Play Compatible PC97 SuperI/O*, National Semiconductor, Preliminary, March 1998, 218 pages; page numbers below are printed
pages, which equal file pages. The two parts it covers differ in the identification register and a stepping register. The
board's documents call the chip the NS87307; reading that as the PC87307 is inferred from the shared number. Registers:
[registers.md](registers.md) (111 registers). The board is in [platforms/visws](../../platforms/visws/README.md).

**Grades** as on the [PIIX4 page](../piix4/README.md): *established* is a datasheet page or a shipped routine read in
full (the latter a **software expectation**, not a measurement); *inferred* is a reasoned reading; *unknown* is not settled.
Reset values are the datasheet's; none was read from a board.

## Configuration protocol (established, pp.24-27)

The part is configured through an index port and a data port. Two strap pins choose how it wakes. With the base address
straps at 11 it is in Plug and Play motherboard mode: index port 0x2e, data port 0x2f, both read/write, and it wakes in the
Config state, so no key sequence is needed. Other straps give 0x15c and 0x15d, or full Plug and Play ISA mode with the
write-only ports 0x279 and 0xa79. The PROM, the HAL and Linux write 0x2e and 0x2f directly, so the board uses the
motherboard mode (software expectation). A write selects a register by index, the data port then reads or writes it, a read
of the index port returns the last index, and reserved bits are kept, so software uses read-modify-write. Index 0x07 selects
a logical device and then indexes 0x30 to 0xff address that device. Index 0x02 bit 0 is the soft reset.

## The nine logical devices

| No. | Device | Register space | Board use |
|---|---|---|---|
| 0 | Keyboard controller | `ld0_*` | the PROM activates it; the HAL selects it to steer IRQ 1; the board's keyboard controller may be this one (inferred from the PIIX4's XBCS write) |
| 1 | Mouse controller | `ld1_*` | the HAL selects it to steer IRQ 12 |
| 2 | Real-time clock and advanced power control | `ld2_*` | the PROM activates it; which clock the board uses is unknown |
| 3 | Floppy disk controller | `ld3_*` | PROM activates it; floppy recovery; the HAL steers IRQ 6 |
| 4 | Parallel port | `ld4_*` | PROM activates it; its ARC tree puts the port at 0x378 |
| 5 | Second UART with infrared | `ld5_*` | COM2 at 0x2f8, IRQ 3 (the reset values), the firmware's second serial port |
| 6 | First UART | `ld6_*` | COM1 at 0x3f8, IRQ 4 (the reset values): the PROM's serial console, 9600 8N1 |
| 7 | General-purpose I/O | `ld7_*`, `p1_*`, `p2_*` | base 0xfc0; its data byte carries the board revision |
| 8 | Power management | `ld8_*`, `fer1`, `fer2`, `pmc*`, `wd*` | base 0xfc8 |

Each logical device has the standard Plug and Play registers (activate at 0x30, I/O range check at 0x31, base address at 0x60
and 0x61, interrupt select at 0x70, interrupt type at 0x71, two DMA selects at 0x74 and 0x75) with per-device reset values
and read-only bits, and a few device-specific configuration registers at 0xf0 and 0xf1 (Tables 2-12 to 2-20, pp.30-34). A
device is active only while its activate bit and its function enable bit in the power management block are both set (FER1
for devices 0 and 2 to 6, FER2 bit 7 for the GPIO ports); a hard reset sets both function enable registers to 0xff.

## What the firmware, the HAL and Linux do to it

Sources: [boot-path.md](../../software/visws/boot-path.md), [nt-hal.md](../../software/visws/nt-hal.md),
[boot-and-detection](../../platforms/visws/boot-and-detection.md).

- **Boot block, set-up step for the Super I/O.** Twenty-six index and data writes through 0x2e and 0x2f activate logical
  devices 0 to 8, put the GPIO block at 0xfc0 and the power management block at 0xfc8, and end by writing function enable
  register 2 with bit 7 set. The step's count is established; the individual values of the writes are not decoded. The self-test activates the UARTs again.
- **Linux.** Selects device 7, writes the base 0xfc0 to 0x60 and 0x61 and 1 to 0x30; selects device 8 the same way with
  0xfc8; writes `fer2` bit 7 (the comment says it enables the GPIO registers); reads the GPIO data byte and keeps seven
  bits as the board revision (below 6 is revision 4, below 12 revision 5, otherwise 6 on a 320; the 540 is always 2). The
  2.2 kernel also writes the interrupt select of device 6 on a 320 revision 5 board.
- **HAL.** `Ns307InitChip` reads the GPIO and power management bases back through devices 7 and 8, and the interrupt steering
  routine selects device 0, 5, 6, 3, 4 or 1 and writes bits 0 (level) and 1 (polarity) of the interrupt type register for
  IRQs 1, 3, 4, 6, 7 and 12. It does so only on the no-8259 route table and the 540 revision 0 table.
- **PROM, serial.** UART 1 is the PROM's console and UART 2 its second port, both 16550 compatible, initialised with line
  control 0x80, divisor (12 for 9600), line control 3, interrupt enable 0, modem control 3 and FIFO control 7.

## Board wiring

- **GPIO at 0xfc0.** The block's data byte `p1_data`. The low seven bits are the board revision per Linux and the PROM; the
  registry export of one 320 reports 0x11. That pins carry the revision is the software's reading; the wiring is unknown.
- **Power management at 0xfc8.** The firmware and Linux write only `fer2`; the watchdog and the clock controls are not
  touched by held software.
- **Legacy interrupts.** The UARTs, floppy and parallel port reach the processors through the PIIX4's 8259 pair and Cobalt
  entry 12 ([PIIX4 page](../piix4/README.md)), except where the HAL's no-8259 table steers an interrupt directly through
  the interrupt type register.

## Where sources disagree or say more than the datasheet

- **Parallel port base.** The reset base is 0x278, but the PROM's ARC configuration tree names the port at 0x378, so the PROM's
  configuration step must write the base (inferred, since the 26 writes are not decoded). The floppy controller's 0x3f2 and the
  UARTs' 0x3f8 and 0x2f8 match the reset values.
- **The second UART is used.** The PROM's second serial port is the device 5 UART at 0x2f8, IRQ 3 (software expectation).
- **Identification split (`sid`).** Chip identification in bits 7:5 and revision in 4:0 holds for the PC87307 (Figure 2-1,
  p.34); for the PC97307 the whole byte, 0xcf, is the identification (Figure 2-2).
- **Printed values.** Table 2-12 prints the keyboard command base low byte as "64", read here as 0x64; the watchdog status text
  in Section 9.1.2 says bit 1 while the register description and bitmap say bit 0 (this unit uses bit 0); the function enable
  register 2 text marks the cleared state of bit 7 as the default while the register table and bitmap reset it to 1 (the
  sibling PC87317 datasheet resets the same bit to 1); the UART configuration register resets to 0x02 in Sections 2.8.1 and
  2.9.1 and to 0x00 in the bitmap summary on p.42 (this unit takes 0x02).

## Unknowns

- PC87307 or PC97307 on the board (the identification and stepping registers would say).
- The strap settings: CFG0 (whether devices 0, 2 and 3 wake active), CFG1, CFG3 and CFG2, SELCS.
- The values of the PROM's 26 configuration writes beyond the activation, the two bases and the final function enable write.
- Which keyboard controller and clock the board uses: this part's or a separate one.
- What the floppy controller's drives are, and which status registers software reads.
- What the board connects to the chip selects, the watchdog output and the multiplexed pins.
- The wiring of the GPIO pins that carry the board revision, and what the pull-up and output type bits are set to.
