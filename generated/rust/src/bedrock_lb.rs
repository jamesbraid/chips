// generated from devices/bedrock_lb/registers.toml by defs-gen - do not edit, change the source
// Bedrock local block (LB) registers: field layouts, reset statements and the vector engine
#![allow(dead_code)]

pub mod enums {
    pub mod region_size {
        pub const FINE: u32 = 0; // established
        pub const COARSE: u32 = 1; // established
        pub const NMODE: u32 = 2; // established
        pub const INVALID: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Fine,
            Coarse,
            Nmode,
            Invalid,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Fine,
                    1 => Self::Coarse,
                    2 => Self::Nmode,
                    3 => Self::Invalid,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Fine => 0,
                    Self::Coarse => 1,
                    Self::Nmode => 2,
                    Self::Invalid => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod vector_op {
        pub const READ: u32 = 0; // established
        pub const WRITE: u32 = 1; // established
        pub const UNDEFINED: u32 = 2; // established
        pub const EXCHANGE: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Read,
            Write,
            Undefined,
            Exchange,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Read,
                    1 => Self::Write,
                    2 => Self::Undefined,
                    3 => Self::Exchange,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Read => 0,
                    Self::Write => 1,
                    Self::Undefined => 2,
                    Self::Exchange => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod vector_reply_type {
        pub const READ: u32 = 0; // established
        pub const WRITE: u32 = 1; // established
        pub const UNDEFINED: u32 = 2; // established
        pub const EXCHANGE: u32 = 3; // established
        pub const ADDRESS_ERROR: u32 = 4; // established
        pub const COMMAND_ERROR: u32 = 5; // established
        pub const PROTECTION_ERROR: u32 = 6; // established
        pub const UNKNOWN_ERROR: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Read,
            Write,
            Undefined,
            Exchange,
            AddressError,
            CommandError,
            ProtectionError,
            UnknownError,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Read,
                    1 => Self::Write,
                    2 => Self::Undefined,
                    3 => Self::Exchange,
                    4 => Self::AddressError,
                    5 => Self::CommandError,
                    6 => Self::ProtectionError,
                    7 => Self::UnknownError,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Read => 0,
                    Self::Write => 1,
                    Self::Undefined => 2,
                    Self::Exchange => 3,
                    Self::AddressError => 4,
                    Self::CommandError => 5,
                    Self::ProtectionError => 6,
                    Self::UnknownError => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Revision and identity. The header says this register carries the chip identity and sets the node's ID and the size of each region. The manufacturer, p (established)
pub mod rev_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600000;
    pub mod region_size { // bits 47:46, established
        pub const SHIFT: u32 = 46;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::region_size::Value;
    }
    pub mod node_id { // bits 39:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod revision { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod part_number { // bits 27:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod manufacturer { // bits 11:1, established
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
/// Processor PIO access permission, one bit per region. A region whose bit is clear gets no write access to the local block, network interface, crossbar  (established)
pub mod cpu_permission {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604000;
    pub mod region_enable { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Writing the 64-bit ASCII key the SN1 header names sets the writer's own region bit in cpu_permission. The key is not reproduced here. Reset unknown. (established)
pub mod cpu_permission_override {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604008;
}
/// The same per-region access vector as cpu_permission, applied to accesses that come from the I/O interface side rather than from a processor. Reset unk (established)
pub mod io_permission {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604010;
    pub mod region_enable { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// A write to bit 0 resets the Bedrock with a soft reset. The header does not say which state survives it. Reset unknown. (established)
pub mod soft_reset {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604018;
    pub mod soft_reset { // bits 0:0, established
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
/// Regions that can receive an invalidate. The block samples it when an invalidate arrives. If an invalidate names a processor interface in a region whos (established)
pub mod region_present {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604020;
    pub mod present { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Four 16-bit entries, one per slot. Each entry holds a node number in its low eight bits and a valid bit at bit 15. A node listed with its valid bit se (established)
pub mod nodes_absent {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604028;
    pub mod entry3_valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod entry3_node { // bits 55:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod entry2_valid { // bits 47:47, established
        pub const SHIFT: u32 = 47;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod entry2_node { // bits 39:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod entry1_valid { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod entry1_node { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod entry0_valid { // bits 15:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod entry0_node { // bits 7:0, established
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
/// Control for a one-wire serial bus to the node board's add-only serial PROM. The header names the part as a Dallas 1990A and says the PROM holds the no (established)
pub mod microlan_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604030;
    pub mod clkdiv_phi1 { // bits 33:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod clkdiv_phi0 { // bits 26:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod low_pulse { // bits 19:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sample_offset { // bits 9:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod done { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod read_data { // bits 0:0, established
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
/// Local-block error bits. Reads do not change them. A write sets the bits it names. Any set bit raises the block's error request to both processor inter (established)
pub mod error_bits {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604040;
    pub mod gclk_drop { // bits 10:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rq_bad_inval { // bits 9:9, established
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rq_bad_addr { // bits 8:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rp_bad_data { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rq_bad_data { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rp_long { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rq_long { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rp_short { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rq_short { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rp_bad_cmd { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rq_bad_cmd { // bits 0:0, established
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
/// Write one to clear the matching error bits. A zero bit in the written value leaves its error bit alone, so any subset clears atomically. Reset unknown (established)
pub mod error_mask_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604048;
    pub mod clear { // bits 10:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Header of the first packet that caused an error. It is captured while valid is clear, and valid is then set. A later error while valid is set sets ove (established)
pub mod error_hdr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604050;
    pub mod valid { // bits 44:44, established
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 40:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod err_type { // bits 35:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod source { // bits 30:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod suppl { // bits 18:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod command { // bits 6:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Address field from the header of the first packet that caused an error. Not relevant for a global clock drop. Reset unknown. (established)
pub mod error_hdr2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604058;
    pub mod address { // bits 37:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3fffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Data flit of the first erroring packet, for the error kinds that carry data. Reset unknown. (established)
pub mod error_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604060;
    pub mod flit { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Chooses which internal signals appear on the debug pins. The header gives no list of the choices. Reset unknown. (established)
pub mod debug_select {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604100;
    pub mod select { // bits 5:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Value on the chip's debug pins. Reset unknown. (established)
pub mod debug_pins {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604108;
    pub mod pins { // bits 31:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Local source of the real-time clock. The local block gives the clock to both processor interfaces. With use_internal set it generates the clock from t (established)
pub mod rt_local_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604200;
    pub mod use_internal { // bits 32:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gclk { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gclk_counter { // bits 25:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod max_count { // bits 13:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod gclk_enable { // bits 0:0, established
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
/// Filtering of an incoming global clock, used when rt_local_ctrl use_internal is clear. Simple filtering drops single-cycle glitches. Complex filtering  (established)
pub mod rt_filter_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x604208;
    pub mod error_counter { // bits 57:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dropout_threshold { // bits 45:36, established
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dropout_counter { // bits 33:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mask_enable { // bits 20:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mask_counter { // bits 19:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod offset { // bits 4:0, established
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
/// Plain storage. The header says it is reset to zero. (established)
pub mod scratch0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608000;
    pub mod bits { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Plain storage. The header says it is not reset, and does not name the reset it means. Reset unknown. (established)
pub mod scratch1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608008;
    pub mod bits { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Plain storage. The header says it is not reset, and does not name the reset it means. Reset unknown. (established)
pub mod scratch2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608010;
    pub mod bits { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// One-bit storage (bit 0 of a 64-bit word). The header gives no reset value. The public Linux ia64 L1 driver uses it as a hub-wide lock: it releases the (established)
pub mod scratch3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608018;
    pub mod bit { // bits 0:0, established
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
/// One-bit storage (bit 0 of a 64-bit word). The header gives no reset value, and the public Linux tree shows no use of it. Reset unknown. (established)
pub mod scratch4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608020;
    pub mod bit { // bits 0:0, established
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
/// Write-if-zero alias of scratch 0. A write is accepted only when the current value is zero. (established)
pub mod scratch0_wz {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608040;
    pub mod bits { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Write-if-zero alias of scratch 1. A write is accepted only when the current value is zero. (established)
pub mod scratch1_wz {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608048;
    pub mod bits { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Write-if-zero alias of scratch 2. A write is accepted only when the current value is zero. (established)
pub mod scratch2_wz {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608050;
    pub mod bits { // bits 63:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xffffffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Read-set-if-zero alias of scratch 3 (one bit, bit 0 of a 64-bit word). A read returns the old value and sets the bit when it was zero, so a single rea (established)
pub mod scratch3_rz {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608058;
    pub mod bit { // bits 0:0, established
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
/// Read-set-if-zero alias of scratch 4 (one bit). A read returns the old value and sets the bit when it was zero. (established)
pub mod scratch4_rz {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608060;
    pub mod bit { // bits 0:0, established
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
/// Vector I/O request parameters. A write sends one request, and the block replies to the write at once without waiting for the operation. The request is (established)
pub mod vector_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60c000;
    pub mod busy { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pio_id { // bits 50:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_id { // bits 39:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod address { // bits 23:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 1:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::vector_op::Value;
    }
}
/// Outgoing vector route for the next request. The header gives no field layout. Reset unknown. (established)
pub mod vector_route {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60c008;
}
/// Write data for an outgoing vector write, and the data value for a read reply. Reset unknown. (established)
pub mod vector_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60c010;
}
/// Return status of the last vector request. Software clears it before launching a request. The block leaves the fields unchanged when a reply has an err (established)
pub mod vector_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60c020;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod source { // bits 61:51, established
        pub const SHIFT: u32 = 51;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pio_id { // bits 50:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_id { // bits 39:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod address { // bits 23:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod type_or_error { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::vector_reply_type::Value;
    }
}
/// Return route from the last reply. The block stores it only for an error-free reply that arrives while valid is clear. Reset unknown. (established)
pub mod vector_return {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60c028;
}
/// Read data from the last reply, under the same update rule as vector_return. Reset unknown. (established)
pub mod vector_read_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60c030;
}
/// Clear the vector status. The header gives the same field layout as vector_status and says only that this register clears it. It does not say whether a (established)
pub mod vector_status_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60c038;
    pub mod valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod source { // bits 61:51, established
        pub const SHIFT: u32 = 51;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pio_id { // bits 50:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_id { // bits 39:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod address { // bits 23:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod type_or_error { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::vector_reply_type::Value;
    }
}
pub const CHIP_PART_BEDROCK: u32 = 0x3012; // established
pub const ERROR_PI_PEND1_BIT: u32 = 0x37; // established
pub const REVISION_1_0: u32 = 0x1; // established
pub const REVISION_1_1: u32 = 0x2; // established
pub const RTC_FREQ_KHZ_CONFIG: u32 = 0x4e2; // inferred
