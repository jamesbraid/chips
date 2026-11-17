# Altix 350 PROM: the L1 requests from reset to the console

Every request the SAL 5.04 SHub 1 PROM (`shub1snprom.bin`, snprom-10.54-70399, sha256 `51ccf9ad830b...`) sends to the system
controller (the L1) between processor reset and the start of the console, in the order a single-node Altix 350 (module type
`F`, one SHub 1, 2 GiB, one processor) issues them, with what the PROM reads from each reply and what it does when the reply is
wrong. It is written so that an L1 model can answer every request in order. The wider path is in [boot-sequence.md](boot-sequence.md);
the L1 side of the same link is in the sysco repository, `software/firmware/l1/` (pages `sn2-prom-link-1.62.1.md`,
`sn2-dimm-spd-request.md`, `sn2-l1-settings-defaults-1.62.1.md`, `node-link-sn1-vs-sn2.md`).

**How it was read.** The order and the call paths come from the IA-64 Ghidra module (`retools/tools/re-run --ghidra-export IMAGE
--sn2-prom` for the call graph and decompiled C, and its `DecompileAt` script for functions the export does not reach, such as the
code entered after the jump to RAM). Decompiler output is navigation: every constant quoted here (call-site addresses, request codes,
argument values, status literals) was checked against `ia64-linux-gnu-objdump -z` or the image bytes. Function names are the
reviewed names from the boot-sequence page where they exist; otherwise the address.

**Grades.** *established*: the whole function and its callers read, values checked. *inferred*: a reading from a call list, a name or a
sibling image, or a path whose gating condition was not evaluated. *unknown*: not settled.

## Conventions used below

- **Frame.** The PROM builds a request with `sysctl_cmd_construct_req` (`0xffa81f40`; 23 call sites, all accounted for in the table
  at the end) and sends it with `sysctl_cmd_command` (`0xffa82c10`, which is `0xffa82a10` with a timeout of `0x2dc6c0` ticks). Payload:
  bytes 0 to 3 big-endian destination word, bytes 4 and 5 request code, then, **only when the request has arguments**, byte 6 argument
  count and the arguments (tag `0` plus 4-byte big-endian integer; tag `1` plus NUL-terminated string; tag `0x80|n` plus n raw bytes).
  A request with no arguments is exactly six payload bytes with no count byte: the builder's sixth parameter (argument slots, two
  per integer or string, three per raw block) is tested at `0xffa81ff6` and a zero sends it to `0xffa82150`, which returns length 6
  (established, Ghidra and objdump of `0xffa81f40`). The requests `0x0001`, `0x0003`, `0x0009`, `0x000e`, `0x0010` and `0x0013` pass 0
  (routine, call site: `0xffa7d040` at `0xffa7d0dc`, `0xffa7ca10` at `0xffa7ca9c`, `0xffa7db00` at `0xffa7dc7c`, `0xffa7ce90` at `0xffa7cf1c`,
  `0xffae8250` at `0xffae82fc`, `0xffa7cbe0` at `0xffa7cc6c`); `0x100b` passes 6 (count 3) and
  `0x1005` passes 2 (count 1). Wire example for `0x0003`: `7e 05 0f ff f0 06 00 03 69 27 7e`. The ARM L1 reads the count only when the
  frame is longer than 7 bytes before the CRC and takes 0 otherwise, so both ends agree (sysco `sn2-prom-link-1.62.1.md`). The destination word is the open target
  ORed with 6 (the task). Every request on the main path is opened with target `0x0ffff000`, so the word is `0x0ffff006`
  (established, `sysctl_cmd_open` `0xffa819c0` and each wrapper's constant); the `0x4ffff006` form belongs to a second wrapper set that
  `0xffaac4b0(4, ...)` selects through the dispatch run `0xffa80210` to `0xffa80580` (the I/O board path, not read end to end; which
  mode each caller passes was not traced): `0xffa7e3b0` (request `0x0003`, entered through `0xffa7e5e0` at `0xffa80430`), `0xffa7e6d0`
  (request `0x0013`, with the `0x0003` fallback in `0xffa7cbe0`) and `0xffa7e900`. The target is set at `0xffa7e446`, `0xffa7e836`
  and `0xffa7e946`. The `0xffa7e3b0` wrapper calls the `0x0003` routine `0xffa7ca10` at `0xffa7e51c` with `0x4ffff000` and has no
  slab lookup and no type fold (those are in `0xffa7d510`, which belongs to the `0x0ffff000` set). Every other `0x0003` site
  (`0xffa7d34c`, and `0xffa7d8ac` through `0xffa7cbe0` in the `0x0013` wrapper) passes `0x0ffff000`. Established for the constants
  (objdump, all seven `movl ...0x4ffff000` sites); the `0x4ffff000` literal also appears at `0xffa819d6`, `0xffa855b6`, `0xffa910a6`
  (the `0x100b` twin) and `0xffb5efc6`.
  The L1 ignores everything but the task number.
- **Wire framing** (established, `0xffa86c90`): flag `0x7e`, one header byte, the payload with `0x7e` and `0x7d` escaped as `0x7d`
  plus the byte xor `0x20`, the complemented CRC-16 (initial `0xffff`, reflected `0x8408`, standard table at `0xffbe1190`; it runs over the
  header byte and then the unescaped payload, and the two CRC bytes are escaped too) low byte first, flag `0x7e`; payload
  clamped to 127 bytes. The request header byte is the open handle: `5 + processor slice` (slice = `cr.lid` bits 26:23), so 5 for
  the boot processor, up to 19 when several are open. Console traffic uses `0x40 | slice` (class 2).
- **Reply** (established, `sysctl_cmd_interpret_resp` `0xffa82270`): the receiver (`0xffa87830`) takes frames whose header byte is
  `0x20 | n` or `0x40 | n` for n from 5 to 19, or a byte from 0 to 4 with class bits clear, and checks the CRC; the PROM then reads status in bytes 0 to 3 (big-endian), the
  argument count in byte 4 and arguments from byte 5. Status 0 is success. Status `-106` selects a second status at bytes 6 to 9
  (that value minus 106000). Any other status is returned to the caller unchanged. With status 0 each caller supplies a list of
  expected arguments; a tag that differs from the expected type gives `-32` and a count that differs from the expected count gives
  `-33`. So a reply with the wrong number of arguments is an error, never ignored. Reply header byte: `0x20` plus the request's header
  index.
- **No reply, send failure.** `0xffa82a10` retries a partial send up to 50 times (500 ticks apart; status `-26`), any other send error
  returns at once. If no reply frame arrives before the deadline (`0x2dc6c0` ticks after the send), the receive returns `-24` and the
  routine calls the node-die routine `0xffad2cb0` with progress code `0x8d` ("Critical system controller transaction failed").
  Every request below goes through this routine (`0xffa82c10` is `0xffa82a10` with the timeout), so the die call precedes whatever the
  request's own caller does with the `-24`. As read in the review below, the die routine shows `ERR 8d` on the display, then writes
  a write of `0x1_0001_0000_0000` to `0x1_2000_0000` (called the CRB message-control store on this page: the register is `SH_CRB_MESSAGE_CONTROL`, which clears the coherence enables and does not reset the node as far as the header shows; see "The park path's inputs") and, for the local node and the calling processor's own slice,
  does not return: it enters `0xffaeb7c0` (cache init, `rfi`, then an endless `PAL_HALT_LIGHT` loop at `0xffaeb8d0`). Read the review
  section "Silence" before relying on a model that withholds a reply. This applies to `0x100b` as well.
- **Gating.** Most requests are made only by the node's master processor (`0xffa0ff30` returns 1 when no lower-numbered processor is
  flagged present; the single processor of a one-CPU node qualifies) and, for the display text, only while bit 6 of the node object's
  flags is set (set at the end of the link start, cleared by the node-die routine). A processor that runs under the simulator CPU ID
  signature (`cpuid[2] == 0xaeeeeeee8badbeef`) sends nothing.
- **Caching.** The identity wrappers keep results in the node object (a bitmap plus values at object offset `0xa8`:
  `0xffa81510` checks, `0xffa81630` stores). A cached value is never asked again. Whether the cache survives the jump to RAM
  (`0xffac6bb0`, progress `0x19`) was not read (unknown); every identity request below that appears "again" after the jump is
  conditional on that.

## The link start before the first request

Established unless stated; functions read in Ghidra, constants cross-checked.

1. **Chip selection.** `sysctl_state_init` (`0xffa8b5d0`, reached from `sysctl_init` `0xffa1f430`, progress `0xd`, through
   `0xffa8f8a0` on the node that is its own master) zeroes a `0xeb8`-byte state object and asks a registry (`0xffa0f7e0`, array at
   `0xffbd8a18`) for the method table whose match function accepts the part number. The SHub 1 match function `0xffa959a0` accepts
   `0x4363`; the table is at `0xffbd7c18`. The state object's flag word at offset `0x50` is set to bits 1 and 3 (not bit 5), so the
   UART is driven by direct SHub junk-bus accesses, not through the alternate accessor.
2. **Software lock.** `0xffa93cd0` (method `+0x238`) takes a lock bit 6 in the SHub scratch register at `0x81_5003_1540` through
   `0xffa0f1a0` (spin with a `10000000`-tick limit; on timeout it releases and retries); `0xffa93d80` (`+0x240`) releases it. Plain
   read/write storage is enough (inferred from the access pattern).
3. **UART programming** (`sc_uart_init` `0xffa937b0`, method `+0x228`). Runs only if bits 41:39 of `0x81_101d_0100` read 7 (the
   value SAL_A set when this processor won the election). Registers are 16550-style at `0x8000000ffed40000 | nasid << 38` with an
   8-byte stride. In order: poll line status (`+0x28`) until bit 6 is set, or give up after `100000` ticks (10-tick delays);
   read line control (`+0x18`); write it back with bit 7 set; write `0` to the divisor high byte (`+0x08`), `1` to the divisor low
   byte (`+0x00`; the divisor comes from method `+0x280`, `0xffa94340`, which returns 1); write line control with the original
   value and bit 7 clear; write line control `3` (8 data bits, no parity, one stop); write modem control `+0x20` = `0x22`; write the
   interrupt enable `+0x08` = `0`; write FIFO control `+0x10` = `0xc7`; read the scratch register `+0x38`. No bytes are sent.
4. **State register.** Back in `0xffa8b5d0`, with bits 41:39 equal to 7 the code clears them, reads bits 49:42 into the object,
   writes that field plus one, and clears bit 63 of `0x81_101d_0100` (the register address is method `+0x270`, `0xffa94300`). The
   receiver (`0xffa87830`) later uses the same bit field as its parse state. A model should back this register with plain storage
   starting at the value SAL_A leaves (bits 41:39 = 7).
5. **Handshake.** None. The PROM sends no sync or hello frame and does not wait for a line-up byte. The first bytes on the wire
   are the first request frame. (Established: neither `0xffa8b5d0`, `0xffa937b0` nor the send path `0xffa86ed0` writes a byte
   other than a request or console frame.) Receive bytes are read from the receive buffer register (`+0x00`) when line status
   (`+0x28`) bit 0 is set; bits 1 to 3 set with bit 0 clear read as a line error.

## The requests, in order

"Needs" is what the PROM's reader requires of the reply. "Blank L1" is what the ARM L1 1.62.1 program returns with an empty settings
record (sysco pages above). Function addresses are in the SAL_B flash image.

### 1. `0x100b` PROM version, progress `0xd`

- **Site:** `0xffa90f5c`, routine `0xffa90e60`, called from `sysctl_init` `0xffa1f62c`. The routine's twin `0xffa91060` (site
  `0xffa9115c`, target `0x4ffff000`) has no caller on this path.
- **Arguments:** three integers: `1`, then `5`, then `4`. The last two are the bytes at `0xffba20e8` and `0xffba20e9`, the PROM
  version (5.04); the same bytes feed the version field in `0xffa46540`. (Established: image bytes read.)
- **Reply read:** `sysctl_cmd_command` is run, then the reply is parsed with an expected list of zero arguments. The result of
  the routine is ignored by `sysctl_init`.
- **Needs:** status 0 and argument count 0 (a different count only changes a status the caller drops). The real L1 sends no reply
  (next bullet); the 3,000,000-tick wait then ends in the `0x8d` die path above.
- **Repeats:** once per node object; no retries.
- **L1 handler:** `L1ReqIRouter` code `0x100b`, `0xcb474`. It checks four arguments (counting the code) and **sends no reply on success**
  (sysco `12e3608`, section "The 0x100b reply": established, L1 1.62.1). The PROM waits the full timeout (`0x2dc6c0` ticks through
  `0xffa82c10` and `0xffa82a10`), calls `0xffad2cb0` with progress `0x8d`, and `sysctl_init` ignores the `-24` it gets back: the
  caller at `0xffa1f62c` is followed at once by the return (established, re-read in the review). **Resolved against sysco's first
  reading:** `0xffad2cb0` does not return for the boot processor, so the PROM parks (see "Resolution of the sysco conflict" below, and
  sysco `331df54`). A model that stays silent for `0x100b` reproduces the 1.62.1 L1 but parks the boot processor; what ends the wait on
  a real brick is not known. A model that answers it (status 0, no arguments) is accepted by the PROM, as an approximation. Real boots of builds 4.56, 4.65 and 4.80 passed this wait with the same die and park code ("Real boots and the other PROM builds" below).
- **Blank L1:** same, no reply. Grade: request, arguments, reader, no reply from L1 1.62.1: established; the PROM parks the boot
  processor after the missed reply: established for the code; what ends the wait on real hardware: unknown.

### 2. `0x1005` display text "Prom starting..."

- **Site:** `0xffa7e09c`, routine `sysctl_display_text` `0xffa7df40`, call from `main` at `0xffa1a5ec` (block entered from
  `0xffa19d6c`), after `0xffa3e5d0`.
- **Gating:** master processor, display flag (bit 6) set.
- **Arguments:** one string, the text (truncated: a NUL is stored at byte `0x48` if longer).
- **Reply read:** zero expected arguments.
- **Needs:** status 0, count 0. Errors are ignored (the text is cosmetic and `main` drops the status).
- **Repeats:** one per message; the same routine sends, in this path, "Init memory..." (after request 11), "Init Intercon..." and
  "Init I/O..." and "Running" (later sections).
- **L1 handler:** `0xcaeb4`; replies with status 0 and no arguments, and -100 if the count is one or less. Blank L1: status 0, none.
- Grade: established.

### 3. `0x0003` rack, bay, type

- **Site:** `0xffa7ca9c`, routine `0xffa7ca10`, reached from `main` at `0xffa19d8c` (`0xffaac4b0(2, nasid)`) through `0xffa80210`
  -> `0xffa7d510` -> `0xffa7d1f0` (cache key 0 miss). First identity request of the run.
- **Arguments:** none.
- **Reply read:** two integers: the module word and the type. The type is lowercased by the PROM if it is a letter `A` to `Z`
  (`F` becomes `f`, `0x66`). The module word is cached; its bits 15:6 (rack) and 5:0 (bay) are split out by `0xffa7d1f0`; it masks the word to 20 bits and keeps ten of them for the rack, so a larger rack number is truncated.
- **Needs:** status 0, count 2, tags 0 and 0. On `F` the later type switch (`0xffa7d510`) sends the next request.
- **On error:** the wrappers return -1 and the later users get an unknown module; not fatal here.
- **Repeats:** once (cached) unless the cache is lost.
- **Type `o`:** when the type letter is `o` the identity wrapper `0xffa7d1f0` follows with up to eleven board-area EEPROM reads
  (`0xffa84fd0`, site `0xffa7d46c`) until one succeeds; not reached for `F` (inferred for the arguments: not traced).
- **Reply on the wire** (established, L1 1.62.1 handler `0xc8bb8` and `syscom_process_outbound_response` `0xc3f64`; the handler is shared with
  `0x0002`, which sends only the first integer): `20|subchannel`, status `00 00 00 00`, count `02`, `00` plus the module word big-endian,
  `00` plus the type character as a 32-bit big-endian integer: 16 payload bytes before the CRC. For an Altix 350: word `rack << 6 | bay`,
  type `0x46` (`F`, inferred). The PROM accepts it when the status is 0, the count is 2 and both tags are `0x00` (`0xffa82270`, expected
  list of two integers from `0xffa7ca10`); a wrong tag gives -32, a wrong count -33. After lowercasing (`f`), `0xffa7d510` asks `0x000e`
  and turns the type into `c` if the slab is 0 or -1. The observed destination `0x0ffff006` is the `0xffa7d1f0` path; the `0xffa7e3b0`
  wrapper would send `0x4ffff006` (`sysctl_cmd_open` `0xffa819c0` rewrites a `0x4ffff000` target to `0x0ffff000` when the node's cached type is `m` or `o`).
- **L1 handler:** `0xc8bb8` (sysco, established): `rack << 6 | bay` then the type character. Blank L1: 0 and the brick type (inferred `F`).
- Grade: request, reader, order: established; `F` for an Altix 350: inferred.

### 4. `0x000e` slab

- **Site:** `0xffa7cf1c`, routine `0xffa7ce90`, reached from `0xffa7d950` (cache key 4), called by `0xffa7d510` because the lowercase
  type `f` (as `l`, `b`, `{`) triggers a slab lookup.
- **Arguments:** none.
- **Reply read:** one integer (the slab). On error the routine returns -1.
- **Special effect:** if the slab is `0` or `-1`, `0xffa7d510` replaces the type with `c` (99). If a one-node Altix 350 reports slab 0
  (inferred, see the review at the end), the type seen by the PROM becomes `c`.
- **Needs:** status 0, count 1.
- **Reply on the wire** (established for the shape, L1 1.62.1 handler `0xca214`): `20|subchannel`, `00 00 00 00`, `01`, `00` plus the slab as a
  32-bit big-endian integer (a zero-extended byte): 11 payload bytes. For a single-slot type the blade workaround is skipped and the slab
  is `SysComGetSlab` of the request's source tag (0 for the lone node: inferred). The PROM (`0xffa7ce90`, expected list of one integer)
  holds it as a signed char, so `0xff` reads as -1; the caller `0xffa7d950` caches it under key 4 unless it is -1 (a reply of `0xff` is returned but not cached). In `0xffa7d510` the condition is
  `(slab + 1) & 0xff < 2`, so slab 0, 0xff or a failed request give `c`, and slab 1 to 254 keep `f`. The type and module word then go to
  `0xffa7d010`, which packs `rack << 16 | type << 8 | bay`.
- **L1 handler:** `0xca214`. Blank L1: 0 (inferred).
- **Repeats:** cached.
- Grade: established (order between this and `0x0013`: `0x000e` first, from `0xffa7d510` itself; this resolves the open order question
  in the reviewed table).

### 5. `0x0013` slot

- **Site:** `0xffa7cc6c`, routine `0xffa7cbe0`, from `0xffa7d760` (cache key 3), called by `0xffaac4b0(2)` after the type.
- **Arguments:** none.
- **Reply read:** two integers: slot, then a type character (lowercased as above; values of 0x100 and up go to a helper `0xffaac0a0`).
  The slot is cached; the character is only checked.
- **Needs:** status 0, count 2. A status of -101 (unknown request) makes the PROM fall back to `0x0003` for the slot (inferred from the
  call at the end of `0xffa7cbe0`).
- **L1 handler:** `0xca2f8`; for type `F` with one slot: `0` then the type character (sysco). Blank L1: `0`, `F`.
- **Repeats:** cached.
- Grade: established.

### 6. `0x0009` partition

- **Site:** `0xffa7dc7c`, routine `0xffa7db00`, call from `main` at `0xffa19dec` (after `0xffaac4b0(2)` stores its result).
- **Arguments:** none.
- **Reply read:** one integer (byte stored at node object offset 5; cached key 5). On error it returns -1 (stored as 0xff; later
  code in `0xffaa9d70` replaces it with 0 and prints a message).
- **L1 handler:** `0xc9e94`, setting 14. Blank L1: 0 (inferred: no default stored for that setting).
- **Repeats:** later calls from `0xffaa9d70` hit the cache unless the first one failed.
- Grade: established.

### 7. `0x0001` debug switches, progress `0xe`

- **Site:** `0xffa7d0dc`, routine `0xffa7d040`, call from `main` at `0xffa19e2c`.
- **Arguments:** none.
- **Reply read:** one integer. `main` keeps the low 16 bits; if the status is not negative and this is the master it stores the word
  in `0x81_5003_1560` (`0xffa974d0`) and sets flag 11 in `0x81_5003_1550` (`0xffa0eae0`).
- **On error:** flag 11 stays clear and `main` later prints "System Controller DIP switches unavailable" and asks on the console
  (`0xffad2f10`). Bit 11 of the stored word (`0xffa975e0(11)`) selects the single-node interconnect skip; bit 8 gates request 8.
- **L1 handler:** `0xc8b74`. Blank L1: status 0, integer 0 (sysco, established). With 0 the PROM takes the interconnect-discovery
  branch rather than the skip (see the boot-sequence page for what that costs; the `0x800` conflict is recorded there).
- Grade: established.

### 8. `0x0010` processor presence, progress `0x10`

- **Site:** `0xffae82fc`, routine `0xffae8250`, from `sysctl_cpu_presence` `0xffae8660`, from `main_early_disable` `0xffad34a0`
  (called at `0xffa1a55c`).
- **Gating:** only if debug bit 8 is clear (`0xffa975e0(8)` false), so on a blank L1 it is sent.
- **Arguments:** none.
- **Reply read** (parsed by hand, not through `0xffa82270`): status bytes 0 to 3 must be 0 (else the status goes back); then
  tag/integer pairs: node count (must be at most 4), CPU count (at most 16), and for each node a presence word then an enable word.
  The routine returns `presence[slab] & enable[slab]`, the slab from the cache (`0xffa11a10` or `0xffa7d950`). A bad count gives
  `-100` (`0xffffffffffffff9c`).
- **Reply layout** (byte offsets, read from the hand parser): status 0 to 3; byte 4 (argument count) and the tag bytes are not
  checked; node count at 6 to 9 (tag at 5); CPU count at 11 to 14 (tag at 10); then per node a presence word (tag at 15, value at 16
  to 19) and an enable word (tag at 20, value at 21 to 24), each tag/value pair 5 bytes. The arrays hold four words; the PROM
  indexes them by the node's slab (0 for one node).
- **Needs for one processor:** status 0; node count 1; CPU count 1; presence 1; enable 1. The bit tested is the processor's slice
  (`cr.lid` bits 26:23) in the ANDed word. A clear bit, or any status whose low bit is clear (the `-100` for a bad count is
  `0xffffff9c`), makes `main_early_disable` (`0xffad34a0`) show progress `0x87` and call the same park path as the die routine
  (`0xffa9fba0` to `0xffaeb7c0`) on that processor. Every processor sends this request, not only the master.
- **L1 handler:** `0xca5f4`; reply order status, node count, CPU count, then per node presence and enable (sysco). Blank L1: not
  determined by the settings record (taken from the board's I/O expanders): unknown.
- **Repeats:** not cached. Asked again in `main_two` (request 13) and in `main_three` (request 16).
- Grade: request, reader: established; values: inferred.

### 9. `0x0006` DIMM SPD, sixteen requests, between progress `0x14` and `0x15`

- **Site:** `0xffa8450c`, routine `0xffa843f0`, through `sysctl_eeprom_dimm` `0xffa85470` and its wrapper `0xffa84680`, driven by the
  "Probing memory DIMMs" step `0xffa77bb0` (called from `0xffa78100`, `main` at `0xffa1a01c`; master only). The earlier page places
  this under phase `0x16`; the progress code written before the call is `0x14` (`main` at `0xffa19fe6`).
- **Arguments:** four integers: device id, selector `4`, byte offset `0`, length `48`. The device id for bank b (0 to 3) and
  position p (0 to 3) is `8 + ((p & 1) * 4 + b) * 2 + (p >> 1)`. The order is bank-major, p ascending:
  8,16,9,17; 10,18,11,19; 12,20,13,21; 14,22,15,23 (established, `0xffa77bb0` loops and `0xffa85470` arithmetic).
- **Reply read:** one integer ("bytes left", ignored for a 48-byte read) and one raw block (tag `0x80|n`, the SPD bytes, up to 64
  per chunk, copied to a 256-byte buffer); expected count 2. The first 48 SPD bytes are the ones the PROM uses (see the SPD
  review in boot-sequence).
- **Needs for a present DIMM:** status 0, count 2, int then raw.
- **On error:** any negative status or wrong count makes that slot absent (the routine returns 1; status -107 returns 3, still
  absent). If the open fails it returns 1. If every slot is absent the PROM later stops with "No memory on node" (progress `0x80`).
- **Repeats:** all sixteen are sent whether or not earlier ones succeed. A 2 GiB node needs the first four present (ids 8, 16, 9, 17)
  and the last twelve answered with an error status; the L1 for type `F` returns -104 for 14, 15, 22 and 23 and for any
  unpopulated slot (sysco).
- **L1 handler:** `0xc9658`. Blank L1: -104 for every device (presence flags are clear, sysco: not settled what sets them).
- Grade: established.

### 10. `0x1005` display text "Init memory...", progress `0x16`

Same routine as request 2; site `0xffa7e09c` through `main` at `0xffa1a3ec`. Master only. Grade: established.

### 11. `0x0015` sharing mode

- **Site:** `0xffa7fbbc`, routine `0xffa7fab0`, from `0xffa46540` (entered through the stub at `0xffa46530`, called at `0xffa1a37c`, master only, after the "DEX POD" check).
- **Arguments:** none.
- **Reply read:** one integer; on error the routine returns -1 or the status. The value goes (masked to 4 bits) into a configuration word
  passed to the node operations table (`+0x170`); it is not otherwise tested.
- **L1 handler:** `0xccc80`. Blank L1: 0 (inferred).
- Grade: established for the request; the use of the value is inferred.

### After the jump to RAM (`main_two`, `0xffa1ade0`)

12. **`0x1005` "Init Intercon..."** at `0xffa1b41c` (master only). Established.
13. **Board EEPROM read for the hub record, then `0x0010`.** `0xffa9fe80(nasid, 0x11, 0)` runs `init_klcfg_hub` (`0xffaa1ea0`). It calls
    `0xffaa1310`, which fills the klconfig board string through `0xffaeccd0` -> `0xffa84fd0` with a NULL chassis pointer and a board
    buffer, so only the **board area is read: device id 1, selector 2, offset 0**, then offset 64, 128, ... in 64-byte chunks until
    the "bytes left" integer is 0 (`0xffa843f0` passes length 64 and stops when the next length is 0). Expected reply per chunk:
    status 0, count 2, int (bytes left), raw bytes. The bytes must be an IPMI-style board area (format version, length in 8-byte
    units, checksum making the whole area sum to 0, fields ending `0xc1`; see the boot-sequence page). A failure is non-fatal
    ("Could not retrieve EEPROM info on nasid"). Then `0xffae8660` sends `0x0010` again with the same reply requirements as
    request 8 (`0xffaa1ea0`; `param_2 == 0x11` branch). Grade: established for the path and arguments.
    If the identity cache did not survive the jump, `0x0003`, `0x000e`, `0x0013` and `0x0009` are asked again at their first use here.

### I/O discovery and the console (`main_three`, `0xffad7280`)

14. **`0x1005` "Init I/O..."** at progress `0x24` (`0xffad789c`). Established.
15. **I/O board EEPROM read: `0x0006`, device id 98, selector 2 (once per PIC widget).** See the section "Request `0x0006` in I/O
    discovery" below.
16. **Progress `0x25`** (`0xffa485a0` writes it at entry, `0xffa0ddb0(0x25)`; no write of `0x26` was found between its call at `0xffad761c` and the `0x27` write at `0xffad7766`). If this is the partition master (flag 1 in `0x81_5003_1550`, set by the master election code), `0xffa485a0`
    sends `0x0012` (`0xffa7ea90`, site `0xffa7ebfc`): no arguments, one integer reply; any error or any value below 0x800 becomes
    0x800, so only status and count matter. `0xffaa03f0` then sends `0x0010` again per node (`0xffad3ed0`) and `0x0008`
    (`0xffa7dda0`, site `0xffa7de3c`: no arguments, one string reply; an error, for example the -104 a blank L1 returns, selects a
    default text and is not fatal). The partition is requested again but cached. Then `0x1005` "Running" (`0xffad79ac`).
    Grade: path established, gating on flag 1: inferred.
17. **Console.** `console_probe` (`0xffa1fca0`) walks the spec string and selects the first character whose probe passes. In `main`
    the spec is `pd` (string at `0xffba7cd0`): the `p` probe (`0xffae9200`) passes whenever the CPU ID signature is absent, so the
    console is the L1 console. In `main_three` the spec is `rpd` (`0xffbba0a0`): the `r` probe (`0xffaea490`) passes the same way, so
    the console moves to the remote-console index. The `d` direct console (`0xffaeaff0`) is used only if both fail; its probe
    writes `0x55` then `0xaa` to the UART scratch register `0x8000000ffed40038 | nasid << 38` and needs each read back.
    **No numbered request is sent for the console.** Characters leave as class-2 frames (`0xffae96f0` -> `0xffa86ed0`, header
    byte `0x40 | slice` for `p`, index 4 for `r`: `0x44`), up to 127 payload bytes per frame. Typed characters arrive in a different class (class 0, index 4 for `r`: header `0x04`; see "Console input" below). The PROM's own
    console init for `p` (`0xffae87f0`) only re-reads the cached type, slot and slab. Grade: established for the probes and
    framing; which console index a given phase prints on: inferred.

After `Running` the PROM loads the EFI image (`0xffaf8c50`, "Loading EFI", progress `0x27`); no further L1 request is sent before
the EFI hand-off in the code read (established for the direct calls; indirect calls through the node operations tables were not
all resolved).

## Request `0x0006` in I/O discovery

Read on 2026-11-16 in the Ghidra decompiles of snprom 10.54 (`shub1snprom.bin`, flat at `0xffa00000`; `--sn2-prom --no-analysis`, address
ranges), each branch cross-checked in a flat `ia64-linux-gnu-objdump` listing. A model run that stopped here prompted the reading;
the run is not evidence. Nothing was run.

**What it is (established).** The board-information-area read of the I/O board's EEPROM, the same transfer as request 13, aimed at
the I/O side. The model's stop is request code `0x0006`, destination `0x0ffff006`, four tag-0 integers `0x62`, `2`, `0`, `0x40`
(bytes `00 00000062 00 00000002 00 00000000 00 00000040`, the 20 argument bytes with no count byte; the frame's count byte is 4).

**Call chain (established).** `0xffab38b0` prints "Discovering local I/O on nasid %d" (master only, through `0xffaad6d0`, called from `main_three` at `0xffad756c`), then `0xffab15c0` reads the widget identification word at `nasid << 38 | 0x8000_0008_0000_0000` and, for a crossbar
part (`0xd000`/`0xd100`), walks the widgets in `0xffab0f10`. For a widget whose id part is `0xd102` (PIC) it runs the PIC set-up
`0xffab0c00` on head 0 and on head 1 (`W + 0x80_0000`; the register writes are in [devices/pic](../../../devices/pic/README.md#prom-set-up-of-a-pic-in-main_three-0xffab0c00)), then `bridge_discover`
`0xffabfb10`. That calls `io_mfg_info` (`0xffaf1ee0`, site `0xffac01fc`; a second caller site, `0xffaaeafc`, is in `0xffaae7f0`, the same read
for another widget class; see the review below). An even node number selects `0xffaecd80`, which calls `0xffa85550`; an odd one selects `0xffaeccd0` and the id-1 path of
request 13 (`0xffa84fd0`). So it runs **once per PIC widget** (once on a lone node with one PIC), not per head and not per brick.

**Arguments (established).** Device id `0x62` (98) when the module type the L1 reported for `0x0003` is `o` after lowercasing (`0x6f`), else 1
(`0xffa85550`). A blank L1 that answers the type letter `O` therefore gets 98; an `F` module (the ARM L1 1.62.1 reading) is `f`, then `c`,
and gets id 1. Selector 2 (board information area), offset 0, length 64; the loop in `0xffa843f0` repeats at offset 64, 128, ... until
the "bytes left" integer is 0 (at most 64 bytes a chunk; the caller passes total length 0, which becomes 0x40000000, so only
bytes-left ends it; the parse buffer is 496 bytes and nothing bounds the total).

**Destination (established).** `0xffa85550` opens target `0x4ffff000`; `sysctl_cmd_open` (`0xffa819c0`) rewrites it to `0x0ffff000` when the
cached type is `m` (`0x6d`) or `o` (`0x6f`), so the word is `0x0ffff000 | 6 = 0x0ffff006`: target `0xffff`, task 6, the same as the
requests on the `0x0ffff000` set. For other types it would be `0x4ffff006`; the L1 ignores everything but the task number.

**Reply the PROM reads (established, `0xffa82270` as called by `0xffa843f0`).** Status 0, count 2: integer tag 0 with the bytes left
after the chunk, then a raw block (tag `0x80 | n`, n up to 64) copied to the parse buffer. Then `0xffa84990` parses an IPMI-style board
area: byte 0 version (not compared with anything), byte 1 length in 8-byte units (0 gives "read_board_ia: eeprom length byte of ZERO", return 1), language, a 3-byte
manufacture time, then type/length-coded fields ending at `0xc1`. The sum of the whole area must be 0, else "read_board_ia: bad checksum" and
return 3. A good area is kept as the board string.

**What it uses the fields for (established for the code, inferred for the effect).** `io_mfg_info` first builds the board string from the
parsed fields (`0xffaec9d0`): `Part:`, `;Name:`, `;Serial:`, `;Revision:`, `;Laser:`, then a final `;`. The first four are the area's part
number, product name, serial number and FRU file id fields (inferred from the field order, not from labels); the `Laser:` value is made by the PROM
itself as `%x` of a base-36 hash of the serial's alphanumerics (`0xffaec8b0`), not read from the EEPROM. `0xffabf570` then parses the
hex number after `Laser:` (`0xffa154a0`, base 16) into the widget component (offset `0x28`), copies the whole string to an allocated buffer
(pointer at component offset `0x68`) and copies the component name to offset `0xc1`. The component name does not come
from the EEPROM for type `o`: `0xffabfb10` maps the type letter `o` to the name "onboardIO" (other letters map to other names, an
unknown one to "WEIRDIO") and looks that name up (`0xffabf7c0`, `0xffaed410`).

**Failures (established for the branch structure).**

- Status `-101` (unknown request), `-104` (not present), `-105`, `-107`, any other negative status (`-106` is read differently: see the review), a wrong tag (`-32`) or a wrong count (`-33`):
  `0xffa843f0` returns 1 (status `-107` returns 3, which `0xffa84990` treats the same), `0xffa84990` prints
  "read_board_ia: error reading info area from L1 %d" and returns 1, `io_mfg_info` prints
  "io_mfg_info: Could not retrieve EEPROM info on nasid %d" and zeroes the board string. **Not fatal, and no brick or widget is skipped**:
  `0xffabfb10` goes on with the type-derived name, finds no `Laser:`, and I/O discovery continues. The caller never checks the result.
- Bad version/length/checksum: same, return 3.
- No reply: `0xffa82c10` returns `-24` after `0x2dc6c0` ticks, but the node-die routine `0xffad2cb0` (progress `0x8d`) has already
  parked the boot processor (see "Silence"). This is the stop the model hit: its reply for id 98 was missing.
- A send error, other than the partial-send retries, returns 1 at once (non-fatal).

**Minimal model reply (established that it is accepted; whether the real L1 answers so is inferred).** Status `-104`, no arguments: the same
reply a model already gives for id 1, selector 2. Any complete reply stops the park. Reading the board area needs a valid IPMI area.

**L1 side.** the sysco repository, `software/firmware/l1/sn2-prom-link-1.62.1.md` (section on request `0x0006`): the ARM 1.62.1 handler `0xc9658` maps
id 98 to table entry 18 (RISER) for module type `F` and returns -104 when that record is not present; the ColdFire handlers do the
same mapping for type `O` (id 98 and 99 to records 18 and 19, in `brick-request-handlers.md`). This is an ordinary request with a reply, not the
open `0x100b` wait question.

## Console input

What the L1 sends to the node when a character is typed, and how the PROM takes it. Grades as above.

- **Frame (established, both ends).** `0x7e`, header byte, the raw character(s), FCS-16 low byte first (the same CRC and escaping as the request frames; residue `0xf0b8`), `0x7e`. The header is the console index with the class bits clear: `0x04` for `r`, the boot processor's slice (0 to 3) for `p`. There is no sub-header, type byte or count. The class-2 header `0x40 | n` is the node-to-L1 direction only.
- **Why (established, `0xffa88590` to `0xffa88606`).** The receiver `0xffa87830`, state 1, takes index below 5 only with `(header & 0xe0) == 0`, and index 5 to 19 only with class `0x20` or `0x40`. A header of `0x44` or `0x40` to `0x43` is rejected with -23. The same receiver handles replies and console input; no other routine parses console input. The SAL runtime's `l1sc_receive` (rt `0x53b80`) has the same tests.
- **Where the characters go (established).** The payload bytes are appended unchanged to the 128-byte ring of that index, at `ctx + index * 0x98 + 0x21c` (tentative write index `+0x2a4`, committed write `+0x29c`, read `+0x2a0`). On a good CRC the frame is committed and the ready byte `+0x211` is incremented. An empty payload is accepted. The readers are `p`: poll `0xffae9250`, readc `0xffae93c0`, getc `0xffae9640` (poll in a loop, then readc), reached through `0xffae8b70`, `0xffae8be0` and `0xffae8c50`; `r`: the same routines with index 4 hard-coded, through `0xffae9b60`, `0xffae9c40` and `0xffae9d20`.
- **A frame is only taken while a console poll is outstanding (established for the gate, inferred for the effect).** Poll raises `+0x210` of the index before it calls the receiver; the receiver does not take the payload of an index whose `+0x210` is zero and returns -24. The header byte is already consumed; the payload stays in the UART and is taken by the next poll, except when the index equals the polling processor's own slice or is 4 with bit 2 of `ctx+0x28` set. There the receiver resets to idle, the header is lost and the payload bytes are parsed as new headers (read in Ghidra, not run).
- **Flow control (established: none at the link).** The node sends no acknowledgement or credit. A full ring sets the index's bit in `ctx+0x40`, calls the chip hook at `+0x248` of the chip table (inferred to be the receive-interrupt mask) and returns -21; `readc` undoes it when it takes a character.
- **The L1 sender (established for ARM 1.62.1, sysco `sn2-prom-link-1.62.1.md`).** One character per frame, header = the subchannel the L1 last learned from the node's class-2 frame, so a model answers with `output header & 0x1f`.
- **Worked bytes for "a" (checked with a CRC script, residue `0xf0b8`).** To `r`: `7e 04 61 a8 1a 7e`. To `p` with slice 0: `7e 00 61 c8 7d 5d 7e` (the CRC high byte is `0x7d`, escaped). Return key to `r`: `7e 04 0d 0a 8f ba 7e` in CR LF form.
- **EFI (established for the runtime copy, not for SAL_B's own console rows).** EFI reads through SAL console calls `0x26`, `0x29` and `0x2b`; the runtime's `sc_rt_cons_poll`, `sc_rt_cons_readc` and `sc_rt_cons_getc` call the shared routines with index 4, so EFI input is the same frame with header `0x04`.
- **Unknown.** Whether the POD prompt runs on `p` or `r` (answering with the last output header covers both); the chip hook's exact effect.

## Request 0x1007 and the kernel console

What a Linux SN2 kernel makes the PROM runtime send to the L1 after the PROM has handed over, and how the console works afterwards. Read in the SAL 5.04 runtime component (ELF addresses written `rt:0xNNNN`, Ghidra for the call graph, `ia64-linux-gnu-objdump` for every constant). Kernel side: the linux-sn2 tree (Linux 7.x with SN2 support: `drivers/tty/serial/sn_console.c`, `drivers/char/snsc.c`, `drivers/char/snsc_event.c`, `arch/ia64/include/asm/sn/sn_sal.h`). Grades as above.

### The 0x1007 request

- **Who sends it (established).** `SN_SAL_SYSCTL_EVENT` (`0x02000044`; runtime handler `salruntime_sysctl_event` `rt:0xe290`, SAL_B twin `0xffb1d710`). Its one argument is the nasid; it finds the node's L1 state object through block A `+0x180` and calls `sysctl_event_init` (`rt:0x4cb80`). The kernel makes the call once, from `scdrv_event_init` (`snsc_event.c`), in the `device_initcall` of the system-controller driver `scdrv_init`, and only for the console nasid. It is not `SN_SAL_CONSOLE_INTR`: that call sends no request to the L1 at all (below).
- **What `sysctl_event_init` does, in order (established, objdump of `rt:0x4cb80` to `0x4cdff`).**
  1. `sysctl_subch_open(state, 0xffff000, 19)` (`rt:0x505b0`) claims **slot 19** of the node's slot table (`0x98` bytes per slot, in-use byte at `+0x210`) for its own use, fixed, not allocated. It fails with `-30` (`0xffffffe2`) if slot 19 is already in use. Nothing is sent.
  2. `sysctl_cmd_open(state, 0xffff000)` (`rt:0x4f320`) takes the request slot: `5 + slice` of the calling processor (`cr.lid` bits 26:23), so 5 for the boot processor.
  3. The request is built with `sysctl_cmd_construct_req` (task 6, code `0x1007`, two argument slots, one integer = 19) and sent with `sysctl_cmd_command` (`rt:0x50570`, timeout 3,000,000 ticks).
  4. The reply is read by `sysctl_cmd_interpret_resp` with an **empty** expected-argument list.
  5. On success it returns 19 (the subchannel) and the SAL call returns r8 = 0, r9 = 19 (r9 sign-extended from the 32-bit result: the kernel's `ia64_sn_sysctl_event_init` returns `rv.v0`). On any negative result the PROM closes slot 19 and the request slot and returns that negative number in r9 (r8 is still 0).
- **Request frame (established).** Header byte `0x05` (5 plus slice), then destination word `0x0ffff006`, code `0x1007`, count byte `01`, then one integer argument: tag `00`, value `00 00 00 13`. The argument is **the subchannel number the PROM has just reserved for events, not an event mask**. The model's log (index 5, address `0x0ffff006`, one argument, bytes `0000000013`) is this frame.
- **Reply the PROM accepts (established).** Header `0x20 | slot` (`0x25` for slot 5), status `00 00 00 00`, argument count `00`: payload `25 00 00 00 00 00`. The reader takes the status only: status 0 is success; a negative status is returned unchanged (status `-106` is replaced by the second status at bytes 6 to 9, as for every request). Because the expected list is empty, extra arguments in the reply are not read and not checked. It is the same shape the L1 sends for `0x1005`.
- **If the reply never comes (established).** The wait ends with `-24`; `sysctl_cmd_command_timeout` (`rt:0x50370`) then calls `main_node_die_remote(nasid, 0x8d)` (`rt:0x677f0`), which shows `ERR 8d` on the L1 display (another request, `0x1005`), writes the progress code to the LEDs, and calls `intcon_die_remote` and `cpubus_disable_bus`. The kernel is **inferred** not to come back from that call (the code after `main_node_die_remote` returns normally; the stop seen after the `ttySG0` line is a model run, not a hardware observation). It is the runtime twin of the die path the boot code takes for `0x100b` (see "Silence"). The runtime has no retry for a missing reply. A partial send is retried 50 times at 500-tick intervals, as in SAL_B.
- **If the reply is an error status (established).** No hang: `sysctl_event_init` closes slot 19 and returns the status; the kernel prints `couldn't open event subchannel` and gives up on environment events. Boot continues. A reply with status 0 but extra arguments is the same as a clean reply.
- **What Linux does after success.** `request_irq(SGI_UART_VECTOR = 0xe9, scdrv_event_interrupt, IRQF_SHARED, "system controller events")`. Event messages would be read through `SN_SAL_IROUTER_OP` receive on subchannel 19. Nothing else is sent to the L1. The kernel never asks for events itself again; the L1 sends them unprompted after this request.
- **What the L1 does (sysco `sn2-prom-link-1.62.1.md`, `brick-request-handlers.md`).** ARM 1.62.1: handler `0xcb094` (`L1ReqIRouter` code table): one integer, `SysComSetTasknum`, setting `0x13` written, reply status 0 (established for the calls, as in sysco). ColdFire `O`, 1.62.1 package 3: block inside the general dispatcher `0xffe3f9d4`, entry `0xffe40ef6`; fewer than two words gives `-100`; otherwise the event word `0x30006d78` becomes `port tag << 16 | (slab * 32 + (value & 0x1f))` (so 19 for slab 0 and port tag 0, the port tag being 0 on a one-port node), setting `0x13` is written, reply status 0 and nothing else (established, whole block read). After this the L1 forwards its environment events to the node as class-2 frames with header `0x40 | 19 = 0x53`. The word is -1 after a cold start in both families (ColdFire `0xffe3d374`, ARM `0xc0584`: -1 unless a soft-reset flag is set and the saved subchannel is 4 or more), so no event can reach the node before this request. This settles the open ColdFire initial value in "Real boots" below for 1.62.1 package 3: -1 on a cold start. The test is `0xffe3df3c`; the clear routine is `0xffe3df54` (`-1` and setting `0x13` = 0); the forwarder is `0xffe3db60`.

### The calls the kernel's console makes

The kernel (`sn_console.c`) never touches the junk-bus UART. All of it goes through SAL; the PROM's own UART accesses are the only users of the junk-bus UART, at PIO address `0x8000000ffed40000 | nasid << 38` (`0x7fed40000` is the same register block's offset inside the SHub's MMR window, `sc_shub_dev_reg_offset`; the window supplies bit 35). The runtime console device is `sysctl_rt_dev`, index 1 of the table (see `sn2-runtime.md`), with L1 console index 4 in every call.

| Call | Kernel use | Runtime path | What reaches the L1 or the UART |
|---|---|---|---|
| `PUTB` `0x28` | `snt_hw_puts_raw`: early printk and the polled console; all output until interrupts start | `rt:0x7c00` -> `sc_rt_cons_putb` `rt:0x7fa90`, then flush `0x7f670` | class-2 frame, header `0x44`, up to 127 payload bytes (`l1sc_send`), UART data register writes (`+0x00`, LSR `+0x28` polled), no reply |
| `XMIT_CHARS` `0x2a` | `snt_hw_puts_buffered`, interrupt mode only | `rt:0x80c0` -> `sc_rt_cons_xmit` `rt:0x7fdb0` -> `l1sc_send_async` `rt:0x522e0` | frame built into the send buffer, transmit interrupt enabled (`IER` bit 1); the bytes leave from the interrupt path (below) |
| `POLL` `0x26` | `snt_poll_input_pending` (timer, 60 Hz) | `rt:0x7fe0` -> `sc_rt_cons_poll` `0x7f3b0` -> `sc_cons_poll` `0x7eaa0` | raises the slot 4 poll count, runs `l1sc_receive` (reads the UART), lowers it; r9 = a character is waiting |
| `GETC` `0x22` | `snt_poll_getc` | `rt:0x7990` -> `sc_rt_cons_getc` `0x7f570` | loops poll and readc; blocks until a character arrives |
| `READC` `0x2b` | `snt_intr_getc` | `rt:0x81b0` -> `sc_rt_cons_readc` `0x7f490` -> `sc_cons_readc` `0x7ec10` | pops the slot 4 ring; no UART access unless the ring had been full |
| `INTR` `0x27` | `ia64_sn_console_intr_enable/disable/status` | `rt:0x82c0` -> `console_rt_intr` `0x2bda0` -> `sc_rt_cons_intr` `0x7fe90` | below |
| `PUTC` `0x21`, `PUTS` `0x23` | not used by this driver | `rt:0x78b0`, `0x7aa0` | same buffer and flush as `PUTB` |

`INTR` takes (mask, action) in a1 and a2. Mask 2 is receive, mask 1 is transmit; action 1 on, 0 off, 2 status (established, `0x7fe90`):

- **action 2 (status).** Returns `l1sc_intr_status(state, 4)` (`rt:0x52a00`): the UART interrupt identification register (`+0x10`) is read: bit 1 of its low byte gives transmit-ready (mask 1, and `l1sc_send_intr` then pushes the next send buffer into the UART), bit 2 gives receive-ready, which runs `l1sc_receive` and reports mask 2 only if a complete class-0 frame for index 4 has been committed to the slot 4 ring. A model's UART therefore needs a standard 16550 interrupt identification value (`0x02` transmit-holding-register empty, `0x04` received data) and not only a pending flag.
- **receive on (mask 2, action 1).** Adds one to the slot 4 poll count (state `+0x470`, which is slot 4's `+0x210`) and sets bit 0 of the UART interrupt enable (`+0x08`) (`sc_uart_rxintr` `rt:0x60490`). The permanently raised poll count is what lets `l1sc_receive` take input frames while no poll is running: with the interrupt on, the receiver's "a poll is outstanding" gate (see "Console input") is always open. **receive off** clears the bit and lowers the count.
- **transmit off (mask 1, action 0).** `l1sc_xmit_intr_disable(state, 4)`: clears bit 1 of the enable register when no slot wants it (`sc_uart_txintr` `rt:0x605f0`). Transmit on is not supported through this call (`-1`); the PROM turns it on itself in `l1sc_send_async`.
- A separate path, `SN_SAL_IROUTER_OP` (`0x02000043`, `rt:0xaff0`), carries the system-controller driver's own interrupt control: `INIT` (7) returns 0 and sends nothing, `INTR_ON` mask 2 (5) sets the same UART enable bit, `OPEN` (0) takes a request slot like `sysctl_cmd_open`, and `SEND`/`RECV` (2, 3) move whole class-0/class-1 messages. The kernel's `scdrv_init` calls `INIT` and `INTR_ON` before `SYSCTL_EVENT`, so the UART receive interrupt is on before the `0x1007` request is made. None of these ops sends a request frame except `SEND` on an opened subchannel.

### How input and output travel

- **Output (established).** Console bytes leave as class-2 frames, header `0x44` (index 4), at most 127 bytes per frame, no reply (frame and CRC as in "Frame"; `l1sc_fill_sendbuf` `rt:0x52fe0`). `PUTB` flushes on every call and sends synchronously (it waits on the UART line status). `XMIT_CHARS` fills one send buffer and returns; the UART transmit interrupt (`IER` bit 1, interrupt identification `0x02`) drains it. If the previous buffer is not drained, `XMIT_CHARS` returns 0 characters accepted and the kernel retries after the next interrupt.
- **Input (established, receiver as in "Console input").** The L1 sends a class-0 frame with header `0x04` (the index) per typed character. The PROM takes it in `l1sc_receive` (`rt:0x53b80`) when the slot 4 poll count is non-zero, which `INTR` receive-on keeps true and `POLL` raises for the duration of one call. Characters land in the 128-byte slot 4 ring; `POLL` and `INTR` status report them; `READC` and `GETC` pop them.
- **Interrupt path (established for the writes, inferred for the delivery).** The junk-bus UART interrupt is event bit 20, `uart_int`, of the node's `SH_EVENT_OCCURRED`; the PROM wrote local interrupt 5's destination with vector `0xe9` and its enable `0x2000` before the kernel started (SAL_B sites `0xffb73b86` and `0xffb73bc6`, see `devices/shub/registers.md`). The kernel's `SGI_UART_VECTOR` is `0xe9`. Both the console driver and the system-controller drivers register on it as shared handlers; the console handler reads `INTR` status and then drains receive and transmit as above. The kernel's `irq_ack` (`sn_ack_irq`; this tree has no end-of-interrupt hook) reads `SH_EVENT_OCCURRED` and clears the bits it saw set, masked to the UART, IPI and I/O interrupt bits, through `SH_EVENT_OCCURRED_ALIAS`. The console driver sets `handle_level_irq` on the vector. The UART line is level: the bit must stay set while the UART interrupt identification register reports an interrupt.
- **Polled fallback (established).** Before `request_irq` succeeds, and when it fails ("console proceeding in polled mode"), a 60 Hz kernel timer calls `POLL` and `PUTB`; no interrupt is needed for that.
- **What the L1 must have in place.** Output: the console subchannel is learnt from the node's class-2 frame header (`header & 0x1f`, which is 4 for this console). Input: the L1 console must be in console (pass-through) mode, state 1 of the ColdFire management port (entered from the locked prompt with control-D; sysco `console-behaviour.md`); the ARM L1 sends one frame per character addressed to the subchannel it learnt. No acknowledgement or flow control exists in either direction; a full 128-byte ring only masks the receive interrupt.

### Console transmit and THRE (read 2026-11-17 in the SAL 5.04 runtime, Ghidra `--sn2-prom --sal-runtime`; nothing run)

Why a model's console stalls when THRE is raised the wrong way. All addresses are runtime addresses (`rt:`); the chip-method table is the one at `rt:0xa1bd0` (slot offsets as in "What `sc_rt_cons_putb` needs" in [sn2-runtime.md](../../sal/sn2-runtime.md)): `+0x208` send (`sc_uart_send_chars`), `+0x210` fill (`sc_uart_fill_fifo`), `+0x240` unlock, `+0x248` receive-interrupt mask, `+0x250` transmit-interrupt mask (`sc_uart_txintr`), `+0x258` interrupt status (`sc_uart_intr_status`), each slot read from the relocation table.

**Call numbers (established, Linux `arch/ia64/include/asm/sn/sn_sal.h` lines 40 to 49, `sn_console.c` tree at `69571599c5`).** `PUTC` `0x02000021`, `GETC` `0x02000022`, `POLL` `0x02000026`, **`INTR` `0x02000027`**, `PUTB` `0x02000028`, `XMIT_CHARS` `0x0200002a`, **`READC` `0x0200002b`**. `0x0200002b` is READC, not INTR.

**1. The transmit path (established).**

- **`XMIT_CHARS` never touches the UART data register.** `sc_rt_cons_xmit` (`rt:0x7fdb0`) calls `l1sc_send_async` (`rt:0x522e0`) with header `0x44`. If the send buffer is drained (send position equals send length, words at `+0x68` and `+0x6c` of the console state) it builds one frame with `l1sc_fill_sendbuf` (`rt:0x52fe0`) and returns the payload bytes taken, **at most `0x7f` (127)**: a longer request is clamped at `0x52fe0`, so a kernel handing over 546 bytes gets 127 back and must come back for the rest. If the buffer is not drained it takes nothing, returns 0 and sets the slot's "owes a transmit report" byte (`+0x212` of the slot, `0x98` apart). Either way it ORs the slot into the transmit-want mask (`+0x78`), sets bit 63 of the state register (read-modify-write; plain storage, a software flag), and calls `+0x250` with 1, a read-modify-write of IER that sets bit 1. That IER write is the only hardware effect.
- **The bytes leave from the interrupt path.** `INTR` status (`sc_rt_cons_intr` `rt:0x7fe90`, action 2) runs `l1sc_intr_status` (`rt:0x52a00`), a do-while loop:
  1. read IIR (`+0x258`, `sc_uart_intr_status` `rt:0x60750`): transmit = `(IIR >> 1) & 1`, receive = `IIR & 4`. So `0xc2` is transmit, `0xc4` and `0xcc` receive, `0xc1` none, and `0xc6` (line status) reads as both;
  2. if transmit: `l1sc_send_intr` (`rt:0x527d0`). If the buffer is not drained it calls `+0x210`, `sc_uart_fill_fifo` (`rt:0x5f540`), which **writes up to 16 bytes to the data register with no LSR check** (it assumes the 16-deep FIFO is empty because THRE fired) and stores the number of free slots (16 minus bytes written) in bits 62:58 of the state register (meaning inferred from its use here and in `sc_uart_send_chars`). If the buffer was already drained when the interrupt arrived it sets the slot's report byte and **reports transmit-complete (mask 1)** to the caller. The slot's report byte also yields mask 1 on any later status call while the buffer stays drained (cleared only by the next accepted `XMIT_CHARS`);
  3. receive: `l1sc_receive` drains the UART into the slot ring; mask 2 if a frame for slot 4 is committed;
  4. loop again unless IIR read as none, or as transmit-only after this call already reported mask 1.
  So a frame of about 127 bytes takes about 9 THRE interrupts (16 bytes each), and the kernel is told "transmit ready" only at a THRE interrupt that finds the buffer drained, after the last 16 bytes have left the FIFO.
- **The synchronous path (`PUTB`, `sc_cons_flush` `rt:0x7ef40`, `l1sc_send` `rt:0x53220`)** writes through `sc_uart_send_chars` (`rt:0x5eb40`): it keeps the same free-slot count; when it is 0 it polls LSR bit 6 (TEMT) every 10 ticks, for at most 5,000,000 ticks (then drops the buffer and sets LED code `0x81`), sets the count to 16, writes up to 16 bytes, repeats. It never reads IIR. If the state-register bit 63 flag is set (transmit interrupt armed) it first clears IER bit 1 (`+0x250` with 0), sends, then sets IER bit 1 again. If an asynchronous frame is still half sent, `l1sc_send` first clears IER bit 1, finishes it synchronously, then re-sets bit 1. So **IER goes 3, 1, 3 around every `PUTB` while transmit interrupts are armed**, and the IER write at the end is a 0-to-1 write that re-arms THRE.
- **Where the other IER writes come from.** `INTR` mask 1 off (`sc_rt_cons_intr`, `l1sc_xmit_intr_disable` `rt:0x51a60`) clears the slot from the want mask and, when no slot wants it, clears the state-register bit and IER bit 1 (3 to 1). Linux issues it when its transmit queue is empty at entry to `sn_transmit_chars` (`sn_console.c` lines 540 to 543). `XMIT_CHARS` is the only caller that sets bit 1 again. A 3 to 3 write is an `XMIT_CHARS` made when IER bit 1 was already set.
- **Is there a software transmit buffer?** One: a single frame buffer (`+0x108`, one frame at most, 127 payload bytes before escapes) per console state. Transmit completes asynchronously from the interrupt path, never from a later SAL call. The PROM has no timer for it.
- **L1 framing.** Flag `0x7e`, header `0x44`, payload with `0x7d`/`0x7e` escaped as `0x7d` then xor `0x20`, CRC-16 (low byte first, escaped), closing `0x7e`. No reply, no acknowledgement (see "How input and output travel"). The bytes in the model's UART therefore exceed the payload count by the framing, and a frame of 127 payload bytes is about 132 bytes before escapes.

**2. `INTR` (`0x02000027`) (established).** Arguments: mask (1 transmit, 2 receive), action (0 off, 1 on, 2 status). Status ignores the mask and returns the mask built by the loop above (r9). It reads IIR (`+0x10`) only; LSR is not read on this path. TX-ready is reported only as described in 1. Receive: `l1sc_receive` runs whenever IIR shows receive, or the ring write index moved. Transmit on is `-1`; the PROM does it inside `XMIT_CHARS`.

**3. What the PROM assumes of the UART (established unless noted).**

- Init (`sc_uart_init` `rt:0x5fe40`): divisor latch 1 (`sc_shub_uart_divisor` `rt:0x609d0` returns 1), LCR 3 (8N1), MCR `0x22`, IER 0, **FCR `0xc7`** (FIFOs enabled, both cleared, receive trigger 14), then a scratch read. The FIFO is enabled and 16 bytes deep (the burst size in both writers; Linux `sn_console.c` line 48 `SN_SAL_UART_FIFO_DEPTH 16`).
- Baud and input clock: **unknown.** Divisor 1 means baud = input clock / 16; the PROM never states the clock. The L1 side is probably 750,000 baud, which would make the clock 12 MHz: see "Node console UART: part and link" below. Linux assumes 960 characters per second only to size its 60 Hz fallback timer (`sn_console.c` lines 48 to 49 and 671 to 678), not as a transmit limit. The PROM's own limit is the 5,000,000-tick TEMT wait; its tick rate is the RTC's.
- Linux flow, `sn_console.c` in the held tree (the older circular-buffer form of `sn_transmit_chars` was not read): `snp_start_tx` (line 307) calls `sn_transmit_chars` (lines 517 to 575), which, in interrupt mode, calls `XMIT_CHARS` (`snt_hw_puts_buffered` line 213) in a loop (lines 547 to 567) and stops when it returns less than asked. The handler `sn_sal_interrupt` (lines 583 to 601) calls `INTR` status (line 587) and runs `sn_transmit_chars` again only when mask 1 comes back. In interrupt mode it enables only receive (line 711); transmit is armed by the PROM inside `XMIT_CHARS`. The queue is handed over in the order: first `XMIT_CHARS` from `start_tx`, then one per transmit-ready report.

**4. THRE timing and the rules the model must follow.**

Take the 546-byte case. `start_tx` hands over 127 bytes (IER 1 to 3). The interrupt runs `INTR` status. Everything below is established from the code; the rule that follows from it is graded where noted.

- *Instant THRE (what breaks).* Each data write puts THRE back at once. The loop in step 4 of "the bytes leave" then reads `0xc2` again and again inside one `INTR` status call: all the fills (about 9) happen inside the call, and the last pass reads `0xc2`, finds the buffer drained, reports mask 1 and exits, **with the THRE interrupt consumed by that IIR read**. Linux then calls `XMIT_CHARS` with the next 127 bytes from inside the handler. IER goes 3 to 3, the model has no pending THRE and no transmit event arrives, so the frame sits in the buffer. Later `XMIT_CHARS` calls return 0 (buffer not drained) and only rewrite IER, which is the stall trace seen (IIR `0xc2` once, then IER = 3 rewrites until a key press raises a receive interrupt). The stall is explained by the missing IER re-arm (rule 4): with rule 4, instant THRE does not stall.
- *Per-byte pacing or one character time (what breaks).* THRE returns before 16 bytes have left. Two failures: the PROM's next `fill` writes 16 bytes into a FIFO that still holds some, and the IIR-read loop still races the THRE (the loop's own junk-bus accesses can take longer than one character time). **Rule broken, inferred from the PC16550D datasheet:** in FIFO mode THRE is set only when the transmit FIFO is empty and is cleared by a write of at least one byte to it (National Semiconductor PC16550D, June 1995, page 17: LSR bit 5 and bit 6 text; Table IV on page 17 puts THRE interrupt reset at "reading the IIR (if the source of the interrupt) or writing the transmitter holding register"; IIR bits 7:6 are set when FCR bit 0 is set, page 18). TEMT (LSR bit 6) additionally waits for the shift register.
- *Is the THRE for the last chunk raised after `XMIT_CHARS` has returned?* Yes under the datasheet rule: `XMIT_CHARS` writes no data, so no THRE is expected during it; a THRE comes from the FIFO emptying, 16 characters after the last `fill` (about `16 x 10` bit times at the programmed baud). The `INTR` status call that wrote those last 16 bytes sees IIR `0xc1` on its next pass and returns with mask 0. The report of "drained" comes from the later THRE call.

**The model rule (what to build).** Rules 1, 2, 3 and 5 take PC16550D behaviour and are graded inferred: the SHub UART is not shown to be a PC16550D, and the PROM writes MCR `0x22`, where that part's MCR bits 5 to 7 are always 0 (datasheet page 18).

1. THR write (data register, `+0x00`): clears the pending THRE interrupt and clears LSR bit 5; with FIFOs enabled it adds to a 16-deep transmit FIFO. Bytes past 16 are lost (inferred, PC16550D), so a model that wants to expose a bad PROM sequence should drop them, not queue them.
2. THRE (LSR bit 5, IIR `0x02`) rises only when the transmit FIFO is empty, after the bytes queued have taken `n x (1 start + 8 data + 1 stop)` bit times at the programmed baud. TEMT (LSR bit 6) rises one more character later, when the shift register is empty. Grade: inferred (PC16550D datasheet) for the rule, **unknown** for the input clock and so the real time.
3. IIR read: if the value returned is `0xc2` (THRE the highest-priority source) the pending THRE flag is cleared; other reads change nothing (inferred, PC16550D Table IV). IIR must be returned with bits 7:6 set (FIFO mode).
4. **Re-arm on an IER write (software expectation, inferred; the datasheet is silent on a same-value write).** The PROM's flow needs an IER write with bit 1 set to raise the THRE interrupt whenever THRE is currently set, including a write that leaves bit 1 at 1 (the 3 to 3 case). The PROM consumes the final THRE in its own IIR read and Linux hands over the next frame in the same handler, with no data write to restart anything; a 0-to-1-only rule would stall on real timing too. The real SHub UART's behaviour for this write has not been observed. If an observation shows the real part does not re-arm, the contradicting side is this PROM-and-Linux flow, and the question is open. Rule 4 is the smallest rule the code needs.
5. The interrupt line (event bit 20) is a level of "enabled cause pending": IER bit 1 with THRE pending, or IER bit 0 with receive data. Receive priority over THRE in IIR (`0xc4` before `0xc2`) as the datasheet's Table IV says (inferred, as for rules 1 to 3).
6. Do not add a fixed delay to the first THRE after an IER write: with the FIFO empty, THRE is already set and the interrupt is immediate (that is how `XMIT_CHARS` starts every frame).

Not read: the kernel's older circular-buffer `sn_transmit_chars` (2.6 and 3.2); the SHub 2 image; whether the model's other IER 3, 1, 3 sequences come from `PUTB` (printk) or from Linux's off call (the PROM produces both).

### Node console UART: part and link (read 2026-11-17, nothing run; not yet independently reviewed)

What the SHub 1 console UART is, what is at the other end and what its datasheets say about THRE. Grades: established, software expectation, inferred, unknown.

**Answer first: THRE on an IER write.** For an enable that goes 0 to 1 while THRE is set (transmit FIFO empty), the 16550-family datasheets read here all say the part raises the THRE interrupt, and the public Linux 8250 core relies on it. For the SHub's own part this is **inferred**, because the part is unidentified. For a write that leaves IER bit 1 at 1 (the 3 to 3 case), **unknown**: no datasheet read addresses it and the Linux probe tests only 0 to 1. Rule 4 above keeps its grade. Evidence:

- PC16550D (June 1995, p. 17, LSR bit 5): THRE "causes the UART to issue an interrupt to the CPU when the Transmit Holding Register Empty Interrupt enable is set high". Table IV on the same page: the THRE interrupt is reset by reading IIR (if it is the source) or writing the transmitter holding register.
- TL16C550C (SLLS177I, March 2021, LSR bit 5, section 7.7.8): "If the THRE interrupt is enabled when THRE is set, an interrupt is generated." Table 7-5 and section 7.7.3 item 1: reset by an IIR read (if source) or a THR write. Section 7.7.3 item 2 adds that with fewer than two bytes in the FIFO since it last emptied the interrupt is delayed one character time minus the last stop bit, and that the first interrupt after changing FCR bit 0 is immediate.
- ST16C550 (Exar, Rev. 4.30, LSR bit-5): same sentence as the PC16550D ("this bit causes the UART to issue an interrupt to CPU when the THR interrupt enable is set"). Only the LSR bit 5 and MCR text were checked in this copy.
- Linux `serial8250_THRE_test` (`drivers/tty/serial/8250/8250_port.c`): "Real 16550s should always reassert this interrupt whenever the transmitter is idle and the interrupt is enabled." It writes IER 0, then `UART_IER_THRI`, and reads IIR; a part that does not reassert gets `UART_BUG_THRE` and a backup timer. It never writes THRI over THRI. Software expectation for 0 to 1 only.
- None of the above says a THRE interrupt already cleared by an IIR read comes back on a same-value IER write. A reading of the datasheets as "THRE and ETBEI" being a level fits the text of the LSR bullet but contradicts the IIR-read reset in Table IV and Table 7-5, so a model cannot take the level reading from them.
- The functional argument for 3 to 3 (the PROM and Linux flow in rule 4 stalls without it) is software-expectation grade. The 60 Hz fallback timer cannot hide a missed THRE: `sn_sal_timer_poll` transmits and re-arms only while `sc_port.irq` is 0 (`sn_console.c` lines 612 to 629), and `sn_sal_switch_to_interrupts` sets it once the IRQ is granted (lines 697 to 719), so in interrupt mode only the UART interrupt moves transmit.

**1. What the part is and where it sits.**

- *On the SHub junk bus, not in the processor interface (established).* The public Linux 2.4 header `include/asm-ia64/sn/sn2/shub.h` (Library root `linux-mips`, revision `8ef7d46c94d5`) says the junk bus "is used to access the PROM, LED's, and UART", through the local block's MMR space, with a 16-bit data path. It defines `SH_JUNK_BUS_UART0` to `UART7` as `0x7fed40000 + 8 * n`: eight registers at a stride of 8, the PROM's UART base. The LEDs are `0x7fed00000` to `0x7fed30000`.
- *A chip-enable of its own (established as a register layout; inferred as a separate chip).* `SH_JUNK_BUS_TIME` (`0x1_1002_0000`, the 2.4 `shub_mmr.h`; reset value `0x4040_4040`) has four byte fields: `FPROM_SETUP_HOLD` 7:0, `FPROM_ENABLE` 15:8, `UART_SETUP_HOLD` 23:16, `UART_ENABLE` 31:24. A UART with its own setup/hold and enable widths next to the flash's looks like a peripheral behind a chip select, not logic inside the SHub. The unit is not stated (junk-bus clocks, inferred).
- *The PROM sets that timing (established access, my decode of the fields).* The write `0x15031010` to `0x81_1002_0000` (see [prom-reset.md](../../../devices/shub/prom-reset.md), step A1) decodes as `FPROM_SETUP_HOLD` 0x10, `FPROM_ENABLE` 0x10, `UART_SETUP_HOLD` 3, `UART_ENABLE` 0x15. That settles the "role unknown" notes on this register in the SHub pages: it is the junk-bus timing register. Both strobes are shortened from the reset default (0x40): the UART's enable to 0x15 and its setup/hold to 3, the flash's both to 0x10.
- *No part name anywhere (established absence in the PROM).* Strings in the SAL 5.04 image name only the register fields above, `SH_JUNK_*`, the shell line "Use JunkBus UART: junk", the KLCONFIG component name `HubUart` (`init_klcfg_hubuart`) and the error texts "UART parity/overrun/framing error". No `16550`, `16C`, `TL16`, `ST16`, `XR16`, `NS16` or `SC16` string. The PROM never reads a chip ID or EFR: `sc_uart_init` reads only LCR, LSR and the scratch register, and `direct_probe` writes `0x55` then `0xaa` to scratch.
- *Which parts fit (inferred).* Everything the PROM does is plain 16550 programming: DLAB, divisor, LCR 3, IER, FCR `0xc7`, 16-byte bursts. Parts that fit that and the writes to MCR:
  - National PC16550D / NS16550AF, Exar ST16C550, NXP SC16C550B: MCR bits 7:5 read 0 and ignore writes, so MCR `0x22` is harmless but bit 5 means nothing.
  - TI TL16C550C and TL16C550D: MCR bit 5 is AFE (auto-RTS and auto-CTS), so `0x22` is AFE plus RTS. 16-byte FIFOs; the C is rated 16 MHz, the D up to 24 MHz at 5 V (48 MHz in one 3.3 V package).
  - TI TL16C750: AFE; 16-byte FIFO unless FCR bit 5 is set (it is 0 in `0xc7`).
  - Exar XR16C850: bit 5 is Xon-Any; 128-byte FIFOs, and its THR-empty interrupt follows a programmed transmit trigger level, so the PROM's "16 slots free" assumption would not be guaranteed. Cannot be excluded, less likely.
  - A 64-byte-FIFO part in 16-byte mode behaves like the 16-byte parts for this writer.
  The PROM writing a bit that does nothing on a PC16550D is not evidence against it; the bit being a useful AFE is only a weak hint for the TL16C550C/D, because the PROM never reads MCR in the init path read here and sends nothing that depends on CTS.
- *What would discriminate.* Read MCR back after writing `0x22` (`0x22` on the AFE parts, `0x02` on PC16550D/ST16C550/SC16C550B); write LCR `0xbf` and probe the enhanced registers (XR and 750-class parts only); write FCR bit 5 and see whether IIR bit 5 or the FIFO depth changes (64-byte part); fill the FIFO past 16 bytes with the transmitter held and count (16 or more); read the board's chip marking. Timing is not a discriminator without the junk-bus clock. A hardware read needs the repository owner's approval first.

**2. The other end: the L1.**

- *The node link is the L1's "jb" (junk bus) port (inferred).* The ARM Linux L1 (`l1`, 1.62.1 package 4, SHA-256 `22cb6287...bfc5`) runs on a Samsung S3C2410 (kernel strings `s3c2410-uart`, `sgi2410l1-l1io`) with an FPGA UART block, the "L1IO FPGA" (kernel string "L1IO FPGA: ID ... [ %d UARTs, %d JTAG ports, %d SERIRQs ]"). Its UARTs are FPGA logic exposed as `/dev/l1io_ni0..31`, `l1io_ii0..3` and `l1io_jb0..5`; the L1 end is not a 16550 part. The command alias list `syscom|junkbus|jb|bedrock` and the strings "junkbus uart reset", "set length of JunkBus PPP read delay" and "enable/disable data dump on junkbus PPP errors" tie the "jb" port to the node's junk-bus UART and the PPP framing already read in `sn2-prom-link-1.62.1.md` in the sysco repository (`software/firmware/l1/`). `LBIReadJunkbusStatus` and `SHUB2_HandleJunkbusStatusInterrupt` read SHub junk-bus status. Established strings; inferred that this port is the one that reaches the SHub 1 console UART.
- *Rate: 750,000 baud (established as the constant; inferred as this link's).* The L1's per-family set-up functions call its UART init with port `0x29` (`l1io_jb0`), kind 3, speed `0xb71b0` = 750,000 (the Dorado, Gemini, Opus TIO, Vortix and Autofan set-ups among them; the same constant ends a small one-port function at `0x33060`). Node-link ports 5 and 6 (`l1io_ni0` and `ni1`) are opened at `0x2dc6c0` = 3,000,000 in the same functions; those are the TIO and router links (the sysco page notes the scan-chain path for them). Which family function serves an IP57 (Altix 350) was not traced: the `IP57_*` routines contain no UART open of their own and the table that maps the brick type to its set-up was not decoded. So the L1 side of the Altix 350's console link is **inferred** to be 750,000 baud.
- *Serial format on the L1 side: unknown.* The L1 stores a 28-byte configuration block per port (`uartSetConfig`) whose meaning is not read; nothing here shows the L1's data bits, parity or stop bits. The PROM side is 8N1 (LCR 3, established).
- *Derived SHub-side input clock (inferred).* Divisor 1 and 16x oversampling give baud = clock / 16, so if both ends run 750,000 baud the SHub UART's clock is 12.000 MHz (750,000 x 16). That is within the rating of the TL16C550C (16 MHz), the PC16550D, the ST16C550 (24 MHz at 5 V) and the XR16C850 (24 MHz). A 12 MHz figure is also the clock the ColdFire L1's quad UART code assumes (`quad-uart-and-serial-links.md` in the sysco repository), which only shows 12 MHz is a common board clock. The ColdFire 'O' packages (the same container) were not read for their SHub-side port; whether an Altix 350 module carries the ARM or the ColdFire L1 is unknown in sysco.
- *Consequence for a model.* One character is 10 bit times: 13.33 microseconds at 750,000 baud, so 16 bytes drain in 213 microseconds. Grade: inferred.

**3. FIFO.**

- Enabled (established): FCR `0xc7` is bit 0 (enable), bit 1 (clear receive FIFO), bit 2 (clear transmit FIFO), bits 7:6 = 3 (receive trigger 14 on the 16-byte parts: PC16550D table on page 17, TL16C550C Table 7-4). DMA mode (bit 3) is 0.
- Depth 16 (software expectation): both PROM writers send 16-byte bursts, and Linux `sn_console.c` sets `SN_SAL_UART_FIFO_DEPTH` to 16. That matches the PC16550D, ST16C550, TL16C550C/D, SC16C550B and the TL16C750 in 16-byte mode; it does not match a 32-, 64- (FCR bit 5 set) or 128-byte mode of the parts above. The part's own depth is **unknown**, since it is unidentified.

**4. THRE and IER, part by part.** See the answer at the top. Part-specific points that differ:

| Part | THRE interrupt on enable with THR empty | Reset of that interrupt | Other |
|---|---|---|---|
| PC16550D | stated (LSR bit 5, p. 17) | IIR read if source, or THR write (Table IV) | silent on a same-value IER write |
| TL16C550C/D | stated (section 7.7.8) | the same (Table 7-5) | delay of one character time (section 7.7.3), immediate after an FCR bit 0 change |
| ST16C550 | stated (LSR bit-5) | not checked in this copy | MCR 7:5 not used |
| TL16C750 | not read in detail | not read | 64-byte mode needs FCR bit 5 |
| XR16C850 | interrupt follows a transmit trigger level (sections on transmitter operation); not read for the empty-FIFO enable | not read | 128-byte FIFO |

The behaviour every candidate shares: THRE is set when the FIFO is empty, cleared by a data write, and the interrupt is enabled by IER bit 1. A model that raises on any IER write with bit 1 set and THRE set is a superset of what all of them state; whether the real part raises on 1 to 1 is not shown.

**Sources read this session.** Library roots `linux-mips` (2.4 `shub.h`, `shub_mmr.h`, `sn_serial.c`), `linux` (`8250_port.c`, `8250_core.c`), `origami-docs` (PC16550D copy, page 17); no TL16C550, ST16C550 or XR16C850 hit in `origami-docs` or `techpubs` (searched by part name), so those three datasheets were fetched from the vendors' public sites (TI `tl16c550c.pdf`, `tl16c550d.pdf`, `tl16c750.pdf`; the Exar ST16C550 Rev 4.30 PDF; MaxLinear `16c850-231-080905.pdf`). The PROM was read as strings and register constants only; the L1 `l1` program by a call-site scan of its UART init and string search; the L1 kernel by strings. No IRIX source and no restricted Library result was opened.

The vendor datasheets are now held in the Library cache:

- TI TL16C550C, single UART with 16-byte FIFOs (SLLS177): `io-chip/ti-tl16c550c-datasheet.pdf`
- TI TL16C750, single UART with 64-byte FIFOs and auto flow control: `io-chip/ti-tl16c750-datasheet.pdf`
- Exar/MaxLinear ST16C550, 16-byte FIFO UART, Rev 5.01 (supersedes the Rev 4.30 copy read above): `io-chip/exar-st16c550-datasheet.pdf`
- Exar/MaxLinear XR16C850, 128-byte FIFO UART, Rev 2.3.1: `io-chip/exar-xr16c850-datasheet.pdf`

### Is there an input limit near 80 characters? (read 2026-11-16, nothing run)

A model run showed an 83-character command producing no output. Read in the SAL 5.04 runtime in Ghidra (`l1sc_receive` `rt:0x53b80`, `sc_cons_readc` `rt:0x7ec10`, `sc_cons_poll`
`rt:0x7eaa0`, `l1sc_intr_status` `rt:0x52a00`) and in the linux-sn2 `drivers/tty/serial/sn_console.c`. Grades as above.

- **The PROM ring holds 127 characters, not 80 (established).** The ring of index 4 is 128 bytes at `ctx + 4 * 0x98 + 0x21c`; a byte is taken only while the read index differs from the
  tentative write index plus one (mask `0x7f`), so at most 127 committed characters wait there. A full ring sets the index's bit in `ctx+0x40`, calls the chip hook at `+0x248` and returns -21;
  `READC` clears the bit and calls the hook again when it takes a character. A bad CRC returns -22 and drops that frame, a frame with no room for its two CRC bytes -23, a closed
  poll gate -24. A frame is committed (its characters become readable) only on a good CRC.
- **One poll consumes everything in the UART (established).** `l1sc_receive` is a byte state machine that reads the UART until no byte is available; after each good frame it goes back to
  waiting for a header and keeps going, so one `POLL`, one `INTR` status call or one `READC` that had been blocked takes every complete frame the UART holds, up to the ring's room. It is
  not one character per call.
- **The kernel has no limit near 80 (established).** `sn_receive_chars` loops `INTR` status then `READC` until the status shows no receive-ready, or until `tty_insert_flip_char` fails
  (characters then stay in the PROM ring). Interrupt mode drains on every receive interrupt, polled mode on every 60 Hz tick. No kernel buffer is smaller than the ring.
- **Wire size (established arithmetic).** One frame per character is six bytes (`7e`, header, character, two CRC bytes, `7e`), more when a byte is escaped. 83 characters are about 500
  bytes on the UART, close to a 512-byte buffer; 127 characters would be about 760 bytes. So a limit near 80 characters is not the PROM ring (about 127 characters) or the kernel. If the
  limit is on input at all, it sits in the model's path from its L1 to the UART (a buffer or queue of about 512 bytes that drops, or a receive FIFO without flow control). This is
  inferred from the arithmetic and the absence of any other limit: the model was not read.
- **The likelier second cause is output, not input (inferred).** The kernel sends output through `XMIT_CHARS`, which takes at most 127 bytes per call and relies on a second
  transmit-ready interrupt to continue (see [SN_SAL_HWPERF_OP and sn_topology](../../sal/runtime-services.md#7-sn_sal_hwperf_op-and-sn_topology)). A command whose echo plus output, or whose
  output alone, is longer than 127 bytes in one write stops in the same place. An 83-character command that echoes its text can cross that line. Two checks tell them apart, neither run:
  send 120 characters in one console write to a command that prints nothing and check the next prompt appears (input path), then run a short command that prints 200 bytes (output path).

### What a model must do

1. Answer `0x1007` with `25 00 00 00 00 00` (header `0x20 | n` for the request's index n) and record 19 as the event subchannel (event word 0x13; setting `0x13`). Send no events unless one is wanted: if one is sent, its header is `0x53` and it must be a complete event frame.
2. Keep answering the earlier requests as listed above. No other request is made for the console, `0x100a` clears the event word, `0x100b` clears it when the slab matches.
3. Model the junk-bus UART as a 16550 with 8-byte register stride at `0x8000000ffed40000 | nasid << 38` (offset `0x7fed40000` in the MMR window): receive/transmit data at `+0x00`, interrupt enable at `+0x08` (bit 0 receive, bit 1 transmit), interrupt identification at `+0x10` (`0x02`, `0x04`, `0x01` when nothing is pending, as on a 16550), line status at `+0x28` (bit 0 data ready; bit 6 transmitter empty, which `sc_uart_send_chars` polls, sleeping 10 ticks between reads, for up to 5,000,000 ticks before each burst of 16 data writes; on timeout it drops the buffer). `sc_uart_intr_status` turns the identification byte into bit 0 = `(IIR >> 1) & 1` (transmit) and bit 1 = `IIR & 4` (receive), so a value of `0x06` reports both, and `l1sc_intr_status` repeats until neither is set: reading the identification register must clear a transmit-holding-register-empty interrupt, and the receive interrupt must drop once the data register is drained, or `INTR` status never returns. Drive event bit 20 of `SH_EVENT_OCCURRED` from it as a level.
4. Strip frames (flag, header, CRC) from node output; header `0x44` is the console. Wrap typed bytes as class-0 frames with the console index (`0x04`) for input, one per character.

Grades: sender, grammar, ordering, die-on-silence, slot 19, call table, interrupt-enable semantics: established (runtime read; kernel source). ARM handler layout and the stored event word format: ARM inferred, ColdFire 1.62.1 package 3 established. Delivery of `SH_EVENT_OCCURRED` bit 20 to vector `0xe9` through local interrupt 5: inferred (the PROM writes are established, the hardware path is not read from a manual; the PROM writes enable `0x2000`, bit 13, and how that enable bit relates to event bit 20 is unknown, see [interrupts.md](../../../devices/shub/interrupts.md)). Whether the 3,000,000-tick wait is 3 s: inferred (see "Silence").

## Order and replies at a glance

| Order | Code | Arguments | Reply the PROM needs | Grade |
|---|---|---|---|---|
| 0 | none (link start) | UART at `0x8000000ffed40000`, divisor 1, 8N1, FIFO `0xc7`, MCR `0x22`; state register `0x81_101d_0100` bits 41:39 = 7 | no handshake | established |
| 1 | `0x100b` | ints 1, 5, 4 | status 0, 0 args accepted; the L1 sends none, the PROM times out (3,000,000 ticks), runs the `0x8d` die routine, which parks the boot processor (SAL 4.55 to 5.04; SAL 4.43 and earlier return `-24` without the die call; 4.04 not examined) | established for the code; what ends the wait on hardware: unknown |
| 2 | `0x1005` | string "Prom starting..." | status 0, 0 args (errors ignored) | established |
| 3 | `0x0003` | none | status 0, 2 ints (module word, type letter) | established |
| 4 | `0x000e` | none | status 0, 1 int (slab; 0 turns type `f` into `c`) | established |
| 5 | `0x0013` | none | status 0, 2 ints (slot, type letter) | established |
| 6 | `0x0009` | none | status 0, 1 int | established |
| 7 | `0x0001` | none | status 0, 1 int (debug word; blank 0) | established |
| 8 | `0x0010` | none | status 0, int nodes (at most 4), int CPUs (at most 16), per node presence and enable | established, values inferred |
| 9 | `0x0006` x16 | device id (8,16,9,17,10,18,11,19,12,20,13,21,14,22,15,23), 4, 0, 48 | present: status 0, int, raw (count 2); absent: any negative status | established |
| 10 | `0x1005` | string "Init memory..." | status 0, 0 args | established |
| 11 | `0x0015` | none | status 0, 1 int | established |
| 12 | `0x1005` | string "Init Intercon..." | status 0, 0 args | established |
| 13 | `0x0006` then `0x0010` | 1, 2, offset 0/64/..., 64; then none | board area in 64-byte chunks until bytes-left is 0; then as 8 | established |
| 14 | `0x1005` | string "Init I/O..." | status 0, 0 args | established |
| 15 | `0x0006`, once per `bridge_discover` (each PIC widget; see review) | 98 (type `o`) or 1, 2, 0, 64, then 64, 128, ... | as 13; any negative status is tolerated, silence parks | established |
| 16 | `0x0012`, `0x0010`, `0x0008` | none | 1 int; as 8; 1 string (error tolerated) | established, gating inferred |
| 16b | `0x1005` | string "Running" | status 0, 0 args | established |
| 17 | console | class-2 frames, no request | none | established |

## Where this page corrects or extends the reviewed table

- The `0x100b` arguments are `1, 5, 4` (the two version bytes were "not read").
- The order is no longer inferred: `0x000e` comes before `0x0013`, because of the type switch in `0xffa7d510` for type `f`.
- `0x0003` is sent with destination word `0x0ffff006`, as are the others on this path; the `0x5000_1006` value in the earlier run was
  not reproduced by the code read.
- The DIMM requests follow progress `0x14`, not `0x16`; the device-id order is bank-major.
- The reviewed table lists 10 rows for 23 sites; the rest are: two task-3 text-command routines (`0xffa0d3d0`, `0xffa0d760`),
  `0x0008`, `0x000a`, `0x0012`, `0x1007`, `0x100a`, `0x200e`, `0x200d`, `0x200f`, the display-by-geoid and PCI-operation routines of the
  SAL runtime (`0xffb5ead0`, `0xffb5ed50`) and the `0x100b` twin. Of these only `0x0008` and `0x0012` are on the boot path;
  the others are not reached from `main`, `main_two` or `main_three` by direct calls, and their callers are SAL procedure
  descriptors the kernel calls (established for the call graph, as far as direct calls and descriptor tables go).
- The no-reply claim for `0x100b` in the L1 link page and the PROM's wait are both right: the L1 sends nothing and the PROM waits
  out the timeout (sysco `12e3608`), and then parks (sysco `331df54`). What really ends the wait on a brick is the open point.

## Unknown

- Whether the node object's identity cache survives the jump to RAM (decides whether `0x0003`, `0x000e`, `0x0013`, `0x0009` repeat).
- The value of the partition-master flag and whether I/O discovery sends EEPROM reads on a model with no I/O widget.
- What ends the PROM's wait for `0x100b` on a real brick, given a silent L1 and a die routine that parks: no L1 frame source that could do it exists in the ARM L1 1.62.1 or the 1.44.0 handler (resolution below).
- `0x0010` values on a blank L1.
- Indirect calls through the node operations tables between `0xffaf8c50` and the EFI jump were not all resolved.

## Review

Independent review of chips commit `77d39fb` (this page), examined at `77d39fb`. The reviewer did not write it. Method: the retools IA-64 Ghidra export of `shub1snprom.bin` (SAL 5.04, sha256 matches the page) for the decompiled C of the request routines, `main`, `main_early_disable`, the frame builder, the send and wait routines and the receiver; `ia64-linux-gnu-objdump` over the whole SAL_B range as the cross-check for every constant, call target, call site and branch; the version bytes and the CRC table read from the image. The L1 side was read in the sysco pages only (section "The 0x100b reply" in `sn2-prom-link-1.62.1.md`, sysco `12e3608`); the L1 program was not re-read.

**Confirmed (re-read in the binary).**

- Census: exactly 23 `br.call` sites reach the frame builder `0xffa81f40`. Request codes read at 21 of them match the page's list (task-3 commands at `0xffa0d52c` and `0xffa0d80c`; `0x0003`, `0x0013`, `0x000e`, `0x0001`, `0x0009`, `0x0008`, `0x1005`, `0x000a`, `0x0012`, `0x1007`, `0x100a`, `0x200e`, `0x200f`, `0x0015`, `0x0006`, `0x100b` twice, `0x0010`, and `0x1005` in `0xffb5ead0`). The code constants at `0xffa7f59c` (`0x200d`) and `0xffb5ee7c` were not read. The twin `0xffa91060` and `0xffb5ed50` have no direct callers; `0xffa7e1d0`, `0xffa7ed60`, `0xffa7efe0`, `0xffa7f190`, `0xffa7f430`, `0xffa7f6b0` and `0xffb5ead0` have one direct caller each, none in `main`, `main_two` or `main_three`.
- Order in `main` before the jump: `0x100b` (inside `sysctl_init`, progress `0xd`), `0x1005` "Prom starting..." (master), then `0xffaac4b0(2, nasid)`, which calls `0xffa80210` (`0x0003`, then the type switch in `0xffa7d510`: `0x000e` for types `f`, `l`, `b`, `{`; slab 0 or -1 turns the type into `c`), then `0xffa80270` (`0x0013`), then `0xffa802f0` (slab, cached). Then `0x0009`, progress `0xe`, `0x0001` (master stores the low 16 bits in the scratch register and sets flag 11), progress `0x10`, `0x0010` through `main_early_disable` (only if debug bit 8 is clear), the DIMM probe (`0xffa78100` calls `0xffa77bb0`) after progress `0x14` and before progress `0x15`, "Init memory..." at progress `0x16`, then `0x0015` (master, after the "DEX POD" test). The PROM then goes to RAM through `0xffac6bb0` at progress `0x19`. `0x000e` before `0x0013` and the slab-0 type change are confirmed.
- Link start: `sc_uart_init` writes, in this order, line control with bit 7 set, divisor high byte 0, divisor low byte 1 (method `0xffa94340` returns 1), line control with bit 7 cleared, line control 3, modem control `0x22`, interrupt enable 0, FIFO control `0xc7`, then reads scratch; registers at `0x8000000ffed40000` with stride 8 and the nasid shifted by 38; the first step polls line status bit 6 for up to 100000 ticks. The test is bits 41:39 equal to 7 on the state register (`0xffa94300` returns `0x1_101d_0100`), and `0xffa8b5d0` then clears them, bumps bits 49:42 and clears bit 63.
- `0x0010`: limits (nodes at most 4, CPUs at most 16, else `-100`), reply order status, node count, CPU count, then presence and enable per node, and the arrays indexed by slab.
- DIMM reads: device id for bank b and position p is `8 + ((p & 1) * 4 + b) * 2 + (p >> 1)`, bank-major (`0xffa7bd60` passes p>>1, p&1 and b to `0xffa85470`); selector 4, offset 0, length 48 fixed in `0xffa84680`; expected reply int then raw (size 5 in the parser); a negative status gives return 1, `-107` gives 3, and nothing aborts the loop. Board area read: chunks of 64 bytes until the bytes-left integer is 0.
- The `-24` and send-retry arithmetic (50 tries, 500 ticks, `-26`), the `0x2dc6c0` timeout constant in `0xffa82c10`, the status `-106` second-status rule, and `-32`/`-33` on tag and count mismatch in `0xffa82270`.
- Frame builder: destination word is the open target `0x0ffff000` ORed with task 6, the open handle is `5 + slice`, and the CRC table at `0xffbe1190` is the standard reflected `0x8408` table (all 256 entries compared).
- After the jump: "Init Intercon..." (master) comes first at `0xffa1b41c`, then `0xffa1a980` (not traced), then `0xffa9fe80` (board area read, then `0x0010`), as listed; the `0x0012`, `0x0010` per node and `0x0008` group runs from `main_three` only when the master test and flag 1 pass (`0xffad761c`, `0xffad765c`, `0xffaa03f0`). `0x0008` goes through `0xffaa9d60`, which then repeats `0x0009` (cached unless it failed).

**Mechanical fixes made in this review.**

1. The `0x100b` text said a missed reply makes the PROM die and that a model "must reply to all of them". The L1 (1.62.1) sends no reply for the three-argument form (sysco `12e3608`), and the PROM's caller ignores the result, so the page no longer says a model must reply; the conflict over what the die routine does afterwards is recorded under "Silence" below and in the request 1 text. The "no-reply claim contradicts the wait" note and the unknown about a deployed L1 were rewritten.
2. The die routine was described as returning to its caller after the reset write. It does not return for the local node and the calling processor's own slice (see "Silence"); text corrected.
3. The wire framing text omitted that the CRC covers the header byte and that the CRC bytes are escaped; added. The receiver also accepts header bytes 0 to 4 with class bits clear; added.
4. `0x0010`: the reply layout was given without offsets and the consequence of a clear bit ("stops considering its own slice") was vague; added the byte offsets, that tags and the count byte are not checked, that every processor sends the request, and that a failure parks that processor through progress `0x87`.
5. `0x0015`: the routine is entered through the stub `0xffa46530` (the call target), whose body starts at `0xffa46540`.
6. `0x0003`: added the type `o` path (up to eleven board-area reads from `0xffa7d1f0`) the page did not list.

**Silence: which requests tolerate a missing reply.** Every request goes through `0xffa82c10`/`0xffa82a10`. A missing reply ends in `0xffa82730` returning `-24` after the timeout, and the die routine `0xffad2cb0` runs before any caller sees the `-24`. The routine writes `ERR 8d` text to the display (only while the display flag is set), clears the display flag, writes four progress indicator updates, then calls `0xffa9fc70(nasid, 0, 0)`. That writes `0x1_0001_0000_0000` to `0x1_2000_0000` and clears bits 29:26 of the scratch word at `0x1_5003_1550`. When the node is the local node and the parameters are zero it then calls `0xffa9fba0(nasid, own slice)`, which for the calling processor calls `0xffaeb7c0`. That routine sets a flag, switches state with `rfi` to `0xffaeb8b0`, calls PAL index 3 (cache init) and loops forever on PAL index 29 (halt light) at `0xffaeb8d0`. Nothing in the die path returns on that route. The simulator signature path returns `-24` earlier and never reaches it.

- On this reading no request tolerates silence on real hardware: a missing reply to any of them parks the boot processor, whatever the caller does with the status. This is the 5.04 reading (builds 4.55 to 5.04 share it, next section). It includes `0x100b`, whose caller at `0xffa1f62c` ignores the result; the die routine has already run. Sysco `12e3608` read `0xffad2cb0` as returning ("no halt was found"), because it did not follow the tail through `0xffa9fc70`; sysco `331df54` corrects that and a second reading confirms the park (see the resolution below). The L1 side (no reply from 1.62.1) and the PROM side (the die routine parks the processor) both hold, so a PROM 5.04 image on a silent L1 parks at its first request, and what happens on real bricks is not explained by the code read. Nobody has run the pair. For an implementer: answer `0x100b` with status 0 and no arguments as an approximation, and treat the real wait-ending mechanism as unknown.
- Error replies (a negative status or a wrong argument count, not silence) are tolerated as follows. Ignored by the caller: `0x1005` and `0x100b`. Fallback value: `0x0003` (unknown type), `0x000e` (type becomes `c`), `0x0013` (`-101` falls back to `0x0003`; other errors give `0xff`), `0x0009` (becomes 0 with a printed warning), `0x0001` (console prompt about the switches), `0x0012` (value forced to `0x800`), `0x0008` (default text), `0x0015` (not otherwise tested), `0x0006` for DIMMs (slot absent) and for the board area (a message, then the boot goes on). Not tolerated: `0x0010`, whose presence-and-enable bit for the processor's own slice must be set or that processor is parked at progress `0x87`; and "No memory on node" (progress `0x80`) if every DIMM slot errors.

**Resolution of the sysco conflict.** Settled by a second reading in Ghidra of both programs (the IA-64 export of `shub1snprom.bin` and the ARM `l1` of L1 1.62.1), with `ia64-linux-gnu-objdump` as the cross-check for every branch. The sysco page was the one in error and now says so (sysco `331df54`).

- **The park is real (established).** `0xffad2cb0` calls `0xffa9fc70(nasid, 0, 0)` at `0xffad2dbc` before its own `br.ret`. With the third argument 0 the callee compares the local node number (`0xffa0dcf0`, bits 42:32 of a local register) with its first argument (`0xffa9fe0c`), tests the second argument for 0, and calls `0xffa9fba0` (`0xffa9fe60`), which repeats the node test and tests the slice in `cr.lid` against the one passed. For the boot processor all of these hold, so `0xffa9fba0` calls `0xffaeb7c0` (`0xffa9fc5c`): the `rfi` to `0xffaeb8b0`, PAL index 3, then PAL index 29 in a loop at `0xffaeb8d0` (the loop branch at `0xffaeb8ec` returns to the call). Sysco's "no halt was found" read stopped at the routine's own return. The only bypass is the simulator signature, which also suppresses the send.
- **The L1 is silent (established, re-read).** `syscom_process_inbound_request` (`0xc2284`) adds the code as argument 0, so the node's frame (count byte 3) arrives with the count 4 that `0xcb474` requires. The destination `0x0ffff006` is the local wildcard with task 6, registered as a direct function by `L1ReqInit`. The handler never calls `ARG__START`, and the router tail replies only when the reply-count word is set. `PPPRead` only de-frames; no layer acknowledges. The ColdFire handlers read in sysco also send nothing, so no L1 package read answers `0x100b`.
- **Candidates closed.** A reply by another path in the ARM L1 (generic acknowledgement, PPP layer, another task or subchannel): none found. A different argument count: not sent, the builder is called with three integers. Wait skipped on a real boot: only by the simulator signature. The receiver (`0xffa87830`) completes a slot on any frame whose CRC residue is `0xf0b8` (`0xffa89de0`) and whose header byte is the slot's; it does not read the code or body.
- **The L1's frame sources, enumerated (established for ARM L1 1.62.1; sysco `sn2-prom-link-1.62.1.md`, section "What could end the wait").** Only four routines write to the node link: the request, event, response and chunked-response writers. Responses (`0x20 | subchannel`) need a request that carries a reply, and the `0x100b` handler sends none. Events (`0x40 | subchannel`) need the event word, which is -1 after every L1 start and after a node power-down, and is set only by the node's own `0x1007` (or restored after an L1 soft reset). Request frames to the node carry typed console characters. No periodic, heartbeat or link-up frame exists. Nothing the PROM sends before `0x100b` (it sends no byte at all during link start) prompts a frame. The ARM L1 1.44.0 handler has the same structure and no reply. ARM L1 1.38.4 has the same four writers, the same router and the same handler (re-read, see Review), but the event-word statement holds for 1.62.1 only: in 1.38.4 no store of -1 into the word was found and `SysComInit` zeroes the block, so the event gate is open from the start (inferred). An event sent with word 0 has header `0x40`, which the PROM receiver rejects for an index below 5 (it needs class 0 there), so it cannot complete the slot either. The one frame that could complete slot `n` is an event with header `0x40 | n` from a stale event word after a warm restart, which cannot be the first-power-up path.
- **Still unknown.** What ends the wait on first power-up of a real brick. The real boots below show that it ends, for builds 4.56, 4.65 and 4.80, which carry the same wait, die and park code as 5.04. The code read still shows no L1 frame that can end it (ARM 1.44.0 and 1.62.1, ColdFire handlers). The L1 build fitted in an Altix 350 module is not established (see below). The tick is inferred to be one microsecond (the timer `0xffa0da70` divides the SHub clock count times its period register by 1000), so the wait is 3 seconds; the period register was not checked against a manual.
- **For a model.** A silent model is the faithful L1 and makes the PROM stop at its first request. To boot, answer with a status 0, zero-argument frame whose header byte is `0x20` plus the slot (5 plus the slice for the boot processor), and record that as an approximation rather than hardware behaviour. For slice 0 the wire frame is `7e 25 00 00 00 00 00 68 66 7e` (payload `25` then status 0 and count 0; FCS computed and checked against the `0xf0b8` residue).

### Real boots and the other PROM builds

Added 2026-11-15. Sources: the published logs listed here, and every SHub 1 image in the holdings, 29 builds from 3.32 to 5.04 (the
header of each carries `SGI SAL Version X.YY relDATE`; a log names a build through the `version X.YY` field the kernel prints, which is the SAL system table's version word; the leading `SAL X.Y` is the SAL specification revision).

**What the published logs show (inferred: a console log is an observation of a boot, not a read of shipped code; no log reaches before EFI).** In a Linux boot line such as `SAL 3.2: SGI SN2 version 4.65`, 3.2 is the SAL specification revision and 4.65 is SGI's SN2 PROM build version. "SAL 4.xx" on this page always means that build version, never the specification revision.

| Log | Machine | SAL printed | Build it names |
|---|---|---|---|
| Library `boot-logs/irixnet-thread-849-page-2-prism-sal-465-boot.html` (irixnet forum thread 849, page 2; two serial captures, posted 2019): `SAL 3.2: SGI SN2 version 4.65`, `SGI SAL version 4.65`, `ttySG0 ... SGI SN L1` | Prism | 4.65 | snprom 10.15 (SAL 4.65, built 2006-12-04) |
| Library mail root `linux-ia64-list`, 2007-08-01, SGI engineer, message `Pine.LNX.4.64.0707312246390.14878@schroedinger.engr.sgi.com`: `SAL 2.9: SGI SN2 version 4.80`, four logical nodes | SHub 1 test system | 4.80 | snprom 10.30 (SAL 4.80, built 2007-04-12) |
| Library mail root `linux-ia64-list`, 2005-11-18, messages `200511180316.jAI3G9g06785@unix-os.sc.intel.com` and `8110.1132286958@kao2.melbourne.sgi.com`: `SAL 2.9: SGI SN2 version 4.4` | Altix | 4.04 (the kernel prints the minor byte with `%x`, so `4.4` is minor `0x04`; 4.40 would print `4.40`) | snprom 4.04 (built 2004-12-03), held, not examined; inferred |
| owner's page, nsafran.com, Altix 350: SAL 4.56 (statement, not a capture) | Altix 350 | 4.56 | snprom 10.6 (SAL 4.56, built 2006-06-15); inferred |
| linux-ia64 list 2008 (`20080422223049.GA8765@sgi.com`, `20080624143922.GK10123@sgi.com`): `SAL 3.2: SGI SN2 version 1.42` and `1.50` | Altix 4700 class | 1.42, 1.50 | SHub 2 series, not read here |

Every log starts at the EFI banner or the kernel's own first line. The PROM's text never appears, because `0x1005` ("Prom starting...")
and the later progress texts go to the L1 display (request `0x1005` is display text), not the serial console. No log has a timestamp or
a visible delay before the kernel starts, and none shows an error from the PROM. So the logs establish exactly this and no more: real
machines running SAL 4.65 and 4.80 (and, by the owner's word, 4.56) reached EFI. They do not show whether those boots waited 3 s.
No Altix 330, Altix 3000 or Altix 350 console capture from power-on, and no L1 log, is held; the linux-ia64 and other mail archives, the forum and
owner-site captures held, and the Altix and ProPack manuals were searched for the PROM and L1 start-up strings
("Prom starting", "Init memory", "ERR 8d", "SGI SN L1", "L1 running", "L1 booting").

**What the `0x100b` request does in each build (established, objdump of every image; the die chain read to the same shape in the builds marked R below).**

| SAL builds (snprom) | `0x100b` goes through | On a missing reply |
|---|---|---|
| 3.32, 4.20, 4.31, 4.32, 4.33, 4.43 (4.04 not examined) | the plain send-and-wait (in 4.43 `0xffa380c0`), which has no die call | returns `-24`; the caller drops it; boot continues after the 3 s wait. Read in Ghidra for 4.43 and 4.20 (next paragraph); 3.32, 4.31, 4.32 and 4.33 by the absence of the `0x8d` setup in the routine (4.31 to 4.33 are not in the image set held here, so they are unchecked in Ghidra) |
| 4.55 (10.5) through 5.04 (10.54): all 23 builds | a send-and-wait that calls the die routine on `-24` (5.04 `0xffa82a10`; 4.80 `0xffa82670`; 4.65 `0xffa81cc0`; 4.56 `0xffa81080`) | `ERR 8d`, CRB message-control store, halt loop (R: 4.56, 4.65, 4.80, 4.90, 5.04) |

**Ghidra reading of 4.43 and 4.20 (established, 2026-11-15, whole-image decompile).** In 4.43 the `0x100b` routine is `0xffad0c70` (twin `0xffad0e70` for target `0x4ffff000`, called through `0xffad1070`); it builds the request with code `0x100b` and sends it through `0xffa380c0`. That routine retries a partial send up to 50 times, then calls the receive `0xffa37e00` with the timeout `3000000`, which returns `-24` on the deadline; neither contains a die call or the `0x8d` code, and `0xffad0c70` closes the slot and returns the `-24`. Its only caller, `0xffa89b50`, is a void function that drops the result. The 4.20 image has the same shape: routine `0xffac8f70` (code `0x100b`), wait `0xffa34970`, receive `0xffa346b0` (also `3000000`), caller `0xffa847c0` drops it. So in both builds a missing reply costs the 3 s and boot continues. SAL 4.33 is not among the images held here; it stays at the objdump absence reading.

In 4.43 a retry wrapper (`0xffa329d0`, six callers) already ended in this die routine's counterpart (`0xffa58380` with `0x8d`); the
version report (`0x100b`) was among the other call sites of the plain routine (20 call sites in all). Between SAL 4.43 (2005-12-02) and SAL 4.55
(2006-06-05) the two were merged, so from 4.55 on the version report is no longer fire-and-forget. The send routine passes the same
3,000,000-tick timeout (`0x2dc6c0`) in every build checked (4.43, 4.55, 4.56, 4.65, 4.80, 4.90, 5.04). The die chain in 4.56, 4.65 and 4.80 is the 5.04 one under other addresses: the die routine
(`0xffad1f70`, `0xffad2b00`, `0xffad37d0`) calls a routine that writes `0x1_0001_0000_0000` to `0x1_2000_0000`, tests the local node
and the slice in `cr.lid`, and enters the halt routine.

**The park path's inputs at `sysctl_init` (established, Ghidra and objdump of 5.04).** Nothing the boot processor holds from earlier
stages changes the outcome; the only state read is hardware:

- the simulator signature, `cpuid[2] == 0xaeeeeeee8badbeef` (`0xffa82a10`): the send returns `-24` at once and never reaches the wait;
- the slot's reply-ready byte (`slot * 0x98 + 0x211`, set by the receiver on a good frame for slot `5 + slice`) and the node timer
  (`0xffa0da70`): no frame for 3,000,000 ticks gives `-24` (`0xffa82730`);
- the die routine `0xffad2cb0(nasid, 0x8d)`: the node's state object (nasid from its first halfword; the object found through
  `0xffa7fcb0`) for the `ERR 8d` display text, which is shown only if the object's tag at `+0xeb0` is `0x4c015343` and then clears flag bit 6;
  four progress-indicator writes (`0xffa0e0d0`); then `0xffa9fc70(nasid, 0, 0)`;
- `0xffa9fc70`: its arguments are the constants 0 and 0 here, so the tests reduce to one: the SHub ID register at `0x1_1006_0580`
  (bits 42:32, read by `0xffa0dcf0`) equals `nasid`, which it does for the node's own nasid. It also writes the CRB message-control store
  and clears bits 29:26 of the scratch word `0x1_5003_1550`. Then `0xffa9fba0(nasid, slice)` repeats the node test and compares the
  slice (`cr.lid` bits 26:23) with itself, so it is true for the calling processor, and enters the halt routine `0xffaeb7c0`;
- the halt routine: marks the slice (`0xffa0eae0`), `rfi`, PAL cache init, then PAL halt in a loop.

No master or slave flag, no per-slice record and no scratch-word value that changes a branch is read on this path (the scratch word `0x1_5003_1550` is read and written back with bits 29:26 cleared, and the value is not tested). The two stores match SAL_A's error block for "PAL early self-test failed" (`0xffc4e276` area, [boot-sequence.md](boot-sequence.md)): the same value `0x1_0001_0000_0000` to the same register offset `0x1_2000_0000`, and the same clear of bits 29:26. They differ in the window: SAL_A writes through the local MMR window (`0x8000_0081_2000_0000`), the die chain through the window that `0xffa0c560` forms with the node number folded in (`0x8000_0009_2000_0000` for node 0; address bit 35 against SAL_A's bit 39, which looks like Linux's global and local MMR spaces, inferred); SAL_A's block also ORs `0x280_0000_0000` into `0x101d_0080`, which the die chain does not (read by the reviewer in 5.04 and 4.90; the die chain's halt is the PAL loop at `0xffaeb8d0`, SAL_A's a spin). So the boot processor reaches the halt loop on any
real first boot whose wait times out (established for the code). What the write does: the register is `SH_CRB_MESSAGE_CONTROL` (coherent request buffer message control), [crb_message_control](../../../devices/shub/registers.md) in the register map. The name, offset and layout are **established** from SGI's Linux 2.4 ia64 SN2 header (`include/asm-ia64/sn/sn2/shub_mmr.h`, `shub_mmr_t.h`; Linux v5.3 dropped it), and the PROM's own register-name table (the address word `0x1_2000_0000` at `0xffbfd280`, with the three entries after it holding `0x1_2000_0080`, `_0100` and `_0180`, the header's order for `SH_CRB_NACK_LIMIT`, `SH_CRB_TIMEOUT_PRESCALE` and `SH_CRB_TIMEOUT_SKID`; each entry's name pointer sits in the 8 bytes before its address word) carries the same name. Bits 11:0 are enables (system coherence, local and remote speculation, colour, five mismatch checks, bogus-write suppression, IVACK consolidation), bits 47:32 an IVACK stall count and bits 63:48 an IVACK throttle control. The OR values `0x3f1` and `0x3b03f7` set enables (and, in the second, bits 21, 20, 19, 17 and 16, which the 2.4 header calls reserved). The die write stores `0x1_0001_0000_0000`: SAL_A's copy is a plain 64-bit `st8` (`0xffc4e290`); the park path `0xffa9fc70` loads the same address and value into the argument registers of a write helper (`0xffa0c560`, not read). The value clears bits 11:0, including system coherence, and sets stall count 1 and throttle control 1 (**established** for the value, **inferred** for the effect on the hardware). The register has no reset or halt field in the header, and nothing in the PROM or in Linux treats it as a reset, so the write is read as quiescing the node's coherent traffic and not as a reset: the boot does not loop on a 3 s period, it stops at the halt loop (**inferred**; no hardware read or manual page states what the chip does with the store). Either way the boot does not continue.

**Conclusion (graded).**

- Inferred (logs, and for 4.56 an owner's statement): SAL 4.65 and 4.80 PROMs booted real hardware to EFI while carrying the die-on-silence code for `0x100b`, with the same park path as 5.04; SAL 4.56 did the same on an Altix 350 by its owner's word. So a missing reply is not what happened on those machines: something completed the wait. Whether SAL 5.04 itself boots real hardware is not shown by any held log; it differs from 4.80 only in addresses and small changes, not in this path (inferred).
- Established for ARM L1 1.44.0 and 1.62.1, inferred for 1.38.4 (writers by call graph and the event gate read; the request and response writers' gates not read in full): no L1 frame source found, and no ColdFire `0x100b` handler read (`brick-request-handlers.md` in the sysco repository), sends a frame that could do it on a cold start. The logs and the code therefore disagree for the L1 builds read; the L1 build on those machines is the missing piece.
- Inferred: the L1 on those machines was 1.37.25 or newer. Every build from 4.33 to 5.04 contains the text "Check L1 firmware version. Must be at least 1.37.25" (printed when the PROM's I/O-port set-up fails; it is a requirement of that feature, not of `0x100b`). The ARM readings in sysco that reach that range are 1.38.4 (2005-06) and 1.40.5 (2005-12). Both `0x100b` handlers were read in Ghidra on 2026-11-15 and send no reply (sysco `arm-prom-version-request-1.38.4-1.40.5.md`; 1.38.4 handler `0x8abb0`, 1.40.5 handler `0x8b460`): established; the reviewer re-read 1.38.4 only. Both predate SAL 4.55 (2006-06), and no L1 build between 1.40.5 and 1.44.0 is held.
- Unknown: which L1 build an Altix 350 module carries. The 350 guide (007-4660-001) and the L1 and L2 guide (007-3938-005) print module prompts such as `001c01-L1>`, the L1 display text "L1 running", and L1 messages, and name no firmware version or processor. Both candidate families are in the 1.62.1 package (ColdFire `O`, ARM `F`).
- Unknown: what ends the wait. Candidates not excluded: an L1 build that replies and is not held (ARM 1.38.4, 1.40.5, 1.44.0, 1.60.3 and 1.62.1 do not; ColdFire builds from 1.37.25 on were not read); a ColdFire L1 whose event word starts at a value other than -1 (the ColdFire clear routine `0xffe3d4ec` stores -1 and then calls the NVRAM setter with `0x13`; the word at `0x30006d14` has two direct references in package 5 of the 6.5.30 container, the test and that store, and no direct store of a power-on value was found, so its initial value was not determined); a frame from another source on first power-up. A model should therefore keep the approximation above.

**Findings not fixed (author to settle before these claims stand).**

1. The die-routine conflict above, for the sysco author: decide whether `0xffa9fba0` really reaches `0xffaeb7c0` for the boot processor (the parameters at `0xffa9fe00` to `0xffa9fe60` read that way) and correct `12e3608` or this page. Settled: it does, and sysco corrected `12e3608` (see the resolution above). Until then the `0x100b` grade stays at "established: no reply from the L1; unknown: PROM behaviour afterwards".
2. Incoming console frames: settled, see "Console input" below. The receiver's rule is right and the earlier `0x40 | index` reading was wrong; console input is class 0.
3. Console index for `p`: `0xffae96f0` sends with header `param_2 | 0x40`, where `param_2` is the console index (index 4 selects the remote-console buffer); that the index for `p` is the slice is inferred, not read.
4. `0xffa1a980` (called before the hub board read in `main_two`) and the callees of most `main_two` calls were not traced for further L1 requests; the census shows no other request builder site on the path, so only an indirect call through the node operations tables could add one.
5. The type `o` board reads, and which arguments the `0xffa846c0` route sends, were not traced.

**Grades.** Request codes, argument counts and order up to the jump, the link-start register sequence, the `0x0010` and SPD reader layouts, the frame format and the census are correctly **established**. The effect of a missing reply, the console index and incoming header, and `0x0010` blank-L1 values stay **inferred** or **unknown** as above.

**Cleared scope:** the request list and order before the jump to RAM, link start, `0x0010` limits and layout, SPD ids, phase and absent-slot rule, frame format and CRC, the 23-site census. **Not cleared:** the `0x100b` and silence conclusions (the sysco conflict is resolved above; the hardware effect is not), the console frame headers, the requests after the jump beyond their order and gates, and anything that depends on indirect calls through the node operations tables.

**Not checked.** The L1 program (the sysco pages were taken as given); the tick unit of the timeout; the hardware effect of the write to `0x1_2000_0000`; the callees `0xffa9f750` and `0xffa1a980`; the code of `0xffa7f59c` and `0xffb5ee7c`; the chip match value and the lock routines in the link start; the board-area bytes the parsers require; any run of the PROM.

## Review (second reading of the 0x100b wait)

Independent review of chips `ebd72b6`, `28b3864` and `a1e9539`, examined with sysco `70960aa` and `1e9c304`. The reviewer wrote none of them. Method: retools `441b26c`, Ghidra export of the IA-64 PROM images (`--sn2-prom`, whole-image decompile) and of the ARM `l1` programs, with `ia64-linux-gnu-objdump` over the flat PROM image for call sites and the halt loop. Images and hashes: `shub1snprom.bin` of snprom 10.54 (SAL 5.04, matches the checksum list), snprom 10.40 (SAL 4.90), `snprom.bin` of 4.43 and 4.20; ARM `l1` 1.38.4 (`f652c04c...`) and 1.62.1 (`22cb6287...`), carved from the 6.5.28 overlay and the 1.62.1 package and matching the hashes in the sysco pages.

**Confirmed.**
- SAL 4.20 and 4.43: the `0x100b` routine (`0xffac8f70`, `0xffad0c70`) goes through a plain send-and-wait with timeout `3000000` (`0xffa34970`, `0xffa380c0`); no routine reachable from that wait contains the `0x8d` die call, and the one caller drops the result (4.43's only `0x8d` site is the retry wrapper `0xffa329d0`, which the wait does not reach).
- SAL 5.04 and 4.90: `0x100b` goes through the wrapper with `3000000` into the routine that calls the die routine on exactly `-24` (5.04 `0xffa82c10` to `0xffa82a10`; 4.90 `0xffa82a70` to `0xffa82870`). The die chain is the same in both: display text only if the state object's tag matches, four progress writes, `0xffa9fc70` (4.90 `0xffa9faf0`), the node and slice tests, then the halt routine, whose `rfi` leads to the PAL call loop `0xffaeb8d0` to `0xffaeb8ec`. A framing error from the receiver does not change the return value (the wait loop ignores it), so only the deadline gives `-24`.
- The die chain stores `0x1_0001_0000_0000` at offset `0x1_2000_0000` and clears bits 29:26 of `0x1_5003_1550`. That is the same value and register offset as SAL_A's "PAL early self-test failed" store (`0x8000_0081_2000_0000`, and the same clear). The windows differ (address bit 39 in SAL_A, bit 35 through `0xffa0c560`), and SAL_A also ORs `0x280_0000_0000` into `0x101d_0080`. The park path does read the scratch word (read-modify-write) but never tests it; the text now says so.
- The `0x4ffff000` set: `0xffa7e3b0` calls the `0x0003` routine `0xffa7ca10` at `0xffa7e51c` with `0x4ffff000` and no slab or type fold; `0xffa7e6d0` calls the `0x0013` routine `0xffa7cbe0` (its `0x0003` fallback inside) at `0xffa7e84c`; `0xffa7d34c` and `0xffa7d8ac` use `0x0ffff000`. One looseness: `0xffa7e84c` is a `0x0013` site, and its `0x0003` use is the fallback in `0xffa7cbe0`.
- The receiver `0xffa87830`: on a good CRC (`0xf0b8`) it increments the reply-ready byte of the slot named by the header index; the header is accepted as class `0x20` or `0x40` for index 5 to 19, or class 0 for index 0 to 4, anything else is rejected.
- ARM 1.38.4 and 1.62.1: the `0x100b` literal compare (`0x892e8`, `0xc9410`), count 4 or `-100`, log, `SysComEventDisable` on the slab test, and no `ARG__START` on the work path; the routine is registered as a direct function for destination `0xffff006` and the router calls it and returns 0 without sending. Only four routines call `PPPWrite` in both builds. Their input is the packet class byte set by the router or by `EvtIRouter`; the event writer needs the event word not equal to -1; the request writer sends one console character per request; responses need `ARG__START`. `nvramLogFinsert`, `nvramSet` and the `vram` setters are storage routines with no router or frame calls. No frame from these builds can complete slot 5 or above during the wait.
- "SAL 4.xx" is the SAL system table's version word, not the specification revision: the kernel prints `SAL <revision>: <oem> <product> version <version>` from `sal_revision` and `sal_version` (linux-history `arch/ia64/kernel/sal.c`). The page's wording is right; I made the one sentence that said "the SAL number" exact.

**Changed.** Logs are an observation, so "established" became "inferred" for the log table heading and the real-boot bullet (and the 4.56 owner statement no longer sits under an "Established" label). The scratch-word sentence now says what is read. The SAL_A match is stated. The frame-source bullet and the conclusion carry a 1.38.4 difference: its event word is not stored as -1 anywhere the review found, `SysComInit` zeroes the block, and the gate is open from the start (inferred; the ELF word is in bss). A frame sent with word 0 has header `0x40`, rejected by the receiver, so the open question is unchanged. The citation `boot-logs/linux-ia64-list/` is replaced by the mail root name.

**Citations.** The mail logs resolve (root `linux-ia64-list`, inbox `linux-ia64`): `Pine.LNX.4.64.0707312246390.14878@schroedinger.engr.sgi.com` (SAL 2.9, version 4.80), `200511180316.jAI3G9g06785@unix-os.sc.intel.com` and `8110.1132286958@kao2.melbourne.sgi.com` (version 4.4; the second says at least SAL 4.30 is needed, which fits 4.04). `boot-logs/irixnet-thread-849-page-2-prism-sal-465-boot.html` does not resolve in `irix-artifacts`, `irix-mirrors`, `irix-extracts` or `origami-docs`, and a search by name finds nothing, so the Prism 4.65 row is not checkable from the Library as it stands.

**Not checked.** Builds 4.55 to 4.80 (4.56, 4.65, 4.80, the other 18) are not in the roots the reviewer had, so the "all 23 builds" and the 4.56, 4.65, 4.80 die-chain statements are the earlier work, not re-read. ARM 1.40.5, 1.44.0 and 1.60.3 handlers; any ColdFire code; the request and response writers' gates in 1.38.4 beyond the call graph; which L1 tasks address packets to the SysCom tasks (the console request sources in 1.38.4, `0x68308` and `0x68430`, were not resolved); whether 1.38.4 sends any event at cold start; the hardware effect of the `0x1_2000_0000` write; the tick unit; the receiver was read in the decompile, not in objdump.

## Review (third reading: who addresses the L1's SysCom writers)

L1-side tracing in the sysco repository, `software/firmware/l1/sn2-prom-link-1.62.1.md` ("Review (third reading: who addresses the SysCom writers)") and `arm-prom-version-request-1.38.4-1.40.5.md`, for ARM L1 1.38.4 and 1.62.1. No frame ends the `0x100b` wait on a cold boot (established for both builds). The only node-channel writers are the four already named, fed by the L1's SysCom outbound task (one task in 1.38.4, one per slab in 1.62.1). Their inputs are per-character console requests (need a person at the L1 console in pass-through mode, or an L2 feeding console input), environment events (forwarded only when the event word is not -1) and answers to the node's own requests. The event word is -1 after every power-on in both builds, for every brick type that has a SysCom writer at all; it is restored only after an L1 soft reset, and the `0x100b` handler clears it when its slab matches the request's, so a stale event can land only in the short interval before the first request is handled (inferred; the interval was not measured). The `?` brick-type request frame has header `0x40 | subchannel`, which the receiver would accept for slot `n`, but it also needs a console character, and 1.38.4 has no such branch. No heartbeat, status or link-up frame exists (established). So what ended the wait on real machines is still unknown, and the L1-side correction is that 1.38.4's event word is not left at zero.

## Review

Independent re-read of the CRB message-control rewrite and the L1 sender paragraph.

- **Confirmed (established).** SGI's Linux 2.4 ia64 SN2 MMR headers define `SH_CRB_MESSAGE_CONTROL` at `0x1_2000_0000` with `INIT` 6 and mask `0xffffffff00000fff`; enables at bits 0 to 11 in the order the register page lists, `IVACK_STALL_COUNT` at 47:32 and `IVACK_THROTTLE_CONTROL` at 63:48. `SH_CRB_NACK_LIMIT` is at `+0x80` (limit 11:0, `PRI_FREQ` 15:12, enable 63), `SH_CRB_TIMEOUT_PRESCALE` at `+0x100` (scaling factor 31:0, `INIT` 0) and `SH_CRB_TIMEOUT_SKID` at `+0x180` (skid 5:0, `RESET_SKID_COUNT` 63, `INIT` 7). In the SAL 5.04 PROM the name table's address words for these four are at `0xffbfd280`, `0xffbfd290`, `0xffbfd2a0` and `0xffbfd2b0`, followed by `SH_MEMORY_WRITE_STATUS_0` (`0x1_2007_0000`, as in the header). Each entry's name pointer is in the 8 bytes before its address word, so the table carries the right names; read naively, the pointer next to an address word names the next register. The PROM's string table also holds `SYSTEM_FLUSH_DURATION`, `SYSTEM_FLUSH_INTERVAL` and `ENABLE_PIPE_SNOOP_ERRORS` among the message-control field names, which the 2.4 header lacks. The park path `0xffa9fc70` loads `0x1_2000_0000` and `0x1_0001_0000_0000` into the argument registers of a write helper; SAL_A stores the same value with `st8` at `0xffc4e290` after `movl r9=0x8000008120000000`. The OR at `0xffa978e6` selects `0x3b03f7` when bits 31:28 of the register at `0x8000008110060580` exceed 2 and `0x3f1` otherwise, between a set and a restore of bit 24 of `0x8000008120010100`. `0x3b0000` is bits 21, 20, 19, 17 and 16.
- **Corrected.** Five mismatch checks (bits 5 to 9), not six; bit 3 is a colour value, not an enable. The value written clears bits 11:0 rather than "twelve enables". Bit 24 is restored from the saved value, not simply cleared. "Plain 64-bit store" holds for SAL_A only; the park path's write helper was not read. The register map's public source column cited Linux v5.3 and kernel use for these four registers, which is wrong (no kernel code touches them; only the two headers define them), and the field sources were dropped by the generator because they did not start with an allowed prefix. Fixed through `public_from` and rewritten source strings.
- **Grades.** The name, offset and layout are established; the reset values stay inferred (the `INIT` macros); the effect of the die write is inferred and nothing in the pages claims more. No source read says the register resets a node, and none says it does not, so "no boot loop" rests on the missing reset field. SAL_A spinning after the store is read from code.
- **Patents.** US 6,678,798 (node controller read-latency, speculative reply) and US 6,751,698 (SN1 Bedrock) are in the Library. 6,678,798 describes the SHub-style node controller (processor interface, memory directory, network, I/O, local block, crossbar), NACK-based non-blocking protocol, and the timed I/O read after which a missing invalidate acknowledgment is ignored; the three pages read (front page and the first two of the description) name no registers, so it explains what the speculative and IVACK controls are about but not what clearing the coherence enable does at the chip. The Bedrock patent is another chip and its source map in the Library says it is not a register map; it was not read through. Neither states what a write to this register does. The effect stays inferred.
- **Not checked.** The write helper at `0xffa0c560`, the SHub 2 overlay's `SH2_CRB_MESSAGE_CONTROL` name, and the "SAL_B" users of the NACK, prescale and skid registers. URLs: none read outside the Library.

## Review (request frame grammar and identity replies)

Independent re-read of the frame grammar and the `0x0003`, `0x0002` and `0x000e` replies, in Ghidra with Capstone and `objdump` as cross-checks. Images: `shub1snprom.bin` (sha256 `51ccf9ad830b...`), the 1.62.1 and 1.38.4 `/stand/sysco/bin/l1` programs (sha256 `22cb6287...` and `f652c04c...`).

- **Confirmed (established).**
  - `0xffa81f40` writes the count byte only when its sixth parameter (`cmp4.eq` at `0xffa81ff6`) is nonzero, and `0xffa82150` returns length 6. Argument tags are `0` plus 4 big-endian bytes, `1` plus the string and its NUL, and `0x80|n` plus n bytes. Slots are 2, 2 and 3.
  - The sixth parameter is 0 at all six zero-argument call sites listed in "Frame". `0x100b` passes 6 and `0x1005` passes 2.
  - The CRC of the wire example is `69 27`.
  - On the L1, `syscom_process_inbound_request` (1.62.1 `0xc2284`, 1.38.4 `0x83ac4`) reads byte 7 only if the length is above 7 and otherwise takes 0. The loop runs count times. The code starts the argument list at 1, so the entry `-100` test (total zero) cannot fire. `PPPRead` (read in 1.38.4) strips the check bytes before the length reaches the parser.
  - The reply layout, header, status, count and arguments, gives 16 bytes for `0x0003` and 11 for `0x0002` and `0x000e`.
  - The PROM reply parser `0xffa82270`: status 0, then count equal to the arguments consumed, or `-32` for a wrong tag and `-33` for a wrong count. The lowercase fold, the `(slab + 1) & 0xff < 2` rule and `0xffa7d010` packing are as written. The rule fires only for the lowercase types `f`, `l`, `b` and `{`.
  - Destination `0x0ffff006` is the `0xffa7d1f0` path (it passes `0xffff000`). `0xffa7e3b0` passes `0x4ffff000`.
- **Corrected.**
  - The rack field is bits 15:6 of the word, not 19:6.
  - The call-site list named routine entries. The list now gives both.
  - `0x4ffff000` is rewritten to `0x0ffff000` for node types `m` and `o`.
  - The slab-0 sentence in the `0x000e` entry stated a value the code does not fix.
  - A `0xff` slab is not cached.
- **1.38.4 replies (read, not on the page before).**
  - The `0x0002` and `0x0003` handler (`0x8882c`) gives the same layout, but its type mapping differs: type `Z` and type `|` both become `,` (with a log entry), and `=` becomes `#` when the per-slot flag is zero. 1.62.1 has only the `=` rule.
  - `0x000e` replies with the slab, or `slab & 1` for type `Z`. There is no blade workaround. 1.62.1 applies the workaround only for types `,`, `}`, `.` and `$`, or a brick with more than one slot.
  - None of this changes the `F` path.
- **Lone-node slab.**
  - For type `F` the L1's `SysComGetSlab` of the source tag is `tag >> 5`, and the tag is `(channel * 32 + (header & 0x1f)) & 0x7f`. The slab is the channel number the frame arrived on, mod 4.
  - The channel number of the node link on an `F` brick comes from the Opus TIO scan-chain configuration, which was not read. Slab 0 is therefore still inferred (it holds if the node is channel 0), and so is the `c` fold.
  - The tag-to-request-struct copy through `IRouterRequest` was read only as far as the argument passing.
- **Grades.** `F` for an Altix 350 and slab 0 for the lone node stay inferred.
- **Not checked.** The `0x4ffff006` caller chain beyond the `0xffa819c0` rewrite, and the 1.38.4 `0x0013` handler.

## Review (console input frames, commit cf6ed3d)

Independent re-read in Ghidra (IA-64, `--sn2-prom --no-analysis`) of snprom 10.54 and an objdump listing of `0xffa88590` to `0xffa8860c`. The L1 side is reviewed on the sysco page.

Confirmed: the header test. `0xffa88590` takes the index as `header & 0x1f`, branches back on `0x7e`, takes class `header & 0xe0` equal to 0 for index 0 to 4 and class `0x20` or `0x40` for index 5 to 19, and any other index or class falls to -23 (`0xffffffe9`); so `0x44` and `0x40` to `0x43` are rejected. The CRC is seeded with the header byte, the table is the reflected FCS-16 one, the residue test is `0xf0b8`, and a frame of header plus FCS only (empty payload) is accepted for index below 5. Ring offsets: base `ctx + index * 0x98 + 0x21c`, tentative write `+0x2a4`, committed write `+0x29c`, read `+0x2a0`, mask `0x7f`; ready byte `+0x211` incremented on a good frame and cleared by `readc` (`0xffae93c0`) when the ring empties; poll `0xffae9250` raises `+0x210`, calls the receiver only when `+0x211` is zero, lowers `+0x210`, and returns whether `+0x211` is set. A full ring sets the index's bit in `ctx+0x40`, calls the hook at `+0x248` of the chip table and returns -21; `readc` undoes it. For index above 4 the receiver also pushes a zero and the index byte ahead of the payload; index 0 to 4 has no such prefix.

Recomputed with a scratch script (FCS-16, init `0xffff`, polynomial `0x8408`, complement, low byte first, escape `0x7e` and `0x7d`): header `04`, `a`: `7e 04 61 a8 1a 7e`; header `00`, `a`: `7e 00 61 c8 7d 5d 7e` (high byte `0x7d` escaped); header `04`, CR LF: `7e 04 0d 0a 8f ba 7e`. All three match the page.

Changed: the "only taken while a poll is outstanding" bullet (above) said bytes wait in the UART in every case; for the processor's own slice index, and for index 4 with `ctx+0x28` bit 2 set, the receiver resets instead. Grade of that bullet stays inferred.

Not checked: the callers of the chip hook at `+0x248` beyond its use here; the SAL runtime's `l1sc_receive` equivalence (rt `0x53b80`); the SAL console calls `0x26`, `0x29`, `0x2b` and the runtime copies; the `p` and `r` wrappers (`0xffae8b70` to `0xffae9d20`) beyond their poll, readc and getc entries.

## Review (request `0x0006` in I/O discovery, commit a132551)

Independent re-read on 2026-11-16 in Ghidra (IA-64, `--sn2-prom --no-analysis`) of snprom 10.54 (`shub1snprom.bin`), with a flat objdump listing as a cross-check on the loop, the builder and the PIC-init stores. The PIC register decode is reviewed on the [PIC page](../../../devices/pic/README.md); the L1 side on the sysco page `software/firmware/l1/sn2-prom-link-1.62.1.md`.

**Confirmed.**

- Chain `0xffab38b0` -> `0xffab15c0` -> `0xffab0f10`; `0xffab0f10` dispatches only a widget id part `0xd102`, runs `0xffab0c00` on `W` and `W + 0x80_0000`, then calls `0xffabfb10` once; `0xffabfb10` calls `io_mfg_info` (`0xffaf1ee0`, site `0xffac01fc`); even node to `0xffaecd80` -> `0xffa85550` -> `0xffa84990` -> `0xffa843f0` (builder `0xffa81f40`, send `0xffa82c10`), odd node to `0xffaeccd0` -> `0xffa84fd0` (always id 1). Once per PIC widget on this path.
- Arguments: four tag-0 integers 98, selector 2, offset 0, length 64 (`0xffa843f0` stores them in that order and adds 64 to the offset and the destination each pass). Id 98 (`0x62`) is built only in `0xffa85550`, when the cached type letter is `o` (0x6f); the only other callers of `0xffa84990` are in `0xffa84fd0`, which passes 1. Target `0x4ffff000` is rewritten to `0x0ffff000` in `0xffa819c0` for cached type `m` or `o`; the builder ORs in task 6, giving `0x0ffff006`, request code 6, then the count byte 4. The type letter is lowercased in `0xffa7ca10` (`A` to `Z` add 0x20).
- Reply grammar in `0xffa82270`: status word, count byte that must equal the number of arguments read (else -33), an int with tag byte 0 (else -32), then a raw block whose length is the low 7 bits of its tag byte. Status -107 makes `0xffa843f0` return 3; every other negative status returns 1; both end in the "error reading info area" message, `io_mfg_info` zeroes the board string, and the caller ignores the result. A zero length byte prints "eeprom length byte of ZERO" and returns 1; a nonzero checksum prints "bad checksum" and returns 3.
- Silence: `0xffa82c10` waits 3,000,000 (`0x2dc6c0`) ticks, returns -24 and calls `0xffad2cb0` with 0x8d first. Send errors other than -26 return at once; -26 is retried 50 times with a 500 us wait, then returns -26.
- Name for type `o` is "onboardIO"; an unmapped letter gives "WEIRDIO" (string bytes read at `0xffbb83a0`, `0xffbb83f8`).
- Whether `0xffad2cb0` parks the boot processor was not re-traced here; the page's earlier "Silence" section owns that.

**Changed (fixed above).**

- `0xffaad6d0` is called from `main_three` at `0xffad756c`, not from `0xffaad720`, which does other I/O set-up and does not call it. `0xffab38b0` has a second caller, the wrapper at `0xffaadc10`, which has no direct caller (how it is reached was not traced). The "master only" gating is by the test `0xffa0ff30` in `0xffab38b0`; the branch around the call in `main_three` tests that routine's result too, and its arguments were not resolved.
- "Once per PIC widget" holds for this path, but `0xffabfb10` has a second caller, `0xffaaeb10`, which calls it for widgets with id part `0xe000` or `0xe010` (the TIO bridge parts) when the module type letter is one of a set that includes `f`. The call at `0xffaaeafc` is not a generic accessor: `0xffaae7f0` repeats the type-to-name map and the `io_mfg_info` read for another widget class. Both routes send `0x0006`; for a type-`f` module they send id 1. How `0xffaaeb10` is reached (no direct caller) and whether an Altix 350 takes it were not traced.
- The chunk loop is not bounded by length 64: the caller passes length 0, which `0xffa843f0` turns into 0x40000000, so only the bytes-left integer ends it, and chunk size is the smaller of 64 and the bytes left. The parse buffer is 496 bytes (frame 512, buffer at +16), not 490. Nothing stops a reply from claiming more.
- Board-area checks: the version byte is not compared with anything. A `0xc1` byte only ends the optional custom fields (two are read); a missing one is not an error. The checksum covers `length * 8` bytes from the buffer start. Failures are the length-zero and checksum cases only.
- The board string is not only searched for `Laser:`. `0xffaec9d0` builds it as `Part:...;Name:...;Serial:...;Revision:...;Laser:%x;`; the `Laser:` number is a hash the PROM computes from the serial (`0xffaec8b0`, base 36), and `0xffabf570` parses it as a hex number (`0xffa154a0` with base 16) into component offset `0x28`, not "16 bytes". The string itself is also copied into an allocated buffer (component offset `0x68`). So a reply needs a parseable area, but its contents only reach hinv-style strings.
- Status -106 is special-cased in `0xffa82270`: it returns the next integer minus 0x19e10, which can be non-negative. No L1 build read sends it; ignore it in a model.

**Not checked.** Whether `0xffad2cb0` halts. Who calls `0xffaaeb10` and `0xffaadc10`. The `0xffa82630` and `0xffa82730` send and receive routines beyond their return values. The ColdFire L1 handlers. Grades otherwise stand; "once per PIC widget" is now established for the PIC route only.

## Review (request 0x1007 and the kernel console, commit 14dc77b)

Independent review of chips commit `14dc77b` (the section "Request 0x1007 and the kernel console" here and the `0x02000043`/`0x02000044` rows of `software/sal/runtime-services.md`). The reviewer did not write it. Method: Ghidra export of `shub1snprom.bin` (snprom 10.54, `--sn2-prom --sal-runtime`) for the runtime and SAL_B functions named below, `ia64-linux-gnu-objdump` over the inflated runtime ELF for r8 and r9 and for constants, the linux-sn2 tree (7.3-rc3) for the kernel side, and a CRC script for the frames.

**Confirmed.**
- `SN_SAL_SYSCTL_EVENT` handler `rt:0xe290` calls `sysctl_event_init` (`rt:0x4cb80`); the SAL return is r8 = 0 and r9 = the sign-extended 32-bit result (objdump of `0xe42c` to `0xe470`). `sysctl_subch_open(state, 0xffff000, 0x13)` claims slot 19 (`0x98` bytes per slot, in-use byte `+0x210`, `-30` if taken). `sysctl_cmd_open` takes `5 + (cr.lid >> 23 & 0xf)`. The request is task 6, code `0x1007`, one integer argument = 19 and is sent with the 3,000,000 tick wait; `sysctl_cmd_interpret_resp` is called with an empty expected list and reads only the status (and replaces `-106`).
- Reply `25 00 00 00 00 00` and the framed bytes `7e 25 00 00 00 00 00 68 66 7e` (recomputed: complemented CRC-16, `0x6668`, low byte first, no escapes). The request frame's CRC is `0x173f`.
- Timeout chain: a send that keeps returning `-26` is retried 50 times at 500 ticks; a receive that returns `-24` makes `sysctl_cmd_command_timeout` (`rt:0x50370`) call `main_node_die_remote(nasid, 0x8d)` (`rt:0x677f0`): `ERR %x` on the display, LED and flag writes, `intcon_die_remote`, `cpubus_disable_bus`.
- Kernel: `scdrv_init` (`device_initcall`) calls `ia64_sn_irtr_init` and `ia64_sn_irtr_intr_enable(RECV)` per node, and `scdrv_event_init` only when the node is the console nasid; the failure message is "couldn't open event subchannel" and the kernel reads `rv.v0`; `request_irq(SGI_UART_VECTOR = 0xe9, ..., IRQF_SHARED)`. `sn_console.c` uses `PUTB`, `XMIT_CHARS`, `POLL`, `GETC`, `READC` and `INTR` as the table says; mask 1 is transmit, 2 is receive; status passes mask 0 and action 2.
- `INTR` (`rt:0x7fe90`, arguments mask then action): status ignores the mask; receive on adds one to the slot 4 count and sets `IER` bit 0, off clears it and subtracts; transmit off calls `l1sc_xmit_intr_disable`; anything else returns -1. `XMIT_CHARS` (`l1sc_send_async`, header `0x44`) accepts a buffer only when the previous one is drained (else 0 accepted) and enables the transmit interrupt; `l1sc_send_intr` then pushes the next buffer. Wrapper addresses `0x7c00`, `0x80c0`, `0x7fe0`, `0x7990`, `0x81b0`, `0x82c0` and the callee chain match the table.
- 16550 offsets: `IER` `+8`, `IIR` `+0x10`, `LSR` `+0x28` bit 6, data `+0`; the 5,000,000 tick limit is in `sc_uart_send_chars`.
- SAL_B writes: `0x8000000910000980` (vector `0xe9 << 52`, destination `<< 4`) at `0xffb73b86` and `0x8000000910000a00` = `0x2000` at `0xffb73bc6`, in `0xffb73a40` (objdump of the bundles).
- Linux: `SGI_UART_VECTOR` is `0xe9` (`arch/ia64/include/asm/sn/intr.h`); the 60 Hz fallback is `HZ * 16 / 960` jiffies in `sn_sal_switch_to_asynch`, and the timer stops polling once `sc_port.irq` is set; `XMIT_CHARS` output in interrupt mode leaves from the PROM's transmit interrupt.

**Changed (fixed above).**
- The UART address. `0x7fed40000` is the offset in the MMR window; every PROM access uses `0x8000000ffed40000 | nasid << 38` (as this page already said in "Real boots"). A model that mapped `0x7fed40000` literally would miss it.
- The identification register: raw values are mapped to two bits as described, `0x06` reports both, and the status call loops until both are clear, so the clear-on-read behaviour is a model requirement, not an option.
- The transmit poll sleeps 10 ticks between reads, sends 16 bytes per burst and drops the buffer on timeout.
- The acknowledge text named `sn_end_irq`, which this kernel does not have; replaced with `sn_ack_irq` and `handle_level_irq`.
- Delivery stays inferred, with the enable bit 13 against event bit 20 mismatch stated; it was left implicit.
- "The kernel does not come back" from the die path is now inferred (the code returns, the stop is a model observation).

**Not checked.** That ops-table slots `+0x248` and `+0x250` are `sc_uart_rxintr` and `sc_uart_txintr` was read from the call sites and their consistency (readc re-enable, xmit disable), not from the table. The `+0x800`/`+0x804` ring read in `l1sc_intr_status`. `sysctl_display_text` as request `0x1005`. `PUTB`'s per-byte buffering helper `0x7f7a0`. The `-106` second-status path (decompiler lost it). Whether the 3,000,000 ticks are 3 s. Hardware delivery of the UART interrupt.

## Geoid consumers of the identity requests

`0x0003`, `0x000e` and `0x0013` feed the node geoid through `0xffaac4b0`; the field mapping and the replies for a lone 350 are in [KLCONFIG: geoid and module id](../../../platforms/sn2/klconfig.md#geoid-and-module-id). No new request code was found. Related, not an L1 request: `shub_discover` reads an L1-pushed word from SHub scratch `0x1_101d_0080`; its layout (type byte `l`; slab bits 18:16, bay 25:20, rack 34:26, slot 38:35, module type forced to `c`) is **inferred** from `0xffa8d120` and is not yet modelled.

## Requests after boot: text commands, the clock and the event clear

Requests the runtime makes after the console is up. Frames are as in "Conventions"; addresses are SAL_B in `shub1snprom.bin` 10.54. Read in Ghidra, objdump cross-check, no emulator. L1 side: sysco `software/firmware/l1/sn2-power-time-requests-1.62.1.md`.

| Request | Site | Header byte | Destination word | Arguments | Reply the PROM reads | Grade |
|---|---|---|---|---|---|---|
| `0x0000` text command | `0xffa0d760` (`version`), `0xffa0d3d0` (reset), `0xffa0d610` (power-down) | the open handle: `0x12` for the reset text, one per call otherwise | `0x0ffff003`, or `0x1ffff003` for the L2 forms (task 3) | one string, tag 1, NUL-terminated | `version` (`0xffa8c9a0`): status 0 only is tested; the reset and power-down texts: any valid frame, not parsed | established |
| `0x200e` time of day get | `0xffa7f190` | `5 + slice` | `0x0ffff006` | none (six bytes) | status 0, then six integers, tags 0: year, month, day, hour, minute, second | established |
| `0x200d` time of day set | `0xffa7f430` | `5 + slice` | `0x0ffff006` | six integers, same order | status only | established |
| `0x100a` event subchannel clear | `0xffa7efe0` | `5 + slice` | `0x0ffff006` | none | none read (the L1 sends no reply); only the type `l` power-down path sends it | established |

- **Strings sent (established).** `version`; `p <partition> rst` (L2) and `* rst` (L1) for reset; `p <partition> pwr d` and `* pwr d` for power-down. The `*` form is the L1's send-to-all command; `p <n>` is routed by an L2.
- **Timeouts and the L2 probe.** The reset text is sent and waited for with the standard wait (`0xffa82c10`, 3,000,000 ticks); the `version` probe and the power-down texts wait 20,000,000 ticks (`0xffa82a10`, `0xffa0d760`). A silent `version` probe takes the `0x8d` die path after 20,000,000 us; the die routine returns and the reset continues on the L1 path (established, `0xffa82a10`, `0xffad2cb0`). The probe's destination word is `0x1ffff003` and counts as an L2 only for reply status exactly 0. The ColdFire `O` L1 does not route that word to its command task: it sends a routing-error reply when no L2 is attached (sysco `sn2-power-time-requests-1.62.1.md`), so the PROM sends `* rst` to `0x0ffff003`. A model answers the probe with an error status, never 0.
- **`0x200e` with no L2 or chip.** The reply must carry six integers; a different count gives `-33` and the clock falls back to 1998-01-01 (section 6.4 of [runtime-services.md](../../sal/runtime-services.md)).
- **Order seen on a 350 (inferred).** `0x200e` once at the first `GetTime` and again after 300 s of elapsed RTC; `0x200d` only from `SetTime`; `0x0000` only on `reset`; nothing on `poweroff`.

### Review of "Requests after boot"

Independent re-read on 2026-11-16 (PROM 10.54 in Ghidra, `0xffa0d3d0`, `0xffa0d760`, `0xffa8c9a0`, `0xffa82a10`, `0xffa81f40`, `0xffa82270`).

**Confirmed.** Destination words (`0x0ffff003`, `0x1ffff003`, task 6 for `0x200e`, `0x200d`, `0x100a`); request code 0 with one tag-1 string; the strings; `0x200e` expects 12 argument bytes (six integers); the reply parser returns the status word as is, status `-0x6a` is special-cased, and a negative status with a string argument copies the text out; `0x100a` is read-less.

**Changed.** The probe paragraph above. Frame header detail: the first four reply bytes are the status, so only status 0 satisfies the probe.

**Not checked.** The ColdFire `version` handler `0xffe4c01c` (not reached for `0x1ffff003`); the ARM catch-all for a type-1 destination (the ARM router `0x109af8` also treats `0x1ffff` as non-local).

## Review (console transmit and THRE, commit 860a6b1)

Independent review of chips commit `860a6b1`, examined at that revision. The reviewer wrote none of it. Method: the SAL 5.04 runtime in the Ghidra IA-64 module (`--sn2-prom --sal-runtime --no-analysis`, addresses as `rt:` plus `0x100000000`), `sn_sal.h` and `sn_console.c` in the held linux-sn2 tree, and the PC16550D pages from the Library (`origami-docs`, `library/cache/misc/www.scs.stanford.edu_10wi-cs140_pintos_specs_pc16550d.pdf`, pages 17 and 18). Nothing was run.

**Confirmed.**
- Call numbers: `PUTC` 0x21, `GETC` 0x22, `POLL` 0x26, `INTR` 0x27, `PUTB` 0x28, `XMIT_CHARS` 0x2a, `READC` 0x2b (`sn_sal.h:40-49`); `INTR` takes (mask, action) with action 0 off, 1 on, 2 status and mask 1 transmit, 2 receive (`sn_sal.h:101-108`, `:394`).
- `sc_rt_cons_xmit` (`rt:0x7fdb0`) -> `l1sc_send_async` with header 0x44; the buffer is drained when the words at `+0x68` and `+0x6c` are equal; `l1sc_fill_sendbuf` (`rt:0x52fe0`) clamps the payload at 0x7f and returns the count taken; the not-drained case returns 0 and sets the slot byte at `slot*0x98 + 0x212`; it ORs the slot into the want mask at `+0x78`, sets bit 63 of the state register and calls slot `+0x250` with 1. `sc_uart_txintr` (`rt:0x605f0`) is an unconditional read-modify-write of IER (register offset 8, 16-bit store) setting bit 1, so an `XMIT_CHARS` with bit 1 already set does write IER 3 to 3.
- `l1sc_intr_status` (`rt:0x52a00`): reads IIR at register offset `0x10` first, transmit = bit 1 of IIR, receive = bit 2; transmit calls `l1sc_send_intr` (`rt:0x527d0`), which calls `sc_uart_fill_fifo` (`rt:0x5f540`) when the buffer is not drained and otherwise sets the slot byte and reports mask 1; the slot byte also gives mask 1 while the buffer stays drained; the loop ends on mask 0 or on transmit-only after mask 1. `sc_uart_fill_fifo` writes at most 16 bytes to the data register with no LSR read and stores 16 minus the count in bits 62:58 of the state register.
- `sc_uart_send_chars` (`rt:0x5eb40`): with a free-slot count of 0 it polls LSR (offset `0x28`) bit 6 every 10 ticks for at most 5,000,000 ticks, then drops the buffer and calls `chipset_led_set(0x81)`; `l1sc_send` (`rt:0x53220`) clears IER bit 1, sends, and sets it again when bit 63 is set, and does the same around an unfinished asynchronous frame. `sc_rt_cons_intr` (`rt:0x7fe90`): status ignores the mask; transmit-on returns -1; transmit-off is `l1sc_xmit_intr_disable`.
- `sc_uart_init` (`rt:0x5fe40`): wait for TEMT (up to 100,000 ticks), divisor from `sc_shub_uart_divisor` (returns 1) written with DLAB set, LCR 3, MCR 0x22, IER 0, FCR 0xc7, then a scratch-register read. All values match.
- Linux: `sn_console.c` line citations (48-49, 213, 307, 517-575, 583-601, 673-676, 711) match the file at `69571599c5`, and the file is also present at `v7.3-rc3-epic1-sn2`, `v7.2-epic3-sn2` and `v6.19-epic3-sn2` (existence only). The driver also installs `handle_level_irq` for the vector (line 708).
- PC16550D: page 17 gives the LSR bit 5 and bit 6 text and Table IV (THRE reset by reading IIR when it is the source, or by writing the holding register); page 18 gives IIR bits 7:6 set when FCR bit 0 is set.

**Findings.**
1. **The datasheet is graded established for a part nothing shows is in the SHub.** "Rule broken, established by the datasheet" and rules 1 to 3 and 5 take PC16550D behaviour as the SHub junk-bus UART's. The PROM drives 16550-style registers (FCR 0xc7, 16-byte bursts, LSR bits 5 and 6), but the UART is not identified anywhere in these pages, and the PROM writes MCR 0x22 where the datasheet says MCR bits 5 to 7 are permanently 0 (page 18). Under this repository's rules a compatible part is inferred. Fix: grade rules 1 to 3 and 5 "inferred (PC16550D; the PROM's register use is 16550-compatible)" and keep the PROM-side facts established.
2. **The stall is explained by the missing re-arm, not by the instant THRE.** With rule 4 (an IER write with bit 1 set re-raises a pending THRE) an instant THRE no longer stalls: the final `INTR` status call consumes the interrupt, `XMIT_CHARS` rewrites IER, and the interrupt fires again. A model whose THRE is a level of "THRE set and IER bit 1" (not cleared by the IIR read) also does not stall. So the "Instant THRE (what breaks)" and pacing bullets describe fidelity, and rule 4 is the one rule progress depends on. Fix: say so in the bullets and in rule 2. Rule 4 stays **inferred**, as written: page 17 says THRE "causes the UART to issue an interrupt ... when the Transmit Holding Register Empty Interrupt enable is set high", which supports a re-trigger on enabling, and is silent on a write that leaves bit 1 at 1.
3. The chip-method slot table (`rt:0xa1bd0`, "each slot read from the relocation table") was not re-read. The slot-to-function mapping holds by behaviour (slot `+0x250` is the IER read-modify-write, `+0x210` is `sc_uart_fill_fifo`, `+0x258` is `sc_uart_intr_status`, `+0x208` is the synchronous sender), which is enough for the claims, but the offsets themselves are unchecked.

**Verdict.** Accept the transmit-path analysis and the model rules, with findings 1 and 2 applied. Rule 4 correctly remains inferred.

**Not verified.** The IER sequences and the stall trace seen in the model run; the real UART's baud, input clock and same-value IER write behaviour; the older circular-buffer `sn_transmit_chars`; the claim "about 9 interrupts" beyond the arithmetic (127 payload plus 5 framing bytes over 16); the PC16550D cover date; the SHub 2 image.
