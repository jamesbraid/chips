// @generated from devices/hpc1/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 375a6b58c47ddb4d00925fe95a4934440c1d9ae9bbfb1ed95ad1a0fa3c2cbb9d
// SGI HPC1 peripheral controller (Indigo, R3000 and R4000 boards)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub mod enums {
    pub mod scsi_direction {
        pub const TO_DEVICE: u32 = 0; // established
        pub const TO_MEMORY: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            ToDevice,
            ToMemory,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::ToDevice,
                    1 => Self::ToMemory,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::ToDevice => 0,
                    Self::ToMemory => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// The word at the window base. Software probes it with a guarded read to find out whether a controller is present at the slot; what the word holds is no (inferred)
pub mod enet_probe {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
}
/// Transmit count register. The driver's register dump prints it and nothing writes it; its meaning is not settled. (unknown)
pub mod enet_xcount {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
}
/// Current transmit buffer pointer, by the dump label. Read by the register dump only; no driver writes it. (unknown)
pub mod enet_cxbp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc;
}
/// Next transmit buffer descriptor pointer: the physical address of the descriptor the transmit channel fetches next. Software writes the head of the que (established)
pub mod enet_nxbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// Transmit byte count of the descriptor in progress. Named by the dump and by the public driver; no driver reads it in a decision. (inferred)
pub mod enet_xbc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14;
}
/// Transmit FIFO pointer, by the dump label. Only dumped. (unknown)
pub mod enet_xpntr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
}
/// Transmit FIFO data port, by the dump label. Only dumped. (unknown)
pub mod enet_xfifo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
}
/// Current transmit buffer descriptor pointer. Both drivers load it with the same address they put in the next-descriptor pointer when they start or rest (established)
pub mod enet_cxbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
}
/// Current first transmit buffer descriptor pointer: the first descriptor of the frame being sent. Written with the queue head at a restart. (established)
pub mod enet_cpfxbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x24;
}
/// Previous first transmit buffer descriptor pointer. Named by the dump and the public header; neither driver writes it. (inferred)
pub mod enet_ppfxbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// Receive interrupt delay count. Bit 24 set (0x01000000) disables the delay; the IRIX driver writes that value at initialisation and writes its tunable  (established)
pub mod enet_intdelay {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2c;
}
/// Transmit status and channel start. Bit 22 starts the transmit channel when written one and reads one while the channel is running. The bits above it c (established)
pub mod enet_trstat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
    pub mod seeq_tx_status_high { // bits 23:23, inferred
        pub const SHIFT: u32 = 23;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tx_active { // bits 22:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod seeq_tx_status_low { // bits 21:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Receive status and channel start. Bit 14 starts the receive channel when written one and reads one while it runs; the other bits of the upper byte car (established)
pub mod enet_rcvstat {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x38;
    pub mod seeq_rx_status_high { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rx_active { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod seeq_rx_status_low { // bits 13:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Ethernet channel control: reset, interrupt clear and loopback. Reading bit 1 reports a pending interrupt. (established)
pub mod enet_ctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x3c;
    pub mod clear_overflow { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod normal_mode { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clear_int { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
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
/// Receive count register, by the dump label. Only dumped. (unknown)
pub mod enet_rcount {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x44;
}
/// Receive byte count of the descriptor in progress. (inferred)
pub mod enet_rbc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
}
/// Current receive buffer pointer, by the dump label. (inferred)
pub mod enet_crbp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4c;
}
/// Next receive buffer descriptor pointer: physical address of the first descriptor the receive channel fetches. Software writes the head of the ring her (established)
pub mod enet_nrbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50;
}
/// Current receive buffer descriptor pointer. The IRIX driver loads it with the ring head at start and its watchdog reads it to see whether the channel h (established)
pub mod enet_crbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x54;
}
/// Receive FIFO pointer, by the dump label. The PROM's early test stores the byte 0x5a to its low byte lane and reads the register after it, without a re (unknown)
pub mod enet_rpntr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x58;
}
/// Receive FIFO data port, by the dump label. (unknown)
pub mod enet_rfifo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x5c;
}
/// SCSI channel byte count of the descriptor being moved. The channel loads it from the descriptor; software does not write it in normal operation. (established)
pub mod scsi_bc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
}
/// SCSI channel current buffer pointer: the physical address of the data being moved, loaded from a descriptor. (established)
pub mod scsi_cbp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8c;
}
/// SCSI next descriptor pointer. Software writes the physical address of the first descriptor, then the control register with the start bit; the channel  (established)
pub mod scsi_nbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
}
/// SCSI channel control. The reset bit holds the WD33C93 chip in reset while set. The flush bit drains the channel FIFO and the start bit reads one while (established)
pub mod scsi_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x94;
    pub mod start { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod direction { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::scsi_direction::Value;
    }
    pub mod flush { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
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
/// SCSI FIFO pointer register. Present in both headers and in the chip interface table; no driver read or write of it was found. (inferred)
pub mod scsi_pntr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x98;
}
/// SCSI FIFO data port. No driver access was found. (inferred)
pub mod scsi_fifo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x9c;
}
/// Parallel port byte count with the strobe timing fields. The header gives three seven-bit timing fields at bits 30:24, 22:16 and 14:8; the driver store (established)
pub mod par_bc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa8;
    pub mod strobe_min { // bits 30:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod strobe_lead { // bits 22:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod strobe_trail { // bits 14:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Parallel current buffer pointer. The PROM's power-on test writes a walking one from bit 27 down to bit 0 and reads each value back, so the low 28 bits (established)
pub mod par_cbp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xac;
}
/// Parallel next descriptor pointer: the physical address of the first descriptor, written before the control register. (established)
pub mod par_nbdp {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb0;
}
/// Parallel port control. (established)
pub mod par_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb4;
    pub mod start { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flush { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ignore_ack { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod to_memory { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod soft_ack { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod polarity { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod interrupt { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
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
/// Parallel FIFO status. Bits 22:16 hold the number of bytes still in the port FIFO; the stop routine drains that many bytes by hand when the count is un (inferred)
pub mod par_fifo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb8;
}
/// Parallel DMA configuration, named by the public header only. No IRIX object touches it. (unknown)
pub mod par_dmacfg {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xbc;
}
/// DMA byte order of each channel and the controller revision. A set bit makes that channel's DMA words and descriptors little-endian; clear leaves them  (established)
pub mod endian {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc0;
    pub mod revision { // bits 7:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dsp_little { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod par_little { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod scsi_little { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod enet_little { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cpu_little { // bits 0:0, established
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
/// The Ethernet chip's eight registers, one per 32-bit slot with the byte in bits 7:0; register n is at 0x100 plus 4n. Registers 0 to 5 hold the station  (established)
pub mod seeq {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 4;
}
/// The WD33C93's address/auxiliary-status port. The chip sits on the 15:8 byte lane of the word: a big-endian byte access is at +2 and a little-endian on (established)
pub mod wd33c93_address {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x120;
    pub mod data { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// The WD33C93's data port, on the same byte lane. (established)
pub mod wd33c93_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x124;
    pub mod data { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Parallel port external status and remote register, one byte in bits 23:16 of the word. A DMA read start stores 1 and a write start stores 3; the reset (established)
pub mod par_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x134;
}
/// DSP DMA transfer length in SRAM words. See devices/hollywood-dsp. (inferred)
pub mod dsp_dma_count {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x180;
}
/// Low 16 bits of the memory-side DMA address. (inferred)
pub mod dsp_gio_low {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x184;
}
/// High 16 bits of the memory-side DMA address. (inferred)
pub mod dsp_gio_high {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x188;
}
/// 16-bit peripheral-bus (DSP SRAM) address of the DMA. (inferred)
pub mod dsp_pbus_addr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18c;
}
/// DSP DMA control. (inferred)
pub mod dsp_dma_ctrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x190;
    pub mod folded { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod direction { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod go { // bits 0:0, inferred
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
/// A free-running 24-bit counter; what it counts is not stated. (unknown)
pub mod dsp_counter {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x194;
}
/// Handshake transmit word, written by the DSP for the host. (inferred)
pub mod dsp_hand_tx {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x198;
}
/// Handshake receive word, written by the host for the DSP. (inferred)
pub mod dsp_hand_rx {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x19c;
}
/// DSP-to-CPU interrupt status: bit 0 end of DMA, bit 1 the DSP wrote the transmit word, bit 2 the DSP read the receive word. (inferred)
pub mod dsp_int_status {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1a0;
}
/// Enable bits for the three DSP interrupt sources. (inferred)
pub mod dsp_int_mask {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1a4;
}
/// DSP miscellaneous control. The PROM stores 9 (reset with 32K SRAM) at start-up, 1 (reset) while it loads the DSP and 8 (run, 32K SRAM) afterwards. (inferred)
pub mod dsp_misc {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1b0;
    pub mod pbus_extend { // bits 6:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sram_32k { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irqa_high { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irqa { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
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
/// DMA burst length and spacing; the fields are not stated. (inferred)
pub mod dsp_burst {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1b4;
}
/// The auxiliary byte: the console LED and the four wires of the serial EEPROM. Bit 0 is shared by the LED and the EEPROM protect-register enable. (established)
pub mod aux {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1bc;
    pub mod eeprom_do { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod eeprom_di { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod eeprom_sk { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod eeprom_cs { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod led_pre { // bits 0:0, established
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
/// The interrupt controller window, 64 bytes at 0x1c0. The registers are in the interrupt controller's own unit; the controller is not part of the HPC1. (established)
pub mod int2_window {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c0;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 4;
}
/// Four 16-byte blocks of 8-bit registers at 0xd00, 0xd10, 0xd20, 0xd30, each register in its own slot with the byte in bits 7:0 (offset +3 big-endian).  (established)
pub mod serial_window {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xd00;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 4;
}
/// The battery-backed real-time clock window, one 8-bit register per 32-bit slot, accessed by word at the slot. The chip's registers are in its own unit. (established)
pub mod clock_window {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xe00;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 4;
}
/// Board revision word, in the modem SRAM space. The kernel inverts the word and takes bits 14:12; bit 15 is the header's marker for the HP1 base board. (established)
pub mod board_rev {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50000;
    pub mod hp1_marker { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod revision_inverted { // bits 14:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// The DSP SRAM, one 24-bit word per 32-bit slot, 128 KB. (established)
pub mod dsp_sram {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x60000;
    pub const COUNT: u32 = 32768;
    pub const STRIDE: u64 = 4;
}
/// Word 0 of the Ethernet DMA descriptor: flags and byte count. The HPC3 puts the buffer address first and the flags second; the HPC1 order is the revers (established)
pub mod enet_desc_w0 {
    pub const WIDTH: u32 = 32;
    pub mod eop { // bits 31:31, inferred
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod own { // bits 30:30, inferred
        pub const SHIFT: u32 = 30;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod intr { // bits 15:15, inferred
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod byte_count { // bits 12:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word 1 of the Ethernet DMA descriptor: the buffer address with the end-of-chain flag. (established)
pub mod enet_desc_w1 {
    pub const WIDTH: u32 = 32;
    pub mod eochain { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod buffer { // bits 27:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word 2 of the Ethernet DMA descriptor. (established)
pub mod enet_desc_w2 {
    pub const WIDTH: u32 = 32;
    pub mod next { // bits 27:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word 0 of the SCSI and parallel DMA descriptor. A descriptor is three hardware words in a 16-byte slot; the fourth word is software-only. The words ar (established)
pub mod scsi_desc_w0 {
    pub const WIDTH: u32 = 32;
    pub mod byte_count { // bits 12:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word 1 of the SCSI and parallel DMA descriptor. (established)
pub mod scsi_desc_w1 {
    pub const WIDTH: u32 = 32;
    pub mod eox { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod buffer { // bits 27:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word 2 of the SCSI and parallel DMA descriptor. (established)
pub mod scsi_desc_w2 {
    pub const WIDTH: u32 = 32;
    pub mod next { // bits 27:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const EEPROM_OP_PROTECT_CLEAR: u32 = 0xffff; // established
pub const EEPROM_OP_READ: u32 = 0xc000; // established
pub const EEPROM_OP_WRITE: u32 = 0xa000; // established
pub const EEPROM_OP_WRITE_ALL: u32 = 0x8800; // inferred
pub const EEPROM_OP_WRITE_DISABLE: u32 = 0x8000; // established
pub const EEPROM_OP_WRITE_ENABLE: u32 = 0x9800; // established
pub const NVRAM_ENET_OFFSET: u32 = 0xfa; // established
pub const NVRAM_REVISION: u32 = 0x6; // established
pub const NVRAM_SIZE: u32 = 0x100; // established
pub const SCSI_START_DMA: u32 = 0x80; // established
pub const SCSI_START_DMA_TO_MEM: u32 = 0x90; // established
