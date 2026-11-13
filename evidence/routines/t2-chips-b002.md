# Tier-2 reading, batch 2 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: branches, loads and stores, calls and constants. No role here is settled outright by the facts, so each is inferred, and the open points are stated.

- `bte_unaligned_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x144a0
  **Inferred.** Role (from name): a block copy that chooses between the BTE path and plain `bcopy`. It reads the `disable_bte` and `maxcpus` globals (0x144cc, 0x144dc), calls `bte_pull` (0x1452c, 0x14560, 0x145fc) and `bte_copy` (0x14650, 0x146a4), and calls `bcopy` (0x145ac, 0x1461c, 0x1467c). It compares `a2` against 0x80 (0x14664) and a value against 0x7fff80 (0x14640); the other operand of the 0x7fff80 compare is not resolved. Which pieces count as unaligned, and what the 0x7fff80 limit means, are not settled by these facts.
  Reviewed: 2026-11-12

- `bte_poison_copy` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x146f4
  **Inferred.** A wrapper around `bte_copy` (0x14708) that passes the fixed value 0x110 as its fourth argument. A non-zero result from `bte_copy` branches to the `cmn_err` report at 0x14738 with level 0xc and the copy result as an argument. The meaning of 0x110 is not established.
  Reviewed: 2026-11-12

- `bte_poison_range` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14748
  **Inferred.** Works over a range by calling `poison_state_alter_range` (0x14798, 0x14840) and `bte_copy` (0x147e8, passing the constants 0x110 in `a3` and 0x4000 in `a4`). The globals `disable_bte_poison_range` and `disable_bte` are tested before the copy path (0x14768, 0x14778). The branch at 0x147fc goes back to the test at 0x147b8 when `bte_copy` returns zero, so the call sits in a loop that continues on a zero result, and a non-zero result leaves the loop. What the poison state is, and the meaning of 0x110 and 0x4000, are not established.
  Reviewed: 2026-11-12

- `bte_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14858
  **Inferred.** Role (from name): disables use of the BTE. The rendered facts show only a return at 0x1485c, with no call, load or store visible in them, and the return value is not computed from anything in the facts. The facts are too thin to say whether the routine is a stub, and which disable it performs is not established.
  Reviewed: 2026-11-12

- `bte_wait_for_xfer_completion` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x14864
  **Inferred.** A bounded poll of a BTE control record passed in `a0`. It reads the 8-byte word at `a0` and the 8-byte word that one points to (0x14868, 0x14870), tests the low 16 bits of the latter for zero (0x1487c, 0x1488c), and reads the hub register at 0x9200000001030100 twice (0x1486c, 0x14898). The first value plus 500 is compared with the second read, and the loop branches back to the zero test (0x148a0 to 0x1488c) while that sum is at least the second read (unsigned). The timeout report at 0x148c8 passes 0x1f4 (500) to `cmn_err` at level 0x14. The exact completion bit and what the register counts are not established.
  Reviewed: 2026-11-12

- `net_link_up` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1540c
  **Inferred.** Reads one 8-byte word at the fixed address 0x9200000001600000 (0x15410); the facts leave its return value unresolved. `check_ni_errors` reads the same address (0x19dec), which suggests a network-interface status register. The bit that means link up, and how the return value is derived from the word, are not established.
  Reviewed: 2026-11-12

- `restore_cpu_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16310
  **Inferred.** Moves fields inside the error record passed in `a0`. It loads a flag byte at +0x38 and, when that is zero, returns at once (0x16318 to 0x16358) with no store. Otherwise it loads two words (0x16324, 0x16328) and compares a value against 0x55d4a80 (0x16334). When that value is below the bound it stores a byte at +0x39 (0x1633c), loads the words at +0x18, +0x10 and +0x8, and stores to +0x20, +0x28 and +0x30 (0x16340 to 0x16354). Otherwise it stores a byte at +0x39 (0x16364) and returns without the word stores. The stored byte values are not shown. Whether this restores or saves CPU error state is not established.
  Reviewed: 2026-11-12

- `restore_hub_err` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x16368
  **Inferred.** Works over the record at `a0` in four similar steps, with a loop (0x163b8 branches back to 0x163a4). It tests the words at +0x1f8, +0x1e8, +0x208 and +0x218, and the words at +0x70, +0x60, +0x80 and +0x90, for zero. It also loads the words at +0x68, +0x58, +0x78 and +0x88 and compares a loaded value against the 0x55d4a80 bound (0x163e4 to 0x164a4), and it stores to +0x1f8, +0x1e8, +0x208 and +0x218 (0x1642c, 0x16458, 0x16484, 0x164b0). The stored values are not shown. The value returned is the word at +0x1e8 (0x163c0). The meaning of each field, and whether this restores or saves, are not established.
  Reviewed: 2026-11-12

- `clear_hub_pi_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x164b4
  **Inferred.** A loop (0x164fc branches back to 0x164c8). Each pass loads a word (0x164cc) and tests it for zero (0x164d4), loads two more words (0x164dc, 0x164e0) and compares a value against 0x55d4a80 (0x164ec). When both tests pass it stores to two 8-byte fields (0x164f4, 0x164f8). The stored values and the return value are not shown by the facts. The name suggests it clears PI error state, but which error fields it clears is not established.
  Reviewed: 2026-11-12

- `clear_hub_md_error` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1650c
  **Inferred.** Handles four slots of the record at `a0` (+0x8, +0x18, +0x28, +0x38). For each it tests the word at that offset for zero (0x16524, 0x16550, 0x1657c, 0x165a8), loads the word 8 below it and a second word, compares a value against 0x55d4a80, and stores to the slot (0x16544, 0x16570, 0x1659c, 0x165c8) when both tests pass. The stored values are not shown by the facts. The name suggests it clears memory-directory error latches, but the register meanings are not established.
  Reviewed: 2026-11-12

- `hubii_eint_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19714
  **Inferred.** Role (from name): sets up the hub II error interrupt for one node. It loads halfwords at 0x197fc and 0x19804, calls `hwgraph_info_get_LBL` (0x19754) and `intr_heuristic` (0x197a0), and calls `intr_connect_level` (0x197d0) with `hubii_eint_handler` as its fourth argument. Failure paths call `cmn_err` (0x1986c) and `assfail`, which receives 0x135 (0x19854) and 0x153 (0x19888) as its third argument. Two 8-byte stores (0x19824, 0x19844) write to addresses the facts do not resolve, and what they hold is not established.
  Reviewed: 2026-11-12

- `check_ni_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x19dc0
  **Inferred.** Role (from name): scans network-interface status words. The facts show loads from fixed addresses 0x9200000001608008 (0x19dd0), 0x9200000001600000 (0x19dec), 0x9200000001600010 (0x19e60, 0x19f48) and 0x92000000010000a0 (0x19e14, 0x19e24), tested against bit masks, and further loads at 0x19e88 and 0x19f70 whose addresses are not resolved. Several mask hits call `cmn_err` (levels 0x14 and 0x15, 0x19e7c to 0x1a00c). `protected_broadcast` is called twice in a row, with 0x67 and then 0x68 (0x19f2c, 0x19f34), reached by falling through the last mask test at 0x19f24. The bit each mask stands for, such as 0x3eff000000 or 0xf0000000, is not established.
  Reviewed: 2026-11-12

- `hubni_eint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1a4
  **Inferred.** A thin interrupt entry that calls `hubni_error_handler` (0x1a1b4) with flag 1, passes its own a2 and a3 through, and returns the callee's result. The flag is probably the local-versus-remote choice, which the twin entry below suggests but the facts do not show.
  Reviewed: 2026-11-12

- `hubni_rmteint_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1c8
  **Inferred.** Role (from name): the remote-interrupt twin of `hubni_eint_handler`. It calls `hubni_error_handler` (0x1a1d8) with flag 0 and returns its result. The two entries differ only in that flag.
  Reviewed: 2026-11-12

- `klsave_md_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a1ec
  **Inferred.** Calls `find_lboard` (type 0x11, 0x1a24c), then `find_first_component` (class 2, 0x1a260) on its result. It loads a word at +0x48 (0x1a20c) and passes its own `a2` through to `find_lboard`. It then compares `a1` with 2, 1, 3 and 4 (0x1a2a4 to 0x1a2c0) and stores 8-byte words on the path each match selects (0x1a2e4 to 0x1a324). The stored register set and the meaning of those four values are not established.
  Reviewed: 2026-11-12

- `check_md_errors` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1a618
  **Inferred.** Role (from name): walks memory-directory error entries for one node, starting from the `kl_error_log` slot selected through `nasid_to_compact_node` (0x1a63c, 0x1a654). It calls `md_err_log_prev` (0x1a688, and 0x1a73c in a loop closed by the branch at 0x1a74c) and `md_err_log_last` (0x1a84c), and calls `kl_panic` (0x1a730) on one path. The four type values it compares against (0x1a70c to 0x1a724) and the panic condition are not established.
  Reviewed: 2026-11-12

- `klsave_spool_registers` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1aac4
  **Inferred.** Role (from name): saves a spool-register set. It calls `get_nasid` five times (0x1aae8 to 0x1ab4c) and does the same board and component lookup as `klsave_md_registers` (`find_lboard` with type 0x11 at 0x1ab8c, `find_first_component` with class 2 at 0x1aba0). It reads a word at +0x48 of an address the facts do not resolve (0x1ab1c, 0x1ab64) and writes three 8-byte words (0x1abf0 to 0x1ac00). The contents of those words, how the `get_nasid` results are used, and the flag tested at 0x1abd4 are not established.
  Reviewed: 2026-11-12

- `hubpi_spool_get_next` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ac2c
  **Inferred.** Role (from name): fetches the next pending spool entry for a node. It loads fields at +0x1910, +0x1920 and +0x1930 of the node's `kl_error_log` record, stores to +0x1920 and +0x1910 (0x1ad44, 0x1add8), and stores 8-byte words through pointers whose base the facts do not resolve (0x1accc, 0x1acf8, 0x1ada0, 0x1ae7c). It brackets the work with `splerr` and `splx` (0x1ac48, 0x1ae20 to 0x1aec4) and calls `klsave_spool_registers` with `a2` = 2 on one path (0x1aeb4). The ring layout and the flag bytes read at +0x520 are not established.
  Reviewed: 2026-11-12

- `hubiio_crb_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1b8b0
  **Inferred.** Role (from name): an error handler for a hub I/O CRB error. It takes the lock at `a1+796` with `mutex_spinlock_spl` (0x1b8fc), then compares unresolved values with 1, 5, 1 and 2 (0x1ba08 to 0x1ba28). After a bound check on a value below 8 (0x1bac4) it makes a table load (0x1bacc) whose use the facts do not resolve. It calls `bte_crb_error_handler` (0x1ba4c), `hubiio_crb_free` (0x1ba58), `mutex_spinunlock` (0x1ba7c) and `sn0_error_dump` (0x1bb08), and calls `cmn_err` and `assfail` (0x70c as its third argument). Which comparison reaches which handler is not established.
  Reviewed: 2026-11-12

- `hub_error_count_update` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c040
  **Inferred.** A periodic monitor for one node. It reads the node's `kl_error_log` record (0x1c058 to 0x1c08c), calls `ii_llp_error_monitor` on the record at +8 (0x1c074) and `ni_llp_error_monitor` on the record at +32 (0x1c080), and re-arms itself with `timeout` at 0x64 (0x1c0a0) when a word it loaded is non-zero (0x1c090). The unit of the 0x64 interval is not established.
  Reviewed: 2026-11-12

- `hub_error_count_enable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c0b8
  **Inferred.** Role (from name): turns on the error count for one node. It reaches a return of -1 for a negative node index (0x1c0d0), reads the node's `kl_error_log` slot (0x1c0e8 to 0x1c10c), calls `bzero` with 0x40 as its second argument on one branch (0x1c130), stores a 4-byte word (0x1c154), and calls `timeout` with `hub_error_count_update` as its first argument and 0x64 as its third (0x1c150). The value stored and the other `timeout` arguments are not established.
  Reviewed: 2026-11-12

- `hub_error_count_disable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c164
  **Inferred.** The disable side of the same per-node counter. It goes to a return of -1 for a negative index (0x1c16c) and at a second early exit whose condition the facts show only as `v1 == 0` (0x1c17c). When the slot word equals -1 (0x1c18c) it skips the store and goes to the return at 0x1c1a8, which the facts show yielding -1 or 0 without saying which belongs to this path. Otherwise it stores a 4-byte word (0x1c1a4). The stored value is not shown, and nothing here cancels the armed `timeout`, so whether it is cancelled elsewhere is not established.
  Reviewed: 2026-11-12

- `hub_error_count_get` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c1b8
  **Inferred.** Role (from name): reads the node's error count. It returns 0 for a negative index and for an index of 0x100 or more (0x1c1c0, 0x1c1d4), stores a 4-byte word (0x1c1ec), and returns the 8-byte value from the node's `kl_error_log` slot (0x1c1f8). What the 0x100 bound limits and the meaning of the returned value are not established.
  Reviewed: 2026-11-12

- `klerror_check_recoverable` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c5ec
  **Inferred.** Role (from name): decides whether a saved error record for the current processor can be recovered. It reads the per-processor data area through `pdaindr` (0x1c654, flag byte at +0x520 read at 0x1c658) and the node's `kl_error_log` slot (0x1c608). It calls `klerror_global_check` (0x1c678) and `error_check_part_page` (0x1c708). It reads the byte at +0x1810 of the selected record, and stores to +0x1811, +0x1818, +0x1820 and +0x1828 in that record (0x1c704 to 0x1c738). It also calls `cmn_err_tag` (0x1c758, with 0xb54 and 0x14 as its first two arguments) and `assfail` (0x1c76c, with 0xbe as its third). The meaning of the fields and of the flag is not established.
  Reviewed: 2026-11-12

- `sn0_skip_dump` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1c78c
  **Inferred.** Calls `dumptlb` (0x1c794) with the halfword at -0x3be0 as its argument, the same halfword that indexes `pdaindr` in `hubpi_spool_get_next` and `klerror_check_recoverable`, and then branches to itself at 0x1c79c with no exit. The facts show no return after the call, so this is either an intentional halt after the TLB dump or a gap in the rendered facts. Which of the two it is, is not established.
  Reviewed: 2026-11-12
