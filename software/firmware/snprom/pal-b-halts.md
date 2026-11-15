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

- `0xffe7f000` to `0xffe7f03c`: `r28` = `psr` with bit 35 set and bits 13 and 14 cleared (`dep` at `0xffe7f00c`, `0xffe7f016`,
  `0xffe7f01c`), then `br.few 0xffe96bd0` with `b0` = `0xffe7f040`. `0xffe96bd0` is the PAL's return-to-physical-mode helper: `rsm 0x6000`,
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

**The table** (established; entries are link addresses minus `0x88000`, resolved from the twelve qwords at `0xffee06f0`):
`0xffee7c60`, `0xffee1e20`, `0xffeec200`, `0xffee8960`, `0xffee1010`, `0xffee1ee0`, `0xffee26f0`, `0xffeeb7c0`, `0xffee2b70`, `0xffef2990`,
`0xffef2e80`, `0xffef2c40`, `0xffef3290`, then a zero qword. The loop (`0xffee03a0` to `0xffee03dc`) loads each offset, adds `r6`, loads
`b0`, calls it with `r8 = 0`, `r9 = 0` and ORs `r9` into `r12` (the call at `0xffee03c0`). No entry read in this page touches an MSR: the four entries read (`0xffee7c60`, `0xffee1e20`, `0xffeec200`, `0xffee8960`) contain none in
their bodies, and the sub-test routines `0xffee0cc0`, `0xffee0760`, `0xffee2170` that entry 3 calls contain none either (checked by
scanning each body for `msr[`). That agrees with the model seeing no MSR access between the `0xffee0390` write and the spin.

Each entry is a test group guarded by one bit of `r13` (a **set** bit skips the group): `0xffee7c60` bit 44 (`0xffee7cbc`), `0xffee1e20`
bit 43 (`0xffee1e2c`) and bit 39 (`0xffee1eec`), `0xffeec200` bit 42 (`0xffeec20c`), `0xffee8960` bit 41 (`0xffee897c`).
`r13 = 0xe030ffffffff` has bits 47:45, 37:36 and 31:0 set, so groups 44 to 38 (except 37 and 36) and 35:32 run. A group runs
its sub-tests in order and stops at the first that returns `r8 != 0` (`cmp.eq p7,p6=r8,r0`, then `(p6) br 0xffeec280` in group 42).
Then it calls the result routine `0xffebf000` with `r9 = 0` on success and a constant whose low two bits are `3` on failure (group 42:
`0xffeec296`, `r9 = 0x400000003`; group 44: `0xffee7d36`, `0x100000003`; group 43: `0xffee1e56`, `0x200000003`).

**The result routine `0xffebf000`** (not a test; established). `p8 = (r8 < 0)`. On failure (`p8`) it clears the top half of `ar.k7`, sets
bits 31:28 to 1 and ORs in the second argument shifted left 32, then stores that to the doubleword at `cr.iva + 0x100b0` if that word is
non-zero. It reads `cr.iva + 0x100c0` (`r37`) and `cr.iva + 0x100d0` (`r38`). With `cr.iva = 0x80000000ffe78000` those are image addresses
`0xffe880b0` (0 in this image), `0xffe880c0` (0) and `0xffe880d0` (a pointer, `0x80000000fff10000`). Because the word at `0xffe880c0` is zero the
bundle at `0xffebf09c` branches to `0xffebf0f0`, where `p13` stays set when `p8` is set and `r9[1:0] = 3` (`0xffebf096`) and bit 59 of the
zero `r37` is clear (`0xffebf0f6`). `0xffebf10c: (p13) br.cond 0xffebf2a0` then goes to `0xffe7f000`. So with the shipped contents a failed group (`r8 < 0`,
`r9[1:0] = 3`) is fatal and a passed group (`r8 = 0`) returns. This is established for the zero words read from the image; those flash words are not
written by the PAL on this path (the store at `0xffebf086` needs `r36 != 0`).

## 3. What the groups test, and what a healthy processor returns

*Established.* The failing group is not identified by the code; it depends on which instruction the model executes wrongly. The code
tells what each candidate checks. Group 42 (`0xffeec200`, the third entry and the first one the model's trace names):

| Sub-test | Address | Checks |
|---|---|---|
| 1 | `0xffeec2d0` | compare-type forms (`cmp.eq/lt/ltu/ge/gt/le`, `.and`, `.or`, `.or.andcm`) against fixed operands and branch on each predicate; `mov pr=` with masks, readback of `pr` for values `-1`, `0xffffffff`, `0xffff0000ffff`, `0xff00ff00ff00ff`, `0xf0f0...`, `0x3333...`, `0x5555...`, 0 (`pr` bit 0 reads 1); 48 predicated adds over `p9` to `p63` after `mov pr=r0,-2` (all 0) and after `mov pr=r34,-4` (each register 7, except `r43` 6); `br.call` of `0xffeec990`, which decrements `rrb.pr` in the saved `ar.pfs` (wrapping 0 to `0x2f`), and predicated adds over `p16` to `p18`, `p62`, `p63` expecting `4, 8, 0, 1, 2` |
| 2 | `0xffee0cc0` | branch-register moves with patterns (`0x5555555555555555`) |
| 3 | `0xffee0760` | `ar.k0` to `ar.k7` write and read-back |
| 4 | `0xffee2170` | control-register write and read-back (`cr.dcr`, `cr.itm`, `cr.iva`, `cr.pta`, ...) with `rsm 0x6000` and `psr` handling |

Sub-tests 2 to 4 were read to their first instructions only; what each accepts back from the implemented-bit masks is **unknown**
(route: read the compares after each read-back, `0xffee0cc0` to `0xffee1010`, `0xffee0760` to `0xffee0cc0`, `0xffee2170` to `0xffee26f0`).
Sub-test 1 is a pure architectural test: any processor with correct predicate, compare and `rrb.pr` rotation semantics returns `r8 = 0` and `r9 = 0`. That includes
restoring `rrb.pr` from `ar.pfs` on `br.ret`, the thing sub-test 1's last stage exercises (the routine at `0xffeec990` edits
the saved `ar.pfs`).

**What a healthy processor returns.** For the stop not to occur, every group that runs (all of them except those whose `r13` bit is set)
must leave `r8 = 0` at its result call. No MSR, memory or SAL value is read by these groups, so no value can be "supplied": only correct instruction behaviour avoids the stop. The
bit-set skip in `r13` is not available to a model: `r13` is `r37` as returned by SAL_A ORed with `0xe030ffff8000`.

## 4. What SAL_A puts into `r37` (reason 3)

*Established.* At `0xffc4e310` the reason-3 path (`dep.z r3=r20,0,8` equals 3) calls `0xffc4eaa0`, then `0xffc4e330` to `0xffc4e34c`: `r8 = [r8 + 0x40]`,
`shr.u r8=r8,16`, `or r37=r8,r37`, `mov b6=r36`, `br.few b6`. No SHub register, no L1 value, no debug-switch word is read on the way (the
SHub accesses of SAL_A are in the reason-0 path and in the common node set-up before this point, none of which reaches `r37`).
`0xffc4eaa0` searches the table at `0xffc51648` (three triples for PAL pairs 7.31/7.79, 5.37/5.73, 1.27/2.25, terminated by `-1`) and then
the 96-byte record table at `0xffc51000` for the record whose first doubleword equals the full `cpuid[3]` (for the 5.73 pair `0x1f010504`) and whose
version windows contain the pair. The doubleword at record + `0x40` is `0x51` in all 15 records (and in the terminating zero record that follows them, at `0xffc515e0`), so the value ORed into `r37` is **0** in every case:
`r37` comes back as the value PAL handed in, `0xe030ffffffff` (`movl` at `0xffed7a76`), and `r13 = 0xe030ffffffff`. Bit 42 is therefore clear
and group 42 always runs on this PROM, whatever the SHub, L1 or switch state. This answers the "which input sets bit 42" question: none does.

## 5. The question list, graded

1. *Deliberate halt?* Yes (established): a stop with the marker `r7 = 0xcccc`, no report out. The error recorded is in `ar.k7` (bits 31:28 = 1, upper half =
   second argument of the result call) (established); nothing reads it before the stop.
2. *Path.* The indirect call at `0xffee03c0` calls table entries (section 2); no table entry uses msr[1640] after `0xffee0390`. The
   msr[1640] write at `0xffee0390` is not on the decision path (established). The decision is `r8 < 0` with `r9[1:0] = 3` at one of the
   result calls (established); which sub-test fails in the model is **unknown** without a trace of `r8` after each group.
   Meaning of msr[1640] bits 63, 59, 56: bit 56 and 59 as in pal-msrs.md and pal-instructions.md; bit 63 **unknown**.
3. *Model-estimated values on the path.* None: no MSR read, reserved slot, `br.ia` table load or SHub read occurs between `0xffee0390`
   and `0xffe7f100` (established by scanning every body on the path for `msr[` and reserved opcodes). The estimated values the model supplies earlier
   (msr[1212], msr[1226], the `br.ia` return `r1 = 0`) decide only that execution reaches `0xffed75e0` and, via msr[0] bit 17 clear, the table.
   The M-word `0x108000000` appears on the other arm (`0xffe7f1f6`) and in the return path before the table (`0xffed87d6`); the model runs it as a no-op there,
   which is **inferred** harmless for this stop because nothing between it and the table depends on its effect.

## Unknown

- Which group and sub-test fails in the model (route: log `r8` and the call site at each `0xffebf000` call, or read the three remaining sub-tests' compares).
- Meaning of msr[1640] bit 63 and of the FIT entry reserved bit 25 that selects between the two stops.
- Whether a debugger or L1 reads `r30` or `r7` after the stop (nothing in the PROM does).
- Why the entry at `PAL_B + 0x100a0` is the target the generic PAL_A hand-off uses for the msr[1779] bit 15 case.
