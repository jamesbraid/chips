<!-- generated from devices/mbcs/registers.toml by defs-gen - do not edit, change the source -->

# RASC Core Services (MBCS): the register block a Core Services FPGA bitstream presents on the TIO FPGA port, as SGI's Linux driver defines it

Offsets, widths and field positions are the definitions of SGI's Linux FPGA Core Services driver header (v5.3). They describe the Core Services block that SGI's RASC bitstreams contain; other bitstreams on the same port need not have it. The header gives no reset value and no access direction: access is what the driver does (r read, w written, rw read-modify-write or an unused placeholder), reset is unknown throughout. Offsets are from the base of the FPGA port's 256 MiB small window.

Unit `mbcs`, macro prefix `MBCS`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `id` | 0x0 | r | 64 |  |  | unknown | established |  |
| `status` | 0x8 | r | 64 |  |  | unknown | established |  |
| `err_detail1` | 0x10 | rw | 64 |  |  | unknown | established |  |
| `err_detail2` | 0x18 | rw | 64 |  |  | unknown | established |  |
| `control` | 0x20 | rw | 64 |  |  | unknown | established |  |
| `req_timeout` | 0x28 | rw | 64 |  |  | unknown | established |  |
| `err_int_dest` | 0x38 | rw | 64 |  |  | unknown | established |  |
| `targ_flush` | 0x50 | rw | 64 |  |  | unknown | established |  |
| `err_status` | 0x60 | r | 64 |  |  | unknown | established |  |
| `clr_err_stat` | 0x68 | w | 64 |  |  | unknown | established |  |
| `err_int_en` | 0x70 | w | 64 |  |  | unknown | established |  |
| `rd_dma_sys_addr` | 0x100 | w | 64 |  |  | unknown | established |  |
| `rd_dma_loc_addr` | 0x108 | w | 64 |  |  | unknown | established |  |
| `rd_dma_ctrl` | 0x110 | w | 64 |  |  | unknown | established |  |
| `rd_dma_amo_dest` | 0x118 | w | 64 |  |  | unknown | established |  |
| `rd_dma_int_dest` | 0x120 | w | 64 |  |  | unknown | established |  |
| `rd_dma_aux_stat` | 0x130 | rw | 64 |  |  | unknown | established |  |
| `wr_dma_sys_addr` | 0x200 | w | 64 |  |  | unknown | established |  |
| `wr_dma_loc_addr` | 0x208 | w | 64 |  |  | unknown | established |  |
| `wr_dma_ctrl` | 0x210 | w | 64 |  |  | unknown | established |  |
| `wr_dma_amo_dest` | 0x218 | w | 64 |  |  | unknown | established |  |
| `wr_dma_int_dest` | 0x220 | w | 64 |  |  | unknown | established |  |
| `wr_dma_aux_stat` | 0x230 | rw | 64 |  |  | unknown | established |  |
| `alg_amo_dest` | 0x300 | w | 64 |  |  | unknown | established |  |
| `alg_int_dest` | 0x308 | w | 64 |  |  | unknown | established |  |
| `alg_offsets` | 0x310 | rw | 64 |  |  | unknown | established |  |
| `alg_step` | 0x318 | w | 64 |  |  | unknown | established |  |

### Register `id`

Identification word of the core. Its low bits are the same widget identification layout the TIO driver reads at offset 0 of the port's window: bit 0 is one, manufacturer in 11:1, part number in 27:12. The core adds an 8-bit bitstream revision in 35:28. The MBCS driver never reads this register; the layout is the header's.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:28 | `bitstream_rev` | established |  |  |  |
| 27:12 | `part_num` | established |  |  |  |
| 11:1 | `mfg_id` | established |  |  |  |
| 0 | `always_one` | established |  |  |  |

### Register `status`

Core status. The driver's one interrupt handler reads it and tests the read-DMA-done, write-DMA-done and algorithm-done bits; it reads nothing else.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `alg_half_speed_sel` | established |  |  |  |
| 59:52 | `pending_int_reqs` | established |  |  |  |
| 48 | `alg_done` | established |  |  |  |
| 47 | `alg_pipe_running` | established |  |  |  |
| 46 | `alg_waiting` | established |  |  |  |
| 45 | `wr_dma_done` | established |  |  |  |
| 44 | `wr_dma_in_progress` | established |  |  |  |
| 42 | `rd_dma_done` | established |  |  |  |
| 41 | `rd_dma_in_progress` | established |  |  |  |
| 39:32 | `cm_req_credits` | established |  |  |  |
| 31:24 | `ice_req_credits` | established |  |  |  |
| 23:16 | `ice_rsp_credits` | established |  |  |  |
| 15:8 | `pending_writes` | established |  |  |  |
| 7:0 | `pending_reads` | established |  |  |  |

### Register `err_detail1`

Captured detail of the first error (header name `cm_error_detail1`). The driver writes zero at attach and never reads it. Access rw is a placeholder.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  |  |
| 49 | `data_error_bit` | established |  |  |  |
| 48 | `head_error_bit` | established |  |  |  |
| 35 | `head_cw_error` | established |  |  |  |
| 34 | `pio_or_memory` | established |  |  |  |
| 33:32 | `read_type` | established |  |  |  |
| 31:24 | `gfx_cred` | established |  |  |  |
| 23:16 | `byte_enable` | established |  |  |  |
| 15:8 | `tnum` | established |  |  |  |
| 7:6 | `data_size` | established |  |  |  |
| 5:4 | `source_id` | established |  |  |  |
| 3:0 | `packet_type` | established |  |  |  |

### Register `err_detail2`

Captured address of the first error. The driver does not touch it. Access rw is a placeholder.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `address` | established |  |  |  |

### Register `control`

Core control. Every driver access is read, change a bit, write back. The go bits start an engine, the clr bits stop one and clear its status, `alg_done_clr` clears the algorithm-done status. Whether the go and clr bits read back as set is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 51 | `alg_done_clr` | established |  |  |  |
| 50 | `alg_sram2_locked` | established |  |  |  |
| 49 | `alg_sram1_locked` | established |  |  |  |
| 48 | `alg_sram0_locked` | established |  |  |  |
| 46 | `alg_done_int_en` | established |  |  |  |
| 45 | `alg_done_amo_en` | established |  |  |  |
| 44 | `alg_wait_step` | established |  |  |  |
| 41 | `alg_clr` | established |  |  |  |
| 40 | `wr_dma_clr` | established |  |  |  |
| 39 | `rd_dma_clr` | established |  |  |  |
| 38 | `alg_go` | established |  |  |  |
| 37 | `wr_dma_go` | established |  |  |  |
| 36 | `rd_dma_go` | established |  |  |  |
| 35 | `force_gap_war` | established |  |  |  |
| 34 | `prescalar_byp` | established |  |  |  |
| 33 | `rearm_stat_regs` | established |  |  |  |
| 27:20 | `credit_limit` | established |  |  |  |
| 12 | `address_mode` | established |  |  |  |
| 8:4 | `max_trans` | established |  |  |  |
| 1:0 | `cm_id` | established |  |  |  |

### Register `req_timeout`

Request time-out. The driver reads it, sets the 24-bit time-out field to all ones and writes it back.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:0 | `time_out` | established |  |  |  |

### Register `err_int_dest`

Destination of the error interrupt: a 56-bit address and an 8-bit vector (the same format as every interrupt destination register of the core). The driver never programs it. Access rw is a placeholder.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `int_vector` | established |  |  |  |
| 55:0 | `address` | established |  |  |  |

### Register `targ_flush`

Target flush (header name `MBCS_CM_TARG_FL`). The header gives it an offset and a reserved slot but no layout; the driver does not touch it. Access rw is a placeholder.

### Register `err_status`

Error status, one bit per condition. The driver reads it at attach and writes the value it read to `clr_err_stat`.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49 | `wr_dma_prog_err` | established |  |  |  |
| 48 | `rd_dma_prog_err` | established |  |  |  |
| 47 | `int_gen_tnum_tout` | established |  |  |  |
| 46 | `int_gen_rsp_err` | established |  |  |  |
| 45 | `ram2_perr` | established |  |  |  |
| 44 | `ram1_perr` | established |  |  |  |
| 43 | `ram0_perr` | established |  |  |  |
| 42 | `ram2_access_conflict` | established |  |  |  |
| 41 | `ram1_access_conflict` | established |  |  |  |
| 40 | `ram0_access_conflict` | established |  |  |  |
| 39 | `alg_data_underflow` | established |  |  |  |
| 38 | `alg_data_overflow` | established |  |  |  |
| 37 | `wr_dma_multi_tnum_tou` | established |  |  |  |
| 36 | `wr_dma_tnum_tout` | established |  |  |  |
| 35 | `wr_dma_err_rsp` | established |  |  |  |
| 34 | `rd_dma_multi_tnum_tou` | established |  |  |  |
| 33 | `rd_dma_tnum_tout` | established |  |  |  |
| 32 | `rd_dma_err_rsp` | established |  |  |  |
| 31 | `rx_bad_didn` | established |  |  |  |
| 30 | `cm2hcm_rsp_cred_of` | established |  |  |  |
| 29 | `cm2hcm_req_cred_of` | established |  |  |  |
| 28 | `data_flit_sb_err` | established |  |  |  |
| 27 | `missing_tail` | established |  |  |  |
| 26 | `early_tail` | established |  |  |  |
| 25 | `early_term` | established |  |  |  |
| 24 | `req_range_dsize_inv` | established |  |  |  |
| 23 | `pio_req_addr_inv` | established |  |  |  |
| 22 | `req_addr_align_inv` | established |  |  |  |
| 21 | `head_cmd_err_bit` | established |  |  |  |
| 20 | `head_inv_rd_type` | established |  |  |  |
| 19 | `missing_head` | established |  |  |  |
| 18 | `head_sb_err` | established |  |  |  |
| 17 | `rsp_pactype_inv` | established |  |  |  |
| 16 | `head_inv_data_size` | established |  |  |  |
| 7 | `request_timeout` | established |  |  |  |
| 6 | `buffer_overflow` | established |  |  |  |
| 5 | `bad_datavalid` | established |  |  |  |
| 4 | `bad_length` | established |  |  |  |
| 3 | `unexpected_rsp` | established |  |  |  |
| 2 | `unsupported_req` | established |  |  |  |
| 1 | `ecc_mbe` | established |  |  |  |
| 0 | `ecc_sbe` | established |  |  |  |

### Register `clr_err_stat`

Clear error status: bit n clears bit n of `err_status` (the driver writes back the value it read from `err_status`; the header's field names carry a clr_ prefix).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49 | `clr_wr_dma_prog_err` | established |  |  |  |
| 48 | `clr_rd_dma_prog_err` | established |  |  |  |
| 47 | `clr_int_gen_tnum_tout` | established |  |  |  |
| 46 | `clr_int_gen_rsp_err` | established |  |  |  |
| 45 | `clr_ram2_perr` | established |  |  |  |
| 44 | `clr_ram1_perr` | established |  |  |  |
| 43 | `clr_ram0_perr` | established |  |  |  |
| 42 | `clr_ram2_access_confl` | established |  |  |  |
| 41 | `clr_ram1_access_confl` | established |  |  |  |
| 40 | `clr_ram0_access_confl` | established |  |  |  |
| 39 | `clr_alg_data_underflo` | established |  |  |  |
| 38 | `clr_alg_data_overflow` | established |  |  |  |
| 37 | `clr_wr_dma_multi_tnum` | established |  |  |  |
| 36 | `clr_wr_dma_tnum_tout` | established |  |  |  |
| 35 | `clr_wr_dma_err_rsp` | established |  |  |  |
| 34 | `clr_rd_dma_multi_tnum` | established |  |  |  |
| 33 | `clr_rd_dma_tnum_tout` | established |  |  |  |
| 32 | `clr_rd_dma_err_rsp` | established |  |  |  |
| 31 | `clr_rx_bad_didn` | established |  |  |  |
| 30 | `clr_cm2hcm_rsp_cred_o` | established |  |  |  |
| 29 | `clr_cm2hcm_req_cred_o` | established |  |  |  |
| 28 | `clr_data_flit_sb_err` | established |  |  |  |
| 27 | `clr_missing_tail` | established |  |  |  |
| 26 | `clr_early_tail` | established |  |  |  |
| 25 | `clr_early_term` | established |  |  |  |
| 24 | `clr_req_range_dsize_i` | established |  |  |  |
| 23 | `clr_pio_req_addr_inv` | established |  |  |  |
| 22 | `clr_req_addr_align_in` | established |  |  |  |
| 21 | `clr_head_cmd_err_bit` | established |  |  |  |
| 20 | `clr_head_inv_rd_type` | established |  |  |  |
| 19 | `clr_missing_head` | established |  |  |  |
| 18 | `clr_head_sb_err` | established |  |  |  |
| 17 | `clr_rsp_pactype_inv` | established |  |  |  |
| 16 | `clr_head_inv_data_siz` | established |  |  |  |
| 7 | `clr_request_timeout` | established |  |  |  |
| 6 | `clr_buffer_overflow` | established |  |  |  |
| 5 | `clr_bad_datavalid` | established |  |  |  |
| 4 | `clr_bad_length` | established |  |  |  |
| 3 | `clr_unexpected_rsp` | established |  |  |  |
| 2 | `clr_unsupported_req` | established |  |  |  |
| 1 | `clr_ecc_mbe` | established |  |  |  |
| 0 | `clr_ecc_sbe` | established |  |  |  |

### Register `err_int_en`

Error interrupt enable, one bit per `err_status` condition. The driver writes 0x3ffffff7e00ff at attach: every defined condition enabled except bits 16 and 23.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49 | `int_en_wr_dma_prog_er` | established |  |  |  |
| 48 | `int_en_rd_dma_prog_er` | established |  |  |  |
| 47 | `int_en_int_gen_tnum_t` | established |  |  |  |
| 46 | `int_en_int_gen_rsp_er` | established |  |  |  |
| 45 | `int_en_ram2_perr` | established |  |  |  |
| 44 | `int_en_ram1_perr` | established |  |  |  |
| 43 | `int_en_ram0_perr` | established |  |  |  |
| 42 | `int_en_ram2_access_co` | established |  |  |  |
| 41 | `int_en_ram1_access_co` | established |  |  |  |
| 40 | `int_en_ram0_access_co` | established |  |  |  |
| 39 | `int_en_alg_data_under` | established |  |  |  |
| 38 | `int_en_alg_data_overf` | established |  |  |  |
| 37 | `int_en_wr_dma_multi_t` | established |  |  |  |
| 36 | `int_en_wr_dma_tnum_to` | established |  |  |  |
| 35 | `int_en_wr_dma_err_rsp` | established |  |  |  |
| 34 | `int_en_rd_dma_multi_t` | established |  |  |  |
| 33 | `int_en_rd_dma_tnum_to` | established |  |  |  |
| 32 | `int_en_rd_dma_err_rsp` | established |  |  |  |
| 31 | `int_en_rx_bad_didn` | established |  |  |  |
| 30 | `int_en_cm2hcm_rsp_cre` | established |  |  |  |
| 29 | `int_en_cm2hcm_req_cre` | established |  |  |  |
| 28 | `int_en_data_flit_sb_e` | established |  |  |  |
| 27 | `int_en_missing_tail` | established |  |  |  |
| 26 | `int_en_early_tail` | established |  |  |  |
| 25 | `int_en_early_term` | established |  |  |  |
| 24 | `int_en_req_range_dsiz` | established |  |  |  |
| 23 | `int_en_pio_req_addr_i` | established |  |  |  |
| 22 | `int_en_req_addr_align` | established |  |  |  |
| 21 | `int_en_head_cmd_err_b` | established |  |  |  |
| 20 | `int_en_head_inv_rd_ty` | established |  |  |  |
| 19 | `int_en_missing_head` | established |  |  |  |
| 18 | `int_en_head_sb_err` | established |  |  |  |
| 17 | `int_en_rsp_pactype_in` | established |  |  |  |
| 16 | `int_en_head_inv_data_` | established |  |  |  |
| 7 | `int_en_request_timeou` | established |  |  |  |
| 6 | `int_en_buffer_overflo` | established |  |  |  |
| 5 | `int_en_bad_datavalid` | established |  |  |  |
| 4 | `int_en_bad_length` | established |  |  |  |
| 3 | `int_en_unexpected_rsp` | established |  |  |  |
| 2 | `int_en_unsupported_re` | established |  |  |  |
| 1 | `int_en_ecc_mbe` | established |  |  |  |
| 0 | `int_en_ecc_sbe` | established |  |  |  |

### Register `rd_dma_sys_addr`

Read DMA (host memory to local RAM) system address: 56 bits of a TIO-view DMA address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `dma_sys_addr` | established |  |  |  |

### Register `rd_dma_loc_addr`

Read DMA local address: a 21-bit offset in a RAM and a 2-bit RAM select.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:21 | `dma_ram_sel` | established |  |  |  |
| 20:0 | `dma_ram_addr` | established |  |  |  |

### Register `rd_dma_ctrl`

Read DMA control: length in 128-byte units, completion AMO and interrupt enables, and a peer I/O select.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37 | `pio_mem_n` | established |  |  |  |
| 35 | `done_int_en` | established |  |  |  |
| 34 | `done_amo_en` | established |  |  |  |
| 15:0 | `dma_op_length` | established |  |  |  |

### Register `rd_dma_amo_dest`

Read DMA completion atomic-memory-operation destination: a 56-bit address and a 3-bit modifier type.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:56 | `dma_amo_mod_type` | established |  |  |  |
| 55:0 | `dma_amo_sys_addr` | established |  |  |  |

### Register `rd_dma_int_dest`

Read DMA completion interrupt destination.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `int_vector` | established |  |  |  |
| 55:0 | `address` | established |  |  |  |

### Register `rd_dma_aux_stat`

Read DMA auxiliary status. The driver does not touch it. Access rw is a placeholder.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:40 | `pending_reqs_left` | established |  |  |  |
| 22 | `lrsp_buff_empty` | established |  |  |  |
| 16:0 | `op_num_pacs_left` | established |  |  |  |

### Register `wr_dma_sys_addr`

Write DMA (local RAM to host memory) system address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:0 | `dma_sys_addr` | established |  |  |  |

### Register `wr_dma_loc_addr`

Write DMA local address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:21 | `dma_ram_sel` | established |  |  |  |
| 20:0 | `dma_ram_addr` | established |  |  |  |

### Register `wr_dma_ctrl`

Write DMA control.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37 | `pio_mem_n` | established |  |  |  |
| 35 | `done_int_en` | established |  |  |  |
| 34 | `done_amo_en` | established |  |  |  |
| 15:0 | `dma_op_length` | established |  |  |  |

### Register `wr_dma_amo_dest`

Write DMA completion atomic-memory-operation destination.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:56 | `dma_amo_mod_type` | established |  |  |  |
| 55:0 | `dma_amo_sys_addr` | established |  |  |  |

### Register `wr_dma_int_dest`

Write DMA completion interrupt destination.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `int_vector` | established |  |  |  |
| 55:0 | `address` | established |  |  |  |

### Register `wr_dma_aux_stat`

Write DMA auxiliary status. The driver does not touch it. Access rw is a placeholder.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45:40 | `pending_reqs_left` | established |  |  |  |
| 21 | `lreq_buff_empty` | established |  |  |  |
| 16:0 | `op_num_pacs_left` | established |  |  |  |

### Register `alg_amo_dest`

Algorithm-done atomic-memory-operation destination.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 58:56 | `dma_amo_mod_type` | established |  |  |  |
| 55:0 | `dma_amo_sys_addr` | established |  |  |  |

### Register `alg_int_dest`

Algorithm-done interrupt destination.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `int_vector` | established |  |  |  |
| 55:0 | `address` | established |  |  |  |

### Register `alg_offsets`

Offsets of the three RAMs as the algorithm sees them (header names `sram0_offset` and so on, seven bits each at 6:0, 14:8 and 22:16). The driver declares the layout and never writes it. Access rw is a placeholder.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:16 | `sram2_offset` | established |  |  |  |
| 14:8 | `sram1_offset` | established |  |  |  |
| 6:0 | `sram0_offset` | established |  |  |  |

### Register `alg_step`

Algorithm step count for debug stepping (16 bits). The driver writes the value it holds, zero unless something set it, before every algorithm start.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `alg_step_cnt` | established |  |  |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CACHELINE_SIZE` | 0x80 | established |  | Unit of the DMA length fields: the driver rounds a byte count up to 128-byte units. |
| `DEBUG_START` | 0x100000 | established |  | Start of the debug register region. By the driver's own comment the first debug register holds the algorithm number and revision; the algorithm sysfs file prints its high then low 32 bits. |
| `ERR_INT_EN_DRIVER` | 0x3ffffff7e00ff | established |  | Value the driver writes to err_int_en. Its comment says only bit 23 (the PIO request address invalid error) is turned off; the constant also leaves bit 16 clear. Bits 8 to 15 are not defined conditions. |
| `GSCR_START` | 0x0 | established |  | Start of the first region of the window, which holds the registers above. The driver maps one page of it to user space, uncached. The name is not expanded in the source. |
| `MFG_NUM` | 0x1 | established |  | Manufacturer number of both ids. |
| `PART_NUM` | 0xfff0 | established |  | Part number the Core Services driver binds to, with manufacturer 1. |
| `PART_NUM_ALG0` | 0xf001 | established |  | Second part number the driver binds to, with manufacturer 1. The header names it ALG0; what distinguishes it from the first is unknown. |
| `RAM0_START` | 0x200000 | established |  | Start of local RAM 0 in the window. |
| `RAM1_START` | 0x400000 | established |  | Start of local RAM 1 in the window. |
| `RAM2_START` | 0x600000 | established |  | Start of local RAM 2 in the window. |
| `REQ_TOUT_MASK` | 0xffffff | established |  | Value the driver writes to the time-out field (all 24 bits). |
| `SRAM_SIZE` | 0x100000 | established |  | Size the driver gives the character device for seeking (1 MiB). It is the driver's limit, not a stated RAM size. |
