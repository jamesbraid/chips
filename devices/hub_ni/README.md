# Hub network interface

The Hub network interface is the port onto CrayLink, the fabric that joins nodes. Its registers sit
in the Hub register space from `0x600000` to `0x638180`: the port parameters and port error registers
at `0x608000`, and the routing tables at `0x638000`. The register list, the census reach and the
reset-value status are in [devices/hub/registers.md](../hub/registers.md). The field layouts added here are in
[devices/hub_ni/registers-extra.md](registers-extra.md), built from
[devices/hub_ni/registers-extra.toml](registers-extra.toml).

## Added from the public header

The field layouts, enumerations, the offsets the census does not reach, and the software default
constants come from the public Linux SN0 Hub network interface header (Linux v7.2-rc7). The header
gives names, masks and shifts. It gives no access types and no reset values. So the access of each
register added here is an assumption and is graded inferred, the reset of every register stays
unknown, and the header's default constants are graded inferred as values software writes.

- **Status, revision and identity.** Eight-bit mode at bit 30, link-up at 29 and the down reason at
  28. The header's comment says the down reason reads 0 for a link that failed and 1 for one that
  never came out of reset. Bit 18 selects more memory or more nodes, bit 17 selects fine or coarse
  regions, the node number is nine bits at 16:8, the chip revision four bits at 7:4 and the chip
  identity four bits at 3:0.
- **Port reset.** Warm reset at bit 7, link reset at bit 1 and whole-Hub reset at bit 0. The header
  gives no read value for this register.
- **Protection and diagnostic parameters.** The protection configuration has one bit, which the
  header names as permitting reset. The diagnostic parameters have port timeout reset at bit 18,
  eight-bit link mode at bit 12, port disable at bit 6 and send data error at bit 0.
- **Global parameters.** Maximum retry count in ten bits at 57:48, tail timeout wrap in sixteen bits
  at 47:32, credit timeout in four bits at 19:16 and tail timeout in four bits at 7:4.
- **Port parameters.** Maximum burst in ten bits at 9:0. The null-packet timeout is six bits; see the
  first open conflict below for its position.
- **Vector routing.** The parameters register holds an access identifier, a write identifier, a
  register address at 19:3 and a two-bit operation. The status register holds valid and overrun
  bits at 63 and 62, a source field, the echoed identifiers and address, and a three-bit response
  type. The header names the response types 0 read, 1 write, 2 undefined, 3 exchange, 4 address
  error, 5 command error, 6 protection error and 7 unknown, and says a type with bit 2 set is an
  error. The header gives no meaning for the source field.
- **Port error.** Link reset at bit 37, internal error at 36, bad message at 35, bad destination at
  34 and queue overflow at 33. Four error counts follow: credit timeout at 31:28, tail timeout at
  27:24, retry at 23:16, check-bit errors at 15:8 and sequence-number errors at 7:0. Bit 32 is outside
  the header's error mask and has no name. Each counter's maximum is 0xff.
- **Ageing controls.** Virtual channel at 11:10 with three named values (A, B and any), a two-bit
  congestion field at 9:8 that the header gives no values for, and an eight-bit age at 7:0. The
  census names the CPU 0 and CPU 1 memory controls. The header also names the CPU PIO controls, the
  block-transfer engine controls and the I/O memory and PIO controls, which this unit adds at their
  header offsets.
- **Routing tables.** The header gives 32 meta entries and 16 local entries, each eight bytes apart.
  The census names entry 0 of each. The entry width is not in the header, so entries 1 to 31 and
  1 to 15 are added as arrays with no width.
- **Other offsets the census does not reach.** The return vector, the PIO protection bits and their
  override register, and the port parameters register are added at their header offsets. The override
  register's unlock value is not in the header and is not imported.

## Open conflicts inside the public header

These are recorded in the unit rather than resolved.

- **Null-packet timeout.** The header gives this field a shift of 10 and a mask of six bits at bit 16.
  The shift and the software default put it at 15:10, which is the position used here, graded inferred.
- **Vector parameters, access identifier.** The header's mask covers 49:40. Another source places the
  top bit at 50. This unit follows the header.
- **Vector status, source field.** The header's mask covers 60:51. Another source gives it one more
  bit. This unit follows the header.
- **Credit-timeout comment.** The header's comment on the credit-timeout field repeats the comment on
  the field above it. The name used here is the mask's own name.
- **Stability.** The header says every register in it is subject to change until tapeout. The
  layouts are graded established as the header's content, and any later revision of the header is a
  reason to recheck them.

## What stays open

- The access type and reset value of every register in this interface. The public header gives
  neither, and the census reads only some of them.
- The meaning of the vector source field and of the congestion field, and the entry width of the
  routing tables.
- What a vector operation returns when nothing answers it. This is the central question for a
  single-node machine that software still launches vector operations on. It needs a read on hardware
  or a hardware document.
- The behaviour of the link on reset, warm reset and forced width, and the timing of each. None of it
  is imported here.
- Whether a Hub with no cabled peer reports its link as down for the reason the header names. No
  register read from such a machine is held.

## Left out

Facts in this area that rest on the vendor's own kernel and PROM source, on firmware disassembly
that this repository does not hold, or on behaviour chosen for a software reconstruction rather than
observed on hardware, are not imported. Among them are the reset and access values in the vendor's
register table, the vector-operation sequences and their counts, the link-reset sequence and its
timing, the no-peer down reason, the power-fail workaround that switches link width, and the
interrupt that the error bit raises. Each needs a binary read in this repository, or a hardware
capture, before it can be imported.
