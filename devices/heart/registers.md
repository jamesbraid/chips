<!-- generated from devices/heart/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 ae368d15e21d51d42b2115a87fdc90eb6aebf0433a74724323058784d2a713ad -->

# HEART (Octane system controller)

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout. Views: the offset is the 8-byte slot address. "4 at slot+4" is a 32-bit load or store at that address plus 4, the low word of the slot on a big-endian machine; a 64-bit access to the slot address reaches the same register. Names come from the config register_names (the shipped diagnostic prints them, or the public Linux driver where it prints none); offsets 0x100000 and up are the widget block, see the chip page.

Unit `heart`, macro prefix `HEART`.
Default source: census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `mode` | 0x0 | rw | 64 |  |  | unknown | established | census: 78 sites, 34 routines |
| `mem_arb` | 0x18 | rw | 64 |  |  | unknown | established | census: 12 sites, 4 routines |
| `memcfg0` | 0x20 | rw | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `memcfg1` | 0x28 | rw | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `memcfg2` | 0x30 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `memcfg3` | 0x38 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `fc_mode` | 0x40 | rw | 64 |  |  | unknown | established | census: 17 sites, 9 routines |
| `fc_limit` | 0x48 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `fc0_addr` | 0x50 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `fc0_count` | 0x60 | rw | 64 |  |  | unknown | established | census: 5 sites, 5 routines |
| `status` | 0x80 | r | 64 |  |  | unknown | established | census: 48 sites, 40 routines |
| `berr_addr` | 0x88 | r | 64 |  |  | unknown | established | census: 9 sites, 7 routines |
| `berr_misc` | 0x90 | r | 64 |  |  | unknown | established | census: 10 sites, 8 routines |
| `mem_err` | 0x98 | r | 64 |  |  | unknown | established | census: 14 sites, 12 routines |
| `bad_mem` | 0xa0 | r | 64 |  |  | unknown | established | census: 12 sites, 10 routines |
| `piu_err` | 0xa8 | r | 64 |  |  | unknown | established | census: 9 sites, 7 routines |
| `imr0` | 0x10000 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `imr1` | 0x10008 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `imr2` | 0x10010 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `imr3` | 0x10018 | rw | 64 |  |  | unknown | established | census: 9 sites, 5 routines |
| `set_isr` | 0x10020 | w | 64 |  |  | unknown | established | census: 7 sites, 6 routines |
| `clr_isr` | 0x10028 | w | 64 |  |  | unknown | established | census: 21 sites, 20 routines |
| `isr` | 0x10030 | r | 64 |  |  | unknown | established | census: 27 sites, 17 routines |
| `imsr` | 0x10038 | r | 64 |  |  | unknown | established | census: 13 sites, 10 routines |
| `cause` | 0x10040 | rw | 64 |  |  | unknown | established | census: 58 sites, 22 routines |
| `count` | 0x20000 | r | 64 |  |  | unknown | established | census: 162 sites, 80 routines |
| `trigger` | 0x40000 | w | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `prid` | 0x50000 | r | 64 |  |  | unknown | established | census: 84 sites, 33 routines |
| `sync` | 0x60000 | r | 64 |  |  | unknown | established | census: 6 sites, 1 routines |
| `wid_id` | 0x100000 | r | 64 |  |  | unknown | established | census: 28 sites, 21 routines |
| `wid_err_upper` | 0x100010 | r | 32 |  |  | unknown | established | census: 3 sites, 3 routines |
| `wid_err_lower` | 0x100018 | r | 32 |  |  | unknown | established | census: 3 sites, 3 routines |
| `wid_req_timeout` | 0x100028 | rw | 32 |  |  | unknown | established | census: 4 sites, 2 routines |
| `wid_err_cmdword` | 0x100040 | rw | 64 |  |  | unknown | established | census: 12 sites, 11 routines |
| `wid_err_type` | 0x100060 | rw | 64 |  |  | unknown | established | census: 20 sites, 11 routines |
| `wid_err_mask` | 0x100068 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `wid_pio_err_upper` | 0x100070 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `wid_pio_err_lower` | 0x100078 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `wid_pio_rto_addr` | 0x100090 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |

### Register `mode`

### Register `mem_arb`

### Register `memcfg0`

### Register `memcfg1`

### Register `memcfg2`

### Register `memcfg3`

### Register `fc_mode`

### Register `fc_limit`

### Register `fc0_addr`

### Register `fc0_count`

### Register `status`

### Register `berr_addr`

### Register `berr_misc`

### Register `mem_err`

### Register `bad_mem`

### Register `piu_err`

### Register `imr0`

### Register `imr1`

### Register `imr2`

### Register `imr3`

### Register `set_isr`

### Register `clr_isr`

### Register `isr`

### Register `imsr`

### Register `cause`

### Register `count`

### Register `trigger`

### Register `prid`

### Register `sync`

### Register `wid_id`

### Register `wid_err_upper`

### Register `wid_err_lower`

### Register `wid_req_timeout`

### Register `wid_err_cmdword`

### Register `wid_err_type`

### Register `wid_err_mask`

### Register `wid_pio_err_upper`

### Register `wid_pio_err_lower`

### Register `wid_pio_rto_addr`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CAUSE_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `CAUSE_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `CAUSE_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `CAUSE_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `COUNT_B_11_0` | 0xfff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `FC_MODE_V_45` | 0x45 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `IMR3_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `MEM_ARB_V_100000` | 0x100000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `MODE_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `MODE_V_200000` | 0x200000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `MODE_V_400000` | 0x400000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `STATUS_B_11` | 0x800 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `STATUS_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `STATUS_B_7_4` | 0xf0 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `WID_ERR_MASK_V_2C07` | 0x2c07 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `WID_ERR_MASK_V_3FF60000` | 0x3ff60000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `WID_REQ_TIMEOUT_V_80` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
