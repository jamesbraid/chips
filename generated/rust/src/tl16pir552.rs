// generated from devices/tl16pir552/registers.toml by defs-gen - do not edit, change the source
// TI TL16PIR552 dual UART and IEEE 1284 parallel port, parallel-port register contract (Fuel and Origin 200 board part)
#![allow(dead_code)]

pub mod enums {
    pub mod cnfgb_dma_select {
        pub const DMA3: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Dma3,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    3 => Self::Dma3,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Dma3 => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod cnfgb_irq_select {
        pub const IRQ7: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Irq7,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    1 => Self::Irq7,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Irq7 => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ecr_mode {
        pub const STANDARD: u32 = 0; // established
        pub const BIDIRECTIONAL: u32 = 1; // established
        pub const PARALLEL_FIFO: u32 = 2; // established
        pub const ECP: u32 = 3; // established
        pub const EPP: u32 = 4; // established
        pub const RESERVED: u32 = 5; // established
        pub const TEST_FIFO: u32 = 6; // established
        pub const CONFIGURATION: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Standard,
            Bidirectional,
            ParallelFifo,
            Ecp,
            Epp,
            Reserved,
            TestFifo,
            Configuration,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Standard,
                    1 => Self::Bidirectional,
                    2 => Self::ParallelFifo,
                    3 => Self::Ecp,
                    4 => Self::Epp,
                    5 => Self::Reserved,
                    6 => Self::TestFifo,
                    7 => Self::Configuration,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Standard => 0,
                    Self::Bidirectional => 1,
                    Self::ParallelFifo => 2,
                    Self::Ecp => 3,
                    Self::Epp => 4,
                    Self::Reserved => 5,
                    Self::TestFifo => 6,
                    Self::Configuration => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Configuration register B, read only. Its IRQ-line sample bit depends on the board wiring, so its reset value is unknown. (established)
pub mod cnfgb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod compression { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irq_line_sample { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irq_select { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::cnfgb_irq_select::Value;
    }
    pub mod dma_select { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::cnfgb_dma_select::Value;
    }
}
/// Extended control register. Its top three bits select the mode, which also decides what the other chip-select offsets hold. The two low bits are read o (established)
pub mod ecr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod mode { // bits 7:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ecr_mode::Value;
    }
    pub mod ecp_fault_irq_disable { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dma_enable { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod service_intr_disable { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fifo_full { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fifo_empty { // bits 0:0, established
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
/// Configuration register A, read only. It reads the constant with the implementation ID in the top nibble and the low nibble reserved and read as ones. (established)
pub mod cnfga {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod impl_id { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reserved_low { // bits 3:0, established
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
/// Forward data FIFO that uses the standard parallel-port handshake. (established)
pub mod pp_fifo {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// ECP data FIFO. A forward write enqueues data. A reverse read receives peripheral data through the ECP handshake. (established)
pub mod ecp_dfifo {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Test FIFO with no parallel-port protocol handshake. FIFO state stays reflected by the FULL and EMPTY bits. Overflow and underrun do not stall. Read an (established)
pub mod test_fifo {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Parallel data port in standard and bidirectional modes. A write drives the data lines and a read returns their value. In the other modes offset 0 of t (established)
pub mod data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Status inputs, plus the PRINT and EPP TIMEOUT status. PRINT clears on a rising ACK and sets when this register is read. TIMEOUT clears when this regis (established)
pub mod dsr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod busy { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ack { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod perror { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod select_in { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fault { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod print_intr { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod timeout { // bits 0:0, established
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
/// Parallel control register. (established)
pub mod dcr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod direction { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irq_on_ack { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod select_ctl { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod init_ctl { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod autofd_ctl { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod strobe_ctl { // bits 0:0, established
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
/// EPP address. An access generates the EPP address strobe automatically. (established)
pub mod epp_addr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
}
/// EPP data. Each of the four offsets with the high address bit set is this register. An access generates the EPP data strobe automatically. (established)
pub mod epp_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 1;
}
/// ECP address FIFO. A written byte enters the FIFO tagged as an ECP address. (established)
pub mod ecp_afifo {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
