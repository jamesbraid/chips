// @generated from devices/router_sn1/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 b70f66625e769d9712121c425a33c1e848b0297d809537cea42eec8674d89524
// SN1 network router: port block, local routing table and remote reset mask (public header positions)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Remote reset mask of one port (RR_RESET_MASK, 0x18 from the port base). Bit L minus 1 is the reset-allowed bit for link L (RRM_RESETOK). The header na (established)
pub mod reset_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18;
}
/// Local routing table of one port: entry x sits at 0x200 plus 8 times x from the port base (RR_LOCAL_TABLE). Each 64-bit entry holds eight 3-bit fields, (established)
pub mod local_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200;
    pub const COUNT: u32 = 128;
    pub const STRIDE: u64 = 8;
    pub mod link8 { // bits 30:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link7 { // bits 26:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link6 { // bits 22:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link5 { // bits 18:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link4 { // bits 14:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link3 { // bits 10:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link2 { // bits 6:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link1 { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const LOCAL_ENTRIES: u32 = 0x80; // established
pub const MAX_PORTS: u32 = 0x8; // established
pub const META_ENTRIES: u32 = 0x10; // established
pub const RTABLE_FIELD_BITS: u32 = 0x3; // established
pub const RTABLE_FIELD_STRIDE_BITS: u32 = 0x4; // established
