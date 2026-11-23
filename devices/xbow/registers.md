<!-- generated from devices/xbow/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 1d5707b21be4c7d824b64b2d6d46ae200225b3a331af2e4f73daad0758f2a2ce -->

# Xbow (crossbar)

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout. Views: the offset is the 8-byte slot address. "4 at slot+4" is a 32-bit load or store at that address plus 4, the low word of the slot on a big-endian machine; a 64-bit access to the slot address reaches the same register.

Unit `xbow`, macro prefix `XBOW`.
Default source: census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `xb_id` | 0x0 | r | 32 |  |  | unknown | established | census: 21 sites, 7 routines |
| `xb_stat` | 0x8 | r | 32 |  |  | unknown | established | census: 8 sites, 4 routines |
| `xb_err_upper` | 0x10 | r | 32 |  |  | unknown | established | census: 10 sites, 4 routines |
| `xb_err_lower` | 0x18 | r | 32 |  |  | unknown | established | census: 10 sites, 4 routines |
| `xb_ctrl` | 0x20 | rw | 32 |  |  | unknown | established | census: 9 sites, 3 routines |
| `xb_pkt_to` | 0x28 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `xb_int_upper` | 0x30 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `xb_int_lower` | 0x38 | rw | 32 |  |  | unknown | established | census: 6 sites, 2 routines |
| `xb_err_cmdword` | 0x40 | rw | 32 |  |  | unknown | established | census: 14 sites, 4 routines |
| `xb_llp_ctrl` | 0x48 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `xb_stat_clr` | 0x50 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `xb_arb_reload` | 0x58 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `reserved` | 0x80 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `reserved_88` | 0x88 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `reserved_90` | 0x90 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `reserved_98` | 0x98 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `reserved_a0` | 0xa0 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `reserved_a8` | 0xa8 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `reserved_b0` | 0xb0 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `reserved_b8` | 0xb8 | rw | 32 |  |  | unknown | established | census: 2 sites, 1 routines |
| `xb_link_ctrl` | 0x108 | rw | 32 |  |  | unknown | established | census: 9 sites, 1 routines |
| `xb_link_stat` | 0x110 | r | 32 |  |  | unknown | established | census: 3 sites, 3 routines |
| `xb_link_arb_upper` | 0x118 | rw | 32 |  |  | unknown | established | census: 15 sites, 5 routines |
| `xb_link_arb_lower` | 0x120 | rw | 32 |  |  | unknown | established | census: 15 sites, 5 routines |
| `xb_link_stat_clr` | 0x128 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `xb_link_reset` | 0x130 | w | 32 |  |  | unknown | established | census: 6 sites, 4 routines |
| `xb_link_aux_stat` | 0x138 | r | 32 |  |  | unknown | established | census: 6 sites, 4 routines |
| `xb_link_ctrl_148` | 0x148 | rw | 32 |  |  | unknown | established | census: 9 sites, 1 routines |
| `xb_link_stat_150` | 0x150 | r | 32 |  |  | unknown | established | census: 3 sites, 3 routines |
| `xb_link_stat_clr_168` | 0x168 | r | 32 |  |  | unknown | established | census: 3 sites, 1 routines |
| `xb_link_aux_stat_178` | 0x178 | r | 32 |  |  | unknown | established | census: 6 sites, 4 routines |
| `xb_link_arb_upper_198` | 0x198 | rw | 32 |  |  | unknown | established | census: 4 sites, 1 routines |
| `xb_link_arb_upper_1d8` | 0x1d8 | rw | 32 |  |  | unknown | established | census: 4 sites, 1 routines |

### Register `xb_id`

### Register `xb_stat`

### Register `xb_err_upper`

### Register `xb_err_lower`

### Register `xb_ctrl`

### Register `xb_pkt_to`

### Register `xb_int_upper`

### Register `xb_int_lower`

### Register `xb_err_cmdword`

### Register `xb_llp_ctrl`

### Register `xb_stat_clr`

### Register `xb_arb_reload`

### Register `reserved`

### Register `reserved_88`

### Register `reserved_90`

### Register `reserved_98`

### Register `reserved_a0`

### Register `reserved_a8`

### Register `reserved_b0`

### Register `reserved_b8`

### Register `xb_link_ctrl`

### Register `xb_link_stat`

### Register `xb_link_arb_upper`

### Register `xb_link_arb_lower`

### Register `xb_link_stat_clr`

### Register `xb_link_reset`

### Register `xb_link_aux_stat`

### Register `xb_link_ctrl_148`

### Register `xb_link_stat_150`

### Register `xb_link_stat_clr_168`

### Register `xb_link_aux_stat_178`

### Register `xb_link_arb_upper_198`

### Register `xb_link_arb_upper_1d8`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `RESERVED_V_FF` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_20_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_20_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_20_V_24` | 0x24 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_20_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_V_24` | 0x24 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_CTRL_V_80000000` | 0x80000000 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_ID_0_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_ID_0_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_ID_0_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_ID_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_ID_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_ID_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_INT_UPPER_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_ARB_UPPER_1D8_V_9` | 0x9 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_AUX_STAT_138_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_AUX_STAT_138_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_AUX_STAT_178_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_AUX_STAT_B_5` | 0x20 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_AUX_STAT_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_CTRL_108_B_3` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_CTRL_108_V_80000` | 0x80000 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_CTRL_148_B_3` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_CTRL_B_3` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_LINK_CTRL_V_80000` | 0x80000 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_STAT_8_B_5_2` | 0x24 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_STAT_8_B_9_6` | 0x3c0 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_STAT_B_5_2` | 0x24 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
| `XB_STAT_B_9_6` | 0x3c0 | inferred | census: loads and stores in the shipped binaries; names from the Crossbow ASIC Specification revision 12.0 register name (Hwreg column), applied by the census join after the offsets were read from the code |  |
