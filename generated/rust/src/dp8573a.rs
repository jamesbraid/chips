// @generated from devices/dp8573a/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 3d5cf3c64ca396076a616c64c2650a09e803487e15909b32eb1f6fd64cc9c1d7
// National DP8573A real-time clock and battery-backed RAM (Indigo, R3000 and R4000 boards)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Always present, whichever block is selected. Bit 0 is the interrupt status, high while the chip's interrupt output is asserted (read only). Bit 1 is t (established)
pub mod status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
    pub mod ram7 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod register_select { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ram5 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ram4 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod alarm { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod periodic { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod power_fail { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod interrupt_status { // bits 0:0, established
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
/// Hundredths and tenths of a second, two BCD digits, 00 to 99, incrementing every 10 ms while the clock runs. The PROM's first read of the clock after r (established)
pub mod hundredths {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x17;
}
/// Seconds, BCD 00 to 59. Written by IRIX and the PROM only with the clock stopped. (established)
pub mod seconds {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1b;
}
/// Minutes, BCD 00 to 59. (established)
pub mod minutes {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1f;
}
/// Hours, BCD. In 24-hour mode (real time mode bit 2 clear, which is how IRIX and the PROM run the chip) the range is 00 to 23 and bits 5:4 are the tens  (established)
pub mod hours {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x23;
}
/// Day of month, BCD 01 to 28/29/30/31. Rolls over to 01. (established)
pub mod day_of_month {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x27;
}
/// Month, BCD 01 to 12. Rolls over to 01. (established)
pub mod month {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2b;
}
/// Year, BCD 00 to 99. IRIX and the PROM store years since 1970 here, not a century year. The PROM accepts a clock whose year plus 1970 is below 2070. (established)
pub mod year {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2f;
}
/// A general RAM byte. Not touched by any shipped Indigo code. (established)
pub mod ram_0c {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x33;
}
/// The data sheet's address table shows only bits 0 and 1 present and gives no function, and the page text does not describe them. No shipped Indigo code (unknown)
pub mod reg_0d {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x37;
}
/// Day of week counter, 1 to 7, rolls over to 1. The chip does not derive it from the date; software sets it. IRIX never writes it (its time computation  (established)
pub mod day_of_week {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3b;
}
/// Seconds compare RAM. Compared with the seconds counter only when interrupt control 1 bit 0 is set; otherwise a free RAM byte. (established)
pub mod cmp_seconds {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4f;
}
/// Minutes compare RAM, same rules as the seconds one with interrupt control 1 bit 1. (established)
pub mod cmp_minutes {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x53;
}
/// Hours compare RAM, a free RAM byte while interrupt control 1 bit 2 is clear. IRIX keeps its bad-clock flag in bit 0 of this byte (set when the kernel  (established)
pub mod cmp_hours {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x57;
}
/// Day-of-month compare RAM. The PROM's RAM test writes 5a here and restores it. (established)
pub mod cmp_day_of_month {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5b;
}
/// Month compare RAM. (established)
pub mod cmp_month {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5f;
}
/// Day-of-week compare RAM. (established)
pub mod cmp_day_of_week {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x63;
}
/// Time save RAM, seconds. While time save control bit 7 is set this byte follows the seconds counter; clearing that bit freezes it, which is how softwar (established)
pub mod save_seconds {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x67;
}
/// Time save RAM, minutes. (established)
pub mod save_minutes {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6b;
}
/// Time save RAM, hours. (established)
pub mod save_hours {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6f;
}
/// Time save RAM, day of month. (established)
pub mod save_day_of_month {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x73;
}
/// Time save RAM, month. There is no year in time save RAM; software reads the year counter directly after the latch. (established)
pub mod save_month {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x77;
}
/// A general RAM byte. Not touched by any shipped Indigo code. (established)
pub mod ram_1e {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7b;
}
/// A general RAM byte that doubles as the chip's test-mode register while the test-enable bit of the periodic flag register is set. The data sheet says t (established)
pub mod ram_test {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7f;
}
/// Block 0. Bits 0 to 5 are the six periodic event flags: minutes, tens of seconds, seconds, 100 ms, 10 ms and 1 ms rollovers. They are set whether or no (established)
pub mod periodic_flag {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf;
    pub mod test_enable { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod osc_fail_or_single_supply { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ms { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ten_ms { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hundred_ms { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod second { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ten_second { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod minute { // bits 0:0, established
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
/// Block 0. Bit 7 is the time save enable: while set the time save RAM follows the clock, and a write that clears it freezes the clock's value there. Bit (established)
pub mod timesave_ctl {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x13;
    pub mod enable { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod absent { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ram { // bits 5:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Block 1. Bits 1:0 are the leap-year counter: years since the last leap year, 0 meaning this year is one. Bit 2 selects 12-hour (set) or 24-hour (clear (established)
pub mod rt_mode {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
    pub mod ram { // bits 7:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod int_standby { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod run { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hour12 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod leap { // bits 1:0, established
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
/// Block 1. Bit 7 chooses what the MFO pin carries: the power-fail interrupt (clear) or the buffered crystal oscillator (set). Bits 6:0 are general RAM.  (established)
pub mod output_mode {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb;
    pub mod mfo_oscillator { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ram { // bits 6:0, established
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
/// Block 1. Bits 0 to 5 enable the six periodic interrupts (minutes, tens of seconds, seconds, 100 ms, 10 ms, 1 ms), which raise main status bit 2 and th (established)
pub mod int0_ctl {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf;
    pub mod ram { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ms { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ten_ms { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hundred_ms { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod second { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ten_second { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod minute { // bits 0:0, established
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
/// Block 1. Bits 0 to 5 enable the compare of seconds, minutes, hours, day of month, month and day of week against the matching compare RAM byte: a clear (established)
pub mod int1_ctl {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x13;
    pub mod power_fail_int_enable { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod alarm_int_enable { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmp_day_of_week { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmp_month { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmp_day_of_month { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmp_hours { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmp_minutes { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmp_seconds { // bits 0:0, established
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
pub const BAD_CLOCK_FLAG: u32 = 0x1; // established
pub const EPOCH_YEAR: u32 = 0x7b2; // established
pub const INT1_INIT: u32 = 0x80; // established
pub const LANE_OFFSET: u32 = 0x3; // established
pub const RAM_TEST_A: u32 = 0xa5; // established
pub const RAM_TEST_B: u32 = 0x5a; // established
pub const RT_RS: u32 = 0x40; // established
pub const RT_RUN: u32 = 0x18; // established
pub const RT_TIMSAV_ON: u32 = 0x80; // established
pub const WINDOW_SIZE: u32 = 0x80; // established
