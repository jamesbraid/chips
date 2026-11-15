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
| A39 | `0xffa0be1c`, reached from `0xffa197f0` (call at `0xffa19bdc`) through `0xffa0f8c0` | R64 `0x8000_0009_0000_0000 + (nasid << 38)` | the chip identification word at offset `0x1_0000_0000` (global window); bits 27:12 stored as the node's part number, bits 31:28 as its revision | a bounded read (must not fault). The part number is compared with 17251 (`0x4363`) at `0xffa959a6`; that function is reached through a table, so which register feeds the compare is not traced: **inferred** that this word does | established (access); inferred (required value) |
| A40 | `0xffa1f430` (`sysctl_init`, call at `0xffa19c0c`) | A30 again, then the L1 start. This is where this page stops | | | established |

The routines above reach SHub registers through three small accessors that appear in the lists: a 64-bit load `0xffa0e5a0` and a 64-bit store `0xffa0e640` (plain `ld8` and `st8` on a physical address, in physical mode), and the node-object read `0xffa0bd20`, which for the local node (first argument 0) forms the global-window address from a NASID and an offset and does one `ld8`. The `main()` calls through operation tables (`0xffa1a910`, the object operations behind `[obj + 32]`) are not resolved statically: which registers they touch, and the exact order of the first L1 console accesses, are listed under [What was not traced](#what-was-not-traced).

### The node lock (used by A28, A29, A34 and A37)

The routine that takes the lock is `0xffa0ed30` (read in full); `0xffa0e730` wraps it around a read-modify-write of `0x8000_0081_5003_1550`, and `0xffa0ee40` releases it. One cycle issues, in order:

1. R64 `0x8000_0081_1003_0000 + 0x80 * (slice & 3)` (`0xffa0e020`; the value's low byte is later written as a progress code, so any value is accepted; its meaning is **unknown**).
2. R64 `0x8000_0081_1006_0280` and R64 `0x8000_0081_101c_0000` (`0xffa0da70`, the clock time in microseconds; the read of `0x1_1006_0280` gives the tick period).
3. R64 `0x8000_0081_101d_0208`, repeated with a short delay (`0xffa0fc90`) until it reads 0, with a deadline of 1,000,000 microseconds on the clock; on timeout the PROM writes 0 to `0x8000_0081_101d_0200` and keeps polling.
4. P(low byte of step 1's value): R64 and W64 history, two LED stores.
5. R64 `0x8000_0081_5003_1550`, W64 the same address with the bit or field changed.
6. W64 `0x8000_0081_101d_0200` with 0 (release, `0xffa0ee40`).

What the code needs (established as the test, **inferred** as hardware behaviour): `0x1_101d_0208` reads 0 when the lock is free and, if it is a hardware lock, a read that returns 0 takes it, and a write of 0 to `0x1_101d_0200` frees it. A plain register pair where `0x208` always reads 0 satisfies every access read. If `0x208` read non-zero forever the PROM would loop forever; the forced write of 0 to `0x200` is its only recovery. Whether a read has a side effect in the chip is **unknown**.

The word `0x1_5003_1550` is the PROM's own storage (inferred, from its use): bits 21 to 24 (21 + slice), 26 to 29 (26 + slice), 30 to 33 (30 + slice), 35 to 38 (35 + slice) and bit 34, and a 3-bit count at bit 47 (even slice) or bit 50 (odd slice), which each present slice publishes from a PAL call and the master waits for as that many ready bits among 29:26 (inferred; a reviewer's reading of the local-master wait). It must read back what was written and read 0 before the first write (A10 or the loser's undefined value). Bits 29:26 are the "other processor flagged" bits that SAL_A's error path clears.

## Accesses not on the reset path

SAL_A has two more groups that run only on other reasons, kept here so the access list is complete.

- **Reason 1 (machine check) or 2 (INIT), SAL_A end (`0xffc4e570`).** R64 `0x8000_0081_1003_0000 | ((slice & 3) << 7)` into `r31` before branching to SAL_B offset `0x20` or `0x10`. Reason 0 does not make this read: its branch to `0xffc4e580` skips it (`cmp.eq p6=0,r3` at `0xffc4e4d0`, `(p6) br` at `0xffc4e4fc`). This corrects [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#sal_a-on-shub-1), which lists the read for reason 0 as well.
- **SAL_A error path (`0xffc4e090` to `0xffc4e2d0`),** taken only if bit 2 of `r35` is set and its low two bits are not zero (PAL reports a fault). P(176): R64 and W64 history, W16 LED A and LED B; then RMW of `0x8000_0081_5003_1550` clearing bits 29:26; RMW of `0x8000_0081_101d_0080` ORing `0x280_0000_0000`; W64 `0x8000_0081_2000_0000` with `0x1_0001_0000_0000`; then a spin. The SAL_B reset entry has a similar path for a non-zero reason argument (code 179, `0xffa1de06` to `0xffa1df7c`: P(179) then a spin).

## Registers touched

For each register: where the PROM sees it, the unit by address block, the Linux name, what a read must return, the grade of that requirement and the reset value. "Reset" is the value the PROM can rely on before its own first write; every entry is *unknown* because no document gives it, and the entry says what the code tolerates or requires.

| Address (local form; `0x1_...` is the node offset) | Window and unit | Linux v5.3 name or our label | What a read must return | Grade |
|---|---|---|---|---|
| `0x81_1006_0580` | local, LB | `SH1_SHUB_ID` (unnamed fields besides revision: labels below) | bits 42:32 any NASID; bits 31:28 revision, either side of 2 accepted (above 2 chooses `0x3b03f7` and `0x4047`, 2 or below `1009` and `0x4045`); the whole word reads back what the PROM stores (see [the SHub ID register](#the-shub-id-register)) | established (reads); inferred (what hardware returns) |
| `0x81_1002_0000` | local, LB | unnamed; label `lb_reg_1002_0000` (ours) | never read in this phase | established (the write) |
| `0x81_2001_0100` | local, PI | unnamed; label `pi_reg_2001_0100` (ours) | bit 24 settable; any other bits kept; reads back as written | established (access); inferred (role) |
| `0x81_5003_1500 + 16*n` (n = 0 to 3), `1510`, `1530` | local, NI block by address | unnamed; label `cpu_hist` (ours) | plain 64-bit storage; reads what was last written | established (use); inferred (storage) |
| `0x81_5003_1540`, `1550`, `1560` | local, NI block by address | unnamed; label `cpu_bits` for `1550` (ours); `1560` is later the debug-switch word | plain 64-bit storage, 0 after SAL_A's winner writes them | inferred |
| `0x81_101d_0080`, `0x81_101d_0088` | local, LB | unnamed; labels `lb_elect` and `lb_elect_set` (ours) | after a write of v to `0x88` a read of `0x80` returns exactly v, twice; `0x80` is also read-modify-written at bits 39 to 41 later | established (test); relation unknown |
| `0x81_101d_0100` | local, LB | unnamed; label `lb_l1_state` (ours; the PROM's own names for the same word are `sc_shub_state_reg` and `sc_shub_pushed_data_reg`) | bits 41:39 read back as written (7) after A16 and the other bits are kept; no reader that requires 7 was found | established (access); inferred (any requirement) |
| `0x81_101d_0200`, `0x81_101d_0208` | local, LB | unnamed; label `lb_lock` (ours) | `0x208` reads 0 when free; `0x200` accepts 0 | established (test); inferred (behaviour) |
| `0x81_1003_0000 + 0x80*(slice & 3)` | local, LB | unnamed; label `lb_slice_rec` (ours) | any 64-bit value; the low byte becomes a progress code | established (read); unknown (meaning) |
| `0x81_1006_0480` | local, LB | `SH1_IPI_ACCESS` | accepts 1 | established |
| `0x81_1006_0280` | local, LB | unnamed; label `rtc_ctl` (ours) | reads back the stored value (bits 13:4 give the tick period); written before its first read | established (use); inferred (bit roles) |
| `0x81_101c_0000` | local, LB | `SH1_RTC` | accepts a write of 0, then a 55-bit counter that advances | established (access) |
| `0x87_fed0_0000` + `N*0x10000` (N = 0 to 3) | local junk bus | `SH1_REAL_JUNK_BUS_LED0` to `LED3` | 16-bit writes accepted; not read | established |
| `0x9_2002_0080 + (nasid << 38)` | global, PI | unnamed; label `pi_slice_present` (ours) | bit `slice` clear for every slice but the running one; later CPU-enumeration callers of the same word read bits 0 and 1 (first processor of slices 0 and 1) and bits 4 and 5 (second processor), and the own-slice bit they expect was not traced, so a model should set it | established (access); inferred (meaning) |
| `0x9_0000_0000 + (nasid << 38)` (offset `0x1_0000_0000`) | global, MD block by address | unnamed; label `chip_id_word` (ours) | bits 27:12 = `0x4363` and bits 31:28 the revision, if the compare at `0xffa959a6` takes this word | inferred |

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
| `0x1_101d_0208` | yes (the lock) | 0 to proceed; non-zero is waited out for 1,000,000 microseconds, then forced | unknown (requires: reads 0 eventually) |
| `0x1_1003_0000 + 0x80*slice` | yes | any value | unknown (any) |
| `0x1_2002_0080` | yes (A33) | bit of each other slice must be 0 for a one-processor node | unknown (requires bit 0 for the other slices) |
| `0x1_0000_0000` | yes (A39) | `0x4363` in bits 27:12 if the later compare is on this word | unknown (requires `0x4363`, inferred) |
| `0x1_1006_0280`, `0x1_101c_0000` | no: written (A22, A23, A24) before the first read | none | the reset value never reaches the PROM; unknown |
| `0x1_1002_0000`, `0x1_1006_0480`, `0x7_fed0_0000..3` | never read | none | unknown (not needed) |

## The SHub ID register

`0x1_1006_0580` (`SH1_SHUB_ID`) is read by the node-id routine at `main` start (A30, and again on later calls) and inline at 18 sites in the table builder (A26), and is written once by a later routine at `0xffa95a30` (the only direct call is `0xffa5f84c`, in the NUMAlink numbering path, after the jump to RAM, so outside this page's phase; read in full for this question). Linux v5.3 treats it as read only and names only the revision (bits 31:28; `SH1_SHUB_ID_REVISION_MASK`). The PROM's write, an `ld8` of the register through the node-object read, then `dep` into the value, then a 64-bit store through the node-object write, is:

- bits 42:32 replaced by the NASID argument;
- bits 45:44 replaced by 0, 1, 2 or 3, chosen from an argument (with bits 10:9 masked and the rest halved): 31 or below gives 0, 63 or below gives 1, 127 or below gives 2, more gives 3;
- bits 52:48 replaced by 1, 2, 4, 8 or 16, chosen from a 16-bit field of the second argument: 63 or below gives 1, 127 or below 2, 255 or below 4, 511 or below 8, more 16.

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

## What was not traced

The page covers the accesses found by reading every function reachable by direct calls from the reset entry and from `main` up to `sysctl_init`. Four things are left, none of them a gap in the accesses listed above:

- Calls through operation tables and function descriptors (`0xffa1a910`, the node-object operations behind `[obj + 32]`, PAL calls) were not followed. A different register may be touched there. The L1 start-up, which this page ends at, is reached through them.
- The exact order of the first L1 console accesses (UART at `0xf_fed4_0000 + 8*n` in the global form, or `0x7_fed4_0000 + 8*n` local; the state word `0x1_101d_0100`) is from [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#l1-controller-dependency), not re-read here.
- Which error and workaround routines run at the reset entry or in `main` before `sysctl_init` depends on PAL return values the code does not show; the accesses on the normal path are listed.
- The roles of `0x1_1002_0000`, `0x1_2001_0100`, `0x1_1006_0280` bits other than the period field, `0x1_1003_0000 + 0x80*slice`, the bit meanings in `0x1_5003_1550`, and what a hardware read of `0x1_101d_0200` and `0x208` does: **unknown**. A SHub 1 programmer's reference for the local block, the processor interface and the network interface block would settle them; a hardware read is the last resort and needs the repository owner's approval.

## Corrections to earlier pages

- [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#sal_a-on-shub-1) step 7 says SAL_A reads `[0x81_1003_0000 + (slice & 3) * 128]` for reason 0. It reads it only for reasons 1 and 2 (above).
- The part number and revision the PROM stores for a node come from `0x1_0000_0000` (A39), not from the SHub ID register; the earlier page's inference that the SHub ID register carries the widget-ID layout is not supported by this reading.
