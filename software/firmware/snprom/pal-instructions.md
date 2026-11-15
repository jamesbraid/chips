# SN2 PROM PAL: instructions no manual defines, event entry state and the `br.ia` call sites

What the PAL code in the SAL 5.04 SHub 1 PROM (`shub1snprom.bin`, package `snprom-10.54-70399`, sha256 starting `51ccf9ad`) needs
from a processor beyond the architected instruction set: two instruction encodings the Itanium manuals leave reserved but
the firmware executes on its normal path, the state the hardware must hand the PAL at its event vectors, and the register
layout at every `br.ia` in the PAL code. Companion to [pal-msrs.md](pal-msrs.md), which catalogues the `msr[]` accesses, and
[boot-sequence.md](boot-sequence.md); part of [the snprom images](README.md).

**Grades.** *established*: read from the shipped image (instruction, operands, address) or from a published manual page
(cited by document, revision and page). *inferred*: a reading built from code behaviour, with the reasoning. *unknown*: not
settled, with what would settle it. Nothing here says what a processor does in hardware unless a manual says it.

## Method and sources

- **Code reading is from Ghidra** with the IA-64 processor module in retools (`ghidra/processors/ia64`), the whole 6 MiB image
  loaded at `0xffa00000` and every bundle disassembled; addresses are the slot addresses objdump prints (slot 0 is the bundle,
  slot 1 is +6, slot 2 is +0xc). Every address, operand and count below was read from that listing unless it says otherwise.
  binutils 2.44 `objdump` was used only to cross-check the module on a hand-built bundle (item 1) and to disassemble a data
  table as bytes. Counts were produced by scripts over the Ghidra listing; the same 702 sites were also found
  independently by a standalone decoder scan, so the count is double-checked.
- **Manuals read** (cited as document, revision, printed page; the opcode tables were read from the rendered pages, the other manuals
  were searched as text for the vector addresses, entry state and any PAL-only instruction):
  Intel Itanium Architecture Software Developer's Manual rev 2.3, vol 1 (245317), vol 2 (245318), vol 3 (323207);
  SDM specification update 248699-008; Itanium 2 Processor Reference Manual 251110 revisions -001, -002, -003;
  Itanium 2 Processor Hardware Developer's Manual 251109-001; Itanium Processor Hardware Developer's Manual 248701-002;
  Itanium 2 Processor Specification Update 251141-001 (the only revision of 251141 held; revision -028 was **not** read);
  SAL Specification rev 3.4 (245359-009).
- Public software read: GNU binutils 2.44 `opcodes/ia64-opc-m.c` (tag `binutils-2_44`, sourceware.org git) and the
  `src/encodings/encoding.decode` table of the ski simulator (github.com/trofi/ski, master as fetched in November 2026,
  commit not recorded).

## 1. The undefined M-unit slot (`0x108000000`)

### What it is (established)

A 41-bit slot in an M position with major opcode 0 (bits 40:37), x3 = 0 (35:33), x2 = 2 (32:31), x4 = 1 (30:27), bit 26
(`y`) = 0, and every other bit, including the qualifying predicate (5:0), zero. In the image it is the 41-bit value
`0x108000000`; Ghidra prints it as `unknown.m 0x108000000` because the module deliberately assigns it no mnemonic.

**Count (established, Ghidra).** 702 sites over the PAL components: generic PAL_A 1; processor-specific PAL_A 7.31 18, 5.37 22,
1.27 22; PAL_B 7.79 211, 5.73 211, 2.25 217. Every site has `srlz.d` or `srlz.i` as the nearest preceding non-nop instruction
(`srlz.d` 501 times, `srlz.i` 201 times). Reachability of individual sites is not proved; counts are of decoded sites.

### What the manuals say

**Verdict: reserved, and it faults. Established for the architecture; what an Itanium 2 does is unknown.**

- SDM vol 3 Table 4-42 and Table 4-43, section 4.4.10 "System/Memory Management", printed page 3:345: opcode 0, x3 = 0 sub-table
  indexed by x4 and x2. Row x4 = 0 holds `break.m`, `invala`, `fwb`, `srlz.d`; row x4 = 1 holds the "1-bit Ext (Table 4-46)" entry
  at x2 = 0 and `srlz.i` at x2 = 3. The cell x4 = 1, x2 = 2 is empty and shaded the dark purple used for "Reserved if PR[qp] is 1"
  (read from the rendered page: the text extraction loses the colour). The cell x4 = 1, x2 = 1 next to it is the same purple.
- The legend: vol 3 section 4.1 (printed pages 3:294 to 3:295) and the section 4 introduction (printed page 3:299). "Reserved if
  PR[qp] is 1" encodings "cause an Illegal Operation fault if the predicate register specified by the qp field of the
  instruction (bits 5:0) is 1 and execute as a nop instruction if 0". Vol 2 section 8, the ISR description for the General Exception vector (printed page 2:192), lists "reserved major opcodes, reserved
  sub-opcodes, or reserved instruction fields" among the causes of an Illegal Operation fault.
- PR0 always reads as 1: vol 1 section 3.1.4 "Predicate Registers" (printed page 1:26). The slot's qp field is 0, so PR[qp] = 1 and
  the architecture says the instruction **raises an Illegal Operation fault every time it executes**. It is not an architectural nop.
- It is **not** `nop.m` or `hint.m`. Those share x3 = 0 and x4 = 1 but use x2 = 0 with bit 26 (`y`) choosing nop (0) or hint (1)
  (Table 4-46 and format M48, printed page 3:349). This slot has x2 = 2. (Aside: GNU's table also lists a DAHR `mov` at x2 = 0,
  y = 1, z = 1; that is a later extension and is not this encoding.)
- B-unit companion: SDM vol 3 Table 4-48 "Indirect/Miscellaneous Branch Opcode Extensions" (printed page 3:350). x6 (bits 32:27)
  = 9 is x4 = 9, x2 = 0: the cell is the teal "Reserved if PR[qp] is 1 B-unit" colour (between `rfi` at x6 = 8 and the
  `vmsw.1` cell at x6 = 0x19 in the next column). With qp = 0 it is likewise a reserved encoding that faults.
- Ignored cells do exist in these tables (white: execute as nop). For B-unit x4 = 1, x2 = 0 the cell is white; neither of the two
  encodings here is in a white cell.
- Spec updates: SDM update 248699-008 mentions only the `nop.m`/`hint.m` naming (its lines on "hint.m"); Itanium 2 update 251141-001 and
  reference manuals 251110-001, -002 and -003 list `break.m` and `nop.m` (format M37/M48) and no other M-unit encoding.
  None names an implementation-specific or PAL-only instruction (established for the revisions read; 251141 beyond -001 unread).
- Side finding, not about this slot: Itanium 2 Reference Manual 251110-002 Table 4-4 "Latencies for OS Related Instructions"
  (printed page 4-4) lists `mov from msr[r0]` and `mov to msr[r0]` rows (latency 36 for the read, 35 and 46 for write
  serialisation). Revisions -001 and -003 do not have the msr rows. So Intel's reference manual acknowledged `msr[]` as a register
  file in one revision. [pal-msrs.md](pal-msrs.md) says no Itanium 2 manual names these registers; the file exists, the registers still are not named.

### What public software does

- binutils 2.44 (`opcodes/ia64-opc-m.c`): the M0 table has `fwb` (x3 0, x4 0, x2 2), `mf` (x4 2, x2 2), `mf.a`, `srlz.d` (x4 0, x2 3),
  `srlz.i` (x4 1, x2 3), `sync.i`, `nop.m` and `hint.m` (x4 1, x2 0, y 0 or 1), and no entry for x4 1, x2 2. It decodes as
  data (established for the table; also checked by assembling the bundle and running the retools-container objdump, which printed
  `data8 0x108000000`).
- ski `encoding.decode`, table `opM0_0`, 128 entries indexed by bits 32:26: entry `0x42` (x2 2, x4 1, y 0) is `EM_ILLEGALOPQP`, the
  same entry used for the other empty "reserved if qp" cells (for example `0x38` to `0x3F`); neighbours `0x40` is `EM_FWB`, `0x44`
  `EM_MF`, `0x62` `EM_SRLZ_I`. So ski treats it as reserved-if-qp, as the SDM does (established for ski's table; I did not run ski on the PROM).

### Patents

Read on Google Patents through a page fetch that answered targeted questions (not the full text read line by line): **US 6,542,981 B1** and **US 7,660,977 B2**.
- US 6,542,981 B1 describes a "special" `br.ia`: ordinary instructions first set a branch register with a function number, another
  with a return address, and one MSR to "a special value"; the processor checks the MSR, and if it is set `br.ia` invokes resident
  microcode instead of switching to IA-32. No instruction encoding, no MSR number and no PAL-only instruction is given.
- US 7,660,977 B2 describes locking PAL/microcode updates (a `PAL_PROC_DISABLE_PAL_UPDATE` procedure, index 77) and says PAL hides
  hardware MSRs; it defines no instruction.

Seen only as search-result snippets, **not read**: US 6,848,046, US 6,775,728, US 8,214,830, US 2004/0019835 A1 (and US 7,904,751 B2
cited by it), US 2009/0249053 A1, US 7,146,488, US 2014/0359640 A1 / WO 2013/101217 A1 / US 9,483,293. None of the snippets mentions a
PAL-only or implementation-specific instruction. No Intel patent found says what encoding `0x108000000` is.

### How the code uses it (Ghidra)

Every site is `srlz` then the slot, in a group of its own; the slot has no non-zero field, so it carries no register operand (inferred:
whatever it does, it does through machine state, not through a general register).

**Nearest preceding `msr[]` write** (PAL_B 7.79, 211 sites; the figures depend on how far the index trace may cross branches, see the review; 5.73 has the same total and the msr[1545] / msr[1547] split differs (6 and 6); 2.25 has six more sites, all in the msr[1546] class):

| Class | Sites | Notes |
|---|---|---|
| after a write to msr[1546] | 137 | typical shape: msr[1544] = index or 0, msr[1546] = command or data, `srlz.d`, slot |
| after a write to msr[1545] or msr[1544] | 12 and 9 | same family, different register written last |
| after a write to msr[1603], [1627], [1600] | 18, 2, 1 | cache-maintenance style routines that end by writing msr[1084] |
| after a write to msr[1084] | 17 | |
| after a write to msr[1730] | 2 | the bit-54 window (below) |
| index not resolved or no write within 30 slots | 10 and 3 | |

PAL_A: processor-specific images 7.31 / 5.37 / 1.27 have the same families (1546: 6 / 10 / 10, 1544: 5 / 4 / 4, 1730: 1 / 1 / 1, none:
5 / 6 / 6); the generic PAL_A's single site is the one in the bit-54 window.

**Nearest following `msr[]` access or branch** (PAL_B 7.79, 211 sites): read of msr[1545] 40, write to msr[1084] 28, write to
msr[1640] 26 (the window close), read of 1559 9, 1608 5, 1058 5, 1028 3, write to 1546 8 and 1544 5, conditional branch 26,
`br.ret` 22, `br.few` 10, none 4. 86 sites (about 41 per cent) are followed first by an `msr[]` **read**; at 79 of those the value read is fed
to a bit test, compare or extract within 14 slots (a heuristic text match, so approximate). At the other 125 nothing is read after the slot before the
routine writes, branches or returns. In no case does a register that the slot could have produced exist to be tested (it has none).

**Windows.**
- The generic PAL_A site, `0xffff82f6`, sits in the routine at `0xffff8210`: it clears `cr.pta` bit 0, sets msr[1553] bits 43:42 to 3,
  sets msr[1640] bit 54, sets msr[1730] bit 43 and clears bit 36, `srlz.i`, the slot, then restores all four (written bits back,
  `cr.pta` restored), as [pal-msrs.md](pal-msrs.md) describes. 26 PAL_B sites are followed by a msr[1640] write (the close of the same window in
  the cases read); 2 PAL_B sites and 1 site in each processor-specific PAL_A follow a msr[1730] write. How `0xffff8210` is entered is still unknown (no static branch reaches it).
- The `msr[1544..1547]` family with `msr[1545]` read afterwards is the commonest shape. Example (PAL_B 5.73, `0xffe8d5e6`): msr[1544]
  and msr[1546] written, `srlz.d`, slot, msr[1545] read and split into fields, then compared (`0xffe8d620`).

**The boot-path user: PAL procedure 520 (PAL_B 5.73).** SAL_B calls PAL procedure 520 at `0xffa9b586` and wants r8 = 0 back. The handler
(`0xffea42a0`, read in Ghidra) does, in order: `rsm 0x6000` (clears psr.ic and psr.i); clears `cr.pta` bit 0 (kept in p11); sets msr[1640]
bit 54; writes msr[1544] = 0 and msr[1546] = `0x8940000000000000`; `srlz.i`; **the slot (`0xffea4366`)**; clears bit 54; restores `cr.pta`
and psr.ic if it was set (psr.i is not set again); then it calls, one after another through `b0` set from `ip`, five routines: `0xffe88250`,
`0xffe885a0`, `0xffe88810`, `0xffe88970` and `0xffe89040`. The first loops four times (counter in bits 17:16 of the values written to
msr[1544] and msr[1546], loop test at `0xffe88356`) with `srlz.d` and the slot in each pass, sets msr[1084] (`0x43c`) around the loop and puts it back, and returns;
the second ends with msr[1544] = 0, `srlz.d` and the slot at `0xffe88656`, then returns. The third (`0xffe88810`) has no slot (it polls
an msr with `srlz.d` and a read loop). The fourth has a slot at `0xffe88ac6`, followed by a read of an msr whose index is in r2 (`0xffe88ad6`);
its consumer was not traced. The fifth was not read to its end. After the five, `0xffea4a96` does `mov b0=r8` (the b0 saved at entry) and
`mov r8=0`; r8 becomes -4 or -5 only under predicates p9 and p13 (`0xffea4aa0`, `0xffea4aa6`). p9 comes from bits of msr[1536] (`0x600`) read at
`0xffea44b0`, after all five calls (so after every slot above), and p13 from loop-count compares (`0xffea4b5c` and following). So r8 = 0 is the default and
the two failure values depend on state read after the slots; **whether a slot changes that state is not excluded** (established for the path
read, the dependence itself unknown).

### What a CPU model can justify

- **Established (architecture):** the encoding is reserved-if-qp in SDM rev 2.3; with qp = 0 it is an Illegal Operation fault.
  binutils and ski agree it is not a defined instruction. The B-unit x6 = 9 slot is in the same state.
- **Established (code):** the shipped PAL, which runs on hardware, executes it 702 times, always immediately after `srlz`, on the boot
  path (procedure 520). PAL_A 5.37 and 1.27 and PAL_B 2.25's counterpart are byte-identical in Intel's SR870BN4 PAL according to
  [pal-msrs.md](pal-msrs.md)'s review, so it is Intel's code, not an SGI addition (that is the review's claim; not re-checked here).
- **Inferred:** a processor that runs this PAL to completion must not raise Illegal Operation for it. Either the hardware treats it
  as a PAL-mode instruction or, equally consistent with the code, as an operation that completes the pending `msr[]` command
  sequence and has no architectural result. Reason: its operands are all zero, it always follows `srlz` and an `msr[]` write
  group, and the code never tests an output of it. A model that executes it as a nop after `srlz` would complete the 520 path,
  but that is a statement about what the PROM needs to proceed, not about the hardware.
- **Unknown:** whether it has any effect (for example committing the msr[1544..1547] index/command registers, flushing a pipeline
  queue or performing the access they describe); whether msr[1545] contents after it depend on it; whether it is legal only with
  psr.ic = 0 or in PAL physical mode; what it does outside PAL mode. What would settle it: an Itanium 2 / Madison PAL or
  microarchitecture document that defines the PAL-private opcode space (not found in any revision read); a reading of the
  msr[1544..1547] consumers in PAL_B to see whether a read of msr[1545] ever returns different values with and without the slot
  (a code reading, not yet done); or a hardware trace, which this program does not take without approval.

### The B-unit companion (B-unit opcode 0, x6 = 9)

Ghidra prints `unknown.b 0x48000000` (bit 30 and bit 27 set: x4 = 9, x2 = 0, qp = 0). 45 sites: PAL_B 7.79 12, 5.73 12, 2.25 18;
processor-specific PAL_A 7.31, 5.37 and 1.27 one each; none in the generic PAL_A. Every one has `srlz.i` as the nearest preceding
non-nop instruction (established). The four sites named earlier (`0xffe0905c`, `0xffe0912c`, `0xffe0917c`, `0xffe091bc`) are in
the exit path that restores r30, r31 and pr from msr[0], msr[1641] and msr[1642]; four more (`0xffdf7c5c`, `0xffdf7c9c`,
`0xffdf7cec`, `0xffdf7d2c`) are in the code that saves and restores `ar.unat` through msr[0]; the rest are in other routines of the same
kind (`0xffdfa8ec`, `0xffe0727c`, `0xffe091ec`, `0xffe23a5c`). SDM status as above (reserved if qp = 1, so faulting with qp = 0).
Grades: encoding and sites established; behaviour unknown, and the same inference holds: a processor that completes this PAL treats it
as non-faulting. The code after each site read is ordinary and the sites are not branch targets, which suggests it does not redirect control there (inferred, assuming it falls through).

## 2. Hardware event entry state

### What the SDM defines (established)

The SDM specifies the state the PAL hands **to** SAL (the exit state) and a small set of resources the hardware owes the PAL. It does not
give numeric vector addresses for PALE_CHECK, PALE_INIT or PALE_PMI, nor a register-by-register entry state; those are implementation
dependent. What it does fix:

| Event | Source | What the hardware provides |
|---|---|---|
| any PAL-based interruption (RESET, MCA, INIT, PMI) | vol 2 section 5.4, printed page 2:101; Table 3-2 footnotes i and j, pages 2:24 to 2:28; section 5.6 and Table 5-6 (page 2:109) | priority RESET > MCA > INIT > PMI; they do not use the IVT; PSR.ic, i, dfl, dfh, sp, di, si, db, lp, tb, cpl, is, id, da, dd, ss, ed, bn, ia, vm are 0 on an interruption; PSR.dt and PSR.it are 0 after a PAL-based one; PSR.mc becomes 1 after MCA or INIT; mfl, mfh, up, pk, rt are unchanged |
| PALE_CHECK (MCA) | vol 2 section 11.3.1 "PALE_CHECK" (page 2:296), 11.3.1.1 (2:297) | PSR.mc = 1 on entry (set by hardware). Required resources: XR0 (min-state pointer registered with PAL_MC_REGISTER_MEM) and bank 0 GR24 to GR31 as scratch, not preserved across the event. When PSR.ic = 0 at the event, optional XIP, XPSR, XFS (stand-ins for IIP, IPSR, IFS) and XR1 to XR3 (scratch for GR24 to GR31); a model-specific `rfi` must restore from them. When PSR.ic = 1, IIP, IPSR, IIM and IFS are loaded as for any interruption. |
| PALE_INIT (INIT) | vol 2 section 11.4 (2:306); Itanium 2 Hardware Developer's Manual 251109-001 section 5.3.2 and Table 5-7 (page 5-6) | INIT is held pending while PSR.mc = 1 and recognised at instruction boundaries; it disturbs no architectural, cache, MSR or integer or floating-point state; IP = PALE_INIT entry; IIP = IP at the INIT; IPSR = PSR at the INIT; IFS.v = 0. PSR.mc = 1 after INIT (Table 3-2 footnote i). |
| PALE_PMI (PMI) | vol 2 section 11.5.1 (2:310) | IIP and IPSR saved by hardware; PMI events pend while PSR.ic = 0 and are delivered when PSR.ic = 1; PSR.i has no effect; the PALE_PMI entry is programmable (PAL_COPY_PAL, section 11.10.3 page 2:389); undefined if a PMI arrives before PAL registers its entrypoint. |
| PMI and INIT vector latches | vol 2 section 11.5.1 | PMI events are latched in implementation-specific latches that the PAL reads; vector numbers 0 to 3 are for SAL, 4 to 15 for PAL; INIT delivery is enabled while PSR.mc = 0. |

The SDM's PALE exit states (MCA vol 2 section 11.3.2 pages 2:297 to 2:299, INIT section 11.4.2 pages 2:306 to 2:310, PMI section 11.5.2
page 2:312) say what PAL itself leaves for SAL: bank 0 GR16 to GR20 as handoff parameters (MCA: GR16 first free min-state address, GR17 XR0
value, GR18 processor state parameter, GR19 rendezvous return, GR20 SALE_ENTRY parameter), CFM a zero-size frame after a `cover`,
RSC.mode = 0 (enforced lazy), BR0 and BR1 saved, PSR.mc = 1 and all other PSR bits 0 except mfl, mfh, pk which are unchanged; PMI passes the
vector number in GR24, XR0 in GR25 and saved RSC, B0, B1 in GR26 to GR28. These describe what the PAL provides **after** its entry code, not what
the hardware provides before it, so they bound the PAL's save work but are not entry state. The vector entry addresses themselves are
the firmware address-space placement of the "PAL_A block" of vol 2 Figure 11-3 and 11-4 (printed pages 2:284 and 2:285): the SDM draws
PALE_RESET, PALE_INIT and PALE_CHECK as entry points in the PAL_A block below 4 GB minus 64 and gives no offsets (grade: not defined by the SDM).

### What the generic PAL_A assumes at its vectors (Ghidra, established for the code)

The vector bundles at the top of the generic PAL_A, `0xffffff50` to `0xffffffb0`, are `nop`, `nop`, `br.few` each. Branch targets:
`0xffffff70` to `0xffff83f0`, `0xffffff80` to `0xffffda60`, `0xffffff90` to `0xffff8a80`, `0xffffffa0` to `0xffff8da0`, `0xffffffb0` to
`0xffff83a0` (the reset stub); `0xffffff50` and `0xffffff60` are `br.few b0`.

Both event paths (`0xffff8a80`, `0xffff8da0`), before any write to a general register that matters, read:
- **p1 and p2.** The first bundles branch on p1 (`0xffff8a8c`, `0xffff8dac`) and then p2 (`0xffff8a9c`, `0xffff8dbc`) to pick one of four
  copies of the save block on each path (the copies start at `0xffff8aa0`, `0xffff8af0`, `0xffff8b50`, `0xffff8ba0` and at `0xffff8dc0` and
  three more; eight in all, four per path). Each copy ends by setting p1 and p2 to the pair that selected it (`cmp.ne.and` to 0/0,
  `cmp.eq` to 0/1 and 1/0, `cmp.eq.or` to 1/1), because the NaT tests inside the copy overwrite p1 and p2. So the dispatch only
  preserves whatever p1 and p2 held on entry; no particular value is needed (inferred from the code, checked in Ghidra). The saved
  `pr` in msr[1642] is read after the first two `tnat.z` have overwritten p1 and p2, so those two bits of it are not the entry values.
- **r30, r31, r29 and pr.** Each save block tests r30, r31 and r29 for NaT (`tnat.z`) and stores each to `msr[0]` (r30), msr[1641]
  (r31), msr[1643] (r29) only when it is not NaT (the stores are predicated), and stores `pr` to msr[1642] with bit 0 cleared if r29 was NaT. After a PAL-based interruption PSR.bn is 0, so these are
  bank 0 registers, inside the SDM's bank 0 GR24 to GR31 set that hardware does not preserve (section 11.3.1.1). The PAL reads them before writing them
  and saves them, which fits preserving the bank 0 values of an interrupted handler (inferred). A NaT value is tolerated.
- **msr[1640] bit 56.** `0xffff8bf6` and `0xffff8f16` read msr[1640] and test bit 56 (`tbit.z p14` at `0xffff8c06`, `0xffff8f26`); if clear
  the code sets r30 = 2 (set in the same group) and branches to `0xffff8120`, which builds a PSR image in r28 (psr.mc set, psr.ic and
  psr.i clear), copies `b0` into `cr.iip`, clears `cr.ifs.v`, sets r8 = 0, and executes `rfi`. If set it continues. (Inferred meaning of
  bit 56: a valid-state flag, as [pal-msrs.md](pal-msrs.md) says.)
- **Then:** the 8-byte pointer at `0xffffffe0` (the FIT), the FIT entries (PAL_B type), the PAL_B header bytes against `cpuid[3]` (bits
  31:24, 23:16, 15:8 against the header's revision, model and family bytes) and bits 15:8 of msr[1715] (`0xffff8c96`, `0xffff8fb6`).
- **b0.** `mov r31=b0` (`0xffff8d86`, `0xffff90b6`) saves the incoming b0 into r31, then b0 is set to the PAL_B entry and `br.few b0`.
  Both PAL_B entries reached this way restore it: the `+0x10080` target starts with `mov b0=r31` (`0xffe19576` in 7.79) and the `+0x10070` target
  starts with `mf` and has `mov b0=r31` in its next bundle (`0xffe0e2fc`); no other `b0` use comes first. So the incoming **b0** is read and
  carried through (established for the code); the event must leave b0 holding the interrupted b0 or a value PAL does not mind. The other
  vectors in the PAL_B stub table do not start this way: `+0x10060` begins `alloc r2=ar.pfs` (7.79 `0xffe23b00`, 5.73 `0xffed4b00`; in 2.25 `0xfff74f00`
  is a run of `nop.b` bundles and moves of b0 to b7 before the `alloc` at `0xfff74fc0`), `+0x10050` and `+0x10090` begin with compares and an `alloc`.
- **Targets.** `0xffffff90`'s path computes PAL_B base + `0x10080` (`movl r30=0x10080` at `0xffff8d76`) and `0xffffffa0`'s path computes
  PAL_B base + `0x10070` (`movl r30=0x10070` at `0xffff9096`). **This corrects [pal-msrs.md](pal-msrs.md), which says both
  go to +`0x10080`.** In PAL_B 7.79 (base `0xffdc8000`) the bundles at `0xffdd8070` and `0xffdd8080` are `br.few` to `0xffe0e2f0` and `0xffe19570`; in
  5.73 (`0xffe78000`): `0xffebf2f0` and `0xffeca570`; in 2.25 (`0xfff28000`): `0xfff712f0` and `0xfff73770`. A third bundle at +`0x10060` goes to
  `0xffe23b00` (7.79), `0xffed4b00` (5.73), `0xfff74f00` (2.25), the target of a vector not reached by the generic PAL_A read here.
  (`+0x10090` goes to `0xffe26670`, `0xffed75e0`, `0xfff77950`, the return address the first `br.ia` row sets in `b0`.)
  Which of the two handlers is MCA and which INIT: the SDM fixes no address. Both handlers test msr[1152] bit 18, msr[1237] bit 2 and msr[1572] bit 18 first; the `+0x10080` one (`0xffe19570` / `0xffeca570`) first copies msr[1237] bit 3 into msr[1558] bit 5,
  the `+0x10070` one (`0xffe0e2f0` / `0xffebf2f0`) starts with `mf`.
  I did not find a discriminator (no PSR.mc, XR0 or min-state reference in either first block), so the assignment stays **inferred**
  (earlier note: `0xffffff90` = PALE_CHECK, `0xffffffa0` = PALE_INIT, from the register saves) and the PMI vector among the other three is **unknown**.
  The vector at `0xffffff70` goes to the reset-return code (`alloc r1=ar.pfs` at `0xffff83f0`, which reads cpuid[3] and writes msr[0] = 0); the
  vector at `0xffffff80` goes to `0xffffda60` and was not read.

**What a CPU model must therefore provide at each entry (summary).**
- Established by SDM: PSR.mc = 1 at MCA and INIT entry; interruption collection off (PSR.ic = 0) and PSR.i = 0; IIP, IPSR set for PMI, INIT and (when ic = 1) MCA; INIT leaves IFS.v = 0; the priority order RESET > MCA > INIT > PMI.
- Established by the code (needed to run this PAL): an `msr[]` file readable at indices 1640 (bit 56 set to continue) and 1715 (revision byte) and writable at 0, 1641, 1642, 1643; readable `cpuid[3]`; a physically addressed 8-byte read at `0xffffffe0`; predicates p1 and p2 defined; r29, r30, r31 and `pr` captured; b0 preserved.
- Unknown: the entry addresses the hardware jumps to (the `0xffffff50`..`0xffffffb0` vector stubs are inferred as RESET at `0xffffffb0`, INIT or CHECK at `0xffffff90` and `0xffffffa0`, with PMI not identified); the state of r29 to r31 and p1, p2 on entry; the reset value of msr[1640] bit 56. Route to settle: a Madison PAL specification that lists the vectors and entry state, or a read of the PAL_B first-block code against min-state layout (not done).

## 3. The PAL_B `br.ia` sites

Nine `br.ia` bundles are in the PAL_B images and six more in PAL_A (all in Ghidra). Three kinds appear. The first column is the slot-2 address.

| Site | Operand register | b0 (return address) | r2 | r3 | r5 | r1 before | What happens next |
|---|---|---|---|---|---|---|---|
| PAL_B 7.79 `0xffe254ac` | b1 = `0x80000000ffffffe0` (set at `0xffe2547c` from r9) | `0xffe26670` (= r12 + `0x20b0`, r12 = `0xffe245c0`) | `0xffe254b0` if `cpuid[3]` revision byte (0 reads as 1) is 3 or below; `0xffe25d90` above 3 | 1 | 0 | `0x99` (`mov r1=0x99` at `0xffe252ac`) | `0xffe26670`: `alloc r2=ar.pfs,96`, restore pr from r100, then `cmp.eq p0,p2=0,r1`: if r1 is non-zero, set msr[1640] bit 59 |
| PAL_B 5.73 `0xffed641c` | b1 = `0x80000000ffffffe0` | `0xffed75e0` (r12 = `0xffed54b0`, +`0x2130`) | `0xffed6420` (revision <= 3) or `0xffed6d00` (otherwise) | 1 | 0 | `0x99` (`0xffed62fc`) | same code at `0xffed75e0` |
| PAL_B 2.25 `0xfff7678c` | b1 = `0x80000000ffffffe0` | `0xfff77950` (r12 = `0xfff75970`, +`0x1fe0`) | `0xfff77070` only (no revision test; the `r3 = 0`, `r2 = 0` arm is not reached by any static branch) | 1 | 0 | `0x99` (`0xfff766ac`) | same code at `0xfff77950` |
| PAL_B 7.79 `0xffe3aae0` (5.73 `0xffeebb20`, 2.25 `0xfff8cae0`) | b0 = `0x80000000fff72c90` (5.73 `...fff73cd0`, 2.25 `...fff64c90`), set at `0xffe3aac6` | the operand itself (b0) | holds the operand value (`movl r2` at `0xffe3aac6`, then `mov b0=r2`) | not set | not set (r14 = `1<<30`) | not read | psr.di is set by `ssm 0x400000` and `srlz.d` immediately before; the two slots after are `br.cond` to the failure exit `0xffe3ac90`; routine has no `msr[]` access |
| PAL_B 7.79 `0xffdff426` (5.73 `0xffeb0426`, 2.25 `0xfff62726`) | b4, predicated (p47) | n/a | n/a | n/a | n/a | n/a | neighbours decode as unrelated data (`getf`, `fwb`, `break.b`); not code (inferred) |
| generic PAL_A `0xffff83ec` (reset stub) | b0 = r3 = `0x80000000ffffffe0` (set at `0xffff83a6`) | none set | not set | `0x80000000ffffffe0` | 1 (`0xffff83dc`) | `alloc r1=ar.pfs` follows at `0xffff83f0` | after `msr[212] = 0` and `msr[1225] = 4`, `srlz.d` |
| generic PAL_A `0xffff872c` (FIT PAL_A check) | b0 = `0x80000000ffff8730` (`0xffff86e6`, `mov b0=r6`), the bundle after the `br.ia` | `0xffff8730` | FIT entry address (r82) | the entry's size field, bits 23:0 of the second qword (r83) | 1 | stale (`alloc r1=ar.pfs` at `0xffff83f0` is the only write between reset and here) | `0xffff8730`: `alloc r3`, then `cmp.eq p0,p21=r1,r0` and a branch on p21 (non-zero r1 goes to `0xffff8600`) |
| generic PAL_A `0xffff8a5c` (no usable PAL_A) | b0 = `0x80000000ffff8a60` | `0xffff8a60` | 0 | 0 | 0 | not read | `0xffff8a60`: `alloc r3`, then `br.few 0xffff8120` (the error exit above) |
| PAL_A 7.31 `0xfffc4a6c` (5.37 `0xfffcb66c`, 1.27 `0xfffd1e1c`) | b0 = r12 + `0x40`, the bundle after the `br.ia` | `0xfffc4a70` | 0 | 0 | 0 | overwritten by `alloc r1=ar.pfs` at the return | taken only when msr[1225] bit 14 or bit 2 is set (read at `0xfffc4a10`) |

(msr[1225] test in PAL_B: the branch at `0xffe252dc` goes to this block when bit 14 or bit 2 of msr[1225] is set and to the loader calls when both are clear.
That is carried over from [pal-msrs.md](pal-msrs.md) and the read at `0xffe252b6` was re-read here.)

**Tables behind r2 (established, bytes; meaning inferred).** The two r2 targets in 7.79, `0xffe254b0` and `0xffe25d90`, are
data, not instructions (they follow the `br.ia` bundle directly and run to `0xffe26670`; each is `0x8e0` = 2272 bytes). Each starts with
a 16-byte block of high-entropy bytes, then 282 eight-byte words: in the first 256, word k has k in bits 47:40 (most words have nothing else set), then 26 more words (re-read in review; an earlier
reading as 141 sixteen-byte records was wrong). How these tables relate to the msr[1224] loaders is in the review. 5.73's `0xffed6420` and `0xffed6d00` have
the same spacing (`0x8e0`); 2.25 has one table at `0xfff77070`.

### PAL_B 5.73 br.ia at 0xffed641c

Re-read in the Ghidra slot listing of `snprom-10.54-70399`; the bundle is `0xffed6410` and this is its slot 2. Grades: established (code as read), inferred, unknown.

- **Gate (established).** msr[1225] is read at `0xffed6300`. Bit 14 or bit 2 set goes to `0xffed6360`, the `br.ia` path; both clear calls the loader at `0xffe96d40` with return address `0xffed6350`, which branches to `0xffed75e0`. So the `br.ia` and the loader are alternatives, not a sequence.
- **Operands (established).** b1 = `0x80000000ffffffe0` (`movl r9` at `0xffed6366`, `mov b1=r9` at `0xffed63ec`); b0 = r12 + `0x2130` = `0xffed75e0`, with r12 = `0xffed54b0` from `mov r12=ip` at `0xffed54b6` (static read); r3 = 1, r5 = 0, r1 = `0x99` (`0xffed62fc`, no later write before the `br.ia`).
- **Table choice (established).** `cpuid[3]` bits 15:8 against 3, unsigned compare: above 3 gives r2 = r12 + `0x1850` = `0xffed6d00`; 3 or below, including 0, gives r12 + `0xf70` = `0xffed6420`. There is no "0 reads as 1" step as in 7.79.
- **Tables against the loader (established, compared word by word).** Each table is a 16-byte lead plus 282 qwords, `0x8e0` bytes; qwords 256 to 281 are zero in both. The loader at `0xffe96d40` writes 256 values to msr[1224]; they equal the first 256 qwords of the `0xffed6d00` table exactly. The `0xffed6420` table matches them except 16 words (indices 104-107, 109, 110, 113, 114, 117, 118, 144-147, 149, 150). A second 256-write loader at `0xffe98480` matches neither table; no direct branch to it was found (indirect callers not excluded). A "single loader with no revision test" is therefore not the whole picture for 5.73: the loader is not chosen by revision, the `br.ia` table is.
- **Return code (established).** `0xffed75e0`: `alloc`, restore pr from r100, `cmp.eq p0,p2=0,r1`. r1 non-zero sets msr[1640] bit 59 (`0xffed7600` to `0xffed7610`); r1 = 0 skips that write. Nothing else there reads r1, and a non-zero r1 is not fatal at this code. msr[1640] bit 59 is also set by a later msr[1212] and msr[1226] mismatch check (`0xffed77d0` to `0xffed784c`, only when msr[0] bit 30 is clear). No reader of bit 59 was found within nine slots of a `tbit` on bit 59 in this PAL_B image (simple scan); other readers are **unknown**.
- **After that (established, partly traced).** It clears six application registers, then tests msr[0] bits 30, 24 and 10, msr[1779] bit 15, and bit 23 of the saved pr, and ends in calls to `0xffe96bd0` (and on one arm `0xffe88760` and `0xffe88970`). The callees were not traced.
- **Loader writes the `br.ia` path lacks (established for the listed code).** The loader writes msr[1225] = 1, msr[1224] 256 times, then msr[1200..1211], msr[1216..1223] and msr[1232..1235]. Neither the `br.ia` path nor `0xffed75e0` to `0xffed7b0f` writes any of msr[1200..1236]. A `br.ia` callee that does nothing would leave them unwritten; whether the real callee writes them is **unknown**.

### Does a consistent layout emerge?

- **r2, r3, r5 are not one convention across all sites (established for the values).** Across the sites that set them (the three PAL_B first-row
  sites, the three generic ones that set r5 and the three PAL_A-specific ones): r2 is either 0 or a pointer to an object (a FIT entry in the
  generic PAL_A, a data table in PAL_B); r3 is 0, 1, the FIT entry's size field or the reset vector value; r5 is 0 at seven sites and 1 at the reset stub and the FIT check.
- **Weak pattern (inferred):** where r2 is a pointer, r3 and r5 describe it: the FIT check passes (entry address, entry size, 1); PAL_B passes
  (table address, 1, 0); the three PAL_A-specific sites and the "no PAL_A" site pass nothing (0, 0, 0). The simplest reading is r2 = pointer,
  r3 = extent or count, r5 = a mode flag, but a function number in r3 or a selector in r5 is **not** supported: r3 is 1 in the PAL_B sites
  and a 24-bit size in the FIT site, and the same PAL_A callee sees r5 = 1 and r5 = 0. The b0 value follows two styles: the operand is
  `0x80000000ffffffe0` (reset stub, PAL_B first row) or it is the address of the bundle after the `br.ia` (the other PAL_A sites).
  The patent's "function number in a branch register" is the nearest published description (US 6,542,981 B1); it does not fit r3 or r5 and is not
  claimed to apply.
- **r1 afterwards.** At the PAL_B site r1 is preset to `0x99`, a non-zero constant, and after the return the code tests r1 against zero and
  sets msr[1640] bit 59 when it is non-zero (established). At the generic PAL_A FIT check r1 is tested against zero immediately after the return, with
  no write to r1 between `0xffff83f0` and `0xffff8a80` other than that `alloc` (established). Reading (inferred): r1 is a result or status register for the call, zero meaning success, and the
  non-zero preset in PAL_B makes a call that never writes r1 look like a failure. The specific PAL_A sites overwrite r1 with `alloc` at the return, so they
  ignore it. What the callee puts in r1 and in any other register is **unknown**.
- **Not claimed:** what the processor does at `br.ia` with msr[1225] in either state; whether a `br.ia` with msr[1225] set to 4 returns at all
  (the reset stub's return path is not traced; see [boot-sequence.md](boot-sequence.md)).

## 4. PAL_A 5.37 up to the first reserved slot

The processor-specific PAL_A 5.37 (image `0xfffc9ac0`, entered at +`0x300` = `0xfffc9dc0`) is the first code after the generic PAL_A hand-off. A model that returns 0 for every `msr[]` read runs it up to the reserved M slot in the bundle at `0xfffca400`. Read in Ghidra (IA-64 module) from `shub1snprom.bin`, sha256 starting `51ccf9ad`. Intel's SR870BN4 BIOS package (`S870BN4C.BIN`, sha256 starting `fb422439`) holds the same bytes: 0x67c0 bytes from the start of the 5.37 image, this site included (established, byte comparison). No bytes or listings are reproduced here.

### The stop site (established)

- Bundle `0xfffca400`: template 0x0b (`M;MI;`, stops after slot 0 and slot 2). Slot 0 `nop.m`, **slot 1 at `0xfffca406` is the reserved word `0x108000000`** (the stop is at slot index ri = 1), slot 2 `nop.i`. The qualifying predicate of all three slots is 0 (PR0), so the slot is the architecturally faulting encoding of section 1.
- Context class (section 1's table): **after a write to msr[1546]** (`mov msr[r27]=r12` at `0xfffca3f0`, r27 = 1546, a stop, then `srlz.d`, a `nop.i` and the `nop.m` of the slot's bundle, a stop, then the slot with its `nop.i`, a stop). msr[1544] is not written in this routine. It is the second of the 22 reserved slots in this image and the first on the entry path.
- After the slot: msr[1558] is read, bit 13 cleared and written back (`0xfffca410` to `0xfffca430`); msr[1608] to msr[1612] are read and each compared with zero. Any nonzero value branches to `0xfffca690`, which calls `0xfffcd6f0`, sets msr[1416] bit 53, msr[1084] bit 8 and msr[1640] bit 62 and leaves to `0xfffcb260` (an error exit, inferred from the flags). All zero falls through to the msr[0] bit 6 and bit 11 tests and a `br` to `0xfffcd850`, whose return point `0xfffca520` composes a second msr[1546] write (row 8 of the same table, msr[1544] = 0) and a second reserved slot at `0xfffca626`.
- **Dependence (established for the code, inferred for meaning):** the slot has no register operands, nothing after it tests a general register it could have written. The code branches only on msr[1608..1612], state the msr[1546] command may change, and on predicates set before the slot. The destination registers of an undefined encoding are not known, so "it writes no register or predicate" is not shown; only that none is named and that every register the code tests later is loaded again after the slot. So the code relies on the slot as ordering or a side effect, not on a result. Whether the slot is needed for those reads to be zero is **unknown**. The PAL_B routine at `0xffde3430` (7.79) has the same shape: msr[1544] and msr[1546] written, `srlz.d`, a slot at `0xffde3466`, then five msr reads from one of four banks at `0x640`, `0x648`, `0x650`, `0x658` (five registers each), returned to its caller untested. msr[1608..1612] is the second bank. That supports reading the msr[1546] write as a command and msr[1608..1612] as its status (**inferred**), and does not say what the slot does.

### Path from the entry to the stop

1. `0xfffc9dc0`: msr[1632] = `0x660` (its own index), `srlz.d`. Read msr[0].
2. msr[0] is masked with `cpuid[3]` revision byte (bits 15:8): above 1 clears `0x2488`, above 3 clears `0x10010` (compares at `0xfffc9e00` to `0xfffc9e7c`). Written back at `0xfffc9ed6`.
3. msr[1504] read, bits 58 and 19 set, written (`0xfffc9eb6`). msr[1152] read, bit 18 set only if msr[0] bit 22 is set, written (`0xfffc9ef0`). msr[1536] read, bit 15 set, written (`0xfffc9f10`). msr[1572] read, bit 15 set, written (`0xfffc9f50`). None branches on the value.
4. FIT walk: the pointer at physical `0xffffffe0`, signature check (failure goes to `0xfffcb600`), checksum if the header entry's C_V bit is set (it is), msr[1640] = 0 (`0xfffca000`). For each type 1 (PAL_B) entry: msr[1715] read (`0xfffca0b0`); skip unless the entry address has its low 11 bits clear (the three PAL_B entries have C_V clear, so no PAL_B checksum is computed; the PAL_A entries have it set); read the PAL_B header word at entry + `0x10114`; skip the entry if its revision byte (bits 15:8) is below msr[1715] bits 15:8, or its family (31:24) or model (23:16) differs from `cpuid[3]`. The three PAL_B headers are family 0x1f, models 0, 1, 2, revision bytes 7, 5, 2 (7.79, 5.73, 2.25). No match ends at `0xfffcb600`.
5. msr[0] bit 21 set goes to `0xfffca720`, bit 7 set goes to `0xfffca4c0`; both skip the stop site.
6. msr[1536] read again (`0xfffca220`), bits 59:48 used as a 12-bit mask: zero selects fixed fields (r22 = `0xbfff`, r23 = 0) and goes straight on; nonzero scans for the first run of clear bits (each bit stands for two units: r26 steps by 2 to `0x18`), sets r23 to the run's first position and the run's end minus 1 into bits 17:11 of r22, and a second pass is started from `0xfffca4bc` when the run ended on a set bit and not at the top. All twelve set skips the site to `0xfffca4c0`. Only the zero mask and the single-run case were traced; the second pass adds 1 to r26 and was not followed.
7. msr[1559] read (`0xfffca346`); bits 26:22 index a table of 16-bit entries inside the image (row 12 here). The write at `0xfffca3f0` follows.

### Each msr read (grades: code established, meaning inferred, hardware value unknown)

| msr | site | branch on value? | emulator 0 | other values |
|---|---|---|---|---|
| 0 | `0xfffc9de0`, `0xfffca1c0`, `0xfffca1e0` | yes, bit 21 and bit 7 skip the stop site; revision-masked bits 13, 10, 7, 3, 16, 4 are cleared by the write-back (bit 7 only when the `cpuid[3]` revision byte is above 1, so the bit 7 skip needs a revision byte of 0 or 1); bit 22 gates the msr[1152] bit | passes | bit 21 or 7 set: skip. The generic PAL_A reset stub writes msr[0] = 0 (`0xffff8406`), so 0 is what a reset boot hands over |
| 1504 | `0xfffc9eb6` | no | read-modify-write | any value reaches the site |
| 1152 | `0xfffc9ef0` | no (bit 18 set if msr[0] bit 22) | writes 0 | any |
| 1536 | `0xfffc9f10` and `0xfffca220` | first: no. second: bits 59:48 | mask 0: the fixed value | nonzero: other r22/r23; all ones: skip |
| 1572 | `0xfffc9f50` | no | read-modify-write | any |
| 1715 | `0xfffca0b0` | bits 15:8 against the PAL_B header revision byte | 0 accepts every entry | above the header byte (5 for the model 1 PAL_B 5.73): that entry is skipped, none left ends at `0xfffcb600` |
| 1559 | `0xfffca346` | no, bits 26:22 are table index | index 0 gives zero table fields | indices 7 to 24 give nonzero entries |

What a real Madison returns for any of these is **unknown**: no source held names these registers. `cpuid[3]` also steers steps 2 and 4; its values in the model were not part of this reading.

### The values written to msr[1546]

Established from the code, no hardware naming: no read of msr[1546] with a resolvable constant index exists anywhere in the PAL (0 of the resolved reads, against 651 resolved writes; the counts in [pal-msrs.md](pal-msrs.md) agree), so there is no read-modify-write mask and no test of its bits. About 70 reads take a computed index (offsets from `0x640` and `0x6a8`, table entries, a caller-supplied register); none was shown to reach 1546, and none was excluded.

- `0x908000000000bfff` (`0xfffca3f0`) is built with `dep` instructions: bit 63 = 1; bits 60:58 = 4 (constant); bits 57:53 from the table (4, so bit 55); bits 52:46 = 0; bit 43 = 1 only when msr[1559] bits 23:22 are 1 or 2; bits 41:29 from the table (0 at index 0); bits 22:18 = r23 (run start, 0); bits 15:0 = r22 (`0x7ff` with `r26 - 1` at bit 11: run end, here 0x17). Zero elsewhere.
- `0x8940000000000000` (PAL procedure 520) is a constant: bits 63, 59, 56, 54. The loop of the first called routine puts a counter in bits 17:16 of it.
- Across the 15 msr[1546] writes with resolvable values in PAL_A 5.37 and the constants in PAL_B 5.73, bit 63 is always set, and bits 60:58 take the values 2, 3, 4 and 5; sites compose other fields with `dep` at bits 45:43, 17:16, 6:1 and 15:0. **Inferred:** msr[1546] is a command or data port whose layout depends on the command (bit 63 valid or go, bits 60:58 the command class), with the msr[1544] to msr[1547] family. **Unknown:** every field's meaning, and what the 12-bit msr[1536] mask or the msr[1559] index are physically.

### Is the site on every boot?

Reached on the normal PALE_RESET path, not created by zero reads, **only on a processor whose `cpuid[3]` has family 0x1f and model 1**: the generic search takes PAL_A 7.31 for model 0 and PAL_A 1.27 for model 2, and PAL_B 5.73 is the model 1 PAL_B. The reset stub zeroes msr[0], the FIT header and a PAL_B match are needed, and only msr[1536] bits 59:48 all set or msr[0] bits 21 or 7 set would skip it. The zero reads make the value written simple (single run, zero table fields); with a real msr[1559] index in 7 to 24 (inferred, since only those table entries are nonzero) the value differs. Whether msr[1608..1612] read zero afterwards on hardware is unknown. An emulator must return zero there to stay on the main path.

## 5. Context of every reserved-slot site

Section 4 reads one site, the first reserved M slot on the PAL_A 5.37 path (`0xfffca406`), and finds that the code after it only tests
status registers against zero. This section sets all 747 sites (702 M-unit words `0x108000000`, 45 B-unit words `0x48000000`) against that
context. One row per site, with the writes before it and the reads after it, is in [reserved-slot-sites.md](reserved-slot-sites.md). The
question behind it: for how many sites does "execute the word as a no-op" rest on the same evidence as at the verified site, and where
is that evidence missing or contradicted.

### Method and limits

- **Listing.** The Ghidra slot listing of the whole 6 MiB image (IA-64 module, every bundle) gives every instruction; a site is a slot whose
  41 bits equal the reserved word in an M position, or `0x48000000` in a B position. 702 and 45 found, the counts section 1 and the
  B-unit paragraph give. A separate standalone bundle decoder (template table, no Ghidra) finds the same 702 and 45 in the same image
  ranges, per image (generic PAL_A 1, 7.31 18, 5.37 22, 1.27 22, PAL_B 7.79 211, 5.73 211, 2.25 217; B-unit 1, 1, 1, 12, 12, 18 for the
  processor-specific PAL_A and the three PAL_B). `objdump` was not re-run for this section; its agreement with the module over the whole
  image is measured in the retools page.
- **Before the slot.** The msr writes in the 400 instructions before the site, back to the previous site, with the index register and value
  register evaluated forward over that window (constants, `movl`, `adds`, `dep`, `dep.z`, `or`; known bits tracked, so a value can be
  partly known). The state is dropped at a call, an `alloc` and an unconditional branch, because code after one is entered from
  somewhere else. An index that is a caller's register stays unresolved (`?`).
- **After the slot.** Forward in listing order, up to 110 instructions, to the next site, an unconditional branch, a call, a return or
  `rfi`. Conditional branches are passed on the fall-through side. Each msr read is followed through `extr`, `and`, `shr` and `dep`
  into the first compare or `tbit` that uses it; a read with no such use before the register is overwritten is "consumed as data". A
  loop is a conditional branch back to an address after the slot with an msr read in the loop body.
- **What this cannot see.** Effects that reach a read in another routine, code reached only by an indirect branch the trace does not
  resolve, and any read after the trace ends. "None found" below means none inside that trace, not none in the image. The index
  evaluation follows listing order, not control flow, so a value assembled in a different routine is shown unresolved, not guessed.
- **Entry sets.** Static flow from the PAL_A entry (+0x300), the PAL_B reset continuation (stub at +0x10060), the PAL_PROC dispatch (+0x10010), the two event stubs
  and, in PAL_B 5.73, the procedure 520 handler (`0xffea42a0`), following both arms of conditional branches and resolving jumps through
  a register set from `ip`. It is a lower bound ("can be reached"), not a trace of the boot: for example it misses the return to
  `0xfffca520`, so the second PAL_A 5.37 site `0xfffca626` (on the path by the reading in section 4) is added by hand.

### The verified context

The site at `0xfffca406` (section 4), as the reference: (a) a write to msr[1546] (here the only write to it; sometimes with msr[1544] before or
after), (b) `srlz.d`, (c) the slot, (d) reads of the status registers msr[1608..1612] (the five registers at `0x648..0x64c`) each compared
with zero, a non-zero value taking an error exit, and (e) no read anywhere in the following code of a register the slot could be setting
(it has no operand, so this is "no read of any command or result register the slot could be completing").

### Classes (M-unit)

| Class | Context | Sites | Against the verified context | Later code reads state the slot could change |
|---|---|---|---|---|
| V | msr[1546] write (class 4), `srlz.d`, slot, then msr[1608..1611 or 1612] each `cmp.ne` against 0 | 6 | **exact match** (the two sites per PAL_A image: `0xfffca406` and `0xfffca626`, and their counterparts) | reads; the same value with or without a change (zero required, any other value takes the error exit) |
| K | msr[1544] = 0, msr[1546] = `0x9021004d60000001`, `srlz.d`, slot, then a poll of msr[1212] until bit 14 is set, bits 13:0 compared with `0x317c` and msr[1226] with a 64-bit constant | 3 (one per PAL_B) | **differs, matters**: a poll that needs a non-zero value | **MUST SEE A CHANGE** (poll on msr[1212] bit 14; see "Sites that matter") |
| P1 | msr[1546] class 2, `srlz.i`, slot, then msr[1640] bit 54 cleared (window close), `cr.pta` restored, a write setting bit 4 of msr[1552], `srlz.i`, poll msr[1552] until bit 2 is set | 60 (20 per PAL_B) | differs, matters: a poll that needs a bit set | MUST SEE A CHANGE of msr[1552] bit 2, but a write to that register comes between the slot and the poll, so the change is explained without the slot (inferred) |
| P2 | command, slot, then msr[1416] written and polled until bit 40 is clear | 5 | differs: a poll, but a zero read satisfies it | reads; the same value with or without a change (a zero read passes) |
| R | msr[1546] (class 2 mostly, class 3 for 15, 22 with the class not resolved), `srlz.d`, slot, then msr[1545] read (PAL_B only): 86 tested, 41 returned or stored | 127 | **differs, matters**: reads a register the command may fill | reads; undecided. Tests use bit 3 (21 sites), a constant 7 (16), a constant 0 (11) or a caller-supplied value (about 38); none is shown to need a value only the slot could produce |
| S | command, slot, then msr[1600], [1601] or [1608] (caller-selected bank) read and shifted into a result or returned, not compared with a constant | 21 (7 per PAL_B) | differs, matters: a status bank read as data, not tested | reads; undecided (no expected value in the code; the value goes to the caller) |
| O | command, slot, then another msr read: msr[1058] tested (15), msr[1510], [1511], [1512] tested (9), msr[1028..1031] returned (3), msr[1779] (3), reads through a caller's index (17), msr[1536] and [1553] (one site per PAL_A, `0xfffcae86` in 5.37) | 50 | differs, matters: reads a register other than the status bank | reads; undecided (the msr[1058] and msr[1510..1512] reads are tested, the rest returned or unused; none shown to need the slot) |
| N1 | command write(s), `srlz.d`, slot, then no read before the next command or data write (msr[1544], [1546], [1600], [1084], [1558]) | 157 | **differs, matters**: no status read follows | none found |
| N2 | command write(s), `srlz.d` or `srlz.i`, slot, then no read before a branch or return | 113 | differs, matters: no status read follows | none found |
| W1 | cache or table-maintenance routines: msr[1546] earlier, then msr[1084] written last, `srlz.i` (69 + 24 + 12 with `srlz.d`), slot, then msr[1084] or msr[1546] written | 105 (35 per PAL_B) | differs, matters: no command write directly before, no read after | none found |
| W2 | the bit-54 window: msr[1553] bits 43:42, msr[1640] bit 54, msr[1730] bits 43 and 36 written, `srlz.i`, slot, then the same registers restored | 19 (the generic PAL_A site, 5 per PAL_B, 1 per processor-specific PAL_A) | differs: no msr[1546] command at all | none found |
| U | the index of the writes before the slot is a caller's register or was set in another routine, so the class is not resolved | 36 | not decided | none found in the trace; 3 sites of PAL_A 5.37 are the loop at `0xfffcdd20` (below) |

Of the 702 M-unit sites: 6 match the verified context exactly; 0 differ only in which command and status msrs they use (the nearest are the 21 S sites, which read the same banks but
compare nothing against a constant);
696 differ in a way that matters: 430 with no read after them at all (N1, N2, W1, W2, U), 198 that read a register the command could be
filling (R, S, O) and 68 with a poll (K, P1, P2). Of the 696, only K and P1 wait for a bit that a zero read does not give; P1's change is
explained by a write that precedes the poll, K's is not.

### Classes (B-unit)

| Class | Context | Sites | Later code reads state the slot could change |
|---|---|---|---|
| B0 | `srlz.i`, slot, no msr write before it in the trace (these sit in the exit paths that restore r30, r31 and pr from msr[0], msr[1641] and msr[1642], and in the `ar.unat` save and restore code) | 21 | none found |
| B1 | msr[1664] (15 of 21), msr[1283] (3) or another register written before; then `srlz.i`, slot, then branch, return or a write to msr[1282] | 21 | none found |
| BP | PAL_B 2.25 only: msr[1664] written, `srlz.i`, slot, then writes to msr[1282], [1237] and [1416] and a poll of msr[1416] until bit 40 is clear | 3 | reads; the same value with or without a change (a zero read passes) |

None of the 45 B-unit sites has an msr[1546] command before it or a status register read after it, so none matches the verified
context; the evidence for treating them as a no-op is only that the code after each is ordinary and does not depend on a result (inferred).

### Counts per image

Images in the order a model-1 (Madison) boot runs them (generic PAL_A reset, PAL_A 5.37 from +0x300, PAL_B 5.73 as SAL_B reaches it),
then the model-0 and model-2 pairs. Sites per class, M and B together:

| Class | generic A | A 5.37 | B 5.73 | A 7.31 | B 7.79 | A 1.27 | B 2.25 | Total |
|---|---|---|---|---|---|---|---|---|
| V | 0 | 2 | 0 | 2 | 0 | 2 | 0 | 6 |
| K | 0 | 0 | 1 | 0 | 1 | 0 | 1 | 3 |
| P1 | 0 | 0 | 20 | 0 | 20 | 0 | 20 | 60 |
| P2 | 0 | 0 | 2 | 0 | 2 | 0 | 1 | 5 |
| R | 0 | 0 | 40 | 0 | 40 | 0 | 47 | 127 |
| S | 0 | 0 | 7 | 0 | 7 | 0 | 7 | 21 |
| O | 0 | 1 | 16 | 1 | 15 | 1 | 16 | 50 |
| N1 | 0 | 8 | 45 | 5 | 46 | 8 | 45 | 157 |
| N2 | 0 | 5 | 33 | 4 | 33 | 5 | 33 | 113 |
| W1 | 0 | 0 | 35 | 0 | 35 | 0 | 35 | 105 |
| W2 | 1 | 1 | 5 | 1 | 5 | 1 | 5 | 19 |
| U | 0 | 5 | 7 | 5 | 7 | 5 | 7 | 36 |
| B0 | 0 | 0 | 7 | 0 | 7 | 0 | 7 | 21 |
| B1 | 0 | 1 | 5 | 1 | 5 | 1 | 8 | 21 |
| BP | 0 | 0 | 0 | 0 | 0 | 0 | 3 | 3 |
| **All** | 1 | 23 | 223 | 19 | 223 | 23 | 235 | 747 |

Which sites a processor model reaches. The generic PAL_A picks 7.31 for `cpuid[3]` model 0, 5.37 for model 1 and 1.27 for model 2
(section 4 and [pal-authentication.md](pal-authentication.md)), and each model's PAL_B is the one with the same model byte. Sites per model:

| Model (cpuid[3] model byte), images | V | K | P1 | P2 | R | S | O | N1 | N2 | W1 | W2 | U | B0 | B1 | BP | All |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 (Madison): generic PAL_A, 5.37, 5.73 | 2 | 1 | 20 | 2 | 40 | 7 | 17 | 53 | 38 | 35 | 7 | 12 | 7 | 6 | 0 | 247 |
| 0: generic PAL_A, 7.31, 7.79 | 2 | 1 | 20 | 2 | 40 | 7 | 16 | 51 | 37 | 35 | 7 | 12 | 7 | 6 | 0 | 243 |
| 2: generic PAL_A, 1.27, 2.25 | 2 | 1 | 20 | 1 | 47 | 7 | 17 | 53 | 38 | 35 | 7 | 12 | 7 | 9 | 3 | 259 |

The generic PAL_A site is shared by all three. Per model, the sites that static flow reaches from the entry points (lower bound,
class letter after each address):

- **Model 1.** PAL_A 5.37 from +0x300: `0xfffca406` V, `0xfffca626` V, `0xfffcd4d6` N1, `0xfffcd9a6` N1, `0xfffcdb06` N2, `0xfffcdd66` U, `0xfffcde56` U, `0xfffcdea6` U, `0xfffce576` U. PAL_B 5.73 reset continuation: `0xffe88ac6` N1, `0xffe88c26` N2, `0xffe88e86` U, `0xffe88f76` U, `0xffe88fc6` U, `0xffed51c6` N1, `0xffed5246` N1, `0xffed52c6` N1, `0xffed5346` N1, `0xffed5436` O, `0xffed77c6` K, `0xffed7886` U. PAL 520 handler (PAL_B 5.73): `0xffe88346` N1, `0xffe88656` N2, `0xffe88ac6` N1, `0xffe88c26` N2, `0xffe88e86` U, `0xffe88f76` U, `0xffe88fc6` U, `0xffea4366` N1.
- **Model 0.** PAL_A 7.31 from +0x300: `0xfffc38a6` V, `0xfffc8236` N1, `0xfffc8706` N1, `0xfffc8866` N2, `0xfffc8ac6` U, `0xfffc8bb6` U, `0xfffc8c06` U, `0xfffc90c6` U, `0xfffc9956` N2. PAL_B 7.79 reset continuation: `0xffdd8ac6` N1, `0xffdd8c26` N2, `0xffdd8e86` U, `0xffdd8f76` U, `0xffdd8fc6` U, `0xffe24266` N1, `0xffe242e6` N1, `0xffe24366` N1, `0xffe243e6` N1, `0xffe244d6` N1, `0xffe26856` K, `0xffe26916` U.
- **Model 2.** PAL_A 1.27 from +0x300: `0xfffd0b16` V, `0xfffd3cf6` N1, `0xfffd41c6` N1, `0xfffd4326` N2, `0xfffd4586` U, `0xfffd4676` U, `0xfffd46c6` U, `0xfffd4ec6` U. PAL_B 2.25 reset continuation: `0xfff38ac6` N1, `0xfff38c26` N2, `0xfff38e86` U, `0xfff38f76` U, `0xfff38fc6` U, `0xfff397c6` U, `0xfff75686` N1, `0xfff75706` N1, `0xfff75786` N1, `0xfff75806` N1, `0xfff758f6` O, `0xfff77b36` K, `0xfff77bf6` U.

The known order inside PAL_A 5.37 (section 4 and the reading below): `0xfffca406` (V), then the call at `0xfffca51c` into `0xfffcd850`
(`0xfffcd9a6` N1, `0xfffcdb06` N2, then three sites per pass for eight passes at `0xfffcdd66`, `0xfffcde56`, `0xfffcdea6`), the return to `0xfffca520`,
`0xfffca626` (V). The three loop sites are U above only because the registers holding 1544, 1546 and 1600 are set earlier in the
routine (`0xfffcdb6c` to `0xfffcdb7c`); read by hand, each pass writes msr[1544] (`0x001`, `0x101`, ..., `0x701`), msr[1546] (class 5 value
`0x954...` with an 11-bit field of `0xff`, `0x1ff`, ..., `0x7ff`) and msr[1600], then `srlz.d`, the slot, a read of msr[1559] for an
index, then two more command groups (class 3 values, msr[1544] with the pass number in bits 10:8) each with its own `srlz.d` and slot. None of them reads a status register.

### The second PAL_A 5.37 site, `0xfffcd9a6`

Second reserved word that the model reaches, in the routine at `0xfffcd850`. Context, read in Ghidra: msr[1544] = 0 and msr[1600..1603] = 0
(`0xfffcd870`), msr[1608..1611] and msr[1616..1619] = 0 (`0xfffcd8c0`), then in one instruction group msr[1624..1627] = 0 and
**msr[1546] = `0x8d20000000000000`** with bit 43 set when msr[1559] bits 23:22 are 1 or 2 (`0xfffcd930` to `0xfffcd990`), `srlz.d` (`0xfffcd996`), the
slot in the bundle at `0xfffcd9a0`. It is a command write, class 3 (bits 63, 59, 58, 56 and 53; the verified site writes class 4), not a pure
clear. After the slot: msr[1559] read for an index, a second msr[1546] write (class 5 `0x9500000340000000` + `0x7ff`, bit 43 again), the same sixteen clears
again, msr[1544] = 0, `srlz.d` and the next slot. No status register is read and nothing is compared between the two slots, so it is class N1, not V.
Nothing after it tests state the slot could have changed inside the routine; the status registers it clears are tested later by the V site at `0xfffca626`, after
another command and another slot, so a dependence of those reads on this slot is neither shown nor excluded. The sixteen
zero writes look like an initialisation of a command and status register file before commands are issued (inferred; the loop later
writes msr[1600] non-zero, so at least that one is a command or data register, not status).

### Sites that matter

1. **K: the msr[1212] poll (3 sites; MUST SEE A CHANGE).** PAL_B 7.79 `0xffe26856`, 5.73 `0xffed77c6`, 2.25 `0xfff77b36`. After msr[1544] = 0, msr[1546] =
   `0x9021004d60000001`, `srlz.d` and the slot the code loops reading msr[1212] (index `0x4bc`) until bit 14 is set, then requires bits 13:0 of msr[1212] to
   equal `0x317c` and msr[1226] (`0x4ca`) to equal a 64-bit constant. In 5.73 and 2.25 the constant is `0x82518167826f836c` in all three revision arms. In 7.79 it is `0x833e80ab8096833e` for
   a `cpuid[3]` revision byte (0 reads as 1) of 3 or below, `0x82518167826f836c` for 4 to 8, and `0xbad` in both places above 8 (the compare chain is read from the listing: inferred for which arm a given revision takes). A mismatch is not fatal: it sets msr[1640]
   bit 59 (`0xffe268c6` to `0xffe268e0`) and goes on with a second command (`0x9020000000000001`, `srlz.d`, a second slot). A model that reads zero from msr[1212] loops forever at
   `0xffe26860`. The site is on the PAL_B reset continuation (+0x10060): the three ways through the msr[1225] test (`br.ia` after reset left it at 4, the msr[1224]
   loaders, or neither) rejoin at the common exit `0xffe26670` (5.73 `0xffed75e0`, 2.25 `0xfff77950`), which has no conditional skip before the site. Grade: reachable by static
   flow established; "every pass of the reset continuation" inferred, since the PAL_A to PAL_B hand-off was not re-traced. Whether the slot or the msr[1546] write alone provides the
   response: **unknown**. The constants are not in the data the loaders write: the two loaders at `0xffde68f0` and `0xffde8030` (7.79) write indices 1200..1211, 1216..1223,
   1224 (256 values), 1225 and 1232..1235 only; none of their 281 values and none of the 282 words of the `br.ia` tables at `0xffe254b0` and `0xffe25d90` has either 64-bit
   constant or bits 13:0 equal to `0x317c`, and neither constant occurs anywhere in the image as bytes (established, 7.79). So the check is a known-answer test whose
   expected values live in the check itself. What msr[1212] and msr[1226] are: **unknown**.
2. **P1: msr[1552] polls (60 sites).** The window routines, for example PAL_B 5.73 `0xffea0fe6` to the poll at `0xffea1050`, set bit 4 of msr[1552] after the slot and then loop until
   bit 2 reads set. A zero read hangs there. The write that precedes the poll is the more direct cause, so the slot is not required to explain the change (inferred).
3. **R: msr[1545] after a command (127 sites).** This is the result register of the msr[1544..1547] group in every reading so far (inferred, no source names it). 56 of the tested sites
   compare it with a constant or a caller-supplied value. The values asked for are not shown to be produced only by the slot; a model that stores what is written to msr[1545]
   satisfies some and not others. Not resolved here.
4. **S and O (71 sites).** Same question for reads that are returned or compared in the caller. Not resolved.
5. **Not slot-related, but needed to get past the slots: the msr[1730] loops at `0xfffcb2c0` and `0xfffcb390` (PAL_A 5.37; 7.31 and 1.27 counterparts not read).** Loop 1 exits when msr[1730] bits 3:0 are `0xf`,
   loop 2 when bits 11:8 are `0xf`; each pass writes msr[1728] (bit 48 set and 49 clear in loop 1, the reverse in loop 2) and strobes msr[1730] bits 42, 48 and 49 then clears bit 48. Both loops
   are skipped when msr[0] bit 22, msr[1152] bit 18 or msr[1572] bit 18 is set (`0xfffcb260` to `0xfffcb2bc`), and continue at `0xfffcb460` and `0xfffcb4c0`. A stepped count or training loop
   (inferred; no source names the bits). It needs a non-zero read; a zero read hangs. The msr[1416] bit 40 poll at `0xfffcd7d0` is different: it waits for the bit to be clear, which a zero read satisfies.

### The msr[1546] command values across all sites

650 of the 702 M-unit sites have a write to msr[1546] before them in the trace; 52 do not (19 W2 and 33 U). Bits 60:58 are the command class
(inferred: bit 63 is set in every value seen, so it is a valid or go bit, and the class is the field the code assembles with `dep`; no source names any of this). Of the 650,
the class is known for 589 and was not resolved for 61 (the value comes from a caller's register).

| Class (bits 60:58) | Sites | Fully known values | Fields that vary | After the slot (class letters) | What later code requires |
|---|---|---|---|---|---|
| 2 | 270 | `0x8940000000000000` (98: PAL_B windows, PAL 520 handler, PAL_A 5.37 `0xfffceee6` and its 1.27 counterpart), `0x8922000000000000` (9) | the other 163 are partly known: bit 63 and the class known, bits 51:44 and 27:0 zero, bits 55:52, 43:40, 39:32 and 31:28 assembled from registers | R 90, N1 47, P1 60, O 36, S 21, N2 9, P2 4, W1 3 | msr[1545] tests (bit 3, constants 7 and 0, a register), msr[1552] bit 2 set, msr[1416] bit 40 clear, the bank 1600/1601/1608 returned |
| 3 | 261 | `0x8d40000000000000` (15) | partly known values of the same shape as class 2; `0x8d20000000000000` + bit 43 at PAL_A 5.37 `0xfffcd9a6` | W1 102, N1 72, N2 57, R 15, O 12, U 3 | msr[1545] bit 3 test (15 sites); the rest need nothing |
| 4 | 9 | `0x9021004d60000001` (3, K); `0x9020000000000001` is the failure arm of K, read by hand | PAL_A: bits 57:53 from a table at `0xfffcce70`, bit 43 from msr[1559], bits 41:29 from the table, 22:18 run start, 15:0 run end | V 6, K 3 | V: msr[1608..1612] compare 0. K: msr[1212] bit 14, `0x317c`, msr[1226] constant |
| 5 | 49 | none fully known | partly known; by top 16 bits and low byte: `0x9490..034000..` (5), `0x9700..2xx` (6), `0x9720..067f` (3), `0x9740..3xx` (8), `0x9780..x3ff` with x = 0 to 3 in bits 9:8 of the second word (12), `0x97c0..01d0003000` (3), `0x97e0..7f` (12) | N1 30, N2 17, O 2 | none (O: msr[1536], msr[1553] and a bit-1 test) |
| not resolved | 61 | none | value from a caller's register or computed in another routine | R 22, N2 30, N1 8, P2 1 | R: msr[1545] tests (constant 0 or 7); others none |

The status registers the V class reads are msr[1608..1612] (the bank at `0x648`). Across the image msr[1600..1627] are read only by the S class (data, 21 sites) and the V class; the sites otherwise write them (the sixteen zero writes at `0xfffcd870` and `0xfffcda36`, the clears at `0xffe23e36`). Every meaning in this table is **inferred**; none is named by a source.

### Cross-check against Intel's SR870BN4 BIOS

Package `SR870BN4_1001_SUP3.ZIP`, file `S870BN4C.BIN`, sha256 starting `fb422439` (5,111,342 bytes). Method: locate each SGI PAL image in the file by unique 64-byte chunks,
compare the aligned bytes, scan the aligned region with the standalone bundle decoder. Established:

| Image | Intel bytes | Reserved M slots | B slots | Notes |
|---|---|---|---|---|
| PAL_A 5.37 (0x67c0 bytes) | identical | 22 | 1 | same offsets as the SGI image |
| PAL_A 1.27 (0x6ce0 bytes) | identical | 22 | 1 | same offsets |
| generic PAL_A (0x7fc0 bytes, from `0xffff8000`, last 0x40 bytes left out) | identical except 8 bytes at image offsets 8 to 15 | 1 | 0 | the site is the same; the section 1 text "byte-identical" holds apart from those 8 bytes |
| PAL_A 7.31 | not the same image: 611 of 1,712 sampled 16-byte steps match | | | consistent with Intel holding PAL_A 7.46; not compared |
| PAL_B 2.20 against SGI 2.25 | 110,910 of 634,816 bytes differ over the 0x9afc0 bytes at the best alignment (code that moved inflates this) | 217 | 18 | 166 of the 217 M offsets and none of the 18 B offsets coincide; the totals and the class counts (V 0, K 1, P1 20, P2 1, R 47, S 7, O 16, N1 45, N2 33, W1 35, W2 5, U 7, B0 7, B1 8, BP 3) equal 2.25's |

The Intel PAL_B 2.20 was classified by the same listing and trace, with the image's own length (not established) replaced by the 2.25
length and the base address of 2.25. The poll at msr[1212] is present there once (K 1). PAL_B 7.79 and 5.73 were not compared: no region of the file matched more than about a quarter of their sampled steps. The slot therefore occurs in Intel's own shipped PAL images, in the same contexts, including the msr[1212] poll in 2.20 (established for the three PAL_A images and 2.20 as counted above).

### Grades

- **Established:** the 747 sites, their addresses, the preceding writes and following reads as listed, field patterns where the evaluation resolved them, the Intel byte comparison and
  the standalone counts, the msr[1212] and msr[1226] constants and what the loaders and tables contain.
- **Inferred:** the class letters, reading msr[1546] as a command port with bits 60:58 as a class, msr[1545] as its result, msr[1608..1612] as its status, the entry sets, "reachable
  on every pass" for K, and every statement of what a register is.
- **Unknown:** what the word does; whether the slot or the preceding write causes the response the K and P1 polls wait for; what msr[1212], msr[1226], msr[1552] and the
  msr[1730] fields are; the later reads of R, S and O sites (not resolved); behaviour of sites reached only through the PAL_PROC dispatch (indirect, not traced).
  What would settle the polls: a Madison or McKinley document that names the msr file, or a trace from hardware, which this program does not take without approval.

## Questions left (unknown)

1. What the two reserved encodings do on Itanium 2 and Madison, and whether anything depends on their result (item 1).
2. Which of the vectors at `0xffffff90` and `0xffffffa0` is MCA and which INIT, which predicates and registers each event leaves, where PMI is (item 2).
3. The consumer of the 142-record tables and the full callee contract of `br.ia` (item 3).
4. Whether a Madison document (or revision -028 of 251141) defines PAL-only opcodes: not in the revisions read.
5. Whether the reserved slot or the msr[1546] write causes the response that the msr[1212] poll (3 sites) and the msr[1552] polls (60 sites) wait for, and what msr[1212], msr[1226] and the msr[1730] fields are (section 5).

## Review

Independent review of chips commit `adac12b` (this page), examined at that commit. The reviewer did not write the page. Method: load `shub1snprom.bin` (SAL 5.04, `snprom-10.54-70399`) through the retools Ghidra export with the IA-64 module, dump every slot (1,155,916 lines), and recount from that listing with a fresh script, not the page's own tables; read the SDM table cells from rendered pages (vol 3 pdf pages for printed 3:345, 3:349 and 3:350) and the legend pages as text; read the patent text on Google Patents (the Library had no patent root to try first). Branch targets, immediates and bit positions were compared with the listing; `objdump` was not needed.

**Confirmed (re-read, established).**

- Reserved M slot and B-unit slot. Table 4-43 (printed 3:345): opcode 0, x3 = 0, x4 = 1 has `srlz.i` at x2 = 3, the "1-bit Ext" entry at x2 = 0, and x2 = 1 and x2 = 2 are the dark purple cells (reserved if PR[qp] is 1). `0x108000000` decodes to x2 = 2, x4 = 1, y = 0, qp = 0. Table 4-46 and M48 (3:349): `nop.m`/`hint.m` are x2 = 0 only. Table 4-48 (3:350): x4 = 9, x2 = 0 (`x6 = 9`) is a cyan (reserved if PR[qp] is 1, B-unit) cell between `rfi` (x4 = 8) and `vmsw.1` (x2 = 1); `0x48000000` is x4 = 9, x2 = 0, qp = 0. The legend (3:294 to 3:295, 3:299) says these fault if PR[qp] is 1 and are nops if 0; PR0 reads as 1 (vol 1, 1:26). So both slots, with qp = 0, raise Illegal Operation architecturally. Conclusion stands.
- Site counts, recounted from the Ghidra listing by component (FIT address and size): M slot 702 = generic PAL_A 1; 7.31 18; 5.37 22; 1.27 22; PAL_B 7.79 211, 5.73 211, 2.25 217. B-unit slot 45 = 7.79 12, 5.73 12, 2.25 18, one each in the three specific PAL_A images, none in the generic. The nearest preceding non-nop instruction is `srlz.d` 501 times and `srlz.i` 201 times for the M slot, and `srlz.i` 45 of 45 for the B slot. Each M-slot bundle is `nop.m 0x1fffff ;;`, slot, `nop.i 0x1fffff ;;`: the slot is alone in its instruction group.
- Preceding-write classes in 7.79: the msr[1546] family dominates and 5.73 has the 6/6 split of msr[1545] and msr[1547]; 2.25 has six more sites, all in the msr[1546] class (this review: 141/147). Next-access counts (read of msr[1545] 40, write of msr[1640] 26, read of 1608 5, 1058 5, write of 1546 8, 1544 5) reproduce.
- Procedure 520 (5.73): `0xffea42a0` does what the page says, in that order (`rsm 0x6000`, `cr.pta` bit 0 into p11, msr[1640] bit 54, msr[1544] = 0, msr[1546] = `0x8940000000000000`, `srlz.i`, slot at `0xffea4366`, close, then the five calls through `ip`-relative `b0` to `0xffe88250`, `0xffe885a0`, `0xffe88810`, `0xffe88970`, `0xffe89040`). The first routine's four-pass loop, msr[1084] (`0x43c`) save and restore, the slot in routines 1, 2 and 4 and none in 3, and the `mov r8=0` with p9/p13 overrides all re-read. SAL_B's call sets `r28 = 0x208` at `0xffa9b586`, and the dispatch at `0xffe9e1c6` compares it.
- Side finding: the 251110-002 Table 4-4 (printed 4-4) has the `mov from msr[r0]` (36) and `mov to msr[r0]` (35, 46) rows; the text of -001 and -003 has no `msr` string. True as stated.
- Event entry: the vector bundles, their targets, the register saves into msr[0], 1641, 1642 and 1643, the msr[1640] bit 56 test and the error exit at `0xffff8120` (psr.mc set, ic and i clear, `rfi`) match. PAL_B `+0x10080` for `0xffffff90` (`movl` at `0xffff8d76`) and `+0x10070` for `0xffffffa0` (`0xffff9096`) match, and the PAL_B stub bundles and targets match in all three images. The HDM 251109 Table 5-7 and section 5.3.2 text and printed page 5-6 match; SDM vol 2 pages 2:296 and 2:297 (PSR.mc set by hardware, XR0 and bank 0 GR24 to GR31) and Figures 11-3 and 11-4 at 2:284 and 2:285 match.
- `br.ia` rows: all 17 `br.ia` slots in the image are as counted (15 in PAL, two outside). Row 1 reproduced in 7.79: `r9` = `0x80000000ffffffe0` into `b1`, `b0` = `r12` + `0x20b0` = `0xffe26670`, `r2` = `r12` + `0xef0` or `+ 0x17d0` (`0xffe254b0` or `0xffe25d90`) chosen on the revision byte (above 3 takes the larger), `r3` = 1, `r5` = 0, `r1` = `0x99` at `0xffe252ac` untouched on the taken path, return code `cmp.eq p0,p2=0,r1` then msr[1640] bit 59. The `+0x10090` stub in each PAL_B goes to that return address (`0xffe26670`, `0xffed75e0`, `0xfff77950`). Row 2 is `ssm 0x400000` (bit 22 is psr.di), `srlz.d`, then `br.ia b0`, two branches to the failure exit. Row 3 (`(p47) b4`) is data.

**Mechanical fixes made in this review.**

- `pal-msrs.md` said both generic vectors go to PAL_B + `0x10080`; now `0xFFFFFF90` goes to `+0x10080` and `0xFFFFFFA0` to `+0x10070` (as `boot-sequence.md` already had).
- "Eight copies of the save block": there are four per path, and each copy re-establishes the p1/p2 pair that selected it, so the dispatch preserves p1 and p2 and needs no entry value. The saved `pr` is read after the NaT tests have overwritten p1 and p2. The saves of r29 to r31 are predicated on not being NaT.
- "Each PAL_B target starts `mov b0=r31`": true for the `+0x10080` target; the `+0x10070` target begins `mf` and has `mov b0=r31` in the next bundle. The `+0x10060` target in 5.73 and 7.79 starts with `alloc`, and in 2.25 it is nop bundles and moves of b0 to b7, then `alloc` at `0xfff74fc0`. Text corrected.
- Second `br.ia` row: `r2` is not "not set"; it holds the same value as the operand (`b0` is loaded from it). `r3` and `r5` are not set (the frame is stacked registers, `alloc 10,8`).
- Procedure 520: the read of msr[1536] that sets p9 is after all five calls, not after the first two slots.
- Table description at `r2`: 282 eight-byte words after the 16-byte header, not 141 sixteen-byte records (see below).
- The preceding-write class table is annotated as dependent on the index trace (next item).

**Findings that change a value or a verdict.**

1. **The `r2` tables are the msr[1224] loader data (changes "unknown").** In 7.79 the loader at `0xffde68f0` (chosen for revision bytes 4 to 8) writes 256 values to msr[1224]; each has its index in bits 47:40 and a payload in the low bits. The table at `0xffe25d90` (the `br.ia` table for revision above 3) equals those 256 values word for word, 256 of 256 (read from the image bytes and from the `movl` constants). The table at `0xffe254b0` (revision 3 or less) has the same layout but is mostly payload-less: 232 of its first 256 words are just the index in bits 47:40, 110 equal the 256 values the other loader (`0xffde8030`, chosen for revision 3 or less) writes, 24 are non-blank and different. So the page's statement that the table does not match the 256 msr[1224] writes was wrong, and it is established from bytes that the special `br.ia` is handed the same 256-entry structure that the PAL otherwise writes through msr[1224] with msr[1225] = 1. That the two routes load the same hardware structure is **inferred**; what the structure is stays **unknown**. The loader and the table are both selected on the `cpuid[3]` revision byte, with limit 3 in both. (Checked in 7.79 only; 5.73 has a single loader and tables with `0x8e0` spacing, not compared.)
2. **Patent reading (inferred, partial).** US 6,542,981 B1 is titled "Microcode upgrade and special function support by executing RISC instruction to invoke resident microcode". It describes, before `br.ia`, one branch register set to a function number, another to a return address and one MSR to a special value, the processor checking the MSR, validating the function, authenticating and decrypting the code and storing it in processor memory, an error code set on failure and execution continuing at the return address. It names no general register, no pointer to a data table and no register that receives status. First row against that: operand register holding a constant (`b1`), return address in `b0`, an MSR (msr[1225] = 4 from the reset stub) tested around it: matches. A pointer to a 2272-byte data table in `r2` and a status in `r1` are not in the patent; the table's equality with the msr[1224] loader values (item 1) makes the "load a table of microcode-like data" reading plausible, but `r1` as status and `r2` as pointer are this page's inference and nothing more. The patent's own wording says a payload is found at addresses the processor knows, not through a register. Grade: inferred; no document says what Madison does.
3. **Architectural semantics of `br.ia` the page omits (established, SDM vol 3 `br`, printed 3:20 to 3:21).** The target is `BR[b]{31:0}` relative to CSD.base, so `b1` = `0x80000000ffffffe0` enters IA-32 at EIP `0xffffffe0` with PSR.is set; a qualifying predicate other than PR0 raises Illegal Operation; PSR.di = 1 raises a Disabled Instruction Set Transition fault; dirty stacked registers raise Illegal Operation; the frame is forced to zero; `b0` is not read. Consequences: the row 3 `br.ia (p47) b4` could only fault architecturally, which supports "data"; row 2's `ssm 0x400000` (psr.di) before the `br.ia` is consistent with a deliberate fault probe, as the page says; and in row 1 the code at `0xffe26670` clears ar.eflag, ar.csd, ar.ssd, ar.cflg, ar.fsr and ar.fir after the return, the IA-32 application registers a real transition would disturb. That last point is a code fact (read) and its purpose is inferred.
4. **Preceding-write statistic is heuristic.** The page's 158 of 211 (137 + 12 + 9) was not reproduced. Tracing the index only along straight-line code gives 150 (130 + 12 + 8); letting the trace cross branches, as the page's counts seem to, gives 162 (141 + 12 + 9). Unresolved sites are 8 here. In every variant the msr[1544..1547] family is 71 to 77 per cent of the 211 and the ordering of the classes is unchanged. Claims should quote the range.
5. **PALE entry predicates.** The "stale predicates" worry in the entry list does not apply (see fixes); the entry-state requirement list can drop p1 and p2.

**Not checked.** The 5.73 and 2.25 `br.ia` registers beyond their `b0`/`r12` offsets (they match the `+0x10090` stubs); the SDM vol 2 Table 3-2 footnotes and sections 11.4 and 11.5 text beyond the page numbers; the patents other than 6,542,981 (and 7,660,977, not re-read); `ski` and binutils tables; PAL_B 7.79 first-row reachability and the claim about Intel's SR870BN4 PAL (from another page); whether `0xffff8210` is entered; the five 520 routines past the slot positions. Hardware behaviour of either reserved encoding on Itanium 2 or Madison remains **unknown**.

**Grades.** Architectural statements (reserved cells, fault rule, `br.ia` semantics, PR0) are **established** by SDM rev 2.3. Site counts, operand values, table equality and code order are **established** (image). The reading that the reserved slots complete the msr command sequence, that the two `br.ia` routes load one structure, and the patent mapping are **inferred**. Nothing about what Madison does is established.

**Cleared scope.** Reserved-encoding verdict and counts, the 520 sequence, the generic PAL_A vector reading and the PAL_B stub targets, and the row 1 and row 2 register layouts, as corrected above.

## Review (PAL_A 5.37 first reserved slot)

Independent review of chips commit `612b72b` (section 4), examined at that commit. The reviewer did not write the page. Method: load `shub1snprom.bin` (`snprom-10.54-70399`, sha256 starting `51ccf9ad`) through the retools Ghidra module (retools main), dump every slot, and re-read the entry path from `0xfffc9dc0` to the slot and the code after it from that listing, with scripts that do not use the page's tables; decode the bundle words from the image bytes; compare the 5.37 image with the Intel package. `objdump` was not needed.

**Confirmed (established).**

- Stop site. The bundle at `0xfffca400` has template 0x0b; slot 0 is `nop.m`, slot 1 is the word `0x108000000` (x2 = 2, x4 = 1, every other field 0), slot 2 is `nop.i`, and the qp field of all three is 0. It follows `mov msr[r27]=r12` (`0xfffca3f0`, r27 = `0x60a`), a stop, then `srlz.d`, `nop.i` and `nop.m` in one group, a stop, then the slot with its `nop.i` in a group of their own. The slot is not alone in its group: `nop.i` shares it.
- After the slot: msr[1558] (`0x616`) read, bit 13 cleared, written back (`0xfffca410` to `0xfffca430`); msr[`0x648`] to msr[`0x64c`] read, the first four compared with 0 in r15 and the fifth in r16, any difference branching to `0xfffca690`. That routine calls `0xfffcd6f0`, sets msr[1416] bit 53, msr[1084] bit 8 and msr[1640] bit 62, and goes to `0xfffcb260`.
- msr[0]: `cpuid[3]` revision byte above 1 clears `0x2488`, above 3 clears `0x10010` (unsigned compares at `0xfffc9e1c` and `0xfffc9e6c`); the masked value is written back at `0xfffc9ed6`; bit 22 of it gates the msr[1152] bit 18 (`0xfffc9ee6`); bit 21 goes to `0xfffca720` and bit 7 to `0xfffca4c0` (`0xfffca1cc`, `0xfffca1ec`). The reset stub writes msr[0] = 0 at `0xffff8406`.
- Pure read-modify-write: msr[1504] (bits 58, 19), msr[1152] (bit 18, conditional), msr[1536] first access (bit 15), msr[1572] (bit 15), msr[1558] (bit 13 cleared). None is tested.
- msr[1536] bits 59:48: `extr.u` at `0xfffca22c`, zero gives r22 = `0xbfff`, r23 = 0, r26 = `0x18`; nonzero runs the scan loops; no clear bit among the twelve exits to `0xfffca4c0`.
- msr[1715] bits 15:8 (`0xfffca0b0`, `0xfffca0ec`) is compared with the PAL_B header revision byte by signed `cmp.lt` at `0xfffca130`: 0 skips nothing, a value above 5 skips the 5.73 entry, and no entry left goes to `0xfffcb600`. The three header words, read from the image, are `0x1f000779`, `0x1f010573`, `0x1f020225` (family, model, revision byte 7, 5, 2).
- msr[1559] bits 26:22 (`0xfffca37c`) index 16-bit entries: the base is `0xfffcce70`, the first load is that entry (value 4, so bit 55 of msr[1546]) for every index, the second is at `2 * (index - 7)` from it. Entries are zero for index 0 to 6 and 25 up, and nonzero for 7 to 24. Bit 43 is 1 for index bits 1:0 equal to 1 or 2.
- The composition of `0x908000000000bfff`: the `dep` fields at `0xfffca3c0` to `0xfffca3ec` give bit 63, bits 60:58 = 4, bits 57:53 = 4, bits 52:46 = 0, bits 41:29 from the table (0), bits 22:18 = r23 (0) and bits 15:0 = r22 (`0xbfff`); `r22 = 0x7ff` with `0x17` at bit 11 gives the same value. Every field position and width in the page matches.
- Entry state: FIT pointer at `0xffffffe0` points at a header with `_FIT_` and C_V set; entries 4, 5, 6 are PAL_A 7.31, 5.37, 1.27 (type 0xe, C_V set) and entries 1, 2, 3 are the PAL_B images (C_V clear). The 5.37 entry is 0x67c units of 16 bytes, which is the 0x67c0 bytes of the Intel comparison.
- The Intel package: `S870BN4C.BIN` (sha256 starting `fb422439`, from package `SR870BN4_1001_SUP3.ZIP`) holds the 0x67c0 bytes of the 5.37 image byte for byte (compared from the image's first byte to its last, and no further), the slot's bundle included.

**Mechanical fixes made in this review (section 4).**

- The instruction-group context is now exact (a stop between the msr write and `srlz.d`; the slot shares its group with a `nop.i`).
- The bit 7 skip needs a `cpuid[3]` revision byte of 0 or 1, because the write-back clears bit 7 above that.
- The PAL_B entries have C_V clear, so no PAL_B checksum runs.
- The msr[1536] scan: it looks for the first run of clear bits, each bit standing for two units, and the page said only "a run of bits". The second-pass loop adds 1 to r26, which makes it odd while the compare is against `0x18`; only the zero and single-run cases were traced and the page now says so.
- "Never read anywhere" is narrowed to reads with a constant index.
- "Reached on every reset boot" is narrowed to family 0x1f, model 1.

**Findings that change a verdict.**

1. **Reachability is per processor model.** The generic search (`0xffff8636` to `0xffff869c`) compares the image header's family and model with `cpuid[3]`. PAL_A 5.37 is the model 1 image (header word `0x1f010537`); model 0 runs 7.31 and model 2 runs 1.27, each with its own copies of the same pattern. A model of another processor never reaches this site.
2. **Computed-index reads exist (changes "established").** About 70 `mov rN=msr[rM]` reads take their index from an `add`, a table load or a caller register (for example `0xffe07ab0`, `0xffde3510`, `0xffde4f60`). The ones read in context add to `0x640` or `0x6a8`, or load from the same 16-bit table as the 5.37 site; none was shown to give 1546 and none was excluded. Only the constant-index reading is established.
3. **The status-bank pattern (new evidence, inferred).** The PAL_B 7.79 routine at `0xffde3430` writes msr[1544] and msr[1546] with the same field layout as the 5.37 value, runs `srlz.d`, the slot at `0xffde3466`, then reads five msr from the bank selected by two bits of an argument (`0x640`, `0x648`, `0x650`, `0x658`, five each), and returns them. The 5.37 site reads the second bank, `0x648` to `0x64c`, and tests for zero. So the msr[1546] write acts like a command and msr[1608..1612] like its status; the slot lies between them.

**Grade for "the slot can be treated as a no-op ordering point": inferred, not established.**

- Established: the slot has no named register operand; its group holds only `nop.i`; the code after it tests only msr[1608..1612] (and predicates set before it) and reloads every general register it compares; the slot executes with qp = 0 on the normal path, so a model must not fault on it.
- Not established: that the slot does nothing. The encoding is architecturally reserved, so nothing defines its effects, including any implicit register, predicate or msr write. It sits between a command write and its status read in every instance checked, which is also what a trigger or completion point would look like.
- What a model can do on this evidence: execute it without a fault and without changing a general register, and return 0 for msr[1608..1612] so the path continues. That is a sufficient behaviour for this path, grade inferred. It is not what the hardware does (unknown), and a non-zero status on hardware would take the error exit.

**Not checked.** The second slot at `0xfffca626` and the code at `0xfffcd850`; the multi-run second pass of the msr[1536] scan; the 15-write statistic over msr[1546] values in PAL_A 5.37 and PAL_B 5.73; whether other entries (events, INIT) reach the `0x300` entry with msr[0] non-zero; the origin of the msr[1715] and msr[1536] values on hardware (unknown).

**Cleared scope.** The stop site and its context, the code after it, the per-register reads and the table, the msr[1546] composition, and the Intel byte match, as corrected above. The no-op reading is cleared as inferred only.
