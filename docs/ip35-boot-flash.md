# IP35 boot flash: the address windows and the two PROM positions

The IP35 node controller (Bedrock) drives a boot flash that holds the CPU PROM code and the
system configuration and error records. This page records what the published sources settle
about the flash's size, its two selections and the windows that reach it, and what they leave
open. Nothing here was read from a fitted flash part or a board.

Grades: **established** (a published patent or a public header, quoted or cited below),
**inferred** (a reasoned reading), **unknown** (not settled, with the route that would settle it).

## Address windows

Both windows come from the public Linux SN1 header
`include/asm-ia64/sn/addrs.h` (Linux ia64 tree, commit `7570df54ef8c`, under
`CONFIG_IA64_SGI_SN1`). The macros are positions in the hub's address space, relative to
`HSPEC_BASE` and to each node's HSPEC base.

| Fact | Grade | Source |
| --- | --- | --- |
| The local boot space (LBOOT) is 128 MB and starts where the local register space ends: `LBOOT_BASE` is `LREG_LIMIT`, which is `HSPEC_BASE + 0x10000000 + 0x8000000`, so `HSPEC_BASE + 0x18000000`. | established | `addrs.h`, `LREG_*` and `LBOOT_*` macros |
| The header's comment on LBOOT says 256 MB, but `LBOOT_SIZE` is 0x8000000 (128 MB). The macro is taken as the size. | established (header); the comment is the conflict | `addrs.h`, LBOOT comment and `LBOOT_SIZE` |
| LBOOT has a stride of 0x2000000 (32 MB), with the comment "two PROMs, on 32M boundaries". The header defines no PROM count macro. | established (stride); two selections is the header comment's wording | `addrs.h`, `LBOOT_STRIDE` |
| The remote boot space (RBOOT) is 128 MB for each node, at `NODE_HSPEC_BASE(n) + 0x38000000`. | established | `addrs.h`, `RBOOT_SIZE` and `NODE_RBOOT_BASE` |
| Uncached reads in LBOOT reach the local hub's boot PROM and other devices on the directory bus. | established | `addrs.h`, LBOOT comment |

The header comment describes the SN1 platform. The Linux tree has no SN2 equivalent of these
macros, so the header does not show that the same layout applies to other nodes.

## Size and layout of the flash

| Fact | Grade | Source |
| --- | --- | --- |
| The memory directory unit supports a 16 MB flash PROM for boot code and for system configuration and error information. The text says "two 8 MB parts". | established | US 6,751,698 B1 (Bedrock), the memory-system description |
| The flash is reached through the LBOOT and RBOOT spaces of the HSPEC space. | established | US 6,751,698 B1, the boot-prom access passage |
| Before chip IDs are set up, the processor interface sends LBOOT accesses on node 0 to the local memory directory unit. After chip IDs exist, RBOOT can reach any node's PROM. | established | US 6,751,698 B1, the same passage |
| Mapping: HSPEC address 0 corresponds to PROM address 0, and HSPEC address 8 to PROM address 1, an 8-byte stride in HSPEC. The patent does not call this compression and does not explain it. | established (patent text); the mechanism is unknown | US 6,751,698 B1, the address-mapping passage |
| Whether ordinary reads keep their address inside the selected window (wrapping, masking, or bounds checks) is not described. | unknown | the patent gives no statement |

The two 8 MB parts are the patent's own words. The public header's two PROM positions on 32 MB
boundaries agree with two selections; the patent does not say which part sits at which position.

## Writes

| Fact | Grade | Source |
| --- | --- | --- |
| The memory directory unit supports byte writes to the flash PROM only. | established | US 6,751,698 B1, the write-width passage |
| The junk-bus passage lists the flash PROM among devices that take 64-bit reads and 16-bit writes. This conflicts with the byte-write statement. The two are not reconciled in the patent. | unknown (the conflict) | US 6,751,698 B1, the junk-bus passage |
| The flash and the junk bus cannot be reached during the memory directory unit's built-in self test. | established | US 6,751,698 B1, the self-test passage |
| No compressed byte-write interface is described in the patent. | unknown | the patent gives no statement |

## Unknown

- How the 16 MB splits between the two PROM positions, and each part's capacity and part number.
  The patent gives "two 8 MB parts" but no mapping of parts to positions.
- Whether ordinary reads wrap or mask an address that runs past the selected window.
- The write width the flash accepts: byte writes (memory directory unit text) or 16-bit writes
  (junk-bus text).
- What the 8-byte HSPEC stride means in hardware, beyond the patent's description.
- The command set the flash answers to, and the board's wiring from the flash to the memory
  directory unit.

Routes that would settle these: a published Bedrock or memory directory unit specification with
the boot-flash pages, or a read of the flash's own identification data from a board. Neither is
in this repository.

## Not imported

- The PROM's own probe of the flash, its environment or label records, and the way the PROM
  erases and programs the flash. These need the PROM image itself to re-derive (the CPU PROM
  payload `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`, described in
  [ip35-prom-md-config.md](ip35-prom-md-config.md)). They are not stated here until that
  disassembly is done.
- The store compression factor and the per-position command state. Neither appears in the
  patent text read here.
