<!-- generated from devices/shub/registers.toml by defs-gen - do not edit, change the source -->

# SHub 1 registers outside the I/O interface: interrupts, local block, real-time clock, PIO write status, TLB purge, junk bus LEDs

SHub 1 offsets as the SGI Linux ia64 platform header defines them (SH1_ names), relative to the node's register space; the SHub 2 overlay changes them. Every register is 64 bits wide unless noted, because the kernel reaches all of them with 64-bit loads and stores. The header gives neither the unit a register belongs to nor reset values; the unit named in each doc is inferred from the register's name prefix and address block. Reset values are unknown except where the header's INIT macro names a value, which is recorded as inferred. Roles are paraphrased from the header comments and the kernel's use.

Unit `shub`, macro prefix `SHUB`.
Default source: Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `chip_id` | 0x100000000 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa0be1c (read) and 0xffa0f8c0 (storage of the fields); the compare against 17251 is site 0xffa959a6 |
| `md_mbist_status` | 0x100000080 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa6fbac (written 0 at engine start); bit 36 read on failure per the earlier reviewed reading; no Linux v5.3 name |
| `md_mbist_err` | 0x1000000b8 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa725f6 (read in the failure report, per the earlier reviewed reading); no Linux v5.3 name |
| `md_mbist_mask` | 0x1000000c0 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa6fbdc (written all ones at engine start); no Linux v5.3 name |
| `md_bank_cfg0` | 0x100010000 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_bank_cfg1` | 0x100010008 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_bank_cfg2` | 0x100010010 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_timing_0` | 0x100010020 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_timing_1` | 0x100010028 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_refresh_0` | 0x100010030 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_timing_2` | 0x100010040 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_timing_3` | 0x100010048 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_refresh_1` | 0x100010050 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_const_58` | 0x100010058 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_ctl_60` | 0x100010060 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_const_78` | 0x100010078 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa76bf0 (memory controller set-up; sites per node-bringup.md); no Linux v5.3 name |
| `md_mbist_cmd` | 0x100020080 | w | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa6fb7c (written first when the engine starts); no Linux v5.3 name |
| `md_mbist_ctl` | 0x100020088 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa6fc3c (start), 0xffa6fd3c (poll), 0xffa6b1dc (failure test); no Linux v5.3 name |
| `md_dqlp_dir_privilege_vector` | 0x100030300 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `md_dir_access_lp` | 0x100031000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6b10c (memctl_write_dir_access, the string the routine prints); no Linux v5.3 name |
| `md_dqrp_dir_privilege_vector` | 0x100050300 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `md_dir_access_rp` | 0x100051000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa6b14c; no Linux v5.3 name |
| `ipi_int` | 0x110000380 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc_int_config` | 0x110001480 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc_int_enable` | 0x110001500 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred` | 0x110010000 | r | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `event_occurred_alias` | 0x110010008 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `lb_reg_1002_0000` | 0x110020000 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e7f0 (offset and use); no Linux v5.3 name |
| `lb_slice_rec` | 0x110030000 | r | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffa0e020 (read of the running processor's entry), 0xffc4e570 (reasons 1 and 2 only) |
| `rtc_ctl` | 0x110060280 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa94d06, 0xffa94d26 (writes), 0xffa0da00 (read of the period); the SAL runtime component's chipset_rtc_period reads the same field |
| `ipi_access` | 0x110060480 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `md_clk_sel` | 0x110060500 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa77e0c (read through the node's global window), 0xffa77e20 (mask); no Linux v5.3 name |
| `shub_id` | 0x110060580 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `ptc` | 0x1101a0000 | w | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `int_cmp` | 0x1101b0080 | rw | 64 | 3 |  | 0x0 (inferred) | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `rtc` | 0x1101c0000 | rw | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `lb_elect` | 0x1101d0080 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e9b0, 0xffc4e766 (election reads), 0xffc4e246, 0xffa0b0f0 (bit updates); no Linux v5.3 name |
| `lb_elect_set` | 0x1101d0088 | w | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e9a6 (release store of slice + 1); no Linux v5.3 name |
| `lb_l1_state` | 0x1101d0100 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e790 and 0xffc4e7a0 (read-modify-write); the PROM's runtime also names the word sc_shub_state_reg and sc_shub_pushed_data_reg |
| `lb_lock` | 0x1101d0200 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa0ed30 (take), 0xffa0ee40 (release), 0xffa0e730 (user) |
| `lb_lock_status` | 0x1101d0208 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa0ed30 (the poll); the offset-form variant site 0xffa0e880 reads 0x1101d0208 on a remote node |
| `pi_reg_2000_0000` | 0x120000000 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa97796 to 0xffa97916 (read, OR, write) and site 0xffc4e276 (SAL_A error path); no Linux v5.3 name |
| `pi_reg_2000_0180` | 0x120000180 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa2459c to 0xffa245cc (read, OR bit 63, write); other sites site 0xffae3696; no Linux v5.3 name |
| `pi_reg_2001_0100` | 0x120010100 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4e800 and 0xffc4e816 (read-modify-write); Linux v5.3 defines no name |
| `pi_slice_present` | 0x120020080 | r | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffa115ac (read through the global window of the node), 0xffa99e2c (caller) |
| `pi_cam_control` | 0x120050300 | w | 64 |  |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pi_reg_2006_0100` | 0x120060100 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa246a6 (read after the pi_cam_control write); no Linux v5.3 name |
| `pi_reg_2006_0180` | 0x120060180 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa246d6; no Linux v5.3 name |
| `pi_reg_2006_0200` | 0x120060200 | r | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffa246f6; no Linux v5.3 name |
| `pio_write_status` | 0x120070200 | r | 64 | 2 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `pio_write_status_alias` | 0x120070208 | w | 64 | 2 |  | unknown | inferred | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |
| `cpu_hist` | 0x150031500 | rw | 64 | 4 |  | unknown | established | SAL 5.04 PROM site 0xffc4e5c6 and 0xffc4e5e0 (progress write), 0xffa0ddb0; no Linux v5.3 name |
| `fw_word_1540` | 0x150031540 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffc4ea06 (zeroed by the election winner); no Linux v5.3 name |
| `cpu_bits` | 0x150031550 | rw | 64 |  |  | unknown | established | SAL 5.04 PROM site 0xffc4ea00 (zeroed), 0xffa0e730 (set and clear a bit under the lock), 0xffa1d430 (test), 0xffa99cf0 and 0xffa9a130 (arbitration); no Linux v5.3 name |
| `fw_debug_word` | 0x150031560 | rw | 64 |  |  | unknown | inferred | SAL 5.04 PROM site 0xffc4ea10 (zeroed in SAL_A), 0xffa19e50 (loaded from the L1 reply in phase 0xe), 0xffa975e0 (bit test) |
| `junk_bus_led` | 0x7fed00000 | w | 16 | 4 |  | unknown | established | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver |

### Register `chip_id`

Chip identification word at node offset 0x1_0000_0000 (memory and directory block by address); the name is ours. The PROM reads it through the node's global window at node start and stores bits 27:12 as the node's part number and bits 31:28 as its revision. The part number is compared with 17251 (0x4363) site 0xffa959a6, reached through a table, so that this word feeds the compare is inferred. A bounded read that returns the part number satisfies the PROM.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31:28 | `revision` | established |  | SAL 5.04 PROM site 0xffa0f8c0 (stored) | Revision as stored by the PROM; no value is required here. |
| 27:12 | `part_number` | inferred |  | SAL 5.04 PROM site 0xffa0f8c0 and 0xffa959a6 | Part number; the PROM expects 0x4363 (17251). Inferred: the compare's input is not traced to this word. |

### Register `md_mbist_status`

Memory test engine status; the name is ours. Written 0 at engine start. The memory-test loop reads bit 36 after every engine run (site 0xffa702c0) and treats it set as failure (-2), so it must read 0 on a passing run; the error report reads it again and then md_mbist_err. The directory write does not test it. The flag name (compare error) is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 36 | `cmp_err` | inferred |  | SAL 5.04 PROM site 0xffa702c0 and 0xffa72500, per the node-bringup.md review | Set means the engine run failed. Name is ours. |

### Register `md_mbist_err`

Memory test engine other-error value; the name is ours. Read only in the failure report, after bit 36 of md_mbist_status is found set; not read on a passing run.

### Register `md_mbist_mask`

Memory test engine mask; the name is ours (inferred from the all-ones write only). Written with all ones each time the engine starts.

### Register `md_bank_cfg0`

Memory controller register, unnamed; the name is ours. Per-bank configuration word 0 of the memory controller set-up (node-bringup.md: timing index in bits 35:32 and one byte per bank at bit 8k with density index in 2:0, rank code in 3 and bank number in 6:5; not re-read for this file).

### Register `md_bank_cfg1`

Memory controller register, unnamed; the name is ours. Per-bank configuration word 1; read once first, then written.

### Register `md_bank_cfg2`

Memory controller register, unnamed; the name is ours. Per-bank configuration word 2; the memory test driver reads each bank's config byte here and skips banks whose density index is 7 (empty).

### Register `md_timing_0`

Memory controller register, unnamed; the name is ours. Timing fields built from a 32-byte flash table row; bits 7:0 are 0x02 and one of bits 52, 53 or 54 selects tRCD 3, 2 or 4 (node-bringup.md; not re-read for this file). Read then written.

### Register `md_timing_1`

Memory controller register, unnamed; the name is ours. Six 4-bit timing fields (node-bringup.md; not re-read for this file). Read then written.

### Register `md_refresh_0`

Memory controller register, unnamed; the name is ours. Refresh interval 195 in bits 16:8 (overridable by the MemoryRefresh variable), tRFC clocks in bits 22:17 and per-bank enables (node-bringup.md; not re-read for this file).

### Register `md_timing_2`

Memory controller register, unnamed; the name is ours. Paired with md_timing_0 (same layout, per node-bringup.md); read then written.

### Register `md_timing_3`

Memory controller register, unnamed; the name is ours. Second copy of md_timing_1's layout; read then written.

### Register `md_refresh_1`

Memory controller register, unnamed; the name is ours. Second copy of md_refresh_0's layout.

### Register `md_const_58`

Memory controller register, unnamed; the name is ours. Written with the constant 0x4004e20 (node-bringup.md).

### Register `md_ctl_60`

Memory controller register, unnamed; the name is ours. Written 0x4047 when the SHub ID revision is above 2 and 0x4045 otherwise (the same revision split as pi_reg_2000_0000's OR value).

### Register `md_const_78`

Memory controller register, unnamed; the name is ours. Written with the constant 0x24 (node-bringup.md).

### Register `md_mbist_cmd`

Memory test and DRAM initialisation engine, command or address word; the name is ours. Written with the caller's word before md_mbist_ctl. The meaning of the word is unknown; it is plain storage as far as the PROM shows.

### Register `md_mbist_ctl`

Memory test and DRAM initialisation engine control; the name is ours. The PROM starts the engine by writing md_mbist_cmd, then 0 to md_mbist_status and all ones to md_mbist_mask, then this register with go set, an operation code in bits 38:32 and a 31-bit value. It then polls: while (value & 0x300_0000_0000) equals 0x100_0000_0000 (go set, fail clear) it waits; it stops when go clears or fail sets, with a deadline of 20,000,000 microseconds on the PROM's own clock routine (the routine site 0xffa0da70 returns microseconds). Fail set afterwards is an error. A model where go clears at once and fail never sets satisfies the code.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 41 | `fail` | inferred |  | SAL 5.04 PROM site 0xffa6fd40 (mask 0x30000000000) and 0xffa6b1e6 (bit test) | Set when the operation failed; the PROM stops polling when it sets and reports an error. Name is ours. |
| 40 | `go` | inferred |  | SAL 5.04 PROM site 0xffa6fc16 (constant 0x10000000000) and the poll site 0xffa6fd40 | Written 1 to start; reads 1 while the engine runs. The PROM waits for it to clear. Name is ours. |
| 38:32 | `op` | inferred |  | SAL 5.04 PROM site 0xffa6fc26 (seven-bit deposit at bit 32) | Operation code: 64 for the directory write, 48 and 16 for the memory test, 7, 2, 0, 0, 2, 1, 1, 0 for the first DRAM initialisation sequence (earlier reading, meaning inferred). Name is ours. |
| 30:0 | `value` | inferred |  | SAL 5.04 PROM site 0xffa6fbe6 (mask 0x7fffffff) | Operand written with the operation. Name is ours. |

### Register `md_dqlp_dir_privilege_vector`

Memory and directory unit: privilege vector for access class 0 of the left directory queue port (header SH1_MD_DQLP_MMR_DIR_PRIVEC0, title 'privilege vector for acc=0'). Defined by the header; no use in any kernel file read. Layout and role unknown.

### Register `md_dir_access_lp`

Directory memory initial-value write, left queue port block (the block is the one the Linux header calls SH1_MD_DQLP_MMR_DIR_PRIVEC0 at the 0x300 offset; the left reading is inferred from that name); the name is ours. The PROM stores the value shifted left 55 here and to md_dir_access_rp, then runs the engine with operation code 64. No separate initialise register for directory ECC was seen. The routine fails on a -3 timeout or bit 41 of md_mbist_ctl and does not test bit 36 of md_mbist_status.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:55 | `value` | inferred |  | SAL 5.04 PROM site 0xffa6b076 (shift left 55) | The caller's value shifted left 55. The width of the field is inferred from the shift; name is ours. |

### Register `md_dqrp_dir_privilege_vector`

Same, right queue port (header SH1_MD_DQRP_MMR_DIR_PRIVEC0). The reading of DQLP and DQRP as left and right ports is inferred from the names.

### Register `md_dir_access_rp`

As md_dir_access_lp for the right queue port block (SH1_MD_DQRP_MMR_DIR_PRIVEC0's block); the name is ours.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:55 | `value` | inferred |  | SAL 5.04 PROM site 0xffa6b076 | As md_dir_access_lp. Name is ours. |

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

Pending interrupt events for the node (SHub interrupt event occurred). The kernel's interrupt acknowledge reads it, keeps the bits in the mask of the junk-bus UART, IPI and the two II interrupts, and writes that value to the alias to clear them. Only bits the header names are recorded; the others are unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `ii_int1` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 1. |
| 29 | `ii_int0` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending I/O interface interrupt 0. |
| 28 | `ipi_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending IPI interrupt. |
| 26 | `rtc3_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 3 interrupt. |
| 25 | `rtc2_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 2 interrupt. |
| 24 | `rtc1_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending RTC comparator 1 interrupt. |
| 20 | `uart_int` | established |  | Linux v5.3 SGI SN2 platform MMR header (GPL): names, offsets and field positions; kernel use from the same tree's SN2 setup, interrupt, I/O, timer, SMP and TLB-purge code and the v4.9 real-time clock driver | Pending junk-bus UART interrupt. |

### Register `event_occurred_alias`

Clears pending events: the kernel writes the bits it wants cleared here and never reads it. That a one clears and a zero leaves a bit alone is inferred from the kernel writing back exactly the bits it read as set (interrupt acknowledge) and a single bit to clear one RTC event (the mmtimer driver). Neither the kernel nor the header says what a read returns.

### Register `lb_reg_1002_0000`

Local block register, unnamed; the name is ours (address). SAL_A writes 0x15031010 to it on each of its two entries (reason 3 and reason 0). The image holds no other reference to the address, so it is never read back. The meaning of the value is unknown; a plain write-accepting register satisfies the PROM.

### Register `lb_slice_rec`

Per-slice local block record, 128 bytes apart (index = slice & 3); the name is ours. SAL_B reads the running processor's entry in the lock routine and writes its low byte as a progress code, so any value is accepted; SAL_A reads it into r31 for reasons 1 and 2 only. The meaning of the value is unknown.

Array of 4 registers, stride 128.

### Register `rtc_ctl`

Real-time clock control; the name is ours. The PROM writes 0x100000000, then writes 0 to rtc, then writes 0x100000041, all at the SAL_B reset entry, before any read. The tick period in nanoseconds is 10 times (period + 1); with the PROM's write the field is 4, 50 ns, 20 MHz, which is also what SAL_FREQ_BASE for the real-time clock returns (1,000,000,000 divided by the period). The reset value never reaches the PROM. Roles of the other bits are inferred only. If a read returned 0 the PROM would assume a 10 ns period (100 MHz); every PROM deadline is in microseconds scaled by this period, so the counter must tick at the rate the field gives.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 33:32 | `mode` | inferred |  | SAL 5.04 PROM site 0xffa96626 (read), 0xffa967e6 (set to 1) and 0xffa94d26 (written 1) | Read by an interconnect-phase routine that branches on 1, 2 and 3, and set to 1 by another. Written 1 by the reset entry. Meaning inferred only; name is ours. |
| 13:4 | `period` | established |  | SAL 5.04 PROM site 0xffa0da00 and the SAL runtime's chipset_rtc_period | Tick period field: period in nanoseconds is 10 times (value + 1). Written 4 by the PROM. Name is ours. |
| 0 | `run` | inferred |  | SAL 5.04 PROM site 0xffa94d06 (clear), 0xffa94d26 (set), 0xffa967e6 (clear) | Clear when the PROM writes the counter to 0, set after; cleared again by an interconnect-phase routine. A run control is inferred from that order only; name is ours. |

### Register `ipi_access`

Which processors may send interprocessor interrupts to this one (header title: CPU interrupt access permission bits). The only use found is the cross-partition driver reading it as the target of a protected remote read; the driver comment says there is no special reason for that choice. So the register can be read without harm; its bit layout and write behaviour are unknown. The SHub 1 PROM writes 1 here once, as the winner of the node election in SAL_A (SAL 5.04 PROM site 0xffc4ea40); the meaning of 1 is unknown.

### Register `md_clk_sel`

DRAM bus clock select; the name is ours. The memory-controller set-up reads it and uses bits 1:0 as an index into a four-entry table held in flash (200, 160, 133 and 100 MHz for 0 to 3, per the earlier reading). The chosen clock and the DIMM's CAS latency must be a pair the PROM supports or it prints that the memory bus speed is not supported. In the local block by address. Linux does not define it: the position and use are as observed in the PROM, the meaning (bus clock select) is inferred.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1:0 | `sel` | inferred |  | SAL 5.04 PROM site 0xffa77e20 | Clock table index. Name is ours. |

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

### Register `lb_lock`

Firmware lock pair, release side; the name is ours. The PROM takes the lock by polling lb_lock_status until it reads 0, does a read-modify-write of cpu_bits, then writes 0 here. If the status does not read 0 within 1,000,000 microseconds it writes 0 here and polls again. Whether a read of lb_lock_status takes the lock in hardware is unknown; a plain register pair where the status always reads 0 satisfies every access read. Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.

### Register `lb_lock_status`

Firmware lock status; the name is ours. The PROM polls it with a short delay until it reads 0; any non-zero value keeps it waiting until the 1,000,000 microsecond deadline, then it writes 0 to lb_lock and keeps polling, so a status that never reads 0 hangs the PROM. A read side effect is unknown. Linux v5.3 does not define the lock; the PROM behaviour above is as observed at the access and the meaning is inferred.

### Register `pi_reg_2000_0000`

Processor interface register, unnamed; the name is ours. A SAL_B routine sets bit 24 of pi_reg_2001_0100, reads this register, ORs in 0x3b03f7 when the SHub ID revision (bits 31:28 of shub_id) is above 2 and 0x3f1 otherwise, writes it, then clears bit 24 again. SAL_A's error path writes 0x1000100000000 here (bits 48 and 32) and spins. What the bits mean is unknown; that the OR value splits at revision 2 is established (the same split as the memory controller's 0x4047 and 0x4045).

### Register `pi_reg_2000_0180`

Processor interface register, unnamed; the name is ours. A routine reached through a table that also writes pi_cam_control reads this register and writes it back with bit 63 set. Meaning unknown.

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

### Register `cpu_hist`

Progress history of processor slice n (n = cr.lid bits 26:23, 0 to 3), 16 bytes apart; the name is ours. Every progress code is written as: read the word, shift it left 8, put the code in the low byte, write it back. The code is never read for a decision; any reset value is tolerated and the register must return what was last written. SAL_A also reads slice 1 and slice 3 words (0x150031510, 0x150031530) and copies them, ORed with 0x60, to LED registers. The block is the network interface's by address; the PROM uses it as plain storage (inferred).

Array of 4 registers, stride 16.

### Register `fw_word_1540`

Firmware scratch word; the name is ours. SAL_A's election winner writes 0 to it. No read was found in the reset phase. Plain storage satisfies the access.

### Register `cpu_bits`

Firmware per-processor state word; the name is ours. The winner of the SAL_A election zeroes it. Bits the PROM uses: 21 + slice (tested in 0xffa1d430, set in the SAL_B reset entry), 26 + slice (set by the local-master arbitration, polled until the other present processors have set theirs), 30 + slice and bit 34 (a second barrier), 35 + slice (set in the SAL_B reset entry), and a 3-bit count at bit 47 (even slice) or bit 50 (odd slice) that each present slice publishes from a PAL call and the master waits for as that many ready bits among 29:26 (inferred). Bits are set and cleared by read-modify-write under the lock pair lb_lock and lb_lock_status. The SAL_A error path clears bits 29:26. The meanings are inferred from use; the word must read back what was written.

### Register `fw_debug_word`

Firmware debug-switch word; the name is ours. SAL_A's election winner zeroes it; the PROM later stores the L1's reply to request 0x0001 and tests bits of it (bit 11 selects the single-node route, bit 14 skips I/O initialisation). Plain storage.

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
