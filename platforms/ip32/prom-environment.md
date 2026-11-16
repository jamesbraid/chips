# O2 PROM environment: the flash "env" segment, its checksums and how setenv writes it

The O2 PROM keeps its environment variables (`console`, `netaddr`, `OSLoadPartition` and so on) in one segment of the
boot flash, not in the calendar clock's battery-backed RAM. This page gives the segment layout, both checksums, the
default store, how `setenv`, `unsetenv` and `resetenv` rewrite it, and a byte-exact example for a blank store and for
`setenv console d`. The flash part and its decode are in [prom-rom.md](prom-rom.md) and
[devices/at29c040a/README.md](../../devices/at29c040a/README.md).

Sources and grades:

- **PROM 4.18**, the `firmware` segment of the 431616-byte IP32 PROM image (the build IRIX 6.5.30 ships with), read in
  Ghidra as flat code at `0x81000000`. The routines named below were read in full. Addresses are loaded addresses.
  Strings and tables in the data part sit 8 or 16 bytes below the file position, because the segment holds more than
  one load block: use pointers, not file offsets.
- **IRIX 6.5.7 public source**, the kernel's IP32 flash file and header (`IP32flash.c`, `IP32flash.h`): the kernel's own
  writer of the same segment. Facts are in my words. The shipped 6.5.30 IP32 kernel object carries the same routine
  names and messages (`flash_write_env`, "nvram table overflow") but was not read in full.
- **Flash dump**: the 512 KiB PROM 4.18 image in a public PROM mirror (`ip32prom.rev4.18.bin`, SHA-256
  `a60e19b6d0a1bd807a75383f90d088a2a0b73cf892a72f19f2e897d9c31979f0`) carries an env segment from a used machine.
  Origin of the dump is not recorded: grade **observed**, source machine unknown.
- **Emulator captures** of flash files written by the stock PROM running on a model (about a dozen distinct stores).
  They reproduce the PROM's own output byte for byte against the rules below. They are model behaviour, not hardware.

## Layout

The segment starts at flash offset `0x4000` (CPU address `0xbfc04000`, the first byte after the 16 KiB boot loader
segment). Words are big-endian. The PROM writes a segment of `0x3f0` (1008) bytes there; the factory image and the
kernel's rewrite keep whatever length the existing segment has (the dump above is `0x400`).

| Offset | Size | Content |
|---|---|---|
| `0x00` | 8 | reserved, zero when the PROM writes it |
| `0x08` | 4 | magic `SHDR` (`0x53484452`) |
| `0x0c` | 4 | segment length in bytes, header and checksum word included; a multiple of 4 |
| `0x10` | 1 | name length (3) |
| `0x11` | 1 | version-string length (PROM writes 4; kernel writes 3) |
| `0x12` | 2 | segment type and pad, zero |
| `0x14` | 32 | name `env`, zero filled |
| `0x34` | 8 | version string, zero filled: PROM `v1.0`, kernel `1.0` |
| `0x3c` | 4 | header checksum |
| `0x40` | length - 0x44 | body: `name=value` strings, each ended by a zero byte, the list ended by an empty string; unused tail |
| length - 4 | 4 | body checksum |

The PROM's string pool holds `0x3ac` bytes; with a `0x3f0` segment the pool fills the body exactly. Names are looked up
by an exact `name=` match. All of this is **established** (PROM create and update routines at `0x810394d0` and
`0x810396f0`, loader at `0x81025594`, and the kernel source).

## Integrity rules

1. **Header checksum** (established, PROM `0x81025614`, kernel source). The sum modulo 2^32 of the sixteen header words
   at offsets `0x00` to `0x3c`, including the checksum word, is zero. The word at `0x3c` is therefore minus the sum of
   the fifteen words before it. The segment must start on a 256-byte boundary, the magic must match and the length must
   be a multiple of 4.
2. **Body checksum** (established, PROM `0x81025594`). The sum modulo 2^32 of every word from offset `0x40` up to and
   including the last word of the segment (the segment end rounded up to 4) is zero. The last word is minus the sum of
   the words before it. The checksum covers the unused tail too, whatever it holds.
3. The PROM scans the flash from `0xbfc00000` in 256-byte steps, moving to the next 256-byte boundary after the segment end after each valid header,
   and takes the first valid-header segment named `env` whose body checksum also passes (`0x810253f0`, `0x81025470`).
   Seed is zero; there is no other magic or version check.

**On mismatch** (established, `0x8100a710`): a segment with a bad header or bad body checksum is simply not found. The
PROM then builds the default list in memory and writes a fresh `0x3f0` segment at `0xbfc04000` (`0x8100ac80`). Every
variable is lost, including `passwd_key` and `netpasswd_key`. The same happens when a valid segment's first body byte
is zero (an empty store). That is the failure an earlier emulator write hit: changing `console` in the body without
recomputing the body checksum made the segment unfindable and the PROM wrote the defaults back.

## Defaults and what the PROM reads

Default list (established, the variable table at `0x810552f4`, in table order; the order is the order of the strings in
a freshly written store):

`AutoLoad=Yes`, `console=g`, `diskless=0`, `dbaud=9600`, `volume=80`, `sgilogo=y`, `monitor=h`, `TimeZone=PST8PDT`,
`netaddr=192.0.2.1`, `crt_option=1`.

The table has sixteen more names with no default, so they are absent from a blank store: `OSLoadOptions`,
`SystemPartition`, `OSLoadPartition`, `OSLoader`, `OSLoadFilename`, `rbaud`, `diagmode`, `nogfxkbd`, `keybd`, `lang`,
`scsiretries`, `scsihostid`, `pagecolor`, `nogui`, `passwd_key`, `netpasswd_key`. Setting a variable to an empty value
removes it, so a default cannot be stored empty. After the flash is loaded, any named variable that has a default and
is missing from the flash list is set to its default and the flash is rewritten (`0x8100ad5c`): `unsetenv console`
comes back as `console=g` at the next start.

Variables that are never stored (established, table at `0x81055438`): `DEBUG`, `VERBOSE`, `_udpcksum` (bound to
integers in RAM), and the read-only `gfx`, `cpufreq` and `eaddr` (the Ethernet address comes from the identity chip).

Consumers (software expectation: call sites found by scanning for the string addresses; only the first two were read
in some depth): `console` and `monitor` at `0x8100dde4` (display setup: `monitor` starting with `g` or `G` selects the
graphics-console path; an empty `console` falls back to a default), `dbaud` and `rbaud` at `0x81009ae0` (serial rates,
19200 and 9600 fallbacks) and `0x8100b138`, `AutoLoad` at `0x81039ac0`, `SystemPartition`, `OSLoadPartition`,
`OSLoader`, `OSLoadFilename`, `OSLoadOptions` at `0x810172d8`, `0x81047570`, `0x81048d30`, `diskless` at `0x8101269c`,
`keybd` and `nogfxkbd` at `0x8101ffb8`, `0x81012ac4`, `0x8101fe70`, `diagmode` at `0x810202fc`, `scsihostid` at
`0x8101a424`, `pagecolor` at `0x81030270`, `volume` at `0x81000994`, `sgilogo` at `0x8103caa0`, `nogui` at
`0x810463b0`, `netaddr` at `0x81029e30`. The environment is loaded by the main entry (`0x81000370`) before display
setup, once per start; `init` re-enters through the reset vector and loads it again.

## How the PROM writes

- **Where**: always in place at `0xbfc04000`. No append, no wear levelling, no explicit erase: the AT29C040A erases and
  reprograms a whole 256-byte sector per programming cycle (established for the part by its datasheet; see
  [devices/at29c040a/README.md](../../devices/at29c040a/README.md)). The kernel writes the same segment a 256-byte
  page at a time and verifies each page by reading the last byte back.
- **What is written**: the whole segment each time: header words `0x00` to `0x38`, the header checksum, the body from
  the pool, the body checksum last. The update path (`0x810396f0`) reads the existing header and writes it back
  unchanged, so an existing segment keeps its length; the create path (`0x810394d0`) builds a `0x3f0` header.
- **Byte order and access**: each word goes out as four byte writes, most significant first (`0x81003450`), with the
  MACE flash write-enable bit (bit 0 of the word at `0xbf310008`) set around the whole write (`0x810034e8`). After every
  256th byte the writer waits until a read of that last byte returns what was written. The final short page (`0xf0`
  bytes of a `0x3f0` segment, holding the body checksum) is not polled; the chip starts programming it once byte loads
  stop.
- **`setenv NAME VALUE`** (`0x8100a560`, command `0x8100b138`): refuses read-only variables, updates the in-memory list
  by deleting any old entry and appending `NAME=VALUE` at the end (so `console` moves to the last position), then
  rebuilds the persistent list and rewrites the segment (`0x8100aa64`). The rebuilt list keeps the entries whose name
  is already in the stored segment or in the default table; a name that is neither is kept only with `setenv -p`.
  `setenv -f` takes the same path as plain `setenv`. Values of `dbaud` and `rbaud` also reprogram the serial port.
- **`unsetenv`** (`0x8100b2c4`): reaches the same set routine with an empty value, which drops the entry
  (call chain read, not every branch).
- **`resetenv`** (`0x8100aec8`): clears the list, sets every default again in table order, re-appends `netpasswd_key`
  then `passwd_key` if they were set, and rewrites the segment through the update path. It keeps the two keys and loses
  everything else.
- **The tail**: the body is built in a stack buffer that is not cleared, so after a `setenv` the bytes after the last
  string are stale stack contents (nonzero in several captured stores). The default write in a blank flash copies the
  string pool, whose tail is zero. The body checksum covers whichever bytes are there.
- **Interrupted write**: the PROM has no journal or second copy. A write cut off between sectors leaves a new header
  and early body next to an old tail, so the body checksum fails and the next start rebuilds the defaults (inferred
  from the validation rules above; not run). The kernel zeroes the whole segment if it found the variables corrupt, which
  has the same result.

## Worked example

Blank flash (no valid `env` segment, or all `0xff`): the PROM writes these `0x3f0` bytes at flash `0x4000` (this
store was also produced by the stock PROM on an emulator and matches byte for byte; checksum words below).

```
0000  00 00 00 00 00 00 00 00 53 48 44 52 00 00 03 f0
0010  03 04 00 00 65 6e 76 00 00 00 00 00 00 00 00 00
0020  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
0030  00 00 00 00 76 31 2e 30 00 00 00 00 ce 14 13 8e
0040  "AutoLoad=Yes\0console=g\0diskless=0\0dbaud=9600\0volume=80\0sgilogo=y\0"
      "monitor=h\0TimeZone=PST8PDT\0netaddr=192.0.2.1\0crt_option=1\0"   (0x40 to 0xba)
00bb  zero bytes up to 0x3eb
03ec  c1 1f b2 ba
```

Header checksum: the nonzero words before `0x3c` are `0x53484452`, `0x3f0`, `0x03040000`, `0x656e7600` and
`0x76312e30`. Their sum is `0x31ebec72` modulo 2^32, so the checksum word is `0xce14138e`.

Body checksum: the 235 body words sum to `0x3ee04d46` modulo 2^32; the last word is minus that, `0xc11fb2ba`.

After `setenv console d` (the entry moves to the end; the list length is unchanged, the header is rewritten
identically, so only the body and the last word change):

```
0040  "AutoLoad=Yes\0diskless=0\0dbaud=9600\0volume=80\0sgilogo=y\0monitor=h\0"
      "TimeZone=PST8PDT\0netaddr=192.0.2.1\0crt_option=1\0console=d\0"   (0x40 to 0xba)
00bb  tail
03ec  4d 56 26 87      (tail all zero)
```

With an all-zero tail the body words sum to `0xb2a9d979`, so the last word is `0x4d562687`. The real PROM leaves
stack bytes in the tail, so its checksum word is different; compute it over whatever the tail holds. A writer outside
the PROM may zero the tail. Both examples were computed with a script over these rules; the blank store was also
checked against a store the stock PROM wrote on an emulator (identical bytes), and the header checksum against the
`0x400`-byte segment in the 4.18 flash dump (header and body sums both zero).

## Unknown

- Real-hardware reads of the env segment on a physical O2: none held. Everything above is shipped code, public source
  and emulator output.
- What the AT29C040A leaves in omitted bytes and whether a cut-off write corrupts a sector (the part's datasheet is
  contradictory on omitted bytes, see the part page): decides the interrupted-write result.
- An existing valid segment longer than `0x3f0` with a nonempty body (the kernel's rewrite of a factory-length `0x400`
  segment followed by a PROM `setenv`): the update path appears to write body words past its `0x3ac`-byte pool. Code
  reading only; not run.
- Whether a factory image's valid, empty `0x400` segment rewrites the flash once per default variable at first start
  (the setting loop runs with the segment already known). Code reading only.
- The meaning of every consumer of `diagmode`, `keybd`, `nogfxkbd`, `lang`, `scsiretries` and `pagecolor`; only the
  call sites are known.
- Whether the real kernel at 6.5.22 and 6.5.30 differs from the 6.5.7 source in header version string or length rules.
- The calendar clock's 114 or 242 user-RAM bytes are not used by this PROM for the environment; no use of them by this
  PROM was found, and the kernel's reader of them is separate (see [devices/mace/README.md](../../devices/mace/README.md)).
