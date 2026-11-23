// generated from devices/lithium/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 70596ec24940e8315b4fb0fe9a073a0422cfac082fac58aa7aa316aae98f2930
// Lithium (I/O ASIC of the SGI Visual Workstation 320 and 540): the PCI bridge window and the audio engine, as SGI's Linux platform code names them
#![allow(dead_code)]

/// Audio link controller. The driver resets the codec link by writing reset, waiting a microsecond, then writing link_enable alone, and never reads the r (established)
pub mod host_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
    pub mod reset { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_enable { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod prom_bit8 { // bits 8:8, unknown
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_failure { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_codec { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_ready { // bits 0:0, inferred
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
/// Audio interrupt status. The driver clears pending bits by writing ones to the bits it wants cleared, and writes all ones to clear everything, so the b (inferred)
pub mod intr_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
    pub mod link_err { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod comm2_trig { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod comm2_underflow { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod comm1_trig { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod comm1_overflow { // bits 0:0, inferred
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
/// Audio interrupt enable mask, same bit layout as the status. The driver sets bits by read-modify-write and clears them the same way. (inferred)
pub mod intr_mask {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14;
}
/// Codec register access. A write starts a codec register read or write; the driver waits until busy clears (about two ticks at most) before and after. F (established)
pub mod codec_command {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
    pub mod busy { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dir { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr { // bits 6:0, established
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
/// Codec register data, 16 bits used by the driver. (established)
pub mod codec_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
}
/// Input DMA ring buffer base: the 40-bit physical address shifted right 8, with bit 29 set. The driver says bit 37 of the address (bit 29 here) must be  (established)
pub mod comm1_base {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100;
}
/// Input DMA control and pointers. The two low bytes are the write and read pointers in 32-byte chunks; for the input channel the hardware advances the w (inferred)
pub mod comm1_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x104;
    pub mod reset { // bits 31:31, inferred
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod size { // bits 30:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dma_enable { // bits 27:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tmask { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tptr { // bits 23:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rptr { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wptr { // bits 7:0, established
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
/// Input DMA configuration. (inferred)
pub mod comm1_cfg {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x108;
    pub mod lock { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod slot { // bits 6:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod direction { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 2:2, established
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
    }
}
/// Output DMA ring buffer base, same encoding as comm1_base. (established)
pub mod comm2_base {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10c;
}
/// Output DMA control and pointers, same layout as comm1_ctl. For output the hardware advances the read pointer and software the write pointer. (inferred)
pub mod comm2_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x110;
}
/// Output DMA configuration, same layout as comm1_cfg. (inferred)
pub mod comm2_cfg {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x114;
}
/// Low word of a 64-bit counter Linux calls unadjusted system time, microseconds since boot (the unit is Linux's comment; the time driver scales the valu (established)
pub mod ust_low {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x200;
}
/// High word of the same counter. The NT audio, time and video drivers all read it before and after the other words and retry if it changed; the time dri (established)
pub mod ust_high {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x204;
}
/// Time stamp of the input channel's last sample counter update. The NT driver pairs it with ust_high (read first, re-read afterwards, retried until equa (established)
pub mod audio1_ust {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x300;
}
/// Input media stream counter: samples processed as of audio1_ust. The NT driver writes zero to it when it starts input with no pending counter pair, so  (established)
pub mod audio1_msc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x304;
}
/// Time stamp for the output channel, read the same way as audio1_ust. (established)
pub mod audio2_ust {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x308;
}
/// Output media stream counter. The NT driver writes zero to it when it starts output with no pending counter pair, so it is writable. (established)
pub mod audio2_msc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30c;
}
/// A word on the second audio page, offset from physical 0xff00f000. The NT audio driver stores the silence sample here before it starts DMA, in both dir (inferred)
pub mod silence_word {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x500;
}
/// Two words on the third audio page, offset from physical 0xff010000 (0x98 and 0x9c). Linux's comment calls them undocumented internal copies of the DMA (inferred)
pub mod dma_pointer_copy {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x98;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4;
}
/// Command word of the standard header. The NT HAL stores all ones here once when it sets up a bridge whose revision byte is above zero; nothing reads it (inferred)
pub mod bridge_cmd {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
}
/// Status word of the standard header. The HAL stores a value with bits 15:11 set here at bridge set-up and the master-abort bit (bit 13) after each conf (inferred)
pub mod bridge_status {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
}
/// Revision byte. The HAL tests it above zero to choose where the bus number goes; the PROM tests bridge B's byte against zero and maps zero to Lithium g (established)
pub mod bridge_rev {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
}
/// When the revision byte is zero the top byte holds the bus number: the HAL clears bits 31:24 and ORs in the bus number shifted up 24, as a 32-bit read- (inferred)
pub mod bridge_40 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
}
/// Bus numbers behind the bridge. Linux reads it as a 16-bit value from each bridge's window and keeps the low byte as that bridge's PCI bus number, then (inferred)
pub mod bus_number {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x44;
    pub mod subordinate { // bits 15:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod primary { // bits 7:0, inferred
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
/// Interrupt enables, one bit per PCI interrupt source of the bridge. Linux writes it once at start-up, to every device bit on both bridges (the 2.2 kern (established)
pub mod int_enable {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x46;
    pub mod intd { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod intc { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod intb { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod inta_4 { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod inta_3 { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod inta_2 { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod inta_1 { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod inta_0 { // bits 0:0, inferred
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
/// Error status. The PROM stores all ones here in both bridges at the start of its bridge set-up and nothing in the NT HAL or the PROM reads it, so the P (inferred)
pub mod err_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
}
/// Bridge control, meaning unknown. All accesses are 32-bit and all by the PROM: the boot block ORs the low five bits into it in both bridges before the  (inferred)
pub mod bridge_58 {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x58;
}
/// Thirty-two words, one per PCI device number on the bridge's bus (inferred from the PROM's device scan, which indexes them by device number). The PROM  (inferred)
pub mod dma_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x60;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 4;
}
/// Configuration address for a type 1 cycle on the bridge's own bus and the buses behind it: bit 31 set, bus in 23:16, device in 15:11, function in 10:8, (established)
pub mod cfg_addr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xf8;
}
/// Configuration data. Accessed as a byte, halfword or word; the lane is picked by the low address bits (the boot block stores a byte at this offset plus (established)
pub mod cfg_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xfc;
}
/// Word at physical 0xff01c004, in a one-page Lithium-side block that no driver touches. The PROM reads it (no HAL or driver read was found) and compares (inferred)
pub mod build_stamp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
}
pub const AUDIO_DMA_CHANNELS: u32 = 0x7; // inferred
pub const AUDIO_PAGE1: u32 = 0xff00f000; // established
pub const AUDIO_PAGE2: u32 = 0xff010000; // established
pub const AUDIO_PHYS: u32 = 0xff001000; // established
pub const BRIDGE_A_PCI_MEM_PHYS: u32 = 0xf0000000; // established
pub const BRIDGE_B_PCI_MEM_PHYS: u32 = 0xf4000000; // established
pub const DEVICE_ID: u32 = 0x1002; // inferred
pub const DMA_CHUNK: u32 = 0x20; // inferred
pub const PCI_A_PHYS: u32 = 0xfc000000; // established
pub const PCI_B_PHYS: u32 = 0xfd000000; // established
pub const PCI_MEM_BUS_BASE: u32 = 0x80000000; // established
pub const PCI_MEM_SIZE: u32 = 0x4000000; // established
pub const STAMP_PHYS: u32 = 0xff01c000; // established
pub const TABLE_WINDOW_PHYS: u32 = 0xff018000; // established
pub const VENDOR_ID: u32 = 0x10a9; // inferred
