/* generated from devices/uv_bau/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 2daabcb00ca4cf0ccb9e7ae19034116a669196719e08dfd2559a070a278bfaa3 */
/* UV broadcast assist unit (BAU): descriptor, payload queue and constants */
#ifndef UV_BAU_GEN_H
#define UV_BAU_GEN_H

#include <stdint.h>


/*
 * High dword of the UV2 and UV3 message header, bit positions counted from the dword (header bit minus 64).
 */
/* word DESC_HDR_HI: 64 bits; Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) */
#define UV_BAU_DESC_HDR_HI_WIDTH                     64 /* established */
#define UV_BAU_DESC_HDR_HI_COMMAND_SHIFT             56 /* established */
#define UV_BAU_DESC_HDR_HI_COMMAND_MASK              0xffull
#define UV_BAU_DESC_HDR_HI_COMMAND_INPLACE           (UV_BAU_DESC_HDR_HI_COMMAND_MASK << UV_BAU_DESC_HDR_HI_COMMAND_SHIFT)
#define UV_BAU_DESC_HDR_HI_MULTILEVEL_SHIFT          31 /* established */
#define UV_BAU_DESC_HDR_HI_MULTILEVEL_MASK           0x1ull
#define UV_BAU_DESC_HDR_HI_MULTILEVEL_INPLACE        (UV_BAU_DESC_HDR_HI_MULTILEVEL_MASK << UV_BAU_DESC_HDR_HI_MULTILEVEL_SHIFT)
#define UV_BAU_DESC_HDR_HI_CHAINING_SHIFT            30 /* established */
#define UV_BAU_DESC_HDR_HI_CHAINING_MASK             0x1ull
#define UV_BAU_DESC_HDR_HI_CHAINING_INPLACE          (UV_BAU_DESC_HDR_HI_CHAINING_MASK << UV_BAU_DESC_HDR_HI_CHAINING_SHIFT)
#define UV_BAU_DESC_HDR_HI_SEQUENCE_SHIFT            14 /* established */
#define UV_BAU_DESC_HDR_HI_SEQUENCE_MASK             0xffffull
#define UV_BAU_DESC_HDR_HI_SEQUENCE_INPLACE          (UV_BAU_DESC_HDR_HI_SEQUENCE_MASK << UV_BAU_DESC_HDR_HI_SEQUENCE_SHIFT)
#define UV_BAU_DESC_HDR_HI_FAIRNESS_SHIFT            11 /* established */
#define UV_BAU_DESC_HDR_HI_FAIRNESS_MASK             0x7ull
#define UV_BAU_DESC_HDR_HI_FAIRNESS_INPLACE          (UV_BAU_DESC_HDR_HI_FAIRNESS_MASK << UV_BAU_DESC_HDR_HI_FAIRNESS_SHIFT)

/*
 * Low dword of the UV2 and UV3 message header (descriptor bytes 0x30 to 0x37, the message header at the top of the 64-byte descriptor). Only fields the driver sets or reads are listed; the rest are reserved or payload.
 */
/* word DESC_HDR_LO: 64 bits; Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) */
#define UV_BAU_DESC_HDR_LO_WIDTH                     64 /* established */
#define UV_BAU_DESC_HDR_LO_SWACK_FLAG_SHIFT          52 /* established */
#define UV_BAU_DESC_HDR_LO_SWACK_FLAG_MASK           0x1ull
#define UV_BAU_DESC_HDR_LO_SWACK_FLAG_INPLACE        (UV_BAU_DESC_HDR_LO_SWACK_FLAG_MASK << UV_BAU_DESC_HDR_LO_SWACK_FLAG_SHIFT)
#define UV_BAU_DESC_HDR_LO_CANCELED_SHIFT            25 /* established */
#define UV_BAU_DESC_HDR_LO_CANCELED_MASK             0x1ull
#define UV_BAU_DESC_HDR_LO_CANCELED_INPLACE          (UV_BAU_DESC_HDR_LO_CANCELED_MASK << UV_BAU_DESC_HDR_LO_CANCELED_SHIFT)
#define UV_BAU_DESC_HDR_LO_MSG_TYPE_SHIFT            22 /* established */
#define UV_BAU_DESC_HDR_LO_MSG_TYPE_MASK             0x7ull
#define UV_BAU_DESC_HDR_LO_MSG_TYPE_INPLACE          (UV_BAU_DESC_HDR_LO_MSG_TYPE_MASK << UV_BAU_DESC_HDR_LO_MSG_TYPE_SHIFT)
#define UV_BAU_DESC_HDR_LO_REPLIED_TO_SHIFT          21 /* established */
#define UV_BAU_DESC_HDR_LO_REPLIED_TO_MASK           0x1ull
#define UV_BAU_DESC_HDR_LO_REPLIED_TO_INPLACE        (UV_BAU_DESC_HDR_LO_REPLIED_TO_MASK << UV_BAU_DESC_HDR_LO_REPLIED_TO_SHIFT)
#define UV_BAU_DESC_HDR_LO_DEST_SUBNODEID_SHIFT      15 /* established */
#define UV_BAU_DESC_HDR_LO_DEST_SUBNODEID_MASK       0x1full
#define UV_BAU_DESC_HDR_LO_DEST_SUBNODEID_INPLACE    (UV_BAU_DESC_HDR_LO_DEST_SUBNODEID_MASK << UV_BAU_DESC_HDR_LO_DEST_SUBNODEID_SHIFT)
#define UV_BAU_DESC_HDR_LO_BASE_DEST_NASID_SHIFT     0 /* established */
#define UV_BAU_DESC_HDR_LO_BASE_DEST_NASID_MASK      0x7fffull
#define UV_BAU_DESC_HDR_LO_BASE_DEST_NASID_INPLACE   (UV_BAU_DESC_HDR_LO_BASE_DEST_NASID_MASK << UV_BAU_DESC_HDR_LO_BASE_DEST_NASID_SHIFT)

#define UV_BAU_DESC_BYTES                            0x40u /* established */
#define UV_BAU_DESC_QUALIFIER                        0x534749u /* established */
#define UV_BAU_DISTRIBUTION_BITS                     0x100u /* established */
#define UV_BAU_DS_ACTIVE                             0x1u /* established */
#define UV_BAU_DS_DESTINATION_TIMEOUT                0x2u /* established */
#define UV_BAU_DS_IDLE                               0x0u /* established */
#define UV_BAU_DS_SOURCE_TIMEOUT                     0x3u /* established */
#define UV_BAU_ITEMS_PER_SET                         0x8u /* established */
#define UV_BAU_LB_SUBNODEID                          0x10u /* established */
#define UV_BAU_MSG_NOOP                              0x0u /* established */
#define UV_BAU_MSG_REGULAR                           0x1u /* established */
#define UV_BAU_MSG_RETRY                             0x2u /* established */
#define UV_BAU_NUM_SETS                              0x40u /* established */
#define UV_BAU_PAYLOADQ_GNODE_SHIFT                  0x31u /* established */
#define UV_BAU_PAYLOAD_QUEUE_ENTRIES                 0x14u /* established */
#define UV_BAU_PAYLOAD_QUEUE_ENTRY_BYTES             0x20u /* established */
#define UV_BAU_SW_ACK_RESOURCES                      0x8u /* established */
#define UV_BAU_UV1_ENDPOINT_COMMAND                  0x38u /* established */
#define UV_BAU_UV1_SOFT_ACK_PERIOD                   0x9u /* established */
#define UV_BAU_UV2_DESC_BUSY                         0x2u /* established */
#define UV_BAU_UV2_DESC_DEST_PUT_ERR                 0x7u /* established */
#define UV_BAU_UV2_DESC_DEST_STRONG_NACK             0x5u /* established */
#define UV_BAU_UV2_DESC_DEST_TIMEOUT                 0x4u /* established */
#define UV_BAU_UV2_DESC_IDLE                         0x0u /* established */
#define UV_BAU_UV2_DESC_SOURCE_TIMEOUT               0x6u /* established */
#define UV_BAU_UV2_ENDPOINT_COMMAND                  0x28u /* established */
#define UV_BAU_UV2_SOFT_ACK_PERIOD                   0xfu /* established */

#endif /* UV_BAU_GEN_H */
