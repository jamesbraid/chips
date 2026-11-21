<!-- generated from devices/dm2/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 534766be60c23e754f44497a1ac59c97d036d7a9c9fb7fc107d2d08156f5526b -->

# DMediaPro DM2 (XT-DIGVID) XIO video board: widget window, XG block, FPGA load, GIF register file and word layouts

Register and word contract of the DM2 board's 16 MiB widget window, as the shipped kernel driver, the user-space media module and the board's diagnostic use it. Every offset is a byte offset from the window base and every register is a 32-bit word. Grades follow the contract pages: established means the access was read in full from a shipped binary, inferred means the item is reasoned from names or shape, unknown means nothing shipped settles it. Where a position or formula is established and only the role is inferred, the item is graded established and its doc says what is inferred. The GIF register file (window base plus 0x800000) is a file of 64-bit slots at an 8-byte stride. Software only ever reaches the odd (low) 32-bit word of a slot, at slot base plus 4, so every GIF register here is listed as 0x800000 + R + 4, where R is the register number (the slot offset) that the library and the diagnostic use. The input and output colour-converter blocks have two register layouts, one per FPGA image, and the two are not unified: they live in separate address spaces, xcc_prog (the images the media module loads) and xcc_diag (the images only the diagnostic loads). No reset value of any register is known.

Unit `dm2`, macro prefix `DM2`.
Default source: shipped kernel driver and media library readings.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| xcc_prog | byte | Colour-converter registers as the library programs them, for the ixcc and oxcc images it loads. |
| xcc_diag | byte | Colour-converter registers as the diagnostic's table names them, for the ixcc_2 and oxcc_2 images only the diagnostic loads. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `widget_id` | 0x4 | r | 32 |  |  | unknown | established | shipped diagnostic tables |
| `widget_status` | 0xc | r | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `widget_control` | 0x24 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `xg_req_timeout` | 0x2c | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `int_dest_hi` | 0x34 | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `int_dest_lo` | 0x3c | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `xg_int_vectors` | 0x5c | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `xg_config` | 0x64 | r | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `xg_error_cause` | 0x6c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `xg_water_mark` | 0x74 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `xg_mapram_err_addr` | 0x94 | r | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `xg_nic` | 0x9c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `fpga_prog` | 0x120000 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `gif_reset` | 0x800004 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `gif_prog_control` | 0x80000c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `pipe_dma_control` | 0x800014 | rw | 32 | 2 |  | unknown | established | shipped kernel driver and media library readings |
| `pipe_start_addr1` | 0x80001c | rw | 32 | 2 |  | unknown | established | shipped kernel driver and media library readings |
| `pipe_start_addr2` | 0x800024 | rw | 32 | 2 |  | unknown | established | shipped kernel driver and media library readings |
| `pipe_vid_control` | 0x80002c | rw | 32 | 2 |  | unknown | established | shipped kernel driver and media library readings |
| `pipe_vid_control2` | 0x800034 | rw | 32 | 2 |  | unknown | established | shipped kernel driver and media library readings |
| `pipe1_ring_ptr_reset` | 0x800064 | w | 32 |  |  | unknown | inferred | shipped kernel driver and media library readings |
| `pipe1_reset_word` | 0x80006c | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `pipe0_ring_ptr_reset` | 0x800074 | w | 32 |  |  | unknown | inferred | shipped kernel driver and media library readings |
| `pipe0_reset_word` | 0x80007c | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `gif_ident` | 0x800084 | r | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `ust_msc_counter` | 0x80008c | rw | 32 |  |  | unknown | inferred | shipped kernel driver and media library readings |
| `pack_r0800` | 0x800804 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `pack_r0808` | 0x80080c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `pack_r0810` | 0x800814 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `pack_misc_sel` | 0x800824 | rw | 32 |  |  | unknown | established | shipped diagnostic tables |
| `pack_r0840` | 0x800844 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `pack_r0848` | 0x80084c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `pack_r0850` | 0x800854 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `unpack_r1000` | 0x801004 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `unpack_r1008` | 0x80100c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `unpack_version_sel` | 0x801014 | rw | 32 |  |  | unknown | established | shipped diagnostic tables |
| `unpack_misc_sel` | 0x80101c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `unpack_idma_data_sel` | 0x801024 | rw | 32 | 2 |  | unknown | established | shipped diagnostic tables |
| `unpack_ovfifo_test_pattern_sel` | 0x801034 | rw | 32 | 2 |  | unknown | established | shipped diagnostic tables |
| `unpack_r1040` | 0x801044 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `unpack_r1048` | 0x80104c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `vif_control` | 0x801804 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `vif_enable` | 0x80180c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `vif_scratch` | 0x801814 | rw | 32 |  |  | unknown | inferred | shipped diagnostic tables |
| `vif_dmux` | 0x80182c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `vif_f0_actvid` | 0x801884 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `vif_f1_actvid` | 0x80188c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `vif_lines_per_frame` | 0x801894 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_status` | 0x802004 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_enable` | 0x80200c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_format` | 0x802014 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_xcc_rden` | 0x80201c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_trs_hblank` | 0x802024 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_line_regs` | 0x80202c | rw | 32 | 5 |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_xcc_rden2` | 0x802054 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_vitc_sel` | 0x80205c | rw | 32 |  |  | unknown | established | shipped diagnostic tables |
| `hdoc_resync` | 0x802064 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_resync_wndw` | 0x80206c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_data_rden` | 0x802074 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `hdoc_fifo_wen_sel` | 0x80207c | rw | 32 | 2 |  | unknown | established | shipped diagnostic tables |
| `hdoc_diag_regs` | 0x8020b4 | rw | 32 | 8 |  | unknown | inferred | shipped diagnostic tables |
| `clink_tx_message` | 0x803804 | w | 32 | 12 |  | unknown | established | shipped kernel driver and media library readings |
| `clink_pgen_lo` | 0x803864 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `clink_pgen_hi` | 0x80386c | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `clink_ksync_sel` | 0x803874 | rw | 32 |  |  | unknown | established | shipped diagnostic tables |
| `clink_rx_message` | 0x803884 | r | 32 | 12 |  | unknown | established | shipped kernel driver and media library readings |
| `clink_uart_reset` | 0x8038e4 | rw | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `clink_tx_doorbell` | 0x8038ec | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `clink_rx_release` | 0x8038f4 | w | 32 |  |  | unknown | established | shipped kernel driver and media library readings |
| `ixcc_diag_control0` | 0x802804 | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `ixcc_diag_control1` | 0x80280c | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `ixcc_diag_lut_control` | 0x802814 | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `ixcc_diag_lut_data` | 0x80281c | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `oxcc_diag_control0` | 0x803004 | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `oxcc_diag_control1` | 0x80300c | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `oxcc_diag_lut_control` | 0x803014 | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `oxcc_diag_lut_data` | 0x80301c | rw | 32 |  | xcc_diag | unknown | established | shipped diagnostic tables |
| `ixcc_prog_lut_control` | 0x802804 | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `ixcc_prog_lut_data` | 0x80280c | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `ixcc_prog_offset` | 0x802814 | rw | 32 | 4 | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `ixcc_prog_misc` | 0x802834 | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `ixcc_prog_alpha` | 0x80283c | rw | 32 | 2 | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `ixcc_prog_coeflo` | 0x80284c | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `ixcc_prog_coefhi` | 0x802854 | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `ixcc_prog_coefind` | 0x80285c | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_lut_control` | 0x803004 | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_lut_data` | 0x80300c | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_offset_lo` | 0x803014 | rw | 32 | 3 | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_offset_bit16` | 0x80301c | rw | 32 | 3 | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_around` | 0x803044 | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_pack8` | 0x80304c | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_dec` | 0x803054 | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_coeflo` | 0x80305c | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_coefhi` | 0x803064 | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |
| `oxcc_prog_coefind` | 0x80306c | rw | 32 |  | xcc_prog | unknown | established | shipped kernel driver and media library readings |

### Register `widget_id`

Widget identification, read by the diagnostic only; the kernel never reads it. The field split is established; the readback value is unknown (the part and manufacturer the driver registers with are not read from this register).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `revision` | established |  | shipped diagnostic tables |  |
| 27:12 | `part` | established |  | shipped diagnostic tables |  |
| 11:1 | `manufacturer` | established |  | shipped diagnostic tables |  |

### Register `widget_status`

Widget status. The kernel reads it once at attach and tests bit 5 only: when set it prints that the XIO slot is the slower 400 MB/s kind. The test is established; what the bit encodes is unknown (the message says link speed).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `link_slow` | established |  | shipped kernel driver and media library readings |  |

### Register `widget_control`

Widget control (the diagnostic calls it the XG control register). The init routine stores widget id, interrupt target and a constant, then ORs the XG error interrupt enable; the error handler clears the enable first and nothing sets it again. The low nibble comes from the widget's own number and bits 25:22 from the target widget of the XG error interrupt object, both inferred from the helper names. The same target value is also stored in the interrupt destination upper word, bits 19:16. Because the map RAM entry carries no widget field and this is the only other place a target widget is stored, bits 25:22 are the inferred home of the target widget for the board's own DMA requests; nothing in the shipped software states it. Bits 14 and 9 are written as constants and are unexplained. The only routine that sets bit 17 is the XG init routine, which runs at attach and again from the board-reset ioctl; the error handler and the detach routine clear it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:22 | `int_target` | inferred |  | shipped kernel driver and media library readings | target widget of the interrupt object (established store); that it also selects the DMA target widget is inferred |
| 17 | `xg_error_int_enable` | established |  | shipped kernel driver and media library readings | role established from the handler's own disable and the diagnostic's messages; that nothing else lives in the bit is inferred |
| 14 | `const_bit14` | unknown |  | shipped kernel driver and media library readings |  |
| 9 | `const_bit9` | unknown |  | shipped kernel driver and media library readings |  |
| 3:0 | `widget_number` | inferred |  | shipped kernel driver and media library readings |  |

### Register `xg_req_timeout`

Request timeout, the odd word of common-block slot 0x28. The only access in the shipped software is a store of 0 in the routine the XG init routine calls just before it enables the error interrupt (after reading the error cause word, printing a message if it is non-zero, and before writing the cause word back). Never read. The store is established; the role (the common block's request timeout, here left disabled or at its minimum) is inferred from the slot's role in the common widget block.

### Register `int_dest_hi`

Interrupt destination, upper: address bits 47:32 in the low half and the target widget id above them, from the interrupt object the kernel allocated for the XG error interrupt. The driver asserts that the two video interrupt objects have the same address and target as the error interrupt, so one destination serves all three. Store established; field names inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:16 | `target_id` | inferred |  | shipped kernel driver and media library readings |  |
| 15:0 | `addr_hi` | inferred |  | shipped kernel driver and media library readings |  |

### Register `int_dest_lo`

Interrupt destination, lower: the low 32 bits of the interrupt address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `addr_lo` | established |  | shipped kernel driver and media library readings |  |

### Register `xg_int_vectors`

XG interrupt vectors. In the common widget block this slot is an error command word; in the XG it holds interrupt vectors, so the common role does not apply (established for the XG use, inferred that the divergence is deliberate; no read exists). Bits 17 and 8 are ORed in as constants and are inferred to be per-source enables, which one is which is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:18 | `error_vector` | established |  | shipped kernel driver and media library readings |  |
| 17 | `const_bit17` | inferred |  | shipped kernel driver and media library readings |  |
| 16:9 | `gv1_vector` | established |  | shipped kernel driver and media library readings |  |
| 8 | `const_bit8` | inferred |  | shipped kernel driver and media library readings |  |
| 7:0 | `gv0_vector` | established |  | shipped kernel driver and media library readings |  |

### Register `xg_config`

XG configuration, read at attach and by the diagnostic; read-only from software. The subsystem field must read 1. The map-RAM size code is printed by the kernel as the code times 32 kilobytes; the table from size code to real size is unknown. The type code indexes a three-string table (order established).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `mapram_type` | established | xg_mapram_type (k32x36=0, k64x18=1, k128x9=2, invalid=3) | shipped kernel driver and media library readings |  |
| 5:3 | `mapram_size_code` | established |  | shipped kernel driver and media library readings |  |
| 2:0 | `subsystem` | established |  | shipped kernel driver and media library readings |  |

### Register `xg_error_cause`

XG error cause, one bit per error. The error handler reads it, writes the same value back before decoding, and prints one message per set bit. That the write-back is write-one-to-clear is inferred. Bit 22 is tested twice in the shipped handler and prints both a cache-line and a double-word underflow message; bit 24 is never tested. The intended assignment of bit 24 (graphics double-word credit underflow) is inferred; the diagnostic writes 0 here. Bit 31 has no test in the handler's shift sequence.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `bit31_untested` | unknown |  | shipped kernel driver and media library readings | no test seen in the handler's shift sequence; a direct sign test on the raw word was not looked for |
| 30 | `xtalk_write_full_fifo` | established |  | shipped kernel driver and media library readings |  |
| 29 | `guava_write_too_few` | established |  | shipped kernel driver and media library readings |  |
| 28 | `idma_resp_invalid_tag` | established |  | shipped kernel driver and media library readings |  |
| 27 | `idma_resp_size` | established |  | shipped kernel driver and media library readings |  |
| 26 | `odma_fifo_overflow` | established |  | shipped kernel driver and media library readings |  |
| 25 | `cmd_fifo_overflow` | established |  | shipped kernel driver and media library readings |  |
| 24 | `gfx_dword_credit_underflow` | inferred |  | shipped kernel driver and media library readings | never tested by the shipped handler; the assignment comes from the sequence of messages |
| 23 | `gfx_dword_credit_overflow` | established |  | shipped kernel driver and media library readings |  |
| 22 | `gfx_cacheline_credit_underflow` | established |  | shipped kernel driver and media library readings | the handler also prints the double-word underflow message when this bit is set |
| 21 | `gfx_cacheline_credit_overflow` | established |  | shipped kernel driver and media library readings |  |
| 20 | `xtalk_resp_credit_underflow` | established |  | shipped kernel driver and media library readings |  |
| 19 | `xtalk_resp_credit_overflow` | established |  | shipped kernel driver and media library readings |  |
| 18 | `xtalk_req_credit_underflow` | established |  | shipped kernel driver and media library readings |  |
| 17 | `xtalk_req_credit_overflow` | established |  | shipped kernel driver and media library readings |  |
| 16 | `guava_bus_parity` | established |  | shipped kernel driver and media library readings |  |
| 15 | `guava_bus_data_parity` | established |  | shipped kernel driver and media library readings |  |
| 14 | `guava_bus_cmd_parity` | established |  | shipped kernel driver and media library readings |  |
| 13 | `mapram_invalid` | established |  | shipped kernel driver and media library readings | the handler prints the address read from the map-RAM error address register |
| 12 | `mapram_parity` | established |  | shipped kernel driver and media library readings | the handler prints the address read from the map-RAM error address register |
| 11 | `gfx_fifo_overflow` | established |  | shipped kernel driver and media library readings |  |
| 10 | `xtalk_request` | established |  | shipped kernel driver and media library readings |  |
| 9 | `xtalk_response` | established |  | shipped kernel driver and media library readings |  |
| 8 | `xtalk_read_req_timeout` | established |  | shipped kernel driver and media library readings |  |
| 7 | `xtalk_bad_command` | established |  | shipped kernel driver and media library readings |  |
| 6 | `xtalk_address` | established |  | shipped kernel driver and media library readings |  |
| 5 | `guava_bad_interrupt` | established |  | shipped kernel driver and media library readings |  |
| 4 | `guava_bad_command` | established |  | shipped kernel driver and media library readings |  |
| 3 | `guava_valid_when_idle` | established |  | shipped kernel driver and media library readings |  |
| 2 | `guava_pio_cmd_resp_overflow` | established |  | shipped kernel driver and media library readings |  |
| 1 | `guava_pio_data_resp_overflow` | established |  | shipped kernel driver and media library readings |  |
| 0 | `guava_overlap` | established |  | shipped kernel driver and media library readings |  |

### Register `xg_water_mark`

High/low water mark (the diagnostic's name). The init routine keeps the two 6-bit fields from the current value, forces bits 15:0 to a constant and bits 31:28 to 0. The diagnostic stores bits 27:0 as plain storage. What high and low mean (presumably graphics FIFO thresholds) is inferred. This is the XG register at window offset 0x74, not the pipe 0 per-pipe word whose window offset is 0x800074.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `forced_zero` | established |  | shipped kernel driver and media library readings |  |
| 27:22 | `mark_b` | inferred |  | shipped kernel driver and media library readings |  |
| 21:16 | `mark_a` | inferred |  | shipped kernel driver and media library readings |  |
| 15:0 | `fixed_low` | established |  | shipped kernel driver and media library readings | forced to a constant by the init routine |

### Register `xg_mapram_err_addr`

Offending map-RAM entry address, read after a map-RAM parity or invalid error and printed as five hex digits. Read-only is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `entry_addr` | established |  | shipped kernel driver and media library readings |  |

### Register `xg_nic`

Board identity one-wire register, read through the shared one-wire accessor. The offset and accessor are established; the bit protocol is not in the driver object (unknown). The diagnostic stores bits 15:2 as plain storage; bits 1:0 are inferred to be the one-wire pulse and sample bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:2 | `storage` | established |  | shipped diagnostic tables |  |
| 1:0 | `onewire` | inferred |  | shipped kernel driver and media library readings |  |

### Register `fpga_prog`

GIF FPGA programming and status register. Read layout (this register): DONE and INIT for each FPGA in adjacent bit pairs. The message calls the GIF INIT bit INIT_L, active low, so it reads 1 when the pin is not asserted. The pairs run in the order GIF, packer, unpacker, input colour converter, output colour converter, VIF, HDOC, CLINK, which is not the order of the library's FPGA numbers. Names are inferred. The write layout is the word FPGA_PROG_WRITE.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `clink_init` | established |  | shipped kernel driver and media library readings |  |
| 14 | `clink_done` | established |  | shipped kernel driver and media library readings |  |
| 13 | `hdoc_init` | established |  | shipped kernel driver and media library readings |  |
| 12 | `hdoc_done` | established |  | shipped kernel driver and media library readings |  |
| 11 | `vif_init` | established |  | shipped kernel driver and media library readings |  |
| 10 | `vif_done` | established |  | shipped kernel driver and media library readings |  |
| 9 | `oxcc_init` | established |  | shipped kernel driver and media library readings |  |
| 8 | `oxcc_done` | established |  | shipped kernel driver and media library readings |  |
| 7 | `ixcc_init` | established |  | shipped kernel driver and media library readings |  |
| 6 | `ixcc_done` | established |  | shipped kernel driver and media library readings |  |
| 5 | `unpacker_init` | established |  | shipped kernel driver and media library readings |  |
| 4 | `unpacker_done` | established |  | shipped kernel driver and media library readings |  |
| 3 | `packer_init` | established |  | shipped kernel driver and media library readings |  |
| 2 | `packer_done` | established |  | shipped kernel driver and media library readings |  |
| 1 | `gif_init` | established |  | shipped kernel driver and media library readings |  |
| 0 | `gif_done` | established |  | shipped kernel driver and media library readings |  |

### Register `gif_reset`

GIF reset/enable word (register number 0x00). The init routine stores 0 when asked to reinitialise; the FPGA load path polls for a value of 0x80. The meaning of the bits is unknown.

### Register `gif_prog_control`

Per-FPGA programming control (register number 0x08), for the seven FPGAs behind the GIF. The select word is one-hot and bit 7 is a strobe level (idle high, pulsed low around each download); the code shows only the values and the pulse shape, so the names are inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `prog_strobe` | inferred |  | shipped kernel driver and media library readings |  |
| 6:0 | `fpga_select` | inferred |  | shipped kernel driver and media library readings |  |

### Register `pipe_dma_control`

Per-pipe DMA control word, indexed by pipe (pipe 0 at register number 0x10, pipe 1 at 0x38). The driver keeps a shadow and rewrites the whole word. Bits 3:0 are per-slot valid latches and bit 4 is abort; both are ORed into the written value and never kept in the shadow (established from the driver's own assertion). Bit 16 is the pipe interrupt enable (inferred from trace names). Bits 12, 10 and 9 are set and cleared by the raster configuration; their roles are inferred. The valid bits are inferred to be write-one-to-set latches. The initial shadow is 0xea040 for pipe 0 and 0xa040 for pipe 1. The diagnostic stores bits 14:5 (and 20:17 on pipe 0). The diagnostic calls pipe 0 the IDMA engine and pipe 1 the ODMA engine; the contract pages assign pipe 0 to video out (HDOC side) and pipe 1 to video in (VIF side), which is inferred.

Array of 2 registers, stride 40.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `int_enable` | inferred |  | shipped kernel driver and media library readings |  |
| 12 | `cfg_bit12` | inferred |  | shipped kernel driver and media library readings |  |
| 10 | `cfg_bit10` | inferred |  | shipped kernel driver and media library readings |  |
| 9 | `cfg_bit9` | inferred |  | shipped kernel driver and media library readings |  |
| 4 | `abort` | established |  | shipped kernel driver and media library readings |  |
| 3:0 | `slot_valid` | established |  | shipped kernel driver and media library readings |  |

### Register `pipe_start_addr1`

Per-pipe raster start address 1 (register numbers 0x18 and 0x40). The value must be below 16 MiB (the driver rejects larger ones). The diagnostic does not store the low 3 bits, so 8-byte alignment is inferred.

Array of 2 registers, stride 40.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:0 | `start_addr` | established |  | shipped kernel driver and media library readings |  |

### Register `pipe_start_addr2`

Per-pipe raster start address 2 (register numbers 0x20 and 0x48), same range test as start address 1. Alignment is inferred.

Array of 2 registers, stride 40.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:0 | `start_addr` | established |  | shipped kernel driver and media library readings |  |

### Register `pipe_vid_control`

Per-pipe video control (register numbers 0x28 and 0x50; the diagnostic's IDMA_OV and ODMA_IV). Formula and width are established, exactly the 26 bits the diagnostic stores; what the two counts and flags mean in the video path is unknown. Bits 11:0 come from a 16-bit field of the pipe record, bits 23:12 from a 12-bit argument of the raster configuration, bit 24 is set when one 16-bit pipe field is zero and bit 25 when another is nonzero.

Array of 2 registers, stride 40.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25 | `flag_nonzero` | established |  | shipped kernel driver and media library readings |  |
| 24 | `flag_zero` | established |  | shipped kernel driver and media library readings |  |
| 23:12 | `count_hi` | established |  | shipped kernel driver and media library readings |  |
| 11:0 | `count_lo` | established |  | shipped kernel driver and media library readings |  |

### Register `pipe_vid_control2`

Per-pipe video control 2 (register numbers 0x30 and 0x58): the low 12 bits of an argument. Meaning unknown.

Array of 2 registers, stride 40.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:0 | `value` | established |  | shipped kernel driver and media library readings |  |

### Register `pipe1_ring_ptr_reset`

Pipe 1 per-pipe word (register number 0x60), stored 0 when the pipe's status buffer is set up and by the clink-timeout path. The stores and the pipe assignment (pipe 1 owns this offset, pipe 0 owns 0x800074) are established; that it resets the board's status-ring write index is inferred. The host never reads it.

### Register `pipe1_reset_word`

Pipe 1 per-pipe word (register number 0x68), stored 0 at DMA start. Meaning unknown.

### Register `pipe0_ring_ptr_reset`

Pipe 0 per-pipe word (register number 0x70), stored 0 when the pipe's status buffer is set up and by the clink-timeout path. The stores and the pipe assignment (pipe 0 owns this offset, pipe 1 owns 0x800064) are established; that it resets the board's status-ring write index is inferred. The host never reads it. Not to be confused with the XG water-mark register at window offset 0x74.

### Register `pipe0_reset_word`

Pipe 0 per-pipe word (register number 0x78), stored 0 at DMA start. Meaning unknown.

### Register `gif_ident`

GIF identification (register number 0x80). Read once, by the GIF initialisation routine, which runs only from the board-reset ioctl when its argument has bit 1 clear (the media library issues it after all eight FPGAs are loaded), not at attach; the routine first requires the board-alive flag and the GIF DONE bit in the programming register. The upper 24 bits must be the ASCII text GIF; the low byte is the GIF version, which the driver prints at debug level 3 or above. Any other value fails that ioctl with the message that the GIF version is invalid.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:8 | `magic` | established |  | shipped kernel driver and media library readings |  |
| 7:0 | `version` | established |  | shipped kernel driver and media library readings |  |

### Register `ust_msc_counter`

Register number 0x88, stored 0 by the UST initialisation just before the host UST is sampled. The store is established; that it is the board's own UST/MSC counter is inferred from the pattern and the driver's message.

### Register `pack_r0800`

Packer register number 0x800. The library's per-pipe init stores a constant (see PACK_INIT_R0800). Roles unknown.

### Register `pack_r0808`

Packer register number 0x808. Init constant PACK_INIT_R0808. Roles unknown.

### Register `pack_r0810`

Packer register number 0x810. Init constant PACK_INIT_R0810. Roles unknown.

### Register `pack_misc_sel`

Packer miscellaneous select (register number 0x820, the diagnostic's PACK_MISC_SEL). Name and storage mask (bits 2 and 0) are established; the library stores 1 during init. Role unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `storage_bit2` | established |  | shipped diagnostic tables |  |
| 0 | `storage_bit0` | established |  | shipped diagnostic tables |  |

### Register `pack_r0840`

Packer register number 0x840. Init value is 0x1000 for pipe 1 (PACK_INIT_R0840). Roles unknown.

### Register `pack_r0848`

Packer register number 0x848. Init constant PACK_INIT_R0848. Roles unknown.

### Register `pack_r0850`

Packer register number 0x850. Init constant PACK_INIT_R0850. Roles unknown.

### Register `unpack_r1000`

Unpacker register number 0x1000. Init constant UNPACK_INIT_R1000. Roles unknown.

### Register `unpack_r1008`

Unpacker register number 0x1008. Init constant UNPACK_INIT_R1008. Roles unknown.

### Register `unpack_version_sel`

Unpacker VERSION_SEL (register number 0x1010). Name only; the diagnostic's storage mask is 0, which means not tested rather than read-only. Role unknown.

### Register `unpack_misc_sel`

Unpacker MISC_SEL (register number 0x1018). The library stores 0x0fffe0f9 with a flag shifted into bit 28 (UNPACK_INIT_MISC_BASE); the diagnostic's storage mask is bits 11:2 and 0. Bits of the library constant outside that mask are either not storage or not tested. Roles unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 28 | `flag28` | inferred |  | shipped kernel driver and media library readings | the library ORs the second output of its timing mapper here; inferred to mean standard-definition timing |
| 11:2 | `diag_storage_hi` | established |  | shipped diagnostic tables |  |
| 0 | `diag_storage_lo` | established |  | shipped diagnostic tables |  |

### Register `unpack_idma_data_sel`

Unpacker IDMA_DATA0_SEL and IDMA_DATA1_SEL (register numbers 0x1020 and 0x1028). Names only; diagnostic mask 0. Roles unknown.

Array of 2 registers, stride 8.

### Register `unpack_ovfifo_test_pattern_sel`

Unpacker OVFIFO_TEST_PATTERN0_SEL and OVFIFO_TEST_PATTERN1_SEL (register numbers 0x1030 and 0x1038). Names only; diagnostic mask 0. Roles unknown.

Array of 2 registers, stride 8.

### Register `unpack_r1040`

Unpacker register number 0x1040. Init value is 0x1200 for pipe 0 (UNPACK_INIT_R1040). Roles unknown.

### Register `unpack_r1048`

Unpacker register number 0x1048. Init constant UNPACK_INIT_R1048. Roles unknown.

### Register `vif_control`

VIF control (register number 0x1800, the diagnostic's CONTROL_SEL). Formula and width (14 bits) are established, matching the diagnostic's storage mask; the meaning of any bit is unknown. Bit 0 is 0 on the path the library reads, bits 5:4 are one of two bits chosen by a standard-definition flag, bit 6 is that flag, bit 7 is 0 in the formula (the debug-build library pulses it high then low at the start of an input transfer, which is inferred to clear a sticky error flag in register 0x1810), bits 10:8 are always 7, bit 11 comes from a format-table word and bit 12 is a nonzero test.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `nonzero_test` | established |  | shipped kernel driver and media library readings |  |
| 11 | `row_word1` | established |  | shipped kernel driver and media library readings |  |
| 10:8 | `const_7` | established |  | shipped kernel driver and media library readings |  |
| 7 | `err_clear` | inferred |  | shipped kernel driver and media library readings |  |
| 6 | `sd_flag` | established |  | shipped kernel driver and media library readings |  |
| 5:4 | `mode_sel` | established |  | shipped kernel driver and media library readings |  |
| 0 | `bit0` | established |  | shipped kernel driver and media library readings |  |

### Register `vif_enable`

VIF enable (register number 0x1808, the diagnostic's ENABLE_SEL); the kernel stores the pipe's second shadow word here and abort clears bit 0. The store is established; that bit 0 is the enable is inferred. This is the in-pipe (pipe 1) video enable; the pairing is inferred from trace names.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `bit1` | unknown |  | shipped kernel driver and media library readings |  |
| 0 | `enable` | inferred |  | shipped kernel driver and media library readings |  |

### Register `vif_scratch`

Register number 0x1810. The diagnostic writes it between every write and read-back of the other VIF registers, a bus-hold or clearing write. The release library never touches it; the debug build of the library reads it at the start of an input transfer and tests bit 5, pulsing bit 7 of the VIF control (register number 0x1800) high then low when it is set, and reads it again 27 ms later. That bit 5 is a sticky input-error flag cleared by that pulse is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `err_flag` | inferred |  | shipped diagnostic tables |  |

### Register `vif_dmux`

VIF DMUX register (register number 0x1828, the diagnostic's DMUX_REG_SEL). Bits 2:0 are a small selector (0 on the path read), bits 4:3 a two-bit mode (2 or 3, from the format class), bit 5 is set when a path field equals 10 and bit 7 is set except in one special path case. Formula established; meaning unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `bit7` | established |  | shipped kernel driver and media library readings |  |
| 5 | `path_is_10` | established |  | shipped kernel driver and media library readings |  |
| 4:3 | `mode` | established |  | shipped kernel driver and media library readings |  |
| 2:0 | `selector` | established |  | shipped kernel driver and media library readings |  |

### Register `vif_f0_actvid`

VIF field 0 active video (register number 0x1880): two 11-bit line numbers computed from the format row's line count and the path's start offsets. What each line is, is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:11 | `line1` | established |  | shipped kernel driver and media library readings |  |
| 10:0 | `line0` | established |  | shipped kernel driver and media library readings |  |

### Register `vif_f1_actvid`

VIF field 1 active video (register number 0x1888): same layout as field 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:11 | `line1` | established |  | shipped kernel driver and media library readings |  |
| 10:0 | `line0` | established |  | shipped kernel driver and media library readings |  |

### Register `vif_lines_per_frame`

VIF lines per frame (register number 0x1890): the format row's total line count minus 1 (1124 for the 1125-line HD rows).

### Register `hdoc_status`

HDOC status (register number 0x2000). The library sets bit 24 as a hold-off before writing the other HDOC registers and clears it after; the final value is built from pipe flags and ORs bit 17 last, except that on a board whose NIC part number is 1653 with revision 3 or later bit 17 is cleared instead (the inferred reading of which NIC fields hold part and revision comes from the GET_NIC ioctl result). The constant part is 0xc8008, or 0x2c8008 by a path flag. Formula established; field meanings unknown. 26 bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24 | `hold_off` | established |  | shipped kernel driver and media library readings |  |
| 17 | `flag17` | established |  | shipped kernel driver and media library readings | set last; cleared instead on the one board-revision case above |
| 12 | `flag12` | established |  | shipped kernel driver and media library readings |  |
| 11 | `flag11` | established |  | shipped kernel driver and media library readings |  |
| 10 | `flag10` | established |  | shipped kernel driver and media library readings |  |
| 9:7 | `sel_9_7` | established |  | shipped kernel driver and media library readings |  |
| 6:5 | `sel_6_5` | established |  | shipped kernel driver and media library readings |  |
| 1:0 | `sel_1_0` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_enable`

HDOC enable (register number 0x2008, the diagnostic's ENABLE_SEL); the kernel stores the pipe's second shadow here and abort clears bit 0. The out-pipe (pipe 0) video enable; the pairing is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | inferred |  | shipped kernel driver and media library readings |  |

### Register `hdoc_format`

HDOC format (register number 0x2010): total lines minus 1 and samples per line minus 1, from format-row words (1125 lines and 2200 samples for 1080i at 59.94).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:12 | `lines_minus_1` | established |  | shipped kernel driver and media library readings |  |
| 11:0 | `samples_minus_1` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_xcc_rden`

HDOC xcc_rden (register number 0x2018): active width plus 41 in the low 12 bits, with constant bits 17, 15 and 12 (0x29000). Formula established; meaning unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:0 | `width_plus_41` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_trs_hblank`

HDOC trs_hblank (register number 0x2020): two 12-bit fields; the high one is active width plus 4 (standard-definition timing) or 8, the low one is 2 or 4 by the same flag. Formula established; meaning unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:12 | `hblank_end` | established |  | shipped kernel driver and media library readings |  |
| 11:0 | `mode` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_line_regs`

Five HDOC registers with one layout, in order: actvid_fld0, trs_vblank_fld0, actvid_fld1, trs_vblank_fld1, field (register numbers 0x2028 to 0x2048). Two 11-bit line numbers computed from the format row and the path. The last register is forced to 0 when the first and second operands are equal. Formula established; meaning unknown. 22 bits each.

Array of 5 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:11 | `line1` | established |  | shipped kernel driver and media library readings |  |
| 10:0 | `line0` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_xcc_rden2`

HDOC xcc_rden2 (register number 0x2050): two 12-bit fields. Normally the first is active width plus 41 and the second is 41; when the path's geometry equals the full raster both are samples per line minus 41.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:12 | `blank_field` | established |  | shipped kernel driver and media library readings |  |
| 11:0 | `width_field` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_vitc_sel`

HDOC VITC_SEL (register number 0x2058). Name and 23-bit mask only; not written by the library.

### Register `hdoc_resync`

HDOC resync (register number 0x2060). The library reads it at init and hands the two fields to the kernel as the resync value, and writes the pair back from the resync routine.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:12 | `line` | established |  | shipped kernel driver and media library readings |  |
| 11:0 | `sample` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_resync_wndw`

HDOC resync window (register number 0x2068): the resync position moved by 7 samples with carry into the line count and a wrap at the line total. Window semantics are inferred from the name.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:12 | `line` | established |  | shipped kernel driver and media library readings |  |
| 11:0 | `sample` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_data_rden`

HDOC data_rden (register number 0x2070): active width plus 1 or 2 in the low 12 bits and 0x1000 or 0x2000 in bits 13:12, chosen by the standard-definition flag.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:12 | `mode` | established |  | shipped kernel driver and media library readings |  |
| 11:0 | `end` | established |  | shipped kernel driver and media library readings |  |

### Register `hdoc_fifo_wen_sel`

HDOC FIFOA_WEN_SEL and FIFOB_WEN_SEL (register numbers 0x2078 and 0x2080). Names and 24-bit masks only; not written by the library.

Array of 2 registers, stride 8.

### Register `hdoc_diag_regs`

Eight diagnostic-only registers, register numbers 0x20b0 to 0x20e8. The diagnostic names, in order, LFIFO_TEST_PATTEN, OXCC_DATA_HI, OXCC_DATA_LO, LFIFO_DATA, VIF_LB_TEST_PATTERN_LO, VIF_LB_TEST_PATTERN_HI, DEFAULT_Y (0x20e0) and DEFAULT_C (0x20e8). Only the last two numbers are tied to names; the assignment of the others to slots follows the listing order and is inferred. Roles unknown. Diagnostic mask 0.

Array of 8 registers, stride 8.

### Register `clink_tx_message`

CLINK transmit message: twelve halfword registers (register numbers 0x3800 to 0x3858) that the send ioctl fills from the 24-byte VBOB message, byte 2k in the high half and byte 2k+1 in the low half, before ringing the doorbell. Stores established; that it is a transmit buffer is inferred from the next store.

Array of 12 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `halfword` | established |  | shipped kernel driver and media library readings |  |

### Register `clink_pgen_lo`

CLINK pattern-generator divider, low (register number 0x3860, the diagnostic's PGEN_LO_SEL). The library writes CLINK_PGEN_LO_INIT when configuring the on-board 50 MHz clock, but only when the environment variable _XTDIGVID_NO_VBOB_SUPPORT is set (the diagnostic build of the initialisation path); in normal operation it is never written. Role inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `divider_lo` | inferred |  | shipped kernel driver and media library readings |  |

### Register `clink_pgen_hi`

CLINK pattern-generator divider, high (register number 0x3868, PGEN_HI_SEL). The library writes CLINK_PGEN_HI_INIT, under the same environment-variable condition as the low register. Role inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `divider_hi` | inferred |  | shipped kernel driver and media library readings |  |

### Register `clink_ksync_sel`

CLINK KSYNC_SEL (register number 0x3870). Name and 9-bit mask only; not written by the library.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8:0 | `storage` | established |  | shipped diagnostic tables |  |

### Register `clink_rx_message`

CLINK receive message: twelve halfword registers (register numbers 0x3880 to 0x38d8) the status-ring service routine reads when a message-received flag is set, keeping bits 15:0 of each as a high and a low byte.

Array of 12 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `halfword` | established |  | shipped kernel driver and media library readings |  |

### Register `clink_uart_reset`

CLINK UART reset (register number 0x38e0, UART_RESET_SEL): the library writes 1 then 0 at init and when an input path opens while the output pipe is idle. Name from the diagnostic, accesses from the library.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `reset` | established |  | shipped kernel driver and media library readings |  |

### Register `clink_tx_doorbell`

CLINK transmit doorbell (register number 0x38e8): the send ioctl stores 1 after filling the transmit message and arms a 250-tick timeout; the board answers with the transmit-done status flag. The lock, the outstanding-ack halfword and the wait variable are board-wide (one send at a time for both pipes), so the flag may come on either pipe's ring.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `ring` | established |  | shipped kernel driver and media library readings |  |

### Register `clink_rx_release`

CLINK receive release (register number 0x38f0): the service routine stores 1 after copying a received frame; the event post routine stores a register value to the same word in two places whose value was not traced (unknown).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `release` | established |  | shipped kernel driver and media library readings |  |

### Register `ixcc_diag_control0`

Diagnostic layout, input block CONTROL0 (register number 0x2800), 9 storage bits. The layout goes with the second input image, which only the diagnostic loads; which layout belongs to which image is read from who loads it, not from the bitstreams (inferred).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8:0 | `storage` | established |  | shipped diagnostic tables |  |

### Register `ixcc_diag_control1`

Diagnostic layout, input block CONTROL1 (register number 0x2808), 8 storage bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `storage` | established |  | shipped diagnostic tables |  |

### Register `ixcc_diag_lut_control`

Diagnostic layout, input block LUT_CONTROL (register number 0x2810), 5 storage bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `storage` | established |  | shipped diagnostic tables |  |

### Register `ixcc_diag_lut_data`

Diagnostic layout, input block LUT_DATA (register number 0x2818). Diagnostic mask 0: not tested rather than read-only.

### Register `oxcc_diag_control0`

Diagnostic layout, output block control (register number 0x3000), 9 storage bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8:0 | `storage` | established |  | shipped diagnostic tables |  |

### Register `oxcc_diag_control1`

Diagnostic layout, output block register number 0x3008, 10 storage bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9:0 | `storage` | established |  | shipped diagnostic tables |  |

### Register `oxcc_diag_lut_control`

Diagnostic layout, output block register number 0x3010, 5 storage bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `storage` | established |  | shipped diagnostic tables |  |

### Register `oxcc_diag_lut_data`

Diagnostic layout, output block register number 0x3018. Diagnostic mask 0: not tested rather than read-only.

### Register `ixcc_prog_lut_control`

Input colour-converter LUT control (block base, register number 0x2800). Per component the library writes 8, then 2, 4 or 1 for component 0, 1 or 2, then 8192 data writes, then 0. The sequence is established; the meaning of the control values is unknown.

### Register `ixcc_prog_lut_data`

Input colour-converter LUT data (register number 0x2808). Each of the 8192 entries per component is one 32-bit store carrying no index; whether the entry index auto-increments is unknown.

### Register `ixcc_prog_offset`

Input colour-converter red, green, blue and alpha offsets (register numbers 0x2810, 0x2818, 0x2820, 0x2828): format-table row words 10 to 13, as unsplit 32-bit values.

Array of 4 registers, stride 8.

### Register `ixcc_prog_misc`

Input colour converter misc (register number 0x2830): bit 0 is set when the path's conversion mode is zero and bit 8 is the mode's bit 0 shifted up. Formula established; meaning unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `mode_bit0` | established |  | shipped kernel driver and media library readings |  |
| 0 | `mode_zero` | established |  | shipped kernel driver and media library readings |  |

### Register `ixcc_prog_alpha`

Input colour converter alpha pair (register numbers 0x2838 and 0x2840, one failure message): the first is 4 when the standard-definition flag is set, else the path mode; the second is 0 when the table row index equals a path field, else 3 or the path mode. Offsets established; meaning unknown.

Array of 2 registers, stride 8.

### Register `ixcc_prog_coeflo`

Input colour converter coefficient, low 16 bits (register number 0x2848). Written before the high bit and the index.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `value` | established |  | shipped kernel driver and media library readings |  |

### Register `ixcc_prog_coefhi`

Input colour converter coefficient, bit 16 (register number 0x2850).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `bit16` | established |  | shipped kernel driver and media library readings |  |

### Register `ixcc_prog_coefind`

Input colour converter coefficient index (register number 0x2858), 5 bits, written after the low and high parts. That it latches the coefficient is inferred from the order. Ten coefficients come from a per-format table: words 0 to 8 go to indices 16, 20, 24, 17, 21, 25, 18, 22, 26 (a transposed 3 by 3 matrix, inferred) and word 9 to index 28; then seven filter taps go to indices 0 to 6.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `index` | established |  | shipped kernel driver and media library readings |  |

### Register `oxcc_prog_lut_control`

Output colour-converter LUT control (block base, register number 0x3000); same sequence as the input block.

### Register `oxcc_prog_lut_data`

Output colour-converter LUT data (register number 0x3008); same behaviour as the input block.

### Register `oxcc_prog_offset_lo`

Output colour converter red, green and blue offsets, low 16 bits (register numbers 0x3010, 0x3020, 0x3030), from format-table row words 10 to 12. Each is followed by a register holding bit 16 of the same offset.

Array of 3 registers, stride 16.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `value` | established |  | shipped kernel driver and media library readings |  |

### Register `oxcc_prog_offset_bit16`

Output colour converter red, green and blue offsets, bit 16 (register numbers 0x3018, 0x3028, 0x3038).

Array of 3 registers, stride 16.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `bit16` | established |  | shipped kernel driver and media library readings |  |

### Register `oxcc_prog_around`

Output colour converter around (register number 0x3040): format-table row word 13.

### Register `oxcc_prog_pack8`

Output colour converter pack8 (register number 0x3048): 1 when the component size is 8 bits.

### Register `oxcc_prog_dec`

Output colour converter dec (register number 0x3050): 0, or 3 or the pipe mode, chosen by the path. Offset established; formula unknown.

### Register `oxcc_prog_coeflo`

Output colour converter coefficient, low 16 bits (register number 0x3058).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `value` | established |  | shipped kernel driver and media library readings |  |

### Register `oxcc_prog_coefhi`

Output colour converter coefficient, bit 16 (register number 0x3060).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `bit16` | established |  | shipped kernel driver and media library readings |  |

### Register `oxcc_prog_coefind`

Output colour converter coefficient index (register number 0x3068), 5 bits, written after the low and high parts.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `index` | established |  | shipped kernel driver and media library readings |  |

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `FPGA_INFO_KIND` | 32 | established | shipped kernel driver and media library readings |
| `FPGA_PROG_WRITE` | 32 | established | shipped kernel driver and media library readings |
| `MAPRAM_ENTRY` | 32 | established | shipped kernel driver and media library readings |
| `MAPRAM_ENTRY_INVALIDATED` | 32 | established | shipped kernel driver and media library readings |
| `RING_ENTRY_FLAGS` | 32 | established | shipped kernel driver and media library readings |
| `RING_ENTRY_W0` | 32 | established | shipped kernel driver and media library readings |
| `VBOB_MSG_HEADER` | 32 | established | shipped kernel driver and media library readings |

### Word `FPGA_INFO_KIND`

Word at +4 of a 28-byte FPGA info record (all fields are big-endian 32-bit words): the kind, which selects the start, byte and stop routines.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1:0 | `kind` | established | fpga_kind (others_handshaked=0, gif=1, others_blind=2) | shipped kernel driver and media library readings |  |

### Word `FPGA_PROG_WRITE`

Write layout of the GIF programming register: an 8-bit data byte, a clock in bit 8 and a strobe in bit 9 that is high in the idle and active-data states. Each image byte of the GIF load is stored eight times unshifted, once with the clock low and once high. Values and tests established; the names are inferred. The kernel's own byte-load case stores a byte ORed with the clock-low and clock-high patterns the same way.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9 | `strobe` | inferred |  | shipped kernel driver and media library readings |  |
| 8 | `clock` | inferred |  | shipped kernel driver and media library readings |  |
| 7:0 | `data` | established |  | shipped kernel driver and media library readings |  |

### Word `MAPRAM_ENTRY`

A valid map-RAM page-table entry, one 32-bit word per 16 KiB page of the board's own DMA address space, stored by the driver as one big-endian PIO store. Written value is the page number's low 26 bits shifted left by 2, ORed with the valid bit. Whether the hardware reads bits 1:0 or the top bits as attributes, and the byte order its logic applies to the store, are unknown: nothing reads an entry back.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29 | `valid` | established |  | shipped kernel driver and media library readings | 1 in every valid entry |
| 28 | `invalid` | established |  | shipped kernel driver and media library readings | 0 in valid entries |
| 27:2 | `ppn` | established |  | shipped kernel driver and media library readings | system DMA address bits 39:14, the low 26 bits of the page number the driver's DMA mapping returns (that those are address bits 39:14 is inferred) |

### Word `MAPRAM_ENTRY_INVALIDATED`

An invalidated map-RAM entry: bit 28 set and a run-length counter below it. The driver writes n consecutive entries, the i-th as the invalid bit with the value n minus 1 minus i, so a single invalidated page is exactly the invalid bit alone. That bit 28 is what the hardware tests, and that the counter is only a run length, is inferred; the effect is the map-RAM-invalid error cause with the entry address in the map-RAM error address register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 28 | `invalid` | established |  | shipped kernel driver and media library readings |  |
| 27:0 | `run_left` | inferred |  | shipped kernel driver and media library readings |  |

### Word `RING_ENTRY_FLAGS`

Word 1 of a status-ring entry, the flag word. Bit numbers and names come from the driver's own 20-entry flag-name table (established); what each bit means in hardware terms is inferred from its name. Pipe 0 is the out pipe (video interrupt 1), pipe 1 the in pipe (video interrupt 0). The host clears VALID first, then handles the completion bits slot by slot in order, then the field-interrupt bit, the error bits while DMA is enabled, and the two link bits. Bits 20 to 31 have no table entry and no test.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19 | `clink_rcv_done` | established |  | shipped kernel driver and media library readings | VBOB message received; raises the receive event |
| 18 | `clink_xmit_done` | established |  | shipped kernel driver and media library readings | VBOB message acknowledge |
| 17:16 | `current_valid` | inferred |  | shipped kernel driver and media library readings | named by the driver's table but never tested by the service routine |
| 15:12 | `aborted` | established |  | shipped kernel driver and media library readings | DMA slot 0 to 3 aborted, one bit per slot |
| 11:8 | `done` | established |  | shipped kernel driver and media library readings | DMA slot 0 to 3 completion, one bit per slot |
| 7 | `f_intr` | established |  | shipped kernel driver and media library readings | field interrupt: counters, host timestamp, watchdog re-arm, timestamp event |
| 6 | `fif` | established |  | shipped kernel driver and media library readings | with the field interrupt bit: the device's view of field parity, compared against the driver's field counter |
| 5 | `in_change` | established |  | shipped kernel driver and media library readings | pipe 1 only: input state changed |
| 4 | `overflow` | established |  | shipped kernel driver and media library readings | pipe 0: a transfer error; pipe 1: a sequence-lost message with no event posted |
| 3 | `trs_error` | established |  | shipped kernel driver and media library readings | pipe 1 only: logged, not counted as an error |
| 2 | `input_off` | established |  | shipped kernel driver and media library readings | pipe 1 only: with in_change, the input signal went away |
| 1 | `f` | established |  | shipped kernel driver and media library readings | passed to the completion routine as a boolean |
| 0 | `valid` | established |  | shipped kernel driver and media library readings | entry present; cleared by the host before anything else |

### Word `RING_ENTRY_W0`

Word 0 of a 0x80-byte status-ring entry. The service routine treats bits 23:0 as a device media stream counter (MSC) and extends it to 64 bits, detecting a wrap by an unsigned compare with the previous value. The code only works if bits 31:24 read as zero (inferred; the driver does not check). The name MSC is inferred from the driver's own strings.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `reserved_zero` | inferred |  | shipped kernel driver and media library readings |  |
| 23:0 | `msc` | inferred |  | shipped kernel driver and media library readings |  |

### Word `VBOB_MSG_HEADER`

First four bytes of the 24-byte VBOB control message frame, in wire order from the high byte: count of bytes that follow, pipe, register id with bit 7 set for a write, then the first data byte. Byte layout established from every message builder in the library; names are inferred. The same 24 bytes are carried as twelve halfwords in the CLINK transmit and receive registers. Which pipe's ring carries a receive flag is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:24 | `count` | established |  | shipped kernel driver and media library readings | count of bytes that follow (last used index) |
| 23:16 | `pipe` | established | vbob_pipe (output=0, input=1) | shipped kernel driver and media library readings | equals the ioctl pipe word in every caller (a get passes it as the pipe word); the driver rejects a value above 1; that it selects a cable is inferred |
| 15 | `write` | established |  | shipped kernel driver and media library readings | set for a write message |
| 14:8 | `reg_id` | established |  | shipped kernel driver and media library readings |  |
| 7:0 | `data0` | inferred |  | shipped kernel driver and media library readings |  |

## Enums

### Enum `fpga_kind`

Programming routine set an FPGA info record selects.

| Label | Value | Grade | Source |
|---|---|---|---|
| `others_handshaked` | 0 | established | shipped kernel driver and media library readings |
| `gif` | 1 | established | shipped kernel driver and media library readings |
| `others_blind` | 2 | established | shipped kernel driver and media library readings |

### Enum `vbob_pipe`

Pipe byte of a VBOB message frame.

| Label | Value | Grade | Source |
|---|---|---|---|
| `output` | 0 | established | shipped kernel driver and media library readings |
| `input` | 1 | established | shipped kernel driver and media library readings |

### Enum `xg_mapram_type`

XG configuration word, map-RAM type code: the diagnostic indexes a three-string table with it.

| Label | Value | Grade | Source |
|---|---|---|---|
| `k32x36` | 0 | established | shipped kernel driver and media library readings |
| `k64x18` | 1 | established | shipped kernel driver and media library readings |
| `k128x9` | 2 | established | shipped kernel driver and media library readings |
| `invalid` | 3 | established | shipped kernel driver and media library readings |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CLINK_PGEN_HI_INIT` | 0x25 | established | shipped kernel driver and media library readings | value written to the pattern-generator high register (37); role inferred |
| `CLINK_PGEN_LO_INIT` | 0xc3f7 | established | shipped kernel driver and media library readings | value written to the pattern-generator low register when the library configures the on-board 50 MHz clock; role inferred |
| `FPGA_CLINK_DONE_MASK` | 0x4000 | established | shipped kernel driver and media library readings | DONE mask of the clink record, tested in the word read from the programming register |
| `FPGA_CLINK_IMAGE_SIZE` | 0x8a64 | established | shipped kernel driver and media library readings | image size in bytes of the clink record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_CLINK_INIT_MASK` | 0x8000 | established | shipped kernel driver and media library readings | INIT mask of the clink record, tested in the word read from the programming register |
| `FPGA_CLINK_KIND` | 0x0 | established | shipped kernel driver and media library readings | kind word of the clink record |
| `FPGA_CLINK_NUMBER` | 0x7 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the clink FPGA |
| `FPGA_CLINK_PORT_OFFSET` | 0x3800 | established | shipped kernel driver and media library readings | port offset of the clink record, the register number base of its block |
| `FPGA_CLINK_SELECT` | 0x40 | inferred | shipped kernel driver and media library readings | select word of the clink record (a one-hot FPGA choice is inferred) |
| `FPGA_DATA_PORT_ADD` | 0x80000 | established | shipped kernel driver and media library readings | added to a per-FPGA status port window offset to reach its data port (status ports are 0x800004 ORed with the port offset, data ports 0x880004 ORed with it); the two bases differ only in bit 19 of the window offset (0x80000), which is this value |
| `FPGA_GIF_DONE_MASK` | 0x1 | established | shipped kernel driver and media library readings | DONE mask of the gif record, tested in the word read from the programming register |
| `FPGA_GIF_IMAGE_SIZE` | 0x2bc21 | established | shipped kernel driver and media library readings | image size in bytes of the gif record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_GIF_INIT_MASK` | 0x2 | established | shipped kernel driver and media library readings | INIT mask of the gif record, tested in the word read from the programming register |
| `FPGA_GIF_KIND` | 0x1 | established | shipped kernel driver and media library readings | kind word of the gif record |
| `FPGA_GIF_NUMBER` | 0x0 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the gif FPGA |
| `FPGA_GIF_PORT_OFFSET` | 0x0 | established | shipped kernel driver and media library readings | port offset of the gif record, the register number base of its block |
| `FPGA_GIF_SELECT` | 0x0 | established | shipped kernel driver and media library readings | select word of the gif record (a one-hot FPGA choice is inferred) |
| `FPGA_HDOC_DONE_MASK` | 0x1000 | established | shipped kernel driver and media library readings | DONE mask of the hdoc record, tested in the word read from the programming register |
| `FPGA_HDOC_IMAGE_SIZE` | 0x19682 | established | shipped kernel driver and media library readings | image size in bytes of the hdoc record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_HDOC_INIT_MASK` | 0x2000 | established | shipped kernel driver and media library readings | INIT mask of the hdoc record, tested in the word read from the programming register |
| `FPGA_HDOC_KIND` | 0x0 | established | shipped kernel driver and media library readings | kind word of the hdoc record |
| `FPGA_HDOC_NUMBER` | 0x5 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the hdoc FPGA |
| `FPGA_HDOC_PORT_OFFSET` | 0x2000 | established | shipped kernel driver and media library readings | port offset of the hdoc record, the register number base of its block |
| `FPGA_HDOC_SELECT` | 0x8 | inferred | shipped kernel driver and media library readings | select word of the hdoc record (a one-hot FPGA choice is inferred) |
| `FPGA_INFO_OFF_DONE_MASK` | 0x14 | established | shipped kernel driver and media library readings | byte offset in an FPGA info record: DONE mask tested in the programming register read |
| `FPGA_INFO_OFF_IMAGE_SIZE` | 0x8 | established | shipped kernel driver and media library readings | byte offset in an FPGA info record: image size in bytes |
| `FPGA_INFO_OFF_INIT_MASK` | 0x18 | established | shipped kernel driver and media library readings | byte offset in an FPGA info record: INIT mask tested in the programming register read |
| `FPGA_INFO_OFF_KIND` | 0x4 | established | shipped kernel driver and media library readings | byte offset in an FPGA info record: kind word: 0, 1 or 2, selecting the start, byte and stop routines |
| `FPGA_INFO_OFF_NAME` | 0x0 | established | shipped kernel driver and media library readings | byte offset in an FPGA info record: pointer to the name string, used in the load failure messages |
| `FPGA_INFO_OFF_PORT_OFFSET` | 0x10 | established | shipped kernel driver and media library readings | byte offset in an FPGA info record: port offset ORed into the status and data port offsets |
| `FPGA_INFO_OFF_SELECT` | 0xc | established | shipped kernel driver and media library readings | byte offset in an FPGA info record: select word stored at the per-FPGA programming control register |
| `FPGA_INFO_RECORDS` | 0x8 | established | shipped kernel driver and media library readings | records in the info table, indexed by the FPGA number the load routine takes (0 to 7) |
| `FPGA_INFO_RECORD_SIZE` | 0x1c | established | shipped kernel driver and media library readings | size of one FPGA info record: seven big-endian 32-bit words (name pointer, kind, image size, select word, port offset, DONE mask, INIT mask) |
| `FPGA_IXCC_DONE_MASK` | 0x40 | established | shipped kernel driver and media library readings | DONE mask of the ixcc record, tested in the word read from the programming register |
| `FPGA_IXCC_IMAGE_SIZE` | 0x4db30 | established | shipped kernel driver and media library readings | image size in bytes of the ixcc record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_IXCC_INIT_MASK` | 0x80 | established | shipped kernel driver and media library readings | INIT mask of the ixcc record, tested in the word read from the programming register |
| `FPGA_IXCC_KIND` | 0x2 | established | shipped kernel driver and media library readings | kind word of the ixcc record |
| `FPGA_IXCC_NUMBER` | 0x4 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the ixcc FPGA |
| `FPGA_IXCC_PORT_OFFSET` | 0x2800 | established | shipped kernel driver and media library readings | port offset of the ixcc record, the register number base of its block |
| `FPGA_IXCC_SELECT` | 0x10 | inferred | shipped kernel driver and media library readings | select word of the ixcc record (a one-hot FPGA choice is inferred) |
| `FPGA_OXCC_DONE_MASK` | 0x100 | established | shipped kernel driver and media library readings | DONE mask of the oxcc record, tested in the word read from the programming register |
| `FPGA_OXCC_IMAGE_SIZE` | 0x4db30 | established | shipped kernel driver and media library readings | image size in bytes of the oxcc record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_OXCC_INIT_MASK` | 0x200 | established | shipped kernel driver and media library readings | INIT mask of the oxcc record, tested in the word read from the programming register |
| `FPGA_OXCC_KIND` | 0x2 | established | shipped kernel driver and media library readings | kind word of the oxcc record |
| `FPGA_OXCC_NUMBER` | 0x3 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the oxcc FPGA |
| `FPGA_OXCC_PORT_OFFSET` | 0x3000 | established | shipped kernel driver and media library readings | port offset of the oxcc record, the register number base of its block |
| `FPGA_OXCC_SELECT` | 0x20 | inferred | shipped kernel driver and media library readings | select word of the oxcc record (a one-hot FPGA choice is inferred) |
| `FPGA_PACK_DONE_MASK` | 0x4 | established | shipped kernel driver and media library readings | DONE mask of the pack record, tested in the word read from the programming register |
| `FPGA_PACK_IMAGE_SIZE` | 0x19682 | established | shipped kernel driver and media library readings | image size in bytes of the pack record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_PACK_INIT_MASK` | 0x8 | established | shipped kernel driver and media library readings | INIT mask of the pack record, tested in the word read from the programming register |
| `FPGA_PACK_KIND` | 0x0 | established | shipped kernel driver and media library readings | kind word of the pack record |
| `FPGA_PACK_NUMBER` | 0x1 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the pack FPGA |
| `FPGA_PACK_PORT_OFFSET` | 0x800 | established | shipped kernel driver and media library readings | port offset of the pack record, the register number base of its block |
| `FPGA_PACK_SELECT` | 0x1 | inferred | shipped kernel driver and media library readings | select word of the pack record (a one-hot FPGA choice is inferred) |
| `FPGA_UNPACK_DONE_MASK` | 0x10 | established | shipped kernel driver and media library readings | DONE mask of the unpack record, tested in the word read from the programming register |
| `FPGA_UNPACK_IMAGE_SIZE` | 0x19682 | established | shipped kernel driver and media library readings | image size in bytes of the unpack record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_UNPACK_INIT_MASK` | 0x20 | established | shipped kernel driver and media library readings | INIT mask of the unpack record, tested in the word read from the programming register |
| `FPGA_UNPACK_KIND` | 0x0 | established | shipped kernel driver and media library readings | kind word of the unpack record |
| `FPGA_UNPACK_NUMBER` | 0x2 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the unpack FPGA |
| `FPGA_UNPACK_PORT_OFFSET` | 0x1000 | established | shipped kernel driver and media library readings | port offset of the unpack record, the register number base of its block |
| `FPGA_UNPACK_SELECT` | 0x2 | inferred | shipped kernel driver and media library readings | select word of the unpack record (a one-hot FPGA choice is inferred) |
| `FPGA_VIF_DONE_MASK` | 0x400 | established | shipped kernel driver and media library readings | DONE mask of the vif record, tested in the word read from the programming register |
| `FPGA_VIF_IMAGE_SIZE` | 0x19682 | established | shipped kernel driver and media library readings | image size in bytes of the vif record; the exact byte total the image file must contain (kind 2 skips the length check) |
| `FPGA_VIF_INIT_MASK` | 0x800 | established | shipped kernel driver and media library readings | INIT mask of the vif record, tested in the word read from the programming register |
| `FPGA_VIF_KIND` | 0x0 | established | shipped kernel driver and media library readings | kind word of the vif record |
| `FPGA_VIF_NUMBER` | 0x6 | established | shipped kernel driver and media library readings | FPGA number (info table index) of the vif FPGA |
| `FPGA_VIF_PORT_OFFSET` | 0x1800 | established | shipped kernel driver and media library readings | port offset of the vif record, the register number base of its block |
| `FPGA_VIF_SELECT` | 0x4 | inferred | shipped kernel driver and media library readings | select word of the vif record (a one-hot FPGA choice is inferred) |
| `GIF_BLOCK_CLINK` | 0x3800 | established | shipped kernel driver and media library readings | register number base of the CLINK FPGA block |
| `GIF_BLOCK_CORE` | 0x0 | established | shipped kernel driver and media library readings | register number base of the GIF core and pipe registers |
| `GIF_BLOCK_HDOC` | 0x2000 | established | shipped kernel driver and media library readings | register number base of the HDOC FPGA block |
| `GIF_BLOCK_IXCC` | 0x2800 | established | shipped kernel driver and media library readings | register number base of the input colour-converter FPGA block |
| `GIF_BLOCK_OXCC` | 0x3000 | established | shipped kernel driver and media library readings | register number base of the output colour-converter FPGA block |
| `GIF_BLOCK_PACKER` | 0x800 | established | shipped kernel driver and media library readings | register number base of the packer FPGA block |
| `GIF_BLOCK_SIZE` | 0x800 | established | shipped diagnostic tables | each of the 8 per-FPGA blocks of the GIF register file spans 2 KiB of register numbers; every register found sits inside its block |
| `GIF_BLOCK_UNPACKER` | 0x1000 | established | shipped kernel driver and media library readings | register number base of the unpacker FPGA block |
| `GIF_BLOCK_VIF` | 0x1800 | established | shipped kernel driver and media library readings | register number base of the video input formatter FPGA block |
| `GIF_FILE_BASE` | 0x800000 | established | shipped kernel driver and media library readings | window offset of the GIF register file; a register number R sits at this base plus R plus 4 |
| `GIF_SLOT_STRIDE` | 0x8 | established | shipped kernel driver and media library readings | the GIF register file is 64-bit slots at an 8-byte stride; software reaches only the odd (low) 32-bit word, at slot base plus 4 |
| `MAPRAM_BASE` | 0x100000 | established | shipped kernel driver and media library readings | window offset of the map RAM; the entry for a board DMA address is at this base plus 4 times (address >> 14) |
| `MAPRAM_PAGE_SHIFT` | 0xe | established | shipped kernel driver and media library readings | a board DMA address is a 16 KiB page index into the flat map-RAM table |
| `MAPRAM_SLOT_PAGES_MAX` | 0x400 | established | shipped kernel driver and media library readings | largest page count of one DMA slot mapping; a larger transfer is rejected (16 MiB) |
| `PACK_INIT_R0800` | 0x1f0008 | established | shipped kernel driver and media library readings | value the library stores at init: packer register number 0x800, pipe 1 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `PACK_INIT_R0808` | 0x1f0008 | established | shipped kernel driver and media library readings | value the library stores at init: packer register number 0x808, pipe 1 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `PACK_INIT_R0810` | 0x1f0008 | established | shipped kernel driver and media library readings | value the library stores at init: packer register number 0x810, pipe 1 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `PACK_INIT_R0840` | 0x1000 | established | shipped kernel driver and media library readings | value the library stores at init: packer register number 0x840, pipe 1 init (the library's pipe 1 value). The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `PACK_INIT_R0848` | 0x1000 | established | shipped kernel driver and media library readings | value the library stores at init: packer register number 0x848, pipe 1 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `PACK_INIT_R0850` | 0xd00 | established | shipped kernel driver and media library readings | value the library stores at init: packer register number 0x850, pipe 1 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `PIPE_DMA_CONTROL_INIT_PIPE0` | 0xea040 | established | shipped kernel driver and media library readings | initial DMA control shadow of pipe 0 |
| `PIPE_DMA_CONTROL_INIT_PIPE1` | 0xa040 | established | shipped kernel driver and media library readings | initial DMA control shadow of pipe 1 |
| `RING_DMA_ADDR_PIPE0` | 0x8000000 | established | shipped kernel driver and media library readings | fixed board DMA address of pipe 0's status ring; no register carries it and the map RAM places it (that the board has the address built in is inferred) |
| `RING_DMA_ADDR_PIPE1` | 0x9000000 | established | shipped kernel driver and media library readings | fixed board DMA address of pipe 1's status ring |
| `RING_ENTRIES` | 0x10 | established | shipped kernel driver and media library readings | entries per pipe status ring (2048 bytes); the host index is masked with 0xf |
| `RING_ENTRY_BYTES` | 0x80 | established | shipped kernel driver and media library readings | size of one status-ring entry; only words 0 and 1 are read by shipped software, the remaining bytes are unknown |
| `UNPACK_INIT_MISC_BASE` | 0xfffe0f9 | established | shipped kernel driver and media library readings | value the library stores at init: unpacker MISC_SEL init, ORed with a flag shifted left by 28. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `UNPACK_INIT_R1000` | 0x160008 | established | shipped kernel driver and media library readings | value the library stores at init: unpacker register number 0x1000, pipe 0 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `UNPACK_INIT_R1008` | 0x32001f | established | shipped kernel driver and media library readings | value the library stores at init: unpacker register number 0x1008, pipe 0 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `UNPACK_INIT_R1040` | 0x1200 | established | shipped kernel driver and media library readings | value the library stores at init: unpacker register number 0x1040, pipe 0 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `UNPACK_INIT_R1048` | 0xd00 | established | shipped kernel driver and media library readings | value the library stores at init: unpacker register number 0x1048, pipe 0 init. The pairing of pipe 1 with the packer and pipe 0 with the unpacker is inferred from the pipes' directions; the bit roles are unknown |
| `VBOB_MSG_BYTES` | 0x18 | established | shipped kernel driver and media library readings | size of a VBOB control message frame; carried as twelve halfwords |
| `VBOB_TX_TIMEOUT_TICKS` | 0xfa | established | shipped kernel driver and media library readings | clock ticks the send ioctl waits for the transmit-done flag after the doorbell; the real time depends on the tick rate (inferred) |

## Test vectors

A vector is a value recorded from a source. An example only shows the layout.

| Target | Value | Kind | Decoded |
|---|---|---|---|
| `widget_control` | 0x4200 | vector | const_bit9=1, const_bit14=1, xg_error_int_enable=0 |
| `xg_water_mark` | 0x3f40 | vector | fixed_low=16192, mark_a=0, mark_b=0, forced_zero=0 |
| `pipe_dma_control` | 0xa040 | vector | slot_valid=0, abort=0, cfg_bit9=0, cfg_bit10=0, cfg_bit12=0, int_enable=0 |
| `pipe_dma_control` | 0xea040 | vector | slot_valid=0, abort=0, cfg_bit9=0, cfg_bit10=0, cfg_bit12=0, int_enable=0 |
| `gif_ident` | 0x47494600 | example | magic=4671814, version=0 |
| `FPGA_PROG_WRITE` | 0x100 | vector | data=0, clock=1, strobe=0 |
| `FPGA_PROG_WRITE` | 0x200 | vector | data=0, clock=0, strobe=1 |
| `FPGA_PROG_WRITE` | 0x300 | vector | data=0, clock=1, strobe=1 |
| `MAPRAM_ENTRY` | 0x20000004 | example | valid=1, invalid=0, ppn=1 |
| `MAPRAM_ENTRY_INVALIDATED` | 0x10000000 | vector | invalid=1, run_left=0 |
| `RING_ENTRY_FLAGS` | 0x40001 | example | valid=1, clink_xmit_done=1, clink_rcv_done=0 |
| `VBOB_MSG_HEADER` | 0x4012000 | example | count=4, pipe=1, write=0, reg_id=32 |
