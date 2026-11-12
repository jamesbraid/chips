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
pub const SERIAL_RING_PTR_B_9_3: u32 = 0x3f8; // inferred
pub const SERIAL_RX_TIMER_COUNT_B_27_16: u32 = 0xfff0000; // inferred
pub const SERIAL_RX_TIMER_RELOAD_B_11_0: u32 = 0xfff; // inferred
pub const SERIAL_SHADOW_CTS_V_100000: u32 = 0x100000; // inferred
pub const SERIAL_SHADOW_DCD_V_800000: u32 = 0x800000; // inferred
pub const SERIAL_SHADOW_DCTS_V_10000: u32 = 0x10000; // inferred
pub const SERIAL_SHADOW_DDCD_V_80000: u32 = 0x80000; // inferred
pub const SERIAL_SHADOW_OUTPUTS_B_28_24: u32 = 0x1f000000; // inferred
pub const SERIAL_SHADOW_RX_FLAGS_B_7_0: u32 = 0xff; // inferred
pub const SERIAL_SRCIR_TIMER_ARM_V_80000000: u32 = 0x80000000; // inferred
pub const SIO_CR_CMD_PULSE: u32 = 0xf; // established
pub const SIO_CR_SIO_DIAG_IDLE: u32 = 0x80; // established
