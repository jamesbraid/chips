# IP30 PROM environment: the DS1687 NVRAM and the flash PDS

Question answered: where does the Octane (IP30) PROM keep its environment variables, how is the store protected, and what bytes does a `setenv`
leave behind. Ratings follow [AGENTS.md](../../AGENTS.md).

## Evidence

- The 6.5.7 standalone-library NVRAM and flash code (`stand/arcs/lib/libsk/ml/IP30nvram.c`, `ml/nvram.c`, `ml/sflash.c`, `lib/setenv.c`), the IP30
  NVRAM and flash headers (`IP30nvram.h`, `sflash.h`) and the first-stage PROM's read-only copy (`stand/arcs/IP30prom/rprom_nvram.c`). Read in full;
  facts are written in our own words.
- `root/firmware/IP30prom.bin` (6.5.30, `platforms/ip30/prom.bin`), disassembled with objdump as a cross-check (no Ghidra export was made). Image
  offsets below are file offsets; the program runs at `0x9fc00000` plus the offset. The checksum routine (`0x6b200`), the whole-store reader
  (`0x6b280`), the byte writer (`0x6b45c`), the validity test (`0x6b62c`, revision 7) and the variable table (`0xd4de8`, 28 rows) were read
  and match the source. The reinitialise message and the "old layout" message are present as strings.
- Nothing was read from a real Octane. The clock part itself is in [ds1685](../../devices/ds1685/README.md).

## Where it lives

Almost all variables sit in the 242 battery-backed bytes of the DS1687, registers `0x0e` to `0xff` of its address space. Established (source,
confirmed in the image).

| Store offset | DS1687 access | Size |
|---|---|---|
| 0 to 49 (regs `0x0e` to `0x3f`) | bank 0, direct register | 50 bytes, byte 0 reserved for clock diagnostics |
| 50 to 113 (regs `0x40` to `0x7f`) | bank 0, direct register | 64 bytes |
| 114 to 241 (regs `0x80` to `0xff`) | bank 1, extended RAM: write `reg & 0x7f` to register `0x50`, then use `0x53` | 128 bytes |

The PROM sets Register A to `0x20` (oscillator on, bank 0) for the first two sets and `0x30` (bank 1) for the third, and does so around every
access. It reads all 242 bytes into a memory copy on first use and serves reads from that copy; writes go to the chip and the copy.

Six variables (`OSLoadOptions`, `SystemPartition`, `OSLoadPartition`, `OSLoader`, `OSLoadFilename`, `fastfan`) are **not** in the NVRAM. They live
in the flash PDS, below. Established.

## Layout

Fixed offsets, fixed lengths, one NUL-padded ASCII field per variable. Offsets are store offsets (register is offset plus `0x0e`). Layout
revision 7. Established (source, with every offset and length in the table below also read from the image's variable table, except where noted).

| Offset | Len | Field | Default |
|---|---|---|---|
| 0 | 1 | diagnostics byte | untouched |
| 1 | 1 | checksum | computed |
| 2 | 1 | layout revision | `7` |
| 3 | 2 | `console` | `g` |
| 5 | 6 | `pagecolor` | empty |
| 11 | 8 | `dbaud` | `9600` |
| 19 | 1 | `diskless` | `0` |
| 20 | 1 | `AutoLoad`, stored as `Y` or `N` (first letter, upper-cased) | `Yes` stored as `Y` |
| 21 | 8 | `diagmode` | empty |
| 29 | 20 | `netaddr` | `192.0.2.1` (the string in the 6.5.30 image) |
| 49 | 1 | `nogfxkbd` (`0` or `1`; anything else is reset to the default on read) | empty |
| 50 | 5 | `keybd` | empty |
| 55 | 17 | `passwd_key` (never reset by `resetenv`) | empty |
| 72 | 3 | `volume` (first byte must be a digit or it is reset) | `80` |
| 75 | 1 | `sgilogo` | `y` |
| 76 | 8 | `rbaud` | empty |
| 84 | 1 | `bootmaster` | empty |
| 85 | 8 | `monitor` | empty |
| 93 | 1 | `rebound` | empty |
| 94 | 1 | `boottune` | `1` |
| 95 | 6 | `ef0mode` | empty |
| 101 | 2 | CPU disable word, big-endian: magic `0xb21` in the high 12 bits, CPU mask in the low 4 bits, and bit `0x0020` of the low byte marks it invalid | `b2 10` |
| 103 | 1 | `autopower` | `y` |
| 104 | 4 | count of first-stage PROM flashes | from the flash header, else 0 |
| 108 | 4 | count of main PROM flashes | from the flash header, else 0 |
| 112 | 4 | count of PDS erases | from the flash header, else 0 |
| 116 | 4 | uptime counter | 0 |
| 120 | 1 | `uncachedprom` | empty |
| 121 | 2 | first-stage PROM flags (low 3 bits verbosity, `0x08` main-PROM validate pending, bits 4 to 6 debug, `0x80` test) | untouched |
| 123 | 119 | free | untouched |

`eaddr` has no NVRAM field: the PROM reads the Ethernet address from the IOC3's serial ID part and treats `eaddr` as read-only. Established.

A string variable is "unset" when its first byte is NUL. The reader tests only that byte, so everything after the first NUL is invisible to
software but is covered by the checksum. Established.

## Integrity rule

One byte at store offset 1 (register `0x0f`). Established (source; the image routine at `0x6b200` has the same steps).

1. `sum = 0xa5`.
2. For each store offset `i` from 2 to 241 inclusive: `sum = sum XOR store[i]`, then rotate `sum` left by one bit within 8 bits.
3. The result is stored at offset 1.

The seed makes an all-zero or all-ones store fail. Coverage is the revision byte through the last free byte; offset 0 (diagnostics) and the
checksum itself are not covered. The check is the whole store every time, not per variable.

Validity (the test at `0x6b62c`): the stored byte equals the computed one **and** offset 2 equals 7. One tolerance: if the checksum fails but the
CPU-disable word's invalid bit (`0x0020`, in the second byte, offset 102) is set, the PROM clears that bit in its copy and tests again; if that
passes it prints "Clearing CPU disable mask with diagmode NMI hook.", clears `bootmaster`, and resets the CPU-disable word to `b2 10`. This covers a
crash during a CPU-mask update. Established.

## On a mismatch

At power-on the PROM tests validity once, early (the first-stage PROM only reads; it never repairs). The main PROM, on failure:

1. Tries layouts 2 to 6 (same checksum rule, different revision byte). If one matches it prints "old NVRAM layout; converting to new layout." and
   upgrades field by field (adds `bootmaster`, `autopower`, flash counters, `uncachedprom`, first-stage flags and `boottune`), then continues.
2. If no old layout matches (a wrong checksum always lands here) it resets the CPU-disable word, sets the flash counters from the flash headers and the
   uptime to 0, prints "NVRAM checksum is incorrect: reinitializing.", writes the default of every variable in the table order below, and finally
   writes revision 7, which also rewrites the checksum. Every variable is lost, `passwd_key` included (set to empty). The flash PDS is not touched
   by this path.

The table order the image uses for the defaults pass: `OSLoadOptions`, `SystemPartition`, `OSLoadPartition`, `OSLoader`, `OSLoadFilename`,
`AutoLoad`, `rbaud`, `bootmaster`, `fastfan`, `console`, `diagmode`, `diskless`, `nogfxkbd`, `keybd`, `ef0mode`, `dbaud`, `pagecolor`, `volume`,
`sgilogo`, `autopower`, `monitor`, `rebound`, `netaddr`, `eaddr`, `passwd_key`, `boottune`, `uncachedprom`. Established (image table).

This is the failure the checksum rule exists to avoid: a changed byte with a stale checksum looks like a trashed store and the whole environment is
reset on the next boot.

## What is read at power-on

Every variable above is read into the environment once (the "initialise strings" pass), with these tests: `console` is also forced to `g` (with
`ConsoleWarning`) when the password jumper is pulled; `nogfxkbd`, `volume` and `passwd_key` are validated as in the table. Empty fields stay unset.
`console` starting with `d` selects the serial console; any other first character selects graphics when a board and keyboard are available (see
[prom-console-input](prom-console-input.md)). `diagmode`, `AutoLoad`, `boottune`, `volume`, `autopower`, `nogfxkbd`, `bootmaster`, `uncachedprom`,
the CPU-disable word and the flash counters are consumed by boot code. Established that they are read; the later effect of each is outside this page.

## How a write works

Established (source; the byte writer at `0x6b45c` matches).

- `setenv NAME VALUE` for a name in the table calls the store writer with the value's address and the field's fixed length. The writer copies exactly
  that many bytes from the string, **without stopping at the NUL**, so bytes after the terminator come from whatever follows the string in memory.
  The PROM then recomputes the checksum over its memory copy and writes it to register `0x0f`.
- Writes are in place, byte by byte, ascending, through the same bank rules as reads. Data first, checksum last. There is no journal, no second
  copy, no wear levelling (the part is battery RAM) and no erase step.
- An interrupted write therefore leaves new data with the old checksum: the next boot fails validation and reinitialises everything (above).
  Inferred from the ordering; nothing records a real interruption.
- `AutoLoad` keeps only the upper-cased first letter. `dbaud` is checked against the list of valid serial rates (an invalid value is replaced). The
  values `rbaud`, `monitor` and the others are stored as typed, truncated to the field.
- `resetenv` resets the CPU-disable word, invalidates every flash PDS variable, writes the table default to every field except `passwd_key` (kept)
  and `eaddr`, then writes revision 7 and the checksum (each field write also rewrites the checksum). The flash counters and uptime are not touched.
- Setting a variable to empty writes the empty string, so the first byte becomes 0 (and the rest is whatever followed the terminator).

## Flash PDS variables

The six PDS variables (offset 555, "variable is in flash" marker, never an NVRAM offset) live in the last 64 KiB block of the boot flash at the
selected base plus `0xf0000`. Layout and rules, established from source; the flash chip and its command sequences are in
[flash](flash.md) and the Origami `ip30-flash` datasheet.

- Header, 24 bytes: magic `0x46504453` ("FPDS"), 32-bit erase count, a 14-byte timestamp (seven 16-bit fields), and a 16-bit checksum. The
  checksum is the Internet one's-complement sum of the 24 bytes taken with the checksum field zero, complemented and stored; a header validates when
  the complement of the sum over all 24 bytes, including the stored field, is 0. Software expectation (the summing routine in the library was not
  read).
- Entries follow, 16-bit aligned. Word 0: type in the high byte (`0x01` environment, `0x10` log, `0x40` and `0x80` data) and data length in
  16-bit words in the low byte. Word 1: valid flag, `0xffff` valid, `0x0000` invalidated. Then the data. An environment entry's data is the
  string `NAME=VALUE` with its NUL, padded to an even length, at most 128 bytes. Word 0 equal to `0xffff` is free space.
- On a bad or missing header, the PDS block is erased if not blank and a fresh header is written (erase count from the NVRAM counter plus one,
  which is also written back to NVRAM offset 112). The message is "WARNING: Bad/Uninitialized Flash Persistant Data Storage Header".
- `setenv` on a PDS variable: if the same name has a valid entry with the same value, nothing is written. Otherwise the old entry's valid word is
  written to 0, and the new entry is appended in two flash writes (word 0, then the data, skipping the valid word). When the block fills, a compress
  pass erases the block and rewrites only the valid environment and data entries. Setting empty just invalidates.
- `resetenv` invalidates every valid environment entry. Load at power-on walks the valid environment entries and splits each at the first `=`.
- Interruption: the old entry is invalidated before the new one is written, so a power loss between the two loses the variable; a loss after
  word 0 but before the data leaves a valid-looking entry with erased data, which load reports as "Bad PDS env entry" and skips. Inferred from the
  order of operations.

## Worked example

Assumptions: layout 7, the 6.5.30 defaults above, every field NUL-padded to its length (the real PROM leaves stray bytes after the terminator, see
unknowns), flash counters 0, offset 0 and the free area 0, first-stage flags 0.

Non-zero bytes of the blank store (offset: value):

```
1: checksum   2: 07   3: 67 ('g')   11: 39 36 30 30 ("9600")   19: 30 ('0')   20: 59 ('Y')
29: 31 39 32 2e 30 2e 32 2e 31 ("192.0.2.1")   72: 38 30 ("80")   75: 79   94: 31   101: b2 10   103: 79
```

Checksum, computed with the rule above (verified with a short script, not committed): offsets 2 to 241 folded with seed `0xa5` give `0x9e`.
So the blank store has offset 1 = `9e`, in register terms register `0x0f` = `0x9e`.

After `setenv console d` the writer copies two bytes into offset 3 and 4: `64 00` (`d`, NUL), recomputes, and writes register `0x0f` = `0x1f`. Only
offsets 1, 3, 4 differ. In register terms: bank 0 register `0x11` = `0x64`, register `0x12` = `0x00`, register `0x0f` = `0x1f`.

If the second byte were some other value `x` (which the real PROM may write) the checksum changes accordingly; both are valid because the checksum
covers whatever is stored.

## Unknowns

1. The second byte the PROM writes after `d` in `console`: it is the byte following the value's terminator in the command buffer, not traced. The
   PROM accepts any value there. A writer should store NUL.
2. The bytes after each terminator in the blank-reset pass. The writer copies the field length from the default string's address, so the real
   result contains neighbouring read-only data (for example `passwd_key` picks up part of the `9600` default's neighbourhood). Not exact in the
   example above; harmless to validity. Also not traced: the string the `dbaud` writer copies from.
3. Power-on state of a fresh part with the clock oscillator off or the lithium cell flat: the PROM's clock start and valid-RAM checks were not
   traced here (see [ds1685](../../devices/ds1685/README.md)).
4. Whether the first-stage PROM (a separate image not in `IP30prom.bin`) ever differs from the shared source; it was read from source only.
5. The diagnostics byte at offset 0: reserved by the header, who writes it was not traced.
6. Flash PDS summing routine and compress/erase timing: source read, library routine for the sum not read, nothing observed on hardware.
