// generated from devices/hub/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 b60d4fb7431ff51b63d99d670a08717509715e57155ebbd0e581bdd116cda08d
// Hub (Origin 2000 node controller)
#![allow(dead_code)]

/// (established)
pub mod pi_region_present {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod pi_cpu_num {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod pi_max_crb_timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30;
}
/// (established)
pub mod pi_crb_sfactor {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38;
}
/// (established)
pub mod pi_cpu_present_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40;
}
/// (established)
pub mod pi_cpu_present_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x48;
}
/// (established)
pub mod pi_cpu_enable_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50;
}
/// (established)
pub mod pi_cpu_enable_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x58;
}
/// (established)
pub mod pi_nmi_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x70;
}
/// (established)
pub mod pi_int_pend0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x98;
}
/// (established)
pub mod pi_int_pend1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod pi_int_mask0_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa8;
}
/// (established)
pub mod pi_int_mask1_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0;
}
/// (established)
pub mod pi_int_mask0_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb8;
}
/// (established)
pub mod pi_int_mask1_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xc0;
}
/// (established)
pub mod pi_rt_compare_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x108;
}
/// (established)
pub mod pi_rt_compare_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110;
}
/// (established)
pub mod pi_profile_compare {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x118;
}
/// (established)
pub mod pi_rt_pend_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120;
}
/// (established)
pub mod pi_rt_pend_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x128;
}
/// (established)
pub mod pi_prof_pend_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x130;
}
/// (established)
pub mod pi_prof_pend_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x138;
}
/// (established)
pub mod pi_rt_en_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x140;
}
/// (established)
pub mod pi_rt_en_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x148;
}
/// (established)
pub mod pi_prof_en_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150;
}
/// (established)
pub mod pi_prof_en_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x158;
}
/// (established)
pub mod pi_gfx_int_cmp_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x320;
}
/// (established)
pub mod pi_gfx_int_cmp_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x348;
}
/// (established)
pub mod pi_err_stack_addr_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x418;
}
/// (established)
pub mod pi_err_stack_addr_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420;
}
/// (established)
pub mod pi_err_stack_size {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x428;
}
/// (established)
pub mod pi_hardreset_bit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20068;
}
/// (established)
pub mod pi_rt_count {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30100;
}
/// (established)
pub mod md_mig_candidate_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200048;
}
/// (established)
pub mod md_dir_error_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200058;
}
/// (established)
pub mod md_protocol_error_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200068;
}
/// (established)
pub mod md_mem_error_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200078;
}
/// (established)
pub mod md_misc_error_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200088;
}
/// (established)
pub mod per_hub_init {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2000c8;
}
/// (established)
pub mod hub_ifdr_fix_value {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2000d0;
}
/// (established)
pub mod hub_reply_queue_depth {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2000d8;
}
/// (established)
pub mod hub_rev_war_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2000e0;
}
/// (established)
pub mod md_ureg0_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220000;
}
/// (established)
pub mod md_ureg0_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220008;
}
/// (established)
pub mod md_ureg1_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220080;
}
/// (established)
pub mod iio_iidem {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400120;
}
/// (established)
pub mod hub_piomap_alloc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400160;
}
/// (established)
pub mod mlreset {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400190;
}
/// (established)
pub mod iio_ioprb_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400198;
}
/// (established)
pub mod iio_ibcn {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400200;
}
/// (established)
pub mod hub_error_devenable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4002c8;
}
/// (established)
pub mod iio_prte_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400308;
}
/// (established)
pub mod iio_icto {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4003b8;
}
/// (established)
pub mod iio_ictp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4003c0;
}
/// (established)
pub mod iio_icrb_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400400;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// (established)
pub mod iio_icrb_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400408;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// (established)
pub mod iio_icrb_c {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400410;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// (established)
pub mod iio_icrb_d {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400418;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// (established)
pub mod iio_ibsa_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410008;
}
/// (established)
pub mod iio_ibda_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410010;
}
/// (established)
pub mod iio_ibsa_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420008;
}
/// (established)
pub mod iio_ibda_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420010;
}
/// (established)
pub mod iio_ibna_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420020;
}
/// (established)
pub mod ni_scratch_reg0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600100;
}
/// (established)
pub mod ni_scratch_reg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600108;
}
/// (established)
pub mod ni_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600208;
}
/// (established)
pub mod ni_vector_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600210;
}
/// (established)
pub mod ni_vector_read_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600310;
}
/// (established)
pub mod ni_meta_table0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638000;
}
/// (established)
pub mod ni_local_table0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638100;
}
pub const HUB_IFDR_FIX_VALUE_B_6_0: u32 = 0x7f; // inferred
pub const HUB_PIOMAP_ALLOC_B_3_0: u32 = 0xf; // inferred
pub const HUB_PIOMAP_ALLOC_B_4_0: u32 = 0x1f; // inferred
pub const HUB_PIOMAP_ALLOC_B_7_0: u32 = 0xff; // inferred
pub const HUB_PIOMAP_ALLOC_V_300: u32 = 0x300; // inferred
pub const HUB_REPLY_QUEUE_DEPTH_B_6_0: u32 = 0x7f; // inferred
pub const HUB_REV_WAR_CTRL_V_100: u32 = 0x100; // inferred
pub const IIO_IBCN_V_2: u32 = 0x2; // inferred
pub const IIO_ICRB_A_B_0: u32 = 0x1; // inferred
pub const IIO_ICRB_A_B_2_0: u32 = 0x7; // inferred
pub const IIO_ICRB_A_B_3_0: u32 = 0xf; // inferred
pub const IIO_ICRB_A_B_4_0: u32 = 0x1f; // inferred
pub const IIO_ICRB_B_B_1_0: u32 = 0x3; // inferred
pub const IIO_ICRB_B_B_4_0: u32 = 0x1f; // inferred
pub const IIO_ICTO_V_FF: u32 = 0xff; // inferred
pub const IIO_ICTP_V_1000: u32 = 0x1000; // inferred
pub const IIO_PRTE_0_B_7_0: u32 = 0xff; // inferred
pub const MD_MEM_ERROR_CLR_B_0: u32 = 0x1; // inferred
pub const MD_MISC_ERROR_CLR_B_9_0: u32 = 0x3ff; // inferred
pub const MD_UREG0_0_B_7_0: u32 = 0xff; // inferred
pub const MD_UREG0_0_V_1: u32 = 0x1; // inferred
pub const MD_UREG0_0_V_1C: u32 = 0x1c; // inferred
pub const MD_UREG0_0_V_7F: u32 = 0x7f; // inferred
pub const MD_UREG0_0_V_8: u32 = 0x8; // inferred
pub const MD_UREG0_0_V_FE: u32 = 0xfe; // inferred
pub const MD_UREG0_1_B_0: u32 = 0x1; // inferred
pub const MD_UREG0_1_B_3: u32 = 0x8; // inferred
pub const MD_UREG0_1_B_4_2_1: u32 = 0x16; // inferred
pub const MD_UREG0_1_B_7_0: u32 = 0xff; // inferred
pub const MD_UREG0_1_V_45: u32 = 0x45; // inferred
pub const MD_UREG0_1_V_80: u32 = 0x80; // inferred
pub const MD_UREG0_1_V_A0: u32 = 0xa0; // inferred
pub const MD_UREG0_1_V_C0: u32 = 0xc0; // inferred
pub const MD_UREG0_1_V_C5: u32 = 0xc5; // inferred
pub const MD_UREG1_0_V_1: u32 = 0x1; // inferred
pub const MD_UREG1_0_V_2: u32 = 0x2; // inferred
pub const MD_UREG1_0_V_23: u32 = 0x23; // inferred
pub const MD_UREG1_0_V_2A: u32 = 0x2a; // inferred
pub const MD_UREG1_0_V_2B: u32 = 0x2b; // inferred
pub const MD_UREG1_0_V_3: u32 = 0x3; // inferred
pub const MD_UREG1_0_V_31: u32 = 0x31; // inferred
pub const MD_UREG1_0_V_35: u32 = 0x35; // inferred
pub const MD_UREG1_0_V_36: u32 = 0x36; // inferred
pub const MD_UREG1_0_V_3F: u32 = 0x3f; // inferred
pub const MD_UREG1_0_V_4: u32 = 0x4; // inferred
pub const MD_UREG1_0_V_46: u32 = 0x46; // inferred
pub const MD_UREG1_0_V_47: u32 = 0x47; // inferred
pub const MD_UREG1_0_V_48: u32 = 0x48; // inferred
pub const MD_UREG1_0_V_5: u32 = 0x5; // inferred
pub const MD_UREG1_0_V_5D: u32 = 0x5d; // inferred
pub const MD_UREG1_0_V_81: u32 = 0x81; // inferred
pub const MD_UREG1_0_V_83: u32 = 0x83; // inferred
pub const MD_UREG1_0_V_84: u32 = 0x84; // inferred
pub const MD_UREG1_0_V_97: u32 = 0x97; // inferred
pub const MD_UREG1_0_V_A: u32 = 0xa; // inferred
pub const MD_UREG1_0_V_A6: u32 = 0xa6; // inferred
pub const MD_UREG1_0_V_B: u32 = 0xb; // inferred
pub const MD_UREG1_0_V_B4: u32 = 0xb4; // inferred
pub const MD_UREG1_0_V_C: u32 = 0xc; // inferred
pub const MD_UREG1_0_V_CF: u32 = 0xcf; // inferred
pub const MD_UREG1_0_V_F: u32 = 0xf; // inferred
pub const MD_UREG1_0_V_F3: u32 = 0xf3; // inferred
pub const MD_UREG1_0_V_FC: u32 = 0xfc; // inferred
pub const PI_ERR_STACK_ADDR_A_B_8: u32 = 0x100; // inferred
pub const PI_INT_PEND1_B_0: u32 = 0x1; // inferred
pub const PI_PROF_EN_B_V_1: u32 = 0x1; // inferred
pub const PI_REGION_PRESENT_V_1: u32 = 0x1; // inferred
pub const PI_RT_COMPARE_A_V_1: u32 = 0x1; // inferred
pub const PI_RT_COMPARE_A_V_2: u32 = 0x2; // inferred
pub const PI_RT_COMPARE_A_V_2A: u32 = 0x2a; // inferred
pub const PI_RT_COMPARE_A_V_2B: u32 = 0x2b; // inferred
pub const PI_RT_COMPARE_A_V_3: u32 = 0x3; // inferred
pub const PI_RT_COMPARE_A_V_35: u32 = 0x35; // inferred
pub const PI_RT_COMPARE_A_V_36: u32 = 0x36; // inferred
pub const PI_RT_COMPARE_A_V_4: u32 = 0x4; // inferred
pub const PI_RT_COMPARE_A_V_5: u32 = 0x5; // inferred
pub const PI_RT_COMPARE_A_V_5D: u32 = 0x5d; // inferred
pub const PI_RT_COMPARE_A_V_5E: u32 = 0x5e; // inferred
pub const PI_RT_COMPARE_A_V_5F: u32 = 0x5f; // inferred
pub const PI_RT_COMPARE_A_V_60: u32 = 0x60; // inferred
pub const PI_RT_COMPARE_A_V_81: u32 = 0x81; // inferred
pub const PI_RT_COMPARE_A_V_83: u32 = 0x83; // inferred
pub const PI_RT_COMPARE_A_V_84: u32 = 0x84; // inferred
pub const PI_RT_COMPARE_A_V_A: u32 = 0xa; // inferred
pub const PI_RT_COMPARE_A_V_A6: u32 = 0xa6; // inferred
pub const PI_RT_COMPARE_A_V_B: u32 = 0xb; // inferred
pub const PI_RT_COMPARE_A_V_B4: u32 = 0xb4; // inferred
pub const PI_RT_COMPARE_A_V_C: u32 = 0xc; // inferred
pub const PI_RT_COUNT_B_11_0: u32 = 0xfff; // inferred
pub const PI_RT_EN_A_V_1: u32 = 0x1; // inferred
