// generated from devices/ds1742/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 b5672543306ae2503fda41b02a00f5048d44954b349878d975e681f37ea3002a
// Dallas DS1742W nonvolatile timekeeping RAM (Fuel L1 storage part, 3.3 V, 2 KiB)
#![allow(dead_code)]

/// Battery-backed RAM below the clock bytes. The sources give no RAM count and no layout inside it. The 2,040 is inferred from the clock placement, not s (inferred)
pub mod ram {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 2040;
    pub const STRIDE: u64 = 1;
}
/// The eight clock and calendar bytes at the top of the chip. Table 2 (p. 5) gives their order and bit meanings, which the device README transcribes; thi (established)
pub mod clock {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7f8;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 1;
}
