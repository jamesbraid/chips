<!-- generated from devices/shub_ii/registers.toml by defs-gen - do not edit, change the source -->

# SHub 1 I/O interface (II): Crosstalk port, access protection, CRBs and block transfer engines

Offsets are node-relative, the same numbers the SGI Linux ia64 header uses: the II starts 4 MiB into the node's register space. Field positions are the header's bitfield unions read least-significant first, which agrees with the header's own shift and mask macros wherever it has both. The header is the vendor platform source, so offsets and field positions are established as definitions. Role text is a paraphrase of the header's comments and is inferred. Reset values are unknown unless a source states one, and none does. The kernel files read use few of these registers; the access note in each register says whether the kernel touches it.

Unit `shub_ii`, macro prefix `SHUB_II`.
Default source: Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `widget_id` | 0x400000 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `widget_status` | 0x400008 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `widget_control` | 0x400020 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `local_access_protection` | 0x400100 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `local_access_override` | 0x400108 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `outbound_widget_access` | 0x400110 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `inbound_widget_access` | 0x400118 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `inbound_device_error_mask` | 0x400120 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `llp_control_status` | 0x400128 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `llp_log` | 0x400130 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `interrupt_destination` | 0x400138 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `graphics_map` | 0x400140 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `scratch` | 0x400150 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `itte` | 0x400160 | rw | 64 | 7 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `prb` | 0x400198 | rw | 64 | 9 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crosstalk_credit_timeout` | 0x4001e0 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `misc_error_mask` | 0x4001e8 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crosstalk_timeout_threshold` | 0x4001f0 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `error_clear` | 0x4001f8 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `bte_common_control` | 0x400200 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `spurious_message` | 0x400208 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `spurious_sideband` | 0x400210 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `llp_channel_test` | 0x400218 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `error_packet_header_1` | 0x400220 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `error_packet_header_2` | 0x400228 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `sxb_access_protection` | 0x400230 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `sxb_access_override` | 0x400238 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `wrapper_interrupt` | 0x400240 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `wrapper_error_log` | 0x400248 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `wrapper_control` | 0x400250 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `wrapper_status` | 0x400258 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `wrapper_error_interrupt_mask` | 0x400260 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `prb_counter_adjust` | 0x400300 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `pio_read_entry_a` | 0x400308 | rw | 64 | 8 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `pio_read_entry_b` | 0x400348 | rw | 64 | 8 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `pio_deallocate` | 0x400388 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_deallocate` | 0x400390 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `ioq_fifo_depth` | 0x400398 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `iiq_arbitration` | 0x4003a0 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_management` | 0x4003a8 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_control` | 0x4003b0 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_timeout` | 0x4003b8 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_timeout_prescaler` | 0x4003c0 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_a` | 0x400400 | rw | 64 | 15 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_b` | 0x400408 | rw | 64 | 15 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_c` | 0x400410 | rw | 64 | 15 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_d` | 0x400418 | rw | 64 | 15 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `crb_e` | 0x400420 | rw | 64 | 15 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `spurious_crb_message_low` | 0x400700 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `spurious_crb_message_mid` | 0x400708 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `spurious_crb_message_high` | 0x400710 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `debug_submenu_select` | 0x400718 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `bte_length_status` | 0x410000 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `bte_source` | 0x410008 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `bte_destination` | 0x410010 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `bte_control` | 0x410018 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `bte_notify` | 0x410020 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `bte_interrupt` | 0x410028 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `perf_control` | 0x430000 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |
| `perf_profile` | 0x430008 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |

### Register `widget_id`

Crosstalk widget identification. Echoes the revision and manufacturer fields of the local block's revision register and carries the part number SGI assigned to SHub. Also visible to a widget on the link at its own offset 0. Header name IIO_WID.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `rev_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 27:12 | `part_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 11:1 | `mfg_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `widget_status`

Widget status: error flags the II sets on a Crosstalk credit timeout, tail timeout, retry limit and similar link faults, plus a pending count. Cleared by the mechanisms the header lists per field. Header name IIO_WSTAT. SAL 5.04 PROM: written 0 once, in its set-up routine (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `crazy` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 23:16 | `llp_tx_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 9 | `tx_mx_rty` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 5 | `xt_tail_to` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `xt_crd_to` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `pending` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `widget_control`

Widget control: Crosstalk flow control. Holds the widget id the II answers to, tag mode, destination credit count, a force-bad-packet debug bit, the direct-connect bit and the elasticity threshold. Header name IIO_WCR. SAL 5.04 PROM: read-modify-write, each followed by a read back and a 10 ms wait: wid from bits 9:6 of the widget 0 status with tag cleared (site 0xffab33e0), dir_con cleared (site 0xffab3320), tag set (site 0xffab3260), dst_crd set to 4 (site 0xffab3580); wid is read to find the master link (site 0xffab3720).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:18 | `e_thresh` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 17 | `dir_con` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16 | `f_bad_pkt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15:13 | `dst_crd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `tag` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `wid` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `local_access_protection`

Local access protection: one bit per region of nodes. A PIO read or write is performed only if the requester's region bit is set; reset value permits every node. The header says it is also reachable through an alias window for the local processors. Header name IIO_ILAPR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `region` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `local_access_override`

Protection override: writing the 64-bit ASCII string SGIrules sets the requester's region bit in the local access protection register; any other value is ignored. Header name IIO_ILAPO.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `io_ovrride` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `outbound_widget_access`

Outbound widget access: one bit per widget qualifying PIO and graphics writes the SHub launches toward that widget, on top of the local access protection register. Header name IIO_IOWA. SAL 5.04 PROM: written 0xff01 (site 0xffab30e0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `wx_oac` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `w0_oac` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `inbound_widget_access`

Inbound widget access: qualifies requests a widget sends toward the SHub. Meant for software to fence off a misbehaving widget. Header name IIO_IIWA. SAL 5.04 PROM: written 0xff01 (site 0xffab30e0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `wx_iac` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `w0_iac` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `inbound_device_error_mask`

Inbound device error mask: per-device (up to eight per widget) enable bits for DMA masters. The SHub clears a device's bit when it detects an error that requires the device to be shut off. Header name IIO_IIDEM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `wf_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 55:48 | `we_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 47:40 | `wd_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 39:32 | `wc_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 31:24 | `wb_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 23:16 | `wa_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15:8 | `w9_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7:0 | `w8_dxs` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `llp_control_status`

LLP control and status: programmable control and observation fields for the link-level protocol port toward Crosstalk. Header name IIO_ILCSR. SAL 5.04 PROM: bit 13 (llp_stat bit 1, the header's IIO_LLP_CSR_IS_UP) must be set, and the PROM prints that an I/O brick is attached (site 0xffab2e60); read-modify-write of d_avail_sel to 0 (site 0xffab3020), llp_en to 1 (site 0xffab2f80) and nullto to 3 (site 0xffab3780), and wrmrst set when the L1 module type is 111 (site 0xffab3170).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41:32 | `maxbrst` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 27:26 | `d_avail_sel` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 25:16 | `maxrtry` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14 | `remote_power` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 13:12 | `llp_stat` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 11 | `bm8` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 10 | `llp_en` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `wrmrst` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 5:0 | `nullto` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `llp_log`

LLP log: status of the link error rate. Header name IIO_ILLR. SAL 5.04 PROM: written 0 (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `cb_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15:0 | `sn_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `interrupt_destination`

Interrupt destination for II-detected non-BTE error interrupts: vector level, target PI unit, target node, an enable bit and a sent state. Which processor interface receives the packet is fixed in hardware: PI0 register 0x1800090 or PI1 register 0x1a00090 of the target node (header text). Header name IIO_IIDSR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33 | `pi1_forward_int` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 32 | `pi0_forward_int` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 29:28 | `int_sent` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 24 | `enable` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 19:9 | `node` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `pi_id` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7:0 | `level` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `graphics_map`

Graphics node and widget map: matches write responses coming back from a graphics widget to the processor that issued the write, so the response can be turned into a flow-control credit for that processor. Two instances. Header name IIO_IGFX. SAL 5.04 PROM: instance 0 written 2 and instance 1 written 3 (site 0xffab1cc0).

Array of 2 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 17 | `p_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16:5 | `n_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `pi_id` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `w_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `scratch`

Scratch register for software. Two instances, no hardware effect. Header name IIO_ISCR.

Array of 2 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `scratch` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `itte`

Translation table entry mapping one SHub big window to a Crosstalk address: a 5-bit offset joined to the window-relative address bits, a 4-bit widget number and an I/O space bit. The header numbers the entries 1 to 7; the kernel numbers them 0 to 6, and uses the top big window as a stand-in for small window 0 to work around a defect on the processor-interface side. Header names IIO_ITTE1 to IIO_ITTE7. SAL 5.04 PROM: all seven written 0 (site 0xffab1cc0); it programs no translation and uses no big window.

Array of 7 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `iosp` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 11:8 | `w_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4:0 | `offset` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `prb`

PIO request buffer for one widget (widget 0 and widgets 8 to F): the state the II keeps to manage PIO flow control on Crosstalk and toward the router network, including a spurious-read and spurious-write indicator. Nine entries, widget 0 first and widgets 8 to F after it, at an 8-byte stride (header names IIO_IPRB0, IIO_IPRB8 to IIO_IPRBF). SAL 5.04 PROM: f_bit set by read-modify-write in entry 0 and in entries 8 to F (site 0xffab1cc0); the header gives f_bit no meaning.

Array of 9 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `mult_err` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 51 | `spur_rd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 50 | `spur_wr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 49 | `rd_to` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 48 | `error` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 47:43 | `of_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 42 | `f_bit` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 41:40 | `m_bit` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 37:24 | `nb` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 21:8 | `na` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7:0 | `c_bit` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crosstalk_credit_timeout`

Crosstalk credit timeout threshold: how long, counted in 128 II clocks, outbound Crosstalk credits may stay below the threshold before a credit timeout is flagged. Header name IIO_IXCC.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:0 | `time_out` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `misc_error_mask`

Miscellaneous error mask: enable bits for widget 0 and the two BTE streams; the SHub clears a bit when it shuts that source down after an error. Software sets it again by writing a one. The kernel's BTE recovery sets the two BTE bits. Kernel: read, BTE 0 and BTE 1 bits set, written back after a BTE error. Header name IIO_IMEM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `clr_precise` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `b1_esd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `b0_esd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `w0_esd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crosstalk_timeout_threshold`

Crosstalk timeout threshold: read response timeout, its prescaler and the tail-flit timeout, after which the II raises an error interrupt. Header name IIO_IXTT.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:55 | `rrsp_to` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 54:32 | `rrsp_ps` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 25:0 | `tail_to` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `error_clear`

Error clear: writing a one clears the matching error bit elsewhere in the SHub (PRB entries, crazy-widget, BTE 0 and 1, CAM and queue over/underflows, bad commands). The kernel's BTE recovery writes the BTE 0 and BTE 1 bits. Kernel: written with BTE 0 and BTE 1 clear bits after a BTE error (write-one-to-clear). Header name IIO_IECLR. SAL 5.04 PROM: written 0x7ffffffffff, bits 42:0, which cover every defined clear bit and the reserved bits between them (site 0xffab1cc0); its BTE error path writes bits 17 and 18 (site 0xffa94d40).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 42 | `xn_ii_invalid_cmd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 41 | `ii_xn_invalid_cmd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 40 | `ii_xn_req_cred_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 39 | `ii_xn_rep_cred_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 38 | `iiq_req_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 37 | `iiq_rep_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 36 | `ioq_req_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 35 | `ioq_rep_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 34 | `ioq_req_underflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 33 | `ioq_rep_underflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 32 | `cam_read_miss` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 31 | `cam_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 30 | `cam_intr_to` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 29 | `spur_rd_hdr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 18 | `e_bte_1` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 17 | `e_bte_0` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16 | `e_crazy` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15 | `e_prb_f` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14 | `e_prb_e` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 13 | `e_prb_d` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 12 | `e_prb_c` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 11 | `e_prb_b` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 10 | `e_prb_a` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 9 | `e_prb_9` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `e_prb_8` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `e_prb_0` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `bte_common_control`

BTE control, shared by both engines: the combined count of CRBs the two engines may use (which sets their bandwidth) and a soft reset used to recover after an error. Kernel: read, soft reset set, written back to reinitialise both BTE state machines after an error. Header name IIO_IBCR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `soft_reset` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `count` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `spurious_message`

Header of a spurious read response from Crosstalk, captured together with the spurious-sideband register. Header name IIO_IXSM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:60 | `didn` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 59:56 | `sidn` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 55:52 | `pactyp` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 51:47 | `tnum` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 46 | `ct` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 45:44 | `ds` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 43 | `gbr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 42 | `vbpm` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 41 | `error` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 40 | `bo` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 39:36 | `alt_pactyp` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 35:33 | `tag` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 31:0 | `byte_en` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `spurious_sideband`

Spurious sideband and valid flag for the capture in the spurious-message register. Header name IIO_IXSS.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7:0 | `sideband` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `llp_channel_test`

LLP channel test: access to the LLP's test port. Header name IIO_ILCT.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54 | `test_err_capture` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 53 | `test_clear` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 52:50 | `test_flit` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 49 | `test_cberr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 48 | `test_valid` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 47:28 | `test_data` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 27:20 | `test_mask` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 19:0 | `test_seed` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `error_packet_header_1`

Header, part 1, of an illegal incoming network packet, with a valid flag, an overrun flag and an error type (short or long request or reply). Header name IIO_IIEPH1. SAL 5.04 PROM: written 0 (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 50 | `valid` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 46 | `overrun` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 41:38 | `err_type` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 36:23 | `source` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 21:8 | `suppl` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 6:0 | `command` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `error_packet_header_2`

Header, part 2, of an illegal incoming network packet. Header name IIO_IIEPH2. SAL 5.04 PROM: written 0 (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 60 | `tail` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 49:3 | `address` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `sxb_access_protection`

Local access protection for the SXB. Same scheme as the main local access protection register. Header name IIO_ISLAPR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `region` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `sxb_access_override`

Override for the SXB access protection register. Header name IIO_ISLAPO.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `io_sbx_ovrride` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `wrapper_interrupt`

Wrapper interrupt: how long the II wrapper waits for an issued interrupt before it times it out and drops it. Header name IIO_IWI.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:48 | `intrpt_retry_period` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 39:32 | `timeout` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 23:0 | `prescale` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `wrapper_error_log`

Wrapper error log. Header name IIO_IWEL.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33 | `xn_ii_invalid_cmd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 32 | `ii_xn_invalid_cmd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 25 | `ii_xn_req_cred_over_under` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 24 | `ii_xn_rep_cred_over_under` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 17 | `iiq_req_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16 | `iiq_rep_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15 | `ioq_req_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14 | `ioq_rep_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 13 | `ioq_req_underflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 12 | `ioq_rep_underflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 9 | `cam_read_miss` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `cam_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `intr_timed_out` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `wrapper_control`

Wrapper control. Header name IIO_IWC. SAL 5.04 PROM: dma_byte_swap cleared by read-modify-write, no wait (site 0xffaad720).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `force_req_cred` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 62 | `force_rep_cred` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 49:44 | `iiq_depth` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 40:36 | `xn_req_iq_depth` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 32:28 | `xn_rep_iq_depth` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `ii_xn_cred_over_under_log` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `cam_read_lines_reset` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `dma_byte_swap` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `wrapper_status`

Wrapper status. Header name IIO_IWS.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12:8 | `xn_req_iq_credits` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4:0 | `xn_rep_iq_credits` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `wrapper_error_interrupt_mask`

Wrapper error interrupt mask. Header name IIO_IWEIM. SAL 5.04 PROM: ioq_req_overflow (bit 15) set by read-modify-write (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33 | `xn_ii_invalid_cmd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 32 | `ii_xn_invalid_cmd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 25 | `ii_xn_req_cred_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 24 | `ii_xn_rep_cred_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 17 | `iiq_req_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16 | `iiq_rep_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15 | `ioq_req_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14 | `ioq_rep_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 13 | `ioq_req_underflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 12 | `ioq_rep_underflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 9 | `cam_read_miss` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `cam_overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `intr_timed_out` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `prb_counter_adjust`

PRB counter adjust: a write moves a field of the matching widget's PRB entry up or down by one. For recovery after errors and resets. Header name IIO_IPCA.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9:8 | `field` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `adjust` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `wid` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `pio_read_entry_a`

PIO read table entry, part A: what the II remembers about an outstanding PIO read so it can build the network reply when Crosstalk answers. Eight entries. Header names IIO_IPRTE0_A to IIO_IPRTE7_A. SAL 5.04 PROM: each entry read (value discarded), then written 0 (site 0xffab1cc0).

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `vld` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 62:58 | `to_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 57:54 | `widget` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `pio_read_entry_b`

PIO read table entry, part B. Eight entries. Header names IIO_IPRTE0_B to IIO_IPRTE7_B. SAL 5.04 PROM: each entry read (value discarded), then written 0 (site 0xffab1cc0).

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `source` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 52:50 | `init` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 49:3 | `address` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `pio_deallocate`

PIO deallocation: a write frees one outstanding-read entry after a read response timeout. Kept for compatibility; SHub cleans up read timeouts itself. Header name IIO_IPDR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `init_rpcnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `pnd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 2:0 | `te` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_deallocate`

CRB entry deallocation: after software has handled an error captured in a CRB entry and cleared its mark bit, it writes the CRB number plus the pending bit here to return the entry to the free list. The pending bit reads back until the hardware has finished. Kernel: written to free a CRB, then polled until the pending bit clears. Header name IIO_ICDR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `pnd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `crb_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `ioq_fifo_depth`

Debug access to the depth of two internal II queues. Header name IIO_IFDR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `set_ioq_rp` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14:8 | `ioq_max_rp` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7 | `set_ioq_rq` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 6:0 | `ioq_max_rq` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `iiq_arbitration`

Inbound queue arbitration: a slow-drain mode for stress testing. Header name IIO_IIAP.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:8 | `rp_mls` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 5:0 | `rq_mls` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_management`

CRB management: valid and error-mark bit vectors for the 15 CRBs, the spurious-message flag and tuning fields. The header warns that writing it while the CRBs are active is dangerous. The kernel reads it to find marked or valid CRBs before cleaning up BTE errors. Kernel: read-only, to see which CRBs are valid or marked before BTE cleanup. Header name IIO_ICMR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `precise` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 49:35 | `crb_mark` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 34:20 | `crb_vld` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 19:16 | `fc_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 13 | `clr_rppd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 12 | `clr_rqpd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7:4 | `c_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 1 | `rd_hdr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `sp_msg` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_control`

CRB control: software control of the CRB table logic; takes priority over incoming Crosstalk and BTE requests. Header name IIO_ICCR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `pending` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15:8 | `cmd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `crb_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_timeout`

CRB timeout: the maximum timeout value. Header name IIO_ICTO.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `timeout` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_timeout_prescaler`

CRB timeout prescaler: how often the per-CRB timeout counters advance. Header name IIO_ICTP. SAL 5.04 PROM: written 0x1fffff (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:0 | `prescale` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_a`

CRB entry doubleword A (header IIO_ICRB0_A to IIO_ICRBE_A). Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).

Array of 15 registers, stride 48.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 57:54 | `sidn` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 53:49 | `tnum` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 48:2 | `addr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 1 | `vld` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `iow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_b`

CRB entry doubleword B (header IIO_ICRB0_B to IIO_ICRBE_B): holds the mark bit that flags an error entry, the 3-bit error code, the initiator and the incoming message type. The kernel reads it for every CRB when an II error interrupt arrives, clears the mark and then frees the entry through the deallocation register. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).

Array of 15 registers, stride 48.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `use_old` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 51:50 | `imsgtype` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 49:42 | `imsg` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 41:39 | `init` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 38:34 | `exc` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 26:16 | `ack_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15 | `resp` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14 | `ack` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 13 | `hold` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 12 | `wb` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 11 | `intvn` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 10 | `stall_ib` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 9 | `stall_intr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `stall_bte_0` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7 | `stall_bte_1` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 6 | `error` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 5:3 | `errcode` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 2 | `ln_uce` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 1 | `mark` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `xt_err` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_c`

CRB entry doubleword C (header IIO_ICRB0_C to IIO_ICRBE_C): the kernel reads the BTE number from it when the entry belongs to a BTE operation. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).

Array of 15 registers, stride 48.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 36:22 | `suppl` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 21 | `bo` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 20 | `resprqd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 19 | `gbr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 18 | `bte_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 17 | `ct` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16:15 | `size` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14:0 | `source` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_d`

CRB entry doubleword D (header IIO_ICRB0_D to IIO_ICRBE_D): carries the BTE-operation flag the kernel tests to tell BTE entries from others, and the per-entry timeout counter. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).

Array of 15 registers, stride 48.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `sleep` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 51:48 | `pr_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 47:44 | `pr_psc` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 43 | `bte_op` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 42:0 | `pa_be` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `crb_e`

CRB entry doubleword E (header IIO_ICRB0_E to IIO_ICRBE_E): read by the error handler together with the other four. Fifteen entries at a 0x30 stride; entry 0 is the base. SAL 5.04 PROM: all fifteen entries written 0 (site 0xffab1cc0).

Array of 15 registers, stride 48.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25 | `cvld` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 24 | `tvld` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 22:8 | `context` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7:0 | `timeout` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `spurious_crb_message_low`

Spurious message header, low 64 bits; valid when the spurious flag in the CRB management register is set. Header name IIO_ICSML.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `overflow` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 60:47 | `newsuppl_ex` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 46:0 | `tt_addr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `spurious_crb_message_mid`

Spurious message header, middle 64 bits. Header name IIO_ICSMM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10:0 | `tt_ack_cnt` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `spurious_crb_message_high`

Spurious message header, high bits. Header name IIO_ICSMH.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:56 | `tt_init` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 55:49 | `tt_device` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 48 | `rqcnt_ge_2` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 47 | `rqcnt_lt_2` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 46 | `rqcnt_ge_18` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 45 | `rqcnt_lt_18` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 44 | `rpcnt_ge_2` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 43 | `rpcnt_lt_2` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 42 | `rpcnt_ge_18` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 41 | `rpcnt_lt_18` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 40 | `rpcnt_ge_34` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 39 | `rpcnt_lt_34` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 38 | `match` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 37 | `cbn` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 36 | `tt_bte_num` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 35 | `tt_respreqd` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 34 | `tt_use_old` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 33:32 | `tt_imsgtype` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 31:24 | `tt_imsg` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 23 | `g_stall_ib` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 22 | `g_stall_il` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 21 | `g_stall_bte0` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 20 | `g_stall_bte1` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 19 | `tt_intvn` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 18 | `tt_resp` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 17 | `tt_ack` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16 | `tt_hold` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15 | `tt_wb` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 14:10 | `tt_exc` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 9 | `plusg` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 8 | `plusz` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7 | `mnusz` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 6 | `mnusg` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 5 | `sync` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `ft_active_o` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3 | `ft_wact_o` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 2 | `ft_cwact_o` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 1 | `xerr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `tt_vld` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `debug_submenu_select`

Debug submenu select: selects what the SHub debug unit shows from the II. Header name IIO_IDBSS.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20:16 | `iioclk_menu` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 10:8 | `fsbclk_wrapper_submenu` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 2:0 | `iioclk_core_submenu` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `bte_length_status`

BTE length and status, one block per engine (engine 1 is 64 KiB above engine 0). Length is in 128-byte cache lines. A write loads the length, sets busy and clears error; the engine counts the length down and clears busy at the end. On SHub 1 the kernel writes the length first and the control register second, which starts the transfer. Header names IIO_IBLS0 and IIO_IBLS1. Kernel: written with the length, read to see busy and error. SAL 5.04 PROM: read and written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes it with the length in lines and bit 20 set, then the notify word is polled. The PROM error-decoder name table calls it II_IBLS0 and II_IBLS1.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `busy` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 16 | `error` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 15:0 | `length` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `bte_source`

BTE source physical address, cache-line aligned. One per engine. Header names IIO_IBSA0 and IIO_IBSA1. Kernel: written with the source physical address, AS bits removed. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes the source with bits 63, 37 and 36 cleared. PROM name table: II_IBSA0, II_IBSA1.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 48:7 | `addr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `bte_destination`

BTE destination physical address, cache-line aligned. One per engine. Header names IIO_IBDA0 and IIO_IBDA1. Kernel: written with the destination physical address, AS bits removed. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes the destination with bits 63, 37 and 36 cleared. PROM name table: II_IBDA0, II_IBDA1.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 48:7 | `addr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `bte_control`

BTE control and terminate: the zero-fill and notify attributes. Writing it starts the transfer. The header says that reading it ends a transfer in progress, and that stopping one engine can disturb the other. The kernel uses notify (bit 4) always and zero-fill (bit 0) for memory clears. Header names IIO_IBCT0 and IIO_IBCT1. Kernel: the last write of a transfer, with the mode. SAL 5.04 PROM: read in both engines (plain 8-byte reads, values discarded) and never written by its set-up routine (site 0xffab1cc0), which by the header ends any transfer in progress; the block copy 0xffa952f0 writes it last, with the caller flags masked to 0x11 (zero fill and notify); the credit routine 0xffa7a960 writes 0x11; the two-engine copy test 0xffa96980 writes 0x10 (notify, a plain copy) to both engines, last of the writes (see the README). PROM name table: II_IBCT0, II_IBCT1, fields POISON, NOTIFY, ZEROFILL.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `poison` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 4 | `notify` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 0 | `zerofill` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `bte_notify`

BTE notification address: a cache-line-aligned address that receives the completion write (the header calls it a write-invalidate) carrying the final length and status. Header names IIO_IBNA0 and IIO_IBNA1. Kernel: written with the physical address of a notification word. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0); the block copy 0xffa952f0 writes the notify address with bits 63, 37 and 36 cleared, after IBDA and before IBCT. PROM name table: II_IBNA0, II_IBNA1, field ADDRESS<39:07>.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 48:7 | `addr` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `bte_interrupt`

BTE interrupt address: programmable level, node and PI unit of the processor to interrupt on completion. The kernel never uses it. Header names IIO_IBIA0 and IIO_IBIA1. SAL 5.04 PROM: written 0 in both engines (site 0xffab1cc0) and never otherwise. PROM name table: II_IBIA0, II_IBIA1, field NODEID.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `level` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 11:1 | `node_id` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `perf_control`

I/O performance control: selects which of 17 quantities each of the two performance counters measures. Header name IIO_IPCR. SAL 5.04 PROM: written 0 (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `icct` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 7:4 | `ippr1_c` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 3:0 | `ippr0_c` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

### Register `perf_profile`

I/O performance profiling: the counter values. Header name IIO_IPPR. SAL 5.04 PROM: read once, value discarded (site 0xffab1cc0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `ippr1` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |
| 31:0 | `ippr0` | established |  | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BTE_ENGINES` | 0x2 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Engines in the II; SHub 2 has four, in a different block (see the SHub 2 overlay of devices/shub). |
| `BTE_LEN_BITS` | 0x10 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Width of the length field of the BTE status register; the kernel's longest transfer is 65535 cache lines (BTE_LEN_MASK shifted by the line size). |
| `BTE_LINE_BYTES` | 0x80 | inferred | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | BTE unit of transfer. The kernel shifts the byte length by the L1 cache line size of the CPU (128 bytes on Itanium 2); the header's own text says lines are 128 bytes. |
| `CRB_STRIDE` | 0x30 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Distance between CRB entries: each entry takes six 8-byte slots, of which five (A to E) are registers (header macro IIO_ICRB_A: base plus 6 times 8 times the index). |
| `CRB_TIMEOUT_PRESCALE_PROM` | 0x1fffff | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Value the SAL 5.04 PROM writes to the CRB timeout prescaler (site 0xffab1cc0). |
| `ERROR_CLEAR_ALL` | 0x7ffffffffff | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Value the SAL 5.04 PROM writes to the error clear register (site 0xffab1cc0): bits 42:0, which cover every defined clear bit and the reserved bits between them. |
| `HUB_WIDGET_ID_MAX` | 0xf | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Highest widget number. |
| `ICRB_ECODE_AERR` | 0x3 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: access (protection) error. |
| `ICRB_ECODE_DERR` | 0x0 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: directory error caused by an II access. |
| `ICRB_ECODE_PERR` | 0x1 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: poison error on an I/O access. |
| `ICRB_ECODE_PRERR` | 0x5 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: partial read error. |
| `ICRB_ECODE_PWERR` | 0x4 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: partial write error. |
| `ICRB_ECODE_TOUT` | 0x6 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: timeout before deallocation. |
| `ICRB_ECODE_WERR` | 0x2 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: write error, for example an invalidate to a read-only line. |
| `ICRB_ECODE_XTERR` | 0x7 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB error code: incoming Crosstalk packet had its error bit set. |
| `ICRB_IMSGT_BTE` | 0x1 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB incoming message type: from a BTE. |
| `ICRB_IMSGT_CRB` | 0x3 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB incoming message type 3. The header marks it with question marks. |
| `ICRB_IMSGT_SN1NET` | 0x2 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB incoming message type: from the network. The header names it for SN1; whether SHub reuses the value for NUMAlink is not stated. |
| `ICRB_IMSGT_XTALK` | 0x0 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB incoming message type: from Crosstalk. |
| `ICRB_INIT_BTE0` | 0x1 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB initiator: BTE 0. |
| `ICRB_INIT_BTE1` | 0x5 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB initiator: BTE 1. Bit 2 of the initiator is the BTE number (kernel hub error code). |
| `ICRB_INIT_CRB` | 0x3 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB initiator 3; the header marks it with a question mark. |
| `ICRB_INIT_NET` | 0x2 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB initiator: the network (the header calls it SN1net). |
| `ICRB_INIT_XTALK` | 0x0 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | CRB initiator: Crosstalk. |
| `LLP_NULLTO_PROM` | 0x3 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Value the SAL 5.04 PROM leaves in the nullto field of the LLP control and status register (site 0xffab3780). |
| `NUM_BIG_WINDOWS` | 0x6 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Big windows the kernel treats as real; the seventh entry stands in for small window 0 (header comment: a permanent workaround for a processor-interface defect). |
| `NUM_CRBS` | 0xf | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Number of CRB entries, numbered 0 to 14 (the header's IIO_NUM_CRBS). |
| `NUM_ITTES` | 0x7 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Number of big-window translation entries. The header's manual numbering is 1 to 7, the kernel's 0 to 6. |
| `PROTECTION_OVERRIDE_KEY` | 0x53474972756c6573 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Value written to the local access protection override register: the ASCII string SGIrules (header text). |
| `WARM_RESET` | 0x100 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Bit 8 of the LLP control and status register; the header names it ILCSR_WARM_RESET. Same position as the warm_reset field. |
| `WCR_DST_CRD_PROM` | 0x4 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Destination credit count the SAL 5.04 PROM leaves in the widget control register (site 0xffab3580). |
| `WIDGET_ACCESS_OPEN` | 0xff01 | established | Linux v5.3 SGI SN2 platform I/O register header (GPL): names, offsets and field layouts; kernel use from the same tree's SN2 BTE and hub error code | Value the SAL 5.04 PROM writes to both the outbound and the inbound widget access register (site 0xffab30e0): widget 0 and widgets 8 to F open. Which bits that opens is the header's field layout (inferred). |
