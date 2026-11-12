// generated from defs/r5000_identity.toml by defs-gen - do not edit, change the source
// MIPS R5000 family processor identity, reset entries, cache geometry and TLB size
#![allow(dead_code)]

pub const R5K_COLD_RANDOM: u32 = 0x2f; // established
pub const R5K_COLD_WIRED: u32 = 0x0; // established
pub const R5K_FCR0_OBSERVED: u32 = 0x2310; // inferred
pub const R5K_IMP_VR5000: u32 = 0x23; // established
pub const R5K_PHYS_ADDR_BITS: u32 = 0x24; // established
pub const R5K_PRID_IMP_MASK: u32 = 0xff00; // established
pub const R5K_PRID_IMP_SHIFT: u32 = 0x8; // established
pub const R5K_PRID_OBSERVED: u32 = 0x2321; // inferred
pub const R5K_PRID_REV_MASK: u32 = 0xff; // established
pub const R5K_PRIMARY_CACHE_BYTES: u32 = 0x8000; // established
pub const R5K_PRIMARY_LINE_BYTES: u32 = 0x20; // established
pub const R5K_PRIMARY_SETS: u32 = 0x200; // established
pub const R5K_PRIMARY_WAYS: u32 = 0x2; // established
pub const R5K_RESET_VECTOR: u64 = 0xffffffffbfc00000; // established
pub const R5K_SECONDARY_LINE_BYTES: u32 = 0x20; // established
pub const R5K_SECONDARY_WAYS: u32 = 0x1; // established
pub const R5K_SYSCLK_MAX_MHZ: u32 = 0x64; // established
pub const R5K_TLB_ENTRIES: u32 = 0x30; // established
pub const R5K_USER_ADDR_BITS: u32 = 0x28; // established
pub const R5K_WARM_STATUS_SET: u32 = 0x500004; // established
