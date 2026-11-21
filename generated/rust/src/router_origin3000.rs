// generated from devices/router_origin3000/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 f05ec3257a5dd901126db53badb95885bd988bb22c6f7690f241e3c347fa3a6a
// network router as the Origin 3000 kernel reaches it (register numbers of a vector access)
#![allow(dead_code)]

/// (established)
pub mod status_rev_id {
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
pub mod port_reset_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod global_parms0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod global_parms1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x28;
}
/// (established)
pub mod port_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x88;
}
/// (established)
pub mod jbus0_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200;
}
