// generated from devices/hub_windows/registers.toml by defs-gen - do not edit, change the source
// Hub register arrays whose extent is a fact of its own
#![allow(dead_code)]

/// The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then  (established)
pub mod pi_gfx_window {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300;
    pub const COUNT: u32 = 10;
    pub const STRIDE: u64 = 8;
}
/// The sixteen microcontroller and UART 1 registers as one array. They are also listed one by one under their own names; this is the same storage seen as (established)
pub mod md_ureg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220080;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
