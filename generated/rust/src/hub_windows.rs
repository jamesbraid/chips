// @generated from devices/hub_windows/registers.toml by defs-gen - do not edit, change the source
// defs-gen 4
// input sha256 433dec6921b0152c218127b867a36172e0ae5ba71149fa793336f17dac3023f3
// Hub register arrays whose extent is a fact of its own
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

pub mod enums {
    pub mod iio_prb_mode {
        pub const NORMAL: u32 = 0; // established
        pub const COLLECT_A: u32 = 1; // established
        pub const SERVICE_A: u32 = 2; // established
        pub const SERVICE_B: u32 = 3; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Normal,
            CollectA,
            ServiceA,
            ServiceB,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Normal,
                    1 => Self::CollectA,
                    2 => Self::ServiceA,
                    3 => Self::ServiceB,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Normal => 0,
                    Self::CollectA => 1,
                    Self::ServiceA => 2,
                    Self::ServiceB => 3,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then  (established)
pub mod pi_gfx_window {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300;
    pub const COUNT: u32 = 10;
    pub const STRIDE: u64 = 8;
}
/// The six memory/directory performance counters as one array. The header gives no access type, so rw is an assumption. (inferred)
pub mod md_perf_cnt {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x210010;
    pub const COUNT: u32 = 6;
    pub const STRIDE: u64 = 8;
}
/// The eight microcontroller and UART 0 registers as one array. The same storage is listed one by one where the census reaches it. The header gives no ac (inferred)
pub mod md_ureg0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220000;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
}
/// The sixteen microcontroller and UART 1 registers as one array. They are also listed one by one under their own names; this is the same storage seen as (established)
pub mod md_ureg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220080;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
}
/// The nine I/O partial-request buffer entries (0, then 8 to f) as one array; entry 0 sits at the first offset and entries 8 to f follow, eight bytes apa (inferred)
pub mod iio_ioprb {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400198;
    pub const COUNT: u32 = 9;
    pub const STRIDE: u64 = 8;
    pub mod error { // bits 48:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ovflow { // bits 47:43, established
        pub const SHIFT: u32 = 43;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod fire_and_forget { // bits 42:42, established
        pub const SHIFT: u32 = 42;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod mode { // bits 41:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        #[allow(unused_imports)]
        pub use super::super::enums::iio_prb_mode::Value;
    }
    pub mod bnakctr { // bits 37:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x3fff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod anakctr { // bits 21:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3fff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod xtalkctr { // bits 7:0, established
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
/// The eight PIO read address table entries as one array. The header gives no access type, so rw is an assumption. (inferred)
pub mod iio_prte {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400308;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
    pub mod valid { // bits 56:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod srcnode { // bits 54:46, established
        pub const SHIFT: u32 = 46;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod initiator { // bits 45:44, established
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod addr { // bits 40:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x3fffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// The eight network age-control registers as one array: CPU 0 memory, CPU 0 PIO, CPU 1 memory, CPU 1 PIO, GBR memory, GBR PIO, I/O memory, I/O PIO, in t (inferred)
pub mod ni_age {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600500;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
}
/// The 32-entry meta routing table as one array, replacing the split of the first entry and the other 31. Each entry holds the exit port. The header give (inferred)
pub mod ni_meta_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638000;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 8;
    pub mod exit_port { // bits 3:0, established
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
/// The 16-entry local routing table as one array, replacing the split of the first entry and the other 15. Each entry holds the exit port. The header giv (inferred)
pub mod ni_local_table {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638100;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 8;
    pub mod exit_port { // bits 3:0, established
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
pub const BWIN_INDEX_BITS: u32 = 0x3; // established
pub const BWIN_SIZE_BITS_M_MODE: u32 = 0x1d; // established
pub const BWIN_SIZE_BITS_N_MODE: u32 = 0x1c; // established
pub const HUB_REGISTER_WIDGET: u32 = 0x1; // established
pub const HUB_REGISTER_WINDOW_SIZE: u32 = 0x800000; // established
pub const NASID_BITS_M_MODE: u32 = 0x8; // established
pub const NASID_BITS_N_MODE: u32 = 0x9; // established
pub const NASID_LOCAL_BITS: u32 = 0x4; // established
pub const NASID_SHIFT_M_MODE: u32 = 0x20; // established
pub const NASID_SHIFT_N_MODE: u32 = 0x1f; // established
pub const NODE_SIZE_BITS_M_MODE: u32 = 0x20; // established
pub const NODE_SIZE_BITS_N_MODE: u32 = 0x1f; // established
pub const SWIN_SIZE_BITS: u32 = 0x18; // established
