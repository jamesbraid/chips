// @generated from devices/r5000_cp0/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 6a9b39abb11b3b99b791300a4de226fd477602f6718575488b04e14313a7ffdf
// MIPS R5000 CP0 Config, Status, PageMask and LLAddr field positions, and FCR31 flags
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const R5KCFG_BE_MASK: u32 = 0x8000; // established
pub const R5KCFG_CACHE_32K_CODE: u32 = 0x3; // established
pub const R5KCFG_DB_MASK: u32 = 0x10; // established
pub const R5KCFG_DC_MASK: u32 = 0x1c0; // established
pub const R5KCFG_DC_SHIFT: u32 = 0x6; // established
pub const R5KCFG_EB_MASK: u32 = 0x2000; // established
pub const R5KCFG_EC_DIVISOR_BASE: u32 = 0x2; // established
pub const R5KCFG_EC_MASK: u32 = 0x70000000; // established
pub const R5KCFG_EC_SHIFT: u32 = 0x1c; // established
pub const R5KCFG_EM_MASK: u32 = 0x4000; // established
pub const R5KCFG_EP_MASK: u32 = 0xf000000; // established
pub const R5KCFG_EP_SHIFT: u32 = 0x18; // established
pub const R5KCFG_EW_MASK: u32 = 0xc0000; // established
pub const R5KCFG_EW_SHIFT: u32 = 0x12; // established
pub const R5KCFG_FIXED_ONE_MASK: u32 = 0x10000; // established
pub const R5KCFG_IB_MASK: u32 = 0x20; // established
pub const R5KCFG_IC_MASK: u32 = 0xe00; // established
pub const R5KCFG_IC_SHIFT: u32 = 0x9; // established
pub const R5KCFG_K0_MASK: u32 = 0x7; // established
pub const R5KCFG_K0_SHIFT: u32 = 0x0; // established
pub const R5KCFG_SB_MASK: u32 = 0xc00000; // established
pub const R5KCFG_SB_SHIFT: u32 = 0x16; // established
pub const R5KCFG_SC_BIT: u32 = 0x11; // established
pub const R5KCFG_SC_MASK: u32 = 0x20000; // established
pub const R5KCFG_SE_MASK: u32 = 0x1000; // established
pub const R5KCFG_SS_MASK: u32 = 0x300000; // established
pub const R5KCFG_SS_SHIFT: u32 = 0x14; // established
pub const R5KFCR_CAUSE_MASK: u32 = 0x3f000; // established
pub const R5KFCR_CAUSE_SHIFT: u32 = 0xc; // established
pub const R5KFCR_CC0_MASK: u32 = 0x800000; // established
pub const R5KFCR_CC_HI_MASK: u32 = 0xfe000000; // established
pub const R5KFCR_CC_HI_SHIFT: u32 = 0x19; // established
pub const R5KFCR_ENABLE_MASK: u32 = 0xf80; // established
pub const R5KFCR_ENABLE_SHIFT: u32 = 0x7; // established
pub const R5KFCR_FLAG_MASK: u32 = 0x7c; // established
pub const R5KFCR_FLAG_SHIFT: u32 = 0x2; // established
pub const R5KFCR_FS_MASK: u32 = 0x1000000; // established
pub const R5KFCR_RM_MASK: u32 = 0x3; // established
pub const R5KFCR_RSVD_MASK: u32 = 0x7c0000; // established
pub const R5KLL_MASK: u32 = 0xffffffff; // established
pub const R5KLL_SHIFT: u32 = 0x4; // established
pub const R5KPM_FIELD_MASK: u32 = 0x1ffe000; // established
pub const R5KPM_FIELD_SHIFT: u32 = 0xd; // established
pub const R5KPM_PAGE_16K: u32 = 0x6000; // established
pub const R5KPM_PAGE_16M: u32 = 0x1ffe000; // established
pub const R5KPM_PAGE_1M: u32 = 0x1fe000; // established
pub const R5KPM_PAGE_256K: u32 = 0x7e000; // established
pub const R5KPM_PAGE_4K: u32 = 0x0; // established
pub const R5KPM_PAGE_4M: u32 = 0x7fe000; // established
pub const R5KPM_PAGE_64K: u32 = 0x1e000; // established
pub const R5KST_BEV_MASK: u32 = 0x400000; // established
pub const R5KST_CE_MASK: u32 = 0x20000; // established
pub const R5KST_CU_MASK: u32 = 0x70000000; // established
pub const R5KST_DE_MASK: u32 = 0x10000; // established
pub const R5KST_ERL_MASK: u32 = 0x4; // established
pub const R5KST_EXL_MASK: u32 = 0x2; // established
pub const R5KST_FR_MASK: u32 = 0x4000000; // established
pub const R5KST_IE_MASK: u32 = 0x1; // established
pub const R5KST_IMPLEMENTED_MASK: u32 = 0xf653ffff; // established
pub const R5KST_IM_MASK: u32 = 0xff00; // established
pub const R5KST_IM_SHIFT: u32 = 0x8; // established
pub const R5KST_KSU_MASK: u32 = 0x18; // established
pub const R5KST_KSU_SHIFT: u32 = 0x3; // established
pub const R5KST_KX_MASK: u32 = 0x80; // established
pub const R5KST_RE_MASK: u32 = 0x2000000; // established
pub const R5KST_SR_MASK: u32 = 0x100000; // established
pub const R5KST_SX_MASK: u32 = 0x40; // established
pub const R5KST_UX_MASK: u32 = 0x20; // established
pub const R5KST_XX_MASK: u32 = 0x80000000; // established
