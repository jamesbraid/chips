// generated from devices/hub_ni/registers-extra.toml by defs-gen - do not edit, change the source
// Hub network interface field layouts, port and vector fields, and register offsets outside the census
#![allow(dead_code)]

pub mod enums {
    pub mod ni_node_mode {
        pub const MORE_MEMORY: u32 = 0; // established
        pub const MORE_NODES: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            MoreMemory,
            MoreNodes,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::MoreMemory,
                    1 => Self::MoreNodes,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::MoreMemory => 0,
                    Self::MoreNodes => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ni_pio_request_type {
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
    pub mod ni_pio_type {
        pub const READ: u32 = 0; // established
        pub const WRITE: u32 = 1; // established
        pub const UNDEFINED: u32 = 2; // established
        pub const EXCHANGE: u32 = 3; // established
        pub const ADDRESS_ERROR: u32 = 4; // established
        pub const COMMAND_ERROR: u32 = 5; // established
        pub const PROTECTION_ERROR: u32 = 6; // established
        pub const UNKNOWN: u32 = 7; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Read,
            Write,
            Undefined,
            Exchange,
            AddressError,
            CommandError,
            ProtectionError,
            Unknown,
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
                    7 => Self::Unknown,
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
                    Self::Unknown => 7,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ni_region_size {
        pub const COARSE: u32 = 0; // established
        pub const FINE: u32 = 1; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            Coarse,
            Fine,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::Coarse,
                    1 => Self::Fine,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::Coarse => 0,
                    Self::Fine => 1,
                    Self::Other(v) => v,
                }
            }
        }
    }
    pub mod ni_vchannel {
        pub const CHANNEL_A: u32 = 0; // established
        pub const CHANNEL_B: u32 = 1; // established
        pub const ANY: u32 = 2; // established
        #[derive(Debug, Clone, Copy, PartialEq, Eq)]
        pub enum Value {
            ChannelA,
            ChannelB,
            Any,
            Other(u32),
        }
        impl Value {
            pub const fn from_raw(v: u32) -> Self {
                match v {
                    0 => Self::ChannelA,
                    1 => Self::ChannelB,
                    2 => Self::Any,
                    _ => Self::Other(v),
                }
            }
            pub const fn raw(self) -> u32 {
                match self {
                    Self::ChannelA => 0,
                    Self::ChannelB => 1,
                    Self::Any => 2,
                    Self::Other(v) => v,
                }
            }
        }
    }
}

/// Layout of the status, revision and identity register, ni_status_rev_id. The header names the port status bits separately; this word uses the same name (established)
pub mod ni_status_rev_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600000;
    pub mod eightbit_mode { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_up { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod down_reason { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod more_nodes { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_node_mode::Value;
    }
    pub mod region_size { // bits 17:17, established
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_region_size::Value;
    }
    pub mod node_id { // bits 16:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod chip_rev { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod chip_id { // bits 3:0, established
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
/// Layout of the port reset register, ni_port_reset. The register is written, not read back; the header gives no read value. (established)
pub mod ni_port_reset {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600008;
    pub mod warm_reset { // bits 7:7, established
        pub const SHIFT: u32 = 7;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod link_reset { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod local_reset { // bits 0:0, established
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
/// Layout of the protection configuration register, ni_protection. (established)
pub mod ni_protection {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600010;
    pub mod reset_ok { // bits 0:0, established
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
/// Layout of the global link parameters register, ni_global_parms. The header's comment on the credit-timeout field repeats the wording of the field abov (established)
pub mod ni_global_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600018;
    pub mod max_retry { // bits 57:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tail_timeout_wrap { // bits 47:32, established
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod credit_timeout { // bits 19:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tail_timeout { // bits 7:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Layout of the diagnostic parameters register, ni_diag_parms. The header names each bit and gives no further behaviour. (established)
pub mod ni_diag_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600110;
    pub mod port_timeout_reset { // bits 18:18, established
        pub const SHIFT: u32 = 18;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod llp_8bit_mode { // bits 12:12, established
        pub const SHIFT: u32 = 12;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod port_disable { // bits 6:6, established
        pub const SHIFT: u32 = 6;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod send_error { // bits 0:0, established
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
/// Layout of the vector routing parameters register, ni_vector_parms. The header's identifier mask covers bits 49:40. Other sources put the top bit of th (established)
pub mod ni_vector_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600200;
    pub mod pio_id { // bits 49:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x3ff;
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
    pub mod address { // bits 19:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1ffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pio_type { // bits 1:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_pio_request_type::Value;
    }
}
/// Layout of the vector routing status register, ni_vector_status. The source field is ten bits in the header (60:51). Another source gives it eleven bit (established)
pub mod ni_vector_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600300;
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
    pub mod target { // bits 60:51, established
        pub const SHIFT: u32 = 51;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pio_id { // bits 49:40, established
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x3ff;
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
    pub mod address { // bits 31:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pio_type { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_pio_type::Value;
    }
}
/// Return vector of a vector operation, named NI_RETURN_VECTOR in the header. The header gives no layout. The IRIX register table confirms the access. (established)
pub mod ni_return_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600308;
}
/// PIO protection bits, one per region, named NI_IO_PROTECT in the header. Offset and name are from the header. The header gives neither a field layout n (established)
pub mod ni_io_protect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600400;
}
/// PIO protection override, named NI_IO_PROT_OVRRD in the header. The header gives no unlock value or behaviour, so none is imported. The IRIX register t (established)
pub mod ni_io_prot_ovrrd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600408;
}
/// Layout of each of the eight ageing registers, ni_age_cpu0_memory through ni_age_io_pio. The census names two of them. The header gives the channel fie (established)
pub mod ni_age_cpu0_memory {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600500;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// CPU 0 PIO age control, named NI_AGE_CPU0_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access. (established)
pub mod ni_age_cpu0_pio {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600508;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// Layout of each of the eight ageing registers, ni_age_cpu0_memory through ni_age_io_pio. The census names two of them. The header gives the channel fie (established)
pub mod ni_age_cpu1_memory {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600510;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// CPU 1 PIO age control, named NI_AGE_CPU1_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access. (established)
pub mod ni_age_cpu1_pio {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600518;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// Block-transfer engine memory age control, named NI_AGE_GBR_MEMORY in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access. (established)
pub mod ni_age_gbr_memory {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600520;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// Block-transfer engine PIO age control, named NI_AGE_GBR_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access. (established)
pub mod ni_age_gbr_pio {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600528;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// I/O interface memory age control, named NI_AGE_IO_MEMORY in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access. (established)
pub mod ni_age_io_memory {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600530;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// I/O interface PIO age control, named NI_AGE_IO_PIO in the header. Layout in NI_AGE_FORMAT. The IRIX register table confirms the access. (established)
pub mod ni_age_io_pio {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x600538;
    pub mod vchannel { // bits 11:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
        pub use super::super::enums::ni_vchannel::Value;
    }
    pub mod congestion { // bits 9:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod age { // bits 7:0, established
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
/// Port parameters, named NI_PORT_PARMS in the header. Offset and name are from the header. The fields are graded on their own. The IRIX register table c (established)
pub mod ni_port_parms {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608000;
    pub mod null_timeout { // bits 15:10, established
        pub const SHIFT: u32 = 10;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod max_burst { // bits 9:0, established
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
/// Layout of the port error register, ni_port_error, and of its clearing alias, ni_port_error_clear. Bit 32 is outside the header's error mask and has no (established)
pub mod ni_port_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608008;
    pub mod link_reset { // bits 37:37, established
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod internal_error { // bits 36:36, established
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_message { // bits 35:35, established
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_destination { // bits 34:34, established
        pub const SHIFT: u32 = 34;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod queue_overflow { // bits 33:33, established
        pub const SHIFT: u32 = 33;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod credit_timeout_count { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tail_timeout_count { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_count { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod check_bit_error_count { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sequence_error_count { // bits 7:0, established
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
/// Layout of the port error register, ni_port_error, and of its clearing alias, ni_port_error_clear. Bit 32 is outside the header's error mask and has no (established)
pub mod ni_port_error_clear {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x608088;
    pub mod link_reset { // bits 37:37, established
        pub const SHIFT: u32 = 37;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod internal_error { // bits 36:36, established
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_message { // bits 35:35, established
        pub const SHIFT: u32 = 35;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bad_destination { // bits 34:34, established
        pub const SHIFT: u32 = 34;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod queue_overflow { // bits 33:33, established
        pub const SHIFT: u32 = 33;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod credit_timeout_count { // bits 31:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod tail_timeout_count { // bits 27:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0xf;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod retry_count { // bits 23:16, established
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod check_bit_error_count { // bits 15:8, established
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod sequence_error_count { // bits 7:0, established
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
/// Meta routing table entries 1 to 31, eight bytes apart from the census entry ni_meta_table0. The header gives the stride and the count of 32 entries. A (inferred)
pub mod ni_meta_entry {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638008;
    pub const COUNT: u32 = 31;
    pub const STRIDE: u64 = 8;
}
/// Local routing table entries 1 to 15, eight bytes apart from the census entry ni_local_table0. The header gives the stride and the count of 16 entries. (inferred)
pub mod ni_local_entry {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638108;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 8;
}
pub const NI_LOCAL_ENTRIES: u32 = 0x10; // established
pub const NI_META_ENTRIES: u32 = 0x20; // established
pub const NI_PORT_ERROR_COUNT_MAX: u32 = 0xff; // established
pub const NI_PORT_PARMS_DEFAULTS: u32 = 0x1bf0; // established
pub const NI_PORT_PARMS_HUB20_DEFAULTS: u32 = 0x7f0; // established
