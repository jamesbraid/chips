# SN2 node physical address map

How an Altix (SN2) processor, SHub or TIO forms and decodes an address: the node number, the address-space selector, the local and global register windows, memory aliases, I/O windows and the DMA address a bridge sees. Everything is read from SGI's own Linux platform headers and setup code for SN2 (Linux v5.3, `arch/ia64/include/asm/sn/addrs.h` and `arch.h`, plus the setup, I/O and DMA code that uses them). That source is the vendor's software and defines these facts, so they are **established** as definitions of what the kernel computes. What the hardware does with a given address is **inferred** from those definitions and says so. No PROM, SAL image or hardware read is held; see [questions/sn2-address-map-open.md](../../questions/sn2-address-map-open.md) for what that leaves open.

The shape is the same family as the Origin 3000's Bedrock node (a NASID in the high bits, a per-node offset below it), but the field positions, the window offsets and the chip are different; do not carry Bedrock numbers over ([ip35 address map notes](../ip35/nasid-numbering.md) are a separate machine). See [../../devices/shub/README.md](../../devices/shub/README.md) for the chip.

**PROM view.** The SHub 2 first-stage firmware uses the local MMR window (`0x2_0000_0000 + offset`, with bit 63 set for uncached access in physical mode) and, for the fabric accessor, the global window (`0x3_0000_0000`); the SHub 1 firmware uses `0x80_0000_0000 + offset`. `SN_SAL_GET_SN_INFO` in the SHub 2 build computes the NASID width and shift from the register at `0x2_2011_0000`: mask `(1 << (V + 10)) - 1`, shift `40 - V` (read in full; what V is on hardware is unknown): [software/firmware/snprom](../../software/firmware/snprom/README.md).

## What software is told, and what it assumes

The kernel does not hard-code the node number field. It asks firmware once per CPU (SAL call `SN_SAL_GET_SN_INFO`, see [../../software/sal/README.md](../../software/sal/README.md)) and keeps the answer in a small per-CPU record:

| Field | From | Meaning |
|---|---|---|
| shub2 | v0 bits 7:0 | 0 for SHub 1, 1 for SHub 2 |
| nasid mask | v1 bits 15:0 | width of the node number, as a mask, for example 0x7ff for 11 bits |
| nasid shift | v1 bits 23:16 | bit position of the node number's lowest bit. The comment in the header says bits 23:15; the code that takes the field uses bits 23:16 |
| as shift | the kernel | nasid shift minus 2 |
| system size, sharing domain size, region size, coherency id, partition id | v0 | log2 of maximum nodes, log2 of nodes per sharing domain, region size, coherency domain id, partition id |

If the call is not implemented (an old PROM) the kernel falls back to SHub 1 with mask 0x7ff, shift 38, system size 10 (a thousand nodes), sharing domain size 8, and takes the region size from the SHub identification register. Those fallback numbers are the only concrete values for the fields the sources give. Established as the fallback; whether real SHub 1 firmware reports the same is **inferred**. For SHub 2 the sources give no values at all (unknown, see the question page).

## Anatomy of a node address

Below, N is the nasid shift (38 in the fallback), A = N - 2 is the address-space shift.

```
 63 61 60 ...      N+k-1 .. N   N-1 .. A    A-1 ........ 0
+-----+------------+-----------+-----------+-------------+
| rgn |  (zero)    |   NASID   |    AS     | node offset |
+-----+------------+-----------+-----------+-------------+
```

- **Region (bits 63:61).** The IA-64 virtual region. The kernel sees physical memory through region 7 (cached, `PAGE_OFFSET`) and I/O through region 6 (uncached, `__IA64_UNCACHED_OFFSET`, 0xc000...). The same node addresses are used in physical mode with bit 63 set for uncached access; the kernel's TLB-purge code does this, and the register stores it makes through `GLOBAL_PHYS_MMR_SPACE` carry region 4's base (bit 63 set) as the physical uncached attribute. The region bits are cleared when the kernel converts a virtual address to physical (`TO_PHYS_MASK`).
- **NASID.** Node number. Even NASIDs are SHubs (processor and memory nodes); odd NASIDs are TIOs. The macro `IS_TIO_NASID` tests bit 0, and the header says so ("low NASID bit is 0: memory and SHub MMRs; low bit 1: TIO"). Memory-less or processor-less SHubs exist ("headless nodes") and get compact node numbers after the populated ones. The maximum node number is 16383 (`MAX_NUMALINK_NODES` 16384, the TIO DMA format has 14 bits of it); the fallback mask is 11 bits wide.
- **AS (2 bits at A).** Address-space selector, used when the NASID is a SHub's. Same values on both chips:

  | AS | Name | Kernel macro | Meaning |
  |---|---|---|---|
  | 0 | local resources and MMR | none | registers and special spaces; see below |
  | 1 | GET | `AS_GET_SPACE` | the header calls it "GET space"; no use in the kernel files read, role unknown |
  | 2 | AMO | `AS_AMO_SPACE` | atomic memory operations (fetch-and-op, "fetchop"); used by the special memory driver and the cross-partition code; encoding below |
  | 3 | cacheable memory | `AS_CAC_SPACE` | ordinary cached memory |

  The cached kernel mapping is `PAGE_OFFSET | AS_CAC_SPACE | physical`; the AMO mapping is `uncached | AS_AMO_SPACE | physical`. So the physical address the processor emits for ordinary memory has AS = 3, and the kernel's "physical address" for the same byte has AS = 0 (`TO_PHYS` removes both region and AS bits). This is how three different views of one byte of memory are selected; whether AS = 1 and 2 reach the same DRAM line through different controllers is inferred from the names.
- **Node offset (A bits).** Byte offset in the node: 64 GiB with the fallback shift. The same offset is used to index memory, AMO, GET and (in the local resources space) registers.

### AMO space (AS = 2)

Each atomic variable takes a 64-byte line of which the first eight bytes are the variable; the remaining address bits select the operation (kernel header for the special-memory driver). The offsets and macro names are established as the encodings the kernel issues; the operation column is **inferred** from the macro names (the header comment describes only the variable layout):

| Access | Offset added to the address | Operation |
|---|---|---|
| load | 0 / 8 / 16 / 24 | read, read and increment, read and decrement, read and clear |
| store | 0 / 24 / 32 | write, AND into the variable, OR into the variable |
| store | 56 | clear the cached copy (named `FETCHOP_CLEAR_CACHE` in the header) |

The same cache line is also reachable cached, through AS = 3. The header warns that a line used for AMO variables must not hold anything else: if the cached alias is modified and written back it overwrites the uncached value. On SHub 2 the kernel clears the SHub's AMO cache by loading four lines from a scratch page through AMO space before it zero-fills memory with the block transfer engine (`SH2_AMO_CACHE_ENTRIES` 4); SHub 1 does not.

### AS = 0: local resources, MMRs and compatibility

The header comment describes AS = 0 as "local resources and MMR space": if the top bit of the node offset is clear it is local resources space, and there the node-number field is reinterpreted as a space id: **0** the IA-64 and NT compatibility space, **2** the local MMR space, **4** local memory regardless of the local node's id. If the top bit of the node offset is set it is global MMR space. The constants agree with that reading for SHub 1 and the fallback shift:

| Constant | SHub 1 | SHub 2 |
|---|---|---|
| `LOCAL_MMR_OFFSET` | 0x80_0000_0000 (node field value 2 at shift 38) | 0x2_0000_0000 |
| `GLOBAL_MMR_OFFSET` | 0x8_0000_0000 (top bit of a 36-bit node offset) | 0x3_0000_0000 |

For SHub 2 the constants sit well below any plausible NASID field, so the node-field reading does not apply; how SHub 2 splits local and global MMR is **unknown** without its shift value. The kernel forms register addresses as:

- local: `uncached | LOCAL_MMR_OFFSET | register` (used for the real-time clock, event register and LEDs, where "this node's" copy is wanted)
- global, on a given node: `uncached | GLOBAL_MMR_OFFSET | (nasid << N) | register`
- global, physical mode: the same with bit 63 set in place of the region
- remote SHub 1 with a register offset that does not have bit 32 set (the II block, 0x400000 and up): small window 1 plus 0x800000, i.e. `global node base + 0x1000000 + 0x800000 + register`, which puts the II registers 0x1c00000 into a node's global window; offsets with bit 32 set (processor interface, memory/directory, local block, the clock, purge and IPI registers, all of SHub 1's non-II MMRs) go to `global node base + register` directly. Header comment: "non-II MMRs start at the top of the big window space (4 GiB)".

For TIOs the macros differ: on SHub 1 TIO register addresses use the same global form; on SHub 2 they are `uncached | (nasid << N) | register | (1 << A)`, i.e. with the lowest AS bit set (**inferred**: the header calls the two AS bits of a TIO address a chiplet id, 0 for the TIO local block and 1 for the "ICE"; TIO pages are the I/O stream's).

## I/O windows (SHub 1)

A node's global window also carries the I/O space (all in `global node base`, which is `uncached | GLOBAL_MMR_OFFSET | NASID << N`):

| Window | Size | Where | Notes |
|---|---|---|---|
| Small windows | 16 MiB each (`SWIN_SIZE_BITS` 24) | base + widget << 24, widget 0 to 15 | one per Crosstalk widget; widget number mask 0xf |
| Big windows | 512 MiB each (`BWIN_SIZE_BITS` 29) | base + 512 MiB + window << 29 | seven translation entries in the II map them; window number is three bits |
| Small window 0 | 16 MiB | stands in via the top big window | the kernel treats `HUB_NUM_BIG_WINDOW` (6) as the surrogate for small window 0, to work around a processor-interface defect (header comment) |

The II translation table (see [../../devices/shub_ii/README.md](../../devices/shub_ii/README.md)) maps each big window to a 48-bit Crosstalk address: the header text says five offset bits are joined to the 29 window-relative bits, so a big window reaches 16 GiB of a widget in the header's M-mode figure (the same comment gives 8 GiB for N-mode: 28 bits plus five, plus an I/O space bit; which mode applies to the fallback layout is unknown), of which only a fraction is addressable. A bridge's registers are in its widget's small window; the PROM hands the kernel the ready-made base (`bs_base` in the bus record) and the kernel does not compute it.

## TIO address space (the SHub 2 formula; SHub 1 TIO uses the global form above)

| Constant | Value | Meaning |
|---|---|---|
| `TIO_IO_BASE(n)` | `uncached | n << N` | base of a TIO's address space |
| `TIO_SWIN_SIZE_BITS` | 28 | small windows are 256 MiB |
| `TIO_SWIN_WIDGET_MASK` | 3 | four small windows, widgets 0 to 3 |
| `TIO_BWIN_SIZE_BITS` | 30 | big windows are 1 GiB |
| `TIO_BWIN_WINDOW_SELECT_MASK` | 7 | window number, three bits |
| `TIO_HWIN_SHIFT_BITS` | 33 | selector for "H windows": `node offset >> 33` |
| Coretalk address | nasid at bit 40 (mask 0x3fff), chiplet id at bit 38 (mask 3), node offset below bit 38 (mask 0x3fffffffff) | address format as seen by a TIO's core |

The header says a TIO address has its top node offset bit set and a two-bit chiplet id in place of AS: 0 for the TIO local block (MMR access), 1 for the "ICE" chiplet (coretalk access). TIO internals belong to the TIO device pages, written separately.

## DMA addresses seen by bridges

PIC (the PCI-X bridge reached through SHub) gets a 64-bit crosstalk address from `PHYS_TO_DMA`: remove the region and AS bits, keep the offset, and move the node number down two bits (`((x & NASID_MASK) >> 2) | NODE_OFFSET(x)`), so the node number occupies bits N-2 upward in the DMA address, the position the AS bits held in the processor address.

TIOCP, TIOCA and TIOCE get `PHYS_TO_TIODMA`, which differs by chip:

- SHub 1: `(nasid << 40) | node offset`. Established.
- SHub 2: `(nasid << 40) | network address`, where the network address keeps the low N-4 bits of the physical address and moves the next two bits (the "bank" select) up to bits 37:36. Established as the macro; the meaning of the bank bits is **unknown**.

The block transfer engine's source, destination and notification address have the AS bits cleared before being written, and on SHub 2 pass through the TIO conversion above.

## Memory and the physical address handed to the kernel

Firmware describes node memory to the kernel through the standard EFI memory map and ACPI tables (SRAT proximity domains): the kernel maps proximity domain to NASID with `pxm_to_nasid`. The physical addresses in these tables are node addresses without region or AS bits, as the kernel's `TO_PHYS` defines. How much memory per node and how the PROM lays it out inside the 64 GiB offset (hole sizes, interleave) is not in the code read; **unknown** (see the question page).

## Simulator and legacy I/O (informational)

- Legacy VGA ports and the PCI legacy I/O window are mapped by firmware; the kernel gets the base from the bus record (`bs_legacy_io`, `bs_legacy_mem`) and ORs in the uncached region. On SN2, ports below 64 KiB other than the VGA ranges point at nothing.
- Under the SGI simulator the kernel maps legacy ports at `0xc0000087cc000000` (SHub 1) or `0xc00000028c000000` (SHub 2) ORed with the port number with its low two bits dropped and shifted left 12 (the IDE ports 0x1f0 to 0x1f7, 0x3f6 and 0x3f7 also get the port number ORed in). Simulator-only; recorded for completeness.

## Established versus inferred, in one list

- Established: the AS values and names; the field shift relation `AS shift = NASID shift - 2`; the local and global MMR offsets for both chips; the window sizes; the DMA conversion macros; the fallback field values.
- Inferred: the node-field reading of AS = 0 on SHub 1; what AS 1 (GET) is; why the II lands at 0x1c00000; the TIO AS-bit reading on SHub 2.
- Unknown: the SHub 2 nasid shift and mask; how SHub 2 splits local and global MMR; the memory layout inside a node's offset.

## Review

Independent review of this page at chips commit 788b7be against Linux v5.3 `addrs.h`, `arch.h`, `shubio.h`, the SN2 setup, BTE, I/O and driver code that uses them, and `mspec.c`. The reviewer did not write the page.

**Checked, every formula.**
- Field relation `AS shift = NASID shift - 2`, the 2-bit AS mask, AS values 1, 2 and 3 and their macros, `TO_PHYS_MASK`, `CAC_BASE`, `AMO_BASE`, `IS_TIO_NASID` (bit 0), `NODE_OFFSET` and the 64 GiB size at shift 38.
- `SH1_LOCAL_MMR_OFFSET` 0x80_0000_0000, `SH2_LOCAL_MMR_OFFSET` 0x2_0000_0000, `SH1_GLOBAL_MMR_OFFSET` 0x8_0000_0000, `SH2_GLOBAL_MMR_OFFSET` 0x3_0000_0000, the uncached region and the region 4 (bit 63) base for physical mode. All exact. The "node field value 2 at shift 38" and "top bit of a 36-bit offset" readings of the SHub 1 values are arithmetic-consistent and graded inferred.
- Register address macros: local, global, global physical, the `SH1_IS_BIG_WINDOW_ADDR` split on bit 32, small window 1 plus 0x800000 for II offsets, direct global for offsets with bit 32 set, and the SHub 2 TIO form with `1 << (NASID_SHIFT - 2)`.
- The 0x1c00000 arithmetic: small window 1 is global base plus (1 << 24); plus 0x800000; plus the II block start 0x400000 = 0x1c00000. Correct. (The phrase "puts the II registers 0x1c00000 into a window" means the block starts there; register N sits at 0x1800000 + N.)
- Window sizes and masks: small windows 24 bits, widget mask 0xf; big windows 29 bits, window mask 0x7; `NODE_BWIN_BASE0` = global base plus 512 MiB; TIO small windows 28 bits, mask 3; TIO big windows 30 bits, mask 7; `TIO_HWIN_SHIFT_BITS` 33; coretalk nasid at 40 (mask 0x3fff), chiplet at 38, offset mask 0x3fffffffff; seven translation entries and the big window 6 stand-in for small window 0.
- DMA formulas: `PHYS_TO_DMA`, `SH1_TIO_PHYS_TO_DMA`, `SH2_TIO_PHYS_TO_DMA` with the N-4 bit offset and the two bank bits moved to 37:36; the BTE source and destination conversion.
- AMO encodings (load 0/8/16/24, store 0/24/32, cache clear 56, 64-byte variables), the SHub 2 four-line AMO cache flush (in `mspec_zero_block`, before a zero-fill BTE copy), the `SN_SAL_GET_SN_INFO` bit positions and the header comment's 23:15 versus the code's 23:16, the fallback values (mask 0x7ff, shift 38, size 10, sharing 8, coherency = NASID >> 9), and the two simulator I/O bases and port formula.

**Grades.** Constants, macros and formulas are established as definitions, as stated; hardware meaning is marked inferred. No fact is graded above what the source defines, with the exceptions below.

**Findings (judgement or wording, not changed).**
1. The AMO table is headed "established as the encodings the kernel issues". The offsets and the macro names are established; the operation meanings (increment, decrement, clear, AND, OR, clear cached copy) are read from the macro names and the header comment's description and should be graded inferred.
2. The big window reach "16 GiB of a widget" is the header's M-mode figure (five offset bits plus 29). The same header comment gives an N-mode figure of 8 GiB (28 bits plus five, plus an I/O space bit). The page does not say which mode applies to the fallback layout.
3. The DSDT OEM revision threshold 0x20101 is in `acpi.h`. The code that fills `sn_acpi_rev` from the table was not found in the files fetched; the "decided by the DSDT's OEM revision" statement (on the SAL page) is therefore plausible but not verified here.
4. The page quotes two header comment fragments (the "low NASID bit is 0" line and the local-memory space id); both are short and attributed, no longer passages are copied.

**Cleared:** every address macro, constant and formula listed above (all were read against the source), and the inferred 0x1c00000 arithmetic. **Not cleared:** the node-field reading of AS = 0 on SHub 1 (inferred, no second source), the meaning of GET space and of the TIO chiplet ids (inferred from names), any SHub 2 NASID shift (unknown, correctly), and the memory layout inside a node (unknown).

Findings 1-8 addressed in the commit "docs: address the SN2 SHub review findings"; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Sources were fetched as single files from Linux v5.3 into scratch and compared with the changed text. 

**Checked.**
- AMO table: the offsets and names (`FETCHOP_LOAD` 0, `_INCREMENT` 8, `_DECREMENT` 16, `_CLEAR` 24, `_STORE` 0, `_AND` 24, `_OR` 32, `_CLEAR_CACHE` 56) are in `mspec.h`; that header's comment describes only the 64-byte variable layout and the aliasing hazard, not the operations. The operation column is therefore inferred from the names alone. The page said "and the header comment's description"; corrected (mechanical).
- Big window reach: the translation-table comment in `shubio.h` gives 16 GiB per widget for M-mode (five offset bits with SysAD[28:0]) and, for N-mode, five bits with SysAD[27:0] plus the IOSP bit as Crosstalk[47], 8 GiB. The page's wording matches.

**Findings.** One mechanical wording fix, made. **Cleared:** findings 1 and 2 of the first review as now worded. **Not cleared:** as before (finding 3, the AS = 0 node-field reading, GET space, SHub 2 NASID shift).
