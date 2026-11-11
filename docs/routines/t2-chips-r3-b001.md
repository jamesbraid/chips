# Tier-2 routine roles, chips batch 1

Role statements for batch 1 of the tier-2 reading round, targets 26 to 50 of the ranked list. Each statement comes only from the rendered facts for that routine: registers, calls, constants and branch structure in the named binary. Routine names and the purposes they suggest come from symbol names, and each entry says where the reading is a guess.

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** The routine returns at once when a1 is zero (beq at 0x14758). Otherwise it branches on the symbols disable_bte_poison_range and disable_bte and on maxcpus (0x14768, 0x14778, 0x14784) before choosing its path: it calls poison_state_alter_range at 0x14798 with a0 OR'd with 0xa800000000000000 and a2 = 0x1, and calls bte_copy at 0x147e8 with a3 = 0x110 and a4 = 0x4000. It calls poison_state_alter_range again at 0x14840 on the way out. The meaning of the 0xa8 tag and the copy's purpose are not in the facts.

- `bte_wait_for_xfer_completion` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14864
  **Inferred.** The routine loads a pointer from a0 and then the 16-bit field at the low end of the word it points to, branching on whether that field is zero (beq at 0x1487c). It spins in a loop (beq at 0x148a0 back to 0x1488c) whose bound is read from the global block at 0x9200000001030100, using the constant 500 (0x1f4) as an offset. On exhaustion it reports through cmn_err at 0x148c8 with level 0x14 and the constant 0x1f4. The name suggests a transfer wait; which field is polled is inferred from the load shape alone.

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** The routine is a 20-byte leaf: one 8-byte load from the fixed address 0x9200000001600000 at 0x15410, then a return at 0x15418 whose v0 the facts do not tie to that load. It makes no call and no branch. The name suggests a link-state read, but the facts show only a raw doubleword returned, so the bit meaning is not derived.

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** The routine tests the byte at +0x38 of the record at a0 (lbu at 0x16310, beq at 0x16318). When that byte is set it copies three doublewords from +0x8, +0x10 and +0x18 into +0x20, +0x28 and +0x30 (sd at 0x1634c, 0x16350, 0x16354). It stores a byte at +0x39 (sb at 0x1633c and 0x16364) and compares a counter against the constant 0x55d4a80 (beq at 0x16334). The name suggests restoring a saved CPU error record; the direction and purpose of the copy are inferred from the offsets.

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** The routine restores a saved hub error record at a0. Four words at +0x1f8, +0x1e8, +0x208 and +0x218 each gate a block: the block is skipped when the word is zero (beq at 0x16370, 0x16380, 0x1638c, 0x16398), and when it is nonzero the routine loads doublewords from +0x58 through +0x90 (ld at 0x163fc through 0x16494) and stores results into the gate words (sd at 0x1642c, 0x16458, 0x16484, 0x164b0). Bounded loops over pointer fields at +0x70, +0x60, +0x80 and +0x90 compare against the constant 0x55d4a80 (beq at 0x163e4, 0x16420, 0x1644c, 0x16478). Which saved word pairs with which block is inferred from the branch order.

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** The routine loads doublewords through two pointers (ld at 0x164cc, 0x164dc), reads the global at 0x9200000001030100 (ld at 0x164e0), and stores two doublewords (sd at 0x164f4, 0x164f8). It loops while a4 is nonzero (bne at 0x164fc) and tests a7 against the constant bound 0x55d4a80 (beq at 0x164ec). The stored value is not in the facts, so the name's claim of clearing the PI error is not shown directly.

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** The routine walks four field pairs of the record at a0. Each pair is taken only when its gate word at +0x18, +0x8, +0x28 or +0x38 is nonzero (beq at 0x16524, 0x16550, 0x1657c, 0x165a8), and then stores a doubleword back into that field (sd at 0x16544, 0x16570, 0x1659c, 0x165c8). Each gate also compares a counter against the constant 0x55d4a80 (beq at 0x1653c, 0x16568, 0x16594, 0x165c0). The name suggests clearing MD error state; the stored value is not derived.

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** The routine looks up a node's hwgraph label with hwgraph_info_get_LBL at 0x19754 and passes it to intr_heuristic at 0x197a0, then connects hubii_eint_handler with intr_connect_level at 0x197d0. If intr_connect_level returns a negative value (bltz at 0x197d8) it reports through cmn_err at 0x1986c. It stores two doublewords into table entries at 0x9200000001c00128 and 0x9200000001c00138 (sd at 0x19824, 0x19844), and calls assfail at 0x19854 and 0x19888 with the constants 0x135 and 0x153. The name suggests a HUB II error interrupt setup, which the call sequence supports.

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** The routine reads the NI error registers at 0x9200000001608008, 0x9200000001600000, 0x92000000010000a0, 0x9200000001600010 and 0x9200000001608088. It tests bit masks from the constants 0x3eff000000, 0x30000000, 0x8000000000, 0x10000000000, 0x2000000000, 0x1000000000, 0x800000000, 0x400000000, 0x200000000, 0xf0000000 and 0xf000000 (bne and beq at 0x19de8 through 0x19f24), and reports each set bit through cmn_err. It calls protected_broadcast with 0x67 and 0x68 at 0x19f2c and 0x19f34. The name suggests an NI error scan; which register is which is inferred from the addresses.

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** The routine finds a board record with find_lboard at 0x1a24c (type 0x11) and then a component with find_first_component at 0x1a260 (type 0x2). It selects a save path from the argument a1 compared with 0x2, 0x1, 0x3 and 0x4 (beq at 0x1a2a4 through 0x1a2c0), and stores eight doublewords into the save area (sd at 0x1a2e4 and later). It reads the global at 0x9200000001030100 four times (ld at 0x1a2e8 and later). The name suggests saving MD registers; the mapping of a1 to save paths is inferred from the comparisons.

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** The routine indexes the per-node error log through nasid_to_compact_node (lh at 0x1a63c, ld at 0x1a654), then walks entries calling md_err_log_prev at 0x1a688 and md_err_log_last at 0x1a84c. It dispatches on a value compared with 2, 1, 3 and 4 (beq at 0x1a70c through 0x1a724) and returns a 0-3 code (return at 0x1a784). It calls kl_panic at 0x1a730 with the constant 0x2 on one path whose condition is not derived. The name suggests an MD error check; the classes are inferred from the constants.

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** The routine gets the node ID with get_nasid (calls at 0x1aae8 through 0x1ab4c), then finds a board record with find_lboard at 0x1ab8c (type 0x11) and a component with find_first_component at 0x1aba0 (type 0x2). It loads the global at 0x9200000001030100 (ld at 0x1abfc) and stores three doublewords into the save area (sd at 0x1abf0 through 0x1ac00). A flag bit 0x1 of a2 selects an extra path (beq at 0x1abd4). The name suggests saving spool registers; the save layout is inferred from the stores.

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** The routine indexes per-CPU data through pdaindr (scaled by 16, with a byte flag at +0x520) and the node's error log through kl_error_log, then takes a spl level with splerr at 0x1ac48 and restores it with splx at 0x1ae20, 0x1ae80, 0x1ae90, 0x1aea0 and 0x1aec4. It calls klsave_spool_registers at 0x1aeb4 with the constant 0x2. It reads spool-pointer words at 0x9200000001000418 through 0x9200000001000468 and branches on whether the entry matches (beq at 0x1ad8c). The name suggests returning the next spooled PI error record; the pointer roles are inferred.

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** The routine takes a spinlock on a1+796 with mutex_spinlock_spl at 0x1b8fc and releases it with mutex_spinunlock at 0x1ba7c. It calls bte_crb_error_handler at 0x1ba4c and hubiio_crb_free at 0x1ba58, dumps through sn0_error_dump at 0x1bb08, and reports through cmn_err at 0x1bb1c, 0x1bbd0 and 0x1bbf0. It dispatches on the value at a6 compared with 0x1, 0x5 and 0x2 (beq and bne at 0x1ba08 through 0x1ba28), and uses an indirect jump at 0x1bad0 through a jump table whose targets are unresolved. The per-case roles are not derived; the locking and cleanup sequence is inferred from the calls.

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** The routine finds the node's error record through nasid_to_compact_node and kl_error_log (lh at 0x1c058, ld at 0x1c06c). It calls ii_llp_error_monitor at 0x1c074 on the record at +8 and ni_llp_error_monitor at 0x1c080 on the record at +32. It re-arms itself with timeout at 0x1c0a0 using the constant 0x64 (100 ticks), but only when the first word of the record is nonzero (beq at 0x1c090). The name suggests a periodic error monitor; the rescheduling condition is read from the branch.

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** It takes an early exit to a return of -1 or 0 at 0x1c118 when a0 is negative (bltz at 0x1c0d0) or the node's compact ID is -1 (beq at 0x1c0ec). Otherwise it clears 0x40 bytes of the node's record with bzero at 0x1c130 and stores a 32-bit word at +0x0 (sw at 0x1c154). It schedules hub_error_count_update with timeout at 0x1c150 using 0x64 ticks and a3 = 0x1. The name suggests enabling per-node error counting; the cleared size and the rescheduling are read from the calls.

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** The routine returns -1 when a0 is negative (bltz at 0x1c16c) or when v1 is zero (beq at 0x1c17c). Otherwise it stores a 32-bit word at +0x0 of the node's record (sw at 0x1c1a4) and returns from 0x1c1a8 with -1 or 0, or returns -1 from 0x1c1b0 (beq at 0x1c18c picks the first). The routine makes no call, so it does not cancel the timeout that hub_error_count_enable scheduled; the stored word's meaning is not derived.

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** The routine rejects a negative node index (bltz at 0x1c1c0) and an index of 0x100 or more (beq at 0x1c1d4), returning 0 at 0x1c200. For a valid node it stores a 32-bit word to the pointer in a1 (sw at 0x1c1ec) and returns the first doubleword of the node's record at 0x1c1f8, or 0 at 0x1c208 when the compact ID is -1. The name suggests reading the error count; which field is the count is not derived from the facts.

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** The routine reads the error-log entry for the node through kl_error_log (ld at 0x1c608) and the per-CPU record through pdaindr (ld at 0x1c654, lbu at 0x1c658). It calls klerror_global_check at 0x1c678 and error_check_part_page at 0x1c708, and walks records of 32 bytes indexed by a0 (shift by 5 at 0x1c6a4 and later). It calls assfail at 0x1c76c with 0xbe when a0 is zero (beq at 0x1c63c), and cmn_err_tag at 0x1c758 with 0xb54. It returns -1 or 0 at 0x1c69c. The name suggests a recoverability check; the checks themselves are only partly derived.

- `sn0_skip_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c78c
  **Inferred.** The routine calls dumptlb at 0x1c794 with a0 taken from the halfword at gp-relative -0x3be0, passing a1 to a3 through; a halfword load from abs 0xffffffffffffc420 sits in the delay slot at 0x1c798. The next instruction at 0x1c79c is a branch to itself that is always taken, so as decoded the routine does not return after the dump. Whether that is a deliberate spin or a decoding artifact is not settled by the facts; confirm before relying on it.

- `intr_connect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f26c
  **Inferred.** The routine reads per-CPU data through pdaindr (ld at 0x1f3bc, lh at 0x1f3c0 at +0x422) and maps a compact node to a NASID through compact_to_nasid_node (lh at 0x1f3d4). It fetches interrupt pointers with an indirect call through the table at 0x1f210 (jal at 0x1f2a0) and holds a spinlock with mutex_spinlock_spl at 0x1f2b4, releasing it at 0x1f2f0. It updates a shared word with an ll/sc pair (ll at 0x1f47c, sc at 0x1f484) and calls intr_thread_setup through the table at 0x21368 with a4 = 0x200 when the flag bit 0x100 of a2 is set (beq at 0x1f474). It returns -1 or 0 at 0x1f304. The name suggests connecting an interrupt at a level; the level-to-table mapping is inferred.

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** The routine is a 28-byte wrapper: it calls do_intr_block_bit at 0x1f828 with a2 = 0x1 and returns that call's result at 0x1f834. The argument a1 and a3 pass through unchanged. The name suggests blocking an interrupt bit, and the constant 0x1 supports a set-versus-clear flag, but the meaning of the flag is inferred from the name.

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The routine is a 28-byte wrapper: it calls do_intr_block_bit at 0x1f844 with a2 = 0x0 and returns that call's result at 0x1f850. It is the same call as intr_block_bit at 0x1f820 with the flag cleared, so the pair differs only in the constant passed. The name suggests unblocking an interrupt bit; the flag meaning is inferred from the name.

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** The routine loads a pending-interrupt word at 0x9200000001000098 (ld at 0x1ff2c) and masks it with the value at [-0x3a68]:8 (beq at 0x1ff4c). It finds the highest set bit with the function ms1bit at 0x1ff84 and uses it to index a table of 72-byte records (the scale at 0x1ffa4 is x*72). Each record carries a semaphore at +0x20 manipulated by cvsema, valusema and vsema (calls at 0x1ff5c, 0x1ffd8 and 0x1fff8), a wakeup count compared at 0x1fff0 against hub_intr_wakeup_cnt, and a function pointer at +0x10 called indirectly at 0x1ffc8 and 0x2005c whose target is not in the symbol table. The name suggests interrupt pending dispatch; the table layout is inferred from the scale and offsets.
