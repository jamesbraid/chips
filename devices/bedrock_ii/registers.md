<!-- generated from devices/bedrock_ii/registers.toml by defs-gen - do not edit, change the source -->

# Bedrock I/O interface (II) registers: field layouts, block transfer engines and reset values

Offsets are hub-relative: the I/O interface is the block that starts 4 MiB into the node's register space. Field layouts come from the public Linux 2.5.40 SN1 headers, so they are established as header positions. Behaviour the headers describe only in comments is inferred. Reset values are unknown unless a header states one. Access directions the headers do not state are recorded as they are used by the public consumers. Where the header and a consumer disagree the field is listed with the disagreement in its doc.

Unit `bedrock_ii`, macro prefix `BEDROCK_II`.
Default source: Linux 2.5.40 SN1 register headers: names, offsets and field layouts.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `widget_id` | 0x400000 | r | 64 |  |  | 0x1c110049 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `widget_control` | 0x400020 | rw | 64 |  |  | 0x4011 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `local_access_protection` | 0x400100 | rw | 64 |  |  | 0xfffffffffffffff (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `protection_override` | 0x400108 | w | 64 |  |  | unknown | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `outbound_widget_access` | 0x400110 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `inbound_widget_access` | 0x400118 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `inbound_device_error_mask` | 0x400120 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `link_control` | 0x400128 | rw | 64 |  |  | 0x3fc03ff040a (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `llp_log` | 0x400130 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `interrupt_destination` | 0x400138 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `graphics_map` | 0x400140 | rw | 64 | 2 |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `scratch` | 0x400150 | rw | 64 | 2 |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `translation_table_entry` | 0x400160 | rw | 64 | 7 |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `pio_request_buffer_w0` | 0x400198 | rw | 64 |  |  | 0xf (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `pio_request_buffer_w8` | 0x4001a0 | rw | 64 | 8 |  | 0xf (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `credit_count_timeout` | 0x4001e0 | rw | 64 |  |  | 0x3ffffff (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `misc_error_mask` | 0x4001e8 | rw | 64 |  |  | 0x111 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crosstalk_timeout_threshold` | 0x4001f0 | rw | 64 |  |  | 0xfffffff03ffffff (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `error_clear` | 0x4001f8 | w | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_global_control` | 0x400200 | rw | 64 |  |  | 0x8 (established) | inferred | Linux 2.5.40 SN1 register headers: IIO_IBCR (name and offset) |
| `pio_read_address` | 0x400308 | rw | 64 | 8 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `request_buffer_management` | 0x4003a8 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `request_buffer_control` | 0x4003b0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crb_timeout` | 0x4003b8 | rw | 64 |  |  | 0xff (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crb_timeout_prescaler` | 0x4003c0 | rw | 64 |  |  | 0xffffff (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crb_a` | 0x400400 | r | 64 | 15 |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crb_b` | 0x400408 | r | 64 | 15 |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crb_c` | 0x400410 | r | 64 | 15 |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `crb_d` | 0x400418 | r | 64 | 15 |  | 0x0 (established) | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_length_status` | 0x410000 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_source` | 0x410008 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_destination` | 0x410010 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_control` | 0x410018 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_notification_address` | 0x410020 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `bte_interrupt_address` | 0x410028 | rw | 64 | 2 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |

### Register `widget_id`

Widget identification. Echoes the manufacturer and revision fields of the local block's revision register and carries the Bedrock's crosstalk part. Its value follows the local revision register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `revision` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 27:12 | `part` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 11:1 | `manufacturer` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `widget_control`

Crosstalk widget control register (the header's IO widget control). The header states no access type, so rw is assumed. No field layout is recorded here.

### Register `local_access_protection`

One enable bit per processor region. The header states that at reset every region is permitted, and gives no number. The shipped Origin 350 PROM register table gives sixty set bits, 0x0fffffffffffffff, so the top four bits of the 64-bit field are clear at reset; that value is used. A processor PIO is performed only when the requester's region bit is set; otherwise it gets an error response. Readable only by permitted regions or through the local alias.

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

IO translation table entries 1 to 7, eight bytes apart; the first is entry 1. The header states no access type, so rw is assumed. No field layout is recorded here.

Array of 7 registers, stride 8.

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

IO crosstalk credit count timeout. The header states no access type, so rw is assumed. No field layout is recorded here.

### Register `misc_error_mask`

Write-one-to-set per the header. The header's description says the hub clears each field when an error requires that source to be shut down and that software sets a field by writing one. The companion header's macro comments instead call bits 0, 4 and 8 shut-down flags, and the Itanium error handler reads them that way. The register description and the recovery write govern. No Linux header states the reset value. The later chip's recovery write re-enables a source by setting its bit, which agrees with the value in the PROM register table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `clear_precise` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 8 | `bte_1_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 4 | `bte_0_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 0 | `widget_0_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `crosstalk_timeout_threshold`

IO crosstalk timeout threshold. The header states no access type, so rw is assumed. No field layout is recorded here.

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

IO BTE control register: the one register that controls both transfer engines, as against bte_control, which each engine has. The header states no access type, so rw is assumed. No field layout is recorded here.

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

IO CRB timeout. The header states no access type, so rw is assumed. No field layout is recorded here.

### Register `crb_timeout_prescaler`

IO CRB timeout prescaler. The header states no access type, so rw is assumed. No field layout is recorded here.

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

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BTE_REGISTER_SIZE` | 0x30 | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Extent of one block transfer engine's registers: six registers eight bytes apart from the engine's base (status, source, destination, control, notification, interrupt). The source defines the six offsets and the distance from engine 0 to engine 1, the stride of the engine registers here, but no size symbol, so the size is the end of the last register; nothing is defined between it and the next engine. |
| `MANUFACTURER_BEDROCK` | 0x36 | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Manufacturer field value for Bedrock in the OpenBSD device table and in mainline Linux's widget table. Read on silicon unknown. |
| `PART_BEDROCK` | 0xc110 | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Crosstalk part the SN1 header assigns to the Bedrock. The same value is named Bedrock in OpenBSD's device table. No consumer tests it and no read on silicon is recorded. |
| `PI0_INTERRUPT_PENDING_MODIFY` | 0x1800090 | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Hard-coded target of an II interrupt packet from PI select 0, at this offset in PI0's register space on the named node (the header's interrupt-destination logic). |
| `PI1_INTERRUPT_PENDING_MODIFY` | 0x1a00090 | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Hard-coded target of an II interrupt packet from PI select 1, at this offset in PI1's register space on the named node (the header's interrupt-destination logic). |
| `PROTECTION_OVERRIDE_KEY` | 0x53474972756c6573 | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | The 64-bit key the SN1 tree names for protection_override: the ASCII string SGIrules. |
