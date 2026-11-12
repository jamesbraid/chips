// generated from defs/ice1724.toml by defs-gen - do not edit, change the source
// VIA/IC Ensemble ICE1724 (Envy24HT) PCI audio controller registers
#![allow(dead_code)]

pub mod enums {
    pub mod ac97_slot {
        pub const SPLIT: u32 = 0; // established
        pub const PACKED: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Split,
            Packed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Split,
                    1 => Self::Packed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Split => 0,
                    Self::Packed => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod adc_inputs {
        pub const ONE_STEREO: u32 = 0; // established
        pub const TWO_STEREO: u32 = 1; // established
        pub const ONE_STEREO_SPDIF: u32 = 2; // established
        pub const NONE: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            OneStereo,
            TwoStereo,
            OneStereoSpdif,
            None,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::OneStereo,
                    1 => Self::TwoStereo,
                    2 => Self::OneStereoSpdif,
                    3 => Self::None,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::OneStereo => 0,
                    Self::TwoStereo => 1,
                    Self::OneStereoSpdif => 2,
                    Self::None => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod converter_type {
        pub const AC97: u32 = 0; // established
        pub const I2S: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Ac97,
            I2s,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Ac97,
                    1 => Self::I2s,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Ac97 => 0,
                    Self::I2s => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod i2c_direction {
        pub const READ: u32 = 0; // established
        pub const WRITE: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Read,
            Write,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Read,
                    1 => Self::Write,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Read => 0,
                    Self::Write => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod i2s_format {
        pub const I2S: u32 = 0; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            I2s,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::I2s,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::I2s => 0,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod interleave {
        pub const ALL_EIGHT: u32 = 0; // established
        pub const FIRST_SIX: u32 = 1; // established
        pub const FIRST_FOUR: u32 = 2; // established
        pub const FIRST_PAIR: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            AllEight,
            FirstSix,
            FirstFour,
            FirstPair,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::AllEight,
                    1 => Self::FirstSix,
                    2 => Self::FirstFour,
                    3 => Self::FirstPair,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::AllEight => 0,
                    Self::FirstSix => 1,
                    Self::FirstFour => 2,
                    Self::FirstPair => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod pm_state {
        pub const D0: u32 = 0; // established
        pub const D1: u32 = 1; // established
        pub const D2: u32 = 2; // established
        pub const D3HOT: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            D0,
            D1,
            D2,
            D3hot,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::D0,
                    1 => Self::D1,
                    2 => Self::D2,
                    3 => Self::D3hot,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::D0 => 0,
                    Self::D1 => 1,
                    Self::D2 => 2,
                    Self::D3hot => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod rate_code {
        pub const K48: u32 = 0; // established
        pub const K24: u32 = 1; // established
        pub const K12: u32 = 2; // established
        pub const K9_6: u32 = 3; // established
        pub const K32: u32 = 4; // established
        pub const K16: u32 = 5; // established
        pub const K8: u32 = 6; // established
        pub const K96: u32 = 7; // established
        pub const K44_1: u32 = 8; // established
        pub const K22_05: u32 = 9; // established
        pub const K11_025: u32 = 10; // established
        pub const K88_2: u32 = 11; // established
        pub const K176_4: u32 = 12; // established
        pub const UNLISTED_13: u32 = 13; // unknown
        pub const K192: u32 = 14; // established
        pub const K64: u32 = 15; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            K48,
            K24,
            K12,
            K96,
            K32,
            K16,
            K8,
            K96,
            K441,
            K2205,
            K11025,
            K882,
            K1764,
            Unlisted13,
            K192,
            K64,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::K48,
                    1 => Self::K24,
                    2 => Self::K12,
                    3 => Self::K96,
                    4 => Self::K32,
                    5 => Self::K16,
                    6 => Self::K8,
                    7 => Self::K96,
                    8 => Self::K441,
                    9 => Self::K2205,
                    10 => Self::K11025,
                    11 => Self::K882,
                    12 => Self::K1764,
                    13 => Self::Unlisted13,
                    14 => Self::K192,
                    15 => Self::K64,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::K48 => 0,
                    Self::K24 => 1,
                    Self::K12 => 2,
                    Self::K96 => 3,
                    Self::K32 => 4,
                    Self::K16 => 5,
                    Self::K8 => 6,
                    Self::K96 => 7,
                    Self::K441 => 8,
                    Self::K2205 => 9,
                    Self::K11025 => 10,
                    Self::K882 => 11,
                    Self::K1764 => 12,
                    Self::Unlisted13 => 13,
                    Self::K192 => 14,
                    Self::K64 => 15,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod resolution_bits {
        pub const BITS16: u32 = 0; // established
        pub const BITS18: u32 = 1; // established
        pub const BITS20: u32 = 2; // established
        pub const BITS24: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Bits16,
            Bits18,
            Bits20,
            Bits24,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Bits16,
                    1 => Self::Bits18,
                    2 => Self::Bits20,
                    3 => Self::Bits24,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Bits16 => 0,
                    Self::Bits18 => 1,
                    Self::Bits20 => 2,
                    Self::Bits24 => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod route_source {
        pub const NORMAL: u32 = 0; // established
        pub const PSDIN0_LEFT: u32 = 2; // established
        pub const PSDIN0_RIGHT: u32 = 3; // established
        pub const SPDIN_LEFT: u32 = 6; // established
        pub const SPDIN_RIGHT: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Normal,
            Psdin0Left,
            Psdin0Right,
            SpdinLeft,
            SpdinRight,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Normal,
                    2 => Self::Psdin0Left,
                    3 => Self::Psdin0Right,
                    6 => Self::SpdinLeft,
                    7 => Self::SpdinRight,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Normal => 0,
                    Self::Psdin0Left => 2,
                    Self::Psdin0Right => 3,
                    Self::SpdinLeft => 6,
                    Self::SpdinRight => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod spdif_rate {
        pub const K44_1: u32 = 0; // established
        pub const RESERVED_1: u32 = 1; // established
        pub const K48: u32 = 2; // established
        pub const K32: u32 = 3; // established
        pub const K88_2: u32 = 4; // established
        pub const K96: u32 = 5; // established
        pub const K192: u32 = 6; // established
        pub const K176_4: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            K441,
            Reserved1,
            K48,
            K32,
            K882,
            K96,
            K192,
            K1764,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::K441,
                    1 => Self::Reserved1,
                    2 => Self::K48,
                    3 => Self::K32,
                    4 => Self::K882,
                    5 => Self::K96,
                    6 => Self::K192,
                    7 => Self::K1764,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::K441 => 0,
                    Self::Reserved1 => 1,
                    Self::K48 => 2,
                    Self::K32 => 3,
                    Self::K882 => 4,
                    Self::K96 => 5,
                    Self::K192 => 6,
                    Self::K1764 => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod xin1_clock {
        pub const CLK24_576: u32 = 0; // established
        pub const CLK49_152: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Clk24576,
            Clk49152,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Clk24576,
                    1 => Self::Clk49152,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Clk24576 => 0,
                    Self::Clk49152 => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Bit 7 is a soft reset of the whole chip. The public driver writes 1, waits, then writes 0; the datasheet does not say whether the bit self-clears. Bit (established)
pub mod ccs_control {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod soft_reset { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt mask. A set bit masks the source. The datasheet states this polarity only for MT03; here it is inferred from the reset value and the driver' (established)
pub mod ccs_irq_mask {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod mpu_receive { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mpu_transmit { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod multichannel { // bits 4:4, established
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
/// Bits 7 and 5 are write-1-to-clear. Bit 4 is read only and clears when its source in the multi-channel register clears. Bits are sticky. (established)
pub mod ccs_irq_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod mpu_receive { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mpu_transmit { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod multichannel { // bits 4:4, established
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
/// The public driver copies EEPROM bytes 6 to 9 here; the datasheet says the driver loads them, and hardware does not. The reset value means 24.576 MHz,  (established)
pub mod ccs_system_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
    pub mod xin1_clock { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::xin1_clock::Value;
    }
    pub mod mpu_uart { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod adc_inputs { // bits 3:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::adc_inputs::Value;
    }
    pub mod dac_count_minus_one { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Converter type and AC'97 slot layout. Bit 7 reflects the power-up strap on GPIO 0 in reverse and may be overwritten. (established)
pub mod ccs_ac97_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
    pub mod converter_type { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::converter_type::Value;
    }
    pub mod ac97_slot { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ac97_slot::Value;
    }
}
/// Converter capabilities, written from the EEPROM. (established)
pub mod ccs_i2s_features {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
    pub mod volume_by_gpio { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod supports_96k { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod resolution { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::resolution_bits::Value;
    }
    pub mod supports_192k { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod other_ids { // bits 2:0, unknown
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// S/PDIF transmitter enable and capability bits. Bit 6 is read only and reflects the SPDTX pin during reset, reversed: 0 means the transmitter is on the (established)
pub mod ccs_spdif_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
    pub mod transmitter_enable { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod transmitter_present { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spdif_ids { // bits 5:2, unknown
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spdif_input { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod external_output { // bits 0:0, established
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
/// Valid bytes in the MPU-401 transmit FIFO, which is 32 deep. (established)
pub mod ccs_uart_tx_count {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xa;
    pub mod count { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Valid bytes in the MPU-401 receive FIFO, which is 32 deep. (established)
pub mod ccs_uart_rx_count {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb;
    pub mod count { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// MPU-401 data port. (established)
pub mod ccs_midi_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xc;
}
/// MPU-401 command and status. The datasheet gives no bit definitions. The public Linux driver's reading (bit 0 UART mode, bits 1 to 4 FIFO empty and ful (unknown)
pub mod ccs_midi_command {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd;
}
/// MPU-401 watermark. Both watermarks reset to 0. (established)
pub mod ccs_uart_setting {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xe;
    pub mod rx_mark_select { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod watermark { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Writing this register starts an I2C transfer, so the busy bit must be clear first. Device address 1010000 is reserved for the configuration EEPROM. (established)
pub mod ccs_i2c_device {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x10;
    pub mod device { // bits 7:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod direction { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::i2c_direction::Value;
    }
}
/// I2C byte address. (established)
pub mod ccs_i2c_byte {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x11;
}
/// I2C data byte, written before a write transfer and read after a read transfer. (established)
pub mod ccs_i2c_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x12;
}
/// Bit 7 mirrors the EEPROM strap on GPIO 3 at reset, so a board with an EEPROM reads 80. The printed reset 00 conflicts with that text; the text is take (established)
pub mod ccs_i2c_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x13;
    pub mod eeprom_present { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod busy { // bits 0:0, established
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
/// GPIO data, bits 15 to 0. A bit takes a write only while its write-mask bit is 0. Bits 22 to 16 are in ccs_gpio_data_hi. (established)
pub mod ccs_gpio_data {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x14;
}
/// GPIO write mask, bits 15 to 0. Reset masks every bit, so no GPIO data can be written until software clears mask bits. Bits 22 to 16 are in ccs_gpio_ma (established)
pub mod ccs_gpio_mask {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x16;
}
/// GPIO direction in three bytes, 0x18 to 0x1A. Bits 22 to 0 are defined: 0 is input, 1 is output. Bit 3 doubles as the EEPROM strap at reset; bit 2 is f (established)
pub mod ccs_gpio_direction {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
    pub mod direction { // bits 22:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7fffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Each bit set stops or powers down the named clock. Bits 6 and 1 are reserved. The ALSA driver writes 0 here, which is an expectation. (established)
pub mod ccs_power_down {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1c;
    pub mod xin1_clock { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xin2_clock { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod i2c_clock { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod midi_clock { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spdif_clock { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod serial_clock { // bits 0:0, established
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
/// GPIO data, bits 22 to 16 in bits 6 to 0. Masked by ccs_gpio_mask_hi. (established)
pub mod ccs_gpio_data_hi {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1e;
    pub mod data { // bits 6:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// GPIO write mask, bits 22 to 16 in bits 6 to 0. (established)
pub mod ccs_gpio_mask_hi {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1f;
    pub mod mask { // bits 6:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// One bit per source; write 1 to clear. The multi-channel source bit in the controller's status register is inferred to be the OR of the unmasked bits h (established)
pub mod mt_irq_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod spdif_out { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma3 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma2 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma1 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fifo_error { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rdma1 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rdma0 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma0 { // bits 0:0, established
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
/// Sample rate. When bit 4 is 1 the rate code is ignored and the S/PDIF input clock is the master, with the master clock on the SPMCLKIN pin. (established)
pub mod mt_sampling_rate {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod spdif_input_master { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rate_code { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::rate_code::Value;
    }
}
/// Clock ratio and data format. Bit 3 selects a 128x master clock; 176.4 kHz forces it. Bit 2 is listed read-write with no description. (established)
pub mod mt_i2s_format {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod mclk_128x { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit2 { // bits 2:2, unknown
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod format { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::i2s_format::Value;
    }
}
/// Source mask, same bit layout as mt_irq_status. A set bit masks the source. Every source is masked at reset. (established)
pub mod mt_irq_mask {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
    pub mod spdif_out { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma3 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma2 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma1 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fifo_error { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rdma1 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rdma0 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma0 { // bits 0:0, established
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
/// AC'97 register index. Valid only in AC-link mode, though the drivers also use the converter reset bit in I2S mode. (established)
pub mod mt_ac97_index {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
    pub mod index { // bits 6:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// AC'97 command and status. The datasheet limits this register to AC-link mode. In I2S mode bit 7 is inferred to reset the converters, from the sibling  (established)
pub mod mt_ac97_command {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
    pub mod cold_reset { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_cycle { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod read_cycle { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod codec_ready { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod codec_select { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// AC'97 data port. (established)
pub mod mt_ac97_data {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
}
/// Start of the interleaved playback buffer. Bits 1 and 0 read 0, so the address is dword aligned. The datasheet says the field is in dword units; the dr (established)
pub mod mt_pdmai_address {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
    pub mod address { // bits 31:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3fffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Buffer size in dwords less one, counting down as data moves. Reloads at zero, so the buffer wraps. Bits 18 to 0 are used. (established)
pub mod mt_pdmai_count {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14;
    pub mod count { // bits 18:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Read-modify-write only. A 1 starts the stream and a 0 stops it. Bit 3 is read only, 0. Bit positions are the same as mt_irq_status. (established)
pub mod mt_dma_start {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x18;
    pub mod pdma4 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma3 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma2 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma1 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rdma1 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rdma0 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pdma0 { // bits 0:0, established
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
/// Interleaved channel count; see enum interleave. Sets which of PDMA1 to PDMA3 are free. (established)
pub mod mt_pdmai_streams {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x19;
    pub mod interleave { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::interleave::Value;
    }
}
/// Underrun on playback or overrun on record, per stream. Bit positions are the same as mt_dma_start. Write 1 to clear; any flag raises the interrupt thr (established)
pub mod mt_dma_underrun {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1a;
}
/// Pause and resume, per stream; bit positions are the same as mt_dma_start. A 1 pauses and a 0 resumes. (established)
pub mod mt_dma_pause {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1b;
}
/// Interrupt interval in dwords less one. Counts down; at zero it raises the stream's source. Write only. The index line says 1C to 1D, but the layout co (established)
pub mod mt_pdmai_terminal {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
    pub mod count { // bits 18:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7ffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Start of the first record buffer. Dword aligned, same encoding as mt_pdmai_address. (established)
pub mod mt_rdma0_address {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
    pub mod address { // bits 31:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3fffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Buffer size in dwords less one, counting down. Read the position only after at least two sample frames have passed. (established)
pub mod mt_rdma0_count {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x24;
}
/// Interrupt interval in dwords less one. Write only. (established)
pub mod mt_rdma0_terminal {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x26;
}
/// Source of each output channel, in I2S mode only, adding at most one sample time of delay. The layout is established; the zero reset is inferred from t (inferred)
pub mod mt_routing {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2c;
    pub mod psdout3_right { // bits 31:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod psdout2_right { // bits 28:26, established
        pub const SHIFT: u32 = 26;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod psdout1_right { // bits 25:23, established
        pub const SHIFT: u32 = 23;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod psdout0_right { // bits 22:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod psdout3_left { // bits 19:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod psdout2_left { // bits 16:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod psdout1_left { // bits 13:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod psdout0_left { // bits 10:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod spdif_right { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
    pub mod spdif_left { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::route_source::Value;
    }
}
/// Start of the second record buffer. Dword aligned, same encoding as mt_pdmai_address. (established)
pub mod mt_rdma1_address {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
    pub mod address { // bits 31:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3fffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Buffer size in dwords less one, counting down. (established)
pub mod mt_rdma1_count {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x34;
}
/// Interrupt interval in dwords less one. Write only. (established)
pub mod mt_rdma1_terminal {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x36;
}
/// S/PDIF transmitter channel status. Reads 0000 when the SPDTX pin is floating or high, and 2000 at power-up when the transmitter is fitted. Every field (established)
pub mod mt_spdif_control {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x3c;
    pub mod validity { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod spdif_rate { // bits 14:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::spdif_rate::Value;
    }
    pub mod generation_level { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod category { // bits 10:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pre_emphasis { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod copyright { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod non_audio { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod professional { // bits 0:0, established
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
/// Stream to meter. 0 to 7 are the eight interleaved slots, 8 and 9 the S/PDIF left and right, 10 and 11 RDMA0, 18 and 19 RDMA1. Other values are ignored (established)
pub mod mt_peak_index {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3e;
    pub mod index { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Peak level of the selected stream, the nine most significant bits of the level. Reading clears the peak. (established)
pub mod mt_peak_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3f;
    pub mod peak { // bits 7:0, established
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
/// Start of the playback buffer for the S/PDIF stream and the three extra stereo pairs. Element 0 is PDMA4 (S/PDIF), 1 is PDMA3, 2 is PDMA2, 3 is PDMA1.  (established)
pub mod mt_pdma_address {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
    pub mod address { // bits 31:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3fffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Buffer size in dwords less one, counting down. Element order as mt_pdma_address. (established)
pub mod mt_pdma_count {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x44;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// Interrupt interval in dwords less one. Write only. Element order as mt_pdma_address. (established)
pub mod mt_pdma_terminal {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x46;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// PCI vendor ID, IC Ensemble. (established)
pub mod pci_vendor_id {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x0;
}
/// PCI device ID. The same ID is used by the VT1720 (Envy24PT), so it does not tell the parts apart. (established)
pub mod pci_device_id {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
}
/// Bit 1 (memory space) and bits 3 to 7 and 9 are hardwired to 0. The datasheet lists bit 8 as read-write but describes it as hardwired to 0; it reads 0  (established)
pub mod pci_command {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
    pub mod bus_master { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod io_space { // bits 0:0, established
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
/// Bits 15 to 12 are write-1-to-clear. Bit 11 is hardwired to 0. Bit 14 reads 0. Bit 4 (capability list) is hardwired to 1. (established)
pub mod pci_status {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
    pub mod parity_error { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod master_abort { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod target_abort { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod devsel_timing { // bits 10:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod capability_list { // bits 4:4, established
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
/// Vendor revision. The datasheet shows it as a placeholder; the value is not given. (established)
pub mod pci_revision {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
}
/// Class code: multimedia, audio. The field is 24 bits in the header; the programming interface byte at offset 0x09 reads 0. (established)
pub mod pci_class {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xa;
    pub mod base_class { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod subclass { // bits 7:0, established
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
/// Not supported; reads 0. (established)
pub mod pci_cache_line {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xc;
}
/// Writes take effect in eight-clock steps: writing FF reads back F8. (established)
pub mod pci_latency_timer {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd;
    pub mod count { // bits 7:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Type 0, single function. (established)
pub mod pci_header_type {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xe;
}
/// Built-in self test is not supported. (established)
pub mod pci_bist {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf;
}
/// Controller registers (CCS), 32 bytes of I/O space. Bits 31 to 5 are the base. (established)
pub mod pci_bar0 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
    pub mod base { // bits 31:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x7ffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Multi-channel registers (MT), 128 bytes of I/O space. Bits 31 to 7 are the base. (established)
pub mod pci_bar1 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14;
    pub mod base { // bits 31:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1ffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Subsystem IDs. Loaded from the EEPROM after reset when one answers, otherwise the reset value. Writable only while the subsystem mask bit is set. Whic (established)
pub mod pci_subsystem {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2c;
    pub mod subsystem_device { // bits 31:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod subsystem_vendor { // bits 15:0, established
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
/// Reserved; the part has no option ROM. (established)
pub mod pci_expansion_rom {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
/// Points to the power-management capability at 0x80. (established)
pub mod pci_capability_ptr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x34;
}
/// Set by firmware. FF means the interrupt is not routed. (established)
pub mod pci_interrupt_line {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3c;
}
/// INTA#. (established)
pub mod pci_interrupt_pin {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3d;
}
/// Minimum grant in the low byte, maximum latency in the high byte. Both 0. (established)
pub mod pci_grant_latency {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x3e;
    pub mod max_latency { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod min_grant { // bits 7:0, established
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
/// The table places the subsystem ID mask at 0x40 and the register section at 0x42. Bit 7 is the control that makes the subsystem IDs writable. The offse (inferred)
pub mod pci_svid_mask {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x42;
    pub mod writable { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Capability ID: power management. (established)
pub mod pci_pm_capability_id {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x80;
}
/// End of the capability list. (established)
pub mod pci_pm_next {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x81;
}
/// Power management version 1.0. D2 is supported, D1 and PME are not. (established)
pub mod pci_pm_caps {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x82;
}
/// Power state select. (established)
pub mod pci_pm_control {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x84;
    pub mod power_state { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::pm_state::Value;
    }
}
/// Power management bridge extension and data. Read only, reset 0. (established)
pub mod pci_pm_data {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x86;
}
pub const CCS_AC97_CONF: u32 = 0x5; // established
pub const CCS_GPIO_DATA: u32 = 0x14; // established
pub const CCS_GPIO_DATA_HI: u32 = 0x1e; // established
pub const CCS_GPIO_DIR: u32 = 0x18; // established
pub const CCS_GPIO_MASK: u32 = 0x16; // established
pub const CCS_GPIO_MASK_HI: u32 = 0x1f; // established
pub const CCS_I2C_BYTE_ADDR: u32 = 0x11; // established
pub const CCS_I2C_CTRL: u32 = 0x13; // established
pub const CCS_I2C_DATA: u32 = 0x12; // established
pub const CCS_I2C_DEV_ADDR: u32 = 0x10; // established
pub const CCS_I2S_FEATURES: u32 = 0x6; // established
pub const CCS_IRQ_MASK: u32 = 0x1; // inferred
pub const CCS_IRQ_STATUS: u32 = 0x2; // inferred
pub const CCS_SPDIF_CONF: u32 = 0x7; // established
pub const CCS_SYSCONF: u32 = 0x4; // established
pub const MT_BURST: u32 = 0x19; // established
pub const MT_CAPTURE_ADDR: u32 = 0x20; // established
pub const MT_CAPTURE_SIZE: u32 = 0x24; // established
pub const MT_CONVERTER_RESET: u32 = 0x5; // established
pub const MT_DMA_CONTROL: u32 = 0x18; // established
pub const MT_DMA_INT_MASK: u32 = 0x3; // inferred
pub const MT_IRQ_STATUS: u32 = 0x0; // inferred
pub const MT_MCLK_128X: u32 = 0x2; // established
pub const MT_PLAYBACK_ADDR: u32 = 0x10; // established
pub const MT_PLAYBACK_SIZE: u32 = 0x14; // established
pub const MT_RATE: u32 = 0x1; // established
pub const MT_SPDIF_OUT_ADDR: u32 = 0x40; // established
pub const MT_SPDIF_OUT_SIZE: u32 = 0x44; // established
