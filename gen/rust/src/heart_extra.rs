// generated from defs/heart_extra.toml by defs-gen - do not edit, change the source
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
pub const WIDGET_ERR_LOWER: u32 = 0x78; // established
pub const WIDGET_ERR_TYPE: u32 = 0x60; // established
pub const WIDGET_ERR_UPPER: u32 = 0x70; // established
pub const WIDGET_RD_TIMEOUT_LATCH: u32 = 0x90; // established
pub const WIDGET_REQ_TIMEOUT: u32 = 0x28; // established
