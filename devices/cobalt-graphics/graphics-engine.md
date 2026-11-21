# Cobalt rendering engine: register window, packet queue, interrupts

How software feeds the Cobalt rendering engine. Back to the [overview](README.md). Everything here comes from one
place, the Windows NT 4.0 miniport `sgcomp.sys` v5.2.4 and its symbols, read function by function; no public document
describes this block and Linux never drove it (SGI's hardware OpenGL for Linux was a 1999 demonstration that was not
released, per SGI engineers' posts in comp.sys.sgi.admin, 2004). Where a register is named below the name is mine unless
quoted as a symbol. Grades: see the overview.

**Short answer to "FIFO or DMA".** The engine fetches commands by DMA from packet buffers in main memory. The host
builds packets in memory (the memory is the same SDRAM the processors use), links them, and tells the engine which
context to run through one control register; completion and stalls come back as two interrupt causes. There is no
register FIFO that the host pushes words into. Software expectation. The packet format itself is unknown.

## Register window at `0xc8000000` (`0x19000` bytes)

`CobaltInitialize` maps exactly this window (`MmMapIoSpace`, uncached, `0xc8000000`, `0x19000` bytes) before it looks
at the display back end's ID. Accesses seen are 32-bit. Offsets are from the base.

| Offset | Seen as | What software does | Grade |
|---|---|---|---|
| `0x00000` to `0x07fff` | nothing | the miniport never touches this range in the routines read | unknown |
| `0x08000` to `0x0bfff` | 2048 entries of 8 bytes | `CoInitHw`, the tile and texture allocators and `CoBuildTlbPacket` write the low dword of an entry with a 24-bit value (`x & 0xffffff`); entry `i` is at `0x8000 + 8*i`. Entries not in use are filled with the value of the first | software expectation (access), inferred (a translation table from page numbers to memory pages) |
| `0x0c000` to `0x0c1ff` | 64 entries of 8 bytes | at pool setup every entry gets the physical base of the context packet pool (`+4` of the pool descriptor). One entry per context; `0xc010` (context 2) is also rewritten with `(x & 0x1fffff) \| 0x4000000` while building texture-table packets | software expectation (access), inferred (per-context base pointers) |
| `0x10000` | control and status | write: `mode \| (context << 12) \| 0x800` selects the context to run (`pCoContextSwitch`, the retrace and event paths). `CoInitHw` writes `0xfffff040`. Read: bits `[31:12]` are the context the engine is running; software shifts right 12 to get it and treats 0 as "none" | software expectation |
| `0x10008` | doorbell | write `0x400` to restart the engine's scheduler after queuing work | software expectation |
| `0x10018` | interrupt cause | read, mask `0x60000000`, write 0 to acknowledge, then re-read until the cause bits drop. Bit 31 is also polled by `pCoWaitForEvent`: wait for it set, then write `0x7fffffff` | software expectation |
| `0x10020` | interrupt enable | `CoInitHw` writes `0x60000000` (both causes on) | software expectation |
| `0x18138`, `0x18140` | read | read into the packet being built after a header word `0x84e44040`; looks like two 32-bit instrument or occlusion counters | inferred |
| `0x185c0`, `0x185c8` | read | on a stop interrupt, read to find where the engine stopped: two 12-bit values combine into a position that is then converted to an offset in the context's packet buffer (low 20 bits) | inferred |
| `0x185d0` | write | the current-context packet pointer (written when the current context changes or is freed) | inferred |
| `0x18800` | write | a per-context value read from the context record at `+0x500` | unknown |
| `0x19000` end | | | |

Reset values are unknown for all of them. The retrace and engine handlers are the only paths that read status, and both
treat a read of zero as "not mine".

The display back end also uses `0x10000`, `0x10018` and `0x10020` in its own block, at `0xd0000000` (see
[display-engine.md](display-engine.md)). The two windows share offsets, not a register file: the engine's are at
`0xc8010000` and up.

## Interrupts

- **Pin 25 (the "RE" pin): the engine.** `CoInterruptHandler` reads `+0x10018` and returns "not mine" when it reads zero.
  Otherwise it clears the register, waits for the clear to take, and queues an event carrying the cause bits for a
  deferred routine (`CoDPC`, `CoProcessCobaltEvent`). The event processor tests cause `0x40000000` first: if the current
  context was running it flags the context, then reads the running context from `0x10000` (falling back to `0x185c0`
  when that reads zero), and recovers the stop position from `0x185c0` and `0x185c8` to resume from. Cause `0x20000000`
  also queues an event but does not take that path. Software expectation for the use; what each cause means in hardware
  terms is inferred (bit 30 a stop that needs a restart, bit 29 a completion), not published.
- **Pin 24 (the "AS" pin): vertical retrace.** `CoVRetraceHandler` reads the 32-bit register at `0xca000000` and writes
  back its complement. If bit 1 of the value read was set it increments a frame counter and, in the stereo case, reads
  the display back end's `vt_f2rf_lock` and sets bit 6 of its `vt_flags`. It then queues a retrace event, which the
  deferred routine uses to run the swaps and queued work that were waiting for retrace. Software expectation. The
  write-back of the complement is the driver clearing set bits, so the register is write-one-to-clear or latching;
  which, is unknown.

Both pins are on the Cobalt interrupt controller at `0xc4000000`. The miniport asks the HAL for the vector of internal
level 25 and of level 24 (`HalGetInterruptVector`), then connects the engine handler to the first and the retrace
handler to the second with `IoConnectInterrupt`. Software expectation.

## Command interface in main memory

All of this is main-memory data the engine reads (UMA), so an emulator must resolve engine reads of physical RAM; the
engine never needs the host's cache.

- **Packet buffers.** The driver keeps a "render node" (RN) per drawing context, each with one or more packet buffers
  allocated by `pCoAllocatePacketPages` and growing by `pCoExpandPacketBuffer`. A single packet may not cross a
  `grmPacketSize` boundary, which is 128 dwords (512 bytes); the dispatcher chains buffers when a packet would.
  Software expectation.
- **Alignment.** Software pads every packet with zero dwords up to a 32-byte boundary before dispatching it
  (`grmDispatchPacket`, `CoSetGrmPktHeader`). Size and position are counted in 32-byte units after that. Software
  expectation.
- **Link word and ownership.** For each packet the driver also writes one dword into a link table (the RN's table at
  record offset `0x120`) that carries, in units of 32 bytes, the packet's size and the next buffer's position, and sets bit
  0. To wait for the engine to finish with a buffer the driver spins until bit 0 of a header or link dword in memory reads
  clear (`grmDispatchPacket`, the tail of the routine). So bit 0 means "owned by the engine" and the engine clears it.
  The field split of the link word is inferred from two routines and not confirmed: `size/next` in the upper bits, bit 1
  also set by `CoSetGrmPktHeader`.
- **Per-context shadow.** Every new context starts from a 208-dword packet (`CoInitShadowRam` copies the table
  `initialCxShadow`, 19 pairs of header word and dword index, into the RN's packet area) that holds default state. The
  headers, in order of position, are: `0x80003020` (index 0), `0x046400c0` (2), `0x05260480` (9), `0x09a900c0` to
  `0x09a900c3` (`0x2e`, `0x35`, `0x3c`, `0x43`: four packets seven dwords apart), `0x0ca96120` to `0x0ca96123` (`0x4a`, `0x54`,
  `0x5e`, `0x68`: four of ten dwords), `0x1129f020` to `0x1129f023` (`0x72` to `0x78`: four of two), `0x91aa0220` (`0x7a`),
  `0x93cc0340` (`0x8c`), `0x00210440` (`0xa7`), end at `0xd0`. The four-times structure with the low two bits counting
  0 to 3 matches the datasheet's four hardware lights; that is inferred, no source names the packets. Software
  expectation for the table's contents.
- **Header words seen elsewhere.** Packet builders in the driver and in the OpenGL driver store header dwords of the form
  `0x9880_4000`, `0x8000_3020`, `0x84e4_4040`, `0x99ce_00a0`, `0x9865_c020`, `0x9700_0020`, `0x9700_0040`, `0x9700_0060`,
  `0x91aa_0020`, `0x91ea_2040`, `0x93cc_0080`. The low byte tracks the packet's length in 32-byte units times 32
  (`0x20`, `0x40`, `0x60`, `0xa0`, `0x80` seen), and a family (`0x97...`, `0x98...`) repeats with different lengths. So the top
  bits look like an opcode and the low bits a size. Inferred; the opcode list is unknown.
- **Texture-table packets.** `CoBuildTlbPacket` builds a packet that loads engine table entries (the `0x8000` window) from
  a list of memory pages for a texture; `CO_CREATE_TEXTLBPKT`, `CO_FREE_TEXTLBPKT` and `CO_SET_READY_TEXTLBPKT` are the
  commands the OpenGL driver uses to ask for one. Whether the table is walked by the engine or loaded by it from the
  packet is unknown.
- **Host-side scheduler.** The miniport multiplexes contexts in software: per-context work queues ("drops" and "chunks"),
  a round-robin timer, a wait-on-completion timer, an idle timer, a serialised queue that is drained after each
  vertical retrace, and a swap that is scheduled to happen at retrace (`CoScheduleSwap`) or immediately for unsynchronised
  swaps. Registry values `IdleOnOpenGL`, `IdleOnGDI`, `IdleOnGDIwithOGL`, `IdleOnD3D` and `SchedulerMode` tune it. None of
  this is hardware, but it shows what the hardware cannot do: there is no hardware context queue, only one running
  context at a time, selected by `+0x10000`.

## What is not known

Opcode set and packet layouts; the contents of `0x00000` to `0x07fff` and `0x0c200` to `0x17fff`; what `0x8000` entries
and `0xc000` entries are in hardware terms; what the engine does on each interrupt cause; whether the engine reads the
packet buffers by physical address or through the `0x8000` table; reset values; the Z and stencil buffer layout; how
the engine writes pixels into the display back end's tile lists (the miniport hands it the same lists it gives the
display, see `pAllocateTilesForBuffer`). The route is the OpenGL driver `sgcoicd.dll`, whose setup code is a software
implementation of the geometry pipeline that ends by writing packets; reading its packet emitters in full (see
[the open questions](../../questions/cobalt-graphics-open.md)).
