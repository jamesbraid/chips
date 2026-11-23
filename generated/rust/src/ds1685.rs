// @generated from devices/ds1685/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 2d03aff8397fa4913c718e61cdbc7f8b15ad4905a2ec4a42ae8709b19c99ca92
// Dallas DS1685/DS1687 real-time clock and battery-backed RAM (Octane and Octane2 system boards)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Bank-0 user RAM, 114 bytes. The driver's write loop covers a 50-byte run from 0Eh and a 64-byte run from 40h, whose sum is 114, so the block runs from (inferred)
pub mod user_ram {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xe;
    pub const COUNT: u32 = 114;
    pub const STRIDE: u64 = 1;
}
/// Model byte, the first of the eight identification bytes; the datasheet gives the value 71h. Probe does not read it, so only the sysfs and proc views s (established)
pub mod model {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x40;
}
/// Six serial-number bytes that follow the model byte. Linux exposes them through sysfs and nothing consulted checks them. (established)
pub mod serial {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x41;
    pub const COUNT: u32 = 6;
    pub const STRIDE: u64 = 1;
}
/// CRC byte over the seven identification bytes before it. The datasheet text gives no polynomial, so this import cannot reproduce the check. No driver c (established)
pub mod serial_crc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x47;
}
/// Century, in the same data-mode form as the other calendar bytes. Linux computes the year as the year byte plus the century times 100. (established)
pub mod century {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x48;
}
/// Date alarm. The wake-up alarm matches this byte together with the hours, minutes and seconds alarm bytes. Linux also writes it as the alarm date. (established)
pub mod date_alarm {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x49;
}
/// Extended control and flag byte. Only the bits named below are positioned here. Its other bits (the wake-up, RAM-clear and valid-battery flags) are rea (inferred)
pub mod ctrl4a {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4a;
    pub mod incr { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pab { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod kickstart_flag { // bits 0:0, inferred
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
/// Extended enable byte, holding the enables for the wake-up, RAM-clear and kickstart interrupts. Linux writes it at probe and remove. Bit positions are  (inferred)
pub mod ctrl4b {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4b;
}
/// Address for the extended RAM, seven bits. The address does not advance on its own, so software writes it before each byte. (inferred)
pub mod ext_ram_address {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x50;
}
/// Extended RAM data at the address in the address register. (inferred)
pub mod ext_ram_data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x53;
}
/// Seconds. Binary or BCD according to the data-mode bit, which this unit does not carry. (inferred)
pub mod seconds {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
}
/// Seconds alarm byte. Linux's alarm paths read and write it with the other alarm bytes; the sources consulted do not describe how the match treats a wil (inferred)
pub mod alarm_seconds {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
}
/// Minutes. Same data-mode rule as seconds. (inferred)
pub mod minutes {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
}
/// Minutes alarm byte. (inferred)
pub mod alarm_minutes {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
}
/// Hours. Linux forces 24-hour mode at probe and converts the stored value first if the chip was in 12-hour mode. (inferred)
pub mod hours {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
}
/// Hours alarm byte. Probe converts it together with the time hours when it finds 12-hour mode. (inferred)
pub mod alarm_hours {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
}
/// Day of the week. Linux reads it on the time path and OpenBSD writes it on the set path; OpenBSD's read path does not read it. (inferred)
pub mod day_of_week {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
}
/// Date of the month. (inferred)
pub mod date {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
}
/// Month. (inferred)
pub mod month {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
}
/// Year within the century. The century comes from the century byte in bank 1. (inferred)
pub mod year {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x9;
}
pub const BANK0_RAM_BYTES: u32 = 0x72; // inferred
pub const EXT_RAM_BYTES: u32 = 0x80; // inferred
pub const RAM_CLEAR_RECOVERY_MS: u32 = 0x96; // established
pub const RAM_TOTAL_BYTES: u32 = 0xf2; // established
