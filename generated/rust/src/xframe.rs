// @generated from devices/xframe/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 3f1ba58411bf364f6941e22e5f572e709f77f3c0d7ce1256a016fceffaeb02e0
// Neterion Xframe 10-Gigabit Ethernet controller (SGI 10-Gigabit Ethernet card), the offsets, bits and layouts the held sources establish
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const ADAPTER_STATUS_RMAC_LOCAL_FAULT: u64 = 0x100000000000000; // inferred
pub const ADAPTER_STATUS_RMAC_REMOTE_FAULT: u64 = 0x200000000000000; // inferred
pub const DESCRIPTOR_PAGE_BYTES: u32 = 0x1000; // inferred
pub const DMA_CHANNELS: u32 = 0x10; // established
pub const GENERAL_INT_MASK_ENABLE: u32 = 0x0; // inferred
pub const MAC_RMAC_ERR_REG_OFFSET: u32 = 0x2028; // inferred
pub const MAC_RMAC_LINK_STATE_CHANGE: u64 = 0x100000000; // inferred
pub const PIC_INT_MASK_OFFSET: u32 = 0x808; // inferred
pub const PIC_INT_TX: u64 = 0x8000000000000000; // inferred
pub const RING_MODE_1: u32 = 0x0; // inferred
pub const RING_MODE_3: u32 = 0x1; // inferred
pub const RING_MODE_5: u32 = 0x2; // inferred
pub const RXD_FIVE_BUFFER_BYTES: u32 = 0x40; // inferred
pub const RXD_FIVE_BUFFER_CONTROL_WORDS: u32 = 0x3; // inferred
pub const RXD_FIVE_BUFFER_POINTERS: u32 = 0x5; // inferred
pub const SCHEDULED_INT_CTRL_OFFSET: u32 = 0x918; // inferred
pub const SCHED_INT_CTRL_TIMER_EN: u64 = 0x8000000000000000; // inferred
pub const SWAPPER_CTRL_HIGH_OFFSET: u32 = 0x90c; // established
pub const SWAPPER_CTRL_HIGH_VALUE: u32 = 0xffffeaff; // established
pub const SWAPPER_CTRL_LOW_OFFSET: u32 = 0x908; // established
pub const SWAPPER_CTRL_LOW_VALUE: u32 = 0xabffbfff; // established
pub const TXD_WORDS: u32 = 0x4; // inferred
pub const TXPIC_INT_MASK_OFFSET: u32 = 0x818; // inferred
pub const TXPIC_INT_REG_OFFSET: u32 = 0x810; // inferred
pub const WATCHDOG_CHECK_SECONDS: u32 = 0x1; // inferred
pub const WATCHDOG_RESET_COUNT: u32 = 0xf; // inferred
