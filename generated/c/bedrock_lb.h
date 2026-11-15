/* generated from devices/bedrock_lb/registers.toml by defs-gen - do not edit, change the source */
/* Bedrock local block (LB) registers: field layouts, reset statements and the vector engine */
#ifndef BEDROCK_LB_GEN_H
#define BEDROCK_LB_GEN_H

#include <stdint.h>


/* enum region_size */
#define BEDROCK_LB_REGION_SIZE_FINE                  0 /* established */
#define BEDROCK_LB_REGION_SIZE_COARSE                1 /* established */
#define BEDROCK_LB_REGION_SIZE_NMODE                 2 /* established */
#define BEDROCK_LB_REGION_SIZE_INVALID               3 /* established */

/* enum vector_op */
#define BEDROCK_LB_VECTOR_OP_READ                    0 /* established */
#define BEDROCK_LB_VECTOR_OP_WRITE                   1 /* established */
#define BEDROCK_LB_VECTOR_OP_UNDEFINED               2 /* established */
#define BEDROCK_LB_VECTOR_OP_EXCHANGE                3 /* established */

/* enum vector_reply_type */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_READ            0 /* established */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_WRITE           1 /* established */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_UNDEFINED       2 /* established */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_EXCHANGE        3 /* established */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_ADDRESS_ERROR   4 /* established */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_COMMAND_ERROR   5 /* established */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_PROTECTION_ERROR 6 /* established */
#define BEDROCK_LB_VECTOR_REPLY_TYPE_UNKNOWN_ERROR   7 /* established */

/*
 * Revision and identity. The header says this register carries the chip identity and sets the node's ID and the size of each region. The manufacturer, part and revision fields are assigned by IBM under the IEEE 1149.1 scheme, and the header does not say whether they are writable. The I/O interface's widget identification register echoes the manufacturer and revision fields.
 */
/* rev_id: rw64, reset 0x23012049; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_REV_ID                            0x600000 /* established */
#define BEDROCK_LB_REV_ID_REGION_SIZE_SHIFT          46 /* established */
#define BEDROCK_LB_REV_ID_REGION_SIZE_MASK           0x3ull
#define BEDROCK_LB_REV_ID_REGION_SIZE_INPLACE        (BEDROCK_LB_REV_ID_REGION_SIZE_MASK << BEDROCK_LB_REV_ID_REGION_SIZE_SHIFT)
#define BEDROCK_LB_REV_ID_NODE_ID_SHIFT              32 /* established */
#define BEDROCK_LB_REV_ID_NODE_ID_MASK               0xffull
#define BEDROCK_LB_REV_ID_NODE_ID_INPLACE            (BEDROCK_LB_REV_ID_NODE_ID_MASK << BEDROCK_LB_REV_ID_NODE_ID_SHIFT)
#define BEDROCK_LB_REV_ID_REVISION_SHIFT             28 /* established */
#define BEDROCK_LB_REV_ID_REVISION_MASK              0xfull
#define BEDROCK_LB_REV_ID_REVISION_INPLACE           (BEDROCK_LB_REV_ID_REVISION_MASK << BEDROCK_LB_REV_ID_REVISION_SHIFT)
#define BEDROCK_LB_REV_ID_PART_NUMBER_SHIFT          12 /* established */
#define BEDROCK_LB_REV_ID_PART_NUMBER_MASK           0xffffull
#define BEDROCK_LB_REV_ID_PART_NUMBER_INPLACE        (BEDROCK_LB_REV_ID_PART_NUMBER_MASK << BEDROCK_LB_REV_ID_PART_NUMBER_SHIFT)
#define BEDROCK_LB_REV_ID_MANUFACTURER_SHIFT         1 /* established */
#define BEDROCK_LB_REV_ID_MANUFACTURER_MASK          0x7ffull
#define BEDROCK_LB_REV_ID_MANUFACTURER_INPLACE       (BEDROCK_LB_REV_ID_MANUFACTURER_MASK << BEDROCK_LB_REV_ID_MANUFACTURER_SHIFT)

/*
 * Processor PIO access permission, one bit per region. A region whose bit is clear gets no write access to the local block, network interface, crossbar or memory-directory registers, and no read that would change state. A write or a state-changing read from such a region is not performed and gets an error reply. The header calls it the access-rights vector for those four units. The table record behind this reset (decoded from the firmware image) is one field spanning bits 63:0 whose reset is 0x0fffffffffffffff; the same record appears for this register, the local block's processor permission and its region present register, and the table does write 64 set bits for single 64-bit fields elsewhere (three registers of the processor interface block and the first register of the memory-directory block), so the four clear bits are not how the table writes all-ones. Whether the silicon reads them clear is not settled by any public source.
 */
/* cpu_permission: rw64, reset 0xfffffffffffffff; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_CPU_PERMISSION                    0x604000 /* established */
#define BEDROCK_LB_CPU_PERMISSION_REGION_ENABLE_SHIFT 0 /* established */
#define BEDROCK_LB_CPU_PERMISSION_REGION_ENABLE_MASK 0xffffffffffffffffull
#define BEDROCK_LB_CPU_PERMISSION_REGION_ENABLE_INPLACE (BEDROCK_LB_CPU_PERMISSION_REGION_ENABLE_MASK << BEDROCK_LB_CPU_PERMISSION_REGION_ENABLE_SHIFT)

/*
 * Writing the 64-bit ASCII key the SN1 header names sets the writer's own region bit in cpu_permission. The key is not reproduced here. Reset unknown.
 */
/* cpu_permission_override: w64, reset unknown; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_CPU_PERMISSION_OVERRIDE           0x604008 /* established */

/*
 * The same per-region access vector as cpu_permission, applied to accesses that come from the I/O interface side rather than from a processor.
 */
/* io_permission: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_IO_PERMISSION                     0x604010 /* established */
#define BEDROCK_LB_IO_PERMISSION_REGION_ENABLE_SHIFT 0 /* established */
#define BEDROCK_LB_IO_PERMISSION_REGION_ENABLE_MASK  0xffffffffffffffffull
#define BEDROCK_LB_IO_PERMISSION_REGION_ENABLE_INPLACE (BEDROCK_LB_IO_PERMISSION_REGION_ENABLE_MASK << BEDROCK_LB_IO_PERMISSION_REGION_ENABLE_SHIFT)

/*
 * A write to bit 0 resets the Bedrock with a soft reset. The header does not say which state survives it. Reset unknown.
 */
/* soft_reset: w64, reset unknown; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SOFT_RESET                        0x604018 /* established */
#define BEDROCK_LB_SOFT_RESET_SOFT_RESET_SHIFT       0 /* established */
#define BEDROCK_LB_SOFT_RESET_SOFT_RESET_MASK        0x1ull
#define BEDROCK_LB_SOFT_RESET_SOFT_RESET_INPLACE     (BEDROCK_LB_SOFT_RESET_SOFT_RESET_MASK << BEDROCK_LB_SOFT_RESET_SOFT_RESET_SHIFT)

/*
 * Regions that can receive an invalidate. The block samples it when an invalidate arrives. If an invalidate names a processor interface in a region whose bit is clear, the block acknowledges on that interface's behalf. The region size in the revision register sets how many nodes share one bit. The table record behind this reset (decoded from the firmware image) is one field spanning bits 63:0 whose reset is 0x0fffffffffffffff; the same record appears for this register, the local block's processor permission and its region present register, and the table does write 64 set bits for single 64-bit fields elsewhere (three registers of the processor interface block and the first register of the memory-directory block), so the four clear bits are not how the table writes all-ones. Whether the silicon reads them clear is not settled by any public source.
 */
/* region_present: rw64, reset 0xfffffffffffffff; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_REGION_PRESENT                    0x604020 /* established */
#define BEDROCK_LB_REGION_PRESENT_PRESENT_SHIFT      0 /* established */
#define BEDROCK_LB_REGION_PRESENT_PRESENT_MASK       0xffffffffffffffffull
#define BEDROCK_LB_REGION_PRESENT_PRESENT_INPLACE    (BEDROCK_LB_REGION_PRESENT_PRESENT_MASK << BEDROCK_LB_REGION_PRESENT_PRESENT_SHIFT)

/*
 * Four 16-bit entries, one per slot. Each entry holds a node number in its low eight bits and a valid bit at bit 15. A node listed with its valid bit set cannot receive an invalidate.
 */
/* nodes_absent: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_NODES_ABSENT                      0x604028 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY3_VALID_SHIFT   63 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY3_VALID_MASK    0x1ull
#define BEDROCK_LB_NODES_ABSENT_ENTRY3_VALID_INPLACE (BEDROCK_LB_NODES_ABSENT_ENTRY3_VALID_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY3_VALID_SHIFT)
#define BEDROCK_LB_NODES_ABSENT_ENTRY3_NODE_SHIFT    48 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY3_NODE_MASK     0xffull
#define BEDROCK_LB_NODES_ABSENT_ENTRY3_NODE_INPLACE  (BEDROCK_LB_NODES_ABSENT_ENTRY3_NODE_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY3_NODE_SHIFT)
#define BEDROCK_LB_NODES_ABSENT_ENTRY2_VALID_SHIFT   47 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY2_VALID_MASK    0x1ull
#define BEDROCK_LB_NODES_ABSENT_ENTRY2_VALID_INPLACE (BEDROCK_LB_NODES_ABSENT_ENTRY2_VALID_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY2_VALID_SHIFT)
#define BEDROCK_LB_NODES_ABSENT_ENTRY2_NODE_SHIFT    32 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY2_NODE_MASK     0xffull
#define BEDROCK_LB_NODES_ABSENT_ENTRY2_NODE_INPLACE  (BEDROCK_LB_NODES_ABSENT_ENTRY2_NODE_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY2_NODE_SHIFT)
#define BEDROCK_LB_NODES_ABSENT_ENTRY1_VALID_SHIFT   31 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY1_VALID_MASK    0x1ull
#define BEDROCK_LB_NODES_ABSENT_ENTRY1_VALID_INPLACE (BEDROCK_LB_NODES_ABSENT_ENTRY1_VALID_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY1_VALID_SHIFT)
#define BEDROCK_LB_NODES_ABSENT_ENTRY1_NODE_SHIFT    16 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY1_NODE_MASK     0xffull
#define BEDROCK_LB_NODES_ABSENT_ENTRY1_NODE_INPLACE  (BEDROCK_LB_NODES_ABSENT_ENTRY1_NODE_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY1_NODE_SHIFT)
#define BEDROCK_LB_NODES_ABSENT_ENTRY0_VALID_SHIFT   15 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY0_VALID_MASK    0x1ull
#define BEDROCK_LB_NODES_ABSENT_ENTRY0_VALID_INPLACE (BEDROCK_LB_NODES_ABSENT_ENTRY0_VALID_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY0_VALID_SHIFT)
#define BEDROCK_LB_NODES_ABSENT_ENTRY0_NODE_SHIFT    0 /* established */
#define BEDROCK_LB_NODES_ABSENT_ENTRY0_NODE_MASK     0xffull
#define BEDROCK_LB_NODES_ABSENT_ENTRY0_NODE_INPLACE  (BEDROCK_LB_NODES_ABSENT_ENTRY0_NODE_MASK << BEDROCK_LB_NODES_ABSENT_ENTRY0_NODE_SHIFT)

/*
 * Control for a one-wire serial bus to the node board's add-only serial PROM. The header names the part as a Dallas 1990A and says the PROM holds the node board's serial number and configuration. Bytes travel least-significant bit first. The header gives no unit for the timing fields, no completion latency and no sequence of commands, so the timing and the transaction are unknown. The public Linux SN1 tree does not use this register outside its header.
 */
/* microlan_ctl: rw64, reset 0x31e300002; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_MICROLAN_CTL                      0x604030 /* established */
#define BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI1_SHIFT    27 /* established */
#define BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI1_MASK     0x7full
#define BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI1_INPLACE  (BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI1_MASK << BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI1_SHIFT)
#define BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI0_SHIFT    20 /* established */
#define BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI0_MASK     0x7full
#define BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI0_INPLACE  (BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI0_MASK << BEDROCK_LB_MICROLAN_CTL_CLKDIV_PHI0_SHIFT)
#define BEDROCK_LB_MICROLAN_CTL_LOW_PULSE_SHIFT      10 /* established */
#define BEDROCK_LB_MICROLAN_CTL_LOW_PULSE_MASK       0x3ffull
#define BEDROCK_LB_MICROLAN_CTL_LOW_PULSE_INPLACE    (BEDROCK_LB_MICROLAN_CTL_LOW_PULSE_MASK << BEDROCK_LB_MICROLAN_CTL_LOW_PULSE_SHIFT)
#define BEDROCK_LB_MICROLAN_CTL_SAMPLE_OFFSET_SHIFT  2 /* established */
#define BEDROCK_LB_MICROLAN_CTL_SAMPLE_OFFSET_MASK   0xffull
#define BEDROCK_LB_MICROLAN_CTL_SAMPLE_OFFSET_INPLACE (BEDROCK_LB_MICROLAN_CTL_SAMPLE_OFFSET_MASK << BEDROCK_LB_MICROLAN_CTL_SAMPLE_OFFSET_SHIFT)
#define BEDROCK_LB_MICROLAN_CTL_DONE_SHIFT           1 /* established */
#define BEDROCK_LB_MICROLAN_CTL_DONE_MASK            0x1ull
#define BEDROCK_LB_MICROLAN_CTL_DONE_INPLACE         (BEDROCK_LB_MICROLAN_CTL_DONE_MASK << BEDROCK_LB_MICROLAN_CTL_DONE_SHIFT)
#define BEDROCK_LB_MICROLAN_CTL_READ_DATA_SHIFT      0 /* established */
#define BEDROCK_LB_MICROLAN_CTL_READ_DATA_MASK       0x1ull
#define BEDROCK_LB_MICROLAN_CTL_READ_DATA_INPLACE    (BEDROCK_LB_MICROLAN_CTL_READ_DATA_MASK << BEDROCK_LB_MICROLAN_CTL_READ_DATA_SHIFT)

/*
 * Local-block error bits. Reads do not change them. A write sets the bits it names. Any set bit raises the block's error request to both processor interfaces (bit 55 of their pending-1 register). The header says the contents survive a reset.
 */
/* error_bits: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_ERROR_BITS                        0x604040 /* established */
#define BEDROCK_LB_ERROR_BITS_GCLK_DROP_SHIFT        10 /* established */
#define BEDROCK_LB_ERROR_BITS_GCLK_DROP_MASK         0x1ull
#define BEDROCK_LB_ERROR_BITS_GCLK_DROP_INPLACE      (BEDROCK_LB_ERROR_BITS_GCLK_DROP_MASK << BEDROCK_LB_ERROR_BITS_GCLK_DROP_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_INVAL_SHIFT     9 /* established */
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_INVAL_MASK      0x1ull
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_INVAL_INPLACE   (BEDROCK_LB_ERROR_BITS_RQ_BAD_INVAL_MASK << BEDROCK_LB_ERROR_BITS_RQ_BAD_INVAL_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_ADDR_SHIFT      8 /* established */
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_ADDR_MASK       0x1ull
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_ADDR_INPLACE    (BEDROCK_LB_ERROR_BITS_RQ_BAD_ADDR_MASK << BEDROCK_LB_ERROR_BITS_RQ_BAD_ADDR_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RP_BAD_DATA_SHIFT      7 /* established */
#define BEDROCK_LB_ERROR_BITS_RP_BAD_DATA_MASK       0x1ull
#define BEDROCK_LB_ERROR_BITS_RP_BAD_DATA_INPLACE    (BEDROCK_LB_ERROR_BITS_RP_BAD_DATA_MASK << BEDROCK_LB_ERROR_BITS_RP_BAD_DATA_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_DATA_SHIFT      6 /* established */
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_DATA_MASK       0x1ull
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_DATA_INPLACE    (BEDROCK_LB_ERROR_BITS_RQ_BAD_DATA_MASK << BEDROCK_LB_ERROR_BITS_RQ_BAD_DATA_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RP_LONG_SHIFT          5 /* established */
#define BEDROCK_LB_ERROR_BITS_RP_LONG_MASK           0x1ull
#define BEDROCK_LB_ERROR_BITS_RP_LONG_INPLACE        (BEDROCK_LB_ERROR_BITS_RP_LONG_MASK << BEDROCK_LB_ERROR_BITS_RP_LONG_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RQ_LONG_SHIFT          4 /* established */
#define BEDROCK_LB_ERROR_BITS_RQ_LONG_MASK           0x1ull
#define BEDROCK_LB_ERROR_BITS_RQ_LONG_INPLACE        (BEDROCK_LB_ERROR_BITS_RQ_LONG_MASK << BEDROCK_LB_ERROR_BITS_RQ_LONG_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RP_SHORT_SHIFT         3 /* established */
#define BEDROCK_LB_ERROR_BITS_RP_SHORT_MASK          0x1ull
#define BEDROCK_LB_ERROR_BITS_RP_SHORT_INPLACE       (BEDROCK_LB_ERROR_BITS_RP_SHORT_MASK << BEDROCK_LB_ERROR_BITS_RP_SHORT_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RQ_SHORT_SHIFT         2 /* established */
#define BEDROCK_LB_ERROR_BITS_RQ_SHORT_MASK          0x1ull
#define BEDROCK_LB_ERROR_BITS_RQ_SHORT_INPLACE       (BEDROCK_LB_ERROR_BITS_RQ_SHORT_MASK << BEDROCK_LB_ERROR_BITS_RQ_SHORT_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RP_BAD_CMD_SHIFT       1 /* established */
#define BEDROCK_LB_ERROR_BITS_RP_BAD_CMD_MASK        0x1ull
#define BEDROCK_LB_ERROR_BITS_RP_BAD_CMD_INPLACE     (BEDROCK_LB_ERROR_BITS_RP_BAD_CMD_MASK << BEDROCK_LB_ERROR_BITS_RP_BAD_CMD_SHIFT)
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_CMD_SHIFT       0 /* established */
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_CMD_MASK        0x1ull
#define BEDROCK_LB_ERROR_BITS_RQ_BAD_CMD_INPLACE     (BEDROCK_LB_ERROR_BITS_RQ_BAD_CMD_MASK << BEDROCK_LB_ERROR_BITS_RQ_BAD_CMD_SHIFT)

/*
 * Write one to clear the matching error bits. A zero bit in the written value leaves its error bit alone, so any subset clears atomically. Reset unknown.
 */
/* error_mask_clr: w64, reset unknown; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_ERROR_MASK_CLR                    0x604048 /* established */
#define BEDROCK_LB_ERROR_MASK_CLR_CLEAR_SHIFT        0 /* established */
#define BEDROCK_LB_ERROR_MASK_CLR_CLEAR_MASK         0x7ffull
#define BEDROCK_LB_ERROR_MASK_CLR_CLEAR_INPLACE      (BEDROCK_LB_ERROR_MASK_CLR_CLEAR_MASK << BEDROCK_LB_ERROR_MASK_CLR_CLEAR_SHIFT)

/*
 * Header of the first packet that caused an error. It is captured while valid is clear, and valid is then set. A later error while valid is set sets overrun and leaves the rest alone. The err_type value uses the same bit numbering as error_bits, so err_type 5 means rp_long. Not relevant for a global clock drop.
 */
/* error_hdr1: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_ERROR_HDR1                        0x604050 /* established */
#define BEDROCK_LB_ERROR_HDR1_VALID_SHIFT            44 /* established */
#define BEDROCK_LB_ERROR_HDR1_VALID_MASK             0x1ull
#define BEDROCK_LB_ERROR_HDR1_VALID_INPLACE          (BEDROCK_LB_ERROR_HDR1_VALID_MASK << BEDROCK_LB_ERROR_HDR1_VALID_SHIFT)
#define BEDROCK_LB_ERROR_HDR1_OVERRUN_SHIFT          40 /* established */
#define BEDROCK_LB_ERROR_HDR1_OVERRUN_MASK           0x1ull
#define BEDROCK_LB_ERROR_HDR1_OVERRUN_INPLACE        (BEDROCK_LB_ERROR_HDR1_OVERRUN_MASK << BEDROCK_LB_ERROR_HDR1_OVERRUN_SHIFT)
#define BEDROCK_LB_ERROR_HDR1_ERR_TYPE_SHIFT         32 /* established */
#define BEDROCK_LB_ERROR_HDR1_ERR_TYPE_MASK          0xfull
#define BEDROCK_LB_ERROR_HDR1_ERR_TYPE_INPLACE       (BEDROCK_LB_ERROR_HDR1_ERR_TYPE_MASK << BEDROCK_LB_ERROR_HDR1_ERR_TYPE_SHIFT)
#define BEDROCK_LB_ERROR_HDR1_SOURCE_SHIFT           20 /* established */
#define BEDROCK_LB_ERROR_HDR1_SOURCE_MASK            0x7ffull
#define BEDROCK_LB_ERROR_HDR1_SOURCE_INPLACE         (BEDROCK_LB_ERROR_HDR1_SOURCE_MASK << BEDROCK_LB_ERROR_HDR1_SOURCE_SHIFT)
#define BEDROCK_LB_ERROR_HDR1_SUPPL_SHIFT            8 /* established */
#define BEDROCK_LB_ERROR_HDR1_SUPPL_MASK             0x7ffull
#define BEDROCK_LB_ERROR_HDR1_SUPPL_INPLACE          (BEDROCK_LB_ERROR_HDR1_SUPPL_MASK << BEDROCK_LB_ERROR_HDR1_SUPPL_SHIFT)
#define BEDROCK_LB_ERROR_HDR1_COMMAND_SHIFT          0 /* established */
#define BEDROCK_LB_ERROR_HDR1_COMMAND_MASK           0x7full
#define BEDROCK_LB_ERROR_HDR1_COMMAND_INPLACE        (BEDROCK_LB_ERROR_HDR1_COMMAND_MASK << BEDROCK_LB_ERROR_HDR1_COMMAND_SHIFT)

/*
 * Address field from the header of the first packet that caused an error. Not relevant for a global clock drop.
 */
/* error_hdr2: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_ERROR_HDR2                        0x604058 /* established */
#define BEDROCK_LB_ERROR_HDR2_ADDRESS_SHIFT          0 /* established */
#define BEDROCK_LB_ERROR_HDR2_ADDRESS_MASK           0x3fffffffffull
#define BEDROCK_LB_ERROR_HDR2_ADDRESS_INPLACE        (BEDROCK_LB_ERROR_HDR2_ADDRESS_MASK << BEDROCK_LB_ERROR_HDR2_ADDRESS_SHIFT)

/*
 * Data flit of the first erroring packet, for the error kinds that carry data.
 */
/* error_data: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_ERROR_DATA                        0x604060 /* established */
#define BEDROCK_LB_ERROR_DATA_FLIT_SHIFT             0 /* established */
#define BEDROCK_LB_ERROR_DATA_FLIT_MASK              0xffffffffffffffffull
#define BEDROCK_LB_ERROR_DATA_FLIT_INPLACE           (BEDROCK_LB_ERROR_DATA_FLIT_MASK << BEDROCK_LB_ERROR_DATA_FLIT_SHIFT)

/*
 * Chooses which internal signals appear on the debug pins. The header gives no list of the choices.
 */
/* debug_select: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_DEBUG_SELECT                      0x604100 /* established */
#define BEDROCK_LB_DEBUG_SELECT_SELECT_SHIFT         0 /* established */
#define BEDROCK_LB_DEBUG_SELECT_SELECT_MASK          0x3full
#define BEDROCK_LB_DEBUG_SELECT_SELECT_INPLACE       (BEDROCK_LB_DEBUG_SELECT_SELECT_MASK << BEDROCK_LB_DEBUG_SELECT_SELECT_SHIFT)

/*
 * Value on the chip's debug pins.
 */
/* debug_pins: r64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_DEBUG_PINS                        0x604108 /* established */
#define BEDROCK_LB_DEBUG_PINS_PINS_SHIFT             0 /* established */
#define BEDROCK_LB_DEBUG_PINS_PINS_MASK              0xffffffffull
#define BEDROCK_LB_DEBUG_PINS_PINS_INPLACE           (BEDROCK_LB_DEBUG_PINS_PINS_MASK << BEDROCK_LB_DEBUG_PINS_PINS_SHIFT)

/*
 * Local source of the real-time clock. The local block gives the clock to both processor interfaces. With use_internal set it generates the clock from the Bedrock's system clock, with its period set by max_count. With it clear it filters an incoming global clock instead (see rt_filter_ctrl).
 */
/* rt_local_ctrl: rw64, reset 0x100000640; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_RT_LOCAL_CTRL                     0x604200 /* established */
#define BEDROCK_LB_RT_LOCAL_CTRL_USE_INTERNAL_SHIFT  32 /* established */
#define BEDROCK_LB_RT_LOCAL_CTRL_USE_INTERNAL_MASK   0x1ull
#define BEDROCK_LB_RT_LOCAL_CTRL_USE_INTERNAL_INPLACE (BEDROCK_LB_RT_LOCAL_CTRL_USE_INTERNAL_MASK << BEDROCK_LB_RT_LOCAL_CTRL_USE_INTERNAL_SHIFT)
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_SHIFT          28 /* established */
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_MASK           0x1ull
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_INPLACE        (BEDROCK_LB_RT_LOCAL_CTRL_GCLK_MASK << BEDROCK_LB_RT_LOCAL_CTRL_GCLK_SHIFT)
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_COUNTER_SHIFT  16 /* established */
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_COUNTER_MASK   0x3ffull
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_COUNTER_INPLACE (BEDROCK_LB_RT_LOCAL_CTRL_GCLK_COUNTER_MASK << BEDROCK_LB_RT_LOCAL_CTRL_GCLK_COUNTER_SHIFT)
#define BEDROCK_LB_RT_LOCAL_CTRL_MAX_COUNT_SHIFT     4 /* established */
#define BEDROCK_LB_RT_LOCAL_CTRL_MAX_COUNT_MASK      0x3ffull
#define BEDROCK_LB_RT_LOCAL_CTRL_MAX_COUNT_INPLACE   (BEDROCK_LB_RT_LOCAL_CTRL_MAX_COUNT_MASK << BEDROCK_LB_RT_LOCAL_CTRL_MAX_COUNT_SHIFT)
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_ENABLE_SHIFT   0 /* established */
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_ENABLE_MASK    0x1ull
#define BEDROCK_LB_RT_LOCAL_CTRL_GCLK_ENABLE_INPLACE (BEDROCK_LB_RT_LOCAL_CTRL_GCLK_ENABLE_MASK << BEDROCK_LB_RT_LOCAL_CTRL_GCLK_ENABLE_SHIFT)

/*
 * Filtering of an incoming global clock, used when rt_local_ctrl use_internal is clear. Simple filtering drops single-cycle glitches. Complex filtering (mask_enable set) expects positive edges at regular intervals, tracks missing and unexpected edges, and generates an edge itself when one is missing. Under either option the clock it hands the processor interfaces stays high for (2 * max_count + 1 - offset) / 2 cycles of the block's system clock after each positive edge. Clock loss is error bit gclk_drop.
 */
/* rt_filter_ctrl: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_RT_FILTER_CTRL                    0x604208 /* established */
#define BEDROCK_LB_RT_FILTER_CTRL_ERROR_COUNTER_SHIFT 48 /* established */
#define BEDROCK_LB_RT_FILTER_CTRL_ERROR_COUNTER_MASK 0x3ffull
#define BEDROCK_LB_RT_FILTER_CTRL_ERROR_COUNTER_INPLACE (BEDROCK_LB_RT_FILTER_CTRL_ERROR_COUNTER_MASK << BEDROCK_LB_RT_FILTER_CTRL_ERROR_COUNTER_SHIFT)
#define BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_THRESHOLD_SHIFT 36 /* established */
#define BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_THRESHOLD_MASK 0x3ffull
#define BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_THRESHOLD_INPLACE (BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_THRESHOLD_MASK << BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_THRESHOLD_SHIFT)
#define BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_COUNTER_SHIFT 24 /* established */
#define BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_COUNTER_MASK 0x3ffull
#define BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_COUNTER_INPLACE (BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_COUNTER_MASK << BEDROCK_LB_RT_FILTER_CTRL_DROPOUT_COUNTER_SHIFT)
#define BEDROCK_LB_RT_FILTER_CTRL_MASK_ENABLE_SHIFT  20 /* established */
#define BEDROCK_LB_RT_FILTER_CTRL_MASK_ENABLE_MASK   0x1ull
#define BEDROCK_LB_RT_FILTER_CTRL_MASK_ENABLE_INPLACE (BEDROCK_LB_RT_FILTER_CTRL_MASK_ENABLE_MASK << BEDROCK_LB_RT_FILTER_CTRL_MASK_ENABLE_SHIFT)
#define BEDROCK_LB_RT_FILTER_CTRL_MASK_COUNTER_SHIFT 8 /* established */
#define BEDROCK_LB_RT_FILTER_CTRL_MASK_COUNTER_MASK  0xfffull
#define BEDROCK_LB_RT_FILTER_CTRL_MASK_COUNTER_INPLACE (BEDROCK_LB_RT_FILTER_CTRL_MASK_COUNTER_MASK << BEDROCK_LB_RT_FILTER_CTRL_MASK_COUNTER_SHIFT)
#define BEDROCK_LB_RT_FILTER_CTRL_OFFSET_SHIFT       0 /* established */
#define BEDROCK_LB_RT_FILTER_CTRL_OFFSET_MASK        0x1full
#define BEDROCK_LB_RT_FILTER_CTRL_OFFSET_INPLACE     (BEDROCK_LB_RT_FILTER_CTRL_OFFSET_MASK << BEDROCK_LB_RT_FILTER_CTRL_OFFSET_SHIFT)

/*
 * Plain storage. The header says it is reset to zero.
 */
/* scratch0: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH0                          0x608000 /* established */
#define BEDROCK_LB_SCRATCH0_BITS_SHIFT               0 /* established */
#define BEDROCK_LB_SCRATCH0_BITS_MASK                0xffffffffffffffffull
#define BEDROCK_LB_SCRATCH0_BITS_INPLACE             (BEDROCK_LB_SCRATCH0_BITS_MASK << BEDROCK_LB_SCRATCH0_BITS_SHIFT)

/*
 * Plain storage. The header says it is not reset, and does not name the reset it means.
 */
/* scratch1: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH1                          0x608008 /* established */
#define BEDROCK_LB_SCRATCH1_BITS_SHIFT               0 /* established */
#define BEDROCK_LB_SCRATCH1_BITS_MASK                0xffffffffffffffffull
#define BEDROCK_LB_SCRATCH1_BITS_INPLACE             (BEDROCK_LB_SCRATCH1_BITS_MASK << BEDROCK_LB_SCRATCH1_BITS_SHIFT)

/*
 * Plain storage. The header says it is not reset, and does not name the reset it means.
 */
/* scratch2: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH2                          0x608010 /* established */
#define BEDROCK_LB_SCRATCH2_BITS_SHIFT               0 /* established */
#define BEDROCK_LB_SCRATCH2_BITS_MASK                0xffffffffffffffffull
#define BEDROCK_LB_SCRATCH2_BITS_INPLACE             (BEDROCK_LB_SCRATCH2_BITS_MASK << BEDROCK_LB_SCRATCH2_BITS_SHIFT)

/*
 * One-bit storage (bit 0 of a 64-bit word). The header gives no reset value. The public Linux ia64 L1 driver uses it as a hub-wide lock: it releases the lock by writing zero to this address.
 */
/* scratch3: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH3                          0x608018 /* established */
#define BEDROCK_LB_SCRATCH3_BIT_SHIFT                0 /* established */
#define BEDROCK_LB_SCRATCH3_BIT_MASK                 0x1ull
#define BEDROCK_LB_SCRATCH3_BIT_INPLACE              (BEDROCK_LB_SCRATCH3_BIT_MASK << BEDROCK_LB_SCRATCH3_BIT_SHIFT)

/*
 * One-bit storage (bit 0 of a 64-bit word). The header gives no reset value, and the public Linux tree shows no use of it.
 */
/* scratch4: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH4                          0x608020 /* established */
#define BEDROCK_LB_SCRATCH4_BIT_SHIFT                0 /* established */
#define BEDROCK_LB_SCRATCH4_BIT_MASK                 0x1ull
#define BEDROCK_LB_SCRATCH4_BIT_INPLACE              (BEDROCK_LB_SCRATCH4_BIT_MASK << BEDROCK_LB_SCRATCH4_BIT_SHIFT)

/*
 * Write-if-zero alias of scratch 0. A write is accepted only when the current value is zero.
 */
/* scratch0_wz: w64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH0_WZ                       0x608040 /* established */
#define BEDROCK_LB_SCRATCH0_WZ_BITS_SHIFT            0 /* established */
#define BEDROCK_LB_SCRATCH0_WZ_BITS_MASK             0xffffffffffffffffull
#define BEDROCK_LB_SCRATCH0_WZ_BITS_INPLACE          (BEDROCK_LB_SCRATCH0_WZ_BITS_MASK << BEDROCK_LB_SCRATCH0_WZ_BITS_SHIFT)

/*
 * Write-if-zero alias of scratch 1. A write is accepted only when the current value is zero.
 */
/* scratch1_wz: w64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH1_WZ                       0x608048 /* established */
#define BEDROCK_LB_SCRATCH1_WZ_BITS_SHIFT            0 /* established */
#define BEDROCK_LB_SCRATCH1_WZ_BITS_MASK             0xffffffffffffffffull
#define BEDROCK_LB_SCRATCH1_WZ_BITS_INPLACE          (BEDROCK_LB_SCRATCH1_WZ_BITS_MASK << BEDROCK_LB_SCRATCH1_WZ_BITS_SHIFT)

/*
 * Write-if-zero alias of scratch 2. A write is accepted only when the current value is zero.
 */
/* scratch2_wz: w64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH2_WZ                       0x608050 /* established */
#define BEDROCK_LB_SCRATCH2_WZ_BITS_SHIFT            0 /* established */
#define BEDROCK_LB_SCRATCH2_WZ_BITS_MASK             0xffffffffffffffffull
#define BEDROCK_LB_SCRATCH2_WZ_BITS_INPLACE          (BEDROCK_LB_SCRATCH2_WZ_BITS_MASK << BEDROCK_LB_SCRATCH2_WZ_BITS_SHIFT)

/*
 * Read-set-if-zero alias of scratch 3 (one bit, bit 0 of a 64-bit word). A read returns the old value and sets the bit when it was zero, so a single read is a test-and-set. The public Linux ia64 L1 driver takes its hub-wide lock this way and reads until it gets zero.
 */
/* scratch3_rz: r64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH3_RZ                       0x608058 /* established */
#define BEDROCK_LB_SCRATCH3_RZ_BIT_SHIFT             0 /* established */
#define BEDROCK_LB_SCRATCH3_RZ_BIT_MASK              0x1ull
#define BEDROCK_LB_SCRATCH3_RZ_BIT_INPLACE           (BEDROCK_LB_SCRATCH3_RZ_BIT_MASK << BEDROCK_LB_SCRATCH3_RZ_BIT_SHIFT)

/*
 * Read-set-if-zero alias of scratch 4 (one bit). A read returns the old value and sets the bit when it was zero.
 */
/* scratch4_rz: r64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_SCRATCH4_RZ                       0x608060 /* established */
#define BEDROCK_LB_SCRATCH4_RZ_BIT_SHIFT             0 /* established */
#define BEDROCK_LB_SCRATCH4_RZ_BIT_MASK              0x1ull
#define BEDROCK_LB_SCRATCH4_RZ_BIT_INPLACE           (BEDROCK_LB_SCRATCH4_RZ_BIT_MASK << BEDROCK_LB_SCRATCH4_RZ_BIT_SHIFT)

/*
 * Vector I/O request parameters. A write sends one request, and the block replies to the write at once without waiting for the operation. The request is built from three registers: the route, the write data and this one, which should be written last. Software waits for busy to clear before it starts.
 */
/* vector_parms: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_VECTOR_PARMS                      0x60c000 /* established */
#define BEDROCK_LB_VECTOR_PARMS_BUSY_SHIFT           63 /* established */
#define BEDROCK_LB_VECTOR_PARMS_BUSY_MASK            0x1ull
#define BEDROCK_LB_VECTOR_PARMS_BUSY_INPLACE         (BEDROCK_LB_VECTOR_PARMS_BUSY_MASK << BEDROCK_LB_VECTOR_PARMS_BUSY_SHIFT)
#define BEDROCK_LB_VECTOR_PARMS_PIO_ID_SHIFT         40 /* established */
#define BEDROCK_LB_VECTOR_PARMS_PIO_ID_MASK          0x7ffull
#define BEDROCK_LB_VECTOR_PARMS_PIO_ID_INPLACE       (BEDROCK_LB_VECTOR_PARMS_PIO_ID_MASK << BEDROCK_LB_VECTOR_PARMS_PIO_ID_SHIFT)
#define BEDROCK_LB_VECTOR_PARMS_WRITE_ID_SHIFT       32 /* established */
#define BEDROCK_LB_VECTOR_PARMS_WRITE_ID_MASK        0xffull
#define BEDROCK_LB_VECTOR_PARMS_WRITE_ID_INPLACE     (BEDROCK_LB_VECTOR_PARMS_WRITE_ID_MASK << BEDROCK_LB_VECTOR_PARMS_WRITE_ID_SHIFT)
#define BEDROCK_LB_VECTOR_PARMS_ADDRESS_SHIFT        3 /* established */
#define BEDROCK_LB_VECTOR_PARMS_ADDRESS_MASK         0x1fffffull
#define BEDROCK_LB_VECTOR_PARMS_ADDRESS_INPLACE      (BEDROCK_LB_VECTOR_PARMS_ADDRESS_MASK << BEDROCK_LB_VECTOR_PARMS_ADDRESS_SHIFT)
#define BEDROCK_LB_VECTOR_PARMS_TYPE_SHIFT           0 /* inferred */
#define BEDROCK_LB_VECTOR_PARMS_TYPE_MASK            0x3ull
#define BEDROCK_LB_VECTOR_PARMS_TYPE_INPLACE         (BEDROCK_LB_VECTOR_PARMS_TYPE_MASK << BEDROCK_LB_VECTOR_PARMS_TYPE_SHIFT)

/*
 * Outgoing vector route for the next request. The header gives no field layout.
 */
/* vector_route: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_VECTOR_ROUTE                      0x60c008 /* established */

/*
 * Write data for an outgoing vector write, and the data value for a read reply.
 */
/* vector_data: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_VECTOR_DATA                       0x60c010 /* established */

/*
 * Return status of the last vector request. Software clears it before launching a request. The block leaves the fields unchanged when a reply has an error. A reply that arrives while valid is already set sets overrun and leaves the rest alone. Otherwise the block loads the source, ids, address and type, sets valid, and updates return and read data. The header does not say what a write of a nonzero value does.
 */
/* vector_status: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_VECTOR_STATUS                     0x60c020 /* established */
#define BEDROCK_LB_VECTOR_STATUS_VALID_SHIFT         63 /* established */
#define BEDROCK_LB_VECTOR_STATUS_VALID_MASK          0x1ull
#define BEDROCK_LB_VECTOR_STATUS_VALID_INPLACE       (BEDROCK_LB_VECTOR_STATUS_VALID_MASK << BEDROCK_LB_VECTOR_STATUS_VALID_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_OVERRUN_SHIFT       62 /* established */
#define BEDROCK_LB_VECTOR_STATUS_OVERRUN_MASK        0x1ull
#define BEDROCK_LB_VECTOR_STATUS_OVERRUN_INPLACE     (BEDROCK_LB_VECTOR_STATUS_OVERRUN_MASK << BEDROCK_LB_VECTOR_STATUS_OVERRUN_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_SOURCE_SHIFT        51 /* established */
#define BEDROCK_LB_VECTOR_STATUS_SOURCE_MASK         0x7ffull
#define BEDROCK_LB_VECTOR_STATUS_SOURCE_INPLACE      (BEDROCK_LB_VECTOR_STATUS_SOURCE_MASK << BEDROCK_LB_VECTOR_STATUS_SOURCE_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_PIO_ID_SHIFT        40 /* established */
#define BEDROCK_LB_VECTOR_STATUS_PIO_ID_MASK         0x7ffull
#define BEDROCK_LB_VECTOR_STATUS_PIO_ID_INPLACE      (BEDROCK_LB_VECTOR_STATUS_PIO_ID_MASK << BEDROCK_LB_VECTOR_STATUS_PIO_ID_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_WRITE_ID_SHIFT      32 /* established */
#define BEDROCK_LB_VECTOR_STATUS_WRITE_ID_MASK       0xffull
#define BEDROCK_LB_VECTOR_STATUS_WRITE_ID_INPLACE    (BEDROCK_LB_VECTOR_STATUS_WRITE_ID_MASK << BEDROCK_LB_VECTOR_STATUS_WRITE_ID_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_ADDRESS_SHIFT       3 /* established */
#define BEDROCK_LB_VECTOR_STATUS_ADDRESS_MASK        0x1fffffull
#define BEDROCK_LB_VECTOR_STATUS_ADDRESS_INPLACE     (BEDROCK_LB_VECTOR_STATUS_ADDRESS_MASK << BEDROCK_LB_VECTOR_STATUS_ADDRESS_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_TYPE_OR_ERROR_SHIFT 0 /* established */
#define BEDROCK_LB_VECTOR_STATUS_TYPE_OR_ERROR_MASK  0x7ull
#define BEDROCK_LB_VECTOR_STATUS_TYPE_OR_ERROR_INPLACE (BEDROCK_LB_VECTOR_STATUS_TYPE_OR_ERROR_MASK << BEDROCK_LB_VECTOR_STATUS_TYPE_OR_ERROR_SHIFT)

/*
 * Return route from the last reply. The block stores it only for an error-free reply that arrives while valid is clear.
 */
/* vector_return: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_VECTOR_RETURN                     0x60c028 /* established */

/*
 * Read data from the last reply, under the same update rule as vector_return.
 */
/* vector_read_data: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_VECTOR_READ_DATA                  0x60c030 /* established */

/*
 * Clear the vector status. The header gives the same field layout as vector_status and says only that this register clears it. It does not say whether a read or a write does the clearing, so that is unknown.
 */
/* vector_status_clear: rw64, reset 0x0; Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR               0x60c038 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_VALID_SHIFT   63 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_VALID_MASK    0x1ull
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_VALID_INPLACE (BEDROCK_LB_VECTOR_STATUS_CLEAR_VALID_MASK << BEDROCK_LB_VECTOR_STATUS_CLEAR_VALID_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_OVERRUN_SHIFT 62 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_OVERRUN_MASK  0x1ull
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_OVERRUN_INPLACE (BEDROCK_LB_VECTOR_STATUS_CLEAR_OVERRUN_MASK << BEDROCK_LB_VECTOR_STATUS_CLEAR_OVERRUN_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_SOURCE_SHIFT  51 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_SOURCE_MASK   0x7ffull
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_SOURCE_INPLACE (BEDROCK_LB_VECTOR_STATUS_CLEAR_SOURCE_MASK << BEDROCK_LB_VECTOR_STATUS_CLEAR_SOURCE_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_PIO_ID_SHIFT  40 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_PIO_ID_MASK   0x7ffull
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_PIO_ID_INPLACE (BEDROCK_LB_VECTOR_STATUS_CLEAR_PIO_ID_MASK << BEDROCK_LB_VECTOR_STATUS_CLEAR_PIO_ID_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_WRITE_ID_SHIFT 32 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_WRITE_ID_MASK 0xffull
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_WRITE_ID_INPLACE (BEDROCK_LB_VECTOR_STATUS_CLEAR_WRITE_ID_MASK << BEDROCK_LB_VECTOR_STATUS_CLEAR_WRITE_ID_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_ADDRESS_SHIFT 3 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_ADDRESS_MASK  0x1fffffull
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_ADDRESS_INPLACE (BEDROCK_LB_VECTOR_STATUS_CLEAR_ADDRESS_MASK << BEDROCK_LB_VECTOR_STATUS_CLEAR_ADDRESS_SHIFT)
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_TYPE_OR_ERROR_SHIFT 0 /* established */
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_TYPE_OR_ERROR_MASK 0x7ull
#define BEDROCK_LB_VECTOR_STATUS_CLEAR_TYPE_OR_ERROR_INPLACE (BEDROCK_LB_VECTOR_STATUS_CLEAR_TYPE_OR_ERROR_MASK << BEDROCK_LB_VECTOR_STATUS_CLEAR_TYPE_OR_ERROR_SHIFT)

#define BEDROCK_LB_CHIP_PART_BEDROCK                 0x3012u /* established */
#define BEDROCK_LB_ERROR_PI_PEND1_BIT                0x37u /* established */
#define BEDROCK_LB_REVISION_1_0                      0x1u /* established */
#define BEDROCK_LB_REVISION_1_1                      0x2u /* established */
#define BEDROCK_LB_RTC_FREQ_KHZ_CONFIG               0x4e2u /* inferred */

#endif /* BEDROCK_LB_GEN_H */
