# HEART registers outside the census

<!-- generated from defs/heart_extra.toml by defs-gen - do not edit, change the source -->

Unit `heart_extra`, macro prefix `HEART`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `sdram_mode` | 0x8 | w | 64 |  |  | unknown | established |  |
| `mem_ref` | 0x10 | w | 64 |  |  | unknown | established |  |

### Register `sdram_mode`

### Register `mem_ref`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `WIDGET_ERR_LOWER` | 0x78 | established |  | failed PIO latch, lower: address 31:0 |
| `WIDGET_ERR_TYPE` | 0x60 | established |  | widget error type; bit names [E] from the monitor table; kernel writes back the value it read, clear rule [I]; bits 0 and 10, 11 meaning [U] |
| `WIDGET_ERR_UPPER` | 0x70 | established |  | failed PIO latch, upper: bits 7:0 address 39:32, 23:22 processor, 15 read/write flag (sense [I]); cleared with the error type [I] |
| `WIDGET_RD_TIMEOUT_LATCH` | 0x90 | established |  | PIO read-timeout latch: bits 19:18 processor, 15:12 widget port, 11:0 address bits 23:12 |
| `WIDGET_REQ_TIMEOUT` | 0x28 | established |  | value 0x28 (40) read from one Octane2 by its owner, the 32-bit value in the low half of the slot; kernel stores of 40000 and 128 reach it through a pointer and the destination is [I]; tick unit [U]: settle by a timed uncached read of an unclaimed widget address at two programmed values (hardware) |
