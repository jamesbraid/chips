// generated from devices/lh28f800su/registers.toml by defs-gen - do not edit, change the source
// Sharp LH28F800SU 8 Mbit x16 flash: array geometry, command set, identifier and status registers
#![allow(dead_code)]

pub mod enums {
    pub mod bsr_op {
        pub const OK_OR_RUNNING: u32 = 0; // established
        pub const FAILURE: u32 = 2; // established
        pub const ABORTED: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            OkOrRunning,
            Failure,
            Aborted,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::OkOrRunning,
                    2 => Self::Failure,
                    3 => Self::Aborted,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::OkOrRunning => 0,
                    Self::Failure => 2,
                    Self::Aborted => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod gsr_op {
        pub const OK_OR_RUNNING: u32 = 0; // established
        pub const SLEEP: u32 = 1; // established
        pub const FAILURE: u32 = 2; // established
        pub const FAILURE_OR_ABORT: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            OkOrRunning,
            Sleep,
            Failure,
            FailureOrAbort,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::OkOrRunning,
                    1 => Self::Sleep,
                    2 => Self::Failure,
                    3 => Self::FailureOrAbort,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::OkOrRunning => 0,
                    Self::Sleep => 1,
                    Self::Failure => 2,
                    Self::FailureOrAbort => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Block status register, one per block, read through the extended-status mode at the BSR word address of that block. Bits 1 and 0 are reserved. (established)
pub mod bsr {
    pub const WIDTH: u32 = 8;
    pub mod block_ready { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lock_cleared { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod op_status { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::bsr_op::Value;
    }
    pub mod queue_full { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod low_vpp { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Compatible status register, read after 0x70. Bit 7 is ready when set and busy when clear. Bits 2 to 0 are reserved. (established)
pub mod csr {
    pub const WIDTH: u32 = 8;
    pub mod ready { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod erase_suspended { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod erase_error { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod program_error { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod low_vpp { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Global status register, read through the extended-status mode at the GSR word address of a block. Only the low byte is defined. DQ8 to DQ15 float duri (established)
pub mod gsr {
    pub const WIDTH: u32 = 8;
    pub mod write_ready { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod suspended { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod op_status { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::gsr_op::Value;
    }
    pub mod queue_full { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod buffer_available { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod buffer_ready { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod buffer_select { // bits 0:0, established
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
pub const LH28F800SU_ARRAY_BYTES: u32 = 0x100000; // established
pub const LH28F800SU_BLOCK_BYTES: u32 = 0x10000; // inferred
pub const LH28F800SU_BLOCK_COUNT: u32 = 0x10; // established
pub const LH28F800SU_BLOCK_ERASE_TYP_MS: u32 = 0x2bc; // established
pub const LH28F800SU_BLOCK_WORDS: u32 = 0x8000; // established
pub const LH28F800SU_CMD_BLOCK_LOCK: u32 = 0x77; // established
pub const LH28F800SU_CMD_CLEAR_STATUS: u32 = 0x50; // established
pub const LH28F800SU_CMD_CONFIRM: u32 = 0xd0; // established
pub const LH28F800SU_CMD_ERASE_SETUP: u32 = 0x20; // established
pub const LH28F800SU_CMD_EXT_STATUS: u32 = 0x71; // established
pub const LH28F800SU_CMD_IDENTIFY: u32 = 0x90; // established
pub const LH28F800SU_CMD_PROGRAM: u32 = 0x40; // established
pub const LH28F800SU_CMD_PROGRAM_ALT: u32 = 0x10; // established
pub const LH28F800SU_CMD_READ_ARRAY: u32 = 0xff; // established
pub const LH28F800SU_CMD_READ_STATUS: u32 = 0x70; // established
pub const LH28F800SU_CMD_SUSPEND: u32 = 0xb0; // established
pub const LH28F800SU_CMD_UPLOAD_STATUS: u32 = 0x97; // established
pub const LH28F800SU_ID_WORD0: u32 = 0xb0; // established
pub const LH28F800SU_ID_WORD1: u32 = 0x66a8; // established
pub const LH28F800SU_RP_RECOVERY_NS: u32 = 0x190; // established
pub const LH28F800SU_WORD_PROGRAM_TYP_US: u32 = 0x8; // established
