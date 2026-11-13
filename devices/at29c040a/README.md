# AT29C040A: byte-load program cycle, polling and block locks

Status: transcribed from the published Atmel datasheet. Not yet checked against the PDF. Chips holds no
register contract for this part. Two published O2 board photographs show it at U203 (inferred; see
[o2-prom-rom.md](../../platforms/ip32/prom-rom.md)). The base board note in [baseio.md](../baseio/README.md) records an AMD AM29LV800B
on a different board instead.

Source: Atmel, *AT29C040A: 4-megabit (512K x 8), 5-volt only, 256-byte sector Flash Memory*, revision
`0333I-FLASH-05/02`, 17 pages. Page numbers are printed pages, which match the PDF pages.

## Byte-load program cycle (established, p. 2)

- Data is latched one byte at a time. A8 to A18 select the sector and A0 to A7 select the byte position
  inside it. Positions may be loaded in any order.
- Loading ends when no new byte load starts within 150 microseconds of the last one. Internal control then
  erases and programs the sector, which frees the external bus.
- The text gives no separate rule that waits for 256 distinct bytes before programming starts.

## Polling during a program cycle (established, pp. 3 and 11)

- The last loaded byte reads back with I/O7 complemented.
- Repeated reads at a fixed address toggle I/O6 until the cycle completes. The level of the first and last
  toggle is not fixed.
- Page 3 defines a protected write without the unlock prefix as a polling cycle that changes no array byte.

## Block protection (established, p. 4)

- The first and last 16 KiB blocks each have their own lock. A locked block is protected from erase and
  programming.

## Unloaded positions in a partial load (unknown)

- Page 2 says a byte that is not loaded erases to `0xff`.
- Page 9 waveform note 3 calls an unloaded byte indeterminate.
- Page 10 repeats that warning for the software-protected waveform and says all 256 bytes must be loaded in
  its protection algorithms.

The datasheet therefore gives no single guaranteed result for a sector that is only partly loaded. A
measurement on a physical part, or a later revision of the datasheet that resolves the contradiction,
would settle it.

## Completion time and part grades (established, pp. 2, 9, 13)

- The write cycle completes within 10 milliseconds of the final byte load (pp. 2 and 9).
- The ordering table identifies `AT29C040A-12TC` (120 ns) and `AT29C040A-15TC` (150 ns) as commercial TSOP parts
  (p. 13).

## Software data protection (established, transcribed)

- Enable: before a sector load, write `0xaa` to `0x5555`, `0x55` to `0x2aaa` and `0xa0` to `0x5555`, using
  address bits A14 to A0. Once enabled, protection survives power transitions. The page of this prefix is not
  recorded in this import. Page 3 says a protected write without the command sequence still polls and leaves
  the data unchanged.
- Disable: write `0xaa` to `0x5555`, `0x55` to `0x2aaa`, `0x80` to `0x5555`, `0xaa` to `0x5555`, `0x55` to
  `0x2aaa` and `0x20` to `0x5555`, then a sector load (p. 10).

## Software identification (established, transcribed)

- Enter: write `0xaa` to `0x5555`, `0x55` to `0x2aaa` and `0x90` to `0x5555`, then wait 10 milliseconds (pp. 5
  and 12).
- Reads at `0x00000` and `0x00001` return manufacturer `0x1f` and device `0xa4`.
- Exit: write `0xf0` to `0x5555`, then wait 10 milliseconds (pp. 5 and 12).
- The board photographs do not show this mode or its use on an O2.

## Chip erase (unknown)

- Atmel calls chip erase an optional six-byte command and refers its details to a separate application note
  (p. 3). This datasheet does not give the sequence, so none is recorded here.
