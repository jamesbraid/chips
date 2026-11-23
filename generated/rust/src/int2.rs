// @generated from devices/int2/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 29645b43ee4985139264014550a8e1993073007c6bdd414538f5005486db0086
// INT2 local interrupt controller and 8254 timer block (Indigo, R3000 and R4000 boards)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Raw state of the eight local 0 sources, one bit each, high while the source asserts. It appears not to be gated by the mask (inferred): the PROM clear (established)
pub mod local0_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
}
/// Enables local 0 sources toward the CPU. A one bit lets the source raise the local 0 output. All eight bits read back what was written: the PROM writes (established)
pub mod local0_mask {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
}
/// Raw state of the eight local 1 sources. Same rules as local 0 status. With all masks clear the PROM expects bits 0, 2, 3 and 4 to read zero and tolera (established)
pub mod local1_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb;
}
/// Enables local 1 sources toward the CPU. All eight bits read back. (established)
pub mod local1_mask {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf;
}
/// VME interrupt request levels 1 to 7 in bits 1 to 7 (inferred from the header names; no shipped R4000 Indigo code reads it for VME). Bit 0 is read by t (established)
pub mod vme_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x13;
}
/// Which VME levels may raise local 0 bit 7. The IRIX routine that targets an I/O interrupt at the CPU sets bit n in this register. The PROM never reads  (established)
pub mod vme0_mask {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x17;
}
/// Which VME levels may raise local 1 bit 3. The PROM writes 0x5a and checks the read-back, so all eight bits hold. (established)
pub mod vme1_mask {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1b;
}
/// Five-bit read/write port at the offset NetBSD calls the map polarity register on the Indy generation. The header calls it the LED and serial-port conf (established)
pub mod port_config {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1f;
    pub mod power { // bits 4:4, unknown
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod vr_interrupt_latch { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ser1_rts { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ser0_rts { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod parity_or_ext_clock { // bits 0:0, unknown
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
/// Write-only strobe. Writing 1 clears the timer 0 interrupt latch, 2 clears timer 1. IRIX acknowledges timer 0 with 1 and timer 1 with 2; the PROM write (established)
pub mod timer_ack {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x23;
    pub mod timer1 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod timer0 { // bits 0:0, established
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
/// No R4000 Indigo kernel object or the PROM touches this offset. NetBSD defines it for the Indy generation, where Linux calls it reserved on INT2. Nothi (unknown)
pub mod error_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x27;
}
/// 8254 counter 0 data, one byte at a time per the control word. Its output is the timer 0 interrupt (CPU IP4). IRIX loads it with 50 after control word  (established)
pub mod timer0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x33;
}
/// 8254 counter 1 data. Its output is the timer 1 interrupt (CPU IP5), the profiling and fast clock. IRIX loads it with 5000 divided by the wanted rate,  (established)
pub mod timer1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x37;
}
/// 8254 counter 2 data. Its output clocks counters 0 and 1 (NetBSD's interrupt driver states this and programs it that way on the R3000 Indigo; IRIX's co (established)
pub mod timer2 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3b;
}
/// 8254 control word. The R4000 Indigo kernel and the PROM only write it. Standard 8254 layout; the values seen are 0x34, 0x74 and 0xb4 (counter 0, 1, 2  (established)
pub mod timer_control {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3f;
    pub mod counter { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rw { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 3:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bcd { // bits 0:0, established
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
pub const ACK_TIMER0: u32 = 0x1; // established
pub const ACK_TIMER1: u32 = 0x2; // established
pub const LOCAL0_CENTR: u32 = 0x2; // established
pub const LOCAL0_DUART: u32 = 0x20; // established
pub const LOCAL0_ENET: u32 = 0x8; // established
pub const LOCAL0_FIFO: u32 = 0x1; // established
pub const LOCAL0_GDMA: u32 = 0x10; // established
pub const LOCAL0_GIO1: u32 = 0x40; // established
pub const LOCAL0_SCSI: u32 = 0x4; // established
pub const LOCAL0_VME0: u32 = 0x80; // established
pub const LOCAL1_ACFAIL: u32 = 0x20; // established
pub const LOCAL1_DSP: u32 = 0x10; // established
pub const LOCAL1_GIO2: u32 = 0x80; // established
pub const LOCAL1_GR1MODE: u32 = 0x2; // established
pub const LOCAL1_VIDEO: u32 = 0x40; // established
pub const LOCAL1_VME1: u32 = 0x8; // established
pub const TIMER_MASTER_HZ: u32 = 0xf4240; // inferred
