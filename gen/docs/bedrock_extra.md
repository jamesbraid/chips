# Hub and Bedrock network-controller registers outside the census

<!-- generated from defs/bedrock_extra.toml by defs-gen - do not edit, change the source -->

Unit `bedrock_extra`, macro prefix `BEDROCK`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `ii_widget_status` | 0x400008 | r | 64 |  |  | unknown | established |  |
| `ii_shutdown_status` | 0x4001e8 | r | 64 |  |  | unknown | established |  |
| `ii_error_header_1` | 0x400220 | r | 64 |  |  | unknown | established |  |
| `ii_error_header_2` | 0x400228 | r | 64 |  |  | unknown | established |  |
| `node_region_mask` | 0x1000018 | r | 64 |  |  | unknown | established |  |
| `mem_bank_config` | 0x1f80008 | rw | 64 |  |  | unknown | established |  |

### Register `ii_widget_status`

### Register `ii_shutdown_status`

### Register `ii_error_header_1`

### Register `ii_error_header_2`

### Register `node_region_mask`

### Register `mem_bank_config`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `II_CREDIT_TIMEOUT` | 0x4001e0 | established |  | Bedrock layout, [I] Hub: bits 25:0 count 128-clock ticks while outbound credits are below 1 (direct) or 2 (crossbar), saturate, raise one interrupt; no consumer in anything held |
| `II_ERROR_HEADER_1_COMMAND` | 0x7f | established |  | bits 6:0 |
| `II_ERROR_HEADER_1_ERR_TYPE` | 0xf00000000 | established |  | bits 35:32; 2 short request packet, 3 short reply packet, 4 long request packet, 5 long reply packet, any other value prints as unknown (each value selects its own text in the print routine) |
| `II_ERROR_HEADER_1_OVERRUN` | 0x10000000000 | established |  | bit 40 |
| `II_ERROR_HEADER_1_PRINT_GATE` | 0x100000000000 | established |  | bit 44 gates the print; [I] header valid |
| `II_ERROR_HEADER_1_SOURCE` | 0x7ff00000 | established |  | bits 30:20 |
| `II_ERROR_HEADER_1_SUPPLEMENTAL` | 0x7ff00 | established |  | bits 18:8 |
| `II_ERROR_HEADER_2_ADDRESS` | 0x3fffffffff | established |  | bits 37:0 |
| `II_ERROR_HEADER_2_TAIL` | 0x10000000000 | established |  | bit 40 |
| `II_READ_RESP_PRESCALE_B_54_32` | 0x7fffff00000000 | established |  | Bedrock layout: read-response prescaler, bits 54:32; unit [U] |
| `II_READ_RESP_TIMEOUT_B_59_55` | 0xf80000000000000 | established |  | Bedrock layout: read-response timeout, bits 59:55; unit [U] |
| `II_TAIL_TIMEOUT` | 0x4001f0 | established |  | Bedrock layout, [I] Hub: bits 25:0 tail timeout; the same offset holds the read-response fields below |
| `II_WIDGET_STATUS_CREDIT_TIMEOUT` | 0x10 | established |  | bit 4, reason when bit 32 is set |
| `II_WIDGET_STATUS_ERROR` | 0x100000000 | established |  | bit 32, the "crazy" error flag; name [I] |
| `II_WIDGET_STATUS_RETRY_TIMEOUT` | 0x200 | established |  | bit 9, reason when bit 32 is set |
| `II_WIDGET_STATUS_TAIL_TIMEOUT` | 0x20 | established |  | bit 5, reason when bit 32 is set |
| `MEM_BANK_CONFIG_BANK_SELECT` | 0x300000000 | established |  | bits 33:32; the PROM clears these and ORs in a selector shifted left 32 (not masked to two bits by that routine) |
| `MEM_BANK_CONFIG_B_58_56` | 0x700000000000000 | established |  | the same write ORs in 7 here; meaning [U]: settle by a published Bedrock register list (none held) or the same routine's callers' use of the result |
| `MEM_BANK_CONFIG_LANE_ENABLE` | 0x3 | established |  | per lane, bits 1:0 enable the lane's two banks, one bit each; bits 3:2 are not read by the decode routine [U] |
| `MEM_BANK_CONFIG_LANE_SIZE` | 0xf0 | established |  | per lane, bits 7:4: one size code shared by both banks of the lane |
| `NIC_ACCESS_HUB_PHYS_LOW` | 0x1e04030 | established | shipped IRIX kernel binaries, per kudzu docs/nic.md | Physical address of the one-wire access register (nic_access_hub) for node 0. |
| `NODE_SHIFT` | 0x21 | established | shipped IRIX kernel binaries, per kudzu docs/ip35-hub-errors.md | Physical node number shift of the Origin 300/350 hub, as the kernel's memory-directory, I/O and one-wire code all apply it. |
| `PI_ERROR_SPOOL_SIZE_BASE` | 0x1000 | established |  | bytes for a value of 1 |
