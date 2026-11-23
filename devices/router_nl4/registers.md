<!-- generated from devices/router_nl4/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 8b308a8b92038c2fa56d72eb843a6e1e2ec8301ecc496cafbe84909de51dcf9a -->

# NUMAlink 4 router (R4): global, local-block and per-port registers, as the SN2 PROM's error and dump tables name them

Register numbers, names and bit ranges come from the register description table that the SN2 PROM images carry for the NUMAlink 4 router (names with the prefix R4_, here without it). The table gives each register's number in the router's own register space, its name and its fields with bit positions and a small flags value. It states no reset values and no semantics, so every reset is unknown, roles are inferred from the names, and an access of r or rw is inferred from the flags (bit 1 set means writable, otherwise r; the flag-8 scratch aliases have neither bit and their r is a default). Width 64 is inferred: every number is a multiple of 8 and the SHub's own vector accesses are doublewords. The eight ports are lettered A to H in the PROM and indexed 0 to 7 here (the PROM's own port number is the index plus one). A per-port register is recorded at port A with count 8; the stride is the one the table shows (the port-block distance for registers inside the port blocks, 8 for the per-port registers kept in the global block). The prose is in devices/router_nl4/README.md.

Unit `router_nl4`, macro prefix `ROUTER_NL4`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `status_rev_id` | 0x0 | r | 64 |  |  | unknown | established |  |
| `global_parm0` | 0x10 | rw | 64 |  |  | unknown | established |  |
| `global_parm1` | 0x20 | rw | 64 |  |  | unknown | established |  |
| `asic_to_l1_status` | 0x30 | r | 64 |  |  | unknown | established |  |
| `asic_to_l1_data` | 0x38 | rw | 64 |  |  | unknown | established |  |
| `l1_to_asic_status` | 0x40 | rw | 64 |  |  | unknown | established |  |
| `l1_to_asic_data` | 0x48 | r | 64 |  |  | unknown | established |  |
| `scratch0` | 0x1000 | rw | 64 |  |  | unknown | established |  |
| `scratch0_alias` | 0x1008 | r | 64 |  |  | unknown | established |  |
| `scratch1` | 0x1010 | rw | 64 |  |  | unknown | established |  |
| `scratch1_alias` | 0x1018 | r | 64 |  |  | unknown | established |  |
| `scratch2` | 0x1020 | rw | 64 |  |  | unknown | established |  |
| `scratch2_alias` | 0x1028 | r | 64 |  |  | unknown | established |  |
| `scratch3` | 0x1030 | rw | 64 |  |  | unknown | established |  |
| `scratch3_alias` | 0x1038 | rw | 64 |  |  | unknown | established |  |
| `scratch4` | 0x1040 | rw | 64 |  |  | unknown | established |  |
| `scratch4_alias` | 0x1048 | rw | 64 |  |  | unknown | established |  |
| `scratch5` | 0x1050 | rw | 64 |  |  | unknown | established |  |
| `scratch5_alias` | 0x1058 | r | 64 |  |  | unknown | established |  |
| `scratch6` | 0x1060 | rw | 64 |  |  | unknown | established |  |
| `scratch6_alias` | 0x1068 | r | 64 |  |  | unknown | established |  |
| `scratch7` | 0x1070 | rw | 64 |  |  | unknown | established |  |
| `scratch7_alias` | 0x1078 | r | 64 |  |  | unknown | established |  |
| `scratch8` | 0x1080 | rw | 64 |  |  | unknown | established |  |
| `scratch8_alias` | 0x1088 | r | 64 |  |  | unknown | established |  |
| `scratch9` | 0x1090 | rw | 64 |  |  | unknown | established |  |
| `scratch9_alias` | 0x1098 | r | 64 |  |  | unknown | established |  |
| `asic_first_error` | 0x2000 | rw | 64 |  |  | unknown | established |  |
| `asic_first_error_timestamp` | 0x2008 | rw | 64 |  |  | unknown | established |  |
| `lb_error_summary` | 0x2010 | rw | 64 |  |  | unknown | established |  |
| `lb_first_error` | 0x2020 | rw | 64 |  |  | unknown | established |  |
| `lb_error_report_mask` | 0x2030 | rw | 64 |  |  | unknown | established |  |
| `lb_error_detail_1` | 0x2050 | rw | 64 |  |  | unknown | established |  |
| `lb_error_detail_2` | 0x2060 | rw | 64 |  |  | unknown | established |  |
| `lb0_test_point_select_512` | 0x2700 | rw | 64 |  |  | unknown | established |  |
| `lb_dateline` | 0x4000 | rw | 64 |  |  | unknown | established |  |
| `lb_preage` | 0x4010 | rw | 64 |  |  | unknown | established |  |
| `pio_time_out` | 0x4020 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_0` | 0x4e00 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_1` | 0x4e08 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_2` | 0x4e10 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_3` | 0x4e18 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_4` | 0x4e20 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_5` | 0x4e28 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_6` | 0x4e30 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_7` | 0x4e38 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_8` | 0x4e40 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_9` | 0x4e48 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_10` | 0x4e50 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_11` | 0x4e58 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_12` | 0x4e60 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_13` | 0x4e68 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_14` | 0x4e70 | rw | 64 |  |  | unknown | established |  |
| `mcast_trans_table_15` | 0x4e78 | rw | 64 |  |  | unknown | established |  |
| `mcast_dest_table` | 0x4e80 | rw | 64 |  |  | unknown | established |  |
| `mcast_rep_gather_buf` | 0x4f00 | rw | 64 |  |  | unknown | established |  |
| `mcast_gather_config` | 0x4f80 | rw | 64 |  |  | unknown | established |  |
| `mcast_dest_vec_0` | 0x4f90 | rw | 64 |  |  | unknown | established |  |
| `mcast_dest_vec_1` | 0x4f98 | rw | 64 |  |  | unknown | established |  |
| `mcast_dest_vec_2` | 0x4fa0 | rw | 64 |  |  | unknown | established |  |
| `mcast_dest_vec_3` | 0x4fa8 | rw | 64 |  |  | unknown | established |  |
| `lb_local_table` | 0x5000 | rw | 64 |  |  | unknown | established |  |
| `lb_global_table` | 0x6000 | rw | 64 |  |  | unknown | established |  |
| `rtc_source` | 0x1001900 | rw | 64 |  |  | unknown | established |  |
| `rtc_intrn_cntrl` | 0x1001908 | rw | 64 |  |  | unknown | established |  |
| `throttle_interval` | 0x1001910 | rw | 64 |  |  | unknown | established |  |
| `throttle_time` | 0x1001918 | rw | 64 |  |  | unknown | established |  |
| `throttle_status` | 0x1001920 | r | 64 |  |  | unknown | established |  |
| `throttle_skip` | 0x1001928 | rw | 64 |  |  | unknown | established |  |
| `debug_port_config` | 0x1001930 | rw | 64 |  |  | unknown | established |  |
| `vbit_emul` | 0x1001938 | rw | 64 |  |  | unknown | established |  |
| `lb1_test_point_select_512` | 0x1002700 | rw | 64 |  |  | unknown | established |  |
| `hard_reset` | 0x1003000 | rw | 64 |  |  | unknown | established |  |
| `soft_reset` | 0x1003008 | rw | 64 |  |  | unknown | established |  |
| `port_reset` | 0x1003010 | rw | 64 |  |  | unknown | established |  |
| `protection_config` | 0x1003018 | rw | 64 |  |  | unknown | established |  |
| `port_rst_mask` | 0x1003020 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_win` | 0x1003100 | rw | 64 |  |  | unknown | established |  |
| `tsf_arm_mask` | 0x1004000 | rw | 64 |  |  | unknown | established |  |
| `tsf_counter_presets` | 0x1004080 | rw | 64 |  |  | unknown | established |  |
| `tsf_decrement_ctl` | 0x1004100 | rw | 64 |  |  | unknown | established |  |
| `tsf_diag_msg_ctl` | 0x1004180 | rw | 64 |  |  | unknown | established |  |
| `tsf_disarm_mask` | 0x1004200 | rw | 64 |  |  | unknown | established |  |
| `tsf_enable_ctl` | 0x1004280 | rw | 64 |  |  | unknown | established |  |
| `tsf_software_arm` | 0x1004300 | rw | 64 |  |  | unknown | established |  |
| `tsf_software_disarm` | 0x1004380 | rw | 64 |  |  | unknown | established |  |
| `tsf_software_triggered` | 0x1004400 | rw | 64 |  |  | unknown | established |  |
| `tsf_trigger_mask` | 0x1004480 | rw | 64 |  |  | unknown | established |  |
| `tsf_armed_state` | 0x1005000 | rw | 64 |  |  | unknown | established |  |
| `tsf_counter_value` | 0x1005080 | rw | 64 |  |  | unknown | established |  |
| `tsf_triggered_state` | 0x1005100 | rw | 64 |  |  | unknown | established |  |
| `root_test_point_select` | 0x1006000 | rw | 64 |  |  | unknown | established |  |
| `root_test_point_compare` | 0x1006008 | rw | 64 |  |  | unknown | established |  |
| `root_test_point_trigger_select` | 0x1006010 | rw | 64 |  |  | unknown | established |  |
| `branch1_test_point_select` | 0x1006020 | rw | 64 |  |  | unknown | established |  |
| `branch1_test_point_compare` | 0x1006028 | rw | 64 |  |  | unknown | established |  |
| `branch1_test_point_trigger_select` | 0x1006030 | rw | 64 |  |  | unknown | established |  |
| `branch2_test_point_select` | 0x1006040 | rw | 64 |  |  | unknown | established |  |
| `branch2_test_point_compare` | 0x1006048 | rw | 64 |  |  | unknown | established |  |
| `branch2_test_point_trigger_select` | 0x1006050 | rw | 64 |  |  | unknown | established |  |
| `branch1_debug_data` | 0x1007100 | r | 64 |  |  | unknown | established |  |
| `branch2_debug_data` | 0x1007108 | r | 64 |  |  | unknown | established |  |
| `root_debug_data` | 0x1007110 | r | 64 |  |  | unknown | established |  |
| `stop_clk_control` | 0x1008000 | rw | 64 |  |  | unknown | established |  |
| `stop_clk_delay_phase` | 0x1008080 | rw | 64 |  |  | unknown | established |  |
| `performance_count0_control` | 0x1080000 | rw | 64 |  |  | unknown | established |  |
| `performance_count1_control` | 0x1090000 | rw | 64 |  |  | unknown | established |  |
| `performance_count2_control` | 0x10a0000 | rw | 64 |  |  | unknown | established |  |
| `performance_count3_control` | 0x10b0000 | rw | 64 |  |  | unknown | established |  |
| `performance_count4_control` | 0x10c0000 | rw | 64 |  |  | unknown | established |  |
| `performance_count5_control` | 0x10d0000 | rw | 64 |  |  | unknown | established |  |
| `performance_count6_control` | 0x10e0000 | rw | 64 |  |  | unknown | established |  |
| `performance_count7_control` | 0x10f0000 | rw | 64 |  |  | unknown | established |  |
| `profile_dn_control` | 0x1100000 | rw | 64 |  |  | unknown | established |  |
| `profile_peak_control` | 0x1100080 | rw | 64 |  |  | unknown | established |  |
| `profile_range` | 0x1100100 | rw | 64 |  |  | unknown | established |  |
| `profile_up_control` | 0x1100180 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_0` | 0x1100200 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_1` | 0x1100208 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_2` | 0x1100210 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_3` | 0x1100218 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_4` | 0x1100220 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_5` | 0x1100228 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_6` | 0x1100230 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_7` | 0x1100238 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_8` | 0x1100240 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_9` | 0x1100248 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_10` | 0x1100250 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_11` | 0x1100258 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_12` | 0x1100260 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_13` | 0x1100268 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_14` | 0x1100270 | rw | 64 |  |  | unknown | established |  |
| `perf_trig_pattern_15` | 0x1100278 | rw | 64 |  |  | unknown | established |  |
| `performance_counter0` | 0x1110000 | rw | 64 |  |  | unknown | established |  |
| `performance_counter1` | 0x1120000 | rw | 64 |  |  | unknown | established |  |
| `performance_counter2` | 0x1130000 | rw | 64 |  |  | unknown | established |  |
| `performance_counter3` | 0x1140000 | rw | 64 |  |  | unknown | established |  |
| `performance_counter4` | 0x1150000 | rw | 64 |  |  | unknown | established |  |
| `performance_counter5` | 0x1160000 | rw | 64 |  |  | unknown | established |  |
| `performance_counter6` | 0x1170000 | rw | 64 |  |  | unknown | established |  |
| `performance_counter7` | 0x1180000 | rw | 64 |  |  | unknown | established |  |
| `profile_counter` | 0x1190000 | rw | 64 |  |  | unknown | established |  |
| `profile_peak` | 0x1190080 | rw | 64 |  |  | unknown | established |  |
| `port_vc0_n_count_init` | 0x2000010 | rw | 64 | 8 |  | unknown | established |  |
| `port_vc1_n_count_init` | 0x2000018 | rw | 64 | 8 |  | unknown | established |  |
| `port_vc2_n_count_init` | 0x2000020 | rw | 64 | 8 |  | unknown | established |  |
| `port_vc3_n_count_init` | 0x2000028 | rw | 64 | 8 |  | unknown | established |  |
| `portlb_arbl_vc0_n_count_init` | 0x2000120 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbl_vc1_n_count_init` | 0x2000128 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbl_vc2_n_count_init` | 0x2000130 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbl_vc3_n_count_init` | 0x2000138 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbr_vc0_n_count_init` | 0x2000140 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbr_vc1_n_count_init` | 0x2000148 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbr_vc2_n_count_init` | 0x2000150 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbr_vc3_n_count_init` | 0x2000158 | rw | 64 |  |  | unknown | established |  |
| `porta_d_count_init` | 0x2000400 | rw | 64 |  |  | unknown | established |  |
| `portb_d_count_init` | 0x2000408 | rw | 64 |  |  | unknown | established |  |
| `portg_d_count_init` | 0x2000410 | rw | 64 |  |  | unknown | established |  |
| `porth_d_count_init` | 0x2000418 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbl_d_count_init` | 0x2000420 | rw | 64 |  |  | unknown | established |  |
| `portc_d_count_init` | 0x2000428 | rw | 64 |  |  | unknown | established |  |
| `portd_d_count_init` | 0x2000430 | rw | 64 |  |  | unknown | established |  |
| `porte_d_count_init` | 0x2000438 | rw | 64 |  |  | unknown | established |  |
| `portf_d_count_init` | 0x2000440 | rw | 64 |  |  | unknown | established |  |
| `portlb_arbr_d_count_init` | 0x2000448 | rw | 64 |  |  | unknown | established |  |
| `throttle_enable_arbl` | 0x2000500 | rw | 64 |  |  | unknown | established |  |
| `throttle_enable_arbr` | 0x2000508 | rw | 64 |  |  | unknown | established |  |
| `age_rate_port` | 0x2000600 | rw | 64 | 8 |  | unknown | established |  |
| `age_rate_portlb` | 0x2000680 | rw | 64 |  |  | unknown | established |  |
| `arbl_test_point_select_512` | 0x2002700 | rw | 64 |  |  | unknown | established |  |
| `arbr_test_point_select_512` | 0x2002720 | rw | 64 |  |  | unknown | established |  |
| `cdq0_test_point_select_512` | 0x2002740 | rw | 64 |  |  | unknown | established |  |
| `cdq1_test_point_select_512` | 0x2002760 | rw | 64 |  |  | unknown | established |  |
| `cdq2_test_point_select_512` | 0x2002780 | rw | 64 |  |  | unknown | established |  |
| `cdq3_test_point_select_512` | 0x2002800 | rw | 64 |  |  | unknown | established |  |
| `port_local_table` | 0x8000000 | rw | 64 | 8 |  | unknown | established |  |
| `port_global_table` | 0x8001000 | rw | 64 | 8 |  | unknown | established |  |
| `port_neighbor_table` | 0x8001800 | rw | 64 | 8 |  | unknown | established |  |
| `port_parms` | 0x8001840 | rw | 64 | 8 |  | unknown | established |  |
| `port_spray_dir` | 0x8001848 | rw | 64 | 8 |  | unknown | established |  |
| `port_spray_cmd_3f_0` | 0x8001850 | rw | 64 | 8 |  | unknown | established |  |
| `port_spray_cmd_7f_40` | 0x8001858 | rw | 64 | 8 |  | unknown | established |  |
| `port_spray_cmd_bf_80` | 0x8001860 | rw | 64 | 8 |  | unknown | established |  |
| `port_spray_cmd_ff_c0` | 0x8001868 | rw | 64 | 8 |  | unknown | established |  |
| `port_llp_config` | 0x8001888 | rw | 64 | 8 |  | unknown | established |  |
| `port_llp_test_ctl` | 0x8001890 | rw | 64 | 8 |  | unknown | established |  |
| `port_llp_state` | 0x8001898 | r | 64 | 8 |  | unknown | established |  |
| `port_llp_err1` | 0x80018a0 | rw | 64 | 8 |  | unknown | established |  |
| `port_llp_err2` | 0x80018a8 | rw | 64 | 8 |  | unknown | established |  |
| `port_llp_capt_wd1` | 0x80018b0 | r | 64 | 8 |  | unknown | established |  |
| `port_llp_capt_wd2` | 0x80018b8 | r | 64 | 8 |  | unknown | established |  |
| `port_llp_capt_sbcb` | 0x80018c0 | r | 64 | 8 |  | unknown | established |  |
| `port_credit` | 0x80018c8 | rw | 64 | 8 |  | unknown | established |  |
| `port_debit` | 0x80018d0 | rw | 64 | 8 |  | unknown | established |  |
| `port_credit_state` | 0x80018d8 | r | 64 | 8 |  | unknown | established |  |
| `port_llp_pkt` | 0x80018e0 | rw | 64 | 8 |  | unknown | established |  |
| `port_error_detail` | 0x8002000 | r | 64 | 8 |  | unknown | established |  |
| `port_error_detail_clear` | 0x8002100 | rw | 64 | 8 |  | unknown | established |  |
| `port_error_summary` | 0x8002200 | rw | 64 | 8 |  | unknown | established |  |
| `port_first_error` | 0x8002210 | rw | 64 | 8 |  | unknown | established |  |
| `port_error_report_mask` | 0x8002218 | rw | 64 | 8 |  | unknown | established |  |
| `port_test_point_select_512` | 0x8002700 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_config` | 0x8007000 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cmd_lo` | 0x8007008 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cmd_up` | 0x8007010 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr0` | 0x8007018 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr1` | 0x8007020 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr2` | 0x8007028 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr3` | 0x8007030 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr4` | 0x8007038 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr5` | 0x8007040 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr6` | 0x8007048 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr7` | 0x8007050 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr8` | 0x8007058 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr9` | 0x8007060 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr10` | 0x8007068 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr11` | 0x8007070 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr12` | 0x8007078 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr13` | 0x8007080 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr14` | 0x8007088 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr15` | 0x8007090 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr16` | 0x8007098 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr17` | 0x80070a0 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr18` | 0x80070a8 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr19` | 0x80070b0 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr20` | 0x80070b8 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr21` | 0x80070c0 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr22` | 0x80070c8 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr23` | 0x80070d0 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr24` | 0x80070d8 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr25` | 0x80070e0 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr26` | 0x80070e8 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr27` | 0x80070f0 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr28` | 0x80070f8 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr29` | 0x8007100 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr30` | 0x8007108 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr31` | 0x8007110 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr32` | 0x8007118 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr33` | 0x8007120 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr34` | 0x8007128 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr35` | 0x8007130 | rw | 64 | 8 |  | unknown | established |  |
| `port_perf_cntr36` | 0x8007138 | rw | 64 | 8 |  | unknown | established |  |

### Register `status_rev_id`

PROM register R4_STATUS_REV_ID. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 57 | `local_pok` | established |  |  | Flags 0x1. |
| 56 | `lb_error` | established |  |  | Flags 0x1. |
| 55 | `porth_error` | established |  |  | Flags 0x1. |
| 54 | `portg_error` | established |  |  | Flags 0x1. |
| 53 | `portf_error` | established |  |  | Flags 0x1. |
| 52 | `porte_error` | established |  |  | Flags 0x1. |
| 51 | `portd_error` | established |  |  | Flags 0x1. |
| 50 | `portc_error` | established |  |  | Flags 0x1. |
| 49 | `portb_error` | established |  |  | Flags 0x1. |
| 48 | `porta_error` | established |  |  | Flags 0x1. |
| 47:44 | `position` | established |  |  | Flags 0x1. |
| 43:40 | `inport` | established |  |  | Flags 0x1. |
| 39 | `porth_link_up` | established |  |  | Flags 0x1. |
| 38 | `portg_link_up` | established |  |  | Flags 0x1. |
| 37 | `portf_link_up` | established |  |  | Flags 0x1. |
| 36 | `porte_link_up` | established |  |  | Flags 0x1. |
| 35 | `portd_link_up` | established |  |  | Flags 0x1. |
| 34 | `portc_link_up` | established |  |  | Flags 0x1. |
| 33 | `portb_link_up` | established |  |  | Flags 0x1. |
| 32 | `porta_link_up` | established |  |  | Flags 0x1. |
| 31:28 | `chip_revision` | established |  |  | Flags 0x1. |
| 27:12 | `part_number` | established |  |  | Flags 0x1. |
| 11:1 | `mfg_id` | established |  |  | Flags 0x1. |
| 0 | `force1` | established |  |  | Flags 0x1. |

### Register `global_parm0`

PROM register R4_GLOBAL_PARM0. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23 | `porth_dateline` | established |  |  | Flags 0xb. |
| 22 | `portg_dateline` | established |  |  | Flags 0xb. |
| 21 | `portf_dateline` | established |  |  | Flags 0xb. |
| 20 | `porte_dateline` | established |  |  | Flags 0xb. |
| 19 | `portd_dateline` | established |  |  | Flags 0xb. |
| 18 | `portc_dateline` | established |  |  | Flags 0xb. |
| 17 | `portb_dateline` | established |  |  | Flags 0xb. |
| 16 | `porta_dateline` | established |  |  | Flags 0xb. |
| 15:12 | `deadlock_to_val` | established |  |  | Flags 0xb. |
| 11:8 | `tail_to_val` | established |  |  | Flags 0xb. |
| 5 | `use_oldest_age_enable` | established |  |  | Flags 0xb. |
| 4 | `inherit_age_enable` | established |  |  | Flags 0xb. |
| 3 | `pass2_arb_enable` | established |  |  | Flags 0xb. |
| 2 | `preferred_enable` | established |  |  | Flags 0xb. |
| 1 | `most_eligible_enable` | established |  |  | Flags 0xb. |
| 0 | `bypass_enable` | established |  |  | Flags 0xb. |

### Register `global_parm1`

PROM register R4_GLOBAL_PARM1. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20:16 | `deadlock_to_tick` | established |  |  | Flags 0xb. |
| 12:8 | `send_to_tick` | established |  |  | Flags 0xb. |
| 4:0 | `tail_to_tick` | established |  |  | Flags 0xb. |

### Register `asic_to_l1_status`

PROM register R4_ASIC_TO_L1_STATUS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `status` | established |  |  | Flags 0x1. |

### Register `asic_to_l1_data`

PROM register R4_ASIC_TO_L1_DATA. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `data` | established |  |  | Flags 0xb. |

### Register `l1_to_asic_status`

PROM register R4_L1_TO_ASIC_STATUS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `status` | established |  |  | Flags 0xb. |

### Register `l1_to_asic_data`

PROM register R4_L1_TO_ASIC_DATA. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `data` | established |  |  | Flags 0x1. |

### Register `scratch0`

PROM register R4_SCRATCH0. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch_64` | established |  |  | Flags 0xb. |

### Register `scratch0_alias`

PROM register R4_SCRATCH0_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch_64` | established |  |  | Flags 0x8. |

### Register `scratch1`

PROM register R4_SCRATCH1. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch_64` | established |  |  | Flags 0xb. |

### Register `scratch1_alias`

PROM register R4_SCRATCH1_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch_64` | established |  |  | Flags 0x8. |

### Register `scratch2`

PROM register R4_SCRATCH2. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch_64` | established |  |  | Flags 0xb. |

### Register `scratch2_alias`

PROM register R4_SCRATCH2_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch_64` | established |  |  | Flags 0x8. |

### Register `scratch3`

PROM register R4_SCRATCH3. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `scratch_1` | established |  |  | Flags 0xb. |

### Register `scratch3_alias`

PROM register R4_SCRATCH3_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `scratch_1` | established |  |  | Flags 0xf. |

### Register `scratch4`

PROM register R4_SCRATCH4. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `scratch_1` | established |  |  | Flags 0xb. |

### Register `scratch4_alias`

PROM register R4_SCRATCH4_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `scratch_1` | established |  |  | Flags 0xf. |

### Register `scratch5`

PROM register R4_SCRATCH5. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0xb. |

### Register `scratch5_alias`

PROM register R4_SCRATCH5_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0x8. |

### Register `scratch6`

PROM register R4_SCRATCH6. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0xb. |

### Register `scratch6_alias`

PROM register R4_SCRATCH6_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0x8. |

### Register `scratch7`

PROM register R4_SCRATCH7. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0xb. |

### Register `scratch7_alias`

PROM register R4_SCRATCH7_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0x8. |

### Register `scratch8`

PROM register R4_SCRATCH8. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0xb. |

### Register `scratch8_alias`

PROM register R4_SCRATCH8_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0x8. |

### Register `scratch9`

PROM register R4_SCRATCH9. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0xb. |

### Register `scratch9_alias`

PROM register R4_SCRATCH9_ALIAS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `scratch_8` | established |  |  | Flags 0x8. |

### Register `asic_first_error`

PROM register R4_ASIC_FIRST_ERROR. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `lb_error` | established |  |  | Flags 0xb. |
| 7 | `porth_error` | established |  |  | Flags 0xb. |
| 6 | `portg_error` | established |  |  | Flags 0xb. |
| 5 | `portf_error` | established |  |  | Flags 0xb. |
| 4 | `porte_error` | established |  |  | Flags 0xb. |
| 3 | `portd_error` | established |  |  | Flags 0xb. |
| 2 | `portc_error` | established |  |  | Flags 0xb. |
| 1 | `portb_error` | established |  |  | Flags 0xb. |
| 0 | `porta_error` | established |  |  | Flags 0xb. |

### Register `asic_first_error_timestamp`

PROM register R4_ASIC_FIRST_ERROR_TIMESTAMP. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `rtc_value` | established |  |  | Flags 0xb. |

### Register `lb_error_summary`

PROM register R4_LB_ERROR_SUMMARY. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `vch3_deadlock_to` | established |  |  | Flags 0xb. |
| 19 | `vch2_deadlock_to` | established |  |  | Flags 0xb. |
| 18 | `vch1_deadlock_to` | established |  |  | Flags 0xb. |
| 17 | `vch0_deadlock_to` | established |  |  | Flags 0xb. |
| 16 | `gather_spur_err` | established |  |  | Flags 0xb. |
| 15 | `gather_to` | established |  |  | Flags 0xb. |
| 14 | `gather_err` | established |  |  | Flags 0xb. |
| 13 | `rep_bad_next_dir` | established |  |  | Flags 0xb. |
| 12 | `rep_bad_this_dir` | established |  |  | Flags 0xb. |
| 11 | `rep_msg_len_err` | established |  |  | Flags 0xb. |
| 10 | `bad_rep_msg` | established |  |  | Flags 0xb. |
| 9 | `rep_sb_error` | established |  |  | Flags 0xb. |
| 8 | `req_bad_next_dir` | established |  |  | Flags 0xb. |
| 7 | `req_bad_this_dir` | established |  |  | Flags 0xb. |
| 6 | `jtag_pio_err` | established |  |  | Flags 0xb. |
| 5 | `pio_chn_to` | established |  |  | Flags 0xb. |
| 4 | `pio_unexp_valid` | established |  |  | Flags 0xb. |
| 3 | `pio_bad_addr` | established |  |  | Flags 0xb. |
| 2 | `req_msg_len_err` | established |  |  | Flags 0xb. |
| 1 | `bad_req_msg` | established |  |  | Flags 0xb. |
| 0 | `req_sb_error` | established |  |  | Flags 0xb. |

### Register `lb_first_error`

PROM register R4_LB_FIRST_ERROR. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `vch3_deadlock_to` | established |  |  | Flags 0xb. |
| 19 | `vch2_deadlock_to` | established |  |  | Flags 0xb. |
| 18 | `vch1_deadlock_to` | established |  |  | Flags 0xb. |
| 17 | `vch0_deadlock_to` | established |  |  | Flags 0xb. |
| 16 | `gather_spur_err` | established |  |  | Flags 0xb. |
| 15 | `gather_to` | established |  |  | Flags 0xb. |
| 14 | `gather_err` | established |  |  | Flags 0xb. |
| 13 | `rep_bad_next_dir` | established |  |  | Flags 0xb. |
| 12 | `rep_bad_this_dir` | established |  |  | Flags 0xb. |
| 11 | `rep_msg_len_err` | established |  |  | Flags 0xb. |
| 10 | `bad_rep_msg` | established |  |  | Flags 0xb. |
| 9 | `rep_sb_error` | established |  |  | Flags 0xb. |
| 8 | `req_bad_next_dir` | established |  |  | Flags 0xb. |
| 7 | `req_bad_this_dir` | established |  |  | Flags 0xb. |
| 6 | `jtag_pio_err` | established |  |  | Flags 0xb. |
| 5 | `pio_chn_to` | established |  |  | Flags 0xb. |
| 4 | `pio_unexp_valid` | established |  |  | Flags 0xb. |
| 3 | `pio_bad_addr` | established |  |  | Flags 0xb. |
| 2 | `req_msg_len_err` | established |  |  | Flags 0xb. |
| 1 | `bad_req_msg` | established |  |  | Flags 0xb. |
| 0 | `req_sb_error` | established |  |  | Flags 0xb. |

### Register `lb_error_report_mask`

PROM register R4_LB_ERROR_REPORT_MASK. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `vch3_deadlock_to` | established |  |  | Flags 0xb. |
| 19 | `vch2_deadlock_to` | established |  |  | Flags 0xb. |
| 18 | `vch1_deadlock_to` | established |  |  | Flags 0xb. |
| 17 | `vch0_deadlock_to` | established |  |  | Flags 0xb. |
| 16 | `gather_spur_err` | established |  |  | Flags 0xb. |
| 15 | `gather_to` | established |  |  | Flags 0xb. |
| 14 | `gather_err` | established |  |  | Flags 0xb. |
| 13 | `rep_bad_next_dir` | established |  |  | Flags 0xb. |
| 12 | `rep_bad_this_dir` | established |  |  | Flags 0xb. |
| 11 | `rep_msg_len_err` | established |  |  | Flags 0xb. |
| 10 | `bad_rep_msg` | established |  |  | Flags 0xb. |
| 9 | `rep_sb_error` | established |  |  | Flags 0xb. |
| 8 | `req_bad_next_dir` | established |  |  | Flags 0xb. |
| 7 | `req_bad_this_dir` | established |  |  | Flags 0xb. |
| 6 | `jtag_pio_err` | established |  |  | Flags 0xb. |
| 5 | `pio_chn_to` | established |  |  | Flags 0xb. |
| 4 | `pio_unexp_valid` | established |  |  | Flags 0xb. |
| 3 | `pio_bad_addr` | established |  |  | Flags 0xb. |
| 2 | `req_msg_len_err` | established |  |  | Flags 0xb. |
| 1 | `bad_req_msg` | established |  |  | Flags 0xb. |
| 0 | `req_sb_error` | established |  |  | Flags 0xb. |

### Register `lb_error_detail_1`

PROM register R4_LB_ERROR_DETAIL_1. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `command` | established |  |  | Flags 0xb. |
| 55:52 | `echo3_0` | established |  |  | Flags 0xb. |
| 51:3 | `address` | established |  |  | Flags 0xb. |
| 1:0 | `dest_chiplet` | established |  |  | Flags 0xb. |

### Register `lb_error_detail_2`

PROM register R4_LB_ERROR_DETAIL_2. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:48 | `supplemental` | established |  |  | Flags 0xb. |
| 47:46 | `src_chiplet` | established |  |  | Flags 0xb. |
| 45:32 | `source` | established |  |  | Flags 0xb. |
| 31:28 | `dir3_0` | established |  |  | Flags 0xb. |
| 27:24 | `echo7_4` | established |  |  | Flags 0xb. |
| 23 | `echo8` | established |  |  | Flags 0xb. |
| 22 | `dir4` | established |  |  | Flags 0xb. |
| 21:8 | `destination` | established |  |  | Flags 0xb. |
| 7:0 | `age` | established |  |  | Flags 0xb. |

### Register `lb0_test_point_select_512`

PROM register R4_LB0_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `lb_dateline`

PROM register R4_LB_DATELINE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `en` | established |  |  | Flags 0xb. |

### Register `lb_preage`

PROM register R4_LB_PREAGE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `age` | established |  |  | Flags 0xb. |

### Register `pio_time_out`

PROM register R4_PIO_TIME_OUT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `value` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_0`

PROM register R4_MCAST_TRANS_TABLE_0. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_1`

PROM register R4_MCAST_TRANS_TABLE_1. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_2`

PROM register R4_MCAST_TRANS_TABLE_2. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_3`

PROM register R4_MCAST_TRANS_TABLE_3. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_4`

PROM register R4_MCAST_TRANS_TABLE_4. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_5`

PROM register R4_MCAST_TRANS_TABLE_5. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_6`

PROM register R4_MCAST_TRANS_TABLE_6. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_7`

PROM register R4_MCAST_TRANS_TABLE_7. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_8`

PROM register R4_MCAST_TRANS_TABLE_8. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_9`

PROM register R4_MCAST_TRANS_TABLE_9. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_10`

PROM register R4_MCAST_TRANS_TABLE_10. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_11`

PROM register R4_MCAST_TRANS_TABLE_11. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_12`

PROM register R4_MCAST_TRANS_TABLE_12. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_13`

PROM register R4_MCAST_TRANS_TABLE_13. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_14`

PROM register R4_MCAST_TRANS_TABLE_14. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_trans_table_15`

PROM register R4_MCAST_TRANS_TABLE_15. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 31:28 | `to` | established |  |  | Flags 0xb. |
| 26 | `self_inc_en` | established |  |  | Flags 0xb. |
| 25 | `vec_up_en` | established |  |  | Flags 0xb. |
| 24 | `vec_low_en` | established |  |  | Flags 0xb. |
| 21:20 | `vec_idx` | established |  |  | Flags 0xb. |
| 18:16 | `action` | established |  |  | Flags 0xb. |
| 15:8 | `cmd_out` | established |  |  | Flags 0xb. |
| 7:0 | `cmd_in` | established |  |  | Flags 0xb. |

### Register `mcast_dest_table`

PROM register R4_MCAST_DEST_TABLE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 28:24 | `dir1` | established |  |  | Flags 0xb. |
| 20:16 | `dir0` | established |  |  | Flags 0xb. |
| 13:0 | `node_id` | established |  |  | Flags 0xb. |

### Register `mcast_rep_gather_buf`

PROM register R4_MCAST_REP_GATHER_BUF. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `free` | established |  |  | Flags 0xb. |
| 61 | `err` | established |  |  | Flags 0xb. |
| 60 | `forced_suppl` | established |  |  | Flags 0x1. |
| 59 | `mcast_done` | established |  |  | Flags 0x1. |
| 58:50 | `echo` | established |  |  | Flags 0x1. |
| 49:36 | `source_node` | established |  |  | Flags 0x1. |
| 35:32 | `timer` | established |  |  | Flags 0x1. |
| 28:24 | `dir1` | established |  |  | Flags 0x1. |
| 20:16 | `dir0` | established |  |  | Flags 0x1. |
| 15:8 | `exp_suppl` | established |  |  | Flags 0x1. |
| 7:0 | `act_suppl` | established |  |  | Flags 0x1. |

### Register `mcast_gather_config`

PROM register R4_MCAST_GATHER_CONFIG. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12:8 | `gather_to_tick` | established |  |  | Flags 0xb. |
| 0 | `lut_pair` | established |  |  | Flags 0xb. |

### Register `mcast_dest_vec_0`

PROM register R4_MCAST_DEST_VEC_0. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `exp_count` | established |  |  | Flags 0xb. |
| 15:0 | `bit_map` | established |  |  | Flags 0xb. |

### Register `mcast_dest_vec_1`

PROM register R4_MCAST_DEST_VEC_1. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `exp_count` | established |  |  | Flags 0xb. |
| 15:0 | `bit_map` | established |  |  | Flags 0xb. |

### Register `mcast_dest_vec_2`

PROM register R4_MCAST_DEST_VEC_2. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `exp_count` | established |  |  | Flags 0xb. |
| 15:0 | `bit_map` | established |  |  | Flags 0xb. |

### Register `mcast_dest_vec_3`

PROM register R4_MCAST_DEST_VEC_3. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `exp_count` | established |  |  | Flags 0xb. |
| 15:0 | `bit_map` | established |  |  | Flags 0xb. |

### Register `lb_local_table`

PROM register R4_LB_LOCAL_TABLE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 4:0 | `dir1` | established |  |  | Flags 0xb. |

### Register `lb_global_table`

PROM register R4_LB_GLOBAL_TABLE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 4:0 | `dir1` | established |  |  | Flags 0xb. |

### Register `rtc_source`

PROM register R4_RTC_SOURCE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:32 | `porth_rtc_select` | established |  |  | Flags 0xb. |
| 31:28 | `portg_rtc_select` | established |  |  | Flags 0xb. |
| 27:24 | `portf_rtc_select` | established |  |  | Flags 0xb. |
| 23:20 | `porte_rtc_select` | established |  |  | Flags 0xb. |
| 19:16 | `portd_rtc_select` | established |  |  | Flags 0xb. |
| 15:12 | `portc_rtc_select` | established |  |  | Flags 0xb. |
| 11:8 | `portb_rtc_select` | established |  |  | Flags 0xb. |
| 7:4 | `porta_rtc_select` | established |  |  | Flags 0xb. |
| 3:0 | `lb_rtc_select` | established |  |  | Flags 0xb. |

### Register `rtc_intrn_cntrl`

PROM register R4_RTC_INTRN_CNTRL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:16 | `count` | established |  |  | Flags 0x1. |
| 9:0 | `max_count` | established |  |  | Flags 0xb. |

### Register `throttle_interval`

PROM register R4_THROTTLE_INTERVAL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29:0 | `count` | established |  |  | Flags 0xb. |

### Register `throttle_time`

PROM register R4_THROTTLE_TIME. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29:0 | `count` | established |  |  | Flags 0xb. |

### Register `throttle_status`

PROM register R4_THROTTLE_STATUS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:32 | `time` | established |  |  | Flags 0x1. |
| 29:0 | `interval` | established |  |  | Flags 0x1. |

### Register `throttle_skip`

PROM register R4_THROTTLE_SKIP. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `next` | established |  |  | Flags 0xb. |

### Register `debug_port_config`

PROM register R4_DEBUG_PORT_CONFIG. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `en` | established |  |  | Flags 0xb. |

### Register `vbit_emul`

PROM register R4_VBIT_EMUL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `v_bit_emulation` | established |  |  | Flags 0xb. |

### Register `lb1_test_point_select_512`

PROM register R4_LB1_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `hard_reset`

PROM register R4_HARD_RESET. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `hard_reset` | established |  |  | Flags 0x7. |

### Register `soft_reset`

PROM register R4_SOFT_RESET. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `soft_reset` | established |  |  | Flags 0x7. |

### Register `port_reset`

PROM register R4_PORT_RESET. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9 | `port_warm_reset` | established |  |  | Flags 0x7. |
| 8 | `porth_link_reset` | established |  |  | Flags 0x7. |
| 7 | `portg_link_reset` | established |  |  | Flags 0x7. |
| 6 | `portf_link_reset` | established |  |  | Flags 0x7. |
| 5 | `porte_link_reset` | established |  |  | Flags 0x7. |
| 4 | `portd_link_reset` | established |  |  | Flags 0x7. |
| 3 | `portc_link_reset` | established |  |  | Flags 0x7. |
| 2 | `portb_link_reset` | established |  |  | Flags 0x7. |
| 1 | `porta_link_reset` | established |  |  | Flags 0x7. |
| 0 | `lb_reset` | established |  |  | Flags 0x7. |

### Register `protection_config`

PROM register R4_PROTECTION_CONFIG. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `lb_force_local_lut` | established |  |  | Flags 0xb. |
| 29 | `porth_force_local_lut` | established |  |  | Flags 0xb. |
| 28 | `portg_force_local_lut` | established |  |  | Flags 0xb. |
| 27 | `portf_force_local_lut` | established |  |  | Flags 0xb. |
| 26 | `porte_force_local_lut` | established |  |  | Flags 0xb. |
| 25 | `portd_force_local_lut` | established |  |  | Flags 0xb. |
| 24 | `portc_force_local_lut` | established |  |  | Flags 0xb. |
| 23 | `portb_force_local_lut` | established |  |  | Flags 0xb. |
| 22 | `porta_force_local_lut` | established |  |  | Flags 0xb. |
| 21:8 | `node_id` | established |  |  | Flags 0xb. |
| 7 | `porth_local_reset_en` | established |  |  | Flags 0xb. |
| 6 | `portg_local_reset_en` | established |  |  | Flags 0xb. |
| 5 | `portf_local_reset_en` | established |  |  | Flags 0xb. |
| 4 | `porte_local_reset_en` | established |  |  | Flags 0xb. |
| 3 | `portd_local_reset_en` | established |  |  | Flags 0xb. |
| 2 | `portc_local_reset_en` | established |  |  | Flags 0xb. |
| 1 | `portb_local_reset_en` | established |  |  | Flags 0xb. |
| 0 | `porta_local_reset_en` | established |  |  | Flags 0xb. |

### Register `port_rst_mask`

PROM register R4_PORTA_RST_MASK; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `from_porth` | established |  |  | Flags 0xb. |
| 6 | `from_portg` | established |  |  | Flags 0xb. |
| 5 | `from_portf` | established |  |  | Flags 0xb. |
| 4 | `from_porte` | established |  |  | Flags 0xb. |
| 3 | `from_portd` | established |  |  | Flags 0xb. |
| 2 | `from_portc` | established |  |  | Flags 0xb. |
| 1 | `from_portb` | established |  |  | Flags 0xb. |
| 0 | `from_porta` | established |  |  | Flags 0xb. |

### Register `port_perf_win`

PROM register R4_PORT_PERF_WIN. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `force_en` | established |  |  | Flags 0xb. |
| 62 | `clear` | established |  |  | Flags 0x7. |
| 59:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `tsf_arm_mask`

PROM register R4_TSF_ARM_MASK. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `mask` | established |  |  | Flags 0xb. |

### Register `tsf_counter_presets`

PROM register R4_TSF_COUNTER_PRESETS. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `count_8a` | established |  |  | Flags 0xb. |
| 55:48 | `count_8b` | established |  |  | Flags 0xb. |
| 47:32 | `count_16` | established |  |  | Flags 0xb. |
| 31:0 | `count_32` | established |  |  | Flags 0xb. |

### Register `tsf_decrement_ctl`

PROM register R4_TSF_DECREMENT_CTL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `ctl` | established |  |  | Flags 0xb. |

### Register `tsf_diag_msg_ctl`

PROM register R4_TSF_DIAG_MSG_CTL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `enable` | established |  |  | Flags 0xb. |

### Register `tsf_disarm_mask`

PROM register R4_TSF_DISARM_MASK. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `mask` | established |  |  | Flags 0xb. |

### Register `tsf_enable_ctl`

PROM register R4_TSF_ENABLE_CTL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `ctl` | established |  |  | Flags 0xb. |

### Register `tsf_software_arm`

PROM register R4_TSF_SOFTWARE_ARM. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `bit7` | established |  |  | Flags 0x7. |
| 6 | `bit6` | established |  |  | Flags 0x7. |
| 5 | `bit5` | established |  |  | Flags 0x7. |
| 4 | `bit4` | established |  |  | Flags 0x7. |
| 3 | `bit3` | established |  |  | Flags 0x7. |
| 2 | `bit2` | established |  |  | Flags 0x7. |
| 1 | `bit1` | established |  |  | Flags 0x7. |
| 0 | `bit0` | established |  |  | Flags 0x7. |

### Register `tsf_software_disarm`

PROM register R4_TSF_SOFTWARE_DISARM. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `bit7` | established |  |  | Flags 0x7. |
| 6 | `bit6` | established |  |  | Flags 0x7. |
| 5 | `bit5` | established |  |  | Flags 0x7. |
| 4 | `bit4` | established |  |  | Flags 0x7. |
| 3 | `bit3` | established |  |  | Flags 0x7. |
| 2 | `bit2` | established |  |  | Flags 0x7. |
| 1 | `bit1` | established |  |  | Flags 0x7. |
| 0 | `bit0` | established |  |  | Flags 0x7. |

### Register `tsf_software_triggered`

PROM register R4_TSF_SOFTWARE_TRIGGERED. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `bit7` | established |  |  | Flags 0x7. |
| 6 | `bit6` | established |  |  | Flags 0x7. |
| 5 | `bit5` | established |  |  | Flags 0x7. |
| 4 | `bit4` | established |  |  | Flags 0x7. |
| 3 | `bit3` | established |  |  | Flags 0x7. |
| 2 | `bit2` | established |  |  | Flags 0x7. |
| 1 | `bit1` | established |  |  | Flags 0x7. |
| 0 | `bit0` | established |  |  | Flags 0x7. |

### Register `tsf_trigger_mask`

PROM register R4_TSF_TRIGGER_MASK. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `mask` | established |  |  | Flags 0xb. |

### Register `tsf_armed_state`

PROM register R4_TSF_ARMED_STATE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `state` | established |  |  | Flags 0xb. |

### Register `tsf_counter_value`

PROM register R4_TSF_COUNTER_VALUE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `count_8a` | established |  |  | Flags 0xb. |
| 55:48 | `count_8b` | established |  |  | Flags 0xb. |
| 47:32 | `count_16` | established |  |  | Flags 0xb. |
| 31:0 | `count_32` | established |  |  | Flags 0xb. |

### Register `tsf_triggered_state`

PROM register R4_TSF_TRIGGERED_STATE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `state` | established |  |  | Flags 0xb. |

### Register `root_test_point_select`

PROM register R4_ROOT_TEST_POINT_SELECT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `trigger_enable` | established |  |  | Flags 0xb. |
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 58:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 50:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 42:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 34:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 26:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 18:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 10:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 2:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `root_test_point_compare`

PROM register R4_ROOT_TEST_POINT_COMPARE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `compare_pattern` | established |  |  | Flags 0xb. |
| 31:0 | `compare_mask` | established |  |  | Flags 0xb. |

### Register `root_test_point_trigger_select`

PROM register R4_ROOT_TEST_POINT_TRIGGER_SELECT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `trigger7_nibble_sel` | established |  |  | Flags 0xb. |
| 58:56 | `trigger7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `trigger6_nibble_sel` | established |  |  | Flags 0xb. |
| 50:48 | `trigger6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `trigger5_nibble_sel` | established |  |  | Flags 0xb. |
| 42:40 | `trigger5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `trigger4_nibble_sel` | established |  |  | Flags 0xb. |
| 34:32 | `trigger4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `trigger3_nibble_sel` | established |  |  | Flags 0xb. |
| 26:24 | `trigger3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `trigger2_nibble_sel` | established |  |  | Flags 0xb. |
| 18:16 | `trigger2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `trigger1_nibble_sel` | established |  |  | Flags 0xb. |
| 10:8 | `trigger1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `trigger0_nibble_sel` | established |  |  | Flags 0xb. |
| 2:0 | `trigger0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `branch1_test_point_select`

PROM register R4_BRANCH1_TEST_POINT_SELECT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `trigger_enable` | established |  |  | Flags 0xb. |
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 58:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 50:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 42:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 34:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 26:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 18:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 10:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 2:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `branch1_test_point_compare`

PROM register R4_BRANCH1_TEST_POINT_COMPARE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `compare_pattern` | established |  |  | Flags 0xb. |
| 31:0 | `compare_mask` | established |  |  | Flags 0xb. |

### Register `branch1_test_point_trigger_select`

PROM register R4_BRANCH1_TEST_POINT_TRIGGER_SELECT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `trigger7_nibble_sel` | established |  |  | Flags 0xb. |
| 58:56 | `trigger7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `trigger6_nibble_sel` | established |  |  | Flags 0xb. |
| 50:48 | `trigger6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `trigger5_nibble_sel` | established |  |  | Flags 0xb. |
| 42:40 | `trigger5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `trigger4_nibble_sel` | established |  |  | Flags 0xb. |
| 34:32 | `trigger4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `trigger3_nibble_sel` | established |  |  | Flags 0xb. |
| 26:24 | `trigger3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `trigger2_nibble_sel` | established |  |  | Flags 0xb. |
| 18:16 | `trigger2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `trigger1_nibble_sel` | established |  |  | Flags 0xb. |
| 10:8 | `trigger1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `trigger0_nibble_sel` | established |  |  | Flags 0xb. |
| 2:0 | `trigger0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `branch2_test_point_select`

PROM register R4_BRANCH2_TEST_POINT_SELECT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `trigger_enable` | established |  |  | Flags 0xb. |
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 58:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 50:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 42:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 34:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 26:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 18:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 10:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 2:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `branch2_test_point_compare`

PROM register R4_BRANCH2_TEST_POINT_COMPARE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `compare_pattern` | established |  |  | Flags 0xb. |
| 31:0 | `compare_mask` | established |  |  | Flags 0xb. |

### Register `branch2_test_point_trigger_select`

PROM register R4_BRANCH2_TEST_POINT_TRIGGER_SELECT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `trigger7_nibble_sel` | established |  |  | Flags 0xb. |
| 58:56 | `trigger7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `trigger6_nibble_sel` | established |  |  | Flags 0xb. |
| 50:48 | `trigger6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `trigger5_nibble_sel` | established |  |  | Flags 0xb. |
| 42:40 | `trigger5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `trigger4_nibble_sel` | established |  |  | Flags 0xb. |
| 34:32 | `trigger4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `trigger3_nibble_sel` | established |  |  | Flags 0xb. |
| 26:24 | `trigger3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `trigger2_nibble_sel` | established |  |  | Flags 0xb. |
| 18:16 | `trigger2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `trigger1_nibble_sel` | established |  |  | Flags 0xb. |
| 10:8 | `trigger1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `trigger0_nibble_sel` | established |  |  | Flags 0xb. |
| 2:0 | `trigger0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `branch1_debug_data`

PROM register R4_BRANCH1_DEBUG_DATA. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `trig` | established |  |  | Flags 0x1. |
| 31:0 | `data` | established |  |  | Flags 0x1. |

### Register `branch2_debug_data`

PROM register R4_BRANCH2_DEBUG_DATA. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `trig` | established |  |  | Flags 0x1. |
| 31:0 | `data` | established |  |  | Flags 0x1. |

### Register `root_debug_data`

PROM register R4_ROOT_DEBUG_DATA. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `trig` | established |  |  | Flags 0x1. |
| 31:0 | `data` | established |  |  | Flags 0x1. |

### Register `stop_clk_control`

PROM register R4_STOP_CLK_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `enable` | established |  |  | Flags 0xb. |
| 7 | `mode` | established |  |  | Flags 0xb. |
| 6 | `polarity` | established |  |  | Flags 0xb. |
| 5 | `event` | established |  |  | Flags 0xb. |
| 4:0 | `stimulus` | established |  |  | Flags 0xb. |

### Register `stop_clk_delay_phase`

PROM register R4_STOP_CLK_DELAY_PHASE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `delay` | established |  |  | Flags 0xb. |

### Register `performance_count0_control`

PROM register R4_PERFORMANCE_COUNT0_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `performance_count1_control`

PROM register R4_PERFORMANCE_COUNT1_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `performance_count2_control`

PROM register R4_PERFORMANCE_COUNT2_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `performance_count3_control`

PROM register R4_PERFORMANCE_COUNT3_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `performance_count4_control`

PROM register R4_PERFORMANCE_COUNT4_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `performance_count5_control`

PROM register R4_PERFORMANCE_COUNT5_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `performance_count6_control`

PROM register R4_PERFORMANCE_COUNT6_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `performance_count7_control`

PROM register R4_PERFORMANCE_COUNT7_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `clr_enable` | established |  |  | Flags 0xb. |
| 31 | `clr_mode` | established |  |  | Flags 0xb. |
| 30 | `clr_polarity` | established |  |  | Flags 0xb. |
| 29 | `clr_event` | established |  |  | Flags 0xb. |
| 28:24 | `clr_stimulus` | established |  |  | Flags 0xb. |
| 18 | `peak_det_enable` | established |  |  | Flags 0xb. |
| 17 | `dec_enable` | established |  |  | Flags 0xb. |
| 16 | `inc_enable` | established |  |  | Flags 0xb. |
| 15 | `dn_mode` | established |  |  | Flags 0xb. |
| 14 | `dn_polarity` | established |  |  | Flags 0xb. |
| 13 | `dn_event` | established |  |  | Flags 0xb. |
| 12:8 | `dn_stimulus` | established |  |  | Flags 0xb. |
| 7 | `up_mode` | established |  |  | Flags 0xb. |
| 6 | `up_polarity` | established |  |  | Flags 0xb. |
| 5 | `up_event` | established |  |  | Flags 0xb. |
| 4:0 | `up_stimulus` | established |  |  | Flags 0xb. |

### Register `profile_dn_control`

PROM register R4_PROFILE_DN_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `mode` | established |  |  | Flags 0xb. |
| 6 | `polarity` | established |  |  | Flags 0xb. |
| 5 | `event` | established |  |  | Flags 0xb. |
| 4:0 | `stimulus` | established |  |  | Flags 0xb. |

### Register `profile_peak_control`

PROM register R4_PROFILE_PEAK_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `polarity` | established |  |  | Flags 0xb. |
| 5 | `event` | established |  |  | Flags 0xb. |
| 3 | `stimulus` | established |  |  | Flags 0xb. |

### Register `profile_range`

PROM register R4_PROFILE_RANGE. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `range7` | established |  |  | Flags 0xb. |
| 55:48 | `range6` | established |  |  | Flags 0xb. |
| 47:40 | `range5` | established |  |  | Flags 0xb. |
| 39:32 | `range4` | established |  |  | Flags 0xb. |
| 31:24 | `range3` | established |  |  | Flags 0xb. |
| 23:16 | `range2` | established |  |  | Flags 0xb. |
| 15:8 | `range1` | established |  |  | Flags 0xb. |
| 7:0 | `range0` | established |  |  | Flags 0xb. |

### Register `profile_up_control`

PROM register R4_PROFILE_UP_CONTROL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `mode` | established |  |  | Flags 0xb. |
| 6 | `polarity` | established |  |  | Flags 0xb. |
| 5 | `event` | established |  |  | Flags 0xb. |
| 4:0 | `stimulus` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_0`

PROM register R4_PERF_TRIG_PATTERN_0. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_1`

PROM register R4_PERF_TRIG_PATTERN_1. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_2`

PROM register R4_PERF_TRIG_PATTERN_2. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_3`

PROM register R4_PERF_TRIG_PATTERN_3. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_4`

PROM register R4_PERF_TRIG_PATTERN_4. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_5`

PROM register R4_PERF_TRIG_PATTERN_5. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_6`

PROM register R4_PERF_TRIG_PATTERN_6. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_7`

PROM register R4_PERF_TRIG_PATTERN_7. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_8`

PROM register R4_PERF_TRIG_PATTERN_8. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_9`

PROM register R4_PERF_TRIG_PATTERN_9. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_10`

PROM register R4_PERF_TRIG_PATTERN_10. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_11`

PROM register R4_PERF_TRIG_PATTERN_11. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_12`

PROM register R4_PERF_TRIG_PATTERN_12. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_13`

PROM register R4_PERF_TRIG_PATTERN_13. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_14`

PROM register R4_PERF_TRIG_PATTERN_14. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `perf_trig_pattern_15`

PROM register R4_PERF_TRIG_PATTERN_15. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `bit_en` | established |  |  | Flags 0xb. |
| 31:0 | `data` | established |  |  | Flags 0xb. |

### Register `performance_counter0`

PROM register R4_PERFORMANCE_COUNTER0. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `performance_counter1`

PROM register R4_PERFORMANCE_COUNTER1. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `performance_counter2`

PROM register R4_PERFORMANCE_COUNTER2. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `performance_counter3`

PROM register R4_PERFORMANCE_COUNTER3. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `performance_counter4`

PROM register R4_PERFORMANCE_COUNTER4. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `performance_counter5`

PROM register R4_PERFORMANCE_COUNTER5. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `performance_counter6`

PROM register R4_PERFORMANCE_COUNTER6. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `performance_counter7`

PROM register R4_PERFORMANCE_COUNTER7. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `count` | established |  |  | Flags 0xb. |

### Register `profile_counter`

PROM register R4_PROFILE_COUNTER. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `counter` | established |  |  | Flags 0xb. |

### Register `profile_peak`

PROM register R4_PROFILE_PEAK. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `counter` | established |  |  | Flags 0xb. |

### Register `port_vc0_n_count_init`

PROM register R4_PORTA_VC0_N_COUNT_INIT; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 32.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:32 | `n_init_input_port_lb` | established |  |  | Flags 0xb. |
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `port_vc1_n_count_init`

PROM register R4_PORTA_VC1_N_COUNT_INIT; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 32.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:32 | `n_init_input_port_lb` | established |  |  | Flags 0xb. |
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `port_vc2_n_count_init`

PROM register R4_PORTA_VC2_N_COUNT_INIT; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 32.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:32 | `n_init_input_port_lb` | established |  |  | Flags 0xb. |
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `port_vc3_n_count_init`

PROM register R4_PORTA_VC3_N_COUNT_INIT; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 32.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:32 | `n_init_input_port_lb` | established |  |  | Flags 0xb. |
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `portlb_arbl_vc0_n_count_init`

PROM register R4_PORTLB_ARBL_VC0_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `portlb_arbl_vc1_n_count_init`

PROM register R4_PORTLB_ARBL_VC1_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `portlb_arbl_vc2_n_count_init`

PROM register R4_PORTLB_ARBL_VC2_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `portlb_arbl_vc3_n_count_init`

PROM register R4_PORTLB_ARBL_VC3_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29:28 | `n_init_input_port_h` | established |  |  | Flags 0xb. |
| 25:24 | `n_init_input_port_g` | established |  |  | Flags 0xb. |
| 5:4 | `n_init_input_port_b` | established |  |  | Flags 0xb. |
| 1:0 | `n_init_input_port_a` | established |  |  | Flags 0xb. |

### Register `portlb_arbr_vc0_n_count_init`

PROM register R4_PORTLB_ARBR_VC0_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |

### Register `portlb_arbr_vc1_n_count_init`

PROM register R4_PORTLB_ARBR_VC1_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |

### Register `portlb_arbr_vc2_n_count_init`

PROM register R4_PORTLB_ARBR_VC2_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |

### Register `portlb_arbr_vc3_n_count_init`

PROM register R4_PORTLB_ARBR_VC3_N_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:20 | `n_init_input_port_f` | established |  |  | Flags 0xb. |
| 17:16 | `n_init_input_port_e` | established |  |  | Flags 0xb. |
| 13:12 | `n_init_input_port_d` | established |  |  | Flags 0xb. |
| 9:8 | `n_init_input_port_c` | established |  |  | Flags 0xb. |

### Register `porta_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `portb_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `portg_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `porth_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `portlb_arbl_d_count_init`

PROM register R4_PORTLB_ARBL_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `portc_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `portd_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `porte_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `portf_d_count_init`

PROM register R4_PORTA_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `portlb_arbr_d_count_init`

PROM register R4_PORTLB_ARBR_D_COUNT_INIT. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `d_init_vc3` | established |  |  | Flags 0xb. |
| 23:16 | `d_init_vc2` | established |  |  | Flags 0xb. |
| 15:8 | `d_init_vc1` | established |  |  | Flags 0xb. |
| 7:0 | `d_init_vc0` | established |  |  | Flags 0xb. |

### Register `throttle_enable_arbl`

PROM register R4_THROTTLE_ENABLE_ARBL. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `inputh_vc3_enable` | established |  |  | Flags 0xb. |
| 30 | `inputh_vc2_enable` | established |  |  | Flags 0xb. |
| 29 | `inputh_vc1_enable` | established |  |  | Flags 0xb. |
| 28 | `inputh_vc0_enable` | established |  |  | Flags 0xb. |
| 27 | `inputg_vc3_enable` | established |  |  | Flags 0xb. |
| 26 | `inputg_vc2_enable` | established |  |  | Flags 0xb. |
| 25 | `inputg_vc1_enable` | established |  |  | Flags 0xb. |
| 24 | `inputg_vc0_enable` | established |  |  | Flags 0xb. |
| 23 | `inputf_vc3_enable` | established |  |  | Flags 0xb. |
| 22 | `inputf_vc2_enable` | established |  |  | Flags 0xb. |
| 21 | `inputf_vc1_enable` | established |  |  | Flags 0xb. |
| 20 | `inputf_vc0_enable` | established |  |  | Flags 0xb. |
| 19 | `inpute_vc3_enable` | established |  |  | Flags 0xb. |
| 18 | `inpute_vc2_enable` | established |  |  | Flags 0xb. |
| 17 | `inpute_vc1_enable` | established |  |  | Flags 0xb. |
| 16 | `inpute_vc0_enable` | established |  |  | Flags 0xb. |
| 15 | `inputd_vc3_enable` | established |  |  | Flags 0xb. |
| 14 | `inputd_vc2_enable` | established |  |  | Flags 0xb. |
| 13 | `inputd_vc1_enable` | established |  |  | Flags 0xb. |
| 12 | `inputd_vc0_enable` | established |  |  | Flags 0xb. |
| 11 | `inputc_vc3_enable` | established |  |  | Flags 0xb. |
| 10 | `inputc_vc2_enable` | established |  |  | Flags 0xb. |
| 9 | `inputc_vc1_enable` | established |  |  | Flags 0xb. |
| 8 | `inputc_vc0_enable` | established |  |  | Flags 0xb. |
| 7 | `inputb_vc3_enable` | established |  |  | Flags 0xb. |
| 6 | `inputb_vc2_enable` | established |  |  | Flags 0xb. |
| 5 | `inputb_vc1_enable` | established |  |  | Flags 0xb. |
| 4 | `inputb_vc0_enable` | established |  |  | Flags 0xb. |
| 3 | `inputa_vc3_enable` | established |  |  | Flags 0xb. |
| 2 | `inputa_vc2_enable` | established |  |  | Flags 0xb. |
| 1 | `inputa_vc1_enable` | established |  |  | Flags 0xb. |
| 0 | `inputa_vc0_enable` | established |  |  | Flags 0xb. |

### Register `throttle_enable_arbr`

PROM register R4_THROTTLE_ENABLE_ARBR. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `inputh_vc3_enable` | established |  |  | Flags 0xb. |
| 30 | `inputh_vc2_enable` | established |  |  | Flags 0xb. |
| 29 | `inputh_vc1_enable` | established |  |  | Flags 0xb. |
| 28 | `inputh_vc0_enable` | established |  |  | Flags 0xb. |
| 27 | `inputg_vc3_enable` | established |  |  | Flags 0xb. |
| 26 | `inputg_vc2_enable` | established |  |  | Flags 0xb. |
| 25 | `inputg_vc1_enable` | established |  |  | Flags 0xb. |
| 24 | `inputg_vc0_enable` | established |  |  | Flags 0xb. |
| 23 | `inputf_vc3_enable` | established |  |  | Flags 0xb. |
| 22 | `inputf_vc2_enable` | established |  |  | Flags 0xb. |
| 21 | `inputf_vc1_enable` | established |  |  | Flags 0xb. |
| 20 | `inputf_vc0_enable` | established |  |  | Flags 0xb. |
| 19 | `inpute_vc3_enable` | established |  |  | Flags 0xb. |
| 18 | `inpute_vc2_enable` | established |  |  | Flags 0xb. |
| 17 | `inpute_vc1_enable` | established |  |  | Flags 0xb. |
| 16 | `inpute_vc0_enable` | established |  |  | Flags 0xb. |
| 15 | `inputd_vc3_enable` | established |  |  | Flags 0xb. |
| 14 | `inputd_vc2_enable` | established |  |  | Flags 0xb. |
| 13 | `inputd_vc1_enable` | established |  |  | Flags 0xb. |
| 12 | `inputd_vc0_enable` | established |  |  | Flags 0xb. |
| 11 | `inputc_vc3_enable` | established |  |  | Flags 0xb. |
| 10 | `inputc_vc2_enable` | established |  |  | Flags 0xb. |
| 9 | `inputc_vc1_enable` | established |  |  | Flags 0xb. |
| 8 | `inputc_vc0_enable` | established |  |  | Flags 0xb. |
| 7 | `inputb_vc3_enable` | established |  |  | Flags 0xb. |
| 6 | `inputb_vc2_enable` | established |  |  | Flags 0xb. |
| 5 | `inputb_vc1_enable` | established |  |  | Flags 0xb. |
| 4 | `inputb_vc0_enable` | established |  |  | Flags 0xb. |
| 3 | `inputa_vc3_enable` | established |  |  | Flags 0xb. |
| 2 | `inputa_vc2_enable` | established |  |  | Flags 0xb. |
| 1 | `inputa_vc1_enable` | established |  |  | Flags 0xb. |
| 0 | `inputa_vc0_enable` | established |  |  | Flags 0xb. |

### Register `age_rate_port`

PROM register R4_AGE_RATE_PORTA; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `age_rate_enable` | established |  |  | Flags 0xb. |
| 60:56 | `age_range_7_trigger` | established |  |  | Flags 0xb. |
| 52:48 | `age_range_6_trigger` | established |  |  | Flags 0xb. |
| 44:40 | `age_range_5_trigger` | established |  |  | Flags 0xb. |
| 36:32 | `age_range_4_trigger` | established |  |  | Flags 0xb. |
| 28:24 | `age_range_3_trigger` | established |  |  | Flags 0xb. |
| 20:16 | `age_range_2_trigger` | established |  |  | Flags 0xb. |
| 12:8 | `age_range_1_trigger` | established |  |  | Flags 0xb. |
| 4:0 | `age_range_0_trigger` | established |  |  | Flags 0xb. |

### Register `age_rate_portlb`

PROM register R4_AGE_RATE_PORTLB. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `age_rate_enable` | established |  |  | Flags 0xb. |
| 60:56 | `age_range_7_trigger` | established |  |  | Flags 0xb. |
| 52:48 | `age_range_6_trigger` | established |  |  | Flags 0xb. |
| 44:40 | `age_range_5_trigger` | established |  |  | Flags 0xb. |
| 36:32 | `age_range_4_trigger` | established |  |  | Flags 0xb. |
| 28:24 | `age_range_3_trigger` | established |  |  | Flags 0xb. |
| 20:16 | `age_range_2_trigger` | established |  |  | Flags 0xb. |
| 12:8 | `age_range_1_trigger` | established |  |  | Flags 0xb. |
| 4:0 | `age_range_0_trigger` | established |  |  | Flags 0xb. |

### Register `arbl_test_point_select_512`

PROM register R4_ARBL_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `arbr_test_point_select_512`

PROM register R4_ARBR_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `cdq0_test_point_select_512`

PROM register R4_CDQ0_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `cdq1_test_point_select_512`

PROM register R4_CDQ1_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `cdq2_test_point_select_512`

PROM register R4_CDQ2_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `cdq3_test_point_select_512`

PROM register R4_CDQ3_TEST_POINT_SELECT_512. Offset and field positions read from the table; role inferred from the names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `port_local_table`

PROM register R4_PORTA_LOCAL_TABLE; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 4:0 | `dir0` | established |  |  | Flags 0xb. |

### Register `port_global_table`

PROM register R4_PORTA_GLOBAL_TABLE; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 4:0 | `dir0` | established |  |  | Flags 0xb. |

### Register `port_neighbor_table`

PROM register R4_PORTA_NEIGHBOR_TABLE; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  | Flags 0xb. |
| 13:0 | `neighbor_id` | established |  |  | Flags 0xb. |

### Register `port_parms`

PROM register R4_PORTA_PARMS; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37:30 | `spare` | established |  |  | Flags 0xb. |
| 29 | `v_bit_emulation` | established |  |  | Flags 0xb. |
| 28 | `new_dir_spray_enable` | established |  |  | Flags 0xb. |
| 27 | `dir_spray_enable` | established |  |  | Flags 0xb. |
| 26 | `extend_enable` | established |  |  | Flags 0xb. |
| 25 | `extend_shub_input` | established |  |  | Flags 0xb. |
| 24:17 | `extend_shub_dir_vec` | established |  |  | Flags 0xb. |
| 16 | `arm_force_cb_error` | established |  |  | Flags 0x7. |
| 15 | `linkreset_on_bufferoverflow` | established |  |  | Flags 0xb. |
| 14 | `eatuntiltail_on_bufferoverflow` | established |  |  | Flags 0xb. |
| 13 | `linkreset_on_fifooverflow` | established |  |  | Flags 0xb. |
| 12 | `send_deadlock_eat_enable_vch3` | established |  |  | Flags 0xb. |
| 11 | `send_deadlock_eat_enable_vch2` | established |  |  | Flags 0xb. |
| 10 | `send_deadlock_eat_enable_vch1` | established |  |  | Flags 0xb. |
| 9 | `send_deadlock_eat_enable_vch0` | established |  |  | Flags 0xb. |
| 8 | `tail_to_error_tail_enable_vch3` | established |  |  | Flags 0xb. |
| 7 | `tail_to_error_tail_enable_vch2` | established |  |  | Flags 0xb. |
| 6 | `tail_to_error_tail_enable_vch1` | established |  |  | Flags 0xb. |
| 5 | `tail_to_error_tail_enable_vch0` | established |  |  | Flags 0xb. |
| 4 | `mip_reset_enable` | established |  |  | Flags 0xb. |
| 3:0 | `send_deadlock_to_val` | established |  |  | Flags 0xb. |

### Register `port_spray_dir`

PROM register R4_PORTA_SPRAY_DIR; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `dir7` | established |  |  | Flags 0xb. |
| 55:48 | `dir6` | established |  |  | Flags 0xb. |
| 47:40 | `dir5` | established |  |  | Flags 0xb. |
| 39:32 | `dir4` | established |  |  | Flags 0xb. |
| 31:24 | `dir3` | established |  |  | Flags 0xb. |
| 23:16 | `dir2` | established |  |  | Flags 0xb. |
| 15:8 | `dir1` | established |  |  | Flags 0xb. |

### Register `port_spray_cmd_3f_0`

PROM register R4_PORTA_SPRAY_CMD_3F_0; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `mask` | established |  |  | Flags 0xb. |

### Register `port_spray_cmd_7f_40`

PROM register R4_PORTA_SPRAY_CMD_7F_40; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `mask` | established |  |  | Flags 0xb. |

### Register `port_spray_cmd_bf_80`

PROM register R4_PORTA_SPRAY_CMD_BF_80; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `mask` | established |  |  | Flags 0xb. |

### Register `port_spray_cmd_ff_c0`

PROM register R4_PORTA_SPRAY_CMD_FF_C0; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `mask` | established |  |  | Flags 0xb. |

### Register `port_llp_config`

PROM register R4_PORTA_LLP_CONFIG; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `enable_rmt_ft_upd` | established |  |  | Flags 0xb. |
| 3 | `enable_tuning` | established |  |  | Flags 0xb. |
| 2 | `ac_encode` | established |  |  | Flags 0xb. |
| 1 | `enablelink` | established |  |  | Flags 0xb. |
| 0 | `bitmode32` | established |  |  | Flags 0xb. |

### Register `port_llp_test_ctl`

PROM register R4_PORTA_LLP_TEST_CTL; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62 | `cb_error` | established |  |  | Flags 0xb. |
| 61 | `captured` | established |  |  | Flags 0xb. |
| 60 | `fakesnerror` | established |  |  | Flags 0x7. |
| 59 | `send_sn_error` | established |  |  | Flags 0x7. |
| 58 | `send_cb_error` | established |  |  | Flags 0x7. |
| 57 | `capture_cb_only` | established |  |  | Flags 0xb. |
| 56 | `arm_capture` | established |  |  | Flags 0x7. |
| 55:54 | `noise_mode` | established |  |  | Flags 0xb. |
| 53:52 | `lfsr_mode` | established |  |  | Flags 0xb. |
| 49:44 | `wire_sel` | established |  |  | Flags 0xb. |
| 41:40 | `send_test_mode` | established |  |  | Flags 0xb. |
| 39:0 | `pattern` | established |  |  | Flags 0xb. |

### Register `port_llp_state`

PROM register R4_PORTA_LLP_STATE; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:10 | `link_send_fsm_state` | established |  |  | Flags 0x1. |
| 9:4 | `link_rcv_fsm_state` | established |  |  | Flags 0x1. |
| 3:0 | `link_reset_state` | established |  |  | Flags 0x1. |

### Register `port_llp_err1`

PROM register R4_PORTA_LLP_ERR1; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:48 | `retry_count` | established |  |  | Flags 0xb. |
| 47:16 | `rx_cb_err_count` | established |  |  | Flags 0xb. |
| 15:0 | `rx_sn_err_count` | established |  |  | Flags 0xb. |

### Register `port_llp_err2`

PROM register R4_PORTA_LLP_ERR2; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:28 | `coresentbadcrc_count` | established |  |  | Flags 0xb. |
| 27 | `squash` | established |  |  | Flags 0xb. |
| 26 | `reset_timeout` | established |  |  | Flags 0xb. |
| 25 | `retry_timeout` | established |  |  | Flags 0xb. |
| 24 | `wire_overflow` | established |  |  | Flags 0xb. |
| 23:0 | `wire_cnt` | established |  |  | Flags 0xb. |

### Register `port_llp_capt_wd1`

PROM register R4_PORTA_LLP_CAPT_WD1; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `data` | established |  |  | Flags 0x1. |

### Register `port_llp_capt_wd2`

PROM register R4_PORTA_LLP_CAPT_WD2; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `data` | established |  |  | Flags 0x1. |

### Register `port_llp_capt_sbcb`

PROM register R4_PORTA_LLP_CAPT_SBCB; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 34 | `faked_all_sn_errors` | established |  |  | Flags 0x1. |
| 33 | `sent_all_sn_errors` | established |  |  | Flags 0x1. |
| 32 | `sent_all_cb_errors` | established |  |  | Flags 0x1. |
| 31:16 | `captured_rcv_crc` | established |  |  | Flags 0x1. |
| 15:0 | `captured_rcvsbsn` | established |  |  | Flags 0x1. |

### Register `port_credit`

PROM register R4_PORTA_CREDIT; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:56 | `send_limit_vch3` | established |  |  | Flags 0xb. |
| 54:48 | `send_limit_vch2` | established |  |  | Flags 0xb. |
| 46:40 | `send_limit_vch1` | established |  |  | Flags 0xb. |
| 38:32 | `send_limit_vch0` | established |  |  | Flags 0xb. |
| 29:24 | `rcv_initial_vch3` | established |  |  | Flags 0xb. |
| 21:16 | `rcv_initial_vch2` | established |  |  | Flags 0xb. |
| 13:8 | `rcv_initial_vch1` | established |  |  | Flags 0xb. |
| 5:0 | `rcv_initial_vch0` | established |  |  | Flags 0xb. |

### Register `port_debit`

PROM register R4_PORTA_DEBIT; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 36 | `en_short_interval` | established |  |  | Flags 0xb. |
| 35 | `en_xmitbuf_threshold` | established |  |  | Flags 0xb. |
| 34:32 | `credit_only_interval` | established |  |  | Flags 0xb. |
| 30 | `force_debit_vch3` | established |  |  | Flags 0x7. |
| 29:24 | `withhold_vch3` | established |  |  | Flags 0xb. |
| 22 | `force_debit_vch2` | established |  |  | Flags 0x7. |
| 21:16 | `withhold_vch2` | established |  |  | Flags 0xb. |
| 14 | `force_debit_vch1` | established |  |  | Flags 0x7. |
| 13:8 | `withhold_vch1` | established |  |  | Flags 0xb. |
| 6 | `force_debit_vch0` | established |  |  | Flags 0x7. |
| 5:0 | `withhold_vch0` | established |  |  | Flags 0xb. |

### Register `port_credit_state`

PROM register R4_PORTA_CREDIT_STATE; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `credits_vch3` | established |  |  | Flags 0x1. |
| 55:48 | `credits_vch2` | established |  |  | Flags 0x1. |
| 47:40 | `credits_vch1` | established |  |  | Flags 0x1. |
| 39:32 | `credits_vch0` | established |  |  | Flags 0x1. |
| 29:24 | `debits_vch3` | established |  |  | Flags 0x1. |
| 21:16 | `debits_vch2` | established |  |  | Flags 0x1. |
| 13:8 | `debits_vch1` | established |  |  | Flags 0x1. |
| 5:0 | `debits_vch0` | established |  |  | Flags 0x1. |

### Register `port_llp_pkt`

PROM register R4_PORTA_LLP_PKT; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `count` | established |  |  | Flags 0xb. |

### Register `port_error_detail`

PROM register R4_PORTA_ERROR_DETAIL; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `detail` | established |  |  | Flags 0x1. |

### Register `port_error_detail_clear`

PROM register R4_PORTA_ERROR_DETAIL_CLEAR; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  |  | Flags 0x7. |

### Register `port_error_summary`

PROM register R4_PORTA_ERROR_SUMMARY; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 46 | `extend_turn_err` | established |  |  | Flags 0xb. |
| 45 | `coresentbadcrc_cnt_non_zero` | established |  |  | Flags 0xb. |
| 44 | `retry_cnt_non_zero` | established |  |  | Flags 0xb. |
| 43 | `cb_error_cnt_non_zero` | established |  |  | Flags 0xb. |
| 42 | `sn_error_cnt_non_zero` | established |  |  | Flags 0xb. |
| 41 | `rcv_tail_to_vch3` | established |  |  | Flags 0xb. |
| 40 | `rcv_tail_to_vch2` | established |  |  | Flags 0xb. |
| 39 | `rcv_tail_to_vch1` | established |  |  | Flags 0xb. |
| 38 | `rcv_tail_to_vch0` | established |  |  | Flags 0xb. |
| 37 | `send_deadlock_to_vch3` | established |  |  | Flags 0xb. |
| 36 | `send_deadlock_to_vch2` | established |  |  | Flags 0xb. |
| 35 | `send_deadlock_to_vch1` | established |  |  | Flags 0xb. |
| 34 | `send_deadlock_to_vch0` | established |  |  | Flags 0xb. |
| 33 | `damq_deadlock_to_vch3` | established |  |  | Flags 0xb. |
| 32 | `damq_deadlock_to_vch2` | established |  |  | Flags 0xb. |
| 31 | `damq_deadlock_to_vch1` | established |  |  | Flags 0xb. |
| 30 | `damq_deadlock_to_vch0` | established |  |  | Flags 0xb. |
| 29 | `invalid_global_lu_vch3` | established |  |  | Flags 0xb. |
| 28 | `invalid_global_lu_vch2` | established |  |  | Flags 0xb. |
| 27 | `invalid_global_lu_vch1` | established |  |  | Flags 0xb. |
| 26 | `invalid_global_lu_vch0` | established |  |  | Flags 0xb. |
| 25 | `invalid_local_lu_vch3` | established |  |  | Flags 0xb. |
| 24 | `invalid_local_lu_vch2` | established |  |  | Flags 0xb. |
| 23 | `invalid_local_lu_vch1` | established |  |  | Flags 0xb. |
| 22 | `invalid_local_lu_vch0` | established |  |  | Flags 0xb. |
| 21 | `dateline_error_vch3` | established |  |  | Flags 0xb. |
| 20 | `dateline_error_vch1` | established |  |  | Flags 0xb. |
| 19 | `illegal_dir_vch3` | established |  |  | Flags 0xb. |
| 18 | `illegal_dir_vch2` | established |  |  | Flags 0xb. |
| 17 | `illegal_dir_vch1` | established |  |  | Flags 0xb. |
| 16 | `illegal_dir_vch0` | established |  |  | Flags 0xb. |
| 15 | `credit_overflow_vch3` | established |  |  | Flags 0xb. |
| 14 | `credit_overflow_vch2` | established |  |  | Flags 0xb. |
| 13 | `credit_overflow_vch1` | established |  |  | Flags 0xb. |
| 12 | `credit_overflow_vch0` | established |  |  | Flags 0xb. |
| 11 | `fifo_overflow_vch3` | established |  |  | Flags 0xb. |
| 10 | `fifo_overflow_vch2` | established |  |  | Flags 0xb. |
| 9 | `fifo_overflow_vch1` | established |  |  | Flags 0xb. |
| 8 | `fifo_overflow_vch0` | established |  |  | Flags 0xb. |
| 7 | `buffer_overflow_vch3` | established |  |  | Flags 0xb. |
| 6 | `buffer_overflow_vch2` | established |  |  | Flags 0xb. |
| 5 | `buffer_overflow_vch1` | established |  |  | Flags 0xb. |
| 4 | `buffer_overflow_vch0` | established |  |  | Flags 0xb. |
| 3 | `retry_to` | established |  |  | Flags 0xb. |
| 2 | `rcv_link_reset` | established |  |  | Flags 0xb. |
| 1 | `rcv_warm_reset` | established |  |  | Flags 0xb. |
| 0 | `power_not_ok` | established |  |  | Flags 0xb. |

### Register `port_first_error`

PROM register R4_PORTA_FIRST_ERROR; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 46 | `extend_turn_err` | established |  |  | Flags 0xb. |
| 45 | `coresentbadcrc_cnt_non_zero` | established |  |  | Flags 0xb. |
| 44 | `retry_cnt_non_zero` | established |  |  | Flags 0xb. |
| 43 | `cb_error_cnt_non_zero` | established |  |  | Flags 0xb. |
| 42 | `sn_error_cnt_non_zero` | established |  |  | Flags 0xb. |
| 41 | `rcv_tail_to_vch3` | established |  |  | Flags 0xb. |
| 40 | `rcv_tail_to_vch2` | established |  |  | Flags 0xb. |
| 39 | `rcv_tail_to_vch1` | established |  |  | Flags 0xb. |
| 38 | `rcv_tail_to_vch0` | established |  |  | Flags 0xb. |
| 37 | `send_deadlock_to_vch3` | established |  |  | Flags 0xb. |
| 36 | `send_deadlock_to_vch2` | established |  |  | Flags 0xb. |
| 35 | `send_deadlock_to_vch1` | established |  |  | Flags 0xb. |
| 34 | `send_deadlock_to_vch0` | established |  |  | Flags 0xb. |
| 33 | `damq_deadlock_to_vch3` | established |  |  | Flags 0xb. |
| 32 | `damq_deadlock_to_vch2` | established |  |  | Flags 0xb. |
| 31 | `damq_deadlock_to_vch1` | established |  |  | Flags 0xb. |
| 30 | `damq_deadlock_to_vch0` | established |  |  | Flags 0xb. |
| 29 | `invalid_global_lu_vch3` | established |  |  | Flags 0xb. |
| 28 | `invalid_global_lu_vch2` | established |  |  | Flags 0xb. |
| 27 | `invalid_global_lu_vch1` | established |  |  | Flags 0xb. |
| 26 | `invalid_global_lu_vch0` | established |  |  | Flags 0xb. |
| 25 | `invalid_local_lu_vch3` | established |  |  | Flags 0xb. |
| 24 | `invalid_local_lu_vch2` | established |  |  | Flags 0xb. |
| 23 | `invalid_local_lu_vch1` | established |  |  | Flags 0xb. |
| 22 | `invalid_local_lu_vch0` | established |  |  | Flags 0xb. |
| 21 | `dateline_error_vch3` | established |  |  | Flags 0xb. |
| 20 | `dateline_error_vch1` | established |  |  | Flags 0xb. |
| 19 | `illegal_dir_vch3` | established |  |  | Flags 0xb. |
| 18 | `illegal_dir_vch2` | established |  |  | Flags 0xb. |
| 17 | `illegal_dir_vch1` | established |  |  | Flags 0xb. |
| 16 | `illegal_dir_vch0` | established |  |  | Flags 0xb. |
| 15 | `credit_overflow_vch3` | established |  |  | Flags 0xb. |
| 14 | `credit_overflow_vch2` | established |  |  | Flags 0xb. |
| 13 | `credit_overflow_vch1` | established |  |  | Flags 0xb. |
| 12 | `credit_overflow_vch0` | established |  |  | Flags 0xb. |
| 11 | `fifo_overflow_vch3` | established |  |  | Flags 0xb. |
| 10 | `fifo_overflow_vch2` | established |  |  | Flags 0xb. |
| 9 | `fifo_overflow_vch1` | established |  |  | Flags 0xb. |
| 8 | `fifo_overflow_vch0` | established |  |  | Flags 0xb. |
| 7 | `buffer_overflow_vch3` | established |  |  | Flags 0xb. |
| 6 | `buffer_overflow_vch2` | established |  |  | Flags 0xb. |
| 5 | `buffer_overflow_vch1` | established |  |  | Flags 0xb. |
| 4 | `buffer_overflow_vch0` | established |  |  | Flags 0xb. |
| 3 | `retry_to` | established |  |  | Flags 0xb. |
| 2 | `rcv_link_reset` | established |  |  | Flags 0xb. |
| 1 | `rcv_warm_reset` | established |  |  | Flags 0xb. |
| 0 | `power_not_ok` | established |  |  | Flags 0xb. |

### Register `port_error_report_mask`

PROM register R4_PORTA_ERROR_REPORT_MASK; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 46 | `extend_turn_err` | established |  |  | Flags 0xb. |
| 45 | `coresentbadcrc_cnt_non_zero` | established |  |  | Flags 0xb. |
| 44 | `retry_cnt_non_zero` | established |  |  | Flags 0xb. |
| 43 | `cb_error_cnt_non_zero` | established |  |  | Flags 0xb. |
| 42 | `sn_error_cnt_non_zero` | established |  |  | Flags 0xb. |
| 41 | `rcv_tail_to_vch3` | established |  |  | Flags 0xb. |
| 40 | `rcv_tail_to_vch2` | established |  |  | Flags 0xb. |
| 39 | `rcv_tail_to_vch1` | established |  |  | Flags 0xb. |
| 38 | `rcv_tail_to_vch0` | established |  |  | Flags 0xb. |
| 37 | `send_deadlock_to_vch3` | established |  |  | Flags 0xb. |
| 36 | `send_deadlock_to_vch2` | established |  |  | Flags 0xb. |
| 35 | `send_deadlock_to_vch1` | established |  |  | Flags 0xb. |
| 34 | `send_deadlock_to_vch0` | established |  |  | Flags 0xb. |
| 33 | `damq_deadlock_to_vch3` | established |  |  | Flags 0xb. |
| 32 | `damq_deadlock_to_vch2` | established |  |  | Flags 0xb. |
| 31 | `damq_deadlock_to_vch1` | established |  |  | Flags 0xb. |
| 30 | `damq_deadlock_to_vch0` | established |  |  | Flags 0xb. |
| 29 | `invalid_global_lu_vch3` | established |  |  | Flags 0xb. |
| 28 | `invalid_global_lu_vch2` | established |  |  | Flags 0xb. |
| 27 | `invalid_global_lu_vch1` | established |  |  | Flags 0xb. |
| 26 | `invalid_global_lu_vch0` | established |  |  | Flags 0xb. |
| 25 | `invalid_local_lu_vch3` | established |  |  | Flags 0xb. |
| 24 | `invalid_local_lu_vch2` | established |  |  | Flags 0xb. |
| 23 | `invalid_local_lu_vch1` | established |  |  | Flags 0xb. |
| 22 | `invalid_local_lu_vch0` | established |  |  | Flags 0xb. |
| 21 | `dateline_error_vch3` | established |  |  | Flags 0xb. |
| 20 | `dateline_error_vch1` | established |  |  | Flags 0xb. |
| 19 | `illegal_dir_vch3` | established |  |  | Flags 0xb. |
| 18 | `illegal_dir_vch2` | established |  |  | Flags 0xb. |
| 17 | `illegal_dir_vch1` | established |  |  | Flags 0xb. |
| 16 | `illegal_dir_vch0` | established |  |  | Flags 0xb. |
| 15 | `credit_overflow_vch3` | established |  |  | Flags 0xb. |
| 14 | `credit_overflow_vch2` | established |  |  | Flags 0xb. |
| 13 | `credit_overflow_vch1` | established |  |  | Flags 0xb. |
| 12 | `credit_overflow_vch0` | established |  |  | Flags 0xb. |
| 11 | `fifo_overflow_vch3` | established |  |  | Flags 0xb. |
| 10 | `fifo_overflow_vch2` | established |  |  | Flags 0xb. |
| 9 | `fifo_overflow_vch1` | established |  |  | Flags 0xb. |
| 8 | `fifo_overflow_vch0` | established |  |  | Flags 0xb. |
| 7 | `buffer_overflow_vch3` | established |  |  | Flags 0xb. |
| 6 | `buffer_overflow_vch2` | established |  |  | Flags 0xb. |
| 5 | `buffer_overflow_vch1` | established |  |  | Flags 0xb. |
| 4 | `buffer_overflow_vch0` | established |  |  | Flags 0xb. |
| 3 | `retry_to` | established |  |  | Flags 0xb. |
| 2 | `rcv_link_reset` | established |  |  | Flags 0xb. |
| 1 | `rcv_warm_reset` | established |  |  | Flags 0xb. |
| 0 | `power_not_ok` | established |  |  | Flags 0xb. |

### Register `port_test_point_select_512`

PROM register R4_PORTA_TEST_POINT_SELECT_512; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `nibble7_nibble_sel` | established |  |  | Flags 0xb. |
| 59:56 | `nibble7_chiplet_sel` | established |  |  | Flags 0xb. |
| 54:52 | `nibble6_nibble_sel` | established |  |  | Flags 0xb. |
| 51:48 | `nibble6_chiplet_sel` | established |  |  | Flags 0xb. |
| 46:44 | `nibble5_nibble_sel` | established |  |  | Flags 0xb. |
| 43:40 | `nibble5_chiplet_sel` | established |  |  | Flags 0xb. |
| 38:36 | `nibble4_nibble_sel` | established |  |  | Flags 0xb. |
| 35:32 | `nibble4_chiplet_sel` | established |  |  | Flags 0xb. |
| 30:28 | `nibble3_nibble_sel` | established |  |  | Flags 0xb. |
| 27:24 | `nibble3_chiplet_sel` | established |  |  | Flags 0xb. |
| 22:20 | `nibble2_nibble_sel` | established |  |  | Flags 0xb. |
| 19:16 | `nibble2_chiplet_sel` | established |  |  | Flags 0xb. |
| 14:12 | `nibble1_nibble_sel` | established |  |  | Flags 0xb. |
| 11:8 | `nibble1_chiplet_sel` | established |  |  | Flags 0xb. |
| 6:4 | `nibble0_nibble_sel` | established |  |  | Flags 0xb. |
| 3:0 | `nibble0_chiplet_sel` | established |  |  | Flags 0xb. |

### Register `port_perf_config`

PROM register R4_PORTA_PERF_CONFIG; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:45 | `diag` | established |  |  | Flags 0xb. |
| 44:8 | `en` | established |  |  | Flags 0xb. |
| 7:0 | `dir` | established |  |  | Flags 0xb. |

### Register `port_perf_cmd_lo`

PROM register R4_PORTA_PERF_CMD_LO; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `cnt7` | established |  |  | Flags 0xb. |
| 55:48 | `cnt6` | established |  |  | Flags 0xb. |
| 47:40 | `cnt5` | established |  |  | Flags 0xb. |
| 39:32 | `cnt4` | established |  |  | Flags 0xb. |
| 31:24 | `cnt3` | established |  |  | Flags 0xb. |
| 23:16 | `cnt2` | established |  |  | Flags 0xb. |
| 15:8 | `cnt1` | established |  |  | Flags 0xb. |
| 7:0 | `cnt0` | established |  |  | Flags 0xb. |

### Register `port_perf_cmd_up`

PROM register R4_PORTA_PERF_CMD_UP; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `cnt7` | established |  |  | Flags 0xb. |
| 55:48 | `cnt6` | established |  |  | Flags 0xb. |
| 47:40 | `cnt5` | established |  |  | Flags 0xb. |
| 39:32 | `cnt4` | established |  |  | Flags 0xb. |
| 31:24 | `cnt3` | established |  |  | Flags 0xb. |
| 23:16 | `cnt2` | established |  |  | Flags 0xb. |
| 15:8 | `cnt1` | established |  |  | Flags 0xb. |
| 7:0 | `cnt0` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr0`

PROM register R4_PORTA_PERF_CNTR0; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr1`

PROM register R4_PORTA_PERF_CNTR1; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr2`

PROM register R4_PORTA_PERF_CNTR2; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr3`

PROM register R4_PORTA_PERF_CNTR3; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr4`

PROM register R4_PORTA_PERF_CNTR4; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr5`

PROM register R4_PORTA_PERF_CNTR5; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr6`

PROM register R4_PORTA_PERF_CNTR6; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr7`

PROM register R4_PORTA_PERF_CNTR7; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr8`

PROM register R4_PORTA_PERF_CNTR8; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr9`

PROM register R4_PORTA_PERF_CNTR9; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr10`

PROM register R4_PORTA_PERF_CNTR10; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr11`

PROM register R4_PORTA_PERF_CNTR11; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr12`

PROM register R4_PORTA_PERF_CNTR12; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr13`

PROM register R4_PORTA_PERF_CNTR13; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr14`

PROM register R4_PORTA_PERF_CNTR14; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr15`

PROM register R4_PORTA_PERF_CNTR15; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr16`

PROM register R4_PORTA_PERF_CNTR16; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr17`

PROM register R4_PORTA_PERF_CNTR17; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr18`

PROM register R4_PORTA_PERF_CNTR18; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr19`

PROM register R4_PORTA_PERF_CNTR19; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr20`

PROM register R4_PORTA_PERF_CNTR20; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr21`

PROM register R4_PORTA_PERF_CNTR21; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr22`

PROM register R4_PORTA_PERF_CNTR22; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr23`

PROM register R4_PORTA_PERF_CNTR23; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr24`

PROM register R4_PORTA_PERF_CNTR24; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr25`

PROM register R4_PORTA_PERF_CNTR25; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr26`

PROM register R4_PORTA_PERF_CNTR26; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr27`

PROM register R4_PORTA_PERF_CNTR27; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr28`

PROM register R4_PORTA_PERF_CNTR28; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr29`

PROM register R4_PORTA_PERF_CNTR29; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr30`

PROM register R4_PORTA_PERF_CNTR30; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr31`

PROM register R4_PORTA_PERF_CNTR31; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr32`

PROM register R4_PORTA_PERF_CNTR32; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr33`

PROM register R4_PORTA_PERF_CNTR33; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr34`

PROM register R4_PORTA_PERF_CNTR34; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr35`

PROM register R4_PORTA_PERF_CNTR35; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

### Register `port_perf_cntr36`

PROM register R4_PORTA_PERF_CNTR36; one per port A to H. Offset and field positions read from the table; role inferred from the names.

Array of 8 registers, stride 16777216.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:0 | `cnt` | established |  |  | Flags 0xb. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `MAX_PORTS` | 0x8 | established |  | Ports lettered A to H in the table; the Dense router and the R-brick manuals describe an eight-port crossbar (007-4823-001 p.61). |
| `PORT_BLOCK_STRIDE` | 0x1000000 | established |  | Distance between one port's block and the next for every register inside the port blocks (port A first, port H last). |
