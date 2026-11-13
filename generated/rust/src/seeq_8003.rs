// generated from devices/seeq_8003/registers.toml by defs-gen - do not edit, change the source
// SEEQ 8003 and 80C03 Ethernet data link controller (Indy)
#![allow(dead_code)]

pub mod enums {
    pub mod bank_select {
        pub const BANK0: u32 = 0; // inferred
        pub const BANK1: u32 = 1; // inferred
        pub const BANK2: u32 = 2; // inferred
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Bank0,
            Bank1,
            Bank2,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Bank0,
                    1 => Self::Bank1,
                    2 => Self::Bank2,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Bank0 => 0,
                    Self::Bank1 => 1,
                    Self::Bank2 => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod receive_match {
        pub const RECEIVER_OFF: u32 = 0; // established
        pub const ALL_FRAMES: u32 = 1; // established
        pub const STATION_AND_BROADCAST: u32 = 2; // established
        pub const STATION_BROADCAST_AND_MULTICAST: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            ReceiverOff,
            AllFrames,
            StationAndBroadcast,
            StationBroadcastAndMulticast,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::ReceiverOff,
                    1 => Self::AllFrames,
                    2 => Self::StationAndBroadcast,
                    3 => Self::StationBroadcastAndMulticast,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::ReceiverOff => 0,
                    Self::AllFrames => 1,
                    Self::StationAndBroadcast => 2,
                    Self::StationBroadcastAndMulticast => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Station address bytes 0 to 5, one per register. Byte 0 bit 0 is the first bit on the wire. The data sheet's reset list does not name the station addre (established)
pub mod station_address {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 6;
    pub const STRIDE: u64 = 1;
}
/// Multicast hash bytes 0 to 5, written with bank 1 selected. Used with the multicast hash filter enable in the control register. (inferred)
pub mod multicast_hash_low {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 6;
    pub const STRIDE: u64 = 1;
}
/// Multicast hash bytes 6 and 7, written at bank 2 registers 0 and 1. (inferred)
pub mod multicast_hash_high {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 1;
}
/// Inter-packet gap byte. HPC3 writes each transmit descriptor's gap here when its write-control bit is set. The sources read it as the gap, but the enco (inferred)
pub mod inter_packet_gap {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
}
/// Counter, flag and filter control. Writing a zero and then a one to a counter or flag enable clears the counter or flag. The sources do not give the re (inferred)
pub mod control {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
    pub mod no_carrier_flag_enable { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod receive_short_frames { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod multicast_hash_enable { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sqe_flag_enable { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod total_collision_count_enable { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tx_collision_count_enable { // bits 0:0, inferred
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
/// 80C03 configuration: auto-pad, no preamble, do not receive own frames, no CRC, AutoDUPLEX, CRC to FIFO and fast discard, as NetBSD's header names them (inferred)
pub mod configuration {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
}
/// Receive command. Reset clears it. Bits 5 to 0 enable interrupts for each receive condition. Bit 0 also makes overflow frames frames of interest. Bits  (established)
pub mod rx_command {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
    pub mod match_mode { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::receive_match::Value;
    }
    pub mod int_good_frame { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_end_of_frame { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_short_frame { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_dribble_error { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_crc_error { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_overflow { // bits 0:0, established
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
/// Transmit command. Reset clears it. Bits 3 to 0 enable interrupts for each transmit condition. Bits 6 and 5 select the register bank for writes to regi (established)
pub mod tx_command {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
    pub mod bank { // bits 6:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::bank_select::Value;
    }
    pub mod int_success { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_sixteen_collisions { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_collision { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_underflow { // bits 0:0, established
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
/// Transmit collision counter, low byte. With bits 2 to 0 of register 1 it forms an 11-bit count. Reading it after reset with no frames sent gives zero,  (inferred)
pub mod tx_collisions_low {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Transmit collision counter, high bits. Only bits 2 to 0 are described; the other bits are unknown. (inferred)
pub mod tx_collisions_high {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod count_bits_10_8 { // bits 2:0, inferred
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
/// Total collision counter, low byte. The sources do not give the counter's full width. (inferred)
pub mod total_collisions_low {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
}
/// Total collision counter, high bits. The width and bit layout are not stated: unknown. (inferred)
pub mod total_collisions_high {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
}
/// Test register. The sources say do not use it. (inferred)
pub mod test_read {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
}
/// Collision-test and carrier flags. (inferred)
pub mod sqe_and_carrier {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
    pub mod no_carrier_flag { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sqe_flag { // bits 0:0, inferred
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
/// Receive status for the frame of interest. Reading it clears the receive interrupt. Bit 7 is old/new. Old/new is set on a read or on reset, and cleared (established)
pub mod rx_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
    pub mod old_new { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod good_frame { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod end_of_frame { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod short_frame { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dribble_error { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod crc_error { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overflow { // bits 0:0, established
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
/// Transmit status. Reading it clears the transmit interrupt. Bit 7 is old/new: set on each read and on reset, and cleared when new status is loaded at t (established)
pub mod tx_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
    pub mod old_new { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod success { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sixteen_collisions { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod collision { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod underflow { // bits 0:0, established
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
pub const SERVICE_INTERVAL_NS: u32 = 0x320; // established
