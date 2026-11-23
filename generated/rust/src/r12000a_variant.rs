// @generated from devices/r12000a_variant/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 4df134dc1016e8cf057c55413f2b161f333b9b165e5097b4b0016efb318a1b37
// R12000A mode-bit fields and performance control 0 syndrome field
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const R12KA_MODE_HSTL_MASK: u32 = 0x60000000; // established
pub const R12KA_MODE_HSTL_SHIFT: u32 = 0x1d; // established
pub const R12KA_MODE_SCCLKDIV_MASK: u32 = 0x380000; // established
pub const R12KA_MODE_SCCLKDIV_SHIFT: u32 = 0x13; // established
pub const R12KA_MODE_SCCLKDIV_TEST_CODE: u32 = 0x7; // established
pub const R12KA_MODE_SYSCLKDIV_CODE_A_ONLY: u32 = 0xc; // established
pub const R12KA_MODE_SYSCLKDIV_MASK: u32 = 0x1e00; // established
pub const R12KA_MODE_SYSCLKDIV_SHIFT: u32 = 0x9; // established
pub const R12KA_PERF_CTL0_SYNDROME_MASK: u32 = 0xff800000; // established
pub const R12KA_PERF_CTL0_SYNDROME_SHIFT: u32 = 0x17; // established
