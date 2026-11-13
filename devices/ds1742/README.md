# DS1742W nonvolatile timekeeping RAM (Fuel L1)

The DS1742W is a 3.3 V, 2,048-byte battery-backed SRAM with a clock, identified on a revision B Fuel
board by its package marking. The register facts the sources state are in `devices/ds1742/registers.toml`, and
the generated reference is `devices/ds1742/registers.md`. This page holds what that unit does not carry.

Each fact carries one label. **Established** means the manufacturer specification states it, as the
source records it. **Inferred** means a public driver, a board marking or a reasoned reading of one
supports it. **Unknown** means the sources do not settle it, with the route that would. No fact here
was measured on a board.

## Sources

- **Maxim (Analog Devices) DS1742 Y2KC nonvolatile timekeeping RAM datasheet**, document 19-6715,
  Rev 6/13. Its ordering table (p. 1) lists the DS1742W-120 at 3.3 V. Page numbers below are the printed
  pages, which equal the PDF pages: pin list p. 2, read and write of the clock p. 3 to 4, register map
  (Table 2) p. 5.
- **John Hartley, "SGI NVRAM & Time Keeper Chips"** (web.archive.org snapshot of
  just.graphica.com.au/tips/sgi-nvram, 2024-12-24) and **IRIXNet thread 2535** (posts 1 and 3). Both
  describe the Fuel's DS1742W-120 as the L1's own NVRAM and clock.
- **OpenBSD `sys/arch/sgi/dev/dsrtc.c`**, lines 124 to 133, at commit
  `2df91d80c104636deeef8124252ddd5951b55fbf`.
- **Photographs of a Fuel IP34 board** (Hartley's article). A detail view, SHA-256
  `2fd4b83b1da20b51026f67c39072da55548b219ac8b18a6b8f0b05cf11084450`, shows the `DALLAS DS1742W-120
  Timekeeping RAM` package marking beside the "IP34 Assy" legend. The board revision is not readable in
  that view; the whole-board revision B photograph is SHA-256
  `db5249da27cf48739c8e72ac3d850a1eaff6ce97be105d67eed75727155a0a3a`.

## Package and pins (established)

- Eleven address pins, A0 to A10, select one of 2,048 bytes.
- Eight data pins.
- Active-low chip enable, output enable and write enable.
- No DMA request and no interrupt output.
- No external reset input that clears stored RAM or the clock.

## Clock and calendar (established, with a gap)

- The clock occupies the top eight bytes of the chip, offsets `0x7f8` to `0x7ff` (datasheet p. 2 and
  Table 2, p. 5). The register entry records the offsets only. Table 2 gives the layout, in BCD:

  | Offset | Content |
  |---|---|
  | `0x7f8` | Control: bit 7 W (write), bit 6 R (read freeze), bits 5 to 0 century, 00 to 39 |
  | `0x7f9` | Seconds 00 to 59; bit 7 OSC (oscillator stop) |
  | `0x7fa` | Minutes 00 to 59 |
  | `0x7fb` | Hours 00 to 23 |
  | `0x7fc` | Day 01 to 07; bit 7 BF (battery flag), bit 6 FT (frequency test) |
  | `0x7fd` | Date 01 to 31 |
  | `0x7fe` | Month 01 to 12 |
  | `0x7ff` | Year 00 to 99 |

- Leap-year compensation is stated valid up to the year 2100 (p. 1), and the century register runs
  00 to 39 (Table 2).
- Read freeze: R must stay clear for at least 500 microseconds to ensure the visible registers
  update, and updating catches up within a second of R being cleared (p. 3). W set halts updates for
  loading and takes effect when W is written clear (p. 4).
- The datasheet states no factory RAM image, checksum, serial number or initial calendar value, and
  says the lithium cell is disconnected until power is first applied (p. 1). The reset state of the
  clock and RAM is therefore unknown.

## Fuel use (inferred)

- **Fuel L1 storage and clock.** Hartley's article says the L1 has its own NVRAM and clock in the
  DS1742W-120, and thread 2535 reports dumping, copying and clearing the chip and watching the L1's
  log and serial number follow it. Inferred: no capture of the L1's bus traffic was read.
- **OpenBSD labels the part.** The `dsrtc` driver reports a `DS1742W` on Fuel and gives it a software
  address. Inferred: the driver's own comment calls its IOC3 mapping a guess.
- **Package marking.** The detail photograph shows a `DS1742W-120` package on an IP34
  board. Inferred: this establishes the marking on that board only, not the address wiring or behaviour on other
  revisions.

## Open questions

- **The system Timekeeper on Fuel.** Public evidence supports a separate system Timekeeper, distinct
  from the L1 part. Its part and its connection through IOC3 are **unknown**. Route: a Fuel board
  schematic, or a revision-specific measurement with its provenance recorded. The
  [system Timekeeper page](../../platforms/ip34/system-timekeeper.md) has the driver's byte map and year base.
- **Address decode of the IOC3 path.** OpenBSD addresses its presumed Fuel system clock through IOC3
  byte-bus select 0 at the top of a 32 KiB window, offsets `0x7ff8` to `0x7fff`. The part has only
  eleven address pins, so those offsets would fall at chip offsets `0x7f8` to `0x7ff` if the board
  wired the low eleven byte-bus lines straight through. If it did, the 2 KiB chip would mirror every
  `0x800` bytes. That wiring is **unknown**. A board schematic, a published byte-bus trace or a
  revision-specific measurement would settle it. The OpenBSD mapping alone is not enough to choose
  a mirror or a 32 KiB window.
- **Reset state.** The clock and RAM reset values are **unknown**. Route: a measured read on a
  revision-specific board after an agreed read-only plan.
