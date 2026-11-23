/* generated from devices/xframe/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 3 */
/* input sha256 3f1ba58411bf364f6941e22e5f572e709f77f3c0d7ce1256a016fceffaeb02e0 */
/* Neterion Xframe 10-Gigabit Ethernet controller (SGI 10-Gigabit Ethernet
 * card), the offsets, bits and layouts the held sources establish */
#ifndef XFRAME_GEN_H
#define XFRAME_GEN_H

#include <stdint.h>


/* inferred */
#define XFRAME_ADAPTER_STATUS_RMAC_LOCAL_FAULT       0x100000000000000ull
/* inferred */
#define XFRAME_ADAPTER_STATUS_RMAC_REMOTE_FAULT      0x200000000000000ull
#define XFRAME_DESCRIPTOR_PAGE_BYTES                 0x1000u /* inferred */
#define XFRAME_DMA_CHANNELS                          0x10u /* established */
#define XFRAME_GENERAL_INT_MASK_ENABLE               0x0u /* inferred */
#define XFRAME_MAC_RMAC_ERR_REG_OFFSET               0x2028u /* inferred */
/* inferred */
#define XFRAME_MAC_RMAC_LINK_STATE_CHANGE            0x100000000ull
#define XFRAME_PIC_INT_MASK_OFFSET                   0x808u /* inferred */
/* inferred */
#define XFRAME_PIC_INT_TX                            0x8000000000000000ull
#define XFRAME_RING_MODE_1                           0x0u /* inferred */
#define XFRAME_RING_MODE_3                           0x1u /* inferred */
#define XFRAME_RING_MODE_5                           0x2u /* inferred */
#define XFRAME_RXD_FIVE_BUFFER_BYTES                 0x40u /* inferred */
#define XFRAME_RXD_FIVE_BUFFER_CONTROL_WORDS         0x3u /* inferred */
#define XFRAME_RXD_FIVE_BUFFER_POINTERS              0x5u /* inferred */
#define XFRAME_SCHEDULED_INT_CTRL_OFFSET             0x918u /* inferred */
/* inferred */
#define XFRAME_SCHED_INT_CTRL_TIMER_EN               0x8000000000000000ull
#define XFRAME_SWAPPER_CTRL_HIGH_OFFSET              0x90cu /* established */
/* established */
#define XFRAME_SWAPPER_CTRL_HIGH_VALUE               0xffffeaffu
#define XFRAME_SWAPPER_CTRL_LOW_OFFSET               0x908u /* established */
/* established */
#define XFRAME_SWAPPER_CTRL_LOW_VALUE                0xabffbfffu
#define XFRAME_TXD_WORDS                             0x4u /* inferred */
#define XFRAME_TXPIC_INT_MASK_OFFSET                 0x818u /* inferred */
#define XFRAME_TXPIC_INT_REG_OFFSET                  0x810u /* inferred */
#define XFRAME_WATCHDOG_CHECK_SECONDS                0x1u /* inferred */
#define XFRAME_WATCHDOG_RESET_COUNT                  0xfu /* inferred */

#endif /* XFRAME_GEN_H */
