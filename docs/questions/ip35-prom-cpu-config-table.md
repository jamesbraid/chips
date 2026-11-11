# IP35 PROM: the processor speed table, what feeds it, and what it cannot describe

Question. The IP35 boot PROM carries a table of processor configuration words with CPU and hub clocks. Does it, or
its board-name tables, hold an entry for a 1 GHz R16000 (the part on IP59 boards)? If not, what decides the
configuration word for a part the table lacks? Which socket masks does the PROM allow per product name?

Short answer.

- No. Neither PROM 6.210 nor PROM 6.211 has a 1 GHz row, a 1 GHz clock constant, or any word that fixes a 1 GHz
  configuration. The table's fastest row is 900 MHz. The table is reached only through a 4-bit code from the processor
  module's power-supply-controller register, and every code that selects an R16000 row is already taken or unmapped
  in a way that leaves no slot for 1 GHz. The table therefore cannot describe an IP59 module.
- For a part outside the table the PROM takes the configuration word from three other places, none of which is the
  speed table: the 80-byte configuration record flashed in the node's boot flash (the only source the PROM acts on
  before RAM exists), the node board's EEPROM text record (`CpuCfg0Reg`, `CpuSpeed`, `HubSpeed`), and the live CP0
  Config register of the processor it is running on. The table is the last-resort fallback behind the EEPROM record.
  The L1 system controller plays no part in choosing the word.
- The six product-name rows (`IP53_*CPU`, `IP59_*CPU`) are a separate table of socket masks `0x0f`, `0x05`, `0x01`.
  They carry no clock.

Sources. The shipped IP35 PROM, SGI Version 6.210 (built Aug 26 2004), container segment `ip35prom`, load address
0xc00000001fc00000, length 0x1686a8; unpacked segment sha256
`554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`. The shipped IP35 PROM, SGI Version 6.211 (built
Jan 25 2008, from IRIX 6.5.30 patch 7208), unpacked segment sha256
`25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271`. The BaseIO image carried in the 6.210 container
(sha256 `f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7`, load address 0xc000000013000000).
Offsets below are offsets into the unpacked segment; address = 0x1fc00000 + offset for the CPU PROM. Method:
disassembly with `capstone` and byte searches over the segments; nothing was run. Field names (`SysClkDiv`,
`SCClkDiv`, `SCSize`, tap) are those of the MIPS R10000 Microprocessor User's Manual, version 2.0 (Config register mode
bits). The PROM's printers confirm tap (bits 28:25 plus bit 22 as bit 4), cache size (bits 18:16) and cache clock
(`SCClkDiv`, bits 21:19); the position of `SysClkDiv` (bits 12:9) is the manual's, and is supported here by the fit
below, not by a PROM printer. How the PROM image is unpacked: [ip35-reset-window.md](ip35-reset-window.md).

## The table

Established (both PROMs; table read in full).

- Selector: 64 signed 32-bit words at 6.210 offset 0x151f20 (address 0x1fd51f20). `-1` means no row.
- Rows: 29 rows of 16 bytes at 6.210 offset 0x152020 (address 0x1fd52020), row n at `0x152020 + 16 n`. A row is
  the configuration word (big-endian 32 bits), the CPU clock in Hz, the hub clock in Hz, then four bytes of which
  byte 13 is a machine-type byte (0, 1 or 2). In 6.211 the same 29 rows sit at offset 0x151fc0 (0x60 lower); the
  selector table is 0x60 lower too. The rows are byte-identical between the two PROMs. The BaseIO image holds two
  more identical copies, at image offsets 0x11f2b8 and 0x164590.
- Row use: `0x1fc1f3a0` reads the board register at `0x9000000034000000 + (NASID << 33)`, takes bits 15:12 as a class
  and builds a selector index: class `0x2000` gives 0x30 + low nibble, `0x4000` gives 0x20 + low nibble, `0x8000`
  gives 0x10 + low byte, anything else the first of the two low nibbles that is not `0xf` (from the low nibble up).
  A found row is copied into an 80-byte record: record +0 gets 0x15, +4 the word, +0x10 the CPU clock, +0x18 the hub
  clock, +0x28 gets 1, +0x2c, +0x30 and +0x3c get row bytes 12, 13 and 14, +0x34 gets 0.
- The three R16000 rows named in the question are at 6.210 offsets 0x1521c0 (row 26, 700 MHz, word `0x589bad85`),
  0x152160 (row 20, 800 MHz, `0x549baf85`) and 0x1521e0 (row 28, 900 MHz, `0x569cb185`). In 6.211 they are at
  0x152160, 0x152100 and 0x152180.

| Row | 6.210 offset | Word | CPU MHz | Cache | Tap | SysClkDiv | Reached by board-register code |
|---|---|---|---|---|---|---|---|
| 0 | 0x152020 | `0x5219a785` | 400 | 1 MB | 0x9 | 3 | none |
| 1 | 0x152030 | `0x1213a785` | 200 | 4 MB | 0x9 | 3 | low-nibble path 0xe |
| 2 | 0x152040 | `0x5413a785` | 400 | 4 MB | 0xa | 3 | low-nibble path 0x0 |
| 3 | 0x152050 | `0x549ca985` | 500 | 8 MB | 0xa | 4 | low-nibble path 0x1, 0x6 |
| 4 | 0x152060 | `0x5414a785` | 400 | 8 MB | 0xa | 3 | low-nibble path 0x2 |
| 5 | 0x152070 | `0x5213a785` | 360 | 4 MB | 0x9 | 3 | low-nibble path 0x8 |
| 6 | 0x152080 | `0x5412a785` | 400 | 2 MB | 0xa | 3 | 0x8000 + 0 |
| 7 | 0x152090 | `0x549aa985` | 500 | 2 MB | 0xa | 4 | 0x8000 + 1, 2 |
| 8 | 0x1520a0 | `0x549cab85` | 600 | 8 MB | 0xa | 5 | low-nibble path 0x3 |
| 9 | 0x1520b0 | `0x549aa985` | 500 | 2 MB | 0xa | 4 | 0x4000 + 4, 6 |
| 10 | 0x1520c0 | `0x569cad85` | 700 | 8 MB | 0xb | 6 | low-nibble path 0x4 |
| 11 | 0x1520d0 | `0x569caf85` | 800 | 8 MB | 0xb | 7 | low-nibble path 0x5 |
| 12 | 0x1520e0 | `0x549bab85` | 600 | 4 MB | 0xa | 5 | 0x4000 + 7 |
| 13 | 0x1520f0 | `0x541aab85` | 600 | 2 MB | 0xa | 5 | 0x8000 + 3 |
| 14 | 0x152100 | `0x541bab85` | 600 | 4 MB | 0xa | 5 | 0x8000 + 4 |
| 15 | 0x152110 | `0x569caf85` | 800 | 8 MB | 0xb | 7 | low-nibble path 0x7, 0xa |
| 16 | 0x152120 | `0x549dad85` | 700 | 16 MB | 0xa | 6 | none |
| 17 | 0x152130 | `0x549bad85` | 700 | 4 MB | 0xa | 6 | 0x4000 + 9 |
| 18 | 0x152140 | `0x549cad85` | 700 | 8 MB | 0xa | 6 | 0x4000 + 0xa |
| 19 | 0x152150 | `0x549dad85` | 700 | 16 MB | 0xa | 6 | 0x4000 + 0xb |
| 20 | 0x152160 | `0x549baf85` | 800 | 4 MB | 0xa | 7 | 0x4000 + 0xc |
| 21 | 0x152170 | `0x549caf85` | 800 | 8 MB | 0xa | 7 | 0x4000 + 0xd |
| 22 | 0x152180 | `0x549daf85` | 800 | 16 MB | 0xa | 7 | 0x4000 + 0xe |
| 23 | 0x152190 | `0x549bab85` | 600 | 4 MB | 0xa | 5 | 0x4000 + 8 |
| 24 | 0x1521a0 | `0x5219a785` | 400 | 1 MB | 0x9 | 3 | 0x2000 + 0 |
| 25 | 0x1521b0 | `0x5219a785` | 400 | 1 MB | 0x9 | 3 | 0x2000 + 1, 5 |
| 26 | 0x1521c0 | `0x589bad85` | 700 | 4 MB | 0xc | 6 | 0x4000 + 3 |
| 27 | 0x1521d0 | `0x569baf85` | 800 | 4 MB | 0xb | 7 | 0x4000 + 1 |
| 28 | 0x1521e0 | `0x569cb185` | 900 | 8 MB | 0xb | 8 | 0x4000 + 2 |

Hub clock is 200 MHz in every row. Cache = `1 << (SCSize - 1)` MB from bits 18:16; tap = bits 28:25 plus bit 22 as
bit 4; SysClkDiv = bits 12:9. Rows 0 and 16 are reached by no code. The class `0x4000` codes 0 and 0xf map to no row,
and so do classes `0x2000` codes 2 to 4 and 6 to 0xf: no code is left that selects an unused R16000 row.

Established. In 27 of the 29 rows the CPU clock equals the hub clock times (SysClkDiv + 1) / 2 (the 400, 500, 600,
700, 800 and 900 MHz rows, with SysClkDiv 3 to 8). The two exceptions are the 200 MHz and 360 MHz rows (1 and 5).
Inferred: the same rule would give SysClkDiv 9 for a 1 GHz part on a 200 MHz hub. Nothing in either PROM states it.

Established. Neither PROM contains the big-endian or little-endian 32-bit word for 1,000,000,000, 333,333,333 or
333,000,000, a 64-bit 1,000,000,000, the words `0x4aedb385` or `0x00edb385`, nor a text `1000 MHz` or `1.0 GHz`.
The same searches over the BaseIO image find nothing either.

## Where the configuration word comes from

Established, from the control flow of each routine (6.210; the 6.211 addresses differ by the shifted tail only).

1. Early start-up (`0x1fc00690` to `0x1fc006fc`). Before any RAM, the PROM reads the configuration record flashed at
   `flash + 0x60` (the word at record +4, flash address `0x9000000018000064`), writes it to CP0 Config (`mtc0` at
   `0x1fc006ac`), reads Config back, and compares the low 16 bits and then bits 24:16 of readback and flash word. A
   mismatch jumps to `0x1fc006fc`, which stores 0xb4 to two per-slice registers and calls `0x1fc50c34`; where that path
   ends was not traced. Nothing consults the speed table or the node EEPROM at this point.
2. The configuration report (`0x1fc1e034`). It copies the 80-byte record from `0x9000000038000060 + (nasid << 33)`
   and prints it under "Config values flashed in the PROM". For the local node it then prints the live Config
   register decode (`0x1fc03c40`, register 16, then `0x1fc1dc74`) under "Config values loaded from nasid N CPU c".
   For a remote node it calls the EEPROM loader `0x1fc1f4dc` and prints "loaded from board EEPROM"; only when that
   returns zero does it call the table lookup `0x1fc1f3a0` and print "loaded from board/PIMM PSC".
3. The EEPROM loader wraps the parser at `0x1fc1c498` to `0x1fc1c6fc`. It needs `DataValid:Yes`, reads
   `CpuCfg0Reg` as a hexadecimal word into record +4, and reads `CpuSpeed` and `HubSpeed`. The text fields
   `HubModeBits`, `CpuCfg1Reg`, `CpuCfg2Reg`, `CpuCfg3Reg`, `MinIrixVer`, `MinPromVer` and `MinL1Ver` are
   consumed by other code. The strings sit at offsets 0x84380 to 0x84470 (format) and 0x89420 to 0x894d0 (names).

Inferred. A 1 GHz module under PROM 6.210 or 6.211 can run only on a flashed record and, for the remote-node check, an
EEPROM record, because the table has nothing for it. The failure arm of the table lookup is the text "Unknown PIMM_PSC
type/no board EEPROM values" (printed at `0x1fc1e10c`'s zero branch, `0x1fc1e1dc`).

Established, bounded to the strings, tables and routines read in the L1 1.44.0 image that ships with IRIX 6.5.30: the
system controller has no path that reads a processor's Config or PRId and does not interpret `CpuCfg0Reg`; it reads the
node board EEPROM's product name and a power code only. The processor-module clock commands were not traced. Unknown: where the electrical mode bits that the processor latches at reset come from. The
PROM only proves they equal bits 24:0 of the flashed word, or it takes the mismatch path above.

## Product names and socket masks

Established (6.210 and 6.211, same offsets).

- Six rows of 16 bytes at offset 0x8a970: a 64-bit pointer to a product name, then a mask byte at row +8. In order:
  `IP53_4CPU` 0x0f (row 0x8a970), `IP53_2CPU` 0x05 (0x8a980), `IP53_1CPU` 0x01 (0x8a990), `IP59_4CPU` 0x0f (0x8a9a0),
  `IP59_2CPU` 0x05 (0x8a9b0), `IP59_1CPU` 0x01 (0x8a9c0). The names are at 0x6efa8 to 0x6eff8 (6.210) and 0x6ef98
  to 0x6efe8 (6.211). The IP59 rows are identical to the IP53 rows.
- The consumer is the per-socket routine at `0x1fc66d8c` (start of the table at address 0x1fc8a958). It compares the
  node's EEPROM product name with each row name; on a match it keeps going only if bit (1 << socket) is set in the row
  mask, and otherwise returns at once. Socket bit 0 is slice A, 1 slice B, 2 slice C, 3 slice D, so a 2CPU product
  allows slices A and C, a 1CPU product slice A only.
- The routine returns immediately, without touching these rows, when the board register class (bits 15:12 of the
  register at `0x9000000014000000`) is `0x4000` (`0x1fc66da4` to `0x1fc66dc0`). The class values of IP53 and IP59 nodes
  are not established in the PROM; the R16000 rows above are reached through class `0x4000`, which suggests but does
  not show that node boards of those products carry it.

## What the table does not settle

- Inferred: the configuration word a 1 GHz IP59 module carries is whatever its flash record and node EEPROM hold. Public
  console captures show what the PROM prints from it (processor "1.0 GHz R16000 Rev 3.0", "Secondary Cache 16MB
  333MHz Tap 0x15", boot banner line "revision: f50" for each of four processors on a Tezro tower under PROM 6.210),
  which fixes cache clock 333 MHz (SCClkDiv 5), tap 0x15 (bits 28:25 = 5, bit 22 = 1) and 16 MB (SCSize 5) by the
  PROM's own arithmetic, but not the other bits of the word.
- Unknown: the SysClkDiv, DDR, Kseg0CA, PrcReqMax, block size, ECC, drive and CTM bits of a real 1 GHz word. Route: a
  raw read of the flash record (`flash + 0x64`) or the node EEPROM `CpuCfg0Reg` of a 1 GHz module, or a CP0 Config read
  on one. No such capture is public. Software-only routes are exhausted for the PROM; the L1 and kernel images do
  not hold it.
- Unknown: which board-register class IP53 and IP59 node boards carry.

Tracked in [open-questions.md](../open-questions.md) as "IP35 PROM: the 1 GHz R16000 configuration word".
