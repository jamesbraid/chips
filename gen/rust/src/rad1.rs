// generated from defs/rad1.toml by defs-gen - do not edit, change the source
// SGI RAD digital audio ASIC (PCI 10a9:0005) register contract
#![allow(dead_code)]

pub mod enums {
    pub mod channel_type {
        pub const ANALOG_IN: u32 = 0; // established
        pub const ANALOG_OUT: u32 = 1; // established
        pub const AES_IN: u32 = 2; // established
        pub const AES_OUT: u32 = 3; // established
        pub const ADAT_IN: u32 = 4; // established
        pub const ADAT_OUT: u32 = 5; // established
        pub const AES_IN_SUBCODE: u32 = 6; // inferred
        pub const ADAT_IN_SUBCODE: u32 = 7; // inferred
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            AnalogIn,
            AnalogOut,
            AesIn,
            AesOut,
            AdatIn,
            AdatOut,
            AesInSubcode,
            AdatInSubcode,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::AnalogIn,
                    1 => Self::AnalogOut,
                    2 => Self::AesIn,
                    3 => Self::AesOut,
                    4 => Self::AdatIn,
                    5 => Self::AdatOut,
                    6 => Self::AesInSubcode,
                    7 => Self::AdatInSubcode,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::AnalogIn => 0,
                    Self::AnalogOut => 1,
                    Self::AesIn => 2,
                    Self::AesOut => 3,
                    Self::AdatIn => 4,
                    Self::AdatOut => 5,
                    Self::AesInSubcode => 6,
                    Self::AdatInSubcode => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Sample-position register, ADAT input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the sta (established)
pub mod pos_adat_in_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, ADAT input, position B; also the ADAT-input subcode channel's position (read at shift 4). The upper 14 bits count frames and (established)
pub mod pos_adat_in_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, AES3 input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the sta (established)
pub mod pos_aes_in_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, AES3 input, position B; also the AES3-input subcode channel's position (read at shift 4). The upper 14 bits count frames and (established)
pub mod pos_aes_in_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, analog input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the s (established)
pub mod pos_analog_in_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, analog input position B in bits 31:18; the analog output reads bits 17:4 of this same register as its position B. The upper  (established)
pub mod pos_analog_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, ADAT output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the st (established)
pub mod pos_adat_out_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, ADAT output, position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the st (established)
pub mod pos_adat_out_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, AES3 output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the st (established)
pub mod pos_aes_out_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x24;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, AES3 output, position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the st (established)
pub mod pos_aes_out_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Sample-position register, analog output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the  (established)
pub mod pos_analog_out_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2c;
    pub mod frame_count { // bits 31:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ust_latch { // bits 17:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Free-running counter that the driver reads for timestamps and a liveness check: two reads 10 microseconds apart must differ by at least 3. No write to (established)
pub mod ust_counter {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
    pub mod count { // bits 31:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Receiver and video-reference status. The driver reads it only through the status slot copy. The bits are undecoded; use is established, meaning inferr (inferred)
pub mod sync_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
}
/// Controls the counter on the Octane board. The bit meanings, whether the writes are pulses, and whether the counter resets are unknown. (inferred)
pub mod ust_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
}
/// ADAT input channel control. Start value 0xa0000008 is written unconditionally; the other bits are undecoded. The shadow word is written whole; the dri (established)
pub mod adat_in_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x44;
    pub mod subcode_enable { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable { // bits 0:0, established
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
/// AES3 input channel control. Start value 0x10. The shadow word is written whole; the driver clears the enable at subsystem start. (established)
pub mod aes_in_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
    pub mod subcode_enable { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable { // bits 0:0, established
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
/// Analog input channel control. Start value is 0x03000000 on board mode 12 and 0x05000000 on modes 7 and 13. On mode 7 bit 27 is also the serial clock o (established)
pub mod analog_in_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4c;
    pub mod mux_clock { // bits 27:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable { // bits 0:0, established
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
/// ADAT output channel control. Start value 0x60000000 on modes 7 and 12; on mode 13 the driver leaves an unknown earlier value. The shadow word is writt (established)
pub mod adat_out_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50;
    pub mod enable { // bits 0:0, established
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
/// AES3 output channel control. Start value 0x40000000 on modes 7 and 12 and 0 on mode 13. The driver sets bits 2 and 3 as output metadata flags without  (established)
pub mod aes_out_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x54;
    pub mod metadata_flags { // bits 3:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable { // bits 0:0, established
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
/// Analog output channel control. Idle value 0x20000000, running 0x20000001. Software treats bit 0 as the start and the Octane PROM as busy: it waits for (established)
pub mod analog_out_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x58;
    pub mod clock_gen2 { // bits 30:30, inferred
        pub const SHIFT: u32 = 30;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clock_gen1 { // bits 29:29, inferred
        pub const SHIFT: u32 = 29;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod line_mux { // bits 25:25, unknown
        pub const SHIFT: u32 = 25;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable { // bits 0:0, established
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
/// Starts and stops the status ring. One shot is 0x40001, continuous is the interval field plus 0x40003, stop is 0x1fffc. Bit meanings beyond the grade o (established)
pub mod status_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x5c;
    pub mod go { // bits 18:18, unknown
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod interval { // bits 16:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x7fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod continuous { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod start { // bits 0:0, inferred
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
/// Output control shadow. Bring-up value 0x1500; halt ORs bit 8. A vendor PROM writes 0x480. Write-and-shadow: the drivers never read it back. (inferred)
pub mod output_misc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x70;
    pub mod mute { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod subcode_enable { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Written 0x08000010 once at start on every board mode. Purpose unknown. (unknown)
pub mod config_74 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x74;
}
/// Written 0x00fac688 once at start on every board mode. Purpose unknown. (unknown)
pub mod config_78 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x78;
}
/// On analog-capable boards: four gain bytes, each the driver's dB value plus 0x48, with 0 meaning mute; the whole shadow is written on each change. Star (established)
pub mod gain {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x7c;
    pub mod out_right { // bits 31:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod out_left { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod in_right { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod in_left { // bits 7:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Block reset and receiver control, written whole from a shadow. At start the driver writes 0xffffffff, 0xffe3cffe, 0xffe3c0fe, 0xffe24070, then 0xffe20 (inferred)
pub mod central_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80;
    pub mod analog_out_if_reset { // bits 14:14, inferred
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clockgen_reset { // bits 11:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod adat_rx_resync { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod adat_rx_enable { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Written 0 at start on board modes 7 and 13; skipped on mode 12. Purpose unknown. (unknown)
pub mod mode_84 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x84;
}
/// General-purpose output 1. On the Octane board a vendor PROM treats it as the analog-output relay: 3 releases the mute and 2 applies it; halt writes 2  (inferred)
pub mod gpio_relay {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
    pub mod bit1 { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit0 { // bits 0:0, inferred
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
/// General-purpose output 2. On the MediaIO card (mode 7) it is the serial data line of the 16-bit video-clock mux: for each of 16 bits, most significant (inferred)
pub mod gpio_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8c;
    pub mod const1 { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod data { // bits 0:0, inferred
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
/// Analog-output level or mode. Written 2 on board modes 7 and 12, 0 on mode 13, and 2 or 3 when the output's interface parameter selects it. What the se (established)
pub mod analog_out_mode {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
}
/// Loads one clock generator: set select bit 28 + n and the integer divisor minus one in the low bits. Rate = master / (divisor + remainder / denominator (established)
pub mod clockgen_load {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa0;
    pub mod select { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flags { // bits 10:9, unknown
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod divisor_minus_1 { // bits 8:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Fractional part of the clock divisor: the remainder in bits 31:16 and 0x10000 minus the denominator in bits 15:0. (established)
pub mod clockgen_frac {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa4;
    pub mod remainder { // bits 31:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod denominator_complement { // bits 15:0, established
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
/// Master clock select of clock generator 3, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown (inferred)
pub mod clockgen_master_3 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa8;
    pub mod master_192k { // bits 0:0, inferred
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
/// Master clock select of clock generator 2, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown (inferred)
pub mod clockgen_master_2 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xac;
    pub mod master_192k { // bits 0:0, inferred
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
/// Master clock select of clock generator 1, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown (inferred)
pub mod clockgen_master_1 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb0;
    pub mod master_192k { // bits 0:0, inferred
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
/// Master clock select of clock generator 0, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown (inferred)
pub mod clockgen_master_0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb4;
    pub mod master_192k { // bits 0:0, inferred
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
/// Written once at start on every board mode with a 32-bit mask of all ones except bits 30 and 29. Purpose unknown. (unknown)
pub mod config_b8 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb8;
}
/// Written with the same all-ones-but-bits-30:29 mask as config_b8, immediately after it. Purpose unknown. (unknown)
pub mod config_bc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xbc;
}
/// Descriptor RAM, low 32 bits of the buffer's PCI address of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). E (established)
pub mod desc_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x400;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 12;
}
/// Descriptor RAM, high 32 bits of the buffer's PCI address of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control).  (established)
pub mod desc_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x404;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 12;
}
/// Descriptor RAM, control word, see DESC_WORD of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). Entry n of da (established)
pub mod desc_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x408;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 12;
}
/// Working descriptor of channel type 4 (adat_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor  (established)
pub mod work_adat_in_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4c0;
}
/// Working descriptor of channel type 4 (adat_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux d (established)
pub mod work_adat_in_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4c4;
}
/// Working descriptor of channel type 2 (aes_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor R (established)
pub mod work_aes_in_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4c8;
}
/// Working descriptor of channel type 2 (aes_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux dr (established)
pub mod work_aes_in_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4cc;
}
/// Working descriptor of channel type 0 (analog_in), address low: the descriptor now running. The driver writes the same value to the channel's descripto (established)
pub mod work_analog_in_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4d0;
}
/// Working descriptor of channel type 0 (analog_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux (established)
pub mod work_analog_in_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4d4;
}
/// Working descriptor of channel type 7 (adat_in_sub), address low: the descriptor now running. The driver writes the same value to the channel's descrip (established)
pub mod work_adat_in_sub_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4d8;
}
/// Working descriptor of channel type 7 (adat_in_sub), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Lin (established)
pub mod work_adat_in_sub_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4dc;
}
/// Working descriptor of channel type 6 (aes_in_sub), address low: the descriptor now running. The driver writes the same value to the channel's descript (established)
pub mod work_aes_in_sub_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4e0;
}
/// Working descriptor of channel type 6 (aes_in_sub), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linu (established)
pub mod work_aes_in_sub_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4e4;
}
/// Working descriptor of channel type 5 (adat_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor (established)
pub mod work_adat_out_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4e8;
}
/// Working descriptor of channel type 5 (adat_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux  (established)
pub mod work_adat_out_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4ec;
}
/// Working descriptor of channel type 3 (aes_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor  (established)
pub mod work_aes_out_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4f0;
}
/// Working descriptor of channel type 3 (aes_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux d (established)
pub mod work_aes_out_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4f4;
}
/// Working descriptor of channel type 1 (analog_out), address low: the descriptor now running. The driver writes the same value to the channel's descript (established)
pub mod work_analog_out_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4f8;
}
/// Working descriptor of channel type 1 (analog_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linu (established)
pub mod work_analog_out_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4fc;
}
/// Status ring, base PCI address low. A one-shot transfer uses the same registers with the limit set to 0xfffffffc. (established)
pub mod status_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x500;
}
/// Status ring limit and wrap: the driver writes 0x78 minus slot count times 0x80, and 0xfffffffc for one shot. Field layout undecoded. (established)
pub mod status_limit {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x504;
}
/// Working descriptor of channel type 4 (adat_in), address high. (established)
pub mod work_adat_in_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x508;
}
/// Working descriptor of channel type 2 (aes_in), address high. (established)
pub mod work_aes_in_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50c;
}
/// Working descriptor of channel type 0 (analog_in), address high. (established)
pub mod work_analog_in_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x510;
}
/// Working descriptor of channel type 7 (adat_in_sub), address high. (established)
pub mod work_adat_in_sub_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x514;
}
/// Working descriptor of channel type 6 (aes_in_sub), address high. (established)
pub mod work_aes_in_sub_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x518;
}
/// Working descriptor of channel type 5 (adat_out), address high. (established)
pub mod work_adat_out_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x51c;
}
/// Working descriptor of channel type 3 (aes_out), address high. (established)
pub mod work_aes_out_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x520;
}
/// Working descriptor of channel type 1 (analog_out), address high. (established)
pub mod work_analog_out_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x524;
}
/// Status ring, base PCI address high. (established)
pub mod status_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x528;
}
/// ADAT output subcode buffer A: 15 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doublewor (established)
pub mod adat_out_subcode_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1000;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 8;
}
/// ADAT output subcode buffer B: 15 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doublewor (established)
pub mod adat_out_subcode_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1080;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 8;
}
/// AES3 output subcode buffer A: 16 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doublewor (established)
pub mod aes_out_subcode_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1100;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// AES3 output subcode buffer B: 16 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doublewor (established)
pub mod aes_out_subcode_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1180;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// extra AES3 subcode doublewords of buffer A: 2 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears  (established)
pub mod aes_out_subcode_extra_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1200;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8;
}
/// extra AES3 subcode doublewords of buffer B: 2 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears  (established)
pub mod aes_out_subcode_extra_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1210;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8;
}
/// Control word of a descriptor, in the RAM entry and in the working descriptor of a channel. The driver builds it as ((tag & 0xf) << 3) + (-length_units (inferred)
pub mod desc_word {
    pub const WIDTH: u32 = 32;
    pub mod length_units { // bits 31:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1ffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod next_index { // bits 6:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod end_of_descriptor { // bits 2:2, inferred
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
/// Low byte of PCI config offset 8. The driver reads the dword and splits this byte. (established)
pub mod pci_revision {
    pub const WIDTH: u32 = 8;
    pub mod board_mode { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod chip_rev { // bits 3:0, established
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
/// Slot word at byte offset 0x7c. The driver clears it before a transfer and waits for the engine to set bit 31. (established)
pub mod status_done {
    pub const WIDTH: u32 = 32;
    pub mod done { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod aes_rate_code { // bits 26:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod aes_no_input { // bits 19:19, inferred
        pub const SHIFT: u32 = 19;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Slot word at byte offset 0x78 of each status slot. Bits not listed are never read by the driver. (inferred)
pub mod status_flags {
    pub const WIDTH: u32 = 32;
    pub mod video_event_b { // bits 8:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod video_event_a { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod adat_present { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const BAR0_SIZE: u32 = 0x2000; // inferred
pub const CLOCKGEN_AES_OUT: u32 = 0x2; // established
pub const CLOCKGEN_ANALOG_IN: u32 = 0x0; // established
pub const CLOCKGEN_ANALOG_OUT: u32 = 0x1; // established
pub const CLOCKGEN_COUNT: u32 = 0x4; // inferred
pub const DESC_ENTRIES: u32 = 0x10; // inferred
pub const DESC_ENTRY_BYTES: u32 = 0xc; // established
pub const DESC_STATUS_ENTRY: u32 = 0xf; // inferred
pub const DMA_UNIT_BYTES: u32 = 0x80; // established
pub const GAIN_BIAS: u32 = 0x48; // established
pub const GAIN_BRINGUP: u32 = 0xd6d6d6d6; // established
pub const MODE_MEDIAIO: u32 = 0x7; // established
pub const MODE_OCTANE: u32 = 0xc; // established
pub const MODE_PCI_BOARD: u32 = 0xd; // established
pub const MUX_BITS: u32 = 0x10; // established
pub const MUX_PROBE_PASSES: u32 = 0x400; // inferred
pub const PCI_CLASS_OCTANE: u32 = 0x0; // established
pub const PCI_DEVICE: u32 = 0x5; // established
pub const PCI_VENDOR: u32 = 0x10a9; // established
pub const REV_MEDIAIO: u32 = 0x70; // inferred
pub const REV_OCTANE: u32 = 0xc0; // established
pub const REV_PCI_BOARD: u32 = 0xd0; // inferred
pub const RING_WORDS_ADAT: u32 = 0x1000; // established
pub const RING_WORDS_ANALOG: u32 = 0x400; // established
pub const STATUS_INTERVAL_DRIVER: u32 = 0xfa; // established
pub const STATUS_INTERVAL_UNITS: u32 = 0x21; // inferred
pub const STATUS_SLOTS_MAX: u32 = 0x80; // established
pub const STATUS_SLOT_BYTES: u32 = 0x80; // established
pub const STATUS_SLOT_DONE: u32 = 0x7c; // established
pub const STATUS_SLOT_FLAGS: u32 = 0x78; // established
pub const STATUS_SLOT_MIRROR: u32 = 0x44; // established
pub const STATUS_START_CONT: u32 = 0x40003; // established
pub const STATUS_START_ONESHOT: u32 = 0x40001; // established
pub const STATUS_STOP: u32 = 0x1fffc; // established
pub const UST_MIN_ADVANCE: u32 = 0x3; // established

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn analog_out_ctrl_20000001() {
        assert_eq!(analog_out_ctrl::enable::get(0x20000001), 1);
        assert_eq!(analog_out_ctrl::clock_gen1::get(0x20000001), 1);
        assert_eq!(analog_out_ctrl::clock_gen2::get(0x20000001), 0);
    }

    #[test]
    fn status_ctrl_480ef() {
        assert_eq!(status_ctrl::start::get(0x480ef), 1);
        assert_eq!(status_ctrl::continuous::get(0x480ef), 1);
        assert_eq!(status_ctrl::interval::get(0x480ef), 8251);
        assert_eq!(status_ctrl::go::get(0x480ef), 1);
    }

    #[test]
    fn gain_d6d6d6d6() {
        assert_eq!(gain::in_left::get(0xd6d6d6d6), 214);
        assert_eq!(gain::in_right::get(0xd6d6d6d6), 214);
        assert_eq!(gain::out_left::get(0xd6d6d6d6), 214);
        assert_eq!(gain::out_right::get(0xd6d6d6d6), 214);
    }

    #[test]
    fn central_ctrl_ffe20000() {
        assert_eq!(central_ctrl::adat_rx_enable::get(0xffe20000), 0);
        assert_eq!(central_ctrl::adat_rx_resync::get(0xffe20000), 0);
        assert_eq!(central_ctrl::clockgen_reset::get(0xffe20000), 0);
        assert_eq!(central_ctrl::analog_out_if_reset::get(0xffe20000), 0);
    }

    #[test]
    fn gpio_relay_2() {
        assert_eq!(gpio_relay::bit0::get(0x2), 0);
        assert_eq!(gpio_relay::bit1::get(0x2), 1);
    }

    #[test]
    fn gpio_relay_3() {
        assert_eq!(gpio_relay::bit0::get(0x3), 1);
        assert_eq!(gpio_relay::bit1::get(0x3), 1);
    }

    #[test]
    fn gpio_data_2() {
        assert_eq!(gpio_data::data::get(0x2), 0);
        assert_eq!(gpio_data::const1::get(0x2), 1);
    }

    #[test]
    fn gpio_data_3() {
        assert_eq!(gpio_data::data::get(0x3), 1);
        assert_eq!(gpio_data::const1::get(0x3), 1);
    }

    #[test]
    fn clockgen_load_20000603() {
        assert_eq!(clockgen_load::divisor_minus_1::get(0x20000603), 3);
        assert_eq!(clockgen_load::flags::get(0x20000603), 3);
        assert_eq!(clockgen_load::select::get(0x20000603), 2);
    }

    #[test]
    fn clockgen_frac_34ff6d() {
        assert_eq!(clockgen_frac::remainder::get(0x34ff6d), 52);
        assert_eq!(clockgen_frac::denominator_complement::get(0x34ff6d), 65389);
    }

    #[test]
    fn desc_word_fffff008() {
        assert_eq!(desc_word::end_of_descriptor::get(0xfffff008), 0);
        assert_eq!(desc_word::next_index::get(0xfffff008), 1);
        assert_eq!(desc_word::length_units::get(0xfffff008), 33554400);
    }
}
