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
| The delay routine has 55 call sites. Which one the node is in cannot be told from a pc sample: the routine does not change `ra`, so **the return address at the stop names the caller** and the register `a0` is overwritten. Not in the retained evidence. | unknown | |
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
  by vector read and write over the router's UART bank (`0x1fc1663c`, `0x1fc163a4`, offsets 0x240 to 0x268); that path is not used for the local link.
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
  the same form. Its parse is `0x1fc63b24` and was not read.
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

## Not settled

| Item | Route |
| --- | --- |
| The caller of the delay in this run | `ra` and the checkpoint doubleword at the stop |
| Whether the stop is a blink loop (codes 0x82 or 0x8f) and what condition leads there | the same two values; then the code before `0x1fc013d0` and `0x1fc01fec` |
| The default console and whether the L1 must name it | read the console selection from `ConsoleDevice` to the first print |
| The coverage of the L1's FCS check and what the 25 frames contained | one captured frame |
| The routine behind the XBridge 0x7c reads | the guest-error log with pc |
| The reply frame parse (`0x1fc63b24`) | read it |
