<!-- generated from devices/pic/registers-extra.toml by defs-gen - do not edit, change the source -->

# PIC bits outside the census

Unit `pic_extra`, macro prefix `PIC`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `wid_stat` | 0x8 | rw | 64 |  |  | unknown | established |  |
| `wid_err_upper` | 0x10 | rw | 64 |  |  | unknown | established |  |
| `wid_int_upper` | 0x30 | rw | 64 |  |  | unknown | established |  |
| `wid_tst_pin_ctrl` | 0x70 | rw | 64 |  |  | unknown | established |  |
| `pci_err_upper` | 0xd0 | rw | 64 |  |  | unknown | established |  |
| `buf_addr_match` | 0x300 | rw | 64 | 32 |  | unknown | established |  |
| `buf_flush_w_touch` | 0x400 | rw | 64 | 8 |  | unknown | established |  |
| `buf_flush_wo_touch` | 0x408 | rw | 64 | 8 |  | unknown | established |  |
| `buf_inflight` | 0x410 | rw | 64 | 8 |  | unknown | established |  |
| `buf_prefetch` | 0x418 | rw | 64 | 8 |  | unknown | established |  |
| `buf_total_pci_retry` | 0x420 | rw | 64 | 8 |  | unknown | established |  |
| `buf_max_pci_retry` | 0x428 | rw | 64 | 8 |  | unknown | established |  |
| `buf_max_latency` | 0x430 | rw | 64 | 8 |  | unknown | established |  |
| `buf_clear_all` | 0x438 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_timeout` | 0x638 | rw | 64 |  |  | unknown | established |  |
| `pcix_read_buf_addr` | 0xa00 | rw | 64 | 16 |  | unknown | established |  |
| `pcix_read_buf_attr` | 0xa08 | rw | 64 | 16 |  | unknown | established |  |
| `pcix_write_buf_addr` | 0xb00 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_write_buf_attr` | 0xb08 | rw | 64 | 8 |  | unknown | established |  |
| `pcix_write_buf_valid` | 0xb10 | rw | 64 | 8 |  | unknown | established |  |
| `int_ate_mp` | 0x12000 | rw | 64 | 1024 |  | unknown | established |  |

### Register `wid_stat`

Widget status, the second word of the standard widget configuration block (`p_wid_stat`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `wid_err_upper`

Widget error address, upper word (`p_wid_err_upper`); the lower word is the census register `bus_err`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `wid_int_upper`

Widget interrupt destination, upper word (`p_wid_int_upper`); the lower word is the census register `intr_dst_target_id`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `wid_tst_pin_ctrl`

Test pin control (`p_wid_tst_pin_ctrl`), the one slot of the bridge-specific block between the response words and the address-lock error register. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `pci_err_upper`

PCI bus error address, upper word (`p_pci_err_upper`); the lower word is the census register `pci_bus_addr`. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `buf_addr_match`

Buffer address match registers: sixteen pairs, upper word then lower word, sixteen bytes per pair (`p_buf_addr_match[n].upper` and `.lower`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 32 registers, stride 8.

### Register `buf_flush_w_touch`

Performance monitor block n, word 0 (`p_buf_count[n].flush_w_touch`): eight blocks of eight words, 0x40 bytes apart. The header comment marks them even-numbered buffers only. The register names are the only description. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_flush_wo_touch`

Performance monitor block n, word 1 (`flush_wo_touch`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_inflight`

Performance monitor block n, word 2 (`inflight`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_prefetch`

Performance monitor block n, word 3 (`prefetch`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_total_pci_retry`

Performance monitor block n, word 4 (`total_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_max_pci_retry`

Performance monitor block n, word 5 (`max_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_max_latency`

Performance monitor block n, word 6 (`max_latency`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `buf_clear_all`

Performance monitor block n, word 7 (`clear_all`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 64.

### Register `pcix_timeout`

PCI-X timeout (`p_pcix_timeout`), the eighth word of the PCI-X register block that follows the seven census registers. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

### Register `pcix_read_buf_addr`

PCI-X read buffer n, address word (`p_pcix_read_buf_64[n].p_buf_addr`); the attribute word of the same buffer follows it. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `pcix_read_buf_attr`

PCI-X read buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 16 registers, stride 16.

### Register `pcix_write_buf_addr`

PCI-X write buffer n, address word (`p_pcix_write_buf_64[n].p_buf_addr`); the attribute, valid and one unused word follow at eight-byte steps. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `pcix_write_buf_attr`

PCI-X write buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `pcix_write_buf_valid`

PCI-X write buffer n, valid word (`p_buf_valid`). Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 8 registers, stride 32.

### Register `int_ate_mp`

Second copy of the internal translation entries with manual parity generation (`p_int_ate_ram_mp`); the census register `int_ate` is the automatic-parity copy. No IRIX routine reaches this range. Offset, width and name are the header definition. Access direction is not stated by the header or by any code read; nothing in the SN2 driver or the IRIX objects reaches this register, so its behaviour is unknown.

Array of 1024 registers, stride 8.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `ARB_REG` | 64 | established |  |
| `BUF_FLUSH_WO_TOUCH_REG` | 64 | established |  |
| `BUF_FLUSH_W_TOUCH_REG` | 64 | established |  |
| `BUF_INFLIGHT_REG` | 64 | established |  |
| `BUF_MATCH_LOWER_REG` | 64 | established |  |
| `BUF_MATCH_UPPER_REG` | 64 | established |  |
| `BUF_MAX_LATENCY_REG` | 64 | established |  |
| `BUF_MAX_RETRY_REG` | 64 | established |  |
| `BUF_PREFETCH_REG` | 64 | established |  |
| `BUF_TOTAL_RETRY_REG` | 64 | established |  |
| `BUS_TIMEOUT_REG` | 64 | established |  |
| `CMD_WORD_REG` | 64 | established |  |
| `CONTROL_REG` | 64 | established |  |
| `DEVICE_REG` | 64 | established |  |
| `DIR_MAP_REG` | 64 | established |  |
| `ERR_INT_VIEW_REG` | 64 | established |  |
| `ERR_LOWER_REG` | 64 | established |  |
| `ERR_UPPER_REG` | 64 | established |  |
| `ID_REG` | 64 | established |  |
| `INT_ADDR_REG` | 64 | established |  |
| `INT_DEST_LOWER_REG` | 64 | established |  |
| `INT_DEST_UPPER_REG` | 64 | established |  |
| `INT_DEVICE_REG` | 64 | established |  |
| `INT_ENABLE_REG` | 64 | established |  |
| `INT_HOST_ERR_REG` | 64 | established |  |
| `INT_MODE_REG` | 64 | established |  |
| `INT_RESET_REG` | 64 | established |  |
| `INT_STATUS_REG` | 64 | established |  |
| `LINK_ERR_ADDR_REG` | 64 | established |  |
| `LLP_CFG_REG` | 64 | established |  |
| `MAP_FAULT_REG` | 64 | established |  |
| `MULT_INT_REG` | 64 | established |  |
| `PCIX_ERR_ATTR_REG` | 64 | established |  |
| `PCIX_READ_BUF_ATTR_REG` | 64 | established |  |
| `PCIX_TIMEOUT_REG` | 64 | established |  |
| `PCIX_WRITE_BUF_ATTR_REG` | 64 | established |  |
| `PCIX_WRITE_BUF_VALID_REG` | 64 | established |  |
| `PCI_ERR_LOWER_REG` | 64 | established |  |
| `PCI_ERR_UPPER_REG` | 64 | established |  |
| `RAM_PERR_REG` | 64 | established |  |
| `REQ_TIMEOUT_REG` | 64 | established |  |
| `RESP_CLEAR_REG` | 64 | established |  |
| `RESP_ERR_LOWER_REG` | 64 | established |  |
| `RESP_ERR_UPPER_REG` | 64 | established |  |
| `RESP_STATUS_REG` | 64 | established |  |
| `RRB_EVEN_REG` | 64 | established |  |
| `RRB_ODD_REG` | 64 | established |  |
| `STATUS_REG` | 64 | established |  |
| `TEST_PIN_CTRL_REG` | 64 | established |  |
| `TYPE1_CFG_REG` | 64 | established |  |

### Word `ARB_REG`

Arbitration: request wait tick and enable, grant freeze, bridge high and low priority enables, and device-broke bits (names only).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:20 | `dev_broke` | established |  |  |  |
| 17:16 | `req_wait_tick` | established |  |  |  |
| 11:8 | `req_wait_en` | established |  |  |  |
| 7 | `disarb` | established |  |  |  |
| 6 | `freeze_gnt` | established |  |  |  |
| 4:3 | `en_bridge_hi` | established |  |  |  |
| 1:0 | `en_bridge_lo` | established |  |  |  |

### Word `BUF_FLUSH_WO_TOUCH_REG`

Performance counter, per even buffer block: flushes with no data used. A word write clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `notouch_cnt` | established |  |  |  |

### Word `BUF_FLUSH_W_TOUCH_REG`

Performance counter, per even buffer block: flushes after at least one data use. A word write clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `touch_cnt` | established |  |  |  |

### Word `BUF_INFLIGHT_REG`

Performance counter, per even buffer block: bus clocks a request spent in flight. A word write clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `inflight_cnt` | established |  |  |  |

### Word `BUF_MATCH_LOWER_REG`

Read response buffer address match, lower word.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `filled` | established |  |  |  |
| 62 | `armed` | established |  |  |  |
| 61 | `flush` | established |  |  |  |
| 60 | `xerr` | established |  |  |  |
| 59 | `pkterr` | established |  |  |  |
| 58 | `timeout` | established |  |  |  |
| 57 | `prefetch` | established |  |  |  |
| 56 | `precise` | established |  |  |  |
| 55:48 | `dw_be` | established |  |  |  |
| 47:32 | `upp_addr` | established |  |  |  |
| 31:0 | `low_addr` | established |  |  |  |

### Word `BUF_MATCH_UPPER_REG`

Read response buffer address match, upper word: buffer state flags and the upper address and byte enables.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `filled` | established |  |  |  |
| 30 | `armed` | established |  |  |  |
| 29 | `flush` | established |  |  |  |
| 28 | `xerr` | established |  |  |  |
| 27 | `pkterr` | established |  |  |  |
| 26 | `timeout` | established |  |  |  |
| 25 | `prefetch` | established |  |  |  |
| 24 | `precise` | established |  |  |  |
| 23:16 | `dw_be` | established |  |  |  |
| 15:0 | `upp_addr` | established |  |  |  |

### Word `BUF_MAX_LATENCY_REG`

Performance counter, per even buffer block: longest request latency in bus clocks. A word write clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `max_latency_cnt` | established |  |  |  |

### Word `BUF_MAX_RETRY_REG`

Performance counter, per even buffer block: largest retry count for one request. A word write clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `max_retry_cnt` | established |  |  |  |

### Word `BUF_PREFETCH_REG`

Performance counter, per even buffer block: requests from the prefetcher. A word write clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `prefetch_cnt` | established |  |  |  |

### Word `BUF_TOTAL_RETRY_REG`

Performance counter, per even buffer block: PCI retries that matched the buffer tag. A word write clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `retry_cnt` | established |  |  |  |

### Word `BUS_TIMEOUT_REG`

PIO retry control: retry hold-off and retry count for programmed I/O to the PCI bus. IRIX clears the low ten bits for one specific device pair (meaning unknown).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20:16 | `pci_retry_hld` | established |  |  |  |
| 9:0 | `pci_retry_cnt` | established |  |  |  |

### Word `CMD_WORD_REG`

Held Crosstalk command word. Same layout is used for the bus-side error word and the link-side error word (request FIFO overflow, unexpected response).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `didn` | established |  |  |  |
| 27:24 | `sidn` | established |  |  |  |
| 23:20 | `pactyp` | established |  |  |  |
| 19:15 | `tnum` | established |  |  |  |
| 14 | `coherent` | established |  |  |  |
| 13:12 | `ds` | established |  |  |  |
| 11 | `gbr` | established |  |  |  |
| 10 | `vbpm` | established |  |  |  |
| 9 | `error` | established |  |  |  |
| 8 | `barrier` | established |  |  |  |

### Word `CONTROL_REG`

Widget control. Fields from the register structure plus the mask definitions in bridge.h for the bits the structure leaves reserved (bus, device and function number, parity enables, no-snoop and relaxed ordering). IRIX attach writes bits 55:48, 31:29 and 21 (see README, "Control register").

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62 | `no_snoop` | established |  |  | No-snoop control bit (PIC_CTRL_NO_SNOOP). Effect on PCI-X attributes is inferred from the name. IRIX attach clears bits 62:61. |
| 61 | `relax_order` | established |  |  | Relaxed-ordering control bit (PIC_CTRL_RELAX_ORDER); effect inferred from the name. |
| 55:48 | `bus_num` | established |  |  | Bus number field (PIC_CTRL_BUS_NUM). IRIX attach clears bits 55:48 and writes the caller value there (established); that it is the bus number the PIC presents in PCI-X attributes is inferred. |
| 47:43 | `dev_num` | established |  |  | Device number field (PIC_CTRL_DEV_NUM). IRIX attach clears bits 47:40, which covers this field and the function field. |
| 42:40 | `fun_num` | established |  |  | Function number field (PIC_CTRL_FUN_NUM). |
| 31 | `par_en_ate` | established |  |  | Parity enable, translation RAM (PIC_CTRL_PAR_EN_ATE). IRIX attach sets bits 31:30 always. |
| 30 | `par_en_resp` | established |  |  | Parity enable, response RAM (PIC_CTRL_PAR_EN_RESP). |
| 29 | `par_en_req` | established |  |  | Parity enable, request path (PIC_CTRL_PAR_EN_REQ). IRIX attach sets it unless the revision is 1 (established). The public workaround list says revision A must not enable write-request RAM parity checking; tying the two is inferred (README, "Revision differences"). |
| 27:24 | `rst_pin_n` | established |  |  | PCI reset pins, one bit per pin (name and the four-bit mask in bridge.h only). |
| 22 | `mem_swap` | established |  |  | Memory byte swap (name only). |
| 21 | `page_size` | established |  |  | Translation page size: set for 16 KiB I/O pages, clear for 4 KiB. The Altix kernel sets it from its page size; IRIX attach sets it always. |
| 16 | `f_bad_pkt` | established |  |  | Force bad packet (name only). |
| 15:12 | `llp_xbar_crd` | established |  |  | Link-layer crossbar credit count. |
| 11 | `clr_rllp_cnt` | established |  |  | Clear the receive link-layer counter. |
| 10 | `clr_tllp_cnt` | established |  |  | Clear the transmit link-layer counter. |
| 9 | `sys_end` | established |  |  | System endianness select (name only; the sense of the two states is not stated). |
| 5:4 | `pci_speed` | established |  |  | PCI bus speed field. IRIX reads bits 5:4 through its speed accessor (established); the code values are not stated. |
| 3:0 | `widget_id` | established |  |  | This widget number on the Crosstalk link (inferred from the name; IRIX attach merges the widget number into the register). |

### Word `DEVICE_REG`

Per-device control. Bit 19 is swap_direct (README, "Device-register bit 19").

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 29 | `en_virtual1` | established |  |  |  |
| 28 | `en_error_lock` | established |  |  |  |
| 27 | `en_page_chk` | established |  |  |  |
| 26 | `force_pci_par` | established |  |  |  |
| 25 | `en_virtual0` | established |  |  |  |
| 23 | `dir_wrt_gen` | established |  |  |  |
| 22 | `dev_size` | established |  |  |  |
| 21 | `real_time` | established |  |  |  |
| 19 | `swap_direct` | established |  |  | Byte swap of the 32-bit direct window. |
| 18 | `prefetch` | established |  |  |  |
| 17 | `precise` | established |  |  |  |
| 16 | `coherent` | established |  |  |  |
| 15 | `barrier` | established |  |  |  |
| 14 | `gbr` | established |  |  |  |
| 13 | `dev_swap` | established |  |  |  |
| 12 | `dev_io_mem` | established |  |  |  |
| 11:0 | `dev_off` | established |  |  | Device offset, 12 bits. |

### Word `DIR_MAP_REG`

Direct map: relocates a 2 GiB PCI window onto Crosstalk. IRIX writes widget at 23:20, offset at 16:0 (in units of 2 GiB) and bit 17 only for a translation equal to 0x20000000.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:20 | `dir_w_id` | established |  |  | Target widget number for the direct window. |
| 17 | `dir_add512` | established |  |  | Add 512 MiB to the base. |
| 16:0 | `dir_off` | established |  |  | Window offset, 2 GiB units (bit 0 is Crosstalk address bit 31). |

### Word `ERR_INT_VIEW_REG`

Error interrupt view: records an error whether or not it is enabled. Cleared by any write to the interrupt reset register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41 | `int_ram_perr` | established |  |  |  |
| 40 | `bus_arb_broke` | established |  |  |  |
| 39 | `pci_x_req_tout` | established |  |  |  |
| 38 | `pci_x_tabort` | established |  |  |  |
| 37 | `pci_x_perr` | established |  |  |  |
| 36 | `pci_x_serr` | established |  |  |  |
| 35 | `pci_x_mretry` | established |  |  |  |
| 34 | `pci_x_mtout` | established |  |  |  |
| 33 | `pci_x_da_parity` | established |  |  |  |
| 32 | `pci_x_ad_parity` | established |  |  |  |
| 30 | `pmu_page_fault` | established |  |  |  |
| 29 | `unexpected_resp` | established |  |  |  |
| 28 | `bad_xresp_packet` | established |  |  |  |
| 27 | `bad_xreq_packet` | established |  |  |  |
| 26 | `resp_xtalk_error` | established |  |  |  |
| 25 | `req_xtalk_error` | established |  |  |  |
| 24 | `invalid_access` | established |  |  |  |
| 23 | `unsupported_xop` | established |  |  |  |
| 22 | `xreq_fifo_oflow` | established |  |  |  |
| 21 | `llp_rec_snerror` | established |  |  |  |
| 20 | `llp_rec_cberror` | established |  |  |  |
| 19 | `llp_rcty` | established |  |  |  |
| 18 | `llp_tx_retry` | established |  |  |  |
| 17 | `llp_tcty` | established |  |  |  |
| 15 | `pci_abort` | established |  |  |  |
| 14 | `pci_parity` | established |  |  |  |
| 13 | `pci_serr` | established |  |  |  |
| 12 | `pci_perr` | established |  |  |  |
| 11 | `pci_master_tout` | established |  |  |  |
| 10 | `pci_retry_cnt` | established |  |  |  |
| 9 | `xread_req_tout` | established |  |  |  |

### Word `ERR_LOWER_REG`

Widget error address, lower word: the address held when a bus-side error is logged; bits 47:32 repeat the upper word.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:32 | `upp_addr` | established |  |  |  |
| 31:0 | `low_addr` | established |  |  |  |

### Word `ERR_UPPER_REG`

Widget error address, upper word: the upper 16 address bits held when a bus-side error is logged. Held until the error group is cleared.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `upp_addr` | established |  |  |  |

### Word `ID_REG`

Widget identification. Layout of the JTAG-style identification word: revision, part number, manufacturer. Bit 0 has no field in the header. The compare value in the SN2 PROM for the low twelve bits is 0x049, which would make bit 0 read one (inferred, see README).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `rev_num` | established |  |  | Part revision. IRIX attach accepts 1, 2 and 3 and names them A, B and C. The public header calls 1 revision A. |
| 27:12 | `part_num` | established |  |  | Part number. The header names 0xd102 for bus 0 and 0xd112 for bus 1 (macros PIC_WIDGET_PART_NUM_BUS0 and _BUS1) and tests both with manufacturer 0x24. Which register address returns the 0xd112 value is inferred: the bus-1 block sits 0x800000 above bus 0 (PIC_BUS1_OFFSET). |
| 11:1 | `mfg_num` | established |  |  | Manufacturer number, 0x24 (36). IRIX and the SN1 IA-64 PROM both compare it against 36. |

### Word `INT_ADDR_REG`

Per-pin host address: 48-bit destination address and the 8-bit vector (bit position) in the host register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:48 | `int_fld` | established |  |  | Vector. |
| 47:0 | `int_addr` | established |  |  | Destination address. |

### Word `INT_DEST_LOWER_REG`

Interrupt destination, lower word: full destination address and the target widget. IRIX reads and writes target widget bits 51:48.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 51:48 | `target_id` | established |  |  |  |
| 47:32 | `upp_addr` | established |  |  |  |
| 31:0 | `low_addr` | established |  |  |  |

### Word `INT_DEST_UPPER_REG`

Interrupt destination, upper word: the high 16 bits of the host address plus the target widget.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:16 | `target_id` | established |  |  |  |
| 15:0 | `upp_addr` | established |  |  |  |

### Word `INT_DEVICE_REG`

Interrupt device select: three bits per pin naming the device whose buffers a pin interrupt flushes. IRIX attach writes 0x6db6db, which is device 3 in every field.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:21 | `int7_dev` | established |  |  |  |
| 20:18 | `int6_dev` | established |  |  |  |
| 17:15 | `int5_dev` | established |  |  |  |
| 14:12 | `int4_dev` | established |  |  |  |
| 11:9 | `int3_dev` | established |  |  |  |
| 8:6 | `int2_dev` | established |  |  |  |
| 5:3 | `int1_dev` | established |  |  |  |
| 2:0 | `int0_dev` | established |  |  |  |

### Word `INT_ENABLE_REG`

Interrupt enable: bit n enables the status bit n. The header says all bits are zero after reset. IRIX attach ORs in 0x00003eff7ffffe00 (bits 30:9, 39:32 and 45:41); bit 40 (arbitration failure) and the low byte stay clear.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45 | `pcix_split_msg_pe` | established |  |  | Enable for PCI-X split message parity error. |
| 44 | `pcix_split_emsg` | established |  |  | Enable for PCI-X split error message. |
| 43 | `pcix_split_to` | established |  |  | Enable for PCI-X split completion timeout. |
| 42 | `pcix_unex_comp` | established |  |  | Enable for PCI-X unexpected completion. |
| 41 | `int_ram_perr` | established |  |  |  |
| 40 | `bus_arb_broke` | established |  |  |  |
| 39 | `pci_x_req_tout` | established |  |  |  |
| 38 | `pci_x_tabort` | established |  |  |  |
| 37 | `pci_x_perr` | established |  |  |  |
| 36 | `pci_x_serr` | established |  |  |  |
| 35 | `pci_x_mretry` | established |  |  |  |
| 34 | `pci_x_mtout` | established |  |  |  |
| 33 | `pci_x_da_parity` | established |  |  |  |
| 32 | `pci_x_ad_parity` | established |  |  |  |
| 30 | `pmu_page_fault` | established |  |  |  |
| 29 | `unexpected_resp` | established |  |  |  |
| 28 | `bad_xresp_packet` | established |  |  |  |
| 27 | `bad_xreq_packet` | established |  |  |  |
| 26 | `resp_xtalk_error` | established |  |  |  |
| 25 | `req_xtalk_error` | established |  |  |  |
| 24 | `invalid_access` | established |  |  |  |
| 23 | `unsupported_xop` | established |  |  |  |
| 22 | `xreq_fifo_oflow` | established |  |  |  |
| 21 | `llp_rec_snerror` | established |  |  |  |
| 20 | `llp_rec_cberror` | established |  |  |  |
| 19 | `llp_rcty` | established |  |  |  |
| 18 | `llp_tx_retry` | established |  |  |  |
| 17 | `llp_tcty` | established |  |  |  |
| 15 | `pci_abort` | established |  |  |  |
| 14 | `pci_parity` | established |  |  |  |
| 13 | `pci_serr` | established |  |  |  |
| 12 | `pci_perr` | established |  |  |  |
| 11 | `pci_master_tout` | established |  |  |  |
| 10 | `pci_retry_cnt` | established |  |  |  |
| 9 | `xread_req_tout` | established |  |  |  |
| 7:0 | `int_state` | established |  |  |  |

### Word `INT_HOST_ERR_REG`

Host error field: the bit position in the host interrupt register that an error sets.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `bridge_err_fld` | established |  |  |  |

### Word `INT_MODE_REG`

Interrupt mode: one bit per pin. IRIX attach writes zero.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `clr_pkt` | established |  |  | Per-pin mode bit named enable-clear-packet. IRIX attach writes zero. What it changes is covered under the interrupt-packet section of the README (unknown beyond the name). |

### Word `INT_RESET_REG`

Interrupt reset: write only. A one at an error bit clears that bit and rearms the error registers; bit 6 clears the multiple-error indication. Bits 6:0 carry the Bridge-family group strobes in bridge.h and 0x7f clears all of them: IRIX attach writes 0x7f. Whether a PIC honours the group strobes is unknown (README, "Open").

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45 | `pcix_split_msg_pe` | established |  |  | Clear PCI-X split message parity error. |
| 44 | `pcix_split_emsg` | established |  |  | Clear PCI-X split error message. |
| 43 | `pcix_split_to` | established |  |  | Clear PCI-X split completion timeout. |
| 42 | `pcix_unex_comp` | established |  |  | Clear PCI-X unexpected completion. |
| 41 | `int_ram_perr` | established |  |  |  |
| 40 | `bus_arb_broke` | established |  |  |  |
| 39 | `pci_x_req_tout` | established |  |  |  |
| 38 | `pci_x_tabort` | established |  |  |  |
| 37 | `pci_x_perr` | established |  |  |  |
| 36 | `pci_x_serr` | established |  |  |  |
| 35 | `pci_x_mretry` | established |  |  |  |
| 34 | `pci_x_mtout` | established |  |  |  |
| 33 | `pci_x_da_parity` | established |  |  |  |
| 32 | `pci_x_ad_parity` | established |  |  |  |
| 30 | `pmu_page_fault` | established |  |  |  |
| 29 | `unexpected_resp` | established |  |  |  |
| 28 | `bad_xresp_packet` | established |  |  |  |
| 27 | `bad_xreq_packet` | established |  |  |  |
| 26 | `resp_xtalk_error` | established |  |  |  |
| 25 | `req_xtalk_error` | established |  |  |  |
| 24 | `invalid_access` | established |  |  |  |
| 23 | `unsupported_xop` | established |  |  |  |
| 22 | `xreq_fifo_oflow` | established |  |  |  |
| 21 | `llp_rec_snerror` | established |  |  |  |
| 20 | `llp_rec_cberror` | established |  |  |  |
| 19 | `llp_rcty` | established |  |  |  |
| 18 | `llp_tx_retry` | established |  |  |  |
| 17 | `llp_tcty` | established |  |  |  |
| 15 | `pci_abort` | established |  |  |  |
| 14 | `pci_parity` | established |  |  |  |
| 13 | `pci_serr` | established |  |  |  |
| 12 | `pci_perr` | established |  |  |  |
| 11 | `pci_master_tout` | established |  |  |  |
| 10 | `pci_retry_cnt` | established |  |  |  |
| 9 | `xread_req_tout` | established |  |  |  |
| 6 | `multi_clr` | established |  |  |  |

### Word `INT_STATUS_REG`

Interrupt status: read only. Bits 7:0 are the live level of the eight interrupt pins. The remaining bits latch error conditions when the matching enable bit is set. Bits 45:42 are named in bridge.h but are reserved in the register structure.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 45 | `pcix_split_msg_pe` | established |  |  | PCI-X split message parity error. |
| 44 | `pcix_split_emsg` | established |  |  | PCI-X split error message received. |
| 43 | `pcix_split_to` | established |  |  | PCI-X split completion timeout. |
| 42 | `pcix_unex_comp` | established |  |  | PCI-X unexpected completion. |
| 41 | `int_ram_perr` | established |  |  |  |
| 40 | `bus_arb_broke` | established |  |  | Bus arbitration failure. |
| 39 | `pci_x_req_tout` | established |  |  |  |
| 38 | `pci_x_tabort` | established |  |  |  |
| 37 | `pci_x_perr` | established |  |  |  |
| 36 | `pci_x_serr` | established |  |  |  |
| 35 | `pci_x_mretry` | established |  |  |  |
| 34 | `pci_x_mtout` | established |  |  | PCI-X master timeout. |
| 33 | `pci_x_da_parity` | established |  |  |  |
| 32 | `pci_x_ad_parity` | established |  |  |  |
| 30 | `pmu_page_fault` | established |  |  |  |
| 29 | `unexpected_resp` | established |  |  |  |
| 28 | `bad_xresp_packet` | established |  |  |  |
| 27 | `bad_xreq_packet` | established |  |  |  |
| 26 | `resp_xtalk_error` | established |  |  |  |
| 25 | `req_xtalk_error` | established |  |  |  |
| 24 | `invalid_access` | established |  |  |  |
| 23 | `unsupported_xop` | established |  |  |  |
| 22 | `xreq_fifo_oflow` | established |  |  |  |
| 21 | `llp_rec_snerror` | established |  |  |  |
| 20 | `llp_rec_cberror` | established |  |  |  |
| 19 | `llp_rcty` | established |  |  |  |
| 18 | `llp_tx_retry` | established |  |  |  |
| 17 | `llp_tcty` | established |  |  |  |
| 15 | `pci_abort` | established |  |  |  |
| 14 | `pci_parity` | established |  |  |  |
| 13 | `pci_serr` | established |  |  |  |
| 12 | `pci_perr` | established |  |  |  |
| 11 | `pci_master_tout` | established |  |  | PCI master timeout, recorded only when the enable bit is set. An unclaimed configuration cycle is the usual cause (inferred, README). |
| 10 | `pci_retry_cnt` | established |  |  |  |
| 9 | `xread_req_tout` | established |  |  |  |
| 7:0 | `int_state` | established |  |  | Current level of interrupt pins 7 to 0 (active high for a pin driven low). |

### Word `LINK_ERR_ADDR_REG`

Link-side error address.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:32 | `upp_addr` | established |  |  |  |
| 31:0 | `low_addr` | established |  |  |  |

### Word `LLP_CFG_REG`

Link-layer configuration; valid on the first bus only (head 0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:16 | `llp_maxretry` | established |  |  |  |
| 15:10 | `llp_nulltimeout` | established |  |  |  |
| 9:0 | `llp_maxburst` | established |  |  |  |

### Word `MAP_FAULT_REG`

Page map fault address: PCI address bits 21:4 and device number of a translation that faulted.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:4 | `pci_addr` | established |  |  |  |
| 2:0 | `pci_dev_num` | established |  |  |  |

### Word `MULT_INT_REG`

Multiple interrupt: set when a condition recurs before it is cleared. Bit 6 of the reset register clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41 | `int_ram_perr` | established |  |  |  |
| 40 | `bus_arb_broke` | established |  |  |  |
| 39 | `pci_x_req_tout` | established |  |  |  |
| 38 | `pci_x_tabort` | established |  |  |  |
| 37 | `pci_x_perr` | established |  |  |  |
| 36 | `pci_x_serr` | established |  |  |  |
| 35 | `pci_x_mretry` | established |  |  |  |
| 34 | `pci_x_mtout` | established |  |  |  |
| 33 | `pci_x_da_parity` | established |  |  |  |
| 32 | `pci_x_ad_parity` | established |  |  |  |
| 30 | `pmu_page_fault` | established |  |  |  |
| 29 | `unexpected_resp` | established |  |  |  |
| 28 | `bad_xresp_packet` | established |  |  |  |
| 27 | `bad_xreq_packet` | established |  |  |  |
| 26 | `resp_xtalk_error` | established |  |  |  |
| 25 | `req_xtalk_error` | established |  |  |  |
| 24 | `invalid_access` | established |  |  |  |
| 23 | `unsupported_xop` | established |  |  |  |
| 22 | `xreq_fifo_oflow` | established |  |  |  |
| 21 | `llp_rec_snerror` | established |  |  |  |
| 20 | `llp_rec_cberror` | established |  |  |  |
| 19 | `llp_rcty` | established |  |  |  |
| 18 | `llp_tx_retry` | established |  |  |  |
| 17 | `llp_tcty` | established |  |  |  |
| 15 | `pci_abort` | established |  |  |  |
| 14 | `pci_parity` | established |  |  |  |
| 13 | `pci_serr` | established |  |  |  |
| 12 | `pci_perr` | established |  |  |  |
| 11 | `pci_master_tout` | established |  |  |  |
| 10 | `pci_retry_cnt` | established |  |  |  |
| 9 | `xread_req_tout` | established |  |  |  |
| 7:0 | `int_state` | established |  |  |  |

### Word `PCIX_ERR_ATTR_REG`

PCI-X error attribute (the 2.4-era offset list and the Altix structure differ on where it sits; IRIX reaches the bus error attribute at 0x608). Assuming the split-completion and DMA-request error attributes (0x620, 0x628) share the layout is inferred from the names only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:44 | `bus_cmd` | established |  |  |  |
| 43:32 | `byte_cnt` | established |  |  |  |
| 30 | `ns` | established |  |  |  |
| 29 | `ro` | established |  |  |  |
| 28:24 | `tag` | established |  |  |  |
| 23:16 | `bus_num` | established |  |  |  |
| 15:11 | `dev_num` | established |  |  |  |
| 10:8 | `fun_num` | established |  |  |  |
| 7:0 | `l_byte_cnt` | established |  |  |  |

### Word `PCIX_READ_BUF_ATTR_REG`

PCI-X read buffer attribute.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:44 | `bus_cmd` | established |  |  |  |
| 43:32 | `byte_cnt` | established |  |  |  |
| 31 | `entry_valid` | established |  |  |  |
| 30 | `ns` | established |  |  |  |
| 29 | `ro` | established |  |  |  |
| 28:24 | `tag` | established |  |  |  |
| 23:16 | `bus_num` | established |  |  |  |
| 15:11 | `dev_num` | established |  |  |  |
| 10:8 | `fun_num` | established |  |  |  |
| 5:0 | `f_buffer_index` | established |  |  |  |

### Word `PCIX_TIMEOUT_REG`

PCI-X read request timeout error pointer (read buffer structure and location). The 2.4-era offset list puts it in the low register page, but the Altix structure puts the PCI-X error group at 0x600 and up. Which slot holds this layout is unknown (README, revision differences).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8:4 | `rd_buff_loc` | established |  |  |  |
| 3:0 | `rd_buff_struct` | established |  |  |  |

### Word `PCIX_WRITE_BUF_ATTR_REG`

PCI-X write buffer attribute.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 47:44 | `bus_cmd` | established |  |  |  |
| 43:32 | `byte_cnt` | established |  |  |  |
| 31 | `entry_valid` | established |  |  |  |
| 30 | `ns` | established |  |  |  |
| 29 | `ro` | established |  |  |  |
| 28:24 | `tag` | established |  |  |  |
| 23:16 | `bus_num` | established |  |  |  |
| 15:11 | `dev_num` | established |  |  |  |
| 10:8 | `fun_num` | established |  |  |  |
| 5:0 | `f_buffer_index` | established |  |  |  |

### Word `PCIX_WRITE_BUF_VALID_REG`

PCI-X write buffer valid cache lines.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `wrt_valid_buff` | established |  |  |  |

### Word `PCI_ERR_LOWER_REG`

PCI bus error address, lower word, with the requester identity. IRIX reads it for the bus address of the error.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:56 | `pci_xtalk_did` | established |  |  |  |
| 53 | `pci_dac` | established |  |  |  |
| 52 | `pci_dev_master` | established |  |  |  |
| 51 | `pci_vdev` | established |  |  |  |
| 50:48 | `pci_dev_num` | established |  |  |  |
| 47:32 | `pci_uaddr_err` | established |  |  |  |
| 31:0 | `pci_laddr_err` | established |  |  |  |

### Word `PCI_ERR_UPPER_REG`

PCI bus error address, upper word, with the requester identity.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27:24 | `pci_xtalk_did` | established |  |  |  |
| 21 | `pci_dac` | established |  |  |  |
| 20 | `pci_dev_master` | established |  |  |  |
| 19 | `pci_vdev` | established |  |  |  |
| 18:16 | `pci_dev_num` | established |  |  |  |
| 15:0 | `pci_uaddr_err` | established |  |  |  |

### Word `RAM_PERR_REG`

Internal RAM parity error log: failing entry address and per-RAM error flags.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 57:48 | `ate_err_addr` | established |  |  |  |
| 40:32 | `rd_resp_err_addr` | established |  |  |  |
| 31:24 | `wrt_resp_err_addr` | established |  |  |  |
| 21 | `ate_err` | established |  |  |  |
| 20 | `rd_resp_err` | established |  |  |  |
| 19 | `wrt_resp_err` | established |  |  |  |
| 18:16 | `dbe_ate` | established |  |  |  |
| 15:8 | `dbe_rd` | established |  |  |  |
| 7:0 | `dbe_wrt` | established |  |  |  |

### Word `REQ_TIMEOUT_REG`

Request timeout reload value. The timer ticks every 32 PCI clocks (960 ns at 33 MHz). IRIX writes 0x750 on revision 1 only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `time_out` | established |  |  |  |

### Word `RESP_CLEAR_REG`

Read response buffer clear: write a one to discard a buffer.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `rrb_clear` | established |  |  |  |

### Word `RESP_ERR_LOWER_REG`

Response-buffer error address, lower word, with the device and buffer number.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:52 | `dev_num` | established |  |  |  |
| 51:48 | `buff_num` | established |  |  |  |
| 47:32 | `upp_addr` | established |  |  |  |
| 31:0 | `low_addr` | established |  |  |  |

### Word `RESP_ERR_UPPER_REG`

Response-buffer error address, upper word, with the device and buffer number of the failing entry.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:20 | `dev_num` | established |  |  |  |
| 19:16 | `buff_num` | established |  |  |  |
| 15:0 | `upp_addr` | established |  |  |  |

### Word `RESP_STATUS_REG`

Read response buffer status: one valid bit and one in-use bit per buffer.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:16 | `rrb_valid` | established |  |  |  |
| 15:0 | `rrb_inuse` | established |  |  |  |

### Word `RRB_EVEN_REG`

Read response buffer allocation, even devices. Buffers 0,2,...,14, four bits each: enable, 2-bit virtual channel, device-pair bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `buff_14_en` | established |  |  |  |
| 30:29 | `buff_14_vdev` | established |  |  |  |
| 28 | `buff_14_pdev` | established |  |  |  |
| 27 | `buff_12_en` | established |  |  |  |
| 26:25 | `buff_12_vdev` | established |  |  |  |
| 24 | `buff_12_pdev` | established |  |  |  |
| 23 | `buff_10_en` | established |  |  |  |
| 22:21 | `buff_10_vdev` | established |  |  |  |
| 20 | `buff_10_pdev` | established |  |  |  |
| 19 | `buff_8_en` | established |  |  |  |
| 18:17 | `buff_8_vdev` | established |  |  |  |
| 16 | `buff_8_pdev` | established |  |  |  |
| 15 | `buff_6_en` | established |  |  |  |
| 14:13 | `buff_6_vdev` | established |  |  |  |
| 12 | `buff_6_pdev` | established |  |  |  |
| 11 | `buff_4_en` | established |  |  |  |
| 10:9 | `buff_4_vdev` | established |  |  |  |
| 8 | `buff_4_pdev` | established |  |  |  |
| 7 | `buff_2_en` | established |  |  |  |
| 6:5 | `buff_2_vdev` | established |  |  |  |
| 4 | `buff_2_pdev` | established |  |  |  |
| 3 | `buff_0_en` | established |  |  |  |
| 2:1 | `buff_0_vdev` | established |  |  |  |
| 0 | `buff_0_pdev` | established |  |  |  |

### Word `RRB_ODD_REG`

Read response buffer allocation, odd devices. Buffers 1,3,...,15, four bits each.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `buff_15_en` | established |  |  |  |
| 30:29 | `buff_15_vdev` | established |  |  |  |
| 28 | `buff_15_pdev` | established |  |  |  |
| 27 | `buff_13_en` | established |  |  |  |
| 26:25 | `buff_13_vdev` | established |  |  |  |
| 24 | `buff_13_pdev` | established |  |  |  |
| 23 | `buff_11_en` | established |  |  |  |
| 22:21 | `buff_11_vdev` | established |  |  |  |
| 20 | `buff_11_pdev` | established |  |  |  |
| 19 | `buff_9_en` | established |  |  |  |
| 18:17 | `buff_9_vdev` | established |  |  |  |
| 16 | `buff_9_pdev` | established |  |  |  |
| 15 | `buff_7_en` | established |  |  |  |
| 14:13 | `buff_7_vdev` | established |  |  |  |
| 12 | `buff_7_pdev` | established |  |  |  |
| 11 | `buff_5_en` | established |  |  |  |
| 10:9 | `buff_5_vdev` | established |  |  |  |
| 8 | `buff_5_pdev` | established |  |  |  |
| 7 | `buff_3_en` | established |  |  |  |
| 6:5 | `buff_3_vdev` | established |  |  |  |
| 4 | `buff_3_pdev` | established |  |  |  |
| 3 | `buff_1_en` | established |  |  |  |
| 2:1 | `buff_1_vdev` | established |  |  |  |
| 0 | `buff_1_pdev` | established |  |  |  |

### Word `STATUS_REG`

Widget status. Bus-side status. Bits 35:33 carry the PCI-X mode report; the low byte is the live level of the miscellaneous PCI inputs.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:34 | `pci_x_speed` | established |  |  | PCI-X bus speed code. |
| 33 | `pci_x_active` | established |  |  | The bus is running in PCI-X mode. |
| 31:24 | `llp_rec_cnt` | established |  |  | Link-layer receive counter. |
| 23:16 | `llp_tx_cnt` | established |  |  | Link-layer transmit counter. |
| 15:12 | `rx_credit_cnt` | established |  |  | Receive credit count. |
| 11:8 | `tx_credit_cnt` | established |  |  | Transmit credit count. |
| 7:0 | `pci_misc_input` | established |  |  | Level of the PCI miscellaneous input pins. README records the interrupt pin sense in the interrupt status register, not here. |

### Word `TEST_PIN_CTRL_REG`

Test pin control: selects output function and value for the test pins. Diagnostic only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `tdata_out` | established |  |  |  |
| 15:14 | `sel_tpin_7` | established |  |  |  |
| 13:12 | `sel_tpin_6` | established |  |  |  |
| 11:10 | `sel_tpin_5` | established |  |  |  |
| 9:8 | `sel_tpin_4` | established |  |  |  |
| 7:6 | `sel_tpin_3` | established |  |  |  |
| 5:4 | `sel_tpin_2` | established |  |  |  |
| 3:2 | `sel_tpin_1` | established |  |  |  |
| 1:0 | `sel_tpin_0` | established |  |  |  |

### Word `TYPE1_CFG_REG`

Type-1 configuration address bits: supplies the secondary bus and device number of a type-1 configuration cycle.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `bus_num` | established |  |  |  |
| 15:11 | `dev_num` | established |  |  |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ATE_ADDR_SHIFT` | 0xc | established |  | Translation entry bit 12 is the lowest page-address bit; the kernel stores the page-aligned address in place with the low bits as flags, whatever the I/O page size. |
| `ATE_BARRIER` | 0x10 | established |  | Bit 4: barrier, requested for consistent (coherent-memory) mappings. |
| `ATE_COHERENT` | 0x2 | established |  | Bit 1 of a translation entry on the PIC: coherent. The same bit position is the programmed-I/O bit on the TIOCP. |
| `ATE_MSI` | 0x4 | established |  | Bit 2: the mapping is for a message-signalled interrupt write. |
| `ATE_PREFETCH` | 0x8 | established |  | Bit 3: prefetch. The kernel clears it in PCI-X mode because prefetch is not supported there. |
| `ATE_TARGET_SHIFT` | 0x8 | established |  | Shift of the target widget number in a PIC translation entry: the kernel ORs the hub's Crosstalk widget id left by 8. Entry bits from 12 up carry the page address (shift PCI32_ATE_ADDR_SHFT 12). |
| `ATE_VALID` | 0x1 | established |  | Bit 0 of an internal translation entry: valid. |
| `CFG_TYPE0_BASE` | 0x20000 | established |  | Base of eight type-0 configuration windows of 0x1000 bytes each (eight functions of 0x100 bytes). Internal device n is reached through window n + 1 because the PIC takes device 0: the first device sits one window up. The kernel derives the internal device as PCI slot minus 1. |
| `CFG_TYPE1_BASE` | 0x28000 | established |  | Base of the 0x1000-byte type-1 configuration window. |
| `CONTROL_PAGE_SIZE_16K` | 0x200000 | established |  | Bit 21 of the control register: translation page size. The kernel clears it for 4 KiB I/O pages and sets it when its page size is 16 KiB or more. The shipped IRIX attach sets it unconditionally, which agrees with 16 KiB pages. |
| `DEVICE_SWAP_DIRECT` | 0x80000 | inferred |  | bit 19 of the device register (0x200 plus 8n), named swap_direct in the public PIC header. Set selects the address-preserving byte map for the 32-bit direct window; clear selects the lane-preserving map. The bit position comes from the public SN2 driver's byte-stream flag mapping onto this bit; no PIC measurement confirms the lane sense (open question in open-questions.md) |
| `DIRECT64_ATTR_BARRIER` | 0x100000000000000 | established |  | Bit 56: barrier. Set for consistent mappings. |
| `DIRECT64_ATTR_PRECISE` | 0x400000000000000 | established |  | Bit 58: precise. Defined; no SGI Altix provider code read sets it. |
| `DIRECT64_ATTR_PREFETCH` | 0x800000000000000 | established |  | Bit 59 of a 64-bit direct address: prefetch. Cleared by the kernel in PCI-X mode. Used for streaming mappings. |
| `DIRECT64_ATTR_SWAP` | 0x80000000000000 | established |  | Bit 55: byte swap. Defined, but no SGI Altix provider code read ever sets it. |
| `DIRECT64_ATTR_TARGET_SHIFT` | 0x3c | established |  | Shift of the target widget number in a 64-bit direct PCI address. Same placement as the other PIC page, now also named by the SGI Altix provider. |
| `DIRECT64_ATTR_VIRTUAL` | 0x200000000000000 | established |  | Bit 57: second virtual channel. In conventional PCI mode the kernel sets it for every function except function 0, so function 0 uses channel 0 and other functions channel 1. Not set in PCI-X mode. |
| `DIRECT64_ATTR_VIRTUAL1` | 0x40000000000000 | established |  | Bit 54: defined next to the virtual-channel bit; no provider code read sets it. |
| `HOST_INTR_ADDR_MASK` | 0xffffffffffff | established |  | Mask of the destination address field of a per-pin interrupt address register, 48 bits. The kernel clears this field and ORs the new address in; the TIOCP uses a 54-bit field. |
| `INTR_FLUSH_WAIT_VALUE` | 0x10f | established |  | The value the kernel's read-ordering flush waits to see at the memory word it armed as an interrupt target after forcing a pin interrupt. As a packet shape, 0x100 plus vector 0x0f, it matches the shape the shipped IRIX path is inferred to wait for; the kernel names no meaning for bit 8. |
| `INTR_PCIX_MASTER_TIMEOUT` | 0x400000000 | established |  | bit 34 of the interrupt status register (0x100), the PCI-X master timeout. Which bit a bus in PCI-X mode sets for an unclaimed configuration cycle is not stated by any source read (unknown) |
| `INTR_PCI_MASTER_TIMEOUT` | 0x800 | established |  | bit 11 of the interrupt status register (0x100) and of the error view (0x170). The view records a master timeout whether or not the enable bit is set; status records it only when bit 11 of the enable register (0x108) is also set. An unclaimed configuration cycle is the usual source (inferred, see devices/pic/facts-outside-census.md) |
| `INTR_RESET_MULTIPLE_CLEAR` | 0x40 | established |  | bit 6 of the reset register (0x110), the multiple-error clear. Bits 8:7 and 5:0 have no PIC field. A one written at an error bit's own position clears that bit and rearms the error registers, and any write to 0x110 also clears the error view |
| `PCI32_DIRECT_BASE` | 0x80000000 | established |  | Start of the 2 GiB direct-mapped 32-bit window, offset from the base the direct-map register holds. Not used in PCI-X mode. |
| `PCI32_MAPPED_BASE` | 0x40000000 | established |  | Start of the translated 32-bit window: PCI addresses from here up to PCI32_DIRECT_BASE go through the internal translation entries, index (address minus base) shifted by the I/O page shift. |
| `PCI32_MAPPED_SWAP` | 0x20000000 | established |  | Bit 29 of a translated-window PCI address: the kernel sets it only when the device's Device register copy it was handed already has the swap bit (bit 19) set. |
| `PCIX_SPECIAL_CYCLE_BASE` | 0x40000 | established |  | Eight-byte PCI-X special cycle window. No code read uses it. |
| `PCI_IACK_BASE` | 0x30000 | established |  | Eight-byte PCI interrupt acknowledge cycle window. No code read uses it. |
