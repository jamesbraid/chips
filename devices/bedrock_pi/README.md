# Bedrock processor interface (PI)

The processor interface is the Bedrock unit a processor touches first and most. The Bedrock has two of them, PI0 and PI1,
each facing two processor slots, A and B. Each one holds the interrupt pending banks and per-processor masks, the
real-time counter and its compares, the region and cached-alias controls, the protection registers, the graphics credit
registers and the error capture for its two processors. The census of the shipped kernels names both interfaces and both
slots by the strings the PROM and kernel print (see [devices/bedrock/README.md](../bedrock/README.md)).

Register layouts, with a grade on each field, are in [devices/bedrock_pi/registers.toml](registers.toml). The generated
reference is [devices/bedrock_pi/registers.md](registers.md). Offsets in this page and in the reference are inside one
interface; PI1 repeats the same layout 2 MiB higher in the node window. The neighbouring units are the
[local block](../bedrock_lb/README.md), which drives the real-time clock both interfaces count, and the
[I/O interface](../bedrock_ii/README.md), which routes graphics credits back to a processor.

No Bedrock specification is held, and no read of the interface on hardware is recorded. The sources are the public Linux
2.5.40 SN1 processor-interface register header, read from the history tree at tag `v2.5.40`, and that header's own
comments. The header gives names, offsets, widths and field positions, and it gives behaviour only in comments. It states
no reset value for any register. So every field position is graded established from the header, every behaviour a comment
describes is graded inferred, and every reset is unknown.

Reset fetch, the compatibility segment (ckseg1) and the Bedrock node number, as the PROMs and IRIX use them: [platforms/decode-reset-and-kseg1.md](../../platforms/decode-reset-and-kseg1.md).

## Access and reset

- Every register is 64 bits wide.
- The header says these registers are not reset by a soft reset: the CPU and I/O protection registers, region present,
  cached-alias size, the two CPU enables, and the error stack address and size. The error status records and the spurious
  message records are described as not cleared at reset. The header gives no value for any of them at power-on.
- Access is stated for some registers, such as "read/write" in the protection and enable comments, and is not stated for
  many others. Where the header is silent, the register is recorded as read and write and its description says so.
  Registers the header describes as read only are recorded read only.

## Processor identity and presence

- A read of the CPU number register gives the reading processor's slot in bit 0 and its interface in bit 1.
- The CPU present registers are set by the interface on the first transaction from each processor. The header gives no
  write behaviour for them.
- A clear CPU enable bit makes the interface ignore that processor's bus request, so it never gets the bus. The header
  says this and nothing else about the enable.
- The NMI registers raise a non-maskable interrupt to their processor when written. The header gives no predicate on the
  written value and no latch behaviour, so what a given stored value does is unknown.

## Protection and regions

- The CPU protection register has one bit per region. A denied access to a local register gets an error reply to a
  partial read or write, named PRERR and PWERR in the header.
- The I/O protection register has one bit per region. It decides whether I/O-initiated interrupt writes may set pending
  bits. Only the pending-modify register is reachable that way.
- The protection override register takes a write with a special data pattern that sets the writing processor's region
  bit in the CPU protection register. The header does not give the pattern.
- Region present has one bit per region. A clear bit blocks speculative coherent reads to that region. A coherent read to
  an absent region gets an error reply, and no error register changes. Partial accesses are not checked, and cached-alias
  accesses are not affected.
- The cached-alias size is a four-bit code. The header says every cached-alias space in a system must use the same size,
  and it does not say what each code means.

## Interrupt banks and masks

Each interface has two pending banks. Bank 0 maps to interrupt level 2 and bank 1 to level 3, unless the remap
register moves bits 31 to 0 of bank 1 to level 2. Each processor has its own pair of masks. The masks for bank 0 pass a
pending bit to a level 2 interrupt (bit 10 of the processor's Cause register), and the masks for bank 1 pass bits 63 to
32 to a level 3 interrupt (bit 11 of Cause). The header's comment on bank 1 says bits 31 to 0 go to level 3 or level 2
depending on the low four bits of the remap register. Their encoding is not given.

- Pending-modify sets one bit (bit 8 set) or clears it (bit 8 clear). Bit 6 chooses the bank and bits 5 to 0 the bit.
  It is the only pending register an I/O write may reach, and I/O protection checks it. The alias at the second address
  has the same layout and checks, and the header does not say why there are two.
- Bank 0 bit 1 and bit 2 are the graphics interrupts for CPU A and CPU B. Hardware sets them and software clears them.
- Bank 0 bit 3 is the page migration bit. The header says only one processor per Bedrock should enable it.
- Bank 0 bits 5 and 6 come from the CPU-to-CPU pending registers.
- Bank 1 bit 58 is named performance counter overflow in the register layout. The header's comment on the same bank
  calls it the real-time clock drop-out bit. The two names are both in the header; which one describes the hardware is
  unknown.
- Bank 1 bits 56 and 57 are the CPU A and CPU B NACK interrupts. Bit 59 is correctable system error for CPU B and bit 60
  for CPU A. Bit 61 is memory correctable, bit 62 network error, and bit 63 system shutdown. Bits 54 and 55 are crossbar
  and local-block errors. The header says bits 54, 55, 62 and 63 only reflect other logic.
- The remap register's bit 4 forwards the memory and unit errors (correctable, uncorrectable and page migration, and the
  network, local-block and crossbar errors) to the I/O interface. The I/O interface then interrupts the node named in its
  destination register. The header's comment gives this purpose.
- The CPU-to-CPU pending registers have one bit per region. A store by a processor sets the bit for its own region. A read
  returns the bits, and a write clears each bit whose data bit is one. A mask register covers both.

## Real-time clock and profiling

- The real-time counter is 55 bits, wraps to zero, and counts each rising edge of the global clock. It sits in its own
  64 KB page so user space can map it. The clock rate comes from the local block, see its page.
- Each processor has a real-time compare. When the counter equals it, the processor's real-time pending bit is set. The
  header's comment on the compare register says this sends a level 4 interrupt.
- The header's comment on the real-time pending register says the interrupt is at level 5. That conflicts with the
  compare register's comment. Both are in the header, and the register layout does not settle it.
- A real-time pending bit reaches the processor only while its enable bit is set. Any store to the pending register clears
  the bit.
- The profiling compare is 32 bits. When the low 32 bits of the counter match it, both profiling pending registers are set.
  Each processor has its own profiling pending and enable bits, so each can be cleared alone.

## Graphics credits

Each processor has a graphics page, a credit counter, a bias, an interrupt counter and an interrupt compare. A separate
credit mode register switches the counter from counting doublewords to counting transactions. The header gives these
comments, which describe behaviour and so are graded inferred:

- Uncached I/O stores into the enabled page are graphics write commands tracked by the credit counter, not ordinary
  writes. The counter drops by one per doubleword sent and rises by one per doubleword acknowledged.
- When the credit counter is below the bias, write-ready is withheld, an interrupt is sent, and write-ready is allowed
  again. The header's bias comment says the flow-control interrupt is sent when the counter is at or below the bias. The
  two comments do not agree on the edge.
- The interrupt counter is written by software, loaded from the compare on an interrupt, NMI or soft reset, and zeroed
  when the credit counter rises above the bias. It counts one per clock while the credit counter is at or below zero.
  The clock rate is not given.
- The header does not say which pending bit carries the flow-control interrupt, or how long write-ready stays withheld.

## Error capture

- Each processor has an error pending register. Its bits are twelve CPU A and CPU B pairs in bits 0 to 23, with the CPU B
  bit at the even position, then bit 24 for memory uncorrectable, then five more pairs in bits 25 to 34 with the CPU A bit
  at the even position. Errors are raised as the header names them, for example spool complete, spurious message,
  write-buffer error, system-state parity, system data and address ECC, command parity, uncached uncorrectable, bad data
  and request-buffer timeout.
- The write-with-clear register clears each bit whose data bit is one. The writable view takes a direct write to every
  unreserved bit except memory uncorrectable.
- Each processor has a mask over the error bits, and a set bit lets that error raise the level 6 interrupt to the
  processor. The header says only one processor per Bedrock should enable memory uncorrectable.
- Each processor has an error status 0 and an error status 1 record, saved only when the valid bit is set. Status 0 holds
  the error type, the request number, the supplemental field, the command, the address, an overrun flag and the valid
  bit. Status 1 holds the spool, timeout and invalidate counts, the coherency request buffer number, a write flag, two
  encoded bits, seven named flags, and an 11-bit source. Each record has a write-clear alias. Any write to the alias clears
  both of that processor's records.
- The error stack address is the next write to the error stack, and it increments after each write within the size the
  stack-size register selects. The header describes the size as a count of 64-bit entries. It gives no encoding.
- Each processor has a NACK count with an enable bit, and the two share one compare value. A negative acknowledgement that
  arrives when the count equals the compare gets an error reply instead of a NACK, the count clears, and the processor's
  NACK pending bit is set. The spool compare registers are named in the header and nothing more is said of them.
- The spurious message capture holds the header of an incoming message that matches no coherency request buffer entry
  when its valid bit is clear.

## Diagnostic registers

- The system bus error check enable has six bits: ECC generation, data-quality generation, address and data parity,
  command parity, state checking and data-quality checking. The header gives no reset value.
- The bad check bit registers invert the check bits sent with uncorrectable reply data in each set position.
- The error injection register arms one error kind per bit for the next outbound transfer of that kind. The bit clears
  when the error is injected. A bit stays set until a matching transfer occurs, so software can poll it.
- The reply level register stops the processors from issuing requests while the reply FIFO holds more entries than the
  value. The FIFO holds 63 entries.
- The debug select register chooses the debug signals the interface drives. The header names thirteen low and thirteen
  high selector bits, with the names in the register's description.

## Performance counters

Each processor has a control register and two counters. The control register holds an event selector, a mode and an enable
for each counter. The counters are 40 bits wide. On overflow a counter wraps to zero, sets its own overflow bit and sets
the performance overflow bit in bank 1. The header does not list the events or the mode encodings.

## What is unknown

- Reset values of every register. The header gives none.
- The access mode of the registers the header does not describe. They are recorded read and write.
- The encoding of the remap selector, the error stack size, the error type field, the performance counter mode and the
  performance event selector.
- The pattern that the protection override register takes.
- Whether bank 1 bit 58 is the performance overflow or the real-time drop-out, and whether the real-time compare raises
  level 4 or level 5.
- The pending bit or bits that carry the graphics flow-control interrupt, the length of time write-ready is withheld, and
  the clock the interrupt counter counts.
- What a store of a value other than one to an NMI register does.
- How the shipped kernels use the graphics credit registers, the performance registers and the error stack. This page
  has not read any of them.

A Bedrock specification, or a read of the interface's registers on hardware after PROM hand-off, would settle the reset
values and the access modes. A logic analyser on the processor bus during a stalled graphics store would settle the
flow-control interrupt. None of these is held or requested.
