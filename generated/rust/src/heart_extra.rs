// generated from devices/heart/registers-extra.toml by defs-gen - do not edit, change the source
// HEART registers outside the census
#![allow(dead_code)]

/// (established)
pub mod sdram_mode {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x8;
}
/// (established)
pub mod mem_ref {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10;
}
/// (inferred)
pub mod mlan_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb8;
}
pub const MEMCFG_ADDR_MASK: u32 = 0x1ff; // inferred
pub const MEMCFG_SIZE_MASK: u32 = 0x3f0000; // inferred
pub const MEMCFG_SIZE_SHIFT: u32 = 0x10; // inferred
pub const MEMCFG_UNIT_SHIFT: u32 = 0x19; // inferred
pub const MEMCFG_VALID: u32 = 0x80000000; // inferred
pub const MLAN_DATA_SHIFT: u32 = 0x2; // inferred
pub const MLAN_DONE: u32 = 0x2; // inferred
pub const MLAN_PULSE_SHIFT: u32 = 0xa; // inferred
pub const MLAN_SAMPLE: u32 = 0x1; // inferred
pub const WIDGET_ERR_LOWER: u32 = 0x78; // established
pub const WIDGET_ERR_TYPE: u32 = 0x60; // established
pub const WIDGET_ERR_UPPER: u32 = 0x70; // established
pub const WIDGET_RD_TIMEOUT_LATCH: u32 = 0x90; // established
pub const WIDGET_REQ_TIMEOUT: u32 = 0x28; // established
