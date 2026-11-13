# R5000: NEC VR5000 processor contract

This page covers the MIPS R5000 processor line as the NEC VR5000 and VR5000A user's manual and the MIPS overview describe it: the identity words, the reset entries, the Config, Status, PageMask, LLAddr and FCR31 fields, the caches and their CACHE operations, and what is unknown. The constants are in [devices/r5000_identity/registers.toml](../r5000_identity/registers.toml) and [devices/r5000_cp0/registers.toml](../r5000_cp0/registers.toml), generated to [devices/r5000_identity/registers.md](../r5000_identity/registers.md) and [devices/r5000_cp0/registers.md](../r5000_cp0/registers.md).

This is the processor's interface, not an SGI board's. Nothing here was read from silicon or from a running machine. The observed identity words come from one public `hinv` capture of an O2 and are graded inferred.

## Sources and grades

- NEC, *VR5000/VR5000A 64-/32-bit Microprocessor User's Manual*, U11761EJ6V0UM00, sixth edition, April 2001. It covers the µPD30500 and µPD30500A. Page numbers below are from that edition. Its facts are established for those parts. Whether a given SGI assembly carries one of them is not established. A legible part marking or a primary fitment record would settle that.
- MIPS Technologies, *MIPS R5000 Microprocessor Technical Backgrounder*, an undated 13-page overview. Its pages 1 to 9 agree with the manual on the core, cache, TLB, ISA and clock interface facts on this page.
- *MIPS IV Instruction Set*, revision 3.2, SGI 007-2597-001, September 1995. Only its identity was checked. Per-instruction rounding and exception cases are not taken from it.
- One public `hinv` capture of an O2 (R5000 180 MHz): `CPU: MIPS R5000 Processor Chip Revision: 2.1` and `FPU: ... Revision: 1.0`. It prints revision numbers only, so the full PRId and FCR0 words are composed with the manual's implementation byte and graded inferred. The earlier text cited Usenet owner reports with no message identifiers; those could not be found and are not relied on.

Facts in this page are the manual's or the overview's unless marked otherwise. An inferred grade means a reported value, not a manual statement.

## Identity

- PRId is CP0 register 15. Its implementation byte, bits 15:8, is `0x23` in the manual. Established. The revision byte is bits 7:0, a major nibble and a minor nibble. Established. The manual reserves bits 31:16. Established.
- The O2 `hinv` capture gives chip revision 2.1 and FPU revision 1.0, which with the implementation byte `0x23` compose to PRId `0x00002321` and FCR0 `0x00002310`. Inferred. FCR0 is the read-only floating-point identity register. The capture does not give its field layout, so none is taken from it. This is one capture, not a promise for every part.
- The manual's revision numbers do not identify die changes. Unknown: the silicon errata publication the manual's history refers to has not been located, so the observed revision's errata status is open.

## Address space, ISA and clocks

- The ISA is MIPS IV, with MIPS I to III compatibility (manual section 6.2.2, printed page 104) and 64-bit integer registers. Established (manual).
- The physical address space is 36 bits. Extended user addressing covers 40 bits. With extended addressing off, the 32-bit segment and privilege view applies. Privileged and unmapped segment encodings follow the manual's chapter 6, not a blanket mask. Established (manual).
- The manual's feature list gives a 200 MHz core for the µPD30500-200 (250 MHz for the 30500A-250) and an external bus up to 100 MHz (printed page 2). Established (manual). That is the processor's interface limit, not an O2 bus clock.
- The overview says multiprocessor hooks exist, but the first production version lacks that support. Overview only; the overview could not be located in the Library for this verification, so this is unverified.
- The manual's EC field gives processor-to-system divisors of codes 0 to 6 as 2 to 8. The overview describes multipliers of 2, 3 and 4. The two sources do not agree on the later ratios, so only the manual's table is recorded as its own claim. Unknown for ratios above 4 until a source settles them.

## Joint TLB

- The TLB has 48 entries, each mapping an even and an odd page. Established (overview and manual).
- Page sizes run from 4 KiB to 16 MiB in factors of four. The PageMask field is bits 24:13, and its legal values are in the table below. Established (manual page 126, Table 6-9). The manual leaves other field patterns undefined.

| Page size | PageMask field value |
|---|---|
| 4 KiB | `0x00000000` |
| 16 KiB | `0x00006000` |
| 64 KiB | `0x0001e000` |
| 256 KiB | `0x0007e000` |
| 1 MiB | `0x001fe000` |
| 4 MiB | `0x007fe000` |
| 16 MiB | `0x01ffe000` |

- Cold reset sets Wired to zero and Random to 47, the top of the 48-entry range. Established (manual pages 161–163).

## Reset entries

- **Cold reset** starts at `0xffffffffbfc00000`, an unmapped, uncached address. It sets ERL and BEV and clears SR. Wired and Random are set as above. Other values are undefined, except the Config fields the manual loads from the boot mode stream. Established (manual pages 161–163).
- **Soft reset** uses the same vector. It saves the restart address in ErrorEPC and sets ERL, BEV and SR. Other register contents are kept. The cache and bus state machines reset, and cache and memory contents become undefined. Established (manual pages 162–163).
- **NMI** uses the same vector and the same ErrorEPC and Status changes as soft reset. It keeps register contents, and cache and memory state too. Established (manual pages 162–163). The shared vector does not make an NMI a cold reset.
- A soft reset or NMI changes Status by ORing in ERL, BEV and SR, which is `0x00500004`. No other Status bit changes. Bit 19 is reserved in the manual, which gives it no NMI meaning. Established.
- A warm entry keeps Config, the general registers, HI and LO, the floating-point registers and FCR31, EPC and Cause, LLAddr, and the TLB. Established as the manual's register retention rule.
- The reset values of Config K0 (bits 2:0) and SE (bit 12) are undefined in the manual. So are Status bits that no reset entry sets. Established as undefined. Software must write them before relying on them.

## Config

The manual's Config fields, with bits and meaning. Each field is in [devices/r5000_cp0/registers.md](../r5000_cp0/registers.md).

| Bits | Field | Meaning in the manual |
|---|---|---|
| 30:28 | EC | Processor-to-system divisor. Codes 0 to 6 give 2 to 8. Code 7 is reserved. |
| 27:24 | EP | Writeback data timing pattern, codes 0 to 8. Not a CPU frequency field. |
| 23:22 | SB | Secondary block size. Code 1 is eight words, 32 bytes. Other codes are reserved for this part. |
| 21:20 | SS | Secondary cache size. Codes 0, 1 and 2 are 512 KiB, 1 MiB and 2 MiB. Code 3 is unresolved, see below. |
| 19:18 | EW | System bus width. Code 0 is the 64-bit SysAD bus. |
| 17 | SC | Zero means a secondary cache is present, one means absent. |
| 16 | | Format bit, one. |
| 15 | BE | Memory endianness, selected at reset. |
| 14 | EM | Parity mode. The manual requires one for this part. |
| 13 | EB | Sub-block ordering. The manual requires one for this part. |
| 12 | SE | Software secondary cache enable. Reset value undefined. |
| 11:9 | IC | Primary instruction cache size. Code 3 is 32 KiB. |
| 8:6 | DC | Primary data cache size. Code 3 is 32 KiB. |
| 5 | IB | One for a 32-byte primary instruction line. |
| 4 | DB | One for a 32-byte primary data line. |
| 2:0 | K0 | kseg0 cache algorithm. Software controlled. Reset value undefined. |

- The mode word maps its secondary-presence bit to SC and its two size bits to SS. Established (manual pages 296–297).
- Bits 31 and 3 read as zero in the manual's diagram. The prose calls bits 3:0 software controlled, while the diagram gives only K0 bits 2:0. Unknown: whether bit 3 is software writable.
- SS code 3 is listed as "none" in the register table, and the mode word leaves that code reserved. Unknown for code 3. Codes 0 to 2 are not affected.

## Status

- Implemented fields, with their bits: XX 31, CU2:0 30:28, FR 26, RE 25, BEV 22, SR 20, CE 17, DE 16, IM7:0 15:8, KX 7, SX 6, UX 5, KSU 4:3, ERL 2, EXL 1, IE 0. Their union is `0xf653ffff`. Bits 27, 24:23, 21 and 19:18 are reserved. Established (manual pages 143–146, Tables 7-3 and 7-4).
- **XX** is the user-mode MIPS IV enable (Table 6-1, printed page 103; section 6.2.3, page 104; Table 7-3, page 144). Page 104 adds that in kernel mode all instructions are always valid, so XX does not disable MIPS IV there. Established. The earlier text said that with XX clear every MIPS IV operation is refused, in both COP1 and COP1X encodings, before operand execution, translation or any operand access. The manual pages read do not say any of that, so it is dropped. Which instructions count as MIPS IV, and the order of that refusal against translation, are unknown.
- Unknown: the exception type the manual raises for a disabled floating-point operation. The manual establishes that the operation is refused, but does not settle which exception it raises.
- IM1 and IM0 are the software interrupts. IM7 to IM2 are the six external inputs. Established.

## ErrorEPC

ErrorEPC is the restart address. For an interrupted instruction in a delay slot it is the preceding branch or jump, not the delay-slot instruction. The register has no separate delay flag. Established (manual page 154).

## Count and Compare

- Count and Compare are 32-bit. Count advances independently of instruction retirement. The reset selection permits either the full or the half maximum issue rate. Half is the stated default. Established (manual reset selection).
- When Count equals Compare, Cause IP7 is set. Writing Compare clears the timer interrupt. Established.
- The reset selection does not say which rate an O2 uses. Unknown for the O2.

## LLAddr

LLAddr is a 32-bit read/write diagnostic register. It holds physical address bits 35:4 of the most recent LL read, so the field is that address shifted right four bits. Established (manual page 132, Figure 6-17). It is not a cache-line or reservation granule selection.

## FCR31 and the FPU

- FCR31 fields: CC7 to CC1 at 31:25, FS 24, CC0 23, reserved 22:18, Cause 17:12, Enables 11:7, Flags 6:2, RM 1:0. Established (manual pages 188–189, Figures 8-4 and 8-5).
- The FPU has single and double IEEE operations, FR-dependent register views, rounding control, condition codes, flags, enables and causes. Established (manual chapters 8 and 9).
- The manual documents an unimplemented-operation exception for certain computations and conversions, and for the exceptional multiplication part of multiply-add operations. Established that the class exists (manual page 211). Unknown: which individual cases raise it, which needs the per-instruction source.

## Caches

- Primary instruction and data caches: 32 KiB each, two-way, 32-byte lines, 512 sets each. Established (manual and overview).
- Primary Index operations take the set from virtual address bits 13:5 and the way from bit 14. Established (manual pages 72–74).
- The secondary cache is direct-mapped, with 32-byte lines and the sizes in the Config table above. Established (manual).
- The secondary cache can run write-through or write-back. The manual has a secondary cache write-through protocol (section 16.5, printed page 285); the overview's page 7 statement could not be re-read.
- The CACHE table includes primary index invalidate and writeback-invalidate, index load and store of the tag, create-dirty-exclusive, hit invalidate and writeback, instruction fill, secondary flash invalidate, secondary tag operations, and a 128-line page invalidate. Established (manual CACHE table; the packet did not record its page).
- The 128-line page invalidate covers 4 KiB, 128 lines of 32 bytes, and needs alignment. Established.
- Secondary Index Store Tag takes its tag from the effective address. The primary tag operations do not. Established (manual CACHE table).
- Unsupported combinations, uncached operands and absent-secondary operations are undefined in the manual. Unknown in every case.
- Unknown: whether the secondary index uses physical or virtual address bits. Manual pages 72–74 describe a physical index. Page 230 calls the secondary cache virtually indexed. The public Linux cache driver uses physical indexing, which is a software expectation, not a manual statement. The sources conflict.

## Unknown, and what would settle it

- **Which NEC part an SGI assembly carries.** A legible part marking or a primary fitment record. The manual covers the µPD30500 and µPD30500A only.
- **Silicon errata for the observed revision.** The errata publication the manual's history refers to. Not located.
- **Secondary index addressing.** The manual's own pages and the Linux driver disagree. Settled by a manual statement that resolves the conflict, or a documented capture of an index operation on a known address.
- **Config bit 3 and the K0 field.** Settled by the manual's own correction or a reviewed diagram.
- **SS code 3 and the EC ratios above 4.** Settled by the owning register table or the processor's clock documentation.
- **The exception raised for a disabled floating-point operation (XX clear in user mode).** Settled by the manual's exception table for that case.
- **Which FP operations raise the unimplemented exception, and the exact per-instruction rounding and exception cases.** Settled by the per-instruction source and the applicable errata.
- **Full MIPS IV instruction conformance.** Needs the instruction reference's per-instruction text, which the packet did not read.
- **Reset values of K0, SE and the Status bits that no reset entry sets.** Undefined in the manual. Settled only by a raw read after cold reset, before firmware runs, on a part with a known marking.
- **Cache diagnostic operations, parity and secondary error behavior.** Not covered by this page.
- **Which Count rate an O2 uses.** Settled by a raw Config read or a boot line that prints it.
