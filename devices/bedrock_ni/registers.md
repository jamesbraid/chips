<!-- generated from devices/bedrock_ni/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 04d5ffad594b1763f0ae5bf21018846c021831d98979a127f60036b8abad3823 -->

# Bedrock network interface (NI) registers: field layouts, port error bits and routing tables

Offsets are in the node's local alias, the same offsets the census names in devices/bedrock/registers.toml. Register names, offsets, widths and field positions come from the public Linux 2.5.40 SN1 register headers, read directly from that tag, so they are established as header facts. Behaviour the headers give only in their comments is inferred. No Bedrock specification is held. The headers state no reset value, so every reset is unknown, except one software default the headers name without a source.

Unit `bedrock_ni`, macro prefix `BEDROCK_NI`.
Default source: Linux 2.5.40 SN1 register headers: names, offsets and field layouts.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `port_status` | 0x680000 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `port_reset` | 0x680008 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `reset_enable` | 0x680010 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `diag_parms` | 0x680018 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `channel_control` | 0x680020 | rw | 64 |  |  | 0x100 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `channel_test` | 0x680028 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `port_parms` | 0x680030 | rw | 64 |  |  | 0x7a3ff1bf0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `channel_age` | 0x680038 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `port_errors` | 0x680100 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `port_header_a` | 0x680108 | r | 64 |  |  | unknown | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `port_header_b` | 0x680110 | r | 64 |  |  | unknown | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `port_sideband` | 0x680118 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `port_error_clear` | 0x680120 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `local_table` | 0x681000 | rw | 64 | 128 |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |
| `global_table` | 0x682000 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |

### Register `port_status`

Link-level protocol status. The header calls bit 1 link up and bit 2 remote power; the header gives no encoding for the two-bit status, so the meaning of bit 1 is inferred from its name.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `remote_power` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Named remote power by the Linux header. The meaning rests on the name alone. The IRIX source header does not confirm it; see link_up. |
| 1 | `link_up` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Named link up by the Linux header. The meaning rests on the name alone. The IRIX source header, which describes an earlier layout, names the first register of this block as a status and revision word with a two-bit port status at bits 29:28, so it does not confirm these bits. |
| 0 | `status_bit0` | unknown |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Low bit of the two-bit port status. The header gives no meaning for it. |

### Register `port_reset`

Writing this register resets the network interface. The header's comments say bit 0 sends a link reset to the peer, bit 1 sends a warm reset over the link and bit 2 resets the local Bedrock. What the peer does with a link reset is not stated. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `local_reset` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Local reset. Header comment: resets this Bedrock. |
| 1 | `port_reset` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Port reset. Header comment: sends a warm reset over the link. |
| 0 | `link_reset_out` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Link reset sent out. Header comment: sends a link reset. |

### Register `reset_enable`

Warm reset enable. The header's comment says bit 0 lets a reset arriving over the link reset the Bedrock. The header does not say whether the bit also gates a local reset, so that is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `reset_ok` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Lets the link reset the Bedrock. The header comment says so; whether it gates the local reset bit is unknown. |

### Register `diag_parms`

Diagnostic parameters. Field names are the header's; the header gives no operating description beyond them.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `send_err_off` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Header name: disable send error recovery. |
| 1 | `port_disable` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Header name: port disable. |
| 0 | `send_data_error` | inferred |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Header name: send data error. |

### Register `channel_control`

Virtual channel selection for outgoing messages. Bits 0 to 3 pick the channel for requests of each class and bits 4 to 7 for replies.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `send_vch_sel` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Send channel select. The header gives no encoding beyond the name. |
| 7 | `vch_vector_reply` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 6 | `vch_nine_reply` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 5 | `vch_two_reply` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 4 | `vch_one_reply` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 3 | `vch_vector_request` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 2 | `vch_nine_request` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 1 | `vch_two_request` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 0 | `vch_one_request` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `channel_test`

Access to the link test logic: seed, mask, data, valid, error and flit fields, plus clear and error-capture controls. The header gives the field layout only. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54 | `test_errcapture` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 53 | `test_clear` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 52:50 | `test_flit` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 49 | `test_cberr` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 48 | `test_valid` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 47:28 | `test_data` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 27:20 | `test_mask` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 19:0 | `test_seed` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `port_parms`

Link-level protocol parameters and the enables for error header capture. The header gives field positions, and the reset-defaults constant above.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 34:31 | `vch_err_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | One enable per virtual channel. |
| 30 | `squash_err_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 29 | `first_err_enable` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 27:26 | `d_avail_sel` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Data-available select. The header gives no encoding. |
| 25:16 | `max_retry` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 15:10 | `null_timeout` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 9:0 | `max_burst` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `channel_age`

Age at which request and reply packets enter the fabric. The header's comment says a higher reply age gives replies fixed priority over requests under saturation (inferred from the comment).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `reply_inject_age` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 7:0 | `request_inject_age` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `port_errors`

Latched link-port and problem-message errors. The header's comment says reads do not change the register and bits 52 to 24 assert the network interface interrupt (inferred from the comment). The header's comment says the eight-bit counters do not wrap.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `link_reset_in` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Link reset in. The header says bits 52 to 24 assert the network interface interrupt. |
| 51:48 | `internal_long` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Internal long-packet event count, four bits. |
| 47:44 | `internal_short` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Internal short-packet event count, four bits. |
| 43:40 | `external_bad_header` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | External bad-header event count, four bits. |
| 39:36 | `external_long` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | External long-packet event count, four bits. |
| 35:32 | `external_short` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | External short-packet event count, four bits. |
| 31:28 | `fifo_overflow` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | FIFO overflow event count, four bits. |
| 27:24 | `tail_timeout` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Tail-timeout event count, four bits. |
| 23:16 | `retry_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Retry count, eight bits. |
| 15:8 | `cb_error_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Check-bit error count, eight bits. |
| 7:0 | `sn_error_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Sequence-number error count, eight bits. |

### Register `port_header_a`

First half of the header of an erroring packet, as the header's union lays it out. The header's comment says it holds the captured header. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:35 | `pha_address_b` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 34:32 | `pha_prexsel` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 31:24 | `pha_command` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 20:13 | `pha_destination` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 12:9 | `pha_direction` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 8:1 | `pha_age` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 0 | `pha_v` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Valid bit. |

### Register `port_header_b`

Second half of the header of an erroring packet, as the header's union lays it out. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:38 | `phb_address_c` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 37:35 | `phb_address_a` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 26:16 | `phb_source` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 10:0 | `phb_supplemental` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `port_sideband`

Sideband data for the header registers and extra error data. The header says this register is not cleared on reset. Its write effect is not stated, so the access direction is taken from the header's description as data the port provides.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:16 | `vch_active` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 15 | `send_error` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 14 | `cb_status` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 13 | `sn_status` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 12 | `squash` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 11 | `bad_message` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 10 | `rcv_error` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 9 | `bad_prexsel` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 8 | `bad_dest` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 7:0 | `sideband` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `port_error_clear`

The same information as port errors, with the same layout. The header's comment for this register repeats the port-errors comment, including that reads are non-destructive, which conflicts with the register name. The read effect is therefore unknown: the header does not settle whether a read clears the latched errors. Whether the read clears anything is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52 | `pec_link_reset_in` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 51:48 | `pec_internal_long` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 47:44 | `pec_internal_short` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 43:40 | `pec_external_bad_header` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 39:36 | `pec_external_long` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 35:32 | `pec_external_short` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 31:28 | `pec_fifo_overflow` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 27:24 | `pec_tail_timeout` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 23:16 | `pec_retry_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 15:8 | `pec_cb_error_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |
| 7:0 | `pec_sn_error_count` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `local_table`

Next-hop table for a local destination, one entry per 7-bit local destination at a stride of eight bytes; entry 0 is at the base. The header names the table and gives no access direction.

Array of 128 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `next_vch_lsb` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Low bit of the next virtual channel. The header gives no more than the name. |
| 3:0 | `next_exit_port` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

### Register `global_table`

Next-hop table for the one-bit meta destination. The header names the table and gives no access direction.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `next_vch_lsb` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Low bit of the next virtual channel. The header gives no more than the name. |
| 3:0 | `next_exit_port` | established |  | Linux 2.5.40 SN1 register headers: names, offsets and field layouts |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `PORT_PARMS_HEADER_DEFAULT` | 0x7a3ff1bf0 | inferred | Linux 2.5.40 SN1 register headers: names, offsets and field layouts | Value the header's reset-defaults macro builds for the port parameters: virtual-channel errors 0xf, first error enabled, maximum retry 0x3ff, null timeout 6, maximum burst 0x3f0. The header names it as the reset default and gives no source for it, so it is a header claim, not a hardware reset value. |
