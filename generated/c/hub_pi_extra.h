/* generated from devices/hub_pi/registers-extra.toml by defs-gen - do not edit, change the source */
/* Hub processor interface registers, bit layouts and constants outside the census */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/*
 * CPU protection register, named PI_CPU_PROTECT in the header. The header gives no fields. The IRIX register table confirms the access.
 */
/* pi_cpu_protect: rw64, reset 0xffffffffffffffff; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CPU_PROTECT_OFFSET                    0x0u /* established */

/*
 * Protection override register, named PI_PROT_OVRRD in the header as the way to clear a CPU protection bit. The header gives neither an unlock value nor a behaviour, so none is imported. The IRIX register table confirms the access.
 */
/* pi_prot_override: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_PROT_OVERRIDE_OFFSET                  0x8u /* established */

/*
 * Interrupt pending protection register, named PI_IO_PROTECT in the header. The header gives no fields. The IRIX register table confirms the access.
 */
/* pi_io_protect: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_IO_PROTECT_OFFSET                     0x10u /* established */

/*
 * Reply level register, named PI_REPLY_LEVEL in the header. The header gives no fields. The IRIX register table confirms the access.
 */
/* pi_reply_level: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_REPLY_LEVEL_OFFSET                    0x60u /* established */

/*
 * Non-maskable interrupt to processor B, named PI_NMI_B in the header and paired with the processor A register at the same stride. The IRIX register table confirms the access.
 */
/* pi_nmi_b: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_NMI_B_OFFSET                          0x78u /* established */

/*
 * Soft reset, named PI_SOFTRESET in the header with the comment that it resets both processors. The header gives no value and no fields, so the data written is not imported. The IRIX register table confirms the access.
 */
/* pi_softreset: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_SOFTRESET_OFFSET                      0x80u /* established */

/*
 * Cross-call interrupt pending set for processor A, named PI_CC_PEND_SET_A in the header. The IRIX register table confirms the access.
 */
/* pi_cc_pend_set_a: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CC_PEND_SET_A_OFFSET                  0xc8u /* established */

/*
 * Cross-call interrupt pending set for processor B, named PI_CC_PEND_SET_B in the header. The header's pairing rule puts it eight bytes above the processor A set. The IRIX register table confirms the access.
 */
/* pi_cc_pend_set_b: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CC_PEND_SET_B_OFFSET                  0xd0u /* established */

/*
 * Cross-call interrupt pending clear for processor A, named PI_CC_PEND_CLR_A in the header. The IRIX register table confirms the access.
 */
/* pi_cc_pend_clr_a: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CC_PEND_CLR_A_OFFSET                  0xd8u /* established */

/*
 * Cross-call interrupt pending clear for processor B, named PI_CC_PEND_CLR_B in the header. The IRIX register table confirms the access.
 */
/* pi_cc_pend_clr_b: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CC_PEND_CLR_B_OFFSET                  0xe0u /* established */

/*
 * Cross-call interrupt mask, named PI_CC_MASK in the header. The IRIX register table confirms the access.
 */
/* pi_cc_mask: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CC_MASK_OFFSET                        0xe8u /* established */

/*
 * Global clock filter control, named PI_RT_FILTER_CTRL in the header, which gives no fields. It sits next to the real-time clock control register. The IRIX register table confirms the access.
 */
/* pi_rt_filter_ctrl: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_RT_FILTER_CTRL_OFFSET                 0x168u /* established */

/*
 * Built-in self-test write data, named PI_BIST_WRITE_DATA in the header. The IRIX register table confirms the access.
 */
/* pi_bist_write_data: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BIST_WRITE_DATA_OFFSET                0x200u /* established */

/*
 * Built-in self-test read data, named PI_BIST_READ_DATA in the header. The IRIX register table confirms the access.
 */
/* pi_bist_read_data: r64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BIST_READ_DATA_OFFSET                 0x208u /* established */

/*
 * Built-in self-test count and target, named PI_BIST_COUNT_TARG in the header. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.
 */
/* pi_bist_count_targ: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BIST_COUNT_TARG_OFFSET                0x210u /* established */

/*
 * Built-in self-test ready indicator, named PI_BIST_READY in the header. The IRIX register table confirms the access.
 */
/* pi_bist_ready: r64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BIST_READY_OFFSET                     0x218u /* established */

/*
 * Built-in self-test control, named PI_BIST_SHIFT_LOAD in the header. The IRIX register table confirms the access.
 */
/* pi_bist_shift_load: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BIST_SHIFT_LOAD_OFFSET                0x220u /* established */

/*
 * Built-in self-test control, named PI_BIST_SHIFT_UNLOAD in the header. The IRIX register table confirms the access.
 */
/* pi_bist_shift_unload: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BIST_SHIFT_UNLOAD_OFFSET              0x228u /* established */

/*
 * Built-in self-test control, named PI_BIST_ENTER_RUN in the header. The IRIX register table confirms the access.
 */
/* pi_bist_enter_run: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BIST_ENTER_RUN_OFFSET                 0x230u /* established */

/*
 * Graphics page for processor A, named PI_GFX_PAGE_A in the header. The header names only the enable bit, which is in the fields below. The IRIX register table confirms the access.
 */
/* pi_gfx_page_a: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_PAGE_A_OFFSET                     0x300u /* established */
#define HUB_PI_GFX_PAGE_A_ENABLE_SHIFT               40 /* established */
#define HUB_PI_GFX_PAGE_A_ENABLE_MASK                0x1ull
#define HUB_PI_GFX_PAGE_A_ENABLE_INPLACE             (HUB_PI_GFX_PAGE_A_ENABLE_MASK << HUB_PI_GFX_PAGE_A_ENABLE_SHIFT)

/*
 * Graphics credit counter for processor A, named PI_GFX_CREDIT_CNTR_A in the header. The header gives no field layout and no meaning beyond the name. The IRIX register table confirms the access.
 */
/* pi_gfx_credit_cntr_a: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_CREDIT_CNTR_A_OFFSET              0x308u /* established */

/*
 * Graphics bias for processor A, named PI_GFX_BIAS_A in the header. The header gives no field layout. The IRIX register table confirms the access.
 */
/* pi_gfx_bias_a: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_BIAS_A_OFFSET                     0x310u /* established */

/*
 * Graphics interrupt counter for processor A, named PI_GFX_INT_CNTR_A in the header. The header gives no field layout. The IRIX register table confirms the access.
 */
/* pi_gfx_int_cntr_a: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_INT_CNTR_A_OFFSET                 0x318u /* established */

/*
 * Graphics page for processor B, named PI_GFX_PAGE_B in the header. The header's pairing rule puts it 0x28 above the processor A page. The IRIX register table confirms the access.
 */
/* pi_gfx_page_b: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_PAGE_B_OFFSET                     0x328u /* established */
#define HUB_PI_GFX_PAGE_B_ENABLE_SHIFT               40 /* established */
#define HUB_PI_GFX_PAGE_B_ENABLE_MASK                0x1ull
#define HUB_PI_GFX_PAGE_B_ENABLE_INPLACE             (HUB_PI_GFX_PAGE_B_ENABLE_MASK << HUB_PI_GFX_PAGE_B_ENABLE_SHIFT)

/*
 * Graphics credit counter for processor B, named PI_GFX_CREDIT_CNTR_B in the header. The IRIX register table confirms the access.
 */
/* pi_gfx_credit_cntr_b: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_CREDIT_CNTR_B_OFFSET              0x330u /* established */

/*
 * Graphics bias for processor B, named PI_GFX_BIAS_B in the header. The IRIX register table confirms the access.
 */
/* pi_gfx_bias_b: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_BIAS_B_OFFSET                     0x338u /* established */

/*
 * Graphics interrupt counter for processor B, named PI_GFX_INT_CNTR_B in the header. The IRIX register table confirms the access.
 */
/* pi_gfx_int_cntr_b: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_GFX_INT_CNTR_B_OFFSET                 0x340u /* established */

/*
 * Clear-on-read alias of error status 0 for processor A, named PI_ERR_STATUS0_A_RCLR in the header. The header's comment says a read clears the register. The IRIX register table confirms the access.
 */
/* pi_err_status0_a_rclr: r64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_ERR_STATUS0_A_RCLR_OFFSET             0x438u /* established */

/*
 * Clear-on-read alias of error status 0 for processor B, named PI_ERR_STATUS0_B_RCLR in the header. The header's comment says a read clears the register. The IRIX register table confirms the access.
 */
/* pi_err_status0_b_rclr: r64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_ERR_STATUS0_B_RCLR_OFFSET             0x458u /* established */

/*
 * Error spool compare for processor A, named PI_SPOOL_CMP_A in the header. The header gives no field layout. The IRIX register table confirms the access.
 */
/* pi_spool_cmp_a: rw64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_SPOOL_CMP_A_OFFSET                    0x470u /* established */

/*
 * Error spool compare for processor B, named PI_SPOOL_CMP_B in the header. The IRIX register table confirms the access.
 */
/* pi_spool_cmp_b: rw64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_SPOOL_CMP_B_OFFSET                    0x478u /* established */

/*
 * Timed-out CRB entries for processor A, named PI_CRB_TIMEOUT_A in the header. The header gives no field layout. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.
 */
/* pi_crb_timeout_a: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CRB_TIMEOUT_A_OFFSET                  0x480u /* established */

/*
 * Timed-out CRB entries for processor B, named PI_CRB_TIMEOUT_B in the header. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.
 */
/* pi_crb_timeout_b: w64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_CRB_TIMEOUT_B_OFFSET                  0x488u /* established */

/*
 * Enables for the processor bus checks, named PI_SYSAD_ERRCHK_EN in the header. Six enable bits, each named in the header's constants. The IRIX register table confirms the access.
 */
/* pi_sysad_errchk_en: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_SYSAD_ERRCHK_EN_OFFSET                0x490u /* established */
#define HUB_PI_SYSAD_ERRCHK_EN_QUAL_SHIFT            5 /* established */
#define HUB_PI_SYSAD_ERRCHK_EN_QUAL_MASK             0x1ull
#define HUB_PI_SYSAD_ERRCHK_EN_QUAL_INPLACE          (HUB_PI_SYSAD_ERRCHK_EN_QUAL_MASK << HUB_PI_SYSAD_ERRCHK_EN_QUAL_SHIFT)
#define HUB_PI_SYSAD_ERRCHK_EN_STATE_SHIFT           4 /* established */
#define HUB_PI_SYSAD_ERRCHK_EN_STATE_MASK            0x1ull
#define HUB_PI_SYSAD_ERRCHK_EN_STATE_INPLACE         (HUB_PI_SYSAD_ERRCHK_EN_STATE_MASK << HUB_PI_SYSAD_ERRCHK_EN_STATE_SHIFT)
#define HUB_PI_SYSAD_ERRCHK_EN_CMDP_SHIFT            3 /* established */
#define HUB_PI_SYSAD_ERRCHK_EN_CMDP_MASK             0x1ull
#define HUB_PI_SYSAD_ERRCHK_EN_CMDP_INPLACE          (HUB_PI_SYSAD_ERRCHK_EN_CMDP_MASK << HUB_PI_SYSAD_ERRCHK_EN_CMDP_SHIFT)
#define HUB_PI_SYSAD_ERRCHK_EN_SADP_SHIFT            2 /* established */
#define HUB_PI_SYSAD_ERRCHK_EN_SADP_MASK             0x1ull
#define HUB_PI_SYSAD_ERRCHK_EN_SADP_INPLACE          (HUB_PI_SYSAD_ERRCHK_EN_SADP_MASK << HUB_PI_SYSAD_ERRCHK_EN_SADP_SHIFT)
#define HUB_PI_SYSAD_ERRCHK_EN_QUALGEN_SHIFT         1 /* established */
#define HUB_PI_SYSAD_ERRCHK_EN_QUALGEN_MASK          0x1ull
#define HUB_PI_SYSAD_ERRCHK_EN_QUALGEN_INPLACE       (HUB_PI_SYSAD_ERRCHK_EN_QUALGEN_MASK << HUB_PI_SYSAD_ERRCHK_EN_QUALGEN_SHIFT)
#define HUB_PI_SYSAD_ERRCHK_EN_ECCGEN_SHIFT          0 /* established */
#define HUB_PI_SYSAD_ERRCHK_EN_ECCGEN_MASK           0x1ull
#define HUB_PI_SYSAD_ERRCHK_EN_ECCGEN_INPLACE        (HUB_PI_SYSAD_ERRCHK_EN_ECCGEN_MASK << HUB_PI_SYSAD_ERRCHK_EN_ECCGEN_SHIFT)

/*
 * Forced SysAD check-bit error for processor A, named PI_BAD_CHECK_BIT_A in the header and described there as diagnostic. The header gives no field layout. The IRIX register table confirms the access.
 */
/* pi_bad_check_bit_a: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BAD_CHECK_BIT_A_OFFSET                0x498u /* established */

/*
 * Forced SysAD check-bit error for processor B, named PI_BAD_CHECK_BIT_B in the header. The IRIX register table confirms the access.
 */
/* pi_bad_check_bit_b: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_BAD_CHECK_BIT_B_OFFSET                0x4a0u /* established */

/*
 * Consecutive negative-acknowledge counter for processor A, named PI_NACK_CNT_A in the header. The IRIX register table confirms the access.
 */
/* pi_nack_cnt_a: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_NACK_CNT_A_OFFSET                     0x4a8u /* established */
#define HUB_PI_NACK_CNT_A_ENABLE_SHIFT               20 /* established */
#define HUB_PI_NACK_CNT_A_ENABLE_MASK                0x1ull
#define HUB_PI_NACK_CNT_A_ENABLE_INPLACE             (HUB_PI_NACK_CNT_A_ENABLE_MASK << HUB_PI_NACK_CNT_A_ENABLE_SHIFT)
#define HUB_PI_NACK_CNT_A_COUNT_SHIFT                0 /* established */
#define HUB_PI_NACK_CNT_A_COUNT_MASK                 0xfffffull
#define HUB_PI_NACK_CNT_A_COUNT_INPLACE              (HUB_PI_NACK_CNT_A_COUNT_MASK << HUB_PI_NACK_CNT_A_COUNT_SHIFT)

/*
 * Consecutive negative-acknowledge counter for processor B, named PI_NACK_CNT_B in the header. The IRIX register table confirms the access.
 */
/* pi_nack_cnt_b: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_NACK_CNT_B_OFFSET                     0x4b0u /* established */
#define HUB_PI_NACK_CNT_B_ENABLE_SHIFT               20 /* established */
#define HUB_PI_NACK_CNT_B_ENABLE_MASK                0x1ull
#define HUB_PI_NACK_CNT_B_ENABLE_INPLACE             (HUB_PI_NACK_CNT_B_ENABLE_MASK << HUB_PI_NACK_CNT_B_ENABLE_SHIFT)
#define HUB_PI_NACK_CNT_B_COUNT_SHIFT                0 /* established */
#define HUB_PI_NACK_CNT_B_COUNT_MASK                 0xfffffull
#define HUB_PI_NACK_CNT_B_COUNT_INPLACE              (HUB_PI_NACK_CNT_B_COUNT_MASK << HUB_PI_NACK_CNT_B_COUNT_SHIFT)

/*
 * Negative-acknowledge compare, named PI_NACK_CMP in the header. The header gives a maximum of 0x0fffff for the count, so the compare is twenty bits wide. The IRIX register table confirms the access.
 */
/* pi_nack_cmp: rw64, reset 0x0; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_NACK_CMP_OFFSET                       0x4b8u /* established */

/*
 * Layout of the interrupt pending modify register, pi_int_pend_mod, as Linux writes it: a set bit and an interrupt level. Linux only writes the register. Whether a second processor in a node reaches it at another offset is not established by a public source and is not recorded.
 */
/* word PI_INT_PEND_MOD_FORMAT: 64 bits; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_INT_PEND_MOD_FORMAT_WIDTH             64 /* inferred */
#define HUB_PI_INT_PEND_MOD_FORMAT_SET_SHIFT         8 /* inferred */
#define HUB_PI_INT_PEND_MOD_FORMAT_SET_MASK          0x1ull
#define HUB_PI_INT_PEND_MOD_FORMAT_SET_INPLACE       (HUB_PI_INT_PEND_MOD_FORMAT_SET_MASK << HUB_PI_INT_PEND_MOD_FORMAT_SET_SHIFT)
#define HUB_PI_INT_PEND_MOD_FORMAT_LEVEL_SHIFT       0 /* inferred */
#define HUB_PI_INT_PEND_MOD_FORMAT_LEVEL_MASK        0x7full
#define HUB_PI_INT_PEND_MOD_FORMAT_LEVEL_INPLACE     (HUB_PI_INT_PEND_MOD_FORMAT_LEVEL_MASK << HUB_PI_INT_PEND_MOD_FORMAT_LEVEL_SHIFT)

/*
 * Layout of the real-time counter local control register, the register the census names by its real-time clock control name. The header's mask and shift definitions give the fields below. The header gives no access type or reset value for it.
 */
/* word PI_RT_LOCAL_CTRL_FORMAT: 64 bits; public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions */
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_WIDTH            64 /* established */
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_USE_INTERNAL_SHIFT 16 /* established */
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_USE_INTERNAL_MASK 0x1ull
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_USE_INTERNAL_INPLACE (HUB_PI_RT_LOCAL_CTRL_FORMAT_USE_INTERNAL_MASK << HUB_PI_RT_LOCAL_CTRL_FORMAT_USE_INTERNAL_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_SHIFT       15 /* established */
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_MASK        0x1ull
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_INPLACE     (HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_MASK << HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_COUNT_SHIFT 8 /* established */
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_COUNT_MASK  0x7full
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_COUNT_INPLACE (HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_COUNT_MASK << HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_COUNT_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_MAX_COUNT_SHIFT  1 /* established */
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_MAX_COUNT_MASK   0x7full
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_MAX_COUNT_INPLACE (HUB_PI_RT_LOCAL_CTRL_FORMAT_MAX_COUNT_MASK << HUB_PI_RT_LOCAL_CTRL_FORMAT_MAX_COUNT_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_EN_SHIFT    0 /* established */
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_EN_MASK     0x1ull
#define HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_EN_INPLACE  (HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_EN_MASK << HUB_PI_RT_LOCAL_CTRL_FORMAT_GCLK_EN_SHIFT)

#define HUB_IP_ERROR                                 0x4000u /* established */
#define HUB_IP_MASK                                  0x7c00u /* established */
#define HUB_IP_PEND0                                 0x400u /* established */
#define HUB_IP_PEND1_CC                              0x800u /* established */
#define HUB_IP_PROF                                  0x2000u /* established */
#define HUB_IP_RT                                    0x1000u /* established */
#define HUB_PI_CALIAS_SIZE_0                         0x0u /* established */
#define HUB_PI_CALIAS_SIZE_128K                      0x6u /* established */
#define HUB_PI_CALIAS_SIZE_16K                       0x3u /* established */
#define HUB_PI_CALIAS_SIZE_16M                       0xdu /* established */
#define HUB_PI_CALIAS_SIZE_1M                        0x9u /* established */
#define HUB_PI_CALIAS_SIZE_256K                      0x7u /* established */
#define HUB_PI_CALIAS_SIZE_2M                        0xau /* established */
#define HUB_PI_CALIAS_SIZE_32K                       0x4u /* established */
#define HUB_PI_CALIAS_SIZE_32M                       0xeu /* established */
#define HUB_PI_CALIAS_SIZE_4K                        0x1u /* established */
#define HUB_PI_CALIAS_SIZE_4M                        0xbu /* established */
#define HUB_PI_CALIAS_SIZE_512K                      0x8u /* established */
#define HUB_PI_CALIAS_SIZE_64K                       0x5u /* established */
#define HUB_PI_CALIAS_SIZE_64M                       0xfu /* established */
#define HUB_PI_CALIAS_SIZE_8K                        0x2u /* established */
#define HUB_PI_CALIAS_SIZE_8M                        0xcu /* established */
#define HUB_PI_LOCAL_WINDOW_BASE                     0x1000000u /* established */
#define HUB_PI_NODE_SHIFT                            0x20u /* established */
#define HUB_PI_NODE_WINDOW_BASE                      0x1800000u /* established */

#endif /* HUB_GEN_H */
