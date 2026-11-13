/* generated from devices/ioc3/registers.toml by defs-gen - do not edit, change the source */
/* IOC3 (PCI I/O controller) */
#ifndef IOC3_GEN_H
#define IOC3_GEN_H

#include <stdint.h>


/* sio_ir: rw32, reset unknown; census: 54 sites, 8 routines */
#define IOC3_SIO_IR                                  0x00001c /* established */

/* sio_ies: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_SIO_IES                                 0x000020 /* established */

/* sio_iec: w32, reset unknown; census: 5 sites, 1 routines */
#define IOC3_SIO_IEC                                 0x000024 /* established */

/* sio_cr: rw32, reset unknown; census: 18 sites, 3 routines */
#define IOC3_SIO_CR                                  0x000028 /* established */

/* int_out: w32, reset unknown; census: 2 sites, 1 routines */
#define IOC3_INT_OUT                                 0x00002c /* established */

/* gpcr_s: rw32, reset unknown; census: 11 sites, 3 routines */
#define IOC3_GPCR_S                                  0x000034 /* established */

/* gpcr_c: w32, reset unknown; census: 2 sites, 1 routines */
#define IOC3_GPCR_C                                  0x000038 /* established */

/* gppr0: w32, reset unknown; census: 6 sites, 1 routines */
#define IOC3_GPPR0                                   0x000040 /* established */

/* gppr5: rw32, reset unknown; census: 12 sites, 1 routines */
#define IOC3_GPPR5                                   0x000054 /* established */

/* ppbr_h_a: w32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_PPBR_H_A                                0x000080 /* established */

/* ppbr_l_a: w32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_PPBR_L_A                                0x000084 /* established */

/* ppcr_a: rw32, reset unknown; census: 9 sites, 2 routines */
#define IOC3_PPCR_A                                  0x000088 /* established */

/* ppcr: rw32, reset unknown; census: 39 sites, 4 routines */
#define IOC3_PPCR                                    0x00008c /* established */

/* ppbr_h_b: w32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_PPBR_H_B                                0x000090 /* established */

/* ppbr_l_b: w32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_PPBR_L_B                                0x000094 /* established */

/* ppcr_b: rw32, reset unknown; census: 9 sites, 2 routines */
#define IOC3_PPCR_B                                  0x000098 /* established */

/* km_csr: rw32, reset unknown; census: 21 sites, 3 routines */
#define IOC3_KM_CSR                                  0x00009c /* established */

/* sbbr_h: w32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_SBBR_H                                  0x0000b0 /* established */

/* sbbr_l: w32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_SBBR_L                                  0x0000b4 /* established */

/* port_a_stpir: w32, reset unknown; census: 15 sites, 4 routines */
#define IOC3_PORT_A_STPIR                            0x0000bc /* established */

/* port_a_stcir: r32, reset unknown; census: 12 sites, 4 routines */
#define IOC3_PORT_A_STCIR                            0x0000c0 /* established */

/* port_a_srpir: r32, reset unknown; census: 18 sites, 3 routines */
#define IOC3_PORT_A_SRPIR                            0x0000c4 /* established */

/* port_a_srcir: w32, reset unknown; census: 15 sites, 3 routines */
#define IOC3_PORT_A_SRCIR                            0x0000c8 /* established */

/* port_a_srtr: w32, reset unknown; census: 9 sites, 3 routines */
#define IOC3_PORT_A_SRTR                             0x0000cc /* established */

/* port_a_shadow: rw32, reset unknown; census: 21 sites, 5 routines */
#define IOC3_PORT_A_SHADOW                           0x0000d0 /* established */

/* emcr: rw32, reset unknown; census: 39 sites, 5 routines */
#define IOC3_EMCR                                    0x0000f0 /* established */

/* eisr: rw32, reset unknown; census: 9 sites, 2 routines */
#define IOC3_EISR                                    0x0000f4 /* established */

/* eier: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_EIER                                    0x0000f8 /* established */

/* ercsr: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ERCSR                                   0x0000fc /* established */

/* erbr_h: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ERBR_H                                  0x000100 /* established */

/* erbr_l: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ERBR_L                                  0x000104 /* established */

/* erbar: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ERBAR                                   0x000108 /* established */

/* ercir: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ERCIR                                   0x00010c /* established */

/* erpir: rw32, reset unknown; census: 15 sites, 5 routines */
#define IOC3_ERPIR                                   0x000110 /* established */

/* ertr: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ERTR                                    0x000114 /* established */

/* etcsr: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ETCSR                                   0x000118 /* established */

/* ersr: w32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_ERSR                                    0x00011c /* established */

/* etcdc: r32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ETCDC                                   0x000120 /* established */

/* ebir: r32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_EBIR                                    0x000124 /* established */

/* etbr_h: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_ETBR_H                                  0x000128 /* established */

/* etbr_l: rw32, reset unknown; census: 12 sites, 2 routines */
#define IOC3_ETBR_L                                  0x00012c /* established */

/* etcir: rw32, reset unknown; census: 9 sites, 3 routines */
#define IOC3_ETCIR                                   0x000130 /* established */

/* etpir: rw32, reset unknown; census: 9 sites, 3 routines */
#define IOC3_ETPIR                                   0x000134 /* established */

/* emar_h: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_EMAR_H                                  0x000138 /* established */

/* emar_l: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC3_EMAR_L                                  0x00013c /* established */

/* ehar_h: rw32, reset unknown; census: 9 sites, 2 routines */
#define IOC3_EHAR_H                                  0x000140 /* established */

/* ehar_l: rw32, reset unknown; census: 9 sites, 2 routines */
#define IOC3_EHAR_L                                  0x000144 /* established */

/* micr: rw32, reset unknown; census: 30 sites, 2 routines */
#define IOC3_MICR                                    0x000148 /* established */

/* midr_r: r32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_MIDR_R                                  0x00014c /* established */

/* midr_w: w32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_MIDR_W                                  0x000150 /* established */

/* pp_dcr: rw8, reset unknown; census: 6 sites, 1 routines */
#define IOC3_PP_DCR                                  0x020152 /* established */

/* pp_ecr: rw8, reset unknown; census: 12 sites, 2 routines */
#define IOC3_PP_ECR                                  0x02015a /* established */

/* uarta_reg0: w8, reset unknown; census: 3 sites, 1 routines */
#define IOC3_UARTA_REG0                              0x020178 /* established */

/* uarta_reg1: w8, reset unknown; census: 6 sites, 2 routines */
#define IOC3_UARTA_REG1                              0x020179 /* established */

/* uarta_reg2: w8, reset unknown; census: 9 sites, 2 routines */
#define IOC3_UARTA_REG2                              0x02017a /* established */

/* uarta_reg3: rw8, reset unknown; census: 33 sites, 5 routines */
#define IOC3_UARTA_REG3                              0x02017b /* established */

/* uarta_reg4: rw8, reset unknown; census: 9 sites, 2 routines */
#define IOC3_UARTA_REG4                              0x02017c /* established */

/* uarta_reg5: r8, reset unknown; census: 3 sites, 1 routines */
#define IOC3_UARTA_REG5                              0x02017d /* established */

/* uarta_reg7: w8, reset unknown; census: 3 sites, 1 routines */
#define IOC3_UARTA_REG7                              0x02017f /* established */

/* cfg_command: rw32, reset unknown; census: 9 sites, 2 routines */
#define IOC3_CFG_COMMAND                             0x200004 /* established */

/* cfg_revision: r32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_CFG_REVISION                            0x200008 /* established */

/* cfg_latency: w32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_CFG_LATENCY                             0x20000c /* established */

/* cfg_error_addr_lo: rw32, reset unknown; census: 6 sites, 1 routines */
#define IOC3_CFG_ERROR_ADDR_LO                       0x200040 /* established */

/* cfg_error_addr_hi: r32, reset unknown; census: 3 sites, 1 routines */
#define IOC3_CFG_ERROR_ADDR_HI                       0x200044 /* established */

#define IOC3_CFG_COMMAND_V_8146                      0x8146u /* inferred */
#define IOC3_CFG_ERROR_ADDR_LO_B_0                   0x1u /* inferred */
#define IOC3_CFG_ERROR_ADDR_LO_B_3_0                 0xfu /* inferred */
#define IOC3_CFG_LATENCY_V_2800                      0x2800u /* inferred */
#define IOC3_CFG_LATENCY_V_FF00                      0xff00u /* inferred */
#define IOC3_CFG_REVISION_B_7_0                      0xffu /* inferred */
#define IOC3_EMCR_V_1200                             0x1200u /* inferred */
#define IOC3_EMCR_V_2                                0x2u /* inferred */
#define IOC3_EMCR_V_80000000                         0x80000000u /* inferred */
#define IOC3_EMCR_V_AC                               0xacu /* inferred */
#define IOC3_ERBAR_V_1000000                         0x1000000u /* inferred */
#define IOC3_ERCSR_B_8_0                             0x1ffu /* inferred */
#define IOC3_ETBR_L_V_1                              0x1u /* inferred */
#define IOC3_ETCDC_B_15_0                            0xffffu /* inferred */
#define IOC3_ETCIR_B_15_0                            0xffffu /* inferred */
#define IOC3_GPCR_C_V_2                              0x2u /* inferred */
#define IOC3_GPCR_S_V_10000                          0x10000u /* inferred */
#define IOC3_GPCR_S_V_20                             0x20u /* inferred */
#define IOC3_GPPR5_V_1                               0x1u /* inferred */
#define IOC3_MICR_B_11                               0x800u /* inferred */
#define IOC3_MICR_V_400                              0x400u /* inferred */
#define IOC3_MIDR_R_B_15_0                           0xffffu /* inferred */
#define IOC3_PORT_A_SRCIR_V_80000000                 0x80000000u /* inferred */
#define IOC3_PORT_A_SRPIR_B_11_3                     0xff8u /* inferred */
#define IOC3_PORT_A_SRTR_V_A0                        0xa0u /* inferred */
#define IOC3_PORT_A_SSCR                             0xb8u /* established */
#define IOC3_PORT_A_SSCR_V_20000000                  0x20000000u /* inferred */
#define IOC3_PORT_A_SSCR_V_8000000                   0x8000000u /* inferred */
#define IOC3_PORT_A_SSCR_V_80000000                  0x80000000u /* inferred */
#define IOC3_PORT_A_STCIR_B_11_3                     0xff8u /* inferred */
#define IOC3_PPCR_A_V_40000000                       0x40000000u /* inferred */
#define IOC3_PPCR_B_V_40000000                       0x40000000u /* inferred */
#define IOC3_PPCR_V_40000000                         0x40000000u /* inferred */
#define IOC3_PPCR_V_80000000                         0x80000000u /* inferred */
#define IOC3_SIO_CR_V_70000                          0x70000u /* inferred */
#define IOC3_SIO_CR_V_AE5E                           0xae5eu /* inferred */
#define IOC3_SIO_IEC_V_7F0000                        0x7f0000u /* inferred */
#define IOC3_SIO_IEC_V_FFFF                          0xffffu /* inferred */
#define IOC3_SIO_IR_B_0                              0x1u /* inferred */
#define IOC3_SIO_IR_V_3C0000                         0x3c0000u /* inferred */
#define IOC3_SIO_IR_V_400000                         0x400000u /* inferred */
#define IOC3_UARTA_REG2_V_1                          0x1u /* inferred */
#define IOC3_UARTA_REG2_V_7                          0x7u /* inferred */
#define IOC3_UARTA_REG3_V_3                          0x3u /* inferred */
#define IOC3_UARTA_REG3_V_4                          0x4u /* inferred */
#define IOC3_UARTA_REG3_V_40                         0x40u /* inferred */
#define IOC3_UARTA_REG3_V_80                         0x80u /* inferred */
#define IOC3_UARTA_REG5_B_5                          0x20u /* inferred */

#endif /* IOC3_GEN_H */
