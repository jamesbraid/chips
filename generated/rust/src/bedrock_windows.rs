// generated from devices/bedrock_windows/registers.toml by defs-gen - do not edit, change the source
// Bedrock register arrays whose extent is a fact of its own
#![allow(dead_code)]

/// The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then  (established)
pub mod gfx_window {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300;
    pub const COUNT: u32 = 10;
    pub const STRIDE: u64 = 8;
}
