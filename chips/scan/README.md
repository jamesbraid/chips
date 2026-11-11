# Router scan-chain tunnel through the L1 (IP35)

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): no specification is held). The IP35 kernel can read a router's
registers by a second route that touches no memory window and no vector packet: it asks the brick's L1 system controller to
shift a bit pattern through the router's scan (JTAG) chain and hands back the bits that come out. The host-visible part is a
message protocol carried over the L1 link described in [../l1/README.md](../l1/README.md); nothing here is a register
offset. The other route to the same chip is the vector-packet path in [../router/README.md](../router/README.md).

Every fact is read from IRIX 6.5.30 objects of the IP35 boot set: the three members of `jtagio.a` (`read_reg.o`,
`scancmd.o`, `smpl_jtagio.o`), `irouter.o`, and `kernel.o` for the one caller. All are relocatable, so routines are cited
by offset. The public Linux headers `asm-ia64/sn/ksys/l1.h` and `asm-ia64/sn/router.h` (the pinned `linux-2.5.40`
submodule, see [docs/sources/INDEX.md](../../docs/sources/INDEX.md)) were read afterwards, for agreement and conflict only.

Census: [census/](census/) and the config [`tools/configs/scan-tunnel.json`](../../tools/configs/scan-tunnel.json), run with
[`retools/tools/chips/callargs.py`](../../retools/tools/chips/callargs.py). It finds the **2 call sites** of `read_rr_reg` in the kernel and resolves
neither: both pass the selector as arithmetic on a loop index (below), which the straight-line pass cannot fold, so
`census.tsv` is empty and `unresolved.tsv` lists them. No header is generated: the values here are selectors, opcodes and
framing constants, not offsets into a window, and a register-offset header would misstate them. The tables below are the
contract.

## What this page covers, and what it does not

- Read in full: `read_rr_reg` and `extract_mux_data` (`read_reg.o`), all four routines of `scancmd.o`, every routine of
  `smpl_jtagio.o` (`simp_jtag_open`, `_close`, `_reset`, `_scan_ir`, `_scan_dr`, `_sel_sic`, `simp_process_scancmd`,
  `scancmd_to_irtr`), and `IRouterInitID`, `IRouterWritePacket`, `IRouterReadPacket`, `add_frame`, `IRouterFreePacket`,
  `IRouterMakeBlankPacket` and `get_frame_base` of `irouter.o`.
- Read but not decoded to the last field: `IRouterMakePacket` and `IRouterExtract`. The framing they build and take apart is
  recorded from the writer and reader, which are read in full; the node fields they fill are inferred.
- No routine other than `router_acquire_port_info` calls `read_rr_reg` in the kernel object (the symbol search found two
  calls, both in it). `simp_jtag_reset`, `_scan_ir`, `_scan_dr` and `_sel_sic` are exported but have no caller in the held
  objects; their protocol is read, their use is not known.
- Which router registers a selector names is **unknown**. The reset and idle values of the scan chain are unknown.

## Call chain (established)

| step | routine | what it does | Grade |
|---|---|---|---|
| 1 | `router_acquire_port_info` (`kernel.o` `0x27bc`) | per router port, calls `read_rr_reg` twice with the node halfword at record +4, the halfword at record +504, and selector `2*port - 1` then `2*port - 2` (port is one-based, so `2*(port-1) + 1` and `2*(port-1)`). The first result (two doublewords) lands in the port record at offsets 0 and 8; the second goes to a stack buffer and only its first doubleword is kept, stored at port record +16. A zero return takes the error exit. | established |
| 2 | `read_rr_reg` (`read_reg.o` `0x0`, 364 bytes) | the read-one-register command, below | established |
| 3 | `simp_process_scancmd` (`smpl_jtagio.o` `0x478`) | validates, bit-reverses, hands the command to the packet layer and checks the reply | established |
| 4 | `scancmd_to_irtr` (`smpl_jtagio.o` `0x8b4`) | wraps the command in an iRouter packet, sends it to the L1 and waits for the reply | established |
| 5 | `IRouterWritePacket`, `IRouterReadPacket` (`irouter.o` `0x14`, `0x190`) | frame the packet into 127-byte sends and reassemble the reply | established |

## The command record

`simp_jtag_open` (`0x0`) allocates one global record on the first call and keeps it: `scancmd_create` asks `kmem_zalloc`
for `(ceil(bits/32) + 4) * 4` bytes, 144 for the 1024-bit maximum that `read_rr_reg` passes. The record is a four-word header
followed by payload words. `scancmd_init(bits, record)` zeroes the same count; `read_rr_reg` and the `simp_jtag_*` wrappers
call it with 0 bits, so they clear only the 16-byte header and leave the payload words as they were. The four wrappers and
`read_rr_reg` take no lock around the shared record (no lock call appears in any of the five), so concurrent callers would
share it; the kernel's one caller does not hold its own lock across the two reads either (it takes a spinlock only after
both). `simp_jtag_close` frees the record; nothing in the held objects calls it.

**Grade of the table.** Established, and checked against the routines' constants in this pass: the operation byte of word 0 (`0x88` in `read_rr_reg`, `0x83` in the scan-instruction and scan-data wrappers, `0x84` in the select wrapper, `0x80` in reset). The word 2 bit assignments are established from the stores as the cells say; what each bit means on the wire is inferred.

| header word | content (established from the stores) | Grade |
|---|---|---|
| word 0 | top byte is the operation: `0x88` read one router register (`read_rr_reg`), `0x80` reset (`simp_jtag_reset`), `0x83` scan an instruction or data register (`simp_jtag_scan_ir`, `simp_jtag_scan_dr`), `0x84` select (`simp_jtag_sel_sic`). The low 24 bits are cleared by the init. The reply is read back from this word: bits 15:8 of the reply's first word are a status byte (below). | established |
| word 2 | bit 31: set by `scan_dr`, cleared by `scan_ir`, and set from the low bit of the second argument by `reset`. Bit 29 is cleared when the global `l3_bigend` is non-zero and set otherwise (below). Bit 27: the low bit of the global `psi`. Bits 15:8: the low byte of the global `state`. Bits 7:0: 1 for `scan_ir` and `scan_dr`, 0 otherwise (`read_rr_reg` clears them explicitly). | established |
| word 3 | the number of bits in the payload: 197 for `read_rr_reg`, 192 for `sel_sic`, the caller's count for IR and DR scans. | established |
| words 4 up | payload, `ceil(bits/32)` words. `sel_sic` stores six words: its second, third and fourth arguments, the fifth (a 64-bit value) split high word then low word, and the sixth; they fill its 192 bits exactly. Its seventh argument is the error buffer. | established |

Globals (`smpl_jtagio.o` `.sdata`, read from the object): `max_sc_len` starts 0, `l3_bigend` starts 1, `psi` starts 0, the
record pointer starts 0. `simp_jtag_open` stores its first argument in `max_sc_len` and 1 in `l3_bigend`. `psi` is never
written in the held objects, so bit 27 of word 2 is 0 as shipped. `state` (in `.sbss`) is stored 0 by a successful reset, 1 by a
successful IR or DR scan and 16 by any of `reset`, `scan_ir`, `scan_dr`, `sel_sic` or `read_rr_reg` on failure; `sel_sic` and
`read_rr_reg` leave it alone on success. Its low byte is copied into word 2 bits 15:8 of the next IR or DR scan. What 0, 1 and
16 stand for is unknown.

## Reading one register: `read_rr_reg` (established)

Arguments: a0 the node halfword (the router's node number as the kernel records it), a1 a packed brick position, a2 the
selector, a3 a pointer for two doublewords, a4 a buffer for an error message.

1. `simp_jtag_open(1024, errbuf)`; `scancmd_init(0, record)`; word 0 top byte set to `0x88`; word 2 bits 15:8 and bits 7:0
   cleared; word 3 set to 197.
2. One input word is stored on the stack: the selector shifted left by one. The routine stores nothing else in the input
   buffer, yet `simp_process_scancmd` reads `ceil(197/32) = 7` words from it, so words 1 to 6 are whatever the stack held
   (read from the instructions: one `sw` to the buffer, no clear).
3. The packed position `a1` is rewritten before it is used (next table), and the call is
   `simp_process_scancmd(address, record, input, output at stack+1024, errbuf)`.
4. On success `extract_mux_data(out, reply)` gathers 128 bits from the reply: bit `i` of the result (`i` from 0) is source bit
   `68 + i`, where source bit `k` is bit `31 - (k mod 32)` of reply word `k / 32` (counting words from the first payload
   word), and result bit `i` lands in bit `i mod 64` of doubleword `i / 64`. Return 1. On failure, `state` is set to 16 and
   the return is 0.

So the 197-bit shift-out is read back as 128 bits starting 68 bits in; the 68 leading and 1 trailing bit are discarded. What
the selector chooses inside the router (a multiplexer position is the only hint, from the routine name `extract_mux_data`) is
unknown.

### Packed position to address (established arithmetic, inferred reading)

The routine uses the low 12 bits of `a1`. It passes the low 6 bits unchanged and re-encodes bits 11:6. Let `n = (a1 >> 6) & 0x3f` and
`h = bit 5 of n` (bit 11 of `a1`). If `h` is 1 the tens digit is bits 4:2 of `n` and the units digit bits 1:0; if `h` is 0 the
tens digit is bits 4:3 and the units digit bits 2:0. The value `100*h + 10*tens + units + 1` goes into bits 15:6 of a word, the
low 6 bits of `a1` into bits 5:0 and the node halfword into bits 31:16. `simp_process_scancmd` then forms the destination
address `((word & 0xffff) << 12) | 0xf` and sign-extends the top halfword as the node number.

The destination address is a **local-brick-style L1 address**: type 0 in bits 31:28, a 10-bit rack in bits 27:18, a 6-bit bay
in bits 17:12 and a task in bits 4:0, which is the public `l1.h` layout (agreement; the header gives type 0 as the L1 and tasks
1 to 6). So the packed position is a bay in its low 6 bits and a rack number, held as a two-field decimal-style code, in bits
11:6; the +1 makes the rack one-based. Inferred: the role (rack and bay) comes from the match with the public layout, the
arithmetic is established. The task value `0xf` is **not** in the public header (it names tasks 1 to 6 only); the L1
firmware answers it (next section).

### The L1 end of the scan command: task 15 (established, firmware 1.44.0)

The L1 firmware image shipped with IRIX 6.5.30 (version 1.44.0, build stamp 20060717182038, ColdFire code loaded at
`0xffe00000`) registers a local endpoint for **task 15 (`0xf`)** at `0xffe71842`, in the routine that also creates a queue
named `SCAN_QUE` and a task named `SCAN_TSK` (entry `0xffe718cc`). So the kernel's `| 0xf` is a task number in the L1's table
of local tasks (the table `packet_deliver` indexes for tasks 1 to 24); the other local tasks registered by the image are 1 to 6,
10 to 12 and 14 to 20, each from its own init routine. The task's loop (`0xffe718cc` to `0xffe71bb4`):

- Takes one packet at a time from `SCAN_QUE`. A packet must carry exactly one argument (byte at packet +0x20 equal to 1), of
  argument type 1 (low three bits of the byte at +0x24); otherwise it logs "Invalid Scan packet received" and drops it with
  no reply. The argument is the data block, its length is the halfword at +0x26.
- Requires bit 31 of the block's first word to be set. If it is clear the task logs `Boundary scan "si" functions disabled
  in this L1 image!` and does not process the request; the reply path is not taken. (When the one-time initialisation flag at `0x30000044` is
  clear it instead logs "Error initializing scan", clears bits 15:8 of that first word, which is the field the kernel reads as
  the reply status, and again sends no reply.)
- When a mode word at `0x3000007c` equals 2 it byte-swaps the first four words (the 16-byte request header) of the block in
  place before and after processing; the routine that does the work is at `0xffe7296c` (not read).
- Replies through `response_send` with one argument of type 1, a pointer to the same block and the same length, so the reply
  payload is the request block modified in place. Failure to send logs "Error sending Scan packet response".

That grades the role of task 15 as **established**: it is a scan service, named so by its own queue and task strings and by the
message text that calls the function set boundary scan. The data format beyond the bit 31 flag and the header swap, what
`0xffe7296c` shifts and into which chain, and how the kernel's 197-bit command maps to it are **unknown**. Settling test: read the routine at `0xffe7296c` and its callers in the L1 firmware image with `hostfacts.py --flat` and follow the 197-bit buffer from the caller to the shift loop; the chain's own wiring is not in software, so the mapping to physical chains stays unknown beyond that.

## Sending the command: `simp_process_scancmd` and `scancmd_to_irtr` (established)

- A command whose bit count (word 3) is not below `max_sc_len` is refused with the message "Packet length exceeds maximum
  allowed by library." and a zero return.
- With an input pointer, each of the `ceil(bits/32)` words is reversed bit for bit (adjacent bits, then pairs, nibbles, bytes,
  halfwords) and the reversed word is written back to the caller's buffer as well as to the payload. The output words are not
  reversed here; `extract_mux_data` reads them most-significant-bit first instead, which undoes the reversal.
- Header byte order: with `l3_bigend` non-zero (the shipped default) the four header words go out as they are and word 2 bit 29
  is 0; with it zero, bit 29 is set and each header word is byte-swapped first. Nothing in the held objects writes `l3_bigend`
  after `simp_jtag_open`, so the swapped form is dead code as shipped.
- `scancmd_to_irtr(record, byte_count, address, node)` builds a one-entry description (type 1, length `byte_count`, pointer to the
  record) and calls `IRouterMakePacket` with the tag `0xabcd`. It finds the node's L1 handle (the node halfword indexes the
  kernel's `nasid_to_compact_node` halfword array through a pointer slot in `.srdata`; it reads a pointer from the absolute address
  `0xffffffffffffc400`, follows it to an array of pointers, indexes that with the compact node, reads the doubleword at +0x8620 of the
  record found and adds 40 to get the handle. What those structures are is unknown) and calls `sc_open(handle, 0x0ffff000)`. The source address `0x0ffff000` is the same
  "local" address the L1 command path uses ([../l1/README.md](../l1/README.md)). `sc_open`'s return value is the subchannel
  for every later send and receive. It sends with `IRouterWritePacket`, frees the packet, reads the reply with
  `IRouterReadPacket`, closes the channel, and accepts the reply only if the halfword at node +50 is `0xabcd` and the byte at +48 is 1.
  `IRouterExtract` copies the payload back into the record. A failure at any step returns 0 with no message here.
- After a successful round trip `simp_process_scancmd` takes bits 15:8 of the reply's first word. **Zero is an error:** the
  message is "Unable to process packet; L1 system controller error." followed by "Confirm brick is connected and is powered
  up." and "RJ45 scan cable and ITP must be unplugged from brick." (the last names a physical scan connector that must be free,
  so the L1 shares the chain with an external probe). A transfer failure gives "IRouter packet send failed, or bad response packet."
  Any nonzero status byte is success; its other values are unused here. On success the payload words are copied to the output buffer
  unchanged, and the return is 1.

## iRouter framing (established from the writer and reader)

`IRouterWritePacket` sends a packet as a sequence of `sc_send` calls, each at most **127 bytes**: a 9-byte header and up to
118 data bytes (it copies `min(remaining, 118)` per send). The header, as the receiver reads it, is:

| offset | content | Grade |
|---|---|---|
| 0 to 3 | zero as sent | established |
| 4 | `0x30` | established |
| 5 | frame type: 1 first frame of a head packet (bit 7 of the node byte at +37 set), 2 first frame of any other packet, 3 each further frame of the same packet | established |
| 6 | for type 1 the low 7 bits of the byte at +37 of the packet node (`IRouterMakePacket` fills it with a descending number and sets bit 7 on the head); zero otherwise | established |
| 7, 8 | the data length of the whole packet, big-endian (as sent in every first-of-packet frame; a continuation frame carries zero here) | established |
| 9 on | data | established |

The receiver, `IRouterReadPacket`, calls `sc_recv_intr` with the constant 4,000,000 (`0x3d0900`) as its time-out argument (unit
unknown) and reads the 16 bits at offsets 4 and 5 as `0x3001`, `0x3002` or `0x3003`. For 1 and 2 it takes the length and, for 1, the
packet count; a first-of-packet frame that arrives while the previous packet still has bytes outstanding is an error, as is a data
frame longer than the bytes outstanding, a type other than these three and a failed receive (return -1). It allocates a 1056-byte node
(`kmem_zalloc(1056)`) for each packet and chains them; success returns 0. `IRouterMakePacket` also
allocates 1056-byte nodes (a 32-byte header and room for the 1024-byte payload) and records the tag at +50, the descriptor count at +48
and the destination address word at +40 (inferred from the stores; the routine is not decoded to the last field).

## Objects (established, every routine read)

- `IP35/usr/cpu/sysgen/IP35boot/jtagio.a(read_reg.o)` (established): the read-one-register command. `read_rr_reg` (364 bytes)
  builds a 197-bit scan command with operation byte `0x88` and sends it through `simp_process_scancmd`; `extract_mux_data` (208 bytes) then keeps 128 bits of the reply starting at bit 68 as two doublewords. Both routines are described above.
- `IP35/usr/cpu/sysgen/IP35boot/jtagio.a(scancmd.o)` (established): the allocator for the command record. `scancmd_create` and
  `scancmd_init` size it as `ceil(bits/32) + 4` words, `scancmd_destroy` returns at once for a null pointer and otherwise calls `kmem_free` with the size argument 4, not the length `scancmd_create` allocated; the free on `scancmd_create`'s own failure path also passes 4, and `scancmd_dump` is an empty routine that returns at once.
- `IP35/usr/cpu/sysgen/IP35boot/jtagio.a(smpl_jtagio.o)` (established): the command layer. `simp_jtag_open`, `_close`, `_reset`,
  `_scan_ir`, `_scan_dr` and `_sel_sic` fill the header words listed above, `simp_process_scancmd` bit-reverses the data and
  checks the reply status byte, and `scancmd_to_irtr` wraps the record in an iRouter packet to the local L1 and checks the tag
  `0xabcd` on the reply. It holds the globals `max_sc_len`, `l3_bigend`, `psi`, `state` and the record pointer, and six message strings.
- `IP35/usr/cpu/sysgen/IP35boot/irouter.o` (established): the iRouter packet layer. `IRouterWritePacket` cuts a packet into
  sends of at most 127 bytes with a 9-byte header, `IRouterReadPacket` reassembles them from `sc_recv_intr`, and
  `IRouterMakePacket`, `IRouterMakeBlankPacket`, `add_frame`, `get_frame_base`, `IRouterFreePacket` and `IRouterExtract` manage the
  1056-byte packet nodes that carry them (`IRouterInitID` stores an identifier at +4 and zeroes +0 and +6 of its record).

## Public sources (read after the binaries)

- `asm-ia64/sn/ksys/l1.h` (`linux-2.5.40`): the address layout above agrees; it names an "iRouter" task (1) and an L2 and an "L3"
  address type, a C-brick and an I/O-brick type. No public code implements the scan path: a search of the pinned trees found the
  word "iRouter" only in that header's task and error constants, and no `read_rr_reg` or scan-chain routine.
- `asm-ia64/sn/router.h` (`linux-2.5.40`): `RR_LB_TO_L2` (`0x40`) and `RR_L2_TO_LB` (`0x48`) are described as the data to and from
  "the JTAG controller" (a valid bit, a 32-bit data field and, on the return side, a parity bit), and `RR_GLOBAL_PARMS1` bits 7:0 as
  "JTAG Sw Register" bits. Those are router registers on the chip side of the same JTAG controller. They are not reached by the
  vector census ([../router/README.md](../router/README.md): the kernels never touch `0x40` or `0x48` by constant), consistent with
  the scan route being the only software use of that controller. Inferred only: nothing in the held code connects the L1's scan
  messages to those two registers.

## L2 and the rack controller image

The L2 is named by an address-type constant in the public header and by no routine in the held kernels. The held file
`mmscfw.bin` is not host-visible hardware: it is a 32-bit x86 VxWorks image (strings: `Wind River Systems` copyright, a
`vxworks` boot line, `ffsc` target name) for a rack-level controller it calls the MMSC, with an address daemon that assigns rack IDs, a console and
command interpreter whose help text lists commands to show and set the rack ID, count racks, rescan modules, list
partitions, restart the controller, read its logs and set serial-port parameters, and a message pipe whose name contains "L2". It reaches the host only over serial ports and an Ethernet link, so it has no register map for software to depend on.
Inferred from strings only; the image's code was not disassembled, and whether it is the L2 or a sibling product is unknown.

## Open

See [../../docs/open-questions.md](../../docs/open-questions.md): the meaning of the selector, the scan-chain
state codes, the work done at L1 `0xffe7296c`, and the L2 controller.
