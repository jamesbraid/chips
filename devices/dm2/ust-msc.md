# DM2 UST and MSC: where a completed buffer's stamps come from

Status: **draft, not independently reviewed.** Part of the [DM2 pipe timing note](pipes-timing.md); the status ring is in the [interrupt note](interrupts-status.md) and the slot programming in the [DMA note](dma.md). This page answers four questions about the stamps the media library reports for each completed video buffer (`ML_VIDEO_UST_INT64`, `ML_VIDEO_MSC_INT64`), and about what the shipped confidence test expects of them.
Grades: **E** established (read in the disassembly, or the object's own tables), **I** inferred (reasoning given), **U** unknown (what would settle it given). Decompiler output was not used. Function names and member names come from the debug build's DWARF; every address is a virtual address in the build named.

## Sources

| Tag | Object (under `usr/` in the DM2 1.1.3ml root) | sha256 |
|---|---|---|
| L | `lib32/mlmodule/libdigvid.so` (release build) | `aacf8d4a64dcd34b523c4b2b7bc66153104b710171d42f7e65a588bcb95bc2ca` |
| D | `lib32/mlmodule/debug/libdigvid.so` (debug build, DWARF) | `a6bcd5d2da2531c9191c5bec8e4c76bea8816d42f109ba4841b46fe6524fbc24` |
| K30 | `cpu/sysgen/IP30boot/xtdigvid.o`; addresses are `.text` offsets | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` |
| U | `diags/ml_xtdigvid/bin/check_ustmsc` | `4526fcdfee9c0b8fc5c2938a03f9cd86b4bff1ce1a149830849dc31a0539abbb` |
| V | `diags/ml_xtdigvid/bin/dv_memtovid` (stripped) | `5b3a07b2383ec6c2eb5398547e72072225972b8864a8a9a0824bac6ccbfc16e7` |
| T | `diags/ml_xtdigvid/bin/xtdigvid_confidence` (a C-shell script, read as text) | `90a75022dcf19f964956c2765378f54ee6030ec34cae2f84d6213f7711c4f0b2` |

Names used below: pipe 0 is output, pipe 1 input; "pipe + 0xNNN" is an offset in the driver's per-pipe record; "slot record" is one of the four 0x60-byte DMA slot records at pipe + 0x840 (interrupt note section 4); `c` is the field counter (pipe + 0xaa0), `p` the previous field counter (pipe + 0xac0), `E` the extended ring word 0 (pipe + 0xab0) and `Ep` its previous value (pipe + 0xab8).

## The chain in one paragraph

The board writes a 0x80-byte status entry per event into a ring in host memory. The driver's interrupt routine reads each entry, (1) completes any DMA slot whose DONE bit is set, then (2) if F_INTR is set, bumps the field counter and extends ring word 0 to 64 bits. The completion step copies a pair of values, chosen from the counter state, into the slot record; the driver then posts a transfer-complete event (event type 8) whose header carries them: `msc` as stored and `ust` after a conversion to nanoseconds. The library's event thread copies the event's `ust` and `msc` into the buffer-complete message unchanged. The library's own clock is not used (question 2) and the library does no arithmetic on the values except a lost-sequence check (question 3).

## 1. Slots per buffer on an output path, and the field size

**Answer: one slot per buffer, never one per field.** A buffer is one ML buffer: one frame when the path's interleave mode is INTERLEAVED (the mode `xtdigvid_confidence` uses), one field when it is SINGLE_FIELD. So an interlaced frame in INTERLEAVED mode (ML_TIMING_525 included) takes one slot; in SINGLE_FIELD mode a frame takes two buffers and so two slots, written as a pair (below).

- **E: the library queues one FIFO block per buffer.** `xhdSendBuffer` (D 0x4127b0) builds one `dmsevent_t` per call with the buffer pointer and `length` and enqueues it (`dmFifoEnq` family); `ddSendBuffers` (D 0x421640) calls it once per message. There is no loop and no split on field boundaries. The DMA ioctl `0x68647603` (D 0x411118 to 0x411214, L 0x40bf88 to 0x40bfbc) names the FIFO, not a slot count.
- **E: the kernel arms one of four slots per block.** `xtdigvid_dma` takes the block's length from the dequeued block, uses `slot = next_index & 3`, and in the ordinary case writes one control word `(1 << slot) | shadow | 0x10000` per block ([DMA note](dma.md) section 4 step 8; K30 0x2a338 to 0x2a384). The ordinary case is: (`progressive` or `interleaved` nonzero) and `ffmode` zero. The alternative (`ffmode` set, or SINGLE_FIELD) holds the first block's slot pending and writes both valid bits when the next block arrives (K30 0x255f8 to 0x25678). Still one slot per block; the pair is two blocks.
- **E: the driver never reads the library's size field.** The DMA ioctl carries `xferSize`, but the only reads of that structure in `xtdigvid_dma` are at offsets 0 (FIFO id), 16 (pipe), 32 (initial MSC) and 136 (`output_repeat_buffers`; K30 0x15de4 to 0x15dec, 0x15e54 to 0x15e5c, 0x1cbdc, 0x1d0dc, 0x1e1c0), not 20. The raster block's `field_size` (pipe + 0xa4c) is also never loaded: there is no load with displacement 2636 anywhere in K30.
- **E: how the library derives the sizes.** All of it is in `xhdCommitPathControls` (D 0x40c470, L 0x409e50). With `W` image width, `H1`/`H2` ML image heights 1 and 2, `px` bytes per pixel (a float), `rowbytes = trunc(W * px)`:

| Value | Rule | Where |
|---|---|---|
| `xferSize` / `frameSize` (path + 116) | progressive or INTERLEAVED: `W * H1 * px`; SINGLE_FIELD: `W * (H1 + H2) * px` | D 0x40c850 to 0x40c8f0; L 0x40a064 to 0x40a0b0 and 0x40a108 to 0x40a134 |
| raster `field_size` | `H1 * rowbytes`, in every mode | D 0x4106cc to 0x4106ec; L 0x40b9d8 to 0x40ba18 |
| raster `interleaved` | progressive 1; INTERLEAVED 1; SINGLE_FIELD 0 | D 0x4106f4 to 0x410774 |
| raster `msc_increment` | progressive 1; SINGLE_FIELD 1; INTERLEAVED 1 with frame forcing on, else 2 | D 0x410778 to 0x4107a4 |
| `output_repeat_buffers` | repeat NONE 0; FIELD 1; FRAME 2 if SINGLE_FIELD else 1 | D 0x411160 to 0x4111d8 |

The `frameSize` rule for INTERLEAVED uses `H1` alone, so **I** that `H1` is then the whole interleaved frame's line count (a half-height buffer would be wrong); settled by `mluComputePathParamsFromTiming` in `libMLU.so.1` or a dump of a path's parameters. `field_length1` and `field_length2` in the raster block are the video heights (ML_VIDEO_HEIGHT_1/2), not the image heights, so for the timing rows in [the timing note](pipes-timing.md) section 6 they are the field line counts.

How many status entries the board writes per field, and whether a completed slot gets an entry of its own, are board behaviour that no shipped software states (**U**, interrupt note section 6.3).

## 2. Where UST comes from

**Answer: the kernel driver's transfer-complete event, built from the status entry's word 0 (the board's own counter), scaled and converted to nanoseconds by the kernel. Not the library's clock, not a host timestamp in the ring entry.**

- **E: the library copies the event.** The event thread (D `event_loop` 0x413780; L 0x40cec8) reads the event record with ioctl `0x68647605`. `xthd_event_t` (DWARF) is `msc` at +0 (uint64), `ust` at +8, `type` at +16, then a union: `transfer_complete { uint32 dma_length }` and `field_intr { uint64 ust; uint64 msc }` at +24. For type 8 (the library's `EV_TRANSFER_COMPLETE`) it dequeues the buffer's message and stores the event's `ust` (+8) into the message's `ML_VIDEO_UST_INT64` parameter (0x327013; D 0x414540 to 0x414584, L 0x40d494 to 0x40d4bc) and `msc` (+0) into `ML_VIDEO_MSC_INT64` (0x328013; D 0x414594 to 0x4145d8, L 0x40d4c4 to 0x40d4e8). The event's `dma_length` goes into the first parameter looked up (0xb49021, D 0x4144a0 to 0x4144cc; name **I**). No scaling, no arithmetic.
- **E: the library's clock is only a debug print.** The only imports that read a clock are `mlGetSystemUST` (debug build only; call sites D 0x412b08 in `checkForSequenceLost` and D 0x42170c in `ddSendBuffers`) and `time`. Both `mlGetSystemUST` results go only to level-4 and level-5 trace prints. The release build does not import `mlGetSystemUST` at all (its dynamic symbols list no UST function). So the release library's `ML_VIDEO_UST` is the kernel's, by construction.
- **E: the kernel's event carries a converted counter value.** `xtdigvid_post_event` (K30 0x10910) fills the next 152-byte event slot: `type` from its argument, `msc` = the 64-bit word at pipe + 0xa98 (K30 0x10db4, 0x10dbc), and `ust` = `ust_to_nano(*(pipe + 0xa90) + board->0x30, &event.ust)` (K30 0x10dc8 to 0x10de8; `ust_to_nano` is a kernel routine outside this object). Event 8 is posted by the DMA completion routine (K30 0x2ea60; the post is at 0x33764, `li a1, 8` at 0x33760, payload word = the slot record's length at +0x50). It is the only post of constant 8 (scan of the 26 relocation sites naming `xtdigvid_post_event`; **I** that none passes 8 in a register).
- **E: the two source words.** `pipe + 0xa98` and `pipe + 0xa90` are loaded from the slot record's +0x28 and +0x30 (K30 0x31b9c to 0x31bb8) under the pipe's mutex. The completion routine stores them in the slot record at one of several sites (section 3); at every one of them the `+0x30` value is first multiplied by 12 (K30 0x316dc to 0x316f0: `x * 4 - x`, then `* 4`).
- **E: where the `+0x30` value starts.** It is the extended status-entry word 0 (`E` or `Ep`, or a value extrapolated from them), extended to 64 bits exactly as in the [interrupt note](interrupts-status.md) section 5 (K30 0x38368 to 0x383b4), once per F_INTR entry. So **the interrupt note's reading of word 0 as the board's MSC is wrong: it feeds the UST path, not MSC.** The MSC path is the field counter (section 3).
- **E: the host side of the clock.** `board + 0x30` is a raw host UST sample. `xtdigvid_init_ust` (K30 0x9ff4) stores 0 to window register `0x80008c` followed by `sync` (0xa034 to 0xa064), calls `update_ust`, then `get_ust(board + 0x30)` (0xa070 to 0xa08c). So the board's UST word is zeroed at the same instant the host samples its own UST; `ust = ust_to_nano(12 * word0_extended + host_ust_at_zero)`. `xtdigvid_dma` calls `xtdigvid_init_ust` again at every transfer start (K30 0x160b4 to 0x160cc) and then compares `host_now - (pipe + 0xab0 + board + 0x30)` against 0x28f5c (167,772) raw ticks, printing a warning if it is larger (0x16114 to 0x16138). `0x80008c` is written once and never read: the constant `0x80008c` is formed at one place in each of K30 (0xa034), IP27 (0xa520) and IP35 (0x9f2c). **I** that the register is the board's free-running UST counter and word 0 samples it; the zeroing and the use as an offset are E, the register's purpose is not named by any string.
- **E: no host timestamp in the ring.** The driver only clears VALID in an entry (atomic clear on word 1, K30 0x34e78) and zeroes the whole ring at reset; nothing else stores into the ring. The host clock sampled at each field interrupt (`get_ust_nano`, pipe + 0xac8, K30 0x38364) is never copied into the event: it is used only to decide how stale a completion is (section 3).
- **Units.** The event's `ust` is nanoseconds: the library stores it unchanged as ML's UST and the shipped test compares its deltas with 33,370,000 (section 4). That `ust_to_nano` produces nanoseconds follows from those two facts and its name (**I**; its body is outside the shipped objects). The word-0 tick is 1/12 of a host UST tick (E for the factor); the absolute rate of either is **U** (it depends on the host's UST clock, which none of these objects state). Word 0 is 24 bits wide (E: the extension compares against the low 24 bits only), so at 12 host ticks per board tick the wrap and the extension are both sound only if the host tick is slow enough that a wrap takes longer than a field; the shipped code does not check (**I**).

## 3. Where MSC comes from, and what the second completion of a pair would report

**Answer: MSC is the driver's field counter, not a per-entry flag and not a count of entries.** `c` (pipe + 0xaa0) is incremented once per ring entry with F_INTR set, in the same routine that extends word 0 (K30 0x350f0 to 0x35100: `p = c; c = c + 1`). A non-progressive pipe then compares `c & 1` with FIF (flag bit 6) and adds one more when they differ, setting `p = c_before_the_extra_increment` (K30 0x3a0a4 to 0x3a0d4). DONE_n bits and entries without F_INTR never change `c`, `p`, `E` or `Ep`. The start value comes from the library (100 or 101, [pipe timing note](pipes-timing.md) section 2). All E.

The event's `msc` is the slot record's +0x28 and its UST source the slot record's +0x30. The completion routine (K30 0x2ea60) sets both **at completion time from the current counter state**, choosing among three pairs. Inputs, all E:

- `F`: the entry's F flag (bit 1), passed in as the routine's third argument (saved at K30 0x2f044). `par = c & 1`.
- `fresh`: the host time elapsed since the last field interrupt was processed, less than 1 ms: `now - pipe + 0xac8 < 1,000,000` ns (K30 0x30c78 to 0x30ca4, tested at 0x31538, 0x33594, 0x33ab8, 0x3426c). `now` is read inside the routine, per completion.
- the mode halfwords from the raster block: `progressive` (pipe + 0xa5e), `ffmode` (+0xa52), `interleaved` (+0xa50).

The resulting `(msc, ust source)`; the UST source is then multiplied by 12 and converted as in section 2:

| Mode | Condition | `msc` | UST source | K30 address of the assignment |
|---|---|---|---|---|
| progressive | not fresh | `c` | `E` | 0x330f0 to 0x33104 |
| progressive | fresh | `p` | `Ep` | 0x316c4 to 0x316d8 |
| interlaced, `ffmode` 0, `interleaved` set (INTERLEAVED frames, the 525 test) | `F != par` | `p` | `Ep` | 0x33f30 to 0x33f44 |
| same | `F == par`, not fresh | `c` | `E` | 0x340a4 to 0x340bc |
| same | `F == par`, fresh | `p - 1` | `2*Ep - E` | 0x33c30 to 0x33c58 |
| interlaced, `ffmode` 0, `interleaved` 0 (SINGLE_FIELD) | `F == par` | `c` | `E` | 0x340c8 to 0x340dc |
| same | `F != par`, not fresh | `c + 1` | `2*E - Ep` | 0x34560 to 0x34584 |
| same | `F != par`, fresh | `p` | `Ep` | 0x343e8 to 0x343fc |
| interlaced, `ffmode` set | `F != par` | `c` | `E` | 0x33a5c to 0x33a6c |
| same | `F == par`, not fresh | `p` | `Ep` | 0x33a70 to 0x33a84 |
| same | `F == par`, fresh | `p - 1` | `2*Ep - E` | 0x335ac to 0x335d4 |

Dispatch: `progressive` test at K30 0x31528 to 0x31530, `ffmode` at 0x33578 to 0x33580, `interleaved` at 0x33a88 to 0x33a90, parity at 0x3358c, 0x33a9c and 0x340c0. The pipe index only selects which debug-trace flags gate logging around these assignments; both pipes take the same assignment (**I**: every branch on the pipe index that I followed ends at the same assignment).

Two consequences, both E from the code above:

1. **A completion is stamped from the counter state at the moment the completion routine runs, and the DONE loop runs before the F_INTR step of the same entry** (interrupt note section 6.1; the loop exit at K30 0x371e4 goes to the F_INTR test at 0x38008). A DONE bit that arrives in an entry together with its F_INTR is stamped with the previous field interrupt's state.
2. **Two completions processed in the same service pass get identical stamps.** `c`, `p`, `E`, `Ep` change only in the F_INTR step, `F` and `par` are the same for one entry, and `fresh` is evaluated microseconds apart. So when the board marks two slots done in one entry (DONE_i and DONE_j together), or in two entries with no F_INTR between them, both slots receive the same `msc` and the same UST source. The second buffer's message then has `msc` and `ust` equal to the first's, and a consumer that subtracts consecutive messages gets `deltaMSC = 0` and `deltaUST = 0` for it, while the first buffer (whose predecessor completed a frame earlier) shows `deltaMSC = 2` (INTERLEAVED, step 2) and one frame of UST.

   For two buffers to be two frames apart in MSC, each needs its own F_INTR entries between their completions: with INTERLEAVED frames, the second completion's `msc` must have been advanced by two field interrupts (two entries with F_INTR, each bumping `c` once) since the first's. The other ways to see 0/0 are a second slot completed with a DONE bit but no new F_INTR, or one F_INTR per frame instead of per field (delta 1, not 0). Whether the board's status writes ever combine two slots in one entry is **U** (interrupt note section 6.3).

The library does not repair duplicates. `checkForSequenceLost` (D 0x4129b0, L 0x40ca20; called from the event thread at D 0x414434 to 0x414470) takes a step of 1 for progressive or SINGLE_FIELD paths and 2 for INTERLEAVED interlaced (D 0x4129e0 to 0x412a1c) and posts SEQUENCE_LOST only when the MSC has jumped by more than the step; a repeat or a delta of 0 is silent (E). It is skipped until one buffer has completed (the previous completed buffer's `msc`, event_loop local `mscFromTransferComplete`, is zero before that; tested at D 0x414434), and the thread keeps its own `lastReportedMSC`, passed by reference.

## 4. What the confidence test expects

**Answer: deltaMSC exactly 2, and 0 < deltaUST <= 33,378,000 ns, per buffer; the nominal frame is 33,366,667 ns and passes.**

- **E: where the test comes from.** The script `xtdigvid_confidence` (T lines 698 to 835; "UST INCREMENT CORRECTNESS CHECK") runs `dv_memtovid` on the 525 timing (`ML_TIMING_525`, CbYCr 601, 8 bit, 4:2:2, INTERLEAVED, F1 dominance, internal genlock, 20 buffers, `-M`) with output captured, keeps the lines containing "transfer complete", and runs `check_ustmsc -u 8000 -f <file>` (T line 115 sets `CHECK_USTMSC`; the run is at T lines 831 to 835). Pass is the exit status of `check_ustmsc`.
- **E: the lines.** `dv_memtovid` (V; the `ML_BUFFERS_COMPLETE` branch at 0x10005128) prints `transfer complete: length:%ld MSC:%lld deltaMSC:%lld UST:0x%016llx deltaUST:%lld` for each completed buffer after the first, with the deltas against the previous completed buffer's message (V 0x1000519c to 0x100051b8, print at 0x100051bc to 0x100051ec; the previous values are updated at 0x10005260 to 0x1000526c). The first buffer produces no such line. With 20 buffers that is 19 lines.
- **E: what `check_ustmsc` tests.** Defaults in `.data` at U 0x10004440: count 10, `ust_variance` 8000, `ust_delta` 0x01fd2f90 = 33,370,000, `msc_delta` 2 (the script overrides only the variance). It reads `count` lines and for each (main at U 0x100012d0, loop at 0x10001660 to 0x1000189c): `deltaMSC <= 0` fails ("MSC delta <= 0"); `deltaMSC != msc_delta` fails ("MSC delta error"); `deltaUST <= 0` fails; `deltaUST > ust_delta + ust_variance` (33,378,000) fails and increments the error count ("UST delta exceed tolerance by %lld"). **There is no lower bound on deltaUST other than 0.** A short file (fewer than `count` lines) fails with "EOF after buffer count". Exit status 0 passed, 1 failed.
- **Arithmetic.** One 525-line frame is 858 samples per line times 525 lines at 13.5 MHz: 450,450 / 13,500,000 s = 1001/30000 s = 33.366667 ms, so 33,366,667 ns (rounded), two fields of 16,683,333 ns each. This is the frame period of the row at L 0x41c6d0 ([timing note](pipes-timing.md) section 6, "525": 858, 525, 13.5 MHz). The default 33,370,000 is that value rounded to 10 µs; the difference is 3,333 ns, inside the 8,000 ns tolerance, and a UST step of exactly 33,366,667 passes. The tolerance is in nanoseconds (**I**: the unit follows from the default's size and the units of the event's `ust`; `check_ustmsc` itself does no unit conversion).
- **I: why 2.** The library's expected step for INTERLEAVED interlaced paths is 2 (section 3), the raster block carries `msc_increment` 2 for it, and a frame spans two F_INTR entries.

## 5. Statements in other DM2 pages that this page supersedes

- [Interrupt note](interrupts-status.md) section 5 and the pipe 0 / pipe 1 table in section 4: status-entry word 0 and pipe + 0xab0/0xab8 are **not** an MSC; they are the board counter that becomes UST (section 2 here). The "device MSC" strings in the driver name the field counter at pipe + 0xaa0.
- [Interrupt note](interrupts-status.md) section 6.2, the 0x100 payload: the conversion is `ust_to_nano(12 * E + board->0x30)`, not an index into a table at board + 0x30 (K30 0x35590 to 0x355fc, same arithmetic as section 2 here).
- [Interrupt note](interrupts-status.md) section 6, "Bit 1 F": its value is compared with `c & 1` in the completion routine (section 3 here), so it is a field-parity flag of the completion; it is not unused. What it means in the video standard's terms is still **U**.
- [Pipe timing note](pipes-timing.md) section 2, "What the application sees": the `ust`/`msc` of each buffer come from event type 8 as above; the field-interrupt event (0x100) is not what the library reports for buffers.

## 6. Unknowns

| Unknown | Settled by |
|---|---|
| How many ring entries the board writes per field and per completed slot, and whether it ever sets two DONE bits in one entry | a capture of the ring, or the GIF configuration |
| The rate of the board's UST counter (word 0) and of the host UST tick | the host kernel's UST clock definition, or a capture of word 0 against a known clock |
| The register at window `0x80008c`: that it is the UST counter that word 0 samples (only its write of 0 and the use of word 0 as an offset are read) | the GIF configuration, or a capture of word 0 across the write |
| Meaning of the F flag (bit 1) in video terms, and of FIF = 1 | a capture of the flags against a known source |
| `H1` for INTERLEAVED paths (whole frame or first field) | `mluComputePathParamsFromTiming` in `libMLU.so.1`, or a printed path parameter dump |
| `ust_to_nano` body and unit | the host kernel (not shipped in these objects); the unit is inferred from the library's use |
| Whether an input path stamps the same way | the input pipe uses the same completion routine (E), but no input-path test was traced |
