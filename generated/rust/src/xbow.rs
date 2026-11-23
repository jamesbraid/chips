// @generated from devices/xbow/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 1d5707b21be4c7d824b64b2d6d46ae200225b3a331af2e4f73daad0758f2a2ce
// Xbow (crossbar)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// (established)
pub mod xb_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
}
/// (established)
pub mod xb_stat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
}
/// (established)
pub mod xb_err_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// (established)
pub mod xb_err_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
}
/// (established)
pub mod xb_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
}
/// (established)
pub mod xb_pkt_to {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// (established)
pub mod xb_int_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
/// (established)
pub mod xb_int_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x38;
}
/// (established)
pub mod xb_err_cmdword {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
}
/// (established)
pub mod xb_llp_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
}
/// (established)
pub mod xb_stat_clr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50;
}
/// (established)
pub mod xb_arb_reload {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x58;
}
/// (established)
pub mod reserved {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80;
}
/// (established)
pub mod reserved_88 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
}
/// (established)
pub mod reserved_90 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
}
/// (established)
pub mod reserved_98 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x98;
}
/// (established)
pub mod reserved_a0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa0;
}
/// (established)
pub mod reserved_a8 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa8;
}
/// (established)
pub mod reserved_b0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb0;
}
/// (established)
pub mod reserved_b8 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb8;
}
/// (established)
pub mod xb_link_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x108;
}
/// (established)
pub mod xb_link_stat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x110;
}
/// (established)
pub mod xb_link_arb_upper {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x118;
}
/// (established)
pub mod xb_link_arb_lower {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x120;
}
/// (established)
pub mod xb_link_stat_clr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x128;
}
/// (established)
pub mod xb_link_reset {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x130;
}
/// (established)
pub mod xb_link_aux_stat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x138;
}
/// (established)
pub mod xb_link_ctrl_148 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x148;
}
/// (established)
pub mod xb_link_stat_150 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x150;
}
/// (established)
pub mod xb_link_stat_clr_168 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x168;
}
/// (established)
pub mod xb_link_aux_stat_178 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x178;
}
/// (established)
pub mod xb_link_arb_upper_198 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x198;
}
/// (established)
pub mod xb_link_arb_upper_1d8 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1d8;
}
pub const RESERVED_V_FF: u32 = 0xff; // inferred
pub const XB_CTRL_20_B_3_0: u32 = 0xf; // inferred
pub const XB_CTRL_20_B_7_0: u32 = 0xff; // inferred
pub const XB_CTRL_20_V_24: u32 = 0x24; // inferred
pub const XB_CTRL_20_V_80000000: u32 = 0x80000000; // inferred
pub const XB_CTRL_B_3_0: u32 = 0xf; // inferred
pub const XB_CTRL_B_7_0: u32 = 0xff; // inferred
pub const XB_CTRL_V_24: u32 = 0x24; // inferred
pub const XB_CTRL_V_80000000: u32 = 0x80000000; // inferred
pub const XB_ID_0_B_10_0: u32 = 0x7ff; // inferred
pub const XB_ID_0_B_15_0: u32 = 0xffff; // inferred
pub const XB_ID_0_B_2_0: u32 = 0x7; // inferred
pub const XB_ID_B_10_0: u32 = 0x7ff; // inferred
pub const XB_ID_B_15_0: u32 = 0xffff; // inferred
pub const XB_ID_B_2_0: u32 = 0x7; // inferred
pub const XB_INT_UPPER_B_15_0: u32 = 0xffff; // inferred
pub const XB_LINK_ARB_UPPER_1D8_V_9: u32 = 0x9; // inferred
pub const XB_LINK_AUX_STAT_138_B_5: u32 = 0x20; // inferred
pub const XB_LINK_AUX_STAT_138_B_7_0: u32 = 0xff; // inferred
pub const XB_LINK_AUX_STAT_178_B_5: u32 = 0x20; // inferred
pub const XB_LINK_AUX_STAT_B_5: u32 = 0x20; // inferred
pub const XB_LINK_AUX_STAT_B_7_0: u32 = 0xff; // inferred
pub const XB_LINK_CTRL_108_B_3: u32 = 0x8; // inferred
pub const XB_LINK_CTRL_108_V_80000: u32 = 0x80000; // inferred
pub const XB_LINK_CTRL_148_B_3: u32 = 0x8; // inferred
pub const XB_LINK_CTRL_B_3: u32 = 0x8; // inferred
pub const XB_LINK_CTRL_V_80000: u32 = 0x80000; // inferred
pub const XB_STAT_8_B_5_2: u32 = 0x24; // inferred
pub const XB_STAT_8_B_9_6: u32 = 0x3c0; // inferred
pub const XB_STAT_B_5_2: u32 = 0x24; // inferred
pub const XB_STAT_B_9_6: u32 = 0x3c0; // inferred
