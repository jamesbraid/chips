# Machine-independent kernel routines of the IP30 build read for completeness

These routines of `IP30/unix` (the linked IRIX 6.5 kernel for the Octane; addresses are virtual addresses) reach no chip
register of their own. They sit in the inventory because they are large, and each is read here to say what it does. A bare
number such as `-15456` addresses the process page below zero, where the halfword at -15456 is the number of the processor
running the code and the doubleword at -15744 holds that processor's flag bits.

- `log_tstamp_event` (`IP30/unix` `0xa8000000201f272c`, 716 bytes, frame 64 bytes) appends one timestamped record of
  five words to the calling processor's event log. It finds the per-processor structure through the table at
  0xa8000000204b0380 indexed by the processor number, and reads the free-running counter at 0xffffffffaff20000 for the
  timestamp. The log has two modes. When the word at structure +0x310 is nonzero it uses a private ring: the record at
  the pointer in +0x300 is filled in the order timestamp (+0x8), fifth argument (+0x28), fourth (+0x20), third
  (+0x18), second (+0x10), then the event code at +0x0, and the pointer advances by 48 bytes or wraps to the start in
  +0x2f8 when it was below the limit in +0x308. When it is zero it uses the shared ring at +0x288 if one exists: when
  the first word of the shared header is nonzero it adds 1 to it with `ll` and `sc` and stops; otherwise it takes a
  slot with `atomicIncWithWrap` on the header's word at +8 (wrap size at +0x14), adds 1 to the header's first word the
  same way and stops when the slot's first word is already nonzero, fills its arguments, chooses the timestamp (the
  current count, or one less than the following slot's when that is not later), clears the halfword at +6, stores the
  event code and bumps the used count at header +4 with `ll` and `sc`. When the used count reaches the threshold at
  +0x18, the reader count at +0x28 is nonzero, the event code is not 0xea62 and no per-processor suppression byte (at
  -16302) is set, it raises the interrupt level with `spl1` (only when `issplprof` says the current level allows it),
  calls `compare_and_dec_int_gt` on the reader count and, when that succeeds, `sv_signal` on the semaphore at +0x20,
  and restores the level with `splx`. The routine returns nothing. Established.
- `log_tstamp_vevent` (`IP30/unix` `0xa8000000201f29f8`, 1168 bytes, frame 112 bytes) is the variable-length sibling
  of `log_tstamp_event`: the second argument points to a payload and the third is its length in bytes. In the private
  mode it rounds the record to a multiple of 48 bytes by ((length + 7) / 40) + 1 slots, wrapping the pointer in +0x300
  across the limit in +0x308, and copies the payload in with `bcopy` after writing the event code at +0x0, the
  timestamp at +0x8 and the first four payload doublewords at +0x10. In the shared mode it needs ((length + 15) / 48) +
  1 slots, adds 1 to the header's first word at once when that exceeds the ring size at +0x14 of the descriptor,
  reserves the run with `atomicAddWithWrap`, stops without storing when any slot of the run is already in use, and
  otherwise copies the payload with `bcopy`, in two parts when it wraps past the end, fixing up the timestamp from the
  next slot as `log_tstamp_event` does. It stores the slot count minus one in the halfword at +6, then the event code,
  then adds the slot count to the used count and wakes a reader under the same conditions as `log_tstamp_event`.
  Inferred: read from decompiler output, with the call list and the absolute-address words checked against the fact
  sheet, and the two payload-copy branches not traced instruction by instruction.
- `timeout_get_queuehead` (`IP30/unix` `0xa800000020015514`, 580 bytes, frame 48 bytes) chooses the callout list a new
  timeout goes on and stamps the timeout with a sequence number. Its first argument is the kind (0, 1, 3 or
  4) and its second the timeout record, whose bits 31:25 of the word at +0x10 name the processor. It reads that
  processor's structure from the table at 0xa8000000204b0380 and advances the 24-bit counter in the word at structure
  +0x5a8 by one, keeping the top byte, and skipping 0 by going to 1. When the counter equals the oldest-live value at
  +0x600 it walks the list at +0x5a0 to find the next free number and stores that at +0x600. It stores the number in
  the low 24 bits of the record's word at +0x10 and converts the record's tick count at +0x0 (replaced by 1 when not
  positive; the value -100 selects the plain queue and sets it to 0): for kinds 1 and 4 it adds the converted current
  time from the unnamed routine at 0xa80000002001524c times the figure at 0xa8000000204ae420 and for kinds 0 and 3 the
  one at 0xa8000000204ae428, with the tick count clamped to 0x7fffffff. It returns the structure's address plus 0x598.
  Inferred: read from decompiler output and the dumped fact sheet; the walk that looks for a free number was not
  traced by instruction.
- `strread` (`IP30/unix` `0xa80000002012bb88`, 2172 bytes, frame 144 bytes) is the STREAMS read path for a stream
  head. The first argument is the vnode and the second the user I/O descriptor. It takes a kernel spinlock at gp+0x528
  with `mutex_spinlock`, reads the stream head from vnode +0x38, and when the head has a monitor at +0xa8 releases the
  lock with `spinunlock_pmonitor` (otherwise with `nested_spinunlock` and `splx`). If bits 0x440 of the head's flag
  doubleword at +0x20 are set it returns at once: 0x16 when bit 0x40 is set and otherwise the error word at head
  +0x4c. Otherwise it loops: it takes a message from the head's read queue with `getq` (through `RD` on the doubleword
  at head +0x0), and with none queued returns 0 for a hung-up head (bit 4), returns 0x5c when the vnode word at +0x20
  is 6 (an unreadable stream kind), and else waits with `strwaitq` and tries again, returning its error. A data
  message (type byte 0, 1 or 0x83 in the data block at +0x1e) is copied to the caller with `streams_uiomove`, whose
  error is returned after `freemsg`; empty ones are freed or put back with `putbq`; consumed blocks go to `freeb`, a
  partly read message is put back with `putbq`, and signal messages (type 0x0b) at the head of the queue go to
  `strsignal`. A file-pass message (type 9) is accepted only when bit 0x200000 of the head flags is set, in which case
  `vfile_close` is called on its file; otherwise it is put back and 0x4d is returned. Every exit calls `vmonitor`.
  Inferred: read from decompiler output and the call list; the type classification and the partial-read bookkeeping
  were not traced instruction by instruction.
- `rfscall` (`IP30/unix` `0xa8000000202d372c`, 1668 bytes, frame 288 bytes) is the client side of one NFS call. Its
  arguments are the mount record, the procedure number, the encode and decode routines and their buffers, a status
  pointer, a credential and a retry flag. It gets a transaction id from `krpc_getxid`. It returns 0x97 when bit 0x4000
  of the mount flags at record +0x130 is set, and 0x91 when bit 2 of those flags is set and the pointer at -16360 is
  nonzero and bit 0x2000 of the word at +0x94 of the structure that the doubleword at +0x318 of its target points to
  is set. It counts the call in the statistics block through the process-page pointer at -15056: the words at +0x15c
  and +0x164 plus 4 * procedure when the protocol version at record +0x208 is 3, and +0x28 and +0x30 plus 4 *
  procedure otherwise. A TCP mount (flag 0x2000) is passed to `rfscall_tcp`. Otherwise it takes a handle with `clget`
  and calls `KCLNT_CALL` in a loop, splitting the timeout at record +0x168 into tenths of a second and a remainder in
  microseconds. A status below 19 is handed to a function through a table in the data segment. Any other failure sets
  flag bit 0x20000. If the calling thread has been signalled (the same test as at entry) the routine sets bit 2,
  prints "NFS server %s not responding" the first time and returns 0x91, and with bit 0x4000 set it returns 0x97. When
  flag bit 0 is set and the retry argument is zero it doubles the timeout up to 900, sets bit 2 and prints "NFS server
  %s not responding still trying" the first time, and calls again. A status of 0 clears bits 2 and 8 of the flags when
  bit 0 is clear, and with bit 0 set and bit 2 set it clears bit 2 and prints "NFS server %s ok". Other statuses
  except 18 set bit 8 and print "NFS%d %s failed for server %s: %s" with `krpc_sperrno`. When the reply status is 13,
  no substitute credential exists, the credential's word at +0x8 is zero and its word at +0x10 is not, it substitutes
  a copy from `crdup` with +0x10 copied to +0x8 and retries; `crfree` releases the copy. Inferred: read from
  decompiler output and the call list, not traced by instruction.
- `migrate_timeouts` (`IP30/unix` `0xa800000020015c10`, 424 bytes, frame 160 bytes) moves every pending callout from
  one processor's list to another's, re-registering each in the destination. Its first argument (a0) is the source
  processor number and the second (a1) the destination; when they are equal it returns at once. It looks the source
  structure up in the table at 0xa8000000204b0380 (16 bytes a processor, pointer in the second doubleword) and works
  on the lock at structure +0x590 and the list head at +0x5a0. Each pass of the loop calls `allocate_migrate_timeout`,
  raises the level with `spl1`, takes the lock with `mutex_spinlock_spl` (passing the address of `splprof`) and pops
  the head record. When the list is empty it unlocks, restores the level with `splx` and releases the spare with
  `free_migrate_timeout`, and that call's result is what the routine returns. Otherwise it unlinks the record (head
  becomes the doubleword at record +0x8), copies its first nine doublewords to the stack, unlocks and frees the record
  with `callout_free`. It then reads the free-running counter, the doubleword at 0xffffffffaff20000, divides the
  record's first doubleword minus that count by 12500000 and passes the quotient, the word at record +0x10 and the
  spare to `add_migrated_timeout`. When bit 1 of the halfword at record +0x46 is set it calls `clock_prtimeout_nothrd`
  with the destination, the doublewords at +0x18 and +0x20, the original first doubleword, then +0x28, +0x30 and
  +0x38; otherwise `clock_prtimeout` with the destination, +0x18, +0x20, the first doubleword, the halfword at +0x42
  and the doublewords at +0x28 and +0x30. The result is stored as a word at the start of the record that
  `add_migrated_timeout` returned, the level is restored with `splx` and the loop repeats. Established.
- `chktimeout_tick` (`IP30/unix` `0xa800000020015758`, 384 bytes, frame 64 bytes) converts the counter value that
  `do_chktimeout_tick` returns into a tick count relative to the free-running counter. Its first argument (a0) is the
  kind, 0, 1, 3 or 4; the second (a1) carries the processor number in bits 31:25 (`srl` 25), and a1 together with a2
  and a3 is passed on unchanged to `do_chktimeout_tick`. It finds that processor's structure from the table at
  0xa8000000204b0380 (16 bytes a processor, pointer in the second doubleword) and, when bit 0 of the word at structure
  +0x630 is set, calls `do_chktimeout_tick` on the address structure +0x588; a nonzero result ends the search.
  Otherwise, or when the first call returns 0, it runs over processors 0 up to the word `maxcpus` and calls
  `do_chktimeout_tick` on each one that `cpu_enabled` accepts and whose flag bit is set, stopping at the first nonzero
  result. For a nonzero result the routine subtracts the doubleword at 0xffffffffaff20000, divides the difference as a
  signed value by the doubleword at 0xa8000000204ae428 for kinds 0 and 3 or by the one at 0xa8000000204ae420 for kinds
  1 and 4 (a zero divisor raises trap code 7) and leaves other kinds undivided, then replaces a result below 1 with 1.
  When no call returns nonzero it returns the register s0 unconverted: 0 once any call was made, and otherwise the
  doubleword at 0(sp) loaded in the prologue, which the routine never stores. Established.
- `startrtclock` (`IP30/unix` `0xa800000020014a2c`, 376 bytes, frame 16 bytes) programs the first real-time clock
  compare for the calling processor and returns nothing. It calls the unnamed routine at 0xa800000020016768, divides
  its result by 100 (unsigned) and stores the quotient as the word at -15088 of the process page. On the processor
  whose number (the halfword at -15456) equals `master_procid` it also divides the signed word at -14604 by 100000 and
  stores that as `cpufreq_cycles`; when `count_min_delta` is still 0 it then sets `count_min_delta` to the smallest
  count k from 1 upward for which k times `cpufreq_cycles`, summed in 32 bits, is a multiple of 125. For every
  processor it then stores 0 as the word at -15000 and reads the doubleword at 0xffffffffaff20000. It adds 249999 to
  that count, divides by 125000 and multiplies back (the multiply is shifts and adds), and stores the rounded value as
  the doubleword at -15032. That value is rounded up to a multiple of `count_min_delta` (added `count_min_delta` - 1,
  divided, multiplied) and stored to -15016 and then again to -15032. Last it calls `initcounter` with
  `cpufreq_cycles` times (that value minus the count rounded down to a multiple of `count_min_delta`), divided by 125,
  as a 32-bit argument. Divisors of 0 raise trap code 7. Established.
- `nanotime_syscall` (`IP30/unix` `0xa800000020016254`, 368 bytes, frame 32 bytes)
  stores the current time into the buffer at `a0` as a 32-bit seconds word at +0 and a 64-bit nanoseconds doubleword
  at +8, and returns the value of its final `splx`. It saves `a0` in s0, calls `spl65` (a second name for
  `splprof` at the same address) and keeps the returned level at 0(sp). It then reads a consistent set of values and
  repeats until the word at 0xa8000000204ae3e4 equals the word at 0xa8000000204ae3e0 read first: the doubleword at
  0xa8000000204ae3e8 (a base tick count), the word at +0 and the doubleword at +8 of the structure at
  0xa8000000204b03a0, the free-running counter at 0xffffffffaff20000, and `adjtime_nanos`, `adjtime_delta` and
  `adjtime_RTC` (0xa8000000204ae3f0, 0xa8000000204ae3f8,
  0xa8000000204ae400). With e = counter minus the base tick count, the adjustment is `adjtime_nanos`, except that
  while the counter is below `adjtime_RTC` plus `adjtime_delta` and `adjtime_delta` is not 0 it is `adjtime_nanos`
  times e divided by `adjtime_delta` (a signed 64-bit divide; a zero divisor would raise trap code 7). The nanoseconds
  are the low 32 bits of the structure's doubleword (taken as unsigned), plus 80 times e (e*4+e, shifted left 4), plus
  the adjustment, plus `timetrim` (the word at 0xa8000000204a735c) times e divided by 12500000. Whenever the sum
  reaches 1000000000 the code subtracts 1000000000 (adds 0xffffffffc4653600) once per loop pass (the loop body is
  written out twice) until it is below, counting the subtractions, and adds the count to the seconds word. The result
  is stored nanoseconds first at +8, then seconds at +0. If the word `time` (0xa8000000204af188) is below those
  seconds it takes `timelock` (`mutex_spinlock_spl`, second argument the address of `spl65`), reloads the seconds from
  the output, stores them to `time` when `time` is still lower, and releases the lock with `mutex_spinunlock`. Last it
  calls `splx` with the saved level. Established.
- `du_conpoll` (`IP30/unix` `0xa80000002014813c`, 368 bytes, frame 32 bytes)
  polls the console port for an input byte and calls the debugger when that byte is 1; it takes no argument. It
  returns at once when the halfword `kdebug` (0xa8000000204a80da) is 0, when the word `console_is_tport`
  (0xa8000000204ae580) is nonzero, or when the doubleword at -16352 of the process page is 0. It also returns when
  `spinlock_islocked` reports `strhead_monp_lock`, `str_intr_lock` or the lock at
  `streams_mon`+16 held. When the word `console_device_attached` (0xa8000000204ae584) is 0, or the doubleword
  `the_console_port` (0xa8000000204aeda8) is 0, it calls `console_debug_poll` and returns that result. Otherwise it
  needs the byte at -16305 of the process page to equal 1, then calls `sio_lock_port` with the port, 1 and that byte;
  a zero result returns. With the port locked it subtracts the word at 0xa8000000204aedbc from the low 32 bits of the
  counter at 0xffffffffaff20000; when that difference is not above `timer_freq` (the word at 0xa8000000204ae40c) it
  calls `sio_unlock_port` and returns, and otherwise it stores the new low word to 0xa8000000204aedbc. If the
  doubleword at port +16 is nonzero and its halfwords at +12 and +14 do not differ by exactly 0x100, it calls the
  unlabelled routine at `0xa800000020144ac8` and then unlocks and returns: the compare after that call reads a stack
  word that is 0 on this path, so its branch to the unlock is always taken. In every other case it calls the function
  at +72 of the doubleword at port +0 with the port, the address of 0(sp) and 1; a result of 0 or less unlocks and
  returns. A positive result is added to the word `du_chars_lost` (0xa8000000204aedb8). A byte at 0(sp) equal to 1
  then unlocks and calls `debug` with the string "ring"; any other byte unlocks and returns. The value left in v0 is
  whatever the last call returned, apart from the early returns: v0 is the nonzero `console_is_tport` word, or
  0xffffffffaff20000 when `sio_lock_port` returned 0 (the delay slot of that branch builds it), or the nonzero
  `spinlock_islocked` result. Established.
- `timein_body` (`IP30/unix` `0xa8000000200159f4`, 364 bytes, frame 96 bytes)
  runs the expired entries of a timeout queue described by the record in `a0`, and returns the value of the last
  `mutex_spinunlock`. The record's lock is at +8 and the head of the list at +24. Every pass takes the lock with
  `mutex_spinlock_spl` (second argument the address of `spl65`) and reads the head. A null head releases the lock and
  returns. Otherwise it compares the head entry's doubleword at +0 (the expiry) with the free-running counter at
  0xffffffffaff20000. When the counter has not reached it, `set_timer_intr` is called with the word at record +168
  shifted right 16, the expiry, and 0; a nonzero result unlocks and returns, while a zero result falls through to run
  the entry anyway. Running an entry unlinks it (the entry's doubleword at +8 becomes the head). If the halfword at
  entry +70 has bit 1 clear, `timein_entry_ithrd` is called with the record, the entry and the saved level, and the
  loop restarts at the lock call. If bit 1 is set, the entry's word at +16 is copied to record +104, 1 is stored at
  record +88, the lock is released, `timein_entry` is called with the entry, and `test_and_set_int64` (an atomic swap)
  stores 0 at record +88. When the value it returns, the old word, is 2 the code locks again, calls `sv_broadcast` on record +112 and unlocks;
  either way it loops. Established.
- `nanotime` (`IP30/unix` `0xa8000000200163c4`, 228 bytes, no frame)
  reads the current time into the buffer at `a0`, a seconds
  word at +0 and a nanoseconds doubleword at +8, without raising the interrupt level or taking a lock. When the
  doubleword at 0xa8000000204ae3e8 (the base tick count) is zero it stores a zero word at +0 and a zero doubleword at +8
  and returns. Otherwise it reads a consistent set, retrying while the word at 0xa8000000204ae3e4 differs from the word at
  0xa8000000204ae3e0 read first, with a `sync` before and after: the base tick count, and the word at +0 and the doubleword
  at +8 of the structure at 0xa8000000204b03a0. It forms the nanoseconds as the low 32 bits of that doubleword taken as
  unsigned plus 80 times the number of counter ticks since the base (the counter is the doubleword at 0xffffffffaff20000; the
  factor 80 is built as e*4+e shifted left 4). That sum is compared with 1000000000 using a first reading of the counter, but the sum that is stored
  uses a second reading taken after the compare. When the first sum was below 1000000000 the second sum is stored as
  it is. Otherwise 1000000000 is taken off at least once (an add of 0xffffffffc4653600) and again while the result is
  still not below it, and the seconds word is raised by one for each subtraction. The nanoseconds go to +8 first and the
  seconds to +0 afterwards. Unlike `nanotime_syscall` it applies no `adjtime` term and no `timetrim` term, does not touch the
  `time` variable and takes no lock. Nothing is returned. Established.
- `ftrc_event` (`IP30/unix` `0xa8000000200b72ac`, 324 bytes, frame 176 bytes) appends one 64-byte event record to a trace ring.
  The arguments are the trace handle (`a0`), a byte value (`a1`), a doubleword that must be nonzero (`a2`) and five more
  doublewords (`a3` to `a7`) plus a ninth that is read from the caller's stack at 176(sp). When the word at 0xa8000000204a79f8 is zero it first
  calls the unnamed routine at 0xa8000000200b6eac, which sets that word to 1 and runs `spinlock_init` twice. A null handle or
  a zero `a2` returns -1, as does a handle whose doubleword at +0x10 (the ring) is zero. Otherwise it takes `mutex_spinlock` on
  the ring's lock at ring +0x40, reads the free-running counter at 0xffffffffaff20000 and stores it at ring +0x8, takes the
  slot from the write pointer at ring +0x30 and moves the pointer on by 64. When the new pointer is not below the limit at
  ring +0x28 it sets the word at +0x3c to 1 and resets the pointer from ring +0x20. It releases the lock with
  `mutex_spinunlock`, clearing the first byte of the claimed slot in that call's delay slot, and then fills the slot
  outside the lock in this order: the counter's low 32 bits as a word at +4, the ninth argument at +0x38, `a7` at +0x30, `a6` at
  +0x28, `a5` at +0x20, `a4` at +0x18, `a3` at +0x10 and `a2` at +0x8 (each a doubleword), `a1` as a byte at +1, the
  processor number (halfword at -15456) at +2, and last the low byte of the handle's word at +0x8 at +0 in the delay slot of the
  branch to the exit. It returns 0 on that path. Established.
- `uuid_create` (`IP30/unix` `0xa800000020214308`, 320 bytes, frame 48 bytes) builds a version 1 time-based identifier of 16
  bytes in the buffer at `a0` and stores a status word through `a1`. It takes `mutex_lock` on the lock whose address is the pool
  word at 0xa8000000204ac630, with 25 as second argument. State lives in `.sbss`: a started byte at 0xa8000000204afb40, a
  have-address byte at 0xa8000000204afb41, six node bytes at 0xa8000000204afb42, the last time as a doubleword at
  0xa8000000204afb48 and a clock sequence halfword at 0xa8000000204afb50. On the first call it calls `nanotime` into a stack buffer and computes seconds times 10000000 plus nanoseconds
  divided by 100 plus 122192928000000000 (the doubleword at 0xa8000000204a8e80), keeps that as the starting time, sets the
  started byte and builds the clock sequence from the low 12 bits of the counter at 0xffffffffaff20000 ORed with 0x8000.
  Every call then adds 1 to the time, and stores in order the clock sequence halfword at out+8, the low 32 bits of the
  time as a word at out+0, the time back into state, bits 47:32 as a halfword at out+4 and bits 59:48 ORed with 0x1000 as a
  halfword at out+6 (in the delay slot of the test that follows). When the have-address byte is zero it calls `get_eaddr`
  with the node bytes' address and stores the low byte of the result in that byte; a zero result calls `mutex_unlock`
  and stores 0x16c9a08b through `a1` (in the delay slot) and returns that call's result without writing the node field.
  Otherwise it unlocks, copies the three halfwords of the node to the output at offsets 10, 12 and 14 and stores a zero word through `a1`.
  The return value is whatever `mutex_unlock` left. Established.
- `xthread_periodic_timeout` (`IP30/unix` `0xa80000002019195c`, 228 bytes, frame 32 bytes) starts a periodic kernel thread
  whose record is the structure in `a4`. If bit 0x800 of the word at record +0x0 is already set it returns at
  once and stores nothing. Otherwise it stores the word 0x200 at +0x0, then `a5` at +0x28, `a6` at +0x30 and `a2` at
  +0x38, and calls `xthread_table_name_get_property` with `a0` unchanged, 2 as second argument and `a3` as third. The result
  is stored as a halfword at +0x4a; its low 16 bits sign-extended give a processor number, and -1 is replaced by the
  running processor (halfword at -15456). That number is stored as a halfword at +0x48. The routine then looks up that
  processor's record in the table `pdaindr` (0xa8000000204b0380, 16 bytes per processor, the pointer at +8) and, when bit 0x800
  of its word at +0x48 is set, or when that is clear and its word at +0x658 is nonzero, replaces the halfword at +0x48
  with `clock_processor` (0xa8000000204af8e8). It calls `xthread_setup` with the first two arguments as received, the
  record twice (third and fifth arguments) and 0xa80000002019183c as fourth. Last it stores the free-running counter at
  0xffffffffaff20000 at +0x40, in the delay slot of the call to the unnamed routine at 0xa8000000201918a8, and returns that
  routine's result. That routine does nothing unless bit 0x800 of the record's first word is set. Its own callees are, in order, `valusema` on the semaphore at +0x8,
  `vsema` (only when that count is not above 0) and `clock_prtimeout_nothrd`. Between them it adds the doubleword at +0x38 to the one at
  +0x40, and the timeout it arms is given the record, the routine itself as callback and a processor: the halfword at +0x48
  when that is the running processor and its record passes the same two tests above, and otherwise
  `clock_processor` (stored back at +0x48). Established.
