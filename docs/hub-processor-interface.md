# Hub processor interface

The processor interface (PI) is the Hub block that faces the node's two processors. Its offsets sit
below `0x200000` in the Hub register space, and the second processor's set repeats the first at the
pairing offsets the header gives. The census in [chips/hub/README.md](../chips/hub/README.md) reaches
the interrupt, real-time counter, error and timer registers. The register list with grades is in
[gen/docs/hub_pi_extra.md](../gen/docs/hub_pi_extra.md) and [gen/docs/hub.md](../gen/docs/hub.md).
This page covers what the public Linux SN0 processor-interface header adds, and what stays open.

## Sources

- The public Linux SN0 Hub processor-interface header at tag v4.0 (`arch/mips/include/asm/sn/sn0/hubpi.h`).
  It gives names, offsets, masks and shifts. It gives no access types and no reset values.
- The public OpenBSD IP27 kernel file `sys/arch/sgi/sgi/ip27_machdep.c` at commit
  `2df91d80c104636deeef8124252ddd5951b55fbf`, for the counter rate. This is a software expectation.

## Added from the public header

Registers the census does not reach are in [defs/hub_pi_extra.toml](../defs/hub_pi_extra.toml), graded
inferred as a whole because the header gives no access type. Their access is an assumption, stated in
each entry.

- **Protection.** The CPU protection register at offset 0, the protection override at 8 and the
  interrupt-pending protection register at 16. The header names the override and gives no unlock value.
- **Reply level** at `0x60`, **non-maskable interrupt to processor B** at `0x78`, and **soft reset**
  at `0x80`. The header's comment says the soft reset goes to both processors.
- **Cross-call pending** set, clear and mask registers at `0xc8` to `0xe8`. Processor B sits eight
  bytes above processor A in each pair.
- **Clock filter control** at `0x168`, next to the real-time clock control register. The header gives no fields.
- **Built-in self-test** registers at `0x200` to `0x230`. The header names them and says nothing of their use.
- **Graphics page, credit, bias and interrupt counter** for each processor, at `0x300` to `0x340`. Each
  processor's set is `0x28` above the other's. The interrupt compare at `0x320` and `0x348` is already in
  defs/hub.toml. The header names the counters and gives no field layout beyond the page enable.
- **Clear-on-read aliases** of error status 0 at `0x438` and `0x458`. The header's comment says a read clears
  the register. The kernel's use of the status 1 alias is recorded in chips/hub/README.md and is not reconciled here.
- **Spool compare, CRB timeout, forced check bits and negative-acknowledge** registers at `0x470` to `0x4b8`.

The layouts the header gives for registers the census names are these:

- **Interrupt cause bits.** The five Hub-driven processor lines report on Cause bits 10 to 14, named
  in the header as the pending bank, the second bank with cross-call, the real-time comparator, the
  profiling comparator and Hub errors. The profiling comparator is bit 13, which is IP5. That matches
  the header's comment calling the profiling line level 5. The mask of all five is `0x7c00`.
- **Real-time clock control** at `0x160`. Use-internal is bit 16. The global clock flag is bit 15 and
  the global clock count is bits 14:8. The maximum count is bits 7:1, and the global clock enable is bit 0.
  The header does not say what the maximum count sets. See the rate section.
- **Cached-alias size.** The register at `0x28` holds a code from 0 to 15. The codes are 0 for no alias,
  then 4 KB at code 1, doubling at each step to 64 MB at code 15. The header gives each name.
- **Processor bus checks** at `0x490`. Six enable bits: error-correction generation (bit 0), data-quality
  generation (bit 1), SysAD parity (bit 2), SysCmd parity (bit 3), SysState parity (bit 4) and data-quality
  checking (bit 5).
- **Negative-acknowledge counters** at `0x4a8` and `0x4b0`. Enable is bit 20, and the count is bits 19:0.
  The compare at `0x4b8` is twenty bits wide.
- **Graphics page enable** is bit 40 of each page register. The header does not give the page address
  bits or the width of the credit fields.

## The real-time counter rate

The counter rate is **inferred** at 1,250,000 Hz. The OpenBSD IP27 kernel registers the Hub
real-time counter as a timecounter at that frequency, truncated to 32 bits. It uses one value for every
board, and it reads the counter only as a reference. That is a software expectation, not a hardware
measurement.

The census gives a consistent but not independent check. The IP27 kernel stores the counter plus 1250 as the
profiling compare (chips/hub/README.md). At 1.25 MHz that is one millisecond.

What is **unknown** is whether the counter's rate comes from the clock control register on this chip. The
Bedrock layout, a later chip, describes that relation, and a sibling chip is a hypothesis only. On the
Hub, no specification is held. Nothing here fills a field from that layout.

## Graphics credit block

The header names ten registers for the graphics page, credit, bias and interrupt counter, and it names
the page enable bit. It does not say what the credit counter counts, how the bias compares, or when
the interrupt fires. Those statements come from the later chip's header and from the shipped graphics
driver, and neither is read in this import. They are not imported as Hub facts.

To settle them, read the shipped graphics flow code in an installed IRIX image and check the credit
behaviour on a live pipe.

## Interrupt delivery

The census in chips/hub/README.md has the bank-to-level table, the levels the kernel connects and the
dispatcher. This import adds only the Cause bit positions above. How a line behaves when its pending bits
change is not given by the header and is not stated here.

## Not imported

- **Reset values and access types from a machine-readable IRIX register table.** That table is not a source
  this repository accepts. Reset values stay unknown, as they are in defs/hub.toml.
- **The protection override unlock value.** The public header does not give one. It stays unknown here.
- **Stock PROM and IRIX kernel behaviour** drawn from binary analysis done outside this checkout: the
  processor rendezvous, the deliberate bus-error probe, the status-record check and the graphics credit
  sequences. The binaries are not in this checkout, so none of those readings is re-derived here. They
  are leads for the next pass over the shipped images.

## Open

- **Reset values** of every processor interface register: unknown. A read of each register on a live
  Hub before firmware writes it would settle them, or a Hub specification.
- **Whether the maximum count sets the counter rate.** Observe the firmware's write to the clock control
  register on two machine configurations whose Hub clocks differ. The firmware should write a different
  maximum count on each, if the rate follows the clock.
- **Graphics credit semantics** and the page address field: see the graphics section.
- **Sense of the interrupt-modify write.** Bit 8 of the value written to offset `0x90` is the set or clear
  choice in the shipped firmware's posting code. The census in chips/hub/README.md says the sense is not
  read. Reading that store in the firmware image would settle it.
- **Access types** of every register in [defs/hub_pi_extra.toml](../defs/hub_pi_extra.toml): assumed in
  each entry, unknown until a live read or a specification.
