# SHub 1: memory bring-up and the memory-test engine, as SAL 5.04 drives them

What the SHub 1 firmware (`shub1snprom.bin`, SAL 5.04, snprom 10.54 build 70399, sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`, base `0xffa00000`) writes to the memory and directory (MD) block of one SHub to bring up a single node with one 2 GiB bank (four identical DIMMs in bank 0, nothing else), and what each register has to return for the firmware to get through "Testing memory" and "Initializing memory" and on to the jump to RAM. Written so that a device model can be built from this page and the generated header ([registers.md](registers.md)) alone.

Sites are SAL_B addresses, read with `ia64-linux-gnu-objdump`; no PROM bytes or listings are kept here. Register offsets are SHub 1 node offsets (`0x1_xxxx_xxxx`); the PROM reaches them as `0x8_0000_0000 + (nasid << 38) + offset` (global window, bit 63 set for uncached physical access). "Linux name" means a constant in Linux v5.3 `arch/ia64/include/asm/sn/shub_mmr.h`: that header (all 502 lines were searched for every offset below) names none of the registers on this page. The only MD names it has are `SH1_MD_DQLP_MMR_DIR_PRIVEC0` (`0x1_0003_0300`) and `SH1_MD_DQRP_MMR_DIR_PRIVEC0` (`0x1_0005_0300`), which are in [registers.toml](registers.toml) already. No SHub specification is public, so every register name below is ours and no reset value is established anywhere.

**Grades** follow [AGENTS.md](../../AGENTS.md). *Established*: the instructions at the site were read in full and the statement follows from them; it says what the code does, not what the hardware means. *Inferred*: reasoned from part of a function, from a value's use, or from a name; the reasoning is given. *Unknown*: not settled. The register and engine facts below that rest on a code path I followed to the end are marked established; the hardware meaning of any field is inferred at best, because nothing public defines it.

Companions: [node-bringup.md](../../software/firmware/snprom/node-bringup.md) (the earlier, reviewed single-node reading) and its review, [prom-reset.md](prom-reset.md), [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md). Where this page differs from them, [Differences from the earlier pages](#differences-from-the-earlier-pages) says so.

## What runs, in order, on a 2 GiB node

All of this is `main()`; the order is the order of the call sites (established).

1. `0xffa78100` runs the three set-up steps, in this order: DIMM discovery (`0xffa77bb0`, via the L1), controller programming (`0xffa76bf0`) and the DRAM initialisation commands (`0xffa775c0`, eight engine runs).
2. `0xffa6f000` is "Testing memory". Before it looks at the test mode it calls the credit routine `0xffa7af50` (see [`md_reg_0001_0068`](#the-credit-word-0x1_0001_0068)), so that routine runs even when the test is skipped. Then, for each bank that is present, it runs the per-bank test `0xffa6de80`.
3. `main()` then tests bit 8 of the L1 debug-switch word (`0xffa975e0`, the word at `0x1_5003_1560`). **Clear**: `0xffa7c6d0` runs first and, for every bank whose flag bit 0 is clear, rewrites the three bank configuration words with that bank's density field set to 7 (`0xffae7a80`; for the 2 GiB node that re-stores the same word for banks 1 to 3, which already hold 7). **Set**: `0xffa7c6d0` is skipped. Either way `main()` goes on to `0xffa788b0`, which sums the bank sizes (reads `0x1_0001_0010`; a total of zero prints a warning and freezes the node), and then to `0xffa782c0`, "Initializing memory". For each bank whose density index is not 7 and whose flag bit 0 is set (or any such bank when bit 8 is set) it zero-fills the whole bank with the engine (the per-bank routine in mode 1), then it runs the credit routine again (argument 2), then sets bit 3 of `0x1_0003_0000` and `0x1_0005_0000`. Bit 8 changes which banks are touched, not whether the step runs.
4. Presence and privilege vectors, the jump to RAM, and the directory writes that go with it come after this page's scope; the directory-write contract is in [the directory-access words](#the-directory-access-words-0x1_0003_1000-and-0x1_0005_1000).

**The test mode (established).** `0xffa6f000` takes a mode whose low four bits select the test: 1 skips the memory test ("Skipping memory test, as requested"), 0 and 2 and 3 run it with 3, 4 and 5 data patterns (see the engine section) and 3 also prints per-bank progress. `main()` calls `0xffa17b90` once, at `0xffa19f4c`, with the result of a stub (`0xffb91cb0`, which returns 0), so the test of its argument for the stand-in processor id never matches. The mode is then bits 1:0 of the switch word, plus 16 when bit 2 is set; both consumers (`0xffa6f000` and `0xffa6de80`) mask it with 15, so bit 2 has no effect. The reviewed L1 notes say a blank L1 answers request `0x0001` with 0, so the word is 0, the mode is 0 and bit 8 is clear: the full three-pattern test runs, `0xffa7c6d0` runs, and "Initializing memory" runs. The word's other bits do not reach the memory routines read for this page (bit 8 is the only other bit they test). A word with bit 0 set and bit 1 clear (for example the console default `0x0405` the PROM offers when the L1 cannot answer) selects mode 1.

## The registers, one by one

Every register is 64 bits wide. "Written" means the value as the PROM stores it; a layout listed as fields is the PROM's deposit positions (established), whose hardware meaning is inferred from names and use.

### md_clk_sel, `0x1_1006_0500`

Read only, at `0xffa77e0c` (inside `0xffa77bb0`). Bits 1:0 index a four-entry table of 16-bit words in flash: 0 gives 200 MHz, 1 gives 160, 2 gives 133, 3 gives 100 (established, table read). Nothing else is used. **Must return** any value whose bits 1:0 give a bus clock and CAS-latency pair the PROM supports for the DIMMs' SPD data (200 MHz with CL 2.0, 2.5 or 3.0; 160 MHz likewise; 133 MHz with CL 2.0 or 2.5; 100 MHz with CL 2.0); other pairs print "memory bus speed ... not supported" and carry on with unusable timing values. Zero is the simplest choice. Reset value: unknown. Linux name: none.

### Bank configuration: `0x1_0001_0000`, `_0008`, `_0010`

Written with one identical word by `0xffa76bf0` (stores at `0xffa7701c`, `0xffa7704c`, `0xffa7707c`); `0x1_0001_0008` is read first (`0xffa76c3c`) and the word is merged into that read, so bits the PROM does not deposit keep their previous value. The deposits (established, `0xffa76dxx` to `0xffa77006`):

| Bits | Source | Meaning (inferred) |
|---|---|---|
| 35:32 | timing index (0 to 8) from the bus clock and CAS pair | which of the nine timing-table rows is in use |
| 2:0, 10:8, 18:16, 26:24 | density index of bank 0, 1, 2, 3 | 7 means empty; 3 is 512 Mbit-per-rank parts, i.e. 2 GiB for four single-rank DIMMs |
| 3, 11, 19, 27 | rank code of bank 0..3 | 0 for single-rank, 1 for dual-rank DIMMs |
| 6:5, 14:13, 22:21, 30:29 | a 2-bit field per bank, equal to the bank number in the traced run | unknown role |

Bank size in bytes is `0x400_0000 << (density + rank code) << 2` (established, `0xffa6de80`); density 3 and rank code 0 give 2 GiB. For the 2 GiB node the low byte is `0x03` (density 3, rank 0, field 0) and the other three bytes are `0x27`, `0x47`, `0x67` (density 7, field 1, 2, 3), so the word is `timing_index << 32 | 0x6747_2703`.

**Must return.** The words must read back what the PROM wrote: the memory test reads `0x1_0001_0008` (`0xffa6dedc`, `0xffa6cebc`, `0xffa7ab9c`) and `0x1_0001_0010` (`0xffa6f2fc`, `0xffa7838c`, `0xffa7890c`) to find which banks exist and how big they are. `0x1_0001_0000` is never read in the traced path. Before the first write any value is accepted (the merge keeps stale bits, which then reach all three registers). Linux name: none. Grade: positions and read-back requirement established; field meaning inferred; reset unknown.

### Timing words: `0x1_0001_0020`, `_0028`, `_0040`, `_0048`

Written by `0xffa76bf0` from a 32-byte row of a table in flash (row = timing index; table at `0xffbe0650`). `0x1_0001_0040` and `0x1_0001_0048` are read first and merged (`0xffa76c6c`, `0xffa76c9c`); `_0020` and `_0028` are write-only.

- `0x1_0001_0020` and `_0040` carry one word `T`: the old value's bits 63:52 and 1:0 are kept; bits 39:8 get the low 32 bits of the row's first doubleword; bit 1 is set and bits 7:2 are cleared (so the low byte is `0x02` or `0x03`, bit 0 keeping its old value); bits 43:40, 47:44, 51:48 get the 16-bit values at row offsets 8, 10, 12; bit 52 is always set, and bit 53 is also set when the value at offset 8 of the DIMM record is 2, bit 54 when it is 4 (established; the record value is read as the tRCD in clocks, which is inferred). It is a different word from the one in `_0028`/`_0048`.
- `0x1_0001_0028` and `_0048` carry one word `U`: bits 3:0, 7:4, 11:8, 15:12, 19:16, 23:20 get the 16-bit values at row offsets 14, 16, 18, 20, 22, 24; bits 63:24 are the old value of `_0048` (established).

**Must return.** `_0040` and `_0048` any value before the first write (they are merged); after it, what was written (the merge reads happen before the writes, so a read-back is not needed in the traced path, but keep storage). `_0020` and `_0028` are never read. Linux names: none. Reset: unknown.

### Refresh words: `0x1_0001_0030` and `_0050`

One word `R` is written to both, once, after the eight DRAM initialisation commands (`0xffa77adc`, `0xffa77b0c`). It starts as a read of `0x1_0001_0050` (`0xffa7761c`), then (established, `0xffa775c0` to `0xffa77aac`): bits 16:8 = 195 (or the number in the flash variable `MemoryRefresh`); bit 23 cleared; bits 22:17 = tRFC in clocks (SPD byte 42 divided by 5, at least 14); bits 7:0 get bit `cs` set for each chip select that exists (`cs = 2 * bank + rank`, so bit 0 for the 2 GiB node); bits 27:24 get bit `bank` set for each bank whose density index is 1 or less (not for the 2 GiB node). Meanings: refresh interval, tRFC and chip-select enables are inferred from the values; bits 27:24 are unknown.

**Must return** the stored value for `_0050` (it is read once before the write); any value before the first write. `_0030` is never read. Linux names: none. Reset: unknown.

### Constants and one control word: `0x1_0001_0058`, `_0060`, `_0078`

Plain writes at the end of `0xffa76bf0` (`0xffa7745c`, `0xffa773cc`, `0xffa7748c`), never read: `_0058` = `0x04004e20`; `_0060` = `0x4047` if bits 31:28 of `0x1_1006_0580` (read at `0xffa7738c`) are above 2, else `0x4045`; `_0078` = `0x24` (all established). Roles unknown. **Must return** nothing (never read). Linux names: none.

### The credit word, `0x1_0001_0068`

Read and conditionally written by the credit routine `0xffa7a960` (entry through `0xffa7af50` with argument 4, called from "Testing memory"; through `0xffa7af90` with argument 2, called from "Initializing memory"). It returns at once if `cpuid[2]` equals `0xaeeeeeee8badbeef` (the stand-in processor id), or if no bank is flagged present (the flag is bit 0 of the halfword at offset 4 + 8 * bank of the bank records; `0xffa77bb0` sets 1 for a bank with all four DIMMs and 2 otherwise, established from the stores). With a bank flagged (the first one found) it reads `0x1_0001_0068` (`0xffa7ab6c`), takes the 32-bit signed value `v`, and compares it with the argument `a`:

| Condition | What the PROM does |
|---|---|
| `v == a` | nothing |
| `v < a` | runs the engine (operation 48, pattern zero, 20,000,000 us deadline, result ignored) over the last 1/32 of the bank: start = bank base + size - size/32, 8-byte count = size/256; then writes `a` to `0x1_0001_0068`; then zero-fills through the block-transfer engine: writes IBLS0 at `0x8_01c1_0000 + (nasid << 38)` with `0x100000 + 2 * (a - v)` (bit 20 busy, low bits the length), the same bank-base address to IBLS0 `+0x08`, `+0x10`, `+0x20`, `17` to `+0x18`, and polls bit 20 of IBLS0 until it reads 0 (deadline 2,000,000 us; on a timeout it prints a message and returns, without issuing the transfer again) |
| `v > a` | writes `a` to `0x1_0001_0068`; runs the engine (operation 48, zero) over `(v - a) * 32` 8-byte words at the bank base |

(All established; read in full at `0xffa7a960` to `0xffa7af40`.) With a reset value of 0 the first call (argument 4) takes the `v < a` path, with a BTE length of 8 (`0x100008`, as in the earlier traced run). The second call (argument 2, from "Initializing memory", which always runs) then finds 4 and takes the `v > a` path, zero-filling 64 words at the bank base. With a reset value of 4 the first call does nothing. **Must return** what was written (the value after the first call must be 4, or the second call's branch changes); the register's role is unknown (it keeps a credit-like count for the block-transfer zero fill, inferred from the comparison, unverified). IBLS0 must read bit 20 as 0 after the write ([shub_ii](../shub_ii/README.md)). Linux name: none. Reset: unknown.

### MD size and enable words: `0x1_0003_0000` and `0x1_0005_0000`

Read and written in "Initializing memory" (`0xffa785cc`, `0xffa785ec`, `0xffa7861c`): the PROM reads `0x1_0003_0000`, sets bit 3, and writes the result to both `0x1_0003_0000` and `0x1_0005_0000` (established, `0xffa782c0`; local node only). A second routine (`0xffa733d0`, called from `0xffa6a1bc` in slot 97; traced in the last section) writes bits 2:0 of both with a size class from 0 to 4 (0 for a count of up to 127); another (`0xffa78f70`) reads bits 2:0 plus one as a shift. Whether the table path runs on a single node was not traced (unknown). **Must return** the stored value; the model must accept the read-modify-write. The 2.4 header names this register `SH_MD_DQLP_MMR_DIR_CONFIG` (mask `0x1f`, INIT `0x10`): bits 2:0 `SYS_SIZE` (system size code), bit 3 `EN_DIRECC` (enable directory ECC correction), bit 4 `EN_DIRPOIS` (local poisoning for directory fall-through); the right port's twin is `SH_MD_DQRP_MMR_DIR_CONFIG` (names from the header, established; added in review). The earlier "memory initialised" reading of bit 3 is withdrawn. Linux names: none.

### Words written with ones and a constant: `0x1_0003_0200` to `_0270`, `0x1_0005_0200` to `_0270`, `0x1_0003_0400`, `0x1_0005_0400`

`0xffa76bf0` stores all ones to eight words at stride 0x10 in each of the `0x3` and `0x5` blocks (`0xffa7729c`, `0xffa7732c`), and `0x1000` to `0x1_0003_0400` and `0x1_0005_0400` (`0xffa773fc`, `0xffa7742c`). None is read. **Must return** nothing; accept the stores. The earlier pages also list stores to `0x1_0183_0200` and `0x1_0185_0200`; this reading finds the arm that would form those addresses unreachable (the test that selects it is on bit 32 of an address that always has it set), so no store to them is claimed (established for the instruction sequence). Roles unknown.

### The memory-test engine registers

`0x1_0002_0080` (word), `0x1_0002_0088` (control), `0x1_0000_0080` (status; bit 36 is the failure bit the test reads), `0x1_0000_00b8` (error word read in the failure report) and `0x1_0000_00c0` (written all ones at each start). Layouts, the start sequence and the poll are in [the engine contract](#the-engine-contract). Summary of what each must return on a passing run:

| Register | Read by | Must return |
|---|---|---|
| `0x1_0002_0088` | the poll `0xffa6fc60` and the failure checks | after a start write, bits 41:40 not equal to `01` within the deadline; bit 41 reads 0 |
| `0x1_0000_0080` bit 36 | `0xffa702c0` after every operation-16 poll | 0. The PROM writes 0 to this register before each start, so plain storage gives it |
| `0x1_0002_0080`, `0x1_0000_00c0` | never in the passing path | plain storage |
| `0x1_0000_00b8` | `0xffa725f6`, only in the failure report and only when bit 36 is found clear | not read on a passing run |

### The directory-access words, `0x1_0003_1000` and `0x1_0005_1000`

`memctl_write_dir_access` (`0xffa6b060`, name from its error string) stores `value << 55` to `0x1_0003_1000` (`0xffa6b10c`) and then to `0x1_0005_1000` (`0xffa6b14c`), both in the global window of the node whose number is bits 48:38 of the address argument, and then runs engine operation 64 with a count (below). Never read. **Must return** nothing; the engine run must complete as for any other operation. The field is the top nine bits, 63:55 (the shift gives the width as inferred, since the values seen are 6 and 7); what the stored value means to the directory is unknown. The function does not check bit 36 of `0x1_0000_0080`; it fails on a timeout (-3) or on bit 41 of `0x1_0002_0088`. Its wrapper `0xffa7a690` rounds the range to 512-byte units and passes the count in 8-byte words. Callers: `0xffa73aec` (value 7, address 0, length 65535, so 8192 words), `0xfface79c` in the PROM-to-RAM copy (value 6, 6 MiB, so 0xc0000 words) and `0xffb1ac1c`; the first two are after the point where the PROM jumps to RAM and are outside this page. No separate directory-ECC register is touched (established for this function). Linux names: none.

### Pattern registers for the test data

Before every operation 48 or 16 run the PROM programs 16 words (`0xffa703d0`, established): two patterns `A` and `B`, stored as `A, B, A, B` at offsets `0x8000`, `0x8010`, `0x8800`, `0x8810` of each of the four blocks `0x3`, `0x4`, `0x5`, `0x6` (`0x1_0003_8000`, `0x1_0003_8010`, `0x1_0003_8800`, `0x1_0003_8810`, then the same in `0x1_0004_xxxx`, `0x1_0005_xxxx`, `0x1_0006_xxxx`). With the 40-bit pattern `p` from the command structure (bits 39:0 of the 64-bit pattern) and `f` the "other flag" byte at structure offset 76, `A = p | 1 << 42 | f << 40` and `B = p | f << 40` when the pattern's invert byte is 0, `B = (~p & 0xff_ffff_ffff) | f << 40` when it is 1. Not read on a passing path (the compare-error diagnosis `0xffa708e0` reads these words and the ones at `+0x20` and `+0x30` of each, so a model that captures compare data would put it there). **Must return** nothing on a passing run; accept 64-bit stores at these 16 offsets. Roles of bit 42 and of the 40-bit width are unknown.

## The engine contract

One engine does all of: DRAM initialisation commands, the memory test patterns, zero fill, and the directory write. Nothing here is readable from a specification; the completion logic is read from the code, the hardware semantics are inferred.

### Start (established, `0xffa6fb30`)

In this order, all 64-bit stores into the node's window:

1. `0x1_0002_0080` = the command word (a byte address for the memory operations, a DRAM command word for the initialisation sequence).
2. `0x1_0000_0080` = 0.
3. `0x1_0000_00c0` = all ones.
4. `0x1_0002_0088` = `1 << 40 | (op & 0x7f) << 32 | (value & 0x7fff_ffff)`. Bit 40 is "go".

The command word and the value come from a small command structure the callers build (node number at +0, word at +8, 32-bit value at +16, pattern at +24, mode at +32, flags). `0xffa70310` is the dispatcher: operation 16 goes to the compare wrapper `0xffa700d0`; everything else is `start` then `poll` with the caller's deadline (every caller passes 20,000,000 explicitly; the poll also uses that value for a deadline of 0).

### Poll (established, read in full, `0xffa6fc60`)

Time is in microseconds. `0xffa0da70` reads the real-time clock at `0x1_101c_0000` and `0xffa0da00` the period from bits 13:4 of `0x1_1006_0280` (`rtc_ctl`): the period in nanoseconds is `10 * field + 10`, the count is multiplied by it and divided by 1000. So the 20,000,000 deadline is 20 seconds of clock time at the clock's real rate, and the clock has to advance or every wait lasts the full count. (Under the processor-id stand-in the count is also shifted left by 7.)

1. Save the per-slice word at `0x1_1003_0000 + 0x80 * slice` (any value) and write progress code 88 through the progress routine `0xffa0ddb0` (a shift-in of the code into `0x1_5003_1500 + 16 * slice` plus LED writes); the saved word's low byte is written back through the same routine at exit.
2. Loop: read `0x1_0002_0088`, keep bits 41:40. Leave the loop when they are **not** `01`. `01` means busy (go set, no failure). Bits 38:0 are never examined.
3. Read the register again. If bit 40 is clear, return 0. If bit 40 is still set (so bits are `11`), store the value just read back with bit 40 cleared, and poll until bit 40 reads 0, with a fresh deadline of the same length.
4. A deadline expiry in either loop returns -3 (the caller prints "MBIST TIMEOUT" with the address from bits 32:0 of `0x1_0000_0080` times 8, and names the suspect DIMMs).

So: `00` is done and passed; `10` is done and failed (poll returns 0, the caller sees bit 41); `11` is failed with go still set (the model must accept the PROM clearing bit 40 by a write); `01` is busy.

### Result checks after the poll (established)

- Operation 48 and operations 7, 2, 1, 0 for DRAM initialisation, the credit fills: the callers test only for -3 and bit 41 of `0x1_0002_0088`. The DRAM initialisation runs and the credit-routine fills ignore the result.
- Operation 16 (compare), inside `0xffa700d0`, after each of four passes: bit 41 of `0x1_0002_0088` set means fail (-2); then bit 36 of `0x1_0000_0080` set means fail (-2). The pattern loop that calls the wrapper (`0xffa6c3a0`) only treats -3 and bit 41 as errors, so a bit-36-only failure is passed over there (it would be cleared by the next start writing 0 to `0x1_0000_0080`).
- Operation 64, the directory write: -3 or bit 41.
- Failure report (`0xffa72500`): reads `0x1_0000_0080`; for a timeout it prints the byte address from bits 32:0 and returns -3. Otherwise it reads the register again: with bit 36 **clear** it reads `0x1_0000_00b8`, prints "MBIST failed other than bist compare error" and returns -2; with bit 36 **set** it calls a diagnosis routine (`0xffa708e0`) that reads back the data words at offsets `0x8000` to `0x8030` and `0x8800` to `0x8830` of the blocks `0x3` to `0x6` and runs further engine operations (`0xffa727e0`, `0xffa72ad0`, which read bit 36 again at `0xffa72d96` and `0xffa730cc`). The failing byte address is derived from bits 32:0 of `0x1_0000_0080`. None of this runs on a passing path.

### Operations the PROM uses

| Op | Users | Command word at `0x1_0002_0080` | Value (30:0) |
|---|---|---|---|
| 7, 2, 0, 0, 2, 1, 1, 0 | `0xffa775c0`, DRAM initialisation, per chip select, eight runs per present chip select, results ignored | a command word built by `0xffa77550` from the bank's 2-bit field (bits 35:34), the rank (bit 12), a 14-bit mode value split over bits 11:10, 23:13 and 26, and bit 8 for one run; bit 21 is added for the five runs with operations 7, 2, 2, 1, 1 (established); the earlier trace recorded `0x200000`, `0x200000`, `0x100`, `0x9c800`, `0x200000`, `0x200000`, `0x200000`, `0x1c800` | 0 |
| 48 (`0x30`) | pattern pass (write), zero fill, init-memory fill, credit fill | start byte address within the node: `bank << 34` for a whole bank, so 0 for bank 0 | count of 8-byte words, bank size / 8 (`0x1000_0000` for 2 GiB) |
| 16 (`0x10`) | pattern pass (compare), four passes per pattern | start + 32 * k for pass k = 0..3 | as op 48 |
| 64 (`0x40`) | directory write | the address as passed (global, node in bits 48:38) | count of 8-byte words |
| 80 (`0x50`) | directory entry read, `0xffae7dd0` (callers: the 16384-entry loop `0xffa77b40`, and the permission query `0xffa7a800`) | the byte address, node in bits 48:38 | 0 |

The DRAM-initialisation meaning of ops 7, 2, 1, 0 (precharge-all, refresh, mode-register sets) is inferred from the order and the word fields; the memory-test meaning of 48 (write the pattern over the range) and 16 (read and compare) is inferred from the pass structure and from bit 36 being read after 16 only. Op 80 is reached on a single node: see [Operation 80](#operation-80-directory-entry-read-after-the-sal-shadow).

### Operation 80: directory entry read after the SAL shadow

Added from a trace of the first op 80 a one-node SHub 1 model issues, which comes after the SAL shadow copy. Read in Ghidra (IA-64 module, `--sn2-prom --no-analysis`) with objdump as a cross-check; no PROM bytes are kept here. This corrects the earlier statement that op 80 is only for remote nodes.

**Caller chain (established).** `main` `0xffa19a20` hands the continuation to the jump to RAM (`0xffac6bb0`), which runs the shadow function `0xffac7400` (progress 0x44, "Shadowing SAL to ...", `0xfface570` copies the 6 MiB image, calls `0xffaeb450` and `0xffaeb1f0` for the `0x1_2001_0180` and `0x1_2001_0100` writes, then the chip-object method below) and ends in `main_two` `0xffa1ade0`. After progress 0x1a, `main_two` calls `0xffa738d0` (call at `0xffa1af7c`). That function runs only when the slice gate `0xffa0ff30` returns 1 (the master slice of the node, so always on a one-node machine's first processor). It calls the loop `0xffa77b40(nasid)` (call at `0xffa739c6`, nasid from the node object's halfword at offset 0), which calls `0xffae7dd0(addr, 2)` 16384 times with `addr = (nasid << 38) + i * 0x400`, i = 0 to 0x3fff (0 to `0xfffc00` on NASID 0, the first 16 MiB of the node in 1 KiB steps; the call at `0xffa77b7c`). `0xffae7dd0` builds the command structure (node = bits 48:38 of the address, word = the address, value 0) and calls the dispatcher `0xffa70310` with operation 80 and the 20,000,000 deadline (call at `0xffae7e2c`), so `0xffa6fb30` and the poll `0xffa6fc60` are the ones above. `0xffa77b40` has a second caller: `0xffa782c0` (memory initialisation, from `main` and slot 97), only when the node being set up is not the node reading its own id from `0x1_1006_0580` (bits 42:32, `0xffa0dcf0`), and not with the stand-in processor id; that is the remote-node case and does not run on one node. The only other caller of `0xffae7dd0` is the permission query `0xffa7a800` (`memctl_query_mem_permissions`, from the SAL procedure `0x0200003e` at `0xffb1a8c0`), which is reached from the operating system, not from the boot path.

**Words written for the first call on NASID 0 (established).** `0x1_0002_0080` = the address argument (0 for i = 0, `i * 0x400` after); `0x1_0000_0080` = 0; `0x1_0000_00c0` = all ones; `0x1_0002_0088` = `0x15000000000` (go, operation `0x50`, value 0). The word is the address as passed, with the node number left in bits 48:38; no range, length or permission bits exist for this operation.

**What it does (established as code, inferred as hardware meaning).** It reads one directory entry; it does not write directory or protection state. After the poll `0xffae7dd0` reads `0x1_0002_0088` once more and returns -1 if bit 41 is set (a timeout, -3, also returns -1). Otherwise it reads one result register in the global window of the same node and extracts a field of it: bit 11 of the address picks the right queue port block (`0x1_0005_2xxx`) over the left one (`0x1_0003_2xxx`), and bit 7 picks `0x2000` over `0x2800`. The loop's addresses have bit 7 clear, so it reads `0x1_0003_2800` when bit 11 is clear and `0x1_0005_2800` when it is set (pairs of consecutive indexes share a port). The field depends on the second argument: 0 gives bits 57:55, 1 bits 54:52, 2 bit 59, 3 bit 58, anything else a 26-bit field (bits 25:0, or 51:26 when address bit 8 is set). The loop passes 2, so it takes bit 59. The `value << 55` layout that operation 64 writes (above) and the 57:55 field read here are the same bit range, which is why the entry's access bits are inferred to be there; the other fields are unknown. None of `0x1_0003_2000`, `0x1_0003_2800`, `0x1_0005_2000`, `0x1_0005_2800` has a name in the Linux v5.3 header or in the SN2 headers in our holdings (the only MD name found is `SH1_MD_DQLP_MMR_DIR_PRIVEC0`); the names are ours.

**Completion and read-back (established).** Completion is the same poll as every other operation: bits 41:40 not `01`, then bit 40 clear, deadline 20,000,000. The extra read of `0x1_0002_0088` must have bit 41 clear. The returned field is discarded by the loop (`0xffa77b80` only decrements the count), so no value read from the result registers is tested on this path, and nothing later in the boot path reads directory entries: the only other consumer is the OS-time query `0xffa7a800`, which tests only for -1.

**Permission writes are a different path (established).** `memctl_change_mem_permissions` is `0xffa7a690` (error string "Error writing directory access bits"), a locked wrapper around `0xffa6b060` and operation 64 (above). Arguments: address, length in bytes, an unused third word, permission value. It rounds the address down and the end up to 512-byte units, so the word count is the rounded length divided by 8. It runs from `0xfface79c` (in `0xfface570`, value 6, address `0xa00000` plus the masked shadow base, which is 0 on NASID 0, length `0x600000`), from `0xffa73aec` (value 7, address 0, length 65535) and, at OS time only, from the SAL procedure at `0xffb1ac1c`. The two boot calls run only when the chip-object method at slot 39 of the class-0 method table (table `0xffbd7c18`, slot at `0xffbd7d50`, descriptor `0xffc4bd30`, entry `0xffa96460`) returns anything but 2. That method returns bits 31:28 of the SHub ID word at `0x1_1006_0580` of the node, in the global window: the revision (the 2.4 header's `SH_SHUB_ID_REVISION` is bits 31:28). A model whose revision reads 2 or lower never issues operation 64 on this path; a model that reports revision 3 issues both calls.

**Operation 64 words for the two boot calls (established as code, NASID 0).** Per call, in order: `0x1_0003_1000` = permission `<< 55`; `0x1_0005_1000` = the same (both in the global window of the node, node number in bits 48:38); `0x1_0002_0080` = the aligned address; `0x1_0000_0080` = 0; `0x1_0000_00c0` = all ones; `0x1_0002_0088` = `0x14000000000 | words` (operation `0x40` at bit 32, go bit 40). Completion is the same poll as for every operation, and bit 41 of `0x1_0002_0088` must be clear afterwards.

| Call | Address | Length | Permission | `0x1_0003_1000` and `0x1_0005_1000` | `0x1_0002_0080` | Words | Go word |
|---|---|---|---|---|---|---|---|
| `0xfface79c` (shadow copy, first) | `0xa00000` | `0x600000` | 6 | `0x0300_0000_0000_0000` | `0xa00000` | `0xc0000` | `0x140000c0000` |
| `0xffa73aec` (after the op 80 loop) | 0 | 65535, rounded to `0x10000` | 7 | `0x0380_0000_0000_0000` | 0 | `0x2000` | `0x14000002000` |

The shadow base is masked to 0 in place by `0xffaeb1c0` before the call, so the address carries no bit 40 and no node bits. Nothing on the boot path reads the `0x1_0003_1000` and `0x1_0005_1000` words back, so plain storage is enough; faithful behaviour would store the permission in bits 57:55 of the directory entries the count covers (inferred).

**What a model must do.** Complete the run as for any other operation (bit 40 cleared on a write with go set, bits 41:40 clear afterwards, bit 41 clear). Keep `0x1_0003_2000`, `0x1_0003_2800`, `0x1_0005_2000` and `0x1_0005_2800` readable as storage; any value passes, because nothing tests it. Expect 16384 runs back to back. Faithful behaviour, if directory contents are modelled, is to return the entry that operation 64 stored for that address in bits 63:55 (inferred), but no firmware path requires it.

### Review (operation 80 trace, commit 0c34aeb)

Independent re-read in Ghidra (IA-64 module, `--sn2-prom --no-analysis`, address lists), cross-checked with `ia64-linux-gnu-objdump` listings of the same image (snprom 10.54, `shub1snprom.bin`).

- **Confirmed.** Caller chain and call sites `0xffa1af7c`, `0xffa739c6`, `0xffa77b7c`, `0xffae7e2c`; the loop in `0xffa77b40` (sign-extended NASID shifted by 38, 16384 iterations, step `0x400`, second argument 2); the dispatcher call with operation `0x50` and deadline 20,000,000; the four words and the go word `0x15000000000`; the re-read of `0x1_0002_0088` bit 41 (and -3 also giving -1); the result-register select (bit 11 picks `0x1_0005` over `0x1_0003`, bit 7 clear picks `0x2800`) and the field table (0: 57:55, 1: 54:52, 2: bit 59, 3: bit 58, otherwise 26 bits); the loop discards the result; `0xffa7a800` tests only for -1; `0xffa782c0` calls `0xffa77b40` (call at `0xffa7869c`) only when its own-node id read (`0xffa0dcf0`) differs from the node being set up and cpuid[2] is not the stand-in value; slot 39's method `0xffa96460` returns bits 31:28 of the global-window `0x1_1006_0580`.
- **Changed.** The permission-write paragraph named two callers of `0xffa7a690`; a third exists at `0xffb1ac1c` (SAL procedure, OS time). The op 64 words were not given; they are now in the table above. The "master slice" reading of the gate `0xffa0ff30` is inferred: the code returns 1 when no lower-numbered slice's flag (index `0x1a` plus the slice) is set.
- **Not checked.** That `0xffa782c0`'s second caller `0xffa6a2ac` is slot 97 (the first, `0xffa1a2fc`, is in `main`); the SAL procedure number `0x0200003e` for `0xffb1a8c0`; the poll `0xffa6fc60` was read as part of the dispatcher only.

### The test sequence for one 2 GiB bank (mode 0; established as code)

`0xffa6f000` skips banks with density index 7 and, with bit 8 of the debug word clear, banks whose flag bit 0 is clear. For bank 0, `0xffa6de80(mode 0)` then does, with start 0 and count `0x1000_0000`:

1. The pattern loop `0xffa6c6d0`: three patterns (mode 0; four for mode 2, five for mode 3) from a table of 16-byte entries in flash: `0`, `0xffff_ffff_ffff_ffff`, `0x5555_5555_5555_5555`, then `0xcccc_cccc_cccc_cccc` and `0x0f0f_0f0f_0f0f_0f0f`; all with the invert byte 1 (so `B` is the complement) and the other flag 0. For each: program the 16 pattern registers, run op 48, check -3 and bit 41; program again, run op 16 four times (start offsets 0, 32, 64, 96, reprogramming before each; the complement-on-odd-pass rule only applies with the other flag set, which these entries do not). That is 15 engine runs.
2. A zero fill: pattern 0 with the invert byte 0 (`A = 1 << 42`, `B = 0`), op 48 over the whole bank.
3. `0xffa6ce60`, a processor-side test with ordinary stores and loads (below).

The bank fails ("failed memory tests") when step 1 returns -2 or -3, or a count of 100 or more ("too many errors"); a count from 1 to 99 is tolerated and printed only in mode 3. The processor-side test of step 3 returns an error count, never -2 or -3, so the caller never fails the bank on it; its errors are only printed. All checks use the engine's own completion registers. "Initializing memory" (which always runs) later repeats step 2 once more (mode 1: the same single op 48 with pattern 0 over the whole bank).

### What the processor-side test needs (established; `0xffa6ce60` read in full)

It reads `0x1_0001_0008` for the bank size, then performs 16-byte stores and loads with the processor, uncached, at addresses `(nasid << 38) + (bank << 34) + 0x30_0000_0000 + offset` with bit 63 set (the PROM's form: `(a & 0x7fff_ffcf_ffff_ffff) | 0x8000_0030_0000_0000`), with offsets formed by single-bit and complementary patterns up to the bank size minus 16. It stores a pair of values from a flash table and reads it back through `0xffa6f640`, comparing 128 bits; it never reads a location the engine fill was meant to have set: every compare of an address follows a store of the expected pair to that address in the same step (base address, walking address, base plus walk with its complement, march, short sequences). So bank memory must behave as ordinary RAM for uncached 64-bit accesses at those node-relative addresses, with no aliasing inside the bank (a wrapped address would show as a compare error, which is counted and printed but does not fail the bank). Whether the engine ever writes real data has no effect on this.

## What a model must do for the test to pass

- Treat `0x1_0002_0088` as a register with storage whose bit 40 clears itself: on a write with bit 40 set, run (or skip) the operation and immediately store the value with bit 40 cleared and bit 41 clear. That satisfies every poll (established: `00` exits at the first read, and a model that never leaves `01` times out after 20 seconds of RTC time per run, with 8 + 1 + 16 + 2 = 27 runs on the passing path whether switch bit 8 is set or not: the 8 DRAM initialisation commands, the first credit fill when `0x1_0001_0068` starts below 4, the 15 pattern runs and the zero fill of the bank test, then the "Initializing memory" fill and its credit fill).
- Keep `0x1_0000_0080`, `0x1_0002_0080` and `0x1_0000_00c0` as storage; do not set bit 36. Keep every other register in this page as storage that reads back what was written; the sizing reads need `0x1_0001_0008` and `_0010` to do so.
- Implement `0x1_0001_0068` as storage; let IBLS0 clear bit 20 (the first credit call writes it when `0x1_0001_0068` reads below 4).
- Memory contents: no engine write has to happen for the PROM to pass memory initialisation. The PROM never reads back what an engine run wrote (the compare passes are checked through the engine's own bits, which the model reports as passed), and the directory writes and the DRAM commands have no readable effect. A model that zeroes memory on op 48 with pattern 0 matches the hardware intent (and the PROM's own "Initializing memory"); the cost was not measured (the zero fill runs over the whole 2 GiB bank twice, plus the credit fills). The directory contents are never read in this path.
- Ordinary RAM semantics for processor accesses to the bank at physical addresses from 0 to 2 GiB (reached through the node's own-memory window) are required by the processor-side test, and by everything after the jump to RAM.

## Established and inferred, in short

| Statement | Grade |
|---|---|
| Start sequence, the word and control layouts of the go word, the poll and its three exits, the two-step bit 40 clear, the deadlines in microseconds and their scaling | established (code) |
| Which operations are issued, in what order, with what start and count, for a 2 GiB bank in mode 0 | established (code); the mode value follows from a switch word of 0, the value the reviewed L1 notes give for a blank L1 |
| Which result bits are examined after which operation | established |
| Hardware meaning of the operations (DRAM commands, write pattern, read-compare, directory write), of bit 36 as "compare error" and bit 41 as "failed" | inferred |
| Bank configuration, timing and refresh deposit positions | established; field meanings inferred |
| Registers whose roles are unknown (`0x1_0001_0058`, `_0060`, `_0078`, `_0068`, `0x1_0003_0000`/`5_0000`, the all-ones words, the pattern registers) | roles unknown; access established |
| Reset values of every register in this page | unknown |
| Processor-side test needs read-after-write RAM semantics | established (code) |

What would settle the unknowns: a SHub 1 programmer's reference for the MD block (none is public), or the SGI service tools that ship with the machine, or a hardware read of the registers at the point the PROM has not yet touched them (needs the owner's approval; see [AGENTS.md](../../AGENTS.md)).

## Differences from the earlier pages

- [node-bringup.md](../../software/firmware/snprom/node-bringup.md) lists `0x1_0001_0030` and `_0050` as plain writes; `_0050` is read first and merged (`0xffa7761c`), as [registers.toml](registers.toml) already says.
- It lists per-processor stores to `0x1_0183_0200` and `0x1_0185_0200`; the arm that forms them is unreachable (above).
- It says bit 36 is read "after every engine run"; it is read after operation 16 runs only, inside the compare wrapper, and after a failure. Operation 48, the directory write and the DRAM commands never read it.
- It calls `0xffa6f000` the test driver and the deadline in "ticks"; the function is the whole "Testing memory" step and the deadline is in microseconds (as the review there says).
- New here: the credit word `0x1_0001_0068` and its two call sites, `0x1_0003_0000`/`0x1_0005_0000`, the pattern registers, the pattern table and the test sequence, the bank flag values, and the directory-write argument values.

## Review (memory bring-up and the memory-test engine)

Independent review of chips commits `b715cca` (this page) and `2764d9e` (the memory bring-up fields in `registers.toml`, `registers.shub2.toml` and the generated files), examined at chips `acf6511` plus those two. The reviewer wrote none of it. Method: the SHub 1 image (SAL 5.04, sha256 `51ccf9ad...3a34617`) was read through the IA-64 Ghidra module (Ghidra 12.1.3, the SN2 PROM profile, taken from the retools main branch because the retools revision this repository pins predates the module). Forty-five functions were decompiled: the engine start, poll, dispatcher, compare wrapper and pattern routines (`0xffa6fb30`, `0xffa6fc60`, `0xffa70310`, `0xffa700d0`, `0xffa703d0`, `0xffa6ff30`), the pattern pass, zero fill and loop (`0xffa6c390`, `0xffa6c5a0`, `0xffa6c6d0`), the per-bank test and the processor-side test (`0xffa6de80`, `0xffa6ce60`, `0xffa6f640`), "Testing memory" (`0xffa6f000`), the credit routine (`0xffa7a950`), the controller set-up and DRAM commands (`0xffa76bf0`, `0xffa775c0`, `0xffa77550`, `0xffa77bb0`), "Initializing memory" and the size sum (`0xffa782c0`, `0xffa788b0`), the density re-marking (`0xffa7c6d0`, `0xffae7a80`), the failure report and the directory write (`0xffa72500`, `0xffa6b060`, `0xffa7a690`), the switch-word readers (`0xffa975e0`, `0xffa97660`, `0xffa17b90`) and `main` (`0xffa19a20`). The decompiler output was used for control flow only. Every address, constant and branch polarity cited below was checked against an `ia64-linux-gnu-objdump -z` listing of the whole image, and where the two differed the listing was followed (it never differed on a value). Flash tables were read from the image bytes: the clock table (`0xffba2052`), the timing table (`0xffbe0650`) and the pattern table (`0xffbe0770`). Linux v5.3 `shub_mmr.h` was fetched as a single file and searched for every name and offset on the page. The L1 side is the reviewed sysco note on the settings defaults (a blank L1 answers request `0x0001` with 0). `defs-gen` was re-run.

**Confirmed (re-read in the image).**

- Engine start (`0xffa6fb30`): 64-bit stores in the node's window, in this order: the word to `0x1_0002_0080`, 0 to `0x1_0000_0080`, all ones to `0x1_0000_00c0`, then `0x1_0002_0088` = `1 << 40 | (op & 0x7f) << 32 | (value & 0x7fff_ffff)`.
- Poll (`0xffa6fc60`): the first loop leaves when bits 41:40 are not `01`; the register is then read again; bit 40 clear returns 0; bit 40 still set stores that read back with bit 40 cleared and polls bit 40 to clear with a fresh deadline; an expiry in either loop returns -3. The deadline is now plus the argument, or plus 20,000,000 for an argument of 0; every caller passes `0x1312d00` explicitly. The time is `0xffa0da70` (counter times the `rtc_ctl` period, divided by 1000).
- Operations: 48 for the pattern write, the zero fill and the credit fills; 16 for the compare (the wrapper runs four passes, the start address plus 32 times the pass number, reprogramming the 16 pattern words before each); 64 for the directory write (`0xffa6b060`, value shifted left 55 stored to `0x1_0003_1000` and `0x1_0005_1000` first); 80 for the directory read (`0xffae7dd0`). The DRAM commands are 7, 2, 0, 0, 2, 1, 1, 0, once per chip select that exists (one for the 2 GiB node). Bank 0 of the 2 GiB node gets start 0 and count `0x1000_0000` (size 2 GiB, divided by 8).
- Result checks: bit 36 of `0x1_0000_0080` is read inside the compare wrapper after bit 41 is found clear, in the failure report and in the compare-error diagnosis, nowhere else; the pattern pass `0xffa6c390` tests only -3 and bit 41, so a bit-36-only failure passes there.
- The patterns programmed (`A` and `B` at `0x8000`, `0x8010`, `0x8800`, `0x8810` of blocks 3 to 6), the pattern table (0, all ones, `0x5555...`, `0xcccc...`, `0x0f0f...`, invert byte 1, other flag 0), 3, 4 and 5 patterns for modes 0, 2 and 3, 15 runs for mode 0, the zero fill with invert 0.
- The processor-side test `0xffa6ce60`, read in full: its tests are "Base Address", "Walking Address", "Base + Walk/Inv", "Addr March/Inv" and "Short Sequences". Every compare through `0xffa6f640` follows a store of the expected pair to that address in the same step. So no engine write has to happen for the test, and the page's claim that plain RAM is enough holds for everything up to the end of "Initializing memory". The address form `0x8000_0030_0000_0000 | nasid << 38 | bank << 34 | offset` is as stated.
- Bank configuration deposits (bits 35:32 and the three fields per bank), the three stores in the order `_0000`, `_0008`, `_0010`, the timing and refresh deposit positions, the read of `_0008`, `_0040`, `_0048` and `_0050` before their writes, `_0058`, `_0060`, `_0078`, the two `0x400` stores, and the eight all-ones stores in each of the `0x3` and `0x5` blocks. The unreachable `0x1_0183_0200` and `0x1_0185_0200` arms are confirmed from both listings (the test is on bit 32 of `0x1_0003_0200 + 16 * n` and of `0x1_0005_0200 + 16 * n`, which is always set).
- The mode: `0xffa17b90` is called once, with the result of a stub that returns 0 (`0xffb91cb0`), so the mode is bits 1:0 of the word at `0x1_5003_1560` plus 16 for bit 2, and both consumers mask it with 15.
- The SHub 2 overlay removes all eight new registers (and every earlier memory register); no register added by `2764d9e` is left in it. The Linux v5.3 header names only `SH1_MD_DQLP_MMR_DIR_PRIVEC0` and `SH1_MD_DQRP_MMR_DIR_PRIVEC0` among these offsets.

**The switch word is 0 (the reviewed value).**

- The mode is 0: three patterns, 15 pattern runs, then the zero fill and the processor-side test. Bit 8 is clear. Bit 2 and the bits above 8 do not reach the memory routines read; bit 8 is the only other bit they test.
- The page was wrong about bit 8, and the error does not depend on the value. `main` tests bit 8 only to decide whether `0xffa7c6d0` runs. It then calls `0xffa788b0` and `0xffa782c0` unconditionally (both listings: the clear-bit path at `0xffa1a350` returns to `0xffa1a2c0`, the set path falls into it). So "Initializing memory" always runs, the second credit call always happens, and `0x1_0003_0000` and `0x1_0005_0000` are always read-modified-written. With bit 8 clear `0xffa7c6d0` also runs and sets density 7 for each bank whose flag bit 0 is clear. Bit 8 changes which banks "Testing memory" and "Initializing memory" touch (those with flag bit 0 clear are skipped unless it is set).
- Engine runs on the passing path: 8 DRAM commands, 1 credit fill (register below 4), 15 pattern runs, 1 zero fill, 1 "Initializing memory" fill, 1 second credit fill (the register holds 4, above 2): 27 runs, not 25 (and not 27 only with bit 8 set).

**Mechanical fixes made in this review.**

1. Step 3 and the mode paragraph: the polarity of bit 8 (above), the mode as established, the stub that feeds `0xffa17b90`.
2. Credit word: the engine fill runs before the register write; the BTE timeout prints and returns (the page said it issued the transfer again, but the code returns to the caller at `0xffa7ad10`); the first flagged bank, not bank 0; "Initializing memory" always runs. Same changes in the `md_reg_0001_0068` and `md_reg_0003_0000` docs.
3. Timing word `T`: bit 0 keeps its old value, so the low byte is `0x02` or `0x03`; bit 52 is always set and bits 53 and 54 are added for the record values 2 and 4 (the page and the `trcd` fields said "exactly one of" 52, 53, 54). `const_lo` is now bits 7:1; `trcd3`, `trcd2` and `trcd4` are corrected and graded inferred.
4. Failure report: with bit 36 clear it reads `0x1_0000_00b8` and prints "other than bist compare error"; with bit 36 set it runs the diagnosis. The page and the `md_mbist_err` and `md_mbist_status` docs had the polarity reversed. Nothing on a passing path changes.
5. Run counts in "What a model must do" (27), the error tolerance (a pass count of 1 to 99 is tolerated, 100 or more or -2 or -3 fails the bank, the processor-side test never fails it), the deadline wording, and the pattern words (`f << 40` from the other flag byte).
6. Site corrections: `0xffa773ec` to `0xffa773fc`; the `_0008` and `_0010` read sites to the call sites (`0xffa6cebc`, `0xffa7ab9c`, `0xffa7838c`, `0xffa7890c`).
7. Grades: 41 field grades changed from established to inferred where the doc asserts a meaning the image does not state and Linux v5.3 does not define: every bank `density` and `rank` field, `timing_idx` (three registers each), refresh `cs_enable`, `interval`, `trfc` (two registers each), and the six `trcd` fields. Deposit positions stay established in the docs.
8. `node-bringup.md`: the `_0050` read-first, the unreachable `0x1_0183_0200` and `0x1_0185_0200` stores (table rows and the open-questions line), the error-report polarity, and bit 36 read after operation-16 passes only (its table row). The older review records on that page were left as written.

**Findings not fixed.**

1. A read-modify-write of the SHub ID register is missing from the page and from the `shub_id` accesses: when the node running the PROM is the node being set up, `0xffa76bf0` reads `0x1_1006_0580` (`0xffa774dc`) and writes it back with bits 45:44 cleared (`0xffa774fc`), after the timing stores and before the all-ones stores. A model that decodes the size field in bits 45:44 needs it.
2. `0xffa6f000` starts with two flash-variable lookups, `DisabledMem` and `DisMemReason`: each bank named in them has flag bit 0 cleared (after an L1 query per bank), which skips its test. With the variables unset nothing happens. The page does not mention them.
3. The presence and privilege vector routines (`0xffa79310`, `0xffa79960`) are called from inside `0xffa76bf0`, after the all-ones stores and before the `_0060` write, not after this page's scope. [node-bringup.md](../../software/firmware/snprom/node-bringup.md) lists their stores.
4. `0xffae7b90`, called from "Initializing memory" only for a bank other than 0 that is fully populated (never for the one-bank node), reads `_0010` and `_0020`, rewrites `_0000`, `_0008`, `_0010`, `_0020` (bit 63 set, then cleared after a 100,000 microsecond delay) and `_0040`. The statement that `_0020` is never read, here and in the `md_timing_0` access of `w`, holds for the one-bank node only. The earlier review's "no read of `0x1_0001_0020` exists in SAL_B" is wrong for this routine.
5. The credit routine, before its register reads, calls the flash-variable lookup `0xffa802f0` and two formatting routines whose results it does not use; the page says it was read in full without mentioning them.
6. The bank flag values (1 for a bank with all four DIMMs, 2 otherwise) and the 0 to 8 timing index mapping, the density and rank code derivation from the SPD bytes (`0xffa7b1b0`, `0xffa7b310`, `0xffa7b410`, `0xffa7b6c0`, `0xffa7b7e0`) were not re-read; the flag stores were checked in `0xffa77bb0`, the rest rests on the earlier reviewed page.
7. "A model that zeroes memory on op 48 costs nothing" was a claim without a measurement and is now stated as unmeasured. Zeroing 2 GiB twice is not obviously free for an emulator.
8. The compare diagnosis `0xffa708e0` and its helpers (`0xffa727e0`, `0xffa72ad0`) were located and their reads of the pattern words (offsets `0x8000` to `0x8030`, `0x8800` to `0x8830` in blocks 3 to 6) listed, not decoded. A model that reports a compare failure would need them.
9. The second-node path (`0xffa6a100`, entered through a descriptor at `0xffc4bb40`) was located, not followed. `0xffa733d0` is also called from `0xffad7bac`, so the "reached only through a function-descriptor table" wording is about the caller, not about the size-class routine itself.

**Not checked.** The L1 request path (`0xffa7d040`, `0xffa7d1f0`) beyond its use as the source of the word; the SPD derivation above; the DIMM discovery routine beyond the flag stores; whether `0xffa0ff30` returns 1 on the one processor of a one-processor node (its use as the master test was taken from the earlier pages); the SHub 2 image (not read); the generated Python, Rust and XML outputs beyond reproducibility; the DRAM command words on the page (the earlier trace values), of which only the field positions in `0xffa77550` were re-read.

**Cleared scope.** The engine start, poll, result checks, operation codes and counts, the pattern registers and table, the pass and run counts for a one-bank 2 GiB node with a switch word of 0 (27 runs), the credit routine's two paths, the processor-side test's independence from engine data, the bank configuration, timing and refresh deposit positions as corrected, the "must return" entries after the corrections above (no value changed; the polarity and condition changes are in fixes 2 and 4), and the SHub 2 overlay. Not cleared: the findings above, the SPD-derived values, and the roles of the words in the `0x3` and `0x5` blocks.

## SPD and the DIMM group rule

Added from reading `0xffa77bb0` (DIMM discovery) and `0xffa76290` for the slot 5 sweep ([prom-reset.md](prom-reset.md#slot-5-after-the-permission-set-up-slot-by-slot)). Established.

- **A bank is four DIMM positions.** `0xffa77bb0` asks for the SPD of position `p` = 0 to 3 of each bank `b` = 0 to 3 (`0xffa7bd60(nasid, b, p, buffer)`, an L1 request, 256 bytes per position) and collects a four-bit mask per bank: bit `p` is set when the request returned status 0. The L1 device id of position `p` in bank `b` is `8 + ((p & 1) * 4 + b) * 2 + (p >> 1)`, so bank 0 asks for ids 8, 16, 9 and 17 for p = 0, 1, 2, 3 (re-derived in Ghidra from `0xffa7bd60` and `0xffa85470`; it agrees with [l1-requests.md](../../software/firmware/snprom/l1-requests.md)). The PROM's name for a missing position is `DIMM%d N%d_%c_BUS_%c` (`0xffa73bd0`): DIMM number `2b + (p >> 1)`, bus letter `L` or `R` from `p & 1`, then `X` or `Y` from `p >> 1`; so each bank spans DIMM numbers `2b` and `2b+1`, each on the L and R buses. How those four positions map to the physical Altix 350 slots is not in the PROM and stays unknown. `0xffa76290` then rejects any mask other than 0 or `0xf`: it prints "DIMM groups must be plugged in sets of 4 DIMMs", names each missing DIMM, prints "Bank n will be disabled" and sets the mask to 0. A bank with mask `0xf` gets flag 1, density and rank from the SPD and size `0x40 << (density + rank + 2)`; any other bank gets flag 2 and density 7. Density (`0xffa7b1b0`) is taken from SPD byte 31 of each of the four positions (0x10, 0x20, 0x40, 0x80 give 0 to 3; 0x01 and 0x02 give 4 and 5; anything else 7) and the smallest code of the four wins. Rank (`0xffa7b310`) is from SPD byte 5 (1 gives 0, 2 gives 1, other values -1); the four must agree or the PROM prints "DIMMS within bank slot have different number of banks" and returns rank 0. So four identical images are sufficient, not strictly required, but only the rank agreement is checked.
- **Consequence for a one-node Altix 350.** If the model serves SPD for fewer than four DIMMs of bank 0, every bank reads density 7, `0xffa788b0` returns 0 and `main` prints "No memory on node" and freezes the node (slot 97 and slot 5 instead take `0xffa0afd0`). To keep the hardware path the L1 must answer all four positions of bank 0 (ids 8, 16, 9, 17) with status 0 and valid SPD (byte 31 a known density, byte 5 equal in all four, plus the timing bytes the later routines read). Banks must also be filled from bank 0 upward: `0xffa764a0` prints "FATAL MEMORY CONFIGURATION ERROR: Dimms must be plugged in continuous order" and halts the node (`0xffad2cb0(nasid, 0xd8)`) if an empty bank (density 7) precedes a populated one, and the same for a single-sided bank above a double-sided one. Absent positions must therefore return an L1 error status for banks 1 to 3, not a zeroed SPD. In the stand-in processor (`cpuid[2]` = `0xaeeeeeee8badbeef`) case `0xffa7bd60` does not use the L1 at all: it builds a fake SPD from the bank configuration word at `0x1_0001_0008`. How "one DIMM pair" in the manuals maps to four positions is **unknown** here; the PROM's own count is four.
- **Values derived from the SPD.** The bus clock and CAS pair come from `SH_MD_CLK_SEL` (`md_clk_sel`) and the SPD (the page above), the density and rank from the SPD bytes as `0xffa7b1b0` and `0xffa7b310` read them (not re-read for this section), and the timing words from `0xffa7b7e0`, `0xffa7b410`, `0xffa7b6c0` (not re-read). So an SPD set that is valid for the 2 GiB node above yields the words listed there; a different size only changes the density and rank fields and `0xffa788b0`'s sum. Grade: the rule is established; the per-byte SPD derivation stays as the earlier page grades it.

## Node memory set-up after the tests (slot 97)

Slot 97 (`0xffa6a100`) runs the same sequence as `main` and, once memory is present, adds three steps that `main`'s listing above does not have (established, `0xffa733d0`, `0xffa78f60`, `0xffa79310`, `0xffa79960`; full table in [prom-reset.md](prom-reset.md#slot-97-0xffa6a100-and-the-test-0xffa788b0)):

- `SH_MD_DQLP_MMR_DIR_CONFIG` (`0x1_0003_0000`, the register `md_reg_0003_0000`) bits 2:0 get the size class (0 to 4, from the highest NASID-form id in the PCFG area; 0 for a one-node machine) before the memory set-up, and the same value is written to `0x1_0005_0000`. This is the "size class" write the section above could not place.
- The eight words at `0x1_0003_0200` and `0x1_0005_0200` (named `DIR_LOCVEC0..7` in the PROM's table) are written again with the node mask (1 for NASID 0), replacing the all-ones values.
- Presence vectors (`DIR_PRESVEC0..3`, `SH_SHUBS_PRESENT0..3`) and privilege vectors 0 to 7 are written with the values listed in the table. None of these registers is read. The mask for one node is 1 in word 0.

### Review

Independent review of the SPD and slot 97 sections added in `a577b18`, re-read in Ghidra (`shub1snprom.bin`, snprom 10.54). Confirmed: the four-position mask and the `0xf`-only rule in `0xffa76290`; the device id formula in `0xffa85470` (bank 0 gives ids 8, 16, 9, 17); the density-from-SPD-byte-31 and rank-from-byte-5 routines; `0xffa788b0`; `0xffa78f60`, `0xffa79310` and `0xffa79960` and the values listed. Corrected: the SPD mapping and group rule are now stated by position, with the L1 ids and the PROM's DIMM labels; the contiguous-bank and rank-order halts (`0xffa764a0`) and the stand-in processor path in `0xffa7bd60` were missing; the header names `DIR_CONFIG` bits 2:0 and 3 (system size code, directory ECC enable). Not verified: the timing routines `0xffa7b7e0`, `0xffa7b410`, `0xffa7b6c0` (they read the bank 0 buffer only; not re-derived), the L1 reply parser, and the physical slot each position is.
