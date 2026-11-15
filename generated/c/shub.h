/* generated from devices/shub/registers.toml by defs-gen - do not edit, change the source */
/* SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs */
#ifndef SHUB_GEN_H
#define SHUB_GEN_H

#include <stdint.h>


/*
 * Chip identification word at node offset 0x1_0000_0000 (memory and directory block by address); the name is ours. The PROM reads it through the node's global window at node start and stores bits 27:12 as the node's part number and bits 31:28 as its revision. The part number is compared with 17251 (0x4363) site 0xffa959a6, reached through a table, so that this word feeds the compare is inferred. A bounded read that returns the part number satisfies the PROM.
 */
/* chip_id: r64, reset unknown; SAL 5.04 PROM site 0xffa0be1c (read) and 0xffa0f8c0 (storage of the fields); the compare against 17251 is site 0xffa959a6 */
#define SHUB_CHIP_ID                                 0x100000000 /* inferred */
#define SHUB_CHIP_ID_REVISION_SHIFT                  28 /* inferred */
#define SHUB_CHIP_ID_REVISION_MASK                   0xfull
#define SHUB_CHIP_ID_REVISION_INPLACE                (SHUB_CHIP_ID_REVISION_MASK << SHUB_CHIP_ID_REVISION_SHIFT)
#define SHUB_CHIP_ID_PART_NUMBER_SHIFT               12 /* inferred */
#define SHUB_CHIP_ID_PART_NUMBER_MASK                0xffffull
#define SHUB_CHIP_ID_PART_NUMBER_INPLACE             (SHUB_CHIP_ID_PART_NUMBER_MASK << SHUB_CHIP_ID_PART_NUMBER_SHIFT)

/*
 * Memory test engine status; the name is ours. Written 0 at engine start. The memory-test loop reads bit 36 after every engine run (site 0xffa702c0) and treats it set as failure (-2), so it must read 0 on a passing run; the error report reads it again and then md_mbist_err. The directory write does not test it. The flag name (compare error) is inferred.
 */
/* md_mbist_status: rw64, reset unknown; SAL 5.04 PROM site 0xffa6fbac (written 0 at engine start); bit 36 read on failure per the earlier reviewed reading; no Linux v5.3 name */
#define SHUB_MD_MBIST_STATUS                         0x100000080 /* inferred */
#define SHUB_MD_MBIST_STATUS_CMP_ERR_SHIFT           36 /* inferred */
#define SHUB_MD_MBIST_STATUS_CMP_ERR_MASK            0x1ull
#define SHUB_MD_MBIST_STATUS_CMP_ERR_INPLACE         (SHUB_MD_MBIST_STATUS_CMP_ERR_MASK << SHUB_MD_MBIST_STATUS_CMP_ERR_SHIFT)

/*
 * Memory test engine other-error value; the name is ours. Read only in the failure report, after bit 36 of md_mbist_status is found set; not read on a passing run.
 */
/* md_mbist_err: r64, reset unknown; SAL 5.04 PROM site 0xffa725f6 (read in the failure report, per the earlier reviewed reading); no Linux v5.3 name */
#define SHUB_MD_MBIST_ERR                            0x1000000b8 /* inferred */

/*
 * Memory test engine mask; the name is ours (inferred from the all-ones write only). Written with all ones each time the engine starts.
 */
/* md_mbist_mask: w64, reset unknown; SAL 5.04 PROM site 0xffa6fbdc (written all ones at engine start); no Linux v5.3 name */
#define SHUB_MD_MBIST_MASK                           0x1000000c0 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Per-bank configuration word 0 of the memory controller set-up (node-bringup.md: timing index in bits 35:32 and one byte per bank at bit 8k with density index in 2:0, rank code in 3 and bank number in 6:5; not re-read for this file).
 */
/* md_bank_cfg0: w64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_BANK_CFG0                            0x100010000 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Per-bank configuration word 1; read once first, then written.
 */
/* md_bank_cfg1: rw64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_BANK_CFG1                            0x100010008 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Per-bank configuration word 2; the memory test driver reads each bank's config byte here and skips banks whose density index is 7 (empty).
 */
/* md_bank_cfg2: rw64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_BANK_CFG2                            0x100010010 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Timing fields built from a 32-byte flash table row; bits 7:0 are 0x02 and one of bits 52, 53 or 54 selects tRCD 3, 2 or 4 (node-bringup.md; not re-read for this file).
 */
/* md_timing_0: w64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_TIMING_0                             0x100010020 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Six 4-bit timing fields (node-bringup.md; not re-read for this file).
 */
/* md_timing_1: w64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_TIMING_1                             0x100010028 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Refresh interval 195 in bits 16:8 (overridable by the MemoryRefresh variable), tRFC clocks in bits 22:17 and per-bank enables (node-bringup.md; not re-read for this file).
 */
/* md_refresh_0: w64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_REFRESH_0                            0x100010030 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Paired with md_timing_0 (same layout, per node-bringup.md); read then written.
 */
/* md_timing_2: rw64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_TIMING_2                             0x100010040 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Second copy of md_timing_1's layout; read then written.
 */
/* md_timing_3: rw64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_TIMING_3                             0x100010048 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Second copy of md_refresh_0's layout. The bring-up routine reads it (site 0xffa7761c), puts the refresh interval 195 in bits 16:8 and writes it back (site 0xffa77b0c); the same word is also written to md_refresh_0 (site 0xffa77adc).
 */
/* md_refresh_1: rw64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_REFRESH_1                            0x100010050 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Written with the constant 0x4004e20 (node-bringup.md).
 */
/* md_const_58: w64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_CONST_58                             0x100010058 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Written 0x4047 when the SHub ID revision is above 2 and 0x4045 otherwise (the same revision split as pi_reg_2000_0000's OR value).
 */
/* md_ctl_60: w64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_CTL_60                               0x100010060 /* inferred */

/*
 * Memory controller register, unnamed; the name is ours. Written with the constant 0x24 (node-bringup.md).
 */
/* md_const_78: w64, reset unknown; SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name */
#define SHUB_MD_CONST_78                             0x100010078 /* inferred */

/*
 * Memory test and DRAM initialisation engine, command or address word; the name is ours. Written with the caller's word before md_mbist_ctl. The meaning of the word is unknown; it is plain storage as far as the PROM shows.
 */
/* md_mbist_cmd: w64, reset unknown; SAL 5.04 PROM site 0xffa6fb7c (written first when the engine starts); no Linux v5.3 name */
#define SHUB_MD_MBIST_CMD                            0x100020080 /* inferred */

/*
 * Memory test and DRAM initialisation engine control; the name is ours. The PROM starts the engine by writing md_mbist_cmd, then 0 to md_mbist_status and all ones to md_mbist_mask, then this register with go set, an operation code in bits 38:32 and a 31-bit value. It then polls: while (value & 0x300_0000_0000) equals 0x100_0000_0000 (go set, fail clear) it waits; it stops when go clears or fail sets, with a deadline of 20,000,000 microseconds on the PROM's own clock routine (the routine site 0xffa0da70 returns microseconds). Fail set afterwards is an error. A model where go clears at once and fail never sets satisfies the code.
 */
/* md_mbist_ctl: rw64, reset unknown; SAL 5.04 PROM site 0xffa6fc3c (start), 0xffa6fd3c (poll), 0xffa6b1dc (failure test); no Linux v5.3 name */
#define SHUB_MD_MBIST_CTL                            0x100020088 /* inferred */
#define SHUB_MD_MBIST_CTL_FAIL_SHIFT                 41 /* inferred */
#define SHUB_MD_MBIST_CTL_FAIL_MASK                  0x1ull
#define SHUB_MD_MBIST_CTL_FAIL_INPLACE               (SHUB_MD_MBIST_CTL_FAIL_MASK << SHUB_MD_MBIST_CTL_FAIL_SHIFT)
#define SHUB_MD_MBIST_CTL_GO_SHIFT                   40 /* inferred */
#define SHUB_MD_MBIST_CTL_GO_MASK                    0x1ull
#define SHUB_MD_MBIST_CTL_GO_INPLACE                 (SHUB_MD_MBIST_CTL_GO_MASK << SHUB_MD_MBIST_CTL_GO_SHIFT)
#define SHUB_MD_MBIST_CTL_OP_SHIFT                   32 /* inferred */
#define SHUB_MD_MBIST_CTL_OP_MASK                    0x7full
#define SHUB_MD_MBIST_CTL_OP_INPLACE                 (SHUB_MD_MBIST_CTL_OP_MASK << SHUB_MD_MBIST_CTL_OP_SHIFT)
#define SHUB_MD_MBIST_CTL_VALUE_SHIFT                0 /* inferred */
#define SHUB_MD_MBIST_CTL_VALUE_MASK                 0x7fffffffull
#define SHUB_MD_MBIST_CTL_VALUE_INPLACE              (SHUB_MD_MBIST_CTL_VALUE_MASK << SHUB_MD_MBIST_CTL_VALUE_SHIFT)

/*
 * Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege vector for acc=0'). Defined by the header; no use in any kernel file read. Layout and role unknown.
 */
/* md_dqlp_dir_privilege_vector: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_DQLP_DIR_PRIVILEGE_VECTOR            0x100030300 /* established */

/*
 * Directory memory initial-value write, left queue port block (the block is the one the Linux header calls SH1_MD_DQLP_MMR_DIR_PRIVEC0 at the 0x300 offset; the left reading is inferred from that name); the name is ours. The PROM stores the value shifted left 55 here and to md_dir_access_rp, then runs the engine with operation code 64. No separate initialise register for directory ECC was seen. The routine fails on a -3 timeout or bit 41 of md_mbist_ctl and does not test bit 36 of md_mbist_status.
 */
/* md_dir_access_lp: w64, reset unknown; SAL 5.04 PROM site 0xffa6b10c (memctl_write_dir_access, the string the routine prints); no Linux v5.3 name */
#define SHUB_MD_DIR_ACCESS_LP                        0x100031000 /* established */
#define SHUB_MD_DIR_ACCESS_LP_VALUE_SHIFT            55 /* inferred */
#define SHUB_MD_DIR_ACCESS_LP_VALUE_MASK             0x1ffull
#define SHUB_MD_DIR_ACCESS_LP_VALUE_INPLACE          (SHUB_MD_DIR_ACCESS_LP_VALUE_MASK << SHUB_MD_DIR_ACCESS_LP_VALUE_SHIFT)

/*
 * Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names.
 */
/* md_dqrp_dir_privilege_vector: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_MD_DQRP_DIR_PRIVILEGE_VECTOR            0x100050300 /* established */

/*
 * As md_dir_access_lp for the right queue port block (SH1_MD_DQRP_MMR_DIR_PRIVEC0's block); the name is ours.
 */
/* md_dir_access_rp: w64, reset unknown; SAL 5.04 PROM site 0xffa6b14c; no Linux v5.3 name */
#define SHUB_MD_DIR_ACCESS_RP                        0x100051000 /* established */
#define SHUB_MD_DIR_ACCESS_RP_VALUE_SHIFT            55 /* inferred */
#define SHUB_MD_DIR_ACCESS_RP_VALUE_MASK             0x1ffull
#define SHUB_MD_DIR_ACCESS_RP_VALUE_INPLACE          (SHUB_MD_DIR_ACCESS_RP_VALUE_MASK << SHUB_MD_DIR_ACCESS_RP_VALUE_SHIFT)

/*
 * Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR window with send set, the target's physical processor id, a delivery type, a vector and a fixed base. The kernel stores through uncached physical mode with release ordering, after a memory barrier. On a SHub 1 revision 2 or lower it holds a global lock around the store and waits for the PIO write status to drain.
 */
/* ipi_int: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IPI_INT                                 0x110000380 /* established */
#define SHUB_IPI_INT_SEND_SHIFT                      63 /* established */
#define SHUB_IPI_INT_SEND_MASK                       0x1ull
#define SHUB_IPI_INT_SEND_INPLACE                    (SHUB_IPI_INT_SEND_MASK << SHUB_IPI_INT_SEND_SHIFT)
#define SHUB_IPI_INT_IDX_SHIFT                       52 /* established */
#define SHUB_IPI_INT_IDX_MASK                        0xffull
#define SHUB_IPI_INT_IDX_INPLACE                     (SHUB_IPI_INT_IDX_MASK << SHUB_IPI_INT_IDX_SHIFT)
#define SHUB_IPI_INT_BASE_SHIFT                      21 /* established */
#define SHUB_IPI_INT_BASE_MASK                       0x1fffffffull
#define SHUB_IPI_INT_BASE_INPLACE                    (SHUB_IPI_INT_BASE_MASK << SHUB_IPI_INT_BASE_SHIFT)
#define SHUB_IPI_INT_PID_SHIFT                       4 /* established */
#define SHUB_IPI_INT_PID_MASK                        0xffffull
#define SHUB_IPI_INT_PID_INPLACE                     (SHUB_IPI_INT_PID_MASK << SHUB_IPI_INT_PID_SHIFT)
#define SHUB_IPI_INT_AGENT_SHIFT                     3 /* established */
#define SHUB_IPI_INT_AGENT_MASK                      0x1ull
#define SHUB_IPI_INT_AGENT_INPLACE                   (SHUB_IPI_INT_AGENT_MASK << SHUB_IPI_INT_AGENT_SHIFT)
#define SHUB_IPI_INT_TYPE_SHIFT                      0 /* established */
#define SHUB_IPI_INT_TYPE_MASK                       0x7ull
#define SHUB_IPI_INT_TYPE_INPLACE                    (SHUB_IPI_INT_TYPE_MASK << SHUB_IPI_INT_TYPE_SHIFT)

/*
 * Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and processor id fields and leaves type, agent and base zero. The register has the same layout as the IPI message, without the send bit. A fourth comparator (RTC 0) exists; the driver comment says firmware uses it, and the header defines nothing for it.
 */
/* rtc_int_config: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC_INT_CONFIG                          0x110001480 /* established */
#define SHUB_RTC_INT_CONFIG_COUNT                    3
#define SHUB_RTC_INT_CONFIG_STRIDE                   256
#define SHUB_RTC_INT_CONFIG_IDX_SHIFT                52 /* established */
#define SHUB_RTC_INT_CONFIG_IDX_MASK                 0xffull
#define SHUB_RTC_INT_CONFIG_IDX_INPLACE              (SHUB_RTC_INT_CONFIG_IDX_MASK << SHUB_RTC_INT_CONFIG_IDX_SHIFT)
#define SHUB_RTC_INT_CONFIG_BASE_SHIFT               21 /* established */
#define SHUB_RTC_INT_CONFIG_BASE_MASK                0x1fffffffull
#define SHUB_RTC_INT_CONFIG_BASE_INPLACE             (SHUB_RTC_INT_CONFIG_BASE_MASK << SHUB_RTC_INT_CONFIG_BASE_SHIFT)
#define SHUB_RTC_INT_CONFIG_PID_SHIFT                4 /* established */
#define SHUB_RTC_INT_CONFIG_PID_MASK                 0xffffull
#define SHUB_RTC_INT_CONFIG_PID_INPLACE              (SHUB_RTC_INT_CONFIG_PID_MASK << SHUB_RTC_INT_CONFIG_PID_SHIFT)
#define SHUB_RTC_INT_CONFIG_AGENT_SHIFT              3 /* established */
#define SHUB_RTC_INT_CONFIG_AGENT_MASK               0x1ull
#define SHUB_RTC_INT_CONFIG_AGENT_INPLACE            (SHUB_RTC_INT_CONFIG_AGENT_MASK << SHUB_RTC_INT_CONFIG_AGENT_SHIFT)
#define SHUB_RTC_INT_CONFIG_TYPE_SHIFT               0 /* established */
#define SHUB_RTC_INT_CONFIG_TYPE_MASK                0x7ull
#define SHUB_RTC_INT_CONFIG_TYPE_INPLACE             (SHUB_RTC_INT_CONFIG_TYPE_MASK << SHUB_RTC_INT_CONFIG_TYPE_SHIFT)

/*
 * Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes the configuration, enables, and only then writes the real expiry, in that order.
 */
/* rtc_int_enable: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC_INT_ENABLE                          0x110001500 /* established */
#define SHUB_RTC_INT_ENABLE_COUNT                    3
#define SHUB_RTC_INT_ENABLE_STRIDE                   256
#define SHUB_RTC_INT_ENABLE_ENABLE_SHIFT             0 /* established */
#define SHUB_RTC_INT_ENABLE_ENABLE_MASK              0x1ull
#define SHUB_RTC_INT_ENABLE_ENABLE_INPLACE           (SHUB_RTC_INT_ENABLE_ENABLE_MASK << SHUB_RTC_INT_ENABLE_ENABLE_SHIFT)

/*
 * Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them. Only bits the header names are recorded; the others are unknown.
 */
/* event_occurred: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_EVENT_OCCURRED                          0x110010000 /* established */
#define SHUB_EVENT_OCCURRED_II_INT1_SHIFT            30 /* established */
#define SHUB_EVENT_OCCURRED_II_INT1_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_II_INT1_INPLACE          (SHUB_EVENT_OCCURRED_II_INT1_MASK << SHUB_EVENT_OCCURRED_II_INT1_SHIFT)
#define SHUB_EVENT_OCCURRED_II_INT0_SHIFT            29 /* established */
#define SHUB_EVENT_OCCURRED_II_INT0_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_II_INT0_INPLACE          (SHUB_EVENT_OCCURRED_II_INT0_MASK << SHUB_EVENT_OCCURRED_II_INT0_SHIFT)
#define SHUB_EVENT_OCCURRED_IPI_INT_SHIFT            28 /* established */
#define SHUB_EVENT_OCCURRED_IPI_INT_MASK             0x1ull
#define SHUB_EVENT_OCCURRED_IPI_INT_INPLACE          (SHUB_EVENT_OCCURRED_IPI_INT_MASK << SHUB_EVENT_OCCURRED_IPI_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC3_INT_SHIFT           26 /* established */
#define SHUB_EVENT_OCCURRED_RTC3_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC3_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC3_INT_MASK << SHUB_EVENT_OCCURRED_RTC3_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC2_INT_SHIFT           25 /* established */
#define SHUB_EVENT_OCCURRED_RTC2_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC2_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC2_INT_MASK << SHUB_EVENT_OCCURRED_RTC2_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_RTC1_INT_SHIFT           24 /* established */
#define SHUB_EVENT_OCCURRED_RTC1_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_RTC1_INT_INPLACE         (SHUB_EVENT_OCCURRED_RTC1_INT_MASK << SHUB_EVENT_OCCURRED_RTC1_INT_SHIFT)
#define SHUB_EVENT_OCCURRED_UART_INT_SHIFT           20 /* established */
#define SHUB_EVENT_OCCURRED_UART_INT_MASK            0x1ull
#define SHUB_EVENT_OCCURRED_UART_INT_INPLACE         (SHUB_EVENT_OCCURRED_UART_INT_MASK << SHUB_EVENT_OCCURRED_UART_INT_SHIFT)

/*
 * Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.
 */
/* event_occurred_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_EVENT_OCCURRED_ALIAS                    0x110010008 /* established */

/*
 * Local block register, unnamed; the name is ours (address). SAL_A writes 0x15031010 to it on each of its two entries (reason 3 and reason 0). The image holds no other reference to the address, so it is never read back. The meaning of the value is unknown; a plain write-accepting register satisfies the PROM.
 */
/* lb_reg_1002_0000: w64, reset unknown; SAL 5.04 PROM site 0xffc4e7f0 (offset and use); no Linux v5.3 name */
#define SHUB_LB_REG_1002_0000                        0x110020000 /* established */

/*
 * Per-slice local block record, 128 bytes apart (index = slice & 3); the name is ours. SAL_B reads the running processor's entry in the lock routine and writes its low byte as a progress code, so any value is accepted; SAL_A reads it into r31 for reasons 1 and 2 and for a reason above 3, not for reason 0 (or 3). The meaning of the value is unknown.
 */
/* lb_slice_rec: r64, reset unknown; SAL 5.04 PROM site 0xffa0e020 (read of the running processor's entry), 0xffc4e570 (not reached for reason 0) */
#define SHUB_LB_SLICE_REC                            0x110030000 /* established */
#define SHUB_LB_SLICE_REC_COUNT                      4
#define SHUB_LB_SLICE_REC_STRIDE                     128

/*
 * Real-time clock control; the name is ours. The PROM writes 0x100000000, then writes 0 to rtc, then writes 0x100000041, all at the SAL_B reset entry, before any read. The tick period in nanoseconds is 10 times (the period field + 1); with the PROM's write the field is 4, 50 ns, 20 MHz, which is also what SAL_FREQ_BASE for the real-time clock returns (1,000,000,000 divided by the period). The reset value never reaches the PROM. Roles of the other bits are inferred only. If a read returned 0 the PROM would assume a 10 ns period (100 MHz); every PROM deadline is in microseconds scaled by this period, so the counter must tick at the rate the field gives.
 */
/* rtc_ctl: rw64, reset unknown; SAL 5.04 PROM site 0xffa94d06, 0xffa94d26 (writes), 0xffa0da00 (read of the period); the SAL runtime component's chipset_rtc_period reads the same field */
#define SHUB_RTC_CTL                                 0x110060280 /* established */
#define SHUB_RTC_CTL_MODE_SHIFT                      32 /* inferred */
#define SHUB_RTC_CTL_MODE_MASK                       0x3ull
#define SHUB_RTC_CTL_MODE_INPLACE                    (SHUB_RTC_CTL_MODE_MASK << SHUB_RTC_CTL_MODE_SHIFT)
#define SHUB_RTC_CTL_PERIOD_SHIFT                    4 /* inferred */
#define SHUB_RTC_CTL_PERIOD_MASK                     0x3ffull
#define SHUB_RTC_CTL_PERIOD_INPLACE                  (SHUB_RTC_CTL_PERIOD_MASK << SHUB_RTC_CTL_PERIOD_SHIFT)
#define SHUB_RTC_CTL_RUN_SHIFT                       0 /* inferred */
#define SHUB_RTC_CTL_RUN_MASK                        0x1ull
#define SHUB_RTC_CTL_RUN_INPLACE                     (SHUB_RTC_CTL_RUN_MASK << SHUB_RTC_CTL_RUN_SHIFT)

/*
 * Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross-partition driver reading it as the target of a protected remote read; the driver comment says there is no special reason for that choice. So the register can be read without harm; its bit layout and write behaviour are unknown. The SHub 1 PROM writes 1 here once, as the winner of the node election in SAL_A (SAL 5.04 PROM site 0xffc4ea40); the meaning of 1 is unknown.
 */
/* ipi_access: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_IPI_ACCESS                              0x110060480 /* established */

/*
 * DRAM bus clock select; the name is ours. The memory-controller set-up reads it and uses bits 1:0 as an index into a four-entry table held in flash (200, 160, 133 and 100 MHz for 0 to 3, per the earlier reading). The chosen clock and the DIMM's CAS latency must be a pair the PROM supports or it prints that the memory bus speed is not supported. In the local block by address. Linux does not define it: the position and use are as observed in the PROM, the meaning (bus clock select) is inferred.
 */
/* md_clk_sel: r64, reset unknown; SAL 5.04 PROM site 0xffa77e0c (read through the node's global window), 0xffa77e20 (mask); no Linux v5.3 name */
#define SHUB_MD_CLK_SEL                              0x110060500 /* inferred */
#define SHUB_MD_CLK_SEL_SEL_SHIFT                    0 /* inferred */
#define SHUB_MD_CLK_SEL_SEL_MASK                     0x3ull
#define SHUB_MD_CLK_SEL_SEL_INPLACE                  (SHUB_MD_CLK_SEL_SEL_MASK << SHUB_MD_CLK_SEL_SEL_SHIFT)

/*
 * SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in the fallback for an old PROM the nodes-per-bit field, which it reports as the region size. SHub 2's counterpart is not named in the header. The SHub 1 PROM also writes it (SAL 5.04 PROM site 0xffa95a30, reached from 0xffa5f84c): it reads the word, replaces bits 42:32 with the node id, bits 45:44 with a size code and bits 52:48 with a nodes-per-bit code, and writes the word back; the other bits are stored as read, so they may be read only. After the write the three fields must read back as written. The first read, at main start, needs any node id in bits 42:32; the reset value is unknown. See prom-reset.md.
 */
/* shub_id: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_SHUB_ID                                 0x110060580 /* established */
#define SHUB_SHUB_ID_NODES_PER_BIT_SHIFT             48 /* established */
#define SHUB_SHUB_ID_NODES_PER_BIT_MASK              0x1full
#define SHUB_SHUB_ID_NODES_PER_BIT_INPLACE           (SHUB_SHUB_ID_NODES_PER_BIT_MASK << SHUB_SHUB_ID_NODES_PER_BIT_SHIFT)
#define SHUB_SHUB_ID_SIZE_CODE_SHIFT                 44 /* inferred */
#define SHUB_SHUB_ID_SIZE_CODE_MASK                  0x3ull
#define SHUB_SHUB_ID_SIZE_CODE_INPLACE               (SHUB_SHUB_ID_SIZE_CODE_MASK << SHUB_SHUB_ID_SIZE_CODE_SHIFT)
#define SHUB_SHUB_ID_NASID_SHIFT                     32 /* inferred */
#define SHUB_SHUB_ID_NASID_MASK                      0x7ffull
#define SHUB_SHUB_ID_NASID_INPLACE                   (SHUB_SHUB_ID_NASID_MASK << SHUB_SHUB_ID_NASID_SHIFT)
#define SHUB_SHUB_ID_REVISION_SHIFT                  28 /* established */
#define SHUB_SHUB_ID_REVISION_MASK                   0xfull
#define SHUB_SHUB_ID_REVISION_INPLACE                (SHUB_SHUB_ID_REVISION_MASK << SHUB_SHUB_ID_REVISION_SHIFT)

/*
 * Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel writes the two registers of that node's global window back to back with interrupts and interruption collection off, the first with a type bit, the page-size exponent, the region id and a start bit, the second with the virtual address and a start bit; both stores are in one atomic assembly sequence. It does this once per page of the range, after taking a global lock, for every node that has the mm's processors, except the local node which uses the processor's own global purge instruction instead. Entry 0 is the control word and entry 1 the address word. After a batch of nodes it waits on the PIO write status.
 */
/* ptc: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PTC                                     0x1101a0000 /* established */
#define SHUB_PTC_COUNT                               2
#define SHUB_PTC_STRIDE                              128
#define SHUB_PTC_START_SHIFT                         63 /* established */
#define SHUB_PTC_START_MASK                          0x1ull
#define SHUB_PTC_START_INPLACE                       (SHUB_PTC_START_MASK << SHUB_PTC_START_SHIFT)
#define SHUB_PTC_RID_SHIFT                           8 /* inferred */
#define SHUB_PTC_RID_MASK                            0x7fffffffffffffull
#define SHUB_PTC_RID_INPLACE                         (SHUB_PTC_RID_MASK << SHUB_PTC_RID_SHIFT)
#define SHUB_PTC_PS_SHIFT                            2 /* inferred */
#define SHUB_PTC_PS_MASK                             0x3full
#define SHUB_PTC_PS_INPLACE                          (SHUB_PTC_PS_MASK << SHUB_PTC_PS_SHIFT)
#define SHUB_PTC_TYPE_BIT_SHIFT                      0 /* inferred */
#define SHUB_PTC_TYPE_BIT_MASK                       0x1ull
#define SHUB_PTC_TYPE_BIT_INPLACE                    (SHUB_PTC_TYPE_BIT_MASK << SHUB_PTC_TYPE_BIT_SHIFT)

/*
 * Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).
 */
/* int_cmp: rw64, reset 0x0; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_INT_CMP                                 0x1101b0080 /* established */
#define SHUB_INT_CMP_COUNT                           3
#define SHUB_INT_CMP_STRIDE                          128
#define SHUB_INT_CMP_COMPARE_SHIFT                   0 /* established */
#define SHUB_INT_CMP_COMPARE_MASK                    0x7fffffffffffffull
#define SHUB_INT_CMP_COMPARE_INPLACE                 (SHUB_INT_CMP_COMPARE_MASK << SHUB_INT_CMP_COMPARE_SHIFT)

/*
 * Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only. The SHub 1 PROM (SAL 5.04) writes 0 to it at the SAL_B reset entry (0xffa94d20) and again to a node's counter in the interconnect phase, then reads it on every delay and timeout, so it must advance. Its tick period comes from rtc_ctl (SHub 1: 10 ns times the field plus one, 50 ns after the PROM's own write). See prom-reset.md.
 */
/* rtc: rw64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_RTC                                     0x1101c0000 /* established */
#define SHUB_RTC_COUNTER_SHIFT                       0 /* established */
#define SHUB_RTC_COUNTER_MASK                        0x7fffffffffffffull
#define SHUB_RTC_COUNTER_INPLACE                     (SHUB_RTC_COUNTER_MASK << SHUB_RTC_COUNTER_SHIFT)

/*
 * Node election word; the name is ours. SAL_A stores slice + 1 to lb_elect_set and reads this register: the 64-bit value must equal exactly what was written, twice (site 0xffc4e9b0 and 0xffc4e766). Equal means this processor is the node's winner. Later code ORs bits 39 to 41 into it (set bit 41 when no other processor position is flagged; bit 40 set across nodes; bit 39 on a remote node) as firmware state. The relation to lb_elect_set is unknown: a write to the offset 8 above may alias, latch (first writer wins) or store into this word; the code reads the same register for all three.
 */
/* lb_elect: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e9b0, 0xffc4e766 (election reads), 0xffc4e246, 0xffa0b0f0 (bit updates); no Linux v5.3 name */
#define SHUB_LB_ELECT                                0x1101d0080 /* established */

/*
 * Election write register; the name is ours. SAL_A stores slice + 1 here and reads lb_elect. Whether it aliases lb_elect, latches the first writer or something else is unknown. A model that returns the written value at lb_elect satisfies every access read.
 */
/* lb_elect_set: w64, reset unknown; SAL 5.04 PROM site 0xffc4e9a6 (release store of slice + 1); no Linux v5.3 name */
#define SHUB_LB_ELECT_SET                            0x1101d0088 /* established */

/*
 * L1 link state word in the local block; the name is ours. SAL_A's election winner sets bits 41:39 to 7 by read-modify-write, keeping the other bits. An earlier reading says the L1 start checks bits 41:39 for 7; a later review found no reader that does, so that requirement is unconfirmed and plain storage satisfies the write. Other bits are used by the L1 transport and are not decoded here.
 */
/* lb_l1_state: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e790 and 0xffc4e7a0 (read-modify-write); the PROM's runtime also names the word sc_shub_state_reg and sc_shub_pushed_data_reg */
#define SHUB_LB_L1_STATE                             0x1101d0100 /* established */
#define SHUB_LB_L1_STATE_LINK_SHIFT                  39 /* inferred */
#define SHUB_LB_L1_STATE_LINK_MASK                   0x7ull
#define SHUB_LB_L1_STATE_LINK_INPLACE                (SHUB_LB_L1_STATE_LINK_MASK << SHUB_LB_L1_STATE_LINK_SHIFT)

/*
 * Firmware lock pair, release side; the name is ours. The PROM takes the lock by polling lb_lock_status until it reads 0, does a read-modify-write of cpu_bits, then writes 0 here. If the status does not read 0 within 1,000,000 microseconds it writes 0 here and polls again. Whether a read of lb_lock_status takes the lock in hardware is unknown; a plain register pair where the status always reads 0 satisfies every access read. Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.
 */
/* lb_lock: rw64, reset unknown; SAL 5.04 PROM site 0xffa0ed30 (take), 0xffa0ee40 (release), 0xffa0e730 (user) */
#define SHUB_LB_LOCK                                 0x1101d0200 /* inferred */

/*
 * Firmware lock status; the name is ours. The PROM polls it with a short delay until it reads 0; any non-zero value keeps it waiting until the 1,000,000 microsecond deadline, then it writes 0 to lb_lock and keeps polling, so a status that never reads 0 hangs the PROM. A read side effect is unknown. Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.
 */
/* lb_lock_status: r64, reset unknown; SAL 5.04 PROM site 0xffa0ed30 (the poll); the offset-form variant site 0xffa0e880 reads 0x1101d0208 on a remote node */
#define SHUB_LB_LOCK_STATUS                          0x1101d0208 /* inferred */

/*
 * Processor interface register, unnamed; the name is ours. A SAL_B routine sets bit 24 of pi_reg_2001_0100, reads this register, ORs in 0x3b03f7 when the SHub ID revision (bits 31:28 of shub_id) is above 2 and 0x3f1 otherwise, writes it, then clears bit 24 again. SAL_A's error path writes 0x1000100000000 here (bits 48 and 32) and spins. What the bits mean is unknown; that the OR value splits at revision 2 is established (the same split as the memory controller's 0x4047 and 0x4045).
 */
/* pi_reg_2000_0000: rw64, reset unknown; SAL 5.04 PROM site 0xffa97796 to 0xffa97916 (read, OR, write) and site 0xffc4e276 (SAL_A error path); no Linux v5.3 name */
#define SHUB_PI_REG_2000_0000                        0x120000000 /* established */

/*
 * Processor interface register, unnamed; the name is ours. A routine reached through a table that also writes pi_cam_control reads this register and writes it back with bit 63 set. Meaning unknown.
 */
/* pi_reg_2000_0180: rw64, reset unknown; SAL 5.04 PROM site 0xffa2459c to 0xffa245cc (read, OR bit 63, write); other sites site 0xffae3696; no Linux v5.3 name */
#define SHUB_PI_REG_2000_0180                        0x120000180 /* inferred */

/*
 * Processor interface register, unnamed (the block is inferred from the neighbouring SH1_PI_CAM_CONTROL and SH1_PIO_WRITE_STATUS_0); the name is ours. SAL_A reads it and writes it back with bit 24 set, using the read value for nothing else. The PROM later brackets writes to the register site 0x120000000 with bit 24 set then cleared, which suggests a write enable (inferred). Any reset value is tolerated; bit 24 must be settable and read back as written.
 */
/* pi_reg_2001_0100: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e800 and 0xffc4e816 (read-modify-write); Linux v5.3 defines no name */
#define SHUB_PI_REG_2001_0100                        0x120010100 /* established */
#define SHUB_PI_REG_2001_0100_BIT24_SHIFT            24 /* inferred */
#define SHUB_PI_REG_2001_0100_BIT24_MASK             0x1ull
#define SHUB_PI_REG_2001_0100_BIT24_INPLACE          (SHUB_PI_REG_2001_0100_BIT24_MASK << SHUB_PI_REG_2001_0100_BIT24_SHIFT)
#define SHUB_PI_REG_2001_0100_BIT17_SHIFT            17 /* inferred */
#define SHUB_PI_REG_2001_0100_BIT17_MASK             0x1ull
#define SHUB_PI_REG_2001_0100_BIT17_INPLACE          (SHUB_PI_REG_2001_0100_BIT17_MASK << SHUB_PI_REG_2001_0100_BIT17_SHIFT)
#define SHUB_PI_REG_2001_0100_BIT3_SHIFT             3 /* inferred */
#define SHUB_PI_REG_2001_0100_BIT3_MASK              0x1ull
#define SHUB_PI_REG_2001_0100_BIT3_INPLACE           (SHUB_PI_REG_2001_0100_BIT3_MASK << SHUB_PI_REG_2001_0100_BIT3_SHIFT)

/*
 * Per-slice flags in the processor interface; the name is ours. The local-master arbitration reads it for slices 0 and 1 other than the running one and tests bit slice; a set bit makes the PROM count that processor present and wait for it (up to 5,000,000 microseconds). On a one-processor node the bit for every other slice must read 0. The meaning (processor present) is inferred from that use. Later CPU-enumeration callers of the same word read bits 0 and 1 (first processor of slices 0 and 1) and bits 4 and 5 (second processor); the own-slice bit they expect was not traced, so a model should set it.
 */
/* pi_slice_present: r64, reset unknown; SAL 5.04 PROM site 0xffa115ac (read through the global window of the node), 0xffa99e2c (caller) */
#define SHUB_PI_SLICE_PRESENT                        0x120020080 /* established */
#define SHUB_PI_SLICE_PRESENT_PRESENT2_SHIFT         4 /* inferred */
#define SHUB_PI_SLICE_PRESENT_PRESENT2_MASK          0x3ull
#define SHUB_PI_SLICE_PRESENT_PRESENT2_INPLACE       (SHUB_PI_SLICE_PRESENT_PRESENT2_MASK << SHUB_PI_SLICE_PRESENT_PRESENT2_SHIFT)
#define SHUB_PI_SLICE_PRESENT_PRESENT_SHIFT          0 /* inferred */
#define SHUB_PI_SLICE_PRESENT_PRESENT_MASK           0x3ull
#define SHUB_PI_SLICE_PRESENT_PRESENT_INPLACE        (SHUB_PI_SLICE_PRESENT_PRESENT_MASK << SHUB_PI_SLICE_PRESENT_PRESENT_SHIFT)

/*
 * Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the kernel writes 0x8000000000000010 here on every timer tick, through the address of its own node. What the value does is unknown. The SHub 1 PROM (SAL 5.04) also writes it, from two routines reached through tables (site 0xffa24510 and 0xffa245f0, order not located): the low 7 bits of an argument with bit 63 set, plus bit 8 (and bit 9 when bit 5 of the argument is set) in the first, and with bits 9:8 clear in the second; the second then reads pi_reg_2006_0100, pi_reg_2006_0180 and pi_reg_2006_0200. Meaning of the fields is unknown.
 */
/* pi_cam_control: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PI_CAM_CONTROL                          0x120050300 /* established */

/*
 * Processor interface register, unnamed; the name is ours. Read once, with pi_reg_2006_0180 and pi_reg_2006_0200, right after the second pi_cam_control write; the value is stored for a later report. Any value is tolerated (inferred; the consumer was not traced).
 */
/* pi_reg_2006_0100: r64, reset unknown; SAL 5.04 PROM site 0xffa246a6 (read after the pi_cam_control write); no Linux v5.3 name */
#define SHUB_PI_REG_2006_0100                        0x120060100 /* inferred */

/*
 * Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100.
 */
/* pi_reg_2006_0180: r64, reset unknown; SAL 5.04 PROM site 0xffa246d6; no Linux v5.3 name */
#define SHUB_PI_REG_2006_0180                        0x120060180 /* inferred */

/*
 * Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100.
 */
/* pi_reg_2006_0200: r64, reset unknown; SAL 5.04 PROM site 0xffa246f6; no Linux v5.3 name */
#define SHUB_PI_REG_2006_0200                        0x120060200 /* inferred */

/*
 * PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O write barrier spins until the pending write count shows idle. The kernel stores the address of the instance for its slice (the slice is the processor's position within the node) in its per-processor data.
 */
/* pio_write_status: r64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PIO_WRITE_STATUS                        0x120070200 /* established */
#define SHUB_PIO_WRITE_STATUS_COUNT                  2
#define SHUB_PIO_WRITE_STATUS_STRIDE                 128
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT 56 /* established */
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK 0x3full
#define SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_INPLACE (SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK << SHUB_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_SHIFT)
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT   1 /* established */
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK    0x1ull
#define SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_INPLACE (SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK << SHUB_PIO_WRITE_STATUS_WRITE_DEADLOCK_SHIFT)

/*
 * Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.
 */
/* pio_write_status_alias: w64, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_PIO_WRITE_STATUS_ALIAS                  0x120070208 /* inferred */
#define SHUB_PIO_WRITE_STATUS_ALIAS_COUNT            2
#define SHUB_PIO_WRITE_STATUS_ALIAS_STRIDE           128

/*
 * Progress history of processor slice n (n = cr.lid bits 26:23, 0 to 3), 16 bytes apart; the name is ours. Every progress code is written as: read the word, shift it left 8, put the code in the low byte, write it back. The code is never read for a decision; any reset value is tolerated and the register must return what was last written. SAL_A also reads slice 1 and slice 3 words (0x150031510, 0x150031530) and copies them, ORed with 0x60, to LED registers. The block is the network interface's by address; the PROM uses it as plain storage (inferred).
 */
/* cpu_hist: rw64, reset unknown; SAL 5.04 PROM site 0xffc4e5c6 and 0xffc4e5e0 (progress write), 0xffa0ddb0; no Linux v5.3 name */
#define SHUB_CPU_HIST                                0x150031500 /* established */
#define SHUB_CPU_HIST_COUNT                          4
#define SHUB_CPU_HIST_STRIDE                         16

/*
 * Firmware scratch word; the name is ours. SAL_A's election winner writes 0 to it. No read was found in the reset phase. Plain storage satisfies the access.
 */
/* fw_word_1540: rw64, reset unknown; SAL 5.04 PROM site 0xffc4ea06 (zeroed by the election winner); no Linux v5.3 name */
#define SHUB_FW_WORD_1540                            0x150031540 /* inferred */

/*
 * Firmware per-processor state word; the name is ours. The winner of the SAL_A election zeroes it. Bits the PROM uses: 21 + slice (tested in 0xffa1d430, set in the SAL_B reset entry), 26 + slice (set by the local-master arbitration, polled until the other present processors have set theirs), 30 + slice and bit 34 (a second barrier), 35 + slice (set in the SAL_B reset entry), and a 3-bit count at bit 47 (even slice) or bit 50 (odd slice) that each present slice publishes from a PAL call and the master waits for as that many ready bits among 29:26 (inferred). Bits are set and cleared by read-modify-write under the lock pair lb_lock and lb_lock_status. The SAL_A error path clears bits 29:26. The meanings are inferred from use; the word must read back what was written.
 */
/* cpu_bits: rw64, reset unknown; SAL 5.04 PROM site 0xffc4ea00 (zeroed), 0xffa0e730 (set and clear a bit under the lock), 0xffa1d430 (test), 0xffa99cf0 and 0xffa9a130 (arbitration); no Linux v5.3 name */
#define SHUB_CPU_BITS                                0x150031550 /* established */

/*
 * Firmware debug-switch word; the name is ours. SAL_A's election winner zeroes it; the PROM later stores the L1's reply to request 0x0001 and tests bits of it (bit 11 selects the single-node route, bit 14 skips I/O initialisation). Plain storage.
 */
/* fw_debug_word: rw64, reset unknown; SAL 5.04 PROM site 0xffc4ea10 (zeroed in SAL_A), 0xffa19e50 (loaded from the L1 reply in phase 0xe), 0xffa975e0 (bit test) */
#define SHUB_FW_DEBUG_WORD                           0x150031560 /* inferred */

/*
 * Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.
 */
/* junk_bus_led: w16, reset unknown; Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver */
#define SHUB_JUNK_BUS_LED                            0x7fed00000 /* established */
#define SHUB_JUNK_BUS_LED_COUNT                      4
#define SHUB_JUNK_BUS_LED_STRIDE                     65536

#define SHUB_IPI_BASE_VALUE                          0xfeeu /* established */
#define SHUB_PIO_WRITE_STATUS_ALIAS_CLEAR            0x7u /* established */
#define SHUB_PIO_WRITE_STATUS_IDLE                   0x3f00000000000000ull /* established */
#define SHUB_PI_CAM_WAR_VALUE                        0x8000000000000010ull /* established */
#define SHUB_RTC_CONFIG_MASK                         0xff3ffffffefffffull /* established */
#define SHUB_RTC_ENABLE_MASK                         0x1u /* established */
#define SHUB_RTC_MASK                                0x7fffffffffffffull /* established */
#define SHUB_SHUB_1_1_MAX_REVISION                   0x2u /* established */

#endif /* SHUB_GEN_H */
