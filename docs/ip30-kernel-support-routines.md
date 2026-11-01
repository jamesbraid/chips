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
