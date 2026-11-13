# R14000 performance counters

This page covers the CP0 register 25 performance counters that the MIPS R12000, R14000 and R16000 expose: the four control and counter pairs, the control field positions, the counter width and overflow bit, and the event numbers SGI's profiling guide names. The constants are in [devices/r14000_perf_counters/registers.toml](../devices/r14000_perf_counters/registers.toml), generated to [devices/r14000_perf_counters/registers.md](../devices/r14000_perf_counters/registers.md).

Nothing here was read from silicon or from a running machine. The R14000 claims rest on a public driver and on SGI's guide, so most are inferred, and no R14000 processor manual has been checked.

## Sources and grades

- Linux v5.10, `arch/mips/oprofile/op_model_mipsxx.c` (commit `2c85ebc57b3e1817b6ce1a6b703928e113a90442`). The driver's access wrappers, programming, interrupt handling, counter count and CPU selection. It shows what software expects. A driver fact is inferred for the R14000, not measured.
- Linux `arch/mips/include/asm/mipsregs.h` (commit `db2ddb87143519e20a95aa36c60b36107b736a58`). The generic control field names and positions.
- SGI, *SpeedShop User's Guide*, 007-3311-011, Table 4-3 (printed p. 61). It gives the hardware counter events for the R12000, R14000 and R16000, with event 0 as cycles. Established for the event numbering.
- NEC, *VR10000 Series 64-/32-bit Microprocessor User's Manual*, March 2001, U10278EJ4V0UM00, printed pages 247 (Figure 11-23, control register format), 248 (Table 11-24, R12000 counter events) and 250 (Table 11-27, control field definitions). Established for the R12000. The same manual is cited in [docs/r12000a_variant.md](r12000a_variant.md).

Established means a published manual states the fact. Inferred means a public driver or a reasoned reading shows it and no processor manual for the R14000 has been checked. Unknown items are listed at the end.

Page 250 of the NEC manual says in one place that the R12000 has two counters, while its definition and access table give four. Use the definition and the table.

## Register selection

Each pair has a control register and a counter register, both in CP0 register 25. The Linux driver uses these selectors, and the NEC access table gives the same map for the R12000:

| Pair | Control selector | Counter selector |
|---|---:|---:|
| 0 | 0 | 1 |
| 1 | 2 | 3 |
| 2 | 4 | 5 |
| 3 | 6 | 7 |

For the R12000, NEC defines four pairs with independent state. For the R14000, the four pairs and their selectors are inferred from the Linux driver. Whether all four pairs accept every event is not established for the R14000 (see the unknowns).

## Control fields

The generic Linux header names these bits. The driver sets them, so their use is inferred for the R14000.

| Bit | Name | Meaning | R14000 grade |
|---|---|---|---|
| 0 | EXL | count at exception level | inferred |
| 1 | K | count in kernel mode | inferred |
| 2 | S | count in supervisor mode | unknown |
| 3 | U | count in user mode | inferred |
| 4 | IE | overflow interrupt enable | inferred |
| 9:5 | event | five-bit event select | inferred |

The event select is established for the R12000 by NEC's Figure 11-23 and Table 11-27: five bits, 9:5. The R14000 position is inferred from that and from the event numbers below.

The NEC manual also documents three R12000 fields. The R14000 status of each is unknown:

- Conditional count, bits 14:10 of each control register.
- Trigger, bits 16:15 of control 0.
- L1 or L2 selector, bit 15 of control 3.

The NEC manual states that ERL disables counting for the R12000. Whether the R14000 does the same is not established, and nor is the precedence between EXL, ERL and the other enables.

## Events

SGI's table gives these event numbers for the R12000, R14000 and R16000. Established for the numbering:

| Event | Meaning |
|---:|---|
| 0 | processor clock cycles |
| 1 | decoded instructions |
| 5 | failed conditional stores |
| 8 | correctable ECC errors on secondary-cache data (NEC and SGI agree) |
| 14 | unimplemented |
| 15 | retired instructions |
| 16 | executed prefetch instructions |
| 21 | retired floating-point instructions |
| 23 | TLB misses |
| 24 | mispredicted branches |

The table lists 32 numbers, 0 to 31. The ones above are the ones the constants name. Event 0 counts processor clock cycles. The retired-instruction events count the number retired in a cycle, so a clock-cycle counter cannot stand in for them.

Whether each event is available on each of the four R14000 pairs is not established. SGI's table gives the numbering, not a pair matrix. The NEC manual says that on the R12000 all four counters can select any event.

## Counter width and overflow

The Linux driver treats each counter as an unsigned 32-bit value. It preloads the counter with `0x80000000` minus the period, and it treats a set bit 31 with the interrupt enable set as an overflow. For the R12000, NEC gives four 32-bit pairs and puts the overflow interrupt on counter bit 31 (printed p. 247). Those R12000 facts are established. The R14000 wrap behaviour and high-bit write rules are not.

NEC says the R12000 keeps counting after an overflow. The R14000 rule is not established.

The driver writes zero to a control register to disable a pair before it loads the counter, and then writes the control to start it. That is what the software does. It is not a reset value. Power-on and reset values for these registers are not established for any part in this page.

## Interrupts

NEC says the R12000's IP[7] is shared with Count/Compare. The Linux driver hooks a performance interrupt handler and uses platform IRQ selection where one is given. Neither source establishes the R14000 interrupt pin, its relation to Count/Compare, whether the pending state persists, or which writes clear it.

## Unknown, and what would settle it

- **R14000 control bits 2 and 3 (S and U) and the exception-level precedence.** Settled by an R14000 processor manual or a measurement that counts with each enable alone while the processor is at each exception level.
- **R14000 event availability on each of the four pairs.** SGI's table gives numbers, not a pair matrix. Settled by an R14000 manual's event table, or a counting test on a part for each event on each pair.
- **R14000 counter width, wrap and overflow persistence.** The driver and the R12000 manual are the only sources. Settled by the R14000 manual or a counter test that runs past 2^32.
- **R14000 interrupt pin and assertion rules.** The Linux driver does not say. Settled by the R14000 manual's signal description, or an interrupt test on the part with the enable set and clear.
- **Whether the R14000 has the R12000's conditional-count, trigger and L1/L2 fields.** Settled by the R14000 manual.
- **Reset and power-on values.** Not given by any source here. Settled by the R14000 manual or a register read taken straight after a reset. A read after firmware or a driver has run is not a reset value.
- **Accepted reads and writes outside the four pairs.** The driver uses only selectors 0 to 7. Other selectors and wider access widths are not established.
- **Physical measurements.** No capture from a real R14000 is in this repository for any field here.
