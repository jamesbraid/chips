/* generated from devices/ioc3/registers-extra.toml by defs-gen - do not edit, change the source */
/* IOC3 registers outside the census */
#ifndef IOC3_GEN_H
#define IOC3_GEN_H

#include <stdint.h>


/*
 * The 32-bit microlan control register the shipped IRIX one-wire access routine drives: it writes the pulse width shifted left 10 ORed with the sample time shifted left 2, polls bit 1 (done) with no limit, and returns bit 0 (the sampled line level). Only the lowest bit of the pulse and sample fields is recorded as a position.
 */
/* one_wire_ctl: rw32, reset unknown */
#define IOC3_ONE_WIRE_CTL                            0x000030 /* established */
#define IOC3_ONE_WIRE_CTL_PULSE_SHIFT                10 /* established */
#define IOC3_ONE_WIRE_CTL_PULSE_MASK                 0x1u
#define IOC3_ONE_WIRE_CTL_PULSE_INPLACE              (IOC3_ONE_WIRE_CTL_PULSE_MASK << IOC3_ONE_WIRE_CTL_PULSE_SHIFT)
#define IOC3_ONE_WIRE_CTL_SAMPLE_SHIFT               2 /* established */
#define IOC3_ONE_WIRE_CTL_SAMPLE_MASK                0x1u
#define IOC3_ONE_WIRE_CTL_SAMPLE_INPLACE             (IOC3_ONE_WIRE_CTL_SAMPLE_MASK << IOC3_ONE_WIRE_CTL_SAMPLE_SHIFT)
#define IOC3_ONE_WIRE_CTL_DONE_SHIFT                 1 /* established */
#define IOC3_ONE_WIRE_CTL_DONE_MASK                  0x1u
#define IOC3_ONE_WIRE_CTL_DONE_INPLACE               (IOC3_ONE_WIRE_CTL_DONE_MASK << IOC3_ONE_WIRE_CTL_DONE_SHIFT)
#define IOC3_ONE_WIRE_CTL_RESULT_SHIFT               0 /* established */
#define IOC3_ONE_WIRE_CTL_RESULT_MASK                0x1u
#define IOC3_ONE_WIRE_CTL_RESULT_INPLACE             (IOC3_ONE_WIRE_CTL_RESULT_MASK << IOC3_ONE_WIRE_CTL_RESULT_SHIFT)

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

/*
 * Layout of the general-purpose control set alias, gpcr_s (offset 0x34), as the shipped IRIX one-wire routine writes it. Before reading the address part the routine stores 0x200000 to the register address its caller passes, when that address is not null; with a null address it prints that it is bypassing the enable and goes on. The word is written whole, so bit 21 is the only bit the routine sets. That the store enables the one-wire path to the part is read from the routine's own message, and that a set alias leaves other bits alone is inferred from its name.
 */
/* word GPCR_S_FORMAT: 32 bits; shipped IRIX kernel binaries, per kudzu docs/nic.md */
#define IOC3_GPCR_S_FORMAT_WIDTH                     32 /* inferred */
#define IOC3_GPCR_S_FORMAT_NIC_ENABLE_SHIFT          21 /* inferred */
#define IOC3_GPCR_S_FORMAT_NIC_ENABLE_MASK           0x1u
#define IOC3_GPCR_S_FORMAT_NIC_ENABLE_INPLACE        (IOC3_GPCR_S_FORMAT_NIC_ENABLE_MASK << IOC3_GPCR_S_FORMAT_NIC_ENABLE_SHIFT)

#define IOC3_GPCR_S_MICROLAN_ROUTE_BIT               0x200000u /* inferred */
#define IOC3_GPCR_S_NIC_ENABLE_WORD                  0x200000u /* inferred */
#define IOC3_GPPR_LIGHTBAR_RED_PIN                   0x1u /* inferred */
#define IOC3_GPPR_LIGHTBAR_WHITE_PIN                 0x0u /* inferred */
#define IOC3_GPPR_MEANINGFUL_MASK                    0x1ffu /* inferred */
#define IOC3_GPPR_MICROLAN_PIN                       0x8u /* inferred */
#define IOC3_GPPR_PHY_RESET_PIN                      0x5u /* inferred */
#define IOC3_GPPR_UARTA_MODESEL_PIN                  0x7u /* inferred */
#define IOC3_GPPR_UARTB_MODESEL_PIN                  0x6u /* inferred */
#define IOC3_INT_OUT_COUNT_MASK                      0xffffu /* inferred */
#define IOC3_INT_OUT_DIAG_BIT                        0x40000000u /* inferred */
#define IOC3_INT_OUT_MODE_HIGH                       0x4u /* inferred */
#define IOC3_INT_OUT_MODE_LOW                        0x0u /* inferred */
#define IOC3_INT_OUT_MODE_MASK                       0x70000u /* inferred */
#define IOC3_INT_OUT_MODE_ONE_PULSE                  0x5u /* inferred */
#define IOC3_INT_OUT_MODE_PULSE_TRAIN                0x6u /* inferred */
#define IOC3_INT_OUT_MODE_SQUARE                     0x7u /* inferred */
#define IOC3_INT_OUT_PIN0_ROUTE_BIT                  0x100000u /* inferred */
#define IOC3_INT_OUT_PULSE_TICKS                     0x3u /* inferred */
#define IOC3_INT_OUT_STATE_BIT                       0x80000000u /* inferred */
#define IOC3_INT_OUT_TICK_NS                         0x1e78u /* inferred */
#define IOC3_PORT_CTL_CARRIER_REQ_BIT                0x40000u /* inferred */
#define IOC3_PORT_CTL_CTS_REQ_BIT                    0x80000u /* inferred */
#define IOC3_PORT_CTL_FLOW_CTL_BIT                   0x20000u /* inferred */
#define IOC3_PORT_CTL_HIGH_WATER_MASK                0x1ffu /* inferred */
#define IOC3_PORT_CTL_QUAD_SPEED_BIT                 0x100000u /* inferred */
#define IOC3_PORT_CTL_RING_DMA_EN_BIT                0x10000000u /* inferred */
#define IOC3_SIO_CR_ARBITER_IDLE_BIT                 0x400000u /* inferred */
#define IOC3_SIO_CR_REQUESTER_MASK                   0x380000u /* inferred */
#define IOC3_SIO_CR_RESET_BIT                        0x1u /* inferred */
#define IOC3_SIO_CR_SER_A_BASE_MASK                  0xfeu /* inferred */
#define IOC3_SIO_CR_SER_B_BASE_MASK                  0x7f00u /* inferred */
#define IOC3_SIO_CR_STROBE_MASK                      0x78000u /* inferred */
#define IOC3_SIO_IR_SRC_A_CARRIER                    0x10u /* inferred */
#define IOC3_SIO_IR_SRC_A_CTS                        0x20u /* inferred */
#define IOC3_SIO_IR_SRC_A_PCI_ERR                    0x100u /* inferred */
#define IOC3_SIO_IR_SRC_A_RX_FULL                    0x2u /* inferred */
#define IOC3_SIO_IR_SRC_A_RX_HIGH                    0x4u /* inferred */
#define IOC3_SIO_IR_SRC_A_RX_TIMER                   0x8u /* inferred */
#define IOC3_SIO_IR_SRC_A_TX_DONE                    0x80u /* inferred */
#define IOC3_SIO_IR_SRC_A_TX_EMPTY                   0x1u /* inferred */
#define IOC3_SIO_IR_SRC_A_UART                       0x40u /* inferred */
#define IOC3_SIO_IR_SRC_B_CARRIER                    0x2000u /* inferred */
#define IOC3_SIO_IR_SRC_B_CTS                        0x4000u /* inferred */
#define IOC3_SIO_IR_SRC_B_PCI_ERR                    0x20000u /* inferred */
#define IOC3_SIO_IR_SRC_B_RX_FULL                    0x400u /* inferred */
#define IOC3_SIO_IR_SRC_B_RX_HIGH                    0x800u /* inferred */
#define IOC3_SIO_IR_SRC_B_RX_TIMER                   0x1000u /* inferred */
#define IOC3_SIO_IR_SRC_B_TX_DONE                    0x10000u /* inferred */
#define IOC3_SIO_IR_SRC_B_TX_EMPTY                   0x200u /* inferred */
#define IOC3_SIO_IR_SRC_B_UART                       0x8000u /* inferred */
#define IOC3_SIO_IR_SRC_KBD                          0x400000u /* inferred */
#define IOC3_SIO_IR_SRC_PP_PASSTHRU                  0x40000u /* inferred */
#define IOC3_SIO_IR_SRC_PP_PCI_ERR                   0x200000u /* inferred */
#define IOC3_SIO_IR_SRC_RT_IN_PULSE                  0x10000000u /* inferred */
#define IOC3_SIO_IR_SRC_RT_OUT_PULSE                 0x8000000u /* inferred */

#endif /* IOC3_GEN_H */
