// generated from defs/bridge_extra.toml by defs-gen - do not edit, change the source
// Bridge-family registers and bits outside the census
#![allow(dead_code)]

pub const DEVICE_BARRIER: u32 = 0x8000; // established
pub const DEVICE_PRECISE: u32 = 0x20000; // established
pub const DEVICE_PREFETCH: u32 = 0x40000; // established
pub const DEVICE_REALTIME: u32 = 0x200000; // established
pub const DEVICE_SIZE_64: u32 = 0x400000; // established
pub const DEVICE_SWAP_PAIR: u32 = 0x180000; // established
pub const DEVICE_WRITE_GATHER_EN: u32 = 0x1800000; // established
pub const TEST_PIN_CONTROL: u32 = 0x70; // established
pub const TEST_PIN_CONTROL_DATA_OUT: u32 = 0xf00; // established
pub const TEST_PIN_CONTROL_SELECT0: u32 = 0x3; // established
pub const TEST_PIN_CONTROL_SELECT1: u32 = 0xc; // established
pub const TEST_PIN_CONTROL_SELECT2: u32 = 0x30; // established
pub const TEST_PIN_CONTROL_SELECT3: u32 = 0xc0; // established
pub const XBRIDGE_TEST_PIN_CONTROL_DATA_OUT: u32 = 0xff0000; // established
