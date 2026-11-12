// generated from defs/hub_extra.toml by defs-gen - do not edit, change the source
// Hub block transfer engine registers and control bits outside the census
#![allow(dead_code)]

/// Notification address of engine 0, the twin of the engine 1 slot in the census. Offset and name are from the public header. The header gives no access  (inferred)
pub mod iio_ibna_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410020;
}
/// Interrupt address of engine 0. Offset and name are from the public header. The header gives no access type, so rw is assumed. (inferred)
pub mod iio_ibia_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410028;
    pub mod level { // bits 22:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node { // bits 8:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt address of engine 1. Offset and name are from the public header. The header gives no access type, so rw is assumed. (inferred)
pub mod iio_ibia_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420028;
    pub mod level { // bits 22:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node { // bits 8:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const IIO_IBCT_NOTIFY: u32 = 0x10; // established
pub const IIO_IBCT_POISON: u32 = 0x100; // established
pub const IIO_IBCT_ZFIL_MODE: u32 = 0x1; // established
pub const IIO_IBLS_BUSY: u32 = 0x100000; // established
pub const IIO_IECLR_BTE0: u32 = 0x20000; // inferred
pub const IIO_IECLR_BTE1: u32 = 0x40000; // inferred
