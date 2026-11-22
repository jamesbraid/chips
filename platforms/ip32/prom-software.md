# O2 PROM software: layout, environment, console, ARCS tables, configuration tree, boot menu

This page records what the O2 (IP32) system PROM's own code does, read from the shipped flash images with a MIPS
disassembler and Ghidra's decompiler as a map. Nothing here is taken from source, from another emulator or from a
sibling board. Hardware meanings of register bits are out of scope unless the code itself shows the use. Where this page
and the older notes under this directory differ, the older notes were written for a different question and have not
been re-read against this page.

Images. Two O2 PROM images are held, both as a 0x100-byte container header (magic `PROM`) followed by the flash
contents from flash offset 0:

| Release that carried it | PROM revision (banner date) | sha256 | Size |
|---|---|---|---|
| IRIX 6.5 base media | 4.8 (9 Apr 1998) | `820585bed598df75dc2a1dda887b5cd336c560f0575aa065a7cdbc2edbccfab8` | 428 800 |
| IRIX 6.5.30 media | 4.18 (22 Oct 2002) | `11230c353cb14fcc50ede286df228e169e32fc9e5a2206276ae29c259fafb23c` | 431 872 |

These are the only two O2 PROM images in the firmware directory this reading used (checked against the asset manifest).
[`references/prom-images.md`](../../references/prom-images.md) also lists shipped images for 2.3, 3.3, 4.0, 4.3 to 4.7
and 4.9 to 4.17; none of those was read here. It lists a separate 524 288-byte raw flash dump of 4.18 with sha256
`a60e19b6…`; that dump is not among the held images, and neither padding of the held 4.18 image to 512 KiB (`0xff` fill,
with or without the 0x100-byte container header: `8c1898c1…`, `3c7cadba…`) reproduces it. **Unknown** whether the raw
dump differs from the shipped 4.18 flash contents.

Everything below is the 4.18 image (newest held) unless a difference from 4.8 is named. Addresses are flash offsets
(`0xbfc00000` + offset when executing from flash) or run-time addresses of the firmware segment, as marked.

## Grades used

**Established**: read in the disassembly, whole function or table. **Inferred**: a reading built from names, call
shapes or partial paths. **Unknown**: not settled.

## Flash layout (established)

The flash is 512 KiB at `0xbfc00000` (the segment descriptor the PROM carries has base `0xbfc00000`, end `0xbfc80000`).
The image holds five segments, each placed at a 0x100-aligned flash offset. Every segment begins with a branch that
skips its own header, then a 0x40-byte header:

- `+0x08` the ASCII word `SHDR`; `+0x0c` the segment length counted from the segment base;
- `+0x10` name length byte, `+0x11` version length byte, `+0x14` name (up to 32 bytes), `+0x34` version (8 bytes);
- `+0x3c` a header balance word: the 16 words at `+0x00..+0x3c` sum to zero (32-bit wrap);
- body from `+0x40`; the last word of the segment balances the body words to zero.

The code that finds a segment compares the name length byte and the name, then checks the body sum (find routine at
`0x81025470` in the firmware, `0xbfc01750` in the first-stage loader). All five segments of both images satisfy both
sums, including the stock `env` segment (checked by summing the file).

| Segment | Version | 4.18 flash offset / length | 4.8 length |
|---|---|---|---|
| sloader | 1.0 | 0x0000 / 0x4000 | same |
| env | 1.0 | 0x4000 / 0x400 | same |
| post1 | 1.0 | 0x4400 / 0x4d44 | 0x4c34 |
| firmware | 4.18 (4.8) | 0x9200 / 0x5fffc | 0x5f27c |
| version | 4.18 (4.8) | 0x69200 / 0x388 | same |

Reset path (established, flash `0x0000`..): the first instruction is a branch to `0xbfc00048`, which branches to the
first-stage entry at `0xbfc003a8`. The entry tests Status bits 20:19 and bits 13:12 of the 64-bit CRIME word at
`0x14000008`; when either pattern matches it branches to `0xbfc007e8`, which records state at `0x80000400` and ends in a
loop (**unknown** what condition this is). The normal path clears the general and floating registers, saves a 64-bit
value into eight bytes of the real-time clock's battery RAM (below), and at `0xbfc006dc` calls a routine that builds a
stack in the data cache (next section) and calls the loader main at `0xbfc00a80`. The loader main looks up `post1` then
`firmware`, each with its checksum verified (`0xbfc00a90`..`0xbfc00ac0`), clears bits 5:4 of the low word of the 64-bit
register at `0x1f310008`, and calls the `post1` entry with the reset reason, the firmware segment pointer and a third
argument. If `post1` returns, the loader falls to a fallback routine at `0xbfc00b70` and loops (`0xbfc00b34`).
Two forever-loops (`0xbfc00738`, `0xbfc00754`) write `0x400` or `0x800` to the CRIME word at `0x14000008` and toggle bits
5:4 of `0x1f310008` with a delay between toggles (**inferred**: error blink patterns).

Battery-RAM use (established accesses, **inferred** purpose): the first stage writes the 64-bit value it holds at entry to
bytes `0x37`..`0x3e` of the clock chip's RAM, through the MACE ISA window at `0x1f3a0007 + 0x100*n`, and on the other
entry path increments byte `0x3f` (`0xbfc005f0`). No environment variable is stored there.

## Memory and cache initialisation

First stage (established, `0xbfc008f0`..`0xbfc00a58`): before any DRAM is used, a routine writes cache tags with
`cache` Index Store Tag operations so that the 4 KiB at `0x80000000` behaves as RAM, with the stack at `0x80001000`, then
fills it with a pattern. It has three tag-setup paths keyed on the CP0 PRId implementation byte (`0x23`, `0x28`, `0x27`
take the R5000-family path; others use a different cache operation). The fill uses the D-cache.

`post1` (established from strings and the routine at `0xbfc05ad4`): clears bit 0 of the 64-bit CRIME register at
`0x14000008` (the string says "ECC off"), then sizes memory by programming and probing the eight bank-control registers
at `0x14000208 + 8*n` (n = 0..7). It writes `(address>>25 & 0x1f) | 0x100` per bank to test for a 128 MB part versus
32 MB, prints per-bank results (strings "Bank%d = %dM", "no simm installed", "Error, no SIMM in bank0") and the total.
It then copies a bootstrap into RAM ("CopyPOST1"), runs ten data-cache/secondary-cache memory tests (`mem_scache1..10`),
`pcache_init`, `scache_init`, `mem_init`, and the matching `*_verify` routines (strings at flash `0x8b10`..`0x90f8`),
and ends with "This is the end of post1". Which test patterns run and what a failure does beyond printing:
**unknown**, not read.

Firmware (established, run-time):

- Entry stub at `0x81000048` zeroes `0x8105ffe0..0x813fffc0` (uncached alias), stores `1` at `0x81054260`, sets the
  stack to `0xa13fc000` and calls the main routine `0x81000370` in a loop. The first argument is the start reason from
  the first stage, the second a flag.
- Main (`0x81000370`): `0x81004e98(0x30)` (clear both bits of the word at `0x1f310008`, see below), CPU and cache setup
  `0x810040c0`, `FlushAllCaches` `0x81004d18`, trap vector setup `0x810242b8` (copies handlers to `0x80000000`,
  `0x80000080`, `0x80000100`, `0x80000180`), Status register update clearing bit 22 (BEV) `0x81022b80/b90`, a MACE ISA
  byte read-modify-write `0x81002e84` (touches `0x1f3a0a07`, `0x1f3a4a07`, `0x1f3a4b07`), then environment init
  `0x8100a710`, then the chain `0x81000498`: `0x81002b30` (a pool of linked tiles in uncached memory from `0xa1100000`, **inferred**: DMA buffers), graphics/console `0x8100dde4`, environment
  mirrors and the configuration tree build `0x81016950`, A/V timing `0x81002708`, memory size `0x81003cec` feeding
  `0x81007010(0x41400000, size - 0x1400000)` (a loop that programs a block of 0x20000-byte windows; **unknown** role),
  firmware memory descriptors `0x81003ebc`, power-on diagnostic message `0x8100df48`. Then the halt vectors are patched (below) and a dispatch on
  the start reason (`0x81000848`, table at `0x8104938c`).
- CPU and cache setup selects an init routine from PRId bits 15:8 (`0x810040c0`): `0x04` → `0x81005cc0`, `0x09`/`0x0e`
  (R10000/R12000) → `0x810062b0`, `0x20`..`0x22` → `0x81006170`, `0x23` (R5000) → `0x81005770`, `0x27` (RM7000) →
  `0x81006b0c`; anything else prints "Not supported CPU type" and asserts. The R10000 path reads primary instruction and
  data size from Config[31:29] and Config[28:26] as `0x1000 << n`, secondary size from Config[18:16] as `0x80000 << n`
  and the secondary line length from Config bit 13. The R5000 path reads secondary presence from Config bit 17 and size
  from Config[21:20] as `0x80000 << n`, with a 32-byte line. A table of cache routines is filled in per CPU
  (`0x810600c8..0x810600f4`). A debug dump routine (`0x81004230`) prints the sizes it computed.
- Memory size (`0x81003cec`, established arithmetic, inferred meaning): starts at 32 MB (`0x2000000`) or 128 MB
  (`0x8000000`) from bit 8 of the register at `0x14000208`, then for each of `0x14000210..0x14000240` adds 32 MB or 128 MB
  only when that register differs from the one at `0x14000208` (inferred: an unpopulated bank reads back as bank 0).
- Initial memory descriptors (established): `0x81016448` first calls `0x81003e4c`, which adds FreeMemory for pages 0..1
  and FreeMemory from `0x2000` for `((helper(size, 0x10000000) + 0xfff) >> 12) - 2` pages (the helper at `0x81045484`
  was not read; it looks like a minimum), then splits page 0 off as an ExceptionBlock descriptor and the next page as a
  SystemParameterBlock descriptor (`0x81016568`, base `0x1000`). The main chain later calls `0x81003ebc`, which splits
  out three firmware ranges: FirmwarePermanent `0x1000000` for 0x100 pages, FirmwareTemporary `0x1100000` for 0x300 pages
  and FirmwareTemporary `0xd50000` for 0x2b0 pages. The type codes follow the string table at `0x81052da4`: 0 ExceptionBlock,
  1 SystemParameterBlock, 2 FreeContiguous, 3 FreeMemory, 4 BadMemory, 5 LoadedProgram, 6 FirmwareTemporary,
  7 FirmwarePermanent.

Firmware load map (inferred from 1 100+ resolved references and the jump targets): the firmware segment is copied from
its base to `0x81000000` as three chunks described by `{address, length}` pairs inside the segment: text
`0x81000000..0x81048e70` (the segment's own header and branch are at its start), read-only data and strings
`0x81048e70..0x81054100`, initialised data `0x81054100..0x8105ffe0`; zero-initialised data follows. The loader that does
this copy is in `post1`; **unknown** until that code is read.

Cache-resident stack and the `0x1f310008` word (inferred): the 64-bit register at `0x1f310008` is read-modify-written by
`0x81004e98` (set both bits 5:4, then clear the ones named in the argument; called with `0x30` at start and `0x20` in the
menu loop) and by the flash routines; bit 0 set means flash writes enabled (`0x810034e8`). The two-bit pattern looks like
two status LEDs. **Inferred** only.

## Environment and NVRAM layout (established unless marked)

The environment lives in the `env` flash segment at `0xbfc04000`, not in battery RAM. The strings "NVRAM variable" in the
error messages are a name carried over; every save goes through the flash segment rewrite below. **Inferred**: no
RTC-RAM bytes are used for variables (the only clock/RTC strings concern the time of day, `0x8102627c`, `0x81026784`).

- Body (from segment `+0x40`, 0x3c0 bytes on the stock image): a sequence of `NAME=VALUE` strings each ending in a zero
  byte, ended by an empty string. The saver (`0x8100aa64`) asserts that its work buffer (0x3ac bytes at `0x810724f4`)
  fits the segment body, packs the surviving entries, and rewrites the whole segment with the flash write routines
  (`0x810396f0`), recomputing the body balance word.
- On the stock 4.18 image the `env` body is all zero. At start (`0x8100a710`) the code finds the segment by name `env`
  and tests the first body byte. Zero (or no segment) selects the default path `0x8100ac80`, which applies the defaults
  below and creates or rewrites the segment (`0x810394d0`, version string `1.0`, body size 940 bytes). Non-zero selects
  `0x8100ad5c`, which sets each stored variable, then fills defaults for the rest. Variables are held in a table of
  string pointers at `0x81072438` (count at `0x810728a4`).
- Lookup (`0x8100a928`) searches the flash body first, then the default table. Set (`0x8100a560`) takes
  name, value and a mode (0 normal, 1 force, 2 delete-style): it ignores a set of `passwd_key` or `netpasswd_key` to a
  non-empty value unless forced (only `passwd`, `resetpw` and `resetenv` reach those), consults a second table for
  read-only and mirrored variables, then calls the saver.
- Default table, 26 entries of `{name, default, 0}` at `0x810552f4`. Defaults other than empty:
  `AutoLoad=Yes`, `console=g`, `diskless=0`, `dbaud=9600`, `volume=80`, `sgilogo=y`, `monitor=h`, `TimeZone=PST8PDT`,
  `netaddr=192.0.2.1`, `crt_option=1`. Empty defaults: `OSLoadOptions`, `SystemPartition`, `OSLoadPartition`, `OSLoader`,
  `OSLoadFilename`, `rbaud`, `diagmode`, `nogfxkbd`, `keybd`, `lang`, `scsiretries`, `scsihostid`, `pagecolor`, `nogui`,
  `passwd_key`, `netpasswd_key`. The serial driver supplies `19200` for `rbaud` and `9600` for `dbaud` when the value is
  empty or invalid (strings at `0x8104a4fc`, `0x8104a7d8`).
- Mirror and read-only table at `0x81055438`, entries `{name, storage address, flags}`: `DEBUG` → `0x810720d0` and
  `VERBOSE` → `0x810720d4` and `_udpcksum` → `0x810720d8` (flag 2: the numeric value is stored into that word on set);
  `gfx`, `cpufreq`, `eaddr` (flag 1: informative, cannot be set; the message is "Environment variable ... is
  informative only"). `cpufreq` is set from the CPU clock routine and `eaddr` from the board's one-wire ID chip (strings
  `ds2502_*`), both at start (`0x8100a710`, again in `resetenv` `0x8100aec8`).
- Setters and callers (established): the `setenv` monitor command `0x8100b138` (also called through the ARCS
  SetEnvironmentVariable vector entry `0x8100f530`), `unsetenv` `0x8100b2c4`, `resetenv` `0x8100aec8` (remembers both
  password keys, clears the table, re-applies defaults, restores the keys, rewrites flash), the `passwd`/`resetpw`
  commands (`0x810258a0`, `0x810259d0`), and the autoboot path. `setenv dbaud` and `setenv rbaud` reopen `serial(0)` and
  `serial(1)` respectively and reapply the speed (`0x8100b138` tail, calls `0x81016ebc`).
- Checksum: segment sum rule above (header word at `+0x3c`, body balance word at the end). **Established** that the PROM
  recomputes the body balance after every save.

4.8 differences: the default table has 25 entries (no `crt_option`); `no_gbe_reset_war` is absent as a variable name.

## Console paths and input

- Console selection (`0x81016d30`): if the `console` variable is unset it is set to `g`. A table of driver records at
  `0x81054280` (12-byte entries) is scanned for a record with a display hook; if one exists and `console` does not start
  with `d`, ConsoleOut is `video()` and ConsoleIn is `keyboard()`; otherwise both are `serial(0)`. (**Established** by
  disassembly; the table has one display hook, the graphics driver at `0x8102f8d0`, so "display present" is a link-time
  fact, not a probe.) The same variable is read by the graphics init (`0x8100dde4`): `g` or `G`, or a non-zero result
  from a helper, enables the graphics bring-up chain; otherwise the display controller is only quiesced.
- Opening (`0x81016b84`): closes descriptors 0 and 1, opens ConsoleIn (mode 0, must return descriptor 0) then ConsoleOut
  (mode 1, descriptor 1). On a failure it prints "Cannot open ... for input/output" (with "Cannot connect to keyboard --
  check the cable" for the keyboard error), first retries after re-selecting, then sets `NoAutoLoad` to
  `CONSOLE OPEN FAILED.` and retries with `serial(0)`, and halts with "Cannot open any console!" if that fails too.
- Serial: the MACE 16550 driver (`mace_16c550.c` strings, routines `0x81009658..0x8100a184`). `dbaud` is `serial(0)`,
  `rbaud` is `serial(1)` (established from `0x8100b138`). Framing, parity and overrun errors are reported as strings.
- Keyboard and mouse: a PS/2 driver (`0x8101fe70` adds the controller `pckbd` and keyboard peripheral, and `pcms` and a
  pointer peripheral). The controller registers are read at `0x1f320028` (data) and `0x1f320038` (status); a value
  `0xaa` is the keyboard self-test pass. The keyboard component is added when the init flag is clear, or no earlier
  probe succeeded (`0x8101f740`), or `nogfxkbd` starts with `1`. The layout table in `0x8101ffb8` is keyed by the
  `keybd` variable (names such as `de_CH`, `fr_CH`; a "Select Keyboard Layout" menu item changes it). **Inferred**: the
  register meanings; the addresses and the `0xaa` test are established.

Input behaviour when no PS/2 device answers is covered by [prom-console-input.md](prom-console-input.md); this page does
not re-derive it.

## ARCS vectors and the system parameter block (established)

`0x810174d0` builds the SPB at `0xa0001000`: signature word `0x53435241`, length `0x48`, version 1, revision 10,
RestartBlock 0, DebugBlock 0, general-exception vector `0x810175c0`, UTLB-miss vector `0x810176b8`, firmware vector length
`0x8c` (35 entries) at `0xa0001800`, private vector length `0x34` (13 entries) at `0xa0001c00`, adapter count 0. The
vectors are copied from tables at `0x81058840` and `0x810588cc`. After copying, `0x81000528` replaces five entries with
flash routines: Halt `0xbfc0161c`, PowerDown `0xbfc01648`, Restart `0xbfc01674`, Reboot `0xbfc016a0`,
EnterInteractiveMode `0xbfc015f0`. Entries 8 and 19 are zero.

Firmware vector (index, role, target in the 4.18 firmware):

| # | Role | Target | # | Role | Target |
|---|---|---|---|---|---|
| 0 | Load | `0x81014858` | 18 | GetMemoryDescriptor | `0x81016410` |
| 1 | Invoke | `0x8101499c` | 20 | GetTime | `0x8100f2fc` |
| 2 | Execute | `0x81014c6c` | 21 | GetRelativeTime | `0x81003360` |
| 3 | Halt | `0x810005a4` (then flash) | 22 | GetDirectoryEntry | `0x8100f23c` |
| 4 | PowerDown | `0x810005d0` (then flash) | 23 | Open | `0x8100e900` |
| 5 | Restart | `0x810005fc` (then flash) | 24 | Close | `0x8100f0b8` |
| 6 | Reboot | `0x81000628` (then flash) | 25 | Read | `0x8100ecc0` |
| 7 | EnterInteractiveMode | `0x81000578` (then flash) | 26 | GetReadStatus | `0x8100f3d0` |
| 9 | GetPeer | `0x8100bfb8` | 27 | Write | `0x8100ef64` |
| 10 | GetChild | `0x8100bfc0` | 28 | Seek | `0x8100f180` |
| 11 | GetParent | `0x8100bfdc` | 29 | Mount | `0x8100f490` |
| 12 | GetConfigurationData | `0x8100bfe4` | 30 | GetEnvironmentVariable | `0x8100f550` |
| 13 | AddChild | `0x8100c030` | 31 | SetEnvironmentVariable | `0x8100f530` |
| 14 | DeleteComponent | `0x8100c2a4` | 32 | GetFileInformation | `0x8100f570` |
| 15 | GetComponent | `0x8100fb40` | 33 | SetFileInformation | `0x8100f614` |
| 16 | SaveConfiguration | `0x8100c3a0` | 34 | FlushAllCaches | `0x81004d18` |
| 17 | GetSystemId | `0x8100f3c4` | | | |

The role names are the published ARC 1.2 order; the index-to-role mapping is **inferred** from that order, with the
targets' behaviour (Open's nine open modes, Get/Set environment, memory descriptor list walk) agreeing. Private vector
(13 entries at `0x810588cc`): entry 0 `0x81016ebc` is a device-control call (the `setenv` code uses it with request
`0x7404` to apply a serial speed); entry 2 `0x81014928`, 3 `0x81014c48`, 4 `0x81014db8` sit beside Load/Invoke/Execute;
entry 9 is the SPB initialiser `0x810174d0` itself; entry 12 `0x81017e1c` is the CPU clock routine that `hinv` uses.
The other private entries (1 `0x8100b0ec`, 5 `0x8100ff1c`, 6 `0x8100ffbc`, 7 `0x8100e2a0`, 8 `0x81032c28`, 10
`0x8103a678`, 11 `0x810181d0`) are **unknown** in role.

Memory descriptors (established): a node is `{type, base page, page count, magic 0x4b45565e, next}`, sorted by base,
list head at `0x81061770`. `GetMemoryDescriptor(0)` returns the head; any other argument must carry the magic and returns
its next pointer. Splitting is done by `0x81016568`.

Open modes (established, `0x8100e900`): 0 read, 1 write, 2 read/write, 3 create, 4 create read/write, 5 supersede
write, 6 supersede read/write, 7 open directory, 8 create directory; anything else returns error 7.

## Configuration tree

Component entries follow the ARC layout (class, type, flags, version/revision `0x0001000a`, key, affinity, data size,
identifier length, identifier pointer). Class names, in order, from the table at `0x8105f610`: system, processor,
cache, memory, adapter, controller, peripheral. Type names from `0x8105f62c` (0..40): ARC, CPU, FPU, primary icache,
primary dcache, secondary icache, secondary dcache, secondary cache, ternary cache, main, EISA, TC, SCSI, DTI, multi
function, disk, tape, CDROM, WORM, serial, network, display, parallel, pointer, keyboard, audio, other, disk, floppy disk,
tape, modem, monitor, printer, pointer, keyboard, terminal, line, network, PCI, bridge, other. **Note** this makes memory
class 3 and types shifted by one from the ARC 1.2 enumeration after secondary cache (a ternary cache type exists).

Build order and identifiers in the 4.18 firmware (established):

1. Root `SGI-IP32` (class 0, type 0), `0x810039fc`.
2. CPU: identifier chosen from a table by PRId (`0x81003660`: `MIPS-R4000`, `MIPS-R4000FPC`, `MIPS-R5000`,
   ` QED-RM7000`, `MIPS-R10000`, `MIPS-R12000`, `MIPS-R4700`, `MIPS-R4600`, `MIPS-R4400`, `MIPS-?????` and the `FPC`
   forms); its FPU child; then caches: primary I, primary D, then one or two of types 7/8 depending on what the cache
   setup found; then memory (class 3, type 9) (`0x81003a54`). The memory component's key encodes the size.
3. Everything else is built by a walker (`0x8100c3c0`, started at `0x8100bea8` with tag 1 and the root) over the
   12-byte records at `0x81054280` (`{install routine, parent tag, display hook}`). Each record whose tag matches is
   called with the parent component, then the walker recurses into the children it created. Eight records carry tag 1 and
   run in this order (established): `0x81003a54` (CPU, FPU, caches, memory), the graphics driver `0x8102f8d0` (display
   controller, type 21, identifier `SGI-CRM, Rev B`, `Rev C` or `Rev ?`, plus a monitor peripheral, type 31),
   `0x81009248` (network controller, type 20, and a network peripheral, type 37; the identifier names the PHY chip found:
   QS6612X, ICS1889/1890/1892 or DP83840), `0x8100a18c` (serial controller, type 19), `0x81000934` (audio controller,
   type 25, identifier `A3`, key 1, added only when `0x81000910` succeeds), `0x8101fe70` (PS/2 keyboard `pckbd` and mouse
   `pcms` with their peripherals), `0x81019170` (registers the integral Adaptec driver with the PCI layer, no node) and
   `0x81011f28` (the PCI bridge `MACE-PCI`, class adapter, type PCI; its slot scan then calls registered drivers, one of
   which adds the SCSI adapter, type 12, and `0x8101e630` adds disk, tape and CD-ROM peripherals). Three more records
   at `0x810542e0`..`0x810542f8` (`0x810200c0`, `0x81027280`, `0x81035810`) carry tag 0 and were not walked in this flow;
   **unknown** what they are. The builder runs inside `0x81016950` in the main chain, after graphics init.
4. A second copy of the root/CPU/cache builders (`IP32.c` strings, `0x81023664` and `0x810236bc`) sits next to the
   first (`IP32k.c`). Both are present in the image; which one the boot executes is the first (called from the table);
   the second's callers were not found. **Unknown** whether it is dead.

`GetConfigurationData` and `AddChild` are the vector entries; `AddChild` allocates, links as last child, and prints
"WARNING: AddChild %s(%d) different from system" if the new child does not match the system identifier. The tree
printer (`0x8103fe44`, `0x8103fc50`) formats class, type, flags (`Failed`, `ReadOnly`, `Removable`, `ConsoleIn`,
`ConsoleOut`, `Input`, `Output`) and key; cache keys encode line count and size as `1 << n`.

## Boot menu and monitor commands

After start-up the dispatch (`0x81000848`) chooses by reason (table `0x8104938c`): reasons 0 and 1 run the A/V and
volume init (`0x81000994`), the autoboot attempt `0x81039ac0` and then the maintenance menu loop `0x810000e0`; 7
skips the A/V step; 2 goes straight to the loop; 3, 4, 5 and 6 run `0x81000654`, `0x810006d4`, `0x810006f4`,
`0x81000768` (halt, power-off and restart messages such as "Okay to power off the system now" and "Unable to boot; press
any key to continue"). **Inferred** that these reason codes mirror the halt, power-down, restart and reboot vectors.

Autoboot (`0x81039ac0`): runs only when `AutoLoad` starts with `y` or `Y` and `NoAutoLoad` is unset. It prints
"To perform system maintenance instead, press <Esc>" (**inferred**: it then polls for a short time); Esc falls into the menu, otherwise the
boot routine `0x81045a20` loads the `OSLoader`/`OSLoadPartition`/`OSLoadFilename` named by the environment.

Menu (`0x810123f0`, six records of `{label, handler, ?, button image}` at `0x81060c50`): Start System (`0x81012528`),
Install System Software (`0x810125a8`), Run Diagnostics (`0x81012678`, which loads the diagnostics program from the
distribution CD-ROM if present, else from the installed system), Recover System (`0x810129f4`), Enter Command Monitor
(`0x81012988`) and Select Keyboard Layout (`0x81012ac4`). The text title is "System Maintenance Menu" with the prompt
"Option?". **Inferred**: a graphical menu is used when a display console is open and `nogui` is unset. With `diskless` equal to `1` the loop at `0x810000e0` sets flag bit 0 on the second and fourth entries of the menu
descriptor table at `0x81058644` (Install and Recover); what that bit does is **unknown**. Install and Recover ask for a source (local CD-ROM, tape, remote tape or
remote directory via `netinsthost`/`netinstfile`, `tapedevice`) and load `sashARCS`.

Command monitor (`0x8103dec0` over the table at `0x81054100`, prompt `> `): entries are `{name, handler, usage}`; a
leading `.` hides a command from `help` and is skipped when matching. Visible: `auto`, `boot`, `date`, `exit`, `help`,
`hinv`, `init`, `ls`, `passwd`, `printenv`, `off`, `resetenv`, `resetpw`, `setenv`, `single`, `unsetenv`, `version`.
Hidden: `checksum`, `dump`, `fill`, `g`/`get`, `p`/`put`, `go`, `?`, `play`, `reboot`. Handlers: `boot` `0x81047a00`, `date`
`0x8100e784`, `dump` `0x8100b5b8`, `fill` `0x8100a34c`, `go` `0x810478c0`, `hinv` `0x8103fb00`, `ls` `0x81048400`,
`passwd` `0x810258a0`, `off` `0x81032c40`, `printenv` `0x8100b3b4`, `version` `0x810002fc` (prints "PROM Monitor (BE)"
and the version segment string).

## hinv (established)

`hinv [-v] [-t [-p]]` (`0x8103fb00`, flags in `0x81052e88`: `-v` 1, `-p` 2, `-t` 4, `-b` 8). `-b` calls a different
printer through a private vector. Otherwise it records whether the processor has a secondary cache sibling, then walks
the tree from the root's child and prints each node. The summary printer `0x810401b8` switches on class and type:

- System (`0x00000000`): `System: ` followed by the root identifier minus its first four characters (`IP32`).
- Processor (`0x01000001`): `Processor: <MHz> Mhz <cpu identifier>`, then `, <n>M secondary cache` if one is attached,
  `, (cpu n)` when the key is non-zero, `, with FPU` if an FPU child follows. MHz comes from `0x81017e1c`.
- Caches (`0x02000003..8`): `Primary I-cache size`, `Primary D-cache size`, `Secondary I-cache size`,
  `Secondary D-cache size`, `Secondary cache size`, `Ternary cache size`, in Kbytes (key `1 << n` times 4) or Mbytes;
  suppressed unless verbose or when a secondary cache sibling was folded into the processor line.
- Memory (`0x03000009`): `Memory size: <n> Mbytes` (key >> 8).
- Network controller (`0x05000014`) when its identifier starts `MACE`: `Network: <identifier+5> revision <key>`.
- Display controller (`0x05000015`): `Graphics: <identifier minus first four characters>` (for example `CRM, Rev B`).
- Audio (`0x05000019`): `Audio: Iris Audio Processor: version <v> revision a.b.c` when the identifier is `HAL2`,
  otherwise `Audio: <identifier> version <key>`.
- SCSI controller peripheral and disks (`0x0500001a`, `0x0600001b..1d`): `SCSI Device: Controller n ID m` for the
  adapter and `SCSI Disk`/`SCSI CDROM`/`SCSI Tape: scsi(n)disk(m)` forms for each target.

`-t` prints each node through the raw printer `0x8103fe44` instead (indented by depth: class name, type name,
identifier, key); with `-v` it also prints the flags and the component's configuration data (`0x8103fc50`), and with
`-p` the component's path string (`0x810456e4`).

## Differences, 4.8 versus 4.18

Established from a string diff of the two images and the default-table comparison above; function-level differences
beyond that were not diffed.

- New in 4.18: the `crt_option` variable (default `1`) and the `no_gbe_reset_war` variable name; a third flat-panel
  identification string "Mitsubishi 7of9" (4.8 knows Corona and ichiban); the ternary cache type and its
  "Ternary cache size" line; PROM text grew by 0xb20 bytes, read-only data by 0x170, data by 0xf0.
- The segment structure, flash offsets, environment layout, ARCS vector shape, command list and menu strings are the same.

## Not established here

See [the question page](../../questions/ip32-prom-software.md).
