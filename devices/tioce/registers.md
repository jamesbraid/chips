<!-- generated from devices/tioce/registers.toml by defs-gen - do not edit, change the source -->

# TIOCE (TIO PCI Express bridge), as SGI's Linux Altix platform code defines it

Names and offsets are the definitions of SGI's Linux Altix platform code (header and provider, v5.3). The TIOCE's own register specification is not held. The header gives no access direction and no reset value for any register; rows say what the provider does where it touches one. Bit masks the header defines are listed as constants with the comment that precedes them, not attached to registers.

Unit `tioce`, macro prefix `TIOCE`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `adm_id` | 0x0 | rw | 64 |  |  | unknown | established |  |
| `adm_dyn_credit_status` | 0x10 | rw | 64 |  |  | unknown | established |  |
| `adm_last_credit_status` | 0x18 | rw | 64 |  |  | unknown | established |  |
| `adm_credit_limit` | 0x20 | rw | 64 |  |  | unknown | established |  |
| `adm_force_credit` | 0x28 | rw | 64 |  |  | unknown | established |  |
| `adm_control` | 0x30 | rw | 64 |  |  | unknown | established |  |
| `adm_mmr_chn_timeout` | 0x38 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_ure_timeout` | 0x40 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_dre_timeout` | 0x48 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_debug_sel` | 0x50 | rw | 64 |  |  | unknown | established |  |
| `adm_int_status` | 0x58 | rw | 64 |  |  | unknown | established |  |
| `adm_int_status_alias` | 0x60 | rw | 64 |  |  | unknown | established |  |
| `adm_int_mask` | 0x68 | rw | 64 |  |  | unknown | established |  |
| `adm_int_pending` | 0x70 | rw | 64 |  |  | unknown | established |  |
| `adm_force_int` | 0x78 | rw | 64 |  |  | unknown | established |  |
| `adm_ure_ups_buf_barrier_flush` | 0x80 | rw | 64 |  |  | unknown | established |  |
| `adm_int_dest` | 0x88 | rw | 64 | 15 |  | unknown | established |  |
| `adm_error_summary` | 0x100 | rw | 64 |  |  | unknown | established |  |
| `adm_error_summary_alias` | 0x108 | rw | 64 |  |  | unknown | established |  |
| `adm_error_mask` | 0x110 | rw | 64 |  |  | unknown | established |  |
| `adm_first_error` | 0x118 | rw | 64 |  |  | unknown | established |  |
| `adm_error_overflow` | 0x120 | rw | 64 |  |  | unknown | established |  |
| `adm_error_overflow_alias` | 0x128 | rw | 64 |  |  | unknown | established |  |
| `adm_tnum_error` | 0x140 | rw | 64 |  |  | unknown | established |  |
| `adm_mmr_err_detail` | 0x148 | rw | 64 |  |  | unknown | established |  |
| `adm_msg_sram_perr_detail` | 0x150 | rw | 64 |  |  | unknown | established |  |
| `adm_bap_sram_perr_detail` | 0x158 | rw | 64 |  |  | unknown | established |  |
| `adm_ce_sram_perr_detail` | 0x160 | rw | 64 |  |  | unknown | established |  |
| `adm_ce_credit_oflow_detail` | 0x168 | rw | 64 |  |  | unknown | established |  |
| `adm_tx_link_idle_max_timer` | 0x170 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_debug_sel` | 0x178 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_debug_sel_top` | 0x200 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_debug_lat_sel_lo_top` | 0x208 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_debug_lat_sel_hi_top` | 0x210 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_debug_trig_sel_top` | 0x218 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_debug_trig_lat_sel_lo_top` | 0x220 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_debug_trig_lat_sel_hi_top` | 0x228 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_trig_compare_top` | 0x230 | rw | 64 |  |  | unknown | established |  |
| `adm_pcie_trig_compare_en_top` | 0x238 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_debug_sel_top` | 0x240 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_debug_lat_sel_lo_top` | 0x248 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_debug_lat_sel_hi_top` | 0x250 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_debug_trig_sel_top` | 0x258 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_debug_trig_lat_sel_lo_top` | 0x260 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_debug_trig_lat_sel_hi_top` | 0x268 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_trig_compare_top` | 0x270 | rw | 64 |  |  | unknown | established |  |
| `adm_ssp_trig_compare_en_top` | 0x278 | rw | 64 |  |  | unknown | established |  |
| `adm_bap_ctrl` | 0x400 | rw | 64 |  |  | unknown | established |  |
| `msg_buf_data63_0` | 0x800 | rw | 64 | 35 |  | unknown | established |  |
| `msg_buf_data127_64` | 0xa00 | rw | 64 | 35 |  | unknown | established |  |
| `msg_buf_parity` | 0xc00 | rw | 64 | 35 |  | unknown | established |  |
| `lsi_lpu_id` | 0x2000 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rst` | 0x2008 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_dbg_stat` | 0x2010 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_dbg_cfg` | 0x2018 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_ctrl` | 0x2020 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_stat` | 0x2028 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_int_and_stat` | 0x2040 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_int_mask` | 0x2048 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_perf_cnt_sel` | 0x2100 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_perf_cnt_ctrl` | 0x2110 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_perf_cnt1` | 0x2120 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_perf_cnt1_test` | 0x2128 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_perf_cnt2` | 0x2130 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_perf_cnt2_test` | 0x2138 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_lyr_cfg` | 0x2200 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_lyr_status` | 0x2208 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_lyr_int_stat` | 0x2210 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_ly_int_stat_test` | 0x2218 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_lk_ly_int_stat_mask` | 0x2220 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_fc_upd_ctl` | 0x2240 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_flw_ctl_upd_to_timer` | 0x2260 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_flw_ctl_upd_timer0` | 0x2268 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_flw_ctl_upd_timer1` | 0x2270 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_freq_nak_lat_thrsh` | 0x2400 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ack_nak_lat_tmr` | 0x2408 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rply_tmr_thr` | 0x2410 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rply_tmr` | 0x2418 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rply_num_stat` | 0x2420 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rty_buf_max_addr` | 0x2428 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rty_fifo_ptr` | 0x2430 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rty_fifo_rd_wr_ptr` | 0x2438 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rty_fifo_cred` | 0x2440 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_seq_cnt` | 0x2448 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ack_sent_seq_num` | 0x2450 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_seq_cnt_fifo_max_addr` | 0x2458 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_seq_cnt_fifo_ptr` | 0x2460 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_seq_cnt_rd_wr_ptr` | 0x2468 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_tx_lk_ts_ctl` | 0x2470 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_mem_addr_ctl` | 0x2480 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_mem_d_ld0` | 0x2488 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_mem_d_ld1` | 0x2490 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_mem_d_ld2` | 0x2498 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_mem_d_ld3` | 0x24a0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_mem_d_ld4` | 0x24a8 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rty_d_cnt` | 0x24c0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_seq_buf_cnt` | 0x24c8 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_seq_buf_bt_d` | 0x24d0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ack_lat_thr` | 0x24e0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_nxt_rcv_seq_1_cntr` | 0x2500 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_unsp_dllp_rcvd` | 0x2508 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_lk_ts_ctl` | 0x2510 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_phy_lyr_cfg` | 0x2600 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_phy_lyr_int_stat` | 0x2610 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_phy_lyr_int_stat_test` | 0x2618 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_phy_lyr_int_mask` | 0x2620 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_phy_cfg` | 0x2680 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_phy_stat1` | 0x2688 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_phy_stat2` | 0x2690 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_phy_stat3` | 0x2698 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_phy_int_stat` | 0x26a0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_phy_int_stat_test` | 0x26a8 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_rcv_phy_int_mask` | 0x26b0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_tx_phy_cfg` | 0x2700 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_tx_phy_stat` | 0x2708 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_tx_phy_int_stat` | 0x2710 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_tx_phy_int_stat_test` | 0x2718 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_tx_phy_int_mask` | 0x2720 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_tx_phy_stat2` | 0x2728 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_cfg1` | 0x2780 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_cfg2` | 0x2788 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_cfg3` | 0x2790 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_cfg4` | 0x2798 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_cfg5` | 0x27a0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_stat1` | 0x27a8 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_stat2` | 0x27b0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_int_stat` | 0x27b8 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_int_stat_test` | 0x27c0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_int_mask` | 0x27c8 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_ltssm_stat_wr_en` | 0x27d0 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_cfg1` | 0x2800 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_cfg2` | 0x2808 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_cfg3` | 0x2810 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_cfg4` | 0x2818 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_stat` | 0x2820 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_int_stat` | 0x2828 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_int_stat_test` | 0x2830 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_int_mask` | 0x2838 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_pwr_dn1` | 0x2840 | rw | 64 | 2 |  | unknown | established |  |
| `lsi_gb_pwr_dn2` | 0x2848 | rw | 64 | 2 |  | unknown | established |  |
| `crm_debug_mux` | 0x4050 | rw | 64 |  |  | unknown | established |  |
| `crm_ssp_err_cmd_wrd` | 0x4060 | rw | 64 |  |  | unknown | established |  |
| `crm_ssp_err_addr` | 0x4068 | rw | 64 |  |  | unknown | established |  |
| `crm_ssp_err_syn` | 0x4070 | rw | 64 |  |  | unknown | established |  |
| `cxm_dyn_credit_status` | 0x5010 | rw | 64 |  |  | unknown | established |  |
| `cxm_last_credit_status` | 0x5018 | rw | 64 |  |  | unknown | established |  |
| `cxm_credit_limit` | 0x5020 | rw | 64 |  |  | unknown | established |  |
| `cxm_force_credit` | 0x5028 | rw | 64 |  |  | unknown | established |  |
| `cxm_disable_bypass` | 0x5030 | rw | 64 |  |  | unknown | established |  |
| `cxm_debug_mux` | 0x5050 | rw | 64 |  |  | unknown | established |  |
| `dtl_dtdr_credit_limit` | 0x6000 | rw | 64 | 2 |  | unknown | established |  |
| `dtl_dtdr_credit_force` | 0x6008 | rw | 64 | 2 |  | unknown | established |  |
| `dtl_dyn_credit_status` | 0x6010 | rw | 64 | 2 |  | unknown | established |  |
| `dtl_dtl_last_credit_stat` | 0x6018 | rw | 64 | 2 |  | unknown | established |  |
| `dtl_dtl_ctrl` | 0x6020 | rw | 64 | 2 |  | unknown | established |  |
| `dtl_debug_sel` | 0x6050 | rw | 64 | 2 |  | unknown | established |  |
| `utl_utl_ctrl` | 0x7000 | rw | 64 | 2 |  | unknown | established |  |
| `utl_debug_sel` | 0x7008 | rw | 64 | 2 |  | unknown | established |  |
| `ure_dyn_credit_status` | 0xb010 | rw | 64 |  |  | unknown | established |  |
| `ure_last_credit_status` | 0xb018 | rw | 64 |  |  | unknown | established |  |
| `ure_credit_limit` | 0xb020 | rw | 64 |  |  | unknown | established |  |
| `ure_control` | 0xb030 | rw | 64 |  |  | unknown | established |  |
| `ure_status` | 0xb038 | rw | 64 |  |  | unknown | established |  |
| `ure_debug_sel` | 0xb050 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie_debug_sel` | 0xb058 | rw | 64 |  |  | unknown | established |  |
| `ure_ssp_err_cmd_wrd` | 0xb060 | rw | 64 |  |  | unknown | established |  |
| `ure_ssp_err_addr` | 0xb068 | rw | 64 |  |  | unknown | established |  |
| `ure_page_map` | 0xb070 | rw | 64 |  |  | unknown | established |  |
| `ure_dir_map` | 0xb078 | rw | 64 | 2 |  | unknown | established |  |
| `ure_pipe_sel1` | 0xb088 | rw | 64 |  |  | unknown | established |  |
| `ure_pipe_mask1` | 0xb090 | rw | 64 |  |  | unknown | established |  |
| `ure_pipe_sel2` | 0xb098 | rw | 64 |  |  | unknown | established |  |
| `ure_pipe_mask2` | 0xb0a0 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie1_credits_sent` | 0xb0a8 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie1_credits_used` | 0xb0b0 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie1_credit_limit` | 0xb0b8 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie2_credits_sent` | 0xb0c0 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie2_credits_used` | 0xb0c8 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie2_credit_limit` | 0xb0d0 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie_force_credit` | 0xb0d8 | rw | 64 |  |  | unknown | established |  |
| `ure_rd_tnum_val` | 0xb0e0 | rw | 64 |  |  | unknown | established |  |
| `ure_rd_tnum_rsp_rcvd` | 0xb0e8 | rw | 64 |  |  | unknown | established |  |
| `ure_rd_tnum_esent_timer` | 0xb0f0 | rw | 64 |  |  | unknown | established |  |
| `ure_rd_tnum_error` | 0xb0f8 | rw | 64 |  |  | unknown | established |  |
| `ure_rd_tnum_first_cl` | 0xb100 | rw | 64 |  |  | unknown | established |  |
| `ure_rd_tnum_link_buf` | 0xb108 | rw | 64 |  |  | unknown | established |  |
| `ure_wr_tnum_val` | 0xb110 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_err_addr0` | 0xb118 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_err_addr1` | 0xb120 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_err_addr2` | 0xb128 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_rd_addr0` | 0xb130 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_rd_addr1` | 0xb138 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_rd_addr2` | 0xb140 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_wr_addr0` | 0xb148 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_wr_addr1` | 0xb150 | rw | 64 |  |  | unknown | established |  |
| `ure_sram_wr_addr2` | 0xb158 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush10` | 0xb160 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush11` | 0xb168 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush12` | 0xb170 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush13` | 0xb178 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush20` | 0xb180 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush21` | 0xb188 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush22` | 0xb190 | rw | 64 |  |  | unknown | established |  |
| `ure_buf_flush23` | 0xb198 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie_control1` | 0xb1a0 | rw | 64 |  |  | unknown | established |  |
| `ure_pcie_control2` | 0xb1a8 | rw | 64 |  |  | unknown | established |  |
| `ure_maint_ups_dat1_data63_0` | 0xc000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_dat1_data127_64` | 0xd000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_dat1_parity` | 0xe000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_hdr1_data63_0` | 0xf000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_hdr1_data127_64` | 0x10000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_hdr1_parity` | 0x11000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_dat2_data63_0` | 0x12000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_dat2_data127_64` | 0x13000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_dat2_parity` | 0x14000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_hdr2_data63_0` | 0x15000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_hdr2_data127_64` | 0x16000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_ups_hdr2_parity` | 0x17000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_dns_dat_data63_0` | 0x18000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_dns_dat_data127_64` | 0x19000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_dns_dat_parity` | 0x1a000 | rw | 64 | 512 |  | unknown | established |  |
| `ure_maint_dns_hdr_data31_0` | 0x1b000 | rw | 64 | 64 |  | unknown | established |  |
| `ure_maint_dns_hdr_data95_32` | 0x1b200 | rw | 64 | 64 |  | unknown | established |  |
| `ure_maint_dns_hdr_parity` | 0x1b400 | rw | 64 | 64 |  | unknown | established |  |
| `ure_maint_rci_data41_0` | 0x1b600 | rw | 64 | 64 |  | unknown | established |  |
| `ure_maint_rci_data69_42` | 0x1b800 | rw | 64 | 64 |  | unknown | established |  |
| `ure_maint_rspq` | 0x1ba00 | rw | 64 | 64 |  | unknown | established |  |
| `adm_maint_bap_buf_data63_0` | 0x24000 | rw | 64 | 258 |  | unknown | established |  |
| `adm_maint_bap_buf_data127_64` | 0x24810 | rw | 64 | 258 |  | unknown | established |  |
| `adm_maint_bap_buf_parity` | 0x25020 | rw | 64 | 258 |  | unknown | established |  |
| `ure_ate40` | 0x30000 | rw | 64 | 4096 |  | unknown | established |  |
| `ure_ate3240` | 0x38000 | rw | 64 | 2048 |  | unknown | established |  |
| `dre_dyn_credit_status1` | 0x40010 | rw | 64 |  |  | unknown | established |  |
| `dre_dyn_credit_status2` | 0x40018 | rw | 64 |  |  | unknown | established |  |
| `dre_last_credit_status1` | 0x40020 | rw | 64 |  |  | unknown | established |  |
| `dre_last_credit_status2` | 0x40028 | rw | 64 |  |  | unknown | established |  |
| `dre_credit_limit1` | 0x40030 | rw | 64 |  |  | unknown | established |  |
| `dre_credit_limit2` | 0x40038 | rw | 64 |  |  | unknown | established |  |
| `dre_force_credit1` | 0x40040 | rw | 64 |  |  | unknown | established |  |
| `dre_force_credit2` | 0x40048 | rw | 64 |  |  | unknown | established |  |
| `dre_debug_mux1` | 0x40050 | rw | 64 |  |  | unknown | established |  |
| `dre_debug_mux2` | 0x40058 | rw | 64 |  |  | unknown | established |  |
| `dre_ssp_err_cmd_wrd` | 0x40060 | rw | 64 |  |  | unknown | established |  |
| `dre_ssp_err_addr` | 0x40068 | rw | 64 |  |  | unknown | established |  |
| `dre_comp_err_cmd_wrd` | 0x40070 | rw | 64 |  |  | unknown | established |  |
| `dre_comp_err_addr` | 0x40078 | rw | 64 |  |  | unknown | established |  |
| `dre_req_status` | 0x40080 | rw | 64 |  |  | unknown | established |  |
| `dre_config1` | 0x40088 | rw | 64 |  |  | unknown | established |  |
| `dre_config2` | 0x40090 | rw | 64 |  |  | unknown | established |  |
| `dre_config_req_status` | 0x40098 | rw | 64 |  |  | unknown | established |  |
| `dre_dyn_fifo` | 0x40100 | rw | 64 |  |  | unknown | established |  |
| `dre_last_fifo` | 0x40120 | rw | 64 |  |  | unknown | established |  |
| `dre_maint_ds_head_q_data63_0` | 0x40200 | rw | 64 | 32 |  | unknown | established |  |
| `dre_maint_ds_head_q_data127_64` | 0x40300 | rw | 64 | 32 |  | unknown | established |  |
| `dre_maint_ds_head_q_parity` | 0x40400 | rw | 64 | 32 |  | unknown | established |  |
| `dre_maint_ds_data_q_data63_0` | 0x41000 | rw | 64 | 256 |  | unknown | established |  |
| `dre_maint_ds_data_q_data127_64` | 0x42000 | rw | 64 | 256 |  | unknown | established |  |
| `dre_maint_ds_data_q_parity` | 0x43000 | rw | 64 | 256 |  | unknown | established |  |
| `dre_maint_ure_us_rsp_q_data63_0` | 0x44000 | rw | 64 | 8 |  | unknown | established |  |
| `dre_maint_ure_us_rsp_q_data127_64` | 0x44100 | rw | 64 | 8 |  | unknown | established |  |
| `dre_maint_ure_us_rsp_q_parity` | 0x44200 | rw | 64 | 8 |  | unknown | established |  |
| `dre_maint_us_wrt_rsp` | 0x44300 | rw | 64 | 32 |  | unknown | established |  |

### Register `adm_id`

Widget identification word: part 0xce00, source id 1, revision A = 1 (header constants). Revision A needs the access workaround described on the unit page. Name and offset are the vendor header's definition (struct member ce_adm_id). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_dyn_credit_status`

Name and offset are the vendor header's definition (struct member ce_adm_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_last_credit_status`

Name and offset are the vendor header's definition (struct member ce_adm_last_credit_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_credit_limit`

Name and offset are the vendor header's definition (struct member ce_adm_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_force_credit`

Name and offset are the vendor header's definition (struct member ce_adm_force_credit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_control`

Name and offset are the vendor header's definition (struct member ce_adm_control). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_mmr_chn_timeout`

Name and offset are the vendor header's definition (struct member ce_adm_mmr_chn_timeout). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_ure_timeout`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_ure_timeout). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_dre_timeout`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_dre_timeout). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_debug_sel`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_int_status`

Interrupt status. Bit n is the interrupt source named by the header (error, link 1 and 2 errors, PCIe error, hot-plug events per port, INTA to INTD of each port, message slots 0 to 3, power-management events). The provider reads it on revision A before forcing an interrupt. Name and offset are the vendor header's definition (struct member ce_adm_int_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_int_status_alias`

Interrupt status alias. The provider sets every bit through it at attach to clear transients (the alias is the write path to clear; role from that use). Name and offset are the vendor header's definition (struct member ce_adm_int_status_alias). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_int_mask`

Interrupt mask. The provider sets a source bit, writes its destination, then clears the bit, so a set bit blocks the source while the destination is rewritten. Name and offset are the vendor header's definition (struct member ce_adm_int_mask). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_int_pending`

Name and offset are the vendor header's definition (struct member ce_adm_int_pending). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_force_int`

Force interrupt. Bits 0 to 7 force INTA to INTD of port 1 then port 2; bit 8 forces always. The bit numbering differs from the status register, and the provider maps explicitly. Revision A does not use it (workaround). Name and offset are the vendor header's definition (struct member ce_adm_force_int). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ure_ups_buf_barrier_flush`

Name and offset are the vendor header's definition (struct member ce_adm_ure_ups_buf_barrier_flush). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_int_dest`

Interrupt destination, one per source (the header declares fifteen). The provider writes the kernel vector in bits 63:56 (shift INTR_VECTOR_SHFT) ORed with the destination coretalk address of the target CPU, indexed by interrupt source bit. Name and offset are the vendor header's definition (struct member ce_adm_int_dest). The header gives no access direction or reset value; access rw is a placeholder.

Array of 15 registers, stride 8.

### Register `adm_error_summary`

Name and offset are the vendor header's definition (struct member ce_adm_error_summary). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_error_summary_alias`

Error summary alias. The provider sets every bit through it at attach to clear transient errors. Name and offset are the vendor header's definition (struct member ce_adm_error_summary_alias). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_error_mask`

Name and offset are the vendor header's definition (struct member ce_adm_error_mask). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_first_error`

Name and offset are the vendor header's definition (struct member ce_adm_first_error). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_error_overflow`

Name and offset are the vendor header's definition (struct member ce_adm_error_overflow). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_error_overflow_alias`

Name and offset are the vendor header's definition (struct member ce_adm_error_overflow_alias). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_tnum_error`

Name and offset are the vendor header's definition (struct member ce_adm_tnum_error). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_mmr_err_detail`

Name and offset are the vendor header's definition (struct member ce_adm_mmr_err_detail). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_msg_sram_perr_detail`

Name and offset are the vendor header's definition (struct member ce_adm_msg_sram_perr_detail). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_bap_sram_perr_detail`

Name and offset are the vendor header's definition (struct member ce_adm_bap_sram_perr_detail). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ce_sram_perr_detail`

Name and offset are the vendor header's definition (struct member ce_adm_ce_sram_perr_detail). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ce_credit_oflow_detail`

Name and offset are the vendor header's definition (struct member ce_adm_ce_credit_oflow_detail). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_tx_link_idle_max_timer`

Name and offset are the vendor header's definition (struct member ce_adm_tx_link_idle_max_timer). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_debug_sel`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_debug_sel_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_sel_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_debug_lat_sel_lo_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_debug_lat_sel_hi_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_debug_trig_sel_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_sel_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_debug_trig_lat_sel_lo_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_debug_trig_lat_sel_hi_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_trig_compare_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_trig_compare_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_pcie_trig_compare_en_top`

Name and offset are the vendor header's definition (struct member ce_adm_pcie_trig_compare_en_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_debug_sel_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_sel_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_debug_lat_sel_lo_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_debug_lat_sel_hi_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_debug_trig_sel_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_sel_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_debug_trig_lat_sel_lo_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_lat_sel_lo_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_debug_trig_lat_sel_hi_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_lat_sel_hi_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_trig_compare_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_trig_compare_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_ssp_trig_compare_en_top`

Name and offset are the vendor header's definition (struct member ce_adm_ssp_trig_compare_en_top). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_bap_ctrl`

Name and offset are the vendor header's definition (struct member ce_adm_bap_ctrl). The header gives no access direction or reset value; access rw is a placeholder.

### Register `msg_buf_data63_0`

Name and offset are the vendor header's definition (struct member ce_msg_buf_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 35 registers, stride 8.

### Register `msg_buf_data127_64`

Name and offset are the vendor header's definition (struct member ce_msg_buf_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 35 registers, stride 8.

### Register `msg_buf_parity`

Name and offset are the vendor header's definition (struct member ce_msg_buf_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 35 registers, stride 8.

### Register `lsi_lpu_id`

Name and offset are the vendor header's definition (struct member ce_lsi_lpu_id). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rst`

Name and offset are the vendor header's definition (struct member ce_lsi_rst). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_dbg_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_dbg_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_dbg_cfg`

Name and offset are the vendor header's definition (struct member ce_lsi_dbg_cfg). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_ctrl`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_ctrl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_int_and_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_int_and_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_int_mask`

Name and offset are the vendor header's definition (struct member ce_lsi_int_mask). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_perf_cnt_sel`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt_sel). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_perf_cnt_ctrl`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt_ctrl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_perf_cnt1`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_perf_cnt1_test`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt1_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_perf_cnt2`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_perf_cnt2_test`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt2_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_lyr_cfg`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_cfg). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_lyr_status`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_status). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_lyr_int_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_int_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_ly_int_stat_test`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_ly_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_lk_ly_int_stat_mask`

Name and offset are the vendor header's definition (struct member ce_lsi_lk_ly_int_stat_mask). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_fc_upd_ctl`

Name and offset are the vendor header's definition (struct member ce_lsi_fc_upd_ctl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_flw_ctl_upd_to_timer`

Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_to_timer). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_flw_ctl_upd_timer0`

Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_timer0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_flw_ctl_upd_timer1`

Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_timer1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_freq_nak_lat_thrsh`

Name and offset are the vendor header's definition (struct member ce_lsi_freq_nak_lat_thrsh). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ack_nak_lat_tmr`

Name and offset are the vendor header's definition (struct member ce_lsi_ack_nak_lat_tmr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rply_tmr_thr`

Name and offset are the vendor header's definition (struct member ce_lsi_rply_tmr_thr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rply_tmr`

Name and offset are the vendor header's definition (struct member ce_lsi_rply_tmr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rply_num_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_rply_num_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rty_buf_max_addr`

Name and offset are the vendor header's definition (struct member ce_lsi_rty_buf_max_addr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rty_fifo_ptr`

Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_ptr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rty_fifo_rd_wr_ptr`

Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_rd_wr_ptr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rty_fifo_cred`

Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_cred). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_seq_cnt`

Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ack_sent_seq_num`

Name and offset are the vendor header's definition (struct member ce_lsi_ack_sent_seq_num). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_seq_cnt_fifo_max_addr`

Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_fifo_max_addr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_seq_cnt_fifo_ptr`

Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_fifo_ptr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_seq_cnt_rd_wr_ptr`

Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_rd_wr_ptr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_tx_lk_ts_ctl`

Name and offset are the vendor header's definition (struct member ce_lsi_tx_lk_ts_ctl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_mem_addr_ctl`

Name and offset are the vendor header's definition (struct member ce_lsi_mem_addr_ctl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_mem_d_ld0`

Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_mem_d_ld1`

Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_mem_d_ld2`

Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_mem_d_ld3`

Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld3). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_mem_d_ld4`

Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld4). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rty_d_cnt`

Name and offset are the vendor header's definition (struct member ce_lsi_rty_d_cnt). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_seq_buf_cnt`

Name and offset are the vendor header's definition (struct member ce_lsi_seq_buf_cnt). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_seq_buf_bt_d`

Name and offset are the vendor header's definition (struct member ce_lsi_seq_buf_bt_d). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ack_lat_thr`

Name and offset are the vendor header's definition (struct member ce_lsi_ack_lat_thr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_nxt_rcv_seq_1_cntr`

Name and offset are the vendor header's definition (struct member ce_lsi_nxt_rcv_seq_1_cntr). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_unsp_dllp_rcvd`

Name and offset are the vendor header's definition (struct member ce_lsi_unsp_dllp_rcvd). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_lk_ts_ctl`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_lk_ts_ctl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_phy_lyr_cfg`

Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_cfg). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_phy_lyr_int_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_phy_lyr_int_stat_test`

Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_phy_lyr_int_mask`

Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_mask). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_phy_cfg`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_cfg). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_phy_stat1`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_phy_stat2`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_phy_stat3`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat3). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_phy_int_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_phy_int_stat_test`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_rcv_phy_int_mask`

Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_mask). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_tx_phy_cfg`

Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_cfg). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_tx_phy_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_tx_phy_int_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_tx_phy_int_stat_test`

Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_tx_phy_int_mask`

Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_mask). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_tx_phy_stat2`

Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_stat2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_cfg1`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_cfg2`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_cfg3`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg3). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_cfg4`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg4). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_cfg5`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg5). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_stat1`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_stat2`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_int_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_int_stat_test`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_int_mask`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_mask). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_ltssm_stat_wr_en`

Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat_wr_en). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_cfg1`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_cfg2`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_cfg3`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg3). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_cfg4`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg4). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_int_stat`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_int_stat_test`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_stat_test). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_int_mask`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_mask). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_pwr_dn1`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_pwr_dn1). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `lsi_gb_pwr_dn2`

Name and offset are the vendor header's definition (struct member ce_lsi_gb_pwr_dn2). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 4096.

### Register `crm_debug_mux`

Name and offset are the vendor header's definition (struct member ce_crm_debug_mux). The header gives no access direction or reset value; access rw is a placeholder.

### Register `crm_ssp_err_cmd_wrd`

Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.

### Register `crm_ssp_err_addr`

Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.

### Register `crm_ssp_err_syn`

Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_syn). The header gives no access direction or reset value; access rw is a placeholder.

### Register `cxm_dyn_credit_status`

Name and offset are the vendor header's definition (struct member ce_cxm_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `cxm_last_credit_status`

Name and offset are the vendor header's definition (struct member ce_cxm_last_credit_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `cxm_credit_limit`

Name and offset are the vendor header's definition (struct member ce_cxm_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `cxm_force_credit`

Name and offset are the vendor header's definition (struct member ce_cxm_force_credit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `cxm_disable_bypass`

Name and offset are the vendor header's definition (struct member ce_cxm_disable_bypass). The header gives no access direction or reset value; access rw is a placeholder.

### Register `cxm_debug_mux`

Name and offset are the vendor header's definition (struct member ce_cxm_debug_mux). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dtl_dtdr_credit_limit`

Name and offset are the vendor header's definition (struct member ce_dtl_dtdr_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `dtl_dtdr_credit_force`

Name and offset are the vendor header's definition (struct member ce_dtl_dtdr_credit_force). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `dtl_dyn_credit_status`

Name and offset are the vendor header's definition (struct member ce_dtl_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `dtl_dtl_last_credit_stat`

Name and offset are the vendor header's definition (struct member ce_dtl_dtl_last_credit_stat). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `dtl_dtl_ctrl`

Name and offset are the vendor header's definition (struct member ce_dtl_dtl_ctrl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `dtl_debug_sel`

Name and offset are the vendor header's definition (struct member ce_dtl_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `utl_utl_ctrl`

Name and offset are the vendor header's definition (struct member ce_utl_utl_ctrl). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `utl_debug_sel`

Name and offset are the vendor header's definition (struct member ce_utl_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8192.

### Register `ure_dyn_credit_status`

Name and offset are the vendor header's definition (struct member ce_ure_dyn_credit_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_last_credit_status`

Name and offset are the vendor header's definition (struct member ce_ure_last_credit_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_credit_limit`

Name and offset are the vendor header's definition (struct member ce_ure_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_control`

Name and offset are the vendor header's definition (struct member ce_ure_control). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_status`

Name and offset are the vendor header's definition (struct member ce_ure_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_debug_sel`

Name and offset are the vendor header's definition (struct member ce_ure_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie_debug_sel`

Name and offset are the vendor header's definition (struct member ce_ure_pcie_debug_sel). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_ssp_err_cmd_wrd`

Name and offset are the vendor header's definition (struct member ce_ure_ssp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_ssp_err_addr`

Name and offset are the vendor header's definition (struct member ce_ure_ssp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_page_map`

Upstream request engine page size map. The provider clears the page-size field and sets it to the 256 KiB encoding (4) at attach, the largest the code uses; the 32/40-bit entries are then 256 KiB pages. Name and offset are the vendor header's definition (struct member ce_ure_page_map). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_dir_map`

Upstream request engine direct map, one per port. For 32-bit direct DMA the provider stores the target's coretalk address with the low 30 bits cleared (a 1 GiB-aligned base), reads it back to flush, and refcounts users: a second user needs the same base. Name and offset are the vendor header's definition (struct member ce_ure_dir_map). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8.

### Register `ure_pipe_sel1`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pipe_mask1`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pipe_sel2`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pipe_mask2`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie1_credits_sent`

Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credits_sent). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie1_credits_used`

Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credits_used). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie1_credit_limit`

Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie2_credits_sent`

Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credits_sent). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie2_credits_used`

Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credits_used). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie2_credit_limit`

Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credit_limit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie_force_credit`

Name and offset are the vendor header's definition (struct member ce_ure_pcie_force_credit). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_rd_tnum_val`

Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_val). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_rd_tnum_rsp_rcvd`

Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_rsp_rcvd). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_rd_tnum_esent_timer`

Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_esent_timer). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_rd_tnum_error`

Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_error). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_rd_tnum_first_cl`

Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_first_cl). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_rd_tnum_link_buf`

Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_link_buf). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_wr_tnum_val`

Name and offset are the vendor header's definition (struct member ce_ure_wr_tnum_val). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_err_addr0`

Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr0). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_err_addr1`

Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_err_addr2`

Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_rd_addr0`

Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr0). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_rd_addr1`

Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_rd_addr2`

Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_wr_addr0`

Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr0). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_wr_addr1`

Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_sram_wr_addr2`

Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush10`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush10). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush11`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush11). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush12`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush12). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush13`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush13). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush20`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush20). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush21`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush21). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush22`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush22). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_buf_flush23`

Name and offset are the vendor header's definition (struct member ce_ure_buf_flush23). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie_control1`

Name and offset are the vendor header's definition (struct member ce_ure_pcie_control1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_pcie_control2`

Name and offset are the vendor header's definition (struct member ce_ure_pcie_control2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `ure_maint_ups_dat1_data63_0`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_dat1_data127_64`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_dat1_parity`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_hdr1_data63_0`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_hdr1_data127_64`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_hdr1_parity`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_dat2_data63_0`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_dat2_data127_64`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_dat2_parity`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_hdr2_data63_0`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_hdr2_data127_64`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_ups_hdr2_parity`

Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_dns_dat_data63_0`

Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_dns_dat_data127_64`

Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_dns_dat_parity`

Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 512 registers, stride 8.

### Register `ure_maint_dns_hdr_data31_0`

Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_data31_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 64 registers, stride 8.

### Register `ure_maint_dns_hdr_data95_32`

Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_data95_32). The header gives no access direction or reset value; access rw is a placeholder.

Array of 64 registers, stride 8.

### Register `ure_maint_dns_hdr_parity`

Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 64 registers, stride 8.

### Register `ure_maint_rci_data41_0`

Name and offset are the vendor header's definition (struct member ce_ure_maint_rci_data41_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 64 registers, stride 8.

### Register `ure_maint_rci_data69_42`

Name and offset are the vendor header's definition (struct member ce_ure_maint_rci_data69_42). The header gives no access direction or reset value; access rw is a placeholder.

Array of 64 registers, stride 8.

### Register `ure_maint_rspq`

Name and offset are the vendor header's definition (struct member ce_ure_maint_rspq). The header gives no access direction or reset value; access rw is a placeholder.

Array of 64 registers, stride 8.

### Register `adm_maint_bap_buf_data63_0`

Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 258 registers, stride 8.

### Register `adm_maint_bap_buf_data127_64`

Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 258 registers, stride 8.

### Register `adm_maint_bap_buf_parity`

Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 258 registers, stride 8.

### Register `ure_ate40`

Upstream request engine 40-bit address translation entries, 4096 entries. The provider uses 64 MiB pages: bus address 0x4000000000 plus index times 64 MiB. Entry bit 63 valid, bit 62 message-signalled interrupt (not capable here), the rest the page-aligned coretalk address. Name and offset are the vendor header's definition (struct member ce_ure_ate40). The header gives no access direction or reset value; access rw is a placeholder.

Array of 4096 registers, stride 8.

### Register `ure_ate3240`

Upstream request engine 32/40-bit address translation entries, 2048 entries. Entries 0 to 31 serve port 1 and 32 to 63 port 2 for 16 GiB super-page mappings; entries 64 and up map the 32-bit window in 256 KiB pages from bus address 0. Same entry layout as ce_ure_ate40, and message-signalled interrupt capable. Name and offset are the vendor header's definition (struct member ce_ure_ate3240). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2048 registers, stride 8.

### Register `dre_dyn_credit_status1`

Name and offset are the vendor header's definition (struct member ce_dre_dyn_credit_status1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_dyn_credit_status2`

Name and offset are the vendor header's definition (struct member ce_dre_dyn_credit_status2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_last_credit_status1`

Name and offset are the vendor header's definition (struct member ce_dre_last_credit_status1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_last_credit_status2`

Name and offset are the vendor header's definition (struct member ce_dre_last_credit_status2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_credit_limit1`

Name and offset are the vendor header's definition (struct member ce_dre_credit_limit1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_credit_limit2`

Name and offset are the vendor header's definition (struct member ce_dre_credit_limit2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_force_credit1`

Name and offset are the vendor header's definition (struct member ce_dre_force_credit1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_force_credit2`

Name and offset are the vendor header's definition (struct member ce_dre_force_credit2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_debug_mux1`

Name and offset are the vendor header's definition (struct member ce_dre_debug_mux1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_debug_mux2`

Name and offset are the vendor header's definition (struct member ce_dre_debug_mux2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_ssp_err_cmd_wrd`

Name and offset are the vendor header's definition (struct member ce_dre_ssp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_ssp_err_addr`

Name and offset are the vendor header's definition (struct member ce_dre_ssp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_comp_err_cmd_wrd`

Name and offset are the vendor header's definition (struct member ce_dre_comp_err_cmd_wrd). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_comp_err_addr`

Downstream request engine completion error address. The provider ORs zero into it at attach, after setting the interrupt and error summary alias bits, so the value is read and written back unchanged. Name and offset are the vendor header's definition (struct member ce_dre_comp_err_addr). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_req_status`

Name and offset are the vendor header's definition (struct member ce_dre_req_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_config1`

Name and offset are the vendor header's definition (struct member ce_dre_config1). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_config2`

Name and offset are the vendor header's definition (struct member ce_dre_config2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_config_req_status`

Name and offset are the vendor header's definition (struct member ce_dre_config_req_status). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_dyn_fifo`

Name and offset are the vendor header's definition (struct member ce_dre_dyn_fifo). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_last_fifo`

Name and offset are the vendor header's definition (struct member ce_dre_last_fifo). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_maint_ds_head_q_data63_0`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 32 registers, stride 8.

### Register `dre_maint_ds_head_q_data127_64`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 32 registers, stride 8.

### Register `dre_maint_ds_head_q_parity`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 32 registers, stride 8.

### Register `dre_maint_ds_data_q_data63_0`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 256 registers, stride 8.

### Register `dre_maint_ds_data_q_data127_64`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 256 registers, stride 8.

### Register `dre_maint_ds_data_q_parity`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 256 registers, stride 8.

### Register `dre_maint_ure_us_rsp_q_data63_0`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_data63_0). The header gives no access direction or reset value; access rw is a placeholder.

Array of 8 registers, stride 8.

### Register `dre_maint_ure_us_rsp_q_data127_64`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_data127_64). The header gives no access direction or reset value; access rw is a placeholder.

Array of 8 registers, stride 8.

### Register `dre_maint_ure_us_rsp_q_parity`

Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_parity). The header gives no access direction or reset value; access rw is a placeholder.

Array of 8 registers, stride 8.

### Register `dre_maint_us_wrt_rsp`

Name and offset are the vendor header's definition (struct member ce_dre_maint_us_wrt_rsp). The header gives no access direction or reset value; access rw is a placeholder.

Array of 32 registers, stride 8.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ADM_ERR_ADM_CREDIT_OFLOW` | 0x400000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_ADM_SRAM_PE` | 0x800000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_ADM_SSP_REQ_TIMEOUT` | 0x80000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_ADM_SSP_RSP_UNEXP` | 0x40000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_CRM_SSP_REQ_INVALID` | 0x1 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_CXM_CREDIT_OFLOW` | 0x40 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DRE_CREDIT_OFLOW` | 0x20000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DRE_SRAM_PE` | 0x40000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DRE_SSP_REQ_INVAL` | 0x80 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_COMP_D_CRED_MAX_ERR` | 0x20000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_COMP_HD_CRED_MAX_ERR` | 0x10000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_INF_COMPL_CRED_UPDT_ERR` | 0x2000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_INF_NPOSTED_CRED_UPDT_ERR` | 0x8000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_INF_POSTED_CRED_UPDT_ERR` | 0x4000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_MIN_PDATA_CREDIT_ERR` | 0x1000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_NPOSTED_D_CRED_MAX_ERR` | 0x80000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_NPOSTED_HD_CRED_MAX_ERR` | 0x40000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_POSTED_D_CRED_MAX_ERR` | 0x200000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL1_POSTED_HD_CRED_MAX_ERR` | 0x100000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_COMP_D_CRED_MAX_ERR` | 0x8000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_COMP_HD_CRED_MAX_ERR` | 0x4000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_INF_COMPL_CRED_UPDT_ERR` | 0x800000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_INF_NPOSTED_CRED_UPDT_ERR` | 0x2000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_INF_POSTED_CRED_UPDT_ERR` | 0x1000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_MIN_PDATA_CREDIT_ERR` | 0x400000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_NPOSTED_D_CRED_MAX_ERR` | 0x20000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_NPOSTED_HD_CRED_MAX_ERR` | 0x10000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_POSTED_D_CRED_MAX_ERR` | 0x80000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_DTL2_POSTED_HD_CRED_MAX_ERR` | 0x40000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_MMR_ACCESS_ERROR` | 0x100000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_MMR_ADDR_ERROR` | 0x200000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PCIE_COMPL_TIMEOUT` | 0x4000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PCIE_ERR_COMPL` | 0x10000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PCIE_UNEXP_COMPL` | 0x8000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PORT1_PCIE_COR_ERR` | 0x100000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PORT1_PCIE_FAT_ERR` | 0x400000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PORT1_PCIE_NFAT_ERR` | 0x200000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PORT2_PCIE_COR_ERR` | 0x800000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PORT2_PCIE_FAT_ERR` | 0x2000000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_PORT2_PCIE_NFAT_ERR` | 0x1000000000000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_MBE` | 0x20 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_PROTOCOL_ERROR` | 0x8 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_REQ_ADDR_ERR` | 0x1000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_REQ_BAD_BE` | 0x2000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_REQ_HEADER` | 0x2 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_REQ_LONG` | 0x100 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_REQ_OFLOW` | 0x200 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_REQ_SHORT` | 0x400 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_REQ_SIDEBAND` | 0x800 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_RSP_HEADER` | 0x4 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_RSP_INVALID` | 0x80000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_RSP_LONG` | 0x100000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_RSP_SHORT` | 0x200000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_RSP_SIDEBAND` | 0x400000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_SSP_SBE` | 0x10 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_URE_ATE3240_PAGE_FAULT` | 0x4000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_URE_ATE40_PAGE_FAULT` | 0x8000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_URE_CREDIT_OFLOW` | 0x10000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_URE_SRAM_PE` | 0x20000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_URE_SSP_RD_REQ_TIMEOUT` | 0x2000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_URE_SSP_RSP_UNEXP` | 0x800000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_ERR_URE_SSP_WR_REQ_TIMEOUT` | 0x1000000 | established |  | Header comment: ce_adm_error_mask and ce_adm_error_summary register bit masks |
| `ADM_FORCE_INT_ALWAYS_SHFT` | 0x8 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT1_DEV_A_SHFT` | 0x0 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT1_DEV_B_SHFT` | 0x1 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT1_DEV_C_SHFT` | 0x2 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT1_DEV_D_SHFT` | 0x3 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT2_DEV_A_SHFT` | 0x4 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT2_DEV_B_SHFT` | 0x5 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT2_DEV_C_SHFT` | 0x6 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_FORCE_INT_PCIE_PORT2_DEV_D_SHFT` | 0x7 | established |  | Header comment: ce_adm_force_int register bit defines |
| `ADM_INT_CE_ERROR_SHFT` | 0x0 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_LSI1_IP_ERROR_SHFT` | 0x1 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_LSI2_IP_ERROR_SHFT` | 0x2 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_ERROR_SHFT` | 0x3 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_MSG_SHFT` | 0xe | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_MSG_SLOT_0_SHFT` | 0xe | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_MSG_SLOT_1_SHFT` | 0xf | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_MSG_SLOT_2_SHFT` | 0x10 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_MSG_SLOT_3_SHFT` | 0x11 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT1_DEV_A_SHFT` | 0x6 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT1_DEV_B_SHFT` | 0x7 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT1_DEV_C_SHFT` | 0x8 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT1_DEV_D_SHFT` | 0x9 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT2_DEV_A_SHFT` | 0xa | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT2_DEV_B_SHFT` | 0xb | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT2_DEV_C_SHFT` | 0xc | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PCIE_PORT2_DEV_D_SHFT` | 0xd | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PORT1_HOTPLUG_EVENT_SHFT` | 0x4 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PORT1_PM_PME_MSG_SHFT` | 0x16 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PORT2_HOTPLUG_EVENT_SHFT` | 0x5 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `ADM_INT_PORT2_PM_PME_MSG_SHFT` | 0x17 | established |  | Header comment: ce_adm_int_mask/ce_adm_int_status register bit defines |
| `BUS_SRC_ID_SHFT` | 0x8 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `DEV_SRC_ID_SHFT` | 0x3 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `DRE_ADDR_MODE_SHFT` | 0x4 | established |  | Header comment: ce_dre_config1 register bit masks and shifts |
| `DRE_CONFIG_COMPLETION_VALID` | 0x10 | established |  | Header comment: ce_dre_config_req_status register bit masks |
| `DRE_CONFIG_REQUEST_ACTIVE` | 0x20 | established |  | Header comment: ce_dre_config_req_status register bit masks |
| `DRE_DOWNSTREAM_CONFIG_ERROR` | 0x8 | established |  | Header comment: ce_dre_config_req_status register bit masks |
| `DRE_DYN_RO_ENABLE` | 0x2 | established |  | Header comment: ce_dre_config1 register bit masks and shifts |
| `DRE_LAST_CONFIG_COMPLETION` | 0x7 | established |  | Header comment: ce_dre_config_req_status register bit masks |
| `DRE_RO_ENABLE` | 0x1 | established |  | Header comment: ce_dre_config1 register bit masks and shifts |
| `DRE_SUP_CONFIG_COMP_ERROR` | 0x4 | established |  | Header comment: ce_dre_config1 register bit masks and shifts |
| `DRE_SUP_IO_COMP_ERROR` | 0x8 | established |  | Header comment: ce_dre_config1 register bit masks and shifts |
| `E_CONFIG_BUS_SHFT` | 0x14 | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks |
| `E_CONFIG_DEVICE_SHFT` | 0xf | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks |
| `E_CONFIG_FUNC_SHFT` | 0xc | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks |
| `FNC_SRC_ID_SHFT` | 0x0 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `HOST_BRIDGE_DEVICE_ID` | 0x4001 | established |  | Header comment: CE Host Bridge Vendor/Device IDs |
| `HOST_BRIDGE_VENDOR_ID` | 0x10a9 | established |  | Header comment: CE Host Bridge Vendor/Device IDs |
| `INTR_VECTOR_SHFT` | 0x38 | established |  | Header comment: ce_adm_int_dest register bit masks & shifts |
| `LSI_GB_CFG1_LPBK_EN_MASK` | 0x40000 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_LPBK_EN_SHFT` | 0x12 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_LPBK_SEL_MASK` | 0x30000 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_LPBK_SEL_SHFT` | 0x10 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RVRS_CLK_MASK` | 0x300000 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RVRS_CLK_SHFT` | 0x14 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RVRS_LB_MASK` | 0x80000 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RVRS_LB_SHFT` | 0x13 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_ADJ_MASK` | 0x7000 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_ADJ_SHFT` | 0xc | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_FLT_MASK` | 0x8000 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_FLT_SHFT` | 0xf | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_SMP_MASK` | 0xf00 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_SMP_SHFT` | 0x8 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_THS_MASK` | 0xff | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_RXL0S_THS_SHFT` | 0x0 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_SLF_TS_MASK` | 0xf000000 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `LSI_GB_CFG1_SLF_TS_SHFT` | 0x18 | established |  | Header comment: ce_lsiX_gb_cfg1 register bit masks & shifts |
| `NUM_M3240_ATES` | 0x800 | established |  | Array extent of a register array in the header struct; the header has no comment here |
| `NUM_M40_ATES` | 0x1000 | established |  | Array extent of a register array in the header struct; the header has no comment here |
| `NUM_PORTS` | 0x2 | established |  | Array extent of a register array in the header struct; the header has no comment here |
| `PART_NUM` | 0xce00 | established |  | Header comment: CE ASIC part & mfgr information |
| `PIO_CONFIG_SPACE` | 0x4000000 | established |  | Header comment: PCI Compatible Config Space |
| `PIO_CONFIG_SPACE_LEN` | 0x4000000 | established |  | Header comment: PCI Compatible Config Space |
| `PIO_E_CONFIG_SPACE` | 0x10000000 | established |  | Header comment: PCI Enhanced Config Space |
| `PIO_E_CONFIG_SPACE_LEN` | 0x10000000 | established |  | Header comment: PCI Enhanced Config Space |
| `PIO_IO_SPACE` | 0x100000000 | established |  | Header comment: PCI I/O Space |
| `PIO_IO_SPACE_ALIAS` | 0x8000000 | established |  | Header comment: PCI I/O Space Alias |
| `PIO_IO_SPACE_ALIAS_LEN` | 0x8000000 | established |  | Header comment: PCI I/O Space Alias |
| `PIO_IO_SPACE_LEN` | 0x100000000 | established |  | Header comment: PCI I/O Space |
| `PIO_MEM_SPACE` | 0x200000000 | established |  | Header comment: PCI MEM Space |
| `PIO_MMR` | 0x0 | established |  | Header comment: Local CE Registers Space |
| `PIO_MMR_LEN` | 0x4000000 | established |  | Header comment: Local CE Registers Space |
| `PKT_TRAFIC_SHRT` | 0x10 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `REV_A` | 0x1 | established |  | Header comment: CE ASIC part & mfgr information |
| `SRC_ID` | 0x1 | established |  | Header comment: CE ASIC part & mfgr information |
| `URE_ABP` | 0x1 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_AIP` | 0x8 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_ATE3240_ENABLE` | 0x1 | established |  | Header comment: ce_ure_page_map register bit masks & shifts |
| `URE_ATE40_ENABLE` | 0x2 | established |  | Header comment: ce_ure_page_map register bit masks & shifts |
| `URE_ATE_PAR_DISABLE` | 0x1000000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_DNS_DAT_PAR_DISABLE` | 0x8000000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_DNS_HDR_PAR_DISABLE` | 0x10000000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_ELAL1_SHFT` | 0x8 | established |  | Header comment: ce_ure_pcie_control1 register bit masks & shifts |
| `URE_ELAL_SHFT` | 0x4 | established |  | Header comment: ce_ure_pcie_control1 register bit masks & shifts |
| `URE_HPC` | 0x40 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_HPS` | 0x20 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_MALFORM_DISABLE` | 0x100000000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_MASK1_SHFT` | 0x0 | established |  | Header comment: ce_ure_pipe_mask register bit masks & shifts |
| `URE_MASK2_SHFT` | 0x14 | established |  | Header comment: ce_ure_pipe_mask register bit masks & shifts |
| `URE_MASK3_SHFT` | 0x28 | established |  | Header comment: ce_ure_pipe_mask register bit masks & shifts |
| `URE_MSP` | 0x4 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_PAGESIZE_SHFT` | 0x4 | established |  | Header comment: ce_ure_page_map register bit masks & shifts |
| `URE_PCP` | 0x2 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_PIP` | 0x10 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_PN1_SHFT` | 0x10 | established |  | Header comment: ce_ure_pcie_control1 register bit masks & shifts |
| `URE_PN2_SHFT` | 0x18 | established |  | Header comment: ce_ure_pcie_control1 register bit masks & shifts |
| `URE_PSN1_SHFT` | 0x13 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_PSN2_SHFT` | 0x20 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_RCI_PAR_DISABLE` | 0x2000000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_RD_MRG_ENABLE` | 0x1 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_RSPQ_BYPASS_DISABLE` | 0x1000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_RSPQ_PAR_DISABLE` | 0x4000000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_SCC` | 0x1000 | established |  | Header comment: ce_ure_pcie_control1 register bit masks & shifts |
| `URE_SEL1_SHFT` | 0x0 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `URE_SEL2_SHFT` | 0x14 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `URE_SEL3_SHFT` | 0x28 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `URE_SI` | 0x1 | established |  | Header comment: ce_ure_pcie_control1 register bit masks & shifts |
| `URE_SPLS_SHFT` | 0xf | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_SPLV_SHFT` | 0x7 | established |  | Header comment: ce_ure_pcie_control2 register bit masks & shifts |
| `URE_UNSUP_DISABLE` | 0x200000000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_UPS_DAT1_PAR_DISABLE` | 0x100000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_UPS_DAT2_PAR_DISABLE` | 0x400000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_UPS_HDR1_PAR_DISABLE` | 0x200000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_UPS_HDR2_PAR_DISABLE` | 0x800000000 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_WRT_MRG_ENABLE1` | 0x10 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_WRT_MRG_ENABLE2` | 0x20 | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `URE_WRT_MRG_TIMER_SHFT` | 0xc | established |  | Header comment: ce_ure_control register bit masks & shifts |
| `VIRT_PPB_DEVICE_ID` | 0x4002 | established |  | Header comment: CE Virtual PPB Vendor/Device IDs |
| `VIRT_PPB_VENDOR_ID` | 0x10a9 | established |  | Header comment: CE Virtual PPB Vendor/Device IDs |
