/* generated from defs/bridge_extra.toml by defs-gen - do not edit, change the source */
/* Bridge-family registers and bits outside the census */
#ifndef BRIDGE_GEN_H
#define BRIDGE_GEN_H

#include <stdint.h>


#define BRIDGE_CONTROL_FLASH_WR_EN                   0x80000000u /* established */
#define BRIDGE_CONTROL_RST_PIN_N                     0xf000000u /* established */
#define BRIDGE_CONTROL_WIDGET_NUMBER                 0xfu /* established */
#define BRIDGE_DEVICE_BARRIER                        0x8000u /* established */
#define BRIDGE_DEVICE_PRECISE                        0x20000u /* established */
#define BRIDGE_DEVICE_PREFETCH                       0x40000u /* established */
#define BRIDGE_DEVICE_REALTIME                       0x200000u /* established */
#define BRIDGE_DEVICE_SIZE_64                        0x400000u /* established */
#define BRIDGE_DEVICE_SWAP_PAIR                      0x180000u /* established */
#define BRIDGE_DEVICE_SWAP_PROGRAMMED                0x2000u /* established */
#define BRIDGE_DEVICE_WRITE_GATHER_EN                0x1800000u /* established */
#define BRIDGE_INT_STATUS_INVALID_ADDRESS            0x1000000u /* established */
#define BRIDGE_STATUS_FLASH_SELECT                   0x40u /* established */
#define BRIDGE_TEST_PIN_CONTROL                      0x70u /* established */
#define BRIDGE_TEST_PIN_CONTROL_DATA_OUT             0xf00u /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT0              0x3u /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT1              0xcu /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT2              0x30u /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT3              0xc0u /* established */
#define XBRIDGE_TEST_PIN_CONTROL_DATA_OUT            0xff0000u /* established */

#endif /* BRIDGE_GEN_H */
