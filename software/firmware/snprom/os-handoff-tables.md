# The tables the SN2 PROM builds for the operating system

What the SAL 5.04 PROM (SHub 1, Altix 350) puts in front of the loader and the kernel: the ACPI 2.0 tables, the EFI memory map, the SAL system table and the EFI runtime services. Each section gives the builder's address and what it writes, so a machine model can supply the same thing. The kernel side (what `setup_arch` needs from each) is in [the early-boot page](../../linux/sn2-early-boot.md); the hand-off record is in [efi.md](efi.md#2-the-hand-off-from-sal_b).

Image: `shub1snprom.bin` from snprom 10.54 build 70399, SAL 5.04, flat at `0xffa00000`; the EFI component is the gzip ELF of FIT type `0x1f`. Addresses `0xff......` are SAL_B machine addresses; EFI addresses are ELF addresses (the Ghidra export adds `0x100000`).

**Grades.** *established*: the whole builder was read and the constants decoded from the image bytes. *inferred*: read from call shape or names. *unknown*: not read. Decompiler output was navigation only. The UEFI/EFI 1.10 and ACPI 2.0 specifications are not held in the Library (a search of `techpubs` found neither), so structure offsets below are checked against the PROM's own stores and against Linux, not a specification.

## How the tables are built

SAL_B runs `0xffafc140` just before it enters EFI. It allocates every table from a hand-off arena (`0xffafc350`, zeroed, so every field not named below is 0) and writes the 0x58-byte record. The calls, in order (established):

| Builder | Makes |
|---|---|
| `0xffac8120` | the memory descriptor array |
| `0xffafca90` | the SAL system table |
| `0xffb5c9b0` | the ACPI 1.0 RSDP: a stub that stores 0 |
| `0xffb5a2f0` | the ACPI 2.0 RSDP, which calls `0xffb59da0` for the XSDT |

The record's ACPI 1.0 slot is therefore 0 and there is no ACPI 1.0 table (the kernel does not use one). EFI's `InstallConfigurationTable` adds no entry for a null table ([efi.md](efi.md#3-configuration-tables-and-where-sn2-specific-data-lives)), so no ACPI 1.0 configuration table exists. The ACPI 2.0 pointer is also stored at block B `+0xc0` ([sn2-runtime](../../sal/sn2-runtime.md#two-data-blocks-the-handlers-use)).

All ACPI tables share the header writer `0xffb565e0` and the checksum/length writer `0xffb56750` (established): OEM id `SGI` (3 bytes, rest 0), OEM table id = the signature followed by `SN2\0` (for example `APICSN2\0`), OEM revision `(revision << 16) + 1`, creator id 1. The length/checksum writer also stores its third argument at `+0x20` (creator revision): 1 for the MADT, SRAT, SLIT and FADT, but `0x44` (the table's own length) for the XSDT. Length and the checksum byte are set last.

## 1. ACPI

Established, from the five builders.

| Table | Builder | Revision | Length |
|---|---|---|---|
| RSDP | `0xffb5a2f0` | 2 | 0x24 |
| XSDT | `0xffb59da0` | 1 | 0x44 |
| MADT (`APIC`) | `0xffb56910` | 1 | 0x2c + 12 per CPU |
| SRAT | `0xffb56d40` | 1 | 0x30 + 40 per memory node + 16 per CPU |
| SLIT | `0xffb57570` | 1 | 0x2c + N*N |
| FADT (`FACP`) | `0xffb57c40` | 3 | 0xf4 |
| FACS | `0xffb58360` | n/a | 0x40 |

**RSDP.** Signature `RSD PTR `, OEM id `SGI`, revision 2, RSDT address 0, length 0x24, XSDT address at `+0x18`, both checksums set.

**XSDT.** Four 64-bit entries at `+0x24`: MADT, SRAT, SLIT, FADT, in that order. No DSDT, no SPCR and no HCDP/PCDP at hand-off (the HCDP is EFI's, [efi.md](efi.md#3-configuration-tables-and-where-sn2-specific-data-lives); no SPCR or PCDP signature exists in SAL_B). The FADT's `X_DSDT` is 0 at this point. **A later builder does exist** (established): `0xffb585c0` (frees and clears a previous DSDT/SSDTs, zeroes `X_DSDT`, re-checksums the FADT) and `0xffb58ca0` ("SAL ACPI: generating DSDT..."), both fed the RSDP from block B `+0xc0`. The latter builds a header-only DSDT (revision 2, length 36, OEM revision `0x20001`; `0x20101` on a rewrite path whose condition was not decoded), stores it in `X_DSDT`, re-checksums the FADT, and when it succeeds generates SSDTs through `0xffb5c940` ("ACPI 2.0 ssdt at ...") and appends them to the XSDT after the four entries. The namespace code at `0xffb4a210` to `0xffb52b00` uses the names `_SB_`, `SGIHUB`, `SGITIO`, `H%03x`, `P%03x`, `D%03x`, `_HID`, `_SEG`, `_BBN`, `_CRS`, `_PRT`, `_ADR`, `_SUN`. It runs from the tail of the deferred hub/bus initialisation (`0xffb2d450`, reached from the I/O dispatcher's first `0x55` call) and from the `0x5c` case; the `NoACPIIO` POD variable is consulted. When exactly SSDTs appear is **inferred**. The early-boot kernel reads the tables before any of this, so it sees no DSDT ([early-boot page](../../linux/sn2-early-boot.md)).

**Where the numbers come from** (established as the reads; the writers of both tables are unread, see section 5). A per-node table at block A `+0x10` (a count, then one halfword per NASID, `-1` for an absent node) and a per-CPU table at block A `+0x18`: 4-byte entries `{u16 id, u16 flags}` ended by id `0xffff`, flag bit 0 = CPU enabled. The CPU id is the SAPIC id the kernel sees: ID in bits 15:8, EID in bits 7:0. A node "has memory" when `0xffa788b0` finds a non-zero total in the SHub memory configuration register at `0x9_0001_0010` of that NASID. Proximity domains are compact numbers: the n-th node with memory, in NASID order, gets domain n; a CPU takes the domain of its NASID, found from the id as `(id & 0x7f) | ((id >> 11) << 7)`, the same decode [GET_SAPIC_INFO](../../sal/sn2-runtime.md#get_sapic_info-0x0200001d) uses.

**MADT.** Header 0x2c: local APIC address (`+0x24`) 0 and flags 0, so the kernel stores no address. One type 7 (local SAPIC, length 12) per CPU table entry, in table order: `+2` ACPI processor id (0, 1, 2 ...), `+3` SAPIC id (`id >> 8`), `+4` EID (`id & 0xff`), `+8` flags = `4`, with bit 0 added when the table flag is set (a CPU the table marks absent keeps flags 4: the enable bit is the only difference). No IOSAPIC, interrupt-override or NMI entries.

**SRAT.** Header 0x30 with the two reserved words 0. Memory entries first, then CPU entries, both in the order of their source tables.
- *Memory* (type 1, length 0x28), one per node with memory: domain at `+2`; base at `+8` = `(nasid << 38) + 0x30_0000_0000`; length at `+0x10` = `0x10_0000_0000` (64 GiB, the node's whole cacheable window, not the installed size); `+0x18` = 1; flags at `+0x1c` = 1 (enabled). The `0x30_0000_0000` is address-space bits 37:36 = 3 ([address map](../../../platforms/sn2/address-map.md)); the kernel takes the NASID as `(base >> 38) & 0x7ff`, which these bits do not disturb.
- *Processor* (type 0, length 16), one per CPU, including CPUs on nodes without memory (the domain comes from the compact map by NASID, which has no number for such a node; the builder allocates the map without a visible clear, so the value the entry gets is **unknown**): domain `[7:0]` at `+2`, SAPIC id at `+3`, flags `+4` = 1, EID at `+8`, domain `[15:8]` at `+9`. So a slice appears only through the EID/id bits of its CPU.

**SLIT.** `+0x24` holds N, the number of domains (highest compact number + 1); the N*N byte matrix starts at `+0x2c`, pre-filled `0xff`. An entry is `10 * distance(i, j) / distance(i, i)`, capped at `0xfe`, using a per-chip distance method (`0xffa0b210`; the chip method is **inferred** to count router hops from the node table at block A `+0x30`).

**FADT.** Revision 3, no DSDT. Fields set: PM profile `+0x2d` = 4, SCI interrupt `+0x2e` = 0x34, PM1 event/control/timer/GPE0 lengths 4/2/4/8, `P_LVL2_LAT` 0x65 and `P_LVL3_LAT` 0x3e9 (C2/C3 unsupported), flags `0x1041` (WBINVD, fixed RTC absent, headless), `X_FIRMWARE_CTRL` = the FACS. The extended PM1a event, PM1a control, PM timer and GPE0 blocks are memory-space generic addresses that point to freshly allocated, zeroed RAM (4, 2, 4, 8 bytes): they are not hardware. Their bit width, bit offset and access size fields are 0, and bit 0 (SCI_EN) of the 2-byte PM1a control word is set (the only non-zero byte). FACS: signature, length 0x40, version 1 at `+0x20`.

## 2. The EFI memory map

The array is built by `0xffac8120` (0x28-byte descriptors: type, physical start, pages, attribute), sorted by start, and handed to EFI, which adds its own allocations and returns the result through `GetMemoryMap` (descriptor size 0x30, version 1). The kernel sees both. Established unless marked.

| Source | Type | Start and size | Attribute |
|---|---|---|---|
| PAL code, first node only | 13 | `0x0100_0000`, 16 MiB | `0x8000000000000009` |
| Flash window | 11 | `0xff80_0000`, 8 MiB | `0x8000000000000001` |
| I/O port space | 12 | `0x1fff_ffff_fc00_0000`, 64 MiB | `0x8000000000000001` |
| MMIO, SHub 1 (part `0x4363`) | 11 | `(nasid << 38) + 0x8_0000_0000`, 32 GiB | `0x8000000000000001` |
| MMIO, TIO (part `0x4422`, **inferred** to be a TIO) | 11 | `nasid << 38`, 64 GiB | `0x8000000000000001` |

Every node with memory then gets, from its bank 0 (base = `(nasid << 38) + 0x30_0000_0000`), in this order:

| Offset | Type | Attribute |
|---|---|---|
| `0` to `0x1_0000` | 8 (unusable) | 9 |
| to `0x8_0000` | 6 (runtime data) | `0x1001` |
| to `0x40_0000` | 4 (boot data) | 1 |
| to `0x200_0000` | 6 | `0x1009` |
| to `0x300_0000` | 6 | 9 |
| to `0x600_0000` | 4 | 9 |

After that: conventional memory (type 7, attribute 9) up to the SAL copy at `([block A + 0x28] & 0xf_ff00_0000) + 0xa0_0000`, a type 5 (runtime code) descriptor of 6 MiB there (attribute 9, no runtime bit), then conventional memory to the end of the bank. A bank's size is 31/32 of the bank record's size, capped at 16 GiB; a disabled bank is one type 8 descriptor of attribute 9. Banks sit 16 GiB apart (`bank << 34`). If the bank length `len` (the 31/32 figure) is below about 2 GiB, the last `64 MiB - len/31` of it (64 MiB minus 1/32 of the record size) is typed 8 (attribute 8). The carve-out table above applies to bank 0 only; the SAL-copy test applies to every bank. With node base B = `(nasid << 38) + 0x30_0000_0000` the layout is B+0 to +0x1_0000 type 8, to +0x8_0000 type 6 (`0x1001`), to +0x40_0000 type 4 (1), to +0x200_0000 type 6 (`0x1009`), to +0x300_0000 type 6 (9), to +0x600_0000 type 4 (9). The type 5 start is `((([block A + 0x28] & 0xf_ff00_0000) + 0xa0_0000) & 0x7fff_ffcf_ffff_ffff) | B` (the builder masks through `0xffaeb1c0` at `0xffacf6cc`, as the copy does; established); if that is not beyond the running offset, no type 5 descriptor is emitted. The value at block A `+0x28` is the constant `0x40_0000` from the block's layout table (section 5; **inferred** that nothing rewrites it), so the mask (bits 35:24 only) leaves 0 and the SAL copy sits at node base + `0xa0_0000`, inside the type 6 range from `+0x40_0000` to `+0x200_0000`. That start is not beyond the running offset after the carve-outs (`+0x600_0000`), so by the rule above no type 5 descriptor is emitted on bank 0 (**inferred** from the arithmetic; the descriptor code was not re-run). The SAL shadow copy (6 MiB) goes to the same address ([boot-sequence](boot-sequence.md)). Attribute 9 is write-back plus uncached, so the kernel's write-back test passes for the conventional and boot-data ranges. The bank size and enable bit come from component records of type `0x32` inside the node's board of type `0x11` (`+0x1c` bank, `+0x38` size in MiB, `+2` bit 0 enabled); the PROM's inventory builder produces those, and the layout of the record is not decoded.

Notes. The PAL descriptor is one 16 MiB range, exactly the kernel's limit, and it contains `PAL_PROC` (`0x01ff_f800`) and `SAL_PROC` (`0x01ff_fc00`). Under the simulator signature the port space instead sits at `0xf_cc00_0000` inside bank 0 and nothing is added at the end. No descriptor covers the legacy VGA range `0xa0000`, so `efi_mem_type(0xa0000)` is not conventional (**inferred** from the list above). The runtime bit (bit 63) is set only on the PAL, port-space, flash and MMIO descriptors, so those are all `SetVirtualAddressMap` has to map.

## 3. The SAL system table

Builder `0xffafca90`, 0xe0 bytes, five entries (established).

| Field | Value |
|---|---|
| signature | `SST_` |
| `+4` size | `0x60` (the header only; the checksum byte at `+0xc` covers the same 0x60 bytes) |
| `+8` SAL spec revision | `0x0302` |
| `+0xa` entries | 5 |
| `+0x14`, `+0x16` SAL_A and SAL_B version | `0x0504` (5.04) |
| `+0x18` OEM id, `+0x38` product id | `SGI`, `SN2` |

Entries start at `+0x60`, in order:

| Offset | Type | Contents |
|---|---|---|
| `0x60` | 0, entry point (48 bytes) | `PAL_PROC` `0x01ff_f800` (`+8`), `SAL_PROC` `0x01ff_fc00` (`+0x10`), global pointer `0x01ff_fc00` (`+0x18`) |
| `0x90` | 2, platform features | feature byte `+1` = 8: only the ITC-drift bit; no bus lock, no IRQ or IPI redirection |
| `0xa0` | 3, translation register (32 bytes) | instruction TR 0, virtual address `0x0100_0000`, page size 2^24, PTE 0 |
| `0xc0` | 4, PTC domains | count at `+4`, array pointer at `+8`; one domain per NASID, each `{count, pointer to u16 ids}`, from the block A `+0x18` CPU table |
| `0xd0` | 5, AP wake-up | mechanism byte `+1` = 0 (external interrupt), vector `0x12` at `+8` |

No type 1 (memory descriptor) entries. The three entry-point addresses are in the PAL-code range; what code sits at `0x01ff_fc00` was not traced (**unknown**), so a model may place its own SAL stub there or anywhere in the PAL range. This agrees with [sn2-runtime](../../sal/sn2-runtime.md); the AP wake-up and platform-feature values are new there. A model that clears the ITC-drift bit or changes the vector changes kernel behaviour (the early-boot page lists why).

## 4. The EFI runtime services

The system table in the EFI image (`SystemTable`, `0x1fe268`, 120 bytes) is static: signature `IBI SYST`, revision `0x0001000a` (EFI 1.10) at `+8`, header size 120, CRC field 0; the vendor, console and table pointers are filled in at run time and the vendor string was not found (**unknown**). Runtime services table (`RuntimeServices`, `0x1fe2e0`, signature `RUNTSERV`) members, named from the image's symbols (**inferred** for which slot holds which, established for each body):

| Service | Implementation |
|---|---|
| `GetTime` | real: SAL `0x0200000b` fills seven u16 (year, month, day, hour, minute, second, milliseconds; converted to nanoseconds); always returns success whatever SAL returned; capabilities resolution 1, accuracy 50,000,000 (50 ppm), no sets-to-zero; time zone and daylight 0. |
| `SetTime` | real: SAL `0x0200000a` |
| `GetWakeupTime`, `SetWakeupTime` | stubs (`RtSNGetWakeupTime`, `RtSNSetWakeupTime`) returning `0x8000000000000003`, `EFI_UNSUPPORTED` |
| `SetVirtualAddressMap` | real (below) |
| `ConvertPointer` | real; loops forever on an address outside every known range |
| `GetVariable`, `GetNextVariableName`, `SetVariable` | real; read, update and erase go through the SAL callback `0x8000000000003000`, whose descriptor in SAL_B is the one `0x02000008` uses ([sn2-runtime](../../sal/sn2-runtime.md)) |
| `GetNextHighMonotonicCount` | real |
| `ResetSystem` | real: cold and shutdown send SAL callback `0x5000` (descriptor of `0x02000002`) op 2, warm op 1; other types return `EFI_UNSUPPORTED` |

The SAL side of the clock (`0xffa1cef0`, `0xffa1c8d0`, established): the time is a base value held at block A `+0x48`, advanced by the SHub real-time counter at `0x81_101c_0000` (the same counter `Stall` uses), and re-read when more than 300,000,000 ticks have passed. The base is read by a chip method at slot `+0xb8` (unread); if it fails the base is 1998-01-01 00:00:00. A model can therefore answer with any fixed base and a running counter.

`SetVirtualAddressMap` (`0x12d0e0` and `0x121800`, established; the exported entry swaps `cr.iva` to the SAL runtime vector table for the call): it fails with `EFI_UNSUPPORTED` before `ExitBootServices` or when already virtual, `EFI_INVALID_PARAMETER` for a descriptor size under 0x28 or a version other than 1, and `EFI_NOT_FOUND` for a descriptor with a virtual address that matches no runtime range. It matches each descriptor to a runtime range by physical start, fixes up the runtime image list, events and its own pointers, returns `EFI_NO_MAPPING` if a runtime range got no virtual address, and finally calls SAL `0x02000013` once to retarget the PROM's own pointers (mode value 1, then a clearing call). The kernel tolerates failure.

SAL calls the runtime implements among those the kernel and EFI use: `PROBE` `0x02000003` (protected read, returns data), `SYSCTL_OP` `0x02000030` (ops 1, 2, `0x200f`), `PCI_CONFIG_READ`/`WRITE` `0x01000010`/`11` (decode the address as segment/bus/device/function/register, look up the device and read or write through its config method; status 0 even when no device is found, in which case no data is returned), and `PHYSICAL_ID_INFO` `0x01000013` (status 0; r9 not decoded, **unknown**). All four are present in both the SAL_B and the runtime dispatch tables.

## 5. Block A and the tables the builders read

Established from the layout code (`0xffac42d0`, carving routine `0xffac4230`) and its size tables in the image; decompiler output was navigation and the table bytes were read from the image.

**What block A is.** The word at physical `0x1000038` is slot 7 of a pointer table at physical `0x1000000` (slot n at `0x1000000 + 8n`). `0xffac42d0(1, nasid, 0)` rebuilds the table in the node window: slots 2 to 5 get 1 MiB regions at `(nasid << 38) + 0x30_0200_0000 + 0, 1, 2, 3 MiB`, slot 7 (block A) a 6 MiB region at `+4 MiB` (so `(nasid << 38) + 0x30_0240_0000`), slot 8 (block B) a 2 MiB region at `+10 MiB`. Before that, an early layout of the same slots (size `0xa000` for most, `0x10000` for block A) serves the first stage. Block A's first words are 8-byte fields carved by `0xffac4230` from the size table at `0xffbe7b48` (early copy `0xffbe7948`): a region entry gets the next address, an odd entry stores its value with the low bit cleared and consumes nothing. The 64 words of the header are `+0x00` to `+0x1f8`; the regions start after them, at block `+0x200`, so the running address begins there. The final word at `+0x1f8` receives the running address after the last region, which is where the heap starts. Block A's first word is overwritten with the tag `NODPDATA` (`0xffac5ac0`), and the first word of the heap receives the bytes left in the 6 MiB region. Odd entries store their value only when the third argument of `0xffac42d0` is 0; a zero entry in the early table stores `0x7f` instead and consumes nothing.

| Block A field | Content | Source |
|---|---|---|
| `+0x10` | node table, `0x1080` bytes: a count halfword, then one halfword per NASID, -1 for an absent node | size from the table; written by `0xffacbce0` (below) |
| `+0x18` | CPU table, `0x2000` bytes: 4-byte entries `{u16 id, u16 flags}` ended by `0xffff` | size from the table; written by `0xfface0b0` (below) |
| `+0x20` | the hwcfg block (KLCONFIG is 64 KiB into it) | stored by `0xffaa0100` after an `0xb0000`-byte arena allocation |
| `+0x28` | the constant `0x40_0000` | layout table entry `0x400001` (odd entry, value with bit 0 cleared) |
| `+0x30` | the PCFG area, `0x80000` bytes (tag `PCFG`, limit at area +40) | `0xffa47290` zeroes and tags it |
| `+0x38` | the local chip object, `0x80` bytes; its method table is the pointer at `+0x20` | read by `0xffa47290`; copied whole (`0x28` bytes) into the transfer area |
| `+0x40` to `+0x60` | five more `0x80`-byte records | role unread |
| `+0x68` to `+0x78`, `+0xd8` to `+0x178`, `+0x198` to `+0x1f0` | the constant `0xfe` | layout table, odd entries (role unread) |
| `+0x80` | the constant `0x180_0000` | layout table, odd entry |
| `+0x90` | `0x5480`-byte region | role unread |
| `+0x98` to `+0xa8`, `+0xb0` (`0x2000`), `+0xb8` to `+0xd0` | `0x80`-byte records and one `0x2000` region | role unread |
| `+0x180` | zero until set later (the L1 transport object for the node; `l1sc_send` and the I/O re-init read it) | layout table entry 0 |
| `+0x188`, `+0x190` | two `0x80`-byte records | role unread |
| `+0x1f8` | heap start (see below) | end of the carved regions |

Earlier readings give `+0x50` as an offset that `main_ptov` adds; the layout makes it the pointer to a `0x80`-byte record that `0xffa1c2e0` passes as the second argument to the translation helper, so "offset" is **inferred** to mean a field of that record. The regions total `0x8ac80` bytes after the `0x200`-byte header, so the heap is at `block A + 0x8ae80` and runs to the end of the 6 MiB region. It is an arena with magic `ARNA` (`0x414e5241`) created by `0xffac3290` (called from `0xffadd540`) and allocated from by `0xffac30c0`. The first `0xb0000` allocation for KLCONFIG is therefore at or after `(nasid << 38) + 0x30_0248_ae80`, plus the arena and allocation headers (sizes unread), and KLCONFIG 64 KiB further: **inferred** `GET_KLCONFIG_ADDR` for NASID 0 is at least `0x30_0249_ae80`, inside the type 6 range of section 2. Other allocations from the same arena may come first (not enumerated).

**Block B** is the 2 MiB region of slot 8 with the layout `0xffbe81c8` (early `0xffbe8048`, `0x800` bytes); its fields are in [sn2-runtime](../../sal/sn2-runtime.md#two-data-blocks-the-handlers-use).

**Other inputs.**

- Per NASID: the chip part number at `(nasid << 38) + 0x9_0000_0000` bits 27:12 (`0x4363` SHub 1, `0x4422` TIO), the memory configuration register `0x9_0001_0010`, and the node's inventory board (type `0x11`) with its bank components.
- The SHub real-time counter and its period.
- The per-CPU records at `0x1000000 + 8 * (n + 2)` (n = bits 26:23 of `cr.lid`) and the stack pointer table at `0x1000000 + 8 * (n + 9)`; their layout is the early-boot page's.

A one-node model needs: NASID 0 present, N CPU entries with ids that decode to NASID 0, one board with up to four bank records, and the registers above. **The two table writers (established, read in Ghidra and disassembly).** `0xffacbce0(chip)` takes a node's chip object (first halfword the NASID n) and writes the *local* block A's node table: halfwords 1 to n are set to `-1`, halfword n+1 to 0, and the count at halfword 0 to n+1. So the entry for NASID n is 0 (present) and every lower NASID is reset to `-1`; for NASID 0 the table is count 1, entry 0 = 0. It then calls `0xfface0b0(chip, cpu_table)`, `0xffaf64b0` and `0xffadd540(n, cpu_table)`. It is class-0 method slot 2: the descriptor `0xffc4bb80` holds `0xffacbcd0`, a `nop` bundle in front of `0xffacbce0`, and `main` calls it through the wrapper `0xffa1a910` at `0xffa19bec`, early, on the local chip object ([prom-reset.md](../../../devices/shub/prom-reset.md#slot-2-the-node-table-writer-answers-who-fills-block-as-node-table)). Established; that the object's class pointer selects class 0 is inferred (reviewed). `0xfface0b0` is the CPU table writer, also called directly from `main_two` (`0xffa1b5ac`): for slices 0 to 3 whose presence test `0xffa11710` is non-zero it stores the id `((nasid >> 7) & 0x1f) << 11 | slice << 7 | (nasid & 0x7f)` and then the flag word 1 if `0xffa99870` is non-zero, else 0; it ends with `{0xffff, 0}`. It writes from the start of the table each call, so what several nodes leave in one table was not read. `0xffad3a90`, the other candidate, is the `DisabledCpus`/`DisCpusReason` variable handler and writes neither table. The CPU start function `0xffac6340` appends 72-byte entries to the PCFG list through the chip object's method at table entry `+0x98`, not to the CPU table.

## Unknowns

- What sits at the SAL entry address `0x01ff_fc00`, and the effect of CPUs on memory-less nodes in the SRAT.
- The system-table vendor string and the chip clock-base method (`+0xb8`).
- Which condition selects the OEM revision `0x20101` DSDT rewrite, the SSDT bodies, and the HCDP table body (EFI's, [efi.md](efi.md)).
- The multi-node result in both tables, the roles of the other `0x80`-byte records, and the inventory record layout.
- Whether the kernel accepts the AS-bit-3 addresses as read (it uses `(base >> 38) & 0x7ff`; the rest was not traced).

## Review

Independent review of chips `fbcf305`, re-reading the SAL_B builders and the EFI image of `shub1snprom.bin` with the retools objdump and Ghidra export (the decompiler was used for navigation only; every constant below was read from disassembly or image bytes). The reviewer did not write the page. No Library holding of the ACPI specification exists (a `techpubs` search found none), so offsets rest on the PROM's stores and the kernel record.

**Confirmed (established).** RSDP (revision 2, length 0x24, OEM `SGI`, XSDT at `+0x18`, RSDT 0, two checksums), XSDT (four entries, length 0x44), MADT (type 7 entries of 12 bytes: processor id, `id >> 8`, `id & 0xff`, flags 4 or 5; local APIC address 0), SRAT (memory entry base, 64 GiB length, `+0x18` and flags 1; processor entry layout), SLIT (N, `0xff` fill, `10*d/d(i,i)` capped at `0xfe`), FADT (revision 3, 0xf4 bytes, PM profile 4, SCI 0x34, latencies, flags `0x1041`, lengths 4/2/4/8, `X_FIRMWARE_CTRL`, `X_DSDT` 0), FACS (0x40, version 1). Header: OEM id, table id, OEM revision. Memory map: PAL type 13 at `0x1000000`, 16 MiB, attribute `0x8000000000000009`, added by the first call only; port space type 12 64 MiB (`0x1fffffffc000000`, or `0xfcc000000` under the simulator signature); SHub 1 MMIO `(nasid<<38)+0x8_0000_0000` 32 GiB, TIO `nasid<<38` 64 GiB; flash window; the carve-out offsets and attributes; descriptor size 0x28 in SAL_B and 0x30, version 1 from `GetMemoryMap`. SAL table: 0xe0 bytes, `0x60` header, revision 0x0302, versions 0x0504, five entries with the stated values and the sizes 48/16/32/16/16 the kernel skips by. Runtime services: the call ids, `RuntimeServices` revision `0x0001000a` (header 0x70) and `SystemTable` revision `0x0001000a`, `ConvertPointer`'s endless loop, `SetVirtualAddressMap` statuses and SAL `0x02000013`. Kernel needs met: SRAT has a processor entry per CPU, port space has the UC bit, the PAL range is exactly 16 MiB (not over), the EFI revision is at `+8`, type 2 byte `+1` = 8 and type 5 mechanism 0.

**Changed.** The DSDT/SSDT claim: a later SAL_B builder exists (above). The XSDT creator revision is `0x44`, not 1. The ACPI 1.0 slot installs no EFI entry. The PM1a control word has SCI_EN set and the generic addresses carry zero widths. The carve-out addresses and the type 5 condition are given exactly; the tail figure is `len/31`. Variable and reset calls go through the SAL callbacks `0x3000` and `0x5000`, not a direct SAL id. Added `GetTime` always succeeding, the wakeup status value, and the `cr.iva` swap.

**Not settled.** Block A `+0x28`, the SSDT contents and trigger, SRAT domain for memory-less nodes, the runtime-slot assignments (the five static ones are relocations, the other six are filled at run time, so which slot holds `RtSN*` stays inferred). Nothing here rests on a model run.

## Review of the 350 summary, block A, I/O SAL and console (second reader)

Independent review of chips commits `e009a62`, `f7dba3f`, `962c477` and `a6cb292` by a reader who did not write them. Every address below was re-read in the IA-64 Ghidra module (`--sn2-prom --sal-runtime --no-analysis` with address ranges) and cross-checked against a flat objdump of the same image and the inflated SAL runtime ELF; no grade rests on a model run.

**Confirmed.** The pointer table at `0x1000000` and its carve (`0xffac42d0`, `0xffac4230`): block A at `(nasid << 38) + 0x30_0240_0000`, 6 MiB; block B at `+0x30_02a0_0000`, 2 MiB; the size table at `0xffbe7b48` and the `+0x28` constant `0x40_0000` (odd entry `0x400001`); so the SAL copy sits at node base `+ 0xe0_0000`, and the no-type-5 conclusion for bank 0 follows from the arithmetic as the page says.

**Changed.** The heap is at `+0x8ae80` (header `0x200` plus `0x8ac80` of regions). Added the `0xfe` filler entries, the `NODPDATA` tag and the heap's leading length word. The node-table and CPU-table writers are now read: `0xffacbce0` and `0xfface0b0`; `0xffad3a90` is not a writer. **Unread:** the caller of `0xffacbce0` and what several nodes leave in the two tables.
