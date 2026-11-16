# IP35 PROM 6.210: reading the time-of-day clock

Scope. The BASEIO (I/O) PROM monitor inside `ip35prom.img` 6.210 (gzip ELF at image offset `0x8cbb0`, linked at
`0xc000000013000000`), read in Ghidra as a flat image and checked against the disassembly. Addresses are monitor
addresses. Grades: established (routine read in full), inferred, unknown.

## Established

- `0xc000000013040560` (`cpu_get_tod`, named by its own message strings, 800 bytes) is the only routine in this
  monitor that touches the clock. It fills a time record for its caller (`0xc0000000130a6abc` returns it; the ARCS-style
  time call and the elapsed-seconds helper `0xc0000000130d2f9c` use it). The monitor has no clock writer: the cached base and layout words are used only by the probe and `cpu_get_tod`,
  and neither stores a time field; its only related string is `fixme: cpu_update_nvram`. The monitor does store control
  bytes: the probe writes bytes `0xb` and 6, a layout 1 read writes `0x7ff8` and a layout 2 read writes `0xb`.
- The base is `0x80000` above the register base of an IOC the monitor finds in the configuration data. One lookup
  routine is tried first (`0xc0000000130dcc6c`), then a second (`0xc0000000130dcc24`); the code names neither chip, so
  which is the IOC3 and which the IOC4 is inferred from the order of the words in the error text. Neither found: it prints `Did not find an IOC3 or IOC4 NVRAM base address`. The
  first use (`0xc000000013040510`) writes 0 to byte `0xb`, `0xff` to byte 6, then `0x80` to byte `0xb`. Byte 6 reading
  back `0xff` selects layout 1, anything else layout 2. The probe runs for whichever IOC was found; unlike the kernel,
  the monitor has no IOC4 shortcut.
- Layout 1: byte `0x7ff8` gets `0x40` (freeze), BCD year `0x7fff`, month `0x7ffe`, date `0x7ffd`, hours `0x7ffb`, minutes
  `0x7ffa`, seconds `0x7ff9`, then `0x7ff8` gets 0. Layout 2: byte `0xb` gets 0, BCD seconds, minutes, hours, date,
  month, year at bytes 1, 2, 4, 8, 9, `0xa`, then `0xb` gets `0x80`. Fields are decoded as high nibble times 10 plus low nibble,
  with no range check.
- Year arithmetic: the BCD year plus `0x7b2` (1970), in both layouts. No century byte is read and no leap rule is
  applied; the record holds a full year and the seconds helper does its own calendar sum.

## Inferred

- The I-brick's 32 KB NVRAM test range makes layout 1 the likelier one on IO7 (see Review); the part is still unnamed.
- Layout 1 is the Mostek M48T35 / Dallas DS1742 family map (control byte, clock in the top eight bytes of the part).
- Layout 2 matches the Dallas DS1286 register map: seconds at 1, minutes 2, hours 4, date 8, month 9, year `0xa`, command
  register at `0xb` whose bit 7 is the transfer-enable bit. The match is by offsets only; no name appears in the PROM.

## Unknown

- Which layout the I-brick IO7 uses: the monitor probes at run time, so the code does not say. The part on IO7 is
  therefore **unknown** from this PROM.
- The 1970 base here disagrees with the 1968 base IRIX uses for the same bytes
  (the kudzu repository's `software/kernel/ip35-tod-clock.md` has the IRIX side): a clock IRIX
  set reads two years later in the monitor. The two callers of the time routine (`0xc0000000130a6fdc`,
  `0xc0000000130d2fa4`) were not read, so what the monitor does with the value is unknown.

## Review

Independent re-read of the PROM 6.210 I/O monitor (gzip ELF at image offset `0x8cbb0`), Ghidra (flat load, decompile of
`0xc000000013040560` and `0xc000000013040510`) cross-checked with a full MIPS disassembly. Confirmed: `cpu_get_tod` adds
`0x7b2` (1970) to the BCD year in both layouts; both layouts' offsets and the probe order (0 to byte `0xb`, `0xff` to
byte 6, `0x80` to byte `0xb`, then read byte 6) match; no century byte is read; no routine stores a time field.

Changed: the base routines are described by what the code does, not as named IOC3 and IOC4 windows; the control-byte
stores are listed; the claim that the two year bases never collide was removed (callers not read); a typo fixed.

- IO7 carries an IOC3. established: SGI's I/O diagnostics guide 108-0264-004 (printed p. 2-5) says the IO7 test covers
  the I-brick board's "IOC3, USB, and IEEE 1394" parts, and the Origin 3000 Series Technical Configuration Owner's Guide
  007-4311-002 Figure 3-12 (printed p. 29) groups "Ethernet", "Serial" and "TOD/NVRAM" on the I-brick board. The figure's
  text layer carries no chip name, so the figure alone does not name the IOC. No IOC4 is named for IO7 (the IOC4 appears
  on the Origin 350 and Tezro boards).
- Layout on IO7: inferred, weak. The same guide (printed p. 2-7) lists an NVRAM test range `0x7fd1` to `0x7ff7` for IO7.
  That range ends just below layout 1's freeze byte `0x7ff8`; layout 2 puts its command register at byte `0xb`. The
  probe itself was never observed on an I-brick.
- Part: **unknown**. Library searches for the chip found no source that names it on IO7: "IO7", "007-4653" (the
  Origin 3900 guide: no parts list), "M48T35", "DS1742", "DS1286", "DS1687" and "timekeeper" over the techpubs,
  irix-mirrors, irix-artifacts and origami-docs roots; "I-brick battery real-time clock IO7 replace" and "I-brick NVRAM
  time of day clock battery" over techpubs (no hits); "field replaceable unit I-brick" and "030-1557" (the I-brick board
  part prefix; only Origami's own notes). The M48T35 and DS1742 hits are about the Origin 200, the Origin 350's IOC4 and
  the Origami models, not IO7. M48T35 and DS1742 share layout 1, so the layout cannot tell them apart.
