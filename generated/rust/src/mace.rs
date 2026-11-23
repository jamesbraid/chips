// @generated from devices/mace/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 46f8c30b055f7f92fd720b4f96d8d6328458907ed9687b8809658c5be263490e
// MACE (O2 I/O ASIC)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// (established)
pub mod pci_err_addr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80000;
}
/// (established)
pub mod pci_err_flags {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80004;
}
/// (established)
pub mod pci_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80008;
}
/// (established)
pub mod pci_flush_rev {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8000c;
}
/// (established)
pub mod pci_config_addr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80cf8;
}
/// (established)
pub mod pci_config_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80cfc;
}
/// (established)
pub mod vout_vhw_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200058;
}
/// (established)
pub mod eth_mac_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x280000;
}
/// (established)
pub mod eth_rx_fifo {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x280040;
}
/// (established)
pub mod eth_internal_ram {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x280100;
}
/// (established)
pub mod aud_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300000;
}
/// (established)
pub mod aud_codec_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300008;
}
/// (established)
pub mod aud_codec_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300010;
}
/// (established)
pub mod aud_codec_read {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300018;
}
/// (established)
pub mod aud_ch1_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300020;
}
/// (established)
pub mod aud_ch1_read {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300028;
}
/// (established)
pub mod aud_ch1_write {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300030;
}
/// (established)
pub mod aud_ch1_depth {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300038;
}
/// (established)
pub mod aud_ch2_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300040;
}
/// (established)
pub mod aud_ch2_read {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300048;
}
/// (established)
pub mod aud_ch2_write {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300050;
}
/// (established)
pub mod aud_ch2_depth {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300058;
}
/// (established)
pub mod aud_ch3_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300060;
}
/// (established)
pub mod aud_ch3_read {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300068;
}
/// (established)
pub mod aud_ch3_write {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300070;
}
/// (established)
pub mod aud_ch3_depth {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300078;
}
/// (established)
pub mod pioflush {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x304018;
}
/// (established)
pub mod isa_ring_base {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x310000;
}
/// (established)
pub mod isa_misc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x310008;
}
/// (established)
pub mod isa_int_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x310010;
}
/// (established)
pub mod isa_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x310018;
}
/// (established)
pub mod par_cntl_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x314010;
}
/// (established)
pub mod par_diag {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x314018;
}
/// (established)
pub mod s1_tx_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x318000;
}
/// (established)
pub mod s1_rx_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x318020;
}
/// (established)
pub mod s2_tx_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x31c000;
}
/// (established)
pub mod s2_rx_cntl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x31c020;
}
/// (established)
pub mod i2c_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x330010;
}
/// (established)
pub mod i2c_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x330018;
}
/// (established)
pub mod tmr_ust {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340000;
}
/// (established)
pub mod tmr_compare1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340008;
}
/// (established)
pub mod tmr_compare2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340010;
}
/// (established)
pub mod tmr_compare3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340018;
}
/// (established)
pub mod tmr_ain {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340020;
}
/// (established)
pub mod tmr_aout1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340028;
}
/// (established)
pub mod tmr_aout2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340030;
}
/// (established)
pub mod isa_parallel {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x380000;
}
/// (established)
pub mod isa_parallel_380100 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x380100;
}
/// (established)
pub mod isa_parallel_380200 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x380200;
}
/// (established)
pub mod isa_parallel_380300 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x380300;
}
/// (established)
pub mod isa_parallel_380400 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x380400;
}
/// (established)
pub mod isa_ecp1284 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x388200;
}
/// (established)
pub mod isa_rtc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0000;
}
/// (established)
pub mod isa_rtc_3a0100 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0100;
}
/// (established)
pub mod isa_rtc_3a0200 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0200;
}
/// (established)
pub mod isa_rtc_3a0300 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0300;
}
/// (established)
pub mod isa_rtc_3a0400 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0400;
}
/// (established)
pub mod isa_rtc_3a0500 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0500;
}
/// (established)
pub mod isa_rtc_3a0600 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0600;
}
/// (established)
pub mod isa_rtc_3a0700 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0700;
}
/// (established)
pub mod isa_rtc_3a0800 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0800;
}
/// (established)
pub mod isa_rtc_3a0900 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0900;
}
/// (established)
pub mod isa_rtc_3a0a00 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0a00;
}
/// (established)
pub mod isa_rtc_3a0b00 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0b00;
}
/// (established)
pub mod isa_rtc_3a0c00 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0c00;
}
/// (established)
pub mod isa_rtc_3a0e00 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a0e00;
}
/// (established)
pub mod isa_rtc_3a4800 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a4800;
}
/// (established)
pub mod isa_rtc_3a4900 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a4900;
}
/// (established)
pub mod isa_rtc_3a4a00 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a4a00;
}
/// (established)
pub mod isa_rtc_3a4b00 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3a4b00;
}
pub const AUD_CODEC_CNTL_B_15_0: u32 = 0xffff; // inferred
pub const AUD_CODEC_CNTL_V_10000: u32 = 0x10000; // inferred
pub const AUD_CODEC_READ_B_15_0: u32 = 0xffff; // inferred
pub const AUD_CONTROL_B_1: u32 = 0x2; // inferred
pub const AUD_CONTROL_B_11_5: u32 = 0xfe0; // inferred
pub const AUD_CONTROL_V_1: u32 = 0x1; // inferred
pub const ETH_MAC_CONTROL_B_7_0: u32 = 0xff; // inferred
pub const ETH_MAC_CONTROL_V_1: u32 = 0x1; // inferred
pub const I2C_CONTROL_B_0: u32 = 0x1; // inferred
pub const I2C_CONTROL_V_1: u32 = 0x1; // inferred
pub const I2C_CONTROL_V_3: u32 = 0x3; // inferred
pub const ISA_ECP1284_B_7_0: u32 = 0xff; // inferred
pub const ISA_ECP1284_V_10: u32 = 0x10; // inferred
pub const ISA_ECP1284_V_40: u32 = 0x40; // inferred
pub const ISA_ECP1284_V_60: u32 = 0x60; // inferred
pub const ISA_ECP1284_V_8: u32 = 0x8; // inferred
pub const ISA_ECP1284_V_80: u32 = 0x80; // inferred
pub const ISA_ECP1284_V_C0: u32 = 0xc0; // inferred
pub const ISA_INT_MASK_B_7_0: u32 = 0xff; // inferred
pub const ISA_INT_MASK_V_100: u32 = 0x100; // inferred
pub const ISA_INT_MASK_V_18: u32 = 0x18; // inferred
pub const ISA_INT_MASK_V_A00: u32 = 0xa00; // inferred
pub const ISA_INT_STAT_B_1: u32 = 0x2; // inferred
pub const ISA_INT_STAT_B_8: u32 = 0x100; // inferred
pub const ISA_MISC_B_1: u32 = 0x2; // inferred
pub const ISA_MISC_B_4: u32 = 0x10; // inferred
pub const ISA_MISC_B_5_4: u32 = 0x30; // inferred
pub const ISA_MISC_B_7_0: u32 = 0xff; // inferred
pub const ISA_MISC_V_1: u32 = 0x1; // inferred
pub const ISA_PARALLEL_380100_B_3: u32 = 0x8; // inferred
pub const ISA_PARALLEL_380100_B_4: u32 = 0x10; // inferred
pub const ISA_PARALLEL_380100_B_5: u32 = 0x20; // inferred
pub const ISA_PARALLEL_380100_B_6: u32 = 0x40; // inferred
pub const ISA_PARALLEL_380100_B_6_3: u32 = 0x48; // inferred
pub const ISA_PARALLEL_380100_B_7: u32 = 0x80; // inferred
pub const ISA_PARALLEL_380100_B_7_0: u32 = 0xff; // inferred
pub const ISA_PARALLEL_380100_B_7_3: u32 = 0xf8; // inferred
pub const ISA_PARALLEL_380100_B_7_4: u32 = 0xf0; // inferred
pub const ISA_PARALLEL_380100_B_7_5_4: u32 = 0xb0; // inferred
pub const ISA_PARALLEL_380100_B_7_6_3: u32 = 0xc8; // inferred
pub const ISA_PARALLEL_380200_B_6: u32 = 0x40; // inferred
pub const ISA_PARALLEL_380200_B_6_3: u32 = 0x78; // inferred
pub const ISA_PARALLEL_380200_B_7_0: u32 = 0xff; // inferred
pub const ISA_PARALLEL_380200_B_7_5_4: u32 = 0xb0; // inferred
pub const ISA_PARALLEL_380200_B_7_6_3: u32 = 0xc8; // inferred
pub const ISA_PARALLEL_380200_V_1: u32 = 0x1; // inferred
pub const ISA_PARALLEL_380200_V_2: u32 = 0x2; // inferred
pub const ISA_PARALLEL_380200_V_20: u32 = 0x20; // inferred
pub const ISA_PARALLEL_380200_V_4: u32 = 0x4; // inferred
pub const ISA_PARALLEL_380200_V_5: u32 = 0x5; // inferred
pub const ISA_PARALLEL_380200_V_7: u32 = 0x7; // inferred
pub const ISA_PARALLEL_380200_V_8: u32 = 0x8; // inferred
pub const ISA_PARALLEL_380200_V_D: u32 = 0xd; // inferred
pub const ISA_PARALLEL_380200_V_E: u32 = 0xe; // inferred
pub const ISA_PARALLEL_380300_B_7_0: u32 = 0xff; // inferred
pub const ISA_PARALLEL_380300_V_1: u32 = 0x1; // inferred
pub const ISA_PARALLEL_380300_V_2: u32 = 0x2; // inferred
pub const ISA_PARALLEL_380300_V_3: u32 = 0x3; // inferred
pub const ISA_PARALLEL_380300_V_6: u32 = 0x6; // inferred
pub const ISA_PARALLEL_380300_V_8: u32 = 0x8; // inferred
pub const ISA_PARALLEL_380300_V_9: u32 = 0x9; // inferred
pub const ISA_PARALLEL_380300_V_A: u32 = 0xa; // inferred
pub const ISA_PARALLEL_380400_B_7_0: u32 = 0xff; // inferred
pub const ISA_PARALLEL_380400_V_1A: u32 = 0x1a; // inferred
pub const ISA_PARALLEL_380400_V_2: u32 = 0x2; // inferred
pub const ISA_PARALLEL_380400_V_42: u32 = 0x42; // inferred
pub const ISA_PARALLEL_380400_V_5: u32 = 0x5; // inferred
pub const ISA_PARALLEL_380400_V_8: u32 = 0x8; // inferred
pub const ISA_PARALLEL_380400_V_9: u32 = 0x9; // inferred
pub const ISA_PARALLEL_B_7_0: u32 = 0xff; // inferred
pub const ISA_PARALLEL_V_100: u32 = 0x100; // inferred
pub const ISA_PARALLEL_V_2: u32 = 0x2; // inferred
pub const ISA_PARALLEL_V_4: u32 = 0x4; // inferred
pub const ISA_PARALLEL_V_5: u32 = 0x5; // inferred
pub const ISA_PARALLEL_V_55: u32 = 0x55; // inferred
pub const ISA_PARALLEL_V_78: u32 = 0x78; // inferred
pub const ISA_PARALLEL_V_87: u32 = 0x87; // inferred
pub const ISA_PARALLEL_V_AA: u32 = 0xaa; // inferred
pub const ISA_PARALLEL_V_FE: u32 = 0xfe; // inferred
pub const ISA_PARALLEL_V_FF: u32 = 0xff; // inferred
pub const ISA_RING_BASE_B_4: u32 = 0x10; // inferred
pub const ISA_RING_BASE_V_0: u32 = 0x0; // inferred
pub const ISA_RTC_3A0100_V_C0: u32 = 0xc0; // inferred
pub const ISA_RTC_3A0200_B_4_0: u32 = 0x1f; // inferred
pub const ISA_RTC_3A0200_B_5_0: u32 = 0x3f; // inferred
pub const ISA_RTC_3A0300_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A0400_B_4_0: u32 = 0x1f; // inferred
pub const ISA_RTC_3A0400_B_5_0: u32 = 0x3f; // inferred
pub const ISA_RTC_3A0400_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A0500_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A0600_B_2_0: u32 = 0x7; // inferred
pub const ISA_RTC_3A0700_B_2_0: u32 = 0x7; // inferred
pub const ISA_RTC_3A0700_B_4_0: u32 = 0x1f; // inferred
pub const ISA_RTC_3A0700_B_5_0: u32 = 0x3f; // inferred
pub const ISA_RTC_3A0800_B_2_0: u32 = 0x7; // inferred
pub const ISA_RTC_3A0800_B_4_0: u32 = 0x1f; // inferred
pub const ISA_RTC_3A0900_B_2_0: u32 = 0x7; // inferred
pub const ISA_RTC_3A0A00_B_15_5_3_0: u32 = 0xffef; // inferred
pub const ISA_RTC_3A0A00_B_15_7_5_0: u32 = 0xffbf; // inferred
pub const ISA_RTC_3A0A00_B_4: u32 = 0x10; // inferred
pub const ISA_RTC_3A0A00_B_6_5: u32 = 0x60; // inferred
pub const ISA_RTC_3A0A00_B_7: u32 = 0x80; // inferred
pub const ISA_RTC_3A0A00_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A0A00_V_10: u32 = 0x10; // inferred
pub const ISA_RTC_3A0A00_V_20: u32 = 0x20; // inferred
pub const ISA_RTC_3A0A00_V_30: u32 = 0x30; // inferred
pub const ISA_RTC_3A0B00_B_15_3_1_0: u32 = 0xfffb; // inferred
pub const ISA_RTC_3A0B00_B_15_8_6_0: u32 = 0xff7f; // inferred
pub const ISA_RTC_3A0B00_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A0B00_V_2: u32 = 0x2; // inferred
pub const ISA_RTC_3A0B00_V_80: u32 = 0x80; // inferred
pub const ISA_RTC_3A0B00_V_82: u32 = 0x82; // inferred
pub const ISA_RTC_3A0C00_B_7: u32 = 0x80; // inferred
pub const ISA_RTC_3A0E00_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A0E00_V_1: u32 = 0x1; // inferred
pub const ISA_RTC_3A4900_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A4A00_B_0: u32 = 0x1; // inferred
pub const ISA_RTC_3A4A00_B_15_2: u32 = 0xfffc; // inferred
pub const ISA_RTC_3A4A00_B_1_0: u32 = 0x3; // inferred
pub const ISA_RTC_3A4A00_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A4A00_V_8: u32 = 0x8; // inferred
pub const ISA_RTC_3A4B00_B_15_2_0: u32 = 0xfffd; // inferred
pub const ISA_RTC_3A4B00_B_7_0: u32 = 0xff; // inferred
pub const ISA_RTC_3A4B00_V_2: u32 = 0x2; // inferred
pub const ISA_RTC_3A4B00_V_81: u32 = 0x81; // inferred
pub const ISA_RTC_3A4B00_V_83: u32 = 0x83; // inferred
pub const ISA_RTC_3A4B00_V_9: u32 = 0x9; // inferred
pub const ISA_RTC_B_5_0: u32 = 0x3f; // inferred
pub const PAR_CNTL_STAT_B_0: u32 = 0x1; // inferred
pub const PAR_CNTL_STAT_V_1: u32 = 0x1; // inferred
pub const PAR_CNTL_STAT_V_2: u32 = 0x2; // inferred
pub const PAR_CNTL_STAT_V_4: u32 = 0x4; // inferred
pub const PAR_DIAG_B_0: u32 = 0x1; // inferred
pub const PAR_DIAG_B_1: u32 = 0x2; // inferred
pub const PAR_DIAG_B_11_0: u32 = 0xfff; // inferred
pub const PCI_CONFIG_ADDR_B_7_2: u32 = 0xfc; // inferred
pub const PCI_CONFIG_ADDR_V_4: u32 = 0x4; // inferred
pub const PCI_CONFIG_ADDR_V_8: u32 = 0x8; // inferred
pub const PCI_CONFIG_ADDR_V_C: u32 = 0xc; // inferred
pub const PCI_CONFIG_DATA_B_7_0: u32 = 0xff; // inferred
pub const PCI_CONFIG_DATA_V_3020: u32 = 0x3020; // inferred
pub const PCI_CONFIG_DATA_V_6: u32 = 0x6; // inferred
pub const PCI_CONTROL_B_11: u32 = 0x800; // inferred
pub const PCI_CONTROL_V_503: u32 = 0x503; // inferred
pub const PCI_CONTROL_V_85FF: u32 = 0x85ff; // inferred
pub const PCI_CONTROL_V_8DFF: u32 = 0x8dff; // inferred
pub const PCI_CONTROL_V_FE000000: u32 = 0xfe000000; // inferred
pub const PCI_CONTROL_V_FF000000: u32 = 0xff000000; // inferred
pub const PCI_FLUSH_REV_V_1: u32 = 0x1; // inferred
pub const VOUT_VHW_CFG_B_3_0: u32 = 0xf; // inferred
