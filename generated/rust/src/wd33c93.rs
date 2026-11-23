// @generated from devices/wd33c93/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 9910f5661f6314c737e8fc59355fe020e6e1845f293604aa3a75852ecd0c3cb5
// WD33C93/WD33C93A SCSI bus interface controller as wired on the Indigo (R3000 and R4000 boards)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Own ID and CDB size. The bus ID in bits 2:0 and the configuration bits are sampled by the Reset command, so they take effect only after a reset. Both  (established)
pub mod own_id {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x0;
    pub mod fs { // bits 7:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod eih_raf { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ehp { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod eaf { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod id { // bits 2:0, established
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
/// Control. Interrupt and DMA mode selection. IRIX and the PROM write 0x2d (burst DMA mode) once the chip has been reset and detected as a WD33C93A or B, (established)
pub mod control {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1;
    pub mod dma_mode { // bits 7:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hhp { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod edi { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod idi { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ha { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hsp { // bits 0:0, established
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
/// Selection timeout. Zero disables the timeout. IRIX writes 0x40; the PROM writes 0x40 through a helper called at the end of its reset routine. During t (established)
pub mod timeout {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x2;
}
/// CDB bytes 1 to 12 for Select-and-Transfer. The same offsets are total sectors, heads, cylinders, logical address and head and cylinder numbers for Tra (established)
pub mod cdb {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x3;
    pub const COUNT: u32 = 12;
    pub const STRIDE: u64 = 1;
}
/// Target LUN. The initiator writes the LUN for the Identify message; after Select-and-Transfer completes it holds the target's status byte (IRIX reads i (established)
pub mod target_lun {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0xf;
    pub mod tlv { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dok { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lun { // bits 2:0, established
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
/// Command phase: how far a Select-and-Transfer has progressed. The chip advances it as phases complete (CPH_ constants); the driver writes a value back  (established)
pub mod command_phase {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x10;
}
/// Synchronous transfer: offset in bits 3:0 (zero means asynchronous), period in bits 6:4 (0 is 8 clock cycles, 2 to 7 are that many cycles), bit 7 fast  (established)
pub mod sync_transfer {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x11;
    pub mod fast { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod period { // bits 6:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x7;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod offset { // bits 3:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// 24-bit transfer count, most significant byte at index 12h, written with one address-port write of 12h and three data-port writes. IRIX writes zero for (established)
pub mod transfer_count {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x12;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 1;
}
/// Destination ID: target to select or reselect, bits 2:0; bit 6 DPD gives the expected data direction in advanced mode (1 is device to host); bit 7 SCC  (established)
pub mod dest_id {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x15;
    pub mod scc { // bits 7:7, inferred
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dpd { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod df { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod id { // bits 2:0, established
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
/// Source ID: ER (bit 7) enables reselection, ES (bit 6) selection, DSP (bit 5) ignores select parity; bit 3 SIV and bits 2:0 report who selected or rese (established)
pub mod source_id {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x16;
    pub mod er { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod es { // bits 6:6, inferred
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dsp { // bits 5:5, inferred
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod siv { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod id { // bits 2:0, established
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
/// SCSI status: the cause of the last interrupt, high nibble the group (0 reset, 1 done, 2 paused, 4 terminated, 8 service) and low nibble the qualifier  (established)
pub mod scsi_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x17;
}
/// Command: bits 6:0 the command code, bit 7 single-byte transfer. The register stays selected after a write (no auto-increment). It must not be written  (established)
pub mod command {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x18;
    pub mod sbt { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod code { // bits 6:0, established
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
/// Data register: the host side of the 12-byte FIFO. IRIX uses it in programmed-I/O message and inquiry phases, polling the DBR bit of the auxiliary stat (established)
pub mod data {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x19;
}
/// Queue tag, WD33C93B only. IRIX never touches it. NetBSD writes 0x55 here and reads it back after a reset that returned status 0x01: if it reads 0x55 t (inferred)
pub mod queue_tag {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x1a;
}
/// Auxiliary status. Bit 7 INT is the interrupt-request pin: it stays set until the SCSI status register is read. Bit 6 LCI says a command was written wh (established)
pub mod aux_status {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x122;
    pub mod int { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lci { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bsy { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cip { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pe { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dbr { // bits 0:0, established
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
/// Data port. Reads and writes the internal register selected through the address port. Every IRIX and PROM access is a byte access. A qtest can discrimi (established)
pub mod data_port {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x126;
}
/// Address port. A byte written here selects the internal register the next data-port access uses. No shipped code reads it back (a read returns the auxi (established)
pub mod address {
    pub const WIDTH: u32 = 8;
    pub const OFFSET: u64 = 0x122;
}
pub const CMD_ABORT: u32 = 0x1; // inferred
pub const CMD_ASSERT_ATN: u32 = 0x2; // inferred
pub const CMD_DISCONNECT: u32 = 0x4; // established
pub const CMD_NEGATE_ACK: u32 = 0x3; // inferred
pub const CMD_RESELECT: u32 = 0x5; // inferred
pub const CMD_RESET: u32 = 0x0; // established
pub const CMD_SBT: u32 = 0x80; // established
pub const CMD_SELECT: u32 = 0x7; // inferred
pub const CMD_SELECT_ATN: u32 = 0x6; // established
pub const CMD_SELECT_ATN_XFER: u32 = 0x8; // established
pub const CMD_SELECT_XFER: u32 = 0x9; // inferred
pub const CMD_TRANSFER_INFO: u32 = 0x20; // established
pub const CMD_TRANSLATE: u32 = 0x18; // inferred
pub const CONTROL_IRIX_BURST: u32 = 0x2d; // established
pub const CONTROL_IRIX_SINGLE: u32 = 0x8d; // established
pub const CPH_CMD_COMPLETE: u32 = 0x60; // established
pub const CPH_CMD_START: u32 = 0x30; // established
pub const CPH_DATA_DONE: u32 = 0x46; // established
pub const CPH_DISCONNECTED: u32 = 0x43; // established
pub const CPH_DISCONNECT_MSG: u32 = 0x42; // established
pub const CPH_IDENTIFY_IN: u32 = 0x45; // established
pub const CPH_IDENTIFY_SENT: u32 = 0x20; // established
pub const CPH_RESELECTED: u32 = 0x44; // established
pub const CPH_SAVE_DP: u32 = 0x41; // established
pub const CPH_SELECTED: u32 = 0x10; // established
pub const CPH_STATUS_DONE: u32 = 0x50; // established
pub const CPH_STATUS_PHASE: u32 = 0x47; // established
pub const OWNID_IRIX_AF: u32 = 0xa8; // established
pub const OWNID_IRIX_PLAIN: u32 = 0x80; // established
pub const PHASE_COMMAND: u32 = 0x2; // established
pub const PHASE_DATA_IN: u32 = 0x1; // established
pub const PHASE_DATA_OUT: u32 = 0x0; // established
pub const PHASE_MSG_IN: u32 = 0x7; // established
pub const PHASE_MSG_OUT: u32 = 0x6; // established
pub const PHASE_STATUS: u32 = 0x3; // established
pub const SOURCEID_ENABLE_RESEL: u32 = 0x80; // established
pub const STATUS_BAD_CMD: u32 = 0x40; // inferred
pub const STATUS_BAD_STATUS: u32 = 0x47; // established
pub const STATUS_DISCONNECT: u32 = 0x85; // established
pub const STATUS_MSGIN_PAUSED: u32 = 0x20; // inferred
pub const STATUS_PARITY: u32 = 0x43; // established
pub const STATUS_PARITY_ATN: u32 = 0x44; // established
pub const STATUS_REQ_MSGIN: u32 = 0x8f; // established
pub const STATUS_REQ_MSGOUT: u32 = 0x8e; // established
pub const STATUS_RESELECT: u32 = 0x80; // established
pub const STATUS_RESELECT_AF: u32 = 0x81; // established
pub const STATUS_RESET: u32 = 0x0; // established
pub const STATUS_RESET_AF: u32 = 0x1; // established
pub const STATUS_SAT_DONE: u32 = 0x16; // established
pub const STATUS_SAVE_DP: u32 = 0x21; // established
pub const STATUS_SELECT_DONE: u32 = 0x11; // established
pub const STATUS_SEL_TIMEOUT: u32 = 0x42; // established
pub const STATUS_UNEXP_DISC: u32 = 0x41; // established
pub const STATUS_UNEXP_PHASE: u32 = 0x48; // established
pub const STATUS_XFER_DONE: u32 = 0x18; // established
pub const TIMEOUT_IRIX: u32 = 0x40; // established
