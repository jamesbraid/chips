// @generated from devices/dm2/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 534766be60c23e754f44497a1ac59c97d036d7a9c9fb7fc107d2d08156f5526b
// DMediaPro DM2 (XT-DIGVID) XIO video board: widget window, XG block, FPGA load, GIF register file and word layouts
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub mod enums {
    pub mod fpga_kind {
        pub const OTHERS_HANDSHAKED: u32 = 0; // established
        pub const GIF: u32 = 1; // established
        pub const OTHERS_BLIND: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            OthersHandshaked,
            Gif,
            OthersBlind,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::OthersHandshaked,
                    1 => Self::Gif,
                    2 => Self::OthersBlind,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::OthersHandshaked => 0,
                    Self::Gif => 1,
                    Self::OthersBlind => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod vbob_pipe {
        pub const OUTPUT: u32 = 0; // established
        pub const INPUT: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Output,
            Input,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Output,
                    1 => Self::Input,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Output => 0,
                    Self::Input => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod xg_mapram_type {
        pub const K32X36: u32 = 0; // established
        pub const K64X18: u32 = 1; // established
        pub const K128X9: u32 = 2; // established
        pub const INVALID: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            K32x36,
            K64x18,
            K128x9,
            Invalid,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::K32x36,
                    1 => Self::K64x18,
                    2 => Self::K128x9,
                    3 => Self::Invalid,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::K32x36 => 0,
                    Self::K64x18 => 1,
                    Self::K128x9 => 2,
                    Self::Invalid => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Widget identification, read by the diagnostic only; the kernel never reads it. The field split is established; the readback value is unknown (the part (established)
pub mod widget_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
    pub mod revision { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod part { // bits 27:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod manufacturer { // bits 11:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Widget status. The kernel reads it once at attach and tests bit 5 only: when set it prints that the XIO slot is the slower 400 MB/s kind. The test is  (established)
pub mod widget_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc;
    pub mod link_slow { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Widget control (the diagnostic calls it the XG control register). The init routine stores widget id, interrupt target and a constant, then ORs the XG  (established)
pub mod widget_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x24;
    pub mod int_target { // bits 25:22, inferred
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xg_error_int_enable { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod const_bit14 { // bits 14:14, unknown
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod const_bit9 { // bits 9:9, unknown
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod widget_number { // bits 3:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Request timeout, the odd word of common-block slot 0x28. The only access in the shipped software is a store of 0 in the routine the XG init routine ca (established)
pub mod xg_req_timeout {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2c;
}
/// Interrupt destination, upper: address bits 47:32 in the low half and the target widget id above them, from the interrupt object the kernel allocated f (established)
pub mod int_dest_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
    pub mod target_id { // bits 19:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr_hi { // bits 15:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt destination, lower: the low 32 bits of the interrupt address. (established)
pub mod int_dest_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x3c;
    pub mod addr_lo { // bits 31:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// XG interrupt vectors. In the common widget block this slot is an error command word; in the XG it holds interrupt vectors, so the common role does not (established)
pub mod xg_int_vectors {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x5c;
    pub mod error_vector { // bits 25:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod const_bit17 { // bits 17:17, inferred
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gv1_vector { // bits 16:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod const_bit8 { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gv0_vector { // bits 7:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// XG configuration, read at attach and by the diagnostic; read-only from software. The subsystem field must read 1. The map-RAM size code is printed by  (established)
pub mod xg_config {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x64;
    pub mod mapram_type { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::xg_mapram_type::Value;
    }
    pub mod mapram_size_code { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod subsystem { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// XG error cause, one bit per error. The error handler reads it, writes the same value back before decoding, and prints one message per set bit. That th (established)
pub mod xg_error_cause {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x6c;
    pub mod bit31_untested { // bits 31:31, unknown
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_write_full_fifo { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_write_too_few { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod idma_resp_invalid_tag { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod idma_resp_size { // bits 27:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod odma_fifo_overflow { // bits 26:26, established
        pub const SHIFT: u32 = 26;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd_fifo_overflow { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gfx_dword_credit_underflow { // bits 24:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gfx_dword_credit_overflow { // bits 23:23, established
        pub const SHIFT: u32 = 23;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gfx_cacheline_credit_underflow { // bits 22:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gfx_cacheline_credit_overflow { // bits 21:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_resp_credit_underflow { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_resp_credit_overflow { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_req_credit_underflow { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_req_credit_overflow { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_bus_parity { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_bus_data_parity { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_bus_cmd_parity { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mapram_invalid { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mapram_parity { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gfx_fifo_overflow { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_request { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_response { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_read_req_timeout { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_bad_command { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalk_address { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_bad_interrupt { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_bad_command { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_valid_when_idle { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_pio_cmd_resp_overflow { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_pio_data_resp_overflow { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod guava_overlap { // bits 0:0, established
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
/// High/low water mark (the diagnostic's name). The init routine keeps the two 6-bit fields from the current value, forces bits 15:0 to a constant and bi (established)
pub mod xg_water_mark {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x74;
    pub mod forced_zero { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mark_b { // bits 27:22, inferred
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mark_a { // bits 21:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fixed_low { // bits 15:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Offending map-RAM entry address, read after a map-RAM parity or invalid error and printed as five hex digits. Read-only is inferred. (established)
pub mod xg_mapram_err_addr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x94;
    pub mod entry_addr { // bits 19:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Board identity one-wire register, read through the shared one-wire accessor. The offset and accessor are established; the bit protocol is not in the d (established)
pub mod xg_nic {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x9c;
    pub mod storage { // bits 15:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod onewire { // bits 1:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// GIF FPGA programming and status register. Read layout (this register): DONE and INIT for each FPGA in adjacent bit pairs. The message calls the GIF IN (established)
pub mod fpga_prog {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x120000;
    pub mod clink_init { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clink_done { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hdoc_init { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hdoc_done { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod vif_init { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod vif_done { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod oxcc_init { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod oxcc_done { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ixcc_init { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ixcc_done { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod unpacker_init { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod unpacker_done { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod packer_init { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod packer_done { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gif_init { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gif_done { // bits 0:0, established
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
/// GIF reset/enable word (register number 0x00). The init routine stores 0 when asked to reinitialise; the FPGA load path polls for a value of 0x80. The  (established)
pub mod gif_reset {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800004;
}
/// Per-FPGA programming control (register number 0x08), for the seven FPGAs behind the GIF. The select word is one-hot and bit 7 is a strobe level (idle  (established)
pub mod gif_prog_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80000c;
    pub mod prog_strobe { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fpga_select { // bits 6:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Per-pipe DMA control word, indexed by pipe (pipe 0 at register number 0x10, pipe 1 at 0x38). The driver keeps a shadow and rewrites the whole word. Bi (established)
pub mod pipe_dma_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800014;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 40;
    pub mod int_enable { // bits 16:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cfg_bit12 { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cfg_bit10 { // bits 10:10, inferred
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cfg_bit9 { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod abort { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod slot_valid { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Per-pipe raster start address 1 (register numbers 0x18 and 0x40). The value must be below 16 MiB (the driver rejects larger ones). The diagnostic does (established)
pub mod pipe_start_addr1 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80001c;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 40;
    pub mod start_addr { // bits 23:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Per-pipe raster start address 2 (register numbers 0x20 and 0x48), same range test as start address 1. Alignment is inferred. (established)
pub mod pipe_start_addr2 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800024;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 40;
    pub mod start_addr { // bits 23:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Per-pipe video control (register numbers 0x28 and 0x50; the diagnostic's IDMA_OV and ODMA_IV). Formula and width are established, exactly the 26 bits  (established)
pub mod pipe_vid_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80002c;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 40;
    pub mod flag_nonzero { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flag_zero { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count_hi { // bits 23:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count_lo { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Per-pipe video control 2 (register numbers 0x30 and 0x58): the low 12 bits of an argument. Meaning unknown. (established)
pub mod pipe_vid_control2 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800034;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 40;
    pub mod value { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Pipe 1 per-pipe word (register number 0x60), stored 0 when the pipe's status buffer is set up and by the clink-timeout path. The stores and the pipe a (inferred)
pub mod pipe1_ring_ptr_reset {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800064;
}
/// Pipe 1 per-pipe word (register number 0x68), stored 0 at DMA start. Meaning unknown. (established)
pub mod pipe1_reset_word {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80006c;
}
/// Pipe 0 per-pipe word (register number 0x70), stored 0 when the pipe's status buffer is set up and by the clink-timeout path. The stores and the pipe a (inferred)
pub mod pipe0_ring_ptr_reset {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800074;
}
/// Pipe 0 per-pipe word (register number 0x78), stored 0 at DMA start. Meaning unknown. (established)
pub mod pipe0_reset_word {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80007c;
}
/// GIF identification (register number 0x80). Read once, by the GIF initialisation routine, which runs only from the board-reset ioctl when its argument  (established)
pub mod gif_ident {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800084;
    pub mod magic { // bits 31:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod version { // bits 7:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Register number 0x88, stored 0 by the UST initialisation just before the host UST is sampled. The store is established; that it is the board's own UST (inferred)
pub mod ust_msc_counter {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80008c;
}
/// Packer register number 0x800. The library's per-pipe init stores a constant (see PACK_INIT_R0800). Roles unknown. (established)
pub mod pack_r0800 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800804;
}
/// Packer register number 0x808. Init constant PACK_INIT_R0808. Roles unknown. (established)
pub mod pack_r0808 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80080c;
}
/// Packer register number 0x810. Init constant PACK_INIT_R0810. Roles unknown. (established)
pub mod pack_r0810 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800814;
}
/// Packer miscellaneous select (register number 0x820, the diagnostic's PACK_MISC_SEL). Name and storage mask (bits 2 and 0) are established; the library (established)
pub mod pack_misc_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800824;
    pub mod storage_bit2 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod storage_bit0 { // bits 0:0, established
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
/// Packer register number 0x840. Init value is 0x1000 for pipe 1 (PACK_INIT_R0840). Roles unknown. (established)
pub mod pack_r0840 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800844;
}
/// Packer register number 0x848. Init constant PACK_INIT_R0848. Roles unknown. (established)
pub mod pack_r0848 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80084c;
}
/// Packer register number 0x850. Init constant PACK_INIT_R0850. Roles unknown. (established)
pub mod pack_r0850 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x800854;
}
/// Unpacker register number 0x1000. Init constant UNPACK_INIT_R1000. Roles unknown. (established)
pub mod unpack_r1000 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801004;
}
/// Unpacker register number 0x1008. Init constant UNPACK_INIT_R1008. Roles unknown. (established)
pub mod unpack_r1008 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80100c;
}
/// Unpacker VERSION_SEL (register number 0x1010). Name only; the diagnostic's storage mask is 0, which means not tested rather than read-only. Role unkno (established)
pub mod unpack_version_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801014;
}
/// Unpacker MISC_SEL (register number 0x1018). The library stores 0x0fffe0f9 with a flag shifted into bit 28 (UNPACK_INIT_MISC_BASE); the diagnostic's st (established)
pub mod unpack_misc_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80101c;
    pub mod flag28 { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod diag_storage_hi { // bits 11:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod diag_storage_lo { // bits 0:0, established
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
/// Unpacker IDMA_DATA0_SEL and IDMA_DATA1_SEL (register numbers 0x1020 and 0x1028). Names only; diagnostic mask 0. Roles unknown. (established)
pub mod unpack_idma_data_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801024;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8;
}
/// Unpacker OVFIFO_TEST_PATTERN0_SEL and OVFIFO_TEST_PATTERN1_SEL (register numbers 0x1030 and 0x1038). Names only; diagnostic mask 0. Roles unknown. (established)
pub mod unpack_ovfifo_test_pattern_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801034;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8;
}
/// Unpacker register number 0x1040. Init value is 0x1200 for pipe 0 (UNPACK_INIT_R1040). Roles unknown. (established)
pub mod unpack_r1040 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801044;
}
/// Unpacker register number 0x1048. Init constant UNPACK_INIT_R1048. Roles unknown. (established)
pub mod unpack_r1048 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80104c;
}
/// VIF control (register number 0x1800, the diagnostic's CONTROL_SEL). Formula and width (14 bits) are established, matching the diagnostic's storage mas (established)
pub mod vif_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801804;
    pub mod nonzero_test { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row_word1 { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod const_7 { // bits 10:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod err_clear { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sd_flag { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode_sel { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit0 { // bits 0:0, established
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
/// VIF enable (register number 0x1808, the diagnostic's ENABLE_SEL); the kernel stores the pipe's second shadow word here and abort clears bit 0. The sto (established)
pub mod vif_enable {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80180c;
    pub mod bit1 { // bits 1:1, unknown
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable { // bits 0:0, inferred
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
/// Register number 0x1810. The diagnostic writes it between every write and read-back of the other VIF registers, a bus-hold or clearing write. The relea (inferred)
pub mod vif_scratch {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801814;
    pub mod err_flag { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// VIF DMUX register (register number 0x1828, the diagnostic's DMUX_REG_SEL). Bits 2:0 are a small selector (0 on the path read), bits 4:3 a two-bit mode (established)
pub mod vif_dmux {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80182c;
    pub mod bit7 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod path_is_10 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 4:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod selector { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// VIF field 0 active video (register number 0x1880): two 11-bit line numbers computed from the format row's line count and the path's start offsets. Wha (established)
pub mod vif_f0_actvid {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801884;
    pub mod line1 { // bits 21:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod line0 { // bits 10:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// VIF field 1 active video (register number 0x1888): same layout as field 0. (established)
pub mod vif_f1_actvid {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80188c;
    pub mod line1 { // bits 21:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod line0 { // bits 10:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// VIF lines per frame (register number 0x1890): the format row's total line count minus 1 (1124 for the 1125-line HD rows). (established)
pub mod vif_lines_per_frame {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x801894;
}
/// HDOC status (register number 0x2000). The library sets bit 24 as a hold-off before writing the other HDOC registers and clears it after; the final val (established)
pub mod hdoc_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802004;
    pub mod hold_off { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flag17 { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flag12 { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flag11 { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flag10 { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sel_9_7 { // bits 9:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sel_6_5 { // bits 6:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sel_1_0 { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC enable (register number 0x2008, the diagnostic's ENABLE_SEL); the kernel stores the pipe's second shadow here and abort clears bit 0. The out-pip (established)
pub mod hdoc_enable {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80200c;
    pub mod enable { // bits 0:0, inferred
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
/// HDOC format (register number 0x2010): total lines minus 1 and samples per line minus 1, from format-row words (1125 lines and 2200 samples for 1080i a (established)
pub mod hdoc_format {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802014;
    pub mod lines_minus_1 { // bits 22:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod samples_minus_1 { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC xcc_rden (register number 0x2018): active width plus 41 in the low 12 bits, with constant bits 17, 15 and 12 (0x29000). Formula established; mean (established)
pub mod hdoc_xcc_rden {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80201c;
    pub mod width_plus_41 { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC trs_hblank (register number 0x2020): two 12-bit fields; the high one is active width plus 4 (standard-definition timing) or 8, the low one is 2 o (established)
pub mod hdoc_trs_hblank {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802024;
    pub mod hblank_end { // bits 23:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Five HDOC registers with one layout, in order: actvid_fld0, trs_vblank_fld0, actvid_fld1, trs_vblank_fld1, field (register numbers 0x2028 to 0x2048).  (established)
pub mod hdoc_line_regs {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80202c;
    pub const COUNT: u32 = 5;
    pub const STRIDE: u64 = 8;
    pub mod line1 { // bits 21:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod line0 { // bits 10:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC xcc_rden2 (register number 0x2050): two 12-bit fields. Normally the first is active width plus 41 and the second is 41; when the path's geometry  (established)
pub mod hdoc_xcc_rden2 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802054;
    pub mod blank_field { // bits 23:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod width_field { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC VITC_SEL (register number 0x2058). Name and 23-bit mask only; not written by the library. (established)
pub mod hdoc_vitc_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80205c;
}
/// HDOC resync (register number 0x2060). The library reads it at init and hands the two fields to the kernel as the resync value, and writes the pair bac (established)
pub mod hdoc_resync {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802064;
    pub mod line { // bits 22:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sample { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC resync window (register number 0x2068): the resync position moved by 7 samples with carry into the line count and a wrap at the line total. Windo (established)
pub mod hdoc_resync_wndw {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80206c;
    pub mod line { // bits 22:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sample { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC data_rden (register number 0x2070): active width plus 1 or 2 in the low 12 bits and 0x1000 or 0x2000 in bits 13:12, chosen by the standard-defini (established)
pub mod hdoc_data_rden {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802074;
    pub mod mode { // bits 13:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod end { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// HDOC FIFOA_WEN_SEL and FIFOB_WEN_SEL (register numbers 0x2078 and 0x2080). Names and 24-bit masks only; not written by the library. (established)
pub mod hdoc_fifo_wen_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80207c;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8;
}
/// Eight diagnostic-only registers, register numbers 0x20b0 to 0x20e8. The diagnostic names, in order, LFIFO_TEST_PATTEN, OXCC_DATA_HI, OXCC_DATA_LO, LFI (inferred)
pub mod hdoc_diag_regs {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8020b4;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
}
/// CLINK transmit message: twelve halfword registers (register numbers 0x3800 to 0x3858) that the send ioctl fills from the 24-byte VBOB message, byte 2k (established)
pub mod clink_tx_message {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803804;
    pub const COUNT: u32 = 12;
    pub const STRIDE: u64 = 8;
    pub mod halfword { // bits 15:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// CLINK pattern-generator divider, low (register number 0x3860, the diagnostic's PGEN_LO_SEL). The library writes CLINK_PGEN_LO_INIT when configuring th (established)
pub mod clink_pgen_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803864;
    pub mod divider_lo { // bits 15:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// CLINK pattern-generator divider, high (register number 0x3868, PGEN_HI_SEL). The library writes CLINK_PGEN_HI_INIT, under the same environment-variabl (established)
pub mod clink_pgen_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80386c;
    pub mod divider_hi { // bits 7:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// CLINK KSYNC_SEL (register number 0x3870). Name and 9-bit mask only; not written by the library. (established)
pub mod clink_ksync_sel {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803874;
    pub mod storage { // bits 8:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// CLINK receive message: twelve halfword registers (register numbers 0x3880 to 0x38d8) the status-ring service routine reads when a message-received fla (established)
pub mod clink_rx_message {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803884;
    pub const COUNT: u32 = 12;
    pub const STRIDE: u64 = 8;
    pub mod halfword { // bits 15:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// CLINK UART reset (register number 0x38e0, UART_RESET_SEL): the library writes 1 then 0 at init and when an input path opens while the output pipe is i (established)
pub mod clink_uart_reset {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8038e4;
    pub mod reset { // bits 0:0, established
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
/// CLINK transmit doorbell (register number 0x38e8): the send ioctl stores 1 after filling the transmit message and arms a 250-tick timeout; the board an (established)
pub mod clink_tx_doorbell {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8038ec;
    pub mod ring { // bits 0:0, established
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
/// CLINK receive release (register number 0x38f0): the service routine stores 1 after copying a received frame; the event post routine stores a register  (established)
pub mod clink_rx_release {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8038f4;
    pub mod release { // bits 0:0, established
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
/// Diagnostic layout, input block CONTROL0 (register number 0x2800), 9 storage bits. The layout goes with the second input image, which only the diagnost (established)
pub mod ixcc_diag_control0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802804;
    pub mod storage { // bits 8:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Diagnostic layout, input block CONTROL1 (register number 0x2808), 8 storage bits. (established)
pub mod ixcc_diag_control1 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80280c;
    pub mod storage { // bits 7:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Diagnostic layout, input block LUT_CONTROL (register number 0x2810), 5 storage bits. (established)
pub mod ixcc_diag_lut_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802814;
    pub mod storage { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Diagnostic layout, input block LUT_DATA (register number 0x2818). Diagnostic mask 0: not tested rather than read-only. (established)
pub mod ixcc_diag_lut_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80281c;
}
/// Diagnostic layout, output block control (register number 0x3000), 9 storage bits. (established)
pub mod oxcc_diag_control0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803004;
    pub mod storage { // bits 8:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Diagnostic layout, output block register number 0x3008, 10 storage bits. (established)
pub mod oxcc_diag_control1 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80300c;
    pub mod storage { // bits 9:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Diagnostic layout, output block register number 0x3010, 5 storage bits. (established)
pub mod oxcc_diag_lut_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803014;
    pub mod storage { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Diagnostic layout, output block register number 0x3018. Diagnostic mask 0: not tested rather than read-only. (established)
pub mod oxcc_diag_lut_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80301c;
}
/// Input colour-converter LUT control (block base, register number 0x2800). Per component the library writes 8, then 2, 4 or 1 for component 0, 1 or 2, t (established)
pub mod ixcc_prog_lut_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802804;
}
/// Input colour-converter LUT data (register number 0x2808). Each of the 8192 entries per component is one 32-bit store carrying no index; whether the en (established)
pub mod ixcc_prog_lut_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80280c;
}
/// Input colour-converter red, green, blue and alpha offsets (register numbers 0x2810, 0x2818, 0x2820, 0x2828): format-table row words 10 to 13, as unspl (established)
pub mod ixcc_prog_offset {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802814;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 8;
}
/// Input colour converter misc (register number 0x2830): bit 0 is set when the path's conversion mode is zero and bit 8 is the mode's bit 0 shifted up. F (established)
pub mod ixcc_prog_misc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802834;
    pub mod mode_bit0 { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode_zero { // bits 0:0, established
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
/// Input colour converter alpha pair (register numbers 0x2838 and 0x2840, one failure message): the first is 4 when the standard-definition flag is set,  (established)
pub mod ixcc_prog_alpha {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80283c;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8;
}
/// Input colour converter coefficient, low 16 bits (register number 0x2848). Written before the high bit and the index. (established)
pub mod ixcc_prog_coeflo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80284c;
    pub mod value { // bits 15:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Input colour converter coefficient, bit 16 (register number 0x2850). (established)
pub mod ixcc_prog_coefhi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x802854;
    pub mod bit16 { // bits 0:0, established
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
/// Input colour converter coefficient index (register number 0x2858), 5 bits, written after the low and high parts. That it latches the coefficient is in (established)
pub mod ixcc_prog_coefind {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80285c;
    pub mod index { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Output colour-converter LUT control (block base, register number 0x3000); same sequence as the input block. (established)
pub mod oxcc_prog_lut_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803004;
}
/// Output colour-converter LUT data (register number 0x3008); same behaviour as the input block. (established)
pub mod oxcc_prog_lut_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80300c;
}
/// Output colour converter red, green and blue offsets, low 16 bits (register numbers 0x3010, 0x3020, 0x3030), from format-table row words 10 to 12. Each (established)
pub mod oxcc_prog_offset_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803014;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 16;
    pub mod value { // bits 15:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Output colour converter red, green and blue offsets, bit 16 (register numbers 0x3018, 0x3028, 0x3038). (established)
pub mod oxcc_prog_offset_bit16 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80301c;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 16;
    pub mod bit16 { // bits 0:0, established
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
/// Output colour converter around (register number 0x3040): format-table row word 13. (established)
pub mod oxcc_prog_around {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803044;
}
/// Output colour converter pack8 (register number 0x3048): 1 when the component size is 8 bits. (established)
pub mod oxcc_prog_pack8 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80304c;
}
/// Output colour converter dec (register number 0x3050): 0, or 3 or the pipe mode, chosen by the path. Offset established; formula unknown. (established)
pub mod oxcc_prog_dec {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803054;
}
/// Output colour converter coefficient, low 16 bits (register number 0x3058). (established)
pub mod oxcc_prog_coeflo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80305c;
    pub mod value { // bits 15:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Output colour converter coefficient, bit 16 (register number 0x3060). (established)
pub mod oxcc_prog_coefhi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x803064;
    pub mod bit16 { // bits 0:0, established
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
/// Output colour converter coefficient index (register number 0x3068), 5 bits, written after the low and high parts. (established)
pub mod oxcc_prog_coefind {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80306c;
    pub mod index { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word at +4 of a 28-byte FPGA info record (all fields are big-endian 32-bit words): the kind, which selects the start, byte and stop routines. (established)
pub mod fpga_info_kind {
    pub const WIDTH: u32 = 32;
    pub mod kind { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::fpga_kind::Value;
    }
}
/// Write layout of the GIF programming register: an 8-bit data byte, a clock in bit 8 and a strobe in bit 9 that is high in the idle and active-data stat (established)
pub mod fpga_prog_write {
    pub const WIDTH: u32 = 32;
    pub mod strobe { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clock { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod data { // bits 7:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// A valid map-RAM page-table entry, one 32-bit word per 16 KiB page of the board's own DMA address space, stored by the driver as one big-endian PIO sto (established)
pub mod mapram_entry {
    pub const WIDTH: u32 = 32;
    pub mod valid { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod invalid { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ppn { // bits 27:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3ffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// An invalidated map-RAM entry: bit 28 set and a run-length counter below it. The driver writes n consecutive entries, the i-th as the invalid bit with  (established)
pub mod mapram_entry_invalidated {
    pub const WIDTH: u32 = 32;
    pub mod invalid { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod run_left { // bits 27:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word 1 of a status-ring entry, the flag word. Bit numbers and names come from the driver's own 20-entry flag-name table (established); what each bit m (established)
pub mod ring_entry_flags {
    pub const WIDTH: u32 = 32;
    pub mod clink_rcv_done { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clink_xmit_done { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod current_valid { // bits 17:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod aborted { // bits 15:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod done { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod f_intr { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fif { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod in_change { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overflow { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod trs_error { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod input_off { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod f { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod valid { // bits 0:0, established
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
/// Word 0 of a 0x80-byte status-ring entry. The service routine treats bits 23:0 as a device media stream counter (MSC) and extends it to 64 bits, detect (established)
pub mod ring_entry_w0 {
    pub const WIDTH: u32 = 32;
    pub mod reserved_zero { // bits 31:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod msc { // bits 23:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// First four bytes of the 24-byte VBOB control message frame, in wire order from the high byte: count of bytes that follow, pipe, register id with bit 7 (established)
pub mod vbob_msg_header {
    pub const WIDTH: u32 = 32;
    pub mod count { // bits 31:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pipe { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::vbob_pipe::Value;
    }
    pub mod write { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reg_id { // bits 14:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod data0 { // bits 7:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const CLINK_PGEN_HI_INIT: u32 = 0x25; // established
pub const CLINK_PGEN_LO_INIT: u32 = 0xc3f7; // established
pub const FPGA_CLINK_DONE_MASK: u32 = 0x4000; // established
pub const FPGA_CLINK_IMAGE_SIZE: u32 = 0x8a64; // established
pub const FPGA_CLINK_INIT_MASK: u32 = 0x8000; // established
pub const FPGA_CLINK_KIND: u32 = 0x0; // established
pub const FPGA_CLINK_NUMBER: u32 = 0x7; // established
pub const FPGA_CLINK_PORT_OFFSET: u32 = 0x3800; // established
pub const FPGA_CLINK_SELECT: u32 = 0x40; // inferred
pub const FPGA_DATA_PORT_ADD: u32 = 0x80000; // established
pub const FPGA_GIF_DONE_MASK: u32 = 0x1; // established
pub const FPGA_GIF_IMAGE_SIZE: u32 = 0x2bc21; // established
pub const FPGA_GIF_INIT_MASK: u32 = 0x2; // established
pub const FPGA_GIF_KIND: u32 = 0x1; // established
pub const FPGA_GIF_NUMBER: u32 = 0x0; // established
pub const FPGA_GIF_PORT_OFFSET: u32 = 0x0; // established
pub const FPGA_GIF_SELECT: u32 = 0x0; // established
pub const FPGA_HDOC_DONE_MASK: u32 = 0x1000; // established
pub const FPGA_HDOC_IMAGE_SIZE: u32 = 0x19682; // established
pub const FPGA_HDOC_INIT_MASK: u32 = 0x2000; // established
pub const FPGA_HDOC_KIND: u32 = 0x0; // established
pub const FPGA_HDOC_NUMBER: u32 = 0x5; // established
pub const FPGA_HDOC_PORT_OFFSET: u32 = 0x2000; // established
pub const FPGA_HDOC_SELECT: u32 = 0x8; // inferred
pub const FPGA_INFO_OFF_DONE_MASK: u32 = 0x14; // established
pub const FPGA_INFO_OFF_IMAGE_SIZE: u32 = 0x8; // established
pub const FPGA_INFO_OFF_INIT_MASK: u32 = 0x18; // established
pub const FPGA_INFO_OFF_KIND: u32 = 0x4; // established
pub const FPGA_INFO_OFF_NAME: u32 = 0x0; // established
pub const FPGA_INFO_OFF_PORT_OFFSET: u32 = 0x10; // established
pub const FPGA_INFO_OFF_SELECT: u32 = 0xc; // established
pub const FPGA_INFO_RECORDS: u32 = 0x8; // established
pub const FPGA_INFO_RECORD_SIZE: u32 = 0x1c; // established
pub const FPGA_IXCC_DONE_MASK: u32 = 0x40; // established
pub const FPGA_IXCC_IMAGE_SIZE: u32 = 0x4db30; // established
pub const FPGA_IXCC_INIT_MASK: u32 = 0x80; // established
pub const FPGA_IXCC_KIND: u32 = 0x2; // established
pub const FPGA_IXCC_NUMBER: u32 = 0x4; // established
pub const FPGA_IXCC_PORT_OFFSET: u32 = 0x2800; // established
pub const FPGA_IXCC_SELECT: u32 = 0x10; // inferred
pub const FPGA_OXCC_DONE_MASK: u32 = 0x100; // established
pub const FPGA_OXCC_IMAGE_SIZE: u32 = 0x4db30; // established
pub const FPGA_OXCC_INIT_MASK: u32 = 0x200; // established
pub const FPGA_OXCC_KIND: u32 = 0x2; // established
pub const FPGA_OXCC_NUMBER: u32 = 0x3; // established
pub const FPGA_OXCC_PORT_OFFSET: u32 = 0x3000; // established
pub const FPGA_OXCC_SELECT: u32 = 0x20; // inferred
pub const FPGA_PACK_DONE_MASK: u32 = 0x4; // established
pub const FPGA_PACK_IMAGE_SIZE: u32 = 0x19682; // established
pub const FPGA_PACK_INIT_MASK: u32 = 0x8; // established
pub const FPGA_PACK_KIND: u32 = 0x0; // established
pub const FPGA_PACK_NUMBER: u32 = 0x1; // established
pub const FPGA_PACK_PORT_OFFSET: u32 = 0x800; // established
pub const FPGA_PACK_SELECT: u32 = 0x1; // inferred
pub const FPGA_UNPACK_DONE_MASK: u32 = 0x10; // established
pub const FPGA_UNPACK_IMAGE_SIZE: u32 = 0x19682; // established
pub const FPGA_UNPACK_INIT_MASK: u32 = 0x20; // established
pub const FPGA_UNPACK_KIND: u32 = 0x0; // established
pub const FPGA_UNPACK_NUMBER: u32 = 0x2; // established
pub const FPGA_UNPACK_PORT_OFFSET: u32 = 0x1000; // established
pub const FPGA_UNPACK_SELECT: u32 = 0x2; // inferred
pub const FPGA_VIF_DONE_MASK: u32 = 0x400; // established
pub const FPGA_VIF_IMAGE_SIZE: u32 = 0x19682; // established
pub const FPGA_VIF_INIT_MASK: u32 = 0x800; // established
pub const FPGA_VIF_KIND: u32 = 0x0; // established
pub const FPGA_VIF_NUMBER: u32 = 0x6; // established
pub const FPGA_VIF_PORT_OFFSET: u32 = 0x1800; // established
pub const FPGA_VIF_SELECT: u32 = 0x4; // inferred
pub const GIF_BLOCK_CLINK: u32 = 0x3800; // established
pub const GIF_BLOCK_CORE: u32 = 0x0; // established
pub const GIF_BLOCK_HDOC: u32 = 0x2000; // established
pub const GIF_BLOCK_IXCC: u32 = 0x2800; // established
pub const GIF_BLOCK_OXCC: u32 = 0x3000; // established
pub const GIF_BLOCK_PACKER: u32 = 0x800; // established
pub const GIF_BLOCK_SIZE: u32 = 0x800; // established
pub const GIF_BLOCK_UNPACKER: u32 = 0x1000; // established
pub const GIF_BLOCK_VIF: u32 = 0x1800; // established
pub const GIF_FILE_BASE: u32 = 0x800000; // established
pub const GIF_SLOT_STRIDE: u32 = 0x8; // established
pub const MAPRAM_BASE: u32 = 0x100000; // established
pub const MAPRAM_PAGE_SHIFT: u32 = 0xe; // established
pub const MAPRAM_SLOT_PAGES_MAX: u32 = 0x400; // established
pub const PACK_INIT_R0800: u32 = 0x1f0008; // established
pub const PACK_INIT_R0808: u32 = 0x1f0008; // established
pub const PACK_INIT_R0810: u32 = 0x1f0008; // established
pub const PACK_INIT_R0840: u32 = 0x1000; // established
pub const PACK_INIT_R0848: u32 = 0x1000; // established
pub const PACK_INIT_R0850: u32 = 0xd00; // established
pub const PIPE_DMA_CONTROL_INIT_PIPE0: u32 = 0xea040; // established
pub const PIPE_DMA_CONTROL_INIT_PIPE1: u32 = 0xa040; // established
pub const RING_DMA_ADDR_PIPE0: u32 = 0x8000000; // established
pub const RING_DMA_ADDR_PIPE1: u32 = 0x9000000; // established
pub const RING_ENTRIES: u32 = 0x10; // established
pub const RING_ENTRY_BYTES: u32 = 0x80; // established
pub const UNPACK_INIT_MISC_BASE: u32 = 0xfffe0f9; // established
pub const UNPACK_INIT_R1000: u32 = 0x160008; // established
pub const UNPACK_INIT_R1008: u32 = 0x32001f; // established
pub const UNPACK_INIT_R1040: u32 = 0x1200; // established
pub const UNPACK_INIT_R1048: u32 = 0xd00; // established
pub const VBOB_MSG_BYTES: u32 = 0x18; // established
pub const VBOB_TX_TIMEOUT_TICKS: u32 = 0xfa; // established

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn widget_control_4200() {
        assert_eq!(widget_control::const_bit9::get(0x4200), 1);
        assert_eq!(widget_control::const_bit14::get(0x4200), 1);
        assert_eq!(widget_control::xg_error_int_enable::get(0x4200), 0);
    }

    #[test]
    fn xg_water_mark_3f40() {
        assert_eq!(xg_water_mark::fixed_low::get(0x3f40), 16192);
        assert_eq!(xg_water_mark::mark_a::get(0x3f40), 0);
        assert_eq!(xg_water_mark::mark_b::get(0x3f40), 0);
        assert_eq!(xg_water_mark::forced_zero::get(0x3f40), 0);
    }

    #[test]
    fn pipe_dma_control_a040() {
        assert_eq!(pipe_dma_control::slot_valid::get(0xa040), 0);
        assert_eq!(pipe_dma_control::abort::get(0xa040), 0);
        assert_eq!(pipe_dma_control::cfg_bit9::get(0xa040), 0);
        assert_eq!(pipe_dma_control::cfg_bit10::get(0xa040), 0);
        assert_eq!(pipe_dma_control::cfg_bit12::get(0xa040), 0);
        assert_eq!(pipe_dma_control::int_enable::get(0xa040), 0);
    }

    #[test]
    fn pipe_dma_control_ea040() {
        assert_eq!(pipe_dma_control::slot_valid::get(0xea040), 0);
        assert_eq!(pipe_dma_control::abort::get(0xea040), 0);
        assert_eq!(pipe_dma_control::cfg_bit9::get(0xea040), 0);
        assert_eq!(pipe_dma_control::cfg_bit10::get(0xea040), 0);
        assert_eq!(pipe_dma_control::cfg_bit12::get(0xea040), 0);
        assert_eq!(pipe_dma_control::int_enable::get(0xea040), 0);
    }

    #[test]
    fn fpga_prog_write_100() {
        assert_eq!(fpga_prog_write::data::get(0x100), 0);
        assert_eq!(fpga_prog_write::clock::get(0x100), 1);
        assert_eq!(fpga_prog_write::strobe::get(0x100), 0);
    }

    #[test]
    fn fpga_prog_write_200() {
        assert_eq!(fpga_prog_write::data::get(0x200), 0);
        assert_eq!(fpga_prog_write::clock::get(0x200), 0);
        assert_eq!(fpga_prog_write::strobe::get(0x200), 1);
    }

    #[test]
    fn fpga_prog_write_300() {
        assert_eq!(fpga_prog_write::data::get(0x300), 0);
        assert_eq!(fpga_prog_write::clock::get(0x300), 1);
        assert_eq!(fpga_prog_write::strobe::get(0x300), 1);
    }

    #[test]
    fn mapram_entry_invalidated_10000000() {
        assert_eq!(mapram_entry_invalidated::invalid::get(0x10000000), 1);
        assert_eq!(mapram_entry_invalidated::run_left::get(0x10000000), 0);
    }
}
