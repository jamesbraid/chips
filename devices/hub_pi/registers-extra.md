<!-- generated from devices/hub_pi/registers-extra.toml by defs-gen - do not edit, change the source -->

# Hub processor interface registers, bit layouts and constants outside the census

Unit `hub_pi_extra`, macro prefix `HUB`.
Default source: public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pi_cpu_protect` | 0x0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_prot_override` | 0x8 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_io_protect` | 0x10 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_reply_level` | 0x60 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_nmi_b` | 0x78 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_softreset` | 0x80 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_cc_pend_set_a` | 0xc8 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_cc_pend_set_b` | 0xd0 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_cc_pend_clr_a` | 0xd8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_cc_pend_clr_b` | 0xe0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_cc_mask` | 0xe8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_rt_filter_ctrl` | 0x168 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bist_write_data` | 0x200 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bist_read_data` | 0x208 | r | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bist_count_targ` | 0x210 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bist_ready` | 0x218 | r | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bist_shift_load` | 0x220 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bist_shift_unload` | 0x228 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bist_enter_run` | 0x230 | w | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_page_a` | 0x300 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_credit_cntr_a` | 0x308 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_bias_a` | 0x310 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_int_cntr_a` | 0x318 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_page_b` | 0x328 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_credit_cntr_b` | 0x330 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_bias_b` | 0x338 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_gfx_int_cntr_b` | 0x340 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_err_status0_a_rclr` | 0x438 | r | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_err_status0_b_rclr` | 0x458 | r | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_spool_cmp_a` | 0x470 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_spool_cmp_b` | 0x478 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_crb_timeout_a` | 0x480 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_crb_timeout_b` | 0x488 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_sysad_errchk_en` | 0x490 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bad_check_bit_a` | 0x498 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_bad_check_bit_b` | 0x4a0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_nack_cnt_a` | 0x4a8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_nack_cnt_b` | 0x4b0 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `pi_nack_cmp` | 0x4b8 | rw | 64 |  |  | unknown | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |

### Register `pi_cpu_protect`

CPU protection register, named PI_CPU_PROTECT in the header. The header gives no fields. Access is assumed read and write.

### Register `pi_prot_override`

Protection override register, named PI_PROT_OVRRD in the header as the way to clear a CPU protection bit. The header gives neither an unlock value nor a behaviour, so none is imported. Access is assumed write only.

### Register `pi_io_protect`

Interrupt pending protection register, named PI_IO_PROTECT in the header. The header gives no fields. Access is assumed read and write.

### Register `pi_reply_level`

Reply level register, named PI_REPLY_LEVEL in the header. The header gives no fields. Access is assumed read and write.

### Register `pi_nmi_b`

Non-maskable interrupt to processor B, named PI_NMI_B in the header and paired with the processor A register at the same stride. Access is assumed write only, as for the processor A register in devices/hub/registers.toml.

### Register `pi_softreset`

Soft reset, named PI_SOFTRESET in the header with the comment that it resets both processors. The header gives no value and no fields, so the data written is not imported. Access is assumed write only.

### Register `pi_cc_pend_set_a`

Cross-call interrupt pending set for processor A, named PI_CC_PEND_SET_A in the header. Access is assumed write only.

### Register `pi_cc_pend_set_b`

Cross-call interrupt pending set for processor B, named PI_CC_PEND_SET_B in the header. The header's pairing rule puts it eight bytes above the processor A set. Access is assumed write only.

### Register `pi_cc_pend_clr_a`

Cross-call interrupt pending clear for processor A, named PI_CC_PEND_CLR_A in the header. Access is assumed read and write.

### Register `pi_cc_pend_clr_b`

Cross-call interrupt pending clear for processor B, named PI_CC_PEND_CLR_B in the header. Access is assumed read and write.

### Register `pi_cc_mask`

Cross-call interrupt mask, named PI_CC_MASK in the header. Access is assumed read and write.

### Register `pi_rt_filter_ctrl`

Global clock filter control, named PI_RT_FILTER_CTRL in the header, which gives no fields. It sits next to the real-time clock control register. Access is assumed read and write.

### Register `pi_bist_write_data`

Built-in self-test write data, named PI_BIST_WRITE_DATA in the header. Access is assumed write only.

### Register `pi_bist_read_data`

Built-in self-test read data, named PI_BIST_READ_DATA in the header. Access is assumed read only.

### Register `pi_bist_count_targ`

Built-in self-test count and target, named PI_BIST_COUNT_TARG in the header. Access is assumed read and write.

### Register `pi_bist_ready`

Built-in self-test ready indicator, named PI_BIST_READY in the header. Access is assumed read only.

### Register `pi_bist_shift_load`

Built-in self-test control, named PI_BIST_SHIFT_LOAD in the header. Access is assumed write only.

### Register `pi_bist_shift_unload`

Built-in self-test control, named PI_BIST_SHIFT_UNLOAD in the header. Access is assumed write only.

### Register `pi_bist_enter_run`

Built-in self-test control, named PI_BIST_ENTER_RUN in the header. Access is assumed write only.

### Register `pi_gfx_page_a`

Graphics page for processor A, named PI_GFX_PAGE_A in the header. The header names only the enable bit, which is in the fields below. Access is assumed read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `enable` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Graphics page enable, bit 40. The header names it PI_GFX_PAGE_ENABLE for both processor pages. |

### Register `pi_gfx_credit_cntr_a`

Graphics credit counter for processor A, named PI_GFX_CREDIT_CNTR_A in the header. The header gives no field layout and no meaning beyond the name. Access is assumed read and write.

### Register `pi_gfx_bias_a`

Graphics bias for processor A, named PI_GFX_BIAS_A in the header. The header gives no field layout. Access is assumed read and write.

### Register `pi_gfx_int_cntr_a`

Graphics interrupt counter for processor A, named PI_GFX_INT_CNTR_A in the header. The header gives no field layout. Access is assumed read and write.

### Register `pi_gfx_page_b`

Graphics page for processor B, named PI_GFX_PAGE_B in the header. The header's pairing rule puts it 0x28 above the processor A page. Access is assumed read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `enable` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Graphics page enable, bit 40, the same bit as the processor A page. |

### Register `pi_gfx_credit_cntr_b`

Graphics credit counter for processor B, named PI_GFX_CREDIT_CNTR_B in the header. Access is assumed read and write.

### Register `pi_gfx_bias_b`

Graphics bias for processor B, named PI_GFX_BIAS_B in the header. Access is assumed read and write.

### Register `pi_gfx_int_cntr_b`

Graphics interrupt counter for processor B, named PI_GFX_INT_CNTR_B in the header. Access is assumed read and write.

### Register `pi_err_status0_a_rclr`

Clear-on-read alias of error status 0 for processor A, named PI_ERR_STATUS0_A_RCLR in the header. The header's comment says a read clears the register. Access is assumed read only.

### Register `pi_err_status0_b_rclr`

Clear-on-read alias of error status 0 for processor B, named PI_ERR_STATUS0_B_RCLR in the header. The header's comment says a read clears the register. Access is assumed read only.

### Register `pi_spool_cmp_a`

Error spool compare for processor A, named PI_SPOOL_CMP_A in the header. Access is assumed read and write. The header gives no field layout.

### Register `pi_spool_cmp_b`

Error spool compare for processor B, named PI_SPOOL_CMP_B in the header. Access is assumed read and write.

### Register `pi_crb_timeout_a`

Timed-out CRB entries for processor A, named PI_CRB_TIMEOUT_A in the header. The header gives no field layout. Access is assumed read and write.

### Register `pi_crb_timeout_b`

Timed-out CRB entries for processor B, named PI_CRB_TIMEOUT_B in the header. Access is assumed read and write.

### Register `pi_sysad_errchk_en`

Enables for the processor bus checks, named PI_SYSAD_ERRCHK_EN in the header. Six enable bits, each named in the header's constants. Access is assumed read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `qual` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Check the data-quality signal, named PI_SYSAD_ERRCHK_QUAL in the header. |
| 4 | `state` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Check SysState parity, named PI_SYSAD_ERRCHK_STATE in the header. |
| 3 | `cmdp` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Check SysCmd parity, named PI_SYSAD_ERRCHK_CMDP in the header. |
| 2 | `sadp` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Check SysAD parity, named PI_SYSAD_ERRCHK_SADP in the header. |
| 1 | `qualgen` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Generate the data-quality signal, named PI_SYSAD_ERRCHK_QUALGEN in the header. |
| 0 | `eccgen` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Generate error-correction bits, named PI_SYSAD_ERRCHK_ECCGEN in the header. |

### Register `pi_bad_check_bit_a`

Forced SysAD check-bit error for processor A, named PI_BAD_CHECK_BIT_A in the header and described there as diagnostic. The header gives no field layout. Access is assumed read and write.

### Register `pi_bad_check_bit_b`

Forced SysAD check-bit error for processor B, named PI_BAD_CHECK_BIT_B in the header. Access is assumed read and write.

### Register `pi_nack_cnt_a`

Consecutive negative-acknowledge counter for processor A, named PI_NACK_CNT_A in the header. Access is assumed read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `enable` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Count enable, bit 20, named PI_NACK_CNT_EN in the header. |
| 19:0 | `count` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Negative-acknowledge count, bits 19:0, named PI_NACK_CNT_MASK in the header. |

### Register `pi_nack_cnt_b`

Consecutive negative-acknowledge counter for processor B, named PI_NACK_CNT_B in the header. Access is assumed read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `enable` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Count enable, bit 20, the same bit as the processor A counter. |
| 19:0 | `count` | established |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Negative-acknowledge count, bits 19:0. |

### Register `pi_nack_cmp`

Negative-acknowledge compare, named PI_NACK_CMP in the header. The header gives a maximum of 0x0fffff for the count, so the compare is twenty bits wide. Access is assumed read and write.

## Words

| Word | Width | Grade | Source |
|---|---|---|---|
| `PI_INT_PEND_MOD_FORMAT` | 64 | inferred | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) |
| `PI_RT_LOCAL_CTRL_FORMAT` | 64 | established | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions |

### Word `PI_INT_PEND_MOD_FORMAT`

Layout of the interrupt pending modify register, pi_int_pend_mod, as Linux writes it: a set bit and an interrupt level. Linux only writes the register. Whether a second processor in a node reaches it at another offset is not established by a public source and is not recorded.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `set` | inferred |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | set the level (1) or clear it (0); the role is read from how Linux builds the word |
| 6:0 | `level` | inferred |  | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | interrupt level number; Linux ORs the level into the word unmasked. The 0 to 127 range is inferred from the width of the sibling Bedrock layout |

### Word `PI_RT_LOCAL_CTRL_FORMAT`

Layout of the real-time counter local control register, the register the census names by its real-time clock control name. The header's mask and shift definitions give the fields below. The header gives no access type or reset value for it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `use_internal` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Use internal clock, bit 16, named PRLC_USE_INT in the header. The header gives no behaviour beyond the name. |
| 15 | `gclk` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Global clock flag, bit 15, named PRLC_GCLK in the header. The header gives no behaviour beyond the name. |
| 14:8 | `gclk_count` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Global clock count, seven bits at 14:8, named PRLC_GCLK_COUNT in the header. |
| 7:1 | `max_count` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Maximum count, seven bits at 7:1, named PRLC_MAX_COUNT in the header. The header gives no statement of what it sets. |
| 0 | `gclk_en` | established |  | public Linux SN0 Hub processor-interface header: PI_RT_LOCAL_CTRL mask and shift definitions | Global clock enable, bit 0, named PRLC_GCLK_EN in the header. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `IP_ERROR` | 0x4000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for Hub errors, named HUB_IP_ERROR in the header: IP6 line. |
| `IP_MASK` | 0x7c00 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | All five Hub-driven Cause bits together, named HUB_IP_MASK in the header. |
| `IP_PEND0` | 0x400 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the first pending bank, named HUB_IP_PEND0 in the header: IP2 line. |
| `IP_PEND1_CC` | 0x800 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the second pending bank and the cross-call sources, named HUB_IP_PEND1_CC in the header: IP3 line. |
| `IP_PROF` | 0x2000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the profiling comparator, named HUB_IP_PROF in the header: IP5 line. |
| `IP_RT` | 0x1000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Cause bit for the real-time counter comparator, named HUB_IP_RT in the header: IP4 line. |
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
| `PI_LOCAL_WINDOW_BASE` | 0x1000000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Physical base of the processor's own hub window; no node shift. |
| `PI_NODE_SHIFT` | 0x20 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Physical node number shift of the Origin 200/2000 hub in the 32-bit-node-number configuration. |
| `PI_NODE_WINDOW_BASE` | 0x1800000 | established | public Linux SN0 Hub processor-interface header, Linux v4.0 (names, offsets, masks and shifts) | Physical base of a named node's window. |
