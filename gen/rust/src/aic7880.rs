// generated from defs/aic7880.toml by defs-gen - do not edit, change the source
// Adaptec AIC-7880 SCSI controller on the O2: host DMA and SCB register contract
#![allow(dead_code)]

/// Read-only port that returns 0xff to the host and to the sequencer. It is a source for logical and arithmetic functions. The book gives no write functi (inferred)
pub mod allones {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x69;
}
/// Read returns 0x00 and does not return an earlier write. Written as the destination NONE, the byte is discarded and no location changes. Both direction (inferred)
pub mod allzeros {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6a;
}
/// A write stores the byte. Bits 6:4 form an octal value, and a read returns the one-hot byte with bit N set, where N is that value. The book does not de (inferred)
pub mod function1 {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x6e;
    pub mod select { // bits 6:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
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
/// SCB page select latch. All eight bits read back as written, whether or not external SRAM is selected and however much of it is fitted, so a read-back  (inferred)
pub mod scbptr {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x90;
}
/// Data FIFO control. Bits 5 and 4 enable SCSI and SCSI-block DMA, bit 3 enables host DMA, bit 2 selects the direction, bit 1 flushes the FIFO and bit 0  (inferred)
pub mod dfcntrl {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x93;
    pub mod wideodd { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
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
/// SCB byte counter. Bits 6:5 read zero. With SCBAUTO clear the window offset selects the byte and the counter is not used. With SCBAUTO set the counter  (inferred)
pub mod scbcnt {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x9a;
    pub mod scbauto { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod scbofs { // bits 4:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x1f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// SCB window: 32 byte positions of the page that SCBPTR selects. Sequencer accesses are byte wide. Host reads are byte wide. Host writes are byte wide i (inferred)
pub mod scbwin {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xa0;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 1;
}
