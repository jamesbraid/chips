# IOC3 registers outside the census

<!-- generated from defs/ioc3_extra.toml by defs-gen - do not edit, change the source -->

Unit `ioc3_extra`, macro prefix `IOC3`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `one_wire_ctl` | 0x30 | rw | 32 |  |  | unknown | established |  |
| `plp_a_addr_hi` | 0x80 | rw | 32 |  |  | unknown | established |  |
| `plp_a_addr_lo` | 0x84 | rw | 32 |  |  | unknown | established |  |
| `plp_a_count` | 0x88 | rw | 32 |  |  | unknown | established |  |
| `plp_ctl` | 0x8c | rw | 32 |  |  | unknown | established |  |
| `plp_b_addr_hi` | 0x90 | rw | 32 |  |  | unknown | established |  |
| `plp_b_addr_lo` | 0x94 | rw | 32 |  |  | unknown | established |  |
| `plp_b_count` | 0x98 | rw | 32 |  |  | unknown | established |  |
| `km_rx_kbd` | 0xa0 | r | 32 |  |  | unknown | established |  |
| `km_rx_mouse` | 0xa4 | r | 32 |  |  | unknown | established |  |
| `km_tx_kbd` | 0xa8 | w | 32 |  |  | unknown | established |  |
| `km_tx_mouse` | 0xac | w | 32 |  |  | unknown | established |  |

### Register `one_wire_ctl`

### Register `plp_a_addr_hi`

### Register `plp_a_addr_lo`

### Register `plp_a_count`

### Register `plp_ctl`

### Register `plp_b_addr_hi`

### Register `plp_b_addr_lo`

### Register `plp_b_count`

### Register `km_rx_kbd`

### Register `km_rx_mouse`

### Register `km_tx_kbd`

### Register `km_tx_mouse`
