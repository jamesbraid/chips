# IP35 PROM: the reset barrier, boot-master election, progress registers and interrupt-line self test

Question. When the processors of an IP35 node leave reset, how does the shipped PROM make them agree on one boot
master and on who is present before the first rendezvous? Specifically: which stores does every processor make to
the local block's scratch registers, how is the master chosen, what exactly releases the others and what do they
test, what read-modify-writes follow, which delays in the sequence count instructions and which count the
real-time counter, where do progress codes go, and how does the PROM check that the processor interface's pending
bits reach the processor's interrupt lines?

Method: disassembly of the shipped IP35 PROM image (SGI Version 6.210, built Aug 26 2004; container segment
`ip35prom`, load and entry 0xc00000001fc00000, length 0x1686a8, unpacked segment sha256
554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b) and the 6.211 image (built Jan 25 2008,
sha256 25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271). Addresses are 6.210 image addresses (style
of [ip35-reset-window.md](ip35-reset-window.md)). Register names follow the offsets in
[ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md): "PI" is the processor interface at 0x1000000
(local form), "II" the I/O block at 0x1400000, "LB" the local block at 0x1600000, "MD" the memory controller at
0x1780000. Instruction text was read with the retools Capstone decoder (`tools/hostfacts.py`). Nothing was run.
The kernel citation (item 12) is to the IRIX 6.5.30 IP35 kernel at link addresses.

## Answer

1. **Which path runs the barrier. Established.**
   The reset vector parks the old Status register in CP0 register 17 (0x1fc00418) and tests it at 0x1fc00458 to
   0x1fc00464 against 0x180000 (bits 20 and 19: soft reset and NMI). Neither bit set, or bit 19 alone, goes to
   0x1fc00644, which tests bit 20 again (0x1fc0064c) and, when it is clear, continues on the **cold path** to
   0x1fc00780 (the path with the stores below). Bit 20 set without 19 goes to 0x1fc01bac, a path that rebuilds the
   TLB, stores zero to MD +0x790010, stores the Status register in the processor's progress doubleword (item 9) and reports
   on the console; it does not touch LB scratch 1 (read to 0x1fc01cf0; the rest of that path was not followed). Both bits set
   falls through to an NMI sequence at 0x1fc0046c. So a processor started by a soft reset does not make the
   cold-path stores of item 2.

2. **The stores every processor makes on the cold path. Established.**
   At 0x1fc007b8 to 0x1fc007ec, with no election yet, every processor stores all ones to LB scratch 0 (0x1608000,
   0x1fc007d4) and zero to LB scratch 1 (0x1608008, 0x1fc007ec). These come after the progress code 0x60 (0x1fc007b4)
   and before a call to the master-only set-up routine (0x1fc008e4).

3. **Boot-master election. Established (routine 0x1fc01284 to 0x1fc01370; called at 0x1fc008ec and again at 0x1fc01a28).**
   The routine reads the processor's slice number (PI +0x20; bit 0 slot A or B, bit 1 interface 0 or 1) and the
   present words (PI +0x40 for slot A, +0x48 for slot B) and returns 1 for the master:
   - interface 0, slot A: master.
   - interface 0, slot B: master only when PI +0x40 (slot A present) reads zero.
   - interface 1: not master when either of interface 0's present words, read through the **node window**
     (0x9200000001800040 and +0x48), is nonzero; otherwise slot A is master and slot B is master only when its own
     interface's +0x40 (read through the local form 0x1000040) is zero.
   So the master is the lowest present slice in A-B-C-D order. The PROM relies on two properties of the register
   windows, both **inferred** as hardware facts because only the PROM's use shows them: the local form at 0x1000000
   answers from the *requesting* processor's own interface (a processor on interface 1 reads bit 1 of +0x20 set and
   its own +0x40 there), and the node form at 0x1800000 reaches interface 0.

4. **Master-only set-up before the release. Established for the first 0x80 bytes of routine 0x1fc01a24.**
   After the election the master stores 0x10001 to II +0x1f8, stores 0xff01 to II +0x110, then reads II +0x128 and
   tests bit 13 (0x1fc01a44 to 0x1fc01a9c); the branch taken when bit 13 is clear (0x1fc01b84) was not read.
   Non-masters return at 0x1fc01a38 before any of this.

5. **The release and what the others test. Established.**
   The master stores 0x07f80000 to LB scratch 1 (0x1fc0125c, called at 0x1fc008fc). Every other processor calls
   0x1fc01228 (at 0x1fc0090c) and spins on `(LB scratch 1 & 0x07f80000) != 0` (0x1fc01238 to 0x1fc0124c): **any** bit
   of the mask ends the wait, not equality with 0x07f80000. The loop has no counter, no timer and no write.
   A processor whose scratch 1 value never gains one of those bits waits for ever.

6. **What follows the release. Established.**
   All processors, master included, continue to the main routine (0x1fc698dc) and, at its start:
   - store zero to the four doublewords of the MD semaphore block at 0x1790000, +8, +0x10 and +0x18
     (0x1fc699c4 to 0x1fc699e4), unconditionally and before the election at 0x1fc69a50;
   - read LB scratch 1, clear bits 0x07f80000 and store it back (0x1fc699e8 to 0x1fc69a00), a **read-modify-write**,
     not a store of zero. With only the release value in the register the result is zero; any other bit would be kept;
   - when a saved PROM setting that disables the I/O interface exists (lookup at 0x1fc69950, a negative result means
     absent), OR 2 into II scratch 0 without the hub lock (0x1fc69974 to 0x1fc69980), so every processor does this
     read-modify-write of the register that later carries the presence bits in 7:4 (item 1 of the presence-poll page).
   A processor that reaches these two steps after a peer has already used the semaphore block (see
   [ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md) item 3, which names +0x10010 a semaphore) erases the
   peer's hold: the PROM depends on all processors reaching this point together.

7. **Delays: one counts instructions, one counts the real-time counter. Established.**
   Routine 0x1fc040e0 is a two-instruction countdown (`bne $4,$0,self; daddiu $4,$4,-1`): its argument is a
   **loop count**, not a time. The main routine calls it with 500 at 0x1fc69a0c and is wrapped in a check: it reads the
   real-time counter (0x1fc6b73c) before and after and, when the counter did not advance (`before < after` false,
   0x1fc69a18), reports a failure (0x1fc6ad54 to 0x1fc6ad70) and then continues
   to the pair publication (0x1fc6ad78 back to 0x1fc69a24). So this step needs the counter to move by at least one tick
   during 500 loop iterations, and nothing more. The delays that count the counter are the routine at 0x1fc6b79c
   (argument 2000 at 0x1fc69a30, 1000 inside the publication) and the lock's 10,000,000-unit limit; see
   [ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md). Another loop-count delay is scaled by a small index:
   0x1fc688a4 to 0x1fc688b0 waits 100 times a value between 0 and 3 (inferred to be the slice number) iterations
   before a processor re-enters a poll, and 800 iterations on the other exit (0x1fc6888c): established, purpose
   inferred (back-off).

8. **Skew the barrier tolerates. Established for the count, inferred for its meaning.**
   Between a processor's cold-path clear of scratch 1 (0x1fc007ec) and the master's release store (0x1fc008fc) the
   master runs 68 instructions in line plus two calls (0x1fc01580 and 0x1fc01a24, not counted). A processor whose
   clear lands after the release is the only way the poll in item 5 can miss it. The code gives no sign that
   processors are expected to leave reset at different times: no wait, no retry, no check that all clears landed.
   **Inferred**: the processors share one reset and leave it on the same clock edge, so that every clear precedes the
   release by construction. No timing figure for the skew between processors is held. Route: a measurement on
   hardware or a processor-module reset specification.

9. **Progress codes. Established for the writes, unknown for the target registers' behaviour.**
   Through the cold path and the main routine the PROM writes small progress codes (0x5e, 0x5f, 0x60, 0xb4, 0x5d,
   0x03 at 0x1fc00454, 0x1fc0068c, 0x1fc007b4, 0x1fc00730, 0x1fc0089c, 0x1fc0094c ...) to two places per code:
   - the processor's own real-time compare register: 0x9200000001000108 plus 8 times the slot (slice bit 0), a doubleword
     store; the main routine stores 13 there at 0x1fc69918 and the publication routine stores 0x24 as the pair marker in
     the same register (0x1fc69274);
   - a doubleword at physical 0x100000c0 plus 8 times the **whole** slice number (0x1fc00750 to 0x1fc00774, and the
     helper at 0x1fc6b54c, whose argument is the code; the main routine's later codes 0x28 and 0x38 at 0x1fc69a38
     and 0x1fc69a4c go only through the helper). The address is 0x9000000010000000 + 0xc0 (attribute 0, the
     node-local space that also holds the boot flash at +0x18000000); it is not a processor-interface register.
   Whether a compare register being written with such codes raises the real-time interrupt depends on a comparator
   rule not read here; whether the 0x100000c0 doublewords are plain storage is **unknown**. Route: the
   behaviour of those four doublewords is not read by any PROM routine found; trace a hardware boot.

10. **The processor-interface interrupt-line self test. Established (routine 0x1fc65bbc, 0x240 bytes; called at 0x1fc6a7e0
    by the processor whose slice number equals a loop index; inferred to run one processor at a time).**
    Mask and unmask are read-modify-writes of the calling processor's own interface in the local form: level L < 64 uses
    PI +0xa8 (slot A) or +0xb8 (slot B), level L >= 64 uses +0xb0 or +0xc0 with bit L - 64; routine 0x1fc62660
    clears the bit (mask), routine 0x1fc628a4 sets it (unmask).
    The test then does, for pending-bank 0 and then bank 1:
    a. bank 0: store 0x13f to PI +0x90 (modify write with bit 8 set, bank 0, level 63: set the pending bit), unmask
       level 63, wait for the CPU Cause register to show **only** interrupt line IP2 (value 0x400 in the field 0x3c00);
       store 0x3f (clear), wait for the whole field to read zero; mask level 63;
    b. bank 1: unmask level 64, store 0x140 to PI +0x90 (set bank 1 bit 0), wait for the field to read exactly 0x800
       (IP3 only); store 0x40 (clear), wait for zero; mask level 64.
    Each wait (routine 0x1fc62818) reads CP0 Cause through a jump-table routine (0x1fc03c40, register 13) at most 64
    times; it ends as soon as the target bit matches the expected value, and then requires the **whole** field
    Cause bits 13:10 (0x3c00) to equal the expected value; any other line pending at that moment (IP3 for the first
    test, IP4 the real-time interrupt, IP5 the profiling interrupt) fails the step with -1. A failure prints the
    values and a local-block scratch 1 field (bits 58:43) and returns the failure to the caller (0x1fc6a7e8).
    Consequences, all established as what the PROM expects: a set pending bit with its mask enabled must drive Cause
    IP2 (bank 0) or IP3 (bank 1) within 64 reads of Cause; a clear must drop it within 64 reads; no other interrupt
    line may be pending in between. Mode 2 of the argument returns at once (0x1fc65bd4); mode 3 takes a different
    failure print (0x1fc65e94 and 0x1fc65ed4, not read).

11. **Levels the PROM uses for its own signalling. Established for the writes; meaning of 12 to 17 unknown.**
    The pair rendezvous raises and lowers bank 1 bits 48 and 49 with modify writes 0x171, 0x170, 0x71 and 0x70
    through the local form ([ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md) item 1), so both slots of
    one interface see each other's flags in PI +0xa0 and the pending banks are per interface, not per slot. The
    Three small helpers also use bank 0 bits indexed by the processor's slot (slice bit 0): 0x1fc3d140 returns 1 when
    PI +0x98 bits 16 + slot and 14 + slot are both set; 0x1fc3d254 clears levels 12 + slot and 14 + slot and 0x1fc3d0e4
    clears level 14 + slot, each by a modify write (bit 8 clear) of the level number to PI +0x90. What those bits
    mean is **unknown**; route: the processor-interface pending-bit list in a Bedrock document.

12. **What the kernel does with the same registers. Established for the set it names.**
    The 6.5.30 IP35 kernel's literal pool holds addresses for PI +0x18, +0x20, +0x28, +0x90, +0x98, +0xa0 and
    +0x118 to +0x158, for MD +0x8 (local form 0x9200000001780008), the LB base, and II +0x130 and +0x1f8. The one reader of the MD word
    (0xc00000000006b9ec, 0xc00000000006ba90, 0xc00000000006bb10) is the memory-error address decode in
    [ip35-prom-memory-bank-config.md](ip35-prom-memory-bank-config.md). The kernel's interrupt connect, mask and boot
    clear are in the kudzu repository's `docs/interrupts.md`.

## Same in 6.211

Compared by masked instruction words (jump targets and gp-relative displacements ignored). Zero masked differences
unless noted; three words in the self test and one in the main routine differ only in a string-pointer immediate
(`0x6fa8` became `0x6f98`):

| Routine | 6.210 | 6.211 |
|---|---|---|
| cold-path clears, election, release and poll | 0x1fc007bc to 0x1fc013a0 | same addresses |
| loop-count delay | 0x1fc040e0 | same bytes |
| main routine | 0x1fc698dc | 0x1fc698d4 |
| pair publication | 0x1fc69234 | 0x1fc6922c |
| interrupt-line self test | 0x1fc65bbc | 0x1fc65bb4 |
| Cause wait, mask, unmask | 0x1fc62818, 0x1fc62660, 0x1fc628a4 | 0x1fc62810, 0x1fc62658, 0x1fc6289c |
| interrupt helpers | 0x1fc3d0e4, 0x1fc3d140, 0x1fc3d254 | each 4 higher |
| slice read, delay by counter | 0x1fc6b530, 0x1fc6b79c | each 0x10 lower |

Established for the listed routines; the rest of the image was not compared.

## Sites

| What | Image address | Grade |
|---|---|---|
| cold-path selection on parked Status | 0x1fc00458 to 0x1fc0064c | established |
| clears of LB scratch 0 and scratch 1 | 0x1fc007d4, 0x1fc007ec | established |
| election | 0x1fc01284 | established |
| release store, poll | 0x1fc0125c, 0x1fc01228 | established |
| MD semaphore-block clears, scratch 1 read-modify-write | 0x1fc699c4 to 0x1fc69a00 | established |
| loop-count delay and counter-advance check | 0x1fc040e0, 0x1fc69a0c to 0x1fc69a18 | established |
| progress writes | 0x1fc6b54c and the stores listed in item 9 | established |
| interrupt-line self test | 0x1fc65bbc to 0x1fc65e94 | established (failure prints not read) |
