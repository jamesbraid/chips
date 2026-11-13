# DS1744 nonvolatile timekeeping SRAM

The DS1744 is a 32 KiB byte-wide battery-backed SRAM with a clock in its top eight bytes. The
register facts the sources state are in `devices/ds1744/registers.toml`, and the generated reference is
`devices/ds1744/registers.md`. This page holds what that unit does not carry.

Each fact carries one label. **Established** means the manufacturer specification states it, as the
source records it. **Inferred** means arithmetic on an established fact. **Unknown** means the sources
do not settle it, with the route that would. No fact here was measured on a board.

## Sources

- **Analog Devices/Maxim DS1744 nonvolatile timekeeping SRAM datasheet**, document 19-5502, revision
  6/13, 16 pages. A later verification pass re-read it in full. Page numbers are the datasheet's own
  "n of 16" numbers: the package and pin list are on pages 1 to 3, the clock reads on page 4 and the register
  map (Table 2) on page 6.

## Package and interface (established)

- The DS1744 comes in a 28-pin encapsulated package. The DS1744P comes in a 34-pin PowerCap module
  with a separate battery-and-crystal PowerCap.
- Both expose the same byte-wide memory and clock interface.
- Fifteen address inputs select one of 32,768 bytes.
- No DMA request and no interrupt output. The pinout and the register map show no interrupt register.

## Clock and calendar (established, with a gap)

- The clock occupies the top eight bytes of the chip (page 1, page 3). The defs entry records those
  positions only. Table 2 (page 6) gives the order: `0x7ff8` century with the read bit `R` in bit 6 and
  the write bit `W` in bit 7, `0x7ff9` seconds with the oscillator stop bit `OSC` in bit 7, `0x7ffa` minutes,
  `0x7ffb` hours, `0x7ffc` day, `0x7ffd` date, `0x7ffe` month, `0x7fff` year. The values are BCD in 24-hour form
  (page 3).
- The day register, at `0x7ffc`, carries a battery voltage-level flag in bit 7, `BF`, and a frequency test
  bit `FT` in bit 6 (Table 2, page 6).
- The valid date range and leap-year rule are in the calendar section of the specification. They are
  not transcribed here.

## Retention and reset (established)

- The specification advertises over ten years of operation without external power (page 1), and gives the life expectancy as 10 years at 25 C with the oscillator running (page 7), from the
  battery. The part ships with its lithium source disconnected, and the source is enabled when `VCC`
  first rises above the power-fail point (page 7).
- The part carries no factory image, checksum, serial number or initial calendar value. The reset
  state of the clock and RAM is therefore unknown.

## Read freeze (established)

- The read freeze bit `R` must stay clear for at least 500 microseconds to guarantee that the visible
  image refreshes, and the image then catches up within one second (page 4).

## IO9 board (unknown)

The sources do not say which IO9 board revision fitted this part, or how the board wires the part in.
These questions are open:

- **Fitted package and revision.** Unknown. Route: a board schematic, or a revision-specific board
  photograph with its marking read.
- **Address wiring.** Whether all fifteen address inputs connect directly to the bus is unknown. Route:
  a board schematic or a published byte-bus trace.
- **Address decode and aliases.** The decode the board applies to the part, and any aliases it creates
  inside the byte-bus space, are unknown. Route: the same schematic or trace as above.
- **Contents at power-up.** Fresh physical SRAM and calendar contents are unknown. Route: a measured read
  after an agreed read-only plan on a revision-specific board.

These unknowns must not be filled from the DS1744 specification alone, or from how a guest's software
reads the part.

## Sibling parts

- The DS1742W, a 2 KiB part in the same family, is described in [DS1742W](../ds1742/README.md). Its clock sits
  at the top eight bytes of its own 2 KiB array and its package and pins differ.
