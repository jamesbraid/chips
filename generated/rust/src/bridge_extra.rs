// generated from devices/bridge/registers-extra.toml by defs-gen - do not edit, change the source
// Bridge-family registers and bits outside the census
#![allow(dead_code)]

/// The widget identification word as the shipped IRIX kernel reads it for the Bridge family. The kernel reads the 32-bit word at byte offset 4 of the wid (established)
pub mod wid_id_format {
    pub const WIDTH: u32 = 32;
    pub mod part { // bits 27:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const BRIDGE: u32 = 49154; // established
        pub const XBRIDGE: u32 = 53250; // established
        pub const PIC_BUS0: u32 = 53506; // established
        pub const PIC_BUS1: u32 = 53522; // established
        pub const TIOCP_A: u32 = 57344; // established
        pub const TIOCP_B: u32 = 57360; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Bridge,
            Xbridge,
            PicBus0,
            PicBus1,
            TiocpA,
            TiocpB,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    49154 => Self::Bridge,
                    53250 => Self::Xbridge,
                    53506 => Self::PicBus0,
                    53522 => Self::PicBus1,
                    57344 => Self::TiocpA,
                    57360 => Self::TiocpB,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Bridge => 49154,
                    Self::Xbridge => 53250,
                    Self::PicBus0 => 53506,
                    Self::PicBus1 => 53522,
                    Self::TiocpA => 57344,
                    Self::TiocpB => 57360,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod manufacturer { // bits 11:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const MFR_36: u32 = 36; // established
        pub const MFR_54: u32 = 54; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Mfr36,
            Mfr54,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    36 => Self::Mfr36,
                    54 => Self::Mfr54,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Mfr36 => 36,
                    Self::Mfr54 => 54,
                    Self::Other(v) => v,
                }
            }
        }
    }
}
pub const CFG_FUNC_SHIFT: u32 = 0x8; // established
pub const CFG_SLOTS_32: u32 = 0x8; // established
pub const CFG_SLOT_BIAS_64: u32 = 0x1; // established
pub const CFG_SLOT_SHIFT: u32 = 0xc; // established
pub const CFG_WINDOW32_OFFSET: u32 = 0x20000; // established
pub const CONTROL_FLASH_WR_EN: u32 = 0x80000000; // established
pub const CONTROL_RST_PIN_N: u32 = 0xf000000; // established
pub const CONTROL_WIDGET_NUMBER: u32 = 0xf; // established
pub const DEVICE_BARRIER: u32 = 0x8000; // established
pub const DEVICE_PRECISE: u32 = 0x20000; // established
pub const DEVICE_PREFETCH: u32 = 0x40000; // established
pub const DEVICE_REALTIME: u32 = 0x200000; // established
pub const DEVICE_SIZE_64: u32 = 0x400000; // established
pub const DEVICE_SWAP_PAIR: u32 = 0x180000; // established
pub const DEVICE_SWAP_PROGRAMMED: u32 = 0x2000; // established
pub const DEVICE_WRITE_GATHER_EN: u32 = 0x1800000; // established
pub const INTR_ADDR32_HI: u32 = 0x11; // established
pub const INTR_ADDR32_LO: u32 = 0x8; // established
pub const INTR_ADDR32_OFFSET: u32 = 0x134; // established
pub const INTR_ADDR32_SRC_HI: u32 = 0x2f; // established
pub const INTR_ADDR32_SRC_LO: u32 = 0x26; // established
pub const INTR_ADDR64_OFFSET: u32 = 0x130; // established
pub const INTR_COUNT: u32 = 0x8; // established
pub const INTR_STRIDE: u32 = 0x8; // established
pub const INT_STATUS_INVALID_ADDRESS: u32 = 0x1000000; // established
pub const STATUS_FLASH_SELECT: u32 = 0x40; // established
pub const TEST_PIN_CONTROL: u32 = 0x70; // established
pub const TEST_PIN_CONTROL_DATA_OUT: u32 = 0xf00; // established
pub const TEST_PIN_CONTROL_SELECT0: u32 = 0x3; // established
pub const TEST_PIN_CONTROL_SELECT1: u32 = 0xc; // established
pub const TEST_PIN_CONTROL_SELECT2: u32 = 0x30; // established
pub const TEST_PIN_CONTROL_SELECT3: u32 = 0xc0; // established
pub const WID_OFFSET: u32 = 0x4; // established
pub const WINDOW_BIT_A: u32 = 0x3f; // established
pub const WINDOW_BIT_B: u32 = 0x3c; // established
pub const WINDOW_BIT_C: u32 = 0x39; // established
pub const XBRIDGE_TEST_PIN_CONTROL_DATA_OUT: u32 = 0xff0000; // established
