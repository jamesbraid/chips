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

## Primary instruction cache

- **Established** (R10000 manual p. 46): the instruction cache is a subset of the secondary cache. Each block is 16
  words (64 bytes), and each block is either invalid or valid. The two ways use least-recently-used replacement.
  The manual warns that speculative execution affects the exact LRU choice, so a victim cannot be predicted from a
  few observed refills.
- **Established** (pp. 188, 194–195): an instruction-cache Index or Index Load Tag operation takes its set from
  VA[13:6] and its way from VA[0].
- **Established** (pp. 194–195): Index Load Tag (I) returns TagLo[0] as tag parity, TagLo[2] as state parity,
  TagLo[3] as the LRU bit, TagLo[6] as the valid state, TagLo[31:8] as physical tag bits 35:12 and TagHi[3:0] as
  tag bits 39:36. All other TagLo and TagHi bits read as zero, and it ignores parity errors. Index Store Tag (I)
  writes the same fields back, including both parity bits, and checks no parity.
- **Established** (p. 197): Hit Invalidate (I) reads both ways at VA[13:6] and compares them with the translated
  physical address. It clears the valid state of a matching valid entry only, leaves the LRU bit alone and checks
  parity. With no match it does nothing.
- **Established** (pp. 201–202): Index Load Data (I) reads one instruction word addressed by VA[13:2], with the way
  from VA[0]. The word goes to TagLo[31:0] and TagHi[3:0], and its parity bit goes to ECC[0]. The manual describes
  the stored word as 36 bits of predecoded instruction plus one parity bit. The tag is not read, and parity is not
  checked.
- **Established** (p. 202): Index Store Data (I) writes a word from TagLo[31:0], TagHi[3:0] and ECC[0] straight
  into the instruction cache, bypassing predecode. The tag is unchanged.
- **Unknown** (pp. 201–202): the diagnostic value of a word that came from an ordinary refill. The manual does not
  give the predecode algorithm, and it does not say that the low 32 bits equal the raw instruction. Route: a
  reference that defines predecode, or a read of a word on hardware under a stated plan.
- **Established** (p. 161): power-on reset initializes all internal state. The manual gives no post-reset tag
  image, so none is asserted here.

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

- **Established** (R10000 manual p. 53, Table 4-1): the 3-bit cache algorithm field has one encoding wherever it
  is read: the TLB EntryLo fields, CP0 Config K0 for kseg0 and VA[61:59] for xkphys. Value 2 is uncached, 3 is
  cacheable noncoherent, 4 is cacheable coherent exclusive, 5 is cacheable coherent exclusive on write and 7 is
  uncached accelerated. Values 0, 1 and 6 are reserved.
- **Established** (p. 54): under algorithm 5 a load that misses the secondary cache issues a coherent block read
  shared, so an external agent with a cache may keep a copy in Shared state. A store that hits a Shared block
  issues an upgrade that tells external caches to invalidate. Algorithm 4 issues a block read exclusive on a load
  miss instead.
- **Established** (pp. 239–240): EntryLo0 and EntryLo1 carry the physical frame number (physical bits 33:6), the
  cache algorithm, a valid bit and the uncached attribute in bits 63:62. The global bit G is kept once per TLB
  entry, written from bit 0 of both halves on a TLB write. It makes the lookup ignore the ASID only when it is set
  in both EntryLo0 and EntryLo1. The manual's field table describes bit 2 (D) with the valid-bit text, so this
  page does not use bit 2.
- **Established** (p. 242, Table 14-6): PageMask 0 selects 4 KiB pages and 0x6000 selects 16 KiB pages. The manual
  leaves the TLB undefined for other MASK values outside its table.
- **Established** (p. 56): an uncached load followed by a SYNC instruction guarantees that all cache accesses,
  uncached accesses and uncached accelerated accesses have been globally performed. This is an ordering guarantee.
  It does not say that the load flushes or invalidates any cache line.
- **Inferred** (pp. 54, 56): an uncached access goes to the system interface without probing this processor's own
  primary or secondary caches, because the manual says uncached accesses bypass both caches. The manual does not
  say what happens to a dirty cached copy of the same physical address, so the mixed-access result stays unknown
  (see Aliases).

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
- **Established** (p. 189): an Index operation uses the address only to pick a line, so it need not match a tag,
  and an unmapped address can perform it without a TLB exception. A Hit operation that matches both ways is
  undefined. CACHE operations raise no Watch exception.
- **Unknown** (pp. 188–189): the Address Error rule for low address bits. Page 189 says an Index operation ignores
  bit 0 and that bit 1 can still raise Address Error, and that other operations need zero low bits. The same page
  says CACHE operations are never checked for alignment Address Error. The page does not settle which applies.
  Route: an errata entry, or a measured trap on hardware.

## Aliases

- **Established** (pp. 67, 345): when a secondary cache access finds that the virtual index bits VA[13:12] differ
  from the PIdx field in the secondary tag, the hardware purges the primary lines at the old index and writes the
  new index into PIdx. The R10000 raises no exception for this. It does not implement the Virtual Coherency
  exception.
- **Unknown**: the result of a cached and an uncached access to one physical address at the same time. Route: the
  manual's cacheability rules for mixed access, then a measurement on hardware.
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

## Index operations in detail

Pages marked NEC below are from two NEC manuals, cited by printed page:

- NEC, *VR10000 Series 64-/32-bit Microprocessor User's Manual*, fourth edition, March 2001, U10278EJ4V0UM00 (NEC UM).
- NEC, *VR5000, VR10000 64-bit Microprocessor Instruction User's Manual*, first edition, August 2000, U12754EJ1V0UMJ1 (NEC ISUM). The UM defers the CACHE encodings and per-operation text to this manual.

Every R10000 value here comes from the R10000 column of the ISUM table. The facts describe the R10000 as those manuals do. R12000 behaviour needs separate evidence.

### Encoding (established)

- `CACHE op, offset(base)` has major opcode `101111`, base register in bits 25:21, `op` in bits 20:16 and a signed 16-bit offset. The operand is `GPR[base]` plus the sign-extended offset, translated through the TLB (NEC ISUM pp. 70–72).
- `op[1:0]` selects the cache: `00` primary instruction, `01` primary data, `11` secondary. `10` is undefined on the R10000. `op[4:2]` selects the operation. Unlisted encodings are undefined (NEC ISUM pp. 16–17, 70).
- The R10000 does not implement Create Dirty Exclusive, Hit Writeback, Fill (I), Flash, Page Invalidate or the Hit Set Virtual variants (NEC ISUM p. 16).

| `op` | Primary I | Primary D | Secondary |
| ---: | --- | --- | --- |
| `0x00` | Index Invalidate | | |
| `0x01` | | Index Writeback Invalidate | |
| `0x03` | | | Index Writeback Invalidate |
| `0x04` | Index Load Tag | | |
| `0x05` | | Index Load Tag | |
| `0x07` | | | Index Load Tag |
| `0x08` | Index Store Tag | | |
| `0x09` | | Index Store Tag | |
| `0x0b` | | | Index Store Tag |
| `0x10` | Hit Invalidate | | |
| `0x11` | | Hit Invalidate | |
| `0x13` | | | Hit Invalidate |
| `0x14` | Cache Barrier | | |
| `0x15` | | Hit Writeback Invalidate | |
| `0x17` | | | Hit Writeback Invalidate |
| `0x18` | Index Load Data | | |
| `0x19` | | Index Load Data | |
| `0x1b` | | | Index Load Data |
| `0x1c` | Index Store Data | | |
| `0x1d` | | Index Store Data | |
| `0x1f` | | | Index Store Data |

Table: established (NEC ISUM pp. 16–17, 70).

### Exceptions and ordering (established)

- The CACHE instruction needs usable CP0. Bit 0 of the operand is the way select for index operations, so it is not checked for alignment (NEC ISUM pp. 71–72). The alignment wording for the other low bits is open; see the Unknown under mapped addresses above.
- CACHE instructions execute serially. No later load or store issues speculatively until the CACHE instruction graduates, and earlier memory traffic, including writebacks, must have completed. Instruction fetch is not serialized (NEC ISUM p. 16).
- Uncorrectable-error protection is suppressed during Index Load and Index Store Tag and Data operations (NEC UM p. 189).

### Geometry and index source

- **Established** (NEC UM pp. 61–67): all three caches are two-way set associative and write-back. Each primary cache is indexed by virtual address and tagged by physical address. The primary instruction index is VA[13:6] and the primary data index is VA[13:5]. The way is VA[0].
- **Established** (NEC ISUM pp. 71–72, NEC UM p. 67): the secondary cache is 512 KiB to 16 MiB in powers of two, set by SCSize. Its block is 64 or 128 bytes, set by SCBlkSize. For a cache of 2^N bytes with 2^B-byte blocks, the set is PA[N-2:B] and the way is PA[0]. A 512 KiB cache with 64-byte blocks is indexed by PA[17:6].
- **Unknown** (NEC UM pp. 81, 86, 91, 276): the UM's secondary read and write text gives the index as PA(23:6), which is 18 bits and fits no allowed cache size. The CacheErr format on p. 276 gives SIdx as PA[22:6], which is 17 bits and fits a 16 MiB cache. The way-prediction table index on p. 81 matches the formula only up to 1 MiB. The formula above is the one the ISUM supports. The UM also writes VA(0) and VA(3) where the ISUM writes PA[0] and PA[3]. Translation does not change those bits, because they lie below the page size.

### Mapped operands: which address gives the index

- **Established** (NEC ISUM pp. 70, 72): every CACHE operand, index or hit, is translated like a data address first. Unmapped operands (kseg0, kseg1, xkphys) take their physical address from the virtual address. For a primary index operation the translation still happens and can raise an exception, but the physical address is not used.
- **Established** (NEC ISUM pp. 14–15, 71): the primary index comes from the virtual address. The secondary index comes from the physical address, PA[N-2:B], and for Index Load and Store Data (S) the quadword (PA[B-1:4]) and doubleword (PA[3]) come from it too. The generic sentence on ISUM p. 72, that the virtual address indexes any index operation, does not override these specific statements for the secondary cache. The secondary cache is physically indexed (NEC UM p. 67).
- **Inferred** (from the points above): a mapped secondary index operation reaches the set given by the physical frame, not the virtual page number. Two virtual addresses mapped to one frame reach one secondary line. Two addresses with equal VA[N-2:B] but frames that differ in index bits reach different lines. The primary set depends only on virtual bits, so VA[13:12] can differ from the frame's PA[13:12]. That is why the secondary tag records VA[13:12] as its virtual index.
- **Unknown** (NEC ISUM pp. 15, 72): the BadVAddr, Context and EntryHi values after a CACHE operation raises a TLB exception. Neither manual gives them for CACHE operations.

### Tag and data formats

Tag fields (**established**, NEC UM pp. 279–281, Figures 14-28 to 14-30, pp. 194–196; NEC ISUM pp. 20–25). Index Store Tag writes every listed field from the registers, including the parity, ECC, LRU and MRU bits. Index Load Tag fills these fields and sets every other bit of TagLo and TagHi to zero.

| Cache | TagLo | TagHi |
| --- | --- | --- |
| Primary I | [31:8] PA[35:12], [6] state (1 valid), [3] LRU, [2] state parity, [0] tag parity | [3:0] PA[39:36] |
| Primary D | [31:8] PA[35:12], [7:6] state, [3] LRU, [2] state parity, [1] secondary way, [0] tag parity | [3:0] PA[39:36], [31:29] state modifier |
| Secondary | [31:14] PA[35:18], [11:10] state, [8:7] virtual index, [6:0] tag ECC | [3:0] PA[39:36], [31] MRU |

- **Established** (NEC UM pp. 192, 279–280, Table 14-24): the primary D state modifier in TagHi[31:29] is `001` normal, `010` written and inconsistent with the secondary cache, or `100` refilling. With the refill bit set, the state values mean refill or upgrade states. With the modifier clear, the state is `0` invalid, `1` shared, `2` clean exclusive or `3` dirty exclusive.
- **Established** (NEC UM p. 67, Table 5-4): the secondary state is `0` invalid, `1` shared, `2` clean exclusive or `3` dirty exclusive. A secondary line is valid in every state but 0.
- **Established** (NEC UM pp. 66–67, 195–196): the secondary tag array holds the full 22-bit physical tag PA[39:18], even when the cache is above 512 KiB and some of those bits are redundant. The 26-bit SCTag holds that tag, a 2-bit virtual index PIdx and the 2-bit state. Seven ECC bits accompany it in the CACHE mapping. The virtual index is VA[13:12] of the access that filled the line, written at refill.
- **Established** (NEC UM p. 280, Figure 14-29; NEC ISUM p. 24): the primary D tag's TagLo[1] holds the secondary way that the line's writeback uses. That use is **inferred** from the manual's silence.

Data fields (**established**, NEC ISUM pp. 29–30; NEC UM pp. 273, 282–283, 86, 91):

| Operation | Address selects | Register contents |
| --- | --- | --- |
| Index Load/Store Data (I) | word VA[13:2], way VA[0] | Inst[31:0] in TagLo, Inst[35:32] in TagHi[3:0], parity in ECC[0] |
| Index Load/Store Data (D) | word VA[13:2], way VA[0] | data word in TagLo, byte parity in ECC[3:0] |
| Index Load/Store Data (S) | quadword and way, with the doubleword chosen by PA[3] | doubleword bits 63:32 in TagHi, bits 31:0 in TagLo, check bits in ECC[9:0] |

- Every Index Store Data leaves the tag array and the LRU or MRU bit unchanged. Index Store Data (I) bypasses predecode. Index Load Data suppresses parity and ECC checks. ECC[9] is the quadword's even parity bit and ECC[8:0] are the nine check bits (NEC UM p. 273).
- **Established** (NEC UM p. 91, NEC ISUM p. 30): Index Store Data (S) writes a whole quadword. The doubleword chosen by PA[3] comes from TagHi:TagLo, the other doubleword is written as zero, and ECC[9:0] is stored as given without generating or checking anything. Two Index Store Data (S) operations to the two doublewords of one quadword leave only the second doubleword's data.
- **Established** (NEC UM Figure 14-33, p. 283): TagHi holds doubleword bits 63:32 and TagLo bits 31:0. Which half of a refilled primary line a word load returns is **unknown** (see Not settled).

### Index operations on existing lines

- **Established** (NEC ISUM pp. 18–19, 25, 27): Index Invalidate (I) clears the I state bit and state parity of the selected way and leaves LRU alone. Index Writeback Invalidate (D) invalidates the selected D way, resets its state modifier and secondary-way field, and writes an inconsistent line back to the secondary cache.
- **Established** (NEC ISUM pp. 18–19): Index Writeback Invalidate (S) reads the selected secondary tag. If its state is Invalid, nothing else happens. Otherwise it invalidates the matching primary I and D subset lines, writes back inconsistent D lines first, sets the state to Invalid, writes the tag with the operand's PA and VA[13:12], and generates the ECC. A dirty-exclusive block goes to the system interface. Other valid states send a tag-invalidation notice. The MRU bit points away from the invalidated way.
- **Established** (NEC ISUM pp. 27–28): Hit Invalidate (S) and Hit Writeback Invalidate (S) search both ways. On a hit they do the same subset and state actions, and only Hit Writeback Invalidate writes back. On a hit they set Status.CH, and on a miss they clear it.
- **Established** (NEC ISUM p. 27): Hit Invalidate (I) and Hit Invalidate (D) invalidate a matching line in the named primary cache only.
- **Inferred** (from the silence of NEC ISUM p. 25): Index Store Tag (S) and Index Store Data (S) purge nothing. A primary line stays valid over a valid secondary line that Index Store Tag (S) has changed, so it can hold data the secondary line no longer describes.

### Staging: how operations build a line

- **Established** (NEC ISUM pp. 18–30, 71; NEC UM p. 91): each Index Store Tag writes one way of one set, and each Index Store Data writes one unit.
  - Primary I: one tag operation per way and set, and one Index Store Data (I) per 36-bit word. A 64-byte block takes 1 tag and 16 data operations.
  - Primary D: one tag and one Index Store Data (D) per 32-bit word. A 32-byte block takes 1 tag and 8 data operations.
  - Secondary: one tag and one Index Store Data (S) per quadword. A 64-byte block takes 4 data operations and a 128-byte block takes 8. Each one fills one doubleword, so a 64-byte block has 4 of its 8 doublewords filled, and a 128-byte block has 8 of 16.
- **Inferred**: Index Store Tag writes no data and Index Store Data writes no tag, so a staged line can be built in either order. Data written to an Invalid line is not visible to any access until a tag operation makes the line valid.
- **Inferred**: Index Store Data (I) and (D) are the only index operations that stage a full block of nonzero words. A primary hit then does not read the secondary cache. A staged instruction line holds at most two nonzero 32-bit words per quadword, since Index Store Data (S) zero-fills the other half.
- **Inferred**: Index Store Tag does not enforce the subset rule in either direction.
- **Inferred**: two operands that give the same set and way overwrite each other. Staging N blocks takes N tag operations at distinct set and way pairs. Do not stage one tag in both ways of a set. The manual makes a double hit undefined for hit operations (NEC ISUM p. 15) and does not say what an ordinary access does.

### Inclusion: the secondary cache as parent

- **Established** (NEC ISUM p. 17): invalidating a secondary block invalidates its primary subset blocks.
- **Established** (NEC ISUM pp. 18, 27–28, 72; NEC UM pp. 47, 50): Index Writeback Invalidate (S), Hit Invalidate (S) and Hit Writeback Invalidate (S) invalidate the secondary block and every primary I and D line that is a subset of it. The primary state diagrams show Hit Invalidate and Index Writeback Invalidate (S) taking a valid line to Invalid.
- **Established** (NEC UM p. 67, pp. 47, 50): the hardware also enforces the subset rule on other paths. A virtual-index mismatch on a secondary access purges the primary locations implemented in hardware, and subset enforcement is an internally initiated state transition.
- **Inferred**: a primary line is a subset when its physical block lies inside the secondary block. A 128-byte secondary block holds two I blocks and four D blocks. A 64-byte one holds one I block and two D blocks. A primary line outside the block is untouched. The manual says "each subset block" and gives no address range.
- **Established** (NEC ISUM pp. 18–19): Index Writeback Invalidate (S) uses the stored tag, not the operand's PA, to find the primary lines. A primary I line is invalidated when its tag equals the secondary tag and it is Valid. A primary D line is invalidated when its tag matches and it is not Invalid. An inconsistent dirty D line is written back to the secondary cache first.
- **Established** (NEC ISUM pp. 27–28): a hit operation acts only when the operand's PA matches a valid secondary tag in one of the two ways. On a miss it purges nothing, even if a primary line holds that PA. On a hit it purges the subset primary lines.
- **Established** (NEC ISUM pp. 19, 27–28): the hit operations find the primary lines through PIdx, TagLo[8:7]. The UM pages read do not say this for hit operations. A primary line at an index other than PIdx can therefore survive them.

### Later cached accesses

- **Established** (NEC UM pp. 82, 87–88): a cached access that misses both primary caches looks up both secondary ways. A way with a matching tag and a valid state is a hit, and the data comes from the secondary data array. If the hit way is not the one the MRU bit predicted, the processor reads that way and updates MRU. Only a miss in both ways reads the system interface. The MRU bit and the way chosen at staging therefore change timing, not the hit result.
- **Established** (NEC UM pp. 87–88, 193–196): a primary D miss refills 8 words (32 bytes) from the secondary cache. A primary I miss refills 16 words (64 bytes), one quadword at a time, and each quadword is read through the secondary data check.
- **Inferred** (conditions for a hit at the staged address):
  1. The staged state is valid (1, 2 or 3). State 0 misses.
  2. TagLo[31:14] and TagHi[3:0] equal PA[35:18] and PA[39:36] of the access. For a cache above 512 KiB the redundant tag bits must match as well (NEC UM p. 83).
  3. The access uses a cached algorithm. CACHE on an uncached address is undefined.
  4. No conflicting valid primary copy exists. A primary hit returns primary data and never consults the secondary cache, and Index Store Tag (S) does not purge primary lines.
  5. TagLo[8:7] equals VA[13:12] of the access. Otherwise hardware purges primary lines at the recorded index (NEC UM p. 67, established as a purge). Whether the access then continues is **unknown**.
- **Inferred** (from the separate arrays, NEC UM pp. 61–64): a line in the primary I cache serves fetches only, and a line in the primary D cache serves data accesses only. The manuals do not discuss a load hitting a primary I line.

### Primary instruction-cache refill

- **Established** (NEC UM pp. 47, 62, 88, Figure 4-2): a cached fetch that misses the primary I cache and hits a secondary line refills the 64-byte block from the secondary cache. The refilled line is Valid and is tagged with the fetch's physical address. Index Load Tag (I) reads it as described under Tag and data formats.
- **Inferred**: the block goes into the set given by VA[13:6] of the fetch, which the index operations and the cache geometry imply. The manual does not state this for refills.
- **Unknown** (NEC UM p. 62): the manual gives least-recently-used replacement but does not say whether an Invalid way is preferred, or how the LRU bit updates. Which way a refill takes when one way is Invalid, or when both are valid, is therefore not settled. The tag parity, state parity and LRU bits of a refilled line are not specified by these pages.

### Check bits and error behaviour

- **Established** (NEC UM pp. 91, 194, 196; NEC ISUM pp. 25, 30): an ordinary secondary write generates the ECC and parity. Index Store Data (S) stores ECC[9:0] unchanged, and Index Store Tag (S) stores TagLo[6:0] as the tag ECC unchanged. Neither operation checks anything.
- **Established** (NEC UM pp. 194, 196): with SCCorEn set, every secondary data read passes through the corrector. A correctable error is fixed, and an uncorrectable one posts a Cache Error. With SCCorEn clear, the ECC[9] parity is checked first, and only a parity error sends the read through the corrector. The secondary tag read always checks its ECC. A correctable tag error is fixed in place, and an uncorrectable one posts a Cache Error (NEC UM p. 196).
- **Established** (NEC UM p. 189): Status.DE suppresses posting of uncorrectable errors and their CacheErr update. Cache hits are not inhibited, and the bad data is used.
- **Inferred**: a staging sequence must supply ECC[9:0] that is valid for its data, or a later cached access can post a Cache Error. With SCCorEn clear, ECC[9] must be the even parity of the 128 data bits. An all-zero quadword needs all-zero check bits. The tag ECC must match the staged tag, state and virtual index. The tag ECC matrix is Table 9-6 on NEC UM p. 196. Its text extraction is damaged, so read it from the page image.
- **Unknown**: what a read of a secondary quadword that was never written returns, and whether its check bits are valid. The arrays hold power-on contents.

### Not settled

- **Unknown**: the order in which the two doublewords of a secondary quadword appear in a refilled primary line, that is, which of TagHi and TagLo a word load at the lower address returns. Neither manual says. A PROM routine's staging does not settle it either (see [docs/questions/ip35-prom-cache-staging.md](questions/ip35-prom-cache-staging.md)). Route: stage one word in TagHi and another in TagLo of one doubleword, then read the lower address with a cached word load on an R10000 under a stated plan.
- **Unknown**: the primary I tag address width. NEC UM Table 9-2 (p. 191) lists 27 bits. The tag register format (NEC UM p. 279, Figure 14-28) has 28, made of a 24-bit PTag0 and a 4-bit PTag1.
- **Unknown**: the revision of the R10000 that the manuals describe. They do not tie this behaviour to a revision.

## Coherent block reads and external coherence

These rules cover the processor side of coherent (algorithm 4 and 5) traffic. Each was checked against the R10000
manual's printed pages. They describe the processor, not what the system interface agent does with a request.

- **Established** (R10000 manual p. 128): a data response to a coherent block read shared, or to a noncoherent block
  read, may carry Shared, CleanExclusive or DirtyExclusive. A response to a coherent block read exclusive, or to an
  upgrade, may carry only CleanExclusive or DirtyExclusive. Block data is supplied in subblock order, starting at the
  quadword-aligned address of the request.
- **Established** (p. 142, Table 6-27): the processor's response to an external request, when no internal conflict
  exists. The state response is the former state encoded on SysState[1:0] (Invalid 0, Shared 1, CleanExclusive 2,
  DirtyExclusive 3). Every row returns that former state.

  | Former state | Intervention shared | Intervention exclusive | Invalidate |
  | --- | --- | --- | --- |
  | Invalid | Invalid, no data | Invalid, no data | Invalid, no data |
  | Shared | Shared, no data | Invalid, no data | Invalid, no data |
  | CleanExclusive | Shared, no data | Invalid, no data | Invalid, no data (the manual says this should not occur normally) |
  | DirtyExclusive | Shared, data required, returned as Shared | Invalid, data required, returned as DirtyExclusive | Invalid, no data |

  The manual's footnote says the processor's data response to a shared intervention on a DirtyExclusive block must be
  written back to memory by the external agent.
- **Established** (p. 143, Table 6-28): the processor's resolution when an external request hits a block with a
  request pending issue, meaning buffered but not yet on the system interface:
  - Pending coherent block read: an intervention (shared or exclusive) or an invalidate is serviced with Invalid. The
    processor stalls the read until the external request gets its completion response.
  - Pending upgrade: an intervention or invalidate is serviced with Shared. After the external completion response,
    the processor internally NACKs the pending upgrade.
  - Pending block write: an intervention (shared or exclusive) returns DirtyExclusive, and the write becomes a
    DirtyExclusive data response. An invalidate returns DirtyExclusive and deletes the pending write.
  - Pending eliminate: any intervention or invalidate returns Shared or CleanExclusive, and deletes the eliminate. A
    DirtyExclusive eliminate reports CleanExclusive.
- **Established** (p. 163): a soft reset initializes the external interface state, but leaves the general-purpose,
  CP0 and CP1 registers and both cache levels unchanged. The cache clocks are not affected. Normal operation
  resumes only after a cold reset.

## Not covered here

The victim the replacement logic picks under speculative fetch, the timing of replacement, the cache contents after
cold reset, partial stores, `PREF`, and the exact result of mixed alias accesses are not described here. Requests
that carry NACK or ERR responses, processor reset-mode inputs and instruction-fetch coherence are not covered yet. The open items are listed in
[open-questions.md](open-questions.md).
