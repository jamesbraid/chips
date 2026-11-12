# O2 CPU cache and CRIME processor-interface visibility

This page covers the R10000 processor's primary and secondary caches as the O2 uses them, and what the
CRIME 1.5 processor interface tells us about I/O visibility of cached data. The CRIME register map is in the
[CRIME transcription](sources/specs/crime-1.5-specification-rev0.3.registers.md). None of the cache facts below
is a memory-mapped register, so there is no `defs/` unit for them.

Sources:

- MIPS, *R10000 Microprocessor User's Manual*, version 2.0 (October 10, 1996). Cited by printed page.
- SGI, *CRIME 1.5 Specification*, revision 0.3 (2 June 1997). Cited by printed page, with the PDF page in brackets.

Each fact carries its grade. Facts from the R10000 manual apply to the R10000 family unless a page says otherwise.

The CRIME 1.5 revision 0.3 specification has not been checked against every O2 board or CRIME revision. The
cache facts describe the processor, not a board.

## Primary caches

- **Established** (R10000 manual pp. 46, 48–49, 188, 194): each primary cache is 32 KiB and two-way. The
  instruction cache has 64-byte lines and the data cache has 32-byte lines. Both are indexed with virtual
  addresses and tagged with physical addresses. The data index is VA[13:5] and the instruction index is
  VA[13:6]. An Index operation selects the way with VA[0].
- **Established** (pp. 188, 194): Primary Index Load Tag returns physical tag bits 39:12 through the TagHi and
  TagLo registers.

## Secondary cache

- **Established** (pp. 51, 188): the R10000 needs an external two-way secondary cache with a physical index and
  tag. Its block is 64 or 128 bytes, chosen at reset.
- **Established** as the CRIME 1.5 specification's own assumption (printed p. 5-9 [PDF p. 97]): CRIME 1.5 assumes
  a 128-byte block, which is 32 words. It is not a measured block size.
- **Unknown**: the reset strap that selects the secondary block size on the O2's R10000 secondary module, and
  so the block size the O2 uses. Route: the module's schematic, or a read of the strap on a running machine
  under a stated plan.

## Cached and uncached access

- **Established** (pp. 53–54): a mapped address takes its cache algorithm from the TLB EntryLo field. kseg0
  takes it from the Config K0 field. xkphys takes it from VA[61:59]. Algorithm 2 bypasses both caches.
  Algorithm 3 is cacheable and noncoherent.
- **Established** (p. 56): a cached access does not probe the uncached buffer.
- **Established** (pp. 188, 287): a CACHE operation on an address whose algorithm is 2 has undefined behaviour.

## Writeback path

- **Established** (pp. 48, 51, 189): a cached store can leave the newest data in the primary or secondary cache
  while RAM still holds an older value. A primary data writeback goes to the secondary cache first. A secondary
  writeback goes to the system interface.
- **Established** (p. 190): CACHE operations finish the earlier loads, stores and writebacks before they run.

## CACHE operations

- **Established** (pp. 191, 198–200): Secondary Hit WriteBack Invalidate (`0x17`) sends a dirty matching block
  to the system interface and invalidates the matching primary subsets.
- **Established** (pp. 191, 198–200): Secondary Hit Invalidate (`0x13`) drops a matching block and its primary
  subsets without writing anything back.
- **Established** (pp. 191, 198–200): primary-data Hit WriteBack Invalidate (`0x15`) writes dirty data to the
  secondary cache. RAM can still hold the old value after this operation.
- **Established** (pp. 189, 200): a hit operation with no matching line does nothing.
- **Established** (pp. 192–193, 198–200): primary-data Index WriteBack Invalidate (`0x01`) writes the selected
  line to the secondary cache if it is inconsistent, then invalidates it.
- **Established** (pp. 192–193, 198–200): secondary Index WriteBack Invalidate (`0x03`) writes the primary
  subsets that are dirty and inconsistent into the selected secondary block. The operand selects a set and a
  way. The tag stored in the cache identifies the line. The block goes to the system interface when its state
  needs a writeback. The manual lists the secondary tag invalidation before that writeback.

## Maintenance through mapped addresses

- **Established** (pp. 188–190, 200): a Hit CACHE operation translates its operand address and compares the
  physical result with the cache tags. A valid TLB-mapped operand with algorithm 3 can therefore select
  Secondary Hit WriteBack Invalidate (`0x17`).
- **Established** (pp. 188–190, 200): mapped addressing alone does not raise Address Error. CP0 must be usable.
  A missing or invalid TLB entry can raise TLB Refill or TLB Invalid. A privilege violation can raise Address
  Error. A CACHE operation does not raise TLB Modified.

## Aliases

- **Unknown**: the result of a cached and an uncached access to one physical address at the same time, and of
  two cached virtual addresses with different primary indexes that name one physical line. Route: the
  manual's virtual-coherency and alias rules, which this page did not read, then a measurement on hardware.
- **Unknown**: whether invalidating a data cache entry leaves the instruction cache entry for the same line
  valid. The secondary invalidate operations also invalidate primary subsets, so they cannot settle it. Route:
  a primary-only operation, or a measurement on hardware.

## CRIME processor interface and I/O visibility

- **Established** (CRIME printed pp. 5-3, 5-5 [PDF pp. 91, 93]): CRIME 1.5 does not support coherent I/O. Its
  processor interface accepts noncoherent reads and block writes.
- **Inferred**: because the interface is noncoherent, a device reading memory through CRIME sees the backing
  RAM and not the contents of the CPU's caches. A dirty line stays invisible to such a device until a writeback
  moves it to RAM. The inference rests on the first point above, not on a measured O2 transfer.
- **Unknown**: whether the MACE PCI-side DMA path has any snooping, buffering or ordering that changes this
  view. Route: a MACE DMA description that gives its buffering and translation rules, and a measured transfer.

## Not covered here

Replacement policy, cache contents at reset, the timing of replacement, partial stores, `PREF`, unmapped faults
and the exact result of mixed alias accesses are not described here. The open items are listed in
[open-questions.md](open-questions.md).
