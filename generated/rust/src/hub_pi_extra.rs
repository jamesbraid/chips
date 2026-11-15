// generated from devices/hub_pi/registers-extra.toml by defs-gen - do not edit, change the source
// Hub processor interface registers, bit layouts and constants outside the census
#![allow(dead_code)]

pub mod enums {
    pub mod pi_calias_size {
        pub const SIZE_NONE: u32 = 0; // established
        pub const SIZE_4K: u32 = 1; // established
        pub const SIZE_8K: u32 = 2; // established
        pub const SIZE_16K: u32 = 3; // established
        pub const SIZE_32K: u32 = 4; // established
        pub const SIZE_64K: u32 = 5; // established
        pub const SIZE_128K: u32 = 6; // established
        pub const SIZE_256K: u32 = 7; // established
        pub const SIZE_512K: u32 = 8; // established
        pub const SIZE_1M: u32 = 9; // established
        pub const SIZE_2M: u32 = 10; // established
        pub const SIZE_4M: u32 = 11; // established
        pub const SIZE_8M: u32 = 12; // established
        pub const SIZE_16M: u32 = 13; // established
        pub const SIZE_32M: u32 = 14; // established
        pub const SIZE_64M: u32 = 15; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            SizeNone,
            Size4k,
            Size8k,
            Size16k,
            Size32k,
            Size64k,
            Size128k,
            Size256k,
            Size512k,
            Size1m,
            Size2m,
            Size4m,
            Size8m,
            Size16m,
            Size32m,
            Size64m,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::SizeNone,
                    1 => Self::Size4k,
                    2 => Self::Size8k,
                    3 => Self::Size16k,
                    4 => Self::Size32k,
                    5 => Self::Size64k,
                    6 => Self::Size128k,
                    7 => Self::Size256k,
                    8 => Self::Size512k,
                    9 => Self::Size1m,
                    10 => Self::Size2m,
                    11 => Self::Size4m,
                    12 => Self::Size8m,
                    13 => Self::Size16m,
                    14 => Self::Size32m,
                    15 => Self::Size64m,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::SizeNone => 0,
                    Self::Size4k => 1,
                    Self::Size8k => 2,
                    Self::Size16k => 3,
                    Self::Size32k => 4,
                    Self::Size64k => 5,
                    Self::Size128k => 6,
                    Self::Size256k => 7,
                    Self::Size512k => 8,
                    Self::Size1m => 9,
                    Self::Size2m => 10,
                    Self::Size4m => 11,
                    Self::Size8m => 12,
                    Self::Size16m => 13,
                    Self::Size32m => 14,
                    Self::Size64m => 15,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// CPU protection register, named PI_CPU_PROTECT in the header. The header gives no fields. The IRIX register table confirms the access. (established)
pub mod pi_cpu_protect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x0;
}
/// Protection override register, named PI_PROT_OVRRD in the header as the way to clear a CPU protection bit. The header gives neither an unlock value nor (established)
pub mod pi_prot_override {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x8;
}
/// Interrupt pending protection register, named PI_IO_PROTECT in the header. The header gives no fields. The IRIX register table confirms the access. (established)
pub mod pi_io_protect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10;
}
/// (established)
pub mod pi_calias_size {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x28;
    pub mod size { // bits 3:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::pi_calias_size::Value;
    }
}
/// Reply level register, named PI_REPLY_LEVEL in the header. The header gives no fields. The IRIX register table confirms the access. (established)
pub mod pi_reply_level {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60;
}
/// Non-maskable interrupt to processor B, named PI_NMI_B in the header and paired with the processor A register at the same stride. The IRIX register tab (established)
pub mod pi_nmi_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x78;
}
/// Soft reset, named PI_SOFTRESET in the header with the comment that it resets both processors. The header gives no value and no fields, so the data wri (established)
pub mod pi_softreset {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x80;
}
/// Layout of the interrupt pending modify register, pi_int_pend_mod, as Linux writes it: a set bit and an interrupt level. Linux only writes the register (established)
pub mod pi_int_pend_mod {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x90;
    pub mod set { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 6:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Cross-call interrupt pending set for processor A, named PI_CC_PEND_SET_A in the header. The IRIX register table confirms the access. (established)
pub mod pi_cc_pend_set_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xc8;
}
/// Cross-call interrupt pending set for processor B, named PI_CC_PEND_SET_B in the header. The header's pairing rule puts it eight bytes above the proces (established)
pub mod pi_cc_pend_set_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xd0;
}
/// Cross-call interrupt pending clear for processor A, named PI_CC_PEND_CLR_A in the header. The IRIX register table confirms the access. (established)
pub mod pi_cc_pend_clr_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xd8;
}
/// Cross-call interrupt pending clear for processor B, named PI_CC_PEND_CLR_B in the header. The IRIX register table confirms the access. (established)
pub mod pi_cc_pend_clr_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xe0;
}
/// Cross-call interrupt mask, named PI_CC_MASK in the header. The IRIX register table confirms the access. (established)
pub mod pi_cc_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xe8;
}
/// Layout of the real-time counter local control register, the register the census names by its real-time clock control name. The header's mask and shift (established)
pub mod pi_rt_local_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x160;
    pub mod use_internal { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gclk { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gclk_count { // bits 14:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod max_count { // bits 7:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gclk_en { // bits 0:0, established
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
/// Global clock filter control, named PI_RT_FILTER_CTRL in the header, which gives no fields. It sits next to the real-time clock control register. The I (established)
pub mod pi_rt_filter_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x168;
}
/// Built-in self-test write data, named PI_BIST_WRITE_DATA in the header. The IRIX register table confirms the access. (established)
pub mod pi_bist_write_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200;
}
/// Built-in self-test read data, named PI_BIST_READ_DATA in the header. The IRIX register table confirms the access. (established)
pub mod pi_bist_read_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x208;
}
/// Built-in self-test count and target, named PI_BIST_COUNT_TARG in the header. The IRIX register table gives write-only access; the earlier reading of t (established)
pub mod pi_bist_count_targ {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x210;
}
/// Built-in self-test ready indicator, named PI_BIST_READY in the header. The IRIX register table confirms the access. (established)
pub mod pi_bist_ready {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x218;
}
/// Built-in self-test control, named PI_BIST_SHIFT_LOAD in the header. The IRIX register table confirms the access. (established)
pub mod pi_bist_shift_load {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220;
}
/// Built-in self-test control, named PI_BIST_SHIFT_UNLOAD in the header. The IRIX register table confirms the access. (established)
pub mod pi_bist_shift_unload {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x228;
}
/// Built-in self-test control, named PI_BIST_ENTER_RUN in the header. The IRIX register table confirms the access. (established)
pub mod pi_bist_enter_run {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x230;
}
/// Graphics page for processor A, named PI_GFX_PAGE_A in the header. The header names only the enable bit, which is in the fields below. The IRIX registe (established)
pub mod pi_gfx_page_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300;
    pub mod enable { // bits 40:40, established
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
/// Graphics credit counter for processor A, named PI_GFX_CREDIT_CNTR_A in the header. The header gives no field layout and no meaning beyond the name. Th (established)
pub mod pi_gfx_credit_cntr_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x308;
}
/// Graphics bias for processor A, named PI_GFX_BIAS_A in the header. The header gives no field layout. The IRIX register table confirms the access. (established)
pub mod pi_gfx_bias_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x310;
}
/// Graphics interrupt counter for processor A, named PI_GFX_INT_CNTR_A in the header. The header gives no field layout. The IRIX register table confirms  (established)
pub mod pi_gfx_int_cntr_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x318;
}
/// Graphics page for processor B, named PI_GFX_PAGE_B in the header. The header's pairing rule puts it 0x28 above the processor A page. The IRIX register (established)
pub mod pi_gfx_page_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x328;
    pub mod enable { // bits 40:40, established
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
/// Graphics credit counter for processor B, named PI_GFX_CREDIT_CNTR_B in the header. The IRIX register table confirms the access. (established)
pub mod pi_gfx_credit_cntr_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x330;
}
/// Graphics bias for processor B, named PI_GFX_BIAS_B in the header. The IRIX register table confirms the access. (established)
pub mod pi_gfx_bias_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x338;
}
/// Graphics interrupt counter for processor B, named PI_GFX_INT_CNTR_B in the header. The IRIX register table confirms the access. (established)
pub mod pi_gfx_int_cntr_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x340;
}
/// Bit pairs are B then A (even bit B, odd bit A) for bits 0 to 23. (established)
pub mod pi_err_int_pend {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400;
    pub mod md_uncorr { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_tag_a { // bits 23:23, established
        pub const SHIFT: u32 = 23;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_tag_b { // bits 22:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uncac_uncorr_a { // bits 21:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uncac_uncorr_b { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_spool_a { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_spool_b { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_addr_a { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_addr_b { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_data_a { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_data_b { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_addr_a { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_addr_b { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_data_a { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_data_b { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_a { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_b { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_werr_a { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_werr_b { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_terr_a { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_terr_b { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spur_msg_a { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spur_msg_b { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool_cmp_a { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool_cmp_b { // bits 0:0, established
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
/// (established)
pub mod pi_err_int_mask_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x408;
    pub mod md_uncorr { // bits 24:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_tag_a { // bits 23:23, inferred
        pub const SHIFT: u32 = 23;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_tag_b { // bits 22:22, inferred
        pub const SHIFT: u32 = 22;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uncac_uncorr_a { // bits 21:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uncac_uncorr_b { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_spool_a { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_spool_b { // bits 18:18, inferred
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_addr_a { // bits 17:17, inferred
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_addr_b { // bits 16:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_data_a { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_data_b { // bits 14:14, inferred
        pub const SHIFT: u32 = 14;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_addr_a { // bits 13:13, inferred
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_addr_b { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_data_a { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_data_b { // bits 10:10, inferred
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_a { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_b { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_werr_a { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_werr_b { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_terr_a { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_terr_b { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spur_msg_a { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spur_msg_b { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool_cmp_a { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool_cmp_b { // bits 0:0, inferred
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
/// (established)
pub mod pi_err_int_mask_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410;
    pub mod md_uncorr { // bits 24:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_tag_a { // bits 23:23, inferred
        pub const SHIFT: u32 = 23;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_tag_b { // bits 22:22, inferred
        pub const SHIFT: u32 = 22;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uncac_uncorr_a { // bits 21:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uncac_uncorr_b { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_spool_a { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_spool_b { // bits 18:18, inferred
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_addr_a { // bits 17:17, inferred
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_addr_b { // bits 16:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_data_a { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syscmd_data_b { // bits 14:14, inferred
        pub const SHIFT: u32 = 14;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_addr_a { // bits 13:13, inferred
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_addr_b { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_data_a { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysad_data_b { // bits 10:10, inferred
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_a { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sysstate_b { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_werr_a { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_werr_b { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_terr_a { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrb_terr_b { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spur_msg_a { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spur_msg_b { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool_cmp_a { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool_cmp_b { // bits 0:0, inferred
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
/// (established)
pub mod pi_err_status0_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x430;
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
    pub mod overrun { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr { // bits 61:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1fffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd { // bits 24:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod suppl { // bits 16:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reqnum { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x7;
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
/// Clear-on-read alias of error status 0 for processor A, named PI_ERR_STATUS0_A_RCLR in the header. The header's comment says a read clears the register (established)
pub mod pi_err_status0_a_rclr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x438;
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
    pub mod overrun { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr { // bits 61:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1fffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd { // bits 24:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod suppl { // bits 16:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reqnum { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x7;
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
/// (established)
pub mod pi_err_status1_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x440;
    pub mod msgsrc { // bits 63:53, established
        pub const SHIFT: u32 = 53;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbstat { // bits 52:43, established
        pub const SHIFT: u32 = 43;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrbrrb { // bits 42:42, established
        pub const SHIFT: u32 = 42;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbnum { // bits 41:39, established
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod invcnt { // bits 38:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod toutcnt { // bits 28:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool { // bits 20:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits. (established)
pub mod pi_err_status1_a_rclr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x448;
    pub mod msgsrc { // bits 63:53, established
        pub const SHIFT: u32 = 53;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbstat { // bits 52:43, established
        pub const SHIFT: u32 = 43;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrbrrb { // bits 42:42, established
        pub const SHIFT: u32 = 42;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbnum { // bits 41:39, established
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod invcnt { // bits 38:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod toutcnt { // bits 28:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool { // bits 20:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// (established)
pub mod pi_err_status0_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x450;
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
    pub mod overrun { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr { // bits 61:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1fffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd { // bits 24:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod suppl { // bits 16:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reqnum { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x7;
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
/// Clear-on-read alias of error status 0 for processor B, named PI_ERR_STATUS0_B_RCLR in the header. The header's comment says a read clears the register (established)
pub mod pi_err_status0_b_rclr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x458;
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
    pub mod overrun { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr { // bits 61:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1fffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd { // bits 24:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod suppl { // bits 16:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reqnum { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x7;
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
/// (established)
pub mod pi_err_status1_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x460;
    pub mod msgsrc { // bits 63:53, established
        pub const SHIFT: u32 = 53;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbstat { // bits 52:43, established
        pub const SHIFT: u32 = 43;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrbrrb { // bits 42:42, established
        pub const SHIFT: u32 = 42;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbnum { // bits 41:39, established
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod invcnt { // bits 38:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod toutcnt { // bits 28:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool { // bits 20:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Established by the header's comment 'clear on read' for the whole register: the cor mask is all bits. (established)
pub mod pi_err_status1_b_rclr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x468;
    pub mod msgsrc { // bits 63:53, established
        pub const SHIFT: u32 = 53;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbstat { // bits 52:43, established
        pub const SHIFT: u32 = 43;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wrbrrb { // bits 42:42, established
        pub const SHIFT: u32 = 42;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crbnum { // bits 41:39, established
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod invcnt { // bits 38:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod toutcnt { // bits 28:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spool { // bits 20:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error spool compare for processor A, named PI_SPOOL_CMP_A in the header. The header gives no field layout. The IRIX register table confirms the access (established)
pub mod pi_spool_cmp_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x470;
}
/// Error spool compare for processor B, named PI_SPOOL_CMP_B in the header. The IRIX register table confirms the access. (established)
pub mod pi_spool_cmp_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x478;
}
/// Timed-out CRB entries for processor A, named PI_CRB_TIMEOUT_A in the header. The header gives no field layout. The IRIX register table gives write-onl (established)
pub mod pi_crb_timeout_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x480;
}
/// Timed-out CRB entries for processor B, named PI_CRB_TIMEOUT_B in the header. The IRIX register table gives write-only access; the earlier reading of t (established)
pub mod pi_crb_timeout_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x488;
}
/// Enables for the processor bus checks, named PI_SYSAD_ERRCHK_EN in the header. Six enable bits, each named in the header's constants. The IRIX register (established)
pub mod pi_sysad_errchk_en {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x490;
    pub mod qual { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod state { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmdp { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sadp { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod qualgen { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod eccgen { // bits 0:0, established
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
/// Forced SysAD check-bit error for processor A, named PI_BAD_CHECK_BIT_A in the header and described there as diagnostic. The header gives no field layo (established)
pub mod pi_bad_check_bit_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x498;
}
/// Forced SysAD check-bit error for processor B, named PI_BAD_CHECK_BIT_B in the header. The IRIX register table confirms the access. (established)
pub mod pi_bad_check_bit_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4a0;
}
/// Consecutive negative-acknowledge counter for processor A, named PI_NACK_CNT_A in the header. The IRIX register table confirms the access. (established)
pub mod pi_nack_cnt_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4a8;
    pub mod enable { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count { // bits 19:0, established
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
/// Consecutive negative-acknowledge counter for processor B, named PI_NACK_CNT_B in the header. The IRIX register table confirms the access. (established)
pub mod pi_nack_cnt_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4b0;
    pub mod enable { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count { // bits 19:0, established
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
/// Negative-acknowledge compare, named PI_NACK_CMP in the header. The header gives a maximum of 0x0fffff for the count, so the compare is twenty bits wid (established)
pub mod pi_nack_cmp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4b8;
}
pub const IP_ERROR: u32 = 0x4000; // established
pub const IP_MASK: u32 = 0x7c00; // established
pub const IP_PEND0: u32 = 0x400; // established
pub const IP_PEND1_CC: u32 = 0x800; // established
pub const IP_PROF: u32 = 0x2000; // established
pub const IP_RT: u32 = 0x1000; // established
pub const PI_BASE: u32 = 0x0; // established
pub const PI_CALIAS_SIZE_0: u32 = 0x0; // established
pub const PI_CALIAS_SIZE_128K: u32 = 0x6; // established
pub const PI_CALIAS_SIZE_16K: u32 = 0x3; // established
pub const PI_CALIAS_SIZE_16M: u32 = 0xd; // established
pub const PI_CALIAS_SIZE_1M: u32 = 0x9; // established
pub const PI_CALIAS_SIZE_256K: u32 = 0x7; // established
pub const PI_CALIAS_SIZE_2M: u32 = 0xa; // established
pub const PI_CALIAS_SIZE_32K: u32 = 0x4; // established
pub const PI_CALIAS_SIZE_32M: u32 = 0xe; // established
pub const PI_CALIAS_SIZE_4K: u32 = 0x1; // established
pub const PI_CALIAS_SIZE_4M: u32 = 0xb; // established
pub const PI_CALIAS_SIZE_512K: u32 = 0x8; // established
pub const PI_CALIAS_SIZE_64K: u32 = 0x5; // established
pub const PI_CALIAS_SIZE_64M: u32 = 0xf; // established
pub const PI_CALIAS_SIZE_8K: u32 = 0x2; // established
pub const PI_CALIAS_SIZE_8M: u32 = 0xc; // established
pub const PI_ERR_CLEAR_ALL_A: u32 = 0xaaaaaa; // established
pub const PI_ERR_CLEAR_ALL_B: u32 = 0x555555; // established
pub const PI_ERR_RD_DERR: u32 = 0x2; // established
pub const PI_ERR_RD_PRERR: u32 = 0x1; // established
pub const PI_ERR_RD_TERR: u32 = 0x3; // established
pub const PI_ERR_WR_PWERR: u32 = 0x1; // established
pub const PI_ERR_WR_TERR: u32 = 0x3; // established
pub const PI_ERR_WR_WERR: u32 = 0x0; // established
pub const PI_LOCAL_WINDOW_BASE: u32 = 0x1000000; // established
pub const PI_MIN_STACK_SIZE: u32 = 0x1000; // established
pub const PI_NODE_SHIFT: u32 = 0x20; // established
pub const PI_NODE_WINDOW_BASE: u32 = 0x1800000; // established
pub const PI_STACK_SIZE_SHIFT: u32 = 0xc; // established
