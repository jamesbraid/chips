# DM2 video interrupts and the status ring

Status: **draft, not independently reviewed.** Part of the [DM2 scoping datasheet](README.md).
Grades: **E** established (the cited instructions were read), **I** inferred (reasoning given), **U** unknown (what would settle it given).
Decompiler output was not used. Every address is a `.text` offset in the IP30 object unless a column says otherwise.

## Sources

| Tag | Object | sha256 |
|---|---|---|
| K30 | `usr/cpu/sysgen/IP30boot/xtdigvid.o` | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` |
| K27 | `usr/cpu/sysgen/IP27boot/xtdigvid.o` | `138ab5488ed6263b14582c61cf324a79929459ba62f29f92113fed36630f38ae` |
| K35 | `usr/cpu/sysgen/IP35boot/xtdigvid.o` | `64c024a59b6b1dd7962af6d7857e83ff93ef29e498816b91c524a4d00fab1976` |

All under the DM2 1.1.3ml root. K30 was read. K27 and K35 were checked only for matching constants and instruction shapes
(section 9); their bodies were not read line by line.

How it was read. The video interrupt service is an unnamed static routine at `.text` 0x34b9c in K30, reached by relocation from
both `xtdigvid_gv_intr_*_handler` stubs (`.text+0x34b9c` in their `HI16`/`LO16` pair). It runs to about 0x3d0c4, with a few cold blocks
out of line up to 0x3d154. **Correction to the scoping datasheet:** it is not inside the 97,484-byte `xtdigvid_dma` symbol. That
symbol is 0x15878 to 0x2d544 in K30 (size 0x17ccc), the DMA start routine; the statics that follow `xtdigvid_siglost_abort`
(which ends at 0x2ea60) are unnamed, among them the DMA completion routine at 0x2ea60 and the service routine. objdump labels them
`xtdigvid_siglost_abort+0x...` only because that is the nearest preceding symbol. Its trace-record blocks (a spin lock, a host timestamp read, then a record store, repeated 82 times) were collapsed by
a script and everything else was read in address order from `objdump -dr` output. Each E below names the addresses read.
The completion routine it calls (0x2ea60) was read only for its arguments and for what it reads of the ring (nothing).
The relocatable object names the flag table and strings; those are the object's own.

## 1. The path in one paragraph

The board writes a record into a 2 KB ring in host memory, sets bit 0 (VALID) in the record's second word, and raises one of two
video interrupts (one per pipe). The handler (a thin wrapper) calls one shared service routine for the interrupting pipe. That
routine atomically clears VALID on the record at its own tail index, copies the 0x80-byte record into a host-side mirror, decodes
the flag word bit by bit (completion, field interrupt, errors, VBOB link events), advances the tail index modulo 16 and repeats
until it meets a record without VALID. No register is written to acknowledge the interrupt, and no register is read to learn the
cause. The ring write position is not visible to the host.

## 2. Interrupt sources and their acknowledgement

| Source | Handler (K30) | What it reads | How it is acknowledged | Grade |
|---|---|---|---|---|
| Video 0 ("xtdigvid gv 0") | `xtdigvid_gv_intr_0_handler` 0x3dce8 | calls the service routine with pipe 1 (board + 0xa3b8, the `in` pipe) | nothing written to the board | E (0x3dd00-0x3dd10) |
| Video 1 ("xtdigvid gv 1") | `xtdigvid_gv_intr_1_handler` 0x3dd20 | calls the service routine with pipe 0 (board + 0x50, the `out` pipe) | nothing written to the board | E (0x3dd44-0x3dd48) |
| XG error ("xtdigvid XG err") | `xtdigvid_xg_intr_handler` 0x3d180 | reads the cause word at window `0x6c` (0x3d3f4) | see below | E |

**Video interrupts.** The only board register accesses in the whole service routine are the two CLINK-receive operations in
section 7 and no write is made to deassert the interrupt (E: the routine contains one `sync`, at 0x35c64, for the receive-release
store at 0x35c60, and the driver follows every window store with a `sync`, so there is no other window store in it). The interrupt is therefore not a level the driver
must clear; **I** that it is an ordinary Crosstalk interrupt packet toward the vector programmed at window `0x5c` (scoping
datasheet section 2), cleared by the host interrupt controller. What would settle it: a transaction capture of the widget.
The routine begins by setting a per-pipe "in service" word (pipe + 0xa358) to 1 (0x34e5c) and clears it on every exit path
(0x39d2c). The debug dump prints it as `in_intr` (E, argument order of the dump at 0x3de2c, which reads +0xa358 as its last
argument).

**XG error interrupt.** Order in K30: print "XG error interrupt" through `cmn_err` (0x3d1d0, unconditional); read the cause word at `0x6c` into a register (0x3d3f4); clear bit 17 (0x20000) of the
control word at `0x24` with a read-modify-write followed by `sync` (0x3d55c-0x3d578), which masks further error interrupts;
record the cause with two 64-bit compare-and-swaps from zero, at board + 0xadb8 and board + 0xa50, value `(cause << 32) | 1` (0x3d57c, 0x3d5a4); if the cause is nonzero, **write the value read back
to `0x6c`** and `sync` (0x3d5bc-0x3d5c0); then print one message per set cause bit (the bit list is in the scoping datasheet
section 5). E for the sequence. **I** that `0x6c` is write-one-to-clear, because the handler writes back exactly the bits it read
and nothing else. The handler never sets control bit 17 again. **E (settled):** the only code that sets it is `xtdigvid_init_xg` (K30 `0x5880`,
`lw` at `0x5874`, `or` with `0x20000`, `sw`, `sync`), which runs at attach (call from `xtdigvid_init_board` at `0x1488`) and from
the board-reset ioctl when its argument has bit 0 set (call at `0xd7e4`, after the kernel's widget reset service; see
[fpga-load.md](fpga-load.md) section 6.1). A scan of all stores with displacement 36 in K27, K30 and K35 finds the window writers
only in `xtdigvid_init_xg` (two stores), `xtdigvid_deinit_board` (clears the bit at detach: K30 `0x24d4` to `0x24ec`) and this
handler; the other hits are stores into the per-pipe records. So after one XG error interrupt the error interrupt stays masked until
the board is reset with that ioctl or re-attached; the media library issues it once, at initialisation (argument 3). Errors that follow
are not reported until then (**I**: the bit's role as the interrupt enable is E; that masked errors are lost rather than queued is
the usual meaning of a cleared enable, nothing here proves it).

## 3. The ring: size, location and base programming

All of this is E from `xtdigvid_init_gif` (K30 0x5f70-0x6190, 0x6540-0x6900) and the ring-reset path in `xtdigvid_ioctl`
(0xbf68-0xc010) unless marked.

- **Size.** 16 entries of 0x80 bytes, one ring per pipe: 2048 bytes. `bzero(ring, 2048)` at init and at reset (0x61b4, 0xc008). The
  loop index is masked with `0xf` (0x361a8). The ring lives in a host page from `kvpalloc`; its kernel address is kept at pipe + 0x18
  and the page's bus address comes from `kvtophys` then `xtalk_dmamap_addr(map, addr, 2048)`.
- **Board-side address.** The board addresses the ring at a fixed DMA address, `0x8000000` for pipe 0 and `0x9000000` for pipe 1
  (constants built at 0x6884-0x6894 and used as the map RAM address at 0x5fb4).
- **Map RAM programming.** `xtdigvid_write_mapram(board, &ppn, 1, dma_addr)` with `ppn = bus_address >> 14` (0x68a0). Per
  the scoping datasheet's map-RAM entry rule that is one 16 KiB page entry at window `0x100000 + (dma_addr >> 14) * 4`, that is
  `0x108000` (pipe 0) or `0x109000` (pipe 1); only the first 2 KiB of the page is used. The page before and the page after are
  invalidated with `xtdigvid_invalidate_mapram(board, 1, dma_addr)`, one entry each (`0x7ffc000` and `0x8004000` for pipe 0, `0x8ffc000`
  and `0x9004000` for pipe 1; 0x5f70-0x5f90 and 0x6140-0x6168; the routine at 0x2e380 stores `0x10000000 | n` for n = count-1 down to 0,
  read in full). The entry rule is in the scoping datasheet and was re-read in `xtdigvid_write_mapram` (0x2e3ec: `0x20000000 | ppn << 2`,
  with an assertion that ppn has no bit in 31:28). The window offsets above apply it, so they are **I**; the DMA addresses passed are **E**.
  The entry holds `bus_address >> 14`, so the low 14 bits of the ring's bus address are dropped: the ring must start on a 16 KiB
  boundary or the board sees a different 2 KiB (**U**: `kvpalloc` alignment not read; the driver does not check it).
- **No base register.** The driver writes no register that carries the ring address. The constants `0x8000000` and `0x9000000`
  appear as lui operands only at the three sites above (a scan of the object for the lui forms found no others). **I**
  that the board has the two ring addresses built in and relies on the map RAM to place them. Settled by: the GIF FPGA
  configuration (`gif_1.xla`), or a capture of the first status write on the Crosstalk link.
- **Ring pointer reset register.** Window `0x800074` for pipe 0 and `0x800064` for pipe 1: a zero is stored and followed by
  `sync` (0x61a8-0x61ac for init, 0xbffc-0xc000 for the reset path). The stores are chosen by pipe index (init: `movn` on "index is 0"
  at 0x6194 picks `0x74` for pipe 0; reset: `movz` at 0xbfe4 on the same condition picks `0x64` for pipe 1). Right after it the host
  zeroes the ring (`bzero` 2048) and its tail index (pipe + 0x20: 0x61bc, 0xc010). **I** that the register resets the board's write
  index so the next record lands in entry 0; the driver never writes any other value and never reads it. The scoping datasheet's
  earlier listing (`0x800064`, `0x800074` "cleared when the status buffer is set up") is consistent. Pipe 0 owns `0x800074` and
  pipe 1 owns `0x800064`, as the reset path in `IP30boot/xtdigvid.o` 0xbfe4 shows (`movz t8,ra,t9` with `ra = 0x800064`,
  `t8 = 0x800074`, `t9 = pipe < 1`). The [VBOB note](vbob.md) (step 5 of the send path) gives the same assignment.
- **Reset path trigger.** The same three actions (register zero, ring zero, tail zero) run when a VBOB message times out with
  its acknowledge still outstanding (the "reset sdma ring ptr" path, E from the string at that site; see the [VBOB note](vbob.md)).

## 4. Host state per pipe

Offsets are from the pipe record (pipe 0 at board + 0x50, pipe 1 at board + 0xa3b8, record size 0xa368). E unless a grade is shown.

| Offset | Use | Evidence |
|---|---|---|
| +0x08 | pointer to the board record | used by every pipe-index computation (`(pipe - board - 0x50) / 0xa368`) |
| +0x18 | ring base, kernel address | 0x34e64, 0x3620c; printed as `pstatus` by the dump |
| +0x20 | ring tail index, 0 to 15, 32-bit | 0x34e60, 0x361a0-0x361ac |
| +0x24 to +0x823 | mirror: 16 copies of the 0x80-byte record, stride 0x80 | 0x361f0-0x3622c (`bcopy(ring + idx*0x80, pipe + 0x24 + idx*0x80, 0x80)`) |
| +0x824 | is_open | **I**, argument order of the dump's format string |
| +0x828 | dma_active | **I**, same |
| +0x82c | dma_enabled; the error decode in section 6 only runs while it is nonzero | E for the test (0x35620); name **I** |
| +0x830 | flag set to 1 after the DMA start timeout (+0xa360) is cancelled by a completion (0x37e68); tested at 0x371ec, 0x3a6f4, 0x359fc | E for the store and tests; meaning **U** |
| +0x838 | completion slot index, 0 to 3, advanced modulo 4 per completion | 0x371fc-0x3720c |
| per-slot descriptors | 0x60-byte stride (`slot * 3 << 5`, 0x2ea98-0x2eab0); the completion routine touches words at +2112, +2120, +2128, +2144, +2152, +2160 from `pipe + slot * 0x60` | E for the stride and offsets; field names **I** (the dump names `int_sema`, `msc`, `gif_buf_idx`, `dma_status`, `dma_address`) |
| +0xa00 | one 64-bit error word, set by compare-and-swap from 0: low half 2 plus a boolean in the high half on a transfer error, low half 3 on a signal-loss abort | E for the stores (0x3582c, 0x2e800); roles **I** |
| +0xa08 | DMA control shadow; written to window `0x800014` (pipe 0) or `0x80003c` (pipe 1) | 0x2e83c-0x2e848, 0x67e0 |
| +0xaa0 | field counter, incremented once per field interrupt | 0x350f0-0x35100 |
| +0xab0 | extended media stream counter (64-bit) | 0x34f78, 0x383b4 |
| +0xab8 | previous value of +0xab0 | 0x3837c |
| +0xac0 | previous field counter | 0x350f8 |
| +0xac8 | host timestamp taken at the field interrupt | `get_ust_nano` target at 0x38364 |
| +0xa358 | in-service word | section 2 |
| +0xa360 | timer id, DMA start/field timeout | cancelled at 0x37cc4 |
| +0xa364 | timer id, signal-loss watchdog | 0x38f88, 0x39004 |

## 5. The 0x80-byte entry

| Entry offset | Content | Grade |
|---|---|---|
| +0x00 | 32-bit word. The service treats bits 23:0 as a device media stream counter (MSC); see below | E for the use, I for the name and for bits 31:24 being zero |
| +0x04 | 32-bit flag word; bit 0 is VALID. Bits in section 6 | E |
| +0x08 to +0x7f | copied with the rest and never read by the service routine, the completion routine or the dump | U |

**Word 0.** The service routine extends it to 64 bits (0x38368-0x383b4 and 0x34f5c-0x34f78): it loads word 0 of the new entry, compares it
unsigned with the low 24 bits of the previous extended counter at +0xab0, and stores `word0 | (prev & ~0xffffff)`, or
`word0 | ((prev + 0x1000000) & ~0xffffff)` when word 0 is smaller (a wrap of a 24-bit counter). The whole word is OR-ed in, so the
code only works if bits 31:24 read as zero (**I**; not checked by the driver). That this counter is the board's MSC is **I**: the
driver's own strings call it the device MSC ("pipe device UST/MSC", "Resyncing device MSC") and the descriptor field is named `msc`.
The field is the same on both pipes' rings (E, one code path).

**Correction.** The completion routine uses this extended word, multiplied by 12 and added to a host clock sample, as the UST of a completed buffer, and takes the MSC from the field counter at pipe + 0xaa0, so the "MSC" reading above is wrong; see the [UST and MSC note](ust-msc.md) section 2.

**What the record does not carry.** The scoping datasheet section 4 says the interrupt reads a "device UST/MSC" back from the status
record. Only the MSC half comes from the record. The timestamp stored at +0xac8 is the host's own clock sampled by the
service routine at the field interrupt (E: call to the host time functions at 0x38338-0x38364, no ring load feeds it).

**Bytes +0x08 to +0x7f.** No shipped software in this object reads them (E for the three readers named; **I** for the rest of
the object, by a scan for the entry stride constant: `dsrl ...,0x19` only at 0x34f60, 0x36218, 0x38374, and a shift by 7 only in the
service routine and in the dump at 0x3dff4). They are settled as "no software dependency" unless a reader is found elsewhere. The ring is kernel memory; **I** that user space
reaches the board's progress only through the posted events (no ioctl in the VBOB note returns ring contents).
What would settle what the board writes there: a capture of the ring memory, or the GIF FPGA configuration.

## 6. The flag word

The driver carries a 20-entry table at `.data` 0x20 (16 bytes each: bit number as a 32-bit word, then a name pointer), used by the
debug dump at 0x3dd54 to print the names of set bits. Bit number and name are read from the table, E (parsed from the object's
`.data` and `.rodata`). **The scoping datasheet section 3 omits "F" and "FIF" and so has the later names two bits low; this table
replaces it.** The handler use in the third column is E (code read at the cited addresses); what each bit means in hardware terms is **I**, taken from
its name only. "Pipe 0" is the `out` pipe (interrupt gv 1), "pipe 1" the `in` pipe (interrupt gv 0).

| Bit | Mask | Name | What the service routine does | Evidence |
|---|---|---|---|---|
| 0 | 0x1 | VALID | entry present; cleared by the host before anything else | 0x34e78-0x34e84, 0x361c8-0x361e0 |
| 1 | 0x2 | F | becomes a boolean `fbit` passed to the completion routine; logged as "dma fbit" | 0x36b14-0x36b20, call 0x36e88 |
| 2 | 0x4 | INPUT_OFF | pipe 1 only: with IN_CHANGE it means the input signal went away (section 8); logged "dma input off" | 0x3a6c4, 0x3a8c4 |
| 3 | 0x8 | TRS_ERROR | pipe 1 only: logged "dma trs error"; a message "trs error detected but ignored" at debug level 1 or higher; not counted as an error | 0x3abcc-0x3ad98 |
| 4 | 0x10 | OVERFLOW | pipe 0: a transfer error. Pipe 1: "hw seq lost", printed but no event posted (section 8) | 0x35630, 0x35880-0x35a0c, 0x3b7d8 |
| 5 | 0x20 | IN_CHANGE | pipe 1 only: input state changed (section 8) | 0x3a6cc, 0x398cc |
| 6 | 0x40 | FIF | with F_INTR: the device's view of the field parity, compared against the low bit of the driver's field counter | 0x3a0a8-0x3a0b4, logged at 0x38304 |
| 7 | 0x80 | F_INTR | field interrupt: counters, host timestamp, watchdog re-arm, timestamp event | 0x38008, section 6.2 |
| 8-11 | 0x100 to 0x800 | DONE_0 to DONE_3 | DMA slot completion | 0x371bc-0x371e0 |
| 12-15 | 0x1000 to 0x8000 | ABORTED_0 to ABORTED_3 | DMA slot aborted | 0x371c8-0x371e0 |
| 16, 17 | 0x10000, 0x20000 | CURRENT_VALID_0, _1 | **never tested** by the service routine; only named by the dump | no test of these bits at any flag-word use (the flag word is read at 0x35578, 0x35628, 0x35a14, 0x35f7c, 0x36b0c, 0x371c4, 0x38004, 0x3a6bc, 0x3abc8) |
| 18 | 0x40000 | CLINK_XMIT_DONE | VBOB message acknowledge (section 7) | 0x35f80 |
| 19 | 0x80000 | CLINK_RCV_DONE | VBOB message received, event 512 (section 7) | 0x35a18 |

Bits 20 to 31 have no table entry and no test (E for both).

### 6.1 Order inside one entry (E, address-ordered reading)

1. Atomically clear VALID; if it was clear, stop (0x34f24 goes to 0x39d18). The old word is the flag word for the rest of the pass.
2. Copy the entry to the mirror; set `fbit = flags & 2`.
3. Up to four times: take slot `i` = +0x838; if neither DONE_i nor ABORTED_i is set, leave the loop (0x371e4). Otherwise advance
   +0x838 modulo 4 (0x371fc-0x3720c) and, for ABORTED_i, print "dma_abort intr" at debug level 3 and post event 32 (0x36b24-0x36b6c);
   on pipe 1 only, the first time (+0x830 still zero) and while dma_enabled, cancel the DMA start timeout (+0xa360) and set +0x830 to 1
   (0x371ec-0x371f0, 0x37c90-0x37cc4, 0x37e68; the message is "disable field/dma timeout"); then call the completion routine 0x2ea60 with
   `(pipe, slot, fbit, aborted)` (0x36e68-0x36e8c). A DONE and an ABORTED bit for consecutive slots are therefore handled in slot order
   from +0x838, not by bit position.
4. If F_INTR: section 6.2.
5. If dma_enabled: error bits, section 8. For pipe 1, the INPUT_OFF and IN_CHANGE handling at 0x35a10 runs regardless of dma_enabled.
6. If CLINK_RCV_DONE then CLINK_XMIT_DONE: section 7.
7. Advance the tail (section 6.3) and test the next entry.

### 6.2 F_INTR

Order (E): host timestamp sampled into +0xac8 and the MSC extension of section 5 (0x38338-0x383b4); field counter +0xaa0 incremented, previous
value saved at +0xac0 (0x350f0-0x35100); if the pipe's `progressive` halfword (+0xa5e, see [the pipe timing note](pipes-timing.md), section 3) is zero, the counter's low bit is compared with FIF and the counter is
bumped once more when they differ, with the message "Resyncing device MSC" (0x3a0a4-0x3a0d4; E for the code, I for the intent); if the
DMA control shadow (+0xa08) has bit 16 set, post event `0x100` with a 16-byte payload on the stack: the field counter, and an
`ust_to_nano` conversion into a buffer indexed by 12 times the extended MSC from a table at board + 0x30 (0x35590-0x355fc; E for the code, the
payload meaning **U**, as is the role of that table). For pipe 1 while dma_enabled, the signal-loss
watchdog is cancelled and re-armed first (0x38f5c-0x39004, section 8).

Posted event codes in the routine, E from the `li a1` before each `xtdigvid_post_event` call: 32 (0x35858, 0x36b6c), 256 (0x355fc),
512 (0x35f78). Names: the object's event-name strings sit beside the compares for 32 (TRANSFER_ERROR(BUFFERS_ABORTED)),
512 (CLINK_DATA_RCVD) and 128 (SYNC_GAINED), so those are E; 64 is SYNC_LOST by position among the strings (I); the
name of 256 is **U** (the string list holds `TRANSFER_COMPLETE(ust/msc)` which suits its payload, I at best).

### 6.3 Head and tail

- **Tail (host).** One 32-bit index at pipe + 0x20. It is advanced after every entry whose VALID was set: `idx = (idx + 1) & 0xf`, then
  the new entry's word 1 is cleared of VALID and tested (0x361a0-0x361e0). It is zeroed only by init and by the reset path.
  Nothing else changes it (E: stores to +0x20 are at 0x361ac, 0x61bc, 0xc010 and the two copies of the init sequence).
- **Head (board).** Not visible. The host never reads a head register and never writes the ring pointer register (section 3)
  except to zero it. The board's own advance, its wrap at 16 and what it does when the next entry still has VALID set (stall,
  overwrite or drop) are **U**. The host's behaviour is consistent with a producer that fills entries 0 to 15 in order after a
  reset and sets VALID last, but nothing here proves the wrap or the overrun rule. What would settle it: the GIF FPGA configuration or a
  capture of the ring while it overruns.
- **Race note (E).** VALID is cleared before the entry is copied (0x34e78 then 0x3622c), so the mirror can hold a newer entry
  than the flag word in use if the board writes immediately. Whether the board waits for the clear is **U**.

## 7. CLINK (VBOB link) events

Both are ring flags; the protocol is in the [VBOB note](vbob.md). The interrupt-side facts:

- **CLINK_RCV_DONE** (0x35a14-0x35f7c). Read twelve 32-bit window words at `0x803884 + 8k` (k = 0 to 11), keep the low 16 bits of each,
  store them as big-endian byte pairs into a 24-byte buffer (0x35c00-0x35c4c), write 1 to window `0x8038f4` and `sync` (0x35c60-0x35c64),
  then post event 512 with the buffer in every case (0x35f58-0x35f78). A buffer whose byte 2 is `0xa7` only gains an extra trace record
  "vbob signal status" on the way (0x35c7c-0x35c88, 0x3af18-0x3b06c, which rejoins at 0x35f54). E. The window address is built as
  `(0x3880 | 0x80004) + 8k`, which is `0x803884 + 8k`; the VBOB note records the same receive words.
- **CLINK_XMIT_DONE** (0x35f80-0x361ac). Print "vbob clink ack intr" at debug level 2, store 0 to a halfword at board + 0x14738 and
  `sv_signal` the variable at board + 0x14720 (0x3616c-0x36198). No window access. E. It wakes the ioctl waiting for the acknowledge.
- Which pipe's ring carries each flag is **U** (same routine for both; the VBOB note records the same gap).

## 8. Sync loss

**Hardware report (E for what the driver tests; I for what the board means).** Two flag bits: INPUT_OFF (bit 2) and IN_CHANGE (bit 5).
The driver reads them only for pipe 1, the video input (0x35a10 and 0x3562c branch on the pipe index being 1). There is no sync flag for the
output pipe. Names are the driver's table; the meaning ("input signal absent", "input status changed") is the name's, **I**.

On pipe 1 (E):

| Condition | Driver action |
|---|---|
| IN_CHANGE and INPUT_OFF | log "hw signal lost" (0x39a34-0x39b9c); and, while dma_enabled, it also counts as a transfer error: cancel the signal-loss watchdog if +0x830 is set (0x3a6f4-0x3a73c), log "dma input off" and "dma in change", then store error words with a compare-and-swap at +0xa00 and post event 32 (0x35630-0x35858) |
| IN_CHANGE alone | log "hw signal gained" (0x39ba8-0x39d10); nothing else |
| INPUT_OFF alone | while dma_enabled, log "dma input off" (0x3a8c4); nothing else |
| OVERFLOW | log "hw seq lost"; at debug level 3 and above, with dma_enabled set, the pending-timer word (+0x830) clear, and the field counter at or above 108, print "hw seq lost"; no event, no register write (0x35880-0x35a0c, 0x3b7d8-0x3b84c) |
| TRS_ERROR | log and ignore |

On pipe 0 the only error bit is OVERFLOW, a transfer error: the same compare-and-swap and event 32 (0x35630-0x35858).
No `SYNC_GAINED` post exists in this routine; the only literal 128 passed to `xtdigvid_post_event` anywhere in K30 is absent
(E for the scan of `li a1,128`). The code that posts it, if any, is **U**: the name table suggests an event the library consumes; a user-space
caller or a computed event code are the likely routes.

**Software watchdog (E).** Each F_INTR on pipe 1 while dma_enabled cancels `untimeout(id at +0xa364)` and re-arms
`fast_itimeout(xtdigvid_siglost_abort, pipe, xtdigvid_siglost_timer, plhi)`, storing the new id at +0xa364 (0x38f5c-0x39004);
a failed arm logs "fast_itimeout siglost failed". If no field interrupt arrives in time, `xtdigvid_siglost_abort` runs
(K30 0x2e524, read in full): it posts event 64 (SYNC_LOST by position among the name strings, **I**; 0x2e77c), prints at debug level 1 and
above, compare-and-swaps 3 into the +0xa00 word (0x2e7f4-0x2e800), and writes the DMA control shadow +0xa08 to window `0x800014` (pipe 0) or
`0x80003c` (pipe 1) followed by `sync` (0x2e83c-0x2e848). The scoping datasheet says this routine sets an abort bit in the shadow. The
routine as read loads the shadow and stores it back with no bit change, so it rewrites the register with whatever the shadow already
holds. Where an abort bit would be set in the shadow (the DMA abort routine at 0x14484 is the candidate) is **U**; settled by reading
`xtdigvid_dma_abort`. Default `xtdigvid_siglost_timer` is 175 (scoping datasheet); its unit is **U** (clock ticks of the host kernel, not
stated by the driver).

**Not a ring flag (U).** The "locked" state of the genlock input and the VBOB sync detector are not reported through the ring
(scoping datasheet section 8). The ring flags above are the only sync indication in the interrupt path. Settled by: reading the
VBOB firmware messages (the VBOB note), or a capture.

## 9. IP27 and IP35 objects

The same structure is present in both. Evidence (counts over the routine's text, which starts at 0x350b0 in K27 and 0x34bbc in K35,
called from `xtdigvid_gv_intr_0_handler` and `_1_handler` the same way as in K30): one load-linked/store-conditional pair with a
`-2` mask for VALID (K27 two sites, K35 two), one `andi 0xf` for the index, one `lui 0xff`/`0x100` pair for the MSC wrap, `dsrl 0x19`
stride shifts (K27 three, K35 two), the `0xa368` pipe-size constant, `14464` and `14580` for the CLINK words, `0x4720` for
the wake variable, `0x80`, `0x40`, `0x10` flag tests, the field counter at +2720 and the extended MSC at +2736. In all three objects
the init constants `0x8ff`, `0x7ff`, `0x900`, `0x800` lui forms, the `0x64` and `0x74` ori forms and four `li 2048` appear the same number of
times. This is **I** that the logic and the base programming are the same on the three builds; the K27 and K35 bodies were not read
instruction by instruction. The counts are not all equal: K35 references the extended-MSC offset (+2736) ten times against six in K27
and K30, a difference this pass did not explain.

## 10. Disagreements with the other DM2 pages

- Scoping datasheet section 3: the flag-bit list is missing bits 1 and 6 ("F", "FIF"), so IN_CHANGE is bit 5, F_INTR bit 7, DONE_n
  bits 8-11, ABORTED_n bits 12-15, CURRENT_VALID bits 16-17, CLINK_XMIT_DONE bit 18, CLINK_RCV_DONE bit 19.
- Scoping datasheet sections 3 and 4: "the interrupt reads a device UST/MSC from the record" is half right; only the MSC (24 bits) is in the
  record.
- Scoping datasheet section 4: "a ring pointer the interrupt routine advances" is the host's tail index, not a hardware pointer.

## 10a. Further corrections to the scoping datasheet and the draft pages

- Scoping datasheet section 2 and the GIF page section 3: the request timeout register `0x2c` is written (0 once, in the routine called
  from the XG init routine); the earlier statement that no common-block slot beyond `0x20`, `0x30`, `0x38`, `0x58` is touched was wrong
  for slot `0x28`. See [gif-registers.md](gif-registers.md) section 3.
- Scoping datasheet section 2 (`0x800084`): the GIF identification is not read at attach. It is read by `xtdigvid_init_gif`, which the
  board-reset ioctl calls ([fpga-load.md](fpga-load.md) section 11).
- Scoping datasheet section 2 (control): "the error handler ... re-enables nothing" is true of the handler; the re-enable is in the
  XG init routine (section 2 above).

## 11. Unknowns, with what settles each

| Unknown | Settled by |
|---|---|
| Content of entry bytes 0x08 to 0x7f; whether bits 31:24 of word 0 are zero | capture of the ring memory, or the GIF configuration; no shipped reader exists, so "no software dependency" is a valid end state |
| Board write index behaviour: wrap, overrun, whether the ring pointer register does anything but reset the write index | the GIF configuration, or a capture while overrunning |
| That the ring DMA addresses `0x8000000`, `0x9000000` are built into the board | same |
| Meaning of F (bit 1) and FIF (bit 6) | the GIF configuration; the driver's use is the only evidence |
| Meaning and trigger of CURRENT_VALID_0 and _1 | the GIF configuration; the dump names them and nothing tests them |
| Whether the interrupt packet needs any register acknowledge | a transaction capture; the driver writes none |
| ~~XG control bit 17 re-enable site~~ | settled in section 2: `xtdigvid_init_xg` only |
| Event 256's name; event 128's poster | the library's event table and a scan of libdigvid for the 128 literal |
| Pipe field +0x830 and the payload of event 0x100; pipe fields +0xa50 to +0xa5e are named in [the pipe timing note](pipes-timing.md), section 3 | reading the DMA start routine and `xtdigvid_dma_abort` (the scoping datasheet's separate open item) |
| Where the abort bit in the DMA control shadow is set | reading `xtdigvid_dma_abort` (0x14484) |
| Watchdog unit | the clock tick rate of the host kernel on the target build |

Nothing here needs a physical system to describe what the shipped driver does: the ring, its map RAM addresses, the tail
protocol, the flag table and the CLINK window words are all E. How the board produces the ring entries is not visible to software.

## 12. Invalid map-RAM entry, abort, and what the driver needs the board to post

This section answers two questions the other pages left open. Everything is read from K30 (K27 and K35 have the same structure;
the abort store differs as noted in dma.md section 7). The driver tells us what it expects; it cannot tell us what the board does, so
the hardware half of each answer is graded **U** with the route that would settle it.

### 12.1 A transfer that reaches an invalid map-RAM entry

- **E.** The driver makes invalid entries on purpose: one guard entry before and one after every mapped buffer, one on each side of the
  two status-ring pages (dma.md section 2), and an invalidation of all `0x8000` entries at attach (`xtdigvid_invalidate_mapram(board,
  0x8000, 0)`, K30 `0x17a0`, `li a1,0x8000` at `0x1724`) and in the board-reset ioctl when its argument has bit 0 set (`0xe3ec`,
  `li a1,0x8000` at `0xe410`). `0x8000` entries is the 32K-entry map RAM of configuration type 0; the size code read from `0x64` is not
  used to bound it (that register is read only for a debug-level print, K30 `0x9a8`).
- **E.** The only reporter the driver has for an access to an invalid entry is XG error cause bit 13, "map RAM invalid", with the offending
  entry address (20 bits) in register `0x94` (K30 `0x3d9a0` to `0x3d9d4`). Section 2 above gives the handler: it masks the error
  interrupt, records `(cause << 32) | 1` in both pipes' error words (board `+0xa50` and `+0xadb8`), writes the cause back to `0x6c`, and
  prints. It posts no event, wakes nobody, releases no slot semaphore and touches no GIF register and no ring.
- **E.** The recorded error word has an effect only when `xtdigvid_dma` ends: it reads and clears the word, and bit 0 set makes the ioctl
  return errno 5 (dma.md section 6). So an invalid-entry error is reported to the application after the fact, by the ioctl's return.
- **E.** Nothing in the driver tests cause bit 13 to decide whether a slot finished. A slot is finished only by ring flags DONE_n or
  ABORTED_n (section 6.1). The code has no branch that assumes a DONE_n for a slot whose transfer hit an invalid entry.
- **U (hardware).** Whether the board sets DONE_n, ABORTED_n or nothing for that slot; and so whether a video interrupt (a ring entry) is
  also raised. What the software shows is only the XG error path: **I** that the board raises the XG error interrupt (the cause bit has its
  own message and address register, the enable is control bit 17, and no other path reports it). The input pipe is covered if no
  completion ever arrives: `xtdigvid_dma` arms a 200-tick timer on the first input buffer (dma.md section 4 step 6) that runs
  `xtdigvid_dma_abort`, which prints "no input dma complete interrupts received" or "no input field interrupts received" and, on one of
  its paths, writes the abort bit (section 12.2). The output pipe arms no timer.
- Settled by: the XG and GIF logic (the FPGA configuration), or a capture of the ring and of `0x6c` after a transfer is aimed at an
  unmapped page. Either is a physical test under the repository's agreement rule.

### 12.2 Abort

- **E (the write).** To abort, the driver stores `gif_dma_control_shadow | 0x10` (bit 4) to the pipe's DMA control register (window
  `0x800014` for pipe 0, `0x80003c` for pipe 1), followed by `sync`. Writers: `xtdigvid_dma_abort` in all three builds (K30 `0x14bb0` to
  `0x14bd4`; it is the timer routine named above), and the
  self-abort in the cleanup of `xtdigvid_dma` in K27 (`0x2234c`) and K35 (`0x21de4`) only. `xtdigvid_siglost_abort` rewrites the shadow
  without the bit (interrupts section 8). The value written has the slot-valid bits 3:0 clear and bit 16 clear, because the shadow
  never holds bits 4:0 (the assertion at K30 `0x255ac`) and bit 16 is kept apart in `pipe + 0xa74` (dma.md section 3.1).
- **E (what the driver expects back).** The ring flags that report an abort are ABORTED_0 to ABORTED_3, bits 12 to 15 of the flag word
  (section 6). The service routine consumes DONE_n and ABORTED_n in the same loop, in slot order from the completion counter `pipe +
  0x838` (section 6.1 step 3): for each ABORTED_n it prints "dma_abort intr" at debug level 3, posts event 32
  (TRANSFER_ERROR(BUFFERS_ABORTED)) and calls the completion routine, which stores `(status & 4) | 2` in the slot status and releases the
  slot semaphore. So the entry the driver needs is an ordinary 0x80-byte ring entry with VALID and ABORTED_n set for slot n, where n is the
  next slot in arming order.
- **I.** After an abort write the board posts ABORTED_n for every slot that is armed and not yet complete, in arming order, instead of
  DONE_n. Reasoning: the end of `xtdigvid_dma` drains every slot with `psema` on the slot semaphore, with no timeout (K30 `0x18454`;
  an interrupted wait prints "Interrupted during dma, waiting..." and retries after a 200000 microsecond delay, `0x19544` to `0x19570`), and the
  only code that releases a slot semaphore is the completion routine (`vsema` at `0x320fc`), which only the DONE_n and ABORTED_n flags
  reach. If the board posted nothing for an armed slot, the ioctl could not return after the abort. **U:** whether it posts one entry per
  armed slot or only for the slots it has started; whether an already-posted DONE_n is replaced.
- **I.** The driver does not rely on the board's slot counter surviving an abort: every `xtdigvid_dma` call begins with PIPE_RESET, which
  stores 0 to `0x80006c` (pipe 1) or `0x80007c` (pipe 0) and zeroes `pipe + 0x834`, `+0x838` and `+0x83c` (dma.md section 4 step 6).
  That the board's own completion-order counter restarts at slot 0 after that store is inferred (dma.md); the pair of resets would be
  needed if an abort could leave the board and the host out of step.
- **Latches after an abort: U.** The driver never writes a value with bit 4 set and then a value with bit 4 clear in a way that
  distinguishes a strobe from a level: the abort store is followed, after the drain, by the end-of-stream store of the bare shadow
  (`0x1ae04`, bits 4:0 and 16 clear) and by the next stream's first valid-bit store (bit 4 clear again). A level abort bit would
  be cleared by either; a strobe needs nothing. The same holds for the valid bits 3:0 (dma.md section 3.1 already reads them as
  write-one-to-set latches, **I**). One tension to carry: bit 16 is clear in the abort store, in the end-of-stream store and in the
  reset stores, yet the ABORTED_n entries and their interrupts must still arrive after the abort store for the drain to finish; so
  either bit 16 does not gate ring posting and interrupts, or it is also a set-only latch. Which is **U**.
- Settled by: the GIF FPGA configuration, or register captures of the control word before and after an abort write on a running pipe
  (a physical test).

