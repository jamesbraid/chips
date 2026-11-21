<!-- generated from devices/hub/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 b60d4fb7431ff51b63d99d670a08717509715e57155ebbd0e581bdd116cda08d -->

# Hub (Origin 2000 node controller)

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown unless a register entry cites the source that states one.

Unit `hub`, macro prefix `HUB`.
Default source: census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pi_region_present` | 0x18 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) |
| `pi_cpu_num` | 0x20 | rw | 64 |  |  | 0x0 (established) | established | census: 136 sites, 20 routines |
| `pi_max_crb_timeout` | 0x30 | w | 64 |  |  | 0x80 (established) | established | census: 2 sites, 1 routines |
| `pi_crb_sfactor` | 0x38 | w | 64 |  |  | 0x0 (established) | established | census: 2 sites, 1 routines |
| `pi_cpu_present_a` | 0x40 | r | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_cpu_present_b` | 0x48 | r | 64 |  |  | 0x0 (established) | established | census: 2 sites, 1 routines |
| `pi_cpu_enable_a` | 0x50 | r | 64 |  |  | 0x0 (established) | established | census: 2 sites, 2 routines |
| `pi_cpu_enable_b` | 0x58 | r | 64 |  |  | 0x0 (established) | established | census: 2 sites, 2 routines |
| `pi_nmi_a` | 0x70 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `pi_int_pend0` | 0x98 | r | 64 |  |  | 0x0 (established) | established | census: 11 sites, 8 routines (r); census: 2 sites, 2 routines (r, indexed) |
| `pi_int_pend1` | 0xa0 | r | 64 |  |  | 0x0 (established) | established | census: 5 sites, 4 routines (r); census: 1 sites, 1 routines (r, indexed) |
| `pi_int_mask0_a` | 0xa8 | rw | 64 |  |  | 0x0 (established) | established | census: 4 sites, 4 routines |
| `pi_int_mask1_a` | 0xb0 | rw | 64 |  |  | 0x0 (established) | established | census: 4 sites, 4 routines |
| `pi_int_mask0_b` | 0xb8 | rw | 64 |  |  | 0x0 (established) | established | census: 2 sites, 2 routines |
| `pi_int_mask1_b` | 0xc0 | rw | 64 |  |  | 0x0 (established) | established | census: 6 sites, 3 routines |
| `pi_rt_compare_a` | 0x108 | w | 64 |  |  | 0x0 (established) | established | census: 25 sites, 6 routines |
| `pi_rt_compare_b` | 0x110 | w | 64 |  |  | 0x0 (established) | established | census: 3 sites, 3 routines |
| `pi_profile_compare` | 0x118 | w | 64 |  |  | 0x0 (established) | established | census: 2 sites, 2 routines |
| `pi_rt_pend_a` | 0x120 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_rt_pend_b` | 0x128 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_prof_pend_a` | 0x130 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_prof_pend_b` | 0x138 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_rt_en_a` | 0x140 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_rt_en_b` | 0x148 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_prof_en_a` | 0x150 | w | 64 |  |  | 0x0 (established) | established | census: 2 sites, 2 routines (w); census: 1 sites, 1 routines (w, indexed) |
| `pi_prof_en_b` | 0x158 | w | 64 |  |  | 0x0 (established) | established | census: 2 sites, 2 routines (w); census: 1 sites, 1 routines (w, indexed) |
| `pi_gfx_int_cmp_a` | 0x320 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_gfx_int_cmp_b` | 0x348 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `pi_err_stack_addr_a` | 0x418 | rw | 64 |  |  | 0x0 (established) | established | census: 4 sites, 3 routines (r); census: 2 sites, 1 routines (w, indexed) |
| `pi_err_stack_addr_b` | 0x420 | rw | 64 |  |  | 0x0 (established) | established | census: 7 sites, 3 routines |
| `pi_err_stack_size` | 0x428 | r | 64 |  |  | 0x0 (established) | established | census: 2 sites, 1 routines (r); census: 2 sites, 1 routines (r, indexed) |
| `pi_hardreset_bit` | 0x20068 | w | 64 |  |  | 0x1 (established) | established | census: 1 sites, 1 routines |
| `pi_rt_count` | 0x30100 | rw | 64 |  |  | 0x0 (established) | established | census: 161 sites, 80 routines |
| `md_mig_candidate_clr` | 0x200048 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_dir_error_clr` | 0x200058 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines (r); census: 4 sites, 3 routines (r, indexed) |
| `md_protocol_error_clr` | 0x200068 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `md_mem_error_clr` | 0x200078 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines (r); census: 5 sites, 3 routines (r, indexed) |
| `md_misc_error_clr` | 0x200088 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `per_hub_init` | 0x2000c8 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `hub_ifdr_fix_value` | 0x2000d0 | r | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `hub_reply_queue_depth` | 0x2000d8 | r | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `hub_rev_war_ctrl` | 0x2000e0 | rw | 64 |  |  | 0x0 (established) | established | census: 3 sites, 1 routines |
| `md_ureg0_0` | 0x220000 | rw | 64 |  |  | unknown | established | census: 6 sites, 2 routines (w); census: 22 sites, 6 routines (rw, indexed) |
| `md_ureg0_1` | 0x220008 | rw | 64 |  |  | unknown | established | census: 9 sites, 2 routines (w); census: 36 sites, 5 routines (rw, indexed) |
| `md_ureg1_0` | 0x220080 | w | 64 |  |  | 0x0 (established) | established | census: 38 sites, 9 routines |
| `iio_iidem` | 0x400120 | rw | 64 |  |  | 0xffffffffffffffff (established) | established | census: 5 sites, 3 routines |
| `hub_piomap_alloc` | 0x400160 | rw | 64 |  |  | 0x0 (established) | established | census: 5 sites, 4 routines |
| `mlreset` | 0x400190 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `iio_ioprb_0` | 0x400198 | rw | 64 |  |  | 0x1 (established) | established | census: 7 sites, 4 routines |
| `iio_ibcn` | 0x400200 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hub_error_devenable` | 0x4002c8 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `iio_prte_0` | 0x400308 | rw | 64 |  |  | 0x0 (established) | established | census: 4 sites, 1 routines |
| `iio_icto` | 0x4003b8 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `iio_ictp` | 0x4003c0 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `iio_icrb_a` | 0x400400 | rw | 64 | 15 |  | unknown | established | census: 14 sites, 9 routines |
| `iio_icrb_b` | 0x400408 | rw | 64 | 15 |  | unknown | established | census: 11 sites, 6 routines |
| `iio_icrb_c` | 0x400410 | r | 64 | 15 |  | unknown | established | census: 6 sites, 5 routines |
| `iio_icrb_d` | 0x400418 | r | 64 | 15 |  | unknown | established | census: 2 sites, 2 routines |
| `iio_ibsa_0` | 0x410008 | r | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `iio_ibda_0` | 0x410010 | r | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `iio_ibsa_1` | 0x420008 | rw | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) |
| `iio_ibda_1` | 0x420010 | rw | 64 |  |  | unknown | established | census: 1 sites, 1 routines (r); census: 1 sites, 1 routines (w, indexed) |
| `iio_ibna_1` | 0x420020 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `ni_scratch_reg0` | 0x600100 | w | 64 |  |  | 0x0 (established) | established | census: 1 sites, 1 routines |
| `ni_scratch_reg1` | 0x600108 | rw | 64 |  |  | 0x0 (established) | established | census: 14 sites, 2 routines |
| `ni_vector` | 0x600208 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `ni_vector_data` | 0x600210 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `ni_vector_read_data` | 0x600310 | rw | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `ni_meta_table0` | 0x638000 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ni_local_table0` | 0x638100 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |

### Register `pi_region_present`

### Register `pi_cpu_num`

### Register `pi_max_crb_timeout`

### Register `pi_crb_sfactor`

### Register `pi_cpu_present_a`

### Register `pi_cpu_present_b`

### Register `pi_cpu_enable_a`

### Register `pi_cpu_enable_b`

### Register `pi_nmi_a`

### Register `pi_int_pend0`

### Register `pi_int_pend1`

### Register `pi_int_mask0_a`

### Register `pi_int_mask1_a`

### Register `pi_int_mask0_b`

### Register `pi_int_mask1_b`

### Register `pi_rt_compare_a`

### Register `pi_rt_compare_b`

### Register `pi_profile_compare`

### Register `pi_rt_pend_a`

### Register `pi_rt_pend_b`

### Register `pi_prof_pend_a`

### Register `pi_prof_pend_b`

### Register `pi_rt_en_a`

### Register `pi_rt_en_b`

### Register `pi_prof_en_a`

### Register `pi_prof_en_b`

### Register `pi_gfx_int_cmp_a`

### Register `pi_gfx_int_cmp_b`

### Register `pi_err_stack_addr_a`

### Register `pi_err_stack_addr_b`

### Register `pi_err_stack_size`

### Register `pi_hardreset_bit`

### Register `pi_rt_count`

### Register `md_mig_candidate_clr`

### Register `md_dir_error_clr`

### Register `md_protocol_error_clr`

### Register `md_mem_error_clr`

### Register `md_misc_error_clr`

### Register `per_hub_init`

### Register `hub_ifdr_fix_value`

### Register `hub_reply_queue_depth`

### Register `hub_rev_war_ctrl`

### Register `md_ureg0_0`

### Register `md_ureg0_1`

### Register `md_ureg1_0`

### Register `iio_iidem`

### Register `hub_piomap_alloc`

### Register `mlreset`

### Register `iio_ioprb_0`

### Register `iio_ibcn`

### Register `hub_error_devenable`

### Register `iio_prte_0`

### Register `iio_icto`

### Register `iio_ictp`

### Register `iio_icrb_a`

Array of 15 registers, stride 32.

### Register `iio_icrb_b`

Array of 15 registers, stride 32.

### Register `iio_icrb_c`

Array of 15 registers, stride 32.

### Register `iio_icrb_d`

Array of 15 registers, stride 32.

### Register `iio_ibsa_0`

### Register `iio_ibda_0`

### Register `iio_ibsa_1`

### Register `iio_ibda_1`

### Register `iio_ibna_1`

### Register `ni_scratch_reg0`

### Register `ni_scratch_reg1`

### Register `ni_vector`

### Register `ni_vector_data`

### Register `ni_vector_read_data`

### Register `ni_meta_table0`

### Register `ni_local_table0`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `HUB_IFDR_FIX_VALUE_B_6_0` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_PIOMAP_ALLOC_V_300` | 0x300 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_REPLY_QUEUE_DEPTH_B_6_0` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `HUB_REV_WAR_CTRL_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_IBCN_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB_A_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB_A_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB_A_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB_A_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB_B_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICRB_B_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICTO_V_FF` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_ICTP_V_1000` | 0x1000 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `IIO_PRTE_0_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_MEM_ERROR_CLR_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_MISC_ERROR_CLR_B_9_0` | 0x3ff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_1C` | 0x1c | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_7F` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_8` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_0_V_FE` | 0xfe | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_3` | 0x8 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_4_2_1` | 0x16 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_45` | 0x45 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_80` | 0x80 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_A0` | 0xa0 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_C0` | 0xc0 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG0_1_V_C5` | 0xc5 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_23` | 0x23 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_2A` | 0x2a | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_2B` | 0x2b | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_31` | 0x31 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_35` | 0x35 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_36` | 0x36 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_3F` | 0x3f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_46` | 0x46 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_47` | 0x47 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_48` | 0x48 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_5D` | 0x5d | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_83` | 0x83 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_84` | 0x84 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_97` | 0x97 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_A` | 0xa | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_A6` | 0xa6 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_B` | 0xb | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_B4` | 0xb4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_C` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_CF` | 0xcf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_F` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_F3` | 0xf3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `MD_UREG1_0_V_FC` | 0xfc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_ERR_STACK_ADDR_A_B_8` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_INT_PEND1_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_PROF_EN_B_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_REGION_PRESENT_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_2A` | 0x2a | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_2B` | 0x2b | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_35` | 0x35 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_36` | 0x36 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5D` | 0x5d | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5E` | 0x5e | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_5F` | 0x5f | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_60` | 0x60 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_83` | 0x83 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_84` | 0x84 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_A` | 0xa | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_A6` | 0xa6 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_B` | 0xb | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_B4` | 0xb4 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COMPARE_A_V_C` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_COUNT_B_11_0` | 0xfff | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
| `PI_RT_EN_A_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the public Linux SN0 Hub register headers (the processor, memory, I/O and network interface sets) by offset; IRIX prints no register names, so every name is inferred (config register_names) |  |
