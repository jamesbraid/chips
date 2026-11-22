# Crimson (IP17) PROM 4.0.3: what its own software does

This page records what the shipped Crimson PROM `SGI Version 4.0.3 Rev  IP17,  Apr 30, 1992` does: part `070-081x-005` (the last digit
of the label is unreadable), 524288 bytes, sha256 `46217a1c9a73f3e5eaec7eb955945ba4f5634c329e50063a7a08ddfa77d4ba33`. The image is
listed in [prom-images.md](../../references/prom-images.md) and was fetched from the public PROM catalogue; the digest was checked
after the download. It is read from the image alone, as MIPS code loaded at virtual `0xbfc00000` (image offset = address minus
`0xbfc00000`). Addresses below are image addresses in that window. The earlier byte-order survey of this image is
[byte-order.md](../../software/firmware/byte-order.md); this page re-checks it and goes further. Where the two differ, this page is
the newer reading and the survey carries the corrections.

Grades: **established** (read in full in the disassembly, or executed), **inferred** (reasoned from a partial read, a name or a
string), **unknown**. Disassembly is from the MIPS `objdump` in the toolchain container; the decompiler was not needed. Register
fields of the R4000 Config and Status registers follow the R4000 manual's layout and were not re-read for this page. Hardware
meanings are given only where the code itself shows a use; strings name things but name no register layout.

Two facts frame everything below. This PROM predates ARC: there is no `ARCS` signature, no system parameter block and no firmware
vector (the signature is absent as a string, as a data word and as an immediate). It is the older SGI monitor: a table of jump slots at
the reset vector, a command monitor, an environment kept in non-volatile RAM, and boot paths named `dksc(0,1,8)sash`.
And its code is built to run in either byte order, which is why it matters for Windows NT on MIPS.

## Image layout (established)

The first 0x3c0 bytes are slots of two words (`j target; nop`) in the usual MIPS layout. Slot 0 (`0xbfc00000`) jumps to the reset code
at `0xbfc003c0`. Named targets: `0x08` to `0xbfc00714`, `0x10` to `0xbfc00680`, `0x18` to `0xbfc00620` (the `init` command's
handler), `0x20` to `0xbfc005d0`, `0x28` to `0xbfc0064c`, `0x80` to `0xbfc09688` (the formatted-print routine), `0x110` to
`0xbfc032ac`, `0x200` to `0xbfc00800`, `0x300` to `0xbfc008a0`, `0x380` to `0xbfc00850`. Every other slot jumps to `0xbfc008f0`, which
prints "ERROR: call to unimplemented prom routine". Code and read-only data are interleaved module by module (the Ethernet, network
and disk drivers each carry their own strings); the monitor's tables, the register tables and the environment records sit together
from about `0xbfc37bb0` to `0xbfc46290`. At least some initialised globals are read straight from ROM (a network checksum switch at
`0xbfc46190`, see Hazards). The roles of the slots other than slot 0x80 were not traced.

## Reset path and the Config.BE test (established)

`0xbfc003c0` writes Status with `0x00410000`, clears Cause, PageMask, WatchLo and WatchHi, and writes the whole Config register with `3`
(`0xbfc003d8`, `0xbfc003dc`). It reads Config back (`0xbfc003e4`), masks bit 15 (`andi v0,v0,0x8000` at `0xbfc003ec`) and branches
to `0xbfc00410` when the bit is **set**. When the bit is **clear** the next four instructions run first:

- `lui v0,0xbd80; addiu v0,v0,7` builds `0xbd800007` (`0xbfc003f8`, `0xbfc003fc`);
- `li v1,1; sb v1,0(v0)` stores the byte `1` there (`0xbfc00404`, `0xbfc00408`).

Nothing else differs on the reset path. The write of Config relies on the BE bit not being writable (a CPU property per the R4000
manual, not re-read here): the PROM tests what the hardware strap gave, and the value it wrote is the same in either mode.

After the branch both modes continue identically (established as call order):

1. `0xbfc00410` onward: LED byte written twice (values 0 then 1) through `0xbfc00a4c`, which stores the one's complement of its
   argument to the byte at table address `0xbf200001` (little-endian view `0xbf200002`). An on-board self test of the console UART at
   `0xbfc04390` runs next (details under Console). A failure blinks the LED forever (`0xbfc00a84`).
2. A line break, then the banner "SGI Version 4.0.3 Rev  IP17,  Apr 30, 1992" (the pointer is at `0xbfc46280`; `0xbfc00434`), then,
   **only when Config bit 15 is clear**, the string `, EL` (`0xbfc37c43`; code at `0xbfc00444` to `0xbfc00460`), then two line breaks.
3. `0xbfc00498`: a word store of `0x01010000` to the register-table entry at `0xbfc399b0` (big-endian view `0xb7f40000`) or
   `0xbfc399b4` (little-endian view `0xb7f40004`), selected by the same bit. Those are the same four byte registers
   (`0xb7f40000` to `0xb7f40003`); the meaning is unknown (see Device map).
4. LED 2; the data-cache size and line size are read from Config (`0xbfc0c940`, `0xbfc0ca44`) and passed to a cache set-up routine
   (`0xbfc0ce68`).
5. "Memory address pattern test from A0000000 to A0003000", then the same for `A0500000` to `A05FFFFC` (`0xbfc004d4` to `0xbfc00528`
   and `0xbfc00538` to `0xbfc00580`); a failure goes to `0xbfc04640` and `0xbfc009d4`. The PROM therefore needs RAM at physical `0` to
   `0x3000` and at `0x500000` to `0x5fffff` before it will run at all.
6. LED 0; words `0xa0000000` to `0xa0001000` are cleared; `0xbfc00744`; then a jump to the main routine `0xbfc03b90`.

## Little-endian operation

### Does a little-endian boot complete? (answer)

**Established**: nothing in the PROM stops, restarts or flips the byte order when Config bit 15 is clear. The IP20, IP22 and IP24
PROMs rewrite a mode EEPROM and restart the CPU in that case; this one does not (there are two writes of Config in the image: the reset
write of 3, and a bare accessor at `0xbfc11a50` that nothing calls; the only little-endian action is the byte store above, the `, EL`
banner suffix and the table selections below). The monitor, memory test, environment, loader and inventory code all carry
little-endian branches, listed in the next section.

**Established, executed**: the image was run in an R4000 emulator (a generic CPU emulator, not the hardware) twice, once big-endian
and once little-endian, with the ROM presented so that each 32-bit word has the same value in both modes and with the two UART
status bits forced ready. Both runs printed the same text: the banner (the little-endian run adds `, EL`), then
"Memory address pattern test from A0000000 to A0003000" and "...from A0500000 to A05FFFFC". Both then stopped at the
timer-based CPU speed measurement at `0xbfc22410`, which needs a modelled timer. With that one routine replaced by a stub that
returns a constant, both runs went on, identically, to the secondary-cache tag-clearing loop at `0xbfc0cebc` and stayed in it for
the rest of the budget; why was not diagnosed (the loop step comes from Config and from the `e2` byte, and the emulator supplies
neither faithfully). So the code through the pattern test, including the little-endian string reads, is executed rather than only
read. Nothing beyond that was run.

**Unknown**: whether the PROM reaches the monitor prompt and loads a little-endian program on the real board. The remaining
obstacles are hardware behaviour the listing cannot show: the I/O board's byte lanes (see below), the DUART and the SCSI and
Ethernet DMA engines in little-endian mode, and the lane-unswizzled ROM reads in the hazards list. What would settle it is a run on a Crimson
with `e2endian little` set, or a complete model of the CPU board.

### What the 137 callers do

`0xbfc11ac8` returns 1 when Config bit 15 is clear (`mfc0; srl 15; andi 1; xori 1`). It has exactly 137 `jal` callers and no data
reference (searched for the address as a data word and as `lui/addiu` pairs). Reading the code after each call to the next
`jr ra` puts every call in one of these classes (the counts are from that reading and are exact for the classes of 1 to 4 sites; the
two large classes are counted by a pattern match and are within a few of the true figure):

| Class | Sites | What the little-endian branch does |
|---|---|---|
| Register-address table selection | about 91 | Chooses the little-endian one of two parallel pointer tables (see below), so a register access lands in the right byte lane. |
| String and ROM pointer reads | about 34 | If the pointer is in the PROM's own megabyte (`0xbfcxxxxx`) or in `0xa08xxxxx` (tested as `ptr >> 20` equal to `0xbfc` or `0xa08`), reads each byte at address `xor 3` (for example at `0xbfc0134c`, `0xbfc09574`, `0xbfc0b7b8`). Strings in RAM elsewhere are read plainly. |
| Hex digit tables | 3 (`0xbfc018b4`, `0xbfc0a128`, `0xbfc170d0`) | Uses a second copy of the digit string whose bytes are stored lane-swapped (`32107654BA98FEDC` at `0xbfc37e2c` against `0123456789ABCDEF` at `0xbfc37e40`, and a lower-case pair at `0xbfc3973c`, `0xbfc39750`), because the digit is fetched with a plain byte load. |
| Network byte-order helpers | 4 (`0xbfc0f718`, `0xbfc0f758`, `0xbfc0f798`, `0xbfc0f7d8`) | Swap a 32-bit or 16-bit value (`0xbfc1184c`, `0xbfc11834`) in little-endian mode and return it unchanged in big-endian mode: the standard network-to-host helpers. |
| Single-purpose | 4 (`0xbfc03538` program loader, `0xbfc03c00` banner, `0xbfc0c7b4` `endian` command, `0xbfc0a5ac` "IO3B" warning) | Described below. |
| Wrapper | 1 (`0xbfc222b0`) | A function that only returns the flag; its one caller is the dispatcher at `0xbfc223c4`. |

There is no code path that depends on the flag outside these classes.

**The two register tables** (established). Two arrays of ten pointers: `0xbfc39960` (big-endian view) and `0xbfc39988` (little-endian
view). The survey page says eleven; the arrays are ten entries each. Entry order and big-endian addresses: 0 `0xbf200001`,
1 `0xbf800000`, 2 `0xbfa00000`, 3 `0xbf400000`, 4 `0xbf600000`, 5 `0xbf100000`, 6 `0xbf180000`, 7 `0xbfe00000`, 8 `0xbd800000`,
9 `0xbd000000`. The little-endian entries are the big-endian ones with the lane swizzle of the bus each sits on: byte addresses on the
32-bit wide space are `xor 3` (`0xbf200001` becomes `0xbf200002`, `0xbf800000` becomes `0xbf800003`, likewise `0xbfa00003`,
`0xbf400003`, `0xbf600003`, `0xbf100003`, `0xbf180003`, `0xbfe00003`), and the words on the 64-bit wide space are `+4`
(`0xbd800004`, `0xbd000004`). Larger tables of 30 pointers each,
for the I/O board, sit at `0xbfc39780` (big-endian) and `0xbfc39870` (little-endian), twice over (a second 30-entry block with the
`0xb7b` prefix instead of `0xb7f`, +0x78); there a byte register `A` becomes `A xor 7`, a halfword `A xor 6` and a word `A xor 4`,
so each access reaches the same bus lane the big-endian access would. Twenty-six sites pick the ten-entry pair with the flag and
load one entry straight away (for example `0xbfc0c6d0` to `0xbfc0c6fc`); they use entries 0, 2, 4, 7, 8 and 9 only, and the
routine at `0xbfc1f1f0` selects both tables and keeps entry 2 of each in RAM descriptors. Entries 1, 3, 5 and 6 (`0xbf800000`,
`0xbf400000`, `0xbf100000`, `0xbf180000`) are never loaded by any code I found, and the `0xbf` space's other device addresses are
reached only through them.

**The only deliberate byte-order write is the byte store at reset** (established as the only conditional store; see the next section
for what it is).

**Hazards: ROM reads that skip the lane swizzle** (established as reads; consequences inferred). In little-endian mode a plain byte or
halfword load from ROM data returns a different byte from the one the big-endian build reads, because the ROM supplies whole words:

- The password encoder (`0xbfc125cc`, called by `passwd` at `0xbfc12318` and `0xbfc12338` and at `0xbfc12590`) XORs the first eight
  characters of the typed string with the eight-byte key `#!$%^&*@` (at `0xbfc3b10c`) using `lbu` at `0xbfc12664`, `0xbfc12670`,
  `0xbfc1267c`, `0xbfc1268c`, and then turns each byte into two characters through the table `cafebabedeadbeef` (`0xbfc3b0f8`). None of
  these ROM reads has an `xor 3`, so in little-endian mode the key and the table are read with their bytes permuted within each
  word. A password stored in non-volatile RAM in one byte order will then not match in the other (inferred).
- A switch byte at `0xbfc46190` (value 1 in the ROM word, tested at `0xbfc3705c`) gates an IP header checksum check in the network
  code; in little-endian mode it reads 0, so the check is skipped (inferred).
- Five halfword loads at `0xbfc3fe94` (callers `0xbfc2a780`, `0xbfc2a8b8`, `0xbfc2aab0`, `0xbfc2b67c`, `0xbfc2b734`) and a byte
  load at `0xbfc3fe10` (caller `0xbfc29efc`) read ROM constants that are zero or small; whether the swizzle changes their value was
  not worked out (unknown).

## The byte at `0xbd800007`, the `0xbfe00000` byte and `e2endian`

**`0xbd800007`.** The reset store (established) writes `1` to byte 7 of the doubleword at `0xbd800000`. On the I/O swizzle the tables
show, a little-endian byte at offset 7 is the most significant byte of the 32-bit big-endian word at `0xbd800000`, so it is bits
31 to 24 of that register. The register at `0xbd800000` is read by the PROM in three places and never written:

- through table entry 8 (`0xbd800000`/`0xbd800004`) in two bus-probe routines, `0xbfc21e20` (read probe) and `0xbfc21f38` (write
  probe), which touch an address with a byte, halfword or word access, then read the register and test `andi 0x1e0` at
  `0xbfc21ee0` and `0xbfc21ff4`; the routine returns 1 when any of bits 5 to 8 is set, and then reads `0xbd000000` (table entry 9)
  and discards the value; before the access it also reads `0xbd000000` once;
- once unswizzled at `0xbfc0f968` in the exception dump (the word is saved in the crash block and later printed).

The four bits `0x100`, `0x80`, `0x40`, `0x20` are printed by the routine at `0xbfc0ae48` ("Rmp Status: %x < %s%s%s%s>") as `DMA BERR`,
`IOEACK`, `IOWACK` and `RANGE`. So the register at `0xbd800000` is the system-bus status word, and `0xbd000000` is read to
acknowledge it (inferred from the names and the read-and-discard). Whether the store of 1 in bits 31 to 24 sets a mode or merely
clears a status field is **unknown**: no big-endian code writes that register, and no instruction reads that byte back. The only link to
byte order is that the PROM writes it on the little-endian path alone; the warning at `0xbfc39a8c` ("IO3B needed for little endian
IO") shows that little-endian operation needs a particular I/O board variant. What would settle it: the Crimson CPU-board
documentation (not held), or the IRIX kernel for this board.

**The `0xbfe00000` byte.** Table entry 7 (`0xbfe00000`, little-endian view `0xbfe00003`) is a byte-wide region on the same bus lane as
the other `0xbf` devices. Its uses are exactly four, all through the table:

| Site | Access | Use |
|---|---|---|
| `0xbfc0c6fc` | `lbu` at +0, `andi 4` | `e2endian` with no argument: returns bit 2 |
| `0xbfc0c744` | `lbu`, `ori 4`, `sb` at +0 | `e2endian big`: set bit 2 |
| `0xbfc0c784` | `lbu`, `andi 0xfb`, `sb` at +0 | `e2endian little`: clear bit 2 |
| `0xbfc0c8d8` | `lbu` at +0x80 | secondary cache size: 4 MB when the byte is `0xba`, otherwise 1 MB (function `0xbfc0c8ac`; the 4 MB value is `lui 0x40`, the 1 MB value `lui 0x10`) |

There is no other reference to this region as a constant (the words `0xbfe00000` and `0xbfe00003` occur only in the two tables), and
no other code loads table entry 7. The `e2endian` handler is at
`0xbfc0c7f4`: with no argument it prints `big` when the bit is set and `little` when clear (`0xbfc39d70`, `0xbfc39d78`); with one argument
the first character `b` (98) sets and `l` (108) clears; it then returns. It does not reset the machine or touch Config.

**How `e2endian` takes effect.** The PROM never reads the bit at reset: the reset path reads Config and nothing else, and the only reader
of the bit is the `e2endian` status call. So the bit reaches `Config.BE` through the hardware, which presumably samples it into the CPU's
byte-order strap on the next reset (**inferred**; the PROM neither reads it back nor triggers a reset). The name `e2` suggests a small
non-volatile part, which fits a byte that is written with no ready poll only if it is a battery-backed or fast-write device (unknown which). What would settle it is the CPU-board schematic, or an
owner with a Crimson who runs `e2endian little`, power-cycles, and then runs `endian`. The `endian` command (handler `0xbfc0c7ac`) prints
`cpu endian:`, then `little` or `big` from Config alone, so it can confirm the result.

## The loader refuses images of the wrong byte order (established)

The file loader at `0xbfc03490` opens the named file, reads a 76-byte header into a local buffer and, at `0xbfc03538`, tests the flag:

- little-endian: the 16-bit file-header magic must be `0x162`, `0x166` or `0x142`; otherwise the PROM prints
  "%s: not little endian byte order" (`0xbfc38450`, built at `0xbfc03568`) and gives up;
- big-endian: the magic must be `0x160`, `0x163` or `0x140`; otherwise it prints "%s: not big endian byte order" (`0xbfc38474`).

`0x160` and `0x162` are the big- and little-endian MIPS file magics of the public NetBSD ecoff header (not re-read here); the other
four are accepted by the code and were not named from a public source. Magic accepted, the loader goes on to the optional-header
magic at offset 20 (`0x107`, `0x108`, `0x10b`, `0x123` and `0x109`; anything else prints "%s: bad magic number", `0xbfc38494`). So a
little-endian PROM boots only a little-endian image, and the PROM does not byte-swap or convert an image. Strings elsewhere in the
loader ("not in a.out format", "short read") are the other rejections. The network boot path (`bootp` then TFTP) hands its file to
the same routine, so the same check applies.

## Memory sizing and where RAM sits

All **established** unless marked.

- **Size source.** The word at `0xbf000000` (read directly, not through a table, at `0xbfc03e38` and in the exception dump at
  `0xbfc0f958`). Bits 3 to 0 are `n`. If bit 4 is clear the memory size is `n << 24` (n x 16 MB); if bit 4 is set it is `(n << 26) +
  0x10000000` (256 MB + n x 64 MB). The routine at `0xbfc0ad8c` prints the same decode as `msize` in the line "Mpsr:%x:id %d msize %d %s%s%s",
  which names the register (Mpsr) and prints three more flags from bits 7, 8 and 9, each as one of two short strings; what the
  flags and the id field (`word & 0x60`) mean is unknown. Whether bits above 9 are used is unknown.
- **Where RAM sits.** RAM is assumed contiguous from physical 0: the tests and clears below run over `0xa0000000`-based addresses
  from page 0 up to the size. No register sets a base. The PROM's own workspace is physical `0x500000` to `0x5fffff` (strings
  buffer at `0xa0500010`, a copy of its clear loop at `0xa0500050`, an NVRAM shadow at `0xa0500530`, globals from `0xa0510000`, and the
  crash block at `0xa0511500`); that megabyte is never cleared or handed to a program. The exception-vector and parameter pages at
  `0x1000` to `0x2fff` are skipped by the test and the clear.
- **Test and clear order** (`0xbfc069b0` and the main routine). The quick memory test checks `0..0x1000`, `0x3000..0x500000`
  and `0x600000..0x800000`. The full test runs the same ranges to `min(size, 0x1000000)` and then the rest with an uncached
  or cached routine copied to RAM. After that main clears, either cached (`0xbfc03e74`) `0x80003000..0x80500000` and
  `0x80600000..top` and then once more over `0x80600000` plus the secondary cache size, or uncached (`0xbfc03f70`) `0xa0003000..0xa0500000` and `0xa0600000..(0xa0000000|min(size, 32 MB))`. The
  banner message is "Sizing caches, clearing 4 Mbytes of memory" and the main routine clears `0xa0600000..0xa0a00000` (6 to 10 MB)
  unconditionally at `0xbfc03cc0`, so at least 10 MB of RAM is assumed. The cached and uncached clears exist because
  uncached clears are slow.
- **Stack of the PON monitor.** `0xbfc009d4` sets Status to `0x410000`, then `sp = 0x80600000 + (data cache size) - 4` and jumps to the
  `pon>` loop at `0xbfc00f80`, so the diagnostic monitor runs on a stack in the first cache-size bytes above 6 MB. The stack of the
  main monitor was not traced.
- **Consequence for a client that needs RAM at physical 0 and at 6 MB.** The PROM supplies both (page 0 to `0x4fffff` and
  `0x600000` up), keeps `0x500000` to `0x5fffff` for itself and leaves the rest as unclaimed RAM; the diagnostic monitor's stack
  and the clears use the region above 6 MB, so a client must not assume it is untouched. The PROM never touches memory above
  the 512 MB window of KSEG0 and KSEG1 (every address it forms is `0x80000000` or `0xa0000000` plus the offset), so memory beyond
  512 MB is neither tested nor cleared; whether the size register can encode more than that and whether the hardware decodes it
  is unknown (the decode above reaches 1216 MB).

## Caches (established unless marked)

All sizes come from Config; there is no tag probe in the live code.

- Primary data size: `1 << (Config[8:6] + 12)` (`0xbfc0c940`). Primary instruction size: `1 << (Config[11:9] + 12)` (`0xbfc0c95c`).
  Line sizes: data 32 bytes when Config bit 4 is set, else 16 (`0xbfc0ca44`); instruction 32 when bit 5 is set, else 16 (`0xbfc0ca64`).
- Secondary cache: size is not probed but chosen by the EEPROM byte at offset `0x80` of the `0xbfe00000` region (4 MB if `0xba`, else
  1 MB; `0xbfc0c8ac`). Its line size is `1 << (Config[23:22] + 4)` unless Config bit 17 (no secondary) is set, when `0xbfc0ca84`
  returns 0. A tag-probing sizer at `0xbfc0c978` to `0xbfc0ca40` (it writes the tags and looks for one that reads back zero over
  64 KB to 4 MB) has no caller and no data reference; whether it is dead is **inferred**.
- The sizes and line masks are stored at `0xa0511404` to `0xa05114cc` and used by the maintenance routines (`0xbfc0cb44` writeback-and-
  invalidate of data, `0xbfc0cbc0` instruction invalidate, `0xbfc0cd..` the ranged forms; they step with `cache` ops 0 and 1).
- The start-up cache self test prints "Primary D-cache", "Primary I-cache" and "Secondary I+D cache" failures and tag, address,
  data and memory-interface tests (strings at `0xbfc38c94` onward), run from the PON diagnostics.

## Environment and NVRAM (established)

**Store.** The environment lives in a byte-wide non-volatile RAM on the I/O board whose base is entry 26 of the large register table
(`0xb7f10000`, little-endian view `0xb7f10007`; the second-board copy is `0xb7b10000`). Each logical byte `i` is at `base + 8*i`.
Reads go through `0xbfc0b6a4(offset, count)`, which copies the bytes into a shadow string at `0xa0500530`; writes go through
`0xbfc0b7b8(offset, count, string)`, which walks the source string with the little-endian `xor 3` rule when it lives in ROM.
`offset` is in address bytes (a variable of `n` characters spans `8n` bytes).

**Layout.** Twelve variables, from the record table at `0xbfc38120` (name, default, offset, length):

| Name | Offset | Length | Default |
|---|---|---|---|
| `netaddr` | `0x000` | 16 | `192.0.2.1` |
| `dbaud` | `0x080` | 5 | `9600` |
| `rbaud` | `0x0a8` | 5 | `9600` |
| `bootfile` | `0x0d0` | 50 | `dksc(0,1,8)sash` |
| `bootmode` | `0x260` | 1 | `m` |
| `console` | `0x268` | 1 | `g` |
| `root` | `0x280` | 20 | `dks0d1s0` |
| `keybd` | `0x320` | 10 | `df` |
| `monitor` | `0x370` | 4 | `60` |
| `sync_on_green` | `0x390` | 1 | `y` |
| `diskless` | `0x398` | 1 | `0` |
| `passwd_key` | `0x3a0` | 17 | empty |

**Validity.** The byte at offset `0x3ff0` is a checksum and the byte at `0x3fe8` a valid flag. The checksum (`0xbfc0b950`) runs over every
logical byte below `0x3ff0` (2046 of them): start at `0xa5`, then for each byte `v = rotl8(v xor byte)`; the result is compared with
the stored byte. The flag counts as valid when `byte & 0x56` is non-zero. On a bad checksum the PROM prints "Non-volatile RAM
checksum is incorrect", on a clear flag "Non-volatile RAM is not set valid", then "Initializing the non-volatile RAM parameters."
and runs `0xbfc031e0`, which clears bits `0x56` of the flag byte, writes each default through the write routine, and sets bits `0x56`
again. Every call of the write routine recomputes the checksum and stores it in table entry 28 (`0xb7f13ff0`, little-endian
`0xb7f13ff7`; `0xbfc0b924` to `0xbfc0b93c`). The check is the function at `0xbfc03120`, called first from `0xbfc02fe0` (which then
builds the in-RAM environment list from the record table); it writes a zero byte to entry 29 (`0xb7f18000`) before it starts.

Other variables seen as strings and not stored in NVRAM: `DEBUG`, `VERBOSE`, `UDPCKSUM` and the read-only informative ones that
"Cannot change - variable is informative only" protects (`cpufreq`, `hostname`, `path`).
`getenv` is `0xbfc128f0`; `printenv`, `setenv` and `unsetenv` are the commands at `0xbfc186d0`, `0xbfc18440`, `0xbfc185e8`.
Writing a variable that fails the read-back prints "Non-volatile ram write error".

**The e2 region is separate.** The byte at `0xbfe00000` and its `0x80` byte are a different store from the NVRAM (a different address
table, 32-bit lane against 64-bit lane). The CPU-board store is at `0xbfe00000`; the environment is on the I/O board.

## Console (established unless marked)

- **Early console.** The routine at `0xbfc00b18` prints a string, one character at a time through `0xbfc00b5c`. It is the small
  routine used before anything is initialised: little-endian aware (the `xor 3` rule on the string pointer), and it addresses the UART
  through the word at `0xbfc399c0` (big-endian view `0xbfa00000`) or `0xbfc399c4` (little-endian view `0xbfa00003`). It waits up to
  `0x8000` loops for status bit 3 (`andi 8`) and then bit 2 (`andi 4`) in the byte at offset `0x10`, and writes the character to
  offset `0x30`.
- **UART self test** (`0xbfc04390`): the PROM writes `0x2a, 0x3a, 0x4a, 0x1a` to offset `0x20`, `0x13` and `0x87` to offset `0`, `0xbb` to
  offset `0x10`, `0x05` to offset `0x20`, then sends `0x31..0x44` through the transmitter and checks it back at offset `0x30` with
  status bit 0. With the `0x87` mode byte (bit 7 set) this is a local loopback. The register layout (a 16-byte register stride;
  mode at 0, status or clock-select at `0x10`, command at `0x20`, data at `0x30`) and the command values match a Signetics 2681-style
  dual UART (inferred; the part name is nowhere in the image). Failure blinks the LED forever. The strings name four dual UARTs:
  "DUART0 channel B", "DUART2 channel A and B", "DUART3 channel A and B".
- **Which console.** `console` is read at `0xbfc2053c` to `0xbfc2062x` and at `0xbfc10ba8`. The character `g` (0x67) or `G` (0x47) selects the
  graphics path (default `g`); `d` (0x64), `r` (0x72) and `a` (0x61) are also compared and select other behaviours that were not
  traced (inferred as a serial console for `d` and the remote or alternate ports for `r` and `a`). The graphics path probes
  a board ID word at `0xb7000000` through the bus-probe routine (low byte `0xdd` or `0xee`), prints
  "gfx: no working graphics hardware", "gfx: couldn't open keyboard", "gfx: GM DRAM doesn't respond",
  "gfx: couldn't identify graphics board" and similar, and reads the `monitor` and `sync_on_green` variables. The serial paths use `dbaud`
  and `rbaud` (device names `tty(0)` and `tty(1)`). `enable` and `disable` add or drop a console device (`console uart`,
  `graphics`, `pseudo console` are the device names).
- **Little-endian banner.** The banner for the graphics console is built at `0xbfc03c00` to `0xbfc03c4c`: in little-endian mode it copies
  the banner into a RAM buffer at `0xa0500010` (`0xbfc12df0`), appends `, EL` and two line breaks (`0xbfc38ae8`, `0xbfc12b80`) and
  prints the buffer (`0xbfc113bc`).

## Hardware inventory (`hinv`) (established as strings and walk; inferred as roles)

`hinv` (handler `0xbfc17640`) walks an in-RAM component list that the start-up code built; the node type (offset 8 of each node,
values 1 to 8) selects a print routine through a jump table (the eight-entry table at `0xbfc37844` is one of them). The strings it can
print:

- CPU board: the names `IP15`, `IP17` and `IP12` select among three line formats, with `%d MHZ` or the `cpufreq` variable; the
  IP17 line reads "CPU board: IP17 <n> MHZ". "Processor %d" for a multiprocessor build.
- "System option: Floating point processor".
- "Memory size: %2d Mbytes"; "Instruction cache size: %2d Kbytes"; "Data cache size"; "Secondary data cache size" or
  "Secondary I/D cache size" in K, 1 Mbyte or MB forms.
- Graphics: `GR1.1`, `GR1.2` with the options Auxiliary Planes, Medium Resolution Monitor, Turbo, Bitplane Expansion and Z-Buffer;
  `LG1`; `GR2` with `-XS`, `-XS24` and `-Elan` and Z-buffer variants. The Crimson upgrade document names the Elan graphics.
- System options: Central Data serial board, National Instrument GPIB board, audio processor with a revision.
- Storage: Interphase ESDI (`dkip`), SCSI disks (`dksc`) with controller and ID, SCSI tapes by type (QIC-24, DAT, QIC-150,
  9 track, 8mm), CD-ROM, scanner, removable flag, ISI tape (`tpqic`), Xylogics SMD and IPI controllers (drivers `xyl` and `ipi` are in the
  image) and VME boards.

The memory figure printed is the size from `0xbf000000` described above; the cache lines print the sizes from the Config decode.

## Monitor commands (established)

The command table is at `0xbfc38540`, twelve bytes per entry (name, handler, usage string): `auto` (`0xbfc0d0f8`), `boot` (`0xbfc16180`),
`disable` (`0xbfc16534`), `dump` (`0xbfc168c0`), `checksum` (`0xbfc17470`), `enable` (`0xbfc164d0`), `endian` (`0xbfc0c7ac`),
`e2endian` (`0xbfc0c7f4`), `exit` (`0xbfc17540`), `fill` (`0xbfc166ac`), `g` (get, `0xbfc17228`), `go` (`0xbfc17590`), `help` and `?`
(`0xbfc14c90`), `hinv` (`0xbfc17640`), `init` (`0xbfc00620`), `load` (`0xbfc17ff0`), `p` (put, `0xbfc17338`), `passwd` (`0xbfc122d0`),
`printenv` (`0xbfc186d0`), `resetpw` (`0xbfc123a8`), `setenv` (`0xbfc18440`), `sload` (`0xbfc187b0`), `unsetenv` (`0xbfc185e8`),
`dev` (`0xbfc18ec0`, device test), `cp` (`0xbfc195c0`), `version` (`0xbfc17560`), `ecc` (`0xbfc19a40`, `ecc 0|1`). Usage strings are in
the image (`boot [-f FILE] [-n] [ARGS]`, `dump [-(b|h|w)] [-(o|d|u|x|c|B)] RANGE`, and so on). There is a separate small command
set behind the `pon>` prompt (`0xbfc37c50`): `ww`, `wh`, `wb` (write), `dw`, `dh`, `db` (display), `dr`, `wr` (registers `sr` and `sp`),
`sload`, `mem LO HI`, `sys` and `?`. A set switch bit tested by `0xbfc04264` (mask `0x81`) at the top of the main routine prints "PON switch was set." and enters PON mode through `0xbfc009d4`;
mask `0x84` is tested at `0xbfc03c84` (it selects the uncached clear and a direct entry to the monitor) and in the loader at `0xbfc034a0`
(it adds trace lines); neither use was traced further, so its role as a diagnostic switch is inferred. The tested register is the
halfword at entry 3 of the large table (`0xb7f30000`, little-endian `0xb7f30006`), read as a halfword; its role as a switch word is inferred.
The program loader path, passwords (`passwd`, `resetpw`, "Enter new password:", the key discussed above) and the boot menu strings
("To perform system maintenance instead, press <Esc>") complete the monitor.

## The device map the PROM touches

Addresses are the big-endian-view virtual addresses in KSEG1; the physical address is the low 29 bits. "Table" means reached through the
register tables above, so the little-endian address differs as described. Grades are for the access, not for the part named.

| Address | Width | What the PROM does there | Grade |
|---|---|---|---|
| `0xbf000000` | word | Read for memory size and printed as `Mpsr` (see above). Also read in the exception dump. | established; name inferred |
| `0xbf200001` | byte | Front-panel LED: the one's complement of a value is stored (`0xbfc00a4c`, `0xbfc0c684`). | established; role inferred |
| `0xbf600000` (table entry 4) | bytes at +0, +4, +8, +12 | A three-counter timer: control words `0x34`, `0x74`, `0xb4` at offset 12 (counter 0, 1, 2 in mode 2, 16-bit loads), counters at 0, 4 and 8. Used for ticks and the CPU speed measurement at `0xbfc22410` that feeds "%d MHZ". After each write the code reads `0xbc000000` (a bus drain, inferred). | established as accesses; part inferred |
| `0xbfa00000` (table 2) | byte | Console dual UART (above). Also tested as "DUART0 channel B" etc. | established; part inferred |
| `0xbfe00000` (table 7) | byte | CPU-board `e2` store: byte 0 bit 2 = endian bit, byte `0x80` = secondary cache size flag. | established |
| `0xbd800000` (table 8) | word | System-bus status, bits `0x1e0` = four error flags; read in the bus-probe routines and the exception dump; the byte at `0xbd800007` is stored once on the little-endian path. | established; name inferred |
| `0xbd000000` (table 9) | word | Read and discarded after probes and in the status-set routine at `0xbfc11790` (which loads Status with `0x4001`); an acknowledge. | inferred |
| `0xbc000000`, `0xbc000004` | words | Read in the exception dump as "Rmp Error Address: %x %x"; read once after each store in timing loops (bus drain). | inferred |
| `0xbe400000`..`0xbe4000fc` | words | A block of 32-bit registers touched by one routine cluster at `0xbfc072a4` to `0xbfc07560` (offsets `0x04`, `0x20`, `0x38`, `0x40`, `0x78`, `0x80`, `0xa0`, `0xb0`, `0xc0`..`0xd8`, `0xfc`: set to zero, read back, tested); it has no little-endian twin in the tables, which fits words only. I did not tie it to a named test. | established as accesses; role unknown |
| `0xb7000000` | word | Probed for a graphics board ID (low byte `0xdd` or `0xee`). | established; role inferred |
| `0xb7c20000` | byte | Read with `lb` in the Ethernet driver's set-up code (`0xbfc33454`, `0xbfc3347c`; the driver has "eh%d: bad RAM" strings). | role inferred |
| `0xb7c14000`, `0xb3f0ffff`, `0xb7d00000`..`0xb7d7ffff` | byte | `0xb7d00000` upward is walked in 8-byte steps with a zero written to `0xb7cffff8` by code inside the `ecc` command handler (`0xbfc19a98` to `0xbfc19b54`); the other two are built at `0xbfc2c328` and `0xbfc2c378` in the disk-driver region. | unknown |
| `0xb7f10000` (entry 26) | byte, stride 8 | The environment NVRAM, 2048 logical bytes; entry 28 (`0xb7f13ff0`) is the checksum byte. | established; part unknown |
| `0xb7f13ff8` (entry 27) | byte | Time-of-day clock, bit-serial: the PROM writes the 64-bit pattern `C5 3A A3 5C C5 3A A3 5C` (ROM at `0xbfc39c60`), one bit per write, then reads or writes eight clock bytes one bit at a time (`0xbfc0b534`). The pattern is the recognition sequence of a Dallas phantom-clock part that sits in the RAM socket (inferred from the pattern; the datasheet is not held). Strings: "initializing tod clock", "setting secs=%d min=%d hour=%d day=%d month=%d year=%d". | established as accesses; part inferred |
| `0xb7f18000` (29) | byte | Written with 0 before the checksum check. | unknown |
| `0xb7f30000` (3) | halfword | Option or switch word read by `0xbfc04264`. | established; role inferred |
| `0xb7f40000`..`0xb7f40003` (11 to 15) | bytes | Four byte registers: written once with the word `0x01010000` at reset; bit 0 of the last pulsed (set then cleared) at `0xbfc0a674` to `0xbfc0a6a4`; bits `0x40` and `0x80` set and cleared by the routine at `0xbfc0bad4` for two units. | established as accesses; roles unknown |
| rest of the 30-entry table | various | `0xb7fe0000`, `0xb7fe8000`, `0xb7ff0000`, `0xb7ff0002`, `0xb7ff4000`, `0xb7ff8000`, `0xb7fc0002`, `0xb7fc000a`, `0xb7f28000`, `0xb7f20000`, `0xb7fa0000`, `0xb7fb0000`, `0xb7f48000`, `0xb7f4c000`, `0xb7f60000`, `0xb7f10000`/`0xb7f13ff0`, `0xb7e00004`, `0xb7fffff0` | roles not read; the table lists them |
| `0xb7fffff4` | byte | Read in little-endian mode only: bit 0 set prints "IO3B needed for little endian IO" (`0xbfc0a5bc`..`0xbfc0a5dc`). Read without the lane swizzle; its big-endian equivalent is `0xb7fffff3`. | established; meaning inferred |

The second 30-entry block (`0xb7b` prefix) is a second copy of the same registers for a second I/O board; the routines that take a unit
number (`0xbfc0bad4`) divide it by two to choose the board and use its low bit for the unit. That is inferred from the index
arithmetic only. The drivers present in the image, by string, cover SCSI (`sc`), Ethernet (`eh`, `enp`), Xylogics and IPI disk,
a tape driver, GPIB, a Central Data serial board and an audio processor; they were not read.

## Differences from the survey page

- The register-address tables hold ten entries each. The survey's eleventh pair is the neighbouring data: the eleventh big-endian
  position is the first little-endian entry (`0xbf200002`) and the eleventh little-endian position is the separate pair at
  `0xbfc399b0` (`0xb7f40000`, `0xb7f40004`). The command table starts at `0xbfc38540`, not `0xbfc38560`.
- The loader's two rejection strings are called from `0xbfc03568` and `0xbfc035a0` of the loader, not just present.
- The 137 callers are classified above; the survey only counted them.
- `0xbd800000` is the system-bus status word (names printed beside bits 5 to 8) and the byte store at reset sets part of it on the
  little-endian path. Its effect is still unknown.
- The `0xbfe00000` region is not just the endian byte: it also holds the secondary-cache-size flag, which makes it a small
  configuration store.

## Not established here

See [the question page](../../questions/ip17-prom-software.md): whether the little-endian boot completes on hardware, what the byte
store to `0xbd800007` does, how the hardware samples the `e2` bit at reset, the polarity of the `IO3B` test, what the
`0xa08xxxxx` class of string pointers is, the real effect of the lane-unswizzled ROM reads, the second I/O-board block, and the
non-volatile part behind the environment.
