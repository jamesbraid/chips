# IP27 PROM multiprocessor start-up: the pair liveness check, the early stack and the peer wait

Question answered: on an Origin 200, Origin 2000 or Onyx2 node board with both processor slots filled, how do slices A and B
come up together, what does the PROM do when it thinks the other slice is dead, where does each slice keep its early stack,
and what does the "Waiting for peers to complete discovery" phase touch. Ratings follow [AGENTS.md](../../AGENTS.md):
**established**, **inferred**, **unknown**, and **software expectation** for the public Linux headers and the published PROM
manual. Nothing here is a hardware observation.

Image: IP27 PROM 6.156 (IRIX 6.5.30 media), payload sha256 `c2c69bf33c375b43ec7ac511fab41ddf595be1b6838ae717e58a9a1273437fdd`,
the same payload as [prom-node-numbering.md](prom-node-numbering.md). Addresses are payload load addresses, low 32 bits (the
image loads at `0xc00000001fc00000`). Slice numbers come from PI_CPU_NUM (PI+0x20): A is 0, B is 1.

Other sources: the published *Origin200/2000 IP27 PROM Technical Reference Manual* (108-0170-001), and the public Linux files
`arch/mips/include/asm/sn/sn0/hubpi.h`, `arch/mips/include/asm/sn/addrs.h` and `arch/mips/sgi-ip27/ip27-timer.c`.

## Answer

- **The first thing the two slices wait on is each other, at one routine, and nothing before it synchronises them.**
  Established. After the early reset code (below) both slices run the same early main routine; the check at `0x1fc5878c` is the
  first point where either looks at the other, and the pair barrier follows it.
- **The check gives the partner 200,000 reads and then disables it.** Established. No hardware mechanism that makes the partner
  arrive in time was found, and the published manual describes none: it says only that the PROM times out and disables the
  other CPU. Whether the two slices leave reset at the same instant is **unknown**; the manual says a reset resets every CPU
  in the module and nothing about relative timing.
- **Both slices keep their early stack at the same physical addresses, each in its own cache.** Established for the addresses,
  software expectation (the manual) for "the data cache is used as memory".
- **Real-time counters are set by software, one Hub at a time.** Established for the PROM. Whether the hardware can slave a
  counter to a global clock is **unknown**; the PROM selects the internal source.

## The pair liveness check (0x1fc5878c)

One caller, `0x1fc58d2c`, in the early main routine that both slices run. The manual's progress table calls code 0x24
"local arbitration" and 0x28 "first local barrier". All steps **established** from the listing:

1. Each slice stores 0x24 into its own real-time compare register (PI+0x108 for A, PI+0x110 for B). It also shows 0x24 on the
   node LEDs. The PROM uses these compare registers as a per-slice progress word throughout reset.
2. The check runs only when both PI_CPU_PRESENT_A (PI+0x40) and PI_CPU_PRESENT_B (PI+0x48) read nonzero. Otherwise it returns
   at once.
3. It reads its own compare register back; anything but 0x24 raises failure code 0x91 and the routine carries on.
4. It reads the other slice's compare register up to 200,000 (0x30d40) times and stops at the first read that equals 0x24. A
   match on the very last read counts as a miss.
5. On a miss, slice A stores zero to PI_CPU_ENABLE_B (PI+0x58) and slice B stores zero to PI_CPU_ENABLE_A (PI+0x50). Each slice
   then sets its own bit in the flag word at I/O block +0x150: bit 23 for A, bit 22 for B. The value it returns is the other
   slice's last compare value; the "other CPU on this node died with LEDs" message prints only when that value is positive, so a
   partner that never posted anything is disabled silently.
6. On a match, slice B waits 1 ms and writes nothing; slice A sets bits 23 and 22 together.
7. Before the check the PROM tests that the real-time counter advances during a short busy loop (failure code 0x87 if not, and it
   carries on). After the check come the LED 0x28 code, the pair barrier, then the compare register is cleared to zero.
   **Inferred** from that order: once a slice has posted 0x24, its code stays until both slices have passed the check, so a
   partner that posts late (but inside the window) still finds it.

If both slices miss, each has zeroed the other's PI_CPU_ENABLE. The manual says a CPU whose PI_CPU_ENABLE is off makes no Hub
requests at all, so neither goes on. (The manual says in two places "store 1" and "set to zero"; the listing stores zero.)
**Established** for the stores, software expectation for the effect.

The pair barrier itself is two pending levels in the shared PI_INT_PEND1 register (levels 113 and 112, bits 49 and 48), set and
cleared through PI_INT_PEND_MOD with bit 8 set or clear. Each slice leaves its wait when the partner's level appears or when the
partner's flag bit (22 or 23 of the flag word above) is clear. **Established.**

### How the slices are released

- The reset code of every slice reads PI_CPU_NUM and runs short fixed delay loops; slice B and slice A each take one different
  loop. No wait on the other slice. **Established.**
- At reset every slice checks PI+0x420 for the constant 0x52737430. If absent it stores it there and writes 0x81 to NI_PORT_RESET
  (NI+0x8), expecting the processor to be restarted. A processor still running afterwards logs 0xa6 and disables itself. So
  PI+0x420 must keep its value across that restart. **Established** for the code and the dependency; that the restart restarts
  both slices together is **inferred**, not documented.
- The real time a 200,000-read poll takes, and the relative reset timing of the two slices, are **unknown**. No measurement
  is held.

## The early stack

- Right after code 0x2a ("configure Dex mode stack and data") every slice tags 32 KiB of secondary-cache lines for the physical
  range 0x100000 to 0x107fff and then sets its stack pointer to the XKPHYS cached address of 0x104000. The sequence has no slice
  term. **Established.** The tagging writes cache tags and data by index with no memory access: **software expectation**
  (the manual: Dex mode "treats the CPU data cache as memory"); the exact line state written is **inferred**.
- The early main routine's frame is about 1.2 KB, so its saved registers and return addresses sit just below 0x104000.
  **Established** for the frame size.
- The early routine ends by switching to the final main routine on a RAM stack: new stack top `0xc00000001fdf0000` plus the
  slice number shifted left 16, after running the PROM's two cache routines. From then on each slice has its own stack and its own
  per-slice data pointer. **Established.** So the Dex phase is the only phase in which the two slices use identical addresses
  for private memory.
- The public Linux headers describe a 256 MB uncached alias of the reader's node memory whose lowest 128 KiB is flipped by bit
  0x10000 for slice B (software expectation). The PROM's own RAM mappings are TLB entries onto physical 0x1a00000 to 0x1bfffff, not
  that alias, and no PROM code was found that addresses the flipped region (**inferred**: the 6.156 payload's code was searched; the
  inflated monitor image was not read).
- The window at XKPHYS 0x9000000010000000 is the boot flash. The PROM reads a configuration block in it: three words at
  +0x70, +0x78 and +0x80 hold 180,000,000, 90,000,000 and 1,250,000 in this image, and a word at +0x90 selects which of two LED
  register layouts the PROM drives. **Established** for the reads and values; the units are **inferred** from the sizes.

## "Waiting for peers to complete discovery"

Printed once by the network discovery routine at `0x1fc4fe4c` (one caller, `0x1fc518bc`). **Established** unless marked.

- Only the local master of each node runs it. The local slave goes straight to the pair barrier and spins there, with a 1 ms delay
  per pass and an LED blink that writes into the barrier's own stack frame.
- Each pass: read the real-time counter and set a deadline of 120,000,000 ticks (96 s at the counter's 1.25 MHz); set a mark and
  the node count in the master's own NI_SCRATCH_REG1 (bit 22 plus the count); check the console abort key; then read every other
  Hub's NI_SCRATCH_REG1 by routed remote read and require bit 22 set and the same node count. Headless Hubs and entries with a
  flag at bit 28 are skipped. When all agree it waits 0.5 s and does a second pass over NI_SCRATCH_REG0 and REG1, looking at bits
  51 and 53 of REG1. A mismatch waits 8 s and reruns, up to three times, then reports failure code 0xab.
  The meaning of REG1 bits 22, 51 and 53 is **inferred**.
- The message "Hub ... with NIC ... took an exception! Disabling and continuing" belongs to this routine's peer table: the master
  prints it for a peer entry whose flags have bits 16 and 30 set. What sets bit 30 was not traced (**unknown**).
- Registers and memory the phase and its neighbours touch: the flag word at I/O block +0x150 (slice-alive bits 22, 23; global
  master bit 35), NI_SCRATCH_REG0 and REG1, NI_STATUS_REV_ID, the routed vector-access registers, PI_INT_PEND levels 112 and
  113 (barrier) and 10 and 11 (slave loop), the real-time counter, the node LED registers, and a node-addressed junk-bus UART
  window at +0x1a20000 whose receive routine (`0x1fc3978c`, polling a status byte at +8 and reading data at +0) has three callers.
- No code in this phase reads the Dex lines at 0x100000.

## Real-time counters across nodes

- The PROM initialises each Hub's counter itself, at reset on every slice: it writes PI_RT_LOCAL_CTRL (PI+0x160), writes zero
  to PI_RT_COUNT (PI+0x30100), then writes PI_RT_LOCAL_CTRL again with a divisor computed from two flash configuration words
  (Hub clock over counter rate: 90,000,000 / 1,250,000 = 72, giving 0x10047 in this image). It is the only writer of that
  register found, and no PROM write reaches another node's counter. **Established**; the absence of a remote write is
  **inferred** from the call sites of the remote-write routine.
- The public Linux header names PI_RT_LOCAL_CTRL fields USE_INT (bit 16), GCLK (bit 15), GCLK_COUNT, MAX_COUNT and GCLK_EN
  (bit 0), and a GCLK filter register. The PROM sets USE_INT, so it does not select a global clock. Whether a global clock pin
  exists and what the GCLK bits do is **unknown**: only the names are held. Linux zeroes each node's own counter
  and reads node 0's counter remotely as its clock source, so it treats the counters as independent (software expectation).

## Unknown

See [questions/ip27-prom-pair-timing-and-peer-flags.md](../../questions/ip27-prom-pair-timing-and-peer-flags.md).
