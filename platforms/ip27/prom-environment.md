# IP27 PROM environment: the base I/O Timekeeper NVRAM and the node flash log

Question answered: on an Origin 200, Origin 2000 or Onyx2, where do the PROMs keep their environment variables, how is the store protected, and what
bytes does `setenv` leave behind (the case that matters is `setenv console d`). Ratings follow [AGENTS.md](../../AGENTS.md): **established**,
**inferred**, **unknown**.

## Evidence

- The 6.5.7 standalone-library NVRAM code (`stand/arcs/lib/libsk/ml/SN0nvram.c`, `ml/nvram.c`, `lib/setenv.c`, `libkl/ml/SN0nvram.c`,
  `libkl/ml/iodiscover.c`), the NVRAM header (`sys/SN/nvram.h`), the flash-log code (`libkl/ml/promlog.c`, `ip27log.c`, `sys/SN/promlog.h`,
  `stand/arcs/IP27prom/Promlog/promlog.txt`). Read in full; facts are in our own words.
- `root/firmware/io6prom.img` (segment `io6prom`, load `0x11c00000`) and `root/firmware/ip27prom.img` (load `0x1fc00000`), unpacked with
  `retools/tools/chips/promgen64.py` and read as a disassembly (objdump) and, for the IO6 routines below, in Ghidra as a flat image at `0x11c00000`. Read and matching the source: the checksum routine
  (`0x11c799e0`), the byte writer (`0x11c7bf8c`), the multi-byte writer (`0x11c7bfe8`), the checksum updater (`0x11c7bf20`), the validity test
  (`0x11c7a32c`), the validity setter (`0x11c7a04c`), the start-up path with the reinitialise message (`0x11c81b40`) and the 42-row variable table
  (`0x11ca7e28`, 48 bytes a row). In the node PROM: the three NVRAM reads (`0x1fc27b58`, `0x1fc3c86c`, `0x1fc3ffe0`) and the log header writer
  (`0x1fc0ab68`).
- Nothing was read from a real machine. The part is in [baseio](../../devices/baseio/README.md) and the IOC3 window in [ioc3](../../devices/ioc3/README.md).

## Where it lives

| Store | Part and access | Holds | Rating |
|---|---|---|---|
| Timekeeper NVRAM | ST M48T35, 32 KiB, byte-wide, on the base I/O board's IOC3 byte-bus select 0 (IOC3 base + `0x80000`). The clock is in its top eight bytes (`0x7ff8` to `0x7fff`) | every ARCS-style variable, including `console`; hardware inventory and name tables; all of it behind one checksum | established (source; the part marking is inferred in [baseio](../../devices/baseio/README.md)) |
| Node boot flash, sectors 14 and 15 (flash offsets `0xe0000` to `0xfffff`) | the 1 MiB flash of each node board, read through the Hub | the node PROM's own variables and its message log | established (source) |
| Base I/O board flash | 1 MiB, code only: the flash command erases sectors 0 to 13 and refuses a larger image | no variables | inferred (source: the flash command touches only sectors 0 to 13 and no log call names this device) |
| Module system controller NVRAM | 2 KiB, behind the controller (`scr`, `scw` commands) | not a PROM environment store; not traced | unknown |

The IOC3 itself has no NVRAM. `console` lives in the Timekeeper NVRAM, at offset `0x0f`, **not** in the flash log. Established.

Offsets `0x00` to `0x0d` are never read, written or checksummed on this part (the header reserves them for a different clock chip). The IO6 PROM
reads and writes the master base I/O board's part; every other base I/O board's part is a slave that the master mirrors (below). Established.

## Layout of the Timekeeper NVRAM

Fixed offset, fixed length, one NUL-padded ASCII field per variable; offsets are into the 32 KiB part. Layout revision 4. Every row below was read
from the shipped IO6 PROM's table and agrees with the 6.5.7 header, which lacks only `dumpdev` and `tg0mode` at the end. Established.

| Offset | Len | Variable | Default | Offset | Len | Variable | Default |
|---|---|---|---|---|---|---|---|
| `0x000e` | 1 | layout revision | `4` (byte) | `0x0426` | 2 | `diagmode` | empty |
| `0x000f` | 2 | `console` | `d` | `0x0428` | 4 | `netaddr` (raw bytes) | `192.0.2.1` |
| `0x0011` | 128 | `ConsolePath` | `default` | `0x042c` | 1 | `nogfxkbd` | empty |
| `0x0091` | 128 | `SystemPartition` | `dksc(0,1,8)` | `0x042d` | 5 | `keybd` | empty |
| `0x0111` | 128 | `OSLoader` | `sash` | `0x0432` | 6 | `lang` | empty |
| `0x0191` | 128 | `OSLoadFilename` | `unix` | `0x0438` | 17 | `passwd_key` | empty |
| `0x0211` | 128 | `OSLoadOptions` | empty | `0x0449` | 17 | `netpasswd_key` | empty |
| `0x0291` | 6 | `pagecolor` | empty | `0x045a` | 1 | `scsiretries` | empty |
| `0x0297` | 5 | `dbaud` | `9600` | `0x045b` | 3 | `volume` | `80` |
| `0x029c` | 128 | `dbgtty` | `/dev/tty/ioc30` | `0x045e` | 6 | `ef0mode` | empty |
| `0x031c` | 1 | `diskless` | `0` | `0x0464` | 2 | `scsihostid` | `00` |
| `0x031d` | 8 | `TimeZone` | `PST8PDT` | `0x0466` | 1 | `sgilogo` | `y` |
| `0x0325` | 128 | `OSLoadPartition` | `dksc(0,1,0)` | `0x0467` | 1 | `nogui` | empty |
| `0x03a5` | 1 | `AutoLoad` (`Y` or `N`) | `N` | `0x0468` | 1 | `nonstop` | `0` |
| `0x03a6` | 128 | `root` | `dks0d1s0` | `0x0469` | 1 | `fastmem` | empty |
| `0x046a` | 5 | `rbaud` | `19200` | `0x046f` | 8 | restart block (not checksummed) | zero |
| `0x0477` | 50 | `AltOSPath` | empty | `0x04bb` | 1 | `rebound` | empty |
| **`0x04bc`** | 1 | **checksum** | computed | `0x34c0` | 128 | `gConsoleIn` | `default` |
| `0x3540` | 128 | `gConsoleOut` | `default` | `0x35c1` | 1 | `ProbeAllScsi` | `n` |
| `0x35c2` | 128 | `ProbeWhichScsi` | empty | `0x3643` | 128 | `oldConsolePath` | empty |
| `0x36f9` | 128 | `dbgname` | empty | `0x377c` | 128 | `swap` | empty |
| `0x37fc` | 1 | `RestorePartEnv` | `y` | `0x3801` | 1 | stored partition id | not in table |
| `0x3802` | 128 | stored console path | not in table | `0x3883` | 1 | clock leap-cycle marker | not in table |
| `0x3885` | 128 | `dumpdev` | empty | `0x3905` | 32 | `tg0mode` | empty |
| `0x7fcb` | 1 | stored partition id (reinit writes `0xff`) | `0xff` | `0x7fd1` | | end of checksummed area | |

Between the named fields sit the inventory table, name table and error area (4 KiB each, each behind a valid-marker byte) and free space. The part
has no `eaddr` row: the Ethernet address is not kept here. Established for the rows above; the free-space contents are unknown.

## The checksum

One byte at `0x04bc`. It is a rotating XOR over the area from `0x0e` up to, not including, `0x7fd1`:

1. Start with `c = 0xa5`.
2. For each offset `p` from `0x0e` to `0x7fd0`: if `p` is neither `0x04bc` (the checksum) nor `0x046f` (first byte of the restart block), `c = c ^ byte[p]`.
3. In every case (skipped bytes too), rotate the byte left one bit: `c = ((c << 1) | (c >> 7)) & 0xff`.
4. The result is the checksum byte.

The bytes from `0x7fd1` up (power-fail words, serial area, clock) are outside it. Established: source, and the shipped routine's seed (`-91`),
start (`14`), end (`32721`) and the two skipped offsets (`1212`, `1135`) were read from the image. The source keeps `c` in a signed char; the
rotate is the 8-bit rotate above.

Because XOR then rotate is linear, the result has a closed form, with `N = 0x7fd1 - 0x0e`: checksum = `rotl8(0xa5, N)` xor, for every counted byte
`b` at `p`, `rotl8(b, 0x7fd1 - p)`, rotation counts taken mod 8. Changing one counted byte from `a` to `b` therefore changes the checksum by
`rotl8(a ^ b, (0x7fd1 - p) mod 8)`. Inferred from the algorithm; checked by script against the full loop.

## Validity and what the PROM does on a mismatch

- Valid means: the revision byte at `0x0e` is `4`, and the computed checksum equals the stored one. The checksum is computed again before it is
  called bad, so a single bad read is tolerated. Established (source and image).
- On an invalid store the IO6 PROM prints "NVRAM checksum is incorrect: reinitializing.", then rewrites **every table row** with its default
  (including `passwd_key` and `netpasswd_key`, which become empty), writes `0xff` to `0x7fcb`, sets the revision to `4` and recomputes the checksum.
  Bytes outside the table (inventory, names, free space) are not cleared. Established (source and image).
- On a valid store each variable is read into the run-time environment; a few are repaired: `nogfxkbd` must start with `0` or `1`, `volume` with a
  digit, and a first byte of `Y` makes `AutoLoad` read `Yes`, anything else `No`. Then fields whose first byte is not ASCII (an old or erased area)
  get their default and the checksum is redone. Established (source).
- The node PROM does **not** validate the store: its validity function returns true unconditionally, and it reads the raw bytes. Established
  (source; the image's start-up code agrees).

## What each PROM reads at power-on

| PROM | Reads | Default if blank or invalid |
|---|---|---|
| Node PROM (`ip27prom.img`) | NVRAM `ConsolePath` (`0x11`, 128 bytes) to pick which base I/O board is the console; `dbaud` (`0x297`, 5 bytes) for the console baud rate; the stored partition id (`0x3801`) and stored console path (`0x3802`, 128 bytes) when several nodes share a partition. Flash log: `ForceConsole`, `PartitionID`, `LastModule` (`Origin200Module` on an Origin 200), `DisableMemMask`, `DisableMemSz`, `MemDisReason`, `DisableA`, `DisableB`, `EarlyInitCntA`, `EarlyInitCntB`, `NASIDOffset`, `GlobalMaster`, `DisableIO`, `force_coarse`, `DisableExpress` and others | `ConsolePath` `default` means this board is a console candidate (an invalid path is not treated as a match); module and partition default to `0`, counters to `0`, memory-disable size and reason to `00000000`; an absent `ForceConsole` is not forced |
| IO6 PROM (`io6prom.img`) | the whole table above, through the start-up path, and the log keys `LastModule` (default `1`), `PartitionID`, `DomainID`, `ClusterID`, `CellID` (default `0`), `BackPlane` (`000`), `Premium` (`00`) | the table's default column |

`console` is read only by the IO6 PROM. The table default is `d`, but an empty field creates no variable and the PROM then treats `console` as `g`. How
`g`, `d` and `d2` choose the console is in [prom-console-input.md](prom-console-input.md). Established.

## How `setenv` and `resetenv` write

- **NVRAM, in place.** No log, no append, no erase and no wear levelling (battery-backed SRAM). `setenv NAME VALUE` finds the variable by
  case-insensitive name, copies exactly the field length from the string to the NVRAM, byte by byte in ascending order, then recomputes the
  checksum over the whole area and writes it **last**. The copy does not stop at the string's end: bytes after the terminating NUL come from
  whatever follows the string in the PROM's memory. Established (source and image: the writer loops the field length with no end test).
- Consequence for `console`: `setenv console d` stores `64 xx`. `xx` is the byte after the NUL of the typed word. The setenv command hands the
  writer its argument as parsed, a pointer into the token list the parser builds with the arguments packed back to back (`setenv`, `console`, `d`,
  each NUL-ended) in a stack buffer that is never cleared, so `xx` is the stale byte after `d`'s NUL: `00` only when that byte happens to be zero,
  and a non-zero `xx` reads back as a two-letter `console` (`dX`). The default written by `resetenv` and the reinitialise pass is the table's
  two-byte string, `64 00` (read from the image). Established that the byte is copied and where it comes from (public source for the parser; the
  shipped parser was not read); **unknown** what the stale byte is in a given session. An emulator should write `64 00`, which is what a clean run gives.
- `AutoLoad` stores only the first character, upper-cased. `netaddr` is parsed to four raw bytes. `dbaud` is range-checked first. Established.
- `resetenv` writes every row but the two password keys, then sets the revision and the checksum. The password keys are untouched. Established.
- Writes to the master part are mirrored to each slave base I/O board's part, except offsets `0x3885` to `0x7fd0` in the 6.5.7 source; in the shipped
  IO6 image the byte-copy helper (`0x11c677dc`) skips `0x3926` to `0x7fd0`, the end of `tg0mode` onward (inferred: the helper's bounds, its caller was
  not read); each slave's checksum is recomputed from its own bytes. Single-board machines (Origin 200) have no slave. Established (source).
- **Interrupted write.** There is no journal. A reset after the field bytes but before the checksum byte leaves a stale checksum; the next boot
  fails validation and reinitialises the whole table to defaults (above). Established as the code's consequence; not observed.

## Flash log (node boot flash)

Not used for `console`. Layout from source, with the header layout also matching the image's writer. Established.

| Where | Content |
|---|---|
| Sector 14 and 15, `0x10000` bytes each, one active at a time | active = the sector whose header has the magic and, if both do, the larger sequence number |
| Sector offset `0x00` to `0x0f` | erased (`ff`) |
| `0x10` | magic `0x504c4f47` ("PLOG"), big-endian |
| `0x14` | version `1` |
| `0x18` | sequence number, increases by one at each swap |
| `0x1c` to `0xff` | erased |
| `0x100` onward | entries, each starting on a 4-byte boundary; an erased byte `0xff` where an entry should start is the end marker |

Entry: byte 0 = valid (bit 7, `0` means cancelled), type (bits 6 to 5: `0` variable, `1` list, `2` log, `3` end), CPU slice (bit 4), key length
(bits 3 to 0, at most 15); byte 1 = value length (at most 127, bit 7 zero); then key and value bytes (ASCII `1` to `127`, no NUL); padding to a
multiple of four. Entry size is `(2 + key_len + value_len + 3) & ~3`.

- **Set a variable.** Find the entry. If the new bytes can be had by clearing bits only (flash cannot set a bit), patch it in place. Otherwise
  clear its valid bit and append a new entry at the end. If the sector has no room, erase the other sector, copy the live variable and list
  entries, and write that sector's header last with sequence plus one. Established (source).
- **Interrupted write.** An interrupted compaction leaves the new sector without a header, so the old sector stays active. An interrupted append
  can leave a header and a partly erased key or value; nothing in the code detects it. Established for the order; the append case is inferred.
- **Blank flash.** No magic in either header reads as an uninitialised log: reads return the caller's default and writes fail until the `initlog`
  command erases both sectors and writes a header with sequence `1` (or the larger old sequence plus one). Established.

## Worked examples

Rating: **inferred** for the images below. The algorithm is established; the images assume the PROM's strings end exactly at their NUL, but the real PROM copies the whole
field length from the neighbouring memory, so a real freshly reset store has non-zero bytes after most long defaults and a different checksum.
Recompute over the bytes actually present; never reuse a number from here on a real store.

**Smallest store.** Every byte `0`, revision `4` at `0x0e`, `console` at `0x0f`, checksum `0x04bc` computed. Checked by script against the full loop and
the closed form.

| `console` bytes at `0x0f` | Checksum at `0x04bc` |
|---|---|
| `67 00` (`g`) | `0x90` |
| `64 00` (`d`) | `0x9c` |

First steps for `d` (`c`, then XOR byte, then rotate): seed `a5`; `0x0e`: `a5^04 = a1`, rotate `43`; `0x0f`: `43^64 = 27`, rotate `4e`; `0x10`: `4e^00`,
rotate `9c`; the rest are rotations only, 32,704 more, ending at `9c`.

**Reset store, `console` default.** Zero-filled part; each table row written with its default, NUL-padded; `AutoLoad` `4e`; `netaddr` `c0 00 02 01`;
password keys zero; `0x7fcb` = `ff`; `0x0e` = `04`. 106 non-zero bytes. Checksum `0xef`. After `setenv console g` it is `0xe3`; after `setenv console d` it is back
to `0xef`, equal to the delta rule: `0xe3 ^ rotl8(0x67 ^ 0x64, (0x7fd1 - 0x0f) mod 8) = 0xe3 ^ rotl8(0x03, 2) = 0xe3 ^ 0x0c = 0xef`.

So the minimum for iris to match the PROM: write `64 00` at `0x0f`, recompute the rotating XOR over `0x0e` to `0x7fd0` skipping `0x04bc` and `0x046f`, write the
result to `0x04bc`. On a store that is already valid, nothing else changes.

## Unknowns

1. The stale byte after `d` in the parser's token list at `setenv console d` (second `console` byte): `00` on a clean run, otherwise leftovers of earlier
   commands. A captured serial session with a store dump would settle which. It does not affect validity.
2. The part's contents at power-on before any PROM write, and the free-space bytes between the named fields.
3. Whether the module system controller's 2 KiB NVRAM carries anything the PROMs read as environment.
4. The IO6 PROM's variable table in releases other than the shipped image (6.5.7 differs by the last two rows).

## Review

Independent review against the IO6 image (`io6prom.img`, segment `io6prom`, read in Ghidra as a flat image at `0x11c00000`, decompiles checked against
objdump) and the public 6.5.7 library source. Confirmed, grades unchanged unless noted:

- Layout. All 42 rows of the shipped variable table (48-byte rows: name, default pointer, offset, length) match the page's offsets and lengths,
  including `console` at `0x0f` (2 bytes), the checksum at `0x04bc`, the restart block at `0x046f` and the added `dumpdev` and `tg0mode`. Defaults match
  (`console` `d`, `AutoLoad` `N`, `dbgtty` `/dev/tty/ioc30`, `nonstop` `0`, `scsihostid` `00`, `volume` `80`, `rbaud` `19200`).
- Checksum (`0x11c799e0`). Seed `0xa5` (`-0x5b` as a signed char), offsets `0x0e` to `0x7fd0`, XOR skipped at `0x04bc` and `0x046f`, rotate left one
  bit applied at every offset including the skipped ones; the result is stored at `0x04bc` last. Matches.
- Validity (`0x11c7a32c`): revision byte at `0x0e` equals 4 and the checksum matches, tried twice. Reinitialise (`0x11c81b40`): message, every table row
  from its default (the two password rows from the empty string's neighbourhood, so empty), `0xff` to `0x7fcb`, revision 4, checksum. Writer
  (`0x11c7bfe8`): ascending bytes, the field length with no NUL test, checksum updater (`0x11c7bf20`) last. All match.
- Worked examples, recomputed with an independent script: smallest store `g` `0x90`, `d` `0x9c`; reset store `0xef` with `d`, `0xe3` after `setenv console g`,
  `0xef` again after `d`, and the delta rule gives the same. All reproduce. The page's "106 non-zero bytes" counts the checksum byte (105 plus it).

Corrected: the second `console` byte. The shipped writer copies the field length from the argument pointer, and the setenv command passes the
parsed argument, so the byte after `d` is the stale byte after its NUL in the token list, not necessarily `00` (a claim elsewhere that it is always `64 00`
holds only for `resetenv` and the reinitialise pass, whose default string `d`, NUL is in the image). The page's "unknown" stands, now with the source of the byte named.
The slave-copy exclusion in the shipped image starts at `0x3926`, not `0x3885`. The flash-log header writer (`0x1fc0ab68`) was read: 28-byte erased header, `PLOG` at `+0x10`, version 1 at `+0x14`, sequence at `+0x18`. Not re-read: the node PROM's NVRAM reads, the log entry code and the module controller store.
