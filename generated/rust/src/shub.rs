// generated from devices/shub/registers.toml by defs-gen - do not edit, change the source
// SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs
#![allow(dead_code)]

/// Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege  (established)
pub mod md_dqlp_dir_privilege_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030300;
}
/// Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names. (established)
pub mod md_dqrp_dir_privilege_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050300;
}
/// Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR windo (established)
pub mod ipi_int {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000380;
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
    pub const OFFSET: u64 = 0x110001480;
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
    pub const OFFSET: u64 = 0x110001500;
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
    pub const OFFSET: u64 = 0x110010000;
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
    pub const OFFSET: u64 = 0x110010008;
}
/// Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross- (established)
pub mod ipi_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060480;
}
/// SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in t (established)
pub mod shub_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060580;
    pub mod nodes_per_bit { // bits 52:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod revision { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel wri (established)
pub mod ptc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101a0000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
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
    pub mod rid { // bits 62:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ps { // bits 7:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3f;
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
/// Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for proce (established)
pub mod int_cmp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101b0080;
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
/// Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because  (established)
pub mod rtc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101c0000;
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
/// Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the k (established)
pub mod pi_cam_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120050300;
}
/// PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O wr (established)
pub mod pio_write_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120070200;
    pub const COUNT: u32 = 2;
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
    pub const OFFSET: u64 = 0x120070208;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
}
/// Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps a 16-bit LED state per processor  (established)
pub mod junk_bus_led {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x7fed00000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
pub const IPI_BASE_VALUE: u32 = 0xfee; // established
pub const PIO_WRITE_STATUS_ALIAS_CLEAR: u32 = 0x7; // established
pub const PIO_WRITE_STATUS_IDLE: u64 = 0x3f00000000000000; // established
pub const PI_CAM_WAR_VALUE: u64 = 0x8000000000000010; // established
pub const RTC_CONFIG_MASK: u64 = 0xff3ffffffefffff; // established
pub const RTC_ENABLE_MASK: u32 = 0x1; // established
pub const RTC_MASK: u64 = 0x7fffffffffffff; // established
pub const SHUB_1_1_MAX_REVISION: u32 = 0x2; // established
