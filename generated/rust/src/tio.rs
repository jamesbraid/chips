// generated from devices/tio/registers.toml by defs-gen - do not edit, change the source
// TIO (NUMAlink I/O node ASIC of the Altix generation), as SGI's Linux platform code names its registers
#![allow(dead_code)]

/// Widget-format identification word of the TIO itself (`TIO_NODE_ID`). The kernel reads the whole 64-bit register, keeps the low 32 bits and splits them (established)
pub mod node_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x90060e80;
    pub mod rev { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod part { // bits 27:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mfg { // bits 11:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// ICE chiplet freeze configuration (`TIO_ICE_FRZ_CFG`). Bit 61 disables the conveyor of the FPGA port: the FPGA-port driver clears it to enable and sets (established)
pub mod ice_frz_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0008100;
    pub mod disable_conveyor { // bits 61:61, established
        pub const SHIFT: u32 = 61;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Big-window translation table entries (`TIO_ITTE_BASE`, one entry per big window number 0 to 7). An entry maps one 1 GiB window of the TIO's address sp (established)
pub mod itte {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0008800;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
    pub mod valid { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod widget { // bits 13:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod offset { // bits 7:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// ICE port-module interface transmit configuration (`TIO_ICE_PMI_TX_CFG`). The FPGA-port driver resets corelet n by writing a one in bit n, waiting 2 ms (established)
pub mod ice_pmi_tx_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb000b100;
}
/// Dynamic transmit credit status of channel buffer 3 (`TIO_ICE_PMI_TX_DYN_CREDIT_STAT_CB3`). The driver treats a credit count of 15 as proof that an FPG (established)
pub mod ice_pmi_tx_dyn_credit_stat_cb3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb000be18;
    pub mod credit_count { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const BIG_WINDOW_SIZE_BITS: u32 = 0x1e; // established
pub const CE_PART_NUMBER: u32 = 0xce00; // established
pub const CTALK_CHIPLET_SHIFT: u32 = 0x26; // established
pub const CTALK_NASID_SHIFT: u32 = 0x28; // established
pub const ERROR_VECTOR: u32 = 0x36; // established
pub const ERROR_VECTOR_TIOCA: u32 = 0x35; // established
pub const ERROR_VECTOR_TIOCX: u32 = 0x37; // established
pub const FPGA_CORELET: u32 = 0x3; // established
pub const INTR_VECTOR_SHIFT: u32 = 0x38; // established
pub const KLTYPE_TIO: u32 = 0x12; // established
pub const SAL_HUB_ERROR_INTERRUPT: u32 = 0x2000060; // established
pub const SAL_IOIF_INTERRUPT: u32 = 0x200004a; // established
pub const SMALL_WINDOW_SIZE_BITS: u32 = 0x1c; // established
pub const WIDGET_ID_OFFSET: u32 = 0x0; // established
