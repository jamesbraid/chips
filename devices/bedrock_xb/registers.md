<!-- generated from devices/bedrock_xb/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 ed209e81bcd3b4c09ee365d6ba1890e8b0e7509d8b2d283d8968ad81ab13d230 -->

# Bedrock internal crossbar (XB) registers outside the census

The crossbar's 21 control, debug and error registers at the start of its block, the 14 error-clear registers and the first-error register. The census has only the block's row in the dump table. Names, offsets and field layouts come from the public Linux header; that header states no access direction, reset value or side effect, so every item is inferred and the reset values are unknown. Access is recorded as rw for the control and error registers, r for the first-error register and w for the clear registers: the first two are assumed from the header's wording, the first-error register is what the header says (not writable). Clear registers take the field layout of the register they clear. Bit positions are the little-endian layout the header gives first.

Unit `bedrock_xb`, macro prefix `BEDROCK`.
Default source: Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `xb_parms` | 0x700000 | rw | 64 |  |  | 0x8000080000021 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_slow_gnt` | 0x700008 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_spew_control` | 0x700010 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_ioq_arb_trigger` | 0x700018 | rw | 64 |  |  | 0x5 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_poq0_error` | 0x700020 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_piq0_error` | 0x700028 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_poq1_error` | 0x700030 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_piq1_error` | 0x700038 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_mp0_error` | 0x700040 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_mp1_error` | 0x700048 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_mmq_error` | 0x700050 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_miq_error` | 0x700058 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_noq_error` | 0x700060 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_niq_error` | 0x700068 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_ioq_error` | 0x700070 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_iiq_error` | 0x700078 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_loq_error` | 0x700080 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_liq_error` | 0x700088 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_first_error` | 0x700090 | r | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_debug_data_ctl` | 0x700098 | rw | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_debug_arb_ctl` | 0x7000a0 | rw | 64 |  |  | unknown | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_poq0_error_clear` | 0x700120 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_piq0_error_clear` | 0x700128 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_poq1_error_clear` | 0x700130 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_piq1_error_clear` | 0x700138 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_mp0_error_clear` | 0x700140 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_mp1_error_clear` | 0x700148 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_mmq_error_clear` | 0x700150 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_miq_error_clear` | 0x700158 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_noq_error_clear` | 0x700160 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_niq_error_clear` | 0x700168 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_ioq_error_clear` | 0x700170 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_iiq_error_clear` | 0x700178 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_loq_error_clear` | 0x700180 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_liq_error_clear` | 0x700188 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `xb_first_error_clear` | 0x700190 | w | 64 |  |  | 0x0 (established) | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |

### Register `xb_parms`

Crossbar-wide parameters. The header gives the bypass enable and three wrap periods (age, deadlock, tail). It does not say what the periods count or how the crossbar uses them.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 51:32 | `tail_wrap` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 31:12 | `deadlock_wrap` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 11:4 | `age_wrap` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 0 | `byp_en` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_slow_gnt`

Wavefront grant period per unit: the number of cycles between grant opportunities. The all-ones value gives no grants, and one less than all ones the slowest rate. Used to apply backpressure to a unit's output queues. Bypass grants are not affected.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `pi0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 27:24 | `pi1` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 23:20 | `mp0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 19:16 | `mp1` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 15:12 | `mmq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 11:8 | `ni` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 7:4 | `ii` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 3:0 | `lb` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_spew_control`

Snoop selector for internal crossbar traffic, sent to the PI1 port. The header says only one selector should be set, and any set selector takes PI1 away from every use except this debug connection. Separate from the debug data select register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10 | `snoop_poq0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 9 | `snoop_mp0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 8 | `snoop_mmq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 7 | `snoop_noq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 6 | `snoop_ioq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 5 | `snoop_loq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 4 | `snoop_piq0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 3 | `snoop_miq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 2 | `snoop_niq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 1 | `snoop_iiq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 0 | `snoop_liq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_ioq_arb_trigger`

Clocks the I/O output queue waits before crossbar arbitration starts, so the slower I/O data rate can catch up in the queue buffer.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `clocks` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_poq0_error`

Error record for the PI0 output queue. The header says software may write it to test error handling, and the write raises an interrupt.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:12 | `tail_timeout` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 9:8 | `underflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 5:4 | `overflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 1:0 | `invalid_xsel` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_piq0_error`

Error record for the PI0 input queue. The header says the processor-interface input cannot underflow, so no underflow field is defined.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5:4 | `deadlock_timeout` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 1:0 | `overflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_poq1_error`

Error record for the PI1 output queue. The header gives no field layout for it. The header gives a layout only for the first-instance register of this pair; this one is assumed to share it (inferred from the matching names and the matching clear registers; no header text says so).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:12 | `tail_timeout` | inferred |  | Linux 2.5.40 SN1 register headers: xb_poq0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member pe_tail_timeout of the header's xb_poq0_error structure, 2 bits. |
| 9:8 | `underflow` | inferred |  | Linux 2.5.40 SN1 register headers: xb_poq0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member pe_underflow of the header's xb_poq0_error structure, 2 bits. |
| 5:4 | `overflow` | inferred |  | Linux 2.5.40 SN1 register headers: xb_poq0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member pe_overflow of the header's xb_poq0_error structure, 2 bits. |
| 1:0 | `invalid_xsel` | inferred |  | Linux 2.5.40 SN1 register headers: xb_poq0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member pe_invalid_xsel of the header's xb_poq0_error structure, 2 bits. |

### Register `xb_piq1_error`

Error record for the PI1 input queue. The header gives no field layout for it. The header gives a layout only for the first-instance register of this pair; this one is assumed to share it (inferred from the matching names and the matching clear registers; no header text says so).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5:4 | `deadlock_timeout` | inferred |  | Linux 2.5.40 SN1 register headers: xb_piq0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member pe_deadlock_timeout of the header's xb_piq0_error structure, 2 bits. |
| 1:0 | `overflow` | inferred |  | Linux 2.5.40 SN1 register headers: xb_piq0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member pe_overflow of the header's xb_piq0_error structure, 2 bits. |

### Register `xb_mp0_error`

Error record for the memory-to-PI0 output queue. The header notes the crossbar select is decoded on the memory side of this queue, so no invalid-select field is defined.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:12 | `tail_timeout` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 9:8 | `underflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 5:4 | `overflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_mp1_error`

Error record for the memory-to-PI1 output queue. The header gives no field layout for it. The header gives a layout only for the first-instance register of this pair; this one is assumed to share it (inferred from the matching names and the matching clear registers; no header text says so).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:12 | `tail_timeout` | inferred |  | Linux 2.5.40 SN1 register headers: xb_mp0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member me_tail_timeout of the header's xb_mp0_error structure, 2 bits. |
| 9:8 | `underflow` | inferred |  | Linux 2.5.40 SN1 register headers: xb_mp0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member me_underflow of the header's xb_mp0_error structure, 2 bits. |
| 5:4 | `overflow` | inferred |  | Linux 2.5.40 SN1 register headers: xb_mp0_error structure, applied to the matching second-instance register by name (the header gives no structure of its own) | Member me_overflow of the header's xb_mp0_error structure, 2 bits. |

### Register `xb_mmq_error`

Error record for the memory output queue that carries miscellaneous traffic to LB, NI and II. The header gives no field layout for it.

### Register `xb_miq_error`

Error record for the memory input queue. The header says further errors of this queue are logged in the memory unit's input error registers.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `deadlock_timeout` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_noq_error`

Error record for the NI output queue. The header defines three separate 4-bit counters for it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:12 | `tail_timeout` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 11:8 | `underflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 7:4 | `overflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_niq_error`

Error record for the NI input queue. The header gives no field layout for it.

### Register `xb_ioq_error`

Error record for the I/O output queue. The header gives no field layout for it.

### Register `xb_iiq_error`

Error record for the I/O input queue. The header gives no field layout for it.

### Register `xb_loq_error`

Error record for the LB output queue.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:12 | `tail_timeout` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 9:8 | `underflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 1:0 | `invalid_xsel` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_liq_error`

Error record for the LB input queue. The header says it records only request-channel errors: the reply channel has no flow control and cannot overflow or deadlock.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `deadlock_timeout` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 0 | `overflow` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_first_error`

The first crossbar error latched. It latches when the valid bit is clear and an error occurs. Any set valid bit interrupts both processor interfaces. The interrupt stays until the error register that captured the error is cleared, then this register is cleared, in that order. The header says the register is not writable but is set whenever software writes any error register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 12 | `valid` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 11:8 | `source` | inferred | first_error_source (liq=2, loq=3, iiq=4, ioq=5, niq=6, noq=7, miq=8, mmq=9, mp1=10, mp0=11, piq1=12, poq1=13, piq0=14, poq0=15) | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 7:4 | `channel` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 3:0 | `err_type` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_debug_data_ctl`

Selects which queue observation points drive debug output. The header says more than one selected point makes the debug output undefined. The output formats are not in the header.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `observe_lodata` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 14 | `observe_source_field` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 13 | `observe_poq0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 12 | `observe_poq1` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 11 | `observe_mmq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 10 | `observe_mp0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 9 | `observe_mp1` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 8 | `observe_noq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 7 | `observe_ioq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 6 | `observe_loq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 5 | `observe_piq0` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 4 | `observe_piq1` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 3 | `observe_miq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 2 | `observe_niq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 1 | `observe_iiq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |
| 0 | `observe_liq` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_debug_arb_ctl`

Three-bit select for the debug mux of the crossbar's queues and arbiter. The header does not give the output each value selects.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2:0 | `select` | inferred |  | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |  |

### Register `xb_poq0_error_clear`

Clears the PI0 output queue error record. The header does not say whether a write clears by any value or only by set bits, so the mechanism is unknown. Field layout as the base register.

### Register `xb_piq0_error_clear`

Clears the PI0 input queue error record. The write mechanism is unknown; field layout as the base register.

### Register `xb_poq1_error_clear`

Clears the PI1 output queue error record. The write mechanism is unknown.

### Register `xb_piq1_error_clear`

Clears the PI1 input queue error record. The write mechanism is unknown.

### Register `xb_mp0_error_clear`

Clears the memory-to-PI0 output queue error record. The write mechanism is unknown.

### Register `xb_mp1_error_clear`

Clears the memory-to-PI1 output queue error record. The write mechanism is unknown.

### Register `xb_mmq_error_clear`

Clears the memory output queue error record. The write mechanism is unknown.

### Register `xb_miq_error_clear`

Clears the memory input queue error record. The header names this register with an extra XM_ in the macro, and its comment says it clears the MIQ error register. The write mechanism is unknown.

### Register `xb_noq_error_clear`

Clears the NI output queue error record. The write mechanism is unknown.

### Register `xb_niq_error_clear`

Clears the NI input queue error record. The write mechanism is unknown.

### Register `xb_ioq_error_clear`

Clears the I/O output queue error record. The write mechanism is unknown.

### Register `xb_iiq_error_clear`

Clears the I/O input queue error record. The write mechanism is unknown.

### Register `xb_loq_error_clear`

Clears the LB output queue error record. The write mechanism is unknown.

### Register `xb_liq_error_clear`

Clears the LB input queue error record. The write mechanism is unknown.

### Register `xb_first_error_clear`

Clears the first-error register. The header says it is cleared after the error register that captured the error. The write mechanism is unknown.

## Enums

### Enum `first_error_source`

| Label | Value | Grade | Source |
|---|---|---|---|
| `liq` | 2 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `loq` | 3 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `iiq` | 4 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `ioq` | 5 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `niq` | 6 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `noq` | 7 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `miq` | 8 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `mmq` | 9 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `mp1` | 10 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `mp0` | 11 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `piq1` | 12 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `poq1` | 13 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `piq0` | 14 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |
| `poq0` | 15 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `XB_PARMS_ACTIVE_DEFAULTS` | 0x80000fffff021 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS | Software constant named as the active defaults in the same public header. Same as the reset constant except the deadlock period has all 20 bits set. Whether software writes this value is unknown. |
| `XB_PARMS_RESET_DEFAULTS` | 0x8000080000021 | inferred | Linux 2.5.40 public SN1 crossbar register headers: register names, offsets and field layouts, first-error source codes, XBP_RESET_DEFAULTS and XBP_ACTIVE_DEFAULTS | Software constant named as the reset defaults in the Linux 2.5.40 public SN1 crossbar header. It is what software writes, not a hardware reset value, and the reset value is unknown. Decodes to bypass on, age period 2, and deadlock and tail periods with only the top bit of their 20-bit fields set. |
