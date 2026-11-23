// generated from devices/piix4/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 4095ecd03f27c316c0e277b1e0601b278c04db4d80a6d3f1f614b65056469c03
// Intel 82371AB PIIX4 (PCI-to-ISA bridge, IDE, USB, power management and SMBus) as wired in the Visual Workstation 320 and 540
#![allow(dead_code)]

/// Bus-master IDE command, primary channel; the secondary channel's is at +8 (bm_cmd_sec). (established)
pub mod bm_cmd {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod rw { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod start { // bits 0:0, established
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
/// Bus-master IDE status, primary channel; secondary channel's copy is at offset 0x0a. (established)
pub mod bm_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod dma1_cap { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dma0_cap { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irq { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod error { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod active { // bits 0:0, established
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
/// Descriptor table pointer, primary channel; secondary channel's copy is at offset 0x0c. (established)
pub mod bm_prd {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
}
/// Bus-master IDE command, secondary channel. (established)
pub mod bm_cmd_sec {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
    pub mod rw { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod start { // bits 0:0, established
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
/// Bus-master IDE status, secondary channel. (established)
pub mod bm_status_sec {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xa;
    pub mod dma1_cap { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dma0_cap { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irq { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod error { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod active { // bits 0:0, established
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
/// Descriptor table pointer, secondary channel. (established)
pub mod bm_prd_sec {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc;
}
/// Vendor identification, Intel. (established)
pub mod f0_vid {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x0;
}
/// Device identification of function 0. The firmware's self-test reads the function 0 vendor and device words as one dword and expects 0x71108086. (established)
pub mod f0_did {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
}
/// PCI command. The firmware writes 0x0f once. Bits 2 to 0 are hardwired to 1 and the bits the datasheet marks not implemented read 0, so the write leave (established)
pub mod f0_pcicmd {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
    pub mod serre { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sce { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bus_master { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod memory { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod io_space { // bits 0:0, established
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
/// PCI status. Bits 14 to 11 are write-1-to-clear; DEVSEL# timing is medium (01). (established)
pub mod f0_pcists {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
    pub mod sig_serr { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod master_abort { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rcv_target_abort { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sig_target_abort { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod devsel { // bits 10:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fast_b2b { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Revision. Stepping 00h initially; the specification update lists later values. Which stepping the board carries is not known. (established)
pub mod f0_rid {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
}
/// Class code, programming interface byte, 0x00. The PROM's register walk reads this dword once and discards the result. (established)
pub mod f0_classc_pi {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x9;
}
/// Class code, sub-class byte: 0x01 (PCI-to-ISA bridge) while GENCFG bit 1 selects subtractive decode, 0x80 (other bridge) when it selects positive decod (established)
pub mod f0_classc_scc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xa;
}
/// Class code, base class byte, 0x06 (bridge). (established)
pub mod f0_classc_basec {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb;
}
/// Header type, 0x80: a multifunction device. Functions 1 to 3 read their own header type as 0. (established)
pub mod f0_hedt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xe;
}
/// ISA I/O recovery timer. Reset enables 8-bit and 16-bit recovery with one SYSCLK added to the 3.5 SYSCLK minimum. Not written by any held software. (established)
pub mod f0_iort {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4c;
    pub mod dmaac { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rec8_en { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rec8 { // bits 5:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rec16_en { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rec16 { // bits 1:0, established
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
/// X-bus chip select. The PROM writes the byte 0xf4: that sets the extended BIOS, lower BIOS, BIOSCS# write enable, coprocessor error and mouse functions (established)
pub mod f0_xbcs {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4e;
    pub mod mc_loc { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bios_1meg { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod apic_cs { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ext_bios { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lower_bios { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod coproc_err { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mouse { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod port61_alias { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bioscs_wp { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod kbccs_en { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtccs_en { // bits 0:0, established
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
/// PIRQ[A:D]# route control, one byte each at 0x60 to 0x63. The PROM writes 0x09 to the first (route PIRQA# to IRQ9). The routed IRQ must be level sensit (established)
pub mod f0_pirqrc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 1;
    pub mod route_off { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irq { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const IRQ3: u32 = 3; // established
        pub const IRQ4: u32 = 4; // established
        pub const IRQ5: u32 = 5; // established
        pub const IRQ6: u32 = 6; // established
        pub const IRQ7: u32 = 7; // established
        pub const IRQ9: u32 = 9; // established
        pub const IRQ10: u32 = 10; // established
        pub const IRQ11: u32 = 11; // established
        pub const IRQ12: u32 = 12; // established
        pub const IRQ14: u32 = 14; // established
        pub const IRQ15: u32 = 15; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Irq3,
            Irq4,
            Irq5,
            Irq6,
            Irq7,
            Irq9,
            Irq10,
            Irq11,
            Irq12,
            Irq14,
            Irq15,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    3 => Self::Irq3,
                    4 => Self::Irq4,
                    5 => Self::Irq5,
                    6 => Self::Irq6,
                    7 => Self::Irq7,
                    9 => Self::Irq9,
                    10 => Self::Irq10,
                    11 => Self::Irq11,
                    12 => Self::Irq12,
                    14 => Self::Irq14,
                    15 => Self::Irq15,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Irq3 => 3,
                    Self::Irq4 => 4,
                    Self::Irq5 => 5,
                    Self::Irq6 => 6,
                    Self::Irq7 => 7,
                    Self::Irq9 => 9,
                    Self::Irq10 => 10,
                    Self::Irq11 => 11,
                    Self::Irq12 => 12,
                    Self::Irq14 => 14,
                    Self::Irq15 => 15,
                    Self::Other(v) => v,
                }
            }
        }
    }
}
/// Serial IRQ control. Not written by the PROM; GENCFG bit 16 must also select SERIRQ for it to take effect. (established)
pub mod f0_serirqc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x64;
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
    pub mod continuous { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod frame_size { // bits 5:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod start_width { // bits 1:0, established
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
/// Top of memory and ISA/DMA forwarding. The PROM writes 0xf2: top of memory 16 MB and the 512-640 KB region forwarded to PCI. (established)
pub mod f0_tom {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x69;
    pub mod top { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lower_bios_fwd { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod a0000_en { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod low512_fwd { // bits 1:1, established
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
/// Miscellaneous status. (established)
pub mod f0_mstat {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6a;
    pub mod serr_dtt { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod host_retry { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Motherboard device DMA control, 0x76 and 0x77. The PROM writes 0x0c to both, which is the disabled channel (100) with the bit the datasheet says reads (established)
pub mod f0_mbdma {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x76;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 1;
    pub mod fast { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod one { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod chnl { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// APIC base address relocation (the I/O APIC window follows the Intel 0xfec0 base). Not written by held software. (established)
pub mod f0_apicbase {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x80;
}
/// Deterministic latency control: delayed transaction, passive release and SERR# generation enables. Not written by held software. (established)
pub mod f0_dlc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x82;
    pub mod serr_en { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod usb_pr { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod passive_release { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod delayed_txn { // bits 0:0, established
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
/// PCI DMA configuration: the DMA type of each channel. Channel 4 is the cascade and has no field. The PROM bit-walks the byte at 0x90 and the one at 0x9 (established)
pub mod f0_pdmacfg {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x90;
    pub mod ch7 { // bits 15:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const NORMAL_ISA: u32 = 0; // established
        pub const PC_PCI: u32 = 1; // established
        pub const DISTRIBUTED: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            NormalIsa,
            PcPci,
            Distributed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::NormalIsa,
                    1 => Self::PcPci,
                    2 => Self::Distributed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::NormalIsa => 0,
                    Self::PcPci => 1,
                    Self::Distributed => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ch6 { // bits 13:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const NORMAL_ISA: u32 = 0; // established
        pub const PC_PCI: u32 = 1; // established
        pub const DISTRIBUTED: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            NormalIsa,
            PcPci,
            Distributed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::NormalIsa,
                    1 => Self::PcPci,
                    2 => Self::Distributed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::NormalIsa => 0,
                    Self::PcPci => 1,
                    Self::Distributed => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ch5 { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const NORMAL_ISA: u32 = 0; // established
        pub const PC_PCI: u32 = 1; // established
        pub const DISTRIBUTED: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            NormalIsa,
            PcPci,
            Distributed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::NormalIsa,
                    1 => Self::PcPci,
                    2 => Self::Distributed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::NormalIsa => 0,
                    Self::PcPci => 1,
                    Self::Distributed => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ch3 { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const NORMAL_ISA: u32 = 0; // established
        pub const PC_PCI: u32 = 1; // established
        pub const DISTRIBUTED: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            NormalIsa,
            PcPci,
            Distributed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::NormalIsa,
                    1 => Self::PcPci,
                    2 => Self::Distributed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::NormalIsa => 0,
                    Self::PcPci => 1,
                    Self::Distributed => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ch2 { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const NORMAL_ISA: u32 = 0; // established
        pub const PC_PCI: u32 = 1; // established
        pub const DISTRIBUTED: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            NormalIsa,
            PcPci,
            Distributed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::NormalIsa,
                    1 => Self::PcPci,
                    2 => Self::Distributed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::NormalIsa => 0,
                    Self::PcPci => 1,
                    Self::Distributed => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ch1 { // bits 3:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const NORMAL_ISA: u32 = 0; // established
        pub const PC_PCI: u32 = 1; // established
        pub const DISTRIBUTED: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            NormalIsa,
            PcPci,
            Distributed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::NormalIsa,
                    1 => Self::PcPci,
                    2 => Self::Distributed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::NormalIsa => 0,
                    Self::PcPci => 1,
                    Self::Distributed => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ch0 { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const NORMAL_ISA: u32 = 0; // established
        pub const PC_PCI: u32 = 1; // established
        pub const DISTRIBUTED: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            NormalIsa,
            PcPci,
            Distributed,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::NormalIsa,
                    1 => Self::PcPci,
                    2 => Self::Distributed,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::NormalIsa => 0,
                    Self::PcPci => 1,
                    Self::Distributed => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
}
/// Distributed DMA slave base pointers: 0x92 for channels 0 to 3, 0x94 for channels 5 to 7; bits 15:6 are I/O address bits. The PROM bit-walks bytes 0x93 (established)
pub mod f0_ddmabp {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x92;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 2;
    pub mod base { // bits 15:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// General configuration: pin function selects and bus mode. The PROM writes the bytes 0x4d (register 0xb0) and 0x60 (register 0xb3). 0x4d sets bit 0 (IS (established)
pub mod f0_gencfg {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xb0;
    pub mod kbccs_gpo26 { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtcale_gpo25 { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtccs_gpo24 { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xoe_gpo { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ri_gpi12 { // bits 27:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lid_gpi10 { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod batlow_gpi9 { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod thrm_gpi8 { // bits 23:23, established
        pub const SHIFT: u32 = 23;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod susstat2_gpo { // bits 22:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod susstat1_gpo { // bits 21:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod zz_gpo { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pcistp_gpo { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cpustp_gpo { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod susbc_gpo { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod serirq_sel { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod smbalert_sel { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod irq8_sel { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sec_ide_tristate { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pri_ide_tristate { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reqc_sel { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reqb_sel { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reqa_sel { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pnp_decode { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod alt_access { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ide_split { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod config2 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod config1 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos_decode { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod isa_mode { // bits 0:0, established
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
/// Real-time clock configuration. The PROM writes 0x25 (positive decode, upper bank enable, RTC enable). The HAL sets bit 2 by read-modify-write before u (established)
pub mod f0_rtccfg {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xcb;
    pub mod pos_decode { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lock_upper { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lock_lower { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod upper_en { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc_en { // bits 0:0, established
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
/// Vendor identification, Intel. (established)
pub mod f1_vid {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x0;
}
/// Device identification of function 1. The firmware's self-test reads the function 0 vendor and device words as one dword and expects 0x71108086. (established)
pub mod f1_did {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
}
/// PCI command. The PROM's IDE attach writes 5 (I/O space and bus master enable). (established)
pub mod f1_pcicmd {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
    pub mod bme { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod iose { // bits 0:0, established
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
/// PCI status. (established)
pub mod f1_pcists {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
}
/// Revision. (established)
pub mod f1_rid {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
}
/// Class code, programming interface (bus master capable, both channels legacy mode). (established)
pub mod f1_classc_pi {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x9;
}
/// Class code, sub-class: IDE. (established)
pub mod f1_classc_scc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xa;
}
/// Class code, base class: mass storage. (established)
pub mod f1_classc_basec {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb;
}
/// Master latency timer. The PROM's IDE attach writes 0x80. (established)
pub mod f1_mlt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd;
}
/// Header type, 0: single function (multifunction is reported by function 0). (established)
pub mod f1_hedt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xe;
}
/// Bus-master interface base address: I/O space, bits 15:4 are address bits, bit 0 hardwired 1. (established)
pub mod f1_bmiba {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
    pub mod base { // bits 15:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rte { // bits 0:0, established
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
/// IDE timing: 0x40 primary channel, 0x42 secondary. The PROM's IDE attach writes the dword 0xc077c077 (both channels: decode enabled, slave timing regis (established)
pub mod f1_idetim {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x40;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 2;
    pub mod ide_en { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sitre { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod isp { // bits 13:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dte1 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ppe1 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ie1 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod time1 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dte0 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ppe0 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ie0 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod time0 { // bits 0:0, established
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
/// Slave IDE timing (drive 1 of each channel) when IDETIM bit 14 is set. The PROM writes 0. (established)
pub mod f1_sidetim {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x44;
}
/// Ultra DMA/33 enable per drive. (established)
pub mod f1_udmactl {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x48;
    pub mod ssde1 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ssde0 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod psde1 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod psde0 { // bits 0:0, established
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
/// Ultra DMA/33 cycle times, two bits per drive (00 CT 4 and RP 6 PCI clocks, 01 3 and 5, 10 2 and 4). (established)
pub mod f1_udmatim {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4a;
    pub mod sct1 { // bits 13:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sct0 { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pct1 { // bits 5:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pct0 { // bits 1:0, established
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
/// Vendor identification, Intel. (established)
pub mod f2_vid {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x0;
}
/// Device identification of function 2. The firmware's self-test reads the function 0 vendor and device words as one dword and expects 0x71108086. (established)
pub mod f2_did {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
}
/// PCI command. (established)
pub mod f2_pcicmd {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
}
/// PCI status. (established)
pub mod f2_pcists {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
}
/// Revision. (established)
pub mod f2_rid {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
}
/// Class code, programming interface: OpenHCI-style USB host controller. (established)
pub mod f2_classc_pi {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x9;
}
/// Class code, sub-class: USB. (established)
pub mod f2_classc_scc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xa;
}
/// Class code, base class: serial bus. (established)
pub mod f2_classc_basec {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb;
}
/// Master latency timer. (established)
pub mod f2_mlt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd;
}
/// Header type, 0. (established)
pub mod f2_hedt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xe;
}
/// USB I/O space base address: bits 15:5, bit 0 hardwired 1. (established)
pub mod f2_usbba {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
    pub mod base { // bits 15:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x7ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rte { // bits 0:0, established
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
/// Interrupt line; no effect on the hardware. (established)
pub mod f2_intln {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3c;
}
/// Interrupt pin, hardwired 4 (INTD#). The datasheet says the USB interrupt is also ORed to PIRQD#; the board wires only this pin to its own interrupt en (established)
pub mod f2_intpn {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3d;
}
/// Serial bus release number, 0x10 (USB 1.0). (established)
pub mod f2_sbrnum {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x60;
}
/// Legacy keyboard and mouse support: trap and SMI enables and status. Not written by held software. (established)
pub mod f2_legsup {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xc0;
    pub mod usbpirqden { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Miscellaneous support: bit 4 lets a read of port 0x70 return the RTC index. Byte accesses only. (established)
pub mod f2_miscsup {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xff;
    pub mod rtciren { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Vendor identification, Intel. (established)
pub mod f3_vid {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x0;
}
/// Device identification of function 3. The firmware's self-test reads the function 0 vendor and device words as one dword and expects 0x71108086. (established)
pub mod f3_did {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
}
/// PCI command. Bit 0 enables the SMBus I/O block and works independently of PMREGMISC bit 0. The PROM's function 3 attach sets it after writing the SMBu (established)
pub mod f3_pcicmd {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
    pub mod iose { // bits 0:0, established
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
/// PCI status; the PROM's attach clears it by writing 0x3800. (established)
pub mod f3_pcists {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x6;
}
/// Revision. (established)
pub mod f3_rid {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8;
}
/// Class code, programming interface. (established)
pub mod f3_classc_pi {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x9;
}
/// Class code, sub-class: other bridge. (established)
pub mod f3_classc_scc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xa;
}
/// Class code, base class: bridge. (established)
pub mod f3_classc_basec {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb;
}
/// Header type, 0. (established)
pub mod f3_hedt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xe;
}
/// Interrupt line; no effect on the hardware. (established)
pub mod f3_intln {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3c;
}
/// Interrupt pin. The datasheet says it reads 1 (PIRQA#). The specification update (spec change 1, p.13) says the register is not implemented because the (unknown)
pub mod f3_intpn {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3d;
}
/// Power management base address. Bits 15:6 hold the I/O base, bit 0 is hardwired 1, bits 31:16 are hardwired 0. The PROM writes 0x0f80 and the register  (established)
pub mod f3_pmba {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
    pub mod base { // bits 15:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rte { // bits 0:0, established
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
/// Idle timer counts and resolutions for the device monitors and the slow burst count. Not written by held software. (established)
pub mod f3_cnta {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x44;
}
/// Fast burst timer count, CPU select, thermal duty and video status. The specification update (spec change 5) corrects bit 5 to 8 microsecond granularit (established)
pub mod f3_cntb {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x48;
}
/// General purpose input control: enable, polarity and edge for the device-monitor GPI inputs (Table 17 maps GPI18 to GPI21 to device monitors 10 to 13). (established)
pub mod f3_gpictl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4c;
}
/// Miscellaneous power management. The PROM writes 1 after the base. When the bit is clear every access to the power management block goes unclaimed. (established)
pub mod f3_pmregmisc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x80;
    pub mod pmiose { // bits 0:0, established
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
/// SMBus base address: bits 15:4, bit 0 hardwired 1. The PROM's function 3 attach writes 0x0fd0, so the register reads 0x00000fd1 (not read back by any h (established)
pub mod f3_smbba {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
    pub mod base { // bits 15:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rte { // bits 0:0, established
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
/// SMBus host configuration. The PROM writes 0x09: host interface enabled and the interrupt routed to IRQ9. (established)
pub mod f3_smbhstcfg {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd2;
    pub mod intrsel { // bits 3:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod host_en { // bits 0:0, established
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
/// SMBus slave command match value. (established)
pub mod f3_smbslvc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd3;
}
/// SMBus slave shadow port 1. (established)
pub mod f3_smbshdw1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd4;
}
/// SMBus slave shadow port 2. (established)
pub mod f3_smbshdw2 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd5;
}
/// SMBus revision. (established)
pub mod f3_smbrev {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xd6;
}
/// RTC index and NMI enable, shared. Bits 6:0 index the lower RTC bank; bit 7 set disables NMI. The PROM and the HAL reach the clock through ports 0x70 a (established)
pub mod rtci {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x70;
    pub mod nmi_dis { // bits 7:7, established
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
/// RTC data, lower 128-byte bank. (established)
pub mod rtcd {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x71;
}
/// RTC extended index: bits 6:0 address the upper bank (the datasheet lists it write only in its register page and read/write in Table 5). Bit 7 is the a (established)
pub mod rtcei {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x72;
    pub mod nmi_dis { // bits 7:7, established
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
/// RTC extended data, upper 128-byte bank (battery-backed RAM). (established)
pub mod rtced {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x73;
}
/// Port 92. The PROM never writes it; the application processors set bit 1. The datasheet text says FAST_A20 set asserts A20M# low but its own table and  (established)
pub mod p92 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x92;
    pub mod fast_a20 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fast_init { // bits 0:0, established
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
/// APM control port; a write can raise an SMI#. (established)
pub mod apmc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb2;
}
/// APM status port. (established)
pub mod apms {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xb3;
}
/// Power management status. The HAL clears it and reads bit 8 for the power button; the PROM reads it for wake-up state and writes it back to clear. (established)
pub mod pmsts {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x0;
    pub mod rsm_sts { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pwrbtnor_sts { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc_sts { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pwrbtn_sts { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gbl_sts { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bm_sts { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tmrof_sts { // bits 0:0, established
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
/// Power management resume enable. The PROM and the HAL write 0x0100 (power button). (established)
pub mod pmen {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x2;
    pub mod rtc_en { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pwrbtn_en { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gbl_en { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tmrof_en { // bits 0:0, established
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
/// Power management control. Linux powers off, and the HAL suspends, by writing 0x2000 (suspend enable with type 0, soft off). The PROM writes 0x1401 (wo (established)
pub mod pmcntrl {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x4;
    pub mod sus_en { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sus_typ { // bits 12:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const SOFF: u32 = 0; // established
        pub const STR: u32 = 1; // established
        pub const POSCL: u32 = 2; // established
        pub const POSCCL: u32 = 3; // established
        pub const POS: u32 = 4; // established
        pub const WORKING: u32 = 5; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Soff,
            Str,
            Poscl,
            Posccl,
            Pos,
            Working,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Soff,
                    1 => Self::Str,
                    2 => Self::Poscl,
                    3 => Self::Posccl,
                    4 => Self::Pos,
                    5 => Self::Working,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Soff => 0,
                    Self::Str => 1,
                    Self::Poscl => 2,
                    Self::Posccl => 3,
                    Self::Pos => 4,
                    Self::Working => 5,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod gbl_rls { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod brld_en_bm { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sci_en { // bits 0:0, established
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
/// Power management timer: a free-running 24-bit counter at 3.579545 MHz; bit 23 toggling sets TMROF_STS. (established)
pub mod pmtmr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
    pub mod tmr_val { // bits 23:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xffffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// General purpose status. The PROM reads it (0xf8c) for wake-up and power-fail state. (established)
pub mod gpsts {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xc;
    pub mod lid_sts { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ri_sts { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi_sts { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod usb_sts { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod thrmor_sts { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod thrm_sts { // bits 0:0, established
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
/// General purpose enable. The PROM's function 3 attach writes 0 (0xf8e). (established)
pub mod gpen {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0xe;
    pub mod lid_en { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ri_en { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi_en { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod usb_en { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod thrm_en { // bits 0:0, established
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
/// Processor control: throttling, clock control and PCI clock run enables. Not written by held software. (established)
pub mod pcntrl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// Processor level 2: a read enters stop grant or quick start. (established)
pub mod plvl2 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x14;
}
/// Processor level 3: a read enters stop clock, sleep or deep sleep. (established)
pub mod plvl3 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x15;
}
/// Global status. (established)
pub mod glbsts {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x18;
}
/// Device status: idle and trap status of the device monitors. (established)
pub mod devsts {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
}
/// Global enable. (established)
pub mod glben {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x20;
}
/// Global control: SMI enable, end of SMI, BIOS release, global standby timer. (established)
pub mod glbctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// Device control: trap and idle enables of the device monitors. (established)
pub mod devctl {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x2c;
}
/// General purpose input, byte reads only (offsets 0x30 to 0x32; the byte at 0x33 is not listed). Bits 21:0 are the logical value on pins GPI21 to GPI0;  (established)
pub mod gpireg {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x30;
    pub mod board_id { // bits 21:18, inferred
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi17 { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi16 { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi15 { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi14 { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi13 { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi12 { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi11 { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi10 { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi9 { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi8 { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi7 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi6 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi5 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi4 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi3 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi2 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi1 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpi0 { // bits 0:0, established
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
/// General purpose output, byte accesses only (ports 0xfb4 to 0xfb7). Bits 30:0 drive GPO30 to GPO0 and read back the last value written; a pin shared wi (established)
pub mod gporeg {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
    pub mod gpo30 { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo29 { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo28 { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo27 { // bits 27:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo26 { // bits 26:26, established
        pub const SHIFT: u32 = 26;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo25 { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo24 { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo23 { // bits 23:23, established
        pub const SHIFT: u32 = 23;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo22 { // bits 22:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo21 { // bits 21:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo20 { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo19 { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo18 { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo17 { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo16 { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo15 { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo14 { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo13 { // bits 13:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo12 { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo11 { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo10 { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo9 { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo8 { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo7 { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo6 { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo5 { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo4 { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo3 { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo2 { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo1 { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gpo0 { // bits 0:0, established
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
/// Reset control. Linux restarts the board by writing 0x06 (reset CPU with system reset set); the HAL does the same on all but the earliest boards. Bit 2 (established)
pub mod rc {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod rcpu { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod srst { // bits 1:1, established
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
/// SMBus host status: failed, bus collision, device error, interrupt (all write 1 to clear) and host busy. The PROM clears it by writing before its one t (established)
pub mod smbhststs {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod failed { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bus_err { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dev_err { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod inter { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod host_busy { // bits 0:0, established
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
/// SMBus slave status. (established)
pub mod smbslvsts {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
}
/// SMBus host control. The PROM's single transaction writes 0x54 (start, block protocol); reading the register resets the block data index. (established)
pub mod smbhstcnt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
    pub mod start { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd_prot { // bits 4:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub const QUICK: u32 = 0; // established
        pub const BYTE: u32 = 1; // established
        pub const BYTE_DATA: u32 = 2; // established
        pub const WORD_DATA: u32 = 3; // established
        pub const BLOCK: u32 = 5; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Quick,
            Byte,
            ByteData,
            WordData,
            Block,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Quick,
                    1 => Self::Byte,
                    2 => Self::ByteData,
                    3 => Self::WordData,
                    5 => Self::Block,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Quick => 0,
                    Self::Byte => 1,
                    Self::ByteData => 2,
                    Self::WordData => 3,
                    Self::Block => 5,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod kill { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod interen { // bits 0:0, established
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
/// SMBus host command field. (established)
pub mod smbhstcmd {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
}
/// SMBus host address: bits 7:1 slave address, bit 0 read (1) or write (0). (established)
pub mod smbhstadd {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x4;
}
/// SMBus host data 0 (byte count for block transfers). (established)
pub mod smbhstdat0 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x5;
}
/// SMBus host data 1. (established)
pub mod smbhstdat1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6;
}
/// SMBus block data port. (established)
pub mod smbblkdat {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x7;
}
pub const BOARD_ID_SHIFT: u32 = 0x2; // inferred
pub const IDETIM_PROM_VALUE: u32 = 0xc077c077; // established
pub const PM_BASE: u32 = 0xf80; // established
pub const RC_PORT: u32 = 0xcf9; // established
pub const SMB_BASE: u32 = 0xfd0; // established

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn f0_pcicmd_f() {
        assert_eq!(f0_pcicmd::io_space::get(0xf), 1);
        assert_eq!(f0_pcicmd::memory::get(0xf), 1);
        assert_eq!(f0_pcicmd::bus_master::get(0xf), 1);
        assert_eq!(f0_pcicmd::sce::get(0xf), 1);
        assert_eq!(f0_pcicmd::serre::get(0xf), 0);
    }

    #[test]
    fn f0_xbcs_f4() {
        assert_eq!(f0_xbcs::rtccs_en::get(0xf4), 0);
        assert_eq!(f0_xbcs::kbccs_en::get(0xf4), 0);
        assert_eq!(f0_xbcs::bioscs_wp::get(0xf4), 1);
        assert_eq!(f0_xbcs::port61_alias::get(0xf4), 0);
        assert_eq!(f0_xbcs::mouse::get(0xf4), 1);
        assert_eq!(f0_xbcs::coproc_err::get(0xf4), 1);
        assert_eq!(f0_xbcs::lower_bios::get(0xf4), 1);
        assert_eq!(f0_xbcs::ext_bios::get(0xf4), 1);
        assert_eq!(f0_xbcs::apic_cs::get(0xf4), 0);
        assert_eq!(f0_xbcs::bios_1meg::get(0xf4), 0);
        assert_eq!(f0_xbcs::mc_loc::get(0xf4), 0);
    }

    #[test]
    fn f0_pirqrc_9() {
        assert_eq!(f0_pirqrc::route_off::get(0x9), 0);
        assert_eq!(f0_pirqrc::irq::get(0x9), 9);
    }

    #[test]
    fn f0_tom_f2() {
        assert_eq!(f0_tom::top::get(0xf2), 15);
        assert_eq!(f0_tom::lower_bios_fwd::get(0xf2), 0);
        assert_eq!(f0_tom::a0000_en::get(0xf2), 0);
        assert_eq!(f0_tom::low512_fwd::get(0xf2), 1);
    }

    #[test]
    fn f0_mbdma_c() {
        assert_eq!(f0_mbdma::fast::get(0xc), 0);
        assert_eq!(f0_mbdma::one::get(0xc), 1);
        assert_eq!(f0_mbdma::chnl::get(0xc), 4);
    }

    #[test]
    fn f0_rtccfg_25() {
        assert_eq!(f0_rtccfg::rtc_en::get(0x25), 1);
        assert_eq!(f0_rtccfg::upper_en::get(0x25), 1);
        assert_eq!(f0_rtccfg::lock_lower::get(0x25), 0);
        assert_eq!(f0_rtccfg::lock_upper::get(0x25), 0);
        assert_eq!(f0_rtccfg::pos_decode::get(0x25), 1);
    }

    #[test]
    fn f1_pcicmd_5() {
        assert_eq!(f1_pcicmd::iose::get(0x5), 1);
        assert_eq!(f1_pcicmd::bme::get(0x5), 1);
    }

    #[test]
    fn f1_idetim_4000() {
        assert_eq!(f1_idetim::ide_en::get(0x4000), 0);
        assert_eq!(f1_idetim::sitre::get(0x4000), 1);
        assert_eq!(f1_idetim::isp::get(0x4000), 0);
        assert_eq!(f1_idetim::rtc::get(0x4000), 0);
    }

    #[test]
    fn f1_idetim_c077() {
        assert_eq!(f1_idetim::ide_en::get(0xc077), 1);
        assert_eq!(f1_idetim::sitre::get(0xc077), 1);
        assert_eq!(f1_idetim::isp::get(0xc077), 0);
        assert_eq!(f1_idetim::rtc::get(0xc077), 0);
        assert_eq!(f1_idetim::dte1::get(0xc077), 0);
        assert_eq!(f1_idetim::ppe1::get(0xc077), 1);
        assert_eq!(f1_idetim::ie1::get(0xc077), 1);
        assert_eq!(f1_idetim::time1::get(0xc077), 1);
        assert_eq!(f1_idetim::dte0::get(0xc077), 0);
        assert_eq!(f1_idetim::ppe0::get(0xc077), 1);
        assert_eq!(f1_idetim::ie0::get(0xc077), 1);
        assert_eq!(f1_idetim::time0::get(0xc077), 1);
    }

    #[test]
    fn f3_pmba_f81() {
        assert_eq!(f3_pmba::rte::get(0xf81), 1);
        assert_eq!(f3_pmba::base::get(0xf81), 62);
    }

    #[test]
    fn f3_pmregmisc_1() {
        assert_eq!(f3_pmregmisc::pmiose::get(0x1), 1);
    }

    #[test]
    fn f3_smbba_fd1() {
        assert_eq!(f3_smbba::rte::get(0xfd1), 1);
        assert_eq!(f3_smbba::base::get(0xfd1), 253);
    }

    #[test]
    fn f3_smbhstcfg_9() {
        assert_eq!(f3_smbhstcfg::host_en::get(0x9), 1);
        assert_eq!(f3_smbhstcfg::intrsel::get(0x9), 4);
    }

    #[test]
    fn pmen_100() {
        assert_eq!(pmen::pwrbtn_en::get(0x100), 1);
        assert_eq!(pmen::rtc_en::get(0x100), 0);
    }

    #[test]
    fn pmcntrl_1401() {
        assert_eq!(pmcntrl::sus_en::get(0x1401), 0);
        assert_eq!(pmcntrl::sus_typ::get(0x1401), 5);
        assert_eq!(pmcntrl::sci_en::get(0x1401), 1);
    }

    #[test]
    fn pmcntrl_2000() {
        assert_eq!(pmcntrl::sus_en::get(0x2000), 1);
        assert_eq!(pmcntrl::sus_typ::get(0x2000), 0);
        assert_eq!(pmcntrl::sci_en::get(0x2000), 0);
    }

    #[test]
    fn rc_6() {
        assert_eq!(rc::srst::get(0x6), 1);
        assert_eq!(rc::rcpu::get(0x6), 1);
    }

    #[test]
    fn smbhstcnt_54() {
        assert_eq!(smbhstcnt::start::get(0x54), 1);
        assert_eq!(smbhstcnt::cmd_prot::get(0x54), 5);
        assert_eq!(smbhstcnt::kill::get(0x54), 0);
        assert_eq!(smbhstcnt::interen::get(0x54), 0);
    }
}
