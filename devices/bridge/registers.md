<!-- generated from devices/bridge/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 5c857fc18475a73158d341e50faa7869fa17c1d787b05a3b26772bf0b11b8e3b -->

# Bridge (XIO-to-PCI bridge), Origin 2000 and Octane

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout. Views: the offset is the 8-byte slot address. "4 at slot+4" is a 32-bit load or store at that address plus 4, the low word of the slot on a big-endian machine; a 64-bit access to the slot address reaches the same register.

Unit `bridge`, macro prefix `BRIDGE`.
Default source: census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `wid_id` | 0x0 | r | 32 |  |  | unknown | established | census: 15 sites, 3 routines |
| `wid_stat` | 0x8 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `wid_err_upper` | 0x10 | r | 32 |  |  | unknown | established | census: 7 sites, 3 routines |
| `wid_err_lower` | 0x18 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `wid_control` | 0x20 | rw | 32 |  |  | unknown | established | census: 87 sites, 5 routines |
| `wid_req_timeout` | 0x28 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `wid_int_upper` | 0x30 | rw | 32 |  |  | unknown | established | census: 39 sites, 7 routines |
| `wid_int_lower` | 0x38 | rw | 32 |  |  | unknown | established | census: 15 sites, 5 routines |
| `wid_err_cmdword` | 0x40 | r | 32 |  |  | unknown | established | census: 5 sites, 3 routines |
| `wid_llp` | 0x48 | rw | 32 |  |  | unknown | established | census: 15 sites, 2 routines |
| `wid_tflush` | 0x50 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `wid_aux_err` | 0x58 | r | 32 |  |  | unknown | established | census: 5 sites, 3 routines |
| `wid_resp_upper` | 0x60 | r | 32 |  |  | unknown | established | census: 14 sites, 6 routines |
| `wid_resp_lower` | 0x68 | r | 32 |  |  | unknown | established | census: 8 sites, 4 routines |
| `dir_map` | 0x80 | rw | 32 |  |  | unknown | established | census: 42 sites, 6 routines |
| `ram_perr_or_map_fault` | 0x90 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `arb` | 0xa0 | rw | 32 |  |  | unknown | established | census: 18 sites, 4 routines |
| `bus_timeout` | 0xc0 | rw | 32 |  |  | unknown | established | census: 18 sites, 4 routines |
| `pci_cfg` | 0xc8 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `pci_err_upper` | 0xd0 | r | 32 |  |  | unknown | established | census: 8 sites, 4 routines |
| `pci_err_lower` | 0xd8 | r | 32 |  |  | unknown | established | census: 8 sites, 4 routines |
| `int_status` | 0x100 | r | 32 |  |  | unknown | established | census: 15 sites, 13 routines |
| `int_enable` | 0x108 | rw | 32 |  |  | unknown | established | census: 18 sites, 4 routines |
| `int_rst_stat` | 0x110 | rw | 32 |  |  | unknown | established | census: 9 sites, 2 routines |
| `int_mode` | 0x118 | rw | 32 |  |  | unknown | established | census: 18 sites, 4 routines |
| `int_device` | 0x120 | rw | 32 |  |  | unknown | established | census: 18 sites, 4 routines |
| `int_host_err` | 0x128 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `int_addr` | 0x130 | rw | 32 |  |  | unknown | established | census: 36 sites, 6 routines |
| `device` | 0x200 | rw | 32 |  |  | unknown | established | census: 18 sites, 4 routines |
| `wr_req_buf` | 0x240 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `rrb_map` | 0x280 | rw | 32 |  |  | unknown | established | census: 30 sites, 4 routines |
| `resp_status` | 0x290 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `resp_clear` | 0x298 | w | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `int_ate_ram` | 0x10000 | rw | 64 |  |  | unknown | established | census: 6 sites, 2 routines |
| `ext_ate_ram` | 0x80000 | rw | 64 |  |  | unknown | established | census: 24 sites, 2 routines |

### Register `wid_id`

### Register `wid_stat`

### Register `wid_err_upper`

### Register `wid_err_lower`

### Register `wid_control`

### Register `wid_req_timeout`

### Register `wid_int_upper`

### Register `wid_int_lower`

### Register `wid_err_cmdword`

### Register `wid_llp`

### Register `wid_tflush`

### Register `wid_aux_err`

### Register `wid_resp_upper`

### Register `wid_resp_lower`

### Register `dir_map`

### Register `ram_perr_or_map_fault`

### Register `arb`

### Register `bus_timeout`

### Register `pci_cfg`

### Register `pci_err_upper`

### Register `pci_err_lower`

### Register `int_status`

### Register `int_enable`

### Register `int_rst_stat`

### Register `int_mode`

### Register `int_device`

### Register `int_host_err`

### Register `int_addr`

### Register `device`

### Register `wr_req_buf`

### Register `rrb_map`

### Register `resp_status`

### Register `resp_clear`

### Register `int_ate_ram`

### Register `ext_ate_ram`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `INT_ADDR_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
| `INT_ADDR_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
| `INT_STATUS_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
| `INT_STATUS_B_6` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
| `RRB_MAP_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
| `WID_ID_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
| `WID_ID_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
| `WID_INT_UPPER_B_5_0` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the public Linux Bridge register header and the public OpenBSD XBridge register header names by offset, else the shipped accessor name; every name is inferred (config register_names) |  |
