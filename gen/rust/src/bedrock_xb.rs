// generated from defs/bedrock_xb.toml by defs-gen - do not edit, change the source
// Bedrock internal crossbar (XB) registers outside the census
#![allow(dead_code)]

pub mod enums {
    pub mod first_error_source {
        pub const LIQ: u32 = 2; // inferred
        pub const LOQ: u32 = 3; // inferred
        pub const IIQ: u32 = 4; // inferred
        pub const IOQ: u32 = 5; // inferred
        pub const NIQ: u32 = 6; // inferred
        pub const NOQ: u32 = 7; // inferred
        pub const MIQ: u32 = 8; // inferred
        pub const MMQ: u32 = 9; // inferred
        pub const MP1: u32 = 10; // inferred
        pub const MP0: u32 = 11; // inferred
        pub const PIQ1: u32 = 12; // inferred
        pub const POQ1: u32 = 13; // inferred
        pub const PIQ0: u32 = 14; // inferred
        pub const POQ0: u32 = 15; // inferred
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Liq,
            Loq,
            Iiq,
            Ioq,
            Niq,
            Noq,
            Miq,
            Mmq,
            Mp1,
            Mp0,
            Piq1,
            Poq1,
            Piq0,
            Poq0,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    2 => Self::Liq,
                    3 => Self::Loq,
                    4 => Self::Iiq,
                    5 => Self::Ioq,
                    6 => Self::Niq,
                    7 => Self::Noq,
                    8 => Self::Miq,
                    9 => Self::Mmq,
                    10 => Self::Mp1,
                    11 => Self::Mp0,
                    12 => Self::Piq1,
                    13 => Self::Poq1,
                    14 => Self::Piq0,
                    15 => Self::Poq0,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Liq => 2,
                    Self::Loq => 3,
                    Self::Iiq => 4,
                    Self::Ioq => 5,
                    Self::Niq => 6,
                    Self::Noq => 7,
                    Self::Miq => 8,
                    Self::Mmq => 9,
                    Self::Mp1 => 10,
                    Self::Mp0 => 11,
                    Self::Piq1 => 12,
                    Self::Poq1 => 13,
                    Self::Piq0 => 14,
                    Self::Poq0 => 15,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Crossbar-wide parameters. The header gives the bypass enable and three wrap periods (age, deadlock, tail). It does not say what the periods count or h (inferred)
pub mod xb_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700000;
    pub mod tail_wrap { // bits 51:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xfffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock_wrap { // bits 31:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xfffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age_wrap { // bits 11:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod byp_en { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Wavefront grant period per unit: the number of cycles between grant opportunities. The all-ones value gives no grants, and one less than all ones the  (inferred)
pub mod xb_slow_gnt {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700008;
    pub mod pi0 { // bits 31:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pi1 { // bits 27:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mp0 { // bits 23:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mp1 { // bits 19:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mmq { // bits 15:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ni { // bits 11:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ii { // bits 7:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lb { // bits 3:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Snoop selector for internal crossbar traffic, sent to the PI1 port. The header says only one selector should be set, and any set selector takes PI1 aw (inferred)
pub mod xb_spew_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700010;
    pub mod snoop_poq0 { // bits 10:10, inferred
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_mp0 { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_mmq { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_noq { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_ioq { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_loq { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_piq0 { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_miq { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_niq { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_iiq { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod snoop_liq { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Clocks the I/O output queue waits before crossbar arbitration starts, so the slower I/O data rate can catch up in the queue buffer. (inferred)
pub mod xb_ioq_arb_trigger {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700018;
    pub mod clocks { // bits 3:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error record for the PI0 output queue. The header says software may write it to test error handling, and the write raises an interrupt. (inferred)
pub mod xb_poq0_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700020;
    pub mod tail_timeout { // bits 13:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod underflow { // bits 9:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overflow { // bits 5:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod invalid_xsel { // bits 1:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error record for the PI0 input queue. The header says the processor-interface input cannot underflow, so no underflow field is defined. (inferred)
pub mod xb_piq0_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700028;
    pub mod deadlock_timeout { // bits 5:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overflow { // bits 1:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error record for the PI1 output queue. The header gives no field layout for it. (inferred)
pub mod xb_poq1_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700030;
}
/// Error record for the PI1 input queue. The header gives no field layout for it. (inferred)
pub mod xb_piq1_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700038;
}
/// Error record for the memory-to-PI0 output queue. The header notes the crossbar select is decoded on the memory side of this queue, so no invalid-selec (inferred)
pub mod xb_mp0_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700040;
    pub mod tail_timeout { // bits 13:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod underflow { // bits 9:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overflow { // bits 5:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error record for the memory-to-PI1 output queue. The header gives no field layout for it. (inferred)
pub mod xb_mp1_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700048;
}
/// Error record for the memory output queue that carries miscellaneous traffic to LB, NI and II. The header gives no field layout for it. (inferred)
pub mod xb_mmq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700050;
}
/// Error record for the memory input queue. The header says further errors of this queue are logged in the memory unit's input error registers. (inferred)
pub mod xb_miq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700058;
    pub mod deadlock_timeout { // bits 7:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error record for the NI output queue. The header defines three separate 4-bit counters for it. (inferred)
pub mod xb_noq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700060;
    pub mod tail_timeout { // bits 15:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod underflow { // bits 11:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overflow { // bits 7:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error record for the NI input queue. The header gives no field layout for it. (inferred)
pub mod xb_niq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700068;
}
/// Error record for the I/O output queue. The header gives no field layout for it. (inferred)
pub mod xb_ioq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700070;
}
/// Error record for the I/O input queue. The header gives no field layout for it. (inferred)
pub mod xb_iiq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700078;
}
/// Error record for the LB output queue. (inferred)
pub mod xb_loq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700080;
    pub mod tail_timeout { // bits 13:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod underflow { // bits 9:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod invalid_xsel { // bits 1:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Error record for the LB input queue. The header says it records only request-channel errors: the reply channel has no flow control and cannot overflow (inferred)
pub mod xb_liq_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700088;
    pub mod deadlock_timeout { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overflow { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// The first crossbar error latched. It latches when the valid bit is clear and an error occurs. Any set valid bit interrupts both processor interfaces.  (inferred)
pub mod xb_first_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700090;
    pub mod valid { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod source { // bits 11:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::first_error_source::Value;
    }
    pub mod channel { // bits 7:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod err_type { // bits 3:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Selects which queue observation points drive debug output. The header says more than one selected point makes the debug output undefined. The output f (inferred)
pub mod xb_debug_data_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700098;
    pub mod observe_lodata { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_source_field { // bits 14:14, inferred
        pub const SHIFT: u32 = 14;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_poq0 { // bits 13:13, inferred
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_poq1 { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_mmq { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_mp0 { // bits 10:10, inferred
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_mp1 { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_noq { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_ioq { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_loq { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_piq0 { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_piq1 { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_miq { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_niq { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_iiq { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod observe_liq { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Three-bit select for the debug mux of the crossbar's queues and arbiter. The header does not give the output each value selects. (inferred)
pub mod xb_debug_arb_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7000a0;
    pub mod select { // bits 2:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Clears the PI0 output queue error record. The header does not say whether a write clears by any value or only by set bits, so the mechanism is unknown (inferred)
pub mod xb_poq0_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700120;
}
/// Clears the PI0 input queue error record. The write mechanism is unknown; field layout as the base register. (inferred)
pub mod xb_piq0_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700128;
}
/// Clears the PI1 output queue error record. The write mechanism is unknown. (inferred)
pub mod xb_poq1_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700130;
}
/// Clears the PI1 input queue error record. The write mechanism is unknown. (inferred)
pub mod xb_piq1_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700138;
}
/// Clears the memory-to-PI0 output queue error record. The write mechanism is unknown. (inferred)
pub mod xb_mp0_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700140;
}
/// Clears the memory-to-PI1 output queue error record. The write mechanism is unknown. (inferred)
pub mod xb_mp1_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700148;
}
/// Clears the memory output queue error record. The write mechanism is unknown. (inferred)
pub mod xb_mmq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700150;
}
/// Clears the memory input queue error record. The header names this register with an extra XM_ in the macro, and its comment says it clears the MIQ erro (inferred)
pub mod xb_miq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700158;
}
/// Clears the NI output queue error record. The write mechanism is unknown. (inferred)
pub mod xb_noq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700160;
}
/// Clears the NI input queue error record. The write mechanism is unknown. (inferred)
pub mod xb_niq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700168;
}
/// Clears the I/O output queue error record. The write mechanism is unknown. (inferred)
pub mod xb_ioq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700170;
}
/// Clears the I/O input queue error record. The write mechanism is unknown. (inferred)
pub mod xb_iiq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700178;
}
/// Clears the LB output queue error record. The write mechanism is unknown. (inferred)
pub mod xb_loq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700180;
}
/// Clears the LB input queue error record. The write mechanism is unknown. (inferred)
pub mod xb_liq_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700188;
}
/// Clears the first-error register. The header says it is cleared after the error register that captured the error. The write mechanism is unknown. (inferred)
pub mod xb_first_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700190;
}
pub const XB_PARMS_ACTIVE_DEFAULTS: u64 = 0x80000fffff021; // inferred
pub const XB_PARMS_RESET_DEFAULTS: u64 = 0x8000080000021; // inferred
