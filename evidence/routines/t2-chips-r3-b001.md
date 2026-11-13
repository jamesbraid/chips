# Tier-2 routine roles, chips batch 1

Role statements for batch 1 of the tier-2 reading round, targets 26 to 50 of the ranked list. Each statement comes only from the rendered facts for that routine: registers, calls, constants and branch structure in the named binary. Routine names and the purposes they suggest come from symbol names, and each entry says where the reading is a guess.

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** A branch at 0x14758 on a1 == 0 goes to 0x14824; the facts do not show that target as a return. Otherwise the routine branches on the symbols disable_bte_poison_range and disable_bte and on maxcpus (0x14768, 0x14778, 0x14784). On the path through 0x14798 it calls poison_state_alter_range with a0 OR'd with 0xa800000000000000 and a2 = 0x1, and calls bte_copy at 0x147e8 with a1 = 0x0, a3 = 0x110 and a4 = 0x4000. A second call to poison_state_alter_range at 0x14840 has a2 = 0x1; which path reaches it is not derived. The routine returns 0 or the bte_copy result (0x1481c). The meaning of the 0xa8 tag and the copy's purpose are not in the facts.
  Reviewed: 2026-11-12

- `bte_wait_for_xfer_completion` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14864
  **Inferred.** The routine loads a pointer from a0 and then the 16-bit field at the low end of the word it points to, branching on whether that field is zero (beq at 0x1487c). It spins in a loop (beq at 0x148a0 back to 0x1488c) whose bound is read from the global block at 0x9200000001030100, using the constant 500 (0x1f4) as an offset. On exhaustion it reports through cmn_err at 0x148c8 with level 0x14 and the constant 0x1f4. The name suggests a transfer wait; which field is polled is inferred from the load shape alone.
  Reviewed: 2026-11-12

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** The routine is a 20-byte leaf: one 8-byte load at 0x15410, then a return at 0x15418 whose v0 the facts do not tie to that load. It makes no call and no branch. The facts do not give the load's address. Role (from name): reading a link state; the facts show only a raw doubleword load, so the bit meaning is not derived.
  Reviewed: 2026-11-12

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** The routine tests the byte at +0x38 of the record at a0 (lbu at 0x16310); when it is zero the branch at 0x16318 goes to a return at 0x16358. When it is set, the routine loads two doublewords (ld at 0x16324, 0x16328) and compares one unsigned against the constant 0x55d4a80 (beq at 0x16334); when that value is at or above the constant it goes to a return at 0x16360. Only when it is below the constant does it store a byte at +0x39 (sb at 0x1633c) and copy three doublewords from +0x18, +0x10 and +0x8 into +0x30, +0x28 and +0x20 (sd at 0x1634c, 0x16350, 0x16354). A second sb at +0x39 sits at 0x16364. Role (from name): restoring a saved CPU error record; what the loaded value is and the purpose of the copy are not derived.
  Reviewed: 2026-11-12

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** Role (from name): restoring a saved hub error record at a0. Four doublewords at +0x1f8, +0x1e8, +0x208 and +0x218 are each tested against zero (beq at 0x16370, 0x16380, 0x1638c, 0x16398). When one is zero the branch goes to a block (0x163fc, 0x16430, 0x1645c, 0x16488); when it is nonzero control continues to the next test. Each block loads a pointer field (+0x70, +0x60, +0x80 or +0x90) and skips when it is zero (beq at 0x16408, 0x16434, 0x16460, 0x1648c). Otherwise it loads a second field (+0x68, +0x58, +0x78 or +0x88) and a doubleword through it, compares that unsigned against the constant 0x55d4a80 (beq at 0x16420, 0x1644c, 0x16478, 0x164a4), and stores a doubleword into the tested word only when the value is below the constant (sd at 0x1642c, 0x16458, 0x16484, 0x164b0). A loop around 0x163a4 to 0x163cc and a return of the doubleword at +0x1e8 (0x163c0) are not derived further. Which saved word pairs with which block is read from the branch order.
  Reviewed: 2026-11-12

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** The routine loads doublewords through two pointers (ld at 0x164cc, 0x164dc) and a third doubleword at 0x164e0, and stores two doublewords (sd at 0x164f4, 0x164f8). The stores are skipped when a7 is zero (beq at 0x164d4) or when a7 is at or below the constant 0x55d4a80 unsigned (beq at 0x164ec). The routine loops back to 0x164c8 while a4 is nonzero (bne at 0x164fc). The stored values are not in the facts, so the name's claim of clearing the PI error is not shown directly.
  Reviewed: 2026-11-12

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** The routine handles four fields of the record at a0 in turn, at +0x18, +0x8, +0x28 and +0x38. Each is tested against zero (beq at 0x16524, 0x16550, 0x1657c, 0x165a8) and skipped when zero. When nonzero, the routine loads a doubleword through a neighbouring field (+0x10, +0x0, +0x20 or +0x30), compares it unsigned against the constant 0x55d4a80 (beq at 0x1653c, 0x16568, 0x16594, 0x165c0), and stores a doubleword back into the tested field only when the loaded value is above the constant (sd at 0x16544, 0x16570, 0x1659c, 0x165c8). Role (from name): clearing MD error state; the stored value is not derived.
  Reviewed: 2026-11-12

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** The routine calls hwgraph_info_get_LBL at 0x19754, then intr_heuristic at 0x197a0 (a1 = 0x0, a2 = -0x1, a3 = 0x4), then intr_connect_level at 0x197d0 with hubii_eint_handler in a3. The facts do not show the label result being passed to intr_heuristic. When the intr_heuristic result equals -1 the branch at 0x197b4 goes to 0x19864, where the cmn_err call at 0x1986c (level 0x14) sits. When intr_connect_level returns a negative value the branch at 0x197d8 goes to 0x1987c; the facts do not show what is there. It stores two doublewords (sd at 0x19824, 0x19844), and calls assfail at 0x19854 and 0x19888 with the constants 0x135 and 0x153. Role (from name): HUB II error interrupt setup; the facts show the call sequence but not the target addresses of the stores.
  Reviewed: 2026-11-12

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** The routine loads from 0x9200000001608008, 0x9200000001600000, 0x92000000010000a0 and 0x9200000001600010. It tests bit masks from the constants 0x3eff000000, 0x30000000, 0x8000000000, 0x10000000000, 0x2000000000, 0x1000000000, 0x800000000, 0x400000000, 0x200000000, 0xf0000000 and 0xf000000 (bne and beq at 0x19de8 through 0x19f24), and calls cmn_err at twelve sites, several of them on a set mask bit. It calls protected_broadcast with 0x67 and 0x68 at 0x19f2c and 0x19f34. Role (from name): an NI error scan; which register is which is inferred from the addresses.
  Reviewed: 2026-11-12

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** The routine calls find_lboard at 0x1a24c (a1 = 0x11) and, when that returns nonzero, find_first_component at 0x1a260 (a1 = 0x2); a zero result from either, or a zero at 0x1a29c, goes to 0x1a2c8 (beq at 0x1a254, 0x1a274, 0x1a29c). It then compares a1 with 0x2, 0x1, 0x3 and 0x4 in that order (beq at 0x1a2a4 through 0x1a2c0) to pick a path. The facts show eight sd stores (0x1a2e4 and later) and four doubleword loads (ld at 0x1a2e8, 0x1a2fc, 0x1a30c, 0x1a31c) spread over those paths, not all taken on one call. Role (from name): saving MD registers; the mapping of a1 values to paths is inferred from the comparisons.
  Reviewed: 2026-11-12

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** The routine indexes the per-node error log through nasid_to_compact_node and kl_error_log (lh at 0x1a63c, ld at 0x1a654), then calls md_err_log_prev at 0x1a688 and, in a loop closed by the bne at 0x1a74c, at 0x1a73c. It calls md_err_log_last at 0x1a84c. It loads a word at 0x1a708 and compares it with 2, 1, 3 and 4 in that order (beq at 0x1a70c through 0x1a724); a value matching none of them falls through to kl_panic at 0x1a730. It returns 0, 1, 2 or 3 (return at 0x1a784). Role (from name): an MD error check; the classes are inferred from the constants.
  Reviewed: 2026-11-12

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** The routine makes five get_nasid calls (0x1aae8, 0x1aaf8, 0x1ab3c, 0x1ab44, 0x1ab4c), then calls find_lboard at 0x1ab8c (a1 = 0x11) and, when that returns nonzero, find_first_component at 0x1aba0 (a1 = 0x2). A zero result from either goes to 0x1ac04 (beq at 0x1ab94, 0x1abb8). When bit 0x1 of a2 is clear the branch at 0x1abd4 goes to 0x1ac1c; when it is set the routine tests a value at 0x1abe0 and may store three doublewords (sd at 0x1abf0, 0x1abf8, 0x1ac00) with a doubleword load at 0x1abfc between them. Role (from name): saving spool registers; the save layout is inferred from the stores.
  Reviewed: 2026-11-12

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** The routine indexes per-CPU data through pdaindr (scaled by 16, with a byte at +0x520) and the node's error log through kl_error_log. It calls splerr at 0x1ac48 and splx on several exits (0x1ae20, 0x1ae80, 0x1ae90, 0x1aea0 and 0x1aec4). It calls klsave_spool_registers at 0x1aeb4 with a2 = 0x2. It compares the doublewords at +6416 and +6432 of the log record the per-CPU byte selects (beq at 0x1acc0 and 0x1ad8c). The address constants 0x9200000001000418, 0x9200000001000420, 0x9200000001000430, 0x9200000001000440, 0x9200000001000448, 0x9200000001000460 and 0x9200000001000468 appear in registers at the splx calls; the facts show no loads from them. Role (from name): returning the next spooled PI error record; what the two compared fields are is not derived.
  Reviewed: 2026-11-12

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** The routine takes a spinlock on a1+796 with mutex_spinlock_spl at 0x1b8fc and releases it with mutex_spinunlock at 0x1ba7c. It calls bte_crb_error_handler at 0x1ba4c and hubiio_crb_free at 0x1ba58, calls sn0_error_dump at 0x1bb08 with a1 = 0x20000000, and calls cmn_err at 0x1bb1c, 0x1bbd0 and 0x1bbf0 and assfail at 0x1bbac (a2 = 0x70c). It compares a6 with 0x1, 0x5, 0x1 and 0x2 (beq and bne at 0x1ba08 through 0x1ba28). A branch at 0x1bac4 sends an unsigned s8 of 0x8 or more to 0x1bb04, and the sn0_error_dump call carries a table reference in a6. The facts show no indirect jump; the per-case roles are not derived, and the locking and cleanup sequence is inferred from the calls.
  Reviewed: 2026-11-12

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** The routine finds the node's error record through nasid_to_compact_node and kl_error_log (lh at 0x1c058, ld at 0x1c06c). It calls ii_llp_error_monitor at 0x1c074 on the record at +8 and ni_llp_error_monitor at 0x1c080 on the record at +32. It calls timeout at 0x1c0a0 with hub_error_count_update itself and the constant 0x64 in a2, but only when the first word of the record is nonzero (beq at 0x1c090). Role (from name): a periodic error monitor; the unit of the timeout is not derived.
  Reviewed: 2026-11-12

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** A branch at 0x1c0d0 (a0 negative) goes to 0x1c120, one at 0x1c0e0 (a6 zero) goes to 0x1c120, and one at 0x1c0ec (compact ID equals -1) goes to 0x1c128; the facts do not show those targets. The only return the facts show is at 0x1c118, with v0 of -1 or 0, reached when the record's first word is nonzero (beq at 0x1c10c not taken). When that word is zero it clears 0x40 bytes of the record with bzero at 0x1c130 and calls timeout at 0x1c150 with hub_error_count_update, a2 = 0x64 and a3 = 0x1, with a 32-bit store at +0x0 (sw at 0x1c154). Role (from name): enabling per-node error counting; the cleared size and the rescheduling are read from the calls.
  Reviewed: 2026-11-12

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** The routine returns -1 when a0 is negative (bltz at 0x1c16c) or when v1 is zero (beq at 0x1c17c). Otherwise it stores a 32-bit word at +0x0 of the node's record (sw at 0x1c1a4) and returns from 0x1c1a8 with -1 or 0, or returns -1 from 0x1c1b0 (beq at 0x1c18c picks the first). The routine makes no call, so it does not cancel the timeout that hub_error_count_enable scheduled; the stored word's meaning is not derived.
  Reviewed: 2026-11-12

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** The routine returns 0 at 0x1c200 when a0 is negative (bltz at 0x1c1c0) or a0 is 0x100 or more (beq at 0x1c1d4). It returns 0 at 0x1c208 when the compact ID is -1 (beq at 0x1c1e0). Otherwise it stores a 32-bit word (sw at 0x1c1ec; the facts do not show its base register) and returns the kl_error_log table entry for the node (the doubleword loaded at 0x1c1f4, returned at 0x1c1f8), not a field read through it. Role (from name): reading the error count; whether the returned value is the count is not derived.
  Reviewed: 2026-11-12

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** The routine reads the error-log entry for the node through kl_error_log (ld at 0x1c608) and the per-CPU record through pdaindr (ld at 0x1c654, lbu at 0x1c658). It calls klerror_global_check at 0x1c678 and error_check_part_page at 0x1c708. Records are indexed by a0 scaled by 32 in the loaded addresses. When register a0 is zero at 0x1c63c it goes to 0x1c768, followed by assfail at 0x1c76c with 0xbe. It calls cmn_err_tag at 0x1c758 with 0xb54 in a0. It returns -1 or 0 at 0x1c69c. Role (from name): a recoverability check; the checks themselves are only partly derived.
  Reviewed: 2026-11-12

- `sn0_skip_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c78c
  **Inferred.** The routine calls dumptlb at 0x1c794 with a0 loaded from the halfword at the address shown as -0x3be0 and a1, a2 and a3 passed through unchanged; another halfword load sits at 0x1c798. The facts show no return and no further call after the dump. Whether the routine falls off the end of its 24 bytes is not settled by the facts; confirm before relying on it.
  Reviewed: 2026-11-12

- `intr_connect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f26c
  **Inferred.** The routine reads per-CPU data through pdaindr (ld at 0x1f3bc, lh at 0x1f3c0 at +0x422) and does a halfword table load at 0x1f3d4 whose table the facts do not name. It calls intr_get_ptrs (the routine at 0x1f210, jal at 0x1f2a0), holds a spinlock with mutex_spinlock_spl at 0x1f2b4 and releases it at 0x1f2f0. It updates a shared word with an ll/sc pair (ll at 0x1f47c, sc at 0x1f484). It calls intr_thread_setup (the routine at 0x21368, jal at 0x1f4e0) with a4 = 0x200 when bit 0x100 of the word loaded at 0x1f468 is set (beq at 0x1f474) and a further nonzero test at 0x1f4bc passes. It returns -1 or 0 at 0x1f304. Role (from name): connecting an interrupt at a level; the level-to-table mapping is inferred.
  Reviewed: 2026-11-12

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** The routine is a 28-byte wrapper: it calls do_intr_block_bit at 0x1f828 with a2 = 0x1 and returns that call's result at 0x1f834. The argument a1 and a3 pass through unchanged. The name suggests blocking an interrupt bit, and the constant 0x1 supports a set-versus-clear flag, but the meaning of the flag is inferred from the name.
  Reviewed: 2026-11-12

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The routine is a 28-byte wrapper: it calls do_intr_block_bit at 0x1f844 with a2 = 0x0 and returns that call's result at 0x1f850. It is the same call as intr_block_bit at 0x1f820 with the flag cleared, so the pair differs only in the constant passed. The name suggests unblocking an interrupt bit; the flag meaning is inferred from the name.
  Reviewed: 2026-11-12

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** The routine loads the doubleword at 0x9200000001000098 (ld at 0x1ff2c) and masks it with the value at [-0x3a68]:8 (beq at 0x1ff4c). It calls ms1bit at 0x1ff84 and uses its result to index a table of 72-byte records. It calls cvsema, valusema and vsema on the address of record +0x20 (calls at 0x1ff5c, 0x1ffd8 and 0x1fff8) and compares the valusema result against hub_intr_wakeup_cnt (beq at 0x1fff0). A word at +0x18 of the record is tested for bit 0x1000 (beq at 0x1ffb0); a doubleword at +0x8 is tested for zero (beq at 0x1ffbc). Calls through an unresolved target at 0x1ffc8 and 0x2005c receive the doubleword at +0x10 as a0 and the entry a0 as a1, so +0x10 is passed as an argument, and the facts do not show which field holds the callee. Role (from name): pending-interrupt dispatch; the table layout is inferred from the scale and offsets.
  Reviewed: 2026-11-12
