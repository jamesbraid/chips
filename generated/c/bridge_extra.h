/* generated from devices/bridge/registers-extra.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 d79809f695c80a0f37db113eb9f4cd966cf14bc3f14cab4c534195c46a2ac4f8 */
/* Bridge-family registers and bits outside the census */
#ifndef BRIDGE_GEN_H
#define BRIDGE_GEN_H

#include <stdint.h>


/*
 * The widget identification word as the shipped IRIX kernel reads it for the
 * Bridge family. The kernel reads the 32-bit word at byte offset 4 of the
 * widget window (WID_OFFSET), the low half of the slot that the census lists as
 * wid_id at the slot address. It tells the layout apart by the part field.
 */
/* word WID_ID_FORMAT: 32 bits; shipped IRIX kernel binaries, per kudzu
 * docs/ip35-pcibr-registers.md */
#define BRIDGE_WID_ID_FORMAT_WIDTH                   32 /* established */
#define BRIDGE_WID_ID_FORMAT_PART_SHIFT              12 /* established */
#define BRIDGE_WID_ID_FORMAT_PART_MASK               0xffffu
#define BRIDGE_WID_ID_FORMAT_PART_INPLACE (BRIDGE_WID_ID_FORMAT_PART_MASK << BRIDGE_WID_ID_FORMAT_PART_SHIFT)
#define BRIDGE_WID_ID_FORMAT_PART_BRIDGE             49154 /* established */
#define BRIDGE_WID_ID_FORMAT_PART_XBRIDGE            53250 /* established */
#define BRIDGE_WID_ID_FORMAT_PART_PIC_BUS0           53506 /* established */
#define BRIDGE_WID_ID_FORMAT_PART_PIC_BUS1           53522 /* established */
#define BRIDGE_WID_ID_FORMAT_PART_TIOCP_A            57344 /* established */
#define BRIDGE_WID_ID_FORMAT_PART_TIOCP_B            57360 /* established */
#define BRIDGE_WID_ID_FORMAT_MANUFACTURER_SHIFT      1 /* established */
#define BRIDGE_WID_ID_FORMAT_MANUFACTURER_MASK       0x7ffu
#define BRIDGE_WID_ID_FORMAT_MANUFACTURER_INPLACE (BRIDGE_WID_ID_FORMAT_MANUFACTURER_MASK << BRIDGE_WID_ID_FORMAT_MANUFACTURER_SHIFT)
#define BRIDGE_WID_ID_FORMAT_MANUFACTURER_MFR_36     36 /* established */
#define BRIDGE_WID_ID_FORMAT_MANUFACTURER_MFR_54     54 /* established */

#define BRIDGE_CFG_FUNC_SHIFT                        0x8u /* established */
#define BRIDGE_CFG_SLOTS_32                          0x8u /* established */
#define BRIDGE_CFG_SLOT_BIAS_64                      0x1u /* established */
#define BRIDGE_CFG_SLOT_SHIFT                        0xcu /* established */
#define BRIDGE_CFG_WINDOW32_OFFSET                   0x20000u /* established */
/* established */
#define BRIDGE_CONTROL_FLASH_WR_EN                   0x80000000u
/* established */
#define BRIDGE_CONTROL_RST_PIN_N                     0xf000000u
#define BRIDGE_CONTROL_WIDGET_NUMBER                 0xfu /* established */
#define BRIDGE_DEVICE_BARRIER                        0x8000u /* established */
#define BRIDGE_DEVICE_PRECISE                        0x20000u /* established */
#define BRIDGE_DEVICE_PREFETCH                       0x40000u /* established */
#define BRIDGE_DEVICE_REALTIME                       0x200000u /* established */
#define BRIDGE_DEVICE_SIZE_64                        0x400000u /* established */
#define BRIDGE_DEVICE_SWAP_PAIR                      0x180000u /* established */
#define BRIDGE_DEVICE_SWAP_PROGRAMMED                0x2000u /* established */
/* established */
#define BRIDGE_DEVICE_WRITE_GATHER_EN                0x1800000u
#define BRIDGE_INTR_ADDR32_HI                        0x11u /* established */
#define BRIDGE_INTR_ADDR32_LO                        0x8u /* established */
#define BRIDGE_INTR_ADDR32_OFFSET                    0x134u /* established */
#define BRIDGE_INTR_ADDR32_SRC_HI                    0x2fu /* established */
#define BRIDGE_INTR_ADDR32_SRC_LO                    0x26u /* established */
#define BRIDGE_INTR_ADDR64_OFFSET                    0x130u /* established */
#define BRIDGE_INTR_COUNT                            0x8u /* established */
#define BRIDGE_INTR_STRIDE                           0x8u /* established */
/* established */
#define BRIDGE_INT_STATUS_INVALID_ADDRESS            0x1000000u
#define BRIDGE_STATUS_FLASH_SELECT                   0x40u /* established */
#define BRIDGE_TEST_PIN_CONTROL                      0x70u /* established */
#define BRIDGE_TEST_PIN_CONTROL_DATA_OUT             0xf00u /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT0              0x3u /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT1              0xcu /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT2              0x30u /* established */
#define BRIDGE_TEST_PIN_CONTROL_SELECT3              0xc0u /* established */
#define BRIDGE_WID_OFFSET                            0x4u /* established */
#define BRIDGE_WINDOW_BIT_A                          0x3fu /* established */
#define BRIDGE_WINDOW_BIT_B                          0x3cu /* established */
#define BRIDGE_WINDOW_BIT_C                          0x39u /* established */
#define XBRIDGE_TEST_PIN_CONTROL_DATA_OUT            0xff0000u /* established */

#endif /* BRIDGE_GEN_H */
