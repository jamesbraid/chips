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
