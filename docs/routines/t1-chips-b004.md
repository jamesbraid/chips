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

- `ackkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29fc0.
  This has the same shape as `acktmoclock` at 0x29f84: the same processor number and per-processor byte are tested
  (beq at 0x29fe0), and the two exits store to 0x9200000001000130 and 0x9200000001000138. The stores mirror the pair in
  `acktmoclock`, so the two are probably companions, but the facts do not show how they are used. Grade: inferred.

- `startkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29ffc.
  The routine takes a spinlock at .sbss+192 with mutex_spinlock_spl (0x2a008), then tests the .sdata word at +368; when
  that word is zero it jumps to 0x2a1c4 and calls setkgvector with prof_intr. Otherwise it passes the halfword at -0x3bd6
  to cnodetocpu (0x2a104), compares the value at -0x3ac4 with a1 (0x2a074), and stores doublewords to 0x9200000001000158,
  0x9200000001000118 and 0x9200000001000150 (0x2a0f0, 0x2a170, 0x2a1ac). It releases the lock through mutex_spinunlock
  at 0x2a184 and 0x2a1b4. Grade: inferred. The meanings of the -0x3bd6 and -0x3ac4 values are not established.

- `slowkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2a1dc.
  The routine takes the same spinlock (.sbss+192) through mutex_spinlock_spl (0x2a1f0) and releases it through
  mutex_spinunlock at 0x2a220 and 0x2a27c. It compares the halfword at master_procid with the running processor's number
  (bne at 0x2a20c), so the master processor takes a different path. Later it stores 32-bit words to the -0x3bf8 block at
  +0x3c58 (0x2a270) and to 0xffffffffffffc53c (0x2a280), then calls ackkgclock (0x2a284). It calls spinlock_init at 0x2a2a4
  on the path where the .sdata word at +376 is zero. Grade: inferred.

- `mdir_xlate_addr_mem` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b86c.
  The routine loads a doubleword from 0x9200000001780008 (0x2b870) and branches on the sign of a2 (bltz at 0x2b8a8).
  Both paths format text with sprintf (calls at 0x2b8e0 and 0x2b900) using the string at .rodata+47160, and the second
  path also passes its arg1 on. It returns sprintf's result. The name suggests a directory-address translation, but the
  facts show no translation arithmetic, so what the formatted text is for is unknown. Grade: inferred.

- `_mraccess` in `IP35/usr/cpu/sysgen/IP35boot/ksync_metered.a(sema.o)` at 0x3890.
  The routine first obtains a record from wchanmeter (call at 0x38b0). If that record is found it either calls mr_access
  (0x38c0) or looks up an entry with mrmeter_getentry (0x392c) and creates one with mrmeter_entry (0x3994), using kind
  code 5. It updates counters in the record at offsets +0x1c0 to +0x1d0, and a load-linked and store-conditional pair at
  +0x198 (0x3940 and 0x394c) makes that update atomic. Its return value is one of the results of mr_access or
  mrmeter_getentry. The name suggests a metered access; the facts show the counter updates but not what is counted.
  Grade: inferred.

- `_mrupdate` in `IP35/usr/cpu/sysgen/IP35boot/ksync_metered.a(sema.o)` at 0x39ec.
  This is the counterpart of `_mraccess`: it obtains the same record from wchanmeter (0x3a0c) and updates a different
  set of counters, at offsets +0x1a0 to +0x1d8. It calls mr_update (0x3a1c) and calls mrmeter_entry with kind code 6
  rather than 5 (0x3ac4). Whether the value tested with a7 at 0x3a90 is an input or a computed flag is not known from the
  facts. Grade: inferred.

- `restart` in `IP27/unix` at 0xc000000000029814.
  The routine calls us_delay with 0xf4240 (0x298a0), then sysctlr_power_off with 0 (0x298cc), then us_delay with
  0x2dc6c0 (0x298d4). It loops over a count held at 0xc0000000014d3e24, and calls ni_reset_port (0x29904) on the path
  where the word at 0xc0000000014d4350 is zero. After the loop it calls get_nasid, elsc_init and elsc_system_reset
  (0x29928 to 0x29930), and prints with printf (0x2994c) when the reset result is negative. The name suggests a restart
  sequence, and the calls agree with that, but the addresses give only the order of calls, not a confirmed boot sequence.
  Grade: inferred.

- `bte_init` in `IP27/unix` at 0xc00000000002bf5c.
  The routine writes fields into the structure passed as a0, at offsets 0x0, 0x18, 0x20, 0x28, 0x30, 0x40, 0x54 and 0x70,
  and stores a doubleword to 0x92000000014001f8 twice. It tests a bit of the word at 0xc0000000014d405c (0x2bf84), then calls
  spinlock_init at a0+68 (0x2bf98) with the lock word at 0xc000000001407658. A loop runs on the count in a2 (the test at
  0x2c004), and each pass starts from a halfword in the table at 0xc0000000014d4e80 (0x2bfdc). The name suggests the
  block-transfer engine, but the field meanings are not in the facts. Grade: inferred.

- `net_link_up` in `IP27/unix` at 0xc00000000002e58c.
  The routine is a leaf: it loads one doubleword from 0x9200000001600000 (0x2e590) and returns. The value it returns is
  not established, because the facts list the return value as unknown. The name suggests a network link state, and
  nothing else in the body supports or contradicts that. Grade: inferred.

- `intpend0` in `IP27/unix` at 0xc00000000003908c.
  The routine reads a pending word from 0x9200000001000098 and tests it against the word at -0x3a68 (0xc0000000000390cc).
  It calls ms1bit (0x39104) to pick an index, scales that index by 72 (the expression is (9 * index) * 8) to address a
  record table at -0x3a58, and calls cvsema (0x390dc), valusema (0x39158) and vsema (0x39178) on the record. It can also
  call an indirect routine loaded from record +16 (0x39148). The name suggests an interrupt-pending dispatcher; the link
  from bit to record is inferred from the scale only. Grade: inferred.

- `intpend1` in `IP27/unix` at 0xc0000000000391ec.
  This is the second-level counterpart of `intpend0`. It reads the words at 0x92000000010000a0 and 0x9200000001000098,
  calls ms1bit (0x39238), and uses the same 72-byte record scale, but on a different record table at -0x3a50. It calls an
  indirect routine from record +16 (0x39270). On one path it calls cmn_err (0x392c8) with first argument 0 and a message
  pointer the facts do not resolve. Grade: inferred.

- `cpuintr` in `IP27/unix` at 0xc000000000039688.
  The routine copies 0x168 bytes with bcopy (0x3972c), taking the source from its second argument, then calls doacvec
  (0x39734) and doactions (0x3973c). It stores to 0x9200000001000090 and reads 0x9200000001000098, the same pair that
  `dbgintr` and `intpend0` use. Two log_tstamp_event calls, with codes 0x71 and 0x65 (0x39770 and 0x3978c), sit on paths
  that test bit 0x20 of the word at -0x3d80. Grade: inferred. The bcopy destination and the meaning of the source are
  unknown.

- `dbgintr` in `IP27/unix` at 0xc0000000000397fc.
  This is a short path that stores a doubleword to 0x9200000001000090 and reads 0x9200000001000098, using the same
  per-processor table at 0xc0000000014d5028 as `cpuintr`. It calls debug (0x39834) with a fixed pointer, a byte from that
  table entry at +1312 plus 118, and the 0x9200000001000090 address. The name suggests a debugger entry on a debug
  interrupt; the facts agree on the calls but not on what debug does. Grade: inferred.

- `debug_stop_all_cpus` in `IP27/unix` at 0xc000000000039c18.
  The routine walks the processors: it gets a slice pointer for each with get_cpu_slice (0x39c48), tests the candidate
  against the running processor's number from -0x3be0, and calls cpu_enabled (0x39c94) with that number. On the path
  that gets a slice it stores a doubleword through the table at 0x9200000001800090 (0x39c6c). The loop bound is the word at
  0xc0000000014d2aa0. The name suggests stopping the other processors, but the stored value is not established, so the
  effect of the store is unknown. Grade: inferred.

- `intr_clear_bits` in `IP27/unix` at 0xc000000000039e28.
  The routine reads a doubleword through its a1 argument and tests it against two masks (the bne/beq pairs at 0x39e5c and
  0x39e80). It writes 0x9200000001000090 on the paths that pass and reads 0x9200000001000098 as well. Its return value is
  unknown to the facts. The name suggests clearing interrupt bits, but the facts do not show which bits are cleared or how.
  Grade: inferred.

- `__nanotime` in `IP27/unix` at 0xc000000000047314.
  The routine takes a spinlock at 0xc0000000014d2b3c through mutex_spinlock_spl (0x47320) and reads the counter at
  0x9200000001030100. It compares that counter with bases held in the words from 0xc0000000014d2b50 to 0xc0000000014d2b68,
  and compares several values with 0x3b9aca00, which is one billion, so it appears to split the count into seconds and a
  sub-second part. It releases the lock with mutex_spinunlock at 0x474c0 and 0x47540. Grade: inferred. The counter's rate
  is not in the facts.

- `ecc_handler` in `IP27/unix` at 0xc00000000005614c.
  The routine reads an error record from its a1 argument (fields at +0x0 to +0x34, +0x2b8 and +0x2bc) and branches on mask
  bits of the word at +0x18, including masks 0x5500000, 0xaa00000, 0x3800000, 0x4000000 and 0x8000000. It calls
  ecc_cacheOp with codes 0, 1, 3, 4, 5 and 7, calls ecc_force_cache_line_invalid on some paths, saves the error with
  save_cache_error (0x56418), and on one path calls memerror_handle_uce (0x567bc). It reports through cmn_err_tag with code
  0xb96 (0x568a0) and calls failsoft_panic_check (0x566d8) on another path. Grade: inferred. The mask meanings, and the
  names cer_to_hex and eccf_recoverable_threshold, do not settle which error classes these paths handle.

- `get_myid` in `IP27/unix` at 0xc0000000000988ec.
  The routine is a leaf: it loads a doubleword from 0x9200000001000020 and returns it. The facts establish the read and
  the return, and nothing more. The name suggests a processor or node id, but that is only a hint. Grade: inferred.

- `gfx_flow_attach_me` in `IP27/unix` at 0xc000000000396524.
  The routine stores a halfword at the record's +0x60 and a doubleword at +0x68, and writes three doublewords into the table
  at 0x9200000001000000. It loads the word at +0x14 and, on the path taken when a tested register is below 3 (unsigned),
  calls err_int_block_mask (0x396664) with code 8, the processor number from -0x3be0, and the word at 0xc0000000014cbf40
  plus one. The tested register is probably the word loaded from +0x14, but the facts leave it unnamed. The name says
  graphics, but nothing in the facts identifies a graphics device. Grade: inferred.

- `gfx_flow_detach_me` in `IP27/unix` at 0xc0000000003966c8.
  This is the counterpart of `gfx_flow_attach_me`. It stores to the record's +0x14, +0x60 and +0x68 fields and to the
  pointer held at +0x58, writes the same table at 0x9200000001000000, and calls err_int_unblock_mask (0x3967dc) with
  code 8, the processor number, and a value scaled from the byte at table entry +1312 by 40 ((x << 2 + x) << 3). The
  constant 0xdeadbabe passed as a5 is not explained by the facts. Grade: inferred.

- `getcpuid` in `IP30/unix` at 0xa800000020011334.
  The routine is a leaf: it loads a doubleword from the uncached address 0xffffffffaff50000 (0xa80000002001133c) and returns
  it. The name suggests a processor id, but the facts show only a read of that address. Grade: inferred.

- `__nanotime` in `IP30/unix` at 0xa800000020016030.
  This has the same shape as the IP27 `__nanotime` above, in the IP30 kernel. It takes a spinlock at 0xa8000000204ae3d4
  through mutex_spinlock_spl (0xa80000002001603c), reads the counter at the uncached address 0xffffffffaff20000, and keeps a
  running base in the words at 0xa8000000204b03a0 and 0xa8000000204b03a8. It compares against 0x3b9aca00, so the same
  seconds and sub-second split is implied. Grade: inferred.

- `heart_cpu_intr` in `IP30/unix` at 0xa80000002003ec64.
  The routine reads a halfword at 0xffffffffffffc3a0 and calls doacvec (0xa80000002003ec80) with its own four arguments.
  A doubleword store to the uncached address 0xffffffffaff10028 sits in the delay slot of that call (0xa80000002003ec84),
  and the routine then calls doactions (0xa80000002003ec88) and returns its result. The name suggests a HEART interrupt
  entry, but the facts do not say which device owns the store target. Grade: inferred.

- `chkdebug` in `IP30/unix` at 0xa80000002003ecd4.
  The routine reads the same halfword at 0xffffffffffffc3a0 and a doubleword at the uncached address 0xffffffffaff10030,
  and stores to 0xffffffffaff10028 (0xa80000002003ed00). It tests its a2 argument against the 0xffffffffaff10030 word
  (0xa80000002003ecf4) and calls debug (0xa80000002003ed04) with a string pointer, its arg1, the base 0xffffffffaff10000,
  and a halfword from -0x3c60 plus 42. Grade: inferred. The purpose of the test is unknown.
