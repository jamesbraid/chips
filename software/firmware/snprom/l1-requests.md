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
  bytes 0 to 3 big-endian destination word, bytes 4 and 5 request code, byte 6 argument count, then arguments (tag `0` plus 4-byte
  big-endian integer; tag `1` plus NUL-terminated string; tag `0x80|n` plus n raw bytes). The destination word is the open target
  ORed with 6 (the task). Every request on the main path is opened with target `0x0ffff000`, so the word is `0x0ffff006`
  (established, `sysctl_cmd_open` `0xffa819c0` and each wrapper's constant); the `0x4ffff006` form exists only on the slot and slab
  wrappers `0xffa7e6d0`/`0xffa7e900`, reached through `0xffaac4b0(4, ...)`, which this path does not call (inferred, caller list).
  The L1 ignores everything but the task number.
- **Wire framing** (established, `0xffa86c90`): flag `0x7e`, one header byte, the payload with `0x7e` and `0x7d` escaped as `0x7d`
  plus the byte xor `0x20`, the complemented CRC-16 (initial `0xffff`, reflected `0x8408`) low byte first, flag `0x7e`; payload
  clamped to 127 bytes. The request header byte is the open handle: `5 + processor slice` (slice = `cr.lid` bits 26:23), so 5 for
  the boot processor, up to 19 when several are open. Console traffic uses `0x40 | slice` (class 2).
- **Reply** (established, `sysctl_cmd_interpret_resp` `0xffa82270`): the receiver (`0xffa87830`) takes frames whose header byte is
  `0x20 | n` or `0x40 | n` for n from 5 to 19 and checks the CRC; the PROM then reads status in bytes 0 to 3 (big-endian), the
  argument count in byte 4 and arguments from byte 5. Status 0 is success. Status `-106` selects a second status at bytes 6 to 9
  (that value minus 106000). Any other status is returned to the caller unchanged. With status 0 each caller supplies a list of
  expected arguments; a tag that differs from the expected type gives `-32` and a count that differs from the expected count gives
  `-33`. So a reply with the wrong number of arguments is an error, never ignored. Reply header byte: `0x20` plus the request's header
  index.
- **No reply, send failure.** `0xffa82a10` retries a partial send up to 50 times (500 ticks apart; status `-26`), any other send error
  returns at once. If no reply frame arrives before the deadline (`0x2dc6c0` ticks after the send), the receive returns `-24` and the
  routine calls the node-die routine `0xffad2cb0` with progress code `0x8d` ("Critical system controller transaction failed"),
  which writes the node reset request (`0x1_0001_0000_0000` to `0x1_2000_0000`) and then returns to the caller (established for the
  call; whether the node halts afterwards is decided by that hardware write, not read). **This applies to every request below,
  including `0x100b`.** A model must reply to all of them.
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
- **Needs:** status 0 and argument count 0 (a different count only changes a status the caller drops). A reply must still arrive
  or the 3,000,000-tick wait ends in the `0x8d` die path above.
- **Repeats:** once per node object; no retries.
- **L1 handler:** `L1ReqIRouter` code `0x100b`, `0xcb474`. It checks four arguments (counting the code) and **sends no reply on success**
  (sysco: established). **Conflict, not resolved here:** the PROM code waits for a reply like any other request. Either the PROM
  runs the die path on a real L1 of this generation, or a deployed L1 answers; this repository cannot tell which. Answer it with
  status 0 and no arguments.
- **Blank L1:** same, no reply. Grade: request, arguments, reader: established; real L1 behaviour: unknown.

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
  (`F` becomes `f`, `0x66`). The module word is cached; its bits 19:6 and 5:0 are split into rack and bay by `0xffa7d1f0`.
- **Needs:** status 0, count 2, tags 0 and 0. On `F` the later type switch (`0xffa7d510`) sends the next request.
- **On error:** the wrappers return -1 and the later users get an unknown module; not fatal here.
- **Repeats:** once (cached) unless the cache is lost.
- **L1 handler:** `0xc8bb8` (sysco, established): `rack << 6 | bay` then the type character. Blank L1: 0 and the brick type (inferred `F`).
- Grade: request, reader, order: established; `F` for an Altix 350: inferred.

### 4. `0x000e` slab

- **Site:** `0xffa7cf1c`, routine `0xffa7ce90`, reached from `0xffa7d950` (cache key 4), called by `0xffa7d510` because the lowercase
  type `f` (as `l`, `b`, `{`) triggers a slab lookup.
- **Arguments:** none.
- **Reply read:** one integer (the slab). On error the routine returns -1.
- **Special effect:** if the slab is `0` or `-1`, `0xffa7d510` replaces the type with `c` (99). A one-node Altix 350 reports slab 0,
  so the type seen by the PROM becomes `c`.
- **Needs:** status 0, count 1.
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
- **Needs for one processor:** status 0; node count 1; CPU count 1; presence 1; enable 1 (bit 0 of the ANDed word is the boot
  processor; the PROM stops considering its own slice otherwise).
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

- **Site:** `0xffa7fbbc`, routine `0xffa7fab0`, from `0xffa46540` (called at `0xffa1a37c`, master only, after the "DEX POD" check).
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
15. **I/O EEPROM reads (conditional).** `0xffaad6d0` runs I/O discovery. Only if the widget identification read at
    `(nasid << 38) + 0x8000_0008_0000_0000` returns a crossbar part (`0xd000`/`0xd100`) does it reach `io_mfg_info`
    (`0xffaf1ee0`), which sends `0x0006` with device id 1 (id 98 when the cached type is `o`) and selector 2, from `0xffaecd80`
    through `0xffa85550`. On a model with no I/O widget answering, none are sent. Inferred: gating not evaluated against a model.
16. **Progress `0x26`.** If this is the partition master (flag 1 in `0x81_5003_1550`, set by the master election code), `0xffa485a0`
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
    byte `0x40 | slice` for `p`, index 4 for `r`: `0x44`), up to 127 payload bytes per frame, and arrive the same way. The PROM's own
    console init for `p` (`0xffae87f0`) only re-reads the cached type, slot and slab. Grade: established for the probes and
    framing; which console index a given phase prints on: inferred.

After `Running` the PROM loads the EFI image (`0xffaf8c50`, "Loading EFI", progress `0x27`); no further L1 request is sent before
the EFI hand-off in the code read (established for the direct calls; indirect calls through the node operations tables were not
all resolved).

## Order and replies at a glance

| Order | Code | Arguments | Reply the PROM needs | Grade |
|---|---|---|---|---|
| 0 | none (link start) | UART at `0x8000000ffed40000`, divisor 1, 8N1, FIFO `0xc7`, MCR `0x22`; state register `0x81_101d_0100` bits 41:39 = 7 | no handshake | established |
| 1 | `0x100b` | ints 1, 5, 4 | status 0, 0 args; a reply must arrive (3,000,000 ticks, else die `0x8d`) | established; real L1 reply unknown |
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
| 15 | `0x0006` (conditional) | 1 or 98, 2, offset, 64 | as 13 | inferred |
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
- The no-reply claim for `0x100b` in the L1 link page contradicts the PROM's wait.

## Unknown

- Whether the node object's identity cache survives the jump to RAM (decides whether `0x0003`, `0x000e`, `0x0013`, `0x0009` repeat).
- The value of the partition-master flag and whether I/O discovery sends EEPROM reads on a model with no I/O widget.
- What a deployed L1 does for `0x100b`.
- `0x0010` values on a blank L1.
- Indirect calls through the node operations tables between `0xffaf8c50` and the EFI jump were not all resolved.
