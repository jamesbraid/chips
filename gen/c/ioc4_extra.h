/* generated from defs/ioc4_extra.toml by defs-gen - do not edit, change the source */
/* IOC4 registers outside the census */
#ifndef IOC4_GEN_H
#define IOC4_GEN_H

#include <stdint.h>


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
#define IOC4_SIO_CR_CMD_PULSE                        0xfu /* established */
#define IOC4_SIO_CR_SIO_DIAG_IDLE                    0x80u /* established */

#endif /* IOC4_GEN_H */
