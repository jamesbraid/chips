# Tier-2 reading, batch 3 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls, branches and constants. Every role is inferred. The facts do not settle what the fields, bits or callees mean, and each entry says where that stays open.

- `intr_connect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f26c
  **Inferred.** It calls `intr_get_ptrs` (0x1f210, from 0x1f2a0) and then `mutex_spinlock_spl` (0x1f2b4). A branch on bit 0x2 of a1 (0x1f2e4) and one on a1 being zero (0x1f30c) lead to `mutex_spinunlock` (0x1f2f0) and a return of -1 or 0. Later it does an `ll`/`sc` loop on a word (0x1f47c, 0x1f484), reached only when bit 0x100 of a loaded word is set (0x1f474). It calls `intr_thread_setup` with a4 = 0x200 (0x1f4e0) when a loaded word is nonzero (0x1f4bc); that call's a1 is built from `pdaindr` indexed by `a0 << 4`. The facts do not show where the lock is released after the `ll`/`sc` update, what the word holds, or what the level number means.
  Reviewed: 2026-11-12 (sonnet)

- `intr_disconnect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f508
  **Inferred.** It follows the same opening as `intr_connect_level`: `intr_get_ptrs` (0x1f52c), then `mutex_spinlock_spl` (0x1f540). It compares a2 against the constant 0x3 at 0x1f570 and, when they differ, calls `mutex_spinunlock` (0x1f578) and returns -1 or 0. Further on it does a series of stores and loads, ending in a doubleword store at 0x1f6a4. The facts do not give that store's target address, and show no loop around it. Which entry the routine clears is not established.
  Reviewed: 2026-11-12 (sonnet)

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** A 28-byte wrapper that passes its arguments to `do_intr_block_bit` (0x1f828) with a2 set to the constant 0x1, and returns that result. The flag value is read as "block" from the name, not from the callee.
  Reviewed: 2026-11-12 (sonnet)

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The sibling of `intr_block_bit`: the same 28-byte wrapper around `do_intr_block_bit` (0x1f844), with the constant 0x0 in place of 0x1. The pairing with the block routine is inferred from the names and the flag values.
  Reviewed: 2026-11-12 (sonnet)

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** It reads a hub pending word at the fixed address 0x9200000001000098 and loops while the result ANDed with a stored mask is nonzero (0x20014). It finds a set bit through `ms1bit` (0x1ff84), which by its name returns the most significant one, indexes a 72-byte record table by that bit number (the `x * 9 * 8` scaling at 0x1ffa4), and calls the semaphore routines `cvsema`, `valusema` and `vsema` on the record at +32 (0x1ff5c, 0x1ffd8, 0x1fff8). It calls through a function pointer stored at record +16 (0x1ffc8, 0x2005c) on conditional paths: the call at 0x1ffc8 requires the word at record +8 to be nonzero, and the branch at 0x1ffb0 sends the case where bit 0x1000 of the word at record +24 is clear to the call at 0x2005c. Which bit is taken first and what the record fields mean is not established here.
  Reviewed: 2026-11-12 (sonnet)

- `cpuintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20508
  **Inferred.** It loads a halfword (0x20524) and then record fields at +0x8 and +0x520 (0x20534, 0x2053c); the facts do not name the source of the halfword. Unless the branches at 0x20554 or 0x2055c skip it, it copies 0x168 bytes with `bcopy` (0x205ac). It then runs `doacvec` and `doactions` (0x205b4, 0x205bc). When bit 0x20 of a loaded word is clear (0x205cc) it returns `doactions`'s result; otherwise it logs timestamp events 0x71 and 0x65 with `log_tstamp_event` (0x205f0, 0x2060c). It also does a doubleword store (0x20548); the facts give neither its address nor the address of the load at 0x205c4. The vector and action callees may be the dispatch step, which is a guess from their names. The exact dispatch order is open.
  Reviewed: 2026-11-12 (sonnet)

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** It loads the halfword at `-0x3be0` and a record through `pdaindr` (the facts show the index in the argument expression for `debug`), does a doubleword store (0x206ac), and does a load (0x206b8). The facts give neither address; 0x9200000001000090 appears as the third argument to `debug`. It calls `debug` (0x206b4) with a constant string address (`.rodata+32520`), a byte from the record at +1312 plus 118, and 0x9200000001000090, and returns its result. Its role as a debug entry follows from the name and the `debug` callee, not from any body in this read.
  Reviewed: 2026-11-12 (sonnet)

- `tlbintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20778
  **Inferred.** It follows the `dbgintr` shape: a halfword load (0x20778), record loads at +0x8 and +0x520 (0x20790, 0x20798), a doubleword store (0x207a4) and a load (0x207ac); the facts give no addresses for them. It calls `tlbflush_rand` (0x207a8) with its own four arguments and returns that result. The name suggests a TLB-flush handler, but the facts show only the call, not the flush itself.
  Reviewed: 2026-11-12 (sonnet)

- `chkdebug` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20974
  **Inferred.** It does a halfword load (0x20974), record loads at +0x8 and +0x520, and loads the doubleword at 0x92000000010000a0. It calls `dbgintr` (0x209b0) with a0 = 0 only when that word ANDed with a loaded value is nonzero (the branch at 0x209a8); the facts do not resolve where that value comes from. Otherwise it returns without the call. The word at 0x92000000010000a0 is a flag by name, which the facts do not confirm.
  Reviewed: 2026-11-12 (sonnet)

- `hub_migrintr_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20a2c
  **Inferred.** It calls `cnodetocpu` (0x20a34) and then `intr_connect_level` (0x20a68) with a1 = 3, a2 = 0, `migr_intr_handler` in a3 and `migr_intr_prologue_handler` in a5. It skips that connect when `numnodes` is 1 (0x20a4c) or when a0 equals -1 (0x20a54); the facts do not show that a0 holds the `cnodetocpu` result. When `intr_connect_level` returns nonzero it calls `cmn_err` (0x20a88). That the routine sets up the migration interrupt is inferred from the handler names.
  Reviewed: 2026-11-12 (sonnet)

- `intr_dumpvec` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20f58
  **Inferred.** It checks its a0 argument against 0 and against `numnodes` (0x20f90, 0x20fa8) and goes to a separate path when a0 is out of range. It also goes to a separate path when the `compact_to_nasid_node` entry for a0 is -1 (0x20fb4); that path makes the unresolved indirect calls at 0x211a8 and 0x21190 with the table symbol or entry as arguments, and the routine does not silently skip it. On the in-range path it reads words through the table pointed to by `-0x3c00` (loads at 0x21058 to 0x21088), calls `dump_vector` (0x210d0), and loops with counters compared against 0x2 (0x21134) and 0x40 (0x210e0). It makes several indirect calls with a constant format string at `.rodata+32520` (0x21050 to 0x211a8). The printed field names are open, because the indirect callees are not resolved here.
  Reviewed: 2026-11-12 (sonnet)

- `bte_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21994
  **Inferred.** It takes an error record in a0, reads its node-table pointer at +8, and branches on the halfword at +16 against the cases 1, 2, 3, 6 and 7 (0x21ad0 to 0x21af0), then against 0 (0x21af8). It calls `hubiio_crb_error_handler` (0x219f0) for the node and `mutex_spinlock_spl` (0x21a0c, with `splerr` in an argument slot) and `mutex_spinunlock` (0x21a94). Between them it does doubleword stores; the facts name only the addresses 0x9200000001c00000 and 0x9200000001c001f8 as arguments to the unlock. A path for a halfword value outside the listed cases calls `cmn_err` at level 12 (0x21b58). It returns one of 2 to 7. The meaning of each error code is not established by these facts.
  Reviewed: 2026-11-12 (sonnet)

- `bte_stall_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21c9c
  **Inferred.** It calls `verify_snchip_rev` and branches on its result against 5 (0x21cbc); when it is 5 or more it goes to 0x21cf0. It does an `lld`/`scd` loop (0x21cd4, 0x21cdc) and tests `bte_stall_node_mask` ANDed with a value (0x21cec); the facts do not give the loop's target address and one early path returns. It allocates with `kmem_alloc_node` (0x21d14, a0 = 0x200, so likely a 512-byte buffer) and frees it with `kmem_free` (0x22030, size 0x200). It calls `us_delay` with 1 (0x21de4, in a loop), 10 (0x21dfc) and 1 (0x21e48, in a loop), and on one path calls `bte_error_handler` (0x21fd0) inside a loop. The facts do not identify the registers it programs and reads; the intent of the stall is open.
  Reviewed: 2026-11-12 (sonnet)

- `bte_bpush_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2204c
  **Inferred.** It does nothing further when `bpush_war_enable` is zero (the branch at 0x22068 goes to 0x22078) and otherwise calls `get_hub_chiprev` (0x22098) with a halfword loaded from `compact_to_nasid_node`. It branches on the result against 5 (0x220b0; 5 or more goes to 0x220cc). The branch at 0x220bc jumps to `rt_pin_thread` (0x220d4) when `bte_stall_node_mask` ANDed with a value is zero, so the pin call is on the bit-clear path, not the bit-set path. After `rt_pin_thread` a chain of comparisons (0x220fc to 0x22148) can jump straight to `bte_stall_node` (0x22160); the fall-through path reaches `rt_unpin_thread` (0x22150) first, and `bte_stall_node` (0x22160) follows it. The hardware problem the workaround addresses is not in these facts, so the name is the only hint.
  Reviewed: 2026-11-12 (sonnet)

- `hub_piomap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22420
  **Inferred.** It finds the widget's id and master through `xwidget_info_get`, `xwidget_info_id_get` and `xwidget_info_master_get` (0x22450 to 0x2246c), and it searches a mapping table under `mutex_spinlock` (0x22548, released at 0x225c8, 0x2262c and 0x226f4). It checks the request against the limits 0x1000000 (0x224d0) and 0x20000000 (0x2252c), and it waits on a sync object with `sv_wait` (0x2270c, argument 0x19) on one path. The table layout and the wait condition are open here.
  Reviewed: 2026-11-12 (sonnet)

- `hub_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2288c
  **Inferred.** It looks up the same widget records as `hub_piomap_alloc` (0x228a8 to 0x228d0) and then calls `hub_piomap_addr` (0x22914). It checks whether the request's end, a2 plus a3, is above 0x1000000 (0x228e4) and tests bit 0x8 of a4 (0x22928) to choose the path. The translation rule itself is in `hub_piomap_addr`, which this read does not cover.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dmamap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22958
  **Inferred.** It looks up the widget through `xwidget_info_get`, `xwidget_info_id_get` and `xwidget_info_master_get` (0x22968 to 0x22980). It allocates a 16-byte record with `kern_malloc` (0x22990) and stores words at +0x0, +0xc and +0x8 (0x2299c to 0x229b0). When bit 0x1 of a3 is set (the branch at 0x229c0) it also stores a byte at +0x4 and a word at +0xc again (0x229c4, 0x229c8). It returns the record pointer. The field meanings are not named by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x229d8
  **Inferred.** It loads the word at +0xc of its argument (0x229dc), stores a word at +0xc (0x229f0) and calls `kern_free` with the same arguments (0x229ec), returning its result. The pairing with `hub_dmamap_alloc`, which allocates a 16-byte record, is from the names and the shared +0xc field. The value stored at +0xc is not derived here.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dmamap_addr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a00
  **Inferred.** It reads and writes the word at +0xc of its argument record and tests bit 0x2 of that word (0x22a18). On one path it reports through `cmn_err` at level 4 with the word at +0 and the word at +12 ORed with 0x2 (0x22a48), and it returns its second argument. The address computation is not in this routine's facts.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a5c
  **Inferred.** It has the same shape as `hub_dmamap_addr`: the same +0xc read-modify-write, the bit 0x2 test (0x22a74) and the level-4 `cmn_err` report (0x22aa4), with the same format-string address (`.rodata+34128`). It returns its second argument on the path that returns without the report. Whether it lists or copies map entries is not established by these facts.
  Reviewed: 2026-11-12 (sonnet)

- `hub_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ab8
  **Inferred.** It reads and writes the +0xc word of its argument and tests bit 0x2 of that word (0x22ad0). It tests a3 and, on one path, reports through `cmn_err` at level 4 with a constant -3 (0x22af8). The completion meaning follows from the name and the shared shape, not from the body.
  Reviewed: 2026-11-12 (sonnet)

- `hub_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e3c
  **Inferred.** A 28-byte wrapper that calls `do_hub_intr_alloc` (entry at 0x22b8c, called from 0x22e44) with a3 set to the constant 0x0, and returns its result. Its counterpart `hub_intr_alloc_nothd` passes 0x1 instead, so the flag is read as a thread-related choice from the name.
  Reviewed: 2026-11-12 (sonnet)

- `hub_intr_alloc_nothd` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e58
  **Inferred.** The same 28-byte wrapper as `hub_intr_alloc`, calling `do_hub_intr_alloc` (entry at 0x22b8c, called from 0x22e60) with the constant 0x1 in a3. The name suggests the no-thread variant of interrupt allocation, but the facts show only the flag value.
  Reviewed: 2026-11-12 (sonnet)

- `hub_intr_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e74
  **Inferred.** It reads the record fields at +0x24, +0x28 and +0x2c, clears the byte at +0x5, and writes +0x0 and +0x8 (0x22ea0 to 0x22eac). It calls `hub_intr_disconnect` (0x22eb0), frees the 48-byte record with `kmem_free` (0x22ec8, size 0x30), and calls `intr_unreserve_level` with the halfword at +36 and the word at +40 (0x22ed8). Bits 0x4 and 0x1 of the word at +44 select the paths (0x22e98, 0x22ec0).
  Reviewed: 2026-11-12 (sonnet)

- `hub_intr_connect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22eec
  **Inferred.** It reads the halfword at +0x24 and the words at +0x20 and +0x28, and calls `intr_connect_level` (0x22f24) with those fields and a5 set to 0. A negative result branches to 0x22f50 (0x22f2c); otherwise the routine stores at +0x18 and +0x10 and a word at +0x2c (0x22f4c). The facts do not show what is stored at +0x2c. It returns either the `intr_connect_level` result or 0. When a3 is nonzero it makes an indirect call (0x22f64) whose target is not resolved here.
  Reviewed: 2026-11-12 (sonnet)
