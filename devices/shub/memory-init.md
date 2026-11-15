# SHub 1: memory bring-up and the memory-test engine, as SAL 5.04 drives them

What the SHub 1 firmware (`shub1snprom.bin`, SAL 5.04, snprom 10.54 build 70399, sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`, base `0xffa00000`) writes to the memory and directory (MD) block of one SHub to bring up a single node with one 2 GiB bank (four identical DIMMs in bank 0, nothing else), and what each register has to return for the firmware to get through "Testing memory" and "Initializing memory" and on to the jump to RAM. Written so that a device model can be built from this page and the generated header ([registers.md](registers.md)) alone.

Sites are SAL_B addresses, read with `ia64-linux-gnu-objdump`; no PROM bytes or listings are kept here. Register offsets are SHub 1 node offsets (`0x1_xxxx_xxxx`); the PROM reaches them as `0x8_0000_0000 + (nasid << 38) + offset` (global window, bit 63 set for uncached physical access). "Linux name" means a constant in Linux v5.3 `arch/ia64/include/asm/sn/shub_mmr.h`: that header (all 502 lines were searched for every offset below) names none of the registers on this page. The only MD names it has are `SH1_MD_DQLP_MMR_DIR_PRIVEC0` (`0x1_0003_0300`) and `SH1_MD_DQRP_MMR_DIR_PRIVEC0` (`0x1_0005_0300`), which are in [registers.toml](registers.toml) already. No SHub specification is public, so every register name below is ours and no reset value is established anywhere.

**Grades** follow [AGENTS.md](../../AGENTS.md). *Established*: the instructions at the site were read in full and the statement follows from them; it says what the code does, not what the hardware means. *Inferred*: reasoned from part of a function, from a value's use, or from a name; the reasoning is given. *Unknown*: not settled. The register and engine facts below that rest on a code path I followed to the end are marked established; the hardware meaning of any field is inferred at best, because nothing public defines it.

Companions: [node-bringup.md](../../software/firmware/snprom/node-bringup.md) (the earlier, reviewed single-node reading) and its review, [prom-reset.md](prom-reset.md), [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md). Where this page differs from them, [Differences from the earlier pages](#differences-from-the-earlier-pages) says so.

## What runs, in order, on a 2 GiB node

All of this is `main()`; the order is the order of the call sites (established).

1. `0xffa78100` runs the three set-up steps, in this order: DIMM discovery (`0xffa77bb0`, via the L1), controller programming (`0xffa76bf0`) and the DRAM initialisation commands (`0xffa775c0`, eight engine runs).
2. `0xffa6f000` is "Testing memory". Before it looks at the test mode it calls the credit routine `0xffa7af50` (see [`md_reg_0001_0068`](#the-credit-word-0x1_0001_0068)), so that routine runs even when the test is skipped. Then, for each bank that is present, it runs the per-bank test `0xffa6de80`.
3. `main()` then tests bit 8 of the L1 debug-switch word (`0xffa975e0`, the word at `0x1_5003_1560`). **Clear** (as with the `0x0800` word the earlier pages use): `0xffa7c6d0` runs and, for every bank whose flag bit 0 is clear, rewrites the three bank configuration words with that bank's density field set to 7 (`0xffae7a80`; for the 2 GiB node that re-stores the same word for banks 1 to 3, which already hold 7). "Initializing memory" does not run. **Set**: `0xffa788b0` sums the bank sizes (reads `0x1_0001_0010`); a total of zero prints a warning and freezes the node; otherwise `0xffa782c0` is "Initializing memory": for each present bank it zero-fills the whole bank with the engine (the same per-bank routine in mode 1), runs the credit routine again (argument 2), then sets bit 3 of `0x1_0003_0000` and `0x1_0005_0000`. The sections below mark which registers only that second branch touches.
4. Presence and privilege vectors, the jump to RAM, and the directory writes that go with it come after this page's scope; the directory-write contract is in [the directory-access words](#the-directory-access-words-0x1_0003_1000-and-0x1_0005_1000).

**The test mode (inferred).** `0xffa6f000` takes a mode whose low four bits select the test: 1 skips the memory test ("Skipping memory test, as requested"), 0 and 2 and 3 run it with 3, 4 and 5 data patterns (see the engine section) and 3 also prints per-bank progress. `main()` gets the mode from `0xffa17b90`, which returns the L1 debug-switch word's bits 1:0 (plus 16 when switch bit 2 is set; the 16 is masked off). With the switch word `0x0800` the earlier pages use to skip NUMAlink discovery, the mode is 0. A switch word with bit 0 set and bit 1 clear (for example the console default `0x0405` the PROM offers when the L1 cannot answer) selects mode 1. The call chain of `main()` was followed to `0xffa17b90`'s return value but not every branch of `main()`, so which switch bits arrive here is inferred; that a mode of 0 runs the whole test described below is established.

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

**Must return.** The words must read back what the PROM wrote: the memory test reads `0x1_0001_0008` (`0xffa6dedc`, `0xffa6ceb8`, `0xffa7ab76`) and `0x1_0001_0010` (`0xffa6f2fc`, `0xffa78390`, `0xffa788f0`) to find which banks exist and how big they are. `0x1_0001_0000` is never read in the traced path. Before the first write any value is accepted (the merge keeps stale bits, which then reach all three registers). Linux name: none. Grade: positions and read-back requirement established; field meaning inferred; reset unknown.

### Timing words: `0x1_0001_0020`, `_0028`, `_0040`, `_0048`

Written by `0xffa76bf0` from a 32-byte row of a table in flash (row = timing index; table at `0xffbe0650`). `0x1_0001_0040` and `0x1_0001_0048` are read first and merged (`0xffa76c6c`, `0xffa76c9c`); `_0020` and `_0028` are write-only.

- `0x1_0001_0020` and `_0040` carry one word `T`: the old value's bits 63:40 and 7:0 are kept; bits 39:8 get the low 32 bits of the row's first doubleword; bit 1 is set and bits 7:2 are cleared (so the low byte is `0x02`); bits 43:40, 47:44, 51:48 get the 16-bit values at row offsets 8, 10, 12; then exactly one of bit 52, 53, 54 is ORed in for tRCD of 3, 2, 4 clocks (established). It is a different word from the one in `_0028`/`_0048`.
- `0x1_0001_0028` and `_0048` carry one word `U`: bits 3:0, 7:4, 11:8, 15:12, 19:16, 23:20 get the 16-bit values at row offsets 14, 16, 18, 20, 22, 24; bits 63:24 are the old value of `_0048` (established).

**Must return.** `_0040` and `_0048` any value before the first write (they are merged); after it, what was written (the merge reads happen before the writes, so a read-back is not needed in the traced path, but keep storage). `_0020` and `_0028` are never read. Linux names: none. Reset: unknown.

### Refresh words: `0x1_0001_0030` and `_0050`

One word `R` is written to both, once, after the eight DRAM initialisation commands (`0xffa77adc`, `0xffa77b0c`). It starts as a read of `0x1_0001_0050` (`0xffa7761c`), then (established, `0xffa775c0` to `0xffa77aac`): bits 16:8 = 195 (or the number in the flash variable `MemoryRefresh`); bit 23 cleared; bits 22:17 = tRFC in clocks (SPD byte 42 divided by 5, at least 14); bits 7:0 get bit `cs` set for each chip select that exists (`cs = 2 * bank + rank`, so bit 0 for the 2 GiB node); bits 27:24 get bit `bank` set for each bank whose density index is 1 or less (not for the 2 GiB node). Meanings: refresh interval, tRFC and chip-select enables are inferred from the values; bits 27:24 are unknown.

**Must return** the stored value for `_0050` (it is read once before the write); any value before the first write. `_0030` is never read. Linux names: none. Reset: unknown.

### Constants and one control word: `0x1_0001_0058`, `_0060`, `_0078`

Plain writes at the end of `0xffa76bf0` (`0xffa7745c`, `0xffa773cc`, `0xffa7748c`), never read: `_0058` = `0x04004e20`; `_0060` = `0x4047` if bits 31:28 of `0x1_1006_0580` (read at `0xffa7738c`) are above 2, else `0x4045`; `_0078` = `0x24` (all established). Roles unknown. **Must return** nothing (never read). Linux names: none.

### The credit word, `0x1_0001_0068`

Read and conditionally written by the credit routine `0xffa7a960` (entry through `0xffa7af50` with argument 4, called from "Testing memory"; through `0xffa7af90` with argument 2, called from "Initializing memory", which runs only with debug-switch bit 8 set). It returns at once if `cpuid[2]` equals `0xaeeeeeee8badbeef` (the stand-in processor id), or if no bank is flagged present (the flag is bit 0 of the halfword at offset 4 + 8 * bank of the bank records; `0xffa77bb0` sets 1 for a bank with all four DIMMs and 2 otherwise, established from the stores). With bank 0 flagged it reads `0x1_0001_0068` (`0xffa7ab6c`), takes the 32-bit signed value `v`, and compares it with the argument `a`:

| Condition | What the PROM does |
|---|---|
| `v == a` | nothing |
| `v < a` | writes `a` to `0x1_0001_0068`; runs the engine (operation 48, pattern zero, 20,000,000 us deadline, result ignored) over the last 1/32 of the bank: start = bank base + size - size/32, 8-byte count = size/256; then zero-fills through the block-transfer engine: writes IBLS0 at `0x8_01c1_0000 + (nasid << 38)` with `0x100000 + 2 * (a - v)` (bit 20 busy, low bits the length), the same bank-base address to IBLS0 `+0x08`, `+0x10`, `+0x20`, `17` to `+0x18`, and polls bit 20 of IBLS0 until it reads 0 (deadline 2,000,000 us; on a timeout it prints a message and issues the transfer again, with no other exit) |
| `v > a` | writes `a` to `0x1_0001_0068`; runs the engine (operation 48, zero) over `(v - a) * 32` 8-byte words at the bank base |

(All established; read in full at `0xffa7a960` to `0xffa7af40`.) With a reset value of 0 the first call (argument 4) takes the `v < a` path, with a BTE length of 8 (`0x100008`, as in the earlier traced run). The second call (argument 2, only with switch bit 8 set) then finds 4 and takes the `v > a` path, zero-filling 64 words at the bank base. With a reset value of 4 the first call does nothing. **Must return** what was written (the value after the first call must be 4, or the second call's branch changes); the register's role is unknown (it keeps a credit-like count for the block-transfer zero fill, inferred from the comparison, unverified). IBLS0 must read bit 20 as 0 after the write ([shub_ii](../shub_ii/README.md)). Linux name: none. Reset: unknown.

### MD size and enable words: `0x1_0003_0000` and `0x1_0005_0000`

Read and written in "Initializing memory" (`0xffa785cc`, `0xffa785ec`, `0xffa7861c`; only with debug-switch bit 8 set): the PROM reads `0x1_0003_0000`, sets bit 3, and writes the result to both `0x1_0003_0000` and `0x1_0005_0000` (established, `0xffa782c0`; local node only). A second routine reached only through a function-descriptor table (`0xffa733d0`, called from `0xffa6a1bc`) writes bits 2:0 of both with a size class from 0 to 4 (0 for a count of up to 127); another (`0xffa78f70`) reads bits 2:0 plus one as a shift. Whether the table path runs on a single node was not traced (unknown). **Must return** the stored value; the model must accept the read-modify-write. Roles of bits 2:0 and 3 are inferred only ("size class", "memory initialised"); no source gives them. Linux names: none.

### Words written with ones and a constant: `0x1_0003_0200` to `_0270`, `0x1_0005_0200` to `_0270`, `0x1_0003_0400`, `0x1_0005_0400`

`0xffa76bf0` stores all ones to eight words at stride 0x10 in each of the `0x3` and `0x5` blocks (`0xffa7729c`, `0xffa7732c`), and `0x1000` to `0x1_0003_0400` and `0x1_0005_0400` (`0xffa773ec`, `0xffa7742c`). None is read. **Must return** nothing; accept the stores. The earlier pages also list stores to `0x1_0183_0200` and `0x1_0185_0200`; this reading finds the arm that would form those addresses unreachable (the test that selects it is on bit 32 of an address that always has it set), so no store to them is claimed (established for the instruction sequence). Roles unknown.

### The memory-test engine registers

`0x1_0002_0080` (word), `0x1_0002_0088` (control), `0x1_0000_0080` (status; bit 36 is the failure bit the test reads), `0x1_0000_00b8` (error word read in the failure report) and `0x1_0000_00c0` (written all ones at each start). Layouts, the start sequence and the poll are in [the engine contract](#the-engine-contract). Summary of what each must return on a passing run:

| Register | Read by | Must return |
|---|---|---|
| `0x1_0002_0088` | the poll `0xffa6fc60` and the failure checks | after a start write, bits 41:40 not equal to `01` within the deadline; bit 41 reads 0 |
| `0x1_0000_0080` bit 36 | `0xffa702c0` after every operation-16 poll | 0. The PROM writes 0 to this register before each start, so plain storage gives it |
| `0x1_0002_0080`, `0x1_0000_00c0` | never in the passing path | plain storage |
| `0x1_0000_00b8` | `0xffa725f6`, only after bit 36 is found set | not read on a passing run |

### The directory-access words, `0x1_0003_1000` and `0x1_0005_1000`

`memctl_write_dir_access` (`0xffa6b060`, name from its error string) stores `value << 55` to `0x1_0003_1000` (`0xffa6b10c`) and then to `0x1_0005_1000` (`0xffa6b14c`), both in the global window of the node whose number is bits 48:38 of the address argument, and then runs engine operation 64 with a count (below). Never read. **Must return** nothing; the engine run must complete as for any other operation. The field is the top nine bits, 63:55 (the shift gives the width as inferred, since the values seen are 6 and 7); what the stored value means to the directory is unknown. The function does not check bit 36 of `0x1_0000_0080`; it fails on a timeout (-3) or on bit 41 of `0x1_0002_0088`. Its wrapper `0xffa7a690` rounds the range to 512-byte units and passes the count in 8-byte words. Callers: `0xffa73aec` (value 7, address 0, length 65535, so 8192 words), `0xfface79c` in the PROM-to-RAM copy (value 6, 6 MiB, so 0xc0000 words) and `0xffb1ac1c`; the first two are after the point where the PROM jumps to RAM and are outside this page. No separate directory-ECC register is touched (established for this function). Linux names: none.

### Pattern registers for the test data

Before every operation 48 or 16 run the PROM programs 16 words (`0xffa703d0`, established): two patterns `A` and `B`, stored as `A, B, A, B` at offsets `0x8000`, `0x8010`, `0x8800`, `0x8810` of each of the four blocks `0x3`, `0x4`, `0x5`, `0x6` (`0x1_0003_8000`, `0x1_0003_8010`, `0x1_0003_8800`, `0x1_0003_8810`, then the same in `0x1_0004_xxxx`, `0x1_0005_xxxx`, `0x1_0006_xxxx`). With the 40-bit pattern `p` from the command structure (bits 39:0 of the 64-bit pattern), `A = p | 1 << 42` and `B = p` when the pattern's invert byte is 0, `B = ~p & 0xff_ffff_ffff` when it is 1. Never read. **Must return** nothing; accept 64-bit stores at these 16 offsets. Roles of bit 42 and of the 40-bit width are unknown.

## The engine contract

One engine does all of: DRAM initialisation commands, the memory test patterns, zero fill, and the directory write. Nothing here is readable from a specification; the completion logic is read from the code, the hardware semantics are inferred.

### Start (established, `0xffa6fb30`)

In this order, all 64-bit stores into the node's window:

1. `0x1_0002_0080` = the command word (a byte address for the memory operations, a DRAM command word for the initialisation sequence).
2. `0x1_0000_0080` = 0.
3. `0x1_0000_00c0` = all ones.
4. `0x1_0002_0088` = `1 << 40 | (op & 0x7f) << 32 | (value & 0x7fff_ffff)`. Bit 40 is "go".

The command word and the value come from a small command structure the callers build (node number at +0, word at +8, 32-bit value at +16, pattern at +24, mode at +32, flags). `0xffa70310` is the dispatcher: operation 16 goes to the compare wrapper `0xffa700d0`; everything else is `start` then `poll` with the caller's deadline (always 20,000,000, the default).

### Poll (established, read in full, `0xffa6fc60`)

Time is in microseconds. `0xffa0da70` reads the real-time clock at `0x1_101c_0000` and `0xffa0da00` the period from bits 13:4 of `0x1_1006_0280` (`rtc_ctl`): the period in nanoseconds is `10 * field + 10`, the count is multiplied by it and divided by 1000. So the 20,000,000 deadline is 20 seconds of clock time at the clock's real rate, and the clock has to advance or every wait lasts the full count. (Under the processor-id stand-in the count is also shifted left by 7.)

1. Save the per-slice word at `0x1_1003_0000 + 0x80 * slice` (any value; its low byte is written back as a progress code at exit).
2. Loop: read `0x1_0002_0088`, keep bits 41:40. Leave the loop when they are **not** `01`. `01` means busy (go set, no failure). Bits 38:0 are never examined.
3. Read the register again. If bit 40 is clear, return 0. If bit 40 is still set (so bits are `11`), store the value just read back with bit 40 cleared, and poll until bit 40 reads 0, with a fresh deadline of the same length.
4. A deadline expiry in either loop returns -3 (the caller prints "MBIST TIMEOUT" with the address from bits 32:0 of `0x1_0000_0080` times 8, and names the suspect DIMMs).

So: `00` is done and passed; `10` is done and failed (poll returns 0, the caller sees bit 41); `11` is failed with go still set (the model must accept the PROM clearing bit 40 by a write); `01` is busy.

### Result checks after the poll (established)

- Operation 48 and operations 7, 2, 1, 0 for DRAM initialisation, the credit fills: the callers test only for -3 and bit 41 of `0x1_0002_0088`. The DRAM initialisation runs and the credit-routine fills ignore the result.
- Operation 16 (compare), inside `0xffa700d0`, after each of four passes: bit 41 of `0x1_0002_0088` set means fail (-2); then bit 36 of `0x1_0000_0080` set means fail (-2). The pattern loop that calls the wrapper (`0xffa6c3a0`) only treats -3 and bit 41 as errors, so a bit-36-only failure is passed over there (it would be cleared by the next start writing 0 to `0x1_0000_0080`).
- Operation 64, the directory write: -3 or bit 41.
- Failure report (`0xffa72500`): reads bit 36 of `0x1_0000_0080`; if set, reads `0x1_0000_00b8` and prints it as "MBIST failed other than bist compare error" or similar; the failing byte address is derived from bits 32:0 of `0x1_0000_0080`.

### Operations the PROM uses

| Op | Users | Command word at `0x1_0002_0080` | Value (30:0) |
|---|---|---|---|
| 7, 2, 0, 0, 2, 1, 1, 0 | `0xffa775c0`, DRAM initialisation, per chip select, eight runs per present chip select, results ignored | a command word built by `0xffa77550` from the bank's 2-bit field (bits 35:34), the rank (bit 12), a 14-bit mode value split over bits 11:10, 23:13 and 26, and bit 8 for one run; bit 21 is added for the five runs with operations 7, 2, 2, 1, 1 (established); the earlier trace recorded `0x200000`, `0x200000`, `0x100`, `0x9c800`, `0x200000`, `0x200000`, `0x200000`, `0x1c800` | 0 |
| 48 (`0x30`) | pattern pass (write), zero fill, init-memory fill, credit fill | start byte address within the node: `bank << 34` for a whole bank, so 0 for bank 0 | count of 8-byte words, bank size / 8 (`0x1000_0000` for 2 GiB) |
| 16 (`0x10`) | pattern pass (compare), four passes per pattern | start + 32 * k for pass k = 0..3 | as op 48 |
| 64 (`0x40`) | directory write | the address as passed (global, node in bits 48:38) | count of 8-byte words |
| 80 (`0x50`) | directory read (`0xffae7dd0`), results from `0x1_0003_2000`/`2800` and `0x1_0005_2000`/`2800` | address | 0 |

The DRAM-initialisation meaning of ops 7, 2, 1, 0 (precharge-all, refresh, mode-register sets) is inferred from the order and the word fields; the memory-test meaning of 48 (write the pattern over the range) and 16 (read and compare) is inferred from the pass structure and from bit 36 being read after 16 only. Op 80 is not reached on a single node (its callers are the remote-node loop `0xffa77b40` and the runtime `0xffa7a800`): not exercised, unverified.

### The test sequence for one 2 GiB bank (mode 0; established as code)

`0xffa6f000` skips banks with density index 7 and, with bit 8 of the debug word clear, banks whose flag bit 0 is clear. For bank 0, `0xffa6de80(mode 0)` then does, with start 0 and count `0x1000_0000`:

1. The pattern loop `0xffa6c6d0`: three patterns (mode 0; four for mode 2, five for mode 3) from a table of 16-byte entries in flash: `0`, `0xffff_ffff_ffff_ffff`, `0x5555_5555_5555_5555`, then `0xcccc_cccc_cccc_cccc` and `0x0f0f_0f0f_0f0f_0f0f`; all with the invert byte 1 (so `B` is the complement) and the other flag 0. For each: program the 16 pattern registers, run op 48, check -3 and bit 41; program again, run op 16 four times (start offsets 0, 32, 64, 96, reprogramming before each; the complement-on-odd-pass rule only applies with the other flag set, which these entries do not). That is 15 engine runs.
2. A zero fill: pattern 0 with the invert byte 0 (`A = 1 << 42`, `B = 0`), op 48 over the whole bank.
3. `0xffa6ce60`, a processor-side test with ordinary stores and loads (below).

A pass count above 0 from step 1 would make the bank fail ("failed memory tests"); the default error budget is 100 compare errors in the loop and 4 in the processor-side test. All checks use the engine's own completion registers. With debug-switch bit 8 set, "Initializing memory" later repeats step 2 once more (mode 1: the same single op 48 with pattern 0 over the whole bank).

### What the processor-side test needs (inferred; `0xffa6ce60` was read in outline, not branch by branch)

It reads `0x1_0001_0008` for the bank size, then performs 16-byte stores and loads with the processor, uncached, at addresses `(nasid << 38) + (bank << 34) + 0x30_0000_0000 + offset` with bit 63 set (the PROM's form: `(a & 0x7fff_ffcf_ffff_ffff) | 0x8000_0030_0000_0000`), with offsets formed by single-bit and complementary patterns up to the bank size minus 16. It stores a pair of values from a flash table and reads it back through `0xffa6f640`, comparing 128 bits; it never reads a location the engine fill was meant to have set (each address is written before its first read, as far as read). So bank memory must behave as ordinary RAM for uncached 64-bit accesses at those node-relative addresses, with no aliasing inside the bank (a wrapped address would show as a compare error). Whether the engine ever writes real data has no effect on this.

## What a model must do for the test to pass

- Treat `0x1_0002_0088` as a register with storage whose bit 40 clears itself: on a write with bit 40 set, run (or skip) the operation and immediately store the value with bit 40 cleared and bit 41 clear. That satisfies every poll (established: `00` exits at the first read, and a model that never leaves `01` times out after 20 seconds of RTC time per run, with 8 + 1 + 16 = 25 runs on the passing path with switch bit 8 clear, and 27 with it set).
- Keep `0x1_0000_0080`, `0x1_0002_0080` and `0x1_0000_00c0` as storage; do not set bit 36. Keep every other register in this page as storage that reads back what was written; the sizing reads need `0x1_0001_0008` and `_0010` to do so.
- Implement `0x1_0001_0068` as storage; let IBLS0 clear bit 20 (the first credit call writes it when `0x1_0001_0068` reads below 4).
- Memory contents: no engine write has to happen for the PROM to pass memory initialisation. The PROM never reads back what an engine run wrote (the compare passes are checked through the engine's own bits, which the model reports as passed), and the directory writes and the DRAM commands have no readable effect. A model that does zero memory on op 48 with pattern 0 matches the hardware intent (and the PROM's own "Initializing memory") and costs nothing. The directory contents are never read in this path.
- Ordinary RAM semantics for processor accesses to the bank at physical addresses from 0 to 2 GiB (reached through the node's own-memory window) are required by the processor-side test, and by everything after the jump to RAM.

## Established and inferred, in short

| Statement | Grade |
|---|---|
| Start sequence, the word and control layouts of the go word, the poll and its three exits, the two-step bit 40 clear, the deadlines in microseconds and their scaling | established (code) |
| Which operations are issued, in what order, with what start and count, for a 2 GiB bank in mode 0 | established (code); the mode value from the L1 switch word inferred |
| Which result bits are examined after which operation | established |
| Hardware meaning of the operations (DRAM commands, write pattern, read-compare, directory write), of bit 36 as "compare error" and bit 41 as "failed" | inferred |
| Bank configuration, timing and refresh deposit positions | established; field meanings inferred |
| Registers whose roles are unknown (`0x1_0001_0058`, `_0060`, `_0078`, `_0068`, `0x1_0003_0000`/`5_0000`, the all-ones words, the pattern registers) | roles unknown; access established |
| Reset values of every register in this page | unknown |
| Processor-side test needs read-after-write RAM semantics | inferred |

What would settle the unknowns: a SHub 1 programmer's reference for the MD block (none is public), or the SGI service tools that ship with the machine, or a hardware read of the registers at the point the PROM has not yet touched them (needs the owner's approval; see [AGENTS.md](../../AGENTS.md)).

## Differences from the earlier pages

- [node-bringup.md](../../software/firmware/snprom/node-bringup.md) lists `0x1_0001_0030` and `_0050` as plain writes; `_0050` is read first and merged (`0xffa7761c`), as [registers.toml](registers.toml) already says.
- It lists per-processor stores to `0x1_0183_0200` and `0x1_0185_0200`; the arm that forms them is unreachable (above).
- It says bit 36 is read "after every engine run"; it is read after operation 16 runs only, inside the compare wrapper, and after a failure. Operation 48, the directory write and the DRAM commands never read it.
- It calls `0xffa6f000` the test driver and the deadline in "ticks"; the function is the whole "Testing memory" step and the deadline is in microseconds (as the review there says).
- New here: the credit word `0x1_0001_0068` and its two call sites, `0x1_0003_0000`/`0x1_0005_0000`, the pattern registers, the pattern table and the test sequence, the bank flag values, and the directory-write argument values.
