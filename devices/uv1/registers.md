<!-- generated from devices/uv1/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 159c697560a3b949dc49448667f72fec268c6242349e1b64f09c426b965975bf -->

# UV1 (UV 1000 generation) hub MMR map

Offsets are relative to the hub local MMR window (or the pnode-indexed global window). Offsets, field positions and access letters are definitions in SGI-written Linux platform code. Field positions are the header bitfield structs read least-significant first; reserved and undefined bits are omitted. Role text is a paraphrase of how the kernel uses the register and is inferred. Reset values are unknown: the header states none.

Unit `uv1`, macro prefix `UV1`.
Default source: Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `node_id` | 0x0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `node_present_table` | 0x1400 | rw | 64 | 16 |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `int_cmpb` | 0x22080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `int_cmpc` | 0x22100 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `int_cmpd` | 0x22180 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `ipi_int` | 0x60500 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `extio_int0_broadcast` | 0x61448 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rtc1_int_config` | 0x615c0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `bau_data_config` | 0x61680 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `bau_data_broadcast` | 0x61688 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_int0_config` | 0x61b00 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_int1_config` | 0x61b40 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_int0_config` | 0x61f00 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_int1_config` | 0x61f40 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred0` | 0x70000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred0_alias` | 0x70008 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5` | 0x2d0200 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5_alias` | 0x2d0208 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5_alias_2` | 0x2d0210 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_descriptor_base` | 0x320010 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_activation_control` | 0x320020 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_activation_status_0` | 0x320030 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_activation_status_1` | 0x320040 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_intd_payload_queue_first` | 0x320050 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_intd_payload_queue_last` | 0x320060 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_intd_payload_queue_tail` | 0x320070 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_intd_software_acknowledge` | 0x320080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_intd_software_acknowledge_alias` | 0x320088 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_target_physical_apic_id_mask` | 0x320130 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_misc_control` | 0x320170 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rtc` | 0x340000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_mmr_control` | 0x401080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_mmr_read_data_hi` | 0x4010a0 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_mmr_read_data_lo` | 0x4010a8 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_mmr_control` | 0x801080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_mmr_read_data_hi` | 0x8010a0 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_mmr_read_data_lo` | 0x8010a8 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_addr_map_config` | 0x1600000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_gru_overlay_config` | 0x1600010 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_mmr_overlay_config` | 0x1600028 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_mmioh_overlay_config` | 0x1600030 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_0_overlay_config` | 0x16000c8 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_0_redirect_config` | 0x16000d0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_1_overlay_config` | 0x16000d8 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_1_redirect_config` | 0x16000e0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_2_overlay_config` | 0x16000e8 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_2_redirect_config` | 0x16000f0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |

### Register `node_id`

Header name UVH_NODE_ID. Hub identity: part number, revision, manufacturer and the node id the hub was given. Software reads it at offset 0 to tell the hub generation.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:56 | `ni_port` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 54:48 | `nodes_per_bit` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46:32 | `node_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31:28 | `revision` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 27:12 | `part_number` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11:1 | `manufacturer` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 0 | `force1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `node_present_table`

Header name UVH_NODE_PRESENT_TABLE.

Array of 16 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `nodes` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `int_cmpb`

Header name UVH_INT_CMPB. RTC comparator B: the timer interrupt fires when the clock reaches this value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `real_time_cmpb` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `int_cmpc`

Header name UVH_INT_CMPC.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `real_time_cmpc` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `int_cmpd`

Header name UVH_INT_CMPD.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `real_time_cmpd` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `ipi_int`

Header name UVH_IPI_INT. Send an inter-processor interrupt: the sender writes the target apic id, vector and a send bit in the target hub global MMR window.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `send` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 47:16 | `apic_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `destmode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10:8 | `delivery_mode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `extio_int0_broadcast`

Header name UVH_EXTIO_INT0_BROADCAST.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rtc1_int_config`

Header name UVH_RTC1_INT_CONFIG. Delivery configuration (vector, apic id) for the RTC comparator interrupt.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `apic_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `m` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `t` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 13 | `p` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 12 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11 | `destmode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10:8 | `dm` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `bau_data_config`

Header name UVH_BAU_DATA_CONFIG. Where the hub sends a broadcast assist unit message interrupt: vector, delivery mode and apic id.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `apic_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `m` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `t` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 13 | `p` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 12 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11 | `destmode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10:8 | `dm` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `bau_data_broadcast`

Header name UVH_BAU_DATA_BROADCAST. Enable broadcast of BAU message interrupts to both sockets of the hub (UV2 and later).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_tlb_int0_config`

Header name UVH_GR0_TLB_INT0_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `apic_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `m` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `t` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 13 | `p` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 12 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11 | `destmode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10:8 | `dm` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_tlb_int1_config`

Header name UVH_GR0_TLB_INT1_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `apic_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `m` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `t` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 13 | `p` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 12 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11 | `destmode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10:8 | `dm` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr1_tlb_int0_config`

Header name UVH_GR1_TLB_INT0_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `apic_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `m` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `t` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 13 | `p` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 12 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11 | `destmode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10:8 | `dm` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr1_tlb_int1_config`

Header name UVH_GR1_TLB_INT1_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `apic_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `m` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `t` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 13 | `p` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 12 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11 | `destmode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10:8 | `dm` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred0`

Header name UVH_EVENT_OCCURRED0. Pending hub events (error and interrupt summary bits). The ALIAS register at +8 clears bits when written.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 56 | `power_management_req` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55 | `bau_data` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 54 | `rtc3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 53 | `rtc2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52 | `rtc1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51 | `rtc0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 50 | `profile_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 49 | `extio_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `extio_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 47 | `extio_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46 | `extio_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45 | `ipi_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 44 | `la_seq_trigger` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 43 | `ltc_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 42 | `l1_to_asic` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 41 | `asic_to_l1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 40 | `stop_clock` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 39 | `l1_nmi_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 38 | `lb_irq_int_15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 37 | `lb_irq_int_14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 36 | `lb_irq_int_13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 35 | `lb_irq_int_12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 34 | `lb_irq_int_11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 33 | `lb_irq_int_10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `lb_irq_int_9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `lb_irq_int_8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `lb_irq_int_7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 29 | `lb_irq_int_6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `lb_irq_int_5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `lb_irq_int_4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26 | `lb_irq_int_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 25 | `lb_irq_int_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 24 | `lb_irq_int_1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `lb_irq_int_0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `system_shutdown_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `rh_vpi_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `si_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19 | `xn_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 18 | `rh_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 17 | `lh_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `gr1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `gr0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `lb_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `si_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `xn_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `rh_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `lh_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `gr1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `gr0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `lb_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `si_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `xn_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `rh_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `lh_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `gr1_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `gr0_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `lb_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred0_alias`

Header name UVH_EVENT_OCCURRED0_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `scratch5`

Header name UVH_SCRATCH5. Scratch register firmware and kernel share: carries the TSC sync state and the NMI request bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `scratch5_alias`

Header name UVH_SCRATCH5_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `scratch5_alias_2`

Header name UVH_SCRATCH5_ALIAS_2. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `lb_bau_sb_descriptor_base`

Header name UVH_LB_BAU_SB_DESCRIPTOR_BASE. Base of the 64 sets of selective-broadcast descriptors in memory: page address and the home node id.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:49 | `node_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 42:12 | `page_address` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_sb_activation_control`

Header name UVH_LB_BAU_SB_ACTIVATION_CONTROL. Start a broadcast: a push bit plus the index of the descriptor set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `init` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 62 | `push` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 5:0 | `index` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_sb_activation_status_0`

Header name UVH_LB_BAU_SB_ACTIVATION_STATUS_0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_sb_activation_status_1`

Header name UVH_LB_BAU_SB_ACTIVATION_STATUS_1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_intd_payload_queue_first`

Header name UVH_LB_BAU_INTD_PAYLOAD_QUEUE_FIRST.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:49 | `node_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 42:4 | `address` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_intd_payload_queue_last`

Header name UVH_LB_BAU_INTD_PAYLOAD_QUEUE_LAST.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 42:4 | `address` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_intd_payload_queue_tail`

Header name UVH_LB_BAU_INTD_PAYLOAD_QUEUE_TAIL.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 42:4 | `address` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_intd_software_acknowledge`

Header name UVH_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `timeout_7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `timeout_6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `timeout_5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `timeout_4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `timeout_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `timeout_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `timeout_1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `timeout_0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `pending_7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `pending_6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `pending_5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `pending_4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `pending_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `pending_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `pending_1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `pending_0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_intd_software_acknowledge_alias`

Header name UVH_LB_BAU_INTD_SOFTWARE_ACKNOWLEDGE_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `lb_target_physical_apic_id_mask`

Header name UV1H_LB_TARGET_PHYSICAL_APIC_ID_MASK.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `bit_enables` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_misc_control`

Header name UVH_LB_BAU_MISC_CONTROL. BAU mode control: software acknowledge mode, acknowledge timeout period and per-generation workarounds.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:48 | `fun` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `enable_programmed_initial_priority` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `use_incoming_priority` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26:24 | `programmed_initial_priority` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `suppress_dest_registration` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `vga_io_port_16_bit_decode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `vga_io_port_decode_enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `enable_dual_mapping_mode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19:16 | `intd_soft_ack_timeout_period` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `enable_intd_soft_ack_mode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `descriptor_fetch_mode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13:11 | `qpi_agent_presence_vector` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `force_lock_nop` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `force_broadcast` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `apic_mode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7:0 | `rejection_delay` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rtc`

Header name UVH_RTC. Real-time clock counter, replicated across the cache lines of its page from UV2 on so sockets can read it in parallel.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `real_time_clock` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_tlb_mmr_control`

Header name UVH_GR0_TLB_MMR_CONTROL.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 60 | `mmr_inj_tlblruv` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 56 | `mmr_inj_tlbrreg` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 54 | `mmr_inj_tlbpgsize` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52 | `mmr_inj_tlbram` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `mmr_inj_con` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `mmr_read` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 30 | `mmr_write` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 20 | `mmr_hash_index_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `auto_valid_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13:12 | `mem_sel` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11:0 | `index` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_tlb_mmr_read_data_hi`

Header name UVH_GR0_TLB_MMR_READ_DATA_HI.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 44 | `larger` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 43 | `dirty` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 42:41 | `gaa` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 40:0 | `pfn` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `gr0_tlb_mmr_read_data_lo`

Header name UVH_GR0_TLB_MMR_READ_DATA_LO.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 62:39 | `asid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 38:0 | `vpn` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `gr1_tlb_mmr_control`

Header name UVH_GR1_TLB_MMR_CONTROL.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 60 | `mmr_inj_tlblruv` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 56 | `mmr_inj_tlbrreg` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 54 | `mmr_inj_tlbpgsize` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52 | `mmr_inj_tlbram` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `mmr_inj_con` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `mmr_read` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 30 | `mmr_write` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 20 | `mmr_hash_index_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `auto_valid_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13:12 | `mem_sel` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11:0 | `index` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr1_tlb_mmr_read_data_hi`

Header name UVH_GR1_TLB_MMR_READ_DATA_HI.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 44 | `larger` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 43 | `dirty` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 42:41 | `gaa` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 40:0 | `pfn` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `gr1_tlb_mmr_read_data_lo`

Header name UVH_GR1_TLB_MMR_READ_DATA_LO.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 62:39 | `asid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 38:0 | `vpn` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `rh_gam_addr_map_config`

Header name UVH_RH_GAM_ADDR_MAP_CONFIG. Address map shape: number of node-offset (m) and node-number (n) bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `mmiol_cfg` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9:6 | `n_skt` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5:0 | `m_skt` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_gru_overlay_config`

Header name UVH_RH_GAM_GRU_OVERLAY_CONFIG. Base and enable of the GRU window.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55:52 | `n_gru` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `gr4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:28 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_mmr_overlay_config`

Header name UVH_RH_GAM_MMR_OVERLAY_CONFIG. Base and enable of the global MMR window.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46 | `dual_hub` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:26 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_mmioh_overlay_config`

Header name UVH_RH_GAM_MMIOH_OVERLAY_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55:52 | `n_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51:46 | `m_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:30 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_alias_0_overlay_config`

Header name UVH_RH_GAM_ALIAS_0_OVERLAY_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52:48 | `m_alias` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31:24 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_alias_0_redirect_config`

Header name UVH_RH_GAM_ALIAS_0_REDIRECT_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:24 | `dest_base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_alias_1_overlay_config`

Header name UVH_RH_GAM_ALIAS_1_OVERLAY_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52:48 | `m_alias` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31:24 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_alias_1_redirect_config`

Header name UVH_RH_GAM_ALIAS_1_REDIRECT_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:24 | `dest_base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_alias_2_overlay_config`

Header name UVH_RH_GAM_ALIAS_2_OVERLAY_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52:48 | `m_alias` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31:24 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_alias_2_redirect_config`

Header name UVH_RH_GAM_ALIAS_2_REDIRECT_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:24 | `dest_base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
