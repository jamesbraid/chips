# Bedrock I/O interface (II)

The I/O interface is the Bedrock's crosstalk port: the unit a crossbar or XBridge talks to, and the unit that
processor programmed I/O to widgets leaves through. It also holds the two block transfer engines (BTEs). Its
register layouts, with a grade on each field, are in [devices/bedrock_ii/registers.toml](registers.toml); the
generated reference is [devices/bedrock_ii/registers.md](registers.md). The chip-level context is in
[crosstalk-host-ends.md](../crosstalk/host-ends.md), and the internal crossbar is in [bedrock-crossbar.md](../bedrock_xb/README.md).

No Bedrock specification is held. The sources are the SN1 register headers in the public Linux 2.5.40 tree, the
public Linux ia64 consumers, OpenBSD's SGI crossbar code, the out-of-tree Linux MIPS IP35 port, and two SGI
manuals (the Origin 3000 System Architecture, 108-0240-002, for the unit's role, and the Origin 300 field
diagnostics, 108-0264-004, for its vocabulary). IRIX 6.5.30 kernel behaviour and the stock IP35 PROM 6.210 come
from disassembly, which is a software expectation and not a hardware read. The verification pass re-read the register
offsets against the Linux 2.5.40 header (`include/asm-ia64/sn/sn1/hubio.h` in the `references/code/linux-2.5.40` pin) and
did not re-read the disassembly statements below, which are therefore unverified. The widget part numbers `0xc104` and
`0xc105`, the window base `0x1c00000` and the request-buffer field meanings were removed because their only basis was a note
of another project, not a binary read here. Route for those: read the IP35 kernel's I/O error scan and widget probe in full.
Every fact below is graded in the defs file or here.

Reset fetch, the compatibility segment (ckseg1) and the Bedrock node number, as the PROMs and IRIX use them: [platforms/decode-reset-and-kseg1.md](../../platforms/decode-reset-and-kseg1.md).

## Block transfer engines

Each engine has six registers (length and status, source, destination, control, notification address and
interrupt address). Lengths are in 128-byte cache lines, and the 40-bit addresses have their low seven bits zero.

- The header describes the protocol. A legitimate write to length-status sets busy, clears error and loads the
  length. The hardware decrements the length as each line completes and clears busy at the end. Software writes
  busy with the length first, then source, destination, notification address and control. Writing the control
  register starts the transfer. Reading it ends any transfer in progress, and stopping one engine can disturb the
  other. These are inferred from the header's comments; the header does not give a timing.
- Whether busy is ever visible after a start, and how fast an engine moves data, are unknown. No source gives
  either.
- The notification address receives one completion write, which carries the final length-status value. The
  header's text calls this a write-invalidate.
- The public Itanium consumer sets its notification line to all ones, programs the transfer and then waits for
  the line's busy bit to clear. It also copies length-status into the line itself after a delay. Its comment
  says this works around notification failures seen on real SN0 and SN1 hardware. That report is the only
  hardware evidence for it, and it is not reproduced here, so the failure's cause and its effect on the Bedrock
  are unknown.
- The public Itanium tree's copy routine has no caller at the reviewed tag. The engines are set up and never used
  there.
- The stock IP35 PROM's hub check (disassembly) fills four 512 KiB buffers, starts engine 0 and then engine 1 with
  two back-to-back stores, and polls processor interface 0's pending register for engine 0's level alone. It then
  compares both copies. It passes when engine 1's copy lands before the second compare reads it. That engine 1
  finishes shortly after engine 0 is an inference from the two stores issuing together. No source gives the
  engines' throughput, so the check's timing margin is unknown.
- The completion interrupt goes where the engine's interrupt-address register says. The PROM check programs that
  register; no public consumer does.
- The header's poison bit has no effect described in any public source. Its behaviour is unknown.

What would settle the engine questions: a throughput measurement and a read of busy after a start on an
Origin 300, and a failure case from the vendor's diagnostics (none held).

## Processor PIO and widget access

- Local access protection resets to all ones (the header states this). A processor PIO is performed only when the
  requester's region bit is set; otherwise the access gets an error response. A widget PIO also needs its outbound
  widget bit.
- The protection override register takes a 64-bit ASCII key, which sets the writer's own region bit. The header
  union gives only nine bits for the same field. Nothing public writes it, so the field's width is unknown. A write
  through the local alias does nothing.
- The stock PROM sets the outbound and inbound widget masks to enable widget 0 and widgets 8 to F (disassembly). It
  does not write the device error mask, as far as the disassembly reaches. The disassembly does not decode a
  compressed PROM segment, so a store there is not ruled out.
- IRIX never writes local access protection or the inbound mask. It saves the outbound mask, writes zero, programs
  the PIO request buffers and restores the saved value (disassembly). Unregistering a PCI device clears its device
  bit; registering one sets it.
- Inbound requests from a widget pass only when the widget's inbound bit and the requesting device's bit are both
  set. The header defines a device as an individual DMA master hosted by a widget. A request that carries no device
  number has no source for that bit. How a request's transaction number maps onto the eight device bits is unknown.
- The Bridge specification (revision 4.0, page 88) sets read transaction numbers to the read response buffer number
  (0 to 15), PCI writes to 0x10 plus the device number and interrupt writes to 0x18 plus the device number. The
  II's use of those numbers is not described in any public source.
- What a refused inbound request produces (an error response, a discard, or an interrupt) is unknown.
- Device error mask: the header says its bits are set by writing one. IRIX clears a device by writing back the old
  value with that device's bit cleared. Under write-one-to-set that write clears nothing.
  no-op on the hardware. Which behaviour the hardware has is unknown. A read of the mask after the same write on an
  Origin 300 would settle it.
- The misc error mask (`0x4001e8`) is write-one-to-set in the header. The companion header calls bits 0, 4 and 8
  shut-down flags, and the IRIX error handler reads them that way. The register description and the later chip's
  recovery write both say a source is re-enabled by setting its bit, so the bits read as enables. The reset value
  of 0x111 (widget 0 and both engines enabled) is inferred from that recovery write. A read after PROM hand-off on
  an Origin 300 would settle it.

## Link control and the PROM's link test

- Bit 13 of link control and status is link up. Both public Linux ports skip the node's crosstalk when it is clear.
  Bits 12 and 13 are the two-bit status field, and the meaning of its other values is unknown.
- The stock PROM reads the register first and tests bit 13 before it touches widget 0 (disassembly). With bit 13
  clear it skips every widget 0 access. With bit 13 set it reads widget 0's identification and, for a crossbar or
  bridge part, writes 0xff to widget 0's registers at offsets 0x84 to 0xbc. On either path it writes the register back
  with bit 8 set.
- Bit 14 (remote power) is named in the header with no text. Its meaning is inferred from the name only.
- With the I/O brick off or held, bit 13 is inferred to read zero. The public architecture guide says a link whose
  send logic stopped at its retry limit stays stopped until it is reset, so a link that was up before the brick was
  switched off may read down until a reset. The value with a cable to a powered-off brick, and with no cable at all,
  is unknown. Settling both needs a boot print of the link status from a C-brick with the cable absent, and another
  with it joined to a powered-off brick, or the status-field text in the II specification.

## Interrupts

- The II's own error interrupt uses the destination register. Its PI select picks one of two hard-coded addresses
  on the named node: `0x1800090` for PI0 and `0x1a00090` for PI1 (header). Forwarded-interrupt pending bits 32 and 33
  record the forwarded ones, and error clear bits 30 and 31 clear them.
- The header defines no decode from a widget-side address to a hub unit, so whether an inbound widget write to
  either address reaches the interrupt-pending register is unknown.

## Widget status layouts differ between the II and the crosstalk widget layout

The generic crosstalk widget status puts its pending count in bits 4:0 and a receive count in 31:24. The II's
status puts pending in bits 3:0 and has no receive count. The generic control register has its credits in 15:12,
and the II's in 15:13. Which layout a crosstalk read of widget 1, offset 0x8 or 0x20, returns is unknown. No
consumer reads either through crosstalk.

## DMA routing

The node number for a request with crosstalk bit 47 clear is in bits 39:33 on the SN1 chip. No public header
decodes it. The only public crosstalk memory-address text is the SN0 form with the node in bits 39:32, which is
stale for the Bedrock, so the routing stays unknown until a second node exists to test it.

## Open questions and the test that settles each

| Question | What would settle it |
|---|---|
| Whether busy is visible after a start, and engine throughput | A busy read after a start and a timed transfer on an Origin 300 |
| Whether the device error mask clears by write-one-to-set or by write-back | A read of the mask after the same write on an Origin 300 |
| Reset values of the misc error mask and the device error mask | A read of both after PROM hand-off on an Origin 300 |
| Direct-connect (widget control bit 17): whether any PROM sets it | A trace of the held PROM's writes to widget control, or a read after hand-off |
| Whether a PIO aimed at the Bedrock's own crossbar port reaches the Bedrock | The PROM's crossbar record port flags, or an Origin 300 console log showing which port OpenBSD attached at the hub |
| Link status field values, and bit 14 | A link-status print with the brick off, or the II specification's status-field text |
| The response to a refused inbound request | A capture of a refused DMA on hardware, or the II specification |
| Poison bit behaviour | The vendor's own diagnostic output, or the II specification |
| Protection override field width | The II specification; nothing public writes the register |
| Mapping of transaction numbers onto device bits | The II specification, or a device-to-bit capture on an Origin 300 |
| Node bits of a DMA address | A second node, or the II specification |

## Review

Independent review of the Bedrock I/O and crossbar additions at chips commit 603bf52: the 16 newly named I/O offsets, the I/O and crossbar field layouts and rsvd masks, the manufacturer constant and the 60-bit resets. The reviewer wrote none of them. Sources were the SN1 `hubio.h` and `hubxb.h` of the Linux 2.5.40 tree at the pinned commit (fetched as single files), and the stock IP35 PROM 6.210 image for the register table.

**Checked.**
- All 126 fields of `registers.toml` (II) and the crossbar fields that cite a header member were compared by script with the first (low-bit-first) structure of the named `ii_*` or `xb_*` union: 126 of 126 positions match, none missing. Of the 25 `rsvd` masks, 22 match the members named reserved or unused by script; the other 3 (`xb_poq1_error`, `xb_piq1_error`, `xb_mp1_error`) were checked by hand against the first-instance structures, whose reserved members are spelled `rsrvd` and which include the unused bits.
- The 16 new register offsets equal the header's `#define` values, and each doc says the long name is ours. Access is rw (widget status r) and graded inferred, as the header gives none.
- `MANUFACTURER_BEDROCK` 0x24: bits 11:1 of 0x1c110049 and of 0x23012049 are both 0x24, and the Hub reset 0x1c101048 reads the same. The part fields (0xc110, 0x3012) match the header constants. Inferred is the right grade: it is read off two table resets with no silicon read, and 0x24 equals what the inventory recorded as the table value. The old 0x36 came from a vendor grouping in OpenBSD and agreed with no reset in this map.
- The register table of the PROM image was decoded directly (24-byte register records, 16-byte field records, reset in the last eight bytes). Exactly three single 64-bit fields have the reset 0x0fffffffffffffff: offsets 0x400100 (II local access protection), 0x604000 (LB CPU permission) and 0x604020 (LB region present).
- The inventory's 21 mismatches: no register's offset, access, width, reset or grade changed in these commits (generated JSON compared before and after); only `MANUFACTURER_BEDROCK` changed value, which resolves inventory item B1 and moves it onto the reset values as that item recommended. ci-check exits 0.

**Findings.**
1. **Duplicate definitions.** Offsets 0x400008, 0x400220 and 0x400228 are now defined twice: `bedrock_extra` as `ii_widget_status`, `ii_error_header_1`, `ii_error_header_2` (access r, graded established, reset from the PROM table) and `bedrock_ii` as `widget_status`, `incoming_error_header_1`, `incoming_error_header_2` (the first r, the other two rw, all inferred, with fields). The pair at 0x4001e8 (`ii_shutdown_status` and `misc_error_mask`) was already a duplicate. The export has both: unit `extra` and unit `ii`, so iris would see two names for one register, and two access letters for the error headers. The field constants in `extra` (for example `II_ERROR_HEADER_1_PRINT_GATE`, bit 44) are the same bits as the `ii` fields (`valid`). Recommendation, not applied because it removes names a consumer may use: keep the `ii` unit as the single definition; delete the four `bedrock_extra` register rows and move its field constants onto the `ii` registers (or mark them as aliases); set the two error headers to r in `ii` to agree with the established row, or drop the established claim. Until then iris should read these four registers from unit `ii` only.
2. **The 60-bit resets stay.** The author kept 0x0fffffffffffffff and recorded the decode, but the stated reason was wrong: "no other 64-bit field in the table has an all-ones reset". The table also has single 64-bit fields that reset to all 64 bits set, in the processor interface block (offsets 0x0, 0x10 and 0x18) and for the first register of the memory-directory block. So the table can write 64 set bits, and the three 60-bit records are deliberate. That strengthens the decision to keep the value; the docs of the three registers now say it (fixed in this review). Whether silicon reads the top four bits clear is still unknown, and no change of value or grade is warranted: the reset is a table value, graded established as the others from that table are.
3. The cited tree is the 2.5.40 pin; the Library's copy of the same header sits under a different revision label and was not used.

Resolved after review: devices/bedrock_ii: keep one definition of the four registers named twice

**Cleared:** the 126 field positions, 25 rsvd masks, 16 names and offsets, the manufacturer decode and the 60-bit decode. **Not cleared:** access types of the new registers (inferred), the second-instance crossbar layouts (graded inferred), and the resolution of finding 1.
