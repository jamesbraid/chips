# Kernel routines that read the Hub real-time counter for entropy (IP27 build)

Two routines of the IRIX 6.5.30 IP27 kernel (`IP27/unix`) are not Hub drivers but read the Hub's real-time counter, the doubleword at
`0x9200000001030100` (the processor-interface local alias, offset 0x30100), and hand its low 32 bits to the random-input routine
`randproc_input`. They are the STREAMS stream-head read routine and the NFS client's remote-call routine. Each entry was read from the
linked kernel; addresses are the kernel's own. The counter read is the only register access of either routine.

- `strread` (`IP27/unix` at 0xc00000000015f5e8,
  2172 bytes) is the read side of a STREAMS stream head. It takes the stream's file object in `a0` (the head pointer is the
  doubleword at +0x38) and the I/O descriptor in `a1` (flags at +0xc, remaining byte count at +0x20, a `uio` for
  `streams_uiomove`). It takes the global lock at `gp + 0x1360` (`strhead_monp_lock`) with `mutex_spinlock`, drops it with
  `spinunlock_pmonitor` (or `nested_spinunlock` and `splx` when the head is gone) and works under the head's own monitor,
  released with `vmonitor` on every exit. In the loop it takes the next message with `getq` from the head's read queue; with none
  it returns 0 when the head flags (doubleword at +0x10) say hung up (0x10), when a data copy was already done and bit 0x1000000 is
  clear, or when the no-delay mark is set, returns 0x5c (92) when the file's type word at +0x20 equals 6, and otherwise sleeps in
  `strwaitq` (mode 2, flags from +0xc, the count at +0x20) and then calls `randproc_input` with the low 32 bits of the doubleword at
  `0x9200000001030100` (the Hub real-time counter, `PI` offset 0x30100) ORed with `0x300000000`, so each wake-up feeds the
  counter to the random pool; an error from the wait or a nonzero wake status is returned, with error 11 turned into 0 when flag
  bit 2 of the descriptor's flags and bit 0x20000 of the head flags are both set. A message is classified by the type byte at +0x1e
  of its data block: 0 is ordinary data, which is copied out with `streams_uiomove` piece by piece (freeing each exhausted block with
  `freeb`, returning the mover's error after `freemsg`, requeuing a remainder with `putbq` unless the head is in a mode that
  discards it, and delivering pending signal messages of type 0xb with `strsignal`); types 1 and 0x83 are skipped or stripped
  depending on mode bits 0x100000 and 0x200000; type 9 returns 0x4d (77) after `putbq` unless it can be consumed with
  `vfile_close`. It returns 0 for end of message with a zero-length block. It writes no device register.
  Inferred: the message-type meanings and error names, because the routine was read through its calls and constants and the
  data-block layout is not documented here.
- `rfscall` (`IP27/unix` at 0xc0000000003257c0,
  1668 bytes) is the NFS client's remote-call routine for one request. It takes the mount record in `a0` (flags word at +0x130,
  timeout in tenths of a second at +0x168, retry count at +0x16c), the procedure number in `a1`, three more descriptor
  arguments, a result-status pointer, the caller's credentials in the seventh argument and a flag in the eighth. A mount flag of 0x4000
  returns 0x97 at once; flag 0x2000 hands the whole call to `rfscall_tcp`. Otherwise it takes a transaction number from `krpc_getxid`,
  counts the call in two statistics tables (the record at -0x3a80 of the process page, indexed by the procedure number), and loops:
  `clget` obtains a client handle (its error is returned when it gives none) and `KCLNT_CALL` sends the request with the timeout
  split into seconds (timeout / 10) and microseconds ((timeout % 10) * 100000) and a retry count (1 for a soft mount whose flag 8
  is set, else the record's count, at least 1). A call status below 19 goes through a `jr` table at 0xc0000000003f7b60 (19 entries:
  status 0, 18 and 10 each have their own target, statuses 1, 2, 6 to 9 and 11 share one and 3 to 5 and 12 to 17 another); a higher status takes the
  timeout path. The paths set or clear bit 2 of the mount flags with `ll`/`sc` and print, through `printf`, "NFS server %s not responding"
  (when the bit was clear), "NFS server %s not responding still trying" and "NFS server %s ok"; a hard mount (flag bit 0) doubles its
  timeout up to 900 tenths between retries, and a process being interrupted (mask 0x2000 in word +0x94 of the process's block) returns 0x91. When
  mount flag 0x8000 is set it calls `randproc_input` with the low 32 bits of the doubleword at `0x9200000001030100` (the Hub real-time counter)
  ORed with `0x400000000`, so each call feeds the counter to the random pool. When the reply is error 13 and the credential's two ids
  differ it duplicates the credentials with `crdup`, copies the second id over the first and retries once, freeing the copy with `crfree`.
  A static routine at 0xc0000000003255e8 releases the client handle on every exit. Inferred: what each branch of the status table does, since
  the table's targets were read only as far as the messages above, and the credential retry.
