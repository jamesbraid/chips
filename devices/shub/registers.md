<!-- generated from devices/shub/registers.toml by defs-gen - do not edit, change the source -->

# SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs

SHub 1 offsets as the SGI Linux ia64 platform header defines them (SH1_ names), relative to the node's register space; the SHub 2 overlay changes them. Every register is 64 bits wide unless noted, because the kernel reaches all of them with 64-bit loads and stores. The header gives neither the unit a register belongs to nor reset values; the unit named in each doc is inferred from the register's name prefix and address block. Reset values are unknown except where the header's INIT macro names a value, which is recorded as inferred. Roles are paraphrased from the header comments and the kernel's use. For a register Linux does not define, a register-level grade of established covers the offset, width and direction read in the PROM image; what the register means is graded in its fields and doc, inferred unless stated.

Unit `shub`, macro prefix `SHUB`.
Default source: Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `chip_id` | 0x100000000 | r | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa0be1c (read), 0xffa0f8c0 (storage of the fields), 0xffa0f7e0 (table walk), 0xffa959a6 (compare against 17251) |
| `md_mbist_status` | 0x100000080 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6fbac (written 0 at engine start); bit 36 read at site 0xffa702c0 and 0xffa72500; no Linux v5.3 name |
| `md_mbist_err` | 0x1000000b8 | r | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa725f6 (read in the failure report); no Linux v5.3 name |
| `md_mbist_mask` | 0x1000000c0 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6fbdc (written all ones at engine start); no Linux v5.3 name |
| `md_bank_cfg0` | 0x100010000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7701c (write); no Linux v5.3 name |
| `md_bank_cfg1` | 0x100010008 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa76c3c (read), 0xffa7704c (write), 0xffa6dedc and 0xffa7ab9c (reads for the bank size); no Linux v5.3 name |
| `md_bank_cfg2` | 0x100010010 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7707c (write), 0xffa6f2fc and 0xffa7838c (reads); no Linux v5.3 name |
| `md_timing_0` | 0x100010020 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7710c (write); no Linux v5.3 name |
| `md_timing_1` | 0x100010028 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa770ac (write); no Linux v5.3 name |
| `md_refresh_0` | 0x100010030 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa77adc (write); no Linux v5.3 name |
| `md_timing_2` | 0x100010040 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa76c9c (read), 0xffa7713c (write); no Linux v5.3 name |
| `md_timing_3` | 0x100010048 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa76c6c (read), 0xffa770dc (write); no Linux v5.3 name |
| `md_refresh_1` | 0x100010050 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7761c (read), 0xffa77b0c (write); no Linux v5.3 name |
| `md_const_58` | 0x100010058 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7745c (write); no Linux v5.3 name |
| `md_ctl_60` | 0x100010060 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa773cc (write), 0xffa7738c (revision read); no Linux v5.3 name |
| `md_reg_0001_0068` | 0x100010068 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7ab6c (read), 0xffa7acdc and 0xffa7ad9c (writes) |
| `md_const_78` | 0x100010078 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7748c (write); no Linux v5.3 name |
| `md_mbist_cmd` | 0x100020080 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6fb7c (written first when the engine starts); no Linux v5.3 name |
| `md_mbist_ctl` | 0x100020088 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6fc3c (start), 0xffa6fd3c and 0xffa6fddc (poll), 0xffa6b1dc (failure test); no Linux v5.3 name |
| `md_reg_0003_0000` | 0x100030000 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM sites 0xffa785cc (read) and 0xffa785ec (write); no Linux v5.3 name |
| `md_reg_0003_0200` | 0x100030200 | w | 64 | 8 |  | unknown | established | SAL 5.04 PROM site 0xffa7729c (write loop); no Linux v5.3 name |
| `md_dqlp_dir_privilege_vector` | 0x100030300 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `md_reg_0003_0400` | 0x100030400 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa773fc (write); the only reference to the address in SAL_A and SAL_B |
| `md_dir_access_lp` | 0x100031000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6b10c (memctl_write_dir_access, the string the routine prints); no Linux v5.3 name |
| `md_bist_data_a0` | 0x100038000 | w | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name |
| `md_bist_data_b0` | 0x100038010 | w | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name |
| `md_bist_data_a1` | 0x100038800 | w | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name |
| `md_bist_data_b1` | 0x100038810 | w | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffa703d0 (the pattern programming routine); no Linux v5.3 name |
| `md_reg_0005_0000` | 0x100050000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7861c (write); no Linux v5.3 name |
| `md_reg_0005_0200` | 0x100050200 | w | 64 | 8 |  | unknown | established | SAL 5.04 PROM site 0xffa7732c (write loop); no Linux v5.3 name |
| `md_dqrp_dir_privilege_vector` | 0x100050300 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `md_reg_0005_0400` | 0x100050400 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa7742c (write); the only reference to the address in SAL_A and SAL_B |
| `md_dir_access_rp` | 0x100051000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6b14c; no Linux v5.3 name |
| `ii_int` | 0x110000000 | w | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ii_int_config` | 0x110000080 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ii_int_enable` | 0x110000200 | rw | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `int_node_id_config` | 0x110000300 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffb73d76 and 0xffa23b16 (0x800 plus the target NASID in bits 10:0) |
| `ipi_int` | 0x110000380 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ipi_int_enable` | 0x110000400 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa11056 (wake-up of the other processors) and 0xffa314a6; runtime cpu_launch_slave_threads |
| `local_int_config` | 0x110000480 | rw | 64 | 6 |  | unknown | established | SAL 5.04 PROM sites 0xffa23a20 (interrupts 0 and 1, PMI vector 1), 0xffa31290 (interrupts 2 and 3, INIT), 0xffb73b86 (interrupt 5, vector 0xe9) |
| `local_int_enable` | 0x110000500 | rw | 64 | 6 |  | unknown | established | SAL 5.04 PROM sites 0xffa23a20 (0x7ef to interrupts 0 and 1), 0xffa31290 (0x4000 to interrupts 2 and 3), 0xffb73bc6 (0x2000 to interrupt 5) |
| `rtc0_int_config` | 0x110001380 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa31966 (pid << 4 plus 8: agent bit set, type 0, vector 0); runtime plat_assert_berr |
| `rtc0_int_enable` | 0x110001400 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa31a06 (write 1), 0xffa31d76 (write 0) |
| `rtc_int_config` | 0x110001480 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc_int_enable` | 0x110001500 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred` | 0x110010000 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred_alias` | 0x110010008 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_overflow` | 0x110010080 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM register-name table (SH_EVENT_OVERFLOW, pairing by table order); the PROM never accesses it |
| `event_overflow_alias` | 0x110010088 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa0bb46 (write 8) |
| `lb_reg_1002_0000` | 0x110020000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e7f0 (offset and use); no Linux v5.3 name |
| `lb_slice_rec` | 0x110030000 | r | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffa0e020 (read of the running processor's entry), 0xffc4e570 (not reached for reason 0) |
| `lb_liq_ctl` | 0x110040000 | rw | 64 |  |  | 0x0 (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_LB_LIQ_CTL_INIT macro, value zero; no source states a power-on default) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_LB_LIQ_CTL, 'Local Block LIQ Control' (name, offset, mask 0x70f1f, fields); the PROM's register-name table carries the name (SAL 5.04 image, record 132 of the table from 0xffbfabb0); SAL 5.04 PROM site 0xffa95ccc (read), 0xffa95cfc (write) |
| `lb_max_rep_credit_cnt` | 0x110040100 | rw | 64 |  |  | 0x1f (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_LB_MAX_REP_CREDIT_CNT_INIT macro, value 0x1f) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_LB_MAX_REP_CREDIT_CNT (name, offset, mask 0x1f, field); the PROM's register-name table carries the name (record 134); SAL 5.04 PROM site 0xffa95f3c (read), 0xffa95f6c (write) |
| `lb_max_req_credit_cnt` | 0x110040180 | rw | 64 |  |  | 0x1f (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_LB_MAX_REQ_CREDIT_CNT_INIT macro, value 0x1f) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_LB_MAX_REQ_CREDIT_CNT (name, offset, mask 0x1f, field); the PROM's register-name table carries the name (record 135); SAL 5.04 PROM site 0xffa95f7c (read), 0xffa95fbc (write) |
| `conveyor_belt_time_out` | 0x110040300 | rw | 64 |  |  | 0x0 (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_CONVEYOR_BELT_TIME_OUT_INIT macro, value zero) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CONVEYOR_BELT_TIME_OUT (name, offset, mask 0xfff, field); the PROM's register-name table carries the name (record 138); SAL 5.04 PROM site 0xffa9613c (read), 0xffa9615c (write) |
| `rtc_ctl` | 0x110060280 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa94d06, 0xffa94d26 (writes), 0xffa0da00 (read of the period); the SAL runtime component's chipset_rtc_period reads the same field |
| `ipi_access` | 0x110060480 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `md_clk_sel` | 0x110060500 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa77e0c (read through the node's global window), 0xffa77e20 (mask); no Linux v5.3 name |
| `shub_id` | 0x110060580 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ptc` | 0x1101a0000 | w | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ptc_parms` | 0x1101a0100 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa960a6 (write, then read back); the PROM's table lists it as SH_PTC_PARMS |
| `int_cmpa` | 0x1101b0000 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa319e6 (the counter plus the delay in ticks) |
| `int_cmp` | 0x1101b0080 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc` | 0x1101c0000 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `lb_elect` | 0x1101d0080 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e9b0, 0xffc4e766 (election reads), 0xffc4e246, 0xffa0b0f0 (bit updates); no Linux v5.3 name |
| `lb_elect_set` | 0x1101d0088 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e9a6 (release store of slice + 1); no Linux v5.3 name |
| `lb_l1_state` | 0x1101d0100 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e790 and 0xffc4e7a0 (read-modify-write); the PROM's runtime also names the word sc_shub_state_reg and sc_shub_pushed_data_reg |
| `lb_lock2` | 0x1101d0180 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa0ee40 (release, shared with lb_lock), 0xffa0ed30 (forced release on timeout), 0xffa0eee0 (release on another node), 0xffa0f046 and 0xffa0f5a6 (callers) |
| `lb_lock2_status` | 0x1101d0188 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa0ed30 (this-node poll), 0xffa0ad80 (other-node poll), 0xffa0ef40 (descriptor entry), 0xffa0f056 and 0xffa0f5b6 (callers) |
| `lb_lock` | 0x1101d0200 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa0ed30 (take), 0xffa0ee40 (release), 0xffa0e730 (user) |
| `lb_lock_status` | 0x1101d0208 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa0ed30 (the poll); the offset-form variant site 0xffa0e880 reads 0x1101d0208 on a remote node |
| `crb_message_control` | 0x120000000 | rw | 64 |  |  | 0x6 (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_CRB_MESSAGE_CONTROL_INIT macro (value 6); the macro name says initial value, no source states a power-on default) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_MESSAGE_CONTROL, 'Coherent Request Buffer Message Control' (name, offset, bits 11:0 and 63:32); the PROM's own register-name table carries the same name (SAL 5.04 image, table site 0xffbfd280, followed by NACK_LIMIT and TIMEOUT_PRESCALE in the header's order); SAL 5.04 PROM site 0xffa97796 to 0xffa97916 (read, OR, write) and site 0xffc4e276 (SAL_A error path). Linux v5.3 dropped the register |
| `crb_nack_limit` | 0x120000080 | rw | 64 |  |  | 0x0 (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_CRB_NACK_LIMIT_INIT macro, value zero) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_NACK_LIMIT (name, offset, fields); the PROM's register-name table carries the name at the next entry after SH_CRB_MESSAGE_CONTROL |
| `crb_timeout_prescale` | 0x120000100 | rw | 64 |  |  | 0x0 (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_CRB_TIMEOUT_PRESCALE_INIT macro, value zero) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_TIMEOUT_PRESCALE (name, offset, field); the PROM's register-name table carries the name two entries after SH_CRB_MESSAGE_CONTROL |
| `crb_timeout_skid` | 0x120000180 | rw | 64 |  |  | 0x7 (inferred; SGI Linux 2.4 ia64 SN2 header: the SH_CRB_TIMEOUT_SKID_INIT macro, value 7) | established | SGI Linux 2.4 ia64 SN2 platform MMR header (linux-2.4 branch of the MIPS-tree mirror, commit 8ef7d46c94d5): SH_CRB_TIMEOUT_SKID (name, offset, fields); SAL 5.04 PROM site 0xffa2459c to 0xffa245cc (read, OR bit 63, write); other sites site 0xffae3696 |
| `pi_reg_2001_0100` | 0x120010100 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e800 and 0xffc4e816 (read-modify-write); Linux v5.3 defines no name |
| `pi_slice_present` | 0x120020080 | r | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa115ac (read through the global window of the node), 0xffa99e2c (caller) |
| `pi_cam_control` | 0x120050300 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pi_reg_2006_0100` | 0x120060100 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa246a6 (read after the pi_cam_control write); no Linux v5.3 name |
| `pi_reg_2006_0180` | 0x120060180 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa246d6; no Linux v5.3 name |
| `pi_reg_2006_0200` | 0x120060200 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa246f6; no Linux v5.3 name |
| `pio_write_status` | 0x120070200 | r | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pio_write_status_alias` | 0x120070208 | w | 64 | 2 |  | unknown | inferred | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_lb_cmp_exp_data1` | 0x150031110 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_lb_cmp_enable0` | 0x150031120 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_lb_cmp_enable1` | 0x150031130 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ii_cmp_exp_data0` | 0x150031140 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ii_cmp_exp_data1` | 0x150031150 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ii_cmp_enable0` | 0x150031160 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ii_cmp_enable1` | 0x150031170 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_md_cmp_exp_data0` | 0x150031180 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_md_cmp_exp_data1` | 0x150031190 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_md_cmp_enable0` | 0x1500311a0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_md_cmp_enable1` | 0x1500311b0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_pi_cmp_exp_data0` | 0x1500311c0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_pi_cmp_exp_data1` | 0x1500311d0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_pi_cmp_enable0` | 0x1500311e0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_pi_cmp_enable1` | 0x1500311f0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ni0_cmp_exp_data0` | 0x150031200 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ni0_cmp_exp_data1` | 0x150031210 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ni0_cmp_enable0` | 0x150031220 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ni0_cmp_enable1` | 0x150031230 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ni1_cmp_exp_data0` | 0x150031240 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ni1_cmp_enable0` | 0x150031260 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_iilb_ni1_cmp_enable1` | 0x150031270 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_iilb_cmp_exp_data0` | 0x150031300 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_iilb_cmp_exp_data1` | 0x150031310 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_iilb_cmp_enable0` | 0x150031320 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_iilb_cmp_enable1` | 0x150031330 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_ni0_cmp_exp_data0` | 0x150031340 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_ni0_cmp_enable0` | 0x150031360 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_ni0_cmp_enable1` | 0x150031370 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_sic_cmp_exp_hdr0` | 0x1500313c0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_sic_cmp_exp_hdr1` | 0x1500313d0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_sic_cmp_hdr_enable0` | 0x1500313e0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_pi_sic_cmp_hdr_enable1` | 0x1500313f0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `cpu_hist` | 0x150031500 | rw | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffc4e5c6 and 0xffc4e5e0 (progress write), 0xffa0ddb0; no Linux v5.3 name; SGI 2.4 SN2 header (linux-mips linux-2.4 8ef7d46c94d5) names the offset |
| `fw_word_1540` | 0x150031540 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffc4ea06 (zeroed by the election winner), 0xffa0efd0 to 0xffa0f640 (bit methods), 0xffa5d48c (zeroed on another node); no Linux v5.3 name; SGI 2.4 SN2 header (linux-mips linux-2.4 8ef7d46c94d5) names the offset |
| `cpu_bits` | 0x150031550 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4ea00 (zeroed), 0xffa0e730 (set and clear a bit under the lock), 0xffa1d430 (test), 0xffa99cf0 and 0xffa9a130 (arbitration); no Linux v5.3 name; SGI 2.4 SN2 header (linux-mips linux-2.4 8ef7d46c94d5) names the offset |
| `fw_debug_word` | 0x150031560 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffc4ea10 (zeroed in SAL_A), 0xffa19e50 (loaded from the L1 reply in phase 0xe), 0xffa975e0 (bit test), 0xffa974d0 (field setter) |
| `xn_md_ni0_cmp_enable1` | 0x150031570 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_ni1_cmp_exp_data0` | 0x150031580 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_ni1_cmp_exp_data1` | 0x150031590 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_ni1_cmp_enable0` | 0x1500315a0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_ni1_cmp_enable1` | 0x1500315b0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_exp_hdr0` | 0x1500315c0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_hdr_enable0` | 0x1500315e0 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data0` | 0x150031600 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data1` | 0x150031610 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data2` | 0x150031620 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data3` | 0x150031630 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data_enable0` | 0x150031640 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data_enable1` | 0x150031650 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data_enable2` | 0x150031660 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `xn_md_sic_cmp_data_enable3` | 0x150031670 | rw | 64 |  |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `junk_bus_led` | 0x7fed00000 | w | 16 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |

### Register `chip_id`

Chip identification word at node offset 0x1_0000_0000 (memory and directory block by address); the name is ours. The PROM reads it through the node's global window at node start and stores bits 27:12 as the node's part number and bits 31:28 as its revision. It then offers the part number to four method tables in turn, each of which accepts one value (0x4363, 0x3017, 0x239, 0x4422), and keeps the first match; a part number outside the four stores a null table that two later callers call through without a test. Established covers the access and that chain, read in full; that the field is a part number is inferred, and which chips the other three values belong to is unknown. A bounded read that returns 0x4363 selects the first table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `revision` | inferred |  | SAL 5.04 PROM site 0xffa0f8c0 (stored) | Revision as stored by the PROM (that the field is a revision is inferred); no value is required here. |
| 27:12 | `part_number` | established |  | SAL 5.04 PROM site 0xffa0f8c0, 0xffa0f7e0 and 0xffa959a6 | Part number, as the PROM names it (inferred). Software expectation, read in full: 0x4363 (17251) selects the first of four method tables; 0x3017, 0x239 and 0x4422 select the others, and any other value ends in a call through a null table. Established is the required value, not what the number identifies. |

### Register `md_mbist_status`

Memory test engine status; the name is ours. Written 0 before every engine start. Bit 36 is read after each operation 16 poll (site 0xffa702c0, inside the compare wrapper) and treated as failure when set, so it must read 0 on a passing run; the failure report reads it again; with bit 36 set it runs a diagnosis (site 0xffa708e0) that reads bit 36 once more, with bit 36 clear it reads md_mbist_err. Operation 48, the directory write and the DRAM commands never read it. Bits 32:0 are read in the failure report as the failing address in 8-byte units. Plain storage satisfies the PROM. The flag name (compare error) is inferred. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 36 | `cmp_err` | inferred |  | SAL 5.04 PROM sites 0xffa702c0 and 0xffa72500 | Set means the compare of an operation 16 run failed. Name is ours. |
| 32:0 | `fail_addr` | inferred |  | SAL 5.04 PROM site 0xffa72500 (extract of 33 bits, times 8) | Failing address in 8-byte units, read only in the failure report. Name is ours. |

### Register `md_mbist_err`

Memory test engine other-error value; the name is ours. Read only in the failure report, and only when bit 36 of md_mbist_status is found clear (the report then prints that the failure was not a compare error); not read on a passing run, so it needs no particular value. Its layout is unknown.

### Register `md_mbist_mask`

Memory test engine mask; the name is ours (inferred from the all-ones write only). Written with all ones each time the engine starts; never read. Must return: plain storage.

### Register `md_bank_cfg0`

Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with the same 64-bit word, built by merging fields into the old value of _0008 (bits it does not deposit keep their old value): a timing index in bits 35:32 and one byte per bank at bit 8k with the density index, rank code and a two-bit field. For a 2 GiB node (one bank, density 3, rank 0) the low byte is 0x03 and banks 1 to 3 read 0x27, 0x47, 0x67 (density 7). This one is never read; accept the store. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:32 | `timing_idx` | inferred |  | SAL 5.04 PROM site 0xffa76ec6 (deposit at bit 32, width 4) | Timing-table row index 0 to 8 chosen from the bus clock and CAS latency (100 MHz with CL 2.0 gives 0; 133 MHz 1 and 2; 160 MHz 3 to 5; 200 MHz 6 to 8). Name is ours. |
| 30:29 | `b3_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 3 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 27 | `b3_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 3: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 26:24 | `b3_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 3: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 22:21 | `b2_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 2 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 19 | `b2_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 2: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 18:16 | `b2_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 2: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 14:13 | `b1_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 1 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 11 | `b1_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 1: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 10:8 | `b1_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 1: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 6:5 | `b0_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 0 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 3 | `b0_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 0: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 2:0 | `b0_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 0: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |

### Register `md_bank_cfg1`

Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with the same 64-bit word, built by merging fields into the old value of _0008 (bits it does not deposit keep their old value): a timing index in bits 35:32 and one byte per bank at bit 8k with the density index, rank code and a two-bit field. For a 2 GiB node (one bank, density 3, rank 0) the low byte is 0x03 and banks 1 to 3 read 0x27, 0x47, 0x67 (density 7). Read first by the set-up, then by the memory test and the credit routine to find each bank's size: it must read back what was written. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:32 | `timing_idx` | inferred |  | SAL 5.04 PROM site 0xffa76ec6 (deposit at bit 32, width 4) | Timing-table row index 0 to 8 chosen from the bus clock and CAS latency (100 MHz with CL 2.0 gives 0; 133 MHz 1 and 2; 160 MHz 3 to 5; 200 MHz 6 to 8). Name is ours. |
| 30:29 | `b3_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 3 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 27 | `b3_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 3: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 26:24 | `b3_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 3: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 22:21 | `b2_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 2 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 19 | `b2_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 2: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 18:16 | `b2_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 2: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 14:13 | `b1_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 1 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 11 | `b1_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 1: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 10:8 | `b1_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 1: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 6:5 | `b0_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 0 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 3 | `b0_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 0: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 2:0 | `b0_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 0: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |

### Register `md_bank_cfg2`

Memory controller register, unnamed; the name is ours. One of three registers (offsets 0x1_0001_0000, _0008 and _0010) the memory set-up writes with the same 64-bit word, built by merging fields into the old value of _0008 (bits it does not deposit keep their old value): a timing index in bits 35:32 and one byte per bank at bit 8k with the density index, rank code and a two-bit field. For a 2 GiB node (one bank, density 3, rank 0) the low byte is 0x03 and banks 1 to 3 read 0x27, 0x47, 0x67 (density 7). The memory test driver reads it to skip banks whose density index is 7, and the size sum reads it too: it must read back what was written. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:32 | `timing_idx` | inferred |  | SAL 5.04 PROM site 0xffa76ec6 (deposit at bit 32, width 4) | Timing-table row index 0 to 8 chosen from the bus clock and CAS latency (100 MHz with CL 2.0 gives 0; 133 MHz 1 and 2; 160 MHz 3 to 5; 200 MHz 6 to 8). Name is ours. |
| 30:29 | `b3_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 3 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 27 | `b3_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 3: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 26:24 | `b3_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 3: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 22:21 | `b2_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 2 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 19 | `b2_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 2: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 18:16 | `b2_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 2: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 14:13 | `b1_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 1 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 11 | `b1_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 1: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 10:8 | `b1_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 1: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |
| 6:5 | `b0_field` | established |  | SAL 5.04 PROM site 0xffa76f56 (bank 0) | Two-bit field of bank 0 taken from the bank record; equals the bank number in the traced run, role unknown. Name is ours. |
| 3 | `b0_rank` | inferred |  | SAL 5.04 PROM site 0xffa76f06 (bank 0) | Rank code of bank 0: 0 for single-rank DIMMs, 1 for dual-rank. Name is ours. |
| 2:0 | `b0_density` | inferred |  | SAL 5.04 PROM site 0xffa76ee6 (bank 0; the other banks follow in the same function) | Density index of bank 0: 0 to 5 for 64 MB to 2 GB per rank, 7 for an empty bank. Bank size is 0x4000000 << (density + rank code) << 2 bytes, so 3 with rank code 0 is 2 GiB. Name is ours. |

### Register `md_timing_0`

Memory controller register, unnamed; the name is ours. Timing word built from a 32-byte row of the timing table at flash site 0xffbe0650 (row = the timing index). One of two registers (offsets _0020 and _0040) that carry the same word; bits 63:40 and 7:0 of the old value of _0040 are merged in (read at site 0xffa76c9c). Never read. Must return: plain storage. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54 | `trcd4` | inferred |  | SAL 5.04 PROM site 0xffa77536 | Also set (bit 52 stays set) when the DIMM-record value at offset 8 is 4, read as a tRCD of 4 clocks (inferred). Name is ours. |
| 53 | `trcd2` | inferred |  | SAL 5.04 PROM site 0xffa76e16 | Also set (bit 52 stays set) when the DIMM-record value at offset 8 is 2, read as a tRCD of 2 clocks (inferred). Name is ours. |
| 52 | `trcd3` | inferred |  | SAL 5.04 PROM site 0xffa76d86 | Always set. Read as the base case for a DIMM-record value of 3, the tRCD in clocks (the reading as tRCD is inferred). Name is ours. |
| 51:48 | `row_c` | established |  | SAL 5.04 PROM site 0xffa76e3c | 16-bit value at row offset 12. Name is ours. |
| 47:44 | `row_b` | established |  | SAL 5.04 PROM site 0xffa76e26 | 16-bit value at row offset 10. Name is ours. |
| 43:40 | `row_a` | established |  | SAL 5.04 PROM site 0xffa76df6 | 16-bit value at row offset 8. Name is ours. |
| 39:8 | `row_lo` | established |  | SAL 5.04 PROM site 0xffa76d46 | Low 32 bits of the first doubleword of the 32-byte timing-table row. Name is ours. |
| 7:1 | `const_lo` | established |  | SAL 5.04 PROM sites 0xffa76d80 and 0xffa76dd6 | Always 0x01 in this field: bit 1 set, bits 7:2 cleared; bit 0 keeps its old value. Name is ours. |

### Register `md_timing_1`

Memory controller register, unnamed; the name is ours. Six 4-bit timing fields from the 16-bit values at offsets 14, 16, 18, 20, 22 and 24 of the timing-table row; the other bits keep the old value read from _0048 (site 0xffa76c6c). One of two registers (_0028 and _0048) that carry the same word. Never read. Must return: plain storage. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:20 | `u5` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 24 of the timing-table row. Name is ours. |
| 19:16 | `u4` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 22 of the timing-table row. Name is ours. |
| 15:12 | `u3` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 20 of the timing-table row. Name is ours. |
| 11:8 | `u2` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 18 of the timing-table row. Name is ours. |
| 7:4 | `u1` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 16 of the timing-table row. Name is ours. |
| 3:0 | `u0` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 14 of the timing-table row. Name is ours. |

### Register `md_refresh_0`

Memory controller register, unnamed; the name is ours. One word is written to both _0030 and _0050, once, after the eight DRAM initialisation runs: it starts as the old value of _0050 with bit 23 cleared and these fields deposited. Never read. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27:24 | `bank_small` | established |  | SAL 5.04 PROM site 0xffa77a8c | Bit k set for each present bank whose density index is 1 or less; none for a 2 GiB node. Meaning unknown. Name is ours. |
| 22:17 | `trfc` | inferred |  | SAL 5.04 PROM site 0xffa776ec | tRFC in clocks: SPD byte 42 divided by 5, at least 14. Name is ours. |
| 16:8 | `interval` | inferred |  | SAL 5.04 PROM site 0xffa7764c (195) and 0xffa7769c (override) | Refresh interval, 195 unless the flash variable MemoryRefresh gives another number. Name is ours. |
| 7:0 | `cs_enable` | inferred |  | SAL 5.04 PROM site 0xffa77a6c (deposit of bit cs into bits 7:0) | One bit per chip select that exists (chip select = 2 * bank + rank); bit 0 only for a 2 GiB single-rank node. Meaning inferred. Name is ours. |

### Register `md_timing_2`

Memory controller register, unnamed; the name is ours. Timing word built from a 32-byte row of the timing table at flash site 0xffbe0650 (row = the timing index). One of two registers (offsets _0020 and _0040) that carry the same word; bits 63:40 and 7:0 of the old value of _0040 are merged in (read at site 0xffa76c9c). Read once before the write, so any value is accepted before the first write. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54 | `trcd4` | inferred |  | SAL 5.04 PROM site 0xffa77536 | Also set (bit 52 stays set) when the DIMM-record value at offset 8 is 4, read as a tRCD of 4 clocks (inferred). Name is ours. |
| 53 | `trcd2` | inferred |  | SAL 5.04 PROM site 0xffa76e16 | Also set (bit 52 stays set) when the DIMM-record value at offset 8 is 2, read as a tRCD of 2 clocks (inferred). Name is ours. |
| 52 | `trcd3` | inferred |  | SAL 5.04 PROM site 0xffa76d86 | Always set. Read as the base case for a DIMM-record value of 3, the tRCD in clocks (the reading as tRCD is inferred). Name is ours. |
| 51:48 | `row_c` | established |  | SAL 5.04 PROM site 0xffa76e3c | 16-bit value at row offset 12. Name is ours. |
| 47:44 | `row_b` | established |  | SAL 5.04 PROM site 0xffa76e26 | 16-bit value at row offset 10. Name is ours. |
| 43:40 | `row_a` | established |  | SAL 5.04 PROM site 0xffa76df6 | 16-bit value at row offset 8. Name is ours. |
| 39:8 | `row_lo` | established |  | SAL 5.04 PROM site 0xffa76d46 | Low 32 bits of the first doubleword of the 32-byte timing-table row. Name is ours. |
| 7:1 | `const_lo` | established |  | SAL 5.04 PROM sites 0xffa76d80 and 0xffa76dd6 | Always 0x01 in this field: bit 1 set, bits 7:2 cleared; bit 0 keeps its old value. Name is ours. |

### Register `md_timing_3`

Memory controller register, unnamed; the name is ours. Six 4-bit timing fields from the 16-bit values at offsets 14, 16, 18, 20, 22 and 24 of the timing-table row; the other bits keep the old value read from _0048 (site 0xffa76c6c). One of two registers (_0028 and _0048) that carry the same word. Read once before the write, so any value is accepted before the first write. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:20 | `u5` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 24 of the timing-table row. Name is ours. |
| 19:16 | `u4` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 22 of the timing-table row. Name is ours. |
| 15:12 | `u3` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 20 of the timing-table row. Name is ours. |
| 11:8 | `u2` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 18 of the timing-table row. Name is ours. |
| 7:4 | `u1` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 16 of the timing-table row. Name is ours. |
| 3:0 | `u0` | established |  | SAL 5.04 PROM sites 0xffa76d66 to 0xffa76e46 (deposits at bits 0 to 20) | 16-bit value at row offset 14 of the timing-table row. Name is ours. |

### Register `md_refresh_1`

Memory controller register, unnamed; the name is ours. One word is written to both _0030 and _0050, once, after the eight DRAM initialisation runs: it starts as the old value of _0050 with bit 23 cleared and these fields deposited. Read once, before the write; keep what was written. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 27:24 | `bank_small` | established |  | SAL 5.04 PROM site 0xffa77a8c | Bit k set for each present bank whose density index is 1 or less; none for a 2 GiB node. Meaning unknown. Name is ours. |
| 22:17 | `trfc` | inferred |  | SAL 5.04 PROM site 0xffa776ec | tRFC in clocks: SPD byte 42 divided by 5, at least 14. Name is ours. |
| 16:8 | `interval` | inferred |  | SAL 5.04 PROM site 0xffa7764c (195) and 0xffa7769c (override) | Refresh interval, 195 unless the flash variable MemoryRefresh gives another number. Name is ours. |
| 7:0 | `cs_enable` | inferred |  | SAL 5.04 PROM site 0xffa77a6c (deposit of bit cs into bits 7:0) | One bit per chip select that exists (chip select = 2 * bank + rank); bit 0 only for a 2 GiB single-rank node. Meaning inferred. Name is ours. |

### Register `md_const_58`

Memory controller register, unnamed; the name is ours. Written once with the constant 0x4004e20; never read. Role unknown. See memory-init.md.

### Register `md_ctl_60`

Memory controller register, unnamed; the name is ours. Written 0x4047 when the SHub ID revision (bits 31:28 of 0x1_1006_0580) is above 2 and 0x4045 otherwise; never read. Role unknown. See memory-init.md.

### Register `md_reg_0001_0068`

Memory controller register, unnamed; the name is ours. The credit routine (site 0xffa7a960) reads it for the first flagged bank, reads md_bank_cfg1, and compares the 32-bit value with its argument, 4 when called from the memory test and 2 from Initializing memory (which always runs). Equal: nothing. Value below the argument: zero-fills the last 1/32 of the bank with engine operation 48, then writes the argument back (sign-extended from 32 bits), then zero-fills with the block transfer engine (IBLS0 written 0x100000 plus twice the difference, polled for bit 20 to clear; a timeout prints a message and returns). Value above: writes the argument back and zero-fills (value minus argument) times 32 8-byte words at the bank base with operation 48. The routine returns at once, touching nothing, when cpuid[2] equals 0xaeeeeeee8badbeef or no bank is flagged present. The register must read back what was written; the role of the value is unknown (a credit-like count, inferred from the comparison). See memory-init.md.

### Register `md_const_78`

Memory controller register, unnamed; the name is ours. Written once with the constant 0x24; never read. Role unknown. See memory-init.md.

### Register `md_mbist_cmd`

Memory test and DRAM initialisation engine, command or address word; the name is ours. Written with the caller's 64-bit word before the status and control writes of every engine start: for operations 48 and 16 the byte address within the node where the pass starts (bank << 34, plus 32 times the pass number for operation 16), for operation 64 the directory address, for the DRAM initialisation commands (operations 7, 2, 1, 0) a command word. Never read in the passing path. Must return: plain storage. See memory-init.md.

### Register `md_mbist_ctl`

Memory test and DRAM initialisation engine control; the name is ours. The PROM starts the engine by writing md_mbist_cmd, then 0 to md_mbist_status and all ones to md_mbist_mask, then this register with go set, an operation code in bits 38:32 and a 31-bit value. It then polls, keeping bits 41:40: it leaves the loop when they are not 01 (go set, fail clear), so 00 is done, 10 is done and failed, 11 is failed with go still set (the PROM then stores the value it read back with bit 40 cleared and polls bit 40 to clear), 01 is busy. The deadline is 20,000,000 microseconds, scaled from the real-time clock by the period in rtc_ctl. An expiry returns -3 (printed as MBIST TIMEOUT). Callers test bit 41 afterwards. Bits 38:0 are never read. A model where go clears at once and fail never sets satisfies the code. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41 | `fail` | established |  | SAL 5.04 PROM site 0xffa6fd40 (mask 0x30000000000) and 0xffa6b1e6 (bit test) | Set when the operation failed; the PROM stops polling when it sets and the caller reports an error. Never set in the passing path. Name is ours. |
| 40 | `go` | established |  | SAL 5.04 PROM site 0xffa6fc16 (constant 0x10000000000) and the poll site 0xffa6fd40 | Written 1 to start; reads 1 while the engine runs. The PROM waits for it to clear. Name is ours. |
| 38:32 | `op` | established |  | SAL 5.04 PROM site 0xffa6fc26 (seven-bit deposit at bit 32) | Operation code: 48 and 16 for the memory test (inferred as write the pattern and read and compare), 64 for the directory write, 80 for a directory read (not reached on a single node), 7, 2, 0, 0, 2, 1, 1, 0 for the DRAM initialisation sequence of one chip select (meaning inferred). Name is ours. |
| 30:0 | `value` | established |  | SAL 5.04 PROM site 0xffa6fbe6 (mask 0x7fffffff) | Operand written with the operation: the count of 8-byte words for operations 48, 16 and 64 (bank size divided by 8, 0x1000_0000 for a 2 GiB bank), 0 for the DRAM initialisation commands. Name is ours. |

### Register `md_reg_0003_0000`

MD block register, unnamed; the name is ours. Initializing memory (site 0xffa782c0, which always runs) reads it, sets bit 3 and writes the result to this register and to md_reg_0005_0000. A routine reached only through a function-descriptor table (site 0xffa733d0) writes a size class from 0 to 4 into bits 2:0 of both; another (site 0xffa78f70) reads bits 2:0 plus one as a shift. Whether the table path runs on a single node was not traced. Must return the stored value. Roles of bits 2:0 and 3 are inferred only (size class, memory initialised).

### Register `md_reg_0003_0200`

MD block registers, unnamed; the name is ours. Eight words at stride 0x10 that the memory set-up fills with all ones, once each, through the global window. Never read. Role unknown. See memory-init.md.

Array of 8 registers, stride 16.

### Register `md_dqlp_dir_privilege_vector`

Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege vector for acc=0'). Defined by the header; no use in any kernel file read. Layout and role unknown.

### Register `md_reg_0003_0400`

Memory and directory block register, unnamed; the name is ours. The memory controller set-up writes 0x1000 (bit 12) to it through the global window, between the control register md_ctl_60 and md_const_58. It is 0x100 above SH1_MD_DQLP_MMR_DIR_PRIVEC0 (md_dqlp_dir_privilege_vector); that it is the next privilege vector is not shown. Never read. A write-accepting register satisfies the PROM; the role is unknown.

### Register `md_dir_access_lp`

Directory memory initial-value write, left queue port block (the block is the one the Linux header calls SH1_MD_DQLP_MMR_DIR_PRIVEC0 at the 0x300 offset; the left reading is inferred from that name); the name is ours. The PROM stores the value shifted left 55 here and to md_dir_access_rp, then runs the engine with operation code 64. No separate initialise register for directory ECC was seen. The routine fails on a -3 timeout or bit 41 of md_mbist_ctl and does not test bit 36 of md_mbist_status. Never read; plain storage satisfies the PROM. Callers pass the value 7 for the first 64 KiB of node 0 and 6 for the 6 MiB PROM image copy (argument positions inferred). See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:55 | `value` | inferred |  | SAL 5.04 PROM site 0xffa6b076 (shift left 55) | The caller's value shifted left 55. The width of the field is inferred from the shift; name is ours. |

### Register `md_bist_data_a0`

Memory test data pattern word (first A word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.

Array of 4 registers, stride 65536.

### Register `md_bist_data_b0`

Memory test data pattern word (first B word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.

Array of 4 registers, stride 65536.

### Register `md_bist_data_a1`

Memory test data pattern word (second A word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.

Array of 4 registers, stride 65536.

### Register `md_bist_data_b1`

Memory test data pattern word (second B word of each block), one in each of the blocks 0x3, 0x4, 0x5 and 0x6 (stride 0x1_0000); the name is ours. Programmed before every engine operation 48 or 16: the A words get the 40-bit pattern with bit 42 set, the B words the pattern or its 40-bit complement. Never read. Must return: plain storage. See memory-init.md.

Array of 4 registers, stride 65536.

### Register `md_reg_0005_0000`

As md_reg_0003_0000 for the right queue port block; the PROM only writes it, with the value it read from md_reg_0003_0000 with bit 3 set. The name is ours.

### Register `md_reg_0005_0200`

As md_reg_0003_0200 for the right queue port block. The name is ours.

Array of 8 registers, stride 16.

### Register `md_dqrp_dir_privilege_vector`

Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names.

### Register `md_reg_0005_0400`

Same as md_reg_0003_0400 for the right queue port block, 0x100 above SH1_MD_DQRP_MMR_DIR_PRIVEC0 (md_dqrp_dir_privilege_vector). The same routine writes 0x1000 to it straight after md_reg_0003_0400. The name is ours; the role is unknown.

### Register `md_dir_access_rp`

As md_dir_access_lp for the right queue port block (SH1_MD_DQRP_MMR_DIR_PRIVEC0's block); the name is ours.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:55 | `value` | inferred |  | SAL 5.04 PROM site 0xffa6b076 | As md_dir_access_lp. Name is ours. |

### Register `ii_int`

I/O interface interrupt 0 and 1 (SH_II_INT0, SH_II_INT1): the register a PIC's interrupt write lands on, through the Crosstalk address nasid << 36 | 1 << 47 | offset. Bits 7:0 are the processor vector, bit 8 sends it to the processor interface (header: a pulse). The data a PIC writes is inferred to be 0x100 | vector. Not accessed by the PROM.

Array of 2 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `send` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Send the interrupt message to the processor interface. |
| 7:0 | `idx` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Targeted processor interrupt vector. |

### Register `ii_int_config`

Destination of the I/O interface interrupt n (SH_II_INTn_CONFIG): delivery type, target processor id and optional vector base, the ipi_int layout without send or vector. The PROM writes the processor id of slice 0 to n = 0 and of slice 2 to n = 1 and never reads them.

Array of 2 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49:21 | `base` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 19:4 | `pid` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 3 | `agent` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Agent, must be 0 for SHub. |
| 2:0 | `type` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Interrupt type: 0 interrupt, 2 PMI, 4 NMI, 5 INIT. |

### Register `ii_int_enable`

Bit 0 enables the I/O interface interrupt n. The PROM writes 1 to both and never reads them.

Array of 2 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `int_node_id_config`

Selects the node whose processors take this node's interrupts when it has none of its own (the PROM's table names it SH_INT_NODE_ID_CONFIG). Role inferred.

### Register `ipi_int`

Send an interprocessor interrupt (processor interface or local block, inferred). The sender writes this register in the target node's global MMR window with send set, the target's physical processor id, a delivery type, a vector and a fixed base. The kernel stores through uncached physical mode with release ordering, after a memory barrier. On a SHub 1 revision 2 or lower it holds a global lock around the store and waits for the PIO write status to drain.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `send` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Sending the message; the header says it generates a pulse. |
| 59:52 | `idx` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Interrupt vector delivered to the target processor. |
| 49:21 | `base` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Optional interrupt vector area, 2 MiB aligned. The kernel always puts 0xfee here. |
| 19:4 | `pid` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Processor id, the same value the target processor's SAPIC id holds. |
| 3 | `agent` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Must be zero for SHub. |
| 2:0 | `type` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Interrupt type: 0 interrupt, 2 platform management interrupt, 4 NMI, 5 INIT. |

### Register `ipi_int_enable`

Enable for ipi_int delivery (the PROM's table names it SH_IPI_INT_ENABLE). The PROM writes 1 before it sends wake-up messages and never reads it. That delivery depends on it is inferred.

### Register `local_int_config`

Destination of local interrupt n (0 to 5): the ipi_int message layout without the send bit. The PROM writes type 2 (PMI) vector 1 to interrupts 0 and 1 (slice pairs 0/1 and 2/3), type 5 (INIT) to interrupts 2 and 3 (slices 0 and 2) and vector 0xe9 (Linux SGI_UART_VECTOR) to interrupt 5. Never read. The pairing of these offsets with the PROM's SH_LOCAL_INTn_CONFIG names is by table order (inferred).

Array of 6 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:52 | `idx` | established |  | SAL 5.04 PROM sites 0xffa23a20 (interrupts 0 and 1, PMI vector 1), 0xffa31290 (interrupts 2 and 3, INIT), 0xffb73b86 (interrupt 5, vector 0xe9) |  |
| 49:21 | `base` | established |  | SAL 5.04 PROM sites 0xffa23a20 (interrupts 0 and 1, PMI vector 1), 0xffa31290 (interrupts 2 and 3, INIT), 0xffb73b86 (interrupt 5, vector 0xe9) |  |
| 19:4 | `pid` | established |  | SAL 5.04 PROM sites 0xffa23a20 (interrupts 0 and 1, PMI vector 1), 0xffa31290 (interrupts 2 and 3, INIT), 0xffb73b86 (interrupt 5, vector 0xe9) |  |
| 3 | `agent` | established |  | SAL 5.04 PROM sites 0xffa23a20 (interrupts 0 and 1, PMI vector 1), 0xffa31290 (interrupts 2 and 3, INIT), 0xffb73b86 (interrupt 5, vector 0xe9) |  |
| 2:0 | `type` | established |  | SAL 5.04 PROM sites 0xffa23a20 (interrupts 0 and 1, PMI vector 1), 0xffa31290 (interrupts 2 and 3, INIT), 0xffb73b86 (interrupt 5, vector 0xe9) |  |

### Register `local_int_enable`

Mask of event sources that raise local interrupt n. The PROM writes 0x7ef (the bits it treats as error events), 0x4000 and 0x2000. How a mask bit maps to an event_occurred bit is unknown. Never read.

Array of 6 registers, stride 256.

### Register `rtc0_int_config`

Destination of comparator RTC0's interrupt, which the SAL keeps for a delayed bus-error assertion (Linux mmtimer: RTC0 is used by SAL). Layout as rtc_int_config. Never read.

### Register `rtc0_int_enable`

Enable for comparator RTC0; written after the compare value, cleared first on undo. Never read.

### Register `rtc_int_config`

Where the comparator interrupt of RTC 1, 2 and 3 is sent: type, target processor id, vector area and vector. The mmtimer driver writes the vector and processor id fields and leaves type, agent and base zero. The register has the same layout as the IPI message, without the send bit. A fourth comparator (RTC 0) exists; the driver comment says firmware uses it, and the header defines nothing for it.

Array of 3 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:52 | `idx` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 49:21 | `base` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 19:4 | `pid` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 3 | `agent` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |
| 2:0 | `type` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `rtc_int_enable`

Enable for the comparator interrupt of RTC 1, 2 and 3. The mmtimer driver disables it, sets the comparator to all ones, clears the pending bit, writes the configuration, enables, and only then writes the real expiry, in that order.

Array of 3 registers, stride 256.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `enable` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `event_occurred`

Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them; Linux only reads it. Bits the header names are established. SAL 5.04 reads it for the error bits (mask 0x7ef, sites 0xffa239a0 and 0xffa23fd6) and for bit 21 (site 0xffa31506), and writes bits 5 and 8 to this register itself (sites 0xffa32816 and 0xffa32996); a model should OR written bits in (inferred). Zero from reset is tolerated; the reset value is unknown. Bit 21 must read 0 for the PROM's INIT handling. See interrupts.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `ii_int1` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 1. |
| 29 | `ii_int0` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 0. |
| 28 | `ipi_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending IPI interrupt. |
| 26 | `rtc3_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 3 interrupt. |
| 25 | `rtc2_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 2 interrupt. |
| 24 | `rtc1_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 1 interrupt. |
| 23 | `rtc0_int` | inferred |  | SAL 5.04 PROM site 0xffa31d96 (alias write 0x800000 right after RTC0's enable is cleared) | Pending RTC comparator 0 interrupt, from the sequence and from Linux numbering comparators 1 to 3 as bits 24 to 26. Name is ours. |
| 21 | `bit21` | inferred |  | SAL 5.04 PROM site 0xffa31506 (read), 0xffa31566 (clear through the alias, 0x200000) | Read by the PROM's INIT handling before it forwards INIT to the other processors, cleared through the alias. Meaning unknown; name is ours. |
| 20 | `uart_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending junk-bus UART interrupt. |
| 8 | `bit8` | inferred |  | SAL 5.04 PROM site 0xffa32816 (write to the register), 0xffa23a20 (mask 0x7ef) | As bit 5. Name is ours. |
| 5 | `bit5` | inferred |  | SAL 5.04 PROM site 0xffa32996 (write to the register), 0xffa23a20 (mask 0x7ef) | In the PROM's error mask 0x7ef; the PROM also writes this bit to the register itself in its express-path workaround. Name is ours. |
| 3 | `bit3` | inferred |  | SAL 5.04 PROM site 0xffa0bb16 and 0xffa0bb46 | The PROM writes 8 to the alias (and to the overflow alias) of another node when it clears a processor-interface error before a remote access. Role inferred; name is ours. |

### Register `event_occurred_alias`

Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.

### Register `event_overflow`

Second event word next to event_occurred; only its alias is written by the PROM.

### Register `event_overflow_alias`

Clear alias of event_overflow. The PROM writes 8 together with the same write to event_occurred_alias. Accepting the write is enough.

### Register `lb_reg_1002_0000`

Local block register, unnamed; the name is ours (address). SAL_A writes 0x15031010 to it on each of its two entries (reason 3 and reason 0). The image holds no other reference to the address, so it is never read back. The meaning of the value is unknown; a plain write-accepting register satisfies the PROM.

### Register `lb_slice_rec`

Per-slice local block record, 128 bytes apart (index = slice & 3); the name is ours. SAL_B reads the running processor's entry in the lock routine and writes its low byte as a progress code, so any value is accepted; SAL_A reads it into r31 for reasons 1 and 2 and for a reason above 3, not for reason 0 (or 3). The meaning of the value is unknown.

Array of 4 registers, stride 128.

### Register `lb_liq_ctl`

Local block LIQ control: request control in bits 4:0, reply control in bits 11:8 and three force-credit bits. The node set-up method (slot 34 of the chip-object table, site 0xffa95c20) reads it once, ORs bit 18 and writes the same value back 63 times in a row; nothing tests the value read. If each write adds one credit to the LINVV credit counter (6 bits wide in lb_credit_status in the header), 63 writes fill it; that role is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 18 | `force_linvv_credit` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_LB_LIQ_CTL_FORCE_LINVV_CREDIT; SAL 5.04 PROM site 0xffa95cd6 (the constant 0x40000) | Force LINVV credit. The PROM sets it and writes the word 63 times. |
| 17 | `force_rp_credit` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_LB_LIQ_CTL_FORCE_RP_CREDIT | Force reply credit. |
| 16 | `force_rq_credit` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_LB_LIQ_CTL_FORCE_RQ_CREDIT | Force request credit. |
| 11:8 | `liq_rpl_ctl` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_LB_LIQ_CTL_LIQ_RPL_CTL | LIQ reply control. |
| 4:0 | `liq_req_ctl` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_LB_LIQ_CTL_LIQ_REQ_CTL | LIQ request control. |

### Register `lb_max_rep_credit_cnt`

Maximum number of reply credits from the crossbar. The node set-up method (site 0xffa95c20) reads it, deposits 12 into bits 4:0 and writes it back, once, after the CRB set-up.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `max_cnt` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_LB_MAX_REP_CREDIT_CNT_MAX_CNT; SAL 5.04 PROM site 0xffa95f66 (deposit of 12) | Maximum reply credits. |

### Register `lb_max_req_credit_cnt`

Maximum number of request credits from the crossbar. The node set-up method (site 0xffa95c20) reads it, deposits 12 into bits 4:0 and writes it back, once.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4:0 | `max_cnt` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_LB_MAX_REQ_CREDIT_CNT_MAX_CNT; SAL 5.04 PROM site 0xffa95fa6 (deposit of 12) | Maximum request credits. |

### Register `conveyor_belt_time_out`

Local block conveyor belt time-out. The node set-up method (site 0xffa95c20) reads it last and writes it back with 0x3e8 (1000) in bits 11:0, the field the header gives.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11:0 | `value` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_CONVEYOR_BELT_TIME_OUT_VALUE; SAL 5.04 PROM site 0xffa96156 (deposit of 1000) | Conveyor belt time-out value. |

### Register `rtc_ctl`

Real-time clock control; the name is ours. The PROM writes 0x100000000, then writes 0 to rtc, then writes 0x100000041, all at the SAL_B reset entry, before any read. The tick period in nanoseconds is 10 times (the period field + 1); with the PROM's write the field is 4, 50 ns, 20 MHz, which is also what SAL_FREQ_BASE for the real-time clock returns (1,000,000,000 divided by the period). The reset value never reaches the PROM. The PROM's own name table and the 2.4 header call this offset SH_GC_SRC_CTRL ('SHub Global Clock Control', mask 0x313ff3ff1, INIT 0x100000000: enable counter bit 0, max count bits 13:4, counter 25:16, toggle bit 28, source select 33:32); the 0x100000041 write is enable plus max count 4. Roles of the other bits are inferred only. If a read returned 0 the PROM would assume a 10 ns period (100 MHz); every PROM deadline is in microseconds scaled by this period, so the counter must tick at the rate the field gives.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:32 | `mode` | inferred |  | SAL 5.04 PROM site 0xffa96626 (read), 0xffa967e6 (set to 1) and 0xffa94d26 (written 1) | Read by an interconnect-phase routine that branches on 1, 2 and 3, and set to 1 by another. Written 1 by the reset entry. Meaning inferred only; name is ours. |
| 13:4 | `period` | inferred |  | SAL 5.04 PROM site 0xffa0da00 and the SAL runtime's chipset_rtc_period | Tick period field: the PROM and the SAL runtime both compute the period in nanoseconds as 10 times (value + 1), a software expectation read in two places; that the counter really ticks at that rate is inferred. Written 4 by the PROM. Name is ours. |
| 0 | `run` | inferred |  | SAL 5.04 PROM site 0xffa94d06 (clear), 0xffa94d26 (set), 0xffa967e6 (clear) | Clear when the PROM writes the counter to 0, set after; cleared again by an interconnect-phase routine. A run control is inferred from that order only; name is ours. |

### Register `ipi_access`

Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross-partition driver reading it as the target of a protected remote read; the driver comment says there is no special reason for that choice. So the register can be read without harm; its bit layout and write behaviour are unknown. The SHub 1 PROM writes 1 here once, as the winner of the node election in SAL_A (SAL 5.04 PROM site 0xffc4ea40); the meaning of 1 is unknown.

### Register `md_clk_sel`

DRAM bus clock select; the name is ours. The memory-controller set-up reads it and uses bits 1:0 as an index into a four-entry table held in flash (200, 160, 133 and 100 MHz for 0 to 3, table read). The chosen clock and the DIMM's CAS latency must be a pair the PROM supports or it prints that the memory bus speed is not supported and goes on with unusable timing values. Never written by the PROM. Must return: any value whose bits 1:0 give a supported pair; zero (200 MHz) is the simplest. In the local block by address. Linux does not define it: the position and use are as observed in the PROM, the meaning (bus clock select) is inferred. See memory-init.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1:0 | `sel` | inferred |  | SAL 5.04 PROM site 0xffa77e20 | Clock table index: 0 for 200 MHz, 1 for 160, 2 for 133, 3 for 100. Name is ours. |

### Register `shub_id`

SHub identification (local block, inferred). The kernel reads only the revision, to switch on its SHub 1.1 workarounds when it is 2 or lower, and in the fallback for an old PROM the nodes-per-bit field, which it reports as the region size. SHub 2's counterpart is not named in the header. The SHub 1 PROM also writes it (SAL 5.04 PROM site 0xffa95a30, reached from 0xffa5f84c): it reads the word, replaces bits 42:32 with the node id, bits 45:44 with a size code and bits 52:48 with a nodes-per-bit code, and writes the word back; the other bits are stored as read, so they may be read only. After the write the three fields must read back as written. The first read, at main start, needs any node id in bits 42:32; the reset value is unknown. See prom-reset.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 52:48 | `nodes_per_bit` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Nodes per bit (the kernel's name for the region size). The positions come from macros in the SAL header; the role is the kernel's use of the value as the region size in its old-PROM fallback. |
| 45:44 | `size_code` | inferred |  | SAL 5.04 PROM site 0xffa95a30 | Written with 0, 1, 2 or 3 by thresholds 31, 63 and 127 on an argument (bits 10:9 masked, then halved). The meaning is inferred only; the PROM reads it in memory-presence code. Name is ours. |
| 42:32 | `nasid` | inferred |  | SAL 5.04 PROM site 0xffa0dcf0 (read) and 0xffa95a30 (write) | Node id. Every read in the PROM forms global-window addresses from it, so the node's own global window at this id must decode to the node. The PROM replaces it once, later in boot; it must read back as written. Name is ours. Linux does not define this field (it takes the node id from firmware): the position and the PROM's replacement are what the code does, the meaning is inferred. |
| 31:28 | `revision` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Chip revision. The kernel treats 2 or lower as SHub 1.1. |

### Register `ptc`

Purge translation cache message, SHub 1 (header SH1_PTC_0 and SH1_PTC_1). To purge a virtual address range on every processor of a node the kernel writes the two registers of that node's global window back to back with interrupts and interruption collection off, the first with a type bit, the page-size exponent, the region id and a start bit, the second with the virtual address and a start bit; both stores are in one atomic assembly sequence. It does this once per page of the range, after taking a global lock, for every node that has the mm's processors, except the local node which uses the processor's own global purge instruction instead. Entry 0 is the control word and entry 1 the address word. After a batch of nodes it waits on the PIO write status.

Array of 2 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `start` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Start. Set in the first write; entry 1 has its own start bit at the same position. |
| 62:8 | `rid` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Region identifier and region number: the kernel passes the mm's context shifted left by three, ORed with the region number of the address. The upper bound is inferred from bit 63 being the start bit. |
| 7:2 | `ps` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Page size as a power of two. The field is six bits wide only by inference: the kernel passes a value below 64 and the next field starts at bit 8. |
| 0 | `type_bit` | inferred |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Header title: type. The kernel always writes 1; no other value is known. |

### Register `ptc_parms`

Purge translation cache parameters, next to SH1_PTC_0 and SH1_PTC_1. The PROM writes a value built from a value it read and the constant 0x23c34600 (used when bit 31 of a call result is set) and reads it back; the packing and meaning (a timeout) are not decoded. Neither the PROM nor the runtime stores to ptc itself.

### Register `int_cmpa`

Compare value of RTC0 (55 bits). Never read. Whether a value already below the counter fires is unknown.

### Register `int_cmp`

Compare values for RTC comparators 1, 2 and 3 (header names SH_INT_CMPB, SH_INT_CMPC, SH_INT_CMPD; the header titles them 'RTC compare value for processor B, C, D'). The interrupt fires when the clock reaches the value. The comparator for RTC 0 would sit 0x80 below these and is not defined in the header (unknown).

Array of 3 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `compare` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `rtc`

Real-time clock: a 55-bit counter, read by the kernel as its clock source (clock source rating 450, mask 55 bits) and for microsecond delays, because the CPU cycle counters are not synchronised across processors. The frequency is not in a register; the kernel asks firmware for it. The driver comment says the clock registers sit alone on a 64 KiB page, which is what lets user space map it read-only. The SHub 1 PROM (SAL 5.04) writes 0 to it at the SAL_B reset entry (0xffa94d20) and again to a node's counter in the interconnect phase, then reads it on every delay and timeout, so it must advance. Its tick period comes from rtc_ctl (SHub 1: 10 ns times the field plus one, 50 ns after the PROM's own write). See prom-reset.md.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 54:0 | `counter` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |  |

### Register `lb_elect`

Node election word; the name is ours. SAL_A stores slice + 1 to lb_elect_set and reads this register: the 64-bit value must equal exactly what was written, twice (site 0xffc4e9b0 and 0xffc4e766). Equal means this processor is the node's winner. Later code ORs bits 39 to 41 into it (set bit 41 when no other processor position is flagged; bit 40 set across nodes; bit 39 on a remote node) as firmware state. The relation to lb_elect_set is unknown: a write to the offset 8 above may alias, latch (first writer wins) or store into this word; the code reads the same register for all three.

### Register `lb_elect_set`

Election write register; the name is ours. SAL_A stores slice + 1 here and reads lb_elect. Whether it aliases lb_elect, latches the first writer or something else is unknown. A model that returns the written value at lb_elect satisfies every access read.

### Register `lb_l1_state`

L1 link state word in the local block; the name is ours. SAL_A's election winner sets bits 41:39 to 7 by read-modify-write, keeping the other bits. An earlier reading says the L1 start checks bits 41:39 for 7; a later review found no reader that does, so that requirement is unconfirmed and plain storage satisfies the write. Other bits are used by the L1 transport and are not decoded here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41:39 | `link` | inferred |  | SAL 5.04 PROM site 0xffc4e7a0 (write 7) ; the L1 start check named in boot-sequence.md is unconfirmed | Written 7 by SAL_A's election winner; no reader that requires 7 was found (an earlier reading said the L1 start checks it). Meaning inferred; name is ours. |

### Register `lb_lock2`

Second firmware lock pair, release side; the name is ours. The methods of the chip object take it around read-modify-writes of fw_word_1540 by the same routines that take lb_lock (site 0xffa0ed30 on this node, 0xffa0ee90 on another): poll lb_lock2_status, do the work, write 0 here. On this node a status that does not read 0 within 1,000,000 microseconds makes the PROM write 0 here and keep polling; the other-node form gives up after its deadline and returns -9 without writing. Whether a read of the status takes the lock in hardware is unknown; a plain register pair where the status always reads 0 satisfies every access read. Linux v5.3 does not define the lock; the behaviour is as observed at the access and the meaning is inferred.

### Register `lb_lock2_status`

Second firmware lock status; the name is ours. This-node polls proceed when the whole 64-bit value reads 0 (the same routine as lb_lock_status). The other-node routine, reading it through the node-object read, proceeds when bit 0 reads 0 and ignores the other bits, so a model must keep bit 0 at 0 when the lock is free. A status that never reads 0 times out after 1,000,000 microseconds (forced release on this node, error -9 on another). A read side effect is unknown. Linux v5.3 does not define the lock; the meaning is inferred.

### Register `lb_lock`

Firmware lock pair, release side; the name is ours. The PROM takes the lock by polling lb_lock_status until it reads 0, does a read-modify-write of cpu_bits, then writes 0 here. If the status does not read 0 within 1,000,000 microseconds it writes 0 here and polls again. Whether a read of lb_lock_status takes the lock in hardware is unknown; a plain register pair where the status always reads 0 satisfies every access read. The same lock guards the field setter of fw_debug_word (site 0xffa974d0). Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.

### Register `lb_lock_status`

Firmware lock status; the name is ours. The PROM polls it with a short delay until it reads 0; any non-zero value keeps it waiting until the 1,000,000 microsecond deadline, then it writes 0 to lb_lock and keeps polling, so a status that never reads 0 hangs the PROM. A read side effect is unknown. Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.

### Register `crb_message_control`

SHub 1 coherent request buffer message control: coherence and speculation enables, mismatch checks and the invalidate-acknowledge (IVACK) throttle. A SAL_B routine sets bit 24 of pi_reg_2001_0100, reads this register, ORs in 0x3b03f7 when the SHub ID revision (bits 31:28 of shub_id) is above 2 and 0x3f1 otherwise, writes it, then writes the saved value back with bit 24 cleared; 0x3f1 sets bits 0 and 9:4, and the 0x3b0000 half of the other value sets bits 21, 20, 19, 17 and 16, which the 2.4 header lists as reserved (the PROM table names fields the header lacks: SYSTEM_FLUSH_DURATION, SYSTEM_FLUSH_INTERVAL, ENABLE_PIPE_SNOOP_ERRORS; their positions are not decoded). SAL_A's error path stores 0x1_0001_0000_0000 here with a plain 64-bit store, and the SAL_B park path passes the same address and value to a write helper (not read): the value clears bits 11:0 (system coherence included) and sets IVACK stall count 1 and throttle control 1. Nothing in the header makes a bit of this register reset the node (inferred).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:48 | `ivack_throttle_control` | established |  | SGI Linux 2.4 ia64 SN2 header | IVACK throttling limit and timer control. |
| 47:32 | `ivack_stall_count` | established |  | SGI Linux 2.4 ia64 SN2 header | IVACK stall counter. |
| 11 | `enable_ivack_consolidation` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable IVACK reply consolidation. |
| 10 | `suppress_bogus_writes` | established |  | SGI Linux 2.4 ia64 SN2 header | Ignore residual write data. |
| 9 | `wrb_attribute_mismatch_xb_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable the crossbar write request buffer mismatch check. |
| 8 | `rrb_attribute_mismatch_xb_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable the crossbar read request buffer mismatch check. |
| 7 | `irb_attribute_mismatch_fsb_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable the front-side-bus interrupt request buffer mismatch check. |
| 6 | `wrb_attribute_mismatch_fsb_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable the front-side-bus write request buffer mismatch check. |
| 5 | `rrb_attribute_mismatch_fsb_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable the front-side-bus read request buffer attribute mismatch check. |
| 4 | `message_color_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable colour message processing. |
| 3 | `message_color` | established |  | SGI Linux 2.4 ia64 SN2 header | Colour of the message. |
| 2 | `remote_speculative_message_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Speculative read requests to remote memory enabled. |
| 1 | `local_speculative_message_enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Speculative read requests to local memory enabled. |
| 0 | `system_coherence_enable` | established |  | SGI Linux 2.4 ia64 SN2 header, SH_CRB_MESSAGE_CONTROL_SYSTEM_COHERENCE_ENABLE | System coherence enabled. |

### Register `crb_nack_limit`

Coherent request buffer NACK limit: a 12-bit count limit, a 4-bit frequency for the priority count and an enable in bit 63. The node set-up method (slot 34 of the chip-object table, site 0xffa95c20) reads it (site 0xffa95fcc) and writes it back (0xffa9601c) with bit 63 cleared and bits 15:0 set to 0xffff: a 0xfff limit and a 0xf frequency, enable off.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `enable` | established |  | SGI Linux 2.4 ia64 SN2 header | Enable NACK limit detection. |
| 15:12 | `pri_freq` | established |  | SGI Linux 2.4 ia64 SN2 header | Frequency at which the priority count is incremented. |
| 11:0 | `limit` | established |  | SGI Linux 2.4 ia64 SN2 header | NACK count limit. |

### Register `crb_timeout_prescale`

Coherent request buffer timeout prescale: one 32-bit scaling factor in bits 31:0. The node set-up method (site 0xffa95c20) reads it (site 0xffa9608c) and rewrites bits 31:0 (store site 0xffa960cc, a mix4.l keeping bits 63:32): 0x23c34600 (600,000,000) unless the environment attribute NoTimeouts is found, in which case 0. The attribute lookup call is site 0xffa9605c.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:0 | `scaling_factor` | established |  | SGI Linux 2.4 ia64 SN2 header | CRB timeout prescale factor. |

### Register `crb_timeout_skid`

Coherent request buffer timeout skid limit: a 6-bit skid in bits 5:0 and a reset-skid-counter bit in bit 63. A routine reached through a table that also writes pi_cam_control reads this register and writes it back with bit 63 set. The node set-up method (site 0xffa95c20) (read 0xffa95d4c, write 0xffa95dcc) also clears bits 63 and 62, sets bits 11:8 and deposits 2 into bits 5:0; the 2.4 header's mask 0x800000000000003f has no bits 11:8 or 62, so those writes are outside the header's layout.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `reset_skid_count` | established |  | SGI Linux 2.4 ia64 SN2 header | Reset the skid counter. |
| 5:0 | `skid` | established |  | SGI Linux 2.4 ia64 SN2 header | CRB timeout skid. |

### Register `pi_reg_2001_0100`

Processor interface register, unnamed (the block is inferred from the neighbouring SH1_PI_CAM_CONTROL and SH1_PIO_WRITE_STATUS_0); the name is ours. SAL_A reads it and writes it back with bit 24 set, using the read value for nothing else. The PROM later brackets writes to the register site 0x120000000 with bit 24 set then cleared, which suggests a write enable (inferred). Any reset value is tolerated; bit 24 must be settable and read back as written.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 24 | `bit24` | inferred |  | SAL 5.04 PROM site 0xffc4e816 and 0xffa97796 | Set by SAL_A; set before and cleared after the PROM's writes to 0x120000000 in a SAL_B routine. Role inferred from that bracket; name is ours. |
| 17 | `bit17` | inferred |  | SAL 5.04 PROM site 0xffaeb276 (set) and 0xffaeb2e0 (tested on another node) | Set by a local SAL_B routine and tested across nodes, so it carries a per-node flag; role not decoded. Name is ours. |
| 3 | `bit3` | inferred |  | SAL 5.04 PROM site 0xffa318b6 (set), 0xffa31d56 (clear), 0xffa31ab6 (read) | Set, cleared and tested by SAL_B routines (read-modify-write); role not decoded. Name is ours. |

### Register `pi_slice_present`

Per-slice flags in the processor interface; the name is ours. The local-master arbitration reads it for slices 0 and 1 other than the running one and tests bit slice; a set bit makes the PROM count that processor present and wait for it (up to 5,000,000 microseconds). On a one-processor node the bit for every other slice must read 0. The meaning (processor present) is inferred from that use. Later CPU-enumeration callers of the same word read bits 0 and 1 (first processor of slices 0 and 1) and bits 4 and 5 (second processor); the own-slice bit they expect was not traced, so a model should set it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5:4 | `present2` | inferred |  | SAL 5.04 PROM site 0xffa115ac (read through the global window of the node), 0xffa99e2c (caller) | Second processor of slice 0 and 1, read by the CPU enumeration callers; inferred, not re-read here. Name is ours. |
| 1:0 | `present` | inferred |  | SAL 5.04 PROM site 0xffa115ac | Bit n set means the first processor of slice n is present (inferred from use); the local-master arbitration tests only slices 0 and 1. Name is ours. |

### Register `pi_cam_control`

Control of CRB CAM access (header title; processor interface, inferred). The only use is a SHub 1.1 workaround: on a chip of revision 2 or lower the kernel writes 0x8000000000000010 here on every timer tick, through the address of its own node. What the value does is unknown. The SHub 1 PROM (SAL 5.04) also writes it, from two routines reached through tables (site 0xffa24510 and 0xffa245f0, order not located): the low 7 bits of an argument with bit 63 set, plus bit 8 (and bit 9 when bit 5 of the argument is set) in the first, and with bits 9:8 clear in the second; the second then reads pi_reg_2006_0100, pi_reg_2006_0180 and pi_reg_2006_0200. Meaning of the fields is unknown.

### Register `pi_reg_2006_0100`

Processor interface register, unnamed; the name is ours. Read once, with pi_reg_2006_0180 and pi_reg_2006_0200, right after the second pi_cam_control write; the value is stored for a later report. Any value is tolerated (inferred; the consumer was not traced).

### Register `pi_reg_2006_0180`

Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100.

### Register `pi_reg_2006_0200`

Processor interface register, unnamed; the name is ours. See pi_reg_2006_0100.

### Register `pio_write_status`

PIO write status, one per processor slice (header: PIO write status for CPU 0 and 1; processor interface, inferred). The kernel's memory-mapped-I/O write barrier spins until the pending write count shows idle. The kernel stores the address of the instance for its slice (the slice is the processor's position within the node) in its per-processor data.

Array of 2 registers, stride 128.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 61:56 | `pending_write_count` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Count of PIO writes still in flight. On SHub 1 the kernel treats all ones as idle (see PIO_WRITE_STATUS_IDLE); the header gives no reason. |
| 1 | `write_deadlock` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | A deadlock response was detected for a PIO write. |

### Register `pio_write_status_alias`

Alias of the PIO write status. The header names only the instance for slice 0. The deadlock recovery assembly adds 8 to whichever status address it was given, so the alias for slice 1 is inferred. Writing 7 clears the deadlock, write error and multiple write error bits (assembly comment); the header names only bit 1 (deadlock), so which of bits 0 and 2 is which is unknown. The kernel does this on SHub 1 and reads the alias instead on SHub 2.

Array of 2 registers, stride 128.

### Register `xn_iilb_lb_cmp_exp_data1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_lb_cmp_enable0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_lb_cmp_enable1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ii_cmp_exp_data0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ii_cmp_exp_data1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ii_cmp_enable0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ii_cmp_enable1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_md_cmp_exp_data0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_md_cmp_exp_data1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_md_cmp_enable0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_md_cmp_enable1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_pi_cmp_exp_data0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_pi_cmp_exp_data1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_pi_cmp_enable0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_pi_cmp_enable1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ni0_cmp_exp_data0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ni0_cmp_exp_data1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ni0_cmp_enable0`

A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ni0_cmp_enable1`

A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ni1_cmp_exp_data0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ni1_cmp_enable0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_iilb_ni1_cmp_enable1`

A debug-compare word of the node crossbar. The PROM writes 0 to it twice per node (first and last of the five lists), as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_iilb_cmp_exp_data0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_iilb_cmp_exp_data1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_iilb_cmp_enable0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_iilb_cmp_enable1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_ni0_cmp_exp_data0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_ni0_cmp_enable0`

A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 as a test-and-set flag word (bits 0x20, 0x40, 0x80, 0x100, 0x400), 1360 as a write-if-zero word and 1370 as an OR-accumulating word. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_ni0_cmp_enable1`

A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 as a test-and-set flag word (bits 0x20, 0x40, 0x80, 0x100, 0x400), 1360 as a write-if-zero word and 1370 as an OR-accumulating word. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_sic_cmp_exp_hdr0`

A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_sic_cmp_exp_hdr1`

A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM zeroes once per node; no reader was found. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_sic_cmp_hdr_enable0`

A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_pi_sic_cmp_hdr_enable1`

A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM zeroes once per node; no reader was found. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `cpu_hist`

Progress history of processor slice n (n = cr.lid bits 26:23, 0 to 3), 16 bytes apart; the name is ours. Every progress code is written as: read the word, shift it left 8, put the code in the low byte, write it back. The code is never read for a decision; any reset value is tolerated and the register must return what was last written. SAL_A also reads slice 1 and slice 3 words (0x150031510, 0x150031530) and copies them, ORed with 0x60, to LED registers. The block is the network interface's by address; the PROM uses it as plain storage (inferred). The SGI 2.4 SN2 header names this offset SH_XN_MD_IILB_CMP_EXP_DATA0 at 0x1_5003_1500, SH_XN_MD_IILB_CMP_EXP_DATA1 at 1510, SH_XN_MD_IILB_CMP_ENABLE0 at 1520 and SH_XN_MD_IILB_CMP_ENABLE1 at 1530: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.

Array of 4 registers, stride 16.

### Register `fw_word_1540`

Firmware flag word; the name is ours. SAL_A's election winner writes 0 to it, and a later routine writes 0 to it on another node through the node-object write (site 0xffa5d48c). No read exists on the direct-call reset path. The method tables reached through the chip object hold methods that treat it as a set of flags indexed by a bit number: claim bit n (wait until it reads clear, set it, with an optional deadline in microseconds; returns -1 on timeout), test bit n, and clear bit n, each as a read-modify-write under the lock pair lb_lock2 and lb_lock2_status, on this node (site 0xffa0efd0, 0xffa0f580) or through the global window of another (site 0xffa0f1a0, 0xffa0f3a0, 0xffa0f430, 0xffa0f650). That the flags are claims is inferred from the sequence; which bit numbers callers use was not traced, and whether any of these methods runs before the console start is unknown. The word must read back what was written. The SGI 2.4 SN2 header names this offset SH_XN_MD_NI0_CMP_EXP_DATA0: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.

### Register `cpu_bits`

Firmware per-processor state word; the name is ours. The winner of the SAL_A election zeroes it. Bits the PROM uses: 21 + slice (tested in 0xffa1d430, set in the SAL_B reset entry), 26 + slice (set by the local-master arbitration, polled until the other present processors have set theirs), 30 + slice and bit 34 (a second barrier), 35 + slice (set in the SAL_B reset entry), and a 3-bit count at bit 47 (even slice) or bit 50 (odd slice) that each present slice publishes from a PAL call and the master waits for as that many ready bits among 29:26 (inferred). Bits are set and cleared by read-modify-write under the lock pair lb_lock and lb_lock_status. The SAL_A error path clears bits 29:26. The meanings are inferred from use; the word must read back what was written. The SGI 2.4 SN2 header names this offset SH_XN_MD_NI0_CMP_EXP_DATA1: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.

### Register `fw_debug_word`

Firmware debug-switch word; the name is ours. SAL_A's election winner zeroes it; the PROM later stores the L1's reply to request 0x0001 and tests bits of it (bit 11 selects the single-node route, bit 14 skips I/O initialisation). A field setter (site 0xffa974d0, call sites 0xffa1a51c and 0xffa1a58c, both with a width of 16) replaces a bit field of it with a 16-bit value under the lb_lock and lb_lock_status lock: take the lock, read the word, clear the field, OR in the value, write, release. Plain storage. The SGI 2.4 SN2 header names this offset SH_XN_MD_NI0_CMP_ENABLE0: a 64-bit debug-compare register of the node crossbar (header text: 'MD compare ... input expected data' and 'enable'; reset 0, all 64 bits implemented). The PROM uses it as plain storage (inferred from its use; a model must keep all 64 bits). Whether a non-zero compare value or enable arms a hardware debug trigger is unknown.

### Register `xn_md_ni0_cmp_enable1`

A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM loads, stores and zeroes; the values it keeps are not decoded. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_ni1_cmp_exp_data0`

A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM uses as a counter, loading it and storing the value plus one. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_ni1_cmp_exp_data1`

A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM sets to 0xff00000000 and reads back per slice. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_ni1_cmp_enable0`

A debug-compare word of the node crossbar that the PROM uses as plain storage. Zeroed once per node, then read back by an error-record routine: 15a0 as a test-and-set flag word (bits 0x20, 0x40, 0x80, 0x100, 0x400), 1360 as a write-if-zero word and 1370 as an OR-accumulating word. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_ni1_cmp_enable1`

A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_exp_hdr0`

A debug-compare word of the node crossbar, in the block the PROM also uses for plain storage (0x1500 to 0x1560). The PROM writes 0 to it twice from a routine in the SAL_B image; no reader was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_hdr_enable0`

A debug-compare word of the node crossbar that the PROM uses as plain storage: storage the PROM sets to 0xff00000000 and reads back per slice. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data0`

A debug-compare word of the node crossbar that the PROM uses as plain storage: a word the PROM only reads, through the global window of a NASID it is given; the value is not decoded. A model must return what was written, all 64 bits. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data2`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data3`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data_enable0`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data_enable1`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data_enable2`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `xn_md_sic_cmp_data_enable3`

A debug-compare word of the node crossbar. The PROM writes 0 to it once per node, as an 8-byte store through the global window, in the lists it zeroes after 15a0, 1360 and 1370. No read-back was found. Whether a non-zero value arms a hardware compare trigger is unknown.

### Register `junk_bus_led`

Junk bus LED registers, one per processor slice (header SH1_REAL_JUNK_BUS_LED0 to 3, 64 KiB apart). The kernel keeps an 8-bit LED state per processor and stores it with a 16-bit write at LED0 plus slice times 64 KiB: bit 0 is the heartbeat, toggled twice a second from the timer interrupt, bit 1 an activity flag. The junk bus also holds the UART whose interrupt is event_occurred bit 20.

Array of 4 registers, stride 65536.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `IPI_BASE_VALUE` | 0xfee | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Constant the kernel puts in the base field of every IPI message: 0xfee in units of the field (2 MiB, from bit 21), which is 0x1_fdc0_0000 as an address (0xfee << 21; inferred arithmetic). It is not the 0xfee00000 of the kernel's generic interrupt base constant: that equivalence does not follow from the field position. Used with the vector in the idx field. |
| `PIO_WRITE_STATUS_ALIAS_CLEAR` | 0x7 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Value the kernel's TLB-purge deadlock recovery writes to the alias on SHub 1 to clear the deadlock, write error and multiple write error bits (assembly comment). |
| `PIO_WRITE_STATUS_IDLE` | 0x3f00000000000000 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | What the kernel waits for the masked pending-write count to equal on SHub 1: all six bits set, not zero. The kernel comment points at a defect number for this behaviour; the defect text is not in the sources read. The SHub 2 overlay sets zero. |
| `PI_CAM_WAR_VALUE` | 0x8000000000000010 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Value the kernel writes to the PI CAM control register from every timer tick on a SHub 1 of revision 2 or lower. Meaning not stated by the sources. |
| `RTC_CONFIG_MASK` | 0xff3ffffffefffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of an RTC interrupt configuration register (header SH_RTC1_INT_CONFIG_MASK): bits 59:52 and 49:0 except bit 20. |
| `RTC_ENABLE_MASK` | 0x1 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of an RTC interrupt enable register. |
| `RTC_MASK` | 0x7fffffffffffff | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Valid bits of the real-time clock and of each comparator: 55 bits. The mmtimer driver reports 55 as the clock width. |
| `SHUB_1_1_MAX_REVISION` | 0x2 | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Revision field value at or below which the kernel enables its SHub 1.1 workarounds. |
