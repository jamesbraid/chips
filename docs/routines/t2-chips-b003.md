# Tier-2 reading, batch 3 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls, branches and constants. Every role is inferred. The facts do not settle what the fields, bits or callees mean, and each entry says where that stays open.

- `intr_connect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f26c
  **Inferred.** It looks up a per-CPU record through `pdaindr` at `a0 << 4` and the node id through `compact_to_nasid_node`, then takes a spinlock around an `ll`/`sc` update of a mask word (0x1f47c, 0x1f484). It calls `intr_get_ptrs` (0x1f210, from 0x1f2a0) and `intr_thread_setup` with constant 0x200 (0x1f4e0) when a flag bit is set, and it returns -1 or 0. The meaning of the mask bits and of the level number is not established by these facts.

- `intr_disconnect_level` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f508
  **Inferred.** It follows the same lookup and spinlock shape as `intr_connect_level`, using `intr_get_ptrs` (0x1f52c) and the spinlock calls at 0x1f540 and 0x1f578. It compares a2 against the constant 0x3 at 0x1f570 and writes a doubleword to the fixed address 0x9200000001800000 at 0x1f6a4 inside a loop. It returns -1 or 0, and which entry it clears is open from these facts.

- `intr_block_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f820
  **Inferred.** A 28-byte wrapper that passes its arguments to `do_intr_block_bit` (0x1f828) with a2 set to the constant 0x1, and returns that result. The flag value is read as "block" from the name, not from the callee.

- `intr_unblock_bit` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1f83c
  **Inferred.** The sibling of `intr_block_bit`: the same 28-byte wrapper around `do_intr_block_bit` (0x1f844), with the constant 0x0 in place of 0x1. The pairing with the block routine is inferred from the names and the flag values.

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c
  **Inferred.** It reads a hub pending word at the fixed address 0x9200000001000098 and loops while bits remain. It finds a set bit through `ms1bit` (0x1ff84), which by its name returns the most significant one, indexes a 72-byte record table by that bit number (the `x * 9 * 8` scaling at 0x1ffa4), and calls the semaphore routines `cvsema`, `valusema` and `vsema` on the record at +32 (0x1ff5c, 0x1ffd8, 0x1fff8). It then calls through a function pointer stored at record +16 (0x1ffc8, 0x2005c). Which bit is taken first and what the record fields mean is not established here.

- `cpuintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20508
  **Inferred.** It takes a CPU id from the short at `-0x3be0`, loads that CPU's record through `pdaindr`, and copies 0x168 bytes with `bcopy` (0x205ac). It then runs `doacvec` and `doactions` (0x205b4, 0x205bc) and logs timestamp events 0x71 and 0x65 (0x205f0, 0x2060c). It also writes the mailbox at 0x9200000001000090 and reads 0x9200000001000098, so the vector and action callees are the likely dispatch step. The exact dispatch order is open.

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c
  **Inferred.** It reads the same CPU-indexed record and the halfword at `-0x3be0`, stores a doubleword to the mailbox 0x9200000001000090 (0x206ac), and reads 0x9200000001000098 (0x206b8). It then calls `debug` (0x206b4) with a constant string address and a byte from the CPU record plus 1312 plus 118. Its role as a debug entry follows from the name and the `debug` callee, not from any body in this read.

- `tlbintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20778
  **Inferred.** It follows the `dbgintr` shape: it uses the same CPU record and the same mailbox pair at 0x9200000001000090 and 0x9200000001000098. It then calls `tlbflush_rand` (0x207a8) with its own arguments and returns that result. The name suggests a TLB-flush handler, but the facts show only the call, not the flush itself.

- `chkdebug` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20974
  **Inferred.** It reads the CPU record through the halfword at `-0x3be0` and the doubleword at 0x92000000010000a0. It calls `dbgintr` (0x209b0) only when that word has a bit in common with the value from the CPU record (the branch at 0x209a8). The word at 0x92000000010000a0 is a flag by name, which the facts do not confirm.

- `hub_migrintr_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20a2c
  **Inferred.** It calls `cnodetocpu` (0x20a34) and then `intr_connect_level` (0x20a68) with level 3, `migr_intr_handler` and `migr_intr_prologue_handler`. It skips that connect when `numnodes` is 1 or the CPU value is -1 (0x20a4c, 0x20a54), and it reports a failed connect through `cmn_err` (0x20a88). That the routine sets up the migration interrupt is inferred from the handler names.

- `intr_dumpvec` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20f58
  **Inferred.** It loops over the node index up to `numnodes` (0x20fa8) and skips any node whose `compact_to_nasid_node` entry is -1 (0x20fb4). For each node it reads per-node words at fixed offsets in the table pointed to by `-0x3c00` (0x21058 to 0x21088) and calls `dump_vector` (0x210d0). It then makes several indirect calls with a constant format string at `.rodata+32520` (0x21050 to 0x211a8). The printed field names are open, because the indirect callees are not resolved here.

- `bte_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21994
  **Inferred.** It takes an error record in a0, reads its node-table pointer at +8, and branches on the halfword at +16 through the cases 1, 2, 3, 6 and 7 (0x21ad0 to 0x21af0). It calls `hubiio_crb_error_handler` (0x219f0) for the node, updates the table words at 0x9200000001c001e8, 0x9200000001c001f8 and 0x9200000001c00138 under the `splerr` spinlock (0x21a0c, 0x21a94), and logs at level 12 through `cmn_err` (0x21b58). The meaning of each error code is not established by these facts.

- `bte_stall_node` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x21c9c
  **Inferred.** It calls `verify_snchip_rev` and branches on its result against 5 (0x21cbc). It updates `bte_stall_node_mask` with an `lld`/`scd` pair (0x21cd4, 0x21cdc) and then programs and reads the BTE register banks at 0x9200000001c10000 and 0x9200000001c20000, using delays of 1 and 10 microseconds through `us_delay` (0x21de4, 0x21dfc, 0x21e48). It allocates a 512-byte buffer with `kmem_alloc_node` (0x21d14) and frees it with `kmem_free` (0x22030). On one path it calls `bte_error_handler` (0x21fd0). The intent of the stall and the exact register meanings are open.

- `bte_bpush_war` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2204c
  **Inferred.** It runs only when the `bpush_war_enable` flag is set (0x22068), and it reads the node's nasid and chip revision through `get_hub_chiprev` (0x22098). When the revision is below 5 (0x220b0) and this node's bit in `bte_stall_node_mask` is set (0x220bc), it pins the thread with `rt_pin_thread` (0x220d4), calls `bte_stall_node` (0x22160), and unpins with `rt_unpin_thread` (0x22150). The hardware problem the workaround addresses is not in these facts, so the name is the only hint.

- `hub_piomap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22420
  **Inferred.** It finds the widget's id and master through `xwidget_info_get`, `xwidget_info_id_get` and `xwidget_info_master_get` (0x22450 to 0x2246c), and it searches a mapping table under `mutex_spinlock` (0x22548, released at 0x225c8, 0x2262c and 0x226f4). It checks the request against the limits 0x1000000 (0x224d0) and 0x20000000 (0x2252c), and it waits on a sync object with `sv_wait` (0x2270c, argument 0x19) on one path. The table layout and the wait condition are open here.

- `hub_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2288c
  **Inferred.** It looks up the same widget records as `hub_piomap_alloc` (0x228a8 to 0x228d0) and then calls `hub_piomap_addr` (0x22914). It checks whether the request's end, a2 plus a3, is above 0x1000000 (0x228e4) and tests bit 0x8 of a4 (0x22928) to choose the path. The translation rule itself is in `hub_piomap_addr`, which this read does not cover.

- `hub_dmamap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22958
  **Inferred.** It looks up the widget through `xwidget_info_get`, `xwidget_info_id_get` and `xwidget_info_master_get` (0x22968 to 0x22980). It allocates a 16-byte record with `kern_malloc` (0x22990) and writes four fields into it at offsets 0x0, 0x4, 0x8 and 0xc (0x2299c to 0x229c8), with bit 0x1 of a3 selecting one of the stores (0x229c0). It returns the record pointer. The field meanings are not named by the facts.

- `hub_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x229d8
  **Inferred.** It rewrites the word at +0xc of its argument (0x229dc, 0x229f0) and then calls `kern_free` with the same arguments (0x229ec). It is the release side of `hub_dmamap_alloc`, which allocates a 16-byte record of the same kind. The value stored at +0xc is not derived here.

- `hub_dmamap_addr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a00
  **Inferred.** It reads and writes the word at +0xc of its argument record and tests bit 0x2 of that word (0x22a18). On one path it reports through `cmn_err` at level 4 with the word at +0 and the word at +12 ORed with 0x2 (0x22a48), and it returns its second argument. The address computation is not in this routine's facts.

- `hub_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22a5c
  **Inferred.** It has the same shape as `hub_dmamap_addr`: the same +0xc read-modify-write, the bit 0x2 test (0x22a74) and the level-4 `cmn_err` report (0x22aa4). It uses a different format-string address (`.rodata+34128`) and returns its second argument. Whether it lists or copies map entries is not established by these facts.

- `hub_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22ab8
  **Inferred.** It reads and writes the +0xc word of its argument and tests bit 0x2 of that word (0x22ad0). It tests a3 and, on one path, reports through `cmn_err` at level 4 with a constant -3 (0x22af8). The completion meaning follows from the name and the shared shape, not from the body.

- `hub_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e3c
  **Inferred.** A 28-byte wrapper that calls `do_hub_intr_alloc` through the pointer at 0x22b8c (0x22e44) with a3 set to the constant 0x0, and returns its result. Its counterpart `hub_intr_alloc_nothd` passes 0x1 instead, so the flag is read as a thread-related choice from the name.

- `hub_intr_alloc_nothd` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e58
  **Inferred.** The same 28-byte wrapper as `hub_intr_alloc`, calling `do_hub_intr_alloc` through the pointer at 0x22b8c (0x22e60) with the constant 0x1 in a3. The name suggests the no-thread variant of interrupt allocation, but the facts show only the flag value.

- `hub_intr_free` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22e74
  **Inferred.** It reads the record fields at +0x24, +0x28 and +0x2c, clears the byte at +0x5, and writes +0x0 and +0x8 (0x22ea0 to 0x22eac). It calls `hub_intr_disconnect` (0x22eb0), frees the 48-byte record with `kmem_free` (0x22ec8, size 0x30), and calls `intr_unreserve_level` with the halfword at +36 and the word at +40 (0x22ed8). Bits 0x4 and 0x1 of the word at +44 select the paths (0x22e98, 0x22ec0).

- `hub_intr_connect` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x22eec
  **Inferred.** It reads the halfword at +0x24 and the words at +0x20 and +0x28, and it calls `intr_connect_level` (0x22f24) with those fields and a5 set to 0. It stores the result at +0x2c (0x22f4c) and returns it, or 0 on the success path. When a3 is nonzero it makes an indirect call (0x22f64) whose target is not resolved here.
