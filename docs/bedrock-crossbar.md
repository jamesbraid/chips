# Bedrock internal crossbar (XB)

The crossbar is the switch inside the Bedrock node controller that connects its units to one another. It is
an 8-input, 6-output switch. The crossbar at crosstalk widget 0 is the XBridge's, not this one (see
[bridge-family.md](bridge-family.md)).

**Mode: no-spec.** No specification and no shipped crossbar code is held here. The only source is the public
Linux 2.5.40 SN1 crossbar header (`include/asm-ia64/sn/sn1/hubxb.h` and `hubxb_next.h`, read directly). Its
register names, offsets, field layouts and comments are software definitions, so every register fact is
**inferred**. None is established. The register list, fields and grades are generated from
`defs/bedrock_xb.toml` into [gen/docs/bedrock_xb.md](../gen/docs/bedrock_xb.md).

## The block

The block runs from `0x700000` to `0x700190`, 36 registers, each 64 bits wide (the header's type). Of these:

- 4 control registers: parameters (`0x700000`), slow grant (`0x700008`), spew control (`0x700010`) and I/O
  queue arbitration trigger (`0x700018`).
- 14 queue error records from `0x700020` (output and input queues of PI0, PI1, the memory-to-PI queues, the
  memory input queue, the NI and I/O and LB queues), with one error-clear register per record at `+0x100`.
- The first-error register (`0x700090`), its clear (`0x700190`), and two debug selects (`0x700098`, `0x7000a0`).

The census dump table (see [chips/bedrock/README.md](../chips/bedrock/README.md)) covers this block as one row,
`0x700000` to `0x7000a0`, with 21 names. The clear registers and the first-error clear sit outside that row.

The header gives no access direction for most registers. The defs unit records the control and error registers as
read-write and the clears as write-only, both assumptions from the header's wording. The first-error register is
read-only because the header says it is not writable.

## Queue error records

The header gives field layouts for the records of PI0 output and input, the memory-to-PI0 output, the memory input,
the NI output, LB output and LB input queues. The other seven records have no fields in the header.

Notes the header attaches to particular records (inferred, from its comments):

- The PI0 input record has no underflow field: the processor interface precludes it.
- The memory-to-PI0 record has no invalid-select field: the crossbar select is decoded on the memory side.
- The LB input record covers request-channel errors only. The reply channel has no flow control, so it cannot
  overflow or deadlock.
- Errors after the first on the memory input queue are logged in the memory unit's input error registers.
- The PI0 output record can be written by software to test error handling, and the write raises an interrupt.

## First error

The first-error register latches the first crossbar error. Its valid bit is set when an error occurs while the
valid bit is clear. The header says a set valid bit interrupts both processor interfaces (PI0 and PI1). That
interrupt persists until the error record that captured the error is cleared, and then the first-error register
is cleared, in that order. The register is not writable, but it is set whenever software writes any error record.

The source field names the record that captured the error. The header gives 14 source codes, from `0xf` for the
PI0 output record down to `0x2` for the LB input record. Values `0x0` and `0x1` are not assigned. The type and
channel fields have no encodings in the header.

Both processor interfaces take the interrupt. The 2.5.40 tree has no consumer code for the crossbar, so the routing
is the header's statement only.

## Control registers

- **Parameters.** Bit 0 enables bypass grants. Bits 11:4, 31:12 and 51:32 hold the age, deadlock and tail wrap
  periods. The header does not give their units or how the crossbar uses them.
- **Slow grant.** Eight 4-bit periods, one per unit, in the order LB, II, NI, MMQ, MP1, MP0, PI1, PI0 from the low
  bits up. The all-ones value gives no grants and one less than all ones the slowest rate. It applies backpressure
  only and does not change bypass grants.
- **Spew control.** Eleven selectors, one per traffic point, from the LB input record up to the PI0 output record.
  The header says at most one should be set. A set selector takes PI1 away from everything but a debug connection.
- **I/O queue arbitration trigger.** The number of clocks the I/O output queue waits before crossbar arbitration
  starts, so the slower I/O data rate can catch up in its buffer.
- **Debug data select.** Bits 13:0 each select one of 14 queue observation points. Bit 14 selects source-field
  observation and bit 15 selects low-data observation. More than one selected point makes the debug output
  undefined.
- **Debug arbitration select.** Three bits select the debug mux for the queues and arbiter. The header does not give
  the output of each value.

## Clearing

Each error-clear register "clears" its base record, and the first-error clear clears the first-error register. The
header gives no write rule. It does not say whether any write clears the record, or whether only set bits do
(write-one-to-clear). **Unknown.**

The clear registers take the same field layout as the records they clear.

The 2.5.40 tree has no code that writes these registers. A later Linux tree may have a probe that writes zero to
each clear register, which would work under either rule. That tree is not checked here.

To settle it: a published crossbar specification, or a hardware read of a record before and after a write to its
clear register with an error latched.

## Reset values

The header defines two constants for the parameters register, named as the reset defaults and the active defaults.
They are what software writes, so they are inferred as software values. They are not measured reset values. The
reset default decodes to bypass on, age period 2, and deadlock and tail periods with only the top bit of their 20-bit
fields set. The active default sets all 20 bits of the deadlock period. Whether firmware writes the active value is
**unknown**.

Every other register's reset value is **unknown**. A value read after firmware initialisation is not a reset value.

## What no source here states

Arbitration, the effect of the age, deadlock and tail periods, bypass grants, backpressure in operation, deadlock and
tail timeouts, errors raised by traffic, and the output of the debug selects are all **unknown**. This repository
holds no specification, capture or consumer code that describes them. Settling them needs a published crossbar
specification or a hardware capture. Register tests alone cannot settle them.
