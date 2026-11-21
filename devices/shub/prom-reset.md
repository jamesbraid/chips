# SHub 1: every register access the SAL 5.04 PROM makes from reset to the console start

What the firmware image `shub1snprom.bin` (SAL 5.04, banner "SGI SAL Version 5.04 rel081111 IP41", package snprom-10.54-70399, sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`, 6 MiB at `0xffa00000`) does to SHub 1 registers, in the order it issues the accesses, from processor reset through SAL_A and the reset entry of SAL_B into the first part of `main()`, up to the point where the L1 console UART is brought up. A model of the chip that returns what this page says lets the PROM reach that point. The wider boot path is [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md) and [node-bringup.md](../../software/firmware/snprom/node-bringup.md); the chip is [README.md](README.md) and its register file is [registers.toml](registers.toml).

**Grades.** *established*: the instructions, address constant, width and direction were read in full in this image. *inferred*: a role, a meaning or a hardware behaviour reasoned from that code, with the reasoning given. *unknown*: not settled; the page says what would settle it. **Software expectation**: a value or behaviour the PROM code requires of the hardware. It is evidence about what a model must return, and it is graded as the code reads, not as a hardware fact: a register read taken after firmware has run is not a reset value, and a value the PROM tolerates says nothing about what the silicon holds. Linux v5.3 defines only the revision field (bits 31:28) of the SHub ID register, the real-time clock, the IPI access register, the CRB CAM control, the PIO write status, the two directory privilege vectors and the LED registers; it does not define the NASID field, the bus-clock field, the memory-test engine bits, the firmware lock or the scratch words. Where this page says established for one of those it means what the code does at the access; the meaning is inferred. No SHub reference manual is held, so no register has an established hardware reset value anywhere on this page.

**Sources and checks.** The accesses were read in the SAL 5.04 image (`ia64-linux-gnu-objdump`, physical addresses with `-z`). The SAL_A and progress-write facts reuse the independently reviewed readings in [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md) (SAL_A on SHub 1 and the reviews of streams K, L and M) and each was re-read here. Names come from Linux v5.3 `arch/ia64/include/asm/sn/shub_mmr.h` (SHub 1 names are the `SH1_` constants), `shubio.h` and `addrs.h`; the header names only the registers in [registers.toml](registers.toml), so most rows are "unnamed" with a label that is ours. Where this page corrects an earlier PROM page it says so, at the end.

## Address forms

The PROM runs in physical mode with bit 63 set on every address it uses (the uncached attribute). The decode agrees with the [SN2 address map](../../platforms/sn2/address-map.md).

| Form | Address as issued | Window, NASID, offset |
|---|---|---|
| Local MMR window | `0x8000_0081_xxxx_xxxx` | bit 63; space field (bits 39:38) = 2, the local MMR window `0x80_0000_0000`; no NASID; offset `0x1_xxxx_xxxx` |
| Local junk bus | `0x8000_0087_fedN_0000` | same window; offset `0x7_fedN_0000` (LED registers, N = 0 to 3) |
| Global MMR window | `0x8000_0009_xxxx_xxxx + (nasid << 38)` | bit 63; bit 35 = the global window `0x8_0000_0000`; NASID at bit 38 and up (11 bits, from `0x1_1006_0580` bits 42:32); offset `0x1_xxxx_xxxx` (bit 32 set, so it is not the I/O interface path) |

Offsets are the Linux v5.3 SHub 1 node offsets. The first nibble of the 32-bit part picks the unit by the README's rule: `0x0` memory and directory (MD), `0x1` local block (LB), `0x2` processor interface (PI), `0x5` the network-interface block. Every register on this page is accessed as the width stated; the PROM issues no sub-word access except the 16-bit LED stores.

## The progress write P(c)

Every progress code is written the same way, and it is the commonest access in this phase (SAL_A at `0xffc4e590`, the SAL_B reset entry inline, `main` through the routine at `0xffa0ddb0`). With n = `cr.lid` bits 26:23 (the processor slice, 0 to 3) and c the code byte:

1. read 64 bits at `0x8000_0081_5003_1500 + 16*n` (history H);
2. write 64 bits `(H << 8) | c` to the same address (the low byte replaced);
3. write 16 bits to LED register A, `0x8000_0087_fed0_0000 | (b << 16)` with b = (n >> 1) & 1; the value is c, ORed with `0x60` when the address has bit 16 set;
4. write 16 bits to LED register B, `0x8000_0087_fed2_0000 | ((b ^ 1) << 16)`, value c, ORed with `0x60` when bit 16 is set.

So slices 0 and 1 write `fed0_0000` (c) and `fed3_0000` (c | 0x60); slices 2 and 3 write `fed1_0000` (c | 0x60) and `fed2_0000` (c). The history word is read back by the next progress write of the same slice, so it must return what was stored; no code is read for a decision (established). The LED stores must be accepted and need not be readable (established). Codes in this phase, from the PROM's own table at `0xffbd7000`: 48 (0x30), 49 (0x31), 53 (0x35), 8, 12 (0xc) and then 13 (0xd) (the table is in [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#the-path-in-one-table)).

## Accesses in the order the PROM issues them

Sites are PROM addresses. R is a read, W a write, RMW a read then write of the same address. The "what the code needs" column is the software expectation. Register decode, Linux name and the required read value are collected in [the register table](#registers-touched) below.

### 1. SAL_A (`0xffc4e000`), reason 3 then reason 0

SAL_A is entered twice: reason 3 first (PAL asks which PAL pair to use), then, after PAL_B has run, reason 0 (reset). Both entries run the node set-up (A1 to A7). Reason 3 then returns to PAL and touches no more SHub registers. The first thing both entries do, setting `psr.db` and calling a routine that returns 1, is not an MMR access.

| # | Site | Access | Value, fields | What the code needs | Grade |
|---|---|---|---|---|---|
| A1 | `0xffc4e7f0` | W64 `0x8000_0081_1002_0000` | `0x0000_0000_1503_1010` (bits 28, 26, 24, 17, 16, 12, 4 set) | the write is accepted; the constant appears nowhere else in SAL_A or SAL_B, so it is never read back (a search for the address constant, not a trace) | established (access); unknown (meaning) |
| A2 | `0xffc4e800` | R64 `0x8000_0081_2001_0100` | whole word | the value is used only as the base of A3; no test, no branch; any value | established |
| A3 | `0xffc4e816` | W64 same address | A2 value with bit 24 set | bit 24 must be settable; the later write-enable use (SAL_B `0xffa97796`, below) needs it to read back as written | established (access); inferred (role) |
| A4 | `0xffc4e866` | R64 `0x8000_0081_5003_1510` | whole word (progress history of slice 1) | value used only as LED data; any value | established |
| A5 | `0xffc4e8c0` | W16 `0x8000_0087_fed1_0000` | `(A4 | 0x60) & 0xffff` | accepted | established |
| A6 | `0xffc4e906` | R64 `0x8000_0081_5003_1530` | whole word (history of slice 3) | as A4 | established |
| A7 | `0xffc4e960` | W16 `0x8000_0087_fed3_0000` | `(A6 | 0x60) & 0xffff` | accepted | established |

Reason 0 continues. First `cr.lid` is set to `slice << 23`, where slice is bits 1:0 of PAL's `r33` (no register read). The node election follows (`0xffc4e970`, called at `0xffc4e3a0`); v = slice + 1, so v is 1 to 4.

| # | Site | Access | Value, fields | What the code needs | Grade |
|---|---|---|---|---|---|
| A8 | `0xffc4e9a6` | W64 (release store) `0x8000_0081_101d_0088` | v | accepted | established |
| A9 | `0xffc4e9b0` | R64 (acquire load) `0x8000_0081_101d_0080` | whole word, compared with v for equality | must read exactly v after A8. Equal: this processor is the winner and runs A10 to A13. Not equal: A10 to A13 are skipped, and A15 and A16 are skipped after A14 (a loser never sets bits 41:39 of `0x1_101d_0100`) | established (test); the relation of the two registers is unknown |
| A10 | `0xffc4ea00` | W64 `0x8000_0081_5003_1550` | 0 | plain storage | established |
| A11 | `0xffc4ea06` | W64 `0x8000_0081_5003_1540` | 0 | plain storage | established |
| A12 | `0xffc4ea10` | W64 `0x8000_0081_5003_1560` | 0 | plain storage (this word is later the debug-switch word) | established |
| A13 | `0xffc4ea40` | W64 `0x8000_0081_1006_0480` | 1 | accepted (this is `SH1_IPI_ACCESS`; the header gives the register no layout, so the meaning of 1 is unknown) | established (access) |
| A14 | `0xffc4e766` | R64 `0x8000_0081_101d_0080` | compared with v again (the second check, `0xffc4e730`) | must read v again. Not equal: A15, A16 are skipped | established |
| A15 | `0xffc4e790` | R64 `0x8000_0081_101d_0100` | whole word | any value; the other bits are kept | established |
| A16 | `0xffc4e7a0` | W64 same address | A15 with bits 41:39 set to 7 | plain storage satisfies it. An earlier reading says the L1 start checks bits 41:39 for 7; a later review did not find a reader that does, so the read-back requirement is unconfirmed | established (access); inferred (any requirement) |

Then the progress write for reason 0, P(48): A17 (`0xffc4e5c6`, R64 history), A18 (`0xffc4e5e0`, W64), A19 (`0xffc4e656`, W16 LED A), A20 (`0xffc4e6d0`, W16 LED B). SAL_A then branches to the SAL_B reset entry at `0xffa01000`. (The same address pattern with code 56 or 59 is used for reasons 1 and 2.)

### 2. SAL_B reset entry (`0xffa01000`, a branch to `0xffa1de00`)

| # | Site | Access | Value, fields | What the code needs | Grade |
|---|---|---|---|---|---|
| A21 | `0xffa1dfb6`, `0xffa1dfd0`, `0xffa1e046`, `0xffa1e0c0` | P(49): R64 and W64 history, two W16 LED stores | code 0x31, in physical mode (`psr.i` and `psr.dt` cleared around each) | as P(c) | established |
| A22 | `0xffa94d06` | W64 `0x8000_0081_1006_0280` | `0x1_0000_0000` | accepted | established (access) |
| A23 | `0xffa94d20` | W64 `0x8000_0081_101c_0000` (the real-time clock) | 0 | accepted; the clock restarts from zero (inferred: the counter reads small values afterwards) | established (access) |
| A24 | `0xffa94d26` | W64 `0x8000_0081_1006_0280` | `0x1_0000_0041`: bit 32, bit 6, bit 0, and the field in bits 13:4 = 4 | accepted. After it the clock must advance and the field gives the tick period (see [the real-time clock](#the-real-time-clock)) | established (access); inferred (bit meanings other than the field) |
| A25 | `0xffa1d4b0` | R64 `0x8000_0081_5003_1550`, in `0xffa1d430` (called at `0xffa9ac9c`) | tests bit 21 + n (n the slice) | bit clear: the PROM keeps the PAL entry point it was handed. Bit set: it translates the entry through its RAM tables. A10 zeroed the word on the winner, so the bit reads 0 | established (test); inferred (meaning of the bit) |
| A26 | `0xffac42d0` to `0xffac62e0` | 18 read sites, each R64 `0x8000_0081_1006_0580`; the code uses bits 42:32 only (the node id) | the pointer-table builder forms node-window addresses from it | any NASID; stays constant | established |
| A27 | `0xffa1e450`, `0xffa1e496`, `0xffa1e540`, `0xffa1e5e6` | P(53): history R64 and W64, two LED W16 | code 0x35 | as P(c) | established |
| A28 | `0xffa1e61c` | lock cycle L(1) that sets bit 21 + n of `0x8000_0081_5003_1550` (`0xffa0eae0`, to `0xffa0e730`) | see "the node lock" below | the lock reads 0; the word reads back what was stored | established (sequence); inferred (meaning of the bits) |
| A29 | `0xffa1e63c` | the same cycle for bit 35 + n | as A28 | as A28 | established (sequence) |

### 3. `main()` before the console start (`0xffa19a20`, the compiler placed blocks out of order, so the sequence is the phase order: inferred)

| # | Site | Access | Value, fields | What the code needs | Grade |
|---|---|---|---|---|---|
| A30 | `0xffa0dd60` (called at `0xffa19a4c`) | R64 `0x8000_0081_1006_0580`, then extract bits 42:32 | the NASID | any value; every later global-window address is formed from it, so the node's global window at that NASID must decode to this node | established |
| A31 | `0xffa0ddb0` (call at `0xffa19b8c`) | P(8) | code 8 | as P(c) | established |
| A32 | `0xffa99cf0`, called at `0xffa19b9c` | the local-master arbitration, phase 0xc: A30 again (at `0xffa99d1c`), P(12) (at `0xffa99d4c`), then A33 to A36 | | | established (read in full by batch 3; accesses re-read) |
| A33 | `0xffa115ac` (called at `0xffa99e2c`) | R64 `0x8000_0009_2002_0080 + (nasid << 38)` (global window), for each slice 0 and 1 that is not the running processor's; the code takes bit `slice` | one bit per slice | bit 0 for every slice but the running one on a single-processor node. If a bit reads 1 the PROM counts that processor and waits for it in A35 | established (access); inferred (bit = processor present) |
| A34 | `0xffa99dcc`, `0xffa99dfc` | two lock cycles: write a 3-bit field of the word `0x8000_0081_5003_1550` at bit 47 or 50 (`0xffa0eb10`, `0xffa0e9e0`), and set bit 26 + slice (`0xffa0eae0`) | | the lock reads 0; the word reads back as written | established (sequence); inferred (meaning) |
| A35 | `0xffa99f80`, `0xffa99ff0` | polling loops: R64 `0x8000_0081_5003_1550` through `0xffa0ecd0`, bit 26 + i for i = 0 to 3, with a 500-microsecond wait (`0xffa0db90`) between rounds, until the bits for the other present processors are set, with a deadline of 5,000,000 microseconds | | with no other processor present the loop ends on the first round | established (loop); inferred (timeout outcome) |
| A36 | `0xffa9fba0` | A30 and a comparison with the running slice; no other MMR access | | | established |
| A37 | `0xffa9a130` (call at `0xffa19ba0`) | a second barrier on the same word: lock cycles that set bit 30 + slice and bit 34 and clear them again, and polling reads of bits 34, 30 + i and 26 + i (`0xffa0ecd0`) until bit 30 + i equals bit 26 + i for all four i (the `r35 == 4` test at `0xffa9a290`) | | after a store the word must read back what was stored. All zero except the own slice's bits also passes | established (sequence); inferred (role) |
| A38 | `0xffa0ddb0` (call at `0xffa19bbc`) | P(13) | code 0x0d | as P(c) | established |
| A39 | `0xffa0be1c`, reached from `0xffa197f0` (call at `0xffa19bdc`) through `0xffa0f8c0` | R64 `0x8000_0009_0000_0000 + (nasid << 38)` | the chip identification word at offset `0x1_0000_0000` (global window); bits 27:12 stored as the node's part number, bits 31:28 as its revision | a bounded read (must not fault). The routine at `0xffa0f8c0` stores bits 27:12 in the node object, and `0xffa0f7e0` then offers it to each of four method tables in turn (array at `0xffbd8a18`, four entries and a null terminator); the first table whose method 1 returns non-zero is stored at object offset 32. Method 1 accepts one part number each: 17251 (`0x4363`, first table, `0xffa959a0`), 12311 (`0x3017`, `0xffa948d0`), 569 (`0x239`, `0xffa949e0`) and 17442 (`0x4422`, `0xffa97ce0`). A miss stores 0, `main` ignores the result, and two later callers (`0xffa0b270`, `0xffa0b950`) call through `[obj + 32] + 360` or `+ 408` with no null test, so any other part number calls through a null table. Which chips the other three numbers belong to is **unknown** | established (access, the chain and the four compares, all read); inferred (that the field is a part number) |
| A40 | `0xffa1f430` (`sysctl_init`, call at `0xffa19c0c`) | A30 again, then the L1 start. This is where this page stops | | | established |

The routines above reach SHub registers through three small accessors that appear in the lists: a 64-bit load `0xffa0e5a0` and a 64-bit store `0xffa0e640` (plain `ld8` and `st8` on a physical address, in physical mode), and the node-object read `0xffa0bd20`, which for the local node (first argument 0) forms the global-window address from a NASID and an offset and does one `ld8`. The `main()` calls through operation tables (`0xffa1a910`, the object operations behind `[obj + 32]`) are not resolved statically: which registers they touch, and the exact order of the first L1 console accesses, are listed under [What was not traced](#what-was-not-traced).

### The node lock (used by A28, A29, A34 and A37)

The routine that takes the lock is `0xffa0ed30` (read in full); `0xffa0e730` wraps it around a read-modify-write of `0x8000_0081_5003_1550`, and `0xffa0ee40` releases it. One cycle issues, in order:

1. R64 `0x8000_0081_1003_0000 + 0x80 * (slice & 3)` (`0xffa0e020`; the value's low byte is later written as a progress code, so any value is accepted; its meaning is **unknown**).
2. R64 `0x8000_0081_101c_0000` (the counter), then R64 `0x8000_0081_1006_0280` (the tick period), both in the routine at `0xffa0da70` that returns the clock time in microseconds. The deadline check after each poll in step 3 repeats both reads.
3. R64 `0x8000_0081_101d_0208`, repeated with a 1,000-microsecond delay (`0xffa0fc90`, which passes 1000 to `0xffa0db90`) until it reads 0, with a deadline of 1,000,000 microseconds on the clock; on timeout the PROM writes 0 to `0x8000_0081_101d_0200` and keeps polling.
4. P(low byte of step 1's value): R64 and W64 history, two LED stores.
5. R64 `0x8000_0081_5003_1550`, W64 the same address with the bit or field changed.
6. W64 `0x8000_0081_101d_0200` with 0 (release, `0xffa0ee40`).

What the code needs (established as the test, **inferred** as hardware behaviour): `0x1_101d_0208` reads 0 when the lock is free and, if it is a hardware lock, a read that returns 0 takes it, and a write of 0 to `0x1_101d_0200` frees it. A plain register pair where `0x208` always reads 0 satisfies every access read. If `0x208` read non-zero forever the PROM would loop forever; the forced write of 0 to `0x200` is its only recovery. Whether a read has a side effect in the chip is **unknown**.

The word `0x1_5003_1550` is the PROM's own storage (inferred, from its use): bits 21 to 24 (21 + slice), 26 to 29 (26 + slice), 30 to 33 (30 + slice), 35 to 38 (35 + slice) and bit 34, and a 3-bit count at bit 47 (even slice) or bit 50 (odd slice), which each present slice publishes from a PAL call and the master waits for as that many ready bits among 29:26 (inferred; a reviewer's reading of the local-master wait). It must read back what was written and read 0 before the first write (A10 or the loser's undefined value). Bits 29:26 are the "other processor flagged" bits that SAL_A's error path clears.

### The second lock pair and the flag word (not on the direct-call path)

The chip object's method tables (see A39) hold routines that use a second lock pair, `0x1_101d_0188` (status, polled until it reads 0) and `0x1_101d_0180` (released by writing 0), around read-modify-writes of `0x1_5003_1540`. All of this was read in full; whether any of it runs before the console start is **unknown**, because the callers are indirect.

| # | Site | Access | What the code does | Grade |
|---|---|---|---|---|
| B1 | `0xffa0ed30` (take, this node), `0xffa0ee40` (release) | R64 `0x8000_0081_101d_0188` until the whole word reads 0, then W64 0 to `0x8000_0081_101d_0180` at release | the same routine as the node lock, with these two addresses: 1,000,000-microsecond deadline, then a forced write of 0 to `0x180` and polling continues | established (sequence); inferred (meaning) |
| B2 | `0xffa0ee90` to `0xffa0ad80` (take, another node), `0xffa0eee0` (release) | R64 offset `0x1_101d_0188` through the node-object read, repeated until bit 0 is clear (the other bits are ignored); W64 0 to offset `0x1_101d_0180` through the node-object write at release | the deadline is the caller's (1,000,000 microseconds in the callers read); on timeout it returns -9 and does not write `0x180` | established (sequence); inferred (meaning) |
| B3 | `0xffa0efd0` (claim bit n), `0xffa0f580` (clear bit n) | under B1: R64 `0x8000_0081_5003_1540`, W64 the same address with bit n set or cleared | claim waits until the bit reads clear (a deadline argument of 0 means no deadline; a miss returns -1), test-and-sets it under the lock and releases; clear takes the lock, clears the bit and releases. Reads of the bit before the lock are unlocked | established (sequence); inferred (role) |
| B4 | `0xffa0f1a0`, `0xffa0f430` (claim), `0xffa0f3a0` (test, no lock), `0xffa0f650` (clear) | the same on another node: offset form `0x9_5003_1540 + (nasid << 38)` (global window) with B2 | as B3 | established (sequence); inferred (role) |
| B5 | `0xffa5d48c` | W64 0 to offset `0x1_5003_1540` of another node through the node-object write (and 0 to `0x1_5003_1550` at `0xffa5d44c`), in an interconnect-phase routine | plain storage | established (access) |
| B6 | `0xffa974d0` (setter, called at `0xffa1a51c` and `0xffa1a58c` with a field width of 16) | under the node lock (`0x208` and `0x200`): R64 `0x8000_0081_5003_1560`, W64 the same address with a bit field replaced by a 16-bit argument | take, read, clear the field, OR in the value, write, release (R64 `0x208` until 0, W64 0 to `0x200`) | established (sequence); inferred (role) |

A model that treats `0x188` as a status that always reads 0 (bit 0 clear is enough for B2), `0x180` as write-accepting storage and `0x1540` and `0x1560` as plain storage satisfies every access above. The this-node claim and clear are entered through small thunks (`0xffa0f750` and `0xffa0f780` for the claim, the second passing a deadline of 0; `0xffa0f7b0` for the clear); no caller or descriptor for the thunks was found. The other-node routines are reached through descriptors at `0xffc4bc10` to `0xffc4bdc0` that belong to the method tables.

## Accesses not on the reset path

SAL_A has two more groups that run only on other reasons, kept here so the access list is complete.

- **Reason 1 (machine check) or 2 (INIT), SAL_A end (`0xffc4e570`).** R64 `0x8000_0081_1003_0000 | ((slice & 3) << 7)` into `r31` before branching to SAL_B offset `0x20` or `0x10`. A reason above 3 makes the same read before its hang (code 177). Reason 0 does not make this read: its branch to `0xffc4e580` skips it (`cmp.eq p6=0,r3` at `0xffc4e4d0`, `(p6) br` at `0xffc4e4fc`). This corrects [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#sal_a-on-shub-1), which lists the read for reason 0 as well.
- **SAL_A error path (`0xffc4e090` to `0xffc4e2d0`),** taken only if bit 2 of `r35` is set and its low two bits are not zero (PAL reports a fault). P(176): R64 and W64 history, W16 LED A and LED B; then RMW of `0x8000_0081_5003_1550` clearing bits 29:26; RMW of `0x8000_0081_101d_0080` ORing `0x280_0000_0000`; W64 `0x8000_0081_2000_0000` (`SH_CRB_MESSAGE_CONTROL`) with `0x1_0001_0000_0000`; then a spin. The SAL_B reset entry has a similar path for a non-zero reason argument (code 179, `0xffa1de06` to `0xffa1df7c`: P(179) then a spin).
- **Memory controller set-up (after this page's end), three accesses missing from the first register batch.** W64 `0x8000_0009_0003_0400 + (nasid << 38)` and W64 `0x8000_0009_0005_0400 + (nasid << 38)`, each with `0x1000`, at `0xffa773fc` and `0xffa7742c`, between the control-register write (`0xffa773cc`) and the `0x1_0001_0058` write; neither is read anywhere. R64 `0x1_0001_0068` at `0xffa7ab6c` and W64 of a caller-supplied 32-bit value at `0xffa7acdc` and `0xffa7ad9c`, by a routine that returns untouched when `cpuid[2]` equals `0xaeeeeeee8badbeef`, the constant also noted under [the real-time clock](#the-real-time-clock). All three registers are plain storage as far as the code shows; roles unknown.

## Registers touched

For each register: where the PROM sees it, the unit by address block, the Linux name, what a read must return, the grade of that requirement and the reset value. "Reset" is the value the PROM can rely on before its own first write; every entry is *unknown* because no document gives it, and the entry says what the code tolerates or requires.

| Address (local form; `0x1_...` is the node offset) | Window and unit | Linux v5.3 name or our label | What a read must return | Grade |
|---|---|---|---|---|
| `0x81_1006_0580` | local, LB | `SH1_SHUB_ID` (unnamed fields besides revision: labels below) | bits 42:32 any NASID; bits 31:28 revision, either side of 2 accepted (above 2 chooses `0x3b03f7` and `0x4047`, 2 or below `1009` and `0x4045`); the whole word reads back what the PROM stores (see [the SHub ID register](#the-shub-id-register)) | established (reads); inferred (what hardware returns) |
| `0x81_1002_0000` | local, LB | unnamed; label `lb_reg_1002_0000` (ours) | never read in this phase | established (the write) |
| `0x81_2001_0100` | local, PI | unnamed; label `pi_reg_2001_0100` (ours) | bit 24 settable; any other bits kept; reads back as written | established (access); inferred (role) |
| `0x81_2001_0180` | local, FSB | `SH_FSB_VGA_REMAP` (SGI 2.4 SN2 header, established; key `fsb_vga_remap`) | read once, at `0xffaeb22c` in `0xffaeb1f0` (SAL_B, after the shadow copy, called at `0xfface6fc`), then written back with bits 60:49 cleared and bits 35:24 of the masked copy-destination word placed at bit 49 (zero on the stock path); no test; any value, reset 0 per the header's INIT. The `r33 = 7` at that read is a stale caller register, not an argument | established (access); inferred (stock value 0) |
| `0x81_5003_1500 + 16*n` (n = 0 to 3), `1510`, `1530` | local, XN block | `SH_XN_MD_IILB_CMP_EXP_DATA0`, `_DATA1`, `_ENABLE0`, `_ENABLE1` at `1500`, `1510`, `1520`, `1530` (SGI 2.4 SN2 header and the SHub 1 PROM's own name table, established); label `cpu_hist` (ours) | the PROM uses these four debug-compare registers as plain 64-bit storage; reads what was last written | established (use and names); inferred (storage) |
| `0x81_5003_1540`, `1550`, `1560` | local, XN block | `SH_XN_MD_NI0_CMP_EXP_DATA0`, `_EXP_DATA1`, `_ENABLE0` (SGI 2.4 SN2 header and the SHub 1 PROM's own name table, established); label `cpu_bits` for `1550` (ours); `1560` is later the debug-switch word | plain 64-bit storage, 0 after SAL_A's winner writes them; `1540` is also read-modify-written as a set of flags under the second lock pair (B3, B4), and `1560` as a bit field under the `0x200` lock (B6) | inferred |
| `0x81_101d_0180`, `0x81_101d_0188` | local, LB | unnamed; labels `lb_lock2` and `lb_lock2_status` (ours) | `0x188` reads 0 when free (bit 0 clear for the other-node form); `0x180` accepts 0 | established (test); inferred (behaviour) |
| `0x81_101d_0080`, `0x81_101d_0088` | local, LB | `SH_SCRATCH1` and `SH_SCRATCH1_ALIAS` (2.4 header) | after a write of v to `0x88` a read of `0x80` returns exactly v, twice; `0x80` is also read-modify-written at bits 39 to 41 later | established (test); alias is not clear-only (established), store-through or OR (inferred) |
| `0x81_101d_0100` | local, LB | unnamed; label `lb_l1_state` (ours; the PROM's own names for the same word are `sc_shub_state_reg` and `sc_shub_pushed_data_reg`) | bits 41:39 read back as written (7) after A16 and the other bits are kept; no reader that requires 7 was found | established (access); inferred (any requirement) |
| `0x81_101d_0200`, `0x81_101d_0208` | local, LB | unnamed; label `lb_lock` (ours) | `0x208` reads 0 when free; `0x200` accepts 0; the same pair also guards the `1560` field setter (B6) | established (test); inferred (behaviour) |
| `0x81_1003_0000 + 0x80*(slice & 3)` | local, LB | unnamed; label `lb_slice_rec` (ours) | any 64-bit value; the low byte becomes a progress code | established (read); unknown (meaning) |
| `0x81_1006_0480` | local, LB | `SH1_IPI_ACCESS` | accepts 1 | established |
| `0x81_1006_0280` | local, LB | unnamed; label `rtc_ctl` (ours) | reads back the stored value (bits 13:4 give the tick period); written before its first read | established (use); inferred (bit roles) |
| `0x81_101c_0000` | local, LB | `SH1_RTC` | accepts a write of 0, then a 55-bit counter that advances. When `cpuid[2]` equals `0xaeeeeeee8badbeef` (the PROM's clock-time routine `0xffa0da70` and the runtime's `chipset_rtc_time` test it, apparently a simulator marker: inferred) each counter tick counts as 128 in the time calculation (shift left by 7 before scaling, re-read at `0xffa0dad6`); the runtime's `salruntime_freq_base` tests the same value only on its clock-type-0 (platform base) path, not on the real-time-clock path, which answers `1e9 / period` for any CPU (re-read in the follow-up review) | established (access); inferred (the marker's meaning) |
| `0x87_fed0_0000` + `N*0x10000` (N = 0 to 3) | local junk bus | `SH1_REAL_JUNK_BUS_LED0` to `LED3` | 16-bit writes accepted; not read | established |
| `0x9_2002_0080 + (nasid << 38)` | global, PI | unnamed; label `pi_slice_present` (ours) | bit `slice` clear for every slice but the running one; later CPU-enumeration callers of the same word read bits 0 and 1 (first processor of slices 0 and 1) and bits 4 and 5 (second processor), and the own-slice bit they expect was not traced, so a model should set it | established (access); inferred (meaning) |
| `0x9_0000_0000 + (nasid << 38)` (offset `0x1_0000_0000`) | global, MD block by address | unnamed; label `chip_id_word` (ours) | bits 27:12 = `0x4363` (software expectation: selects the first method table; `0x3017`, `0x239` and `0x4422` select the others, any other value calls through a null table) and bits 31:28 the revision | established (access and requirement); inferred (meaning) |

## Reset values

For each register the PROM reads before it writes it (in this phase), and what the code allows. Nothing here is a reset value in the hardware sense.

| Register | Read before first write? | What the PROM tolerates or needs | Reset value |
|---|---|---|---|
| `0x1_2001_0100` | yes (A2) | keeps whatever it reads; bit 24 must be settable | unknown (the PROM tolerates any value) |
| `0x1_5003_1510`, `1530` | yes (A4, A6) | data for an LED write only | unknown (any value; 0 gives histories made only of codes) |
| `0x1_5003_1500 + 16*n` | yes (A17: the history shift) | any; the shift keeps the old value in bits 63:8 | unknown (any; 0 is clean) |
| `0x1_101d_0080` | yes (A9) | after A8 it must read v; if hardware leaves a stale value there, A8 must replace it | unknown (requires: the value written at `0x88` is visible) |
| `0x1_101d_0100` | yes (A15) | keeps the other bits; no reader that requires 7 in bits 41:39 was found | unknown (the PROM tolerates any other bits) |
| `0x1_5003_1540`, `1550`, `1560` | no for the winner (A10 to A12 are first); yes for a loser | winner zeroes them; a loser reads whatever is there | unknown (a model that zeroes at reset behaves as the winner would leave it) |
| `0x1_1006_0580` | yes (A30) | any NASID, any revision (the revision picks between two constants) | unknown (see [the SHub ID register](#the-shub-id-register)) |
| `0x1_101d_0188` | yes (B1, B2) | 0 to proceed (bit 0 clear on another node); non-zero is waited out for 1,000,000 microseconds, then forced on this node or -9 on another | unknown (requires: reads 0 eventually) |
| `0x1_101d_0208` | yes (the lock) | 0 to proceed; non-zero is waited out for 1,000,000 microseconds, then forced | unknown (requires: reads 0 eventually) |
| `0x1_1003_0000 + 0x80*slice` | yes | any value | unknown (any) |
| `0x1_2002_0080` | yes (A33) | bit of each other slice must be 0 for a one-processor node | unknown (requires bit 0 for the other slices) |
| `0x1_0000_0000` | yes (A39) | `0x4363` in bits 27:12 (or one of `0x3017`, `0x239`, `0x4422`, which pick other method tables); anything else calls through a null table | unknown (requires `0x4363` for the table the SHub 1 path is read with) |
| `0x1_1006_0280`, `0x1_101c_0000` | no: written (A22, A23, A24) before the first read | none | the reset value never reaches the PROM; unknown |
| `0x1_1002_0000`, `0x1_1006_0480`, `0x7_fed0_0000..3` | never read | none | unknown (not needed) |

## The SHub ID register

`0x1_1006_0580` (`SH1_SHUB_ID`) is read by the node-id routine at `main` start (A30, and again on later calls) and inline at 18 sites in the table builder (A26), and is written by a later routine at `0xffa95a30` (the node-object slot 33; the only direct call is `0xffa5f84c`, in the NUMAlink numbering path, after the jump to RAM, so outside this page's phase; read in full for this question; the call that matters on a lone node is the indirect one from `0xffa976e0`, [traced at the end of this page](#the-nasid-change-and-the-node-id-install-0xffacd2b0-to-main_three)). Linux v5.3 treats it as read only and names only the revision (bits 31:28; `SH1_SHUB_ID_REVISION_MASK`). The PROM's write, an `ld8` of the register through the node-object read, then `dep` into the value, then a 64-bit store through the node-object write, is:

- bits 42:32 replaced by the NASID argument;
- bits 45:44 replaced by 0, 1, 2 or 3, chosen from an argument (with bits 10:9 masked and the rest halved): 31 or below gives 0, 63 or below gives 1, 127 or below gives 2, more gives 3;
- bits 52:48 replaced by 1, 2, 4, 8 or 16, chosen from bits 16:1 of the fourth argument: 63 or below gives 1, 127 or below 2, 255 or below 4, 511 or below 8, more 16.

Every other bit is stored as read, so a model may keep them read only. The established facts are the field positions and the replacement values (the function was read in full). That bits 52:48 are the nodes-per-bit field is the Linux header's name for the same field (`SN_SAL_GET_SN_INFO` uses it as the region size, [SAL page](../../software/sal/README.md)). The meaning of bits 45:44 and of the argument that feeds them is inferred only; the PROM reads bits 45:44 back in memory-presence code (earlier reading, [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#node-board-identification-ip41-ip57-others)).

What a read must return:

- **Before the write** (every read in this phase): bits 42:32 any NASID (the global window of that NASID must decode to the node itself); bits 31:28 a revision; nothing in the code decodes bits 27:12 or 11:1 of this register (the part number the PROM checks comes from `0x1_0000_0000`, A39, not from here). No read on this page decodes bits 45:44 or 52:48.
- **After the write:** bits 42:32, 45:44 and 52:48 must read back as written; the NASID is used by every later global-window address.
- **Reset value: unknown.** The only constraint the code gives is that bits 42:32 hold a usable NASID before the first write. (Software expectation, so inferred at best for hardware: a model that resets the NASID to 0 and the revision to 3 satisfies every access read in this phase, and the interpreter trace in [node-bringup.md](../../software/firmware/snprom/node-bringup.md) assumed revision 3.)

## The real-time clock

Two registers matter. The counter `0x1_101c_0000` (`SH1_RTC`, 55 bits) and the configuration `0x1_1006_0280` (label `rtc_ctl`, ours).

- **Tick period, established.** Both the SAL_B routine at `0xffa0da00` and the SAL runtime component's `chipset_rtc_period` (the component's own symbol, runtime offset `0x61780`) compute the period in nanoseconds as `10 * (f + 1)`, where f is bits 13:4 of `0x1_1006_0280`. The time in microseconds is the counter times the period divided by 1000 (`0xffa0da70` and `chipset_rtc_time`); the delay routine `0xffa0db90` converts microseconds to ticks the other way and busy-polls the counter.
- **What the PROM writes, established.** A22 to A24: `0x1_0000_0000`, then 0 to the counter, then `0x1_0000_0041`. The field is then 4, so the period is 50 ns and the counter frequency 20,000,000 Hz. Later code in the interconnect phase (`0xffa967e6`, not in this page's phase) clears bit 0 and sets bits 33:32 to 1 in the register on a node, and one at `0xffa96626` reads bits 33:32, so bits 33:32 carry a mode, not part of the period. The roles of bit 0, bit 6 and bit 32 are **inferred only** (bit 0 clear then set around the counter write suggests a run control).
- **What SAL_FREQ_BASE answers, established.** In the SAL runtime component (type 0x12, `salruntime_freq_base`, the clock-type-2 path read for this page), the call with clock type 2 (the real-time clock) returns status 0 and `1,000,000,000 / period` (integer division). With the PROM's own write the answer is 20,000,000. The Linux kernel accepts any value of 100 kHz or more; its fallback guess is 1e12/30000 (about 33.3 MHz). So Linux's assumption is the failure case; the value the PROM reports is 20 MHz **if the field in `0x1_1006_0280` is what the PROM wrote**. A model that keeps the stored word and advances the counter once per 50 ns produces exactly that. Whether the real chip's counter does tick every 50 ns once the field is 4 is **inferred** (the PROM's formula and the write are the evidence; no document states it).
- **Writes and resets of the counter.** The PROM writes the counter in three places that were read: A23 (reset entry), a write of 0 through the global window at `0xffa961e6` (`0x9_101c_0000 + (nasid << 38)`, interconnect phase) and a generic write of an argument value at `0xffa96796`; it reads the counter on every delay and timeout. The counter's value at power-on is **unknown**; the PROM overwrites it with 0 at the reset entry before it first reads it.
- **A zero field.** If a read of `0x1_1006_0280` returned 0, the PROM would assume a 10 ns period, so the counter would have to advance at 100 MHz. Every deadline in the PROM (the 500-microsecond steps, the 1,000,000 and 5,000,000 microsecond waits, the 20,000,000 microsecond memory-test deadline) is in microseconds and is scaled by this period, so a counter that ticks at a different rate from the field stretches or shrinks them by the ratio. [node-bringup.md](../../software/firmware/snprom/node-bringup.md) calls these deadlines ticks; they are microseconds, as its review says.
- **What would settle the rest:** the SHub 1 programmer's reference for the local block (the register at `0x1_1006_0280`), or a hardware read of the register after a known write.

## The PIO write-error self test: store to `0x1_1005_0608` (`0xffa24cc0`)

Snprom 10.54 `shub1snprom.bin`, Ghidra IA-64 `--sn2-prom --no-analysis` with an `ia64-linux-gnu-objdump` cross-check. Established as code unless marked. Runs right after the op 80 loop: `main_two` call `0xffa1af8c` to the stub `0xffa3dc60`, `0xffa3dc70` (per-slice node set-up; call at `0xffa3dfcc` after the slice barrier `0xffa9a130`, on every slice), `0xffae2f80` (call at `0xffae306c`), `0xffa24cc0`. Only gate: `cpuid[2]` equal to `0xaeeeeeee8badbeef` skips it; no revision, port or slice test. The routine is the PROM's `pio_wt_st_force_err`.

| Step | Site | Access |
|---|---|---|
| 1 | `0xffa23e00(0)` | write 0 to the local interrupt enable registers (`0x7ef` back at the end) |
| 2 | `0xffa24dec` (store routine `0xffa0e640`) | W `0x1_1005_0608` = 0 (explicit argument, `mov r42=r0`); the offset has no register, the store is meant to fail (inferred) |
| 3 | `0xffa24e20` to `0xffa24e5c` | read this slice's `pio_write_status` (table `0xffbd9678` indexed by `cr.lid` bits 26:23: slices 0 and 1 share `0x1_2007_0200`, slices 2 and 3 share `0x1_2007_0280`) until `(v & 5) != 0`; no delay, no deadline |
| 4 | `0xffa24ac0` | W `0x3fffffffffffd` to the alias (`0x1_2007_0208`), then up to 1001 reads of the status, each followed by a 100-count spin of the bare down-counter `0xffa10010` (not microseconds), until bits 61:56 are all ones; exhaustion is silent |
| 5 | `0xffa24ea8`, `0xffa24ee8`, `0xffa24f4c` after a 600-count spin of `0xffa10010` | R `0x1_1005_0280`: `(v & 0x3fffffff) == 0x2200a0c1` (the address >> 3) gives mask 8; R `0x1_2006_0500`: `(v & 0x1_ffff_fff8) == 0x1_1005_0608` gives mask 1; R `0x1_1005_0200`: low byte `0xe9` or `0xea` gives mask 8 |
| 6 | `0xffa30b40(nasid, mask)` | only if the mask is non-zero (the error-clear lists above); then `0xffa23e00(1)` |

A model needs: the store sets bit 2 of that slice's status (the header's write error; bit 0 is the multiple-error bit); the status reads count `0x3f` in bits 61:56 throughout; the alias write clears the error bits. Slices of a pair share one status register and each stores to `0x608`, so the second error may show as bit 0 (multiple errors); either bit ends the poll. Zero for the three detail reads is accepted (mask 0, nothing else runs). Plain storage for `0x608` hangs step 3. The status bits are from the 2.4 SN2 header; the error mechanism and the detail contents are not documented (inferred).

### Review (PIO write-error self test, commit 7c120ec)

Independent re-read in Ghidra (IA-64 module, `--sn2-prom --no-analysis`) with `ia64-linux-gnu-objdump` as a cross-check, plus the 2.4 SN2 header (`shub_mmr.h` at 8ef7d46c).

- **Confirmed.** The chain `0xffa1af8c`, `0xffa3dc60` (a nop bundle falling into `0xffa3dc70`), call `0xffa3dfcc`, `0xffae2f80`, call `0xffae306c`, `0xffa24cc0`; the master slice takes a detour through `0xffa21350` and rejoins before the barrier, so every slice reaches the call; the skip on cpuid[2] equal to `0xaeeeeeee8badbeef` is the only gate; `mov r42=r0` at `0xffa24de6` is the value argument of the store call at `0xffa24dec` (address `0x1_1005_0608` in the local window); the unbounded poll on `(v & 5)`; the 1001-read loop of `0xffa24ac0` testing bits 61:56 against `0x3f`, silent on exhaustion; the `0x3fffffffffffd` alias write; the three compares (`(v & 0x3fffffff) << 3` equals `0x110050608`, which is the page's `0x2200a0c1` form; `0x1_2006_0500` masked with `0x1fffffff8`; low byte of `0x1_1005_0200` minus `0xe9` below 2) with masks 8, 1, 8; `0xffa30b40(nasid, mask)` only for a non-zero mask (it walks the set bits through the pointer table at `0xffbdd010`). Header: `SH_PIO_WRITE_STATUS_0` mask `0xbf03ffffffffffff`, INIT `0x8000000000000000`, multi write error bit 0, deadlock bit 1, write error bit 2, error address bits 49:3, count bits 61:56, writes ok bit 63; `SH_PI_ERROR_DETAIL_1` at `0x1_2006_0500`, mask all ones, INIT 0, one 64-bit status field. `0x1_1005_0608` is absent from the header (`SH_LB_FIRST_ERROR` is `0x1_1005_0600`) and from the PROM name table at `0xffbfb460`, which has `0x600` then `0x680`.
- **Changed.** The delays were called 100 and 600 microseconds. `0xffa10010` is a bare down-counter with no clock read, so they are counts of a short spin; the page now says so (the timeout bookkeeping is unaffected). The slice-to-status mapping was given as slice 0 and slice 1 using `0x200` and `0x280`; the tables at `0xffbd9678` and `0xffbd9698` have the pattern 0, 0, 1, 1 (slices 0 and 1 share `0x200`/`0x208`, slices 2 and 3 share `0x280`/`0x288`). The store routine is `0xffa0e640` (its `st8` sits in the bundle at `0xffa0e650`).
- **Tail call.** `0xffa25340` ends with `br.many 0xffa24cc0` (at `0xffa2544c`) when the slice's status count is not all ones, and with a tail branch to `0xffa24ac0` (the clear) when the count is all ones and `(v & 5)` is set. Its two callers `0xffa21afc` and `0xffa21cec` are in `0xffa217c0`, called from `0xffa02ff0` (the interrupts page reads that as machine-check and INIT handling) and by a branch from `0xffa21db0`. No direct-call path from `main` or `main_two` reaches it, so it does not run in the boot trace; inferred, because indirect callers were not searched.
- **Not checked.** Linux v5.3 absence of an LB block (only the 2.4 header was searched); the header names for the interrupt-enable table at `0xffbd9588` (step 1); the meaning of `0xffa0f780(0xd)` and `0xffa0f7b0(0xd)`, which wrap the call in `0xffae2f80`.

## What was not traced

The page covers the accesses found by reading every function reachable by direct calls from the reset entry and from `main` up to `sysctl_init`. Four things are left, none of them a gap in the accesses listed above:

- Calls through operation tables and function descriptors (`0xffa1a910`, the node-object operations behind `[obj + 32]`, PAL calls) were not followed. A different register may be touched there. The L1 start-up, which this page ends at, is reached through them.
- The exact order of the first L1 console accesses (UART at `0xf_fed4_0000 + 8*n` in the global form, or `0x7_fed4_0000 + 8*n` local; the state word `0x1_101d_0100`) is from [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#l1-controller-dependency), not re-read here.
- Which error and workaround routines run at the reset entry or in `main` before `sysctl_init` depends on PAL return values the code does not show; the accesses on the normal path are listed.
- The roles of `0x1_1002_0000`, `0x1_2001_0100`, `0x1_1006_0280` bits other than the period field, `0x1_1003_0000 + 0x80*slice`, the bit meanings in `0x1_5003_1550`, and what a hardware read of `0x1_101d_0200`, `0x208`, `0x180` and `0x188` does: **unknown**. A SHub 1 programmer's reference for the local block, the processor interface and the network interface block would settle them; a hardware read is the last resort and needs the repository owner's approval.

## Corrections to earlier pages

- [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#sal_a-on-shub-1) step 7 says SAL_A reads `[0x81_1003_0000 + (slice & 3) * 128]` for reason 0. It reads it only for reasons 1 and 2, and for a reason above 3 (above).
- The part number and revision the PROM stores for a node come from `0x1_0000_0000` (A39), not from the SHub ID register; the earlier page's inference that the SHub ID register carries the widget-ID layout is not supported by this reading.

## Review (PROM reset accesses and the two register batches)

Independent review of chips commits `ded2531` (this page), `510fdfe` (the registers SAL_A and the SAL_B reset entry use) and `0df84c4` (the single-node bring-up registers), examined at chips `5423b96`. The reviewer wrote none of it. Method: a fresh `ia64-linux-gnu-objdump` listing (physical addresses, `-z`) of `shub1snprom.bin` (sha256 `51ccf9ad...3a34617`, matches the page) over SAL_A and all of SAL_B (`0xffa00000` to `0xffc4e000`), and of the SAL runtime component (FIT type 0x12, gunzipped, 918,824 bytes) for the symbols `salruntime_freq_base`, `chipset_rtc_period` and `chipset_rtc_time`. Every register offset in both TOML commits was searched for in the listing as a `movl` constant (local, global-window and node-offset forms), and each cited site was read in context. Linux names were checked against `shub_mmr.h`, `sn_sal.h` and `setup.c` at v5.3, fetched as single files. `generated/c/shub.h` was checked with a script against the TOML (offset of every register, shift and mask of every field), and `defs-gen` was re-run to confirm the generated files are reproducible.

**Confirmed (re-read in the binary).**

- Election (A8, A9, A14): `st8.rel` of slice + 1 to `0x1_101d_0088`, then `ld8.acq` of `0x1_101d_0080` compared with it; `cmp.eq p0,p6` sends a mismatch to the skip path, so equal means winner and A10 to A13, A15 and A16 run only for it. A1 value `0x15031010`, A3 bit 24, A13 value 1, A16 `dep` of 7 at bit 39 width 3, and the LED stores A5 and A7 (value ORed with `0x60`, 16-bit) are as listed.
- The lock: the routine at `0xffa0ed30` takes the two addresses as arguments (`0x1_101d_0208` and `0x1_101d_0200` from `0xffa0e730`); it reads `0x208`, branches to the success path when the value is 0 and otherwise delays, re-reads the clock and, once the clock passes the deadline of start + 1,000,000 microseconds, writes 0 to `0x200` and polls again. After success it writes the progress code from the `0x1_1003_0000 + 0x80 * slice` word, the caller does the read-modify-write of `0x1_5003_1550` and the release routine `0xffa0ee40` writes 0 to `0x200`. A read of 0 acquires, as the page says.
- `0x1_2002_0080` (A33): `0xffa11560` does one `ld8` of `0x8000_0009_2002_0080 | nasid << 38` and returns `(value >> slice) & 1`. The caller loops slice 0 and 1; a slice equal to the running one is counted without a read, every other slice is read, and a set bit counts a processor and adds it to the wait mask. The page's reading holds.
- SHub ID (`0x1_1006_0580`) write routine `0xffa95a30`: a 64-bit read, `dep` of the NASID argument into bits 42:32 (`dep ...,32,11`), of a size code into bits 45:44 (`dep ...,44,2`) and of 1, 2, 4, 8 or 16 into bits 52:48 (`dep ...,48,5`), and a 64-bit write; no other bit is touched, so "other bits stored as read" holds. The thresholds are as the page says: for 45:44, argument with bits 10:9 cleared and halved, at most 31 gives 0, 63 gives 1, 127 gives 2, more gives 3; for 52:48, bits 16:1 of the fourth argument, at most 63 gives 1, 127 gives 2, 255 gives 4, 511 gives 8, more gives 16. The write is skipped if the read returns a negative status. Access is the node-object read and write (`0xffa0bd20`, `0xffa0c560`), which form `0x8000_0009_0000_0000 | offset | nasid << 38` for a local-node object; the revision split in the memory-presence code (`extr.u ..,28,4`, then `cmp.ltu` against 2: above 2 gives `0x3b03f7` and `0x4047`, 2 or below gives `0x3f1` and `0x4045`) is as listed. The 18 inline read sites run from `0xffac42f6` to `0xffac6156`.
- RTC: the write sequence at `0xffa94d06`, `0xffa94d20`, `0xffa94d26` is `0x1_0000_0000` to `rtc_ctl`, 0 to the counter, `0x1_0000_0041` to `rtc_ctl`; the routine is called from the reset entry at `0xffa1e130`, after progress code 49 and before code 53. Both `0xffa0da00` and `chipset_rtc_period` do `extr.u r8,4,10`, times 5, times 2, plus 10: period in nanoseconds is 10 * (f + 1), so f = 4 gives 50 ns. `0xffa0da70` and `chipset_rtc_time` multiply the counter by the period and divide by 1000 (shift 3, multiply-high by `0x20c49ba5e353f7cf`, shift 4). `salruntime_freq_base` with clock type 2 calls `chipset_rtc_period`, divides `0x3b9aca00` by it with `__udivdi3` and returns status 0: 1e9 / 50 = 20,000,000.
- Chip identification (A39): the routine at `0xffa0f8c0` reads `0x8000_0009_0000_0000 | nasid << 38` through `0xffa0bd20`, stores the node id at object offset 0, bits 27:12 as a halfword at offset 2 and bits 31:28 as a byte at offset 4. `0xffa0f7e0` then walks an array of four method tables (array at `0xffbd8a18`), calls method 1 of each with the object, the halfword and the byte, and stores the first table for which it returns non-zero at object offset 32. Method 1 of the first table is the function at `0xffa959a0`, which compares the halfword with 17251 (`0x4363`). The other three tables compare with 12311 (`0x3017`), 569 (`0x239`) and 17442 (`0x4422`) (functions `0xffa948d0`, `0xffa949e0`, `0xffa97ce0`). The caller of the chain in `main` is `0xffa19bdc` (through `0xffa197f0`).
- Remaining accesses read for this review: SAL_A `0xffc4e7f0` to `0xffc4e966` (A1 to A7), `0xffc4e9a6` to `0xffc4ea40` (A8 to A13), `0xffc4e766` to `0xffc4e7a0` (A14 to A16), the SAL_A error path RMW of `0x1_101d_0080` with `0x280_0000_0000` and the write of `0x1_0001_0000_0000` to `0x1_2000_0000`; the `pi_reg_2001_0100` and `crb_message_control` sequence at `0xffa97796` to `0xffa97930` (read, set bit 24, read `0x1_2000_0000`, OR in the revision-dependent value, write, restore with bit 24 clear); the PI CAM control writers at `0xffa24510` (low 7 bits, bit 63, bit 8, bit 9 when bit 5 of the second argument is set) and `0xffa245f0` (bits 9:8 clear, then the three `0x1_2006_xxxx` reads); the `lb_elect` bit 41 update at `0xffa0b190`; `pi_reg_2001_0100` bits 3 and 17 (`or 8`, `and -9`, `extr.u 3,1`, `mov 131072`); the memory-test engine start (`0xffa6fb7c` command, `0xffa6fbac` status 0, `0xffa6fbdc` mask all ones, `0xffa6fc3c` control with the 31-bit value, the 7-bit op at bit 32 and bit 40) and its poll (`0xffa6fd3c`, mask `0x300_0000_0000`, wait while it equals `0x100_0000_0000`, deadline 20,000,000 microseconds); `md_clk_sel` read with `and 3` (`0xffa77e0c`); `md_ctl_60` `0x4047` or `0x4045`, `md_const_58` `0x4004e20`, `md_const_78` `0x24`; the directory writes `0xffa6b10c` and `0xffa6b14c`.
- Names: the v5.3 header defines `SH1_SHUB_ID`, `SH1_RTC` and `SH1_IPI_ACCESS` and none of the other new offsets; `SH_SHUB_ID_NODES_PER_BIT_MASK` is `0x001f000000000000` in `sn_sal.h`, bits 52:48. The `SHub 2` overlay removes all 40 new registers. The generated C header has every register offset, field shift and field mask the TOML states (no mismatch), and `defs-gen` reproduces the committed files.
- Item 6 of the brief: `boot-sequence.md` was wrong. In SAL_A the reason test is `dep.z r3=r20,0,8` then `cmp.eq p6,p0=0,r3` at `0xffc4e4d0`, and reason 0 takes `br.cond` at `0xffc4e4fc` to `0xffc4e580`, past the `ld8 r31` at `0xffc4e570`. Reasons 1, 2 and above 3 reach the read (the first two with progress 56 and 59 and a branch offset, a reason above 3 with progress 177 and the hang at `0xffc4e6e0`); reasons 0 and 3 are handled earlier.

**Mechanical fixes made in this review.**

1. `prom-reset.md`, the lock: the order of the two clock reads (the counter first, in `0xffa0da70`, then `rtc_ctl` through the period routine), the note that each poll's deadline check repeats both, and the poll delay (the routine at `0xffa0fc90` passes 1000 to `0xffa0db90`, so 1,000 microseconds, not "short").
2. `prom-reset.md`: a reason above 3 also makes the SAL_A `0x1_1003_0000` read, in the "not on the reset path" list and in the corrections section; the SHub ID write's bits 52:48 come from the fourth argument, not "the second".
3. `boot-sequence.md`, SAL_A step 7: the read of `0x81_1003_0000 + (slice & 3) * 128` is skipped by reason 0 (the author's report holds), and a reason above 3 also makes it.
4. `registers.toml`, `rtc_ctl.period`: grade established changed to inferred. Linux v5.3 does not define the field, and the formula is a software expectation read in the PROM and the SAL runtime; the counter's real rate is inferred, as the page itself says. The sentence "10 times (period + 1)" now says "the period field + 1".
5. `registers.toml`, `chip_id.revision`: established changed to inferred (the PROM stores the nibble; that it is a revision is the author's reading).
6. `registers.toml`, `md_refresh_1`: access `w` changed to `rw`. The bring-up routine reads it at `0xffa7761c`, sets 195 in bits 16:8 and writes the word to `md_refresh_1` and to `md_refresh_0`. `md_refresh_0` stays `w` on this path.
7. `registers.toml`, `md_timing_0` and `md_timing_1`: access `rw` changed to `w`, and "Read then written" removed. No read of `0x1_0001_0020` or `0x1_0001_0028` exists in SAL_B; only `0x1_0001_0040` and `0x1_0001_0048` (and `0x1_0001_0008`) are read first.
8. `registers.toml`, `lb_slice_rec`: the SAL_A read is not made for reason 0 (or 3); it is made for reasons 1, 2 and above 3.
9. `registers.toml` preamble: one sentence saying a register-level grade of established covers offset, width and direction for a register Linux does not define; meaning is graded in the fields and doc. The page states the same rule in its grades paragraph.
Generated files regenerated; `ci-check` exits 0 (see the commit).

**Findings not fixed.**

1. A39 and `chip_id`: the chain is now read, not inferred. The word at `0x1_0000_0000` feeds the compare at `0xffa959a6` through the object halfword (bits 27:12), as above, so a model that returns 0x4363 there selects the first method table. The page (A39 row, "Registers touched", "Reset values") and the `chip_id` doc still say inferred and "not traced"; the grade of the required value can rise to software expectation read in full. Mismatch is not checked anywhere on the path: `main` ignores the return of `0xffa197f0`, `0xffa0f8c0` stores whatever `0xffa0f7e0` returns (0 when no table matches), and the two callers read (`0xffa0b270` and `0xffa0b950`) load `[obj + 32] + 360` or `+ 408` and call through it with no null test. So a part number outside 0x4363, 0x3017, 0x239 and 0x4422 would call through a null table; one of the other three would select another chip's table. Not fatal by an explicit check, fatal in effect. Which other part numbers those three are was not identified.
2. The method tables are reached through `[obj + 32]` and are not traced, but three of their methods are visible from this review and touch registers the page and the TOML do not list: methods at `0xffa0efd0` to `0xffa0f640` use a second lock pair, `0x1_101d_0188` (taken through the same routine `0xffa0ed30`) and `0x1_101d_0180`, around read-modify-writes of `0x1_5003_1540` (reads at `0xffa0f03c` and `0xffa0f5ec`, bit-clear write at `0xffa0f61c`). The statement "no read was found in the reset phase" for `fw_word_1540` holds only for direct calls. The `0x1_5003_1560` field setter (`0xffa974f0` to `0xffa975c0`) also takes the `0x200` lock. Whether any of these methods run before the console start is unknown. Also written in the bring-up and not in the TOML: `0x1_0003_0400` and `0x1_0005_0400` (sites `0xffa773fc`, `0xffa7742c`) and `0x1_0001_0068` (read at `0xffa7ab6c`, written at `0xffa7acdc`).
3. SHub ID write: the global-window address is formed from the node id stored in the object (read from the object, not from the new NASID argument), so the write lands through the old node id's window and the new id appears only in the data. A model that decodes the global window at the old and the new id lets both orders work; one that decodes only the new id would miss this write. Not confirmed that the object id is the old one in every caller.
4. The PROM and the runtime test `cpuid[2] == 0xaeeeeeee8badbeef` and, if it matches, shift the counter by 7 before scaling (`0xffa0da70`, `chipset_rtc_time`) and take a different path for the platform frequency in `salruntime_freq_base`. The RTC reading on this page is for any other CPU ID. `salruntime_freq_base` also answers type 1 with status 0 and value -1 and any type above 2 with status -2 (not on the page).
5. Other pages repeat the SAL_A read for reason 0: `boot-sequence.md` line 106 ("reads ... may return 0"), `images.md` line 193 (table row 8, which also pairs it with progress 48), and `README.md` lines 294 and 365 for the SHub 2 image. Only the SHub 1 5.04 image was read here, and `boot-sequence.md` step 7 was the one fix asked for; the others need their own check.
6. `md_refresh_0` is read at `0xffb11ffc` (a routine outside this phase), so its `w` access is right only for the bring-up path. The batch-3 bit layouts that the author marked "not re-read" (bank configuration, timing, refresh, the memory-test operation code list, the flash-table fields) were not decoded here; only offsets, widths (all `ld8`/`st8`), directions and the constants listed above were checked.
7. The `0x1_1002_0000` and `0x1_2001_0100` roles, the meaning of `0x1_1006_0280` bits 32, 6 and 0 and of `0x1_101d_0088`'s relation to `0x080`, remain unknown; no evidence here settles them.

**Not checked.** The progress-write and LED reading (P(c), A5, A7, A19 to A21, A27) was taken from the earlier reviews cited by the page. The lock users A28, A29, A34, A35 and A37 (bit positions, the 500-microsecond and 5,000,000-microsecond waits) and A25 were not re-read, nor the 5.04 `sysctl_init` entry (A40). The body of `0xffa11f10` (called by the chip-identification routine) and the remaining object-method call targets were not read. The interconnect-phase RTC writes (`0xffa961e6`, `0xffa96796`, `0xffa967e6`) were located, not decoded. The SAL specification and any SHub reference manual were not consulted (none is held).

**Cleared scope.** The SAL_A access list (A1 to A16) with its test polarity, the lock protocol and its "must return" entries, the election pair, `0x1_2002_0080`, the SHub ID write field positions and replacement values, the RTC write sequence, period formula and SAL_FREQ_BASE type 2 answer, the A39 read and its path to the `0x4363` compare, the offsets, widths and directions of every register in the two TOML commits (as corrected), the SHub 2 overlay removals and the generated C header. Not cleared: the grades that this review left (A39 as inferred, pending the author's update), the second lock pair and the untraced method tables, the bit layouts of the memory controller registers, and the SHub 2 image statements in item 5.

Resolved after review: devices/shub: grade the chip identification read from the method-table chain

Resolved after review: devices/shub: add the second firmware lock pair and the flag word's accesses

Resolved after review: devices/shub: add the three bring-up registers the first batch missed

Resolved after review: firmware/snprom: correct the reason-0 read of the per-slice word on the other pages

Resolved after review: devices/shub: note the cpuid[2] branch that rescales the real-time clock

## Review (findings follow-up)

Independent review of chips commits `45fae66`, `6dff4a0`, `5feb445`, `37cb17a` and `8d5c797`, which resolve the findings of the review above, examined at chips `8d5c797`. The reviewer wrote none of them. Method: a fresh `ia64-linux-gnu-objdump -z` listing of `shub1snprom.bin` (sha256 `51ccf9ad...3a34617`; SAL_B and SAL_A, `0xffa00000` to `0xffc50000`) and of `shub2snprom.bin` from snprom 10.40 (sha256 `1c8144e3...f0673dd77`, the 1.40 image, found through `root/sn2/SHA256SUMS` and the images page) over SAL_A only; the SAL runtime component (type 0x12, gunzipped from the 5.04 image) for `chipset_rtc_time` and `salruntime_freq_base`. Each cited site was read in context, and every offset the new registers use was searched for as a `movl` constant over the whole of SAL_A and SAL_B. `defs-gen` was re-run.

**Confirmed (re-read in the binary).**

- Chip identification: `0xffa0f8c0` stores the node id at object offset 0, bits 27:12 as a halfword at offset 2 and bits 31:28 as a byte at offset 4, then calls `0xffa0f7e0` and stores its result at object offset 32. That walk takes the array at `0xffbd8a18` (four table pointers, then a null word), calls the descriptor in word 1 of each table with the object, the halfword and the byte, and stops at the first non-zero return, which it returns; so the first accepting table wins. The four methods are `0xffa959a0` (17251, `0x4363`), `0xffa948d0` (12311, `0x3017`), `0xffa949e0` (569, `0x239`) and `0xffa97ce0` (17442, `0x4422`), each a `zxt2` and one compare. A miss returns 0 and stores 0. `main` calls the chain at `0xffa19bdc` through `0xffa197f0` and does not use the result.
- The null-unchecked calls exist: `0xffa1a710` and `0xffa1a7d0` load `[obj + 32]`, add 360 and call through it with no test; `0xffa0b950` does the same with 408.
- Second lock pair: the routine at `0xffa0ed30` takes a status and a release address, reads the whole 64-bit word (`ld8` through `0xffa0e5a0`), proceeds when it is 0, and once the clock passes start + 1,000,000 microseconds writes 0 to the release address and polls again; the this-node callers pass `0x8000_0081_101d_0188` and `0x8000_0081_101d_0180` (movl at `0xffa0f046`, `0xffa0f056`). The other-node poll `0xffa0ad80` reads through the node-object read, tests bit 0 only (`tbit.z` at `0xffa0ae4c`), returns -9 on a passed deadline and has no write. `0xffa0efd0` tests bit n of `0x8000_0081_5003_1540` before it takes the lock, with a deadline argument of 0 meaning none and -1 on timeout; the 1560 setter `0xffa974d0` takes the lock with `0x208` and `0x200` and replaces a bit field (position and width as arguments). The zeroing writes at `0xffa5d44c` and `0xffa5d48c` go to `0x1_5003_1550` and `0x1_5003_1540` of another node.
- The three registers: W64 `0x1000` to `0x9_0003_0400` and `0x9_0005_0400` (plus nasid) at `0xffa773fc` and `0xffa7742c`, after the `md_ctl_60` write at `0xffa773cc` and before the `0x1_0001_0058` write; no other reference to either address, or to `0x1_0001_0068`, in the whole of SAL_A and SAL_B. `0xffa7ab6c` reads `0x1_0001_0068` and `0xffa7ab9c` `0x1_0001_0008` (`md_bank_cfg1`); the routine compares them as signed 32-bit values, writes the argument back at `0xffa7acdc` (register larger) or `0xffa7ad9c` (register smaller), and returns untouched when `cpuid[2]` equals `0xaeeeeeee8badbeef` (`0xffa7a9a0`). Access `rw` holds.
- Reason 0, SHub 1 5.04: the branch at `0xffc4e4fc` (reason 0 from `cmp.eq p6,p0=0,r3`) goes to `0xffc4e580`, past the `ld8 r31` at `0xffc4e570`. SHub 2 1.40: the branch at `0xff67c3ec` goes to `0xff67c470`, past the load at `0xff67c460`; that load's address is `0x2_1003_0000`, with `cr.lid` bits 25:23. The reasons 1, 2 and above 3 fall through to it.
- RTC: `0xffa0da70` and `chipset_rtc_time` read the full counter word and shift it left by 7 when `cpuid[2]` matches (`0xffa0dad6`), before scaling by the period.
- SHub 2 overlay removes `lb_lock2`, `lb_lock2_status`, `md_reg_0003_0400`, `md_reg_0005_0400` and `md_reg_0001_0068`, now 45 removals; the generated C header carries the same offsets and grades as the TOML, and `defs-gen` writes nothing.

**Mechanical fixes made in this review.**

1. `node-bringup.md`, item 8: said the check's caller was not found; now says the method-table walk and what a miss does.
2. `boot-sequence.md`, chip identity at run time: said the part number is checked on `0x81_1006_0580` and that the PROM proceeds only if it is `0x4363`; it is read from the word at node offset `0x1_0000_0000` and offered to four tables.
3. `prom-reset.md`, `SH1_RTC` row: "not re-read here" is replaced by the re-read below.

**Findings not fixed.**

1. A miss does not necessarily fault. The call through a null table loads from physical address 360 or 408 in a mode where the PROM has translation off; that reads low memory, so the callee is whatever those words hold. The "calls through a null table" wording stays correct, but "faults" would not be. The commit counts only two callers. Reading `0xffa00000` to `0xffac0000` finds more: `[obj + 32] + 360` at `0xffa0affc` (the flag claim), `0xffa0b276`, `0xffa0b5e0`, `0xffa1a710` and `0xffa1a7d0`, and `+ 408` at `0xffa0b950`; the rest of SAL_B was not walked for them. Nothing changes in a "must return" value: 0x4363 selects the first table; the other three part numbers select tables a model would also need.
2. The cpuid[2] note is narrower than the review it came from implied. `salruntime_freq_base` tests the value only for clock type 0 (the platform base), where a match takes a path that sizes the answer from a list in memory (`0x1dcd6500`, `0x12a05f200` or `0xba43b7400`) and any other CPU calls `chipset_fsb_freq`. Type 2, the real-time clock, does not test it: it returns `1e9 / period` for every CPU. So with the marker the counter is scaled by 128 inside the PROM and the runtime's time routine while SAL_FREQ_BASE type 2 still reports 20,000,000. A model that wants one consistent clock for that CPU would have to pick; no real hardware is shown to take this path. The `SH1_RTC` row now says this; the review above, item 4 of its findings, is left as written since it says "platform frequency".
3. `boot-sequence.md` line 429 (an older review record) still lists "`r31` read at `0x81_1003_0000 + (slice & 3) * 128`" without the reason-0 exception, and `node-bringup.md` line 214 and `boot-sequence.md` line 310 say the part number "must be" `0x4363`, true only for the first table. Both are accurate to the first-table path and were left.
4. The review above says "removes all 40 new registers"; with this batch 45 are removed.

**Not checked.** The 1,000,000-microsecond deadline in the other-node callers (the descriptor at `0xffa0ef40` passes the caller's argument on; the callers were not read); `0xffa0f1a0` to `0xffa0f650` beyond the lock and bit operations; whether `0xffa0f8c0`'s other seven callers use the same arguments; the rest of SAL_B (`0xffac0000` onward) for further null-unchecked calls; the 1.11 and 4.43 images; the 55-bit width of the counter; the SHub 2 offsets of anything above.

**Cleared scope.** The method-table walk, the four part numbers and the miss behaviour; the second lock pair's acquire, timeout and release sequences; the `1540` bit-flag use and the `1560` setter's use of the `0x200` lock; the three registers' sites, values and the `rw` access; the reason-0 correction on both images; the RTC left shift; the SHub 2 overlay and the generated header. Not cleared: the other-node deadline and the further untraced method-table call sites.

## Review (PIC interrupt and XN compare pages)

The renamed `0x81_5003_1500` to `1560` rows were checked against the 2.4 header (`SH_XN_MD_IILB_CMP_*` at `0x1_5003_1500` to `1530`, `SH_XN_MD_NI0_CMP_*` at `1540` to `1570`, all reset 0) and the SHub 1 PROM's name records (`0xffbfbf68` on), which agree. The earlier row listed `_CMP_ENABLE0` and the "n = 0 to 3, 1510, 1530" form redundantly; the names are now given with their offsets. The widths are 64 bits for these seven.

## The XN compare words the PROM zeroes in the chip-object method at `0xffa236f0`

One method of the chip object zeroes the node's XN compare words, then writes four lists of error-register clears and masks. The method is slot 84 of the class-0 method table at `0xffbd7c18` (359 descriptor pointers in four 112-slot classes; `0xffbd8a18` holds the four class pointers). `0xffc4ba50` and `0xffc4baa0` are only entries in the descriptor pool; slot 84 is the descriptor at `0xffc4baa0`. The only call of slot 84 found is the wrapper `0xffa3e5d0` (it loads the class pointer from the object at offset 32), called once, at `0xffa19c1c` in `0xffa19a20`, on the chip object of the CPU's own node. `0xffa19a20` itself has one caller (`0xffa1e66c`). No path with another NASID was found, but computed vtable calls were not exhaustively excluded.

The method runs only when `0xffa0ff30` returns 1. That gate reads `cr.lid` bits 26:23 as `n`. For `n` = 0 it returns 1 without reading anything. Otherwise it tests bits 26 to 26+`n`-1 of `cpu_bits` (local window `0x81_5003_1550`, through `0xffa0ecd0`) and returns 0 if any is set. So it is "no lower-numbered slice has set its local-master flag", once per node in the normal case, and not a hardware lock.

Every store goes through the 8-byte store helper at `0xffa0e640` (data translation and interrupts off with `rsm 0x24000`, `st8`, `mf.a`, restore). A stop inside the helper shows `ip 0xffa0e650`.

The PROM's name table has 16-byte records from `0xffbfabb0` (819 records): the register offset, then a word whose low 32 bits are a name offset (the high 32 bits are a field word, for example `0x10535`). The name of record *i* starts at `0xffbfdef8` plus the low 32 bits of record *i*-1's word. The earlier note gave a different pool base (`0xffbfe578`), which does not land on these names. The constant `0xffbfdef8` holds for all ten registers checked, and the names match the 2.4 header.

**Step 1: `0xffa222a0`, local window.** Three 4-entry tables of 64-bit offsets, indexed by slice and walked together for four iterations (counter 3 down to -1, stride 8). Each iteration stores 0 to table A's entry, then B's, then C's, with the value in the second argument. An entry with bit 32 set is ORed with `0x8000008000000000` (local window, `0x81_...`); a clear bit 32 would add `0x1800000` first (no entry uses that). Each offset sits in two adjacent slots, so each is written twice, in this order: A0 `15c0`, B0 `15b0`, C0 `1220`; A1 `15c0`, B1 `15b0`, C1 `1220`; A2 `13c0`, B2 `13e0`, C2 `1230`; A3 `13c0`, B3 `13e0`, C3 `1230`. The tables are A `0xffbd8ae0`, B `0xffbd8b00`, C `0xffbd8b20`, reached gp-relative (gp `0xffd98000`, which is the gp in every descriptor of the table). The `0xffbd8b40` table is unrelated: 32-bit sizes indexed by a device-type byte (`0xffa228e0`), stored to a record field.

**Step 2: `0xffa2bd60`, global window of this node.** Called right after step 1 with a pointer to the node's 16-bit NASID (`0xffa236f0` passes its own first argument). It zeros a 128-byte stack buffer (`0xffa15b80`, a memset), stores 0 to `0x8000000950031xxx | (nasid << 38)` for `15a0`, `1360`, `1370`, in that order (the global flag is bit 35, and bit 32 is the offset's own), and then calls `0xffa2b580` five times with a zero-terminated offset list and the zeroed buffer. `0xffa2b580` pairs each offset with the next buffer word and hands the pairs to the list writer `0xffae3f50`, which stores each value with the same 8-byte helper at `0x8000000800000000 | (nasid << 38) | offset` (for an offset with bit 32 set and bit 38 clear). So the five lists are **writes of 0**, not a print; the earlier note called them a print with no MMIO, and that was wrong. The lists, at `0xffbdbde8`, `0xffbdbe18`, `0xffbdbe48`, `0xffbdbe78` and `0xffbdbea8`:

| List | Offsets (`0x1_5003_...`) |
|---|---|
| 1 | `1270`, `1110`, `1120`, `1130`, `1140` |
| 2 | `1150`, `1160`, `1170`, `1180`, `1190` |
| 3 | `11a0`, `11b0`, `11c0`, `11d0`, `11e0` |
| 4 | `11f0`, `1200`, `1210`, `1240`, `1260` |
| 5 | `1270`, `1610`, `1620`, `1630`, `1640`, `1650`, `1660`, `1670`, `1300`, `1310`, `1320`, `1330`, `1340` |

That is 33 stores to 32 distinct words (`1270` is in lists 1 and 5). All are `SH_XN_*_CMP_*` words in the 2.4 header with 64 valid bits and INIT 0 (the 1100 to 11f0 block was read in the header; the others were not read one by one). Nothing reads them back.

The stop at `r36 = 0x80000009500315a0` was inside the leaf store helper, which has no `alloc` (frame size 2), so `r34` and above were outside its frame at the stop: their values are undefined and are not evidence of a linkage fault. The valid check is `b0` against the caller's next bundle.

Slot 85 (`0xffa23850`) calls the list writer with the same two lists, the 70-entry list at `0xffbd8e18` and the 24-entry list at `0xffbd93e0` (calls at `0xffa2389c` and `0xffa238bc`, tables read from the image), using its own object's NASID: the remote node set-up of a claimed neighbour therefore writes `NI0_LLP_ERR` and `NI1_LLP_ERR` (0) and the other entries on the neighbour through its global window, which an emulator run of the stock PROM against a stub also showed (2026-11-21).

After step 2, `0xffa236f0` calls `0xffae3f50` with the 70-entry list at `0xffbd8e18`, reads `SH1_SHUB_ID` (`0x81_1006_0580`, `0xffa0dcf0`), calls the attribute lookup `0xffad6e30` for `"AttrCheck"`, writes a 5-entry list (`0xffbd9280` if bit 31 of the result is clear, `0xffbd9330` if set), and then a 24-entry list at `0xffbd93e0`. The lists are given at the end of this section.

| Offset (`0x1_...`) | Window | Header name (SGI 2.4 SN2) | Reset (header INIT) | Written | Read-back sites (all decoded) | Grade |
|---|---|---|---|---|---|---|
| `5003_1220` | local | `SH_XN_IILB_NI0_CMP_ENABLE0` | 0 | plain 0, twice, step 1 | none | name established; reset inferred |
| `5003_1230` | local | `SH_XN_IILB_NI0_CMP_ENABLE1` | 0 | plain 0, twice, step 1 | none | same |
| `5003_13c0` | local | `SH_XN_PI_SIC_CMP_EXP_HDR0` | 0 | plain 0, twice, step 1 | none | same |
| `5003_13e0` | local | `SH_XN_PI_SIC_CMP_HDR_ENABLE0` | 0 | plain 0, twice, step 1 | none | same |
| `5003_15b0` | local | `SH_XN_MD_NI1_CMP_ENABLE1` | 0 | plain 0, twice, step 1 | none | same |
| `5003_15c0` | local | `SH_XN_MD_SIC_CMP_EXP_HDR0` | 0 | plain 0, twice, step 1 | none | same |
| `5003_15a0` | global, own NASID | `SH_XN_MD_NI1_CMP_ENABLE0` | 0 | plain 0, step 2 | `0xffa2b340`: read, and if none of the mask bits is set, write back OR mask (test-and-set; masks `0x20` at `0xffa2b6cc`, `0x100` at `0xffa2b81c`, `0x80` at `0xffa2b96c`, `0x400` at `0xffa2ba9c`, `0x40` at `0xffa2bbcc`); a set bit makes the caller skip | name established; reset inferred; use established (decoded) |
| `5003_1360` | global, own NASID | `SH_XN_PI_NI0_CMP_ENABLE0` | 0 | plain 0, step 2 | `0xffa2b430` (via `0xffa2b72c`, `0xffa2b87c`): read; if 0, write the first argument; the PROM's 64-bit record field | same |
| `5003_1370` | global, own NASID | `SH_XN_PI_NI0_CMP_ENABLE1` | 0 | plain 0, step 2 | `0xffa2b430`: read, write back OR the second argument | same |
| the 32 list words above | global, own NASID | `SH_XN_*` per the table | 0 | 0, step 2 lists (`1270` twice) | none | name established; reset inferred |
| `5003_15e0`, `5003_1590` | local | `SH_XN_MD_SIC_CMP_HDR_ENABLE0`, `SH_XN_MD_NI1_CMP_EXP_DATA1` | 0 | `0xff00000000` at `0xffa30d7c`, `0xffa30d9c` (in `0xffa30d40`, called from `0xffae302c`) | `0xffa30dc0`, per slice (array `0xffbdd068`, index `cr.lid` bits 26:23) | name established; use inferred |
| `5003_13f0`, `5003_13d0`, `5003_1570` | local | `SH_XN_PI_SIC_CMP_HDR_ENABLE1`, `SH_XN_PI_SIC_CMP_EXP_HDR1`, `SH_XN_MD_NI0_CMP_ENABLE1` | 0 | plain 0 at `0xffa4852c`, `0xffa4854c`, `0xffa4850c` in `0xffa483d0`, gated by `0xffa0ff30` | `1570` only: loads at `0xffa42d3c`, `0xffa42ffc`, store at `0xffa433dc` in `0xffa42a30` (values not decoded) | name established; use inferred |
| `5003_1580` | local | `SH_XN_MD_NI1_CMP_EXP_DATA0` | 0 | old value plus 1, `0xffa469cc` | the same routine, `0xffa469ac` (a counter) | name established; use inferred |
| `5003_1600` | global, NASID passed in | `SH_XN_MD_SIC_CMP_DATA0` | 0 | never | loads at `0xffa6b71c`, `0xffa6cc9c`, `0xffa6cdac`; value not decoded | name established; use unknown |

The six local words of step 1 are never read by any decoded code. The three global words of step 2 are firmware storage read back by the error-record routines at `0xffa2b690` and `0xffa2b7e0` (callers `0xffa2c39c`, `0xffa2cd4c`), so they must read 0 after the zeroing or the once-only test fails. Nothing waits or polls here.

The writes after the SHUB_ID read are the list that clears the error-summary and overflow aliases and masks the error sources. Offsets are the full 36-bit offsets (the leading 1 is bit 32). Each store is 8 bytes. Names are from the PROM's name table, without `SH_`. The two `EVENT` names, `EVENT_OVERFLOW` (mask `0x0fffffff`) and `EVENT_OCCURRED_ALIAS` (offset `0x1_1001_0008`), were checked against the 2.4 header; the other masks were not, so "value equals the register's valid-bit mask" is an inference. The `AttrCheck` choice only changes the `PI_*` values; a lookup result with bit 31 set (a negative status such as `-2`) selects the second 5-entry list. `0xffad6e30` returns 0 for a successful lookup and the negative status otherwise, via `0xffad6b30` and `0xffad67c0`, which holds `mov r8=-2` at `0xffad6a76`. Which condition produces `-2` was not traced, and what a valid log must hold to return a non-negative status was not decoded.

```
== L1 ffbd8e18 (before SHUB_ID read)
110010008 7fffffff EVENT_OCCURRED_ALIAS
110010088 fffffff EVENT_OVERFLOW_ALIAS
110071000 0 FIRST_ERROR
120060688 7ffffffff PI_ERROR_SUMMARY_ALIAS
120060608 7ffffffff PI_ERROR_OVERFLOW_ALIAS
110071380 0 PI_HW_TIME_STAMP
110071300 0 PI_COR_TIME_STAMP
110071400 0 PI_UNCOR_TIME_STAMP
1000000c0 7f77777ff MEM_ERROR_SUMMARY_ALIAS
1000000d0 7f77777ff MEM_ERROR_OVERFLOW_ALIAS
110071180 0 MD_COR_TIME_STAMP
110071200 0 MD_HW_TIME_STAMP
110071280 0 MD_UNCOR_TIME_STAMP
150040508 ffffffffffffffff NI0_ERROR_SUMMARY_1_ALIAS
150040518 7fffffff003fffff NI0_ERROR_SUMMARY_2_ALIAS
150040528 ffffffffffffffff NI0_ERROR_OVERFLOW_1_ALIAS
150040538 7fffffff003fffff NI0_ERROR_OVERFLOW_2_ALIAS
150040560 0 NI0_FIRST_ERROR_1
150040570 0 NI0_FIRST_ERROR_2
150040580 0 NI0_ERROR_DETAIL_1
150040590 0 NI0_ERROR_DETAIL_2
150040140 0 NI0_ERROR_DETAIL_3
150000048 0 NI0_LLP_ERR
150040608 ffffffffffffffff NI1_ERROR_SUMMARY_1_ALIAS
150040618 7fffffff003fffff NI1_ERROR_SUMMARY_2_ALIAS
150040628 ffffffffffffffff NI1_ERROR_OVERFLOW_1_ALIAS
150040638 7fffffff003fffff NI1_ERROR_OVERFLOW_2_ALIAS
150040660 0 NI1_FIRST_ERROR_1
150040670 0 NI1_FIRST_ERROR_2
150040680 0 NI1_ERROR_DETAIL_1
150040690 0 NI1_ERROR_DETAIL_2
150040150 0 NI1_ERROR_DETAIL_3
150002048 0 NI1_LLP_ERR
150040208 ffffffffffffffff XNIILB_ERRORS_ALIAS
150040228 ffffffffffffffff XNIILB_ERROR_OVERFLOW_ALIAS
150040260 0 XNIILB_FIRST_ERROR
150040110 0 XNIILB_ERROR_DETAIL_1
150040120 0 XNIILB_ERROR_DETAIL_2
150040130 0 XNIILB_ERROR_DETAIL_3
150040308 3ffffffffffff XNPI_ERRORS_ALIAS
150040328 3ffffffffffff XNPI_ERROR_OVERFLOW_ALIAS
150040360 0 XNPI_FIRST_ERROR
150040100 0 XNPI_ERROR_DETAIL_1
150040408 3ffffffffffff XNMD_ERRORS_ALIAS
150040428 3ffffffffffff XNMD_ERROR_OVERFLOW_ALIAS
150040460 0 XNMD_FIRST_ERROR
1500400f0 0 XNMD_ERROR_DETAIL_1
150040008 3fffffffff XN_ERRORS_ALIAS
150040028 3fffffffff XN_ERROR_OVERFLOW_ALIAS
150040060 0 XN_FIRST_ERROR
150040070 0 XN_CORRECTED_DETAIL_1
150040080 0 XN_CORRECTED_DETAIL_2
150040090 0 XN_CORRECTED_DETAIL_3
1500400a0 0 XN_CORRECTED_DETAIL_4
1500400b0 0 XN_UNCORRECTED_DETAIL_1
1500400c0 0 XN_UNCORRECTED_DETAIL_2
1500400d0 0 XN_UNCORRECTED_DETAIL_3
1500400e0 0 XN_UNCORRECTED_DETAIL_4
110071900 0 XN_HW_TIME_STAMP
110071980 0 XN_UNCOR_TIME_STAMP
110071880 0 XN_COR_TIME_STAMP
110050200 0 LB_ERROR_DETAIL_1
110050280 0 LB_ERROR_DETAIL_2
110050300 0 LB_ERROR_DETAIL_3
110050380 0 LB_ERROR_DETAIL_4
110050400 0 LB_ERROR_DETAIL_5
110050588 7fffff LB_ERROR_SUMMARY_ALIAS
110050508 7fffff LB_ERROR_OVERFLOW_ALIAS
110050600 0 LB_FIRST_ERROR
110071100 0 LB_HW_TIME_STAMP
== L2 ffbd9280 (AttrCheck bit31 clear)
120050a80 180200000 PI_ERROR_MASK
120050080 180200000 PI_AFI_ERROR_MASK
120050500 180200000 PI_CRBP_ERROR_MASK
120060080 67fdfffff PI_AFI_FIRST_ERROR
120060480 67fdfffff PI_CRBP_FIRST_ERROR
== L3 ffbd9330 (AttrCheck bit31 set)
120050a80 183200000 PI_ERROR_MASK
120050080 183200000 PI_AFI_ERROR_MASK
120050500 183200000 PI_CRBP_ERROR_MASK
120060080 67cdfffff PI_AFI_FIRST_ERROR
120060480 67cdfffff PI_CRBP_FIRST_ERROR
== L4 ffbd93e0 (always, last)
1000000d8 100000000 MEM_ERROR_MASK
10004a000 100000000 MD_DQLS_MMR_XAMOPW_ERR
10006a000 100000000 MD_DQRS_MMR_YAMOPW_ERR
100033020 4000000000 MD_DQLP_MMR_XUERR1
100033820 4000000000 MD_DQLP_MMR_YUERR1
100053020 4000000000 MD_DQRP_MMR_XUERR1
100053820 4000000000 MD_DQRP_MMR_YUERR1
100033000 4000000000 MD_DQLP_MMR_XCERR1
100033800 4000000000 MD_DQLP_MMR_YCERR1
100053000 4000000000 MD_DQRP_MMR_XCERR1
100053800 4000000000 MD_DQRP_MMR_YCERR1
100033040 4000000000000000 MD_DQLP_MMR_XPERR
100033840 4000000000000000 MD_DQLP_MMR_YPERR
100053040 4000000000000000 MD_DQRP_MMR_XPERR
100053840 4000000000000000 MD_DQRP_MMR_YPERR
150040040 0 XN_ERROR_MASK
150040240 0 XNIILB_ERROR_MASK
150040340 0 XNPI_ERROR_MASK
150040440 0 XNMD_ERROR_MASK
150040540 0 NI0_ERROR_MASK_1
150040550 0 NI0_ERROR_MASK_2
150040640 0 NI1_ERROR_MASK_1
150040650 0 NI1_ERROR_MASK_2
110050480 0 LB_ERROR_MASK
```

### Review
 At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.
Independent review of chips commit `d36d7aa`, re-read in Ghidra (IA-64 import of the SAL 5.04 SHub 1 image, flat at `0xffa00000`) with objdump as a cross-check. Confirmed: the step 1 tables, iteration count, store order and window rule; the step 2 stores to `15a0`, `1360` and `1370` and their read-backs in `0xffa2b340` and `0xffa2b430`; the nine names and header INIT values for the registers checked; that the six local words are never read (no constant, table or base-plus-register access found). Corrected: the five calls at the end of step 2 write 0 (they are not a print), which adds 32 words; the name-table pool base is `0xffbfdef8`; the method table is `0xffbd7c18`, not `0xffc4ba50`; the gate reads `cr.lid` bits 26:23 and `cpu_bits`. Added: the 70-, 5- and 24-entry write lists after step 2, and the XN words with other accesses. Not verified: header masks for the aliases other than the two named above, header INIT for the registers outside the 1100 to 11f0 block, what the `AttrCheck` lookup returns on a model, readers of the error registers in the lists, and exhaustive exclusion of remote-NASID calls (only one caller of slot 84 was found). The overlay `remove` list now names every new XN row, and `defs-gen` was re-run.

## The node set-up method after the error lists: `0xffa95c20` and its caller `0xffa96180`

The SAL 5.04 PROM stops in a model at the first read after the error lists, an 8-byte read of `0x8000000910040000` (global window, NASID 0): `0x1_1004_0000`, the **local block's LIQ control register**. The PROM's name table (record 132 of the table at `0xffbfabb0`, name read with the pool rule above) calls it `SH_LB_LIQ_CTL`; the SGI 2.4 SN2 header (`include/asm-ia64/sn/sn2/shub_mmr.h` at 8ef7d46c) defines `SH_LB_LIQ_CTL` at `0x1_1004_0000`, mask `0x70f1f`, INIT 0: LIQ request control bits 4:0, LIQ reply control bits 11:8, force request credit bit 16, force reply credit bit 17, force LINVV credit bit 18. Established (name from two sources). The stop was inside the leaf load helper `0xffa0e5a0`, so the registers shown at the stop are outside its frame and say nothing about the caller.

**Who calls it.** The method at slot 34 (offset `0x110`) of the class-0 table at `0xffbd7c18` (descriptor `0xffc4ba70`, function `0xffa95c20`) is called by the method at slot 36 (`0xffa96180`, descriptor `0xffc4b9e0`) with the same object. Slot 36 is the "node set-up" method; its own caller was not found (no direct call; a call through a wrapper that loads class offset `0x120` was not located). `0xffa95c20` takes a pointer to the node's 16-bit NASID and runs only when the slice gate `0xffa0ff30` returns 1 (same gate as in the XN section; it returns 0 and the method returns at once if a lower slice has set its local-master flag). All accesses are 8 bytes, through the load helper `0xffa0e5a0` and the store helper `0xffa0e640`, at the global window `0x8000000900000000 | (nasid << 38) | offset` unless said. Every row is established as an access (address, width, direction, constant), and the role is from the header name.

### The value rule for the first read

`LIQ_CTL` is read once (`0xffa95ccc`). The value is not compared, masked or branched on: it is ORed with `0x40000` (bit 18, `FORCE_LINVV_CREDIT`) at `0xffa95cdc` and the result is stored back **63 times in a row** (a counter from 62 down to -1, `0xffa95ce0` to `0xffa95d0c`; the same word each time, not a read-modify-write per pass). No poll, no read between the stores. Any value, including the INIT 0, continues the boot, and a plain read/write register satisfies it (established). The role of the 63 stores is inferred: `SH_LB_CREDIT_STATUS` (`0x1_1005_0000`) gives the LINVV credit counter 6 bits (`0x3f000`), so 63 writes fill it if each adds one; the PROM never reads that register back.

### Accesses of `0xffa95c20`, in order

| # | Offset | Name (header and PROM table) | Dir | What the code does | INIT (header) |
|---|---|---|---|---|---|
| 1 | `1_1004_0000` | `SH_LB_LIQ_CTL` | R, then 63 W | read once, store `value \| 0x40000` 63 times | 0 |
| 2 | `1_2000_0180` | `SH_CRB_TIMEOUT_SKID` | R, W | clear bits 63 and 62, set bits 11:8, deposit 2 in bits 5:0 (`0xffa95d4c`, `0xffa95dcc`). The header's mask `0x800000000000003f` has no bits 11:8 or 62 | 7 |
| 3 | `1_2000_0000` | `SH_CRB_MESSAGE_CONTROL` | R, W | clear bits 11, 2, 1 (and with `0xfffffffffffff7f9`, `0xffa95de0`) | 6 |
| 4 | none | environment lookups `SysFlushInt`, `SysFlushDur` (strings at `0xffbb4a40`, `0xffbb4a50`) | | `0xffad6e30` then the numeric parse at `0xffa154a0`; a negative status keeps the default of -1 for each. No SHub access | |
| 5 | `1_1006_0280` local window (`0x8000008110060280`) | `SH_GC_SRC_CTRL` (the page's `rtc_ctl`) | R | helper `0xffa0da00`: bits 13:4 are `x`, the result is `10*x + 10` (the tick period in ns). Any value works; 0 gives 10. Slot 36 has already written `0x100000041` here through `0xffa964e0(obj, 2, 50)`, its first action (see the next section), so a model that keeps what was written reads field 4, 50 ns | `0x1_0000_0000` |
| 6 | `1_2000_0000` | `SH_CRB_MESSAGE_CONTROL` | R, W | in `0xffa11380(nasid, interval, duration, period)`: if bits 47:32 are non-zero and equal to bits 63:48 it returns without writing (Ghidra and the `cmp4.eq` at `0xffa113f6` agree). Otherwise (bits 47:32 zero, or different from bits 63:48) it writes bits 47:32 (`IVACK_STALL_COUNT`) and 63:48 (`IVACK_THROTTLE_CONTROL`) with `(2*interval + period) / (2*period)` and `(2*duration + period) / (2*period)` (a floating-point divide, `0xffa149c0`), each clamped to 1..65535. Defaults when the lookups fail: interval 327680 (`0x50000`), duration 320. With period 10: `0x8000` and `0x20` | 6 |
| 7 | `1_1004_0100` | `SH_LB_MAX_REP_CREDIT_CNT` | R, W | deposit 12 in bits 4:0 | `0x1f` |
| 8 | `1_1004_0180` | `SH_LB_MAX_REQ_CREDIT_CNT` | R, W | deposit 12 in bits 4:0 | `0x1f` |
| 9 | `1_2000_0080` | `SH_CRB_NACK_LIMIT` | R, W | clear bit 63, set bits 15:0 to `0xffff` (limit `0xfff`, frequency `0xf`) | 0 |
| 10 | `1_1006_0580` local | `SH_SHUB_ID` | R | `0xffa0dcf0` returns bits 42:32 (the NASID); it is the first argument of the next lookup, whose result is not used for the register value | per chips |
| 11 | none | environment lookup `NoTimeouts` (`0xffbb4a60`) | | `tbit` of bit 31 of the status: set (not found) selects `0x23c34600`, clear (found) selects 0 | |
| 12 | `1_2000_0100` | `SH_CRB_TIMEOUT_PRESCALE` | R, W | bits 31:0 become 0x23c34600 (600,000,000) or 0 (`mix4.l` keeps bits 63:32) | 0 |
| 13 | `1_101a_0100` | `SH_PTC_PARMS` | R, W | bits 23:0 = `0x186a0` (100,000), bits 35:24 = `0x3e8` (1000), the rest kept (already described in interrupts.md) | `0x7_ffff_ffff` |
| 14 | `1_1004_0300` | `SH_CONVEYOR_BELT_TIME_OUT` | R, W | `0xffa9613c`/`0xffa9615c`: bits 11:0 = `0x3e8`. Header mask is `0xfff`, INIT 0 | 0 |

There is no poll anywhere in this method and no read value is compared except in row 6 (the bits 47:32 test) and the gate. Every written register is later read by the same routine only where the table says R. After row 14 the method returns (`0xffa95c70`).

### What `0xffa96180` does next

The caller `0xffa96180` first calls `0xffa964e0(obj, 2, 50)` (before step a, so before slot 34): it writes `SH_GC_SRC_CTRL` (`0x1_1006_0280`, local-window form `0x8000000910060280` of the node) with `0x100000041` (period index `(50/10 - 1) * 0x10 = 0x40`, plus `0x100000001` for an argument of 2 or more; for 0 or 1 it forms the value from a clock-source lookup instead, not read). That is the write the `rtc_ctl` register page lists as the PROM's first. After the call to `0xffa95c20` returns, the caller continues. The new accesses, in order (new = not in the table above):

| Step | Offset | Name | Dir | What the code does |
|---|---|---|---|---|
| a | `1_101c_0000` (before the call, `0xffa9620c`) | `SH_RTC` | W | 0 |
| b | `1_2000_0000` | `SH_CRB_MESSAGE_CONTROL` | R | `0xffa9627c` |
| c | `1_1006_0580` global | `SH_SHUB_ID` | R | revision = bits 31:28 (`0xffa962ac`) |
| d | `1_2000_0000` | `SH_CRB_MESSAGE_CONTROL` | W | the value read in b ORed with `0x3b03f7` if revision > 2 or `0x3f1` otherwise (`0xffa962d6`, `0xffa962e0`); store `0xffa9630c`. `0x3b03f7` sets bits 21, 20, 19, 17, 16 (outside the header's mask `0xffffffff00000fff`) |
| e | RAM, not SHub | | R, W | reads a pointer from `0x1000000 + (((lid slice) + 9) << 3)`, then at pointer+24, and copies six doublewords there. Plain memory at the physical address `0x1000000` and the pointers it holds |
| f | | calls `0xffa97960` | | the next step below |

**The next step is `0xffa97960`** (global window, NASID in `r32`; the same slice gate; returns at once if the gate fails). It reads `SH_SHUB_ID` (`0x1_1006_0580`, bits 52:49, a shift count), then loops reading 16-bit entries through `0xffa1c2e0` (a table in RAM; entry -1 means skip; the table pointer comes from `[0x1000038] + 16`) to build a bit mask, then stores it to `SH_CPU_PERM` (`0x1_1006_0000`), `SH_IOI_ACCESS` (`0x1_1006_0400`), `SH_EXT_IOI_ACCESS` (`0x1_1006_0180`), `SH_IO_PERM` (`0x1_1006_0380`) and `SH_IPI_ACCESS` (`0x1_1006_0480`), then writes 0 to `SH_EXT_IO_PERM` (`0x1_1006_0100`) (`0xffa97bbc` to `0xffa97cac`). The next section decodes it.

### Values a model must return

| Read | Return | Grade |
|---|---|---|
| `1_1004_0000` | the last written value; 0 before any write | established that no value is tested; 0 is INIT (inferred) |
| `1_2000_0180`, `1_2000_0080`, `1_2000_0100`, `1_1004_0100/0180/0300`, `1_101a_0100` | the last written value, or the header INIT before a write (7, 0, 0, `0x1f`, `0x1f`, 0, `0x7_ffff_ffff`) | established that no value is tested; INIT inferred |
| `1_2000_0000` (reads b and 3 and 6) | last written value, INIT 6 first. Row 6's write runs when bits 47:32 are 0 or differ from bits 63:48 (INIT 6 runs it) and is skipped when they are non-zero and equal | established (the test); INIT inferred |
| `1_1006_0280` (local) | any value; bits 13:4 only set the PROM's idea of the tick period `10*x + 10` ns, and the INIT `0x1_0000_0000` gives 10 ns. The earlier page row for this register (`rtc_ctl`) says the PROM writes `0x100000041` first, giving 50 ns | established (use), inferred (timing role) |
| `1_1006_0580` | the chip's SHub ID: bits 42:32 NASID, bits 31:28 revision (above 2 selects `0x3b03f7` in step d) | established (use), see the SHub ID section |
| RAM at `0x1000000` and pointers | ordinary memory set up by earlier PROM code; not a register | established (access), content unknown |

### Review
 At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.
Written from objdump of the 10.54 image; re-read in Ghidra in the review at the end of this page. Not done in the original: the Ghidra pass, the caller of slot 36 (found since), the contents of the RAM table and the mask rule in `0xffa97960` (decoded since). The row 2 write sets bits the 2.4 header does not list; that could mean SHub 1 silicon differs from the header, or that the register layout differs for revisions the header does not cover; unknown.

## The node permission set-up: `0xffa97960`

Read in Ghidra (IA-64, SAL 5.04 SHub 1 image, flat at `0xffa00000`, `--sn2-prom --no-analysis`) for the decompile of `0xffa97960`, `0xffa1c2e0` and the functions named below, with an `ia64-linux-gnu-objdump` listing of the same image for every instruction quoted; the two agree. Nothing here is objdump-only. Not independently reviewed.

**Who calls the node set-up.** The method at slot 36 (`0xffa96180`) is called by slot 5 of the same class-0 table (`0xffacc6e0`, descriptor `0xffc4ba50`, table entry `0xffbd7c40`), through `[obj+32] + 0x120`; one more caller of slot 36 exists in the same shape (`0xffad01e0`, slot 5 of the class at `0xffbd86c0`, not read). Slot 5 first prints a message (`0xffa17660`), then calls slot 36, so `0xffa97960` is the last thing slot 36 does. Slot 36 returns straight after `0xffa97960` (`0xffa9641c`).

### What `0xffa97960(nasid)` does

All accesses are 8 bytes, global window `0x8000000900000000 | (nasid << 38) | offset`, through the load helper `0xffa0e5a0` and the store helper `0xffa0e640`. The NASID is the sign-extended 16-bit argument. It returns at once if the slice gate `0xffa0ff30` returns 0.

| # | Offset | Name (2.4 header = PROM name table) | Dir | What the code does | INIT (header) |
|---|---|---|---|---|---|
| 1 | `1_1006_0580` | `SH_SHUB_ID` | R | `extr.u` bits 52:49 (`0xffa97a06`); not compared, only turned into a shift count `s`: `s = 1`, then `s++` once per remaining bit of the value (its bit length plus one). Bits 52:48 are the nodes-per-bit field the PROM wrote as 1, 2, 4, 8 or 16 earlier on this page, so `s` is 1, 2, 3, 4, 5 for those | `0x0010300000000000` |
| 2 | RAM | block A node table | R | no SHub access. Loop `i = 0 .. count-1` (each pass re-reads `[0x1000038]`, adds 16 and calls the translation helper `0xffa1c2e0`; `count` is the first halfword, the entries follow as halfwords, so entry `i` is the halfword at `+2+2i`). If the entry is not `-1`, `mask \|= 1 << (i >> s)`. No poll | |
| 3 | `1_1006_0000` | `SH_CPU_PERM` (`0xffa97bbc`) | W | the mask | `0xffffffffffffffff` |
| 4 | `1_1006_0400` | `SH_IOI_ACCESS` (`0xffa97bec`) | W | the mask | `0xffffffffffffffff` |
| 5 | `1_1006_0180` | `SH_EXT_IOI_ACCESS` (`0xffa97c1c`) | W | the mask | `0xffffffffffffffff` |
| 6 | `1_1006_0380` | `SH_IO_PERM` (`0xffa97c4c`) | W | the mask | 0 |
| 7 | `1_1006_0480` | `SH_IPI_ACCESS` (`0xffa97c7c`) | W | the mask | `0xffffffffffffffff` |
| 8 | `1_1006_0100` | `SH_EXT_IO_PERM` (`0xffa97cac`) | W | 0 | 0 |

The six registers are 64-bit "access bits" fields, titled in the header as the CPU MMR, II MMR and interrupt access permission bits; the header gives no bit meaning beyond that. Names are from both the 2.4 header (`shub_mmr.h` at 8ef7d46c: records at lines 23773 to 23829 and 23932 to 24000) and the PROM's name table (records 529, 531, 532, 536, 537, 538, 540; the pool rule of the section above). Nothing reads any of the six back, nothing polls, and the stores are in the order 0000, 0400, 0180, 0380, 0480, 0100.

**The mask rule (inferred from the code, established as code).** Table entry `i` is the halfword for NASID `i` in block A's node table ([os-handoff-tables.md](../../software/firmware/snprom/os-handoff-tables.md#5-block-a-and-the-tables-the-builders-read): count halfword, then one halfword per NASID, `-1` for an absent node, the entry 0 for a node the PROM has marked present). Bit `i >> s` is set for each present NASID. Since `s = log2(nodes per bit) + 1` and SN2 NASIDs are even (two per node), the bit is `(nasid / 2) / nodes_per_bit`: one bit per group of `nodes_per_bit` nodes. That the field is a node-group bit mask is the Linux meaning of the nodes-per-bit field; the permission registers' bit meaning is **unknown**.

**Value for a one-node Altix 350 (NASID 0, one or two CPUs).** Any nodes-per-bit value gives `s >= 1`, so NASID 0 sets bit 0: mask `0x1`. The CPU count does not enter. So the writes are `SH_CPU_PERM`, `SH_IOI_ACCESS`, `SH_EXT_IOI_ACCESS`, `SH_IO_PERM`, `SH_IPI_ACCESS` = `1`, `SH_EXT_IO_PERM` = 0. This assumes block A's node table at that moment holds count at least 1 with entry 0 not `-1`. **Unknown:** what writes that table first. The writer named in the handoff page (`0xffacbce0`) has no direct call and no descriptor in the image, and the later method in slot 5 (slot 3, `0xffacbfa0`) rebuilds the block layout through `0xffac42d0` after this step. If the table were still zero at this point the mask would be 0. A model needs no value for it: all eight accesses are plain writes.

**Reads that change the flow.** None of the SHub reads does. The gate `0xffa0ff30` (slice test, as in earlier sections) decides whether anything happens. For the SHUB_ID read, any value works; bits 52:49 only change the bit chosen in the mask. To keep the hardware path a model returns the value the PROM wrote earlier (bits 52:48 one of 1, 2, 4, 8, 16, bits 42:32 the NASID).

### What follows: the rest of slot 5

After `0xffa97960` and slot 36 return, slot 5 (`0xffacc6e0`) calls, in this order (descriptors are entries of the table at `0xffbd7c18`; each slot is `0xffa..` as listed; read as decompiles only, **not** traced in depth):

| Call | Function | What it is, as far as read |
|---|---|---|
| slot 95 | `0xffa1ef70` to `0xffa1f430` | builds the node object; read below in the slot-by-slot section (this row said no SHub constant; the local path reads SHUB_ID and the node object set-up reaches the L1 UART and the node lock) |
| slot 85 | `0xffa23850` | runs `0xffa2bd60` (the node XN words of step 2), the error lists `0xffbd8e18` and `0xffbd93e0` through `0xffae3f50`, then `0xffa23a20`, which for a node other than its own writes `SH_INT_NODE_ID_CONFIG` (`0x1_1000_0300`, value NASID or `0x800`) and stores to the `0x8_0000_0000` window (interrupt routing, role unread) |
| slot 97 | `0xffa6a100` | memory set-up: reads the DIMM configuration register `0x1_0001_0010` (`SH_JNR_DIMM_CFG` in the PROM's table; `md_bank_cfg2` here) in `0xffa788b0`, writes `0x1_0003_0000` and `0x1_0005_0000` bits 2:0 from a size class in `0xffa733d0` (below 0x40: 0, 0x80: 1, 0x100: 2, 0x200: 3, else 4), reads `0x81_5003_1560` bit 8 (`0xffa975e0`), and calls the bank set-up and test routines `0xffa78100`, `0xffa782c0`, `0xffa73590` (which calls `0xffa78f60`, `0xffa79310`, `0xffa79960`) |
| slots 45, 46 | `0xffa959d0`, `0xffa96920` | read `0x1_101d_0080` through the node-object helpers (slot 45, `0xffa959d0`), then clear and set bits 57 and 40 and write it back (slot 46, `0xffa96920`; `0xffacc8ac` to `0xffacc92c`). This runs whether or not memory is present. When `0xffa788b0` returned 0 slot 5 first calls `0xffa0afd0`, which reads and sets bit 58 of the same register through the same two methods, and then rejoins the common path at `0xffacc850` (corrected in review). The register is the election register of SAL_A; the bit meanings are unread |
| slot 3 | `0xffacbfa0` | relocates the RAM pointer table into the node window (`0xffac42d0`, the layout builder) |
| slot 81 | `0xffa915f0` | role unread (calls `0xffa8f8a0`, `0xffa8f9c0`, `0xffa80720`) |
| slot 99 | `0xffaacaf0` | allocates the `0xb0000`-byte hwcfg block (`0xffaa0100`, stored at block A `+0x20`) and calls the board-record builder `0xffa9fe80` with type `0x11` (inferred to be the KLCONFIG build) |
| slot 92 | `0xffaadae0` | CPU enable/disable through chip methods `0xffa99870` and `+0x2d8` |

**The next major boot stage is memory discovery and set-up** (slot 97): the PROM reads the DIMM configuration, scans the banks, and programs the memory controller, then tests them. It is followed in the same method by the block layout and KLCONFIG build (slots 3 and 99) and the CPU enable step (slot 92). Grade: the stage order is established as the call order in slot 5; the roles of the slots are inferred from names and constants only.

### Unknowns here

- The bit meaning of the six permission registers, and what a cleared bit blocks.
- Who fills block A's node table before this step: answered in the next section (slot 2 of the class-0 table, called by `main()`).
- The caller of slot 5 itself (see the next section).

## Slot 5 after the permission set-up, slot by slot

Read in Ghidra (IA-64, SAL 5.04 SHub 1 image, flat at `0xffa00000`, `--sn2-prom`) for the decompile of each function named, with a flat `ia64-linux-gnu-objdump` listing for the call setups. Register names are from the PROM's name table (the pool rule above) and agree with the 2.4 SGI header where it has the offset. All accesses are 8 bytes through `0xffa0e5a0` and `0xffa0e640` unless said, at the global window `0x8_0000_0000 | nasid << 38 | offset`, with the bit 63 form the PROM uses. Grades: **established** is the instruction sequence at the site; **inferred** a role or a flag meaning; **unknown** not read. Not independently reviewed.

**Order and arguments (established).** Slot 5 (`0xffacc6e0`) calls, with `obj` the chip object in `r32`: slot 36, then slot 95, 85, 97 (`obj`, slot 5's third argument (`r34`), a pointer to a 64-byte stack buffer, 0), `0xffa788b0`, slot 45, slot 46, slot 3, slot 81, slot 99, slot 92. When `0xffa788b0` returned 0 the branch at `0xffacc84c` goes to `0xffaccaa0`, which calls `0xffa13190(arg2, 0x15, 1)` and `0xffa0afd0(obj)` and jumps back to `0xffacc850`: slots 45, 46, 3, 81, 99 and 92 still run. The flag in `r37` is 0 with memory and 1 without; it is the fourth argument of slot 3 and the third of slots 81, 99 and 92 (`mov r43=r37`, `mov r42=r37`), so "zero" below means the memory-present case. If slot 45's read returns negative, slot 5 prints a message (`0xffacca70`) and skips 46, 3, 81, 99 and 92. The zero arguments select the full (memory-present) path in 97, 3, 81 and 99 (`param_4 == 0` or `param_3 == 0` in each); with no memory slots 3, 81 and 99 get 1 and take their headless variants (not read). Each call is `[[obj+0x20] + 8n]` with `n` the slot number, through a descriptor in the table at `0xffbd7c18` (the class selected by the chip's part number: the 0x4363 SHub 1 method table is the first of the four class pointers at `0xffbd8a18`; the match method is slot 1, `0xffa959a0`; established for the match, inferred that the chip object here is class 0).

**`main()` already does most of this (established).** `main` (`0xffa19a20`) calls slot 2 (below), `0xffa1f430` (slot 95's body) directly, `0xffa99cf0` (sets this slice's bit in `cpu_bits`), the whole memory sequence (`0xffa78100`, `0xffa6f000`, `0xffa7c6d0`, `0xffa788b0`, `0xffa782c0`) and the CPU-enable test on `cpu_bits` bit 2, all on the local chip object from `[[0x1000038]+0x38]`. The caller of slot 5 itself was not found: the ten sites that load class offset `0x28` are in other classes or in `0xffa1fe90` (which uses a different object field). Whether slot 5 runs on a one-node machine after `main`, and so repeats the memory steps, or only for nodes `main` did not set up, is **unknown**. This page lists what slot 5 does when it runs.

### Slot 2: the node-table writer (answers "who fills block A's node table")

Established. `main` calls the thin wrapper `0xffa1a910(obj)` at `0xffa19bec` (after `0xffa197f0`; then `0xffb918f0`, `0xffa1f430`, `0xffa3e5d0`, `0xffa78100` and everything in slot 5 follow). The wrapper calls `[[obj+0x20]+0x10]`, class-0 slot 2: descriptor `0xffc4bb80`, whose entry address is `0xffacbcd0`, a single `nop` bundle that falls into the `alloc` at `0xffacbce0`. A search for `0xffacbce0` as a descriptor or branch target finds nothing for that reason; the descriptor holds `0xffacbcd0`. `obj` is `translate([[0x1000038] + 0x38])`, block A's local chip object. The routine writes the count halfword, `-1` for NASIDs below the chip's and 0 for its own, then `0xfface0b0` (CPU table), `0xffaf64b0` and `0xffadd540` (heap arena); for NASID 0 the table is count 1, entry 0 = 0. **So the table is filled before slot 36**, and `0xffa97960` computes mask `0x1` for NASID 0. Grade: established for the chain and the writer. Review: `obj+0x20` is the class pointer that `0xffa0f7e0` returns for the object (the loop over the four class pointers at `0xffbd8a18` asks each class's slot 1, and class 0's slot 1, `0xffa959a0`, is true when the halfword at `obj+2` is `0x4363`); the stores of that result at object `+0x20` are in `0xffa20d60` (registry entries at `[[0x1000038+0x90]] + 0x4e0`, 0x28 bytes each) and `0xffa8d630`. That `main`'s object (`[[0x1000038]+0x38]`) carries halfword `0x4363` and a class pointer set by one of those was not traced, so the class-0 identity stays inferred for that object.

### Slot 95 (`0xffa1ef70`, body `0xffa1f430`), the node object

Established that the wrapper passes `obj` to `0xffa1f430`, which reads `SH_SHUB_ID` local (`0x1_1006_0580`, local window `0x8000008110060580`, bits 42:32) and compares it with `*obj`. Equal (local node, the one-node case): `0xffa8f8a0` calls `0xffa8b5d0(rec, obj, obj, 0)`, which zeroes a `0xeb8`-byte record (the record at `[[0x1000000 + 8*(lid slice + 2)] + 0x188]`), copies `obj`'s 40 bytes in twice, selects the class (`0xffa0f7e0`, stored at `rec+0x20` by `0xffa8d630`) and calls three class methods in the order slot 71 (lock, in `0xffa8d630`), slot 69 (`0xffa8d530`) and slot 72 (unlock) (table below). Back in `0xffa1f430` it stores the index of the platform class into `[[0x1000010 + 8*slice] + 0x10]` and `[[0x1000040] + 0x88]` (RAM), and finishes with `0xffa90e60`, which opens an L1 channel and sends request `0x100b` (the PROM-version request of [l1-requests.md](../../software/firmware/snprom/l1-requests.md), inferred: the code is a constant at the call `0xffa81f40`; no reply is awaited on success). Not equal: `0xffa8fb80` and `0xffa8f960` build the record for a remote node; not read for SHub accesses. The register accesses of the local path, all through class methods:

| # | Offset | Name | Dir | Width | What and condition | Grade |
|---|---|---|---|---|---|---|
| 1 | `1_1006_0580` local | `SH_SHUB_ID` | R | 8 | bits 42:32 are the local NASID (compared with `*obj`); any value that matches the NASID the PROM already uses | established |
| 2 | `1_101d_0100` | `SH_SCRATCH2` (`lb_l1_state`) | R | 8 | slot 69 (`0xffa937b0`), via slot 78 which returns this offset. Bits 41:39 equal to 7 select the UART init below; any other value skips it | established (test), inferred (role) |
| 3 | `0xf_fed4_0028` (junk bus, UART line status) | | R | 8 | polled until bit 6 is set or 100,000 microseconds of RTC time pass (exit on either) | established |
| 4 | `0xf_fed4_0018`, `_0008`, `_0000`, `_0018`, `_0018`, `_0020`, `_0008`, `_0010` | UART line control, divisor high and low, line control, mode control, interrupt enable, FIFO control | R, then W | 2 (writes), 8 (reads) | line control read once, written `\| 0x80`; divisor high = 0, low = 1 (class slot 80 returns 1); line control `& 0x7f` then 3; offset `0x20` = `0x22`; `0x08` = 0; `0x10` = 199 (0xc7); then a read of `0x38` | established |
| 5 | `1_5003_1540` | `fw_word_1540` | R, W | 8 | slot 71 (`0xffa93cd0`) takes lock bit 6: repeat read until bit 6 clear (deadline 10,000,000 microseconds, then slot 30 clears bit 6 and retry), under the lock pair `lb_lock2_status` R (`1_101d_0188`, bit 0 clear means free) and `lb_lock2` W 0 (`1_101d_0180`); write word with bit 6 set. Slot 72 (`0xffa93d80`) clears bit 6 the same way | established |
| 6 | `1_101c_0000`, `1_1006_0280` | `rtc`, `rtc_ctl` | R | 8 | deadlines of rows 3 and 5 | established |
| 6a | `1_101d_0100` | `SH_SCRATCH2` (`lb_l1_state`) | R, W, R, R, W, R, W | 8 | added in review. After slot 71 (lock) and slot 69 (the UART step) `0xffa8b5d0` (`0xffa8b7dc` to `0xffa8bcf0`) reads the register again; if bits 41:39 are 7 it clears them (`& 0xfffffc7fffffffff`), reads, saves bits 49:42 in the record, rewrites the register with bits 49:42 incremented modulo 256, then reads and rewrites it with bit 63 cleared. Slot 72 (unlock) follows. Not skipped on any condition other than the bits 41:39 test | established |
| 7 | `1_1003_0000` | `lb_slice_rec` (`SH_JUNK_BUS_LED0`) | R | 8 | saved and restored around each lock step by `0xffa0e020` and `0xffa0ddb0` (progress code; junk-bus LED writes at `0x8_7fed_0000`, `0x8_7fed_2000`) | established |

Flow-changing reads: row 1 (must equal the chip's NASID, or the remote path runs) and row 2 (bits 41:39). For a one-node Altix 350 keep the hardware path with `SHUB_ID` bits 42:32 = 0 and `SH_SCRATCH2` bits 41:39 = 7 (the value SAL_A's winner already wrote, [images.md](../../software/firmware/snprom/images.md)); a model that keeps what was written does this on the first pass only: row 6a leaves bits 41:39 at 0, so a second run of this body (slot 95 after `main`, and slot 81) finds 0 and skips rows 3 and 4 and row 6a's writes (corrected in review; the earlier text said rows 1 to 7 repeat). The UART step also returns at once when `cpuid[2]` is `0xaeeeeeee8badbeef` (the stand-in processor id). Other than SHub: the L1 console UART on the junk bus (rows 3 and 4) and one L1 request (`0x100b`); no PIC, TIO or flash. `main` already ran this body on the same object.

### Slot 85 (`0xffa23850`), interrupt set-up and event clear

Established. `0xffa2bd60(obj)` (the XN compare words), then the two error lists `0xffbd8e18` and `0xffbd93e0` through `0xffae3f50(nasid, list)` (both already on this page: the walk stores each `(offset, value)` pair, offset 0 ends), then `0xffa23a20(obj, local chip object)`. The new part is `0xffa23a20`, after `0xffa20e30` (RAM bookkeeping; it records the node in a table at `[[0x1000038 + 0x90]] + 0x4dc` and returns 0, skipping every SHub access below, only if that table already holds 0x80 or more entries; otherwise 1).

For slice `i` = 0 to 3, only if bit `0x1a + i` of `cpu_bits` (`0x81_5003_1550`, local window, 8 bytes) is set (read as `0xffa0ecd0`): `main`'s `0xffa99cf0` sets the running slice's bit, so on a one-CPU node only slice 0 passes (inferred for the setter's coverage; established for the test):

| # | Offset | Name | Dir | What | Grade |
|---|---|---|---|---|---|
| 1 | `1_1000_0480` (`i` = 0, 1) or `1_1000_0580` (`i` = 2, 3), node window of `param_1`'s NASID | `SH_LOCAL_INT0_CONFIG`, `SH_LOCAL_INT1_CONFIG` (`local_int_config` n = 0, 1) | W | `(id << 4) \| 0x10_0000_0000_0002`, `id` = the local chip's SAPIC id form `((nasid >> 7) & 0x1f) << 11 \| (nasid & 0x7f) \| i << 7`. Type 2, the PMI of the table in interrupts.md | established |
| 2 | `1_1000_0300`, only when the node is not the local one | `SH_INT_NODE_ID_CONFIG` | W | the local NASID `\| 0x800` | established |
| 3 | `1_1000_0500` (`i` = 0, 1) or `1_1000_0600` (`i` = 2, 3) | `SH_LOCAL_INT0_ENABLE`, `SH_LOCAL_INT1_ENABLE` | W | `0x7ef` | established |
| 4 | `1_1001_0000` | `SH_EVENT_OCCURRED` | R | once after the loop, global window | established |

Row 4's value `v & 0x7ef` drives `0xffa30b40`: for each set bit `j` it runs list `j` of the pointer array at `0xffbdd010` through `0xffae3f50`. The lists clear the matching event and overflow alias bit in `1_1001_0008` and `1_1001_0088` (value = the bit), write 0 to `SH_FIRST_ERROR` (`1_1007_1000`) and to the block's detail, time-stamp and corrected or uncorrected registers, and write the error-summary and overflow aliases of the block with a constant. List 0 is the processor interface (`SH_PI_ERROR_SUMMARY_ALIAS` `1_2006_0688`, mask `0x7_9fff_fe7f`), 1 the memory (`SH_MEM_ERROR_SUMMARY_ALIAS` `1_0000_00c0`, `0x7_f444_470f`), 2 the crossbar (`SH_XN_ERRORS_ALIAS` `1_5004_0008` and the NI, XNMD, XNPI, XNIILB aliases), 3 the local block (`SH_LB_ERROR_SUMMARY_ALIAS` `1_1005_0588`, `0x7f_ffff`, and `SH_JUNK_ERROR_STATUS` `1_1003_0200`), 5 PI corrected, 6 memory corrected, 7 XN corrected, 8 PI uncorrected, 9 memory uncorrected, 10 XN uncorrected; bit 4 has no list (entry `0xffba2028` is a zero terminator). **A model that returns 0 for `SH_EVENT_OCCURRED` runs none of them** (established: the loop only enters on set bits). Grade: established for the lists as constants in the image (names from the PROM table; store counts 11, 12, 41, 13, 0, 13, 14, 17, 13, 14, 17 for lists 0 to 10, list 4 empty).

Flow-changing reads: the `cpu_bits` bit test (row 1 to 3 only run when set) and `SH_EVENT_OCCURRED` (above). For a one-node Altix 350 with 1 or 2 CPUs keep slice 0's bit set and `SH_EVENT_OCCURRED` 0 or any value whose bits the model also lets the PROM clear; the clears are write-only. Other than SHub: nothing.

### Slot 97 (`0xffa6a100`) and the test `0xffa788b0`

Established: the call order inside slot 97 with the fourth argument 0 is `0xffa4efa0` and `0xffa4f1a0` (RAM walks of the PCFG area at `[[0x1000038] + 0x30]`, 0x48-byte records; the larger of the two values is the highest NASID-form id), `0xffa733d0(nasid, ...)`, `0xffa78100`, `0xffb94670`, `0xffb94680`, `0xffa6f000`, `0xffa788b0`, then, only when it returned 0, `0xffa0afd0(obj)`; `0xffa975e0(8)` then `0xffa7c6d0` when bit 8 of the debug word is clear; and, when memory is present, `0xffa782c0` and `0xffa73590`. The first six, the two tests and `0xffa782c0` are in [memory-init.md](memory-init.md#what-runs-in-order-on-a-2-gib-node); only what is new is below.

| # | Offset | Name | Dir | What | Grade |
|---|---|---|---|---|---|
| 1 | `1_0003_0000` | `SH_MD_DQLP_MMR_DIR_CONFIG` | R, W | `0xffa733d0`, after the slice gate: bits 2:0 are set to a class from `n >> 1`, `n` the highest id above: below 0x40 gives 0, below 0x80 gives 1, below 0x100 gives 2, below 0x200 gives 3, else 4; the other bits kept; the same value is written to `1_0005_0000` (`SH_MD_DQRP_MMR_DIR_CONFIG`) with no read of it | established |
| 2 | `1_0001_0010` | `SH_JNR_DIMM_CFG` (`md_bank_cfg2`) | R | `0xffa788b0`: for bank `k` = 0 to 3 the byte `k` has density bits 2:0 and rank bit 3; a bank with density other than 7 adds `(0x40 << density) << rank`; the result is the sum times 4, so it is non-zero iff some bank is not 7. Zero prints "No memory on node" in `main` and freezes the node (`0xffad2c50(0x80)`); in slot 97 and slot 5 a zero result runs `0xffa0afd0` instead (below) | established |
| 3 | `1_0003_0000` | `DIR_CONFIG` | R | `0xffa78f60`, bits 2:0 give the shift `(class & 7) + 1` | established |
| 4 | `1_0003_0200` + 0x10 `k`, `1_0005_0200` + 0x10 `k`, `k` = 0 to 7 | `SH_MD_DQLP_MMR_DIR_LOCVEC0..7`, DQRP | W | `0xffa78f60` writes the mask `m`: bit `i >> shift` for each NASID `i` whose entry in block A's node table is not -1. NASID 0 alone gives 1. This overwrites the all-ones words of memory-init.md | established (writes), inferred (name role) |
| 5 | `1_1006_0580` | `SH_SHUB_ID` | R | `0xffa79310`: bits 45:44 choose how a NASID maps to a vector bit (four layouts, read in full); for NASID 0 every layout gives word 0 = 1, words 1 to 3 = 0 | established |
| 6 | `1_0003_0100`, `0110`, `0120`, `0130`; `1_0005_0100` to `0130`; `1_1006_0600`, `0680`, `0700`, `0780` | `SH_MD_DQLP_MMR_DIR_PRESVEC0..3`, DQRP, `SH_SHUBS_PRESENT0..3` | W | the four vectors, written in the order 0 of each three, then 1, 2, 3: values 1, 0, 0, 0 for NASID 0 | established |
| 7 | `1_0003_0300` to `0370`, `1_0005_0300` to `0370` | `SH_MD_DQLP_MMR_DIR_PRIVEC0..7`, DQRP | W | `0xffa79960`: `0x4bfff`, `0xc96f25b`, `0xfffffff`, `0x96ffff`, 0, 0, `0x4803f`, `0x48000`, each written to the left port then the right; no condition, no read | established |

`0xffa73590` and `0xffa78f60`, `0xffa79310`, `0xffa79960` run only after the slice gate. `0xffa0afd0` (no memory): class method `0x168`, a read of the "advertisement register" that prints "Error: reading advertisement register" on failure, then sets bit 58 of what it read and writes it back through method `0x170`; the register is not identified here (**unknown**; the earlier page's `SH_SCRATCH1` bit 58 reading says the same). Flow-changing reads: row 2. A one-node Altix 350 keeps the hardware path only if the byte of at least one bank has density other than 7, which the L1 SPD data decide (below and [memory-init.md](memory-init.md#spd-and-the-dimm-group-rule)).

### Slots 45 and 46 (`0xffa959d0`, `0xffa96920`)

Established. Both call the vector helpers with `path = *(obj + 0x18)` and register `0x1_101d_0080` (`SH_SCRATCH1`): `0xffa0bd20` (slot 45, read) and `0xffa0c560` (slot 46, write). With `path = 0` the helper is a plain 8-byte access in node `*obj`'s global window; with a non-zero path it runs the vector read or write engine (writes `1_1007_4100` 0, `1_1006_6100`, `1_1007_4000` and `1_1006_6080`, then polls `1_1005_0580` bit 16 and `1_1007_4100` bit 63 up to 1024 times with 100 microsecond delays; none of this runs with path 0; inferred that the local chip object's path is 0, since slot 5 passes the same object for the local node). Slot 5 reads, then writes `(v & ~(1<<57) | 1<<57) & ~(1<<40) | 1<<40` (bits 57 and 40 set), 8 bytes, through slot 46; the value read is not tested. Flow: none. Other than SHub: nothing.

### Slot 3 (`0xffacbfa0`), block layout and EFI store checksum

Established for what runs with the fourth argument 0: `0xffac42d0(1, nasid, 0)` (the layout builder; it reads `SH_SHUB_ID` local, bits 42:32, and stores RAM pointers), a 36-byte copy between RAM records, `0xffadd540` (heap arena, RAM), the copy of two pointer words from the master record at `[0x1000040]`, `0xffafbca0` (which calls `0xffaf6d10`, below, then fills the SAL entry record in RAM from `0xffc4d918`..). The only SHub access is `SH_SHUB_ID` read through `0xffa0dcf0` (several times, 8 bytes). **Flash is touched:** `0xffaf6d10` prints "Checksumming EFI variable store ..." and reads 16 blocks of 64 KiB (block numbers 0x10 to 0x1f, as `block << 16`) through methods `+0x40`, `+0x50`, `+0x70` and `+0x90` of a flash device descriptor built by `0xffa0fa00` for the node, sums them with `0xffb530b0`, prints "DONE" and stores the sum at `[[0x1000070] + 0x80]`; a sum of `0x956bac74` prints the good form, any other sum only changes the text (no flow change). Which flash that is (the boot flash through the junk bus) is inferred.

### Slot 81 (`0xffa915f0`), node object for the local node

Established. With the third argument 0, `0xffa8f8a0(rec, obj)` runs `0xffa8b5d0` again on `[[0x1000010] + 0x188]` (the same record as slot 95's local path on CPU slice 0, so `SH_SHUB_ID`, the `SH_SCRATCH2` test, the lock on `fw_word_1540` and the junk-bus LED saves repeat, but the UART steps and the `SH_SCRATCH2` writes do not, since the first pass cleared bits 41:39; see row 6a above), then `0xffa80720`: stores the record at `[[0x1000038] + 0x180]`, sets flag bit 2, and `0xffa8c420` allocates `0x80c` bytes from the heap, calls the class `0x238` and `0x240` methods again (slots 71 and 72, lock and unlock), and for each CPU entry of block A's CPU table that matches the node points that CPU's record at the same buffer. No new SHub register. If the allocation fails `0xffad2cb0` runs (it sets bit 39 of `SH_SCRATCH1` through `0xffa0aee0`, clears the four `cpu_bits` slice bits through `0xffa9fc70`, writes `crb_message_control` (`1_2000_0000`) `0x1_0001_0000_0000` and waits 300,000 microseconds); not on the normal path.

### Slot 99 (`0xffaacaf0`), KLCONFIG

Established: `0xffaa0100(nasid)` (allocation and layout of the `0xb0000`-byte block, RAM; delays through `0xffa0db90` read the RTC) then `0xffa9fe80(obj, 0x11, 0)`, the board builder. Its subtree (196 functions by direct calls and class slots) has these SHub reads: `SH_SHUB_ID` (`0xffa0dcf0`, local; `0xffa96460` = class slot 39, global, returns bits 31:28), `SH_JNR_DIMM_CFG` (`0xffa788b0`, the "has memory" test, global), `SH_SCRATCH1` (slot 45), `SH_SCRATCH2` and `0x1_0000_0000` (`chip_id`, read by slot 83 `0xffa94350`, which splits bits 63:53 of the first into a count and a small table value and takes bits 15:8 of the second into a 32-byte record; the meaning of those fields is **unknown**), the lock words of slot 95 and the node-object work again. Every other store is into the KLCONFIG block in node memory. The record builders below `0xffa9fe80` (`0xffaa1310`, `0xffaa1a10`, `0xffaa5450`, `0xffaed240` and the component builders) were scanned for constants only; no other SHub register offset appears in them (**inferred**: a constant search, not a full read). Other than SHub: the L1 UART through the node object. Flow: a node with no memory takes the `ERROR: failed to create lboard for headless node` path only when `0xffa9fe80` returns 0.

### Slot 92 (`0xffaadae0`), CPU enable

Established. `0xffa99870(obj, 2)` reads bit 2 of `cpu_bits` of the node (`1_5003_1550`, 8 bytes, global window). **Set: nothing else.** Either way it then calls `0xffb91760`. Clear: class `+0x2d8` (slot 91, `0xffaad720`, I/O initialisation: it skips with "skipping I/O initialization" if bit 14 of the debug word at `0x1_5003_1560` is set, otherwise runs a long sequence through `0xffab3170` to `0xffab3780`, reads and rewrites `0x8_01c0_0250` bit 0 (II block, local window, 8 bytes), and was not traced further), and, if it returns 0 or less, `0xffa99800(obj, 2, 1)`, which sets bit 2 under the `lb_lock` pair (`1_101d_0208` poll, `1_101d_0200` release) by a read-modify-write of `cpu_bits`. `main` makes the same test and sets the bit with `0xffa0eae0(2, 1)` after `0xffab3840` returns 0 or less, so after a normal `main` slot 92 finds the bit set (inferred; `main`'s other branch, `0xffab3840` positive, leaves it clear). Other than SHub: the I/O brick, PIC or TIO and its flash only under slot 91 (not traced, **unknown**).

### Review
 At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.
Independent review of chips commits `c178154`, `8d5ce0a`, `4c91c7c`, `a577b18` and `e3452ce`, written by an agent that did not write them. Re-read in Ghidra (IA-64 import of `shub1snprom.bin`, snprom 10.54, flat at `0xffa00000`, `--sn2-prom --no-analysis`) for every function named below; the `c178154` section, which was objdump-only, was re-read in full. An `ia64-linux-gnu-objdump` listing was the cross-check for each branch condition. Header facts were checked against the 2.4 SN2 header (`shub_mmr.h` at 8ef7d46c). No model run was used as evidence.

**Confirmed.** `0xffa95c20` row by row: the 63 stores of the LIQ word (counter 62 to -1), the skid, credit, NACK-limit, prescale, PTC and conveyor-belt masks and values, the lookups `SysFlushInt`, `SysFlushDur` and `NoTimeouts` and their defaults (`0x50000`, `0x140`, 600,000,000), the `mix4.l` keeping bits 63:32, the RTC store of 0 and the revision rule (`SHUB_ID` bits 31:28 below 3 gives `0x3f1`, otherwise `0x3b03f7`). The slot 34 and slot 36 descriptors (`0xffc4ba70`, `0xffc4b9e0`) sit at class-0 offsets `0x110` and `0x120`. `0xffa97960`: shift `1 + bitlength(SHUB_ID bits 52:49)`, the loop over the block A node table (count halfword, entry `i` at halfword `i+1`, bit `i >> s`), the six stores in the order `0000, 0400, 0180, 0380, 0480, 0100`, and mask `0x1` for NASID 0. The node-table writer chain: slot 2 descriptor `0xffc4bb80` holds `0xffacbcd0`, a nop bundle falling into the `alloc` at `0xffacbce0`; the wrapper `0xffa1a910` calls `[[obj+0x20]+0x10]`; `main` calls it at `0xffa19bec`; the table contents for NASID 0 are count 1, entry 0. Slot 5's call order (36, 95, 85, 97, `0xffa788b0`, 45, 46, 3, 81, 99, 92) and slot 85's `cpu_bits` test (`0x1a + i` at `0x8000008150031550`), `SH_LOCAL_INT*` stores, `0x7ef` enables and the single `SH_EVENT_OCCURRED` read whose `& 0x7ef` gates the error lists (0 skips them). Slot 97's `DIR_CONFIG` size class, `LOCVEC` mask (shift `(bits 2:0) + 1`), `PRESVEC`/`SHUBS_PRESENT` order and the `PRIVEC` constants; for NASID 0 each of the four `SHUB_ID` bits 45:44 layouts gives word 0 = 1, words 1 to 3 = 0. Header names, masks and INIT values for `SH_LB_LIQ_CTL`, `SH_LB_MAX_REP_CREDIT_CNT`, `SH_LB_MAX_REQ_CREDIT_CNT`, `SH_CONVEYOR_BELT_TIME_OUT`, `SH_CPU_PERM`, `SH_EXT_IO_PERM`, `SH_EXT_IOI_ACCESS`, `SH_IO_PERM`, `SH_IOI_ACCESS`, `SH_IPI_ACCESS`, `SH_SHUBS_PRESENT0`, `SH_MD_DQLP_MMR_DIR_PRESVEC0` and `PRIVEC0/1`.

**Flow-changing reads that keep the one-node path (re-derived).** `SHUB_ID` bits 42:32 equal to the NASID (`0xffa1f430` compares `0xffa0dcf0` with `*obj`); `SH_SCRATCH2` bits 41:39 equal to 7 for the UART step, and only on the first pass (row 6a above); `cpu_bits` bit 26 + slice (slot 85, and the gate `0xffa0ff30`, which returns 0 if any lower slice's bit is set); `SH_EVENT_OCCURRED` any value, 0 skips the clears; `SH_JNR_DIMM_CFG` (`0x1_0001_0010`) byte `k` density other than 7 for at least one bank, else "No memory on node" and the node halts in `main`, and slot 5 takes `0xffa0afd0` and goes on; `lb_lock2_status` bit 0 clear and `fw_word_1540` bit 6 clear for the lock in slots 71 and 72 (`0xffa0f1a0`, `0xffa0f650`); `SHUB_ID` bits 45:44 (sharing mode) only select a vector layout. `ffa11380` skips the `CRB_MESSAGE_CONTROL` write when bits 47:32 are non-zero and equal bits 63:48.

**Corrected in place.** (1) The `0xffa11380` test was inverted in the table row and in "Values a model must return". (2) Slot 36 starts with `0xffa964e0(obj, 2, 50)`, which writes `SH_GC_SRC_CTRL` with `0x100000041` before slot 34 reads it; the page had no such step. (3) Slot 5 does not skip slots 45, 46, 3, 81, 99 and 92 when `0xffa788b0` returns 0: `0xffaccaa0` calls `0xffa13190` and `0xffa0afd0` and rejoins at `0xffacc850`, passing flag 1 to slots 3, 81, 99 and 92. (4) `0xffa8b5d0` rewrites `SH_SCRATCH2` (clears bits 41:39, increments bits 49:42, clears bit 63) after the UART step, so the second run of the node-object builder skips the UART; the page said the first-pass rows repeat. (5) `obj+0x20` is the class pointer from `0xffa0f7e0`, stored by `0xffa20d60` and `0xffa8d630`; the object's class-0 identity stays inferred. (6) `0xffa20e30` returns 0, skipping slot 85's SHub accesses, when its registry already holds 0x80 entries. (7) Slot 97's second argument is slot 5's third argument. Not wrong: the "larger of the two ids" for `0xffa733d0` (the first call already starts from the second's result).

**Grades.** Established: addresses, widths, order, constants and the header facts above. Inferred: roles from names (credit counters, LIQ fill), the class-0 identity of `main`'s object, one-bit-per-node-group meaning of the permission masks. The stop at `0xffa0e5a0` in the node set-up section is a navigation point only; the leaf helpers have no `alloc` and see only their arguments, so a register above the passed arguments at such a stop is not evidence. Not verified: that slot 80 returns 1 (UART divisor), the remote-node record builders `0xffa8fb80`, `0xffa8f960`, the caller of slot 5, the bodies of slots 3, 81, 99 and 92 beyond the first levels, and what `0xffa129f0` tests.

## The NI port set-up before memory discovery: `0xffa483d0` and slot 55 `0xffa5d850`

The read of `0x1_5000_0020` that stops a model after the node set-up is `SH_NI0_LLP_CONFIG`, the first access of this routine. Read in Ghidra (IA-64, SAL 5.04 SHub 1 image, `--sn2-prom --no-analysis`, decompiles of every function named) with an `ia64-linux-gnu-objdump` listing of the same image; the two agree. Names are the PROM's name table (records 81 to 105 and 261 to 281, pool rule above) and the 2.4 SN2 header (`shub_mmr.h` at 8ef7d46c). Independently reviewed: see the Review at the end of this section.

**Where it runs (established).** `main` (`0xffa19a20`) calls the wrapper `0xffa483d0` at `0xffa19ffc`, between the progress write 20 and the memory sequence `0xffa78100`. It is reached only if the slice gate `0xffa0ff30` is 1 and bit 2 of the word at local `0x1_5003_1550` is set (`0xffa0ecd0(2)` at `0xffa19fcc`; the wrapper's own gate is the same slice test). The wrapper calls table slot 55 of the chip class (`[[obj+0x20]+0x1b8]`, descriptor `0xffc4bc20`, function `0xffa5d850`), ignores its result, then stores 0 (local window) to `xn_md_ni0_cmp_enable1`, `xn_pi_sic_cmp_hdr_enable1` and `xn_pi_sic_cmp_exp_hdr1` (see the XN compare section above) and returns.

**The reads and writes.** All accesses are 8 bytes through the node-object read `0xffa0bd20` and write `0xffa0c560`; for the local node (object pointer 0, the case at the stop) they are one `ld8` or `st8` at `0x8000000900000000 | nasid << 38 | offset`. Slot 55 first gets the NASID, then looks up the environment variable `NoTimeouts` (no hardware access; a hit sets flag F). Then for port p = 0 and 1 (A = p * `0x2000`, B = p * `0x200`):

| # | Offset | Name | Dir | Value and use |
|---|---|---|---|---|
| 1 | `1_5000_0020`+A | `SH_NI0_LLP_CONFIG` (NI1 at +A) | R, W | bits 9:0 replaced by 400, written back. The read value is not tested |
| 2 | `1_5003_03f0`+B | `SH_XNNI0_DEAD_FLOW` | R, W | AND `0xfff0fff0fff0fff0` |
| 3 | `1_5003_03c0`+B | `SH_XNNI0_FIFO02_FLOW` | R, W | AND `0xfffffffff0fffff0` |
| 4 | `1_5003_03d0`+B | `SH_XNNI0_FIFO13_FLOW` | R, W | AND `0xfffffffff0fffff0` |
| 5 | `1_5003_03e0`+B | `SH_XNNI0_NI_FLOW` | R, W | only if F; AND `0xfff0fff0fff0fff0` |
| 6 | `1_5000_0018`+A | `SH_NI0_LLP_CHAN_MODE` | R | bit 0 clear: mode m = 3; set: m = 0 |
| 7 | `1_5000_0028`+A | `SH_NI0_LLP_TEST_CTL` | R | kept as the working value |
| 8 | if m != 0, up to three passes | | | probe the link (below). Result not -1: leave the loop. Else: if TEST_CTL bits 41:40 are non-zero, write it with them clear; write 1 to `1_5000_0008`+A (`SH_NI0_LLP_RESET`); wait 100, 200, then 400 microseconds on the RTC (`0xffa0db90`); read TEST_CTL again |
| 9 | `1_5000_0028`+A | `SH_NI0_LLP_TEST_CTL` | W | only if bits 41:40 differ from m: write them as m |

The probe `0xffa5cf40(obj, p)` (also what `shub_port_status`, slot 54 `0xffa5d6a0`, calls per port): read `SH_NI0_LLP_ERR` (`1_5000_0048`+A); if bit 27 (`POWER_NOT_OK`) is set, write the word back with it clear and read again, and return 0 if it is still set. Read `SH_NI0_LLP_STAT` (`1_5000_0000`+A): if its low nibble is not 9 return -1. Otherwise, unless `cpuid[2]` is the simulator value `0xaeeeeeee8badbeef`, read `SH_XNNI0_LINK_0_FLOW` to `_3_FLOW` (`1_5000_1040`+A, +0x10 apart) each until bits 22:16 are non-zero, at most 128 reads each, return -1 if 128 reads pass without it, else return 1. The slot 54 mask has bit p set for a probe result of 1 and prints `shub_port_status: vector 0x%lx/%d NI%d from %I failed: %s` for a negative result. Slot 55 never prints.

Slot 55 returns 0 when every register access succeeds; it returns the negative result of a failed node-object access at once (a vector request error, so only for a remote record), and its caller ignores the value. Established as the instruction sequence. The loop count (three passes of 100, 200 and 400) is the doubling counter compared with 699 at `0xffa5de1c`.

**What a one-node Altix 350 needs.** No value of `SH_NI0_LLP_CONFIG` is tested, so a plain read/write register with the header INIT `0x7fc6ffd00` keeps the hardware path (established). Port state "down" is the right model: any `LLP_STAT` whose low nibble is not 9 is a link that is not up, and the INIT 0 is such a value (established for the test, inferred that 9 means up: the code goes on to check link credits only for 9). With `LLP_STAT` 0 on both ports the PROM does, per port, three probes (each reading `LLP_ERR` and `LLP_STAT`), at most three `LLP_RESET` writes of 1 and 700 microseconds of RTC wait, and the final `LLP_TEST_CTL` write of bits 41:40 = 3 (since `CHAN_MODE` INIT has bit 0 clear), about 1.4 ms of RTC time for both ports. The model needs a running RTC and must keep `LLP_STAT` at not-9 after a `LLP_RESET` write; bit 27 of `LLP_ERR` should read 0 (a sticky 1 makes the probe return 0 early, which also ends the loop). The remaining bits do not matter in this phase. What real hardware reads on a lone node (state value, `POWER_NOT_OK`) is **unknown**; nothing in the PROM separates "no cable" from "link down". A node cabled to a second node would need the value 9 and non-zero link credit fields (bits 22:16 of the four link flow words) and then runs the router discovery, which is not traced here.

**Not traced here.** The other NI methods (slots 47 to 53 and 56 to 64, `0xffa5d590` to `0xffa606c0`) run later; the topology walk and slot 59 are traced in [the next section](#the-numalink-topology-walk-0xffa5b5d0-and-slot-59).

### Review (NI port set-up)

Independent re-read on 2026-11-16 in the Ghidra decompiles of snprom 10.54 (`shub1snprom.bin`, flat at `0xffa00000`: slot 55 `0xffa5d850`, the probe `0xffa5cf40`, `shub_port_status` `0xffa5d6a0`, the wrapper `0xffa483d0`, the environment lookup `0xffad6e30`), against the 2.4 `shub_mmr.h` (8ef7d46c) for offsets, masks and INIT values. No IA-64 objdump was available, so the earlier claim that an objdump listing agrees was not re-checked. At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.

**Confirmed.**
- `SH_NI0_LLP_CONFIG` at `0x1_5000_0020` (+ `0x2000` for port 1): read, bits 9:0 replaced by 400 (`0x190`), written back, the read value not tested; the header's field layout (MAXBURST 9:0, MAXRETRY 19:10, NULLTIMEOUT 25:20, FTU_TIME 35:26, mask `0x3fffffffff`, INIT `0x7fc6ffd00`) matches `registers.toml`.
- The flow-register masks, in order, per port p (stride `0x200`): `DEAD_FLOW` `& 0xfff0fff0fff0fff0`, `FIFO02_FLOW` and `FIFO13_FLOW` each `& 0xfffffffff0fffff0`, and `NI_FLOW` `& 0xfff0fff0fff0fff0` only when the `NoTimeouts` lookup succeeds (the lookup returns 0 on a hit and a negative value on a miss; the code skips the write when bit 31 of the result is set). For the two FIFO registers the header's VC0/VC1 and VC2/VC3 LIMIT fields are bits 3:0 and 27:24, which is what the AND clears; the header's field names for `DEAD_FLOW` and `NI_FLOW` were not read.
- `CHAN_MODE` read, bit 0 clear selects mode 3, set selects 0 (the header names bit 0 BITMODE32); `TEST_CTL` read (header INIT `0xa5fffff`, bits 41:40 are SEND_TEST_MODE, so INIT has them 0 and the final write of 3 happens on a model that keeps INIT).
- The probe loop: only when the mode is non-zero; per pass `0xffa5cf40`; any result but -1 ends the loop; on -1, if `TEST_CTL` bits 41:40 are non-zero clear them with a write, write 1 to `LLP_RESET`, wait 100, 200, 400 us in that order (the doubling variable is compared with 700, so three passes), read `TEST_CTL` again. Then bits 41:40 are written as the mode if they differ.
- `0xffa5cf40`: read `LLP_ERR` (`+0x48`); if bit 27 (POWER_NOT_OK per the header) is set, write the word back with it clear, read again, return 0 if still set; read `LLP_STAT`, low nibble not 9 returns -1; for 9 and a non-simulator CPU ID, the four link flow words (`+0x1040 + 0x10 * i`, up to 128 reads each until bits 22:16 are non-zero, -1 if 128 reads pass), then 1.
- `shub_port_status` (`0xffa5d6a0`) runs the probe for ports 0 and 1; a negative result prints "shub_port_status: vector 0x%lx/%d NI%d from %I failed: %s" and leaves the bit clear, so a down port (probe -1) prints that line when this routine is the caller. That is relevant to a model stop only if `SH_SCRATCH1` bit 40 reads 1 (slot 57), see the next section.
- Slot 55 does not always return 0: it returns the negative status of a failed node-object access (corrected above); for the local node (no route word) a node-object access cannot fail, so on a lone node it returns 0. The wrapper ignores the value.

**Not confirmed here.** The wrapper's caller `main` (the gate at `0xffa19fcc`, the call at `0xffa19ffc`) and the names of the three registers the wrapper zeroes (`0x1_5003_1570`, `0x1_5003_13f0`, `0x1_5003_13d0`) were not re-read. The sibling-board names in the earlier reading stay as written.

**Grades.** Unchanged: the access sequence, values and masks stay established; the meaning of "9 is link up" stays inferred; the reset values stay inferred from the header INIT.

## The NUMAlink topology walk: `0xffa5b5d0` and slot 59

What the SAL 5.04 PROM (`shub1snprom.bin`, snprom 10.54, flat at `0xffa00000`) does to the SHub after the port set-up above, for a lone Altix 350 node whose two NI ports are down (`SH_NI0_LLP_STAT` low nibble not 9). Read in Ghidra (IA-64, `--sn2-prom --no-analysis`, every function named decompiled, listing cross-checked at the branch tests); no `ia64` objdump was available, so the listing is Ghidra's. Names are the 2.4 SN2 header (`shub_mmr.h` at 8ef7d46c) and the PROM's name table. Independently reviewed: see the Review at the end of this section. All accesses are 8 bytes. "Own" is the global MMR window of the node's own NASID (`0x8000_0009_0000_0000 | nasid << 38 | offset`, what `0xffa0bd20`/`0xffa0c560` build when the record has no route word); "local" is `0x8000_0081_xxxx_xxxx`.

**Where it runs (established for the call chain, inferred for the scheduler step).** `main` (`0xffa19a20`) ends by passing descriptor `0xffc4df68` (function `0xffa1add0`, a stub that falls into `0xffa1ade0`) to `0xffac6bb0`. `0xffa1ade0` is the body this page calls `main_two`; that `0xffac6bb0` runs it is inferred from the argument. Its order around the walk: progress 0x1c, `0xffa44ba0`, `0xffa44710`, progress 0x1d, `0xffa4d390` (the route calculation, [traced below](#the-route-calculation-for-a-lone-node-0xffa4d390-and-0xffa5a670)), `0xffa5b5d0` (the walk; the master-slice gate `0xffa0ff30` must return 1).

### Accesses in execution order

| # | Where | Access | Offset (window) | Name (2.4 header) | Value, test and the lone-node value |
|---|---|---|---|---|---|
| 1 | `0xffa44ba0` | RMW x3 | `cpu_bits` `0x1_5003_1550` (local) | `SH_XN_MD_NI0_CMP_EXP_DATA1` | assigns bits 13, 14 and 15, in that order, each to 1 if any record of type byte `+0x5a` = 1 without flag `0x10000` has flag `0x100000`, `0x200000` or `0x400000` respectively, else to 0 (`0xffa0eae0` sets or clears the bit; progress 0x1c); plain storage under the lock pair at `0x1_101d_0200`/`0208`. The routine then calls `0xffa5c900`, rows 2 to 5 |
| 2 | `0xffa5c900` | R | `cpu_bits` bit 0 (local) | | must be set (global master; `0xffa42640` sets bit 0 when this node is the global master, inferred for the lone node) or the function returns 0 |
| 3 | `0xffa5c900` | RMW, p = 0, 1 | `0x1_5003_03a0 + p * 0x200` (local) | `SH_XNNI0_VCSWITCH_FLOW` (mask `0x701010101`, INIT 0) | write `value ^ 0x1000000` (bit 24, `IILB_VCFIFO_SWITCH`); read value not tested |
| 4 | `0xffa5c900` | none | | | per node record: slot 49 (`0xffa5d5b0`, returns 2); per port the neighbour index is -1, so `0xffa46a50` (vector send) is never called |
| 5 | `0xffa5c900` | RMW, p = 0, 1 | `0x1_5003_03a0 + p * 0x200` | `SH_XNNI0_VCSWITCH_FLOW` | the same XOR again, restoring the value |
| 6 | `0xffa44710` | R | `cpu_bits` bit 4 (local) | | if clear, `0xffa42a30` runs. It is the tree barrier, not a master selection. A non-zero return (failure) sets bit 4 (`0xffa0eae0`: RMW `cpu_bits` under the lock pair) and runs the global barrier `0xffa43d20`; zero calls the slice barrier `0xffa9a130` and returns. A lone node returns 0, so bit 4 stays clear (established; see the route calculation section) |
| 7 | `0xffa5b5d0` | R | `cpu_bits` bit 4 | | selects the per-record test; slot 59 runs for the local record either way on a lone node. With bit 4 clear the test is byte `+0x5b` bit 1 of the node record (unless that record's own bit 0 is set or some record has flag `0x1000000`, which keep the modulo test), which `0xffa47290` sets in the local descriptor (`\|= 2`) before `0xffa450e0` copies it into record 0 (established). With bit 4 set the test is `index % count == group`, 0 % 1 == 0 (established) |
| 8 | per record | RMW | `0x1_5003_1580` (local) | `SH_XN_MD_NI1_CMP_EXP_DATA0` | value + 1 (`0xffa46980`); plain counter |
| 9 | per record | R | `cpu_bits` bit 10 | | bit set: verbose messages on (`0xffa17770` gate); clear: `0xffa0ab80` runs |
| 10 | `0xffa0ab80` | R, R | `cpu_bits` bit 1, RTC `0x1_101c_0000` (local) | | only if bit 1 (partition master, set by `0xffa42640`) is set; first call is always due (the deadline word starts at 0), then it prints one spinner character (`/`, `-`, `|` or `\`, each followed by a backspace) with the unconditional print `0xffa17660`. One character on a lone node (inferred) |
| 11 | slot 59 `0xffa5e880` | R | `0x1_1006_0580` (local, `0xffa0dcf0`) | `SH_SHUB_ID` | bits 42:32 used as the NASID of the access window |
| 12 to 17 | slot 59, port p = 0, 1 | W x128 | `0x1_5002_2000 + p * 0x1000 + 8 * i` (own) | `SH_NI0_LOCAL_TABLE`, `SH_NI1_LOCAL_TABLE` | route-table nibble of entry i, bit 63 set per the rule below |
| | | W x16 | `0x1_5002_2400 + p * 0x1000 + 8 * i` | `SH_NI0_GLOBAL_TABLE`, `SH_NI1_GLOBAL_TABLE` | same rule |
| | | W | `0x1_5002_2480 + p * 0x1000` | `SH_NI0_OVER_RIDE_TABLE`, `SH_NI1_OVER_RIDE_TABLE` (INIT `0x8000000000000000`) | 0 |
| | | RMW | `0x1_5003_03a0 + p * 0x200` | `SH_XNNI0_VCSWITCH_FLOW` | OR `0x100` (`PI_VCFIFO_SWITCH`), OR `0x101` if the port record's byte `+0x2b` bit 5 is set |
| | | RMW | `0x1_5003_0400 + p * 0x200` | `SH_XNNI0_INJECT_AGE` (mask `0xffff`) | `(v & ~0xff00) \| 0xc000` (`REPLY_INJECT` = 0xc0); only when the router count (argument 2) is 0, true for a lone node |
| 18 | slot 59 | W x128 each, in the order MD, IILB, PI | `0x1_5002_4000 + 8i`, `0x1_5002_0000 + 8i`, `0x1_5002_1000 + 8i` (own) | `SH_MD_LOCAL_TABLE`, `SH_IILB_LOCAL_TABLE`, `SH_PI_LOCAL_TABLE` | one value per entry, the same for the three; see the table values below |
| 19 | slot 59 | W x16 each, same order | `0x1_5002_4400`, `0x1_5002_0400`, `0x1_5002_1400` `+ 8i` | `SH_MD_GLOBAL_TABLE`, `SH_IILB_GLOBAL_TABLE`, `SH_PI_GLOBAL_TABLE` | bit 63 only when the nibble is not 0xf (no special case for entry 0 or for the node's own index); the PI table additionally ORs bit 4 when the first port's neighbour record has part number `0x3017` and bit 12 when the second port's has |
| 20 | slot 59 | W | `0x1_5002_4480`, `0x1_5002_0480`, `0x1_5002_1480` (own) | `SH_MD_OVER_RIDE_TABLE`, `SH_IILB_OVER_RIDE_TABLE`, `SH_PI_OVER_RIDE_TABLE` | 0 (override disabled). Order in the code: IILB `0x20480` is written first, then MD `0x24480`, then PI `0x21480` |
| 21 | slot 59, only if record flag `0x10000` | | | | slot 55 `0xffa5d850` again (the port set-up above), then `0xffa9fc70` and `0xffa95a30` below. The flag is bit 39 of `SH_SCRATCH1` (`0x1_101d_0080`) as read by slot 57, and that bit is set by `0xffa5d2a0` on a remote node; for a lone node it is inferred clear, so this step is skipped. If it is set, the following apply |
| 22 | `0xffa9fc70(nasid, 0, route 0)` | W | `0x1_2000_0000` (own) | `SH_CRB_MESSAGE_CONTROL` | `0x0001000100000000` |
| 23 | | RMW | `0x1_5003_1550` (own) | | clear bits 29:26 (one write for the four bits) |
| 24 | | delay | RTC | | 300,000 microseconds (100 on the simulator CPU ID); the RTC must run. If the node's own NASID and slice match the caller, `0xffa9fba0` then calls `0xffaeb7c0` (not read) |
| 25 | `0xffa95a30` | R, W | `0x1_1006_0580` (own) | `SH_SHUB_ID` | as the SHub ID section above (NASID in 42:32, bits 45:44, one-hot 52:48) |

Row 7's note: the record byte `+0x5b` is byte `0x2b` of the descriptor. Bit 1 is set for the local node by `0xffa47290` and for a remote node by `0xffa5d2a0`; bit 0 is set by slot 57 when `SH_SCRATCH1` bit 40 is set. The port records' own byte `+0x2b` (array entries; bit 1 from the complement of bit 0 of the register at `0x1_5000_0010 + (p << 13)`, only when bit 40 is set) is a different byte. An earlier version of this page confused the two and concluded that slot 59 is skipped on a lone node; it is not.

**The walk (`0xffa5b5d0`), what each branch needs.** It reads the node table (entry stride `0x48`), builds a halfword array with one entry per record, then calls slot 59 (`[class + 0x1d8]`) for each record that passes a test: with bit 4 of `cpu_bits` set the test is `record index % count == the root's group` (the integer divide `0xffac0880`, which for one record gives 0 = 0); with bit 4 clear it is the record's byte `+0x5b` bit 1. A non-local record of type 1 without flag `0x10000` is first asked for its `SH_SCRATCH1` word through slot 45 and a vector read (row not on the lone-node path, there is no second record). It prints "Distributing routing tables" only when bit 10 of `cpu_bits` is set; the failure text `distribute_numbers: vector 0x%lx from %I failed: %s` is printed whenever slot 59 returns a negative value.

**What slot 59 writes.** Per port the entry value is the low nibble of a byte of the port's route table (`0xffa0cec0(byte, 0)`, 0xf means no route), with bit 63 (`VALID`) set for entry 0, for the entry whose index equals the node's NASID modulo 128 and for every entry whose nibble is not 0xf (local tables; the 16-entry global tables use only the last of the three tests). The MD, IILB and PI tables take the high nibbles of the two port tables: with A the first port's high nibble and B the second's, S = B plus 0x20 if B is not 0xf, else A, and L = A if A is not 0xf, else S; the word is L | S << 8, VALID by the same local and global rules applied to L. The PI table also ORs bit 4 if the first port's neighbour record has part number `0x3017` and bit 12 for the second port's. A record whose byte `+0x5b` bit 0 is set (a node whose port set came from `SH_SCRATCH1` bit 40) is read and compared first and written only on a difference, and skips the override-table writes, the `VCSWITCH_FLOW` OR and the `INJECT_AGE` update entirely; that is not the lone-node path. Contents for NASID 0 alone: see [the route calculation section](#the-route-calculation-for-a-lone-node-0xffa4d390-and-0xffa5a670).

### The vector read and write (`0xffa0bd20`, `0xffa0c560`)

Both take a route word (zero for the local record), the NASID, the register offset and the data. A zero route is the direct access above and involves no vector register. With a route (a remote record; not used on a lone node):

1. claim bit 9 of `fw_word_1540` (`0x1_5003_1540`, local) under `0x1_101d_0180`/`0188`, with a 5,000,000-tick deadline (prints `WARNING: breaking vector lock on node %d.` and goes on if it expires);
2. `0xffa0b9a0`: read `SH_LB_ERROR_SUMMARY` (`0x1_1005_0580`); if bit 16 is set, write 0x10000 to the alias at `+8` and to `0x1_1005_0508`, clear the detail registers and retry (the attempt is spent). When it is set the routine also reads `0x1_1005_0600`, and if its bit 16 is set clears it, `0x1_1007_1100` and the five detail words; when the whole summary equals `0x10000` it writes 8 to `0x1_1001_0008` and `0x1_1001_0088` and clears bit 3 of `0x1_1007_1000` if set. A model returns 0 here (none of this is reached);
3. write 0 to `SH_VEC_STATUS` (`0x1_1007_4100`), read it, and fail with -1 if bit 63 is already set;
4. poll `SH_VEC_PARMS` (`0x1_1006_6080`) until bit 63 (`BUSY`) clears, at most 1024 reads;
5. for a write, store the data in `SH_VEC_DATA` (`0x1_1006_6000`); for a read, store `0xdeadbeefdeadbeef` in `SH_VEC_RDDATA` (`0x1_1007_4000`) instead; then `SH_VEC_ROUTE` (`0x1_1006_6100`, the route word shifted down four bits, `0xf00000000` when empty) and `SH_VEC_PARMS` = `(first route nibble - 1) * 2 | offset & 0x7fffffff8 |` `0x40000e4000000000` (read, PIO_ID 0x1c8) or `0x400003d800000001` (write, PIO_ID 0x7b); bit 62 `START` launches it;
6. up to 1024 times: wait 100 microseconds, read `SH_LB_ERROR_SUMMARY`; if bit 16 is clear, read `SH_LB_ERROR_DETAIL_1` (`0x1_1005_0200`) and, if its low byte is 0xe9 (read) or 0xea (write), write 0 to `0x1_1007_1100` and to the five detail words `0x1_1005_0200` to `0x1_1005_0400`; then read `SH_VEC_STATUS`; bit 63 (`STATUS_VALID`) ends the wait, and a read then reads `SH_VEC_RDDATA` (`0x1_1007_4000`);
7. release the lock. Result: `OVERRUN` (bit 62) gives -2; status type (bits 2:0) 4, 5, 6 give -4, -5, -6; success (0) needs type 0 (read) or 1 (write), PIO_ID 0x1c8 or 0x7b and the status address bits equal to the request; anything else is -3.

**Completion rule.** A vector operation completes when `SH_VEC_STATUS` bit 63 reads 1 on a pass where `SH_LB_ERROR_SUMMARY` bit 16 is 0. There is no timeout bit and no error status for "no neighbour": a request to a node that is not there never produces a reply, so the poll runs out (1024 passes of 100 microseconds, about 102 ms, plus the register reads) and the whole request is retried after waits of 1.8, 7.3, 29, 117, 469, 1,875 and 7,500 ms (each four times the last), eight attempts in all, about 11 s, ending in -7. A model that wants a missing neighbour to fail quickly sets `STATUS_VALID` with a type of 4, 5 or 6 (result -4, -5, -6). Established as the control flow; the timings are computed from the loop bounds and delay arguments, not measured. A request that fails earlier (the vector lock cannot be taken, the pre-check reports an old error, or `SH_VEC_PARMS` stays busy for 1024 reads) waits 100 microseconds and retries without the growth, up to the same eight attempts. What real hardware returns for an absent neighbour is unknown.

### What a lone node needs, and what it prints

- Keep: `SH_NI0_LLP_STAT` low nibble not 9 on both ports (as above), `cpu_bits` bit 0 set by the global-master selection `0xffa445b0` (inferred, the lone node is its own master; bit 4 stays clear), and plain read/write storage at every offset in the table; the walk reads back only `SH_VEC_STATUS` and the vector registers, and those only for a remote record.
- Slot 59 runs once, for the local record. No vector register is touched, no `LLP` register is touched by the walk itself (the second slot 55 run needs flag `0x10000`).
- Prints: the spinner character (row 10), and with `cpu_bits` bit 10 set `Distributing routing tables` and `Set up %s: index %d, %I, nasid %d`. No failure text appears on a lone node.
- Waits: 300 ms of RTC time only if flag `0x10000` is set; otherwise none. The RTC must advance.
- Freezes: none found; every loop in the walk is bounded.
- Slots by use. Reached from the walk or `0xffa5c900`: 49 (`0xffa5d5b0`, port count 2), 55 (only with flag `0x10000`), 59, and 33 (`0xffa95a30`, in the same branch). Leaf methods, called from the route and discovery code and not by the walk: 47 (`0xffa5d590`, returns 128, the local table depth), 48 (`0xffa5d5a0`, 16, the global table depth), 50 (`0xffa5d5c0`, 1), 51 (`0xffa606c0`, maps 0, 1, 2 to 10, 5, 3, else 0xff), 52 (`0xffa5d5d0`, bit 56 of the argument), 53 (`0xffa5d5e0`, reads `SH_NI0_LLP_ERR` bytes 0 and 1). Method 54 (`shub_port_status`), 56 (`0xffa5df20`, discovery), 57 (`0xffa5e0b0`, port fill), 58 (`0xffa5e510`, checks a table entry against the expected turn count), 60 to 64 (`0xffa5fa70` sets one route entry, `0xffa5fee0` prints the tables, `0xffa60410`, `0xffa60550`, `0xffa606b0`) belong to the discovery crawl and route calculation, so they are skipped here (inferred from the callers; 60 to 64 were not read in full).

### Correction to the port-fill reading

`0xffa5e0b0` (slot 57) tests `SH_SCRATCH1` bit 40 with `tbit.z` and branches when it is set: bit 40 **set** stores the NASID from bits 42:32, sets byte `+0x2b` bit 0 and calls `shub_port_status`; bit 40 **clear** stores NASID 0xffff and takes the link mask from bits 55:54. The [boot sequence page](../../software/firmware/snprom/boot-sequence.md) says the reverse.

### Unknowns

Slots 60 to 64 are only partly read (slots 60 and 63 are); `0xffaeb7c0`; the callers of `0xffa60a70` (`0xffa618fc`), which also sets bit 39 of `SH_SCRATCH1` on another node. The earlier unknowns (table contents, the `0xffa42a30` result, the `SH_SCRATCH1` bits) are answered in [the next section](#the-route-calculation-for-a-lone-node-0xffa4d390-and-0xffa5a670).


### Review (topology walk and slot 59)

Independent re-read on 2026-11-16 in the Ghidra decompiles of snprom 10.54 (`shub1snprom.bin`, flat at `0xffa00000`: `0xffa1ade0`, `0xffa44ba0`, `0xffa44710`, `0xffa5b5d0`, `0xffa5c900`, slot 59 `0xffa5e880`, slot 57 `0xffa5e0b0`, `0xffa0bd20`, `0xffa0c560`, `0xffa0b9a0`, `0xffa0f750`, `0xffa0ab80`, `0xffa9fc70`), with the 2.4 `shub_mmr.h` (8ef7d46c) for the masks. No IA-64 objdump was available and no instruction listing was dumped for this section. At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.

**Confirmed.**
- The `main_two` body `0xffa1ade0`: progress 0x1c, `0xffa44ba0`, `0xffa44710`, then (slice gate) progress 0x1d, the route calculation `0xffa4d390` and the walk, then `0xffa44710` again and progress 0x1e. The entry through descriptor `0xffc4df68` and `0xffac6bb0` was not read, so that stays inferred.
- The `VCSWITCH_FLOW` pair in `0xffa5c900`: gate `0xffa0ff30` and `cpu_bits` bit 0, then for ports 0 and 1 at `0x1_5003_03a0 + 0x200 * p` a read and a write of the value XOR `0x1000000` (the header's IILB_VCFIFO_SWITCH, bit 24; mask `0x701010101`); then, per record, slot 49 (returns 2) and a vector send for each port whose neighbour index is not -1 (none on a lone node); then the same XOR again, which restores the value. On an error from the send the restore pair still runs.
- `cpu_bits` bit 4 gate: `0xffa44710` sets it only through `0xffa42a30` and `0xffa0eae0`; the walk's modulo test, with its exceptions, is as corrected in row 7.
- Slot 59's write order, per port (0 then 1): local table 128 entries, global table 16, override 0, `VCSWITCH_FLOW` OR `0x100` (`0x101` when the port record's `+0x2b` bit 5 is set), `INJECT_AGE` `(v & ~0xff00) | 0xc000` only when the router count (argument 2) is 0; then the MD, IILB, PI local tables (128 each, in that order per entry), then the global tables (16), then overrides written 0 in the order IILB, MD, PI. Masks and bit 63 as corrected above. The router count is the number of records with part number `0x239`.
- `SH_SCRATCH1` bit 39 gating: slot 57 sets record flag `0x10000` from bit 39 of the word it is given (assumed to be `SH_SCRATCH1`: the caller was not read); slot 59 runs the second slot 55, `0xffa9fc70` (write `0x0001000100000000` to `0x1_2000_0000`, clear bits 29:26 of `0x1_5003_1550`, wait 300,000 us, 100 under the simulator ID) and `0xffa95a30` only when that flag is set.
- The vector-operation protocol, as corrected in the list above: the lock (bit 9 of `0x1_5003_1540` under `0x1_101d_0180`, 5,000,000-tick deadline, "WARNING: breaking vector lock on node %d." on a lock failure, which does not stop the request), the pre-check, STATUS write 0 then read (bit 63 already set gives -1), the PARMS busy poll (1024 reads), the data and route stores, PARMS `0x40000e4000000000 | offset | (first route nibble - 1) * 2` for a read or `0x400003d800000001 | ...` for a write, 1024 passes of 100 us reading `SH_LB_ERROR_SUMMARY`, then `SH_LB_ERROR_DETAIL_1` (low byte `0xe9` for a read, `0xea` for a write clears the detail words and `0x1_1007_1100`), then STATUS; results -1 to -7 as listed. The retry waits `0x727` us times four per attempt (1.8, 7.3, 29, 117, 469, 1,875, 7,500 ms) and eight attempts in total.
- Slot 57's polarity (the boot-sequence fix): bit 40 clear stores NASID `0xffff` and takes the mask from bits 55:54; bit 40 set sets byte `+0x2b` bit 0, calls `shub_port_status`, and reads `0x1_5000_0010 + (p << 13)` (the header's `SH_NI0_LLP_RESET_EN`, INIT 1) to set bit 1 from its complement. The fix in `boot-sequence.md` is right. The NASID stored comes from bits 42:32 of the second argument, not the word with bit 40; the second argument is the neighbour's chip identification word (offset `0x1_0000_0000`), read for the [neighbour crawl](../../software/firmware/snprom/boot-sequence.md#numalink-discovery-with-a-linked-port-the-neighbour-crawl-sal-504). **Correction:** the two earlier statements above that the field was `(hops - 1) * 2` were wrong; it is the first route nibble minus one, doubled, which puts the port in the one-bit `NI_PORT` field.

**Changed.** Row 1 (bits 13, 14, 15 are assigned from record flags, not unconditionally set); row 7 (the full condition for the test); the slot 59 text (PI extra bits, the global-table valid rule, the exact combine formula, the conditions under which overrides, `VCSWITCH_FLOW` and `INJECT_AGE` are written); vector step 2 (the extra pre-check accesses); step 5 (a read pre-fills `SH_VEC_RDDATA`, not `SH_VEC_DATA`); the retry text (the early-failure path waits 100 us, not the growing wait). The `registers.toml` docs for `vec_data` and `vec_rddata` were corrected to match.

**Not confirmed.** The route-calculation section that follows was added by a later trace and was not re-read here (my decompile of `0xffa44710` agrees that a zero from `0xffa42a30` returns without setting bit 4); `0xffa43d20`, `0xffaeb7c0`, `SH_SCRATCH1` bits 39 and 40 on a lone node (inferred clear), the spinner's RTC source (`0xffa0da70`), and the names of the registers behind `0x1_1005_0600`, `0x1_1001_0008` and `0x1_1007_1000`. The slot 56 and 58 to 64 summaries were not re-read.

**Grades.** The access sequence and values stay established. The lone-node inferences (bit 0 of `cpu_bits` set by the election, `SH_SCRATCH1` bits 39 and 40 clear) stay inferred.

## The route calculation for a lone node: `0xffa4d390` and `0xffa5a670`

Same image and method as the walk above (`--sn2-prom --no-analysis` decompiles, plus a Ghidra listing of the slices around every branch tested; no IA-64 `objdump` was available). Not independently reviewed. Premise for every answer: the node table holds one record, the local SHub (type 1, port count 2, both ports down), as in the [crawl section of the boot sequence page](../../software/firmware/snprom/boot-sequence.md#numalink-discovery-with-the-skip-bit-clear-and-no-link).

**What the functions are (established from their strings and structure).** `0xffa4d390` is `intcon_assign_numbers` (strings `NASIDOffset`, `NASIDStride`, `RtrRoutes`, `ftdepth = %d`, `nasid_nlocal_bits = %d`). It reads debug word bit 5 (`0xffa975e0(5)`); if clear it looks up the three environment variables (no hardware; defaults offset 0, stride 2, flags 0), calls `0xffa4a740` (router tree depth), then walks the record list giving each record a free number (type 1 starts at 0 and steps by 2) and stores the NASID `offset + number * (stride / 2) | (number & 1)` in the record's first halfword, unless the record already holds one (byte `+0x5b` bit 0). It ends with `0xffa5a670` (`route_assign`, prints `Calculating routes`), which allocates and fills the tables. `0xffa4c540` is called only when the router depth from `0xffa4a740` is non-zero, so it is **not called** on a lone node. `0xffa4a740` returns 0: the router count in the record header (`+0x1c`) is 0, its tree loop does not run and `0xffa49790` returns 0 (code read; the count is inferred). The lone node therefore gets NASID 0 unless the environment variables are set (inferred: none set).

**How the tables are filled (established).** `0xffa53650` allocates, per port of each record, a 128-byte local and a 16-byte global table (sizes from slots 47 and 48; a third table only for an NL4 router, part `0x239`), and the pool allocator `0xffa535c0` fills every allocation with `0xff`: both nibbles of each byte are 0xf, "no route". The only code that stores nibbles is `0xffa54b80` (through slot 58), called from the pair loop of `0xffa59030` (one pass per ordered pair of different records) and from `0xffa58c80` (ports with a neighbour). One record gives no pair, and both ports have neighbour index -1, so every table keeps 0xff. The all-pairs distance work (`0xffa56130`, `0xffa56ad0`, `0xffa57600`) touches RAM arrays only.

**Values slot 59 writes for NASID 0 alone (established as code on the premise; the `f` values follow from the 0xff fill).**

| Registers | Entries | Value |
|---|---|---|
| `SH_NI0_LOCAL_TABLE`, `SH_NI1_LOCAL_TABLE` | 0 | `0x800000000000000f` |
| same | 1 to 127 | `0x000000000000000f` |
| `SH_NI0_GLOBAL_TABLE`, `SH_NI1_GLOBAL_TABLE` | 0 to 15 | `0x000000000000000f` (VALID only when the nibble is not 0xf) |
| `SH_NI0_OVER_RIDE_TABLE`, `SH_NI1_OVER_RIDE_TABLE` | | 0 |
| `SH_MD_LOCAL_TABLE`, `SH_IILB_LOCAL_TABLE`, `SH_PI_LOCAL_TABLE` | 0 | `0x8000000000000f0f` |
| same | 1 to 127 | `0x0000000000000f0f` |
| `SH_MD_GLOBAL_TABLE`, `SH_IILB_GLOBAL_TABLE`, `SH_PI_GLOBAL_TABLE` | 0 to 15 | `0x0000000000000f0f` |
| `SH_MD_OVER_RIDE_TABLE`, `SH_IILB_OVER_RIDE_TABLE`, `SH_PI_OVER_RIDE_TABLE` | | 0 |

VALID (bit 63) is set for entry 0 and for entry NASID mod 128, the same entry for NASID 0. In `0xf0f` the first port's nibble is in bits 3:0 and the second's in bits 13:8; neither port has a route, so there is no `0x20` and no `0x10` or `0x1000`. The chip record's byte `+0x5b` bit 0 is clear, so every write is a plain write with no read-back, and the route word is 0, so no vector register is used.

**The result of `0xffa42a30` (established for the code).** It is the tree barrier (`Tree barrier`, `Tree barrier passed.`, `tree barrier at %I timed out`), a binary tree over the group array that `0xffa445b0` builds for the global master (`Global master is %I`): halfword 0 is the position of record 0, halfword 1 the count, then the record indices. It returns 0 when the barrier completes, and -1 or a negative vector error otherwise (listing: only `mov r8=r0` at `0xffa433b0`, `mov r8=-1` at `0xffa43146` and the error value at `0xffa431f0`). With position 0 and count 1 both child positions (1 and 2) are past the count, so the accesses are local: read `0x1_5003_1550` bit 12, read `0x1_5003_1570` (`SH_XN_MD_NI0_CMP_ENABLE1`) bit 0, write the complement of that bit to `0x1_5003_13f0` (`SH_XN_PI_SIC_CMP_HDR_ENABLE1`) and `0x1_5003_13d0` (`SH_XN_PI_SIC_CMP_EXP_HDR1`), write it to `0x1_5003_1570` (the root flips the phase), then the progress read (`0x81_1003_0000 + 0x80 * slice`, `0xffa0e020`) and progress write. The result is 0, so `cpu_bits` bit 4 is **not set** on a lone node. `0xffa44710` sets bit 4 only on a non-zero return (failed barrier), and then runs the global barrier `0xffa43d20`. Both `0xffa44710` calls in `main_two` behave this way. The earlier reading of `0xffa42a30` as a master selection was wrong.

**Accesses of the route calculation (established as code).** No vector access, no L1 request, no write. Only local 8-byte reads: `0x81_5003_1560` (`SH_XN_MD_NI0_CMP_ENABLE0`, the debug word) bit 5 and bits 1:0, `0x81_5003_1550` (`SH_XN_MD_NI0_CMP_EXP_DATA1`, `cpu_bits`) bits 1 and 10 and the slice bits 26 to 29 (`0xffa0ff30`, the master-slice gate), and, only when bits 1 and 10 are both set, `0x81_1006_0580` (`SH_SHUB_ID`, `0xffa0dcf0`) before `0xffa464f0` prints the node table. Nothing is compared and kept: the values are only the debug word and `cpu_bits`. The prints (`0xffa423a0`, `0xffa17770`) go through the console path, not traced here.

**`SH_SCRATCH1` (`0x1_101d_0080`) bits 39 and 40.** Bit 39 is set, with bits 55:54 rewritten, only by `0xffa5d2a0`, reached from slot 56 (`0xffa5df20`), whose only caller is the crawl's neighbour step `0xffa45780` (a port with its link bit set); also by `0xffa0aee0` (the failure halt `0xffad2cb0`) and `0xffa60a70` (not reached without a neighbour: inferred). It is neither set nor cleared on a lone node (established for the callers found). Bit 40 is set only by `0xffa4eb40(nasid)`, called at `0xffad748c` in `main_three` after progress 0x23, and by slot 63 (`0xffa60550`, no caller found in the SAL_B code). So on a first boot bit 40 is clear while `main_two` runs: slot 57 stores NASID 0xffff, which `0xffa4d390` replaces. Neither bit is cleared by SAL_B. A value left in the register by an earlier boot is **unknown**.

**After the walk (inferred for the last call).** `main_two` calls `0xffa44710` again (barrier, as above), reads the local NASID from record 0 (`0xffa0aab0`), writes progress 0x1e and calls `0xffacd2b0`. That clears `cpu_bits` bit 21 + slice, prints `Flushing caches and changing nasid...` and calls `0xffaf5f90`, which flushes caches and jumps to a routine passed to it. Both are read in full in [the next section](#the-nasid-change-and-the-node-id-install-0xffacd2b0-to-main_three).

### Review (route calculation, and the corrections it makes to the walk)

Independent re-read on 2026-11-16 in the Ghidra decompiles of snprom 10.54 (`0xffa47290`, `0xffa450e0`, `0xffa42a30`, `0xffa44710`, `0xffa4d390`, `0xffa53650`, `0xffa535c0`, `0xffa5b5d0`, `0xffa5e880`, `0xffa5e0b0`); no IA-64 objdump and no instruction listing for these. At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.

**Which byte: `+0x2b` of the descriptor is `+0x5b` of the node table entry.** Settled. `0xffa450e0` copies the nine doublewords of a descriptor to entry `+0x30` (entry stride `0x48`), slot 57 and slot 59 take the descriptor pointer (`entry + 0x30`) and use `+0x2b`, and the walk indexes the entry directly and uses `+0x5b`; `0x30 + 0x2b = 0x5b`. `0xffa47290` does `|= 2` on offset `0x2b` of its local copy (the stack byte sits `0x2b` above the copy's first word) before calling `0xffa450e0`. The port records are a separate array (entry `+0x60`, stride `0x28`), and slot 57's per-port write to their `+0x2b` (bit 0 the link mask bit, bit 1 the complement of `SH_NI0_LLP_RESET_EN` bit 0) is a different byte, as the page now says.

**Confirmed.** With `cpu_bits` bit 4 clear and no record carrying flag `0x1000000`, the walk selects a record by byte `+0x5b` bit 1, so the local record, which `0xffa47290` marks, runs slot 59; the earlier statement that slot 59 is skipped on a lone node was wrong. `0xffa44710` sets bit 4 only when `0xffa42a30` returns non-zero, and a zero return takes the other branch (`0xffa9a130(4, 1)`, return 0). `0xffa42a30` returns 0 on completion, -1 on a timeout and a vector error value otherwise (return sites read); its position-0, count-1 path (the local accesses of `0x1_5003_1570` listed above) was not re-derived. The port tables are allocated per port by `0xffa53650` and filled with `0xff` by the pool allocator (a memset), the local table 128 bytes and the global table 16 (slot 47 and 48 sizes, `0xffa5d590` and `0xffa5d5a0`); a third table only for part `0x239`. The NASID environment variables are looked up as `NASIDOffset`, `NASIDStride` and `RtrRoutes` with defaults offset 0, stride 2 when the debug word bit 5 is clear.

**Table values.** The values for NASID 0 follow from my own decompile of slot 59: with every table nibble `0xf`, a local NI table entry is `0xf` with VALID only at entry 0 (and at the node's index, the same entry), the MD, IILB and PI words are `0xf0f` (the first nibble `0xf`, the second `0xf` again) with VALID by the same rule, the global tables take no VALID, no neighbour sets bits 4 or 12, and the overrides are written 0. They match the table.

**Not confirmed.** The NASID the route calculation stores (0 on a lone node: the arithmetic of `0xffa4d390` was skimmed, not traced), `0xffa4a740` returning 0, the callers of `0xffa5d2a0`, and the claims about `SH_SCRATCH1` bit 40 setters (`0xffa4eb40`, slot 63). The per-port field offsets inside the port record (`+0x38`, `+0x40`, `+0x48` relative to the array entry) agree between the allocator and slot 59 but were not tied to the `0x28`-byte records' own layout.

**Grades.** As on the section: established as code for the reads above; the lone-node premise (one record, both ports down) stays the premise.

## The NASID change and the node-id install: `0xffacd2b0` to `main_three`

Same image and method as the sections above (snprom 10.54, `shub1snprom.bin`, flat at `0xffa00000`; Ghidra IA-64 `--sn2-prom --no-analysis` over the named addresses, every function below read in a Ghidra decompile and an `ia64-linux-gnu-objdump` listing, call targets and branch tests taken from the listing). Names are the 2.4 SN2 header (`shub_mmr.h` at 8ef7d46c) and the PROM name table at `0xffbfabb0`. Not independently reviewed. The flow of the stages, the PAL calls and the CPU-side effects are on the [boot sequence page](../../software/firmware/snprom/boot-sequence.md#the-nasid-change-and-the-start-of-main_three). All SHub accesses are 8 bytes. "Global" is `0x8000_0009_0000_0000 | nasid << 38 | offset` (`0x1_xxxx_xxxx` offsets), "local" is `0x8000_0081_xxxx_xxxx`.

**What a lone node does here (established for the code, inferred for the values).** Node record 0 holds NASID 0 (the route calculation above), so `0xffa976e0` rewrites the NASID field with the value it already has: no window moves, every global-window address keeps its NASID. The values that vary with the NASID (`cr.lid`, interrupt pids, address bits 48:38) are given for NASID 0 and for the general case.

### The SHub accesses of the install, in order

| # | Where | Access | Offset (window) | Name | Value and test |
|---|---|---|---|---|---|
| 1 | `0xffacd2b0` | RMW | `0x1_5003_1550` (local) | `cpu_bits` (`SH_XN_MD_NI0_CMP_EXP_DATA1`) | clear bit 21 + slice, under the lock pair at `0x1_101d_0200`/`0208` (`0xffa0eae0(21 + slice, 0)`); every CPU |
| 2 | `0xffacd1e0` | barrier | `cpu_bits` | | `0xffa9a130` (every CPU, before the master writes anything) |
| 3 | `0xffa976e0`, master slice only (`0xffa0ff30`) | | | | progress 0x59 "Writing new node ID to chipset" |
| 4 | | R, W, R | `0x1_2001_0100` (local) | `SH_FSB_SYSTEM_AGENT_CONFIG` (our key `pi_reg_2001_0100`) | read; write with bit 24 (`serialize_fsb_en`) set; read back (value unused) |
| 5 | slot 33 `0xffa95a30` | R | `0x1_1006_0580` (global, route word of the node object `[obj+24]`, normally 0, NASID `[obj+0]` = the NASID the chip had) | `SH_SHUB_ID` | any; the other bits are kept |
| 6 | | W | the same | `SH_SHUB_ID` | read value with bits 42:32 = new NASID (A), 45:44 = f(B), 52:48 = g(C) (rules on the [SHub ID section](#the-shub-id-register)); for NASID 0, B = 0, C = 0: 0, 0, 1 |
| 7 | `0xffa976e0` | R | `0x1_2000_0000` (local) | `SH_CRB_MESSAGE_CONTROL` | value kept |
| 8 | | R | `0x1_1006_0580` (local) | `SH_SHUB_ID` | bits 31:28 (revision): below 3 chooses `0x3f1`, otherwise `0x3b03f7` |
| 9 | | W | `0x1_2000_0000` (local) | `SH_CRB_MESSAGE_CONTROL` | value of row 7 OR the mask |
| 10 | | W | `0x1_2001_0100` (local) | `SH_FSB_SYSTEM_AGENT_CONFIG` | row 4's value with bit 24 cleared (the read-back is not reused: any bit set by someone in between is lost) |
| 11 | | | | | progress 0x5a "New node ID written to chipset"; barrier `0xffa9a130` |
| 12 | `0xffad7aa0` | | | | progress 0x1f "Calling node id install routines" |
| 13 | `0xffaec240` (every CPU) | W, R | `cr.lid` | | write `cr.lid` bits 31:16 = `nasid & 0x7f` (bits 22:16), slice (bits 26:23), `(nasid >> 7) & 0x1f` (bits 31:27); read back bits 31:16 and compare; mismatch: progress 0xc3 "Could not write new value to cr.lid" and a halt (`0xffad2c50`) |
| 14 | `0xffaec340` (master) | 21 pairs | see below | interrupt CONFIG and ENABLE pairs | rewrite the target processor id |
| 15 | stubs `0xffa97950`, `0xffb91700`, `0xffb91280` | | | | return at once (the last returns 0); nothing accessed |
| 16 | `0xffa733d0` (master) | R, W, W | `0x1_0003_0000` (global, new NASID), `0x1_0003_0000`, `0x1_0005_0000` | `SH_MD_DQLP_MMR_DIR_CONFIG`, `SH_MD_DQRP_MMR_DIR_CONFIG` | bits 2:0 of the first replaced by a class from C: C >> 1 below 0x40 gives 0, below 0x80 gives 1, below 0x100 gives 2, below 0x200 gives 3, else 4; the same word written to the second without reading it. For C = 0, bits 2:0 = 0 |
| 17 | | barrier; progress 0x20 "Switching to new node id" | | | `0xffa9a130`, then `0xffafba70` |

B and C come from `0xffa4f1a0` and `0xffa4efa0`, called at the end of `0xffa4d390`: B is the highest NASID among the non-router records (byte `+0x5a` not 2) that do not carry flag `0x10000` in the word at `+0x68` and agree with record 0 in NASID bits 10:9; a record whose byte `+0x6c` is non-zero also contributes a value built from that byte. C starts from B and takes the highest NASID of any non-router record or, for a record whose byte `+0x6d` is non-zero, `(1 << (byte + 6)) - 1`. One record with NASID 0 gives B = 0, and C = 0 if the two bytes are 0 (inferred: the bytes were not traced). B and C also reach row 6 through the argument list of slot 33 (A, B, C in that order).

### The 21 interrupt pairs rewritten by `0xffaec340`

For each entry of the table at `0xffbbc750` (16 bytes: CONFIG offset, ENABLE offset; ends at a zero CONFIG), master slice only, after the NASID write: read ENABLE in the **new** NASID's global window; if it reads 0, skip; else read CONFIG in the local window, replace bits 19:4 with `(nasid & 0x7f) | (old bits 14:11, the slice) | ((nasid >> 7) & 0x1f) << 11` (so bits 10:4 = NASID[6:0], bits 14:11 unchanged, bits 19:15 = NASID[11:7]), and write CONFIG in the global window of the new NASID. Established as code; the names are the PROM name table's, offsets are the table's. All offsets are `0x1_1000_xxxx`.

| Walk | CONFIG | ENABLE | Name (`SH_..._CONFIG`, `SH_..._ENABLE`) |
|---|---|---|---|
| 0 | `0080` | `0200` | `II_INT0` |
| 1 | `0180` | `0280` | `II_INT1` |
| 2 to 7 | `0480` + `0x100 * n` | `0500` + `0x100 * n` | `LOCAL_INT0` to `LOCAL_INT5` |
| 8 to 11 | `0c80` + `0x80 * n` | `1080` + `0x80 * n` | `PROC0_ADV_INT` to `PROC3_ADV_INT` |
| 12 to 15 | `0a80` + `0x80 * n` | `0e80` + `0x80 * n` | `PROC0_ERR_INT` to `PROC3_ERR_INT` |
| 16 | `1280` | `1300` | `PROFILE_INT` |
| 17 | `1380` | `1400` | `RTC0_INT` |
| 18 to 20 | `1480` + `0x100 * (n - 18)` | `1500` + `0x100 * (n - 18)` | `RTC1_INT` to `RTC3_INT` |

The 2.4 header gives `SH_PROC0_ERR_INT_CONFIG` at `0x1_1000_0a80` with mask `0x0ff3ffffffefffff` and INIT 0, and INIT 0 for `SH_PROC0_ERR_INT_ENABLE`, `SH_PROFILE_INT_ENABLE`, `SH_II_INT0_ENABLE` and `SH_RTC1_INT_ENABLE`; the other pairs' INIT lines were not read one by one (inferred the same). Before this step the PROM has already written 1 to both `II_INT` enables (`0xffb73a40`) and 0x7ef or 0x4000 to the `LOCAL_INT` enables (`0xffa23a20`, `0xffa31290`), so on a model that keeps written values those pairs are rewritten; for NASID 0 the rewrite produces the pid the PROM stored already (slice in bits 14:11, NASID bits 0), so the result is unchanged. A model that returns 0 for every ENABLE skips all 21 writes and reaches the same state.

### The window move, and the second jump (`0xffafba70`)

Established: nothing moves the old global window. After row 6 the PROM addresses the chip through the new NASID only: row 14 reads ENABLE through it, row 16 reads `0x1_0003_0000` through it, and `0xffa0dcf0` (local window) reads the new NASID. A model must therefore decode the global window of the NASID stored in `SH_SHUB_ID` bits 42:32 from the write on, and may stop decoding the old one (the PROM does not touch the old one after row 5/6 and does not read back through it). For NASID 0 nothing changes. A nonzero NASID also needs the node-window RAM layout rebuilt, which `main_three` does (`0xffac42d0(1, nasid, 1)`, `0xffadee60`); the RAM view of the node moves with the NASID (inferred from that rebuild: the physical form `nasid << 38 | 0x30_0000_0000` is how the PROM addresses its node-window arenas).

`0xffafba70(descriptor of main_three)`: reads the NASID through `0xffa0dcf0` (three times), builds two arena addresses in the new node window, `(nasid << 38) + 0x30_0000_0000 | 0x300_0000` plus 1 MiB per slice (table `0xffbe6c08`: four entries of 1 MiB) plus `0x180` (table `0xffbe71c8`, whose entries 0 and 1 are odd markers and are skipped), and a third from `0x30_0200_0000` (tables `0xffbe6b78`, `0xffbe7b48`). It calls `0xffaf5f90(0x3ffff, base + 0x3fff0, base, gp, entry, 0)`: sp at base + `0x3fff0`, backing store at base (a cached address, no bit 63), no flush (the type field is 0), gp and entry masked with `0x7fffffcfffffffff` (`0xfface7d0`; for `0xffd98000` and `0xffad7280` the mask changes nothing), and a jump to `main_three` (`0xffad7280`) with argument 0. Established as code; the arena addresses depend on the RAM layout the earlier steps built and are inferred for a real run.

### The memory scrub `0xffae3160` on a lone node

Called from `main_three` after progress 0x22. Master slice: `0xffa21350(0, nasid, nasid, 0)` and `0xffa23600` (decoded in [the section below](#the-rest-of-main_three-up-to-the-io-discovery-on-a-lone-node): the interrupt destination and enable writes, and five processor-interface mask writes), then the barrier. Then set bit 13 of `0x1_5003_1540` (`0xffa0f780(13)`), `0xffa23e00(0)` (for each slice i with `cpu_bits` bit 26 + i set: write 0 to `SH_LOCAL_INT0_ENABLE` for i = 0, 1 or `SH_LOCAL_INT1_ENABLE` for i = 2, 3, global window, 8 bytes), read the environment variable `WrbWARCnt` (default `20`, clamped to 0 to 32; call n), ask the node object for the port count (slot 49, 2) and the mask of ports with a link up (slot 54, `shub_port_status`, inferred from the slot offsets `+0x188` and `+0x1b0` matching those NI methods). With no port up (`SH_NI0_LLP_STAT` low nibble not 9, the lone node), the mask is 0 and the PROM prints `NOTICE:  no NI ports are up, ICC underflow WAR disabled`, then `0xffa23e00(1)` (writes 0x7ef instead of 0), clears bit 13 and runs the barrier. Established as control flow; nothing else is accessed.

With a port up (not the lone node; established as code): k = bits 48:45 of the scrub address `(((nasid ^ 0x400) << 38) + 0x30_0000_0000 + 16 GiB - n * 128)` (0x8 for NASID 0); read `SH_PI_GLOBAL_TABLE[k]` (`0x1_5002_1400 + 8k`, local window), write it `0xf0f | b << 13 | b << 5` (b = the first port up, 0 or 1); read and write `SH_CRB_TIMEOUT_PRESCALE` (`0x1_2000_0100`) = `0x5f5e06`; read and write `SH_CRB_TIMEOUT_SKID` (`0x1_2000_0180`) = `(old & ~0x3f) | (n + 2)`; unless `cpuid[2]` is `0xaeeeeeee8badbeef`, wait 4,000,000 microseconds (`0xffa0db90`; 80,000,000 RTC ticks at the 50 ns tick the PROM sets), store 0 to n 8-byte words 128 bytes apart at the scrub address, wait 1,000,000 microseconds (20,000,000 ticks); `0xffa30b40(nasid, 5)`; then write back SKID (with bit 63 set in the stored value), PRESCALE, the PI table entry and call `0xffa24810`. The waits poll `SH_RTC` (`0x1_101c_0000`) in `0xffa0db90`; nothing else is polled. The bodies of `0xffa30b40` and `0xffa24810` are in [the section below](#the-rest-of-main_three-up-to-the-io-discovery-on-a-lone-node).

### Main_three's SHub accesses on the way to the I/O discovery

The step list with progress codes and function addresses is on the boot sequence page. SHub accesses of the functions read: `0xffa97960` ([above](#the-node-permission-set-up-0xffa97960)); `0xffa73590` (rows of the slot 97 table above); `0xffae3160` (previous section); `0xffa44710` and `0xffa44950` (tree barrier, local reads of `cpu_bits` bit 12 and `SH_XN_MD_NI0_CMP_ENABLE1` as in the route calculation section; on a lone node they return 0); `0xffa4eb40(nasid)` (R and W of `SH_SCRATCH1`, global window of NASID, sets bit 40 and keeps the rest; then two reads of `SH_FSB_SYMMETRIC_AGENT_STATUS` and RAM); `0xffa44e50`, `0xffa0a850`, `0xffa1f960` and `0xffacddf0` (RAM only; `0xffacddf0` flushes 0x100 bytes at physical `0x1000000` with `fc`, `sync.i` and `mf`); `0xffafbca0` (the flash checksum: CFI probe and, if it answers, 1 MiB of 8-byte flash reads; below); `0xffa1a9e0` and `0xffa1ac80` (call node-object methods, among them the node set-up, slot 5; below).

### The rest of `main_three` up to the I/O discovery, on a lone node

Same image and method as the sections above (snprom 10.54, Ghidra IA-64 `--sn2-prom --no-analysis` over the named addresses, call targets and branch tests checked in an `ia64-linux-gnu-objdump` listing). Names are the PROM name table's (`SH_` prefix) and the 2.4 header's. Not independently reviewed. All accesses are 8 bytes through the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store) unless a row says otherwise. "Global" is `0x8000_0009_0000_0000 | nasid << 38 | offset`. The call order in `main_three`, for NASID 0 on the master slice (the other slices run only the barriers and the tests that name them): `0xffae3160` (`0xffa21350`, `0xffa23600`; `0xffa24810` and `0xffa30b40` through it), `0xffa4eb40`, `0xffafbca0`, `0xffa1a9e0`, `0xffa1ac80`. The four calls under `if nasid != 0` (`0xffae0a00`, `0xffac7f90`, `0xffacda00`, `0xffa1f740`) do not run (established: the test is `0xffa0dcf0` returning nonzero).

| Routine | Runs on a lone node | Condition |
|---|---|---|
| `0xffa21350` | yes | master slice (`0xffa0ff30`) |
| `0xffa23600` | yes | same |
| `0xffa30b40` | called from `0xffa23a20` (the body of `0xffa21350`'s method) | its mask is `SH_EVENT_OCCURRED & 0x7ef`; a zero read writes nothing |
| `0xffa24810` | no | only with a port up in `0xffae3160` (`SH_NI0_LLP_STAT` low nibble 9 on port 0 or 1) |
| `0xffa4eb40` | yes | master slice |
| `0xffafbca0` | yes | master slice; the flash part is skipped when `cpuid[2]` is the simulator value `0xaeeeeeee8badbeef` |
| `0xffa1a9e0`, `0xffa1ac80` | the walk runs; whether its body does anything depends on a record flag that was not traced | master slice |
| `0xffae0a00`, `0xffac7f90`, `0xffacda00`, `0xffa1f740` | no | `main_three` calls them only when the NASID read from `SH_SHUB_ID` is nonzero |

#### `0xffa21350` (called as `(0, nasid, nasid, 0)`)

Established. A wrapper: it builds the node object of each NASID argument (`0xffa0fa00`, a 40-byte copy with the method table pointer at `+0x20`) and calls method `+0x2b8` of the first object's table, passing both objects. On SHub 1 (part `0x4363`, table `0xffbd7c18`) that method is `0xffa23a20`, the interrupt-destination and error-enable code already traced under "Slot 85" above, and it ignores the wrapper's fourth argument. For the lone node both objects are node 0:

| # | Access | Offset (global window of NASID) | Name | Value |
|---|---|---|---|---|
| 1 | tests only | `cpu_bits` bit `26 + i` (`0xffa0ecd0`, local read of `0x1_5003_1550`) | | slices that fail the test are skipped; the loop runs i = 0 to 3 |
| 2 | W, per present slice | `0x1_1000_0480` (i = 0, 1) or `0x1_1000_0580` (i = 2, 3) | `SH_LOCAL_INT0_CONFIG`, `SH_LOCAL_INT1_CONFIG` | `0x0010_0000_0000_0002 \| id << 4`, `id = ((nasid >> 7) & 0x1f) << 11 \| (nasid & 0x7f) \| i << 7` (`id` = 0 for NASID 0 slice 0; type 2) |
| 3 | W, only when the two NASIDs differ | `0x1_1000_0300` | `SH_INT_NODE_ID_CONFIG` | local NASID `\| 0x800` (not on a lone node) |
| 4 | W, per present slice | `0x1_1000_0500` (i = 0, 1) or `0x1_1000_0600` (i = 2, 3) | `SH_LOCAL_INT0_ENABLE`, `SH_LOCAL_INT1_ENABLE` | `0x7ef` |
| 5 | R, once | `0x1_1001_0000` | `SH_EVENT_OCCURRED` | any; `v & 0x7ef` is passed to `0xffa30b40` (below) |

The destination and enable offsets are the two 4-entry tables at `0xffbd9568` (`0480`, `0480`, `0580`, `0580`) and `0xffbd9588` (`0500`, `0500`, `0600`, `0600`), indexed by slice. Before row 2 the routine `0xffa20e30` records the node in a RAM table (`[[0x1000038 + 0x90]] + 0x4dc`, 40-byte entries, replacing the entry that already holds this NASID, the second time through) and returns 0 only if the table already holds `0x80` entries; the SHub rows are skipped then. No poll, no wait, no print. Grade: established (code, tables, values); inferred (that `id` is the SAPIC id form, `0` for NASID 0 slice 0).

#### `0xffa30b40(nasid, mask)`

Established. For each set bit `j` of `mask` (bit 0 first) it writes list `j` of the pointer array at `0xffbdd010` through `0xffae3f50`. Called with `SH_EVENT_OCCURRED & 0x7ef` from row 5 above: a model that returns 0 for `SH_EVENT_OCCURRED` writes none of the lists. In `0xffae3160` it is called with 5 (lists 0 and 2) only on the port-up path. The lists, by bit, as `offset = value` (offsets are written after the leading `0x1_`; counts are the stores; every list starts with the two alias clears; "clear" is the PROM's word for the write, the aliases are write-one-to-clear by their name only: inferred):

| Bit | Block | Stores |
|---|---|---|
| 0 | processor interface, 11 | `1001_0008 = 1`, `1001_0088 = 1` (`SH_EVENT_OCCURRED_ALIAS`, `SH_EVENT_OVERFLOW_ALIAS`), `1007_1000 = 0` (`SH_FIRST_ERROR`), `2006_0688`, `2006_0608`, `2006_0788`, `2006_0480`, `2006_0080` = `7_9fff_fe7f` (`SH_PI_ERROR_SUMMARY_ALIAS`, `SH_PI_ERROR_OVERFLOW_ALIAS`, `SH_PI_FIRST_ERROR_ALIAS`, `SH_PI_CRBP_FIRST_ERROR`, `SH_PI_AFI_FIRST_ERROR`), `2006_0500`, `2006_0580`, `1007_1380` = 0 (`SH_PI_ERROR_DETAIL_1`, `_2`, `SH_PI_HW_TIME_STAMP`) |
| 1 | memory, 12 | aliases `= 2`, `1007_1000 = 0`, `0000_00c0`, `0000_00d0 = 7_f444_470f` (`SH_MEM_ERROR_SUMMARY_ALIAS`, `SH_MEM_ERROR_OVERFLOW_ALIAS`), `0000_0090`, `0000_0088 = 0` (`SH_MISC_ERR_HDR_UPPER`, `_LOWER`), `0003_3040`, `0003_3840`, `0005_3040`, `0005_3840 = 0x4000_0000_0000_0000` (`SH_MD_DQLP_MMR_XPERR`, `_YPERR`, `SH_MD_DQRP_MMR_XPERR`, `_YPERR`), `1007_1200 = 0` (`SH_MD_HW_TIME_STAMP`) |
| 2 | crossbar and network, 41 | aliases `= 4`, `1007_1000 = 0`, then the `SH_XN_*`, `SH_XNIILB_*`, `SH_NI0_*`, `SH_NI1_*`, `SH_XNMD_*`, `SH_XNPI_*` summary and overflow aliases (`SH_XN_ERRORS_ALIAS` `3f_9f3f_ffff`; `SH_XNIILB_*` and `SH_NI0_*_1` all ones; `SH_NI0_*_2` `7fff_ffff_003f_ffff`, the `SH_NI1_*_2` ones all ones; `SH_XNMD_*` and `SH_XNPI_*` `3_ffff_f807_ffff`), the matching `FIRST_ERROR` and `ERROR_DETAIL` words = 0, `SH_NI0_LLP_ERR` (`5000_0048`) and `SH_NI1_LLP_ERR` (`5000_2048`) = 0, `SH_XN_HW_TIME_STAMP` (`1007_1900`) = 0 |
| 3 | local block, 13 | `SH_LB_ERROR_DETAIL_1` to `_5` (`1005_0200`, `0280`, `0300`, `0380`, `0400`) = 0, `SH_JUNK_ERROR_STATUS` (`1003_0200`) = 0, aliases `= 8`, `1007_1000 = 0`, `SH_LB_HW_TIME_STAMP` (`1007_1100`) = 0, `SH_LB_ERROR_SUMMARY_ALIAS`, `SH_LB_ERROR_OVERFLOW_ALIAS` (`1005_0588`, `0508`) = `7f_ffff`, `SH_LB_FIRST_ERROR` (`1005_0600`) = 0 |
| 4 | none | entry `0xffba2028` is a zero terminator |
| 5 to 10 | the corrected and uncorrected variants for the processor interface (5, 8), memory (6, 9) and crossbar (7, 10) | aliases `= 0x20, 0x40, 0x80, 0x100, 0x200, 0x400`, `1007_1000 = 0`, the block's `*_CORRECTED_DETAIL_*` or `*_UNCORRECTED_DETAIL_*` and `*_COR_TIME_STAMP` or `_UNCOR_TIME_STAMP` words = 0, and the block's summary and overflow aliases (and for the processor interface the two `FIRST_ERROR` words) = the constant for that case: PI `4000_0100` (5), `2000_0080` (8); memory `222_20a0` (6), `111_1050` (9); crossbar `2040_0000` (7) and `4080_0000` (10) for `SH_XN_ERRORS_ALIAS`, `78_0000` (7) and `780_0000` (10) for `SH_XNPI_*` and `SH_XNMD_*` |

Counts 11, 12, 41, 13, 0, 13, 14, 17, 13, 14, 17 for bits 0 to 10 (read from the image, one terminating zero offset each). The list contents were decoded by script against the name table; rows above abbreviate repeated registers. No wait.

#### `0xffa23600`

Established. Reads `SH_SHUB_ID` (local, `0xffa0dcf0`), looks up the environment variable `AttrCheck` (`0xffad6e30`, no buffer: only the sign of the result is used), reads `SH_SHUB_ID` again and writes one 5-entry list through `0xffae3f50` at `0x8000_0008_0000_0000 | nasid << 38 | offset` (global window, bit 32 of each offset set). A result with bit 31 clear (variable present) selects the list at `0xffbd92d8`; bit 31 set (a negative status, variable absent) selects `0xffbd9388`. No default is set in the code, so the absent case is the stock path (inferred from `0xffad6e30` returning a negative status for a missing name, as in the earlier error-list section). Both are in the image right after the earlier `PI_*` lists (`0xffbd9280`, `0xffbd9330`, written by the chip-object method in `main`), with the same five registers; the new values differ only in bit 32:

| Order | Offset | Name | `AttrCheck` set | `AttrCheck` absent | Earlier write, same register |
|---|---|---|---|---|---|
| 1 | `0x1_2005_0a80` | `SH_PI_ERROR_MASK` | `0x8020_0000` | `0x8320_0000` | `0x1_8020_0000` / `0x1_8320_0000` |
| 2 | `0x1_2005_0080` | `SH_PI_AFI_ERROR_MASK` | `0x8020_0000` | `0x8320_0000` | same |
| 3 | `0x1_2005_0500` | `SH_PI_CRBP_ERROR_MASK` | `0x8020_0000` | `0x8320_0000` | same |
| 4 | `0x1_2006_0080` | `SH_PI_AFI_FIRST_ERROR` | `0x7_7fdf_ffff` | `0x7_7cdf_ffff` | `0x6_7fdf_ffff` / `0x6_7cdf_ffff` |
| 5 | `0x1_2006_0480` | `SH_PI_CRBP_FIRST_ERROR` | `0x7_7fdf_ffff` | `0x7_7cdf_ffff` | same |

Bit reading (2.4 header, `SH_PI_ERROR_MASK` field list; the register's INIT is all ones, so a set bit masks the source, established): `0x8320_0000` is `livelock` (31), `addr_access` (25), `req_format` (24) and `hung_bus` (21); `0x8020_0000` is `livelock` and `hung_bus`. Bit 32 is `bad_snoop`. So the earlier list left `bad_snoop` masked and this one unmasks it; the header's valid bits are 34:0 for `SH_PI_ERROR_MASK`, 34:21 for `SH_PI_AFI_ERROR_MASK` and 20:0 for `SH_PI_CRBP_ERROR_MASK`, so the value's bits outside those ranges (all of them, for the CRBP register) have no register bit to land in. The two `FIRST_ERROR` words take the same constant the clear lists above write to them (inferred as a write-one-to-clear of the recorded first error, so bit 32 now clears a recorded `bad_snoop`). No read-back, no poll, no print. Grade: established (offsets, order, values, window); inferred (which list is the default, the clear semantics).

#### `0xffa24810` (port-up path only)

Established as code; does not run on a lone node. After `0xffa30b40` it zeroes a RAM word (`[[0x1000038 + 0x90]] + 0x5138`) and for i = 0 to 31 calls `0xffa245f0(0x20 + i)`: store `0x1_2005_0300` (`SH_PI_CAM_CONTROL`, local window `0x8000_0081_...`) = `0x8000_0000_0000_0000 | (0x20 + i)`; read `0x1_2006_0100`, `0x1_2006_0180`, `0x1_2006_0200`; repeat the four accesses until two consecutive passes return the same three words (an all-zero first pass is one pass: the saved words start at 0). Bit 4 of the third word sets bit i of the RAM word. No other wait. At least 32 stores and 96 loads.

#### `0xffa4eb40(nasid)`

Established. Master slice.

| # | Access | Offset (window) | Name | Value |
|---|---|---|---|---|
| 1 | R, W | `0x1_101d_0080` (global) | `SH_SCRATCH1` | read; write the read value with bit 40 set (`& ~(1 << 40) \| 1 << 40`) |
| 2 | R, per node entry and slice | `0x1_2002_0080` (global window of the node) | `SH_FSB_SYMMETRIC_AGENT_STATUS` | only for slice k = 0 and 2, once each for every even entry of block A's node table (`[[0x1000038 + 0x10]]`, entry not `-1`; node 0 only on a lone node): bit `k / 2` (0 and 1) nonzero marks the slice present. Slices 1 and 3 return 0 without a read (they read only when `cpuid[2]` is the simulator value) |
| 3 | R, per present slice | `cpu_bits` bit `26 + k` (`0x1_5003_1550`, local for the local node) through node-object method `+0x100` (`0xffa0ebc0`) | | the bit is stored as a 0 or 1 flag in the RAM table; not tested |
| 4 | RAM | `[[0x1000038 + 0x18]]` | | one 4-byte entry (`sapic id form`, flag) per present slice, ended by `0xffff, 0` |

The slice test of row 2 is the same register `0xffa11560` reads in the SAL_A section; for a one-CPU node bit 0 is set and bit 1 is clear, for two CPUs both are set (inferred). A node with no bit set gets an empty table; nothing else reads the value on this path.

#### `0xffafbca0(nasid)`: EFI variable store checksum and RAM record

Established as code. Master slice. First `0xffaf6d10(nasid)`:

1. Prints `Checksumming EFI variable store ...` (debug-level print `0xffa17770`) and allocates 64 KiB of RAM (`0xffac30c0`). If the allocation fails it prints an error and stops here (not on this path).
2. Builds a flash-access context with `0xffacea70` (RAM only: the flash base `nasid << 38 | 0x8000_000f_ff80_0000`, that is physical `0xf_ff80_0000` in the node's window, uncached) and probes it with `0xffaceb80`. Unless `cpuid[2]` is the simulator value, the probe first claims bit 2 of `0x1_5003_1540` (the flag-word claim of the node lock section, `0xffa0f1a0`: R `0x1_101d_0188` until bit 0 clear, R and W `0x1_5003_1540`, W 0 to `0x1_101d_0180`; the deadline argument is 0, so no timeout; `0xffa0f650` clears the bit afterwards), then runs the flash probe `0xffad22f0` with these 16-bit accesses at the flash base (byte offsets): W `0x00f0` at +0; W `0x00aa` at +`0xaaa`, W `0x0055` at +`0x554`, W `0x0090` at +`0xaaa`; R at +0 (manufacturer, stored); W `0x00f0` at +0; the same three writes; R at +2 (device, stored); W `0x00f0` at +0; W `0x0098` at +`0xaa` (CFI query); R at +`0x20`, `+0x22`, `+0x24` (must be `0x51`, `0x52`, `0x59`), `+0x26` (must be 2), `+0x28` (must be 0), `+0x4e` (log2 of the size), `+0x50`, `+0x58` (erase-region count, at most 4), then the region descriptors from `+0x5a`, `+0x54`; W `0x00f0` at +0. Any failed comparison, an interface code `(v + 1) & 2 == 0` at `+0x50`, a region count above 4 or a size below 8 MiB (the context's size field after the probe) makes `0xffaceb80` return -1.
3. If the probe returned -1 (or the simulator value is set) the checksum is the constant `0x956bac74` and the PROM reads nothing more. That constant is the CRC-32 of 1 MiB of `0xff` (computed: `zlib.crc32(b'\xff' * 0x100000)`), the "empty" store, and it is also the value stored on read errors.
4. Otherwise it reads 16 blocks, flash offsets `0x10_0000` to `0x1f_ffff` in steps of 64 KiB, as 4 KiB chunks through `0xffacef00`/`0xffad2940` (each chunk takes the same bit-2 claim and clear; aligned 8-byte uncached loads, bytes passed to a callback that stores them into the 64 KiB buffer), and takes a CRC-32 over them (`0xffb530b0`, table `0xffbd08a0`, initial value `-1`, result inverted). On any read error it prints a message and uses `0x956bac74`.
5. Prints `" = 0x%x%s\tDONE\n"` (the suffix `" (empty)"` when the value is `0x956bac74`, debug-level), stores the low 32 bits into the RAM record `[[0x1000070 + 0x80]]` of the node, and frees the buffer.

Then `0xffafbca0` stores three RAM words (`[[[0x1000038] + 0x98]]`, `+8` and a 32-byte record at `[[0x1000038] + 0xb8]`) from constants in the image (`0xffc4d918` to `0xffc4d968`; `& 0x1fff_ffff_ffff_ffff` on the first two): no SHub access. Grade: established (offsets, order, constants); inferred (that the unreadable-flash case simply prints "empty", from the control flow). No poll; the lock claim waits only if bit 2 of `0x1_5003_1540` or bit 0 of `0x1_101d_0188` stays set. A model has two ways to keep this path: give the flash window a CFI responder that returns the checksummed bytes, or return anything that is not `0x51` at +`0x20` (for example all ones) and the PROM skips the 1 MiB read.

#### `0xffa1a9e0` and `0xffa1ac80`

Established as code. These are not leaf routines: they walk the node records (`[[0x1000038 + 0x30]]`, 0x48 bytes each; byte `+0x5a` is the type, 1 or 3 for a node that is not a router, 2 for a router) and call a method of each record's object (`rec + 0x20` is its method table; method `+0x28` is slot 5, `+0x30` is slot 6 of the class-0 table at `0xffbd7c18`). The decompiler showed the object pointer as a stack argument because the record copy is 40 bytes and its last word lies at the frame top. Slot 5 is `0xffacc6e0`, the node set-up traced under "Slot 5 after the permission set-up"; the earlier text said its caller was not found, and this is the caller.

`0xffa1a9e0(flags)`, master slice, `flags = 0xffa17b90(0)`, which on a lone node is `(0x1_5003_1560 & 3)`, plus `0x10` when bit 2 of the same word is set (local reads, `0xffa97660`, `0xffa975e0`; the word is the debug-switch word): for each record of type 1 or 3 whose byte `+5` equals the local record's byte `+5`, if record flag `0xb` (word `+0x68` bit 16) is set and flag `0x13` (byte `+0x5b` bit 0) is clear, call `0xffa1a6d0(rec)`: read `SH_SCRATCH1` (`0x1_101d_0080`, global window, through slot 45; bit 56 set returns 1 at once); otherwise claim bit `0x11` of `0x1_5003_1540` (`0xffa0f1a0` path as above), read `SH_SCRATCH1` again, write it with bit 56 set (slot 46), clear the claim; return 0. If it returned 0, set record flag `0xc` and call slot 5(rec, id, flags). A read error logs and returns 1 (skip).

`0xffa1ac80(flags)`, master slice: for each record of type 1 or 3 with flag `0xc` set, call slot 6, `0xffaccae0(rec, id, flags)`: debug print `Late initialization of headless node %I`, then the methods at `+0x128` (slot 37, `0xffa96440`), `+0x300` (slot 96, `0xffa1efc0`), `+0x310` (slot 98, `0xffa6a310`), `+0x20` (slot 4, `0xffacc680`), `+0x200` (slot 64, `0xffa606b0`), `+0x290` (slot 82, `0xffa918b0`), `+0x320` (slot 100, `0xffaacbc0`), `+0x2b0` (slot 86, `0xffa23990`), `+0x2e8` (slot 93, `0xffaadc10`), each with `(rec, flags, f)` where `f` is record flag `0x15` (set only when the node has no memory). Slots 37, 96, 64, 82, 100 and 86 are empty. With `f` = 0 (memory present) slot 98 zeroes a RAM word of the node's record and slot 4 (`0xffaf72e0(nasid)`) runs: for each node-table entry (even index, not `-1`) it calls `0xffa788b0`, which reads `SH_JNR_DIMM_CFG` (`0x1_0001_0010`, see the slot 97 table; nonzero when any bank is populated), collects the EFI-store checksums of the nodes with memory from RAM (skipping `0x956bac74`), combines them (`0xffb55b60`, not read), prints once at debug level, and only if the combined value differs from this node's does it repeat the flash probe and read of `0xffafbca0` on another node. On a lone node there is one candidate, so the two values are equal (inferred; `0xffb55b60` was not read). Slot 93 (`0xffaadc10`) runs whatever `f` is: it calls `0xffab38b0(nasid)`, the entry of the I/O discovery. `0xffab38b0` tests `cpu_bits` flag 2 (`0xffa99870(obj, 2)`) and runs `0xffab15c0` only while flag 2 is clear; `main` sets flag 2 only when the I/O interface set-up fails, nothing in `0xffab15c0` was found to set it, and `main_three` calls `0xffaad6d0` (the same `0xffab38b0`) again at progress 0x24. So the discovery body may run twice, once here and once at progress 0x24 (inferred from the flag test; the second pass was not traced to see whether the body is idempotent). Grade: established for the walk, the tests and the methods; unknown for whether a lone node's record has flag `0xb` set (who sets bit 16 of word `+0x68` was not found: the flag-set routine `0xffa13190` is never called with `0xb`), and so for whether slot 5 and slot 6 run here at all, or whether the discovery runs only at 0x24.

#### The four calls for a nonzero NASID

Read at call level only; none runs on NASID 0. `0xffae0a00(nasid)`: master: RAM rewrite of the NASID field in the pointer cells `[0x1000038 + 0x20]` and `[0x1000040 + 0x10]` (bits 48:38), `0xffa9fed0(nasid)` (walks a RAM list of component records, rewriting a NASID field and pointer in each), then rewrites the 16-bit ids of block A's list and the local record (`0xffa0f7e0`): no SHub access. `0xffac7f90`: returns at once. `0xffacda00`: barrier, `0xffa80c50` (saves eight words of the node record, calls `0xffa8f8a0`, the record builder whose `SH_SCRATCH2` and other accesses are in the slot 95 section above, and restores the words) and `0xffa80720` (RAM: sets bit 2 of a record word, stores the record pointer), zero `0x4000` bytes at the record `[0x1000040 + 0x108]` (`0xffa16750`), then on the master a flush of `0x100` bytes at physical `0x1000000` (`fc`, `sync.i`, `mf`, PAL cache-info loop) and the barrier. `0xffa1f740`: `0xffae10f0` picks a table entry by slice and its method `+8` is called with 0 (not read: unknown). Grade: inferred for the SHub claim (no SHub access found in the parts read; the method behind `0xffa1f740` and `0xffa8f8a0`'s own writes are covered elsewhere or unread).

#### What a lone node's model must give back for this stretch

- `SH_EVENT_OCCURRED` (`0x1_1001_0000`) reading 0 (or any value; it only chooses lists to write); `cpu_bits` and `0x1_5003_1540` as plain storage, with bit 2 and bit `0x11` of the latter reading 0 and `0x1_101d_0188` reading 0; `SH_SCRATCH1` as plain storage with bit 56 clear on the first read (a set bit skips the node set-up); `0x1_2002_0080` bit 0 set for one CPU and bits 0 and 1 for two.
- The flash window at `nasid << 38 | 0xf_ff80_0000` must accept 16-bit writes and 8-byte reads; any read value other than `0x51` at +`0x20` keeps the PROM from reading flash (prints "(empty)").
- Waits: none on this path. The PROM prints nothing at normal level; the debug-level prints are `Checksumming EFI variable store ...`, ` = 0x956bac74 (empty)\tDONE` (or the real checksum) and `Late initialization of headless node`.
- Nothing here freezes.

### Unknown here

Whether a lone node's record carries the flag `0xffa1a9e0` tests (word `+0x68` bit 16), and so whether slot 5 and slot 6 run at progress 0x23 or the I/O discovery runs only at 0x24; whether the I/O discovery body is idempotent if it runs twice; `0xffb55b60`, which combines the stored checksums; the method behind `0xffa1f740` and the SHub accesses `0xffa8f8a0` makes when the nonzero-NASID path re-creates a record; whether the PROM's later code compares the chip's NASID with the record after the write on a node with a router; what the real chip does to a request in flight at the moment bits 42:32 change (no PROM code waits for it: after row 6 the next access is in the SHub's own register block); what the flash window does on a real node when the CFI query is not answered.

### Review (NASID change, commit 8745c9d)

Independent re-read of the section above in Ghidra and an ia64 listing of snprom 10.54; the steps are listed on the [boot sequence page](../../software/firmware/snprom/boot-sequence.md#review-nasid-change-and-start-of-main_three-commit-8745c9d). At stops in the sof=2 leaf helpers, r34 and above are out of frame. Confirmed: the access table rows 1 to 17 (addresses, windows, tests), the interrupt pair table (21 entries, listed from the image), the SHUB_ID read-modify-write through the old NASID, the `DIR_CONFIG` pair, the unflushed second jump, and the scrub's lone-node path. Corrected: the scrub's toggling of the `LOCAL_INT` enables is traffic (this page says so; the commit message said none); the barrier has a release bit and an exit phase. New registers in `registers.toml` match the 2.4 header names and offsets for `proc_adv_int_config`, `proc_err_int_*` and the profile pair; the other three offsets come from the PROM table, which agrees with the stride. Grades unchanged.

## `SH_SCRATCH1` (`0x1_101d_0080`) and its alias: what touches which bits

Read in the Ghidra decompiles of snprom 10.54 (`shub1snprom.bin`); no instruction listing. The 2.4 header gives `SH_SCRATCH1` as one 64-bit field, reset 0, and `SH_SCRATCH1_ALIAS` at `0x1_101d_0088` with an address only (established). Linux v5.3 has no name for either (a search of the Linux mainline tree found none; that root's v5.3 coverage was not confirmed).

| Order | Site | Access | Bits |
|---|---|---|---|
| 1 | `0xffc4e970` (first stage, every processor) | store slice + 1 to the alias `0x81_101d_0088`, read `0x81_101d_0080`, equal means winner | whole word; the winner then zeroes `0x1_5003_1550`, `1540`, `1560` and writes 1 to `0x81_1006_0480` |
| 2 | `0xffc4e730` | exact read and compare against slice + 1 | on a match sets bits 41:39 of `0x1_101d_0100` |
| 3 | `0xffa0b0f0` | local read-modify-write | sets bit 41 when no other processor position is flagged |
| 4 | `0xffa0aee0` (from `0xffa0af70`, `0xffad2cb0`) | global window `nasid << 38 \| 0x8000_0009_101d_0080`, read-modify-write | sets bit 39 |
| 5 | `0xffa4eb40` | same window, read-modify-write | sets bit 40 |
| 6 | `0xffa5d2a0` (from slot `0x1c0`, `0xffa5df20`) | vector read (`0xffa959d0`), vector write (`0xffa96920`), literal `0x1_101d_0080` | see below |
| 7 | `0xffa1a6d0` (slots 45 and 46) | read; if bit 56 set return 1; take lock 0x11; re-read; set bit 56 and write | bit 56 |
| 7a | `0xffacc6e0` (node-object method 5, through slots 45 and 46) | read, then write with bits 57 and 40 set | bits 57, 40 |
| 8 | `0xffaf5c80`, `0xffc4e030` (error and park paths) | read-modify-write then spin | OR `0x280_0000_0000` (bits 41, 39); also clear bits 29:26 of `0x1_5003_1550` |

Every write at sites 3 to 8 goes to `0x80`; only site 1 uses the alias. The twin routine `0xffa60a70` does the same job for the other chip type at `0x4_0901_d0080` and sets bit 58 and a byte in bits 30:23; it is not a SHub 1 path.

**The `0xffa5d2a0` poll.** Read the word. Bits 55:54 nonzero: return 0 (done). Word 0, or bit 39 or 41 set: go on. Any other nonzero word: poll again every 10000 microseconds (`0xffa0db90`, 10 ms), until `0xffa0da70` (the microsecond clock) passes its value at entry plus 300000000 (300 s) or the console interrupt check `0xffa1f340` fires, then force the word to `0x2_0000_0000_00` (bit 41) and go on. Going on: write 0 to `0x1_5003_1550` and `0x1_5003_1540`, clear bits 55:54, set bit 39, OR in bits 55:54 from the port probe `0xffa5d6a0`, store through slot 46, and set bit 1 of descriptor byte `+0x2b`. A model that returns a stale nonzero word with no bit 39, 41 or 55:54 makes this wait 300 s.

**The retry de-dup does not compare this register (inferred from the call chain).** `0xffa450e0` compares descriptor words `+8` and `+0x10` through `0xffa11ab0`. For a neighbour slot `0x1c0` (`0xffa5df20`) builds them after the claim: `0xffa8d120` reads `0x1_101d_0100` (`SH_SCRATCH2`, address from slot `0x278`, `0xffa94320`) and accepts it only when its low byte is `0x6c`. It takes the id from bits 34:26 and 25:20 and three small fields from bits 38:35, 18:16 and 15:8, and `0xffa11f10` packs them with a type of 2; a failed read gives type 0 and id `0xffffffff`. The compare tests the low 32 bits (bits 15:8 masked), bits 47:44, signed bits 43:40, then the type, then type-specific bytes. The `SH_SCRATCH1` word read at slot 45 is passed only to the insert-time method `0xffa5e0b0`, which decodes it: bit 39 sets record flag `0x10000`, bit 58 `0x2000000`, bits 16, 18 to 22 other flags, bit 41 (with `0xffa975e0(8)` clear) `0x1010000`, bit 40 stores the NASID from bits 42:32 of its other argument and sets byte `+0x2b` bit 0 (clear: NASID `0xffff`), bits 55:54 the port set.

**Who writes the `0x6c`-tagged word in `SH_SCRATCH2` (`0x1_101d_0100`).** The system controller (L1), not the PROM, for the local SHub.

- *Layout the PROM reads* (`0xffa8d120`, established): low byte `0x6c`; bits 34:26 rack, 25:20 bay (packed with type character `c` by `0xffa7d010`), 38:35 and 18:16 the two nibbles of the geoid's slot and slab byte, 15:8 the partition; bit 19 is a flag. Bits 63:39 are not part of it.
- *PROM writer* (`0xffa8cea0`, the function behind the string "sysctl_set_pushed_data"; established for the code, **inferred** that its single caller `0xffa60f3c`, in the `0xffa60a70` family, is the TIO path: the only message that names it is "cache_advert: sysctl_set_pushed_data failed for TIO"). It reads the register, rebuilds the word from rack, bay, slot, slab and partition with tag `0x6c`, keeps bits 63:39 and bit 19, and writes it back through `0xffa0c560`. Nothing in the PROM calls it for the local SHub. Other PROM writes of this register (established, rows above): SAL_A's election winner sets bits 41:39 to 7 by read-modify-write, and `0xffa8b5d0` later clears them, increments bits 49:42 and clears bit 63. All keep bits 38:0.
- *L1 writer* (established, Ghidra, ARM L1 1.62.1 `SHUB_ScanSetRackSlot` at `0x6cda4` and ColdFire `2MB image` (package 3) routine `0xffe5b3dc`, which logs the same name and source line): when the L1 releases an SHub from reset (`SHUB_Reset_PostRelease`, ARM `0x71d70`; ColdFire `0xffe5e04c`, log text "SHUB %d release done"), it writes register `0x101d0100` through the JTAG scan chain (`SHUB_MMR_Write` -> `JChip_MMR_Write`; ColdFire `0xffe5af98`). The 64-bit value is `datahi << 32 | data` with `datahi = (cfg[8] >> 6) & 0xf` and `data = cfg[8] << 26 | (cfg[0xc] & 0x3f) << 20 | (shub & 0xf) << 16 | (cfg[0x3c] & 0xff) << 8 | 0x6c`, where `cfg` is the L1's own brick configuration and `shub` the SHub index in the brick (the geoid slab, 0 for a lone node). The retry loop runs up to 50 times. That `cfg[8]`, `cfg[0xc]` and `cfg[0x3c]` are rack, bay and partition is **inferred** from the field widths and from the `0x0003` and `0x0009` replies (settings 1 and 2, sysco repository, `software/firmware/l1/brick-request-handlers.md`). That the L1's `0x101d0100` is the PROM's `0x1_101d_0100` (the same register without the local-block bit) is inferred from the shared `0x6c` tag and layout.
- *What a model must provide*: `SH_SCRATCH2` is not zero at reset. Before SAL_A runs, the L1 model writes `0x0410006c` for rack 1, bay 1, slab 0, partition 0 (rack 1 << 26 = `0x04000000`, bay 1 << 20 = `0x00100000`, tag `0x6c`), with the partition equal to its `0x0009` reply; SAL_A's later read-modify-writes keep it. The L1's word has bits 41:39 clear: the value 7 that selects the UART step is not part of the identity, it is set afterwards by SAL_A's election winner (a read-modify-write that keeps bits 38:0, [images.md](../../software/firmware/snprom/images.md)), so the two facts do not conflict. For a lone node nothing reads it back: the local geoid does not use it ([the geoid section](../../platforms/sn2/klconfig.md#does-the-local-geoid-pass-through-shub_discover-0xffa5df20)), so it matters for a loopback neighbour and for hardware fidelity, not for the type-0 symptom. Not seen on hardware; mechanism grade established from firmware, value for rack 1 bay 1 derived.

**Model rule for a lone node.** One 64-bit cell serves `0x80` and `0x88`; a store at either lands in it, with reset 0. The vector read and write engine must return and store that same cell for `0x1_101d_0080`, not response data from another register. No hardware-set bits exist. Keep the node count at 1 by leaving every port link flag clear; if a loopback neighbour must be modelled, its `SH_SCRATCH2` read has to carry the same `0x6c` low byte and id as the local entry. Not settled: how the local template at `[[0x1000038] + 0x38]` is filled, and whether the alias ORs or stores.

### Review (main_three on a lone node, commit b482440; `SH_SCRATCH1`, commit c976c1f)

Independent re-read in Ghidra (IA-64, `--sn2-prom --no-analysis`, named addresses) of snprom 10.54, with an `ia64-linux-gnu-objdump` listing for branch tests. Not run on a model.

Confirmed, `0xffa21350` section: the wrapper and the method table slot (`0xffa23a20`); the slice test (`0xffa0ecd0` on bit `26 + i`, loop i = 0 to 3); the `SH_INT_NODE_ID_CONFIG` write only when the two NASIDs differ; the enable value `0x7ef`; the `SH_EVENT_OCCURRED & 0x7ef` argument to `0xffa30b40`, which writes list `j` of the table at `0xffbdd010` for each set bit; the two destination and enable offset tables at `0xffbd9568` and `0xffbd9588` (read from the image); the five-entry lists at `0xffbd92d8` and `0xffbd9388`, their offsets and values, and the polarity of the `AttrCheck` test (bit 31 clear selects `0xffbd92d8`); the slice and present-bit tests in `0xffa4eb40` (`SH_SCRATCH1` bit 40, `0xffa11710` reading `0x1_2002_0080` bit k / 2 for k = 0 and 2, and returning 0 for k = 1 and 3 unless `cpuid[2]` is the simulator value); `0xffafbca0` and `0xffaf6d10` (64 KiB buffer, flash offsets `0x10_0000` to `0x1f_0000` in 64 KiB blocks, the constant on a failed probe, a read error or the simulator value, the store of the low 32 bits to the RAM record; `zlib.crc32` of 1 MiB of `0xff` is `0x956bac74`); `0xffa1a9e0` walks the records, runs the bit 56 claim `0xffa1a6d0` and then slot 5. Method slots: slot 5 is `0xffacc6e0`, slot 6 `0xffaccae0`, slot 32 (`+0x100`) `0xffa0ebc0`, slots 45 and 46 `0xffa959d0` and `0xffa96920`, each at the literal `0x1_101d_0080`.

Confirmed, `SH_SCRATCH1`: the first-stage election (store of slice + 1 to the alias, exact compare on the register, then three zero stores); the exact re-compare at `0xffc4e730`, which sets bits 41:39 of `0x1_101d_0100`; the writes of bit 41 (`0xffa0b0f0`, only when no other position is flagged), bit 39 (`0xffa0aee0`) and bit 40 (`0xffa4eb40`); the `0xffa5d2a0` poll's exits (bits 55:54, zero, bit 39 or 41), its forced bit 41 and the zeroing, bit 39 and port-mask stores after it; the bit 56 test-and-set in `0xffa1a6d0` under lock 0x11. The alias argument holds: a write-one-to-clear alias on a zero word could never read back slice + 1, so it is not clear-only (established from the code and the header's reset 0). The de-dup key: `0xffa8d120` accepts the `0x1_101d_0100`-class word (address from slot `0x278`) only when its low byte is `0x6c`, takes bits 34:26 and 25:20 (the id), 38:35, 18:16 and 15:8; `0xffa11f10` packs the id, bits 38:35 (to 47:44), bits 18:16 (to 43:40) and the type 2 into the word at descriptor `+8`, and bits 15:8 go to descriptor byte `+5` instead; the compare `0xffa11ab0` tests the low 32 bits with bits 15:8 masked, bits 47:44, signed bits 43:40 and the type, and ends equal for type 2.

Changed:

- The poll units in the `0xffa5d2a0` paragraph and the register's doc were ticks. The delay `0xffa0db90` takes microseconds and the deadline comes from the microsecond clock `0xffa0da70`, so the poll is every 10 ms for 300 s, and the console interrupt check `0xffa1f340` is a third exit. The boot sequence page already said so; this page and `registers.toml` now agree.
- The writers table omitted two writes: the election winner also stores 1 to `0x81_1006_0480`, and the node set-up method (slot 5, `0xffacc6e0`) read-modify-writes the register through slots 45 and 46, setting bits 57 and 40. Bit 57 is added to the register's fields (inferred; no reader found).
- The `id` of `SH_LOCAL_INT0_CONFIG` masks `nasid >> 7` to five bits.
- The word the `0x6c` test reads is named `SH_SCRATCH2` here by address; `registers.toml` still labels `0x1_101d_0100` `lb_l1_state`. Left as is.

Not checked: the 2.4 header names, valid bits and INIT values quoted for the five PI error registers and `SH_SCRATCH1` (the header is not in this clone; no Linux v5.3 hit for `SH_SCRATCH1` in the Linux mainline tree); the other nine lists of `0xffa30b40` beyond their counts; `0xffa24810`; the `0xffa20e30` table; the four nonzero-NASID calls. The five PI first-error and mask registers have reset `unknown` in `registers.toml` while the quoted header INIT is 0 (first-error) or all valid bits (masks); that is under-claimed, not wrong. Grades unchanged otherwise.

### Review (`SH_FSB_VGA_REMAP`, commit 4055b2f)

Independent re-read in Ghidra and an objdump listing of snprom 10.54 (`shub1snprom.bin`), and the SGI Linux 2.4 headers (`shub_mmr.h`, `shub_mmr_t.h`, Linux/MIPS tree commit `8ef7d46c94d5`, read through our holdings). Nothing was run.

**Confirmed.**
- Header: offset `0x120010180`, mask `0x4001fffffffe0000`, INIT 0, fields offset 35:17, asid 37:36, nid 48:38, enable 62; bits 61:49 reserved.
- `0xffaeb1f0` (argument: the masked word): `0xffaeb22c` reads `0x8000008120010180` through the leaf `0xffa0e5a0` (`ld8 r8=[r32]`); `0xffaeb26c` writes `(old & 0xe001ffffffffffff) | ((arg >> 24 & 0xfff) << 49)` through `0xffa0e640`; `0xffaeb28c` and `0xffaeb2bc` read and write `0x8000008120010100` with bit 17 (`0x20000`) ORed in. The caller is `0xfface6fc`, passing the masked word, which is 0 on the stock path.
- `0xffaeb2e0(nasid)` reads `0x8000000920010100 | nasid << 38` (global window of `pi_reg_2001_0100`) and returns `!(value >> 17 & 1)`; callers `0xffac63cc` and `0xffac690c` exist.
- `r33 = 7` is stale: `0xffa0e5a0` is a leaf that reads only r32, and r37 (its r33) is not set before the first call in `0xffaeb1f0`.
- The SHub 2 overlay removal agrees with the SHub 2 PROM of the same release: `shub2snprom.bin` has no `movl` of `0x8000008120010180` or `0x8000008120010100` in a linear listing.

**Changed.**
- The `bit17` source text in `registers.toml` names `0xffaeb276` as the set; that address is a `movl` of the register address. The write is `0xffaeb2bc` (the read is `0xffaeb28c`). Corrected in the toml; the generated tree does not carry field source text, so `defs-gen` writes nothing new.

**Not checked.** What PROM or kernel code does with the value bits 60:49 written on a non-zero path (the field lies in the header's reserved bits); the rest of the generated headers beyond `defs-check`.

## After the block-transfer self-test: the XN accesses in `main_two` up to the NASID change

What SAL 5.04 (`shub1snprom.bin`, snprom 10.54, flat at `0xffa00000`) does to SHub 1 between the two-engine copy self-test (`0xffa96980`, called from `main_two` at `0xffa1b04c`, traced in [the SHub 2 page](../shub_ii/README.md)) and the call to the NASID change (`0xffacd2b0`, [below](#the-nasid-change-and-the-node-id-install-0xffacd2b0-to-main_three)), for a lone node. Read in Ghidra (IA-64, `--sn2-prom --no-analysis`, every function named decompiled), with a listing cross-check of the stop routine `0xffa5c900`, the accessor leaves and the thunks. Call sites are the address of the `br.call` slot. Names are the 2.4 SN2 header (`shub_mmr.h`, Linux/MIPS tree, commit 8ef7d46c). Not independently reviewed. The accessors are `0xffa0e5a0` (8-byte read), `0xffa0e640` (8-byte write) and the 1- and 2-byte variants; each runs with interrupts masked and ends in `mf.a`, so a model sees one access per call.

### The stop: `0xffa5caf0` is inside `0xffa5c900`

`0xffa5caf0` is the return address of the first read in `0xffa5c900`: the first pass of the first loop, port 0, address `0x8000_0081_5003_03a0` (call at `0xffa5caec`, the `ld8` of `0xffa0e5a0`). The routine toggles `IILB_VCFIFO_SWITCH` (bit 24) in `SH_XNNI0_VCSWITCH_FLOW` and `SH_XNNI1_VCSWITCH_FLOW` (header mask `0x701010101`, INIT 0), sends a vector write to each linked neighbour, then toggles the bit back. Call chain: `main_two` (`0xffa1ade0`) calls `0xffa44ba0` at `0xffa1b13c`, which calls `0xffa5c900` at `0xffa44d8c` after assigning `cpu_bits` bits 13, 14 and 15; the call follows `0xffa445b0` (bit 0) and `0xffa44660` (bit 1) and precedes the first `0xffa44710`. Both thunks tail-branch to the one routine at `0xffa42640` with argument 0 or 1 (established).

**Lone-node gating (established as code).** `0xffa5c900` returns 0 at once, touching no XN register, unless the master-slice test `0xffa0ff30` is non-zero (it reads `cpu_bits` bit 26 + i for each slice i below the running one, and returns 0 if any is set, so slice 0 always passes) and `cpu_bits` bit 0 is set (`0xffa0ecd0(0)`, the read at `0xffa5ca2c`). `0xffa445b0` sets bit 0 when the best record index is 0, which a lone node's one record is.

**`r33 = 0x813` at the stop is stale, not an argument.** The read leaf has a two-register frame: `r32` is the address (the caller's `r48`) and `r33` is the caller's `r49`. `0xffa5c900` first writes `r49` at `0xffa5caf0`, after the first read returns (the XOR value for the write), so on the first pass `r49` is whatever an earlier call left. The leaf never uses it. `r34` and above are out of frame.

| # | Site | Access | Offset (window) | Name | Value, test and lone-node value |
|---|---|---|---|---|---|
| 1 | `0xffa5c950` area | R, RAM | `0x0_0100_0038`, then `+0x30` | not a register | the pointer to the node table; two RAM reads, no SHub access |
| 2 | `0xffa5ca2c` | R | `0x1_5003_1550` (local) | `cpu_bits` | bit 0 must read 1 |
| 3 | `0xffa5ca5c` | R | `0x1_1006_0580` (local, `0xffa0dcf0`) | `SH_SHUB_ID` | bits 42:32 kept as the NASID of the vector route; used only for a send |
| 4 | `0xffa5caec`, `0xffa5cb2c` | R then W, p = 0 then 1 | `0x1_5003_03a0 + 0x200 p` (local; the `0x1_5003_03a0` and `0x1_5003_05a0` words) | `SH_XNNI0_VCSWITCH_FLOW`, `SH_XNNI1_VCSWITCH_FLOW` | write the read value XOR `0x1000000`; the read is not tested |
| 5 | none | | | | per node record: slot 49 (`0xffa5d5b0`, returns 2); a port whose neighbour index is -1 sends nothing, and both are -1 on a lone node, so `0xffa46a50` is never called |
| 6 | `0xffa5cc0c`, `0xffa5cc4c` | R then W, p = 0 then 1 | same two words | same | the same XOR again: the pair of toggles restores the value |

The return value is 0 on a lone node; a negative return only makes `0xffa44ba0` print a line (`0xffbb0ae0`) and go on. There is no poll and no deadline in the routine.

### The accesses between the self-test and the NASID change, in order

Order is the execution order of `main_two` for the master slice of a lone node. Stubs: `0xffb91770`, `0xffb911b0`, `0xffb946d0`, `0xffb91b60`, `0xffb90720`, `0xffb91b70` and `0xffb91b80` are one-bundle returns (established), with no access.

| Step | Site (call) | Routine | SHub accesses |
|---|---|---|---|
| 1 | `0xffa1b08c`, `0xffa1b0ac` | master-slice test `0xffa0ff30` | R `0x1_5003_1550` bit 26 + i per lower slice i; none for slice 0 |
| 2 | `0xffa1b3fc`, `0xffa1b41c` | `0xffa805e0`, `0xffa7df40` (`sysctl_display_text`, L1 request `0x1005`) | `0xffa805e0` is RAM only. `0xffa7df40` goes through the L1 UART, not an XN register ([the L1 requests page](../../software/firmware/snprom/l1-requests.md)) |
| 3 | `0xffa1b32c` | `0xffa1a980` (then `0xffaa0100` and the klconfig builders `0xffaa3cf0`, `0xffaa2760`, `0xffaa33a0`, `0xffaa4560`, `0xffaa4f50`, `0xffaa3060`, `0xffaa5450`, `0xffaa8a40`) | R `0x1_1006_0580` (`SH_SHUB_ID`, bits 42:32) three times; everything else is RAM (0xb0000 bytes allocated, node cells at `0x8000_0030_0100_0038` form). If the allocation fails the PROM prints and calls `0xffa1b940(0x84, 2)`, which blinks progress code `0x84` forever (fatal) |
| 4 | `0xffa1b3dc` | `0xffa9fe80(nasid, 0x11, 0)` to `init_klcfg_hub` `0xffaa1ea0` | the board-area and `0x0010` L1 requests (see the L1 page). Through `0xffaa1da0` and `0xffa11710`: R `0x9_2002_0080 | nasid << 38` (global window, `SH_FSB_SYMMETRIC_AGENT_STATUS`), bit 0 or 1 for slice 0 or 2, only for slice bits set in the mask passed in (slices 1 and 3 read nothing unless `cpuid[2]` is the simulator value). The mask is the return of `0xffae8660` (one word from each of two 16-byte arrays filled by `0xffae8250`, ANDed; a negative return becomes `0xf`), not the constant `0x11`, which is `0xffaa1ea0`'s second argument, stored in byte 5 of the new record; a set bit makes `0xffaacbd0` add a per-slice record (role inferred). The call is inside `main_two`'s master-slice test, so it runs on a lone node (established as code); the mask value and what a clear bit does later were not followed |
| 5 | `0xffa1b0cc` | progress write 0x1c, `0xffa0ddb0` | R and W `0x1_5003_1500 + 0x10 n`, two 16-bit LED stores ([the progress write](#the-progress-write-pc)) |
| 6 | `0xffa1b0dc` | `0xffa47870` (the discovery crawl, [boot sequence](../../software/firmware/snprom/boot-sequence.md)) | on a lone node only the local descriptor build `0xffa47290`: R `0x1_5003_1560` (debug word, `0xffa975e0` and `0xffa97660`), R `0x1_1006_0580`, and the RAM descriptor writes. The loop over records 1 and up, with the `0x1_5003_1580` counter and vector sends, does not run. A negative return takes the failure halt `0xffad2c50(0x8f)` |
| 7 | `0xffa1b0fc` | `0xffa48560` to `0xffa53070` | none found |
| 8 | `0xffa1b11c`, `0xffa1b12c` | `0xffa445b0`, `0xffa44660` (thunks to `0xffa42640`) | per call: test, RAM scan of the node table, then `0xffa0eae0(0 or 1, record index is 0)`: the lock cycle (below), R and W `0x1_5003_1550` bit 0 (first) or bit 1 (second). Prints `Global master is %I` at debug level |
| 9 | `0xffa1b13c` | `0xffa44ba0` | three `0xffa0eae0` cycles for bits 13, 14, 15 of `cpu_bits` (value 1 when a record of byte `+0x5a` = 1 without flag `0x10000` has flag `0x100000`, `0x200000`, `0x400000`; otherwise 0), then `0xffa5c900` (above) |
| 10 | `0xffa1b14c` | `0xffa44710` | R `cpu_bits` bit 4 (0 on a lone node), `0xffa42a30` (tree barrier: R `0x1_5003_1550` bit 12, R and W `0x1_5003_1570`, W `0x1_5003_13f0`, `0x1_5003_13d0`, progress read and write; [above](#the-route-calculation-for-a-lone-node-0xffa4d390-and-0xffa5a670)), returns 0, then `0xffa9a130(4, 1)`, the slice barrier (below) |
| 11 | `0xffa1b18c`, `0xffa1b24c` | test again, progress write 0x1d | as steps 1 and 5 |
| 12 | `0xffa1b26c`, `0xffa1b2ac` | `0xffa4d390` (route calculation) then `0xffa5b5d0` (the walk, slot 59) | local reads only for the route calculation; the walk writes the router tables and ORs and updates the `VCSWITCH_FLOW` and `INJECT_AGE` words; all in [the topology walk](#the-numalink-topology-walk-0xffa5b5d0-and-slot-59). Negative returns take `0xffad2c50(0x8b)` or `0xffad2c50(0x8c)` |
| 13 | `0xffa1b1ac` | `0xffa44710` again | as step 10 |
| 14 | `0xffa1b1bc`, `0xffa1b1dc`, `0xffa1b21c` | `0xffa0aab0` (RAM), progress write 0x1e, `0xffacd2b0` | the NASID change, next section; this table stops here |

**The `cpu_bits` cycle `0xffa0eae0(bit, value)`.** One call makes, in order: R `0x1_1003_0000 + 0x80 * slice` (progress word, `0xffa0e020`); R `0x1_101c_0000` and `0x1_1006_0280` (clock in microseconds, `0xffa0da70`); R `0x1_101d_0208` until it reads 0, once on a lone node; the progress write P(low byte of the progress word) (`0xffa0ddb0`, inside the lock routine `0xffa0ed30`); R `0x1_5003_1550`; W the same address with the bit set or cleared; W `0x1_101d_0200` = 0. [The node lock](#the-node-lock-used-by-a28-a29-a34-and-a37) lists the protocol. The header names the two registers `SH_SCRATCH4` (`0x1_101d_0200`) and `SH_SCRATCH4_ALIAS` (`0x1_101d_0208`), one bit wide (mask 1, INIT 0); the second lock pair is `SH_SCRATCH3` (`0x1_101d_0180`) and `SH_SCRATCH3_ALIAS` (`0x1_101d_0188`), also one bit. The header gives no description of an alias read.

**The slice barrier `0xffa9a130` for a lone node.** Read the progress word; wait while `cpu_bits` bit 34 is set; `0xffa0f780(0)` claims bit 0 of `0x1_5003_1540` under the second lock pair (R `0x1_5003_1540` until the bit reads 0, no deadline; lock via `0xffa0ed30` on `0x188` and `0x180`; R, W `0x1_5003_1540` with bit 0 set; W `0x1_101d_0180` = 0); set `cpu_bits` bit 30 + slice; compare bit 30 + i with bit 26 + i for i = 0 to 3. With bit 26 set for slice 0 and nothing else (the PROM sets it itself: `0xffa99cf0`, called at `0xffa1aebc` at the top of `main_two`, calls `0xffa0eae0(26 + cr.lid bits 26:23, 1)` at `0xffa99dfc`), all four pairs match, so it sets bit 34, clears bit 30 + slice, clears bit 34 once the four bits 30 + i read 0, clears bit 0 of `0x1_5003_1540` (`0xffa0f7b0`) and writes the progress code. A model that keeps `cpu_bits` plain does not wait.

### Polls with no deadline, and what ends the PROM

| Where | What it waits on | Deadline | A plain model |
|---|---|---|---|
| `0xffa0ed30` (every `cpu_bits` cycle; also the `0x188` pair) | `0x1_101d_0208` (`0x1_101d_0188`) reads 0 | none to give up: after 1,000,000 microseconds each pass writes 0 to `0x200` (`0x180`) and keeps polling | status reads 0 at once; no wait |
| `0xffa9a130` | `cpu_bits` bit 34 clear; then, for i = 0 to 3, bit 30 + i equal to bit 26 + i, or bit 34 set | none | passes without waiting if bit 26 of the running slice is set and no other slice bit is |
| `0xffa0f780(0)` (from `0xffa9a130`) | bit 0 of `0x1_5003_1540` clear | none (the deadline argument is 0) | bit 0 reads 0 |

Bounded: the vector operations (1024 passes of 100 microseconds, none on a lone node), the tree barrier `0xffa42a30` (timeout message `tree barrier at %I timed out`), the link probe (128 reads per flow word, [above](#the-ni-port-set-up-before-memory-discovery-0xffa483d0-and-slot-55-0xffa5d850)). Fatal paths: the klconfig allocation failure (step 3), and `0xffad2c50` with progress code `0x8b` (route calculation), `0x8c` (walk) or `0x8f` (discovery), each on a negative return (the routine reports and parks the boot processor: it clears `cpu_bits` bits 26 to 29 and 21 + slice, then loops in PAL, see [the L1 requests page](../../software/firmware/snprom/l1-requests.md)); none runs on a lone node whose RAM and registers behave as below. Prints on the path: the spinner character from `0xffa0ab80` (once), `Global master is %I`, and, with `cpu_bits` bit 10 set, `Distributing routing tables` and `Set up %s`. The remaining prints are debug-level.

### What the model needs for this stretch

- `0x1_5003_1550` (`cpu_bits`): 64-bit storage, reads back what was written. The PROM sets bit 0 and bit 1, assigns bits 13 to 15 and 30 + slice, and clears 30 + slice and 34, with bits 26 + slice already set. Bit 4 reads 0 and nothing in this stretch sets it: only a non-zero return of the tree barrier `0xffa42a30` does (`0xffa44710` then calls `0xffa0eae0(4, 1)`); a preset bit 4 skips the tree barrier and runs `0xffa43d20`, which was not traced.
- `0x1_5003_03a0` and `0x1_5003_05a0` (`SH_XNNI0_VCSWITCH_FLOW`, `SH_XNNI1_VCSWITCH_FLOW`): storage, reset 0 (header INIT, inferred), read-modify-write, no side effect. The toggling pair restores the value; slot 59 then ORs `0x100` (or `0x101`). `0x1_5003_0400` and `0x1_5003_0600` (`SH_XNNI0_INJECT_AGE` and port 1, mask `0xffff`): storage; the PROM stores `(v & ~0xff00) | 0xc000`.
- `0x1_101d_0208` and `0x1_101d_0188` read 0 when the lock is free (a plain storage pair, or a read that returns the bit and sets it, cleared by a write of 0 to `0x200` or `0x180`); `0x1_101d_0200` and `0x1_101d_0180` accept writes.
- `0x1_5003_1540`: storage; bit 0 reads 0. `0x1_5003_1570`, `0x1_5003_13f0`, `0x1_5003_13d0`, `0x1_5003_1580`, `0x1_5003_1560` and the history words `0x1_5003_1500 + 0x10 n`: storage.
- `0x1_1003_0000 + 0x80 n` read (any value), `0x1_101c_0000` running clock and `0x1_1006_0280` period, `0x1_1006_0580` returning the NASID in bits 42:32, `0x9_2002_0080 | nasid << 38` bit 0 set (inferred: it makes slice 0 count as present, if the mask from `0xffae8660` includes slice 0); the LED stores accepted.

### Review (XN accesses after the BTE self-test, commit 7e3f144)

Independent re-read, 2026-11-16, by a reviewer who wrote none of it. Ghidra (IA-64 module, `--sn2-prom --no-analysis`) decompiles of `main_two`, `0xffa5c900`, `0xffa44ba0`, `0xffa445b0`, `0xffa44710`, `0xffa42a30`, `0xffa0ed30`, `0xffa0eae0`, `0xffa0ecd0`, `0xffa0f780` (its tail target `0xffa0efd0` by listing), `0xffa0f7b0`, `0xffa9a130`, `0xffa99cf0`, `0xffa0ff30`, `0xffa0e020`, `0xffa0ddb0`, `0xffa0da70`, `0xffad2c50`, `0xffad2cb0`, `0xffa9fc70`, `0xffa9fba0`, `0xffaeb7c0`, `0xffa1b940`, `0xffa9fe80`, `0xffaa1ea0`, `0xffaa1da0` and `0xffa11710`; the `ia64-linux-gnu-objdump` listing for call slots, immediates and predicates. Register names, masks and INIT values against the 2.4 header (`shub_mmr.h` at 8ef7d46c94d5).

**Confirmed.** The stop `0xffa5caf0` is the return ip of the first `0xffa0e5a0` call (slot `0xffa5caec`) in `0xffa5c900`, which is called at `0xffa44d8c` from `0xffa44ba0` (call `0xffa1b13c`), after the bit 13 to 15 assignments; the order `0xffa445b0`, `0xffa44660`, `0xffa44ba0`, `0xffa44710` in `main_two`; both thunks branch to `0xffa42640` with 0 or 1. Gate: `0xffa0ff30` non-zero and `cpu_bits` bit 0 (`0xffa0ecd0(0)`, call `0xffa5ca2c`), bit 0 assigned `index == 0` by `0xffa445b0` (and it is also 1 when no better record is found, since the index starts at 0). VCSWITCH_FLOW: two passes, `0x1_5003_03a0` then `+0x200`, read, XOR `0x1000000` (bit 24, `IILB_VCFIFO_SWITCH`), write, a second identical pair at the end; header offsets `0x1_5003_03a0` and `0x1_5003_05a0`, mask `0x701010101`, INIT 0. `r33 = 0x813` is stale: `xor r49` is the first write of `r49` and follows the first read. Lock cycle: progress word `0x1_1003_0000 + 0x80 * (lid bits 24:23)`, clock, poll of `0x208` to 0 with a 1,000,000-tick re-release of `0x200`, progress write, `cpu_bits` read-modify-write, write 0 to `0x200`; the second pair on `0x188` and `0x180` (`0xffa0f780(0)`: `0xffa0efd0` skips the timer when its deadline argument is 0; `0xffa0f7b0` clears the claim). Header: `SH_SCRATCH3` `0x1_101d_0180` and `SH_SCRATCH4` `0x1_101d_0200`, mask `0x1`, INIT 0; aliases `0x188` and `0x208` have an address only. Barrier `0xffa9a130`: bit 34 wait, claim, set 30 + slice, four-pair compare, set bit 34, clear 30 + slice, clear bit 34 once all four read 0, release, progress write; the path is as described. Tree barrier on a lone node returns 0 (two port iterations, `0x1_5003_13f0` and `0x1_5003_13d0` from the table at `0xffbdfbb0`). Fatal paths: `0xffa1b940(0x84, 2)` after the klconfig allocation failure (call slot `0xffaa03dc`) blinks the code and ends in a `break` loop; `0xffad2c50` with `0x8b`, `0x8c` and `0x8f` on the negative returns in `main_two`.

**Changed.** (1) "Set earlier by the processor on its way in" for `cpu_bits` bit 26 + slice: the PROM sets it, in `0xffa99cf0` at `0xffa99dfc`, called at `0xffa1aebc` with argument 1. A model that clears or ignores that store would hang the first barrier. (2) "`cpu_bits` bit 4 stays 0" was a requirement; it is only what happens on this path. Bit 4 is set only by a non-zero tree-barrier return in `0xffa44710`, and a preset bit skips the barrier for a branch that was not traced. (3) `0x9_2002_0080 | nasid << 38` bit 0: the read depends on the mask returned by `0xffae8660`, not on the constant `0x11`, and the "caller not followed" caveat is now closed for the call site (it is in `main_two`'s master-slice test); the mask value, and the effect of a clear bit, are still unknown, so the requirement is **inferred**, not established. (4) The fatal-path sentence now says what the routine does: `0xffad2c50` calls `0xffad2cb0`, which shows the code, writes the progress code to every slice, calls `0xffa9fc70`, which clears `cpu_bits` bits 26 to 29 and, for the boot processor, `0xffa9fba0` to `0xffaeb7c0`, which clears bit 21 + slice and loops in PAL. This agrees with the L1 requests page; item 5 of the review list in [node-bringup](../../software/firmware/snprom/node-bringup.md) ("not a halt") is true of `0xffad2c50` alone and was left as it is.

**Not checked.** The `0xffa0dcf0` read of `SH_SHUB_ID` and its bits (taken from the existing pages); the `0xffa47870` discovery crawl and its negative-return conditions; `0xffa4d390` and `0xffa5b5d0`; the klconfig builders in step 3; the `0xffa5c900` send loop over neighbour records (row 5), which was read in the decompile but not traced through `0xffa46a50`; the unit of the 1,000,000 and 240,000,000 tick bounds (inferred as microseconds, unchanged); the `0xffa43d20` branch.

**Model requirements.** One tightening and one regrade, no new register: keep the `cpu_bits` store from `0xffa99cf0` (bit 26 + slice) readable by the first barrier; bit 4 reads 0 on this path; the `0x9_2002_0080` bit 0 requirement is inferred.

## Partition fences: `0xffa51200` (`intcon_pttn_erect_reset_fences`)

SAL 5.04 (`shub1snprom.bin`, snprom 10.54, flat at `0xffa00000`), lone node, NASID 0. Read in Ghidra (IA-64, `--sn2-prom --no-analysis`, every function named decompiled) with an `ia64-linux-gnu-objdump` listing for call slots, immediates and predicates. Names and fields are the 2.4 SN2 header (`shub_mmr.h` at 8ef7d46c); the Linux v5.3 headers carry no NI names (a search of the Linux mainline tree found none; its v5.3 coverage was not confirmed). Independently reviewed, see Review below. No external URL was read.

**Where it is (established).** The routine name is the PROM's own: its two error strings begin `intcon_pttn_erect_reset_fences:`. The print "Erecting partition fences .................", two tabs, is the string at `0xffbb1700` (address built at `0xffa51336`, print call `0xffa5135c`, then a console call `0xffa1f170` at `0xffa5136c`, not traced); the end prints "DONE\n" (`0xffbb16c8`, call `0xffa5152c`). Chain: `main` `0xffa19a20` to `main_two` `0xffa1ade0` to the NASID change `0xffacd2b0` to `main_three` `0xffad7280`, which calls `0xffa485a0` at `0xffad761c`; that routine calls `0xffa51200` at `0xffa4873c`. `0xffa485a0` is the partition set-up: it reads `SH_SHUB_ID`, writes progress code `0x25`, runs `0xffa50880` (prints "Checking partitioning information ....", returns 2 on a lone node), then `0xffa50bd0` (flags each port, below), then `0xffa53180`, `0xffa51200` and `0xffa517b0`. `0xffa48560`, which `main_two` calls at `0xffa1b0fc`, is a different routine that only fills a RAM page.

**Gate (established as code, inferred for the values).** `0xffa485a0` runs `0xffa53180`, `0xffa51200` and `0xffa517b0` only if the master-slice test `0xffa0ff30` is non-zero and `cpu_bits` (`0x1_5003_1550`) bit 1 is set (`0xffa0ecd0(1)`). `0xffa50880` reads the same bit too, but only to decide whether to print. `0xffa44660` (called at `0xffa1b12c` in `main_two`) stores bit 1 = (the chosen record index is 0) through the `0xffa0eae0` cycle at `0xffa448ec`, so a lone node has it set. Otherwise the three routines are skipped, and so are their prints.

**What `0xffa0c660` is.** The return address of the store call inside `0xffa0c560`, the node-object write. With a zero route word (the local record) it does one `st8` through `0xffa0e640` to `0x8000_0008_0000_0000 | offset | nasid << 38`; for offset `0x1_5000_0010` and NASID 0 that is `0x8000_0009_5000_0010`. The stop at `0xffa0e650` is that store, so at that stop `r32` is the address and `r33` the value. `r34` is not an argument of the store routine (a leftover out register of the caller). The stop address is the bundle that holds `srlz.d`; the `st8` is its second slot, `0xffa0e656`. The caller of `0xffa0c560` is the fence method, slot 62 of the SHub 1 chip operation table (`0xffbd7c18 + 8 * 62` to descriptor `0xffc4bb30`, function `0xffa60410`), reached from `0xffa51200` through `[ops + 0x1f0]` at `0xffa5167c`.

**How it decides (established).** `0xffa50bd0` sets bit 1 of byte `+3` of port entry p (port array at record `+0x60`, stride `0x28`, entries 1 and 2) when the entry's neighbour index (short at the entry start) is -1, and clears it when the neighbour is a record in the same partition (byte `+0x35` equal, or for a router neighbour `0xffa4f9b0` non-zero; a router record itself goes to `0xffa4fb40`, not read). `0xffa450e0` initialises every neighbour index to -1 when it inserts a record, and a lone node has no neighbour, so both ports end with the bit set. `0xffa51200` then walks the records. For a record of type 2 (router) it takes the NASID from `SH_SHUB_ID`; for any other type it skips a record whose `+0x5b` bit 0 is set (the reason is inferred: not re-derived) and takes the rest. A router record is also skipped when bit 2 of the short at `+0x68` is set. It keeps only a record whose partition byte (descriptor byte 5) equals the local one. It asks the chip for its port count (slot 49, `0xffa5d5b0`, returns 2, no access) and builds the mask M, bit p-1 for each entry whose byte `+3` bit 1 is set. It then calls the fence method twice:

1. `(descriptor, M, 1, 3, 0xff)` at `0xffa5167c`: operation 1 writes 0.
2. `(descriptor, ~M, 2, 3, 0xff)` at `0xffa516dc`: any other operation writes 1.

The method (`0xffa60410`, read in full) tests bit 0 of its fourth argument (3 here; bit 1 is not used), then for p = 0, 1 writes the value to `0x1_5000_0010 + 0x2000 * p` for each bit p set in mask AND `0xff`, through `0xffa0c560`, stopping at the first negative result. A negative result prints `intcon_pttn_erect_reset_fences: Can't fence ports mask 0x%lx on router vec 0x%lx` (call 1, `0xffbb1730`) or `... Can't clear ports mask ...` (call 2, `0xffbb1788`) and the routine goes on to the next record. The failure needs a route word, so it cannot happen for the local record.

### Accesses, in order, on a lone node

All 8-byte. "Own" is the global MMR window of NASID 0, `0x8000_0009_0000_0000 | offset`; "local" is `0x8000_0081_xxxx_xxxx`.

| # | Site | Access | Offset (window) | Header name | Value, test, and what the PROM does with it |
|---|---|---|---|---|---|
| 1 | `0xffa485cc` (`0xffa0dcf0`) | R | `0x1_1006_0580` (local) | `SH_SHUB_ID` | bits 42:32 kept; used only in the fatal-path loop of row 12. Not tested |
| 2 | `0xffa485fc` (`0xffa0ddb0`) | R, W, 2 x W16 | `0x1_5003_1500 + 0x10n`, LED A and B | | the progress write [P(0x25)](#the-progress-write-pc) |
| 3 | `0xffa4860c`, `0xffa4862c` | none for slice 0 | | | master-slice test `0xffa0ff30` (reads `cpu_bits` bit 26 + i for lower slices only) |
| 4 | `0xffa50880` | R | `0x1_5003_1550` bit 1 (local) | `cpu_bits` | only gates the prints "Checking partitioning information ...." and "DONE\n"; the routine runs and returns either way. It returns 2 only if no non-router record has a non-zero partition byte (`+0x35`) or `+0x5b` bit 0; a non-zero partition byte gives 0, and 1 (message "Invalid partition ...") sends `0xffa485a0` to `0xffa50f00` instead of `0xffa50bd0` |
| 5 | `0xffa485a0` after `0xffa50bd0` | R | `0x1_5003_1550` bit 1 | `cpu_bits` | must be 1, with the master-slice test, or `0xffa53180`, `0xffa51200`, `0xffa517b0` and the node-count check are skipped |
| 6 | `0xffa53180` | R (debug word) | `0x1_5003_1560` bit 2 (`0xffa975e0(2)`, local) | | RAM otherwise: sets partition bits in the page at `[0x1000040] + 0x20`. Bit 2 set (with the master and bit 1 tests) prints a page dump (no hardware access) |
| 7 | `0xffa51200` | none | | | prints "Erecting ...", walks the record (RAM), slot 49 returns 2 |
| 8 | `0xffa5167c` to `0xffa0c560` | W | `0x1_5000_0010` (own) | `SH_NI0_LLP_RESET_EN` | value 0 (operation 1, port 0 in M). Mask 1, INIT 1. Not read back. Stop `0xffa0e650` |
| 9 | same call, second pass of the method's loop | W | `0x1_5000_2010` (own) | `SH_NI1_LLP_RESET_EN` | value 0 (port 1 in M) |
| 10 | `0xffa516dc` | none | | | operation 2, mask `~M & 0xff` = `0xfc`: no port 0 or 1 selected, so no write |
| 11 | `0xffa517b0` | none | | | meta-router set-up: two heap allocations (`0xb00` and `0x4200` bytes, RAM); only type 2 records do anything (for those it calls the same chip slot 62 with argument 4 of 1, 2 or 3 and `SH_SHUB_ID`), so on a lone node it only runs the klconfig walk `0xffaa20f0`. The walk's own code reads `SH_SHUB_ID` and klconfig records in RAM; its callees (`0xffaa0fc0`, `0xffaa0b90`, `0xffaa1270`) were not traced to the end, so "RAM only" is inferred. The allocation-failure path prints `intcon_pttn_meta_routers: not enough malloc space` and returns -1, which the caller ignores |
| 12 | back in `0xffa485a0` | none | | | counts the used slots of `[0x1000038 + 0x10]` and asks L1 request `0x0012` (`0xffa7ea90`; [L1 requests](../../software/firmware/snprom/l1-requests.md)); a count above the reply (never below `0x800`) prints "Too many nodes in this partition!" and calls the die routine `0xffad2cb0` with code `0x8a` for every other node and then, through `0xffad2c50`, for itself. That routine sets `SH_SCRATCH1` bit 39, clears `cpu_bits` bits 26 to 29, writes `0x1_2000_0000` and (own slice) clears `cpu_bits` bit 21 + slice, then returns after a delay; it has no halt loop, so "fatal" is not established. One node never reaches it |

There is no permission, protection, route-table or region-mask write in this routine. `SH_NI*_LLP_RESET` and `SH_NI*_LLP_STAT` are not touched here: the PROM reads the link state only in the earlier port set-up and in slot 54.

### What the write means

Header text: `SH_NI0_LLP_RESET_EN`, "Controls LLP warm reset propagation"; field `OK` (bit 0, mask 1): "Allow LLP warm reset to reset SHUB"; `INIT` 1. `SH_NI1_LLP_RESET_EN` is `0x1_5000_2010`, same fields. So writing 0 stops a warm reset that arrives on that link from resetting this SHub. The routine's name and its two operations agree: ports toward a neighbour that is absent or in another partition are fenced (0), ports toward a neighbour in the same partition keep propagation (1). It is not a link-down: `LLP_RESET` (offset `0x08`, the pulse registers) and `LLP_STAT` are not written, and the PROM reads no link status afterwards in this stretch. The line "Erecting partition fences" is the PROM's description (established). That 0 changes only the warm-reset path and not the link is **inferred** from the header text; no manual page states more. The PROM reads the register back in one place only: the port-fill method `0xffa5e0b0` reads it for a record inserted while `SH_SCRATCH1` bit 40 is set and keeps the complement of bit 0 as the port's fence flag; the flag lands in the same byte (`+3` bit 1 of the port entry) that `0xffa50bd0` sets, so a read value 0 means "fenced". That is the neighbour-insert path, and a lone node's own record is inserted with bit 40 clear (the route calculation section above), so it is not on this path.

### Polls, fatal paths and prints in this stretch

- **Polls.** None in `0xffa51200`, `0xffa60410`, `0xffa50880`, `0xffa50bd0`, `0xffa53180` or `0xffa517b0` on a lone node. The remote-route branch of `0xffa0c560` polls (1024 passes) but needs a route word. The L1 request `0x0012` has the L1 timeout of `0x2dc6c0` ticks; a missing reply runs the die routine (l1-requests page).
- **Fatal.** Only "Too many nodes in this partition!" (row 12, count above the L1 value; the die routine returns, so whether the boot stops there is not traced) and an L1 silence on request `0x0012`, which rests on the l1-requests page and was not re-read. A heap failure and a failed fence write are printed and not fatal.
- **Prints.** "Checking partitioning information ....\t\t", "DONE\n", "Erecting partition fences .................\t\t", "DONE\n". The error strings above never print on a lone node. "Invalid partition %d. Running pttn has same pttn id." (`0xffa50880`) needs another record with the local partition id.

### What the model needs

- `SH_NI0_LLP_RESET_EN` (`0x1_5000_0010`) and `SH_NI1_LLP_RESET_EN` (`0x1_5000_2010`): one bit of storage, reset 1 (header INIT, inferred), 64-bit stores accepted, reads return what was written. The PROM writes 0 to port 0 then port 1 and never reads them. With no link behind the port nothing else happens; a model with a link would stop delivering warm resets (`LLP_RESET` bit 1 on the peer) to the SHub once the bit is 0.
- `cpu_bits` bit 1 reads 1 here (set by the PROM), bit 0 is unrelated, and `0x1_5003_1560` bit 2 should read 0 (a set bit only prints a RAM page).
- The progress write, `SH_SHUB_ID` read and the L1 request `0x0012` reply as before. No other register is needed in this stretch.
- Not checked: the klconfig walk `0xffaa20f0`, the console call `0xffa1f170`, whether other code writes the two registers later, and the `0xffa4f9b0` router path (no router on a lone node).

### Review

Independent re-read, 2026-11-16, by a reviewer who wrote none of it. Ghidra (IA-64, `--sn2-prom --no-analysis`) over the named addresses; `ia64-linux-gnu-objdump` over the whole image for slot addresses, immediates and predicates. Header text read through our holdings at Linux/MIPS tree, commit 8ef7d46c94d5.

**Confirmed.** `0xffa51200` and the two call slots `0xffa5167c` and `0xffa516dc`, with the print and "DONE" calls and the three strings; the chain `0xffad761c` to `0xffa485a0` to `0xffa4873c`, progress 0x25 (decimal 37 at `0xffa485e6`), `main_three` entered through descriptor `0xffc4d850`; slots 49 and 62 of the table at `0xffbd7c18` (descriptors `0xffc4bd50` and `0xffc4bb30`, functions `0xffa5d5b0` and `0xffa60410`); the method's operation to value mapping (operation 1 gives 0, otherwise 1), the bit 0 test of argument 4, the two-pass loop at `0x1_5000_0010 + 0x2000 p`, the mask AND `0xff`, stop on first negative; the local write path of `0xffa0c560` to `0x8000_0009_5000_0010`; the second call writing nothing (`~M & 0xff` = `0xfc`); the port-count method returning 2; `0xffa50bd0` and `0xffa53180` as described; the header facts (name, `OK`, "Allow LLP warm reset to reset SHUB", mask 1, INIT 1, NI1 stride `0x2000`); `LLP_RESET` and `LLP_STAT` not touched; the one read-back in `0xffa5e0b0` under `SH_SCRATCH1` bit 40, the only code literals for `0x1_5000_0010` in the image being that read (`0xffa5e2f6`) and the write (`0xffa60476`); the node-count check and the L1 clamp to at least `0x800`; no poll in this stretch on a lone node.

**Changed.** Row 4: bit 1 of `cpu_bits` only gates the prints in `0xffa50880`; the real gate is `0xffa485a0` (row 5). Gate text now says that `0xffa44660` stores (index is 0), through the lock cycle, and where it is called. "Returns 2" holds only for partition byte 0; a return of 1 takes another path. `0xffa51200` skips a router record with `+0x68` bit 2 set, and the reason for `+0x5b` bit 0 is regraded inferred. `r34` note rewritten (the stop is the bundle before the `st8` at `0xffa0e656`). Row 11: `0xffa517b0` calls slot 62 itself for router records, and its klconfig walk is not shown RAM-only, so "RAM only on a lone node" is inferred. Row 12 and the fatal list: the die routine returns, so "parks" and "fatal" were stronger than the code shows. The read-back flag is the same byte `0xffa50bd0` sets.

**Not checked.** The klconfig walk callees beyond `0xffaa0fc0`; `0xffa4fb40`, `0xffa50f00` and `0xffa4f6c0`'s callers; the L1 die-on-silence path (taken from the l1-requests page); the console call `0xffa1f170` and the print routine; other FIT components and the compressed SAL runtime (the register may be touched there); the `+0x35` and `+0x5b` field semantics beyond their tests. The l1-requests page labels the `0x0012` step "progress 0x26", while `0xffa485a0` writes 0x25; not changed here.

**Model requirements.** No change: the registers, reset 1, write-0 behaviour, `cpu_bits` bit 1 = 1 and `0x1_5003_1560` bit 2 = 0 stand.

## Review of the SCRATCH2 identity notes

Independent re-read on 2026-11-16 (PROM 10.54 `0xffa8d120`, `0xffa8cea0`, `0xffa60a70`; the L1 side is in sysco).

**Confirmed.** The PROM decode: tag byte `0x6c`; rack bits 34:26 (9 bits), bay 25:20, slot 38:35, slab 18:16 (3 bits), partition 15:8, bit 19 a flag handled by `0xffaac0a0`; module packed with type `c` by `0xffa7d010`. The writer `0xffa8cea0` keeps bits 63:39 and bit 19 and writes through `0xffa0c560`. Value `0x0410006c` for rack 1, bay 1, SHub 0, partition 0.

**Changed.** The L1 writes the rack as 10 bits (low 6 in the data word, `(cfg[8] >> 6) & 0xf` in the high word), so rack bit 9 lands on bit 35, which the PROM reads as slot bit 0; harmless for racks below 512. The PROM-side writer function first polls a word for up to 10 s ("timed out locking"; register not decoded), see the klconfig review.

**Not checked.** Whether the local SHub ever takes the writer path; hardware reads.

## The router routines of this image

The SAL 5.04 image also carries the routines that configure a NUMAlink 4 router a SHub 1 node reaches through its two
NI ports (`nl4r_init_global` `0xffaaa840`, `nl4r_config_global` `0xffaaab20`, `nl4r_config_port` `0xffaab070`, the
route-table distribution `0xffa5b5d0`, and the NUMAlink 3 pair `0xffaaa4e0`, `0xffaaa740`). A lone node never reaches
them (a node with no peer skips the discovery and the walk above). Their registers, values and order, the lock, and
the comparison with the SHub 2 image are in [../router_nl4/global-config.md](../router_nl4/global-config.md). Read in
Ghidra with an objdump cross-check; the page there is not yet independently reviewed.
