# DM2 VBOB control messages

Status: **draft, not independently reviewed.** Part of the [DM2 scoping datasheet](../xio-dmediapro-dm2.md).
Grades: **E** established (read in disassembly or the object's own tables), **I** inferred, **U** unknown, each with what would settle it.
Decompiler output was used for navigation only.

## Sources

| Tag | Object | sha256 |
|---|---|---|
| L | `usr/lib32/mlmodule/libdigvid.so` (n32, dynsym only) | `aacf8d4a64dcd34b523c4b2b7bc66153104b710171d42f7e65a588bcb95bc2ca` |
| K30 | `usr/cpu/sysgen/IP30boot/xtdigvid.o` | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` |
| K27 | `.../IP27boot/xtdigvid.o` | `138ab5488ed6263b14582c61cf324a79929459ba62f29f92113fed36630f38ae` |
| K35 | `.../IP35boot/xtdigvid.o` | `64c024a59b6b1dd7962af6d7857e83ff93ef29e498816b91c524a4d00fab1976` |
| C | `usr/dmedia/bin/vbob/vbob_config` (strings only) | `e6f92e2982a35f4db45d86481eaacc11762c5f10f1b4b671a78b0b4050bef7b9` |

All under the DM2 1.1.3ml root. Addresses are L virtual addresses or K30 `.text` offsets. K27 and K35 were
checked only for the same constants (TX base 0x3800, doorbell 0x38ec, RX base 0x3880, RX release 0x38f4, timeout 250); each appears at
the same shape. Their handler bodies were not read.
The LVDS fact (cables A and B at seven times the video clock) is from guide 007-4317-001 as cited in the scoping datasheet; not re-read here.

## 1. The channel

Everything the host does with the VBOB goes through one ioctl and one event (E, all below).

**Send, ioctl `0x68647614`.** Library `xhdVbobWriteMessage` (L 0x4105f0) builds a buffer: word 0 = the command number again,
word at +8 = pipe (0 or 1), bytes +12..+35 = the 24-byte message. A variant at L 0x4106f0 is identical but ignores the result.
Kernel `xtdigvid_ioctl` (K30 0xac88) copies in 168 bytes, requires word 0 to equal the command ("ioctl cmd mismatch"),
dispatches on `cmd - 0x68647601` through a jump table (.rodata 0x1a38; entry for 0x...14 is text 0xb530), and rejects pipe >= 2.

Kernel handler, in order (K30 0xb530 to 0xc020, `out` and `in` copies for pipe 0 and 1):
1. `mutex_trylock` of that pipe's clink-ack lock. Failure returns errno 11 (EAGAIN) with log "clinkack lock unavailable".
2. Writes the 24 bytes as twelve 16-bit values, byte 2k high and byte 2k+1 low, each as a 32-bit store of the zero-extended value to window offset `0x803804 + 8*k` (k = 0..11), `sync` after each.
3. Sets the pipe's "ack outstanding" halfword to 1, arms `fast_itimeout(xtdigvid_signal_clink, ..., 250 ticks)`, stores 1 to **`0x8038ec`** (send doorbell), `sync`, then sleeps (`sv_wait_sig`).
4. Wake by ack: the status-ring service routine, on seeing status flag **bit 18 (0x40000, CLINK_XMIT_DONE)**, logs "VBOB_CLINK_ACK", clears the outstanding halfword and `sv_signal`s. The ioctl cancels the timer, unlocks and returns 0.
5. Wake by timer with the halfword still set: the ioctl unlocks, writes 0 to `0x800064` (pipe 0) or `0x800074` (pipe 1) (the "reset sdma ring ptr" path), zeroes the pipe's 0x800-byte status page and ring index, returns errno 11.

Flag bit numbers come from the kernel's own flag-name table (.data 0x20..0x15f, value/name pairs): 18 = CLINK_XMIT_DONE, 19 = CLINK_RCV_DONE. This corrects the order in scoping section 3, which was marked inferred; the table has 20 entries with a one-letter name at index 1.

**Library side of send** (L 0x4105f0): on any failure it checks `oserror()`; if 11 it repeats the ioctl once; a second failure, or any other errno, prints "I/O ERROR communicating with VBOB: " via `perror` and returns -1.

**Receive.** Status flag bit 19 (0x80000, CLINK_RCV_DONE) in the status-ring entry (flag word at entry+4): the service routine (K30 0x35c00) reads twelve 32-bit words at **`0x803884 + 8*k`**, keeps bits 15:0 of each as bytes (high, low), stores 1 to **`0x8038f4`** (release the receive buffer), and calls `xtdigvid_post_event(pipe, 512, buf)`. Event 512 carries the 24 bytes. When the event mask lacks 512 the post routine logs "ignore clink data" and stores 1 to `0x8038f4` again. The library reads it with ioctl `0x68647605` (get event; kernel table entry 0x68647606 is "set event mask"); the event code is at byte 32 of its buffer, the 24 message bytes at 40..63 and are copied unswapped (L 0x40d254, a two-byte copy loop; I first misread it as a swap).
Which pipe's ring carries an RX flag is **U**; both rings run the same code. Settled by: reading `xtdigvid_xg_intr_handler`'s callers for the flag-to-ring routing, or a capture.

**Message frame** (E from every builder in L; names are **I**). Zero-filled 24 bytes:

| Byte | Content |
|---|---|
| 0 | count of bytes that follow (last used index) |
| 1 | pipe: 0 output (cable A, transmit), 1 input (cable B, receive). Equals the ioctl pipe word in every caller |
| 2 | register id; bit 7 set = write |
| 3.. | data |

Naming pipe 1 "input" is **E** from the driver's own "in"/"out" labels. That byte 1 selects a cable is **I**.

**Replies.** Set messages use the send path only: success is the ack interrupt, no reply frame is read. Get messages use the transact helper (L 0x4103a0, inside `xhdGetVbobInfo`):
lock two mutexes, send, then wait for the receive thread to deposit a frame in a 24-byte mailbox (ctx+0x30710), signalling a condition (ctx+0x30810). The wait is `select()` with a 3 second timeout (E for the 3; seconds by **I**). A mailbox already non-zero is taken at once. On timeout with an empty mailbox it prints "Vbob timeout......." (when errno 11) and returns -1.
**The reply is not matched to the request**: any frame lands in the mailbox. Exceptions are the two async forms in section 3, which never reach the mailbox. Callers treat reply byte 0 == 0 as failure (E for the sync and input-signal gets).

## 2. Message kinds

Register ids are byte 2 without bit 7. "n" is byte 0.

| # | Reg | Dir | Library function (L) | n | Body | Reply |
|---|---|---|---|---|---|---|
| 1 | 0x20 | W | `xhdSetVbobTvStandard` 0x40fb70 | 4 | [3]=1; [4]=2 if argument non-zero else 1 | ack only |
| 2 | 0x21 | W | `xhdSetVbobGenlockSrc` 0x40ff20 | 3 | [3] = nibble pair, see below | ack only |
| 3 | 0x22 | W | `xhdSetVbobTiming` 0x40fbf0 | 18 | timing record, below | ack only |
| 4 | 0x24 | W | `xhdSetVbobRouting` 0x40f1f0, `xhdResetVbobRouting` 0x40f9f0 (generic writer 0x40f130/0x40f180) | 4 | [3]=a, [4]=b routing codes 1..10 | ack only |
| 5 | 0x25 | W | same | 4 | as 0x24 | ack only |
| 6 | 0x25 | R | `xhdSetSpecialVbobRouting` 0x40f700 | 3 | [3] = route code | reply [0] != 0, [4] consumed |
| 7 | 0x26 | W | `xhdSetVbobSyncState` 0x40fdf0 | 3 | [3] = 0x80 if argument non-zero else 0 | ack only |
| 8 | 0x26 | R | `xhdGetVbobSyncState` 0x40fe70 | 2 | none | see section 4 |
| 9 | 0x27 | W | `xhdSetVbobInputSignal` 0x4100b0 | 3 | [1]=1; [3] = 0x80 if argument non-zero else 0 | ack only |
| 10 | 0x27 | R | `xhdGetVbobInputSignal` 0x410130 | 2 | [1] = (ctx byte 0x414 != 0) | see section 4 |
| 11 | 0x28 | W | `xhdSetVbobOutputDefault` 0x4101e0 | 3 | [3] = low nibble (argument != 1) \| high nibble (jack-control value != 1) | ack only |
| 12 | 0x40 | R | `xhdGetVbobInfo` 0x410320 | 2 | [1] = index argument | 24 bytes returned to caller unparsed |
| 13 | 0x47 | W | `xhdReinitVbob` 0x410020 | 7 | [3..7] = ASCII "RESET" (0x52 0x45 0x53 0x45 0x54) | ack only |

Routing reg: pipe 1 uses 0x24, pipe 0 uses 0x25 (E, `xhdSetVbobRouting` 0x40f3a0 and `xhdResetVbobRouting`). Codes seen in [3],[4] across the six selector values (ctx word 0x410, 0..5) are 1 to 10; 9 and 10 appear on the test-variable and reset paths. The per-selector table sits in eight code paths and was not tabulated. Meaning of any route code is **U**; settled by the VBOB firmware or the guide's cabling table.
Environment variables read: `_XTDIGVID_TEST_INPUT`, `_XTDIGVID_SWAP_LINKS`, `_XTDIGVID_TEST_OUTPUT` (E strings at L 0x41aab0, 0x41aae8, 0x41ab20); each alters routing codes or which reply byte is used. Not needed for normal operation (I).

**Genlock source (kind 2).** Library enum (E, L 0x41da58): JACK_A=0, JACK_B=1, ANALOG=2, INTERNAL=3. Wire code (E, 0x40ff58): INTERNAL=0, JACK_A=1, JACK_B=2, ANALOG=3. Byte [3] holds `8|code` in the high nibble when the second argument is 0, in the low nibble when non-zero; a second call for the other nibble is a separate message that overwrites the whole byte (E: it does not read-modify-write). Which nibble belongs to which pipe or format family is **U**; settled by the library's callers of 0x40ff20 in `ddSetControls` (not traced).
Unknown source values print "Unknown genlock source type: %d (assuming internal)" and send 0.

**Timing record (kind 3).** Built from an 88-byte timing definition `td` (words) and context words. E for the bytes, **I** for meaning:

| Byte | Value |
|---|---|
| 3 | 6 if the timing is SD (525 or 625), else 5 (from `mlToVlTiming` flag, L 0x407680) |
| 4,5 | td[7] big endian |
| 6,7 | td[2] big endian |
| 8,9 | td[6] big endian |
| 10,11 | ctx word 0x458 big endian |
| 12,13 | td[6] if td[1] != 0, else td[9] |
| 14,15 | 0 if td[1] != 0, else ctx word 0x45c |
| 16 | td[10] - td[8] |
| 17 | td[12] - td[9] |
| 18 | 4 if pixel clock (double at td+0x38) == 74.18, 5 if == 74.25, else 1 (constants at L 0x4203a8, 0x4203a0) |

The clock test is an exact double compare against the truncated 74.18, not 74.25/1.001 (E). Field names for td are **U**.

**TV standard (kind 1).** [4]: 1 or 2 from a boolean argument (callers not traced; which standard is which is **U**).

## 3. Async frames from the VBOB

The receive thread (L 0x40cad0, fed from event 512 at L 0x40d254) treats two frames specially: register byte (byte 2) equal to `0xa6` or `0xa7` with **byte 3 bit 7 set** (E, 0x40caf8 and 0x40cb0c). Everything else goes to the mailbox.

- **0xa6, byte 3 bit 7 (sync change).** Ignored if ctx word 0x700 is non-zero or `getJackParam(ctx,0)` returns 3. Otherwise L 0x40c5d0 runs: for selector 4 it converts byte 5 with `vbobToMLtiming`, tests byte 3 bit 0; for selector 1 it converts byte 4 and tests byte 3 bit 1. Bit set: it posts a sync-regained style event; bit clear: it calls `getSyncErrorStatus` (L 0x40ce60) and posts the loss. Event posting uses `mlDIQueueReturnEvent`. The exact event ids (0x304012, 0x307012, 0x30...) were not decoded to names. **I** that bit set = signal good, bit clear = lost.
- **0xa7, byte 3 bit 7 (input signal change).** Selector 3 uses byte 7 (with `_XTDIGVID_SWAP_LINKS`) or 6; selector 0 uses byte 5 or 4; converts with `vbobToMLtiming`, compares to the stored input timing, posts an input-changed event if different (L 0x40cb1c to 0x40cd54, partly traced).

The kernel's receive path logs a different line when byte 2 is 0xa7 but otherwise treats all frames alike.

## 4. Replies and status

Timing code table (E, `vbobToMLtiming`, L 0x4077c0, jump table L 0x418330). Wire code to ML timing numeric (names from `mlvideo.h` and the library's own enum arrays at 0x41dd58):

| Wire | ML | Wire | ML |
|---|---|---|---|
| 0 | 1 UNKNOWN | 9 | 13 1080 2997p |
| 1 | 0 NONE | 10 | 12 1080 30p |
| 2 | 1 UNKNOWN | 11 | 16 1080 2398p |
| 3 | 2 525 | 12 | 15 1080 24p |
| 4 | 3 625 | 13 | 18 1080 2398PsF |
| 5 | 27 720 5994p | 14 | 17 1080 24PsF |
| 6 | 26 720 60p | 15 | 14 1080 25p |
| 7 | 10 1080 5994i | 16 | 11 1080 50i |
| 8 | 9 1080 60i | 17 | 25 1035 5994i |

Codes 18 and above map to UNKNOWN. No wire code maps to 1080 25PsF (ML 21), though it is a selectable source timing. Wire codes 9 and 10 map to timings the library never offers in its own genlock enums (E); **I** that they are reported-only.

**Sync-state reply (kind 8).** Consumers (L 0x414cb8 to 0x414e74, `ddGetControls`):
- Byte 3 bit 0 = genlock LOCKED (1) or UNLOCKED (0) for selectors 1 and 4 (E); other selectors return an error (`XTDIGVID_GENLOCK_STATE` is only defined for 1 and 4).
- Detected timing code: byte 4 for selector 1 (and 0), byte 5 for 4, byte 6 for 3 (E).
- Error status for `XTDIGVID_GENLOCK_ERROR_STATUS` = `getSyncErrorStatus(which, byte3, ML timing)`: ML NONE gives NO_SIGNAL (1); ML UNKNOWN gives UNKNOWN_SIGNAL (2); otherwise ILLEGAL_COMBINATION (3) if byte 3 bit 3 is set (which = 0) or bit 2 is set (which = 1), else NONE (0). TIMING_MISMATCH (4) is not produced here (E from L 0x40ce60; the mismatch source was not traced, **U**).

**Input-signal reply (kind 10).** Six detected-timing codes at bytes 4..9 (E). `xhdGetGenlockSignal` (L 0x40ee90) picks one per (selector, `getJackParam(ctx,0)`): selector 1: jack 0 -> [4], 4 -> [5], 2 -> [8]; selector 4: jack 0 -> [6], 1 -> [7], 2 -> [9]; any other pair returns status 4. Physical meaning of the six slots is **U** (guide cabling table or the VBOB's own firmware).

**Special-routing reply (kind 6).** Byte 0 non-zero required; byte 4 is stored into the library's route state (ctx words 0x0c or 0x10 by mode) and used on the next call (E, L 0x40f910).

**Info reply (kind 12).** Returned raw; no library path parses it (E that `xhdGetVbobInfo` has no internal caller in L). Content is **U**, settled by `vbob_config` or `vbob_flash` if they call it (`vbob_config` carries its own copy of the transport with `vbobReadData`/`vbobWriteData`; not disassembled).

## 5. What a peer on the VBOB side has to supply (host-visible contract)

All **E** unless noted.
1. Accept the TX register file (12 halfwords at 0x803804 + 8k) and doorbell (0x8038ec = 1); raise the per-pipe CLINK_XMIT_DONE status flag within 250 clock ticks (about 2.5 s if HZ is 100, **I**) of each doorbell, for the pipe named in the ioctl. Whether the real ack comes from the board's CLINK transmitter or from the VBOB itself is **U**; settled by a capture with the VBOB disconnected, or the CLINK FPGA netlist.
2. For get messages (kinds 6, 8, 10, 12), place a 24-byte frame in the RX register file (12 halfwords at 0x803884 + 8k), set CLINK_RCV_DONE, and wait for the host's store of 1 to 0x8038f4 before the next frame (the latter by **I**). Reply byte 0 must be non-zero. The library waits 3 seconds. Any frame answers any outstanding get, so unrequested frames can corrupt a get in flight.
3. Frames with byte 2 = 0xa6 or 0xa7 and byte 3 bit 7 set are notifications and are consumed by the receive thread, never by a waiting get.
4. Set messages need only the ack; the host never reads back a set (except through the matching get).
5. Retry behaviour: the host retries one send once on timeout, so a missing ack costs about two timeouts before the failure is printed.

## 6. Not read

- `vbob_flash`, `vbob_update1/2`, bootloader S-records: the flash and boot protocol over the same ioctl.
- `ddSetControls` callers of kinds 1, 2, 7, 9, 11: which ML control drives which message, and the argument meanings.
- Full route-code table for kinds 4 and 5, and the test-environment variants.
- Event ids posted by the async handlers.
- K27 and K35 handler bodies (constants only).
