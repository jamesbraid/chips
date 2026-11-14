// generated from devices/tiocp/registers-extra.toml by defs-gen - do not edit, change the source
// TIOCP registers and constants outside the census
#![allow(dead_code)]

/// Widget status (`cp_stat`), second word of the standard widget block. Offset, width and name are the header definition. Access direction is not stated; (established)
pub mod stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x8;
}
/// Widget error address, upper word (`cp_err_upper`); the lower word is the census register `bus_err`. Offset, width and name are the header definition.  (established)
pub mod err_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10;
}
/// Widget interrupt destination, upper word (`cp_intr_upper`); the lower word is the census register `intr_dst_target_id`. Offset, width and name are the (established)
pub mod intr_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30;
}
/// Test pin control (`cp_tst_pin_ctrl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so it (established)
pub mod tst_pin_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x70;
}
/// PCI error address, upper word (`cp_pci_err_upper`); the lower word is the census register `pci_bus_addr`. Offset, width and name are the header defini (established)
pub mod pci_err_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xd0;
}
/// Buffer address match registers: sixteen pairs, upper word then lower word. Offset, width and name are the header definition. Access direction is not s (established)
pub mod buf_addr_match_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x300;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 16;
}
/// Buffer address match, lower words (second word of each pair). Offset, width and name are the header definition. Access direction is not stated; no cod (established)
pub mod buf_addr_match_lower {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x308;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 16;
}
/// Performance monitor word `flush_w_touch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access directio (established)
pub mod buf_count_flush_w_touch {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor word `flush_wo_touch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access directi (established)
pub mod buf_count_flush_wo_touch {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x408;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor word `inflight` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is  (established)
pub mod buf_count_inflight {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x410;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor word `prefetch` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is  (established)
pub mod buf_count_prefetch {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x418;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor word `total_pci_retry` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direct (established)
pub mod buf_count_total_pci_retry {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x420;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor word `max_pci_retry` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access directio (established)
pub mod buf_count_max_pci_retry {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x428;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor word `max_latency` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction  (established)
pub mod buf_count_max_latency {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x430;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// Performance monitor word `clear_all` of block n; eight blocks, 0x40 bytes apart. Offset, width and name are the header definition. Access direction is (established)
pub mod buf_count_clear_all {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x438;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 64;
}
/// PCI-X timeout (`cp_pcix_timeout`), eighth word of the PCI-X block. Offset, width and name are the header definition. Access direction is not stated; n (established)
pub mod pcix_timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x638;
}
/// Coretalk debug control (`cp_ct_debug_ctl`). The debug registers exist on the TIOCP only; the PIC leaves this range as padding. Offset, width and name  (established)
pub mod ct_debug_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x700;
}
/// Bridge debug control (`cp_br_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, s (established)
pub mod br_debug_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x708;
}
/// Debug mux control (`cp_mux3_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so (established)
pub mod mux3_debug_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x710;
}
/// Debug mux control (`cp_mux4_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so (established)
pub mod mux4_debug_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x718;
}
/// Debug mux control (`cp_mux5_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so (established)
pub mod mux5_debug_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x720;
}
/// Debug mux control (`cp_mux6_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so (established)
pub mod mux6_debug_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x728;
}
/// Debug mux control (`cp_mux7_debug_ctl`). Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so (established)
pub mod mux7_debug_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x730;
}
/// PCI-X read buffer n, address word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its b (established)
pub mod pcix_read_buf_64_cp_buf_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa00;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 16;
}
/// PCI-X read buffer n, attribute word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its (established)
pub mod pcix_read_buf_64_cp_buf_attr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa08;
    pub const COUNT: u32 = 16;
    pub const STRIDE: u64 = 16;
}
/// PCI-X write buffer n, address word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its  (established)
pub mod pcix_write_buf_64_cp_buf_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb00;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 32;
}
/// PCI-X write buffer n, attribute word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so it (established)
pub mod pcix_write_buf_64_cp_buf_attr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb08;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 32;
}
/// PCI-X write buffer n, valid word. Offset, width and name are the header definition. Access direction is not stated; no code read reaches it, so its be (established)
pub mod pcix_write_buf_64_cp_buf_valid {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb10;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 32;
}
/// Internal translation entries with manual parity generation (`cp_int_ate_ram_mp`); the automatic-parity copy is the census register `int_ate`. No IRIX  (established)
pub mod int_ate_mp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x14000;
    pub const COUNT: u32 = 1024;
    pub const STRIDE: u64 = 8;
}
/// Write request RAM, lower data bank (`cp_wr_req_lower`). Offset and name are the header definition. Access direction is not stated; no code read reache (established)
pub mod wr_req_lower {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18000;
    pub const COUNT: u32 = 256;
    pub const STRIDE: u64 = 8;
}
/// Write request RAM, upper data bank (`cp_wr_req_upper`). Offset and name are the header definition. Access direction is not stated; no code read reache (established)
pub mod wr_req_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18800;
    pub const COUNT: u32 = 256;
    pub const STRIDE: u64 = 8;
}
/// Write request RAM, parity bank (`cp_wr_req_parity`). Offset and name are the header definition. Access direction is not stated; no code read reaches i (established)
pub mod wr_req_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x19000;
    pub const COUNT: u32 = 256;
    pub const STRIDE: u64 = 8;
}
/// Read response RAM, lower data bank (`cp_rd_resp_lower`). The PIC has no read response RAM. Offset and name are the header definition. Access direction (established)
pub mod rd_resp_lower {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1c000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Read response RAM, upper data bank. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behavio (established)
pub mod rd_resp_upper {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1d000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Read response RAM, parity bank. Offset and name are the header definition. Access direction is not stated; no code read reaches it, so its behaviour i (established)
pub mod rd_resp_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1e000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
pub const ATE_MSI: u32 = 0x4; // established
pub const ATE_PIO: u32 = 0x2; // established
pub const CFG_TYPE0_BASE: u32 = 0x21000; // established
pub const CFG_TYPE1_BASE: u32 = 0x28000; // established
pub const DEVIO_BASE: u32 = 0x200000; // established
pub const DEVIO_FLUSH_BASE: u32 = 0xa00000; // established
pub const HOST_INTR_ADDR_MASK: u64 = 0x3fffffffffffff; // established
pub const PCI64_CMDTYPE_MEM: u64 = 0x1000000000000000; // established
pub const PCI64_CMDTYPE_MSI: u64 = 0x3000000000000000; // established
pub const PCIX_SPECIAL_CYCLE_BASE: u32 = 0x40000; // established
pub const PCI_IACK_BASE: u32 = 0x30000; // established
pub const WAR_PV907516: u32 = 0x2; // established
