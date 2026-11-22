# Crimson (IP17) PROM 4.0.3: what the reading left open

Question. What did the reading of the Crimson PROM leave unsettled? The settled parts are on
[the PROM software page](../platforms/ip17/prom-software.md); the byte-order survey is
[byte-order.md](../software/firmware/byte-order.md).

Status: **unknown** for everything below. Where a route is named it is the shortest one I can see.

- **Little-endian boot to the monitor.** Whether the PROM, started with the CPU little-endian, reaches the monitor prompt and loads a
  little-endian program on a real board. The listing shows no halt or restart; an emulated run (ROM words kept as words, UART status
  forced ready, the CPU-speed routine at `0xbfc22410` stubbed) reached the secondary-cache tag-clearing loop at `0xbfc0cebc` in both
  byte orders and stayed there. Route: a Crimson set to little-endian with `e2endian little` and a serial capture; or a model of the CPU
  board that answers the timer, the `e2` byte at offset `0x80`, and the cache set-up.
- **The byte stored to `0xbd800007`.** What setting bits 31 to 24 of the system-bus status word does, and whether it enables
  little-endian I/O or clears a flag. No code reads it back and no big-endian code writes that register. Route: the Crimson CPU-board
  documentation (not held), or the IRIX kernel for IP17 if one can be added to the holdings.
- **How the hardware samples the `e2` bit.** The PROM only writes and prints the bit at `0xbfe00000` byte 0, bit 2. That it reaches the
  CPU's byte-order strap at the next reset is inferred. Route: the same schematic, or an owner test: set the bit, power-cycle, run
  `endian`.
- **The part behind `0xbfe00000`.** Byte 0 is written without any ready check; byte `0x80` holds `0xba` on machines with a 4 MB
  secondary cache (inferred from the code, not from a manual). Whether the store is a non-volatile part, and what else lives at other
  offsets, is not read.
- **The IO3B test.** Bit 0 of the byte at `0xb7fffff4`, read without a lane swizzle in little-endian mode only. Which polarity means
  "IO3B present" is inferred from the warning's wording; the register is in no table.
- **Pointers in `0xa08xxxxx`.** The string routines treat a pointer whose top twelve bits are `0xa08` like a ROM pointer and read it
  with the `xor 3` lane rule. What lives at physical 8 MB that is laid out like the ROM image was not found.
- **Real effect of the lane-unswizzled ROM reads.** The password encoder reads its key and digit tables with plain byte loads, a network
  checksum switch at `0xbfc46190` is read as a plain byte, and five halfword loads at `0xbfc3fe94` and a byte load at `0xbfc3fe10` do
  the same. The consequences stated on the software page are inferred; a run of `passwd` in both byte orders would settle the first.
- **I/O bus lanes in little-endian mode.** Whether DMA data (SCSI, Ethernet) is byte-reversed in little-endian mode and whether the
  network byte-order helpers at `0xbfc0f718` to `0xbfc0f7d8` are the only compensation.
- **Memory above 512 MB.** The size register can encode up to 1216 MB, but every address the PROM forms is in the 512 MB KSEG0 and
  KSEG1 windows; whether the hardware populates and decodes more is unknown.
- **The memory-status flags and the id field.** The `Mpsr` line prints bits 5 to 9 beside the size; their meanings are not read.
- **The second I/O-board block.** The `0xb7b` copy of the 30-entry register table, and the two units per board that
  `0xbfc0bad4` selects, are inferred from index arithmetic only. The roles of most of the 30 table entries are not read.
- **The `0xbe400000` block.** Thirty-odd 32-bit registers touched by one diagnostic cluster at `0xbfc072a4`; no name or test tied to it.
- **Unused cache sizer.** The tag-probing routine at `0xbfc0c978` has no caller; whether anything reaches it indirectly was not
  checked beyond a search for its address as data.
- **Jump slots.** The roles of the slots at `0x08`, `0x10`, `0x20`, `0x28`, `0x110`, `0x200`, `0x300`, `0x380` of the reset vector table
  were not traced.
- **The console variable.** The values `d`, `r` and `a` of `console` and what the graphics path does beyond the probe at `0xb7000000`.
