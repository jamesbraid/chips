// @generated from devices/bedrock_windows/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 4ce22aad6bef30dbc9d45d94765826ca9936e0ce29420eac7da13078ea7efa6d
// Bedrock register arrays whose extent is a fact of its own
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then  (established)
pub mod gfx_window {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300;
    pub const COUNT: u32 = 10;
    pub const STRIDE: u64 = 8;
}
