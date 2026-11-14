# Mapped uncached accesses, the region-present register and the memory configuration word: what the manuals, the PROMs and IRIX show about address decode

Questions answered, for the Origin 2000/Onyx2 node controller (Hub, IP27) and the Origin 300/3000 node controller (Bedrock,
IP35):

2. For a TLB-mapped page with an uncached cache algorithm, where does the R10000's 2-bit uncached attribute come from: the
   physical address, the TLB entry, or a default? How does the processor put it on the system bus, how do the Hub and Bedrock
   route such a request, and does IRIX ever build mapped uncached pages to device or register space?
4. What does the processor-interface region-present register (offset 0x18) do to the decode: fault, route, or nothing? And
   what decode effect does the Hub's memory configuration word have (bank enable, size, interleave)?

Grades: **E** established (read in the named bytes, or a published page states it; address or page given), **I** inferred
(a reasoned reading, reasoning given), **U** unknown (route to settle it given). Companion pages: [reset fetch, ckseg1 and
the Bedrock node number](decode-reset-and-kseg1.md), [IP27 PROM node numbering](ip27/prom-node-numbering.md),
[IP35 NASID numbering](ip35/nasid-numbering.md), [write timing](../evidence/hub-bedrock-config-write-timing.md),
[run-time decode changes](../evidence/runtime-address-decode-changes.md). Register pages: [Hub](../devices/hub/README.md),
[Hub processor interface](../devices/hub_pi/README.md), [Hub memory and directory](../devices/hub_md/README.md),
[Bedrock processor interface](../devices/bedrock_pi/README.md).

## What was read

| Item | Identity |
|---|---|
| MIPS R10000 Microprocessor User's Manual, version 2.0 (October 10, 1996) | Table 4-1 (printed page 53), sections 4.4 and 4.5 (pages 53 to 56), Table 6-21 (page 102), section 6.23 (page 153) |
| Origin and Onyx2 Theory of Operations, 007-3439-002 | printed pages 34 (address space), 36 (DIMM banks), 49 (regions), 51 (I/O is uncached address space) |
| Public Linux mainline v7.2 | `arch/mips/include/asm/mach-ip27/spaces.h`, `sn/sn0/hubpi.h`, `sn/sn0/hubni.h`, `sn/sn0/hubmd.h`, `arch/mips/sgi-ip27/ip27-memory.c` (`mlreset`, `gen_region_mask`, `slot_psize_compute`) |
| Public Linux 3.19 SN1 tree (IP35) | `arch/mips/include/asm/mach-ip35/spaces.h`, `sn/sn0/addrs.h` |
| IP27 CPU PROM, "SGI Version 6.156 built 11:27:56 AM Nov 18, 2003" | unpacked segment sha256 `c2c69bf33c375b43ec7ac511fab41ddf595be1b6838ae717e58a9a1273437fdd`; load 0xc00000001fc00000; addresses are `0x1fc...` load addresses |
| IP35 CPU PROM 6.210 (Aug 26, 2004) and 6.211 (Jan 25, 2008, patch 7208) | unpacked 6.210 sha256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`; 6.211 container sha256 `daed215f0e3b4ccd1a654e16a1e810fdf608a13509f51e3706906272ee4e727a`; 6.211 was read only for the TLB constants in section 1.3 |
| IRIX 6.5.22 and 6.5.30 `unix.IP27` | sha256 `40e3f6246b58aa9b0856cf36cd868355c0c3cbc5e00bb7fc886b52ca4622dc0f` and `567474674eaa83d36431e70f079a35819d0bc3ce1d4b4a2758b8e891b5acc463` |
| IRIX 6.5.22 and 6.5.30 `unix.IP35` | sha256 `87563dbc0cbc35c590348f9ec12863884fc857f6ae3a991b803aa2a71dca791c` and `412a1aae553a348376bc30cacbaf65044de1745d30222f02ec5f88297dcb1dfa` |
| Published console log "OpenBSD on SGI: a rollercoaster story" | the boot lines that print the region-present and cached-alias registers on an Origin 200 and on a Fuel |

Kernel addresses are link addresses; "6.5.22 IP27" means the 6.5.22 `unix.IP27` and so on. Literal-pool words were read from
the images at `gp` plus the displacement (gp is 0xc0000000014d0ef0 in 6.5.22 IP27). No Hub or Bedrock specification is held,
so every statement about what a chip does is from software behaviour (**I**), a public header's comment, or a published
page, never a chip document. Not read: the IP27 monitor ELF inside the PROM, the base-media IP27 PROM 6.11, and the IP27 PROM's
DIMM size probe (section 3, not found).

## 1. Mapped uncached accesses

### 1.1 Where the uncached attribute comes from (E, R10000 manual)

- The cache algorithm of a mapped page is the 3-bit C field of its TLB entry. Table 4-1 (page 53): 2 uncached, 3 cacheable
  noncoherent, 4 cacheable coherent exclusive, 5 cacheable coherent exclusive on write, 7 uncached accelerated; 0, 1 and 6 are
  reserved. The same encoding is used by the Config K0 field for kseg0 and by VA[61:59] for xkphys. **E.**
- The uncached attribute is a separate 2-bit value driven on SysAD[59:58] in the address cycle (Table 6-21, page 102) of
  processor double, single and partial-word read requests, of double, single and partial-word write requests, and of block
  write requests that come from completely gathered uncached accelerated blocks (section 6.23, page 153). The manual lists
  no other request as carrying it, so block reads, cached block writes, upgrades and eliminate requests do not. **E** for the
  list; **I** that the omission means "not driven".
- For an unmapped access the attribute is VA[58:57]. For a mapped access it is the TLB entry's Uncached Attribute field,
  which is initialised in 64-bit mode from bits 63:62 of EntryLo0 and EntryLo1 (section 6.23, page 153). **E.**
- So it is not taken from the physical address (SysAD[39:0] is the physical address and is a different field), and it is not
  a default: the processor puts whatever the page's TLB field holds on the bus for every uncached request to that page,
  whatever its C value (2 or 7). **E** from the two rules above; a page with a cached C value never issues the request kinds
  that carry the attribute.
- Uncached and uncached accelerated accesses execute in order and non-speculatively and go through the 4-entry uncached
  buffer (pages 55, 56 and chapter 6); accelerated stores may gather into one block write (page 55). **E.**

### 1.2 What the Hub and Bedrock see (I; names E from public headers)

- The node controller receives a request with a 40-bit physical address and, for the uncached kinds, the 2-bit attribute. A
  request from a mapped page and one from an unmapped xkphys address with the same physical address, attribute and request
  kind are the same bus transaction: nothing on SysAD says "mapped". **I**, from section 1.1 (the bus fields are the only
  inputs).
- The public headers name the four xkphys uncached spaces by attribute: attribute 0 is `HSPEC_BASE` 0x9000000000000000,
  1 is `IO_BASE` 0x9200000000000000, 2 is `MSPEC_BASE` 0x9400000000000000 and 3 is `UNCAC_BASE` 0x9600000000000000 (Linux
  v7.2 `mach-ip27/spaces.h` lines 21 to 24; the IP35 header has the same four). The Hub header says it assumes the processor
  follows the R10000's rules for the uncached attribute (Linux 3.19 `sn0/addrs.h`, header comment). **E** for the header text.
- What each space is, from what the PROMs and IRIX use it for. **I**:

  | Attribute | Space | Used for (examples) |
  |---|---|---|
  | 0 | Hub-special | boot flash window (PROM copy source 0x9000000010000000 IP27, 0x9000000018000000 IP35), the low-memory uncached alias; PROM TLB entries 62 and 61 (section 1.3) |
  | 1 | I/O and register | local node-controller registers at 0x9200000001000000 (a PROM pool word at 0x1fcdd8b8, IP27 6.156); widget windows |
  | 2 | memory special | fetch-and-op variables (see [Bedrock memory and directory](../devices/bedrock_md/README.md)) |
  | 3 | uncached memory | the PROM's copy destination 0x9600000001a00000; the PROM's and kernel's reads of the node's own tables at node offset 0x2000 (0x9600000000002000 plus the node number shifted) |

- Which space answers is decided by the attribute and the physical address together, and the node by the physical address's
  node-number field (bit 32 and up on the Hub in M mode, bit 33 and up on Bedrock: the node-alias loops in `mlreset` shift by
  32 and 33). At the reset address the attribute is not the selector: the PROMs reach the same flash with attributes 0 and 3
  and the same RAM with attributes 0 and 3 ([decode-reset-and-kseg1.md](decode-reset-and-kseg1.md)). **I.**
- Whether a chip treats a mapped uncached page differently from an unmapped one: no source says so and the bus gives it no way
  to. **I** that it does not; **U** as a chip statement (route: a Hub or Bedrock specification, or a load through a mapped
  page and through the xkphys form of the same address compared on a machine).

### 1.3 IRIX builds mapped uncached pages to register and device space (E)

The IRIX page-table entry is the processor's EntryLo word. **E:**

- `tlbdropin` (6.5.22 IP27 0xc00000000001993c) writes the 64-bit entry argument straight to EntryLo0 or EntryLo1 (`dmtc0` to
  registers 2 and 3 at 0x199ac and 0x199c0, or at 0x199ec to 0x19a00 for a slot that is not yet present) with a 16 KB page mask
  (`li 0x6000` at 0x199c8, then `mtc0 $5`) and `tlbwi` (0x199d0) or `tlbwr` (0x19a04). So the entry's bits 63:62 and its C field reach the processor unchanged.
- `pg_setcachable` (6.5.22 IP27 0xc000000000029938) clears the C field with the mask `-57` (`~0x38`) and sets 0x28, C = 5;
  `pte_cachebits` (0xc0000000000299a4) returns 40 (0x28). So the C field is at bits 5:3, as in EntryLo.

The routine that creates the mapped uncached pages is `v_mapphys` (the kernel's "map a physical range into a process"
primitive):

- Addresses: 6.5.22 IP27 0xc0000000001ebbdc; 6.5.22 IP35 0xc0000000002627dc; 6.5.30 IP27 0xc0000000001efdec; 6.5.30 IP35
  0xc00000000029ffa4. The per-page loop is a static routine entered at 0x1ebcb8 (6.5.22 IP27). All four kernels have the same
  code (the `ori 0x10` and attribute-shift pairs below were found at corresponding places in each).
- Argument: a 64-bit address in xkphys form, a length, a process handle. Range test (6.5.22 IP27 0x1ebe00 to 0x1ebe0c): the
  address with bits 58:57 masked out (mask 0xf9ffffffffffffff, pool word at 0xc0000000014caf30) must lie in
  [0x9000000000000000, 0x9000010000000000), the cache-algorithm-2 xkphys range with a 40-bit physical address; otherwise it
  is refused.
- For each 16 KB page it writes the page frame (address bits 39:14, a 26-bit field at EntryLo bit 8: mask 0x3ffffff at
  0x1ebdd8 to 0x1ebde8), **sets C to 2** (clear with `-57`, `ori 0x10`, store-conditional loop: 0x1ebe60 to 0x1ebe7c and again
  0x1ebe90 to 0x1ebeac), and **copies address bits 58:57 into entry bits 63:62** (`dsrl32 0x19` at 0x1ebe3c, `dsll32 0x1e` at
  0x1ebebc, merged at 0x1ebec8 to 0x1ebecc). That is: the uncached attribute of the mapped page is exactly the attribute bits
  of the xkphys address the caller passed, so a driver that passes 0x92... gets attribute 1 and one that passes 0x90... gets
  attribute 0. The same in 6.5.22 IP35 (`ori 0x10` 0x262a58, 0x262a88; `dsrl32 0x19` 0x262ab4, `dsll32 0x1e` 0x262ab8),
  6.5.30 IP27 (0x1f0074, 0x1f00a4; 0x1f004c, 0x1f00cc) and 6.5.30 IP35 (0x2a0220, 0x2a0250; 0x2a027c, 0x2a0280).
- An address whose bits 61:59 are 7 (uncached accelerated xkphys, 0xb8... to 0xbe...) is accepted too. `v_mapphys` builds a
  one-entry descriptor (mode 0, attribute 1, flags 3: stores at 0x1ebc64 to 0x1ebc84) for `v_setupphys` (6.5.22 IP27
  0xc0000000001eba70), whose modes are 0 -> C = 7 (`ori 0x38` at 0x1ebbd0), 1 -> C = 5 (`ori 0x28` at 0x1ebbd8) and
  2 -> C = 2 (`ori 0x10` at 0x1ebb2c), with the attribute field 0 or 1 taken from descriptor word +20 (0x1ebb38 to 0x1ebb58);
  the result is recorded in the mapping's attribute word, C at bits 28:26 and the attribute at 25:24 (0x1ebb78 to 0x1ebbbc). The
  page loop itself still writes C = 2 for such an address (0x1ec02c to 0x1ec098). **E** for all of that. Where the recorded
  C = 7 is applied to the TLB entry is **U**: the one consumer found (`genphysfault`, 6.5.22 IP27 0xc000000000252b20) only
  compares the recorded values of neighbouring ranges (0x252c30 to 0x252c48). Route: read what builds the entry when a physical
  mapping is first touched, after `genphysfault`.
- The kernel does produce the accelerated form of an address: `hub_piotrans_addr` (6.5.22 IP27 0xc00000000003b6fc) ors
  `7 << 59` into the address returned by `hub_piomap_addr` when bit 3 of its flags argument is set (0x3b78c to 0x3b7a0). Same
  in 6.5.22 IP35 (0xc000000000062ee0, 0x62f70 to 0x62f84), 6.5.30 IP27 (0xc00000000003ba0c, 0x3ba9c to 0x3bab0) and 6.5.30
  IP35 (0xc000000000062680, 0x62710 to 0x62724). **E.** That a graphics or other driver passes that flag was not traced (**U**).

Callers of `v_mapphys` that map register and device space (6.5.22 IP27; call-site addresses; the other three kernels have the
same callers with different addresses):

| Caller | Call site | What it maps | Grade |
|---|---|---|---|
| `xbow_map` (0xc00000000006ea00) | 0x6ea2c | the crossbar chip's register block: address from field +16 of the vertex's fast-info record, length rounded up to 16 KB | E for the call; I that the address is 0x92... (attribute 1), not read |
| `pcibr_map` (0xc000000000072d30) | 0x72d94 | PCI bridge registers: address field +8 of the bridge record plus the caller's offset, length rounded up to 16 KB | E for the call; I for the attribute |
| `cpuprom_map` (0xc00000000006d3e0, reached from `hubspc_map` 0xc00000000006d5c8) | 0x6d430 | the node's boot PROM window: `hubdev_prombase_get(node)`, length at most 0x10000000 | E for the call; I that the base is an attribute-0 address |
| `mem_refcnt_mmap` (0xc0000000002798f8, from `hubspc_map` for device-info value 0) | 0x279984 | the node's page reference counters | E for the call; U for the address |
| `mmmap` (0xc0000000000add60; calls at 0xade94, 0xadedc, 0xadef4) | 0xadedc | the free-running real-time counter: `query_cyclecntr` (0xc0000000000455a4) returns the pool word 0x9200000001030100 (0xc0000000014cae78) | **E**: a mapped uncached page of the Hub's own register block, attribute 1; the same pool word 0x9200000001030100 is used by `query_cyclecntr` in 6.5.22 IP35 (pool 0xc00000000159a0e0) and 6.5.30 IP27 (0xc0000000014cc150) and IP35 (0xc000000001644048) |
| `ude_map` 0x8bcf4, 0x8bd40; `usrvme_map` 0x8c634; `usrpci_map` 0x918e4 (IP27 only); `eimap` 0x966d0; `tsiomap` 0x9ece4; `rad1pcimap` 0x15b58c; `ioc3_serial_kill` 0x17c7a8; `kdspmap` 0x3b4bf4 | | user-level maps of VME, PCI, video and serial hardware | E for the calls; the argument of each was not read |

Not found: any other builder of a C = 2 or C = 7 page-table entry. The mask `-57` appears only in `v_mapphys`, `pg_setcachable`,
`pas_setrangeattr` (which only restores or sets C = 5 and copies the old C), `pas_addmmapdevice`, `vgrowreg`, `sio_initport`,
`reginit` and, in the IP27 kernels, `rad1pciopen` and `rad1_set_video_timing` (and `MgrasInitRSS` in 6.5.30 IP27): scan of all four
kernels. **E** for the scan; what the driver routines do with the mask was not read (**U**).

The PROMs also use mapped uncached pages, with attribute 0 (EntryLo bits 63:62 clear): IP35 6.210 entry 62, VA
0xc00000001fc00000, EntryLo0 0x7f0012 and EntryLo1 0x7f4012 (C = 2, valid, not dirty, physical 0x1fc00000 and 0x1fd00000,
1 MB pages), built at 0x1fc05c80 to 0x1fc05cb8 and written by the shared TLB writer 0x1fc05b30; entry 61 maps RAM at 0x01a00000
the same way (EntryLo 0x68016, 0x6c016). 6.211 builds entry 62 with the same constants at the same address (`ori 0x4012` at 0x1fc05cb4). The IP27
6.156 PROM has the same four entries ([ip35-reset-window.md](../questions/ip35-reset-window.md)). **E.** These are the one
known case of a mapped uncached page to boot flash.

## 2. The region-present register (PI offset 0x18, 64 bits)

### 2.1 What a region is

- A region is a node (fine mode) or a group of nodes (coarse mode). The Theory of Operations manual says: with fewer than 128
  processors a region is two processors sharing a hub, with more it is eight hubs in a node group, and the system has 64
  regions (page 49). The register has one bit per region. **E** (manual), **E** (header: 64-bit register).
- Hub: bit 17 of `NI_STATUS_REV_ID` is the region size, 1 = fine (region = NASID), 0 = coarse (eight nodes per region, shift 3)
  (public Linux `hubni.h`: `REGIONSIZE_FINE 1`, `NASID_TO_COARSEREG_SHFT 3`, `get_region_shift`). **E.** IRIX agrees:
  `is_fine_dirmode` reads bit 17 through a pointer variable (6.5.22 IP27 0xc00000000001d460: `dsrl 0x11`, `andi 1`; the pointer
  is a data word whose run-time value was not read, **I** that it is the status register), and `nasid_to_region` (0xc00000000002734c)
  returns the NASID when that is true and `nasid >> 3` when it is not. **E.**
- Bedrock: the region size is bits 47:46 of the local-block `rev_id`, 0 = one node per region, 1 = two, 2 = four (N mode)
  ([Bedrock local block](../devices/bedrock_lb/README.md)). IRIX `is_fine_dirmode` (6.5.22 IP35 0xc000000000041230) is
  true when those bits are 0, and `nasid_to_region` (0xc00000000004f628) returns `nasid >> 1` when it is not (the code has no
  shift of 2 for the value 2: **E** for the code, **U** whether any shipped configuration uses the value 2). The region of a
  Bedrock node is therefore `nasid` or `nasid >> 1` in IRIX. **E.**
- The PROM sets the region size ([ip27/prom-node-numbering.md](ip27/prom-node-numbering.md), [ip35/nasid-numbering.md](ip35/nasid-numbering.md)).

### 2.2 Who writes it, and the values

| Writer | Where | Value | Grade |
|---|---|---|---|
| IRIX Hub `mlreset(0)` | 6.5.22 IP27 `sd` at 0xc000000000026138 (`ori 1` at 0x26134), 6.5.30 0xc00000000002638c (`ori 1` at 0x26388) | the mask of regions that hold a probed node, **with bit 0 forced on**, to every node's processor interface through its node alias | E |
| IRIX Bedrock `mlreset(0)` | 6.5.22 IP35 `sd` at 0xc00000000004e5b8, 6.5.30 0xc00000000004dc80, for interface 0 (offset 0x18) and interface 1 (0x200018) | the region mask **without** forcing bit 0 | E |
| IP35 PROM 6.210 | 0x1fc5c1d0 to 0x1fc5c1f8, both interfaces | the same value it stores to the local-block region-present register (0x604020), see [write timing](../evidence/hub-bedrock-config-write-timing.md) section 3.4 | E |
| IP27 PROM 6.156 | none found | three searches found no store ([prom-node-numbering.md](ip27/prom-node-numbering.md)); the monitor ELF was not read | I |

Values read after the stock PROM in a published console log (an OpenBSD boot printing the registers before writing them): an
Origin 200 prints region present 0xffffffffffffffff and cached-alias size 2; a Fuel prints 0x1 and 2. **E** that the log says
this. They are reads after firmware, not reset values, and the cached-alias size 2 differs from the single store of 1 that
the IP27 PROM is known to make (0x1fc01140), so something later wrote it: the reset value of the register on either chip is
**U**. Route: a read before any firmware store, or a specification.

### 2.3 What it does

| Evidence | Statement | Grade |
|---|---|---|
| Public Linux v7.2 `ip27-memory.c` `mlreset` (lines 294 to 300), Hub | the comment explains why bit 0 is always set: cached-alias addresses resolve to node 0, so without it they fault; then `PI_REGION_PRESENT = region_mask \| 1` for every node | E for the text, I for the hardware behaviour |
| IRIX Hub `mlreset` | forces bit 0 on every node (above); consistent with the Linux comment | E for the code, I for the reason |
| Public Linux 2.5.40 SN1 processor-interface header comments (as imported in [Bedrock processor interface](../devices/bedrock_pi/README.md)), Bedrock | a clear bit blocks speculative coherent reads to the region; a coherent read to an absent region gets an error reply and no error register changes; partial accesses are not checked; cached-alias accesses are not affected | E for the text, I for silicon |
| IRIX Bedrock `mlreset` | does not force bit 0, consistent with "cached-alias accesses are not affected" | E for the code, I for the link |
| IRIX `handle_cac_buserr`, the only reader of PI 0x18 in the kernels | reads the local register through the pool word 0x9200000001000018, shifts 1 by `nasid_to_region(node of the faulting address)`, and when the bit is clear prints "Region 0x%x, region not populated, node 0x%x paddr 0x%x" (message tag 2939) and returns 3; when set it goes on to the partition and poisoned-page checks. 6.5.22 IP27: routine 0xc000000000036b80, load at 0x36d14 to 0x36d28, pool word at 0xc0000000014cb0e8, string at 0xc00000000140b388; 6.5.22 IP35 routine 0xc00000000005e2e0, 0x5e3d8 to 0x5e3f4 (pool 0xc00000000159a2e0); 6.5.30 IP27 load at 0x36fe0, IP35 at 0x5db34. The check runs when the error spool has no matching record (results 0 and -1 of `get_matching_spool_addr`) | E |
| IRIX `dobuserre` (6.5.22 IP27 0xc000000000035870) calls `handle_cac_buserr` (call at 0x35b80), `handle_uncac_buserr` (0x35b50) or `handle_io_buserr` (0x35c94) by the class of the faulting address. Only the cached handler reads PI 0x18 | E |
| No route derived from it | nothing in either kernel computes a destination from PI 0x18; routing tables are programmed elsewhere (network interface, [run-time decode changes](../evidence/runtime-address-decode-changes.md)) | E for IRIX, I for the chips |

**Answer.** On both chips a clear bit turns a cached (coherent) request that targets that region into an error reply, which the
processor takes as a bus error; it does not change where a request is sent (that is the physical address's node field and the
network tables), and IRIX uses it only to explain a cached bus error that left no error record. **I** (software behaviour plus
the Bedrock header comment; no chip document). What is not shown: whether the Hub checks uncached or partial accesses (the
Bedrock header says no; the Hub has no such statement, **U**), and whether a Hub CALIAS access to a node whose bit is clear faults
(the Linux comment says so; **I**, route: a cached load of low memory with the node-0 bit clear, on a machine).

### 2.4 Where the earlier disagreement lands

Three earlier datasheet statements read as a conflict. They are not about the same chip:

- "Node zero must be present in the Hub's region-present register or cached-alias accesses fault" is a Hub statement and is
  supported (Linux comment, IRIX forcing bit 0, both **I** for the hardware).
- "Cached-alias accesses are unaffected" is a Bedrock statement from the Bedrock header's own text, and IRIX's Bedrock code does
  not force bit 0. It does not apply to the Hub.
- "Which memory regions exist, reset all ones" for the Hub states a reset value no source gives (**U**; section 2.2). The first
  half is right in spirit if "memory" means "node": a region is a node or node group, not a memory bank.

## 3. The Hub memory configuration word (`MD_MEMORY_CONFIG`, offset 0x200018)

Reached locally as 0x9200000001200018 (pool word at 0x1fcdd770 in IP27 6.156) and remotely at 0x9200000001a00000 plus the node
number shifted left 32, plus 0x18. Layout from the public Linux v7.2 `hubmd.h` (**E** as header text; see
[Hub memory and directory](../devices/hub_md/README.md)): eight 3-bit bank size codes at 23:0 (bank b at 3b+2:3b), reply
guarantee 27:24, premium directory 28, ignore ECC 29, a bit named `ARB_MLSS` at 30, I/O protect enable 31, DIMM 0 select 33:32,
and four 5-bit timing fields 53:34. The bank index is address bits 31:29, a 512 MB window (`MD_BANK_SHFT 29`), four banks in the
header's N mode and eight in M mode.

- **Bank enable.** There is no enable bit: code 0 is "empty". The header marks only codes 0 (empty), 4 (64 MB), 5 (128 MB) and
  7 (512 MB) as valid in this register, and 3 (32 MB) as broken in the first Hub. The IP27 PROM refuses 256 MB banks (code 6):
  the text "256 MB dimm banks not allowed on IP27 node boards" is at 0x1fc5f381, 0x1fc63790 and 0x1fc637f9, and it also carries
  "Disabling memory bank %d in module %d slot %d" (0x1fc5f3e8) and the `DisableMemMask` variable (0x1fc5e5a8). **E** for the
  strings; **I** that disabling writes code 0 and that the refusal matches the header's list of valid codes. The routine that probes
  DIMM sizes and writes the codes was **not found**: the strings "Configuring memory" (0x1fc5f050), "Bank %d: %s MB (%s)" (0x1fc62cd0) and the
  256 MB message have no pointer anywhere in the unpacked segment (searched as 64-bit and as 32-bit words). Route: trace
  backward from the sites that read the local word through the pool word 0x1fcdd770 (0x1fc18924, 0x1fc514f8, 0x1fc53118,
  0x1fc531dc, 0x1fc58fcc), which print it in the "Unuseable bank 0: mc 0x%lx" messages (0x1fc5f6b8, 0x1fc5f8c0, 0x1fc5fe98). **U.**
- **Size.** A bank's code gives how much of its 512 MB window is populated, in 4 MB steps (`MD_SIZE_BYTES`: 4 MB shifted left by
  the code). **E** for the header formula, **I** for "this is what decides which addresses answer". A smaller bank sits at the
  base of its window: the public Linux `slot_psize_compute` gives a bank of 128 MB or less memory in the first of its four
  128 MB slots only (`ip27-memory.c`, "hack for 128 dimm banks"). **E** for the text, **I** for the hardware. What the chip does
  for an address inside the window but beyond the populated size, or inside an empty window, is **U**. IRIX carries the text
  "Access to non-existent memory address 0x%x" (6.5.22 IP27 0xc00000000140abb8); its use was not traced.
- **Interleave.** There is no interleave field in the word (**E**: the header's field list above). The only interleave the
  published manual describes is inside a DIMM: the four logical banks of a DIMM are interleaved at 4 KB, and a 16 KB page spans
  all four (Theory of Operations page 36, **E**), which is fixed by the DIMM and not selected by this register (**I**).
- **DIMM select (33:32).** The IP27 PROM changes it with one routine, 0xc00000001fc559cc: it clears bits 33:32 (mask
  0xfffffffcffffffff, pool 0x1fcddbd8), ors in its second argument shifted left 32, and then four times (shift 0, 6, 12, 18)
  **exchanges the size codes of the bank pairs (0,1), (2,3), (4,5) and (6,7)**. Both call sites pass 2: 0x1fc4c2bc (a headless node,
  taken only when bits 33:32 are below 2, test at 0x1fc4c298 to 0x1fc4c2a4) and 0x1fc59fd0. **E.** The strings "Swapping bank 0
  with bank 1 on headless node nasid %d" (0x1fc5e5b8) and "*** Swapping bank 0 with bank 1" (0x1fc5f4e8) belong to those two
  paths (**I**: the string pointers were not resolved). The kernel names a failing module as bits 33:32 XOR address bits 31:29
  (`mdir_xlate_addr_mem`, 6.5.30 IP27 0xc000000000049974, in [the Hub page](../devices/hub/README.md)). **E** for both; so the
  select permutes which physical DIMM serves a bank window (**I**), and a swap exists to move a working bank to the base of the
  address space.
- **Directory format (28).** Set selects the premium directory format. The kernel's directory routines pick between two entry
  layouts on this bit: `check_dir_access` (6.5.30 IP27 0xc00000000002a184) returns bit 7 of the entry when it is set and bit 5
  of the low 16 bits when clear, and the protection listing prints 64 entries when set and 16 when clear (see the Hub page). **E.**
  It changes the directory entry format and the number of protection entries; nothing shows it changing which data addresses
  answer. **I.** The PROM sets it, together with bit 29, in the routine around 0x1fc2818c to 0x1fc281ac (a probe: **I**), and
  temporarily sets bit 29 around a call at 0x1fc2c030 and restores the old word at 0x1fc2c070 (**E** for the stores, **I** for the
  purpose).
- **Timing (53:34).** The PROM writes the flash timing fields (0x1fc1c428 to 0x1fc1c460, from variables) and so does IRIX
  `cpuprom_map` only when a program maps the PROM space ([run-time decode changes](../evidence/runtime-address-decode-changes.md)).
  These change how fast the flash answers, not what answers. **E.**
- **Reset value.** U. The header's `MMC_RESET_DEFAULTS` (all bank codes 7, premium directory and ignore ECC set) is a value
  software writes, not a read from hardware.

The Bedrock counterpart (per-bank enables, one size code per bank pair, the same XOR with the select) is in
[prom-md-config.md](ip35/prom-md-config.md) and [ip35-prom-memory-bank-config.md](../questions/ip35-prom-memory-bank-config.md).

## What stays open

| Question | Route |
|---|---|
| Hub and Bedrock handling of a mapped uncached page versus the xkphys form of the same address | a load through each on a machine, or a chip specification |
| Where the recorded C = 7 of an accelerated physical mapping is applied (section 1.3) | read the entry builder that runs after `genphysfault` |
| Reset value of region present on either chip; whether the Hub checks uncached accesses against it | a read before firmware stores, or a Hub specification |
| The IP27 PROM's DIMM size probe and what an address beyond a bank's size does | find the string references through the PROM's data; a probe read past a small bank |
| What the DIMM select does beyond permuting bank windows | the same probe with the select changed |
