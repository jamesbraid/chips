// @generated from devices/r10000_identity/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 d2842a5c402c77293eed3a25235d7f9e4e9e93075e76f5b4f972fabfc15d48aa
// R10000 family processor identity and secondary-cache configuration fields
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const R10K_CONF_SB_BIT: u32 = 0xd; // established
pub const R10K_CONF_SB_MASK: u32 = 0x2000; // established
pub const R10K_CONF_SS_MASK: u32 = 0x70000; // established
pub const R10K_CONF_SS_SHIFT: u32 = 0x10; // established
pub const R10K_IMP_R10000: u32 = 0x9; // established
pub const R10K_IMP_R12000: u32 = 0xe; // established
pub const R10K_IMP_R14000: u32 = 0xf; // established
pub const R10K_PRID_IMP_MASK: u32 = 0xff00; // established
pub const R10K_PRID_IMP_SHIFT: u32 = 0x8; // established
pub const R10K_PRID_REV_MASK: u32 = 0xff; // established
pub const R10K_R16000_DISPLAY_MAJOR_OFFSET: u32 = 0x2; // inferred
pub const R10K_R16000_PRID_1GHZ: u32 = 0xf50; // inferred
pub const R10K_R16000_REV_MAJOR_MIN: u32 = 0x3; // established
pub const R10K_R16000_TLB_ENTRIES: u32 = 0x40; // inferred
pub const R10K_SCACHE_LINE_BASE_BYTES: u32 = 0x40; // established
pub const R10K_SCACHE_SIZE_UNIT: u32 = 0x80000; // established
pub const R10K_SCACHE_WAYS: u32 = 0x2; // established
