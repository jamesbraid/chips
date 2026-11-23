// @generated from devices/router_origin2000/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 55acab457ef018bc4853a2b04d093f28069ad2bb79ae1b72e1c51ad76c5c6feb
// network router as the Origin 2000 kernel reaches it (register numbers of a vector access)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// (established)
pub mod status_rev_id_led_write_path {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x0;
}
/// (established)
pub mod port_status_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x8;
}
/// (established)
pub mod prot_conf {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10;
}
/// (established)
pub mod global_port_def {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod nic_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38;
}
/// (established)
pub mod port_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x88;
}
