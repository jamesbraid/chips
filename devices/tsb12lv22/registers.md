<!-- generated from devices/tsb12lv22/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 7c0c9c2e3187c6789010517cad60bcc61d96bd60b2a5cd37bd3bb1bc955da983 -->

# TI TSB12LV22 PCI-to-IEEE 1394 OHCI 1.00 link controller (I-brick IO7), the register facts the held sources establish

The PCI-to-1394 link controller on the Origin 3000 and Onyx 3000 I-brick IO7 board (PCI 104c:8009, IEEE 1394 OHCI 1.00 register interface). Grades say how each item was derived: established means the TI datasheet (SLLS290, July 1998) states it; inferred means a software expectation taken from shipped IRIX or PROM code, or a reading that the datasheet does not state outright; unknown means no source held here settles the value. The reset values of most registers are unknown: the datasheet leaves them unspecified or gives them only in part. Software expectations are what the shipped programs require, not measured chip behaviour, and no PHY, bus or DMA behaviour is part of this unit.

Unit `tsb12lv22`, macro prefix `TSB12LV22`.
Default source: TI SLLS290, TSB12LV22 OHCI-Lynx PCI-Based IEEE 1394 Host Controller, July 1998 (pages cited per item).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `version` | 0x0 | r | 32 |  |  | 0x10000 | established |  |
| `guid_rom` | 0x4 | rw | 32 |  |  | unknown | established |  |
| `retry_counts` | 0x8 | rw | 32 |  |  | 0x0 | established |  |
| `csr_data` | 0xc | rw | 32 |  |  | unknown | established |  |
| `csr_compare` | 0x10 | rw | 32 |  |  | unknown | established |  |
| `csr_control` | 0x14 | rw | 32 |  |  | unknown | established |  |
| `config_rom_header` | 0x18 | rw | 32 |  |  | unknown | established |  |
| `bus_id` | 0x1c | r | 32 |  |  | 0x31333934 | established |  |
| `bus_options` | 0x20 | rw | 32 |  |  | unknown | established |  |
| `guid_hi` | 0x24 | rw | 32 |  |  | 0x0 | established |  |
| `guid_lo` | 0x28 | rw | 32 |  |  | 0x0 | established |  |
| `config_rom_map` | 0x34 | rw | 32 |  |  | 0x0 | established |  |
| `posted_write_error` | 0x38 | r | 32 | 2 |  | unknown | established |  |
| `vendor_specific_id` | 0x40 | r | 32 |  |  | 0x0 | established |  |
| `hc_control` | 0x50 | rw | 32 |  |  | unknown | established |  |
| `self_id_buffer` | 0x64 | rw | 32 |  |  | unknown | established |  |
| `self_id_count` | 0x68 | r | 32 |  |  | unknown | established |  |
| `recv_channel_mask_hi` | 0x70 | rw | 32 |  |  | unknown | established |  |
| `recv_channel_mask_lo` | 0x78 | rw | 32 |  |  | unknown | established |  |
| `int_event` | 0x80 | rw | 32 |  |  | unknown | established |  |
| `int_mask` | 0x88 | rw | 32 |  |  | unknown | established |  |
| `iso_xmit_event` | 0x90 | rw | 32 |  |  | unknown | established |  |
| `iso_xmit_mask` | 0x98 | rw | 32 |  |  | unknown | established |  |
| `iso_recv_event` | 0xa0 | rw | 32 |  |  | unknown | established |  |
| `iso_recv_mask` | 0xa8 | rw | 32 |  |  | unknown | established |  |
| `fairness_control` | 0xdc | rw | 32 |  |  | unknown | established |  |
| `link_control` | 0xe0 | rw | 32 |  |  | unknown | established |  |
| `node_id` | 0xe8 | rw | 32 |  |  | unknown | established |  |
| `phy_control` | 0xec | rw | 32 |  |  | unknown | established |  |
| `cycle_timer` | 0xf0 | rw | 32 |  |  | unknown | established |  |
| `async_filter_hi` | 0x100 | rw | 32 |  |  | 0x0 | established |  |
| `async_filter_lo` | 0x108 | rw | 32 |  |  | 0x0 | established |  |
| `phys_filter_hi` | 0x110 | rw | 32 |  |  | 0x0 | established |  |
| `phys_filter_lo` | 0x118 | rw | 32 |  |  | 0x0 | established |  |
| `phys_upper_bound` | 0x120 | r | 32 |  |  | 0x0 | established |  |

### Register `version`

OHCI version. Major version 1 is in bits 23:16 and minor version 0 in bits 7:0, so this is OHCI 1.00. Bit 24 reports whether a configuration ROM is present, sampled from ROM detection. The reset value shown is for the no-ROM case.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24 | `rom_present` | established |  |  | Configuration ROM present, sampled from ROM detection |
| 23:16 | `major` | established |  |  | Major version, 1 |
| 7:0 | `minor` | established |  |  | Minor version, 0 |

### Register `guid_rom`

GUID ROM access. Writing the address-reset bit resets the ROM read address, and the bit clears itself. Writing the read-start bit starts a read, and the byte read appears in the read-data field. The data is unspecified at reset and the command bits read as zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `address_reset` | established |  |  | Self-clearing address reset |
| 25 | `read_start` | established |  |  | Start a GUID ROM read |
| 23:16 | `read_data` | established |  |  | Hardware read-data byte, unspecified at reset |

### Register `retry_counts`

Retry counts. Three read-write count fields are defined. The outbound dual-phase retry fields read as zero. The datasheet summary does not name the three count fields, so the field names here are positional.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `dual_phase_retry` | established |  |  | Outbound dual-phase retry fields, read as zero |
| 11:8 | `count_11_8` | established |  |  | Read-write retry count, bits 11:8 |
| 7:4 | `count_7_4` | established |  |  | Read-write retry count, bits 7:4 |
| 3:0 | `count_3_0` | established |  |  | Read-write retry count, bits 3:0 |

### Register `csr_data`

CSR data word for serial bus register transfers. Unspecified at reset.

### Register `csr_compare`

CSR compare word. Unspecified at reset.

### Register `csr_control`

CSR control. Writing clears the done bit, which the controller sets on completion. The resource select is unspecified at reset, and the done bit is set at reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `done` | established |  |  | Clears on a write and sets on completion |
| 1:0 | `resource_select` | established |  |  | Resource select, unspecified at reset |

### Register `config_rom_header`

Configuration ROM header. The upper 16 bits read as zero at reset. The low 16 bits hold the CRC, which is unspecified without a ROM.

### Register `bus_id`

Constant BusID. The value is the ASCII text 1394.

### Register `bus_options`

Bus options. Bits 31:27, 23:16, 15:12 and 7:6 are writable. Link speed reads as 2. Bit 27 resets to zero. The max_rec field survives SoftReset with its hardware default of 2048 bytes. Other bits have unspecified reset values.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:12 | `max_rec` | established |  |  | Maximum receive packet size code. The hardware default is 10, meaning 2048 bytes, and SoftReset preserves it |
| 2:0 | `link_speed` | established |  |  | Reads as 2, the 400 Mbit/s code |

### Register `guid_hi`

GUID high word. It reads as zero before a ROM load. Without a ROM each GUID register can be written once and then locks, and that lock state is separate from the register's value.

### Register `guid_lo`

GUID low word. The write-once rule for the high word applies here too.

### Register `config_rom_map`

Configuration ROM mapping address. Bits 31:10 are read-write and reset to zero.

### Register `posted_write_error`

Posted-write error address and source reporting, read and updated by the controller, at the offset and four bytes above it. The datasheet summary gives the pair as one address and source record and does not split it per word. Unspecified at reset.

Array of 2 registers, stride 4.

### Register `vendor_specific_id`

OHCI vendor-specific identifier. Read only, reads zero.

### Register `hc_control`

HCControl. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 30 and 18 are unspecified at reset and the other defined bits reset to zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `no_byte_swap_data` | established |  |  | noByteSwapData: controls whether physical accesses to locations outside the controller, and other DMA data accesses, are byte swapped. The name says one means no swap; the table gives no polarity wording beyond the name. Its reset value is unspecified |
| 23 | `program_phy_enable` | established |  |  | Software-clearable permission to program the PHY |
| 22 | `aphy_enhance_enable` | established |  |  | PHY enhancement enable, needed with the 1394a acceleration bit in PCI configuration |
| 19 | `lps` | established |  |  | Link power status. Set it before PHY and link communication |
| 18 | `posted_write_enable` | established |  |  | Posted writes. Changes only while linkEnable is zero |
| 17 | `link_enable` | established |  |  | Clearing it disconnects the controller at once: no packet is received, processed or sent |
| 16 | `soft_reset` | established |  |  | Controller SoftReset. Stays set during reset and clears on completion |

### Register `self_id_buffer`

Self-ID buffer pointer. The address is 2 KiB aligned, so its low 11 bits read as zero. The address is unspecified at reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:11 | `address` | established |  |  | Buffer base address, read-write |

### Register `self_id_count`

Self-ID count. The error and generation fields are unspecified at reset and the size field resets to zero. The controller updates the fields on bus events.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `error` | established |  |  | Self-ID error |
| 23:16 | `generation` | established |  |  | Bus generation the self-ID data belongs to |
| 10:2 | `size` | established |  |  | Self-ID buffer size in quadlets, the header included |

### Register `recv_channel_mask_hi`

Receive channel mask high, channels 32 to 63 (IRChannelMaskHiSet at 0x70 and its clear register at 0x74, Table 20 and Table 32). The set and clear addresses form a pair, the clear address four bytes above the set address. Unspecified at reset.

### Register `recv_channel_mask_lo`

Receive channel mask low, channels 0 to 31 (IRChannelMaskLoSet at 0x78 and its clear register at 0x7c, Table 20). The set and clear addresses form a pair, the clear address four bytes above the set address. Unspecified at reset.

### Register `int_event`

Interrupt events. The set and clear addresses form a pair, the clear address four bytes above the set address. Reads of the clear register return the event bits ANDed with the mask. Implemented event bits are unspecified at reset. Bits 7 and 6 are derived summaries and are not independent latches. Bit 30 is vendor-defined and its meaning is not given. Bit 18 is undefined for OHCI 1.00 and must read zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19 | `phy_reg_received` | established |  |  | PHY requests an interrupt through a status transfer (field `phy`, TI SLLS290 Table 34, p. 28). The IRIX 1394 driver clears it after a PHY register read |
| 17 | `bus_reset` | established |  |  | Bus reset event: the PHY entered bus reset mode (field `busReset`, TI SLLS290 Table 34, p. 28) |
| 16 | `self_id_complete` | established |  |  | Self-ID complete: a self-ID packet stream was received (field `selfDcomplete`, TI SLLS290 Table 34, p. 28) |
| 7 | `iso_recv_summary` | established |  |  | OR of the isochronous receive event and mask. Software writes to it have no effect |
| 6 | `iso_xmit_summary` | established |  |  | OR of the isochronous transmit event and mask. Software writes to it have no effect |

### Register `int_mask`

Interrupt mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Reading either address of the pair returns the mask. Pending event state stays separate from the mask, and the interrupt output must be recomputed when the mask changes. Implemented mask bits are unspecified at reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `master_int_enable` | established |  |  | Enables external interrupt delivery on INTA |

### Register `iso_xmit_event`

Isochronous transmit event, one bit per context. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 7:0 are defined. The low byte is unspecified at reset and the upper bits read as zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `contexts` | established |  |  | One event bit per isochronous transmit context |

### Register `iso_xmit_mask`

Isochronous transmit mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 7:0 are defined. The low byte is unspecified at reset and the upper bits read as zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `contexts` | established |  |  | One mask bit per isochronous transmit context |

### Register `iso_recv_event`

Isochronous receive event. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 3:0 are defined, one per context. The low nibble is unspecified at reset and the upper bits read as zero. The datasheet summary does not state the context count, so four contexts is inferred from the bit count.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `contexts` | inferred |  |  | One event bit per isochronous receive context. The count of four is inferred from the defined bits |

### Register `iso_recv_mask`

Isochronous receive mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 3:0 are defined. The low nibble is unspecified at reset and the upper bits read as zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `contexts` | inferred |  |  | One mask bit per isochronous receive context. The count of four is inferred from the defined bits |

### Register `fairness_control`

Optional fairness control. The low byte is a read-only priority-request limit that resets to zero. The upper bits are unspecified at reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `priority_request_limit` | established |  |  | Read-only priority-request limit, resets to zero |

### Register `link_control`

Link control. The set and clear addresses form a pair, the clear address four bytes above the set address. The defined bits are unspecified at reset and the other bits in the datasheet's diagram reset to zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22 | `cycle_source` | established |  |  | Cycle source |
| 21 | `cycle_master` | established |  |  | Cycle master |
| 20 | `cycle_timer_enable` | established |  |  | Cycle timer enable |
| 10 | `rcv_phy_packets` | established |  |  | Receive PHY packets |
| 9 | `rcv_self_id_packets` | established |  |  | Receive self-ID packets |

### Register `node_id`

Node ID. Validity, root and cable-power status are read and updated by the controller and reset to zero. The bus number resets to all ones. The physical node number is unspecified at reset. The datasheet names a cable-power status bit but its position is not in the summary, so it is not listed as a field.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `id_valid` | established |  |  | Node ID valid, read and updated, reset zero |
| 30 | `root` | established |  |  | This node is root, read and updated, reset zero |
| 15:6 | `bus_number` | established |  |  | Bus number, read-write, resets to all ones |
| 5:0 | `node_number` | established |  |  | Physical node number, read and updated, unspecified at reset |

### Register `phy_control`

PHY access. A PHY read and a PHY write are mutually exclusive. Command bits read as zero at reset. Data and status fields are largely unspecified at reset. A PHY register transfer received from the PHY sets rdDone and the PHY-register-received event.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `rd_done` | established |  |  | PHY read complete, set when a read finishes |
| 27:24 | `rd_addr` | established |  |  | PHY register address of the completed read |
| 23:16 | `rd_data` | established |  |  | PHY register data returned by a read |
| 15 | `rd_reg` | established |  |  | PHY register read request |
| 14 | `wr_reg` | established |  |  | PHY register write request |
| 11:8 | `reg_addr` | established |  |  | PHY register address for a request |
| 7:0 | `wr_data` | established |  |  | PHY register data for a write |

### Register `cycle_timer`

Cycle timer. Unspecified at reset. The counter fields count seconds, cycles and offset ticks at 24.576 MHz.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:25 | `seconds` | established |  |  | Seconds, modulo 128 |
| 24:12 | `count` | established |  |  | Cycle count, modulo 8000 |
| 11:0 | `offset` | established |  |  | Offset ticks at 24.576 MHz, modulo 3072 |

### Register `async_filter_hi`

Asynchronous request source filter, upper node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bit 31 enables requests from nonlocal buses.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `nonlocal_enable` | established |  |  | Accept asynchronous requests from nonlocal buses |

### Register `async_filter_lo`

Asynchronous request source filter, lower node mask. The set and clear addresses form a pair, the clear address four bytes above the set address.

### Register `phys_filter_hi`

Physical request source filter, upper node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. The filter applies after the asynchronous filter, and a rejected physical request falls through to asynchronous receive.

### Register `phys_filter_lo`

Physical request source filter, lower node mask. The set and clear addresses form a pair, the clear address four bytes above the set address.

### Register `phys_upper_bound`

Physical upper bound. It is optional and this part does not implement it, so it reads as zero.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BUS_ID_TEXT` | 0x31333934 | established |  | Constant BusID value. It is the ASCII text 1394 in big-endian byte order. |
| `CYCLE_TIMER_CLOCK_HZ` | 0x1770000 | established |  | Clock the cycle timer counts at, 24.576 MHz. The offset field counts it modulo 3072. |
| `ISO_CHANNELS` | 0x40 | established |  | Isochronous channels the receive channel masks represent, one bit each across the low and high mask words. |
| `MAX_REC_DEFAULT` | 0xa | established |  | Hardware default of the max_rec field of BusOptions, which encodes a 2048-byte maximum receive packet. It survives SoftReset. |
| `PCI_DEVICE_ID` | 0x8009 | established |  | PCI device ID of the TSB12LV22 link controller. |
| `PCI_REVISION` | 0x1 | established |  | Revision ID the datasheet gives for this part. The PCI revision byte is what the IRIX inventory prints as the unit version; see the software expectations in the prose page. |
| `PCI_VENDOR_ID` | 0x104c | established |  | PCI vendor ID of Texas Instruments. |
| `PHY_CLOCK_HZ` | 0x2ee0000 | established |  | Clock the attached PHY supplies to the link controller, 49.152 MHz. |
| `SELF_ID_BUFFER_ALIGN` | 0x800 | established |  | Alignment in bytes of the self-ID buffer pointer. Its low 11 bits read as zero. |
