# SN2 PROM PAL: model-specific register accesses

A catalogue of every `mov msr[rX]=rY` and `mov rY=msr[rX]` in the PAL code of the SAL 5.04 SHub 1 PROM (the PAL_A and PAL_B components
named in the FIT), with what the code around each site says about the register. The SDM (rev 2.3) defines no such instruction, and
neither the Itanium 2 reference manual 251110 nor the specification update 251141 names any of these registers, so the firmware's own
use is the only evidence. Most registers end as **unknown**; the few functions given are **inferred** from how the code uses the
register, with the reasoning stated.

**Grades.** *established*: read from the shipped binary (the instruction, its operands, the value or bits). *inferred*: a reading built
from code behaviour, with the reasoning given. *unknown*: not settled. A statement about what a register does in hardware is never
established here, because no document or measurement says.

Part of [the snprom images](README.md); the reset and PALE_RESET context is in [boot-sequence.md](boot-sequence.md).

## Source and method

- Image: `shub1snprom.bin` from package `snprom-10.54-70399` (SAL 5.04, 6 MiB at `0xffa00000`), sha256 starting `51ccf9ad`.
  Components and addresses are the FIT entries in [boot-sequence.md](boot-sequence.md): generic PAL_A `0xffff8000` to `0xffffffbf`;
  processor-specific PAL_A 7.31 `0xfffc2fc0`, 5.37 `0xfffc9ac0`, 1.27 `0xfffd0280` (each entered at image + `0x300`);
  PAL_B 7.79 `0xffdc8000`, 5.73 `0xffe78000`, 2.25 `0xfff28000`.
- Decode: GNU binutils 2.44 `ia64-linux-gnu-objdump`, which prints the two forms as `mov msr[rX]=rY` and `mov rY=msr[rX]`. Only bundles with a
  valid template were decoded, so data between code does not produce sites. Addresses are objdump line addresses: slot 0 is the bundle
  address, slot 1 is +6 and slot 2 is +0xc (the same convention as the `br.ia` addresses in [boot-sequence.md](boot-sequence.md)).
- Index resolution: for each site the index register was traced backwards through `mov`, `movl`, `adds` and `addl` (up to 120 instructions,
  stopping at a gap in the code). A site whose index comes from a load, an `add` of two registers, a table or a loop is **computed** and
  is counted separately. The trace follows straight-line order, not the control-flow graph, so a few indices could be wrong where two paths meet;
  the sites of the priority registers below were each read by hand. Every site was decoded from the bytes; reachability of the non-priority sites was
  not proved, so counts are of decoded sites, not of executed ones.
- Site totals: generic PAL_A 52; PAL_A 7.31 257, 5.37 365, 1.27 367; PAL_B 7.79 3738, 5.73 3789, 2.25 3674. Computed-index sites: PAL_A 7.31 11, 5.37 11, 1.27 11;
  PAL_B 7.79 about 90, 5.73 about 90, 2.25 about 90 (listed by cluster in the last section).
- PAL_B 7.79, 5.73 and 2.25 share almost all of their MSR sites (same indices, nearly the same counts), as do the three specific PAL_A images, so
  the table below gives counts for each rather than separate pages.

## What an MSR is to this code (inferred)

PAL moves values through `msr[]` the way it moves them through `pmc[]` or `rr[]`: an index in a general register, 64-bit reads and writes, a
serialisation instruction when ordering matters. The code treats MSRs as processor-internal control and status registers: it sets and clears single
bits by read-modify-write, writes constants to blocks of consecutive indices, and polls bits for completion. The indices used are
0, 3 to 32, 154 and 392 to 1779 (see the table); 1000 and up is the range the Itanium 2 PAL uses for nearly everything.

## Entry points of the generic PAL_A that touch MSRs (established)

The vector bundles at `0xFFFFFF50` to `0xFFFFFFB0` branch as follows (read from the bundles): `0xFFFFFF50` and `0xFFFFFF60` return through `b0`;
`0xFFFFFF70` to `0xFFFF83F0`; `0xFFFFFF80` to `0xFFFFDA60`; `0xFFFFFF90` to `0xFFFF8A80`; `0xFFFFFFA0` to `0xFFFF8DA0`; `0xFFFFFFB0` to `0xFFFF83A0`.
Which of `0xFFFFFF90` and `0xFFFFFFA0` is PALE_CHECK and which PALE_INIT is **inferred**: both save registers into MSRs, then look for a PAL_B in the FIT
(the walk reads type 1 entries and compares bytes of the PAL_B header with the `cpuid[3]` family and model bytes and, for the revision byte, with bits 15:8 of msr[1715] read at `0xFFFF8C96` and `0xFFFF8FB6`; so msr[1715] holds a revision-like byte, inferred), and jump to the PAL_B plus `0x10080`.
The SDM's section 11.1 fixes no addresses for them. The routine at `0xFFFF8210` (MSR 1553, 1640, 1730 window, below) is not the target of any static branch in the image, and
the bundle just before it is a branch to itself; how it is entered is **unknown**.

## The `br.ia` sites and the MSR writes before them (established)

| `br.ia` (slot 2) | `b0` | `r2`, `r3`, `r5` | MSR writes in the lead-up |
|---|---|---|---|
| `0xFFFF83EC` (PALE_RESET stub) | `0xFFFFFFE0` | `r5` = 1; `r2`, `r3` not set | msr[212] = 0 (`0xFFFF83C0`), msr[1225] = 4 (`0xFFFF83D0`), `srlz.d`, `r5` = 1 |
| `0xFFFF872C` (FIT PAL_A check) | `0xFFFF8730` | `r2` = FIT entry address, `r3` = entry size field, `r5` = 1 | none on the path; the only MSR access between the reset stub and here is msr[0] = 0 at `0xFFFF8406` |
| `0xFFFF8A5C` (no usable PAL_A) | `0xFFFF8A60` | `r2` = `r3` = `r5` = 0 | none on the path (the msr[1643] writes at `0xFFFF8916` and `0xFFFF8A00` are on other paths) |
| `0xFFFC4A6C` (PAL_A 7.31; `0xFFFCB66C` in 5.37, `0xFFFD1E1C` in 1.27) | `0xFFFC4A70` | `r2` = `r3` = `r5` = 0 | reads msr[1225] first (`0xFFFC4A10`) and calls only if bit 14 or bit 2 is set |

So the later `br.ia` sites are not preceded by fresh 212 or 1225 writes: they rely on the state the reset stub left, and the processor-specific PAL_A tests msr[1225]
before calling (next section). That is the discriminating evidence for 1225 over 212 as the gate (inferred; there is no read of msr[212] anywhere in PAL_A).

## Priority registers

### msr[212]

| Site | Access | Detail |
|---|---|---|
| generic PAL_A `0xFFFF83C0` | write | value 0 (`r0`), in the same instruction group as `mov b0=r3` and `mov r41=4`; `srlz.d` follows the write to 1225 two bundles later |
| PAL_B 7.79 `0xffdfa0c0` / `0xffdfa0f6` (5.73 `0xffeab0c0` / `0xffeab0f6`) | read, write | in a routine that takes no arguments (it returns -2 in `r8` if `r29`, `r30` or `r31` is nonzero): reads msr[1572], msr[212], msr[1416]; **sets** msr[212] bit 0, **clears** msr[1572] bit 15 and msr[1416] bit 34; writes all three; `srlz.d`; polls msr[1572] bit 40 (`0xffdfa110`) until clear; `srlz.i` |
| PAL_B 7.79 `0xffdfa1b6` / `0xffdfa1f0` / `0xffdfa210` (5.73 `0xffeab1b6` and following) | read, write, read | the paired routine (same argument check): writes msr[1713] = 0, **sets** msr[1572] bit 15, **clears** msr[212] bit 0, **sets** msr[1416] bit 34; `srlz.d`; polls msr[212] bit 40 until clear; `srlz.i` |
| PAL_B 7.79 `0xffdefca6`, `0xffdf05a6` | read | tests bit 0 only; at `0xffdefcb0` a clear bit skips a block that then reads msr[1561] |

Function: **inferred** that bit 0 of msr[212] is a mode-enable flag that is 0 after reset and is set and cleared by a pair of PAL procedures that also toggle msr[1572] bit 15 and msr[1416] bit 34;
that bit 40 (of 212 in one routine, of 1572 in the other) is a busy or done flag the code waits on; and that other PAL code checks bit 0 before using a feature. What the mode is: **unknown**.
Which PAL procedure indexes reach the two routines: not resolved (the dispatch is not a plain compare chain on `r28`; no static branch targets their entry points).
The write of 0 at reset is established; that it is a "reset to disabled" is inferred from the later code setting the bit.

### msr[1225]

| Site | Access | Detail |
|---|---|---|
| generic PAL_A `0xFFFF83D0` | write | value 4 (`r41`), then `srlz.d`, then the reset `br.ia` |
| specific PAL_A `0xFFFC4A10` (5.37 `0xFFFCB610`, 1.27 `0xFFFD1DC0`) | read | tests bit 14 and bit 2; the branch skips the `br.ia` at `0xFFFC4A6C` when both are clear |
| PAL_B 7.79 `0xffe252b6` (5.73 `0xffed6306`) | read | tests bit 14 or bit 2 (`tbit.nz.or`); either set takes the branch to `0xffe253e0`, both clear falls into a path that checks a `cpuid[3]` revision byte and calls the routine at `0xffde8030`, which writes msr[1225] = 1 |
| PAL_B 7.79 `0xffde6900`, `0xffde8040` (5.73 `0xffe96d50`, `0xffe98490`) | write | value 1, first instruction of two table-style loaders: each then writes constants to msr[1224] (256 writes per routine, same index every time, `r25` set to 1224 again every fourth write) and to the other indices in 1200 to 1236 (one `movl` constant and one write each), the first loader (`0xffde68f0`) ends after msr[1211] with `srlz.d`, `srlz.i` and `br.few b0` (`0xffde8020`); the second continues through further indices; each routine is reached from `0xffe25340` and `0xffe253c0` after a `cpuid[3]` revision-byte test |

Function: **inferred** that msr[1225] selects a state of a processor-internal mechanism, because the reset stub programs it just before the special `br.ia`,
the processor-specific PAL_A reads it back and uses bit 2 and bit 14 to decide whether to call `br.ia` again, and PAL_B uses the same two bits to decide whether to run its register-load routines (a value of 4
from reset means those routines are skipped, a clear state means they run, and the routines leave it at 1). The stubs are consistent with Intel's patent US 6,542,981 describing an MSR set to a special value
before a `br.ia` that invokes resident microcode, but no MSR number is given there, so naming 1225 as that MSR is **inferred** and unproved. The meaning of individual bits other than "2 and 14 gate the two paths" is **unknown**.
msr[1224] is written and never read in any PAL image: **inferred** a write-only data port loaded while msr[1225] = 1 (consistent with the patent's "microcode upgrade" language, not shown by the code).
The constants written to 1200 to 1236 and 1224 are table data in the PROM and are not reproduced here.

### msr[1640]

About 275 sites in PAL_B 7.79 (137 writes, 137 reads), 6 writes and 5 reads in PAL_A 5.37 and 1.27, 4 and 4 in 7.31, 2 and 3 in generic PAL_A. Observed read-modify-write patterns in PAL_B 7.79:
set bit 54 (31 sites), set bit 54 then clear it later in the same routine (28), set bit 57 (26), set bit 62, set bit 60, set bit 53, and one field write at bit 6 (3).

- **Bit 56 test in the PAL_A hand-offs (established).** At `0xFFFF8BF6` and `0xFFFF8F16` the entry paths of the `0xFFFFFF90` and `0xFFFFFFA0` vectors read msr[1640] and test bit 56 (`0xFFFF8C00`, `0xFFFF8F20`);
  if it is clear they branch to `0xFFFF8120` with `r30` = 2 (the common error exit), otherwise they continue to the FIT walk for PAL_B. Inferred: bit 56 says a valid state exists to be handled (reading a saved context).
- **Bit 54 window (established).** At `0xFFFF82A0` to `0xFFFF8320` the routine at `0xFFFF8210` clears `cr.pta` bit 0, sets msr[1553] bits 43:42 to 3, sets msr[1640] bit 54, sets msr[1730] bit 43 and clears bit 36 (`srlz.i`), executes, then writes the old
  bits back (1730 bits 43 and 36 cleared, 1640 bit 54 cleared, `cr.pta` restored, 1553 bits 43:42 cleared). The same sequence of four MSR changes brackets PMC and PMD register work
  at least 28 times in PAL_B (for example `0xffdf2040` to `0xffdf2090`: PMC/PMD writes then the clears), and
  specific PAL_A has it at `0xFFFC3170` to `0xFFFC31E0`. Inferred: bit 54 (with 1553 and 1730 bits above) opens a window in which the processor is in a PAL-only mode for
  performance-monitor or similar accesses. The window in the generic PAL_A contains one bundle that objdump cannot decode (`0xFFFF82F0`: an instruction slot with an undefined encoding between the `srlz.i` and the closing code); it is
  not named here and its meaning is **unknown**.
- Other bits: 57 and 62 are set in PAL_B and PAL_A 7.31 (`0xfffc3b90` to `0xfffc3ba0` sets bit 62 and then branches to a common exit with `r28` = 63); meaning **unknown**.

Function of msr[1640] as a whole: **inferred** a PAL mode and status word (bit 54 window enable, bit 56 state-valid), the rest **unknown**.

### msr[1641], msr[1642], msr[1643] (and msr[0])

- **Save at the hardware entries (established).** In the paths from `0xFFFF8A80` and `0xFFFF8DA0` (`0xFFFF8AA0` to `0xFFFF8F00`, eight copies selected by predicates from the caller), each is written under a `tnat` test so a NaT value is not stored:
  `msr[0]` gets `r30` (guarded by a predicate), msr[1641] gets `r31` (in one copy `b0`, `0xFFFF8DD0`), msr[1643] gets `r29`, and msr[1642] gets the predicate registers (`mov r30=pr`) with bit 0 cleared.
  No synchronisation instruction follows; the next MSR access is the msr[1640] read.
- **Readers (established).** PAL_B 7.79 reads them back, for example `0xffdf4d36`, `0xffdf4d50`, `0xffdf4d90` (reading 1642, 1643, 1641 after writes at `0xffdf4c16`, `0xffdf4c30`, `0xffdf4c50`
  where msr[1641] = `b0` and msr[1643] = `pr`), and uses them as scratch: `ar.unat` into msr[1643] (`0xffe17146`), bits 0, 1 and 2 of msr[1642] set one at a time (`0xffe16dd0`, `0xffe16e50`, `0xffe16ee0`),
  r5, r10 and r13 read back from 1642, 1643 and 1641 (`0xffe171c0`, `0xffe17200`, `0xffe17270`).
- **Status code (established that it is written; inferred meaning).** msr[1643] also takes 0 at `0xFFFF8916` (just before entering the processor-specific PAL_A at image + `0x300`) and a value in 9 to 15 at `0xFFFF8A00`
  (just before the same entry, when a flag from the FIT walk says something failed), which [boot-sequence.md](boot-sequence.md) reads as success or a failure status.
  So 1643 is both a scratch register and, at that hand-off, a status value for the processor-specific PAL_A.

Function: **inferred** that 1641 to 1643 (with msr[0]) are PAL-private scratch registers used where general registers cannot be trusted (machine check and INIT entry, and the PAL_B code that follows), and that 1643 doubles as a hand-off status word. Their reset values and any hardware meaning are **unknown**.
msr[0] is written 9 times in generic PAL_A (once with 0 at `0xFFFF8406` on the `0xFFFFFF70` path just after `cpuid[3]` is read, eight times with `r30` in the save blocks) and read 16 times in PAL_B 7.79: **inferred** scratch.

## Other registers

Counts are writes/reads per component (decoded sites with a resolved index). The observation column lists up to two read-modify-write patterns seen in PAL_B 7.79 (bit numbers; `field a:b=rX` is a deposit of a register); "unknown" means no function could be read from the code.
Adjacent indices with the same pattern and no distinct bits are merged. No row here is established beyond "the accesses exist"; every function reading is **unknown** unless the observation says otherwise.

| MSR | generic | A 7.31 | A 5.37 | A 1.27 | B 7.79 | B 5.73 | B 2.25 | observation |
|---|---|---|---|---|---|---|---|---|
| 3 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 4-6 | - | - | - | - | 1/2 | 1/2 | 1/2 | unknown |
| 7 | - | - | - | - | 0/2 | 0/2 | 0/2 | unknown |
| 8 | - | - | - | - | - | - | 0/2 | unknown |
| 15 | - | - | - | - | 0/2 | 0/2 | - | unknown |
| 32 | - | - | - | - | 0/1 | 0/1 | 0/1 | unknown |
| 154 | - | - | - | - | 1/0 | 1/0 | 1/0 | = 1 (x1) |
| 392 | - | - | - | - | 1/2 | 1/2 | 1/2 | field 7:6=r45, field 12:11=r45 (x1) |
| 477 | - | - | - | - | 1/0 | 1/0 | 1/0 | = 0x83 (x1) |
| 480 | - | - | - | - | 1/1 | 1/1 | 1/1 | field 38=r58 (x1) |
| 512 | - | - | - | - | 2/2 | 2/2 | 2/2 | unknown |
| 529 | - | - | - | - | 2/2 | 2/2 | 2/2 | unknown |
| 536 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 537 | - | - | - | - | 1/0 | 1/0 | 1/0 | = 0xfee (x1) |
| 1024 | - | - | - | - | 1/3 | 1/3 | 1/3 | unknown |
| 1028-1031 | - | - | - | - | 0/3 | 0/3 | 0/1 | unknown |
| 1039 | - | 2/2 | 2/2 | 2/2 | 11/17 | 11/17 | 7/11 | clear 5:0 (x7); set 0, set 1, set 2, set 3, set 4, set 5 (x4) |
| 1040 | - | - | 2/0 | 2/0 | 17/1 | 18/1 | 14/1 | = 4 (x4); = 3 (x2) |
| 1046 | - | - | - | - | 0/1 | 0/1 | 0/1 | unknown |
| 1056 | - | - | 2/2 | 2/2 | 7/5 | 6/5 | 7/6 | set 0, set 1, set 2 (x1); clear 0, clear 1, clear 2 (x1) |
| 1057 | - | - | - | - | 3/2 | 3/2 | 3/2 | unknown |
| 1058 | - | - | - | - | 1/5 | 1/5 | 1/5 | unknown |
| 1072-1076 | - | - | - | - | 0/1 | 0/1 | 0/1 | unknown |
| 1079 | - | - | - | - | 0/1 | 0/1 | 0/1 | unknown |
| 1081 | - | - | - | - | 0/6 | 0/6 | 0/4 | unknown |
| 1082 | - | - | - | - | 0/2 | 0/2 | - | unknown |
| 1084 | - | 7/5 | 9/6 | 9/6 | 84/38 | 84/38 | 84/38 | field 5:4=r60, clear 15:11, clear 30:16, set 31 (x16); set 31 (x4) |
| 1085 | - | 1/1 | 1/1 | 1/1 | 13/4 | 13/4 | 9/2 | set 1, clear 9 (x2); set 1, clear 9, clear 1, set 9 (x2) |
| 1087 | - | - | - | - | 7/6 | 7/6 | 7/6 | unknown |
| 1152 | - | 1/2 | 1/4 | 1/4 | 4/26 | 4/26 | 3/21 | set 3 (x1); field 13:0=r2 (x1) |
| 1153-1154 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1167 | - | - | - | - | 6/5 | 6/5 | 2/1 | clear 8 (x2); set 8 (x2) |
| 1168 | - | - | - | - | 2/4 | 2/4 | 2/4 | clear 4:3 (x1); field 4:3=r31 (x1) |
| 1183 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1200 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x1 (x2) |
| 1201 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1202 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1203 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1204 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1205 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1206 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1207 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1208 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1209 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1210 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1211 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1212 | - | - | - | - | 0/2 | 0/2 | 0/2 | unknown |
| 1215 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1216-1221 | - | - | - | - | 2/0 | 2/0 | 2/0 | unknown |
| 1222 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x1) |
| 1223 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1226 | - | - | - | - | 0/1 | 0/1 | 0/1 | unknown |
| 1231 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1232 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1233 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1234 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1235 | - | - | - | - | 2/0 | 2/0 | 2/0 | = 0x0 (x2) |
| 1236 | - | - | - | - | 1/0 | 1/0 | 1/0 | = 0x1 (x1) |
| 1237 | - | - | - | 0/3 | 20/52 | 22/54 | 23/52 | clear 0, clear 1 (x4); clear 5 (x3) |
| 1247 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1279 | - | - | 2/2 | 2/2 | 9/11 | 9/11 | 3/5 | clear 23 (x4); set 23 (x3) |
| 1280 | - | - | 2/2 | 2/2 | 2/2 | 2/2 | 2/2 | set 14, set 13 (x1); clear 14, clear 13 (x1) |
| 1282 | - | - | 2/2 | 2/2 | 5/7 | 5/7 | 17/19 | set 3 (x1); clear 3 (x1) |
| 1283 | - | - | - | - | 2/8 | 2/8 | 2/2 | unknown |
| 1292 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1416 | - | 6/9 | 8/13 | 8/13 | 47/69 | 47/69 | 39/59 | bit 34 toggled with 212 (and bit 16 / 50:49 elsewhere) |
| 1417 | - | - | - | - | 11/6 | 11/6 | 11/6 | unknown |
| 1440 | - | - | - | - | 0/1 | 0/1 | 0/1 | unknown |
| 1442 | - | - | - | - | 1/0 | 1/0 | 1/0 | = 15 (x1) |
| 1464 | - | - | - | - | 2/5 | 2/5 | 2/3 | unknown |
| 1504 | - | 4/4 | 6/6 | 6/6 | 21/20 | 21/20 | 22/21 | clear 54, clear 53 (x3); set 54, set 53 (x3) |
| 1505-1507 | - | - | - | - | 12/13 | 12/13 | 12/13 | unknown |
| 1508 | - | - | - | - | 10/14 | 10/14 | 10/14 | unknown |
| 1509-1512 | - | - | - | - | 9/13 | 9/13 | 9/13 | unknown |
| 1536 | - | 4/8 | 3/9 | 3/8 | 11/27 | 11/28 | 20/29 | clear 7 (x2); field 0=r31 (x1) |
| 1537 | - | - | - | - | - | 7/8 | 7/8 | unknown |
| 1544 | - | 12/0 | 15/0 | 15/0 | 176/0 | 176/0 | 182/0 | = 0 (x12); = 769 (x2) |
| 1545 | - | 4/0 | 5/0 | 5/0 | 22/41 | 22/41 | 22/49 | unknown |
| 1546 | - | 13/0 | 17/0 | 17/0 | 203/0 | 203/0 | 209/0 | unknown |
| 1547 | - | - | 3/0 | 3/0 | - | 12/8 | 12/8 | unknown |
| 1552 | - | 1/0 | 1/0 | 1/0 | 47/66 | 49/68 | 49/68 | clear 4 (x22); set 4 (x1) |
| 1553 | 2/2 | 4/4 | 4/4 | 4/4 | 16/19 | 16/21 | 26/32 | bits 43:42 set to 3 then cleared around the 1640 bit 54 window |
| 1557 | - | - | - | - | 0/6 | 0/6 | 0/6 | unknown |
| 1558 | - | 3/3 | 3/3 | 3/3 | 30/46 | 30/46 | 30/45 | clear 4, set 30 (x5) |
| 1559 | - | 2/22 | 2/24 | 2/24 | 14/175 | 14/173 | 14/179 | set 1 (x5); andcm r17, or r2 (x1) |
| 1560 | - | 1/0 | 1/0 | 1/0 | 33/17 | 33/17 | 33/17 | = 0xf1e2 (x16) |
| 1561 | - | 1/0 | 1/0 | 1/0 | 1/6 | 1/6 | 1/6 | unknown |
| 1572 | - | 2/3 | 2/5 | 2/5 | 10/41 | 10/41 | 8/35 | bit 15 toggled and bit 40 polled with 212 and 1416 |
| 1573 | - | 0/1 | 0/1 | 0/1 | 2/2 | 2/2 | 2/2 | field 16=r3 (x1); = 255 (x1) |
| 1600 | - | 7/0 | 9/0 | 9/0 | 76/5 | 76/5 | 76/5 | unknown |
| 1601 | - | 5/0 | 6/0 | 6/0 | 35/5 | 35/5 | 35/5 | unknown |
| 1602-1603 | - | 5/0 | 6/0 | 6/0 | 35/1 | 35/1 | 35/1 | unknown |
| 1604 | - | 1/0 | 1/0 | 1/0 | 3/2 | 3/2 | 3/2 | unknown |
| 1608 | - | 2/2 | 3/2 | 3/2 | 12/6 | 12/6 | 12/6 | unknown |
| 1609-1611 | - | 2/2 | 3/2 | 3/2 | 12/1 | 12/1 | 12/1 | unknown |
| 1612 | - | 1/1 | 1/1 | 1/1 | 3/2 | 3/2 | 3/2 | unknown |
| 1616-1619 | - | 2/0 | 3/0 | 3/0 | 10/1 | 10/1 | 10/1 | unknown |
| 1620 | - | 1/0 | 1/0 | 1/0 | 3/2 | 3/2 | 3/2 | unknown |
| 1624-1626 | - | 2/0 | 3/0 | 3/0 | 10/1 | 10/1 | 10/1 | unknown |
| 1627 | - | 3/0 | 4/0 | 4/0 | 9/2 | 9/2 | 9/2 | unknown |
| 1628 | - | 1/0 | 1/0 | 1/0 | 3/2 | 3/2 | 3/2 | unknown |
| 1632 | - | 1/0 | 1/0 | 1/0 | 1/0 | 1/0 | 1/0 | unknown |
| 1633-1635 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1664 | - | 2/1 | 2/1 | 2/1 | 9/10 | 9/10 | 15/14 | set 0 (x6); field 8=r3 (x1) |
| 1676 | - | - | 2/2 | 2/2 | 6/6 | 7/8 | 7/8 | set 0, set 1 (x2); clear 0, clear 1 (x2) |
| 1697 | - | - | - | - | 2/3 | 2/3 | 2/3 | clear 7 (x1); set 57 (x1) |
| 1698 | - | - | - | - | 3/7 | 3/7 | 3/7 | clear 2:0 (x3) |
| 1704-1711 | - | - | - | - | 1/0 | 1/0 | 1/0 | unknown |
| 1712 | - | - | - | - | 1/3 | 1/3 | 1/3 | unknown |
| 1713 | - | - | - | - | 2/3 | 2/3 | 2/3 | zeroed with the 212 and 1572 toggle |
| 1714 | - | - | - | - | 5/11 | 5/11 | 5/11 | set 53, clear 53 (x2); clear 52, set 52, set 52, set 52 (x1) |
| 1715 | 0/2 | 0/1 | 0/1 | 0/1 | 0/3 | 0/3 | 0/4 | read only; bits 15:8 compared with a PAL_B header byte in the PALE entry paths |
| 1728 | - | 3/3 | 9/9 | 9/9 | 69/69 | 69/69 | 57/57 | set 48, clear 49 (x23); clear 48, set 49 (x23) |
| 1730 | 2/1 | 7/8 | 17/22 | 17/22 | 124/169 | 124/169 | 104/141 | bit 43 set and 36 cleared (42/48/49 in other copies) in the same window |
| 1776 | - | - | - | - | 3/7 | 3/7 | 3/5 | unknown |
| 1777 | - | 1/0 | 1/0 | 1/0 | 3/0 | 3/0 | 3/0 | unknown |
| 1778 | - | - | - | - | 3/7 | 3/7 | 3/7 | clear 5 (x1); clear 3 (x1) |
| 1779 | 0/1 | 1/0 | 1/0 | 1/0 | 6/14 | 6/14 | 6/14 | clear 15 (x2); set 8, clear 8, set 9, clear 9 (x1) |

Sets of indices worth noting: the 1504 to 1512 group is accessed in matching 13-and-12 patterns in PAL_B (probably a block of per-structure registers; inferred from the matching counts); 1544 and 1546 are written in long runs and never read in PAL_A or in 7.79 (1545 and
1547 are also read), so they look like an indexed load port (inferred, weak); 1600 to 1628 are mostly written (a block saved and restored? **unknown**).

## Computed-index sites

PAL_A 7.31: `0xfffc40c6` (sum of two registers) and ten sites in `0xfffc8b90` to `0xfffc9826` with indices set far from the access. PAL_B 7.79: the generic accessor routines at `0xffdd8160` to `0xffdd8600` (index in `r28`, taking an argument:
`mov r29=msr[r28]` / `mov msr[r28]=r29`), table-driven loaders (`0xffde6890`, `0xffde68a6`: read an index, an and-mask and an or-value from a table through `r28`, apply them to the MSR, stop at an index of all ones), a block at `0xffe074d0` to `0xffe076c0`
(index from an extracted bit field), and index sums at `0xffe07ab0` to `0xffe08370`. The table contents are PROM data and are not recorded. Which indices they cover is **unknown**.

## Intel's SR870BN4 PAL (package SR870BN4_1001_SUP3.ZIP, file S870BN4C.BIN, sha256 `fb422439a42e3d06fe5286c68942c03293868cdde07891758437d4f98642d252`)

Compared by locating each SGI component in the file by bundle match and re-running the same decode.

- Generic PAL_A: 2043 of 2048 bundles identical (the differing ones are the last bundles of the block, which hold the pointers); the reset stub, the `br.ia` sites and all 52 MSR sites are the same. Established.
- PAL_A 5.37 and PAL_A 1.27: byte-identical, all MSR sites the same (msr[1225] read, msr[1640] 11 sites each). Established.
- PAL_B 2.20 (Intel) against PAL_B 2.25 (SGI): the same set of (index, read or write) pairs with the same counts for all 250 pairs, including 212 (7 sites), 1225 (3), 1640 (about 260), 1641 to 1643. Established. So the 212, 1225 and 1640 to 1643 uses are Intel common code, not SGI additions.
- PAL_A 7.46 (Intel) is a different build from SGI's 7.31 and uses a different index set (392, 432, 480 to 484, 514 to 522 and others), with none of 212, 1225 or 1640 to 1643. PAL_B 7.79 and 5.73 have no counterpart in this file (its FIT lists one PAL_B, 2.20). So the 1000-and-up indices
  are shown as Intel code only through the shared 5.37, 1.27 and 2.2x images; whether the Madison 7.x images use them for the same purpose cannot be checked against Intel's file.

## What is not settled

- What any MSR is in hardware. Only the uses above are read.
- The entry condition of the `0xFFFF8210` routine and the undecoded slot at `0xFFFF82F0`.
- The PAL procedure indexes of the PAL_B routines (212 and 1572 toggles, the register loaders). Closing this needs the PAL_B dispatch table read to its end.
- Whether control returns from the reset `br.ia` or continues at `0xFFFFFF70`; see [boot-sequence.md](boot-sequence.md).
- Per-bit meaning of 1225, 1640 and every register in the table.

Method note for repeaters: the traces above were produced by decoding with objdump, sanitising invalid templates, and tracing index registers backwards. No PROM or BIOS bytes or listings are stored here.
