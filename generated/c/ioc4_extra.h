/* generated from devices/ioc4/registers-extra.toml by defs-gen - do not edit, change the source */
/* IOC4 registers outside the census */
#ifndef IOC4_GEN_H
#define IOC4_GEN_H

#include <stdint.h>


/*
 * Generic pin data word. The SGI header defines it at 0x38 with bits 7:0 holding the state of the eight generic pins. Offset and name are established by the header and the PROM store; no Linux driver code read touches it, and what a write does is unknown.
 */
/* gpdr: rw32, reset unknown */
#define IOC4_GPDR                                    0x000038 /* established */

/* km_rx_kbd: r32, reset unknown */
#define IOC4_KM_RX_KBD                               0x000204 /* established */

/* km_rx_mouse: r32, reset unknown */
#define IOC4_KM_RX_MOUSE                             0x000208 /* established */

/* km_tx_kbd: w32, reset unknown */
#define IOC4_KM_TX_KBD                               0x00020c /* established */

/* km_tx_mouse: w32, reset unknown */
#define IOC4_KM_TX_MOUSE                             0x000210 /* established */

#define IOC4_ATA_DMA_CONTROL                         0x15cu /* established */
#define IOC4_ATA_DMA_CONTROL_ACTIVE                  0x8u /* established */
#define IOC4_ATA_DMA_CONTROL_DIR_TO_MEMORY           0x4u /* inferred */
#define IOC4_ATA_DMA_CONTROL_ERROR                   0x10u /* established */
#define IOC4_ATA_DMA_CONTROL_START                   0x1u /* established */
#define IOC4_ATA_DMA_CONTROL_STOP                    0x2u /* established */
#define IOC4_ATA_DMA_COUNT_DEVICE                    0x154u /* inferred */
#define IOC4_ATA_DMA_COUNT_MEMORY                    0x158u /* inferred */
#define IOC4_ATA_DMA_CURRENT_HIGH                    0x150u /* unknown */
#define IOC4_ATA_DMA_CURRENT_LOW                     0x14cu /* unknown */
#define IOC4_ATA_DMA_END_AREA                        0x160u /* inferred */
#define IOC4_ATA_DMA_LIST_HIGH                       0x148u /* inferred */
#define IOC4_ATA_DMA_LIST_LOW                        0x144u /* inferred */
#define IOC4_ATA_DMA_TIMING                          0x140u /* inferred */
#define IOC4_EXTINT_COUNT_DIVISOR                    0x208u /* established */
#define IOC4_GPCR_DIR_MASK                           0xffu /* established */
#define IOC4_GPCR_EDGE_MASK                          0xff00u /* established */
#define IOC4_GPCR_INT_OUT_EN                         0x100000u /* established */
#define IOC4_GPIO_PIN_EXT_INT_OUT                    0x0u /* established */
#define IOC4_GPIO_PIN_SERIAL_MODE_0                  0x4u /* established */
#define IOC4_INT_OUT_COUNT_MASK                      0xffffu /* established */
#define IOC4_INT_OUT_DIAG                            0x40000000u /* established */
#define IOC4_INT_OUT_MODE_MASK                       0x70000u /* established */
#define IOC4_INT_OUT_MODE_TOGGLE                     0x70000u /* established */
#define IOC4_INT_OUT_VALUE                           0x80000000u /* established */
#define IOC4_KM_CSR_AUX_CLOCK_LINE                   0x200u /* established */
#define IOC4_KM_CSR_AUX_DATA_LINE                    0x100u /* established */
#define IOC4_KM_CSR_AUX_WRITE_PENDING                0x2u /* established */
#define IOC4_KM_CSR_IDLE_B_15_14                     0xc000u /* inferred */
#define IOC4_KM_CSR_KBD_CLOCK_LINE                   0x20u /* established */
#define IOC4_KM_CSR_KBD_DATA_LINE                    0x10u /* established */
#define IOC4_KM_CSR_KBD_WRITE_PENDING                0x1u /* established */
#define IOC4_KM_CSR_LAST_WRITE_LINE_B_3_2            0xcu /* inferred */
#define IOC4_OTHER_IR_ATA_INT                        0x1u /* established */
#define IOC4_OTHER_IR_ATA_MEMERR                     0x2u /* established */
#define IOC4_OTHER_IR_GEN_INT                        0xff000000u /* established */
#define IOC4_OTHER_IR_KBM                            0x40u /* established */
#define IOC4_OTHER_IR_RT_INT                         0x800000u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_0                   0x4u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_1                   0x8u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_2                   0x10u /* established */
#define IOC4_OTHER_IR_SER_MEMERR_3                   0x20u /* established */
#define IOC4_PCI_CLASS_CODE                          0xb4000u /* established */
#define IOC4_SERIAL_RING_PTR_B_9_3                   0x3f8u /* inferred */
#define IOC4_SERIAL_RX_TIMER_COUNT_B_27_16           0xfff0000u /* inferred */
#define IOC4_SERIAL_RX_TIMER_RELOAD_B_11_0           0xfffu /* inferred */
#define IOC4_SERIAL_SHADOW_CTS_V_100000              0x100000u /* inferred */
#define IOC4_SERIAL_SHADOW_DCD_V_800000              0x800000u /* inferred */
#define IOC4_SERIAL_SHADOW_DCTS_V_10000              0x10000u /* inferred */
#define IOC4_SERIAL_SHADOW_DDCD_V_80000              0x80000u /* inferred */
#define IOC4_SERIAL_SHADOW_OUTPUTS_B_28_24           0x1f000000u /* inferred */
#define IOC4_SERIAL_SHADOW_RX_FLAGS_B_7_0            0xffu /* inferred */
#define IOC4_SERIAL_SRCIR_TIMER_ARM_V_80000000       0x80000000u /* inferred */
#define IOC4_SIO_CR_ARB_DIAG                         0x70u /* established */
#define IOC4_SIO_CR_ATA_DIAG_ACTIVE                  0x200u /* established */
#define IOC4_SIO_CR_ATA_DIAG_IDLE                    0x100u /* established */
#define IOC4_SIO_CR_CMD_PULSE                        0xfu /* established */
#define IOC4_SIO_CR_SIO_DIAG_IDLE                    0x80u /* established */
#define IOC4_SIO_IR_SRC_UART_0                       0x40u /* established */
#define IOC4_SIO_IR_SRC_UART_1                       0x4000u /* established */
#define IOC4_SIO_IR_SRC_UART_2                       0x400000u /* established */
#define IOC4_SIO_IR_SRC_UART_3                       0x40000000u /* established */

#endif /* IOC4_GEN_H */
