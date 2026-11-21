<!-- generated from devices/uv4/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 9e51e3f75eda9a3022a20854471f594497385127ba53339f369e77577b583af3 -->

# UV4 (UV 400 generation, includes the UV4A revision) hub MMR map

Offsets are relative to the hub local MMR window (or the pnode-indexed global window). Offsets, field positions and access letters are definitions in SGI-written Linux platform code. Field positions are the header bitfield structs read least-significant first; reserved and undefined bits are omitted. Role text is a paraphrase of how the kernel uses the register and is inferred. Reset values are unknown: the header states none.

Unit `uv4`, macro prefix `UV4`.
Default source: Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `node_id` | 0x0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `node_present_table` | 0x1400 | rw | 64 | 4 |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
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
| `gr1_tlb_int0_config` | 0x62100 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_int1_config` | 0x62140 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred0` | 0x70000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred0_alias` | 0x70008 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred1` | 0x70080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred1_alias` | 0x70088 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred2` | 0x70100 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred2_alias` | 0x70108 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_proc_intd_queue_first` | 0xa4100 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_proc_intd_queue_last` | 0xa4108 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_proc_intd_soft_ack_pending` | 0xa4110 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_proc_intd_soft_ack_clear` | 0xa4118 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5` | 0xb0200 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5_alias` | 0xb0208 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5_alias_2` | 0xb0210 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_descriptor_base` | 0xc8010 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_activation_control` | 0xc8020 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_activation_status_0` | 0xc8030 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_activation_status_1` | 0xc8040 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_sb_activation_status_2` | 0xc8130 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `lb_bau_misc_control` | 0xc8170 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rtc` | 0xe0000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_addr_map_config` | 0x480000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_gru_overlay_config` | 0x480010 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_mmr_overlay_config` | 0x480028 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_0_overlay_config` | 0x4800c8 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_0_redirect_config` | 0x4800d0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_1_overlay_config` | 0x4800d8 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_1_redirect_config` | 0x4800e0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_2_overlay_config` | 0x4800e8 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_alias_2_redirect_config` | 0x4800f0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_mmioh_overlay_config0` | 0x483000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_mmioh_redirect_config0` | 0x483800 | rw | 64 | 128 |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_mmioh_overlay_config1` | 0x484000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh_gam_mmioh_redirect_config1` | 0x484800 | rw | 64 | 128 |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_gam_gr_config` | 0x600028 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_mmr_control` | 0x601080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_mmr_read_data_hi` | 0x6010a0 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_tlb_mmr_read_data_lo` | 0x6010a8 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_mmr_control` | 0x701080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_mmr_read_data_hi` | 0x7010a0 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr1_tlb_mmr_read_data_lo` | 0x7010a8 | r | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |

### Register `node_id`

Header name UVH_NODE_ID. Hub identity: part number, revision, manufacturer and the node id the hub was given. Software reads it at offset 0 to tell the hub generation.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:57 | `ni_port` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 56:50 | `nodes_per_bit` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 49 | `reserved_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `router_select` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 46:32 | `node_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31:28 | `revision` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 27:12 | `part_number` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11:1 | `manufacturer` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 0 | `force1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `node_present_table`

Header name UVH_NODE_PRESENT_TABLE.

Array of 4 registers, stride 8.

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
| 55:0 | `real_time_cmp_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `int_cmpd`

Header name UVH_INT_CMPD.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `real_time_cmp_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

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
| 63 | `extio_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 62 | `extio_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 61 | `extio_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 60 | `extio_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 59 | `ipi_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 58 | `la_seq_trigger` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 57 | `l1_to_asic` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 56 | `asic_to_l1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55 | `stop_clock` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 54 | `l1_nmi_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 53 | `lb_irq_int_15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52 | `lb_irq_int_14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51 | `lb_irq_int_13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 50 | `lb_irq_int_12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 49 | `lb_irq_int_11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `lb_irq_int_10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 47 | `lb_irq_int_9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46 | `lb_irq_int_8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45 | `lb_irq_int_7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 44 | `lb_irq_int_6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 43 | `lb_irq_int_5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 42 | `lb_irq_int_4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 41 | `lb_irq_int_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 40 | `lb_irq_int_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 39 | `lb_irq_int_1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 38 | `lb_irq_int_0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 37 | `system_shutdown_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 36 | `ni1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 35 | `ni0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 34 | `rtq3_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 33 | `rtq2_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `rtq1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `rtq0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `xb_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 29 | `gr1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `gr0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `lh1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26 | `lh0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 25 | `rh_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 24 | `kt_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `lb_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `ni1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `ni0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `rtq3_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19 | `rtq2_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 18 | `rtq1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 17 | `rtq0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `xb_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `gr1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `gr0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `lh1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `lh0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `rh_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `kt_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `lb_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `ni1_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `ni0_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `gr1_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `gr0_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `lh1_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `lh0_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `rh_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `kt_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `lb_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred0_alias`

Header name UVH_EVENT_OCCURRED0_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `event_occurred1`

Header name UVH_EVENT_OCCURRED1. Second event word (UV4 and UV5 only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 50 | `gr1_tlb_int23` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 49 | `gr1_tlb_int22` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `gr1_tlb_int21` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 47 | `gr1_tlb_int20` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46 | `gr1_tlb_int19` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45 | `gr1_tlb_int18` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 44 | `gr1_tlb_int17` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 43 | `gr1_tlb_int16` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 42 | `gr1_tlb_int15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 41 | `gr1_tlb_int14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 40 | `gr1_tlb_int13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 39 | `gr1_tlb_int12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 38 | `gr1_tlb_int11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 37 | `gr1_tlb_int10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 36 | `gr1_tlb_int9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 35 | `gr1_tlb_int8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 34 | `gr1_tlb_int7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 33 | `gr1_tlb_int6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `gr1_tlb_int5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `gr1_tlb_int4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `gr1_tlb_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 29 | `gr1_tlb_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `gr1_tlb_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `gr1_tlb_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26 | `gr0_tlb_int23` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 25 | `gr0_tlb_int22` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 24 | `gr0_tlb_int21` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `gr0_tlb_int20` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `gr0_tlb_int19` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `gr0_tlb_int18` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `gr0_tlb_int17` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19 | `gr0_tlb_int16` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 18 | `gr0_tlb_int15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 17 | `gr0_tlb_int14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `gr0_tlb_int13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `gr0_tlb_int12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `gr0_tlb_int11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `gr0_tlb_int10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `gr0_tlb_int9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `gr0_tlb_int8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `gr0_tlb_int7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `gr0_tlb_int6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `gr0_tlb_int5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `gr0_tlb_int4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `gr0_tlb_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `gr0_tlb_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `gr0_tlb_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `gr0_tlb_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `proc_general` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `bau_data` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `profile_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred1_alias`

Header name UVH_EVENT_OCCURRED1_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `event_occurred2`

Header name UVH_EVENT_OCCURRED2. Third event word. UV2 to UV4 carry the real-time clock comparator interrupt here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49 | `rtc_31` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `rtc_30` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 47 | `rtc_29` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46 | `rtc_28` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45 | `rtc_27` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 44 | `rtc_26` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 43 | `rtc_25` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 42 | `rtc_24` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 41 | `rtc_23` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 40 | `rtc_22` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 39 | `rtc_21` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 38 | `rtc_20` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 37 | `rtc_19` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 36 | `rtc_18` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 35 | `rtc_17` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 34 | `rtc_16` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 33 | `rtc_15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `rtc_14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `rtc_13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `rtc_12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 29 | `rtc_11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `rtc_10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `rtc_9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26 | `rtc_8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 25 | `rtc_7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 24 | `rtc_6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `rtc_5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `rtc_4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `rtc_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `rtc_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19 | `rtc_1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 18 | `rtc_0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 17 | `bau_dashboard_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `rtc_interval_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `message_accelerator_int15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `message_accelerator_int14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `message_accelerator_int13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `message_accelerator_int12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `message_accelerator_int11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `message_accelerator_int10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `message_accelerator_int9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `message_accelerator_int8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `message_accelerator_int7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `message_accelerator_int6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `message_accelerator_int5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `message_accelerator_int4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `message_accelerator_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `message_accelerator_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `message_accelerator_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `message_accelerator_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred2_alias`

Header name UVH_EVENT_OCCURRED2_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `lb_proc_intd_queue_first`

Header name UV4H_LB_PROC_INTD_QUEUE_FIRST.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:6 | `first_payload_address` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_proc_intd_queue_last`

Header name UV4H_LB_PROC_INTD_QUEUE_LAST.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:5 | `last_payload_address` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_proc_intd_soft_ack_pending`

Header name UV4H_LB_PROC_INTD_SOFT_ACK_PENDING.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `soft_ack_flags` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_proc_intd_soft_ack_clear`

Header name UV4H_LB_PROC_INTD_SOFT_ACK_CLEAR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `soft_ack_pending_flags` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |

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
| 45:12 | `page_address` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

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

### Register `lb_bau_sb_activation_status_2`

Header name UVXH_LB_BAU_SB_ACTIVATION_STATUS_2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `aux_error` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `lb_bau_misc_control`

Header name UVH_LB_BAU_MISC_CONTROL. BAU mode control: software acknowledge mode, acknowledge timeout period and per-generation workarounds.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:48 | `fun` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46 | `address_interleave_select` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:38 | `thread_kill_timebase` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 37 | `reserved_37` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 36 | `suppress_quiesce_msgs_to_qpi` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 35 | `use_legacy_descriptor_formats` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 34 | `suppress_int_prio_udt_to_self` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 33 | `enable_extended_sb_status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `enable_lock_based_system_flush` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `suppress_interrupts_to_self` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `apic_mode_status` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 29 | `enable_automatic_apic_mode_selection` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `enable_programmed_initial_priority` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `use_incoming_priority` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26:24 | `programmed_initial_priority` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `suppress_dest_registration` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `vga_io_port_16_bit_decode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `vga_io_port_decode_enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `enable_dual_mapping_mode` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19:15 | `reserved_15_19` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
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

### Register `rh_gam_addr_map_config`

Header name UVH_RH_GAM_ADDR_MAP_CONFIG. Address map shape: number of node-offset (m) and node-number (n) bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9:6 | `n_skt` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_gru_overlay_config`

Header name UVH_RH_GAM_GRU_OVERLAY_CONFIG. Base and enable of the GRU window.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55:52 | `n_gru` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:26 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_mmr_overlay_config`

Header name UVH_RH_GAM_MMR_OVERLAY_CONFIG. Base and enable of the global MMR window.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:26 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

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

### Register `rh_gam_mmioh_overlay_config0`

Header name UVH_RH_GAM_MMIOH_OVERLAY_CONFIG0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55:52 | `n_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51:46 | `m_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:26 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_mmioh_redirect_config0`

Header name UVH_RH_GAM_MMIOH_REDIRECT_CONFIG0.

Array of 128 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 14:0 | `nasid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_mmioh_overlay_config1`

Header name UVH_RH_GAM_MMIOH_OVERLAY_CONFIG1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55:52 | `n_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51:46 | `m_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45:26 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh_gam_mmioh_redirect_config1`

Header name UVH_RH_GAM_MMIOH_REDIRECT_CONFIG1.

Array of 128 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 14:0 | `nasid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_gam_gr_config`

Header name UVH_GR0_GAM_GR_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10 | `subspace` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_tlb_mmr_control`

Header name UVH_GR0_TLB_MMR_CONTROL.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:59 | `page_size` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `mmr_op_done` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `mmr_read` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 30 | `mmr_write` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 21 | `ecc_sel` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `mmr_hash_index_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `auto_valid_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14:13 | `mem_sel` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12:0 | `index` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_tlb_mmr_read_data_hi`

Header name UVH_GR0_TLB_MMR_READ_DATA_HI.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:55 | `way_ecc` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 53 | `aa_ext` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 52 | `larger` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 51 | `dirty` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 50:49 | `gaa` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 48:34 | `pnid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 33:0 | `pfn` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

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
| 63:59 | `page_size` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `mmr_op_done` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `mmr_read` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 30 | `mmr_write` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access WP in the header. |
| 21 | `ecc_sel` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `mmr_hash_index_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `auto_valid_en` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14:13 | `mem_sel` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12:0 | `index` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr1_tlb_mmr_read_data_hi`

Header name UVH_GR1_TLB_MMR_READ_DATA_HI.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:55 | `way_ecc` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 53 | `aa_ext` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 52 | `larger` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 51 | `dirty` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 50:49 | `gaa` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 48:34 | `pnid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 33:0 | `pfn` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `gr1_tlb_mmr_read_data_lo`

Header name UVH_GR1_TLB_MMR_READ_DATA_LO.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 62:39 | `asid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 38:0 | `vpn` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
