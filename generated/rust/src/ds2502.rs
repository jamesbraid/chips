// @generated from devices/ds2502/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 9941eae5ea6d1a9225c3286c2cb883222d28d7bacbc24cc284abb93703acdb6e
// Maxim DS2502 1 Kbit add-only 1-Wire memory: ROM, commands, memory layout and timing
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const DS2502_CMD_MATCH_ROM: u32 = 0x55; // established
pub const DS2502_CMD_READ_DATA_CRC: u32 = 0xc3; // established
pub const DS2502_CMD_READ_MEMORY: u32 = 0xf0; // established
pub const DS2502_CMD_READ_ROM: u32 = 0x33; // established
pub const DS2502_CMD_READ_STATUS: u32 = 0xaa; // established
pub const DS2502_CMD_SEARCH_ROM: u32 = 0xf0; // established
pub const DS2502_CMD_SKIP_ROM: u32 = 0xcc; // established
pub const DS2502_CMD_WRITE_MEMORY: u32 = 0xf; // established
pub const DS2502_CMD_WRITE_STATUS: u32 = 0x55; // established
pub const DS2502_CRC_INIT: u32 = 0x0; // established
pub const DS2502_CRC_POLY: u32 = 0x31; // inferred
pub const DS2502_EPROM_BYTES: u32 = 0x80; // established
pub const DS2502_FAMILY_CODE: u32 = 0x9; // established
pub const DS2502_PAGE_BYTES: u32 = 0x20; // established
pub const DS2502_PROGRAM_PULSE_US: u32 = 0x1e0; // established
pub const DS2502_ROM_BITS: u32 = 0x40; // established
pub const DS2502_SERIAL_BITS: u32 = 0x30; // established
pub const DS2502_STATUS_BYTES: u32 = 0x8; // established
pub const DS2502_STATUS_FACTORY_LAST: u32 = 0x0; // established
pub const DS2502_T_LOW0_MIN_US: u32 = 0x3c; // established
pub const DS2502_T_LOW1_MAX_US: u32 = 0xf; // established
pub const DS2502_T_LOW1_MIN_US: u32 = 0x1; // established
pub const DS2502_T_PDH_MAX_US: u32 = 0x3c; // established
pub const DS2502_T_PDH_MIN_US: u32 = 0xf; // established
pub const DS2502_T_PDL_MAX_US: u32 = 0xf0; // established
pub const DS2502_T_PDL_MIN_US: u32 = 0x3c; // established
pub const DS2502_T_RDV_US: u32 = 0xf; // established
pub const DS2502_T_REC_MIN_US: u32 = 0x1; // established
pub const DS2502_T_RSTH_MIN_US: u32 = 0x1e0; // established
pub const DS2502_T_RSTL_MAX_US: u32 = 0x3c0; // established
pub const DS2502_T_RSTL_MIN_US: u32 = 0x1e0; // established
pub const DS2502_T_SLOT_MAX_US: u32 = 0x78; // established
pub const DS2502_T_SLOT_MIN_US: u32 = 0x3c; // established
