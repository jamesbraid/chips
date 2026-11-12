// generated from defs/ioc3_extra.toml by defs-gen - do not edit, change the source
// IOC3 registers outside the census
#![allow(dead_code)]

/// (established)
pub mod one_wire_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
/// (established)
pub mod plp_a_addr_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod plp_a_addr_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x84;
}
/// (established)
pub mod plp_a_count {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
}
/// (established)
pub mod plp_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8c;
}
/// (established)
pub mod plp_b_addr_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod plp_b_addr_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x94;
}
/// (established)
pub mod plp_b_count {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x98;
}
/// (established)
pub mod km_rx_kbd {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod km_rx_mouse {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa4;
}
/// (established)
pub mod km_tx_kbd {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa8;
}
/// (established)
pub mod km_tx_mouse {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xac;
}
