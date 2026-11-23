// @generated from devices/bedrock/registers-extra.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 66f55031d6b9d645d30480ba1e0a6af5318d45684c099683530c5dd69e1b2d79
// Hub and Bedrock network-controller registers outside the census
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// (established)
pub mod node_region_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1000018;
}
/// (established)
pub mod mem_bank_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1f80008;
}
pub const II_CREDIT_TIMEOUT: u32 = 0x4001e0; // established
pub const II_READ_RESP_PRESCALE_B_54_32: u64 = 0x7fffff00000000; // established
pub const II_READ_RESP_TIMEOUT_B_59_55: u64 = 0xf80000000000000; // established
pub const II_TAIL_TIMEOUT: u32 = 0x4001f0; // established
pub const MEM_BANK_CONFIG_BANK_SELECT: u64 = 0x300000000; // established
pub const MEM_BANK_CONFIG_B_58_56: u64 = 0x700000000000000; // established
pub const MEM_BANK_CONFIG_LANE_ENABLE: u32 = 0x3; // established
pub const MEM_BANK_CONFIG_LANE_SIZE: u32 = 0xf0; // established
pub const NIC_ACCESS_HUB_PHYS_LOW: u32 = 0x1e04030; // established
pub const NODE_SHIFT: u32 = 0x21; // established
pub const PI_ERROR_SPOOL_SIZE_BASE: u32 = 0x1000; // established
