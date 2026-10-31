# IP35 PROM cache staging: do the later cached fetches hit the lines the routine staged?

Question. The IP35 boot PROM runs a routine at 0x1fc04980 to 0x1fc04e8c that stages code into the CPU caches with
CACHE index operations, then continues from the cached xkphys alias 0x98000000_1fc0xxxx (cache algorithm 3) of
physical 0x1fc0xxxx. RAM is enabled at that physical address by then. Does every cached instruction fetch
through a 0x98... or 0xa8... alias hit a line the routine staged, and would "a cached fetch reads the boot flash"
return the same words?

Short answer. Yes to both, at all eight call sites of the routine (the copy wrapper at 0x1fc05950, the verify
wrapper at 0x1fc05a14 and the six others, tabulated below), provided the PROM's word order for secondary-cache doublewords is the one this page infers (see
"Where the manual is silent"). At the six sites that stage a range, every cached fetch is a primary
instruction-cache hit on a line staged by CACHE operations, except the fetch at 0x980000001fc04f10, which misses the primary cache, hits the secondary cache line
the routine staged, and is refilled from it. No fetch reaches the system interface. Every word returned equals
the flash word at the same offset. At two sites the routine refuses to stage a range and the caller never runs
from a cached alias.

Sources. The shipped IP35 PROM, SGI Version 6.210 (built Aug 26 2004), container segment `ip35prom`, load
address 0xc00000001fc00000, length 0x1686a8, additive checksum ok; unpacked with `tools/promgen64.py`. MIPS
R10000 Microprocessor User's Manual, version 2.0 (October 10, 1996): sections 4.1 to 4.3 (cache organisation,
pp. 46 to 52), 5.1 (secondary cache arrays), 10.1 to 10.22 (CACHE operations, Table 10-1, pp. 191 to 202),
14.21 (ECC register, p. 273) and 14.23 (TagLo and TagHi, Figures 14-28 to 14-33, pp. 278 to 283). Companion
page: [ip35-reset-window.md](ip35-reset-window.md).

Simulator: `tools/cache_stage_sim.py` (needs Python with `capstone`). It interprets the integer, CP1-move, CP0-move and
CACHE instructions of the two paths straight from the PROM bytes, with the cache model below, and stops on
anything else. It does not use the Unicorn harness: Unicorn runs CACHE as a no-op and exposes no TagLo, TagHi or ECC
registers, so a purpose-built interpreter was shorter than hooking it (the Unicorn route was not tried).

    python3 tools/promgen64.py ip35prom.img OUT ip35
    python3 tools/cache_stage_sim.py OUT/ip35.ip35prom.bin --dword lo-hi --regions
    python3 tools/cache_stage_sim.py OUT/ip35.ip35prom.bin --matrix --copy-len 0x2000

## Cache model (from the manual)

| Item | Value | Label |
| --- | --- | --- |
| Primary instruction cache | 32 KB, 2-way, 64-byte blocks (16 words), index VA[13:6], way VA[0], tagged with PA[39:12] (4.1, 10.2, 10.8) | established |
| Secondary cache | 2-way, size 512 KB to 16 MB and block 64 or 128 bytes chosen by mode bits (4.3, 5.1); Index operations use PA[size-2:block] as the set, PA[0] as the way and PA[3] to pick the doubleword of a quadword (10.10, 10.19, 10.22) | established; size and block of IP35 not known, swept |
| Index Store Tag (I) 0x08 | Tag[35:12] = TagLo[31:8], Tag[39:36] = TagHi[3:0], state = TagLo[6], LRU = TagLo[3] (10.8) | established |
| Index Load/Store Data (I) 0x18, 0x1c | one 36-bit instruction in TagHi[3:0]:TagLo[31:0], address VA[13:2], way VA[0], tag untouched; Store bypasses predecode (10.17, 10.20) | established |
| Index Store Tag (S) 0x0b | Tag[35:18] = TagLo[31:14], Tag[39:36] = TagHi[3:0], state = TagLo[11:10] (0 Invalid, 1 Shared, 2 Clean Exclusive, 3 Dirty Exclusive), virtual index = TagLo[8:7], tag check bits = TagLo[6:0], MRU = TagHi[31] (10.10, Figure 14-30) | established |
| Index Load/Store Data (S) 0x1b, 0x1f | one doubleword from or to TagHi and TagLo, the other doubleword of the quadword zero on a store, 10 check bits in ECC[9:0], tag untouched (10.19, 10.22, Figure 14-33) | established |
| Cached fetch | primary hit if a way is Valid and its tag equals PA[39:12]; else a secondary hit if a way is non-Invalid and its tag equals PA[39:18], refilling the primary block from the secondary data; else a system read | inferred from 4.1 to 4.3 (the manual describes the organisation, not the fetch algorithm in these words) |

Not modelled: predecode bits, parity and ECC checking, the virtual-index and subset checks, cache-error exceptions,
the serialisation rules for CACHE (the model runs operations in program order).

## What the routine does, in cache terms

The routine runs twice per call. Pass one (`$8` = 1) stages the routine itself, 0x1fc04980 to 0x1fc04f3f, into way 1
and continues from 0x98000000_1fc04a28. Pass two (`$8` = 0) stages the caller's loop, from the 64-byte line holding the
return address up to the argument in `$4` (0x1fc059c4 for copy, 0x1fc05b2c for verify), into way 0, then returns with
`$31` rewritten to the 0x98... alias. Per 8-byte piece, with `$7` = 0x980000001fc04f00 (the staging slot, primary set
0x3c):

1. Before the loop: Index Store Data (S) zeroes quadwords 0 to 7 of the slot in both ways (0x1fc04abc, 0x1fc04ac0);
   `cache 0x1f,16($7)` stores 0x01400008 into quadword 1 with ECC 0x395 (0x1fc04af4); Index Store Tag (S) writes way 0
   (state 1 Shared, tag PA[35:18] = 0x7f0, the slot's address) and way 1 (Invalid) (0x1fc04b84, 0x1fc04b90).
2. The 8 code bytes are read through the mapped uncached window (`ld` at 0x1fc04bfc), a check word is built, and the
   piece is stored to quadword 0 of the slot (0x1fc04c64) and read back and compared (0x1fc04c68 to 0x1fc04cec).
3. Primary tags for the slot's set: way 1 Invalid (0x1fc04d04, TagLo 0x8), way 0 Valid with the bogus tag
   PA[39:12] = 0xfffffff (0x1fc04d28, TagLo 0xffffff4c, TagHi 0xf).
4. `jalr $10,$7` at 0x1fc04d34 fetches 0x980000001fc04f10. Both primary ways fail (way 0's tag does not match, way 1 is
   Invalid), the secondary way 0 matches, and the primary block is refilled into the Invalid way, way 1.
5. Index Load Data (I) reads words 0 and 1 of the slot back from way 1 (0x1fc04d40, 0x1fc04d48) and Index Store Data (I)
   writes them to the target line, way `$8` (0x1fc04d44, 0x1fc04d4c). The target is the 0x98... alias of the code.
6. After the last piece, Index Store Tag (I) marks each 64-byte target line Valid with tag PA[39:12] = the line's
   physical address and a computed parity (0x1fc04e10; 26 lines for the copy path, 28 for verify); Index Store Tag (S) with zero TagLo/TagHi
   invalidates the slot's secondary way 0 (0x1fc04d68).

Operation counts (copy of 0x1686a8 bytes / verify of 0x1686a8 bytes): Index Store Data (S) 242 / 258, Index Store
Tag (S) 6 / 6, Index Load Tag (S) 4 / 4, Index Load Data (S) 832 / 896, Index Store Tag (I) 442 / 476, Index Load
Data (I) 416 / 448, Index Store Data (I) 416 / 448. The routine makes no cached load or store; its data reads use the
mapped uncached window.

## Result

Run with word order `lo-hi` (below), secondary cache 1 MB with 128-byte blocks. Counts scale with the copied length.

| Fetch | Class | Word returned | Flash word |
| --- | --- | --- | --- |
| 0x980000001fc04a28 to 0x980000001fc04e7c (pass-one targets, 10222 fetches copy, 16740 verify) | primary hit, way 1, line staged by CACHE ops | equal | equal |
| 0x980000001fc04f10, the `jalr` target (208 copy, 224 verify) | primary miss, secondary hit, refill into way 1 | 0x01400008 (`jr $10`) | 0x01400008 |
| 0x980000001fc04f14, its delay slot (208, 224) | primary hit, way 1, line refilled from the secondary cache | 0x00000000 | 0x00000000 |
| 0x980000001fc05958 to 0x980000001fc059c0, copy loop (461347) | primary hit, way 0, staged | equal | equal |
| 0x980000001fc05a1c to 0x980000001fc05ac8, verify loop (184560) | primary hit, way 0, staged | equal | equal |

Differences between returned word and flash word: 0 of all fetches, both paths. Misses of both caches: 0.
Cached loads and stores through 0x98... or 0xa8...: 0. After the copy path the destination equals the source and the
verify path returns 0, so the simulated routine does what the PROM expects. `--matrix` repeats the run for secondary
caches of 512 KB to 16 MB with 64- and 128-byte blocks and for both miss policies: the same result in every
configuration, 0 secondary misses. The miss policy and secondary geometry do not matter because nothing misses.

The question's specific fetch, `jalr $10,$7` landing on 0x980000001fc04f10 from 0x1fc04d34: a primary miss and a
secondary hit on the line the routine staged (Index Store Tag (S) at 0x1fc04b84, Index Store Data (S) at 0x1fc04af4).
It is not served from flash or RAM.

Label: **established** that, given the manual's CACHE semantics and a word order of `lo-hi`, every fetch of both paths
hits staged lines and returns the flash word. **Inferred** for the fetch algorithm, the refill victim and the word
order. **Unknown** for the code that runs after the first instructions of each caller from the staged lines: the
simulator stops at the first instruction it does not model (listed below), so branches that leave the staged range
later are not checked. The whole staged range was fetched word by word instead.

## The other six call sites

`--callers` starts at each call site with the registers the caller's own code builds and runs the routine to its
return. It then fetches every word of the range the routine staged (the 64-byte line holding the return address up to
the end address in `$4`, ORed with 0x3c) through the 0x98... alias, and keeps running the caller from the returned
`$31` until an instruction the interpreter does not model. The four direct calls (`jal`) pass an address in the
mapped window. The two indirect calls (`jalr` through the table slot at 0x1fd67ce0, whose contents in the image are
0xc00000001fc04980) pass the words at 0x1fd67cd8 and 0x1fd67cf8 of the image. Secondary cache 1 MB, 128-byte blocks,
miss returns flash. Output is byte-identical for secondary caches of 512 KB, 1 MB, 4 MB and 16 MB, blocks of 64 and
128 bytes, and both miss policies (16 runs).

| Call site | End address `$4` | Word order `lo-hi` | Word order `hi-lo` |
| --- | --- | --- | --- |
| 0x1fc027e8 | 0xc00000001fc028cc | stages 0x...27c0 to 0x...28fc: 80 of 80 words hit, 0 miss, 0 differ from flash; caller then fetches 2 words from the staged lines until `mtc0` to CP0 register 25 | returns with `$31` unchanged: pass one's own fetches differ (below), no range staged |
| 0x1fc03490 | 0xc00000001fc03630 | 0x...3480 to 0x...363c: 112 of 112 hit, 0 miss, 0 differ; 15 caller fetches, all staged, stop at `xori` | as above |
| 0x1fc036dc | 0xc00000001fc03894 | 0x...36c0 to 0x...38bc: 128 of 128 hit, 0 miss, 0 differ; 16 caller fetches, stop at `xori` | as above |
| 0x1fc0394c | 0xc00000001fc039a8 | 0x...3940 to 0x...39bc: 32 of 32 hit, 0 miss, 0 differ; 11 caller fetches, stop at a load from an address the interpreter has no value for | as above |
| 0x1fc368bc (`jalr $8`) | 0xc00000001fc0dacc | pass one only; pass two refuses (end address lies below the return address, `$4 - $5` unsigned is above 0x4000, test at 0x1fc04a44 to 0x1fc04a4c), routine returns with `$31` still in the mapped window: no cached fetch after pass one | as above |
| 0x1fc36fbc (`jalr $7`) | 0xc00000001fc0dad4 | as 0x1fc368bc | as above |

Pass one's own fetches (the routine's 0x...4a28 to 0x...4e7c, and 0x...4f10, 0x...4f14, 0x...4f18) are the same at
every site. Under `lo-hi`: 184 slot refills (0x...4f10), 13 further staged fetches, all equal to flash. Under
`hi-lo`: 562 cached fetches, 378 differ (all 184 of 0x...4f10 return 0 instead of `jr $10`, all 184 of 0x...4f14 return
`jr $10` instead of 0, all 10 staged fetches from 0x...4a28 on), 0 miss both caches, and the pair-swapped code takes
a branch to the routine's return at 0x1fc04e78 (observed for the call at 0x1fc027e8) before pass two, leaving `$31`
unconverted. So under `hi-lo` none of the eight sites reaches a cached caller.

## Staged range and operand translation

`--staged` prints, per call site, every CACHE operation's operand and the staged set at the routine's return
(secondary cache 1 MB, 128-byte blocks, word order `lo-hi`; the set numbers below depend on that geometry, nothing else does).

**Operands (established from the code, simulated).** No CACHE operation uses a mapped address. Every operand is an
xkphys cache-algorithm-3 alias, VA[63:59] = 0x13 (0x98...), which is unmapped: the physical address is VA[35:0]. The
routine builds them as `(PA & 0x1fffffff) | 0x13 << 59 | way`: the slot register at 0x1fc04a88 to 0x1fc04aa4
(`$7` = 0x980000001fc04f00) and the target register at 0x1fc04a78 to 0x1fc04a84 (`$6`, advanced by 8 per piece, bit 0 =
way). The code itself runs from the mapped window 0xc00000001fc0xxxx, but that address is only a fetch address and a
data-read address (`ld` at 0x1fc04bfc); no CACHE operation takes it. Translation of the operands is therefore the
identity on the low 32 bits.

| Operation (instruction address) | Operand VA | Physical | Index bits used |
| --- | --- | --- | --- |
| Index Store Data (S), zero fill (0x1fc04abc, 0x1fc04ac0) | 0x980000001fc04f00 to 0x...4f70 step 0x10, way bit 0 then 1 | 0x1fc04f00 to 0x1fc04f70 | set PA[19:7] = 0x9e, way PA[0], quadword PA[6:4], doubleword PA[3] |
| Index Store Data (S), trampoline (0x1fc04af4) | 0x980000001fc04f10 | 0x1fc04f10 | set 0x9e, way 0, quadword 1, doubleword 0 |
| Index Store Tag/Load Tag (S) (0x1fc04b84, 0x1fc04b90, 0x1fc04b94, 0x1fc04bcc, 0x1fc04d68) | 0x980000001fc04f00 and 0x...4f01 | 0x1fc04f00, 0x1fc04f01 | set 0x9e, way PA[0] |
| Index Store/Load Data (S), per piece (0x1fc04c64, 0x1fc04c68, 0x1fc04c8c, 0x1fc04cc8, 0x1fc04cdc) | 0x980000001fc04f00, +0x10, +8, +0xc | 0x1fc04f00 to 0x1fc04f10 | set 0x9e, way 0, quadword 0 or 1 |
| Index Store Tag (I) on the slot set (0x1fc04d04, 0x1fc04d28) | 0x980000001fc04f01 (way 1), 0x980000001fc04f00 (way 0) | 0x1fc04f00 | primary set VA[13:6] = 0x3c, way VA[0] |
| Index Load Data (I) from the slot (0x1fc04d40, 0x1fc04d48) | 0x980000001fc04f01, 0x980000001fc04f05 | 0x1fc04f00 | set 0x3c, way 1, word VA[5:2] = 0 and 1 |
| Index Store Data (I) into the target (0x1fc04d44, 0x1fc04d4c) | 0x98...1fc0xxxx and +4, bit 0 = pass (1 then 0) | the target code's physical address | set VA[13:6], way VA[0], word VA[5:2] |
| Index Store Tag (I) per target line (0x1fc04e10) | 0x98...1fc0xxx0 per 64-byte line, bit 0 = pass | the line's physical address | set VA[13:6], way VA[0] |

Index by the untranslated VA instead of the translated PA: identical for every operand, because for an unmapped
xkphys address VA[35:0] equals the PA and the secondary index (at most PA[23:6] for 16 MB) never reaches bit 36. The
simulator indexes the secondary cache by the PA; rerunning with the 64-bit VA substituted gives the same result at
all eight sites (same hits, same fetches). Had the operands been the mapped 0xc00000001fc0xxxx alias, translation by TLB
entry 62 (0xc00000001fc00000 to 0x1fc00000) is also the identity on the low 32 bits, so that would not change the
set or way either. The simulator has no TLB; it models the mapped window as that identity.

**Staged set per call site (established, simulated).** Primary data cache: none, no D-cache CACHE operation is issued.
Index Store Data (S) writes one doubleword per operation and zeroes the other doubleword of the quadword. Index Store
Data (I) writes one word per operation, two per 8-byte piece. Pass one stages the routine itself into way 1 (23 lines,
PA 0x1fc04980 to 0x1fc04f3f, the last one is the slot line, set 0x3c); pass two stages the caller's code into way 0.
The slot in the secondary cache is one block (set 0x9e): quadwords 0 to 7 of both ways are zero-filled, quadword 0 is
rewritten per piece, quadword 1 holds `jr $10`; only way 0 is ever given a valid tag and it is invalidated at 0x1fc04d68,
so no secondary line is valid at return (16 quadwords written, 2 tags written).

| Call site | Way-0 target lines (primary I) | Target PA span | Way-1 lines | Index Store Data (S) ops | Index Store Data (I) words | Index Store Tag (I) ops |
| --- | --- | --- | --- | --- | --- | --- |
| 0x1fc027e8 | 5 | 0x1fc027c0 to 0x1fc028ff | 23 | 258 | 448 | 28 |
| 0x1fc03490 | 7 | 0x1fc03480 to 0x1fc0363f | 23 | 274 | 480 | 30 |
| 0x1fc036dc | 8 | 0x1fc036c0 to 0x1fc038bf | 23 | 282 | 496 | 31 |
| 0x1fc0394c | 2 | 0x1fc03940 to 0x1fc039bf | 23 | 234 | 400 | 25 |
| 0x1fc05950 (copy) | 3 | 0x1fc05940 to 0x1fc059ff | 23 | 242 | 416 | 26 |
| 0x1fc05a14 (verify) | 5 | 0x1fc05a00 to 0x1fc05b3f | 23 | 258 | 448 | 28 |
| 0x1fc368bc | 0 | none staged | 23 | 201 | 368 | 23 |
| 0x1fc36fbc | 0 | none staged | 23 | 201 | 368 | 23 |

At return every site also leaves one stray valid way-0 line at primary set 0x3c with the bogus tag PA[39:12] =
0xfffffff (written at 0x1fc04d28, never cleared).

**Sequential fetches after the trampoline (established, simulated).** The fetch at 0x980000001fc04f10 returns `jr $10`
and the caller resumes at 0x1fc04d3c. The only cached fetches in 0x1fc04f00 to 0x1fc05fff in any run are
0x1fc04f10 and its delay slot 0x1fc04f14. Nothing is fetched from 0x1fc04f18 to 0x1fc04ffc, 0x1fc05000 or 0x1fc06000 through
a 0x98... alias, so there is no fall-through to explain. Lines beyond the first 64-byte block of the slot are not staged:
the primary cache holds way-1 lines only up to 0x1fc04f3f, and the secondary cache holds only the zero-filled slot
quadwords with no valid tag at return. A fetch of 0x1fc04f40 onward misses both caches and is a system read. A model
that runs on through 0x1fc04f18 to 0x1fc04ffc and then page by page is therefore executing without ever seeing `jr $10` at 0x1fc04f10
(or at 0x1fc04f14 under the other word order); the simulation says the word at 0x1fc04f10 must come from secondary
quadword 1 (PA[4] = 1, written once at 0x1fc04af4 before quadword 0 is rewritten 208 or more times), and that a model
which merges quadwords 0 and 1 (ignoring PA[6:4] on Index Store Data (S)) would overwrite it (reasoning from the operation order, not simulated).

## Where the manual is silent, and what the PROM requires

1. **Word order of a secondary-cache doubleword (inferred).** Contradicted: Figure 14-33 (p. 283), and the text of
   10.19 and 14.23, say TagHi carries doubleword bits 63:32 and TagLo bits 31:0. Left open: how the quadword
   halves of the secondary data array map to the words of a primary-cache refill and to memory order; sections 10.17,
   10.20 and Figure 14-31 describe only the registers. The routine loads a doubleword `d` from flash (big-endian, first word in the high half) and
   writes `TagHi = d[31:0]`, `TagLo = d[63:32]`, the opposite. With the manual's literal order (`hi-lo`) the staged
   words come out pair-swapped relative to flash: the staged fetches from 0x980000001fc04a28 on return different
   words than flash and the run diverges (378 of 562 fetches differ at `--copy-len 0x2000`, including all 184 fetches of
   0x980000001fc04f10, which return 0 instead of `jr $10`; 0 secondary misses). Only `lo-hi` reproduces a routine that works, and the PROM boots on silicon, so the secondary data array
   to primary refill path must hand the word in TagLo to the lower address. The manual does not describe how a
   secondary quadword maps to the words of a primary refill, so this is a reading that fits the PROM, not a manual
   statement. The check word does not discriminate: the routine's check bits for 0x01400008 in either half are 0x395.
   The trampoline itself still works in both orders (`jr $10` is then in the word at 0x4f14), but the copied code does
   not.
2. **Refill victim (inferred).** The routine marks way 1 Invalid and way 0 Valid with a non-matching tag, then reads
   back from way 1. That works only if a refill takes an Invalid way before a Valid one. With "always way 0" the run does
   not terminate (stopped at the step limit) and the staged lines differ from flash. Left open: section 4.1 gives "least-recently-used" replacement
   and Figure 14-28 (p. 279) a one-bit LRU field in each primary tag (TagLo[3], set in both tags here), with the
   encoding and whether an Invalid way is preferred unstated; nothing there contradicts the PROM's reading.
3. **Predecode (unspecified).** Index Load Data (I) returns 36 bits per instruction, four more than the word, and
   Index Store Data (I) writes them back unchanged (10.17, 10.20). The extra bits are not defined in the manual; the
   routine copies them without looking at them, so the architectural word is unaffected. The model keeps them zero.
4. **Check bits (unspecified).** The ECC code of the secondary data array is not in the manual. The routine computes
   its own check word from a ten-entry mask table at 0x1fc04f80 and the primary parity bit travels from Load to Store
   through ECC[0]. A real refill would check them; the model does not, so a wrong check word would be a cache error
   on silicon and is invisible here.
5. **Tag parity and the bogus way (unspecified).** The routine sets the state-parity and computes the tag parity for the
   target lines, and sets 0x4c in the bogus way. The model ignores parity.
6. **Mapped window and KSEG1 (assumed).** The model serves the 0xc00000001fc0xxxx window (TLB entry 62) and KSEG1 from
   the flash. That is the reset-window page's conclusion, not something this simulation tests.

## Implication for an emulator

At all eight call sites, an approximation "cached (algorithm 3) fetches of 0x1fc0xxxx read the flash" returns
byte-identical words to what the real caches would supply: 0 differences in every fetch of the staged ranges (673,733 on the copy and verify paths, and 80 + 112 + 128 + 32 words
at the four other staging sites; the two remaining sites stage no range), because the routine copies
verbatim flash bytes into the lines it forges and the one hand-built word, `jr $10` at 0x1fc04f10, is also in the
flash image. It is therefore sufficient for what was simulated, but it does not follow the hardware: on silicon those fetches
never reach the bus, and a store to RAM at the same physical address would not change what runs. The approximation
breaks if RAM is written there, if the caches are flushed, or if a different caller stages different bytes.

Faithful alternative: model the R10000 index operations used here (Index Store/Load Data and Tag for the primary
instruction and secondary caches, 0x08, 0x0b, 0x07, 0x18, 0x1b, 0x1c, 0x1f) with a small array model and the fetch
algorithm above. The simulator is a working reference for it, including the two choices (word order, invalid-first
refill) that a model must make the same way. A model that returns zeroes for the unstaged fetch (RAM contents) shows
the behaviour a hardware capture would show only if the staging is missing.

## Next

The simulator stops at the first unmodelled instruction after each caller returns, so a branch out of a staged range
into another 0x98... target later in the caller's code is not checked. Extending the interpreter over those
caller bodies (CP0 moves, `xori` and a few others) would close that. A physical test is not needed to settle this
question.
