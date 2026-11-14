// generated from devices/pic/registers-extra.toml by defs-gen - do not edit, change the source
// PIC bits outside the census
#![allow(dead_code)]

/// Widget status, the second word of the standard widget configuration block (`p_wid_stat`). Offset, width and name are the header definition. Access dir (established)
pub mod wid_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x8;
}
/// Widget error address, upper word (`p_wid_err_upper`); the lower word is the census register `bus_err`. Offset, width and name are the header definitio (established)
pub mod wid_err_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10;
}
/// Widget interrupt destination, upper word (`p_wid_int_upper`); the lower word is the census register `intr_dst_target_id`. Offset, width and name are t (established)
pub mod wid_int_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30;
}
/// Test pin control (`p_wid_tst_pin_ctrl`), the one slot of the bridge-specific block between the response words and the address-lock error register. Off (established)
pub mod wid_tst_pin_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x70;
}
/// PCI bus error address, upper word (`p_pci_err_upper`); the lower word is the census register `pci_bus_addr`. Offset, width and name are the header def (established)
pub mod pci_err_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xd0;
}
/// Buffer address match registers: sixteen pairs, upper word then lower word, sixteen bytes per pair (`p_buf_addr_match[n].upper` and `.lower`). Offset,  (established)
pub mod buf_addr_match {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 8;
}
/// Performance monitor block n, word 0 (`p_buf_count[n].flush_w_touch`): eight blocks of eight words, 0x40 bytes apart. The header comment marks them eve (established)
pub mod buf_flush_w_touch {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor block n, word 1 (`flush_wo_touch`). Offset, width and name are the header definition. Access direction is not stated by the header (established)
pub mod buf_flush_wo_touch {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x408;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor block n, word 2 (`inflight`). Offset, width and name are the header definition. Access direction is not stated by the header or by (established)
pub mod buf_inflight {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor block n, word 3 (`prefetch`). Offset, width and name are the header definition. Access direction is not stated by the header or by (established)
pub mod buf_prefetch {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x418;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor block n, word 4 (`total_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the heade (established)
pub mod buf_total_pci_retry {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor block n, word 5 (`max_pci_retry`). Offset, width and name are the header definition. Access direction is not stated by the header  (established)
pub mod buf_max_pci_retry {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x428;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor block n, word 6 (`max_latency`). Offset, width and name are the header definition. Access direction is not stated by the header or (established)
pub mod buf_max_latency {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x430;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor block n, word 7 (`clear_all`). Offset, width and name are the header definition. Access direction is not stated by the header or b (established)
pub mod buf_clear_all {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x438;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// PCI-X timeout (`p_pcix_timeout`), the eighth word of the PCI-X register block that follows the seven census registers. Offset, width and name are the  (established)
pub mod pcix_timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638;
}
/// PCI-X read buffer n, address word (`p_pcix_read_buf_64[n].p_buf_addr`); the attribute word of the same buffer follows it. Offset, width and name are t (established)
pub mod pcix_read_buf_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa00;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 16;
}
/// PCI-X read buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or  (established)
pub mod pcix_read_buf_attr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa08;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 16;
}
/// PCI-X write buffer n, address word (`p_pcix_write_buf_64[n].p_buf_addr`); the attribute, valid and one unused word follow at eight-byte steps. Offset, (established)
pub mod pcix_write_buf_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb00;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 32;
}
/// PCI-X write buffer n, attribute word (`p_buf_attr`). Offset, width and name are the header definition. Access direction is not stated by the header or (established)
pub mod pcix_write_buf_attr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb08;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 32;
}
/// PCI-X write buffer n, valid word (`p_buf_valid`). Offset, width and name are the header definition. Access direction is not stated by the header or by (established)
pub mod pcix_write_buf_valid {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb10;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 32;
}
/// Second copy of the internal translation entries with manual parity generation (`p_int_ate_ram_mp`); the census register `int_ate` is the automatic-par (established)
pub mod int_ate_mp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x12000;
    pub const COUNT: u32 = 1024;
    pub const STRIDE: u64 = 8;
}
pub const ATE_ADDR_SHIFT: u32 = 0xc; // established
pub const ATE_BARRIER: u32 = 0x10; // established
pub const ATE_COHERENT: u32 = 0x2; // established
pub const ATE_MSI: u32 = 0x4; // established
pub const ATE_PREFETCH: u32 = 0x8; // established
pub const ATE_TARGET_SHIFT: u32 = 0x8; // established
pub const ATE_VALID: u32 = 0x1; // established
pub const CFG_TYPE0_BASE: u32 = 0x20000; // established
pub const CFG_TYPE1_BASE: u32 = 0x28000; // established
pub const CONTROL_PAGE_SIZE_16K: u32 = 0x200000; // established
pub const DEVICE_SWAP_DIRECT: u32 = 0x80000; // inferred
pub const DIRECT64_ATTR_BARRIER: u64 = 0x100000000000000; // established
pub const DIRECT64_ATTR_PRECISE: u64 = 0x400000000000000; // established
pub const DIRECT64_ATTR_PREFETCH: u64 = 0x800000000000000; // established
pub const DIRECT64_ATTR_SWAP: u64 = 0x80000000000000; // established
pub const DIRECT64_ATTR_TARGET_SHIFT: u32 = 0x3c; // established
pub const DIRECT64_ATTR_VIRTUAL: u64 = 0x200000000000000; // established
pub const DIRECT64_ATTR_VIRTUAL1: u64 = 0x40000000000000; // established
pub const HOST_INTR_ADDR_MASK: u64 = 0xffffffffffff; // established
pub const INTR_FLUSH_WAIT_VALUE: u32 = 0x10f; // established
pub const INTR_PCIX_MASTER_TIMEOUT: u64 = 0x400000000; // established
pub const INTR_PCI_MASTER_TIMEOUT: u32 = 0x800; // established
pub const INTR_RESET_MULTIPLE_CLEAR: u32 = 0x40; // established
pub const PCI32_DIRECT_BASE: u32 = 0x80000000; // established
pub const PCI32_MAPPED_BASE: u32 = 0x40000000; // established
pub const PCI32_MAPPED_SWAP: u32 = 0x20000000; // established
pub const PCIX_SPECIAL_CYCLE_BASE: u32 = 0x40000; // established
pub const PCI_IACK_BASE: u32 = 0x30000; // established
