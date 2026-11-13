// generated from devices/heart/registers.toml by defs-gen - do not edit, change the source
// HEART (Octane system controller)
#![allow(dead_code)]

/// (established)
pub mod mode {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x0;
}
/// (established)
pub mod mem_arb {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod memcfg0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod memcfg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x28;
}
/// (established)
pub mod memcfg2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30;
}
/// (established)
pub mod memcfg3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38;
}
/// (established)
pub mod fc_mode {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40;
}
/// (established)
pub mod fc_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x48;
}
/// (established)
pub mod fc0_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50;
}
/// (established)
pub mod fc0_count {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60;
}
/// (established)
pub mod status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod berr_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x88;
}
/// (established)
pub mod berr_misc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod mem_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x98;
}
/// (established)
pub mod bad_mem {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod piu_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa8;
}
/// (established)
pub mod imr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10000;
}
/// (established)
pub mod imr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10008;
}
/// (established)
pub mod imr2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10010;
}
/// (established)
pub mod imr3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10018;
}
/// (established)
pub mod set_isr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10020;
}
/// (established)
pub mod clr_isr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10028;
}
/// (established)
pub mod isr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10030;
}
/// (established)
pub mod imsr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10038;
}
/// (established)
pub mod cause {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10040;
}
/// (established)
pub mod count {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20000;
}
/// (established)
pub mod trigger {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40000;
}
/// (established)
pub mod prid {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50000;
}
/// (established)
pub mod sync {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60000;
}
/// (established)
pub mod wid_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100000;
}
/// (established)
pub mod wid_err_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100010;
}
/// (established)
pub mod wid_err_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100018;
}
/// (established)
pub mod wid_req_timeout {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100028;
}
/// (established)
pub mod wid_err_cmdword {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100040;
}
/// (established)
pub mod wid_err_type {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100060;
}
/// (established)
pub mod wid_err_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100068;
}
/// (established)
pub mod wid_pio_err_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100070;
}
/// (established)
pub mod wid_pio_err_lower {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100078;
}
/// (established)
pub mod wid_pio_rto_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100090;
}
pub const CAUSE_B_0: u32 = 0x1; // inferred
pub const CAUSE_B_1: u32 = 0x2; // inferred
pub const CAUSE_B_1_0: u32 = 0x3; // inferred
pub const CAUSE_V_1: u32 = 0x1; // inferred
pub const COUNT_B_11_0: u32 = 0xfff; // inferred
pub const FC_MODE_V_45: u32 = 0x45; // inferred
pub const IMR3_V_1: u32 = 0x1; // inferred
pub const MEM_ARB_V_100000: u32 = 0x100000; // inferred
pub const MODE_B_3_0: u32 = 0xf; // inferred
pub const MODE_V_200000: u32 = 0x200000; // inferred
pub const MODE_V_400000: u32 = 0x400000; // inferred
pub const STATUS_B_11: u32 = 0x800; // inferred
pub const STATUS_B_3_0: u32 = 0xf; // inferred
pub const STATUS_B_7_4: u32 = 0xf0; // inferred
pub const WID_ERR_MASK_V_2C07: u32 = 0x2c07; // inferred
pub const WID_ERR_MASK_V_3FF60000: u32 = 0x3ff60000; // inferred
pub const WID_REQ_TIMEOUT_V_80: u32 = 0x80; // inferred
