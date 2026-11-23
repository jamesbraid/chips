// @generated from devices/shub/registers.shub2.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 25a65e6adabd41724ca20aa7682efa4524185c9de88bf41c87116f7cdc9663a8
// SHub 2 registers outside the I/O interface, differences from SHub 1
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// DIMM population word. One routine (0xff482c60) merges the discovered DIMM layout into the old value: the preserved bits are 38 and above and bits 7, 1 (established)
pub mod x_dimm_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10000;
    pub mod clk_en { // bits 37:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod freq { // bits 35:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_cs { // bits 30:29, inferred
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_rev { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_2bk { // bits 27:27, inferred
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_size { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_cs { // bits 22:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_rev { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_2bk { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_size { // bits 18:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_cs { // bits 14:13, inferred
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_rev { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_2bk { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_size { // bits 10:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_cs { // bits 6:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_rev { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_2bk { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_size { // bits 2:0, inferred
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
/// Same layout and value as X_DIMM_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no sou (established)
pub mod y_dimm_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10008;
    pub mod clk_en { // bits 37:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod freq { // bits 35:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_cs { // bits 30:29, inferred
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_rev { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_2bk { // bits 27:27, inferred
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_size { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_cs { // bits 22:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_rev { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_2bk { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_size { // bits 18:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_cs { // bits 14:13, inferred
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_rev { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_2bk { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_size { // bits 10:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_cs { // bits 6:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_rev { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_2bk { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_size { // bits 2:0, inferred
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
/// Same layout and value as X_DIMM_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no sou (established)
pub mod jnr_dimm_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10010;
    pub mod clk_en { // bits 37:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod freq { // bits 35:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_cs { // bits 30:29, inferred
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_rev { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_2bk { // bits 27:27, inferred
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm3_size { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_cs { // bits 22:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_rev { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_2bk { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm2_size { // bits 18:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_cs { // bits 14:13, inferred
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_rev { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_2bk { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm1_size { // bits 10:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_cs { // bits 6:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_rev { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_2bk { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_size { // bits 2:0, inferred
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
/// On-die-termination configuration. Only the one field below is written by the memory bring-up read; it is copied from the Y register. Offset in the loc (established)
pub mod x_odt_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10018;
    pub mod bits_23_20 { // bits 23:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory controller timing word. The firmware writes the same value to X and Y: 0x4856_5320_3324_110e, built from the old Y value by clearing bit 0, set (established)
pub mod x_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10020;
    pub mod ta_dlys { // bits 39:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_0 { // bits 0:0, inferred
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
/// Read and write select delays. The firmware keeps bits 63:25 and sets bits 24:0 to 0x254215 (fields below). Offset in the local window (add 0x2_0000_00 (established)
pub mod x_dqct_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10028;
    pub mod bits_24_20 { // bits 24:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_19_16 { // bits 19:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_15_12 { // bits 15:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_11_8 { // bits 11:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_7_4 { // bits 7:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_3_0 { // bits 3:0, inferred
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
/// Refresh control. The firmware reads the Y register, replaces bits 27:8 (and clears bits 27:24 at site 0xff485d0c), merges the enable byte and writes t (established)
pub mod x_refresh_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10030;
    pub mod hold { // bits 22:17, inferred
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
    pub mod enable { // bits 7:0, inferred
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
/// Same layout as X_ODT_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines (established)
pub mod y_odt_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10048;
    pub mod bits_23_20 { // bits 23:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Same layout as X_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines the (established)
pub mod y_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10050;
    pub mod ta_dlys { // bits 39:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_0 { // bits 0:0, inferred
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
/// Same layout and value as X_DQCT_CFG. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no sou (established)
pub mod y_dqct_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10058;
    pub mod bits_24_20 { // bits 24:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_19_16 { // bits 19:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_15_12 { // bits 15:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_11_8 { // bits 11:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_7_4 { // bits 7:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bits_3_0 { // bits 3:0, inferred
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
/// Same layout as X_REFRESH_CONTROL. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source (established)
pub mod y_refresh_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10060;
    pub mod hold { // bits 22:17, inferred
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
    pub mod enable { // bits 7:0, inferred
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
/// Written once with 0x4e20_0400. The PROM name suggests two time fields (bits 15:0 and 51:16); the code does not split the value. Offset in the local wi (established)
pub mod mem_red_black {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10078;
}
/// Miscellaneous memory controller word. The firmware writes 0x0fc4_0000_000c_4c4c once, then clears bit 58 when a masked size argument exceeds 0x3ff and (established)
pub mod misc_mem_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10080;
    pub mod bit_59 { // bits 59:59, inferred
        pub const SHIFT: u32 = 59;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_58 { // bits 58:58, inferred
        pub const SHIFT: u32 = 58;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// PIO request credit control. The first-stage firmware writes 2; the node set-up table writes 0xf9_0000_0000 to register 0xd8, a different register. Off (established)
pub mod pio_rq_crd_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100d8;
}
/// Credit depth register; the firmware writes 0xc. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is t (established)
pub mod pi_md_rq_crd_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100e0;
}
/// Credit depth register; the firmware writes 0x4. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is t (established)
pub mod pi_md_rp_crd_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100e8;
}
/// Credit depth register; the firmware writes 0xb. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is t (established)
pub mod xn_md_rq_crd_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100f0;
}
/// Credit depth register; the firmware writes 0x3. The PROM name gives a 6-bit depth field. Offset in the local window (add 0x2_0000_0000); the name is t (established)
pub mod xn_md_rp_crd_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100f8;
}
/// Start address of a memory test block. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no so (established)
pub mod mmrbist_base {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20080;
}
/// Memory test control: the early path writes 0x11_0000_0010 and polls bit 40 clear (for up to 2,000,000 microseconds). The other fields of the PROM name (established)
pub mod mmrbist_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20088;
    pub mod in_progress { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Directory configuration. The firmware reads it and merges: bits 2:0 from the node count, clears bits 11 and 10 by size tests, sets bit 3 and bit 15. T (established)
pub mod dir_config_dqlp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30000;
    pub mod bit_15 { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_11 { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_10 { // bits 10:10, inferred
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_3 { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sys_size { // bits 2:0, inferred
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
/// Eight local-vector registers 0x10 apart, all set to ones at initialisation. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own (established)
pub mod dir_locvec_dqlp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30200;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 16;
}
/// Eight registers 0x10 apart written with constants in order: 0x4bfff, 0xc96f25b, 0xfffffff, 0x96ffff, 0, 0, 0x4803f, 0x48000. Not all ones, so the writ (established)
pub mod dir_privec_dqlp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30300;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 16;
}
/// Written once with 0x1000 (bit 12). Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no sourc (established)
pub mod dir_timer_dqlp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30400;
}
/// AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register- (established)
pub mod amo_cfg_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x34800;
    pub mod bits_3_2 { // bits 3:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test pattern register, high half; written with the arm bit. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register (established)
pub mod x_bist_h {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod arm { // bits 43:43, inferred
        pub const SHIFT: u32 = 43;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_41 { // bits 41:41, inferred
        pub const SHIFT: u32 = 41;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_40 { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pattern { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test pattern register, low half; same value without the arm bit. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own reg (established)
pub mod x_bist_l {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38010;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod bit_41 { // bits 41:41, inferred
        pub const SHIFT: u32 = 41;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_40 { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pattern { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test error register, high half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's (established)
pub mod x_bist_err_h {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38020;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod val { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pat { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test error register, low half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's  (established)
pub mod x_bist_err_l {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38030;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod val { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pat { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Y-side twin of X_BIST_H. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines  (established)
pub mod y_bist_h {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38800;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod arm { // bits 43:43, inferred
        pub const SHIFT: u32 = 43;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_41 { // bits 41:41, inferred
        pub const SHIFT: u32 = 41;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_40 { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pattern { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Y-side twin of X_BIST_L. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines  (established)
pub mod y_bist_l {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38810;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod bit_41 { // bits 41:41, inferred
        pub const SHIFT: u32 = 41;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit_40 { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pattern { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test error register, high half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's (established)
pub mod y_bist_err_h {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38820;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod val { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pat { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test error register, low half, read after a failure; reads 0 on a pass. Offset in the local window (add 0x2_0000_0000); the name is the PROM's  (established)
pub mod y_bist_err_l {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38830;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod val { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pat { // bits 39:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register- (established)
pub mod amo_cfg_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4b000;
    pub mod bits_3_2 { // bits 3:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Twin of DIR_CONFIG_DQLP; the firmware writes the same value. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name  (established)
pub mod dir_config_dqrp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50000;
}
/// Eight registers 0x10 apart, all set to ones. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux (established)
pub mod dir_locvec_dqrp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50200;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 16;
}
/// Twin of DIR_PRIVEC_DQLP, same values. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no so (established)
pub mod dir_privec_dqrp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50300;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 16;
}
/// Twin of DIR_TIMER_DQLP. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux; no source defines t (established)
pub mod dir_timer_dqrp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50400;
}
/// AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register- (established)
pub mod amo_cfg_2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x54800;
    pub mod bits_3_2 { // bits 3:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// AMO cache configuration: the firmware reads it and sets bits 3:2. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register- (established)
pub mod amo_cfg_3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x6b000;
    pub mod bits_3_2 { // bits 3:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR windo (established)
pub mod ipi_int {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10000380;
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
/// Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and  (established)
pub mod rtc_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10001480;
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
    pub const OFFSET: u64 = 0x10001500;
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
    pub const OFFSET: u64 = 0x10010000;
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
    pub const OFFSET: u64 = 0x10010008;
}
/// Junk-bus access timing, written once by the first-stage firmware with 0xffff_ffff_0003. Meaning of the value is inferred from the PROM name; the hardw (established)
pub mod junk_bus_time {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10020000;
}
/// Four registers, one per slice, 0x80 apart, that the firmware reads only to remember the progress code it last wrote while it waits on a lock. Any valu (established)
pub mod junk_bus_led_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10030000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// L1 UART transmit data: eight packet bytes per write, padded with 0x7e after the frame. Offset in the local window (add 0x2_0000_0000); the name is the (established)
pub mod asic_to_l1_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10038000;
}
/// L1 UART transmit status: bit 0 set means busy; the firmware polls it clear before each write, 10 microseconds apart, for up to 5,000,000 microseconds. (established)
pub mod asic_to_l1_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10038080;
    pub mod busy { // bits 0:0, inferred
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
/// L1 UART receive data: eight bytes per word, the first byte in bits 7:0. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own reg (established)
pub mod l1_to_asic_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10038100;
}
/// L1 UART receive status: bit 0 set means a word is waiting; the firmware writes 0 to release it. Offset in the local window (add 0x2_0000_0000); the na (established)
pub mod l1_to_asic_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10038180;
    pub mod data_ready { // bits 0:0, inferred
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
/// Rack and slot data provided by the L1 controller; the firmware reads it only on paths this page does not reach on a normal boot. Offset in the local w (established)
pub mod rack_slot_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10038200;
    pub mod byte { // bits 23:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod number { // bits 15:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod code { // bits 3:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit0 { // bits 0:0, inferred
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
/// Clock source control for the real-time clock. The PROM converts counter ticks to microseconds as counter * (max_count * 10 + 10) / 1000, so with max_c (established)
pub mod gc_src_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10060700;
    pub mod source_sel { // bits 33:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod max_count { // bits 13:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable_counter { // bits 0:0, established
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
/// Which processors may send interprocessor interrupts to this one: four registers, one per processor slice (SH2_IPI_ACCESS0 to 3). Defined by the header (established)
pub mod ipi_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10060c00;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// The node's identification word. Read by the firmware to find its own node number (bits 45:32) and the sharing parameters; written during the interconn (established)
#[allow(clippy::module_inception)]
pub mod node_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10060f00;
    pub mod range_check { // bits 55:55, established
        pub const SHIFT: u32 = 55;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sharers_1k { // bits 54:54, established
        pub const SHIFT: u32 = 54;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod nodes_per_bit { // bits 53:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sharing_mode { // bits 47:46, established
        pub const SHIFT: u32 = 46;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node_id { // bits 45:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x3fff;
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
/// Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for proce (established)
pub mod int_cmp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101b0080;
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
/// Node election word: each slice writes slice + 1 through the alias and reads it back; the winner is the one that reads its own value. Plain storage sat (established)
pub mod scratch1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0080;
}
/// Write path onto the SCRATCH1 word; the relation is inferred from the use. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own r (established)
pub mod scratch1_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0088;
}
/// Firmware mailbox word for the L1 console link. Plain storage satisfies the code; the fields are how the 10.54 firmware uses it, names are ours. Offset (established)
pub mod scratch2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0100;
    pub mod clear_bit { // bits 63:63, inferred
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rx_index { // bits 62:58, inferred
        pub const SHIFT: u32 = 58;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod channel { // bits 54:50, inferred
        pub const SHIFT: u32 = 50;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sequence { // bits 49:42, inferred
        pub const SHIFT: u32 = 42;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod state { // bits 41:39, inferred
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
/// Release side of the second firmware lock; the alias 0x08 above is the take side. Whether a read of the alias takes the lock in hardware is unknown; a  (established)
pub mod scratch3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0180;
}
/// Take side of the second firmware lock. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-name table, not Linux. (established)
pub mod scratch3_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0188;
}
/// Release side of the node lock that guards SCRATCH6 and SCRATCH7. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register-n (established)
pub mod scratch4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0200;
}
/// Take side of the node lock; a plain register that always reads 0 satisfies every access. Offset in the local window (add 0x2_0000_0000); the name is t (established)
pub mod scratch4_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0208;
}
/// Claim bits of the second firmware lock: the firmware sets a bit to claim a resource (bit 0 for the barrier, bit 7 for the console link, bit 0xf for a  (established)
pub mod scratch5 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0280;
}
/// Shared firmware word guarded by the node lock: slice present and arrival bits, the barrier flag and a per-slice-pair field. Plain storage; names of th (established)
pub mod scratch6 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0300;
    pub mod pair1_state { // bits 52:50, inferred
        pub const SHIFT: u32 = 50;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pair0_state { // bits 49:47, inferred
        pub const SHIFT: u32 = 47;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod barrier_busy { // bits 34:34, inferred
        pub const SHIFT: u32 = 34;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod slice_arrived { // bits 33:30, inferred
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod slice_present { // bits 29:26, inferred
        pub const SHIFT: u32 = 26;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pal_flags { // bits 24:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Second shared firmware word with the same lock cycle as SCRATCH6. Offset in the local window (add 0x2_0000_0000); the name is the PROM's own register- (established)
pub mod scratch7 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0380;
}
/// Holds the address of the firmware's node-addressing table row (the low 32 bits of the row address with bit 63 set); every later node-number read loads (established)
pub mod scratch24 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101d0c00;
}
/// Which processor slices of the node are present. The firmware tests bit 0 and bit 1 for slices 0 and 1 and wants two equal non-zero reads in a row. Off (established)
pub mod fsb_symmetric_agent_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20020010;
    pub mod cpu_1_active { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cpu_0_active { // bits 0:0, inferred
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
/// PIO write status, four instances (SHub 2 nodes carry up to four processor slices). Note the kernel indexes them out of order: slices 0, 1, 2, 3 use in (established)
pub mod pio_write_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20070200;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
    pub mod writes_ok { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
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
    pub mod write_error_address { // bits 49:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x7fffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_error { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
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
    pub mod multi_write_error { // bits 0:0, established
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
/// Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it wa (inferred)
pub mod pio_write_status_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20070208;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// V, the node-addressing selector: the PROM reads it before forming any global or TIO address and uses it unmasked as an index into a five-entry table,  (established)
pub mod address_mode {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20110000;
}
/// Remote flash remap: the PROM writes the enable bit and a 9-bit field it takes from bits 32:24 of its argument. Meaning of the fields is inferred from  (established)
pub mod firmware_remap {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20110008;
    pub mod enable { // bits 60:60, established
        pub const SHIFT: u32 = 60;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod offset { // bits 32:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// The first-stage firmware reads it and compares the whole word with zero to choose which bit pair of the PAL argument becomes the slice number in cr.li (established)
pub mod processor_type {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20110010;
    pub mod code { // bits 0:0, inferred
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
/// Block transfer engine control and status, one per engine, SHub 2 (four engines, SH2_BT_ENG_CSR_0 to 3). Unlike SHub 1 the kernel starts a transfer wit (established)
pub mod bt_eng_csr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod error_code { // bits 41:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod notify { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod zero_fill { // bits 24:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod busy { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod error { // bits 16:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod length { // bits 15:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// BTE source address, per engine. The kernel converts the physical address to the network address form first (nasid moved to bit 40 upward, the bank-sel (established)
pub mod bt_eng_src {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040080;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// BTE destination address, per engine; same conversion as the source. (established)
pub mod bt_eng_dest {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040100;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// BTE notification address, per engine; same conversion. (established)
pub mod bt_eng_notify {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040180;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// Board type word. The PROM stores the board type here and then checks it (accepted values 0x7b, 0x200, 0xa00, 0xe00; any other prints "unknown board ty (established)
pub mod xn_iilb_pi_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031240;
}
/// Firmware scratch word, slot 3 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_iilb_ni0_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031280;
}
/// Firmware scratch word, slot 3 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_iilb_ni0_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031290;
}
/// Firmware scratch word, slot 2 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_iilb_ni1_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x500312c0;
}
/// Firmware scratch word, slot 2 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_iilb_ni1_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x500312d0;
}
/// Per-slice word 2 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table).  (established)
pub mod xn_md_ni1_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031590;
}
/// Per-slice word 3 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table).  (established)
pub mod xn_md_ni1_cmp_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x500315b0;
}
/// Firmware scratch word, slot 0 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_md_sic_cmp_exp_hdr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x500315c0;
}
/// Firmware scratch word, slot 0 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_md_sic_cmp_exp_hdr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x500315d0;
}
/// Per-slice word 0 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table).  (established)
pub mod xn_md_sic_cmp_hdr_enable0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x500315e0;
}
/// Per-slice word 1 of the four read by the processor lookup (the compact-id lookup picks it by bits 9:7 of the id; a second routine reads it by table).  (established)
pub mod xn_md_sic_cmp_hdr_enable1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x500315f0;
}
/// Firmware scratch word, slot 0 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_ni0_iilb_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031700;
}
/// Firmware scratch word, slot 1 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_ni0_iilb_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031710;
}
/// Firmware scratch word, slot 2 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_ni0_llp_cmp_exp_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031800;
}
/// Firmware scratch word, slot 3 of the group-c list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_ni0_llp_cmp_exp_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031810;
}
/// Firmware scratch word, slot 1 of the group-b list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_ni0_md_cmp_exp_hdr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031b40;
}
/// Firmware scratch word, slot 1 of the group-a list the node set-up zeroes (three lists of four, indexed by slice). Its use after the zeroing was not tr (established)
pub mod xn_ni0_md_cmp_exp_hdr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50031b50;
}
/// Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor  (established)
pub mod junk_bus_led {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xf0000000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// Purge translation cache message, SHub 2 (header SH2_PTC). One 64-bit store per target node replaces SHub 1's two. The region id and region number do n (established)
pub mod ptc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x170000000;
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
    pub mod address { // bits 60:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1ffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ps { // bits 3:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3;
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
/// Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because  (established)
pub mod rtc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2101c0000;
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
pub const EVENT_OCCURRED_EXTIO_INT2: u64 = 0x200000000; // established
pub const EVENT_OCCURRED_EXTIO_INT3: u64 = 0x400000000; // established
pub const IPI_BASE_VALUE: u32 = 0xfee; // established
pub const PIO_WRITE_STATUS_ALIAS_CLEAR: u32 = 0x7; // established
pub const PIO_WRITE_STATUS_IDLE: u32 = 0x0; // established
pub const PI_CAM_WAR_VALUE: u64 = 0x8000000000000010; // established
pub const RTC_CONFIG_MASK: u64 = 0xff3ffffffefffff; // established
pub const RTC_ENABLE_MASK: u32 = 0x1; // established
pub const RTC_MASK: u64 = 0x7fffffffffffff; // established
pub const SHUB_1_1_MAX_REVISION: u32 = 0x2; // established
