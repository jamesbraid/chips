# IP35 PROM environment: the base I/O NVRAM and the CPU PROM log in node flash

Question answered: on a Fuel, a Tezro or Origin 350, or an Origin 3200 or Onyx 3000, where do the PROMs keep their environment variables, how is each
store protected, and what bytes does `setenv console d` leave behind. Ratings follow [AGENTS.md](../../AGENTS.md): **established**, **inferred**,
**unknown**. The sibling page for the Origin 200, 2000 and Onyx2 is [../ip27/prom-environment.md](../ip27/prom-environment.md); the NVRAM layout and
checksum here are the same design, with the differences listed below.

## Evidence

- `ip35prom.img` 6.210, read as a disassembly (objdump) with Ghidra decompiles as navigation. The I/O ("BASEIO") monitor is the gzip ELF at image offset
  `0x8cbb0`, loaded at `0xc000000013000000`. Read in full: the variable table (`0xc00000001311fc68`, 48 rows of 48 bytes), the checksum routine
  (`0x1300d1cc` and its twin `0x130da4e0`), the byte and field writers (`0x130dd97c`, `0x130dbf14`), the checksum updater (`0x130dd944`), the validity test
  (`0x130db488`), the per-variable setter (`0x1300d504`), the defaults loop (`0x130e3208`, shared with `resetenv` at `0x130a5bec`), the `setenv` command
  (`0x130130e8`), the NVRAM base lookup (`0x130e3964`) and the slave mirror (`0x130da2b4`, `0x130c6fc0`). The CPU PROM is the 6.210 payload loaded at
  `0xc00000001fc00000`; the log routines at `0x1fc12e70` to `0x1fc14d9c` and `0x1fc18558` to `0x1fc18830` were read.
- The public 6.5.7 header `sys/SN/nvram.h` and the stand-alone NVRAM library (`libsk/ml/SN0nvram.c`): the shipped monitor agrees with it row by row, and
  with the IP27 sibling's reading of the Origin 2000 image.
- Cross-check, model behaviour only: 1,152 NVRAM images left by the shipped PROM in emulator runs all satisfy the checksum rule below, and 936 of them
  hold every table row except `ConsolePath`, `oldConsolePath` and `dbgname`, including the neighbouring-memory bytes described under "How `setenv`
  writes", exactly as the code predicts. Nothing was read
  from a real machine.
- Only 6.210 was read. 6.211 (patch 7208) was not.

## Which store holds `console`

| Machine | Store holding `console` | Part | Rating |
|---|---|---|---|
| Fuel (IP34) | NVRAM on the base I/O's IOC3, byte-bus select 0 (IOC3 base + `0x80000`), offset `0x0f` | 32 KiB byte-wide timekeeper RAM; part unknown | established (code); part unknown |
| Tezro, Origin 350 (IO9) | NVRAM on the IO9's IOC4 at IOC4 base + `0x80000`, offset `0x0f` | DS1742-compatible, clock in the top eight bytes | established (code); part inferred |
| Origin 3200, Onyx 3000 (I-brick IO7) | NVRAM on the IO7's IOC3, IOC3 base + `0x80000`, offset `0x0f` | 32 KiB timekeeper RAM; part unknown | established (code); part unknown |

All three run the same monitor, and it takes the base from the first IOC it finds (`0x130dcc6c`, then `0x130dcc24`; the TOD page has the same pair and
the IOC3/IOC4 naming is inferred, see [prom-tod-clock.md](prom-tod-clock.md)). `console` is not in the CPU PROM's flash log. The two PROMs each have
their own store:

| Store | Holds | Rating |
|---|---|---|
| Base I/O NVRAM (this page, "Layout") | every ARCS-style variable the monitor reads: `console`, `ConsolePath`, `OSLoader`, ..., hardware inventory, name table | established |
| CPU PROM log in the node's second PROM (flash blocks 30 and 31, "Flash log") | the CPU PROM's own variables: `DisableA` to `DisableD`, `DisableMemMask`, `ConsoleDevice`, `LastModule`, ... | established |

`ConsoleDevice` in the flash log is not `console`: it picks the device (`sc`, `ioc3`, `ioc4`) that carries the CPU PROM's own console, with `sc` the
default when it is unset. Established for the names and the default; what each value selects is inferred. How `console` `g`, `d` and `d2` choose the
console is in [prom-console-input.md](prom-console-input.md).

## Layout of the NVRAM

Fixed offset, fixed length, one NUL-padded field per variable. Layout revision byte `0x0e` = `4`. Offsets `0x00` to `0x0d` are not counted (the TOD probe
writes bytes `6` and `0x0b`; see the TOD page). The checksummed area is `0x0e` to `0x7fd0`; `0x7fd1` and up (serial area, power-fail words, clock) is not.
Every row comes from the shipped table. Established.

| Offset | Len | Variable | Default | Offset | Len | Variable | Default |
|---|---|---|---|---|---|---|---|
| `0x000f` | 2 | `console` | `d`, or `g` (below) | `0x0426` | 2 | `diagmode` | empty |
| `0x0011` | 128 | `ConsolePath` (first copied to `0x3643`) | `default` | `0x0428` | 4 | `netaddr` (raw) | `192.0.2.1` |
| `0x0091` | 128 | `SystemPartition` | `dksc(0,1,8)` | `0x042c` | 1 | `nogfxkbd` | empty |
| `0x0111` | 128 | `OSLoader` | `sash` | `0x042d` | 5 | `keybd` | empty |
| `0x0191` | 128 | `OSLoadFilename` | `unix` | `0x0432` | 6 | `lang` | empty |
| `0x0211` | 128 | `OSLoadOptions` | empty | `0x0438` | 17 | `passwd_key` | empty |
| `0x0291` | 6 | `pagecolor` | empty | `0x0449` | 17 | `netpasswd_key` | empty |
| `0x0297` | 5 | `dbaud` | `9600` | `0x045a` | 1 | `scsiretries` | empty |
| `0x029c` | 128 | `dbgtty` | `/dev/tty/hubtty0` | `0x045b` | 3 | `volume` | `80` |
| `0x031c` | 1 | `diskless` | `0` | `0x045e` | 6 | `ef0mode` | empty |
| `0x031d` | 8 | `TimeZone` | `PST8PDT` | `0x0464` | 2 | `scsihostid` | `00` |
| `0x0325` | 128 | `OSLoadPartition` | `dksc(0,1,0)` | `0x0466` | 1 | `sgilogo` | `y` |
| `0x03a5` | 1 | `AutoLoad` (first letter, `Y` or `N`) | `N` | `0x0467` | 1 | `nogui` | empty |
| `0x03a6` | 128 | `root` | `dks0d1s0` | `0x0468` | 1 | `nonstop` | `0` |
| **`0x04bc`** | 1 | **checksum** | computed | `0x0469` | 1 | `fastmem` | empty |
| `0x046a` | 5 | `rbaud` | `19200` | `0x046f` | 8 | restart block (not checksummed) | zero |
| `0x0477` | 50 | `AltOSPath` | empty | `0x04bb` | 1 | `rebound` | empty |
| `0x34c0` | 128 | `gConsoleIn` | `default` | `0x3540` | 128 | `gConsoleOut` | `default` |
| `0x35c1` | 1 | `ProbeAllScsi` | `n` | `0x35c2` | 128 | `ProbeWhichScsi` | empty |
| `0x3643` | 128 | `oldConsolePath` | empty (see above) | `0x36f9` | 128 | `dbgname` | empty |
| `0x377c` | 128 | `swap` | empty | `0x37fc` | 1 | `RestorePartEnv` | `y` |
| `0x3885` | 128 | `dumpdev` | empty | `0x3905` | 32 | `tg0mode` | empty |
| `0x3925` | 4 | `netmask` (raw) | `255.255.255.0` | `0x3929` | 4 | `dlserver` (raw) | empty |
| `0x392d` | 4 | `dlgate` (raw) | empty | `0x3931` | 4 | `srvaddr` (raw) | empty |
| `0x3935` | 4 | `gateaddr` (raw) | empty | `0x7e46` | 1 | `AutoPROMVars` | `0` |
| `0x4bd` | 1 | inventory-valid marker `0x4a` (inventory from `0x4be`) | not in table | `0x7fcb` | 1 | stored partition id (reinit writes `0xff`) | `0xff` |

Beside the IP27 table this one adds `netmask`, `dlserver`, `dlgate`, `srvaddr`, `gateaddr` and `AutoPROMVars`, and `dbgtty` defaults to
`/dev/tty/hubtty0`. The inventory (`0x4be`, 4 KiB), name table (`0x14bf`, 4 KiB) and error area (`0x24c0`, 4 KiB) sit between the named fields; their
contents are written by other code, and the free space between the fields is unknown at power-on.

**`console` default.** The table says `d`. The defaults loop (`0x130e3208`) writes `g` instead when the board-class word at `0x9000000014000000` has
class `0x4000` (Fuel, per [ip35-board-word-and-config-block.md](../../questions/ip35-board-word-and-config-block.md)). Otherwise it asks the product test
`0x130e24a4`, which reads a product character from the node's I/O board identity and returns 1 to 5 for `7`, `8`, `9`, `0` and `Q`, or 0 when the node's
class word at `0x9000000034000000` is `0x8000`, `0x4000` or `0xc000`; a result of 2, 3 or 5 (`8`, `9`, `Q`) writes `g`, anything else keeps `d`. So a
Fuel, and a Tezro or Origin 350 if its I/O product character is `9`, reset to `g`, and an I-brick whose character is `7` resets to `d`. The same test
(the same branch of the defaults loop) also makes the `AutoLoad` default `Yes` (stored `Y`) instead of `No` (stored `N`), so `g` machines reset to
`AutoLoad` `Y`. Established for the branches; which product each character names is inferred.

## The checksum

One byte at `0x04bc`, a rotating XOR over `0x0e` to `0x7fd0`:

1. `c = 0xa5`.
2. For each offset `p` from `0x0e` to `0x7fd0`: unless `p` is `0x04bc` or `0x046f`, `c ^= byte[p]`. Then, for every `p` (skipped ones too), rotate left
   one bit in 8 bits: `c = ((c << 1) | (c >> 7)) & 0xff`.
3. The final `c` is stored at `0x04bc`.

Established: the shipped routine's seed (`-0x5b`, which is `0xa5`), start (`0xe`), skips (`0x4bc`, `0x46f`) and end (`0x7fd1`, exclusive) were read from the image, and
the public source has the same loop. XOR then rotate is linear, so changing one counted byte from `a` to `b` at offset `p` changes the checksum by
`rotl8(a ^ b, (0x7fd1 - p) mod 8)`. Inferred (algebra); checked by script against the full loop. A second copy at `0x1300d0cc` stops at `0x35c0`; it appears in the mirror
comparison and plays no part in validity (inferred).

## Validity and what the PROM does on a mismatch

- Valid means: byte `0x0e` is `4` and the checksum recomputed equals the stored byte; the PROM tests the checksum twice before calling it bad.
  Established (`0x130db488`).
- Invalid: it prints "NVRAM checksum is incorrect: reinitializing.", rewrites every table row with its default (below), writes `0xff` to `0x7fcb`,
  sets the revision to `4` and recomputes the checksum (`0x130e3208`). Bytes outside the table (inventory, names, free space) are not cleared.
  Established.
- A bad inventory (`0x4bd` is not `0x4a`) or one whose stored identity does not match prints "hardware inventory is invalid" or "This NVRAM did not
  belong to this system" and rebuilds the inventory only (`0x130dcf40`). It does not reset variables. Established for the checks; that the rebuild leaves
  the variables alone is inferred.
- `resetenv` runs the same defaults loop, then writes the revision and checksum. It does not write `0x7fcb`. Established.

## What each PROM reads at power-on

| PROM | Reads | Default if blank or invalid |
|---|---|---|
| I/O monitor | the whole table above through its start-up path; `console` decides ConsoleIn and ConsoleOut (a value starting `d` is serial, port 1 for `d2`; otherwise graphics), `ConsolePath` picks the console I/O board | the table's default column |
| CPU PROM | flash-log variables `DisableA`, `DisableB`, `DisableC`, `DisableD`, `DisableMemMask`, `DisableMemSz`, `MemDisReason`, `MemCfgRCD3`, `MemCfgPremium`, `MemCfgBankSize`, `LastModule`, `UPC`, `CPULogSeqNum`, `ConsoleDevice`, `GlobalMaster`, `force_coarse`, `Verbose`, `DisableIO`, `DisableExpress`, and the product names `IP53_*`, `IP59_*` | an absent variable reads as the caller's default; known only for `ConsoleDevice` (`sc`) |

Established for the names (each is a lookup key in the code); the CPU PROM's reads of the base I/O NVRAM were not traced (unknown).

## How `setenv` and `resetenv` write

- **NVRAM, in place.** No append, no erase, no wear levelling. `setenv NAME VALUE` (`0x130130e8`) finds the row, copies exactly the row's length from the
  value string, one byte at a time in ascending order, to the part and to the mirrors (`0x130dd97c`), then recomputes the checksum over the whole area
  and writes it once, last (`0x130dd944`). The copy has no end test: bytes after the string's NUL come from whatever follows the string in memory.
  Established (`0x130dbf14`).
- Specials. `AutoLoad` stores one byte, the first letter mapped to upper case (`n` to `N`, `y` to `Y`). `netaddr`, `netmask`, `dlserver`, `dlgate`,
  `srvaddr` and `gateaddr` are parsed to four raw bytes. `dbaud` is normalised and stored as 5 bytes. `ConsolePath` is first copied to `oldConsolePath`
  (`0x3643`). `passwd_key` and `netpasswd_key` are skipped by `setenv`. Established.
- Over-read at reset. Defaults come from the table's string pointers, so a 128-byte row holds the string, its NUL and the bytes of whatever follows it
  in the monitor's data. `ConsolePath`, `gConsoleIn` and `gConsoleOut` each hold `default`, NUL, `00`, a gap, `9600`, a gap, `80`, then the start of
  the next message text. The two password keys (17 bytes from the empty string) hold `2e 6d 66 69 6e 64 00 00 70...` (`.mfind`, `p...`). Established for
  the copy; the byte values are read from the 6.210 image.
- **Consequence for `console`.** The row is two bytes. `setenv console d` stores `64 xx`, where `xx` is the byte after the argument's NUL: the setenv
  command passes the parsed argument, a pointer into the parser's packed token list in a never-cleared stack buffer (public source:
  `libsc/lib/parser.c`, `lib/stringlist.c`, `cmd/env_cmd.c`; the shipped parser was not read), so `xx` is `00` only when that stale byte is zero.
  Typing `d2` stores `64 32` (serial port 1). `resetenv` and the reinitialise pass store `64 00` or `67 00` from the default string in the image.
  Established for the copy and for the default strings; the stale byte is unknown. An emulator should write `64 00`.
- Mirrors. A write to the master part goes to every other base I/O board's part, except offsets `0x393a` to `0x7fd0`. Each slave's checksum is
  recomputed from its own bytes (`0x130da2b4`). Established.
- **Interrupted write.** No journal. A reset after the field bytes but before the checksum byte leaves a stale checksum, and the next boot reinitialises
  every table row to its default. Established as the code's consequence; not observed on hardware.

## Flash log (the CPU PROM's variables)

Established from the CPU PROM code for the header and entry layout (re-read in review, see Review), and agreeing with the captured records in [boot-flash.md](boot-flash.md); the compaction and erase details are less well read.

- Where: a 64 KiB-block pair in the node's second PROM, base block index `0x1e` (30): blocks 30 and 31, flash offsets `0x9e0000` and `0x9f0000` of the
  16 MiB logical flash. Erase is by 64 KiB block: an unlock sequence at `0x555`/`0x2aa`, sector command `0x30`, then an all-`0xff` check (the AMD command set, inferred from the sequence).
- Header, 28 bytes at the block start: `0x00` to `0x0f` erased, `0x10` magic `0x504c4f49` (`PLOI`), `0x14` version `1`, `0x18` generation. Entries run from
  block offset `0x100` to `0xffff`, 64 bytes each (1,020 per block).
- Active block: the one whose header has the magic; if both do, the larger generation, and block 30 on a tie. Neither: the log is blank, and a create
  open formats it (erase both blocks, write the header in block 30 only, generation `1` or the larger old generation plus one).
- Entry, 64 bytes: byte `0x00` = type (high nibble) and writer CPU (low nibble); bytes `1` to `0x0e` the name (at most 14 characters); bytes `0x10` to
  `0x3e` the value (at most 47 characters); no per-entry checksum. Type `1` is a live variable, `2` a second live kind that compaction also keeps, `0`
  a cancelled entry, `0xf` (byte `0xff`) the end of the log. The copies stop at the NUL and do not pad, so unused bytes keep the staging buffer's
  earlier contents (`0xff` after a fresh slot read).
- Set a variable (`0x1fc14368`): look for the live entry. If the new 64 bytes can be had from it by clearing bits only, program it in place. Otherwise
  clear its type nibble to `0` and append at the first erased slot. If the block is full, erase the other block, copy every live entry (types `1` and `2`)
  into it from offset `0x100`, write its header last with generation plus one, then switch to it; the old block is erased at the next compaction.
- Unset (`0x1fc65108`): clear the type nibble to `0`.
- **Interrupted write.** An interrupted compaction leaves the new block without a header, so the old block stays active. A power loss after cancelling
  the old entry and before the append loses that variable. A partly programmed append is not detected: unknown (the program order inside one entry
  was not read).

## Worked example

Rating: the algorithm is established, the numbers are computed by script and cross-checked against the closed form. The two stores assume zero outside
the written fields, which no real store has (the inventory and name table add non-zero bytes), so recompute on the bytes present. The delta rule holds on
any store.

**Smallest store.** Every byte `0`, `0x0e` = `04`, `console` at `0x0f`, checksum computed. The first steps for `d`: seed `a5`; `0x0e`: `a5 ^ 04 = a1`,
rotate `43`; `0x0f`: `43 ^ 64 = 27`, rotate `4e`; `0x10`: `4e ^ 00 = 4e`, rotate `9c`; the remaining 32,704 offsets are rotations only, and the result is:

| `console` at `0x0f` | Checksum at `0x04bc` |
|---|---|
| `67 00` (`g`) | `0x90` |
| `64 00` (`d`) | `0x9c` |

**Reset store.** Zero-filled; every table row written with its default including the neighbouring bytes (read from the image), `netaddr` `c0 00 02 01`,
`netmask` `ff ff ff 00`, the other four address rows zero, `0x7fcb` = `ff`, `0x0e` = `04`; 1,562 non-zero bytes counting the checksum. Two cases:

| Machine class | `console`, `AutoLoad` | Checksum after reset | After `setenv console d` |
|---|---|---|---|
| `g` default (Fuel, product `8`, `9`, `Q`) | `67 00`, `59` (`Y`) | `0x46` | `0x4a` |
| `d` default (I-brick `7`) | `64 00`, `4e` (`N`) | `0x3b` | `0x3b`, unchanged |

The `g` row follows the delta rule: `0x46 ^ rotl8(0x67 ^ 0x64, (0x7fd1 - 0x0f) mod 8) = 0x46 ^ rotl8(0x03, 2) = 0x46 ^ 0x0c = 0x4a`.
An earlier version of this page paired `g` with `AutoLoad` `N` (`0x37`, `0x3b`); the PROM never writes that pair.

The minimum for iris to match the PROM: on a store the PROM already accepted, write `64 00` at `0x0f`, recompute the loop above, write the byte to `0x04bc`.
On a blank or zero-filled store do not write a partial image: the PROM accepts any store whose revision and checksum agree and reads the empty rows as
empty variables, so a hand-built image either needs every row of the table or should come from a PROM run (see the notes below).

## Notes on the iris timekeeper models

iris's Fuel store (`dev/timekeeper.rs`) and Tezro store (`dev/ds1744.rs`) are plain 32 KiB byte stores with a calendar in the top eight bytes; neither
knows this layout, so they match the part as the PROM sees it: below `0x7ff8` the bytes read back what was written, which the monitor's TOD probe needs
(it writes `0xff` to byte 6 and reads it back to choose layout 1). A new zeroed backing file fails validity on the first boot and goes through the
reinitialise path above once, which is correct. The difference that matters for `console=d` is outside the models: a host that edits the file must
also write the checksum, and anything short of that makes the PROM wipe the variables on the next boot, as seen earlier.

## Unknowns

1. The Fuel and I-brick NVRAM parts and the IOC3 wiring; the IO9's part is only inferred as DS1742-compatible.
2. Whether the CPU PROM reads `console` or `ConsolePath` from the base I/O NVRAM (a console-device probe prints "nvram is invalid" for a bad one); not traced.
3. The order of program operations inside one 64-byte flash entry, and so what an interrupted append leaves.
4. The 6.211 monitor and CPU PROM; the table and loop here are 6.210.
5. The meaning of the second type value `2` in the flash log, and the defaults the CPU PROM uses for variables other than `ConsoleDevice`.

## Review

Independent review against the 6.210 I/O monitor (the gzip ELF at image offset `0x8cbb0`, inflated; read in Ghidra as a flat image at `0x13000000`,
decompiles checked against objdump) and the CPU PROM payload (flat at `0x1fc00000`). Confirmed, grades unchanged unless noted:

- Layout. All 48 rows of the variable table at `0x1311fc68` match the page's offsets, lengths and defaults, including the five added address rows and
  `AutoPROMVars`; `console` is offset `0x0f`, 2 bytes; the revision byte is `0x0e` = 4.
- Checksum (`0x1300d1cc`, writer chain `0x130dd97c`, `0x130dbf14`, updater `0x130dd944`, validity `0x130db488`): identical to the IP27 routine (seed
  `0xa5`, `0x0e` to `0x7fd0`, XOR skipped at `0x04bc` and `0x046f`, rotate at every offset, checksum written last, validity is revision 4 plus a
  checksum matched on one of two tries). The slave copy helper (`0x130c6fc0`) skips `0x393a` to `0x7fd0` as the page says.
- `console` default. The defaults loop (`0x130e3208`) tests the board class at `0x9000000014000000` (class `0x4000` gives `g`), else the product test
  (`0x130e24a4`: `7`, `8`, `9`, `0`, `Q` return 1 to 5, `0` for node classes `0x8000`, `0x4000`, `0xc000`); results 3, 2 and 5 (`9`, `8`, `Q`) give `g`.
  Matches the page, including that `7` and `0` keep `d`.
- Worked examples, recomputed with an independent script that rebuilds the reset store from the image's table (each row copies its length from the
  default pointer; `AutoLoad` first letter; address rows as raw bytes; `0x7fcb` = `ff`): `g` and `d` smallest stores `0x90` and `0x9c`; reset store
  `0x37` with `g` and `AutoLoad` `N`, `0x3b` with `d`. These reproduce, 1,561 non-zero bytes plus the checksum.
- CPU PROM log header (read at `0x1fc13470` onward): a 28-byte header memset to `ff`, magic `PLOI` at `+0x10`, version 1 at `+0x14`, generation at `+0x18`;
  entry reader (`0x1fc18558`): 64-byte entries, type in the high nibble of byte 0 with `0xf` as end, name 14 bytes from byte 1, value 47 bytes from byte `0x10`.
  Matches. Block 30 on a generation tie, the unlock and erase sequence and the set and unset routines were not read in full.

Corrected:

- The defaults loop applies the same product test to `AutoLoad`: `g` machines reset to `Yes` (stored `Y`), others to `No`. The page's reset example paired
  `g` with `N`, a combination the PROM never writes; the table above now gives `0x46` and `0x4a` for the `g` class, `0x3b` for the `d` class.
- `setenv console d` stores `64 00` only if the byte after the argument's NUL is zero. The argument is the parser's token-list string (stack buffer,
  never cleared), so the second byte is stale; the page's "established" is withdrawn for that byte. `resetenv` and the reinitialise pass do store `64 00` or `67 00`
  from the default string. This also settles the IP27 page's unknown in the same direction: it is unknown, not established, and the source is the token list.
