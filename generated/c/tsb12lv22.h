/* generated from devices/tsb12lv22/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 7c0c9c2e3187c6789010517cad60bcc61d96bd60b2a5cd37bd3bb1bc955da983 */
/* TI TSB12LV22 PCI-to-IEEE 1394 OHCI 1.00 link controller (I-brick IO7), the register facts the held sources establish */
#ifndef TSB12LV22_GEN_H
#define TSB12LV22_GEN_H

#include <stdint.h>


/*
 * OHCI version. Major version 1 is in bits 23:16 and minor version 0 in bits 7:0, so this is OHCI 1.00. Bit 24 reports whether a configuration ROM is present, sampled from ROM detection. The reset value shown is for the no-ROM case.
 */
/* version: r32, reset 0x10000; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_VERSION_OFFSET                     0x0u /* established */
#define TSB12LV22_VERSION_ROM_PRESENT_SHIFT          24 /* established */
#define TSB12LV22_VERSION_ROM_PRESENT_MASK           0x1u
#define TSB12LV22_VERSION_ROM_PRESENT_INPLACE        (TSB12LV22_VERSION_ROM_PRESENT_MASK << TSB12LV22_VERSION_ROM_PRESENT_SHIFT)
#define TSB12LV22_VERSION_MAJOR_SHIFT                16 /* established */
#define TSB12LV22_VERSION_MAJOR_MASK                 0xffu
#define TSB12LV22_VERSION_MAJOR_INPLACE              (TSB12LV22_VERSION_MAJOR_MASK << TSB12LV22_VERSION_MAJOR_SHIFT)
#define TSB12LV22_VERSION_MINOR_SHIFT                0 /* established */
#define TSB12LV22_VERSION_MINOR_MASK                 0xffu
#define TSB12LV22_VERSION_MINOR_INPLACE              (TSB12LV22_VERSION_MINOR_MASK << TSB12LV22_VERSION_MINOR_SHIFT)

/*
 * GUID ROM access. Writing the address-reset bit resets the ROM read address, and the bit clears itself. Writing the read-start bit starts a read, and the byte read appears in the read-data field. The data is unspecified at reset and the command bits read as zero.
 */
/* guid_rom: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_GUID_ROM_OFFSET                    0x4u /* established */
#define TSB12LV22_GUID_ROM_ADDRESS_RESET_SHIFT       31 /* established */
#define TSB12LV22_GUID_ROM_ADDRESS_RESET_MASK        0x1u
#define TSB12LV22_GUID_ROM_ADDRESS_RESET_INPLACE     (TSB12LV22_GUID_ROM_ADDRESS_RESET_MASK << TSB12LV22_GUID_ROM_ADDRESS_RESET_SHIFT)
#define TSB12LV22_GUID_ROM_READ_START_SHIFT          25 /* established */
#define TSB12LV22_GUID_ROM_READ_START_MASK           0x1u
#define TSB12LV22_GUID_ROM_READ_START_INPLACE        (TSB12LV22_GUID_ROM_READ_START_MASK << TSB12LV22_GUID_ROM_READ_START_SHIFT)
#define TSB12LV22_GUID_ROM_READ_DATA_SHIFT           16 /* established */
#define TSB12LV22_GUID_ROM_READ_DATA_MASK            0xffu
#define TSB12LV22_GUID_ROM_READ_DATA_INPLACE         (TSB12LV22_GUID_ROM_READ_DATA_MASK << TSB12LV22_GUID_ROM_READ_DATA_SHIFT)

/*
 * Retry counts. Three read-write count fields are defined. The outbound dual-phase retry fields read as zero. The datasheet summary does not name the three count fields, so the field names here are positional.
 */
/* retry_counts: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_RETRY_COUNTS_OFFSET                0x8u /* established */
#define TSB12LV22_RETRY_COUNTS_DUAL_PHASE_RETRY_SHIFT 16 /* established */
#define TSB12LV22_RETRY_COUNTS_DUAL_PHASE_RETRY_MASK 0xffffu
#define TSB12LV22_RETRY_COUNTS_DUAL_PHASE_RETRY_INPLACE (TSB12LV22_RETRY_COUNTS_DUAL_PHASE_RETRY_MASK << TSB12LV22_RETRY_COUNTS_DUAL_PHASE_RETRY_SHIFT)
#define TSB12LV22_RETRY_COUNTS_COUNT_11_8_SHIFT      8 /* established */
#define TSB12LV22_RETRY_COUNTS_COUNT_11_8_MASK       0xfu
#define TSB12LV22_RETRY_COUNTS_COUNT_11_8_INPLACE    (TSB12LV22_RETRY_COUNTS_COUNT_11_8_MASK << TSB12LV22_RETRY_COUNTS_COUNT_11_8_SHIFT)
#define TSB12LV22_RETRY_COUNTS_COUNT_7_4_SHIFT       4 /* established */
#define TSB12LV22_RETRY_COUNTS_COUNT_7_4_MASK        0xfu
#define TSB12LV22_RETRY_COUNTS_COUNT_7_4_INPLACE     (TSB12LV22_RETRY_COUNTS_COUNT_7_4_MASK << TSB12LV22_RETRY_COUNTS_COUNT_7_4_SHIFT)
#define TSB12LV22_RETRY_COUNTS_COUNT_3_0_SHIFT       0 /* established */
#define TSB12LV22_RETRY_COUNTS_COUNT_3_0_MASK        0xfu
#define TSB12LV22_RETRY_COUNTS_COUNT_3_0_INPLACE     (TSB12LV22_RETRY_COUNTS_COUNT_3_0_MASK << TSB12LV22_RETRY_COUNTS_COUNT_3_0_SHIFT)

/*
 * CSR data word for serial bus register transfers. Unspecified at reset.
 */
/* csr_data: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_CSR_DATA_OFFSET                    0xcu /* established */

/*
 * CSR compare word. Unspecified at reset.
 */
/* csr_compare: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_CSR_COMPARE_OFFSET                 0x10u /* established */

/*
 * CSR control. Writing clears the done bit, which the controller sets on completion. The resource select is unspecified at reset, and the done bit is set at reset.
 */
/* csr_control: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_CSR_CONTROL_OFFSET                 0x14u /* established */
#define TSB12LV22_CSR_CONTROL_DONE_SHIFT             31 /* established */
#define TSB12LV22_CSR_CONTROL_DONE_MASK              0x1u
#define TSB12LV22_CSR_CONTROL_DONE_INPLACE           (TSB12LV22_CSR_CONTROL_DONE_MASK << TSB12LV22_CSR_CONTROL_DONE_SHIFT)
#define TSB12LV22_CSR_CONTROL_RESOURCE_SELECT_SHIFT  0 /* established */
#define TSB12LV22_CSR_CONTROL_RESOURCE_SELECT_MASK   0x3u
#define TSB12LV22_CSR_CONTROL_RESOURCE_SELECT_INPLACE (TSB12LV22_CSR_CONTROL_RESOURCE_SELECT_MASK << TSB12LV22_CSR_CONTROL_RESOURCE_SELECT_SHIFT)

/*
 * Configuration ROM header. The upper 16 bits read as zero at reset. The low 16 bits hold the CRC, which is unspecified without a ROM.
 */
/* config_rom_header: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_CONFIG_ROM_HEADER_OFFSET           0x18u /* established */

/*
 * Constant BusID. The value is the ASCII text 1394.
 */
/* bus_id: r32, reset 0x31333934; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_BUS_ID_OFFSET                      0x1cu /* established */

/*
 * Bus options. Bits 31:27, 23:16, 15:12 and 7:6 are writable. Link speed reads as 2. Bit 27 resets to zero. The max_rec field survives SoftReset with its hardware default of 2048 bytes. Other bits have unspecified reset values.
 */
/* bus_options: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_BUS_OPTIONS_OFFSET                 0x20u /* established */
#define TSB12LV22_BUS_OPTIONS_MAX_REC_SHIFT          12 /* established */
#define TSB12LV22_BUS_OPTIONS_MAX_REC_MASK           0xfu
#define TSB12LV22_BUS_OPTIONS_MAX_REC_INPLACE        (TSB12LV22_BUS_OPTIONS_MAX_REC_MASK << TSB12LV22_BUS_OPTIONS_MAX_REC_SHIFT)
#define TSB12LV22_BUS_OPTIONS_LINK_SPEED_SHIFT       0 /* established */
#define TSB12LV22_BUS_OPTIONS_LINK_SPEED_MASK        0x7u
#define TSB12LV22_BUS_OPTIONS_LINK_SPEED_INPLACE     (TSB12LV22_BUS_OPTIONS_LINK_SPEED_MASK << TSB12LV22_BUS_OPTIONS_LINK_SPEED_SHIFT)

/*
 * GUID high word. It reads as zero before a ROM load. Without a ROM each GUID register can be written once and then locks, and that lock state is separate from the register's value.
 */
/* guid_hi: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_GUID_HI_OFFSET                     0x24u /* established */

/*
 * GUID low word. The write-once rule for the high word applies here too.
 */
/* guid_lo: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_GUID_LO_OFFSET                     0x28u /* established */

/*
 * Configuration ROM mapping address. Bits 31:10 are read-write and reset to zero.
 */
/* config_rom_map: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_CONFIG_ROM_MAP_OFFSET              0x34u /* established */

/*
 * Posted-write error address and source reporting, read and updated by the controller, at the offset and four bytes above it. The datasheet summary gives the pair as one address and source record and does not split it per word. Unspecified at reset.
 */
/* posted_write_error: r32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_POSTED_WRITE_ERROR_OFFSET          0x38u /* established */
#define TSB12LV22_POSTED_WRITE_ERROR_COUNT           2
#define TSB12LV22_POSTED_WRITE_ERROR_STRIDE          4

/*
 * OHCI vendor-specific identifier. Read only, reads zero.
 */
/* vendor_specific_id: r32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_VENDOR_SPECIFIC_ID_OFFSET          0x40u /* established */

/*
 * HCControl. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 30 and 18 are unspecified at reset and the other defined bits reset to zero.
 */
/* hc_control: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_HC_CONTROL_OFFSET                  0x50u /* established */
#define TSB12LV22_HC_CONTROL_NO_BYTE_SWAP_DATA_SHIFT 30 /* established */
#define TSB12LV22_HC_CONTROL_NO_BYTE_SWAP_DATA_MASK  0x1u
#define TSB12LV22_HC_CONTROL_NO_BYTE_SWAP_DATA_INPLACE (TSB12LV22_HC_CONTROL_NO_BYTE_SWAP_DATA_MASK << TSB12LV22_HC_CONTROL_NO_BYTE_SWAP_DATA_SHIFT)
#define TSB12LV22_HC_CONTROL_PROGRAM_PHY_ENABLE_SHIFT 23 /* established */
#define TSB12LV22_HC_CONTROL_PROGRAM_PHY_ENABLE_MASK 0x1u
#define TSB12LV22_HC_CONTROL_PROGRAM_PHY_ENABLE_INPLACE (TSB12LV22_HC_CONTROL_PROGRAM_PHY_ENABLE_MASK << TSB12LV22_HC_CONTROL_PROGRAM_PHY_ENABLE_SHIFT)
#define TSB12LV22_HC_CONTROL_APHY_ENHANCE_ENABLE_SHIFT 22 /* established */
#define TSB12LV22_HC_CONTROL_APHY_ENHANCE_ENABLE_MASK 0x1u
#define TSB12LV22_HC_CONTROL_APHY_ENHANCE_ENABLE_INPLACE (TSB12LV22_HC_CONTROL_APHY_ENHANCE_ENABLE_MASK << TSB12LV22_HC_CONTROL_APHY_ENHANCE_ENABLE_SHIFT)
#define TSB12LV22_HC_CONTROL_LPS_SHIFT               19 /* established */
#define TSB12LV22_HC_CONTROL_LPS_MASK                0x1u
#define TSB12LV22_HC_CONTROL_LPS_INPLACE             (TSB12LV22_HC_CONTROL_LPS_MASK << TSB12LV22_HC_CONTROL_LPS_SHIFT)
#define TSB12LV22_HC_CONTROL_POSTED_WRITE_ENABLE_SHIFT 18 /* established */
#define TSB12LV22_HC_CONTROL_POSTED_WRITE_ENABLE_MASK 0x1u
#define TSB12LV22_HC_CONTROL_POSTED_WRITE_ENABLE_INPLACE (TSB12LV22_HC_CONTROL_POSTED_WRITE_ENABLE_MASK << TSB12LV22_HC_CONTROL_POSTED_WRITE_ENABLE_SHIFT)
#define TSB12LV22_HC_CONTROL_LINK_ENABLE_SHIFT       17 /* established */
#define TSB12LV22_HC_CONTROL_LINK_ENABLE_MASK        0x1u
#define TSB12LV22_HC_CONTROL_LINK_ENABLE_INPLACE     (TSB12LV22_HC_CONTROL_LINK_ENABLE_MASK << TSB12LV22_HC_CONTROL_LINK_ENABLE_SHIFT)
#define TSB12LV22_HC_CONTROL_SOFT_RESET_SHIFT        16 /* established */
#define TSB12LV22_HC_CONTROL_SOFT_RESET_MASK         0x1u
#define TSB12LV22_HC_CONTROL_SOFT_RESET_INPLACE      (TSB12LV22_HC_CONTROL_SOFT_RESET_MASK << TSB12LV22_HC_CONTROL_SOFT_RESET_SHIFT)

/*
 * Self-ID buffer pointer. The address is 2 KiB aligned, so its low 11 bits read as zero. The address is unspecified at reset.
 */
/* self_id_buffer: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_SELF_ID_BUFFER_OFFSET              0x64u /* established */
#define TSB12LV22_SELF_ID_BUFFER_ADDRESS_SHIFT       11 /* established */
#define TSB12LV22_SELF_ID_BUFFER_ADDRESS_MASK        0x1fffffu
#define TSB12LV22_SELF_ID_BUFFER_ADDRESS_INPLACE     (TSB12LV22_SELF_ID_BUFFER_ADDRESS_MASK << TSB12LV22_SELF_ID_BUFFER_ADDRESS_SHIFT)

/*
 * Self-ID count. The error and generation fields are unspecified at reset and the size field resets to zero. The controller updates the fields on bus events.
 */
/* self_id_count: r32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_SELF_ID_COUNT_OFFSET               0x68u /* established */
#define TSB12LV22_SELF_ID_COUNT_ERROR_SHIFT          31 /* established */
#define TSB12LV22_SELF_ID_COUNT_ERROR_MASK           0x1u
#define TSB12LV22_SELF_ID_COUNT_ERROR_INPLACE        (TSB12LV22_SELF_ID_COUNT_ERROR_MASK << TSB12LV22_SELF_ID_COUNT_ERROR_SHIFT)
#define TSB12LV22_SELF_ID_COUNT_GENERATION_SHIFT     16 /* established */
#define TSB12LV22_SELF_ID_COUNT_GENERATION_MASK      0xffu
#define TSB12LV22_SELF_ID_COUNT_GENERATION_INPLACE   (TSB12LV22_SELF_ID_COUNT_GENERATION_MASK << TSB12LV22_SELF_ID_COUNT_GENERATION_SHIFT)
#define TSB12LV22_SELF_ID_COUNT_SIZE_SHIFT           2 /* established */
#define TSB12LV22_SELF_ID_COUNT_SIZE_MASK            0x1ffu
#define TSB12LV22_SELF_ID_COUNT_SIZE_INPLACE         (TSB12LV22_SELF_ID_COUNT_SIZE_MASK << TSB12LV22_SELF_ID_COUNT_SIZE_SHIFT)

/*
 * Receive channel mask high, channels 32 to 63 (IRChannelMaskHiSet at 0x70 and its clear register at 0x74, Table 20 and Table 32). The set and clear addresses form a pair, the clear address four bytes above the set address. Unspecified at reset.
 */
/* recv_channel_mask_hi: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_RECV_CHANNEL_MASK_HI_OFFSET        0x70u /* established */

/*
 * Receive channel mask low, channels 0 to 31 (IRChannelMaskLoSet at 0x78 and its clear register at 0x7c, Table 20). The set and clear addresses form a pair, the clear address four bytes above the set address. Unspecified at reset.
 */
/* recv_channel_mask_lo: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_RECV_CHANNEL_MASK_LO_OFFSET        0x78u /* established */

/*
 * Interrupt events. The set and clear addresses form a pair, the clear address four bytes above the set address. Reads of the clear register return the event bits ANDed with the mask. Implemented event bits are unspecified at reset. Bits 7 and 6 are derived summaries and are not independent latches. Bit 30 is vendor-defined and its meaning is not given. Bit 18 is undefined for OHCI 1.00 and must read zero.
 */
/* int_event: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_INT_EVENT_OFFSET                   0x80u /* established */
#define TSB12LV22_INT_EVENT_PHY_REG_RECEIVED_SHIFT   19 /* established */
#define TSB12LV22_INT_EVENT_PHY_REG_RECEIVED_MASK    0x1u
#define TSB12LV22_INT_EVENT_PHY_REG_RECEIVED_INPLACE (TSB12LV22_INT_EVENT_PHY_REG_RECEIVED_MASK << TSB12LV22_INT_EVENT_PHY_REG_RECEIVED_SHIFT)
#define TSB12LV22_INT_EVENT_BUS_RESET_SHIFT          17 /* established */
#define TSB12LV22_INT_EVENT_BUS_RESET_MASK           0x1u
#define TSB12LV22_INT_EVENT_BUS_RESET_INPLACE        (TSB12LV22_INT_EVENT_BUS_RESET_MASK << TSB12LV22_INT_EVENT_BUS_RESET_SHIFT)
#define TSB12LV22_INT_EVENT_SELF_ID_COMPLETE_SHIFT   16 /* established */
#define TSB12LV22_INT_EVENT_SELF_ID_COMPLETE_MASK    0x1u
#define TSB12LV22_INT_EVENT_SELF_ID_COMPLETE_INPLACE (TSB12LV22_INT_EVENT_SELF_ID_COMPLETE_MASK << TSB12LV22_INT_EVENT_SELF_ID_COMPLETE_SHIFT)
#define TSB12LV22_INT_EVENT_ISO_RECV_SUMMARY_SHIFT   7 /* established */
#define TSB12LV22_INT_EVENT_ISO_RECV_SUMMARY_MASK    0x1u
#define TSB12LV22_INT_EVENT_ISO_RECV_SUMMARY_INPLACE (TSB12LV22_INT_EVENT_ISO_RECV_SUMMARY_MASK << TSB12LV22_INT_EVENT_ISO_RECV_SUMMARY_SHIFT)
#define TSB12LV22_INT_EVENT_ISO_XMIT_SUMMARY_SHIFT   6 /* established */
#define TSB12LV22_INT_EVENT_ISO_XMIT_SUMMARY_MASK    0x1u
#define TSB12LV22_INT_EVENT_ISO_XMIT_SUMMARY_INPLACE (TSB12LV22_INT_EVENT_ISO_XMIT_SUMMARY_MASK << TSB12LV22_INT_EVENT_ISO_XMIT_SUMMARY_SHIFT)

/*
 * Interrupt mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Reading either address of the pair returns the mask. Pending event state stays separate from the mask, and the interrupt output must be recomputed when the mask changes. Implemented mask bits are unspecified at reset.
 */
/* int_mask: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_INT_MASK_OFFSET                    0x88u /* established */
#define TSB12LV22_INT_MASK_MASTER_INT_ENABLE_SHIFT   31 /* established */
#define TSB12LV22_INT_MASK_MASTER_INT_ENABLE_MASK    0x1u
#define TSB12LV22_INT_MASK_MASTER_INT_ENABLE_INPLACE (TSB12LV22_INT_MASK_MASTER_INT_ENABLE_MASK << TSB12LV22_INT_MASK_MASTER_INT_ENABLE_SHIFT)

/*
 * Isochronous transmit event, one bit per context. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 7:0 are defined. The low byte is unspecified at reset and the upper bits read as zero.
 */
/* iso_xmit_event: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_ISO_XMIT_EVENT_OFFSET              0x90u /* established */
#define TSB12LV22_ISO_XMIT_EVENT_CONTEXTS_SHIFT      0 /* established */
#define TSB12LV22_ISO_XMIT_EVENT_CONTEXTS_MASK       0xffu
#define TSB12LV22_ISO_XMIT_EVENT_CONTEXTS_INPLACE    (TSB12LV22_ISO_XMIT_EVENT_CONTEXTS_MASK << TSB12LV22_ISO_XMIT_EVENT_CONTEXTS_SHIFT)

/*
 * Isochronous transmit mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 7:0 are defined. The low byte is unspecified at reset and the upper bits read as zero.
 */
/* iso_xmit_mask: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_ISO_XMIT_MASK_OFFSET               0x98u /* established */
#define TSB12LV22_ISO_XMIT_MASK_CONTEXTS_SHIFT       0 /* established */
#define TSB12LV22_ISO_XMIT_MASK_CONTEXTS_MASK        0xffu
#define TSB12LV22_ISO_XMIT_MASK_CONTEXTS_INPLACE     (TSB12LV22_ISO_XMIT_MASK_CONTEXTS_MASK << TSB12LV22_ISO_XMIT_MASK_CONTEXTS_SHIFT)

/*
 * Isochronous receive event. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 3:0 are defined, one per context. The low nibble is unspecified at reset and the upper bits read as zero. The datasheet summary does not state the context count, so four contexts is inferred from the bit count.
 */
/* iso_recv_event: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_ISO_RECV_EVENT_OFFSET              0xa0u /* established */
#define TSB12LV22_ISO_RECV_EVENT_CONTEXTS_SHIFT      0 /* inferred */
#define TSB12LV22_ISO_RECV_EVENT_CONTEXTS_MASK       0xfu
#define TSB12LV22_ISO_RECV_EVENT_CONTEXTS_INPLACE    (TSB12LV22_ISO_RECV_EVENT_CONTEXTS_MASK << TSB12LV22_ISO_RECV_EVENT_CONTEXTS_SHIFT)

/*
 * Isochronous receive mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 3:0 are defined. The low nibble is unspecified at reset and the upper bits read as zero.
 */
/* iso_recv_mask: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_ISO_RECV_MASK_OFFSET               0xa8u /* established */
#define TSB12LV22_ISO_RECV_MASK_CONTEXTS_SHIFT       0 /* inferred */
#define TSB12LV22_ISO_RECV_MASK_CONTEXTS_MASK        0xfu
#define TSB12LV22_ISO_RECV_MASK_CONTEXTS_INPLACE     (TSB12LV22_ISO_RECV_MASK_CONTEXTS_MASK << TSB12LV22_ISO_RECV_MASK_CONTEXTS_SHIFT)

/*
 * Optional fairness control. The low byte is a read-only priority-request limit that resets to zero. The upper bits are unspecified at reset.
 */
/* fairness_control: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_FAIRNESS_CONTROL_OFFSET            0xdcu /* established */
#define TSB12LV22_FAIRNESS_CONTROL_PRIORITY_REQUEST_LIMIT_SHIFT 0 /* established */
#define TSB12LV22_FAIRNESS_CONTROL_PRIORITY_REQUEST_LIMIT_MASK 0xffu
#define TSB12LV22_FAIRNESS_CONTROL_PRIORITY_REQUEST_LIMIT_INPLACE (TSB12LV22_FAIRNESS_CONTROL_PRIORITY_REQUEST_LIMIT_MASK << TSB12LV22_FAIRNESS_CONTROL_PRIORITY_REQUEST_LIMIT_SHIFT)

/*
 * Link control. The set and clear addresses form a pair, the clear address four bytes above the set address. The defined bits are unspecified at reset and the other bits in the datasheet's diagram reset to zero.
 */
/* link_control: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_LINK_CONTROL_OFFSET                0xe0u /* established */
#define TSB12LV22_LINK_CONTROL_CYCLE_SOURCE_SHIFT    22 /* established */
#define TSB12LV22_LINK_CONTROL_CYCLE_SOURCE_MASK     0x1u
#define TSB12LV22_LINK_CONTROL_CYCLE_SOURCE_INPLACE  (TSB12LV22_LINK_CONTROL_CYCLE_SOURCE_MASK << TSB12LV22_LINK_CONTROL_CYCLE_SOURCE_SHIFT)
#define TSB12LV22_LINK_CONTROL_CYCLE_MASTER_SHIFT    21 /* established */
#define TSB12LV22_LINK_CONTROL_CYCLE_MASTER_MASK     0x1u
#define TSB12LV22_LINK_CONTROL_CYCLE_MASTER_INPLACE  (TSB12LV22_LINK_CONTROL_CYCLE_MASTER_MASK << TSB12LV22_LINK_CONTROL_CYCLE_MASTER_SHIFT)
#define TSB12LV22_LINK_CONTROL_CYCLE_TIMER_ENABLE_SHIFT 20 /* established */
#define TSB12LV22_LINK_CONTROL_CYCLE_TIMER_ENABLE_MASK 0x1u
#define TSB12LV22_LINK_CONTROL_CYCLE_TIMER_ENABLE_INPLACE (TSB12LV22_LINK_CONTROL_CYCLE_TIMER_ENABLE_MASK << TSB12LV22_LINK_CONTROL_CYCLE_TIMER_ENABLE_SHIFT)
#define TSB12LV22_LINK_CONTROL_RCV_PHY_PACKETS_SHIFT 10 /* established */
#define TSB12LV22_LINK_CONTROL_RCV_PHY_PACKETS_MASK  0x1u
#define TSB12LV22_LINK_CONTROL_RCV_PHY_PACKETS_INPLACE (TSB12LV22_LINK_CONTROL_RCV_PHY_PACKETS_MASK << TSB12LV22_LINK_CONTROL_RCV_PHY_PACKETS_SHIFT)
#define TSB12LV22_LINK_CONTROL_RCV_SELF_ID_PACKETS_SHIFT 9 /* established */
#define TSB12LV22_LINK_CONTROL_RCV_SELF_ID_PACKETS_MASK 0x1u
#define TSB12LV22_LINK_CONTROL_RCV_SELF_ID_PACKETS_INPLACE (TSB12LV22_LINK_CONTROL_RCV_SELF_ID_PACKETS_MASK << TSB12LV22_LINK_CONTROL_RCV_SELF_ID_PACKETS_SHIFT)

/*
 * Node ID. Validity, root and cable-power status are read and updated by the controller and reset to zero. The bus number resets to all ones. The physical node number is unspecified at reset. The datasheet names a cable-power status bit but its position is not in the summary, so it is not listed as a field.
 */
/* node_id: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_NODE_ID_OFFSET                     0xe8u /* established */
#define TSB12LV22_NODE_ID_ID_VALID_SHIFT             31 /* established */
#define TSB12LV22_NODE_ID_ID_VALID_MASK              0x1u
#define TSB12LV22_NODE_ID_ID_VALID_INPLACE           (TSB12LV22_NODE_ID_ID_VALID_MASK << TSB12LV22_NODE_ID_ID_VALID_SHIFT)
#define TSB12LV22_NODE_ID_ROOT_SHIFT                 30 /* established */
#define TSB12LV22_NODE_ID_ROOT_MASK                  0x1u
#define TSB12LV22_NODE_ID_ROOT_INPLACE               (TSB12LV22_NODE_ID_ROOT_MASK << TSB12LV22_NODE_ID_ROOT_SHIFT)
#define TSB12LV22_NODE_ID_BUS_NUMBER_SHIFT           6 /* established */
#define TSB12LV22_NODE_ID_BUS_NUMBER_MASK            0x3ffu
#define TSB12LV22_NODE_ID_BUS_NUMBER_INPLACE         (TSB12LV22_NODE_ID_BUS_NUMBER_MASK << TSB12LV22_NODE_ID_BUS_NUMBER_SHIFT)
#define TSB12LV22_NODE_ID_NODE_NUMBER_SHIFT          0 /* established */
#define TSB12LV22_NODE_ID_NODE_NUMBER_MASK           0x3fu
#define TSB12LV22_NODE_ID_NODE_NUMBER_INPLACE        (TSB12LV22_NODE_ID_NODE_NUMBER_MASK << TSB12LV22_NODE_ID_NODE_NUMBER_SHIFT)

/*
 * PHY access. A PHY read and a PHY write are mutually exclusive. Command bits read as zero at reset. Data and status fields are largely unspecified at reset. A PHY register transfer received from the PHY sets rdDone and the PHY-register-received event.
 */
/* phy_control: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_PHY_CONTROL_OFFSET                 0xecu /* established */
#define TSB12LV22_PHY_CONTROL_RD_DONE_SHIFT          31 /* established */
#define TSB12LV22_PHY_CONTROL_RD_DONE_MASK           0x1u
#define TSB12LV22_PHY_CONTROL_RD_DONE_INPLACE        (TSB12LV22_PHY_CONTROL_RD_DONE_MASK << TSB12LV22_PHY_CONTROL_RD_DONE_SHIFT)
#define TSB12LV22_PHY_CONTROL_RD_ADDR_SHIFT          24 /* established */
#define TSB12LV22_PHY_CONTROL_RD_ADDR_MASK           0xfu
#define TSB12LV22_PHY_CONTROL_RD_ADDR_INPLACE        (TSB12LV22_PHY_CONTROL_RD_ADDR_MASK << TSB12LV22_PHY_CONTROL_RD_ADDR_SHIFT)
#define TSB12LV22_PHY_CONTROL_RD_DATA_SHIFT          16 /* established */
#define TSB12LV22_PHY_CONTROL_RD_DATA_MASK           0xffu
#define TSB12LV22_PHY_CONTROL_RD_DATA_INPLACE        (TSB12LV22_PHY_CONTROL_RD_DATA_MASK << TSB12LV22_PHY_CONTROL_RD_DATA_SHIFT)
#define TSB12LV22_PHY_CONTROL_RD_REG_SHIFT           15 /* established */
#define TSB12LV22_PHY_CONTROL_RD_REG_MASK            0x1u
#define TSB12LV22_PHY_CONTROL_RD_REG_INPLACE         (TSB12LV22_PHY_CONTROL_RD_REG_MASK << TSB12LV22_PHY_CONTROL_RD_REG_SHIFT)
#define TSB12LV22_PHY_CONTROL_WR_REG_SHIFT           14 /* established */
#define TSB12LV22_PHY_CONTROL_WR_REG_MASK            0x1u
#define TSB12LV22_PHY_CONTROL_WR_REG_INPLACE         (TSB12LV22_PHY_CONTROL_WR_REG_MASK << TSB12LV22_PHY_CONTROL_WR_REG_SHIFT)
#define TSB12LV22_PHY_CONTROL_REG_ADDR_SHIFT         8 /* established */
#define TSB12LV22_PHY_CONTROL_REG_ADDR_MASK          0xfu
#define TSB12LV22_PHY_CONTROL_REG_ADDR_INPLACE       (TSB12LV22_PHY_CONTROL_REG_ADDR_MASK << TSB12LV22_PHY_CONTROL_REG_ADDR_SHIFT)
#define TSB12LV22_PHY_CONTROL_WR_DATA_SHIFT          0 /* established */
#define TSB12LV22_PHY_CONTROL_WR_DATA_MASK           0xffu
#define TSB12LV22_PHY_CONTROL_WR_DATA_INPLACE        (TSB12LV22_PHY_CONTROL_WR_DATA_MASK << TSB12LV22_PHY_CONTROL_WR_DATA_SHIFT)

/*
 * Cycle timer. Unspecified at reset. The counter fields count seconds, cycles and offset ticks at 24.576 MHz.
 */
/* cycle_timer: rw32, reset unknown; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_CYCLE_TIMER_OFFSET                 0xf0u /* established */
#define TSB12LV22_CYCLE_TIMER_SECONDS_SHIFT          25 /* established */
#define TSB12LV22_CYCLE_TIMER_SECONDS_MASK           0x7fu
#define TSB12LV22_CYCLE_TIMER_SECONDS_INPLACE        (TSB12LV22_CYCLE_TIMER_SECONDS_MASK << TSB12LV22_CYCLE_TIMER_SECONDS_SHIFT)
#define TSB12LV22_CYCLE_TIMER_COUNT_SHIFT            12 /* established */
#define TSB12LV22_CYCLE_TIMER_COUNT_MASK             0x1fffu
#define TSB12LV22_CYCLE_TIMER_COUNT_INPLACE          (TSB12LV22_CYCLE_TIMER_COUNT_MASK << TSB12LV22_CYCLE_TIMER_COUNT_SHIFT)
#define TSB12LV22_CYCLE_TIMER_OFFSET_SHIFT           0 /* established */
#define TSB12LV22_CYCLE_TIMER_OFFSET_MASK            0xfffu
#define TSB12LV22_CYCLE_TIMER_OFFSET_INPLACE         (TSB12LV22_CYCLE_TIMER_OFFSET_MASK << TSB12LV22_CYCLE_TIMER_OFFSET_SHIFT)

/*
 * Asynchronous request source filter, upper node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bit 31 enables requests from nonlocal buses.
 */
/* async_filter_hi: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_ASYNC_FILTER_HI_OFFSET             0x100u /* established */
#define TSB12LV22_ASYNC_FILTER_HI_NONLOCAL_ENABLE_SHIFT 31 /* established */
#define TSB12LV22_ASYNC_FILTER_HI_NONLOCAL_ENABLE_MASK 0x1u
#define TSB12LV22_ASYNC_FILTER_HI_NONLOCAL_ENABLE_INPLACE (TSB12LV22_ASYNC_FILTER_HI_NONLOCAL_ENABLE_MASK << TSB12LV22_ASYNC_FILTER_HI_NONLOCAL_ENABLE_SHIFT)

/*
 * Asynchronous request source filter, lower node mask. The set and clear addresses form a pair, the clear address four bytes above the set address.
 */
/* async_filter_lo: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_ASYNC_FILTER_LO_OFFSET             0x108u /* established */

/*
 * Physical request source filter, upper node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. The filter applies after the asynchronous filter, and a rejected physical request falls through to asynchronous receive.
 */
/* phys_filter_hi: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_PHYS_FILTER_HI_OFFSET              0x110u /* established */

/*
 * Physical request source filter, lower node mask. The set and clear addresses form a pair, the clear address four bytes above the set address.
 */
/* phys_filter_lo: rw32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_PHYS_FILTER_LO_OFFSET              0x118u /* established */

/*
 * Physical upper bound. It is optional and this part does not implement it, so it reads as zero.
 */
/* phys_upper_bound: r32, reset 0x0; TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item) */
#define TSB12LV22_PHYS_UPPER_BOUND_OFFSET            0x120u /* established */

#define TSB12LV22_BUS_ID_TEXT                        0x31333934u /* established */
#define TSB12LV22_CYCLE_TIMER_CLOCK_HZ               0x1770000u /* established */
#define TSB12LV22_ISO_CHANNELS                       0x40u /* established */
#define TSB12LV22_MAX_REC_DEFAULT                    0xau /* established */
#define TSB12LV22_PCI_DEVICE_ID                      0x8009u /* established */
#define TSB12LV22_PCI_REVISION                       0x1u /* established */
#define TSB12LV22_PCI_VENDOR_ID                      0x104cu /* established */
#define TSB12LV22_PHY_CLOCK_HZ                       0x2ee0000u /* established */
#define TSB12LV22_SELF_ID_BUFFER_ALIGN               0x800u /* established */

#endif /* TSB12LV22_GEN_H */
