# DM2 (XT-DIGVID): the DMA start path in `xtdigvid_dma`

Status: **contract part, not independently reviewed.** Labels follow [AGENTS.md](../../AGENTS.md):
**E** established, **I** inferred, **U** unknown. It extends section 4 of the
[scoping datasheet](../xio-dmediapro-dm2.md), which said the body of `xtdigvid_dma` was unread, and corrects
three of that page's statements (section 8). Register offsets are from the widget PIO window base, as in the scoping page.
The GIF register list (start addresses, raster words) is a sibling part; this page lists only what `xtdigvid_dma` itself stores.

## Sources

| Tag | Object | sha256 |
|---|---|---|
| O30 | `usr/cpu/sysgen/IP30boot/xtdigvid.o` of the DMediaPro DM2 software 1.1.3ml set | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` |
| O27 | same set, `IP27boot/xtdigvid.o` | `138ab5488ed6263b14582c61cf324a79929459ba62f29f92113fed36630f38ae` |
| O35 | same set, `IP35boot/xtdigvid.o` | `64c024a59b6b1dd7962af6d7857e83ff93ef29e498816b91c524a4d00fab1976` |

Every address below is an offset into `.text` of O30 unless an object is named. The objects are relocatable ELF64 big-endian;
calls and data references are relocations, so a symbol load is a six-instruction `lui/daddiu/lui/dsll32/daddiu/dadd` group and
`jalr`. I read the disassembly (`mips64-linux-gnuabi64-objdump -dr`, run in the retools container), with the relocations
folded into the instructions and the trace blocks (below) folded to one line. The Ghidra decompiler could not produce
output for this function (its response buffer overflowed after 108 s), so no decompiled text was used even for navigation.
The three builds agree in structure; where I compared them it is stated.

## 1. What the routine is

**E.** `xtdigvid_dma(pipe, request)` is the whole per-pipe streaming loop, not a single "start DMA" step. It is called
from `xtdigvid_ioctl` (symbol load at 0xd34c, `jalr` at 0xd35c; first argument `board + 0x50 + pipe_index * 0xa368`, second a copy of the ioctl argument).
It runs until the stream ends and returns an errno. Its symbol covers 0x15878 to 0x2d544 (97,484 bytes). Two further routines follow
it with no symbol of their own: the FIFO callback at 0x2d544 to 0x2e368 and a 24-byte status classifier at 0x2e368
(section 6). They are not inside the symbol, contrary to the scoping page's wording.

**E.** About 80% of the symbol is trace logging. 218 compiler-inlined blocks, each guarded by `lh r,0(xtdv_dump_event_log_types); andi; beq`,
take a timestamp, a spin lock and an entry in a per-CPU history ring; their guard-to-join spans add up to 79,480 bytes (0.815 of 97,484, counted by a script
from branch-target distance, so approximate). They touch no board register. The strings they carry ("in: PIPE_RESET",
"out: programming both valid bits now.", ...) come in an in/out pair per site, chosen by pipe index, and give the event
names used below. Their source order is the order of the strings' embedded line numbers, which is how the sequence in section 4 was put in order,
since the compiler laid the cold blocks out of order.

**E.** Pipe index is `(pipe - board - 0x50) / 0xa368`: 0 is the "out" pipe (host to board), 1 the "in" pipe. The `dms_*` calls name the
host-side buffer FIFO the ML layer fills.

## 2. Map RAM (E unless marked)

Entries are 32-bit words at `0x100000 + 4 * (board_dma_address >> 14)`. A board DMA address is therefore a 16 KiB-page index into a
flat table. `xtdigvid_write_mapram(board, page_list, count, board_dma_address)` (0x2e3ec) writes `count` entries starting at the
entry for `board_dma_address`; every store is followed by `sync`. Per entry, with `v` the list element (the system DMA
address of one 16 KiB page, shifted right 14):

| Bits | Value written | Grade |
|---|---|---|
| 29 | 1 in every valid entry (`0x20000000`) | E |
| 28 | 0 in valid entries; 1 in invalidated ones | E |
| 27:2 | `v & 0x3ffffff` (the page number's low 26 bits, shifted left 2) | E |
| 31:30, 1:0 | 0 | E |

The assertion in the object, `(*page & ~XG_MAP_RAM_PPN_MASK) == 0`, tests `v & 0xf0000000` (0x2e440, 0x2e470); the shifted-and-masked store
(0x2e484 to 0x2e49c) is `(((v & 0x0fffffff) << 2) & 0x0fffffff) | 0x20000000`, equal to the scoping page's `(v & 0x3ffffff) << 2 | 0x20000000`.
`xtdigvid_invalidate_mapram(board, n, board_dma_address)` (0x2e380) writes `n` consecutive entries, the i-th as `0x10000000 | (n - 1 - i)`, so a
single invalidated page is exactly `0x10000000`. The three builds have identical code for both routines apart from branch targets and one string offset in an assertion.

What the words mean beyond the stores:

- **I.** `v` is the address the kernel's crosstalk DMA mapping returns for each page (section 4, step 5), so bits 27:2 hold address bits 39:14
  of the system DMA address. The routine never adds a widget or attribute field, and 26 bits is all that is kept. Whether the hardware reads bits 1:0
  or the top bits as page attributes is **U**: nothing reads an entry back.
- **I.** Bit 28 marks "invalid" and the counter below it is only the run length left; the XG error cause bit 13 "map RAM invalid" (scoping page, section 5)
  is the observable effect, with the entry address in the register at `0x94`. Which bit pattern the hardware tests is **U**.
- **E.** Entries are written as one big-endian 32-bit PIO store each, with no byte swapping in the driver. The byte order the board's logic applies to that store is **U**:
  software cannot see it and no routine reads an entry back.

### Layout of the board DMA address space (E for the formulas, I for the reasons)

For slot `k` (0 to 3) of a pipe the routine builds the board address as `k << 24` (`sll a4,a4,0x18`, 0x21be8), plus `0x4000000` for pipe 0 (0x27c7c, 0x29e2c, 0x2a820):

| Pipe | Slot k window | Entries |
|---|---|---|
| 1 (in) | `k * 0x1000000`, 16 MiB each, 0x0 to 0x3ffffff | `k * 1024` to `k * 1024 + 1023` |
| 0 (out) | `0x4000000 + k * 0x1000000`, up to 0x7ffffff | `4096 + k * 1024` and up |

Together with the status pages at 0x8000000 and 0x9000000 and the invalidated pages 0x7ffc000 and 0x8ffc000 that `xtdigvid_init_gif` sets up (scoping page, section 4),
this fills the table's index range up to at least 0x9000000 >> 14. The size read from the configuration word at `0x64` (scoping page, section 2) is **U**; whether it covers that range is not checked.

- **E.** A slot's mapping is limited to 1024 pages: the size is rejected above `0x1000000` bytes (0x210e0; error 7, message "too-large transfer size") and the page count is checked `<= 1024` (0x21110 to 0x2111c, an assertion).
  The page-list buffer is `kern_malloc(4096)`, 1024 words (0x16894).
- **I.** The 16 MiB window equals the 24-bit range of the raster start addresses the configuration code validates ("start_addr1 out of range"). So the offset programmed in the GIF is an offset inside the slot's window, and the window base is implicit in which slot's valid bit is raised. No store in this routine programs an address.
- **E.** Guard pages: after writing a slot's entries the routine invalidates one page before the buffer, at `board_address - 0x4000` (only when `board_address >= 0x4000`; 0x254e4 to 0x25524),
  and one page after it, at `board_address + page_count * 0x4000` (0x25550 to 0x25580).
  An unmapped access then fails with the map-RAM-invalid error instead of reading a neighbour. **I (hazard):** for a full 1024-page buffer in slot 0 of pipe 0 the "before" page is the last page of pipe 1 slot 3, whose entry it overwrites. Whether callers ever fill a slot completely is **U**.
- **I.** The page loop takes one list element per 16 KiB chunk and counts chunks as `(size + 16383) >> 14` (0x216b0 to 0x216b8), ignoring the offset of the buffer inside its first page, and the entry carries no sub-page offset. So the driver can only be correct for 16 KiB-aligned buffers. Whether the ML layer guarantees that is **U** (settled by the allocation path in `libdigvid.so`).

## 3. Registers `xtdigvid_dma` stores to

Eleven store sites (ten in O30), all with `sync` after, plus the map RAM entries. No site reads a board register back. All through `board + 0x18` (the mapped window base).

| Offset | Pipe 0 (out) | Pipe 1 (in) | Stored | Site (O30) | Grade |
|---|---|---|---|---|---|
| DMA control | `0x800014` | `0x80003c` | `shadow \| bits` (section 3.1) | 0x16e54, 0x1ae04, 0x25630, 0x25674, 0x2a380 | E (offsets), I (bit roles) |
| reset word | `0x80007c` | `0x80006c` | 0 | 0x16c1c | E (store), U (meaning) |
| video control | `0x80200c` | `0x80180c` | video-control shadow (`pipe+0xa0c`), bit 0 set or cleared | set 0x29fc4 / 0x27e24; clear 0x2249c / 0x21fec | E (stores, bit 0), U (other bits) |
| map RAM | `0x100000 + 4*(addr>>14)` | same | section 2 | via 0x2e3ec, 0x2e380 | E |

Pipe assignment: the control and video-control offsets follow the pipe-index test (`sltiu pipe,1`, `movz/movn`; 0x16e38, 0x1adcc, 0x2a36c, 0x27c8c). The same test selects 0x6c for pipe 1 and 0x7c for pipe 0 (0x16bf0 to 0x16c08).
That agrees with `xtdigvid_init_gif`, which writes `0x64` for pipe 1 and `0x74` for pipe 0 (0x6154 to 0x6194; the scoping page listed the pair without saying which pipe owns which), so each pipe has a word at `0x64/0x74` cleared at status-buffer setup and one at `0x6c/0x7c` cleared at pipe reset.
The pairing of "in" with VIF (video in, `0x80180c`) and "out" with HDOC (`0x80200c`) is I, from the trace names "VIF_DMA_ENABLE" and "HDOC_DMA_ENABLE" on the two paths; nothing else names the two registers.

### 3.1 The DMA control word (pipe + 0xa08 holds its shadow)

- **E.** Bits 3:0 are the per-slot valid bits and bit 4 is the abort bit, together named in the object's assertion
  `!(pipe->gif_dma_control_shadow & (XTHD_GIF_IDMA_CONTROL_DMA_VALID_MASK | XTHD_GIF_IDMA_CONTROL_DMA_ABORT_MASK))`, compiled as `lw 0xa08; andi 0x1f; bne` (0x255ac to 0x255b4). The shadow therefore never holds them: the driver ORs them into a value it writes and never into the shadow.
  The valid bits are one per slot because the single-slot write is `(1 << slot) | shadow | 0x10000` (0x2a350, 0x2a378 to 0x2a380).
- **I.** Bit 16 (`0x10000`, kept in `pipe + 0xa74`) is the interrupt enable: it is stored as 0x10000 at "PIPE_RESET" (0x16c64), written into the control word at "INTR_ENABLE" (0x16e50 to 0x16e58), and zeroed (0xa74 cleared, then the bare shadow written) at the end together with a software event (0x1add4 to 0x1ae0c). The trace names say so. The XG's own interrupt enable is a different bit (control, bit 17, scoping page).
- **I.** The valid bits are write-one-to-set latches, not a level held in the register: the "programming both valid bits" path writes two words in a row, each with exactly one valid bit, and the only way both slots end up armed is if the first survives the second write. Nothing reads the control word back, so this is the single inference the start protocol rests on. Reset value, readback and the behaviour of writing 0 to a valid bit are **U**; a register capture of a running board is the only route, and that is a physical test under the repository's agreement rule, or the entry can be recorded as "model-author choice".
- Other bits of the shadow (`0x1000`, `0x400`, `0x200` and the initial `0xea040` / `0xa040`) are set by `xtdigvid_configure_raster` with load-linked/store-conditional updates and are outside this routine. The abort bit written elsewhere is `shadow | 0x10` (`xtdigvid_dma_abort`, 0x14bcc), without bit 16.

## 4. Sequence

Pipe-private state used below (driver memory, not hardware): `pipe+0x834` next slot index (counts mod 4), `+0x838` completion-order slot counter (mod 4, advanced by the
interrupt side at 0x3720c), `+0x83c` pending slot (-1 for none), `+0x82c` "streaming started" flag, `+0xa00` error word, `+0xa08` control shadow, `+0xa0c` video-control shadow, `+0xa74` interrupt-enable bits, `+0xad0` flags (bit 4 = done, from the object's own name `XTHD_PIPE_FLAGS_DONE`),
and four slot records from `pipe+0x840`, stride 0x60: `+0` status, `+8` pinned user address, `+0x10` slot semaphore, `+0x20` slot index, `+0x38` crosstalk DMA map, `+0x50` length, `+0x58` direction word.

Bring-up, in order (E):

1. `psema(pipe+0x9c0, 286)` (0x15afc) serialises callers on the pipe; interrupted returns its error.
2. A zero FIFO argument in the request prints "dma missing fifo argument" and returns 22 (0x15e5c to 0x15e90).
3. UST sanity and re-initialisation (0x160c8, 0x16114 to 0x16138). Not a DMA step; see the scoping page's UST notes.
4. `alenlist_create` (0x167cc), `dms_open` (0x167f4), `dms_fifo_attach` (0x16828), `dms_fifo_cache_policy(handle, fifo, 2, 0)` (0x16858), `kern_malloc(4096)` for the page list (0x16894), `dms_set_callback` with the FIFO callback at 0x2d544 and the pipe as cookie (0x168e8).
5. Each of the four slot records is cleared (status 0, slot index -1, length 0, address 0) and its semaphore normalised by a `valusema`/`vsema`/`psema` loop (0x16910 to 0x16a48). **I:** the target count is 1, meaning "slot free".
6. **PIPE_RESET (0x16be8 to 0x16c44):** store 0 to `0x80007c` (pipe 0) or `0x80006c` (pipe 1), `sync`; then `+0x838 = 0`, `+0x834 = 0`, `+0x83c = -1`, and post software event 1. **I (weak):** the register restarts a completion-order slot counter in the board that the driver mirrors in `+0x838`, since the driver zeroes its own counter next to the store and the interrupt side advances that counter mod 4 on completions.
7. **INTR_ENABLE (0x16e2c to 0x16e58):** control = `shadow | 0x10000`.

Per buffer, in source order (the trace events are the evidence for order; each step names the code that implements it):

1. **Next block.** `dms_fifo_deq` (0x2614c). Error value 16 means "none ready": the routine sleeps in `sv_wait_sig(pipe+0x9d8, mutex pipe+0x9e0, 30)` (0x23ce4) until the FIFO callback signals. Any other nonzero value is returned. E.
2. **Slot.** `slot = next_index & 3` (0x1d758); `psema(slot semaphore, 286)` (0x1d8fc). With the count normalised to 1 (step 5 above), this blocks until the previous use of the slot has completed. **I.**
3. **Recycle.** When the slot status is 2, `undma(address, length, direction)` unpins the old buffer, then address and status are cleared (0x26ab4 to 0x26adc). Then `xtalk_dmamap_done(slot map)` (0x20790) and `swap_int64(pipe+0xa00, 0)` (0x207b0), which reads and clears the error word (trace "error_status1"). E.
4. **Pin.** Length above 16 MiB: error 7. Otherwise record length, direction word (1 on pipe 0, 0 on pipe 1: `(pipe == 0)`, 0x21150), address and slot index in the slot; `userdma(address, length, direction, 0)` (0x274a4); on success the status becomes 1 (0x21620). A nonzero `userdma` result is returned. E.
5. **Page list.** `alenlist_clear`; `uvaddr_to_alenlist(alist, address, length, 2)` (0x21640); `xtalk_dmamap_list(slot map, alist, 4)` (0x21670); `alenlist_cursor_init`; then `page_count` calls of `alenlist_get(alist, cursor, 16384, &address, &length, flags)` (0x216e4), storing `address >> 14` (signed shift) into the list. Failures: alist null 22, dmamap_list failed 22, alenlist_get failed 22, page-list allocation 12. E.
6. **Input pipe, first buffer only: video-in enable.** When `+0x82c` is 0 and the pipe is input: set bit 0 of the video-control shadow, store it to `0x80180c`, `sync` (0x27cb4 to 0x27e28). Then `+0x82c = 1` and the abort timer is armed: `fast_itimeout(xtdigvid_dma_abort, pipe, 200, plhi)` with the id kept at `pipe + 0xa360` (0x27fdc to 0x28004; the tick unit is **U**). This is the only timer armed in the routine, so the output pipe has none here. E. The output pipe skips this step.
7. **Map RAM.** `xtdigvid_write_mapram(board, page_list, page_count, slot_window_address)` (0x21c0c), then the two guard-page invalidations (section 2). A nonzero return becomes error 5; the routine always returns 0 in all three builds, so that path is dead (E).
8. **Start: valid bit.** The write depends on three halfword flags that `xtdigvid_configure_raster` sets (`pipe+0xa50`, `+0xa52`, `+0xa5e`; meaning **U**):
   - if (`+0xa5e != 0` or `+0xa50 != 0`) and `+0xa52 == 0`: one write, `control = (1 << slot) | shadow | 0x10000` (0x2a338 to 0x2a384);
   - otherwise (replicate-a-field mode, trace "Need to replicate another field"): if no slot is pending, remember this slot in `+0x83c` and write nothing (0x2a318 to 0x2a334); if one is pending, write `control = (1 << this_slot) | shadow | 0x10000` and then `control = (1 << pending_slot) | shadow | 0x10000` (0x255f8 to 0x25678, trace "programming both valid bits now."), each followed by `sync`, then clear `+0x83c` to -1 (0x25ae4).
   Then `next_index = (next_index + 1) & 3` (0x25af4). E for the branch structure and writes; the flag meanings and the replicate-mode reading are **I**.
9. **Output pipe, first buffer only: video-out enable.** After the valid bit, if `+0x82c` is 0 and the pipe is output: set bit 0 of the shadow, store it to `0x80200c`, `sync`, set `+0x82c = 1` (0x29e5c to 0x29fc8, 0x2a158). E. So input enables video before DMA is armed, output arms DMA before video: **I** (the reason is presumably to fill the output FIFO first, not stated).
10. The loop test: the pipe flags word `+0xad0` is tested for bit 4 at 0x16ee4 (E); the FIFO callback sets that bit by load-linked/store-conditional at 0x2dcd4 to 0x2dce0 when bit 0 of the FIFO's user word is set, and signals `sv_signal(pipe+0x9d8)` (E). That the bit ends the loop, and that it marks the FIFO's last block, is **I** from the object's name `XTHD_PIPE_FLAGS_DONE` on the trace event at that test.

Termination (E unless marked):

1. Outstanding slots are drained: for each slot `psema(slot semaphore, 286)` (0x18454); an interrupted wait prints "Interrupted during dma, waiting..." and retries after `delay(drv_usectohz(200000))` (0x19544 to 0x19570). Then `undma` of any pinned buffer (0x17de4 and 0x178c0).
2. `swap_int64(pipe+0xa00, 0)` once more ("error_status2", 0x1a09c); the classifier at 0x2e368 returns 2 when bit 0 of that word is set and 0 otherwise. A nonzero result sets the return value to 5, replacing any earlier errno (0x1a6d8 to 0x1a6e4, `movn`), and sets a local "error bit seen" flag; a word equal to exactly 3 sets a local "signal lost seen" flag (0x1a3a0 to 0x1a3d4). Both flags are sticky across the two reads.
3. Self-abort, trace "dma: video abort". Taken when the routine is leaving with a nonzero errno and neither flag from step 2 is set, so the board reported no cause of its own (0x1a8b8 to 0x1a8c4, then the block at 0x21cb4). O27 and O35 then store `shadow | 0x10` to the control register and sync (O27 0x2234c, O35 0x21de4) and set `pipe+0x9d0` to 1. **O30 has no such store**: its block at 0x21e08 to 0x21e34 only sets `pipe+0x9d0`. See section 7.
4. Video enable off: if the pipe had streamed (`+0x82c`), clear bit 0 of the shadow and store it to `0x80180c` (input; 0x21fcc to 0x21ff0) or `0x80200c` (output; 0x2247c to 0x224a0). The output store happens only when the "error bit seen" flag is clear; the input store when that flag is clear or the "signal lost seen" flag is set (0x1ad98 to 0x1ada0, 0x21fc0, 0x268fc). **I:** the interrupt-side abort already stopped the video path in the skipped case.
5. Interrupts off: `pipe+0xa74 = 0`, control = bare shadow, `sync`, post software event 2 (0x1add4 to 0x1ae0c).
6. Free the page list and the FIFO attachment (`alenlist_destroy`, `dms_set_callback(0)`, `dms_close`, `kern_free`), `vsema(pipe+0x9c0)`, clear counters, return the errno (0x1ae30 to 0x1af60).

## 5. Completion signalling

- **E (host side).** The routine never reads a board register to learn that a slot finished. It waits on the slot semaphore: at reuse (step 2), at drain, and in the interrupted-wait retry.
- **E (releaser).** Completion is set by code outside `xtdigvid_dma`, in the video interrupt code that follows the `xtdigvid_siglost_abort` symbol. Both video interrupt handlers call the unnamed service routine at 0x34b9c, which calls an unnamed routine at 0x2ea60 (call at 0x36e74). That routine stores `(status & 4) | 2` to the slot status (0x31df8 to 0x31e08) and calls `vsema(slot semaphore)` (0x320fc); an abort path in it calls `vsema` too (0x2effc, after posting software event 32 at 0x2efe0). The interrupt service itself belongs to a sibling part.
- **I.** Slot status values: 0 free, 1 armed (buffer pinned and mapped), 2 completed. Bit 2 (value 4) is set on the previous slot at 0x21188 when this buffer follows a pending one and is preserved at completion; the assertions accept status 1 or 5 where a slot is about to be reused and exactly 1 at cleanup. The status ring in host memory the board writes (scoping page, section 4) is what the interrupt side reads to decide which slot completed; its layout is not touched here.
- **I.** Bound on in-flight buffers: the counter `pipe+0xaa8` is incremented under the mutex and asserted `< 6` (0x2337c to 0x233a8), which matches the assertion text `num_outstanding_dmas <= XTHD_VIDEO_DMA_DEPTH+1` with `XTHD_VIDEO_DMA_DEPTH` = 4, the number of slots. The 4 follows from the arithmetic of the compiled compare, not from a stored constant.

## 6. Error handling

| Condition | Where | Result | Grade |
|---|---|---|---|
| Missing FIFO argument | 0x15e5c | message, 22 | E |
| Interrupted semaphore waits | 0x15b10, 0x1d90c, 0x23cfc | the wait's own error (4 on the cleanup path, 0x18790) | E |
| Transfer over 16 MiB | 0x210e0, 0x26b34 | message "too-large transfer size", 7 | E |
| `alenlist_create`, `dms_open` fail | 0x2ba7c, 0x2c0dc | message, 5 | E |
| `dms_fifo_attach` fails | 0x1683c | its result | E |
| Page-list `kern_malloc` fails | 0x2c140 | "Unable to alloc pagelist", 12 | E |
| `uvaddr_to_alenlist` null, `xtalk_dmamap_list` or `alenlist_get` fail | 0x2cf44, 0x2d118, 0x2ba48 | messages, 22 | E |
| `userdma` fails | 0x274b8 | its result | E |
| Invalid FIFO buffer type | 0x2d158 | "invalid fifo buffer type %d", 22 | E |
| Board error word bit 0 at end | 0x1a6d8 | 5 | E (the test), I (that bit 0 is a hardware error) |
| Error word equal to 3 | 0x1a3a0 | "signal lost" flag: no self-abort, and the video-off store is kept on the input pipe | E (flow), I (names) |
| Leaving with an errno and no board-reported cause | 0x1a8b8 to 0x1a8c4, 0x21cb4 | self-abort store in O27 and O35 only | E |

**E.** The error word `pipe+0xa00` is written only by compare-and-swap from zero, so the first cause wins: `xtdigvid_siglost_abort` stores 3 (0x2e7ec to 0x2e804), and the service routine at 0x34b9c does the same with a value derived from the status it read (0x3581c). `xtdigvid_dma` reads and clears it with `swap_int64`. The routine cannot tell hardware error causes from each other: it sees only 0, bit 0, and the value 3.
Hardware error causes reach the XG error handler instead (scoping page, section 5); that handler is not part of this routine.

## 7. Build differences (E)

- O27, O35 and O30 have identical stores, call sequences and sync ordering except one site. The "dma: video abort" block (section 4, termination step 3) stores `shadow | 0x10` to the pipe's control register and syncs in O27 (0x2234c) and O35 (0x21de4), and not in O30 (0x21e30). O30 has 10 sync sites in the symbol, the others 11, and one `ori 0x3c` fewer.
- **U.** Whether this is a deliberate platform difference (a workaround for the Octane2's XIO path, or a defect on the Origin builds) is not stated; it is the only observable difference in the DMA start path between boards, and a model that runs the IP30 driver will never see the abort write from `xtdigvid_dma`. `xtdigvid_dma_abort` stores the same `shadow | 0x10` in all three builds (O30 0x14bcc), so the abort bit is still reachable on IP30.
- The CPU-id load in the trace code differs (O30 `-15456`, O27 `-15328`); not a board effect.

## 8. Corrections to the scoping page

1. Section 4 says the bodies of the DMA start and interrupt service are "inside one 97,484-byte symbol". The interrupt service is not in `xtdigvid_dma`: it sits after `xtdigvid_siglost_abort` (unnamed routines at 0x2ea60 and 0x34b9c, in 0x2ea60 to 0x3d180). `xtdigvid_dma` is the streaming loop plus its start path, and ends at 0x2d544.
2. Section 4 lists the slot programming "at `0x180c`, `0x200c` and nearby" as a descriptor format the host writes. Those two words hold a bit-0 video enable and nothing else in this routine; the slot is armed by a valid bit in the DMA control register and no descriptor words are stored here.
3. Section 2 lists `0x800064` and `0x800074` without a pipe. Pipe 1 owns `0x64`, pipe 0 owns `0x74`; the words at `0x6c` (pipe 1) and `0x7c` (pipe 0) are the ones this routine clears.
   Three sites agree: `xtdigvid_init_gif` (0x6154 to 0x6194), the clink-timeout path of `xtdigvid_ioctl` (`sltiu pipe,1` at 0xbfc0, `movz` at 0xbfe4, store at 0xbffc) and this routine (0x16bf0 to 0x16c1c) all select the lower offset of each pair for pipe 1 and the higher for pipe 0. `movz` moves when its test register is zero, and the test register is 1 for pipe 0, so pipe 0 keeps the higher value. The [VBOB part](vbob.md) (step 5 of its kernel handler) names `0x800064` for pipe 0 and `0x800074` for pipe 1, the opposite assignment; the code at 0xbfc0 to 0xbfe4 gives `0x800074` for pipe 0. That statement needs its `movz` reading rechecked.

## 9. Unknowns and what settles each

| Unknown | What settles it |
|---|---|
| Whether the valid bits latch, reset value and readback of the control register | no shipped code reads it. A capture of a board's control word, or a model-author decision recorded as such |
| Meaning of `0x6c/0x7c` and `0x64/0x74` | the interrupt service routine's use of `pipe+0x838` and the status-ring code; software route in the same object |
| Meaning of bits 1:0 and 31:30 of a map-RAM entry, and what hardware tests for "invalid" | no software reads an entry back. Only a hardware capture or a model-author choice |
| Byte order the board applies to a map-RAM store | same |
| Roles of the three raster flag halfwords at `pipe+0xa50`, `+0xa52`, `+0xa5e` | `xtdigvid_configure_raster` (0x72cc) and the ML module's raster setup in `libdigvid.so` |
| Whether the IP30 build's missing abort store is deliberate | the diagnostics programs, or a boot of both drivers; no shipped text states it |
| 16 KiB alignment of user buffers, and whether a full 1024-page slot is ever used | the ML module's buffer allocation in `libdigvid.so` |
| Timer tick unit of the 200 passed to `fast_itimeout` | the kernel's timer API, not shipped with the driver; or the timeout's observed duration |
| Map RAM size against the used index range | the register at `0x64`, not decoded |
