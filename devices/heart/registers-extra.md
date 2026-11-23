<!-- generated from devices/heart/registers-extra.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 189e7fa9ecefa172f0e241d791ba09c972fbdd69db03706a5ac043de76587a1e -->

# HEART registers outside the census

Unit `heart_extra`, macro prefix `HEART`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `sdram_mode` | 0x8 | w | 64 |  |  | unknown | established |  |
| `mem_ref` | 0x10 | w | 64 |  |  | unknown | established |  |
| `mlan_ctl` | 0xb8 | rw | 64 |  |  | unknown | inferred | OpenBSD SGI Crossbow HEART driver at 7011342f6a72: one 64-bit uncached access per pulse, no other user |

### Register `sdram_mode`

### Register `mem_ref`

### Register `mlan_ctl`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `MEMCFG_ADDR_MASK` | 0x1ff | inferred |  | bits 8:0 of a bank configuration word, the base field; OpenBSD HEART_MEMORY_ADDR_MASK |
| `MEMCFG_SIZE_MASK` | 0x3f0000 | inferred |  | bits 21:16 of a bank configuration word, the size field; OpenBSD HEART_MEMORY_SIZE_MASK |
| `MEMCFG_SIZE_SHIFT` | 0x10 | inferred |  | shift of the size field; OpenBSD HEART_MEMORY_SIZE_SHIFT |
| `MEMCFG_UNIT_SHIFT` | 0x19 | inferred |  | a field step is 2^25 bytes, 32 MiB; OpenBSD HEART_MEMORY_UNIT_SHIFT |
| `MEMCFG_VALID` | 0x80000000 | inferred |  | bit 31 of a bank configuration word; OpenBSD HEART_MEMORY_VALID |
| `MLAN_DATA_SHIFT` | 0x2 | inferred |  | data count of a MicroLAN command, shifted to bit 2; OpenBSD SGI HEART one-wire pulse routine |
| `MLAN_DONE` | 0x2 | inferred |  | completion bit the driver polls after a command; OpenBSD SGI HEART one-wire pulse routine |
| `MLAN_PULSE_SHIFT` | 0xa | inferred |  | pulse count of a MicroLAN command, shifted to bit 10; OpenBSD SGI HEART one-wire pulse routine |
| `MLAN_SAMPLE` | 0x1 | inferred |  | sampled wire level the driver returns after completion; OpenBSD SGI HEART one-wire pulse routine |
| `WIDGET_ERR_LOWER` | 0x78 | established |  | failed PIO latch, lower: address 31:0 |
| `WIDGET_ERR_TYPE` | 0x60 | established |  | widget error type; bit names [E] from the monitor table; kernel writes back the value it read, clear rule [I]; bits 0 and 10, 11 meaning [U] |
| `WIDGET_ERR_UPPER` | 0x70 | established |  | failed PIO latch, upper: bits 7:0 address 39:32, 23:22 processor, 15 read/write flag (sense [I]); cleared with the error type [I] |
| `WIDGET_RD_TIMEOUT_LATCH` | 0x90 | established |  | PIO read-timeout latch: bits 19:18 processor, 15:12 widget port, 11:0 address bits 23:12 |
| `WIDGET_REQ_TIMEOUT` | 0x28 | established |  | value 0x28 (40) read from one Octane2 by its owner, the 32-bit value in the low half of the slot; kernel stores of 40000 and 128 reach it through a pointer and the destination is [I]; tick unit [U]: settle by a timed uncached read of an unclaimed widget address at two programmed values (hardware) |
