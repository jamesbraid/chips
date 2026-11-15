# TIOCA

Mode: **no-spec**. The TIOCA is the AGP bridge of the TIO generation: widget part number `0xe020`, manufacturer `0x24`, a
corelet of a [TIO](../tio/README.md). No specification is held. Every fact comes from SGI's own Linux Altix platform code
(linux-5.3 pin 4d856f72c10e: the register header, its provider header and the PCI/AGP provider), which defines names and
layouts and so grades **established** as software definitions, never as silicon measurements. Registers:
[registers.md](registers.md) (35 registers, 306 header-named fields, DMA and PIO map constants).

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
| 64-bit PCI | bits 63:60 packet type (1 coherent memory, 2 non-coherent PIO), bit 55 swap, bits 53:0 coretalk address |

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
- Reset values are **unknown** for every register: neither the header nor the provider states one, and the provider never reads a register before its first write. Routes not yet tried: the SNPROM images' TIOCA initialisation code (read with Ghidra, to see which registers firmware assumes at reset) and the TIO AEGIS Programmers' Reference, which is not held.

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

The Prism kernel and its `sgi-agp` module were not read with Ghidra. The module is the AGP half only, and the register-touching code is already public source; a disassembly could only confirm that the same stores ship.
