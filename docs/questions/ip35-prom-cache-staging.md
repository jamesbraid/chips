# IP35 PROM cache staging: do the later cached fetches hit the lines the routine staged?

Question. The IP35 boot PROM runs a routine at 0x1fc04980 to 0x1fc04e8c that stages code into the CPU caches with
CACHE index operations, then continues from the cached xkphys alias 0x98000000_1fc0xxxx (cache algorithm 3) of
physical 0x1fc0xxxx. RAM is enabled at that physical address by then. Does every cached instruction fetch
through a 0x98... or 0xa8... alias hit a line the routine staged, and would "a cached fetch reads the boot flash"
return the same words?

Short answer. Yes to both, for the two paths run (the copy wrapper at 0x1fc05910 and the verify wrapper at
0x1fc059d0), provided the PROM's word order for secondary-cache doublewords is the one this page infers (see
"Where the manual is silent"). Every cached fetch is a primary instruction-cache hit on a line staged by CACHE
operations, except the fetch at 0x980000001fc04f10, which misses the primary cache, hits the secondary cache line
the routine staged, and is refilled from it. No fetch reaches the system interface. Every word returned equals
the flash word at the same offset.

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
order. **Unknown** for the six other callers of the routine (0x1fc027e8, 0x1fc03490, 0x1fc036dc, 0x1fc0394c,
0x1fc368bc, 0x1fc36fbc), which were not run: the same simulator can run them, each needs its argument registers.

## Where the manual is silent, and what the PROM requires

1. **Word order of a secondary-cache doubleword (inferred).** Figure 14-33 says TagHi carries doubleword bits 63:32
   and TagLo bits 31:0. The routine loads a doubleword `d` from flash (big-endian, first word in the high half) and
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
   not terminate (stopped at the step limit) and the staged lines differ from flash. The manual gives an LRU bit
   in each primary tag (TagLo[3], set in both tags here) without its encoding.
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

For the two paths run, an approximation "cached (algorithm 3) fetches of 0x1fc0xxxx read the flash" returns
byte-identical words to what the real caches would supply: 0 differences in 673,733 fetches, because the routine copies
verbatim flash bytes into the lines it forges and the one hand-built word, `jr $10` at 0x1fc04f10, is also in the
flash image. It is therefore sufficient for those paths, but it does not follow the hardware: on silicon those fetches
never reach the bus, and a store to RAM at the same physical address would not change what runs. The approximation
breaks if RAM is written there, if the caches are flushed, or if a different caller stages different bytes.

Faithful alternative: model the R10000 index operations used here (Index Store/Load Data and Tag for the primary
instruction and secondary caches, 0x08, 0x0b, 0x07, 0x18, 0x1b, 0x1c, 0x1f) with a small array model and the fetch
algorithm above. The simulator is a working reference for it, including the two choices (word order, invalid-first
refill) that a model must make the same way. A model that returns zeroes for the unstaged fetch (RAM contents) shows
the behaviour a hardware capture would show only if the staging is missing.

## Next

Run the six other callers through the simulator before claiming the approximation is byte-exact for the whole PROM.
If one fetches a word that differs from flash, that caller decides between modelling the cache operations and
leaving the approximation. A physical test is not needed to settle this question.
