<!-- generated from devices/bedrock_lb/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 b37d365dbb57af8f38c2d786617250b65c049cb8d901dc94e622247577944aba -->

# Bedrock local block (LB) registers: field layouts, reset statements and the vector engine

Offsets are hub-relative: the local block starts 6 MiB into the node's register space and holds the 34 registers from the revision register through vector status clear. Field positions, access widths and reset statements come from the public Linux 2.5.40 SN1 headers, so they are established as header facts. Behaviour the headers give only in comments is graded as the comment's own claim, and behaviour they leave open is unknown. No Bedrock specification is held, so no reset value is established where the headers are silent.

Unit `bedrock_lb`, macro prefix `BEDROCK_LB`.
Default source: Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `rev_id` | 0x600000 | rw | 64 |  |  | 0x23012049 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `cpu_permission` | 0x604000 | rw | 64 |  |  | 0xfffffffffffffff (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `cpu_permission_override` | 0x604008 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `io_permission` | 0x604010 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `soft_reset` | 0x604018 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `region_present` | 0x604020 | rw | 64 |  |  | 0xfffffffffffffff (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `nodes_absent` | 0x604028 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `microlan_ctl` | 0x604030 | rw | 64 |  |  | 0x31e300002 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `error_bits` | 0x604040 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `error_mask_clr` | 0x604048 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `error_hdr1` | 0x604050 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `error_hdr2` | 0x604058 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `error_data` | 0x604060 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `debug_select` | 0x604100 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `debug_pins` | 0x604108 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `rt_local_ctrl` | 0x604200 | rw | 64 |  |  | 0x100000640 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `rt_filter_ctrl` | 0x604208 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch0` | 0x608000 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch1` | 0x608008 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch2` | 0x608010 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch3` | 0x608018 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch4` | 0x608020 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch0_wz` | 0x608040 | w | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch1_wz` | 0x608048 | w | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch2_wz` | 0x608050 | w | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch3_rz` | 0x608058 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `scratch4_rz` | 0x608060 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `vector_parms` | 0x60c000 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `vector_route` | 0x60c008 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `vector_data` | 0x60c010 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `vector_status` | 0x60c020 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `vector_return` | 0x60c028 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `vector_read_data` | 0x60c030 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `vector_status_clear` | 0x60c038 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |

### Register `rev_id`

Revision and identity. The header says this register carries the chip identity and sets the node's ID and the size of each region. The manufacturer, part and revision fields are assigned by IBM under the IEEE 1149.1 scheme, and the header does not say whether they are writable. The I/O interface's widget identification register echoes the manufacturer and revision fields.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:46 | `region_size` | established | region_size (fine=0, coarse=1, nmode=2, invalid=3) | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | How many nodes share one region. |
| 39:32 | `node_id` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | This node's number. The header says the register sets the node ID. |
| 31:28 | `revision` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | 1 for Bedrock 1.0, 2 for Bedrock 1.1. |
| 27:12 | `part_number` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Hub chip part number, the value of CHIP_PART_BEDROCK. |
| 11:1 | `manufacturer` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Manufacturer code, assigned by IBM under the header's scheme. The value is not stated in the header. |

### Register `cpu_permission`

Processor PIO access permission, one bit per region. A region whose bit is clear gets no write access to the local block, network interface, crossbar or memory-directory registers, and no read that would change state. A write or a state-changing read from such a region is not performed and gets an error reply. The header calls it the access-rights vector for those four units. The table record behind this reset (decoded from the firmware image) is one field spanning bits 63:0 whose reset is 0x0fffffffffffffff; the same record appears for this register, the local block's processor permission and its region present register, and the table does write 64 set bits for single 64-bit fields elsewhere (three registers of the processor interface block and the first register of the memory-directory block), so the four clear bits are not how the table writes all-ones. Whether the silicon reads them clear is not settled by any public source.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `region_enable` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | One bit per region. |

### Register `cpu_permission_override`

Writing the 64-bit ASCII key the SN1 header names sets the writer's own region bit in cpu_permission. The key is not reproduced here. Reset unknown.

### Register `io_permission`

The same per-region access vector as cpu_permission, applied to accesses that come from the I/O interface side rather than from a processor.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `region_enable` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | One bit per region. |

### Register `soft_reset`

A write to bit 0 resets the Bedrock with a soft reset. The header does not say which state survives it. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `soft_reset` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `region_present`

Regions that can receive an invalidate. The block samples it when an invalidate arrives. If an invalidate names a processor interface in a region whose bit is clear, the block acknowledges on that interface's behalf. The region size in the revision register sets how many nodes share one bit. The table record behind this reset (decoded from the firmware image) is one field spanning bits 63:0 whose reset is 0x0fffffffffffffff; the same record appears for this register, the local block's processor permission and its region present register, and the table does write 64 set bits for single 64-bit fields elsewhere (three registers of the processor interface block and the first register of the memory-directory block), so the four clear bits are not how the table writes all-ones. Whether the silicon reads them clear is not settled by any public source.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `present` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | One bit per region. |

### Register `nodes_absent`

Four 16-bit entries, one per slot. Each entry holds a node number in its low eight bits and a valid bit at bit 15. A node listed with its valid bit set cannot receive an invalidate.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `entry3_valid` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 55:48 | `entry3_node` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 47 | `entry2_valid` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 39:32 | `entry2_node` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 31 | `entry1_valid` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 23:16 | `entry1_node` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 15 | `entry0_valid` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 7:0 | `entry0_node` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `microlan_ctl`

Control for a one-wire serial bus to the node board's add-only serial PROM. The header names the part as a Dallas 1990A and says the PROM holds the node board's serial number and configuration. Bytes travel least-significant bit first. The header gives no unit for the timing fields, no completion latency and no sequence of commands, so the timing and the transaction are unknown. The public Linux SN1 tree does not use this register outside its header.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:27 | `clkdiv_phi1` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Phase-1 divider. The header does not say how it sets time. Bit 33 means a 32-bit access cannot write the whole field. |
| 26:20 | `clkdiv_phi0` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Phase-0 divider. The header does not say how it sets time. |
| 19:10 | `low_pulse` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Low-pulse duration field. Its time base is not stated. |
| 9:2 | `sample_offset` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Sample offset field. Its time base is not stated. |
| 1 | `done` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Completion flag for the operation started by a write. |
| 0 | `read_data` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Sampled bus level. |

### Register `error_bits`

Local-block error bits. Reads do not change them. A write sets the bits it names. Any set bit raises the block's error request to both processor interfaces (bit 55 of their pending-1 register). The header says the contents survive a reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10 | `gclk_drop` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Loss of the global clock. Header 1 is not updated for this error. |
| 9 | `rq_bad_inval` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Request with a bad invalidate. |
| 8 | `rq_bad_addr` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Request with a bad address. |
| 7 | `rp_bad_data` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Reply with bad data. |
| 6 | `rq_bad_data` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Request with bad data. |
| 5 | `rp_long` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Long reply. |
| 4 | `rq_long` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Long request. |
| 3 | `rp_short` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Short reply. |
| 2 | `rq_short` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Short request. |
| 1 | `rp_bad_cmd` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Reply with a bad command. |
| 0 | `rq_bad_cmd` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Request with a bad command. |

### Register `error_mask_clr`

Write one to clear the matching error bits. A zero bit in the written value leaves its error bit alone, so any subset clears atomically. Reset unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10:0 | `clear` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | One bit per error bit in error_bits. |

### Register `error_hdr1`

Header of the first packet that caused an error. It is captured while valid is clear, and valid is then set. A later error while valid is set sets overrun and leaves the rest alone. The err_type value uses the same bit numbering as error_bits, so err_type 5 means rp_long. Not relevant for a global clock drop.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 44 | `valid` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 40 | `overrun` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 35:32 | `err_type` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 30:20 | `source` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 18:8 | `suppl` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 6:0 | `command` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `error_hdr2`

Address field from the header of the first packet that caused an error. Not relevant for a global clock drop.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37:0 | `address` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `error_data`

Data flit of the first erroring packet, for the error kinds that carry data.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `flit` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `debug_select`

Chooses which internal signals appear on the debug pins. The header gives no list of the choices.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5:0 | `select` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `debug_pins`

Value on the chip's debug pins.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `pins` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `rt_local_ctrl`

Local source of the real-time clock. The local block gives the clock to both processor interfaces. With use_internal set it generates the clock from the Bedrock's system clock, with its period set by max_count. With it clear it filters an incoming global clock instead (see rt_filter_ctrl).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32 | `use_internal` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Generate the real-time clock internally rather than filtering the global clock. |
| 28 | `gclk` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Global clock bit. The header names it only. |
| 25:16 | `gclk_counter` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Global clock counter field. The header does not say what it counts. |
| 13:4 | `max_count` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Maximum count that sets the internal clock's period. |
| 0 | `gclk_enable` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Global clock enable. |

### Register `rt_filter_ctrl`

Filtering of an incoming global clock, used when rt_local_ctrl use_internal is clear. Simple filtering drops single-cycle glitches. Complex filtering (mask_enable set) expects positive edges at regular intervals, tracks missing and unexpected edges, and generates an edge itself when one is missing. Under either option the clock it hands the processor interfaces stays high for (2 * max_count + 1 - offset) / 2 cycles of the block's system clock after each positive edge. Clock loss is error bit gclk_drop.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 57:48 | `error_counter` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 45:36 | `dropout_threshold` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 33:24 | `dropout_counter` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 20 | `mask_enable` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Selects complex filtering. |
| 19:8 | `mask_counter` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 4:0 | `offset` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch0`

Plain storage. The header says it is reset to zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `bits` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch1`

Plain storage. The header says it is not reset, and does not name the reset it means.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `bits` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch2`

Plain storage. The header says it is not reset, and does not name the reset it means.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `bits` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch3`

One-bit storage (bit 0 of a 64-bit word). The header gives no reset value. The public Linux ia64 L1 driver uses it as a hub-wide lock: it releases the lock by writing zero to this address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `bit` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch4`

One-bit storage (bit 0 of a 64-bit word). The header gives no reset value, and the public Linux tree shows no use of it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `bit` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch0_wz`

Write-if-zero alias of scratch 0. A write is accepted only when the current value is zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `bits` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch1_wz`

Write-if-zero alias of scratch 1. A write is accepted only when the current value is zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `bits` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch2_wz`

Write-if-zero alias of scratch 2. A write is accepted only when the current value is zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `bits` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch3_rz`

Read-set-if-zero alias of scratch 3 (one bit, bit 0 of a 64-bit word). A read returns the old value and sets the bit when it was zero, so a single read is a test-and-set. The public Linux ia64 L1 driver takes its hub-wide lock this way and reads until it gets zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `bit` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `scratch4_rz`

Read-set-if-zero alias of scratch 4 (one bit). A read returns the old value and sets the bit when it was zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `bit` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

### Register `vector_parms`

Vector I/O request parameters. A write sends one request, and the block replies to the write at once without waiting for the operation. The request is built from three registers: the route, the write data and this one, which should be written last. Software waits for busy to clear before it starts.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `busy` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Set while a request is in flight. |
| 50:40 | `pio_id` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 39:32 | `write_id` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 23:3 | `address` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 1:0 | `type` | inferred | vector_op (read=0, write=1, undefined=2, exchange=3) | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | The header's union gives one bit and its companion mask gives two. The defined values are 0 to 3, so the field is graded inferred for its width. |

### Register `vector_route`

Outgoing vector route for the next request. The header gives no field layout.

### Register `vector_data`

Write data for an outgoing vector write, and the data value for a read reply.

### Register `vector_status`

Return status of the last vector request. Software clears it before launching a request. The block leaves the fields unchanged when a reply has an error. A reply that arrives while valid is already set sets overrun and leaves the rest alone. Otherwise the block loads the source, ids, address and type, sets valid, and updates return and read data. The header does not say what a write of a nonzero value does.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 62 | `overrun` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 61:51 | `source` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 50:40 | `pio_id` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 39:32 | `write_id` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 23:3 | `address` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 2:0 | `type_or_error` | established | vector_reply_type (read=0, write=1, undefined=2, exchange=3, address_error=4, command_error=5, protection_error=6, unknown_error=7) | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Reply type on success (matching the request), or an error code when bit 2 is set. |

### Register `vector_return`

Return route from the last reply. The block stores it only for an error-free reply that arrives while valid is clear.

### Register `vector_read_data`

Read data from the last reply, under the same update rule as vector_return.

### Register `vector_status_clear`

Clear the vector status. The header gives the same field layout as vector_status and says only that this register clears it. It does not say whether a read or a write does the clearing, so that is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 62 | `overrun` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 61:51 | `source` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 50:40 | `pio_id` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 39:32 | `write_id` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 23:3 | `address` | established |  | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |
| 2:0 | `type_or_error` | established | vector_reply_type (read=0, write=1, undefined=2, exchange=3, address_error=4, command_error=5, protection_error=6, unknown_error=7) | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |  |

## Enums

### Enum `region_size`

| Label | Value | Grade | Source |
|---|---|---|---|
| `fine` | 0 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `coarse` | 1 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `nmode` | 2 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `invalid` | 3 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |

### Enum `vector_op`

| Label | Value | Grade | Source |
|---|---|---|---|
| `read` | 0 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `write` | 1 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `undefined` | 2 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `exchange` | 3 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |

### Enum `vector_reply_type`

| Label | Value | Grade | Source |
|---|---|---|---|
| `read` | 0 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `write` | 1 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `undefined` | 2 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `exchange` | 3 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `address_error` | 4 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `command_error` | 5 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `protection_error` | 6 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |
| `unknown_error` | 7 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CHIP_PART_BEDROCK` | 0x3012 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Part number the SN1 chip-identity header assigns to the hub chip. The revision register carries it. |
| `ERROR_PI_PEND1_BIT` | 0x37 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Bit of the processor interface's pending-1 register that carries the local block's error request, counted from zero. |
| `REVISION_1_0` | 0x1 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Revision field value for Bedrock 1.0, from the SN1 chip-identity header. |
| `REVISION_1_1` | 0x2 | established | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Revision field value for Bedrock 1.1, from the SN1 chip-identity header. |
| `RTC_FREQ_KHZ_CONFIG` | 0x4e2 | inferred | Linux 2.5.40 SN1 local-block register headers (field layouts, masks and comments), the processor-interface header (pending-1 bit 55) and the SN1 configuration header (real-time counter default); public Linux ia64 L1 driver (scratch 3 lock use) | Real-time counter frequency the SN1 kernel configuration sets (the SN1 configuration default for the counter). The header gives it as the software default, not as a hardware measurement; the block does not state it. |
