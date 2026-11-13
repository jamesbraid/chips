// generated from devices/lucent_ohci/registers.toml by defs-gen - do not edit, change the source
// AT&T/Lucent 11C1:5802 two-port OHCI USB host controller (Origin 300 IO-8), the register and identity facts the held sources establish
#![allow(dead_code)]

/// Interrupt enable word. The IO-8 board test requires it to read zero after a host-controller reset issued through the command register, and it prints a (established)
pub mod hc_interrupt_enable {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// Frame interval word. The frame interval and its toggle take the OpenHCI reset values (see FRAME_INTERVAL_RESET). The largest data packet field's reset (established)
pub mod hc_fm_interval {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
    pub mod frame_interval_toggle { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fs_largest_data_packet { // bits 30:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x7fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod frame_interval { // bits 13:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Frame number word. The specification makes it read-only to the driver, written only by the controller, with reset zero. The IO-8 board test writes 0xf (established)
pub mod hc_fm_number {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x3c;
    pub mod frame_number { // bits 15:0, established
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
/// Root hub descriptor A. The specification makes the power-switching and over-current fields and the power-on-to-power-good time driver-written, so the  (established)
pub mod hc_rh_descriptor_a {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
    pub mod power_on_to_power_good_time { // bits 31:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod no_over_current_protection { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod over_current_protection_mode { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod no_power_switching { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod power_switching_mode { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Root hub descriptor B. The specification gives the device-removable and port-power-control fields as driver written, one bit per port starting at bit  (established)
pub mod hc_rh_descriptor_b {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4c;
    pub mod port_power_control_mask { // bits 31:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod device_removable { // bits 15:0, established
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
pub const FM_NUMBER_WRITE_MASK: u32 = 0xffff; // inferred
pub const FRAME_INTERVAL_RESET: u32 = 0x2edf; // established
pub const HCLSTHRESHOLD_RESET: u32 = 0x628; // established
pub const MAX_LAT: u32 = 0x56; // established
pub const MIN_GNT: u32 = 0x3; // established
pub const PCI_DEVICE_ID: u32 = 0x5802; // established
pub const PCI_VENDOR_ID: u32 = 0x11c1; // established
pub const SUBSYSTEM_ID: u32 = 0x5802; // established
pub const SUBSYSTEM_VENDOR_ID: u32 = 0x11c1; // established
