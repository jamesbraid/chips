// generated from defs/ds1742.toml by defs-gen - do not edit, change the source
// Dallas DS1742W nonvolatile timekeeping RAM (Fuel L1 storage part, 3.3 V, 2 KiB)
#![allow(dead_code)]

/// Battery-backed RAM below the clock bytes. The sources give no RAM count and no layout inside it. The 2,040 is inferred from the clock placement, not s (inferred)
pub mod ram {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 2040;
    pub const STRIDE: u64 = 1;
}
/// The eight clock and calendar bytes at the top of the chip. The sources give their order and bit meanings only through the chip's own register page, wh (established)
pub mod clock {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7f8;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 1;
}
