# Bedrock local block (LB)

The local block is the Bedrock unit that holds the node's identity and control registers. It also holds the access
vectors that govern processor and I/O access to the local registers of the network, crossbar and memory-directory
units, drives the real-time clock signal that both processor interfaces count, records the block's own errors, and
carries vector I/O requests across the fabric. Its register layouts, with a grade on each field, are in [devices/bedrock_lb/registers.toml](registers.toml);
the generated reference is [devices/bedrock_lb/registers.md](registers.md). The neighbouring units are the
[I/O interface](../bedrock_ii/README.md) and the [internal crossbar](../bedrock_xb/README.md).

No Bedrock specification is held. Every field position and the reset statements come from the public Linux 2.5.40
SN1 local-block register header and its companion masks, and the chip-identity header of the same tree. The Linux
ia64 L1 driver supplies the one software use described below. The configuration default for the real-time counter
comes from the SN1 configuration header. None of these is a hardware read, so the grades in the defs file are about
what the sources state, not about silicon.

Reset fetch, the compatibility segment (ckseg1) and the Bedrock node number, as the PROMs and IRIX use them: [platforms/decode-reset-and-kseg1.md](../../platforms/decode-reset-and-kseg1.md).

## Identity and node number

- The revision register holds the chip identity, this node's number and the region size. Its fields are the
  manufacturer (11:1), part (27:12), revision (31:28), node (39:32) and region size (47:46). The header says
  the register sets the node's ID.
- The part field for the hub chip is `0x3012`. The revision field is 1 for Bedrock 1.0 and 2 for Bedrock 1.1.
- Region size is 0 for one node per region, 1 for two nodes per region, 2 for four (N mode), and 3 is marked
  invalid by the header.
- The header says IBM assigns the manufacturer, part and revision values under IEEE 1149.1. It does not say whether
  those fields accept writes, and it gives no reset value for the register. The widget identification register in the
  I/O interface echoes the manufacturer and revision fields.

## Access permissions and soft reset

- The CPU and I/O permission vectors hold one bit per region. For the local block, network, crossbar and
  memory-directory registers, a region with its bit clear gets no write, and no read that changes state. Such an
  access is not performed and the request gets an error reply. The I/O vector governs accesses that come from the
  I/O interface rather than from a processor.
- Writing the 64-bit ASCII key that the SN1 header names to the override register sets the writer's own region bit in
  the CPU permission vector. The key is not reproduced in this repository.
- A write of bit 0 of the soft-reset register resets the Bedrock. The header does not say which state survives that
  reset.
- Region present lists the regions that may receive an invalidate. When an invalidate names a processor interface in a
  region whose bit is clear, the block acknowledges it on that interface's behalf.
- Nodes absent holds four 16-bit entries. Each entry has a node number in its low eight bits and a valid bit at
  bit 15 of the entry. A listed node cannot receive an invalidate.

## Errors

- The error bits are: request and reply bad command, short, long and bad data (bits 0 to 7 in pairs, request before
  reply), request bad address (8), request bad invalidate (9), and global clock drop (10).
- Reads of the error bits are non-destructive. A write sets the bits it names. The header says the bits survive reset.
  The power-on value is not stated.
- The error mask clear register clears the bits written as one. Zero bits leave their error bits alone, so any subset
  clears in one atomic write.
- Header 1 holds the command, supplemental and source fields, the error type (32 to 35), overrun (40) and valid (44).
  The first error captures the packet header with valid clear and sets valid. A later error while valid is set sets
  overrun and changes nothing else. The error type uses the same numbering as the error bits, so type 5 is a reply
  with a long packet. A global clock drop does not update header 1.
- Header 2 holds the address field (37:0) of the first erroring packet. The data register holds the data flit of that
  packet for the error kinds that carry data.
- Any set error bit raises the block's error request to both processor interfaces. In the interfaces' pending-1
  register it is bit 55. The header gives this as the local block's pending bit.

## Real-time clock

- The local block gives the real-time clock to both processor interfaces. With the use-internal bit set, it
  generates the clock from the Bedrock's system clock, and the period comes from the maximum-count field (13:4).
  With the bit clear, it filters an incoming global clock.
- The filter control register chooses simple filtering, which drops single-cycle glitches, or complex filtering
  (mask-enable at bit 20), which expects regular positive edges, tracks missing and unexpected ones, and generates an
  edge when one is missing. The header gives the high time after each positive edge for either option as
  (2 times maximum count, plus 1, minus the offset) divided by 2, in cycles of the system clock. Clock loss sets error
  bit 10.
- The SN1 configuration header gives the counter a default frequency of 1,250 kHz. That is a software default for the
  kernel, not a measurement, and the block's registers do not state the frequency that results.
- Neither real-time clock register has a power-on value in the header, so both reset values are unknown.

## Scratch registers and locks

- Scratch 0 is reset to zero (the header says so). Scratch 1 and 2 are not reset, and the header does not name the
  reset it means. Scratch 3 and 4 are one-bit registers with no reset value stated.
- Each scratch register has a write-if-zero alias: a write is accepted only while the current value is zero. Scratch 0
  to 2 have these aliases.
- Scratch 3 and 4 have read-set-if-zero aliases. A read returns the old value and sets the bit when it was zero, so one
  read is a test-and-set.
- The public Linux 2.5.40 ia64 L1 driver (arch/ia64/sn/io/l1.c, lines 214-215) takes its hub-wide lock with the scratch 3 read-set-if-zero alias and releases it by
  writing zero to scratch 3. In the public Linux ia64 and SN1 header trees, no other reader of the scratch registers
  was found.

## Vector I/O

The vector engine sends a read or write request along a route to another device, and the reply comes back to the block.
The header describes the sequence: software waits for the busy bit in the parameter register to clear, initialises the
route and the data, and writes the parameter register last. The block answers the parameter write at once, before the
operation finishes.

- Parameter register: type (1:0, one bit in the header's union and a two-bit mask in its companion), address (23:3),
  write id (39:32), request id (50:40) and busy (63). The header's type values are 0 read, 1 write, 2 undefined and
  3 exchange. It says the IP35 does not support exchange, because scratch registers do locks directly.
- Route, data, return route and read data are 64-bit registers. The header gives no field layout for the route.
- Status: type or error (2:0), address, write id, request id, source (61:51), overrun (62) and valid (63). Bit 2 set
  means error, and the codes are 4 address, 5 command, 6 protection and 7 unknown.
- The header says software clears the status before it launches a request. An error reply leaves the fields alone. A
  reply that arrives while valid is already set sets overrun and leaves the rest alone. Otherwise the block loads the
  reply's fields, sets valid, and updates the return route and read data.
- Status clear has the same field layout. The header says it clears the status but does not say whether a read or a
  write does the clearing.

## MicroLAN control

The register at the MicroLAN offset drives a one-wire serial bus to the node board's add-only serial part. The header
names the part as a Dallas 1990A and says it holds the node board's serial number and configuration. Data moves least
significant bit first.

- Fields: read data (bit 0), done (bit 1), sample offset (9:2), low-pulse duration (19:10), and the phase-0 and phase-1
  dividers (26:20 and 33:27). Bit 33 means a 32-bit access cannot write the whole register.
- The header gives no time unit for the timing fields and no completion latency. The bus transaction is not
  described, so the timing, the command set and the identity content are unknown.
- The public Linux SN1 tree does not use this register outside its header.

## Open questions and the test that settles each

| Question | What would settle it |
|---|---|
| Power-on values of the revision, error, permission, real-time clock and vector registers | A read of each after PROM hand-off on an Origin 300, or a Bedrock specification |
| Which reset clears the scratch 1 and 2 values | A Bedrock specification, or a scratch read after each reset kind on hardware |
| Whether a write of a nonzero value to vector status does anything, and whether a read or a write clears vector status clear | A Bedrock specification, or a hardware read of the status after each access kind |
| Route encoding and return-route contents for vector I/O | A Bedrock specification, or a cabled pair of Bedrock nodes read on hardware |
| MicroLAN timing, command set and identity content | A bus trace of the serial part, or the identity part's data sheet; neither is held |
| Real-time counter frequency actually produced | A timed read of the counter on an Origin 300 |
| Meaning of the debug select values | A Bedrock specification |
| Whether identity fields accept writes | A Bedrock specification, or a read-back after a write on hardware |
