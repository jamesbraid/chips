# PAL_CACHE_SUMMARY and PAL_CACHE_INFO in PAL_B 5.73

What the SN2 PROM `shub1snprom.bin` (SAL 5.04, flat load at `0xffa00000`) reports for the cache hierarchy, and which inputs the L3 numbers
depend on. Read in the IA-64 Ghidra module (linear listing of the whole image, flow followed by hand). Addresses are image addresses
(for PAL_B 5.73 also run addresses; link address = image address + `0x88000`). Nothing was run.

**Grades.** *established*: instruction, operands and flow read in the image. *inferred*: reasoned from them. *unknown*: not settled.
Field layouts are the Itanium SDM rev 2.3 vol 2 (PAL_CACHE_INFO, figures 11-2 and 11-3, pp. 2:374-2:375).

## 1. The handlers (established)

PAL_B 5.73 has two dispatch routes (the generic dispatcher is in [pal-b-halts.md](pal-b-halts.md)):

- A static table of 24-byte entries at `0xffe9f6e0` (index, PSR mask, zero), ended by -1, with one 8-byte link address per entry at
  `0xffe9fb00` (the entry's position selects the handler). Index 2 is entry 0 and index 4 is entry 2.
- A special path at `0xffe9e5f0` for indexes 3, 0x12, 0x1e, 0x1f, 0x100 to 0x105 and 0x208 (it first finds the PAL_B whose family and model
  bytes at +`0x10114` match `cpuid[3]`), and a path at `0xffe9e380` for indexes 1 and 0x1d.

| Index | Procedure | Handler |
|---|---|---|
| 1 | PAL_CACHE_FLUSH | `0xffe9ff30` (via `0xffe9e3dc`) |
| 2 | PAL_CACHE_INFO | `0xffea0430` |
| 3 | PAL_CACHE_INIT | `0xffea0d30` (special path, link `0xfff28d30`) |
| 4 | PAL_CACHE_SUMMARY | `0xffea1690` |

## 2. PAL_CACHE_SUMMARY (established)

Arguments `r29`, `r30`, `r31` must all be zero, else `r8 = -2`. Returns `r8 = 0`, `cache_levels` (`r9`) = 3, `unique_caches` (`r10`) = 4,
`r11 = 0`. Constants; no MSR, cpuid or table read.

## 3. PAL_CACHE_INFO (established for the code)

`r29` = level, `r30` = type, `r31` must be zero. Accepted: level 0 type 1 (L1I), level 0 type 2 (L1D), level 1 type 2 (L2), level 2 type 2
(L3). Anything else returns `r8 = -2` with zeros. `config_info_1` is `r9` and `config_info_2` is `r10`; `r11 = 0`.

| Field | L1I | L1D | L2 | L3 |
|---|---|---|---|---|
| unified (bit 0) | 0 | 0 | 1 | 1 |
| attributes (bits 2:1) | 3 (a reserved encoding in table 11-67) | 0 write through | 1 write back | 1 write back |
| associativity | 4 | 4 | 8 | computed, section 4 |
| line size (log2) | 6 (64 B) | 6 | 7 (128 B) | 7 (128 B) |
| stride (log2) | 7 | 7 | 7 | 7 |
| store latency | 255 | 3 | 7 | 7 |
| load latency | 1 | 1 | 5 | 14 |
| store hints | 0 | 0 | 2 | 2 |
| load hints | 1 | 1 | 8 | 2 |
| cache size | 16 KB | 16 KB | 256 KB | computed, section 4 |
| alias boundary (log2) | 12 | 12 | 12 | 12 |
| tag LS bit | 12 | 12 | 15 | 18 |
| tag MS bit | 49 | 49 | 49 | 49 |

L1I, L1D and L2 are literal constants loaded with `movl` (`0xffea0466` to `0xffea04d6`), L3 at `0xffea0536`. No cpuid, `msr[1536]`, `msr[1559]`
or record-table access on those paths. The hint values for L2 and L3 set bit 1 of the store hints and bit 1 of the L3 load hints, which
tables 11-68 and 11-69 list as reserved or non-temporal level 1; they are reported as read. The tag LS bits match 256 sets x 128 B x 8 ways
(L2, 15) and 2048 sets x 128 B (L3, 18). The L2, L1 and L3 geometry and the 14-cycle L3 latency agree with the Itanium 2 reference manual
251110-003 (tables 6-4 and 12-4), which is *inferred* support, not the source of the values.

## 4. What the L3 numbers depend on

*Established.* The L3 path (`0xffea0530` to `0xffea07cc`) reads `msr[1536]` once (`0xffea0580`), takes `~msr & 0x0fff000000000000`, shifts
bits 59:48 down, and counts the **clear** bits (a 24-step loop at `0xffea0750` that advances over the 12 bits; each clear bit adds one pair).
Then:

- associativity (`config_info_1` bits 15:8) = 2 x clear bits;
- cache size (`config_info_2` bits 31:0) = 2 x clear bits x `0x40000` = clear bits x 512 KB, i.e. 256 KB per way.

Only the count matters, not which bits are clear. Nothing else enters: no `cpuid[3]`, no `msr[1559]`, no CPU record table (`0xffbe0a10`).
There is no clamp: all 12 bits set gives associativity 0 and size 0 (the SDM reads associativity 0 as fully associative).
A set bit means two ways absent (the reading of bit i skipping ways 2i and 2i+1 in [pal-b-halts.md](pal-b-halts.md) is *inferred*; this
handler is consistent with it).

The PAL cannot report more than 24 ways x 256 KB = 6 MB. A 9 MB part (18 ways of 512 KB, per 251110-003) is outside this geometry.

## 5. Madison 3M

251110-003 table 12-2 gives family 0x1f model 1 for "up to 6 MB", so `cpuid[3]` does not tell a 3 MB part from a 6 MB one, and this PAL
does not ask it to. The manual lists 3 MB as 12 ways (table 6-4 and table 12-4's `0x8d` descriptor, *established* by the manual).

For 12 ways and 3 MB the handler needs exactly six clear and six set bits in `msr[1536]` bits 59:48 (*established*: the handler reports
12 ways, `0x300000`). Which six are set is not constrained by the handler. If the absent ways are the high ones (*inferred*: the
natural way-skip reading), bits 59:54 are set: the 12-bit field is `0xfc0`, `msr[1536] & 0x0fff000000000000 = 0x0fc0000000000000`.
Then `config_info_1` is `0x02020e0707070c03` (associativity 12) and `config_info_2` is `0x0031120c00300000`.
Any other six-bit pattern gives the same numbers. Whether the real part sets the high or the low bits is **unknown**.

Corroboration: PAL_BRAND_INFO (index 274, handler `0xffea0800`) reads the same bits (`0xffea0940`), computes the same size and inserts
`size >> 20` as one ASCII digit into the string "Intel(r) Itanium(r) 2 Processor with NM L3 Cache" (lower-case `r`, no space before `M`; stores at `0xffea0b96` to `0xffea0c80`), so a
three-megabyte configuration prints `3M` (established for the code). A size that is not a whole number of megabytes is truncated (5 clear bits give `2`).

## 6. Other users of `msr[1536]` bits 59:48 (established unless marked)

- **PAL_CACHE_FLUSH** (`0xffe9ff30`): reads them at `0xffe9ffb0` and rebuilds the way count; `progress_indicator` (`r31`) above that count
  returns -2 (`0xffea01ec`). The walk helper entered through `0xffe920d0` reads them again (`0xffe92460`), visits way numbers 0 to 23, and flushes only
  ways whose pair bit is clear, one 256 KB range (`0xffe92bb0`: addresses to `0x3ffc0` in 128-byte steps) each. So it walks 2 x clear bits ways.
- **PAL_CACHE_INIT** (`0xffea0d30`): for level 2 type 3 (and -1, all) the L3 routine at `0xffe89040` reads them (`0xffe890f0`), counts the clear
  bits the same way and initialises 2048 sets per present way (ranges of `0x800` sets from `0xffe89350`), so 2 x clear bits ways. The L1
  routines (`0xffe88120`, `0xffe88670`) and the L2 routine (`0xffe88970`) do not read them.
- PAL_BRAND_INFO reads them (section 5). The other read sites (`0xffe89770`, `0xffe91110`, `0xffe91d70`, `0xffe92da0`, `0xffea44b0`, `0xffef7ee6`)
  are in diagnostic and self-test code listed in [pal-b-halts.md](pal-b-halts.md); their callers were not traced here (**unknown**).
- No constant-numbered `msr` write changes bits 59:48. Three sites rewrite the whole register with other bits edited (`0xffe8a026`, `0xffe9fe90`, `0xffefc038`); computed register numbers were not searched.

## Unknown

- Which bits of `msr[1536]` a real 3 MB part sets (the count is settled, the positions are not).
- Why the L1I attribute field is 3 and the L2/L3 store-hint vectors set a reserved bit (bit 1); the values are reported as read. The L3 load hint (bit 1, non-temporal level 1) is a defined bit.
- Whether PAL_B 7.79 and 1.27/2.25 (other images in the same PROM) report different L3 values: not read.

## Review

Independent re-read of commit 8338515 in Ghidra (`--sn2-prom --no-analysis`, address ranges) and a flat `ia64-linux-gnu-objdump` listing of snprom 10.54, plus SDM rev 2.3 vol 2 (pp. 2:374-2:375) and 251110-003. Nothing was run.

**Confirmed.**
- Handler table at `0xffe9f6e0`: 42 live 24-byte entries ended by -1 at `0xffe9fae8`, links at `0xffe9fb00` minus `0x88000`: index 2 `0xffea0430`, index 4 `0xffea1690`, index 0x112 (274) `0xffea0800`. FLUSH `0xffe9ff30` is reached by a branch at `0xffe9e3dc`; INIT's link `0xfff28d30` is in the movl list at `0xffe9e646`.
- SUMMARY returns 0, 3, 4, 0 for zero r29..r31, else -2 with zeros (`0xffea1690` to `0xffea16cc`). INFO accepts exactly (0,1), (0,2), (1,2), (2,2) with r31 zero.
- All four `config_info_1` and `config_info_2` constants decode against SDM figures 11-2 and 11-3 as the table says (L1I `0x10001ff07060406` / `0x310c0c00004000`, L1D `0x100010307060400`, L2 `0x802050707070803` / `0x310f0c00040000`, L3 base `0x2020e0707071803` / `0x31120c00000000`).
- L3: one `msr[1536]` read at `0xffea0580`, `~msr & 0x0fff000000000000`, bits 59:48 shifted down; the loop at `0xffea0750` runs 24 steps (only the first 12 can be set), each clear bit adds 1 to r17 and 0x40000 to r19, both doubled at `0xffea07a0`, then `dep r2=r17,r2,8,8` and `or r3=r3,r19`. Six clear bits give `0x02020e0707070c03` and `0x0031120c00300000`, as worked.
- FLUSH reads at `0xffe9ffb0` and compares at `0xffea01ec` (r31 above the way count or negative: -2). INIT's L3 routine reads at `0xffe890f0`. The walk helper range limit `0x3ffc0` is at `0xffe92bb0` (262080, 128-byte steps). BRAND_INFO reads at `0xffea0940`.
- SDM layout of both configs, Table 11-67 (attribute 3 reserved), Table 11-68 (store-hint bit 1 reserved) and Table 11-69 (load-hint bit 1 non-temporal level 1).
- All eleven listed `msr[1536]` read sites exist (the register number is loaded at each; `0xffef7ee6` is `0xffef7ee8` in a linear sweep, probably a phase difference, not re-resolved).

**Changed.**
- Brand string: it is "Intel(r) Itanium(r) 2 Processor with 3M L3 Cache" (lower-case `r`, no space before `M`), not `3 M`.
- SDM page range is 2:374-2:375 (2:376 is PAL_CACHE_INIT).
- "No site writes bits 59:48" is weaker than it read: three whole-register write-backs exist; none changes 59:48 (constant numbers only).
- Unknown list: the L3 load hint is not a reserved bit; only the store hints (bit 1) are.
- Table 6-4 in 251110-003 lists the L3 latency as "14 or 12" cycles without saying which configuration, so the manual does not discriminate the PAL's 14; the 12-way 3 MB row is table 12-4 only.

**Not checked.** Which predicate selects each link in the special path at `0xffe9e5f0` (indexes 0x101 and 0x105 are also in the static table); the INIT routine's level and type decode beyond the read at `0xffe890f0`; the set-count loop at `0xffe89350`; the other `msr[1536]` readers' callers.
