// @generated from devices/isp1040/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 c6f60bd0ad553be96496d3d404604374c4fbab53c331492226b573abf3d0d9b4
// QLogic ISP1040 family SCSI host adapter (PCI 1077:1020), register and mailbox contract
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Low half of the identity word. The reset value is not stated by any source. (established)
pub mod id_l {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x0;
}
/// High half of the identity word. The reset value is not stated by any source. (established)
pub mod id_h {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
}
/// Configuration 0. Its low four bits hold the hardware revision. Linux compares that revision with the 1040A value only, to decide whether to set the FI (established)
pub mod cfg_0 {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
    pub mod hw_revision { // bits 3:0, established
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
/// Configuration 1: FIFO threshold and bus burst enable, written by the drivers at start-up. (established)
pub mod cfg_1 {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
}
/// Bus interface control. It holds the soft reset bit, the interrupt enables and the flash BIOS controls. (established)
pub mod ictrl {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x8;
    pub mod flash_upper { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flash_enable { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod risc_int_enable { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_enable { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod soft_reset { // bits 0:0, inferred
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
/// Interface status. Its bit meanings are not described here; the reset value is unknown. (established)
pub mod istatus {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xa;
}
/// Semaphore register. Linux names it; its use is not described here. (established)
pub mod semaphore {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xc;
}
/// Serial NVRAM interface register. Linux names its clock, select, data-out and data-in bits. (established)
pub mod nvram {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xe;
}
/// Flash BIOS data. Linux and OpenBSD both name it for this part. The NetBSD driver assigns the same offset to request-queue pointers for a later chip ge (inferred)
pub mod flash_data {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x10;
}
/// Flash BIOS address. The same naming and the same two-driver footing as the flash data word. (inferred)
pub mod flash_address {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x12;
}
/// Eight 16-bit mailbox registers, mailboxes 0 to 7 at 0x70 to 0x7e. Mailbox 0 carries the opcode of each command. The other mailboxes carry its operands (established)
pub mod mailbox {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x70;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 2;
}
pub const ASYNC_BUS_RESET: u32 = 0x8001; // established
pub const BUSES: u32 = 0x1; // inferred
pub const DRIVER_SELECTION_TIMEOUT_DEFAULT: u32 = 0xfa; // inferred
pub const OP_BUS_RESET: u32 = 0x18; // established
pub const OP_DUMP_RAM_64: u32 = 0xa; // inferred
pub const OP_GET_TARGET_PARAMS: u32 = 0x28; // established
pub const OP_LOAD_RAM_64: u32 = 0x9; // inferred
pub const OP_SET_RESET_DELAY_PARAMS: u32 = 0x3a; // established
pub const OP_SET_RETRY_COUNT: u32 = 0x32; // established
pub const OP_SET_SELECTION_TIMEOUT: u32 = 0x31; // established
pub const OP_SET_TARGET_PARAMS: u32 = 0x38; // established
pub const PCI_REV_1040: u32 = 0x2; // inferred
pub const PCI_REV_1040A: u32 = 0x3; // inferred
pub const PCI_REV_1040B: u32 = 0x4; // inferred
pub const PCI_REV_1040C: u32 = 0x5; // inferred
pub const SCSI2_SELECTION_ABORT_US: u32 = 0xc8; // established
pub const SCSI2_SELECTION_TIMEOUT_MS: u32 = 0xfa; // established
pub const STATE_GOT_BUS: u32 = 0x100; // established
pub const STATE_GOT_SENSE: u32 = 0x2000; // inferred
pub const STATE_GOT_TARGET: u32 = 0x200; // established
pub const STATUS_COMP_INCOMPLETE: u32 = 0x1; // established
pub const STATUS_COMP_RESET: u32 = 0x4; // established
pub const STATUS_ENTRY_COMP_STATUS_OFFSET: u32 = 0xa; // established
pub const STATUS_ENTRY_SENSE_LENGTH_OFFSET: u32 = 0x12; // established
pub const STATUS_ENTRY_STATE_FLAGS_OFFSET: u32 = 0xc; // established
pub const STATUS_ENTRY_STATUS_FLAGS_OFFSET: u32 = 0xe; // established
pub const STATUS_FLAG_SELECTION_TIMEOUT: u32 = 0x40; // inferred
