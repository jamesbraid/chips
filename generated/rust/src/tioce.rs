// generated from devices/tioce/registers.toml by defs-gen - do not edit, change the source
// TIOCE (TIO PCI Express bridge), as SGI's Linux Altix platform code defines it
#![allow(dead_code)]

/// Widget identification word: part 0xce00, source id 1, revision A = 1 (header constants). Revision A needs the access workaround described on the unit  (established)
pub mod adm_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x0;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_dyn_credit_status). The header gives no access direction or reset value; acce (established)
pub mod adm_dyn_credit_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_last_credit_status). The header gives no access direction or reset value; acc (established)
pub mod adm_last_credit_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_credit_limit). The header gives no access direction or reset value; access rw (established)
pub mod adm_credit_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x20;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_force_credit). The header gives no access direction or reset value; access rw (established)
pub mod adm_force_credit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x28;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_control). The header gives no access direction or reset value; access rw is a (established)
pub mod adm_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_mmr_chn_timeout). The header gives no access direction or reset value; access (established)
pub mod adm_mmr_chn_timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_ure_timeout). The header gives no access direction or reset value; access (established)
pub mod adm_ssp_ure_timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_dre_timeout). The header gives no access direction or reset value; access (established)
pub mod adm_ssp_dre_timeout {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x48;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_sel). The header gives no access direction or reset value; access r (established)
pub mod adm_ssp_debug_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x50;
}
/// Interrupt status. Bit n is the interrupt source named by the header (error, link 1 and 2 errors, PCIe error, hot-plug events per port, INTA to INTD of (established)
pub mod adm_int_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x58;
}
/// Interrupt status alias. The provider sets every bit through it at attach to clear transients (the alias is the write path to clear; role from that use (established)
pub mod adm_int_status_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x60;
}
/// Interrupt mask. The provider sets a source bit, writes its destination, then clears the bit, so a set bit blocks the source while the destination is r (established)
pub mod adm_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x68;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_int_pending). The header gives no access direction or reset value; access rw  (established)
pub mod adm_int_pending {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x70;
}
/// Force interrupt. Bits 0 to 7 force INTA to INTD of port 1 then port 2; bit 8 forces always. The bit numbering differs from the status register, and th (established)
pub mod adm_force_int {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x78;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ure_ups_buf_barrier_flush). The header gives no access direction or reset val (established)
pub mod adm_ure_ups_buf_barrier_flush {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x80;
}
/// Interrupt destination, one per source (the header declares fifteen). The provider writes the kernel vector in bits 63:56 (shift INTR_VECTOR_SHFT) ORed (established)
pub mod adm_int_dest {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x88;
    pub const COUNT: u32 = 15;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_error_summary). The header gives no access direction or reset value; access r (established)
pub mod adm_error_summary {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x100;
}
/// Error summary alias. The provider sets every bit through it at attach to clear transient errors. Name and offset are the vendor header's definition (s (established)
pub mod adm_error_summary_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x108;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_error_mask). The header gives no access direction or reset value; access rw i (established)
pub mod adm_error_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x110;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_first_error). The header gives no access direction or reset value; access rw  (established)
pub mod adm_first_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x118;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_error_overflow). The header gives no access direction or reset value; access  (established)
pub mod adm_error_overflow {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x120;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_error_overflow_alias). The header gives no access direction or reset value; a (established)
pub mod adm_error_overflow_alias {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x128;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_tnum_error). The header gives no access direction or reset value; access rw i (established)
pub mod adm_tnum_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x140;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_mmr_err_detail). The header gives no access direction or reset value; access  (established)
pub mod adm_mmr_err_detail {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x148;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_msg_sram_perr_detail). The header gives no access direction or reset value; a (established)
pub mod adm_msg_sram_perr_detail {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x150;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_bap_sram_perr_detail). The header gives no access direction or reset value; a (established)
pub mod adm_bap_sram_perr_detail {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x158;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ce_sram_perr_detail). The header gives no access direction or reset value; ac (established)
pub mod adm_ce_sram_perr_detail {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x160;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ce_credit_oflow_detail). The header gives no access direction or reset value; (established)
pub mod adm_ce_credit_oflow_detail {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x168;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_tx_link_idle_max_timer). The header gives no access direction or reset value; (established)
pub mod adm_tx_link_idle_max_timer {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x170;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_sel). The header gives no access direction or reset value; access  (established)
pub mod adm_pcie_debug_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x178;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_sel_top). The header gives no access direction or reset value; acc (established)
pub mod adm_pcie_debug_sel_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x200;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_lat_sel_lo_top). The header gives no access direction or reset val (established)
pub mod adm_pcie_debug_lat_sel_lo_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x208;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_lat_sel_hi_top). The header gives no access direction or reset val (established)
pub mod adm_pcie_debug_lat_sel_hi_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x210;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_sel_top). The header gives no access direction or reset value (established)
pub mod adm_pcie_debug_trig_sel_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x218;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_lat_sel_lo_top). The header gives no access direction or rese (established)
pub mod adm_pcie_debug_trig_lat_sel_lo_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x220;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_debug_trig_lat_sel_hi_top). The header gives no access direction or rese (established)
pub mod adm_pcie_debug_trig_lat_sel_hi_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x228;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_trig_compare_top). The header gives no access direction or reset value;  (established)
pub mod adm_pcie_trig_compare_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x230;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_pcie_trig_compare_en_top). The header gives no access direction or reset valu (established)
pub mod adm_pcie_trig_compare_en_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x238;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_sel_top). The header gives no access direction or reset value; acce (established)
pub mod adm_ssp_debug_sel_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x240;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_lat_sel_lo_top). The header gives no access direction or reset valu (established)
pub mod adm_ssp_debug_lat_sel_lo_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x248;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_lat_sel_hi_top). The header gives no access direction or reset valu (established)
pub mod adm_ssp_debug_lat_sel_hi_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x250;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_sel_top). The header gives no access direction or reset value; (established)
pub mod adm_ssp_debug_trig_sel_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x258;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_lat_sel_lo_top). The header gives no access direction or reset (established)
pub mod adm_ssp_debug_trig_lat_sel_lo_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x260;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_debug_trig_lat_sel_hi_top). The header gives no access direction or reset (established)
pub mod adm_ssp_debug_trig_lat_sel_hi_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x268;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_trig_compare_top). The header gives no access direction or reset value; a (established)
pub mod adm_ssp_trig_compare_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x270;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_ssp_trig_compare_en_top). The header gives no access direction or reset value (established)
pub mod adm_ssp_trig_compare_en_top {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x278;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_bap_ctrl). The header gives no access direction or reset value; access rw is  (established)
pub mod adm_bap_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x400;
}
/// Name and offset are the vendor header's definition (struct member ce_msg_buf_data63_0). The header gives no access direction or reset value; access rw (established)
pub mod msg_buf_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x800;
    pub const COUNT: u32 = 35;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_msg_buf_data127_64). The header gives no access direction or reset value; access  (established)
pub mod msg_buf_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xa00;
    pub const COUNT: u32 = 35;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_msg_buf_parity). The header gives no access direction or reset value; access rw i (established)
pub mod msg_buf_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xc00;
    pub const COUNT: u32 = 35;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lpu_id). The header gives no access direction or reset value; access rw is a  (established)
pub mod lsi_lpu_id {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rst). The header gives no access direction or reset value; access rw is a pla (established)
pub mod lsi_rst {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2008;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_dbg_stat). The header gives no access direction or reset value; access rw is  (established)
pub mod lsi_dbg_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2010;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_dbg_cfg). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_dbg_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2018;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_ctrl). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_ltssm_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2020;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_stat). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_lk_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2028;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_int_and_stat). The header gives no access direction or reset value; access rw (established)
pub mod lsi_int_and_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2040;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_int_mask). The header gives no access direction or reset value; access rw is  (established)
pub mod lsi_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2048;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt_sel). The header gives no access direction or reset value; access (established)
pub mod lsi_lk_perf_cnt_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2100;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt_ctrl). The header gives no access direction or reset value; acces (established)
pub mod lsi_lk_perf_cnt_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2110;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt1). The header gives no access direction or reset value; access rw (established)
pub mod lsi_lk_perf_cnt1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2120;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt1_test). The header gives no access direction or reset value; acce (established)
pub mod lsi_lk_perf_cnt1_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2128;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt2). The header gives no access direction or reset value; access rw (established)
pub mod lsi_lk_perf_cnt2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2130;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_perf_cnt2_test). The header gives no access direction or reset value; acce (established)
pub mod lsi_lk_perf_cnt2_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2138;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_cfg). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_lk_lyr_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2200;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_status). The header gives no access direction or reset value; access r (established)
pub mod lsi_lk_lyr_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2208;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_lyr_int_stat). The header gives no access direction or reset value; access (established)
pub mod lsi_lk_lyr_int_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2210;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_ly_int_stat_test). The header gives no access direction or reset value; ac (established)
pub mod lsi_lk_ly_int_stat_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2218;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_lk_ly_int_stat_mask). The header gives no access direction or reset value; ac (established)
pub mod lsi_lk_ly_int_stat_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2220;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_fc_upd_ctl). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_fc_upd_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2240;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_to_timer). The header gives no access direction or reset value; a (established)
pub mod lsi_flw_ctl_upd_to_timer {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2260;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_timer0). The header gives no access direction or reset value; acc (established)
pub mod lsi_flw_ctl_upd_timer0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2268;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_flw_ctl_upd_timer1). The header gives no access direction or reset value; acc (established)
pub mod lsi_flw_ctl_upd_timer1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2270;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_freq_nak_lat_thrsh). The header gives no access direction or reset value; acc (established)
pub mod lsi_freq_nak_lat_thrsh {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2400;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ack_nak_lat_tmr). The header gives no access direction or reset value; access (established)
pub mod lsi_ack_nak_lat_tmr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2408;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rply_tmr_thr). The header gives no access direction or reset value; access rw (established)
pub mod lsi_rply_tmr_thr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2410;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rply_tmr). The header gives no access direction or reset value; access rw is  (established)
pub mod lsi_rply_tmr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2418;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rply_num_stat). The header gives no access direction or reset value; access r (established)
pub mod lsi_rply_num_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2420;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rty_buf_max_addr). The header gives no access direction or reset value; acces (established)
pub mod lsi_rty_buf_max_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2428;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_ptr). The header gives no access direction or reset value; access rw (established)
pub mod lsi_rty_fifo_ptr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2430;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_rd_wr_ptr). The header gives no access direction or reset value; acc (established)
pub mod lsi_rty_fifo_rd_wr_ptr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2438;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rty_fifo_cred). The header gives no access direction or reset value; access r (established)
pub mod lsi_rty_fifo_cred {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2440;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_seq_cnt {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2448;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ack_sent_seq_num). The header gives no access direction or reset value; acces (established)
pub mod lsi_ack_sent_seq_num {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2450;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_fifo_max_addr). The header gives no access direction or reset value;  (established)
pub mod lsi_seq_cnt_fifo_max_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2458;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_fifo_ptr). The header gives no access direction or reset value; acces (established)
pub mod lsi_seq_cnt_fifo_ptr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2460;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_seq_cnt_rd_wr_ptr). The header gives no access direction or reset value; acce (established)
pub mod lsi_seq_cnt_rd_wr_ptr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2468;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_tx_lk_ts_ctl). The header gives no access direction or reset value; access rw (established)
pub mod lsi_tx_lk_ts_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2470;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_mem_addr_ctl). The header gives no access direction or reset value; access rw (established)
pub mod lsi_mem_addr_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2480;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld0). The header gives no access direction or reset value; access rw is (established)
pub mod lsi_mem_d_ld0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2488;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld1). The header gives no access direction or reset value; access rw is (established)
pub mod lsi_mem_d_ld1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2490;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld2). The header gives no access direction or reset value; access rw is (established)
pub mod lsi_mem_d_ld2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2498;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld3). The header gives no access direction or reset value; access rw is (established)
pub mod lsi_mem_d_ld3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24a0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_mem_d_ld4). The header gives no access direction or reset value; access rw is (established)
pub mod lsi_mem_d_ld4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24a8;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rty_d_cnt). The header gives no access direction or reset value; access rw is (established)
pub mod lsi_rty_d_cnt {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24c0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_seq_buf_cnt). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_seq_buf_cnt {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24c8;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_seq_buf_bt_d). The header gives no access direction or reset value; access rw (established)
pub mod lsi_seq_buf_bt_d {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24d0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ack_lat_thr). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_ack_lat_thr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24e0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_nxt_rcv_seq_1_cntr). The header gives no access direction or reset value; acc (established)
pub mod lsi_nxt_rcv_seq_1_cntr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2500;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_unsp_dllp_rcvd). The header gives no access direction or reset value; access  (established)
pub mod lsi_unsp_dllp_rcvd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2508;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_lk_ts_ctl). The header gives no access direction or reset value; access r (established)
pub mod lsi_rcv_lk_ts_ctl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2510;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_cfg). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_phy_lyr_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2600;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_stat). The header gives no access direction or reset value; acces (established)
pub mod lsi_phy_lyr_int_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2610;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_stat_test). The header gives no access direction or reset value;  (established)
pub mod lsi_phy_lyr_int_stat_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2618;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_phy_lyr_int_mask). The header gives no access direction or reset value; acces (established)
pub mod lsi_phy_lyr_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2620;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_cfg). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_rcv_phy_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2680;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat1). The header gives no access direction or reset value; access r (established)
pub mod lsi_rcv_phy_stat1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2688;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat2). The header gives no access direction or reset value; access r (established)
pub mod lsi_rcv_phy_stat2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2690;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_stat3). The header gives no access direction or reset value; access r (established)
pub mod lsi_rcv_phy_stat3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2698;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_stat). The header gives no access direction or reset value; acces (established)
pub mod lsi_rcv_phy_int_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x26a0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_stat_test). The header gives no access direction or reset value;  (established)
pub mod lsi_rcv_phy_int_stat_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x26a8;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_rcv_phy_int_mask). The header gives no access direction or reset value; acces (established)
pub mod lsi_rcv_phy_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x26b0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_cfg). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_tx_phy_cfg {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2700;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_stat). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_tx_phy_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2708;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_stat). The header gives no access direction or reset value; access (established)
pub mod lsi_tx_phy_int_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2710;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_stat_test). The header gives no access direction or reset value; a (established)
pub mod lsi_tx_phy_int_stat_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2718;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_int_mask). The header gives no access direction or reset value; access (established)
pub mod lsi_tx_phy_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2720;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_tx_phy_stat2). The header gives no access direction or reset value; access rw (established)
pub mod lsi_tx_phy_stat2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2728;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg1). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_ltssm_cfg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2780;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg2). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_ltssm_cfg2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2788;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg3). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_ltssm_cfg3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2790;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg4). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_ltssm_cfg4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2798;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_cfg5). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_ltssm_cfg5 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x27a0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat1). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_ltssm_stat1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x27a8;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat2). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_ltssm_stat2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x27b0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_stat). The header gives no access direction or reset value; access  (established)
pub mod lsi_ltssm_int_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x27b8;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_stat_test). The header gives no access direction or reset value; ac (established)
pub mod lsi_ltssm_int_stat_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x27c0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_int_mask). The header gives no access direction or reset value; access  (established)
pub mod lsi_ltssm_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x27c8;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_ltssm_stat_wr_en). The header gives no access direction or reset value; acces (established)
pub mod lsi_ltssm_stat_wr_en {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x27d0;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg1). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_gb_cfg1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2800;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg2). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_gb_cfg2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2808;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg3). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_gb_cfg3 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2810;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_cfg4). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_gb_cfg4 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2818;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_stat). The header gives no access direction or reset value; access rw is a (established)
pub mod lsi_gb_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2820;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_stat). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_gb_int_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2828;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_stat_test). The header gives no access direction or reset value; acces (established)
pub mod lsi_gb_int_stat_test {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2830;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_int_mask). The header gives no access direction or reset value; access rw  (established)
pub mod lsi_gb_int_mask {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2838;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_pwr_dn1). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_gb_pwr_dn1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2840;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_lsi_gb_pwr_dn2). The header gives no access direction or reset value; access rw i (established)
pub mod lsi_gb_pwr_dn2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x2848;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 4096;
}
/// Name and offset are the vendor header's definition (struct member ce_crm_debug_mux). The header gives no access direction or reset value; access rw is (established)
pub mod crm_debug_mux {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4050;
}
/// Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_cmd_wrd). The header gives no access direction or reset value; access (established)
pub mod crm_ssp_err_cmd_wrd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4060;
}
/// Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_addr). The header gives no access direction or reset value; access rw (established)
pub mod crm_ssp_err_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4068;
}
/// Name and offset are the vendor header's definition (struct member ce_crm_ssp_err_syn). The header gives no access direction or reset value; access rw  (established)
pub mod crm_ssp_err_syn {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x4070;
}
/// Name and offset are the vendor header's definition (struct member ce_cxm_dyn_credit_status). The header gives no access direction or reset value; acce (established)
pub mod cxm_dyn_credit_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x5010;
}
/// Name and offset are the vendor header's definition (struct member ce_cxm_last_credit_status). The header gives no access direction or reset value; acc (established)
pub mod cxm_last_credit_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x5018;
}
/// Name and offset are the vendor header's definition (struct member ce_cxm_credit_limit). The header gives no access direction or reset value; access rw (established)
pub mod cxm_credit_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x5020;
}
/// Name and offset are the vendor header's definition (struct member ce_cxm_force_credit). The header gives no access direction or reset value; access rw (established)
pub mod cxm_force_credit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x5028;
}
/// Name and offset are the vendor header's definition (struct member ce_cxm_disable_bypass). The header gives no access direction or reset value; access  (established)
pub mod cxm_disable_bypass {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x5030;
}
/// Name and offset are the vendor header's definition (struct member ce_cxm_debug_mux). The header gives no access direction or reset value; access rw is (established)
pub mod cxm_debug_mux {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x5050;
}
/// Name and offset are the vendor header's definition (struct member ce_dtl_dtdr_credit_limit). The header gives no access direction or reset value; acce (established)
pub mod dtl_dtdr_credit_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x6000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_dtl_dtdr_credit_force). The header gives no access direction or reset value; acce (established)
pub mod dtl_dtdr_credit_force {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x6008;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_dtl_dyn_credit_status). The header gives no access direction or reset value; acce (established)
pub mod dtl_dyn_credit_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x6010;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_dtl_dtl_last_credit_stat). The header gives no access direction or reset value; a (established)
pub mod dtl_dtl_last_credit_stat {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x6018;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_dtl_dtl_ctrl). The header gives no access direction or reset value; access rw is  (established)
pub mod dtl_dtl_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x6020;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_dtl_debug_sel). The header gives no access direction or reset value; access rw is (established)
pub mod dtl_debug_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x6050;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_utl_utl_ctrl). The header gives no access direction or reset value; access rw is  (established)
pub mod utl_utl_ctrl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7000;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_utl_debug_sel). The header gives no access direction or reset value; access rw is (established)
pub mod utl_debug_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x7008;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8192;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_dyn_credit_status). The header gives no access direction or reset value; acce (established)
pub mod ure_dyn_credit_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb010;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_last_credit_status). The header gives no access direction or reset value; acc (established)
pub mod ure_last_credit_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb018;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_credit_limit). The header gives no access direction or reset value; access rw (established)
pub mod ure_credit_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb020;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_control). The header gives no access direction or reset value; access rw is a (established)
pub mod ure_control {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb030;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_status). The header gives no access direction or reset value; access rw is a  (established)
pub mod ure_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb038;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_debug_sel). The header gives no access direction or reset value; access rw is (established)
pub mod ure_debug_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb050;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie_debug_sel). The header gives no access direction or reset value; access  (established)
pub mod ure_pcie_debug_sel {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb058;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_ssp_err_cmd_wrd). The header gives no access direction or reset value; access (established)
pub mod ure_ssp_err_cmd_wrd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb060;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_ssp_err_addr). The header gives no access direction or reset value; access rw (established)
pub mod ure_ssp_err_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb068;
}
/// Upstream request engine page size map. The provider clears the page-size field and sets it to the 256 KiB encoding (4) at attach, the largest the code (established)
pub mod ure_page_map {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb070;
}
/// Upstream request engine direct map, one per port. For 32-bit direct DMA the provider stores the target's coretalk address with the low 30 bits cleared (established)
pub mod ure_dir_map {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb078;
    pub const COUNT: u32 = 2;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel1). The header gives no access direction or reset value; access rw is (established)
pub mod ure_pipe_sel1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb088;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask1). The header gives no access direction or reset value; access rw i (established)
pub mod ure_pipe_mask1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb090;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pipe_sel2). The header gives no access direction or reset value; access rw is (established)
pub mod ure_pipe_sel2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb098;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pipe_mask2). The header gives no access direction or reset value; access rw i (established)
pub mod ure_pipe_mask2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0a0;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credits_sent). The header gives no access direction or reset value; acc (established)
pub mod ure_pcie1_credits_sent {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0a8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credits_used). The header gives no access direction or reset value; acc (established)
pub mod ure_pcie1_credits_used {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0b0;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie1_credit_limit). The header gives no access direction or reset value; acc (established)
pub mod ure_pcie1_credit_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0b8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credits_sent). The header gives no access direction or reset value; acc (established)
pub mod ure_pcie2_credits_sent {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0c0;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credits_used). The header gives no access direction or reset value; acc (established)
pub mod ure_pcie2_credits_used {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0c8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie2_credit_limit). The header gives no access direction or reset value; acc (established)
pub mod ure_pcie2_credit_limit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0d0;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie_force_credit). The header gives no access direction or reset value; acce (established)
pub mod ure_pcie_force_credit {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0d8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_val). The header gives no access direction or reset value; access rw  (established)
pub mod ure_rd_tnum_val {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0e0;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_rsp_rcvd). The header gives no access direction or reset value; acces (established)
pub mod ure_rd_tnum_rsp_rcvd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0e8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_esent_timer). The header gives no access direction or reset value; ac (established)
pub mod ure_rd_tnum_esent_timer {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0f0;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_error). The header gives no access direction or reset value; access r (established)
pub mod ure_rd_tnum_error {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb0f8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_first_cl). The header gives no access direction or reset value; acces (established)
pub mod ure_rd_tnum_first_cl {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb100;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_rd_tnum_link_buf). The header gives no access direction or reset value; acces (established)
pub mod ure_rd_tnum_link_buf {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb108;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_wr_tnum_val). The header gives no access direction or reset value; access rw  (established)
pub mod ure_wr_tnum_val {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb110;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr0). The header gives no access direction or reset value; access  (established)
pub mod ure_sram_err_addr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb118;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr1). The header gives no access direction or reset value; access  (established)
pub mod ure_sram_err_addr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb120;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_err_addr2). The header gives no access direction or reset value; access  (established)
pub mod ure_sram_err_addr2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb128;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr0). The header gives no access direction or reset value; access r (established)
pub mod ure_sram_rd_addr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb130;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr1). The header gives no access direction or reset value; access r (established)
pub mod ure_sram_rd_addr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb138;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_rd_addr2). The header gives no access direction or reset value; access r (established)
pub mod ure_sram_rd_addr2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb140;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr0). The header gives no access direction or reset value; access r (established)
pub mod ure_sram_wr_addr0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb148;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr1). The header gives no access direction or reset value; access r (established)
pub mod ure_sram_wr_addr1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb150;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_sram_wr_addr2). The header gives no access direction or reset value; access r (established)
pub mod ure_sram_wr_addr2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb158;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush10). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush10 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb160;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush11). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush11 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb168;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush12). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush12 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb170;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush13). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush13 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb178;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush20). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush20 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb180;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush21). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush21 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb188;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush22). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush22 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb190;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_buf_flush23). The header gives no access direction or reset value; access rw  (established)
pub mod ure_buf_flush23 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb198;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie_control1). The header gives no access direction or reset value; access r (established)
pub mod ure_pcie_control1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb1a0;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_pcie_control2). The header gives no access direction or reset value; access r (established)
pub mod ure_pcie_control2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xb1a8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_data63_0). The header gives no access direction or reset value (established)
pub mod ure_maint_ups_dat1_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xc000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_data127_64). The header gives no access direction or reset val (established)
pub mod ure_maint_ups_dat1_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xd000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat1_parity). The header gives no access direction or reset value;  (established)
pub mod ure_maint_ups_dat1_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xe000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_data63_0). The header gives no access direction or reset value (established)
pub mod ure_maint_ups_hdr1_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0xf000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_data127_64). The header gives no access direction or reset val (established)
pub mod ure_maint_ups_hdr1_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x10000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr1_parity). The header gives no access direction or reset value;  (established)
pub mod ure_maint_ups_hdr1_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x11000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_data63_0). The header gives no access direction or reset value (established)
pub mod ure_maint_ups_dat2_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x12000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_data127_64). The header gives no access direction or reset val (established)
pub mod ure_maint_ups_dat2_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x13000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_dat2_parity). The header gives no access direction or reset value;  (established)
pub mod ure_maint_ups_dat2_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x14000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_data63_0). The header gives no access direction or reset value (established)
pub mod ure_maint_ups_hdr2_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x15000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_data127_64). The header gives no access direction or reset val (established)
pub mod ure_maint_ups_hdr2_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x16000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_ups_hdr2_parity). The header gives no access direction or reset value;  (established)
pub mod ure_maint_ups_hdr2_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x17000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_data63_0). The header gives no access direction or reset value; (established)
pub mod ure_maint_dns_dat_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x18000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_data127_64). The header gives no access direction or reset valu (established)
pub mod ure_maint_dns_dat_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x19000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_dat_parity). The header gives no access direction or reset value; a (established)
pub mod ure_maint_dns_dat_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1a000;
    pub const COUNT: u32 = 512;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_data31_0). The header gives no access direction or reset value; (established)
pub mod ure_maint_dns_hdr_data31_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1b000;
    pub const COUNT: u32 = 64;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_data95_32). The header gives no access direction or reset value (established)
pub mod ure_maint_dns_hdr_data95_32 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1b200;
    pub const COUNT: u32 = 64;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_dns_hdr_parity). The header gives no access direction or reset value; a (established)
pub mod ure_maint_dns_hdr_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1b400;
    pub const COUNT: u32 = 64;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_rci_data41_0). The header gives no access direction or reset value; acc (established)
pub mod ure_maint_rci_data41_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1b600;
    pub const COUNT: u32 = 64;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_rci_data69_42). The header gives no access direction or reset value; ac (established)
pub mod ure_maint_rci_data69_42 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1b800;
    pub const COUNT: u32 = 64;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_ure_maint_rspq). The header gives no access direction or reset value; access rw i (established)
pub mod ure_maint_rspq {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x1ba00;
    pub const COUNT: u32 = 64;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_data63_0). The header gives no access direction or reset value; (established)
pub mod adm_maint_bap_buf_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24000;
    pub const COUNT: u32 = 258;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_data127_64). The header gives no access direction or reset valu (established)
pub mod adm_maint_bap_buf_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x24810;
    pub const COUNT: u32 = 258;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_adm_maint_bap_buf_parity). The header gives no access direction or reset value; a (established)
pub mod adm_maint_bap_buf_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x25020;
    pub const COUNT: u32 = 258;
    pub const STRIDE: u64 = 8;
}
/// Upstream request engine 40-bit address translation entries, 4096 entries. The provider uses 64 MiB pages: bus address 0x4000000000 plus index times 64 (established)
pub mod ure_ate40 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x30000;
    pub const COUNT: u32 = 4096;
    pub const STRIDE: u64 = 8;
}
/// Upstream request engine 32/40-bit address translation entries, 2048 entries. Entries 0 to 31 serve port 1 and 32 to 63 port 2 for 16 GiB super-page ma (established)
pub mod ure_ate3240 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x38000;
    pub const COUNT: u32 = 2048;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_dyn_credit_status1). The header gives no access direction or reset value; acc (established)
pub mod dre_dyn_credit_status1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40010;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_dyn_credit_status2). The header gives no access direction or reset value; acc (established)
pub mod dre_dyn_credit_status2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40018;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_last_credit_status1). The header gives no access direction or reset value; ac (established)
pub mod dre_last_credit_status1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40020;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_last_credit_status2). The header gives no access direction or reset value; ac (established)
pub mod dre_last_credit_status2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40028;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_credit_limit1). The header gives no access direction or reset value; access r (established)
pub mod dre_credit_limit1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40030;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_credit_limit2). The header gives no access direction or reset value; access r (established)
pub mod dre_credit_limit2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40038;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_force_credit1). The header gives no access direction or reset value; access r (established)
pub mod dre_force_credit1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40040;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_force_credit2). The header gives no access direction or reset value; access r (established)
pub mod dre_force_credit2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40048;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_debug_mux1). The header gives no access direction or reset value; access rw i (established)
pub mod dre_debug_mux1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40050;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_debug_mux2). The header gives no access direction or reset value; access rw i (established)
pub mod dre_debug_mux2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40058;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_ssp_err_cmd_wrd). The header gives no access direction or reset value; access (established)
pub mod dre_ssp_err_cmd_wrd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40060;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_ssp_err_addr). The header gives no access direction or reset value; access rw (established)
pub mod dre_ssp_err_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40068;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_comp_err_cmd_wrd). The header gives no access direction or reset value; acces (established)
pub mod dre_comp_err_cmd_wrd {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40070;
}
/// Downstream request engine completion error address. The provider ORs zero into it at attach, after setting the interrupt and error summary alias bits, (established)
pub mod dre_comp_err_addr {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40078;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_req_status). The header gives no access direction or reset value; access rw i (established)
pub mod dre_req_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40080;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_config1). The header gives no access direction or reset value; access rw is a (established)
pub mod dre_config1 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40088;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_config2). The header gives no access direction or reset value; access rw is a (established)
pub mod dre_config2 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40090;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_config_req_status). The header gives no access direction or reset value; acce (established)
pub mod dre_config_req_status {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40098;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_dyn_fifo). The header gives no access direction or reset value; access rw is  (established)
pub mod dre_dyn_fifo {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40100;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_last_fifo). The header gives no access direction or reset value; access rw is (established)
pub mod dre_last_fifo {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40120;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_data63_0). The header gives no access direction or reset valu (established)
pub mod dre_maint_ds_head_q_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40200;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_data127_64). The header gives no access direction or reset va (established)
pub mod dre_maint_ds_head_q_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40300;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_head_q_parity). The header gives no access direction or reset value; (established)
pub mod dre_maint_ds_head_q_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x40400;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_data63_0). The header gives no access direction or reset valu (established)
pub mod dre_maint_ds_data_q_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x41000;
    pub const COUNT: u32 = 256;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_data127_64). The header gives no access direction or reset va (established)
pub mod dre_maint_ds_data_q_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x42000;
    pub const COUNT: u32 = 256;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ds_data_q_parity). The header gives no access direction or reset value; (established)
pub mod dre_maint_ds_data_q_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x43000;
    pub const COUNT: u32 = 256;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_data63_0). The header gives no access direction or reset v (established)
pub mod dre_maint_ure_us_rsp_q_data63_0 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x44000;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_data127_64). The header gives no access direction or reset (established)
pub mod dre_maint_ure_us_rsp_q_data127_64 {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x44100;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_ure_us_rsp_q_parity). The header gives no access direction or reset val (established)
pub mod dre_maint_ure_us_rsp_q_parity {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x44200;
    pub const COUNT: u32 = 8;
    pub const STRIDE: u64 = 8;
}
/// Name and offset are the vendor header's definition (struct member ce_dre_maint_us_wrt_rsp). The header gives no access direction or reset value; acces (established)
pub mod dre_maint_us_wrt_rsp {
    pub const WIDTH: u32 = 64;
    pub const OFFSET: u64 = 0x44300;
    pub const COUNT: u32 = 32;
    pub const STRIDE: u64 = 8;
}
pub const ADM_ERR_ADM_CREDIT_OFLOW: u64 = 0x400000000; // established
pub const ADM_ERR_ADM_SRAM_PE: u64 = 0x800000000; // established
pub const ADM_ERR_ADM_SSP_REQ_TIMEOUT: u32 = 0x80000000; // established
pub const ADM_ERR_ADM_SSP_RSP_UNEXP: u32 = 0x40000000; // established
pub const ADM_ERR_CRM_SSP_REQ_INVALID: u32 = 0x1; // established
pub const ADM_ERR_CXM_CREDIT_OFLOW: u32 = 0x40; // established
pub const ADM_ERR_DRE_CREDIT_OFLOW: u32 = 0x20000; // established
pub const ADM_ERR_DRE_SRAM_PE: u32 = 0x40000; // established
pub const ADM_ERR_DRE_SSP_REQ_INVAL: u32 = 0x80; // established
pub const ADM_ERR_DTL1_COMP_D_CRED_MAX_ERR: u64 = 0x20000000000; // established
pub const ADM_ERR_DTL1_COMP_HD_CRED_MAX_ERR: u64 = 0x10000000000; // established
pub const ADM_ERR_DTL1_INF_COMPL_CRED_UPDT_ERR: u64 = 0x2000000000; // established
pub const ADM_ERR_DTL1_INF_NPOSTED_CRED_UPDT_ERR: u64 = 0x8000000000; // established
pub const ADM_ERR_DTL1_INF_POSTED_CRED_UPDT_ERR: u64 = 0x4000000000; // established
pub const ADM_ERR_DTL1_MIN_PDATA_CREDIT_ERR: u64 = 0x1000000000; // established
pub const ADM_ERR_DTL1_NPOSTED_D_CRED_MAX_ERR: u64 = 0x80000000000; // established
pub const ADM_ERR_DTL1_NPOSTED_HD_CRED_MAX_ERR: u64 = 0x40000000000; // established
pub const ADM_ERR_DTL1_POSTED_D_CRED_MAX_ERR: u64 = 0x200000000000; // established
pub const ADM_ERR_DTL1_POSTED_HD_CRED_MAX_ERR: u64 = 0x100000000000; // established
pub const ADM_ERR_DTL2_COMP_D_CRED_MAX_ERR: u64 = 0x8000000000000; // established
pub const ADM_ERR_DTL2_COMP_HD_CRED_MAX_ERR: u64 = 0x4000000000000; // established
pub const ADM_ERR_DTL2_INF_COMPL_CRED_UPDT_ERR: u64 = 0x800000000000; // established
pub const ADM_ERR_DTL2_INF_NPOSTED_CRED_UPDT_ERR: u64 = 0x2000000000000; // established
pub const ADM_ERR_DTL2_INF_POSTED_CRED_UPDT_ERR: u64 = 0x1000000000000; // established
pub const ADM_ERR_DTL2_MIN_PDATA_CREDIT_ERR: u64 = 0x400000000000; // established
pub const ADM_ERR_DTL2_NPOSTED_D_CRED_MAX_ERR: u64 = 0x20000000000000; // established
pub const ADM_ERR_DTL2_NPOSTED_HD_CRED_MAX_ERR: u64 = 0x10000000000000; // established
pub const ADM_ERR_DTL2_POSTED_D_CRED_MAX_ERR: u64 = 0x80000000000000; // established
pub const ADM_ERR_DTL2_POSTED_HD_CRED_MAX_ERR: u64 = 0x40000000000000; // established
pub const ADM_ERR_MMR_ACCESS_ERROR: u64 = 0x100000000; // established
pub const ADM_ERR_MMR_ADDR_ERROR: u64 = 0x200000000; // established
pub const ADM_ERR_PCIE_COMPL_TIMEOUT: u32 = 0x4000; // established
pub const ADM_ERR_PCIE_ERR_COMPL: u32 = 0x10000; // established
pub const ADM_ERR_PCIE_UNEXP_COMPL: u32 = 0x8000; // established
pub const ADM_ERR_PORT1_PCIE_COR_ERR: u64 = 0x100000000000000; // established
pub const ADM_ERR_PORT1_PCIE_FAT_ERR: u64 = 0x400000000000000; // established
pub const ADM_ERR_PORT1_PCIE_NFAT_ERR: u64 = 0x200000000000000; // established
pub const ADM_ERR_PORT2_PCIE_COR_ERR: u64 = 0x800000000000000; // established
pub const ADM_ERR_PORT2_PCIE_FAT_ERR: u64 = 0x2000000000000000; // established
pub const ADM_ERR_PORT2_PCIE_NFAT_ERR: u64 = 0x1000000000000000; // established
pub const ADM_ERR_SSP_MBE: u32 = 0x20; // established
pub const ADM_ERR_SSP_PROTOCOL_ERROR: u32 = 0x8; // established
pub const ADM_ERR_SSP_REQ_ADDR_ERR: u32 = 0x1000; // established
pub const ADM_ERR_SSP_REQ_BAD_BE: u32 = 0x2000; // established
pub const ADM_ERR_SSP_REQ_HEADER: u32 = 0x2; // established
pub const ADM_ERR_SSP_REQ_LONG: u32 = 0x100; // established
pub const ADM_ERR_SSP_REQ_OFLOW: u32 = 0x200; // established
pub const ADM_ERR_SSP_REQ_SHORT: u32 = 0x400; // established
pub const ADM_ERR_SSP_REQ_SIDEBAND: u32 = 0x800; // established
pub const ADM_ERR_SSP_RSP_HEADER: u32 = 0x4; // established
pub const ADM_ERR_SSP_RSP_INVALID: u32 = 0x80000; // established
pub const ADM_ERR_SSP_RSP_LONG: u32 = 0x100000; // established
pub const ADM_ERR_SSP_RSP_SHORT: u32 = 0x200000; // established
pub const ADM_ERR_SSP_RSP_SIDEBAND: u32 = 0x400000; // established
pub const ADM_ERR_SSP_SBE: u32 = 0x10; // established
pub const ADM_ERR_URE_ATE3240_PAGE_FAULT: u32 = 0x4000000; // established
pub const ADM_ERR_URE_ATE40_PAGE_FAULT: u32 = 0x8000000; // established
pub const ADM_ERR_URE_CREDIT_OFLOW: u32 = 0x10000000; // established
pub const ADM_ERR_URE_SRAM_PE: u32 = 0x20000000; // established
pub const ADM_ERR_URE_SSP_RD_REQ_TIMEOUT: u32 = 0x2000000; // established
pub const ADM_ERR_URE_SSP_RSP_UNEXP: u32 = 0x800000; // established
pub const ADM_ERR_URE_SSP_WR_REQ_TIMEOUT: u32 = 0x1000000; // established
pub const ADM_FORCE_INT_ALWAYS_SHFT: u32 = 0x8; // established
pub const ADM_FORCE_INT_PCIE_PORT1_DEV_A_SHFT: u32 = 0x0; // established
pub const ADM_FORCE_INT_PCIE_PORT1_DEV_B_SHFT: u32 = 0x1; // established
pub const ADM_FORCE_INT_PCIE_PORT1_DEV_C_SHFT: u32 = 0x2; // established
pub const ADM_FORCE_INT_PCIE_PORT1_DEV_D_SHFT: u32 = 0x3; // established
pub const ADM_FORCE_INT_PCIE_PORT2_DEV_A_SHFT: u32 = 0x4; // established
pub const ADM_FORCE_INT_PCIE_PORT2_DEV_B_SHFT: u32 = 0x5; // established
pub const ADM_FORCE_INT_PCIE_PORT2_DEV_C_SHFT: u32 = 0x6; // established
pub const ADM_FORCE_INT_PCIE_PORT2_DEV_D_SHFT: u32 = 0x7; // established
pub const ADM_INT_CE_ERROR_SHFT: u32 = 0x0; // established
pub const ADM_INT_LSI1_IP_ERROR_SHFT: u32 = 0x1; // established
pub const ADM_INT_LSI2_IP_ERROR_SHFT: u32 = 0x2; // established
pub const ADM_INT_PCIE_ERROR_SHFT: u32 = 0x3; // established
pub const ADM_INT_PCIE_MSG_SHFT: u32 = 0xe; // established
pub const ADM_INT_PCIE_MSG_SLOT_0_SHFT: u32 = 0xe; // established
pub const ADM_INT_PCIE_MSG_SLOT_1_SHFT: u32 = 0xf; // established
pub const ADM_INT_PCIE_MSG_SLOT_2_SHFT: u32 = 0x10; // established
pub const ADM_INT_PCIE_MSG_SLOT_3_SHFT: u32 = 0x11; // established
pub const ADM_INT_PCIE_PORT1_DEV_A_SHFT: u32 = 0x6; // established
pub const ADM_INT_PCIE_PORT1_DEV_B_SHFT: u32 = 0x7; // established
pub const ADM_INT_PCIE_PORT1_DEV_C_SHFT: u32 = 0x8; // established
pub const ADM_INT_PCIE_PORT1_DEV_D_SHFT: u32 = 0x9; // established
pub const ADM_INT_PCIE_PORT2_DEV_A_SHFT: u32 = 0xa; // established
pub const ADM_INT_PCIE_PORT2_DEV_B_SHFT: u32 = 0xb; // established
pub const ADM_INT_PCIE_PORT2_DEV_C_SHFT: u32 = 0xc; // established
pub const ADM_INT_PCIE_PORT2_DEV_D_SHFT: u32 = 0xd; // established
pub const ADM_INT_PORT1_HOTPLUG_EVENT_SHFT: u32 = 0x4; // established
pub const ADM_INT_PORT1_PM_PME_MSG_SHFT: u32 = 0x16; // established
pub const ADM_INT_PORT2_HOTPLUG_EVENT_SHFT: u32 = 0x5; // established
pub const ADM_INT_PORT2_PM_PME_MSG_SHFT: u32 = 0x17; // established
pub const BUS_SRC_ID_SHFT: u32 = 0x8; // established
pub const DEV_SRC_ID_SHFT: u32 = 0x3; // established
pub const DRE_ADDR_MODE_SHFT: u32 = 0x4; // established
pub const DRE_CONFIG_COMPLETION_VALID: u32 = 0x10; // established
pub const DRE_CONFIG_REQUEST_ACTIVE: u32 = 0x20; // established
pub const DRE_DOWNSTREAM_CONFIG_ERROR: u32 = 0x8; // established
pub const DRE_DYN_RO_ENABLE: u32 = 0x2; // established
pub const DRE_LAST_CONFIG_COMPLETION: u32 = 0x7; // established
pub const DRE_RO_ENABLE: u32 = 0x1; // established
pub const DRE_SUP_CONFIG_COMP_ERROR: u32 = 0x4; // established
pub const DRE_SUP_IO_COMP_ERROR: u32 = 0x8; // established
pub const E_CONFIG_BUS_SHFT: u32 = 0x14; // established
pub const E_CONFIG_DEVICE_SHFT: u32 = 0xf; // established
pub const E_CONFIG_FUNC_SHFT: u32 = 0xc; // established
pub const FNC_SRC_ID_SHFT: u32 = 0x0; // established
pub const HOST_BRIDGE_DEVICE_ID: u32 = 0x4001; // established
pub const HOST_BRIDGE_VENDOR_ID: u32 = 0x10a9; // established
pub const INTR_VECTOR_SHFT: u32 = 0x38; // established
pub const LSI_GB_CFG1_LPBK_EN_MASK: u32 = 0x40000; // established
pub const LSI_GB_CFG1_LPBK_EN_SHFT: u32 = 0x12; // established
pub const LSI_GB_CFG1_LPBK_SEL_MASK: u32 = 0x30000; // established
pub const LSI_GB_CFG1_LPBK_SEL_SHFT: u32 = 0x10; // established
pub const LSI_GB_CFG1_RVRS_CLK_MASK: u32 = 0x300000; // established
pub const LSI_GB_CFG1_RVRS_CLK_SHFT: u32 = 0x14; // established
pub const LSI_GB_CFG1_RVRS_LB_MASK: u32 = 0x80000; // established
pub const LSI_GB_CFG1_RVRS_LB_SHFT: u32 = 0x13; // established
pub const LSI_GB_CFG1_RXL0S_ADJ_MASK: u32 = 0x7000; // established
pub const LSI_GB_CFG1_RXL0S_ADJ_SHFT: u32 = 0xc; // established
pub const LSI_GB_CFG1_RXL0S_FLT_MASK: u32 = 0x8000; // established
pub const LSI_GB_CFG1_RXL0S_FLT_SHFT: u32 = 0xf; // established
pub const LSI_GB_CFG1_RXL0S_SMP_MASK: u32 = 0xf00; // established
pub const LSI_GB_CFG1_RXL0S_SMP_SHFT: u32 = 0x8; // established
pub const LSI_GB_CFG1_RXL0S_THS_MASK: u32 = 0xff; // established
pub const LSI_GB_CFG1_RXL0S_THS_SHFT: u32 = 0x0; // established
pub const LSI_GB_CFG1_SLF_TS_MASK: u32 = 0xf000000; // established
pub const LSI_GB_CFG1_SLF_TS_SHFT: u32 = 0x18; // established
pub const NUM_M3240_ATES: u32 = 0x800; // established
pub const NUM_M40_ATES: u32 = 0x1000; // established
pub const NUM_PORTS: u32 = 0x2; // established
pub const PART_NUM: u32 = 0xce00; // established
pub const PIO_CONFIG_SPACE: u32 = 0x4000000; // established
pub const PIO_CONFIG_SPACE_LEN: u32 = 0x4000000; // established
pub const PIO_E_CONFIG_SPACE: u32 = 0x10000000; // established
pub const PIO_E_CONFIG_SPACE_LEN: u32 = 0x10000000; // established
pub const PIO_IO_SPACE: u64 = 0x100000000; // established
pub const PIO_IO_SPACE_ALIAS: u32 = 0x8000000; // established
pub const PIO_IO_SPACE_ALIAS_LEN: u32 = 0x8000000; // established
pub const PIO_IO_SPACE_LEN: u64 = 0x100000000; // established
pub const PIO_MEM_SPACE: u64 = 0x200000000; // established
pub const PIO_MMR: u32 = 0x0; // established
pub const PIO_MMR_LEN: u32 = 0x4000000; // established
pub const PKT_TRAFIC_SHRT: u32 = 0x10; // established
pub const REV_A: u32 = 0x1; // established
pub const SRC_ID: u32 = 0x1; // established
pub const URE_ABP: u32 = 0x1; // established
pub const URE_AIP: u32 = 0x8; // established
pub const URE_ATE3240_ENABLE: u32 = 0x1; // established
pub const URE_ATE40_ENABLE: u32 = 0x2; // established
pub const URE_ATE_PAR_DISABLE: u64 = 0x1000000000; // established
pub const URE_DNS_DAT_PAR_DISABLE: u64 = 0x8000000000; // established
pub const URE_DNS_HDR_PAR_DISABLE: u64 = 0x10000000000; // established
pub const URE_ELAL1_SHFT: u32 = 0x8; // established
pub const URE_ELAL_SHFT: u32 = 0x4; // established
pub const URE_HPC: u32 = 0x40; // established
pub const URE_HPS: u32 = 0x20; // established
pub const URE_MALFORM_DISABLE: u64 = 0x100000000000; // established
pub const URE_MASK1_SHFT: u32 = 0x0; // established
pub const URE_MASK2_SHFT: u32 = 0x14; // established
pub const URE_MASK3_SHFT: u32 = 0x28; // established
pub const URE_MSP: u32 = 0x4; // established
pub const URE_PAGESIZE_SHFT: u32 = 0x4; // established
pub const URE_PCP: u32 = 0x2; // established
pub const URE_PIP: u32 = 0x10; // established
pub const URE_PN1_SHFT: u32 = 0x10; // established
pub const URE_PN2_SHFT: u32 = 0x18; // established
pub const URE_PSN1_SHFT: u32 = 0x13; // established
pub const URE_PSN2_SHFT: u32 = 0x20; // established
pub const URE_RCI_PAR_DISABLE: u64 = 0x2000000000; // established
pub const URE_RD_MRG_ENABLE: u32 = 0x1; // established
pub const URE_RSPQ_BYPASS_DISABLE: u32 = 0x1000000; // established
pub const URE_RSPQ_PAR_DISABLE: u64 = 0x4000000000; // established
pub const URE_SCC: u32 = 0x1000; // established
pub const URE_SEL1_SHFT: u32 = 0x0; // established
pub const URE_SEL2_SHFT: u32 = 0x14; // established
pub const URE_SEL3_SHFT: u32 = 0x28; // established
pub const URE_SI: u32 = 0x1; // established
pub const URE_SPLS_SHFT: u32 = 0xf; // established
pub const URE_SPLV_SHFT: u32 = 0x7; // established
pub const URE_UNSUP_DISABLE: u64 = 0x200000000000; // established
pub const URE_UPS_DAT1_PAR_DISABLE: u64 = 0x100000000; // established
pub const URE_UPS_DAT2_PAR_DISABLE: u64 = 0x400000000; // established
pub const URE_UPS_HDR1_PAR_DISABLE: u64 = 0x200000000; // established
pub const URE_UPS_HDR2_PAR_DISABLE: u64 = 0x800000000; // established
pub const URE_WRT_MRG_ENABLE1: u32 = 0x10; // established
pub const URE_WRT_MRG_ENABLE2: u32 = 0x20; // established
pub const URE_WRT_MRG_TIMER_SHFT: u32 = 0xc; // established
pub const VIRT_PPB_DEVICE_ID: u32 = 0x4002; // established
pub const VIRT_PPB_VENDOR_ID: u32 = 0x10a9; // established
