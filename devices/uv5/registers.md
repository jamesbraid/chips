<!-- generated from devices/uv5/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 8993ab7dfd44166551161add392c877a885cd768dbb0fec5b47295afa7457b29 -->

# UV5 (UV 500 generation) hub MMR map

Offsets are relative to the hub local MMR window (or the pnode-indexed global window). Offsets, field positions and access letters are definitions in SGI-written Linux platform code. Field positions are the header bitfield structs read least-significant first; reserved and undefined bits are omitted. Role text is a paraphrase of how the kernel uses the register and is inferred. Reset values are unknown: the header states none.

Unit `uv5`, macro prefix `UV5`.
Default source: Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `node_id` | 0x0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `node_present_0` | 0x1400 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `node_present_1` | 0x1408 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `int_cmpb` | 0x22080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `ipi_int` | 0x60500 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `extio_int0_broadcast` | 0x61448 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rtc1_int_config` | 0x615c0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred0` | 0x70000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred0_alias` | 0x70008 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred1` | 0x70080 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred1_alias` | 0x70088 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred2` | 0x70100 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `event_occurred2_alias` | 0x70108 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5` | 0xb0200 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5_alias` | 0xb0208 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `scratch5_alias_2` | 0xb0210 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rtc` | 0xe0000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh10_gam_addr_map_config` | 0x470000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh10_gam_mmr_overlay_config` | 0x470090 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh10_gam_gru_overlay_config` | 0x4700b0 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh10_gam_mmioh_overlay_config0` | 0x473000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh10_gam_mmioh_redirect_config0` | 0x473800 | rw | 64 | 128 |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh10_gam_mmioh_overlay_config1` | 0x474000 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `rh10_gam_mmioh_redirect_config1` | 0x474800 | rw | 64 | 128 |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |
| `gr0_gam_gr_config` | 0x600028 | rw | 64 |  |  | unknown | established | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header |

### Register `node_id`

Header name UVH_NODE_ID. Hub identity: part number, revision, manufacturer and the node id the hub was given. Software reads it at offset 0 to tell the hub generation.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:57 | `ni_port` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 38:32 | `node_id` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31:28 | `revision` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 27:12 | `part_number` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 11:1 | `manufacturer` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |
| 0 | `force1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RO in the header. |

### Register `node_present_0`

Header name UVH_NODE_PRESENT_0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `nodes` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `node_present_1`

Header name UVH_NODE_PRESENT_1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `nodes` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `int_cmpb`

Header name UVH_INT_CMPB. RTC comparator B: the timer interrupt fires when the clock reaches this value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `real_time_cmpb` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

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

### Register `event_occurred0`

Header name UVH_EVENT_OCCURRED0. Pending hub events (error and interrupt summary bits). The ALIAS register at +8 clears bits when written.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61 | `la_seq_trigger` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 60 | `l1_to_asic` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 59 | `asic_to_l1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 58 | `stop_clock` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 57 | `l1_nmi_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 56 | `lb_irq_int_15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 55 | `lb_irq_int_14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 54 | `lb_irq_int_13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 53 | `lb_irq_int_12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 52 | `lb_irq_int_11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51 | `lb_irq_int_10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 50 | `lb_irq_int_9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 49 | `lb_irq_int_8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 48 | `lb_irq_int_7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 47 | `lb_irq_int_6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 46 | `lb_irq_int_5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 45 | `lb_irq_int_4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 44 | `lb_irq_int_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 43 | `lb_irq_int_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 42 | `lb_irq_int_1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 41 | `lb_irq_int_0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 40 | `system_shutdown_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 39 | `ni1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 38 | `ni0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 37 | `rt1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 36 | `rt0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 35 | `rdm_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 34 | `xb_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 33 | `lh3_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `lh2_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `lh1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `lh0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 29 | `rh1_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `rh0_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `kt_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26 | `lb_aoerr1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 25 | `ni1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 24 | `ni0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `rt1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `rt0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `rdm_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `xb_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19 | `lh3_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 18 | `lh2_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 17 | `lh1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `lh0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `rh1_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `rh0_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `kt_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `lb_aoerr0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `ni1_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `ni0_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `rdm_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `xb_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `lh3_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `lh2_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `lh1_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `lh0_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `rh1_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `rh0_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `kt_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `lb_hcerr` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred0_alias`

Header name UVH_EVENT_OCCURRED0_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `event_occurred1`

Header name UVH_EVENT_OCCURRED1. Second event word (UV4 and UV5 only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37 | `rdm_tlb_int23` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 36 | `rdm_tlb_int22` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 35 | `rdm_tlb_int21` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 34 | `rdm_tlb_int20` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 33 | `rdm_tlb_int19` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `rdm_tlb_int18` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `rdm_tlb_int17` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `rdm_tlb_int16` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 29 | `rdm_tlb_int15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `rdm_tlb_int14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `rdm_tlb_int13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26 | `rdm_tlb_int12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 25 | `rdm_tlb_int11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 24 | `rdm_tlb_int10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `rdm_tlb_int9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `rdm_tlb_int8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `rdm_tlb_int7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `rdm_tlb_int6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19 | `rdm_tlb_int5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 18 | `rdm_tlb_int4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 17 | `rdm_tlb_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `rdm_tlb_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `rdm_tlb_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `rdm_tlb_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `xh_tlb_int5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `xh_tlb_int4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `xh_tlb_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `xh_tlb_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `xh_tlb_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `xh_tlb_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `proc_general` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `bau_data` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `profile_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `extio_int3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `extio_int2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `extio_int1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `extio_int0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `ipi_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred1_alias`

Header name UVH_EVENT_OCCURRED1_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `event_occurred2`

Header name UVH_EVENT_OCCURRED2. Third event word. UV2 to UV4 carry the real-time clock comparator interrupt here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33 | `rtc_31` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 32 | `rtc_30` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 31 | `rtc_29` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 30 | `rtc_28` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 29 | `rtc_27` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 28 | `rtc_26` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 27 | `rtc_25` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 26 | `rtc_24` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 25 | `rtc_23` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 24 | `rtc_22` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 23 | `rtc_21` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 22 | `rtc_20` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 21 | `rtc_19` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 20 | `rtc_18` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 19 | `rtc_17` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 18 | `rtc_16` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 17 | `rtc_15` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 16 | `rtc_14` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 15 | `rtc_13` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 14 | `rtc_12` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 13 | `rtc_11` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `rtc_10` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 11 | `rtc_9` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 10 | `rtc_8` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 9 | `rtc_7` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8 | `rtc_6` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 7 | `rtc_5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 6 | `rtc_4` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 5 | `rtc_3` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 4 | `rtc_2` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 3 | `rtc_1` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 2 | `rtc_0` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 1 | `bau_dashboard_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 0 | `rtc_interval_int` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `event_occurred2_alias`

Header name UVH_EVENT_OCCURRED2_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `scratch5`

Header name UVH_SCRATCH5. Scratch register firmware and kernel share: carries the TSC sync state and the NMI request bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch5` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `scratch5_alias`

Header name UVH_SCRATCH5_ALIAS. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `scratch5_alias_2`

Header name UVH_SCRATCH5_ALIAS_2. Alias of the preceding register used by software to clear or acknowledge bits; the header defines no fields for it.

### Register `rtc`

Header name UVH_RTC. Real-time clock counter, replicated across the cache lines of its page from UV2 on so sockets can read it in parallel.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `real_time_clock` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh10_gam_addr_map_config`

Header name UVH_RH10_GAM_ADDR_MAP_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:16 | `mk_tme_keyid_bits` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 12 | `ls_enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 8:6 | `n_skt` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh10_gam_mmr_overlay_config`

Header name UVH_RH10_GAM_MMR_OVERLAY_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51:25 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh10_gam_gru_overlay_config`

Header name UVH_RH10_GAM_GRU_OVERLAY_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 54:52 | `n_gru` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51:25 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh10_gam_mmioh_overlay_config0`

Header name UVH_RH10_GAM_MMIOH_OVERLAY_CONFIG0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 61:58 | `n_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 57:52 | `m_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51:26 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh10_gam_mmioh_redirect_config0`

Header name UVH_RH10_GAM_MMIOH_REDIRECT_CONFIG0.

Array of 128 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:0 | `nasid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh10_gam_mmioh_overlay_config1`

Header name UVH_RH10_GAM_MMIOH_OVERLAY_CONFIG1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 61:58 | `n_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 57:52 | `m_io` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
| 51:26 | `base` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `rh10_gam_mmioh_redirect_config1`

Header name UVH_RH10_GAM_MMIOH_REDIRECT_CONFIG1.

Array of 128 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:0 | `nasid` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |

### Register `gr0_gam_gr_config`

Header name UVH_GR0_GAM_GR_CONFIG.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10 | `subspace` | established |  | Linux v5.4 SGI UV platform MMR header (GPL); UV5 rows from the v6.6 header | Access RW in the header. |
