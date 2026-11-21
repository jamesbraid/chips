// generated from devices/ics1890/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 2677952e5dcb35c5d7263390a75249ba01d1e1a2864c98a6cfa1dfe1b408648f
// ICS1890 10Base-T/100Base-TX PHYceiver, MII management registers (Octane base I/O)
#![allow(dead_code)]

pub mod enums {
    pub mod model {
        pub const ICS1889: u32 = 1; // established
        pub const ICS1890: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Ics1889,
            Ics1890,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    1 => Self::Ics1889,
                    2 => Self::Ics1890,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Ics1889 => 1,
                    Self::Ics1890 => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod revision {
        pub const INTERNAL: u32 = 0; // established
        pub const ALPHA: u32 = 1; // established
        pub const GENERAL: u32 = 2; // established
        pub const J_OR_LATER: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Internal,
            Alpha,
            General,
            JOrLater,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Internal,
                    1 => Self::Alpha,
                    2 => Self::General,
                    3 => Self::JOrLater,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Internal => 0,
                    Self::Alpha => 1,
                    Self::General => 2,
                    Self::JOrLater => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// PHY identifier, first word: the low 16 bits of the 24-bit OUI. The part resets to the Integrated Circuit Systems OUI. Writes take effect only after th (established)
pub mod phy_id1 {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
    pub mod oui_low { // bits 15:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// PHY identifier, second word: OUI bits 19 to 24, the model number and the revision number. Reset value is the ICS1890 identity. Writes need the command (established)
pub mod phy_id2 {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x3;
    pub mod oui_high { // bits 15:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod model { // bits 9:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::model::Value;
    }
    pub mod revision { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::revision::Value;
    }
}
/// Extended control. Pre-programs the part; reset loads the defaults from the datasheet's table. Only the bits below are transcribed here. Other bits (fo (established)
pub mod ext_ctrl {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x10;
    pub mod command_override { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod phy_address { // bits 10:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reserved_ics_4 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
