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
(the walk reads type 1 entries and compares bytes of the PAL_B header with the `cpuid[3]` family and model bytes and, for the revision byte, with bits 15:8 of msr[1715] read at `0xFFFF8C96` and `0xFFFF8FB6`; so msr[1715] holds a revision-like byte, inferred), and jump to the PAL_B plus `0x10080` (from `0xFFFFFF90`) or plus `0x10070` (from `0xFFFFFFA0`).
The SDM's section 11.1 fixes no addresses for them. The routine at `0xFFFF8210` (MSR 1553, 1640, 1730 window, below) is not the target of any static branch in the image, and
the bundle just before it is a branch to itself; how it is entered is **unknown**.

## The `br.ia` sites and the MSR writes before them (established)

| `br.ia` (slot 2) | `b0` | `r2`, `r3`, `r5` | MSR writes in the lead-up |
|---|---|---|---|
| `0xFFFF83EC` (PALE_RESET stub) | `0xFFFFFFE0` | `r5` = 1; `r3` = `0x80000000ffffffe0` (the value `b0` was loaded from); `r2` not set | msr[212] = 0 (`0xFFFF83C0`), msr[1225] = 4 (`0xFFFF83D0`), `srlz.d`, `r5` = 1 |
| `0xFFFF872C` (FIT PAL_A check) | `0xFFFF8730` | `r2` = FIT entry address, `r3` = entry size field, `r5` = 1 | none on the path; the only MSR access between the reset stub and here is msr[0] = 0 at `0xFFFF8406` |
| `0xFFFF8A5C` (no usable PAL_A) | `0xFFFF8A60` | `r2` = `r3` = `r5` = 0 | none on the path (the msr[1643] writes at `0xFFFF8916` and `0xFFFF8A00` are on other paths) |
| `0xFFFC4A6C` (PAL_A 7.31; `0xFFFCB66C` in 5.37, `0xFFFD1E1C` in 1.27) | `0xFFFC4A70` | `r2` = `r3` = `r5` = 0 | reads msr[1225] first (`0xFFFC4A10`) and calls only if bit 14 or bit 2 is set |

So the later `br.ia` sites are not preceded by fresh 212 or 1225 writes: they rely on the state the reset stub left, and the processor-specific PAL_A tests msr[1225]
before calling (next section). That is the discriminating evidence for 1225 over 212 as the gate (inferred; there is no read of msr[212] anywhere in PAL_A).

### `br.ia` sites in the PAL_B images (added after review)

Decoding the three PAL_B images with zero runs shown finds three `br.ia` slots in each, nine in all. With the six PAL_A sites above that is every `br.ia` the decoder reports inside a PAL component (established). Two more hits, at `0xffc111c0` and `0xffd44d2c`, lie outside every PAL image in bytes that decode as data, and are not counted.

| `br.ia` (slot 2) | Guard | Registers set before it | MSR writes before it |
|---|---|---|---|
| 7.79 `0xffe254ac` (5.73 `0xffed641c`, 2.25 `0xfff7678c`) | msr[1225] is read at `0xffe252b6`; the branch at `0xffe252dc` goes to this block when bit 14 or bit 2 is set and to the loader calls when both are clear. Same polarity as the specific PAL_A gate (established) | `b1` = `0x80000000ffffffe0` (the `br.ia` operand, the value the reset stub puts in `b0`), `b0` = `0xffe26670`, `r2` = `0xffe254b0` if the `cpuid[3]` revision byte is 3 or less (0 reads as 1) and `0xffe25d90` otherwise, `r3` = 1, `r5` = 0, `r100` = `pr` | msr[1040] = 4; msr[1056] = 2 only when the revision byte is 7 or less; msr[1167], [1183], [1231], [1247] = 0; msr[1215] = one masked bit of msr[1212]; msr[1153], [1154] = 0; msr[1152] set to a low-field value of 8, then written 128 more times with the field at 7 and the value stepping by 128, then bit 16 set; msr[1777] and msr[1714] loaded with ip-relative address values (bit 50 of the old msr[1714] kept); `srlz.d`; then the 1225 read. Addresses `0xffe24600` to `0xffe25296` |
| 7.79 `0xffe3aae0` (5.73 `0xffeebb20`, 2.25 `0xfff8cae0`) | none from an MSR: the routine from its `alloc` at `0xffe3a780` to the `br.ia` has no MSR access. It leaves early if bit 33 of `r13` is set, then runs a chain of one-bit-mask checks (`cmp.eq p7,p6=r14,r0`) that branch to the failure exit `0xffe3ac90` | `b0` = `0x80000000fff72c90` (5.73 `…fff73cd0`, 2.25 `…fff64c90`); `ssm 0x400000` and `srlz.d` immediately before; the two slots after the `br.ia` are branches to `0xffe3ac90`; `r5` is not set in the routine | none |
| 7.79 `0xffdff426` (5.73 `0xffeb0426`, 2.25 `0xfff62726`) | a predicated `br.ia` in a bundle whose neighbours decode as unrelated data (a `getf` and `fwb` pair in the other slots) | `b4` | none |

The first row's block is not reached by the `(p07)` branch at `0xffe2462c`: the compare at `0xffe24610` (`cmp.eq p0,p7=0,r0`) leaves `p7` clear, so that branch never fires. Control gets there by straight-line flow from `0xffe245c0` (the two paths into it, a `cpuid[3]` revision test at `0xffe24560` and its fall-through, both reach `0xffe245c0`), through a cache-flush loop and a chain of predicate-selected jumps, to a computed jump through `b2` = `r12` + 3168 = `0xffe25220`, where `r12` = `0xffe245c0` from the `mov r12=ip` at `0xffe245c6` (established from the bundles). The code that calls this procedure is not traced, so how it is entered is **unknown**. After reset msr[1225] is 4, so bit 2 is set and this path takes the `br.ia` (inferred: assumes nothing else wrote msr[1225] first).

In 5.73 and 2.25 the first row has the same shape with different offsets: `r12` = `0xffed54b0` and `0xfff75970`, `b0` = `r12` + `0x2130` (`0xffed75e0`) and `r12` + `0x1fe0` (`0xfff77950`), and `r2` = `r12` + 3952 or 6224 on the same revision-byte test in 5.73, `r12` + 5888 with no test in 2.25.

The second row has the shape of a fault check, not a service call (inferred): bit 22 of the `ssm` mask is `psr.di`, which the SDM says makes an instruction-set transition fault, and the code treats falling through as failure. What `0xfff72c90` is, and whether the processor would honour the `br.ia` there, is **unknown**. The third row is almost certainly not code (inferred).

## Priority registers

### msr[212]

| Site | Access | Detail |
|---|---|---|
| generic PAL_A `0xFFFF83C0` | write | value 0 (`r0`), in the same instruction group as `mov b0=r3` and `mov r41=4`; `srlz.d` is in the bundle that holds the write to 1225, after its stop bit |
| PAL_B 7.79 `0xffdfa0c0` / `0xffdfa0f6` (5.73 `0xffeab0c0` / `0xffeab0f6`) | read, write | in a routine that takes no arguments (it returns -2 in `r8` if `r29`, `r30` or `r31` is nonzero): reads msr[1572], msr[212], msr[1416]; **sets** msr[212] bit 0, **clears** msr[1572] bit 15 and msr[1416] bit 34; writes all three; `srlz.d`; polls msr[1572] bit 40 (`0xffdfa110`) until clear; `srlz.i` |
| PAL_B 7.79 `0xffdfa1b6` / `0xffdfa1f0` / `0xffdfa210` (5.73 `0xffeab1b6` and following) | read, write, read | the paired routine (same argument check): writes msr[1713] = 0, **sets** msr[1572] bit 15, **clears** msr[212] bit 0, **sets** msr[1416] bit 34; `srlz.d`; polls msr[212] bit 40 until clear; `srlz.i` |
| PAL_B 7.79 `0xffdefca6`, `0xffdf05a6` | read | `0xffdefca6`: tests bit 0; a clear bit branches (`0xffdefcbc`) past a block that then reads msr[1561]. `0xffdf05a6`: the bit 0 test sets p59 only, and the branch after it (`0xffdf05cc`) tests p61, which the argument checks above set, so no branch depends on msr[212] here |

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
| PAL_B 7.79 `0xffde6900`, `0xffde8040` (5.73 `0xffe96d50`, `0xffe98490`) | write | value 1, first instruction of two table-style loaders: each then writes constants to msr[1224] (256 writes per routine, same index every time, `r25` set to 1224 again every fourth write) and to the other indices in 1200 to 1236 (one `movl` constant and one write each), the first loader (`0xffde68f0`) ends after msr[1211] with `srlz.d`, `srlz.i` and `br.few b0` (`0xffde802c`); the second writes the same indices and ends the same way (`br.few b0` at `0xffde976c`); each routine is reached from `0xffe25340` and `0xffe253c0` after a `cpuid[3]` revision-byte test |

Function: **inferred** that msr[1225] selects a state of a processor-internal mechanism, because the reset stub programs it just before the special `br.ia`,
the processor-specific PAL_A reads it back and uses bit 2 and bit 14 to decide whether to call `br.ia` again, and PAL_B uses the same two bits to decide whether to run its register-load routines (a value of 4
from reset means those routines are skipped, a clear state means they run, and the routines leave it at 1). The stubs are consistent with Intel's patent US 6,542,981 describing an MSR set to a special value
before a `br.ia` that invokes resident microcode, but no MSR number is given there, so naming 1225 as that MSR is **inferred** and unproved. The meaning of individual bits other than "2 and 14 gate the two paths" is **unknown**.
msr[1224] is written and never read in any PAL image: **inferred** a write-only data port loaded while msr[1225] = 1 (consistent with the patent's "microcode upgrade" language, not shown by the code).
The constants written to 1200 to 1236 and 1224 are table data in the PROM and are not reproduced here.

**Loader selection when bits 14 and 2 are both clear (checked after review, established for 7.79).** The code reads `cpuid[3]` (index 3 set at `0xffe252e6`) and extracts bits 15:8 (the revision byte, `extr.u r17=r19,8,8`), replaces 0 by 1, and compares it with a limit held in the low seven bits of a constant; bit 7 of the constant selects "revision above limit" (both constants here have it set). At `0xffe252e0` to `0xffe2532c` the limit is 3: above 3 branches to `0xffe25360`, otherwise `0xffde8030` is called (through `0xffe25340`) and its return goes to the common exit `0xffe26670`. At `0xffe25360` to `0xffe253ac` the limit is 8: above 8 goes to the exit, otherwise `0xffde68f0` is called (through `0xffe253c0`). So a revision byte of 3 or less (including 0) selects `0xffde8030`, 4 to 8 selects `0xffde68f0`, and above 8 selects neither. Reset leaves msr[1225] = 4, so the first time through, neither loader runs. In 5.73 and 2.25 the both-clear path calls a single loader (`0xffe96d40`, `0xfff47890`) with no revision test; the revision byte there only picks `r2` for the later `br.ia`. The same bits and encoding are compared at other sites (26 `cpuid[3]` reads in PAL_B 7.79 alone, limits 1, 3, 5, 7 and 8 among them); those are not catalogued.

### msr[1640]

About 275 sites in PAL_B 7.79 (142 writes, 134 reads), 6 writes and 5 reads in PAL_A 5.37 and 1.27, 4 and 4 in 7.31, 2 and 3 in generic PAL_A. Observed read-modify-write patterns in PAL_B 7.79:
set bit 54 (31 sites), set bit 54 then clear it later in the same routine (28), set bit 57 (26), set bit 62, set bit 60, set bit 53, and one field write at bit 6 (3).

- **Bit 56 test in the PAL_A hand-offs (established).** At `0xFFFF8BF6` and `0xFFFF8F16` the entry paths of the `0xFFFFFF90` and `0xFFFFFFA0` vectors read msr[1640] and test bit 56 (`0xFFFF8C06`, `0xFFFF8F26`; the branches are at `0xFFFF8C0C` and `0xFFFF8F2C`);
  if it is clear they branch to `0xFFFF8120` with `r30` = 2 (the common error exit), otherwise they continue to the FIT walk for PAL_B. Inferred: bit 56 says a valid state exists to be handled (reading a saved context).
- **Bit 54 window (established).** At `0xFFFF82A0` to `0xFFFF8320` the routine at `0xFFFF8210` clears `cr.pta` bit 0, sets msr[1553] bits 43:42 to 3, sets msr[1640] bit 54, sets msr[1730] bit 43 and clears bit 36 (`srlz.i`), executes, then writes the old
  bits back (1730 bits 43 and 36 cleared, 1640 bit 54 cleared, `cr.pta` restored, 1553 bits 43:42 cleared). The same sequence of four MSR changes brackets PMC and PMD register work
  at least 28 times in PAL_B (for example `0xffdf2040` to `0xffdf2090`: PMC/PMD writes then the clears), and
  specific PAL_A has it at `0xFFFC3170` to `0xFFFC31E0`. Inferred: bit 54 (with 1553 and 1730 bits above) opens a window in which the processor is in a PAL-only mode for
  performance-monitor or similar accesses. The window in the generic PAL_A contains one bundle that objdump cannot decode (`0xFFFF82F0`: an instruction slot with an undefined encoding between the `srlz.i` and the closing code); it is
  not named here and its meaning is **unknown**; its slot is described under [undecodable slots](#undecodable-slots) below.
- Other bits: 57 and 62 are set in PAL_B and PAL_A 7.31 (`0xfffc3b90` to `0xfffc3ba0` sets bit 62 and then branches to a common exit with `r28` = 63); meaning **unknown**.

Function of msr[1640] as a whole: **inferred** a PAL mode and status word (bit 54 window enable, bit 56 state-valid), the rest **unknown**.

### msr[1641], msr[1642], msr[1643] (and msr[0])

- **Save at the hardware entries (established).** In the paths from `0xFFFF8A80` and `0xFFFF8DA0` (`0xFFFF8AA0` to `0xFFFF8F00`, eight copies selected by predicates from the caller), each is written under a `tnat` test so a NaT value is not stored:
  `msr[0]` gets `r30` (guarded by a predicate), msr[1641] gets `r31`, msr[1643] gets `r29`, and msr[1642] gets the predicate registers (`mov r30=pr`), with bit 0 cleared only when `r29` is NaT.
  No synchronisation instruction follows; the next MSR access is the msr[1640] read.
- **Readers (established).** PAL_B 7.79 reads them back, for example `0xffdf4d36`, `0xffdf4d50`, `0xffdf4d90` (reading 1642, 1643, 1641 after writes at `0xffdf4c16`, `0xffdf4c30`, `0xffdf4c50`
  where msr[1641] = `r12`, msr[1642] = `b0` and msr[1643] = `pr`), and uses them as scratch: `ar.unat` into msr[1643] (`0xffe17146`), bits 0, 1 and 2 of msr[1642] set one at a time (`0xffe16dd0`, `0xffe16e50`, `0xffe16ee0`),
  r5, r10 and r13 read back from 1642, 1643 and 1641 (`0xffe171c0`, `0xffe17200`, `0xffe17270`).
- **Status code (established that it is written; inferred meaning).** msr[1643] also takes 0 at `0xFFFF8916` (just before entering the processor-specific PAL_A at image + `0x300`) and one of 10, 11, 13 or 15 at `0xFFFF8A00`
  (just before the same entry, when a flag from the FIT walk says something failed; 9, 12 and 14 are assigned to the register first but overwritten before the write), which [boot-sequence.md](boot-sequence.md) reads as a status code: Intel SDM vol. 2 Table 11-4 (pp. 2:292 to 2:293) says 10, 11, 13 and 15 each report that a good processor-specific PAL_A was found.
  So 1643 is both a scratch register and, at that hand-off, a status value for the processor-specific PAL_A.

Function: **inferred** that 1641 to 1643 (with msr[0]) are PAL-private scratch registers used where general registers cannot be trusted (machine check and INIT entry, and the PAL_B code that follows), and that 1643 doubles as a hand-off status word. Their reset values and any hardware meaning are **unknown**.
msr[0] is written 9 times in generic PAL_A (once with 0 at `0xFFFF8406` on the `0xFFFFFF70` path just after `cpuid[3]` is read, eight times with `r30` in the save blocks) and read 16 times in PAL_B 7.79: **inferred** scratch.

**msr[0] accesses (added after review; sites established, meaning inferred or unknown).** The index is the literal `r0`, so every access below is msr[0].

- Generic PAL_A: 9 writes, 0 reads. `0xFFFF8406` writes `r0`; eight writes under predicate `p01` at `0xFFFF8AA0`, `0xFFFF8AF0`, `0xFFFF8B50`, `0xFFFF8BA0`, `0xFFFF8DC0`, `0xFFFF8E10`, `0xFFFF8E70` and `0xFFFF8EC0` store `r30`, each in the save block that also stores `r31`, `pr` and `r29` to msr[1641] to msr[1643].
- Each specific PAL_A (7.31 / 5.37 / 1.27): 19 reads, 1 write. The first read (`0xfffc32e0` / `0xfffc9de0` / `0xfffd05a0`) puts msr[0] in `r5`; the write (`0xfffc3440` / `0xfffc9ed6` / `0xfffd05d6`) puts `r5` back, and bit 22 of `r5` is then tested. The other 18 reads each load a register and test one bit of it, in this order of sites, bits 21, 7, 6, 11, 10, 7, 7, 5, 14, 14, 14, 7, 14, 14, 23, 15, 22 and 20 (7.31 sites `0xfffc3730` to `0xfffc48c0`; the other two images repeat the same bit sequence, 1.27 with bit 22 tested once more at its start). Nothing else is done with the value.
- PAL_B 7.79: 7 writes and 16 reads (5.73: 7 and 19; 2.25: 5 and 18). Writes: `0xffdf7930` stores `ar.unat`; `0xffe07020`, `0xffe07070`, `0xffe070d0`, `0xffe07120` (the PAL_B copies of the generic save block) store `r30`; `0xffe16e30` and `0xffe22120` store `r30` and are followed by setting bit 1 of msr[1642]. Reads: `0xffdf7c30`, `0xffdf7c70`, `0xffdf7cc0`, `0xffdf7cf0` go back into `ar.unat`; `0xffe09036` (bits 0 and 1 of the value tested, then branches), `0xffe09110` and `0xffe09160` restore `r30` on the exit path; `0xffe17220`, `0xffe18870`, `0xffe22510` and `0xffe232c0` load `r12` in register-dump code; `0xffe23be6` (bit 0), `0xffe26930` (bit 24), `0xffe26b20` (bit 10), `0xffe27950` (bit 17) and `0xffe27a60` (bit 10) test one bit and branch.

Function: **inferred** that msr[0] is a scratch slot with several uses: `ar.unat` save in PAL_B, `r30` save and restore across PAL entries, and a flag word handed from the generic PAL_A to the processor-specific PAL_A (the generic code stores `r30` as received, the specific code tests bits 5, 6, 7, 10, 11, 14, 15, 20, 21, 22 and 23 of it). What those bits mean, and what `r30` holds at the vectors, is **unknown**.

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

Rechecked after review with a reaching-definition search over the control flow of each image (every definition of the index register that can reach the access, predicated definitions kept alive, indirect branches treated as unknown entries), plus a read of each cluster. The earlier straight-line trace left 11 sites in each specific PAL_A and 89, 89 and 90 in PAL_B 7.79, 5.73 and 2.25. Inferred throughout: a constant is established only where the register has one reaching definition, and the register-stack frames are not followed across calls.

- **All 11 sites in each specific PAL_A resolve.** Ten write 1600, 1544 or 1546 (the same constants as the PAL_B block at `0xffdd8f50`); `0xfffc40c6` (5.37 `0xfffcaca6`, 1.27 `0xfffd1426`) writes a base of 1600, 1608, 1616 or 1624 plus a 2-bit field, so 1600 to 1627. None reaches 212, 1225, 1224 or 1640 to 1643.
- **Constants in PAL_B (62 sites in each image):** 1600, 1544, 1546, 1085, 1040, 1082, 1730, 1572 (the 14 stores at `0xffe074d0` to `0xffe076c0` use the index set before them; the `extr` that looks like their definition is later in the same bundle), 1416, 1084, 1087, 1056, 480, 512 and 529. The "generic accessor" at `0xffdd8160` to `0xffdd8600` the page first described is not one: `r28` is the constant 1084 there and the accesses were never computed. **Six of these sites write msr[1640]** (7.79 `0xffe3c590`, `0xffe3cab0`, `0xffe3d010`, `0xffe3d910`, `0xffe3eaa0`, `0xffe3f670`; the same six in each of the other two images, which are part of the 142 writes counted above); two write msr[1416]. None reaches 212, 1225, 1224, 1641, 1642 or 1643.
- **Bounded, base plus a small field (15 sites):** nine use 1600, 1608, 1616 or 1624 plus a 2-bit field (7.79 `0xffddef80`, `0xffddefb0`, `0xffddf380`, `0xffddf420`, `0xffde2e96`, `0xffde3216`, `0xffde3830`, `0xffde3840`, `0xffde3850`; indices fall in 1600 to 1631); six read 1704 plus a loop counter that starts at 0 and stays below a 3-bit count read from msr[1698] (7.79 `0xffe07ab0`, `0xffe07c10`, `0xffe07d70`, `0xffe080b0`, `0xffe08210`, `0xffe08370`; indices 1704 to 1711). None reaches the registers asked about.
- **Unresolved, 12 sites in 7.79 and 5.73, 13 in 2.25:**
  - Eight sites (7.79 `0xffde4f46` to `0xffde5090`, index `r29` copied to `r2`) sit in code that follows a routine's `br.ret` with no static branch into it. The index is whatever the caller leaves in `r29`. How the code is entered is **unknown**.
  - Two sites (`0xffde6890`, `0xffde68a6`) are the table-driven loader: it reads an index, an and-mask and an or-value from a table at `r28` until an index of all ones. Nothing in the image branches to the loader and no immediate gives its table, so the indices are **unknown** and the table was not read.
  - Two sites (`0xffe09180`, `0xffe091c0`) are on the exit path described under [undecodable slots](#undecodable-slots). Entered by the branches at `0xffe090bc` and `0xffe090ac`, the index is the constant 1642 (set at `0xffe090a6`). Entered by falling through from the other paths, the index register holds the value just read from msr[1641] (the saved `r31`), so the read goes to whatever register that value names. Whether the second read is meant to be indirect is **unknown**; it looks like a restore that should have used the first read's value directly.
  - 2.25 only: `0xfff3a140`, a poll of bit 40 of msr[`r25`] after a msr[1416] update; `r25` reaches the routine from its caller and the routine has no static entry (7.79 and 5.73 poll with a constant index here).
- So the computed sites that surely reach a priority register are the six msr[1640] writes; the 12 or 13 unresolved sites could reach any register, 1642 among them, and 212, 1225 and 1224 are not reached by any resolved computed site. For PAL_B "no other write to 212 or 1225" now holds for every site except those 12 or 13.

## Undecodable slots

GNU binutils 2.44 prints these as raw data although the bundle template is valid. Slot values are read from the 128-bit bundle (template in bits 4:0, slots at bits 5, 46 and 87, 41 bits each); the major opcode is bits 40:37.

| Address | Bundle template | Slot | Major opcode | Remaining fields |
|---|---|---|---|---|
| `0xFFFF82F6` | `0x0b` (two M slots then I, stop at the end) | 1, M unit | 0 | bits 35:33 = 0, bits 32:27 = 33 |
| `0xffe0917c`, `0xffe091bc` | `0x11` (M, I, B, stop at the end), the other two slots are no-ops | 2, B unit | 0 | bits 32:27 = 9 |

(Review found `0xffe0917c` and `0xffe091bc`; two more of the same kind are at `0xffe0905c` and `0xffe0912c`, all on the exit path below.) The M-unit value 33 sits between two values this PROM decodes as `fwb` (32) and `mf` (34) in the same opcode group, and the B-unit value 9 sits between `rfi` (8) and `bsw.0` (12); I did not look either value up in the SDM tables, so I name no instruction for them and grade them **unknown**.

Both values are common idioms, not one-off bytes. The M-slot value occurs 1 time in the generic PAL_A, 18, 22 and 22 times in the three specific PAL_A images, and 211, 211 and 257 times in PAL_B 7.79, 5.73 and 2.25. The B-slot value occurs 0, 1, 1, 1, 12, 12 and 20 times in the same order. Every occurrence has a `srlz.d` or `srlz.i` as the nearest preceding instruction (established, counted from the listing), so they look like a companion to the serialising instruction (inferred), and the hardware evidently accepts them since the PAL runs through them (inferred).

Reachability:
- `0xFFFF82F6` is in the routine at `0xFFFF8210`, which no static branch, immediate or `ip`-relative address in the generic PAL_A reaches and which the bundle before it cannot fall into. By the static flow it does not execute; an indirect entry is not excluded (**unknown**).
- The four B-slot sites (`0xffe0905c`, `0xffe0912c`, `0xffe0917c`, `0xffe091bc`) are on the exit path that restores `r30`, `r31` and `pr` from msr[1641], msr[1642] and msr[0] and selects among its branches with bits 0 and 1 of the msr[0] value (`0xffe09066`, `0xffe0906c`). By the branches: `0xffe0917c` runs on the fall-through run `0xffe09130`, `0xffe09160`, `0xffe09170`, entered from `0xffe090cc` (bits 0 and 1 clear) or by falling from `0xffe090d0` (bit 0 clear, bit 1 set); `0xffe091bc` runs after `0xffe09180` and `0xffe09190`, entered from the branch at `0xffe090bc` (bit 0 set, bit 1 clear) or from the run above. The branch at `0xffe090ac` (bits 0 and 1 set) goes straight to `0xffe091c0` and skips both. Whether this exit path is entered is not traced. These readings assume the B slot falls through; if it redirects control they do not hold (**unknown**). The 5.73 survey in [pal-instructions.md](pal-instructions.md) section 6.2 reads the same word as an `rfi`-like transfer, in which case they do not hold.

## Intel's SR870BN4 PAL (package SR870BN4_1001_SUP3.ZIP, file S870BN4C.BIN, sha256 `fb422439a42e3d06fe5286c68942c03293868cdde07891758437d4f98642d252`)

Compared by locating each SGI component in the file by bundle match and re-running the same decode.

- Generic PAL_A: 2043 of 2048 bundles identical (the differing ones are the first bundle, `0xffff8000`, and the last four, `0xffffffc0` to `0xfffffff0`, which hold the pointers); the reset stub, the `br.ia` sites and all 52 MSR sites are the same. Established.
- PAL_A 5.37 and PAL_A 1.27: byte-identical, all MSR sites the same (msr[1225] read, msr[1640] 11 sites each). Established.
- PAL_B 2.20 (Intel) against PAL_B 2.25 (SGI): the same set of (index, read or write) pairs with the same counts for all 250 pairs, including 212 (7 sites), 1225 (3), 1640 (about 260), 1641 to 1643. Established. So the 212, 1225 and 1640 to 1643 uses are Intel common code, not SGI additions.
- PAL_A 7.46 (Intel) is a different build from SGI's 7.31 and uses a different index set (392, 432, 480 to 484, 514 to 522 and others), with none of 212, 1225 or 1640 to 1643. PAL_B 7.79 and 5.73 have no counterpart in this file (its FIT lists one PAL_B, 2.20). So the 1000-and-up indices
  are shown as Intel code only through the shared 5.37, 1.27 and 2.2x images; whether the Madison 7.x images use them for the same purpose cannot be checked against Intel's file.

## msr 1728 and 1730 strobe loops

Read in the IA-64 Ghidra module (PAL_B 5.73 `0xffe9dd90` to `0xffe9dfb0`, PAL_A 5.37 `0xfffcb200` to `0xfffcb4c0`, PAL_A 1.27 `0xfffd19e0` to `0xfffd1c70`), with the other copies
located by the reference decoder (`ia64_isa.py`) over the PAL_A and PAL_B images. No loop body holds a reserved slot; the O sites in
[reserved-slot-sites.md](reserved-slot-sites.md) only flow into them. Model-run observations are not hardware evidence.

**One routine, 144 copies.** Each copy moves one 4-bit field of msr[1730] to a target `T`: read msr[1730], `extr.u` the nibble (bits 3:0 or 11:8), exit when it equals `T`;
write msr[1728] (select); read msr[1730], set bit 42, set bit 48, set bit 49 when the nibble is below `T` and clear it otherwise (`cmp.lt p7,p8=T-1,nibble`), write, `srlz.d`;
read, clear bit 48, write, `srlz.d`; branch back. Copies: PAL_B 5.73 and 7.79 46 each, 2.25 38, PAL_A 5.37 6, 7.31 2, 1.27 6. All 144 have the same instruction mix, so **no counter,
bound or timeout exists** (established): a nibble that never reaches `T` hangs the caller.

| Register, bit | What the code does | Grade |
|---|---|---|
| msr[1728] 48 / 49 | read-modify-write only: 48 set and 49 clear before a 3:0 loop; 48 clear and 49 set before an 11:8 loop; both clear at exit (72 sites of each form, 216 reads and 216 writes, each write fed by the read of the same index; no other bit of 1728 is touched at any constant-index or `movl`-index site in the image, and the computed-index sites are not excluded) | established; "selects the nibble" inferred |
| msr[1730] 3:0, 11:8 | read, compared with `T`, written back as read by every read-modify-write | established; "counter" inferred |
| msr[1730] 48 | set in one write, cleared in the next, with a read between: a strobe | established |
| msr[1730] 49 | set when nibble < `T`, clear when nibble > `T`: the direction | established as code, hardware meaning inferred |
| msr[1730] 42 | set while stepping; cleared at exit only when `T` is 0 (`cmp.eq p7,p0=T,r0`, then `cmp.eq.and` with the same `T` for the 11:8 field): 72 exit sites carry the predicated clear, and it takes effect in the 30 with `T` 0 (the 29 with `T` 15 and 13 with `T` 8 leave bit 42 set); the other 25 read-modify-write sites are the bit 43 and 36 windows | established; role unknown |
| msr[1730] 43, 36 | the bit 54 window above | established |

**`T` per image** (nibble 3:0 / 11:8): PAL_B 5.73 and 7.79 0 or 15 / 0 or 15 (10 copies with 0 and 13 with 15 per field); PAL_B 2.25 0 / 0 or 8 (8 and 11 copies in 11:8); PAL_A 7.31 15 / 15; PAL_A 5.37 0 or 15 / 0 or 15 (three pairs: 15 and 15, 0 and 0, 15 and 15); PAL_A 1.27 0 / 0 or 8 (three pairs: 0 and 8, 0 and 0, 0 and 8). 8 is reachable from either side. Skip tests (loop not run): PAL_A msr[0] bit 22 (first pair only), msr[1152] bit 18 and msr[1572] bit 18 set, plus
msr[1237] bit 1 in 1.27; the second pair in 5.37 and 1.27 also runs only when `r28` is 2, 0xe, 0x10, 0x208 or 0x209; PAL_B 5.73 msr[1152] bit 18, msr[1237] bit 2, msr[1572] bit 18, or the PAL procedure index in `r28` being 0x1c, 0x1d, 0x206 or 0x20a.

**Is it a counter?** The code compares the nibble with `T`, takes the direction from the comparison and strobes until they match: a servo on a field that a strobe steps (inferred from
144 identical copies, `T` of 0, 8 and 15, and 8 reachable from both sides). A status field set by a calibration step needs neither the direction bit nor the strobe. The step size
(1 assumed), the strobe edge (0 to 1 of bit 48 assumed) and the reset value are **unknown**. Because every write carries the nibble back as read, a model must not let the written
nibble bits override the stepped value. None of Intel's Itanium 2 reference manual 251110 (all three revisions), hardware developer's manual 251109 or specification update 251141
(`docs/library/cache/cpu/itanium/`) names msr 1728 or 1730, and the Library holds no Intel patent on processor self-test or array test via MSR. The system bus is source-synchronous
with strobes (251109, chapter 3); bus-timing taps are a possible use, but no source says so.

**What lets a model past the loops.** The simplest model that passes every loop: msr[1730] bits 3:0 and 11:8 step by one on each 0 to 1 write of bit 48, up when bit 49 is set and down when
clear, the 3:0 field when msr[1728] bit 48 is set and the 11:8 field when bit 49 is. Reset to 0 passes every `T` = 0 loop at once (including `0xffe9ddb0` and `0xffe9de80`) and takes 15 or 8
passes elsewhere; a constant 0 hangs every `T` of 15 or 8, and any constant nonzero value hangs every `T` = 0 loop. The code does not require that model (see Review).

### Review

Independent re-read of every copy in the Ghidra module over the PAL_A and PAL_B images of snprom 10.54 (all 144 strobe sites and all 216 msr[1728] sites decoded, not sampled). Confirmed:
msr[1728] is read-modify-written only, with the three bit pairs and 72 sites of each; each strobe writes bits 42 and 48 (with 49 per the comparison, `cmp.lt p7,p8=T-1,nibble`, so 49 is set below
`T` and clear above), then clears 48 after a fresh read; no other nibble bit is touched; all 144 copies share one instruction mix, exit only through the `cmp.eq` on the nibble and loop on an
unpredicated `br.few`, with no counter. The 3:0 and 11:8 skip tests, the bit 43 and 36 windows and the `T` of 0 at `0xffe9ddb0` and `0xffe9de80` hold.

Corrected here: PAL_A 1.27 has 6 copies, not 4 (the counts summed to 142); PAL_A 5.37 has a `T` = 0 pair, so it is not 15 / 15, and 1.27's 11:8 field takes 0 as well as 8; the second pair in 5.37
and 1.27 has an `r28` gate that the page omitted; "72 of the 97 sites clear bit 42" counted sites that carry a predicated clear, which runs in 30 (`T` 0); the 1.27 address range. The earlier statement that 5.37 and 1.27 are byte-identical
(PAL_A comparison list above) fails for these loops: their `T` differ. Not checked: computed-index sites (`add`, `ld8`, `extr` derived) could in principle touch 1728 or 1730.
The grades stand: code facts established, "servo on a nibble the strobe steps" inferred, no hardware behaviour claimed. msr[1728] need not read back what was written (the loops only
read-modify-write it), so that requirement is dropped.

What the code constrains and does not. Required: the nibble read after some number of strobes equals `T`, for every `T` of 0, 8 and 15, from the unknown reset value; while it differs the
loop goes on, so any model that never reaches `T` hangs the caller. Not required: step size one (a nibble that jumps straight to `T` on the first strobe passes; a step of two from an even reset never
reaches 15); the strobe edge (the set write and the clear write are back to back, so stepping on the 0 to 1 or the
1 to 0 edge, or on the write with 48 set, is indistinguishable); a hardware servo that converges on its own and uses the strobe only as a trigger; whether the other field also moves when one is
selected, since each field is only ever tested while its own loop runs; saturation versus wrap at 0 and 15 (wrap matters only if the direction is inverted). The direction polarity is
constrained only by the `T` = 8 loops: with bit 49 meaning "down", a nibble at 0 and `T` = 8 oscillates between 0 and 15 and never exits, while `T` of 0 and 15 would still pass by wrap. Nothing here
says what the fields mean in hardware.

## What is not settled

- What any MSR is in hardware. Only the uses above are read.
- The entry condition of the `0xFFFF8210` routine and what the undecoded slots do (see [undecodable slots](#undecodable-slots)).
- The PAL procedure indexes of the PAL_B routines (212 and 1572 toggles, the register loaders). Closing this needs the PAL_B dispatch table read to its end.
- Whether control returns from the reset `br.ia` or continues at `0xFFFFFF70`; see [boot-sequence.md](boot-sequence.md).
- Per-bit meaning of 1225, 1640 and every register in the table.

Method note for repeaters: the traces above were produced by decoding with objdump, sanitising invalid templates, and tracing index registers backwards. No PROM or BIOS bytes or listings are stored here.

## Review

Independent review of chips commit `d29ab44`, examined at chips `main` after it. The reviewer wrote none of it. Method: the image (sha256 starts `51ccf9ad`) was decoded again with `ia64-linux-gnu-objdump -z` (zero runs shown, so addresses stay aligned) for generic PAL_A, the three processor-specific PAL_A images and the three PAL_B images; the site totals (52, 257, 365, 3738, 3789, 3674) and the generic and PAL_B counts reproduce. Index registers were then resolved twice: by the straight-line backward trace the page describes, and by a backward walk over the control-flow graph (direct branches, loop branches, calls, and the `mov rX=ip` / `addl rX=32,rX` / `mov b0=rX` / `br` return idiom PAL uses), treating a predicated definition as live unless the access carries the same predicate. Each priority access was then read in context. Intel's file was compared by bundle and by image.

**Confirmed (re-read in the binary).**

- msr[212]: the only write in PAL_A is `0xFFFF83C0`, value `r0`, in the same group as `mov b0=r3` and `mov r41=4`; no PAL_A reads it. PAL_B 7.79 has 5 reads and 2 writes, at the addresses listed (5.73 and 2.25 have the same shape). The two routines at `0xffdfa0a0` and `0xffdfa190` do what the row says, including bit 0 set or cleared, 1572 bit 15 cleared or set, 1416 bit 34 cleared or set, 1713 written with 0 in the second, and the `-2` return when `r29`, `r30` or `r31` is nonzero. The bit 40 polls loop while the bit is set (`tbit.z` then a branch on the complement), so they wait until it is clear; the first polls msr[1572], the second msr[212].
- msr[1225]: the stub writes 4 at `0xFFFF83D0` (index in `r40`, set at `0xFFFF83B0`, no other path into those bundles: `0xFFFF83A0` is the target only of the two branches in the `0xFFFFFFB0` bundle). The specific PAL_A read at `0xFFFC4A10` (5.37 `0xFFFCB610`, 1.27 `0xFFFD1DC0`) is entered only through `0xFFFC4A00` (`mov r8=1225`); it computes `p2` = bit 14 clear and bit 2 clear and skips the `br.ia` when `p2` holds, so the call happens if either bit is set. PAL_B reads it at `0xffe252b6`, `p2` = bit 14 or bit 2 set, and a set bit branches to `0xffe253e0`. The two loaders write 1225 = 1 and 256 values each to 1224; 1224 is never read (512 writes, 0 reads in every PAL_B).
- msr[1640]: 2 writes and 3 reads in generic PAL_A and 4/4, 6/5, 6/5 in the specific images, as the page says. The bit 56 test is at `0xFFFF8C06` and `0xFFFF8F26` and a clear bit errors out to `0xFFFF8120` with `r30` = 2 (`r30` is set in the same group as the test); a set bit continues. The bit 54 window is as described: set 1553 bits 43:42 to 3, clear `cr.pta` bit 0, set 1640 bit 54, set 1730 bit 43 and clear bit 36, `srlz.i`, then undo all of it (`cr.pta` bit 0 restored only if it was set). The PAL_B read-modify-write counts for bit 54 (31) and bit 57 (26) reproduce.
- msr[1641] to 1643 and msr[0] in generic PAL_A: 9 writes to msr[0] (one with `r0` at `0xFFFF8406`, eight with `r30`), and eight copies each of the 1641 (`r31`), 1642 (`pr`) and 1643 (`r29`) saves, each skipped when the source is NaT. The 1643 write of 0 at `0xFFFF8916` runs when a specific PAL_A was found in the primary FIT and the `br.ia` check did not flag a failure (the index is set under the same predicate); the write at `0xFFFF8A00` runs only when no usable specific PAL_A path was taken. Indices are constants set in the same or the previous group on every path; no branch target lies between definition and use at any generic site. msr[1715]: 2 reads (`0xFFFF8C96`, `0xFFFF8FB6`), bits 15:8 compared with the byte at `0x10114` of the PAL_B image.
- Claim 2: the only MSR writes in the 52 generic sites are 1553, 1640, 1730 (inside the routine at `0xFFFF8210`, entered by no static branch and ending in a loop back to itself), 212 and 1225 (the stub), msr[0], 1641 to 1643. Between the vector `0xFFFFFF70` and the `br.ia` at `0xFFFF872C` the only MSR access is msr[0] at `0xFFFF8406` (the callee at `0xFFFF9120` has none); the path to `0xFFFF8A5C` adds none, because the 1643 write at `0xFFFF8916` is predicated off on it and `0xFFFF8A00` is bypassed. The `br.ia` register setup (`r5` 1, 1, 0; `b0` `0xFFFF8730`, `0xFFFF8A60`) is as listed. The only undecoded slot in the reset and hand-off paths is the one inside the routine at `0xFFFF8210`.
- Claim 3. Generic PAL_A: 2043 of 2048 bundles equal Intel's; the five that differ are `0xffff8000` and `0xffffffc0` to `0xfffffff0`. Specific PAL_A 1.27 is byte-identical to the copy at Intel's FIT-listed address; 5.37 is byte-identical to a copy elsewhere in the file (Intel's FIT-listed address for 5.37 does not map linearly to the file, so the match is by content, not by FIT entry). Intel PAL_B 2.20 (header version bytes `20 02`) has the same (index, read or write) counts as SGI 2.25 for every resolved pair, including 212 (5 reads, 2 writes), 1225 (1, 2), 1640 (123, 140), 1641 to 1643, msr[0] and 1715. Intel PAL_A 7.46 (header `46 07`, family byte `0x20`) has 726 decoded sites over indices such as 392, 432, 480 to 484, 514 to 522, 690 and 1164 to 1182, and none of 212, 1225 or 1640 to 1643.
- Patent US 6,542,981 B1 (text read on Google Patents): "set one MSR to a special value" before `br.ia`, "microcode upgrade" language, no MSR number. The page uses it only as a mechanism description.
- Grades: no function is graded established; the "(established)" headings cover instruction facts only.

**Mechanical fixes made in this review (this page).**

1. The `br.ia` table said `r3` was not set at the stub; it holds `0x80000000ffffffe0`.
2. The 212 row put `srlz.d` "two bundles" after the 1225 write; it is in the same bundle, after the stop bit.
3. The bit 56 tests are at `0xFFFF8C06` and `0xFFFF8F26`, not the bundle addresses.
4. The 1643 value written at `0xFFFF8A00` is 10, 11, 13 or 15, not "9 to 15": 9, 12 and 14 are assigned and overwritten before the write.
5. The generic save copies have no `b0` at `0xFFFF8DD0` (the value is the caller's `r31`), and `pr` has bit 0 cleared only when `r29` is NaT.
6. In PAL_B at `0xffdf4c16` to `0xffdf4c50`, msr[1641] = `r12`, msr[1642] = `b0`, msr[1643] = `pr` (the page had `b0` in 1641).
7. PAL_B 7.79 msr[1640]: 142 writes and 134 reads, not 137 and 137.
8. The second 1224 loader writes the same indices as the first and ends the same way; the first ends at `0xffde802c`.
9. Which bundles differ from Intel's generic PAL_A (first bundle and last four).
10. The two PAL_B reads of msr[212] at `0xffdefca6` and `0xffdf05a6` are not alike (see finding 3); the row now says so.

**Findings not fixed.**

1. PAL_B contains `br.ia` sites the page never lists: 7.79 `0xffe254ac` (via `b1` = `0x80000000ffffffe0`, the same target as the reset stub), `0xffe3aae0` (via `b0` = `0x80000000fff72c90`), and a predicated one at `0xffdff426` that sits in what decodes as data and is probably not code; 5.73 and 2.25 have the same three (`0xffed641c`, `0xffeebb20`, `0xffeb0426`; `0xfff7678c`, `0xfff8cae0`, `0xfff62726`). The `0xffe254ac` site is the PAL_B counterpart of the specific PAL_A gate: it is on the path the msr[1225] bit 14 or bit 2 branch takes, so the polarity (call when set, run the loaders when both are clear) matches PAL_A. The page's "br.ia sites" table is PAL_A-only and should say so or list these.
   Resolved after review: commit "firmware/snprom: resolve the PAL MSR review findings": all nine PAL_B sites are listed under [`br.ia` sites in the PAL_B images](#bria-sites-in-the-pal_b-images-added-after-review); `0xffe254ac` is guarded by the msr[1225] bit 14 or bit 2 test and `0xffdff426` is data.
2. In PAL_B the both-clear path is not a single call. A revision byte (`cpuid[3]` bits 15:8, 0 read as 1) up to 3 reaches `0xffde8030`; 4 to 8 reaches `0xffde68f0`; above 8 skips both. Also, a state of 4 left by reset means neither loader runs in the first boot.
   Resolved after review: commit "firmware/snprom: resolve the PAL MSR review findings": confirmed for 7.79 under msr[1225] (revision byte = `cpuid[3]` bits 15:8; 3 or less selects `0xffde8030`, 4 to 8 `0xffde68f0`, above 8 neither); 5.73 and 2.25 have one loader and no revision test there.
3. `0xffdf05a6`: the msr[212] read feeds a `tbit` whose result goes to p59, but the branch after it tests p61 (set earlier from the procedure's arguments, or cleared by `mov pr.rot`). The same pattern is in 5.73 and 2.25. Whether this is a latent bug or the test is meant for another predicate is unknown; the read has no visible effect on control flow.
4. msr[0] is under-described. Besides the 9 generic writes and the 16 PAL_B 7.79 reads, PAL_B 7.79 has 7 writes (5.73 7, 2.25 5), and each specific PAL_A has 19 reads and 1 write. msr[0] is read far more than the "scratch" reading predicts; its function stays unknown.
   Resolved after review: commit "firmware/snprom: resolve the PAL MSR review findings": every access is listed under [msr[0] accesses](#msr1641-msr1642-msr1643-and-msr0).
5. Undecoded slots with a valid template (binutils 2.44 prints data): `0xFFFF82F6` (value `0x108000000`, M-unit opcode 0, x3 0, x4 1, x2 2) and `0xffe0917c` and `0xffe091bc` (`0x048000000`, a B-unit slot: template `0x11`, MIB, slot 2, as the table above says). They sit between `srlz.i` and the next MSR access, so they may be the operation the bit 54 window exists for. Not identified; the opcode map suggests an M-unit invalidation form, unverified.
   Resolved after review: commit "firmware/snprom: resolve the PAL MSR review findings": slot types and opcode fields are under [undecodable slots](#undecodable-slots); the slots are in the exit path and are not known to be unreachable, except `0xFFFF82F6`.
6. Not reproduced: the "250 pairs" for PAL_B 2.20 against 2.25 (this review's trace gives 216 resolved (index, direction) pairs over 146 indices, equal for both images); the 1.27 site total 367 (368 here); and a number of non-priority table rows for PAL_B (for example 1084, 1544, 1546, 1552, 1600 to 1626 write counts), where this review's simpler trace resolves fewer sites and disagrees. Those rows are graded unknown, so no grade moves, but the counts are unverified.
7. Computed-index sites (accessor routines taking the index in a register, the table-driven loaders) can reach any index, including the priority ones. Their coverage of 212, 1225 and 1640 to 1643 is unchecked, so "no other write to 212 or 1225" holds only for the resolved sites of PAL_A; for PAL_B it holds for resolved sites.
   Resolved after review: commit "firmware/snprom: resolve the PAL MSR review findings": see [computed-index sites](#computed-index-sites): 12 sites in 7.79 and 5.73 and 13 in 2.25 remain unresolved; none of the resolved ones reaches 212, 1225 or 1224, and six write msr[1640].
8. Intel's own FIT addresses for PAL_A 5.37 and 7.46 do not map linearly to offsets in the file the way 1.27 and PAL_B 2.20 do; Intel PAL_B 2.20 and PAL_A 7.46 were located by FIT address plus a fixed `0xb0000` skew guessed from where 5.37 sits, and checked by header version bytes only.

**Not checked.** PAL_B control flow beyond the sites listed (which PAL procedure reaches the 212/1572 routines); the non-priority table rows; the bit 62, 60 and 53 pattern counts; indirect-branch entries into the middle of code; whether the 1224 constants form a microcode image.

**Cleared scope.** The generic PAL_A rows for msr 0, 212, 1225, 1640 to 1643 and 1715, with the corrections above; the specific PAL_A 1225 gate and `br.ia` sites in all three images; the PAL_B 212 routines, the 1225 read and loaders, and the 1641 to 1643 uses listed; the no-fresh-write claim for the two later `br.ia` sites; the Intel comparison claims, with the location caveat in finding 8; the use of the patent. Not cleared: any meaning of the registers beyond "inferred", the table's non-priority counts, and PAL_B control flow around the loaders and `br.ia` sites.

## PAL procedure indexes 99, 520, 528 and 530, msr 1632, and the Madison state at entry

SAL 5.04 calls four PAL indexes this page's catalogue did not place, and the generic PAL_A hand-off reads msr 1632 at its first instruction. Method: the image was read in Ghidra (IA-64 module, SN2 PROM import, functions seeded at the entry points named below, since analysis alone creates only the vector entries), and every address and constant was checked against `ia64-linux-gnu-objdump -z`. Where the decompiler hid a value it is said. Madison is cpuid model 1, so "Madison" below means PAL_A 5.37 (`0xfffc9ac0`) and PAL_B 5.73 (`0xffe78000`); PAL_B 7.79 (model 0) and 2.25 (model 2) have the same tables unless said. Grades as above, plus the SDM citations (rev 2.3 volume 2, 245318).

### How SAL calls PAL (established)

- SDM Table 11-48 (p. 2:354): indexes 1 to 255 are architected static-register procedures, 256 to 511 architected stacked, **512 to 767 implementation-specific static**, 768 to 1023 implementation-specific stacked. Static procedures are entered with `br.cond` (not `br.call`), index in `r28`, arguments in `r29` to `r31`, results in `r8` to `r11` (section 11.10.2, p. 2:358). So **520, 528 and 530 are implementation-specific** (the SDM leaves their meaning to the processor), and 99 sits in the architected static range where rev 2.3 lists no procedure (its Table 11-49 to 11-55 stop at 51 for static procedures).
- SAL_A's SALE_ENTRY builds `b1` from `r34` (the "PAL procedure call address" in the SDM's exit state, p. 2:290) with bit 63 set, sets `b0` to the bundle 32 bytes on (`mov r2=ip; addl r2=32,r2; mov b0=r2`) and does `br.few b1` (`0xffc4ed80` to `0xffc4ed9c`). SAL_B does the same through `0xffa1da00` (stacked-style entry: `r28 = in0`, `r29` to `r31` = in1 to in3) and its worker `0xffa1da50` (switches to physical mode with `rfi` if PSR.it, dt or rt is set), and through inline `br.few b1` sequences. The PAL address comes from `0xffa1d430`, which reads a per-CPU slot, so SAL never hard-codes it.
- Unimplemented or unaccepted indexes return `r8 = -1` ("Unimplemented procedure", status table p. 2:366, example PAL_BRAND_INFO; the architected rule that an absent optional procedure returns a unique code is on p. 2:354); `-2` is invalid argument, `-3` completed with error.

### PAL_PROC dispatch in the Madison images (established)

- **Recovery-check PAL_PROC (PAL_A).** PALE_RESET builds `r34` as a position-independent address (`0xfffcb9d6` to `0xfffcb9fc`: link-time `0xfffe29e0`, minus the link-time address of the `mov r12=ip` bundle at `0xfffcb910`, plus its real address); in 5.37 it is **`0xfffcc4a0`**. It accepts only `r28` in {2, 14, 16, 520, 521} (the five `cmp.eq.or.andcm` at `0xfffcc4e0` to `0xfffcc4f6`; Ghidra's decompile of `0xfffcc4a0` shows the same five constants and `return -1` otherwise). Any other index, **including 528**, returns `r8 = -1` through `b0` (`0xfffcc8a6`). Model 0 (7.31, `0xfffc58dc` to `0xfffc58e6`) accepts only 14, 16 and 521 (no 2, no 520); model 2 (1.27, `0xfffd2ca0`) has the same five constants as 5.37. The SDM's recovery list (p. 2:290) is FREQ_RATIOS (14), LOGICAL_TO_PHYSICAL (42), PLATFORM_ADDR (16) and one implementation-specific authentication procedure; 2, 520 and 521 are the extras here, so which of 520 and 521 is the authentication call is **inferred** (an implementation-specific index in the list's slot), not shown.
- **PAL_B entry stubs.** PAL_B + `0x10000` is a table of one-bundle `br.few` stubs (5.73: `0x10000` to `0xffeb8000`, `0x10010` to `0xffe9dcc0`, `0x10020`, `0x10030`, `0x10040`, `0x10050`, `0x10060` to `0xffed4b00` (the reset continuation: its code zeroes msr 1505 to 1512, 1544 to 1547, 1537, 1600 to 1628, 1632 to 1635 and 1641 to 1643), `0x10070` to `0xffebf2f0`, `0x10080` to `0xffeca570`, `0x10090`, `0x100a0`, `0x10100`). Which stub is the PAL_PROC address SAL gets after the second SALE_ENTRY is **not traced**; the index dispatch is at **`0xffe9dcc0`** (reached from `+0x10010`).
- **Dispatch at `0xffe9dcc0`.** It saves `r18 = ip` as the relocation anchor, returns -2 if PSR bit 1 (`be`) is set (`0xffe9dcec` to `0xffe9e8e0`), then: indexes 33 and 26 go to their own routines (`0xffe9e430`, `0xffe9e3e0`); every other index goes through `0xffe9dfb0` (522, 518, 28 and 29 enter it directly) and `0xffe9e000`, which tests msr[1237] bit 5 and sets it when clear, to `0xffe9e190`; there 29 and 1 branch to a PSR-mask path at `0xffe9e380` and the rest continue. A set {520, 3, 31, 259, 260, 30, 256, 18, 258, 261} takes the **special path at `0xffe9e5f0`**: it needs `PSR & 0x100a064002 == 0` (psr.be, i, dfl, lp, dt, rt, it clear, so physical mode with interrupts off), selects a link-time handler by index, walks the FIT for a PAL_B entry whose image word at `+0x10114` has a family byte (byte 3) and model byte (byte 2) equal to `cpuid[3]` bits 31:24 and 23:16 and a byte 1 not below msr[1715] bits 15:8 (`0xffe9e770` to `0xffe9e84c`; in 5.73 byte 1 is 5, byte 2 is 1 and byte 3 is 0x1f, so byte 1 follows the image's major version, 7, 5 and 2 in the three images), turns the link address into a real one (`handler - 0xfff00000 + PAL_B base`) and branches to it. The other indexes (range 1 to 768) are looked up in a table of 43 entries, 24 bytes each (index, PSR mask, expected value 0), terminated by an all-ones index, with a parallel table of handler offsets: indexes 2, 4 to 17, 19 to 25, 27, 28, 32, 34, 37 to 39, 41, 257, 261, 274, 512 to 516, 518, 522, 526, 531 and 768. The mask is `0x2044002` (be, i, dfl, lp clear; callable in virtual mode) or `0x100a064002` (the same plus it, dt, rt clear: physical mode only). A PSR that fails the mask returns `-2` (`0xffe9e8f0`); an index not in the table returns **`r8 = -1`** (`0xffe9e8c0`). Intel's PAL_B 2.20 in the SR870BN4 package (SR870BN4_1001_SUP3.ZIP, `S870BN4C.BIN`, sha256 `fb422439a42e3d06fe5286c68942c03293868cdde07891758437d4f98642d252`) has the same table with one more index (523), and also none of 99, 528 or 530. The index set is therefore Intel common code, not an SGI addition (established for the table; I found no name for 520 or any other implementation-specific index in the file's text).

### PAL 528 (0x210)

- **Call (established).** SALE_ENTRY at `0xffc4ed50`, reached from the helper at `0xffc4eca0` only when `r20`'s low byte is 3 (`cmp.eq p7,p6=3,r3` at `0xffc4ecc6`; the other states skip the call). Registers: `r28 = 528`, `r29 = 5` (`r29` starts at 0, the helper at `0xffc4f130` always returns 1, so bit 2 is ORed in, then bit 0), `r30 = r31 = 0`. If bit 3 of `r33` is set SAL loops on `hint` at `0xffc4ed20` and never calls. The caller restores `b0` and `r20` and **ignores `r8` to `r11`** (`0xffc4eda0` to `0xffc4edbc`).
- **PAL side (established).** The recovery PAL_PROC rejects 528 and returns `r8 = -1` (above). The post-reset dispatch has no 528 either.
- **What the PAL code returns.** `r8 = -1` through `b0`. The PAL code runs as shipped, so a CPU model implements nothing for 528; SAL never reads the result. Meaning of the `r29` bits: **unknown** (read as selector flags: bit 0 = reset check, bit 2 = a flag SAL sets always; inferred only from the code, not from a source).
- Ghidra shows this call as an unnamed indirect call and shows neither `r28 = 528` nor `r29`: it models no arguments for the static convention.

### PAL 530 (0x212)

- **Call (established).** `0xffaeb560`: `alloc`, then `r28 = 530`, `r29 = ` the function's argument, `r30 = r31 = 0`; it calls the physical-mode wrapper `0xffa1da50` only if the argument is nonzero and returns with the PAL status in `r8`. Its one caller, `0xffaf5d5c`, runs after `loadrs` and `invala` on a path that ends in a jump through a function pointer (a restart path): when the low 16 bits of its first argument are not `0xfffe` it first calls the routine holding the second 520 call, then 530 with the top 16 bits of that argument, and it does not test the status.
- **PAL side (established).** Absent from the post-reset table (which has 531, not 530) and from the recovery PAL_PROC: `r8 = -1`.
- **PAL result.** The PAL code returns `r8 = -1`; a CPU model implements nothing for 530. Function of 530 in hardware: **unknown**. (Ghidra decompiles `0xffaeb560` as `FUN_ffa1da50()` with no argument: the index is invisible there; objdump shows `adds r28=530,r0` at `0xffaeb56c`.)

### PAL 99

- **Call (established).** `0xffa9c3d0` (one argument, a structure pointer): `r14 = [struct + 0x50]`; if it is zero the function returns; otherwise it calls the wrapper `0xffa1da00` with `r28 = 99`, `r29 = r14`, `r30 = r31 = 0`. SAL's own strings at `0xffbb4b70` (`%C - PAL_DEBUG_FEATURE not supported`) and `0xffbb4b98` (`%C - DEBUG FEATURES (%s): 0x%lx`) name it: success (`r8 = 0`) prints the second with the name returned by `0xffa9e250` for `%s` and the value SAL passed in (the word at struct + 0x50, reloaded at `0xffa9c506`) for `0x%lx`, not `r9` to `r11`; anything else prints the first (the format is selected by `cmp.eq p6,p7=0,r8` at `0xffa9c450`: zero takes `0xffa9c4f0`, which formats the feature name through `0xffa9e250` and prints the 0x%lx line; nonzero falls to the "not supported" print. Ghidra's decompile of this function lists the "not supported" string as an argument of the name helper in the success branch; the helper reads no argument (it only saves `r1` and calls `0xffaeb5c0`, a lookup keyed on `cpuid[3]`), so that argument is Ghidra's)
- **PAL side (established).** Absent from the table: `r8 = -1`, so SAL prints the "not supported" line. 99 is an index the SDM leaves unassigned in the architected range; the SAL's name is a SAL string, not an SDM name.
- **PAL result.** The PAL code returns `r8 = -1`, so SAL logs the "not supported" line; a CPU model implements nothing for 99.

### PAL 520 (0x208)

- **SAL calls (established).** (1) `0xffa9b586` in the early routine that also writes a progress byte (50 before the call, 52 on `r8 == 0`) to the per-CPU register at `0x8150031500`: `r28 = 0x208`, `r29 = 0x1000000`, `r30 = 0x40000`, `r31 = 0`, `br.few b1`. `r8 == 0` takes `0xffa9ba90` and continues (progress 52); `r8 == -4` falls through to `0xffa9b5f0` (progress 183, then a spin loop at `0xffa9b830`); every other status takes `0xffa9b840` (progress 182, then a spin loop at `0xffa9ba80`). Ghidra's decompile of this routine ends at the indirect `br b1` and shows none of the status handling; the branches are from objdump. (2) `0xffa9c046`: `r29 = r30 = r31 = 0`, physical call through `0xffa1da50`, at the end of a restart path; the result is not read.
- **PAL side (established for 5.73).** Accepted by the recovery PAL_PROC (index 520; the compare list at `0xffe9e1b0` to `0xffe9e216` accepts 520, 3, 31, 259, 260, 30, 256, 18, 258 and 261, not 521) and taken by the special path at `0xffe9e5f0` to `0xffea42a0` (`0xfff2c2a0 - 0xfff00000 + PAL_B base`): clear `cr.pta` bit 0 (`vf`), set msr[1640] bit 54, `msr[1544] = 0`, `msr[1546] = 0x8940000000000000`, `srlz.i`, one of the undecodable M slots (value 33), clear msr[1640] bit 54, restore `cr.pta`, copy `r29` to `r11`, `r30` to `r14` and `r31` to `r15`, and continue in `0xffe88250`, which writes msr 1600, 1084, 1544 and 1546 and does a longer sequence. It leaves `r8` as 0 unless a later step fails (**not traced to the end**).
- **What the handler does with the range (established as code, read in a flat listing of PAL_B 5.73).** After the five routines, `0xffea44b0` reads msr[1536] bits 59:48, counts the ways they leave enabled (two per bit) at 256 KiB each, and returns `r8 = -4` if `r30 + r31` is larger and `-5` if `r29` bits 17:0 are not zero (`0xffea4a9c` to `0xffea4aa6`). A zero size takes the disable path at `0xffea4900`. Otherwise it picks one of two msr bit sets by `cpuid[3]` bits 15:8 against 3 (`0xffea4750` to `0xffea47ac`): above 3, msr[1504] bits 24, 32 and 33, msr[1056] bits 2:0 and msr[1040] = 8179; otherwise msr[1676] bit 0, msr[1282] bit 3, msr[1279] bit 21, msr[1504] bits 16, 40 and 41, msr[1280] bits 13 and 14 and msr[1040] = 3 (predicate state left by the five routines was not traced, so that the two sets are exclusive is inferred). Then it walks the range in 256 KiB chunks (`0xffea4ad0`). Per chunk, `0xffea4fb0` writes msr[1545] = `tag << 22 | ecc << 3 | 3` with tag = address >> 18 and seven ECC bits computed by `popcnt` over fixed masks, msr[1544] = the first entry of a 2048-entry range (way × 2048), msr[1546] = `0x94c0_0000_0000_0000` (bits 45:43 from msr[1559]) with the last entry in bits 15:0, then the undecodable slot; then msr[1600] to msr[1627] = 0 and a second command `0x9490_0003_4000_0000` with the same range and slot. The disable path clears the same msr bits and issues no command, but it also writes msr[1040] = 4 (`0xffea4a80`), a value neither enable path writes, so it does more than clear the enable bits.
- **Meaning (inferred).** L3 cache-as-RAM: each 256 KiB chunk becomes one L3 way whose every line is tagged with the chunk's address in state 3 and zero-filled, in the calling processor's own cache, before any DRAM exists. Reasons: the Madison L3 has 128-byte lines and 4 ways per MB for parts up to 6 MB (Itanium 2 reference manual 251110-003 Table 2-5; the up-to-9 MB row has 2 ways per MB, 512 KiB a way), so one way is 256 KiB on those parts, and the walk stops at 24 ways (entry 49151), the 6 MB part, 2048 entries × 128 bytes is 256 KiB, the capacity check counts ways, and the tag is the address bits above the way size. The SHub is not touched. SAL leaves the mode with `520(0, 0, 0)` in the jump to RAM, after saving its early records to node memory; the PROM's need for a per-processor copy of the range is in [smp-and-timers.md](smp-and-timers.md#6-multi-cpu-entry-and-the-per-slice-table). 520 is in the SDM's implementation-specific static range (512 to 767, Table 11-48, p. 2:354, which reserves these "for diagnostic and bring-up software"); no held SDM or Itanium 2 manual names it. What state 3 means to the L3, what the msr bits do and what happens to the lines on disable are **unknown**.
- **PAL result.** For call (1) SAL needs the PAL code to return `r8 = 0`; `r9` to `r11` are not read by SAL on this path (the later code that uses them was not traced). The PAL code decides the status, from the state the CPU model gives it (see the review below), so a CPU model implements no return value here.

### msr 1632 (`0x660`; sites established, function unknown)

- Generic PAL_A: no access. Processor-specific PAL_A, every image: the first group at the `+0x300` entry is `mov r5=1632; mov msr[r5]=r5; srlz.d` (7.31 `0xfffc32c6`, 5.37 `0xfffc9dc6`, 1.27 `0xfffd0586`), a write of the value `0x660`, the register's own index. Ghidra shows it as four byte writes (`msr 0x660 = 0x60`, `0x661 = 6`, `0x662 = 0`, `0x663 = 0`), a byte-lane view of the same 64-bit value.
- PAL_B, every image: the bulk-zeroing routine reached from the PAL_B + `0x10060` stub writes 0 to msr 1632, 1633, 1634 and 1635 (7.79 `0xffe23dc0`, 5.73 `0xffed4df0`, 2.25 `0xfff752b0`; the 1635 write follows each, in the same group).
- **No image reads msr 1632 to 1635**, so nothing branches on it. A model must accept both writes and may keep the value. Function: **unknown** (a write of the register's own index is the pattern of an "arm" or "unlock" write).
- Catalogue check: retracing every resolved `mov msr[rX]` index in all PAL_A and PAL_B images finds none the table above lacks; the table row for 1632 stays "unknown", with the sites now given. The computed-index sites are unchanged.

### The Madison state at PALE_RESET entry

What a public source or the code's own assumptions establish; everything else is **unknown**.
- **Public.** SDM volume 2 section 11.2.1 (p. 2:289) says only that the processor "begins executing code from the PALE_RESET entrypoint"; the SDM defines the **exit** state to SALE_ENTRY (section 11.2.2, pp. 2:289 to 2:291: CFM `sof` 96, RSC 0, PSR `bn` 1, other PSR bits 0 except `df1`/`dfh` on an FPU failure, DCR 0, IVA a PAL-set value, the interrupt block pointer `0x0000_0000_FEE0_0000`), not the entry state. The Itanium 2 hardware developer's manual (251109-001) Table 5-6, "Itanium 2 Processor Reset State (after PAL)" (PDF p. 44), lists RSC mode 0, CFM `sof` 96, `sol` 0, `sor` 0, `rrbs` 0, TLBs invalid, caches invalid and disabled, and says "all other architectural states are undefined at hardware reset"; its p. 28 says each processor "begins execution at the power-on reset vector defined during configuration". Both describe the state after PAL, not the PALE_RESET entry.
- **The code's assumptions (established).** The reset stub at `0xffff83a0` reads no register. The cold-start path it falls into (`0xffff83f0`) reads `ar.pfs` (for `alloc`; the value is unused), `cpuid[3]` and `cr.ifs` (bit 63 cleared and written back). It writes `cr.ipsr`, `cr.iip` and `cr.ifs` and executes `rfi`, which requires PSR.ic = 0 (SDM p. 2:36: interruption control registers can only be accessed with PSR.ic 0, else Illegal Operation fault; p. 2:41 for IFS). It writes `cr.iva` (0) only after the `rfi`, and does not read it or the PSR before. So: **PSR.ic = 0 at entry is the one PSR assumption the code makes** (inferred from the register-access rule, not stated by the image); CFM, RSE configuration, `cr.iva`, `b0` to `b7` and every general register are not read before being written.
- **Not read before write, therefore unconstrained by the image:** PSR other than ic, CFM, RSE (`ar.rsc`), `cr.iva`, `cr.dcr`, IFS contents, PSR.bn, every register, predicate and floating-point register.

## Review (independent, chips c669e77: PAL 520 handler and its meaning)

Independent re-read of the "PAL 520 (0x208)" section as changed by `c669e77`, against a flat `ia64-linux-gnu-objdump` listing of `shub1snprom.bin` SAL 5.04 loaded at `0xffa00000`, the Itanium SDM rev 2.3 vol 2 and Itanium 2 reference manual 251110-001 to -003. The reviewer wrote none of it and used no restricted source. The second-processor use of the procedure is reviewed under [smp-and-timers.md](smp-and-timers.md#review-independent-chips-c669e77-and-fbb3bc7-per-slice-table-pal-520-and-the-overlay-recipe).

**Verdict.** The handler description is correct as code and the grades are right: *established* for the handler, *inferred* for "L3 cache-as-RAM". Three small wording corrections below; none changes what a model must do.

**Confirmed (established).**

- **Dispatch.** `0xffe9e1c6` loads 520 and `0xffe9e1e0` compares it with the index (with 3, 18, 30, 31, 256, 258 to 261); a match falls to `0xffe9e5f0`, which checks PSR (`psr & 0x100a064002 == 0`) and loads `0x80000000fff2c2a0` for 520 (`0xffe9e636`), which is `0xffea42a0` in this image.
- **Count and errors.** After the five routines return to `0xffea4470`, `0xffea44b0` reads msr[1536], keeps `~msr & 0x0fff0..0` (bits 59:48), and sets a predicate per clear bit; the loop at `0xffea4680` counts them over 24 iterations, then doubles the count, giving capacity = 2 x count x 256 KiB (`mov r23=262144`). `r30 + r31 == 0` branches to the disable path `0xffea4900`; capacity below `r30 + r31` returns -4 (`0xffea4aa0`); `r29` bits 17:0 non-zero returns -5 (`0xffea4aa6`). The -4 test comes first.
- **Bit sets.** `cpuid[3]` bits 15:8 against 3 (`0xffea4750` to `0xffea47ac`, selector `0x83`, "greater than"): above 3, msr[1504] bits 24, 32, 33 (`0x3_0100_0000`), msr[1056] bits 2:0, msr[1040] = 8179; otherwise msr[1676] bit 0, msr[1282] bit 3, msr[1279] bit 21, msr[1504] bits 16, 40, 41 (`0x300_0001_0000`), msr[1280] bits 13 and 14, msr[1040] = 3. The disable path clears the same bits. As the page says, p4 on the "above 3" path is the value restored from the entry predicate image, not set by this code, so exclusivity of the two sets is inferred.
- **Per chunk.** `0xffea4ad0` sets `r19 = r30 >> 18` and `r28 = r29 >> 18`, loops over the enabled-way predicates in steps of 2048 entries (way 0 is entries 0 to 2047, the last way ends at 49151), and calls `0xffea4fb0` per way. `0xffea4fb0` writes msr[1545] = `tag << 22 | ecc << 3 | 3` (ECC is seven `popcnt` parity bits over fixed masks of `tag << 3 | 3`), msr[1544] = first entry, msr[1546] = `0x94c0_0000_0000_0000` with bits 45:43 and the last entry in bits 15:0, then the reserved slot (value 33); then zeroes msr 1600 to 1627 in four groups of four and issues `0x9490_0003_4000_0000` with the same fields. The bits 45:43 value is `((msr[1559] bits 23:22) * 3 >> 1) & 1` (`0xffea4af0` to `0xffea4b1c`), so it is 1 for two of the four values of that field; the page's "from msr[1559]" is right but the selection is not the slice field used elsewhere (bits 21:19).
- **Index range.** SDM vol 2 Table 11-48 puts 512 to 767 at "Implementation-specific procedures; static registers calling conventions" and says no SAL or OS code should call them for normal activity; "reserved for diagnostic and bring-up software". No held 251110 revision names 520, msr[1504], msr[1545] or msr[1546] (text searches of -001, -002 and -003).
- **Arithmetic.** 251110-003 Table 2-5: 128-byte lines, 4 ways per MB for the 1.5/3 MB and up-to-6 MB Itanium 2 rows. 1 MB / 4 ways = 256 KiB a way; 256 KiB / 128 bytes = 2048 sets per way, equal to the PROM's 2048-entry step; 24 ways x 256 KiB = 6 MB, equal to 12 msr[1536] bits x 2 ways. Consistent. Support for "zero-filled": the second command follows 16 zero msr writes, 16 x 8 = 128 bytes, one line.

**Corrections.**

1. **SDM page.** The new text cites Table 11-48 at "p. 2:353". The table and the "diagnostic and bring-up software" sentence are on page 2:354 (the extracted page runs between the footers 2:353 and 2:355); the sentence this commit replaced said 2:354 and was right.
2. **"4 ways per MB ... at any size"** (in the Meaning bullet and in smp-and-timers.md section 4). Table 2-5 gives 2 ways per MB for the up-to-9 MB row (512 KiB a way). The claim holds for parts up to 6 MB only.
3. **"clears the msr bits the enable set" (smp-and-timers.md) and the disable path.** The disable path clears those bits but also writes msr[1040] = 4 (`0xffea4a80`), a value neither enable path writes (8179 or 3). Say so.

**Unchanged text found wrong while reading.** The SAL-calls bullet for PAL 520 says the recovery PAL_PROC accepts "index 520 and 521". The compare list at `0xffe9e1b0` to `0xffe9e216` is 520, 3, 31, 259, 260, 30, 256, 18, 258, 261; 521 is not in it. Not part of `c669e77`.

**Not checked.** The five routines at `0xffe88250` to `0xffe89040`; PAL_B 5.73 identification; which msr[1504] bit the other PAL procedures write; what any of the bits do in silicon (still unknown, as stated).
