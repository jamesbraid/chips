// generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 35170f49ee8ac12d6c880fa6df715404fff2b2377770e4dfa5c12c473b50a477
// Cobalt (system ASIC of the SGI Visual Workstation 320 and 540): the CPU block and the interrupt controller, as SGI's Linux platform code names them
#![allow(dead_code)]

/// Interrupt redirection entry, low word, one per interrupt line (thirty lines, 0 to 29). The kernel writes the level bit and an interrupt vector to unma (established)
pub mod apic_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 30;
    pub const STRIDE: u64 = 16;
    pub mod bit17 { // bits 17:17, unknown
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mask { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod level { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod remote_irr { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dest_mode { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod delivery_mode { // bits 10:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod vector { // bits 7:0, established
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
/// Interrupt redirection entry, high word. Linux and the NT HAL write zero beside every device entry's low word; the HAL writes the NMI entry's high word (established)
pub mod apic_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
    pub const COUNT: u32 = 30;
    pub const STRIDE: u64 = 16;
    pub mod dest { // bits 31:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Controller identification and enable. The kernel reads it, sets the enable bit with a read-modify-write that it says must not change the identificatio (established)
pub mod apic_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xffc;
    pub mod id { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enable { // bits 8:8, established
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
/// Cobalt revision. The kernel prints it at start-up and, in the 2.4 interrupt path, reads it after a driver has acknowledged its device as a way to make (established)
pub mod cpu_rev {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
}
/// Timer and memory control. Linux sets timer_run and clears timer_mask, each by a read-modify-write, after loading the count, and touches no other bit.  (established)
pub mod cpu_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
    pub mod timer_mask { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod timer_run { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod page_close { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ecc_enable { // bits 0:0, established
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
/// Machine reset on early boards. The NT HAL sets bit 0 to reboot the 320 below board revision 12 and the 540 revision 0 (halborg.dll 1.3, HalpReboot, Bo (established)
pub mod cpu_reset {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
    pub mod reset { // bits 0:0, established
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
/// Timer status. The HAL also stores all ones here once while setting up the timer, after it loads the count and sets the run bit, so an all-ones write i (established)
pub mod cpu_stat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
    pub mod timer_intr { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cacheop_intr { // bits 0:0, established
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
/// Timer count. The kernel writes the Cobalt core rate divided by the tick rate (a 100 MHz core rate) before starting the timer and calls it a countdown  (established)
pub mod cpu_timeval {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
/// Timer current value. The NT HAL's timer calibration reads it after starting the timer with a reload of 0xffffffff and takes the fall as the tick count (established)
pub mod cpu_timecur {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x38;
}
/// Memory controller control. At timer set-up the HAL also stores 0 here and 0 in the error status. The PROM self-test sets bit 0 with a full-word store  (established)
pub mod mem_ecc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
    pub mod ecc_enable { // bits 0:0, established
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
/// Memory error status. The NT HAL's error handler reads it, treats the error as non-fatal when bit 16 is set or when bit 17 is set and the syndrome is z (established)
pub mod mem_err_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
}
/// Memory error address, printed by the HAL as the address of the error. (established)
pub mod mem_err_addr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// Memory error ECC syndrome. A nonzero syndrome with a correctable error sends the HAL to HalpCorrectSoftEccError, which computes a quadword offset from (established)
pub mod mem_err_syndrome {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
pub const APIC_8259: u32 = 0xc; // established
pub const APIC_AS: u32 = 0x18; // established
pub const APIC_CPU: u32 = 0x1c; // established
pub const APIC_IDE0: u32 = 0x4; // inferred
pub const APIC_IDE1: u32 = 0x2; // established
pub const APIC_LINES: u32 = 0x1e; // established
pub const APIC_LI_AUDIO: u32 = 0x16; // inferred
pub const APIC_NMI: u32 = 0x1d; // established
pub const APIC_PCIA_BASE0: u32 = 0x0; // established
pub const APIC_PCIA_BASE123: u32 = 0x5; // established
pub const APIC_PCIB_BASE0: u32 = 0x8; // established
pub const APIC_PCIB_BASE123: u32 = 0xd; // established
pub const APIC_PHYS: u32 = 0xc4000000; // established
pub const APIC_PIIX4_USB: u32 = 0x7; // established
pub const APIC_RE: u32 = 0x19; // established
pub const APIC_VIDIN0: u32 = 0x12; // established
pub const APIC_VIDIN1: u32 = 0x13; // established
pub const APIC_VIDOUT0: u32 = 0x10; // established
pub const APIC_VIDOUT1: u32 = 0x11; // established
pub const CPU_MAX: u32 = 0x4; // inferred
pub const CPU_NUM_PHYS: u32 = 0x1e00; // established
pub const CPU_PHYS: u32 = 0xc2000000; // established
pub const MEM_PHYS: u32 = 0xc6000000; // established
pub const TIME_HZ: u32 = 0x5f5e100; // inferred
