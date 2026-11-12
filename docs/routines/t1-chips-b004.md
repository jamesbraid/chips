# Routine roles from the chips kernel binaries, set 4

Roles for 25 routines, each read from its rendered instruction facts: loads, stores, branches, constants and calls.
The routine names come from the inventory and are a hint only. Every entry is graded inferred, because the facts
show the mechanism but not what the loaded values mean. Where a value is unknown to the facts, the entry says so.

- `acktmoclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29f84.
  The routine takes the running processor's number from the halfword at -0x3bd8, uses it to index the per-processor
  pointer table at pdaindr (16 bytes per entry), and tests bit 0 of the byte at 0x528 past the pointer stored at +8 in
  that entry (beq at 0x29fa4). When the bit is set it stores a doubleword to 0x9200000001000128 and returns; when it is
  clear it stores to 0x9200000001000120 and returns. The name suggests a timeout acknowledgement, but no timer access
  appears in the facts. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `ackkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29fc0.
  This has the same shape as `acktmoclock` at 0x29f84: the same processor number and per-processor byte are tested
  (beq at 0x29fe0), and the two exits store to 0x9200000001000130 and 0x9200000001000138. The stores mirror the pair in
  `acktmoclock`, so the two are probably companions, but the facts do not show how they are used. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `startkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29ffc.
  The routine takes a spinlock at .sbss+192 with mutex_spinlock_spl (0x2a008), then tests the .sdata word at +368 (beq
  at 0x2a020). When that word is zero it calls setkgvector with prof_intr (0x2a1c4) and then rejoins the main path at
  0x2a028. On the main path it compares the value at -0x3ac4 with a1 (beq at 0x2a074); when they are equal it skips to
  mutex_spinunlock at 0x2a1b4. Otherwise it stores a word to -0x3ac4 and stores a doubleword to 0x9200000001000158
  (0x2a0f0) or to 0x9200000001000150 (0x2a1ac), chosen by bit 0 of the byte at 0x528 past the pointer at +8 of the
  pdaindr entry (beq at 0x2a0e4). It also stores a doubleword to 0x9200000001000118 (0x2a170) unless the bne at
  0x2a110 skips it. It passes the halfword at -0x3bd6 to cnodetocpu (0x2a104) only when the word at +0x3c58 past the
  pointer at -0x3bf8 is not 1 (beq at 0x2a0fc). It releases the lock through mutex_spinunlock at 0x2a184 and 0x2a1b4.
  Grade: inferred. The meanings of the -0x3bd6 and -0x3ac4 values are not established.
  Reviewed: 2026-11-12 (sonnet)

- `slowkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2a1dc.
  The routine takes the same spinlock (.sbss+192) through mutex_spinlock_spl (0x2a1f0) and releases it through
  mutex_spinunlock at 0x2a220 and 0x2a27c. When the .sdata word at +376 is zero (beq at 0x2a1e4) it first calls
  spinlock_init on that lock (0x2a2a4) and then rejoins before the lock is taken. It compares the halfword at
  master_procid with the running processor's number (bne at 0x2a20c). When they are equal and the word at audioclock
  is nonzero (beq at 0x2a214) it unlocks at 0x2a220 and returns; otherwise it continues. On the continuing path it
  stores a 32-bit word to the -0x3bf8 block at +0x3c58 (0x2a270) only when the .sdata word at +368 is nonzero (beq at
  0x2a250), then calls mutex_spinunlock (0x2a27c) with a 32-bit store to 0xffffffffffffc53c in its delay slot
  (0x2a280), and then calls ackkgclock (0x2a284). Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `mdir_xlate_addr_mem` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b86c.
  The routine loads a doubleword from 0x9200000001780008 (0x2b870) and branches on the sign of a2 (bltz at 0x2b8a8).
  Both paths format text with sprintf (calls at 0x2b8e0 and 0x2b900) and return sprintf's result. The facts render
  .rodata+47160 as the format string of both calls, but the disassembly adds 128 to the base pointer before the first
  call (0x2b8d8) and 96 in the second call's delay slot (0x2b904), so the two strings differ and the facts' value for
  the second call is doubtful. Role (from name): a directory-address translation. The facts show no translation
  arithmetic, so what the formatted text is for is unknown. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_mraccess` in `IP35/usr/cpu/sysgen/IP35boot/ksync_metered.a(sema.o)` at 0x3890.
  The routine first obtains a record from wchanmeter (call at 0x38b0). When the record is nonzero (bne at 0x38b8) it
  first calls mrmeter_entry with a1 = 5 and its own arg1 as a2 (0x3994). It then calls mr_access (0x38c0) whether or
  not a record was found. When the record is nonzero it reads the counter at 0x9200000001030100 (0x38e4) and updates
  the record's fields at offsets +0x1c0 to +0x1d0 (the stores at 0x3910 to 0x391c sit behind the beq at 0x3908, the
  one at 0x390c does not), calls mrmeter_getentry with a2 = 5 (0x392c), and when that returns nonzero runs a load-
  linked and store-conditional loop on the word at +0x198 (0x3940 and 0x394c) that retries at 0x3950. Its return value
  is one of the results of mr_access or mrmeter_getentry. Role (from name): a metered access; the facts show the
  counter updates but not what is counted. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_mrupdate` in `IP35/usr/cpu/sysgen/IP35boot/ksync_metered.a(sema.o)` at 0x39ec.
  This is the counterpart of `_mraccess`: it obtains the same record from wchanmeter (0x3a0c) and updates a different
  set of counters, at offsets +0x1a0 to +0x1d8. It calls mr_update (0x3a1c) and calls mrmeter_entry with kind code 6
  rather than 5 (0x3ac4). Whether the value tested with a7 at 0x3a90 is an input or a computed flag is not known from the
  facts. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `restart` in `IP27/unix` at 0xc000000000029814.
  The routine first loops over the count held at 0xc0000000014d3e24 (blez at 0x29834 skips the loop when the count is
  not positive; the loop branch is at 0x2988c), then calls us_delay with 0xf4240 (0x298a0). It compares the word at
  0xc0000000014cb024 with 2 (beq at 0x298b4). When they are equal it calls get_nasid, elsc_init and elsc_system_reset
  (0x2991c to 0x29930) and prints with printf (0x2994c) when the reset result is negative (bltz at 0x29938). Otherwise
  it enters a polling loop: when the word at 0xc0000000014d4350 is zero it calls ni_reset_port (0x29904), else it
  calls sysctlr_power_off with 0 (0x298cc), and either way it then calls us_delay with 0x2dc6c0 (0x298d4), with loop
  branches at 0x298ec and 0x298f4. Role (from name): a restart sequence. The facts give the calls and the guards but
  not what the guarded words mean. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `bte_init` in `IP27/unix` at 0xc00000000002bf5c.
  The routine writes fields into the structure passed as a0, at offsets 0x0, 0x18, 0x20, 0x28, 0x30, 0x40, 0x54 and
  0x70. It tests the word at 0xc0000000014d405c against a1 (beq at 0x2bf84), then calls spinlock_init on a0+68
  (0x2bf98) with 0xc000000001407658 as its second argument. It reads a halfword from the table at 0xc0000000014d4e80
  (0x2bfdc), indexed by the halfword at -0x3bde (0x2bfb0). It then branches on a2 (beq at 0x2c004); there is no loop.
  Both paths store a doubleword to a0+0 (0x2c008). With a2 nonzero it stores a second doubleword to a0+0 (0x2c010), a
  doubleword to 0x92000000014001f8 (0x2c014) and a word at +0x54 (0x2c018). With a2 zero it stores a doubleword to
  0x92000000014001f8 (0x2c038) and a word at +0x54 (0x2c040). Both paths store a word at +0x70 (0x2c020) and return
  a0. Role (from name): the block-transfer engine. The field meanings are not in the facts. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `net_link_up` in `IP27/unix` at 0xc00000000002e58c.
  The routine is a leaf: it loads one doubleword from 0x9200000001600000 (0x2e590) and returns. The value it returns is
  not established, because the facts list the return value as unknown. The name suggests a network link state, and
  nothing else in the body supports or contradicts that. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `intpend0` in `IP27/unix` at 0xc00000000003908c.
  The routine reads a pending word from 0x9200000001000098 and masks it with the word at -0x3a68 (beq at
  0xc0000000000390cc). It calls ms1bit (0x39104) to pick an index, scales that index by 72 (the expression is (9 *
  index) * 8) to address a record table at -0x3a58, and calls cvsema (0x390dc), valusema (0x39158) and vsema (0x39178)
  with the record's +32 address as their first argument. It can also call an indirect routine at 0x39148, loaded from
  record +8 and skipped when that doubleword is zero (beq at 0x3913c), with the record's +16 doubleword as its first
  argument. A second indirect call at 0xc0000000000391dc is on the path where bit 0x1000 of the record's +24 word is
  clear. Role (from name): an interrupt-pending dispatcher. The link from bit to record is inferred from the scale
  only. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `intpend1` in `IP27/unix` at 0xc0000000000391ec.
  The routine reads the word at 0x92000000010000a0 and masks it with the word at -0x3a60 (beq at 0xc000000000039220),
  calls ms1bit (0xc000000000039238), and uses a 72-byte record scale like `intpend0`, but on a different record table
  at -0x3a50. When the record's first doubleword is nonzero (beq at 0xc000000000039264) it calls the indirect routine
  loaded from that doubleword (0xc000000000039270), with the record's +16 doubleword as its first argument. When it is
  zero it calls cmn_err (0xc0000000000392c8) with a0 = 0 and a1 = 0xc00000000140c658; the facts do not show what is at
  that address. It also reads 0x9200000001000098 (0xc000000000039268). Role (from name): the second-level counterpart
  of `intpend0`. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `cpuintr` in `IP27/unix` at 0xc000000000039688.
  On the path where the byte at -0x3f80 and the word at 0xc0000000014ca2ac are both nonzero (beq at 0x396d4 and
  0x396dc), the routine copies 0x168 bytes with bcopy (0x3972c), passing its second argument as bcopy's first
  argument. On every path it then calls doacvec (0x39734) and doactions (0x3973c). It stores to 0x9200000001000090
  (0x396c8) and reads 0x9200000001000098 (0x396d0), the same pair that `dbgintr` and `intpend0` use. Two
  log_tstamp_event calls, with codes 0x71 (0x39770) and 0x65 (0x3978c), sit on paths that test bit 0x20 of the word at
  -0x3d80 (bne at 0x3969c and 0x3974c). Grade: inferred. The bcopy destination and the meaning of the source are
  unknown.
  Reviewed: 2026-11-12 (sonnet)

- `dbgintr` in `IP27/unix` at 0xc0000000000397fc.
  This is a short path that stores a doubleword to 0x9200000001000090 and reads 0x9200000001000098, using the same
  per-processor table at 0xc0000000014d5028 as `cpuintr`. It calls debug (0x39834) with a fixed pointer, a byte plus
  118, and the 0x9200000001000090 address. The byte is at +1312 past the pointer stored in the table entry. Role (from
  name): a debugger entry on a debug interrupt. The facts agree on the calls but not on what debug does. Grade:
  inferred.
  Reviewed: 2026-11-12 (sonnet)

- `debug_stop_all_cpus` in `IP27/unix` at 0xc000000000039c18.
  The routine loops over the processors up to the word at 0xc0000000014d2aa0 (blez at 0x39c34 skips the loop when the
  count is not positive). It skips the candidate equal to the running processor's number from -0x3be0 (beq at 0x39c88)
  and calls cpu_enabled (0x39c94) for each other candidate; the facts show a1 as the running processor's number but
  leave a0 unresolved. When cpu_enabled returns nonzero and the further tests pass (branches at 0x39ca8, 0x39cb8,
  0x39cc0 and 0x39cd8) it calls get_cpu_slice (0x39c48) and then stores a doubleword at 0x90 past a base derived from
  0x9200000001800000 (0x39c6c). The stored value is not established, so the effect of the store is unknown. Role (from
  name): stopping the other processors. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `intr_clear_bits` in `IP27/unix` at 0xc000000000039e28.
  The routine reads a doubleword through its a1 argument and returns early when it is zero (beq at 0x39e40). Otherwise
  it loops (bne at 0x39e90 branches back to 0x39e48) and tests the word against masks held in v1 and a7, which the
  facts leave unresolved (beq at 0x39e5c and 0x39e80). When a test passes it writes 0x9200000001000090 (stores at
  0x39e64 and 0x39e88) and then reads 0x9200000001000098. Its return value is unknown to the facts. Role (from name):
  clearing interrupt bits. The facts do not show which bits are cleared or how. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `__nanotime` in `IP27/unix` at 0xc000000000047314.
  The routine takes a spinlock at 0xc0000000014d2b3c through mutex_spinlock_spl (0x47320) and reads the counter at
  0x9200000001030100. It compares that counter with bases held in the words from 0xc0000000014d2b50 to 0xc0000000014d2b68,
  and compares several values with 0x3b9aca00, which is one billion, so it appears to split the count into seconds and a
  sub-second part. It releases the lock with mutex_spinunlock at 0x474c0 and 0x47540. Grade: inferred. The counter's rate
  is not in the facts.
  Reviewed: 2026-11-12 (sonnet)

- `ecc_handler` in `IP27/unix` at 0xc00000000005614c.
  The routine reads an error record from its a1 argument (fields at +0x8, +0x10, +0x18, +0x26, +0x28 to +0x34, +0x2b8
  and +0x2bc) and branches on mask bits of the word at +0x18, including masks 0x5500000, 0xaa00000, 0x3800000,
  0x4000000 and 0x8000000. It calls ecc_cacheOp with codes 0, 1, 3, 4, 5 and 7, calls ecc_force_cache_line_invalid on
  some paths, saves the error with save_cache_error (0x56418), and on one path calls memerror_handle_uce (0x567bc). It
  reports through cmn_err_tag with code 0xb96 (0x568a0) and calls failsoft_panic_check (0x566d8) on another path.
  Grade: inferred. The mask meanings, and the names cer_to_hex and eccf_recoverable_threshold, do not settle which
  error classes these paths handle.
  Reviewed: 2026-11-12 (sonnet)

- `get_myid` in `IP27/unix` at 0xc0000000000988ec.
  The routine is a leaf: it loads a doubleword from 0x9200000001000020 and returns it. The facts establish the read and
  the return, and nothing more. The name suggests a processor or node id, but that is only a hint. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `gfx_flow_attach_me` in `IP27/unix` at 0xc000000000396524.
  The routine stores a halfword at the record's +0x60 and a doubleword at +0x68, and writes three doublewords into the
  table at 0x9200000001000000. It loads the word at +0x14 (0x3965c8). The facts leave the register tested at 0x396570
  unnamed; it is not that word, whose load comes after the branch. When the tested register is below 3 (unsigned) it
  calls err_int_block_mask (0x396664) with a0 = 8, its own a1, a2 = the word at 0xc0000000014cbf40 plus one and a3 =
  the processor number from -0x3be0. Role (from name): attaching a graphics flow. Nothing in the facts identifies a
  graphics device. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `gfx_flow_detach_me` in `IP27/unix` at 0xc0000000003966c8.
  This is the counterpart of `gfx_flow_attach_me`. It stores to the record's +0x14, +0x60 and +0x68 fields and to the
  pointer held at +0x58, and writes the same table at 0x9200000001000000. Only when the register tested at 0x396790 is
  below 3 (unsigned) does it call err_int_unblock_mask (0x3967dc) with a0 = 8, a1 = 1, a2 = the processor number, and
  a3 = a value scaled from the byte at table entry +1312 by 40 ((x << 2 + x) << 3). The constant 0xdeadbabe passed as
  a5 is not explained by the facts. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `getcpuid` in `IP30/unix` at 0xa800000020011334.
  The routine is a leaf: it loads a doubleword from the uncached address 0xffffffffaff50000 (0xa80000002001133c) and returns
  it. The name suggests a processor id, but the facts show only a read of that address. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `__nanotime` in `IP30/unix` at 0xa800000020016030.
  This has the same shape as the IP27 `__nanotime` above, in the IP30 kernel. It takes a spinlock at
  0xa8000000204ae3d4 through mutex_spinlock_spl (0xa80000002001603c), reads the counter at the uncached address
  0xffffffffaff20000, and compares it with bases held in the words from 0xa8000000204ae3e8 to 0xa8000000204ae400. It
  compares values with 0x3b9aca00, which suggests the same seconds and sub-second split. It releases the lock with
  mutex_spinunlock at 0xa8000000200161cc and 0xa800000020016244. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `heart_cpu_intr` in `IP30/unix` at 0xa80000002003ec64.
  The routine reads a halfword at 0xffffffffffffc3a0 and calls doacvec (0xa80000002003ec80) with its own four arguments.
  A doubleword store to the uncached address 0xffffffffaff10028 sits in the delay slot of that call (0xa80000002003ec84),
  and the routine then calls doactions (0xa80000002003ec88) and returns its result. The name suggests a HEART interrupt
  entry, but the facts do not say which device owns the store target. Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `chkdebug` in `IP30/unix` at 0xa80000002003ecd4.
  The routine reads the same halfword at 0xffffffffffffc3a0 and a doubleword at the uncached address
  0xffffffffaff10030. It tests register a2 against that word (beq at 0xa80000002003ecf4). The routine computes a2
  itself, shifted by an amount taken from the halfword, so it is not the incoming a2 argument; the facts leave its
  value unresolved. Only when the result is nonzero does it store to 0xffffffffaff10028 (0xa80000002003ed00) and call
  debug (0xa80000002003ed04), with a0 = 0xa8000000203afe98, its arg1 as a1, a3 = 0xffffffffaff10000 and a4 = a
  halfword from -0x3c60 plus 42. Grade: inferred. The purpose of the test is unknown.
  Reviewed: 2026-11-12 (sonnet)
