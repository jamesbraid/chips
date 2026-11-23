// generated from devices/cobalt_mc/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 3d100dec20588755741fdb06f5abce36f69505f14e7ee89805fe602319bd80dc
// Cobalt memory controller of the SGI Visual Workstation 320 and 540: ECC control, error reporting and the bank registers
#![allow(dead_code)]

/// Memory controller control. At timer set-up the HAL also stores 0 here and 0 in the error status. The PROM self-test sets bit 0 with a full-word store  (established)
pub mod ecc_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
    pub mod ecc_enable { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Read by the PROM self-test between its probe writes; half of it is the delay threshold for the counter register (delay_counter). Compared as a signed  (inferred)
pub mod delay_period {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
}
/// Counter the PROM self-test polls (signed compares) until it is at or below, then at or above, half the value of mem_period, as a delay between probe w (inferred)
pub mod delay_counter {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// Memory error status. The NT HAL's error handler reads it, treats the error as non-fatal when bit 16 is set or when bit 17 is set and the syndrome is z (established)
pub mod error_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
    pub mod syndrome_only { // bits 17:17, inferred
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod nonfatal { // bits 16:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory error address, printed by the HAL as the address of the error. (established)
pub mod error_address {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// Memory error ECC syndrome. A nonzero syndrome with a correctable error sends the HAL to HalpCorrectSoftEccError, which computes a quadword offset from (established)
pub mod error_syndrome {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
/// Read once by the PROM self-test's DIMM speed check (check 0x0d, prom-console-path.md), on every Cobalt revision. The check passes only when bit 16 rea (inferred)
pub mod dimm_speed_check {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
    pub mod speed_ok { // bits 16:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Bank register of each of sixteen 128 MiB address slots (slot i decodes from i * 128 MiB), on every revision except 0xa0 and 0xa8, whose registers star (inferred)
pub mod bank {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
pub const BANK_ABSENT: u32 = 0x0; // inferred
pub const BANK_FIRST_LITE: u32 = 0x48; // inferred
pub const BANK_FULL: u32 = 0x3; // inferred
pub const BANK_PARTIAL: u32 = 0x2; // inferred
pub const BANK_SLOTS: u32 = 0x10; // inferred
pub const BANK_SPAN: u32 = 0x8000000; // inferred
pub const BASE: u32 = 0xc6000000; // established
