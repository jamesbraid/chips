/* generated from defs/ioc3_extra.toml by defs-gen - do not edit, change the source */
/* IOC3 registers outside the census */
#ifndef IOC3_GEN_H
#define IOC3_GEN_H

#include <stdint.h>


/* one_wire_ctl: rw32, reset unknown */
#define IOC3_ONE_WIRE_CTL                            0x000030 /* established */

/* plp_a_addr_hi: rw32, reset unknown */
#define IOC3_PLP_A_ADDR_HI                           0x000080 /* established */

/* plp_a_addr_lo: rw32, reset unknown */
#define IOC3_PLP_A_ADDR_LO                           0x000084 /* established */

/* plp_a_count: rw32, reset unknown */
#define IOC3_PLP_A_COUNT                             0x000088 /* established */

/* plp_ctl: rw32, reset unknown */
#define IOC3_PLP_CTL                                 0x00008c /* established */

/* plp_b_addr_hi: rw32, reset unknown */
#define IOC3_PLP_B_ADDR_HI                           0x000090 /* established */

/* plp_b_addr_lo: rw32, reset unknown */
#define IOC3_PLP_B_ADDR_LO                           0x000094 /* established */

/* plp_b_count: rw32, reset unknown */
#define IOC3_PLP_B_COUNT                             0x000098 /* established */

/* km_rx_kbd: r32, reset unknown */
#define IOC3_KM_RX_KBD                               0x0000a0 /* established */

/* km_rx_mouse: r32, reset unknown */
#define IOC3_KM_RX_MOUSE                             0x0000a4 /* established */

/* km_tx_kbd: w32, reset unknown */
#define IOC3_KM_TX_KBD                               0x0000a8 /* established */

/* km_tx_mouse: w32, reset unknown */
#define IOC3_KM_TX_MOUSE                             0x0000ac /* established */

#endif /* IOC3_GEN_H */
