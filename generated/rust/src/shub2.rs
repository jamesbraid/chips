// generated from devices/shub/registers.shub2.toml by defs-gen - do not edit, change the source
// SHub 2 registers outside the I/O interface, differences from SHub 1
#![allow(dead_code)]

/// Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR windo (established)
pub mod ipi_int {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10000380;
    pub mod send { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod idx { // bits 59:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
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
/// Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and  (established)
pub mod rtc_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10001480;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 256;
    pub mod idx { // bits 59:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
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
/// Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes (established)
pub mod rtc_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10001500;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 256;
    pub mod enable { // bits 0:0, established
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
/// Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the  (established)
pub mod event_occurred {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10010000;
    pub mod ii_int1 { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ii_int0 { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ipi_int { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc3_int { // bits 26:26, established
        pub const SHIFT: u32 = 26;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc2_int { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc1_int { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart_int { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferre (established)
pub mod event_occurred_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10010008;
}
/// Which processors may send interprocessor interrupts to this one: four registers, one per processor slice (SH2_IPI_ACCESS0 to 3). Defined by the header (established)
pub mod ipi_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10060c00;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for proce (established)
pub mod int_cmp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x101b0080;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 128;
    pub mod compare { // bits 54:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// PIO write status, four instances (SHub 2 nodes carry up to four processor slices). Note the kernel indexes them out of order: slices 0, 1, 2, 3 use in (established)
pub mod pio_write_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20070200;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
    pub mod pending_write_count { // bits 61:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_deadlock { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it wa (inferred)
pub mod pio_write_status_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20070208;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Block transfer engine control and status, one per engine, SHub 2 (four engines, SH2_BT_ENG_CSR_0 to 3). Unlike SHub 1 the kernel starts a transfer wit (established)
pub mod bt_eng_csr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
    pub mod error_code { // bits 41:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod notify { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod zero_fill { // bits 24:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod busy { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod error { // bits 16:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod length { // bits 15:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// BTE source address, per engine. The kernel converts the physical address to the network address form first (nasid moved to bit 40 upward, the bank-sel (established)
pub mod bt_eng_src {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040080;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// BTE destination address, per engine; same conversion as the source. (established)
pub mod bt_eng_dest {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040100;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// BTE notification address, per engine; same conversion. (established)
pub mod bt_eng_notify {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30040180;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps a 16-bit LED state per processor  (established)
pub mod junk_bus_led {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xf0000000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
/// Purge translation cache message, SHub 2 (header SH2_PTC). One 64-bit store per target node replaces SHub 1's two. The region id and region number do n (established)
pub mod ptc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x170000000;
    pub mod start { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod address { // bits 60:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1ffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ps { // bits 3:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod type_bit { // bits 0:0, inferred
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
/// Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because  (established)
pub mod rtc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2101c0000;
    pub mod counter { // bits 54:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const EVENT_OCCURRED_EXTIO_INT2: u64 = 0x200000000; // established
pub const EVENT_OCCURRED_EXTIO_INT3: u64 = 0x400000000; // established
pub const IPI_BASE_VALUE: u32 = 0xfee; // established
pub const PIO_WRITE_STATUS_ALIAS_CLEAR: u32 = 0x7; // established
pub const PIO_WRITE_STATUS_IDLE: u32 = 0x0; // established
pub const PI_CAM_WAR_VALUE: u64 = 0x8000000000000010; // established
pub const RTC_CONFIG_MASK: u64 = 0xff3ffffffefffff; // established
pub const RTC_ENABLE_MASK: u32 = 0x1; // established
pub const RTC_MASK: u64 = 0x7fffffffffffff; // established
pub const SHUB_1_1_MAX_REVISION: u32 = 0x2; // established
