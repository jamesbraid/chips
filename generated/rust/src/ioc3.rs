// @generated from devices/ioc3/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 b54d0ad6199ff74e5b74165da237d6bb27310e0e5dd68c0108216525798dd463
// IOC3 (PCI I/O controller)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// (established)
pub mod sio_ir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
}
/// (established)
pub mod sio_ies {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod sio_iec {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x24;
}
/// (established)
pub mod sio_cr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// (established)
pub mod int_out {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2c;
}
/// (established)
pub mod gpcr_s {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
}
/// (established)
pub mod gpcr_c {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x38;
}
/// (established)
pub mod gppr0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
}
/// (established)
pub mod gppr5 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x54;
}
/// (established)
pub mod ppbr_h_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod ppbr_l_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x84;
}
/// (established)
pub mod ppcr_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
}
/// (established)
pub mod ppcr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8c;
}
/// (established)
pub mod ppbr_h_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod ppbr_l_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x94;
}
/// (established)
pub mod ppcr_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x98;
}
/// (established)
pub mod km_csr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x9c;
}
/// (established)
pub mod sbbr_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb0;
}
/// (established)
pub mod sbbr_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb4;
}
/// (established)
pub mod port_a_stpir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xbc;
}
/// (established)
pub mod port_a_stcir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc0;
}
/// (established)
pub mod port_a_srpir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc4;
}
/// (established)
pub mod port_a_srcir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc8;
}
/// (established)
pub mod port_a_srtr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xcc;
}
/// (established)
pub mod port_a_shadow {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xd0;
}
/// (established)
pub mod emcr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xf0;
}
/// (established)
pub mod eisr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xf4;
}
/// (established)
pub mod eier {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xf8;
}
/// (established)
pub mod ercsr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xfc;
}
/// (established)
pub mod erbr_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100;
}
/// (established)
pub mod erbr_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x104;
}
/// (established)
pub mod erbar {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x108;
}
/// (established)
pub mod ercir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10c;
}
/// (established)
pub mod erpir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x110;
}
/// (established)
pub mod ertr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x114;
}
/// (established)
pub mod etcsr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x118;
}
/// (established)
pub mod ersr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x11c;
}
/// (established)
pub mod etcdc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x120;
}
/// (established)
pub mod ebir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x124;
}
/// (established)
pub mod etbr_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x128;
}
/// (established)
pub mod etbr_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x12c;
}
/// (established)
pub mod etcir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x130;
}
/// (established)
pub mod etpir {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x134;
}
/// (established)
pub mod emar_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x138;
}
/// (established)
pub mod emar_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x13c;
}
/// (established)
pub mod ehar_h {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x140;
}
/// (established)
pub mod ehar_l {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x144;
}
/// (established)
pub mod micr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x148;
}
/// (established)
pub mod midr_r {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14c;
}
/// (established)
pub mod midr_w {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x150;
}
/// (established)
pub mod pp_dcr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x20152;
}
/// (established)
pub mod pp_ecr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2015a;
}
/// (established)
pub mod uarta_reg0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x20178;
}
/// (established)
pub mod uarta_reg1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x20179;
}
/// (established)
pub mod uarta_reg2 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2017a;
}
/// (established)
pub mod uarta_reg3 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2017b;
}
/// (established)
pub mod uarta_reg4 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2017c;
}
/// (established)
pub mod uarta_reg5 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2017d;
}
/// (established)
pub mod uarta_reg7 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2017f;
}
/// (established)
pub mod cfg_command {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200004;
}
/// (established)
pub mod cfg_revision {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200008;
}
/// (established)
pub mod cfg_latency {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20000c;
}
/// (established)
pub mod cfg_error_addr_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200040;
}
/// (established)
pub mod cfg_error_addr_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200044;
}
pub const CFG_COMMAND_V_8146: u32 = 0x8146; // inferred
pub const CFG_ERROR_ADDR_LO_B_0: u32 = 0x1; // inferred
pub const CFG_ERROR_ADDR_LO_B_3_0: u32 = 0xf; // inferred
pub const CFG_LATENCY_V_2800: u32 = 0x2800; // inferred
pub const CFG_LATENCY_V_FF00: u32 = 0xff00; // inferred
pub const CFG_REVISION_B_7_0: u32 = 0xff; // inferred
pub const EMCR_V_1200: u32 = 0x1200; // inferred
pub const EMCR_V_2: u32 = 0x2; // inferred
pub const EMCR_V_80000000: u32 = 0x80000000; // inferred
pub const EMCR_V_AC: u32 = 0xac; // inferred
pub const ERBAR_V_1000000: u32 = 0x1000000; // inferred
pub const ERCSR_B_8_0: u32 = 0x1ff; // inferred
pub const ETBR_L_V_1: u32 = 0x1; // inferred
pub const ETCDC_B_15_0: u32 = 0xffff; // inferred
pub const ETCIR_B_15_0: u32 = 0xffff; // inferred
pub const GPCR_C_V_2: u32 = 0x2; // inferred
pub const GPCR_S_V_10000: u32 = 0x10000; // inferred
pub const GPCR_S_V_20: u32 = 0x20; // inferred
pub const GPPR5_V_1: u32 = 0x1; // inferred
pub const MICR_B_11: u32 = 0x800; // inferred
pub const MICR_V_400: u32 = 0x400; // inferred
pub const MIDR_R_B_15_0: u32 = 0xffff; // inferred
pub const PORT_A_SRCIR_V_80000000: u32 = 0x80000000; // inferred
pub const PORT_A_SRPIR_B_11_3: u32 = 0xff8; // inferred
pub const PORT_A_SRTR_V_A0: u32 = 0xa0; // inferred
pub const PORT_A_SSCR: u32 = 0xb8; // established
pub const PORT_A_SSCR_V_20000000: u32 = 0x20000000; // inferred
pub const PORT_A_SSCR_V_8000000: u32 = 0x8000000; // inferred
pub const PORT_A_SSCR_V_80000000: u32 = 0x80000000; // inferred
pub const PORT_A_STCIR_B_11_3: u32 = 0xff8; // inferred
pub const PPCR_A_V_40000000: u32 = 0x40000000; // inferred
pub const PPCR_B_V_40000000: u32 = 0x40000000; // inferred
pub const PPCR_V_40000000: u32 = 0x40000000; // inferred
pub const PPCR_V_80000000: u32 = 0x80000000; // inferred
pub const SIO_CR_V_70000: u32 = 0x70000; // inferred
pub const SIO_CR_V_AE5E: u32 = 0xae5e; // inferred
pub const SIO_IEC_V_7F0000: u32 = 0x7f0000; // inferred
pub const SIO_IEC_V_FFFF: u32 = 0xffff; // inferred
pub const SIO_IR_B_0: u32 = 0x1; // inferred
pub const SIO_IR_V_3C0000: u32 = 0x3c0000; // inferred
pub const SIO_IR_V_400000: u32 = 0x400000; // inferred
pub const UARTA_REG2_V_1: u32 = 0x1; // inferred
pub const UARTA_REG2_V_7: u32 = 0x7; // inferred
pub const UARTA_REG3_V_3: u32 = 0x3; // inferred
pub const UARTA_REG3_V_4: u32 = 0x4; // inferred
pub const UARTA_REG3_V_40: u32 = 0x40; // inferred
pub const UARTA_REG3_V_80: u32 = 0x80; // inferred
pub const UARTA_REG5_B_5: u32 = 0x20; // inferred
