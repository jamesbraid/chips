/* generated from devices/l1/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 4 */
/* input sha256 5d88dc9d5c83288a421175717ea9ea8c6659d4accb6cd6159a690b25d4dc2da0 */
/* L1 system controller UART path (node-local window), Origin 3000 family */
#ifndef L1_GEN_H
#define L1_GEN_H

#include <stdint.h>


/* uart_data: rw64, reset unknown; census: 13 sites, 4 routines */
#define L1_UART_DATA                                 0x000080 /* established */

/* uart_ier: rw64, reset unknown; census: 6 sites, 3 routines */
#define L1_UART_IER                                  0x000088 /* established */

/* uart_fcr_iir: rw64, reset unknown; census: 6 sites, 3 routines */
#define L1_UART_FCR_IIR                              0x000090 /* established */

/* uart_lcr: rw64, reset unknown; census: 6 sites, 3 routines */
#define L1_UART_LCR                                  0x000098 /* established */

/* uart_mcr: w64, reset unknown; census: 1 sites, 1 routines */
#define L1_UART_MCR                                  0x0000a0 /* established */

/* uart_lsr: r64, reset unknown; census: 66 sites, 6 routines */
#define L1_UART_LSR                                  0x0000a8 /* established */

/* uart_intr_clear: w64, reset unknown; census: 1 sites, 1 routines */
#define L1_UART_INTR_CLEAR                           0x800090 /* established */

/* uart_intr_pending: r64, reset unknown; census: 2 sites, 1 routines */
#define L1_UART_INTR_PENDING                         0x800098 /* established */

#define L1_UART_DATA_B_7_0                           0xffu /* inferred */
#define L1_UART_DATA_V_44                            0x44u /* inferred */
#define L1_UART_DATA_V_7E                            0x7eu /* inferred */
#define L1_UART_FCR_IIR_B_1                          0x2u /* inferred */
#define L1_UART_FCR_IIR_B_2                          0x4u /* inferred */
#define L1_UART_FCR_IIR_B_2_1                        0x6u /* inferred */
#define L1_UART_FCR_IIR_B_7_0                        0xffu /* inferred */
#define L1_UART_FCR_IIR_V_7                          0x7u /* inferred */
#define L1_UART_IER_B_7_0                            0xffu /* inferred */
#define L1_UART_INTR_PENDING_B_4                     0x10u /* inferred */
#define L1_UART_LCR_B_7_0                            0xffu /* inferred */
#define L1_UART_LSR_B_0                              0x1u /* inferred */
#define L1_UART_LSR_B_15_0                           0xffffu /* inferred */
#define L1_UART_LSR_B_3_2                            0xcu /* inferred */
#define L1_UART_LSR_B_3_2_0                          0xdu /* inferred */
#define L1_UART_LSR_B_5                              0x20u /* inferred */
#define L1_UART_LSR_B_6                              0x40u /* inferred */
#define L1_UART_LSR_B_7_0                            0xffu /* inferred */

#endif /* L1_GEN_H */
