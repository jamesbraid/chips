// generated from defs/bridge.toml by defs-gen - do not edit, change the source
// Bridge (XIO-to-PCI bridge), Origin 2000 and Octane
#![allow(dead_code)]

/// (established)
pub mod wid_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
}
/// (established)
pub mod wid_stat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
}
/// (established)
pub mod wid_err_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// (established)
pub mod wid_err_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod wid_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod wid_req_timeout {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// (established)
pub mod wid_int_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
/// (established)
pub mod wid_int_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x38;
}
/// (established)
pub mod wid_err_cmdword {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
}
/// (established)
pub mod wid_llp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
}
/// (established)
pub mod wid_tflush {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50;
}
/// (established)
pub mod wid_aux_err {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x58;
}
/// (established)
pub mod wid_resp_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x60;
}
/// (established)
pub mod wid_resp_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x68;
}
/// (established)
pub mod dir_map {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod ram_perr_or_map_fault {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod arb {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod bus_timeout {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc0;
}
/// (established)
pub mod pci_cfg {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc8;
}
/// (established)
pub mod pci_err_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xd0;
}
/// (established)
pub mod pci_err_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xd8;
}
/// (established)
pub mod int_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100;
}
/// (established)
pub mod int_enable {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x108;
}
/// (established)
pub mod int_rst_stat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x110;
}
/// (established)
pub mod int_mode {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x118;
}
/// (established)
pub mod int_device {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x120;
}
/// (established)
pub mod int_host_err {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x128;
}
/// (established)
pub mod int_addr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x130;
}
/// (established)
pub mod device {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200;
}
/// (established)
pub mod wr_req_buf {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x240;
}
/// (established)
pub mod rrb_map {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x280;
}
/// (established)
pub mod resp_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x290;
}
/// (established)
pub mod resp_clear {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x298;
}
/// (established)
pub mod int_ate_ram {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10000;
}
/// (established)
pub mod ext_ate_ram {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x80000;
}
pub const INT_ADDR_B_10_0: u32 = 0x7ff; // inferred
pub const INT_ADDR_B_7_0: u32 = 0xff; // inferred
pub const INT_STATUS_B_5: u32 = 0x20; // inferred
pub const INT_STATUS_B_6: u32 = 0x40; // inferred
pub const RRB_MAP_B_10_0: u32 = 0x7ff; // inferred
pub const WID_ID_B_10_0: u32 = 0x7ff; // inferred
pub const WID_ID_B_15_0: u32 = 0xffff; // inferred
pub const WID_INT_UPPER_B_5_0: u32 = 0x3f; // inferred
