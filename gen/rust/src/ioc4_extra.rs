// generated from defs/ioc4_extra.toml by defs-gen - do not edit, change the source
// IOC4 registers outside the census
#![allow(dead_code)]

/// (established)
pub mod km_rx_kbd {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x204;
}
/// (established)
pub mod km_rx_mouse {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x208;
}
/// (established)
pub mod km_tx_kbd {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20c;
}
/// (established)
pub mod km_tx_mouse {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x210;
}
pub const ATA_DMA_CONTROL: u32 = 0x15c; // established
pub const ATA_DMA_CONTROL_ACTIVE: u32 = 0x8; // established
pub const ATA_DMA_CONTROL_DIR_TO_MEMORY: u32 = 0x4; // inferred
pub const ATA_DMA_CONTROL_ERROR: u32 = 0x10; // established
pub const ATA_DMA_CONTROL_START: u32 = 0x1; // established
pub const ATA_DMA_CONTROL_STOP: u32 = 0x2; // established
pub const ATA_DMA_COUNT_DEVICE: u32 = 0x154; // inferred
pub const ATA_DMA_COUNT_MEMORY: u32 = 0x158; // inferred
pub const ATA_DMA_CURRENT_HIGH: u32 = 0x150; // unknown
pub const ATA_DMA_CURRENT_LOW: u32 = 0x14c; // unknown
pub const ATA_DMA_END_AREA: u32 = 0x160; // inferred
pub const ATA_DMA_LIST_HIGH: u32 = 0x148; // inferred
pub const ATA_DMA_LIST_LOW: u32 = 0x144; // inferred
pub const ATA_DMA_TIMING: u32 = 0x140; // inferred
pub const SIO_CR_CMD_PULSE: u32 = 0xf; // established
pub const SIO_CR_SIO_DIAG_IDLE: u32 = 0x80; // established
