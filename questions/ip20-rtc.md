# Indigo real-time clock: what the clock page leaves open

Question. What do the Indigo's clock part and its wiring do where the held sources stop? The settled parts are on
[the clock page](../devices/dp8573a/README.md).

Status: **unknown** for everything below.

- **The part number and crystal.** The software contract is the DP8573A's; whether the board carries an 8572A or 8573A is not stated by any held
  file. Route: a board photograph or parts list. Hardware residue: none beyond reading the package.
- **Whether the chip's interrupt output reaches INT2.** Software writes the power-fail enable and never the periodic enables; no handler for a clock
  interrupt is registered in the IP20 kernel object. Route: the IP12 kernel, a schematic, or a boot capture that shows INT2 local 1 bit 5 moving at power loss.
- **Reads of the four unused slots (`0x3f` to `0x4b`), the two-bit register 13 and the upper 24 bits of a word read.** Route: none in software;
  hardware residue (a read of unwritten registers on a board, which needs agreement first).
- **Power-up contents of interrupt control 0 and the periodic flag test bit.** The data sheet says random. Route: a capture from a flat-battery board.
- **Whether PROM 4.0.5G changes the clock-read routine.** 4.0.5D repeats the motion test and its two messages on every call when the clock does not move; the public source of the later library routine gives up after six. The image 070-8116-005 was not available. Route: that image.
- **IP12 kernel and PROM.** The 4.0.1C PROM shows the same register sequence at `0xbfc0b80c`; its routine was not read in full, and the IP12 kernel was not read.
