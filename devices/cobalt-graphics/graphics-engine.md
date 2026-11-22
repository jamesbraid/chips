# Cobalt rendering engine: register window, packet queue, interrupts

How software feeds the Cobalt rendering engine. Back to the [overview](README.md). Everything here comes from one
place, the Windows NT 4.0 miniport `sgcomp.sys` v5.2.4 and its symbols, read function by function; no public document
describes this block and Linux never drove it (SGI's hardware OpenGL for Linux was a 1999 demonstration that was not
released, per SGI engineers' posts in comp.sys.sgi.admin, 2004). Where a register is named below the name is mine unless
quoted as a symbol. Grades: see the overview.

**Short answer to "FIFO or DMA".** The engine fetches commands by DMA from packet buffers in main memory. The host
builds packets in memory (the memory is the same SDRAM the processors use), links them, and tells the engine which
context to run through one control register; completion and stalls come back as two interrupt causes. There is no
register FIFO that the host pushes words into. Software expectation. The header-word count field and the chaining packet are now known ([below](#how-the-opengl-driver-builds-and-submits-packets-sgcoicddll-524)); the opcode set is not.

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
  The field split of the link word is now read from both builders ([below](#how-the-opengl-driver-builds-and-submits-packets-sgcoicddll-524)): length in bits 11:3, next position in bits 31:12, flags in bits 2:1.
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

## How the OpenGL driver builds and submits packets (`sgcoicd.dll` 5.2.4)

Read in Ghidra from the shipped 5.2.4 NT 4.0 package with SGI's symbols (the ICD `sgcoicd.dll`, the display driver `sgcodd.dll`
and `sgcomp.sys`), checked against the miniport reading above. Grades: *established* is what the driver code does, read in full for
the routine named; the hardware's reading of any word is a software expectation, as above.

**The path, end to end. Established.**

1. The OpenGL driver runs in the application's process. It writes packets straight into packet-buffer memory that the kernel
   side mapped for it (it never touches an engine register; those are at physical addresses only the miniport maps).
2. To make work visible to the engine it calls `ExtEscape` (through `__glCoExtEscape`, `0x69018322`) with one of the escape codes
   below. The display driver's `DrvOpenGLEscape` checks the arguments (`checkargs`, with the escape's name and input size) and
   `IsUserPktOffset` verifies that the position the application passed lies inside the context's own packet buffer, then
   allocates a "drop" (`CoGrmAllocateDrop`) on the context's render node and calls the driver's queue entry.
3. The miniport's scheduler runs the drops in order (`CoExecuteDrop`, `CoScheduleDrop`): drop types 1 finish, 2 screen-to-screen copy,
   3 pixel DMA, 5 serialisation mode, 6 kick (only clears a "pending" flag on the render node), 7 and 8 bind and unbind buffers, 9
   unsynchronised swap; types 0 and 4 complete at once. The engine itself is started by the context switch described above (the
   `0x10000` write), not by the escape.
4. Completion is learned by the application polling the packet buffer (below), blocking on a kernel event, or both.

**ICD escape codes. Established (`DrvOpenGLEscape`; name, input size in bytes).**

| Code | Name | Size | Code | Name | Size |
|---|---|---|---|---|---|
| `0x40` | SETCONTEXT | `0x54` | `0x50` | CACHEOP | `0x24` |
| `0x41` | FIRSTSETCONTEXT | `0x2c` | `0x51` | PIXELDMA_CLEANUP | `0x7c` |
| `0x42` | CREATECONTEXT | `0x20` | `0x52` | SETUP_SCR2SCR | `0x7c` |
| `0x43` | DELETECONTEXT | `0x14` | `0x53` | CREATE_BUFFER | `0x28` |
| `0x44` | RELEASECONTEXT | `0x14` | `0x54` | FREE_BUFFERS | `0x40` |
| `0x46` | SHARELISTS | `0x1c` | `0x55` | BIND_BUFFERS | `0x70` |
| `0x47` | DESCRIBELAYERPLANE | `0x20` | `0x56` | UNBIND_BUFFERS | `0x6c` |
| `0x48` | SWAPBUFFERS | `0x7c` | `0x57` to `0x59` | CREATE, FREE, SET_READY of a texture-table packet | `0x44`, `0x40`, `0x40` |
| `0x4b` | SETLAYERPALETTEENTRIES | `0x28` | `0x5a`, `0x5b` | CREATE_PBUFFER, DELETE_PBUFFER | `0x50`, `0x1c` |
| `0x4c` | FINISH | `0x18` | `0x5d` | PIXELFORMATEXTDESCRIBE | `0x20` |
| `0x4d` | KICKSCHEDULER | `0x7c` | `0x60` to `0x62` | WAIT_FOR_HARDWARE, ALLOC_PACKET_BUFFER, FREE_PACKET_BUFFER (the order of the three names against the codes was not matched; the ICD's wait is `0x62`) | `0x18` |
| `0x4e` | CLEARBUFFER | `0x7c` | `0x4f` | PIXELDMA | `0x7c` |

**Packet buffers. Established.** `InitCoPktBuffer` (`0x690186f2`) links a ring of nodes (a 40-byte descriptor each, count and size from the
context) over one block of memory. In each node's buffer the data starts `0x20` bytes in, the last `0x180` bytes are held back as slack,
and the descriptor carries the next node and the node's position in 32-byte units counted from a base the context records (whether that
base is physical address zero or the pool's start was not determined; the units are 20 bits wide in the words below). The first words of
each node buffer are a header: a link word (below) at dword 0 and again at dword 2, and a running sequence number at dword 3.

**Packet header word. Software expectation, checked against 17 of 18 table entries.** A packet is a header dword followed by payload
dwords. Bits 11:5 are the payload dword count: in the context-shadow table (`initialCxShadow`, copied by `CoInitShadowRam`) the
distance in dwords between consecutive packets is that count plus one for 17 of the 18 packets (headers `0x80003020` through `0x93cc0340`); the last, `0x00210440`,
runs to a padded end. Bits 4:0 hold a small index (the four copies seen differ only there, 0 to 3), and bits 31:12 are a target that selects the
state block. Seen in the shadow table: `0x80003020`, `0x046400c0`, `0x05260480`, four each of `0x09a900c0`, `0x0ca96120` and `0x1129f020`, then `0x91aa0220`,
`0x93cc0340`, `0x00210440`. The ICD emits, besides those, headers with the top byte `0x9x` whose targets step by `0x201` or `0x402` from one block to the next
(`0x922a4`, `0x924a5`, `0x928a7`, `0x92ca9`, `0x92eaa`, `0x930ab`, `0x932ac`, `0x936ae`, `0x938af`), so the target looks like two fields that advance together; it was not decoded.
Counts from the ICD's own headers: `0x80003020`, `0x91aa0020`, `0x92eaa020`, `0x936ae020` and `0x97400020` carry one payload dword; `0x84e44040`, `0x97000040`, `0x938af040` and `0x91ea2040`
two; `0x93cc0080` four; `0x944c42c0` twenty-two (bits 11:5 give 22, and the builder that emits it copies a 20-dword table behind the header); `0x9ed380e0` seven. `0x98804000` is a header with no payload (count 0, bit 14 set): the ICD inserts
it before the closing packet when the context asks for a flush, so it is a one-dword marker (its meaning, inferred: pipeline flush or fence).

**Closing a buffer and chaining. Established (`DispatchCurrentPkt` `0x6901a83a`, `ClosePacket` `0x69062118`).** The ICD ends the data in a node with a
three-dword packet: header `0x97000040`, a dword with the next node's position in bits 31:12 and, in the low bits, a field built from the running sequence
number, and a dword with this node's position in bits 31:12 and the low twelve bits of the sequence number. (The display-list builder's variant writes
the same header and the two positions without the sequence number.) The node is then padded with zero dwords to a 32-byte boundary, and the link word
below is stored. A fixed packet (`0x09280080` plus four dwords the context keeps together) is appended to the new node after a dispatch.

**Link words. Established as software writes; the engine's use is expected.** The ICD's node link word is `((units_used & 0x1ff) | (next_node_position << 9)) << 3 | (flags & 6) | 1`:
bit 0 set means the engine owns the node, bits 2:1 carry flags from the caller (not decoded; the caller's bit 1 together with its bit 0 selects a finish), bits 11:3 the number of
32-byte units used and bits 31:12 the next node's position. The miniport's own per-packet link table (`grmDispatchPacket`, `0x1725c`) writes the same layout except that the
unit count is stored minus one and the flags come from its caller; it then spins until the first dword of the next slot loses bit 0 (the engine clearing it). The two
builders disagree by one in the length field, so which one the engine follows, or whether the engine reads a different word altogether, is not settled.

**Waiting. Established (`CoWaitForPacket` `0x6901b50c`, tail of `DispatchCurrentPkt`).** To reuse a node, or to wait for the engine, the ICD spins on bit 0 of the
node's first dword. It steps through an 18-entry backoff table (`delayTable`) of busy-wait counts; at the last step, unless the context's no-block flag is set,
it asks the driver (`0x62`) whether the hardware is still busy and, if so, sleeps on a kernel event (handle kept in the context) that the miniport signals
from the engine's completion interrupt. `Finish` is escape `0x4c` followed by a wait on a second event. `__glCoIcdKickScheduler` is escape `0x4d` with the
closed node's position as its one argument.

## What is not known

Opcode set and packet layouts; the contents of `0x00000` to `0x07fff` and `0x0c200` to `0x17fff`; what `0x8000` entries
and `0xc000` entries are in hardware terms; what the engine does on each interrupt cause; whether the engine reads the
packet buffers by physical address or through the `0x8000` table; reset values; the Z and stencil buffer layout; how
the engine writes pixels into the display back end's tile lists (the miniport hands it the same lists it gives the
display, see `pAllocateTilesForBuffer`). The route is the OpenGL driver `sgcoicd.dll`, whose setup code is a software
implementation of the geometry pipeline that ends by writing packets; reading its packet emitters in full (see
[the open questions](../../questions/cobalt-graphics-open.md)).

## Review

Independent review of the OpenGL packet-path section (chips commits 7990dc9..7a40091). `sgcoicd.dll` 5.2.4 could not be opened (the
package is an InstallShield cabinet), so the claims were checked against the 1999 `sgcodd.dll` and `sgcomp.sys` from the SGI 320 NT 4.0
install CD. Confirmed there: the shadow-table rule that bits 11:5 of a header are the payload count (every table distance matches
count plus one except the last entry, which runs to a padded end); the chain packet `0x97000040` with a next-position dword and a
position-and-sequence dword; the escape dispatch on a code range from `0x40` upward. Not matching: the escape input sizes and the set of
live codes in that build differ from the table above (for example `0x40` takes `0x50`, not `0x54`, and `0x48` is not handled), so the
table is the 5.2.4 build's alone and remains unchecked here. The count for `0x944c42c0` was corrected from six to twenty-two.
