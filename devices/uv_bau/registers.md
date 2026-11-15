<!-- generated from devices/uv_bau/registers.toml by defs-gen - do not edit, change the source -->

# UV broadcast assist unit (BAU): descriptor, payload queue and constants

The BAU registers are in the per-generation hub units (names containing BAU). This unit holds what the registers point at: the 64-byte activation descriptor and the destination payload queue entry, plus the constants the TLB shootdown driver uses. Positions come from the driver's bitfield structs, packed least-significant first in 32-bit units. Role text paraphrases the driver and is inferred.

Unit `uv_bau`, macro prefix `UV_BAU`.
Default source: Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `DESC_HDR_HI` | 64 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) |
| `DESC_HDR_LO` | 64 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) |

### Word `DESC_HDR_HI`

High dword of the UV2 and UV3 message header, bit positions counted from the dword (header bit minus 64).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `command` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Message type, the endpoint interrupt command. |
| 31 | `multilevel` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Multilevel multicast format; zero for TLB shootdowns. |
| 30 | `chaining` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Next descriptor is part of this activation. |
| 29:14 | `sequence` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Message sequence number. |
| 13:11 | `fairness` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Usually zero. |

### Word `DESC_HDR_LO`

Low dword of the UV2 and UV3 message header (descriptor bytes 0x30 to 0x37, the message header at the top of the 64-byte descriptor). Only fields the driver sets or reads are listed; the rest are reserved or payload.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `swack_flag` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Destination interrupt waits for a software acknowledge. |
| 25 | `canceled` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Message canceled; the resource is to be freed. |
| 24:22 | `msg_type` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Software message type. |
| 21 | `replied_to` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Sent as 0; the destination sets it when it has answered. |
| 19:15 | `dest_subnodeid` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Must be 0x10, the local block. |
| 14:0 | `base_dest_nasid` | established |  | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Nasid of the first destination in the distribution vector. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `DESC_BYTES` | 0x40 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Size of one activation descriptor. |
| `DESC_QUALIFIER` | 0x534749 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV4 payload qualifier the source sets so the destination can verify the origin (ASCII SGI). |
| `DISTRIBUTION_BITS` | 0x100 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Destination bit vector in bytes 0 to 31 of the descriptor: bit n is the node whose number is the base destination nasid plus n times 2 (multi-unicast mode, multilevel flag 0). |
| `DS_ACTIVE` | 0x1 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV1 descriptor status: active. |
| `DS_DESTINATION_TIMEOUT` | 0x2 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV1 descriptor status: destination timeout. |
| `DS_IDLE` | 0x0 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV1 two-bit descriptor status in the activation status registers: idle. |
| `DS_SOURCE_TIMEOUT` | 0x3 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV1 descriptor status: source timeout. |
| `ITEMS_PER_SET` | 0x8 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Descriptors per set; a set is 512 bytes and the driver uses the first of each. |
| `LB_SUBNODEID` | 0x10 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Destination subnode id every descriptor carries: the local block. |
| `MSG_NOOP` | 0x0 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Software message type. |
| `MSG_REGULAR` | 0x1 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Software message type: first transmission. |
| `MSG_RETRY` | 0x2 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Software message type: retransmission. |
| `NUM_SETS` | 0x40 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Descriptor sets, selected by the 6-bit index written to the activation control register. |
| `PAYLOADQ_GNODE_SHIFT` | 0x31 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Position of the home node number in the payload queue first pointer before UV4. |
| `PAYLOAD_QUEUE_ENTRIES` | 0x14 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Entries the driver allots to the destination payload queue. |
| `PAYLOAD_QUEUE_ENTRY_BYTES` | 0x20 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Bytes per queue entry in software acknowledge mode; 17 usable, the software ack vector in byte 15. |
| `SW_ACK_RESOURCES` | 0x8 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Destination software acknowledge resources, one pending and one timeout bit each in the acknowledge register. |
| `UV1_ENDPOINT_COMMAND` | 0x38 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Command code of the endpoint interrupt message on UV1. |
| `UV1_SOFT_ACK_PERIOD` | 0x9 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Soft ack timeout period the driver programs on UV1. |
| `UV2_DESC_BUSY` | 0x2 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV2 descriptor state: busy. |
| `UV2_DESC_DEST_PUT_ERR` | 0x7 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV2 descriptor state: destination side put failed. |
| `UV2_DESC_DEST_STRONG_NACK` | 0x5 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV2 descriptor state: destination rejected the interrupt. |
| `UV2_DESC_DEST_TIMEOUT` | 0x4 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV2 descriptor state: software ack timeout at the destination. |
| `UV2_DESC_IDLE` | 0x0 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV2 and later: status from the three status registers combined as error, busy, aux error: idle. |
| `UV2_DESC_SOURCE_TIMEOUT` | 0x6 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | UV2 descriptor state: source side timeout. |
| `UV2_ENDPOINT_COMMAND` | 0x28 | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Command code of the endpoint interrupt message on UV2 and later. |
| `UV2_SOFT_ACK_PERIOD` | 0xf | established | Linux v5.4 SGI UV broadcast assist unit header and TLB shootdown driver (GPL) | Soft ack timeout period the driver programs on UV2 and UV3. |
