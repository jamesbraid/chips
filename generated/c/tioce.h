/* generated from devices/tioce/registers.toml by defs-gen - do not edit, change the source */
/* TIOCE (TIO PCI Express bridge), as SGI's Linux Altix platform code defines it */
#ifndef TIOCE_GEN_H
#define TIOCE_GEN_H

#include <stdint.h>


/*
 * Widget identification word: part 0xce00, source id 1, revision A = 1 (header constants). Revision A needs the access workaround described on the unit page. Name and offset are the vendor header's definition (struct member ce_adm_id). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_id: rw64, reset unknown */
#define TIOCE_ADM_ID                                 0x000000 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_dyn_credit_status: rw64, reset unknown */
#define TIOCE_ADM_DYN_CREDIT_STATUS                  0x000010 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_last_credit_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_last_credit_status: rw64, reset unknown */
#define TIOCE_ADM_LAST_CREDIT_STATUS                 0x000018 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_credit_limit: rw64, reset unknown */
#define TIOCE_ADM_CREDIT_LIMIT                       0x000020 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_force_credit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_force_credit: rw64, reset unknown */
#define TIOCE_ADM_FORCE_CREDIT                       0x000028 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_control). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_control: rw64, reset unknown */
#define TIOCE_ADM_CONTROL                            0x000030 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_mmr_chn_timeout). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_mmr_chn_timeout: rw64, reset unknown */
#define TIOCE_ADM_MMR_CHN_TIMEOUT                    0x000038 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_ure_timeout). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_ure_timeout: rw64, reset unknown */
#define TIOCE_ADM_SSP_URE_TIMEOUT                    0x000040 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_dre_timeout). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_dre_timeout: rw64, reset unknown */
#define TIOCE_ADM_SSP_DRE_TIMEOUT                    0x000048 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_debug_sel: rw64, reset unknown */
#define TIOCE_ADM_SSP_DEBUG_SEL                      0x000050 /* established */

/*
 * Interrupt status. Bit n is the interrupt source named by the header (error, link 1 and 2 errors, PCIe error, hot-plug events per port, INTA to INTD of each port, message slots 0 to 3, power-management events). The provider reads it on revision A before forcing an interrupt. Name and offset are the vendor header's definition (struct member ce_adm_int_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_int_status: rw64, reset unknown */
#define TIOCE_ADM_INT_STATUS                         0x000058 /* established */

/*
 * Interrupt status alias. The provider sets every bit through it at attach to clear transients (the alias is the write path to clear; role from that use). Name and offset are the vendor header's definition (struct member ce_adm_int_status_alias). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_int_status_alias: rw64, reset unknown */
#define TIOCE_ADM_INT_STATUS_ALIAS                   0x000060 /* established */

/*
 * Interrupt mask. The provider sets a source bit, writes its destination, then clears the bit, so a set bit blocks the source while the destination is rewritten. Name and offset are the vendor header's definition (struct member ce_adm_int_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_int_mask: rw64, reset unknown */
#define TIOCE_ADM_INT_MASK                           0x000068 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_int_pending). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_int_pending: rw64, reset unknown */
#define TIOCE_ADM_INT_PENDING                        0x000070 /* established */

/*
 * Force interrupt. Bits 0 to 7 force INTA to INTD of port 1 then port 2; bit 8 forces always. The bit numbering differs from the status register, and the provider maps explicitly. Revision A does not use it (workaround). Name and offset are the vendor header's definition (struct member ce_adm_force_int). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_force_int: rw64, reset unknown */
#define TIOCE_ADM_FORCE_INT                          0x000078 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ure_ups_buf_barrier_flush). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ure_ups_buf_barrier_flush: rw64, reset unknown */
#define TIOCE_ADM_URE_UPS_BUF_BARRIER_FLUSH          0x000080 /* established */

/*
 * Interrupt destination, one per source (the header declares fifteen). The provider writes the kernel vector in bits 63:56 (shift INTR_VECTOR_SHFT) ORed with the destination coretalk address of the target CPU, indexed by interrupt source bit. Name and offset are the vendor header's definition (struct member ce_adm_int_dest). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_int_dest: rw64, reset unknown */
#define TIOCE_ADM_INT_DEST                           0x000088 /* established */
#define TIOCE_ADM_INT_DEST_COUNT                     15
#define TIOCE_ADM_INT_DEST_STRIDE                    8

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_error_summary). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_error_summary: rw64, reset unknown */
#define TIOCE_ADM_ERROR_SUMMARY                      0x000100 /* established */

/*
 * Error summary alias. The provider sets every bit through it at attach to clear transient errors. Name and offset are the vendor header's definition (struct member ce_adm_error_summary_alias). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_error_summary_alias: rw64, reset unknown */
#define TIOCE_ADM_ERROR_SUMMARY_ALIAS                0x000108 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_error_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_error_mask: rw64, reset unknown */
#define TIOCE_ADM_ERROR_MASK                         0x000110 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_first_error). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_first_error: rw64, reset unknown */
#define TIOCE_ADM_FIRST_ERROR                        0x000118 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_error_overflow). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_error_overflow: rw64, reset unknown */
#define TIOCE_ADM_ERROR_OVERFLOW                     0x000120 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_error_overflow_alias). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_error_overflow_alias: rw64, reset unknown */
#define TIOCE_ADM_ERROR_OVERFLOW_ALIAS               0x000128 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_tnum_error). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_tnum_error: rw64, reset unknown */
#define TIOCE_ADM_TNUM_ERROR                         0x000140 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_mmr_err_detail). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_mmr_err_detail: rw64, reset unknown */
#define TIOCE_ADM_MMR_ERR_DETAIL                     0x000148 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_msg_sram_perr_detail). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_msg_sram_perr_detail: rw64, reset unknown */
#define TIOCE_ADM_MSG_SRAM_PERR_DETAIL               0x000150 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_bap_sram_perr_detail). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_bap_sram_perr_detail: rw64, reset unknown */
#define TIOCE_ADM_BAP_SRAM_PERR_DETAIL               0x000158 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ce_sram_perr_detail). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ce_sram_perr_detail: rw64, reset unknown */
#define TIOCE_ADM_CE_SRAM_PERR_DETAIL                0x000160 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ce_credit_oflow_detail). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ce_credit_oflow_detail: rw64, reset unknown */
#define TIOCE_ADM_CE_CREDIT_OFLOW_DETAIL             0x000168 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_tx_link_idle_max_timer). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_tx_link_idle_max_timer: rw64, reset unknown */
#define TIOCE_ADM_TX_LINK_IDLE_MAX_TIMER             0x000170 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_debug_sel: rw64, reset unknown */
#define TIOCE_ADM_PCIE_DEBUG_SEL                     0x000178 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_sel_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_debug_sel_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_DEBUG_SEL_TOP                 0x000200 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_debug_lat_sel_lo_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_DEBUG_LAT_SEL_LO_TOP          0x000208 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_debug_lat_sel_hi_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_DEBUG_LAT_SEL_HI_TOP          0x000210 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_sel_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_debug_trig_sel_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_DEBUG_TRIG_SEL_TOP            0x000218 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_debug_trig_lat_sel_lo_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_DEBUG_TRIG_LAT_SEL_LO_TOP     0x000220 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_debug_trig_lat_sel_hi_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_DEBUG_TRIG_LAT_SEL_HI_TOP     0x000228 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_trig_compare_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_trig_compare_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_TRIG_COMPARE_TOP              0x000230 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_pcie_trig_compare_en_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_pcie_trig_compare_en_top: rw64, reset unknown */
#define TIOCE_ADM_PCIE_TRIG_COMPARE_EN_TOP           0x000238 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_sel_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_debug_sel_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_DEBUG_SEL_TOP                  0x000240 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_debug_lat_sel_lo_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_DEBUG_LAT_SEL_LO_TOP           0x000248 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_debug_lat_sel_hi_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_DEBUG_LAT_SEL_HI_TOP           0x000250 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_sel_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_debug_trig_sel_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_DEBUG_TRIG_SEL_TOP             0x000258 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_debug_trig_lat_sel_lo_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_DEBUG_TRIG_LAT_SEL_LO_TOP      0x000260 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_debug_trig_lat_sel_hi_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_DEBUG_TRIG_LAT_SEL_HI_TOP      0x000268 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_trig_compare_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_trig_compare_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_TRIG_COMPARE_TOP               0x000270 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_ssp_trig_compare_en_top). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_ssp_trig_compare_en_top: rw64, reset unknown */
#define TIOCE_ADM_SSP_TRIG_COMPARE_EN_TOP            0x000278 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_bap_ctrl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_bap_ctrl: rw64, reset unknown */
#define TIOCE_ADM_BAP_CTRL                           0x000400 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_msg_buf_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* msg_buf_data63_0: rw64, reset unknown */
#define TIOCE_MSG_BUF_DATA63_0                       0x000800 /* established */
#define TIOCE_MSG_BUF_DATA63_0_COUNT                 35
#define TIOCE_MSG_BUF_DATA63_0_STRIDE                8

/*
 * Name and offset are the vendor header's definition (struct member ce_msg_buf_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* msg_buf_data127_64: rw64, reset unknown */
#define TIOCE_MSG_BUF_DATA127_64                     0x000a00 /* established */
#define TIOCE_MSG_BUF_DATA127_64_COUNT               35
#define TIOCE_MSG_BUF_DATA127_64_STRIDE              8

/*
 * Name and offset are the vendor header's definition (struct member ce_msg_buf_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* msg_buf_parity: rw64, reset unknown */
#define TIOCE_MSG_BUF_PARITY                         0x000c00 /* established */
#define TIOCE_MSG_BUF_PARITY_COUNT                   35
#define TIOCE_MSG_BUF_PARITY_STRIDE                  8

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lpu_id). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lpu_id: rw64, reset unknown */
#define TIOCE_LSI_LPU_ID                             0x002000 /* established */
#define TIOCE_LSI_LPU_ID_COUNT                       2
#define TIOCE_LSI_LPU_ID_STRIDE                      4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rst). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rst: rw64, reset unknown */
#define TIOCE_LSI_RST                                0x002008 /* established */
#define TIOCE_LSI_RST_COUNT                          2
#define TIOCE_LSI_RST_STRIDE                         4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_dbg_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_dbg_stat: rw64, reset unknown */
#define TIOCE_LSI_DBG_STAT                           0x002010 /* established */
#define TIOCE_LSI_DBG_STAT_COUNT                     2
#define TIOCE_LSI_DBG_STAT_STRIDE                    4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_dbg_cfg). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_dbg_cfg: rw64, reset unknown */
#define TIOCE_LSI_DBG_CFG                            0x002018 /* established */
#define TIOCE_LSI_DBG_CFG_COUNT                      2
#define TIOCE_LSI_DBG_CFG_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_ctrl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_ctrl: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_CTRL                         0x002020 /* established */
#define TIOCE_LSI_LTSSM_CTRL_COUNT                   2
#define TIOCE_LSI_LTSSM_CTRL_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_stat: rw64, reset unknown */
#define TIOCE_LSI_LK_STAT                            0x002028 /* established */
#define TIOCE_LSI_LK_STAT_COUNT                      2
#define TIOCE_LSI_LK_STAT_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_int_and_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_int_and_stat: rw64, reset unknown */
#define TIOCE_LSI_INT_AND_STAT                       0x002040 /* established */
#define TIOCE_LSI_INT_AND_STAT_COUNT                 2
#define TIOCE_LSI_INT_AND_STAT_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_int_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_int_mask: rw64, reset unknown */
#define TIOCE_LSI_INT_MASK                           0x002048 /* established */
#define TIOCE_LSI_INT_MASK_COUNT                     2
#define TIOCE_LSI_INT_MASK_STRIDE                    4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt_sel). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_perf_cnt_sel: rw64, reset unknown */
#define TIOCE_LSI_LK_PERF_CNT_SEL                    0x002100 /* established */
#define TIOCE_LSI_LK_PERF_CNT_SEL_COUNT              2
#define TIOCE_LSI_LK_PERF_CNT_SEL_STRIDE             4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt_ctrl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_perf_cnt_ctrl: rw64, reset unknown */
#define TIOCE_LSI_LK_PERF_CNT_CTRL                   0x002110 /* established */
#define TIOCE_LSI_LK_PERF_CNT_CTRL_COUNT             2
#define TIOCE_LSI_LK_PERF_CNT_CTRL_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_perf_cnt1: rw64, reset unknown */
#define TIOCE_LSI_LK_PERF_CNT1                       0x002120 /* established */
#define TIOCE_LSI_LK_PERF_CNT1_COUNT                 2
#define TIOCE_LSI_LK_PERF_CNT1_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt1_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_perf_cnt1_test: rw64, reset unknown */
#define TIOCE_LSI_LK_PERF_CNT1_TEST                  0x002128 /* established */
#define TIOCE_LSI_LK_PERF_CNT1_TEST_COUNT            2
#define TIOCE_LSI_LK_PERF_CNT1_TEST_STRIDE           4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_perf_cnt2: rw64, reset unknown */
#define TIOCE_LSI_LK_PERF_CNT2                       0x002130 /* established */
#define TIOCE_LSI_LK_PERF_CNT2_COUNT                 2
#define TIOCE_LSI_LK_PERF_CNT2_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt2_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_perf_cnt2_test: rw64, reset unknown */
#define TIOCE_LSI_LK_PERF_CNT2_TEST                  0x002138 /* established */
#define TIOCE_LSI_LK_PERF_CNT2_TEST_COUNT            2
#define TIOCE_LSI_LK_PERF_CNT2_TEST_STRIDE           4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_cfg). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_lyr_cfg: rw64, reset unknown */
#define TIOCE_LSI_LK_LYR_CFG                         0x002200 /* established */
#define TIOCE_LSI_LK_LYR_CFG_COUNT                   2
#define TIOCE_LSI_LK_LYR_CFG_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_lyr_status: rw64, reset unknown */
#define TIOCE_LSI_LK_LYR_STATUS                      0x002208 /* established */
#define TIOCE_LSI_LK_LYR_STATUS_COUNT                2
#define TIOCE_LSI_LK_LYR_STATUS_STRIDE               4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_int_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_lyr_int_stat: rw64, reset unknown */
#define TIOCE_LSI_LK_LYR_INT_STAT                    0x002210 /* established */
#define TIOCE_LSI_LK_LYR_INT_STAT_COUNT              2
#define TIOCE_LSI_LK_LYR_INT_STAT_STRIDE             4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_ly_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_ly_int_stat_test: rw64, reset unknown */
#define TIOCE_LSI_LK_LY_INT_STAT_TEST                0x002218 /* established */
#define TIOCE_LSI_LK_LY_INT_STAT_TEST_COUNT          2
#define TIOCE_LSI_LK_LY_INT_STAT_TEST_STRIDE         4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_lk_ly_int_stat_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_lk_ly_int_stat_mask: rw64, reset unknown */
#define TIOCE_LSI_LK_LY_INT_STAT_MASK                0x002220 /* established */
#define TIOCE_LSI_LK_LY_INT_STAT_MASK_COUNT          2
#define TIOCE_LSI_LK_LY_INT_STAT_MASK_STRIDE         4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_fc_upd_ctl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_fc_upd_ctl: rw64, reset unknown */
#define TIOCE_LSI_FC_UPD_CTL                         0x002240 /* established */
#define TIOCE_LSI_FC_UPD_CTL_COUNT                   2
#define TIOCE_LSI_FC_UPD_CTL_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_to_timer). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_flw_ctl_upd_to_timer: rw64, reset unknown */
#define TIOCE_LSI_FLW_CTL_UPD_TO_TIMER               0x002260 /* established */
#define TIOCE_LSI_FLW_CTL_UPD_TO_TIMER_COUNT         2
#define TIOCE_LSI_FLW_CTL_UPD_TO_TIMER_STRIDE        4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_timer0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_flw_ctl_upd_timer0: rw64, reset unknown */
#define TIOCE_LSI_FLW_CTL_UPD_TIMER0                 0x002268 /* established */
#define TIOCE_LSI_FLW_CTL_UPD_TIMER0_COUNT           2
#define TIOCE_LSI_FLW_CTL_UPD_TIMER0_STRIDE          4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_timer1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_flw_ctl_upd_timer1: rw64, reset unknown */
#define TIOCE_LSI_FLW_CTL_UPD_TIMER1                 0x002270 /* established */
#define TIOCE_LSI_FLW_CTL_UPD_TIMER1_COUNT           2
#define TIOCE_LSI_FLW_CTL_UPD_TIMER1_STRIDE          4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_freq_nak_lat_thrsh). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_freq_nak_lat_thrsh: rw64, reset unknown */
#define TIOCE_LSI_FREQ_NAK_LAT_THRSH                 0x002400 /* established */
#define TIOCE_LSI_FREQ_NAK_LAT_THRSH_COUNT           2
#define TIOCE_LSI_FREQ_NAK_LAT_THRSH_STRIDE          4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ack_nak_lat_tmr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ack_nak_lat_tmr: rw64, reset unknown */
#define TIOCE_LSI_ACK_NAK_LAT_TMR                    0x002408 /* established */
#define TIOCE_LSI_ACK_NAK_LAT_TMR_COUNT              2
#define TIOCE_LSI_ACK_NAK_LAT_TMR_STRIDE             4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rply_tmr_thr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rply_tmr_thr: rw64, reset unknown */
#define TIOCE_LSI_RPLY_TMR_THR                       0x002410 /* established */
#define TIOCE_LSI_RPLY_TMR_THR_COUNT                 2
#define TIOCE_LSI_RPLY_TMR_THR_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rply_tmr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rply_tmr: rw64, reset unknown */
#define TIOCE_LSI_RPLY_TMR                           0x002418 /* established */
#define TIOCE_LSI_RPLY_TMR_COUNT                     2
#define TIOCE_LSI_RPLY_TMR_STRIDE                    4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rply_num_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rply_num_stat: rw64, reset unknown */
#define TIOCE_LSI_RPLY_NUM_STAT                      0x002420 /* established */
#define TIOCE_LSI_RPLY_NUM_STAT_COUNT                2
#define TIOCE_LSI_RPLY_NUM_STAT_STRIDE               4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rty_buf_max_addr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rty_buf_max_addr: rw64, reset unknown */
#define TIOCE_LSI_RTY_BUF_MAX_ADDR                   0x002428 /* established */
#define TIOCE_LSI_RTY_BUF_MAX_ADDR_COUNT             2
#define TIOCE_LSI_RTY_BUF_MAX_ADDR_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_ptr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rty_fifo_ptr: rw64, reset unknown */
#define TIOCE_LSI_RTY_FIFO_PTR                       0x002430 /* established */
#define TIOCE_LSI_RTY_FIFO_PTR_COUNT                 2
#define TIOCE_LSI_RTY_FIFO_PTR_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_rd_wr_ptr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rty_fifo_rd_wr_ptr: rw64, reset unknown */
#define TIOCE_LSI_RTY_FIFO_RD_WR_PTR                 0x002438 /* established */
#define TIOCE_LSI_RTY_FIFO_RD_WR_PTR_COUNT           2
#define TIOCE_LSI_RTY_FIFO_RD_WR_PTR_STRIDE          4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_cred). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rty_fifo_cred: rw64, reset unknown */
#define TIOCE_LSI_RTY_FIFO_CRED                      0x002440 /* established */
#define TIOCE_LSI_RTY_FIFO_CRED_COUNT                2
#define TIOCE_LSI_RTY_FIFO_CRED_STRIDE               4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_seq_cnt: rw64, reset unknown */
#define TIOCE_LSI_SEQ_CNT                            0x002448 /* established */
#define TIOCE_LSI_SEQ_CNT_COUNT                      2
#define TIOCE_LSI_SEQ_CNT_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ack_sent_seq_num). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ack_sent_seq_num: rw64, reset unknown */
#define TIOCE_LSI_ACK_SENT_SEQ_NUM                   0x002450 /* established */
#define TIOCE_LSI_ACK_SENT_SEQ_NUM_COUNT             2
#define TIOCE_LSI_ACK_SENT_SEQ_NUM_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_fifo_max_addr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_seq_cnt_fifo_max_addr: rw64, reset unknown */
#define TIOCE_LSI_SEQ_CNT_FIFO_MAX_ADDR              0x002458 /* established */
#define TIOCE_LSI_SEQ_CNT_FIFO_MAX_ADDR_COUNT        2
#define TIOCE_LSI_SEQ_CNT_FIFO_MAX_ADDR_STRIDE       4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_fifo_ptr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_seq_cnt_fifo_ptr: rw64, reset unknown */
#define TIOCE_LSI_SEQ_CNT_FIFO_PTR                   0x002460 /* established */
#define TIOCE_LSI_SEQ_CNT_FIFO_PTR_COUNT             2
#define TIOCE_LSI_SEQ_CNT_FIFO_PTR_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_rd_wr_ptr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_seq_cnt_rd_wr_ptr: rw64, reset unknown */
#define TIOCE_LSI_SEQ_CNT_RD_WR_PTR                  0x002468 /* established */
#define TIOCE_LSI_SEQ_CNT_RD_WR_PTR_COUNT            2
#define TIOCE_LSI_SEQ_CNT_RD_WR_PTR_STRIDE           4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_tx_lk_ts_ctl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_tx_lk_ts_ctl: rw64, reset unknown */
#define TIOCE_LSI_TX_LK_TS_CTL                       0x002470 /* established */
#define TIOCE_LSI_TX_LK_TS_CTL_COUNT                 2
#define TIOCE_LSI_TX_LK_TS_CTL_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_mem_addr_ctl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_mem_addr_ctl: rw64, reset unknown */
#define TIOCE_LSI_MEM_ADDR_CTL                       0x002480 /* established */
#define TIOCE_LSI_MEM_ADDR_CTL_COUNT                 2
#define TIOCE_LSI_MEM_ADDR_CTL_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_mem_d_ld0: rw64, reset unknown */
#define TIOCE_LSI_MEM_D_LD0                          0x002488 /* established */
#define TIOCE_LSI_MEM_D_LD0_COUNT                    2
#define TIOCE_LSI_MEM_D_LD0_STRIDE                   4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_mem_d_ld1: rw64, reset unknown */
#define TIOCE_LSI_MEM_D_LD1                          0x002490 /* established */
#define TIOCE_LSI_MEM_D_LD1_COUNT                    2
#define TIOCE_LSI_MEM_D_LD1_STRIDE                   4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_mem_d_ld2: rw64, reset unknown */
#define TIOCE_LSI_MEM_D_LD2                          0x002498 /* established */
#define TIOCE_LSI_MEM_D_LD2_COUNT                    2
#define TIOCE_LSI_MEM_D_LD2_STRIDE                   4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld3). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_mem_d_ld3: rw64, reset unknown */
#define TIOCE_LSI_MEM_D_LD3                          0x0024a0 /* established */
#define TIOCE_LSI_MEM_D_LD3_COUNT                    2
#define TIOCE_LSI_MEM_D_LD3_STRIDE                   4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld4). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_mem_d_ld4: rw64, reset unknown */
#define TIOCE_LSI_MEM_D_LD4                          0x0024a8 /* established */
#define TIOCE_LSI_MEM_D_LD4_COUNT                    2
#define TIOCE_LSI_MEM_D_LD4_STRIDE                   4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rty_d_cnt). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rty_d_cnt: rw64, reset unknown */
#define TIOCE_LSI_RTY_D_CNT                          0x0024c0 /* established */
#define TIOCE_LSI_RTY_D_CNT_COUNT                    2
#define TIOCE_LSI_RTY_D_CNT_STRIDE                   4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_seq_buf_cnt). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_seq_buf_cnt: rw64, reset unknown */
#define TIOCE_LSI_SEQ_BUF_CNT                        0x0024c8 /* established */
#define TIOCE_LSI_SEQ_BUF_CNT_COUNT                  2
#define TIOCE_LSI_SEQ_BUF_CNT_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_seq_buf_bt_d). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_seq_buf_bt_d: rw64, reset unknown */
#define TIOCE_LSI_SEQ_BUF_BT_D                       0x0024d0 /* established */
#define TIOCE_LSI_SEQ_BUF_BT_D_COUNT                 2
#define TIOCE_LSI_SEQ_BUF_BT_D_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ack_lat_thr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ack_lat_thr: rw64, reset unknown */
#define TIOCE_LSI_ACK_LAT_THR                        0x0024e0 /* established */
#define TIOCE_LSI_ACK_LAT_THR_COUNT                  2
#define TIOCE_LSI_ACK_LAT_THR_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_nxt_rcv_seq_1_cntr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_nxt_rcv_seq_1_cntr: rw64, reset unknown */
#define TIOCE_LSI_NXT_RCV_SEQ_1_CNTR                 0x002500 /* established */
#define TIOCE_LSI_NXT_RCV_SEQ_1_CNTR_COUNT           2
#define TIOCE_LSI_NXT_RCV_SEQ_1_CNTR_STRIDE          4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_unsp_dllp_rcvd). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_unsp_dllp_rcvd: rw64, reset unknown */
#define TIOCE_LSI_UNSP_DLLP_RCVD                     0x002508 /* established */
#define TIOCE_LSI_UNSP_DLLP_RCVD_COUNT               2
#define TIOCE_LSI_UNSP_DLLP_RCVD_STRIDE              4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_lk_ts_ctl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_lk_ts_ctl: rw64, reset unknown */
#define TIOCE_LSI_RCV_LK_TS_CTL                      0x002510 /* established */
#define TIOCE_LSI_RCV_LK_TS_CTL_COUNT                2
#define TIOCE_LSI_RCV_LK_TS_CTL_STRIDE               4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_cfg). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_phy_lyr_cfg: rw64, reset unknown */
#define TIOCE_LSI_PHY_LYR_CFG                        0x002600 /* established */
#define TIOCE_LSI_PHY_LYR_CFG_COUNT                  2
#define TIOCE_LSI_PHY_LYR_CFG_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_phy_lyr_int_stat: rw64, reset unknown */
#define TIOCE_LSI_PHY_LYR_INT_STAT                   0x002610 /* established */
#define TIOCE_LSI_PHY_LYR_INT_STAT_COUNT             2
#define TIOCE_LSI_PHY_LYR_INT_STAT_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_phy_lyr_int_stat_test: rw64, reset unknown */
#define TIOCE_LSI_PHY_LYR_INT_STAT_TEST              0x002618 /* established */
#define TIOCE_LSI_PHY_LYR_INT_STAT_TEST_COUNT        2
#define TIOCE_LSI_PHY_LYR_INT_STAT_TEST_STRIDE       4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_phy_lyr_int_mask: rw64, reset unknown */
#define TIOCE_LSI_PHY_LYR_INT_MASK                   0x002620 /* established */
#define TIOCE_LSI_PHY_LYR_INT_MASK_COUNT             2
#define TIOCE_LSI_PHY_LYR_INT_MASK_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_cfg). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_phy_cfg: rw64, reset unknown */
#define TIOCE_LSI_RCV_PHY_CFG                        0x002680 /* established */
#define TIOCE_LSI_RCV_PHY_CFG_COUNT                  2
#define TIOCE_LSI_RCV_PHY_CFG_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_phy_stat1: rw64, reset unknown */
#define TIOCE_LSI_RCV_PHY_STAT1                      0x002688 /* established */
#define TIOCE_LSI_RCV_PHY_STAT1_COUNT                2
#define TIOCE_LSI_RCV_PHY_STAT1_STRIDE               4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_phy_stat2: rw64, reset unknown */
#define TIOCE_LSI_RCV_PHY_STAT2                      0x002690 /* established */
#define TIOCE_LSI_RCV_PHY_STAT2_COUNT                2
#define TIOCE_LSI_RCV_PHY_STAT2_STRIDE               4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat3). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_phy_stat3: rw64, reset unknown */
#define TIOCE_LSI_RCV_PHY_STAT3                      0x002698 /* established */
#define TIOCE_LSI_RCV_PHY_STAT3_COUNT                2
#define TIOCE_LSI_RCV_PHY_STAT3_STRIDE               4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_phy_int_stat: rw64, reset unknown */
#define TIOCE_LSI_RCV_PHY_INT_STAT                   0x0026a0 /* established */
#define TIOCE_LSI_RCV_PHY_INT_STAT_COUNT             2
#define TIOCE_LSI_RCV_PHY_INT_STAT_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_phy_int_stat_test: rw64, reset unknown */
#define TIOCE_LSI_RCV_PHY_INT_STAT_TEST              0x0026a8 /* established */
#define TIOCE_LSI_RCV_PHY_INT_STAT_TEST_COUNT        2
#define TIOCE_LSI_RCV_PHY_INT_STAT_TEST_STRIDE       4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_rcv_phy_int_mask: rw64, reset unknown */
#define TIOCE_LSI_RCV_PHY_INT_MASK                   0x0026b0 /* established */
#define TIOCE_LSI_RCV_PHY_INT_MASK_COUNT             2
#define TIOCE_LSI_RCV_PHY_INT_MASK_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_cfg). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_tx_phy_cfg: rw64, reset unknown */
#define TIOCE_LSI_TX_PHY_CFG                         0x002700 /* established */
#define TIOCE_LSI_TX_PHY_CFG_COUNT                   2
#define TIOCE_LSI_TX_PHY_CFG_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_tx_phy_stat: rw64, reset unknown */
#define TIOCE_LSI_TX_PHY_STAT                        0x002708 /* established */
#define TIOCE_LSI_TX_PHY_STAT_COUNT                  2
#define TIOCE_LSI_TX_PHY_STAT_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_tx_phy_int_stat: rw64, reset unknown */
#define TIOCE_LSI_TX_PHY_INT_STAT                    0x002710 /* established */
#define TIOCE_LSI_TX_PHY_INT_STAT_COUNT              2
#define TIOCE_LSI_TX_PHY_INT_STAT_STRIDE             4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_tx_phy_int_stat_test: rw64, reset unknown */
#define TIOCE_LSI_TX_PHY_INT_STAT_TEST               0x002718 /* established */
#define TIOCE_LSI_TX_PHY_INT_STAT_TEST_COUNT         2
#define TIOCE_LSI_TX_PHY_INT_STAT_TEST_STRIDE        4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_tx_phy_int_mask: rw64, reset unknown */
#define TIOCE_LSI_TX_PHY_INT_MASK                    0x002720 /* established */
#define TIOCE_LSI_TX_PHY_INT_MASK_COUNT              2
#define TIOCE_LSI_TX_PHY_INT_MASK_STRIDE             4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_stat2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_tx_phy_stat2: rw64, reset unknown */
#define TIOCE_LSI_TX_PHY_STAT2                       0x002728 /* established */
#define TIOCE_LSI_TX_PHY_STAT2_COUNT                 2
#define TIOCE_LSI_TX_PHY_STAT2_STRIDE                4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_cfg1: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_CFG1                         0x002780 /* established */
#define TIOCE_LSI_LTSSM_CFG1_COUNT                   2
#define TIOCE_LSI_LTSSM_CFG1_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_cfg2: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_CFG2                         0x002788 /* established */
#define TIOCE_LSI_LTSSM_CFG2_COUNT                   2
#define TIOCE_LSI_LTSSM_CFG2_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg3). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_cfg3: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_CFG3                         0x002790 /* established */
#define TIOCE_LSI_LTSSM_CFG3_COUNT                   2
#define TIOCE_LSI_LTSSM_CFG3_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg4). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_cfg4: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_CFG4                         0x002798 /* established */
#define TIOCE_LSI_LTSSM_CFG4_COUNT                   2
#define TIOCE_LSI_LTSSM_CFG4_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg5). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_cfg5: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_CFG5                         0x0027a0 /* established */
#define TIOCE_LSI_LTSSM_CFG5_COUNT                   2
#define TIOCE_LSI_LTSSM_CFG5_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_stat1: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_STAT1                        0x0027a8 /* established */
#define TIOCE_LSI_LTSSM_STAT1_COUNT                  2
#define TIOCE_LSI_LTSSM_STAT1_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_stat2: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_STAT2                        0x0027b0 /* established */
#define TIOCE_LSI_LTSSM_STAT2_COUNT                  2
#define TIOCE_LSI_LTSSM_STAT2_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_int_stat: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_INT_STAT                     0x0027b8 /* established */
#define TIOCE_LSI_LTSSM_INT_STAT_COUNT               2
#define TIOCE_LSI_LTSSM_INT_STAT_STRIDE              4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_int_stat_test: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_INT_STAT_TEST                0x0027c0 /* established */
#define TIOCE_LSI_LTSSM_INT_STAT_TEST_COUNT          2
#define TIOCE_LSI_LTSSM_INT_STAT_TEST_STRIDE         4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_int_mask: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_INT_MASK                     0x0027c8 /* established */
#define TIOCE_LSI_LTSSM_INT_MASK_COUNT               2
#define TIOCE_LSI_LTSSM_INT_MASK_STRIDE              4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat_wr_en). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_ltssm_stat_wr_en: rw64, reset unknown */
#define TIOCE_LSI_LTSSM_STAT_WR_EN                   0x0027d0 /* established */
#define TIOCE_LSI_LTSSM_STAT_WR_EN_COUNT             2
#define TIOCE_LSI_LTSSM_STAT_WR_EN_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_cfg1: rw64, reset unknown */
#define TIOCE_LSI_GB_CFG1                            0x002800 /* established */
#define TIOCE_LSI_GB_CFG1_COUNT                      2
#define TIOCE_LSI_GB_CFG1_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_cfg2: rw64, reset unknown */
#define TIOCE_LSI_GB_CFG2                            0x002808 /* established */
#define TIOCE_LSI_GB_CFG2_COUNT                      2
#define TIOCE_LSI_GB_CFG2_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg3). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_cfg3: rw64, reset unknown */
#define TIOCE_LSI_GB_CFG3                            0x002810 /* established */
#define TIOCE_LSI_GB_CFG3_COUNT                      2
#define TIOCE_LSI_GB_CFG3_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg4). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_cfg4: rw64, reset unknown */
#define TIOCE_LSI_GB_CFG4                            0x002818 /* established */
#define TIOCE_LSI_GB_CFG4_COUNT                      2
#define TIOCE_LSI_GB_CFG4_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_stat: rw64, reset unknown */
#define TIOCE_LSI_GB_STAT                            0x002820 /* established */
#define TIOCE_LSI_GB_STAT_COUNT                      2
#define TIOCE_LSI_GB_STAT_STRIDE                     4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_int_stat: rw64, reset unknown */
#define TIOCE_LSI_GB_INT_STAT                        0x002828 /* established */
#define TIOCE_LSI_GB_INT_STAT_COUNT                  2
#define TIOCE_LSI_GB_INT_STAT_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_int_stat_test: rw64, reset unknown */
#define TIOCE_LSI_GB_INT_STAT_TEST                   0x002830 /* established */
#define TIOCE_LSI_GB_INT_STAT_TEST_COUNT             2
#define TIOCE_LSI_GB_INT_STAT_TEST_STRIDE            4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_mask). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_int_mask: rw64, reset unknown */
#define TIOCE_LSI_GB_INT_MASK                        0x002838 /* established */
#define TIOCE_LSI_GB_INT_MASK_COUNT                  2
#define TIOCE_LSI_GB_INT_MASK_STRIDE                 4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_pwr_dn1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_pwr_dn1: rw64, reset unknown */
#define TIOCE_LSI_GB_PWR_DN1                         0x002840 /* established */
#define TIOCE_LSI_GB_PWR_DN1_COUNT                   2
#define TIOCE_LSI_GB_PWR_DN1_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_lsi_gb_pwr_dn2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* lsi_gb_pwr_dn2: rw64, reset unknown */
#define TIOCE_LSI_GB_PWR_DN2                         0x002848 /* established */
#define TIOCE_LSI_GB_PWR_DN2_COUNT                   2
#define TIOCE_LSI_GB_PWR_DN2_STRIDE                  4096

/*
 * Name and offset are the vendor header's definition (struct member ce_crm_debug_mux). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* crm_debug_mux: rw64, reset unknown */
#define TIOCE_CRM_DEBUG_MUX                          0x004050 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* crm_ssp_err_cmd_wrd: rw64, reset unknown */
#define TIOCE_CRM_SSP_ERR_CMD_WRD                    0x004060 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* crm_ssp_err_addr: rw64, reset unknown */
#define TIOCE_CRM_SSP_ERR_ADDR                       0x004068 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_syn). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* crm_ssp_err_syn: rw64, reset unknown */
#define TIOCE_CRM_SSP_ERR_SYN                        0x004070 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_cxm_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* cxm_dyn_credit_status: rw64, reset unknown */
#define TIOCE_CXM_DYN_CREDIT_STATUS                  0x005010 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_cxm_last_credit_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* cxm_last_credit_status: rw64, reset unknown */
#define TIOCE_CXM_LAST_CREDIT_STATUS                 0x005018 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_cxm_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* cxm_credit_limit: rw64, reset unknown */
#define TIOCE_CXM_CREDIT_LIMIT                       0x005020 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_cxm_force_credit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* cxm_force_credit: rw64, reset unknown */
#define TIOCE_CXM_FORCE_CREDIT                       0x005028 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_cxm_disable_bypass). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* cxm_disable_bypass: rw64, reset unknown */
#define TIOCE_CXM_DISABLE_BYPASS                     0x005030 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_cxm_debug_mux). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* cxm_debug_mux: rw64, reset unknown */
#define TIOCE_CXM_DEBUG_MUX                          0x005050 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dtl_dtdr_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dtl_dtdr_credit_limit: rw64, reset unknown */
#define TIOCE_DTL_DTDR_CREDIT_LIMIT                  0x006000 /* established */
#define TIOCE_DTL_DTDR_CREDIT_LIMIT_COUNT            2
#define TIOCE_DTL_DTDR_CREDIT_LIMIT_STRIDE           8192

/*
 * Name and offset are the vendor header's definition (struct member ce_dtl_dtdr_credit_force). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dtl_dtdr_credit_force: rw64, reset unknown */
#define TIOCE_DTL_DTDR_CREDIT_FORCE                  0x006008 /* established */
#define TIOCE_DTL_DTDR_CREDIT_FORCE_COUNT            2
#define TIOCE_DTL_DTDR_CREDIT_FORCE_STRIDE           8192

/*
 * Name and offset are the vendor header's definition (struct member ce_dtl_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dtl_dyn_credit_status: rw64, reset unknown */
#define TIOCE_DTL_DYN_CREDIT_STATUS                  0x006010 /* established */
#define TIOCE_DTL_DYN_CREDIT_STATUS_COUNT            2
#define TIOCE_DTL_DYN_CREDIT_STATUS_STRIDE           8192

/*
 * Name and offset are the vendor header's definition (struct member ce_dtl_dtl_last_credit_stat). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dtl_dtl_last_credit_stat: rw64, reset unknown */
#define TIOCE_DTL_DTL_LAST_CREDIT_STAT               0x006018 /* established */
#define TIOCE_DTL_DTL_LAST_CREDIT_STAT_COUNT         2
#define TIOCE_DTL_DTL_LAST_CREDIT_STAT_STRIDE        8192

/*
 * Name and offset are the vendor header's definition (struct member ce_dtl_dtl_ctrl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dtl_dtl_ctrl: rw64, reset unknown */
#define TIOCE_DTL_DTL_CTRL                           0x006020 /* established */
#define TIOCE_DTL_DTL_CTRL_COUNT                     2
#define TIOCE_DTL_DTL_CTRL_STRIDE                    8192

/*
 * Name and offset are the vendor header's definition (struct member ce_dtl_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dtl_debug_sel: rw64, reset unknown */
#define TIOCE_DTL_DEBUG_SEL                          0x006050 /* established */
#define TIOCE_DTL_DEBUG_SEL_COUNT                    2
#define TIOCE_DTL_DEBUG_SEL_STRIDE                   8192

/*
 * Name and offset are the vendor header's definition (struct member ce_utl_utl_ctrl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* utl_utl_ctrl: rw64, reset unknown */
#define TIOCE_UTL_UTL_CTRL                           0x007000 /* established */
#define TIOCE_UTL_UTL_CTRL_COUNT                     2
#define TIOCE_UTL_UTL_CTRL_STRIDE                    8192

/*
 * Name and offset are the vendor header's definition (struct member ce_utl_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* utl_debug_sel: rw64, reset unknown */
#define TIOCE_UTL_DEBUG_SEL                          0x007008 /* established */
#define TIOCE_UTL_DEBUG_SEL_COUNT                    2
#define TIOCE_UTL_DEBUG_SEL_STRIDE                   8192

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_dyn_credit_status: rw64, reset unknown */
#define TIOCE_URE_DYN_CREDIT_STATUS                  0x00b010 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_last_credit_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_last_credit_status: rw64, reset unknown */
#define TIOCE_URE_LAST_CREDIT_STATUS                 0x00b018 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_credit_limit: rw64, reset unknown */
#define TIOCE_URE_CREDIT_LIMIT                       0x00b020 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_control). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_control: rw64, reset unknown */
#define TIOCE_URE_CONTROL                            0x00b030 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_status: rw64, reset unknown */
#define TIOCE_URE_STATUS                             0x00b038 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_debug_sel: rw64, reset unknown */
#define TIOCE_URE_DEBUG_SEL                          0x00b050 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie_debug_sel: rw64, reset unknown */
#define TIOCE_URE_PCIE_DEBUG_SEL                     0x00b058 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_ssp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_ssp_err_cmd_wrd: rw64, reset unknown */
#define TIOCE_URE_SSP_ERR_CMD_WRD                    0x00b060 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_ssp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_ssp_err_addr: rw64, reset unknown */
#define TIOCE_URE_SSP_ERR_ADDR                       0x00b068 /* established */

/*
 * Upstream request engine page size map. The provider clears the page-size field and sets it to the 256 KiB encoding (4) at attach, the largest the code uses; the 32/40-bit entries are then 256 KiB pages. Name and offset are the vendor header's definition (struct member ce_ure_page_map). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_page_map: rw64, reset unknown */
#define TIOCE_URE_PAGE_MAP                           0x00b070 /* established */

/*
 * Upstream request engine direct map, one per port. For 32-bit direct DMA the provider stores the target's coretalk address with the low 30 bits cleared (a 1 GiB-aligned base), reads it back to flush, and refcounts users: a second user needs the same base. Name and offset are the vendor header's definition (struct member ce_ure_dir_map). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_dir_map: rw64, reset unknown */
#define TIOCE_URE_DIR_MAP                            0x00b078 /* established */
#define TIOCE_URE_DIR_MAP_COUNT                      2
#define TIOCE_URE_DIR_MAP_STRIDE                     8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pipe_sel1: rw64, reset unknown */
#define TIOCE_URE_PIPE_SEL1                          0x00b088 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pipe_mask1: rw64, reset unknown */
#define TIOCE_URE_PIPE_MASK1                         0x00b090 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pipe_sel2: rw64, reset unknown */
#define TIOCE_URE_PIPE_SEL2                          0x00b098 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pipe_mask2: rw64, reset unknown */
#define TIOCE_URE_PIPE_MASK2                         0x00b0a0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credits_sent). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie1_credits_sent: rw64, reset unknown */
#define TIOCE_URE_PCIE1_CREDITS_SENT                 0x00b0a8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credits_used). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie1_credits_used: rw64, reset unknown */
#define TIOCE_URE_PCIE1_CREDITS_USED                 0x00b0b0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie1_credit_limit: rw64, reset unknown */
#define TIOCE_URE_PCIE1_CREDIT_LIMIT                 0x00b0b8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credits_sent). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie2_credits_sent: rw64, reset unknown */
#define TIOCE_URE_PCIE2_CREDITS_SENT                 0x00b0c0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credits_used). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie2_credits_used: rw64, reset unknown */
#define TIOCE_URE_PCIE2_CREDITS_USED                 0x00b0c8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie2_credit_limit: rw64, reset unknown */
#define TIOCE_URE_PCIE2_CREDIT_LIMIT                 0x00b0d0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie_force_credit). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie_force_credit: rw64, reset unknown */
#define TIOCE_URE_PCIE_FORCE_CREDIT                  0x00b0d8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_val). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_rd_tnum_val: rw64, reset unknown */
#define TIOCE_URE_RD_TNUM_VAL                        0x00b0e0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_rsp_rcvd). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_rd_tnum_rsp_rcvd: rw64, reset unknown */
#define TIOCE_URE_RD_TNUM_RSP_RCVD                   0x00b0e8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_esent_timer). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_rd_tnum_esent_timer: rw64, reset unknown */
#define TIOCE_URE_RD_TNUM_ESENT_TIMER                0x00b0f0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_error). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_rd_tnum_error: rw64, reset unknown */
#define TIOCE_URE_RD_TNUM_ERROR                      0x00b0f8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_first_cl). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_rd_tnum_first_cl: rw64, reset unknown */
#define TIOCE_URE_RD_TNUM_FIRST_CL                   0x00b100 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_link_buf). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_rd_tnum_link_buf: rw64, reset unknown */
#define TIOCE_URE_RD_TNUM_LINK_BUF                   0x00b108 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_wr_tnum_val). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_wr_tnum_val: rw64, reset unknown */
#define TIOCE_URE_WR_TNUM_VAL                        0x00b110 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_err_addr0: rw64, reset unknown */
#define TIOCE_URE_SRAM_ERR_ADDR0                     0x00b118 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_err_addr1: rw64, reset unknown */
#define TIOCE_URE_SRAM_ERR_ADDR1                     0x00b120 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_err_addr2: rw64, reset unknown */
#define TIOCE_URE_SRAM_ERR_ADDR2                     0x00b128 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_rd_addr0: rw64, reset unknown */
#define TIOCE_URE_SRAM_RD_ADDR0                      0x00b130 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_rd_addr1: rw64, reset unknown */
#define TIOCE_URE_SRAM_RD_ADDR1                      0x00b138 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_rd_addr2: rw64, reset unknown */
#define TIOCE_URE_SRAM_RD_ADDR2                      0x00b140 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_wr_addr0: rw64, reset unknown */
#define TIOCE_URE_SRAM_WR_ADDR0                      0x00b148 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_wr_addr1: rw64, reset unknown */
#define TIOCE_URE_SRAM_WR_ADDR1                      0x00b150 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_sram_wr_addr2: rw64, reset unknown */
#define TIOCE_URE_SRAM_WR_ADDR2                      0x00b158 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush10). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush10: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH10                        0x00b160 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush11). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush11: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH11                        0x00b168 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush12). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush12: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH12                        0x00b170 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush13). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush13: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH13                        0x00b178 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush20). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush20: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH20                        0x00b180 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush21). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush21: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH21                        0x00b188 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush22). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush22: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH22                        0x00b190 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_buf_flush23). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_buf_flush23: rw64, reset unknown */
#define TIOCE_URE_BUF_FLUSH23                        0x00b198 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie_control1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie_control1: rw64, reset unknown */
#define TIOCE_URE_PCIE_CONTROL1                      0x00b1a0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_pcie_control2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_pcie_control2: rw64, reset unknown */
#define TIOCE_URE_PCIE_CONTROL2                      0x00b1a8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_dat1_data63_0: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_DAT1_DATA63_0            0x00c000 /* established */
#define TIOCE_URE_MAINT_UPS_DAT1_DATA63_0_COUNT      512
#define TIOCE_URE_MAINT_UPS_DAT1_DATA63_0_STRIDE     8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_dat1_data127_64: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_DAT1_DATA127_64          0x00d000 /* established */
#define TIOCE_URE_MAINT_UPS_DAT1_DATA127_64_COUNT    512
#define TIOCE_URE_MAINT_UPS_DAT1_DATA127_64_STRIDE   8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_dat1_parity: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_DAT1_PARITY              0x00e000 /* established */
#define TIOCE_URE_MAINT_UPS_DAT1_PARITY_COUNT        512
#define TIOCE_URE_MAINT_UPS_DAT1_PARITY_STRIDE       8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_hdr1_data63_0: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_HDR1_DATA63_0            0x00f000 /* established */
#define TIOCE_URE_MAINT_UPS_HDR1_DATA63_0_COUNT      512
#define TIOCE_URE_MAINT_UPS_HDR1_DATA63_0_STRIDE     8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_hdr1_data127_64: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_HDR1_DATA127_64          0x010000 /* established */
#define TIOCE_URE_MAINT_UPS_HDR1_DATA127_64_COUNT    512
#define TIOCE_URE_MAINT_UPS_HDR1_DATA127_64_STRIDE   8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_hdr1_parity: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_HDR1_PARITY              0x011000 /* established */
#define TIOCE_URE_MAINT_UPS_HDR1_PARITY_COUNT        512
#define TIOCE_URE_MAINT_UPS_HDR1_PARITY_STRIDE       8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_dat2_data63_0: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_DAT2_DATA63_0            0x012000 /* established */
#define TIOCE_URE_MAINT_UPS_DAT2_DATA63_0_COUNT      512
#define TIOCE_URE_MAINT_UPS_DAT2_DATA63_0_STRIDE     8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_dat2_data127_64: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_DAT2_DATA127_64          0x013000 /* established */
#define TIOCE_URE_MAINT_UPS_DAT2_DATA127_64_COUNT    512
#define TIOCE_URE_MAINT_UPS_DAT2_DATA127_64_STRIDE   8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_dat2_parity: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_DAT2_PARITY              0x014000 /* established */
#define TIOCE_URE_MAINT_UPS_DAT2_PARITY_COUNT        512
#define TIOCE_URE_MAINT_UPS_DAT2_PARITY_STRIDE       8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_hdr2_data63_0: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_HDR2_DATA63_0            0x015000 /* established */
#define TIOCE_URE_MAINT_UPS_HDR2_DATA63_0_COUNT      512
#define TIOCE_URE_MAINT_UPS_HDR2_DATA63_0_STRIDE     8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_hdr2_data127_64: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_HDR2_DATA127_64          0x016000 /* established */
#define TIOCE_URE_MAINT_UPS_HDR2_DATA127_64_COUNT    512
#define TIOCE_URE_MAINT_UPS_HDR2_DATA127_64_STRIDE   8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_ups_hdr2_parity: rw64, reset unknown */
#define TIOCE_URE_MAINT_UPS_HDR2_PARITY              0x017000 /* established */
#define TIOCE_URE_MAINT_UPS_HDR2_PARITY_COUNT        512
#define TIOCE_URE_MAINT_UPS_HDR2_PARITY_STRIDE       8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_dns_dat_data63_0: rw64, reset unknown */
#define TIOCE_URE_MAINT_DNS_DAT_DATA63_0             0x018000 /* established */
#define TIOCE_URE_MAINT_DNS_DAT_DATA63_0_COUNT       512
#define TIOCE_URE_MAINT_DNS_DAT_DATA63_0_STRIDE      8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_dns_dat_data127_64: rw64, reset unknown */
#define TIOCE_URE_MAINT_DNS_DAT_DATA127_64           0x019000 /* established */
#define TIOCE_URE_MAINT_DNS_DAT_DATA127_64_COUNT     512
#define TIOCE_URE_MAINT_DNS_DAT_DATA127_64_STRIDE    8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_dns_dat_parity: rw64, reset unknown */
#define TIOCE_URE_MAINT_DNS_DAT_PARITY               0x01a000 /* established */
#define TIOCE_URE_MAINT_DNS_DAT_PARITY_COUNT         512
#define TIOCE_URE_MAINT_DNS_DAT_PARITY_STRIDE        8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_data31_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_dns_hdr_data31_0: rw64, reset unknown */
#define TIOCE_URE_MAINT_DNS_HDR_DATA31_0             0x01b000 /* established */
#define TIOCE_URE_MAINT_DNS_HDR_DATA31_0_COUNT       64
#define TIOCE_URE_MAINT_DNS_HDR_DATA31_0_STRIDE      8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_data95_32). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_dns_hdr_data95_32: rw64, reset unknown */
#define TIOCE_URE_MAINT_DNS_HDR_DATA95_32            0x01b200 /* established */
#define TIOCE_URE_MAINT_DNS_HDR_DATA95_32_COUNT      64
#define TIOCE_URE_MAINT_DNS_HDR_DATA95_32_STRIDE     8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_dns_hdr_parity: rw64, reset unknown */
#define TIOCE_URE_MAINT_DNS_HDR_PARITY               0x01b400 /* established */
#define TIOCE_URE_MAINT_DNS_HDR_PARITY_COUNT         64
#define TIOCE_URE_MAINT_DNS_HDR_PARITY_STRIDE        8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_rci_data41_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_rci_data41_0: rw64, reset unknown */
#define TIOCE_URE_MAINT_RCI_DATA41_0                 0x01b600 /* established */
#define TIOCE_URE_MAINT_RCI_DATA41_0_COUNT           64
#define TIOCE_URE_MAINT_RCI_DATA41_0_STRIDE          8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_rci_data69_42). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_rci_data69_42: rw64, reset unknown */
#define TIOCE_URE_MAINT_RCI_DATA69_42                0x01b800 /* established */
#define TIOCE_URE_MAINT_RCI_DATA69_42_COUNT          64
#define TIOCE_URE_MAINT_RCI_DATA69_42_STRIDE         8

/*
 * Name and offset are the vendor header's definition (struct member ce_ure_maint_rspq). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_maint_rspq: rw64, reset unknown */
#define TIOCE_URE_MAINT_RSPQ                         0x01ba00 /* established */
#define TIOCE_URE_MAINT_RSPQ_COUNT                   64
#define TIOCE_URE_MAINT_RSPQ_STRIDE                  8

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_maint_bap_buf_data63_0: rw64, reset unknown */
#define TIOCE_ADM_MAINT_BAP_BUF_DATA63_0             0x024000 /* established */
#define TIOCE_ADM_MAINT_BAP_BUF_DATA63_0_COUNT       258
#define TIOCE_ADM_MAINT_BAP_BUF_DATA63_0_STRIDE      8

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_maint_bap_buf_data127_64: rw64, reset unknown */
#define TIOCE_ADM_MAINT_BAP_BUF_DATA127_64           0x024810 /* established */
#define TIOCE_ADM_MAINT_BAP_BUF_DATA127_64_COUNT     258
#define TIOCE_ADM_MAINT_BAP_BUF_DATA127_64_STRIDE    8

/*
 * Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* adm_maint_bap_buf_parity: rw64, reset unknown */
#define TIOCE_ADM_MAINT_BAP_BUF_PARITY               0x025020 /* established */
#define TIOCE_ADM_MAINT_BAP_BUF_PARITY_COUNT         258
#define TIOCE_ADM_MAINT_BAP_BUF_PARITY_STRIDE        8

/*
 * Upstream request engine 40-bit address translation entries, 4096 entries. The provider uses 64 MiB pages: bus address 0x4000000000 plus index times 64 MiB. Entry bit 63 valid, bit 62 message-signalled interrupt (not capable here), the rest the page-aligned coretalk address. Name and offset are the vendor header's definition (struct member ce_ure_ate40). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_ate40: rw64, reset unknown */
#define TIOCE_URE_ATE40                              0x030000 /* established */
#define TIOCE_URE_ATE40_COUNT                        4096
#define TIOCE_URE_ATE40_STRIDE                       8

/*
 * Upstream request engine 32/40-bit address translation entries, 2048 entries. Entries 0 to 31 serve port 1 and 32 to 63 port 2 for 16 GiB super-page mappings; entries 64 and up map the 32-bit window in 256 KiB pages from bus address 0. Same entry layout as ce_ure_ate40, and message-signalled interrupt capable. Name and offset are the vendor header's definition (struct member ce_ure_ate3240). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* ure_ate3240: rw64, reset unknown */
#define TIOCE_URE_ATE3240                            0x038000 /* established */
#define TIOCE_URE_ATE3240_COUNT                      2048
#define TIOCE_URE_ATE3240_STRIDE                     8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_dyn_credit_status1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_dyn_credit_status1: rw64, reset unknown */
#define TIOCE_DRE_DYN_CREDIT_STATUS1                 0x040010 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_dyn_credit_status2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_dyn_credit_status2: rw64, reset unknown */
#define TIOCE_DRE_DYN_CREDIT_STATUS2                 0x040018 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_last_credit_status1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_last_credit_status1: rw64, reset unknown */
#define TIOCE_DRE_LAST_CREDIT_STATUS1                0x040020 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_last_credit_status2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_last_credit_status2: rw64, reset unknown */
#define TIOCE_DRE_LAST_CREDIT_STATUS2                0x040028 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_credit_limit1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_credit_limit1: rw64, reset unknown */
#define TIOCE_DRE_CREDIT_LIMIT1                      0x040030 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_credit_limit2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_credit_limit2: rw64, reset unknown */
#define TIOCE_DRE_CREDIT_LIMIT2                      0x040038 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_force_credit1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_force_credit1: rw64, reset unknown */
#define TIOCE_DRE_FORCE_CREDIT1                      0x040040 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_force_credit2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_force_credit2: rw64, reset unknown */
#define TIOCE_DRE_FORCE_CREDIT2                      0x040048 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_debug_mux1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_debug_mux1: rw64, reset unknown */
#define TIOCE_DRE_DEBUG_MUX1                         0x040050 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_debug_mux2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_debug_mux2: rw64, reset unknown */
#define TIOCE_DRE_DEBUG_MUX2                         0x040058 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_ssp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_ssp_err_cmd_wrd: rw64, reset unknown */
#define TIOCE_DRE_SSP_ERR_CMD_WRD                    0x040060 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_ssp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_ssp_err_addr: rw64, reset unknown */
#define TIOCE_DRE_SSP_ERR_ADDR                       0x040068 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_comp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_comp_err_cmd_wrd: rw64, reset unknown */
#define TIOCE_DRE_COMP_ERR_CMD_WRD                   0x040070 /* established */

/*
 * Downstream request engine completion error address. The provider writes zero to it at attach, after clearing the interrupt and error summaries. Name and offset are the vendor header's definition (struct member ce_dre_comp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_comp_err_addr: rw64, reset unknown */
#define TIOCE_DRE_COMP_ERR_ADDR                      0x040078 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_req_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_req_status: rw64, reset unknown */
#define TIOCE_DRE_REQ_STATUS                         0x040080 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_config1). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_config1: rw64, reset unknown */
#define TIOCE_DRE_CONFIG1                            0x040088 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_config2). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_config2: rw64, reset unknown */
#define TIOCE_DRE_CONFIG2                            0x040090 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_config_req_status). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_config_req_status: rw64, reset unknown */
#define TIOCE_DRE_CONFIG_REQ_STATUS                  0x040098 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_dyn_fifo). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_dyn_fifo: rw64, reset unknown */
#define TIOCE_DRE_DYN_FIFO                           0x040100 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_last_fifo). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_last_fifo: rw64, reset unknown */
#define TIOCE_DRE_LAST_FIFO                          0x040120 /* established */

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ds_head_q_data63_0: rw64, reset unknown */
#define TIOCE_DRE_MAINT_DS_HEAD_Q_DATA63_0           0x040200 /* established */
#define TIOCE_DRE_MAINT_DS_HEAD_Q_DATA63_0_COUNT     32
#define TIOCE_DRE_MAINT_DS_HEAD_Q_DATA63_0_STRIDE    8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ds_head_q_data127_64: rw64, reset unknown */
#define TIOCE_DRE_MAINT_DS_HEAD_Q_DATA127_64         0x040300 /* established */
#define TIOCE_DRE_MAINT_DS_HEAD_Q_DATA127_64_COUNT   32
#define TIOCE_DRE_MAINT_DS_HEAD_Q_DATA127_64_STRIDE  8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ds_head_q_parity: rw64, reset unknown */
#define TIOCE_DRE_MAINT_DS_HEAD_Q_PARITY             0x040400 /* established */
#define TIOCE_DRE_MAINT_DS_HEAD_Q_PARITY_COUNT       32
#define TIOCE_DRE_MAINT_DS_HEAD_Q_PARITY_STRIDE      8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ds_data_q_data63_0: rw64, reset unknown */
#define TIOCE_DRE_MAINT_DS_DATA_Q_DATA63_0           0x041000 /* established */
#define TIOCE_DRE_MAINT_DS_DATA_Q_DATA63_0_COUNT     256
#define TIOCE_DRE_MAINT_DS_DATA_Q_DATA63_0_STRIDE    8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ds_data_q_data127_64: rw64, reset unknown */
#define TIOCE_DRE_MAINT_DS_DATA_Q_DATA127_64         0x042000 /* established */
#define TIOCE_DRE_MAINT_DS_DATA_Q_DATA127_64_COUNT   256
#define TIOCE_DRE_MAINT_DS_DATA_Q_DATA127_64_STRIDE  8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ds_data_q_parity: rw64, reset unknown */
#define TIOCE_DRE_MAINT_DS_DATA_Q_PARITY             0x043000 /* established */
#define TIOCE_DRE_MAINT_DS_DATA_Q_PARITY_COUNT       256
#define TIOCE_DRE_MAINT_DS_DATA_Q_PARITY_STRIDE      8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_data63_0). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ure_us_rsp_q_data63_0: rw64, reset unknown */
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_DATA63_0        0x044000 /* established */
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_DATA63_0_COUNT  8
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_DATA63_0_STRIDE 8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_data127_64). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ure_us_rsp_q_data127_64: rw64, reset unknown */
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_DATA127_64      0x044100 /* established */
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_DATA127_64_COUNT 8
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_DATA127_64_STRIDE 8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_parity). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_ure_us_rsp_q_parity: rw64, reset unknown */
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_PARITY          0x044200 /* established */
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_PARITY_COUNT    8
#define TIOCE_DRE_MAINT_URE_US_RSP_Q_PARITY_STRIDE   8

/*
 * Name and offset are the vendor header's definition (struct member ce_dre_maint_us_wrt_rsp). The header gives no access direction or reset value; access rw is a placeholder.
 */
/* dre_maint_us_wrt_rsp: rw64, reset unknown */
#define TIOCE_DRE_MAINT_US_WRT_RSP                   0x044300 /* established */
#define TIOCE_DRE_MAINT_US_WRT_RSP_COUNT             32
#define TIOCE_DRE_MAINT_US_WRT_RSP_STRIDE            8

#define TIOCE_ADM_ERR_ADM_CREDIT_OFLOW               0x400000000ull /* established */
#define TIOCE_ADM_ERR_ADM_SRAM_PE                    0x800000000ull /* established */
#define TIOCE_ADM_ERR_ADM_SSP_REQ_TIMEOUT            0x80000000u /* established */
#define TIOCE_ADM_ERR_ADM_SSP_RSP_UNEXP              0x40000000u /* established */
#define TIOCE_ADM_ERR_CRM_SSP_REQ_INVALID            0x1u /* established */
#define TIOCE_ADM_ERR_CXM_CREDIT_OFLOW               0x40u /* established */
#define TIOCE_ADM_ERR_DRE_CREDIT_OFLOW               0x20000u /* established */
#define TIOCE_ADM_ERR_DRE_SRAM_PE                    0x40000u /* established */
#define TIOCE_ADM_ERR_DRE_SSP_REQ_INVAL              0x80u /* established */
#define TIOCE_ADM_ERR_DTL1_COMP_D_CRED_MAX_ERR       0x20000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_COMP_HD_CRED_MAX_ERR      0x10000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_INF_COMPL_CRED_UPDT_ERR   0x2000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_INF_NPOSTED_CRED_UPDT_ERR 0x8000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_INF_POSTED_CRED_UPDT_ERR  0x4000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_MIN_PDATA_CREDIT_ERR      0x1000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_NPOSTED_D_CRED_MAX_ERR    0x80000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_NPOSTED_HD_CRED_MAX_ERR   0x40000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_POSTED_D_CRED_MAX_ERR     0x200000000000ull /* established */
#define TIOCE_ADM_ERR_DTL1_POSTED_HD_CRED_MAX_ERR    0x100000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_COMP_D_CRED_MAX_ERR       0x8000000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_COMP_HD_CRED_MAX_ERR      0x4000000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_INF_COMPL_CRED_UPDT_ERR   0x800000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_INF_NPOSTED_CRED_UPDT_ERR 0x2000000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_INF_POSTED_CRED_UPDT_ERR  0x1000000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_MIN_PDATA_CREDIT_ERR      0x400000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_NPOSTED_D_CRED_MAX_ERR    0x20000000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_NPOSTED_HD_CRED_MAX_ERR   0x10000000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_POSTED_D_CRED_MAX_ERR     0x80000000000000ull /* established */
#define TIOCE_ADM_ERR_DTL2_POSTED_HD_CRED_MAX_ERR    0x40000000000000ull /* established */
#define TIOCE_ADM_ERR_MMR_ACCESS_ERROR               0x100000000ull /* established */
#define TIOCE_ADM_ERR_MMR_ADDR_ERROR                 0x200000000ull /* established */
#define TIOCE_ADM_ERR_PCIE_COMPL_TIMEOUT             0x4000u /* established */
#define TIOCE_ADM_ERR_PCIE_ERR_COMPL                 0x10000u /* established */
#define TIOCE_ADM_ERR_PCIE_UNEXP_COMPL               0x8000u /* established */
#define TIOCE_ADM_ERR_PORT1_PCIE_COR_ERR             0x100000000000000ull /* established */
#define TIOCE_ADM_ERR_PORT1_PCIE_FAT_ERR             0x400000000000000ull /* established */
#define TIOCE_ADM_ERR_PORT1_PCIE_NFAT_ERR            0x200000000000000ull /* established */
#define TIOCE_ADM_ERR_PORT2_PCIE_COR_ERR             0x800000000000000ull /* established */
#define TIOCE_ADM_ERR_PORT2_PCIE_FAT_ERR             0x2000000000000000ull /* established */
#define TIOCE_ADM_ERR_PORT2_PCIE_NFAT_ERR            0x1000000000000000ull /* established */
#define TIOCE_ADM_ERR_SSP_MBE                        0x20u /* established */
#define TIOCE_ADM_ERR_SSP_PROTOCOL_ERROR             0x8u /* established */
#define TIOCE_ADM_ERR_SSP_REQ_ADDR_ERR               0x1000u /* established */
#define TIOCE_ADM_ERR_SSP_REQ_BAD_BE                 0x2000u /* established */
#define TIOCE_ADM_ERR_SSP_REQ_HEADER                 0x2u /* established */
#define TIOCE_ADM_ERR_SSP_REQ_LONG                   0x100u /* established */
#define TIOCE_ADM_ERR_SSP_REQ_OFLOW                  0x200u /* established */
#define TIOCE_ADM_ERR_SSP_REQ_SHORT                  0x400u /* established */
#define TIOCE_ADM_ERR_SSP_REQ_SIDEBAND               0x800u /* established */
#define TIOCE_ADM_ERR_SSP_RSP_HEADER                 0x4u /* established */
#define TIOCE_ADM_ERR_SSP_RSP_INVALID                0x80000u /* established */
#define TIOCE_ADM_ERR_SSP_RSP_LONG                   0x100000u /* established */
#define TIOCE_ADM_ERR_SSP_RSP_SHORT                  0x200000u /* established */
#define TIOCE_ADM_ERR_SSP_RSP_SIDEBAND               0x400000u /* established */
#define TIOCE_ADM_ERR_SSP_SBE                        0x10u /* established */
#define TIOCE_ADM_ERR_URE_ATE3240_PAGE_FAULT         0x4000000u /* established */
#define TIOCE_ADM_ERR_URE_ATE40_PAGE_FAULT           0x8000000u /* established */
#define TIOCE_ADM_ERR_URE_CREDIT_OFLOW               0x10000000u /* established */
#define TIOCE_ADM_ERR_URE_SRAM_PE                    0x20000000u /* established */
#define TIOCE_ADM_ERR_URE_SSP_RD_REQ_TIMEOUT         0x2000000u /* established */
#define TIOCE_ADM_ERR_URE_SSP_RSP_UNEXP              0x800000u /* established */
#define TIOCE_ADM_ERR_URE_SSP_WR_REQ_TIMEOUT         0x1000000u /* established */
#define TIOCE_ADM_FORCE_INT_ALWAYS_SHFT              0x8u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT1_DEV_A_SHFT    0x0u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT1_DEV_B_SHFT    0x1u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT1_DEV_C_SHFT    0x2u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT1_DEV_D_SHFT    0x3u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT2_DEV_A_SHFT    0x4u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT2_DEV_B_SHFT    0x5u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT2_DEV_C_SHFT    0x6u /* established */
#define TIOCE_ADM_FORCE_INT_PCIE_PORT2_DEV_D_SHFT    0x7u /* established */
#define TIOCE_ADM_INT_CE_ERROR_SHFT                  0x0u /* established */
#define TIOCE_ADM_INT_LSI1_IP_ERROR_SHFT             0x1u /* established */
#define TIOCE_ADM_INT_LSI2_IP_ERROR_SHFT             0x2u /* established */
#define TIOCE_ADM_INT_PCIE_ERROR_SHFT                0x3u /* established */
#define TIOCE_ADM_INT_PCIE_MSG_SHFT                  0xeu /* established */
#define TIOCE_ADM_INT_PCIE_MSG_SLOT_0_SHFT           0xeu /* established */
#define TIOCE_ADM_INT_PCIE_MSG_SLOT_1_SHFT           0xfu /* established */
#define TIOCE_ADM_INT_PCIE_MSG_SLOT_2_SHFT           0x10u /* established */
#define TIOCE_ADM_INT_PCIE_MSG_SLOT_3_SHFT           0x11u /* established */
#define TIOCE_ADM_INT_PCIE_PORT1_DEV_A_SHFT          0x6u /* established */
#define TIOCE_ADM_INT_PCIE_PORT1_DEV_B_SHFT          0x7u /* established */
#define TIOCE_ADM_INT_PCIE_PORT1_DEV_C_SHFT          0x8u /* established */
#define TIOCE_ADM_INT_PCIE_PORT1_DEV_D_SHFT          0x9u /* established */
#define TIOCE_ADM_INT_PCIE_PORT2_DEV_A_SHFT          0xau /* established */
#define TIOCE_ADM_INT_PCIE_PORT2_DEV_B_SHFT          0xbu /* established */
#define TIOCE_ADM_INT_PCIE_PORT2_DEV_C_SHFT          0xcu /* established */
#define TIOCE_ADM_INT_PCIE_PORT2_DEV_D_SHFT          0xdu /* established */
#define TIOCE_ADM_INT_PORT1_HOTPLUG_EVENT_SHFT       0x4u /* established */
#define TIOCE_ADM_INT_PORT1_PM_PME_MSG_SHFT          0x16u /* established */
#define TIOCE_ADM_INT_PORT2_HOTPLUG_EVENT_SHFT       0x5u /* established */
#define TIOCE_ADM_INT_PORT2_PM_PME_MSG_SHFT          0x17u /* established */
#define TIOCE_BUS_SRC_ID_SHFT                        0x8u /* established */
#define TIOCE_DEV_SRC_ID_SHFT                        0x3u /* established */
#define TIOCE_DRE_ADDR_MODE_SHFT                     0x4u /* established */
#define TIOCE_DRE_CONFIG_COMPLETION_VALID            0x10u /* established */
#define TIOCE_DRE_CONFIG_REQUEST_ACTIVE              0x20u /* established */
#define TIOCE_DRE_DOWNSTREAM_CONFIG_ERROR            0x8u /* established */
#define TIOCE_DRE_DYN_RO_ENABLE                      0x2u /* established */
#define TIOCE_DRE_LAST_CONFIG_COMPLETION             0x7u /* established */
#define TIOCE_DRE_RO_ENABLE                          0x1u /* established */
#define TIOCE_DRE_SUP_CONFIG_COMP_ERROR              0x4u /* established */
#define TIOCE_DRE_SUP_IO_COMP_ERROR                  0x8u /* established */
#define TIOCE_E_CONFIG_BUS_SHFT                      0x14u /* established */
#define TIOCE_E_CONFIG_DEVICE_SHFT                   0xfu /* established */
#define TIOCE_E_CONFIG_FUNC_SHFT                     0xcu /* established */
#define TIOCE_FNC_SRC_ID_SHFT                        0x0u /* established */
#define TIOCE_HOST_BRIDGE_DEVICE_ID                  0x4001u /* established */
#define TIOCE_HOST_BRIDGE_VENDOR_ID                  0x10a9u /* established */
#define TIOCE_INTR_VECTOR_SHFT                       0x38u /* established */
#define TIOCE_LSI_GB_CFG1_LPBK_EN_MASK               0x40000u /* established */
#define TIOCE_LSI_GB_CFG1_LPBK_EN_SHFT               0x12u /* established */
#define TIOCE_LSI_GB_CFG1_LPBK_SEL_MASK              0x30000u /* established */
#define TIOCE_LSI_GB_CFG1_LPBK_SEL_SHFT              0x10u /* established */
#define TIOCE_LSI_GB_CFG1_RVRS_CLK_MASK              0x300000u /* established */
#define TIOCE_LSI_GB_CFG1_RVRS_CLK_SHFT              0x14u /* established */
#define TIOCE_LSI_GB_CFG1_RVRS_LB_MASK               0x80000u /* established */
#define TIOCE_LSI_GB_CFG1_RVRS_LB_SHFT               0x13u /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_ADJ_MASK             0x7000u /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_ADJ_SHFT             0xcu /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_FLT_MASK             0x8000u /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_FLT_SHFT             0xfu /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_SMP_MASK             0xf00u /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_SMP_SHFT             0x8u /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_THS_MASK             0xffu /* established */
#define TIOCE_LSI_GB_CFG1_RXL0S_THS_SHFT             0x0u /* established */
#define TIOCE_LSI_GB_CFG1_SLF_TS_MASK                0xf000000u /* established */
#define TIOCE_LSI_GB_CFG1_SLF_TS_SHFT                0x18u /* established */
#define TIOCE_NUM_M3240_ATES                         0x800u /* established */
#define TIOCE_NUM_M40_ATES                           0x1000u /* established */
#define TIOCE_NUM_PORTS                              0x2u /* established */
#define TIOCE_PART_NUM                               0xce00u /* established */
#define TIOCE_PIO_CONFIG_SPACE                       0x4000000u /* established */
#define TIOCE_PIO_CONFIG_SPACE_LEN                   0x4000000u /* established */
#define TIOCE_PIO_E_CONFIG_SPACE                     0x10000000u /* established */
#define TIOCE_PIO_E_CONFIG_SPACE_LEN                 0x10000000u /* established */
#define TIOCE_PIO_IO_SPACE                           0x100000000ull /* established */
#define TIOCE_PIO_IO_SPACE_ALIAS                     0x8000000u /* established */
#define TIOCE_PIO_IO_SPACE_ALIAS_LEN                 0x8000000u /* established */
#define TIOCE_PIO_IO_SPACE_LEN                       0x100000000ull /* established */
#define TIOCE_PIO_MEM_SPACE                          0x200000000ull /* established */
#define TIOCE_PIO_MMR                                0x0u /* established */
#define TIOCE_PIO_MMR_LEN                            0x4000000u /* established */
#define TIOCE_PKT_TRAFIC_SHRT                        0x10u /* established */
#define TIOCE_REV_A                                  0x1u /* established */
#define TIOCE_SRC_ID                                 0x1u /* established */
#define TIOCE_URE_ABP                                0x1u /* established */
#define TIOCE_URE_AIP                                0x8u /* established */
#define TIOCE_URE_ATE3240_ENABLE                     0x1u /* established */
#define TIOCE_URE_ATE40_ENABLE                       0x2u /* established */
#define TIOCE_URE_ATE_PAR_DISABLE                    0x1000000000ull /* established */
#define TIOCE_URE_DNS_DAT_PAR_DISABLE                0x8000000000ull /* established */
#define TIOCE_URE_DNS_HDR_PAR_DISABLE                0x10000000000ull /* established */
#define TIOCE_URE_ELAL1_SHFT                         0x8u /* established */
#define TIOCE_URE_ELAL_SHFT                          0x4u /* established */
#define TIOCE_URE_HPC                                0x40u /* established */
#define TIOCE_URE_HPS                                0x20u /* established */
#define TIOCE_URE_MALFORM_DISABLE                    0x100000000000ull /* established */
#define TIOCE_URE_MASK1_SHFT                         0x0u /* established */
#define TIOCE_URE_MASK2_SHFT                         0x14u /* established */
#define TIOCE_URE_MASK3_SHFT                         0x28u /* established */
#define TIOCE_URE_MSP                                0x4u /* established */
#define TIOCE_URE_PAGESIZE_SHFT                      0x4u /* established */
#define TIOCE_URE_PCP                                0x2u /* established */
#define TIOCE_URE_PIP                                0x10u /* established */
#define TIOCE_URE_PN1_SHFT                           0x10u /* established */
#define TIOCE_URE_PN2_SHFT                           0x18u /* established */
#define TIOCE_URE_PSN1_SHFT                          0x13u /* established */
#define TIOCE_URE_PSN2_SHFT                          0x20u /* established */
#define TIOCE_URE_RCI_PAR_DISABLE                    0x2000000000ull /* established */
#define TIOCE_URE_RD_MRG_ENABLE                      0x1u /* established */
#define TIOCE_URE_RSPQ_BYPASS_DISABLE                0x1000000u /* established */
#define TIOCE_URE_RSPQ_PAR_DISABLE                   0x4000000000ull /* established */
#define TIOCE_URE_SCC                                0x1000u /* established */
#define TIOCE_URE_SEL1_SHFT                          0x0u /* established */
#define TIOCE_URE_SEL2_SHFT                          0x14u /* established */
#define TIOCE_URE_SEL3_SHFT                          0x28u /* established */
#define TIOCE_URE_SI                                 0x1u /* established */
#define TIOCE_URE_SPLS_SHFT                          0xfu /* established */
#define TIOCE_URE_SPLV_SHFT                          0x7u /* established */
#define TIOCE_URE_UNSUP_DISABLE                      0x200000000000ull /* established */
#define TIOCE_URE_UPS_DAT1_PAR_DISABLE               0x100000000ull /* established */
#define TIOCE_URE_UPS_DAT2_PAR_DISABLE               0x400000000ull /* established */
#define TIOCE_URE_UPS_HDR1_PAR_DISABLE               0x200000000ull /* established */
#define TIOCE_URE_UPS_HDR2_PAR_DISABLE               0x800000000ull /* established */
#define TIOCE_URE_WRT_MRG_ENABLE1                    0x10u /* established */
#define TIOCE_URE_WRT_MRG_ENABLE2                    0x20u /* established */
#define TIOCE_URE_WRT_MRG_TIMER_SHFT                 0xcu /* established */
#define TIOCE_VIRT_PPB_DEVICE_ID                     0x4002u /* established */
#define TIOCE_VIRT_PPB_VENDOR_ID                     0x10a9u /* established */

#endif /* TIOCE_GEN_H */
