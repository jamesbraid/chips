# DIVO board: what the kernel driver touches, per LINC (companion to the contract page)

Status: **scoping draft, not independently reviewed.** Every access below is one the shipped IRIX `divo` kernel driver or
the `DIVO.so` video library makes, read from the object code. It is a list of software expectations, not a register
manual: no published specification of the LINC ASIC, the VIP or the board's other blocks is held. The contract it
supports is in [README.md](README.md). Sources (`B1` to `B4`) are defined there.

Ratings: **SE** software expectation (the shipped code does exactly this; read in full), **I** inferred (a reading of the
access, not stated by the code), **U** unknown. Offsets are byte offsets from the base of one LINC's 128 MiB memory
window (the driver calls the two LINCs "pipes" 0 and 1; pipe 1's window is pipe 0's plus `0x8000000`). Addresses are
the driver's literals; names in the second column are mine, chosen from what the code does with the word.

## 1. Window map

| Offset | Width | What the driver does with it | Rating |
|---|---|---|---|
| `0x04400000 + n * 0x10000`, n = 0 to 31 | 64-bit store | mailbox slot n: one 64-bit command word per store (section 3) | SE |
| `0x04c00800` | 32-bit read | must read `0x000810a9` (looks like PCI vendor `0x10a9`, device `0x0008`): "VIP not accessible" otherwise | SE (value), I (the reading as an ID) |
| `0x04c00804` | 32-bit write | `0xf9030146` (once, in the boot-mode sequence) | SE |
| `0x04c0080c` | 32-bit write | `0x00004000` (same sequence) | SE |
| `0x04c00f10` | 32-bit write | `0` (same sequence) | SE |
| `0x05000000` | 16-bit write | `0x0020` (same sequence) | SE |
| `0x05000004` | read through firmware | read by the video library at start; its bits 2 to 4 are rewritten (section 5) | SE |
| `0x05000608` | 8-bit write | `1`, at attach and on every release from reset; written under `splprof` just before the host reads the Unified System Time (UST) | SE (write), I (meaning: UST latch or enable) |
| `0x07000040` | 32-bit write | `0x80800001` (boot-mode sequence) | SE |
| `0x07400040` | 32-bit write | `0x80800001` (same) | SE |
| `0x07800000` | 32-bit, read-modify-write | LINC control: see section 2 | SE |
| `0x07800008` | 32-bit write | `0x7bd83f02` at attach, `0x7bd00002` in the boot-mode sequence | SE |
| `0x07800018` | 32-bit, write and read | LINC status/acknowledge: see section 2 | SE |
| `0x07800020` | 32-bit, read-modify-write | LINC interrupt control: bits 21:20 set at attach and in boot mode, cleared on release | SE (bits), I (they mask the two interrupt sources) |
| `0x07800100` | 32-bit write | `0x01000000` (boot-mode sequence) | SE |
| `0x07800200` | 32-bit write | `0x0001f820` (byte-bus setup) | SE |
| `0x07800220` | 32-bit write | `0x20000000` (boot-mode sequence) | SE |
| `0x07802000` | 32-bit write | `0xe8400000` (boot-mode sequence), then `0xe940fbff` (byte-bus setup) | SE |
| `0x07802008` | 32-bit write | the front-panel LED word: the driver writes the complement of the caller's value in bits 3:0 (private ioctl) | SE |
| `0x0781000c` | 32-bit, read-modify-write | bits 15:11 set at attach (`0xf800`) | SE |
| `0x07c00000` to `0x07c7ffff` | byte | the 512 KiB flash, see section 4 | SE |
| `0x07e08000`, `0x07e08004` | read through firmware | read by the video library at start (section 5): bit 7 of the first word selects a board variant | SE (reads), I (variant) |
| any offset below the window size | 16, 32, 64-bit read | diagnostic ioctls read a word at a caller-supplied offset directly (`DIVO_IOCTL_DIAG_READ_*`) | SE |

The driver also reads and writes the **PCI configuration window** of each LINC (a 256-byte piomap): dword `0x10` is
read for the memory window base, dword `0x04` is OR-ed with `0x6` (memory space and bus master enable), and dword
`0x14` is read as the mailbox consumer index (section 3). SE for all three accesses; I for calling `0x14` the consumer
index (the position is BAR1 in standard configuration space, and the code treats it as the firmware's progress).

## 2. LINC control, status and the interrupt line

| Access | Meaning as the code uses it | Rating |
|---|---|---|
| `[0x07800000]` bit 0 | cleared by the byte-bus setup | SE |
| `[0x07800000]` bit 1 | pulsed (set, then cleared) in the byte-bus setup; cleared once more at attach | SE |
| `[0x07800000]` bits 3:2 | pulsed at attach on pipe 0 only (set bit 2, then restore); cleared on release from reset | SE |
| `[0x07800000]` bit 6 | read after the release-from-reset clears bits 3:2: if set, the reset ioctl fails with `EBUSY` and the video library retries up to 200 times at 100 ms; a model should read it as 0 | SE (use), I (meaning "board still coming up") |
| `[0x07800000] = 0x00800018` | boot-mode sequence start | SE |
| `[0x07800018]` write `0x00300000` | clear status bits 21:20 (attach, release from reset) | SE |
| `[0x07800018]` write `0x00100000` | acknowledge the interrupt: the handler writes it, reads the register back and repeats while bit 20 stays set | SE |
| `[0x07800018]` bit 20 | interrupt pending, write 1 to clear (inferred from the loop) | I |
| `[0x07800018]` bit 21 | firmware panic: if set the handler writes `0x00200000` and runs the panic path (logs "firmware crash", masks bits 21:20 again, wakes every waiter, posts a fatal event) | SE (use), I (name) |
| `[0x07800018] = 0x01000000` | boot-mode sequence | SE |

The LINC raises PCI INTA on its own device: the driver allocates one interrupt per pipe (names `divo_0 a`, `divo_1 a`)
and connects `divo_intr_0` and `divo_intr_1`. A model must drop the line when `[0x07800018]` bit 20 is cleared and
raise it again only for a new packet (section 6). An unexpected extra assertion costs nothing but a handler pass.

## 3. The mailbox

Host to board commands go through a 32-entry ring of 64-bit words. Slot n lives at window offset
`0x04400000 + n * 0x10000`. The driver keeps the next write index in software; before a store it reads the board's
consumer index (PCI configuration dword `0x14`) and treats the ring as full when the next write index equals it, then
polls up to 200 times at 5 ms and fails the call with "firmware not updating". Read as the index of the **last consumed**
slot, the rule is consistent: with everything consumed the register equals the last slot written, which is never the
next one, and it equals the next one only when the board is 31 slots behind. A stand-in that drains the ring at once
therefore makes the register read n after the store to slot n. SE for the compare, I for the direction convention.

The same value also arrives as an interrupt packet (type `0x01000000`, the index in word 1; type `0x04000000` carries
two words), which the host copies to its own shadow and wakes the writer. A stand-in should do both.

Word layout (bit 63 is the top). The opcode is the top six bits:

| Opcode | Seen from | Payload | Rating |
|---|---|---|---|
| `0x00` | video library, write byte | bits 57:32 board address, bits 7:0 data | SE |
| `0x02` | video library, write word | bits 57:32 board address, bits 31:0 data | SE |
| `0x03` | video library, write control; kernel, event mask | bits 57:52 control index, bits 15:0 data (library); the kernel's mask word uses index `0x15` and 32 data bits | SE |
| `0x09` | kernel, reset sequence | bits 40:0 and 47:41 carry a DMA address: the second 4 KiB half of the packet buffer (the packet ring base, section 6) | SE (shape), I (meaning) |
| `0x0a` | kernel, reset sequence | data `0x40`: the number of packet-ring entries | SE (value), I (meaning) |
| `0x0b` | kernel, after each interrupt pass | low 32 bits: index of the last packet consumed | SE (shape), I (meaning) |
| `0x0c` | kernel, reset sequence | a DMA address: the start of the packet buffer | SE (shape), I (meaning) |
| `0x0d` | kernel, reset sequence | bits 57:26: nanosecond offset between the host clock and UST at that moment | SE (shape), I (meaning) |
| `0x10` | video library, read word | bits 25:0 board address; the answer is a reply packet (section 6) | SE |
| `0x12` | video library, read half-word (`0x4800...`) | bits 25:0 board address; answer as above | SE (shape), I (width) |
| `0x20` | block send (private ioctl `0x64767320`) | bits 57:51 word count (at most 127), bits 50:49 scratch slot, bits 40:0 and 47:41 DMA address of a block of command words | SE |
| `0x23`, `0x25`, `0x27`, `0x28` | micro-store load (ioctl `0x64767321`) | DMA address of a block of packer or FPGA data, byte count up to 2 KiB; no other opcode is accepted | SE |

The 40-bit DMA address field is `address >> 7` in bits 40:0 and `address >> 56` in bits 47:41; the buffers are 128-byte
aligned. SE.

The scratch blocks for opcodes `0x20` and `0x23` to `0x28` come from four 2 KiB slots in one 8 KiB kernel buffer, handed
out round-robin; each slot has a semaphore that the matching completion packet releases. A firmware stand-in that
reads a block and never signals completion therefore stalls the fifth block. SE.

## 4. The flash

`divo_flash_part` enters the part-identification mode with the usual three-cycle unlock (`0xaa` to `+0x5555`, `0x55` to
`+0x2aaa`, `0x90` to `+0x5555`), waits 500 ms, reads one 16-bit value at flash offset 0, and leaves the mode with
`0xf0` after the unlock. The write and erase routines refuse unless that value is `0x1fa4`.

* Read: plain byte loads. SE.
* Write: sector size 256 bytes, 2048 sectors (512 KiB). Per sector: unlock with `0xa0` to `+0x5555`, store 256 bytes in
  ascending order, then poll the last byte until it reads back the byte written (up to 10 000 reads); each sector is
  written under `splhi`. A write must start and end on a 256-byte boundary. SE.
* Erase: unlock with `0xf0`, then `0xaa`, `0x55`, `0x80`, `0xaa`, `0x55`, then `0x30` to the first byte of each sector in
  the range; then poll the last sector for 1 ms steps: bit 3 set means the erase timer is running (up to 1000 polls),
  and two equal bit-6 reads in a row mean done (toggle bit). A timeout fails with "erase not starting" or "toggle bit
  not toggling". SE.
* Verify: byte compare; mismatch returns `EIO`. SE.

Part `0x1fa4` is manufacturer `0x1f` (Atmel), device `0xa4`, the identification the published datasheet gives for the
AT29C040A ([devices/at29c040a](../at29c040a/README.md)), whose 256-byte sectors and polling match the write path.
The **erase** sequence (`0x80` prefix, `0x30` per sector) is not a command that datasheet defines, so the part is a
close relative of the AT29C040A, not necessarily that exact part. U (the exact part). A model can serve the sector
write and erase sequences as above on a plain 512 KiB byte array and report `0x1fa4`.

What the flash must contain for the video library to leave it alone is in [README.md](README.md) section 7.

## 5. Reads the video library makes through the firmware at start

`FUN_5ffe0390` (the per-board start routine of `DIVO.so`), after the flash check, issues three opcode-`0x10` reads per
pipe and keeps the answers: `[0x07e08000]`, `[0x05000004]` and `[0x07e08004]`. It tests bit 7 of the first, then rewrites
bits 2 to 4 of the second (sets bits 3 and 2 or bit 3 alone depending on that test, clears bit 4) with an opcode-`0x00`
byte write to `0x05000004`, and flushes. Nothing compares the values with constants; an all-ones answer (the library's own
value on an ioctl error) and an all-zero answer both let the routine finish. SE for the sequence, U for what the bits
mean.

## 6. The packet buffer and the interrupt packets

At attach the driver allocates 16 KiB per pipe, DMA-mapped (one `pciio_dmatrans_addr` call, flags `0x40060`). The first
8 KiB is a descriptor area, the second 8 KiB is the **packet ring**: 64 entries of 128 bytes. At every release from
reset the driver writes `0xffffffff` to the dword at entry offset `0x78` and `0` to the dword at `0x7c` of every entry,
and announces the buffer and ring size with the mailbox words in section 3. An entry is **valid when its dword at
`0x7c` is non-zero** (the board writes it last). The handler consumes from the entry after its saved index, clears the
dword, processes the packet, stops at the first invalid entry or after 64 entries, then sends opcode `0x0b` with the
index. Word 0 of the entry is the type.

| Type (word 0) | What the host does | Rating |
|---|---|---|
| `0x01`, `0x02`, `0x04`, `0x10`, `0x20`, `0x40`, `0x100`, `0x200`, `0x400`, `0x1000` | post an event with that bit to the readers of the pipe node (poll and the get-event ioctl); `0x01`, `0x02`, `0x04`, `0x20`, `0x400` and `0x1000` carry one or two payload words | SE |
| `0x80` | firmware error report: word 1 is a code; codes `0x1f` to `0x31` go through a jump table, any other value is posted as an event | SE |
| `0x800` | call the audio-library hook registered by `divo_al` (board index, packet) | SE |
| `0x8000`, `0x80000000` | an image transfer finished: word 1 (below 2) selects the channel; the host copies the packet and runs the DMA bookkeeping | SE |
| `0x10000`, `0x20000` | **synchronous reply**: word 1 is the value, word 2 the status code returned to the caller of an opcode-`0x10` read; `0x10000` also posts an event | SE |
| `0x01000000` | mailbox consumer index in word 1 | SE |
| `0x02000000` | firmware console text starting at byte 4; logged as a message | SE |
| `0x04000000` | mailbox consumer index in word 1, word 2 stored beside it | SE |
| `0x08000000` | block send complete: word 2 is the scratch slot (0 to 3) to release | SE (use), I (name from the adjacent error text) |
| `0x10000000` | video descriptor complete: word 1 below 2 | SE (use), I (name) |
| `0x20000000` | video packer load complete: word 1 is the slot to release | SE (use), I (name) |
| `0x40000000` | audio packer load complete: word 1 is the slot to release | SE (use), I (name) |
| anything else | logged "unknown interrupt type"; nothing else happens | SE |

A slot index of 4 or more in the three slot-bearing types logs an error and posts a fatal event. A stand-in must not
send them.

## 7. Private ioctl numbers

Base `0x64767300` (ASCII `dvs` plus a count byte). Board node only (a pipe node answers `EINVAL`); every command that
takes a pipe number returns `EINVAL` for a value other than 0 or 1.

| Number | Role | Argument | Rating |
|---|---|---|---|
| `0x64767300` | software version: returns 1 (the library refuses any other value) | 4 bytes out | SE |
| `0x64767302` | returns the kernel's board record pointer (opaque handle) | 8 bytes out | SE |
| `0x64767303` | set mode (pipe, mode): 1 and 2 only record the mode; 3 puts the board in boot mode (reset sequence "hold"), then the byte-bus setup | 16 bytes | SE |
| `0x64767304` | no-op, returns 0 | none | SE |
| `0x64767305` | read the board NIC string (up to the caller's length) | 16-byte descriptor | SE |
| `0x64767306` | set the VL unit number: rewrites the inventory unit, adds the exported `vl_board` label | int | SE |
| `0x64767307` | read controller and unit numbers | 16 bytes out | SE |
| `0x64767308` | read the hwgraph vertex name | 16-byte descriptor | SE |
| `0x6476730a` | set LEDs | 16 bytes | SE |
| `0x6476730b` | store one raw word into mailbox slot n (24 bytes) | 24 bytes | SE |
| `0x6476730c` | reset (pipe, 0 = run firmware, 1 = hold in boot mode) | 16 bytes | SE |
| `0x64767314` to `0x64767318` | flash part id, read, write, verify, erase (`0x7ffff` offset limit, 512 KiB) | 16 or 32 bytes | SE |
| `0x6476731e` | enqueue one word (no reply) | 16 bytes | SE |
| `0x6476731f` | enqueue one word and wait for the synchronous reply packet | 24 bytes in, reply value in the same structure | SE |
| `0x64767320` | block send (opcode `0x20`, DMA'd command block) | 32 bytes | SE |
| `0x64767321` | micro-store block (opcodes `0x23`, `0x25`, `0x27`, `0x28`) | 32 bytes | SE |
| `0x64767322` | get next event (`0x98` bytes; returns `EAGAIN`-style when empty) | 152 bytes | SE |
| `0x64767323` | set event mask (the mask is OR-ed with `0x80`, then sent as a mailbox control word) | 16 bytes | SE |
| `0x64767324` | flush the event queue | 16 bytes | SE |
| `0x64767325`, `0x64767326` | DMA pool and fifo attach, transfer management | 32 bytes | I (the handlers were read as calls into the shared media-streaming layer, not in detail) |
| `0x64767328`, `0x64767329` | frame counter and UST/MSC pair | | I |
| `0x64767332` to `0x64767338`, `0x6476733a` | diagnostic reads and writes at a window offset (16, 32 and 64-bit) | 24 bytes | SE |
| `0x6d687767` | the ioconfig command: assigns the controller number, links the board under `/hw/video/divo` | | SE |

Event queue: 128 entries of `0x90` bytes per pipe; a full queue logs "event overflow" and drops the mask. SE.
