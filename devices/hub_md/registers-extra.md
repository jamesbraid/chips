<!-- generated from devices/hub_md/registers-extra.toml by defs-gen - do not edit, change the source -->

# Hub memory and directory register layouts and constants outside the census

Unit `hub_md_extra`, macro prefix `HUB`.
Default source: public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `md_memory_config` | 0x200018 | rw | 64 |  |  | 0x1e7fbc3fffffff (established) | established | census: 3 sites, 3 routines (r); census: 13 sites, 12 routines (rw, indexed) |
| `md_refresh_control` | 0x200020 | r | 64 |  |  | 0x400 (established) | established | census: 1 sites, 1 routines |
| `md_mig_diff_thresh` | 0x200030 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `md_mig_value_thresh` | 0x200038 | rw | 64 |  |  | unknown | established | census: 10 sites, 5 routines |
| `md_dir_error` | 0x200050 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (r, indexed) |
| `md_protocol_error` | 0x200060 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_mem_error` | 0x200070 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (r, indexed) |
| `md_misc_error` | 0x200080 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_mem_dimm_init` | 0x200090 | w | 64 |  |  | unknown | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_dir_dimm_init` | 0x200098 | w | 64 |  |  | unknown | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_moq_size` | 0x2000a0 | w | 64 |  |  | 0x3212 (established) | established | census: 1 sites, 1 routines |
| `md_mlan_ctl` | 0x2000a8 | rw | 64 |  |  | 0x18b100002 (established) | established | census: 6 sites, 1 routines |
| `md_perf_sel` | 0x210000 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_perf_cnt0` | 0x210010 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_slotid_ustat` | 0x220048 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines (r); census: 2 sites, 2 routines (r, indexed) |
| `md_led1` | 0x220058 | w | 64 |  |  | unknown | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_1` | 0x220088 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_2` | 0x220090 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_3` | 0x220098 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_4` | 0x2200a0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_5` | 0x2200a8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_6` | 0x2200b0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_7` | 0x2200b8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_8` | 0x2200c0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_9` | 0x2200c8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_10` | 0x2200d0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_11` | 0x2200d8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_12` | 0x2200e0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_13` | 0x2200e8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_14` | 0x2200f0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |
| `md_ureg1_15` | 0x2200f8 | rw | 64 |  |  | 0x0 (established) | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) |

### Register `md_memory_config`

Layout of the memory configuration register. Bank descriptors take bits 23:0, three bits each. The timing fields and the bank-size codes are named by the header, and their meaning is only partly stated there.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 53:49 | `fprom_cyc` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Five-bit boot flash cycle timing field at 53:49, named FPROM_CYC in the header. The flash reading of the name is inferred. |
| 48:44 | `fprom_wr` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Five-bit boot flash write timing field at 48:44, named FPROM_WR in the header. The flash reading of the name is inferred. |
| 43:39 | `uctlr_cyc` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Five-bit cycle timing field at 43:39, named UCTLR_CYC in the header. The abbreviation is the only name given; its meaning is inferred from the name. |
| 38:34 | `uctlr_wr` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Five-bit write timing field at 38:34, named UCTLR_WR in the header. The header's abbreviation is the only name for it; its meaning is inferred from the name. |
| 33:32 | `dimm0_sel` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Two-bit DIMM 0 select field at 33:32 (mask 3 in the header). The header gives no meaning for the values. The Origin 2000 boot firmware writes the value 2 here while exchanging the size codes of bank pairs (0,1), (2,3), (4,5) and (6,7), and the shipped kernel names a failing module from this field XORed with address bits 31:29; so the field permutes which DIMM serves a bank window. Established for the writes and the XOR, inferred for the effect. |
| 31 | `io_prot_en` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | I/O protection enable, bit 31, named MMC_IO_PROT_EN in the header. |
| 30 | `arb_mlss` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Bit 30, named MMC_ARB_MLSS in the header. The header gives no meaning for it, so only the name and position are imported. |
| 29 | `ignore_ecc` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Ignore directory ECC bit, bit 29. The header names it MMC_IGNORE_ECC and gives no further behaviour. |
| 28 | `dir_premium` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Directory format bit: set selects the premium directory format, clear the standard one. The header's own accessor macro reads it this way. |
| 27:24 | `reply_guar` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Reply guarantee count, four bits at 27:24 (mask 15 in the header). Its meaning is not stated in the header. |
| 23:21 | `bank7` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 7, bits 23:21. |
| 20:18 | `bank6` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 6, bits 20:18. |
| 17:15 | `bank5` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 5, bits 17:15. |
| 14:12 | `bank4` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 4, bits 14:12. The header sizes eight banks in its M-mode build. |
| 11:9 | `bank3` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 3, bits 11:9. |
| 8:6 | `bank2` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 2, bits 8:6. |
| 5:3 | `bank1` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 1, bits 5:3. |
| 2:0 | `bank0` | established |  | public Linux SN0 Hub memory/directory header: MD_MEMORY_CONFIG fields (MMC_*) | Size code of bank 0, bits 2:0. Codes are in the size table below. |

### Register `md_refresh_control`

Layout of the refresh control register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | public Linux SN0 Hub memory/directory header: MD_REFRESH_CONTROL fields (MRC_*) | Refresh enable, bit 63. |
| 23:12 | `counter` | established |  | public Linux SN0 Hub memory/directory header: MD_REFRESH_CONTROL fields (MRC_*) | Twelve-bit refresh counter at 23:12. The header gives no meaning beyond the name. |
| 11:0 | `threshold` | established |  | public Linux SN0 Hub memory/directory header: MD_REFRESH_CONTROL fields (MRC_*) | Twelve-bit threshold at 11:0, named MRC_CNT_THRESH_MASK in the header. |

### Register `md_mig_diff_thresh`

Layout of the page migration difference and value thresholds. The two registers share this layout. The shipped IRIX kernel arms a threshold by setting the valid bit (bit 63) and clears the bit to disarm it while a candidate is handled.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub memory/directory header: MD_MIG_DIFF_THRES and MD_MIG_VALUE_THRES masks | Threshold enable bit. |
| 19:0 | `value` | established |  | public Linux SN0 Hub memory/directory header: MD_MIG_DIFF_THRES and MD_MIG_VALUE_THRES masks | Threshold value, twenty bits. |

### Register `md_mig_value_thresh`

Layout of the page migration difference and value thresholds. The two registers share this layout. The shipped IRIX kernel arms a threshold by setting the valid bit (bit 63) and clears the bit to disarm it while a candidate is handled.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub memory/directory header: MD_MIG_DIFF_THRES and MD_MIG_VALUE_THRES masks | Threshold enable bit. |
| 19:0 | `value` | established |  | public Linux SN0 Hub memory/directory header: MD_MIG_DIFF_THRES and MD_MIG_VALUE_THRES masks | Threshold value, twenty bits. |

### Register `md_dir_error`

Layout of the directory error latch, from the header's structure. The header lists the fields from the most significant bit down and gives a comment for each range. Bit positions here follow those comments.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `uce_vld` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Valid directory uncorrectable error. |
| 62 | `ae_vld` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Valid directory protection ECC error. |
| 61 | `ce_vld` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Valid correctable ECC error. |
| 41:39 | `bad_prot` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Access rights encoding of a bad access, bits 41:39. |
| 38:32 | `bad_syn` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Bad directory syndrome, bits 38:32. |
| 29:3 | `hspec_addr` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Address of the bad entry in the Hub special space, bits 29:3. |
| 2 | `uce_ovr` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Multiple directory uncorrectable errors. |
| 1 | `ae_ovr` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Multiple protection ECC errors. |
| 0 | `ce_ovr` | established |  | public Linux SN0 Hub memory/directory header: dir_error_reg structure | Multiple correctable errors. |

### Register `md_protocol_error`

Layout of the protocol error latch, from the header's structure.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Valid protocol error. |
| 60:50 | `initiator` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Identifier of the request initiator, eleven bits. |
| 49:48 | `backoff` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Backoff control, two bits. |
| 47:40 | `msg_type` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Type of the request, eight bits. |
| 39:38 | `access` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Access rights of the initiator, two bits. |
| 37 | `priority` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Priority level of the requester. |
| 36:33 | `dir_state` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | State of the directory, four bits. |
| 32 | `pointer_me` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Initiator is the same as the directory pointer. |
| 31:3 | `address` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Request address, bits 31:3. |
| 0 | `overrun` | established |  | public Linux SN0 Hub memory/directory header: proto_error_reg structure | Multiple protocol errors. |

### Register `md_mem_error`

Layout of the memory error latch, from the header's structure.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `uce_vld` | established |  | public Linux SN0 Hub memory/directory header: mem_error_reg structure | Valid memory uncorrectable error. |
| 62 | `ce_vld` | established |  | public Linux SN0 Hub memory/directory header: mem_error_reg structure | Valid correctable ECC error. |
| 39:32 | `bad_syn` | established |  | public Linux SN0 Hub memory/directory header: mem_error_reg structure | Bad memory ECC syndrome, bits 39:32. |
| 31:3 | `address` | established |  | public Linux SN0 Hub memory/directory header: mem_error_reg structure | Bad entry pointer, bits 31:3. |
| 1 | `uce_ovr` | established |  | public Linux SN0 Hub memory/directory header: mem_error_reg structure | Multiple memory uncorrectable errors. |
| 0 | `ce_ovr` | established |  | public Linux SN0 Hub memory/directory header: mem_error_reg structure | Multiple correctable errors. |

### Register `md_misc_error`

Layout of the miscellaneous error latch. The header's valid mask covers bits 9:0. Its long-pack mask is written with a misspelt shift macro, so only the other masks are imported as stated.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 9:8 | `ill_msg` | established |  | public Linux SN0 Hub memory/directory header: MMCE_* masks | Illegal message field, bits 9:8. |
| 7:6 | `ill_rev` | established |  | public Linux SN0 Hub memory/directory header: MMCE_* masks | Illegal revision field, bits 7:6. |
| 5:4 | `long_pack` | established |  | public Linux SN0 Hub memory/directory header: MMCE_* masks | Long packet field, bits 5:4. |
| 3:2 | `short_pack` | established |  | public Linux SN0 Hub memory/directory header: MMCE_* masks | Short packet field, bits 3:2. |
| 1:0 | `bad_data` | established |  | public Linux SN0 Hub memory/directory header: MMCE_* masks | Bad data field, bits 1:0. |

### Register `md_mem_dimm_init`

Memory DIMM mode initialisation. Layout in the MD_DIMM_INIT_FORMAT word. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:32 | `select` | established |  | public Linux SN0 Hub memory/directory header: MDI_* masks | Four-bit select field, named MDI_SELECT in the header. |
| 11:0 | `mode` | established |  | public Linux SN0 Hub memory/directory header: MDI_* masks | Twelve-bit DIMM mode field, named MDI_DIMM_MODE in the header. |

### Register `md_dir_dimm_init`

Directory DIMM mode initialisation. Same layout as the memory register. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:32 | `select` | established |  | public Linux SN0 Hub memory/directory header: MDI_* masks | Four-bit select field, named MDI_SELECT in the header. |
| 11:0 | `mode` | established |  | public Linux SN0 Hub memory/directory header: MDI_* masks | Twelve-bit DIMM mode field, named MDI_DIMM_MODE in the header. |

### Register `md_moq_size`

Layout of the outgoing queue size register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:8 | `rp_size` | established |  | public Linux SN0 Hub memory/directory header: MD_MOQ_SIZE fields (MMS_*) | Reply queue size field, six bits at 13:8, named MMS_RP_SIZE in the header. |
| 4:0 | `rq_size` | established |  | public Linux SN0 Hub memory/directory header: MD_MOQ_SIZE fields (MMS_*) | Request queue size field, five bits at 4:0, named MMS_RQ_SIZE in the header. |

### Register `md_mlan_ctl`

Layout of the one-wire (Microlan) control register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:27 | `phi1` | established |  | public Linux SN0 Hub memory/directory header: MD_MLAN_CTL fields (MLAN_*) | Seven-bit field at 33:27 (mask 0x7f shifted 27), named MLAN_PHI1 in the header. What the field shapes is not stated by the header or by any held source, so its timing meaning is unknown. |
| 26:20 | `phi0` | inferred |  | public Linux SN0 Hub memory/directory header: MD_MLAN_CTL fields (MLAN_*) | Seven-bit field named MLAN_PHI0. The header's mask for it is 0x7f shifted by 27, the same place as PHI1, which contradicts its shift constant of 20. The position 26:20 is taken from the shift constant and is inferred. What the field shapes is not stated by the header or by any held source, so its timing meaning is unknown. |
| 19:10 | `pulse` | established |  | public Linux SN0 Hub memory/directory header: MD_MLAN_CTL fields (MLAN_*) | Ten-bit pulse field at 19:10 (mask 0x3ff shifted 10). The header gives no time unit, so the real pulse width is unknown. |
| 9:2 | `sample` | established |  | public Linux SN0 Hub memory/directory header: MD_MLAN_CTL fields (MLAN_*) | Eight-bit sample field at 9:2 (mask 0xff shifted 2). The header gives no time unit or reference point, so the real sample offset is unknown. |
| 1 | `done` | established |  | public Linux SN0 Hub memory/directory header: MD_MLAN_CTL fields (MLAN_*) | Done bit, bit 1, named MLAN_DONE in the header. The header's reset constant sets only the two phase fields, but the IRIX register reset table gives the whole register's reset as 0x18b100002, so done is set at reset. |
| 0 | `rd_data` | established |  | public Linux SN0 Hub memory/directory header: MD_MLAN_CTL fields (MLAN_*) | Read-data bit, bit 0, named MLAN_RD_DATA in the header. |

### Register `md_perf_sel`

Layout of the performance counter select register. Bit positions come from the header's structure, which lists the fields from the most significant bit down. The order is taken as written there and is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `perf_en` | inferred |  | public Linux SN0 Hub memory/directory header: md_perf_sel_t structure | Counter enable, bit 3, from the header's structure. |
| 2:0 | `perf_sel` | inferred |  | public Linux SN0 Hub memory/directory header: md_perf_sel_t structure | Event select, three bits at 2:0, from the header's structure. |

### Register `md_perf_cnt0`

Layout of performance counters 0 to 5. Bit positions come from the header's structure, read in the same order as the select register and so inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `perf_cnt` | inferred |  | public Linux SN0 Hub memory/directory header: md_perf_cnt_t structure | Twenty-bit counter value, from the header's structure. |

### Register `md_slotid_ustat`

Layout of the slot identity and status register. The header also defines an SN00 slot bit at bit 7 and a PIMM field at 7:4. Both overlap bits named here, so they are left out.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `core_clk_test` | established |  | public Linux SN0 Hub memory/directory header: MD_SLOTID_USTAT fields (MSU_*) | Core clock test bit, bit 7. The header comment says only that it is for testing. |
| 6 | `core_clk` | established |  | public Linux SN0 Hub memory/directory header: MD_SLOTID_USTAT fields (MSU_*) | Core clock bit, bit 6. |
| 5 | `net_sync` | established |  | public Linux SN0 Hub memory/directory header: MD_SLOTID_USTAT fields (MSU_*) | Network sync bit, bit 5. |
| 4 | `fprom_ready` | established |  | public Linux SN0 Hub memory/directory header: MD_SLOTID_USTAT fields (MSU_*) | Flash PROM ready bit, bit 4. The header's comment names it as the flash PROM ready bit. |
| 3 | `i2c_intr` | established |  | public Linux SN0 Hub memory/directory header: MD_SLOTID_USTAT fields (MSU_*) | I2C interrupt bit, bit 3. |
| 2:0 | `sn0_slot_id` | established |  | public Linux SN0 Hub memory/directory header: MD_SLOTID_USTAT fields (MSU_*) | Slot ID, bits 2:0 (mask 7 in the header). |

### Register `md_led1`

Eight-bit LED of the second processor, the twin of md_led0 in the census. The header gives no access type; write-only is carried over from md_led0 and is inferred. The IRIX register table confirms the access.

### Register `md_ureg1_1`

Microcontroller and UART 1 register 1 of 16; the census has register 0. The IRIX register table confirms the access.

### Register `md_ureg1_2`

Microcontroller and UART 1 register 2 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_3`

Microcontroller and UART 1 register 3 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_4`

Microcontroller and UART 1 register 4 of 16; the census has register 0. The header gives no access type, so rw is assumed. The IRIX kernel's LED macro gives it a second role: on the Origin 200 (the SN00 variant) it is the eight-bit LED of the processor in slice 1, as register 0 is the LED of slice 0, at a spacing of four registers per slice. Other Hub variants use the separate LED registers.

### Register `md_ureg1_5`

Microcontroller and UART 1 register 5 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_6`

Microcontroller and UART 1 register 6 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_7`

Microcontroller and UART 1 register 7 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_8`

Microcontroller and UART 1 register 8 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_9`

Microcontroller and UART 1 register 9 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_10`

Microcontroller and UART 1 register 10 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_11`

Microcontroller and UART 1 register 11 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_12`

Microcontroller and UART 1 register 12 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_13`

Microcontroller and UART 1 register 13 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_14`

Microcontroller and UART 1 register 14 of 16; the census has register 0. The header gives no access type, so rw is assumed.

### Register `md_ureg1_15`

Microcontroller and UART 1 register 15 of 16; the census has register 0. The IRIX register table confirms the access.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `MD_MIG_CANDIDATE_FORMAT` | 64 | established | public Linux SN0 Hub memory/directory header: MD_MIG_CANDIDATE masks |

### Word `MD_MIG_CANDIDATE_FORMAT`

Layout of the page migration candidate. The header's initiator and node-number masks overlap at bits 28:20, so only the single-bit fields are imported here. The shipped IRIX kernel reads only the read-to-clear alias (md_mig_candidate_clr), in a loop until the valid bit is clear, and takes the node and page fields below from it. That a read consumes the candidate is inferred from the register name and the loop. Nothing in the kernel accesses the candidate register itself, which sits one doubleword below the alias.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub memory/directory header: MD_MIG_CANDIDATE masks | Candidate valid bit. |
| 30 | `type` | established |  | public Linux SN0 Hub memory/directory header: MD_MIG_CANDIDATE masks | Candidate type bit, named MD_MIG_CANDIDATE_TYPE in the header. Its meaning is not stated there. |
| 29 | `overrun` | established |  | public Linux SN0 Hub memory/directory header: MD_MIG_CANDIDATE masks | Candidate overrun bit. |
| 28:20 | `node` | inferred |  | public Linux SN0 Hub memory/directory header: MD_MIG_CANDIDATE_NODEID_MASK (0x1ff at shift 20) | Node number of the requester, nine bits at 28:20, from the header's node-id mask. The header's initiator mask (11 bits at shift 18) overlaps these bits, so the layout is graded inferred. |
| 17:0 | `page` | inferred |  | public Linux SN0 Hub memory/directory header: MD_MIG_CANDIDATE_ADDR_MASK (0x3ffff) | Page index within the node, eighteen bits at 17:0, from the header's address mask. The header's own comment says the address starts at bit 14, which disagrees with the mask, so the position is graded inferred. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `HUB_MD_BANK_MASK` | 0xe0000000 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank index mask, bits 31:29, per the header's MD_BANK_MASK. |
| `HUB_MD_BANK_SHIFT` | 0x1d | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Log2 of the 512 MB bank granule, per the header's MD_BANK_SHFT. |
| `HUB_MD_DIRTYPE_PREMIUM` | 0x1 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Premium directory format, when the directory format bit is set. |
| `HUB_MD_DIRTYPE_STANDARD` | 0x0 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Standard directory format, when the directory format bit is clear. |
| `HUB_MD_DIR_BUSY_EXCL` | 0x4 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Directory state busy exclusive, from the header's state constants. |
| `HUB_MD_DIR_BUSY_SHARED` | 0x3 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Directory state busy shared, from the header's state constants. |
| `HUB_MD_DIR_EXCLUSIVE` | 0x2 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Directory state exclusive, from the header's state constants. |
| `HUB_MD_DIR_POISONED` | 0x1 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Directory state poisoned, from the header's state constants. |
| `HUB_MD_DIR_SHARED` | 0x0 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Directory state shared, from the header's state constants. |
| `HUB_MD_DIR_UNOWNED` | 0x7 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Directory state unowned, from the header's state constants. |
| `HUB_MD_DIR_WAIT` | 0x5 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Directory state wait, from the header's state constants. |
| `HUB_MD_MEMORY_CONFIG_RESET_DEFAULTS` | 0x1e7fbc3fffffff | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Composite default of the memory configuration register, built from the header's default constant. The header gives it as a value software writes, not a reset read from hardware. Eight bank codes of 7, reply guarantee 15, both directory and ignore-ECC bits set, and the four timing fields at their header values. The IRIX header defines the macro with this value, and the PROM writes it to the register. |
| `HUB_MD_MEM_BANKS_M_MODE` | 0x8 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank count in the header's M-mode build, the default when N mode is not configured. |
| `HUB_MD_MEM_BANKS_N_MODE` | 0x4 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank count in the header's N-mode build (CONFIG_SGI_SN_N_MODE). |
| `HUB_MD_MLAN_CTL_ACCESS_BYTES` | 0x8 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Access size in bytes of the one-wire control register in the shipped IRIX kernel accessor: its loads and stores there are doubleword (census context). Bit 33 belongs to the upper phase field, so a 32-bit access cannot write the whole register; that consequence follows from the field layout, not from a trace. |
| `HUB_MD_MLAN_CTL_RESET_DEFAULTS` | 0x18b100000 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Default value of the one-wire control register: the two phase fields at 0x31 each, from the header's default constant. Not a reset read. The IRIX header defines the macro with this value, and the PROM writes it to the register. |
| `HUB_MD_MOQ_SIZE_RESET_DEFAULTS` | 0x3212 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Default value of the outgoing queue size register, from the header's default constant. Not a reset read. The IRIX header defines the macro with this value, and the PROM writes it to the register. |
| `HUB_MD_REFCNT_COUNT_MASK_PREMIUM` | 0x7ffff | established | public Linux SN0 Hub memory/directory header: MD_PPROT_REFCNT_SHFT, MD_PPROT_REFCNT_WIDTH | Nineteen-bit reference count mask, premium memory; which memory is premium is inferred. |
| `HUB_MD_REFCNT_COUNT_MASK_STANDARD` | 0x7ff | established | public Linux SN0 Hub memory/directory header: MD_SPROT_REFCNT_SHFT, MD_SPROT_REFCNT_WIDTH | Eleven-bit reference count mask, standard memory. |
| `HUB_MD_REFCNT_COUNT_SHIFT` | 0x5 | established | public Linux SN0 Hub memory/directory header: MD_PPROT_REFCNT_SHFT and MD_SPROT_REFCNT_SHFT | Bit position of the count in a node's reference word. |
| `HUB_MD_REFRESH_CONTROL_RESET_DEFAULTS` | 0x400 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Default value of the refresh control register, from the header's default constant. Not a reset read. The IRIX header defines the macro with this value, and the PROM writes it to the register. |
| `HUB_MD_SIZE_128MB` | 0x5 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 5: 128 MB. Valid in the memory configuration register, per the header comment. |
| `HUB_MD_SIZE_16MB` | 0x2 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 2: 16 MB. |
| `HUB_MD_SIZE_1GB` | 0x8 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 8: 1 GB. Does not fit a three-bit bank field. |
| `HUB_MD_SIZE_256MB` | 0x6 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 6: 256 MB. The header gives no validity annotation for it. |
| `HUB_MD_SIZE_2GB` | 0x9 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 9: 2 GB. Does not fit a three-bit bank field. |
| `HUB_MD_SIZE_32MB` | 0x3 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 3: 32 MB. The header marks it broken in the first Hub revision. |
| `HUB_MD_SIZE_4GB` | 0xa | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 10: 4 GB. Does not fit a three-bit bank field. |
| `HUB_MD_SIZE_512MB` | 0x7 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 7: 512 MB. Valid in the memory configuration register, per the header comment. |
| `HUB_MD_SIZE_64MB` | 0x4 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 4: 64 MB. Valid in the memory configuration register, per the header comment. |
| `HUB_MD_SIZE_8MB` | 0x1 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 1: 8 MB. |
| `HUB_MD_SIZE_EMPTY` | 0x0 | established | public Linux SN0 Hub memory/directory header, pinned linux tree (field masks, shifts and default constants) | Bank code 0: empty. Valid in the memory configuration register, per the header comment. |
