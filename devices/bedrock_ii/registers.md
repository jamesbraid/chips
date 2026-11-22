<!-- generated from devices/bedrock_ii/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 e92c529cb2bbb265e3723d89fc5bd3d81da1e957ab0763d431d0d757616456a0 -->

# Bedrock I/O interface (II) registers: field layouts, block transfer engines and reset values

Offsets are hub-relative: the I/O interface is the block that starts 4 MiB into the node's register space. Field layouts come from the public Linux 2.5.40 SN1 headers, so they are established as header positions. Behaviour the headers describe only in comments is inferred. Reset values are unknown unless a header states one. Access directions the headers do not state are recorded as they are used by the public consumers. Where the header and a consumer disagree the field is listed with the disagreement in its doc.

Unit `bedrock_ii`, macro prefix `BEDROCK_II`.
Default source: Linux 2.5.40 SN1 register headers: names, offsets and field layouts.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `widget_id` | 0x400000 | r | 64 |  |  | 0x1c110049 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `widget_status` | 0x400008 | r | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: IIO_WSTAT (name and offset), ii_wstat structure; shipped IRIX kernel I/O error handlers (read sites) |
| `widget_control` | 0x400020 | rw | 64 |  |  | 0x4011 (established) | inferred |  |
| `local_access_protection` | 0x400100 | rw | 64 |  |  | 0xfffffffffffffff (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `protection_override` | 0x400108 | w | 64 |  |  | unknown | inferred |  |
| `outbound_widget_access` | 0x400110 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `inbound_widget_access` | 0x400118 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `inbound_device_error_mask` | 0x400120 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `link_control` | 0x400128 | rw | 64 |  |  | 0x3fc03ff040a (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `llp_log` | 0x400130 | rw | 64 |  |  | 0x0 (established) | inferred |  |
| `interrupt_destination` | 0x400138 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `graphics_map` | 0x400140 | rw | 64 | 2 |  | 0x0 (established) | inferred |  |
| `scratch` | 0x400150 | rw | 64 | 2 |  | 0x0 (established) | inferred |  |
| `translation_table_entry` | 0x400160 | rw | 64 | 7 |  | 0x0 (established) | inferred |  |
| `pio_request_buffer_w0` | 0x400198 | rw | 64 |  |  | 0xf (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `pio_request_buffer_w8` | 0x4001a0 | rw | 64 | 8 |  | 0xf (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `credit_count_timeout` | 0x4001e0 | rw | 64 |  |  | 0x3ffffff (established) | inferred |  |
| `misc_error_mask` | 0x4001e8 | rw | 64 |  |  | 0x111 (established) | inferred |  |
| `crosstalk_timeout_threshold` | 0x4001f0 | rw | 64 |  |  | 0xfffffff03ffffff (established) | inferred |  |
| `error_clear` | 0x4001f8 | w | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_global_control` | 0x400200 | rw | 64 |  |  | 0x8 (established) | inferred | Linux 2.5.40 SN1 register headers: IIO_IBCR (name and offset) |
| `crosstalk_spurious_message` | 0x400208 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure |
| `crosstalk_spurious_sideband` | 0x400210 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IXSS (name and offset), ii_ixss structure |
| `llp_channel_test` | 0x400218 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure |
| `incoming_error_header_1` | 0x400220 | r | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: IIO_IIEPH1 (name and offset), ii_iieph1 structure; shipped IRIX kernel I/O error handlers (read sites) |
| `incoming_error_header_2` | 0x400228 | r | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: IIO_IIEPH2 (name and offset), ii_iieph2 structure; shipped IRIX kernel I/O error handlers (read sites) |
| `prb_counter_adjust` | 0x400300 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IPCA (name and offset), ii_ipca structure |
| `pio_read_address` | 0x400308 | rw | 64 | 8 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `pio_deallocation` | 0x400388 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IPDR (name and offset), ii_ipdr structure |
| `crb_deallocation` | 0x400390 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_ICDR (name and offset), ii_icdr structure |
| `ioq_fifo_depth` | 0x400398 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IFDR (name and offset), ii_ifdr structure |
| `iiq_arbitration` | 0x4003a0 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IIAP (name and offset), ii_iiap structure |
| `request_buffer_management` | 0x4003a8 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `request_buffer_control` | 0x4003b0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crb_timeout` | 0x4003b8 | rw | 64 |  |  | 0xff (established) | inferred |  |
| `crb_timeout_prescaler` | 0x4003c0 | rw | 64 |  |  | 0xffffff (established) | inferred |  |
| `crb_a` | 0x400400 | r | 64 | 15 |  | 0x0 (established) | inferred |  |
| `crb_b` | 0x400408 | r | 64 | 15 |  | 0x0 (established) | inferred |  |
| `crb_c` | 0x400410 | r | 64 | 15 |  | 0x0 (established) | inferred |  |
| `crb_d` | 0x400418 | r | 64 | 15 |  | 0x0 (established) | inferred |  |
| `crb_spurious_message_low` | 0x400600 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_ICSML (name and offset), ii_icsml structure |
| `crb_spurious_message_high` | 0x400608 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure |
| `debug_submenu_select` | 0x400610 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IDBSS (name and offset), ii_idbss structure |
| `bte_length_status` | 0x410000 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_source` | 0x410008 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_destination` | 0x410010 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_control` | 0x410018 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_notification_address` | 0x410020 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_interrupt_address` | 0x410028 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `performance_control` | 0x430000 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IPCR (name and offset), ii_ipcr structure |
| `performance_profiling` | 0x430008 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: IIO_IPPR (name and offset), ii_ippr structure |

### Register `widget_id`

Widget identification. Echoes the manufacturer and revision fields of the local block's revision register and carries the Bedrock's crosstalk part. Its value follows the local revision register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `revision` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 27:12 | `part` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 11:1 | `manufacturer` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `widget_status`

Crosstalk widget status. The register's name and layout are from the header; the header gives no access type, so the census reads it as read-only and the register is graded inferred. The shipped kernel's I/O error handlers only read it, which agrees with r but does not show the register cannot be written. The reset is the power-on table value recorded for this offset in the census unit. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_WSTAT; the header's short name is WSTAT.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `crazy` | established |  | Linux 2.5.40 SN1 register headers: IIO_WSTAT (name and offset), ii_wstat structure | Member w_crazy of the header's ii_wstat structure, 1 bit. The shipped kernel's I/O error handler tests this bit as the error flag (the name crazy is the header's). |
| 23:16 | `llp_tx_cnt` | established |  | Linux 2.5.40 SN1 register headers: IIO_WSTAT (name and offset), ii_wstat structure | Member w_llp_tx_cnt of the header's ii_wstat structure, 8 bits. |
| 9 | `tx_mx_rty` | established |  | Linux 2.5.40 SN1 register headers: IIO_WSTAT (name and offset), ii_wstat structure | Member w_tx_mx_rty of the header's ii_wstat structure, 1 bit. The shipped kernel's I/O error handler tests this bit as the reason when crazy is set. |
| 5 | `xt_tail_to` | established |  | Linux 2.5.40 SN1 register headers: IIO_WSTAT (name and offset), ii_wstat structure | Member w_xt_tail_to of the header's ii_wstat structure, 1 bit. The shipped kernel's I/O error handler tests this bit as the reason when crazy is set. |
| 4 | `xt_crd_to` | established |  | Linux 2.5.40 SN1 register headers: IIO_WSTAT (name and offset), ii_wstat structure | Member w_xt_crd_to of the header's ii_wstat structure, 1 bit. The shipped kernel's I/O error handler tests this bit as the reason when crazy is set. |
| 3:0 | `pending` | established |  | Linux 2.5.40 SN1 register headers: IIO_WSTAT (name and offset), ii_wstat structure | Member w_pending of the header's ii_wstat structure, 4 bits. |

### Register `widget_control`

Crosstalk widget control register (the header's IO widget control). The header states no access type, so rw is assumed. No field layout is recorded here. Field layout added from the header's structure; the rsvd mask is its members named reserved (header naming only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:18 | `e_thresh` | established |  | Linux 2.5.40 SN1 register headers: ii_wcr structure | Member w_e_thresh of the header's ii_wcr structure, 5 bits. |
| 17 | `dir_con` | established |  | Linux 2.5.40 SN1 register headers: ii_wcr structure | Member w_dir_con of the header's ii_wcr structure, 1 bit. |
| 16 | `f_bad_pkt` | established |  | Linux 2.5.40 SN1 register headers: ii_wcr structure | Member w_f_bad_pkt of the header's ii_wcr structure, 1 bit. |
| 15:13 | `dst_credit` | established |  | Linux 2.5.40 SN1 register headers: ii_wcr structure | Member w_dst_crd of the header's ii_wcr structure, 3 bits. |
| 4 | `tag_mode` | established |  | Linux 2.5.40 SN1 register headers: ii_wcr structure | Member w_tag of the header's ii_wcr structure, 1 bit. |
| 3:0 | `widget_id` | established |  | Linux 2.5.40 SN1 register headers: ii_wcr structure | Member w_wid of the header's ii_wcr structure, 4 bits. |

### Register `local_access_protection`

One enable bit per processor region. The header states that at reset every region is permitted, and gives no number. The shipped Origin 350 PROM register table gives sixty set bits, 0x0fffffffffffffff, so the top four bits of the 64-bit field are clear at reset; that value is used. A processor PIO is performed only when the requester's region bit is set; otherwise it gets an error response. Readable only by permitted regions or through the local alias. The table record behind this reset (decoded from the firmware image) is one field spanning bits 63:0 whose reset is 0x0fffffffffffffff; the same record appears for this register, the local block's processor permission and its region present register, and the table does write 64 set bits for single 64-bit fields elsewhere (three registers of the processor interface block and the first register of the memory-directory block), so the four clear bits are not how the table writes all-ones. Whether the silicon reads them clear is not settled by any public source.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `region_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | One bit per region. |

### Register `protection_override`

Writing the 64-bit ASCII key the SN1 tree names sets the writer's own region bit in local access protection. A write through the local alias does nothing. The header union gives a nine-bit field while its description says a 64-bit key, a self-contradiction. No public consumer writes the register.

### Register `outbound_widget_access`

Qualifies every PIO and graphics write the Bedrock launches toward a widget. The stock PROM enables widget 0 and widgets 8 to F in it; IRIX saves it, writes zero and restores it around PIO request-buffer programming.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `widgets_8_to_f` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | One bit per widget, widget 8 at bit 8 through widget 15 at bit 15. |
| 0 | `widget_0` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `inbound_widget_access`

Qualifies every request a widget launches at the Bedrock, including DMA and interrupt writes. The stock PROM enables widget 0 and widgets 8 to F. IRIX and the Itanium port read it only. The header's text also exempts incoming replies from the mask.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `widgets_8_to_f` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 0 | `widget_0` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `inbound_device_error_mask`

Eight bits per widget, one per DMA master (device) 0 to 7. A request passes when its device bit and the widget's inbound bit are both set. The header says the bits are set by writing a one. IRIX clears a device by writing back the old value with the device bit cleared, which under write-one-to-set clears nothing. Which behaviour the hardware has is unknown. Hardware clears a bit itself when an error requires the device to be shut out.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `widget_15` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 55:48 | `widget_14` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 47:40 | `widget_13` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 39:32 | `widget_12` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 31:24 | `widget_11` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 23:16 | `widget_10` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 15:8 | `widget_9` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 7:0 | `widget_8` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `link_control`

Link control and status. Both public Linux ports read bit 13 and skip the node's crosstalk when it is clear. The stock PROM reads it before touching any widget and then sets bit 8. The header gives no meaning for the four values of the status field, and its remote-power bit has no text. That the bit means link up is inferred from how the I/O error interrupt set-up uses it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41:32 | `max_burst` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 27:26 | `data_available_select` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 25:16 | `max_retry` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 14 | `remote_power` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Named by the Linux header only; no text describes it. The IRIX source header, which describes an earlier layout of this register, marks bits 15:14 reserved, so it does not confirm the bit. |
| 13:12 | `link_status` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Bit 13 is link up. The meaning of the two-bit field's other values is unknown. |
| 11 | `eight_bit_mode` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 10 | `link_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 8 | `warm_reset` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 5:0 | `null_timeout` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `llp_log`

IO LLP log register: the link-level protocol log, next to link_control. The header states no access type, so rw is assumed. No field layout is recorded here.

### Register `interrupt_destination`

Destination of every II-detected non-BTE error interrupt. The header's struct puts the node at bits 16:9 and the PI select at bit 8; its companion macros put the node at 15:8. The struct governs: the Itanium consumer writes through it. The PI register address is hard-coded per PI select (see the PI0 and PI1 constants).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33 | `forwarded_pi1` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Forwarded-interrupt pending for PI1. |
| 32 | `forwarded_pi0` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Forwarded-interrupt pending for PI0. |
| 28 | `sent` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Cleared by the Itanium handler and by its error clear. The meaning is inferred. The IRIX source header places an interrupt-sent field at the same bit and gives it no description. |
| 24 | `enable` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Set at init by the Itanium consumer. The meaning is inferred from its name. The IRIX source header places a field of this name at the same bit and gives it no description. |
| 16:9 | `node` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 8 | `pi_select` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 6:0 | `level` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `graphics_map`

IO graphics node-widget map, two registers (0 and 1) eight bytes apart. The header states no access type, so rw is assumed. No field layout is recorded here.

Array of 2 registers, stride 8.

### Register `scratch`

IO scratch registers 0 and 1, eight bytes apart. The header states no access type, so rw is assumed. No field layout is recorded here.

Array of 2 registers, stride 8.

### Register `translation_table_entry`

IO translation table entries 1 to 7, eight bytes apart; the first is entry 1. The header states no access type, so rw is assumed. No field layout is recorded here. Field layout added from the header's structure; the rsvd mask is its members named reserved (header naming only).

Array of 7 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `io_space` | established |  | Linux 2.5.40 SN1 register headers: ii_itte1 structure | Member i_iosp of the header's ii_itte1 structure, 1 bit. |
| 11:8 | `widget_number` | established |  | Linux 2.5.40 SN1 register headers: ii_itte1 structure | Member i_w_num of the header's ii_itte1 structure, 4 bits. |
| 4:0 | `offset` | established |  | Linux 2.5.40 SN1 register headers: ii_itte1 structure | Member i_offset of the header's ii_itte1 structure, 5 bits. |

### Register `pio_request_buffer_w0`

Per-widget PIO flow control for widget 0. Writing the credit field re-arms the spurious-write detector, which persists until the register is written again even when error clear is used. The Itanium probe writes credits 1 for a crossbar at widget 0 and 3 when the widget is directly connected.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `multiple_errors` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 51 | `spurious_read` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 50 | `spurious_write` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 49 | `read_timeout` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 48 | `error` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 47:43 | `overflow_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 42 | `fire_and_forget` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 41:40 | `mode` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 37:24 | `nack_counter_b` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 21:8 | `nack_counter_a` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 7:0 | `credits` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `pio_request_buffer_w8`

PIO request buffers for widgets 8 to F, eight registers at a stride of eight bytes; the first is widget 8. Same layout as the widget 0 entry.

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `multiple_errors` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 51 | `spurious_read` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 50 | `spurious_write` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 49 | `read_timeout` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 48 | `error` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 47:43 | `overflow_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 42 | `fire_and_forget` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 41:40 | `mode` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 37:24 | `nack_counter_b` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 21:8 | `nack_counter_a` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 7:0 | `credits` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `credit_count_timeout`

IO crosstalk credit count timeout. The header states no access type, so rw is assumed. No field layout is recorded here. Field layout added from the header's structure; the rsvd mask is its members named reserved (header naming only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:0 | `timeout` | established |  | Linux 2.5.40 SN1 register headers: ii_ixcc structure | Member i_time_out of the header's ii_ixcc structure, 26 bits. |

### Register `misc_error_mask`

Write-one-to-set per the header. The header's description says the hub clears each field when an error requires that source to be shut down and that software sets a field by writing one. The companion header's macro comments instead call bits 0, 4 and 8 shut-down flags, and the Itanium error handler reads them that way. The register description and the recovery write govern. No Linux header states the reset value. The later chip's recovery write re-enables a source by setting its bit, which agrees with the value in the PROM register table. The shipped kernel's I/O error handlers read this register; a hand-written row once recorded it as read-only on that basis, but reads alone do not show it cannot be written, so rw stays.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `clear_precise` | established |  |  |  |
| 8 | `bte_1_enable` | established |  |  |  |
| 4 | `bte_0_enable` | established |  |  |  |
| 0 | `widget_0_enable` | established |  |  |  |

### Register `crosstalk_timeout_threshold`

IO crosstalk timeout threshold. The header states no access type, so rw is assumed. No field layout is recorded here. Field layout added from the header's structure; the rsvd mask is its members named reserved (header naming only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:55 | `read_response_timeout` | established |  | Linux 2.5.40 SN1 register headers: ii_ixtt structure | Member i_rrsp_to of the header's ii_ixtt structure, 5 bits. |
| 54:32 | `read_response_prescale` | established |  | Linux 2.5.40 SN1 register headers: ii_ixtt structure | Member i_rrsp_ps of the header's ii_ixtt structure, 23 bits. |
| 25:0 | `tail_timeout` | established |  | Linux 2.5.40 SN1 register headers: ii_ixtt structure | Member i_tail_to of the header's ii_ixtt structure, 26 bits. |

### Register `error_clear`

Write-one-to-clear. Clears the named bits elsewhere in the unit. The Itanium probe writes all ones; a bit written with one reads back as zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `forwarded_pi1` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 30 | `forwarded_pi0` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 29 | `spurious_read_header` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 28 | `internal` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 18 | `bte_1` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 17 | `bte_0` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 16 | `crazy` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 15:8 | `request_buffers_8_to_f` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 0 | `request_buffer_0` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `bte_global_control`

IO BTE control register: the one register that controls both transfer engines, as against bte_control, which each engine has. The header states no access type, so rw is assumed. No field layout is recorded here. Field layout added from the header's structure; the rsvd mask is its members named reserved (header naming only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `soft_reset` | established |  | Linux 2.5.40 SN1 register headers: ii_ibcr structure | Member i_soft_reset of the header's ii_ibcr structure, 1 bit. |
| 3:0 | `count` | established |  | Linux 2.5.40 SN1 register headers: ii_ibcr structure | Member i_count of the header's ii_ibcr structure, 4 bits. |

### Register `crosstalk_spurious_message`

Crosstalk spurious message: the header fields of the last incoming Crosstalk packet that was dropped. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IXSM; the header's short name is IXSM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:60 | `didn` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_didn of the header's ii_ixsm structure, 4 bits. |
| 59:56 | `sidn` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_sidn of the header's ii_ixsm structure, 4 bits. |
| 55:52 | `pactyp` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_pactyp of the header's ii_ixsm structure, 4 bits. |
| 51:47 | `tnum` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_tnum of the header's ii_ixsm structure, 5 bits. |
| 46 | `ct` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_ct of the header's ii_ixsm structure, 1 bit. |
| 45:44 | `ds` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_ds of the header's ii_ixsm structure, 2 bits. |
| 43 | `gbr` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_gbr of the header's ii_ixsm structure, 1 bit. |
| 42 | `vbpm` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_vbpm of the header's ii_ixsm structure, 1 bit. |
| 41 | `error` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_error of the header's ii_ixsm structure, 1 bit. |
| 40 | `bo` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_bo of the header's ii_ixsm structure, 1 bit. |
| 39:36 | `alt_pactyp` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_alt_pactyp of the header's ii_ixsm structure, 4 bits. |
| 35:33 | `tag` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_tag of the header's ii_ixsm structure, 3 bits. |
| 31:0 | `byte_en` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSM (name and offset), ii_ixsm structure | Member i_byte_en of the header's ii_ixsm structure, 32 bits. |

### Register `crosstalk_spurious_sideband`

Crosstalk spurious sideband. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IXSS; the header's short name is IXSS.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSS (name and offset), ii_ixss structure | Member i_valid of the header's ii_ixss structure, 1 bit. |
| 7:0 | `sideband` | established |  | Linux 2.5.40 SN1 register headers: IIO_IXSS (name and offset), ii_ixss structure | Member i_sideband of the header's ii_ixss structure, 8 bits. |

### Register `llp_channel_test`

Link layer channel test. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_ILCT; the header's short name is ILCT.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54 | `test_err_capture` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_err_capture of the header's ii_ilct structure, 1 bit. |
| 53 | `test_clear` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_clear of the header's ii_ilct structure, 1 bit. |
| 52:50 | `test_flit` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_flit of the header's ii_ilct structure, 3 bits. |
| 49 | `test_cberr` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_cberr of the header's ii_ilct structure, 1 bit. |
| 48 | `test_valid` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_valid of the header's ii_ilct structure, 1 bit. |
| 47:28 | `test_data` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_data of the header's ii_ilct structure, 20 bits. |
| 27:20 | `test_mask` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_mask of the header's ii_ilct structure, 8 bits. |
| 19:0 | `test_seed` | established |  | Linux 2.5.40 SN1 register headers: IIO_ILCT (name and offset), ii_ilct structure | Member i_test_seed of the header's ii_ilct structure, 20 bits. |

### Register `incoming_error_header_1`

Incoming error packet header, part 1. The register's name and layout are from the header; the header gives no access type. The shipped kernel's I/O error handlers only read it, so access is r; that is a reading of observed use, not a stated access, and the register stays graded inferred. The reset is the power-on table value recorded for this offset in the census unit. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IIEPH1; the header's short name is IIEPH1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 44 | `valid` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH1 (name and offset), ii_iieph1 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_valid of the header's ii_iieph1 structure, 1 bit. The shipped kernel's print routine tests this bit before printing the header. |
| 40 | `overrun` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH1 (name and offset), ii_iieph1 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_overrun of the header's ii_iieph1 structure, 1 bit. The shipped kernel's print routine reads the same bits. |
| 35:32 | `err_type` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH1 (name and offset), ii_iieph1 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_err_type of the header's ii_iieph1 structure, 4 bits. The shipped kernel's print routine names 2 short request packet, 3 short reply packet, 4 long request packet and 5 long reply packet; any other value prints as unknown. |
| 30:20 | `source` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH1 (name and offset), ii_iieph1 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_source of the header's ii_iieph1 structure, 11 bits. The shipped kernel's print routine reads the same bits. |
| 18:8 | `suppl` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH1 (name and offset), ii_iieph1 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_suppl of the header's ii_iieph1 structure, 11 bits. The shipped kernel's print routine reads the same bits. |
| 6:0 | `command` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH1 (name and offset), ii_iieph1 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_command of the header's ii_iieph1 structure, 7 bits. The shipped kernel's print routine reads the same bits. |

### Register `incoming_error_header_2`

Incoming error packet header, part 2. The register's name and layout are from the header; the header gives no access type. The shipped kernel's I/O error handlers only read it, so access is r; that is a reading of observed use, not a stated access, and the register stays graded inferred. The reset is the power-on table value recorded for this offset in the census unit. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IIEPH2; the header's short name is IIEPH2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `tail` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH2 (name and offset), ii_iieph2 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_tail of the header's ii_iieph2 structure, 1 bit. The shipped kernel's print routine reads the same bits. |
| 37:0 | `address` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIEPH2 (name and offset), ii_iieph2 structure; shipped IRIX kernel I/O error handlers (print routine) | Member i_address of the header's ii_iieph2 structure, 38 bits. The shipped kernel's print routine reads the same bits. |

### Register `prb_counter_adjust`

PRB counter adjust. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IPCA; the header's short name is IPCA.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9:8 | `field` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPCA (name and offset), ii_ipca structure | Member i_field of the header's ii_ipca structure, 2 bits. |
| 4 | `adjust` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPCA (name and offset), ii_ipca structure | Member i_adjust of the header's ii_ipca structure, 1 bit. |
| 3:0 | `wid` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPCA (name and offset), ii_ipca structure | Member i_wid of the header's ii_ipca structure, 4 bits. |

### Register `pio_read_address`

Outstanding-read table that the read-response timeout works on. Access direction is not stated by the header. No consumer is recorded.

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 62:58 | `timeout_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 57:54 | `widget` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 51:44 | `source` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 43:41 | `initiator` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 40:3 | `address` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `pio_deallocation`

PIO deallocation. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IPDR; the header's short name is IPDR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `init_rpcnt` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPDR (name and offset), ii_ipdr structure | Member i_init_rpcnt of the header's ii_ipdr structure, 1 bit. |
| 4 | `pnd` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPDR (name and offset), ii_ipdr structure | Member i_pnd of the header's ii_ipdr structure, 1 bit. |
| 2:0 | `te` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPDR (name and offset), ii_ipdr structure | Member i_te of the header's ii_ipdr structure, 3 bits. |

### Register `crb_deallocation`

CRB entry deallocation. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_ICDR; the header's short name is ICDR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `pnd` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICDR (name and offset), ii_icdr structure | Member i_pnd of the header's ii_icdr structure, 1 bit. |
| 3:0 | `crb_num` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICDR (name and offset), ii_icdr structure | Member i_crb_num of the header's ii_icdr structure, 4 bits. |

### Register `ioq_fifo_depth`

IOQ FIFO depth. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IFDR; the header's short name is IFDR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `set_ioq_rp` | established |  | Linux 2.5.40 SN1 register headers: IIO_IFDR (name and offset), ii_ifdr structure | Member i_set_ioq_rp of the header's ii_ifdr structure, 1 bit. |
| 14:8 | `ioq_max_rp` | established |  | Linux 2.5.40 SN1 register headers: IIO_IFDR (name and offset), ii_ifdr structure | Member i_ioq_max_rp of the header's ii_ifdr structure, 7 bits. |
| 7 | `set_ioq_rq` | established |  | Linux 2.5.40 SN1 register headers: IIO_IFDR (name and offset), ii_ifdr structure | Member i_set_ioq_rq of the header's ii_ifdr structure, 1 bit. |
| 6:0 | `ioq_max_rq` | established |  | Linux 2.5.40 SN1 register headers: IIO_IFDR (name and offset), ii_ifdr structure | Member i_ioq_max_rq of the header's ii_ifdr structure, 7 bits. |

### Register `iiq_arbitration`

IIQ arbitration parameters. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IIAP; the header's short name is IIAP.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:8 | `rp_mls` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIAP (name and offset), ii_iiap structure | Member i_rp_mls of the header's ii_iiap structure, 6 bits. |
| 5:0 | `rq_mls` | established |  | Linux 2.5.40 SN1 register headers: IIO_IIAP (name and offset), ii_iiap structure | Member i_rq_mls of the header's ii_iiap structure, 6 bits. |

### Register `request_buffer_management`

Request buffer management. The header warns that writing it while the buffers are not quiescent can have catastrophic side effects. The Itanium probe writes a count of 0xf and nothing else.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `precise` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 49:35 | `marks` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 34:20 | `valid_bits` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 19:16 | `flow_control_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 13 | `clear_pending_bit_13` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | The second of the two clear-pending bits. |
| 12 | `clear_pending_bit_12` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | The header's name is clear pending; this is the first of two clear-pending bits. |
| 7:4 | `count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 1 | `read_header` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 0 | `spurious_message` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `request_buffer_control`

Software control of the request buffers. It has priority over crosstalk and BTE requests. The header names the commands nop, wake, timeout, eject and flush; their numeric codes are not given in the header and are unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `pending` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 15:8 | `command` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Command code. The header names nop, wake, timeout, eject and flush; the codes are unknown. |
| 3:0 | `entry` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `crb_timeout`

IO CRB timeout. The header states no access type, so rw is assumed. No field layout is recorded here. Field layout added from the header's structure; the rsvd mask is its members named reserved (header naming only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `timeout` | established |  | Linux 2.5.40 SN1 register headers: ii_icto structure | Member i_timeout of the header's ii_icto structure, 8 bits. |

### Register `crb_timeout_prescaler`

IO CRB timeout prescaler. The header states no access type, so rw is assumed. No field layout is recorded here. Field layout added from the header's structure; the rsvd mask is its members named reserved (header naming only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:0 | `prescale` | established |  | Linux 2.5.40 SN1 register headers: ii_ictp structure | Member i_prescale of the header's ii_ictp structure, 24 bits. |

### Register `crb_a`

First word of the request-buffer table. Entry i (0 to 14) has three 64-bit words, crb_a, crb_b and crb_c, at these offsets plus 0x20 times i. The header names the fourth word of each entry, crb_d, as well; the field meanings of the entry words are not given by any source held here.

Array of 15 registers, stride 32.

### Register `crb_b`

Array of 15 registers, stride 32.

### Register `crb_c`

Array of 15 registers, stride 32.

### Register `crb_d`

Fourth word of each request-buffer entry. Entry i (0 to 14) is at this offset plus 0x20 times i. Read-only is carried over from the sibling words crb_a to crb_c and is inferred.

Array of 15 registers, stride 32.

### Register `crb_spurious_message_low`

CRB spurious message, low word. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_ICSML; the header's short name is ICSML.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `overflow` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSML (name and offset), ii_icsml structure | Member i_overflow of the header's ii_icsml structure, 1 bit. |
| 59:49 | `newsuppl_ex` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSML (name and offset), ii_icsml structure | Member i_newsuppl_ex of the header's ii_icsml structure, 11 bits. |
| 48:38 | `tt_ack_cnt` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSML (name and offset), ii_icsml structure | Member i_tt_ack_cnt of the header's ii_icsml structure, 11 bits. |
| 37:0 | `tt_addr` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSML (name and offset), ii_icsml structure | Member i_tt_addr of the header's ii_icsml structure, 38 bits. |

### Register `crb_spurious_message_high`

CRB spurious message, high word. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_ICSMH; the header's short name is ICSMH.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:56 | `tt_init` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_init of the header's ii_icsmh structure, 3 bits. |
| 55:49 | `tt_device` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_device of the header's ii_icsmh structure, 7 bits. |
| 48 | `rqcnt_ge_2` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rqcnt_ge_2 of the header's ii_icsmh structure, 1 bit. |
| 47 | `rqcnt_lt_2` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rqcnt_lt_2 of the header's ii_icsmh structure, 1 bit. |
| 46 | `rqcnt_ge_18` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rqcnt_ge_18 of the header's ii_icsmh structure, 1 bit. |
| 45 | `rqcnt_lt_18` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rqcnt_lt_18 of the header's ii_icsmh structure, 1 bit. |
| 44 | `rpcnt_ge_2` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rpcnt_ge_2 of the header's ii_icsmh structure, 1 bit. |
| 43 | `rpcnt_lt_2` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rpcnt_lt_2 of the header's ii_icsmh structure, 1 bit. |
| 42 | `rpcnt_ge_18` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rpcnt_ge_18 of the header's ii_icsmh structure, 1 bit. |
| 41 | `rpcnt_lt_18` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rpcnt_lt_18 of the header's ii_icsmh structure, 1 bit. |
| 40 | `rpcnt_ge_34` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rpcnt_ge_34 of the header's ii_icsmh structure, 1 bit. |
| 39 | `rpcnt_lt_34` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_rpcnt_lt_34 of the header's ii_icsmh structure, 1 bit. |
| 38 | `match` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_match of the header's ii_icsmh structure, 1 bit. |
| 37 | `cbn` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_cbn of the header's ii_icsmh structure, 1 bit. |
| 36 | `tt_bte_num` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_bte_num of the header's ii_icsmh structure, 1 bit. |
| 35 | `tt_respreqd` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_respreqd of the header's ii_icsmh structure, 1 bit. |
| 34 | `tt_use_old` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_use_old of the header's ii_icsmh structure, 1 bit. |
| 33:32 | `tt_imsgtype` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_imsgtype of the header's ii_icsmh structure, 2 bits. |
| 31:24 | `tt_imsg` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_imsg of the header's ii_icsmh structure, 8 bits. |
| 23 | `g_stall_ib` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_g_stall_ib of the header's ii_icsmh structure, 1 bit. |
| 22 | `g_stall_il` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_g_stall_il of the header's ii_icsmh structure, 1 bit. |
| 21 | `g_stall_bte0` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_g_stall_bte0 of the header's ii_icsmh structure, 1 bit. |
| 20 | `g_stall_bte1` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_g_stall_bte1 of the header's ii_icsmh structure, 1 bit. |
| 19 | `tt_intvn` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_intvn of the header's ii_icsmh structure, 1 bit. |
| 18 | `tt_resp` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_resp of the header's ii_icsmh structure, 1 bit. |
| 17 | `tt_ack` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_ack of the header's ii_icsmh structure, 1 bit. |
| 16 | `tt_hold` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_hold of the header's ii_icsmh structure, 1 bit. |
| 15 | `tt_wb` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_wb of the header's ii_icsmh structure, 1 bit. |
| 14:10 | `tt_exc` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_exc of the header's ii_icsmh structure, 5 bits. |
| 9 | `plusg` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_plusg of the header's ii_icsmh structure, 1 bit. |
| 8 | `plusz` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_plusz of the header's ii_icsmh structure, 1 bit. |
| 7 | `mnusz` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_mnusz of the header's ii_icsmh structure, 1 bit. |
| 6 | `mnusg` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_mnusg of the header's ii_icsmh structure, 1 bit. |
| 5 | `sync` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_sync of the header's ii_icsmh structure, 1 bit. |
| 4 | `ft_active_o` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_ft_active_o of the header's ii_icsmh structure, 1 bit. |
| 3 | `ft_wact_o` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_ft_wact_o of the header's ii_icsmh structure, 1 bit. |
| 2 | `ft_cwact_o` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_ft_cwact_o of the header's ii_icsmh structure, 1 bit. |
| 1 | `xerr` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_xerr of the header's ii_icsmh structure, 1 bit. |
| 0 | `tt_vld` | established |  | Linux 2.5.40 SN1 register headers: IIO_ICSMH (name and offset), ii_icsmh structure | Member i_tt_vld of the header's ii_icsmh structure, 1 bit. |

### Register `debug_submenu_select`

Debug submenu select. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IDBSS; the header's short name is IDBSS.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2:0 | `submenu` | established |  | Linux 2.5.40 SN1 register headers: IIO_IDBSS (name and offset), ii_idbss structure | Member i_submenu of the header's ii_idbss structure, 3 bits. |

### Register `bte_length_status`

One copy per block transfer engine; engine 1's block is 64 KiB above engine 0's. A legitimate write sets busy and clears error, with the length loaded in cache lines; the engine decrements the length per line and clears busy at the end.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `busy` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 16 | `error` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 15:0 | `length_lines` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Length in 128-byte cache lines. |

### Register `bte_source`

Source physical address of the transfer. Low seven bits are zero (128-byte lines). After a transfer the register reads the address one line past the last line moved, or the failed line after a data error; hardware behaviour here is unknown.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 39:7 | `address` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `bte_destination`

Destination physical address of the transfer. Same layout and end-of-transfer behaviour as the source register.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 39:7 | `address` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `bte_control`

Writing this register starts the transfer. Reading it terminates any transfer in progress, and stopping one engine can disturb the other. The header states this protocol; the start-on-write and terminate-on-read behaviour is inferred from the header's comments, and whether busy is observable after a start is unknown.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `poison` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Poison behaviour. Its effect is not described in any public source. |
| 4 | `notify` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Write the final length-status word to the notification address on completion. |
| 0 | `zero_fill` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Zero-fill the destination instead of copying from the source. |

### Register `bte_notification_address`

Address that receives the completion write-invalidate. The Itanium consumer sets its line to all ones before the start and expects the final length-status value to be deposited there.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 39:7 | `address` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `bte_interrupt_address`

Where the engine's completion interrupt goes. No public consumer programs it. The PROM's hub check does.

Array of 2 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `level` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 8:1 | `node` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 0 | `pi_select` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `performance_control`

Performance control. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IPCR; the header's short name is IPCR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `icct` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPCR (name and offset), ii_ipcr structure | Member i_icct of the header's ii_ipcr structure, 8 bits. |
| 7:4 | `ippr1_c` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPCR (name and offset), ii_ipcr structure | Member i_ippr1_c of the header's ii_ipcr structure, 4 bits. |
| 3:0 | `ippr0_c` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPCR (name and offset), ii_ipcr structure | Member i_ippr0_c of the header's ii_ipcr structure, 4 bits. |

### Register `performance_profiling`

Performance profiling. The register's name and layout are from the header; the header gives no access type, so rw is assumed and the register is graded inferred. No reset is recorded. The rsvd mask is the structure's members named reserved; it is the header's naming only. The register name is ours, spelled out from the header's description of IIO_IPPR; the header's short name is IPPR.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:32 | `ippr1` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPPR (name and offset), ii_ippr structure | Member i_ippr1 of the header's ii_ippr structure, 32 bits. |
| 31:0 | `ippr0` | established |  | Linux 2.5.40 SN1 register headers: IIO_IPPR (name and offset), ii_ippr structure | Member i_ippr0 of the header's ii_ippr structure, 32 bits. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BTE_REGISTER_SIZE` | 0x30 | inferred |  | Extent of one block transfer engine's registers: six registers eight bytes apart from the engine's base (status, source, destination, control, notification, interrupt). The source defines the six offsets and the distance from engine 0 to engine 1, the stride of the engine registers here, but no size symbol, so the size is the end of the last register; nothing is defined between it and the next engine. |
| `MANUFACTURER_BEDROCK` | 0x24 | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Manufacturer field of the Bedrock identity words: 0x24 in bits 11:1 of both power-on identity values in the firmware register table (the widget_id reset 0x1c110049 here and the revision register reset 0x23012049 in the local block). OpenBSD files the Bedrock under its 0x36 vendor, the same vendor it gives the Hub, whose own table reset also reads 0x24, so that grouping is a naming convenience and not a value read from the chip. Earlier versions of this map gave 0x36. Read on silicon unknown. |
| `PART_BEDROCK` | 0xc110 | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Crosstalk part the SN1 header assigns to the Bedrock. The same value is named Bedrock in OpenBSD's device table. No consumer tests it and no read on silicon is recorded. |
| `PI0_INTERRUPT_PENDING_MODIFY` | 0x1800090 | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Hard-coded target of an II interrupt packet from PI select 0, at this offset in PI0's register space on the named node (the header's interrupt-destination logic). |
| `PI1_INTERRUPT_PENDING_MODIFY` | 0x1a00090 | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Hard-coded target of an II interrupt packet from PI select 1, at this offset in PI1's register space on the named node (the header's interrupt-destination logic). |
| `PROTECTION_OVERRIDE_KEY` | 0x53474972756c6573 | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | The 64-bit key the SN1 tree names for protection_override: the ASCII string SGIrules. |
