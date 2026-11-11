# IP35 PROM: how long the start-up polls and waits really take, how the real-time counter is set, and what the barrier's skew margin is

Question. The processors of an IP35 node synchronise with a local-block scratch barrier, a 200,000-read marker wait, a
fixed 2000-unit wait, rendezvous polls and a node-lock wait with a 10,000,000-unit limit
([ip35-prom-reset-barrier.md](ip35-prom-reset-barrier.md), [ip35-prom-mp-presence-poll.md](ip35-prom-mp-presence-poll.md)).
What does each unit and count mean in time on real hardware, how many instructions and register accesses does one poll pass
cost, which of those costs are known, and is there any hardware mechanism, besides a shared clock, that makes the barrier safe
for a processor that arrives late?

Method: disassembly of the shipped IP35 PROM (SGI Version 6.210, unpacked segment sha256
554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b; 6.211, sha256
25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271) and the IRIX 6.5.30 IP35 kernel, with the retools
Capstone decoder (`tools/hostfacts.py` for routine facts, word-by-word listings for loop bodies). Public sources: Linux kernel
history tree tag v2.5.40 (7570df54ef8c), `include/asm-ia64/sn/sn1/hublb.h`, `hubpi.h`, `hubmd.h`; MIPS R10000 Microprocessor
User's Manual v2.0, Table 1-2; SGI 3000 Family Reference Guide page 28; US patent 6,751,698; a published Tezro verbose PROM
capture. Addresses are 6.210 image addresses. Nothing was run.

## Answer

1. **The PROM sets the real-time counter's rate itself. Established.**
   The routine at 0x1fc6b600 (called at 0x1fc00a2c, before any time-based wait, and at 0x1fc05680) stores 1 << 32 to local-block
   +0x4200 (0x1fc6b644), stores zero to the processor interface's real-time counter at +0x30100 (0x1fc6b648), reads two
   doublewords of the local boot flash's configuration block at offsets 0x78 and 0x80 (0x9000000018000060 plus 0x18 and 0x20,
   0x1fc6b64c and 0x1fc6b650; offsets 0x18 and 0x20 of the block in section 2 of
   [ip35-board-word-and-config-block.md](ip35-board-word-and-config-block.md)), and stores
   `((w78 / w80) / 2 - 1) << 4 | 1 << 32 | 1` to +0x4200 (0x1fc6b684 to 0x1fc6b688). Bits 13:4 of that register are the
   period field (public name `rlc_max_count`, `hublb.h` lines 936 to 962). In both shipped payloads w78 is 200,000,000
   (0x0bebc200) and w80 is 1,250,000 (0x001312d0), at payload bytes 0x78 and 0x80; the quotient is 160 and the field 79.
   Two helpers clear and set bit 0 of the register by read-modify-write (0x1fc6b68c to 0x1fc6b6b0, 0x1fc6b6b4 to 0x1fc6b6d4).

2. **The unit of every counter wait is a microsecond of a 200 MHz clock. Established for the arithmetic, inferred for the hardware.**
   The conversion routine (0x1fc6b73c) computes `ticks * (2F + 2) / 200` with F read back from bits 13:4 of +0x4200; the delay
   routine (0x1fc6b79c) computes the target as the start count plus `units * 200 / (2F + 2)` and loops until the counter reaches it
   (loop 0x1fc6b804 to 0x1fc6b840, which re-reads the counter every pass). With F = 79 a unit is 1.25 ticks and a tick is
   800 ns (1.25 MHz). The kernel agrees: its resolution routine returns 10 * (F + 1) nanoseconds (kudzu `docs/ip35-rtc-and-cycle-counter.md`).
   A published Tezro verbose PROM capture prints "Configured bedrock clock: 200.0 MHz", the first word. Grade: the tick is
   800 ns for any board whose configuration block carries the shipped words (established, both builds); that the local block divides
   its input clock as the field name and both software readers assume is inferred; the register's power-on value is unknown and
   no software reads it before the PROM writes it.
   Consequences (established arithmetic): the fixed wait after publication (argument 2000, 0x1fc69a30) is 2.0 ms (2500 ticks); the
   wait inside publication (argument 1000) is 1.0 ms; the node lock's steal limit (10,000,000, 0x1fc641d4) is 10 s of counter time,
   not 10,000,000 ticks and not an instruction count. The 500-count loop (0x1fc040e0, two instructions a pass) only has to take
   one tick (800 ns) for the counter-advance check at 0x1fc69a18 to pass.

3. **Cost of one pass of each poll. Established (instruction and access counts).**

   | Loop | Addresses | Instructions per pass | Uncached loads per pass | Ends |
   |---|---|---|---|---|
   | reset barrier poll, LB scratch 1 | 0x1fc01238 to 0x1fc0124c | 7 | 1 (local block) | on any release bit, never otherwise |
   | pair marker wait, partner's compare register (local form +0x108 or +0x110) | 0x1fc692ec to 0x1fc692fc | 6 | 1 (processor interface) | on the marker 0x24 or after 200,000 passes |
   | pair rendezvous, odd slice | 0x1fc4461c to 0x1fc44634 | 8 | 2 (PI +0xa0, I/O block scratch 0) | on a flag value, never otherwise |
   | pair rendezvous, even slice | 0x1fc446dc to 0x1fc446f4 | 8 | 2 | same |
   | counter delay | 0x1fc6b804 to 0x1fc6b840 | 14, including two 64-bit divides in a dependent chain | 1 (PI +0x30100) | counter reaches target |
   | node lock wait | 0x1fc6421c to 0x1fc6423c, converter 0x1fc6b73c | about 32 | 3 (+0x4200, +0x30100, lock word at +0x8058) | lock free or 10 s |

   The R10000 manual gives 66 or 67 cycles for a 64-bit divide and 10 or 11 for a 64-bit multiply (Table 1-2): established for the
   R10000, inferred for the R14000 and R16000 (no manual for those parts is cited here). So the delay loop costs at least 134
   cycles a pass in divides alone.

4. **Where the code runs, and what that makes the cost of a pass. Established for the place; unknown for the cost.**
   Everything above, including the barrier and the marker wait, executes from the mapped uncached window of the boot flash
   ([ip35-reset-window.md](ip35-reset-window.md) item 1), so every instruction is an uncached fetch and every pass costs its
   instruction count times that fetch time plus its loads. Neither the fetch time nor the register-load time is given by
   any source read: the R10000 manual does not say how an uncached instruction fetch is issued, and no document read states
   a processor-to-register latency. Bounds only:
   - Flash timing. At 0x1fc00b40 to 0x1fc00b98 (after the barrier, before the marker wait) the PROM writes the memory
     controller's junk-bus timing register (+0x7a0008; `hubmd.h` lines 1061 to 1097: flash setup-hold bits 7:0, flash enable bits
     15:8, UART 23:16 and 31:24, Synergy 47:32) with the flash fields taken from configuration-block words 0x2c and 0x3c (0x10 and 0x10 in
     both payloads), the UART fields 0x02 and 0x0c and the Synergy fields 0xff and 0xff: the register becomes 0x0000ffff0c021010
     if the store takes effect. Read as Bedrock clocks of 5 ns that is about 32 clocks, 160 ns, for one flash access
     (inferred: the header does not define the unit, and the width of a flash read is unknown). The barrier runs before this
     write, at the register's reset timing (unknown).
   - Memory latency. The only published figure is 175 ns for a local cache-line read (SGI 3000 Family Reference Guide, page 28).
     A register inside the processor interface skips the memory controller, so its latency should be lower (inferred, not established).
   Resulting marker-wait window: 200,000 x (6 fetches + 1 load). With free fetches and 175 ns loads it is 35 ms; with 160 ns
   fetches it is about 0.23 s (inferred). The earlier estimate of "tens of milliseconds" counted the load alone.

5. **Skew the reset barrier tolerates. Established for the count, inferred for the margin.**
   Between a processor's own clear of scratch 1 (0x1fc007ec) and the master's release store (0x1fc01278, inside the routine at
   0x1fc0125c; earlier pages name the routine start) the master executes at least 124 instructions: 27 from 0x1fc007f0 to 0x1fc00858,
   36 from 0x1fc0085c to 0x1fc008e8, at least 32 inside the call at 0x1fc01a24, 15 for the election on interface 0 slot A
   (0x1fc01284 to 0x1fc012bc), 6 from 0x1fc008ec to 0x1fc00900 and 8 from 0x1fc0125c to 0x1fc01278, plus the call at 0x1fc01580
   (not counted). Each is an uncached fetch at the reset flash timing. A processor can miss the release only if its clear lags the master
   by more than that. The PROM has no retry for it.

6. **No hardware mechanism for a late processor was found. Established for what exists, inferred for the conclusion.**
   - LB scratch 1 is one 64-bit register at +0x608008, "not reset" and plain storage at its normal address (`hublb.h` line 1069; a
     write-if-zero twin sits at +0x608048). The PROM reaches it by the same address (0x9200000001608008) in the clear (0x1fc007ec),
     the release (0x1fc01278) and the poll (0x1fc01240), from processors of both interfaces, which only works if the register
     is node-wide through that form. The local block has one hard-reset and one soft-reset input (US 6,751,698, local-block signal table) and no per-processor reset.
   - The presence bits are a first-transaction latch: `hubpi.h` lines 811 to 813 and 847 to 849 say the interface sets a processor's
     bit "when it sees the first transaction initiated by the associated CPU". The election therefore reads "lowest slice
     that has already issued a bus transaction", and it is correct on one clock because every processor's first fetch (the reset vector)
     is hundreds of instructions before the election (inferred).
   - The enable bits (+0x50, +0x58) deny a processor the bus while clear (`hubpi.h` lines 885 to 888 and 924 to 927) and survive a soft
     reset; the PROM only clears them (item 2 of the presence-poll page) and never sets them, so a fitted processor must read
     enabled at entry.
   - Real 4-processor nodes boot through this barrier (the published Tezro capture shows four CPUs enabled), with no tolerance in
     the PROM. Hence plain shared-register semantics, with one reset and one clock, are sufficient on hardware (inferred); a
     measurement of the skew itself is not possible by a register read.

## What would settle the unknowns

- Real-time counter period: one 64-bit read of local-block +0x604200 (0x9200000001604200) on a running Bedrock system; the PROM's
  write predicts low bits 0x04f1 and bit 32 set. Also settles the unit claim in item 2.
- Flash timing: one 64-bit read of memory-controller +0x7a0008 (0x92000000017a0008); item 4 predicts 0x0000ffff0c021010.
- Uncached register-read latency: time a tight loop of reads of the processor interface real-time counter against the counter itself from
  user level (the kernel maps that counter for `SGI_QUERY_CYCLECNTR`; see kudzu `docs/ip35-rtc-and-cycle-counter.md`).
- Uncached instruction-fetch time from the boot window: unknown; no read-only route found.

## 6.211

The cold-path clears, election, release and poll (0x1fc007b8 to 0x1fc013a0: 762 words, only five jump targets differ), the
real-time counter set-up, the converter and the delay (shifted by -0x10, word-identical), the marker wait (shifted by -8, 105 words,
seven jump targets differ), the junk-bus timing write (0x1fc00b40 to 0x1fc00ba0), the loop-count delay and the pair rendezvous
(shifted by +4, 100 words) are word-identical to 6.210. The shipped configuration-block words at 0x78, 0x80, 0x8c and 0x9c are
the same in both payloads. The node-lock wait was not compared.

## Sites

| What | Image address | Grade |
|---|---|---|
| counter set-up from configuration words | 0x1fc6b600 to 0x1fc6b688 | established |
| tick to unit conversion; delay routine | 0x1fc6b73c; 0x1fc6b79c | established |
| junk-bus timing write | 0x1fc00b40 to 0x1fc00b98 | established (writes); inferred (meaning of the register's fields in clocks) |
| release store; poll | 0x1fc01278; 0x1fc01238 to 0x1fc0124c | established |
| marker wait loop | 0x1fc692ec to 0x1fc692fc | established |
| pair rendezvous polls | 0x1fc4461c, 0x1fc446dc | established |
| lock wait loop | 0x1fc6421c to 0x1fc6423c | established |
