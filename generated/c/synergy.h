/* generated from devices/synergy/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 4c3ea2546f72bcace270f575e55b39b69ccbbb218f4ea2c4bd2699014b6f3a17 */
/* Synergy: the Itanium processor-bus ASIC of the SN1 IA-64 node (register offsets the Linux port uses) */
#ifndef SYN_GEN_H
#define SYN_GEN_H

#include <stdint.h>


/*
 * Interrupt vector enable mask, vectors 192 to 255, for the processor in bus slot 0. Bit n enables vector 192 plus n. The kernel sets a processor's bit here when it is in slot 0 and clears it in the matching B register. The fake PROM writes all ones to every mask register at start.
 */
/* vec_mask3_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK3_A                              0x0002a0 /* established */

/*
 * Same as vec_mask3_a for the processor in bus slot 1.
 */
/* vec_mask3_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK3_B                              0x0002a8 /* established */

/*
 * Vector enable mask, vectors 128 to 191, slot 0.
 */
/* vec_mask2_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK2_A                              0x0002b0 /* established */

/*
 * Vector enable mask, vectors 128 to 191, slot 1.
 */
/* vec_mask2_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK2_B                              0x0002b8 /* established */

/*
 * Vector enable mask, vectors 64 to 127, slot 0. The kernel's Bedrock-pending-bit interrupts live here and in the next register.
 */
/* vec_mask1_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK1_A                              0x0002c0 /* established */

/*
 * Vector enable mask, vectors 64 to 127, slot 1.
 */
/* vec_mask1_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK1_B                              0x0002c8 /* established */

/*
 * Vector enable mask, vectors 0 to 63, slot 0.
 */
/* vec_mask0_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK0_A                              0x0002d0 /* established */

/*
 * Vector enable mask, vectors 0 to 63, slot 1.
 */
/* vec_mask0_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_VEC_MASK0_B                              0x0002d8 /* established */

/*
 * Offset established; role inferred. From the 2.4.18 patches of April 2002 the kernel's I/O write barrier reads this register for a processor on Synergy 0 (gbl_perf_b for Synergy 1) in a loop that sleeps 5 microseconds while the value is zero, after first reading the Bedrock revision register. The code comment calls the polled thing the Bedrock PIO write status register, and the macro names are GBL_PERF_A/B. The loop therefore implies the register reads nonzero when the processor's earlier uncached stores have drained, but the comment says 'clear', so the polarity is unsettled. Which bits carry that, and what the name's 'perf' means, is unknown.
 */
/* gbl_perf_a: r64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_GBL_PERF_A                               0x000330 /* established */

/*
 * Counterpart of gbl_perf_a, polled by processors on Synergy 1. See there.
 */
/* gbl_perf_b: r64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_GBL_PERF_B                               0x000338 /* established */

/*
 * Written once per Synergy by the fake PROM with (nasid << 16) | (synergy << 9); the comment says it sets the NASID in FSB_CONFIG. The value written and the offset are established; the field meanings are inferred from the comment and the operands; every other bit is unknown.
 */
/* fsb_config: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_FSB_CONFIG                               0x000450 /* established */
#define SYN_FSB_CONFIG_NASID_SHIFT                   16 /* inferred */
#define SYN_FSB_CONFIG_NASID_MASK                    0xffull
#define SYN_FSB_CONFIG_NASID_INPLACE                 (SYN_FSB_CONFIG_NASID_MASK << SYN_FSB_CONFIG_NASID_SHIFT)
#define SYN_FSB_CONFIG_SYNERGY_SHIFT                 9 /* inferred */
#define SYN_FSB_CONFIG_SYNERGY_MASK                  0x1ull
#define SYN_FSB_CONFIG_SYNERGY_INPLACE               (SYN_FSB_CONFIG_SYNERGY_MASK << SYN_FSB_CONFIG_SYNERGY_SHIFT)

/*
 * Performance control, bus 0, counter A. Only with the kernel's optional perf option. Bit 45 enables counting (the code sets it on every event word it stores, with the comment 'bit 45 is enable'); every other bit of the event select is unknown.
 */
/* perf_cntl0_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTL0_A                             0x000ab0 /* established */
#define SYN_PERF_CNTL0_A_ENABLE_SHIFT                45 /* established */
#define SYN_PERF_CNTL0_A_ENABLE_MASK                 0x1ull
#define SYN_PERF_CNTL0_A_ENABLE_INPLACE              (SYN_PERF_CNTL0_A_ENABLE_MASK << SYN_PERF_CNTL0_A_ENABLE_SHIFT)

/*
 * Performance control, counter B. The header labels it bus 0, but the kernel's multiplexer writes it through Synergy 1 (and CNTL0_A through Synergy 0), the same event word to both, so 'B' may mean Synergy 1; unknown. Same layout as perf_cntl0_a.
 */
/* perf_cntl0_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTL0_B                             0x000ab8 /* established */

/*
 * Performance control, bus 1, counter A. Defined in the header; the kernel's multiplexer never writes it.
 */
/* perf_cntl1_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTL1_A                             0x000ac0 /* established */

/*
 * Performance control, bus 1, counter B. Defined, unused.
 */
/* perf_cntl1_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTL1_B                             0x000ac8 /* established */

/*
 * Performance counter 0, A. Read through the remote window and masked to 40 bits, then written zero after each interval.
 */
/* perf_cntr0_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTR0_A                             0x000ad0 /* established */

/*
 * Performance counter 0, B. Same use, but read and cleared through Synergy 1 while counter 0 A is read through Synergy 0, so the header's 'FSB0' label for both is doubtful; unknown.
 */
/* perf_cntr0_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTR0_B                             0x000ad8 /* established */

/*
 * Cache-way disable mask for the L4 cache. The kernel's flush routine writes 0xff with one way's bit cleared, reads a run of 512-byte blocks through nine aliases 8 MB apart so that only that way can allocate, repeats for each of eight ways, then writes 0. That a set bit disables a way is inferred from the register's name and this use. Bits above 7 are unknown. First seen in the 2.4.16 patch of November 2001.
 */
/* syn_tag_disable_way: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_SYN_TAG_DISABLE_WAY                      0x000ae0 /* established */
#define SYN_SYN_TAG_DISABLE_WAY_WAY_DISABLE_SHIFT    0 /* inferred */
#define SYN_SYN_TAG_DISABLE_WAY_WAY_DISABLE_MASK     0xffull
#define SYN_SYN_TAG_DISABLE_WAY_WAY_DISABLE_INPLACE  (SYN_SYN_TAG_DISABLE_WAY_WAY_DISABLE_MASK << SYN_SYN_TAG_DISABLE_WAY_WAY_DISABLE_SHIFT)

/*
 * Performance counter 1, A. Defined, unused by the kernel.
 */
/* perf_cntr1_a: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTR1_A                             0x000af0 /* established */

/*
 * Performance counter 1, B. Defined, unused.
 */
/* perf_cntr1_b: rw64, reset unknown; Linux 2.4.18 IA-64 patch series and Linux v2.5.0, SGI SN1 IA-64 platform code (Synergy header and driver, cache flush, I/O barrier, fake PROM) */
#define SYN_PERF_CNTR1_B                             0x000af8 /* established */

#define SYN_L4_BLOCK_BYTES                           0x200u /* established */
#define SYN_L4_BYTES                                 0x4000000u /* established */
#define SYN_L4_WAYS                                  0x8u /* established */
#define SYN_LOCAL_BASE                               0xe0000000000ull /* established */
#define SYN_PERF_COUNTER_BITS                        0x28u /* established */
#define SYN_REMOTE_WINDOW_SYN0                       0x34000000u /* established */
#define SYN_REMOTE_WINDOW_SYN1                       0x35000000u /* established */

#endif /* SYN_GEN_H */
