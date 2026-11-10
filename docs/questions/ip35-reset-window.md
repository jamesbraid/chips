# IP35 reset window: how the boot PROM runs at 0x1fc0_0000, and when it stops

Question. On an IP35 (SN1, Bedrock) board, processor accesses to the reset address 0x1fc0_0000 reach the boot
PROM although RAM lives at the same physical address once memory is enabled. What does the shipped PROM do
around enabling memory, which address spaces does it execute from at each stage, and does it leave the window
before or after bank 0 is enabled?

Method: disassembly of the shipped IP35 PROM image (SGI Version 6.210, built Aug 26 2004; container segment
`ip35prom`, load and entry 0xc00000001fc00000, length 0x1686a8, additive checksum ok) and, as a contrast, the
shipped IP27 PROM image (SGI Version 6.156, built Nov 18 2003). Addresses below are image addresses: the link
address is 0xc00000001fc0xxxx and the same bytes sit at physical 0x1fc0xxxx. Constants were folded by hand and
by a small straight-line tracker over the whole listing; nothing was run.

Sources outside the binaries: Origin200/2000 IP27 PROM Technical Reference Manual, document 108-0170-001 (boot
sequence, pp. 2-4 to 2-6; progress LED table, pp. 3-2 to 3-4; Dex mode, p. 3-7); MIPS R10000 Microprocessor
User's Manual, version 2.0 (October 10, 1996), section 14.27 and Table 14-27 (CACHE op encodings), sections
10.19 to 10.22 (index store tag and data); NEC VR10000/VR12000 User's Manual U10278EJ4V0UM, revision 4, section
6.23 (uncached attribute on SysAD[59:58], taken from VA[58:57] for unmapped accesses) and the compatibility
segment and reset-vector sections.

## Answer

1. **Established.** Before memory exists the PROM fetches instructions from three places: KSEG1
   (0xffffffffbfc0xxxx, the reset vector and the TLB helpers), a mapped uncached window
   (VA 0xc00000001fc00000, TLB entry 62, physical 0x1fc00000, uncached attribute field 0), and cached
   xkphys aliases (0x98000000_1fc0xxxx, cache algorithm 3) of code it has first staged into the CPU caches
   with CACHE index operations. It never jumps to the LBOOT base alias (0x9000000018000000) for execution;
   that address is only the source of the data copy.
2. **Established.** The PROM does not copy itself before enabling bank 0. The sequence in the main
   routine is: memory configuration and test (the call at 0x1fc6a8a0), the console line "Copying PROM code to
   memory" (0x1fc6a974), the copy and checksum (call at 0x1fc6a990), then the jump to RAM (call at
   0x1fc6a9e4, LED 0x3c). The copy source is 0x9000000018000000 (local boot space, uncached attribute 0)
   or, on a node that is not the boot node, 0x9000000038000000 plus the node number shifted left 33 bits;
   the destination is 0x9600000001a00000 (uncached attribute 3, node-local) and the length is
   0x1fd686a8 - 0x1fc00000 = 0x1686a8.
3. **Established.** The PROM stops executing its main text out of the 0x1fc0_0000 window at the jump to RAM
   (LED 0x3c "About to jump to UALIAS space", then 0x3e "jump to cached space"). That is the transfer the
   manual calls "Transfer program counter to uncached RAM" and "to cached RAM". It happens after the memory
   configuration writes and after the copy.
4. **Established (code and ordering), inferred (RAM coverage).** The PROM does not stop touching the window at that point. Each TLB-writing
   routine hops to the KSEG1 alias of its own address before it executes `tlbwi`. The three routines that
   install the RAM mappings, and the shared writer, therefore fetch instructions from KSEG1 at physical
   0x1fc05b58, 0x1fc05d0c, 0x1fc05d88 and 0x1fc05e04, after the memory configuration writes and after the copy.
   The copy destination 0x01a00000 must be RAM, and the image carries a message rejecting 256 MB banks
   (referenced at 0x1fc51924), so the bank that holds 0x01a00000 is at least 512 MB and also covers 0x1fc05xxx. For the PROM to work, a KSEG1 (uncached, attribute 3 by the processor
   manuals) instruction fetch of physical 0x1fc05xxx must return PROM bytes, not RAM, with bank 0 enabled.
5. **Inferred.** The routing rule real hardware uses for point 4 is not visible in the PROM. Candidates:
   uncached memory-space (attribute 3) reads of a boot window are served by the boot flash regardless of
   RAM; or reads of that address range are served by flash whatever the attribute. The PROM does not
   distinguish them: it never reads 0x1fc0xxxx through an attribute-3 xkphys address (0x96...) once RAM is on.
6. **Inferred.** The cached (cache algorithm 3) fetches the PROM makes at 0x98000000_1fc0xxxx are meant to
   hit CPU cache lines the PROM forged, not to reach flash or RAM. A cached read request carries no
   attribute (NEC manual), so the bus could only decide by address. The forged secondary-cache line
   contains the word 0x01400008 (`jr $10`) at the trampoline slot, and the flash holds the same word at
   0x1fc04f10, so a flash-served and a cache-served fetch return identical instructions.
7. **Unknown.** What stops the KSEG1 routing, if anything. No write in the reset path or in the memory
   transition looks like a boot-window disable. Nothing in the PROM shows an end condition; the TLB writer is
   reachable for the PROM's whole run (call sites listed below).
8. **Unknown.** Whether an attribute-3 read of 0x1fc0xxxx outside what the PROM does (for example by the
   operating system) sees flash or RAM on silicon.

## Stages in order (IP35 PROM 6.210)

LED values are written as 8-byte stores to 0x9200000001000108 plus 8 times the low bit of the 8-byte value read
from 0x9200000001000020 (an uncached attribute-1 address; the register names are not given by the binary).
The values match the progress table in manual 108-0170-001 (Table 3-1), which is how the stages are named.

| Stage | Image address | Fetch space | Label |
| --- | --- | --- | --- |
| Reset vector `j 0x1fc00400` | 0x1fc00000 | KSEG1 (reset vector 0xffffffffbfc00000 per the processor manual) | established |
| Status written, old Status parked in LLAddr; LED 0x5e | 0x1fc00408 to 0x1fc00454 | KSEG1 | established |
| Test of the parked Status bits 20:19 (selects the cold path at 0x1fc00644) | 0x1fc00458 to 0x1fc00464 | KSEG1 | established |
| Cold path: word at 0x9000000018000064 loaded into Config (`mtc0` at 0x1fc006ac); low 16 bits and bits 24:16 compared with the Config read-back | 0x1fc006a8 to 0x1fc006f4 | KSEG1; data read is xkphys uncached attribute 0 at LBOOT + 0x64 | established |
| LED 0x03 (manual: RUNTLB, switch to mapped mode), then `jal 0x1fc05c54` | 0x1fc0094c, 0x1fc00990 | KSEG1 | established |
| TLB cleared (64 entries), entry 62 written, return through the mapped alias | 0x1fc05c28 to 0x1fc05cd8 | hop to KSEG1 at 0x1fc05c80, then mapped uncached VA 0xc00000001fc0xxxx | established |
| LED 0x0e/0x0f (SPEEDUP/SPEEDUPOK): read 0x92000000017a0008, merge words read from 0x900000001800008c and 0x900000001800009c, write back | 0x1fc00b40 to 0x1fc00b98 | mapped uncached window | established (the access); inferred (flash access-time register) |
| Cache tests and invalidates; cache routines at 0x1fc027cc, 0x1fc03464 and 0x1fc036b0 use the cache-staging routine (below) | 0x1fc00c88 to 0x1fc01098; 0x1fc027cc | mapped window, plus cached xkphys aliases of 0x1fc027f4 etc. | established |
| LED 0x2a (MAKESTACK), call to the main routine `0x1fc698dc` (LED 0x2b) | 0x1fc010d8, 0x1fc011d8 | mapped window | established |
| Memory initialise (`0x1fc6587c`), per-bank config updates, "DONE" | call at 0x1fc6a8a0 | mapped window | established |
| "Copying PROM code to memory", copy (`0x1fc65204`, copy loop `0x1fc05910`), verify (`0x1fc059d0`), checksum | 0x1fc6a974, 0x1fc6a990 | mapped window; copy loop and verify loop run from cache lines staged by `0x1fc04980` | established (code); inferred (cache-resident) |
| LED 0x3c, `jal 0x1fc05ce0`: KSEG1 hop at 0x1fc05d0c, entry 61 written, return through the mapped alias | 0x1fc6a9e0, 0x1fc6a9e4 | KSEG1 fetch at 0x1fc05d0c with bank 0 on; afterwards RAM copy via entry 61 | established |
| `sw $0,0` to 0xc00000001fd686a8, the word after the image | 0x1fc6aa7c | VA now backed by the RAM copy (flash cannot take the store) | inferred |
| Cached jump: entry 60 (`0x1fc05d5c`, call site 0x1fc607f4), KSEG1 hop at 0x1fc05d88 | | KSEG1 fetch, bank 0 on | established |
| Node-qualified cached entry 59 (`0x1fc05dd8`, call sites 0x1fc052b4 and 0x1fc613ec), KSEG1 hop at 0x1fc05e04 | | KSEG1 fetch, bank 0 on | established |

## TLB entries the PROM installs (all with page mask 0x1fe000, 1 MiB pages, two pages per entry)

EntryLo decoding: physical frame is EntryLo bits 29:6; cache algorithm is bits 5:3; dirty bit 2; valid bit 1;
bits 63:62 are the uncached attribute (R10000 family; NEC manual 6.23).

| Entry | ASID | VA | EntryLo0 / EntryLo1 | Physical, algorithm, attribute | Writer |
| --- | --- | --- | --- | --- | --- |
| 62 | 1 | 0xc00000001fc00000 | 0x7f0012 / 0x7f4012 | 0x1fc00000 and 0x1fd00000, algorithm 2 (uncached), read-only, attribute 0 | 0x1fc05cb8 |
| 61 | 2 | 0xc00000001fc00000 | 0x68016 / 0x6c016 | 0x01a00000 and 0x01b00000, algorithm 2, writable, attribute 0 | 0x1fc05d34 |
| 60 | 3 | 0xc00000001fc00000 | 0x6802e / 0x6c02e | 0x01a00000 and 0x01b00000, algorithm 5 (cached), writable | 0x1fc05db0 |
| 59 | 4 | 0xc00000001fc00000 | (0x1a00000 or node<<33)>>6 \| 0x2e, and 0x1b00000 likewise | node-local 0x01a00000 and 0x01b00000, algorithm 5 | 0x1fc05e48 |

Label: established for the constants and the write order. Which ASID is current when the PROM returns from each
helper is inferred: the helper writes EntryHi with the new ASID and never restores it, and the jump LEDs
(0x3c, 0x3e) and the manual's step list agree. The attribute-0 mapping of RAM at 0x01a00000 (entry 61) is
what the manual's LED table calls UALIAS space.

## KSEG1 hops (instruction fetches from physical 0x1fc0xxxx through 0xffffffffbfc0xxxx)

Each helper builds `0xc00000001fc0xxxx | 0xffffffffa0000000`, jumps there, runs the privileged sequence, then
masks the return address and ORs 0xc000000000000000 to return into the mapped window. Established.

| Helper | Hop target | Does |
| --- | --- | --- |
| 0x1fc05b30 | 0x1fc05b58 | EntryHi/Lo0/Lo1, Index, `tlbwi` at 0x1fc05b74 |
| 0x1fc05b80 | 0x1fc05ba8 | `tlbr` |
| 0x1fc05bc4 | 0x1fc05bec | `tlbr`, read EntryLo |
| 0x1fc05c54 | 0x1fc05c80 | clear TLB, install entry 62 (before memory) |
| 0x1fc05ce0 | 0x1fc05d0c | entry 61 (after memory and copy) |
| 0x1fc05d5c | 0x1fc05d88 | entry 60 |
| 0x1fc05dd8 | 0x1fc05e04 | entry 59 |

The routine at 0x1fc05e70 returns its argument with 0xffffffffa0000000 ORed in when the current ASID is 1: the
PROM treats ASID 1 as "running from the PROM window".

## Cache-staging routine at 0x1fc04980

Callers: 0x1fc027e8, 0x1fc03490, 0x1fc036dc, 0x1fc0394c, 0x1fc05950 (copy), 0x1fc05a14 (verify), 0x1fc368bc,
0x1fc36fbc. Arguments: `$4` end of the code to stage, `$31` return address. Established from the code and
Table 14-27: it reads the code from [`$31` & ~63, `$4`) in 8-byte pieces through the mapped window, zeroes and then
fills secondary-cache data with `cache 0x1f` (Index Store Data S), writes secondary tags with `cache 0x0b`, forces
an instruction-cache refill by `jalr $10,$7` to the xkphys cache-algorithm-3 alias of a staging line (0x98000000_1fc04f10),
reads the predecoded words back with `cache 0x18` (Index Load Data I), stores them into the target lines with
`cache 0x1c` (Index Store Data I) and tags the lines valid with `cache 0x08` (Index Store Tag I), the tag being
the physical address taken from the xkphys alias. It then returns with `$31` rewritten to the 0x98... alias, so
the caller continues from instruction-cache lines whose tags say physical 0x1fc0xxxx. It reads seven
doublewords from the table at 0x1fc04fd0 to 0x1fc05000 through the mapped window to build check bits.

- **Established:** the sequence of cache operations and that the target addresses are 0x98000000_1fc0xxxx.
- **Established:** the staging slot at 0x1fc04f10 holds `jr $10` in the flash image, and the routine stores the
  same word (0x01400008, built at 0x1fc04ad4 to 0x1fc04ae8) into the secondary cache at offset 16 of its
  staging line (`cache 0x1f,16($7)` at 0x1fc04af4).
- **Inferred:** because of the above, the fetch at 0x98000000_1fc04f10 is satisfied by the staged line and no
  bus read of 0x1fc04f10 is needed. Not run; the tag and state encodings were not simulated.
- **Inferred:** the stated reason is speed. Manual p. 3-7: Dex mode is slow because PROM instruction fetches
  are slow.

## Memory configuration writes

- **Established:** the PROM addresses the memory-directory register block through a table in its data
  segment: base 0x9200000001f80000 plus the node number shifted left 33 bits, register at offset 8
  (that is, offset 0x780008 of the local block; the local alias 0x9200000001780008 is read at 0x1fc6b21c
  for the failure message "memory_init_all failed: Unuseable bank 0: mc 0x%lx").
- **Established (writers found):** 0x1fc54f14 (`sd $1,8($2)` after clearing one bank's bit and setting bits
  63:56 to 0x07; caller loop at 0x1fc65638) and 0x1fc56e28 (`sd $9,8($10)` after replacing bits 33:32 and
  setting 0x07 in bits 63:56; called at 0x1fc65aa4, 0x1fc65b38, 0x1fc65b4c).
- **Unknown:** the complete sequence of writes that enables bank 0 was not reconstructed statically; other
  writers go through further helpers (0x1fc55b34, 0x1fc5573c, 0x1fc55180, 0x1fc578ec) that were not read to the end.
- **Established:** the PROM refuses a 256 MB bank ("256 MB dimm bank not supported on IP27 node boards.", test at
  0x1fc51924), so bank 0 is at least 512 MB and covers physical 0x01a00000 and 0x1fc00000.

## Registers written in the reset path that were checked for a window control

None of these is shown to be a boot-window or PROM-enable control. All are unknown in meaning unless noted.

| Address (local alias) | Access | Site | Label |
| --- | --- | --- | --- |
| 0x9200000001000028 | 8-byte store of 1 | 0x1fc009ac, just after the first TLB install | unknown |
| 0x9200000001608008 | store of all ones, then zero | 0x1fc007d4, 0x1fc007ec | unknown |
| 0x9200000001608010 | read-modify-write: low 12 bits set to 7 | 0x1fc00804 to 0x1fc00828 | unknown |
| 0x9200000001000420 | read, compared | 0x1fc00840 | unknown |
| 0x92000000017a0008 | read, merge with flash-config words, write | 0x1fc00b40 to 0x1fc00b98 | inferred: PROM access timing (LED 0x0e/0x0f bracket it) |
| 0x9200000001790000, 8, 0x10, 0x18 | stores of zero | 0x1fc00480 (0x10); 0x1fc699c4 to 0x1fc699e4; 0x1fc6a888 (0x18) | unknown |
| 0x9200000001400150 | read, write back same value | 0x1fc69978, 0x1fc69980 | unknown |

## Contrast: IP27 PROM 6.156 (public-lineage Hub machines)

Same structure, established from the listing:

- reset vector `j 0x1fc00800` at 0x1fc00000; same LED-store idiom at 0x9200000001000108 and 0x1fc0084c (value 0x5e);
- same TLB writer with a KSEG1 hop (0x1fc057f0, hop target 0x1fc05818, `tlbwi` at 0x1fc05834), the same
  clear loop at 0x1fc058e0, and the same four entries: 62 with 0x7f0012/0x7f4012 (0x1fc05978), 61 with
  0x68016/0x6c016 (0x1fc059f4), 60 with 0x6802e/0x6c02e (0x1fc05a70), 59 with the node-qualified value (0x1fc05b08);
  each installing routine hops to KSEG1 first (0x1fc059cc, 0x1fc05a48, 0x1fc05ac4);
- same cache-staging idiom (46 `cache 0x1c` and 51 `cache 0x08` sites against 97 and 100 in the IP35 image);
- download routine at 0x1fc5573c: source 0x9000000010000000 (local) or 0x9000000030000000 plus node<<32
  (remote), destination 0x9600000001a00000, with the "Copy PROM", "Verifying copy" and checksum strings at
  0x1fc557e0, 0x1fc55814, 0x1fc5588c. Table values read from the data segment.

The manual (108-0170-001, pp. 2-4 to 2-6) gives the same order for this Hub PROM: configure local memory (15),
memory tests (16), download PROM to memory (17), transfer PC to uncached RAM (18), cached RAM (22). It also
states that the PROM runs out of the data cache with instruction fetches slow until step 18. So the IP35 PROM
(a later build of the same lineage) keeps this order.

Difference worth keeping: the IP27 image has the same KSEG1 hops after step 17, so the KSEG1-to-flash
requirement is not new with Bedrock. The IP35 values (local boot at +0x18000000, 128 MB; node-qualified boot at
+0x38000000) differ from the IP27 values (+0x10000000, +0x30000000) in the copy source only.

## Not settled and the next step

1. The routing rule behind point 4 (attribute only, or address range). Next: no further static route
   distinguishes them, because the PROM never reads 0x1fc0xxxx through an attribute-3 xkphys alias after RAM
   is on. A hardware observation would: with bank 0 enabled, write a marker to RAM through 0x96000000_1fc00040
   and read both 0x96000000_1fc00040 and 0xbfc00040; flash bytes from one and the marker from the other
   settles it.
2. **Answered** in [ip35-prom-cache-staging.md](ip35-prom-cache-staging.md): the routine was run against an R10000 cache
   model (`retools/tools/chips/cache_stage_sim.py`, PROM bytes only). The fetch at 0x98000000_1fc04f10 misses the primary
   instruction cache, hits the secondary line the routine staged and is refilled from it, with no system-interface read, under the
   page's stated word-order assumption for secondary-cache doublewords (the manual does not settle that order; the page
   lists what changes if it is swapped). Point 6 above stays "inferred" for the same reason.
3. The full ordered list of memory configuration writes up to bank 0 enable (needs the remaining helpers read).
