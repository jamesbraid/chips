// @generated from devices/isp12160/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 76b80bad40a1f9ab19f16c3d95e98399a2589c9f44ea0003211709b2b5ea1212
// QLogic ISP12160 dual-channel Ultra3 SCSI host adapter (PCI 1077:1216), the constants the held sources establish
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const BUSES: u32 = 0x2; // established
pub const BUS_RESET_DELAY_DEFAULT_S: u32 = 0x5; // established
pub const BUS_RESET_DELAY_MAX_S: u32 = 0xf; // established
pub const CONTROLLER_PROGRAM_WORDS: u32 = 0x361d; // inferred
pub const DRIVER_SELECTION_TIMEOUT_DEFAULT: u32 = 0xfa; // inferred
pub const OP_ABORT_DEVICE: u32 = 0x16; // inferred
pub const OP_BUS_RESET: u32 = 0x18; // inferred
pub const OP_DUMP_RAM: u32 = 0x3; // inferred
pub const OP_LOAD_RAM: u32 = 0x1; // inferred
pub const OP_SET_SELECTION_TIMEOUT: u32 = 0x31; // inferred
pub const PCI_BUS_WIDTH_BITS: u32 = 0x40; // established
pub const PCI_CLOCK_MHZ: u32 = 0x42; // established
pub const PCI_DEVICE_ID: u32 = 0x1216; // established
