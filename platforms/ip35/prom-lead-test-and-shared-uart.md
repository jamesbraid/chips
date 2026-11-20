# IP35 PROM 6.210: the lead-processor test and the node's shared L1 UART

Question. In a firmware-L1 launch of a two-node, four-CPU-per-node Origin 3200 model, all eight CPUs send the same three L1 requests, all
eight sit in the global barrier wait, and every CPU reads II scratch 0 as `0x07fce2f9`. Is the lead test wrong, is the UART lock broken, or does every
slice ask by design?

Method. objdump of the unpacked segment (SGI Version 6.210, sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`; image
addresses), the register pages of this repository and the model's source. Nothing was run; the run's own evidence is the 2026-11-20 firmware-L1 launch.
Grades: **established** (routine read in full, claim follows), **inferred**, **unknown**. Related: [stall note](prom-l1-link-and-delay-loop.md),
[boot flash](boot-flash.md).

## 1. The test, and what +0x1400150 is

| Fact | Grade | Where |
| --- | --- | --- |
| `+0x1400150` is the I/O interface's scratch register 0 (`II_ISCR0`, offset `0x400150` in the II block, reached through the local alias at +0x1000000; chips `devices/bedrock_ii`, entry `scratch`). The public header names it and gives no fields: every bit is PROM software convention. | established for name and offset, inferred for "no hardware meaning" | `devices/bedrock_ii/registers.toml` |
| `0x1fc6b530` returns the whole doubleword at +0x1000020 (`PI_CPU_NUM`) with no mask. The lead test `0x1fc68f64` takes that value N, returns 1 at once if N <= 0 (signed), and otherwise returns 0 as soon as any bit `0x10 << j`, j from 0 to N-1, of II scratch 0 is **set**, and 1 if none is. | established | `0x1fc6b530`, `0x1fc68f64` |
| So a **set** bit 4+j means processor j is present and live; a processor is the lead when no lower-numbered processor is. Wrong-way polarity is not what the code does: with four processors present and bits 7:4 = 1111 only N = 0 passes, which is the intended result. A processor that fails early or is disabled clears its bit (`0x1fc50c34`, `0x1fc69438`), and then the next one up leads. | established (code), inferred (intent) | `0x1fc50c34`, `0x1fc69438` |
| Who sets bits 7:4: the presence routine `0x1fc69234`, called once from main (`0x1fc69a24`) before the test. The A processor of a pair (N even) posts progress 36 in its slot word (PI offsets `0x108` and `0x110`), waits up to `0x30d40` polls for its partner's word, and sets its own bit and the partner's (`0x1fc693f4` to `0x1fc6942c`); on timeout it sets only its own (`0x1fc6933c`). The B processor sets none and waits 1 ms (`0x1fc6939c`). Main then waits 2 ms (`0x1fc69a30`) and runs the first lead test at `0x1fc69a50`. Pairs are PI0 (N = 0, 1) and PI1 (N = 2, 3). | established | `0x1fc69234` to `0x1fc69434`, `0x1fc69a24` to `0x1fc69a50` |
| Every use of the barrier is gated: `0x1fc5ea08` calls the test at entry (`0x1fc5ea14`) and again before the master branch (`0x1fc5eab8`), and `0x1fc44758`, the wait that shows as `ra = 0x1fc44984`, has no other caller. A CPU in that wait therefore got a 1 from the test. | established | `0x1fc5ea14`, `0x1fc5eab8`, caller list of `0x1fc44758` |
| What the code does not give: how all eight CPUs get a 1 when, at the time of the sample, the register has bits 7:4 set and N differs per CPU (frames carry slice `0x10 | N`, read from the same register by `0x1fc0f2e8`, and show N = 0, 2, 1, 3 for CPU indices 0 to 3). By the code only N = 0 can pass. The lead tests must therefore have run while the lower bits were still clear, or the register read differently then. | established as a contradiction between the code and the sample | |
| The only margins the PROM leaves are the 1 ms B-processor wait and the 2 ms settle before the test. The model comments say its processors run on separate host threads and that on hardware the pair posts happen "microseconds apart"; a vCPU that starts late by more than a few milliseconds of the 1.25 MHz counter loses the race. | inferred | model `sgi-bedrock.c` (pair liveness park); timeouts above |
| What would settle it: the model's `sgi_bedrock_io_scratch_read` and `_write` trace events (they carry the CPU index): the first write of bits 4 to 7 against each CPU's first read at the lead test (`0x1fc68f98`). A read of 0 in bits 7:4 by a CPU that later passes, with N nonzero, is the race. | | |

## 2. The value 0x07fce2f9

| Bits | Meaning | Grade |
| --- | --- | --- |
| 0 | global master (set by the master-selection routine, `0x1fc5f044`) | established |
| 7:4 | processor 0 to 3 present (above) | established |
| 9 | partition master | established |
| 3, 13 to 15, 18 to 26 | not decoded: no PROM store of these bits was traced, and the header gives the register no fields | unknown |

The model returns exactly what the PROM stored (`sgi-bedrock-io.c`, scratch read at `0x150`, plain 64-bit storage, no computed bits). So the value is the
PROM's own accumulation across CPUs, not a model choice.

## 3. The CPU number register

`PI_CPU_NUM` (+0x20): bit 0 is the slot (0 CPU A, 1 CPU B), bit 1 the interface (0 PI0, 1 PI1) (public header; chips `devices/bedrock_pi`). The PROM uses the
whole value as the processor index N (section 1) and as the slice of its L1 slot (`0x10 | N`, `0x1fc640f4` and `0x1fc0f2e8`). For a C-brick with CPUs on both PIMMs: PIMM0 A, B read 0, 1 and PIMM1 A, B read 2, 3 (**inferred**: which PIMM is PI0 is not in the header). The model returns `slot | interface << 1` (`sgi-bedrock-pi.c`, `pi_cpu_number`), which agrees. In the launch, CPU indices 1 and 2 are N = 2 and 1: harmless, the PROM never assumes the QEMU index order.

## 4. Every slice asks by design, behind a software lock

| Fact | Grade | Where |
| --- | --- | --- |
| Main opens the L1 port on every CPU. The call at `0x1fc69ad0` follows a lead test whose false branch skips only the block at `0x1fc69a5c` to `0x1fc69a98`; the open, the brick-type classifier and the debug-switch requests are not gated. Only the later rack/bay request is (`0x1fc69b8c`). | established | `0x1fc69a50`, `0x1fc69b8c` |
| The request slot is `0x10 | N` (`0x1fc640f4`), so each CPU has its own slot in one shared port structure; replies come back addressed `0x30 | N`, console frames `0x40 | N`. Four processors sharing one UART is the design. | established | `0x1fc640f4`, `0x1fc0d2fc`, `0x1fc0ec04` |
| UART setup is guarded: under lock 16 it runs only when the low three bits of local-block scratch 2 (`+0x608010`, seen as `+0x1e08010`) are 7, then clears them and bumps a count in bits 43:36 (`0x1fc0f550` to `0x1fc0f63c`). One CPU per node sets the UART up; that matches the run. | established | `0x1fc0f550` |
| The receive parser keeps its state in the same register: bits 2:0 the state, bits 32:28 the slot the current frame belongs to (`0x1fc0e814`, `0x1fc0e938`). It runs under lock 16 on the local UART (`0x1fc0e954`, `0x1fc0ebe4`) and delivers a frame into the ring of whichever slot the frame names, so a reply read by another CPU still reaches its owner. | established for the code, inferred that the ring (`344(slot)` in the port structure) is shared memory | `0x1fc0ded0` |
| The lock: a bit lock. Lock 16 (UART setup, every transmit frame `0x1fc0edf8`, receive) and lock 19 (the console print routine `0x1fc680cc`) are bits of the doubleword at `+0x1790010` (MD performance counter 0, used as storage). Acquire (`0x1fc33598`): spin while the bit is set, take the hub-wide lock by reading LB scratch 3's read-set-if-zero alias (`+0x1608058`, returns 0 and sets when free; `0x1fc066f8`), test again, set the bit, release the hub lock by writing 0 to `+0x1608018` (`0x1fc066dc`). Release (`0x1fc5fd98`): same hub lock, clear the bit. No timeout on the bit; the hub lock is forced free after 10 s (`0x1fc06750`). Not LL/SC and not a hub fetch-and-op. | established | `0x1fc33598`, `0x1fc5fd98`, `0x1fc066f8` |
| The model implements both: read-set on scratch 3 (`sgi-bedrock-lb.c`, `LB_SCRATCH_RS_BASE`) and `+0x790010` as 41-bit storage (`sgi-bedrock-md.c`; bits 16 and 19 are inside it). Under the big lock the read-set is atomic. | established (source read) | `sgi-bedrock-lb.c`, `sgi-bedrock-md.c` |
| The THR interleaving in the trace is not yet evidence of a broken lock: the "first 60 THR writes" list merges every CPU, and two nodes have two UARTs. Each CPU's own bytes decode to frames with the correct residue (`0xf0b8`), so no frame is split inside one CPU's stream. | inferred | the run's summary and frames files |
| What would decide it: split the THR log by node UART; check that no THR write of another CPU falls between a CPU's write of bit 16 and its clear (the model's `sgi_bedrock_md_perf0_read` trace and the scratch 3 read-set trace carry the CPU index). If none does, the lock works and the L1's bad FCS has another cause (section 5). | | |

## 5. Which explanation fits

- **Wrong polarity of the present bits: no.** Set means present; with four present only slice 0 leads. That is also what the sampled register value gives.
- **A missing UART lock: not supported.** The lock exists on setup, transmit and receive, and the model implements the two registers it needs. Not excluded: a lock broken by the model's parking of a processor
  that holds it, or the 10 s forced release; the trace test above decides.
- **Every slice asking: yes, by design**, for the L1 requests and the UART (section 4). **Not by design for the barrier**: eight CPUs in the wait contradicts the test unless it ran before the lower
  bits were visible, which is a race between the model's CPU start-up and the PROM's 1 ms and 2 ms windows (inferred).
- Frame lengths 40, 50 and 51 at the L1: unknown; the PROM's own transmit keeps frames to at most 13 bytes for these requests, so a longer frame at the L1 means bytes from several frames or a lost flag.

## Not settled

| Item | Route |
| --- | --- |
| When each CPU first reads II scratch 0 versus when bits 4 to 7 are written | model trace events with the CPU index |
| The purpose of bits 3, 13 to 15, 18 to 26 | trace PROM stores to the register by writer |
| Whether the receive ring and port structure are shared memory on hardware | allocation of the structure (`0x1fc0f308` callers) |
| Whether any THR write falls inside another CPU's locked frame | the split trace |
