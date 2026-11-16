# IP35 PROM 6.210: reading the time-of-day clock

Scope. The BASEIO (I/O) PROM monitor inside `ip35prom.img` 6.210 (gzip ELF at image offset `0x8cbb0`, linked at
`0xc000000013000000`), read in Ghidra as a flat image and checked against the disassembly. Addresses are monitor
addresses. Grades: established (routine read in full), inferred, unknown.

## Established

- `0xc000000013040560` (`cpu_get_tod`, named by its own message strings, 800 bytes) is the only routine in this
  monitor that touches the clock. It fills a time record for its caller (`0xc0000000130a6abc` returns it; the ARCS-style
  time call and the elapsed-seconds helper `0xc0000000130d2f9c` use it). The monitor has no clock writer: a search for
  stores to the clock bytes found none,; its only related string is `fixme: cpu_update_nvram`.
- The base is `0x80000` from the start of the IOC3's external-bus window, tried first (`0xc0000000130dcc6c`), then
  the IOC4's (`0xc0000000130dcc24`). Neither found: it prints `Did not find an IOC3 or IOC4 NVRAM base address`. The
  first use (`0xc000000013040510`) writes 0 to byte `0xb`, `0xff` to byte 6, then `0x80` to byte `0xb`. Byte 6 reading
  back `0xff` selects layout 1, anything else layout 2.
- Layout 1: byte `0x7ff8` gets `0x40` (freeze), BCD year `0x7fff`, month `0x7ffe`, date `0x7ffd`, hours `0x7ffb`, minutes
  `0x7ffa`, seconds `0x7ff9`, then `0x7ff8` gets 0. Layout 2: byte `0xb` gets 0, BCD seconds, minutes, hours, date,
  month, year at bytes 1, 2, 4, 8, 9, `0xa`, then `0xb` gets `0x80`. Fields are decoded as high nibble times 10 plus low nibble,
  with no range check.
- Year arithmetic: the BCD year plus `0x7b2` (1970), in both layouts. No century byte is read and no leap rule is
  applied; the record holds a full year and the seconds helper does its own calendar sum.

## Inferred

- Layout 1 is the Mostek M48T35 / Dallas DS1742 family map (control byte, clock in the top eight bytes of the part).
- Layout 2 matches the Dallas DS1286 register map: seconds at 1, minutes 2, hours 4, date 8, month 9, year `0xa`, command
  register at `0xb` whose bit 7 is the transfer-enable bit. The match is by offsets only; no name appears in the PROM.

## Unknown

- Which layout the I-brick IO7 uses: the monitor probes at run time, so the code does not say. The part on IO7 is
  therefore **unknown** from this PROM.
- The 1970 base here disagrees with the 1968 base IRIX uses for the same bytes
  (see the IRIX side note in the kudzu repository, `software/kernel/ip35-tod-clock.md`).
  The PROM only displays or differences the time, so the two do not collide in a boot.
