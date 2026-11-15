<!-- generated from devices/hub_ni/registers-extra.toml by defs-gen - do not edit, change the source -->

# Hub network interface field layouts, port and vector fields, and register offsets outside the census

Unit `hub_ni_extra`, macro prefix `HUB`.
Default source: public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `ni_status_rev_id` | 0x600000 | r | 64 |  |  | 0x20020 (established) | established | census: 18 sites, 16 routines (r); census: 5 sites, 4 routines (r, indexed) |
| `ni_port_reset` | 0x600008 | w | 64 |  |  | unknown | established | census: 6 sites, 6 routines |
| `ni_protection` | 0x600010 | r | 64 |  |  | 0x1 (established) | established | census: 3 sites, 2 routines |
| `ni_global_parms` | 0x600018 | rw | 64 |  |  | 0x3fffffe000f00f0 (established) | established | census: 2 sites, 1 routines |
| `ni_diag_parms` | 0x600110 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines (rw); census: 2 sites, 1 routines (rw, indexed) |
| `ni_vector_parms` | 0x600200 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `ni_vector_status` | 0x600300 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines (r); census: 7 sites, 3 routines (r, indexed) |
| `ni_return_vector` | 0x600308 | rw | 64 |  |  | unknown | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_vector_clear` | 0x600380 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `ni_io_protect` | 0x600400 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_io_prot_ovrrd` | 0x600408 | w | 64 |  |  | unknown | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_age_cpu0_memory` | 0x600500 | rw | 64 |  |  | 0x0 (established) | established | census: 9 sites, 3 routines |
| `ni_age_cpu0_pio` | 0x600508 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_age_cpu1_memory` | 0x600510 | rw | 64 |  |  | 0x0 (established) | established | census: 9 sites, 3 routines |
| `ni_age_cpu1_pio` | 0x600518 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_age_gbr_memory` | 0x600520 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_age_gbr_pio` | 0x600528 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_age_io_memory` | 0x600530 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_age_io_pio` | 0x600538 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_port_parms` | 0x608000 | rw | 64 |  |  | 0x1bf0 (established) | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_port_error` | 0x608008 | r | 64 |  |  | unknown | established | census: 4 sites, 4 routines (r); census: 1 sites, 1 routines (r, indexed) |
| `ni_port_error_clear` | 0x608088 | r | 64 |  |  | unknown | established | census: 10 sites, 4 routines (r); census: 3 sites, 3 routines (r, indexed) |
| `ni_meta_entry` | 0x638008 | rw | 64 | 31 |  | unknown | inferred | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `ni_local_entry` | 0x638108 | rw | 64 | 15 |  | unknown | inferred | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |

### Register `ni_status_rev_id`

Layout of the status, revision and identity register, ni_status_rev_id. The header names the port status bits separately; this word uses the same names. The census of the shipped IRIX Origin 200/2000 kernel (the census field table) shows the register read with a shift of 8 and a nine-bit mask for the node number, a shift of 4 for the chip revision and a test of bit 17 for the region size; the header's layout agrees.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `eightbit_mode` | established |  | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | Eight-bit mode bit, bit 30, named NSRI_8BITMODE. The header gives no further meaning. |
| 29 | `link_up` | established |  | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | Link-up bit, bit 29, named NSRI_LINKUP. The header gives no further meaning. |
| 28 | `down_reason` | established |  | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | Down reason, bit 28. The header's comment says 0 means failed and 1 means never came out of reset. |
| 18 | `more_nodes` | established | ni_node_mode (more_memory=0, more_nodes=1) | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | Maximum-node selection, bit 18, named NSRI_MORENODES. |
| 17 | `region_size` | established | ni_region_size (coarse=0, fine=1) | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | Region granularity, bit 17, named NSRI_REGIONSIZE. |
| 16:8 | `node_id` | established |  | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | This Hub's node number, nine bits at 16:8, named NSRI_NODEID. |
| 7:4 | `chip_rev` | established |  | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | Chip revision, four bits at 7:4, named NSRI_REV. The header gives no meaning for the values. |
| 3:0 | `chip_id` | established |  | public Linux SN0 Hub network interface header: NSRI_* masks and shifts | Chip type identifier, four bits at 3:0, named NSRI_CHIPID. |

### Register `ni_port_reset`

Layout of the port reset register, ni_port_reset. The register is written, not read back; the header gives no read value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `warm_reset` | established |  | public Linux SN0 Hub network interface header: NPR_* masks | Send a warm reset over the link, bit 7, named NPR_PORTRESET. |
| 1 | `link_reset` | established |  | public Linux SN0 Hub network interface header: NPR_* masks | Send a link reset, bit 1, named NPR_LINKRESET. |
| 0 | `local_reset` | established |  | public Linux SN0 Hub network interface header: NPR_* masks | Reset the whole Hub, bit 0, named NPR_LOCALRESET. The header's comment says it resets the entire Hub. |

### Register `ni_protection`

Layout of the protection configuration register, ni_protection.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `reset_ok` | established |  | public Linux SN0 Hub network interface header: NPROT_RESETOK | Permits reset, bit 0, named NPROT_RESETOK. |

### Register `ni_global_parms`

Layout of the global link parameters register, ni_global_parms. The header's comment on the credit-timeout field repeats the wording of the field above it; the name used here is the mask's own name.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 57:48 | `max_retry` | established |  | public Linux SN0 Hub network interface header: NGP_* masks and shifts | Maximum retry count, ten bits at 57:48. |
| 47:32 | `tail_timeout_wrap` | established |  | public Linux SN0 Hub network interface header: NGP_* masks and shifts | Tail timeout wrap value, sixteen bits at 47:32. |
| 19:16 | `credit_timeout` | established |  | public Linux SN0 Hub network interface header: NGP_* masks and shifts | Credit timeout value, four bits at 19:16. |
| 7:4 | `tail_timeout` | established |  | public Linux SN0 Hub network interface header: NGP_* masks and shifts | Tail timeout value, four bits at 7:4. |

### Register `ni_diag_parms`

Layout of the diagnostic parameters register, ni_diag_parms. The header names each bit and gives no further behaviour.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 18 | `port_timeout_reset` | established |  | public Linux SN0 Hub network interface header: NDP_* masks | Port timeout reset, bit 18, named NDP_PORTTORESET. |
| 12 | `llp_8bit_mode` | established |  | public Linux SN0 Hub network interface header: NDP_* masks | Link-layer eight-bit mode, bit 12, named NDP_LLP8BITMODE. |
| 6 | `port_disable` | established |  | public Linux SN0 Hub network interface header: NDP_* masks | Port disable, bit 6, named NDP_PORTDISABLE. |
| 0 | `send_error` | established |  | public Linux SN0 Hub network interface header: NDP_* masks | Send a data error, bit 0, named NDP_SENDERROR. |

### Register `ni_vector_parms`

Layout of the vector routing parameters register, ni_vector_parms. The header's identifier mask covers bits 49:40. Other sources put the top bit of that field at 50; this layout follows the public header.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49:40 | `pio_id` | established |  | public Linux SN0 Hub network interface header: NVP_* masks and shifts | Access identifier, ten bits at 49:40, named NVP_PIOID. The top bit is disputed; see the unit note. |
| 39:32 | `write_id` | established |  | public Linux SN0 Hub network interface header: NVP_* masks and shifts | Write identifier, eight bits at 39:32, named NVP_WRITEID. |
| 19:3 | `address` | established |  | public Linux SN0 Hub network interface header: NVP_* masks and shifts | Register address to reach, bits 19:3. The header's mask is 0xffff8, with bits 2:0 always zero. |
| 1:0 | `pio_type` | established | ni_pio_request_type (read=0, write=1, undefined=2, exchange=3) | public Linux SN0 Hub network interface header: NVP_* masks and shifts | Operation, two bits at 1:0, named NVP_TYPE. Only the values 0 to 3 can be requested. |

### Register `ni_vector_status`

Layout of the vector routing status register, ni_vector_status. The source field is ten bits in the header (60:51). Another source gives it eleven bits (61:51); this layout follows the public header.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub network interface header: NVS_* masks and shifts | Valid bit, bit 63, named NVS_VALID. |
| 62 | `overrun` | established |  | public Linux SN0 Hub network interface header: NVS_* masks and shifts | Overrun bit, bit 62, named NVS_OVERRUN. |
| 60:51 | `target` | established |  | public Linux SN0 Hub network interface header: NVS_* masks and shifts | Source field, ten bits at 60:51, named NVS_TARGET. Its encoding is not given in the header. |
| 49:40 | `pio_id` | established |  | public Linux SN0 Hub network interface header: NVS_* masks and shifts | Echo of the access identifier, ten bits at 49:40, named NVS_PIOID. |
| 39:32 | `write_id` | established |  | public Linux SN0 Hub network interface header: NVS_* masks and shifts | Echo of the write identifier, eight bits at 39:32, named NVS_WRITEID. |
| 31:3 | `address` | established |  | public Linux SN0 Hub network interface header: NVS_* masks and shifts | Echo of the register address, bits 31:3. The header's mask is 0xfffffff8. |
| 2:0 | `pio_type` | established | ni_pio_type (read=0, write=1, undefined=2, exchange=3, address_error=4, command_error=5, protection_error=6, unknown=7) | public Linux SN0 Hub network interface header: NVS_* masks and shifts | Response type, three bits at 2:0, named NVS_TYPE. The header's error mask is bit 2: a type with bit 2 set is an error. |

### Register `ni_return_vector`

Return vector of a vector operation, named NI_RETURN_VECTOR in the header. The header gives no layout. The IRIX register table confirms the access.

### Register `ni_vector_clear`

The header describes the register as 'Vector PIO read & clear status': a read clears, so the cor mask is all bits. Header comment only, graded inferred.

### Register `ni_io_protect`

PIO protection bits, one per region, named NI_IO_PROTECT in the header. Offset and name are from the header. The header gives neither a field layout nor a reset. The IRIX register table confirms the access.

### Register `ni_io_prot_ovrrd`

PIO protection override, named NI_IO_PROT_OVRRD in the header. The header gives no unlock value or behaviour, so none is imported. The IRIX register table confirms the access.

### Register `ni_age_cpu0_memory`

Layout of each of the eight ageing registers, ni_age_cpu0_memory through ni_age_io_pio. The census names two of them. The header gives the channel field its own names and no meaning for the congestion field.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_age_cpu0_pio`

CPU 0 PIO age control, named NI_AGE_CPU0_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_age_cpu1_memory`

Layout of each of the eight ageing registers, ni_age_cpu0_memory through ni_age_io_pio. The census names two of them. The header gives the channel field its own names and no meaning for the congestion field.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_age_cpu1_pio`

CPU 1 PIO age control, named NI_AGE_CPU1_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_age_gbr_memory`

Block-transfer engine memory age control, named NI_AGE_GBR_MEMORY in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_age_gbr_pio`

Block-transfer engine PIO age control, named NI_AGE_GBR_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_age_io_memory`

I/O interface memory age control, named NI_AGE_IO_MEMORY in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_age_io_pio`

I/O interface PIO age control, named NI_AGE_IO_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:10 | `vchannel` | established | ni_vchannel (channel_a=0, channel_b=1, any=2) | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Virtual channel, two bits at 11:10, named NAGE_VCH. |
| 9:8 | `congestion` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Congestion control, two bits at 9:8, named NAGE_CC. The header gives no values. |
| 7:0 | `age` | established |  | public Linux SN0 Hub network interface header: NAGE_* masks, shifts and channel names | Age, eight bits at 7:0, named NAGE_AGE. |

### Register `ni_port_parms`

Port parameters, named NI_PORT_PARMS in the header. Offset and name are from the header. The fields are graded on their own. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:10 | `null_timeout` | established |  | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Null-packet timeout, six bits. The header gives it a shift of 10 and a mask of 0x3f at bit 16, which disagree. The IRIX register table places the field at 15:10, as the shift and the default constant do. |
| 9:0 | `max_burst` | established |  | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Maximum burst, ten bits at 9:0, named NPP_MAXBURST in the header. |

### Register `ni_port_error`

Layout of the port error register, ni_port_error, and of its clearing alias, ni_port_error_clear. Bit 32 is outside the header's error mask and has no name. The rsvd mask is the header structure's unused members: bits 63:38 and bit 32. NPE_MASK, 0x3effffffff, is the header's own mask of defined bits and agrees.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37 | `link_reset` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Link reset, bit 37, named NPE_LINKRESET. |
| 36 | `internal_error` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Internal error, bit 36, named NPE_INTERNALERROR. |
| 35 | `bad_message` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Bad message, bit 35, named NPE_BADMESSAGE. |
| 34 | `bad_destination` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Bad destination, bit 34, named NPE_BADDEST. |
| 33 | `queue_overflow` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | FIFO overflow, bit 33, named NPE_FIFOOVERFLOW. |
| 31:28 | `credit_timeout_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Credit timeout count, four bits at 31:28. |
| 27:24 | `tail_timeout_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Tail timeout count, four bits at 27:24. |
| 23:16 | `retry_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Retry count, eight bits at 23:16. |
| 15:8 | `check_bit_error_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Check-bit error count, eight bits at 15:8. |
| 7:0 | `sequence_error_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Sequence-number error count, eight bits at 7:0. The header's counter maximum is 0xff. |

### Register `ni_port_error_clear`

Layout of the port error register, ni_port_error, and of its clearing alias, ni_port_error_clear. Bit 32 is outside the header's error mask and has no name.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37 | `link_reset` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Link reset, bit 37, named NPE_LINKRESET. |
| 36 | `internal_error` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Internal error, bit 36, named NPE_INTERNALERROR. |
| 35 | `bad_message` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Bad message, bit 35, named NPE_BADMESSAGE. |
| 34 | `bad_destination` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Bad destination, bit 34, named NPE_BADDEST. |
| 33 | `queue_overflow` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | FIFO overflow, bit 33, named NPE_FIFOOVERFLOW. |
| 31:28 | `credit_timeout_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Credit timeout count, four bits at 31:28. |
| 27:24 | `tail_timeout_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Tail timeout count, four bits at 27:24. |
| 23:16 | `retry_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Retry count, eight bits at 23:16. |
| 15:8 | `check_bit_error_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Check-bit error count, eight bits at 15:8. |
| 7:0 | `sequence_error_count` | established |  | public Linux SN0 Hub network interface header: NPE_* masks and shifts | Sequence-number error count, eight bits at 7:0. The header's counter maximum is 0xff. |

### Register `ni_meta_entry`

Meta routing table entries 1 to 31, eight bytes apart from the census entry ni_meta_table0. The header gives the stride and the count of 32 entries. Access is assumed read and write. The entry width is not stated in the header and is not imported.

Array of 31 registers, stride 8.

### Register `ni_local_entry`

Local routing table entries 1 to 15, eight bytes apart from the census entry ni_local_table0. The header gives the stride and the count of 16 entries. Access is assumed read and write. The entry width is not stated in the header and is not imported.

Array of 15 registers, stride 8.

## Enums

### Enum `ni_node_mode`

| Label | Value | Grade | Source |
|---|---|---|---|
| `more_memory` | 0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `more_nodes` | 1 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |

### Enum `ni_pio_request_type`

| Label | Value | Grade | Source |
|---|---|---|---|
| `read` | 0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `write` | 1 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `undefined` | 2 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `exchange` | 3 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |

### Enum `ni_pio_type`

| Label | Value | Grade | Source |
|---|---|---|---|
| `read` | 0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `write` | 1 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `undefined` | 2 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `exchange` | 3 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `address_error` | 4 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `command_error` | 5 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `protection_error` | 6 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `unknown` | 7 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |

### Enum `ni_region_size`

| Label | Value | Grade | Source |
|---|---|---|---|
| `coarse` | 0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `fine` | 1 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |

### Enum `ni_vchannel`

| Label | Value | Grade | Source |
|---|---|---|---|
| `channel_a` | 0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `channel_b` | 1 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |
| `any` | 2 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `NI_BASE` | 0x600000 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Start of the network interface registers, from the header. |
| `NI_BASE_TABLES` | 0x630000 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Start of the routing tables, from the header. |
| `NI_LOCAL_ENTRIES` | 0x10 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Local routing table entry count, named NI_LOCAL_ENTRIES in the public header. |
| `NI_META_ENTRIES` | 0x20 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Meta routing table entry count, named NI_META_ENTRIES in the public header. |
| `NI_NASID_TO_COARSEREG_SHIFT` | 0x3 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Shift from a node number to its region number in coarse mode, with eight nodes per region. |
| `NI_NASID_TO_FINEREG_SHIFT` | 0x0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Shift from a node number to its region number in fine mode, where each node is a region. |
| `NI_PORT_ERROR_COUNT_MAX` | 0xff | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Largest value of an error counter in the port error register, named NPE_COUNT_MAX in the header. |
| `NI_PORT_PARMS_DEFAULTS` | 0x1bf0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Composite default of the port parameters register: null timeout 6 at 15:10 and burst 0x3f0. A default the header gives for software to write, not a reset read from hardware. The IRIX header defines the macro with this value, and the PROM writes it to the register, the Hub 2.0 value on Hub revision 2. |
| `NI_PORT_PARMS_HUB20_DEFAULTS` | 0x7f0 | established | public Linux SN0 Hub network interface header, pinned linux tree (names, masks, shifts and software default constants) | Composite default the header gives for the Hub 2.0 port parameters: null timeout 1 at 15:10 and burst 0x3f0. A software default, not a reset read. The IRIX header defines the macro with this value, and the PROM writes it to the register, the Hub 2.0 value on Hub revision 2. |
