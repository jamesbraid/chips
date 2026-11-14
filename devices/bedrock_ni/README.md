# Bedrock network interface (NI)

The network interface is the Bedrock's NUMAlink port. Its registers sit in the node's register space from `0x680000`
to `0x682000`: 13 control, status and error registers, one 128-entry local routing table and one global routing entry,
142 registers in all. Register layouts, with a grade on each field, are in [devices/bedrock_ni/registers.toml](registers.toml);
the generated reference is [devices/bedrock_ni/registers.md](registers.md). The name map for the port
(`LINK (NI)` on the C-brick) is in [interconnect-naming.md](../../evidence/interconnect-naming.md). The neighbouring units are the
[local block](../bedrock_lb/README.md), which holds the node's identity and the vector engine, and the
[I/O interface](../bedrock_ii/README.md).

No Bedrock specification is held, and no read of the port on hardware is recorded. The sources are the public Linux
2.5.40 SN1 register headers (`include/asm-ia64/sn/sn1/hubni.h` and `hubni_next.h` in the `references/code/linux-2.5.40` pin,
`7570df54ef8c`; the offsets, field positions and the port-parameters default were re-read there in a later verification pass). They give register names, offsets, widths and
field positions, and a few comments. The headers state no reset value for any register. So every field is graded from
the header alone, and a comment's claim about behaviour is graded inferred.

Reset fetch, the compatibility segment (ckseg1) and the Bedrock node number, as the PROMs and IRIX use them: [platforms/decode-reset-and-kseg1.md](../../platforms/decode-reset-and-kseg1.md).

## Link status and reset

- Port status has a two-bit status field. The header names bit 1 link up and bit 2 remote power. It gives no encoding
  for the status, so bit 0 has no stated meaning. Bit 1 meaning link up rests on the name alone.
- Port reset is a write-only trigger with three bits: link reset out (bit 0), port reset (bit 1) and local reset (bit 2).
  The header's comments say bit 1 sends a warm reset over the link and bit 2 resets this Bedrock. What the far end does
  with a link reset is not stated.
- Reset enable has one bit. The header's comment says it lets a reset arriving over the link reset the Bedrock. The header
  does not say whether the same bit gates a local reset, so that is unknown.
- Diagnostic parameters carry three bits, named send data error, port disable and send error off. The header gives no
  behaviour for them beyond the names.

## Virtual channels and link parameters

- Channel control selects a virtual channel for each message class: one, two, nine and vector, for requests and for
  replies (bits 0 to 7), and a send channel select (bit 8). The header gives no encoding beyond the names.
- Channel test exposes the link test logic: a 20-bit seed, an 8-bit mask, a 20-bit data field, valid, check-bit
  error, a three-bit flit field, clear and error-capture bits. The header gives the layout only.
- Port parameters hold the maximum burst (9:0), null timeout (15:10), maximum retry (25:16), data-available select
  (27:26), first-error and squash-error enables (29 and 30) and one virtual-channel error enable per channel (34:31).
  The header names a reset-defaults value for them, `0x7a3ff1bf0` as the header's macro builds it. The header gives no
  source for it, so it is inferred as a header claim and not a hardware reset value.
- Channel age holds a request injection age (7:0) and a reply injection age (15:8). The header's comment says a higher
  reply age gives replies priority over requests when the network is saturated. That is inferred from the comment.

## Errors and the network interrupt

- Port errors holds eight-bit sequence-number, check-bit and retry counts (7:0, 15:8, 23:16), four-bit tail-timeout
  and FIFO-overflow counts (27:24, 31:28), four-bit external and internal short, long and bad-header counts (35:32 to
  51:48), and a link-reset-in bit at 52. The header's comment says the eight-bit counters do not wrap and that bits 52
  to 24 assert the network interface interrupt. The interrupt statement is inferred from the comment. The header does
  not say which processor-interface pending bit, if any, receives it.
- Port header A and port header B hold the captured header of an erroring packet: a valid bit, age, direction,
  destination, command, prexsel and address fields in A, and supplemental, source and address fields in B.
- Port sideband carries eight sideband bits, eight error flags (bad destination, bad prexsel, receive error, bad
  message, squash, sequence-number status, check-bit status and send error) and four active virtual-channel bits. The
  header says it is not cleared on reset. That is inferred from the comment.
- Port error clear has the same layout as port errors. Its comment repeats the port-errors comment, including the
  statement that reads are non-destructive. That conflicts with the register's name, so whether a read clears the
  latched errors, and so whether it drops the interrupt, is unknown. The header does not settle it.

## Routing tables

- The local table has 128 entries at a stride of eight bytes, starting at `0x681000`. Each is indexed by the 7-bit local
  destination and holds a four-bit next exit port and one low virtual-channel bit.
- The global table at `0x682000` has one entry with the same fields, indexed by the one-bit meta destination.
- The header names both tables and gives no access direction. The unit records them as read-write, from their use as
  lookup tables. What an exit port value selects on the port is not stated anywhere in the header.

## What is unknown

- Reset values of every register. The headers give none.
- What writes to port errors and to port sideband do. Neither header comment says.
- Whether the reset enable also gates a local reset.
- Whether a read of port error clear clears the latched errors.
- The meaning of port status values 0, 2 and 3, and of status bit 0.
- What an exit port value means on the port, and what the routing tables do on a direct link.
- Link training time, and what the far end's port status shows while it is reset.
- How the shipped IRIX Origin 300 and Origin 350 kernels use these registers: which port-status bits they test, what they write to port reset and reset enable, which latched-error bits (52 to 24, with bit 52 as a link reset from another partition) they test, and what they do with the header and sideband words. An earlier version stated these as established, from a note of another project, and the kernel code was not available to re-read. Route: read the IP35 kernel's Bedrock link-error and link-reset code in full.

A Bedrock network interface specification would settle most of these. Failing that, a read-only trace of a port on
hardware, with its cable and far-end state recorded, would settle the port status and reset questions.
