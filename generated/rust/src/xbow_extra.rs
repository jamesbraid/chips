// @generated from devices/xbow/registers-extra.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 5d0eaa0d4362a4e57ae74a9515b91ea99d1ae0b25cbc4f8dbf94696f4a778ea6
// Xbow registers outside the census
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// (established)
pub mod perf_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x60;
}
/// (established)
pub mod perf_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x68;
}
/// (inferred)
pub mod link_f_arb_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2d8;
}
pub const FENCE_LINK_8: u32 = 0x80; // inferred
pub const FENCE_LINK_9: u32 = 0x88; // inferred
pub const FENCE_LINK_A: u32 = 0x90; // inferred
pub const FENCE_LINK_B: u32 = 0x98; // inferred
pub const FENCE_LINK_C: u32 = 0xa0; // inferred
pub const FENCE_LINK_D: u32 = 0xa8; // inferred
pub const FENCE_LINK_E: u32 = 0xb0; // inferred
pub const FENCE_LINK_F: u32 = 0xb8; // inferred
pub const FENCE_WIDGET_0: u32 = 0x78; // inferred
pub const FLUSH_LINK_8: u32 = 0x100; // established
pub const FLUSH_LINK_9: u32 = 0x140; // established
pub const FLUSH_LINK_A: u32 = 0x180; // established
pub const FLUSH_LINK_B: u32 = 0x1c0; // established
pub const FLUSH_LINK_C: u32 = 0x200; // established
pub const FLUSH_LINK_D: u32 = 0x240; // established
pub const FLUSH_LINK_E: u32 = 0x280; // established
pub const FLUSH_LINK_F: u32 = 0x2c0; // established
pub const ID_MFR_MASK: u32 = 0xffe; // established
pub const ID_PART_MASK: u32 = 0xffff000; // established
pub const ID_REV_MASK: u32 = 0xf0000000; // established
pub const PART_PXBOW: u32 = 0xd100; // established
pub const PART_XBOW: u32 = 0x0; // established
pub const PART_XXBOW: u32 = 0xd000; // established
pub const PERF_A_B_19_0: u32 = 0xfffff; // established
pub const PERF_A_B_22_20: u32 = 0x700000; // established
pub const PERF_B_B_19_0: u32 = 0xfffff; // established
pub const PERF_B_B_22_20: u32 = 0x700000; // established
pub const PROM_CROSSBAR_LOCK_BIT: u32 = 0x2; // inferred
pub const RESOURCE_LOCK: u32 = 0xc0; // inferred
pub const RESOURCE_LOCK_CLEAR: u32 = 0xc8; // inferred
pub const REV_CODE_1: u32 = 0x1; // established
pub const REV_CODE_2: u32 = 0x2; // established
pub const REV_CODE_3: u32 = 0x3; // established
pub const REV_CODE_4: u32 = 0x4; // established
pub const REV_CODE_5: u32 = 0x5; // established
