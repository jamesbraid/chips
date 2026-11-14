// generated from devices/hub/registers-extra.toml by defs-gen - do not edit, change the source
// Hub block transfer engine registers and control bits outside the census
#![allow(dead_code)]

/// Widget identification register of the Hub widget. Offset and field layout are from the public header. The header gives no access type and no reset val (established)
pub mod iio_wid {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400000;
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
/// Local access protection register, named and placed by the public header. The header gives no fields, access type or reset. The IRIX register table con (established)
pub mod iio_ilapr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400100;
}
/// Protection override register, named and placed by the public header. The header gives no unlock value or behaviour, so none is imported. The IRIX regi (established)
pub mod iio_ilapo {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400108;
}
/// Graphics node and widget register 1, the twin of iio_igfx_0 in the census. The header gives both the same field layout: widget number in bits 3:0, nod (inferred)
pub mod iio_igfx_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400148;
    pub mod valid { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod processor { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node { // bits 12:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod widget { // bits 3:0, established
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
/// Scratch register 0. The header names its bit uses for software only and gives a mask of the bits that exist, 0x0000000f00f11fff. The IRIX register tab (established)
pub mod iio_scratch_reg0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400150;
}
/// Scratch register 1, the twin of register 0. The IRIX register table confirms the access. (established)
pub mod iio_scratch_reg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400158;
}
/// Big-window translation entry n, for n from 0 to 6. Entry 0 is at the register offset and each later entry is eight bytes further on. The IRIX register (established)
pub mod iio_itte {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400160;
    pub const COUNT: u32 = 7;
    pub const STRIDE: u64 = 8;
    pub mod iospace { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod widget { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod slice { // bits 4:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Word A of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individu (inferred)
pub mod iio_icrb_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400400;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// Word B of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individu (inferred)
pub mod iio_icrb_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400408;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// Word C of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individu (inferred)
pub mod iio_icrb_c {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400410;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// Word D of the I/O interface's CRB entries. Entry x (0 to 14) is at this offset plus 0x20 times x; the census names entry 0 and a few siblings individu (inferred)
pub mod iio_icrb_d {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400418;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 32;
}
/// Notification address of engine 0, the twin of the engine 1 slot in the census. Offset and name are from the public header. The IRIX register table con (established)
pub mod iio_ibna_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410020;
}
/// Interrupt address of engine 0. Offset and name are from the public header. The IRIX register table confirms the access. (established)
pub mod iio_ibia_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410028;
    pub mod level { // bits 22:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node { // bits 8:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt address of engine 1. Offset and name are from the public header. The IRIX register table confirms the access. (established)
pub mod iio_ibia_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420028;
    pub mod level { // bits 22:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node { // bits 8:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const IIO_IBCT_NOTIFY: u32 = 0x10; // established
pub const IIO_IBCT_POISON: u32 = 0x100; // established
pub const IIO_IBCT_ZFIL_MODE: u32 = 0x1; // established
pub const IIO_IBLS_BUSY: u32 = 0x100000; // established
pub const IIO_IECLR_BTE0: u32 = 0x20000; // inferred
pub const IIO_IECLR_BTE1: u32 = 0x40000; // inferred
pub const IIO_IIDSR_ENB: u32 = 0x1000000; // established
pub const IIO_IIDSR_LVL_MASK: u32 = 0x3f; // established
pub const IIO_IIDSR_NODE_MASK: u32 = 0xff00; // established
pub const IIO_IIDSR_SENT: u32 = 0x10000000; // established
pub const IIO_ILCSR_BM8: u32 = 0x800; // established
pub const IIO_ILCSR_LLP_EN: u32 = 0x400; // established
pub const IIO_ILCSR_MAX_BURST_MASK: u64 = 0x3ff00000000; // established
pub const IIO_ILCSR_MAX_RETRY_MASK: u32 = 0x3ff0000; // established
pub const IIO_ILCSR_NULL_TO_MASK: u32 = 0x3f; // established
pub const IIO_ILCSR_WARM_RESET: u32 = 0x100; // established
pub const IIO_ILLR_CB_CNT_MASK: u32 = 0xffff0000; // established
pub const IIO_ILLR_SN_CNT_MASK: u32 = 0xffff; // established
pub const IIO_ITTE_BASE: u32 = 0x400160; // established
pub const IIO_ITTE_INVALID_WIDGET: u32 = 0x3; // established
pub const IIO_ITTE_IOSP: u32 = 0x1000; // established
pub const IIO_LLP_CSR_IS_UP: u32 = 0x2000; // established
pub const IIO_LLP_CSR_LLP_STAT_MASK: u32 = 0x3000; // established
pub const IIO_WCR_DIR_CON: u32 = 0x20000; // established
pub const IIO_WCR_WIDGET_ID_MASK: u32 = 0xf; // established
pub const IIO_WID_PART_HUB: u32 = 0xc101; // established
pub const IIO_WSTAT_ECRAZY: u64 = 0x100000000; // established
pub const IIO_WSTAT_TXRETRY: u32 = 0x200; // established
pub const IIO_WSTAT_TXRETRY_MASK: u32 = 0x7f0000; // established
pub const LNK_STAT_WORKING: u32 = 0x2; // established
