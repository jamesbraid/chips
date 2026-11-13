/* generated from devices/hub/registers.toml by defs-gen - do not edit, change the source */
/* Hub (Origin 2000 node controller) */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/* pi_region_present: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_REGION_PRESENT                        0x000018 /* established */

/* pi_cpu_num: rw64, reset unknown; census: 136 sites, 20 routines */
#define HUB_PI_CPU_NUM                               0x000020 /* established */

/* pi_calias_size: rw64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_CALIAS_SIZE                           0x000028 /* established */

/* pi_max_crb_timeout: w64, reset unknown; census: 2 sites, 1 routines */
#define HUB_PI_MAX_CRB_TIMEOUT                       0x000030 /* established */

/* pi_crb_sfactor: w64, reset unknown; census: 2 sites, 1 routines */
#define HUB_PI_CRB_SFACTOR                           0x000038 /* established */

/* pi_cpu_present_a: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_CPU_PRESENT_A                         0x000040 /* established */

/* pi_cpu_present_b: r64, reset unknown; census: 2 sites, 1 routines */
#define HUB_PI_CPU_PRESENT_B                         0x000048 /* established */

/* pi_cpu_enable_a: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_CPU_ENABLE_A                          0x000050 /* established */

/* pi_cpu_enable_b: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_CPU_ENABLE_B                          0x000058 /* established */

/* pi_nmi_a: w64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_NMI_A                                 0x000070 /* established */

/* pi_int_pend_mod: w64, reset unknown; census: 9 sites, 8 routines */
#define HUB_PI_INT_PEND_MOD                          0x000090 /* established */

/* pi_int_pend0: r64, reset unknown; census: 11 sites, 8 routines */
#define HUB_PI_INT_PEND0                             0x000098 /* established */

/* pi_int_pend1: r64, reset unknown; census: 5 sites, 4 routines */
#define HUB_PI_INT_PEND1                             0x0000a0 /* established */

/* pi_int_mask0_a: rw64, reset unknown; census: 4 sites, 4 routines */
#define HUB_PI_INT_MASK0_A                           0x0000a8 /* established */

/* pi_int_mask1_a: rw64, reset unknown; census: 4 sites, 4 routines */
#define HUB_PI_INT_MASK1_A                           0x0000b0 /* established */

/* pi_int_mask0_b: rw64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_INT_MASK0_B                           0x0000b8 /* established */

/* pi_int_mask1_b: rw64, reset unknown; census: 6 sites, 3 routines */
#define HUB_PI_INT_MASK1_B                           0x0000c0 /* established */

/* pi_rt_compare_a: w64, reset unknown; census: 25 sites, 6 routines */
#define HUB_PI_RT_COMPARE_A                          0x000108 /* established */

/* pi_rt_compare_b: w64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_RT_COMPARE_B                          0x000110 /* established */

/* pi_profile_compare: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_PROFILE_COMPARE                       0x000118 /* established */

/* pi_rt_pend_a: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_RT_PEND_A                             0x000120 /* established */

/* pi_rt_pend_b: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_RT_PEND_B                             0x000128 /* established */

/* pi_prof_pend_a: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_PROF_PEND_A                           0x000130 /* established */

/* pi_prof_pend_b: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_PROF_PEND_B                           0x000138 /* established */

/* pi_rt_en_a: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_RT_EN_A                               0x000140 /* established */

/* pi_rt_en_b: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_RT_EN_B                               0x000148 /* established */

/* pi_prof_en_a: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_PROF_EN_A                             0x000150 /* established */

/* pi_prof_en_b: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_PROF_EN_B                             0x000158 /* established */

/* pi_rt_local_ctrl: rw64, reset unknown; census: 6 sites, 1 routines */
#define HUB_PI_RT_LOCAL_CTRL                         0x000160 /* established */

/* pi_gfx_int_cmp_a: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_GFX_INT_CMP_A                         0x000320 /* established */

/* pi_gfx_int_cmp_b: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_GFX_INT_CMP_B                         0x000348 /* established */

/* pi_err_int_pend: rw64, reset unknown; census: 13 sites, 5 routines */
#define HUB_PI_ERR_INT_PEND                          0x000400 /* established */

/* pi_err_int_mask_a: rw64, reset unknown; census: 5 sites, 2 routines */
#define HUB_PI_ERR_INT_MASK_A                        0x000408 /* established */

/* pi_err_int_mask_b: rw64, reset unknown; census: 5 sites, 2 routines */
#define HUB_PI_ERR_INT_MASK_B                        0x000410 /* established */

/* pi_err_stack_addr_a: r64, reset unknown; census: 4 sites, 3 routines */
#define HUB_PI_ERR_STACK_ADDR_A                      0x000418 /* established */

/* pi_err_stack_addr_b: rw64, reset unknown; census: 7 sites, 3 routines */
#define HUB_PI_ERR_STACK_ADDR_B                      0x000420 /* established */

/* pi_err_stack_size: r64, reset unknown; census: 2 sites, 1 routines */
#define HUB_PI_ERR_STACK_SIZE                        0x000428 /* established */

/* pi_err_status0_a: r64, reset unknown; census: 5 sites, 4 routines */
#define HUB_PI_ERR_STATUS0_A                         0x000430 /* established */

/* pi_err_status1_a: r64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_ERR_STATUS1_A                         0x000440 /* established */

/* pi_err_status1_a_rclr: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_ERR_STATUS1_A_RCLR                    0x000448 /* established */

/* pi_err_status0_b: r64, reset unknown; census: 5 sites, 4 routines */
#define HUB_PI_ERR_STATUS0_B                         0x000450 /* established */

/* pi_err_status1_b: r64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_ERR_STATUS1_B                         0x000460 /* established */

/* pi_err_status1_b_rclr: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_PI_ERR_STATUS1_B_RCLR                    0x000468 /* established */

/* pi_hardreset_bit: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PI_HARDRESET_BIT                         0x020068 /* established */

/* pi_rt_count: rw64, reset unknown; census: 161 sites, 80 routines */
#define HUB_PI_RT_COUNT                              0x030100 /* established */

/* md_memory_config: r64, reset unknown; census: 3 sites, 3 routines */
#define HUB_MD_MEMORY_CONFIG                         0x200018 /* established */

/* md_refresh_control: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_REFRESH_CONTROL                       0x200020 /* established */

/* md_fandop_cac_stat: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_FANDOP_CAC_STAT                       0x200028 /* established */

/* md_mig_diff_thresh: rw64, reset unknown; census: 6 sites, 3 routines */
#define HUB_MD_MIG_DIFF_THRESH                       0x200030 /* established */

/* md_mig_value_thresh: rw64, reset unknown; census: 10 sites, 5 routines */
#define HUB_MD_MIG_VALUE_THRESH                      0x200038 /* established */

/* md_mig_candidate_clr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_MIG_CANDIDATE_CLR                     0x200048 /* established */

/* md_dir_error: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_DIR_ERROR                             0x200050 /* established */

/* md_dir_error_clr: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_DIR_ERROR_CLR                         0x200058 /* established */

/* md_protocol_error: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_PROTOCOL_ERROR                        0x200060 /* established */

/* md_protocol_error_clr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_PROTOCOL_ERROR_CLR                    0x200068 /* established */

/* md_mem_error: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_MEM_ERROR                             0x200070 /* established */

/* md_mem_error_clr: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_MEM_ERROR_CLR                         0x200078 /* established */

/* md_misc_error: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_MISC_ERROR                            0x200080 /* established */

/* md_misc_error_clr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_MISC_ERROR_CLR                        0x200088 /* established */

/* md_moq_size: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_MOQ_SIZE                              0x2000a0 /* established */

/* md_mlan_ctl: rw64, reset unknown; census: 6 sites, 1 routines */
#define HUB_MD_MLAN_CTL                              0x2000a8 /* established */

/* per_hub_init: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_PER_HUB_INIT                             0x2000c8 /* established */

/* hub_ifdr_fix_value: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_HUB_IFDR_FIX_VALUE                       0x2000d0 /* established */

/* hub_ifdr_fix_value_2000d8: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_HUB_IFDR_FIX_VALUE_2000D8                0x2000d8 /* established */

/* per_hub_init_2000e0: rw64, reset unknown; census: 3 sites, 1 routines */
#define HUB_PER_HUB_INIT_2000E0                      0x2000e0 /* established */

/* md_perf_sel: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_PERF_SEL                              0x210000 /* established */

/* md_perf_cnt0: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MD_PERF_CNT0                             0x210010 /* established */

/* md_ureg0_0: w64, reset unknown; census: 6 sites, 2 routines */
#define HUB_MD_UREG0_0                               0x220000 /* established */

/* md_ureg0_1: w64, reset unknown; census: 9 sites, 2 routines */
#define HUB_MD_UREG0_1                               0x220008 /* established */

/* md_slotid_ustat: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_SLOTID_USTAT                          0x220048 /* established */

/* md_led0: w64, reset unknown; census: 4 sites, 1 routines */
#define HUB_MD_LED0                                  0x220050 /* established */

/* md_ureg1_0: w64, reset unknown; census: 38 sites, 9 routines */
#define HUB_MD_UREG1_0                               0x220080 /* established */

/* iio_wstat: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_WSTAT                                0x400008 /* established */

/* iio_wcr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_IIO_WCR                                  0x400020 /* established */

/* iio_iowa: rw64, reset unknown; census: 6 sites, 3 routines */
#define HUB_IIO_IOWA                                 0x400110 /* established */

/* iio_iiwa: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_IIO_IIWA                                 0x400118 /* established */

/* iio_iidem: rw64, reset unknown; census: 5 sites, 3 routines */
#define HUB_IIO_IIDEM                                0x400120 /* established */

/* iio_ilcsr: rw64, reset unknown; census: 2 sites, 1 routines */
#define HUB_IIO_ILCSR                                0x400128 /* established */

/* iio_illr: rw64, reset unknown; census: 2 sites, 1 routines */
#define HUB_IIO_ILLR                                 0x400130 /* established */

/* iio_iidsr: rw64, reset unknown; census: 12 sites, 5 routines */
#define HUB_IIO_IIDSR                                0x400138 /* established */

/* iio_igfx_0: rw64, reset unknown; census: 2 sites, 1 routines */
#define HUB_IIO_IGFX_0                               0x400140 /* established */

/* hub_piomap_alloc: rw64, reset unknown; census: 5 sites, 4 routines */
#define HUB_HUB_PIOMAP_ALLOC                         0x400160 /* established */

/* mlreset: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_MLRESET                                  0x400190 /* established */

/* iio_ioprb_0: rw64, reset unknown; census: 7 sites, 4 routines */
#define HUB_IIO_IOPRB_0                              0x400198 /* established */

/* iio_imem: rw64, reset unknown; census: 4 sites, 3 routines */
#define HUB_IIO_IMEM                                 0x4001e8 /* established */

/* iio_ieclr: w64, reset unknown; census: 2 sites, 1 routines */
#define HUB_IIO_IECLR                                0x4001f8 /* established */

/* iio_ibcn: w64, reset unknown; census: 2 sites, 1 routines */
#define HUB_IIO_IBCN                                 0x400200 /* established */

/* hub_error_devenable: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_HUB_ERROR_DEVENABLE                      0x4002c8 /* established */

/* iio_prte_0: rw64, reset unknown; census: 4 sites, 1 routines */
#define HUB_IIO_PRTE_0                               0x400308 /* established */

/* iio_ipdr: rw64, reset unknown; census: 5 sites, 2 routines */
#define HUB_IIO_IPDR                                 0x400388 /* established */

/* iio_icdr: rw64, reset unknown; census: 3 sites, 1 routines */
#define HUB_IIO_ICDR                                 0x400390 /* established */

/* iio_ifdr: rw64, reset unknown; census: 8 sites, 3 routines */
#define HUB_IIO_IFDR                                 0x400398 /* established */

/* iio_icmr: rw64, reset unknown; census: 6 sites, 3 routines */
#define HUB_IIO_ICMR                                 0x4003a8 /* established */

/* iio_iccr: rw64, reset unknown; census: 7 sites, 1 routines */
#define HUB_IIO_ICCR                                 0x4003b0 /* established */

/* iio_icto: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_ICTO                                 0x4003b8 /* established */

/* iio_ictp: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_ICTP                                 0x4003c0 /* established */

/* iio_icrb0_a: rw64, reset unknown; census: 14 sites, 9 routines */
#define HUB_IIO_ICRB0_A                              0x400400 /* established */

/* iio_icrb0_b: rw64, reset unknown; census: 11 sites, 6 routines */
#define HUB_IIO_ICRB0_B                              0x400408 /* established */

/* iio_icrb0_c: r64, reset unknown; census: 6 sites, 5 routines */
#define HUB_IIO_ICRB0_C                              0x400410 /* established */

/* iio_icrb0_d: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_IIO_ICRB0_D                              0x400418 /* established */

/* iio_icrb1_b: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_ICRB1_B                              0x400428 /* established */

/* iio_ibls_0: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBLS_0                               0x410000 /* established */

/* iio_ibsa_0: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBSA_0                               0x410008 /* established */

/* iio_ibda_0: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBDA_0                               0x410010 /* established */

/* iio_ibct_0: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBCT_0                               0x410018 /* established */

/* iio_ibls_1: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBLS_1                               0x420000 /* established */

/* iio_ibsa_1: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBSA_1                               0x420008 /* established */

/* iio_ibda_1: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBDA_1                               0x420010 /* established */

/* iio_ibct_1: rw64, reset unknown; census: 3 sites, 1 routines */
#define HUB_IIO_IBCT_1                               0x420018 /* established */

/* iio_ibna_1: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_IIO_IBNA_1                               0x420020 /* established */

/* iio_ipcr: rw64, reset unknown; census: 4 sites, 2 routines */
#define HUB_IIO_IPCR                                 0x430000 /* established */

/* iio_ippr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_IIO_IPPR                                 0x430008 /* established */

/* ni_status_rev_id: r64, reset unknown; census: 18 sites, 16 routines */
#define HUB_NI_STATUS_REV_ID                         0x600000 /* established */

/* ni_port_reset: w64, reset unknown; census: 6 sites, 6 routines */
#define HUB_NI_PORT_RESET                            0x600008 /* established */

/* ni_protection: r64, reset unknown; census: 3 sites, 2 routines */
#define HUB_NI_PROTECTION                            0x600010 /* established */

/* ni_global_parms: rw64, reset unknown; census: 2 sites, 1 routines */
#define HUB_NI_GLOBAL_PARMS                          0x600018 /* established */

/* ni_scratch_reg0: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_NI_SCRATCH_REG0                          0x600100 /* established */

/* ni_scratch_reg1: rw64, reset unknown; census: 14 sites, 2 routines */
#define HUB_NI_SCRATCH_REG1                          0x600108 /* established */

/* ni_diag_parms: rw64, reset unknown; census: 2 sites, 1 routines */
#define HUB_NI_DIAG_PARMS                            0x600110 /* established */

/* ni_vector_parms: w64, reset unknown; census: 3 sites, 3 routines */
#define HUB_NI_VECTOR_PARMS                          0x600200 /* established */

/* ni_vector: w64, reset unknown; census: 3 sites, 3 routines */
#define HUB_NI_VECTOR                                0x600208 /* established */

/* ni_vector_data: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_NI_VECTOR_DATA                           0x600210 /* established */

/* ni_vector_status: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_NI_VECTOR_STATUS                         0x600300 /* established */

/* ni_vector_read_data: rw64, reset unknown; census: 4 sites, 2 routines */
#define HUB_NI_VECTOR_READ_DATA                      0x600310 /* established */

/* ni_vector_clear: r64, reset unknown; census: 3 sites, 3 routines */
#define HUB_NI_VECTOR_CLEAR                          0x600380 /* established */

/* ni_age_cpu0_memory: rw64, reset unknown; census: 9 sites, 3 routines */
#define HUB_NI_AGE_CPU0_MEMORY                       0x600500 /* established */

/* ni_age_cpu1_memory: rw64, reset unknown; census: 9 sites, 3 routines */
#define HUB_NI_AGE_CPU1_MEMORY                       0x600510 /* established */

/* ni_port_error: r64, reset unknown; census: 4 sites, 4 routines */
#define HUB_NI_PORT_ERROR                            0x608008 /* established */

/* ni_port_error_clear: r64, reset unknown; census: 10 sites, 4 routines */
#define HUB_NI_PORT_ERROR_CLEAR                      0x608088 /* established */

/* ni_meta_table0: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_NI_META_TABLE0                           0x638000 /* established */

/* ni_local_table0: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_NI_LOCAL_TABLE0                          0x638100 /* established */

#define HUB_HUB_IFDR_FIX_VALUE_2000D8_B_6_0          0x7fu /* inferred */
#define HUB_HUB_IFDR_FIX_VALUE_B_6_0                 0x7fu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_B_3_0                   0xfu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_B_4_0                   0x1fu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_B_7_0                   0xffu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_V_300                   0x300u /* inferred */
#define HUB_IIO_IBCN_V_2                             0x2u /* inferred */
#define HUB_IIO_IBCT_1_V_10                          0x10u /* inferred */
#define HUB_IIO_IBLS_1_V_1                           0x1u /* inferred */
#define HUB_IIO_IBLS_1_V_100000                      0x100000u /* inferred */
#define HUB_IIO_ICDR_B_4                             0x10u /* inferred */
#define HUB_IIO_ICDR_V_10                            0x10u /* inferred */
#define HUB_IIO_ICMR_V_40                            0x40u /* inferred */
#define HUB_IIO_ICRB0_A_B_0                          0x1u /* inferred */
#define HUB_IIO_ICRB0_A_B_2_0                        0x7u /* inferred */
#define HUB_IIO_ICRB0_A_B_3_0                        0xfu /* inferred */
#define HUB_IIO_ICRB0_A_B_4_0                        0x1fu /* inferred */
#define HUB_IIO_ICRB0_B_B_1_0                        0x3u /* inferred */
#define HUB_IIO_ICRB0_B_B_4_0                        0x1fu /* inferred */
#define HUB_IIO_ICTO_V_FF                            0xffu /* inferred */
#define HUB_IIO_ICTP_V_1000                          0x1000u /* inferred */
#define HUB_IIO_IECLR_V_20000                        0x20000u /* inferred */
#define HUB_IIO_IECLR_V_FF0000                       0xff0000u /* inferred */
#define HUB_IIO_IECLR_V_FFFF                         0xffffu /* inferred */
#define HUB_IIO_IFDR_B_6_0                           0x7fu /* inferred */
#define HUB_IIO_IIDSR_V_1000000                      0x1000000u /* inferred */
#define HUB_IIO_ILCSR_B_1                            0x2u /* inferred */
#define HUB_IIO_ILCSR_B_13                           0x2000u /* inferred */
#define HUB_IIO_ILCSR_B_15_0                         0xffffu /* inferred */
#define HUB_IIO_ILCSR_V_100                          0x100u /* inferred */
#define HUB_IIO_ILLR_B_15_0                          0xffffu /* inferred */
#define HUB_IIO_IMEM_B_0                             0x1u /* inferred */
#define HUB_IIO_IMEM_B_4                             0x10u /* inferred */
#define HUB_IIO_IMEM_B_4_0                           0x11u /* inferred */
#define HUB_IIO_IMEM_B_8                             0x100u /* inferred */
#define HUB_IIO_IMEM_V_101                           0x101u /* inferred */
#define HUB_IIO_IPDR_B_4                             0x10u /* inferred */
#define HUB_IIO_IPDR_V_10                            0x10u /* inferred */
#define HUB_IIO_PRTE_0_B_7_0                         0xffu /* inferred */
#define HUB_IIO_WCR_B_3_0                            0xfu /* inferred */
#define HUB_MD_LED0_V_1                              0x1u /* inferred */
#define HUB_MD_LED0_V_2                              0x2u /* inferred */
#define HUB_MD_LED0_V_23                             0x23u /* inferred */
#define HUB_MD_LED0_V_2A                             0x2au /* inferred */
#define HUB_MD_LED0_V_2B                             0x2bu /* inferred */
#define HUB_MD_LED0_V_3                              0x3u /* inferred */
#define HUB_MD_LED0_V_31                             0x31u /* inferred */
#define HUB_MD_LED0_V_35                             0x35u /* inferred */
#define HUB_MD_LED0_V_36                             0x36u /* inferred */
#define HUB_MD_LED0_V_3F                             0x3fu /* inferred */
#define HUB_MD_LED0_V_4                              0x4u /* inferred */
#define HUB_MD_LED0_V_46                             0x46u /* inferred */
#define HUB_MD_LED0_V_47                             0x47u /* inferred */
#define HUB_MD_LED0_V_48                             0x48u /* inferred */
#define HUB_MD_LED0_V_5                              0x5u /* inferred */
#define HUB_MD_LED0_V_5D                             0x5du /* inferred */
#define HUB_MD_LED0_V_81                             0x81u /* inferred */
#define HUB_MD_LED0_V_83                             0x83u /* inferred */
#define HUB_MD_LED0_V_84                             0x84u /* inferred */
#define HUB_MD_LED0_V_9                              0x9u /* inferred */
#define HUB_MD_LED0_V_97                             0x97u /* inferred */
#define HUB_MD_LED0_V_A                              0xau /* inferred */
#define HUB_MD_LED0_V_A6                             0xa6u /* inferred */
#define HUB_MD_LED0_V_B                              0xbu /* inferred */
#define HUB_MD_LED0_V_B4                             0xb4u /* inferred */
#define HUB_MD_LED0_V_C                              0xcu /* inferred */
#define HUB_MD_LED0_V_CF                             0xcfu /* inferred */
#define HUB_MD_LED0_V_F                              0xfu /* inferred */
#define HUB_MD_LED0_V_F3                             0xf3u /* inferred */
#define HUB_MD_LED0_V_FC                             0xfcu /* inferred */
#define HUB_MD_MEMORY_CONFIG_B_1_0                   0x3u /* inferred */
#define HUB_MD_MEM_ERROR_CLR_B_0                     0x1u /* inferred */
#define HUB_MD_MISC_ERROR_CLR_B_9_0                  0x3ffu /* inferred */
#define HUB_MD_MLAN_CTL_B_0                          0x1u /* inferred */
#define HUB_MD_MLAN_CTL_B_1                          0x2u /* inferred */
#define HUB_MD_REFRESH_CONTROL_B_11_0                0xfffu /* inferred */
#define HUB_MD_SLOTID_USTAT_B_3_0                    0xfu /* inferred */
#define HUB_MD_SLOTID_USTAT_B_7_0                    0xffu /* inferred */
#define HUB_MD_UREG0_0_B_7_0                         0xffu /* inferred */
#define HUB_MD_UREG0_0_V_1                           0x1u /* inferred */
#define HUB_MD_UREG0_0_V_1C                          0x1cu /* inferred */
#define HUB_MD_UREG0_0_V_7F                          0x7fu /* inferred */
#define HUB_MD_UREG0_0_V_8                           0x8u /* inferred */
#define HUB_MD_UREG0_0_V_FE                          0xfeu /* inferred */
#define HUB_MD_UREG0_1_B_0                           0x1u /* inferred */
#define HUB_MD_UREG0_1_B_3                           0x8u /* inferred */
#define HUB_MD_UREG0_1_B_4_2_1                       0x16u /* inferred */
#define HUB_MD_UREG0_1_B_7_0                         0xffu /* inferred */
#define HUB_MD_UREG0_1_V_45                          0x45u /* inferred */
#define HUB_MD_UREG0_1_V_80                          0x80u /* inferred */
#define HUB_MD_UREG0_1_V_A0                          0xa0u /* inferred */
#define HUB_MD_UREG0_1_V_C0                          0xc0u /* inferred */
#define HUB_MD_UREG0_1_V_C5                          0xc5u /* inferred */
#define HUB_MD_UREG1_0_V_1                           0x1u /* inferred */
#define HUB_MD_UREG1_0_V_2                           0x2u /* inferred */
#define HUB_MD_UREG1_0_V_23                          0x23u /* inferred */
#define HUB_MD_UREG1_0_V_2A                          0x2au /* inferred */
#define HUB_MD_UREG1_0_V_2B                          0x2bu /* inferred */
#define HUB_MD_UREG1_0_V_3                           0x3u /* inferred */
#define HUB_MD_UREG1_0_V_31                          0x31u /* inferred */
#define HUB_MD_UREG1_0_V_35                          0x35u /* inferred */
#define HUB_MD_UREG1_0_V_36                          0x36u /* inferred */
#define HUB_MD_UREG1_0_V_3F                          0x3fu /* inferred */
#define HUB_MD_UREG1_0_V_4                           0x4u /* inferred */
#define HUB_MD_UREG1_0_V_46                          0x46u /* inferred */
#define HUB_MD_UREG1_0_V_47                          0x47u /* inferred */
#define HUB_MD_UREG1_0_V_48                          0x48u /* inferred */
#define HUB_MD_UREG1_0_V_5                           0x5u /* inferred */
#define HUB_MD_UREG1_0_V_5D                          0x5du /* inferred */
#define HUB_MD_UREG1_0_V_81                          0x81u /* inferred */
#define HUB_MD_UREG1_0_V_83                          0x83u /* inferred */
#define HUB_MD_UREG1_0_V_84                          0x84u /* inferred */
#define HUB_MD_UREG1_0_V_97                          0x97u /* inferred */
#define HUB_MD_UREG1_0_V_A                           0xau /* inferred */
#define HUB_MD_UREG1_0_V_A6                          0xa6u /* inferred */
#define HUB_MD_UREG1_0_V_B                           0xbu /* inferred */
#define HUB_MD_UREG1_0_V_B4                          0xb4u /* inferred */
#define HUB_MD_UREG1_0_V_C                           0xcu /* inferred */
#define HUB_MD_UREG1_0_V_CF                          0xcfu /* inferred */
#define HUB_MD_UREG1_0_V_F                           0xfu /* inferred */
#define HUB_MD_UREG1_0_V_F3                          0xf3u /* inferred */
#define HUB_MD_UREG1_0_V_FC                          0xfcu /* inferred */
#define HUB_NI_PORT_ERROR_CLEAR_B_7_0                0xffu /* inferred */
#define HUB_NI_PORT_RESET_V_2                        0x2u /* inferred */
#define HUB_NI_PORT_RESET_V_81                       0x81u /* inferred */
#define HUB_NI_STATUS_REV_ID_B_0                     0x1u /* inferred */
#define HUB_NI_STATUS_REV_ID_B_3_0                   0xfu /* inferred */
#define HUB_NI_STATUS_REV_ID_B_7_0                   0xffu /* inferred */
#define HUB_NI_STATUS_REV_ID_B_8_0                   0x1ffu /* inferred */
#define HUB_PER_HUB_INIT_2000E0_V_100                0x100u /* inferred */
#define HUB_PI_CALIAS_SIZE_V_1                       0x1u /* inferred */
#define HUB_PI_CALIAS_SIZE_V_2                       0x2u /* inferred */
#define HUB_PI_ERR_INT_PEND_V_FF0000                 0xff0000u /* inferred */
#define HUB_PI_ERR_INT_PEND_V_FFFF                   0xffffu /* inferred */
#define HUB_PI_ERR_STACK_ADDR_A_B_8                  0x100u /* inferred */
#define HUB_PI_INT_PEND1_B_0                         0x1u /* inferred */
#define HUB_PI_INT_PEND_MOD_V_100                    0x100u /* inferred */
#define HUB_PI_INT_PEND_MOD_V_40                     0x40u /* inferred */
#define HUB_PI_INT_PEND_MOD_V_69                     0x69u /* inferred */
#define HUB_PI_INT_PEND_MOD_V_6B                     0x6bu /* inferred */
#define HUB_PI_INT_PEND_MOD_V_7                      0x7u /* inferred */
#define HUB_PI_INT_PEND_MOD_V_76                     0x76u /* inferred */
#define HUB_PI_PROF_EN_B_V_1                         0x1u /* inferred */
#define HUB_PI_REGION_PRESENT_V_1                    0x1u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_1                      0x1u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_2                      0x2u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_2A                     0x2au /* inferred */
#define HUB_PI_RT_COMPARE_A_V_2B                     0x2bu /* inferred */
#define HUB_PI_RT_COMPARE_A_V_3                      0x3u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_35                     0x35u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_36                     0x36u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_4                      0x4u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_5                      0x5u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_5D                     0x5du /* inferred */
#define HUB_PI_RT_COMPARE_A_V_5E                     0x5eu /* inferred */
#define HUB_PI_RT_COMPARE_A_V_5F                     0x5fu /* inferred */
#define HUB_PI_RT_COMPARE_A_V_60                     0x60u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_81                     0x81u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_83                     0x83u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_84                     0x84u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_A                      0xau /* inferred */
#define HUB_PI_RT_COMPARE_A_V_A6                     0xa6u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_B                      0xbu /* inferred */
#define HUB_PI_RT_COMPARE_A_V_B4                     0xb4u /* inferred */
#define HUB_PI_RT_COMPARE_A_V_C                      0xcu /* inferred */
#define HUB_PI_RT_COUNT_B_11_0                       0xfffu /* inferred */
#define HUB_PI_RT_EN_A_V_1                           0x1u /* inferred */
#define HUB_PI_RT_LOCAL_CTRL_V_10000                 0x10000u /* inferred */

#endif /* HUB_GEN_H */
