// generated from defs/bedrock_md.toml by defs-gen - do not edit, change the source
// Bedrock memory and directory (MD) registers: field layouts, reset statements, error records and backdoor carriers
#![allow(dead_code)]

pub mod enums {
    pub mod dir_format {
        pub const UNOWNED: u32 = 0; // established
        pub const POINTER: u32 = 1; // established
        pub const SHARED_FINE: u32 = 2; // established
        pub const SHARED_COARSE: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Unowned,
            Pointer,
            SharedFine,
            SharedCoarse,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Unowned,
                    1 => Self::Pointer,
                    2 => Self::SharedFine,
                    3 => Self::SharedCoarse,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Unowned => 0,
                    Self::Pointer => 1,
                    Self::SharedFine => 2,
                    Self::SharedCoarse => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod dir_pointer_state {
        pub const EXCLUSIVE: u32 = 0; // established
        pub const BUSY_SHARED: u32 = 4; // established
        pub const BUSY_EXCLUSIVE: u32 = 5; // established
        pub const WAIT: u32 = 6; // established
        pub const POISONED: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Exclusive,
            BusyShared,
            BusyExclusive,
            Wait,
            Poisoned,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Exclusive,
                    4 => Self::BusyShared,
                    5 => Self::BusyExclusive,
                    6 => Self::Wait,
                    7 => Self::Poisoned,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Exclusive => 0,
                    Self::BusyShared => 4,
                    Self::BusyExclusive => 5,
                    Self::Wait => 6,
                    Self::Poisoned => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod size_code {
        pub const EMPTY: u32 = 0; // inferred
        pub const MB64: u32 = 1; // inferred
        pub const MB128: u32 = 2; // inferred
        pub const MB256: u32 = 3; // inferred
        pub const MB512: u32 = 4; // inferred
        pub const GB1: u32 = 5; // inferred
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Empty,
            Mb64,
            Mb128,
            Mb256,
            Mb512,
            Gb1,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Empty,
                    1 => Self::Mb64,
                    2 => Self::Mb128,
                    3 => Self::Mb256,
                    4 => Self::Mb512,
                    5 => Self::Gb1,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Empty => 0,
                    Self::Mb64 => 1,
                    Self::Mb128 => 2,
                    Self::Mb256 => 3,
                    Self::Mb512 => 4,
                    Self::Gb1 => 5,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Access-rights vector. A region whose bit is set is inside the cell and uses the directory's local-access protection instead of per-region protection.  (established)
pub mod current_cell {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780000;
    pub mod region_bits { // bits 63:0, established
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
/// Memory configuration. Each DIMM position d has a byte at bits 8d+7 to 8d holding two bank enables, a DRAM width bit and a size code. Addresses beyond  (established)
pub mod memory_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780008;
    pub mod rcd_rp_config { // bits 61:60, established
        pub const SHIFT: u32 = 60;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod timing_high { // bits 58:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod timing_low { // bits 53:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ignore_cpu_protection { // bits 47:47, established
        pub const SHIFT: u32 = 47;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ignore_io_protection { // bits 46:46, established
        pub const SHIFT: u32 = 46;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod io_protection_enable { // bits 45:45, established
        pub const SHIFT: u32 = 45;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cell_protection_enable { // bits 44:44, established
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bank_select { // bits 33:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos3_size { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::size_code::Value;
    }
    pub mod pos3_width { // bits 27:27, established
        pub const SHIFT: u32 = 27;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos3_enables { // bits 25:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos2_size { // bits 23:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::size_code::Value;
    }
    pub mod pos2_width { // bits 19:19, established
        pub const SHIFT: u32 = 19;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos2_enables { // bits 17:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos1_size { // bits 15:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::size_code::Value;
    }
    pub mod pos1_width { // bits 11:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos1_enables { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos0_size { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::size_code::Value;
    }
    pub mod pos0_width { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pos0_enables { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Arbitration control. The arbitration timing is not specified by the header. Reset unknown. (established)
pub mod arbitration_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780010;
    pub mod write_guarantee { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reply_guarantee { // bits 3:0, established
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
/// Page-migration configuration. The header names the interval, node mask and enable. Interval units and the scheduling rule are not given. Reset unknown (established)
pub mod migration_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780018;
    pub mod enable { // bits 32:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod node_mask { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod interval { // bits 9:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Fetch-and-op cache status 0: a captured cache entry. Guest write behaviour is not given. Reset unknown. (established)
pub mod fetchop_cache_status0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780020;
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
    pub mod address { // bits 32:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x7ffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Fetch-and-op cache status 1: a second captured cache entry with the same layout as status 0. Reset unknown. (established)
pub mod fetchop_cache_status1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780028;
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
    pub mod address { // bits 32:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x7ffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Miscellaneous error word 0: message header fields and two-bit error flags. The field positions are not summarised here. Reset unknown. (established)
pub mod misc_error0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780040;
}
/// Miscellaneous error word 1: a 38-bit address and the same style of flags. The field positions are not summarised here. Reset unknown. (established)
pub mod misc_error1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780048;
}
/// Clear alias of miscellaneous error word 1. The header names it a clear register without saying whether a read or a write clears it. The one consumer r (established)
pub mod misc_error1_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780058;
}
/// Reply-queue credit sizes, all read-only fields. The header gives 12 header entries and 24 data entries as the defaults for each queue. A write resets  (established)
pub mod outgoing_reply_queue_size {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x780060;
    pub mod third_data_queue { // bits 52:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pi1_data_queue { // bits 44:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pi0_data_queue { // bits 36:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod third_header_queue { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pi1_header_queue { // bits 19:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pi0_header_queue { // bits 11:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Performance counter 0 selection. Complete event encodings and interrupt cadence are not given by the header. Reset unknown. (established)
pub mod perf_select0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x790000;
    pub mod interrupt { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod command { // bits 59:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod channel { // bits 19:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod source { // bits 14:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod activity { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Performance counter 1 selection, with the same layout as counter 0. Reset unknown. (established)
pub mod perf_select1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x790008;
    pub mod interrupt { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod command { // bits 59:20, established
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0xffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod channel { // bits 19:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod source { // bits 14:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod activity { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Performance counter 0. The header describes a 41-bit count; the events that advance it are not given. The Itanium console code and the boot firmware o (established)
pub mod perf_counter0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x790010;
    pub mod count { // bits 40:0, established
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
/// Performance counter 1. The same 41-bit count layout as counter 0. Reset unknown. (established)
pub mod perf_counter1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x790018;
    pub mod count { // bits 40:0, established
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
/// Refresh control. Once the memory configuration holds the DIMM information, the hardware refreshes every bank. If a refresh window expires with banks u (established)
pub mod refresh_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0000;
    pub mod enable { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod live_counter { // bits 23:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold { // bits 11:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Junk-bus timing for the flash PROM, the L1 UART and a device the Linux header names Synergy. The header names the timing fields; it does not place the (established)
pub mod junk_bus_timing {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0008;
    pub mod synergy_enable { // bits 47:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod synergy_setup_hold { // bits 39:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart_enable { // bits 31:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart_setup_hold { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flash_enable { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod flash_setup_hold { // bits 7:0, established
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
/// Reads the value on LED bank 0. The header says a read of this register gives the 8-bit LED value. Whether a write drives the LEDs is not stated. Reset (established)
pub mod led0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0010;
    pub mod data { // bits 7:0, established
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
/// Reads the value on LED bank 1. Otherwise as LED bank 0. (established)
pub mod led1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0018;
    pub mod data { // bits 7:0, established
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
/// Reads the value on LED bank 2. Otherwise as LED bank 0. (established)
pub mod led2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0020;
    pub mod data { // bits 7:0, established
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
/// Reads the value on LED bank 3. Otherwise as LED bank 0. (established)
pub mod led3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0028;
    pub mod data { // bits 7:0, established
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
/// Self-test control. Command precedence, self-clearing behaviour, the algorithm and the duration are unresolved. A retained write cannot qualify a compl (established)
pub mod self_test_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0030;
    pub mod dimm { // bits 6:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bank { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reset { // bits 2:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod stop { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod start { // bits 0:0, established
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
/// Self-test data and pattern control. The header gives the control names, not their full transformation rules. (established)
pub mod self_test_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0038;
    pub mod write_control { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod cycle_control { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod byte_control { // bits 5:5, established
        pub const SHIFT: u32 = 5;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod nibble_control { // bits 4:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod initial_pattern { // bits 3:0, established
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
/// Self-test error address: the failing column and row, and which block failed. Guest writes and the clearing mechanism are unresolved. (established)
pub mod self_test_error_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0040;
    pub mod directory_error { // bits 49:49, established
        pub const SHIFT: u32 = 49;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod memory_error { // bits 48:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod row { // bits 46:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7fff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod memory_column { // bits 30:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7fff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod directory_column { // bits 14:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Self-test status. Reports the result of the test. Neither bit is meaningful until the test has run to completion. (established)
pub mod self_test_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0048;
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
    pub mod passed { // bits 0:0, established
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
/// Issue-block debug selector. The prose gives three bits while both endian layouts declare two. The width conflict is open. The meanings of the selectio (established)
pub mod issue_debug_select {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7a0060;
    pub mod selection { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Directory configuration. Bit 0 selects the premium directory format, and bit 1 ignores directory ECC. The register survives a soft reset. Reset unknow (established)
pub mod dir_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0000;
    pub mod ignore_dir_ecc { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod premium { // bits 0:0, established
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
/// Directory error record. The address and syndrome belong to the highest-priority kind latched: uncorrectable above protection above correctable. Reset  (established)
pub mod dir_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0010;
    pub mod uncorrectable_valid { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod protection_double_valid { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod correctable_valid { // bits 61:61, established
        pub const SHIFT: u32 = 61;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod protection_correctable_valid { // bits 60:60, established
        pub const SHIFT: u32 = 60;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uncorrectable_overrun { // bits 59:59, established
        pub const SHIFT: u32 = 59;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod protection_double_overrun { // bits 58:58, established
        pub const SHIFT: u32 = 58;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod correctable_overrun { // bits 57:57, established
        pub const SHIFT: u32 = 57;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod protection_correctable_overrun { // bits 56:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod protection_index { // bits 54:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_protection { // bits 51:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syndrome { // bits 46:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod hub_special_address { // bits 32:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x3fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Clear alias of the directory error record. The header repeats the base register's text and names no mechanism. Read-to-clear is the consumer's expecta (established)
pub mod dir_error_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0018;
}
/// Protocol error record: directory state and format, pointer, message type, initiator, valid and overrun. The field positions are not summarised here. R (established)
pub mod protocol_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0020;
}
/// Clear alias of the protocol error record. The mechanism is not stated. (established)
pub mod protocol_error_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0028;
}
/// Page-migration candidate. On overrun the newest candidate replaces the earlier one. The clear operation is not established by the header's repeated te (established)
pub mod mig_candidate {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0030;
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
    pub mod local { // bits 34:34, established
        pub const SHIFT: u32 = 34;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold_type { // bits 33:33, established
        pub const SHIFT: u32 = 33;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 32:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod initiator { // bits 31:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod page_address { // bits 20:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Clear alias of the migration candidate. Software reads only this alias and never the base register. That reading removes the candidate is inferred; th (established)
pub mod mig_candidate_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0038;
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
    pub mod local { // bits 34:34, established
        pub const SHIFT: u32 = 34;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold_type { // bits 33:33, established
        pub const SHIFT: u32 = 33;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod overrun { // bits 32:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod initiator { // bits 31:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x7ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod page_address { // bits 20:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x1fffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Page-migration difference threshold. A valid threshold is reached when the difference between the requester's count and the home count is at least the (established)
pub mod mig_diff_thresh {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0040;
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
    pub mod saturation_action { // bits 37:35, established
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold_action { // bits 34:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold { // bits 14:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Page-migration value threshold. Software writes it with bit 63 set and the local interrupt enable and action fields clear. Whether bits 18 to 15 are i (established)
pub mod mig_value_thresh {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0048;
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
    pub mod local_interrupt_enable { // bits 62:62, established
        pub const SHIFT: u32 = 62;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod saturation_action { // bits 37:35, established
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold_action { // bits 34:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod threshold { // bits 14:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Outgoing request-queue size. Each field defaults to four and has a maximum of four. A header occupies one entry. Writes above four and the side effect (established)
pub mod outgoing_request_queue_size {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0050;
    pub mod third_request_queue { // bits 26:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pi1_request_queue { // bits 18:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pi0_request_queue { // bits 10:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Failing directory word captured by the self-test. Guest writes are not established. (established)
pub mod selftest_dir_error_data {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0058;
    pub mod word { // bits 31:0, established
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
/// Directory-block debug selector. The meanings of the selections come from a separate design specification that is not held. (established)
pub mod dir_debug_select {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7c0060;
    pub mod selection { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory-block ECC configuration. Bit 0 ignores data ECC. Reset unknown. (established)
pub mod mb_ecc_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0000;
    pub mod ignore_data_ecc { // bits 0:0, established
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
/// Memory error record: an address, a syndrome and a valid and overrun flag pair for each of three kinds. The address and syndrome belong to the earliest (established)
pub mod mem_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0010;
    pub mod differing_address { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod read_uncorrectable_flags { // bits 61:60, inferred
        pub const SHIFT: u32 = 60;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_uncorrectable_flags { // bits 57:56, inferred
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod read_correctable_flags { // bits 53:52, inferred
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod syndrome { // bits 47:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod address { // bits 32:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x3fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Clear alias of the memory error record. The header repeats the base register's text and names no mechanism. Read-to-clear is the consumer's expectatio (established)
pub mod mem_error_clr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0018;
}
/// Self-test captured memory data, quarter 0 of the failing line. (established)
pub mod selftest_mem_error_data0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0020;
    pub mod word { // bits 35:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Self-test captured memory data, quarter 1 of the failing line. (established)
pub mod selftest_mem_error_data1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0028;
    pub mod word { // bits 35:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Self-test captured memory data, quarter 2 of the failing line. (established)
pub mod selftest_mem_error_data2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0030;
    pub mod word { // bits 35:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Self-test captured memory data, quarter 3 of the failing line. (established)
pub mod selftest_mem_error_data3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0038;
    pub mod word { // bits 35:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0xfffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory-block debug selector. The meaning of the selection requires the separate design specification. (established)
pub mod mem_debug_select {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7e0040;
    pub mod selection { // bits 0:0, established
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
/// Directory word in the pointer format. Bits 1:0 hold the format, which is the same in both flavors. In a premium word bits 24:22 extend the pointer to  (established)
pub mod dir_entry_pointer {
    pub const WIDTH: u32 = 64;
    pub mod first_pointer_high { // bits 24:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod first_pointer { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod state { // bits 4:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::dir_pointer_state::Value;
    }
    pub mod format { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::dir_format::Value;
    }
}
/// Directory word in the shared-fine format. In this format a vector bit stands for one processor interface, not one processor. (established)
pub mod dir_entry_shared_fine {
    pub const WIDTH: u32 = 64;
    pub mod first_vector_high { // bits 31:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod first_tag_high { // bits 23:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod first_vector { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod first_tag { // bits 4:2, established
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod format { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::dir_format::Value;
    }
}
pub const DIMM_POSITIONS: u32 = 0x4; // established
pub const DIR_BACKDOOR_EIGHTHS: u32 = 0x7; // established
pub const DIR_LINE_BYTES: u32 = 0x80; // established
pub const DIR_WORD_STRIDE: u32 = 0x10; // established
pub const ECC_BACKDOOR_EIGHTHS: u32 = 0x5; // established
pub const INTR_CORRECTABLE_MEM_BIT: u32 = 0x3d; // established
pub const INTR_UNCORRECTABLE_MEM_BIT: u32 = 0x18; // established
pub const MD_WINDOW_BASE_UNITS: u32 = 0x1fc; // established
pub const MD_WINDOW_BASE_UNIT_SHIFT: u32 = 0x10; // established
pub const PAGE_COUNTER_OFFSET: u32 = 0x8; // established
pub const PHYSICAL_BANKS_PER_DIMM: u32 = 0x2; // established
pub const PROTECTION_ENTRY_OFFSET: u32 = 0x408; // established
pub const PTR_DEVICE_MASK: u32 = 0x7; // established
pub const PTR_NODE_SHIFT: u32 = 0x3; // established
pub const REFRESH_CYCLES_PER_4096: u32 = 0xc35; // established
pub const REFRESH_INTERVAL_BOOK_NS: u32 = 0x1f40; // established
pub const SCRUB_BACKDOOR_EIGHTHS: u32 = 0x4; // established
pub const SOFTWARE_BANKS: u32 = 0x8; // established
pub const SOFTWARE_BANK_BYTES: u32 = 0x40000000; // established
