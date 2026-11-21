// generated from devices/r10000_cp0/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 ac3e03c75ed94daca87b077b35f60770d6347248765e51833d4b0943ef3eb864
// R10000 CP0 Count and Compare timer interrupt and TLB geometry
#![allow(dead_code)]

/// The Cause register bit that carries the Count and Compare timer interrupt. (established)
pub mod cause_timer {
    pub const WIDTH: u32 = 32;
    pub mod ip7 { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const R10K_CP0_COMPARE: u32 = 0xb; // established
pub const R10K_CP0_COUNT: u32 = 0x9; // established
pub const R10K_TLB_ASID_BITS: u32 = 0x8; // inferred
pub const R10K_TLB_ENTRIES: u32 = 0x40; // inferred
