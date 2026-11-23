<!-- generated from devices/tioce/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 52905da533c0fdd4266ab81f4644ea275734bd46daf5436fb5dcce504d25b373 -->

# TIOCE (TIO PCI Express bridge), as SGI's Linux Altix platform code defines it

Names and offsets are the definitions of SGI's Linux Altix platform code (header and provider, v5.3). The TIOCE's own register specification is not held. The header gives no access direction and no reset value for any register; rows say what the provider does where it touches one. Bit layouts the header defines are fields of their registers. Where the header names a register with its masks (interrupt status and mask, error summary and mask, force interrupt, the upstream engine control, page map, pipe select and mask, PCIe control, gearbox configuration, downstream engine configuration) the fields are established; the same layout on a sibling register (an alias, say) is inferred and said so on the register. Constants keep the plain values (identifiers, address windows, enhanced configuration masks).

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

Interrupt status. Bit n is the interrupt source named by the header (error, link 1 and 2 errors, PCIe error, hot-plug events per port, INTA to INTD of each port, message slots 0 to 3, power-management events). The provider reads it on revision A before forcing an interrupt. Name and offset are the vendor header's definition (struct member ce_adm_int_status). The header gives no access direction or reset value; access rw is a placeholder. Field layout: the header defines the bit position of every source. Bit 14 is also named as the first message slot. Bits 18 to 21 and above 23 have no definition.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23 | `port2_pm_pme_msg` | established |  |  |  |
| 22 | `port1_pm_pme_msg` | established |  |  |  |
| 17 | `pcie_msg_slot_3` | established |  |  |  |
| 16 | `pcie_msg_slot_2` | established |  |  |  |
| 15 | `pcie_msg_slot_1` | established |  |  |  |
| 14 | `pcie_msg_slot_0` | established |  |  |  |
| 13 | `port2_intd` | established |  |  |  |
| 12 | `port2_intc` | established |  |  |  |
| 11 | `port2_intb` | established |  |  |  |
| 10 | `port2_inta` | established |  |  |  |
| 9 | `port1_intd` | established |  |  |  |
| 8 | `port1_intc` | established |  |  |  |
| 7 | `port1_intb` | established |  |  |  |
| 6 | `port1_inta` | established |  |  |  |
| 5 | `port2_hotplug_event` | established |  |  |  |
| 4 | `port1_hotplug_event` | established |  |  |  |
| 3 | `pcie_error` | established |  |  |  |
| 2 | `lsi2_ip_error` | established |  |  |  |
| 1 | `lsi1_ip_error` | established |  |  |  |
| 0 | `ce_error` | established |  |  |  |

### Register `adm_int_status_alias`

Interrupt status alias. The provider sets every bit through it at attach to clear transients (the alias is the write path to clear; role from that use). Name and offset are the vendor header's definition (struct member ce_adm_int_status_alias). The header gives no access direction or reset value; access rw is a placeholder. Field layout is inferred: the header gives positions only for the status and mask registers. The provider writes all ones here at attach, after a load and OR, to clear stale interrupts, which reads as a write-to-clear alias of the status word (inferred from the provider comment, not stated by the header).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23 | `port2_pm_pme_msg` | inferred |  |  |  |
| 22 | `port1_pm_pme_msg` | inferred |  |  |  |
| 17 | `pcie_msg_slot_3` | inferred |  |  |  |
| 16 | `pcie_msg_slot_2` | inferred |  |  |  |
| 15 | `pcie_msg_slot_1` | inferred |  |  |  |
| 14 | `pcie_msg_slot_0` | inferred |  |  |  |
| 13 | `port2_intd` | inferred |  |  |  |
| 12 | `port2_intc` | inferred |  |  |  |
| 11 | `port2_intb` | inferred |  |  |  |
| 10 | `port2_inta` | inferred |  |  |  |
| 9 | `port1_intd` | inferred |  |  |  |
| 8 | `port1_intc` | inferred |  |  |  |
| 7 | `port1_intb` | inferred |  |  |  |
| 6 | `port1_inta` | inferred |  |  |  |
| 5 | `port2_hotplug_event` | inferred |  |  |  |
| 4 | `port1_hotplug_event` | inferred |  |  |  |
| 3 | `pcie_error` | inferred |  |  |  |
| 2 | `lsi2_ip_error` | inferred |  |  |  |
| 1 | `lsi1_ip_error` | inferred |  |  |  |
| 0 | `ce_error` | inferred |  |  |  |

### Register `adm_int_mask`

Interrupt mask. The provider sets a source bit, writes its destination, then clears the bit, so a set bit blocks the source while the destination is rewritten. Name and offset are the vendor header's definition (struct member ce_adm_int_mask). The header gives no access direction or reset value; access rw is a placeholder. Field layout: the header defines these positions for the mask and the status register alike. The provider sets a bit before retargeting a source and clears it afterwards.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23 | `port2_pm_pme_msg` | established |  |  |  |
| 22 | `port1_pm_pme_msg` | established |  |  |  |
| 17 | `pcie_msg_slot_3` | established |  |  |  |
| 16 | `pcie_msg_slot_2` | established |  |  |  |
| 15 | `pcie_msg_slot_1` | established |  |  |  |
| 14 | `pcie_msg_slot_0` | established |  |  |  |
| 13 | `port2_intd` | established |  |  |  |
| 12 | `port2_intc` | established |  |  |  |
| 11 | `port2_intb` | established |  |  |  |
| 10 | `port2_inta` | established |  |  |  |
| 9 | `port1_intd` | established |  |  |  |
| 8 | `port1_intc` | established |  |  |  |
| 7 | `port1_intb` | established |  |  |  |
| 6 | `port1_inta` | established |  |  |  |
| 5 | `port2_hotplug_event` | established |  |  |  |
| 4 | `port1_hotplug_event` | established |  |  |  |
| 3 | `pcie_error` | established |  |  |  |
| 2 | `lsi2_ip_error` | established |  |  |  |
| 1 | `lsi1_ip_error` | established |  |  |  |
| 0 | `ce_error` | established |  |  |  |

### Register `adm_int_pending`

Name and offset are the vendor header's definition (struct member ce_adm_int_pending). The header gives no access direction or reset value; access rw is a placeholder.

### Register `adm_force_int`

Force interrupt. Bits 0 to 7 force INTA to INTD of port 1 then port 2; bit 8 forces always. The bit numbering differs from the status register, and the provider maps explicitly. Revision A does not use it (workaround). Name and offset are the vendor header's definition (struct member ce_adm_force_int). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header: bits 0 to 7 are the four interrupt pins of each port, bit 8 forces unconditionally. These positions differ from the status register, and the provider maps between them explicitly.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `always` | established |  |  |  |
| 7 | `port2_intd` | established |  |  |  |
| 6 | `port2_intc` | established |  |  |  |
| 5 | `port2_intb` | established |  |  |  |
| 4 | `port2_inta` | established |  |  |  |
| 3 | `port1_intd` | established |  |  |  |
| 2 | `port1_intc` | established |  |  |  |
| 1 | `port1_intb` | established |  |  |  |
| 0 | `port1_inta` | established |  |  |  |

### Register `adm_ure_ups_buf_barrier_flush`

Name and offset are the vendor header's definition (struct member ce_adm_ure_ups_buf_barrier_flush). The header gives no access direction or reset value; access rw is a placeholder. Field layout: the header gives only the shift of each of eight selectors (one per pipe of each port), spaced four bits apart. The four-bit width is inferred from the spacing. The provider never touches it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `port2_pipe3` | inferred |  |  |  |
| 27:24 | `port2_pipe2` | inferred |  |  |  |
| 23:20 | `port2_pipe1` | inferred |  |  |  |
| 19:16 | `port2_pipe0` | inferred |  |  |  |
| 15:12 | `port1_pipe3` | inferred |  |  |  |
| 11:8 | `port1_pipe2` | inferred |  |  |  |
| 7:4 | `port1_pipe1` | inferred |  |  |  |
| 3:0 | `port1_pipe0` | inferred |  |  |  |

### Register `adm_int_dest`

Interrupt destination, one per source (the header declares fifteen). The provider writes the kernel vector in bits 63:56 (shift INTR_VECTOR_SHFT) ORed with the destination coretalk address of the target CPU, indexed by interrupt source bit. Name and offset are the vendor header's definition (struct member ce_adm_int_dest). The header gives no access direction or reset value; access rw is a placeholder. The vector field is inferred: the header gives only the shift 56 and the provider ORs the vector over the destination address; bit 63 as the top is the end of the word, not a header fact. The extent of the address part is unknown.

Array of 15 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `vector` | inferred |  |  |  |

### Register `adm_error_summary`

Name and offset are the vendor header's definition (struct member ce_adm_error_summary). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header: one bit per error source, bits 0 to 61.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61 | `port2_pcie_fat_err` | established |  |  |  |
| 60 | `port2_pcie_nfat_err` | established |  |  |  |
| 59 | `port2_pcie_cor_err` | established |  |  |  |
| 58 | `port1_pcie_fat_err` | established |  |  |  |
| 57 | `port1_pcie_nfat_err` | established |  |  |  |
| 56 | `port1_pcie_cor_err` | established |  |  |  |
| 55 | `dtl2_posted_d_cred_max_err` | established |  |  |  |
| 54 | `dtl2_posted_hd_cred_max_err` | established |  |  |  |
| 53 | `dtl2_nposted_d_cred_max_err` | established |  |  |  |
| 52 | `dtl2_nposted_hd_cred_max_err` | established |  |  |  |
| 51 | `dtl2_comp_d_cred_max_err` | established |  |  |  |
| 50 | `dtl2_comp_hd_cred_max_err` | established |  |  |  |
| 49 | `dtl2_inf_nposted_cred_updt_err` | established |  |  |  |
| 48 | `dtl2_inf_posted_cred_updt_err` | established |  |  |  |
| 47 | `dtl2_inf_compl_cred_updt_err` | established |  |  |  |
| 46 | `dtl2_min_pdata_credit_err` | established |  |  |  |
| 45 | `dtl1_posted_d_cred_max_err` | established |  |  |  |
| 44 | `dtl1_posted_hd_cred_max_err` | established |  |  |  |
| 43 | `dtl1_nposted_d_cred_max_err` | established |  |  |  |
| 42 | `dtl1_nposted_hd_cred_max_err` | established |  |  |  |
| 41 | `dtl1_comp_d_cred_max_err` | established |  |  |  |
| 40 | `dtl1_comp_hd_cred_max_err` | established |  |  |  |
| 39 | `dtl1_inf_nposted_cred_updt_err` | established |  |  |  |
| 38 | `dtl1_inf_posted_cred_updt_err` | established |  |  |  |
| 37 | `dtl1_inf_compl_cred_updt_err` | established |  |  |  |
| 36 | `dtl1_min_pdata_credit_err` | established |  |  |  |
| 35 | `adm_sram_pe` | established |  |  |  |
| 34 | `adm_credit_oflow` | established |  |  |  |
| 33 | `mmr_addr_error` | established |  |  |  |
| 32 | `mmr_access_error` | established |  |  |  |
| 31 | `adm_ssp_req_timeout` | established |  |  |  |
| 30 | `adm_ssp_rsp_unexp` | established |  |  |  |
| 29 | `ure_sram_pe` | established |  |  |  |
| 28 | `ure_credit_oflow` | established |  |  |  |
| 27 | `ure_ate40_page_fault` | established |  |  |  |
| 26 | `ure_ate3240_page_fault` | established |  |  |  |
| 25 | `ure_ssp_rd_req_timeout` | established |  |  |  |
| 24 | `ure_ssp_wr_req_timeout` | established |  |  |  |
| 23 | `ure_ssp_rsp_unexp` | established |  |  |  |
| 22 | `ssp_rsp_sideband` | established |  |  |  |
| 21 | `ssp_rsp_short` | established |  |  |  |
| 20 | `ssp_rsp_long` | established |  |  |  |
| 19 | `ssp_rsp_invalid` | established |  |  |  |
| 18 | `dre_sram_pe` | established |  |  |  |
| 17 | `dre_credit_oflow` | established |  |  |  |
| 16 | `pcie_err_compl` | established |  |  |  |
| 15 | `pcie_unexp_compl` | established |  |  |  |
| 14 | `pcie_compl_timeout` | established |  |  |  |
| 13 | `ssp_req_bad_be` | established |  |  |  |
| 12 | `ssp_req_addr_err` | established |  |  |  |
| 11 | `ssp_req_sideband` | established |  |  |  |
| 10 | `ssp_req_short` | established |  |  |  |
| 9 | `ssp_req_oflow` | established |  |  |  |
| 8 | `ssp_req_long` | established |  |  |  |
| 7 | `dre_ssp_req_inval` | established |  |  |  |
| 6 | `cxm_credit_oflow` | established |  |  |  |
| 5 | `ssp_mbe` | established |  |  |  |
| 4 | `ssp_sbe` | established |  |  |  |
| 3 | `ssp_protocol_error` | established |  |  |  |
| 2 | `ssp_rsp_header` | established |  |  |  |
| 1 | `ssp_req_header` | established |  |  |  |
| 0 | `crm_ssp_req_invalid` | established |  |  |  |

### Register `adm_error_summary_alias`

Error summary alias. The provider sets every bit through it at attach to clear transient errors. Name and offset are the vendor header's definition (struct member ce_adm_error_summary_alias). The header gives no access direction or reset value; access rw is a placeholder. Field layout is inferred: the header assigns bits to the summary and mask registers only. The provider writes all ones here at attach with the same clear-transient-errors intent as the status alias; the one-bit-per-source layout is carried over from the summary by that role, not stated.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61 | `port2_pcie_fat_err` | inferred |  |  |  |
| 60 | `port2_pcie_nfat_err` | inferred |  |  |  |
| 59 | `port2_pcie_cor_err` | inferred |  |  |  |
| 58 | `port1_pcie_fat_err` | inferred |  |  |  |
| 57 | `port1_pcie_nfat_err` | inferred |  |  |  |
| 56 | `port1_pcie_cor_err` | inferred |  |  |  |
| 55 | `dtl2_posted_d_cred_max_err` | inferred |  |  |  |
| 54 | `dtl2_posted_hd_cred_max_err` | inferred |  |  |  |
| 53 | `dtl2_nposted_d_cred_max_err` | inferred |  |  |  |
| 52 | `dtl2_nposted_hd_cred_max_err` | inferred |  |  |  |
| 51 | `dtl2_comp_d_cred_max_err` | inferred |  |  |  |
| 50 | `dtl2_comp_hd_cred_max_err` | inferred |  |  |  |
| 49 | `dtl2_inf_nposted_cred_updt_err` | inferred |  |  |  |
| 48 | `dtl2_inf_posted_cred_updt_err` | inferred |  |  |  |
| 47 | `dtl2_inf_compl_cred_updt_err` | inferred |  |  |  |
| 46 | `dtl2_min_pdata_credit_err` | inferred |  |  |  |
| 45 | `dtl1_posted_d_cred_max_err` | inferred |  |  |  |
| 44 | `dtl1_posted_hd_cred_max_err` | inferred |  |  |  |
| 43 | `dtl1_nposted_d_cred_max_err` | inferred |  |  |  |
| 42 | `dtl1_nposted_hd_cred_max_err` | inferred |  |  |  |
| 41 | `dtl1_comp_d_cred_max_err` | inferred |  |  |  |
| 40 | `dtl1_comp_hd_cred_max_err` | inferred |  |  |  |
| 39 | `dtl1_inf_nposted_cred_updt_err` | inferred |  |  |  |
| 38 | `dtl1_inf_posted_cred_updt_err` | inferred |  |  |  |
| 37 | `dtl1_inf_compl_cred_updt_err` | inferred |  |  |  |
| 36 | `dtl1_min_pdata_credit_err` | inferred |  |  |  |
| 35 | `adm_sram_pe` | inferred |  |  |  |
| 34 | `adm_credit_oflow` | inferred |  |  |  |
| 33 | `mmr_addr_error` | inferred |  |  |  |
| 32 | `mmr_access_error` | inferred |  |  |  |
| 31 | `adm_ssp_req_timeout` | inferred |  |  |  |
| 30 | `adm_ssp_rsp_unexp` | inferred |  |  |  |
| 29 | `ure_sram_pe` | inferred |  |  |  |
| 28 | `ure_credit_oflow` | inferred |  |  |  |
| 27 | `ure_ate40_page_fault` | inferred |  |  |  |
| 26 | `ure_ate3240_page_fault` | inferred |  |  |  |
| 25 | `ure_ssp_rd_req_timeout` | inferred |  |  |  |
| 24 | `ure_ssp_wr_req_timeout` | inferred |  |  |  |
| 23 | `ure_ssp_rsp_unexp` | inferred |  |  |  |
| 22 | `ssp_rsp_sideband` | inferred |  |  |  |
| 21 | `ssp_rsp_short` | inferred |  |  |  |
| 20 | `ssp_rsp_long` | inferred |  |  |  |
| 19 | `ssp_rsp_invalid` | inferred |  |  |  |
| 18 | `dre_sram_pe` | inferred |  |  |  |
| 17 | `dre_credit_oflow` | inferred |  |  |  |
| 16 | `pcie_err_compl` | inferred |  |  |  |
| 15 | `pcie_unexp_compl` | inferred |  |  |  |
| 14 | `pcie_compl_timeout` | inferred |  |  |  |
| 13 | `ssp_req_bad_be` | inferred |  |  |  |
| 12 | `ssp_req_addr_err` | inferred |  |  |  |
| 11 | `ssp_req_sideband` | inferred |  |  |  |
| 10 | `ssp_req_short` | inferred |  |  |  |
| 9 | `ssp_req_oflow` | inferred |  |  |  |
| 8 | `ssp_req_long` | inferred |  |  |  |
| 7 | `dre_ssp_req_inval` | inferred |  |  |  |
| 6 | `cxm_credit_oflow` | inferred |  |  |  |
| 5 | `ssp_mbe` | inferred |  |  |  |
| 4 | `ssp_sbe` | inferred |  |  |  |
| 3 | `ssp_protocol_error` | inferred |  |  |  |
| 2 | `ssp_rsp_header` | inferred |  |  |  |
| 1 | `ssp_req_header` | inferred |  |  |  |
| 0 | `crm_ssp_req_invalid` | inferred |  |  |  |

### Register `adm_error_mask`

Name and offset are the vendor header's definition (struct member ce_adm_error_mask). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header: same bit assignment as the summary register. The header does not say whether a set bit enables or masks the source (unknown).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61 | `port2_pcie_fat_err` | established |  |  |  |
| 60 | `port2_pcie_nfat_err` | established |  |  |  |
| 59 | `port2_pcie_cor_err` | established |  |  |  |
| 58 | `port1_pcie_fat_err` | established |  |  |  |
| 57 | `port1_pcie_nfat_err` | established |  |  |  |
| 56 | `port1_pcie_cor_err` | established |  |  |  |
| 55 | `dtl2_posted_d_cred_max_err` | established |  |  |  |
| 54 | `dtl2_posted_hd_cred_max_err` | established |  |  |  |
| 53 | `dtl2_nposted_d_cred_max_err` | established |  |  |  |
| 52 | `dtl2_nposted_hd_cred_max_err` | established |  |  |  |
| 51 | `dtl2_comp_d_cred_max_err` | established |  |  |  |
| 50 | `dtl2_comp_hd_cred_max_err` | established |  |  |  |
| 49 | `dtl2_inf_nposted_cred_updt_err` | established |  |  |  |
| 48 | `dtl2_inf_posted_cred_updt_err` | established |  |  |  |
| 47 | `dtl2_inf_compl_cred_updt_err` | established |  |  |  |
| 46 | `dtl2_min_pdata_credit_err` | established |  |  |  |
| 45 | `dtl1_posted_d_cred_max_err` | established |  |  |  |
| 44 | `dtl1_posted_hd_cred_max_err` | established |  |  |  |
| 43 | `dtl1_nposted_d_cred_max_err` | established |  |  |  |
| 42 | `dtl1_nposted_hd_cred_max_err` | established |  |  |  |
| 41 | `dtl1_comp_d_cred_max_err` | established |  |  |  |
| 40 | `dtl1_comp_hd_cred_max_err` | established |  |  |  |
| 39 | `dtl1_inf_nposted_cred_updt_err` | established |  |  |  |
| 38 | `dtl1_inf_posted_cred_updt_err` | established |  |  |  |
| 37 | `dtl1_inf_compl_cred_updt_err` | established |  |  |  |
| 36 | `dtl1_min_pdata_credit_err` | established |  |  |  |
| 35 | `adm_sram_pe` | established |  |  |  |
| 34 | `adm_credit_oflow` | established |  |  |  |
| 33 | `mmr_addr_error` | established |  |  |  |
| 32 | `mmr_access_error` | established |  |  |  |
| 31 | `adm_ssp_req_timeout` | established |  |  |  |
| 30 | `adm_ssp_rsp_unexp` | established |  |  |  |
| 29 | `ure_sram_pe` | established |  |  |  |
| 28 | `ure_credit_oflow` | established |  |  |  |
| 27 | `ure_ate40_page_fault` | established |  |  |  |
| 26 | `ure_ate3240_page_fault` | established |  |  |  |
| 25 | `ure_ssp_rd_req_timeout` | established |  |  |  |
| 24 | `ure_ssp_wr_req_timeout` | established |  |  |  |
| 23 | `ure_ssp_rsp_unexp` | established |  |  |  |
| 22 | `ssp_rsp_sideband` | established |  |  |  |
| 21 | `ssp_rsp_short` | established |  |  |  |
| 20 | `ssp_rsp_long` | established |  |  |  |
| 19 | `ssp_rsp_invalid` | established |  |  |  |
| 18 | `dre_sram_pe` | established |  |  |  |
| 17 | `dre_credit_oflow` | established |  |  |  |
| 16 | `pcie_err_compl` | established |  |  |  |
| 15 | `pcie_unexp_compl` | established |  |  |  |
| 14 | `pcie_compl_timeout` | established |  |  |  |
| 13 | `ssp_req_bad_be` | established |  |  |  |
| 12 | `ssp_req_addr_err` | established |  |  |  |
| 11 | `ssp_req_sideband` | established |  |  |  |
| 10 | `ssp_req_short` | established |  |  |  |
| 9 | `ssp_req_oflow` | established |  |  |  |
| 8 | `ssp_req_long` | established |  |  |  |
| 7 | `dre_ssp_req_inval` | established |  |  |  |
| 6 | `cxm_credit_oflow` | established |  |  |  |
| 5 | `ssp_mbe` | established |  |  |  |
| 4 | `ssp_sbe` | established |  |  |  |
| 3 | `ssp_protocol_error` | established |  |  |  |
| 2 | `ssp_rsp_header` | established |  |  |  |
| 1 | `ssp_req_header` | established |  |  |  |
| 0 | `crm_ssp_req_invalid` | established |  |  |  |

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

Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg1). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header masks (gearbox configuration). Meanings of the fields are unknown beyond their names.

Array of 2 registers, stride 4096.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27:24 | `slf_ts` | established |  |  |  |
| 21:20 | `rvrs_clk` | established |  |  |  |
| 19 | `rvrs_lb` | established |  |  |  |
| 18 | `lpbk_en` | established |  |  |  |
| 17:16 | `lpbk_sel` | established |  |  |  |
| 15 | `rxl0s_flt` | established |  |  |  |
| 14:12 | `rxl0s_adj` | established |  |  |  |
| 11:8 | `rxl0s_smp` | established |  |  |  |
| 7:0 | `rxl0s_ths` | established |  |  |  |

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

Name and offset are the vendor header's definition (struct member ce_ure_control). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header: write-merge timer is the eleven-bit mask at bit 12; the rest are single bits. The parity-disable and malform-disable bits are the header names; their effects are not described.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45 | `unsup_disable` | established |  |  |  |
| 44 | `malform_disable` | established |  |  |  |
| 40 | `dns_hdr_par_disable` | established |  |  |  |
| 39 | `dns_dat_par_disable` | established |  |  |  |
| 38 | `rspq_par_disable` | established |  |  |  |
| 37 | `rci_par_disable` | established |  |  |  |
| 36 | `ate_par_disable` | established |  |  |  |
| 35 | `ups_hdr2_par_disable` | established |  |  |  |
| 34 | `ups_dat2_par_disable` | established |  |  |  |
| 33 | `ups_hdr1_par_disable` | established |  |  |  |
| 32 | `ups_dat1_par_disable` | established |  |  |  |
| 24 | `rspq_bypass_disable` | established |  |  |  |
| 22:12 | `wrt_mrg_timer` | established |  |  |  |
| 5 | `wrt_mrg_enable2` | established |  |  |  |
| 4 | `wrt_mrg_enable1` | established |  |  |  |
| 0 | `rd_mrg_enable` | established |  |  |  |

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

Upstream request engine page size map. The provider clears the page-size field and sets it to the 256 KiB encoding (4) at attach, the largest the code uses; the 32/40-bit entries are then 256 KiB pages. Name and offset are the vendor header's definition (struct member ce_ure_page_map). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header. The pagesize field holds the encodings the header names (0 to 4); 5 to 7 are unknown. The provider uses 4.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:4 | `pagesize` | established | ure_pagesize (4k=0, 16k=1, 64k=2, 128k=3, 256k=4) |  |  |
| 1 | `ate40_enable` | established |  |  |  |
| 0 | `ate3240_enable` | established |  |  |  |

### Register `ure_dir_map`

Upstream request engine direct map, one per port. For 32-bit direct DMA the provider stores the target's coretalk address with the low 30 bits cleared (a 1 GiB-aligned base), reads it back to flush, and refcounts users: a second user needs the same base. Name and offset are the vendor header's definition (struct member ce_ure_dir_map). The header gives no access direction or reset value; access rw is a placeholder.

Array of 2 registers, stride 8.

### Register `ure_pipe_sel1`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel1). The header gives no access direction or reset value; access rw is a placeholder. Three 19-bit selectors at bits 0, 20 and 40 (header selector masks). Within a selector the header defines traffic class, bus, device and function masks at bits 18:16, 15:8, 7:3 and 2:0; they sum to 19 bits. The layout is established for the first selector, whose position the macros give; for the second and third it is inferred from the identical selector width. Meaning of each selector (a source id match for a pipe) is inferred from the register name.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:56 | `sel3_tc` | inferred |  |  |  |
| 55:48 | `sel3_bus` | inferred |  |  |  |
| 47:43 | `sel3_dev` | inferred |  |  |  |
| 42:40 | `sel3_fnc` | inferred |  |  |  |
| 38:36 | `sel2_tc` | inferred |  |  |  |
| 35:28 | `sel2_bus` | inferred |  |  |  |
| 27:23 | `sel2_dev` | inferred |  |  |  |
| 22:20 | `sel2_fnc` | inferred |  |  |  |
| 18:16 | `sel1_tc` | established |  |  |  |
| 15:8 | `sel1_bus` | established |  |  |  |
| 7:3 | `sel1_dev` | established |  |  |  |
| 2:0 | `sel1_fnc` | established |  |  |  |

### Register `ure_pipe_mask1`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask1). The header gives no access direction or reset value; access rw is a placeholder. Three 19-bit mask fields at bits 0, 20 and 40 from the header masks. That each mask applies to the selector of the same index is inferred from naming.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:40 | `mask3` | inferred |  |  |  |
| 38:20 | `mask2` | inferred |  |  |  |
| 18:0 | `mask1` | inferred |  |  |  |

### Register `ure_pipe_sel2`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel2). The header gives no access direction or reset value; access rw is a placeholder. Same selector layout as the first pipe select register (see there); the header comment covers both under one name. Selector two and three sub-layout is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:56 | `sel3_tc` | inferred |  |  |  |
| 55:48 | `sel3_bus` | inferred |  |  |  |
| 47:43 | `sel3_dev` | inferred |  |  |  |
| 42:40 | `sel3_fnc` | inferred |  |  |  |
| 38:36 | `sel2_tc` | inferred |  |  |  |
| 35:28 | `sel2_bus` | inferred |  |  |  |
| 27:23 | `sel2_dev` | inferred |  |  |  |
| 22:20 | `sel2_fnc` | inferred |  |  |  |
| 18:16 | `sel1_tc` | established |  |  |  |
| 15:8 | `sel1_bus` | established |  |  |  |
| 7:3 | `sel1_dev` | established |  |  |  |
| 2:0 | `sel1_fnc` | established |  |  |  |

### Register `ure_pipe_mask2`

Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask2). The header gives no access direction or reset value; access rw is a placeholder. Same layout as the first pipe mask register; the header comment covers both.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:40 | `mask3` | inferred |  |  |  |
| 38:20 | `mask2` | inferred |  |  |  |
| 18:0 | `mask1` | inferred |  |  |  |

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

Name and offset are the vendor header's definition (struct member ce_ure_pcie_control1). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header masks. Names ELAL, PN and SI match the PCI Express capability fields of the same abbreviations (exit latency, port number, slot implemented); that reading is inferred from the names and unconfirmed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `pn2` | established |  |  |  |
| 23:16 | `pn1` | established |  |  |  |
| 12 | `scc` | established |  |  |  |
| 10:8 | `elal1` | established |  |  |  |
| 6:4 | `elal` | established |  |  |  |
| 0 | `si` | established |  |  |  |

### Register `ure_pcie_control2`

Name and offset are the vendor header's definition (struct member ce_ure_pcie_control2). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header masks. The names abp, pcp, msp, aip, pip, hps, hpc, splv, spls and psn match the slot capabilities fields of the public PCI Express specification (attention button, power controller, MRL sensor, attention and power indicators, hot-plug surprise and capable, slot power limit value and scale, physical slot number); that reading is inferred from the names. The provider never writes these.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 44:32 | `psn2` | established |  |  |  |
| 31:19 | `psn1` | established |  |  |  |
| 16:15 | `spls` | established |  |  |  |
| 14:7 | `splv` | established |  |  |  |
| 6 | `hpc` | established |  |  |  |
| 5 | `hps` | established |  |  |  |
| 4 | `pip` | established |  |  |  |
| 3 | `aip` | established |  |  |  |
| 2 | `msp` | established |  |  |  |
| 1 | `pcp` | established |  |  |  |
| 0 | `abp` | established |  |  |  |

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

Name and offset are the vendor header's definition (struct member ce_dre_config1). The header gives no access direction or reset value; access rw is a placeholder. Header-defined bits 0 to 3. The address mode field starts at bit 4 (constant DRE_ADDR_MODE_SHFT); its width and values are unknown, so it is not a field.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `sup_io_comp_error` | established |  |  |  |
| 2 | `sup_config_comp_error` | established |  |  |  |
| 1 | `dyn_ro_enable` | established |  |  |  |
| 0 | `ro_enable` | established |  |  |  |

### Register `dre_config2`

Name and offset are the vendor header's definition (struct member ce_dre_config2). The header gives no access direction or reset value; access rw is a placeholder.

### Register `dre_config_req_status`

Name and offset are the vendor header's definition (struct member ce_dre_config_req_status). The header gives no access direction or reset value; access rw is a placeholder. Field layout from the header masks.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `config_request_active` | established |  |  |  |
| 4 | `config_completion_valid` | established |  |  |  |
| 3 | `downstream_config_error` | established |  |  |  |
| 2:0 | `last_config_completion` | established |  |  |  |

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

## Enums

### Enum `ure_pagesize`

| Label | Value | Grade | Source |
|---|---|---|---|
| `4k` | 0 | established |  |
| `16k` | 1 | established |  |
| `64k` | 2 | established |  |
| `128k` | 3 | established |  |
| `256k` | 4 | established |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BUS_SRC_ID_SHFT` | 0x8 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `DEV_SRC_ID_SHFT` | 0x3 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `DRE_ADDR_MODE_SHFT` | 0x4 | established |  | Header comment: ce_dre_config1 register bit masks and shifts |
| `E_CONFIG_BUS_MASK` | 0xff00000 | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks. Bits of an enhanced configuration space offset that select the bus number. |
| `E_CONFIG_BUS_SHFT` | 0x14 | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks |
| `E_CONFIG_DEVICE_MASK` | 0xf8000 | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks. Bits of an enhanced configuration space offset that select the device number. |
| `E_CONFIG_DEVICE_SHFT` | 0xf | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks |
| `E_CONFIG_FUNC_MASK` | 0x7000 | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks. Bits of an enhanced configuration space offset that select the func number. |
| `E_CONFIG_FUNC_SHFT` | 0xc | established |  | Header comment: CE PCI Enhanced Config Space shifts & masks |
| `FNC_SRC_ID_SHFT` | 0x0 | established |  | Header comment: ce_ure_pipe_sel register bit masks & shifts |
| `HOST_BRIDGE_DEVICE_ID` | 0x4001 | established |  | Header comment: CE Host Bridge Vendor/Device IDs |
| `HOST_BRIDGE_VENDOR_ID` | 0x10a9 | established |  | Header comment: CE Host Bridge Vendor/Device IDs |
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
| `VIRT_PPB_DEVICE_ID` | 0x4002 | established |  | Header comment: CE Virtual PPB Vendor/Device IDs |
| `VIRT_PPB_VENDOR_ID` | 0x10a9 | established |  | Header comment: CE Virtual PPB Vendor/Device IDs |
