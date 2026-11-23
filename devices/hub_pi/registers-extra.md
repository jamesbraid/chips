<!-- generated from devices/hub_pi/registers-extra.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 6bd43d1a2beced09685294a1651d96ebd8187133f5b5a5408a19ea14d79ea62b -->

# Hub processor interface registers, bit layouts and constants outside the census

Unit `hub_pi_extra`, macro prefix `HUB`.
Default source: public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pi_cpu_protect` | 0x0 | rw | 64 |  |  | 0xffffffffffffffff (established) | established |  |
| `pi_prot_override` | 0x8 | w | 64 |  |  | unknown | established |  |
| `pi_io_protect` | 0x10 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_calias_size` | 0x28 | rw | 64 |  |  | 0xf (established) | established | census: 3 sites, 3 routines (rw); census: 2 sites, 2 routines (rw, indexed) |
| `pi_reply_level` | 0x60 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_nmi_b` | 0x78 | w | 64 |  |  | unknown | established |  |
| `pi_softreset` | 0x80 | w | 64 |  |  | unknown | established |  |
| `pi_int_pend_mod` | 0x90 | w | 64 |  |  | unknown | established | census: 9 sites, 8 routines (w); census: 8 sites, 8 routines (w, indexed) |
| `pi_cc_pend_set_a` | 0xc8 | w | 64 |  |  | unknown | established |  |
| `pi_cc_pend_set_b` | 0xd0 | w | 64 |  |  | unknown | established |  |
| `pi_cc_pend_clr_a` | 0xd8 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_cc_pend_clr_b` | 0xe0 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_cc_mask` | 0xe8 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_rt_local_ctrl` | 0x160 | rw | 64 |  |  | unknown | established | census: 6 sites, 1 routines |
| `pi_rt_filter_ctrl` | 0x168 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_bist_write_data` | 0x200 | w | 64 |  |  | unknown | established |  |
| `pi_bist_read_data` | 0x208 | r | 64 |  |  | 0x0 (established) | established |  |
| `pi_bist_count_targ` | 0x210 | w | 64 |  |  | unknown | established |  |
| `pi_bist_ready` | 0x218 | r | 64 |  |  | 0x0 (established) | established |  |
| `pi_bist_shift_load` | 0x220 | w | 64 |  |  | unknown | established |  |
| `pi_bist_shift_unload` | 0x228 | w | 64 |  |  | unknown | established |  |
| `pi_bist_enter_run` | 0x230 | w | 64 |  |  | unknown | established |  |
| `pi_gfx_page_a` | 0x300 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_gfx_credit_cntr_a` | 0x308 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_gfx_bias_a` | 0x310 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_gfx_int_cntr_a` | 0x318 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_gfx_page_b` | 0x328 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_gfx_credit_cntr_b` | 0x330 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_gfx_bias_b` | 0x338 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_gfx_int_cntr_b` | 0x340 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_err_int_pend` | 0x400 | rw | 64 |  |  | unknown | established | census: 13 sites, 5 routines (rw); census: 3 sites, 2 routines (rw, indexed) |
| `pi_err_int_mask_a` | 0x408 | rw | 64 |  |  | 0x0 (established) | established | census: 5 sites, 2 routines (rw); census: 1 sites, 1 routines (w, indexed) |
| `pi_err_int_mask_b` | 0x410 | rw | 64 |  |  | 0x0 (established) | established | census: 5 sites, 2 routines (rw); census: 1 sites, 1 routines (w, indexed) |
| `pi_err_status0_a` | 0x430 | r | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `pi_err_status0_a_rclr` | 0x438 | r | 64 |  |  | unknown | established |  |
| `pi_err_status1_a` | 0x440 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_err_status1_a_rclr` | 0x448 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_err_status0_b` | 0x450 | r | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `pi_err_status0_b_rclr` | 0x458 | r | 64 |  |  | unknown | established |  |
| `pi_err_status1_b` | 0x460 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_err_status1_b_rclr` | 0x468 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `pi_spool_cmp_a` | 0x470 | rw | 64 |  |  | unknown | established |  |
| `pi_spool_cmp_b` | 0x478 | rw | 64 |  |  | unknown | established |  |
| `pi_crb_timeout_a` | 0x480 | w | 64 |  |  | unknown | established |  |
| `pi_crb_timeout_b` | 0x488 | w | 64 |  |  | unknown | established |  |
| `pi_sysad_errchk_en` | 0x490 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_bad_check_bit_a` | 0x498 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_bad_check_bit_b` | 0x4a0 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_nack_cnt_a` | 0x4a8 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_nack_cnt_b` | 0x4b0 | rw | 64 |  |  | 0x0 (established) | established |  |
| `pi_nack_cmp` | 0x4b8 | rw | 64 |  |  | 0x0 (established) | established |  |

### Register `pi_cpu_protect`

CPU protection register, named PI_CPU_PROTECT in the header. The header gives no fields. The IRIX register table confirms the access.

### Register `pi_prot_override`

Protection override register, named PI_PROT_OVRRD in the header as the way to clear a CPU protection bit. The header gives neither an unlock value nor a behaviour, so none is imported. The IRIX register table confirms the access.

### Register `pi_io_protect`

Interrupt pending protection register, named PI_IO_PROTECT in the header. The header gives no fields. The IRIX register table confirms the access.

### Register `pi_calias_size`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `size` | inferred | pi_calias_size (size_none=0, size_4k=1, size_8k=2, size_16k=3, size_32k=4, size_64k=5, size_128k=6, size_256k=7, size_512k=8, size_1m=9, size_2m=10, size_4m=11, size_8m=12, size_16m=13, size_32m=14, size_64m=15) | public Linux SN0 Hub processor-interface header: field layout and masks | Cached alias size: 0 is none, then 4 KiB doubling to 64 MiB at 15. The header lists values 0 to 15 and gives no field extent; four bits is the width that holds them. |

### Register `pi_reply_level`

Reply level register, named PI_REPLY_LEVEL in the header. The header gives no fields. The IRIX register table confirms the access.

### Register `pi_nmi_b`

Non-maskable interrupt to processor B, named PI_NMI_B in the header and paired with the processor A register at the same stride. The IRIX register table confirms the access.

### Register `pi_softreset`

Soft reset, named PI_SOFTRESET in the header with the comment that it resets both processors. The header gives no value and no fields, so the data written is not imported. The IRIX register table confirms the access.

### Register `pi_int_pend_mod`

Layout of the interrupt pending modify register, pi_int_pend_mod, as Linux writes it: a set bit and an interrupt level. Linux only writes the register. Whether a second processor in a node reaches it at another offset is not established by a public source and is not recorded.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `set` | inferred |  |  | set the level (1) or clear it (0); the role is read from how Linux builds the word |
| 6:0 | `level` | inferred |  |  | interrupt level number; Linux ORs the level into the word unmasked. The 0 to 127 range is inferred from the width of the sibling Bedrock layout |

### Register `pi_cc_pend_set_a`

Cross-call interrupt pending set for processor A, named PI_CC_PEND_SET_A in the header. The IRIX register table confirms the access.

### Register `pi_cc_pend_set_b`

Cross-call interrupt pending set for processor B, named PI_CC_PEND_SET_B in the header. The header's pairing rule puts it eight bytes above the processor A set. The IRIX register table confirms the access.

### Register `pi_cc_pend_clr_a`

Cross-call interrupt pending clear for processor A, named PI_CC_PEND_CLR_A in the header. The IRIX register table confirms the access.

### Register `pi_cc_pend_clr_b`

Cross-call interrupt pending clear for processor B, named PI_CC_PEND_CLR_B in the header. The IRIX register table confirms the access.

### Register `pi_cc_mask`

Cross-call interrupt mask, named PI_CC_MASK in the header. The IRIX register table confirms the access.

### Register `pi_rt_local_ctrl`

Layout of the real-time counter local control register, the register the census names by its real-time clock control name. The header's mask and shift definitions give the fields below. The header gives no access type or reset value for it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `use_internal` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Use internal clock, bit 16, named PRLC_USE_INT in the header. The header gives no behaviour beyond the name. |
| 15 | `gclk` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Global clock flag, bit 15, named PRLC_GCLK in the header. The header gives no behaviour beyond the name. |
| 14:8 | `gclk_count` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Global clock count, seven bits at 14:8, named PRLC_GCLK_COUNT in the header. |
| 7:1 | `max_count` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Maximum count, seven bits at 7:1, named PRLC_MAX_COUNT in the header. The header gives no statement of what it sets. |
| 0 | `gclk_en` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Global clock enable, bit 0, named PRLC_GCLK_EN in the header. |

### Register `pi_rt_filter_ctrl`

Global clock filter control, named PI_RT_FILTER_CTRL in the header, which gives no fields. It sits next to the real-time clock control register. The IRIX register table confirms the access.

### Register `pi_bist_write_data`

Built-in self-test write data, named PI_BIST_WRITE_DATA in the header. The IRIX register table confirms the access.

### Register `pi_bist_read_data`

Built-in self-test read data, named PI_BIST_READ_DATA in the header. The IRIX register table confirms the access.

### Register `pi_bist_count_targ`

Built-in self-test count and target, named PI_BIST_COUNT_TARG in the header. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.

### Register `pi_bist_ready`

Built-in self-test ready indicator, named PI_BIST_READY in the header. The IRIX register table confirms the access.

### Register `pi_bist_shift_load`

Built-in self-test control, named PI_BIST_SHIFT_LOAD in the header. The IRIX register table confirms the access.

### Register `pi_bist_shift_unload`

Built-in self-test control, named PI_BIST_SHIFT_UNLOAD in the header. The IRIX register table confirms the access.

### Register `pi_bist_enter_run`

Built-in self-test control, named PI_BIST_ENTER_RUN in the header. The IRIX register table confirms the access.

### Register `pi_gfx_page_a`

Graphics page for processor A, named PI_GFX_PAGE_A in the header. The header names only the enable bit, which is in the fields below. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `enable` | established |  |  | Graphics page enable, bit 40. The header names it PI_GFX_PAGE_ENABLE for both processor pages. |

### Register `pi_gfx_credit_cntr_a`

Graphics credit counter for processor A, named PI_GFX_CREDIT_CNTR_A in the header. The header gives no field layout and no meaning beyond the name. The IRIX register table confirms the access.

### Register `pi_gfx_bias_a`

Graphics bias for processor A, named PI_GFX_BIAS_A in the header. The header gives no field layout. The IRIX register table confirms the access.

### Register `pi_gfx_int_cntr_a`

Graphics interrupt counter for processor A, named PI_GFX_INT_CNTR_A in the header. The header gives no field layout. The IRIX register table confirms the access.

### Register `pi_gfx_page_b`

Graphics page for processor B, named PI_GFX_PAGE_B in the header. The header's pairing rule puts it 0x28 above the processor A page. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `enable` | established |  |  | Graphics page enable, bit 40, the same bit as the processor A page. |

### Register `pi_gfx_credit_cntr_b`

Graphics credit counter for processor B, named PI_GFX_CREDIT_CNTR_B in the header. The IRIX register table confirms the access.

### Register `pi_gfx_bias_b`

Graphics bias for processor B, named PI_GFX_BIAS_B in the header. The IRIX register table confirms the access.

### Register `pi_gfx_int_cntr_b`

Graphics interrupt counter for processor B, named PI_GFX_INT_CNTR_B in the header. The IRIX register table confirms the access.

### Register `pi_err_int_pend`

Bit pairs are B then A (even bit B, odd bit A) for bits 0 to 23.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24 | `md_uncorr` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | PI_ERR_MD_UNCORR. The header's comment says it must be cleared in the memory/directory unit. |
| 23 | `sysstate_tag_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 23, named PI_ERR_SYSSTATE_TAG_A. |
| 22 | `sysstate_tag_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 22, named PI_ERR_SYSSTATE_TAG_B. |
| 21 | `uncac_uncorr_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 21, named PI_ERR_UNCAC_UNCORR_A. |
| 20 | `uncac_uncorr_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 20, named PI_ERR_UNCAC_UNCORR_B. |
| 19 | `bad_spool_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 19, named PI_ERR_BAD_SPOOL_A. |
| 18 | `bad_spool_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 18, named PI_ERR_BAD_SPOOL_B. |
| 17 | `syscmd_addr_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 17, named PI_ERR_SYSCMD_ADDR_A. |
| 16 | `syscmd_addr_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 16, named PI_ERR_SYSCMD_ADDR_B. |
| 15 | `syscmd_data_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 15, named PI_ERR_SYSCMD_DATA_A. |
| 14 | `syscmd_data_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 14, named PI_ERR_SYSCMD_DATA_B. |
| 13 | `sysad_addr_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 13, named PI_ERR_SYSAD_ADDR_A. |
| 12 | `sysad_addr_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 12, named PI_ERR_SYSAD_ADDR_B. |
| 11 | `sysad_data_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 11, named PI_ERR_SYSAD_DATA_A. |
| 10 | `sysad_data_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 10, named PI_ERR_SYSAD_DATA_B. |
| 9 | `sysstate_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 9, named PI_ERR_SYSSTATE_A. |
| 8 | `sysstate_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 8, named PI_ERR_SYSSTATE_B. |
| 7 | `wrb_werr_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 7, named PI_ERR_WRB_WERR_A. |
| 6 | `wrb_werr_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 6, named PI_ERR_WRB_WERR_B. |
| 5 | `wrb_terr_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 5, named PI_ERR_WRB_TERR_A. |
| 4 | `wrb_terr_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 4, named PI_ERR_WRB_TERR_B. |
| 3 | `spur_msg_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 3, named PI_ERR_SPUR_MSG_A. |
| 2 | `spur_msg_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 2, named PI_ERR_SPUR_MSG_B. |
| 1 | `spool_cmp_a` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 1, named PI_ERR_SPOOL_CMP_A. |
| 0 | `spool_cmp_b` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Bit 0, named PI_ERR_SPOOL_CMP_B. |

### Register `pi_err_int_mask_a`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24 | `md_uncorr` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 23 | `sysstate_tag_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 22 | `sysstate_tag_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 21 | `uncac_uncorr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 20 | `uncac_uncorr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 19 | `bad_spool_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 18 | `bad_spool_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 17 | `syscmd_addr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 16 | `syscmd_addr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 15 | `syscmd_data_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 14 | `syscmd_data_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 13 | `sysad_addr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 12 | `sysad_addr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 11 | `sysad_data_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 10 | `sysad_data_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 9 | `sysstate_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 8 | `sysstate_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 7 | `wrb_werr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 6 | `wrb_werr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 5 | `wrb_terr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 4 | `wrb_terr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 3 | `spur_msg_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 2 | `spur_msg_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 1 | `spool_cmp_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 0 | `spool_cmp_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |

### Register `pi_err_int_mask_b`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24 | `md_uncorr` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 23 | `sysstate_tag_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 22 | `sysstate_tag_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 21 | `uncac_uncorr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 20 | `uncac_uncorr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 19 | `bad_spool_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 18 | `bad_spool_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 17 | `syscmd_addr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 16 | `syscmd_addr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 15 | `syscmd_data_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 14 | `syscmd_data_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 13 | `sysad_addr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 12 | `sysad_addr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 11 | `sysad_data_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 10 | `sysad_data_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 9 | `sysstate_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 8 | `sysstate_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 7 | `wrb_werr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 6 | `wrb_werr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 5 | `wrb_terr_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 4 | `wrb_terr_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 3 | `spur_msg_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 2 | `spur_msg_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 1 | `spool_cmp_a` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |
| 0 | `spool_cmp_b` | inferred |  | public Linux SN0 Hub processor-interface header: field layout and masks | Mask bit paired with the same pending bit. The header gives no layout for the mask registers; this layout is inferred from the pending register. |

### Register `pi_err_status0_a`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Valid. |
| 62 | `overrun` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Overrun, spooled to memory. |
| 61:25 | `addr` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Address, 37 bits (PI_ERR_ST0_ADDR_MASK). |
| 24:17 | `cmd` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message command, eight bits. |
| 16:6 | `suppl` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message supplemental field, eleven bits. |
| 5:3 | `reqnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read request number (the structure calls it the T5 request number). |
| 2:0 | `type` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Error type. Read-request errors are 1 (PRERR), 2 (DERR), 3 (TERR); write-request errors are 0 (WERR), 1 (PWERR), 3 (TERR); which table applies depends on the status 1 read/write bit. |

### Register `pi_err_status0_a_rclr`

Clear-on-read alias of error status 0 for processor A, named PI_ERR_STATUS0_A_RCLR in the header. The header's comment says a read clears the register. The IRIX register table confirms the access. Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Valid. |
| 62 | `overrun` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Overrun, spooled to memory. |
| 61:25 | `addr` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Address, 37 bits (PI_ERR_ST0_ADDR_MASK). |
| 24:17 | `cmd` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message command, eight bits. |
| 16:6 | `suppl` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message supplemental field, eleven bits. |
| 5:3 | `reqnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read request number (the structure calls it the T5 request number). |
| 2:0 | `type` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Error type. Read-request errors are 1 (PRERR), 2 (DERR), 3 (TERR); write-request errors are 0 (WERR), 1 (PWERR), 3 (TERR); which table applies depends on the status 1 read/write bit. |

### Register `pi_err_status1_a`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `msgsrc` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message source, eleven bits. |
| 52:43 | `crbstat` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Status from the read or write buffer, ten bits. |
| 42 | `wrbrrb` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read or write CRB: 0 read, 1 write. |
| 41:39 | `crbnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB number, three bits: write 0 to 7 or read 0 to 4. |
| 38:29 | `invcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Signed invalidate counter (read request buffer), ten bits. |
| 28:21 | `toutcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB timeout counter, eight bits. |
| 20:0 | `spool` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Number spooled to memory, 21 bits. |

### Register `pi_err_status1_a_rclr`

Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `msgsrc` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message source, eleven bits. |
| 52:43 | `crbstat` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Status from the read or write buffer, ten bits. |
| 42 | `wrbrrb` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read or write CRB: 0 read, 1 write. |
| 41:39 | `crbnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB number, three bits: write 0 to 7 or read 0 to 4. |
| 38:29 | `invcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Signed invalidate counter (read request buffer), ten bits. |
| 28:21 | `toutcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB timeout counter, eight bits. |
| 20:0 | `spool` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Number spooled to memory, 21 bits. |

### Register `pi_err_status0_b`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Valid. |
| 62 | `overrun` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Overrun, spooled to memory. |
| 61:25 | `addr` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Address, 37 bits (PI_ERR_ST0_ADDR_MASK). |
| 24:17 | `cmd` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message command, eight bits. |
| 16:6 | `suppl` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message supplemental field, eleven bits. |
| 5:3 | `reqnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read request number (the structure calls it the T5 request number). |
| 2:0 | `type` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Error type. Read-request errors are 1 (PRERR), 2 (DERR), 3 (TERR); write-request errors are 0 (WERR), 1 (PWERR), 3 (TERR); which table applies depends on the status 1 read/write bit. |

### Register `pi_err_status0_b_rclr`

Clear-on-read alias of error status 0 for processor B, named PI_ERR_STATUS0_B_RCLR in the header. The header's comment says a read clears the register. The IRIX register table confirms the access. Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Valid. |
| 62 | `overrun` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Overrun, spooled to memory. |
| 61:25 | `addr` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Address, 37 bits (PI_ERR_ST0_ADDR_MASK). |
| 24:17 | `cmd` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message command, eight bits. |
| 16:6 | `suppl` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message supplemental field, eleven bits. |
| 5:3 | `reqnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read request number (the structure calls it the T5 request number). |
| 2:0 | `type` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Error type. Read-request errors are 1 (PRERR), 2 (DERR), 3 (TERR); write-request errors are 0 (WERR), 1 (PWERR), 3 (TERR); which table applies depends on the status 1 read/write bit. |

### Register `pi_err_status1_b`

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `msgsrc` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message source, eleven bits. |
| 52:43 | `crbstat` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Status from the read or write buffer, ten bits. |
| 42 | `wrbrrb` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read or write CRB: 0 read, 1 write. |
| 41:39 | `crbnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB number, three bits: write 0 to 7 or read 0 to 4. |
| 38:29 | `invcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Signed invalidate counter (read request buffer), ten bits. |
| 28:21 | `toutcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB timeout counter, eight bits. |
| 20:0 | `spool` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Number spooled to memory, 21 bits. |

### Register `pi_err_status1_b_rclr`

Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `msgsrc` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Message source, eleven bits. |
| 52:43 | `crbstat` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Status from the read or write buffer, ten bits. |
| 42 | `wrbrrb` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Read or write CRB: 0 read, 1 write. |
| 41:39 | `crbnum` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB number, three bits: write 0 to 7 or read 0 to 4. |
| 38:29 | `invcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Signed invalidate counter (read request buffer), ten bits. |
| 28:21 | `toutcnt` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | CRB timeout counter, eight bits. |
| 20:0 | `spool` | established |  | public Linux SN0 Hub processor-interface header: field layout and masks | Number spooled to memory, 21 bits. |

### Register `pi_spool_cmp_a`

Error spool compare for processor A, named PI_SPOOL_CMP_A in the header. The header gives no field layout. The IRIX register table confirms the access.

### Register `pi_spool_cmp_b`

Error spool compare for processor B, named PI_SPOOL_CMP_B in the header. The IRIX register table confirms the access.

### Register `pi_crb_timeout_a`

Timed-out CRB entries for processor A, named PI_CRB_TIMEOUT_A in the header. The header gives no field layout. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.

### Register `pi_crb_timeout_b`

Timed-out CRB entries for processor B, named PI_CRB_TIMEOUT_B in the header. The IRIX register table gives write-only access; the earlier reading of the Linux header assumed read and write.

### Register `pi_sysad_errchk_en`

Enables for the processor bus checks, named PI_SYSAD_ERRCHK_EN in the header. Six enable bits, each named in the header's constants. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `qual` | established |  |  | Check the data-quality signal, named PI_SYSAD_ERRCHK_QUAL in the header. |
| 4 | `state` | established |  |  | Check SysState parity, named PI_SYSAD_ERRCHK_STATE in the header. |
| 3 | `cmdp` | established |  |  | Check SysCmd parity, named PI_SYSAD_ERRCHK_CMDP in the header. |
| 2 | `sadp` | established |  |  | Check SysAD parity, named PI_SYSAD_ERRCHK_SADP in the header. |
| 1 | `qualgen` | established |  |  | Generate the data-quality signal, named PI_SYSAD_ERRCHK_QUALGEN in the header. |
| 0 | `eccgen` | established |  |  | Generate error-correction bits, named PI_SYSAD_ERRCHK_ECCGEN in the header. |

### Register `pi_bad_check_bit_a`

Forced SysAD check-bit error for processor A, named PI_BAD_CHECK_BIT_A in the header and described there as diagnostic. The header gives no field layout. The IRIX register table confirms the access.

### Register `pi_bad_check_bit_b`

Forced SysAD check-bit error for processor B, named PI_BAD_CHECK_BIT_B in the header. The IRIX register table confirms the access.

### Register `pi_nack_cnt_a`

Consecutive negative-acknowledge counter for processor A, named PI_NACK_CNT_A in the header. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `enable` | established |  |  | Count enable, bit 20, named PI_NACK_CNT_EN in the header. |
| 19:0 | `count` | established |  |  | Negative-acknowledge count, bits 19:0, named PI_NACK_CNT_MASK in the header. |

### Register `pi_nack_cnt_b`

Consecutive negative-acknowledge counter for processor B, named PI_NACK_CNT_B in the header. The IRIX register table confirms the access.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `enable` | established |  |  | Count enable, bit 20, the same bit as the processor A counter. |
| 19:0 | `count` | established |  |  | Negative-acknowledge count, bits 19:0. |

### Register `pi_nack_cmp`

Negative-acknowledge compare, named PI_NACK_CMP in the header. The header gives a maximum of 0x0fffff for the count, so the compare is twenty bits wide. The IRIX register table confirms the access.

## Enums

### Enum `pi_calias_size`

| Label | Value | Grade | Source |
|---|---|---|---|
| `size_none` | 0 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_4k` | 1 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_8k` | 2 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_16k` | 3 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_32k` | 4 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_64k` | 5 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_128k` | 6 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_256k` | 7 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_512k` | 8 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_1m` | 9 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_2m` | 10 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_4m` | 11 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_8m` | 12 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_16m` | 13 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_32m` | 14 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `size_64m` | 15 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `IP_ERROR` | 0x4000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for Hub errors, named HUB_IP_ERROR in the header: IP6 line. |
| `IP_MASK` | 0x7c00 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | All five Hub-driven Cause bits together, named HUB_IP_MASK in the header. |
| `IP_PEND0` | 0x400 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the first pending bank, named HUB_IP_PEND0 in the header: IP2 line. |
| `IP_PEND1_CC` | 0x800 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the second pending bank and the cross-call sources, named HUB_IP_PEND1_CC in the header: IP3 line. |
| `IP_PROF` | 0x2000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the profiling comparator, named HUB_IP_PROF in the header: IP5 line. |
| `IP_RT` | 0x1000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the real-time counter comparator, named HUB_IP_RT in the header: IP4 line. |
| `PI_BASE` | 0x0 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Start of the processor interface registers, from the header. |
| `PI_CALIAS_SIZE_0` | 0x0 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 0: no alias, per the header's name PI_CALIAS_SIZE_0. |
| `PI_CALIAS_SIZE_128K` | 0x6 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 6: 128 KB, per the header. |
| `PI_CALIAS_SIZE_16K` | 0x3 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 3: 16 KB, per the header. |
| `PI_CALIAS_SIZE_16M` | 0xd | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 13: 16 MB, per the header. |
| `PI_CALIAS_SIZE_1M` | 0x9 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 9: 1 MB, per the header. |
| `PI_CALIAS_SIZE_256K` | 0x7 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 7: 256 KB, per the header. |
| `PI_CALIAS_SIZE_2M` | 0xa | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 10: 2 MB, per the header. |
| `PI_CALIAS_SIZE_32K` | 0x4 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 4: 32 KB, per the header. |
| `PI_CALIAS_SIZE_32M` | 0xe | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 14: 32 MB, per the header. |
| `PI_CALIAS_SIZE_4K` | 0x1 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 1: 4 KB, per the header. |
| `PI_CALIAS_SIZE_4M` | 0xb | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 11: 4 MB, per the header. |
| `PI_CALIAS_SIZE_512K` | 0x8 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 8: 512 KB, per the header. |
| `PI_CALIAS_SIZE_64K` | 0x5 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 5: 64 KB, per the header. |
| `PI_CALIAS_SIZE_64M` | 0xf | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 15: 64 MB, per the header. |
| `PI_CALIAS_SIZE_8K` | 0x2 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 2: 8 KB, per the header. |
| `PI_CALIAS_SIZE_8M` | 0xc | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cached-alias size code 12: 8 MB, per the header. |
| `PI_ERR_CLEAR_ALL_A` | 0xaaaaaa | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | The header's clear-all mask for processor A's error pending bits. |
| `PI_ERR_CLEAR_ALL_B` | 0x555555 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | The header's clear-all mask for processor B's error pending bits. |
| `PI_ERR_RD_DERR` | 0x2 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Error type 2 in the error status of a read request: data error. |
| `PI_ERR_RD_PRERR` | 0x1 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Error type 1 in the error status of a read request: partial read error. |
| `PI_ERR_RD_TERR` | 0x3 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Error type 3 in the error status of a read request: timeout. |
| `PI_ERR_WR_PWERR` | 0x1 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Error type 1 in the error status of a write request: partial write error. |
| `PI_ERR_WR_TERR` | 0x3 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Error type 3 in the error status of a write request: timeout. |
| `PI_ERR_WR_WERR` | 0x0 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Error type 0 in the error status of a write request: write error. |
| `PI_LOCAL_WINDOW_BASE` | 0x1000000 | established |  | Physical base of the processor's own hub window; no node shift. |
| `PI_MIN_STACK_SIZE` | 0x1000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Smallest error stack, bytes. The header's size macro gives the stack as this value shifted left by the size field minus one, or zero when the field is zero. |
| `PI_NODE_SHIFT` | 0x20 | established |  | Physical node number shift of the Origin 200/2000 hub in the 32-bit-node-number configuration. |
| `PI_NODE_WINDOW_BASE` | 0x1800000 | established |  | Physical base of a named node's window. |
| `PI_STACK_SIZE_SHIFT` | 0xc | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Shift of the 4 KiB unit of the error stack size, from the header. |
