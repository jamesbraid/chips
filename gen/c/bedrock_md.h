/* generated from defs/bedrock_md.toml by defs-gen - do not edit, change the source */
/* Bedrock memory and directory (MD) registers: field layouts, reset statements, error records and backdoor carriers */
#ifndef BEDROCK_MD_GEN_H
#define BEDROCK_MD_GEN_H

#include <stdint.h>


/* enum dir_format */
#define BEDROCK_MD_DIR_FORMAT_UNOWNED                0 /* established */
#define BEDROCK_MD_DIR_FORMAT_POINTER                1 /* established */
#define BEDROCK_MD_DIR_FORMAT_SHARED_FINE            2 /* established */
#define BEDROCK_MD_DIR_FORMAT_SHARED_COARSE          3 /* established */

/* enum dir_pointer_state */
#define BEDROCK_MD_DIR_POINTER_STATE_EXCLUSIVE       0 /* established */
#define BEDROCK_MD_DIR_POINTER_STATE_BUSY_SHARED     4 /* established */
#define BEDROCK_MD_DIR_POINTER_STATE_BUSY_EXCLUSIVE  5 /* established */
#define BEDROCK_MD_DIR_POINTER_STATE_WAIT            6 /* established */
#define BEDROCK_MD_DIR_POINTER_STATE_POISONED        7 /* established */

/* enum size_code */
#define BEDROCK_MD_SIZE_CODE_EMPTY                   0 /* inferred */
#define BEDROCK_MD_SIZE_CODE_MB64                    1 /* inferred */
#define BEDROCK_MD_SIZE_CODE_MB128                   2 /* inferred */
#define BEDROCK_MD_SIZE_CODE_MB256                   3 /* inferred */
#define BEDROCK_MD_SIZE_CODE_MB512                   4 /* inferred */
#define BEDROCK_MD_SIZE_CODE_GB1                     5 /* inferred */

/*
 * Access-rights vector. A region whose bit is set is inside the cell and uses the directory's local-access protection instead of per-region protection. The same vector sets the access rights for the Hub special spaces: set gives read and write, clear gives read only, except the local and remote register windows, which are inaccessible when the bit is clear. The header attributes region size to the network interface, while the local block's revision register holds it. Reset unknown: the header states no value.
 */
/* current_cell: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_CURRENT_CELL                      0x780000 /* established */
#define BEDROCK_MD_CURRENT_CELL_REGION_BITS_SHIFT    0 /* established */
#define BEDROCK_MD_CURRENT_CELL_REGION_BITS_MASK     0xffffffffffffffffull
#define BEDROCK_MD_CURRENT_CELL_REGION_BITS_INPLACE  (BEDROCK_MD_CURRENT_CELL_REGION_BITS_MASK << BEDROCK_MD_CURRENT_CELL_REGION_BITS_SHIFT)

/*
 * Memory configuration. Each DIMM position d has a byte at bits 8d+7 to 8d holding two bank enables, a DRAM width bit and a size code. Addresses beyond a configured size return errors. The header says software must ask the system controller whether a DIMM is x4 or x8/x16 before it sets the width. The header says the register survives a soft reset. Reset unknown.
 */
/* memory_config: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MEMORY_CONFIG                     0x780008 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_RCD_RP_CONFIG_SHIFT 60 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_RCD_RP_CONFIG_MASK  0x3ull
#define BEDROCK_MD_MEMORY_CONFIG_RCD_RP_CONFIG_INPLACE (BEDROCK_MD_MEMORY_CONFIG_RCD_RP_CONFIG_MASK << BEDROCK_MD_MEMORY_CONFIG_RCD_RP_CONFIG_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_TIMING_HIGH_SHIFT   56 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_TIMING_HIGH_MASK    0x7ull
#define BEDROCK_MD_MEMORY_CONFIG_TIMING_HIGH_INPLACE (BEDROCK_MD_MEMORY_CONFIG_TIMING_HIGH_MASK << BEDROCK_MD_MEMORY_CONFIG_TIMING_HIGH_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_TIMING_LOW_SHIFT    48 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_TIMING_LOW_MASK     0x3full
#define BEDROCK_MD_MEMORY_CONFIG_TIMING_LOW_INPLACE  (BEDROCK_MD_MEMORY_CONFIG_TIMING_LOW_MASK << BEDROCK_MD_MEMORY_CONFIG_TIMING_LOW_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_IGNORE_CPU_PROTECTION_SHIFT 47 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_IGNORE_CPU_PROTECTION_MASK 0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_IGNORE_CPU_PROTECTION_INPLACE (BEDROCK_MD_MEMORY_CONFIG_IGNORE_CPU_PROTECTION_MASK << BEDROCK_MD_MEMORY_CONFIG_IGNORE_CPU_PROTECTION_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_IGNORE_IO_PROTECTION_SHIFT 46 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_IGNORE_IO_PROTECTION_MASK 0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_IGNORE_IO_PROTECTION_INPLACE (BEDROCK_MD_MEMORY_CONFIG_IGNORE_IO_PROTECTION_MASK << BEDROCK_MD_MEMORY_CONFIG_IGNORE_IO_PROTECTION_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_IO_PROTECTION_ENABLE_SHIFT 45 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_IO_PROTECTION_ENABLE_MASK 0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_IO_PROTECTION_ENABLE_INPLACE (BEDROCK_MD_MEMORY_CONFIG_IO_PROTECTION_ENABLE_MASK << BEDROCK_MD_MEMORY_CONFIG_IO_PROTECTION_ENABLE_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_CELL_PROTECTION_ENABLE_SHIFT 44 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_CELL_PROTECTION_ENABLE_MASK 0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_CELL_PROTECTION_ENABLE_INPLACE (BEDROCK_MD_MEMORY_CONFIG_CELL_PROTECTION_ENABLE_MASK << BEDROCK_MD_MEMORY_CONFIG_CELL_PROTECTION_ENABLE_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_BANK_SELECT_SHIFT   32 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_BANK_SELECT_MASK    0x3ull
#define BEDROCK_MD_MEMORY_CONFIG_BANK_SELECT_INPLACE (BEDROCK_MD_MEMORY_CONFIG_BANK_SELECT_MASK << BEDROCK_MD_MEMORY_CONFIG_BANK_SELECT_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS3_SIZE_SHIFT     28 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS3_SIZE_MASK      0xfull
#define BEDROCK_MD_MEMORY_CONFIG_POS3_SIZE_INPLACE   (BEDROCK_MD_MEMORY_CONFIG_POS3_SIZE_MASK << BEDROCK_MD_MEMORY_CONFIG_POS3_SIZE_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS3_WIDTH_SHIFT    27 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS3_WIDTH_MASK     0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_POS3_WIDTH_INPLACE  (BEDROCK_MD_MEMORY_CONFIG_POS3_WIDTH_MASK << BEDROCK_MD_MEMORY_CONFIG_POS3_WIDTH_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS3_ENABLES_SHIFT  24 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS3_ENABLES_MASK   0x3ull
#define BEDROCK_MD_MEMORY_CONFIG_POS3_ENABLES_INPLACE (BEDROCK_MD_MEMORY_CONFIG_POS3_ENABLES_MASK << BEDROCK_MD_MEMORY_CONFIG_POS3_ENABLES_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS2_SIZE_SHIFT     20 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS2_SIZE_MASK      0xfull
#define BEDROCK_MD_MEMORY_CONFIG_POS2_SIZE_INPLACE   (BEDROCK_MD_MEMORY_CONFIG_POS2_SIZE_MASK << BEDROCK_MD_MEMORY_CONFIG_POS2_SIZE_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS2_WIDTH_SHIFT    19 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS2_WIDTH_MASK     0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_POS2_WIDTH_INPLACE  (BEDROCK_MD_MEMORY_CONFIG_POS2_WIDTH_MASK << BEDROCK_MD_MEMORY_CONFIG_POS2_WIDTH_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS2_ENABLES_SHIFT  16 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS2_ENABLES_MASK   0x3ull
#define BEDROCK_MD_MEMORY_CONFIG_POS2_ENABLES_INPLACE (BEDROCK_MD_MEMORY_CONFIG_POS2_ENABLES_MASK << BEDROCK_MD_MEMORY_CONFIG_POS2_ENABLES_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS1_SIZE_SHIFT     12 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS1_SIZE_MASK      0xfull
#define BEDROCK_MD_MEMORY_CONFIG_POS1_SIZE_INPLACE   (BEDROCK_MD_MEMORY_CONFIG_POS1_SIZE_MASK << BEDROCK_MD_MEMORY_CONFIG_POS1_SIZE_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS1_WIDTH_SHIFT    11 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS1_WIDTH_MASK     0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_POS1_WIDTH_INPLACE  (BEDROCK_MD_MEMORY_CONFIG_POS1_WIDTH_MASK << BEDROCK_MD_MEMORY_CONFIG_POS1_WIDTH_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS1_ENABLES_SHIFT  8 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS1_ENABLES_MASK   0x3ull
#define BEDROCK_MD_MEMORY_CONFIG_POS1_ENABLES_INPLACE (BEDROCK_MD_MEMORY_CONFIG_POS1_ENABLES_MASK << BEDROCK_MD_MEMORY_CONFIG_POS1_ENABLES_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS0_SIZE_SHIFT     4 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS0_SIZE_MASK      0xfull
#define BEDROCK_MD_MEMORY_CONFIG_POS0_SIZE_INPLACE   (BEDROCK_MD_MEMORY_CONFIG_POS0_SIZE_MASK << BEDROCK_MD_MEMORY_CONFIG_POS0_SIZE_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS0_WIDTH_SHIFT    3 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS0_WIDTH_MASK     0x1ull
#define BEDROCK_MD_MEMORY_CONFIG_POS0_WIDTH_INPLACE  (BEDROCK_MD_MEMORY_CONFIG_POS0_WIDTH_MASK << BEDROCK_MD_MEMORY_CONFIG_POS0_WIDTH_SHIFT)
#define BEDROCK_MD_MEMORY_CONFIG_POS0_ENABLES_SHIFT  0 /* established */
#define BEDROCK_MD_MEMORY_CONFIG_POS0_ENABLES_MASK   0x3ull
#define BEDROCK_MD_MEMORY_CONFIG_POS0_ENABLES_INPLACE (BEDROCK_MD_MEMORY_CONFIG_POS0_ENABLES_MASK << BEDROCK_MD_MEMORY_CONFIG_POS0_ENABLES_SHIFT)

/*
 * Arbitration control. The arbitration timing is not specified by the header. Reset unknown.
 */
/* arbitration_control: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_ARBITRATION_CONTROL               0x780010 /* established */
#define BEDROCK_MD_ARBITRATION_CONTROL_WRITE_GUARANTEE_SHIFT 4 /* established */
#define BEDROCK_MD_ARBITRATION_CONTROL_WRITE_GUARANTEE_MASK 0xfull
#define BEDROCK_MD_ARBITRATION_CONTROL_WRITE_GUARANTEE_INPLACE (BEDROCK_MD_ARBITRATION_CONTROL_WRITE_GUARANTEE_MASK << BEDROCK_MD_ARBITRATION_CONTROL_WRITE_GUARANTEE_SHIFT)
#define BEDROCK_MD_ARBITRATION_CONTROL_REPLY_GUARANTEE_SHIFT 0 /* established */
#define BEDROCK_MD_ARBITRATION_CONTROL_REPLY_GUARANTEE_MASK 0xfull
#define BEDROCK_MD_ARBITRATION_CONTROL_REPLY_GUARANTEE_INPLACE (BEDROCK_MD_ARBITRATION_CONTROL_REPLY_GUARANTEE_MASK << BEDROCK_MD_ARBITRATION_CONTROL_REPLY_GUARANTEE_SHIFT)

/*
 * Page-migration configuration. The header names the interval, node mask and enable. Interval units and the scheduling rule are not given. Reset unknown; the software that uses the migration interface never touches this register, so who sets the enable bit is unknown.
 */
/* migration_config: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MIGRATION_CONFIG                  0x780018 /* established */
#define BEDROCK_MD_MIGRATION_CONFIG_ENABLE_SHIFT     32 /* established */
#define BEDROCK_MD_MIGRATION_CONFIG_ENABLE_MASK      0x1ull
#define BEDROCK_MD_MIGRATION_CONFIG_ENABLE_INPLACE   (BEDROCK_MD_MIGRATION_CONFIG_ENABLE_MASK << BEDROCK_MD_MIGRATION_CONFIG_ENABLE_SHIFT)
#define BEDROCK_MD_MIGRATION_CONFIG_NODE_MASK_SHIFT  16 /* established */
#define BEDROCK_MD_MIGRATION_CONFIG_NODE_MASK_MASK   0xffull
#define BEDROCK_MD_MIGRATION_CONFIG_NODE_MASK_INPLACE (BEDROCK_MD_MIGRATION_CONFIG_NODE_MASK_MASK << BEDROCK_MD_MIGRATION_CONFIG_NODE_MASK_SHIFT)
#define BEDROCK_MD_MIGRATION_CONFIG_INTERVAL_SHIFT   0 /* established */
#define BEDROCK_MD_MIGRATION_CONFIG_INTERVAL_MASK    0x3ffull
#define BEDROCK_MD_MIGRATION_CONFIG_INTERVAL_INPLACE (BEDROCK_MD_MIGRATION_CONFIG_INTERVAL_MASK << BEDROCK_MD_MIGRATION_CONFIG_INTERVAL_SHIFT)

/*
 * Fetch-and-op cache status 0: a captured cache entry. Guest write behaviour is not given. Reset unknown.
 */
/* fetchop_cache_status0: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS0             0x780020 /* established */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS0_VALID_SHIFT 63 /* established */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS0_VALID_MASK  0x1ull
#define BEDROCK_MD_FETCHOP_CACHE_STATUS0_VALID_INPLACE (BEDROCK_MD_FETCHOP_CACHE_STATUS0_VALID_MASK << BEDROCK_MD_FETCHOP_CACHE_STATUS0_VALID_SHIFT)
#define BEDROCK_MD_FETCHOP_CACHE_STATUS0_ADDRESS_SHIFT 6 /* established */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS0_ADDRESS_MASK 0x7ffffffull
#define BEDROCK_MD_FETCHOP_CACHE_STATUS0_ADDRESS_INPLACE (BEDROCK_MD_FETCHOP_CACHE_STATUS0_ADDRESS_MASK << BEDROCK_MD_FETCHOP_CACHE_STATUS0_ADDRESS_SHIFT)

/*
 * Fetch-and-op cache status 1: a second captured cache entry with the same layout as status 0. Reset unknown.
 */
/* fetchop_cache_status1: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS1             0x780028 /* established */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS1_VALID_SHIFT 63 /* established */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS1_VALID_MASK  0x1ull
#define BEDROCK_MD_FETCHOP_CACHE_STATUS1_VALID_INPLACE (BEDROCK_MD_FETCHOP_CACHE_STATUS1_VALID_MASK << BEDROCK_MD_FETCHOP_CACHE_STATUS1_VALID_SHIFT)
#define BEDROCK_MD_FETCHOP_CACHE_STATUS1_ADDRESS_SHIFT 6 /* established */
#define BEDROCK_MD_FETCHOP_CACHE_STATUS1_ADDRESS_MASK 0x7ffffffull
#define BEDROCK_MD_FETCHOP_CACHE_STATUS1_ADDRESS_INPLACE (BEDROCK_MD_FETCHOP_CACHE_STATUS1_ADDRESS_MASK << BEDROCK_MD_FETCHOP_CACHE_STATUS1_ADDRESS_SHIFT)

/*
 * Miscellaneous error word 0: message header fields and two-bit error flags. The field positions are not summarised here. Reset unknown.
 */
/* misc_error0: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MISC_ERROR0                       0x780040 /* established */

/*
 * Miscellaneous error word 1: a 38-bit address and the same style of flags. The field positions are not summarised here. Reset unknown.
 */
/* misc_error1: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MISC_ERROR1                       0x780048 /* established */

/*
 * Clear alias of miscellaneous error word 1. The header names it a clear register without saying whether a read or a write clears it. The one consumer reads and discards the value. The clearing mechanism is unknown.
 */
/* misc_error1_clr: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MISC_ERROR1_CLR                   0x780058 /* established */

/*
 * Reply-queue credit sizes, all read-only fields. The header gives 12 header entries and 24 data entries as the defaults for each queue. A write resets the credit counters to these defaults.
 */
/* outgoing_reply_queue_size: rw64, reset 0x1818180c0c0c00; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE         0x780060 /* established */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_DATA_QUEUE_SHIFT 48 /* established */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_DATA_QUEUE_MASK 0x1full
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_DATA_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_DATA_QUEUE_MASK << BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_DATA_QUEUE_SHIFT)
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_DATA_QUEUE_SHIFT 40 /* established */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_DATA_QUEUE_MASK 0x1full
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_DATA_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_DATA_QUEUE_MASK << BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_DATA_QUEUE_SHIFT)
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_DATA_QUEUE_SHIFT 32 /* established */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_DATA_QUEUE_MASK 0x1full
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_DATA_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_DATA_QUEUE_MASK << BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_DATA_QUEUE_SHIFT)
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_HEADER_QUEUE_SHIFT 24 /* established */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_HEADER_QUEUE_MASK 0xfull
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_HEADER_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_HEADER_QUEUE_MASK << BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_THIRD_HEADER_QUEUE_SHIFT)
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_HEADER_QUEUE_SHIFT 16 /* established */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_HEADER_QUEUE_MASK 0xfull
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_HEADER_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_HEADER_QUEUE_MASK << BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI1_HEADER_QUEUE_SHIFT)
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_HEADER_QUEUE_SHIFT 8 /* established */
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_HEADER_QUEUE_MASK 0xfull
#define BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_HEADER_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_HEADER_QUEUE_MASK << BEDROCK_MD_OUTGOING_REPLY_QUEUE_SIZE_PI0_HEADER_QUEUE_SHIFT)

/*
 * Performance counter 0 selection. Complete event encodings and interrupt cadence are not given by the header. Reset unknown.
 */
/* perf_select0: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_PERF_SELECT0                      0x790000 /* established */
#define BEDROCK_MD_PERF_SELECT0_INTERRUPT_SHIFT      63 /* established */
#define BEDROCK_MD_PERF_SELECT0_INTERRUPT_MASK       0x1ull
#define BEDROCK_MD_PERF_SELECT0_INTERRUPT_INPLACE    (BEDROCK_MD_PERF_SELECT0_INTERRUPT_MASK << BEDROCK_MD_PERF_SELECT0_INTERRUPT_SHIFT)
#define BEDROCK_MD_PERF_SELECT0_COMMAND_SHIFT        20 /* established */
#define BEDROCK_MD_PERF_SELECT0_COMMAND_MASK         0xffffffffffull
#define BEDROCK_MD_PERF_SELECT0_COMMAND_INPLACE      (BEDROCK_MD_PERF_SELECT0_COMMAND_MASK << BEDROCK_MD_PERF_SELECT0_COMMAND_SHIFT)
#define BEDROCK_MD_PERF_SELECT0_CHANNEL_SHIFT        16 /* established */
#define BEDROCK_MD_PERF_SELECT0_CHANNEL_MASK         0xfull
#define BEDROCK_MD_PERF_SELECT0_CHANNEL_INPLACE      (BEDROCK_MD_PERF_SELECT0_CHANNEL_MASK << BEDROCK_MD_PERF_SELECT0_CHANNEL_SHIFT)
#define BEDROCK_MD_PERF_SELECT0_SOURCE_SHIFT         8 /* established */
#define BEDROCK_MD_PERF_SELECT0_SOURCE_MASK          0x7full
#define BEDROCK_MD_PERF_SELECT0_SOURCE_INPLACE       (BEDROCK_MD_PERF_SELECT0_SOURCE_MASK << BEDROCK_MD_PERF_SELECT0_SOURCE_SHIFT)
#define BEDROCK_MD_PERF_SELECT0_ACTIVITY_SHIFT       4 /* established */
#define BEDROCK_MD_PERF_SELECT0_ACTIVITY_MASK        0xfull
#define BEDROCK_MD_PERF_SELECT0_ACTIVITY_INPLACE     (BEDROCK_MD_PERF_SELECT0_ACTIVITY_MASK << BEDROCK_MD_PERF_SELECT0_ACTIVITY_SHIFT)
#define BEDROCK_MD_PERF_SELECT0_MODE_SHIFT           0 /* established */
#define BEDROCK_MD_PERF_SELECT0_MODE_MASK            0x3ull
#define BEDROCK_MD_PERF_SELECT0_MODE_INPLACE         (BEDROCK_MD_PERF_SELECT0_MODE_MASK << BEDROCK_MD_PERF_SELECT0_MODE_SHIFT)

/*
 * Performance counter 1 selection, with the same layout as counter 0. Reset unknown.
 */
/* perf_select1: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_PERF_SELECT1                      0x790008 /* established */
#define BEDROCK_MD_PERF_SELECT1_INTERRUPT_SHIFT      63 /* established */
#define BEDROCK_MD_PERF_SELECT1_INTERRUPT_MASK       0x1ull
#define BEDROCK_MD_PERF_SELECT1_INTERRUPT_INPLACE    (BEDROCK_MD_PERF_SELECT1_INTERRUPT_MASK << BEDROCK_MD_PERF_SELECT1_INTERRUPT_SHIFT)
#define BEDROCK_MD_PERF_SELECT1_COMMAND_SHIFT        20 /* established */
#define BEDROCK_MD_PERF_SELECT1_COMMAND_MASK         0xffffffffffull
#define BEDROCK_MD_PERF_SELECT1_COMMAND_INPLACE      (BEDROCK_MD_PERF_SELECT1_COMMAND_MASK << BEDROCK_MD_PERF_SELECT1_COMMAND_SHIFT)
#define BEDROCK_MD_PERF_SELECT1_CHANNEL_SHIFT        16 /* established */
#define BEDROCK_MD_PERF_SELECT1_CHANNEL_MASK         0xfull
#define BEDROCK_MD_PERF_SELECT1_CHANNEL_INPLACE      (BEDROCK_MD_PERF_SELECT1_CHANNEL_MASK << BEDROCK_MD_PERF_SELECT1_CHANNEL_SHIFT)
#define BEDROCK_MD_PERF_SELECT1_SOURCE_SHIFT         8 /* established */
#define BEDROCK_MD_PERF_SELECT1_SOURCE_MASK          0x7full
#define BEDROCK_MD_PERF_SELECT1_SOURCE_INPLACE       (BEDROCK_MD_PERF_SELECT1_SOURCE_MASK << BEDROCK_MD_PERF_SELECT1_SOURCE_SHIFT)
#define BEDROCK_MD_PERF_SELECT1_ACTIVITY_SHIFT       4 /* established */
#define BEDROCK_MD_PERF_SELECT1_ACTIVITY_MASK        0xfull
#define BEDROCK_MD_PERF_SELECT1_ACTIVITY_INPLACE     (BEDROCK_MD_PERF_SELECT1_ACTIVITY_MASK << BEDROCK_MD_PERF_SELECT1_ACTIVITY_SHIFT)
#define BEDROCK_MD_PERF_SELECT1_MODE_SHIFT           0 /* established */
#define BEDROCK_MD_PERF_SELECT1_MODE_MASK            0x3ull
#define BEDROCK_MD_PERF_SELECT1_MODE_INPLACE         (BEDROCK_MD_PERF_SELECT1_MODE_MASK << BEDROCK_MD_PERF_SELECT1_MODE_SHIFT)

/*
 * Performance counter 0. The header describes a 41-bit count; the events that advance it are not given. The Itanium console code and the boot firmware of this machine class both use the word as a lock word by setting and clearing bits, which the header does not sanction. That use is a software expectation, inferred. Reset unknown.
 */
/* perf_counter0: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_PERF_COUNTER0                     0x790010 /* established */
#define BEDROCK_MD_PERF_COUNTER0_COUNT_SHIFT         0 /* established */
#define BEDROCK_MD_PERF_COUNTER0_COUNT_MASK          0x1ffffffffffull
#define BEDROCK_MD_PERF_COUNTER0_COUNT_INPLACE       (BEDROCK_MD_PERF_COUNTER0_COUNT_MASK << BEDROCK_MD_PERF_COUNTER0_COUNT_SHIFT)

/*
 * Performance counter 1. The same 41-bit count layout as counter 0. Reset unknown.
 */
/* perf_counter1: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_PERF_COUNTER1                     0x790018 /* established */
#define BEDROCK_MD_PERF_COUNTER1_COUNT_SHIFT         0 /* established */
#define BEDROCK_MD_PERF_COUNTER1_COUNT_MASK          0x1ffffffffffull
#define BEDROCK_MD_PERF_COUNTER1_COUNT_INPLACE       (BEDROCK_MD_PERF_COUNTER1_COUNT_MASK << BEDROCK_MD_PERF_COUNTER1_COUNT_SHIFT)

/*
 * Refresh control. Once the memory configuration holds the DIMM information, the hardware refreshes every bank. If a refresh window expires with banks unrefreshed, all other traffic halts until they are refreshed. The enable bit is cleared on reset because the first DIMM operation must be a mode-register write. The enable and threshold survive a soft reset. The live counter's reset is unknown.
 */
/* refresh_control: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_REFRESH_CONTROL                   0x7a0000 /* established */
#define BEDROCK_MD_REFRESH_CONTROL_ENABLE_SHIFT      63 /* established */
#define BEDROCK_MD_REFRESH_CONTROL_ENABLE_MASK       0x1ull
#define BEDROCK_MD_REFRESH_CONTROL_ENABLE_INPLACE    (BEDROCK_MD_REFRESH_CONTROL_ENABLE_MASK << BEDROCK_MD_REFRESH_CONTROL_ENABLE_SHIFT)
#define BEDROCK_MD_REFRESH_CONTROL_LIVE_COUNTER_SHIFT 12 /* established */
#define BEDROCK_MD_REFRESH_CONTROL_LIVE_COUNTER_MASK 0xfffull
#define BEDROCK_MD_REFRESH_CONTROL_LIVE_COUNTER_INPLACE (BEDROCK_MD_REFRESH_CONTROL_LIVE_COUNTER_MASK << BEDROCK_MD_REFRESH_CONTROL_LIVE_COUNTER_SHIFT)
#define BEDROCK_MD_REFRESH_CONTROL_THRESHOLD_SHIFT   0 /* established */
#define BEDROCK_MD_REFRESH_CONTROL_THRESHOLD_MASK    0xfffull
#define BEDROCK_MD_REFRESH_CONTROL_THRESHOLD_INPLACE (BEDROCK_MD_REFRESH_CONTROL_THRESHOLD_MASK << BEDROCK_MD_REFRESH_CONTROL_THRESHOLD_SHIFT)

/*
 * Junk-bus timing for the flash PROM, the L1 UART and a device the Linux header names Synergy. The header names the timing fields; it does not place the Synergy device on any board. This is the only register in any unit that names the UART and the flash PROM. Reset unknown.
 */
/* junk_bus_timing: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_JUNK_BUS_TIMING                   0x7a0008 /* established */
#define BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_ENABLE_SHIFT 40 /* established */
#define BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_ENABLE_MASK 0xffull
#define BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_ENABLE_INPLACE (BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_ENABLE_MASK << BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_ENABLE_SHIFT)
#define BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_SETUP_HOLD_SHIFT 32 /* established */
#define BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_SETUP_HOLD_MASK 0xffull
#define BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_SETUP_HOLD_INPLACE (BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_SETUP_HOLD_MASK << BEDROCK_MD_JUNK_BUS_TIMING_SYNERGY_SETUP_HOLD_SHIFT)
#define BEDROCK_MD_JUNK_BUS_TIMING_UART_ENABLE_SHIFT 24 /* established */
#define BEDROCK_MD_JUNK_BUS_TIMING_UART_ENABLE_MASK  0xffull
#define BEDROCK_MD_JUNK_BUS_TIMING_UART_ENABLE_INPLACE (BEDROCK_MD_JUNK_BUS_TIMING_UART_ENABLE_MASK << BEDROCK_MD_JUNK_BUS_TIMING_UART_ENABLE_SHIFT)
#define BEDROCK_MD_JUNK_BUS_TIMING_UART_SETUP_HOLD_SHIFT 16 /* established */
#define BEDROCK_MD_JUNK_BUS_TIMING_UART_SETUP_HOLD_MASK 0xffull
#define BEDROCK_MD_JUNK_BUS_TIMING_UART_SETUP_HOLD_INPLACE (BEDROCK_MD_JUNK_BUS_TIMING_UART_SETUP_HOLD_MASK << BEDROCK_MD_JUNK_BUS_TIMING_UART_SETUP_HOLD_SHIFT)
#define BEDROCK_MD_JUNK_BUS_TIMING_FLASH_ENABLE_SHIFT 8 /* established */
#define BEDROCK_MD_JUNK_BUS_TIMING_FLASH_ENABLE_MASK 0xffull
#define BEDROCK_MD_JUNK_BUS_TIMING_FLASH_ENABLE_INPLACE (BEDROCK_MD_JUNK_BUS_TIMING_FLASH_ENABLE_MASK << BEDROCK_MD_JUNK_BUS_TIMING_FLASH_ENABLE_SHIFT)
#define BEDROCK_MD_JUNK_BUS_TIMING_FLASH_SETUP_HOLD_SHIFT 0 /* established */
#define BEDROCK_MD_JUNK_BUS_TIMING_FLASH_SETUP_HOLD_MASK 0xffull
#define BEDROCK_MD_JUNK_BUS_TIMING_FLASH_SETUP_HOLD_INPLACE (BEDROCK_MD_JUNK_BUS_TIMING_FLASH_SETUP_HOLD_MASK << BEDROCK_MD_JUNK_BUS_TIMING_FLASH_SETUP_HOLD_SHIFT)

/*
 * Reads the value on LED bank 0. The header says a read of this register gives the 8-bit LED value. Whether a write drives the LEDs is not stated. Reset unknown.
 */
/* led0: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_LED0                              0x7a0010 /* established */
#define BEDROCK_MD_LED0_DATA_SHIFT                   0 /* established */
#define BEDROCK_MD_LED0_DATA_MASK                    0xffull
#define BEDROCK_MD_LED0_DATA_INPLACE                 (BEDROCK_MD_LED0_DATA_MASK << BEDROCK_MD_LED0_DATA_SHIFT)

/*
 * Reads the value on LED bank 1. Otherwise as LED bank 0.
 */
/* led1: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_LED1                              0x7a0018 /* established */
#define BEDROCK_MD_LED1_DATA_SHIFT                   0 /* established */
#define BEDROCK_MD_LED1_DATA_MASK                    0xffull
#define BEDROCK_MD_LED1_DATA_INPLACE                 (BEDROCK_MD_LED1_DATA_MASK << BEDROCK_MD_LED1_DATA_SHIFT)

/*
 * Reads the value on LED bank 2. Otherwise as LED bank 0.
 */
/* led2: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_LED2                              0x7a0020 /* established */
#define BEDROCK_MD_LED2_DATA_SHIFT                   0 /* established */
#define BEDROCK_MD_LED2_DATA_MASK                    0xffull
#define BEDROCK_MD_LED2_DATA_INPLACE                 (BEDROCK_MD_LED2_DATA_MASK << BEDROCK_MD_LED2_DATA_SHIFT)

/*
 * Reads the value on LED bank 3. Otherwise as LED bank 0.
 */
/* led3: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_LED3                              0x7a0028 /* established */
#define BEDROCK_MD_LED3_DATA_SHIFT                   0 /* established */
#define BEDROCK_MD_LED3_DATA_MASK                    0xffull
#define BEDROCK_MD_LED3_DATA_INPLACE                 (BEDROCK_MD_LED3_DATA_MASK << BEDROCK_MD_LED3_DATA_SHIFT)

/*
 * Self-test control. Command precedence, self-clearing behaviour, the algorithm and the duration are unresolved. A retained write cannot qualify a completed test.
 */
/* self_test_control: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELF_TEST_CONTROL                 0x7a0030 /* established */
#define BEDROCK_MD_SELF_TEST_CONTROL_DIMM_SHIFT      5 /* established */
#define BEDROCK_MD_SELF_TEST_CONTROL_DIMM_MASK       0x3ull
#define BEDROCK_MD_SELF_TEST_CONTROL_DIMM_INPLACE    (BEDROCK_MD_SELF_TEST_CONTROL_DIMM_MASK << BEDROCK_MD_SELF_TEST_CONTROL_DIMM_SHIFT)
#define BEDROCK_MD_SELF_TEST_CONTROL_BANK_SHIFT      4 /* established */
#define BEDROCK_MD_SELF_TEST_CONTROL_BANK_MASK       0x1ull
#define BEDROCK_MD_SELF_TEST_CONTROL_BANK_INPLACE    (BEDROCK_MD_SELF_TEST_CONTROL_BANK_MASK << BEDROCK_MD_SELF_TEST_CONTROL_BANK_SHIFT)
#define BEDROCK_MD_SELF_TEST_CONTROL_RESET_SHIFT     2 /* established */
#define BEDROCK_MD_SELF_TEST_CONTROL_RESET_MASK      0x1ull
#define BEDROCK_MD_SELF_TEST_CONTROL_RESET_INPLACE   (BEDROCK_MD_SELF_TEST_CONTROL_RESET_MASK << BEDROCK_MD_SELF_TEST_CONTROL_RESET_SHIFT)
#define BEDROCK_MD_SELF_TEST_CONTROL_STOP_SHIFT      1 /* established */
#define BEDROCK_MD_SELF_TEST_CONTROL_STOP_MASK       0x1ull
#define BEDROCK_MD_SELF_TEST_CONTROL_STOP_INPLACE    (BEDROCK_MD_SELF_TEST_CONTROL_STOP_MASK << BEDROCK_MD_SELF_TEST_CONTROL_STOP_SHIFT)
#define BEDROCK_MD_SELF_TEST_CONTROL_START_SHIFT     0 /* established */
#define BEDROCK_MD_SELF_TEST_CONTROL_START_MASK      0x1ull
#define BEDROCK_MD_SELF_TEST_CONTROL_START_INPLACE   (BEDROCK_MD_SELF_TEST_CONTROL_START_MASK << BEDROCK_MD_SELF_TEST_CONTROL_START_SHIFT)

/*
 * Self-test data and pattern control. The header gives the control names, not their full transformation rules.
 */
/* self_test_data: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELF_TEST_DATA                    0x7a0038 /* established */
#define BEDROCK_MD_SELF_TEST_DATA_WRITE_CONTROL_SHIFT 7 /* established */
#define BEDROCK_MD_SELF_TEST_DATA_WRITE_CONTROL_MASK 0x1ull
#define BEDROCK_MD_SELF_TEST_DATA_WRITE_CONTROL_INPLACE (BEDROCK_MD_SELF_TEST_DATA_WRITE_CONTROL_MASK << BEDROCK_MD_SELF_TEST_DATA_WRITE_CONTROL_SHIFT)
#define BEDROCK_MD_SELF_TEST_DATA_CYCLE_CONTROL_SHIFT 6 /* established */
#define BEDROCK_MD_SELF_TEST_DATA_CYCLE_CONTROL_MASK 0x1ull
#define BEDROCK_MD_SELF_TEST_DATA_CYCLE_CONTROL_INPLACE (BEDROCK_MD_SELF_TEST_DATA_CYCLE_CONTROL_MASK << BEDROCK_MD_SELF_TEST_DATA_CYCLE_CONTROL_SHIFT)
#define BEDROCK_MD_SELF_TEST_DATA_BYTE_CONTROL_SHIFT 5 /* established */
#define BEDROCK_MD_SELF_TEST_DATA_BYTE_CONTROL_MASK  0x1ull
#define BEDROCK_MD_SELF_TEST_DATA_BYTE_CONTROL_INPLACE (BEDROCK_MD_SELF_TEST_DATA_BYTE_CONTROL_MASK << BEDROCK_MD_SELF_TEST_DATA_BYTE_CONTROL_SHIFT)
#define BEDROCK_MD_SELF_TEST_DATA_NIBBLE_CONTROL_SHIFT 4 /* established */
#define BEDROCK_MD_SELF_TEST_DATA_NIBBLE_CONTROL_MASK 0x1ull
#define BEDROCK_MD_SELF_TEST_DATA_NIBBLE_CONTROL_INPLACE (BEDROCK_MD_SELF_TEST_DATA_NIBBLE_CONTROL_MASK << BEDROCK_MD_SELF_TEST_DATA_NIBBLE_CONTROL_SHIFT)
#define BEDROCK_MD_SELF_TEST_DATA_INITIAL_PATTERN_SHIFT 0 /* established */
#define BEDROCK_MD_SELF_TEST_DATA_INITIAL_PATTERN_MASK 0xfull
#define BEDROCK_MD_SELF_TEST_DATA_INITIAL_PATTERN_INPLACE (BEDROCK_MD_SELF_TEST_DATA_INITIAL_PATTERN_MASK << BEDROCK_MD_SELF_TEST_DATA_INITIAL_PATTERN_SHIFT)

/*
 * Self-test error address: the failing column and row, and which block failed. Guest writes and the clearing mechanism are unresolved.
 */
/* self_test_error_addr: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR              0x7a0040 /* established */
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_ERROR_SHIFT 49 /* established */
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_ERROR_MASK 0x1ull
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_ERROR_INPLACE (BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_ERROR_MASK << BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_ERROR_SHIFT)
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_ERROR_SHIFT 48 /* established */
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_ERROR_MASK 0x1ull
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_ERROR_INPLACE (BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_ERROR_MASK << BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_ERROR_SHIFT)
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_ROW_SHIFT    32 /* established */
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_ROW_MASK     0x7fffull
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_ROW_INPLACE  (BEDROCK_MD_SELF_TEST_ERROR_ADDR_ROW_MASK << BEDROCK_MD_SELF_TEST_ERROR_ADDR_ROW_SHIFT)
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_COLUMN_SHIFT 16 /* established */
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_COLUMN_MASK 0x7fffull
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_COLUMN_INPLACE (BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_COLUMN_MASK << BEDROCK_MD_SELF_TEST_ERROR_ADDR_MEMORY_COLUMN_SHIFT)
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_COLUMN_SHIFT 0 /* established */
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_COLUMN_MASK 0x7fffull
#define BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_COLUMN_INPLACE (BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_COLUMN_MASK << BEDROCK_MD_SELF_TEST_ERROR_ADDR_DIRECTORY_COLUMN_SHIFT)

/*
 * Self-test status. Reports the result of the test. Neither bit is meaningful until the test has run to completion.
 */
/* self_test_status: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELF_TEST_STATUS                  0x7a0048 /* established */
#define BEDROCK_MD_SELF_TEST_STATUS_DONE_SHIFT       1 /* established */
#define BEDROCK_MD_SELF_TEST_STATUS_DONE_MASK        0x1ull
#define BEDROCK_MD_SELF_TEST_STATUS_DONE_INPLACE     (BEDROCK_MD_SELF_TEST_STATUS_DONE_MASK << BEDROCK_MD_SELF_TEST_STATUS_DONE_SHIFT)
#define BEDROCK_MD_SELF_TEST_STATUS_PASSED_SHIFT     0 /* established */
#define BEDROCK_MD_SELF_TEST_STATUS_PASSED_MASK      0x1ull
#define BEDROCK_MD_SELF_TEST_STATUS_PASSED_INPLACE   (BEDROCK_MD_SELF_TEST_STATUS_PASSED_MASK << BEDROCK_MD_SELF_TEST_STATUS_PASSED_SHIFT)

/*
 * Issue-block debug selector. The prose gives three bits while both endian layouts declare two. The width conflict is open. The meanings of the selections are not given.
 */
/* issue_debug_select: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_ISSUE_DEBUG_SELECT                0x7a0060 /* established */
#define BEDROCK_MD_ISSUE_DEBUG_SELECT_SELECTION_SHIFT 0 /* established */
#define BEDROCK_MD_ISSUE_DEBUG_SELECT_SELECTION_MASK 0x3ull
#define BEDROCK_MD_ISSUE_DEBUG_SELECT_SELECTION_INPLACE (BEDROCK_MD_ISSUE_DEBUG_SELECT_SELECTION_MASK << BEDROCK_MD_ISSUE_DEBUG_SELECT_SELECTION_SHIFT)

/*
 * Directory configuration. Bit 0 selects the premium directory format, and bit 1 ignores directory ECC. The register survives a soft reset. Reset unknown.
 */
/* dir_config: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_DIR_CONFIG                        0x7c0000 /* established */
#define BEDROCK_MD_DIR_CONFIG_IGNORE_DIR_ECC_SHIFT   1 /* established */
#define BEDROCK_MD_DIR_CONFIG_IGNORE_DIR_ECC_MASK    0x1ull
#define BEDROCK_MD_DIR_CONFIG_IGNORE_DIR_ECC_INPLACE (BEDROCK_MD_DIR_CONFIG_IGNORE_DIR_ECC_MASK << BEDROCK_MD_DIR_CONFIG_IGNORE_DIR_ECC_SHIFT)
#define BEDROCK_MD_DIR_CONFIG_PREMIUM_SHIFT          0 /* established */
#define BEDROCK_MD_DIR_CONFIG_PREMIUM_MASK           0x1ull
#define BEDROCK_MD_DIR_CONFIG_PREMIUM_INPLACE        (BEDROCK_MD_DIR_CONFIG_PREMIUM_MASK << BEDROCK_MD_DIR_CONFIG_PREMIUM_SHIFT)

/*
 * Directory error record. The address and syndrome belong to the highest-priority kind latched: uncorrectable above protection above correctable. Reset unknown; the header gives no value.
 */
/* dir_error: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_DIR_ERROR                         0x7c0010 /* established */
#define BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_VALID_SHIFT 63 /* established */
#define BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_VALID_MASK 0x1ull
#define BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_VALID_INPLACE (BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_VALID_MASK << BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_VALID_SHIFT)
#define BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_VALID_SHIFT 62 /* established */
#define BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_VALID_MASK 0x1ull
#define BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_VALID_INPLACE (BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_VALID_MASK << BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_VALID_SHIFT)
#define BEDROCK_MD_DIR_ERROR_CORRECTABLE_VALID_SHIFT 61 /* established */
#define BEDROCK_MD_DIR_ERROR_CORRECTABLE_VALID_MASK  0x1ull
#define BEDROCK_MD_DIR_ERROR_CORRECTABLE_VALID_INPLACE (BEDROCK_MD_DIR_ERROR_CORRECTABLE_VALID_MASK << BEDROCK_MD_DIR_ERROR_CORRECTABLE_VALID_SHIFT)
#define BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_VALID_SHIFT 60 /* established */
#define BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_VALID_MASK 0x1ull
#define BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_VALID_INPLACE (BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_VALID_MASK << BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_VALID_SHIFT)
#define BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_OVERRUN_SHIFT 59 /* established */
#define BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_OVERRUN_MASK 0x1ull
#define BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_OVERRUN_INPLACE (BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_OVERRUN_MASK << BEDROCK_MD_DIR_ERROR_UNCORRECTABLE_OVERRUN_SHIFT)
#define BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_OVERRUN_SHIFT 58 /* established */
#define BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_OVERRUN_MASK 0x1ull
#define BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_OVERRUN_INPLACE (BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_OVERRUN_MASK << BEDROCK_MD_DIR_ERROR_PROTECTION_DOUBLE_OVERRUN_SHIFT)
#define BEDROCK_MD_DIR_ERROR_CORRECTABLE_OVERRUN_SHIFT 57 /* established */
#define BEDROCK_MD_DIR_ERROR_CORRECTABLE_OVERRUN_MASK 0x1ull
#define BEDROCK_MD_DIR_ERROR_CORRECTABLE_OVERRUN_INPLACE (BEDROCK_MD_DIR_ERROR_CORRECTABLE_OVERRUN_MASK << BEDROCK_MD_DIR_ERROR_CORRECTABLE_OVERRUN_SHIFT)
#define BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_OVERRUN_SHIFT 56 /* established */
#define BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_OVERRUN_MASK 0x1ull
#define BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_OVERRUN_INPLACE (BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_OVERRUN_MASK << BEDROCK_MD_DIR_ERROR_PROTECTION_CORRECTABLE_OVERRUN_SHIFT)
#define BEDROCK_MD_DIR_ERROR_PROTECTION_INDEX_SHIFT  52 /* established */
#define BEDROCK_MD_DIR_ERROR_PROTECTION_INDEX_MASK   0x7ull
#define BEDROCK_MD_DIR_ERROR_PROTECTION_INDEX_INPLACE (BEDROCK_MD_DIR_ERROR_PROTECTION_INDEX_MASK << BEDROCK_MD_DIR_ERROR_PROTECTION_INDEX_SHIFT)
#define BEDROCK_MD_DIR_ERROR_BAD_PROTECTION_SHIFT    48 /* established */
#define BEDROCK_MD_DIR_ERROR_BAD_PROTECTION_MASK     0xfull
#define BEDROCK_MD_DIR_ERROR_BAD_PROTECTION_INPLACE  (BEDROCK_MD_DIR_ERROR_BAD_PROTECTION_MASK << BEDROCK_MD_DIR_ERROR_BAD_PROTECTION_SHIFT)
#define BEDROCK_MD_DIR_ERROR_SYNDROME_SHIFT          40 /* established */
#define BEDROCK_MD_DIR_ERROR_SYNDROME_MASK           0x7full
#define BEDROCK_MD_DIR_ERROR_SYNDROME_INPLACE        (BEDROCK_MD_DIR_ERROR_SYNDROME_MASK << BEDROCK_MD_DIR_ERROR_SYNDROME_SHIFT)
#define BEDROCK_MD_DIR_ERROR_HUB_SPECIAL_ADDRESS_SHIFT 3 /* established */
#define BEDROCK_MD_DIR_ERROR_HUB_SPECIAL_ADDRESS_MASK 0x3fffffffull
#define BEDROCK_MD_DIR_ERROR_HUB_SPECIAL_ADDRESS_INPLACE (BEDROCK_MD_DIR_ERROR_HUB_SPECIAL_ADDRESS_MASK << BEDROCK_MD_DIR_ERROR_HUB_SPECIAL_ADDRESS_SHIFT)

/*
 * Clear alias of the directory error record. The header repeats the base register's text and names no mechanism. Read-to-clear is the consumer's expectation, not a stated rule.
 */
/* dir_error_clr: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_DIR_ERROR_CLR                     0x7c0018 /* established */

/*
 * Protocol error record: directory state and format, pointer, message type, initiator, valid and overrun. The field positions are not summarised here. Reset unknown.
 */
/* protocol_error: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_PROTOCOL_ERROR                    0x7c0020 /* established */

/*
 * Clear alias of the protocol error record. The mechanism is not stated.
 */
/* protocol_error_clr: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_PROTOCOL_ERROR_CLR                0x7c0028 /* established */

/*
 * Page-migration candidate. On overrun the newest candidate replaces the earlier one. The clear operation is not established by the header's repeated text. Reset unknown.
 */
/* mig_candidate: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MIG_CANDIDATE                     0x7c0030 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_VALID_SHIFT         63 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_VALID_MASK          0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_VALID_INPLACE       (BEDROCK_MD_MIG_CANDIDATE_VALID_MASK << BEDROCK_MD_MIG_CANDIDATE_VALID_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_LOCAL_SHIFT         34 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_LOCAL_MASK          0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_LOCAL_INPLACE       (BEDROCK_MD_MIG_CANDIDATE_LOCAL_MASK << BEDROCK_MD_MIG_CANDIDATE_LOCAL_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_THRESHOLD_TYPE_SHIFT 33 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_THRESHOLD_TYPE_MASK 0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_THRESHOLD_TYPE_INPLACE (BEDROCK_MD_MIG_CANDIDATE_THRESHOLD_TYPE_MASK << BEDROCK_MD_MIG_CANDIDATE_THRESHOLD_TYPE_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_OVERRUN_SHIFT       32 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_OVERRUN_MASK        0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_OVERRUN_INPLACE     (BEDROCK_MD_MIG_CANDIDATE_OVERRUN_MASK << BEDROCK_MD_MIG_CANDIDATE_OVERRUN_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_INITIATOR_SHIFT     21 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_INITIATOR_MASK      0x7ffull
#define BEDROCK_MD_MIG_CANDIDATE_INITIATOR_INPLACE   (BEDROCK_MD_MIG_CANDIDATE_INITIATOR_MASK << BEDROCK_MD_MIG_CANDIDATE_INITIATOR_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_PAGE_ADDRESS_SHIFT  0 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_PAGE_ADDRESS_MASK   0x1fffffull
#define BEDROCK_MD_MIG_CANDIDATE_PAGE_ADDRESS_INPLACE (BEDROCK_MD_MIG_CANDIDATE_PAGE_ADDRESS_MASK << BEDROCK_MD_MIG_CANDIDATE_PAGE_ADDRESS_SHIFT)

/*
 * Clear alias of the migration candidate. Software reads only this alias and never the base register. That reading removes the candidate is inferred; the header does not say so.
 */
/* mig_candidate_clr: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MIG_CANDIDATE_CLR                 0x7c0038 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_CLR_VALID_SHIFT     63 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_CLR_VALID_MASK      0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_CLR_VALID_INPLACE   (BEDROCK_MD_MIG_CANDIDATE_CLR_VALID_MASK << BEDROCK_MD_MIG_CANDIDATE_CLR_VALID_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_CLR_LOCAL_SHIFT     34 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_CLR_LOCAL_MASK      0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_CLR_LOCAL_INPLACE   (BEDROCK_MD_MIG_CANDIDATE_CLR_LOCAL_MASK << BEDROCK_MD_MIG_CANDIDATE_CLR_LOCAL_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_CLR_THRESHOLD_TYPE_SHIFT 33 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_CLR_THRESHOLD_TYPE_MASK 0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_CLR_THRESHOLD_TYPE_INPLACE (BEDROCK_MD_MIG_CANDIDATE_CLR_THRESHOLD_TYPE_MASK << BEDROCK_MD_MIG_CANDIDATE_CLR_THRESHOLD_TYPE_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_CLR_OVERRUN_SHIFT   32 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_CLR_OVERRUN_MASK    0x1ull
#define BEDROCK_MD_MIG_CANDIDATE_CLR_OVERRUN_INPLACE (BEDROCK_MD_MIG_CANDIDATE_CLR_OVERRUN_MASK << BEDROCK_MD_MIG_CANDIDATE_CLR_OVERRUN_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_CLR_INITIATOR_SHIFT 21 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_CLR_INITIATOR_MASK  0x7ffull
#define BEDROCK_MD_MIG_CANDIDATE_CLR_INITIATOR_INPLACE (BEDROCK_MD_MIG_CANDIDATE_CLR_INITIATOR_MASK << BEDROCK_MD_MIG_CANDIDATE_CLR_INITIATOR_SHIFT)
#define BEDROCK_MD_MIG_CANDIDATE_CLR_PAGE_ADDRESS_SHIFT 0 /* established */
#define BEDROCK_MD_MIG_CANDIDATE_CLR_PAGE_ADDRESS_MASK 0x1fffffull
#define BEDROCK_MD_MIG_CANDIDATE_CLR_PAGE_ADDRESS_INPLACE (BEDROCK_MD_MIG_CANDIDATE_CLR_PAGE_ADDRESS_MASK << BEDROCK_MD_MIG_CANDIDATE_CLR_PAGE_ADDRESS_SHIFT)

/*
 * Page-migration difference threshold. A valid threshold is reached when the difference between the requester's count and the home count is at least the threshold. The action encodings are not given. Reset unknown.
 */
/* mig_diff_thresh: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MIG_DIFF_THRESH                   0x7c0040 /* established */
#define BEDROCK_MD_MIG_DIFF_THRESH_VALID_SHIFT       63 /* established */
#define BEDROCK_MD_MIG_DIFF_THRESH_VALID_MASK        0x1ull
#define BEDROCK_MD_MIG_DIFF_THRESH_VALID_INPLACE     (BEDROCK_MD_MIG_DIFF_THRESH_VALID_MASK << BEDROCK_MD_MIG_DIFF_THRESH_VALID_SHIFT)
#define BEDROCK_MD_MIG_DIFF_THRESH_SATURATION_ACTION_SHIFT 35 /* established */
#define BEDROCK_MD_MIG_DIFF_THRESH_SATURATION_ACTION_MASK 0x7ull
#define BEDROCK_MD_MIG_DIFF_THRESH_SATURATION_ACTION_INPLACE (BEDROCK_MD_MIG_DIFF_THRESH_SATURATION_ACTION_MASK << BEDROCK_MD_MIG_DIFF_THRESH_SATURATION_ACTION_SHIFT)
#define BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_ACTION_SHIFT 32 /* established */
#define BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_ACTION_MASK 0x7ull
#define BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_ACTION_INPLACE (BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_ACTION_MASK << BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_ACTION_SHIFT)
#define BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_SHIFT   0 /* established */
#define BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_MASK    0x7fffull
#define BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_INPLACE (BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_MASK << BEDROCK_MD_MIG_DIFF_THRESH_THRESHOLD_SHIFT)

/*
 * Page-migration value threshold. Software writes it with bit 63 set and the local interrupt enable and action fields clear. Whether bits 18 to 15 are ignored is unknown. Reset unknown.
 */
/* mig_value_thresh: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MIG_VALUE_THRESH                  0x7c0048 /* established */
#define BEDROCK_MD_MIG_VALUE_THRESH_VALID_SHIFT      63 /* established */
#define BEDROCK_MD_MIG_VALUE_THRESH_VALID_MASK       0x1ull
#define BEDROCK_MD_MIG_VALUE_THRESH_VALID_INPLACE    (BEDROCK_MD_MIG_VALUE_THRESH_VALID_MASK << BEDROCK_MD_MIG_VALUE_THRESH_VALID_SHIFT)
#define BEDROCK_MD_MIG_VALUE_THRESH_LOCAL_INTERRUPT_ENABLE_SHIFT 62 /* established */
#define BEDROCK_MD_MIG_VALUE_THRESH_LOCAL_INTERRUPT_ENABLE_MASK 0x1ull
#define BEDROCK_MD_MIG_VALUE_THRESH_LOCAL_INTERRUPT_ENABLE_INPLACE (BEDROCK_MD_MIG_VALUE_THRESH_LOCAL_INTERRUPT_ENABLE_MASK << BEDROCK_MD_MIG_VALUE_THRESH_LOCAL_INTERRUPT_ENABLE_SHIFT)
#define BEDROCK_MD_MIG_VALUE_THRESH_SATURATION_ACTION_SHIFT 35 /* established */
#define BEDROCK_MD_MIG_VALUE_THRESH_SATURATION_ACTION_MASK 0x7ull
#define BEDROCK_MD_MIG_VALUE_THRESH_SATURATION_ACTION_INPLACE (BEDROCK_MD_MIG_VALUE_THRESH_SATURATION_ACTION_MASK << BEDROCK_MD_MIG_VALUE_THRESH_SATURATION_ACTION_SHIFT)
#define BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_ACTION_SHIFT 32 /* established */
#define BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_ACTION_MASK 0x7ull
#define BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_ACTION_INPLACE (BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_ACTION_MASK << BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_ACTION_SHIFT)
#define BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_SHIFT  0 /* established */
#define BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_MASK   0x7fffull
#define BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_INPLACE (BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_MASK << BEDROCK_MD_MIG_VALUE_THRESH_THRESHOLD_SHIFT)

/*
 * Outgoing request-queue size. Each field defaults to four and has a maximum of four. A header occupies one entry. Writes above four and the side effects of resizing are not specified.
 */
/* outgoing_request_queue_size: rw64, reset 0x4040400; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE       0x7c0050 /* established */
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_THIRD_REQUEST_QUEUE_SHIFT 24 /* established */
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_THIRD_REQUEST_QUEUE_MASK 0x7ull
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_THIRD_REQUEST_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_THIRD_REQUEST_QUEUE_MASK << BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_THIRD_REQUEST_QUEUE_SHIFT)
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI1_REQUEST_QUEUE_SHIFT 16 /* established */
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI1_REQUEST_QUEUE_MASK 0x7ull
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI1_REQUEST_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI1_REQUEST_QUEUE_MASK << BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI1_REQUEST_QUEUE_SHIFT)
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI0_REQUEST_QUEUE_SHIFT 8 /* established */
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI0_REQUEST_QUEUE_MASK 0x7ull
#define BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI0_REQUEST_QUEUE_INPLACE (BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI0_REQUEST_QUEUE_MASK << BEDROCK_MD_OUTGOING_REQUEST_QUEUE_SIZE_PI0_REQUEST_QUEUE_SHIFT)

/*
 * Failing directory word captured by the self-test. Guest writes are not established.
 */
/* selftest_dir_error_data: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELFTEST_DIR_ERROR_DATA           0x7c0058 /* established */
#define BEDROCK_MD_SELFTEST_DIR_ERROR_DATA_WORD_SHIFT 0 /* established */
#define BEDROCK_MD_SELFTEST_DIR_ERROR_DATA_WORD_MASK 0xffffffffull
#define BEDROCK_MD_SELFTEST_DIR_ERROR_DATA_WORD_INPLACE (BEDROCK_MD_SELFTEST_DIR_ERROR_DATA_WORD_MASK << BEDROCK_MD_SELFTEST_DIR_ERROR_DATA_WORD_SHIFT)

/*
 * Directory-block debug selector. The meanings of the selections come from a separate design specification that is not held.
 */
/* dir_debug_select: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_DIR_DEBUG_SELECT                  0x7c0060 /* established */
#define BEDROCK_MD_DIR_DEBUG_SELECT_SELECTION_SHIFT  0 /* established */
#define BEDROCK_MD_DIR_DEBUG_SELECT_SELECTION_MASK   0x3ull
#define BEDROCK_MD_DIR_DEBUG_SELECT_SELECTION_INPLACE (BEDROCK_MD_DIR_DEBUG_SELECT_SELECTION_MASK << BEDROCK_MD_DIR_DEBUG_SELECT_SELECTION_SHIFT)

/*
 * Memory-block ECC configuration. Bit 0 ignores data ECC. Reset unknown.
 */
/* mb_ecc_config: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MB_ECC_CONFIG                     0x7e0000 /* established */
#define BEDROCK_MD_MB_ECC_CONFIG_IGNORE_DATA_ECC_SHIFT 0 /* established */
#define BEDROCK_MD_MB_ECC_CONFIG_IGNORE_DATA_ECC_MASK 0x1ull
#define BEDROCK_MD_MB_ECC_CONFIG_IGNORE_DATA_ECC_INPLACE (BEDROCK_MD_MB_ECC_CONFIG_IGNORE_DATA_ECC_MASK << BEDROCK_MD_MB_ECC_CONFIG_IGNORE_DATA_ECC_SHIFT)

/*
 * Memory error record: an address, a syndrome and a valid and overrun flag pair for each of three kinds. The address and syndrome belong to the earliest error of the highest priority: uncorrectable read above uncorrectable write above correctable read. Bit 63 is set when uncorrectable errors reached different cache lines. The header's flag summary gives the order of each pair's bits only in one place, so the pair order is inferred. Reset unknown.
 */
/* mem_error: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MEM_ERROR                         0x7e0010 /* established */
#define BEDROCK_MD_MEM_ERROR_DIFFERING_ADDRESS_SHIFT 63 /* established */
#define BEDROCK_MD_MEM_ERROR_DIFFERING_ADDRESS_MASK  0x1ull
#define BEDROCK_MD_MEM_ERROR_DIFFERING_ADDRESS_INPLACE (BEDROCK_MD_MEM_ERROR_DIFFERING_ADDRESS_MASK << BEDROCK_MD_MEM_ERROR_DIFFERING_ADDRESS_SHIFT)
#define BEDROCK_MD_MEM_ERROR_READ_UNCORRECTABLE_FLAGS_SHIFT 60 /* inferred */
#define BEDROCK_MD_MEM_ERROR_READ_UNCORRECTABLE_FLAGS_MASK 0x3ull
#define BEDROCK_MD_MEM_ERROR_READ_UNCORRECTABLE_FLAGS_INPLACE (BEDROCK_MD_MEM_ERROR_READ_UNCORRECTABLE_FLAGS_MASK << BEDROCK_MD_MEM_ERROR_READ_UNCORRECTABLE_FLAGS_SHIFT)
#define BEDROCK_MD_MEM_ERROR_WRITE_UNCORRECTABLE_FLAGS_SHIFT 56 /* inferred */
#define BEDROCK_MD_MEM_ERROR_WRITE_UNCORRECTABLE_FLAGS_MASK 0x3ull
#define BEDROCK_MD_MEM_ERROR_WRITE_UNCORRECTABLE_FLAGS_INPLACE (BEDROCK_MD_MEM_ERROR_WRITE_UNCORRECTABLE_FLAGS_MASK << BEDROCK_MD_MEM_ERROR_WRITE_UNCORRECTABLE_FLAGS_SHIFT)
#define BEDROCK_MD_MEM_ERROR_READ_CORRECTABLE_FLAGS_SHIFT 52 /* inferred */
#define BEDROCK_MD_MEM_ERROR_READ_CORRECTABLE_FLAGS_MASK 0x3ull
#define BEDROCK_MD_MEM_ERROR_READ_CORRECTABLE_FLAGS_INPLACE (BEDROCK_MD_MEM_ERROR_READ_CORRECTABLE_FLAGS_MASK << BEDROCK_MD_MEM_ERROR_READ_CORRECTABLE_FLAGS_SHIFT)
#define BEDROCK_MD_MEM_ERROR_SYNDROME_SHIFT          40 /* established */
#define BEDROCK_MD_MEM_ERROR_SYNDROME_MASK           0xffull
#define BEDROCK_MD_MEM_ERROR_SYNDROME_INPLACE        (BEDROCK_MD_MEM_ERROR_SYNDROME_MASK << BEDROCK_MD_MEM_ERROR_SYNDROME_SHIFT)
#define BEDROCK_MD_MEM_ERROR_ADDRESS_SHIFT           3 /* established */
#define BEDROCK_MD_MEM_ERROR_ADDRESS_MASK            0x3fffffffull
#define BEDROCK_MD_MEM_ERROR_ADDRESS_INPLACE         (BEDROCK_MD_MEM_ERROR_ADDRESS_MASK << BEDROCK_MD_MEM_ERROR_ADDRESS_SHIFT)

/*
 * Clear alias of the memory error record. The header repeats the base register's text and names no mechanism. Read-to-clear is the consumer's expectation, not a stated rule.
 */
/* mem_error_clr: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MEM_ERROR_CLR                     0x7e0018 /* established */

/*
 * Self-test captured memory data, quarter 0 of the failing line.
 */
/* selftest_mem_error_data0: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA0          0x7e0020 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA0_WORD_SHIFT 0 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA0_WORD_MASK 0xfffffffffull
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA0_WORD_INPLACE (BEDROCK_MD_SELFTEST_MEM_ERROR_DATA0_WORD_MASK << BEDROCK_MD_SELFTEST_MEM_ERROR_DATA0_WORD_SHIFT)

/*
 * Self-test captured memory data, quarter 1 of the failing line.
 */
/* selftest_mem_error_data1: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA1          0x7e0028 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA1_WORD_SHIFT 0 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA1_WORD_MASK 0xfffffffffull
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA1_WORD_INPLACE (BEDROCK_MD_SELFTEST_MEM_ERROR_DATA1_WORD_MASK << BEDROCK_MD_SELFTEST_MEM_ERROR_DATA1_WORD_SHIFT)

/*
 * Self-test captured memory data, quarter 2 of the failing line.
 */
/* selftest_mem_error_data2: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA2          0x7e0030 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA2_WORD_SHIFT 0 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA2_WORD_MASK 0xfffffffffull
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA2_WORD_INPLACE (BEDROCK_MD_SELFTEST_MEM_ERROR_DATA2_WORD_MASK << BEDROCK_MD_SELFTEST_MEM_ERROR_DATA2_WORD_SHIFT)

/*
 * Self-test captured memory data, quarter 3 of the failing line.
 */
/* selftest_mem_error_data3: r64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA3          0x7e0038 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA3_WORD_SHIFT 0 /* established */
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA3_WORD_MASK 0xfffffffffull
#define BEDROCK_MD_SELFTEST_MEM_ERROR_DATA3_WORD_INPLACE (BEDROCK_MD_SELFTEST_MEM_ERROR_DATA3_WORD_MASK << BEDROCK_MD_SELFTEST_MEM_ERROR_DATA3_WORD_SHIFT)

/*
 * Memory-block debug selector. The meaning of the selection requires the separate design specification.
 */
/* mem_debug_select: rw64, reset unknown; Linux 2.5.40 SN1 memory-directory register header */
#define BEDROCK_MD_MEM_DEBUG_SELECT                  0x7e0040 /* established */
#define BEDROCK_MD_MEM_DEBUG_SELECT_SELECTION_SHIFT  0 /* established */
#define BEDROCK_MD_MEM_DEBUG_SELECT_SELECTION_MASK   0x1ull
#define BEDROCK_MD_MEM_DEBUG_SELECT_SELECTION_INPLACE (BEDROCK_MD_MEM_DEBUG_SELECT_SELECTION_MASK << BEDROCK_MD_MEM_DEBUG_SELECT_SELECTION_SHIFT)

/*
 * Directory word in the pointer format. Bits 1:0 hold the format, which is the same in both flavors. In a premium word bits 24:22 extend the pointer to ten bits.
 */
/* word DIR_ENTRY_POINTER: 64 bits; Linux 2.5.40 SN1 memory-directory header, directory word layout */
#define BEDROCK_MD_DIR_ENTRY_POINTER_WIDTH           64 /* established */
#define BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_HIGH_SHIFT 22 /* established */
#define BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_HIGH_MASK 0x7ull
#define BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_HIGH_INPLACE (BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_HIGH_MASK << BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_HIGH_SHIFT)
#define BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_SHIFT 8 /* established */
#define BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_MASK 0xffull
#define BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_INPLACE (BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_MASK << BEDROCK_MD_DIR_ENTRY_POINTER_FIRST_POINTER_SHIFT)
#define BEDROCK_MD_DIR_ENTRY_POINTER_STATE_SHIFT     2 /* established */
#define BEDROCK_MD_DIR_ENTRY_POINTER_STATE_MASK      0x7ull
#define BEDROCK_MD_DIR_ENTRY_POINTER_STATE_INPLACE   (BEDROCK_MD_DIR_ENTRY_POINTER_STATE_MASK << BEDROCK_MD_DIR_ENTRY_POINTER_STATE_SHIFT)
#define BEDROCK_MD_DIR_ENTRY_POINTER_FORMAT_SHIFT    0 /* established */
#define BEDROCK_MD_DIR_ENTRY_POINTER_FORMAT_MASK     0x3ull
#define BEDROCK_MD_DIR_ENTRY_POINTER_FORMAT_INPLACE  (BEDROCK_MD_DIR_ENTRY_POINTER_FORMAT_MASK << BEDROCK_MD_DIR_ENTRY_POINTER_FORMAT_SHIFT)

/*
 * Directory word in the shared-fine format. In this format a vector bit stands for one processor interface, not one processor.
 */
/* word DIR_ENTRY_SHARED_FINE: 64 bits; Linux 2.5.40 SN1 memory-directory header, directory word layout */
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_WIDTH       64 /* established */
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_HIGH_SHIFT 24 /* established */
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_HIGH_MASK 0xffull
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_HIGH_INPLACE (BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_HIGH_MASK << BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_HIGH_SHIFT)
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_HIGH_SHIFT 22 /* established */
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_HIGH_MASK 0x3ull
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_HIGH_INPLACE (BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_HIGH_MASK << BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_HIGH_SHIFT)
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_SHIFT 8 /* established */
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_MASK 0xffull
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_INPLACE (BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_MASK << BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_VECTOR_SHIFT)
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_SHIFT 2 /* established */
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_MASK 0x7ull
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_INPLACE (BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_MASK << BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FIRST_TAG_SHIFT)
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FORMAT_SHIFT 0 /* established */
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FORMAT_MASK 0x3ull
#define BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FORMAT_INPLACE (BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FORMAT_MASK << BEDROCK_MD_DIR_ENTRY_SHARED_FINE_FORMAT_SHIFT)

#define BEDROCK_MD_DIMM_POSITIONS                    0x4u /* established */
#define BEDROCK_MD_DIR_BACKDOOR_EIGHTHS              0x7u /* established */
#define BEDROCK_MD_DIR_LINE_BYTES                    0x80u /* established */
#define BEDROCK_MD_DIR_WORD_STRIDE                   0x10u /* established */
#define BEDROCK_MD_ECC_BACKDOOR_EIGHTHS              0x5u /* established */
#define BEDROCK_MD_INTR_CORRECTABLE_MEM_BIT          0x3du /* established */
#define BEDROCK_MD_INTR_UNCORRECTABLE_MEM_BIT        0x18u /* established */
#define BEDROCK_MD_PAGE_COUNTER_OFFSET               0x8u /* established */
#define BEDROCK_MD_PHYSICAL_BANKS_PER_DIMM           0x2u /* established */
#define BEDROCK_MD_PROTECTION_ENTRY_OFFSET           0x408u /* established */
#define BEDROCK_MD_PTR_DEVICE_MASK                   0x7u /* established */
#define BEDROCK_MD_PTR_NODE_SHIFT                    0x3u /* established */
#define BEDROCK_MD_REFRESH_CYCLES_PER_4096           0xc35u /* established */
#define BEDROCK_MD_REFRESH_INTERVAL_BOOK_NS          0x1f40u /* established */
#define BEDROCK_MD_SCRUB_BACKDOOR_EIGHTHS            0x4u /* established */
#define BEDROCK_MD_SOFTWARE_BANKS                    0x8u /* established */
#define BEDROCK_MD_SOFTWARE_BANK_BYTES               0x40000000u /* established */

#endif /* BEDROCK_MD_GEN_H */
