# IP35 PROM 6.210: the delay loop at 0x1fc6b834 and the node side of the L1 link

Question. A model run with the real L1 firmware starts the node, which then prints nothing on any console and spins with every
sample at `0xc00000001fc6b834`, while the L1 logs 25 "PPP error ... bad FCS" lines on the node link. What is that loop, how does the
PROM talk to the L1, what does it do when the L1 does not answer, and what do the model's warnings mean?

Method. objdump of the unpacked segment (SGI Version 6.210, sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`,
addresses are image addresses), the register table in `devices/bedrock`, and the model's own source for the counter. Nothing was run.
The L1 side of the link is in the controller repository. The run's evidence is the launch record and the pc samples of the 2026-11-20
firmware-L1 launch. Grades: **established** (the routine was read and the claim follows), **inferred** (reasoning stated),
**unknown**. Other pages: [request timeouts](prom-l1-request-timeouts.md), [NASID numbering](nasid-numbering.md).

## 1. The loop at 0x1fc6b834 is a microsecond delay, not a poll of the L1

| Fact | Grade | Where |
| --- | --- | --- |
| The loop is the body of the PROM's microsecond delay routine `0x1fc6b79c`. It reads the hub real-time counter (`PI_RT_COUNTER`, node alias +0x30100) once for a start value, forms a deadline of start + (microseconds x 200) / D, then re-reads the counter (`ld` at `0x1fc6b834`, the sampled pc) until it is not below the deadline (`sltu`, `bnez` back to `0x1fc6b804`). It polls no L1, UART or device register. | established | `0x1fc6b7a0` to `0x1fc6b844` |
| D = ((word at node-alias +0x1604200 and 0x3ff0) >> 3) + 2. The word is written by the timer start-up routine `0x1fc6b600`: it first stores 1 << 32, zeroes the counter, reads two doublewords of the flash configuration block through the boot-space window (+0x78 and +0x80, which are configuration offsets 0x18 and 0x20: bus clock in Hz and 1,250,000) and stores `((bus / 1,250,000) >> 1) - 1) << 4 | 1 << 32 | 1`. So D equals bus clock / 1.25 MHz and the delay is the requested microseconds at the counter's 1.25 MHz. Called from `0x1fc00a2c` and `0x1fc05680`. | established for the code; the flash offsets are the observed layout in [boot flash](boot-flash.md#cpu-configuration-block-at-0x60) | `0x1fc6b600` to `0x1fc6b688` |
| What ends the wait: the counter reaching the deadline. In the model the counter is a 1.25 MHz function of the virtual clock (the `PI_RT_HZ` constant in the model's Bedrock PI) and the divider register is stored and read back, so a delay ends after its nominal time if virtual time advances. | established for the code; the model reading is from its source, not a run | model `sgi-bedrock-pi.c`, `sgi-bedrock-lb.c` |
| The delay routine has 54 call sites. Which one the node is in cannot be told from a pc sample: the routine does not change `ra`, so **the return address at the stop names the caller** and the register `a0` is overwritten. Not in the retained evidence. | unknown | |
| Candidates that never leave a delay: two fatal-error blink loops. The code stores an error code in a per-slice checkpoint doubleword (uncached address `0x9000000010000000 + 0xc0 + 8 x slice`, slice read from `0x9200000001000020`), waits 500,000 microseconds, stores 0 and waits 500,000 again forever. Codes `0x82` (`0x1fc013d8`, after the call at `0x1fc013d0` that loads the segment named "io7prom") and `0x8f` (`0x1fc01fec`) are the two seen; the same register holds the progress codes `0x35`, `0x36` and `0x0e` written near `0x1fc009e4`. A loop of this kind prints nothing and shows the same pc forever. | established for the code; inferred that this run is in one of them | `0x1fc01424`, `0x1fc01474`, `0x1fc02038`, `0x1fc02088` |
| What would decide: `ra` at the stop (gdb `info registers`), or the value in the checkpoint doubleword and whether it alternates with 0. A `ra` inside `0x1fc01424` to `0x1fc0147c` or `0x1fc02038` to `0x1fc02090` is a blink loop; one inside the request primitive (`0x1fc63d38` and its poll `0x1fc533e4`) is a 2-second L1 wait ([timeouts page](prom-l1-request-timeouts.md)). | | |

The caller chain up to the boot sequence step therefore cannot be given for this run. For the L1 wait the chain is established: the
main routine (`0x1fc698dc`) calls the port open at `0x1fc69ad0` (through `0x1fc68f48` to `0x1fc503bc` to `0x1fc0f308`), which makes the first
requests of section 2.

## 2. The node side of the L1 link (established unless stated)

- **UART.** For the local node (kind 15, the call at `0x1fc68f50`), `0x1fc0f160` programs a 16550-compatible UART at node alias
  `0x9000000030000080` with registers every 8 bytes: it waits up to 100,000 microseconds for line-status bit 6 (transmitter empty, offset
  0x28), sets line control (0x18) to 0x80, writes the divisor 12,000,000 / (16 x 57,600) = 13 to offsets 0x08 (high) and 0x00 (low), line
  control 3 (8 data bits; parity and stop bits read as 8N1, **inferred** from the 16550 layout), modem control (0x20) 0x22, interrupt
  enable (0x08) 0, FIFO control (0x10) 1 then 7. The baud argument is `0xe100` = 57,600 (`0x1fc0f5cc`). Registers of other nodes' UARTs are reached
  by vector read and write over the router's UART bank (`0x1fc1663c`, `0x1fc163a4`, offsets 0x240 to 0x268); that path is taken for other kinds of port and is **inferred** not to be used for the local link.
- **Frame** (transmit routine `0x1fc0ec04`, up to 127 payload bytes per frame): flag `0x7e`, one address byte (the low byte of the
  link-slot argument; its meaning for a request is **inferred** as the slot), the payload, the two FCS bytes low byte first, flag `0x7e`.
  The bytes `0x7e` and `0x7d` in address, payload and FCS are sent as `0x7d` followed by the byte xor `0x20`. The FCS is the
  16-bit reflected CRC with polynomial `0x8408` (table checked entry by entry against the generated table), initial value `0xffff`,
  one's complement at the end, over the address byte and the unstuffed payload. There is **no `0xff 0x03` address and control pair and no protocol field**.
  Longer packets are cut into several frames by the layer above (the chunk codes `0x3001` to `0x3003` of the controller notes: inferred).
- **Payload.** The request builder `0x1fc63e78` writes a 4-byte head (a per-slot word at port record +332 or'ed with a flag), the 16-bit request code
  at bytes 4 and 5, then argument descriptors whose first byte has bit 7 set; the layout is that of the controller's router packet
  (**inferred**; not decoded here).
- **Who sends first.** The PROM; the L1 only answers. The open routine, after the UART set-up above, first asks for brick type and
  rack/bay (code `0x0003`, builder call at `0x1fc24d2c`, wrapper `0x1fc68724`, request primitive `0x1fc63d38`) and then reads the debug switches
  (code `0x0001`, `0x1fc28d04`). Nothing is sent before the UART set-up.
- **Reply, timeout, retry.** Established on the [timeouts page](prom-l1-request-timeouts.md): one wait of 2,000,000 microseconds for the reply, no
  resend, `-4` on timeout; the only resend is when the transmit ring is full (up to 50 sends 500 microseconds apart). A reply is a frame of
  the same form (**inferred**). Its parse is `0x1fc63b24` and was not read.
- **What the L1's "bad FCS" can and cannot mean.** The PROM's FCS is the plain CRC above. A frame that fails it at the L1 has a different
  coverage (for example the L1 also covering a fixed address and control pair), a different stuffing, or was damaged in the model's link.
  The retained evidence cannot say which. Comparing one captured frame with the algorithm above settles it.

## 3. If the L1 never answers

- The PROM does not wait forever on a request: each ordinary request costs 2 s and the boot goes on (established, [timeouts page](prom-l1-request-timeouts.md)); it prints
  "*** System Controller DIP switches unavailable" and waits up to 6 s for a line at the menu (`0x1fc6b2d8`). That print needs a console.
- There are three console back ends: the ELSC (L1 request) UART, the junk-bus UART, and the base-I/O IOC3 or IOC4 serial port
  ("ELSC not responding.", "Junk UART not responding.", "IOC3 found, but is not the console."; menu `Console Selection`, variable
  `ConsoleDevice` and `ForceConsole`). Which one carries the first output, and whether the L1 must name it first, was **not traced**.
  The retained observation fits "the PROM has not printed yet" (no text on IOC3 serial A in several minutes), which is what a blink loop or an
  early long wait produces; it does not show that the PROM needs the L1 to name the console.
- The L1's `select` line `---c-- CPU0` is the controller's own routing and says nothing about the PROM's choice.

## 4. The model's warnings

| Warning | Reading | Grade |
| --- | --- | --- |
| "node N and its peer both carry number 0" | A hub's node number is 0 at reset and is set by the PROM's node-number distribution (`0x1fc5cc60`), after the master's NASID calculation (`0x1fc5d63c`, [NASID page](nasid-numbering.md)). Two hubs that both read 0 therefore mean the distribution has not run (or has not reached the peer). It repeats for as long as the PROM is before that step. | established for the order; the warning text is the model's. Inferred that it is harmless here: it is expected before the step |
| XBridge accesses at 0x7c (28) and two XBow register errors | The PROM string pool has the input/output discovery messages ("XBOW LINK %d does NOT have NUMAlink connection! Skipping", "Widget present, but link not alive!", "Xbow arbitration delay..."), which is where absent widgets are probed. Which routine reads 0x7c of a bridge, and with what base, was not found: the offset has no row in the XBridge register census and the immediate does not appear as a plain load displacement. | inferred that these are discovery probes of absent or partly modelled widgets; the exact step is **unknown**. The probe pc is in the model's log if run with the guest-error log and the pc; it is not in the retained evidence |
| Whether any of them is a register the PROM expects the L1 to have set | no. The L1 sets no hub register: the PROM sets its own timer, node numbers and I/O. What the PROM takes from the L1 is rack, bay, brick type and the debug switches, and a failure of each is tolerated. | inferred (from the request list) |

## Follow-up: the stall is the global barrier wait (return address 0x1fc44984)

A second launch (all CPUs at `0x1fc6b834` with `ra` = `0x1fc44984`, checkpoint doublewords slice 0 `0x53`, `0x54`, then `0x5a`; slices 1 to 3
`0x1e`, then `0x5b`; the counter at 1.25 MHz and D = 160) rules out the blink loops of section 1 and a hung counter. Read with objdump of
the same segment; the barrier itself is described on the [topologies sheet](../../../origami/docs/datasheets/origin3000-topologies.md) of the
emulator project, so only the new facts are graded here.

| Question | Answer | Grade |
| --- | --- | --- |
| Caller | `0x1fc44984` is inside `0x1fc44758`, the wait of the global barrier `0x1fc5ea08`; `0x1fc44758` has four call sites, all in that routine. After each failed poll it calls the delay with 100,000 units (`0x1fc4497c`, 100 ms at 1.25 MHz), then `0x1fc50b14(0)` (a console poll, not read further), and polls again. | established |
| What it polls | A vector read (`0x1fc5cf3c`, address `0x608008`) of the target hub's local-block scratch 1. It ends the wait when bit 13 of that word has the wanted value (1 for the "set" wait, 0 for the "clear" wait); bits 34:19 carry the barrier's line number. It also gives up on a hub whose bit 40 or bit 35 is set, and on Ctrl-C. There is no timeout. | established |
| Who writes it | The target hub's own lead processor, by a local store to its scratch 1 (the global master for every other lead; the other leads for the master). Not an interrupt and not the L1. | established |
| Which barrier line and which target | Not in the retained samples. The first barrier a lead reaches after discovery is line 4315 (`0x1fc60c04`), then 4348 (`0x1fc60c70`); the slice 0 path after `0x5a` goes there. At the stop, `a3` of the call is in `s3` (the line), the target entry index in `s1` and the wait kind in `s4`: reading `s3`, `s1`, `s4` on a stuck CPU decides it. | inferred for 4315 |
| Why all 8 CPUs | By the PROM only a node's lead processor (the lowest-numbered present slice, test `0x1fc68f64`, slice from `0x9200000001000020`) runs the barrier loop; any other returns at once (`0x1fc5ea14` to `0x1fc5ea30`). All CPUs showing `ra` `0x1fc44984` therefore needs either every CPU to pass the lead test in the model (II scratch 0 bits 4+j, local `0x400150`, as seen from `0x1400150`) or a second entry into `0x1fc44758` that the call-site list does not show. Not settled. | unknown |

Checkpoints (the per-slice doubleword is written by `0x1fc6b54c(code)`; decimal in the code, hex here):

| Code | Store | Meaning | Grade |
| --- | --- | --- | --- |
| `0x53`, `0x54` | `0x1fc68314`, `0x1fc68338` | bracket the call `0x1fc66978(...)` in the boot-string interpreter (`0x1fc6813c`, called from the main routine at `0x1fc69c10`, after its L1 requests), made by a lead whose II scratch 0 bit 1 is clear. That call writes its own `0x4a` and `0x4b`. | established for the stores; the call's purpose not read |
| `0x1d`, `0x1e` | `0x1fc68224`, `0x1fc6824c` | end of the interpreter's string. `0x1e` then `0x5b` is the normal sequence for a non-lead slice: it skips the lead-only block. | established |
| `0x5b` | `0x1fc6092c` | every slice, in the per-processor start routine `0x1fc60760` (reached through a pointer table at `0x1fc6efa4`), after "node discovery begins" prints and `0x1fc68fe0` | established |
| `0x4f`, `0x5a` | `0x1fc609b4`, `0x1fc609dc` | lead only (`0x1fc68f64` true): `0x4f` before `0x1fc6017c`, `0x5a` after it, then `0x1fc5ff88`, the discovery, the unconditional print at `0x1fc60bc8` and barrier 4315 | established |

So `0x5a` on slice 0 and `0x5b` on slices 1 to 3 is the expected pair for one lead and three non-leads; after `0x5a` the next steps are discovery and the first global
barrier, and a non-lead goes on to the "Local Slave" rendezvous. The checkpoints do not move because the barrier does not pass.

**No output.** Before this point the PROM has already executed unconditional prints (`0x1fc680cc`, for example at `0x1fc60bc8`), and the barrier prints
"waiting for node with nic ... at global barrier..." every 100 polls (10 s). None reached ioc3-a or ioc3-b, so the console in use is not the IOC3 port (or the print does
not leave the PROM). The console is an indirect object chosen at console initialisation (`0x1fc3c9ac` calls through a pointer in the global table); where it is chosen was
not traced. **The PROM does have an ELSC back end that sends through the L1 request layer** (probe `0x1fc29450`, "Switching to ELSC UART") and a junk-UART back end. If the
default is ELSC, console text leaves as L1 frames, which would explain the empty UART and IOC3 and the continued stream of bad frames (the barrier's 10-second prints and
its console poll would keep producing them). That the lengths 40, 50 and 51 are console text is **inferred**, not shown.

**L1 requests.** Established: the open at `0x1fc69ad0` sends code `0x0003` first and then code `0x0001`, inside the main routine before the interpreter call at `0x1fc69c10` and so before `0x53`
and `0x5a`; the request primitive returns after 2 s without resending, and the main path continues (the [timeouts page](prom-l1-request-timeouts.md)). So the stall is not a
missing L1 reply for those two requests. Requests later in main (`0x1fc6a53c`, `0x1fc6aefc`, `0x1fc6b134`) and any made during discovery were not traced, so a later need for a
reply is **unknown**; the barrier itself uses no L1 traffic.

## Not settled

| Item | Route |
| --- | --- |
| The caller of the delay in this run | `ra` and the checkpoint doubleword at the stop |
| Whether the stop is a blink loop (codes 0x82 or 0x8f) and what condition leads there | the same two values; then the code before `0x1fc013d0` and `0x1fc01fec` |
| The default console and whether the L1 must name it | read the console selection from `ConsoleDevice` to the first print |
| The coverage of the L1's FCS check and what the 25 frames contained | one captured frame |
| The routine behind the XBridge 0x7c reads | the guest-error log with pc |
| The reply frame parse (`0x1fc63b24`) | read it |
