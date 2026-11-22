# Indigo R4000 (IP20) PROM 4.0.5D Rev A: what its own software does

This page records what the shipped IP20 PROM image `SGI Version 4.0.5D Rev A IP20,  Aug 19, 1992` does: part 070-8116-004,
524288 bytes, sha256 `e6e1f1ed90d5979ef5829f823c2a4ff65ea24c3273a2b065a8b71abeba97f82f`. The image is listed in
[prom-images.md](../../references/prom-images.md); the checksum was recomputed on the copy read here and matches. It is read from the
image alone, as MIPS code loaded at virtual `0xbfc00000` (image offset = address minus `0xbfc00000`). Addresses below are image addresses in
that window; the `0x9fc` and `0xbfc` windows are the same bytes.

Grades: **established** (read in full in the disassembly), **inferred** (reasoned from a partial read, a name or a public header),
**unknown**. Disassembly is from the MIPS objdump in the toolchain container, over the whole image; the decompiler was not used. Register
names for the memory controller (MC) come from the public Linux `arch/mips/include/asm/sgi/mc.h` (v5.3), the names for the first peripheral
controller (HPC1) from the public NetBSD `sys/arch/sgimips/hpc/hpcreg.h`. The ARC component and memory-type numbers follow the public ARC
specification and the same NetBSD tree. Cross-references that only name a binary address were each confirmed by finding the `lui` plus
offset pair (or the data word) in the listing; where this page says nothing refers to an address, that is a scan of every
`lui`/`addiu`/`ori`/load/store pair in the image and of every aligned data word, not a proof against computed addresses.

Companion reading of the same family: [the Indigo2 page](../ip22/prom-software.md) and [the O2 page](../ip32/prom-software.md). The
byte-order survey across all held PROMs is [byte-order.md](../../software/firmware/byte-order.md); this page adds to its IP20 section: the
routine that does the byte-order work the string describes, a fifth NT default entry (`scsihostid`), and the absence of a CPUCTRL0 byte-order
helper in this image.

## Answers first

1. **Windows NT boot defaults.** The four variables `SystemPartition`, `OSLoadPartition`, `OSLoader`, `OSLoadFilename` (and a fifth,
   `scsihostid`) have an alternative default taken from a pointer table at `0xbfc45c40` instead of the record's own empty default, **only
   when a RAM flag at `0xa8741070` is non-zero**. That flag is set in exactly one place, a run-time test of the CPU's own byte order at
   `0xbfc08e00`: it is non-zero only if the CPU is running little-endian when that routine executes. The table is read by the environment
   initialiser (`0xbfc08ec0`, NVRAM invalid path), by `resetenv` (`0xbfc097d8`), by the NVRAM format-migration routine (`0xbfc2b530`) and by the
   validation pass over a valid NVRAM (`0xbfc08ec0`, second half). Established. On the normal path the reset code never lets a little-endian CPU
   reach `0xbfc08e00` (below), so the table is dead on a machine that behaves as the reset code expects. Inferred. A little-endian boot path
   does not complete: the PROM's program loader reads little-endian ECOFF images (and byte-swaps their headers) but then refuses to start
   them with "file loaded but not executed: opposite endian", and it does not recognise a PE image at all. Established.
2. **"Setting endianness."** Nothing in the image refers to that string. The routine that does the work, in the same order position as the
   string among the other start-up progress strings, is `0xbfc08e00`: it measures the CPU's byte order and, if the HPC1 byte at
   `0xbfb800c3` answers, sets or clears its low five bits. It does **not** touch the MC. The Config.BE test and the byte-order flip are a
   separate, earlier step at the reset vector. Established for the code, inferred for the string-to-routine pairing.
3. **RAM.** The probe code places the first bank at physical `0x08000000` and packs the rest after it (largest first), skipping from
   `0x18000000` to `0x20000000`. Nothing here programs RAM at physical 0 or 6 MiB. Physical `0x0` to `0x1fff` is described as RAM
   and used (exception vectors at `0x80000000`, the ARC block at `0xa0001000`). Established. How far above `0x2000` the low alias reaches is unknown.

## Reset path and the Config.BE test (established)

The first word at `0xbfc00000` is `j 0xbfc003c0`; the next vectors jump to `0xbfc0074c`. The reset routine at `0xbfc003c0`:

1. Status is written with `0x00410000` (BEV and DE bits), Cause, PageMask, WatchLo and WatchHi are cleared, and Config is written with `3`
   (`0xbfc003d8`..`dc`), then read back (`0xbfc003e0`).
2. `andi v0,v0,0x8000` (`0xbfc003e8`) isolates Config bit 15 (BE). A **set** bit branches over the flip (`bnez` at `0xbfc003ec`); a **clear**
   bit does `jal 0xbfc01320` (`0xbfc003f4`). So the flip runs only when the CPU came up with BE clear, that is little-endian by the R4000
   description of the bit. That Config.BE ignores the write (the written `3` has bit 15 clear, yet the test would loop forever if it
   took effect) is inferred; the R4000 manual is the route to settle it.
3. `0xbfc003fc` reads the word at `0xbfb800c0` (HPC1 base plus `0xc0`), and if bit 0 is set writes zero to the whole word. Established as code;
   the name is NetBSD's `HPC1_BIGENDIAN` register (five endian bits, two revision bits; `0xbfb800c3` is the same register's low byte as a
   big-endian CPU addresses it). Inferred: this clears a little-endian request left in the HPC.
4. MC `+0xec` and `+0xfc` are zeroed. CPUCTRL0 (`+0x04`) is written whole with `0x3c002014 | ((line/8 + 4) << 20)`, where `line` is
   16 when Config.SC (bit 17) is set and otherwise `1 << (Config[23:22] + 4)`; CPUCTRL1 (`+0x0c`) gets `0x16`; `+0xd4` gets `0x11453433`,
   `+0xdc` gets `0x34332`. The value written to CPUCTRL0 has bit 17 (`LENDIAN`) clear, bit 16 (`WRESETPMEM`) clear and bit 18
   (`WRESETDMEM`) clear. This is the only MC endianness-bit write the image makes, and it is a whole-register store, not a
   read-modify-write. No routine sets or clears `0x20000` or `0x40000` in CPUCTRL0, and the strings "CPUCTRL0" and "Big Endian" are absent (the
   Indigo2 helper that prints them has no counterpart here); every CPUCTRL0 write site found is listed in the device map. Established (the constants are in the listing; the bit names are the public header's). An 625-tick wait on the MC
   refresh counter at `+0x1004` follows.
5. Then, in order: `0xbfc0089c`, `0xbfc0096c`, `0xbfc008f8` (peripheral set-up in `0xbfb8xxxx`), `0xbfc023e0` with `s8 = 0xbfc020d0`, `0xbfc028b0`
   (a write and read-back test of MC `+0xd4` with a walking one bit, CPUCTRL0 bit 4 cleared around it and restored), `0xbfc02960`, `0xbfc00a00` (memory
   sizing), a test of the bank words, `0xbfc0059c` (CPUCTRL0 low nibble forced to 2) and `j 0xbfc015c0`, the main start-up routine.

## The flip routine and what runs little-endian (established unless marked)

`0xbfc01320`: save `ra` in `k1`; read EEPROM word 0 (`0xbfc01414`, command `0xc000`), `xori a1,v0,0x8400` (`0xbfc0132c`); write it back
(`0xbfc01490`: enable-write `0x9800`, write `0xa000`, disable `0x8000`, with a ready poll at `0xbfc0154c`); then `lui v1,1; sw v1,0(v0)` with
`v0 = 0xbfa00000` (`0xbfc01340`), and `jr k1`. The bit-bang is the standard 16-bit-word microwire read of 16 bits and write of 16 bits through
a 32-bit register at **MC `+0x30`** (bit `0x1` PRE, `0x2` chip select, `0x4` clock, `0x8` data to the chip, `0x10` data from the chip).

- Callers (every `jal` and `j` scanned): the flip routine is called only from `0xbfc003f4`; the word write only from the flip; the word read
  only from the flip. The six references to `0xbfa00030` all lie in `0xbfc0134c` to `0xbfc015b8`. No other code writes the EEPROM register or
  stores `0x10000` to MC `+0`.
- **Why `+0x30` and `+0`.** The public header has the EEPROM register at `+0x34` and CPUCTRL0 at `+0x04`, one word above those. Inferred: the R4000
  system bus is 64 bits wide and the MC's 32-bit registers sit on one half of it, so a little-endian CPU, which swaps the word lane, reaches
  the register that a big-endian CPU finds at `+4` at `+0` instead. That explains both addresses; the flip routine is written for the
  little-endian view. The same swap explains the one byte access: the ready-poll loop toggles the byte at `0xbfb801bc` (`lb`/`sb` at
  `0xbfc0158c`, `0xbfc015a4`), whereas the big-endian code toggles the HPC1 auxiliary byte at `0xbfb801bf` (below).
- The value stored is `0x10000`, which the public header names `WRESETPMEM` (warm reset, memory preserved), CPUCTRL0 bit 16. It is not the
  `LENDIAN` bit (`0x20000`) or the `WRESETDMEM` bit (`0x40000`). Inferred: it restarts the CPU so that the mode stream is re-read from the
  EEPROM word just written. XOR mask `0x8400` changes bits 15 and 10; what bit 10 does is unknown (no other code names it).
- **Code that executes correctly when fetched little-endian.** The path from `0xbfc003c0` to `0xbfc003fc` contains no load or store at
  all, and `0xbfc01320` to `0xbfc01548` use only word loads and stores to the MC plus the single HPC byte pair above; the 32-bit instruction
  words are unaffected by the CPU's byte order because the R4000 fetches instructions a word at a time. So the test, the flip and the
  restart request execute correctly on a little-endian CPU. Inferred (nothing was run; the code shape and the odd addresses support it).
  The next stage does not: after the test the reset path stores to MC `+4`, `+0xc`, `+0xc4` and so on at their big-endian offsets,
  which on the lane-swap reading reach different registers when little-endian. So a CPU that survived the flip without restarting would run
  the rest of the start-up with the MC mis-addressed. Inferred.

## "Setting endianness." and the run-time test at `0xbfc08e00`

The string `Setting endianness.\r\n` is at `0xbfc42bb0`, one of seven progress strings in a block that also holds "Initializing
primary/secondary caches.", "Initializing exception handlers.", "Initializing environment.", "Executing remainder of diagnostic.",
"Initializing software and devices." and "All initialization and diagnostic completed.". **None of the progress strings
(`0xbfc42b60` to `0xbfc42c34`) is referenced** by any address pair, immediate in range, or data word in the image, so nothing prints them in this build.
Established as a scan result. The Config.BE test at `0xbfc003e8` runs before any console exists and cannot be this step.

The main routine at `0xbfc015c0` calls, in order: `0xbfc0753c` (primary and secondary cache set-up, below), `0xbfc01bf8`, `0xbfc08b28` (copies
exception-vector stubs from ROM `0xbfc073e0` and `0xbfc07408` to `0x80000000` and `0x80000080`), `0xbfc36904(0)` (Status = 0), **`0xbfc08e00`**, **`0xbfc08ec0`** (environment
initialisation, below), `0xbfc01f5c`, `0xbfc02fa0`. The order cache, exception, [endianness], environment is the order of the strings, which is
why `0xbfc08e00` is the best match for "Setting endianness" (inferred; the reference itself is missing). `0xbfc08e00` does:

1. Store `0x11223344` to the stack and read back the byte at the lowest address. If it is `0x44` the CPU is little-endian and the word at
   `0xa8741070` is set to 1 (`0xbfc08e1c`..`28`). This is the only store to that word in the image. It is zero when the routine runs because the memory-sizing step clears RAM (inferred; `0xbfc00798` re-zeroes the PROM data area on restart paths only).
2. Read the byte at `0xbfb800c3` through the guarded-access helper `0xbfc2a5b0` (it saves and installs a bus-error handler; returns 0 when the access
   succeeds; tail not read, inferred).
3. Access succeeded: if the CPU is little-endian, OR `0x1f` into the byte; otherwise AND it with `0xe0`. So the five endianness bits of the HPC1 register
   are all set for a little-endian CPU and all cleared for a big-endian one (the register's meaning is NetBSD's; the stores are in the listing).
4. Access failed (no register): if the CPU is little-endian, set the word at `0xa8740da0` to 1. That word is read by the Ethernet driver
   (`0xbfc10fec`, `0xbfc11688`), which then word-swaps its packet buffers. Established; the purpose is inferred from the swap call.

The byte test and the table lookup are therefore the PROM's only checks of its own byte order. **Under the reset path above the flag is 0 on any
CPU that reaches this routine**, because a little-endian CPU is restarted first. The flag can be 1 only if the restart store does not
take effect (or on a mode-pin arrangement not covered by the EEPROM). Inferred; a physical little-endian experiment would settle it.

## Windows NT boot defaults and the loader (question 1)

Table: 25 words at `0xbfc45c40`..`0xbfc45c9f`, indexed by the record number of the 44-byte environment record table at `0xbfc45760`
(index = (record address minus `0xbfc45760`) / 44). Non-zero entries (established, full table dumped):

| Index | Variable | NT value |
|---|---|---|
| 0 | `SystemPartition` | `scsi()disk(1)rdisk()partition(1)` |
| 1 | `OSLoadPartition` | `scsi()disk(1)rdisk()partition(1)` |
| 2 | `OSLoader` | `osloader.exe` |
| 3 | `OSLoadFilename` | `\nt\system\ntoskrnl.exe` |
| 14 | `scsihostid` | `6` |

(byte-order.md lists the first four; index 14 is the fifth, pointer `0xbfc45d10`.) Everything else, including `OSLoadOptions` and `console`, keeps
its record default (empty, `g`, and so on).

Readers, each testing `0xa8741070` first (established):

- `0xbfc08ec0` (environment initialiser, call `0xbfc015f0`). If the NVRAM check `0xbfc2b044` fails it prints "NVRAM checksum is incorrect:
  reinitializing the NVRAM.", tries the legacy-layout migration `0xbfc2b4b4`/`0xbfc2b530` and otherwise walks the records
  (`0xbfc08f44`..) writing the default of each one: the default is `table[index]` when the flag is set and the entry is non-null,
  else the record's own default (`+0x20`). If NVRAM is valid it walks the records again from `0xbfc09098` and **skips an empty stored value**;
  a stored value that fails its check is defaulted the same way. So the NT value lands only on a reinitialised or invalid-valued NVRAM.
- `0xbfc097d8` (`resetenv`, command table) resets every record except keys `203` (`passwd_key`), `220` (`netpasswd_key`) and `250` (`eaddr`) the same way.
- `0xbfc2b530` (legacy NVRAM migration) resets a list of variables (`OSLoader`, `OSLoadFilename`, `OSLoadOptions`, `SystemPartition`,
  `OSLoadPartition`, `TimeZone`, `FWSearchPath`, `scsiretries`, `scsihostid`, `netpasswd_key`, `keybd`, `lang`, `sgilogo`, `nogui`) to defaults at `0xbfc2b70c`..`2b7b8`, with the same table.
- Table length: the table has 24 words but `netpasswd_key` is record 24, so the initialiser's key-`220` branch (`0xbfc08f94`) and `0xbfc090d4` read
  index 24, which is the first four ASCII bytes of the string `scsi()...` (`0x73637369`), used as a pointer when the flag is set. Arithmetic
  established; the fault that would follow is inferred. Not reachable unless the flag is set.

Boot, the loader and what a little-endian image meets (established unless marked):

- The stock boot variables are the ARC ones: `SystemPartition`, `OSLoader`, `OSLoadPartition`, `OSLoadFilename`, `OSLoadOptions`,
  `ConsoleIn`, `ConsoleOut` (name table at `0xbfc533f0`). The path vocabulary includes `scsi`, `disk`, `rdisk`, `partition`, `serial`, `video`,
  `keyboard`, `pointer`, `network`, `multi`, `eisa`, `cdrom`, `fdisk` (`0xbfc5a668`..). Whether an empty key like `scsi()` is accepted: the component
  parser `0xbfc2bc4c` requires the key text to end exactly at `)` and uses the library number parser `0xbfc3adfc`; with a standard
  parser an empty key passes. Inferred; not traced to the end.
- The loader (Load `0xbfc28714`, header reader `0xbfc28cb4`, Execute `0xbfc28ba4`) takes an ECOFF header. It accepts `0x160`, `0x163`, `0x140`
  (big-endian) and byte-swapped `0x162`, `0x166`, `0x142` (little-endian). For a little-endian magic it sets a flag (`0xa8744ad0`) and swaps the
  file header, a.out header and each section header (`0xbfc28ed4`..`0xbfc290e8`, swap helpers `0xbfc36834`, `0xbfc3684c`), so the image **is
  loaded**. Any other magic prints "Illegal f_magic number 0x%x, expected MIPSELMAGIC or MIPSEBMAGIC." and returns 15. A PE image
  (`MZ`) is therefore rejected; no PE or `MZ` check exists in the loader.
- Execute (`0xbfc28ba4`) calls Load and then, if the little-endian flag is set (`0xbfc28c28`), prints "WARNING: file loaded but not executed:
  opposite endian" and returns success **without invoking** (`0xbfc28c44`). The flag test does not compare with the CPU's byte order, so a
  little-endian file is never executed by Execute even on a little-endian CPU. Invoke (`0xbfc28868`) has no such test; a client that calls Load and Invoke
  separately would reach it. Established.
- The `boot` and `auto` commands (`0xbfc37080`, `0xbfc388e0`) call Execute (`0xbfc37318`, `0xbfc387a4`), as does the start-up autoload below. So **the NT boot path stops at
  the loader**: `osloader.exe` is not an ECOFF file in any NT release this page was checked against (no copy was read; a PE image is the expectation, inferred), and a
  little-endian ECOFF would load but not run. The reset-time restart to big-endian (above) precedes all of it.

What would settle the open parts: a run of this PROM on a little-endian-configured machine or an R4000-and-MC specification (does the restart
take effect, what does Config.BE ignore), and the NT osloader image header (its machine field), neither held here.

## Memory sizing and where RAM sits (established unless marked)

`0xbfc00a00` clears the two bank registers (MC `+0xc4`, `+0xcc`; each holds two 16-bit bank words, banks 0 and 2 in the high half) and for each
of four banks: sets the word to `0x3f20`, probes the size with the pattern routine `0xbfc00d1c` (it tries eight sizes by the 4 MiB doubling
steps, using test words at `0xa8000000` and `0xac000000`, i.e. physical `0x08000000` and `0x0c000000`), programs the size word
(`0xbfc00f1c`: `((size-1) << 8)`, bit `0x4000` when a sub-bank pattern applies, valid bit `0x2000`, base byte `0x20`), runs an address test
(`0xbfc02b50`) over `size << 22` bytes at `0xa8000000`, and clears the word on failure. `0xbfc00f64` then places the banks. Public header field names:
base `0xff` (in 4 MiB units), size `0x1f00`, valid `0x2000`, sub-banks `0x4000`.

- **Placement.** Banks are assigned bases starting at 32 (`32 << 22 = 0x08000000`), largest size first (a 32-unit step, halved each pass), each base
  advancing by that step; when the running base reaches 96 (`0x18000000`) it jumps to 128 (`0x20000000`). So the first window is
  `0x08000000` to `0x17ffffff` (256 MiB) and further memory starts at `0x20000000`. Total memory is the sum over banks of
  `((word & 0x1f00) + 0x100) << 14` for valid banks (`0xbfc010a8`). No base below `0x08000000` is ever programmed.
- Failure messages (`0xbfc01114`, `0xbfc011d4`, `0xbfc01188`): "Memory diagnostic (memory probe) \*FAILED\*: No usable memory found. Make sure you
  have a full bank (4 SIMMs)", "Memory diagnostic (address test) \*FAILED\*", and a per-bank "Bank N memory diagnostics (data test) \*FAILED\*; Check or replace: SIMMn".
  The largest bank allowed by the size field is 32 units of 4 MiB, 128 MiB.
- After the test the PROM programs the MC DMA block (`+0x2004`..`+0x204c`, size from the bank sum, waiting on a busy bit `0x40` at `+0x204c`) and
  zeroes cache tags at `0x88100000`, `0x88200000`, `0x88400000` (index store tag), the memory-clear idiom of the Indigo2 page. Roles inferred from the writes.
- **NT's needs.** It wants RAM at physical 0, and at 6 MiB, below 512 MiB. The PROM never programs a bank at base 0, so a bank-0 base at
  `0x08000000` (128 MiB) is the lowest RAM it leaves mapped. Yet the PROM itself **uses physical 0**: `0xbfc08b28` copies exception stubs to
  `0x80000000` and `0x80000080`; the ARC block is built at `0xa0001000`; the descriptor list (below) calls pages 0 and 1 memory. Established.
  So a low alias of the first bank at physical 0 exists, at least for 8 KiB. Inferred from the PROM writing and reading there. Where it ends
  (6 MiB for NT) is unknown. The first window `0x08000000`..`0x17ffffff` is above 128 MiB; NT's "below 512 MiB" holds for the first
  window (256 MiB) but not for memory placed at `0x20000000` (512 MiB). Inferred from the placement rule.
- The PROM's own working RAM: it zero-fills `0x88740000`..`0x887ffffc` (kseg0 alias of `0x08740000`..`0x087fffff`; `0xbfc00798`) and keeps its
  variables at `0xa8740000` and above, with the stack at `0xa87ffff0` and below. Established from the clear loop and the address constants.

## Caches (established)

`0xbfc0753c` (main routine step 1): primary instruction cache size = `1 << (((Config >> 9) & 7) + 12)` (`0xbfc07564`), primary data cache size =
`1 << (((Config >> 6) & 7) + 12)` (`0xbfc07594`); both lines 16 bytes (`16`, mask `15`), stored in a table from `0xa87c853c` (I size) and `0xa87c8544` (D size). Secondary line
defaults to 128 bytes (mask 127). `0xbfc07660` returns 0 (no secondary cache) when Config bit 17 is set; otherwise it loads one word from
`0x88000000 + size` for `size = 0x10000` doubling to `0x400000`, stores zero tags (cache ops `8`, `9`, `0xb` at `0x88000000`) and then issues
index-load-tag (op `7`, at `0x88000000 + size`) for each doubling, stopping at the first `size` whose TagLo reads back zero; that size is the
secondary cache size (64 KiB to 4 MiB). If none is found the secondary line values fall back to 16/15. The cache-op numbers are the `rt` field names of the public R4000
manual (op in bits 4:2, cache in bits 1:0). Reset also derives the secondary line size from Config for CPUCTRL0 (above).

## Memory descriptors (established)

Nodes are 20 bytes: `type`, `base page`, `page count`, magic `0x4b45565e` at `+0xc`, `next` at `+0x10`, head pointer at `0xa87410e0`.
`GetMemoryDescriptor` is `0xbfc0ac30` (null returns the head; any other pointer returns its `next` when the magic matches, else 0). The list is
built by `0xbfc081fc`: free memory (type 3) from physical `0x08002000`, `min(total bank size, 0x08000000)` bytes rounded to pages, minus two pages
(the minimum is taken by `0xbfc35f34`; the cap is 128 MiB, half of what the IP22 page records); free pages 0 to 1 (type 3 at base 0). `0xbfc0ac74` then
retypes page `0x1000` to type 1 (system parameter block) and page 0 to type 0 (exception block), through the retype routine `0xbfc0acb8`. Types are the
SGI numbering of the public NetBSD header (0 exception block, 1 SPB, 3 free memory). Memory above the first 128 MiB, and the second window, never
become descriptors in this routine. Unknown whether another path adds them.

## ARC system parameter block and call table (established)

`0xbfc285f8` skips everything when the ROM word at `0xbfc42e20` is 0 (it holds 1). It copies 136 bytes (34 slots) from `0xbfc53340` to
`0xa0001800` (the firmware vector, length `0x88`) and 40 bytes (10 slots) from `0xbfc533c8` to `0xa0001c00` (the private vector). The block at `0xa0001000`
(`0xbfc28644`): `+0` signature `0x53435241`; `+4` length `0x48`; `+8` version `1`; `+10` revision `10`; `+0xc` restart block 0; `+0x10` debug block 0;
`+0x14` general-exception vector `0xbfc06ab0`; `+0x18` UTLB-miss vector `0xbfc06b84`; `+0x1c` firmware vector length `0x88`; `+0x20` firmware vector
`0xa0001800`; `+0x24` private vector length `0x28`; `+0x28` private vector `0xa0001c00`; `+0x2c` adapter count 0.

The 34 firmware slots (numbers and names from the public ARC layout; only the routines for Load, Invoke, Execute and GetMemoryDescriptor were read, the rest are named by slot order): Load `0xbfc28714`,
Invoke `0xbfc28868`, Execute `0xbfc28ba4`; Halt, PowerDown, Restart, Reboot and EnterInteractiveMode are the stubs `0xbfc005c8`..`0xbfc005e8` (the first
four set `s0` to 1 to 4 and jump to `0xbfc0065c`; the fifth tests whether the caller is inside the ROM and the `0xfeeddead` marker is set); slot 8
(ReturnFromMain) is 0; GetPeer to GetComponent `0xbfc267e8`, `0xbfc267f4`, `0xbfc2681c`, `0xbfc26828`, `0xbfc2687c`, `0xbfc26b60`, `0xbfc2bf88`;
SaveConfiguration `0xbfc26c94`; GetSystemId `0xbfc0a6d4`; GetMemoryDescriptor `0xbfc0ac30`; slot 19 (Signal) 0; GetTime `0xbfc0a5fc`,
GetRelativeTime `0xbfc31d20`, GetDirectoryEntry `0xbfc0a530`, Open `0xbfc09a70`, Close `0xbfc0a384`, Read `0xbfc09ee0`, GetReadStatus `0xbfc0a6e0`,
Write `0xbfc0a1f8`, Seek `0xbfc0a464`, Mount `0xbfc0a7b4`, GetEnvironmentVariable `0xbfc0a88c`, SetEnvironmentVariable `0xbfc0a86c`,
GetFileInformation `0xbfc0a8ac`, SetFileInformation `0xbfc0a950`. There is no FlushAllCaches slot and no TestUnicodeCharacter or
GetDisplayStatus slot. The slot names beyond Load, Invoke, Execute and GetMemoryDescriptor are inferred from slot order and the opcodes the
routines build (`Open` is called by the console opener, `Read`/`Write` by the monitor). The vector is built into RAM, so a client sees RAM pointers.
Private vector (10 entries, names unknown): `0xbfc06428`, `0xbfc09910`, `0xbfc287f4`, `0xbfc28b80`, `0xbfc28c8c`, `0xbfc29e04`, `0xbfc29ea8`,
`0xbfc0e544`, `0xbfc31d08`, `0xbfc285f0` (returns 1).

## Environment and NVRAM (established unless marked)

**Store.** A 256-byte serial EEPROM on the HPC1 auxiliary byte at `0xbfb801bf` (pointer constant at `0xbfc53b00`), the register the NetBSD header names
`HPC1_AUX_REGS` (bit `0x1` console LED / PRE, `0x2` chip select, `0x4` clock, `0x8` data in to chip, `0x10` data out of the chip). It is read and
written as 16-bit words, high byte first (`0xbfc2acac`), with the 3-bit-opcode microwire commands (`0xc000` read, `0x9800` enable-write, `0xa000` write, with
the word number shifted by 5). The 128 words are cached in RAM at `0xa8745270` (valid flag `0xa8745370`). Bit 0 of the register is preserved around every access.

**Layout.** Byte 0 is a checksum and byte 1 is the revision, required to be `6` (`0xbfc2b0b8`..`c0`). The checksum (`0xbfc2a6d0`) starts at `0xa5`; word 0
contributes only its low byte (revision), every other word its high XOR low byte; after each word the accumulator is rotated left by one bit. The
check `0xbfc2b044` tries it twice before declaring the store invalid. A legacy layout (checksum in byte 49, 64 words, word 24 high byte only) is
recognised by `0xbfc2b4b4` and converted by `0xbfc2b530`, which copies old-offset variables (`netaddr`, `dbaud`, `rbaud`, `diskless`, `pagecolor`,
`nogfxkbd`, `passwd_key`, `volume`, `bootmode`, `console`) to the new offsets.

**Records** (44 bytes at `0xbfc45760`: name 28 bytes, default pointer `+0x20`, NVRAM byte offset `+0x24`, length `+0x28`; 25 records, terminated by a zero
length): `SystemPartition`@4/48, `OSLoadPartition`@0x88/48, `OSLoader`@0x34/18, `OSLoadFilename`@0x46/28, `OSLoadOptions`@0x62/12, `AutoLoad`@0xb8/1
(default `Yes`), `TimeZone`@0x80/8 (`PST8PDT`), `console`@2/2 (`g`), `diagmode`@0xb9/2, `diskless`@0x79/1 (`0`), `nogfxkbd`@0xbf/1, `keybd`@0xc0/5,
`lang`@0xc5/6, `scsiretries`@0xed/1, `scsihostid`@0xf1/1, `dbaud`@0x74/5 (`9600`), `rbaud`@0xf4/1, `pagecolor`@0x6e/6, `volume`@0xee/3 (`128`),
`sgilogo`@0xf2/1 (`y`), `nogui`@0xf3/1, `netaddr`@0xbb/4 (`192.0.2.1` default string, stored as 4 bytes), `eaddr`@0xfa/6, `passwd_key`@0xcb/17,
`netpasswd_key`@0xdc/17. The layout differs from the Indigo2 one on the same names (`AutoLoad` here at `0xb8`, there `0xb2`), so the IP22 page's table does not carry over.

The variable-setting wrapper and the RAM environment are the shape of the Indigo2 page's; the check against that page was not repeated here.

## Console (established)

The console opener (`0xbfc06100`..) reads `ConsoleIn` and `ConsoleOut`; each must open (mode 0, mode 1) and the first handle must be 0 and the second 1. On
failure it rebuilds both from the `console` variable (`0xbfc062d0`): when `console` starts with `d` both are `serial(0)`; otherwise `ConsoleOut=video()` and `ConsoleIn=keyboard()`
(strings at `0xbfc44d1c`, `0xbfc44d28`, `0xbfc44d40`). A failed keyboard open prints "Cannot connect to keyboard -- check the cable.", a second failure
falls back to `d` ("Cannot open any console!" if even that fails, `0xbfc062a0`). The serial speed variables are `dbaud` and `rbaud`.

## Configuration tree (established for the three records read)

Root `SGI-IP20` (template `0xbfc451d0`, 9-byte identifier), processor `MIPS-R4000` (template `0xbfc45228`) with `MIPS-R4000FPC` (`0xbfc45240`), cache
nodes from the template at `0xbfc4525c` (used three times, primary I, primary D and secondary; `0xbfc07cac`..`07e1c`). Graphics boards found by string:
GR2 family ("SGI-GR2", "-Elan", "-XS24"), LG1 ("SGI-LG1", "LG1MC"), and `GR1MODE`; Ethernet `ec0` (SEEQ), SCSI `WD33C93`, audio "HAL1". The
sibling order and the remaining types were not walked; unknown.

## Boot flow (established)

After the step sequence above, `0xbfc015c0` tests the result of `0xbfc02fa0` (diagnostics). If they failed it prints "Diagnostics failed. [Press any key to
continue.]" (`0xbfc42c64`), waits for a key and enters the monitor (`0xbfc01c50`). Otherwise it reads `diagmode`; a value starting with `M` runs the manufacturing
autoboot (`0xbfc016a4`, below), and anything else calls `0xbfc09960`: if `AutoLoad` starts with `y` or `Y` it prints "To perform system maintenance
instead, press <Esc>" and calls the loader `0xbfc38530(5, 0, ...)`; if that returns it prints "Unable to boot; press any key to continue:". Every
path ends in the EnterInteractiveMode stub `0xbfc005e8`. The loader builds its path from `SystemPartition`, `OSLoader`, `OSLoadPartition` and
`OSLoadFilename`; the string forms were not traced past the name table.

## Commands (established)

Command table at `0xbfc42e24`, three words per entry (name, handler, help text), 23 entries: `auto` `0xbfc388e0`, `boot` `0xbfc37080`, `.checksum` `0xbfc389a0`,
`.dump` `0xbfc0d0e0`, `exit` `0xbfc38a70`, `.fill` `0xbfc0dab0`, `.g` `0xbfc0dcd0`, `.go` `0xbfc38aa0`, `help` and `.?` `0xbfc390c4`, `init` `0xbfc00774`, `hinv`
`0xbfc39330`, `ls` `0xbfc39ec0`, `passwd` `0xbfc0def0`, `printenv` `0xbfc3a414`, `.p` `0xbfc0dde0`, `resetenv` `0xbfc097d8`, `resetpw` `0xbfc0e004`, `setenv`
`0xbfc3a1f0`, `single` `0xbfc3a500`, `unsetenv` `0xbfc3a38c`, `version` `0xbfc01e9c`. Names starting with `.` are the table's hidden commands (the help text for them is
`checksum:`, `dump:`, and so on). The manufacturing autoboot list is `ide.IP20`, `bootp()ide.IP20`, `sashIP20`, `bootp()sashIP20`, `unix.IP20`, `bootp()unix.IP20`
(strings at `0xbfc42cb0`..), then "Mfg auto boot failed." There is **no little-endian**, `e2endian` or byte-order command in the table.

## Device map the PROM touches

Only offsets whose use was read are listed.

| Address | Block | Offsets read or written here |
|---|---|---|
| `0xbfa00000` | MC | `+0x04` CPUCTRL0 (reset whole write; low nibble `2`; bit `0x400` pulsed `0xbfc03674`/`0xbfc0f5ec`; bit `0x200` set then spin at `0xbfc07ed4`; bit `0x04000000` and `0x10e0` at `0xbfc07950`), `+0x0c` CPUCTRL1, `+0x30` (little-endian view of the EEPROM register), `+0xc4`/`+0xcc` bank words, `+0xd4`, `+0xdc`, `+0xec`, `+0xfc`, `+0x1004` refresh counter, `+0x2004`..`+0x204c` DMA |
| `0xbfb80000` | HPC1 | `+0xc0` endian register (`+0xc3` byte), `+0x1bc`/`+0x1bf` auxiliary EEPROM and LED byte, `+0xe00` (NetBSD's battery-backed RAM block, code at `0xbfc2c750`..); many more offsets from `+0x00` to `+0x4ff0` are used (SCSI, Ethernet, serial, audio) and were not decoded |
| `0xbfbd0000` | board id | word read at `0xbfc07c3c`; bits `0x7000` inverted and shifted down (`0xbfc07c44`), a 3-bit board field (meaning unknown) |

Graphics, audio and serial accesses (`0xbfbe0000`, `0xbfb847e8`, `0xbfb84fe8`, `0xbfb80d03`..`0xbfb80d37`) were seen but not read. Unknown.

## Unknowns and routes that would settle them

See [questions/ip20-prom-software.md](../../questions/ip20-prom-software.md).
