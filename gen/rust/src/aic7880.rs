// generated from defs/aic7880.toml by defs-gen - do not edit, change the source
// Adaptec AIC-7880 SCSI controller on the O2: host DMA register contract
#![allow(dead_code)]

/// Host PCI address for the host DMA transfer, four byte registers at 0x88 to 0x8b. Loading it also loads SHADDR. The byte significance across the four b (inferred)
pub mod lhaddr {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
}
/// 24-bit host transfer count in three byte registers at 0x8c to 0x8e. A zero count inhibits host PCI requests. Loading a nonzero count clears HDONE. The (inferred)
pub mod hcnt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x8c;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 1;
}
/// Data FIFO control. Bits 5 and 4 enable SCSI and SCSI-block DMA, bit 3 enables host DMA, bit 2 selects the direction, bit 1 flushes the FIFO and bit 0  (inferred)
pub mod dfcntrl {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x93;
    pub mod scsien { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sdmaen { // bits 4:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hdmaen { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod direction { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fifoflush { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fiforeset { // bits 0:0, inferred
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
/// Data FIFO status. Reports FIFOEMP, FIFOFULL, FIFOQWDEMP, MREQPEND and HDONE. The bit positions are not in the cited extract, so no field is listed her (inferred)
pub mod dfstatus {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x94;
}
