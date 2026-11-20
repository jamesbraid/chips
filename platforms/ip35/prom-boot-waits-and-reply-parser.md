# IP35 PROM 6.210: the waits behind the stall, the L1 reply parser and the UART inputs

Question. A firmware-L1 launch gets past the lead test: node 0 shows checkpoints `0x71`/`0x74` at about 97 s and `0x80` from about 300 s, CPUs sit in
delay or poll code with `ra` in `0x1fc0da20`, `0x1fc0d820`, `0x1fc0d76c`, `0x1fc0e95c`, `0x1fc3364c` and `0x1fc1451c` (`s4` = 0xf4240), the console prints nothing
and the L1 logs the same requests over and over. What is the PROM waiting for, does it accept the L1's replies, and which UART inputs does it use?

Method. objdump of the unpacked segment (SGI Version 6.210, sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`; image addresses),
the controller repository's request-code names, and this repository's register pages. Nothing was run. Related: [stall note](prom-l1-link-and-delay-loop.md),
[lead test and shared UART](prom-lead-test-and-shared-uart.md), [memory configuration](prom-md-config.md). Grades: **established**, **inferred**, **unknown**.

## 1. Checkpoints and the pollers

| Item | Answer | Grade |
| --- | --- | --- |
| `0x71`, `0x74` | the DIMM read routine `0x1fc309cc` (named on the [memory page](prom-md-config.md)) stores `0x70 | ((lane & 3) << 1) | (position & 1)` at entry (`0x1fc30a14`): `0x71` is lane 0 position 1, `0x74` lane 2 position 0. It runs the DIMM scan (`0x1fc2d524`, via `0x1fc2d664`) and the memory test passes (six calls `0x1fc5695c` to `0x1fc56cd8`). So at 97 s node 0 is reading DIMM data, not stalled. | established |
| `0x80` | not a step. The heartbeat of the generic wait `0x1fc144b8`: it starts with checkpoint value 128 and toggles it (xor with a per-context byte) once per `s4` = 1,000,000 timer units, a heartbeat interval and not a timeout. A checkpoint of `0x80` therefore means a CPU is inside that wait. | established |
| What `0x1fc144b8` waits for | its argument is the timeout in timer units (0 = forever); it loops: read the counter (`0x1fc6b73c`), call a poll hook (offset 8 of the per-CPU wait object, from `0x1fc64f48`), done when the hook returns nonzero, then call the completion hook (offset 16); on timeout it returns -1. All the `ra` values except `0x1fc3364c` and `0x1fc0e95c` are the console-input poll path below it. | established |
| The poll hook | `0x1fc0da34` calls `0x1fc0d9dc`: "a byte is waiting on the console input port": if the port has a console slot count (offset 432) it returns it, else it asks `0x1fc0d7e8` whether the CPU's own request slot (`0x10 | N`, from `0x1fc0f2e8`, the `PI_CPU_NUM` read at pc `0x1fc0f2fc`) has data, pumping the UART receive state machine `0x1fc0ded0` when empty. So `ra` `0x1fc0da20` is the poll loop, `0x1fc0d820` the pump from the slot check, `0x1fc0d76c` the receive byte hook (`0x1fc0ce68`), and `pc` `0x1fc0e048` the pump reading its state from local-block scratch 2 (`+0x608010`). | established |
| Locks seen as `pc` | `0x1fc335f8`: bit test of the lock word at `+0x1790010` (loop while bit 16 or 19 is set, no timeout from `0x1fc5fef0`); ra `0x1fc3364c`: just after releasing the hub lock; `0x1fc0671c`: the read-set read of LB scratch 3 (`+0x1608058`), loop until it reads 0 (10 s forced free); `0x1fc0e95c`: the receive routine taking lock 16. These are CPUs waiting their turn for the UART or console print lock behind a CPU that holds it while it waits in `0x1fc144b8`. | established for the code; inferred for who holds it |
| `0x1fc6b75c`/`774` | the counter read inside `0x1fc6b73c` (the sampled instructions of the loop) | established |
| Which blocking read | `0x1fc43c78` is a blocking `getchar` (`0x1fc144b8(0)`). Callers: the breakpoint and watchpoint handlers (`0x1fc05560`, `0x1fc055e8`: "Go on? ('q' to quit to POD)"), the pager prompt "--More--" (`0x1fc3d334`, `0x1fc3d384`), a pause after a message in the memory-test area (`0x1fc4400c`, between checkpoints 33 and 34, when a flag in the routine is set), `0x1fc304a0`, and the barrier's Ctrl-C check (`0x1fc5c400`, only after a ready test `0x1fc50cc4`, so it does not block when no key is down). The line reader `0x1fc67dc8` (with a timeout argument, 6 s for the DIP-switch menu) also uses it. Which one the CPUs are in is not in the evidence. | established for the list; unknown for which |
| What decides it | at a stuck CPU, `ra` is `0x1fc1451c`, so `sp` is the `0x1fc144b8` frame: `[sp+8]` is the return address into its caller (`0x1fc43c88` for `getchar`, `0x1fc67e54` for the line reader) and `[sp+48]` the return address of that wrapper's caller, which names the prompt among the callers above. `[sp+32]` is the wait object (`s3`): its words at +8 and +16 are the poll and completion hooks. | |

So the observed state fits "the PROM is blocked reading a console character". Because its output is not visible, the prompt (a pager, a breakpoint handler or an error pause) would also be invisible.

## 2. The reply parser (established unless marked)

- **Receive.** The state machine `0x1fc0ded0`, under lock 16 on the local UART. Frame: flag `0x7e`; address byte; bytes with `0x7d` escapes (xor `0x20`); flag. A flag in the address position restarts. The address byte must be a slot index below 5 with the top three bits clear, or an index below 24 with top bits `0x20` or `0x40`: the L1's `0x3S` (index `0x10 | S`, class `0x20`) is accepted. The slot must be allocated (a request in flight: `0x1fc0d7b8`, word 328 of the slot is not -1): a reply that arrives after the 2 s wait, when the slot is released, is dropped. A frame is kept only if it holds at least 2 bytes (3 for slots above 4) and its CRC is good: CRC-16, polynomial `0x8408`, initial `0xffff`, run over the **address byte**, the payload and the two FCS bytes, with residue `0xf0b8` (`0x1fc0e7e4`). A bad CRC resets the frame (code -2) and the request later times out; a bad address or short frame is -3 or -4.
- **Parse** (`0x1fc63b24`, called after the wait releases the slot). Bytes 0 to 3: a status word, nonzero is returned as the failure code. Byte 4: argument count. Each argument: type byte 0 then four bytes (an integer), type 1 then a length-prefixed string, or a byte with bit 7 set and a 7-bit length then that many bytes (binary). The caller supplies a size sum (integer 2, string 2, binary 3) that must equal what was parsed, and byte 4 must equal the number of arguments parsed; a mismatch returns -1, which the wrapper turns into -112. There is **no request code, sequence or tag in the reply**: a reply is matched to a request only by the address byte (the slot).
- **The L1's reply to `0x0003`**: `7e 3S 00 00 00 00 02 00 00 00 00 00 00 00 00 00 43 FCS 7e` reads as status 0, two arguments, integer 0 and integer 0x43 ("C"). The caller `0x1fc24cc8` expects exactly two integers (sum 4), takes the letter from the second, and accepts "C". The layout satisfies the parser, provided the FCS covers the address byte (above).
- **Failure.** A reply that never completes (bad CRC, dropped, wrong slot) is a 2 s timeout; a parse mismatch fails at once. No retry in either case (the [timeouts page](prom-l1-request-timeouts.md)); the caller continues with defaults.
- **Request `0x100a` has no reply** (controller repository: "Sends no reply"). The PROM waits the full 2 s anyway (`0x1fc68a5c`), then ignores the result: each use costs 2 s.
- **Why requests repeat.** Eight CPUs each run the sequence (the [lead note](prom-lead-test-and-shared-uart.md)). In addition `0x0006` (EEPROM read) is a loop: `0x1fc1ce6c` asks for a 64-byte window, reads the reply's "bytes left" integer, advances its offset by 64 and asks again **until that integer is 0**. A reply whose "bytes left" does not reach 0 repeats the request for ever with a growing offset. Callers `0x1fc4fd80` (via `0x1fc1d504`), `0x1fc500a8`, `0x1fc502d8` (the board EEPROM record behind the CPU configuration check: [boot flash](boot-flash.md)). (**inferred** that this is what the run repeats: the offsets in the captured requests settle it.)

## 3. UART inputs

| Input | Use | Grade |
| --- | --- | --- |
| LSR (offset 0x28) | receive byte `0x1fc0ce68`: tests `0x0d` (data ready, parity error, framing error); data ready reads the byte at +0x80; none of the three set returns -3 (empty); error with no data returns -2. LSR bit 7 (FIFO error), overrun and break are not tested. Transmit byte `0x1fc0ced4`: waits up to 50,000 µs for bit 5 (THRE), then writes +0x80. Setup `0x1fc0f160`: waits up to 100,000 µs for bit 6 (TEMT) first. So 0x60 = idle, 0x61 = a byte waiting: both fine; a stuck bit 5 would cost 50 ms per byte. | established |
| MSR, IIR | not read by these three routines; the setup writes IER 0 (polled operation) and FIFO control 1 then 7 (enable, clear both). CTS, DSR and DCD are not tested. | established for the routines read; the rest of the segment was not searched |
| MCR `0x22` | RTS (bit 1) and bit 5. On a 16750-class UART bit 5 enables automatic RTS/CTS flow control, which then gates the transmitter on CTS. That it is the flow-control bit here is **inferred** from the 16550 family; if the model's UART applies CTS (MSR 0x10), the model must hold CTS asserted. | inferred |

## 4. The requests and the console

| Code | Name (controller repository) | Wait on it | Grade |
| --- | --- | --- | --- |
| `0x0001` | read debug switches (one integer) | on failure the switches read 0 and bit 17 of the state word stays clear | established |
| `0x0003` | rack, bay and brick type (two integers) | a failure for most board classes prints and returns class 0 | established |
| `0x000e` | requesting port (one integer: the link index the request came in on), sent by `0x1fc0ee08` after `0x0003` | not traced | established for the builder |
| `0x100a` | event subchannel clear, no reply | 2 s timeout, ignored | established |
| `0x0004` | brick serial (text) | not traced | established for the builder |
| `0x0005` | firmware revision (three integers) | also the ELSC console probe (`0x1fc293f4` formats "%d.%d.%d"): success gives "Switching to ELSC UART" | established |
| `0x0006` | EEPROM read | loop until "bytes left" is 0 (section 2) | established |

- No reply is needed to proceed except `0x0005` for the ELSC console probe and `0x0006` for the EEPROM loop; all others have defaults.
- "System Controller DIP switches unavailable" appears only when the debug-switch request fails (state bit 17 clear), only on the lead processor, at `0x1fc6b2d8` in main after the L1 steps. With a good `0x0001` reply it is correctly absent, and the memory test and DIMM scan (checkpoints `0x7x`) run in main only after those steps. So its absence is not evidence of a failed request.
- The console back end is not decided here. The back ends are entries of device tables (`0x1fd68160`, `0x1fd683e8`); the ELSC enable routine `0x1fc29498` is reached through them, and its choice rule was not traced. If the ELSC back end is selected, console text leaves as L1 frames with address byte `0x40 | N` (`0x1fc0d2fc`): no such frame in the captured transmit stream means the PROM has not printed through it. A capture settles it: break at `0x1fc29498`, `0x1fc294f4` and `0x1fc3c9ac` and note which fires first.

## Not settled

| Item | Route |
| --- | --- |
| Which blocking console read the CPUs are in | `[sp+8]` and `[sp+48]` of the `0x1fc144b8` frame at a stuck CPU |
| What the 0x0006 loop does in the run | the offset and "bytes left" of successive `0x0006` frames |
| The console back end and who prints first | breakpoints at `0x1fc29498`, `0x1fc294f4`, `0x1fc3c9ac` |
| Whether the UART model applies CTS | the model's UART source |
| The requests `0x000e` and `0x0004` waits | read their callers |
