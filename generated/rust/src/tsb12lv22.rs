// @generated from devices/tsb12lv22/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 7c0c9c2e3187c6789010517cad60bcc61d96bd60b2a5cd37bd3bb1bc955da983
// TI TSB12LV22 PCI-to-IEEE 1394 OHCI 1.00 link controller (I-brick IO7), the register facts the held sources establish
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// OHCI version. Major version 1 is in bits 23:16 and minor version 0 in bits 7:0, so this is OHCI 1.00. Bit 24 reports whether a configuration ROM is pr (established)
pub mod version {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x0;
    pub mod rom_present { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod major { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod minor { // bits 7:0, established
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
/// GUID ROM access. Writing the address-reset bit resets the ROM read address, and the bit clears itself. Writing the read-start bit starts a read, and t (established)
pub mod guid_rom {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x4;
    pub mod address_reset { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod read_start { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod read_data { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Retry counts. Three read-write count fields are defined. The outbound dual-phase retry fields read as zero. The datasheet summary does not name the th (established)
pub mod retry_counts {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x8;
    pub mod dual_phase_retry { // bits 31:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count_11_8 { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count_7_4 { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count_3_0 { // bits 3:0, established
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
/// CSR data word for serial bus register transfers. Unspecified at reset. (established)
pub mod csr_data {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xc;
}
/// CSR compare word. Unspecified at reset. (established)
pub mod csr_compare {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x10;
}
/// CSR control. Writing clears the done bit, which the controller sets on completion. The resource select is unspecified at reset, and the done bit is se (established)
pub mod csr_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x14;
    pub mod done { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod resource_select { // bits 1:0, established
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
/// Configuration ROM header. The upper 16 bits read as zero at reset. The low 16 bits hold the CRC, which is unspecified without a ROM. (established)
pub mod config_rom_header {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x18;
}
/// Constant BusID. The value is the ASCII text 1394. (established)
pub mod bus_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x1c;
}
/// Bus options. Bits 31:27, 23:16, 15:12 and 7:6 are writable. Link speed reads as 2. Bit 27 resets to zero. The max_rec field survives SoftReset with it (established)
pub mod bus_options {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x20;
    pub mod max_rec { // bits 15:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_speed { // bits 2:0, established
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
/// GUID high word. It reads as zero before a ROM load. Without a ROM each GUID register can be written once and then locks, and that lock state is separa (established)
pub mod guid_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x24;
}
/// GUID low word. The write-once rule for the high word applies here too. (established)
pub mod guid_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x28;
}
/// Configuration ROM mapping address. Bits 31:10 are read-write and reset to zero. (established)
pub mod config_rom_map {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x34;
}
/// Posted-write error address and source reporting, read and updated by the controller, at the offset and four bytes above it. The datasheet summary give (established)
pub mod posted_write_error {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x38;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4;
}
/// OHCI vendor-specific identifier. Read only, reads zero. (established)
pub mod vendor_specific_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x40;
}
/// HCControl. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 30 and 18 are unspecified at reset and th (established)
pub mod hc_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x50;
    pub mod no_byte_swap_data { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod program_phy_enable { // bits 23:23, established
        pub const SHIFT: u32 = 23;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod aphy_enhance_enable { // bits 22:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod lps { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod posted_write_enable { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_enable { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod soft_reset { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Self-ID buffer pointer. The address is 2 KiB aligned, so its low 11 bits read as zero. The address is unspecified at reset. (established)
pub mod self_id_buffer {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x64;
    pub mod address { // bits 31:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u32 = 0x1fffff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Self-ID count. The error and generation fields are unspecified at reset and the size field resets to zero. The controller updates the fields on bus ev (established)
pub mod self_id_count {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x68;
    pub mod error { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod generation { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod size { // bits 10:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u32 = 0x1ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Receive channel mask high, channels 32 to 63 (IRChannelMaskHiSet at 0x70 and its clear register at 0x74, Table 20 and Table 32). The set and clear add (established)
pub mod recv_channel_mask_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x70;
}
/// Receive channel mask low, channels 0 to 31 (IRChannelMaskLoSet at 0x78 and its clear register at 0x7c, Table 20). The set and clear addresses form a p (established)
pub mod recv_channel_mask_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x78;
}
/// Interrupt events. The set and clear addresses form a pair, the clear address four bytes above the set address. Reads of the clear register return the  (established)
pub mod int_event {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x80;
    pub mod phy_reg_received { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bus_reset { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod self_id_complete { // bits 16:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod iso_recv_summary { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod iso_xmit_summary { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Interrupt mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Reading either address of the pair return (established)
pub mod int_mask {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x88;
    pub mod master_int_enable { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Isochronous transmit event, one bit per context. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 7:0 (established)
pub mod iso_xmit_event {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x90;
    pub mod contexts { // bits 7:0, established
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
/// Isochronous transmit mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 7:0 are defined. The low  (established)
pub mod iso_xmit_mask {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x98;
    pub mod contexts { // bits 7:0, established
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
/// Isochronous receive event. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 3:0 are defined, one per  (established)
pub mod iso_recv_event {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa0;
    pub mod contexts { // bits 3:0, inferred
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
/// Isochronous receive mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bits 3:0 are defined. The low n (established)
pub mod iso_recv_mask {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xa8;
    pub mod contexts { // bits 3:0, inferred
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
/// Optional fairness control. The low byte is a read-only priority-request limit that resets to zero. The upper bits are unspecified at reset. (established)
pub mod fairness_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xdc;
    pub mod priority_request_limit { // bits 7:0, established
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
/// Link control. The set and clear addresses form a pair, the clear address four bytes above the set address. The defined bits are unspecified at reset a (established)
pub mod link_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xe0;
    pub mod cycle_source { // bits 22:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cycle_master { // bits 21:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cycle_timer_enable { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rcv_phy_packets { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rcv_self_id_packets { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Node ID. Validity, root and cable-power status are read and updated by the controller and reset to zero. The bus number resets to all ones. The physic (established)
pub mod node_id {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xe8;
    pub mod id_valid { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod root { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bus_number { // bits 15:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u32 = 0x3ff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node_number { // bits 5:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0x3f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// PHY access. A PHY read and a PHY write are mutually exclusive. Command bits read as zero at reset. Data and status fields are largely unspecified at r (established)
pub mod phy_control {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xec;
    pub mod rd_done { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rd_addr { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rd_data { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u32 = 0xff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rd_reg { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wr_reg { // bits 14:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reg_addr { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u32 = 0xf;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod wr_data { // bits 7:0, established
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
/// Cycle timer. Unspecified at reset. The counter fields count seconds, cycles and offset ticks at 24.576 MHz. (established)
pub mod cycle_timer {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0xf0;
    pub mod seconds { // bits 31:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u32 = 0x7f;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod count { // bits 24:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u32 = 0x1fff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod offset { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u32 = 0xfff;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Asynchronous request source filter, upper node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. Bit  (established)
pub mod async_filter_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x100;
    pub mod nonlocal_enable { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u32 = 0x1;
        pub const fn get(v: u32) -> u32 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u32, x: u32) -> u32 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Asynchronous request source filter, lower node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. (established)
pub mod async_filter_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x108;
}
/// Physical request source filter, upper node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. The filt (established)
pub mod phys_filter_hi {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x110;
}
/// Physical request source filter, lower node mask. The set and clear addresses form a pair, the clear address four bytes above the set address. (established)
pub mod phys_filter_lo {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x118;
}
/// Physical upper bound. It is optional and this part does not implement it, so it reads as zero. (established)
pub mod phys_upper_bound {
    pub const WIDTH: u32 = 32;
    pub const OFFSET: u64 = 0x120;
}
pub const BUS_ID_TEXT: u32 = 0x31333934; // established
pub const CYCLE_TIMER_CLOCK_HZ: u32 = 0x1770000; // established
pub const ISO_CHANNELS: u32 = 0x40; // established
pub const MAX_REC_DEFAULT: u32 = 0xa; // established
pub const PCI_DEVICE_ID: u32 = 0x8009; // established
pub const PCI_REVISION: u32 = 0x1; // established
pub const PCI_VENDOR_ID: u32 = 0x104c; // established
pub const PHY_CLOCK_HZ: u32 = 0x2ee0000; // established
pub const SELF_ID_BUFFER_ALIGN: u32 = 0x800; // established
