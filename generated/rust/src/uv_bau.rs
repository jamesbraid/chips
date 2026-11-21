// generated from devices/uv_bau/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 2daabcb00ca4cf0ccb9e7ae19034116a669196719e08dfd2559a070a278bfaa3
// UV broadcast assist unit (BAU): descriptor, payload queue and constants
#![allow(dead_code)]

/// High dword of the UV2 and UV3 message header, bit positions counted from the dword (header bit minus 64). (established)
pub mod desc_hdr_hi {
    pub const WIDTH: u32 = 64;
    pub mod command { // bits 63:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod multilevel { // bits 31:31, established
        pub const SHIFT: u32 = 31;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod chaining { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sequence { // bits 29:14, established
        pub const SHIFT: u32 = 14;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fairness { // bits 13:11, established
        pub const SHIFT: u32 = 11;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Low dword of the UV2 and UV3 message header (descriptor bytes 0x30 to 0x37, the message header at the top of the 64-byte descriptor). Only fields the  (established)
pub mod desc_hdr_lo {
    pub const WIDTH: u32 = 64;
    pub mod swack_flag { // bits 52:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod canceled { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod msg_type { // bits 24:22, established
        pub const SHIFT: u32 = 22;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod replied_to { // bits 21:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod dest_subnodeid { // bits 19:15, established
        pub const SHIFT: u32 = 15;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base_dest_nasid { // bits 14:0, established
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
pub const DESC_BYTES: u32 = 0x40; // established
pub const DESC_QUALIFIER: u32 = 0x534749; // established
pub const DISTRIBUTION_BITS: u32 = 0x100; // established
pub const DS_ACTIVE: u32 = 0x1; // established
pub const DS_DESTINATION_TIMEOUT: u32 = 0x2; // established
pub const DS_IDLE: u32 = 0x0; // established
pub const DS_SOURCE_TIMEOUT: u32 = 0x3; // established
pub const ITEMS_PER_SET: u32 = 0x8; // established
pub const LB_SUBNODEID: u32 = 0x10; // established
pub const MSG_NOOP: u32 = 0x0; // established
pub const MSG_REGULAR: u32 = 0x1; // established
pub const MSG_RETRY: u32 = 0x2; // established
pub const NUM_SETS: u32 = 0x40; // established
pub const PAYLOADQ_GNODE_SHIFT: u32 = 0x31; // established
pub const PAYLOAD_QUEUE_ENTRIES: u32 = 0x14; // established
pub const PAYLOAD_QUEUE_ENTRY_BYTES: u32 = 0x20; // established
pub const SW_ACK_RESOURCES: u32 = 0x8; // established
pub const UV1_ENDPOINT_COMMAND: u32 = 0x38; // established
pub const UV1_SOFT_ACK_PERIOD: u32 = 0x9; // established
pub const UV2_DESC_BUSY: u32 = 0x2; // established
pub const UV2_DESC_DEST_PUT_ERR: u32 = 0x7; // established
pub const UV2_DESC_DEST_STRONG_NACK: u32 = 0x5; // established
pub const UV2_DESC_DEST_TIMEOUT: u32 = 0x4; // established
pub const UV2_DESC_IDLE: u32 = 0x0; // established
pub const UV2_DESC_SOURCE_TIMEOUT: u32 = 0x6; // established
pub const UV2_ENDPOINT_COMMAND: u32 = 0x28; // established
pub const UV2_SOFT_ACK_PERIOD: u32 = 0xf; // established
