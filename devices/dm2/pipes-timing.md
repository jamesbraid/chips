# DM2 pipes: when they run, the stream counter, field parity, output timing

Status: **draft, not independently reviewed.** Part of the [DM2 scoping datasheet](README.md). The VBOB side of the same flow is in the [VBOB message note](vbob.md); the DMA programming is in the [DMA note](dma.md) and the status ring in the [interrupt note](interrupts-status.md). Where each completed buffer's UST and MSC come from, and what the confidence test expects of them, is in the [UST and MSC note](ust-msc.md). This page adds the library's start sequence, the stream counter's start value, the field-parity rules and the arithmetic behind the VBOB timing record. It does not repeat the DMA register reading.
Grades: **E** established (read in disassembly or the object's own tables), **I** inferred, **U** unknown, each with what would settle it. Decompiler output was used for navigation only.

## Sources

| Tag | Object | sha256 |
|---|---|---|
| L | `usr/lib32/mlmodule/libdigvid.so` (release build) | `aacf8d4a64dcd34b523c4b2b7bc66153104b710171d42f7e65a588bcb95bc2ca` |
| D | `usr/lib32/mlmodule/debug/libdigvid.so` (debug build; DWARF names members and locals) | `a6bcd5d2da2531c9191c5bec8e4c76bea8816d42f109ba4841b46fe6524fbc24` |
| K30 | `usr/cpu/sysgen/IP30boot/xtdigvid.o` | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` |
| U | `usr/diags/ml_xtdigvid/bin/check_ustmsc` | `4526fcdfee9c0b8fc5c2938a03f9cd86b4bff1ce1a149830849dc31a0539abbb` |

All under the DM2 1.1.3ml root. L and D addresses are virtual addresses; K30 addresses are `.text` offsets. The release build's code is reordered, so L addresses jump around; the debug build is contiguous and is cited where it makes a flow easier to follow. Both are marked. Pipe 0 is the output (video-out) pipe and pipe 1 the input pipe, as the library and driver use them (E: the library's `pipe` path parameter is 1 for input paths and 0 for output paths, L 0x4096f0 to 0x4096fc and 0x409948; the driver's "in" and "out" labels).

## 1. What the library does before a pipe runs

**Open of a path** (`xhdOpenPath`, L 0x4096c0; D 0x40b850). It opens the driver node and the pipe node `<device>p<pipe>`, sets pipe ownership with ioctl `0x68647616` twice (set, then clear), reads the board's identity record with `0x6864760f`, creates the FIFO, flushes the pipe's events (`0x68647607`, L 0x40998c) and sets its event mask to 0x200 (`0x68647606`, L 0x4099b8), then starts the event thread. Opening an **input** path while the output pipe is idle also stores 1 then 0 to the CLINK UART reset word, register number 0x38e0 (L 0x409be0 to 0x409c04; D 0x40b850 shows the condition: input path and `xhdIsPipeBusy(0)` false). `xhdInit` does the same pulse at L 0x407f10 to 0x407f64. All E.

**Commit** (`xhdCommitPathControls`, L 0x409e50) programs the GIF, VIF or HDOC, packer or unpacker and colour-converter registers (see [the register note](gif-registers.md)) and ends with the raster ioctl `0x68647604` (L 0x40ba98; section 3).

**Start of a transfer** (`xhdDoTransfer`, L 0x40bf00; D 0x410d60). In order (E unless marked):
1. Build the DMA ioctl `0x68647603` buffer (L 0x40bf88 to 0x40bfbc): FIFO id, pool id -1, pipe word (path parameter at ctx+0x700), transfer size (ctx+0x4ac, the path's frame size), repeat count 0, and flags 0. The structure members are D's `xtdigvid_ioctl_dma_t`: `fifoId`, `poolId`, `pipe`, `xferSize`, `xferCount`, `initial_device_msc`, `is_DMRB`, `isTriggered`, `vidinfo_template`, `output_repeat_buffers`.
2. Choose `initial_device_msc` (section 2).
3. **Input pipe, signal gate.** The library reads the VBOB input-signal reply (kind 10), picks byte 6 for the SD input (path index 3) or byte 4 for the HD input (index 0), converts it to an ML timing and compares it with the path's video timing (a custom format accepts any detected timing but NONE). It posts 0x40304 (SIGNAL_PRESENT) and marks the path present, or leaves it absent. An absent path abandons the start (L 0x40c29c to 0x40c330; the same flow with the failure message in D). The graphics inputs (path indices 2 and 5), and any path with the loopback control on (jack-control member `loopback`), skip the check and are treated as present (D 0x410d60). Nothing the VBOB says is read again after the start: the kernel's own sync-loss watchdog takes over (below).
4. **Output pipe, reference gate.** If the genlock source is not INTERNAL and the handle is not already marked locked, the sync-state reply decides (VBOB note section 5); an unlocked result abandons the start with "Failed to genlock at start transfer".
5. Set the event mask to `0xfffffeff` (ioctl `0x68647606`, L 0x40c028 to 0x40c038): every event except 0x100, the field-interrupt event. The kernel handler stores the mask at pipe + 0xb50 and then calls a masked-update helper (K30 0xa45c, `*word = (*word & ~mask) | value`) on the pipe's DMA control shadow (pipe + 0xa08) with value 0x10000 when mask bit 0x100 is set and 0 when it is clear (K30 0xcb68 to 0xccfc; E for the value and the shadow, the helper's mask operand was not traced and is **I** to be 0x10000). So the library's mask clears shadow bit 16 and the field-interrupt event 0x100 is never posted (the service routine posts it only when the shadow has bit 16, interrupt note section 6.2). The interrupt-enable that the start routine writes into the control register itself is separate from the shadow (DMA note section 3.1), so the hardware field interrupt still runs (E for the start routine's write, I for the separation).
6. Flush events (`0x68647607`, L 0x40c064), then the DMA start ioctl `0x68647603` (L 0x40c0a0), which does not return until the FIFO is drained or an error occurs.
7. After the return: VBOB routing is reset (`xhdResetVbobRouting`) unless an environment variable keeps it, the mask goes back to 0x200 (L 0x40c244 to 0x40c5a4), the FIFO is recreated, and an error posts 0x40201 (DEVICE_ERROR).

**The debug build only** reads VIF register number 0x1810 at the start of an input transfer and tests bit 5 (0x20); if it is set it stores bit 7 of the VIF control (register number 0x1800) as 1 then 0, and after the VBOB checks waits 27 ms and reads 0x1810 again, abandoning the start if bit 5 is still set (D 0x410d60). The release build contains none of this: it has no load of constant 0x1810 or 0x1800 outside the formatter programming (L has `li a1,6144` only at 0x40a688; no `usleep` constant 27000). So in the release library nothing reads VIF 0x1810 at start (E for the absence, by scanning L's constants; the debug-only code is E in D). **I** that bit 5 is a sticky input-error flag cleared by the control's bit 7 pulse; settled by the VIF netlist.

## 2. Where the stream counter starts

Two counters exist; do not conflate them.

**Driver field counter, set by the start ioctl (E).** The kernel's start routine takes the 64-bit `initial_device_msc` from the ioctl structure (offset 32) and stores it to the pipe's field counter (pipe + 0xaa0) and to the previous-field counter (pipe + 0xac0) (K30 0x15de4 to 0x15e2c: `ld a0,32(v1)`, `sd a0,2720(s8)`, `sd v1,2752(s8)`). It zeroes pipe + 0xa90 and pipe + 0xab8 in the same sequence (K30 0x15de8, 0x15df0). It never writes the value to a window register (no store of it anywhere in the routine; the only users are those two fields). The field counter is then incremented once per field interrupt (interrupt note, section 6.2).

**Value chosen by the library (E, L 0x40bfdc to 0x40bff4; D 0x410d60).**

| Condition on the path | `initial_device_msc` |
|---|---|
| image dominance is F1 (ctx 0x474 = 0), or temporal sampling is PROGRESSIVE (ctx 0x46c = 1) | 100 |
| otherwise (interlaced, F2-dominant) | 101 |

The enum names are the library's (`ML_DOMINANCE_F1` 0, `ML_DOMINANCE_F2` 1, `ML_TEMPORAL_SAMPLING_FIELD_BASED` 0, `ML_TEMPORAL_SAMPLING_PROGRESSIVE` 1; value arrays at L 0x41edf0 and 0x41e778). The value is the same for both pipes. So the stream counter in the driver starts at an even number for a field-1-first or progressive stream and at an odd number for a field-2-first stream. **I** that "even" means "the next field is field 1", because the field-parity check (section 4) keeps the counter's parity equal to the hardware's field flag.

**Hardware MSC (ring entry word 0).** The service routine extends the 24-bit word 0 of each status entry to 64 bits (interrupt note section 5). Its value at stream start is **U**: the start routine does not write it, and the extension field (pipe + 0xab0) is not cleared by the start routine (K30 0x15de4 to 0x15e2c has no store to offset 2736). Settled by a capture of word 0 across a start, or the GIF configuration.

**What the application sees.** The library reports `ML_VIDEO_MSC` and `ML_VIDEO_UST` (0x328013, 0x327013) from the kernel's transfer-complete event (`msc` at event offset 0, `ust` at offset 8; D `xthd_event_t`; the event thread is D 0x413780, with the same code scattered around L 0x40d060). The step per buffer the library expects (`checkForSequenceLost`, D 0x4129b0) is 1 when the path is progressive or single-field and 2 when it is interleaved interlaced; a larger jump posts 0x40300 (SEQUENCE_LOST) with an extrapolated UST/MSC pair (E for the step and the post; the extrapolation is linear in the last UST/MSC pair, **I**). The raster ioctl carries a similar `msc_increment` (1 for progressive and single-field, 2 for interleaved interlaced with frame-forcing mode off, 1 with it on; E, D 0x40c470), but the IP30 driver never reads it (E: no load of pipe + 0xa60 anywhere in K30). The diagnostic `check_ustmsc` agrees with the library: its defaults are MSC delta 2 and UST delta 33,370,000 ns, the frame time of a 29.97 Hz interlaced signal, with count 10 and UST variance 8000 (E, `.data` at U 0x10004440 to 0x10004458).

## 3. The raster block the kernel keeps

The raster ioctl `0x68647604` copies 28 bytes from the user buffer (offset 8) into the pipe at **pipe + 0xa48** (K30 0x10884 to 0x108bc, `xtdigvid_eval_ioctl`: size 28, destination board + pipe * 0xa368 + 2712) and then calls `xtdigvid_configure_raster` (K30 0x72cc). The 28 bytes are D's `xtdigvid_ioctl_raster_params_t`, so the pipe fields are:

| Pipe offset | Member | Library value (D 0x40c470) |
|---|---|---|
| +0xa48 | `pipe` | pipe word |
| +0xa4c | `field_size` | image height 1 times bytes per line |
| +0xa50 | `interleaved` | 1 if progressive; else 1 for interleave mode INTERLEAVED, 0 for SINGLE_FIELD |
| +0xa52 | `ffmode` | the frame-forcing control (ctx 0x6b4) |
| +0xa54 | `line_order` | 1 if the image orientation is bottom-to-top |
| +0xa56 | `line_length` | bytes per line divided by 4 |
| +0xa58 | `field_length1` | video height 1 (ctx 0x458) |
| +0xa5a | `field_length2` | video height 2 (ctx 0x45c), 0 if progressive |
| +0xa5c | `interlace_mode` | result of the library's `determineInterlaceMode` (below) |
| +0xa5e | `progressive` | 1 if temporal sampling is PROGRESSIVE |
| +0xa60 | `msc_increment` | section 2 |
| +0xa62 | `videodominance` | image dominance (ctx 0x474), 0 if progressive |

E for the offsets (the copy and the DWARF member order) and for the library's values. This resolves the DMA note's three unknown flag halfwords: **+0xa50 is `interleaved`, +0xa52 is `ffmode`, +0xa5e is `progressive`** (the DMA note's start step 8 and the interrupt note's field-interrupt step can now be read with those names; the logic they describe is unchanged).
Kernel checks in `xtdigvid_configure_raster` (K30 0x7518, 0x77ac to 0x77e8; E): an odd `line_length` returns EINVAL (22); `progressive` set with `interleaved` clear returns 22; `line_length`, `field_length1` and `field_length2` must each be below 4096.
`determineInterlaceMode` (D 0x416120): the row's own `interlace_mode` member is the default (1 only for the 1035-line row); for a non-progressive path the library computes the standard's default field-2 start line minus field-1 start line and compares it with the path's `videostarty2 - videostarty1`; a smaller default difference gives 0, a larger one gives 1 (E for the compare, **I** for "field order implied by the video start lines"). The kernel compares `interlace_mode` with `videodominance` (`xor` at K30 0x9e88 and 0x9fd0); what that equality selects is **U**.

## 4. Field parity: chosen and reported

1. **Chosen.** The start parity is the library's `initial_device_msc` (even for F1-first and progressive, odd for F2-first; section 2). For an interlaced path the raster block also carries `videodominance`, `interlace_mode` and the two field lengths (section 3); the field lengths are the video heights of field 1 and field 2 as the application set them.
2. **Reported by the board.** The status-ring flag word carries FIF (bit 6) next to F_INTR (bit 7). On each field interrupt of a non-progressive pipe (`progressive` at +0xa5e is 0), after the field counter has been incremented, the service routine compares the counter's low bit with FIF; when they differ it adds one more to the counter, stores the old value in the previous-field counter and (with debug output on) logs "Resyncing device MSC" (K30 0x3a0a4 to 0x3a0d4: `andi 0x40`, `andi 0x1`, `beq`, `daddiu 1`, `sd 2720`, `sd 2752`; E). So in steady state the counter's low bit equals FIF at every field interrupt (E), and a stream that starts with the wrong parity is corrected by one extra increment at the first mismatching interrupt. For a progressive pipe no parity check runs and the counter simply counts interrupts (E).
3. **Polarity.** FIF = 1 goes with an odd counter. With the library's start values that makes FIF = 0 the field the stream starts on for an F1-first stream and FIF = 1 for an F2-first stream. That FIF = 1 means "second field" in the video standard's sense is **I**; the driver names it only "FIF". Settled by the GIF configuration, or a capture of FIF against a known video source.
4. **What the application sees.** The library does not deliver field-interrupt events (the mask excludes 0x100, section 1 step 5; the event's payload is a UST and MSC pair, D `field_intr`). An application learns the parity only from the MSC of each buffer: an even MSC on the first buffer of an F1-first stream (E for the start values, **I** for the reading). The device flag F (bit 1) passed to the completion routine ("dma fbit") is **U**.

## 5. When a pipe runs

The DMA note (section 4) has the register sequence; this is the condition summary (E where marked from that note, I where reasoned).

| Step | Input pipe (1) | Output pipe (0) |
|---|---|---|
| Library gate before the start ioctl | VBOB reports the expected signal (or loopback or a graphics path) | reference locked unless INTERNAL |
| Kernel reset and interrupt enable | pipe reset word 0x6c, control bit 16 (DMA note section 4 bring-up steps 6 and 7) | pipe reset word 0x7c, control bit 16 |
| First buffer | video enable (bit 0 of register 0x80180c) is set **before** the first slot's valid bit | the first slot's valid bit is set, **then** video enable (bit 0 of 0x80200c) |
| Start timer | a 200-tick abort timer (`xtdigvid_dma_abort`) is armed at the video enable and cancelled by the first slot completion; without a completion the transfer is aborted with "no input field interrupts received" | none in the start routine |
| While running | each field interrupt re-arms a signal-loss watchdog (`xtdigvid_siglost_abort`, default 175 ticks) and a stalled pipe is aborted with error word 3 | none |
| Stop | slots drained, video enable cleared, control rewritten without bit 16 | the same; the clear is skipped when the board reported a transfer error |

So a pipe is "running" from the moment its video-enable bit and a slot valid bit are both set and the FIFO is being drained, and the host's own pacing is the field interrupt on the input pipe and the slot completions on both. Whether the board starts clocking pixels at video enable or waits for the first field boundary, and whether the first interrupt after enable is aligned to a field start, is **U**; settled by a capture of the status ring across a start, or the VIF and HDOC netlists.

## 6. The output raster, from the VBOB timing record

The VBOB timing record (VBOB note, kind 3) is built from a timing-table row and the path. The row's members (D `xthdTimingEntry_t`): `progressive`, `width`, `height` (the height of one field for an interlaced row), `frame_rate`, `lines_per_frame`, `samples_per_line`, `f_zero_line`, `f_one_line` (first lines of field 1 and 2), `v_zero_f1`, `v_one_f1`, `v_zero_f2`, `v_one_f2` (first and last-plus-one active line of each field), `sampling_rate` in MHz, `dominance`, `interlace_mode`, `VITC_max`, `VITC_min`, `format`. E for the rows (L `.data` at 0x41c6d0).

Deriving the periods from the record's bytes (record bytes in brackets):
- Line period = samples per line [4, 5] divided by the luma sample clock. The luma clock is 74.25 MHz when [18] = 5, 74.25 / 1.001 MHz when [18] = 4, and 13.5 MHz when [3] = 6 (standard definition; the table's own 27.0 for those rows is the multiplexed Y/C clock, so the luma clock is half of it, **I**). [18] = 1 on a high-definition row means a 148.5 MHz multiplexed row that the library never reaches by a named timing.
- Frame period = lines per frame [8, 9] times the line period.
- Field period = the frame period if the record is progressive (bytes 12, 13 equal lines per frame and 14, 15 are 0), else half of it.
- Active lines per field = [10, 11] and [14, 15]; first active line of each field = [16] and [17] after the field's first line.
- Interlaced or progressive: [14, 15] non-zero means interlaced.

The rows that the named timings reach (E, L 0x41c6d0; "row" is the table row, from `mlToVlTiming`, L 0x407680, jump table L 0x418288; "[16]/[17]" are the bytes 16 and 17; the periods are computed from the row and are I where they rest on 1.001):

| ML | Row | Name | i/p | [4,5] | width | [8,9] | [12,13] | [16] | [17] | [18] | Table `frame_rate` | Frame Hz | Field ms |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 2 | 2 | 525 | i | 858 | 720 | 525 | 266 | 16 | 17 | 1 | 30.0 | 29.970 | 16.683 |
| 3 | 3 | 625 | i | 864 | 720 | 625 | 313 | 22 | 23 | 1 | 25.0 | 25.000 | 20.000 |
| 9 | 9 | 1080 60i | i | 2200 | 1920 | 1125 | 564 | 20 | 20 | 5 | 30.0 | 30.000 | 16.667 |
| 10 | 10 | 1080 5994i | i | 2200 | 1920 | 1125 | 564 | 20 | 20 | 4 | 29.97 | 29.970 | 16.683 |
| 11 | 11 | 1080 50i | i | 2640 | 1920 | 1125 | 564 | 20 | 20 | 5 | 25.0 | 25.000 | 20.000 |
| 12 | 12 | 1080 30p | p | 2200 | 1920 | 1125 | 1125 | 41 | 0 | 5 | 30.0 | 30.000 | 33.333 |
| 13 | 13 | 1080 2997p | p | 2200 | 1920 | 1125 | 1125 | 41 | 0 | 4 | 29.97 | 29.970 | 33.367 |
| 14 | 14 | 1080 25p | p | 2640 | 1920 | 1125 | 1125 | 41 | 0 | 5 | 25.0 | 25.000 | 40.000 |
| 15 | 15 | 1080 24p | p | 2750 | 1920 | 1125 | 1125 | 41 | 0 | 5 | 24.0 | 24.000 | 41.667 |
| 16 | 16 | 1080 2398p | p | 2750 | 1920 | 1125 | 1125 | 41 | 0 | 4 | 23.98 | 23.976 | 41.708 |
| 17 | 24 | 1080 24PsF | i | 2750 | 1920 | 1125 | 564 | 20 | 20 | 5 | 24.0 | 24.000 | 20.833 |
| 18 | 25 | 1080 2398PsF | i | 2750 | 1920 | 1125 | 564 | 20 | 20 | 4 | 23.98 | 23.976 | 20.854 |
| 21 | 28 | 1080 25PsF | i | 2640 | 1920 | 1125 | 564 | 20 | 20 | 5 | 24.0 | 25.000 | 20.000 |
| 25 | 20 | 1035 5994i | i | 2200 | 1920 | 1125 | 564 | 40 | 39 | 4 | 29.97 | 29.970 | 16.683 |
| 26 | 21 | 720 60p | p | 1650 | 1280 | 750 | 750 | 25 | 0 | 5 | 60.0 | 60.000 | 16.667 |
| 27 | 22 | 720 5994p | p | 1650 | 1280 | 750 | 750 | 25 | 0 | 4 | 59.94 | 59.940 | 16.683 |

Notes. The table's `frame_rate` for the 525 row is 30.0, not 29.97, and for the 25PsF row it is 24.0 while its line and sample counts give 25.0 Hz (E for the values; the record carries only the counts and the clock code, so the VBOB sees 25 Hz). The 525 and 625 periods use the 13.5 MHz luma clock (I). The 24PsF and 2398PsF rows are built as interlaced-style rows (two fields of 540 lines) at half the segmented-frame rate's field period. For a custom format the row is ML 10's with its members replaced by the ioctl `0x6864761f` result, and the video heights come from the path (E). The period formulas are arithmetic on E bytes; that the VBOB derives its output raster the same way is **U** (settled by the VBOB operating code, not shipped).

**Detected timing.** A detected signal arrives as a wire timing code in the VBOB replies (VBOB note section 4), which `vbobToMLtiming` turns into an ML number and so into a row of the table above; the row gives its field period. Wire codes with no row of their own (HD 1080i 4795 and 48 report as the PsF rows; wire 9 and 10, 1080p 29.97 and 30, are rows 13 and 12) follow the VBOB note's table.

## 7. Unknowns, with what settles each

| Unknown | Settled by |
|---|---|
| Hardware MSC value at stream start (word 0 of the first status entry) | a capture of the ring across a start, or the GIF configuration |
| What FIF = 1 means in the video standard's terms; what the F flag (bit 1) selects | the GIF configuration, or a capture of FIF against a known source |
| Whether video enable starts the pixel clock at once or at the next field boundary | a capture of the ring across a start, or the VIF and HDOC netlists |
| What equality of `interlace_mode` and `videodominance` selects in the raster routine | reading the rest of `xtdigvid_configure_raster` (K30 0x72cc to 0xa0a0, cord-reordered) |
| VIF 0x1810 bit 5 and the control bit 7 pulse (debug build only) | the VIF netlist |
| Whether the VBOB derives its output raster from the 0x22 record as arithmetic on the clock code | the VBOB operating code (not shipped) |
