// @generated from devices/hub_md/registers-extra.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 df97b661d44b747c810d4490e53a5804b7bb12cb4a2de043edf26b3990c7f0d1
// Hub memory and directory register layouts and constants outside the census
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub mod enums {
    pub mod md_bank_size {
        pub const SIZE_EMPTY: u32 = 0; // established
        pub const SIZE_8MB: u32 = 1; // established
        pub const SIZE_16MB: u32 = 2; // established
        pub const SIZE_32MB: u32 = 3; // established
        pub const SIZE_64MB: u32 = 4; // established
        pub const SIZE_128MB: u32 = 5; // established
        pub const SIZE_256MB: u32 = 6; // established
        pub const SIZE_512MB: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            SizeEmpty,
            Size8mb,
            Size16mb,
            Size32mb,
            Size64mb,
            Size128mb,
            Size256mb,
            Size512mb,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::SizeEmpty,
                    1 => Self::Size8mb,
                    2 => Self::Size16mb,
                    3 => Self::Size32mb,
                    4 => Self::Size64mb,
                    5 => Self::Size128mb,
                    6 => Self::Size256mb,
                    7 => Self::Size512mb,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::SizeEmpty => 0,
                    Self::Size8mb => 1,
                    Self::Size16mb => 2,
                    Self::Size32mb => 3,
                    Self::Size64mb => 4,
                    Self::Size128mb => 5,
                    Self::Size256mb => 6,
                    Self::Size512mb => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// MD and core register protection. The header gives no access type, layout or reset; rw is an assumption. (inferred)
pub mod md_io_protect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200000;
}
/// Clear my bit in the MD and core register protection. The header gives no access type, layout or reset; rw is an assumption. (inferred)
pub mod md_io_prot_ovrrd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200008;
}
/// Back-door directory and boot-space protection. The header gives no access type, layout or reset; rw is an assumption. (inferred)
pub mod md_hspec_protect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200010;
}
/// Layout of the memory configuration register. Bank descriptors take bits 23:0, three bits each. The timing fields and the bank-size codes are named by  (established)
pub mod md_memory_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200018;
    pub mod fprom_cyc { // bits 53:49, established
        pub const SHIFT: u32 = 49;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fprom_wr { // bits 48:44, established
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uctlr_cyc { // bits 43:39, established
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uctlr_wr { // bits 38:34, established
        pub const SHIFT: u32 = 34;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dimm0_sel { // bits 33:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod io_prot_en { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod arb_mlss { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ignore_ecc { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dir_premium { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reply_guar { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bank7 { // bits 23:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
    pub mod bank6 { // bits 20:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
    pub mod bank5 { // bits 17:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
    pub mod bank4 { // bits 14:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
    pub mod bank3 { // bits 11:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
    pub mod bank2 { // bits 8:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
    pub mod bank1 { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
    pub mod bank0 { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::md_bank_size::Value;
    }
}
/// Layout of the refresh control register. (established)
pub mod md_refresh_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200020;
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
    pub mod counter { // bits 23:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold { // bits 11:0, established
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
/// (established)
pub mod md_fandop_cac_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200028;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr { // bits 31:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x3ffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Layout of the page migration difference and value thresholds. The two registers share this layout. The shipped IRIX kernel arms a threshold by setting (established)
pub mod md_mig_diff_thresh {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200030;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 19:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Layout of the page migration difference and value thresholds. The two registers share this layout. The shipped IRIX kernel arms a threshold by setting (established)
pub mod md_mig_value_thresh {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200038;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 19:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Latest page migration candidate. The header gives no access type and no reset, so the access letter is an assumption (graded inferred). The header's i (inferred)
pub mod md_mig_candidate {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200040;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node { // bits 28:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod page { // bits 17:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3ffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Layout of the directory error latch, from the header's structure. The header lists the fields from the most significant bit down and gives a comment f (established)
pub mod md_dir_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200050;
    pub mod uce_vld { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ae_vld { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ce_vld { // bits 61:61, established
        pub const SHIFT: u32 = 61;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_prot { // bits 41:39, established
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_syn { // bits 38:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hspec_addr { // bits 29:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x7ffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uce_ovr { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ae_ovr { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ce_ovr { // bits 0:0, established
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
/// Layout of the protocol error latch, from the header's structure. (established)
pub mod md_protocol_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200060;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod initiator { // bits 60:50, established
        pub const SHIFT: u32 = 50;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod backoff { // bits 49:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod msg_type { // bits 47:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod access { // bits 39:38, established
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod priority { // bits 37:37, established
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dir_state { // bits 36:33, established
        pub const SHIFT: u32 = 33;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pointer_me { // bits 32:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod address { // bits 31:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 0:0, established
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
/// Layout of the memory error latch, from the header's structure. (established)
pub mod md_mem_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200070;
    pub mod uce_vld { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ce_vld { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_syn { // bits 39:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod address { // bits 31:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uce_ovr { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ce_ovr { // bits 0:0, established
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
/// Layout of the miscellaneous error latch. The header's valid mask covers bits 9:0. Its long-pack mask is written with a misspelt shift macro, so only t (established)
pub mod md_misc_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200080;
    pub mod ill_msg { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ill_rev { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod long_pack { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod short_pack { // bits 3:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_data { // bits 1:0, established
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
/// Memory DIMM mode initialisation. Layout in the MD_DIMM_INIT_FORMAT word. The IRIX register table gives write-only access; the earlier reading of the L (established)
pub mod md_mem_dimm_init {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200090;
    pub mod select { // bits 35:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 11:0, established
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
/// Directory DIMM mode initialisation. Same layout as the memory register. The IRIX register table gives write-only access; the earlier reading of the Li (established)
pub mod md_dir_dimm_init {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200098;
    pub mod select { // bits 35:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 11:0, established
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
/// Layout of the outgoing queue size register. (established)
pub mod md_moq_size {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2000a0;
    pub mod rp_size { // bits 13:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rq_size { // bits 4:0, established
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
/// Layout of the one-wire (Microlan) control register. (established)
pub mod md_mlan_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2000a8;
    pub mod phi1 { // bits 33:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod phi0 { // bits 26:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pulse { // bits 19:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sample { // bits 9:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod done { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rd_data { // bits 0:0, established
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
/// Layout of the performance counter select register. Bit positions come from the header's structure, which lists the fields from the most significant bi (established)
pub mod md_perf_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x210000;
    pub mod perf_en { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod perf_sel { // bits 2:0, inferred
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
/// Layout of performance counters 0 to 5. Bit positions come from the header's structure, read in the same order as the select register and so inferred. (established)
pub mod md_perf_cnt0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x210010;
    pub mod perf_cnt { // bits 19:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Layout of the slot identity and status register. The header also defines an SN00 slot bit at bit 7 and a PIMM field at 7:4. Both overlap bits named he (established)
pub mod md_slotid_ustat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220048;
    pub mod core_clk_test { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod core_clk { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod net_sync { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fprom_ready { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod i2c_intr { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hub_slot_id { // bits 2:0, established
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
/// (established)
pub mod md_led0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220050;
    pub mod led { // bits 7:0, inferred
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
/// Eight-bit LED of the second processor, the twin of md_led0 in the census. The header gives no access type; write-only is carried over from md_led0 and (established)
pub mod md_led1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220058;
    pub mod led { // bits 7:0, inferred
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
/// Microcontroller and UART 1 register 1 of 16; the census has register 0. The IRIX register table confirms the access. (established)
pub mod md_ureg1_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220088;
}
/// Microcontroller and UART 1 register 2 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220090;
}
/// Microcontroller and UART 1 register 3 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220098;
}
/// Microcontroller and UART 1 register 4 of 16; the census has register 0. The header gives no access type, so rw is assumed. The IRIX kernel's LED macro (inferred)
pub mod md_ureg1_4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200a0;
}
/// Microcontroller and UART 1 register 5 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_5 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200a8;
}
/// Microcontroller and UART 1 register 6 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_6 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200b0;
}
/// Microcontroller and UART 1 register 7 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_7 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200b8;
}
/// Microcontroller and UART 1 register 8 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_8 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200c0;
}
/// Microcontroller and UART 1 register 9 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_9 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200c8;
}
/// Microcontroller and UART 1 register 10 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_10 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200d0;
}
/// Microcontroller and UART 1 register 11 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_11 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200d8;
}
/// Microcontroller and UART 1 register 12 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_12 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200e0;
}
/// Microcontroller and UART 1 register 13 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_13 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200e8;
}
/// Microcontroller and UART 1 register 14 of 16; the census has register 0. The header gives no access type, so rw is assumed. (inferred)
pub mod md_ureg1_14 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200f0;
}
/// Microcontroller and UART 1 register 15 of 16; the census has register 0. The IRIX register table confirms the access. (established)
pub mod md_ureg1_15 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200f8;
}
/// Layout of the page migration candidate. The header's initiator and node-number masks overlap at bits 28:20, so only the single-bit fields are imported (established)
pub mod md_mig_candidate_format {
    pub const WIDTH: u32 = 64;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node { // bits 28:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod page { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3ffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const HUB_MD_BANK_MASK: u32 = 0xe0000000; // established
pub const HUB_MD_BANK_SHIFT: u32 = 0x1d; // established
pub const HUB_MD_BASE: u32 = 0x200000; // established
pub const HUB_MD_BASE_JUNK: u32 = 0x220000; // established
pub const HUB_MD_BASE_PERF: u32 = 0x210000; // established
pub const HUB_MD_DIRTYPE_PREMIUM: u32 = 0x1; // established
pub const HUB_MD_DIRTYPE_STANDARD: u32 = 0x0; // established
pub const HUB_MD_DIR_BUSY_EXCL: u32 = 0x4; // established
pub const HUB_MD_DIR_BUSY_SHARED: u32 = 0x3; // established
pub const HUB_MD_DIR_EXCLUSIVE: u32 = 0x2; // established
pub const HUB_MD_DIR_POISONED: u32 = 0x1; // established
pub const HUB_MD_DIR_SHARED: u32 = 0x0; // established
pub const HUB_MD_DIR_UNOWNED: u32 = 0x7; // established
pub const HUB_MD_DIR_WAIT: u32 = 0x5; // established
pub const HUB_MD_MEMORY_CONFIG_RESET_DEFAULTS: u64 = 0x1e7fbc3fffffff; // established
pub const HUB_MD_MEM_BANKS_M_MODE: u32 = 0x8; // established
pub const HUB_MD_MEM_BANKS_N_MODE: u32 = 0x4; // established
pub const HUB_MD_MLAN_CTL_ACCESS_BYTES: u32 = 0x8; // established
pub const HUB_MD_MLAN_CTL_RESET_DEFAULTS: u64 = 0x18b100000; // established
pub const HUB_MD_MOQ_SIZE_RESET_DEFAULTS: u32 = 0x3212; // established
pub const HUB_MD_PAGE_NUM_SHIFT: u32 = 0xc; // established
pub const HUB_MD_PAGE_SIZE: u32 = 0x1000; // established
pub const HUB_MD_REFCNT_COUNT_MASK_PREMIUM: u32 = 0x7ffff; // established
pub const HUB_MD_REFCNT_COUNT_MASK_STANDARD: u32 = 0x7ff; // established
pub const HUB_MD_REFCNT_COUNT_SHIFT: u32 = 0x5; // established
pub const HUB_MD_REFRESH_CONTROL_RESET_DEFAULTS: u32 = 0x400; // established
pub const HUB_MD_SIZE_128MB: u32 = 0x5; // established
pub const HUB_MD_SIZE_16MB: u32 = 0x2; // established
pub const HUB_MD_SIZE_1GB: u32 = 0x8; // established
pub const HUB_MD_SIZE_256MB: u32 = 0x6; // established
pub const HUB_MD_SIZE_2GB: u32 = 0x9; // established
pub const HUB_MD_SIZE_32MB: u32 = 0x3; // established
pub const HUB_MD_SIZE_4GB: u32 = 0xa; // established
pub const HUB_MD_SIZE_512MB: u32 = 0x7; // established
pub const HUB_MD_SIZE_64MB: u32 = 0x4; // established
pub const HUB_MD_SIZE_8MB: u32 = 0x1; // established
pub const HUB_MD_SIZE_EMPTY: u32 = 0x0; // established
