# DM2 (XT-DIGVID): FPGA info table and the full load protocol

Status: **draft, not independently reviewed.** Part of the [DM2 scoping datasheet](../xio-dmediapro-dm2.md),
which carries the board identity and the rest of the register map. This page is the whole path by which the
user-space ML module puts eight FPGA configurations onto the board, and what it reads back to decide each
load worked. Labels follow [AGENTS.md](../../AGENTS.md): **E** established, **I** inferred, **U** unknown.
Section 9 lists every U with what would settle it. Section 10 lists where this page corrects the scoping
datasheet.

## Evidence

Everything below was read from disassembly (n32 big-endian MIPS, `objdump -d` with the object's own symbol
table and GOT), not from decompiled C. Shipped paths are relative to the install root of the DM2/DM3 software
1.1.3ml set.

| Tag | Object | sha256 | What it is |
|---|---|---|---|
| L | `usr/lib32/mlmodule/libdigvid.so` | `aacf8d4a64dcd34b523c4b2b7bc66153104b710171d42f7e65a588bcb95bc2ca` | the ML module; `.text` 0x406fd0 to 0x417814, `.data` 0x41c6d0 to 0x41fd88, `.srdata` 0x4203b0 |
| K30 | `usr/cpu/sysgen/IP30boot/xtdigvid.o` | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` | kernel object, only used for the readbacks in section 6 |
| K27 | `usr/cpu/sysgen/IP27boot/xtdigvid.o` | `138ab5488ed6263b14582c61cf324a79929459ba62f29f92113fed36630f38ae` | `xtdigvid_verify_gif_loaded` (0x5e64) compared with K30 only |
| K35 | `usr/cpu/sysgen/IP35boot/xtdigvid.o` | `64c024a59b6b1dd7962af6d7857e83ff93ef29e498816b91c524a4d00fab1976` | `xtdigvid_verify_gif_loaded` (0x5870) compared with K30 only |
| M | the 60 files in `usr/dmedia/ucode/xtdigvid/` | per file in section 7 | the FPGA images |

Addresses for L are virtual addresses in the linked library. Every register offset is a byte offset into the
16 MiB widget window the library maps (`mmap(0, 0x1000000, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)`, at L
0x4165f8 to 0x416618, error text "mmap" by `perror`). All device accesses on the load path are 32-bit
(`lw`/`sw`) and none is followed by a `sync` (no `sync` instruction exists in L 0x4164f0 to 0x417750). The
only byte-wide accesses in that range touch host buffers.

The library's own symbol names that are exported and used here: `xthd_program_xilinx` (L 0x416570, 1096 bytes
by its symbol, but the routine's callees are static code that follows it up to 0x417814), `xthd_fpga_info`
(L 0x41fca8, 224 bytes, `.data`). The static routines have no symbol; the names used below ("GIF start",
"others stop") are the prefixes of the library's own messages, which name the routine each message sits in.

## 1. The info table `xthd_fpga_info` (L 0x41fca8, 8 records of 28 bytes) **E**

All fields are 32-bit big-endian words. Record `n` is at `0x41fca8 + 28*n`. The record index is the FPGA
number passed to `xthd_program_xilinx` (valid range 0 to 7, anything else prints
"program_xilinx: invalid FPGA number" and returns -1, L 0x416598 to 0x4165ac and 0x41679c).

| Offset | Field | Use in the code (all E) |
|---|---|---|
| +0 | pointer to name string | printed in the messages "%s INIT timed out", "%s READY timed out", "%s DONE timed out" and "program_xilinx: %s: failed programming at byte %d" |
| +4 | kind: 0, 1 or 2 | selects the start, byte and stop routines (L 0x4166a4 to 0x4166c4); kind 2 also skips the length check on the image (section 7) and changes where a byte is stored (section 4) |
| +8 | image size in bytes | `malloc` size of the load buffer, and the exact byte total the image file must contain (section 7) |
| +12 | select word | stored, with bit 7 set or clear, at window offset `0x80000c` (section 4) |
| +16 | port offset | OR-ed into `0x800004` (status port) and `0x880004` (data port) (section 4) |
| +20 | DONE mask | tested in the word read from `0x120000` |
| +24 | INIT mask | tested in the word read from `0x120000` |

The table, read from the library's `.data` (`objdump -s`) and checked against the code above:

| n | name (string at) | role | kind | size (bytes) | select | port offset | DONE mask | INIT mask | status bits in `0x120000` (DONE, INIT) |
|---|---|---|---|---|---|---|---|---|---|
| 0 | `gif` (0x420478) | GIF | 1 | 179233 (0x2bc21) | 0x00 | 0x0000 | 0x0001 | 0x0002 | 0, 1 |
| 1 | `pack` (0x420480) | PACKER | 0 | 104066 (0x19682) | 0x01 | 0x0800 | 0x0004 | 0x0008 | 2, 3 |
| 2 | `unpack` (0x420488) | UNPACKER | 0 | 104066 | 0x02 | 0x1000 | 0x0010 | 0x0020 | 4, 5 |
| 3 | `oxcc` (0x420490) | OXCC | 2 | 318256 (0x4db30) | 0x20 | 0x3000 | 0x0100 | 0x0200 | 8, 9 |
| 4 | `ixcc` (0x420498) | IXCC | 2 | 318256 | 0x10 | 0x2800 | 0x0040 | 0x0080 | 6, 7 |
| 5 | `hdoc` (0x4204a0) | HDOC | 0 | 104066 | 0x08 | 0x2000 | 0x1000 | 0x2000 | 12, 13 |
| 6 | `vif` (0x4204a8) | VIF | 0 | 104066 | 0x04 | 0x1800 | 0x0400 | 0x0800 | 10, 11 |
| 7 | `clink` (0x4204b0) | CLINK | 0 | 35428 (0x8a64) | 0x40 | 0x3800 | 0x4000 | 0x8000 | 14, 15 |

- **E.** The role of each record is fixed by `xhdInit` (L 0x407880): it loads record 0 from `gif_1.xla`
  ("Failed to load GIF FPGA with image %s"), 7 as CLINK, 5 as HDOC, 3 as OXCC, 2 as UNPACKER, 6 as VIF, 1 as
  PACKER and 4 as IXCC, each with the matching "Failed to load <role> FPGA" message. That is also the order
  of the loads (section 8).
- **E.** Each of the seven non-GIF records has its select bit set in exactly one position (1, 2, 4, 8, 0x10,
  0x20, 0x40 for records 1, 2, 6, 5, 4, 3, 7) and a port offset that steps by 0x800 in the same order
  (0x800, 0x1000, 0x1800, 0x2000, 0x2800, 0x3000, 0x3800). The two mask words are adjacent bit pairs of the
  16-bit status word at `0x120000`: DONE at the even bit, INIT at the odd bit, pairs in the order GIF, 1, 2,
  4, 3, 6, 5, 7 (note records 3 and 4 and records 5 and 6 are swapped against their record numbers).
- **E.** Image size 104066 is the size of every PACKER, UNPACKER, HDOC and VIF file, 318256 of every OXCC and
  IXCC file (including the `_2` and `diag_` variants), 179233 of the GIF file and 35428 of the CLINK file
  (section 7).
- **I.** The select word is a one-hot choice of which of the seven FPGAs behind the GIF a control pulse is
  aimed at, and bit 7 of the control word is a program-strobe level (idle high, pulsed low). The code only
  shows the values and the pulse shape; the names are mine.
- **I.** Each of the seven FPGAs owns a 0x800-byte region of the GIF register file (`0x800000 + port offset`),
  with its status port at word 1 of the region (`| 4`) and the same word aliased with bit 23 set
  (`0x880004 | offset`) as the data port. The CLINK region (0x803800) is where the library's checked write
  (`xhdWriteWord`, which ORs `0x800004` into the offset, L 0x40d9e0 to 0x40da10) reaches the words for offsets
  `0x38e0`, `0x3860` and `0x3868` (window `0x8038e4`, `0x803864`, `0x80386c`) that reset the CLINK FPGA and set
  its pattern generator (L 0x407f20, 0x407fe8, 0x4081b8), which fits the same layout.

## 2. `xthd_program_xilinx` and the PIO delay helper

Signature as the callers use it (n32, arguments in `$4` to `$8`): `xthd_program_xilinx(fd, name, n, check,
verbose)`. **E** from the call sites.

- `xhdInit` (L 0x407954 to 0x407e6c, eight calls) passes `check = 1`, `verbose = 0`.
- `xhdCommitPathControls` (L 0x40a544, 0x40a59c, 0x40a948, 0x40a9a0, 0x40aa68, 0x40ae58, six calls)
  passes `check = 0`, `verbose = 0`. These reload VIF (standard or high definition), HDOC, PACKER and
  UNPACKER when a path is committed with a different format.

Steps, in order (L 0x416570 to 0x416990):

1. Range-check `n`, then `malloc(info[n].size)`; failure prints "can't alloc FPGA buffer" and returns -1.
2. `mmap` the 16 MiB window; failure prints "mmap" through `perror`, frees the buffer and returns -1.
3. Build the file path (section 8) and read the image (section 7) into the buffer. A non-zero return from the
   reader (1) frees the buffer, unmaps and returns that value.
4. Run the start routine for the record's kind, then the byte routine once per image byte, then the stop
   routine. Any failure frees the buffer, unmaps and returns -1 (the byte routine's failure also prints
   "program_xilinx: %s: failed programming at byte %d" with the name and the byte index).
5. On success, free, unmap, return 0.

The routine choice (L 0x4166a4 to 0x4166c4 and 0x416834, 0x4167d0): kind 1 runs start 0x4169c0, byte 0x416ba0,
stop 0x416c80 (the GIF set). Kinds 0 and 2 run start 0x416e00, byte 0x417070, stop 0x4171d0 (the "others" set).
The byte routine gets `(fd, window, n, byte, is_last, check)` where `is_last` is true for the final byte.

**PIO delay helper (L 0x4164f0, `write_word+0x80`).** Every wait on the load path calls it as `wait(fd,
window, arg)`. It is not a timer. It computes `count = floor((arg + 19) / 20)` (a multiply by 0xcccccccd, a
high-word shift of 4, sign-folded), and when `count > 0` it stores 0 to window offset `0x6c`, `count`
times (unrolled by four). **E** (L 0x4164f0 to 0x416568). `0x6c` is the XG error-cause register of the scoping
datasheet, whose clear is a write of the value read back, so a store of 0 clears nothing. Counts for the
arguments the load path uses:

| arg | 20 | 100 | 120 | 300 | 400 | 1000 | 4000 | 5000 | 176000 | 4000000 |
|---|---|---|---|---|---|---|---|---|---|---|
| stores to `0x6c` | 1 | 5 | 6 | 15 | 20 | 50 | 200 | 250 | 8800 | 200000 |

The elapsed time per store is **U** (it depends on the XIO write latency; the code assumes about 1 per 20
units and names the unit nothing). The scoping datasheet's "microseconds by **I**" is withdrawn: the argument
is a store count in disguise.

## 3. GIF load (kind 1, record 0), through `0x120000` **E**

The GIF FPGA is configured by PIO to one register, `0x120000`. Each store below is a 32-bit `sw` of the
value shown; `wait(n)` is the helper of section 2, issued after the store. The order is the order the code
issues them (L 0x4169c0 to 0x416b8c; byte routine L 0x416ba0 to 0x416c78; stop L 0x416c80 to 0x416dfc).

Write layout, as used: bits 7:0 are a data byte, bit 8 is a clock, bit 9 is a strobe that is high in the
idle and active-data states. Read layout: bit 0 DONE, bit 1 INIT (the message calls it "INIT_L", active low:
the bit reads 1 when the pin is not asserted), bits 15:2 the pairs of section 1. **E** for the values and
tests; **I** for the names (section 9).

**Start** (kind 1 start routine):

| Step | Access | Value or test | Failure |
|---|---|---|---|
| 1 | store `0x120000`, `wait(300)` | `0x300` | |
| 2 | store `0x120000`, `wait(400)` | `0x100` | |
| 3 | store `0x120000` | `0x300` (no wait) | |
| 4 | load `0x120000` | bit 0 (DONE) must be **0** | "gif_start_programming: DONE set at start", -1 |
| 5 | `wait(176000)` | 8800 stores to `0x6c` | |
| 6 | up to 1000 times: load `0x120000`; if bit 1 (INIT) is **1** stop polling; else `wait(4000)` and retry | INIT must read 1 within 1000 reads | "gif_start_programming: INIT timed out", -1 |
| 7 | `wait(5000)` | | |
| 8 | store `0x200`, `wait(20)`, store `0x300`, `wait(20)` | one clock pair with data byte 0 | |

**Each byte `b`** (byte routine, no reads, returns 0): eight times in a row: store `b | 0x200`, `wait(20)`,
store `b | 0x300`, `wait(20)`. So each image byte is written **eight times**, unshifted, as eight clock
pulses (bit 8 low then high, with bit 9 high throughout), and the low byte holds the same eight bits every
time. The routine has no shift or mask of `b` beyond `& 0xff`.

**Stop** (after the last byte):

| Step | Access | Value or test | Failure |
|---|---|---|---|
| 1 | load `0x120000` | bit 1 (INIT) must still be **1** | "gif_stop_programming: INIT_L is active", -1 |
| 2 | ten times: store `0x200`, `wait(20)`, store `0x300`, `wait(20)` | ten more clock pairs, data byte 0 | |
| 3 | up to 10 times: `wait(120)`, then load `0x120000`; stop when bit 0 (DONE) is **1** | DONE must read 1 within 10 reads | "gif_stop_programming: DONE timed out", -1 |

Totals for the shipped `gif_1.xla.mcs` (179233 bytes): 3 stores in the reset steps, 2 in the start clock
pair, 8 x 2 x 179233 = 2,867,728 data stores and 20 in the stop pairs, all to `0x120000`, and about as many
`wait(20)` stores to `0x6c` (one per clock-pair half). The clock pairs in total number 1 + 8 x 179233 + 10 =
1,433,875, against the 24-bit length count inside the image of 1,433,857 (section 7). That 18-pulse margin is
**E** as arithmetic and is the reason for the **I** reading in section 9.

**The check argument is ignored for the GIF.** Kind 1 always runs all of the steps above, including the DONE
test at step 4 after the pulse of steps 1 to 3, so a GIF reload with DONE already set works only because
step 2 clears DONE.

## 4. The other seven FPGAs, through the GIF (kinds 0 and 2) **E**

These require the GIF to be configured. Control goes to `0x80000c`; data goes to the per-FPGA ports of
section 1. `sel` is the record's select word (+12), `off` its port offset (+16), `D` its DONE mask (+20),
`I` its INIT mask (+24), `G` the word read from `0x120000`. Start routine L 0x416e00 to 0x417068, byte routine
L 0x417070 to 0x4171cc, stop routine L 0x4171d0 to 0x41730c.

**Start:**

| Step | Access | Value or test | Failure |
|---|---|---|---|
| 1 | only if `check`: load `0x120000` | bit 0 must be **1** (GIF DONE) | "others_start_programming: gif not loaded yet", -1 |
| 2 | store `0x80000c`, `wait(300)` | `sel \| 0x80` | |
| 3 | store `0x80000c`, `wait(400)` | `sel` (bit 7 clear) | |
| 4 | store `0x80000c` | `sel \| 0x80` (no wait) | |
| 5 | only if `check`: load `0x120000` | `G & D` must **not** equal `D` (DONE must be 0 after the pulse) | "others_start_programming: DONE set at start", -1 |
| 6 | `wait(176000)` | | |
| 7 | with `check`: up to 1000 times: load `0x120000`; stop when `G & I == I`; else `wait(4000)` and retry. Without `check`: one `wait(4000000)` and no read | INIT must read 1 within 1000 reads | "others_start_programming: %s INIT timed out" (name), -1 |
| 8 | `wait(5000)` | | |

**Each byte `b`, index `i`** (called with `is_last = (i == size - 1)`):

| Step | Access | Value or test | Failure |
|---|---|---|---|
| 1 | only if `check` and `is_last`: load `0x120000` | `G & I` must be non-zero | "others_program_byte: INIT_L active!", -1 |
| 2 | kind 2: store `b` (word) to `0x800004 \| off`, return 0 (no further access) | | |
| 3 | kinds 0: up to 10 times: load `0x800004 \| off`; stop when bit 7 (`0x80`) is **1** (no wait between reads) | READY must read 1 within 10 reads | "others_program_byte: %s READY timed out" (name), -1 |
| 4 | kind 0: store `b` (word) to `0x880004 \| off`, `wait(0)` (zero stores) | | |

So kinds 0 and 2 send each byte **once**, not eight times. Kind 0 is a READY-handshaked byte port. Kind 2
(OXCC, IXCC) is a blind store to the status-port address with no READY test.

**Stop:**

| Step | Access | Value or test | Failure |
|---|---|---|---|
| 1 | with `check`: up to 10 times: load `0x120000`; stop when `G & D == D`; else `wait(100)` and retry. Without `check`: one `wait(1000)` and no read | DONE must read 1 within 10 reads | "others_stop_programming: %s DONE timed out" (name), -1 |

- **E.** Without `check` (every reload from `xhdCommitPathControls`) the library reads nothing from
  `0x120000` during an "others" load, and the only read left is the per-byte READY poll of kind 0. Success
  is then a fixed wait of 176000 + 4000000 + 5000 units before the bytes, the READY polls, and 1000 units
  after. A reload also does not require DONE to be 0 or INIT to be 1.
- **E.** At `xhdInit` time all of `check`'s tests apply to the seven loads.
- **U.** What READY (bit 7 of a port) means electrically and how long it stays low after a byte. The library
  polls it at most 10 times with no delay.

## 5. What `libdigvid.so` reads back, in one table (decides a load worked) **E**

All reads are 32-bit loads from the mapped window. These are the only reads in the load path; nothing is
read from the GIF version word `0x800084`, and no other site in L touches `0x120000` as a window offset
(the other occurrences of the constant in L are message-type numbers).

| Register | Bits and expected value | When | Retries, spacing | Failure message |
|---|---|---|---|---|
| `0x120000` | bit 0 = 0 | GIF, after the 0x300, 0x100, 0x300 stores | once | "gif_start_programming: DONE set at start" |
| `0x120000` | bit 1 = 1 | GIF, after `wait(176000)` | 1000 reads, `wait(4000)` between | "gif_start_programming: INIT timed out" |
| `0x120000` | bit 1 = 1 | GIF, after the last byte | once | "gif_stop_programming: INIT_L is active" |
| `0x120000` | bit 0 = 1 | GIF, after the ten extra clock pairs | 10 reads, `wait(120)` before each | "gif_stop_programming: DONE timed out" |
| `0x120000` | bit 0 = 1 | each other FPGA, before programming, `check` only | once | "others_start_programming: gif not loaded yet" |
| `0x120000` | `D` bit = 0 | each other FPGA, after the select pulse, `check` only | once | "others_start_programming: DONE set at start" |
| `0x120000` | `I` bit = 1 | each other FPGA, after `wait(176000)`, `check` only | 1000 reads, `wait(4000)` between | "others_start_programming: %s INIT timed out" |
| `0x120000` | `I` bit = 1 | each other FPGA, before the last byte, `check` only | once | "others_program_byte: INIT_L active!" |
| `0x800004 \| off` | bit 7 = 1 | each byte of a kind 0 FPGA | 10 reads, no wait | "others_program_byte: %s READY timed out" |
| `0x120000` | `D` bit = 1 | each other FPGA, after the last byte, `check` only | 10 reads, `wait(100)` between | "others_stop_programming: %s DONE timed out" |

A load "worked", for the library, when all of the rows that apply returned the expected value. `xhdInit`
stops at the first failing load and returns -1 (no later FPGA is attempted, no retry, no fallback image).

## 6. The kernel's readback after the loads (K30) **E for the code, I for the trigger**

After all eight loads `xhdInit` issues the reset ioctl (`0x6864760b`) with the argument 3 once after the GIF
load and with the argument 4 once after the last load (L 0x4079d4 to 0x4079f8 and 0x407ebc to 0x407ee4;
failure messages "xthdInitHW: couldn't reset board" and "xthdInitHW: couldn't reset local bus"). In K30 the
handler for an argument without bit 1 (`andi 2`) calls `xtdigvid_init_gif(board, arg & 4 != 0)` (K30 text
0xe424 to 0xe428 and 0x10200 to 0x10218); an argument with bit 1 set branches elsewhere (K30 0xb208), which was
not read. `xtdigvid_init_gif` (K30 0x599c) calls `xtdigvid_verify_gif_loaded`
(K30 0x5974: load `0x120000`, DONE bit 0 must be 1, else the message "GIF FPGA not loaded") and then loads
`0x800084` and requires its upper 24 bits to equal `0x474946` ("GIF"), as the scoping datasheet records.
The same `verify_gif_loaded` body (load of `0x120000`, `andi 1`) exists in K27 and K35.

- **I.** That the library's argument-4 reset reaches this path. The ioctl-number-to-handler step goes
  through the jump table of `xtdigvid_ioctl` (K30 0xac88, 23240 bytes), which was not decoded; the match
  rests on the matching message strings and on `andi 2` and `andi 4` tests in the one block that calls
  `xtdigvid_init_gif`.
- **E.** The kernel also has its own byte-write ioctl, `0x6864760e` (K30 `xtdigvid_eval_ioctl` text
  0x10750 + 0x34 to 0x10818): eight rounds of three stores of `byte | 0x200` then three stores of
  `byte | 0x300` to `0x120000`, no reads. L contains no use of `0x6864760e` (no `ori` or `addiu` of that value in
  its text), so it is not on the library's load path. It does confirm independently that one byte is clocked
  by eight low-high pulses on `0x120000`.
- **E.** The kernel's word-write ioctl (`0x68647602`) range-checks the offset to below `0xc00000` and to a
  multiple of 4 (K30 0x1081c to 0x10868). `xhdWriteWord` and `xhdReadWord` use it (and `0x68647601` for the
  read); the library's own load routines do not.
- **E.** With the environment variable `_XTDIGVID_READBACK` set, `xhdWriteWord` reads each word back with
  `xhdReadWord` and prints "Readback mismatch at addr 0x%x, expected 0x%x, got 0x%x" on a difference (L 0x40d9e0
  to 0x40dad0). This is the one checked write the library has; it is not part of the FPGA load.

## 7. The `.mcs` files and their parser

The reader is `xilinx_load_intel` (L 0x417310), the record parser `read_intel_hex_line` (L 0x417530). **E**
for everything in this section unless marked.

**File format as parsed.** `fopen(path, "rb")` (failure prints "xilinx_load_intel: no FPGA file %s" and
returns 1). Then, per record: `fgets(line, 128)`; the line must start with `:`; `sscanf(line, ":%2x%4x%2x",
&count, &addr, &type)` must return 3 (else -2, "read_intel_hex_line failed: %d"). The record checksum is
verified: the sum of count, the two address bytes (as `addr + (addr >> 8)`, correct modulo 256), the type,
the data bytes and the final byte must be 0 modulo 256 (else -6). Record types:

- Type 2 (extended segment address): `sscanf(line + 9, "%4x", &seg)`; the base becomes `seg << 4`; no data.
  Return value 2 is not an error.
- Any other type than 2: the record's `count` bytes are parsed with `sscanf(p, "%2x")` two characters at a
  time and stored at `buffer[base + addr + k]`; the buffer is the `malloc(size)` of section 2 and there is
  no bounds check. The return value is the type, so 0 (data) continues the loop and 1 (end of file) ends it.
  Types 3, 4 and 5 are not decoded; they would be stored as data.

**Acceptance.** The reader sums the `count` of every record and stops when the sum exceeds the table size or
the end-of-file record (type 1) is read. It then requires (a) the last record type was 1, (b) the byte sum equals
the table's size exactly (else "xilinx_load_intel: bad FPGA file %s", return 1), and, **for kinds 0 and 1
only**, (c) a length-count check: the routine at L 0x417750 reads bytes 1 to 4 of the loaded buffer and
rebuilds a 24-bit number from them with each byte taken least-significant bit first (the high four bits of byte
1, all of bytes 2 and 3, the low four bits of byte 4); `|8 * size - that number|` must be below 9, else the
message "[xt-digvid] configLength=0x%08x max_size=%x" and then "bad FPGA file %s" with return 1. Kind 2 (OXCC,
IXCC) skips (c).

**Checked against the shipped files** (all 60 parsed with a script that reimplements the above):

- Every file passes the checksum and ends with a type 1 record, and every line ends in CR LF. Data records
  hold 16 bytes each, except one final short record: 1 byte in the GIF, 2 in the 104066-byte images, 4 in
  CLINK, none in OXCC and IXCC. The type 2 records number 3 (GIF), 2 (the 104066-byte
  images, CLINK has 1) and 5 (OXCC, IXCC). The summed byte count is exactly the table size for every file of
  each class (section 1), including the `diag_*`, `_2` and `_fast` variants.
- The length count equals 1433857 for `gif_1.xla.mcs` (8 x 179233 = 1433864), 832521 for every
  104066-byte image (832528) and 283417 for `clink.mcs` (283424): in each file `8 * size` is 7 above the count, so
  the check passes.
- The first bytes are `ff 84 7a 08 f8` for the GIF, `ff 04 d3 02 f9` for the 104066-byte images and
  `ff 04 a2 8c f9` for CLINK. The OXCC and IXCC files start `ff ff ff ff 55 99 aa 66`.

| File | bytes of text | sha256 (first 16 hex) | binary bytes |
|---|---|---|---|
| `gif_1.xla.mcs` | 504169 | `0d0d711aa352deba` | 179233 |
| `clink.mcs` | 99681 | `cba4090a07b29a99` | 35428 |
| `hdoc_hd.xla.mcs` | 292744 | `259da634a2c0c890` | 104066 |
| `hdoc_hd_fast.xla.mcs` | 292744 | `1466bba72bec1e69` | 104066 |
| `hdoc_sd.xla.mcs` and `hdoc_sd_fast.xla.mcs` | 292744 each | `1f88eeb5afed62ee` (identical) | 104066 |
| `vif_hd.xla.mcs` / `vif_sd.xla.mcs` | 292744 each | `7d0de46ab5322e5f` / `ddd31ddf310f60a6` | 104066 |
| `oxcc.mcs` / `ixcc.mcs` | 895193 each | `fb82307edce1298c` / `da093d895ce82d6f` | 318256 |
| `packer_444_8.xla.mcs` / `unpacker_444_8.xla.mcs` | 292744 each | `6f7a4d1cd2617fa4` / `d8ab00cd56971406` | 104066 |

- **E.** `hdoc_sd.xla.mcs` and `hdoc_sd_fast.xla.mcs` are byte-identical (same sha256 over the whole file).
  The four other HDOC files differ.
- **I.** Bytes are sent least-significant bit first. The library's own length-count rebuild takes bits
  least-significant first (E for that code). The CLINK-family header read that way is `0010` (byte 1, low
  nibble 4) then a 24-bit count then `1111` (byte 4, high nibble f), which matches the preamble layout I
  recall for the Xilinx XC4000 and Spartan families; the OXCC and IXCC sync bytes `55 99 aa 66` are the
  Virtex-family sync word `aa 99 55 66` with every byte bit-reversed. Neither Xilinx document was
  consulted for this page, so the families are **I**, and the part numbers are **U**.

## 8. File to FPGA mapping and the root override

**Path.** `sprintf(buf, "%s/usr/dmedia/ucode/xtdigvid/%s.mcs", root, name)` into a 1024-byte stack buffer
(L 0x416644 to 0x416674, format at L 0x41c2a0). `root` is `getenv("_XTDIGVID_MCS_ROOT")` (L 0x41c288) when that
returns non-NULL, and the empty string at L 0x420468 otherwise. An empty value of the variable counts as
set. The result with no variable is the absolute path `/usr/dmedia/ucode/xtdigvid/<name>.mcs`. There is no
trailing-slash handling and no check of the length.

**Which name goes to which number at `xhdInit`** (L 0x407954 to 0x407e6c). The name is the argument that,
plus the fixed `.mcs`, makes the file:

| Order | n | Role | Name passed | File | Selected by |
|---|---|---|---|---|---|
| 1 | 0 | GIF | `gif_1.xla` (L 0x4183d8) | `gif_1.xla.mcs` | fixed |
| 2 | 7 | CLINK | `clink` (L 0x4203b8) | `clink.mcs` | fixed |
| 3 | 5 | HDOC | `hdoc_hd%s.xla` | `hdoc_hd.xla.mcs` or `hdoc_hd_fast.xla.mcs` | board part, below |
| 4 | 3 | OXCC | `oxcc%s` with `%s` = empty | `oxcc.mcs` | fixed |
| 5 | 2 | UNPACKER | `unpacker_%s.xla` | `unpacker_444_8.xla.mcs` at init | packing table, below |
| 6 | 6 | VIF | `vif_hd.xla` | `vif_hd.xla.mcs` | fixed |
| 7 | 1 | PACKER | `packer_%s.xla` | `packer_444_8.xla.mcs` at init | packing table, below |
| 8 | 4 | IXCC | `ixcc%s` with `%s` = empty | `ixcc.mcs` | fixed |

**HDOC suffix (E for the code, I for the field names).** `xhdInit` reads the board's one-wire identity text
through ioctl `0x6864760f` (error text "ioctl XTDIGVID_IOCTL_GET_NIC failed") and parses the field named
`Part` (string at L 0x4203e8) in the form `030-1653-002`: the first number after the dash (decimal 1653) and
the last (decimal 2) with `strtol` (parser L 0x4085f0, field extractor L 0x408680). The suffix is empty,
giving `hdoc_hd.xla.mcs`, when the middle number is 1653 and the last is below 3. It is `_fast` (so
`hdoc_hd_fast.xla.mcs`) when the middle number is 1653 and the last is 3 or more, or when the middle number is
anything else (L 0x407af8 to 0x407b08, 0x407c4c to 0x407c5c). The commit path repeats the same test with the
value kept in the board record (`lh` at record offsets 1796 and 1798, L 0x40aa44 and 0x40afd0), choosing
`hdoc_sd%s.xla` or `hdoc_hd%s.xla` by the format's definition. **I** that these two fields are the part's
middle and last numbers: the dash positions are read from the code's offsets (+4, +9) only. Which numbers a
real board returns is **U** here; the scoping datasheet's two captures list `030-1653-002` (rev G and H).

**Packer and unpacker names.** `hdPackingTable` (L 0x41eab0, 240 bytes) holds 15 rows by 4 columns of
string pointers, row selected from `hdImagePackingEnums` (L 0x41e880, 15 values) and column from
`hdImageSamplingEnums` (L 0x41ea20: `0x4220`, `0x4224`, `0x4440`, `0x4444`). `xhdInit` searches for packing
`0x1001b108` (row 0) and sampling `0x4440` (column 2) and so loads the entry `444_8`. The path-commit code
builds the name the same way (L 0x40a3d4 and 0x40a7e4, same table and format strings) from the format's
values. The table, rows by packing value, with `-` for an empty (null) cell:

| Packing value | 4220 | 4224 | 4440 | 4444 |
|---|---|---|---|---|
| `0x1001b108` | `422_8` | - | `444_8` | `4444_8` |
| `0x100e4108` | - | - | `444_8_r` | `4444_8_r` |
| `0x10093108` | `422_8_3214` | - | - | - |
| `0x1001b10a` | `422_10` | - | - | - |
| `0x1009310a` | `422_10_3214` | - | - | - |
| `0x2111b10a` | `422_10in16l` | - | `444_10in16l` | - |
| `0x2119310a` | `422_10in16l_3214` | - | - | - |
| `0x2121b10a` | `422_10in16r` | - | `444_10in16r` | - |
| `0x2129310a` | `422_10in16r_3214` | - | - | - |
| `0x2111b20c` | - | - | `444_12in16l` | - |
| `0x2121b20c` | - | - | `444_12in16r` | - |
| `0x4001b001` | - | `4224_10_10_10_2` | `4444_10_10_10_2` | `4444_10_10_10_2` |
| `0x400e4001` | - | - | `4444_10_10_10_2_r` | `4444_10_10_10_2_r` |
| `0x40093001` | - | `4224_10_10_10_2_3214` | - | - |
| `0x1001b20c` | - | - | - | `4444_12` |

Every one of the 21 distinct names has a `packer_<name>.xla.mcs` and an `unpacker_<name>.xla.mcs` among the
shipped files (21 plus 21 files). **E.**

**Files no string in `libdigvid.so` names.** `diag_hdoc.xla.mcs`, `diag_ixcc.mcs`, `diag_oxcc.mcs`,
`diag_packer.xla.mcs`, `diag_unpacker.xla.mcs`, `diag_vif.xla.mcs`, `ixcc_2.mcs` and `oxcc_2.mcs` (E: no
matching string in L's `.rodata` or `.srdata`). Their size classes match the table, so they would load
through the same path under another caller. Who selects them is **U**; the diagnostic programs of the same
install set are the candidates and were not read here.

**Order and state across a boot.** The sequence at `xhdInit` is: GIF, reset ioctl (argument 3), the seven
others in the order above, reset ioctl (argument 4), then the library's `xhdSendPIO` and `xhdWriteWord`
calls that reset the CLINK FPGA (the word `0x38e0` stored 1 then 0, failure text "Failed to reset clink"). **E**
for the order; the later setup is outside this page.

## 9. Unknowns and what settles each

| Unknown | Grade | What settles it |
|---|---|---|
| Why the GIF byte is written eight times | I | The library never shifts the byte, so the receiver cannot be taking one bit per pulse from the same data lines unless a counter picks bit k on pulse k. The arithmetic supports one bit per pulse: 1,433,875 pulses against a 1,433,857-bit count, and the least-significant-bit-first order of section 7. The kernel's own byte ioctl also clocks eight pulses. Settled by the GIF's configuration-port logic, which is in no shipped software |
| Which bits of the `0x120000` write are data, clock and strobe, and what bit 7 of `0x80000c` and the select bits do | I | The names above come from the pulse shapes. A schematic or a measured capture of the write path would settle it; no software reads the registers back except as section 5 lists |
| Real time per `0x6c` store, and so the real wait lengths | U | Needs the Crosstalk write latency of the board; software evidence gives only the store counts. The code needs no minimum time unless the hardware gives INIT late: the INIT poll allows 1000 reads after 8800 stores |
| FPGA parts and families | I | Header structure of the images (section 7). The public Xilinx configuration documents, read after, would settle the family; the part number needs the owner's guide or the board |
| READY bit meaning (bit 7 of the 0x800004-offset ports) and whether OXCC and IXCC (kind 2) ever report it | U | Library code never reads it for kind 2. Settled by the receiving logic or a capture |
| Whether the reset ioctl argument 4 is the call that reaches `xtdigvid_init_gif` | I | Decode the jump table of `xtdigvid_ioctl` (K30 0xac88) and match `0x6864760b` to its arm |
| `diag_*`, `ixcc_2`, `oxcc_2` consumers | U | Read the diagnostic programs of the same install set (`usr/diags/ml_xtdigvid/bin`) |
| Whether `hdoc_hd_fast` or `hdoc_hd` goes with a real board's part number | I | A board capture of the `Part` field; the scoping datasheet's captures list only `030-1653-002` |
| Behaviour of a failed load on the board (what the board does if INIT never comes) | U | Library prints and returns -1; nothing reads the board afterward. Needs a capture |

## 10. Corrections to the scoping datasheet, section 6

Found while reading the routines in full; the scoping datasheet itself is not edited here.

- It says the GIF programming finishes with "ten more clock pairs and poll DONE for up to ten tries, 20 units
  apart". The spacing is 120 units, and the wait comes before each read (section 3).
- It says the GIF byte is written to "bits 7:0 with bit 9 then bits 9:8 set ... eight times per byte". That is
  right; the stores are `b|0x200` then `b|0x300`, and the start of the load also sends one clock pair with
  data 0 (section 3).
- It says the other seven FPGAs "write the control word at `0x80000c` with bit 7 set (and cleared), wait, poll
  `0x800004` for the value `0x80`, and send bytes to `0x880004`". The control word is written three times
  (set, clear, set), the polls are of the GIF's `0x120000` bits, the per-byte READY poll is at
  `0x800004 | off`, and the data port is `0x880004 | off`, with a different port per FPGA. OXCC and IXCC send
  their bytes to `0x800004 | off` without a READY poll (section 4).
- It says the `xthd_fpga_info` records hold "a pointer to the name, a kind 0, 1 or 2, a byte count, and mask
  words" and that the table's contents were not dumped. The contents are in section 1: four more words
  (select, port offset, DONE mask, INIT mask).
- Its section 9 row for `xthd_fpga_info` is settled by section 1 of this page.
- It says delays are "in the unit of the library's delay helper, microseconds by **I**". The helper stores
  to the error-cause register; see section 2.
