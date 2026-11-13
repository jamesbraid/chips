# DS1744 nonvolatile timekeeping SRAM

The DS1744 is a 32 KiB byte-wide battery-backed SRAM with a clock in its top eight bytes. The
register facts the sources state are in `devices/ds1744/registers.toml`, and the generated reference is
`devices/ds1744/registers.md`. This page holds what that unit does not carry.

Each fact carries one label. **Established** means the manufacturer specification states it, as the
source records it. **Inferred** means arithmetic on an established fact. **Unknown** means the sources
do not settle it, with the route that would. No fact here was measured on a board.

## Sources

- **Analog Devices/Maxim DS1744 nonvolatile timekeeping SRAM datasheet**, document 19-5502, revision
  6/13, 16 pages. The page and table references below are not recorded in this import; the document
  was not opened for this import.

## Package and interface (established)

- The DS1744 comes in a 28-pin encapsulated package. The DS1744P comes in a 34-pin PowerCap module
  with a separate battery-and-crystal PowerCap.
- Both expose the same byte-wide memory and clock interface.
- Fifteen address inputs select one of 32,768 bytes.
- No DMA request and no interrupt output. The pinout and the register map show no interrupt register.

## Clock and calendar (established, with a gap)

- The clock occupies the top eight bytes of the chip. The defs entry records those positions only.
  The byte order and bit meanings are not given here, and this import did not read the chip's register
  page for them.
- The day register carries a battery voltage-level flag in bit 7, `BF`. The register table lists it.
  The byte offset of the day register is not in this import's sources.
- The valid date range and leap-year rule are in the calendar section of the specification. They are
  not transcribed here.

## Retention and reset (established)

- The specification advertises more than ten years of operation without external power, from the
  battery.
- The part carries no factory image, checksum, serial number or initial calendar value. The reset
  state of the clock and RAM is therefore unknown.

## Read freeze (established)

- The read freeze bit `R` must stay clear for at least 500 microseconds to guarantee that the visible
  image refreshes, and the image then catches up within one second.

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
