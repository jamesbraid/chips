// generated from devices/router_origin3000_rbrick/registers.toml by defs-gen - do not edit, change the source
// Origin 3000 R-brick router registers outside the census (vector space)
#![allow(dead_code)]

pub mod enums {
    pub mod link_state {
        pub const WENTDOWN: u32 = 0; // inferred
        pub const RESETFAIL: u32 = 1; // inferred
        pub const LINKUP: u32 = 2; // inferred
        pub const NOTUSED: u32 = 3; // inferred
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Wentdown,
            Resetfail,
            Linkup,
            Notused,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Wentdown,
                    1 => Self::Resetfail,
                    2 => Self::Linkup,
                    3 => Self::Notused,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Wentdown => 0,
                    Self::Resetfail => 1,
                    Self::Linkup => 2,
                    Self::Notused => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Status word. The kernel refuses a chip whose part field is not the router part, reads the revision from the top nibble, and treats a port as active wh (inferred)
pub mod status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x0;
    pub mod link8_state { // bits 51:50, inferred
        pub const SHIFT: u32 = 50;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod link7_state { // bits 49:48, inferred
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod link6_state { // bits 47:46, inferred
        pub const SHIFT: u32 = 46;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod link5_state { // bits 45:44, inferred
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod link4_state { // bits 43:42, inferred
        pub const SHIFT: u32 = 42;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod link3_state { // bits 41:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod link2_state { // bits 39:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod link1_state { // bits 37:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::link_state::Value;
    }
    pub mod rev { // bits 31:28, inferred
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod chip { // bits 27:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Protection configuration. Each low bit lets a reset arriving on that link through. The census gives the access and offset of the same word; the field  (inferred)
pub mod prot_conf {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10;
    pub mod dir_compare_off { // bits 13:13, inferred
        pub const SHIFT: u32 = 13;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod force_local { // bits 12:12, inferred
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod meta_id { // bits 11:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod reset_ok { // bits 7:0, inferred
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
/// Position word that discovery reads to classify a router. A clear bit marks a metarouter or a repeat router. The census does not name this offset. (inferred)
pub mod position {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50;
    pub mod repeater_flag { // bits 21:21, inferred
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod meta_flag { // bits 20:20, inferred
        pub const SHIFT: u32 = 20;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Scratch register 3. Bit 0 is the router lock: writing 0 releases it. The header names this word as the scratch register itself. (inferred)
pub mod scratch3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x118;
    pub mod lock { // bits 0:0, inferred
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
/// Set-if-zero alias of scratch register 3. A read returns the old lock bit and sets it, so the firmware takes the lock by reading it until the read retu (inferred)
pub mod scratch3_setzero {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x518;
    pub mod lock { // bits 0:0, inferred
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
/// Error status of link 1. The layout is the one the public header gives and the firmware's error decoder prints. The order of the three low flags is not (inferred)
pub mod error_link1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10008;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 1. Bit n-1 names a link n. The direction in which the mask applies is inferred, not established. (inferred)
pub mod reset_mask_link1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10018;
    pub mod reset_ok { // bits 7:0, inferred
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
/// Error status of link 2. Same layout as link 1. (inferred)
pub mod error_link2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10808;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 2. Same layout as link 1. (inferred)
pub mod reset_mask_link2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10818;
    pub mod reset_ok { // bits 7:0, inferred
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
/// Error status of link 3. Same layout as link 1. (inferred)
pub mod error_link3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20008;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 3. Same layout as link 1. (inferred)
pub mod reset_mask_link3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20018;
    pub mod reset_ok { // bits 7:0, inferred
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
/// Error status of link 4. Same layout as link 1. (inferred)
pub mod error_link4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20808;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 4. Same layout as link 1. (inferred)
pub mod reset_mask_link4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20818;
    pub mod reset_ok { // bits 7:0, inferred
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
/// Error status of link 5. Same layout as link 1. (inferred)
pub mod error_link5 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30008;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 5. Same layout as link 1. (inferred)
pub mod reset_mask_link5 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30018;
    pub mod reset_ok { // bits 7:0, inferred
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
/// Error status of link 6. Same layout as link 1. (inferred)
pub mod error_link6 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30808;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 6. Same layout as link 1. (inferred)
pub mod reset_mask_link6 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30818;
    pub mod reset_ok { // bits 7:0, inferred
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
/// Error status of link 7. Same layout as link 1. (inferred)
pub mod error_link7 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40008;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 7. Same layout as link 1. (inferred)
pub mod reset_mask_link7 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40018;
    pub mod reset_ok { // bits 7:0, inferred
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
/// Error status of link 8. Same layout as link 1. (inferred)
pub mod error_link8 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40808;
    pub mod power_not_ok { // bits 38:38, inferred
        pub const SHIFT: u32 = 38;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod deadlock { // bits 37:37, inferred
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod warm_reset_rx { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset_rx { // bits 35:35, inferred
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_rx_illegal { // bits 34:32, unknown
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Reset mask of link 8. Same layout as link 1. The eight mask addresses are not linear: links come in pairs 64 KiB apart, with the second link of a pair (inferred)
pub mod reset_mask_link8 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40818;
    pub mod reset_ok { // bits 7:0, inferred
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
pub const L1_ROUTER_TYPE_META: u32 = 0xe; // inferred
pub const L1_ROUTER_TYPE_ORDINARY: u32 = 0xf; // inferred
pub const L1_ROUTER_TYPE_REPEATER: u32 = 0xc; // inferred
pub const L1_SETTING_ROUTER_TYPE: u32 = 0x3c; // inferred
pub const ROUTER_CHIP_PART: u32 = 0x3017; // inferred
pub const ROUTER_DEST_IDS: u32 = 0x200; // established
pub const ROUTER_ENABLED_PORTS_SIX: u32 = 0x6; // established
pub const ROUTER_LOCAL_TABLE_ENTRIES: u32 = 0x10; // established
pub const ROUTER_PORTS: u32 = 0x8; // established
pub const ROUTER_REMOTE_TABLE_ENTRIES: u32 = 0x20; // established
pub const ROUTER_USB_PORT_FIRST: u32 = 0x2; // established
pub const ROUTER_USB_PORT_LAST: u32 = 0x5; // established
pub const ROUTER_VCS_PER_PORT: u32 = 0x4; // established
