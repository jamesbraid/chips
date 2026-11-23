<!-- generated from devices/pic/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 3d439cd5a9c6040f4c489f3ad4fdb170d8de283af94a577d7c9668ef96e26cc9 -->

# PIC (dual-head PCI-X bridge), Origin 3000 family

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout.

Unit `pic`, macro prefix `PIC`.
Default source: census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pcibr_bridge_ptr` | 0x0 | r | 64 |  |  | unknown | established | census: 5 sites, 3 routines |
| `bus_err` | 0x18 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ssram_size` | 0x20 | rw | 64 |  |  | unknown | established | census: 20 sites, 6 routines |
| `req_timeout` | 0x28 | rw | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `intr_dst_target_id` | 0x38 | rw | 64 |  |  | unknown | established | census: 16 sites, 6 routines |
| `cmdword_err` | 0x40 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `llp_cfg` | 0x48 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `tflush` | 0x50 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `linkside_err` | 0x58 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `resp_err_buf` | 0x60 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `resp_err` | 0x68 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `linkside_err_addr` | 0x78 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `dirmap_wid` | 0x80 | rw | 64 |  |  | unknown | established | census: 14 sites, 6 routines |
| `ssram_parity` | 0x90 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `arbitration` | 0xa0 | rw | 64 |  |  | unknown | established | census: 6 sites, 4 routines |
| `parity_err` | 0xb0 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `timeout` | 0xc0 | rw | 64 |  |  | unknown | established | census: 6 sites, 4 routines |
| `type1_cntr` | 0xc8 | rw | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pci_bus_addr` | 0xd8 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `intr_status` | 0x100 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_enable` | 0x108 | rw | 64 |  |  | unknown | established | census: 7 sites, 5 routines |
| `intr_reset` | 0x110 | rw | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `intr_mode` | 0x118 | rw | 64 |  |  | unknown | established | census: 6 sites, 4 routines |
| `intr_device` | 0x120 | rw | 64 |  |  | unknown | established | census: 6 sites, 4 routines |
| `intr_host_err` | 0x128 | rw | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `intr_addr_vect` | 0x130 | rw | 64 |  |  | unknown | established | census: 12 sites, 6 routines |
| `intr_view` | 0x170 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_multiple` | 0x178 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `force_always` | 0x180 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `force_intr` | 0x1c0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `device` | 0x200 | rw | 64 |  |  | unknown | established | census: 6 sites, 4 routines |
| `wrb_flush` | 0x240 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `rrb` | 0x280 | rw | 64 |  |  | unknown | established | census: 6 sites, 4 routines |
| `rrb_status` | 0x290 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `rrb_clear` | 0x298 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pcix_bus_err_addr` | 0x600 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pcix_bus_err_attr` | 0x608 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pcix_bus_err_data` | 0x610 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pcix_pio_split_addr` | 0x618 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pcix_pio_split_attr` | 0x620 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pcix_req_err_attr` | 0x628 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `pcix_req_err_addr` | 0x630 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `int_ate` | 0x10000 | rw | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pic_attach2` | 0x18000 | w | 64 |  |  | unknown | established | census: 4 sites, 1 routines |
| `pic_attach2_18800` | 0x18800 | w | 64 |  |  | unknown | established | census: 4 sites, 1 routines |
| `pic_attach2_19000` | 0x19000 | w | 64 |  |  | unknown | established | census: 4 sites, 1 routines |
| `ext_ate` | 0x80000 | rw | 64 |  |  | unknown | established | census: 4 sites, 2 routines |

### Register `pcibr_bridge_ptr`

### Register `bus_err`

### Register `ssram_size`

### Register `req_timeout`

### Register `intr_dst_target_id`

### Register `cmdword_err`

### Register `llp_cfg`

### Register `tflush`

### Register `linkside_err`

### Register `resp_err_buf`

### Register `resp_err`

### Register `linkside_err_addr`

### Register `dirmap_wid`

### Register `ssram_parity`

### Register `arbitration`

### Register `parity_err`

### Register `timeout`

### Register `type1_cntr`

### Register `pci_bus_addr`

### Register `intr_status`

### Register `intr_enable`

### Register `intr_reset`

### Register `intr_mode`

### Register `intr_device`

### Register `intr_host_err`

### Register `intr_addr_vect`

### Register `intr_view`

### Register `intr_multiple`

### Register `force_always`

### Register `force_intr`

### Register `device`

### Register `wrb_flush`

### Register `rrb`

### Register `rrb_status`

### Register `rrb_clear`

### Register `pcix_bus_err_addr`

### Register `pcix_bus_err_attr`

### Register `pcix_bus_err_data`

### Register `pcix_pio_split_addr`

### Register `pcix_pio_split_attr`

### Register `pcix_req_err_attr`

### Register `pcix_req_err_addr`

### Register `int_ate`

### Register `pic_attach2`

### Register `pic_attach2_18800`

### Register `pic_attach2_19000`

### Register `ext_ate`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `INTR_ADDR_VECT_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `INTR_ADDR_VECT_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `INTR_DST_TARGET_ID_V_A5A5` | 0xa5a5 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `INTR_DST_TARGET_ID_V_A5A50000` | 0xa5a50000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `INT_ATE_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `LINKSIDE_ERR_ADDR_V_BEEF` | 0xbeef | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `PCIBR_BRIDGE_PTR_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `PCIBR_BRIDGE_PTR_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `RRB_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SSRAM_SIZE_B_5_4` | 0x30 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
