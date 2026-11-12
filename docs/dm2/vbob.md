# DM2 VBOB control messages

Status: **draft, not independently reviewed.** Part of the [DM2 scoping datasheet](../xio-dmediapro-dm2.md). Pipe start, field parity, the stream counter and the output-raster arithmetic are in the [pipe and timing note](pipes-timing.md).
Grades: **E** established (read in disassembly or the object's own tables), **I** inferred, **U** unknown, each with what would settle it.
Decompiler output was used for navigation only; every E below was checked against instructions or data.

## Sources

| Tag | Object | sha256 |
|---|---|---|
| L | `usr/lib32/mlmodule/libdigvid.so` (n32, release build) | `aacf8d4a64dcd34b523c4b2b7bc66153104b710171d42f7e65a588bcb95bc2ca` |
| D | `usr/lib32/mlmodule/debug/libdigvid.so` (n32, debug build) | `a6bcd5d2da2531c9191c5bec8e4c76bea8816d42f109ba4841b46fe6524fbc24` |
| K30 | `usr/cpu/sysgen/IP30boot/xtdigvid.o` | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` |
| K27 | `.../IP27boot/xtdigvid.o` | `138ab5488ed6263b14582c61cf324a79929459ba62f29f92113fed36630f38ae` |
| K35 | `.../IP35boot/xtdigvid.o` | `64c024a59b6b1dd7962af6d7857e83ff93ef29e498816b91c524a4d00fab1976` |
| C | `usr/dmedia/bin/vbob/vbob_config` (strings only) | `e6f92e2982a35f4db45d86481eaacc11762c5f10f1b4b671a78b0b4050bef7b9` |
| T | `usr/diags/ml_xtdigvid/bin/xtdigvid_confidence` (csh script) | `90a75022dcf19f964956c2765378f54ee6030ec34cae2f84d6213f7711c4f0b2` |

All under the DM2 1.1.3ml root. Addresses are L virtual addresses (release build) or K30 `.text` offsets, unless a claim says D.
The debug build D was compiled from the same sources with `-g -DDEBUG`. Its code is contiguous and its DWARF names every structure member, enum constant and many locals. L has the same data layout (E: the `.data` tables line up at a fixed offset of 0x13c40, for example the genlock source-type table at L 0x41da58 and D 0x431698) and its code is reordered, so L addresses are scattered. Names that come only from D's DWARF are marked "(D names)". The debug build also contains code the release build lacks; where that matters it is said.
K27 and K35 were checked only for the same constants (TX base 0x3800, doorbell 0x38ec, RX base 0x3880, RX release 0x38f4, timeout 250); each appears at the same shape. Their handler bodies were not read.
The LVDS fact (cables A and B at seven times the video clock) is from guide 007-4317-001 as cited in the scoping datasheet; not re-read here.
No VBOB operating code is shipped. The package carries the VBOB's 68000-family bootloader (`ucode/vbob/bootloader.bin`, version 1.1) and FPGA images. The `VERSION` file names `vbob_a.bin` and `vbob_b.bin` (1.3.21), which the update scripts flash from `vbob_ndci_a.bin` and `vbob_ndci_b.bin`; none of those is present. Everything below is therefore the host side of the protocol. What the VBOB does with a message is U unless the host's own handling shows it.

## 0. Vocabulary the library uses

**Path index** (ctx word 0x410, called "selector" in earlier drafts of this page). E, from the jack and path lookups (L 0x4114f0, 0x411540 give the SD flag; 0x411590 and 0x411620 the records) and the `*PathIndexes` words (L 0x41fa18 sdInput 3, 0x41fa1c sdGfxInput 5, 0x41fa20 sdOutput 4, 0x41fab8 hdGfxInput 2, 0x41fabc hdOutput 1):

| Index | Path | Direction | Definition |
|---|---|---|---|
| 0 | HD serial input | input | high |
| 1 | HD serial output | output | high |
| 2 | HD graphics input | input | high |
| 3 | SD serial input | input | standard |
| 4 | SD serial output | output | standard |
| 5 | SD graphics input | input | standard |

ctx byte 0x414 is "isInput", byte 0x415 "isStdDef" (1 for indices 3 to 5) and byte 0x416 "isPath" (L 0x411f80 to 0x411fb4). ctx word 0x3070c is the jack type, 0 sdInput, 1 hdInput, 2 sdOutput, 3 hdOutput, made from those bytes (L 0x411fb8 to 0x411fe4; D names `jack_types`). The two graphics inputs take video from the graphics side, not from a serial jack (record names `SDGraphicsDigitalInputJack`, `HDGraphicsDigitalInputJack`).
Other ctx fields used below (D names, offsets confirmed in L): +0x418 transfer pid, +0x420 driver fd, +0x424 "isGenlocked", +0x426 "signalPresent", +0x428 "signalPresentPosted", +0x438 path parameters (+0x444 video timing, +0x458 video height 1, +0x45c video height 2, +0x46c temporal sampling, +0x474 dominance, +0x4b0 subscribed event ids, +0x6b0 their count, +0x6c4 custom-format flag, +0x700 pipe), +0x30710 reply mailbox, +0x307e8 mailbox lock, +0x30810 mailbox condition.

**ML event ids** (D names, enum `mlMessageTypeEnum`): 0x40300 VIDEO_SEQUENCE_LOST, 0x40301 VIDEO_SYNC_GAINED, 0x40302 VIDEO_SYNC_LOST, 0x40304 VIDEO_SIGNAL_PRESENT, 0x40305 VIDEO_SIGNAL_LOST, 0x40201 DEVICE_ERROR. **Parameter ids** posted in their payloads (L `.data` parameter records, names are the library's): 0x304012 ML_VIDEO_SIGNAL_PRESENT, 0x305012 ML_VIDEO_GENLOCK_SOURCE_TIMING, 0x306012 ML_VIDEO_GENLOCK_TYPE, 0x307012 ML_VIDEO_GENLOCK_SIGNAL_PRESENT, 0xf07012 XTDIGVID_GENLOCK_STATE, 0xf08012 XTDIGVID_GENLOCK_ERROR_STATUS, 0x327013 ML_VIDEO_UST, 0x328013 ML_VIDEO_MSC.

## 1. The channel

Everything the host does with the VBOB goes through one ioctl and one event (E, all below).

**Send, ioctl `0x68647614`.** Library `xhdVbobWriteMessage` (L 0x4105f0) builds a buffer: word 0 = the command number again,
word at +8 = pipe (0 or 1), bytes +12..+35 = the 24-byte message. A variant at L 0x4106f0 is identical but ignores the result.
Kernel `xtdigvid_ioctl` (K30 0xac88) copies in 168 bytes, requires word 0 to equal the command ("ioctl cmd mismatch"),
dispatches on `cmd - 0x68647601` through a jump table (.rodata 0x1a38; entry for 0x...14 is text 0xb530), and rejects pipe >= 2.

Kernel handler, in order (K30 0xb530 to 0xc020, `out` and `in` copies for pipe 0 and 1):
1. `mutex_trylock` of the **board's** clink-ack lock, at board + 0x14728 (K30 0xb564 to 0xb58c: the base is the board pointer, not the per-pipe record at board + 0x50 + pipe * 0xa368). Failure returns errno 11 (EAGAIN) with log "clinkack lock unavailable". The lock is initialised once per board (`init_mutex` at K30 0x13dc, board + 0x14728; `init_sv` at K30 0x13a8, board + 0x14720), so both pipes share it. **This corrects the earlier reading "that pipe's lock".**
2. Writes the 24 bytes as twelve 16-bit values, byte 2k high and byte 2k+1 low, each as a 32-bit store of the zero-extended value to window offset `0x803804 + 8*k` (k = 0..11), `sync` after each.
3. Sets the board's "ack outstanding" halfword (board + 0x14738, K30 0xbba8) to 1, arms `fast_itimeout(xtdigvid_signal_clink, ..., 250 ticks)`, stores 1 to **`0x8038ec`** (send doorbell, K30 0xbbf4), `sync`, then sleeps on the board's variable (board + 0x14720, `sv_wait_sig`, K30 0xbc00).
4. Wake by ack: the status-ring service routine, on seeing status flag **bit 18 (0x40000, CLINK_XMIT_DONE)**, logs "VBOB_CLINK_ACK", clears the outstanding halfword (K30 0x3617c) and `sv_signal`s the board variable. The ioctl cancels the timer, unlocks and returns 0. Because the waiter, halfword and variable are board-wide, an XMIT_DONE flag in either pipe's ring wakes the sender (E).
5. Wake by timer with the halfword still set: the ioctl unlocks, writes 0 to `0x800074` (pipe 0) or `0x800064` (pipe 1) (the "reset sdma ring ptr" path; **E**, `movz t8,ra,t9` at K30 0xbfe4 with `t9 = pipe < 1`, `ra = 0x800064`, `t8 = 0x800074`; the [DMA part](dma.md) section 8 item 3 has the full reading), zeroes the pipe's 0x800-byte status page and ring index, returns errno 11. So the pipe word chooses only whose ring is reset after a lost ack (E).

Flag bit numbers come from the kernel's own flag-name table (.data 0x20..0x15f, value/name pairs): 18 = CLINK_XMIT_DONE, 19 = CLINK_RCV_DONE. This corrects the order in scoping section 3, which was marked inferred; the table has 20 entries with a one-letter name at index 1.

**Library side of send** (L 0x4105f0): on any failure it checks `oserror()`; if 11 it repeats the ioctl once; a second failure, or any other errno, prints "I/O ERROR communicating with VBOB: " via `perror` and returns -1.

**Receive.** Status flag bit 19 (0x80000, CLINK_RCV_DONE) in the status-ring entry (flag word at entry+4): the service routine (K30 0x35c00) reads twelve 32-bit words at **`0x803884 + 8*k`**, keeps bits 15:0 of each as bytes (high, low), stores 1 to **`0x8038f4`** (release the receive buffer), and calls `xtdigvid_post_event(pipe, 512, buf)`, where `pipe` is the pipe whose ring held the flag. Event 512 carries the 24 bytes. When that pipe's event mask lacks 512 the post routine logs "ignore clink data" and stores 1 to `0x8038f4` again. The mask is the word at pipe + 0xb50, tested with a plain AND against the event code (K30 0x10b94 to 0x10b9c) and stored by the set-mask ioctl (K30 0xcb70).
The library reads events with ioctl `0x68647605` (get event; `0x68647606` is "set event mask", `0x68647607` "flush events", named by the library's own failure strings). The event code is at byte 32 of its buffer and the 24 message bytes at 40..63, copied unswapped (L 0x40d060 is the ioctl, the copy loop is at L 0x40d254).

**Which pipe's events a library handle sees (E).** Opening a *path* (not a bare jack) opens the driver node and its pipe node `<device>p<pipe>` (pipe 0 for output paths, 1 for input paths), flushes events, sets that pipe's event mask to `0x200` (CLINK data only; L 0x40998c, 0x4099b8), and starts one event thread. The thread selects on that pipe node and reads events for that one pipe only; event 512 from that pipe goes to the parse routine (L 0x40cad0). A transfer start widens the mask to `0xfffffeff` (every event but 0x100; L 0x40c028 to 0x40c038) and every exit of the transfer narrows it back to `0x200` (the `0x7606` stores at L 0x40c244 to 0x40c5a4). A *jack* open has no pipe node and no thread, so it can send but never receives a reply.
So a library handle sees only VBOB frames that the board delivers on its own pipe's ring. Which ring the board uses for a given frame is **U**; the byte-1 rule below is what the library assumes.

**Message frame** (E from every builder in L; names are **I**). Zero-filled 24 bytes:

| Byte | Content |
|---|---|
| 0 | count of bytes that follow (last used index) |
| 1 | pipe selector: 0 output side, 1 input side |
| 2 | register id; bit 7 set = write (also set on unsolicited frames and replies, section 3) |
| 3.. | data |

**Byte 1 is the ioctl pipe word (E).** Every set builder passes the same value as byte 1 and as the ioctl pipe word: 0 for kinds 1, 2, 3, 7, 11 and 13, 1 for kind 9 (L 0x4100f0 to 0x4100f4), and the routing writer passes its `srcId` as both (L 0x40f130 to 0x40f16c). Every get goes through the transact helper, which calls the writer with **byte 1 as the pipe word** (L 0x41046c, `lbu a2,1(a1)` in the delay slot). Kind 8 sends 0; kind 10 sends 1 on an input handle and 0 on an output handle; kind 12 sends the caller's index. A byte 1 above 1 is rejected by the driver (pipe >= 2, above), so the "index" of kind 12 is a pipe number. For a get, the library's thread for that handle listens on the handle's own pipe, which equals byte 1 for every caller in L (kind 8 is issued only from output handles, kind 10's byte 1 follows the handle). So the library expects a reply on the ring of the pipe named by the request's byte 1 (**I**: this is what its threads can see, not something the library checks).
The library never reads byte 0 or byte 1 of a received frame (E: the parse routine at L 0x40cad0 reads byte 2 and bytes 3 to 7; the mailbox consumers test byte 0 != 0 and bytes 3 to 9). What byte 0 and byte 1 hold in a received frame, and whether the board puts a reply on the ring named by the request's byte 1, are **U**. Settled by: the VBOB operating code (not shipped), or a capture showing each frame's bytes and the ring that raised its CLINK_RCV_DONE.

Naming pipe 1 "input" is **E** from the driver's own "in"/"out" labels. That byte 1 selects a cable is **I**.

**Replies.** Set messages use the send path only: success is the ack interrupt, no reply frame is read. Get messages use the transact helper (L 0x4103a0, inside `xhdGetVbobInfo`):
lock two mutexes, send, then wait for the receive thread to deposit a frame in a 24-byte mailbox (ctx+0x30710), signalling a condition (ctx+0x30810). The wait is `select()` with a 3 second timeout (E for the 3; seconds by **I**). A mailbox already non-zero is taken at once. On timeout with an empty mailbox it prints "Vbob timeout......." (when errno 11) and returns -1.
**The reply is not matched to the request**: any frame that is not a notification (section 3) lands in the mailbox. Callers treat reply byte 0 == 0 as failure (E for the sync and input-signal gets).

## 2. Message kinds

Register ids are byte 2 without bit 7. "n" is byte 0. Path index names are section 0.

| # | Reg | Dir | Library function (L) | n | Body | Reply |
|---|---|---|---|---|---|---|
| 1 | 0x20 | W | `xhdSetVbobTvStandard` 0x40fb70 | 4 | [3]=1; [4]=2 if argument non-zero else 1 | ack only |
| 2 | 0x21 | W | `xhdSetVbobGenlockSrc` 0x40ff20 | 3 | [3] = one nibble, section 5 | ack only |
| 3 | 0x22 | W | `xhdSetVbobTiming` 0x40fbf0 | 18 | timing record, below | ack only |
| 4 | 0x24 | W | `xhdSetVbobRouting` 0x40f1f0, `xhdResetVbobRouting` 0x40f9f0 (generic writer 0x40f130/0x40f180) | 4 | [3]=destination port, [4]=source port, section 6 | ack only |
| 5 | 0x25 | W | same | 4 | as 0x24 | ack only |
| 6 | 0x25 | R | `xhdSetSpecialVbobRouting` 0x40f700 | 3 | [3] = route code | reply [0] != 0, [4] consumed |
| 7 | 0x26 | W | `xhdSetVbobSyncState` 0x40fdf0 | 3 | [3] = 0x80 if argument non-zero else 0 | ack only |
| 8 | 0x26 | R | `xhdGetVbobSyncState` 0x40fe70 | 2 | none | see section 4 |
| 9 | 0x27 | W | `xhdSetVbobInputSignal` 0x4100b0 | 3 | [1]=1; [3] = 0x80 if argument non-zero else 0 | ack only |
| 10 | 0x27 | R | `xhdGetVbobInputSignal` 0x410130 | 2 | [1] = (ctx byte 0x414 != 0) | see section 4 |
| 11 | 0x28 | W | `xhdSetVbobOutputDefault` 0x4101e0 | 3 | [3] = low nibble (argument != 1) \| high nibble (jack-control value != 1) | ack only |
| 12 | 0x40 | R | `xhdGetVbobInfo` 0x410320 | 2 | [1] = index argument (a pipe number, section 1) | 24 bytes returned to caller unparsed |
| 13 | 0x47 | W | `xhdReinitVbob` 0x410020 | 7 | [3..7] = ASCII "RESET" (0x52 0x45 0x53 0x45 0x54) | ack only |

Kinds 7 and 9 write registers 0xa6 and 0xa7 (bit 7 set; L 0x4100cc `li v0,167`): the host writes the same register ids that the VBOB later sends back unsolicited. The argument's 0x80 is the same bit 7 of byte 3 that the receive path tests (section 3). **I** that kind 7 enables the VBOB's sync-change notifications and kind 9 its input-signal notifications; settled by the VBOB operating code, or by observing whether frames with byte 3 bit 7 stop when the write sends 0.

**Timing record (kind 3).** Built from an 88-byte entry `td` of the library's timing table (`xthdTimingTable`, L 0x41c6d0, 30 rows; member names and offsets from the D DWARF struct `xthdTimingEntry_t`) and from the path parameters, at L 0x40fbf0 (the D build assembles the same bytes, D 0x4188c0). The row is `mlToVlTiming(path video timing)` (L 0x407680, jump table L 0x418288): the row number equals the ML number for 525, 625 and ML 9 to 16, and differs for ML 17 (row 24), 18 (25), 21 (28), 25 (20), 26 (21) and 27 (22).

| Byte | Value | Source (D names) |
|---|---|---|
| 0, 1, 2 | 0x12, 0, 0xa2 | count 18, pipe 0, register 0x22 write |
| 3 | 6 for a standard-definition timing (525 or 625), else 5 | second result of `mlToVlTiming` (L 0x407680) |
| 4, 5 | big endian | `samples_per_line` (td+0x1c) |
| 6, 7 | big endian | `width` (td+0x08), active samples per line |
| 8, 9 | big endian | `lines_per_frame` (td+0x18) |
| 10, 11 | big endian | path `videoheight1` (ctx 0x458): the selected active lines of field 1 |
| 12, 13 | `lines_per_frame` if the row is progressive (td+0x04), else `f_one_line` (td+0x24), the first line of field 2 | |
| 14, 15 | 0 if progressive, else path `videoheight2` (ctx 0x45c) | |
| 16 | `v_zero_f1` (td+0x28) minus `f_zero_line` (td+0x20): lines from the start of field 1 to its first active line | |
| 17 | `v_zero_f2` (td+0x30) minus `f_one_line` (td+0x24): the same for field 2 (0 for a progressive row, where both are -1) | |
| 18 | 4 if `sampling_rate` (td+0x38, a double) equals the constant 74.18, 5 if it equals 74.25, else 1 | |

E for every byte and member offset; the names are the library's. The clock compare is an exact double compare against the truncated 74.18 (L 0x4203a8), not 74.25/1.001, and the table carries 74.18 for every 59.94-family HD row (E). So code 4 means the 74.25/1.001 MHz pixel clock (**I**, from the rows' frame rates), 5 means 74.25 MHz, and 1 means "other": the 27 MHz standard-definition rows and the 148.5 MHz rows. With a custom format (ctx 0x6c4 non-zero) the row is ML 10 (1080 5994i) with members replaced by the result of ioctl `0x6864761f` (E, `xhdGetCustFormatDefs`, L 0x40f010).
The [pipe and timing note](pipes-timing.md) section 4 derives the frame and field period from these bytes and lists the rows.

**TV standard (kind 1).** [4]: 1 or 2 from a boolean argument (callers not traced; which standard is which is **U**).

## 3. Async frames from the VBOB

The receive parse routine (L 0x40cad0, fed from event 512) treats two register ids specially, and only when **byte 3 bit 7 is set** (E, L 0x40caf8, 0x40cb04 to 0x40cb14, 0x40cd94 to 0x40cd9c): 0xa6 and 0xa7. Everything else, including 0xa6 or 0xa7 with byte 3 bit 7 clear, goes to the mailbox (L 0x40cc80 to 0x40ccc8: lock, 24-byte copy to ctx+0x30710, signal ctx+0x30810, unlock). Since kinds 7 and 9 write 0xa6 and 0xa7, **I** that a reply to a read of 0x26 or 0x27 is also framed with byte 2 = 0xa6 or 0xa7 and byte 3 bit 7 clear, and that bit 7 is what separates a notification from a reply. Settled by a capture of a reply.

**Bytes 0 and 1 of 0xa6 and 0xa7 frames: U.** The library never reads them (section 1). The only constraint it places on where such a frame arrives is indirect and **I**: a 0xa6 notification is acted on only by a handle whose pipe is 0 (E: ctx word 0x700 must be zero, L 0x40cda4 to 0x40cda8), so the library expects genlock notifications on the output pipe's ring; a 0xa7 notification is meaningful only to an input path (index 0 or 3, below), whose pipe is 1, so it expects those on the input pipe's ring. Settled by a capture showing which ring raises CLINK_RCV_DONE for each frame.

- **0xa6, byte 3 bit 7 (genlock sync change).** Acted on only by a pipe-0 handle, and ignored if the handle's genlock source (`getJackParam(ctx, 0)`, section 5) is INTERNAL (3). Otherwise the sync-change handler runs (L 0x40c5d0; D names `handleGenlockState`):
  - path index 4 (SD output): detected timing = `vbobToMLtiming(byte 5)`, locked = byte 3 bit 0;
  - path index 1 (HD output): detected timing = `vbobToMLtiming(byte 4)`, locked = byte 3 bit 1;
  - any other index: nothing is posted.
  Locked sets the handle's lock mark (ctx 0x424) to 1. Not locked sets it to 0 and picks an error status (section 4). It then scans the subscribed events once (L 0x40c640 to 0x40c728): if 0x40302 (SYNC_LOST) is subscribed, a transfer is running (ctx 0x418 not -1) and the mark is 0, it posts 0x40302 with payloads 0x307012 (the detected ML timing) and 0xf08012 (the error status); otherwise if 0x40301 (SYNC_GAINED) is subscribed and the mark is 1, it posts 0x40301 with the same two payloads (status 0) and increments the mark to 2, so a lock is reported once. E for all of this (the payload ids are the immediates `lui 0x30; ori 0x7012` and `lui 0xf0; ori 0x8012` at L 0x40c66c to 0x40c688 and 0x40c6fc to 0x40c714).
- **0xa7, byte 3 bit 7 (input signal change).** Path index 3 (SD input) reads byte 6, or byte 7 when `_XTDIGVID_SWAP_LINKS` is set; path index 0 (HD input) reads byte 4, or byte 5 with that variable. It converts with `vbobToMLtiming` and compares with the path's video timing (ctx 0x444): equal, or the path timing is ML 21 (1080 25PsF) and the signal ML 23, means "signal present" (ctx 0x426 = 1). ML 23 is not in `vbobToMLtiming`'s range (E: its outputs are 0, 1, 2, 3, 9 to 18, 25, 26, 27), so that clause can never be true; **I** that it is a slip for ML 11 (1080 50i), which is what the HD output check uses (section 4). A custom-format path accepts any detected timing other than NONE. A change is posted as 0x40304 (SIGNAL_PRESENT) or 0x40305 (SIGNAL_LOST) with payload 0x304012 and the detected timing (L 0x40cb1c to 0x40cd54, posts at 0x40cc2c to 0x40cd40). For path indices 1, 2, 4 and 5 the compare value is read from an uninitialised stack slot (L 0x40cb34); the library does not guard it, so these frames are only meaningful to an input handle (E for the missing initialisation, I for the consequence).
- The kernel's receive path logs a different line when byte 2 is 0xa7 but otherwise treats all frames alike.

## 4. Replies and status

Timing code table (E, `vbobToMLtiming`, L 0x4077c0, jump table L 0x418330). Wire code to ML timing numeric. The VBOB-side names are the constants of the D DWARF enum `VBOB_PROTOCOL_SYNC_STATE_SYNC_TYPE_t` (E for the names; the library maps by number):

| Wire | VBOB name | ML | Wire | VBOB name | ML |
|---|---|---|---|---|---|
| 0 | INTERNAL | 1 UNKNOWN | 9 | HD1080p2997 | 13 1080 2997p |
| 1 | NOT_PRESENT | 0 NONE | 10 | HD1080p30 | 12 1080 30p |
| 2 | UNKNOWN | 1 UNKNOWN | 11 | HD1080p2398 | 16 1080 2398p |
| 3 | NTSC | 2 525 | 12 | HD1080p24 | 15 1080 24p |
| 4 | PAL | 3 625 | 13 | HD1080i4795 | 18 1080 2398PsF |
| 5 | HD720p5994 | 27 720 5994p | 14 | HD1080i48 | 17 1080 24PsF |
| 6 | HD720p60 | 26 720 60p | 15 | HD1080p25 | 14 1080 25p |
| 7 | HD1080i5994 | 10 1080 5994i | 16 | HD1080i50 | 11 1080 50i |
| 8 | HD1080i60 | 9 1080 60i | 17 | HD1035i5994 | 25 1035 5994i |

Codes 18 (MAX) and above map to UNKNOWN. No wire code maps to 1080 25PsF (ML 21), though it is a selectable source timing; the library treats a 50i detection as satisfying a 25PsF request (below). Wire codes 9 and 10 map to timings the library never offers in its own genlock enums (E); **I** that they are reported-only. The names "i4795" and "i48" show the VBOB reports a segmented-frame 23.98 or 24 Hz signal as an interlaced one at twice the rate (E for the names, I for the reading).

**Sync-state reply (kind 8).** Byte 3 holds one lock bit and one illegal-combination bit per genlock side, SD low and HD above: bit 0 SD locked, bit 1 HD locked, bit 2 SD illegal combination, bit 3 HD illegal combination (E for the four tests: bits 0 and 1 in the sync-change handler and the start-transfer check, bits 2 and 3 in `getSyncErrorStatus` at L 0x40ce60; the names are **I**). Bytes 4 and 5 are the detected-timing codes of the HD and SD genlock detectors (E: HD output, path index 1, reads byte 4; SD output, index 4, reads byte 5; L 0x40c730 to 0x40c78c). The library's `XTDIGVID_GENLOCK_STATE` getter (L 0x414cb8 to 0x414e74; D names `ddGetControls`) tests **bit 0 for both** path indices 1 and 4, while the notification handler and the start-transfer check test bit 1 for the HD side (E for both readings). **I** that the getter is a copy-and-paste defect, so an HD output handle reads the SD lock bit there. `ddGetControls` returns an error for any other path index.
- Error status for `XTDIGVID_GENLOCK_ERROR_STATUS` = `getSyncErrorStatus(which, byte3, ML timing)` (L 0x40ce60; `which` 1 for the SD side, 0 for the HD side): ML NONE gives NO_SIGNAL (1); ML UNKNOWN gives UNKNOWN_SIGNAL (2); otherwise ILLEGAL_COMBINATION (3) if byte 3 bit 2 is set (SD) or bit 3 (HD), else NONE (0).
- **TIMING_MISMATCH (4) comes from the notification handler and the start-transfer check, not from `getSyncErrorStatus`.** When the VBOB reports lock but the handle's reference timing (`ML_VIDEO_GENLOCK_SOURCE_TIMING`) is neither AUTODETECT (0x400) nor equal to the detected timing, they set status 4 (L 0x40c7e8 to 0x40c7f0, `li a6,4; sw a6,4(sp)`; D 0x411ff0). One exception: an HD handle that asks for ML 21 (1080 25PsF) is satisfied by a detected ML 11 (1080 50i). The earlier draft's "not produced here (U)" is withdrawn.

**Input-signal reply (kind 10).** Six detected-timing codes at bytes 4 to 9 (E). `xhdGetGenlockSignal` (L 0x40ee90) picks one per (path index, genlock source from `getJackParam(ctx,0)`, library enum JACK_A 0, JACK_B 1, ANALOG 2):

| Path index | JACK_A | JACK_B | ANALOG |
|---|---|---|---|
| 1 (HD output) | byte 4 | byte 5 | byte 8 |
| 4 (SD output) | byte 6 | byte 7 | byte 9 |

Any other pair returns status 4 (E, L 0x40ee90 and D 0x4170c0). An earlier draft printed "4 -> [5]" in the HD column; the source value is JACK_B = 1. The input paths' own notifications use the same slots: HD input byte 4 or 5, SD input byte 6 or 7 (section 3). So the six slots are [4] and [5] the HD-side detector on digital input A and B, [6] and [7] the SD-side detector on A and B, [8] the HD-side and [9] the SD-side analog reference detector. E for how the library assigns slots; reading them as per-side detectors is **I**.

**Special-routing reply (kind 6).** Byte 0 non-zero required; byte 4 is stored into the library's route state (ctx words 0x0c or 0x10 by mode) and used on the next call (E, L 0x40f910).

**Info reply (kind 12).** Returned raw; no library path parses it (E that `xhdGetVbobInfo` has no internal caller in L). Content is **U**, settled by `vbob_config` or `vbob_flash` if they call it (`vbob_config` carries its own copy of the transport with `vbobReadData`/`vbobWriteData`; not disassembled).

## 5. Genlock reference per source

The reference is chosen per *output jack type*, with two library parameters on the output jacks only. The input jacks carry only loopback and reinit (E: the parameter-record lists at L 0x41f6c8 sdInput, 0x41f6d0 sdOutput, 0x41f6f0 hdInput, 0x41f6f8 hdOutput):

| Parameter | SD output jack | HD output jack |
|---|---|---|
| `ML_VIDEO_GENLOCK_TYPE_INT32` (0x306012) | record L 0x41db00, shared | record L 0x41db00, shared |
| `ML_VIDEO_GENLOCK_SOURCE_TIMING_INT32` (0x305012) | record L 0x41dfc8: AUTODETECT, 525, 625 | record L 0x41dd20: AUTODETECT, 525, 625, 1080 60i, 5994i, 50i, 25p, 24p, 2398p, 1035 5994i, 24PsF, 2398PsF, 25PsF, 720 60p, 5994p |

Type enum (E, L 0x41da58, names at 0x41db00): JACK_A = 0, JACK_B = 1, ANALOG = 2, INTERNAL = 3 (`XTDIGVID_GENLOCK_SRC_TYPE_DIGITAL_JACK_A`, `_B`, `_ANALOG`, `_INTERNAL`). Wire code (E, L 0x40ff58): INTERNAL = 0, JACK_A = 1, JACK_B = 2, ANALOG = 3; an unknown value prints "Unknown genlock source type: %d (assuming internal)" and sends 0. The source and timing live in the per-jack-type control block (D names `xtdigvid_jack_controls_t`: `genlock_timing` at +0x20, `genlock_source` at +0x24); `getJackParam(ctx, 0)` returns the source and `getJackParam(ctx, 1)` the timing (L 0x412b4c to 0x412bb4).

**Nibbles (kind 2), E.** The library sends the wire code as `8 | code` in **one nibble of byte 3 per message**: the high nibble when the handle's `isStdDef` byte (ctx 0x415) is 0, the low nibble when it is 1. The caller passes that byte as the builder's third argument (L 0x412dd0 to 0x412dd4; builder L 0x40ff20, D 0x418e30). So the **high nibble is the HD side's source and the low nibble the SD side's**. The other nibble is 0 and the message does not read-modify-write, so one message names one side only. Bit 3 of a sent nibble is always set and an untouched nibble is 0, so **I** that bit 3 is a "this nibble is valid" marker and a 0 nibble means "leave unchanged"; settled by the VBOB operating code, or a capture where an HD call leaves an earlier SD source in force.
Around the send (E, D 0x41dc70 and L 0x412bc0 to 0x412e6c; D names `processJackControls`): the message goes out only when the requested source differs from the current one; after success the library sets the control block's "genlock source updated" flag and stores the block through ioctl `0x68647619`; on failure it prints "Error setting Genlock Source %d" and returns 1000.

**Reference check at transfer start (output pipe only), E.** If the handle's source is not INTERNAL and its lock mark is 0, `xhdDoTransfer` reads the sync state (kind 8) and runs the sync-change evaluation (D 0x411ff0): lock bit clear leaves it unlocked with the status from `getSyncErrorStatus`; lock bit set with timing AUTODETECT or a matching timing marks it locked; lock bit set with another timing is TIMING_MISMATCH and unlocked. An unlocked result aborts the start with "Failed to genlock at start transfer" (a string of L). With source INTERNAL the check is skipped. L has the same flow (the output branch of `xhdDoTransfer` from 0x40bff8).
The H and V phase of the output against the reference are separate output-jack parameters (0x338012, 0x339012) that program the output formatter's resync registers (`xhdProgramHdocResyncRegs`, L 0x4092c0); outside this page.

## 6. VBOB ports, routing and jacks

**Routing writes (kinds 4 and 5), E.** `xhdSetVbobRouting` (L 0x40f1f0) sends two messages per call, with the register chosen by direction: **0x24 for input paths (pipe 1) and 0x25 for output paths (pipe 0)**. Each message sets one crosspoint: byte 3 is the destination port code and byte 4 the source port code (the generic writer takes `(fd, pipe, reg, from, to)` and stores `to` in byte 3 and `from` in byte 4, L 0x40f140 to 0x40f148; `from` and `to` are D's names for the `_setRouting` arguments). The codes per path index (E, L 0x40f1f0 to 0x40f6f8, D 0x417790):

| Path index | Messages (source to destination) | Register |
|---|---|---|
| 0 HD input | 1 to 5, 2 to 6 | 0x24 |
| 2 HD graphics input | 7 to 5, 8 to 6 | 0x24 |
| 3 SD input | 3 to 5, 4 to 6 | 0x24 |
| 5 SD graphics input | 7 to 5, 8 to 6 | 0x24 |
| 1 HD output | 5 to 1, 6 to 2 | 0x25 |
| 4 SD output | 5 to 3, 6 to 4 | 0x25 |

Three environment variables change this (E strings at L 0x41aab0, 0x41aae8, 0x41ab20; each prints a notice). `_XTDIGVID_TEST_INPUT` makes the HD input and both graphics inputs use source 9 for both messages, and the SD input source 10. `_XTDIGVID_SWAP_LINKS` exchanges the two source codes of an input route, or the two destination codes of an output route. `_XTDIGVID_TEST_OUTPUT` (read only when ctx word 0x440 equals 0x4220) makes the second output message use source 5 again. After an input route's second message (destination 6) the library sleeps 350 ms. Normal operation uses none of them (I).
Port codes, **I**: 1 and 2 are the two HD serial jacks, 3 and 4 the two SD serial jacks, 5 and 6 the two links to the DM2 board (the two LVDS cables), 7 and 8 the graphics-side feeds, 9 and 10 internal test sources. The assignment follows the route table by symmetry (every HD serial path touches 1 and 2, every SD serial path 3 and 4, every input or output 5 and 6) and the shipped confidence test below; no shipped code names a code's jack. Settled by the VBOB operating code, or the guide's cabling table.

**Physical jacks.** E from the shipped diagnostic script T (lines 357 to 367): the LVDS connectors are labelled P1 and P2 on the board and on the VBOB, and the VBOB has coax jacks labelled "HD out 1", "HD out 2", "HD in 1", "HD in 2", "SD out 1", "SD out 2", "SD in 1" and "SD in 2"; the test loops each output to the input with the same number. The library's "digital jack A" and "digital jack B" are therefore the numbers 1 and 2 of the handle's definition (**I**: the library never names a connector; HD input byte 4 versus 5 and SD input byte 6 versus 7 are the A and B detector slots, and the swap variable exchanges them). The analog genlock reference has no coax label in any shipped text (U; the guide).
Jack records (E, L 0x41fa28 to 0x41fb20; type 2 serial, 12 graphics): `HDSerialDigitalInputJack` 0, `HDSerialDigitalOutputJack` 1, `HDGraphicsDigitalInputJack` 2, `SDSerialDigitalInputJack` 3, `SDSerialDigitalOutputJack` 4, `SDGraphicsDigitalInputJack` 5.

**Is "525 and 625 only on the HD genlock input" a rule?** Not in anything shipped. The library's tables carry the opposite constraint. The **SD** output jack's reference-timing list has only AUTODETECT, 525 and 625, and its detected-timing list only NONE, UNKNOWN, 525, 625 (E, L 0x41df78 and 0x41e000). The **HD** output jack's lists contain 525 and 625 *and* every HD timing (E, L 0x41db38 and 0x41dd58). So 525 and 625 are valid references on both genlock sides, and the HD formats only on the HD side. The library hands these lists to the media library's message validator (`mlDIvalidateMsg`, imported; **I** that it enforces them). Apart from those lists and the per-path timing lists (SD paths accept only ML 525 and 625, HD paths the twelve HD rows; E, D `sdVideoTiming`, `hdVideoTiming`), no code in `libdigvid.so` or `xtdigvid.o` tests a timing against a jack or a side. Whether the VBOB itself takes 525 or 625 on only one of its two genlock detectors, or flags ILLEGAL_COMBINATION (byte 3 bits 2 and 3) for it, is **U**; settled by the VBOB operating code or the guide's genlock table. If the statement means "an HD handle can lock to an SD reference", the library allows it. If it means "an SD handle cannot use 525 or 625 as genlock", the library does not forbid that either.

## 7. What a peer on the VBOB side has to supply (host-visible contract)

All **E** unless noted.
1. Accept the TX register file (12 halfwords at 0x803804 + 8k) and doorbell (0x8038ec = 1); raise a CLINK_XMIT_DONE status flag on either pipe's ring within 250 clock ticks (about 2.5 s if HZ is 100, **I**) of each doorbell. Only one send is outstanding at a time (board-wide lock, section 1). Whether the real ack comes from the board's CLINK transmitter or from the VBOB itself is **U**; settled by a capture with the VBOB disconnected, or the CLINK FPGA netlist.
2. For get messages (kinds 6, 8, 10, 12), place a 24-byte frame in the RX register file (12 halfwords at 0x803884 + 8k), set CLINK_RCV_DONE on the ring of a pipe that has an open path whose mask includes 512, and wait for the host's store of 1 to 0x8038f4 before the next frame (the latter by **I**). Reply byte 0 must be non-zero. The library waits 3 seconds. Any frame answers any outstanding get, so unrequested frames can corrupt a get in flight. A frame on a pipe with no open path is released and dropped.
3. Frames with byte 2 = 0xa6 or 0xa7 and byte 3 bit 7 set are notifications and are consumed by the receive thread, never by a waiting get; 0xa6 only from a pipe-0 handle's thread, 0xa7 only meaningfully from an input path's (section 3).
4. Set messages need only the ack; the host never reads back a set (except through the matching get).
5. Retry behaviour: the host retries one send once on timeout, so a missing ack costs about two timeouts before the failure is printed.

## 8. Not read

- `vbob_flash`, `vbob_update1/2`, bootloader S-records: the flash and boot protocol over the same ioctl.
- `ddSetControls` callers of kinds 1, 7, 9: which ML control drives which message, and the argument meanings.
- The special-routing selector table for kind 6 (`xhdSetSpecialVbobRouting` was read for its reply handling only).
- K27 and K35 handler bodies (constants only).
