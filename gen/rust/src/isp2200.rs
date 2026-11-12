// generated from defs/isp2200.toml by defs-gen - do not edit, change the source
// QLogic ISP2200 Fibre Channel host adapter (PCI 1077:2200), the host interface the public drivers use
#![allow(dead_code)]

pub mod enums {
    pub mod hccr_cmd {
        pub const NOOP: u32 = 0; // established
        pub const RESET_RISC: u32 = 1; // established
        pub const PAUSE_RISC: u32 = 2; // established
        pub const RELEASE_RISC: u32 = 3; // established
        pub const PARITY: u32 = 4; // established
        pub const SET_HOST_INT: u32 = 5; // established
        pub const CLEAR_HOST_INT: u32 = 6; // established
        pub const CLEAR_RISC_INT: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Noop,
            ResetRisc,
            PauseRisc,
            ReleaseRisc,
            Parity,
            SetHostInt,
            ClearHostInt,
            ClearRiscInt,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Noop,
                    1 => Self::ResetRisc,
                    2 => Self::PauseRisc,
                    3 => Self::ReleaseRisc,
                    4 => Self::Parity,
                    5 => Self::SetHostInt,
                    6 => Self::ClearHostInt,
                    7 => Self::ClearRiscInt,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Noop => 0,
                    Self::ResetRisc => 1,
                    Self::PauseRisc => 2,
                    Self::ReleaseRisc => 3,
                    Self::Parity => 4,
                    Self::SetHostInt => 5,
                    Self::ClearHostInt => 6,
                    Self::ClearRiscInt => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Control and status register. Writing bit 0 starts a soft reset. The drivers poll the bit until the adapter clears it. Bits 5 and 4 choose the bank tha (established)
pub mod csr {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
    pub mod bank { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod soft_reset { // bits 0:0, established
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
/// Interrupt control. The drivers write 0x8008 to enable and 0 to disable. Other bits are not used by any public driver for this part. (established)
pub mod icr {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x8;
    pub mod global_enable { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod risc_enable { // bits 3:3, established
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
/// Interrupt status. Drivers test the RISC interrupt bit first. OpenBSD also tests the pending bit before it reads the response ring. (established)
pub mod isr {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xa;
    pub mod any_pending { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod risc_pending { // bits 3:3, established
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
/// Semaphore. The adapter sets the lock bit when a mailbox result or asynchronous event waits for the host. The host releases it by writing 0, and the dr (established)
pub mod sema {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xc;
    pub mod status { // bits 1:1, unknown
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lock { // bits 0:0, established
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
/// Serial EEPROM port. The host bit-bangs the clock, chip select and data lines to read the board NVRAM. (established)
pub mod nvram {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xe;
    pub mod data_from_eeprom { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod data_to_eeprom { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod select { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clock { // bits 0:0, established
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
/// Mailboxes 0 to 7, two bytes apart. Mailbox 0 carries the command number in and the status out. Mailbox 4 is the request-queue pointer and mailbox 5 th (established)
pub mod mailbox {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x10;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 2;
}
/// Host command and control register. A write carries a command in bits 15 to 12. A read returns status in the bits named below. Reset values are not sta (established)
pub mod hccr {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xc0;
    pub mod cmd { // bits 15:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::hccr_cmd::Value;
    }
    pub mod host_int { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod risc_reset { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod risc_paused { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Mailboxes 8 to 23. The count of 24 comes from two drivers, but only Linux gives where the upper sixteen sit. Linux writes all 24 on every mailbox comm (inferred)
pub mod mailbox_hi {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xe0;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 2;
}
pub const ASYNC_EVENT_FIRST: u32 = 0x8000; // established
pub const ASYNC_EVENT_LAST: u32 = 0xbfff; // established
pub const ASYNC_LIP: u32 = 0x8010; // established
pub const ASYNC_LOOP_DOWN: u32 = 0x8012; // established
pub const ASYNC_LOOP_UP: u32 = 0x8011; // established
pub const ASYNC_PORT_DB_CHANGE: u32 = 0x8014; // established
pub const ASYNC_RESET: u32 = 0x8001; // established
pub const ASYNC_RSCN: u32 = 0x8015; // established
pub const CMD_ENTRY_32: u32 = 0x11; // inferred
pub const CMD_ENTRY_64: u32 = 0x19; // established
pub const CONT_ENTRY_32: u32 = 0x2; // inferred
pub const CONT_ENTRY_64: u32 = 0xa; // inferred
pub const CPL_ABORTED: u32 = 0x5; // established
pub const CPL_COMPLETE: u32 = 0x0; // established
pub const CPL_DATA_OVERRUN: u32 = 0x7; // established
pub const CPL_DATA_UNDERRUN: u32 = 0x15; // established
pub const CPL_DMA_ERROR: u32 = 0x2; // established
pub const CPL_INCOMPLETE: u32 = 0x1; // established
pub const CPL_PORT_BUSY: u32 = 0x2b; // established
pub const CPL_PORT_CONFIG_CHANGED: u32 = 0x2a; // established
pub const CPL_PORT_LOGGED_OUT: u32 = 0x29; // established
pub const CPL_PORT_UNAVAILABLE: u32 = 0x28; // established
pub const CPL_QUEUE_FULL: u32 = 0x1c; // established
pub const CPL_RESET: u32 = 0x4; // established
pub const CPL_TIMEOUT: u32 = 0x6; // established
pub const CPL_TRANSPORT_ERROR: u32 = 0x3; // established
pub const ENTRY_BYTES: u32 = 0x40; // established
pub const FIRMWARE_LENGTH_WORD_INDEX: u32 = 0x3; // established
pub const ICB_BYTES: u32 = 0x60; // established
pub const ICB_VERSION: u32 = 0x1; // established
pub const MAILBOXES_TOTAL: u32 = 0x18; // established
pub const MARKER_ENTRY: u32 = 0x4; // established
pub const MBOX0_BUSY: u32 = 0x4; // established
pub const MBOX_COMPLETION_LAST: u32 = 0x7fff; // established
pub const NVRAM_IMAGE_BYTES: u32 = 0x100; // established
pub const OP_ABOUT_FIRMWARE: u32 = 0x8; // established
pub const OP_DUMP_RAM: u32 = 0x3; // inferred
pub const OP_EXECUTE_FIRMWARE: u32 = 0x2; // established
pub const OP_FIRMWARE_STATUS: u32 = 0x1f; // inferred
pub const OP_GET_FIRMWARE_OPTIONS: u32 = 0x28; // inferred
pub const OP_INIT_FIRMWARE: u32 = 0x60; // established
pub const OP_LOAD_RAM_32: u32 = 0x1; // inferred
pub const OP_LOAD_RAM_DMA: u32 = 0x9; // inferred
pub const OP_LOAD_RAM_EXT: u32 = 0xb; // inferred
pub const OP_MAILBOX_TEST: u32 = 0x6; // inferred
pub const OP_NOOP: u32 = 0x0; // established
pub const OP_READ_RAM_WORD: u32 = 0x5; // inferred
pub const OP_SET_FIRMWARE_OPTIONS: u32 = 0x38; // inferred
pub const OP_VERIFY_CHECKSUM: u32 = 0x7; // established
pub const OP_WRITE_RAM_WORD: u32 = 0x4; // established
pub const PCI_BAR_IO_CONFIG_OFFSET: u32 = 0x10; // established
pub const PCI_BAR_MEM_CONFIG_OFFSET: u32 = 0x14; // established
pub const PCI_CONFIG_BUS_MASTER_BIT: u32 = 0x4; // established
pub const PCI_DEVICE_ID: u32 = 0x2200; // established
pub const PCI_VENDOR_ID: u32 = 0x1077; // established
pub const PRODUCT_ID_MAILBOX1: u32 = 0x4953; // established
pub const PRODUCT_ID_MAILBOX2: u32 = 0x5020; // established
pub const PRODUCT_ID_MAILBOX3: u32 = 0x2020; // established
pub const REGISTER_WINDOW_BYTES: u32 = 0x100; // established
pub const RISC_CODE_ORIGIN_WORD: u32 = 0x1000; // established
pub const ROM_VERSION_MAILBOX7: u32 = 0x4; // inferred
pub const SEGMENT_LIST_ENTRY: u32 = 0x15; // inferred
pub const STATUS_COMMAND_ERROR: u32 = 0x4005; // established
pub const STATUS_COMPLETE: u32 = 0x4000; // established
pub const STATUS_CONT_ENTRY: u32 = 0x10; // established
pub const STATUS_ENTRY: u32 = 0x3; // established
pub const STATUS_HOST_INTERFACE_ERROR: u32 = 0x4002; // established
pub const STATUS_INVALID_COMMAND: u32 = 0x4001; // established
pub const STATUS_PARAMETER_ERROR: u32 = 0x4006; // established
pub const STATUS_TEST_FAILED: u32 = 0x4003; // established
