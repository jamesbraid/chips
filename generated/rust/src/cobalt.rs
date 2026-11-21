// generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source
// Cobalt (system ASIC of the SGI Visual Workstation 320 and 540): the CPU block and the interrupt controller, as SGI's Linux platform code names them
#![allow(dead_code)]

/// Interrupt redirection entry, low word, one per interrupt line (thirty lines, 0 to 29). The kernel writes the level bit and an interrupt vector to unma (established)
pub mod apic_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
    pub const COUNT: u32 = 30;
    pub const STRIDE: u64 = 16;
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
    pub mod vector { // bits 7:0, inferred
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
/// Interrupt redirection entry, high word. The kernel writes zero beside every low word it sets and never reads it. By the standard I/O APIC layout it wo (inferred)
pub mod apic_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
    pub const COUNT: u32 = 30;
    pub const STRIDE: u64 = 16;
}
/// Controller identification and enable. The kernel reads it, sets the enable bit with a read-modify-write that it says must not change the identificatio (established)
pub mod apic_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xffc;
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
/// Timer control. The kernel sets timer_run and clears timer_mask, each by a read-modify-write, after loading the count. Other bits are never touched. (established)
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
}
/// Timer status. The 2.2 and 2.4 timer handlers clear the pending bit by reading the register and writing it back with that bit cleared. The 2.5 and late (established)
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
}
/// Timer count. The kernel writes the Cobalt core rate divided by the tick rate (a 100 MHz core rate) before starting the timer and calls it a countdown  (established)
pub mod cpu_timeval {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
}
pub const APIC_8259: u32 = 0xc; // established
pub const APIC_AS: u32 = 0x18; // established
pub const APIC_CPU: u32 = 0x1c; // established
pub const APIC_IDE0: u32 = 0x4; // established
pub const APIC_IDE1: u32 = 0x2; // established
pub const APIC_LINES: u32 = 0x1e; // established
pub const APIC_LI_AUDIO: u32 = 0x16; // established
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
pub const CPU_MAX: u32 = 0x4; // established
pub const CPU_NUM_PHYS: u32 = 0x1e00; // established
pub const CPU_PHYS: u32 = 0xc2000000; // established
pub const TIME_HZ: u32 = 0x5f5e100; // established
