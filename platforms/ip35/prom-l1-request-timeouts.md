# IP35 PROM 6.210: what the boot PROM does when the system controller does not answer

Question. The IP35 boot PROM sends requests to the node's system controller (the L1) over a UART. If the controller is silent, how long does each request wait, how often is it repeated, and does the PROM go on, fall back or stop?

Method. Disassembly of the shipped IP35 PROM 6.210 (SGI Version 6.210, built Aug 26 2004; container segment `ip35prom`, unpacked sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`). Addresses are image addresses, `0x1fc00000` plus the offset. The PROM reaches its string literals and some constants through a global-pointer table at the end of the segment (the table entries are section bases; a literal is a base plus a 16-bit offset), so literals were resolved by folding `ld`, `lui` and `daddiu` sequences by hand and by a small straight-line tracker over the whole listing; branch targets were followed by hand. Nothing was run. The controller's side of the same exchange is in the sysco repository (`software/firmware/l1/`). Only 6.210 was read; the 6.211 image was not.

Grades: **established** (the whole routine was read and the claim follows), **inferred** (reasoning stated), **unknown**.

## Answer

1. **Established: a request is sent once and waits once.** The request primitive (`0x1fc63d38`, called by every general L1 request wrapper) sends the encoded request and then waits for the reply for **2,000,000 timer units** (`lui 0x1e` / `ori 0x8480` at `0x1fc63df8`), after which it returns the code `-4`. It does not send the request again. The wrappers turn any nonzero result of the primitive into `-100` after releasing the request slot (`0x1fc63e18`), so the caller cannot tell a timeout from another failure.
2. **Established: the only repetition is on the send side.** If the transmit routine accepts fewer bytes than the request length (`0x1fc534b0` returns `-6`), the primitive waits 500 timer units (`0x1fc63d94`, call to the delay routine `0x1fc0eefc`) and sends again, up to 49 more times (`addiu $16,$0,49` at `0x1fc63d84`), so up to 50 sends and at most 24,500 timer units of delay. This happens only when the transmit ring has no room. A controller that is merely silent does not trigger it.
3. **Established: the timer unit is a microsecond of the PROM's own clock.** The routine at `0x1fc6b73c` returns the hub real-time counter (`0x9200000001030100`) scaled by `((register at 0x9200000001604200 and 0x3ff0) >> 3) + 2` divided by 200; the delay routine `0x1fc6b79c` applies the inverse. The PROM treats the result as microseconds (it adds 1,000,000 for a one-second limit at `0x1fc0ef3c`). That this equals wall-clock microseconds is **inferred**: it depends on the register at `0x9200000001604200` holding the clock ratio the formula assumes.
4. **Established: the router-style chunk reader waits twice as long.** The reader for chunked replies (`0x1fc53688` onward, call to `0x1fc533e4` at `0x1fc53844`) waits **4,000,000 timer units** for each chunk (`lui 0x3d` / `ori 0x900` at `0x1fc537ec`) and prints `IRouter Error:sc_recv_poll failed, rstat:%d` (`0x1fc538e4`) and returns `-1` when one times out. The ordinary request wrappers do not use it.
5. **Established: no caller found on the boot path stops the boot.** The requests the main routine (`0x1fc698dc`) makes on its own straight-line path, in order, and what each does with a failure:

   | Order | Call | Request | On failure |
   |---:|---|---|---|
   | 1 | `0x1fc69ad0` to `0x1fc68f48` to `0x1fc503bc`, which opens the port (`0x1fc0f308`) | debug switches (function 6, code `0x0001`) at `0x1fc0f4d4` | the result is ignored; the two result bytes were zeroed first, so the debug switches read as 0 |
   | 2 | `0x1fc69aec` to `0x1fc68e30` | per-processor setting (code `0x100c`, argument 20) | the status is not tested by the caller |
   | 3 | `0x1fc69b20` to `0x1fc68ba0` (the brick-type classifier) | brick type (code `0x0003`) | skipped for board classes `0x4000` (Origin 300 and Fuel) and `0x8000`/`0xc000`; for the others a failure prints a diagnostic and returns class 0 |
   | 4 | `0x1fc69b3c` to `0x1fc689ec` | event subchannel clear (code `0x100a`) | status ignored |
   | 5 | `0x1fc69b4c` to `0x1fc68964` | debug switches again | the state word is left untouched (bit 17 stays clear) |
   | 6 | `0x1fc69ba4` to `0x1fc68724` (through `0x1fc24cc8`) | brick type and rack/bay (code `0x0003`) | the routine returns the error; main sees a result of zero or below and branches to `0x1fc6b2a0`, which takes the module number from the stored variable `LastModule` (default `0`) and goes on at `0x1fc69bc0` |

   After step 6, if this processor passes the per-slice test at `0x1fc68f64` (it tests bit `0x10 << slice` of the register at `0x9200000001400150`; reading it as the boot-slice test is inferred) and bit 17 of the state word is still clear, main takes `0x1fc6b2d8`: it prints `*** System Controller DIP switches unavailable` and a menu of diagnostic levels, waits up to **6,000,000 timer units** for a line (`lui 0x5b` / `ori 0x8d80` at `0x1fc6b30c`, input routine `0x1fc67dc8`, default text `0000`), merges the answer into the state word and goes on. So a silent controller costs the boot slice 2,000,000 units for each of requests 1, 2, 4, 5 and 6, another 2,000,000 for request 3 on board classes that ask, and up to 6,000,000 at the prompt, and then the PROM continues. The sum for the five certain requests and the prompt is **16 s** at one unit per microsecond (inferred for the unit, established for the counts); with request 3, 18 s. Later requests on the main path (`0x1fc6a53c`, `0x1fc6aefc` onward, `0x1fc6b134` onward) were not traced for their conditions, so the total is a lower bound.
6. **Established: console selection falls back to the previous console.** The routine behind the `elsc` console choice (`0x1fc29498`) probes the controller with the same primitive; on success it prints `Switching to ELSC UART` and switches, otherwise it prints `ELSC not responding.` and leaves the console where it was (`0x1fc294e0`). The twin routine for the junk-bus UART (`0x1fc294f4`) does the same with `Junk UART not responding.`.

So, for the questions as asked: **retry count 0 (one send, one wait); wait per try 2,000,000 timer units, about 2 s; total about 2 s per request, not 4 s; next step: continue.** The 4 s figure belongs to the chunked reader (item 4) and is not the time the ordinary request waits.

## Not settled

| Item | Why open |
|---|---|
| Wall-clock length of a timer unit | needs the content of `0x9200000001604200` at run time; the PROM assumes the formula of item 3. Every constant-address use of that register found in the listing is a load (the timer routines at `0x1fc6b630` to `0x1fc6b7c0` and one use at `0x1fc0dd3c`), so the PROM does not set it on the paths read; stores through computed addresses were not excluded |
| The conditions around requests after step 6 of the main path and the totals beyond 16 s | later call sites not traced |
| What the PROM does if the reply arrives after the 2 s limit | the late frame is dropped by the slot that was released (inferred from the release at `0x1fc63e18`); not traced through the frame parser |
| Whether any caller outside the main path retries a failed request | the 27 call sites of the primitive were listed; only the six above and the console routines were read |
| The 6.211 image | not read |
