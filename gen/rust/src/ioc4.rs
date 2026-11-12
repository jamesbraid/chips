// generated from defs/ioc4.toml by defs-gen - do not edit, change the source
// IOC4 (PCI I/O controller, later)
#![allow(dead_code)]

/// (established)
pub mod pci_err_addr_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
}
/// (established)
pub mod pci_err_addr_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
}
/// (established)
pub mod sio_ir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
}
/// (established)
pub mod other_ir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc;
}
/// (established)
pub mod sio_ies {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// (established)
pub mod other_ies {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14;
}
/// (established)
pub mod sio_iec {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod other_iec {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
}
/// (established)
pub mod sio_cr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod ioc4_attach {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x24;
}
/// (established)
pub mod int_out {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// (established)
pub mod gpcr_s {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
/// (established)
pub mod gpcr_c {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
}
/// (established)
pub mod gppr0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
}
/// (established)
pub mod km_csr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200;
}
/// (established)
pub mod sbbr01_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x300;
}
/// (established)
pub mod sbbr01_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x304;
}
/// (established)
pub mod sbbr23_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x308;
}
/// (established)
pub mod sbbr23_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30c;
}
/// (established)
pub mod port0_sscr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x310;
}
/// (established)
pub mod port0_stpir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x314;
}
/// (established)
pub mod port0_stcir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x318;
}
/// (established)
pub mod port0_srpir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x31c;
}
/// (established)
pub mod port0_srcir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x320;
}
/// (established)
pub mod port0_srtr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x324;
}
/// (established)
pub mod port0_shadow {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x328;
}
/// (established)
pub mod uart0_reg0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x380;
}
/// (established)
pub mod uart0_reg4 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x384;
}
/// (established)
pub mod cfg_id {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x200000;
}
/// (established)
pub mod cfg_command_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200004;
}
/// (established)
pub mod cfg_revision {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200008;
}
pub const CFG_COMMAND_STATUS_B_0: u32 = 0x1; // inferred
pub const CFG_COMMAND_STATUS_B_1: u32 = 0x2; // inferred
pub const CFG_COMMAND_STATUS_B_15_0: u32 = 0xffff; // inferred
pub const CFG_COMMAND_STATUS_V_146: u32 = 0x146; // inferred
pub const CFG_REVISION_B_7_0: u32 = 0xff; // inferred
pub const GPCR_C_V_2: u32 = 0x2; // inferred
pub const GPCR_S_V_200: u32 = 0x200; // inferred
pub const GPCR_S_V_FF00: u32 = 0xff00; // inferred
pub const OTHER_IR_V_40: u32 = 0x40; // inferred
pub const OTHER_IR_V_FF800000: u32 = 0xff800000; // inferred
pub const PCI_ERR_ADDR_L_B_0: u32 = 0x1; // inferred
pub const PCI_ERR_ADDR_L_B_1: u32 = 0x2; // inferred
pub const PCI_ERR_ADDR_L_B_3_0: u32 = 0xf; // inferred
pub const PCI_ERR_ADDR_L_B_3_1: u32 = 0xe; // inferred
pub const PCI_ERR_ADDR_L_B_5: u32 = 0x20; // inferred
pub const PORT0_SRCIR_V_80000000: u32 = 0x80000000; // inferred
pub const PORT0_SRPIR_B_11_3: u32 = 0xff8; // inferred
pub const PORT0_SRTR_V_A0: u32 = 0xa0; // inferred
pub const PORT0_SSCR_V_20000000: u32 = 0x20000000; // inferred
pub const PORT0_SSCR_V_8000000: u32 = 0x8000000; // inferred
pub const PORT0_SSCR_V_80000000: u32 = 0x80000000; // inferred
pub const PORT0_STCIR_B_11_3: u32 = 0xff8; // inferred
pub const SBBR01_L_V_1: u32 = 0x1; // inferred
pub const SBBR23_L_V_1: u32 = 0x1; // inferred
pub const SIO_CR_B_7: u32 = 0x80; // inferred
pub const SIO_CR_V_F: u32 = 0xf; // inferred
pub const SIO_IR_B_0: u32 = 0x1; // inferred
pub const UART0_REG0_V_1: u32 = 0x1; // inferred
pub const UART0_REG0_V_3: u32 = 0x3; // inferred
pub const UART0_REG0_V_4: u32 = 0x4; // inferred
pub const UART0_REG0_V_40: u32 = 0x40; // inferred
pub const UART0_REG0_V_7: u32 = 0x7; // inferred
pub const UART0_REG0_V_80: u32 = 0x80; // inferred
pub const UART0_REG4_B_5: u32 = 0x20; // inferred
