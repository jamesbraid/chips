<!-- generated from devices/hub/registers.toml by defs-gen - do not edit, change the source -->

# Hub (Origin 2000 node controller)

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout.

Unit `hub`, macro prefix `HUB`.
Default source: census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pi_region_present` | 0x18 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_cpu_num` | 0x20 | rw | 64 |  |  | unknown | established | census: 136 sites, 20 routines |
| `pi_calias_size` | 0x28 | rw | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_max_crb_timeout` | 0x30 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `pi_crb_sfactor` | 0x38 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `pi_cpu_present_a` | 0x40 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_cpu_present_b` | 0x48 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `pi_cpu_enable_a` | 0x50 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_cpu_enable_b` | 0x58 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_nmi_a` | 0x70 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_int_pend_mod` | 0x90 | w | 64 |  |  | unknown | established | census: 9 sites, 8 routines |
| `pi_int_pend0` | 0x98 | r | 64 |  |  | unknown | established | census: 11 sites, 8 routines |
| `pi_int_pend1` | 0xa0 | r | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `pi_int_mask0_a` | 0xa8 | rw | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `pi_int_mask1_a` | 0xb0 | rw | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `pi_int_mask0_b` | 0xb8 | rw | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_int_mask1_b` | 0xc0 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `pi_rt_compare_a` | 0x108 | w | 64 |  |  | unknown | established | census: 25 sites, 6 routines |
| `pi_rt_compare_b` | 0x110 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_profile_compare` | 0x118 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_rt_pend_a` | 0x120 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_rt_pend_b` | 0x128 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_prof_pend_a` | 0x130 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_prof_pend_b` | 0x138 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_rt_en_a` | 0x140 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_rt_en_b` | 0x148 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_prof_en_a` | 0x150 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_prof_en_b` | 0x158 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_rt_local_ctrl` | 0x160 | rw | 64 |  |  | unknown | established | census: 6 sites, 1 routines |
| `pi_gfx_int_cmp_a` | 0x320 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_gfx_int_cmp_b` | 0x348 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_err_int_pend` | 0x400 | rw | 64 |  |  | unknown | established | census: 13 sites, 5 routines |
| `pi_err_int_mask_a` | 0x408 | rw | 64 |  |  | unknown | established | census: 5 sites, 2 routines |
| `pi_err_int_mask_b` | 0x410 | rw | 64 |  |  | unknown | established | census: 5 sites, 2 routines |
| `pi_err_stack_addr_a` | 0x418 | r | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `pi_err_stack_addr_b` | 0x420 | rw | 64 |  |  | unknown | established | census: 7 sites, 3 routines |
| `pi_err_stack_size` | 0x428 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `pi_err_status0_a` | 0x430 | r | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `pi_err_status1_a` | 0x440 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_err_status1_a_rclr` | 0x448 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_err_status0_b` | 0x450 | r | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `pi_err_status1_b` | 0x460 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_err_status1_b_rclr` | 0x468 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_hardreset_bit` | 0x20068 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pi_rt_count` | 0x30100 | rw | 64 |  |  | unknown | established | census: 161 sites, 80 routines |
| `md_memory_config` | 0x200018 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `md_refresh_control` | 0x200020 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_fandop_cac_stat` | 0x200028 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_mig_diff_thresh` | 0x200030 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `md_mig_value_thresh` | 0x200038 | rw | 64 |  |  | unknown | established | census: 10 sites, 5 routines |
| `md_mig_candidate_clr` | 0x200048 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_dir_error` | 0x200050 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_dir_error_clr` | 0x200058 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_protocol_error` | 0x200060 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_protocol_error_clr` | 0x200068 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_mem_error` | 0x200070 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_mem_error_clr` | 0x200078 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_misc_error` | 0x200080 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_misc_error_clr` | 0x200088 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_moq_size` | 0x2000a0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_mlan_ctl` | 0x2000a8 | rw | 64 |  |  | unknown | established | census: 6 sites, 1 routines |
| `per_hub_init` | 0x2000c8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_ifdr_fix_value` | 0x2000d0 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_ifdr_fix_value_2000d8` | 0x2000d8 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `per_hub_init_2000e0` | 0x2000e0 | rw | 64 |  |  | unknown | established | census: 3 sites, 1 routines |
| `md_perf_sel` | 0x210000 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_perf_cnt0` | 0x210010 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_ureg0_0` | 0x220000 | w | 64 |  |  | unknown | established | census: 6 sites, 2 routines |
| `md_ureg0_1` | 0x220008 | w | 64 |  |  | unknown | established | census: 9 sites, 2 routines |
| `md_slotid_ustat` | 0x220048 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_led0` | 0x220050 | w | 64 |  |  | unknown | established | census: 4 sites, 1 routines |
| `md_ureg1_0` | 0x220080 | w | 64 |  |  | unknown | established | census: 38 sites, 9 routines |
| `iio_wstat` | 0x400008 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_wcr` | 0x400020 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `iio_iowa` | 0x400110 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `iio_iiwa` | 0x400118 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `iio_iidem` | 0x400120 | rw | 64 |  |  | unknown | established | census: 5 sites, 3 routines |
| `iio_ilcsr` | 0x400128 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `iio_illr` | 0x400130 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `iio_iidsr` | 0x400138 | rw | 64 |  |  | unknown | established | census: 12 sites, 5 routines |
| `iio_igfx_0` | 0x400140 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hub_piomap_alloc` | 0x400160 | rw | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `mlreset` | 0x400190 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ioprb_0` | 0x400198 | rw | 64 |  |  | unknown | established | census: 7 sites, 4 routines |
| `iio_imem` | 0x4001e8 | rw | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `iio_ieclr` | 0x4001f8 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `iio_ibcn` | 0x400200 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hub_error_devenable` | 0x4002c8 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_prte_0` | 0x400308 | rw | 64 |  |  | unknown | established | census: 4 sites, 1 routines |
| `iio_ipdr` | 0x400388 | rw | 64 |  |  | unknown | established | census: 5 sites, 2 routines |
| `iio_icdr` | 0x400390 | rw | 64 |  |  | unknown | established | census: 3 sites, 1 routines |
| `iio_ifdr` | 0x400398 | rw | 64 |  |  | unknown | established | census: 8 sites, 3 routines |
| `iio_icmr` | 0x4003a8 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `iio_iccr` | 0x4003b0 | rw | 64 |  |  | unknown | established | census: 7 sites, 1 routines |
| `iio_icto` | 0x4003b8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ictp` | 0x4003c0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_icrb0_a` | 0x400400 | rw | 64 |  |  | unknown | established | census: 14 sites, 9 routines |
| `iio_icrb0_b` | 0x400408 | rw | 64 |  |  | unknown | established | census: 11 sites, 6 routines |
| `iio_icrb0_c` | 0x400410 | r | 64 |  |  | unknown | established | census: 6 sites, 5 routines |
| `iio_icrb0_d` | 0x400418 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `iio_icrb1_b` | 0x400428 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibls_0` | 0x410000 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibsa_0` | 0x410008 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibda_0` | 0x410010 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibct_0` | 0x410018 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibls_1` | 0x420000 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibsa_1` | 0x420008 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibda_1` | 0x420010 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ibct_1` | 0x420018 | rw | 64 |  |  | unknown | established | census: 3 sites, 1 routines |
| `iio_ibna_1` | 0x420020 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_ipcr` | 0x430000 | rw | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `iio_ippr` | 0x430008 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `ni_status_rev_id` | 0x600000 | r | 64 |  |  | unknown | established | census: 18 sites, 16 routines |
| `ni_port_reset` | 0x600008 | w | 64 |  |  | unknown | established | census: 6 sites, 6 routines |
| `ni_protection` | 0x600010 | r | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `ni_global_parms` | 0x600018 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `ni_scratch_reg0` | 0x600100 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ni_scratch_reg1` | 0x600108 | rw | 64 |  |  | unknown | established | census: 14 sites, 2 routines |
| `ni_diag_parms` | 0x600110 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `ni_vector_parms` | 0x600200 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `ni_vector` | 0x600208 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `ni_vector_data` | 0x600210 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `ni_vector_status` | 0x600300 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ni_vector_read_data` | 0x600310 | rw | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `ni_vector_clear` | 0x600380 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `ni_age_cpu0_memory` | 0x600500 | rw | 64 |  |  | unknown | established | census: 9 sites, 3 routines |
| `ni_age_cpu1_memory` | 0x600510 | rw | 64 |  |  | unknown | established | census: 9 sites, 3 routines |
| `ni_port_error` | 0x608008 | r | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `ni_port_error_clear` | 0x608088 | r | 64 |  |  | unknown | established | census: 10 sites, 4 routines |
| `ni_meta_table0` | 0x638000 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ni_local_table0` | 0x638100 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |

### Register `pi_region_present`

### Register `pi_cpu_num`

### Register `pi_calias_size`

### Register `pi_max_crb_timeout`

### Register `pi_crb_sfactor`

### Register `pi_cpu_present_a`

### Register `pi_cpu_present_b`

### Register `pi_cpu_enable_a`

### Register `pi_cpu_enable_b`

### Register `pi_nmi_a`

### Register `pi_int_pend_mod`

### Register `pi_int_pend0`

### Register `pi_int_pend1`

### Register `pi_int_mask0_a`

### Register `pi_int_mask1_a`

### Register `pi_int_mask0_b`

### Register `pi_int_mask1_b`

### Register `pi_rt_compare_a`

### Register `pi_rt_compare_b`

### Register `pi_profile_compare`

### Register `pi_rt_pend_a`

### Register `pi_rt_pend_b`

### Register `pi_prof_pend_a`

### Register `pi_prof_pend_b`

### Register `pi_rt_en_a`

### Register `pi_rt_en_b`

### Register `pi_prof_en_a`

### Register `pi_prof_en_b`

### Register `pi_rt_local_ctrl`

### Register `pi_gfx_int_cmp_a`

### Register `pi_gfx_int_cmp_b`

### Register `pi_err_int_pend`

### Register `pi_err_int_mask_a`

### Register `pi_err_int_mask_b`

### Register `pi_err_stack_addr_a`

### Register `pi_err_stack_addr_b`

### Register `pi_err_stack_size`

### Register `pi_err_status0_a`

### Register `pi_err_status1_a`

### Register `pi_err_status1_a_rclr`

### Register `pi_err_status0_b`

### Register `pi_err_status1_b`

### Register `pi_err_status1_b_rclr`

### Register `pi_hardreset_bit`

### Register `pi_rt_count`

### Register `md_memory_config`

### Register `md_refresh_control`

### Register `md_fandop_cac_stat`

### Register `md_mig_diff_thresh`

### Register `md_mig_value_thresh`

### Register `md_mig_candidate_clr`

### Register `md_dir_error`

### Register `md_dir_error_clr`

### Register `md_protocol_error`

### Register `md_protocol_error_clr`

### Register `md_mem_error`

### Register `md_mem_error_clr`

### Register `md_misc_error`

### Register `md_misc_error_clr`

### Register `md_moq_size`

### Register `md_mlan_ctl`

### Register `per_hub_init`

### Register `hub_ifdr_fix_value`

### Register `hub_ifdr_fix_value_2000d8`

### Register `per_hub_init_2000e0`

### Register `md_perf_sel`

### Register `md_perf_cnt0`

### Register `md_ureg0_0`

### Register `md_ureg0_1`

### Register `md_slotid_ustat`

### Register `md_led0`

### Register `md_ureg1_0`

### Register `iio_wstat`

### Register `iio_wcr`

### Register `iio_iowa`

### Register `iio_iiwa`

### Register `iio_iidem`

### Register `iio_ilcsr`

### Register `iio_illr`

### Register `iio_iidsr`

### Register `iio_igfx_0`

### Register `hub_piomap_alloc`

### Register `mlreset`

### Register `iio_ioprb_0`

### Register `iio_imem`

### Register `iio_ieclr`

### Register `iio_ibcn`

### Register `hub_error_devenable`

### Register `iio_prte_0`

### Register `iio_ipdr`

### Register `iio_icdr`

### Register `iio_ifdr`

### Register `iio_icmr`

### Register `iio_iccr`

### Register `iio_icto`

### Register `iio_ictp`

### Register `iio_icrb0_a`

### Register `iio_icrb0_b`

### Register `iio_icrb0_c`

### Register `iio_icrb0_d`

### Register `iio_icrb1_b`

### Register `iio_ibls_0`

### Register `iio_ibsa_0`

### Register `iio_ibda_0`

### Register `iio_ibct_0`

### Register `iio_ibls_1`

### Register `iio_ibsa_1`

### Register `iio_ibda_1`

### Register `iio_ibct_1`

### Register `iio_ibna_1`

### Register `iio_ipcr`

### Register `iio_ippr`

### Register `ni_status_rev_id`

### Register `ni_port_reset`

### Register `ni_protection`

### Register `ni_global_parms`

### Register `ni_scratch_reg0`

### Register `ni_scratch_reg1`

### Register `ni_diag_parms`

### Register `ni_vector_parms`

### Register `ni_vector`

### Register `ni_vector_data`

### Register `ni_vector_status`

### Register `ni_vector_read_data`

### Register `ni_vector_clear`

### Register `ni_age_cpu0_memory`

### Register `ni_age_cpu1_memory`

### Register `ni_port_error`

### Register `ni_port_error_clear`

### Register `ni_meta_table0`

### Register `ni_local_table0`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `HUB_IFDR_FIX_VALUE_2000D8_B_6_0` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_IFDR_FIX_VALUE_B_6_0` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_V_300` | 0x300 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IBCN_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IBCT_1_V_10` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IBLS_1_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IBLS_1_V_100000` | 0x100000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICDR_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICDR_V_10` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICMR_V_40` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB0_A_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB0_A_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB0_A_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB0_A_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB0_B_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB0_B_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICTO_V_FF` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICTP_V_1000` | 0x1000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IECLR_V_20000` | 0x20000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IECLR_V_FF0000` | 0xff0000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IECLR_V_FFFF` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IFDR_B_6_0` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IIDSR_V_1000000` | 0x1000000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ILCSR_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ILCSR_B_13` | 0x2000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ILCSR_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ILCSR_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ILLR_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IMEM_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IMEM_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IMEM_B_4_0` | 0x11 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IMEM_B_8` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IMEM_V_101` | 0x101 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IPDR_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IPDR_V_10` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_PRTE_0_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_WCR_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_23` | 0x23 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_2A` | 0x2a | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_2B` | 0x2b | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_31` | 0x31 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_35` | 0x35 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_36` | 0x36 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_3F` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_46` | 0x46 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_47` | 0x47 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_48` | 0x48 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_5D` | 0x5d | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_83` | 0x83 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_84` | 0x84 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_9` | 0x9 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_97` | 0x97 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_A` | 0xa | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_A6` | 0xa6 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_B` | 0xb | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_B4` | 0xb4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_C` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_CF` | 0xcf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_F` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_F3` | 0xf3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_LED0_V_FC` | 0xfc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_MEMORY_CONFIG_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_MEM_ERROR_CLR_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_MISC_ERROR_CLR_B_9_0` | 0x3ff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_MLAN_CTL_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_MLAN_CTL_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_REFRESH_CONTROL_B_11_0` | 0xfff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_SLOTID_USTAT_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_SLOTID_USTAT_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_1C` | 0x1c | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_7F` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_FE` | 0xfe | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_3` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_4_2_1` | 0x16 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_45` | 0x45 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_80` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_A0` | 0xa0 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_C0` | 0xc0 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_C5` | 0xc5 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_23` | 0x23 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_2A` | 0x2a | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_2B` | 0x2b | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_31` | 0x31 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_35` | 0x35 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_36` | 0x36 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_3F` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_46` | 0x46 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_47` | 0x47 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_48` | 0x48 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_5D` | 0x5d | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_83` | 0x83 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_84` | 0x84 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_97` | 0x97 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_A` | 0xa | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_A6` | 0xa6 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_B` | 0xb | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_B4` | 0xb4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_C` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_CF` | 0xcf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_F` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_F3` | 0xf3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_FC` | 0xfc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `NI_PORT_ERROR_CLEAR_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `NI_PORT_RESET_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `NI_PORT_RESET_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `NI_STATUS_REV_ID_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `NI_STATUS_REV_ID_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `NI_STATUS_REV_ID_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `NI_STATUS_REV_ID_B_8_0` | 0x1ff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PER_HUB_INIT_2000E0_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_CALIAS_SIZE_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_CALIAS_SIZE_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_ERR_INT_PEND_V_FF0000` | 0xff0000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_ERR_INT_PEND_V_FFFF` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_ERR_STACK_ADDR_A_B_8` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND1_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND_MOD_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND_MOD_V_40` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND_MOD_V_69` | 0x69 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND_MOD_V_6B` | 0x6b | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND_MOD_V_7` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND_MOD_V_76` | 0x76 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_PROF_EN_B_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_REGION_PRESENT_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_2A` | 0x2a | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_2B` | 0x2b | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_35` | 0x35 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_36` | 0x36 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5D` | 0x5d | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5E` | 0x5e | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5F` | 0x5f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_60` | 0x60 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_83` | 0x83 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_84` | 0x84 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_A` | 0xa | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_A6` | 0xa6 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_B` | 0xb | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_B4` | 0xb4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_C` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COUNT_B_11_0` | 0xfff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_EN_A_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_LOCAL_CTRL_V_10000` | 0x10000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
