// generated from devices/shub/registers.toml by defs-gen - do not edit, change the source
// SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs
#![allow(dead_code)]

/// Chip identification word at node offset 0x1_0000_0000 (memory and directory block by address); the name is ours. The PROM reads it through the node's  (established)
pub mod chip_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100000000;
    pub mod revision { // bits 31:28, inferred
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
}
/// Memory test engine status; the name is ours. Written 0 at engine start. The memory-test loop reads bit 36 after every engine run (site 0xffa702c0) and (inferred)
pub mod md_mbist_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100000080;
    pub mod cmp_err { // bits 36:36, inferred
        pub const SHIFT: u32 = 36;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory test engine other-error value; the name is ours. Read only in the failure report, after bit 36 of md_mbist_status is found set; not read on a p (inferred)
pub mod md_mbist_err {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1000000b8;
}
/// Memory test engine mask; the name is ours (inferred from the all-ones write only). Written with all ones each time the engine starts. (inferred)
pub mod md_mbist_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1000000c0;
}
/// Memory controller register, unnamed; the name is ours. Per-bank configuration word 0 of the memory controller set-up (node-bringup.md: timing index in (inferred)
pub mod md_bank_cfg0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010000;
}
/// Memory controller register, unnamed; the name is ours. Per-bank configuration word 1; read once first, then written. (inferred)
pub mod md_bank_cfg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010008;
}
/// Memory controller register, unnamed; the name is ours. Per-bank configuration word 2; the memory test driver reads each bank's config byte here and sk (inferred)
pub mod md_bank_cfg2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010010;
}
/// Memory controller register, unnamed; the name is ours. Timing fields built from a 32-byte flash table row; bits 7:0 are 0x02 and one of bits 52, 53 or (inferred)
pub mod md_timing_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010020;
}
/// Memory controller register, unnamed; the name is ours. Six 4-bit timing fields (node-bringup.md; not re-read for this file). (inferred)
pub mod md_timing_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010028;
}
/// Memory controller register, unnamed; the name is ours. Refresh interval 195 in bits 16:8 (overridable by the MemoryRefresh variable), tRFC clocks in b (inferred)
pub mod md_refresh_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010030;
}
/// Memory controller register, unnamed; the name is ours. Paired with md_timing_0 (same layout, per node-bringup.md); read then written. (inferred)
pub mod md_timing_2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010040;
}
/// Memory controller register, unnamed; the name is ours. Second copy of md_timing_1's layout; read then written. (inferred)
pub mod md_timing_3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010048;
}
/// Memory controller register, unnamed; the name is ours. Second copy of md_refresh_0's layout. The bring-up routine reads it (site 0xffa7761c), puts the (inferred)
pub mod md_refresh_1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010050;
}
/// Memory controller register, unnamed; the name is ours. Written with the constant 0x4004e20 (node-bringup.md). (inferred)
pub mod md_const_58 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010058;
}
/// Memory controller register, unnamed; the name is ours. Written 0x4047 when the SHub ID revision is above 2 and 0x4045 otherwise (the same revision spl (inferred)
pub mod md_ctl_60 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010060;
}
/// Memory controller register, unnamed; the name is ours. A SAL_B routine reads it, reads md_bank_cfg1, and compares the 32-bit value with its third argu (established)
pub mod md_reg_0001_0068 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010068;
}
/// Memory controller register, unnamed; the name is ours. Written with the constant 0x24 (node-bringup.md). (inferred)
pub mod md_const_78 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100010078;
}
/// Memory test and DRAM initialisation engine, command or address word; the name is ours. Written with the caller's word before md_mbist_ctl. The meaning (inferred)
pub mod md_mbist_cmd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100020080;
}
/// Memory test and DRAM initialisation engine control; the name is ours. The PROM starts the engine by writing md_mbist_cmd, then 0 to md_mbist_status an (inferred)
pub mod md_mbist_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100020088;
    pub mod fail { // bits 41:41, inferred
        pub const SHIFT: u32 = 41;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod go { // bits 40:40, inferred
        pub const SHIFT: u32 = 40;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod op { // bits 38:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod value { // bits 30:0, inferred
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege  (established)
pub mod md_dqlp_dir_privilege_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030300;
}
/// Memory and directory block register, unnamed; the name is ours. The memory controller set-up writes 0x1000 (bit 12) to it through the global window, b (established)
pub mod md_reg_0003_0400 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100030400;
}
/// Directory memory initial-value write, left queue port block (the block is the one the Linux header calls SH1_MD_DQLP_MMR_DIR_PRIVEC0 at the 0x300 offs (established)
pub mod md_dir_access_lp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100031000;
    pub mod value { // bits 63:55, inferred
        pub const SHIFT: u32 = 55;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names. (established)
pub mod md_dqrp_dir_privilege_vector {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050300;
}
/// Same as md_reg_0003_0400 for the right queue port block, 0x100 above SH1_MD_DQRP_MMR_DIR_PRIVEC0 (md_dqrp_dir_privilege_vector). The same routine writ (established)
pub mod md_reg_0005_0400 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100050400;
}
/// As md_dir_access_lp for the right queue port block (SH1_MD_DQRP_MMR_DIR_PRIVEC0's block); the name is ours. (established)
pub mod md_dir_access_rp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100051000;
    pub mod value { // bits 63:55, inferred
        pub const SHIFT: u32 = 55;
        pub const MASK: u64 = 0x1ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR windo (established)
pub mod ipi_int {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110000380;
    pub mod send { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod idx { // bits 59:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and  (established)
pub mod rtc_int_config {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001480;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 256;
    pub mod idx { // bits 59:52, established
        pub const SHIFT: u32 = 52;
        pub const MASK: u64 = 0xff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod base { // bits 49:21, established
        pub const SHIFT: u32 = 21;
        pub const MASK: u64 = 0x1fffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod pid { // bits 19:4, established
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0xffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod agent { // bits 3:3, established
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod r#type { // bits 2:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes (established)
pub mod rtc_int_enable {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110001500;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 256;
    pub mod enable { // bits 0:0, established
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
/// Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the  (established)
pub mod event_occurred {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110010000;
    pub mod ii_int1 { // bits 30:30, established
        pub const SHIFT: u32 = 30;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ii_int0 { // bits 29:29, established
        pub const SHIFT: u32 = 29;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ipi_int { // bits 28:28, established
        pub const SHIFT: u32 = 28;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc3_int { // bits 26:26, established
        pub const SHIFT: u32 = 26;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc2_int { // bits 25:25, established
        pub const SHIFT: u32 = 25;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rtc1_int { // bits 24:24, established
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod uart_int { // bits 20:20, established
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
/// Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferre (established)
pub mod event_occurred_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110010008;
}
/// Local block register, unnamed; the name is ours (address). SAL_A writes 0x15031010 to it on each of its two entries (reason 3 and reason 0). The image (established)
pub mod lb_reg_1002_0000 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110020000;
}
/// Per-slice local block record, 128 bytes apart (index = slice & 3); the name is ours. SAL_B reads the running processor's entry in the lock routine and (established)
pub mod lb_slice_rec {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110030000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 128;
}
/// Real-time clock control; the name is ours. The PROM writes 0x100000000, then writes 0 to rtc, then writes 0x100000041, all at the SAL_B reset entry, b (established)
pub mod rtc_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060280;
    pub mod mode { // bits 33:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod period { // bits 13:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3ff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod run { // bits 0:0, inferred
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
/// Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross- (established)
pub mod ipi_access {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060480;
}
/// DRAM bus clock select; the name is ours. The memory-controller set-up reads it and uses bits 1:0 as an index into a four-entry table held in flash (20 (inferred)
pub mod md_clk_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060500;
    pub mod sel { // bits 1:0, inferred
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
/// SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in t (established)
pub mod shub_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110060580;
    pub mod nodes_per_bit { // bits 52:48, established
        pub const SHIFT: u32 = 48;
        pub const MASK: u64 = 0x1f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod size_code { // bits 45:44, inferred
        pub const SHIFT: u32 = 44;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod nasid { // bits 42:32, inferred
        pub const SHIFT: u32 = 32;
        pub const MASK: u64 = 0x7ff;
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
}
/// Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel wri (established)
pub mod ptc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101a0000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
    pub mod start { // bits 63:63, established
        pub const SHIFT: u32 = 63;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod rid { // bits 62:8, inferred
        pub const SHIFT: u32 = 8;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod ps { // bits 7:2, inferred
        pub const SHIFT: u32 = 2;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod type_bit { // bits 0:0, inferred
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
/// Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for proce (established)
pub mod int_cmp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101b0080;
    pub const COUNT: u32 = 3;
    pub const STRIDE: u64 = 128;
    pub mod compare { // bits 54:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because  (established)
pub mod rtc {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101c0000;
    pub mod counter { // bits 54:0, established
        pub const SHIFT: u32 = 0;
        pub const MASK: u64 = 0x7fffffffffffff;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Node election word; the name is ours. SAL_A stores slice + 1 to lb_elect_set and reads this register: the 64-bit value must equal exactly what was wri (established)
pub mod lb_elect {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0080;
}
/// Election write register; the name is ours. SAL_A stores slice + 1 here and reads lb_elect. Whether it aliases lb_elect, latches the first writer or so (established)
pub mod lb_elect_set {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0088;
}
/// L1 link state word in the local block; the name is ours. SAL_A's election winner sets bits 41:39 to 7 by read-modify-write, keeping the other bits. An (established)
pub mod lb_l1_state {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0100;
    pub mod link { // bits 41:39, inferred
        pub const SHIFT: u32 = 39;
        pub const MASK: u64 = 0x7;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Second firmware lock pair, release side; the name is ours. The methods of the chip object take it around read-modify-writes of fw_word_1540 by the sam (inferred)
pub mod lb_lock2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0180;
}
/// Second firmware lock status; the name is ours. This-node polls proceed when the whole 64-bit value reads 0 (the same routine as lb_lock_status). The o (inferred)
pub mod lb_lock2_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0188;
}
/// Firmware lock pair, release side; the name is ours. The PROM takes the lock by polling lb_lock_status until it reads 0, does a read-modify-write of cp (inferred)
pub mod lb_lock {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0200;
}
/// Firmware lock status; the name is ours. The PROM polls it with a short delay until it reads 0; any non-zero value keeps it waiting until the 1,000,000 (inferred)
pub mod lb_lock_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1101d0208;
}
/// Processor interface register, unnamed; the name is ours. A SAL_B routine sets bit 24 of pi_reg_2001_0100, reads this register, ORs in 0x3b03f7 when th (established)
pub mod pi_reg_2000_0000 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120000000;
}
/// Processor interface register, unnamed; the name is ours. A routine reached through a table that also writes pi_cam_control reads this register and wri (inferred)
pub mod pi_reg_2000_0180 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120000180;
}
/// Processor interface register, unnamed (the block is inferred from the neighbouring SH1_PI_CAM_CONTROL and SH1_PIO_WRITE_STATUS_0); the name is ours. S (established)
pub mod pi_reg_2001_0100 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120010100;
    pub mod bit24 { // bits 24:24, inferred
        pub const SHIFT: u32 = 24;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit17 { // bits 17:17, inferred
        pub const SHIFT: u32 = 17;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod bit3 { // bits 3:3, inferred
        pub const SHIFT: u32 = 3;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Per-slice flags in the processor interface; the name is ours. The local-master arbitration reads it for slices 0 and 1 other than the running one and  (established)
pub mod pi_slice_present {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120020080;
    pub mod present2 { // bits 5:4, inferred
        pub const SHIFT: u32 = 4;
        pub const MASK: u64 = 0x3;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod present { // bits 1:0, inferred
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
/// Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the k (established)
pub mod pi_cam_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120050300;
}
/// Processor interface register, unnamed; the name is ours. Read once, with pi_reg_2006_0180 and pi_reg_2006_0200, right after the second pi_cam_control  (inferred)
pub mod pi_reg_2006_0100 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120060100;
}
/// Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100. (inferred)
pub mod pi_reg_2006_0180 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120060180;
}
/// Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100. (inferred)
pub mod pi_reg_2006_0200 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120060200;
}
/// PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O wr (established)
pub mod pio_write_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120070200;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
    pub mod pending_write_count { // bits 61:56, established
        pub const SHIFT: u32 = 56;
        pub const MASK: u64 = 0x3f;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
    pub mod write_deadlock { // bits 1:1, established
        pub const SHIFT: u32 = 1;
        pub const MASK: u64 = 0x1;
        pub const fn get(v: u64) -> u64 {
            (v >> SHIFT) & MASK
        }
        pub const fn set(v: u64, x: u64) -> u64 {
            (v & !(MASK << SHIFT)) | ((x & MASK) << SHIFT)
        }
    }
}
/// Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it wa (inferred)
pub mod pio_write_status_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120070208;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 128;
}
/// Progress history of processor slice n (n = cr.lid bits 26:23, 0 to 3), 16 bytes apart; the name is ours. Every progress code is written as: read the w (established)
pub mod cpu_hist {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031500;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 16;
}
/// Firmware flag word; the name is ours. SAL_A's election winner writes 0 to it, and a later routine writes 0 to it on another node through the node-obje (inferred)
pub mod fw_word_1540 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031540;
}
/// Firmware per-processor state word; the name is ours. The winner of the SAL_A election zeroes it. Bits the PROM uses: 21 + slice (tested in 0xffa1d430, (established)
pub mod cpu_bits {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031550;
}
/// Firmware debug-switch word; the name is ours. SAL_A's election winner zeroes it; the PROM later stores the L1's reply to request 0x0001 and tests bits (inferred)
pub mod fw_debug_word {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150031560;
}
/// Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor  (established)
pub mod junk_bus_led {
    pub const WIDTH: u32 = 16;
    pub const OFFSET: u64 = 0x7fed00000;
    pub const COUNT: u32 = 4;
    pub const STRIDE: u64 = 65536;
}
pub const IPI_BASE_VALUE: u32 = 0xfee; // established
pub const PIO_WRITE_STATUS_ALIAS_CLEAR: u32 = 0x7; // established
pub const PIO_WRITE_STATUS_IDLE: u64 = 0x3f00000000000000; // established
pub const PI_CAM_WAR_VALUE: u64 = 0x8000000000000010; // established
pub const RTC_CONFIG_MASK: u64 = 0xff3ffffffefffff; // established
pub const RTC_ENABLE_MASK: u32 = 0x1; // established
pub const RTC_MASK: u64 = 0x7fffffffffffff; // established
pub const SHUB_1_1_MAX_REVISION: u32 = 0x2; // established
