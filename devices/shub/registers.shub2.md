<!-- generated from devices/shub/registers.shub2.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 25a65e6adabd41724ca20aa7682efa4524185c9de88bf41c87116f7cdc9663a8 -->

# SHub 2 registers outside the I/O interface, differences from SHub 1

SHub 2 offsets the SGI Linux ia64 platform header defines (SH2_ names) cite it; the rest are read from the SHub 2 PROM and cite no published source. Registers the header defines only for SHub 1 are removed; for those, SHub 2's address is not in the sources read (unknown). Field layouts not patched here are the SHub 1 ones: the header gives one set of field macros for both chips. Registers added from the SHub 2 firmware (grade and site named on each) give the 32-bit offset in the local window; add 0x2_0000_0000 for the address the firmware uses.

Unit `shub2`, macro prefix `SHUB2`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `x_dimm_cfg` | 0x10000 | rw | 64 |  |  | unknown | established |  |
| `y_dimm_cfg` | 0x10008 | rw | 64 |  |  | unknown | established |  |
| `jnr_dimm_cfg` | 0x10010 | rw | 64 |  |  | unknown | established |  |
| `x_odt_cfg` | 0x10018 | rw | 64 |  |  | unknown | established |  |
| `x_cfg` | 0x10020 | rw | 64 |  |  | unknown | established |  |
| `x_dqct_cfg` | 0x10028 | rw | 64 |  |  | unknown | established |  |
| `x_refresh_control` | 0x10030 | rw | 64 |  |  | unknown | established |  |
| `y_odt_cfg` | 0x10048 | rw | 64 |  |  | unknown | established |  |
| `y_cfg` | 0x10050 | rw | 64 |  |  | unknown | established |  |
| `y_dqct_cfg` | 0x10058 | rw | 64 |  |  | unknown | established |  |
| `y_refresh_control` | 0x10060 | rw | 64 |  |  | unknown | established |  |
| `mem_red_black` | 0x10078 | w | 64 |  |  | unknown | established |  |
| `misc_mem_cfg` | 0x10080 | rw | 64 |  |  | unknown | established |  |
| `pio_rq_crd_ctl` | 0x100d8 | rw | 64 |  |  | unknown | established |  |
| `pi_md_rq_crd_ctl` | 0x100e0 | w | 64 |  |  | unknown | established |  |
| `pi_md_rp_crd_ctl` | 0x100e8 | w | 64 |  |  | unknown | established |  |
| `xn_md_rq_crd_ctl` | 0x100f0 | w | 64 |  |  | unknown | established |  |
| `xn_md_rp_crd_ctl` | 0x100f8 | w | 64 |  |  | unknown | established |  |
| `mmrbist_base` | 0x20080 | w | 64 |  |  | unknown | established |  |
| `mmrbist_ctl` | 0x20088 | rw | 64 |  |  | unknown | established |  |
| `dir_config_dqlp` | 0x30000 | rw | 64 |  |  | unknown | established |  |
| `dir_locvec_dqlp` | 0x30200 | w | 64 | 8 |  | unknown | established |  |
| `dir_privec_dqlp` | 0x30300 | w | 64 | 8 |  | unknown | established |  |
| `dir_timer_dqlp` | 0x30400 | w | 64 |  |  | unknown | established |  |
| `amo_cfg_0` | 0x34800 | rw | 64 |  |  | unknown | established |  |
| `x_bist_h` | 0x38000 | w | 64 | 4 |  | unknown | established |  |
| `x_bist_l` | 0x38010 | w | 64 | 4 |  | unknown | established |  |
| `x_bist_err_h` | 0x38020 | r | 64 | 4 |  | unknown | established |  |
| `x_bist_err_l` | 0x38030 | r | 64 | 4 |  | unknown | established |  |
| `y_bist_h` | 0x38800 | w | 64 | 4 |  | unknown | established |  |
| `y_bist_l` | 0x38810 | w | 64 | 4 |  | unknown | established |  |
| `y_bist_err_h` | 0x38820 | r | 64 | 4 |  | unknown | established |  |
| `y_bist_err_l` | 0x38830 | r | 64 | 4 |  | unknown | established |  |
| `amo_cfg_1` | 0x4b000 | rw | 64 |  |  | unknown | established |  |
| `dir_config_dqrp` | 0x50000 | rw | 64 |  |  | unknown | established |  |
| `dir_locvec_dqrp` | 0x50200 | w | 64 | 8 |  | unknown | established |  |
| `dir_privec_dqrp` | 0x50300 | w | 64 | 8 |  | unknown | established |  |
| `dir_timer_dqrp` | 0x50400 | w | 64 |  |  | unknown | established |  |
| `amo_cfg_2` | 0x54800 | rw | 64 |  |  | unknown | established |  |
| `amo_cfg_3` | 0x6b000 | rw | 64 |  |  | unknown | established |  |
| `ipi_int` | 0x10000380 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `rtc_int_config` | 0x10001480 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `rtc_int_enable` | 0x10001500 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `event_occurred` | 0x10010000 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `event_occurred_alias` | 0x10010008 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `junk_bus_time` | 0x10020000 | w | 64 |  |  | unknown | established |  |
| `junk_bus_led_data` | 0x10030000 | r | 64 | 4 |  | unknown | established |  |
| `asic_to_l1_data` | 0x10038000 | w | 64 |  |  | unknown | established |  |
| `asic_to_l1_status` | 0x10038080 | r | 64 |  |  | unknown | established |  |
| `l1_to_asic_data` | 0x10038100 | r | 64 |  |  | unknown | established |  |
| `l1_to_asic_status` | 0x10038180 | rw | 64 |  |  | unknown | established |  |
| `rack_slot_data` | 0x10038200 | r | 64 |  |  | unknown | established |  |
| `gc_src_ctrl` | 0x10060700 | rw | 64 |  |  | unknown | established |  |
| `ipi_access` | 0x10060c00 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `node_id` | 0x10060f00 | rw | 64 |  |  | unknown | established |  |
| `int_cmp` | 0x101b0080 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `scratch1` | 0x101d0080 | rw | 64 |  |  | unknown | established |  |
| `scratch1_alias` | 0x101d0088 | w | 64 |  |  | unknown | established |  |
| `scratch2` | 0x101d0100 | rw | 64 |  |  | unknown | established |  |
| `scratch3` | 0x101d0180 | w | 64 |  |  | unknown | established |  |
| `scratch3_alias` | 0x101d0188 | r | 64 |  |  | unknown | established |  |
| `scratch4` | 0x101d0200 | w | 64 |  |  | unknown | established |  |
| `scratch4_alias` | 0x101d0208 | r | 64 |  |  | unknown | established |  |
| `scratch5` | 0x101d0280 | rw | 64 |  |  | unknown | established |  |
| `scratch6` | 0x101d0300 | rw | 64 |  |  | unknown | established |  |
| `scratch7` | 0x101d0380 | rw | 64 |  |  | unknown | established |  |
| `scratch24` | 0x101d0c00 | rw | 64 |  |  | unknown | established |  |
| `fsb_symmetric_agent_status` | 0x20020010 | r | 64 |  |  | unknown | established |  |
| `pio_write_status` | 0x20070200 | r | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `pio_write_status_alias` | 0x20070208 | w | 64 | 4 |  | unknown | inferred | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `address_mode` | 0x20110000 | r | 64 |  |  | unknown | established |  |
| `firmware_remap` | 0x20110008 | w | 64 |  |  | unknown | established |  |
| `processor_type` | 0x20110010 | r | 64 |  |  | unknown | established |  |
| `bt_eng_csr` | 0x30040000 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `bt_eng_src` | 0x30040080 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `bt_eng_dest` | 0x30040100 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `bt_eng_notify` | 0x30040180 | rw | 64 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `xn_iilb_pi_cmp_exp_data0` | 0x50031240 | rw | 64 |  |  | unknown | established |  |
| `xn_iilb_ni0_cmp_exp_data0` | 0x50031280 | rw | 64 |  |  | unknown | established |  |
| `xn_iilb_ni0_cmp_exp_data1` | 0x50031290 | rw | 64 |  |  | unknown | established |  |
| `xn_iilb_ni1_cmp_exp_data0` | 0x500312c0 | rw | 64 |  |  | unknown | established |  |
| `xn_iilb_ni1_cmp_exp_data1` | 0x500312d0 | rw | 64 |  |  | unknown | established |  |
| `xn_md_ni1_cmp_exp_data1` | 0x50031590 | rw | 64 |  |  | unknown | established |  |
| `xn_md_ni1_cmp_enable1` | 0x500315b0 | rw | 64 |  |  | unknown | established |  |
| `xn_md_sic_cmp_exp_hdr0` | 0x500315c0 | rw | 64 |  |  | unknown | established |  |
| `xn_md_sic_cmp_exp_hdr1` | 0x500315d0 | rw | 64 |  |  | unknown | established |  |
| `xn_md_sic_cmp_hdr_enable0` | 0x500315e0 | rw | 64 |  |  | unknown | established |  |
| `xn_md_sic_cmp_hdr_enable1` | 0x500315f0 | rw | 64 |  |  | unknown | established |  |
| `xn_ni0_iilb_cmp_exp_data0` | 0x50031700 | rw | 64 |  |  | unknown | established |  |
| `xn_ni0_iilb_cmp_exp_data1` | 0x50031710 | rw | 64 |  |  | unknown | established |  |
| `xn_ni0_llp_cmp_exp_data0` | 0x50031800 | rw | 64 |  |  | unknown | established |  |
| `xn_ni0_llp_cmp_exp_data1` | 0x50031810 | rw | 64 |  |  | unknown | established |  |
| `xn_ni0_md_cmp_exp_hdr0` | 0x50031b40 | rw | 64 |  |  | unknown | established |  |
| `xn_ni0_md_cmp_exp_hdr1` | 0x50031b50 | rw | 64 |  |  | unknown | established |  |
| `junk_bus_led` | 0xf0000000 | w | 16 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `ptc` | 0x170000000 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |
| `rtc` | 0x2101c0000 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |

### Register `x_dimm_cfg`

DIMM population word. One routine (0xff482c60) merges the discovered DIMM layout into the old value: the preserved bits are 38 and above and bits 7, 15, 23 and 31, so bits 37:32 are rewritten, and the same value is written to all three registers (X, Y and JNR); bits 37:36 are then set by 0xff4856b0, which reads the Y register first. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37:36 | `clk_en` | inferred |  |  | Two clock-enable bits the firmware sets together after the initial write cleared them. |
| 35:32 | `freq` | inferred |  |  | Memory clock code, 4 bits. |
| 30:29 | `dimm3_cs` | inferred |  |  | DIMM 3 chip-select code, 2 bits. |
| 28 | `dimm3_rev` | inferred |  |  | DIMM 3 revision flag. |
| 27 | `dimm3_2bk` | inferred |  |  | DIMM 3 bank-count flag. |
| 26:24 | `dimm3_size` | inferred |  |  | DIMM 3 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 22:21 | `dimm2_cs` | inferred |  |  | DIMM 2 chip-select code, 2 bits. |
| 20 | `dimm2_rev` | inferred |  |  | DIMM 2 revision flag. |
| 19 | `dimm2_2bk` | inferred |  |  | DIMM 2 bank-count flag. |
| 18:16 | `dimm2_size` | inferred |  |  | DIMM 2 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 14:13 | `dimm1_cs` | inferred |  |  | DIMM 1 chip-select code, 2 bits. |
| 12 | `dimm1_rev` | inferred |  |  | DIMM 1 revision flag. |
| 11 | `dimm1_2bk` | inferred |  |  | DIMM 1 bank-count flag. |
| 10:8 | `dimm1_size` | inferred |  |  | DIMM 1 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 6:5 | `dimm0_cs` | inferred |  |  | DIMM 0 chip-select code, 2 bits. |
| 4 | `dimm0_rev` | inferred |  |  | DIMM 0 revision flag. |
| 3 | `dimm0_2bk` | inferred |  |  | DIMM 0 bank-count flag. |
| 2:0 | `dimm0_size` | inferred |  |  | DIMM 0 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |

### Register `y_dimm_cfg`

Same layout and value as X_DIMM_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37:36 | `clk_en` | inferred |  |  | Two clock-enable bits the firmware sets together after the initial write cleared them. |
| 35:32 | `freq` | inferred |  |  | Memory clock code, 4 bits. |
| 30:29 | `dimm3_cs` | inferred |  |  | DIMM 3 chip-select code, 2 bits. |
| 28 | `dimm3_rev` | inferred |  |  | DIMM 3 revision flag. |
| 27 | `dimm3_2bk` | inferred |  |  | DIMM 3 bank-count flag. |
| 26:24 | `dimm3_size` | inferred |  |  | DIMM 3 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 22:21 | `dimm2_cs` | inferred |  |  | DIMM 2 chip-select code, 2 bits. |
| 20 | `dimm2_rev` | inferred |  |  | DIMM 2 revision flag. |
| 19 | `dimm2_2bk` | inferred |  |  | DIMM 2 bank-count flag. |
| 18:16 | `dimm2_size` | inferred |  |  | DIMM 2 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 14:13 | `dimm1_cs` | inferred |  |  | DIMM 1 chip-select code, 2 bits. |
| 12 | `dimm1_rev` | inferred |  |  | DIMM 1 revision flag. |
| 11 | `dimm1_2bk` | inferred |  |  | DIMM 1 bank-count flag. |
| 10:8 | `dimm1_size` | inferred |  |  | DIMM 1 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 6:5 | `dimm0_cs` | inferred |  |  | DIMM 0 chip-select code, 2 bits. |
| 4 | `dimm0_rev` | inferred |  |  | DIMM 0 revision flag. |
| 3 | `dimm0_2bk` | inferred |  |  | DIMM 0 bank-count flag. |
| 2:0 | `dimm0_size` | inferred |  |  | DIMM 0 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |

### Register `jnr_dimm_cfg`

Same layout and value as X_DIMM_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 37:36 | `clk_en` | inferred |  |  | Two clock-enable bits the firmware sets together after the initial write cleared them. |
| 35:32 | `freq` | inferred |  |  | Memory clock code, 4 bits. |
| 30:29 | `dimm3_cs` | inferred |  |  | DIMM 3 chip-select code, 2 bits. |
| 28 | `dimm3_rev` | inferred |  |  | DIMM 3 revision flag. |
| 27 | `dimm3_2bk` | inferred |  |  | DIMM 3 bank-count flag. |
| 26:24 | `dimm3_size` | inferred |  |  | DIMM 3 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 22:21 | `dimm2_cs` | inferred |  |  | DIMM 2 chip-select code, 2 bits. |
| 20 | `dimm2_rev` | inferred |  |  | DIMM 2 revision flag. |
| 19 | `dimm2_2bk` | inferred |  |  | DIMM 2 bank-count flag. |
| 18:16 | `dimm2_size` | inferred |  |  | DIMM 2 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 14:13 | `dimm1_cs` | inferred |  |  | DIMM 1 chip-select code, 2 bits. |
| 12 | `dimm1_rev` | inferred |  |  | DIMM 1 revision flag. |
| 11 | `dimm1_2bk` | inferred |  |  | DIMM 1 bank-count flag. |
| 10:8 | `dimm1_size` | inferred |  |  | DIMM 1 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |
| 6:5 | `dimm0_cs` | inferred |  |  | DIMM 0 chip-select code, 2 bits. |
| 4 | `dimm0_rev` | inferred |  |  | DIMM 0 revision flag. |
| 3 | `dimm0_2bk` | inferred |  |  | DIMM 0 bank-count flag. |
| 2:0 | `dimm0_size` | inferred |  |  | DIMM 0 size code, 3 bits (the firmware tests 7 in the size fields, so 7 is probably an empty slot; inferred). |

### Register `x_odt_cfg`

On-die-termination configuration. Only the one field below is written by the memory bring-up read; it is copied from the Y register. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:20 | `bits_23_20` | inferred |  |  | Four bits the firmware sets to 0xf when only DIMM 0 of the three is populated (DIMM 0 size not 7, DIMMs 1 to 3 size 7); the other bits are preserved. Name unknown. |

### Register `x_cfg`

Memory controller timing word. The firmware writes the same value to X and Y: 0x4856_5320_3324_110e, built from the old Y value by clearing bit 0, setting bit 1, depositing 3 at bits 7:2, replacing bits 39:8, depositing 3, 5, 6 at bits 43:40, 47:44, 51:48, setting bits 52 and 54, clearing bit 53 (set instead when the DIMM record's word at offset 8 equals 4), depositing 0x10 at bit 55 (width 7) and setting bit 62 (sites 0xff483016 to 0xff4831a0). Only bits 39:8 have a name here; the other positions are as written. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 39:8 | `ta_dlys` | inferred |  |  | Timing delays: the firmware replaces the whole field with 0x2033241; the name is the PROM's. |
| 0 | `bit_0` | inferred |  |  | Replaced by a one-bit argument in a separate routine that rewrites both registers; the PROM name for bit 0 is a serial-mode flag. |

### Register `x_dqct_cfg`

Read and write select delays. The firmware keeps bits 63:25 and sets bits 24:0 to 0x254215 (fields below). Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24:20 | `bits_24_20` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 19:16 | `bits_19_16` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 15:12 | `bits_15_12` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 11:8 | `bits_11_8` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 7:4 | `bits_7_4` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 3:0 | `bits_3_0` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |

### Register `x_refresh_control`

Refresh control. The firmware reads the Y register, replaces bits 27:8 (and clears bits 27:24 at site 0xff485d0c), merges the enable byte and writes the result to both registers. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:17 | `hold` | inferred |  |  | Six-bit hold count from the DIMM data. |
| 16:8 | `interval` | inferred |  |  | Refresh interval, 9 bits, from the DIMM data. |
| 7:0 | `enable` | inferred |  |  | Enable bits; the firmware sets the field from a mask it builds. |

### Register `y_odt_cfg`

Same layout as X_ODT_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:20 | `bits_23_20` | inferred |  |  | Four bits the firmware sets to 0xf when only DIMM 0 of the three is populated (DIMM 0 size not 7, DIMMs 1 to 3 size 7); the other bits are preserved. Name unknown. |

### Register `y_cfg`

Same layout as X_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 39:8 | `ta_dlys` | inferred |  |  | Timing delays: the firmware replaces the whole field with 0x2033241; the name is the PROM's. |
| 0 | `bit_0` | inferred |  |  | Replaced by a one-bit argument in a separate routine that rewrites both registers; the PROM name for bit 0 is a serial-mode flag. |

### Register `y_dqct_cfg`

Same layout and value as X_DQCT_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24:20 | `bits_24_20` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 19:16 | `bits_19_16` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 15:12 | `bits_15_12` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 11:8 | `bits_11_8` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 7:4 | `bits_7_4` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |
| 3:0 | `bits_3_0` | inferred |  |  | Delay or select field; written 5, 1, 2, 4, 5, 2 in this order from the low field up. Name unknown. |

### Register `y_refresh_control`

Same layout as X_REFRESH_CONTROL. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 22:17 | `hold` | inferred |  |  | Six-bit hold count from the DIMM data. |
| 16:8 | `interval` | inferred |  |  | Refresh interval, 9 bits, from the DIMM data. |
| 7:0 | `enable` | inferred |  |  | Enable bits; the firmware sets the field from a mask it builds. |

### Register `mem_red_black`

Written once with 0x4e20_0400. The PROM name suggests two time fields (bits 15:0 and 51:16); the code does not split the value. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `misc_mem_cfg`

Miscellaneous memory controller word. The firmware writes 0x0fc4_0000_000c_4c4c once, then clears bit 58 when a masked size argument exceeds 0x3ff and bit 59 when it exceeds 0x1ff (routine 0xff481280, sites 0xff481696 and 0xff4816c6). Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59 | `bit_59` | inferred |  |  | Cleared by a size test. |
| 58 | `bit_58` | inferred |  |  | Cleared by a size test. |

### Register `pio_rq_crd_ctl`

PIO request credit control. The first-stage firmware writes 2; the node set-up table writes 0xf9_0000_0000 to register 0xd8, a different register. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `pi_md_rq_crd_ctl`

Credit depth register; the firmware writes 0xc. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `pi_md_rp_crd_ctl`

Credit depth register; the firmware writes 0x4. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `xn_md_rq_crd_ctl`

Credit depth register; the firmware writes 0xb. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `xn_md_rp_crd_ctl`

Credit depth register; the firmware writes 0x3. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `mmrbist_base`

Start address of a memory test block. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `mmrbist_ctl`

Memory test control: the early path writes 0x11_0000_0010 and polls bit 40 clear (for up to 2,000,000 microseconds). The other fields of the PROM name are not read in code here. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `in_progress` | inferred |  |  | Polled until clear after a command write. |

### Register `dir_config_dqlp`

Directory configuration. The firmware reads it and merges: bits 2:0 from the node count, clears bits 11 and 10 by size tests, sets bit 3 and bit 15. The DQRP twin, 0x5_0000, receives the same value. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `bit_15` | inferred |  |  | Set by the firmware. |
| 11 | `bit_11` | inferred |  |  | Cleared by a size test. |
| 10 | `bit_10` | inferred |  |  | Cleared by a size test. |
| 3 | `bit_3` | inferred |  |  | Set by the firmware. |
| 2:0 | `sys_size` | inferred |  |  | System size class derived from a 16-bit count the routine extracts from bits 16:1 of its argument. |

### Register `dir_locvec_dqlp`

Eight local-vector registers 0x10 apart, all set to ones at initialisation. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

Array of 8 registers, stride 16.

### Register `dir_privec_dqlp`

Eight registers 0x10 apart written with constants in order: 0x4bfff, 0xc96f25b, 0xfffffff, 0x96ffff, 0, 0, 0x4803f, 0x48000. Not all ones, so the writes do not simply open access to every node; the field layout is not read. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

Array of 8 registers, stride 16.

### Register `dir_timer_dqlp`

Written once with 0x1000 (bit 12). Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `amo_cfg_0`

AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:2 | `bits_3_2` | inferred |  |  | Set by the firmware; the PROM name suggests the two little-endian enables. |

### Register `x_bist_h`

Memory test pattern register, high half; written with the arm bit. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 43 | `arm` | inferred |  |  | Set on the high registers to start that port. |
| 41 | `bit_41` | inferred |  |  | One byte of the test description, in bit 41. |
| 40 | `bit_40` | inferred |  |  | One byte of the test description, in bit 40. |
| 39:0 | `pattern` | inferred |  |  | Test data pattern from the test description. |

### Register `x_bist_l`

Memory test pattern register, low half; same value without the arm bit. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41 | `bit_41` | inferred |  |  | One byte of the test description, in bit 41. |
| 40 | `bit_40` | inferred |  |  | One byte of the test description, in bit 40. |
| 39:0 | `pattern` | inferred |  |  | Test data pattern from the test description. |

### Register `x_bist_err_h`

Memory test error register, high half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `val` | inferred |  |  | Set when the port recorded an error; the firmware reads the pattern only then. |
| 39:0 | `pat` | inferred |  |  | Pattern bits the port saw; 40 bits. |

### Register `x_bist_err_l`

Memory test error register, low half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `val` | inferred |  |  | Set when the port recorded an error; the firmware reads the pattern only then. |
| 39:0 | `pat` | inferred |  |  | Pattern bits the port saw; 40 bits. |

### Register `y_bist_h`

Y-side twin of X_BIST_H. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 43 | `arm` | inferred |  |  | Set on the high registers to start that port. |
| 41 | `bit_41` | inferred |  |  | One byte of the test description, in bit 41. |
| 40 | `bit_40` | inferred |  |  | One byte of the test description, in bit 40. |
| 39:0 | `pattern` | inferred |  |  | Test data pattern from the test description. |

### Register `y_bist_l`

Y-side twin of X_BIST_L. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41 | `bit_41` | inferred |  |  | One byte of the test description, in bit 41. |
| 40 | `bit_40` | inferred |  |  | One byte of the test description, in bit 40. |
| 39:0 | `pattern` | inferred |  |  | Test data pattern from the test description. |

### Register `y_bist_err_h`

Memory test error register, high half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `val` | inferred |  |  | Set when the port recorded an error; the firmware reads the pattern only then. |
| 39:0 | `pat` | inferred |  |  | Pattern bits the port saw; 40 bits. |

### Register `y_bist_err_l`

Memory test error register, low half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value. Four ports 0x1_0000 apart (offsets 0x3_8xxx, 0x4_8xxx, 0x5_8xxx, 0x6_8xxx).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `val` | inferred |  |  | Set when the port recorded an error; the firmware reads the pattern only then. |
| 39:0 | `pat` | inferred |  |  | Pattern bits the port saw; 40 bits. |

### Register `amo_cfg_1`

AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:2 | `bits_3_2` | inferred |  |  | Set by the firmware; the PROM name suggests the two little-endian enables. |

### Register `dir_config_dqrp`

Twin of DIR_CONFIG_DQLP; the firmware writes the same value. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `dir_locvec_dqrp`

Eight registers 0x10 apart, all set to ones. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

Array of 8 registers, stride 16.

### Register `dir_privec_dqrp`

Twin of DIR_PRIVEC_DQLP, same values. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

Array of 8 registers, stride 16.

### Register `dir_timer_dqrp`

Twin of DIR_TIMER_DQLP. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

### Register `amo_cfg_2`

AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:2 | `bits_3_2` | inferred |  |  | Set by the firmware; the PROM name suggests the two little-endian enables. |

### Register `amo_cfg_3`

AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:2 | `bits_3_2` | inferred |  |  | Set by the firmware; the PROM name suggests the two little-endian enables. |

### Register `ipi_int`

Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR window with send set, the target's physical processor id, a delivery type, a vector and a fixed base. The kernel stores through uncached physical mode with release ordering, after a memory barrier. On a SHub 1 revision 2 or lower it holds a global lock around the store and waits for the PIO write status to drain.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `send` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Sending the message; the header says it generates a pulse. |
| 59:52 | `idx` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Interrupt vector delivered to the target processor. |
| 49:21 | `base` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Optional interrupt vector area, 2 MiB aligned. The kernel always puts 0xfee here. |
| 19:4 | `pid` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Processor id, the same value the target processor's SAPIC id holds. |
| 3 | `agent` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Must be zero for SHub. |
| 2:0 | `type` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Interrupt type: 0 interrupt, 2 platform management interrupt, 4 NMI, 5 INIT. |

### Register `rtc_int_config`

Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and processor id fields and leaves type, agent and base zero. The register has the same layout as the IPI message, without the send bit. A fourth comparator (RTC 0) exists; the driver comment says firmware uses it, and the header defines nothing for it.

Array of 3 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:52 | `idx` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |
| 49:21 | `base` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |
| 19:4 | `pid` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |
| 3 | `agent` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |
| 2:0 | `type` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |

### Register `rtc_int_enable`

Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes the configuration, enables, and only then writes the real expiry, in that order.

Array of 3 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |

### Register `event_occurred`

Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them; Linux only reads it. Bits the header names are established. SAL 5.04 reads it for the error bits (mask 0x7ef, sites 0xffa239a0 and 0xffa23fd6) and for bit 21 (site 0xffa31506), and writes bits 5 and 8 to this register itself (sites 0xffa32816 and 0xffa32996); a model should OR written bits in (inferred). Zero from reset is tolerated; the reset value is unknown. Bit 21 must read 0 for the PROM's INIT handling. See interrupts.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `ii_int1` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Pending I/O interface interrupt 1. |
| 29 | `ii_int0` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Pending I/O interface interrupt 0. |
| 28 | `ipi_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Pending IPI interrupt. |
| 26 | `rtc3_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Pending RTC comparator 3 interrupt. |
| 25 | `rtc2_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Pending RTC comparator 2 interrupt. |
| 24 | `rtc1_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Pending RTC comparator 1 interrupt. |
| 23 | `rtc0_int` | inferred |  | SAL 5.04 PROM site 0xffa31d96 (alias write 0x800000 right after RTC0's enable is cleared) | Pending RTC comparator 0 interrupt, from the sequence and from Linux numbering comparators 1 to 3 as bits 24 to 26. Name is ours. |
| 21 | `bit21` | inferred |  | SAL 5.04 PROM site 0xffa31506 (read), 0xffa31566 (clear through the alias, 0x200000) | Read by the PROM's INIT handling before it forwards INIT to the other processors, cleared through the alias. Meaning unknown; name is ours. |
| 20 | `uart_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Pending junk-bus UART interrupt. |
| 8 | `bit8` | inferred |  | SAL 5.04 PROM site 0xffa32816 (write to the register), 0xffa23a20 (mask 0x7ef) | As bit 5. Name is ours. |
| 5 | `bit5` | inferred |  | SAL 5.04 PROM site 0xffa32996 (write to the register), 0xffa23a20 (mask 0x7ef) | In the PROM's error mask 0x7ef; the PROM also writes this bit to the register itself in its express-path workaround. Name is ours. |
| 3 | `bit3` | inferred |  | SAL 5.04 PROM site 0xffa0bb16 and 0xffa0bb46 | The PROM writes 8 to the alias (and to the overflow alias) of another node when it clears a processor-interface error before a remote access. Role inferred; name is ours. |

### Register `event_occurred_alias`

Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.

### Register `junk_bus_time`

Junk-bus access timing, written once by the first-stage firmware with 0xffff_ffff_0003. Meaning of the value is inferred from the PROM name; the hardware accepts the store. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `junk_bus_led_data`

Four registers, one per slice, 0x80 apart, that the firmware reads only to remember the progress code it last wrote while it waits on a lock. Any value is accepted. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

Array of 4 registers, stride 128.

### Register `asic_to_l1_data`

L1 UART transmit data: eight packet bytes per write, padded with 0x7e after the frame. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `asic_to_l1_status`

L1 UART transmit status: bit 0 set means busy; the firmware polls it clear before each write, 10 microseconds apart, for up to 5,000,000 microseconds. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `busy` | inferred |  |  | Set while the previous word is still being sent. |

### Register `l1_to_asic_data`

L1 UART receive data: eight bytes per word, the first byte in bits 7:0. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `l1_to_asic_status`

L1 UART receive status: bit 0 set means a word is waiting; the firmware writes 0 to release it. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `data_ready` | inferred |  |  | A received word is waiting. |

### Register `rack_slot_data`

Rack and slot data provided by the L1 controller; the firmware reads it only on paths this page does not reach on a normal boot. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `byte` | inferred |  |  | Copied to an output word. |
| 15:4 | `number` | inferred |  |  | Value plus one is stored. |
| 3:1 | `code` | inferred |  |  | Index into the table 7, 10, 13, 20, 23, 30, 33, 36. |
| 0 | `bit0` | inferred |  |  | Copied to an output word. |

### Register `gc_src_ctrl`

Clock source control for the real-time clock. The PROM converts counter ticks to microseconds as counter * (max_count * 10 + 10) / 1000, so with max_count 4 the counter advances 20 ticks per microsecond. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:32 | `source_sel` | inferred |  |  | The firmware writes 1 at bit 32; the two-bit width comes from the PROM name table. |
| 13:4 | `max_count` | established |  |  | The firmware writes 4 and reads it back for every time conversion. |
| 0 | `enable_counter` | established |  |  | Set to start the counter. |

### Register `ipi_access`

Which processors may send interprocessor interrupts to this one: four registers, one per processor slice (SH2_IPI_ACCESS0 to 3). Defined by the header; the kernel files read never touch them, so the layout is unknown.

Array of 4 registers, stride 128.

### Register `node_id`

The node's identification word. Read by the firmware to find its own node number (bits 45:32) and the sharing parameters; written during the interconnect phase. Linux v5.3 does not define it for SHub 2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55 | `range_check` | established |  |  | Set by the firmware in the interconnect phase. |
| 54 | `sharers_1k` | established |  |  | Clear selects a sharing domain of 512 nodes, set 2048. |
| 53:48 | `nodes_per_bit` | established |  |  | Nodes per sharing-vector bit. |
| 47:46 | `sharing_mode` | established |  |  | Sharing mode, set from the node count. |
| 45:32 | `node_id` | established |  |  | This node's number. |
| 31:28 | `revision` | established |  |  | Chip revision, returned by a method of the node table and stored; no test of its value found. |

### Register `int_cmp`

Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).

Array of 3 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `compare` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |

### Register `scratch1`

Node election word: each slice writes slice + 1 through the alias and reads it back; the winner is the one that reads its own value. Plain storage satisfies the code. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch1_alias`

Write path onto the SCRATCH1 word; the relation is inferred from the use. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch2`

Firmware mailbox word for the L1 console link. Plain storage satisfies the code; the fields are how the 10.54 firmware uses it, names are ours. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `clear_bit` | inferred |  |  | Cleared once by the firmware's handshake; the send routine 0xff499650 tests it and only when it is set toggles bit 16 of 0x1000_0e00 around a transmit. |
| 62:58 | `rx_index` | inferred |  |  | Index of the next byte to take from the current 8-byte receive word; 7 after reset of the link. |
| 54:50 | `channel` | inferred |  |  | Index of the channel with a pending packet. |
| 49:42 | `sequence` | inferred |  |  | Receive sequence byte. |
| 41:39 | `state` | inferred |  |  | Mailbox state. |

### Register `scratch3`

Release side of the second firmware lock; the alias 0x08 above is the take side. Whether a read of the alias takes the lock in hardware is unknown; a plain pair that always reads 0 satisfies every access. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch3_alias`

Take side of the second firmware lock. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch4`

Release side of the node lock that guards SCRATCH6 and SCRATCH7. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch4_alias`

Take side of the node lock; a plain register that always reads 0 satisfies every access. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch5`

Claim bits of the second firmware lock: the firmware sets a bit to claim a resource (bit 0 for the barrier, bit 7 for the console link, bit 0xf for a packet exchange). Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch6`

Shared firmware word guarded by the node lock: slice present and arrival bits, the barrier flag and a per-slice-pair field. Plain storage; names of the fields are ours. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52:50 | `pair1_state` | inferred |  |  | Three-bit field for odd slices. |
| 49:47 | `pair0_state` | inferred |  |  | Three-bit field for even slices, set from a PAL-supplied value. |
| 34 | `barrier_busy` | inferred |  |  | Barrier in progress. |
| 33:30 | `slice_arrived` | inferred |  |  | Slice n has reached the barrier. |
| 29:26 | `slice_present` | inferred |  |  | Slice n has started. |
| 24:21 | `pal_flags` | inferred |  |  | Four bits assume slices 0 to 3; the code extracts a three-bit slice. Slice n's bit decides whether the PAL entry point is translated through RAM tables (bit set) or used unchanged. |

### Register `scratch7`

Second shared firmware word with the same lock cycle as SCRATCH6. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `scratch24`

Holds the address of the firmware's node-addressing table row (the low 32 bits of the row address with bit 63 set); every later node-number read loads the row through it. The firmware reads it back, so it must store all 64 bits. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `fsb_symmetric_agent_status`

Which processor slices of the node are present. The firmware tests bit 0 and bit 1 for slices 0 and 1 and wants two equal non-zero reads in a row. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `cpu_1_active` | inferred |  |  | Slice 1 present (meaning from the PROM name). |
| 0 | `cpu_0_active` | inferred |  |  | Slice 0 present (meaning from the PROM name). |

### Register `pio_write_status`

PIO write status, four instances (SHub 2 nodes carry up to four processor slices). Note the kernel indexes them out of order: slices 0, 1, 2, 3 use instances 0, 2, 1, 3, in the setup code's table. The idle value is zero, not all ones. The write_error, multi_write_error, write_error_address and writes_ok fields are the SHub 1 header's; the SHub 2 layout was not read.

Array of 4 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `writes_ok` | established |  | SGI Linux 2.4 ia64 SN2 header (Linux/MIPS tree, commit 8ef7d46c94d5) SH_PIO_WRITE_STATUS_0 | No pending writes or errors (header INIT 0x8000000000000000). The PROM tests neither this bit nor the count at the first poll. |
| 61:56 | `pending_write_count` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Count of PIO writes still in flight. On SHub 1 the kernel treats all ones as idle (see PIO_WRITE_STATUS_IDLE); the header gives no reason. |
| 49:3 | `write_error_address` | established |  | SGI Linux 2.4 ia64 SN2 header (Linux/MIPS tree, commit 8ef7d46c94d5) SH_PIO_WRITE_STATUS_0 | Address associated with the error response. The PROM does not read it. |
| 2 | `write_error` | established |  | SGI Linux 2.4 ia64 SN2 header (Linux/MIPS tree, commit 8ef7d46c94d5) SH_PIO_WRITE_STATUS_0 | An error response was detected for a PIO write. The PROM provokes it with a store to 0x1_1005_0608 and spins until this bit or multi_write_error is set. |
| 1 | `write_deadlock` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | A deadlock response was detected for a PIO write. |
| 0 | `multi_write_error` | established |  | SGI Linux 2.4 ia64 SN2 header (Linux/MIPS tree, commit 8ef7d46c94d5) SH_PIO_WRITE_STATUS_0 | More than one PIO write error occurred. The PROM self test accepts it in place of write_error. |

### Register `pio_write_status_alias`

Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.

Array of 4 registers, stride 128.

### Register `address_mode`

V, the node-addressing selector: the PROM reads it before forming any global or TIO address and uses it unmasked as an index into a five-entry table, so it must read 0 to 4 (devices/shub/shub2.md section 1 gives the shifts for each value). Real value unknown. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

### Register `firmware_remap`

Remote flash remap: the PROM writes the enable bit and a 9-bit field it takes from bits 32:24 of its argument. Meaning of the fields is inferred from the PROM name. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 60 | `enable` | established |  |  | Set by the PROM's write. |
| 32:24 | `offset` | established |  |  | Bits 32:24 of the remap argument; meaning inferred from the PROM name. |

### Register `processor_type`

The first-stage firmware reads it and compares the whole word with zero to choose which bit pair of the PAL argument becomes the slice number in cr.lid (zero: bits 2:1, else bits 3:2). Meaning of the bit is inferred from the PROM name. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `code` | inferred |  |  | Zero selects argument bits 2:1, non-zero bits 3:2. The code does not isolate bit 0; the position comes from the PROM name table. |

### Register `bt_eng_csr`

Block transfer engine control and status, one per engine, SHub 2 (four engines, SH2_BT_ENG_CSR_0 to 3). Unlike SHub 1 the kernel starts a transfer with one store here: busy, the mode shifted left by 24, and the length in cache lines in the low bits. The kernel reads it for busy and error; the engine's error code sits in bits 41:36 (kernel's BTE_ERR_BITS).

Array of 4 registers, stride 65536.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41:36 | `error_code` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Six-bit error code; non-zero means error. Bits: 1 short response, 2 long response, 4 (RESP_DSP), 8 access, 0x10 CRB timeout, 0x20 NACK limit (kernel BTEFAIL_SH2_* names). Whether the hardware also sets the error flag at bit 16 when this field is non-zero is unknown: the kernel's SHub 2 status decode ORs the flag in itself when the code is non-zero. |
| 28 | `notify` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | The kernel's notify mode bit is bit 4, so it lands at bit 28. The kernel always sets it. |
| 24 | `zero_fill` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | The kernel shifts its mode word left by 24; its zero-fill mode bit is bit 0, so it lands here. |
| 20 | `busy` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Busy: same position as SHub 1's status register in the kernel's macros. |
| 16 | `error` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Error flag: the kernel tests the same IBLS_ERROR bit position on both chips. |
| 15:0 | `length` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Length in cache lines, as in the SHub 1 status register. The kernel keeps one length width for both chips (BTE_LEN_MASK, 16 bits). |

### Register `bt_eng_src`

BTE source address, per engine. The kernel converts the physical address to the network address form first (nasid moved to bit 40 upward, the bank-select bits moved to bit 36).

Array of 4 registers, stride 65536.

### Register `bt_eng_dest`

BTE destination address, per engine; same conversion as the source.

Array of 4 registers, stride 65536.

### Register `bt_eng_notify`

BTE notification address, per engine; same conversion.

Array of 4 registers, stride 65536.

### Register `xn_iilb_pi_cmp_exp_data0`

Board type word. The PROM stores the board type here and then checks it (accepted values 0x7b, 0x200, 0xa00, 0xe00; any other prints "unknown board type" and returns, after the store) and eight later sites call the 64-bit read helper on it (one ninth site was not classified); one of them is a predicate that returns whether it equals 0xe00. Nothing zeroes it before the store. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_iilb_ni0_cmp_exp_data0`

Firmware scratch word, slot 3 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_iilb_ni0_cmp_exp_data1`

Firmware scratch word, slot 3 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_iilb_ni1_cmp_exp_data0`

Firmware scratch word, slot 2 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_iilb_ni1_cmp_exp_data1`

Firmware scratch word, slot 2 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_md_ni1_cmp_exp_data1`

Per-slice word 2 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table). One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the node set-up write list does not zero them. What the word holds is unknown beyond the caller keeping bits 51:50 of the value read. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_md_ni1_cmp_enable1`

Per-slice word 3 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table). One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the node set-up write list does not zero them. What the word holds is unknown beyond the caller keeping bits 51:50 of the value read. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_md_sic_cmp_exp_hdr0`

Firmware scratch word, slot 0 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_md_sic_cmp_exp_hdr1`

Firmware scratch word, slot 0 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred). SHub 1's equivalent (SH_XN_MD_SIC_CMP_EXP_HDR1) implements bits 41:0 only; the SHub 2 width is not known and a model should keep 64 bits.

### Register `xn_md_sic_cmp_hdr_enable0`

Per-slice word 0 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table). One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the node set-up write list does not zero them. What the word holds is unknown beyond the caller keeping bits 51:50 of the value read. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_md_sic_cmp_hdr_enable1`

Per-slice word 1 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table). One routine (0xff414ca0) stores the constant 0xff_0000_0000 to all four; the node set-up write list does not zero them. What the word holds is unknown beyond the caller keeping bits 51:50 of the value read. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred). SHub 1's equivalent (SH_XN_MD_SIC_CMP_HDR_ENABLE1) implements bits 41:0 only; the SHub 2 width is not known and a model should keep 64 bits.

### Register `xn_ni0_iilb_cmp_exp_data0`

Firmware scratch word, slot 0 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_ni0_iilb_cmp_exp_data1`

Firmware scratch word, slot 1 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_ni0_llp_cmp_exp_data0`

Firmware scratch word, slot 2 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_ni0_llp_cmp_exp_data1`

Firmware scratch word, slot 3 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_ni0_md_cmp_exp_hdr0`

Firmware scratch word, slot 1 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `xn_ni0_md_cmp_exp_hdr1`

Firmware scratch word, slot 1 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not traced. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. A node crossbar debug-compare register by name; the PROM uses it as 64-bit storage (inferred).

### Register `junk_bus_led`

Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.

Array of 4 registers, stride 65536.

### Register `ptc`

Purge translation cache message, SHub 2 (header SH2_PTC). One 64-bit store per target node replaces SHub 1's two. The region id and region number do not go in the data: the kernel adds them, shifted left by four, to the register's address. (The header's `SH2_PTC_ADDR_SHFT` is 4 but sits under a region-id comment and no kernel code uses it, which uses `SH2_PTC_RID_SHFT`; the data's address field is `SH2_PTC_ADDR_MASK`, which starts at bit 12, and that is what this file uses.) The data carries the type bit, the page size and the start bit, and the virtual address in bits 60:12. How wide the address-encoded part is, and so how large the register window is, is unknown. The kernel only waits on the PIO write status afterwards; on a deadlock it reads the status alias instead of clearing it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `start` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |
| 60:12 | `address` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Virtual address to purge (header SH2_PTC_ADDR_MASK 0x1ffffffffffff000). |
| 3:2 | `ps` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Page size as a power of two. The width is a guess from the next field starting at bit 4; the kernel passes a value that may need more bits, so the width is unknown. |
| 0 | `type_bit` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset | Header title: type; the kernel always writes 1. |

### Register `rtc`

Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only. The SHub 1 PROM (SAL 5.04) writes 0 to it at the SAL_B reset entry (0xffa94d20) and again to a node's counter in the interconnect phase, then reads it on every delay and timeout, so it must advance. Its tick period comes from rtc_ctl (SHub 1: 10 ns times the field plus one, 50 ns after the PROM's own write). See prom-reset.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `counter` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): name and offset |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `EVENT_OCCURRED_EXTIO_INT2` | 0x200000000 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): field mask | Bit 33 of the event register: pending SHub 2 external I/O interrupt 2 (header SH2_EVENT_OCCURRED_EXTIO_INT2). The base unit's field table has no entry for it because overlays cannot add fields. |
| `EVENT_OCCURRED_EXTIO_INT3` | 0x400000000 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): field mask | Bit 34 of the event register: pending SHub 2 external I/O interrupt 3. |
| `IPI_BASE_VALUE` | 0xfee | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | Constant the kernel puts in the base field of every IPI message: 0xfee in units of the field (2 MiB, from bit 21), which is 0x1_fdc0_0000 as an address (0xfee << 21; inferred arithmetic). It is not the 0xfee00000 of the kernel's generic interrupt base constant: that equivalence does not follow from the field position. Used with the vector in the idx field. |
| `PIO_WRITE_STATUS_ALIAS_CLEAR` | 0x7 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | Value the kernel's TLB-purge deadlock recovery writes to the alias on SHub 1 to clear the deadlock, write error and multiple write error bits (assembly comment). |
| `PIO_WRITE_STATUS_IDLE` | 0x0 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | What the kernel waits for the masked pending-write count to equal on SHub 2: zero. |
| `PI_CAM_WAR_VALUE` | 0x8000000000000010 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | Value the kernel writes to the PI CAM control register from every timer tick on a SHub 1 of revision 2 or lower. Meaning not stated by the sources. |
| `RTC_CONFIG_MASK` | 0xff3ffffffefffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | Valid bits of an RTC interrupt configuration register (header SH_RTC1_INT_CONFIG_MASK): bits 59:52 and 49:0 except bit 20. |
| `RTC_ENABLE_MASK` | 0x1 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | Valid bits of an RTC interrupt enable register. |
| `RTC_MASK` | 0x7fffffffffffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | Valid bits of the real-time clock and of each comparator: 55 bits. The mmtimer driver reports 55 as the clock width. |
| `SHUB_1_1_MAX_REVISION` | 0x2 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): kernel use | Revision field value at or below which the kernel enables its SHub 1.1 workarounds. |
