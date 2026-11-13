<!-- generated from devices/tl16pir552/registers.toml by defs-gen - do not edit, change the source -->

# TI TL16PIR552 dual UART and IEEE 1284 parallel port, parallel-port register contract (Fuel and Origin 200 board part)

The parallel-port block of the TI TL16PIR552, the part marked on a revision B Fuel system board and on an Origin 200 system board. The registers are selected by three address bits and a chip select, and what an address holds depends on the mode in the ECR register, so each mode's view of the same address is its own space. Grades say how each item was derived: established means the TI datasheet states it, inferred means a reading of the datasheet's own list of bits or a reasoned extension, and unknown means the sources do not settle it. The UART channels are not described here. Fuel's wiring of this part to the IOC3, its address decode, its interrupt routing and its DMA connection are not established by these sources and are not listed. Reset values are unknown except where the datasheet states them.

Unit `tl16pir552`, macro prefix `TL16PIR552`.
Default source: TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| ppcs | byte | Parallel-port chip select (PPCS). Offsets are the three address bits. Registers here exist in every mode, or only in the standard and EPP modes; the ECP-mode view of offset 0 is its own space. |
| ppcs_ecp | byte | Offset 0 of the PPCS chip select in ECP mode. The same address as the standard data register in the ppcs space; the mode selects which one answers. |
| ecpcs | byte | ECP chip select (ECPCS) registers that exist in every mode or in the configuration mode. |
| ecpcs_ecp | byte | Offset 0 of the ECPCS chip select in ECP mode. |
| ecpcs_cfifo | byte | Offset 0 of the ECPCS chip select in parallel FIFO (CFIFO) mode. |
| ecpcs_tfifo | byte | Offset 0 of the ECPCS chip select in test FIFO mode. |
| ecpcs_cfg | byte | Offset 0 of the ECPCS chip select in configuration mode. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `cnfgb` | 0x1 | r | 8 |  | ecpcs | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `ecr` | 0x2 | rw | 8 |  | ecpcs | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `cnfga` | 0x0 | r | 8 |  | ecpcs_cfg | 0x1f | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `pp_fifo` | 0x0 | rw | 8 |  | ecpcs_cfifo | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `ecp_dfifo` | 0x0 | rw | 8 |  | ecpcs_ecp | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `test_fifo` | 0x0 | rw | 8 |  | ecpcs_tfifo | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `data` | 0x0 | rw | 8 |  | ppcs | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `dsr` | 0x1 | r | 8 |  | ppcs | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `dcr` | 0x2 | rw | 8 |  | ppcs | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `epp_addr` | 0x3 | rw | 8 |  | ppcs | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `epp_data` | 0x4 | rw | 8 | 4 | ppcs | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `ecp_afifo` | 0x0 | w | 8 |  | ppcs_ecp | unknown | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |

### Register `cnfgb`

Configuration register B, read only. Its IRQ-line sample bit depends on the board wiring, so its reset value is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `compression` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Compression. Reads zero: compression is unsupported. |
| 6 | `irq_line_sample` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Samples the IRQ line. The sampled value depends on the board. |
| 5:3 | `irq_select` | established | cnfgb_irq_select (irq7=1) | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Reports the IRQ selection. Reads 001, which the datasheet names IRQ7. |
| 2:0 | `dma_select` | established | cnfgb_dma_select (dma3=3) | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Reports the DMA channel selection. Reads 011, which the datasheet names DMA channel 3. |

### Register `ecr`

Extended control register. Its top three bits select the mode, which also decides what the other chip-select offsets hold. The two low bits are read only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:5 | `mode` | established | ecr_mode (standard=0, bidirectional=1, parallel_fifo=2, ecp=3, epp=4, reserved=5, test_fifo=6, configuration=7) | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Mode select. The value decides which register the chip-select offsets 0 and 1 answer as. |
| 4 | `ecp_fault_irq_disable` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | In ECP mode, zero enables the interrupt on a falling FAULT edge. |
| 3 | `dma_enable` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Enables DMA. |
| 2 | `service_intr_disable` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | One disables DMA and all service interrupts. |
| 1 | `fifo_full` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | FIFO full. Read only. |
| 0 | `fifo_empty` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | FIFO empty. Read only. |

### Register `cnfga`

Configuration register A, read only. It reads the constant with the implementation ID in the top nibble and the low nibble reserved and read as ones.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `impl_id` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Implementation ID. Reads as one. |
| 3:0 | `reserved_low` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Reserved. Reads as ones. |

### Register `pp_fifo`

Forward data FIFO that uses the standard parallel-port handshake.

### Register `ecp_dfifo`

ECP data FIFO. A forward write enqueues data. A reverse read receives peripheral data through the ECP handshake.

### Register `test_fifo`

Test FIFO with no parallel-port protocol handshake. FIFO state stays reflected by the FULL and EMPTY bits. Overflow and underrun do not stall. Read and write counters wrap in test mode.

### Register `data`

Parallel data port in standard and bidirectional modes. A write drives the data lines and a read returns their value. In the other modes offset 0 of this chip select is a different register; see the ECP-mode and FIFO spaces.

### Register `dsr`

Status inputs, plus the PRINT and EPP TIMEOUT status. PRINT clears on a rising ACK and sets when this register is read. TIMEOUT clears when this register is written. The bit positions are not stated in the sources consulted and are not listed.

### Register `dcr`

Parallel control register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `direction` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Direction. Puts the data lines in high impedance (reverse) when set. It has no effect in standard mode or in the parallel FIFO mode. |
| 4 | `irq_on_ack` | established |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Enables an interrupt on a rising ACK. |
| 3 | `select_ctl` | inferred |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Drives the SELECT control line. |
| 2 | `init_ctl` | inferred |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Drives the INIT control line. |
| 1 | `autofd_ctl` | inferred |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Drives the AUTOFD control line. |
| 0 | `strobe_ctl` | inferred |  | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) | Drives the STROBE control line. |

### Register `epp_addr`

EPP address. An access generates the EPP address strobe automatically.

### Register `epp_data`

EPP data. Each of the four offsets with the high address bit set is this register. An access generates the EPP data strobe automatically.

Array of 4 registers, stride 1.

### Register `ecp_afifo`

ECP address FIFO. A written byte enters the FIFO tagged as an ECP address.

## Enums

### Enum `cnfgb_dma_select`

| Label | Value | Grade | Source |
|---|---|---|---|
| `dma3` | 3 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |

### Enum `cnfgb_irq_select`

| Label | Value | Grade | Source |
|---|---|---|---|
| `irq7` | 1 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |

### Enum `ecr_mode`

| Label | Value | Grade | Source |
|---|---|---|---|
| `standard` | 0 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `bidirectional` | 1 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `parallel_fifo` | 2 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `ecp` | 3 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `epp` | 4 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `reserved` | 5 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `test_fifo` | 6 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
| `configuration` | 7 | established | TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) |
