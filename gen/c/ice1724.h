/* generated from defs/ice1724.toml by defs-gen - do not edit, change the source */
/* VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller registers */
#ifndef ICE1724_GEN_H
#define ICE1724_GEN_H

#include <stdint.h>


#define ICE1724_CCS_AC97_CONF                        0x5u /* established */
#define ICE1724_CCS_GPIO_DATA                        0x14u /* established */
#define ICE1724_CCS_GPIO_DATA_HI                     0x1eu /* established */
#define ICE1724_CCS_GPIO_DIR                         0x18u /* established */
#define ICE1724_CCS_GPIO_MASK                        0x16u /* established */
#define ICE1724_CCS_GPIO_MASK_HI                     0x1fu /* established */
#define ICE1724_CCS_I2C_BYTE_ADDR                    0x11u /* established */
#define ICE1724_CCS_I2C_CTRL                         0x13u /* established */
#define ICE1724_CCS_I2C_DATA                         0x12u /* established */
#define ICE1724_CCS_I2C_DEV_ADDR                     0x10u /* established */
#define ICE1724_CCS_I2S_FEATURES                     0x6u /* established */
#define ICE1724_CCS_IRQ_MASK                         0x1u /* inferred */
#define ICE1724_CCS_IRQ_STATUS                       0x2u /* inferred */
#define ICE1724_CCS_SPDIF_CONF                       0x7u /* established */
#define ICE1724_CCS_SYSCONF                          0x4u /* established */
#define ICE1724_MT_BURST                             0x19u /* established */
#define ICE1724_MT_CAPTURE_ADDR                      0x20u /* established */
#define ICE1724_MT_CAPTURE_SIZE                      0x24u /* established */
#define ICE1724_MT_CONVERTER_RESET                   0x5u /* established */
#define ICE1724_MT_DMA_CONTROL                       0x18u /* established */
#define ICE1724_MT_DMA_INT_MASK                      0x3u /* inferred */
#define ICE1724_MT_IRQ_STATUS                        0x0u /* inferred */
#define ICE1724_MT_MCLK_128X                         0x2u /* established */
#define ICE1724_MT_PLAYBACK_ADDR                     0x10u /* established */
#define ICE1724_MT_PLAYBACK_SIZE                     0x14u /* established */
#define ICE1724_MT_RATE                              0x1u /* established */
#define ICE1724_MT_SPDIF_OUT_ADDR                    0x40u /* established */
#define ICE1724_MT_SPDIF_OUT_SIZE                    0x44u /* established */

/* hand-written helper macros */
#include "../../defs/ice1724_helpers.h"

#endif /* ICE1724_GEN_H */
