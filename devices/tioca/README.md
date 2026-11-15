# TIOCA

Mode: **no-spec**. The TIOCA is the AGP bridge of the TIO generation: widget part number `0xe020`, manufacturer `0x24`, a
corelet of a [TIO](../tio/README.md). No specification is held. Every fact comes from SGI's own Linux Altix platform code
(linux-5.3 pin 4d856f72c10e: the register header, its provider header and the PCI/AGP provider), which defines names and
layouts and so grades **established** as software definitions, never as silicon measurements. Registers:
[registers.md](registers.md) (35 registers, 305 fields, and DMA and PIO map constants, which include the one header-named bit left out of the fields, bit 28 of `agp_dma_addr_extn`).

## What the code says it is

- **An AGP and PCI host bridge on a TIO widget (established).** It has an AGP side (graphics write buffer, AGP DMA read and
  write buffers, fast-write support) and a 32/64-bit PCI side with PCI interrupts INTA and INTB, with a "CRM" coretalk
  request module, a GART address translator and per-direction byte-swap controls (`control1`: system big-endian, AGP DMA, PCI DMA, PIO I/O,
  PIO memory and graphics-write swap). Coretalk is the TIO-side bus. Names in the header are taken from the vendor's "TIO AEGIS Programmers'
  Reference", which is not held.
- **The kernel treats it as a PCI bus with an AGP aperture.** Firmware reports the bus (asic type 4, a revision, the NASID of
  the closest node); the provider maps the registers (`sizeof` of the common record, as for other bridges), builds a GART, registers the
  PCI DMA interface and the error interrupt (vector `0x35`, whose handler makes one firmware call), and exposes the aperture to the
  AGP driver. The provider header names four erratum workarounds as masks of affected revisions: PV907908 (freezer loses a PIO data credit on a read
  response with a coretalk error), PV908234 (ATI configuration-space trouble after BIOS execution), PV895469 (AGP DMA write data mismatch with
  a merged cache line) and PV910244 (TLB invalidate of written GART entries may not happen on revision A). Only PV910244 is tested against the
  firmware-reported revision in the code read; the other three masks are defined and never referenced. The provider's `control1` bit 42 write
  is marked with that erratum number and a question mark, so tying the bit to it is a guess, and it disables GART prefetch citing a fifth erratum, PV930029,
  unconditionally.

## Bus address map (established, `tioca.h`)

| window | meaning |
|---|---|
| PCI `0xC0000000` and up | the 32-bit PCI window; split in the provider into direct (size 0, unusable because only 1 GiB of bus space is not PIO and the low 32 bits of the coretalk address come straight from the bus address) and GART-mapped |
| `0x80000000` to `0xBFFFFFFF` | graphics aperture (GART-mapped, owned by the AGP driver) |
| `0xC0000000` to `0xFFFFFFFF` | PCI GART-mapped window; with the graphics window, the whole aperture of 2 GiB |
| `0x40000000` and up, to 48 bits | AGP 48-bit direct window: node id, chiplet id and node offset taken straight from the bus address |
| 64-bit PCI | bits 63:60 packet type (1 coherent memory, 2 non-coherent PIO), bit 55 swap (the provider marks it currently unused), bits 53:0 coretalk address |

PIO windows (offsets in the TIOCA's widget space, constants `PIO_*`): internal registers 64 KiB, graphics write buffer, AGP DMA write and read
buffers (diagnostics), PCI type 0 and type 1 configuration windows of 16 MiB, PCI I/O, and two PCI memory windows (one at a programmable
PCI offset held in control 1 bits 31:24, one fixed to PCI 0 to `0xbfffffff`).

## GART (established, the provider)

- Aperture register: 10-bit field of size encoding (all ones for 4 MiB, one fewer low bit per doubling, zero for 4 GiB), a page size
  bit (set for 16 KiB), enable bits for AGP and PCI, and the bus base in place. The provider uses a 2 GiB aperture based at `0x80000000`.
- Table: a flat array of 8-byte entries in kernel memory (coherent, `GART_MEM_PARAM` set to 2, prefetch off), one per aperture page. The pointer register
  takes its coretalk address ORed with 1. An entry is the coretalk page address shifted right 12 with bit 63 valid.
- After changing entries the kernel flushes the GART TLB by setting a flush bit in control 2 and reading the register back, except that a
  coherent table needs no flush apart from the revision A erratum above.
- A GART fetch error is cleared through the alias registers of the status and multiple-error registers and enabled through the mask.

## Questions

- The AGP DMA address extension places a 16-bit node-id field at bit 20, which overlaps the one-bit "PIO memory type" the header puts at bit 28, and
  the header's own comment says bits 27:26 are unused: [Altix I/O cross-check questions](../../questions/altix-io-sn2-cross-check.md#tioca-agp-dma-extension-overlap).
- Which Altix product carries a TIOCA (graphics, an AGP slot): [PIC versus TIO by product](../../questions/altix-io-sn2-cross-check.md#pic-versus-tio-by-product).
  The error interrupt name in the interrupt header is a TIOCA-specific vector, so the platform expected the chip in the field.
- The provider's 48-bit direct check compares the whole AGP DMA extension word shifted right 20 with the target's upper node bits, so on that path bit 28 and the bits above 35 must read as zero. That makes the header's 16-bit node-id span the likelier error and the bit 28 name the lesser claim. Grade: inferred.
- Reset values are **unknown** for every register: neither the header nor the provider states one, and the provider's only reads of a register are read-modify-writes and the 48-bit direct check, none of which looks at a power-on value. The Prism kernel's copy of the provider was read with Ghidra (see Review) and agrees with the source; it adds no reset value. Routes not yet tried: the SNPROM images' TIOCA initialisation code (read with Ghidra, to see which registers firmware assumes at reset) and the TIO AEGIS Programmers' Reference, which is not held.

## Access (registers.toml `access`)

The header gives no direction. What the code read supports:

| register | access | grade | basis |
|---|---|---|---|
| `control1`, `control2`, `int_mask` | rw | established (software expectation) | the provider sets and clears single bits by reading the register and writing it back; `control2` is also read back after a flush |
| `int_status_alias`, `mult_error_alias` | rw | write established, clear-on-write inferred | the provider writes the one bit it wants cleared before unmasking GART fetch errors; readability unknown |
| `gart_aperature`, `gart_ptr_table` | rw | write established, read unknown | written once each at GART setup |
| `agp_dma_addr_extn` | rw | read established, write unknown | read by the 48-bit direct path |
| `id`, `status1`, `status2` | r | inferred | named as identification and status words; no code touches them |
| every other register | rw | unknown | no code read touches it; rw is the widest access, not a finding |

The Prism kernel was read with Ghidra at review (see Review): its provider makes the same register stores and reads as the v5.3 source. The `sgi-agp` module was not read; it is the AGP half only and reaches the registers through the provider.

## Review

Independent review on 2026-11-15 by a reviewer who did not write this page. Revision: chips commit 8468691 (read at main e001983). Sources: Linux v5.3 `arch/ia64/include/asm/sn/tioca.h`, `tioca_provider.h`, `intr.h`, `io.h`, `pcibus_provider_defs.h`, `arch/ia64/sn/pci/tioca_provider.c` and `drivers/char/agp/sgi-agp.c`, fetched singly from the tag; `include/asm-ia64/sn/tioca.h` at v2.6.12, v2.6.18 and v2.6.26. Binary: the Prism kernel (vmlinux 7.3.0, community build of a mainline SN2 tree, symbols but no DWARF), the 12 KiB holding the TIOCA provider functions, read with Ghidra (the IA-64 module, `DecompileAt`); decompiler output used for the stores' offsets and values only.

**Method.** A script parsed every mask in `tioca.h` and compared bit span and name with each field in `registers.toml`; offsets were checked against the struct comments; access and grade claims were checked against each use of a register in the provider and AGP files.

**Confirmed.**
- All 35 register offsets, including the `0x200` pointer and the `0x208` TLB array (eight entries of 8 bytes), against `struct tioca`.
- 305 of 305 fields in the TOML match the header's mask and shift (including the three destination-address registers and the five status, error and mask registers that share one macro block). The 306th header name, `CA_AGP_DMA_PIO_MEM_TYPE`, is carried only as a constant, as the page says.
- Access claims: the provider's read-modify-write of `control1`, `control2` and `int_mask`, its plain writes of `int_status_alias`, `mult_error_alias`, `gart_aperature` and `gart_ptr_table`, its read of `agp_dma_addr_extn` and the `control2` read-back after a flush; no other register is touched (eight in all, as the open question says). `id`, `status1` and `status2` are named as ID and status words and never touched; the grade "inferred" is right.
- Constants and prose: the aperture size encodings (0x3ff for 4 MiB down to 0 for 4 GiB), the 16 KiB page bit, the or-with-1 on the table pointer, `GART_MEM_PARAM` 2, prefetch cleared, the PV910244 flush sequence, the four erratum masks (only PV910244 is tested), PV930029 in the prefetch comment, error vector 0x35, ASIC type 4, the DMA map bases and sizes (1 GiB values over the 2 GB comments), the PIO windows and the 64-bit direct address layout.
- Ghidra on the Prism kernel (`tioca_bus_fixup`, `tioca_fastwrite_enable`, `tioca_dma_map`): the same sequence ships. Offset 0x08 or `0x40000000000` (bit 42); offset 0x10 cleared at bits 33:32 then set to 2 there, then bits 35:34 cleared; offsets 0x58 and 0x68 written `0x10` (the GART fetch error bit); offset 0x78 and-ed with `~0x10`; offset 0x28 written `0x80200007` (bits 0 to 2 set, size field 0x200, base `0x80000000`, so the 16 KiB page bit is set on that build's page size); offset 0x200 written with the table address or 1; fast write sets bit 6 of offset 0x08; the 48-bit direct path reads offset 0xe8 and shifts it right by 20; the error interrupt is registered at 0x35.
- The 2.6.18 and 2.6.26 headers are identical to v5.3; the 2.6.12 one differs only in the integer type names.
- No reset value is stated or implied anywhere read, so "unknown" for all is right.

**Mechanical fixes.**
- "306 header-named fields" in the intro: the registers file holds 305 fields; reworded.
- "The provider never reads a register before its first write" was false (the read-modify-writes read first); reworded to say no read looks at a power-on value.
- The 64-bit address row now notes the provider calls bit 55 (swap) currently unused.
- The page said the Prism kernel was not read with Ghidra; it has been now, with the result above.
- The cross-check question entry said the headers are unchanged at v2.6.12; only the type names differ there (left in the other file, noted here).

**Findings not fixed.**
- The 48-bit direct comment in the provider says the fixed upper node bits "come from the xxx register bits [5:0]". The PCI extension's `upper_node_offset` is exactly bits 5:0, so the comment points at a 6-bit field, and the AGP header's 16-bit field at bit 20 does not fit it either. This supports the page's reading that the node-id span is wrong, but it does not by itself place the field (bits 25:20 would be consistent with bit 28 and the unused 27:26). Grade stays inferred; a register specification is the only thing that settles it.
- The page's reasoning that the 48-bit check "makes bit 28 read as zero" holds only on that path; a set bit 28 would also fail the check if it were a genuine PIO memory type bit, so the check does not discriminate between the two readings except through the comment above.
- Register-level `grade = "established"` on all 35 rows still covers only name and offset; the 24 rows with access `rw` and no code touching them carry a placeholder access. The docs say so; a consumer reading the generated headers will not see it.

**Not checked.**
- The SNPROM images' TIOCA setup code (the only remaining route to reset or firmware-assumed values) was not read.
- The SLES 9 SN2 kernel (2.6.5) was not read; the Prism kernel is a community build, not an SGI release, so it confirms that the mainline provider code compiles to these stores, not what SGI shipped.
- The `sgi-agp` module was not disassembled.

**Cleared scope.** Register names, offsets, field positions, constants and the provider behaviours listed under Confirmed; the access column as a statement of what the code reads and writes, with the grades in the Access table. Not cleared: any reset value, access direction for the 24 untouched `rw` registers, the AGP DMA extension field layout, and that the TIOCA is present in any shipped product.
