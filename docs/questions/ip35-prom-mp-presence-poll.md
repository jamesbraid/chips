# IP35 PROM: how the processors publish presence and what ends their waits

Question. During multi-processor start-up of an IP35 node (Bedrock, up to two processor interfaces with two
processors each), each interface publishes bits in a scratch register of the I/O block and every processor then
polls it. What ends the poll (a time limit, an expected value, a retry count), what happens to a processor that
never shows up, and does the PROM rewrite the memory-controller configuration while other processors run?

Method: disassembly of the shipped IP35 PROM image (SGI Version 6.210, built Aug 26 2004; container segment
`ip35prom`, load and entry 0xc00000001fc00000, length 0x1686a8, additive checksum ok; unpacked segment sha256
554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b). Addresses are image addresses in the style of
[ip35-reset-window.md](ip35-reset-window.md): physical 0x1fc0xxxx, offset into the unpacked segment = address -
0x1fc00000. The PROM has no symbols, so routines are named here by what they do. Constants were folded by hand
from the global pointer table (gp = 0xc00000001fd6f740, set at 0x1fc01920; table words are read from segment
offset gp + displacement). Nothing was run. The behavior that prompted the question (a processor reading the
scratch register thousands of times while the other interface had not published) was seen in a model run, not on
hardware; it was used only to choose what to read.

Offsets used, from the local register view (0x1000000 is processor interface 0, "PI"): PI+0x20 reads the
processor's slice number, 0 to 3 (A, B on the first interface, C, D on the second; the routine at 0x1fc6b530);
PI+0x40 and +0x48 are the "slot fitted" words; PI+0x50 and +0x58 are the per-processor enables; PI+0x90 modifies
and PI+0xa0 reads the second bank of pending-interrupt bits; PI+0x108 and +0x110 are the two real-time compare
registers; PI+0x30100 is the real-time counter; I/O block (0x1400000) +0x150 and +0x158 are called scratch 0 and
scratch 1 below; local block (0x1600000) +0x8058 (test and set read) and +0x8018 (store 0) are the node lock;
memory controller (0x1780000) +0x8 is the configuration word and +0x10010 doubles as a bit-mask semaphore.
The pointer table holds these as 0x9200000001400150 (scratch 0, table word at segment offset 0x1679f8),
0x92000000010000a0 (PI+0xa0), 0x9200000001000090 (PI+0x90) and 0x9200000001790010 (the semaphore word).

## Answer

1. **What ends the poll. Established: value conditions with no time limit; the one retry count and the one
   timer are listed below.**
   Bit for slice n in scratch 0 is `0x10 << n` (0x10, 0x20 for A, B and 0x40, 0x80 for C, D; the shift count is
   the value of PI+0x20).
   - Publication (routine 0x1fc69234, run by every processor). Each processor stores the marker 0x24 in its own
     real-time compare register (0x1fc69274), then reads the partner's compare register up to 0x30d40 = 200,000
     times looking for the same 0x24 (0x1fc692e0 to 0x1fc692fc). That is a retry count of register reads, not a
     clock limit. If the interface's two slots are not both fitted (PI+0x40 and +0x48) the wait is skipped.
     On a match the even slice (A or C) takes the node lock, ORs its own bit and then its partner's bit into
     scratch 0 as two separate read-modify-writes (0x1fc693ec to 0x1fc69428) and releases the lock; the odd slice
     waits 1000 counter units and returns without writing.
   - After publication every processor waits a fixed 2000 counter units (0x1fc69a30, delay routine 0x1fc6b79c).
     That is the only time-based wait in the sequence and nothing is read while it runs. The unit is the PROM's
     own conversion of real-time counter ticks (counter times (field + 2) / 200, field from local block +0x4200
     bits 13:4, routine 0x1fc6b73c); microseconds is inferred.
   - The pair rendezvous (routine 0x1fc445c0) and the cross-interface rendezvous (routine 0x1fc68fe0, which calls
     the first) are called many times from the main routine, first at 0x1fc69a40. Their polls read scratch 0 on
     each pass and have no counter and no deadline.
     Pair rendezvous: the partner of slice n is slice n xor 1. Each processor raises a flag in the second pending
     bank (even slice: bit 49 by a store of 0x171 to PI+0x90; odd slice: bit 48 by 0x170), waits to see the
     partner's flag in PI+0xa0, lowers its own (0x71 or 0x70) and waits to see the partner's flag drop. Both
     waits end early when the partner's bit in scratch 0 is zero. The odd slice's first wait is at
     0x1fc4461c to 0x1fc44634 (one scratch 0 read and one PI+0xa0 read per pass), the even slice's at 0x1fc446dc
     to 0x1fc446f4.
     Cross-interface rendezvous: the first interface's processors raise bit 0 of scratch 1 and the second's
     raise bit 1, each under the semaphore word (acquire 0x1fc5fef0 through 0x1fc33598, release 0x1fc5fd98). A processor waits for the
     other side's flag only while the other side's presence bits are nonzero (the second interface's 0xc0 for the
     first side, loops at 0x1fc690a4 and 0x1fc691c8; the first interface's 0x30 for the second side, loops at
     0x1fc69158 and 0x1fc6920c), and leaves when the flag is seen or the bits go to zero.
   So the exit is a value condition on the partner's presence bit and flag. No routine builds an expected mask
   from the fitted words or from configuration: "present" means "its bit in scratch 0 is set at the moment of the
   test", and the sole test of "is anybody ahead of me" is the election routine 0x1fc68f64, which returns true when
   no lower slice's bit is set. A processor whose partner has published but never arrives therefore waits for
   ever in the pair rendezvous. The 200,000-read count is the only bounded wait and it is in the marker step,
   before publication.
   The node lock acquire (0x1fc641d4) also has a limit: after 10,000,000 counter units it clears the lock itself
   and carries on.
   Grade: **established** for loops, exit conditions and the two numeric bounds (the routines were read to their
   returns). **Inferred**: that PI+0xa0 bits 48 and 49 are the second-bank pending bits the 0x170/0x171 stores
   set (from the layout of the modify word the interrupt code uses: bit 8 set, bit 6 bank, bits 5:0 number); the
   counter unit; that the model run's repeated reads belong to the loop at 0x1fc4461c (same register pair, same
   partner-present condition; no program counter was traced). **Settling test:** on any engine that runs the
   unmodified PROM, log each processor's program counter with every read of scratch 0 and PI+0xa0, with one
   interface's first processor held for longer than 2000 counter units; the prediction is that the other
   interface elects itself master and that waiting processors sit between 0x1fc4461c and 0x1fc44634 until the
   partner raises its flag.

2. **On timeout. Established for the marker wait; no timeout exists for the rendezvous waits.**
   If the 200,000 reads do not find the marker, or the interface has an empty slot, the waiting processor
   stores 0 to the partner's enable register (PI+0x58 for slices A and C, PI+0x50 for B and D; 0x1fc693c4 and
   0x1fc69320), takes the lock, ORs only its own bit into scratch 0 (0x1fc6933c to 0x1fc69364), releases the lock
   and returns the last value it read from the partner's compare register. The main routine reports that the
   partner died when that value is positive (0x1fc6a338 to 0x1fc6a364) and continues. So the partner is marked
   absent in two places: its bit is never published and its enable register reads zero.
   Nothing marks a whole interface absent: the rendezvous waits have no timeout, and they skip an interface
   whose bits read zero.
   Count: the PROM prints no "N processors found" line (no such text is in the image). It builds a
   configuration record per fitted slot (loop at 0x1fc5fe68 to 0x1fc5fe9c over PI+0x40 and +0x48, builder at
   0x1fc54170); the record's enabled byte is `enable register != 0` (0x1fc54230 to 0x1fc54258), so the enable
   store above lowers the enabled count; a slot published late is still listed and enabled. The scratch 0 population
   count (routine 0x1fc647c8) is used at 0x1fc1a9f8 and 0x1fc6b274 on error paths and at 0x1fc5f154 passed to
   another routine (recipient not followed). Grade: **established** that the enable store happens and that the
   record reads that register; **inferred** that an operating system's processor count derives from the enabled
   byte (the kernel was not read for this question). **Settling test:** boot the PROM with the partner's marker
   store suppressed and compare the configuration records' enabled bytes with the operating system's count.

3. **Memory-controller configuration while other processors run. Established: the PROM rewrites it in a
   master-only step while the node's other processors are inside the rendezvous polls, not halted.**
   The master-only memory step is guarded by the election at 0x1fc6a800 to 0x1fc6a808 (non-masters branch to
   0x1fc6a8f0) and reaches memory initialisation at 0x1fc6a8a0 (routine 0x1fc6587c). The configuration word
   (+0x8, reached through the node-indexed alias at +0x1f80008 plus the node number shifted left 33) is rewritten by
   a read-modify-write that clears per-bank fields and sets bits 58:56 to 7 (store at 0x1fc54f14), by a
   write that places a caller-supplied value at bit 32 and sets 58:56 to 7 (store at 0x1fc56e28, routine
   0x1fc56d94, called from 0x1fc65aa4, 0x1fc65b38 and 0x1fc65b4c: the bank-0 swap path) and by the sizing code's
   store at 0x1fc57c20.
   What the other processors do meanwhile: a non-master goes from the election straight into the rendezvous
   routine at 0x1fc6a8f0 and stays in its polls until the master reaches the same call after the memory step
   (the pair partner leaves when the master's flag is raised; the other interface's processors leave when the
   scratch 1 flag appears). Between entering and leaving, a parked processor executes only the register reads,
   the semaphore and flag stores above and its own stack accesses. Nothing on the path from reset to the memory step
   halts, resets or stops a processor, so they run throughout (inferred that every fitted, enabled processor
   left reset together: no PROM code starts a processor). The stack is not in main memory at this point
   (inferred from the stack-switch steps that follow the memory step; not traced).
   Not established: whether a later routine rewrites the word after the others are released (the helpers at
   0x1fc65478 and 0x1fc655d8, called at 0x1fc6a8d8 and 0x1fc6a8e8, and the command-driven memory test at
   0x1fc578ec were not read to the end), and nothing is known about nodes other than the boot node.
   Grade: **established** for the stores, their guard and the parked state of non-masters on the normal path;
   **inferred** for the stack location and for simultaneous release from reset. **Settling test:** log, per
   processor, each store to the configuration, directory-configuration (+0x40000) and ECC-configuration
   (+0x60000) registers of the memory controller with each processor's rendezvous state across a boot.

## Sites

| What | Image address | Grade |
|---|---|---|
| slice number read, real-time count, delay | 0x1fc6b530, 0x1fc6b73c, 0x1fc6b79c | established |
| node lock acquire (10,000,000 unit limit), release | 0x1fc641d4, 0x1fc641b8 | established |
| marker wait, partner disable, publication | 0x1fc69234 to 0x1fc69434 | established |
| post-publication delay | 0x1fc69a30 | established |
| pair rendezvous | 0x1fc445c0 to 0x1fc44750 | established (bit meaning inferred) |
| cross-interface rendezvous | 0x1fc68fe0 to 0x1fc69230 | established (intent inferred) |
| election | 0x1fc68f64 | established |
| presence count | 0x1fc647c8 | established |
| configuration record per fitted slot | 0x1fc5fe00 to 0x1fc5fea0, 0x1fc54170 | established |
| memory step and configuration word stores | 0x1fc6a8a0, 0x1fc54f14, 0x1fc56e28, 0x1fc57c20 | established |

## PROM 6.211 (patch 7208) check

Established. The marker-wait routine in 6.211 starts at 0x1fc6922c (8 bytes earlier than in 6.210) and is
word-for-word identical to 6.210's 105 words except seven `jal` targets, which move with the shifted tail. The
retry bound 0x30d40 is built at 0x1fc692d8 and 0x1fc692e0, the compare registers at 0x1fc692ac and 0x1fc692b8, and
the partner-enable stores at 0x1fc69314 and 0x1fc693c0. Method: `hostfacts.py` on both payloads and a word compare
of the two routines. The bound therefore holds for both shipped CPU PROMs.
