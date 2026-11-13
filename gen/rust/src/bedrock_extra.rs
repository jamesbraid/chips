// generated from defs/bedrock_extra.toml by defs-gen - do not edit, change the source
// Hub and Bedrock network-controller registers outside the census
#![allow(dead_code)]

/// (established)
pub mod ii_widget_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400008;
}
/// (established)
pub mod ii_shutdown_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4001e8;
}
/// (established)
pub mod ii_error_header_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400220;
}
/// (established)
pub mod ii_error_header_2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400228;
}
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
pub const II_ERROR_HEADER_1_COMMAND: u32 = 0x7f; // established
pub const II_ERROR_HEADER_1_ERR_TYPE: u64 = 0xf00000000; // established
pub const II_ERROR_HEADER_1_OVERRUN: u64 = 0x10000000000; // established
pub const II_ERROR_HEADER_1_PRINT_GATE: u64 = 0x100000000000; // established
pub const II_ERROR_HEADER_1_SOURCE: u32 = 0x7ff00000; // established
pub const II_ERROR_HEADER_1_SUPPLEMENTAL: u32 = 0x7ff00; // established
pub const II_ERROR_HEADER_2_ADDRESS: u64 = 0x3fffffffff; // established
pub const II_ERROR_HEADER_2_TAIL: u64 = 0x10000000000; // established
pub const II_READ_RESP_PRESCALE_B_54_32: u64 = 0x7fffff00000000; // established
pub const II_READ_RESP_TIMEOUT_B_59_55: u64 = 0xf80000000000000; // established
pub const II_TAIL_TIMEOUT: u32 = 0x4001f0; // established
pub const II_WIDGET_STATUS_CREDIT_TIMEOUT: u32 = 0x10; // established
pub const II_WIDGET_STATUS_ERROR: u64 = 0x100000000; // established
pub const II_WIDGET_STATUS_RETRY_TIMEOUT: u32 = 0x200; // established
pub const II_WIDGET_STATUS_TAIL_TIMEOUT: u32 = 0x20; // established
pub const MEM_BANK_CONFIG_BANK_SELECT: u64 = 0x300000000; // established
pub const MEM_BANK_CONFIG_B_58_56: u64 = 0x700000000000000; // established
pub const MEM_BANK_CONFIG_LANE_ENABLE: u32 = 0x3; // established
pub const MEM_BANK_CONFIG_LANE_SIZE: u32 = 0xf0; // established
pub const NIC_ACCESS_HUB_PHYS_LOW: u32 = 0x1e04030; // established
pub const NODE_SHIFT: u32 = 0x21; // established
pub const PI_ERROR_SPOOL_SIZE_BASE: u32 = 0x1000; // established
