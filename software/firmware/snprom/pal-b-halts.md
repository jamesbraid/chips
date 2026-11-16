# PAL_B 5.73: the stop at `0xffe7f100` and the self-test that leads to it

What the spin at `0xffe7f100` in the SN2 PROM `shub1snprom.bin` (SAL 5.04, sha256 `51ccf9ad...`, flat load at `0xffa00000`) is, who
branches into it, which self-test group decides, and which values a processor has to supply for the PAL not to stop there. Read in
the IA-64 Ghidra module (every bundle of the 6 MiB image dumped, branches and constants read from that listing). Addresses are
image addresses. For this PAL they are also the run addresses: `cr.iva` is set at `0xffed88b0` to `0x80000000ffe78000`, the image
address of PAL_B 5.73, so nothing is relocated at run time. The `movl` constants inside the PAL (for example `0x80000000fff68170`
at `0xffee0186`) are link-time addresses, `0x88000` above the image address, and the code subtracts the difference (`sub r6=r2,r3`
at `0xffee0190`). The stop is not a read of msr[1640]: the Dell pattern in [../pal/cross-vendor.md](../pal/cross-vendor.md) (a
msr[1640] bit 4 test that branches to its own bundle) is a different site; the shape is the same, a deliberate stop with no re-read.

**Grades.** *established*: instruction, operands and flow read in the image. *inferred*: reasoned from them. *unknown*: not settled,
with what would settle it. Nothing here says what hardware does unless a manual says it.

## 1. What `0xffe7f100` is

*Established.* `0xffe7f100` is the bundle `nop.m; mov r7=0xcccc; br.few 0xffe7f100` (it branches to itself). It is the second half of
a routine that starts at `0xffe7f000` and that every fatal path of PAL_B 5.73 leaves through:

- `0xffe7f000` to `0xffe7f03c`: `r28` = `psr` after three deposits (`0xffe7f00c`, `0xffe7f016`, `0xffe7f01c`): bit 35 set, then two
  deposits of zero whose encoded length is 64 at positions 13 and 14 (`dep r28=0,r28,13,64`). The SDM truncates a deposited field that runs past bit 63 ("the most
  significant len + pos6 - 64 bits of the deposited bit field are truncated", SDM rev 2.3 vol 3, `dep`, p. 3:51, **established**), so they clear bits 63:13, bit 35 included, leaving `psr` bits 12:0. `psr.ic` and `psr.i` end clear. Then `br.few 0xffe96bd0` with `b0` = `0xffe7f040`. `0xffe96bd0` is the PAL's return-to-physical-mode helper: `rsm 0x6000`,
  `cr.iip` = `b0`, `cr.ipsr` = `r28`, `rfi`. It touches no MSR and no memory.
- `0xffe7f040` to `0xffe7f06c`: read the doubleword at physical `0xffffffe0` (the FIT pointer, `0x80000000ffa00000` in this image),
  add `0x18`, read that doubleword (the size/version word of FIT entry 1) and `tbit.z p0,p6=r2,0x19`, so p6 is set when bit 25 is
  **set**.
- `0xffe7f07c`: `(p6) br.cond 0xffe7f110`. Not taken: fall through the eleven nop bundles `0xffe7f080` to `0xffe7f0fc` to the spin at
  `0xffe7f100`.
- With p6 set, `0xffe7f110` to `0xffe7f29c` is a second, different stop: it saves `pmc[0]`, sets bits 43:42 of msr[1553], sets msr[1640]
  bit 54 and msr[1730] bit 43 (clears bit 36), executes the reserved M-word `0x108000000` (`0xffe7f1f6`), closes the window and branches
  back to `0xffe7f110`. It repeats forever.

In this image the qword read at FIT + `0x18` is `0x000107790000a8dc` (PAL_B 7.79 entry: size `0xa8dc`, version `0x0779`, type 1). Bit 25 lies in
its reserved byte (bits 31:24) and is **clear**, so a processor that reads the FIT correctly takes the 0xcccc spin, not the
reserved-slot loop (established). The FIT pointer and the qword are plain physical reads at `0x80000000ffffffe0` and `0x80000000ffa00018`; if a
model returns something else there, the other arm runs instead.

**Where it reports.** *Established:* nowhere. Neither arm stores `r30`, `r7` or any status; there is no call out, no mailbox write, no SAL
entry. `r7 = 0xcccc` is a marker a debugger can see, nothing reads it. The code that jumps here sets `r30` to a reason first (below), and
`r30` is also not read by `0xffe7f000`. What is recorded is done before the jump, in `ar.k7` (section 3). Whether the marker or
`r30` is meant for an external probe is **unknown**; the stop is a deliberate halt, not a poll.

**Every way in** (established, branch scan of the whole image): `0xffe7f100` is entered only by fall-through from `0xffe7f07c`.
`0xffe7f000` is entered from these:

| Site | Form | Reason in `r30` | Context |
|---|---|---|---|
| `0xffe880ac` | `br.few` | none set here | the `PAL_B + 0x100a0` stub; reached when the generic PAL_A hand-off jumps to a FIT PAL_B at `+0x100a0` with `r30 = 2` (`0xffed7906` to `0xffed794c`, taken when msr[1779] bit 15 is set; the target is the first FIT PAL_B, not necessarily 5.73) |
| `0xffeba1fc` | `br.few` | 5 or 6 (`0xffeba1f0`, `0xffeba1f6`, under predicates from a `mov pr=`) | event-entry path that reads one MSR (`0xffeba1c0`) and executes a reserved B-word at `0xffeba1ec` |
| `0xffed41ec` | `(p14) br.cond` | 3 (`0xffed41e6`) | after a msr[`r30`] write and a test of the written value: bit 63 set and bit 57 clear |
| `0xffed47ec` | `br.few` | 9 (`0xffed47dc`) | after a `cr.iip` save and `mf.a` |
| `0xffebf2ec` | `br.few b7` | not set | computed from `ip` at `0xffebf2ac` to `0xffebf2e6` (`0xffebf2a0` minus `0x402a0` = `0xffe7f000`); this is the self-test failure route |

The first four are event-handler errors (inferred from their context: machine-check and INIT entry code); only the last is on the boot path the model runs.

## 2. How the model gets there: the self-test table

*Established.* After SAL_A answers the reason-3 query, PAL_B continues at `0xffed8740` (the return address it handed over as `r36`, built at
`0xffed7bd0` to `0xffed7bf0` as `0xffed78d0 + 0xe70`). The sequence is:

1. `0xffed8740` to `0xffed8826`: the MSR accesses are msr[`0x588`] (bit 16 cleared, then polled until bit 40
   clears, `0xffed8770` to `0xffed878c`), msr[`0x608`] = 0, msr[`0x60a`], the reserved M-word at `0xffed87d6`, msr[`0x610`] = `0x10`,
   then `rfi` through `0xffe96bd0` to `0xffed8830`.
2. `0xffed885c`: `r37 = r37 | 0xe030ffff8000` (PAL forces these skip bits on whatever SAL returned).
3. `0xffed88c0` to `0xffed88dc`: read msr[0]; if bit 17 is **set**, branch to `0xffed8920` and skip the table. If clear (the model's
   case): `0xffed88ec` **`mov r13=r37`**, then `br.few 0xffee0160` with `b0` = `0xffed8920`.
4. `0xffee0160`: `alloc 96`, `r12 = 4`, `r6` = link-to-run delta, `r7 = ip + 0x580` = `0xffee06f0`. Sets psr, clears the protection key and
   region registers, clears `msr[0x5e1..0x5e8]`, and so on, then reaches `0xffee0390` (below) and the table loop.

The write at `0xffee0390` is `mov msr[r2]=r3` with `r2 = 0x668` = msr[1640] after `dep r3=-1,r3,63,1` (`0xffee038c`): it sets bit 63 and
leaves bits 59 and 56 as read (`0x0100000000000000` becomes `0x8100000000000000`). Nothing reads bit 63 on the path to the stop and no
other code in this page tests it; its meaning is **unknown** (the read of msr[1640] at `0xffee0300` to `0xffee0320` ANDs it with
`0xb8000000000080` and drops the result, `r2` is overwritten at `0xffee0326`). Bit 56 is the "state valid" bit the hand-offs test
(pal-msrs.md); bit 59 is set at the `br.ia` return only when `r1` is non-zero (pal-instructions.md), clear here.

**The table** (established; entries are link addresses minus `0x88000`, resolved from the thirteen qwords at `0xffee06f0`):
`0xffee7c60`, `0xffee1e20`, `0xffeec200`, `0xffee8960`, `0xffee1010`, `0xffee1ee0`, `0xffee26f0`, `0xffeeb7c0`, `0xffee2b70`, `0xffef2990`,
`0xffef2e80`, `0xffef2c40`, `0xffef3290`, then a zero qword. The loop (`0xffee03a0` to `0xffee03dc`) loads each offset, adds `r6`, loads
`b0`, calls it with `r8 = 0`, `r9 = 0` and ORs `r9` into `r12` (the call at `0xffee03c0`). On the passing path of entries 1 to 9 there is no MSR access and no reserved M or B word (a flow scan from each entry address over the listing, following
direct branches and calls, found none; the same scan finds both in entries 12 and 13, which the skip bits keep from running). Two arms
are not on that path: a failing group 35/34 in entry 9 reads and writes msr[1640] (`0xffee3432`, `0xffee3452`: bit 60 set) before its result call, and
the result routine's own `mov r37=msr[r37]` at `0xffebf140` (see below). Entry 8 does contain one B-unit word that is not a defined opcode
(`0xffeeb83e`, major opcode 10, which binutils 2.44 prints as `data8`), apparently deliberately: a fault test, not a reserved no-op (section 3).

Each entry is a test group guarded by one bit of `r13` (a **set** bit skips the group; read as `tbit.z p0,p1=r13,N` then `(p1) br`):
entry 1 `0xffee7c60` bit 44, entry 2 `0xffee1e20` bit 43, entry 3 `0xffeec200` bit 42, entry 4 `0xffee8960` bit 41, entry 5 `0xffee1010` bit
40, entry 6 `0xffee1ee0` bit 39, entry 7 `0xffee26f0` bit 38, entry 8 `0xffeeb7c0` bits 33 and 32, entry 9 `0xffee2b70` bits 35 and 34 (its `famax` check at `0xffee4490` expects
the SWA fault, see [floating-point exception faults](#floating-point-exception-faults)), entries 10 to 13 bits 16 to 30 (three to five bits each, checked in the listing). `r13 = 0xe030ffffffff` has bits 47:45, 37:36 and 31:0 set, so entries 1 to 9 run
(bits 44 to 38 and 35:32 are clear) and entries 10 to 13 are skipped. A group runs its sub-tests in order and stops at the first that
returns `r8 != 0` (`cmp.eq p7,p6=r8,r0`, then `(p6) br 0xffeec280` in group 42). Then it calls the result routine `0xffebf000` with
`r9 = 0` on success and a constant whose low two bits are `3` on failure (group 42: `0xffeec296`, `r9 = 0x400000003`; group 44: `0xffee7d36`,
`0x100000003`; group 43: `0xffee1e56`, `0x200000003`). Only `r8 < 0` is fatal (below), so a positive nonzero `r8` from a sub-test is
passed on as a failure code that the result routine does not act on.

**The result routine `0xffebf000`** (not a test; established). `p8 = (r8 < 0)`. On failure (`p8`) it clears the top half of `ar.k7`, sets
bits 31:28 to 1 and ORs in the second argument shifted left 32, then stores that to the doubleword at `cr.iva + 0x100b0` if that word is
non-zero. It reads `cr.iva + 0x100c0` (`r37`) and `cr.iva + 0x100d0` (`r38`). With `cr.iva = 0x80000000ffe78000` those are image addresses
`0xffe880b0` (0 in this image), `0xffe880c0` (0) and `0xffe880d0` (a pointer, `0x80000000fff10000`). Because the word at `0xffe880c0` is zero the
bundle at `0xffebf09c` branches to `0xffebf0f0`, which skips the arm at `0xffebf0a0` to `0xffebf0ec` (a `p12`-guarded call to `0xffebf130`, which reads msr[1559]); at `0xffebf0f0` `p13` stays set when `p8` is set and `r9[1:0] = 3` (`0xffebf096`) and bit 59 of the
zero `r37` is clear (`0xffebf0f6`). `0xffebf10c: (p13) br.cond 0xffebf2a0` then goes to `0xffe7f000`. So with the shipped contents a failed group (`r8 < 0`,
`r9[1:0] = 3`) is fatal and a passed group (`r8 = 0`) returns. This is established for the zero words read from the image; those flash words are not
written by the PAL on this path (the store at `0xffebf086` needs `r36 != 0`).

## 3. What the groups test, and what a healthy processor returns

*Established* for the instructions and constants; *inferred* where a sentence says what an emulator needs. The failing group is not identified
by the code; it depends on which instruction the model executes wrongly. Entries 1 to 9 run. Entry 3 (`0xffeec200`, group 42) is read in
full; entries 1, 2 and 8 are summarised from a lighter read (entry 2 and entry 8 matter because they run before or after it).

- **Entry 1** (`0xffee7c60`, bit 44), skimmed: branch-register moves, both banks of `r16` to `r31` through `bsw.0`/`bsw.1`, stacked-register
  frames with `br.call`/`alloc`, and an edit of `rrb.gr` in a saved `ar.pfs` (`0xffee8920`).
- **Entry 2** (`0xffee1e20`, bit 43) executes three `break` instructions with immediate `0x195631` in one bundle, in the M, I and B slots.
  Each must fault to the break vector at `cr.iva + 0x2c00` (`0xffe7ac00`). The handler reads `cr.isr` (slot number in bits 42:41), reads
  the faulting bundle at `cr.iip` and pulls the immediate out of that slot, then does `r14 = r14 << (slot+1) + (slot+1)` and returns with
  `rfi` to the next slot (`cr.iip` advances a bundle after slot 2). Starting from `r14 = 311` the three breaks must leave `r14 = 19955`
  (`cmp.eq p7,p6=r14,r34`, `0xffee1e82`), else `r8 = -1`. The same handler takes `0x195871`, `0x195872` and `0x195873` (OR into,
  AND-NOT out of, or replace the saved `cr.ipsr`) and sends any other immediate to `0xffe7ec10`. An emulator that does not deliver the break
  fault, reports the wrong slot in `isr.ei`, or restarts at the wrong slot fails here, before entry 3.
- **Entry 3** (`0xffeec200`, bit 42) first sets `r8 = -1` and `r9 = 0x400000003`, then calls these sub-tests in order and stops at the first
  `r8 != 0`:

| Sub-test | Address | Checks |
|---|---|---|
| 1 | `0xffeec2d0` | predicate and compare semantics, in the stages below |
| 2 | `0xffee0cc0` | branch registers `b0` to `b7`: write and read back `16` to `23` and the patterns `0`, `-1`, `0x5555...`, `~0x5555...`; then eight indirect `br` through `b0` to `b7` that must each run their target once (sum `255`) |
| 3 | `0xffee0760` with helper `0xffee0b20` | application registers (below) |
| 4 | `0xffee2170` with helper `0xffee2530` | control registers (below) |

**Sub-test 1, `0xffeec2d0`, exactly.** It sets `r8 = 0` at `0xffeec320` (after the first stage) and every failure jumps to `0xffeec310`
(`r8 = -1`, `br 0xffeec970`), so `r8` is `-1` if any stage below fails and `0` otherwise. The failure tests are all of one shape: a
`cmp.ne.or p1,p0=...` or a predicate read by `(p) br.cond 0xffeec310`. Stages:

1. `0xffeec2e2` to `0xffeec3b8`: `cmp.eq`, `cmp.lt` (immediate `-1`), `cmp.ltu` and `cmp.lt` against `r0`, each with both result predicates in
   both orders; the true predicate must be set and the complement clear.
2. `0xffeec3c2` to `0xffeec48e`: with `r34 = -1`, `r35 = 1` and `p1 p3 p5 p7` preset to 1, the parallel forms `cmp.*.and`, `cmp.*.or` and
   `cmp.*.or.andcm` (with `.andcm` clearing the second target when the condition is true) must leave `p1 p4 p5 p8` set and `p2 p3 p6 p7` clear.
3. `0xffeec492` to `0xffeec5ae`: `mov pr=rN,0xfffffffffffffffe` (mask excludes `p0`) then `mov rM=pr` for `-1`, `0xffffffff`, `0xffff0000ffff`,
   `0xff00ff00ff00ff`, `0xf0f0f0f0f0f0f0f`, `0x3333...`, `0x5555...` and `0`; each readback must equal the input (the odd patterns
   all have bit 0 set, and `pr` bit 0 reads 1; the last input is `1`, compared with the readback after `mov pr=r0`).
4. `0xffeec5b2` to `0xffeec73e`: after `mov pr=r0,-2` (`p1` to `p63` all 0), 55 predicated adds (`p9` to `p63`, each adding 1 to one of `r36` to
   `r43`) must all be skipped; every counter stays 0.
5. `0xffeec748` to `0xffeec89e`: after `mov pr=r34,-4` (`r34 = -1`, mask excludes `p0` and `p1`, so `p2` to `p63` all 1), the same 55 adds
   must all run: `r36` to `r42` equal 7 and `r43` equals 6.
6. `0xffeec8a2` to `0xffeec96e`, the rotating-predicate stage: `mov pr=r0,-2`, then `p62` set; four groups of predicated `adds` over `p16`, `p17`,
   `p18`, `p62`, `p63` with increments 1, 2, 4, 8, separated by three `br.call` of `0xffeec990`. That routine reads `rrb.pr` (bits 37:32) from
   its own `ar.pfs`, decrements it (a value of 0 becomes 47) and returns with `mov ar.pfs`/`br.ret`, so each return restores one more rotation
   of the predicate file in the caller. A single set predicate (physical `p62`) then appears as logical `p62`, `p63`, `p16`, `p17` after 0, 1, 2, 3
   returns, so the final compares (the last at `0xffeec96e`) need `r36 = 4`, `r37 = 8`, `r38 = 0`, `r39 = 1`, `r40 = 2`. This needs `br.call` to clear
   `rrb` in the callee, `ar.pfs` to carry the callee's edit of `rrb.pr`, and `br.ret` to load it into `cfm`.

The compare that decides `r8` is therefore whichever stage 1 to 6 fails first; the last one, taken only if everything before it passed, is
`cmp.ne.or p1,p0=2,r40` followed by `(p01) br.cond 0xffeec310` at `0xffeec96e`. I re-derived stages 2 and 6 by hand and every other stage
by reading; I did not run the routine.

**Sub-test 3, `0xffee0760`.** Reads `ar.k0` to `ar.k7`, `ar.rsc`, `ar.bspstore`, `ar.rnat`, `ar.unat`, `ar.lc`, `ar.fpsr` and saves them. The
helper `0xffee0b20` is called four times with `r32 = 0, -1, 0x5555..., ~0x5555...` and `r33`/`r34` taken from fixed `ar.fpsr` and `ar.pfs`
patterns. It writes `ar.k0` to `ar.k7`, `ar.bspstore` (with `ar.rsc = 0`), `ar.rnat`, `ar.pfs`, `ar.ccv`, `ar.unat`, `ar.lc`, `ar.fpsr`, `ar.ec`
and `ar.rsc`, and demands: `ar.k*`, `ar.ccv`, `ar.unat`, `ar.lc` read back exactly; `ar.bspstore` as `r32 & -8`; `ar.rnat` with bit 63 clear;
`ar.rsc` as `r32 & 0x3fff001f` (this can set `mode` to 3, so an emulator must not act on the RSE for those instants); `ar.ec` as `r32 & 63`;
`ar.fpsr` and `ar.pfs` as written. **`ar.itc` must also differ between two reads** (`0xffee0b82` and `0xffee0bf2` in the helper;
`0xffee08f2` and `0xffee09b2` in the caller): a model whose `ar.itc` is frozen between instructions fails here with `r8 = -1`. The caller
then sets `ar.k0` to `ar.k7` to `16` to `23`, `ar.rsc` `24`, `ar.bspstore` `32`, `ar.rnat` `33`, `ar.ccv` `34`, `ar.unat` `35`, `ar.fpsr` `36`,
`ar.pfs` `38`, `ar.lc` `39`, `ar.ec` `40` and expects each back.

**Sub-test 4, `0xffee2170`.** Runs with `rsm 0x6000`. Reads `cr.dcr`, `cr.itm`, `cr.iva`, `cr.pta`, `cr.ipsr`, `cr.iip`, `cr.ifa`, `cr.itir`, `cr.ifs`,
`cr.lid`, `cr.tpr`, `cr.itv`, `cr.pmv`, `cr.lrr0`, `cr.lrr1` and `cr.cmcv` to save them. Helper `0xffee2530` runs four times with a pattern
in `r32` (`0`, `-1`, `0x5555...`, `~0x5555...`), a `cr.pta` value (`64`, `0xffffffffffff81fd`, `0x5555555555550155`,
`0xaaaaaaaaaaaa81a8`) and a `cr.ifs` value. It writes the pattern to `cr.itm`, `cr.iva`, `cr.iip`, `cr.ifa` and to `cr.dcr`, `cr.ipsr`,
`cr.itir`, `cr.lid`, `cr.tpr`, `cr.itv`, `cr.pmv`, `cr.cmcv`, `cr.lrr0` and `cr.lrr1` after the test ANDs it with a per-register constant
(`0x7f07`, `0x1fff0ffee03e` with bit 41 cleared for `-1`, `0x7f000000fffffffc`, `0xffff0000`, `0x100f0`, `0x100ff`, `0x127ff`), and then
requires the written value back exactly. The constants keep the test inside bits it expects to be implemented; the readback is not masked.
Two readbacks are real rules: `cr.iva` reads with bits 14:0 clear, and `cr.pta`, `cr.ifs`, `cr.itm`, `cr.iip`, `cr.ifa` return all 64
bits. The caller's second pass writes small values (`cr.dcr` 1, `cr.itm` 2, `cr.iva` 0x8000, `cr.pta` 112, `cr.ipsr` 6, `cr.iip` 4,
`cr.ifa` 5, `cr.itir` 8, `cr.ifs` 9, `cr.lid` 0x10000, `cr.tpr` 16 and then 17 to 21 for `cr.itv`, `cr.pmv`, `cr.lrr0`, `cr.lrr1`,
`cr.cmcv`) and expects each back, then restores every saved value, including `cr.lid`. Whether the constants match the Madison implemented
bits is **unknown**.

**Entry 8** (`0xffeeb7c0`, bits 33 and 32), skimmed, not traced through its handlers: a run of instructions that must trap or fault (the B-unit
word at `0xffeeb83e`, `psr.tb` set and then a taken branch, `chk.s.i`, `break.i 0x195871` and others), each followed by branches to the
failure exit `0xffeebcd0` that must not be reached. The test sets one bit of `r14` before each and expects `r14 = 0` after the handler
has run. An emulator must raise the architecturally correct trap or fault for each; for the B-unit word that is inferred to be an
illegal-operation fault (major opcode 10 is not a defined B-unit opcode). The rules a failing check and its handler must follow are in [Processor behaviour the self-tests depend on](#processor-behaviour-the-self-tests-depend-on).

**What a healthy processor returns.** For the stop not to occur, every group that runs (entries 1 to 9) must leave `r8 >= 0` at its result
call. No MSR, memory or SAL value is read by these groups, so no value can be "supplied": only correct instruction behaviour avoids the stop
(including breaks and faults, an advancing `ar.itc`, the `ar.*` and `cr.*` implemented-bit rules and `rrb.pr` handling). The bit-set skip
in `r13` is not available to a model: `r13` is `r37` as returned by SAL_A ORed with `0xe030ffff8000`.

## 4. What SAL_A puts into `r37` (reason 3)

*Established.* At `0xffc4e310` the reason-3 path (`dep.z r3=r20,0,8` equals 3) calls `0xffc4eaa0`, then `0xffc4e330` to `0xffc4e34c`: `r8 = [r8 + 0x40]`,
`shr.u r8=r8,16`, `or r37=r8,r37`, `mov b6=r36`, `br.few b6`. The only write to `r37` in the SAL_A code reachable from its entry `0xffc4e030` (271 bundles, direct branches and calls followed; the
only indirect transfers are the final `br b6`, a spin, a `br b0` return and the PAL call 528, which returns `r8 = -1` per pal-msrs.md) is that `or`.
No SHub register, no L1 value, no debug-switch word reaches it: the other SHub accesses on the way are writes of progress codes or sit
in the error block that `r35` bits 1:0 = 0 skips. The `or` is reached only for sub-id `0` or `7` in `r20` bits 15:8; any other sub-id
branches at `0xffc4e30c` to `0xffc4e6f0`, which this review did not follow.
`0xffc4eaa0` searches the table at `0xffc51648` (three triples for PAL pairs 7.31/7.79, 5.37/5.73, 1.27/2.25, terminated by `-1`) and then
the 96-byte (0x60) record table at `0xffc51000` for the record whose first doubleword equals the full `cpuid[3]` (for the 5.73 pair `0x1f010504`) and whose
version windows contain the pair. The 64-bit doubleword at record + `0x40` is `0x51` in all 15 records (and in the terminating zero record at `0xffc515a0`, whose `+0x40` field is at `0xffc515e0`; a cpuid that matches no record stops there), so the value ORed into `r37` is **0** in every case:
`r37` comes back as the value PAL handed in, `0xe030ffffffff` (`movl` at `0xffed7a76`), and `r13 = 0xe030ffffffff`. Bit 42 is therefore clear
and group 42 always runs on this PROM, whatever the SHub, L1 or switch state. This answers the "which input sets bit 42" question: none does.

## 5. The question list, graded

1. *Deliberate halt?* Yes (established): a stop with the marker `r7 = 0xcccc`, no report out. The error recorded is in `ar.k7` (bits 31:28 = 1, upper half =
   second argument of the result call) (established); nothing reads it before the stop.
2. *Path.* The indirect call at `0xffee03c0` calls table entries (section 2); no entry on the passing path uses msr[1640] after `0xffee0390`
   (a failing group 35/34 in entry 9 does, section 2). The
   msr[1640] write at `0xffee0390` is not on the decision path (established). The decision is `r8 < 0` with `r9[1:0] = 3` at one of the
   result calls (established); which sub-test fails in the model is **unknown** without a trace of `r8` after each group.
   Meaning of msr[1640] bits 63, 59, 56: bit 56 and 59 as in pal-msrs.md and pal-instructions.md; bit 63 **unknown**.
3. *Model-estimated values on the path.* None on the passing path of entries 1 to 9: no MSR read, reserved slot, `br.ia` table load or SHub read occurs between `0xffee0390`
   and `0xffe7f100` (a flow scan of each entry's reachable bundles for `msr[` and the two reserved words; section 2 names the failure arms
   that do read or write an MSR). Entries 12 and 13, which hold reserved slots, are skipped by `r13` bits 16 to 30. The estimated values the model supplies earlier
   (msr[1212], msr[1226], the `br.ia` return `r1 = 0`) decide only that execution reaches `0xffed75e0` and, via msr[0] bit 17 clear, the table.
   The M-word `0x108000000` appears on the other arm (`0xffe7f1f6`) and in the return path before the table (`0xffed87d6`); the model runs it as a no-op there,
   which is **inferred** harmless for this stop because nothing between it and the table depends on its effect.

## 6. PAL_TEST_PROC: phase two and the failure bits

What the late self-test call `PAL_TEST_PROC` (index 258, SAL progress `0x36`) returns, and which group sets each bit. Read in the
same image as above; nothing was run. The result layout is the Self Test State Parameter (SDM rev 2.3 vol 2, Figure 11-9, p. 2:293):
`state` bits 1:0, `te` bit 2, `vm` bit 16, `ia` bit 17, `fp` bit 18, `mf` bit 19, `test_status` bits 63:32 (established). The
procedure returns `r8` = status, `r9` = that parameter, and `r10` and `r11` reserved (SDM vol 2 p. 2:462).

**Entry (established).** The special path at `0xffe9e5f0` (section 5's PAL_PROC dispatch) maps index 258 to the handler at
`0xffeaa190` (link address `0xfff32190`). It checks `test_address` (`r33`: 8 MiB aligned, bit 63 and bits 62:50 clear), the buffer size
(`r34` bits 55:0, at least `0x600000`), and `r35` bit 0 set (cacheable), else returns -2. `r34` bits 63:56 are
`test_phase`: 1 runs the phase-one table of section 2 with `r13 = test_control | 0xe030ffff8000`; 0 runs phase two: `test_control`
(`r35` >> 16) ORed with `0x803058081000` (bits 12, 19, 27, 28, 30, 36, 37 and 47 are always skipped) goes to the table at `0xffefc280`.
Every path leaves through `0xffeaaa40`, which sets `r10 = 0` and `r11 = 0` (established); the exit stub `0xffe9f260` never touches
`r8` to `r11`. So a non-zero `r10` seen by SAL does not come from the PAL code.

**Phase two table (established).** `0xffefb980` saves state, runs `0xffefc080`, which sets `r41 = 4` (the `te` bit), sets msr[1640] bits 63
and 57 for the duration and calls each of eleven groups with the test address, size, attributes and the skip word. Each group returns
`r8` and `r9`; `r9` is ORed into `r41`. A group is skipped when its bit in the skip word is set (a skipped group returns zero). The always-skipped bits 19, 27, 28 and 30 turn off group 10 sub-test 4 and group 11 sub-tests 4, 5 and 7.

| # | Group | Skip bit | Tests (inferred from the code) | Failure `r9` |
|---|---|---|---|---|
| 1 | `0xffeffa40` | 38 | test-buffer pattern store and read-back | `0x100000003` |
| 2 | `0xffefc530` | 41, 40 (bit 39 is a flag passed to the second sub-test, not a skip) | two sub-tests; fails at once if msr[1640] bit 60 is already set, and a failure sets that bit | `0x20000000002` |
| 3 | `0xffefe0f0` | 45 | not read beyond the entry | `0x800000002` |
| 4 | `0xffef9160` | 46 | ALAT: `ld.a`, `ld.c.clr`, `chk.a`, `invala`, aliased store | `0x400000002` |
| 5 | `0xfff0acb0` | 33 | saves `pkr0`, `pkr1` and `rr0`, calls `0xffefe410`, restores them; a non-zero result fails the group | `0x4000000002` |
| 6 | `0xffeff020` | 34 | not read beyond the entry | `0x8000000002` |
| 7 | `0xffefc680` | 44 | region registers and translation | `0x200000002` |
| 8 | `0xffefd2f0` | 43 | performance monitor registers | `0x1000000002` |
| 9 | `0xffef98f0` | 42 | debug registers (runs only if msr[1714] bit 50 is set) | `0x2000000002` |
| 10 | `0xfff003b0` | 16 to 23, one per sub-test | eight cache-array and error-log sub-tests; first one `0xfff00b30` | bit 43 plus the sub-test number minus one, and bit 0 (`0x80000000001`, `0x100000000001`, ...) |
| 11 | `0xfff04ff0` | 31 to 24, one per sub-test | eight more array sub-tests; fails at once if msr[1640] bit 62 is set | bit 50 plus the sub-test number, and bit 0 (`0x8000000000001`, `0x10000000000001`, ...) (`0x7f8000000000001` when bit 62 was already set) |

Groups 10 and 11 read msr[1640] bit 62 first and, if it is set, return `r8 = -1` with `0x7f80000000001` (group 10, bits 50:43 and 0)
or `0x7f8000000000001` (group 11, bits 58:51 and 0) without testing. A failing sub-test of either group sets msr[1640] bit 62 (`0xfff009dc`
and `0xfff0553c`); nothing in PAL_B clears it (established by scanning every deposit and test of bit 62 in the image).

**Result routine (`0xffefc370`, established).** `r9` = `r41`; bits 62:58 of msr[1640] are deposited into `r9` bits 62:58. If `r9` >> 32 is zero the
state is healthy (`state` = 0). Otherwise: msr[1640] bit 59 sets `ia`, bit 60 `fp` and bit 58 `vm`; `r9` bits 33 and 39 also set `vm`; `r9`
bits 33 to 37 set `mf`; msr[1640] bits 61 or 62 select `state` 1 (performance restricted); bit 58 to 60 or any of those `r9` bits select
`state` 2 (functionally restricted), which wins over 1. If none applies `state` is the low two bits of msr[1640] (inferred as unintended).
`r8` is 0 when `r41` bits 1:0 are zero, else -3 (`0xffefc48c`, a predicated `mov`). Every failure constant has bit 0 or bit 1 set, so any
failing group gives -3. Finally msr[1640] bits 63 and 57 are cleared and the rest is left as it was.

**Decode of the model's `r9 = 0x43f8081400080006` (`r8 = -3`).** `state` 2, `te` 1, `mf` 1, `test_status` `0x43f80814`:

| Bit of `r9` | Source |
|---|---|
| 34 (`test_status` 2) | group 4 failed (ALAT) |
| 36 (`test_status` 4) | group 8 failed (performance monitor) |
| 43 (`test_status` 11) | group 10, sub-test 1 (`0xfff00b30`) failed; it stopped group 10 there, so sub-tests 2 to 8 did not run |
| 57 to 51 (`test_status` 25 to 19) | group 11 returned its "bit 62 already set" constant; bit 58 of it is overwritten by msr[1640] bit 58 (0) |
| 62 (`test_status` 30) | copy of msr[1640] bit 62 |
| 19 (`mf`), 1 (`state` 2) | set by bits 34 and 36 above |

So three groups fail independently (4, 8 and 10); group 11 is a consequence of group 10. msr[1640] ends at `0x4100000000000000`:
bit 62 is the failure latch above (established), bit 56 was set before phase one and is unchanged (inferred; the hand-offs test it,
pal-msrs.md). Fixing groups 4 and 8 alone leaves `state` 1 and `r8` -3. `r10` is not a failing-test index and not a state save: the
PAL zeroes it (SDM: reserved).

**What each failing group expects (established for the constants, inferred for the reading).**

- *Group 4.* Block 1: `ld8.a r2`, `ldfd.a f10`, `ld8.a r18`, `ldfd.a f7` from one address, `ld8.c.clr r2`, a 2-byte store to that
  address, `ld8.a r18` again, then `chk.a.nc` on `r2`, `f10`, `r18`, `f7` with `r14` = 111 and `r15` = 0: exactly 3 must miss (`r15` = 3,
  tested at `0xffef93b6`). Block 2: `invala`, 32 `ld8.a` into `r37` to `r68` from one address, 32 `chk.a.nc`: none may miss (`r15` = 0). Block
  3: `chk.a.nc` on `r0` to `r31`: all 32 miss (`r15` = 32). Block 4: `ld8.a r32` and `ldfd.a f32`, `invala.e r32`, `chk.a.nc f32` hits; `ld8.a r32`,
  `invala.e f32`, `chk.a.nc r32` hits (a miss there stops the PAL). A miss must raise the Speculation fault (vector `0x5700`, ISR.code 0 or
  2, `ipsr.ri` advanced by the Speculation handler at `0xffe7d700`, whose code 0 and 2 arm at `0xffe7d750` also increments `r15` and returns with `rfi`; it requires `r14` = 111, else it goes to `0xffe7ec10`), because PAL runs with `psr.it` clear (see the section below).
- *Group 8.* Helper `0xffefdc80(P, pmc4, pmc13, pmc14, pmc15)` runs with P = 0, -1, `0x5555555555555555`, `0x2aaa2aaa2aaa2aaa`. It writes
  pmc0 = P | 1, pmc1 to 3 and 5 to 12 = P, pmc4 and pmc13 to 15 their own values, pmd0 to 17 = P, then reads back. Expected pmc:
  pmc0 = (P & `0xf1`) | 1; pmc1 to 3 = 0; pmc4 = value & `0xfffff7f`; pmc5 to 7 = P & `0xf7fff7f`; pmc8 = P & `0xffffffff3fffffff`; pmc9 = P &
  `0xffffffff3ffffffc`; pmc10 = P; pmc11 = P & `0x3ffffff`; pmc12 = P & `0xffcf`; pmc13 to 15 as written. Expected pmd: pmd0 = P; pmd1 & `0x1fff` =
  P & `0x1fff`; pmd2 = P; pmd3 = P & `0xffff`; pmd4 to 7 = P & `0x7fffffffffff` with bits 63:47 copying bit 46 (bit 47 is not stored as written); pmd8 to 15 and pmd17 = P; pmd16 = P &
  `0xfffffffff` (36 bits). A pmc mismatch returns -2, a pmd mismatch -3 (the unconditional `mov r8=-3` at `0xffefe0cc` is this,
  not the TEST_PROC status). The group then repeats a write and read-back with small distinct values (`0xffefd670` to `0xffefda90`); nothing counts. See the review below.
- *Group 10, sub-test 1.* Writes msr[1560] = `0xf1e2`, sets msr[1640] bit 57 and msr[1504] bits 48 and 54, `psr.mc` = 1. For 16 patterns (0, `0x5555...`,
  `0xaaaa...`, -1, four each) and 14 single-bit flips it writes a cache array entry for the line at test buffer + `0xe000` through msr[1544],
  msr[1546] and the reserved M-word (helpers `0xffe8f100` and `0xffe8f9e0` build the command and the check bits), loads the line, ORs
  msr[1505] to msr[1508], masks with `0xf80001` and requires `0x100001` (`0xfff0105c`), then clears them. The model reads 0 there. The
  reserved word is a no-op in the model and the four registers never latch, so the first iteration fails. Which register carries which bit is
  **unknown**; only the OR is tested.

**Ranking for the model (inferred).** (1) Group 10 sub-test 1: needs cache-array write, a detected single-bit mismatch and the error-log
registers; it cannot pass with the reserved word as a no-op. (2) Group 8: the PMU register file must have the Itanium 2 implemented-bit
masks and counter widths above, not a flat array. (3) Group 4: ALAT capacity (32 entries to one address), `ld.c.clr` and aliased-store
invalidation, GR and FR entries kept apart, and the Speculation fault delivery. Log `r15` at the three tests to find the broken block;
log `r8` after each helper call at `0xffefd4dc`, `0xffefd53c`, `0xffefd5cc` and `0xffefd65c` (-2 pmc, -3 pmd) for group 8.

**Unknown.** Groups 3, 5 and 6 beyond their entry and failure constants; which of msr[1505] to msr[1508] holds which error-log bit; the
meaning of msr[1640] bits 61 and 57.

### What SAL passes (established, SAL_B 5.73)

The progress-`0x36` call chain is `0xffaf5c80`, then `0xffb208b0`, then `0xffb20be0`, then the static wrapper `0xffa1d960`, which
passes index 258 and the three arguments as stacked registers. `0xffb208b0` has this one caller; it writes progress `0x36`, looks the CPU
up with `0xffaeb5c0` (a table of 96-byte records keyed by CPUID register 3) and passes `test_address` and `test_info` through from its own
arguments. The third argument (`test_params`) is the qword at record + `0x48`, read by `0xffb208b0`, not anything the caller chooses.
In the model's run `test_address` is `0x3003800000` and `test_info` is `0x800000`: an 8 MiB buffer and `test_phase` 0, so phase two.

Across the 15 records and the terminator, `test_params` is `0x51` (11 records and the terminator) or `0x10000051` (4 records).
Attributes are `0x51`, so the cacheable bit is set. `test_control` is 0, or `0x1000` (bit 12, which PAL always skips anyway). So SAL
skips nothing: the skip word the groups see is only `0x803058081000` (bits 12, 19, 27, 28, 30, 36, 37, 47). Groups 4 (bit 46), 8 (bit 43),
10 (every sub-test but 4) and 11 (every sub-test but 4, 5, 7) all run, as do groups 1, 2, 3, 5, 6, 7 and 9 (group 9 also needs msr[1714] bit 50).

SAL's handling of the result (`0xffb20a40` onward and `0xffaf5da0`): a non-zero `r8` is kept and progress `0xc1` is written. If `r8` is
zero and `te` is set, `r8` becomes the `state` field and `0xc1` is written when that is non-zero, else progress `0x37`. The caller continues
only when `r8` is zero. Anything else writes `r8` into the progress byte, does three SHub stores and spins at `0xffaf5f30` (a bundle that
branches to itself). So `-3`, `state` 1 and `state` 2 are all fatal for this CPU: no warning, no CPU disable. Because every failing group
sets `r41` bits 1:0, a restricted state reaches SAL only together with `-3`. The SDM (vol 2 p. 2:462) reserves status 1 for "completed,
hardware failures occurred"; this PAL returns `-3` instead. The one call found is phase two; phase one runs inside PAL at reset. Whether
the three callers of `0xffaf5c80` can ever pass phase 1 was not traced.

## Processor behaviour the self-tests depend on

What the Intel manuals say about the checks and the fault that these groups rely on. Each fact cites its document, section and printed
page, and the Library file under `cpu/itanium/`.

*Established.* A failing `chk.s`, `chk.a` or `fchkf` either branches to its target or takes a Speculative Operation fault, and the
manual leaves the choice to the implementation. `check_branch_implemented(check_type)` returns TRUE or FALSE for each check type, and
the result "may depend on other implementation-dependent parameters". SDM rev 2.3 vol 3 (document 323207, `cpu/itanium/itanium-sdm-rev2.3-vol3-323207.pdf`):
the `chk` description and Operation at pp. 3:35 to 3:36, Table 3-1 at p. 3:282, and the `fchkf` Operation at p. 3:63.

*Established.* On Itanium 2, hardware "will usually" resteer a failing `chk.a`, `chk.s` or `fchkf` without the OS, and only when
psr.ic = 1, psr.it = 1, psr.ss = 0 and psr.tb = 0. Otherwise the processor traps to the OS. Itanium 2 Processor Reference Manual for
Software Development and Optimization (order 251110-003, `cpu/itanium/itanium2-processor-reference-manual-251110-003.pdf`): section 2.4.1,
p. 18, with the same list again in section 2.4.3, p. 20.

*Inferred.* PAL code that runs with translation off (psr.it = 0) does not get the hardware resteer. A failing check in PAL therefore
faults rather than branches. The manual's trap goes to an OS, and PAL has none, so the handler that runs is the one at the Speculation
vector below. This follows from the two rules above; no manual states it for PAL.

*Established.* The Speculation vector, 0x5700 (SDM rev 2.3 vol 2, document 245318, `cpu/itanium/itanium-sdm-rev2.3-vol2-245318.pdf`,
section 8.1, pp. 2:198 to 2:199):

- Cause: a `chk.a`, `chk.s` or `fchkf` needs to branch to recovery code and the branch is not implemented.
- IIM holds the check's imm21, zero-extended (the vol 3 `chk` Operation calls `zero_ext(imm21, 21)`).
- ISR.code{3:0} is 0 for `chk.a` on a GR, 1 for `chk.s` on a GR, 2 for `chk.a` on an FR, 3 for `chk.s` on an FR and 4 for `fchkf`.
- The only defined ISR fields are code, ei and ni. The rest of ISR is 0.
- The handler reads the predicates, IIM, IIP, IPSR and ISR into scratch bank 0, copies IIP to IIPA, adds IIM (sign-extended from 21
  bits and shifted left 4) to IIP, and sets IPSR.ri to 0. If neither IPSR.tb nor IPSR.ss is set, it restores the predicates and does
  `rfi`. If IPSR.tb is set, it sets ISR.code's tb bit (and ss if IPSR.ss is set), clears the rest and branches to the taken-branch
  vector 0x5f00. If only IPSR.ss is set, it sets ISR.code's ss bit and branches to the single-step vector 0x6000.

*Established.* ISR.ei (SDM rev 2.3 vol 2 Table 3-7, p. 2:37, and Table 8-2 note a, p. 2:170). For faults and external interrupts ei
equals IPSR.ri, which is 1 for a fault on the L+X slot of an MLX. For traps, ei names the slot of the excepting instruction, and a trap
on the L+X slot sets ei to 2. The Speculation vector is a fault, so its ei is IPSR.ri.

### Floating-point exception faults

*Established.* A Floating-Point Exception fault has four causes: a Software Assist fault; an enabled IEEE Invalid Operation; an enabled
IEEE Zero Divide; and an enabled Denormal/Unnormal Operand trap met by an unnormalized operand. The status flags in the FPSR are not
updated, so only ISR.code says which fault occurred. SDM rev 2.3 vol 1 (document 245317, `cpu/itanium/itanium-sdm-rev2.3-vol1-245317.pdf`),
section 5.4.1.2, p. 1:102.

*Established.* The Denormal/Unnormal fault (ISR.code bit 1, D) is raised only when the D trap is enabled (vol 1, section 5.4.1.2, p. 1:102,
cause 4).

*Established.* The Software Assist fault (ISR.code bit 3, SWA) is implementation-defined. Nothing requires it to be signalled, and no mode
forces it. If no input is a NaTVal, an implementation may signal it at any time during the operation. Most implementations use it only in
difficult cases such as operations consuming denormal numbers (vol 1, section 5.4.1.2, p. 1:102).

*Established.* Priority in Figure 5-11 (vol 1, p. 1:103): the NaTVal operand check first, then the unsupported and other invalid operand
checks, the SNaN and QNaN checks, zero divide, the limits check that raises SWA (frcpa, frsqrta), and last the UnNormal operand check, which
raises D only when the D trap is enabled. Otherwise the operation runs with FLAGS.d set.

*Established.* ISR.code for vector 0x5c00 (SDM rev 2.3 vol 2, document 245318, `cpu/itanium/itanium-sdm-rev2.3-vol2-245318.pdf`, "Floating-point
Fault vector (0x5c00)", p. 2:203): bit 0 is V, bit 1 D, bit 2 Z and bit 3 SWA, for Normal and Parallel FP-HI. Bits 4 to 7 are the same four for
Parallel FP-LO. IIM is not among the parameters the vector defines (IIP, IPSR, IIPA, IFS, ISR, and IIB0 and IIB1 if implemented). ISR.ei is
IPSR.ri for a fault (Table 3-7, vol 2, p. 2:37), so it names the faulting slot.

*Established.* famax (SDM rev 2.3 vol 3, document 323207, `cpu/itanium/itanium-sdm-rev2.3-vol3-323207.pdf`, famax instruction, p. 3:57) lists
Invalid Operation (V), Denormal/Unnormal Operand (D) and the Software Assist fault (SWA) as its floating-point exceptions.

*Software expectation, not established.* On Madison, famax on an unnormal operand raises SWA, not D. No public Itanium 2 document states
this. The evidence is the PAL_B 5.73 self-test table, entry 9 (`0xffee2b70`), which expects the SWA path for `famax` at `0xffee4490`.

## 7. Group 10 error-injection sub-tests and group 11

Read in Ghidra on the same image (every bundle of the 6 MiB image dumped; the helpers and sub-tests read in full). Nothing was run.
This corrects section 6: the helper at `0xffe8f9e0` writes the tag array, not data check bits, and r47 in the sub-tests is not a
pointer (the `r47` that loads halfwords inside the helpers is the helper's own local).

### The array command interface (established)

Every cache-array access writes `msr[1544]` (index), `msr[1546]` (command) and, for a write, the payload registers `msr[1600..1627]`,
then `srlz.d` and the reserved M-word `0x108000000` as the trigger. The order of those writes is not fixed: the data write
(`0xffe8f530`), the tag write (`0xffe8fb70`) and the check-bit clear (`0xffe8f650`) put the payload before or in the same issue group as
the command, so only the trigger can start the access. A read trigger fills the payload registers, which are then read back.

- `msr[1544]` index: bits 7:0 = address bits 14:7, bits 10:8 = address bits 17:15 (the "way" of the sub-tests). The read helpers (`0xffe8ee80` at
  `0xffe8effc`, the tag read `0xffe8f890` at `0xffe8f966`) write the way at bits 15:13 as well.
- `msr[1546]` command: bit 63 = 1; bits 60:58 = operation, 2 for the read command and 3 for the write commands (inferred: read and
  write); bits 57:53 = array number; bit 43 = `((cfg & 3) * 3 >> 1) & 1`; bits 41:29 = a configuration-dependent field. `cfg` is
  `msr[1559]` bits 26:22. Both fields come from a halfword table, one row of 32 halfwords per array: halfword 0 is the array number and
  halfword `cfg - 7` is the field. Rows 8, 9 and 10 give array 8 (data, field 0xe3 at `cfg` 16), array 10 (tag, field 0) and array 9
  (check bits, field 0xe0 at `cfg` 16). The command's bit 43 and the field are built at run time from `cfg`; the prologue's "array 10
  clear" word `0x8940000000000000` is a literal that is byte-identical to the tag read command at `cfg` 16 (op 2, array 10, field 0), so it is
  distinguished only by the msr[1640] bit 54 bracket and index 0: do not model it as an unconditional clear (what bit 54 changes is unknown). The observed words are `0x8900001c60000000` (read array 8), `0x8d00001c60000000` (write array 8),
  `0x8d20001c00000000` (write array 9) and `0x8d40000000000000` (write array 10), all at `cfg` 16.
- `msr[1600..1627]`: sixteen payload registers, `0x640 + 8*(i>>2) + (i&3)` for dword i of the 128-byte line. A tag write puts the word
  in `msr[0x640]` only. A tag read comes back in `msr[1545]`.
- Tag write word (helper `0xffe8f9e0`): bits 34:0 = address bits 49:15 passed through three 12-bit halfword lookups (the table at `0xffe9b910`, reached
  ip-relative from `0xffe8fad6`, is exactly 12-bit bit reversal, so the field is the 35-bit bit reversal of the tag; established, all 4096 entries
  read). The tag read is not reversed, bit 35 = valid, 39:36 = parity, 43:40 = state, 51:44 = an 8-bit field (replacement
  state, inferred). Tag read word (`msr[1545]`, helper `0xffe8f890`): bits 53:19 tag, 8:5 parity, 3:0 state, 16:9 the 8-bit field.
- Data helper `0xffe8f100` (index, way, dword, data, mask): with mask 0 it only does read array 8 (write command 2), set one payload
  register, write array 8. With a mask it first zeroes all sixteen payload registers, writes array 9 with the mask word
  `((mask & 0x7f) << 13) | ((mask >> 7) << 45)` in `msr[0x640 + (i&3)]` and triggers (this happens before `msr[1544]` is written for
  that call, so it uses the previous call's index, and the payload register is block 0 whatever the dword), then does the data write, then zeroes the payload registers and writes array 9 again. The mask is therefore 14 bits.

### The data check code (established for the code, inferred for the hardware)

- Array 9 holds 14 check bits per dword: bits 19:13 for the low 32-bit half and bits 51:45 for the high half (read-back helper
  `0xffe8ee80`). Mask bit k flips check bit k of that field (inferred: the code never says "flip").
- Group 10 sub-test 3 stores data through the cache and requires the array to hold, for each 32-bit half, the seven parities of the half
  ANDed with `0x0003c3ff`, `0x12c87c0f`, `0x25549c71`, `0x49a42592`, `0x8e392aa4`, `0xf03e1348` and `0xffc3c000`. The patterns it
  uses have equal halves, so one code serves both. Every data bit is in exactly three of the seven rows and the 32 columns are distinct, so
  this is a (39,32) odd-weight-column SEC-DED code: any single flip (data or check) has an odd-weight syndrome and is correctable, any
  double flip has an even-weight syndrome and is detect-only (inferred from the matrix, not read from a manual).
- The tag parity is four bits: the popcount parity of tag bits [7:0] with the valid bit, [16:8], [25:17] and [34:26].

### Group 10 sub-tests

All use the same prologue (msr[1560] = `0xf1e2`, msr[1640] bit 57, msr[1504] bits 48 and 54, a cache flush, array 10 clear command
`0x8940000000000000` at index 0, msr[1552] bit 4 cleared then set and bit 2 polled with no timeout), `psr.mc` = 1, `cr.cmcv` and
`cr.tpr` = `0x10000` (masked). No sub-test takes or waits for an interruption; errors are read from the log registers. The flag is
test_control bit n-1; when it is set only the first pass runs, otherwise a second pass adds an `ld8.nta` from the buffer base before the
same `ld8`.

| n | Entry | Skip bit | Kind | Pass condition | Failure `r9` |
|---|---|---|---|---|---|
| 1 | `0xfff00b30` | 16 | check-bit injection, 14 single flips x 16 dwords | `OR(msr[1505..1508]) & 0xf80001 == 0x100001`, registers cleared after each | `0x80000000001` |
| 2 | `0xfff02b00` | 17 | adjacent pairs, `3<<k` (k 0..5, second pass 3, 12, 48) | same OR `== 0x080001` | `0x100000000001` |
| 3 | `0xfff015b0` | 18 | stores through the cache, 8 ways x 16 dwords x 10 patterns, read back by command | data and 14 check bits equal the code above; no log | `0x200000000001` |
| 4 | `0xfff03590` | 19 (always skipped) | tag parity flip in the same way, state 0xd | `OR(msr[1509..1512]) & 0x3c02d == 0x8025` | `0x400000000001` |
| 5 | `0xfff01cf0` | 20 | tag array write and read (4 patterns), then data write and cache load | tag, parity and data read back; no log | `0x800000000001` |
| 6 | `0xfff03e80` | 21 | tag parity flip in the next way of the same set | `OR(msr[1509..1512]) & 0x3c02d == 0x4005` | `0x1000000000001` |
| 7 | `0xfff02560` | 22 | tag array write and read, 6 patterns intended (see the loop note), valid 0 and 1 | tag and parity read back; no log | `0x2000000000001` |
| 8 | `0xfff04730` | 23 | store then read data, check bits, tag, state and the 8-bit field | data and check bits as the code; tag, parity as written; state 7; field 0, 1, 3, 7, .. `0x7f` | `0x4000000000001` |

(Skip bit for sub-test n is 15+n; a sub-test's failure sets msr[1640] bit 62 as section 6 says.) All eight run in order and the first
failure stops the group.

Sub-tests 4, 6 and 7 compare with `cmp.lt p2,p1=r47,8` (or r42 against `0x80`) and branch back on p1, which is the opposite of the loop
test in sub-tests 1, 2, 3 and 5. As decoded, their inner r47 or r42 loop runs only its first value; only the outer way or valid loop
steps. Sub-test 6 therefore only exercises parity bit 0 (inferred from the decode, not run). Sub-test 4 likewise runs r47 = 1 only, for ways 0 to 7.
Sub-test 7 runs r42 = 2 (pattern 1, valid 0), then the reset sets r42 = 1, which selects no pattern, so valid 1 reuses pattern 1's stale values.

Expected log for the model, from the injected mask (sub-tests 1 and 2):

| Injected | Log OR `& 0xf80001` | Meaning (inferred) |
|---|---|---|
| none | 0 | no error |
| one check bit in a half (sub-test 1) | `0x100001` | bit 20 corrected, bit 0 valid |
| two adjacent check bits in the low half (sub-test 2) | `0x080001` | bit 19 uncorrectable, bit 0 valid |
| tag parity in a neighbour way (sub-test 6) | `msr[1509..1512]` OR `& 0x3c02d == 0x4005` | bits 14, 2, 0 |
| tag parity in the accessed way (sub-test 4, skipped) | same mask `== 0x8025` | bits 15, 5, 2, 0 |

Bits 21 to 23 are masked and no test sets them. Which of the four registers carries which bit is **unknown**; only the OR is tested.
The tests do not inject a data-bit flip, so what the log says for one is unknown (a single flip would be corrected by the code above).

### Group 11 (`0xfff04ff0`), when group 10 passed and msr[1640] bit 62 is clear

A second cache array: 4-dword (256-bit) lines, 10 check bits per line for data, a seven-bit ECC over 35 bits (32 tag bits and 3
state bits) for the tags. Its log is `msr[1558]`, its way mask is `msr[1536]` bits 59:48 (12 bits, two ways per bit, up to 24 ways;
zero is accepted), and it is configured through the same `msr[1559]` field. Each group 11 sub-test first sets `msr[1559]` bit 1, clears `msr[1558]` bit 4 and sets bit 30, and restores all three (and `msr[1536]`) afterwards; its prologue `0xfff0575c` also calls `0xffe89f20`. It uses helpers `0xffe93c50`, `0xffe938b0`, `0xffe93fc0`,
`0xffe93620`, `0xffe93e50`, `0xffe932a0`, `0xffe92ff0`, `0xffe8fbc0` and `0xffe94130`, which were not read beyond their arguments.

The prologue does the same cache clear, clears and sets msr[1552] bit 4 and polls bit 2 with no timeout (`0xfff051c0`), then calls
sub-test n if test_control bit 23+n is clear, with test_control bit 7+n as its flag. Failure `r9` is bit 50+n and bit 0 (`0x8000000000001` for n = 1).
Bit 62 already set returns `r8 = -1` and `0x7f8000000000001` (section 6).

| n | Entry | Skip bit | Kind | Pass condition |
|---|---|---|---|---|
| 1 | `0xfff056a0` | 24 | data check injection, mask 1 to `0x200` (10 values) x the 4 dwords of the line (all-zero data), then `ld8` | `msr[1558] & 0x1c1f2000 == 0x080a2000`, then msr[1558] cleared |
| 2 | `0xfff06590` | 25 | pairs `3<<k`, k 0..8 | `msr[1558] & 0x1c1f2000 == 0x080b2000` |
| 3 | `0xfff07470` | 26 | data array write and read, 10 patterns, 256-bit code | four dwords and 10 check bits read back |
| 4 | `0xfff081a0` | 27 (always skipped) | tag ECC single flips | `msr[1558] & 0xf01fff6000 == 0x7008082000` |
| 5 | `0xfff08b30` | 28 (always skipped) | tag ECC pairs `3<<k` | same compare |
| 6 | `0xfff094a0` | 29 | tag array write and read, 10 patterns, state, 7-bit ECC | tag, ECC and state read back; no log |
| 7 | `0xfff09cf0` | 30 (always skipped) | array test, helpers `0xffe943a0` and `0xffe94270` | read back; no log |
| 8 | `0xfff0a650` | 31 | data, tag, ECC and state over up to 24 ways | read back, tag state 3; no log |

Sub-tests 1 and 2 differ only in bit 16 of the expected log (clear for one flip, set for two). They load the line with the same pass
structure as group 10 (a second pass adds the `ld8.nta`). The only polls are the msr[1552] bit 2 poll after each cache clear.

### Unknown

- The meaning of each bit of `msr[1505..1508]`, `msr[1509..1512]` and `msr[1558]`, and which register holds which.
- Whether the mask flips the check bits stored (array 9) or is XORed during the data write; the code only shows the order of commands.
- What the group 11 helpers do inside; the group 11 mask positions and the 256-bit code masks were not decoded further.
- The effect of the unconnected 8-bit field and the replacement-state encoding in the tag word.

## Unknown

- Which group and sub-test fails in the model (route: log `r8` and the call site at each `0xffebf000` call, or read the three remaining sub-tests' compares).
- Meaning of msr[1640] bit 63 and of the FIT entry reserved bit 25 that selects between the two stops.
- Whether a debugger or L1 reads `r30` or `r7` after the stop (nothing in the PROM does).
- Why the entry at `PAL_B + 0x100a0` is the target the generic PAL_A hand-off uses for the msr[1779] bit 15 case.
- A different hang in the same image: the msr[1730] nibble loops (for example PAL_B 5.73 `0xffe9ddb0`) never exit if the nibble does not step; see [msr 1728 and 1730 strobe loops](pal-msrs.md#msr-1728-and-1730-strobe-loops).

## Review

Independent review of `9a454ef` (this page), examined at that revision. The reviewer did not write the page. Read in the retools
`ia64-linux-gnu-objdump` listing of the whole image (bundle-level, flow followed with a small scan script) and byte reads of the record
and FIT tables. The Ghidra decompile of `0xffeec2d0` and `0xffee0b20` was tried and came out as constant-return stubs with
"unreachable block" warnings, so Ghidra was not used as the listing; no instruction-by-instruction comparison against it was made.

**Confirmed.**
- SAL_A reason 3: the only write to `r37` in code reachable from `0xffc4e030` is `or r37=r8,r37` at `0xffc4e34c`. `r8` is a 64-bit load at
  record + `0x40`, shifted right 16; all 15 records and the terminator hold `0x51` there, so the OR adds 0 and bit 42 stays clear. PAL sets
  `r37 = 0xe030ffffffff` at `0xffed7a78` and nothing between that and the SAL_A call writes it.
- PAL_B: `r13` is rewritten at `0xffed8878` and `0xffed8892` (link-to-run delta) and then only by `mov r13=r37` at `0xffed88ee`, on the
  msr[0] bit 17 clear arm; nothing writes `r13` from there to `0xffee03a0`. The OR with `0xe030ffff8000` at `0xffed885e` comes first.
- Table: the loop, `r6`, `r7 = 0xffee06f0`, the zero terminator, and the per-entry `tbit` on `r13` (skip when set). Entry 3 uses bit 42.
- Failure route: `r8 < 0` with `r9[1:0] = 3` reaches `0xffebf2a0` (`0xffebf10c`), which builds `0xffe7f000` from `ip`. The three words read from the
  image (`0xffe880b0`, `0xffe880c0`, `0xffe880d0`) are as stated, and `0xffe880c0 = 0` skips the `p12` arm.
- `0xffe7f000`: the FIT pointer, `tbit.z p0,p6=r2,25` on the qword `0x000107790000a8dc` (bit 25 clear), the 0xcccc spin, no store. All
  five entry sites; the four non-computed ones are reached as listed.
- Entries 1 to 3, the result routine and the sub-test callees contain no reserved M word, no reserved B word and no `msr[`
  access on the passing path.
- Sub-test 1 stages 2 and 6 re-derived by hand; they pass on correct semantics.

**Changed.**
- Thirteen table entries, not twelve; `0xffee1ee0` (bit 39) is its own entry, not part of `0xffee1e20`; full bit map added.
- The two `dep` at `0xffe7f016` and `0xffe7f01c` have length 64, not 1; the stated `psr` value rewritten as inferred.
- Sub-test 1: 55 adds per pass, not 48; stages, predicate masks, `rrb.pr` handling and the single compare that decides `r8` written out.
- Sub-tests 2 to 4 filled in; `ar.itc` must advance (sub-test 3); entry 2 is a `break` handler test and entry 8 a fault test, neither
  mentioned before. The statement that no entry touches an MSR now says "on the passing path" and names the two exceptions.
- The terminator record address (`0xffc515a0`) and the sub-id condition for reaching the SAL_A `or`.

**Not checked.**
- Entries 1 and 8 beyond a skim; entries 4 to 7 and 9 for what they test (only scanned for MSR, reserved and undecodable words).
- The SAL_A sub-id branch to `0xffc4e6f0`, and PAL's source for `r20` bits 15:8 (msr[1643] when no `p16`-`p22`).
- The GR35 field positions in boot-sequence.md and the GR37 field layout (the figures are checked in the sentence below). `ia` = bit 17 agrees with the PAL code (msr[1640] bit 59 is set from the `br.ia`
  return and lands in `r35` bit 17). The rest of the GR35 decode, and the layout `test_control` 46:0, `cs` 47, reserved 63:48, 0 = run,
  1 = skip are consistent with the code (`0xe030ffff8000` sets bit 47, and a set bit skips a group).
- The result routine's second argument (`ar.k7` upper half) and the real-hardware meaning of any value; no run was made.

Checked against the SDM PDF: Figure 11-10 (SDM rev 2.3 vol 2, document 245318, section 11.2.3, p. 2:295) puts test_control in bits 46:0, cs in bit 47 and reserved in bits 63:48, and the text's rule that a 0 in an implemented test_control bit runs the test and a 1 skips it matches the layout listed above as unconfirmed, so the GR37 decode was right and needed no change.

### Review of the PAL_TEST_PROC section

Independent review of `286a050`, section 6 above, by a reader who did not write it. The section was written from an objdump listing
only, so before this review none of it had been re-read in Ghidra. This pass re-read it in Ghidra with the repository's IA-64
processor, `--sn2-prom --no-analysis`, on `shub1snprom.bin` 10.54: instruction listings of the address ranges named below (from a
throwaway listing script run in the Ghidra image) and the stock decompile export as a cross-check. The IA-64 objdump was not
available on the review host, so it was not used. SDM figures were checked in the rev 2.3 vol 2 PDF, and the PMU masks against
Itanium 2 Processor Reference Manual 251110-003, chapter 10.

**Confirmed (instruction-level in Ghidra, grade of the section unchanged).**
- Entry: argument checks and the `-2` exits, `r34` bits 55:0 and 63:56, `r35` bit 0 as the cacheability test, `test_control` as `r35` >> 16
  (SDM vol 2 Fig 11-45 puts attributes in 7:0 and `test_control` in 63:16), the two always-skipped masks `0x803058081000` (phase 0) and
  `0xe030ffff8000` (phase 1), and the exit at `0xffeaaa40` that zeroes `r10` and `r11` and does not touch `r8` or `r9`. A phase above 1
  returns `r8` = 0 and `r9` = 0 (added). The link-address table entry `0xfff32190` for this handler is present at `0xffe9e5f0`; which
  predicate selects it for index 258 was not traced.
- The 11-entry group table at `0xffefc4d0` (the page's `0xffefc280` is the dispatch loop that reads it), with the groups in the order
  listed; `r41` starts at 4; msr[1640] bits 63 and 57 set at `0xffefc140`; `r9` ORed into `r41` after each call.
- Result routine: `r9` bits 62:58 from msr[1640]; all three tests that set `ia`, `fp` and `vm`; `vm` also from `r9` bits 33 and 39; `mf` from bits 33 to
  37; `state` 1 from msr bits 61 or 62, `state` 2 winning; the fall-through to msr[1640] bits 1:0; bits 63 and 57 cleared and nothing
  else (mask `0x7dff...`), so bit 62 is not cleared by the routine; predicated `mov r8=-3` at `0xffefc48c` on `r41` bits 1:0.
  Fig 11-9 (p. 2:293): `state` 1:0, `te` 2, `vm` 16, `ia` 17, `fp` 18, `mf` 19, `test_status` 63:32.
- The decode of `0x43f8081400080006` bit by bit, including the group 11 constant losing bit 58 to the msr copy.
- Group 4: skip bit 46, the three expected miss counts (3, 0, 32 at `0xffef93b6`, `0xffef95d6`, `0xffef96f6`), the final two checks with
  `r14` = 16, the failure constant, and handler arms. Every `chk.a` sits in slot 0 or 1, so `ri` + 1 stays valid.
- Group 8: skip bit 43; the four patterns; helper write order and every readback mask listed; `-2` for pmc and `-3` for pmd.
- Group 10: bit-62 test and constant, skip bits 16 to 23, per-sub-test constants, sub-test 1's msr[1560] = `0xf1e2`, the msr[1640] bit 57
  and msr[1504] bits 48 and 54 writes, `psr.mc`, the 16 patterns by 14 bit positions, and the `& 0xf80001 == 0x100001` test on the OR of
  msr[1505] to msr[1508] at `0xfff0105c`. Group 11: the same shape, skip bits 24 to 31, constants as corrected above.
- The failure latch: groups 10 and 11 set msr[1640] bit 62 on a failing sub-test (`0xfff009dc`, `0xfff0553c`).

**Changed (corrected in place above).**
- Group 2 has two skip bits, 41 and 40. Bit 39 is a flag passed to the second sub-test. The msr[1640] bit 60 test is a latch: the group
  fails at once when it is set and sets it on any failure; the result routine reads it as `fp`.
- Group 5 was "not read": skip bit 33, failure constant `0x4000000002`, and it preloads `r8` and `r9` with -1 when it runs.
- Group 11's skip bits are 24 to 31 (not "24 and up"), and its failure constants follow group 10's pattern.
- The group 8 counting check is not a counting check. It writes distinct small values (pmc 2 to 16, pmd 3 to 17, pmd13 to 15 = 35 to 33,
  pmc9 = 40, pmc0 = 33, pmd0 = 34), freezes via pmc0 and reads back with masks. Values 25, 23 and 21 for pmd1 to pmd3 are the values
  just written to those pmds, read back under a 7-bit mask. They do not come from read-only status registers. The pmc1 to pmc3 reads
  must be zero, as written values 24, 22 and 20 are ignored. pmc0 expects `0x21` after clearing bits 3:1. The pmd4 to 7 expectation copies
  bit 46 into bits 63:47.
- The "Unknown" test_control item is answered (section above).

**Added.**
- Groups 4, 10 and 11 each bracket their work with msr[1552] bit 4 set and a poll of bit 2 until it reads 1, with no timeout; a model
  that never returns bit 2 hangs there. The msr[1544] = 0, msr[1546] and reserved-word sequence with msr[1640] bit 54 set around it
  appears in groups 4, 10 and 11 prologues and after group 10's loop, so it is a general step, not only the cache-array write.
- msr[1640] bit roles seen in this code: 63 and 57 bracket the whole call; 62 failure latch of groups 10 and 11; 60 latch of group 2 (and
  `fp`); 54 brackets the msr[1544]/msr[1546] sequence; 59 and 58 are only read by the result routine (page text unchanged).

**251110 against the group 8 masks.** Agree: pmc0 populated bits 7:4 and 0 (mask `0xf1`); pmc1 to pmc3 read zero; pmc4 to pmc7 bits 27:0
without the reserved bit 7, 63:28 reading zero, bit 23 only in pmc4; pmc9 bits 1:0 ignored (`0x...ffc` mask); pmc11 bits 25:0 (`0x3ffffff`);
pmc12 without bits 5:4 (`0xffcf` exactly); pmd1 12:0; pmd16 35:0 (36 bits); pmd17, pmd2 and pmd8 to 15 all 64 bits.
Agree only through the patterns: pmc10 is expected to read back all 64 bits, while the manual says bits 31:16 and 47:32 return the value
of bits 15:0; every pattern repeats every 16 bits, so a model that implements the mirror passes. pmd3 reads back 16 bits; the manual's figure
is ambiguous on its width.
Disagree: (1) pmd4 to pmd7. The manual shows a 48-bit counter with a separate overflow bit 47 and bits 63:48 copying bit 47. The PAL test
expects bits 63:47 to copy bit 46, as for a 47-bit counter with architectural sign extension. The PAL expectation is a software
expectation from shipped firmware and the manual disagrees with it; the model should follow the PAL until hardware says otherwise.
(2) pmc8 and pmc9 bit 32: the manual lists 32:30 as reserved, the PAL expects bit 32 to read back as written and bits 31:30 to read zero.
(3) pmc13 to pmc15: the PAL writes values with bits set in fields the manual calls reserved (pmc15 31:4, pmc14 63:14) and requires them
to read back as written; for pmc13 the manual says the register must hold `0x2078fefefefe`, and the PAL writes other values.

**Not checked.**
- The mode-switch helpers (`0xffe96bd0`, `0xffe88970`, `0xffe89040` and the like) and the group 11 helpers (section 7);
  groups 1, 3, 6, 7 and 9 beyond their skip bit and failure constant.
- The claim that nothing in the image clears msr[1640] bit 62 (only the result routine was read, and it does not), and the inferred
  bit-56 behaviour and final msr[1640] value.
- That the exit stub `0xffe9f260` never touches `r8` to `r11`; what `0xffe7ec10` does (it reads ISR, IIP and IPSR first).
- SAL: the callers of `0xffaf5c80` and what the SHub stores before the spin mean.

**Regrade.** Section 6 stood as objdump-only until this pass. The established grades above are now backed by Ghidra for the items
under Confirmed. The group 2, group 5, group 11 skip-bit and group 8 counting-check statements were wrong or missing and are fixed.

### Review of the group 10 and 11 decode

Independent review of `ba90ac6` (section 7), by a reader who did not write it. Re-read in Ghidra with the repository's IA-64 processor,
`--sn2-prom --no-analysis`, on `shub1snprom.bin` 10.54: instruction listings of `0xfff00000-0xfff0b000`, the array helpers
`0xffe8ee00-0xffe8ff00` and the dispatcher `0xffefc100-0xffefc500`. The compare and branch encodings in item 5 were also decoded by hand from
the image bytes, independent of Ghidra. The IA-64 objdump was not available. Nothing was run.

**Confirmed (established unless noted).**
- Command word: bit 63, op 60:58, array 57:53, bit 43 `((cfg&3)*3>>1)&1`, field 41:29 from the halfword table at `0xffe9d910` (64-byte
  rows, halfword 0 the array, halfword `cfg-7` the field; rows 8, 9, 10 as stated, `cfg` 16 gives `0xe3`, 0, `0xe0`); the four observed words
  re-derived. Index formula (callers pass address bits 14:7 and 17:15). Payload registers `0x640 + 8*(i>>2) + (i&3)`.
  Op 2 = read and op 3 = write stay inferred.
- Array 9 placement `((mask&0x7f)<<13)|((mask>>7)<<45)`; read-back `0xffe8f0cc` and `0xffe8f0d6` give low half in bits 6:0, high half in 13:7.
- Seven masks (the constants load at `0xfff01956-0xfff019b6`, the ANDs run at `0xfff019c0-0xfff01a5c`). Recomputed: every data bit is in exactly
  three rows, the 32 columns are distinct, so the code is odd-weight-column SEC-DED (inferred). "Copied to both halves" is right (`0xfff01a66`
  copies bits 6:0 to 13:7) and holds because all ten patterns have equal halves.
- Expected-log constants and masks, mask walks (sub-test 1: 1 to `0x2000`; sub-test 2: 3, 6, ..., `0x60`, then second pass 3, 12, 48; group 11
  sub-test 1: 1 to `0x200`; sub-test 2: `3<<k`, k 0..8), msr numbers (1505 to 1508, 1509 to 1512, 1558), entries, skip bits 16 to 23 and 24 to 31,
  flag bits 0 to 7 and 8 to 15, and failure constants. Group 11 failure constants were mis-stated and are corrected above.
- Skip word `0x803058081000` = bits 12, 19, 27, 28, 30, 36, 37, 47: bits 19, 27, 28 and 30 are the always-skipped sub-tests. Bit 12 is group 11
  sub-test 5's flag (moot, it is skipped). Flags 0 to 7 are clear, so group 10 runs both passes.
- msr[1552] bit 4 cleared, flush, then set and bit 2 polled: 18 sites (the two group drivers `0xfff005f0`, `0xfff051c0` and the 16 sub-tests), each a
  three-instruction self-loop with no counter, no timeout and no other exit.
- Group 11: way mask msr[1536] bits 59:48 (the PAL scans for clear bits, two ways per bit, four ways kept); ten check bits per 256-bit
  line (ten mask values; sub-test 3 builds ten parities over four dwords and compares `r14 & 0x3ff`); tag ECC is seven parities over
  `(tag32<<3)|state` = 35 bits with state 3.

**Loop quirk (item 5): confirmed.** Sub-tests 4, 6 and 7 issue `cmp.lt p2,p1=r47,8` (or `r42,0x80`) and branch on `p1`, which is true only when the value
is 8 or more (0x80 for r42). Raw bytes: A6 op `0xc`, first predicate field 2, second field 1, `r2` = r47, `r3` = the limit; branch B1 `qp` 1 to the
loop top. No `br.ctop`, `br.cloop`, `br.wtop`, `rrb` or rotating register (`alloc` sor 0) is in these functions; `p16` is a plain predicate there.
Executed: sub-tests 4 and 6 run r47 = 1 once for each way 0 to 7 (eight passes). Sub-test 7 runs r42 = 2 with valid 0, then r42 = 1, which
selects no pattern predicate, so valid 1 runs with pattern 1's stale r47, r43 and r44. Under the SAL skip word sub-tests 6 and 7 run, 4 does not.

**Changed.**
- Tag write word is the 35-bit bit reversal of the tag (table at `0xffe9b910`); the page said only "three lookups".
- The "array 10 clear" word equals the tag read command; payload-before-command order exists; array 9 mask write uses the previous index; the tag
  read helper also writes the way at 15:13; failure constants of group 11; group 11 sub-tests 1 and 2 use all-zero data over four dwords, not four
  patterns; group 11 sub-tests write msr[1559] bit 1 and msr[1558] bits 4 and 30; sub-test 7's second pass.

**Not checked.** Meaning of msr bits and what the masks do in hardware; the group 11 helpers' internals and the 256-bit data-code masks (read as 40
constants at `0xfff078c6-0xfff07efc`, not tabulated); sub-tests 5 and 8 of group 10 beyond their entries; that `psr.mc` and the masked
`cmcv` and `tpr` stop every interruption; what `0xffe89f20`, `0xffe96bd0`, `0xffe88970` do.
