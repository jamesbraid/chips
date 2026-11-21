// generated from devices/r14000_perf_counters/registers.toml by defs-gen - do not edit, change the source
// defs-gen 2
// input sha256 7eecccb8ac094c1de6c36069e754426c42e0d4e6a5dc0a503425e631c68b20df
// R14000 CP0 performance counters: selectors, control fields and event numbers
#![allow(dead_code)]

pub const R14KPC_CNT_BITS: u32 = 0x20; // inferred
pub const R14KPC_CNT_OVERFLOW_BIT: u32 = 0x1f; // inferred
pub const R14KPC_CP0_REG: u32 = 0x19; // inferred
pub const R14KPC_CTL_EVENT_MASK: u32 = 0x3e0; // inferred
pub const R14KPC_CTL_EVENT_SHIFT: u32 = 0x5; // inferred
pub const R14KPC_CTL_EXL: u32 = 0x1; // inferred
pub const R14KPC_CTL_IE: u32 = 0x10; // inferred
pub const R14KPC_CTL_K: u32 = 0x2; // inferred
pub const R14KPC_CTL_S: u32 = 0x4; // unknown
pub const R14KPC_CTL_U: u32 = 0x8; // inferred
pub const R14KPC_EV_CYCLES: u32 = 0x0; // established
pub const R14KPC_EV_DECODED_INSTR: u32 = 0x1; // established
pub const R14KPC_EV_FAILED_SC: u32 = 0x5; // established
pub const R14KPC_EV_MISPREDICT: u32 = 0x18; // established
pub const R14KPC_EV_PREFETCH_EXEC: u32 = 0x10; // established
pub const R14KPC_EV_RETIRED_FP: u32 = 0x15; // established
pub const R14KPC_EV_RETIRED_INSTR: u32 = 0xf; // established
pub const R14KPC_EV_SCACHE_ECC_CORRECTABLE: u32 = 0x8; // established
pub const R14KPC_EV_TLB_MISS: u32 = 0x17; // established
pub const R14KPC_EV_UNIMPLEMENTED: u32 = 0xe; // established
pub const R14KPC_PAIR0_CNT_SEL: u32 = 0x1; // inferred
pub const R14KPC_PAIR0_CTL_SEL: u32 = 0x0; // inferred
pub const R14KPC_PAIR1_CNT_SEL: u32 = 0x3; // inferred
pub const R14KPC_PAIR1_CTL_SEL: u32 = 0x2; // inferred
pub const R14KPC_PAIR2_CNT_SEL: u32 = 0x5; // inferred
pub const R14KPC_PAIR2_CTL_SEL: u32 = 0x4; // inferred
pub const R14KPC_PAIR3_CNT_SEL: u32 = 0x7; // inferred
pub const R14KPC_PAIR3_CTL_SEL: u32 = 0x6; // inferred
pub const R14KPC_PAIRS: u32 = 0x4; // inferred
pub const R14KPC_R12K_CTL0_TRIGGER_MASK: u32 = 0x18000; // unknown
pub const R14KPC_R12K_CTL3_LEVEL_BIT: u32 = 0x8000; // unknown
pub const R14KPC_R12K_CTL_COND_MASK: u32 = 0x7c00; // unknown
