/* generated from devices/ioc4/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 3 */
/* input sha256 ccef576c800b092fc2194a8aa07585500681e875bfc599b39ac495fed053d9e6 */
/* IOC4 (PCI I/O controller, later) */
#ifndef IOC4_GEN_H
#define IOC4_GEN_H

#include <stdint.h>


/* pci_err_addr_l: rw32, reset unknown; census: 7 sites, 2 routines */
#define IOC4_PCI_ERR_ADDR_L                          0x000000 /* established */

/* pci_err_addr_h: r32, reset unknown; census: 2 sites, 2 routines */
#define IOC4_PCI_ERR_ADDR_H                          0x000004 /* established */

/* sio_ir: rw32, reset unknown; census: 13 sites, 5 routines */
#define IOC4_SIO_IR                                  0x000008 /* established */

/* other_ir: rw32, reset unknown; census: 5 sites, 5 routines */
#define IOC4_OTHER_IR                                0x00000c /* established */

/* sio_ies: rw32, reset unknown; census: 2 sites, 2 routines */
#define IOC4_SIO_IES                                 0x000010 /* established */

/* other_ies: rw32, reset unknown; census: 2 sites, 2 routines */
#define IOC4_OTHER_IES                               0x000014 /* established */

/* sio_iec: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_SIO_IEC                                 0x000018 /* established */

/* other_iec: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_OTHER_IEC                               0x00001c /* established */

/* sio_cr: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC4_SIO_CR                                  0x000020 /* established */

/* ioc4_attach: rw32, reset unknown; census: 2 sites, 1 routines */
#define IOC4_IOC4_ATTACH                             0x000024 /* established */

/* int_out: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_INT_OUT                                 0x000028 /* established */

/* gpcr_s: w32, reset unknown; census: 3 sites, 2 routines */
#define IOC4_GPCR_S                                  0x000030 /* established */

/* gpcr_c: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_GPCR_C                                  0x000034 /* established */

/* gppr0: w32, reset unknown; census: 2 sites, 1 routines */
#define IOC4_GPPR0                                   0x000040 /* established */

/* km_csr: rw32, reset unknown; census: 7 sites, 3 routines */
#define IOC4_KM_CSR                                  0x000200 /* established */

/* sbbr01_l: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_SBBR01_L                                0x000300 /* established */

/* sbbr01_h: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_SBBR01_H                                0x000304 /* established */

/* sbbr23_l: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_SBBR23_L                                0x000308 /* established */

/* sbbr23_h: w32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_SBBR23_H                                0x00030c /* established */

/* port0_sscr: rw32, reset unknown; census: 37 sites, 16 routines */
#define IOC4_PORT0_SSCR                              0x000310 /* established */

/* port0_stpir: w32, reset unknown; census: 5 sites, 4 routines */
#define IOC4_PORT0_STPIR                             0x000314 /* established */

/* port0_stcir: r32, reset unknown; census: 4 sites, 4 routines */
#define IOC4_PORT0_STCIR                             0x000318 /* established */

/* port0_srpir: r32, reset unknown; census: 5 sites, 3 routines */
#define IOC4_PORT0_SRPIR                             0x00031c /* established */

/* port0_srcir: w32, reset unknown; census: 5 sites, 3 routines */
#define IOC4_PORT0_SRCIR                             0x000320 /* established */

/* port0_srtr: w32, reset unknown; census: 3 sites, 3 routines */
#define IOC4_PORT0_SRTR                              0x000324 /* established */

/* port0_shadow: rw32, reset unknown; census: 6 sites, 4 routines */
#define IOC4_PORT0_SHADOW                            0x000328 /* established */

/* uart0_reg0: rw8, reset unknown; census: 17 sites, 5 routines */
#define IOC4_UART0_REG0                              0x000380 /* established */

/* uart0_reg4: rw8, reset unknown; census: 4 sites, 2 routines */
#define IOC4_UART0_REG4                              0x000384 /* established */

/* cfg_id: r16, reset unknown; census: 2 sites, 1 routines */
#define IOC4_CFG_ID                                  0x200000 /* established */

/* cfg_command_status: rw32, reset unknown; census: 6 sites, 2 routines */
#define IOC4_CFG_COMMAND_STATUS                      0x200004 /* established */

/* cfg_revision: r32, reset unknown; census: 1 sites, 1 routines */
#define IOC4_CFG_REVISION                            0x200008 /* established */

#define IOC4_CFG_COMMAND_STATUS_B_0                  0x1u /* inferred */
#define IOC4_CFG_COMMAND_STATUS_B_1                  0x2u /* inferred */
#define IOC4_CFG_COMMAND_STATUS_B_15_0               0xffffu /* inferred */
#define IOC4_CFG_COMMAND_STATUS_V_146                0x146u /* inferred */
#define IOC4_CFG_REVISION_B_7_0                      0xffu /* inferred */
#define IOC4_GPCR_C_V_2                              0x2u /* inferred */
#define IOC4_GPCR_S_V_200                            0x200u /* inferred */
#define IOC4_GPCR_S_V_FF00                           0xff00u /* inferred */
#define IOC4_OTHER_IR_V_40                           0x40u /* inferred */
#define IOC4_OTHER_IR_V_FF800000                     0xff800000u /* inferred */
#define IOC4_PCI_ERR_ADDR_L_B_0                      0x1u /* inferred */
#define IOC4_PCI_ERR_ADDR_L_B_1                      0x2u /* inferred */
#define IOC4_PCI_ERR_ADDR_L_B_3_0                    0xfu /* inferred */
#define IOC4_PCI_ERR_ADDR_L_B_3_1                    0xeu /* inferred */
#define IOC4_PCI_ERR_ADDR_L_B_5                      0x20u /* inferred */
#define IOC4_PORT0_SRCIR_V_80000000                  0x80000000u /* inferred */
#define IOC4_PORT0_SRPIR_B_11_3                      0xff8u /* inferred */
#define IOC4_PORT0_SRTR_V_A0                         0xa0u /* inferred */
#define IOC4_PORT0_SSCR_V_20000000                   0x20000000u /* inferred */
#define IOC4_PORT0_SSCR_V_8000000                    0x8000000u /* inferred */
#define IOC4_PORT0_SSCR_V_80000000                   0x80000000u /* inferred */
#define IOC4_PORT0_STCIR_B_11_3                      0xff8u /* inferred */
#define IOC4_SBBR01_L_V_1                            0x1u /* inferred */
#define IOC4_SBBR23_L_V_1                            0x1u /* inferred */
#define IOC4_SIO_CR_B_7                              0x80u /* inferred */
#define IOC4_SIO_CR_V_F                              0xfu /* inferred */
#define IOC4_SIO_IR_B_0                              0x1u /* inferred */
#define IOC4_UART0_REG0_V_1                          0x1u /* inferred */
#define IOC4_UART0_REG0_V_3                          0x3u /* inferred */
#define IOC4_UART0_REG0_V_4                          0x4u /* inferred */
#define IOC4_UART0_REG0_V_40                         0x40u /* inferred */
#define IOC4_UART0_REG0_V_7                          0x7u /* inferred */
#define IOC4_UART0_REG0_V_80                         0x80u /* inferred */
#define IOC4_UART0_REG4_B_5                          0x20u /* inferred */

#endif /* IOC4_GEN_H */
