# Byte order in shipped SGI MIPS firmware and tools: what exists and what does not

Does any shipped SGI PROM or IRIX tool support a little-endian MIPS machine, and what can change a machine's byte order? This page
reads 170 PROM images and the IRIX 6.5 and 6.5.30 boot, diagnostic and flash binaries for that question only. Windows NT for MIPS
(little-endian kernel, little-endian ARC firmware) is the reason to ask. Labels follow [AGENTS.md](../../AGENTS.md): established is a
code path read as a listing, inferred is a reasoned reading, unknown is not settled.

## Answer

- **No PROM image we hold is built little-endian.** Every one of the 170 (all board families below) has its instruction words
  encoded big-endian: the count of `jr ra` words (`0x03e00008`) read big-endian is 59 or more in every image (up to several
  thousand) and read little-endian is zero in all of them. The one apparent exception, the Indigo 4.0.1 Rev D image, reads zero in
  both directions because it is a dump with each 16-bit pair of bytes swapped (the reset vector reads `f0 0b 80 00` where the other IP12
  images read `0b f0 00 80`); swapped back it has 753 big-endian `jr ra` words, the same count as the other 256 KiB IP12 image.
  It is not a little-endian build. Established. (For the IP27, IO6 and IP35 images the count is of the unpacked payload.)
- **Three families carry a reset-time test of `Config.BE`, and they do three different things.** The Crimson PROM (IP17) continues
  its start-up on a little-endian CPU, after storing one byte to a board register; the Indigo (IP20), Indigo2 (IP22) and Indy (IP24) PROMs rewrite the CPU-mode EEPROM back to
  big-endian and restart the CPU. The Indigo2 IMPACT, POWER Indigo2, Octane, O2 and every Origin and Fuel PROM never test it.
  Established for each (listings below).
- **The IP17 PROM is the only shipped firmware that is aware of running little-endian.** It tests the CPU's byte order 137 times,
  indexes two register-address tables by it, ships `endian` and `e2endian [big|little]` monitor commands, and refuses to load an
  executable of the wrong byte order. Established.
- **The only code that changes a byte-order bit is the IP20/IP22/IP24 flip routine and the IP17 `e2endian` command.** On every
  other MIPS board no shipped software writes the bit. On the Origin 200/2000 and Fuel/Origin 300/3000 boards the PROMs carry prompts for the CPU mode word and the IRIX `flash` tool
  prompts for mode-word fields; none of those prompts names an endian field, and where each stores its answer was not traced.
  Detail and grades below.
- **Nothing in any held image is aimed at Windows NT, except the Indigo PROM 4.0.5D's default boot variables** (below).

## Images read

| Family | Images | Method |
|---|---|---|
| IP5, IP6, IP12 | 1, 1, 3 (4.0 OPT, 4D1-3.1 Rev C, 4.0.1 Rev C twice and Rev D) | raw flash images, base `0xbfc00000` |
| IP17 | 1 (4.0.3) | raw |
| IP20 | 1 (4.0.5D Rev A) | raw |
| IP22, IP24 | 2, 2 (5.1 Rev B, 5.3 Rev E; 5.0 Rev B6, 5.3 Rev B10) | raw |
| IP26, IP28 | 2, 2 (6.0.1 Rev A; 6.2 Rev A) | raw |
| IP30 | 21 (2.15 to 4.17) | raw |
| IP32 | 18 (2.3 to 4.18) | raw |
| IP27, IO6 | 36 each (4.9/5.3 to 6.156) | promgen64 container unpacked, payload read |
| IP35 | 31 (6.37-test to 6.211) | container unpacked, payload read |
| IO4 | 13 | raw |

The IO4 images are 32-bit promgen containers; they were scanned raw and carry the banner `IO4 PROM Monitor %s (BE)`. No IP19, IP21
or IP25 CPU PROM image is held; the IRIX `symmon` boot files for IP19, IP21 and IP25 are the nearest thing (below). Images listed
as held in [prom-images.md](../../references/prom-images.md) but not in the published catalogue (an Indy 5.3 dump and an Octane 4.9
image) were not read here.

Method: every image was scanned for the encoding direction, for `mfc0`/`mtc0` of Config (CP0 register 16) and the instructions that
follow, for `xori ...,0x8400`, and for strings; the listings quoted below were produced with the MIPS `objdump` from the toolchain
container and read by hand.

## IP17 (Crimson), PROM 4.0.3: the little-endian path

Reset runs at `0xbfc003c0`: Status, Cause, PageMask and the watch registers are cleared, Config is written with 3 (K0 only; bit 15 is
0 in the value written), read back, and bit 15 (`andi v0,v0,0x8000` at `0xbfc003ec`) is tested. When the bit is **clear**
(little-endian), the PROM stores the byte `1` at `0xbd800007` (`0xbfc003f8` to `0xbfc00408`) and carries on with the normal start-up
at `0xbfc00410`. It does not flip anything. Established. What `0xbd800007` is is unknown: the PROM's two register tables list a
CPU-board register at `0xbd800000` in the big-endian view and at `0xbd800004` in the little-endian view (below), so the offset has the
lane swizzle, but no other code names it. The IP17 PROM reads the word at `0xbd800000` once, at `0xbfc0f968`.

The little-endian awareness is pervasive and read, not guessed:

- `0xbfc11ac8` returns 1 when Config bit 15 is clear (`mfc0; srl 15; andi 1; xori 1`) and is called from 137 sites. Established.
- Two parallel tables of CPU-board and I/O register addresses sit at `0xbfc39960` (big-endian view) and `0xbfc39988`
  (little-endian view), 11 pointers each; the little-endian pointers are the big-endian ones with the byte lane swizzled
  (`+3` for byte registers, `+4` for the `0xbd8...` and `0xbd0...` entries, `0xbf200001` becomes `0xbf200002`). Code picks the table
  with `0xbfc11ac8` (for example `0xbfc0c6d0` to `0xbfc0c6fc`). Established for the selection; the meaning of each register is not read.
- The monitor command table (`0xbfc38560` on) has `endian` (handler `0xbfc0c7ac`, prints which order the CPU is in from the strings at
  `0xbfc39d60` and `0xbfc39d68`) and `e2endian` (handler `0xbfc0c7f4`, help text "e2 endian bit: e2endian [big|little]"). With no
  argument `e2endian` reads bit 2 of a byte; with `b` it sets that bit (`ori 0x4`) and with `l` it clears it (`0xbfc0c714`,
  `0xbfc0c760` on). The byte is the entry at offset `0x1c` of the table the byte-order test selects: `0xbfe00000` in the big-endian
  view and `0xbfe00003` in the little-endian view. This is a read-modify-write setter and its only callers are `0xbfc0c870` and
  `0xbfc0c880`, both in the command handler. Established. That the byte is the CPU-board mode EEPROM's endian bit is inferred from the
  command name and the string "e2 endian bit".
- The program loader rejects the wrong order: "not little endian byte order" at `0xbfc38454` and "not big endian byte order" at
  `0xbfc38478`, and a warning "IO3B needed for little endian IO" at `0xbfc39a8c`. Strings observed; their call sites were not read.

So the Crimson PROM is endian-neutral at the level of its own code (it addresses registers through the two tables) and can be
told to restart the other way with `e2endian`. Nothing was read that tells whether the IP17 PROM would complete a boot little-endian;
that is unknown.

## IP20, IP22 and IP24: test, flip, restart

All six images (Indigo 4.0.5D Rev A, Indigo2 5.1 Rev B and 5.3 Rev E, Indy 5.0 Rev B6 and 5.3 Rev B10) start the same way after the
reset vector: write Config with 2 (3 on IP20), read it back, `andi v0,v0,0x8000`, and call the flip routine only when the
bit is **clear**. Established, listings read in all six.

| Image | Config test (`andi`) | Flip routine | `xori ...,0x8400` | EEPROM read, write | Restart store (`sw` of `0x10000` to `0xbfa00000`) | EEPROM register |
|---|---|---|---|---|---|---|
| IP20 4.0.5D Rev A | `0xbfc003e8` | `0xbfc01320` | `0xbfc0132c` | `0xbfc01414`, `0xbfc01490` | `0xbfc01340` | MC `+0x30` |
| IP22 5.1 Rev B | `0xbfc003e8` | `0xbfc019d0` | `0xbfc019dc` | `0xbfc01ac4`, `0xbfc01b40` | `0xbfc019f0` | MC `+0x30` |
| IP22 5.3 Rev E | `0xbfc003e8` | `0xbfc01f00` | `0xbfc01f0c` | `0xbfc01ff4`, `0xbfc02070` | `0xbfc01f20` | MC `+0x34` |
| IP24 5.0 Rev B6 | `0xbfc003e8` | `0xbfc01d60` | `0xbfc01d6c` | `0xbfc01e54`, `0xbfc01ed0` | `0xbfc01d80` | MC `+0x34` |
| IP24 5.3 Rev B10 | `0xbfc003e8` | `0xbfc0a810` | `0xbfc0a81c` | `0xbfc0a904`, `0xbfc0a9d0` | `0xbfc0a830` | MC `+0x34` |

The routine, identical in all five apart from the register offset and the addresses: read EEPROM word 0 (opcode `0xc000`), XOR the
result with `0x8400` (bits 15 and 10), write the word back (enable-write `0x9800`, write `0xa000`, then disable, with a ready poll),
store `0x10000` at `0xbfa00000`, and return to the caller. The PROM bit-bangs the part through the MC register: chip select, shift
out 11 bits, shift in 16. The store of `0x10000` is the restart request of the CPU-mode register at MC offset 0; because it is a
restart the "return" is normally never reached. Established (the sequence), inferred (that bit 15 of the word is the byte-order bit
that reaches Config.BE after the restart and that the store of `0x10000` is the CPU-restart-and-reload request, from the string and
the structure; see [platforms/ip22/prom-software.md](../../platforms/ip22/prom-software.md) for the same 5.3 Rev E reading). Bit 10
of the mask is unknown here too.

Callers, searched for `jal` and `j` to each routine across the whole image: the flip routine has exactly one caller, the reset-path
`jal` at `0xbfc003f4` (all five). The word write routine has exactly one caller, the flip routine. The word read routine has one
other caller in IP22 5.3 (`0xbfc0ea14`: reads word 17, shifts it left by 12 and stores it as a configuration value) and one other in
IP24 5.0 (`0xbfc0dd24`) and IP24 5.3 (`0xbfc0e40c`). No other site in any of the five images combines the base `0xbfa0` with
`0x30`/`0x34` or stores `0x10000` to MC offset 0. So the shipped PROMs hold **one** writer of the EEPROM's byte-order bit and one
restart request, both reached only when Config.BE is clear. Established for these five (the 5.1 Rev B listing, 5.0 Rev B6 and 4.0.5D
were read at the routine and the callers; their rest-of-image scans are the pattern search above).

What a little-endian CPU does with these PROMs: the reset-path code up to the test is word-oriented and runs the same either way (the
PROM's own instruction words are encoded big-endian); the flip routine uses word loads and stores only. So the stock behaviour on a
machine that comes up little-endian is a restart into big-endian. A third test of that is not available (nobody ran it); the code
supports the reading. Inferred.

### The "Big Endian" write to the MC mode register

IP22 5.1 and 5.3, IP24 5.0 and 5.3, IP26 and IP28 contain the same diagnostic helper, with the format string "basic_DMA_setup: set
CPUCTRL0 = %x (Big Endian)". It is a read-modify-write of the MC register at `0xbfa00004`: set bit 1 ("refresh 4 lines"), set or
clear bit 14 ("Snoop"; the bit names are from the format strings, so inferred), then **clear bit 18** and print the result with "(Big Endian)". Addresses: IP22 5.1 `0xbfc096a4` (the
`and`-mask build), IP22 5.3 `0xbfc0a56c` to `0xbfc0a63c`, IP24 5.0 `0xbfc09bb4`, IP24 5.3 `0xbfc09c74`, IP26 `0xbfc0799c`, IP28
`0xbfc094a0`. The same function is linked into the IRIX 6.5-base `ide.IP22` at `0xa8486b80` to `0xa8486ca0`. Bit 18 is the MC's
CPU-little-endian bit in the specification the other pages cite; here the PROM clears it and labels the result big-endian, so any
path through this helper forces the MC to big-endian regardless of the CPU. Established (code); that bit 18 is the endian bit is the
specification's statement and the string agrees (inferred as to the bit number from the string).

### The Indigo's NT-flavoured boot defaults

The Indigo PROM 4.0.5D Rev A contains a table of pointers at `0xbfc45c40` to `0xbfc45c4c` to four default values: two copies of
`scsi()disk(1)rdisk()partition(1)`, `osloader.exe` and `\nt\system\ntoskrnl.exe`. They are in the same order as the four variable
descriptors `SystemPartition`, `OSLoadPartition`, `OSLoader`, `OSLoadFilename` (descriptors at `0xbfc45760`, `0xbfc4578c`,
`0xbfc457b8`, `0xbfc457e4`). The pairing is by order, so inferred; the strings are observed. The table does not appear in any other
PROM image (no other image contains `ntoskrnl`, `osloader.exe`, `winnt` or `windows nt`). The same PROM builds the ARC system
parameter block (next section) and prints "Setting endianness." as one of its start-up progress lines, which is the step that holds
the Config.BE test.

## ARC parameter block and vectors in the MIPS PROMs

Searching for the constant `0x53435241` (the ARC signature, `lui 0x5343; ori 0x5241`, or as a data word) finds a builder in: IP20
4.0.5D (`0xbfc28644`), IP26 (`0xbfc18894`), IP28 (`0xbfc165e8`), all 18 IP32 images, IO6, and the IP27 and IP35 payloads (as data
words). It is not found in the IP22, IP24 or IP30 images by this pattern, which says nothing about their blocks (built another
way). Read in full:

- IP20 4.0.5D, `0xbfc28644` on: stores at `0xa0001000` signature, length `0x48`, version `1` (halfword at `+8`), revision `10`
  (halfword at `+0xa`), restart block 0, debug block 0, general-exception vector `0xbfc06ab0`, TLB-miss vector `0xbfc06b84`, then
  the firmware-vector length `0x88`. Established.
- IP32 4.18, `0xbfc207d8` on: the same `0x48`, version 1, revision 10, restart and debug 0 and `+0x2c` (adapter count) 0; it
  then copies a `0x8c`-byte vector to `0xa0001800` and a `0x34`-byte table to `0xa0001c00`. Established.

So the MIPS PROMs and the Visual Workstation PROM use the same block layout (below), differing in vector length and in the
exception-vector fields. All of these are big-endian words on the MIPS side; a little-endian MIPS client would read the byte
swapped. No MIPS PROM holds a byte-swapped or dual-endian copy of any of it. Established (negative result: no swapped copy of the
signature word `0x41524353` or `0x52414353` found by data search in the scanned images; not exhaustive for other layouts).

## IP26 and IP28: no test, constant Config writes

IP26 (POWER Indigo2, R8000) and IP28 (Indigo2 IMPACT, R10000) never read bit 15 of Config in the reset path. IP28 writes Config
with the constant `2` at `0xbfc003cc` and `3` at `0xbfc009f4` (bit 15 is 0 in both), reads Config at `0xbfc00478` (masks bit 13) and at `0xbfc00ad0` (masks bits 18:16) for sizing, and has two read-modify-write helpers that replace only bits 2:0 (`0xbfc1e77c`
sets 3, `0xbfc1e798` sets 2, both masking with `-8`) and a bare `mtc0 a0,$16` wrapper at `0xbfc21e50` whose callers were not traced.
There is no `xori 0x8400` and no access to MC offset `0x30` or `0x34` in either image. Established for the writes. Where the R10000
gets its mode word on the IP28 is not in the PROM (unknown). IP26 contains no `mtc0` of Config at all (seven reads of register 16
only, in cache-size code).

## IP30 and IP32 (Octane, O2): no test

- IP30 (21 images, 2.15 to 4.17): the reset path writes Config with `2` at `0xbfc0072c` (4.17) and never reads bit 15; there is no
  restart or mode write. The strings `LITTLE`, `BIG` and `ENDIAN` in the PROM (file offset `0x97e68` in 4.17) are the field names the
  PROM uses when it decodes the Bridge control register (`IO_SWP`, `MEM_SWP` and neighbours), not CPU byte order. Established.
- IP32 (18 images, 2.3 to 4.18): the start-up replaces Config bits 2:0 with 3 (`0xbfc0073c` to `0xbfc00750` in 4.18, a
  read-modify-write that keeps bit 15) and no code tests bit 15. The banner says `PROM Monitor (BE)`. Established.

No writer of the O2 or Octane CPU mode word, and no cold-reset request that could reload a different one, was found in either family's
PROM; those two reset paths were not searched exhaustively (CRIME cold-reset and the HEART mode-register reset bits not located in
the code). Unknown whether any shipped software exists that issues them.

## IP27, IO6 and IP35: the flash word is compared, never tested for endian

The Origin 200/2000 node PROM (IP27, 36 images) and the Fuel/Origin 300/3000 PROM (IP35, 31 images) read a CPU mode word from flash,
write it to Config, read Config back and compare:

- IP27 6.156 payload: `lw` of the word at `0x9000000010000064` (`0xbfc00c80`), `mtc0` to Config (`0xbfc00c84`), `mfc0` back
  (`0xbfc00c8c`), compare bits 15:0 (`andi 0xffff` both sides, `bne` at `0xbfc00c94`), then compare bits 24:16 (`srl 16`,
  `andi 0x1ff`, `beq` at `0xbfc00ccc`). A mismatch stores the progress code `0xb4` (`0xbfc00d04`, again at `0xbfc00d80`) and calls the routine at `0xbfc38fe0`, which
  was not read. Established for the compare; unknown for what the routine does.
- IP35 6.210 payload: the same sequence with the flash word at `0x9000000018000064` (`0xbfc006a8`), `mtc0` at `0xbfc006ac`,
  compare at `0xbfc006bc` and `0xbfc006f4`, failure code `0xb4` stored at `0xbfc00730` and `0xbfc00770`, then a call to `0xbfc50c34` (not read). The word is read at physical `0x18000064`, not
  `0x10000064`. Established. The IP27 4.9 and 5.x PROMs do not write Config at all at reset (their Config reads are the cache-size
  helpers at `0xbfc02ca0` to `0xbfc02ce4`).

The compare includes bit 15, so (if bit 15 of Config cannot be written, inferred) a flash word with bit 15 clear would fail the
compare on a CPU that came up big-endian; the code does not test or select byte order itself. Whether the silicon makes bit 15 writable is not settled by this code (the write-and-compare cannot
tell); unknown.

**Writers of that flash word.** Neither the PROM nor IRIX's `flash` was decoded all the way to the mode-word store, so what follows
is what the images say they do:

- 16 IP27 PROM images (6.57, 6.60, 6.62, 6.64, 6.69, 6.75, 6.80, 6.94 and 6.103 to 6.156) carry an interactive menu that asks for the secondary cache size, CPU and hub frequency,
  machine type, CPU type, then either individual fields (DDR SRAM, tandem mode bit, SysClk divisor, SCClk divisor, SCClk tap,
  outstanding requests) or the prompt "Enter raw MIPS mode bits" (format `[  0x%x] : `, string at payload `0x69538` in 6.156). The
  raw prompt can supply a word with any bit 15 value. No code reference to these strings was found by the usual `lui`/`ori`/pointer
  searches, so where the answer is stored was not traced. Observed strings; code unread, so unknown.
- 18 IP35 PROM images (6.131 to 6.211) list the command `setmodebits NODE [...]` ("Prgm modebits with values"), the prompt "Enter raw
  mode bits", and name the stored fields `HubModeBits` and `CpuCfg0Reg` to `CpuCfg3Reg`; there is also `verify_modebits`. The
  command table entry is at payload `0x13f9c0`; its handler was not located (the table entry carries a small id word, not a
  pointer). Observed strings; unknown for the code.
- 15 IO6 PROMs print the Config word with named fields (the line `<15>    MemEnd` is the bit 15 entry), 28 carry the message "CPU and PROM modebits
  mismatch."; the six IP27 images 4.9 to 5.19 carry a symbol-name table with
  `get_endian` (its code was not located). Observed strings.
- IRIX `/usr/sbin/flash` (6.5.30: identical bytes to `/usr/sbin/flashio`; the 6.5-base copy carries the same "Mode bit setting definitions" text; N32 big-endian) knows four board families
  (`flashio_everest`, `flashio_racer`, `flashio_sn0`, `flashio_sn1`). With `-f` it offers an overlay of configuration, prompting for
  CPU type (R10K/R12K or R14K), L2 HSTL mode, SysAD HSTL mode, secondary cache size code, tandem mode, the SysClk-to-cache-clock
  alignment, CPU frequency, cache size, configuration type and machine type, and names the stored values `HubModeBits`, `CpuCfg0Reg` to
  `CpuCfg3Reg`, `CpuSpeed` and `HubSpeed`. Its text says "Mode bit setting definitions may be found in the MIPS R10000 manual".
  None of the prompts is for byte order. `get_config_fields` (`0x100126e0` in the 6.5.30 file) only parses numeric fields from the
  image's own header text (two of them multiplied by one million) into a structure; it does not touch bit 15. The routine that
  composes `HubModeBits` was not read. Established for the prompts and for `get_config_fields`; unknown for the composition.
- `/sbin/nvram` and `lsflash` contain no byte-order, EEPROM or mode-bit strings (strings scan).

## IRIX boot and diagnostic binaries

- **`ide.IP22` (6.5-base).** Contains a complete copy of the flip routine of the IP22 5.3 family at `0xa8524590` (`xori a1,v0,0x8400`
  at `0xa852459c`; read word `0xa8524684`; write word `0xa8524750`; restart store `0xa85245a8` to `0xa85245b0`; the same MC `+0x34`
  register). The routine has **no caller** in the image: no `jal`, no pointer in the data section, and no `lui`/`ori` pair forms its
  address. The read routine has one caller at `0xa8503520`. Established for the absence of direct references; unknown whether a command
  reaches it some other way. The image also holds the "eeprom pin signals" test (menu strings at `0xa8560a8c`, `0xa8588b20`) and the
  "Big Endian" CPUCTRL0 helper above.
- **Kernel objects and `symmon`.** IP20, IP22 and IP28 `kernel.o` carry the symbol `set_endianness`; IP22 also `bset_endianness`
  (strings only; the objects have no symbol table readable by the toolchain here, so the functions were not decoded and what they set
  is unknown; the name and the neighbouring `_hpc3_write2` suggest the HPC3 DMA endian bits, inferred). No `xori 0x8400` appears in
  any IP20, IP22, IP26, IP28, IP30, IP32 or IP35 kernel object, `os.a`, `sash`, `symmon` or `ide` (the only hits are `ide.IP22`
  above and noise in data sections). So no IRIX kernel or boot binary we hold writes the CPU-mode EEPROM except through the
  unreferenced `ide.IP22` copy. Established for the scanned set (pattern search, not a full decode).
- **Loaders.** `sash`, `sash64`, `ide*`, `ideloader`, `symmon.IP27/IP30/IP35` and the IO6, IP26, IP27, IP28, IP30, IP32 and IP35 PROMs
  carry "WARNING: file loaded but not executed: opposite endian". In `ide.IP22` the print site is `0xa84fb270`, reached after a
  successful load when a global flag at `0xa8668a30` is non-zero; the endian comparison and the flag's meaning were not decoded.
  `sash` and `ideloader` also contain `swapendian`. So the shipped loaders know the difference between executables of the two orders
  and refuse the opposite one. Observed strings; the check itself unread.
- IP5, IP6 and IP12 PROMs say "inappropriate byte order" on loading (IP6 and IP12); they have no Config register (R2000/R3000) and no
  byte-order test. Observed.

## Visual Workstation PROM 1.1005: a little-endian ARC firmware to copy the shape of

The SGI Visual Workstation 320 and 540 firmware is SGI's own ARC firmware for x86 and Windows NT (loader `arcldr.exe`); it is
little-endian by nature of the machine. These facts are from the pages [boot-path.md](../visws/boot-path.md) and
[firmware.md](../visws/firmware.md) (the 1.1005 image; the older images were not re-read for the byte-level tables) and are
established there unless noted.

- **Parameter block at physical `0x1000`.** The firmware writes it early (the routine at `1.1005@0x1134635`): signature `ARCS`
  (bytes in order, which is `0x53435241` as a little-endian word, the same integer the MIPS PROMs above store), length `0x48`,
  version 1 (word at `0x1008`), revision 10 (word at `0x100a`), restart block at `0x100c` (zero at first, later the address of a
  `0x228`-byte `RSTB` block), debug block `0x1010` zero, `0x1014` and `0x1018` (exception and TLB-miss vectors) not written, the
  firmware vector length `0x8c` at `0x101c` and pointer `0x1200` at `0x1020`, the private vector length `0x3c` at `0x1024` and
  pointer `0x1300` at `0x1028`, adapter count `0` at `0x102c`.
- **Firmware vector, 35 entries at `0x1200`.** `0x8c` bytes copied from a static table; entries 0 to 34 in the standard ARC order
  (Load, Invoke, Execute, Halt, PowerDown, Restart, Reboot, EnterInteractiveMode, reserved, GetPeer, GetChild, GetParent,
  GetConfigurationData, AddChild, DeleteComponent, GetComponent, SaveConfiguration, GetSystemId, GetMemoryDescriptor, reserved,
  GetTime, GetRelativeTime, GetDirectoryEntry, Open, Close, Read, GetReadStatus, Write, Seek, Mount, GetEnvironmentVariable,
  SetEnvironmentVariable, GetFileInformation, SetFileInformation, FlushAllCaches). Entries are stdcall thunks, all returning in
  `EAX`. Slots 8 and 19 are not callable (8 points at data, 19 is zero); there are no slots 35 and 36 (test-Unicode-character and
  display status), and Windows 2000's setup loader guards its display-status call on the vector length. Halt, as shipped, jumps through
  its own vector slot, so it never returns. SaveConfiguration is a no-op returning success. Open, Read, Write and Seek reach a
  20-slot file table with 64-bit positions and FAT, NTFS (read), ISO 9660 and TFTP behind them.
- **Private vector, 15 entries at `0x1300`.** `0x3c` bytes; entry 8 is zero. The last two non-null entries are the PCI configuration
  read and write helpers the firmware's drivers use (`devid, register, value`). The NT 4 and Windows 2000 loaders never call it.
- **Tree.** Nodes of `0x38` bytes: the `0x24`-byte ARC component, then parent, peer, child, one word and a configuration-data
  pointer. Every component the firmware adds is version 1, revision 10; configuration data is a partial resource list (version 0,
  revision 0, device-specific descriptors). The root is class system, type ArcSystem, identifier `SGI-nnn_ARCx86_mp` with nnn 320,
  540, 330 or 530 from the board type. Under the system node the adapter `SGI REV INFO` carries a 256-byte text block (motherboard
  fab and revision, bus speed, Cobalt and I/O generation, bridge, serial I/O and display-engine words) and has children `SYS TYPE`,
  `BOARD REV`, `COBALT`, `COBALT I/O`, `DISPLAY ENGINE` and `ARC PROM` (the last carries flash bytes that include the version
  digits setup compares). The HAL refuses to run without this tree and reads it through these node names.
- **Memory descriptors.** `0x14`-byte blocks (type, base page, page count, magic `0x4b45565e` at `+0x0c`, next at `+0x10`) sorted by
  base page; pages are 4 KiB; types 0 exception block, 1 system block, 2 free, 3 bad, 4 loaded program, 5 firmware temporary, 6
  firmware permanent, plus `0x14` (the firmware's page tables at `0xd00000`) and `0x16` (graphics memory, 4 MiB aligned). `GetMemoryDescriptor(NULL)` returns the head; any other pointer must carry the magic.
  RAM becomes one free descriptor up to 32 MiB and firmware-temporary descriptors above; a fixed list covers low memory.
- **Hand-off.** The firmware builds the boot entry from the ARC variables (`SystemPartition`, `OSLoader`, `OSLoadPartition`,
  `OSLoadFilename`, `OSLoadOptions`), loads a 32-bit PE/COFF image (machine `0x14c`) into free memory, builds name=value argument and
  environment strings, polls its devices once, runs `clts` and `fninit`, sets the stack to `0x61ff0` and calls the entry as
  `(argc, argv, envp)` in flat 32-bit protected mode with its own descriptor tables and page tables live (CR3 `0xd00000`). Nothing
  is quiesced because the firmware never enables interrupts. The loader reads the block fields at `0x100c` to `0x1028` once and
  calls 13 vector slots (GetPeer, GetChild, GetConfigurationData, GetMemoryDescriptor, GetTime, Open, Close, Read, Write, Seek,
  GetEnvironmentVariable, and Restart in setup). Nothing in the firmware is specific to NT or Linux.

What this model shows for a MIPS little-endian firmware: the ARC data structures are plain 32-bit little-endian words with no
byte-order-specific fields, so a little-endian MIPS firmware would build the same block at the same offsets and hand the same
signature integer `0x53435241` to the loader; the block layout, the 35-slot vector, the version-1 revision-10 component stamps and the
descriptor shape are the same as the big-endian MIPS PROMs above (IP20, IP32 builders). Inferred (from the two PROMs' identical
fields; no little-endian MIPS ARC firmware is held).

## Open

- What the IP17 PROM's byte written to `0xbd800007` does, and whether the PROM can finish a boot little-endian: needs the IP17
  register map for the CPU board and a run; no image or capture answers it.
- Which command in `ide.IP22` could reach the flip routine, and what `set_endianness` and `bset_endianness` set in the IP20, IP22
  and IP28 kernels: decode the kernel objects.
- Where the IP27 raw-mode-bits prompt and the IP35 `setmodebits` command store the word, and what their handlers do with bit 15.
- Whether any shipped software writes the O2 or Octane CPU mode word or the CRIME or HEART cold-reset bits: not found in the PROMs;
  the IRIX kernels and the IP30/IP32 diagnostics were not searched for them.
