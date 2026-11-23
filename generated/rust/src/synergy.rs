// @generated from devices/synergy/registers.toml by defs-gen - do not edit, change the source
// defs-gen 3
// input sha256 4c3ea2546f72bcace270f575e55b39b69ccbbb218f4ea2c4bd2699014b6f3a17
// Synergy: the Itanium processor-bus ASIC of the SN1 IA-64 node (register offsets the Linux port uses)
#![allow(dead_code)]
#![allow(clippy::doc_markdown)]
#![cfg_attr(rustfmt, rustfmt_skip)]

/// Interrupt vector enable mask, vectors 192 to 255, for the processor in bus slot 0. Bit n enables vector 192 plus n. The kernel sets a processor's bit  (established)
pub mod vec_mask3_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2a0;
}
/// Same as vec_mask3_a for the processor in bus slot 1. (established)
pub mod vec_mask3_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2a8;
}
/// Vector enable mask, vectors 128 to 191, slot 0. (established)
pub mod vec_mask2_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2b0;
}
/// Vector enable mask, vectors 128 to 191, slot 1. (established)
pub mod vec_mask2_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2b8;
}
/// Vector enable mask, vectors 64 to 127, slot 0. The kernel's Bedrock-pending-bit interrupts live here and in the next register. (established)
pub mod vec_mask1_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2c0;
}
/// Vector enable mask, vectors 64 to 127, slot 1. (established)
pub mod vec_mask1_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2c8;
}
/// Vector enable mask, vectors 0 to 63, slot 0. (established)
pub mod vec_mask0_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2d0;
}
/// Vector enable mask, vectors 0 to 63, slot 1. (established)
pub mod vec_mask0_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2d8;
}
/// Offset established; role inferred. From the 2.4.18 patches of April 2002 the kernel's I/O write barrier reads this register for a processor on Synergy (established)
pub mod gbl_perf_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x330;
}
/// Counterpart of gbl_perf_a, polled by processors on Synergy 1. See there. (established)
pub mod gbl_perf_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x338;
}
/// Written once per Synergy by the fake PROM with (nasid << 16) | (synergy << 9); the comment says it sets the NASID in FSB_CONFIG. The value written and (established)
pub mod fsb_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x450;
    pub mod nasid { // bits 23:16, inferred
        pub const SHIFT: u32 = 16;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod synergy { // bits 9:9, inferred
        pub const SHIFT: u32 = 9;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Performance control, bus 0, counter A. Only with the kernel's optional perf option. Bit 45 enables counting (the code sets it on every event word it s (established)
pub mod perf_cntl0_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xab0;
    pub mod enable { // bits 45:45, established
        pub const SHIFT: u32 = 45;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Performance control, counter B. The header labels it bus 0, but the kernel's multiplexer writes it through Synergy 1 (and CNTL0_A through Synergy 0),  (established)
pub mod perf_cntl0_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xab8;
}
/// Performance control, bus 1, counter A. Defined in the header; the kernel's multiplexer never writes it. (established)
pub mod perf_cntl1_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xac0;
}
/// Performance control, bus 1, counter B. Defined, unused. (established)
pub mod perf_cntl1_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xac8;
}
/// Performance counter 0, A. Read through the remote window and masked to 40 bits, then written zero after each interval. (established)
pub mod perf_cntr0_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xad0;
}
/// Performance counter 0, B. Same use, but read and cleared through Synergy 1 while counter 0 A is read through Synergy 0, so the header's 'FSB0' label f (established)
pub mod perf_cntr0_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xad8;
}
/// Cache-way disable mask for the L4 cache. The kernel's flush routine writes 0xff with one way's bit cleared, reads a run of 512-byte blocks through nin (established)
pub mod syn_tag_disable_way {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xae0;
    pub mod way_disable { // bits 7:0, inferred
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
/// Performance counter 1, A. Defined, unused by the kernel. (established)
pub mod perf_cntr1_a {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xaf0;
}
/// Performance counter 1, B. Defined, unused. (established)
pub mod perf_cntr1_b {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xaf8;
}
pub const L4_BLOCK_BYTES: u32 = 0x200; // established
pub const L4_BYTES: u32 = 0x4000000; // established
pub const L4_WAYS: u32 = 0x8; // established
pub const LOCAL_BASE: u64 = 0xe0000000000; // established
pub const PERF_COUNTER_BITS: u32 = 0x28; // established
pub const REMOTE_WINDOW_SYN0: u32 = 0x34000000; // established
pub const REMOTE_WINDOW_SYN1: u32 = 0x35000000; // established
