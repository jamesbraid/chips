# Tier-2 reading, batch 0 of chips: routine role entries

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: addresses, loads and stores, calls and constants. Every entry is inferred. Where the facts leave something open, the entry says so.

- `i2c_probe` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x88
  **Inferred.** Reads a doubleword from the fixed address 0x9200000001030100 and a second doubleword from an address built from a0 in the high window, several times over (`ld` at 0x8c, 0xb8, 0xbc, 0xf8, 0x108). Unsigned compares at 0xf0 and 0x12c against a6 and an equality test at 0x100 of a5 against t0 steer a loop that leaves by returning 0 at 0x138 or 1 at 0x140. The loop may be a bounded poll, but the facts do not show what it waits for. The meaning of the compared values is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `i2c_arb` in `IP27/usr/cpu/sysgen/IP27boot/i2c.o` at 0x148
  **Inferred.** Calls node_can_talk_to_elsc at 0x194 with its four arguments, and a zero result there branches to the tail at 0x334. Later it tests bit 0 of doublewords loaded through a0-derived addresses (0x1bc, 0x214, 0x2d4) and compares the constants 0xe0 (a4) and 0xe8 (a5) against a doubleword loaded through an a0-derived address (0x1cc, 0x1d4, 0x224, 0x22c). It stores a doubleword through a2 at 0x208 and its return value at 0x350 is either unresolved or -0xb. Which arbitration step each branch implements is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xe668
  **Inferred.** Calls xwidget_info_get at 0xe674 with its four arguments, then passes that result to xwidget_info_id_get at 0xe680 and xwidget_info_master_get at 0xe68c. It passes the master to hwgraph_info_get_LBL at 0xe6a8. It tests the result of an AND with t2 at 0xe6ec against zero, where the doubleword loaded at 0xe6d8 comes from a table based at 0x9200000001c00118 whose index the facts do not resolve, and returns 0 or 1 (0xe6f8). cmn_err is called at 0xe71c with the constant 0x6 as its first argument; what condition leads there is not shown. The bit that means DMA is enabled is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `crbx` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xeed4
  **Inferred.** A formatter with many sprintf calls (0xef98, 0xefe4, 0xf37c, 0xf53c, 0xf56c, 0xf5b8) that write into stack buffers at sp-112, sp-120 and sp-136. It makes 12 indirect calls through registers (0xef18 to 0xef60, 0xf070, 0xf0c8, 0xf110 and 0xf190) whose targets the facts do not resolve. The branches compare the register `a2` with 1, 2, 3, 4, 5, 8, 0x12, 0x41 and 0x100, and `a1` with 0x6, 0x7, 0x8, 0x20, 0x21, 0x22, 0x81, 0x83 and 0xa2; the facts do not resolve which routine arguments those registers hold. The field each path prints is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_ifdr_check_value` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0xfd4c
  **Inferred.** Returns 0 at once when the flag hubio_ifdr_skip is set (0xfd50, 0xfd58). Otherwise it loads a halfword from compact_to_nasid_node indexed by a0 (`lh` at 0xfd74) and a doubleword from a pointer table indexed by a0 (0xfd88), then reads a halfword at offset 19588 of that doubleword's target (0xfd94). It returns 1 when that halfword is below the value in v1 and 0 otherwise (0xfda4 to 0xfdb4). A further load at 0xfd90 is built from the nasid halfword, but the facts do not show that it feeds v1. The meaning of the halfword and of v1 is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_widget_reset` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x104e0
  **Inferred.** Brackets its work with splhi at 0x10528 and splx at 0x105f0, and gets the master node from master_node_get at 0x104ec. A loop counts s1 up to 8 (0x1055c, 0x10584) and tests mask 0x10 of a doubleword loaded at 0x105c4 and 0x10640 through an address built from a compact-to-nasid index shifted left by 0x20 (branches at 0x105cc and 0x10648). It calls hub_setup_prb once, at 0x105e8, with the constants 3 and 2 as its third and fourth arguments. Two assfail calls at 0x1065c and 0x10678 pass the constant 0x562 as their third argument. The registers the loop writes are unknown.
  Reviewed: 2026-11-12 (sonnet)

- `bte_pbzero` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x13334
  **Inferred.** Role (from name): zeroes a range through the block transfer engine. It calls bzero on a0 | 0xa800000000000000 at 0x133b8 and 0x134c8, and calls bte_copy at 0x13448 with a0 = 0 and a3 either 0x10 or 0x11. A branch at 0x13464 compares s0 unsigned with 0x4001 and goes back to 0x13438 when s0 is below it. Branches at 0x13368 and 0x13378 test the flags disable_bte_pbzero and disable_bte, and get_hub_chiprev is called at 0x13410, but the facts do not show that its result decides a branch. Which flag or revision picks which path is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** Returns 0 without copying when a2 is zero (0x14700). Otherwise it calls bte_copy at 0x14708 with a0, a1 and a2 passed through and the constant 0x110 as the fourth argument. A nonzero result (0x14710) is reported through cmn_err at 0x14738 with the constant 0xc and the result. The return value is 0 or the bte_copy result. The meaning of the constant 0x110 is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** Role (from name): clears hub PI error state. It runs a loop. Each pass loads doublewords through pointers the facts do not resolve (0x164cc, 0x164dc) and the fixed address 0x9200000001030100 (0x164e0), and stores two doublewords (0x164f4, 0x164f8). The branch at 0x164ec skips those two stores when the constant 0x55d4a80 is at least a7, unsigned. The loop continues while a4 is nonzero (0x164fc). The stored values and store addresses are unknown.
  Reviewed: 2026-11-12 (sonnet)

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** Works on one error record passed in a0. It tests the fields at offsets 0x8, 0x18, 0x28 and 0x38, and writes back to those slots at 0x16570, 0x16544, 0x1659c and 0x165c8 when the test allows it. Each write is guarded by a bound check against the constant 0x55d4a80, compared unsigned (0x1653c, 0x16568, 0x16594, 0x165c0). It also reads the fixed address 0x9200000001030100 at 0x16530, the same location the PI-error clear routine reads. The values written are unknown.
  Reviewed: 2026-11-12 (sonnet)

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** Looks up a compact node index in nasid_to_compact_node (`lh` at 0x1a63c) and takes that node's pointer from kl_error_log (0x1a654). When the record pointer is nonzero (0x1a674), it calls md_err_log_prev at 0x1a688, and calls it again at 0x1a73c, looping back to 0x1a6e4 while that second call returns nonzero (0x1a74c). It also calls md_err_log_last at 0x1a84c. A word loaded at 0x1a708 is compared with 2, 1, 3 and 4 (0x1a70c to 0x1a724), and falling through all four reaches kl_panic at 0x1a730. The meaning of each case is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** Takes a spinlock at offset 796 of the structure in a1 (mutex_spinlock_spl at 0x1b8fc) and releases it with mutex_spinunlock at 0x1ba7c. It compares values with 1, 2 and 5 (0x1ba08, 0x1ba10, 0x1ba20, 0x1ba28) and with a loop bound of 0xf (0x1b994). On one path it calls bte_crb_error_handler (0x1ba4c) and hubiio_crb_free (0x1ba58). It calls sn0_error_dump at 0x1bb08 and cmn_err at 0x1bb1c, 0x1bbd0 and 0x1bbf0. An assfail call at 0x1bbac passes 0x70c as its third argument. The jump table at 0x1bad0 has unresolved targets, so the full set of cases is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** Maps the nasid in a0 to a compact node index through nasid_to_compact_node (`lh` at 0x1c184), then loads that node's record pointer from kl_error_log (0x1c19c). It returns -1 when a0 is negative (0x1c16c) or when v1 is zero (0x1c17c). When the compact index is -1 (0x1c18c) it skips the store. Otherwise it stores a 4-byte word at the start of the record (0x1c1a4). The return at 0x1c1a8 is -1 or 0 and the facts do not say which path gives which. The value stored is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** Maps the nasid in a0 to a compact node through nasid_to_compact_node (0x1c1dc). It writes a 4-byte word through the a1 pointer (0x1c1ec) and returns the doubleword in that node's kl_error_log slot (0x1c1f4, 0x1c1f8). It returns 0 when a0 is negative or at least 0x100 (0x1c1c0, 0x1c1d4), and when the compact index is -1 (0x1c1e0). The word written through a1 is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** A one-call wrapper. It calls do_intr_block_bit at 0x1f828 with its first two arguments and its fourth argument passed through, and the constant 0x1 as the third argument. It returns that call's value. What the constant 1 selects is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The same one-call wrapper as its neighbour at 0x1f820. It calls do_intr_block_bit at 0x1f844 with the first two and the fourth arguments passed through, and the constant 0x0 as the third argument. It returns that call's value. What the constant 0 selects is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `tvtoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e89c
  **Inferred.** Reads a 4-byte field at offset 0x4 and an 8-byte field at offset 0x8 of its a0 argument (0x2e89c, 0x2e8ac). An equality test of a1 against 1 at 0x2e8dc picks one of two return points (0x2e8e4, 0x2e8f4). Only when a1 equals 1 does it read the fixed address 0x9200000001030100 (0x2e8f0). Role (from name): converts a time value to a clock counter. The returned values are unknown.
  Reviewed: 2026-11-12 (sonnet)

- `acktmoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0
  **Inferred.** Reads a halfword from the fixed address 0xffffffffffffc420 (0x2f3d0) and uses it as a per-CPU index into the pda table (sym(pdaindr), shifted by 4). It checks a flag byte at offset 0x520 of that per-CPU record (0x2f3e4, 0x2f3ec). Depending on that test it writes one doubleword, to 0x9200000001000128 (0x2f3f4) or to 0x9200000001000120 (0x2f404), and returns the shifted index. Which device registers those writes reach is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `startkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440
  **Inferred.** Takes the lock at offset 288 of sym(.sbss) with mutex_spinlock_spl (0x2f44c) and releases it with mutex_spinunlock (0x2f50c, 0x2f548). Under the lock it reads a word at the fixed address 0xffffffffffffc534 (0x2f464), loads doublewords from 0xffffffffffffc400, and stores a doubleword at 0x9200000001000158 (0x2f4b0). It calls cnodetocpu at 0x2f4c4 and compares its result with a halfword loaded from 0xffffffffffffc420 (0x2f4d0). When the flag at sym(.sdata)+392 is zero (0x2f45c), it calls setkgvector with prof_intr at 0x2f52c. The registers involved and the arithmetic on the counter at 0x2f4bc are unknown.
  Reviewed: 2026-11-12 (sonnet)

- `slowkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f558
  **Inferred.** Role (from name): the slow clock tick. It takes the lock at offset 288 of sym(.sbss), the same one as startkgclock (mutex_spinlock_spl at 0x2f56c, mutex_spinunlock at 0x2f59c and 0x2f5f4). It reads the per-CPU record through the same pda lookup and stores doublewords at 0x9200000001000158 and 0x9200000001000150 (0x2f5c4, 0x2f614). It calls ackkgclock at 0x2f5fc. A zero flag at sym(.sdata)+400 leads to a spinlock_init call at 0x2f61c, and the audioclock global is tested at 0x2f590 before the store at 0x2f5c4. The meaning of the writes is unknown.
  Reviewed: 2026-11-12 (sonnet)

- `hubdev_prombase_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x33050
  **Inferred.** Makes one hwgraph_info_get_LBL call (0x33064) on its a0 argument with the label string at .rodata+46016 and a stack buffer at sp-16. It reads a halfword (0x33074) whose source is unknown. It then returns a value loaded from a table based at 0x9000000030000000 (0x33084); the facts do not resolve the index. What the routine is for is unknown: the facts do not show the lookup result feeding that return value, and the callers that use the return value would settle it.
  Reviewed: 2026-11-12 (sonnet)

- `hubdev_cnodeid_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3308c
  **Inferred.** Makes the same hwgraph_info_get_LBL call as its neighbour at 0x33050, with the same label string and a stack buffer at sp-16 (0x330a0). It then reads a halfword (0x330b0) and returns (0x330b4). Role (from name): returns a compute-node id. The return value and the halfword's source are unknown.
  Reviewed: 2026-11-12 (sonnet)
