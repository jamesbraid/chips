# Tier-1 routine roles, chips batch 1

Role statements for batch 1 of the tier-1 reading round. Each statement comes only from the rendered facts for that routine: registers, calls, constants and branch structure in the named binary. Names of routines and the purpose they suggest come from the symbol names, and every entry says where that reading is a guess.

- handle_cac_buserr in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1dcd0.
  The name places this on the cached-access bus error path. It finds the matching spool record (get_matching_spool_addr, 0x1dd08), maps the faulting node to a partition and region (nasid_to_partid, part_id, nasid_to_region), and runs checks (error_check_part_page, error_check_memory_access, error_check_poisoned_state, memory_iscalias). Its outcomes are partition_handle_error calls with codes 0x1 through 0x9, a page discard (error_page_discard, 0x1df78), a CRB dump (dump_crb, 0x1e320), or kl_panic at 0x1ddb4. What the codes mean is not stated in the facts.
  Grade: inferred.

- intpend0 in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c.
  It tests a bit word at 0x9200000001000098 against a mask (and at 0x1ff4c and 0x20014). It picks a table record with ms1bit and works on the semaphore at record +32 (cvsema, valusema, vsema). The loop at 0x1fff0 compares the semaphore value with hub_intr_wakeup_cnt, and two indirect calls through record +16 (0x1ffc8, 0x2005c) do the per-record work. The dispatch rule that decides which record runs is not established.
  Grade: inferred.

- intpend1 in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2006c.
  It has a similar shape to intpend0 but reads a different bit word, at 0x92000000010000a0, masked against s2 (0x200a0). It uses a second record table selected by ms1bit (0x200b8) and makes an indirect call through record +16 (0x200f0). A cmn_err report at 0x20148 sits on a path whose condition the facts do not establish.
  Grade: inferred.

- cpuintr in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20508.
  It finds the current CPU's per-processor block by indexing pdaindr with a 16-bit value from 0xffffffffffffc420, using 16-byte entries. It reads a flag byte at offset 0x520 of that block and tests bit 0x20 of the word at -0x3d80. It calls bcopy with length 0x168, then doacvec and doactions (0x205b4, 0x205bc), and brackets its work with log_tstamp_event calls tagged 0x71 and 0x65 (0x205f0, 0x2060c). The second event passes 0x71 as an argument, which suggests an open and close pair; the facts do not confirm it.
  Grade: inferred.

- dbgintr in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c.
  It reads the same per-CPU block as cpuintr: the 16-bit CPU id, the pdaindr entry, and the flag byte at +0x520. It stores a value to 0x9200000001000090 and calls debug (0x206b4) with a format string from .rodata+32520, a byte read from the per-CPU block at offset 0x520 plus 118, and the 0x9200000001000090 address. The meaning of that byte is not established.
  Grade: inferred.

- chkdebug in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20974.
  It appears to gate the debug entry. It reads the CPU id, the per-CPU flag byte at +0x520, and the word at 0x92000000010000a0, then calls dbgintr (0x209b0) only when a bit test at 0x209a8 is nonzero. The value tested against is listed as unknown in the facts, so the gating condition is only partly understood.
  Grade: inferred.

- get_my_slotid in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23be4.
  This is a thin wrapper. It loads one 64-bit word from 0x9200000001220048 and passes the incoming a1 through a3 to hub_slotbits_to_slot (0x23bf4), returning that result. The facts do not show the loaded word as a direct argument, so its role in the slot lookup is open.
  Grade: inferred.

- llp_pfail_intr in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4.
  The name suggests a link-level power-failure interrupt. It compares the owner CPU from msc_owner_cpu (via the pointer at 0x24fd0) with a 16-bit value (0x2530c), serializes with llp_pfail_barrier (0x25344), and runs a sequence of vector_read and vector_write calls with us_delay waits of 0x64 and 0x12c units. It tests one bit at a time in the word at 0x9200000001608088 (0x253a8 to 0x253f8) and writes 0x9200000001600110 and 0x9200000001600008. A link retrain or quiesce is a guess from the call pattern; the register meanings and the unit of us_delay are not stated.
  Grade: inferred.

- force_system_shutdown in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x26ad4.
  It logs a message through cmn_err (0x26ae4), waits 0x7a120 units with us_delay (0x26af0), and calls elsc_system_reset (0x26af8). If that call returns a negative value, it prints through printf (0x26b14) and waits 0xf4240 units (0x26b20). A backward branch at 0x26b30 to 0x26b04 forms a loop around the reset attempt, and the facts do not show the exit condition.
  Grade: inferred.

- bootstrap in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a5b8.
  This is a short early-boot routine. It reads a 64-bit word at 0x9200000001600000, calls mapped_kernel_setup_tlb (0x2a60c) with its incoming a2 and a3, and then jumps through a relocated pointer (jr at 0x2a62c, target .text+173620). The name and the TLB call suggest a handoff into the mapped kernel. The target is not named, and code from 0x2a634 on is not reached from the entry.
  Grade: inferred.

- __nanotime in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e194.
  It takes the timelock spinlock (mutex_spinlock_spl at 0x2e1a0) and reads a 64-bit counter at 0x9200000001030100. It combines that with the adjtime_delta, adjtime_RTC and adjtime_nanos values, and normalizes the result with loops that compare against 0x3b9aca00. The lock is released at 0x2e340 or 0x2e3c0. Reading 0x3b9aca00 as a count of nanoseconds per second is an inference from the constant alone.
  Grade: inferred.

- acktmoclock in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0.
  It reads the 16-bit CPU id from 0xffffffffffffc420, looks up the per-CPU flag byte at +0x520, and writes one of two hub words depending on that flag. A nonzero flag leads to a store at 0x9200000001000128 and a zero flag to a store at 0x9200000001000120, and the routine returns a value derived from the CPU index. The name suggests a timer acknowledge, but the facts do not show the timeout semantics.
  Grade: inferred.

- ackkgclock in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408.
  This is a close sibling of acktmoclock. It reads the same CPU id and per-CPU flag, and writes 0x9200000001000138 on the nonzero-flag path or 0x9200000001000130 on the zero-flag path. It returns a value derived from the CPU index. Its use as the clock acknowledge is inferred from the name and from the call in slowkgclock (0x2f5fc).
  Grade: inferred.

- startkgclock in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440.
  It runs under the spinlock at sym(.sbss)+288 (mutex_spinlock_spl at 0x2f44c, unlocks at 0x2f50c and 0x2f548). When the word at sym(.sdata)+392 is zero, it jumps to a setkgvector call that installs prof_intr. It maps a node and subnode to a CPU with cnodetocpu (0x2f4c4) and writes state at 0x9200000001000158, 0x9200000001000150 and 0x9200000001000118. The 0x4e2 comparisons and the role of the flag are not established.
  Grade: inferred.

- slowkgclock in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f558.
  It takes the same spinlock as startkgclock and compares the master_procid value with the current CPU index (0x2f588). It calls ackkgclock (0x2f5fc) on one path and calls spinlock_init (0x2f61c) on the path taken when the word at sym(.sdata)+400 is zero. The name "slow" is a label only; the facts do not show a rate.
  Grade: inferred.

- prof_intr in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x301e0.
  This looks like the profiling clock interrupt. It calls fastick_maint (0x301f8), maps a node and subnode to a CPU with cnode_subnode_to_cpu (0x30248), and compares the counter at 0x9200000001030100 with a stored value to decide whether to act. It tests bit 0x20 of the word at -0x3d80, the same test cpuintr makes, and records paired timestamp events 0x6e and 0x65 (0x302b0, 0x302cc).
  Grade: inferred.

- mdir_xlate_addr_mem in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x307f4.
  It formats text into a0 with sprintf, at four call sites (0x30890 to 0x3095c) that share one format string. It reads a 64-bit word at 0x9200000001200018 and a word at 0x9000000010000090 (a zero test at 0x30834), and tests the incoming a2 against zero and 0x36. The argument values 0x24, 0x48, 0x4c, 0x58 and 0x59 suggest a printed rendering of a memory-directory translation, but the facts do not show what is printed.
  Grade: inferred.

- ecc_handler in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3cfcc.
  It works on a structure passed in a1, reading fields from offset 0x0 up to 0x2bc and writing several of them back. It formats the error word at a1+24 (cer_to_hex, 0x3d028), tests its top bits and several field masks, and checks recoverability (eccf_recoverable_threshold, 0x3d0cc). A failed check goes to failsoft_panic_check (0x3d558). It issues cache operations through the pointer at 0x3c820 (ecc_cacheOp, with codes 0 through 7), forces lines invalid, saves the error (save_cache_error, 0x3d298), and calls memerror_handle_uce (0x3d63c) with a final cmn_err_tag report at 0x3d720. The mapping from mask bits to error classes is not established.
  Grade: inferred.

- _mraccess in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3890.
  This is the metered-access half of a synchronization primitive. It looks up a wait-channel meter for syncinfo with wchanmeter (0x38b0). If the meter exists it calls mr_access (0x38c0); otherwise it takes an entry through mrmeter_getentry (0x392c) and mrmeter_entry (0x3994). It updates counters at meter offsets 0x1c0 through 0x1d0, and a load-linked and store-conditional loop (0x3940 to 0x394c) works on the word at +0x198. The primitive it meters is not named in the facts.
  Grade: inferred.

- _mrupdate in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39ec.
  This is the update side of _mraccess in the same archive member. It finds the meter with wchanmeter (0x3a0c). When that returns no meter, it calls mr_update (0x3a1c) and returns. When it finds a meter, it creates a record with mrmeter_entry, class 6 (0x3ac4), branches back to the mr_update call (0x3a1c), and writes fields at meter offsets 0x1a0 through 0x1d8 from the 64-bit counter at 0x9200000001030100. Bit 0x4 of the halfword at offset 0 of that record (0x3a90) gates a store of 2 to the halfword and an increment of the word at meter offset 0x1a0. The field meanings are inferred from the access routine, not stated.
  Grade: inferred.

- sn0drv_ioctl in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0x2a4.
  This is the ioctl entry of the sn0drv object. It compares the command, a1-8, with 0xf, unsigned (0x2dc). Commands out of range go to sndrv_ioctl_common (0x2f8) with the same four arguments. In-range commands load a handler address from a table in .rodata and jump to it through a register (0x2e4 to 0x2e8), and the facts do not resolve those targets. The region from 0x324 to 0xb6c is not reached from the entry and is not analyzed here.
  Grade: inferred.

- bitlockdebug in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x1668.
  It works on a lock structure passed in a2. It takes the lock with try_bitlock (0x16cc, 0x17f8) and updates the lock fields at +0x2a through +0xbc with load-linked and store-conditional loops. On error paths it restores the interrupt level with splx (0x17e0) and reports through cmn_err (0x18bc) using the value at 0xffffffffaff20000. The "debug" in the name suggests a checking variant, but the facts do not show a debug-only path.
  Grade: inferred.

- _64bitlockdebug in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c.
  This is the 64-bit counterpart of bitlockdebug. It has the same structure: an acquire through try_64bitlock (0x1f70, 0x209c), load-linked and store-conditional updates on the same field offsets, splx (0x2084) on the error path, and a cmn_err report (0x2160). The facts do not show a layout difference between the two, so the difference is only the call names.
  Grade: inferred.

- _64bitunlockdebug in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x21d0.
  It releases the lock in a2. It compares the 16-bit field at +0x2a with the 16-bit value at 0xffffffffffffc3a0, which appears to be the current CPU id given how the lock routines above use it. On a mismatch it branches to 0x22a8 and reports through cmn_err (0x22c0). On the success path it updates fields at offsets +0x40 through +0x80 and writes back a0+0. The field layout is inferred from the paired lock routines.
  Grade: inferred.

- heart_mlreset in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x4c8.
  The object name points to the HEART chip block. The routine writes a sequence of 64-bit registers in the 0xffffffffaff10000 window (offsets 0x00 to 0x40), and stores to 0x9000000018000044, 0x9000000018000060 and 0x9000000018000068. It calls getcpuid (0x4d0) first with its own arguments and returns the base address 0xffffffffaff10000. The register meanings and the reason for this order are not stated, and the name "mlreset" is not explained by the facts.
  Grade: inferred.
