<!-- generated from devices/ice1724/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 dd9a3eb1279d5d296b0ebe4786280e365b30feac027d7ff9ddb8d012a80e8ecf -->

# VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller registers

Unit `ice1724`, macro prefix `ICE1724`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| pci | byte | PCI configuration header and capability registers. |
| ccs | byte | Controller registers, BAR0 (32 bytes of I/O space). |
| mt | byte | Multi-channel registers, BAR1 (128 bytes of I/O space). |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `ccs_control` | 0x0 | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_irq_mask` | 0x1 | rw | 8 |  | ccs | 0xfe | established |  |
| `ccs_irq_status` | 0x2 | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_system_config` | 0x4 | rw | 8 |  | ccs | 0xf | established |  |
| `ccs_ac97_config` | 0x5 | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_i2s_features` | 0x6 | rw | 8 |  | ccs | 0x1 | established |  |
| `ccs_spdif_config` | 0x7 | rw | 8 |  | ccs | 0x1 | established |  |
| `ccs_uart_tx_count` | 0xa | r | 8 |  | ccs | 0x0 | established |  |
| `ccs_uart_rx_count` | 0xb | r | 8 |  | ccs | 0x0 | established |  |
| `ccs_midi_data` | 0xc | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_midi_command` | 0xd | rw | 8 |  | ccs | 0x0 | unknown |  |
| `ccs_uart_setting` | 0xe | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_i2c_device` | 0x10 | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_i2c_byte` | 0x11 | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_i2c_data` | 0x12 | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_i2c_status` | 0x13 | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_gpio_data` | 0x14 | rw | 16 |  | ccs | 0x0 | established |  |
| `ccs_gpio_mask` | 0x16 | rw | 16 |  | ccs | 0xffff | established |  |
| `ccs_gpio_direction` | 0x18 | rw | 32 |  | ccs | 0x0 | established |  |
| `ccs_power_down` | 0x1c | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_gpio_data_hi` | 0x1e | rw | 8 |  | ccs | 0x0 | established |  |
| `ccs_gpio_mask_hi` | 0x1f | rw | 8 |  | ccs | 0xff | established |  |
| `mt_irq_status` | 0x0 | rw | 8 |  | mt | 0x0 | established |  |
| `mt_sampling_rate` | 0x1 | rw | 8 |  | mt | 0x0 | established |  |
| `mt_i2s_format` | 0x2 | rw | 8 |  | mt | 0x0 | established |  |
| `mt_irq_mask` | 0x3 | rw | 8 |  | mt | 0xff | established |  |
| `mt_ac97_index` | 0x4 | rw | 8 |  | mt | 0x0 | established |  |
| `mt_ac97_command` | 0x5 | rw | 8 |  | mt | 0x0 | established |  |
| `mt_ac97_data` | 0x6 | rw | 16 |  | mt | 0x0 | established |  |
| `mt_pdmai_address` | 0x10 | rw | 32 |  | mt | 0x0 | established |  |
| `mt_pdmai_count` | 0x14 | rw | 32 |  | mt | 0x0 | established |  |
| `mt_dma_start` | 0x18 | rw | 8 |  | mt | 0x0 | established |  |
| `mt_pdmai_streams` | 0x19 | rw | 8 |  | mt | 0x0 | established |  |
| `mt_dma_underrun` | 0x1a | rw | 8 |  | mt | 0x0 | established |  |
| `mt_dma_pause` | 0x1b | rw | 8 |  | mt | 0x0 | established |  |
| `mt_pdmai_terminal` | 0x1c | w | 32 |  | mt | 0x0 | established |  |
| `mt_rdma0_address` | 0x20 | rw | 32 |  | mt | 0x0 | established |  |
| `mt_rdma0_count` | 0x24 | rw | 16 |  | mt | 0x0 | established |  |
| `mt_rdma0_terminal` | 0x26 | w | 16 |  | mt | 0x0 | established |  |
| `mt_routing` | 0x2c | rw | 32 |  | mt | 0x0 | inferred |  |
| `mt_rdma1_address` | 0x30 | rw | 32 |  | mt | 0x0 | established |  |
| `mt_rdma1_count` | 0x34 | rw | 16 |  | mt | 0x0 | established |  |
| `mt_rdma1_terminal` | 0x36 | w | 16 |  | mt | 0x0 | established |  |
| `mt_spdif_control` | 0x3c | rw | 16 |  | mt | unknown | established |  |
| `mt_peak_index` | 0x3e | rw | 8 |  | mt | 0x0 | established |  |
| `mt_peak_data` | 0x3f | r | 8 |  | mt | 0x0 | established |  |
| `mt_pdma_address` | 0x40 | rw | 32 | 4 | mt | 0x0 | established |  |
| `mt_pdma_count` | 0x44 | rw | 16 | 4 | mt | 0x0 | established |  |
| `mt_pdma_terminal` | 0x46 | w | 16 | 4 | mt | 0x0 | established |  |
| `pci_vendor_id` | 0x0 | r | 16 |  | pci | 0x1412 | established |  |
| `pci_device_id` | 0x2 | r | 16 |  | pci | 0x1724 | established |  |
| `pci_command` | 0x4 | rw | 16 |  | pci | 0x0 | established |  |
| `pci_status` | 0x6 | rw | 16 |  | pci | 0x210 | established |  |
| `pci_revision` | 0x8 | r | 8 |  | pci | unknown | established |  |
| `pci_class` | 0xa | r | 16 |  | pci | 0x401 | established |  |
| `pci_cache_line` | 0xc | r | 8 |  | pci | 0x0 | established |  |
| `pci_latency_timer` | 0xd | rw | 8 |  | pci | 0x0 | established |  |
| `pci_header_type` | 0xe | r | 8 |  | pci | 0x0 | established |  |
| `pci_bist` | 0xf | r | 8 |  | pci | 0x0 | established |  |
| `pci_bar0` | 0x10 | rw | 32 |  | pci | 0x1 | established |  |
| `pci_bar1` | 0x14 | rw | 32 |  | pci | 0x1 | established |  |
| `pci_subsystem` | 0x2c | rw | 32 |  | pci | 0x17241412 | established |  |
| `pci_expansion_rom` | 0x30 | r | 32 |  | pci | 0x0 | established |  |
| `pci_capability_ptr` | 0x34 | r | 8 |  | pci | 0x80 | established |  |
| `pci_interrupt_line` | 0x3c | rw | 8 |  | pci | 0xff | established |  |
| `pci_interrupt_pin` | 0x3d | r | 8 |  | pci | 0x1 | established |  |
| `pci_grant_latency` | 0x3e | r | 16 |  | pci | 0x0 | established |  |
| `pci_svid_mask` | 0x42 | rw | 8 |  | pci | 0x0 | inferred |  |
| `pci_pm_capability_id` | 0x80 | r | 8 |  | pci | 0x1 | established |  |
| `pci_pm_next` | 0x81 | r | 8 |  | pci | 0x0 | established |  |
| `pci_pm_caps` | 0x82 | r | 16 |  | pci | 0x401 | established |  |
| `pci_pm_control` | 0x84 | rw | 16 |  | pci | 0x0 | established |  |
| `pci_pm_data` | 0x86 | r | 16 |  | pci | 0x0 | established |  |

### Register `ccs_control`

Bit 7 is a soft reset of the whole chip. The public driver writes 1, waits, then writes 0; the datasheet does not say whether the bit self-clears. Bits 6 to 0 are reserved.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `soft_reset` | established |  |  |  |

### Register `ccs_irq_mask`

Interrupt mask. A set bit masks the source. The datasheet states this polarity only for MT03; here it is inferred from the reset value and the driver's use. Every source is masked at reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `mpu_receive` | established |  |  |  |
| 5 | `mpu_transmit` | established |  |  |  |
| 4 | `multichannel` | established |  |  | The single mask for every playback and record engine |

### Register `ccs_irq_status`

Bits 7 and 5 are write-1-to-clear. Bit 4 is read only and clears when its source in the multi-channel register clears. Bits are sticky.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `mpu_receive` | established |  |  |  |
| 5 | `mpu_transmit` | established |  |  |  |
| 4 | `multichannel` | established |  |  |  |

### Register `ccs_system_config`

The public driver copies EEPROM bytes 6 to 9 here; the datasheet says the driver loads them, and hardware does not. The reset value means 24.576 MHz, no UART, no inputs and four stereo DACs.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `xin1_clock` | established | xin1_clock (clk24_576=0, clk49_152=1) |  |  |
| 5 | `mpu_uart` | established |  |  |  |
| 3:2 | `adc_inputs` | established | adc_inputs (one_stereo=0, two_stereo=1, one_stereo_spdif=2, none=3) |  |  |
| 1:0 | `dac_count_minus_one` | established |  |  | Stereo DAC count less one; one to four DACs, at least one required |

### Register `ccs_ac97_config`

Converter type and AC'97 slot layout. Bit 7 reflects the power-up strap on GPIO 0 in reverse and may be overwritten.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `converter_type` | established | converter_type (ac97=0, i2s=1) |  |  |
| 1 | `ac97_slot` | established | ac97_slot (split=0, packed=1) |  |  |

### Register `ccs_i2s_features`

Converter capabilities, written from the EEPROM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `volume_by_gpio` | established |  |  | Valid only when the converter type bit is 1 |
| 6 | `supports_96k` | established |  |  |  |
| 5:4 | `resolution` | established | resolution_bits (bits16=0, bits18=1, bits20=2, bits24=3) |  |  |
| 3 | `supports_192k` | established |  |  |  |
| 2:0 | `other_ids` | unknown |  |  | Named in the datasheet; the meaning is not given |

### Register `ccs_spdif_config`

S/PDIF transmitter enable and capability bits. Bit 6 is read only and reflects the SPDTX pin during reset, reversed: 0 means the transmitter is on the board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `transmitter_enable` | established |  |  | Valid only when bit 6 is 1; keep 0 while the transmitter mode fields change |
| 6 | `transmitter_present` | established |  |  |  |
| 5:2 | `spdif_ids` | unknown |  |  | Named in the datasheet; the meaning is not given |
| 1 | `spdif_input` | established |  |  |  |
| 0 | `external_output` | established |  |  |  |

### Register `ccs_uart_tx_count`

Valid bytes in the MPU-401 transmit FIFO, which is 32 deep.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `count` | established |  |  |  |

### Register `ccs_uart_rx_count`

Valid bytes in the MPU-401 receive FIFO, which is 32 deep.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `count` | established |  |  |  |

### Register `ccs_midi_data`

MPU-401 data port.

### Register `ccs_midi_command`

MPU-401 command and status. The datasheet gives no bit definitions. The public Linux driver's reading (bit 0 UART mode, bits 1 to 4 FIFO empty and full flags) is an expectation, not established.

### Register `ccs_uart_setting`

MPU-401 watermark. Both watermarks reset to 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `rx_mark_select` | established |  |  | 1: the watermark is the receive high mark; 0: the transmit low mark |
| 4:0 | `watermark` | established |  |  |  |

### Register `ccs_i2c_device`

Writing this register starts an I2C transfer, so the busy bit must be clear first. Device address 1010000 is reserved for the configuration EEPROM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:1 | `device` | established |  |  |  |
| 0 | `direction` | established | i2c_direction (read=0, write=1) |  |  |

### Register `ccs_i2c_byte`

I2C byte address.

### Register `ccs_i2c_data`

I2C data byte, written before a write transfer and read after a read transfer.

### Register `ccs_i2c_status`

Bit 7 mirrors the EEPROM strap on GPIO 3 at reset, so a board with an EEPROM reads 80. The printed reset 00 conflicts with that text; the text is taken. Bit 0 is busy. Bit 1 is reserved, keep 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `eeprom_present` | established |  |  |  |
| 0 | `busy` | established |  |  |  |

### Register `ccs_gpio_data`

GPIO data, bits 15 to 0. A bit takes a write only while its write-mask bit is 0. Bits 22 to 16 are in ccs_gpio_data_hi.

### Register `ccs_gpio_mask`

GPIO write mask, bits 15 to 0. Reset masks every bit, so no GPIO data can be written until software clears mask bits. Bits 22 to 16 are in ccs_gpio_mask_hi.

### Register `ccs_gpio_direction`

GPIO direction in three bytes, 0x18 to 0x1A. Bits 22 to 0 are defined: 0 is input, 1 is output. Bit 3 doubles as the EEPROM strap at reset; bit 2 is forced to input while the test-enable pin is active.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:0 | `direction` | established |  |  |  |

### Register `ccs_power_down`

Each bit set stops or powers down the named clock. Bits 6 and 1 are reserved. The ALSA driver writes 0 here, which is an expectation.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `xin1_clock` | established |  |  |  |
| 5 | `xin2_clock` | established |  |  |  |
| 4 | `i2c_clock` | established |  |  |  |
| 3 | `midi_clock` | established |  |  |  |
| 2 | `spdif_clock` | established |  |  |  |
| 0 | `serial_clock` | established |  |  | Multi-channel I2S serial clock |

### Register `ccs_gpio_data_hi`

GPIO data, bits 22 to 16 in bits 6 to 0. Masked by ccs_gpio_mask_hi.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:0 | `data` | established |  |  |  |

### Register `ccs_gpio_mask_hi`

GPIO write mask, bits 22 to 16 in bits 6 to 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:0 | `mask` | established |  |  |  |

### Register `mt_irq_status`

One bit per source; write 1 to clear. The multi-channel source bit in the controller's status register is inferred to be the OR of the unmasked bits here. Bit 3 is set by any underrun or overrun flag.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `spdif_out` | established |  |  |  |
| 6 | `pdma3` | established |  |  |  |
| 5 | `pdma2` | established |  |  |  |
| 4 | `pdma1` | established |  |  |  |
| 3 | `fifo_error` | established |  |  |  |
| 2 | `rdma1` | established |  |  |  |
| 1 | `rdma0` | established |  |  |  |
| 0 | `pdma0` | established |  |  | Interleaved playback, also PDMA0 |

### Register `mt_sampling_rate`

Sample rate. When bit 4 is 1 the rate code is ignored and the S/PDIF input clock is the master, with the master clock on the SPMCLKIN pin.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `spdif_input_master` | established |  |  |  |
| 3:0 | `rate_code` | established | rate_code (k48=0, k24=1, k12=2, k9_6=3, k32=4, k16=5, k8=6, k96=7, k44_1=8, k22_05=9, k11_025=10, k88_2=11, k176_4=12, unlisted_13=13, k192=14, k64=15) |  |  |

### Register `mt_i2s_format`

Clock ratio and data format. Bit 3 selects a 128x master clock; 176.4 kHz forces it. Bit 2 is listed read-write with no description.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `mclk_128x` | established |  |  |  |
| 2 | `bit2` | unknown |  |  | No description in the datasheet |
| 1:0 | `format` | established | i2s_format (i2s=0) |  |  |

### Register `mt_irq_mask`

Source mask, same bit layout as mt_irq_status. A set bit masks the source. Every source is masked at reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `spdif_out` | established |  |  |  |
| 6 | `pdma3` | established |  |  |  |
| 5 | `pdma2` | established |  |  |  |
| 4 | `pdma1` | established |  |  |  |
| 3 | `fifo_error` | established |  |  |  |
| 2 | `rdma1` | established |  |  |  |
| 1 | `rdma0` | established |  |  |  |
| 0 | `pdma0` | established |  |  |  |

### Register `mt_ac97_index`

AC'97 register index. Valid only in AC-link mode, though the drivers also use the converter reset bit in I2S mode.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:0 | `index` | established |  |  |  |

### Register `mt_ac97_command`

AC'97 command and status. The datasheet limits this register to AC-link mode. In I2S mode bit 7 is inferred to reset the converters, from the sibling part's datasheet and both drivers.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `cold_reset` | established |  |  |  |
| 6 | `warm_reset` | established |  |  |  |
| 5 | `write_cycle` | established |  |  | Write 1 to start; reads 1 while in progress |
| 4 | `read_cycle` | established |  |  | Write 1 to start; reads 1 while in progress |
| 3 | `codec_ready` | established |  |  |  |
| 1:0 | `codec_select` | established |  |  |  |

### Register `mt_ac97_data`

AC'97 data port.

### Register `mt_pdmai_address`

Start of the interleaved playback buffer. Bits 1 and 0 read 0, so the address is dword aligned. The datasheet says the field is in dword units; the drivers store the byte address unshifted, which is taken here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:2 | `address` | established |  |  |  |

### Register `mt_pdmai_count`

Buffer size in dwords less one, counting down as data moves. Reloads at zero, so the buffer wraps. Bits 18 to 0 are used.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 18:0 | `count` | established |  |  |  |

### Register `mt_dma_start`

Read-modify-write only. A 1 starts the stream and a 0 stops it. Bit 3 is read only, 0. Bit positions are the same as mt_irq_status.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `pdma4` | established |  |  |  |
| 6 | `pdma3` | established |  |  | Usable only when mt_pdmai_streams is above 0 |
| 5 | `pdma2` | established |  |  | Usable only when mt_pdmai_streams is above 1 |
| 4 | `pdma1` | established |  |  | Usable only when mt_pdmai_streams is 3 |
| 2 | `rdma1` | established |  |  |  |
| 1 | `rdma0` | established |  |  |  |
| 0 | `pdma0` | established |  |  |  |

### Register `mt_pdmai_streams`

Interleaved channel count; see enum interleave. Sets which of PDMA1 to PDMA3 are free.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1:0 | `interleave` | established | interleave (all_eight=0, first_six=1, first_four=2, first_pair=3) |  |  |

### Register `mt_dma_underrun`

Underrun on playback or overrun on record, per stream. Bit positions are the same as mt_dma_start. Write 1 to clear; any flag raises the interrupt through mt_irq_status bit 3.

### Register `mt_dma_pause`

Pause and resume, per stream; bit positions are the same as mt_dma_start. A 1 pauses and a 0 resumes.

### Register `mt_pdmai_terminal`

Interrupt interval in dwords less one. Counts down; at zero it raises the stream's source. Write only. The index line says 1C to 1D, but the layout covers 1C to 1E, which holds the 19-bit field.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 18:0 | `count` | established |  |  |  |

### Register `mt_rdma0_address`

Start of the first record buffer. Dword aligned, same encoding as mt_pdmai_address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:2 | `address` | established |  |  |  |

### Register `mt_rdma0_count`

Buffer size in dwords less one, counting down. Read the position only after at least two sample frames have passed.

### Register `mt_rdma0_terminal`

Interrupt interval in dwords less one. Write only.

### Register `mt_routing`

Source of each output channel, in I2S mode only, adding at most one sample time of delay. The layout is established; the zero reset is inferred from the printed 00h for a 32-bit register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:29 | `psdout3_right` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 28:26 | `psdout2_right` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 25:23 | `psdout1_right` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 22:20 | `psdout0_right` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 19:17 | `psdout3_left` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 16:14 | `psdout2_left` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 13:11 | `psdout1_left` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 10:8 | `psdout0_left` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 5:3 | `spdif_right` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |
| 2:0 | `spdif_left` | established | route_source (normal=0, psdin0_left=2, psdin0_right=3, spdin_left=6, spdin_right=7) |  |  |

### Register `mt_rdma1_address`

Start of the second record buffer. Dword aligned, same encoding as mt_pdmai_address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:2 | `address` | established |  |  |  |

### Register `mt_rdma1_count`

Buffer size in dwords less one, counting down.

### Register `mt_rdma1_terminal`

Interrupt interval in dwords less one. Write only.

### Register `mt_spdif_control`

S/PDIF transmitter channel status. Reads 0000 when the SPDTX pin is floating or high, and 2000 at power-up when the transmitter is fitted. Every field except validity is writable only while ccs_spdif_config bit 7 is 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `validity` | established |  |  | Validity flag |
| 14:12 | `spdif_rate` | established | spdif_rate (k44_1=0, reserved_1=1, k48=2, k32=3, k88_2=4, k96=5, k192=6, k176_4=7) |  |  |
| 11 | `generation_level` | established |  |  |  |
| 10:4 | `category` | established |  |  |  |
| 3 | `pre_emphasis` | established |  |  |  |
| 2 | `copyright` | established |  |  | 1 means copyright is not asserted |
| 1 | `non_audio` | established |  |  | 1 means non-PCM |
| 0 | `professional` | established |  |  |  |

### Register `mt_peak_index`

Stream to meter. 0 to 7 are the eight interleaved slots, 8 and 9 the S/PDIF left and right, 10 and 11 RDMA0, 18 and 19 RDMA1. Other values are ignored.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `index` | established |  |  |  |

### Register `mt_peak_data`

Peak level of the selected stream, the nine most significant bits of the level. Reading clears the peak.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `peak` | established |  |  |  |

### Register `mt_pdma_address`

Start of the playback buffer for the S/PDIF stream and the three extra stereo pairs. Element 0 is PDMA4 (S/PDIF), 1 is PDMA3, 2 is PDMA2, 3 is PDMA1. Dword aligned.

Array of 4 registers, stride 16.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:2 | `address` | established |  |  |  |

### Register `mt_pdma_count`

Buffer size in dwords less one, counting down. Element order as mt_pdma_address.

Array of 4 registers, stride 16.

### Register `mt_pdma_terminal`

Interrupt interval in dwords less one. Write only. Element order as mt_pdma_address.

Array of 4 registers, stride 16.

### Register `pci_vendor_id`

PCI vendor ID, IC Ensemble.

### Register `pci_device_id`

PCI device ID. The same ID is used by the VT1720 (Envy24PT), so it does not tell the parts apart.

### Register `pci_command`

Bit 1 (memory space) and bits 3 to 7 and 9 are hardwired to 0. The datasheet lists bit 8 as read-write but describes it as hardwired to 0; it reads 0 here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `bus_master` | established |  |  |  |
| 0 | `io_space` | established |  |  |  |

### Register `pci_status`

Bits 15 to 12 are write-1-to-clear. Bit 11 is hardwired to 0. Bit 14 reads 0. Bit 4 (capability list) is hardwired to 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `parity_error` | established |  |  |  |
| 13 | `master_abort` | established |  |  |  |
| 12 | `target_abort` | established |  |  |  |
| 10:9 | `devsel_timing` | inferred |  |  | The table says 10b; the text and the reset value say medium timing, 01b. |
| 4 | `capability_list` | established |  |  |  |

### Register `pci_revision`

Vendor revision. The datasheet shows it as a placeholder; the value is not given.

### Register `pci_class`

Class code: multimedia, audio. The field is 24 bits in the header; the programming interface byte at offset 0x09 reads 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `base_class` | established |  |  |  |
| 7:0 | `subclass` | established |  |  |  |

### Register `pci_cache_line`

Not supported; reads 0.

### Register `pci_latency_timer`

Writes take effect in eight-clock steps: writing FF reads back F8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:3 | `count` | established |  |  |  |

### Register `pci_header_type`

Type 0, single function.

### Register `pci_bist`

Built-in self test is not supported.

### Register `pci_bar0`

Controller registers (CCS), 32 bytes of I/O space. Bits 31 to 5 are the base.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:5 | `base` | established |  |  |  |

### Register `pci_bar1`

Multi-channel registers (MT), 128 bytes of I/O space. Bits 31 to 7 are the base.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:7 | `base` | established |  |  |  |

### Register `pci_subsystem`

Subsystem IDs. Loaded from the EEPROM after reset when one answers, otherwise the reset value. Writable only while the subsystem mask bit is set. Which EEPROM bytes map to which half is not documented.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `subsystem_device` | established |  |  |  |
| 15:0 | `subsystem_vendor` | established |  |  |  |

### Register `pci_expansion_rom`

Reserved; the part has no option ROM.

### Register `pci_capability_ptr`

Points to the power-management capability at 0x80.

### Register `pci_interrupt_line`

Set by firmware. FF means the interrupt is not routed.

### Register `pci_interrupt_pin`

INTA#.

### Register `pci_grant_latency`

Minimum grant in the low byte, maximum latency in the high byte. Both 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:8 | `max_latency` | established |  |  |  |
| 7:0 | `min_grant` | established |  |  |  |

### Register `pci_svid_mask`

The table places the subsystem ID mask at 0x40 and the register section at 0x42. Bit 7 is the control that makes the subsystem IDs writable. The offset is taken from the register section.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `writable` | inferred |  |  |  |

### Register `pci_pm_capability_id`

Capability ID: power management.

### Register `pci_pm_next`

End of the capability list.

### Register `pci_pm_caps`

Power management version 1.0. D2 is supported, D1 and PME are not.

### Register `pci_pm_control`

Power state select.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1:0 | `power_state` | established | pm_state (d0=0, d1=1, d2=2, d3hot=3) |  |  |

### Register `pci_pm_data`

Power management bridge extension and data. Read only, reset 0.

## Enums

### Enum `ac97_slot`

CCS05 bit 1, the AC'97 data slot layout.

| Label | Value | Grade | Source |
|---|---|---|---|
| `split` | 0 | established |  |
| `packed` | 1 | established |  |

### Enum `adc_inputs`

CCS04 bits 3:2, the physical stereo inputs.

| Label | Value | Grade | Source |
|---|---|---|---|
| `one_stereo` | 0 | established |  |
| `two_stereo` | 1 | established |  |
| `one_stereo_spdif` | 2 | established |  |
| `none` | 3 | established |  |

### Enum `converter_type`

CCS05 bit 7, the multi-channel converter type.

| Label | Value | Grade | Source |
|---|---|---|---|
| `ac97` | 0 | established |  |
| `i2s` | 1 | established |  |

### Enum `i2c_direction`

CCS10 bit 0.

| Label | Value | Grade | Source |
|---|---|---|---|
| `read` | 0 | established |  |
| `write` | 1 | established |  |

### Enum `i2s_format`

MT02 bits 1:0, the serial data format. Other values are reserved.

| Label | Value | Grade | Source |
|---|---|---|---|
| `i2s` | 0 | established |  |

### Enum `interleave`

MT19 bits 1:0, how many playback channels share the interleaved stream.

| Label | Value | Grade | Source |
|---|---|---|---|
| `all_eight` | 0 | established |  |
| `first_six` | 1 | established |  |
| `first_four` | 2 | established |  |
| `first_pair` | 3 | established |  |

### Enum `pm_state`

PCI PM control bits 1:0.

| Label | Value | Grade | Source |
|---|---|---|---|
| `d0` | 0 | established |  |
| `d1` | 1 | established |  |
| `d2` | 2 | established |  |
| `d3hot` | 3 | established |  |

### Enum `rate_code`

MT01 bits 3:0 when bit 4 is 0: the sample-rate code for the internal clock tree.

| Label | Value | Grade | Source |
|---|---|---|---|
| `k48` | 0 | established |  |
| `k24` | 1 | established |  |
| `k12` | 2 | established |  |
| `k9_6` | 3 | established |  |
| `k32` | 4 | established |  |
| `k16` | 5 | established |  |
| `k8` | 6 | established |  |
| `k96` | 7 | established |  |
| `k44_1` | 8 | established |  |
| `k22_05` | 9 | established |  |
| `k11_025` | 10 | established |  |
| `k88_2` | 11 | established |  |
| `k176_4` | 12 | established |  |
| `unlisted_13` | 13 | unknown |  |
| `k192` | 14 | established |  |
| `k64` | 15 | established |  |

### Enum `resolution_bits`

CCS06 bits 5:4, the I2S converter resolution.

| Label | Value | Grade | Source |
|---|---|---|---|
| `bits16` | 0 | established |  |
| `bits18` | 1 | established |  |
| `bits20` | 2 | established |  |
| `bits24` | 3 | established |  |

### Enum `route_source`

MT2C source select for one output channel. Routing works only in I2S mode.

| Label | Value | Grade | Source |
|---|---|---|---|
| `normal` | 0 | established |  |
| `psdin0_left` | 2 | established |  |
| `psdin0_right` | 3 | established |  |
| `spdin_left` | 6 | established |  |
| `spdin_right` | 7 | established |  |

### Enum `spdif_rate`

MT3C bits 14:12, the S/PDIF transmitter sample-rate field. Set from MT01 in master mode, by software in slave mode.

| Label | Value | Grade | Source |
|---|---|---|---|
| `k44_1` | 0 | established |  |
| `reserved_1` | 1 | established |  |
| `k48` | 2 | established |  |
| `k32` | 3 | established |  |
| `k88_2` | 4 | established |  |
| `k96` | 5 | established |  |
| `k192` | 6 | established |  |
| `k176_4` | 7 | established |  |

### Enum `xin1_clock`

CCS04 bits 7:6, the XIN1 crystal. Value 2 and 3 are reserved.

| Label | Value | Grade | Source |
|---|---|---|---|
| `clk24_576` | 0 | established |  |
| `clk49_152` | 1 | established |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CCS_AC97_CONF` | 0x5 | established |  | byte; read (bit 7 sets the per-device I2S converter flag) and written from EEPROM byte 7; role [I] |
| `CCS_GPIO_DATA` | 0x14 | established |  | 16-bit; GPIO data bits 15:0, read and written; role [I] |
| `CCS_GPIO_DATA_HI` | 0x1e | established |  | byte; GPIO data bits 22:16; role [I] |
| `CCS_GPIO_DIR` | 0x18 | established |  | 32-bit; GPIO direction, 24 bits used, loaded from EEPROM bytes 10 to 12; role [I] |
| `CCS_GPIO_MASK` | 0x16 | established |  | 16-bit; GPIO write mask bits 15:0, loaded from EEPROM bytes 13 and 14; role [I] |
| `CCS_GPIO_MASK_HI` | 0x1f | established |  | byte; GPIO write mask bits 22:16, loaded from EEPROM byte 15; role [I] |
| `CCS_I2C_BYTE_ADDR` | 0x11 | established |  | byte; role [I] |
| `CCS_I2C_CTRL` | 0x13 | established |  | byte; bit 7 tested (EEPROM present) and bit 0 polled for busy; role [I] |
| `CCS_I2C_DATA` | 0x12 | established |  | byte; read; role [I] |
| `CCS_I2C_DEV_ADDR` | 0x10 | established |  | byte; the driver writes 0xa0 for the EEPROM; role [I] |
| `CCS_I2S_FEATURES` | 0x6 | established |  | byte; written from EEPROM byte 8; role [I] |
| `CCS_IRQ_MASK` | 0x1 | inferred |  | byte; never touched by the shipped driver; 1 = masked, reset FE per the vendor datasheet; the driver therefore never gets an interrupt |
| `CCS_IRQ_STATUS` | 0x2 | inferred |  | byte; never touched by the shipped driver |
| `CCS_SPDIF_CONF` | 0x7 | established |  | byte; read (bit 0 sets the digital-output-present flag) and written from EEPROM byte 9; role [I] |
| `CCS_SYSCONF` | 0x4 | established |  | byte; access r (bits 1:0 read) and w (EEPROM byte 6; the driver stores 0x40 when no EEPROM answers); role [I]: system configuration, bits 1:0 = number of stereo DACs less one (value 3 gives 8 analog output channels, 0 to 2 give 2) |
| `MT_BURST` | 0x19 | established |  | byte; written 0 when analog output has 8 channels, 3 otherwise; role [I] |
| `MT_CAPTURE_ADDR` | 0x20 | established |  | 32-bit; capture buffer address; role [I] |
| `MT_CAPTURE_SIZE` | 0x24 | established |  | 16-bit; capture size, dword count less one (16-bit field); also read back as the DMA position; "current address" semantics [I] |
| `MT_CONVERTER_RESET` | 0x5 | established |  | byte; bit 7 set, 10 microsecond delay, then cleared during a rate change; role [I] (a converter reset line) |
| `MT_DMA_CONTROL` | 0x18 | established |  | byte; the driver keeps a shadow and writes it at start and stop: bit 0 analog output stream, bit 1 capture stream, bit 7 digital output stream; bit roles [I] |
| `MT_DMA_INT_MASK` | 0x3 | inferred |  | byte; never touched by the shipped driver; 1 = masked, reset FF per the vendor datasheet |
| `MT_IRQ_STATUS` | 0x0 | inferred |  | byte; never touched by the shipped driver; write 1 to clear |
| `MT_MCLK_128X` | 0x2 | established |  | byte; bit 3 set for rates of 120000 Hz and above, cleared below; "128x master clock" role [I] |
| `MT_PLAYBACK_ADDR` | 0x10 | established |  | 32-bit; start address of the playback buffer; role [I] |
| `MT_PLAYBACK_SIZE` | 0x14 | established |  | 32-bit; written with the dword count less one: the driver zeroes count<<2 bytes of the buffer and programs count-1 (mad_start_dma 0xe70..0xe98, 0xf90..0xf98); matches the vendor datasheet and Linux, OpenBSD, FreeBSD [E] for the arithmetic, byte unit of the zeroing call [I] |
| `MT_RATE` | 0x1 | established |  | byte; sample rate code written by the rate routine: 0 for 48 kHz, 4 for 32 kHz, 2 for 12 kHz, 11 for 88.2 kHz equal the public driver's table |
| `MT_SPDIF_OUT_ADDR` | 0x40 | established |  | 32-bit; digital output buffer address; role [I] |
| `MT_SPDIF_OUT_SIZE` | 0x44 | established |  | 16-bit; digital output size; role [I] |
