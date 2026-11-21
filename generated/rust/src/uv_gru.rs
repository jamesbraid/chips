// generated from devices/uv_gru/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 9fd998eb93a63f0428f5eca34e50f2c7058b2d23a787c4039f35569109e1a020
// UV global reference unit (GRU): chiplet memory map, handles and instruction word
#![allow(dead_code)]

/// Control block extended handle, dword 7: the hardware's view of the active control block. (inferred)
pub mod cbe_dw7 {
    pub const WIDTH: u32 = 64;
    pub mod cbrexecstatus { // bits 63:56, inferred
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cbrstate { // bits 55:52, inferred
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ecause { // bits 51:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xfffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// First dword of a control block (the instruction word). Software fills dwords 1 to 7 first, then stores this one with the start bit set and flushes the (established)
pub mod cb_dw0 {
    pub const WIDTH: u32 = 64;
    pub mod tlb_fault_color { // bits 63:63, inferred
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod isubstatus { // bits 61:58, inferred
        pub const SHIFT: u32 = 58;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod istatus { // bits 57:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tri0 { // bits 53:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x3fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod exopc { // bits 31:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod opc { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod iaa1 { // bits 14:13, established
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod iaa0 { // bits 12:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtype { // bits 10:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ima { // bits 3:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod icmd { // bits 0:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Context configuration handle, dword 0: allocates control blocks and data segment to a context and routes its interrupts. Dword 1 is the control block  (inferred)
pub mod cch_dw0 {
    pub const WIDTH: u32 = 64;
    pub mod dsr_allocation_map { // bits 63:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tfm_done_bit_enable { // bits 28:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cause { // bits 27:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod state { // bits 19:18, inferred
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod status { // bits 17:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tlb_int_select { // bits 15:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tfm_fault_bit_enable { // bits 11:11, inferred
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tlb_int_enable { // bits 10:10, inferred
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cb_int_enable { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod req_slice { // bits 8:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod req_slice_set_enable { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod unmap_enable { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod opc { // bits 4:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod delresp { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// TLB fault handle, dword 0. The OS reads the cause here after a TLB miss and issues an opcode to fill the TLB. (inferred)
pub mod tfh_dw0 {
    pub const WIDTH: u32 = 64;
    pub mod ctxnum { // bits 51:48, inferred
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod indexway { // bits 43:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cb_int { // bits 30:30, inferred
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cause { // bits 29:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod state { // bits 22:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod status { // bits 17:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod opc { // bits 6:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod delresp { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// TLB fault handle, dword 2: the missing address space id on read, the fill address space id and attributes on write. (inferred)
pub mod tfh_dw2 {
    pub const WIDTH: u32 = 64;
    pub mod gaa { // bits 58:57, inferred
        pub const SHIFT: u32 = 57;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dirty { // bits 56:56, inferred
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fillasid { // bits 55:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod missasid { // bits 23:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// TLB fault handle, dword 3: page frame and page size of the entry to write. Dword 1 holds the missing virtual address, dword 4 the virtual address to f (inferred)
pub mod tfh_dw3 {
    pub const WIDTH: u32 = 64;
    pub mod pagesize { // bits 52:48, inferred
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pfn { // bits 40:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1ffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// TLB global handle, dword 0: used to flush GRU TLB entries after the kernel changes a mapping. Dword 1 is the virtual address, dword 4 the context bitm (inferred)
pub mod tgh_dw0 {
    pub const WIDTH: u32 = 64;
    pub mod cause { // bits 26:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod state { // bits 22:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod status { // bits 17:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod opc { // bits 2:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod delresp { // bits 1:1, inferred
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cmd { // bits 0:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// TLB global handle, dword 2. (inferred)
pub mod tgh_dw2 {
    pub const WIDTH: u32 = 64;
    pub mod global { // bits 48:48, inferred
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pagesize { // bits 36:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod asid { // bits 23:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// TLB global handle, dword 3: address mask and the count of pages to purge. (inferred)
pub mod tgh_dw3 {
    pub const WIDTH: u32 = 64;
    pub mod n { // bits 57:48, inferred
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod vaddrmask { // bits 38:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
pub const CACHE_LINE: u32 = 0x40; // established
pub const CBE_BASE: u32 = 0x4010000; // established
pub const CBR_AU_SIZE: u32 = 0x2; // established
pub const CBS_ACTIVE: u32 = 0x2; // established
pub const CBS_CALL_OS: u32 = 0x3; // established
pub const CBS_EXCEPTION: u32 = 0x1; // established
pub const CBS_IDLE: u32 = 0x0; // established
pub const CB_BASE: u32 = 0x0; // established
pub const CCHOP_ALLOCATE: u32 = 0x2; // established
pub const CCHOP_DEALLOCATE: u32 = 0x4; // established
pub const CCHOP_INTERRUPT: u32 = 0x3; // established
pub const CCHOP_INTERRUPT_SYNC: u32 = 0x5; // established
pub const CCHOP_START: u32 = 0x1; // established
pub const CCH_BASE: u32 = 0x4020000; // established
pub const CHIPLETS_PER_HUB: u32 = 0x2; // established
pub const CHIPLET_SIZE: u32 = 0x8000000; // established
pub const DSR_AU_BYTES: u32 = 0x400; // established
pub const DS_BASE: u32 = 0x20000; // established
pub const GAA_MMIO: u32 = 0x1; // established
pub const GAA_NCRAM: u32 = 0x2; // established
pub const GAA_RAM: u32 = 0x0; // established
pub const GAA_REGISTER: u32 = 0x3; // established
pub const GRU_PADDR_SHIFT: u32 = 0xc; // established
pub const GSEG_PAGESIZE: u32 = 0x40000; // established
pub const GSEG_STRIDE: u32 = 0x400000; // established
pub const HANDLE_BYTES: u32 = 0x40; // established
pub const HANDLE_STRIDE: u32 = 0x100; // established
pub const IAA_MMIO: u32 = 0x1; // established
pub const IAA_NCRAM: u32 = 0x2; // established
pub const IAA_RAM: u32 = 0x0; // established
pub const IAA_REGISTER: u32 = 0x3; // established
pub const MCS_BASE: u32 = 0x4000000; // established
pub const NUM_CB: u32 = 0x80; // established
pub const NUM_CCH: u32 = 0x10; // established
pub const NUM_DSR_BYTES: u32 = 0x8000; // established
pub const NUM_TFM: u32 = 0x10; // established
pub const NUM_TGH: u32 = 0x18; // established
pub const OP_BCOPY: u32 = 0x1; // established
pub const OP_BSTORE: u32 = 0xe; // established
pub const OP_GAMER: u32 = 0xc; // established
pub const OP_GAMERR: u32 = 0xd; // established
pub const OP_GAMIR: u32 = 0xa; // established
pub const OP_GAMIRR: u32 = 0xb; // established
pub const OP_GAMXR: u32 = 0x9; // established
pub const OP_IVLOAD: u32 = 0x3; // established
pub const OP_IVSET: u32 = 0x7; // established
pub const OP_IVSTORE: u32 = 0x5; // established
pub const OP_MESQ: u32 = 0x8; // established
pub const OP_NOP: u32 = 0x0; // established
pub const OP_VFLUSH: u32 = 0xf; // established
pub const OP_VLOAD: u32 = 0x2; // established
pub const OP_VSET: u32 = 0x6; // established
pub const OP_VSTORE: u32 = 0x4; // established
pub const SUPPORTED_BELOW_HUB_REVISION: u32 = 0x5; // established
pub const TFHOP_EXCEPTION: u32 = 0x4; // established
pub const TFHOP_NOOP: u32 = 0x0; // established
pub const TFHOP_RESTART: u32 = 0x1; // established
pub const TFHOP_USER_POLLING_MODE: u32 = 0x7; // established
pub const TFHOP_WRITE_ONLY: u32 = 0x2; // established
pub const TFHOP_WRITE_RESTART: u32 = 0x3; // established
pub const TFH_BASE: u32 = 0x4018000; // established
pub const TFM_BASE: u32 = 0x4000000; // established
pub const TGHOP_TLBINV: u32 = 0x1; // established
pub const TGH_BASE: u32 = 0x4008000; // established
pub const XTYPE_B: u32 = 0x0; // established
pub const XTYPE_CL: u32 = 0x6; // established
pub const XTYPE_DW: u32 = 0x3; // established
pub const XTYPE_S: u32 = 0x1; // established
pub const XTYPE_W: u32 = 0x2; // established
