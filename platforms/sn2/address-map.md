# SN2 node physical address map

How an Altix (SN2) processor, SHub or TIO forms and decodes an address: the node number, the address-space selector, the local and global register windows, memory aliases, I/O windows and the DMA address a bridge sees. Everything is read from SGI's own Linux platform headers and setup code for SN2 (Linux v5.3, `arch/ia64/include/asm/sn/addrs.h` and `arch.h`, plus the setup, I/O and DMA code that uses them). That source is the vendor's software and defines these facts, so they are **established** as definitions of what the kernel computes. What the hardware does with a given address is **inferred** from those definitions and says so. No PROM, SAL image or hardware read is held; see [questions/sn2-address-map-open.md](../../questions/sn2-address-map-open.md) for what that leaves open.

The shape is the same family as the Origin 3000's Bedrock node (a NASID in the high bits, a per-node offset below it), but the field positions, the window offsets and the chip are different; do not carry Bedrock numbers over ([ip35 address map notes](../ip35/nasid-numbering.md) are a separate machine). See [../../devices/shub/README.md](../../devices/shub/README.md) for the chip.

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

Each atomic variable takes a 64-byte line of which the first eight bytes are the variable; the remaining address bits select the operation (kernel header for the special-memory driver). Established as the encodings the kernel issues:

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

The II translation table (see [../../devices/shub_ii/README.md](../../devices/shub_ii/README.md)) maps each big window to a 48-bit Crosstalk address: the header text says five offset bits are joined to the 29 window-relative bits, so a big window reaches 16 GiB of a widget, of which only a fraction is addressable. A bridge's registers are in its widget's small window; the PROM hands the kernel the ready-made base (`bs_base` in the bus record) and the kernel does not compute it.

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
