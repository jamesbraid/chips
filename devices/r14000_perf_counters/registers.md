<!-- generated from devices/r14000_perf_counters/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 7eecccb8ac094c1de6c36069e754426c42e0d4e6a5dc0a503425e631c68b20df -->

# R14000 CP0 performance counters: selectors, control fields and event numbers

Constants for the performance counters that the MIPS R12000, R14000 and R16000 expose through CP0 register 25: the four control and counter pairs and their selectors, the control field positions, the counter width and overflow bit, and the event numbers SGI's profiling guide names. R14000 claims rest on the public Linux MIPS performance driver and on SGI's guide, so most are inferred. R12000 claims come from the NEC VR10000 Series manual and say so in their text. This unit holds constants only. The reading, the unknowns and what would settle them are in devices/r14000_perf_counters/README.md, generated to devices/r14000_perf_counters/registers.md. Grades: established means a published manual states it; inferred means a public driver or a reasoned reading shows it and no processor manual for the R14000 has been checked; unknown means the field's R14000 behaviour is not established.

Unit `r14000_perf_counters`, macro prefix `R14KPC`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R14KPC_CNT_BITS` | 0x20 | inferred |  | Counter width as the Linux driver treats it, an unsigned 32-bit quantity. The R14000 wrap and high-bit behaviour is not established. The NEC manual gives four 32-bit pairs for the R12000 (printed pp. 247 and 250), so the R12000 is established. |
| `R14KPC_CNT_OVERFLOW_BIT` | 0x1f | inferred |  | Counter bit that the Linux driver tests for overflow, together with the interrupt enable. For the R12000 the NEC manual puts the overflow interrupt on counter bit 31 (printed p. 247), so that part is established. |
| `R14KPC_CP0_REG` | 0x19 | inferred |  | CP0 register that holds the counter pairs on the R14000, as the Linux driver reads and writes them. The NEC manual places the R12000's pairs in the same register (printed p. 247), so the R12000 is established. |
| `R14KPC_CTL_EVENT_MASK` | 0x3e0 | inferred |  | Mask for the five-bit event select, bits 9:5. Established for the R12000; inferred for the R14000 as stated for its shift. |
| `R14KPC_CTL_EVENT_SHIFT` | 0x5 | inferred |  | Lowest bit of the five-bit event select, bits 9:5 of each control register. Established for the R12000 by the NEC manual. The R14000 position is inferred from the R12000 and from the event numbers below. |
| `R14KPC_CTL_EXL` | 0x1 | inferred |  | Control bit 0: count while the processor is at exception level. The field name and position come from the generic Linux header and the driver's use of it. The NEC manual gives the R12000 equivalent in the same position; the R14000 is not checked against a processor manual. |
| `R14KPC_CTL_IE` | 0x10 | inferred |  | Control bit 4: enable the counter's overflow interrupt. The exact rule for when the interrupt asserts or clears is not established. |
| `R14KPC_CTL_K` | 0x2 | inferred |  | Control bit 1: count in kernel mode, from the generic header and the driver's use of it. |
| `R14KPC_CTL_S` | 0x4 | unknown |  | Control bit 2: supervisor-mode counting in the generic header. Whether the R14000 implements it, and how it interacts with exception state, is not established. |
| `R14KPC_CTL_U` | 0x8 | inferred |  | Control bit 3: count in user mode, from the generic header and the driver's use of it. |
| `R14KPC_EV_CYCLES` | 0x0 | established |  | Processor clock cycles. SGI's table gives this numbering for the R12000, R14000 and R16000. Availability on each of the four pairs is not established. |
| `R14KPC_EV_DECODED_INSTR` | 0x1 | established |  | Decoded instructions, from SGI's table. |
| `R14KPC_EV_FAILED_SC` | 0x5 | established |  | Failed conditional stores, from SGI's table. |
| `R14KPC_EV_MISPREDICT` | 0x18 | established |  | Mispredicted branches, from SGI's table. |
| `R14KPC_EV_PREFETCH_EXEC` | 0x10 | established |  | Executed prefetch instructions. This is the lowest event number that needs bit 9 of the event select. |
| `R14KPC_EV_RETIRED_FP` | 0x15 | established |  | Graduated floating-point instructions, from SGI's table. |
| `R14KPC_EV_RETIRED_INSTR` | 0xf | established |  | Graduated instructions, from SGI's table. SGI calls these graduated instructions. |
| `R14KPC_EV_SCACHE_ECC_CORRECTABLE` | 0x8 | established |  | Correctable ECC errors on secondary-cache data. The NEC manual and SGI's table both give this numbering. |
| `R14KPC_EV_TLB_MISS` | 0x17 | established |  | TLB misses, from SGI's table. |
| `R14KPC_EV_UNIMPLEMENTED` | 0xe | established |  | Entry 14 of SGI's table is marked unimplemented. It is not a usable event. |
| `R14KPC_PAIR0_CNT_SEL` | 0x1 | inferred |  | CP0 register 25 selector of pair 0's counter. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIR0_CTL_SEL` | 0x0 | inferred |  | CP0 register 25 selector of pair 0's control register. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIR1_CNT_SEL` | 0x3 | inferred |  | CP0 register 25 selector of pair 1's counter. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIR1_CTL_SEL` | 0x2 | inferred |  | CP0 register 25 selector of pair 1's control register. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIR2_CNT_SEL` | 0x5 | inferred |  | CP0 register 25 selector of pair 2's counter. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIR2_CTL_SEL` | 0x4 | inferred |  | CP0 register 25 selector of pair 2's control register. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIR3_CNT_SEL` | 0x7 | inferred |  | CP0 register 25 selector of pair 3's counter. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIR3_CTL_SEL` | 0x6 | inferred |  | CP0 register 25 selector of pair 3's control register. The R12000 selector map in the NEC manual agrees (printed p. 250). |
| `R14KPC_PAIRS` | 0x4 | inferred |  | Number of control and counter pairs. The Linux driver selects four for the R12000, R14000 and R16000 and two for the R10000. The NEC manual defines four pairs for the R12000 (printed p. 250), so the R12000 is established. |
| `R14KPC_R12K_CTL0_TRIGGER_MASK` | 0x18000 | unknown |  | R12000 only: the trigger field, bits 16:15 of control 0. Whether the R14000 has this field is not established. |
| `R14KPC_R12K_CTL3_LEVEL_BIT` | 0x8000 | unknown |  | R12000 only: the L1 or L2 selector, bit 15 of control 3. Whether the R14000 has this bit is not established. |
| `R14KPC_R12K_CTL_COND_MASK` | 0x7c00 | unknown |  | R12000 only: the conditional-count field, bits 14:10 of each control register. Whether the R14000 has this field is not established. |
