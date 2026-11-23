// @generated from devices/r10000_diagnostic/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 651edc565a4b7f3c622ffdd35f85c717e6bef176606d4da7a24c00089762d871
// R10000 family CP0 Diagnostic register (branch diagnostic): field positions
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const R10KDIAG_BPIDX_R10K_MASK: u32 = 0xff8; // established
pub const R10KDIAG_BPIDX_R12K_MASK: u32 = 0x3ff8; // established
pub const R10KDIAG_BPMODE_MASK: u32 = 0x30000; // established
pub const R10KDIAG_BPOP_MASK: u32 = 0x3; // established
pub const R10KDIAG_BPSTATE_MASK: u32 = 0xc000; // established
pub const R10KDIAG_DBRC_BIT: u32 = 0x16; // established
pub const R10KDIAG_DBRC_MASK: u32 = 0x400000; // established
pub const R10KDIAG_R12K_BTAC_DIS_BIT: u32 = 0x1b; // established
pub const R10KDIAG_R12K_BTAC_DIS_MASK: u32 = 0x8000000; // established
pub const R10KDIAG_R12K_GHIST_ALL_BIT: u32 = 0x1a; // established
pub const R10KDIAG_R12K_GHIST_COUNT_MASK: u32 = 0x3800000; // established
