// generated from devices/r10000_secondary_cache_ecc/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 cc78ff4915b50584aa672ca71dabf3234b0b505cd47089cee5a3062c63bbc60e
// R10000 family CP0 CacheErr fields for secondary-cache errors
#![allow(dead_code)]

pub const R10K_CACHEERR_D_MASK: u32 = 0xc000000; // established
pub const R10K_CACHEERR_D_SHIFT: u32 = 0x1a; // established
pub const R10K_CACHEERR_SIDX_MASK: u32 = 0x7fffc0; // established
pub const R10K_CACHEERR_SIDX_SHIFT: u32 = 0x6; // established
pub const R10K_CACHEERR_TA_MASK: u32 = 0x3000000; // established
pub const R10K_CACHEERR_TA_SHIFT: u32 = 0x18; // established
pub const R10K_CACHEERR_UNIT_SECONDARY: u32 = 0x2; // established
pub const R10K_CACHEERR_UNIT_SHIFT: u32 = 0x1e; // established
