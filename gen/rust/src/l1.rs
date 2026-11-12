// generated from defs/l1.toml by defs-gen - do not edit, change the source
// L1 system controller UART path (node-local window), Origin 3000 family
#![allow(dead_code)]

/// (established)
pub mod uart_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod uart_ier {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x88;
}
/// (established)
pub mod uart_fcr_iir {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod uart_lcr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x98;
}
/// (established)
pub mod uart_mcr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod uart_lsr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa8;
}
/// (established)
pub mod uart_intr_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x800090;
}
/// (established)
pub mod uart_intr_pending {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x800098;
}
pub const UART_DATA_B_7_0: u32 = 0xff; // inferred
pub const UART_DATA_V_44: u32 = 0x44; // inferred
pub const UART_DATA_V_7E: u32 = 0x7e; // inferred
pub const UART_FCR_IIR_B_1: u32 = 0x2; // inferred
pub const UART_FCR_IIR_B_2: u32 = 0x4; // inferred
pub const UART_FCR_IIR_B_2_1: u32 = 0x6; // inferred
pub const UART_FCR_IIR_B_7_0: u32 = 0xff; // inferred
pub const UART_FCR_IIR_V_7: u32 = 0x7; // inferred
pub const UART_IER_B_7_0: u32 = 0xff; // inferred
pub const UART_INTR_PENDING_B_4: u32 = 0x10; // inferred
pub const UART_LCR_B_7_0: u32 = 0xff; // inferred
pub const UART_LSR_B_0: u32 = 0x1; // inferred
pub const UART_LSR_B_15_0: u32 = 0xffff; // inferred
pub const UART_LSR_B_3_2: u32 = 0xc; // inferred
pub const UART_LSR_B_3_2_0: u32 = 0xd; // inferred
pub const UART_LSR_B_5: u32 = 0x20; // inferred
pub const UART_LSR_B_6: u32 = 0x40; // inferred
pub const UART_LSR_B_7_0: u32 = 0xff; // inferred
