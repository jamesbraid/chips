# R12000A variant: mode fields and the secondary-error syndrome

This page covers what the NEC VR12000A user's manual says differs from the R12000: three boot-mode fields, the HSTL output mode, and a 9-bit syndrome register that the variant puts in CP0 register 25. The constants are in [devices/r12000a_variant/registers.toml](registers.toml), generated to [devices/r12000a_variant/registers.md](registers.md). Nothing here was read from silicon or from a running machine.

## Source and grades

- NEC, *VR10000 Series 64-/32-bit Microprocessor User's Manual*, fourth edition, March 2001, U10278EJ4V0UM00. Appendix C (printed pages 357 and 358) lists the R12000A differences. Printed page 247 gives the performance control register layout, with a footnote that bits 31:23 are syndrome bits on the R12000A. The page numbers are the printed numbers.

Established means the manual states the fact. Inferred means a reasoned reading that the manual does not state in those words. Unknown items are listed at the end with what would settle them.

The manual's R12000 material covers the R12000 and R12000L together, so a rule about the R12000 is recorded for both unless the text separates them.

## Boot mode fields

The mode word is read at reset. Only its low 25 bits are copied into CP0 Config (printed p. 180). The fields below are read from the mode word, not from a new register.

### SysClkDiv, bits 12:9

- The field is four bits wide, at bits 12:9. Established (Table C-1, printed p. 357).
- The R12000A table defines these codes:

| Code | Divisor, PClk to SysClk | Status |
|---:|---:|---|
| 0000 to 0010 | none | reserved |
| 0011 | 2 | legal |
| 0100 | 2.5 | legal |
| 0101 | 3 | legal |
| 0110 | 3.5 | legal |
| 0111 | 4 | legal |
| 1000 | 4.5 | legal |
| 1001 | 5 | legal |
| 1010 | 5.5 | legal |
| 1011 | 6 | legal |
| 1100 | 7 | legal, new in the R12000A |
| 1101 to 1111 | none | reserved |

  The codes 3 to 11 give the same divisors as the R12000's own table. Established (Table C-1 against Table B-1, printed p. 346). The R10000 formula for the field, PClk = SysClk x (SysClkDiv + 1) / 2, gives the same divisors for codes 3 to 11 (printed p. 172).
- Code 12 is the only code the R12000A adds. Established (Table C-1, which is the list of mode bits changed in the R12000A).
- The R12000 and R12000L list code 1100 as reserved. Established (Table B-1, printed p. 346, which carries a footnote that the code can be set in the R12000A). What the R12000 does with a reserved code is unknown.
- Code 12 gives 7 rather than the 6.5 that a linear step from code 11 would give. The table states 7, so the step is not linear. Established (Table C-1).

### SCClkDiv, bits 21:19

- The field is three bits wide, at bits 21:19. Established (Table C-2, printed p. 357).
- The codes are: 010 = 1.5, 011 = 2, 100 = 2.5, 101 = 3, 111 = 4. The codes 000, 001 and 110 are reserved. Established (Table C-2).
- Code 111 is labelled as added for testing silicon. Established (Table C-2).
- The manual says the selectable PClk to SCClk divisors are the same as the R12000's. Established (Table C-2 note). So no SCClkDiv code is added or removed by the variant.

### HSTL output mode, bits 30:29

- The field is two bits wide, at bits 30:29. Established (Table C-3, printed p. 358).
- Each code picks an HSTL level for the system interface outputs and one for the secondary cache interface outputs. The codes are 00 = HSTL 1 for both, 01 = HSTL 1 for the system interface and HSTL 2 for the secondary cache, 10 = HSTL 2 for the system interface and HSTL 1 for the secondary cache, 11 = HSTL 2 for both. Established (Table C-3).

## Syndrome register in CP0 register 25

### Layout and access

- The syndrome is nine bits, at bits 31:23 of CP0 register 25, performance control 0. Established (section C.2, printed p. 358; footnote to Figure 11-23, printed p. 247).
- The R12000 and R12000L leave these bits unused, and their figure shows them as zero. Established (figure, printed p. 247).
- The bits are read only. A write to the control register does not change them. Established (section C.2).
- The register is not writable by any other means. Established (section C.2).
- Bit 31 of control 0 is not a counter overflow bit. The overflow interrupt is on counter bit 31, and the manual's text on IP[7] refers to the counter (printed p. 247). Inferred: the manual states the counter rule and the syndrome placement separately, not this contrast. Whether the syndrome bit can assert an interrupt is not stated in the manual. Unknown.

### What fills it

- The register captures the syndrome of data coming into the processor from the secondary cache. Established (section C.2).
- It captures on a single or multiple bit error. Established (section C.2).
- It is written for secondary-to-primary refills and for secondary-to-main-memory writebacks. Established (section C.2).
- It is not written for CacheOp reads from the secondary cache. Established (section C.2).
- After a qualifying error it holds that error's syndrome. Established (section C.2: "always contain the syndrome bits generated for the most recent error").
- Error-free traffic does not clear it. Inferred from the "most recent error" wording. The manual does not say it explicitly.
- The manual describes the variant's error indication as a new mechanism for received secondary cache data. Established (section C.3, printed p. 358). The manual gives no check matrix for it, so the syndrome-to-bit map is not in this page.

### Reset state

- At power-up the register is uninitialized. Established (section C.2). The manual gives no value for it, and zero is not a documented reset value.
- The manual does not say what a reset does to the captured value. Unknown.

## Unknown, and what would settle it

- **Syndrome decoder and check matrix for the R12000A secondary data array.** The manual names the syndrome but not the matrix that produces it. Settled by a matrix published for the part, or a fault-injection capture on a real R12000A under a stated plan.
- **Which error sources fill the register beyond refills and writebacks.** The manual names those two paths. Whether other secondary data events fill it is not stated. Settled by the same fault-injection capture.
- **Interrupt effect of syndrome bit 31.** The manual does not say whether bit 31 of control 0 can assert or acknowledge an interrupt. Settled by the manual's signal description or a test on the part.
- **Value after reset, and reset behaviour.** The manual gives only the power-up state. Settled by a capture of the register after each reset kind on a part.
- **R12000 behaviour on SysClkDiv code 12.** The manual lists the code as reserved. What the part does when it is set is not stated. Settled by a boot-mode test on an R12000 part.
- **R14000 and R16000.** This manual does not cover them. Any statement that they carry the same syndrome field is outside this page. Settled by their own manuals or a capture.
- **Physical measurements.** No capture from a real R12000A part exists in this repository for any field here. The manual states the rules, and a capture would show what a part does.
