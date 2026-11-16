// generated from devices/shub/registers.toml by defs-gen - do not edit, change the source
// SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs
#![allow(dead_code)]

/// Chip identification word at node offset 0x1_0000_0000 (memory and directory block by address); the name is ours. The PROM reads it through the node's  (established)
pub mod chip_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100000000;
    pub mod revision { // bits 31:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod part_number { // bits 27:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test engine status; the name is ours. Written 0 before every engine start. Bit 36 is read after each operation 16 poll (site 0xffa702c0, inside (established)
pub mod md_mbist_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100000080;
    pub mod cmp_err { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fail_addr { // bits 32:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1ffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test engine other-error value; the name is ours. Read only in the failure report, and only when bit 36 of md_mbist_status is found clear (the r (established)
pub mod md_mbist_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1000000b8;
}
/// Memory test engine mask; the name is ours (inferred from the all-ones write only). Written with all ones each time the engine starts; never read. Must (established)
pub mod md_mbist_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1000000c0;
}
/// Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with t (established)
pub mod md_bank_cfg0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010000;
    pub mod timing_idx { // bits 35:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_field { // bits 30:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_rank { // bits 27:27, inferred
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_density { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_field { // bits 22:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_rank { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_density { // bits 18:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_field { // bits 14:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_rank { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_density { // bits 10:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_field { // bits 6:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_rank { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_density { // bits 2:0, inferred
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
/// Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with t (established)
pub mod md_bank_cfg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010008;
    pub mod timing_idx { // bits 35:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_field { // bits 30:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_rank { // bits 27:27, inferred
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_density { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_field { // bits 22:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_rank { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_density { // bits 18:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_field { // bits 14:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_rank { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_density { // bits 10:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_field { // bits 6:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_rank { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_density { // bits 2:0, inferred
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
/// Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with t (established)
pub mod md_bank_cfg2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010010;
    pub mod timing_idx { // bits 35:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_field { // bits 30:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_rank { // bits 27:27, inferred
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b3_density { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_field { // bits 22:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_rank { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b2_density { // bits 18:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_field { // bits 14:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_rank { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b1_density { // bits 10:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_field { // bits 6:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_rank { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod b0_density { // bits 2:0, inferred
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
/// Memory controller register, unnamed; the name is ours. Timing word built from a 32-byte row of the timing table at flash site 0xffbe0650 (row = the ti (established)
pub mod md_timing_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010020;
    pub mod trcd4 { // bits 54:54, inferred
        pub const SHIFT: u32 = 54;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod trcd2 { // bits 53:53, inferred
        pub const SHIFT: u32 = 53;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod trcd3 { // bits 52:52, inferred
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_c { // bits 51:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_b { // bits 47:44, established
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_a { // bits 43:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_lo { // bits 39:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod const_lo { // bits 7:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory controller register, unnamed; the name is ours. Six 4-bit timing fields from the 16-bit values at offsets 14, 16, 18, 20, 22 and 24 of the timi (established)
pub mod md_timing_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010028;
    pub mod u5 { // bits 23:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u4 { // bits 19:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u3 { // bits 15:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u2 { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u1 { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u0 { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory controller register, unnamed; the name is ours. One word is written to both _0030 and _0050, once, after the eight DRAM initialisation runs: it (established)
pub mod md_refresh_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010030;
    pub mod bank_small { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod trfc { // bits 22:17, inferred
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod interval { // bits 16:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cs_enable { // bits 7:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory controller register, unnamed; the name is ours. Timing word built from a 32-byte row of the timing table at flash site 0xffbe0650 (row = the ti (established)
pub mod md_timing_2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010040;
    pub mod trcd4 { // bits 54:54, inferred
        pub const SHIFT: u32 = 54;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod trcd2 { // bits 53:53, inferred
        pub const SHIFT: u32 = 53;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod trcd3 { // bits 52:52, inferred
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_c { // bits 51:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_b { // bits 47:44, established
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_a { // bits 43:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_lo { // bits 39:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod const_lo { // bits 7:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory controller register, unnamed; the name is ours. Six 4-bit timing fields from the 16-bit values at offsets 14, 16, 18, 20, 22 and 24 of the timi (established)
pub mod md_timing_3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010048;
    pub mod u5 { // bits 23:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u4 { // bits 19:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u3 { // bits 15:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u2 { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u1 { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod u0 { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory controller register, unnamed; the name is ours. One word is written to both _0030 and _0050, once, after the eight DRAM initialisation runs: it (established)
pub mod md_refresh_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010050;
    pub mod bank_small { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod trfc { // bits 22:17, inferred
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod interval { // bits 16:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cs_enable { // bits 7:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory controller register, unnamed; the name is ours. Written once with the constant 0x4004e20; never read. Role unknown. See memory-init.md. (established)
pub mod md_const_58 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010058;
}
/// Memory controller register, unnamed; the name is ours. Written 0x4047 when the SHub ID revision (bits 31:28 of 0x1_1006_0580) is above 2 and 0x4045 ot (established)
pub mod md_ctl_60 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010060;
}
/// Memory controller register, unnamed; the name is ours. The credit routine (site 0xffa7a960) reads it for the first flagged bank, reads md_bank_cfg1, a (established)
pub mod md_reg_0001_0068 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010068;
}
/// Memory controller register, unnamed; the name is ours. Written once with the constant 0x24; never read. Role unknown. See memory-init.md. (established)
pub mod md_const_78 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010078;
}
/// Memory test and DRAM initialisation engine, command or address word; the name is ours. Written with the caller's 64-bit word before the status and con (established)
pub mod md_mbist_cmd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100020080;
}
/// Memory test and DRAM initialisation engine control; the name is ours. The PROM starts the engine by writing md_mbist_cmd, then 0 to md_mbist_status an (established)
pub mod md_mbist_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100020088;
    pub mod fail { // bits 41:41, established
        pub const SHIFT: u32 = 41;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod go { // bits 40:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod op { // bits 38:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 30:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// MD block register, unnamed; the name is ours. Initializing memory (site 0xffa782c0, which always runs) reads it, sets bit 3 and writes the result to t (established)
pub mod md_reg_0003_0000 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030000;
}
/// Directory presence vector words 0 to 3 of the left directory queue port. The PROM writes the bit mask of present nodes: for each present NASID n in bl (established)
pub mod md_dqlp_dir_presvec {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030100;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// MD block registers, unnamed; the name is ours. Eight words at stride 0x10 that the memory set-up fills with all ones, once each, through the global wi (established)
pub mod md_reg_0003_0200 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030200;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 16;
}
/// Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege  (established)
pub mod md_dqlp_dir_privilege_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030300;
}
/// Privilege vectors 1 to 7 of the left directory queue port (vector 0 is md_dqlp_dir_privilege_vector at 0x1_0003_0300). The PROM writes constants, the  (established)
pub mod md_dqlp_dir_privec {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030310;
    pub const COUNT: u32 = 7;
    pub const STRIDE: u64 = 16;
}
/// Memory and directory block register, unnamed; the name is ours. The memory controller set-up writes 0x1000 (bit 12) to it through the global window, b (established)
pub mod md_reg_0003_0400 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030400;
}
/// Directory memory initial-value write, left queue port block (the block is the one the Linux header calls SH1_MD_DQLP_MMR_DIR_PRIVEC0 at the 0x300 offs (established)
pub mod md_dir_access_lp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100031000;
    pub mod value { // bits 63:55, inferred
        pub const SHIFT: u32 = 55;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test data pattern word (first A word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Progr (established)
pub mod md_bist_data_a0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100038000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// Memory test data pattern word (first B word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Progr (established)
pub mod md_bist_data_b0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100038010;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// Memory test data pattern word (second A word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Prog (established)
pub mod md_bist_data_a1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100038800;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// Memory test data pattern word (second B word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Prog (established)
pub mod md_bist_data_b1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100038810;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// As md_reg_0003_0000 for the right queue port block; the PROM only writes it, with the value it read from md_reg_0003_0000 with bit 3 set. The name is  (established)
pub mod md_reg_0005_0000 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050000;
}
/// Presence vector words 0 to 3 of the right directory queue port: the same values as md_dqlp_dir_presvec, written beside them. Never read back. Header t (established)
pub mod md_dqrp_dir_presvec {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050100;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// As md_reg_0003_0200 for the right queue port block. The name is ours. (established)
pub mod md_reg_0005_0200 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050200;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 16;
}
/// Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names. (established)
pub mod md_dqrp_dir_privilege_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050300;
}
/// Privilege vectors 1 to 7 of the right directory queue port: the same constants as md_dqlp_dir_privec, written right after each left word. (established)
pub mod md_dqrp_dir_privec {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050310;
    pub const COUNT: u32 = 7;
    pub const STRIDE: u64 = 16;
}
/// Same as md_reg_0003_0400 for the right queue port block, 0x100 above SH1_MD_DQRP_MMR_DIR_PRIVEC0 (md_dqrp_dir_privilege_vector). The same routine writ (established)
pub mod md_reg_0005_0400 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050400;
}
/// As md_dir_access_lp for the right queue port block (SH1_MD_DQRP_MMR_DIR_PRIVEC0's block); the name is ours. (established)
pub mod md_dir_access_rp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100051000;
    pub mod value { // bits 63:55, inferred
        pub const SHIFT: u32 = 55;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O interface interrupt 0 and 1 (SH_II_INT0, SH_II_INT1): the register a PIC's interrupt write lands on, through the Crosstalk address nasid << 36 | 1 (established)
pub mod ii_int {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 256;
    pub mod send { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod idx { // bits 7:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Destination of the I/O interface interrupt n (SH_II_INTn_CONFIG): delivery type, target processor id and optional vector base, the ipi_int layout with (established)
pub mod ii_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000080;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 256;
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
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
/// Bit 0 enables the I/O interface interrupt n. The PROM writes 1 to both and never reads them. (established)
pub mod ii_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000200;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
    pub mod enable { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Selects the node whose processors take this node's interrupts when it has none of its own (the PROM's table names it SH_INT_NODE_ID_CONFIG). Role infe (established)
pub mod int_node_id_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000300;
}
/// Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR windo (established)
pub mod ipi_int {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000380;
    pub mod send { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod idx { // bits 59:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
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
/// Enable for ipi_int delivery (the PROM's table names it SH_IPI_INT_ENABLE). The PROM writes 1 before it sends wake-up messages and never reads it. That (established)
pub mod ipi_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000400;
}
/// Destination of local interrupt n (0 to 5): the ipi_int message layout without the send bit. The PROM writes type 2 (PMI) vector 1 to interrupts 0 and  (established)
pub mod local_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000480;
    pub const COUNT: u32 = 6;
    pub const STRIDE: u64 = 256;
    pub mod idx { // bits 59:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
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
/// Mask of event sources that raise local interrupt n. The PROM writes 0x7ef (the bits it treats as error events), 0x4000 and 0x2000. How a mask bit maps (established)
pub mod local_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000500;
    pub const COUNT: u32 = 6;
    pub const STRIDE: u64 = 256;
}
/// Destination of the error interrupt of processor n (0 to 3): the local_int_config layout. The stride 0x80 and the four offsets come from the PROM's nam (established)
pub mod proc_err_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000a80;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Destination of the advisory interrupt of processor n (0 to 3), the local_int_config layout (name only; the meaning of advisory is not in the sources r (established)
pub mod proc_adv_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000c80;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Enable of the processor n error interrupt. The NASID-change routine reads it in the new global window and skips the matching config register when it r (established)
pub mod proc_err_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000e80;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Enable of the processor n advisory interrupt; read by the NASID-change routine as proc_err_int_enable is. (established)
pub mod proc_adv_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001080;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Destination of the profiling interrupt, the local_int_config layout (name only). Rewritten by the NASID-change routine when profile_int_enable is non- (established)
pub mod profile_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001280;
}
/// Enable of the profiling interrupt; read by the NASID-change routine. (established)
pub mod profile_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001300;
}
/// Destination of comparator RTC0's interrupt, which the SAL keeps for a delayed bus-error assertion (Linux mmtimer: RTC0 is used by SAL). Layout as rtc_ (established)
pub mod rtc0_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001380;
}
/// Enable for comparator RTC0; written after the compare value, cleared first on undo. Never read. (established)
pub mod rtc0_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001400;
}
/// Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and  (established)
pub mod rtc_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001480;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 256;
    pub mod idx { // bits 59:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
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
/// Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes (established)
pub mod rtc_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001500;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 256;
    pub mod enable { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the  (established)
pub mod event_occurred {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110010000;
    pub mod ii_int1 { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ii_int0 { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ipi_int { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc3_int { // bits 26:26, established
        pub const SHIFT: u32 = 26;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc2_int { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc1_int { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc0_int { // bits 23:23, inferred
        pub const SHIFT: u32 = 23;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit21 { // bits 21:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart_int { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit8 { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit5 { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit3 { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferre (established)
pub mod event_occurred_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110010008;
}
/// Second event word next to event_occurred; only its alias is written by the PROM. (inferred)
pub mod event_overflow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110010080;
}
/// Clear alias of event_overflow. The PROM writes 8 together with the same write to event_occurred_alias. Accepting the write is enough. (established)
pub mod event_overflow_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110010088;
}
/// Local block register, unnamed; the name is ours (address). SAL_A writes 0x15031010 to it on each of its two entries (reason 3 and reason 0). The image (established)
pub mod lb_reg_1002_0000 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110020000;
}
/// Per-slice local block record, 128 bytes apart (index = slice & 3); the name is ours. SAL_B reads the running processor's entry in the lock routine and (established)
pub mod lb_slice_rec {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110030000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Local block LIQ control: request control in bits 4:0, reply control in bits 11:8 and three force-credit bits. The node set-up method (slot 34 of the c (established)
pub mod lb_liq_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110040000;
    pub mod force_linvv_credit { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod force_rp_credit { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod force_rq_credit { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod liq_rpl_ctl { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod liq_req_ctl { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Maximum number of reply credits from the crossbar. The node set-up method (site 0xffa95c20) reads it, deposits 12 into bits 4:0 and writes it back, on (established)
pub mod lb_max_rep_credit_cnt {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110040100;
    pub mod max_cnt { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Maximum number of request credits from the crossbar. The node set-up method (site 0xffa95c20) reads it, deposits 12 into bits 4:0 and writes it back,  (established)
pub mod lb_max_req_credit_cnt {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110040180;
    pub mod max_cnt { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Local block conveyor belt time-out. The node set-up method (site 0xffa95c20) reads it last and writes it back with 0x3e8 (1000) in bits 11:0, the fiel (established)
pub mod conveyor_belt_time_out {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110040300;
    pub mod value { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Local block error detail words 1 to 5. A vector read that ends in an error leaves 0xe9 in the low byte of detail 1 (a write 0xea); the PROM then write (established)
pub mod lb_error_detail {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110050200;
    pub const COUNT: u32 = 5;
    pub const STRIDE: u64 = 128;
}
/// Local block error summary. The PROM tests bit 16 only: set before a vector request means an old error (it writes the alias at +8 and the mask at 0x1_1 (established)
pub mod lb_error_summary {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110050580;
}
/// CPU MMR access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a cleared bit blocks a (established)
pub mod cpu_perm {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060000;
}
/// External I/O MMR access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a cleared bit (established)
pub mod ext_io_perm {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060100;
}
/// External I/O interrupt access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a clear (established)
pub mod ext_ioi_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060180;
}
/// Real-time clock control; the name is ours. The PROM writes 0x100000000, then writes 0 to rtc, then writes 0x100000041, all at the SAL_B reset entry, b (established)
pub mod rtc_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060280;
    pub mod mode { // bits 33:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod period { // bits 13:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod run { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// I/O interface (II) MMR access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a clear (established)
pub mod io_perm {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060380;
}
/// I/O interface (II) interrupt access permission bits: one access bit per group of nodes (header field ACCESS_BITS, all 64 bits). Bit meaning and what a (established)
pub mod ioi_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060400;
}
/// Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross- (established)
pub mod ipi_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060480;
}
/// DRAM bus clock select; the name is ours. The memory-controller set-up reads it and uses bits 1:0 as an index into a four-entry table held in flash (20 (inferred)
pub mod md_clk_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060500;
    pub mod sel { // bits 1:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in t (established)
pub mod shub_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060580;
    pub mod nodes_per_bit { // bits 52:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod size_code { // bits 45:44, inferred
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod nasid { // bits 42:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod revision { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Present-SHub vector words 0 to 3 in the processor interface block: the same values as md_dqlp_dir_presvec, written third in each group. Never read bac (established)
pub mod shubs_present {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060600;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Data word of a vector request message. The PROM stores the value to write before arming SH_VEC_PARMS for a write request (a read request stores nothin (established)
pub mod vec_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110066000;
}
/// Vector request parameters and the start/busy handshake. TYPE bit 0 (0 read, 1 write), NI_PORT bit 1, ADDRESS bits 34:3 (the register offset bits 34:3) (established)
pub mod vec_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110066080;
}
/// Route of a vector request: the 16-nibble route word shifted down 4 bits (the first nibble goes to SH_VEC_PARMS NI_PORT instead). When the record has n (established)
pub mod vec_route {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110066100;
}
/// Data of a vector reply. Read once, after SH_VEC_STATUS shows a valid reply for a read request, and stored as the result. Before arming a read request  (established)
pub mod vec_rddata {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110074000;
}
/// Vector reply status. TYPE bits 2:0, ADDRESS bits 34:3, PIO_ID bits 45:35, SOURCE bits 59:46 (header), OVERRUN bit 62, STATUS_VALID bit 63. The PROM wr (established)
pub mod vec_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110074100;
}
/// Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel wri (established)
pub mod ptc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101a0000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
    pub mod start { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rid { // bits 62:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ps { // bits 7:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod type_bit { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Purge translation cache parameters, next to SH1_PTC_0 and SH1_PTC_1. The PROM writes a value built from a value it read and the constant 0x23c34600 (u (inferred)
pub mod ptc_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101a0100;
}
/// Compare value of RTC0 (55 bits). Never read. Whether a value already below the counter fires is unknown. (established)
pub mod int_cmpa {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101b0000;
}
/// Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for proce (established)
pub mod int_cmp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101b0080;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 128;
    pub mod compare { // bits 54:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because  (established)
pub mod rtc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101c0000;
    pub mod counter { // bits 54:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Node election word; the name is ours. SAL_A stores slice + 1 to lb_elect_set and reads this register: the 64-bit value must equal exactly what was wri (established)
pub mod lb_elect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0080;
}
/// Election write register; the name is ours. SAL_A stores slice + 1 here and reads lb_elect. Whether it aliases lb_elect, latches the first writer or so (established)
pub mod lb_elect_set {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0088;
}
/// L1 link state word in the local block; the name is ours. SAL_A's election winner sets bits 41:39 to 7 by read-modify-write, keeping the other bits. An (established)
pub mod lb_l1_state {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0100;
    pub mod link { // bits 41:39, inferred
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Second firmware lock pair, release side; the name is ours. The methods of the chip object take it around read-modify-writes of fw_word_1540 by the sam (inferred)
pub mod lb_lock2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0180;
}
/// Second firmware lock status; the name is ours. This-node polls proceed when the whole 64-bit value reads 0 (the same routine as lb_lock_status). The o (inferred)
pub mod lb_lock2_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0188;
}
/// Firmware lock pair, release side; the name is ours. The PROM takes the lock by polling lb_lock_status until it reads 0, does a read-modify-write of cp (inferred)
pub mod lb_lock {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0200;
}
/// Firmware lock status; the name is ours. The PROM polls it with a short delay until it reads 0; any non-zero value keeps it waiting until the 1,000,000 (inferred)
pub mod lb_lock_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0208;
}
/// SHub 1 coherent request buffer message control: coherence and speculation enables, mismatch checks and the invalidate-acknowledge (IVACK) throttle. A  (established)
pub mod crb_message_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120000000;
    pub mod ivack_throttle_control { // bits 63:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ivack_stall_count { // bits 47:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable_ivack_consolidation { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod suppress_bogus_writes { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_attribute_mismatch_xb_enable { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rrb_attribute_mismatch_xb_enable { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irb_attribute_mismatch_fsb_enable { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_attribute_mismatch_fsb_enable { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rrb_attribute_mismatch_fsb_enable { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod message_color_enable { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod message_color { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod remote_speculative_message_enable { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod local_speculative_message_enable { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod system_coherence_enable { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Coherent request buffer NACK limit: a 12-bit count limit, a 4-bit frequency for the priority count and an enable in bit 63. The node set-up method (sl (established)
pub mod crb_nack_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120000080;
    pub mod enable { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pri_freq { // bits 15:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod limit { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Coherent request buffer timeout prescale: one 32-bit scaling factor in bits 31:0. The node set-up method (site 0xffa95c20) reads it (site 0xffa9608c)  (established)
pub mod crb_timeout_prescale {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120000100;
    pub mod scaling_factor { // bits 31:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Coherent request buffer timeout skid limit: a 6-bit skid in bits 5:0 and a reset-skid-counter bit in bit 63. A routine reached through a table that al (established)
pub mod crb_timeout_skid {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120000180;
    pub mod reset_skid_count { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod skid { // bits 5:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// FSB system agent configuration (SH_FSB_SYSTEM_AGENT_CONFIG in the SGI 2.4 SN2 header at linux-mips linux-2.4 8ef7d46c94d5 and in the PROM's name table (established)
pub mod pi_reg_2001_0100 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120010100;
    pub mod bit24 { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit17 { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit3 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Per-slice flags in the processor interface; the name is ours. The local-master arbitration reads it for slices 0 and 1 other than the running one and  (established)
pub mod pi_slice_present {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120020080;
    pub mod present2 { // bits 5:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod present { // bits 1:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the k (established)
pub mod pi_cam_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120050300;
}
/// Processor interface register, unnamed; the name is ours. Read once, with pi_reg_2006_0180 and pi_reg_2006_0200, right after the second pi_cam_control  (inferred)
pub mod pi_reg_2006_0100 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120060100;
}
/// Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100. (inferred)
pub mod pi_reg_2006_0180 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120060180;
}
/// Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100. (inferred)
pub mod pi_reg_2006_0200 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120060200;
}
/// PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O wr (established)
pub mod pio_write_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120070200;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
    pub mod pending_write_count { // bits 61:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_deadlock { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it wa (inferred)
pub mod pio_write_status_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120070208;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
}
/// Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). Network interface link state. The PROM reads it once per port in i (established)
pub mod ni_llp_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150000000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
    pub mod link_reset_state { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). Writing issues a reset to the network interface; the header says b (established)
pub mod ni_llp_reset {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150000008;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
    pub mod warm { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). Signalling mode of the LLP channel. The PROM reads it once per por (established)
pub mod ni_llp_chan_mode {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150000018;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
    pub mod bitmode32 { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). LLP and channel configuration. The PROM reads it and writes it str (established)
pub mod ni_llp_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150000020;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
    pub mod ftu_time { // bits 35:26, established
        pub const SHIFT: u32 = 26;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod nulltimeout { // bits 25:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod maxretry { // bits 19:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod maxburst { // bits 9:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). LLP test control. The PROM reads it, clears bits 41:40 when a link (established)
pub mod ni_llp_test_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150000028;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
    pub mod send_test_mode { // bits 41:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Port 0 at this offset, port 1 is the next register block, 0x2000 higher (SH_NI1_*). LLP error status. The PROM reads it; if bit 27 (the power_OK loss  (established)
pub mod ni_llp_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150000048;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
    pub mod power_not_ok { // bits 27:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Link flow words 0 to 3 of NI port 0. The PROM reads them only when ni_llp_stat reads 9 (and the CPU is not the simulator id), each up to 128 times unt (established)
pub mod xnni0_link_flow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150001040;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// Link flow words 0 to 3 of NI port 1. The PROM reads them only when ni_llp_stat reads 9 (and the CPU is not the simulator id), each up to 128 times unt (established)
pub mod xnni1_link_flow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150003040;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// Local routing table of the I/O-interface side local block: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0  (established)
pub mod iilb_local_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150020000;
    pub const COUNT: u32 = 128;
    pub const STRIDE: u64 = 8;
}
/// Global routing table of the I/O-interface side local block: 16 doublewords, same entry layout as iilb_local_table, indexed by the high NASID bits (the (established)
pub mod iilb_global_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150020400;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// Route override entry of the I/O-interface side local block; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. Th (established)
pub mod iilb_over_ride_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150020480;
}
/// Local routing table of the processor interface: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction  (established)
pub mod pi_local_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150021000;
    pub const COUNT: u32 = 128;
    pub const STRIDE: u64 = 8;
}
/// Global routing table of the processor interface: 16 doublewords, same entry layout as pi_local_table, indexed by the high NASID bits (the PROM loops 0 (established)
pub mod pi_global_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150021400;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// Route override entry of the processor interface; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header IN (established)
pub mod pi_over_ride_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150021480;
}
/// Local routing table of network interface port 0: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction (established)
pub mod ni0_local_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150022000;
    pub const COUNT: u32 = 128;
    pub const STRIDE: u64 = 8;
}
/// Global routing table of network interface port 0: 16 doublewords, same entry layout as ni0_local_table, indexed by the high NASID bits (the PROM loops (established)
pub mod ni0_global_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150022400;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// Route override entry of network interface port 0; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header I (established)
pub mod ni0_over_ride_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150022480;
}
/// Local routing table of network interface port 1: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (direction (established)
pub mod ni1_local_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150023000;
    pub const COUNT: u32 = 128;
    pub const STRIDE: u64 = 8;
}
/// Global routing table of network interface port 1: 16 doublewords, same entry layout as ni1_local_table, indexed by the high NASID bits (the PROM loops (established)
pub mod ni1_global_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150023400;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// Route override entry of network interface port 1; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The header I (established)
pub mod ni1_over_ride_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150023480;
}
/// Local routing table of the memory and directory unit: 128 doublewords, indexed by the low 7 bits of the destination NASID. Fields: DIR0 bits 3:0 (dire (established)
pub mod md_local_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150024000;
    pub const COUNT: u32 = 128;
    pub const STRIDE: u64 = 8;
}
/// Global routing table of the memory and directory unit: 16 doublewords, same entry layout as md_local_table, indexed by the high NASID bits (the PROM l (established)
pub mod md_global_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150024400;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// Route override entry of the memory and directory unit; bit 63 is ENABLE (header), and when set the entry bypasses the local and global tables. The hea (established)
pub mod md_over_ride_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150024480;
}
/// NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*; the PROM addresses it as base + port * 0x200). Virtual-channel switch control of the cro (established)
pub mod xnni_vcswitch_flow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500303a0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 512;
}
/// NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). FIFO 0/2 flow limits of the crossbar-to- (established)
pub mod xnni_fifo02_flow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500303c0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 512;
}
/// NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). FIFO 1/3 flow limits of the crossbar-to- (established)
pub mod xnni_fifo13_flow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500303d0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 512;
}
/// NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). NI flow limits of the crossbar-to-NI pat (established)
pub mod xnni_ni_flow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500303e0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 512;
}
/// NI port 0 at this offset, port 1 is 0x200 higher (SH_XNNI1_*, PROM-confirmed for DEAD_FLOW at 0x1_5003_05f0). dead-lock flow limits of the crossbar-to (established)
pub mod xnni_dead_flow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500303f0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 512;
}
/// NI port 0 at this offset, port 1 is 0x200 higher. Age value stamped on outgoing packets: REQUEST_INJECT bits 7:0, REPLY_INJECT bits 15:8 (header). Slo (established)
pub mod xnni_inject_age {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150030400;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 512;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_lb_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031110;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_lb_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031120;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_lb_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031130;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ii_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031140;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ii_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031150;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ii_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031160;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ii_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031170;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_md_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031180;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_md_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031190;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_md_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500311a0;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_md_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500311b0;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_pi_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500311c0;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_pi_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500311d0;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_pi_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500311e0;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_pi_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500311f0;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ni0_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031200;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ni0_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031210;
}
/// A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a  (established)
pub mod xn_iilb_ni0_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031220;
}
/// A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a  (established)
pub mod xn_iilb_ni0_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031230;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ni1_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031240;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_iilb_ni1_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031260;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it twice per node (first and last of the five lists), as an 8-byte store through the g (established)
pub mod xn_iilb_ni1_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031270;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_pi_iilb_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031300;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_pi_iilb_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031310;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_pi_iilb_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031320;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_pi_iilb_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031330;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_pi_ni0_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031340;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 a (established)
pub mod xn_pi_ni0_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031360;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 a (established)
pub mod xn_pi_ni0_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031370;
}
/// A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a  (established)
pub mod xn_pi_sic_cmp_exp_hdr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500313c0;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM zeroes once per node; no reader was found. A model mus (established)
pub mod xn_pi_sic_cmp_exp_hdr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500313d0;
}
/// A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a  (established)
pub mod xn_pi_sic_cmp_hdr_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500313e0;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM zeroes once per node; no reader was found. A model mus (established)
pub mod xn_pi_sic_cmp_hdr_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500313f0;
}
/// Progress history of processor slice n (n = cr.lid bits 26:23, 0 to 3), 16 bytes apart; the name is ours. Every progress code is written as: read the w (established)
pub mod cpu_hist {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031500;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// Firmware flag word; the name is ours. SAL_A's election winner writes 0 to it, and a later routine writes 0 to it on another node through the node-obje (inferred)
pub mod fw_word_1540 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031540;
}
/// Firmware per-processor state word; the name is ours. The winner of the SAL_A election zeroes it. Bits the PROM uses: 21 + slice (tested in 0xffa1d430, (established)
pub mod cpu_bits {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031550;
}
/// Firmware debug-switch word; the name is ours. SAL_A's election winner zeroes it; the PROM later stores the L1's reply to request 0x0001 and tests bits (inferred)
pub mod fw_debug_word {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031560;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM loads, stores and zeroes; the values it keeps are not  (established)
pub mod xn_md_ni0_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031570;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM uses as a counter, loading it and storing the value pl (established)
pub mod xn_md_ni1_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031580;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM sets to 0xff00000000 and reads back per slice. A model (established)
pub mod xn_md_ni1_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031590;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 a (established)
pub mod xn_md_ni1_cmp_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500315a0;
}
/// A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a  (established)
pub mod xn_md_ni1_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500315b0;
}
/// A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a  (established)
pub mod xn_md_sic_cmp_exp_hdr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500315c0;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM sets to 0xff00000000 and reads back per slice. A model (established)
pub mod xn_md_sic_cmp_hdr_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1500315e0;
}
/// A debug-compare word of the node crossbar that the PROM uses as plain storage: a word the PROM only reads, through the global window of a NASID it is  (established)
pub mod xn_md_sic_cmp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031600;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_md_sic_cmp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031610;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_md_sic_cmp_data2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031620;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_md_sic_cmp_data3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031630;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_md_sic_cmp_data_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031640;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_md_sic_cmp_data_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031650;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_md_sic_cmp_data_enable2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031660;
}
/// A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes (established)
pub mod xn_md_sic_cmp_data_enable3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031670;
}
/// Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor  (established)
pub mod junk_bus_led {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x7fed00000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
pub const IPI_BASE_VALUE: u32 = 0xfee; // established
pub const PIO_WRITE_STATUS_ALIAS_CLEAR: u32 = 0x7; // established
pub const PIO_WRITE_STATUS_IDLE: u64 = 0x3f00000000000000; // established
pub const PI_CAM_WAR_VALUE: u64 = 0x8000000000000010; // established
pub const RTC_CONFIG_MASK: u64 = 0xff3ffffffefffff; // established
pub const RTC_ENABLE_MASK: u32 = 0x1; // established
pub const RTC_MASK: u64 = 0x7fffffffffffff; // established
pub const SHUB_1_1_MAX_REVISION: u32 = 0x2; // established
