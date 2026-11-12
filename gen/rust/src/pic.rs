// generated from defs/pic.toml by defs-gen - do not edit, change the source
// PIC (dual-head PCI-X bridge), Origin 3000 family
#![allow(dead_code)]

/// (established)
pub mod pcibr_bridge_ptr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x0;
}
/// (established)
pub mod bus_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod ssram_size {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod req_timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x28;
}
/// (established)
pub mod intr_dst_target_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38;
}
/// (established)
pub mod cmdword_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40;
}
/// (established)
pub mod llp_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x48;
}
/// (established)
pub mod tflush {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50;
}
/// (established)
pub mod linkside_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x58;
}
/// (established)
pub mod resp_err_buf {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60;
}
/// (established)
pub mod resp_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x68;
}
/// (established)
pub mod linkside_err_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x78;
}
/// (established)
pub mod dirmap_wid {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod ssram_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod arbitration {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod parity_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0;
}
/// (established)
pub mod timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xc0;
}
/// (established)
pub mod type1_cntr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xc8;
}
/// (established)
pub mod pci_bus_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xd8;
}
/// (established)
pub mod intr_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100;
}
/// (established)
pub mod intr_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x108;
}
/// (established)
pub mod intr_reset {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110;
}
/// (established)
pub mod intr_mode {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x118;
}
/// (established)
pub mod intr_device {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120;
}
/// (established)
pub mod intr_host_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x128;
}
/// (established)
pub mod intr_addr_vect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x130;
}
/// (established)
pub mod intr_view {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x170;
}
/// (established)
pub mod intr_multiple {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x178;
}
/// (established)
pub mod force_always {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x180;
}
/// (established)
pub mod force_intr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1c0;
}
/// (established)
pub mod device {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200;
}
/// (established)
pub mod wrb_flush {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x240;
}
/// (established)
pub mod rrb {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x280;
}
/// (established)
pub mod rrb_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x290;
}
/// (established)
pub mod rrb_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x298;
}
/// (established)
pub mod pcix_bus_err_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600;
}
/// (established)
pub mod pcix_bus_err_attr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608;
}
/// (established)
pub mod pcix_bus_err_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x610;
}
/// (established)
pub mod pcix_pio_split_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x618;
}
/// (established)
pub mod pcix_pio_split_attr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x620;
}
/// (established)
pub mod pcix_req_err_attr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x628;
}
/// (established)
pub mod pcix_req_err_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x630;
}
/// (established)
pub mod int_ate {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10000;
}
/// (established)
pub mod pic_attach2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18000;
}
/// (established)
pub mod pic_attach2_18800 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18800;
}
/// (established)
pub mod pic_attach2_19000 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x19000;
}
/// (established)
pub mod ext_ate {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x80000;
}
pub const INTR_ADDR_VECT_B_10_0: u32 = 0x7ff; // inferred
pub const INTR_ADDR_VECT_B_7_0: u32 = 0xff; // inferred
pub const INTR_DST_TARGET_ID_V_A5A5: u32 = 0xa5a5; // inferred
pub const INTR_DST_TARGET_ID_V_A5A50000: u32 = 0xa5a50000; // inferred
pub const INT_ATE_B_10_0: u32 = 0x7ff; // inferred
pub const LINKSIDE_ERR_ADDR_V_BEEF: u32 = 0xbeef; // inferred
pub const PCIBR_BRIDGE_PTR_B_10_0: u32 = 0x7ff; // inferred
pub const PCIBR_BRIDGE_PTR_B_15_0: u32 = 0xffff; // inferred
pub const RRB_B_10_0: u32 = 0x7ff; // inferred
pub const SSRAM_SIZE_B_5_4: u32 = 0x30; // inferred
