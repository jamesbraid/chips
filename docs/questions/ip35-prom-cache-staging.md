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

## Primary-I word format

Question. The 36-bit words some PROM code stores with Index Store Data (I) are not a plain instruction in TagLo with
four extra bits in TagHi. What do they look like, and where do they come from?

Short answer. Established from the code: the PROM does not transform instruction words in software. The only
36-bit words that are not raw flash words come from a table in the PROM (0x1fc89a20 to 0x1fc8a0a0), loaded verbatim by a
separate routine at 0x1fc028cc. The routine of this page stores the words it reads back with Index Load Data (I)
unchanged. Established by exact comparison with the flash instructions at the same addresses: the table words follow
one layout (the 26 non-opcode instruction bits rearranged, the 6-bit opcode replaced by 10 bits, the parity bit the
even parity of all 36). Inferred: that the table is the hardware's own predecode output (a capture of what the cache
holds after a refill) rather than something generated another way. `tools/predecode_table.py` reproduces the
numbers below.

**1. Every Index Store Data (I) in the three PROMs, and the source of what it stores** (code areas only, found by
scanning for the encoding and reading the surrounding instructions):

| PROM | Site | TagHi, TagLo, ECC come from | Label |
| --- | --- | --- | --- |
| IP35 6.210 | 0x1fc02934 (routine 0x1fc028cc, called from 0x1fc00de8) | `lwu` of a 12-byte triple in the table at 0x1fc89a20 per word, sixteen per line, eight lines; before each line `cache 8` with the table's tag; direct flash data, no transform | established |
| IP35 6.210 | 0x1fc04d44, 0x1fc04d4c (this page's routine) | Index Load Data (I) at 0x1fc04d40 and 0x1fc04d48, nothing in between; hardware readback of a line refilled from the secondary cache | established |
| IP35 6.210 | 0x1fc02c90, 0x1fc02c94 (test at 0x1fc02c2c) | pattern table at 0x1fc8a130 (all ones, 0xaaaaaaaa, 0x55555555, 0; TagHi 0xf, 0xa, 0x5, 0; ECC bit 1, 0, 1, 0); stored then read back with Index Load Data (I) and compared on both ways | established |
| IP35 6.210 | 0x1fc02f60, 0x1fc02f64 | TagHi, TagLo, ECC all zero (0x1fc02f18 to 0x1fc02f20): clears the cache | established |
| IP27 6.156 | 0x1fc03210, 0x1fc03214 | pattern test, same shape as the IP35 test (table at 0x1fc74b30) | established |
| IP27 6.156 | 0x1fc034cc, 0x1fc034d0 | zero (the same clear) | established |
| IP30 4.17 | 0x1fc01908 and 0x1fc31cd8 (32 operations each) | zero | established |
| IP30 4.17 | 0x1fc174d4, 0x1fc4b3e4 | a library routine storing the TagHi/TagLo/ECC its caller passes in memory | caller-supplied, not decoded |

No instruction between a load of a flash word and an Index Store Data (I) shifts, masks or inserts bits: the table words
are used as they are, and the copy routine's words are the hardware's. So the PROM does not transform. The table words
sit beside the flash instruction at the same address and follow one regular layout (established); that they are
the hardware's predecode of that instruction is inferred from the regularity and from the PROM storing them without
change, not shown by anything in the PROM or the manual.

**2. Table words beside flash instructions.** The table's eight lines are tagged at 0x1fc027c0 to 0x1fc029ff through
0xa80000001fc0xxxx (way 0). Lines 0 to 4 (0x1fc027c0 to 0x1fc028ff) carry TagLo 0x01fc024c (tag PA[35:12] = 0x1fc02,
state Valid) and the predecoded words of the code at those addresses. Lines 5 to 7 carry TagLo 0 (Invalid) and zero words. 49
distinct nonzero instruction words are in the five valid lines; samples (TagHi:TagLo is the stored 36-bit value, ECC the parity bit):

| Address | Flash instruction | Stored TagHi:TagLo | ECC |
| --- | --- | --- | --- |
| 0x1fc0280c | 0x24040002 `addiu $4,$0,2` | 0x3:44200004 | 0 |
| 0x1fc02818 | 0x24040022 `addiu $4,$0,0x22` | 0x3:46200004 | 1 |
| 0x1fc027c0 | 0x240400f7 `addiu $4,$0,0xf7` | 0x3:47718004 | 0 |
| 0x1fc028b4 | 0x00021438 `dsll $2,$2,16` | 0x1:03880042 | 1 |
| 0x1fc027cc | 0x03e0c825 `or $25,$31,$0` | 0x3:02507c19 | 1 |
| 0x1fc028c4 | 0x03e00008 `jr $31` | 0x8:20807c00 | 0 |
| 0x1fc027c4 | 0x0bf007d9 `j 0x1fc01f64` | 0x8:299ffe00 | 1 |
| 0x1fc027e8 | 0x0ff01260 `jal 0x1fc04980` | 0x8:0e04fe02 | 1 |
| 0x1fc027f4 | 0x4080c806 `mtc0 $0,$25,6` | 0x7:e0601019 | 0 |
| 0x1fc028ac | 0x3c02c000 `lui $2,0xc000` | 0x3:5c000302 | 1 |
| 0x1fc028fc | 0xdc4c0000 `ld $12,0($2)` | 0x6:dc00080c | 0 |
| 0x1fc02840 | 0xbc8b0000 `cache 0xb,0($4)` | 0x6:bc001160 | 1 |

Layout, with `f` the flash word and `p` the 36-bit stored word (TagHi[3:0] is bits 35:32). Established for all 49 words
except four (below), by exact comparison of bits 25:0:

- `p[25:20] = f[5:0]` (funct, or immediate bits 5:0), `p[19:15] = f[10:6]` (shift amount, or immediate bits 10:6),
  `p[14:10] = f[25:21]` (rs), and the two remaining five-bit groups f[20:16] and f[15:11] fill `p[9:5]` and `p[4:0]`.
- `p[4:0]` holds the destination register. For the operations that write rt (`addi`, `addiu`, `ori`, `lui`, `daddiu`, `ld`
  in the sample) `p[4:0] = f[20:16]` and `p[9:5] = f[15:11]`. For the others (SPECIAL, `jr`, `j`, `jal`, `mtc0`, `cache`, the
  conditional branch, all in the sample) `p[4:0] = f[15:11]` and `p[9:5] = f[20:16]`.
- The 6-bit opcode is not stored. `p[28:26] = f[28:26]` (opcode bits 2:0) in every sample; `p[35:29]` is a 7-bit class that
  depends on the opcode and, for SPECIAL, on the function. Observed (`p[35:26]`): `jr` 1000001000, `or` 0011000000, `dsll` and
  `dsll32` 0001000000, nop 0000000000, op 1 (branch on rs) 1110001001, `j` 1000001010, `jal` 1000000011, `addi` 0011010000,
  `addiu` 0011010001, `ori` 0011010101, `lui` 0011010111, `daddiu` 0011110001, `mtc0` 0111111000, `cache` 0110101111, `ld`
  0110110111. Only these opcodes were sampled, so the class encoding is known for them and not beyond: it is an expansion of
  the opcode into 10 bits (the four extra bits and the six that replace the opcode), and it groups by kind (ALU
  immediate, memory, branch or jump, coprocessor 0) but this sample does not give the individual bits a name.
- ECC[0] equals the even parity of the 36 stored bits in all 49 words (the bit is 1 when the data has an odd number of ones).
  The pattern test stores ECC bits that do not follow this rule (all ones with ECC 1, 0xaaaaaaaa with 0), so the cell is
  directly writable and not computed on Index Store Data (I).
- Four words do not equal the flash instruction at their address (established): the `daddiu` at 0x1fc028d8 and
  0x1fc028f0 decode, through the layout, to immediate 0x1fc8 (flash has 0x1fc9), the ones at 0x1fc028e0 and 0x1fc028f8
  to 0x7620 and 0x7ca0 (flash has 0x9a20 and 0xa0a0). Every other field of those four follows the layout. The staged
  line is therefore not byte-equivalent to flash there. Inferred, not shown: that the table was produced from a build
  whose address constants differed (the first constant pair decodes to 0x1fc87620, an address that is not this image's table);
  the observation is only that these four immediates differ from flash.

For the sample words the extra bits are not a bit inserted inside the instruction: the instruction fields are permuted and
the opcode is expanded. Example: `addiu $4,$0,2` is 0x3:44200004; opcode 001001 becomes class 0011010001 at bits 35:26, immediate
2 sits at bits 25:20 and register 4 at bits 4:0. `lui $2,0xc000` (0x3c02c000) is 0x3:5c000302: rt = 2 at bits 4:0, immediate bits 15:11 (11000 = 0x18) at bits 9:5.

**Class table, p[35:29] (inferred, from the 80 slots of the five Valid lines).** Each row pairs a class value with the
instructions the flash holds at the addresses whose table word carries it (the pairing is observed; that the class means
this opcode for any other occurrence is inferred). p[28:26] is f[28:26]. "Bits 4:0" says which instruction field sits in
p[4:0]: rt (`f[20:16]`, the operations that write rt) or the rd position (`f[15:11]`: SPECIAL rd, a branch offset's top bits,
`mtc0` rd, `cache`/`jal` bits). `tools/predecode_table.py` prints these rows.

    class  opcode / funct                         f[31:29]  bits 4:0  p[28:26]            words  source
    0x00   SPECIAL funct 00 (sll; the nop)        000       -         000                 14     table lines 0-4
    0x08   SPECIAL funct 38 (dsll), 3c (dsll32)   000       rd        000                 10     table lines 0-4
    0x18   SPECIAL funct 25 (or)                  000       rd        000                 2      table lines 0-4
    0x1a   op 08 addi, 09 addiu, 0d ori, 0f lui   001       rt        000,001,101,111     13     table lines 0-4
    0x1e   op 19 daddiu                           011       rt        001                 12     table lines 0-4
    0x35   op 2f cache                            101       rd        111                 12     table lines 0-4
    0x36   op 37 ld                               110       rt        111                 1      table line 4
    0x3f   op 10 mtc0                             010       rd        000                 12     table lines 0-4
    0x40   op 03 jal                              000       rd        011                 1      table line 0
    0x41   SPECIAL funct 08 (jr), op 02 (j)       000       rd        000 (jr), 010 (j)   2      table lines 0, 4
    0x71   op 01 (REGIMM, branch on rs)           000       rd        001                 1      table line 4
    0x7f   (pattern data, TagHi:TagLo 0xf:ffffffff, ECC 1)       pattern self-test table 0x1fc8a130
    0x55   (pattern data, 0xa:aaaaaaaa, ECC 0)                   pattern self-test table
    0x2a   (pattern data, 0x5:55555555, ECC 1)                   pattern self-test table
    0x00   (pattern data, all zero, ECC 0)                       pattern self-test table

**The seven classes reported undecodable (0x00, 0x08, 0x1e, 0x35, 0x3f, 0x41, 0x71): all are in the table above.**
- 0x00 is the nop (`sll $0,$0,0`, 14 of the 80 slots in the Valid lines) and also every word of the three Invalid lines
  (all 48 table triples there are zero, TagLo 0 so the lines are Invalid and never fetched) and the zero entry of the pattern
  table. An all-zero 36-bit word is the nop; no other word carries class 0x00 except `sll` with nonzero fields, none in the table.
- 0x08 `dsll`/`dsll32`, 0x1e `daddiu`, 0x35 `cache`, 0x3f `mtc0`, 0x41 `jr`/`j`, 0x71 branch on rs (op 1): these are the
  opcodes of the code the PROM runs from the staged lines (by reading the code, not simulated): after the table is loaded, 0x1fc0295c jumps (`jr`) to
  0x980000001fc027f4, which executes table lines 0 to 4 (the `mtc0` sequence at 0x1fc027f4 to 0x1fc02824, the `dsll`
  and `cache` words through 0x1fc02884, the `daddiu`/`dsll` address building, the `jr $31` at 0x1fc028c4).
  The classes the table also carries but that code does not run (0x18, 0x1a, 0x36, 0x40) are the `or`,
  `addi/addiu/ori/lui`, `ld` and `jal` words.
- Not instructions: 0x7f, 0x55, 0x2a, and the zero entry. They come from the pattern test (0x1fc02c90), which stores them,
  reads them back and compares, through the 0xa800000000000000 alias on both ways; the self-test is the only reader.
  Inferred: never fetched as code.

**Other sources on the paths a Fuel takes.** The table loader at 0x1fc00de8 is reached by straight-line code from the
cache clear at 0x1fc00de0 after the pattern test, and I found no branch between 0x1fc00c88 and 0x1fc00de8 that depends on
a board-type value (the conditionals there test the pattern-test result, and the low bit of the 8-byte read at
0x9200000001000020 only picks which of two LED slots is written). Earlier branches in the reset code (0x1fc00604 to
0x1fc0064c, 0x1fc00c4c) test Status and Config values and a call result and can bypass it; I did not trace a board-type
read to them, so that a Fuel runs the loader is not shown here. The other Index Store Data (I) source on the staging
paths is this page's routine (0x1fc04d44, 0x1fc04d4c), whose words are hardware readbacks of whatever it staged: a model that predecodes
needs a class for every opcode in the staged range, and the table does not give them all. Opcode/funct values in the
ranges the eight call sites stage that have no class in the table (data words in a range included): routine itself
(0x1fc04980 to 0x1fc04f3f) funct 09 16 24 26 2b 2f 3a 3e and ops 04 05 07 0b 0c 11; 0x1fc027e8 none; 0x1fc03490
funct 24 26 27 2d 3a 3e and ops 04 05 0c 0e 3f; 0x1fc036dc funct 26 27 2d 3a 3e and ops 04 05 0c 0e 3f; 0x1fc0394c funct 24 2d
3a and op 05; copy: funct 24 and ops 04 05 3f; verify: funct 2d and ops 04 05 3f (`beq` 04 and `bne` 05 are among them).
These classes are undecodable from this PROM; they are not needed if the model keeps the architectural word.

**3. The simulator's hit path.** The simulator returned `TagLo` as the instruction word on every primary hit
(`e['w'][wi] & 0xffffffff`) and kept TagHi's four bits unused. That is correct only for the routine it ran: it models
the refill as copying the secondary data words unchanged, so Index Load Data (I) returns the raw flash word in TagLo
and Index Store Data (I) stores it back, which is why every fetch equalled flash. It did not run the table routine at
0x1fc028cc (reached from the reset path at 0x1fc00de8, not from the eight call sites this page covers), and it had no
predecode, so the table words (TagLo 0x44200004 for an `addiu` that flash holds as 0x24040002) were never presented to it.
Executing TagLo as the instruction would be wrong for every one of those table words. On silicon the refill predecodes
and the routine copies the predecoded words, so the staged lines hold predecoded words for the copy path too and the
instruction executed is the decode of those words, not TagLo.

**Consequence for a model.** Either keep the primary instruction cache data opaque and self-consistent (store what Index
Store Data (I) gives, return it from Index Load Data (I), and execute by decoding it with the layout above, which needs
the class bits for the opcodes it meets), or hold the architectural word beside the 36-bit value and execute that. In
the second case the table's words need the architectural word from the table, not from TagLo, and the four
mismatched immediates above must be reproduced if the code that uses them runs from the cache. The layout above is exact for the
sampled opcodes and a model cannot derive it from the manual, which says only that the word is 36 bits.

## Pass one in order, and what it needs from the primary instruction cache

Answers to a model trace in which the routine's primary-I way 1 ends up holding zero words (352 Index Store Data (I)
operations of zero, covering 0x1fc04980 to 0x1fc04eff, then Index Store Tag (I) on sets 38 to 60 with TagLo 0x01fc0444).
All from the code and the simulator's operation log (word order `lo-hi`, copy call at 0x1fc05950); "needs" statements follow from the code.

**Order (established).** There is no zero fill of the primary cache in this routine. The only zero fill is of the
secondary slot (0x1fc04abc, 0x1fc04ac0, before the loop). Pass one, per 8-byte piece, 176 pieces from 0x1fc04980 to
0x1fc04f00:

1. 0x1fc04c64 Index Store Data (S) of the piece into slot quadword 0; 0x1fc04c68, 0x1fc04c8c, 0x1fc04cc8, 0x1fc04cdc
   Index Load Data (S) readbacks and compares.
2. 0x1fc04d04 Index Store Tag (I) set 60 way 1 Invalid (TagLo 0x8); 0x1fc04d28 Index Store Tag (I) set 60 way 0 Valid
   with the bogus tag (TagLo 0xffffff4c, TagHi 0xf). Set 60 is the slot's set (VA[13:6] of 0x980000001fc04f00).
3. 0x1fc04d34 `jalr` fetches 0x980000001fc04f10: primary miss, secondary hit, refill of the Invalid way 1.
4. 0x1fc04d40 Index Load Data (I) set 60 way 1 word 0; 0x1fc04d44 Index Store Data (I) of that word to the target
   (set 38 onward, way 1 in pass one); 0x1fc04d48 Index Load Data (I) word 1; 0x1fc04d4c Index Store Data (I) of it.
5. After the last piece: 0x1fc04d68 Index Store Tag (S) invalidates the slot; then 0x1fc04e10 Index Store Tag (I),
   one per 64-byte target line, way 1, sets 38 to 59 (22 lines) and set 60 (the 23rd, the slot line), TagHi 0,
   TagLo 0x01fc0444 for the first line (tag PA[35:12] = 0x1fc04, Valid, parity bit set).

So the 352 Index Store Data (I) are the readback-then-store copies, and the tags come last. The data is never "filled with zero and
later overwritten": what the copies store is the data. If the Index Load Data (I) at 0x1fc04d40 and 0x1fc04d48 return
zero, the 352 stores are zero and the tags then make them Valid, which reproduces the trace's state exactly. I confirmed
it by forcing both loads to zero in the simulator: 352 stores, 352 zero, 22 way-1 line tags on sets 38 to 59 with TagLo
0x01fc0444. Normally 320 of the 352 are nonzero (the other 32 are nop words of the code).

**What the copy reads (established).** Only set 60 way 1, words 0 and 1 (operands 0x980000001fc04f01 and 0x980000001fc04f05),
every piece. It does not read the lines at sets 38 to 59 and does not read lines executed earlier from 0x98... : before pass
one the routine runs from the mapped uncached window (0xc00000001fc0xxxx), and the first and every cached fetch in pass one up to the
`jr` at 0x1fc049f4 is the trampoline fetch at 0x980000001fc04f10. The routine does depend on a line filled by an
ordinary cached fetch: the Index Load Data (I) reads the line the fetch at 0x980000001fc04f10 just refilled from the
secondary cache. A model that does not fill the primary cache on a cached fetch that misses it returns empty contents there.

**On hardware (inferred).** The refill fills the way the cache picks, the tag equals the physical address, and the words are the
predecoded form of the secondary data (this is how the PROM gets predecoded words without doing the predecode: the secondary
holds raw flash words, the refill predecodes them, the copy moves the predecoded form; the word format section above
gives the layout and the table-driven loader stores the same layout). The routine requires the refill to choose way 1
(the way it set Invalid) and to predecode; the manual specifies neither (see below). In the simulator the first piece's Index Load
Data (I) returned 0x44223000 (word 0) and 0x30430010 (word 1), the staged flash words, since the simulator's refill copies
words unpredecoded; the simulator does fill the primary cache on a cached fetch that misses the primary and hits the secondary
(`fetch()` refill), and only then.

**Intent (inferred).** Not execution from the other way and not from the secondary cache. After the loop the routine
invalidates the slot in the secondary cache (0x1fc04d68) and writes no secondary tag for the target range, so the secondary cache
cannot supply 0x1fc04980 onward. Execution continues from primary way 1 at 0x980000001fc04a28 (the `jr` built at
0x1fc049f4 to 0x1fc04a24) out of the lines it just copied and tagged Valid. A zero-filled way 1 is therefore a symptom of the
readbacks, not a design: the copy only works if the Index Load Data (I) readbacks contain the refilled words.

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
