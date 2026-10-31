# Xbow (Crossbow)

Mode: **spec-backed** (see [docs/specs.md](../../docs/specs.md): Crossbow ASIC Specification, revision 12.0; its
register map is transcribed in `docs/sources/specs/crossbow-asic-specification-rev12.0.registers.md`). Every fact
below was first read from the IRIX 6.5.30 objects `xbow.o` (IP27, IP30 and IP35 boot directories), the error-save
routines of the IP27 and IP35 `kernel.o`, and the IP27, IP30, IP35 and I/O-board PROM images. The specification is
compared afterwards (section "Against the published specification") and never supplies a fact.
Census: [census/](census/census.md) (`census.tsv`, `fields.tsv`, `context.tsv`, `census-sites.tsv`,
`census-windows.tsv`), config [`tools/configs/xbow.json`](../../tools/configs/xbow.json), header
[`include/xbow.h`](../../include/xbow.h).

The crossbar is widget 0 of the XIO fabric. Its ports are numbered 8 to 15 ("links"; widgets 1 to 7 are not ports).
**Every register access in every scanned routine is a 32-bit `lw` or `sw` at the slot offset plus 4**: the registers
are 8-byte slots with the data in the low (big-endian second) word, so the identification word is read at `+0x4`
(established: census widths are 4 and halves 4 on every row; no routine uses `ld`, `sd` or a partial-word
instruction on an Xbow register). This page names a register by its 8-byte slot; add 4 for the address the code uses.
The link registers are a family: link 8 + n is at slot + 0x40 * n, n = 0 to 7 (established: every accessor builds
`(port & 7) << 6` and adds it). The scan does not follow that index, so the census lists link 8 and link 9 and
marks the rest as indexed.

## What identifies the chip (established, `xbow_attach` in `xbow.o`, read in full)

- `xbow_attach` maps 768 (0x300) bytes at widget offset 0 through `xtalk_piotrans_addr`; the slot map ends at 0x2ff.
  It reads the identification word and forms `revision | (part << 4)` from bits 31:28 and 27:12. For a value below 2
  it prints a down-revision message (the `DOWNREV` string and "Crossbow ASIC: rev ... (code=...)"). The code
  compares with 1, 3, 4, 5, 0xd0001 and 0xd0002 and labels the last two "Xbridge 1.0" and "Xbridge 2.0", but those
  arms sit behind the below-2 test, so only values 0 and 1 can reach them (established arithmetic; why the table is
  there is unknown). Nothing rejects a value: attach continues for every part and revision.
- `is_xbox_config` (IP27 `kernel.o`) reads the identification word of widget 0 at a node's window and returns 1 when
  the part field (bits 27:12) is 0, behind a global flag (established).
- Part 0xd100 is the only other part the crossbar helpers read from the chip (see "PXBOW"). `xbow_get_bridge_pointers`
  compares 0xd000, 0xd100, 0xc002 and 0xd002, but with the part number held in a widget's info record, not read from
  a register; it touches no Xbow register.

## Register inventory

The census reaches 33 register rows (one per slot and per whether the access is indexed: offsets 0x0 to 0x58, and
link 8 and link 9 for the link family) plus two rows read only on the PXBOW path. The generated tables carry accessor routine names that are driver routines for this
chip, not register-accessor names, so the graded table below is written by hand from the census rows and the routines
read. It does not reach: the performance counters (reached through stored pointers, read by hand below), the
input-buffer flush registers and the NIC register.

### Graded register table

Access and width are what the instructions do (established wherever a site exists). The grade is of the role and
fields: **E** established (the routine that uses it read in full, or an arithmetic the code performs), **I** inferred,
**U** unknown. Link registers repeat at + 0x40 per link. Names are the specification's, applied after the reading.

| slot | register | width | access seen | who touches it (`xbow.o` routine unless stated) | what the code does | grade |
|---|---|---:|---|---|---|---|
| `0x0` | identification | 4 | r | `xbow_attach`, `xbow_widget_present`, `xbow_error_handler`, `is_xbox_config` (`kernel.o`), PROM present tests | bits 31:28 revision, 27:12 part, 11:1 manufacturer (the PXBOW test requires 0) | E |
| `0x8` | widget 0 status | 4 | r | `xbow_error_handler`, `idbg_xbowregs`, `save_xbow_err` (`kernel.o` and PROMs) | printed and saved raw; the IP30 PROM interrupt routine tests `& 0xff800000` and bits 5 and 2 | E |
| `0x10` | error upper address | 4 | r | `xbow_errintr_handler`, `xbow_error_handler`, `save_xbow_err` | low 16 bits are address bits 47:32 of a 48-bit address | E |
| `0x18` | error lower address | 4 | r | same | address bits 31:0 | E |
| `0x20` | widget 0 control | 4 | rw | `xbow_attach` writes 0x24; `xbow_errintr_handler` ANDs it with status; `idbg_xbowregs` | 0x24 sets bits 5 and 2 | E |
| `0x28` | packet time-out | 4 | r | `idbg_xbowregs` only | printed; the kernel never writes it | I |
| `0x30` | interrupt destination upper | 4 | rw | `xbow_intr_preset` writes; `idbg_xbowregs` reads | `(vector << 24) \| (target << 16 & 0xf0000) \| (address >> 32 & 0xffff)` | E |
| `0x38` | interrupt destination lower | 4 | rw | `xbow_intr_preset` writes; `idbg_xbowregs` reads | address bits 31:0 | E |
| `0x40` | error command word | 4 | rw | `xbow_errintr_handler` reads then writes 0; `xbow_error_handler`; `save_xbow_err`; IP30 PROM interrupt routine | bits 27:24 compared with the port number; the write of 0 re-arms the capture | E |
| `0x48` | LLP control | 4 | r | `idbg_xbowregs` only | printed | I |
| `0x50` | widget 0 status, read-and-clear alias | 4 | r | `xbow_errintr_handler` | read once per interrupt; bits 0, 2, 5 and 31:24 tested | E |
| `0x58` | arbitration reload | 4 | r | `idbg_xbowregs` only | printed | I |
| `0x60` | performance counter A | 4 | rw | `xbow_update_perf_counters`, `xbow_enable_perf_counter`, through a pointer to slot + 4 that `xbow_attach` stores | bits 19:0 count (mask 0xfffff), bits 22:20 link select | E |
| `0x68` | performance counter B | 4 | rw | same, second pointer | same | E |
| `0x70` | NIC | - | none | no scanned routine | none; see the reset section | U |
| `0x100` | link input buffer flush | - | none | no resolved routine | none | U |
| `0x108` | link control | 4 | rw | `xbow_attach`, `xbow_errintr_handler`, `xbow_enable_perf_counter`, `xbow_reset_link`; PROM link reset | see the entry below | E |
| `0x110` | link status | 4 | r | `xbow_link_alive`, `xbow_reset_link`, `xbow_error_handler`, PROM tests | bit 31 is "alive" | E |
| `0x118` | link arbitration upper | 4 | rw | `xbow_prio_bw_alloc`; PROM link reset writes 0 | four 8-bit lanes with a 5-bit count at the bottom of each, sources 8 to 11 | E |
| `0x120` | link arbitration lower | 4 | rw | same | same lanes, sources 12 to 15 | E |
| `0x128` | link status, read-and-clear alias | 4 | r | `xbow_errintr_handler`, `xbow_update_llp_status`, PROM link reset | read to consume errors; bit 31 and the error bits tested | E |
| `0x130` | link reset | 4 | w | `xbow_reset_link`; IP27 PROM and IP30 PROM reset routines (the IP35 PROM routine does not write it) | the value written is 0 | E |
| `0x138` | link auxiliary status | 4 | r | `xbow_widget_present`, `xbow_update_llp_status`, `xbow_error_handler`, PROM tests | bit 5 "widget present"; bits 31:24 and 23:16 summed as two byte counters | E |

Totals: 23 register kinds (15 common, 8 per link; 79 slots with the link family at eight links), graded **18
established, 3 inferred, 2 unknown**. The reserved slots `0x78` to `0xf8` and `0x300` upward are touched by no
scanned routine.

### Registers whose use is established by reading the code

- `0x20` control (`xbow_attach`, `xbow.o`, offset 0x220): the constant 36 (0x24) is stored to the low word after the
  interrupt is connected and before the port loop. It sets bits 5 and 2 and nothing else (established). Reset value:
  unknown; no routine reads the register before writing it (only `xbow_errintr_handler` and `idbg_xbowregs` read it
  afterwards).
- `0x30` and `0x38` (`xbow_intr_preset`, `xbow.o`, offset 0x9b0, read in full): `xbow_setwidint` takes a target, a
  vector and a 64-bit address from the interrupt object (`xtalk_intr_target_get`, `xtalk_intr_vector_get`,
  `xtalk_intr_addr_get`) and calls `xbow_intr_preset`, which writes `(vector & 0xff) << 24 | (target & 0xf) << 16 |
  (address >> 32) & 0xffff` to `+0x34` and the low 32 bits of the address to `+0x3c` (established). The values come
  from the interrupt layer at run time, so none is in `xbow.o` (see the vector question below). The handler it is
  connected to is `xbow_errintr_handler`.
- `0x50` status, read-and-clear (`xbow_errintr_handler`, `xbow.o`, offset 0xd1c, register traffic read in full): on
  entry it reads control (`+0x24`), the clear alias (`+0x54`), error command (`+0x44`), error upper (`+0x14`) and
  error lower (`+0x1c`), then writes 0 to `+0x44` at once (established). It forms the 48-bit address
  `(upper & 0xffff) << 32 | lower` and the source number `(command >> 24) & 0xf`, and compares that number with the
  port it is examining. In the clear-alias value it tests bits 0, 2 and 5 (the strings the object carries are
  "Multiple Error", "XIO Error" and "Register Access Error"), bit `24 + (port & 7)` for each link's request, and
  `(control & status) & 0x800000` for widget 0 (established). For a widget 0 error (bits 0, 2, 5) the routine prints
  raw register values (status, control, command, upper, lower) and counts; it does not pass the captured command or
  address to the error layer (established: no call follows on that path). For a link error with the illegal
  destination bit, when the command's source number equals the port, it calls `xbow_error_handler` with the address
  (established).
- `0x108` link control (`xbow_attach`, `xbow.o`, loop at offset 0x1ec to 0x27c, read in full): for each port 8 to 15
  whose link is alive (`xbow_link_alive`) and whose widget is present (`xbow_widget_present`) it replaces the control
  word by `(old & 0xfffffe2f) | 0x3002b`: it clears bits 8, 7, 6 and 4 and sets bits 17, 16, 5, 3, 1 and 0
  (established arithmetic). `xbow_enable_perf_counter` replaces bits 29:28 with the mode (0, 1 or 2; the range test
  rejects 3 and negative values). `xbow_enable_perf_counter` returns -1 when a1 is outside 8 to 15, a2 is outside
  0 to 2 or a3 is outside 0 and 1 (checked before the lock). Under the lock it also returns -1 when the counter's
  byte at +37 is nonzero and a2 is nonzero, or when the other counter has the same port (byte +36) and a nonzero
  byte at +37; it releases the lock first. It returns 0 otherwise.
  `xbow_errintr_handler` writes the port's control back with bit 3 clear when the call to `xbow_xmit_retry_error`
  returns 0 (that routine returns 1 after counting and writing back a bridge register for the two bridge parts it
  recognises, and also when it cannot look the port up); it also clears bit 17 in its local copy of the masked status
  after an illegal destination is handled, with no hardware write.
  `xbow_reset_link` reads it first and writes the same value back only on success: it returns 0 once bit 31 of the
  word at +276 of the port's block is set, and -1 when its timed wait expires first, which skips the write-back.
- `0x118` and `0x120` (`xbow_prio_bw_alloc`, `xbow.o`, offset 0x2458, read in full): the register is `0x11c + 0x40 *
  (port & 7)` for sources 8 to 11 and `0x124 + ...` for sources 12 to 15; the field is 5 bits at `8 * (source & 3)`;
  the routine adds or subtracts a count converted from a byte rate by `xbow_bytes_to_gbr` (a division by 0x3d0900 =
  4000000, rounded up) and refuses a result of 32 or more (established). `xbow_attach` fills an array of eight 64-bit
  values in its record with 0x2faf0800 (800000000) and another with 0; `xbow_prio_bw_alloc` compares sums with them.
  It returns 1 when it refuses the request and 0 when it stores it.
  It refuses when the new count (the request in register units plus the field's current value) is 32 or more, or
  when the request (a3) in bytes, rounded up to whole register units and converted back to bytes (negated when the
  request releases bandwidth), plus the 64-bit word at +528 of the element is above the word at +464 (unsigned
  compare). The element is 8 bytes at the record base plus 8 times the element index (a2).
  Their role as a bandwidth budget is inferred from the names.
- `0x130` link reset (`xbow_reset_link`, IP27 `xbow.o` offset 0x21f4, IP30 0x1e3c, IP35 0x1dfc): save control, write 0
  to `+0x134`, delay `xbow_reset_delay` microseconds, poll status bit 31 with `us_delay` until set or a limit, restore
  control (established). It returns 0 on success and -1 on timeout. The IP30 build takes the window from a constant
  (0x9000000010000000) where the others use the record pointer.
- `0x138` auxiliary status (`xbow_update_llp_status`, offset 0x1cd4, read in full): for each link it reads the
  auxiliary word (`+0x13c`) and then the clear alias (`+0x12c`); if the alias value has bit 31 set it adds bits 31:24
  to one 64-bit total and bits 23:16 to another, and it warns about any bit in `0x7fffffe7` (all but bits 4 and 3 and
  bit 31). The order, auxiliary before clear, is established; that the clear alias also clears the counters is the
  specification's statement (compared below) and is not observable here. It reschedules itself every 100 ticks while a
  flag at record offset 452 is set.
- `0x60` and `0x68` performance counters (`xbow_update_perf_counters` offset 0x19c0, `xbow_enable_perf_counter` offset
  0x1ae8, read in full): `xbow_attach` stores `xbow + 0x64` and `xbow + 0x6c` (the low words) in the two counter slots
  of its record (established). Enable: write the mode into the link control, then clear 0x700000 in the counter word and
  write `(port - 8) << 20` there to select the link. Update: read the word, take `(word - last) & 0xfffff`, add it
  to a 64-bit total indexed by `(word >> 20) & 7`, store the new low 20 bits as `last`; it runs every 4 ticks
  (established). The census shows the control write as a negative-displacement row (`0x40 * port - 0xf4`, which is
  link control `0x10c + 0x40 * (port - 8)`) in `census-windows.tsv`.
- Error save (`save_xbow_err` in the IP27 and IP35 `kernel.o`; the PROM routines at IP27 PROM `0x1fc08ff0`, I/O-board
  PROM `0x11c39e00` and IP35 PROM `0x1fc0aeec`): read status (`+0xc`), error upper (`+0x14`), error lower (`+0x1c`),
  error command (`+0x44`), and for each of the eight links the status (`+0x114 + 0x40 * n`) and auxiliary status
  (`+0x13c + 0x40 * n`); none writes (established). The window is a constant plus the node number in bits 63:32; the
  kernel object uses 0x92000000e0000000 and the PROMs 0x9200000000000000 for the same widget, so the constant is the
  processor's view and not a property of the chip.
- The "link usable" test: `xbow_widget_present` (offset 0x864 in IP27 `xbow.o`) returns link auxiliary bit 5, except
  that for part 0xd100 with manufacturer 0 on port 15 it returns 1 without reading it; `xbow_link_alive` returns link
  status bit 31. The IP27 PROM (`0x1fc44bbc`) and IP35 PROM (`0x1fc4f3ec`) routines return 1 when both are set; for part 0xd100
  they return 1 for port 15 with neither bit read and without testing the manufacturer; otherwise present with alive
  clear prints "Widget present, but link not alive" and returns 0. The IP30 PROM routine (`0xbfc094f4`) is only
  "present and alive" (established, all read in full).

## PXBOW (part 0xd100)

- **Established.** `xbow_widget_present` and `xbow_error_handler` (`xbow.o`, all three builds) read the
  identification word and, when the part (bits 27:12) is 0xd100 and the manufacturer (bits 11:1) is 0, treat port 15
  as present without reading its auxiliary status. The test is in the IP27 and IP30 objects too, so it is carried by
  every build, not only IP35. The kernel still reads link status bit 31 separately; the IP27 and IP35 PROM routines
  waive both bits for port 15 and do not test the manufacturer (docs/questions/tezro-widget-11.md records the IP35
  routine).
- **Inferred.** The part that answers 0xd100 is the integrated crossbar the IP35 PROM and kernel expect on the IP53
  node board. The binaries carry no such name for it beyond the string `pxbow_port_io_enabled` in the IP35 kernel
  object; the link to the part number is reasoned from the use of 0xd100 in the PIC-class code, not read.
- **Established, small.** No register offset is specific to part 0xd100: the census has two `pxbow` rows (slots 0x0
  and 0x138 only).
- **Unknown.** Whether a PXBOW has registers beyond the Crossbow map or the same map: the specification held here
  predates the part (revision 12.0 gives part 0). The same applies to part 0xd000, which the PROM routes down the
  crossbar path (docs/questions/tezro-widget-11.md).

## Access sequences

**Attach and initialisation (established: `xbow_attach`, `xbow.o`).** In order: map the registers (768 bytes at
offset 0), read the identification word, build the record (the two counter pointers, the two arrays), allocate and
connect the interrupt (`xtalk_intr_alloc`, `xtalk_intr_connect` with `xbow_errintr_handler`, which reaches
`xbow_intr_preset`), register `xbow_error_handler` with `xwidget_error_register`, write widget 0 control 0x24, then
for each port 8 to 15 test alive and present and set link control as above; last, `xswitch_provider_register` with
`xbow_provider`. Nothing in `xbow.o` writes the packet time-out, the LLP control or the arbitration reload, so those
keep whatever the PROM or reset left (reset values unknown).

**PROM link bring-up (established, three small routines read in full).** IP27 PROM `0x1fc43758` and IP35 PROM
`0x1fc4bd30` take the port in the second argument: read the link's clear alias (`+0x2c` of the link block), write link
control `0x00080000` (bit 19: the LLP widget credit field 22:18 set to 2, every other bit clear), write both
arbitration registers 0, [IP27 PROM only] write link reset 0, then poll link status bit 31 up to 100 times with a call
that takes 10. The IP30 PROM routine at `0xbfc6b198` reads link status once, writes control 0 (not 0x80000), both
arbitration registers 0 and reset 0, and does not poll. The IP35 PROM routine does not write the reset register.
docs/questions/tezro-widget-11.md reads the same IP35 routine and the credit table that follows it.

**Error interrupt (established for the register traffic: `xbow_errintr_handler`).** See `0x50` above. After the reads
it re-arms by writing 0 to the error command word, handles each link whose request bit is set, and reports through the
kernel error layer (`cmn_err`, `xbow_error_handler`, `xem_add_ioe`; the layer is not read).

**IP30 PROM interrupt service (established: `0xbfc6ac2c`, read in full).** Reads status (`+0xc`); if `status &
0xff800000` is zero it returns the status. Otherwise, for each port 8 to 15 whose request bit `24 + (port & 7)` is
set, it reads the link status (`+0x114`) and auxiliary status (`+0x13c`) and prints them. A flag starts as `status &
0x24` and becomes 1 if any such link status has bit 17 or bit 1 set; when the flag is set it prints the error command,
upper and lower words and, when its second argument is nonzero, writes 0 to the error command word. It never reads a
clear alias (established); where those errors are cleared is not in this routine.

## Against the published specification

The comparison covers every register the census reached: all 33 slot rows are in the specification's map
(`census.tsv` column `spec` is `present`; the two `pxbow` rows are outside the scope of revision 12.0). Page numbers
are the printed pages of the Crossbow ASIC Specification, revision 12.0.

**Agreements (read in the code first):**

- Identification (p. 85): revision 31:28, part 27:12, manufacturer 11:1. The code's `rev | part << 4` uses the same
  split; the specification's part value for the Crossbow is 0 and `is_xbox_config` tests 0.
- Widget 0 status (pp. 88 to 89): bit 5 register access error, bit 2 crosstalk error, bit 0 multiple error, bit 23
  widget 0 interrupt request, bits 31:24 link F to link 8 interrupt requests. The kernel's strings and tests use bits
  5, 2, 0, 23 and `24 + n` the same way.
- Widget 0 control (p. 90): bit 5 interrupt on access error, bit 2 interrupt on crosstalk error. The kernel writes
  0x24, which is those two bits.
- Interrupt destination (p. 87): upper 31:24 vector, 19:16 target, 15:0 address bits 47:32; lower is address 31:0.
  The kernel's packing matches.
- Error command word, upper, lower (pp. 85 to 86): command 27:24 is the source number (the kernel compares it with
  the port), upper 15:0 is address 47:32; a write to the command word re-arms the capture (the kernel writes 0 after
  reading).
- Link control (pp. 77 to 79): the kernel sets 0 and 1 (source time-out, max request time-out interrupt enables), 3
  (LLP transmit retry), 5 (LLP max retry), 16 (overallocation) and 17 (illegal destination), and clears 4, 6, 7 and
  8 (receiver error, the two counter overflows, bandwidth allocation error); 29:28 are the performance monitor mode;
  22:18 the LLP widget credit, default 2 (the PROM writes 0x80000, field value 2).
- Link status (pp. 79 to 81): bit 31 alive; bits 0, 1, 3, 4, 5, 6, 7, 16, 17 and 18 are the error flags the kernel
  prints, in the specification's meanings (its strings: "Source Timeout Error", "Maximum Request Timeout", "LLP
  Transmitter Retry", "LLP Receiver error", "LLP Max Transmitter Retry", the two counter overflows, "Input
  Overallocation Error", "Invalid Packet Destination", "Multiple Errors").
- Link auxiliary status (p. 81): bit 5 widget present; bits 31:24 and 23:16 byte counters. The kernel sums both and
  does not name which is receive and which transmit; the specification names 31:24 receive.
- Link arbitration upper and lower (pp. 82 to 84): four 8-bit lanes, a 5-bit count in 4:0 and a 3-bit weight above;
  upper is sources 8 to B, lower C to F. The kernel's lane arithmetic matches.
- Performance counters (p. 91): bits 19:0 value, 22:20 link select; the kernel reaches them at slot + 4.
- Link reset (p. 84): write-only; the kernel writes 0.

**Conflicts: none found** among the registers touched. Differences that are not conflicts:

- **Part numbers.** The specification gives the Crossbow part as 0 and no other. The code also reads 0xd100 from the
  chip (PXBOW above). A revision gap: revision 12.0 is dated 18 November 1996.
- **Access width.** The specification says the registers are reached "by Crosstalk double-word packet type only" with
  the data in 31:0 (byte enables 0x0f) and that any other size is a register access error. IRIX issues only 32-bit
  loads and stores at slot + 4. They agree only if the processor-side node controller turns a 32-bit uncached access
  into a double-word packet with enables 0x0f, which is that chip's contract and is **inferred** here, not read.
- **A bit reused by the PROM.** The I/O-board PROM treats bit 0 of link arbitration upper as an "already claimed"
  marker (docs/questions/tezro-widget-11.md, established there). In the specification that bit is the least
  significant bit of the link 8 guaranteed-bandwidth count. A use the specification does not describe, not a
  contradiction of the layout.
- **Not confirmed by the code.** NIC (specification: "not functional", p. 93), input-buffer flush, and the writes of
  packet time-out, LLP control and arbitration reload are not reached by any scanned routine, so their specification
  fields are unconfirmed.

## Error reporting for a refused or timed-out register write

What the chip sets, latches and signals when an uncached store to it is refused or times out. Each item carries its
grade; the first three are answered from the published specification (the binaries only read the bits), the rest are
open.

1. **What sets each error bit? (established by the specification; the code only reads the bits.)** Widget 0 status bit
   5, register access error: a request to a reserved widget 0 address, a write to a read-only or read-and-clear
   register, a read of a write-only register, or a request that is not a double-word packet (specification p. 89, and
   the widget 0 error table on pp. 69 to 70, which also lists "Request Packet Invalid Address" and any size
   mismatch). Bit 2, crosstalk error: a request packet with the command-word error bit or the sideband-invalid bit.
   The connection time-out bit: widget 0 cannot deliver a response or an interrupt packet within the packet time-out.
   The link status bits are listed in the link controller error table (pp. 67 to 69). The binaries confirm the
   bit-to-message mapping (strings and tests above) and never cause one of these errors.
2. **What is latched on a failed or timed-out register write? (established by the specification for widget 0
   errors.)** For a register access error, and for the other widget 0 errors in that table, the 48-bit Crosstalk
   address goes to the error address registers (upper 15:0 = bits 47:32, lower = bits 31:0) and the command word to
   the error command word register; the registers accept only the first erring packet until a write to the command
   word clears them (pp. 65, 69 to 70, 85 to 86). The published page therefore states the capture content for an
   access error, not only for the illegal-destination case. The IRIX code does not use the captured values for a
   widget 0 error (it prints them raw), so no binary shows what the registers hold after a refused write: **unknown
   by observation**. For a link-level time-out (source
   time-out, max request time-out) the specification sets the link status bits and, for max request and max retry,
   marks the affected sources in auxiliary status bits 15:8; it does not say the packet's command or address is
   captured: **unknown**, and the kernel never reads bits 15:8.
3. **Which interrupt vectors fire? (mechanism established; the number is software-chosen.)** The Crossbow sends an
   interrupt as two double-word write packets to the address in the interrupt destination registers: the first, when
   the condition occurs, with the vector in data bits 7:0 and bit 8 set; the second, when every condition is cleared,
   with bit 8 clear; only one interrupt is outstanding however many errors occur (specification pp. 64 to 65). There
   is one vector field (bits 31:24 of interrupt destination upper) for widget 0 and every link. IRIX writes it in
   `xbow_intr_preset` from `xtalk_intr_vector_get`; the interrupt layer allocates the number at run time, so which
   number a product uses is **unknown** from `xbow.o`. Route: the interrupt-allocation code for the node controller
   and for HEART, and any PROM routine that programs `0x30`: not read. Which processor interrupt level the vector
   reaches belongs to those chips' pages.
4. **How a processor's 4-byte access reaches a double-word-only register file. (inferred.)** See the width note above.
   Route: the processor-interface censuses of the node controller and HEART.
5. **What a second error does to the capture and the flags. (unknown.)** The specification says later errors are not
   logged until the command word is written; no code reads a second-error case. Route: none from software; a
   measurement or a published erratum.
6. **PXBOW registers. (unknown.)** Whether the part has the Crossbow's map beyond the identification and link
   registers the code reaches. Route: the IP35 PROM's large crossbar routines (listed in docs/open-questions.md).

## Reset expectations

Unknown for every register: no routine in the objects read reads a register before writing it, except link control
(`xbow_attach` read-modify-write, `xbow_reset_link` save and restore). The specification gives defaults (zero except
packet time-out 0xfffff, arbitration reload 2, interrupt target field 8, link widget credit 2), compared only: no
binary confirms them. NIC and the input-buffer flush: no shipped software touches them in the routines read; routes
tried: the census of three kernel objects and four PROM images, and the PROM's large diagnostic routines (not read in
full). The PROM writes link control 0x80000 and zeroes both arbitration registers on every link it brings up.

## Open

See docs/open-questions.md: the PROMs' large crossbar routines (initialisation, credits, arbitration, diagnostics) that
take their window pointer from a record field, the input-buffer flush use, the packet time-out, LLP control and
arbitration reload values, and the interrupt vector assignment.
