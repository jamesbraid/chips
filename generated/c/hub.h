/* generated from devices/hub/registers.toml by defs-gen - do not edit, change the source */
/* Hub (Origin 2000 node controller) */
#ifndef HUB_GEN_H
#define HUB_GEN_H

#include <stdint.h>


/* pi_region_present: rw64, reset 0xffffffffffffffff; census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) */
#define HUB_PI_REGION_PRESENT                        0x000018 /* established */

/* pi_cpu_num: rw64, reset 0x0; census: 136 sites, 20 routines */
#define HUB_PI_CPU_NUM                               0x000020 /* established */

/* pi_max_crb_timeout: w64, reset 0x80; census: 2 sites, 1 routines */
#define HUB_PI_MAX_CRB_TIMEOUT                       0x000030 /* established */

/* pi_crb_sfactor: w64, reset 0x0; census: 2 sites, 1 routines */
#define HUB_PI_CRB_SFACTOR                           0x000038 /* established */

/* pi_cpu_present_a: r64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_CPU_PRESENT_A                         0x000040 /* established */

/* pi_cpu_present_b: r64, reset 0x0; census: 2 sites, 1 routines */
#define HUB_PI_CPU_PRESENT_B                         0x000048 /* established */

/* pi_cpu_enable_a: r64, reset 0x0; census: 2 sites, 2 routines */
#define HUB_PI_CPU_ENABLE_A                          0x000050 /* established */

/* pi_cpu_enable_b: r64, reset 0x0; census: 2 sites, 2 routines */
#define HUB_PI_CPU_ENABLE_B                          0x000058 /* established */

/* pi_nmi_a: w64, reset unknown; census: 3 sites, 3 routines */
#define HUB_PI_NMI_A                                 0x000070 /* established */

/* pi_int_pend0: r64, reset 0x0; census: 11 sites, 8 routines (r); census: 2 sites, 2 routines (r, indexed) */
#define HUB_PI_INT_PEND0                             0x000098 /* established */

/* pi_int_pend1: r64, reset 0x0; census: 5 sites, 4 routines (r); census: 1 sites, 1 routines (r, indexed) */
#define HUB_PI_INT_PEND1                             0x0000a0 /* established */

/* pi_int_mask0_a: rw64, reset 0x0; census: 4 sites, 4 routines */
#define HUB_PI_INT_MASK0_A                           0x0000a8 /* established */

/* pi_int_mask1_a: rw64, reset 0x0; census: 4 sites, 4 routines */
#define HUB_PI_INT_MASK1_A                           0x0000b0 /* established */

/* pi_int_mask0_b: rw64, reset 0x0; census: 2 sites, 2 routines */
#define HUB_PI_INT_MASK0_B                           0x0000b8 /* established */

/* pi_int_mask1_b: rw64, reset 0x0; census: 6 sites, 3 routines */
#define HUB_PI_INT_MASK1_B                           0x0000c0 /* established */

/* pi_rt_compare_a: w64, reset 0x0; census: 25 sites, 6 routines */
#define HUB_PI_RT_COMPARE_A                          0x000108 /* established */

/* pi_rt_compare_b: w64, reset 0x0; census: 3 sites, 3 routines */
#define HUB_PI_RT_COMPARE_B                          0x000110 /* established */

/* pi_profile_compare: w64, reset 0x0; census: 2 sites, 2 routines */
#define HUB_PI_PROFILE_COMPARE                       0x000118 /* established */

/* pi_rt_pend_a: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_RT_PEND_A                             0x000120 /* established */

/* pi_rt_pend_b: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_RT_PEND_B                             0x000128 /* established */

/* pi_prof_pend_a: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_PROF_PEND_A                           0x000130 /* established */

/* pi_prof_pend_b: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_PROF_PEND_B                           0x000138 /* established */

/* pi_rt_en_a: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_RT_EN_A                               0x000140 /* established */

/* pi_rt_en_b: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_RT_EN_B                               0x000148 /* established */

/* pi_prof_en_a: w64, reset 0x0; census: 2 sites, 2 routines (w); census: 1 sites, 1 routines (w, indexed) */
#define HUB_PI_PROF_EN_A                             0x000150 /* established */

/* pi_prof_en_b: w64, reset 0x0; census: 2 sites, 2 routines (w); census: 1 sites, 1 routines (w, indexed) */
#define HUB_PI_PROF_EN_B                             0x000158 /* established */

/* pi_gfx_int_cmp_a: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_GFX_INT_CMP_A                         0x000320 /* established */

/* pi_gfx_int_cmp_b: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PI_GFX_INT_CMP_B                         0x000348 /* established */

/* pi_err_stack_addr_a: rw64, reset 0x0; census: 4 sites, 3 routines (r); census: 2 sites, 1 routines (w, indexed) */
#define HUB_PI_ERR_STACK_ADDR_A                      0x000418 /* established */

/* pi_err_stack_addr_b: rw64, reset 0x0; census: 7 sites, 3 routines */
#define HUB_PI_ERR_STACK_ADDR_B                      0x000420 /* established */

/* pi_err_stack_size: r64, reset 0x0; census: 2 sites, 1 routines (r); census: 2 sites, 1 routines (r, indexed) */
#define HUB_PI_ERR_STACK_SIZE                        0x000428 /* established */

/* pi_hardreset_bit: w64, reset 0x1; census: 1 sites, 1 routines */
#define HUB_PI_HARDRESET_BIT                         0x020068 /* established */

/* pi_rt_count: rw64, reset 0x0; census: 161 sites, 80 routines */
#define HUB_PI_RT_COUNT                              0x030100 /* established */

/* md_mig_candidate_clr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_MIG_CANDIDATE_CLR                     0x200048 /* established */

/* md_dir_error_clr: r64, reset unknown; census: 1 sites, 1 routines (r); census: 4 sites, 3 routines (r, indexed) */
#define HUB_MD_DIR_ERROR_CLR                         0x200058 /* established */

/* md_protocol_error_clr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_PROTOCOL_ERROR_CLR                    0x200068 /* established */

/* md_mem_error_clr: r64, reset unknown; census: 1 sites, 1 routines (r); census: 5 sites, 3 routines (r, indexed) */
#define HUB_MD_MEM_ERROR_CLR                         0x200078 /* established */

/* md_misc_error_clr: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_MD_MISC_ERROR_CLR                        0x200088 /* established */

/* per_hub_init: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_PER_HUB_INIT                             0x2000c8 /* established */

/* hub_ifdr_fix_value: r64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_HUB_IFDR_FIX_VALUE                       0x2000d0 /* established */

/* hub_reply_queue_depth: r64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_HUB_REPLY_QUEUE_DEPTH                    0x2000d8 /* established */

/* hub_rev_war_ctrl: rw64, reset 0x0; census: 3 sites, 1 routines */
#define HUB_HUB_REV_WAR_CTRL                         0x2000e0 /* established */

/* md_ureg0_0: rw64, reset unknown; census: 6 sites, 2 routines (w); census: 22 sites, 6 routines (rw, indexed) */
#define HUB_MD_UREG0_0                               0x220000 /* established */

/* md_ureg0_1: rw64, reset unknown; census: 9 sites, 2 routines (w); census: 36 sites, 5 routines (rw, indexed) */
#define HUB_MD_UREG0_1                               0x220008 /* established */

/* md_ureg1_0: w64, reset 0x0; census: 38 sites, 9 routines */
#define HUB_MD_UREG1_0                               0x220080 /* established */

/* iio_iidem: rw64, reset 0xffffffffffffffff; census: 5 sites, 3 routines */
#define HUB_IIO_IIDEM                                0x400120 /* established */

/* hub_piomap_alloc: rw64, reset 0x0; census: 5 sites, 4 routines */
#define HUB_HUB_PIOMAP_ALLOC                         0x400160 /* established */

/* mlreset: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_MLRESET                                  0x400190 /* established */

/* iio_ioprb_0: rw64, reset 0x1; census: 7 sites, 4 routines */
#define HUB_IIO_IOPRB_0                              0x400198 /* established */

/* iio_ibcn: w64, reset unknown; census: 2 sites, 1 routines */
#define HUB_IIO_IBCN                                 0x400200 /* established */

/* hub_error_devenable: r64, reset unknown; census: 1 sites, 1 routines */
#define HUB_HUB_ERROR_DEVENABLE                      0x4002c8 /* established */

/* iio_prte_0: rw64, reset 0x0; census: 4 sites, 1 routines */
#define HUB_IIO_PRTE_0                               0x400308 /* established */

/* iio_icto: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_IIO_ICTO                                 0x4003b8 /* established */

/* iio_ictp: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_IIO_ICTP                                 0x4003c0 /* established */

/* iio_icrb_a: rw64, reset unknown; census: 14 sites, 9 routines */
#define HUB_IIO_ICRB_A                               0x400400 /* established */
#define HUB_IIO_ICRB_A_COUNT                         15
#define HUB_IIO_ICRB_A_STRIDE                        32

/* iio_icrb_b: rw64, reset unknown; census: 11 sites, 6 routines */
#define HUB_IIO_ICRB_B                               0x400408 /* established */
#define HUB_IIO_ICRB_B_COUNT                         15
#define HUB_IIO_ICRB_B_STRIDE                        32

/* iio_icrb_c: r64, reset unknown; census: 6 sites, 5 routines */
#define HUB_IIO_ICRB_C                               0x400410 /* established */
#define HUB_IIO_ICRB_C_COUNT                         15
#define HUB_IIO_ICRB_C_STRIDE                        32

/* iio_icrb_d: r64, reset unknown; census: 2 sites, 2 routines */
#define HUB_IIO_ICRB_D                               0x400418 /* established */
#define HUB_IIO_ICRB_D_COUNT                         15
#define HUB_IIO_ICRB_D_STRIDE                        32

/* iio_ibsa_0: r64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_IIO_IBSA_0                               0x410008 /* established */

/* iio_ibda_0: r64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_IIO_IBDA_0                               0x410010 /* established */

/* iio_ibsa_1: rw64, reset 0x0; census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) */
#define HUB_IIO_IBSA_1                               0x420008 /* established */

/* iio_ibda_1: rw64, reset unknown; census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) */
#define HUB_IIO_IBDA_1                               0x420010 /* established */

/* iio_ibna_1: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_IIO_IBNA_1                               0x420020 /* established */

/* ni_scratch_reg0: w64, reset 0x0; census: 1 sites, 1 routines */
#define HUB_NI_SCRATCH_REG0                          0x600100 /* established */

/* ni_scratch_reg1: rw64, reset 0x0; census: 14 sites, 2 routines */
#define HUB_NI_SCRATCH_REG1                          0x600108 /* established */

/* ni_vector: w64, reset unknown; census: 3 sites, 3 routines */
#define HUB_NI_VECTOR                                0x600208 /* established */

/* ni_vector_data: w64, reset unknown; census: 2 sites, 2 routines */
#define HUB_NI_VECTOR_DATA                           0x600210 /* established */

/* ni_vector_read_data: rw64, reset unknown; census: 4 sites, 2 routines */
#define HUB_NI_VECTOR_READ_DATA                      0x600310 /* established */

/* ni_meta_table0: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_NI_META_TABLE0                           0x638000 /* established */

/* ni_local_table0: w64, reset unknown; census: 1 sites, 1 routines */
#define HUB_NI_LOCAL_TABLE0                          0x638100 /* established */

#define HUB_HUB_IFDR_FIX_VALUE_B_6_0                 0x7fu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_B_3_0                   0xfu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_B_4_0                   0x1fu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_B_7_0                   0xffu /* inferred */
#define HUB_HUB_PIOMAP_ALLOC_V_300                   0x300u /* inferred */
#define HUB_HUB_REPLY_QUEUE_DEPTH_B_6_0              0x7fu /* inferred */
#define HUB_HUB_REV_WAR_CTRL_V_100                   0x100u /* inferred */
#define HUB_IIO_IBCN_V_2                             0x2u /* inferred */
#define HUB_IIO_ICRB_A_B_0                           0x1u /* inferred */
#define HUB_IIO_ICRB_A_B_2_0                         0x7u /* inferred */
#define HUB_IIO_ICRB_A_B_3_0                         0xfu /* inferred */
#define HUB_IIO_ICRB_A_B_4_0                         0x1fu /* inferred */
#define HUB_IIO_ICRB_B_B_1_0                         0x3u /* inferred */
#define HUB_IIO_ICRB_B_B_4_0                         0x1fu /* inferred */
#define HUB_IIO_ICTO_V_FF                            0xffu /* inferred */
#define HUB_IIO_ICTP_V_1000                          0x1000u /* inferred */
#define HUB_IIO_PRTE_0_B_7_0                         0xffu /* inferred */
#define HUB_MD_MEM_ERROR_CLR_B_0                     0x1u /* inferred */
#define HUB_MD_MISC_ERROR_CLR_B_9_0                  0x3ffu /* inferred */
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
#define HUB_PI_ERR_STACK_ADDR_A_B_8                  0x100u /* inferred */
#define HUB_PI_INT_PEND1_B_0                         0x1u /* inferred */
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

#endif /* HUB_GEN_H */
