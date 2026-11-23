<!-- generated from devices/bedrock_pi/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 56a9d9b03087a7970d1facfa6db42468dac86685a2fa0f13c9d816cce0e4d02e -->

# Bedrock processor interface (PI) registers: field layouts, interrupt banks, real-time clock, graphics credits and error capture

Offsets are hub-relative inside one processor interface. The second interface repeats the same layout 2 MiB higher in the node window (see the processor-interface page). Register names, offsets, widths and field positions come from the public Linux 2.5.40 SN1 processor-interface register header, so they are established as header facts. Behaviour the header gives only in its comments is inferred. Access modes the header does not state are assumed read and write and labelled so in the text. The header gives no reset value for any register, so every reset is unknown.

Unit `bedrock_pi`, macro prefix `BEDROCK_PI`.
Default source: Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `cpu_protect` | 0x0 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `prot_override` | 0x8 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `io_protect` | 0x10 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `region_present` | 0x18 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cpu_num` | 0x20 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `calias_size` | 0x28 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `max_crb_timeout` | 0x30 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `crb_scale_factor` | 0x38 | rw | 64 |  |  | 0x64 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cpu_present_a` | 0x40 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cpu_present_b` | 0x48 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cpu_enable_a` | 0x50 | rw | 64 |  |  | 0x1 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cpu_enable_b` | 0x58 | rw | 64 |  |  | 0x1 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `nmi_a` | 0x70 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `nmi_b` | 0x78 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `ipi_a` | 0x80 | w | 64 |  |  | unknown | established |  |
| `ipi_b` | 0x88 | w | 64 |  |  | unknown | established |  |
| `int_pend_mod` | 0x90 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_pend0` | 0x98 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_pend1` | 0xa0 | r | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_mask0_a` | 0xa8 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_mask1_a` | 0xb0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_mask0_b` | 0xb8 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_mask1_b` | 0xc0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cc_pend_set_a` | 0xc8 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cc_pend_set_b` | 0xd0 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cc_pend_clr_a` | 0xd8 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cc_pend_clr_b` | 0xe0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `cc_mask` | 0xe8 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_pend1_remap` | 0xf0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `rt_compare_a` | 0x108 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `rt_compare_b` | 0x110 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `profile_compare` | 0x118 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `rt_int_pend_a` | 0x120 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `rt_int_pend_b` | 0x128 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `prof_int_pend_a` | 0x130 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `prof_int_pend_b` | 0x138 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `rt_int_en_a` | 0x140 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `rt_int_en_b` | 0x148 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `prof_int_en_a` | 0x150 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `prof_int_en_b` | 0x158 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `debug_sel` | 0x160 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `int_pend_mod_alias` | 0x180 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_page_a` | 0x300 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_credit_cntr_a` | 0x308 | rw | 64 |  |  | 0x40 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_bias_a` | 0x310 | rw | 64 |  |  | 0x24 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_int_cntr_a` | 0x318 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_int_cmp_a` | 0x320 | rw | 64 |  |  | 0x10000 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_page_b` | 0x328 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_credit_cntr_b` | 0x330 | rw | 64 |  |  | 0x40 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_bias_b` | 0x338 | rw | 64 |  |  | 0x24 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_int_cntr_b` | 0x340 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_int_cmp_b` | 0x348 | rw | 64 |  |  | 0x10000 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_int_pend_wr` | 0x3f8 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_int_pend` | 0x400 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_int_mask_a` | 0x408 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_int_mask_b` | 0x410 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_stack_addr_a` | 0x418 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_stack_addr_b` | 0x420 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_stack_size` | 0x428 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status0_a` | 0x430 | r | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status0_a_clr` | 0x438 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status1_a` | 0x440 | r | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status1_a_clr` | 0x448 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status0_b` | 0x450 | r | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status0_b_clr` | 0x458 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status1_b` | 0x460 | r | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_status1_b_clr` | 0x468 | w | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `spool_cmp_a` | 0x470 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `spool_cmp_b` | 0x478 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `crb_timeout_a` | 0x480 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `crb_timeout_b` | 0x488 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `sysad_errchk_en` | 0x490 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `force_bad_check_bit_a` | 0x498 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `force_bad_check_bit_b` | 0x4a0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `nack_cnt_a` | 0x4a8 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `nack_cnt_b` | 0x4b0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `nack_cmp` | 0x4b8 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `spool_mask` | 0x4c0 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `spurious_hdr_0` | 0x4c8 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `spurious_hdr_1` | 0x4d0 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `err_inject` | 0x4d8 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `reply_level` | 0x10060 | rw | 64 |  |  | 0x10 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `gfx_credit_mode` | 0x20068 | rw | 64 |  |  | 0x1 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `rt_counter` | 0x30100 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `perf_cntl_a` | 0x40200 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `perf_cntr0_a` | 0x40208 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `perf_cntr1_a` | 0x40210 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `perf_cntl_b` | 0x50200 | rw | 64 |  |  | unknown | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `perf_cntr0_b` | 0x50208 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |
| `perf_cntr1_b` | 0x50210 | rw | 64 |  |  | 0x0 (established) | established | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |

### Register `cpu_protect`

One bit per region. A set bit lets the processor in that region reach this interface's local registers. A denied access gets a protection error reply. The header says the register is not reset by a soft reset and gives no reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `cp_cpu_protect` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per region. |

### Register `prot_override`

A write carrying a special data pattern sets the writing processor's region bit in the CPU protect register. The header does not give the pattern.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `po_prot_ovrrd` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Written value compared against the special pattern; the pattern is not stated. |

### Register `io_protect`

One bit per region. Decides whether I/O-initiated interrupt writes from that region may set bits in the two pending banks. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `ip_io_protect` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per region. |

### Register `region_present`

One bit per region. Clear bits block speculative coherent reads to that region. A coherent read to an absent region gets an error reply and no error register changes. Partial reads and writes are not checked. Cached-alias accesses are not affected. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `rp_region_present` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per region. |

### Register `cpu_num`

Read by a processor to learn its own slot and interface. Bit 0 is the slot (0 for CPU A, 1 for CPU B); bit 1 is the interface (0 for PI0, 1 for PI1).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `cn_pi_id` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | 0 is PI0, 1 is PI1. |
| 0 | `cn_cpu_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | 0 is CPU A, 1 is CPU B. |

### Register `calias_size`

Size code for the cached-alias space. The header says all cached-alias spaces in a system must carry the same size. It is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `cs_calias_size` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Size code; the header does not give the size each code means. |

### Register `max_crb_timeout`

Value at which a valid coherency request buffer's timeout counter causes a timeout error. The header refers to the processor interface chapter of the Bedrock manual, which is not held.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `mct_max_timeout` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Maximum timeout value. |

### Register `crb_scale_factor`

Sets how often a valid coherency request buffer's timeout counter increments. The header refers to the same manual section as the maximum timeout register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:0 | `cs_sfactor` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Scale factor. |

### Register `cpu_present_a`

Set by the interface when it sees the first transaction from CPU A. The header gives no write behaviour.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `cpa_cpu_present` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `cpu_present_b`

Set by the interface when it sees the first transaction from CPU B. The header gives no write behaviour.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `cpb_cpu_present` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `cpu_enable_a`

While clear, the interface ignores the bus request from CPU A and never grants it the bus. The header says it is not reset by a soft reset and gives no reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `cea_cpu_enable` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `cpu_enable_b`

While clear, the interface ignores the bus request from CPU B and never grants it the bus. The header says it is not reset by a soft reset and gives no reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `ceb_cpu_enable` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `nmi_a`

A write issues a non-maskable interrupt to CPU A. The header gives no predicate on the written value, no latch behaviour and no reset value.

### Register `nmi_b`

A write issues a non-maskable interrupt to CPU B. The header gives no predicate on the written value, no latch behaviour and no reset value.

### Register `ipi_a`

Inter-processor interrupt delivery for the Itanium processor in slot A of this interface (IA-64 nodes only). A store of (delivery mode << 8) | vector, 64 bits wide, raises that vector on the processor. The Linux code stores to this offset of PI0 for slice 0 and PI1 for slice 2, from the node's hub register window. The MIPS headers do not define the offset and no MIPS software is known to use it. The register's reset, read behaviour and any mode beyond the written value are unknown.

### Register `ipi_b`

Inter-processor interrupt delivery for the Itanium processor in slot B of this interface (IA-64 nodes only), same use as ipi_a: slice 1 on PI0, slice 3 on PI1.

### Register `int_pend_mod`

Sets or clears one bit of an interrupt pending bank. It is the only pending-register write an I/O-issued write may make, and I/O protect checks it. Processor writes are checked against CPU protect. The header gives no reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `ipm_value` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | 1 sets the named bit, 0 clears it. |
| 6 | `ipm_reg_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | 0 selects pending bank 0, 1 selects pending bank 1. |
| 5:0 | `ipm_bit_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Bit number 0 to 63 in the bank chosen by the bank field. |

### Register `int_pend0`

Pending bank 0, read only. The bits map to interrupt level 2 in the header's naming. The graphics bits are set by hardware and must be cleared by software.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:7 | `int_pend0_hi` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | General. |
| 6 | `or_cc_pend_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Set when CPU B has a CPU-to-CPU interrupt pending. |
| 5 | `or_cc_pend_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Set when CPU A has a CPU-to-CPU interrupt pending. |
| 4 | `uart_ucntrl` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Name from the header's field list; the header's comment does not describe it. |
| 3 | `page_migration` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Page migration. |
| 2 | `gfx_int_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Graphics interrupt for CPU B; set by hardware, cleared by software. |
| 1 | `gfx_int_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Graphics interrupt for CPU A; set by hardware, cleared by software. |
| 0 | `int_pend0_lo` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | General; not named by the header. |

### Register `int_pend1`

Pending bank 1, read only. Bits map to interrupt level 3 unless the remap register moves bits 31 to 0 to level 2. The correctable-error, NACK and performance-overflow bits are set by hardware and must be cleared by software. The system shutdown, network, local-block and crossbar bits only reflect other logic and cannot be changed through this interface.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `system_shutdown` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | System shutdown; reflects other logic. |
| 62 | `ni_error` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Network interface error; reflects other logic. |
| 61 | `md_corr_error` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Memory and directory correctable error. |
| 60 | `sys_cor_err_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Correctable system error for CPU A; set by hardware. |
| 59 | `sys_cor_err_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Correctable system error for CPU B; set by hardware. |
| 58 | `perf_cntr_oflow` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Performance counter overflow. The header's comment for this bank calls the same bit RTC drop-out. |
| 57 | `nack_int_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | CPU B NACK count reached its compare; set by hardware. |
| 56 | `nack_int_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | CPU A NACK count reached its compare; set by hardware. |
| 55 | `lb_error` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Local block error; reflects other logic. |
| 54 | `xb_error` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Crossbar error; reflects other logic. |
| 53:0 | `int_pend1_gen` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | General bits 53 to 0. |

### Register `int_mask0_a`

Masks bank 0 for CPU A. A set bit passes the pending bit through as a level 2 interrupt (bit 10 of the processor's Cause register).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:7 | `ima_int_mask0_hi` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the general bits 63 to 7. |
| 6 | `ima_or_ccp_mask_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU B CPU-to-CPU bit. |
| 5 | `ima_or_ccp_mask_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU A CPU-to-CPU bit. |
| 4 | `ima_uart_ucntrl` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the UART bit. |
| 3 | `ima_page_migration` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the page migration bit. The header says only one processor per Bedrock should enable it. |
| 2 | `ima_gfx_int_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU B graphics bit. |
| 1 | `ima_gfx_int_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU A graphics bit. |
| 0 | `ima_int_mask0_lo` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the general bit 0 of bank 0. |

### Register `int_mask1_a`

Masks bank 1 for CPU A. Bits 63 to 32 always raise a level 3 interrupt (bit 11 of Cause). Bits 31 to 0 raise level 3 or level 2 depending on the remap register. The header says only one processor per Bedrock should enable the network, local-block, crossbar and memory-correctable bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `ima_int_mask1` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `int_mask0_b`

Masks bank 0 for CPU B. Same layout and meaning as the CPU A mask.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:7 | `imb_int_mask0_hi` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the general bits 63 to 7. |
| 6 | `imb_or_ccp_mask_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU B CPU-to-CPU bit. |
| 5 | `imb_or_ccp_mask_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU A CPU-to-CPU bit. |
| 4 | `imb_uart_ucntrl` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the UART bit. |
| 3 | `imb_page_migration` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the page migration bit. The header says only one processor per Bedrock should enable it. |
| 2 | `imb_gfx_int_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU B graphics bit. |
| 1 | `imb_gfx_int_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the CPU A graphics bit. |
| 0 | `imb_int_mask0_lo` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Mask for the general bit 0 of bank 0. |

### Register `int_mask1_b`

Masks bank 1 for CPU B. Same layout and meaning as the CPU A mask.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `imb_int_mask1` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `cc_pend_set_a`

A store by a CPU sets the bit for the storing processor's region in the CPU A CPU-to-CPU pending register. These registers have no access protection.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `cpsa_cc_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per region. |

### Register `cc_pend_set_b`

A store by a CPU sets the bit for the storing processor's region in the CPU B CPU-to-CPU pending register. These registers have no access protection.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `cpsb_cc_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per region. |

### Register `cc_pend_clr_a`

A read returns the CPU A CPU-to-CPU pending bits. A write clears each bit whose data bit is one.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `cpca_cc_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per region. |

### Register `cc_pend_clr_b`

A read returns the CPU B CPU-to-CPU pending bits. A write clears each bit whose data bit is one.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `cpcb_cc_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per region. |

### Register `cc_mask`

Masks both CPU-to-CPU pending registers.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:0 | `cm_cc_mask` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `int_pend1_remap`

Moves bank 1 bits 31 to 0 from level 3 to level 2 under control of the low four bits. Bit 4 forwards the memory and unit error interrupts to the I/O interface, which raises its interrupt to the node named in its destination register, so the errors can reach another node. The header does not give the encoding of the four-bit selector.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `ipr_error_forward` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Forward memory, network, local-block and crossbar errors to the I/O interface. |
| 3:0 | `ipr_remap` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Low four bits of the remap selector; encoding not given. |

### Register `rt_compare_a`

When the real-time counter equals this value, the CPU A real-time pending bit is set. The header's comment says this sends a level 4 interrupt. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `rca_rt_compare` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Compare value. |

### Register `rt_compare_b`

When the real-time counter equals this value, the CPU B real-time pending bit is set. The header's comment says this sends a level 4 interrupt. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `rcb_rt_compare` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Compare value. |

### Register `profile_compare`

When the low 32 bits of the real-time counter equal this value, both profiling pending registers are set to one. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `pc_profile_compare` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Compare value. |

### Register `rt_int_pend_a`

Real-time interrupt pending for CPU A. When the matching enable is set, CPU A's interrupt line follows this bit. The header's comment on this register says level 5, which conflicts with the compare register's level 4. Any store clears the bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `ripa_rtc_int_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `rt_int_pend_b`

Real-time interrupt pending for CPU B. When the matching enable is set, CPU B's interrupt line follows this bit. The header's comment says level 5. Any store clears the bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `ripb_rtc_int_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `prof_int_pend_a`

Profiling interrupt pending for CPU A. Set when the profile compare matches. Any store clears it. The A and B copies are separate so each can be cleared alone.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `pipa_prof_int_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `prof_int_pend_b`

Profiling interrupt pending for CPU B. Set when the profile compare matches. Any store clears it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `pipb_prof_int_pend` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `rt_int_en_a`

Enables the real-time interrupt to CPU A.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `riea_rtc_int_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `rt_int_en_b`

Enables the real-time interrupt to CPU B.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `rieb_rtc_int_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `prof_int_en_a`

Enables the profiling interrupt to CPU A.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `piea_prof_int_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `prof_int_en_b`

Enables the profiling interrupt to CPU B.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `pieb_prof_int_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `debug_sel`

Selects the debug data the interface drives, together with the debug module's select. The header gives the selector names below and says the B-select bit chooses CPU A or CPU B logic for some selections. Each low and high selector bit is one signal, named by the header as follows: low selector bits are t5cc A, t5cc B, totcc A, totcc B, reqcc A, reqcc B, rplcc A, rplcc B, intcc, perf increment A 0 and 1, perf increment B 0 and 1; high selector bits are the same names in the same order.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 26 | `ds_b_sel` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Chooses CPU B logic where the selection applies to both processors. |
| 25:13 | `ds_high_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | High selector bits, as named in the register description. |
| 12:0 | `ds_low_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Low selector bits, as named in the register description. |

### Register `int_pend_mod_alias`

Alias of the pending-modify register with the same layout and checks. The header does not say why a second address exists.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `ipm_value` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | 1 sets the named bit, 0 clears it. |
| 6 | `ipm_reg_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | 0 selects pending bank 0, 1 selects pending bank 1. |
| 5:0 | `ipm_bit_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Bit number 0 to 63 in the bank chosen by the bank field. |

### Register `gfx_page_a`

Graphics page for CPU A. Uncached I/O stores into the enabled page are graphics write commands tracked by the credit counter, not ordinary write commands. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `gpa_en_gfx_page` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables the page. |
| 39:17 | `gpa_gfx_page_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Page address, bits 39 to 17. |

### Register `gfx_credit_cntr_a`

Graphics credit counter for CPU A. It drops by one per doubleword sent to graphics and rises by one per doubleword acknowledged. When it is below the bias, the header says write-ready is withheld, an interrupt is sent, and write-ready is allowed again. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:0 | `gcca_gfx_credit_cntr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Credit count. |

### Register `gfx_bias_a`

Graphics bias for CPU A. When the credit counter is at or below this value, the header says a flow-control interrupt is sent. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:0 | `gba_gfx_bias` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Bias value. |

### Register `gfx_int_cntr_a`

Graphics interrupt counter for CPU A. The header says it is written by software, loaded from the compare on an interrupt, NMI or soft reset, zeroed when the credit counter rises above the bias, and counts one per clock while the credit counter is at or below zero. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:0 | `gica_gfx_int_cntr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Counter value. |

### Register `gfx_int_cmp_a`

Graphics interrupt compare for CPU A. The interrupt is sent when the interrupt counter reaches this value. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:0 | `gica_gfx_int_cmp` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Compare value. |

### Register `gfx_page_b`

Graphics page for CPU B. Uncached I/O stores into the enabled page are graphics write commands tracked by the credit counter, not ordinary write commands. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `gpb_en_gfx_page` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables the page. |
| 39:17 | `gpb_gfx_page_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Page address, bits 39 to 17. |

### Register `gfx_credit_cntr_b`

Graphics credit counter for CPU B. It drops by one per doubleword sent to graphics and rises by one per doubleword acknowledged. When it is below the bias, the header says write-ready is withheld, an interrupt is sent, and write-ready is allowed again. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:0 | `gccb_gfx_credit_cntr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Credit count. |

### Register `gfx_bias_b`

Graphics bias for CPU B. When the credit counter is at or below this value, the header says a flow-control interrupt is sent. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:0 | `gbb_gfx_bias` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Bias value. |

### Register `gfx_int_cntr_b`

Graphics interrupt counter for CPU B. The header says it is written by software, loaded from the compare on an interrupt, NMI or soft reset, zeroed when the credit counter rises above the bias, and counts one per clock while the credit counter is at or below zero. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:0 | `gicb_gfx_int_cntr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Counter value. |

### Register `gfx_int_cmp_b`

Graphics interrupt compare for CPU B. The interrupt is sent when the interrupt counter reaches this value. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 25:0 | `gicb_gfx_int_cmp` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Compare value. |

### Register `err_int_pend_wr`

Writable view of the error interrupt pending bits. A read returns every error source. A direct write sets or clears each unreserved bit, except the memory uncorrectable bit. Bit layout is the same as the write-with-clear register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 34 | `irb_timeout_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 33 | `irb_timeout_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 32 | `irb_err_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 31 | `irb_err_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 30 | `pkt_len_err_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 29 | `pkt_len_err_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 28 | `ue_cached_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 27 | `ue_cached_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 26 | `sysad_bad_data_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 25 | `sysad_bad_data_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 24 | `mem_unc` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 23 | `sysstate_tag_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 22 | `sysstate_tag_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 21 | `ue_uncached_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 20 | `ue_uncached_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 19 | `spool_err_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 18 | `spool_err_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 17 | `syscmd_addr_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 16 | `syscmd_addr_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 15 | `syscmd_data_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 14 | `syscmd_data_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 13 | `sysad_addr_ecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 12 | `sysad_addr_ecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 11 | `sysad_data_ecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 10 | `sysad_data_ecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 9 | `sysstate_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 8 | `sysstate_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 7 | `wrb_werr_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 6 | `wrb_werr_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 5 | `wrb_terr_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 4 | `wrb_terr_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 3 | `spurious_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 2 | `spurious_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 1 | `spool_comp_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 0 | `spool_comp_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `err_int_pend`

Error interrupt pending. A read returns every error source. A store clears each bit whose data bit is one. Bits 0 to 23 are twelve CPU B and CPU A pairs with B at the even bit, in order: spool complete, spurious message, the two write-buffer error kinds, system-state parity, system data ECC, system address ECC, command data parity, command address parity, spool error, uncached uncorrectable, system-state tag. Bit 24 is memory uncorrectable. Bits 25 to 34 are five pairs with A at the even bit: bad data, cached uncorrectable, packet length, request-buffer error and request-buffer timeout.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 34 | `irb_timeout_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 33 | `irb_timeout_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 32 | `irb_err_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 31 | `irb_err_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 30 | `pkt_len_err_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 29 | `pkt_len_err_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 28 | `ue_cached_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 27 | `ue_cached_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 26 | `sysad_bad_data_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 25 | `sysad_bad_data_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 24 | `mem_unc` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 23 | `sysstate_tag_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 22 | `sysstate_tag_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 21 | `ue_uncached_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 20 | `ue_uncached_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 19 | `spool_err_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 18 | `spool_err_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 17 | `syscmd_addr_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 16 | `syscmd_addr_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 15 | `syscmd_data_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 14 | `syscmd_data_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 13 | `sysad_addr_ecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 12 | `sysad_addr_ecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 11 | `sysad_data_ecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 10 | `sysad_data_ecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 9 | `sysstate_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 8 | `sysstate_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 7 | `wrb_werr_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 6 | `wrb_werr_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 5 | `wrb_terr_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 4 | `wrb_terr_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 3 | `spurious_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 2 | `spurious_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 1 | `spool_comp_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 0 | `spool_comp_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `err_int_mask_a`

Masks the error pending bits for CPU A. A set bit lets that error raise the level 6 interrupt to CPU A. The header says only one processor per Bedrock should enable the memory uncorrectable bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 34:0 | `eima_mask` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per error pending bit. |

### Register `err_int_mask_b`

Masks the error pending bits for CPU B. A set bit lets that error raise the level 6 interrupt to CPU B. The header says only one processor per Bedrock should enable the memory uncorrectable bit.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 34:0 | `eimb_mask` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per error pending bit. |

### Register `err_stack_addr_a`

Address of the next write to the CPU A error stack. It increments after each write, and only the low bits that the stack size selects count up. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32:3 | `esaa_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Address bits 32 to 3. |

### Register `err_stack_addr_b`

Address of the next write to the CPU B error stack. It increments after each write, and only the low bits that the stack size selects count up. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 32:3 | `esab_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Address bits 32 to 3. |

### Register `err_stack_size`

Size of the error stack that is spooled to local memory when an error occurs. The header describes it as a count of 64-bit entries and says it is not reset by a soft reset. The encoding of the four-bit field is not given in this header.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `ess_size` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `err_status0_a`

First error status record for CPU A. Saved only when the valid bit is set. Writing the matching clear alias clears both status records for this CPU. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `esa_valid` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Record valid. |
| 62 | `esa_over_run` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Overrun flag; the header gives no further description. |
| 61:25 | `esa_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Address field. |
| 24:17 | `esa_cmd` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Command field. |
| 16:6 | `esa_supplemental` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Supplemental message field. |
| 5:3 | `esa_proc_req_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Processor request number, as the header names it. |
| 2:0 | `esa_error_type` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Error type; the header gives no encoding in this register's description. |

### Register `err_status0_a_clr`

Write-clear alias of the first error status record for CPU A. Any write clears both the status 0 and status 1 records for this CPU.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `esca_valid` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Record valid. |
| 62 | `esca_over_run` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Overrun flag; the header gives no further description. |
| 61:25 | `esca_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Address field. |
| 24:17 | `esca_cmd` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Command field. |
| 16:6 | `esca_supplemental` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Supplemental message field. |
| 5:3 | `esca_proc_req_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Processor request number, as the header names it. |
| 2:0 | `esca_error_type` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Error type; the header gives no encoding in this register's description. |

### Register `err_status1_a`

Second error status record for CPU A. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `source` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Source of the error. |
| 52 | `p_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 51 | `v_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 50 | `r_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 49 | `a_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 48 | `w_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 47 | `h_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 46 | `i_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 45 | `t_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 44:43 | `e_bits` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Encoding not given. |
| 42 | `wrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Write buffer flag; the header gives no further description. |
| 41:39 | `crb_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Coherency request buffer number, as the header names it. |
| 38:29 | `inval_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Invalidate counter. |
| 28:21 | `time_out_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Timeout counter. |
| 20:0 | `spool_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Spool count. |

### Register `err_status1_a_clr`

Write-clear alias of the second error status record for CPU A. Any write clears both status records for this CPU.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `source` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Source of the error. |
| 52 | `p_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 51 | `v_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 50 | `r_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 49 | `a_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 48 | `w_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 47 | `h_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 46 | `i_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 45 | `t_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 44:43 | `e_bits` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Encoding not given. |
| 42 | `wrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Write buffer flag; the header gives no further description. |
| 41:39 | `crb_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Coherency request buffer number, as the header names it. |
| 38:29 | `inval_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Invalidate counter. |
| 28:21 | `time_out_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Timeout counter. |
| 20:0 | `spool_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Spool count. |

### Register `err_status0_b`

First error status record for CPU B. Saved only when the valid bit is set. Writing the matching clear alias clears both status records for this CPU. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `esb_valid` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Record valid. |
| 62 | `esb_over_run` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Overrun flag; the header gives no further description. |
| 61:25 | `esb_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Address field. |
| 24:17 | `esb_cmd` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Command field. |
| 16:6 | `esb_supplemental` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Supplemental message field. |
| 5:3 | `esb_proc_req_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Processor request number, as the header names it. |
| 2:0 | `esb_error_type` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Error type; the header gives no encoding in this register's description. |

### Register `err_status0_b_clr`

Write-clear alias of the first error status record for CPU B. Any write clears both the status 0 and status 1 records for this CPU.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `escb_valid` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Record valid. |
| 62 | `escb_over_run` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Overrun flag; the header gives no further description. |
| 61:25 | `escb_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Address field. |
| 24:17 | `escb_cmd` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Command field. |
| 16:6 | `escb_supplemental` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Supplemental message field. |
| 5:3 | `escb_proc_req_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Processor request number, as the header names it. |
| 2:0 | `escb_error_type` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Error type; the header gives no encoding in this register's description. |

### Register `err_status1_b`

Second error status record for CPU B. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `source` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Source of the error. |
| 52 | `p_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 51 | `v_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 50 | `r_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 49 | `a_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 48 | `w_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 47 | `h_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 46 | `i_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 45 | `t_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 44:43 | `e_bits` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Encoding not given. |
| 42 | `wrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Write buffer flag; the header gives no further description. |
| 41:39 | `crb_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Coherency request buffer number, as the header names it. |
| 38:29 | `inval_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Invalidate counter. |
| 28:21 | `time_out_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Timeout counter. |
| 20:0 | `spool_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Spool count. |

### Register `err_status1_b_clr`

Write-clear alias of the second error status record for CPU B. Any write clears both status records for this CPU.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `source` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Source of the error. |
| 52 | `p_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 51 | `v_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 50 | `r_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 49 | `a_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 48 | `w_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 47 | `h_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 46 | `i_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 45 | `t_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Flag; name only in the header. |
| 44:43 | `e_bits` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Encoding not given. |
| 42 | `wrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Write buffer flag; the header gives no further description. |
| 41:39 | `crb_num` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Coherency request buffer number, as the header names it. |
| 38:29 | `inval_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Invalidate counter. |
| 28:21 | `time_out_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Timeout counter. |
| 20:0 | `spool_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Spool count. |

### Register `spool_cmp_a`

Spool compare for CPU A. The header gives the field only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `sca_compare` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `spool_cmp_b`

Spool compare for CPU B. The header gives the field only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `scb_compare` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `crb_timeout_a`

Coherency request buffer timeout. The header says a timeout can be forced by writing one bits; the two fields are named read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:4 | `cta_wrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Write request buffer timeout field. |
| 3:0 | `cta_rrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Read request buffer timeout field. |

### Register `crb_timeout_b`

Coherency request buffer timeout. The header says a timeout can be forced by writing one bits; the two fields are named read and write.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:4 | `ctb_wrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Write request buffer timeout field. |
| 3:0 | `ctb_rrb` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Read request buffer timeout field. |

### Register `sysad_errchk_en`

Controls error checking and forwarding of system bus errors. The header does not give a reset value.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `see_qual_chk_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Check the data quality indicator. |
| 4 | `see_state_chk_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Check system state. |
| 3 | `see_cmdp_chk_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Check command parity. |
| 2 | `see_sadp_chk_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Check address and data parity. |
| 1 | `see_qual_gen_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Generate the data quality indicator. |
| 0 | `see_ecc_gen_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Generate ECC. |

### Register `force_bad_check_bit_a`

For CPU A: when reply data arrives with the uncorrectable indicator set, the check bits sent on the system bus are inverted in each set position, and the data quality indicator is not asserted.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `fbcba_bad_check_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per check bit. |

### Register `force_bad_check_bit_b`

For CPU B: when reply data arrives with the uncorrectable indicator set, the check bits sent on the system bus are inverted in each set position, and the data quality indicator is not asserted.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `fbcbb_bad_check_bit` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | One bit per check bit. |

### Register `nack_cnt_a`

Counts CPU A's negative acknowledgements while the count is enabled. The count clears on any other reply. When a negative acknowledgement arrives with the count equal to the compare, the count clears, the processor gets an error reply instead, and the CPU A NACK bit is set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `nca_cnt_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables the count. |
| 19:0 | `nca_nack_cnt` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Count. |

### Register `nack_cnt_b`

Counts CPU B's negative acknowledgements while the count is enabled. The count clears on any other reply. When a negative acknowledgement arrives with the count equal to the compare, the count clears, the processor gets an error reply instead, and the CPU B NACK bit is set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 20 | `ncb_cnt_en` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables the count. |
| 19:0 | `ncb_nack_cnt` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Count. |

### Register `nack_cmp`

Compare value for both NACK counts. It affects both processors on this interface.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 19:0 | `nc_nack_cmp` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Compare value. |

### Register `spool_mask`

Chooses which error kinds are spooled. A set bit spools that error. It affects both processors on this interface.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `sm_nack_oflow_err` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 4 | `sm_poison_err` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 3 | `sm_timeout_err` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 2 | `sm_dir_err` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 1 | `sm_uncached_err` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 0 | `sm_access_err` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `spurious_hdr_0`

Captures the header of an incoming message that matches no coherency request buffer entry while the valid bit is clear. Write zero to clear. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `sh0_valid` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 62 | `sh0_tail` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 61:25 | `sh0_addr` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 24:17 | `sh0_cmd` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 16:6 | `sh0_supplemental` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 1 | `sh0_prev_valid_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | CPU A's error status record was valid. |
| 0 | `sh0_prev_valid_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | CPU B's error status record was valid. |

### Register `spurious_hdr_1`

Second half of the spurious message capture. Write zero to clear. The header says it is not reset by a soft reset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:53 | `sh1_source` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Source of the spurious message. |

### Register `err_inject`

Arms the injection of one error kind into the next outbound system bus transfer of that type. The bit clears when the error is injected. Writing does not cause a transaction. A bit stays set until a matching transfer occurs, so software can poll it. Data quality injection is not in this register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `sysresp_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 37 | `data_sysad_uncecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 36 | `cmd_sysad_uncecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 35 | `data_sysad_corecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 34 | `cmd_sysad_corecc_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 33 | `data_syscmd_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 32 | `cmd_syscmd_par_b` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 6 | `sysresp_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 5 | `data_sysad_uncecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 4 | `cmd_sysad_uncecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 3 | `data_sysad_corecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 2 | `cmd_sysad_corecc_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 1 | `data_syscmd_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |
| 0 | `cmd_syscmd_par_a` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts |  |

### Register `reply_level`

Stops the processors from issuing requests while the reply FIFO holds more entries than this value. The FIFO holds 63 entries, so a value of 63 never stops the processors, and a value of 0 stops them whenever any reply waits. The register is in its own 64 KB page.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5:0 | `rl_reply_level` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Threshold in entries. |

### Register `gfx_credit_mode`

Switches the credit counter from counting doublewords to counting transactions. The header puts it in its own 64 KB page so it can be mapped to user space. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `gcm_trans_mode` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | 1 counts transactions, 0 counts doublewords. |

### Register `rt_counter`

Real-time counter. It wraps to zero at its maximum value and increments on each rising edge of the global clock. The header puts it in its own 64 KB page so it can be mapped to user space.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `rc_count` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Count. |

### Register `perf_cntl_a`

Controls the two performance counters of CPU A. The header says each counter can be set to count one of several events but does not list the events. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `pca_cntr_1_enable` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables counter 1. |
| 62:60 | `pca_cntr_1_mode` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Counting mode; encoding not given. |
| 59:32 | `pca_cntr_1_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Event selector for counter 1. |
| 31 | `pca_cntr_0_enable` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables counter 0. |
| 30:28 | `pca_cntr_0_mode` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Counting mode; encoding not given. |
| 27:0 | `pca_cntr_0_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Event selector for counter 0. |

### Register `perf_cntr0_a`

Performance counter 0 of CPU A. Forty bits wide. On overflow it wraps to zero, sets its overflow bit and sets the performance overflow bit in bank 1. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `pca_overflow` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Set on overflow. |
| 39:0 | `pca_count_value` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Count. |

### Register `perf_cntr1_a`

Performance counter 1 of CPU A. Forty bits wide. On overflow it wraps to zero, sets its overflow bit and sets the performance overflow bit in bank 1. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `pca_overflow` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Set on overflow. |
| 39:0 | `pca_count_value` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Count. |

### Register `perf_cntl_b`

Controls the two performance counters of CPU B. The header says each counter can be set to count one of several events but does not list the events. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `pcb_cntr_1_enable` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables counter 1. |
| 62:60 | `pcb_cntr_1_mode` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Counting mode; encoding not given. |
| 59:32 | `pcb_cntr_1_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Event selector for counter 1. |
| 31 | `pcb_cntr_0_enable` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Enables counter 0. |
| 30:28 | `pcb_cntr_0_mode` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Counting mode; encoding not given. |
| 27:0 | `pcb_cntr_0_select` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Event selector for counter 0. |

### Register `perf_cntr0_b`

Performance counter 0 of CPU B. Forty bits wide. On overflow it wraps to zero, sets its overflow bit and sets the performance overflow bit in bank 1. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `pcb_overflow` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Set on overflow. |
| 39:0 | `pcb_count_value` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Count. |

### Register `perf_cntr1_b`

Performance counter 1 of CPU B. Forty bits wide. On overflow it wraps to zero, sets its overflow bit and sets the performance overflow bit in bank 1. Access is not stated; read and write is assumed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 40 | `pcb_overflow` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Set on overflow. |
| 39:0 | `pcb_count_value` | established |  | Linux 2.5.40 SN1 processor-interface register header: names, offsets and field layouts | Count. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `PI1_BASE` | 0x200000 | established |  | Offset of the second processor interface's register file from the first, in the node's register space. The unit's registers are the first interface's; the second repeats them at this distance. No public source tree states it. |
