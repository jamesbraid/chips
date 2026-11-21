// generated from devices/ds1744/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 b5d17eac59842695d624daaad596f06b877f17bfefcdbbe686446be878c5d4fe
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
