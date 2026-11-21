/* generated from devices/hub_pi/registers-extra.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 6bd43d1a2beced09685294a1651d96ebd8187133f5b5a5408a19ea14d79ea62b */
/* Hub processor interface registers, bit layouts and constants outside the census */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/* enum pi_calias_size */
#define HUB_PI_CALIAS_SIZE_SIZE_NONE                 0 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_4K                   1 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_8K                   2 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_16K                  3 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_32K                  4 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_64K                  5 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_128K                 6 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_256K                 7 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_512K                 8 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_1M                   9 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_2M                   10 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_4M                   11 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_8M                   12 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_16M                  13 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_32M                  14 /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_64M                  15 /* established */

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

/* pi_calias_size: rw64, reset 0xf; census: 3 sites, 3 routines (rw); census: 2 sites, 2 routines (rw, indexed) */
#define HUB_PI_CALIAS_SIZE_OFFSET                    0x28u /* established */
#define HUB_PI_CALIAS_SIZE_SIZE_SHIFT                0 /* inferred */
#define HUB_PI_CALIAS_SIZE_SIZE_MASK                 0xfull
#define HUB_PI_CALIAS_SIZE_SIZE_INPLACE              (HUB_PI_CALIAS_SIZE_SIZE_MASK << HUB_PI_CALIAS_SIZE_SIZE_SHIFT)

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
 * Layout of the interrupt pending modify register, pi_int_pend_mod, as Linux writes it: a set bit and an interrupt level. Linux only writes the register. Whether a second processor in a node reaches it at another offset is not established by a public source and is not recorded.
 */
/* pi_int_pend_mod: w64, reset unknown; census: 9 sites, 8 routines (w); census: 8 sites, 8 routines (w, indexed) */
#define HUB_PI_INT_PEND_MOD_OFFSET                   0x90u /* established */
#define HUB_PI_INT_PEND_MOD_SET_SHIFT                8 /* inferred */
#define HUB_PI_INT_PEND_MOD_SET_MASK                 0x1ull
#define HUB_PI_INT_PEND_MOD_SET_INPLACE              (HUB_PI_INT_PEND_MOD_SET_MASK << HUB_PI_INT_PEND_MOD_SET_SHIFT)
#define HUB_PI_INT_PEND_MOD_LEVEL_SHIFT              0 /* inferred */
#define HUB_PI_INT_PEND_MOD_LEVEL_MASK               0x7full
#define HUB_PI_INT_PEND_MOD_LEVEL_INPLACE            (HUB_PI_INT_PEND_MOD_LEVEL_MASK << HUB_PI_INT_PEND_MOD_LEVEL_SHIFT)

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
 * Layout of the real-time counter local control register, the register the census names by its real-time clock control name. The header's mask and shift definitions give the fields below. The header gives no access type or reset value for it.
 */
/* pi_rt_local_ctrl: rw64, reset unknown; census: 6 sites, 1 routines */
#define HUB_PI_RT_LOCAL_CTRL_OFFSET                  0x160u /* established */
#define HUB_PI_RT_LOCAL_CTRL_USE_INTERNAL_SHIFT      16 /* established */
#define HUB_PI_RT_LOCAL_CTRL_USE_INTERNAL_MASK       0x1ull
#define HUB_PI_RT_LOCAL_CTRL_USE_INTERNAL_INPLACE    (HUB_PI_RT_LOCAL_CTRL_USE_INTERNAL_MASK << HUB_PI_RT_LOCAL_CTRL_USE_INTERNAL_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_GCLK_SHIFT              15 /* established */
#define HUB_PI_RT_LOCAL_CTRL_GCLK_MASK               0x1ull
#define HUB_PI_RT_LOCAL_CTRL_GCLK_INPLACE            (HUB_PI_RT_LOCAL_CTRL_GCLK_MASK << HUB_PI_RT_LOCAL_CTRL_GCLK_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_GCLK_COUNT_SHIFT        8 /* established */
#define HUB_PI_RT_LOCAL_CTRL_GCLK_COUNT_MASK         0x7full
#define HUB_PI_RT_LOCAL_CTRL_GCLK_COUNT_INPLACE      (HUB_PI_RT_LOCAL_CTRL_GCLK_COUNT_MASK << HUB_PI_RT_LOCAL_CTRL_GCLK_COUNT_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_MAX_COUNT_SHIFT         1 /* established */
#define HUB_PI_RT_LOCAL_CTRL_MAX_COUNT_MASK          0x7full
#define HUB_PI_RT_LOCAL_CTRL_MAX_COUNT_INPLACE       (HUB_PI_RT_LOCAL_CTRL_MAX_COUNT_MASK << HUB_PI_RT_LOCAL_CTRL_MAX_COUNT_SHIFT)
#define HUB_PI_RT_LOCAL_CTRL_GCLK_EN_SHIFT           0 /* established */
#define HUB_PI_RT_LOCAL_CTRL_GCLK_EN_MASK            0x1ull
#define HUB_PI_RT_LOCAL_CTRL_GCLK_EN_INPLACE         (HUB_PI_RT_LOCAL_CTRL_GCLK_EN_MASK << HUB_PI_RT_LOCAL_CTRL_GCLK_EN_SHIFT)

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
 * Bit pairs are B then A (even bit B, odd bit A) for bits 0 to 23.
 */
/* pi_err_int_pend: rw64, reset unknown; census: 13 sites, 5 routines (rw); census: 3 sites, 2 routines (rw, indexed) */
#define HUB_PI_ERR_INT_PEND_OFFSET                   0x400u /* established */
#define HUB_PI_ERR_INT_PEND_MD_UNCORR_SHIFT          24 /* established */
#define HUB_PI_ERR_INT_PEND_MD_UNCORR_MASK           0x1ull
#define HUB_PI_ERR_INT_PEND_MD_UNCORR_INPLACE        (HUB_PI_ERR_INT_PEND_MD_UNCORR_MASK << HUB_PI_ERR_INT_PEND_MD_UNCORR_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_A_SHIFT     23 /* established */
#define HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_A_MASK      0x1ull
#define HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_A_INPLACE   (HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_A_MASK << HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_B_SHIFT     22 /* established */
#define HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_B_MASK      0x1ull
#define HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_B_INPLACE   (HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_B_MASK << HUB_PI_ERR_INT_PEND_SYSSTATE_TAG_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_A_SHIFT     21 /* established */
#define HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_A_MASK      0x1ull
#define HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_A_INPLACE   (HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_A_MASK << HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_B_SHIFT     20 /* established */
#define HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_B_MASK      0x1ull
#define HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_B_INPLACE   (HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_B_MASK << HUB_PI_ERR_INT_PEND_UNCAC_UNCORR_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_BAD_SPOOL_A_SHIFT        19 /* established */
#define HUB_PI_ERR_INT_PEND_BAD_SPOOL_A_MASK         0x1ull
#define HUB_PI_ERR_INT_PEND_BAD_SPOOL_A_INPLACE      (HUB_PI_ERR_INT_PEND_BAD_SPOOL_A_MASK << HUB_PI_ERR_INT_PEND_BAD_SPOOL_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_BAD_SPOOL_B_SHIFT        18 /* established */
#define HUB_PI_ERR_INT_PEND_BAD_SPOOL_B_MASK         0x1ull
#define HUB_PI_ERR_INT_PEND_BAD_SPOOL_B_INPLACE      (HUB_PI_ERR_INT_PEND_BAD_SPOOL_B_MASK << HUB_PI_ERR_INT_PEND_BAD_SPOOL_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_A_SHIFT      17 /* established */
#define HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_A_MASK       0x1ull
#define HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_A_INPLACE    (HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_A_MASK << HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_B_SHIFT      16 /* established */
#define HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_B_MASK       0x1ull
#define HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_B_INPLACE    (HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_B_MASK << HUB_PI_ERR_INT_PEND_SYSCMD_ADDR_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSCMD_DATA_A_SHIFT      15 /* established */
#define HUB_PI_ERR_INT_PEND_SYSCMD_DATA_A_MASK       0x1ull
#define HUB_PI_ERR_INT_PEND_SYSCMD_DATA_A_INPLACE    (HUB_PI_ERR_INT_PEND_SYSCMD_DATA_A_MASK << HUB_PI_ERR_INT_PEND_SYSCMD_DATA_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSCMD_DATA_B_SHIFT      14 /* established */
#define HUB_PI_ERR_INT_PEND_SYSCMD_DATA_B_MASK       0x1ull
#define HUB_PI_ERR_INT_PEND_SYSCMD_DATA_B_INPLACE    (HUB_PI_ERR_INT_PEND_SYSCMD_DATA_B_MASK << HUB_PI_ERR_INT_PEND_SYSCMD_DATA_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSAD_ADDR_A_SHIFT       13 /* established */
#define HUB_PI_ERR_INT_PEND_SYSAD_ADDR_A_MASK        0x1ull
#define HUB_PI_ERR_INT_PEND_SYSAD_ADDR_A_INPLACE     (HUB_PI_ERR_INT_PEND_SYSAD_ADDR_A_MASK << HUB_PI_ERR_INT_PEND_SYSAD_ADDR_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSAD_ADDR_B_SHIFT       12 /* established */
#define HUB_PI_ERR_INT_PEND_SYSAD_ADDR_B_MASK        0x1ull
#define HUB_PI_ERR_INT_PEND_SYSAD_ADDR_B_INPLACE     (HUB_PI_ERR_INT_PEND_SYSAD_ADDR_B_MASK << HUB_PI_ERR_INT_PEND_SYSAD_ADDR_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSAD_DATA_A_SHIFT       11 /* established */
#define HUB_PI_ERR_INT_PEND_SYSAD_DATA_A_MASK        0x1ull
#define HUB_PI_ERR_INT_PEND_SYSAD_DATA_A_INPLACE     (HUB_PI_ERR_INT_PEND_SYSAD_DATA_A_MASK << HUB_PI_ERR_INT_PEND_SYSAD_DATA_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSAD_DATA_B_SHIFT       10 /* established */
#define HUB_PI_ERR_INT_PEND_SYSAD_DATA_B_MASK        0x1ull
#define HUB_PI_ERR_INT_PEND_SYSAD_DATA_B_INPLACE     (HUB_PI_ERR_INT_PEND_SYSAD_DATA_B_MASK << HUB_PI_ERR_INT_PEND_SYSAD_DATA_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSSTATE_A_SHIFT         9 /* established */
#define HUB_PI_ERR_INT_PEND_SYSSTATE_A_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_SYSSTATE_A_INPLACE       (HUB_PI_ERR_INT_PEND_SYSSTATE_A_MASK << HUB_PI_ERR_INT_PEND_SYSSTATE_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SYSSTATE_B_SHIFT         8 /* established */
#define HUB_PI_ERR_INT_PEND_SYSSTATE_B_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_SYSSTATE_B_INPLACE       (HUB_PI_ERR_INT_PEND_SYSSTATE_B_MASK << HUB_PI_ERR_INT_PEND_SYSSTATE_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_WRB_WERR_A_SHIFT         7 /* established */
#define HUB_PI_ERR_INT_PEND_WRB_WERR_A_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_WRB_WERR_A_INPLACE       (HUB_PI_ERR_INT_PEND_WRB_WERR_A_MASK << HUB_PI_ERR_INT_PEND_WRB_WERR_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_WRB_WERR_B_SHIFT         6 /* established */
#define HUB_PI_ERR_INT_PEND_WRB_WERR_B_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_WRB_WERR_B_INPLACE       (HUB_PI_ERR_INT_PEND_WRB_WERR_B_MASK << HUB_PI_ERR_INT_PEND_WRB_WERR_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_WRB_TERR_A_SHIFT         5 /* established */
#define HUB_PI_ERR_INT_PEND_WRB_TERR_A_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_WRB_TERR_A_INPLACE       (HUB_PI_ERR_INT_PEND_WRB_TERR_A_MASK << HUB_PI_ERR_INT_PEND_WRB_TERR_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_WRB_TERR_B_SHIFT         4 /* established */
#define HUB_PI_ERR_INT_PEND_WRB_TERR_B_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_WRB_TERR_B_INPLACE       (HUB_PI_ERR_INT_PEND_WRB_TERR_B_MASK << HUB_PI_ERR_INT_PEND_WRB_TERR_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_SPUR_MSG_A_SHIFT         3 /* established */
#define HUB_PI_ERR_INT_PEND_SPUR_MSG_A_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_SPUR_MSG_A_INPLACE       (HUB_PI_ERR_INT_PEND_SPUR_MSG_A_MASK << HUB_PI_ERR_INT_PEND_SPUR_MSG_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SPUR_MSG_B_SHIFT         2 /* established */
#define HUB_PI_ERR_INT_PEND_SPUR_MSG_B_MASK          0x1ull
#define HUB_PI_ERR_INT_PEND_SPUR_MSG_B_INPLACE       (HUB_PI_ERR_INT_PEND_SPUR_MSG_B_MASK << HUB_PI_ERR_INT_PEND_SPUR_MSG_B_SHIFT)
#define HUB_PI_ERR_INT_PEND_SPOOL_CMP_A_SHIFT        1 /* established */
#define HUB_PI_ERR_INT_PEND_SPOOL_CMP_A_MASK         0x1ull
#define HUB_PI_ERR_INT_PEND_SPOOL_CMP_A_INPLACE      (HUB_PI_ERR_INT_PEND_SPOOL_CMP_A_MASK << HUB_PI_ERR_INT_PEND_SPOOL_CMP_A_SHIFT)
#define HUB_PI_ERR_INT_PEND_SPOOL_CMP_B_SHIFT        0 /* established */
#define HUB_PI_ERR_INT_PEND_SPOOL_CMP_B_MASK         0x1ull
#define HUB_PI_ERR_INT_PEND_SPOOL_CMP_B_INPLACE      (HUB_PI_ERR_INT_PEND_SPOOL_CMP_B_MASK << HUB_PI_ERR_INT_PEND_SPOOL_CMP_B_SHIFT)

/* pi_err_int_mask_a: rw64, reset 0x0; census: 5 sites, 2 routines (rw); census: 1 sites, 1 routines (w, indexed) */
#define HUB_PI_ERR_INT_MASK_A_OFFSET                 0x408u /* established */
#define HUB_PI_ERR_INT_MASK_A_MD_UNCORR_SHIFT        24 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_MD_UNCORR_MASK         0x1ull
#define HUB_PI_ERR_INT_MASK_A_MD_UNCORR_INPLACE      (HUB_PI_ERR_INT_MASK_A_MD_UNCORR_MASK << HUB_PI_ERR_INT_MASK_A_MD_UNCORR_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_A_SHIFT   23 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_A_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_A_INPLACE (HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_A_MASK << HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_B_SHIFT   22 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_B_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_B_INPLACE (HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_B_MASK << HUB_PI_ERR_INT_MASK_A_SYSSTATE_TAG_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_A_SHIFT   21 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_A_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_A_INPLACE (HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_A_MASK << HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_B_SHIFT   20 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_B_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_B_INPLACE (HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_B_MASK << HUB_PI_ERR_INT_MASK_A_UNCAC_UNCORR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_A_SHIFT      19 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_A_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_A_INPLACE    (HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_A_MASK << HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_B_SHIFT      18 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_B_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_B_INPLACE    (HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_B_MASK << HUB_PI_ERR_INT_MASK_A_BAD_SPOOL_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_A_SHIFT    17 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_A_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_A_INPLACE  (HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_A_MASK << HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_B_SHIFT    16 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_B_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_B_INPLACE  (HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_B_MASK << HUB_PI_ERR_INT_MASK_A_SYSCMD_ADDR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_A_SHIFT    15 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_A_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_A_INPLACE  (HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_A_MASK << HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_B_SHIFT    14 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_B_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_B_INPLACE  (HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_B_MASK << HUB_PI_ERR_INT_MASK_A_SYSCMD_DATA_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_A_SHIFT     13 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_A_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_A_INPLACE   (HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_A_MASK << HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_B_SHIFT     12 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_B_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_B_INPLACE   (HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_B_MASK << HUB_PI_ERR_INT_MASK_A_SYSAD_ADDR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_A_SHIFT     11 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_A_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_A_INPLACE   (HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_A_MASK << HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_B_SHIFT     10 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_B_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_B_INPLACE   (HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_B_MASK << HUB_PI_ERR_INT_MASK_A_SYSAD_DATA_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_A_SHIFT       9 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_A_INPLACE     (HUB_PI_ERR_INT_MASK_A_SYSSTATE_A_MASK << HUB_PI_ERR_INT_MASK_A_SYSSTATE_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_B_SHIFT       8 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_SYSSTATE_B_INPLACE     (HUB_PI_ERR_INT_MASK_A_SYSSTATE_B_MASK << HUB_PI_ERR_INT_MASK_A_SYSSTATE_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_WRB_WERR_A_SHIFT       7 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_WRB_WERR_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_WRB_WERR_A_INPLACE     (HUB_PI_ERR_INT_MASK_A_WRB_WERR_A_MASK << HUB_PI_ERR_INT_MASK_A_WRB_WERR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_WRB_WERR_B_SHIFT       6 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_WRB_WERR_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_WRB_WERR_B_INPLACE     (HUB_PI_ERR_INT_MASK_A_WRB_WERR_B_MASK << HUB_PI_ERR_INT_MASK_A_WRB_WERR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_WRB_TERR_A_SHIFT       5 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_WRB_TERR_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_WRB_TERR_A_INPLACE     (HUB_PI_ERR_INT_MASK_A_WRB_TERR_A_MASK << HUB_PI_ERR_INT_MASK_A_WRB_TERR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_WRB_TERR_B_SHIFT       4 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_WRB_TERR_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_WRB_TERR_B_INPLACE     (HUB_PI_ERR_INT_MASK_A_WRB_TERR_B_MASK << HUB_PI_ERR_INT_MASK_A_WRB_TERR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SPUR_MSG_A_SHIFT       3 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SPUR_MSG_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_SPUR_MSG_A_INPLACE     (HUB_PI_ERR_INT_MASK_A_SPUR_MSG_A_MASK << HUB_PI_ERR_INT_MASK_A_SPUR_MSG_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SPUR_MSG_B_SHIFT       2 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SPUR_MSG_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_A_SPUR_MSG_B_INPLACE     (HUB_PI_ERR_INT_MASK_A_SPUR_MSG_B_MASK << HUB_PI_ERR_INT_MASK_A_SPUR_MSG_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_A_SHIFT      1 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_A_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_A_INPLACE    (HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_A_MASK << HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_B_SHIFT      0 /* inferred */
#define HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_B_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_B_INPLACE    (HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_B_MASK << HUB_PI_ERR_INT_MASK_A_SPOOL_CMP_B_SHIFT)

/* pi_err_int_mask_b: rw64, reset 0x0; census: 5 sites, 2 routines (rw); census: 1 sites, 1 routines (w, indexed) */
#define HUB_PI_ERR_INT_MASK_B_OFFSET                 0x410u /* established */
#define HUB_PI_ERR_INT_MASK_B_MD_UNCORR_SHIFT        24 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_MD_UNCORR_MASK         0x1ull
#define HUB_PI_ERR_INT_MASK_B_MD_UNCORR_INPLACE      (HUB_PI_ERR_INT_MASK_B_MD_UNCORR_MASK << HUB_PI_ERR_INT_MASK_B_MD_UNCORR_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_A_SHIFT   23 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_A_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_A_INPLACE (HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_A_MASK << HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_B_SHIFT   22 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_B_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_B_INPLACE (HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_B_MASK << HUB_PI_ERR_INT_MASK_B_SYSSTATE_TAG_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_A_SHIFT   21 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_A_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_A_INPLACE (HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_A_MASK << HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_B_SHIFT   20 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_B_MASK    0x1ull
#define HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_B_INPLACE (HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_B_MASK << HUB_PI_ERR_INT_MASK_B_UNCAC_UNCORR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_A_SHIFT      19 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_A_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_A_INPLACE    (HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_A_MASK << HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_B_SHIFT      18 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_B_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_B_INPLACE    (HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_B_MASK << HUB_PI_ERR_INT_MASK_B_BAD_SPOOL_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_A_SHIFT    17 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_A_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_A_INPLACE  (HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_A_MASK << HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_B_SHIFT    16 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_B_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_B_INPLACE  (HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_B_MASK << HUB_PI_ERR_INT_MASK_B_SYSCMD_ADDR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_A_SHIFT    15 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_A_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_A_INPLACE  (HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_A_MASK << HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_B_SHIFT    14 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_B_MASK     0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_B_INPLACE  (HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_B_MASK << HUB_PI_ERR_INT_MASK_B_SYSCMD_DATA_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_A_SHIFT     13 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_A_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_A_INPLACE   (HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_A_MASK << HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_B_SHIFT     12 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_B_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_B_INPLACE   (HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_B_MASK << HUB_PI_ERR_INT_MASK_B_SYSAD_ADDR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_A_SHIFT     11 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_A_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_A_INPLACE   (HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_A_MASK << HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_B_SHIFT     10 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_B_MASK      0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_B_INPLACE   (HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_B_MASK << HUB_PI_ERR_INT_MASK_B_SYSAD_DATA_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_A_SHIFT       9 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_A_INPLACE     (HUB_PI_ERR_INT_MASK_B_SYSSTATE_A_MASK << HUB_PI_ERR_INT_MASK_B_SYSSTATE_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_B_SHIFT       8 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_SYSSTATE_B_INPLACE     (HUB_PI_ERR_INT_MASK_B_SYSSTATE_B_MASK << HUB_PI_ERR_INT_MASK_B_SYSSTATE_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_WRB_WERR_A_SHIFT       7 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_WRB_WERR_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_WRB_WERR_A_INPLACE     (HUB_PI_ERR_INT_MASK_B_WRB_WERR_A_MASK << HUB_PI_ERR_INT_MASK_B_WRB_WERR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_WRB_WERR_B_SHIFT       6 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_WRB_WERR_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_WRB_WERR_B_INPLACE     (HUB_PI_ERR_INT_MASK_B_WRB_WERR_B_MASK << HUB_PI_ERR_INT_MASK_B_WRB_WERR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_WRB_TERR_A_SHIFT       5 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_WRB_TERR_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_WRB_TERR_A_INPLACE     (HUB_PI_ERR_INT_MASK_B_WRB_TERR_A_MASK << HUB_PI_ERR_INT_MASK_B_WRB_TERR_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_WRB_TERR_B_SHIFT       4 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_WRB_TERR_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_WRB_TERR_B_INPLACE     (HUB_PI_ERR_INT_MASK_B_WRB_TERR_B_MASK << HUB_PI_ERR_INT_MASK_B_WRB_TERR_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SPUR_MSG_A_SHIFT       3 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SPUR_MSG_A_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_SPUR_MSG_A_INPLACE     (HUB_PI_ERR_INT_MASK_B_SPUR_MSG_A_MASK << HUB_PI_ERR_INT_MASK_B_SPUR_MSG_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SPUR_MSG_B_SHIFT       2 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SPUR_MSG_B_MASK        0x1ull
#define HUB_PI_ERR_INT_MASK_B_SPUR_MSG_B_INPLACE     (HUB_PI_ERR_INT_MASK_B_SPUR_MSG_B_MASK << HUB_PI_ERR_INT_MASK_B_SPUR_MSG_B_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_A_SHIFT      1 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_A_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_A_INPLACE    (HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_A_MASK << HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_A_SHIFT)
#define HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_B_SHIFT      0 /* inferred */
#define HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_B_MASK       0x1ull
#define HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_B_INPLACE    (HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_B_MASK << HUB_PI_ERR_INT_MASK_B_SPOOL_CMP_B_SHIFT)

/* pi_err_status0_a: r64, reset unknown; census: 5 sites, 4 routines */
#define HUB_PI_ERR_STATUS0_A_OFFSET                  0x430u /* established */
#define HUB_PI_ERR_STATUS0_A_VALID_SHIFT             63 /* established */
#define HUB_PI_ERR_STATUS0_A_VALID_MASK              0x1ull
#define HUB_PI_ERR_STATUS0_A_VALID_INPLACE           (HUB_PI_ERR_STATUS0_A_VALID_MASK << HUB_PI_ERR_STATUS0_A_VALID_SHIFT)
#define HUB_PI_ERR_STATUS0_A_OVERRUN_SHIFT           62 /* established */
#define HUB_PI_ERR_STATUS0_A_OVERRUN_MASK            0x1ull
#define HUB_PI_ERR_STATUS0_A_OVERRUN_INPLACE         (HUB_PI_ERR_STATUS0_A_OVERRUN_MASK << HUB_PI_ERR_STATUS0_A_OVERRUN_SHIFT)
#define HUB_PI_ERR_STATUS0_A_ADDR_SHIFT              25 /* established */
#define HUB_PI_ERR_STATUS0_A_ADDR_MASK               0x1fffffffffull
#define HUB_PI_ERR_STATUS0_A_ADDR_INPLACE            (HUB_PI_ERR_STATUS0_A_ADDR_MASK << HUB_PI_ERR_STATUS0_A_ADDR_SHIFT)
#define HUB_PI_ERR_STATUS0_A_CMD_SHIFT               17 /* established */
#define HUB_PI_ERR_STATUS0_A_CMD_MASK                0xffull
#define HUB_PI_ERR_STATUS0_A_CMD_INPLACE             (HUB_PI_ERR_STATUS0_A_CMD_MASK << HUB_PI_ERR_STATUS0_A_CMD_SHIFT)
#define HUB_PI_ERR_STATUS0_A_SUPPL_SHIFT             6 /* established */
#define HUB_PI_ERR_STATUS0_A_SUPPL_MASK              0x7ffull
#define HUB_PI_ERR_STATUS0_A_SUPPL_INPLACE           (HUB_PI_ERR_STATUS0_A_SUPPL_MASK << HUB_PI_ERR_STATUS0_A_SUPPL_SHIFT)
#define HUB_PI_ERR_STATUS0_A_REQNUM_SHIFT            3 /* established */
#define HUB_PI_ERR_STATUS0_A_REQNUM_MASK             0x7ull
#define HUB_PI_ERR_STATUS0_A_REQNUM_INPLACE          (HUB_PI_ERR_STATUS0_A_REQNUM_MASK << HUB_PI_ERR_STATUS0_A_REQNUM_SHIFT)
#define HUB_PI_ERR_STATUS0_A_TYPE_SHIFT              0 /* established */
#define HUB_PI_ERR_STATUS0_A_TYPE_MASK               0x7ull
#define HUB_PI_ERR_STATUS0_A_TYPE_INPLACE            (HUB_PI_ERR_STATUS0_A_TYPE_MASK << HUB_PI_ERR_STATUS0_A_TYPE_SHIFT)

/*
 * Clear-on-read alias of error status 0 for processor A, named PI_ERR_STATUS0_A_RCLR in the header. The header's comment says a read clears the register. The IRIX register table confirms the access. Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.
 */
/* pi_err_status0_a_rclr: r64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_ERR_STATUS0_A_RCLR_OFFSET             0x438u /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_VALID_SHIFT        63 /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_VALID_MASK         0x1ull
#define HUB_PI_ERR_STATUS0_A_RCLR_VALID_INPLACE      (HUB_PI_ERR_STATUS0_A_RCLR_VALID_MASK << HUB_PI_ERR_STATUS0_A_RCLR_VALID_SHIFT)
#define HUB_PI_ERR_STATUS0_A_RCLR_OVERRUN_SHIFT      62 /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_OVERRUN_MASK       0x1ull
#define HUB_PI_ERR_STATUS0_A_RCLR_OVERRUN_INPLACE    (HUB_PI_ERR_STATUS0_A_RCLR_OVERRUN_MASK << HUB_PI_ERR_STATUS0_A_RCLR_OVERRUN_SHIFT)
#define HUB_PI_ERR_STATUS0_A_RCLR_ADDR_SHIFT         25 /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_ADDR_MASK          0x1fffffffffull
#define HUB_PI_ERR_STATUS0_A_RCLR_ADDR_INPLACE       (HUB_PI_ERR_STATUS0_A_RCLR_ADDR_MASK << HUB_PI_ERR_STATUS0_A_RCLR_ADDR_SHIFT)
#define HUB_PI_ERR_STATUS0_A_RCLR_CMD_SHIFT          17 /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_CMD_MASK           0xffull
#define HUB_PI_ERR_STATUS0_A_RCLR_CMD_INPLACE        (HUB_PI_ERR_STATUS0_A_RCLR_CMD_MASK << HUB_PI_ERR_STATUS0_A_RCLR_CMD_SHIFT)
#define HUB_PI_ERR_STATUS0_A_RCLR_SUPPL_SHIFT        6 /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_SUPPL_MASK         0x7ffull
#define HUB_PI_ERR_STATUS0_A_RCLR_SUPPL_INPLACE      (HUB_PI_ERR_STATUS0_A_RCLR_SUPPL_MASK << HUB_PI_ERR_STATUS0_A_RCLR_SUPPL_SHIFT)
#define HUB_PI_ERR_STATUS0_A_RCLR_REQNUM_SHIFT       3 /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_REQNUM_MASK        0x7ull
#define HUB_PI_ERR_STATUS0_A_RCLR_REQNUM_INPLACE     (HUB_PI_ERR_STATUS0_A_RCLR_REQNUM_MASK << HUB_PI_ERR_STATUS0_A_RCLR_REQNUM_SHIFT)
#define HUB_PI_ERR_STATUS0_A_RCLR_TYPE_SHIFT         0 /* established */
#define HUB_PI_ERR_STATUS0_A_RCLR_TYPE_MASK          0x7ull
#define HUB_PI_ERR_STATUS0_A_RCLR_TYPE_INPLACE       (HUB_PI_ERR_STATUS0_A_RCLR_TYPE_MASK << HUB_PI_ERR_STATUS0_A_RCLR_TYPE_SHIFT)

/* pi_err_status1_a: r64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_ERR_STATUS1_A_OFFSET                  0x440u /* established */
#define HUB_PI_ERR_STATUS1_A_MSGSRC_SHIFT            53 /* established */
#define HUB_PI_ERR_STATUS1_A_MSGSRC_MASK             0x7ffull
#define HUB_PI_ERR_STATUS1_A_MSGSRC_INPLACE          (HUB_PI_ERR_STATUS1_A_MSGSRC_MASK << HUB_PI_ERR_STATUS1_A_MSGSRC_SHIFT)
#define HUB_PI_ERR_STATUS1_A_CRBSTAT_SHIFT           43 /* established */
#define HUB_PI_ERR_STATUS1_A_CRBSTAT_MASK            0x3ffull
#define HUB_PI_ERR_STATUS1_A_CRBSTAT_INPLACE         (HUB_PI_ERR_STATUS1_A_CRBSTAT_MASK << HUB_PI_ERR_STATUS1_A_CRBSTAT_SHIFT)
#define HUB_PI_ERR_STATUS1_A_WRBRRB_SHIFT            42 /* established */
#define HUB_PI_ERR_STATUS1_A_WRBRRB_MASK             0x1ull
#define HUB_PI_ERR_STATUS1_A_WRBRRB_INPLACE          (HUB_PI_ERR_STATUS1_A_WRBRRB_MASK << HUB_PI_ERR_STATUS1_A_WRBRRB_SHIFT)
#define HUB_PI_ERR_STATUS1_A_CRBNUM_SHIFT            39 /* established */
#define HUB_PI_ERR_STATUS1_A_CRBNUM_MASK             0x7ull
#define HUB_PI_ERR_STATUS1_A_CRBNUM_INPLACE          (HUB_PI_ERR_STATUS1_A_CRBNUM_MASK << HUB_PI_ERR_STATUS1_A_CRBNUM_SHIFT)
#define HUB_PI_ERR_STATUS1_A_INVCNT_SHIFT            29 /* established */
#define HUB_PI_ERR_STATUS1_A_INVCNT_MASK             0x3ffull
#define HUB_PI_ERR_STATUS1_A_INVCNT_INPLACE          (HUB_PI_ERR_STATUS1_A_INVCNT_MASK << HUB_PI_ERR_STATUS1_A_INVCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_A_TOUTCNT_SHIFT           21 /* established */
#define HUB_PI_ERR_STATUS1_A_TOUTCNT_MASK            0xffull
#define HUB_PI_ERR_STATUS1_A_TOUTCNT_INPLACE         (HUB_PI_ERR_STATUS1_A_TOUTCNT_MASK << HUB_PI_ERR_STATUS1_A_TOUTCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_A_SPOOL_SHIFT             0 /* established */
#define HUB_PI_ERR_STATUS1_A_SPOOL_MASK              0x1fffffull
#define HUB_PI_ERR_STATUS1_A_SPOOL_INPLACE           (HUB_PI_ERR_STATUS1_A_SPOOL_MASK << HUB_PI_ERR_STATUS1_A_SPOOL_SHIFT)

/*
 * Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.
 */
/* pi_err_status1_a_rclr: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_ERR_STATUS1_A_RCLR_OFFSET             0x448u /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_MSGSRC_SHIFT       53 /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_MSGSRC_MASK        0x7ffull
#define HUB_PI_ERR_STATUS1_A_RCLR_MSGSRC_INPLACE     (HUB_PI_ERR_STATUS1_A_RCLR_MSGSRC_MASK << HUB_PI_ERR_STATUS1_A_RCLR_MSGSRC_SHIFT)
#define HUB_PI_ERR_STATUS1_A_RCLR_CRBSTAT_SHIFT      43 /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_CRBSTAT_MASK       0x3ffull
#define HUB_PI_ERR_STATUS1_A_RCLR_CRBSTAT_INPLACE    (HUB_PI_ERR_STATUS1_A_RCLR_CRBSTAT_MASK << HUB_PI_ERR_STATUS1_A_RCLR_CRBSTAT_SHIFT)
#define HUB_PI_ERR_STATUS1_A_RCLR_WRBRRB_SHIFT       42 /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_WRBRRB_MASK        0x1ull
#define HUB_PI_ERR_STATUS1_A_RCLR_WRBRRB_INPLACE     (HUB_PI_ERR_STATUS1_A_RCLR_WRBRRB_MASK << HUB_PI_ERR_STATUS1_A_RCLR_WRBRRB_SHIFT)
#define HUB_PI_ERR_STATUS1_A_RCLR_CRBNUM_SHIFT       39 /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_CRBNUM_MASK        0x7ull
#define HUB_PI_ERR_STATUS1_A_RCLR_CRBNUM_INPLACE     (HUB_PI_ERR_STATUS1_A_RCLR_CRBNUM_MASK << HUB_PI_ERR_STATUS1_A_RCLR_CRBNUM_SHIFT)
#define HUB_PI_ERR_STATUS1_A_RCLR_INVCNT_SHIFT       29 /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_INVCNT_MASK        0x3ffull
#define HUB_PI_ERR_STATUS1_A_RCLR_INVCNT_INPLACE     (HUB_PI_ERR_STATUS1_A_RCLR_INVCNT_MASK << HUB_PI_ERR_STATUS1_A_RCLR_INVCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_A_RCLR_TOUTCNT_SHIFT      21 /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_TOUTCNT_MASK       0xffull
#define HUB_PI_ERR_STATUS1_A_RCLR_TOUTCNT_INPLACE    (HUB_PI_ERR_STATUS1_A_RCLR_TOUTCNT_MASK << HUB_PI_ERR_STATUS1_A_RCLR_TOUTCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_A_RCLR_SPOOL_SHIFT        0 /* established */
#define HUB_PI_ERR_STATUS1_A_RCLR_SPOOL_MASK         0x1fffffull
#define HUB_PI_ERR_STATUS1_A_RCLR_SPOOL_INPLACE      (HUB_PI_ERR_STATUS1_A_RCLR_SPOOL_MASK << HUB_PI_ERR_STATUS1_A_RCLR_SPOOL_SHIFT)

/* pi_err_status0_b: r64, reset unknown; census: 5 sites, 4 routines */
#define HUB_PI_ERR_STATUS0_B_OFFSET                  0x450u /* established */
#define HUB_PI_ERR_STATUS0_B_VALID_SHIFT             63 /* established */
#define HUB_PI_ERR_STATUS0_B_VALID_MASK              0x1ull
#define HUB_PI_ERR_STATUS0_B_VALID_INPLACE           (HUB_PI_ERR_STATUS0_B_VALID_MASK << HUB_PI_ERR_STATUS0_B_VALID_SHIFT)
#define HUB_PI_ERR_STATUS0_B_OVERRUN_SHIFT           62 /* established */
#define HUB_PI_ERR_STATUS0_B_OVERRUN_MASK            0x1ull
#define HUB_PI_ERR_STATUS0_B_OVERRUN_INPLACE         (HUB_PI_ERR_STATUS0_B_OVERRUN_MASK << HUB_PI_ERR_STATUS0_B_OVERRUN_SHIFT)
#define HUB_PI_ERR_STATUS0_B_ADDR_SHIFT              25 /* established */
#define HUB_PI_ERR_STATUS0_B_ADDR_MASK               0x1fffffffffull
#define HUB_PI_ERR_STATUS0_B_ADDR_INPLACE            (HUB_PI_ERR_STATUS0_B_ADDR_MASK << HUB_PI_ERR_STATUS0_B_ADDR_SHIFT)
#define HUB_PI_ERR_STATUS0_B_CMD_SHIFT               17 /* established */
#define HUB_PI_ERR_STATUS0_B_CMD_MASK                0xffull
#define HUB_PI_ERR_STATUS0_B_CMD_INPLACE             (HUB_PI_ERR_STATUS0_B_CMD_MASK << HUB_PI_ERR_STATUS0_B_CMD_SHIFT)
#define HUB_PI_ERR_STATUS0_B_SUPPL_SHIFT             6 /* established */
#define HUB_PI_ERR_STATUS0_B_SUPPL_MASK              0x7ffull
#define HUB_PI_ERR_STATUS0_B_SUPPL_INPLACE           (HUB_PI_ERR_STATUS0_B_SUPPL_MASK << HUB_PI_ERR_STATUS0_B_SUPPL_SHIFT)
#define HUB_PI_ERR_STATUS0_B_REQNUM_SHIFT            3 /* established */
#define HUB_PI_ERR_STATUS0_B_REQNUM_MASK             0x7ull
#define HUB_PI_ERR_STATUS0_B_REQNUM_INPLACE          (HUB_PI_ERR_STATUS0_B_REQNUM_MASK << HUB_PI_ERR_STATUS0_B_REQNUM_SHIFT)
#define HUB_PI_ERR_STATUS0_B_TYPE_SHIFT              0 /* established */
#define HUB_PI_ERR_STATUS0_B_TYPE_MASK               0x7ull
#define HUB_PI_ERR_STATUS0_B_TYPE_INPLACE            (HUB_PI_ERR_STATUS0_B_TYPE_MASK << HUB_PI_ERR_STATUS0_B_TYPE_SHIFT)

/*
 * Clear-on-read alias of error status 0 for processor B, named PI_ERR_STATUS0_B_RCLR in the header. The header's comment says a read clears the register. The IRIX register table confirms the access. Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.
 */
/* pi_err_status0_b_rclr: r64, reset unknown; public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) */
#define HUB_PI_ERR_STATUS0_B_RCLR_OFFSET             0x458u /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_VALID_SHIFT        63 /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_VALID_MASK         0x1ull
#define HUB_PI_ERR_STATUS0_B_RCLR_VALID_INPLACE      (HUB_PI_ERR_STATUS0_B_RCLR_VALID_MASK << HUB_PI_ERR_STATUS0_B_RCLR_VALID_SHIFT)
#define HUB_PI_ERR_STATUS0_B_RCLR_OVERRUN_SHIFT      62 /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_OVERRUN_MASK       0x1ull
#define HUB_PI_ERR_STATUS0_B_RCLR_OVERRUN_INPLACE    (HUB_PI_ERR_STATUS0_B_RCLR_OVERRUN_MASK << HUB_PI_ERR_STATUS0_B_RCLR_OVERRUN_SHIFT)
#define HUB_PI_ERR_STATUS0_B_RCLR_ADDR_SHIFT         25 /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_ADDR_MASK          0x1fffffffffull
#define HUB_PI_ERR_STATUS0_B_RCLR_ADDR_INPLACE       (HUB_PI_ERR_STATUS0_B_RCLR_ADDR_MASK << HUB_PI_ERR_STATUS0_B_RCLR_ADDR_SHIFT)
#define HUB_PI_ERR_STATUS0_B_RCLR_CMD_SHIFT          17 /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_CMD_MASK           0xffull
#define HUB_PI_ERR_STATUS0_B_RCLR_CMD_INPLACE        (HUB_PI_ERR_STATUS0_B_RCLR_CMD_MASK << HUB_PI_ERR_STATUS0_B_RCLR_CMD_SHIFT)
#define HUB_PI_ERR_STATUS0_B_RCLR_SUPPL_SHIFT        6 /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_SUPPL_MASK         0x7ffull
#define HUB_PI_ERR_STATUS0_B_RCLR_SUPPL_INPLACE      (HUB_PI_ERR_STATUS0_B_RCLR_SUPPL_MASK << HUB_PI_ERR_STATUS0_B_RCLR_SUPPL_SHIFT)
#define HUB_PI_ERR_STATUS0_B_RCLR_REQNUM_SHIFT       3 /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_REQNUM_MASK        0x7ull
#define HUB_PI_ERR_STATUS0_B_RCLR_REQNUM_INPLACE     (HUB_PI_ERR_STATUS0_B_RCLR_REQNUM_MASK << HUB_PI_ERR_STATUS0_B_RCLR_REQNUM_SHIFT)
#define HUB_PI_ERR_STATUS0_B_RCLR_TYPE_SHIFT         0 /* established */
#define HUB_PI_ERR_STATUS0_B_RCLR_TYPE_MASK          0x7ull
#define HUB_PI_ERR_STATUS0_B_RCLR_TYPE_INPLACE       (HUB_PI_ERR_STATUS0_B_RCLR_TYPE_MASK << HUB_PI_ERR_STATUS0_B_RCLR_TYPE_SHIFT)

/* pi_err_status1_b: r64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_ERR_STATUS1_B_OFFSET                  0x460u /* established */
#define HUB_PI_ERR_STATUS1_B_MSGSRC_SHIFT            53 /* established */
#define HUB_PI_ERR_STATUS1_B_MSGSRC_MASK             0x7ffull
#define HUB_PI_ERR_STATUS1_B_MSGSRC_INPLACE          (HUB_PI_ERR_STATUS1_B_MSGSRC_MASK << HUB_PI_ERR_STATUS1_B_MSGSRC_SHIFT)
#define HUB_PI_ERR_STATUS1_B_CRBSTAT_SHIFT           43 /* established */
#define HUB_PI_ERR_STATUS1_B_CRBSTAT_MASK            0x3ffull
#define HUB_PI_ERR_STATUS1_B_CRBSTAT_INPLACE         (HUB_PI_ERR_STATUS1_B_CRBSTAT_MASK << HUB_PI_ERR_STATUS1_B_CRBSTAT_SHIFT)
#define HUB_PI_ERR_STATUS1_B_WRBRRB_SHIFT            42 /* established */
#define HUB_PI_ERR_STATUS1_B_WRBRRB_MASK             0x1ull
#define HUB_PI_ERR_STATUS1_B_WRBRRB_INPLACE          (HUB_PI_ERR_STATUS1_B_WRBRRB_MASK << HUB_PI_ERR_STATUS1_B_WRBRRB_SHIFT)
#define HUB_PI_ERR_STATUS1_B_CRBNUM_SHIFT            39 /* established */
#define HUB_PI_ERR_STATUS1_B_CRBNUM_MASK             0x7ull
#define HUB_PI_ERR_STATUS1_B_CRBNUM_INPLACE          (HUB_PI_ERR_STATUS1_B_CRBNUM_MASK << HUB_PI_ERR_STATUS1_B_CRBNUM_SHIFT)
#define HUB_PI_ERR_STATUS1_B_INVCNT_SHIFT            29 /* established */
#define HUB_PI_ERR_STATUS1_B_INVCNT_MASK             0x3ffull
#define HUB_PI_ERR_STATUS1_B_INVCNT_INPLACE          (HUB_PI_ERR_STATUS1_B_INVCNT_MASK << HUB_PI_ERR_STATUS1_B_INVCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_B_TOUTCNT_SHIFT           21 /* established */
#define HUB_PI_ERR_STATUS1_B_TOUTCNT_MASK            0xffull
#define HUB_PI_ERR_STATUS1_B_TOUTCNT_INPLACE         (HUB_PI_ERR_STATUS1_B_TOUTCNT_MASK << HUB_PI_ERR_STATUS1_B_TOUTCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_B_SPOOL_SHIFT             0 /* established */
#define HUB_PI_ERR_STATUS1_B_SPOOL_MASK              0x1fffffull
#define HUB_PI_ERR_STATUS1_B_SPOOL_INPLACE           (HUB_PI_ERR_STATUS1_B_SPOOL_MASK << HUB_PI_ERR_STATUS1_B_SPOOL_SHIFT)

/*
 * Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.
 */
/* pi_err_status1_b_rclr: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_ERR_STATUS1_B_RCLR_OFFSET             0x468u /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_MSGSRC_SHIFT       53 /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_MSGSRC_MASK        0x7ffull
#define HUB_PI_ERR_STATUS1_B_RCLR_MSGSRC_INPLACE     (HUB_PI_ERR_STATUS1_B_RCLR_MSGSRC_MASK << HUB_PI_ERR_STATUS1_B_RCLR_MSGSRC_SHIFT)
#define HUB_PI_ERR_STATUS1_B_RCLR_CRBSTAT_SHIFT      43 /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_CRBSTAT_MASK       0x3ffull
#define HUB_PI_ERR_STATUS1_B_RCLR_CRBSTAT_INPLACE    (HUB_PI_ERR_STATUS1_B_RCLR_CRBSTAT_MASK << HUB_PI_ERR_STATUS1_B_RCLR_CRBSTAT_SHIFT)
#define HUB_PI_ERR_STATUS1_B_RCLR_WRBRRB_SHIFT       42 /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_WRBRRB_MASK        0x1ull
#define HUB_PI_ERR_STATUS1_B_RCLR_WRBRRB_INPLACE     (HUB_PI_ERR_STATUS1_B_RCLR_WRBRRB_MASK << HUB_PI_ERR_STATUS1_B_RCLR_WRBRRB_SHIFT)
#define HUB_PI_ERR_STATUS1_B_RCLR_CRBNUM_SHIFT       39 /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_CRBNUM_MASK        0x7ull
#define HUB_PI_ERR_STATUS1_B_RCLR_CRBNUM_INPLACE     (HUB_PI_ERR_STATUS1_B_RCLR_CRBNUM_MASK << HUB_PI_ERR_STATUS1_B_RCLR_CRBNUM_SHIFT)
#define HUB_PI_ERR_STATUS1_B_RCLR_INVCNT_SHIFT       29 /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_INVCNT_MASK        0x3ffull
#define HUB_PI_ERR_STATUS1_B_RCLR_INVCNT_INPLACE     (HUB_PI_ERR_STATUS1_B_RCLR_INVCNT_MASK << HUB_PI_ERR_STATUS1_B_RCLR_INVCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_B_RCLR_TOUTCNT_SHIFT      21 /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_TOUTCNT_MASK       0xffull
#define HUB_PI_ERR_STATUS1_B_RCLR_TOUTCNT_INPLACE    (HUB_PI_ERR_STATUS1_B_RCLR_TOUTCNT_MASK << HUB_PI_ERR_STATUS1_B_RCLR_TOUTCNT_SHIFT)
#define HUB_PI_ERR_STATUS1_B_RCLR_SPOOL_SHIFT        0 /* established */
#define HUB_PI_ERR_STATUS1_B_RCLR_SPOOL_MASK         0x1fffffull
#define HUB_PI_ERR_STATUS1_B_RCLR_SPOOL_INPLACE      (HUB_PI_ERR_STATUS1_B_RCLR_SPOOL_MASK << HUB_PI_ERR_STATUS1_B_RCLR_SPOOL_SHIFT)

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

#define HUB_IP_ERROR                                 0x4000u /* established */
#define HUB_IP_MASK                                  0x7c00u /* established */
#define HUB_IP_PEND0                                 0x400u /* established */
#define HUB_IP_PEND1_CC                              0x800u /* established */
#define HUB_IP_PROF                                  0x2000u /* established */
#define HUB_IP_RT                                    0x1000u /* established */
#define HUB_PI_BASE                                  0x0u /* established */
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
#define HUB_PI_ERR_CLEAR_ALL_A                       0xaaaaaau /* established */
#define HUB_PI_ERR_CLEAR_ALL_B                       0x555555u /* established */
#define HUB_PI_ERR_RD_DERR                           0x2u /* established */
#define HUB_PI_ERR_RD_PRERR                          0x1u /* established */
#define HUB_PI_ERR_RD_TERR                           0x3u /* established */
#define HUB_PI_ERR_WR_PWERR                          0x1u /* established */
#define HUB_PI_ERR_WR_TERR                           0x3u /* established */
#define HUB_PI_ERR_WR_WERR                           0x0u /* established */
#define HUB_PI_LOCAL_WINDOW_BASE                     0x1000000u /* established */
#define HUB_PI_MIN_STACK_SIZE                        0x1000u /* established */
#define HUB_PI_NODE_SHIFT                            0x20u /* established */
#define HUB_PI_NODE_WINDOW_BASE                      0x1800000u /* established */
#define HUB_PI_STACK_SIZE_SHIFT                      0xcu /* established */

#endif /* HUB_GEN_H */
