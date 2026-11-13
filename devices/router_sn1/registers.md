<!-- generated from devices/router_sn1/registers.toml by defs-gen - do not edit, change the source -->

# SN1 network router: port block, local routing table and remote reset mask (public header positions)

Addresses are port-relative: a port's block starts at the base the header computes from the link number L (1 to 8), ((L+1) & 0xe) << 15 | ((L+1) & 1) << 11. Field positions, entry counts and offsets come from the public Linux 2.5.40 ia64 SN router header, so they are established as header positions, following the convention for the other SN1 units. What a header macro computes is established only as arithmetic; what the hardware does with a table value is not stated by the header and is unknown. No router specification is held, so every reset is unknown. The census of the kernels does not reach the routing tables; their layout here comes from the header alone. The prose is in devices/router/README.md.

Unit `router_sn1`, macro prefix `ROUTER_SN1`.
Default source: Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `reset_mask` | 0x18 | rw | 64 |  |  | unknown | established | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) |
| `local_table` | 0x200 | rw | 64 | 128 |  | unknown | established | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) |

### Register `reset_mask`

Remote reset mask of one port (RR_RESET_MASK, 0x18 from the port base). Bit L minus 1 is the reset-allowed bit for link L (RRM_RESETOK). The header names the bit but not what a reset does with it. The kernel code that reads it is in the router census.

### Register `local_table`

Local routing table of one port: entry x sits at 0x200 plus 8 times x from the port base (RR_LOCAL_TABLE). Each 64-bit entry holds eight 3-bit fields, one per link. The header gives no meaning for a field value, and the 4-bit stride leaves bits 31 to 63 unnamed. Reset unknown.

Array of 128 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30:28 | `link8` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 8, bits 30 to 28. |
| 26:24 | `link7` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 7, bits 26 to 24. |
| 22:20 | `link6` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 6, bits 22 to 20. |
| 18:16 | `link5` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 5, bits 18 to 16. |
| 14:12 | `link4` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 4, bits 14 to 12. |
| 10:8 | `link3` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 3, bits 10 to 8. |
| 6:4 | `link2` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 2, bits 6 to 4. |
| 2:0 | `link1` | established |  | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Field for link 1, bits 2 to 0 (RTABLE_SHFT for L=1). |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `LOCAL_ENTRIES` | 0x80 | established | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Entries in one port's local routing table, from RR_LOCAL_ENTRIES. |
| `MAX_PORTS` | 0x8 | established | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Ports on one router, from MAX_ROUTER_PORTS. Port and link numbers run from 1 to 8. |
| `META_ENTRIES` | 0x10 | established | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Entries in the meta routing table, from RR_META_ENTRIES. The header gives no offset for the meta table, so its address is unknown. |
| `RTABLE_FIELD_BITS` | 0x3 | established | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Width of one routing-table field, from RTABLE_MASK (0x7). |
| `RTABLE_FIELD_STRIDE_BITS` | 0x4 | established | Linux 2.5.40 ia64 SN router header (RR_LOCAL_TABLE0, RR_LOCAL_TABLE, RR_RESET_MASK, RRM_RESETOK, RTABLE_SHFT, RTABLE_MASK, MAX_ROUTER_PORTS, RR_LOCAL_ENTRIES, RR_META_ENTRIES) | Bit distance between successive routing-table fields, from RTABLE_SHFT (4 times L minus 1). |
