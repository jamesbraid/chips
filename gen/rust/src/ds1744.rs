// generated from defs/ds1744.toml by defs-gen - do not edit, change the source
// Dallas DS1744 nonvolatile timekeeping SRAM (32 KiB, byte-wide, with clock)
#![allow(dead_code)]

/// Battery-backed RAM below the clock bytes. The sources give no layout inside it. The 32,760 is inferred from the clock placement, not stated by a sourc (inferred)
pub mod ram {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 32760;
    pub const STRIDE: u64 = 1;
}
/// The eight clock and calendar bytes at the top of the chip. The sources give their order and bit meanings only through the chip's own register page, wh (established)
pub mod clock {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7ff8;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 1;
}
