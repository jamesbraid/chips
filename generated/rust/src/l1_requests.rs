// @generated from formats/l1_requests/format.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 9b3aa784db21ee484f4206cd4dc8b9729cd11cf3f9d9d9a81598e181b6c4e09d
// request codes the Origin 3000 kernel sends to the brick controller
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub const REQ_ELSC_CONS_NODE: u32 = 0x1003; // established
pub const REQ_ELSC_CONS_SUBCH: u32 = 0x1002; // established
pub const REQ_ELSC_DEBUG_GET: u32 = 0x1; // established
pub const REQ_ELSC_DISPLAY_LINE_1: u32 = 0x1004; // established
pub const REQ_ELSC_DISPLAY_LINE_2: u32 = 0x1005; // established
pub const REQ_ELSC_EVT_UNREG: u32 = 0x100a; // established
pub const REQ_ELSC_LED_SET: u32 = 0x1009; // established
pub const REQ_ELSC_ODY_EXPANDER_GET: u32 = 0x2007; // established
pub const REQ_ELSC_ODY_EXPANDER_SET: u32 = 0x2008; // established
pub const REQ_ELSC_PARTITION_GET: u32 = 0x9; // established
pub const REQ_ELSC_PARTITION_SET: u32 = 0x1006; // established
pub const REQ_ELSC_PWR_CYCLE: u32 = 0x2006; // established
pub const REQ_ELSC_PWR_OFF: u32 = 0x2005; // established
pub const REQ_ELSC_SLAB_GET: u32 = 0xe; // established
pub const REQ_ELSC_SYSTEM_RESET: u32 = 0x2001; // established
pub const REQ_IOBRICK_ATTACHED_BRICKS: u32 = 0xc; // established
pub const REQ_IOBRICK_GET_SYS_SNUM: u32 = 0x8; // established
pub const REQ_RACK_BAY_TYPE_GET: u32 = 0x3; // established
pub const REQ_SC_COMMAND_INTERP: u32 = 0x0; // established
pub const REQ_SC_PORTSPEED_GET: u32 = 0xa; // established
pub const REQ_SC_SET_SYSTEM_STATE: u32 = 0x100c; // established
pub const REQ_SC_VERSION: u32 = 0x5; // established
