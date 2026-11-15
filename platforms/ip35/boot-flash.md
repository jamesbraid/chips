# IP35 boot flash: the address windows and the two PROM positions

The IP35 node controller (Bedrock) drives a boot flash that holds the CPU PROM code and the
system configuration and error records. This page records what the published sources settle
about the flash's size, its two selections and the windows that reach it, and what they leave
open. Except for the environment records, which match a captured Origin 300 boot, nothing here was read from a fitted flash part or a board.

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
| Reads: HSPEC address maps one to one to PROM address within the given space, and every read size (doubleword, word, half-word, byte) is supported. Writes: HSPEC address maps eight to one to PROM address, so HSPEC address 0 is PROM address 0 and HSPEC address 8 is PROM address 1, an 8-byte stride in HSPEC. The patent does not explain the write mapping. An earlier version of this row applied the 8-byte stride to all accesses; the patent gives it for writes only. | established (patent text); the mechanism is unknown | US 6,751,698 B1, the flash PROM passage under Memory System |
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
- What the 8-byte HSPEC stride for writes means in hardware, beyond the patent's description.
- The command set the flash answers to, and the board's wiring from the flash to the memory
  directory unit.

Routes that would settle these: a published Bedrock or memory directory unit specification with
the boot-flash pages, or a read of the flash's own identification data from a board. Neither is
in this repository.

## CPU configuration block at 0x60

The block is 80 bytes at flash offset 0x60. The PROM reads it through the boot-space window.
The layout is graded observed because the iris emulator maintainer reported the PROM's
behaviour; the disassembly of the shipped 6.210 PROM, in
[ip35-board-word-and-config-block.md](../../questions/ip35-board-word-and-config-block.md#2-the-80-byte-configuration-block-and-its-machine-type-field),
grades the same offsets established.

| Offset | Content | Grade |
| --- | --- | --- |
| +0x00 | 0x15 | observed |
| +0x04 | CPU mode word, from the speed row | observed |
| +0x08 | `ip27conf` (0x69703237636f6e66) | observed |
| +0x10 | CPU clock, Hz | observed |
| +0x18 | bus clock, Hz | observed |
| +0x20 | 0x1312d0 (1,250,000) | observed |
| +0x28 | 1 (ECC enable) | observed |
| +0x2c | 0x10 (flash timing) | observed |
| +0x30 | machine type: 0, 1 or 2 | observed |
| +0x34 | 0 (checksum adjustment; rule unknown) | observed |
| +0x3c | 0x10 (flash write timing) | observed |

The comparison, graded observed as reported: the PROM checks +0x00, 0x04, 0x08, 0x10, 0x18,
0x28, 0x2c, 0x30 and 0x3c. The reference comes from the board's EEPROM text record, or from
the speed row when that record is missing. A difference prints "CPU configuration values
from board EEPROM/PSC did not match" and asks for a reflash. The disassembly's message text
is the same.

Row selection, established from the 6.210 disassembly: class 0x4000 (Fuel) uses row index
0x20 plus the low nibble of the board word; class 0x2000 uses 0x30 plus the low nibble.
A Tezro board word is outside class 0x4000 (the class page infers IP53 is class 0x2000), so
the Fuel rows do not apply to it.

Early mode-word check, established from the 6.210 disassembly: the reset path writes flash
+0x04 to CP0 Config and compares the readback. A mismatch disables that processor slice,
prints a permanent-disable notice and returns to normal start-up.

Reference mode words, one row each:

- 800 MHz, 200 MHz bus, 4 MB cache, tap 0xa, machine type 2: 0x549baf85. Observed on a real
  Fuel, from a public transcript of a `flash -f` run on a public firmware-update page. The
  transcript is not a capture held in these repositories.
- 500 MHz: the value the iris emulator uses is a chosen emulator value, not read from
  hardware or the PROM. The PROM's own 500 MHz rows are 0x549aa985 (2 MB) and 0x549ca985
  (8 MB).

## Environment records that disable absent CPUs

When a processor position is empty, the PROM writes a record that marks it disabled into the
environment store. The store starts at flash offset 0x9e0100 (8 MiB + 0x1e0100). Each absent
position takes the next 64-byte slot.

One record:

| Offset in record | Content | Bytes |
| --- | --- | --- |
| 0x00 | 0x10 | 1 |
| 0x01 | ASCII `Disable` | 7 |
| 0x08 | ASCII position letter, A to D | 1 |
| 0x09 | zero | 7 |
| 0x10 | ASCII `32: CPU failed early init.` | 26 |
| 0x2a | zero | 22 |

The lengths total 64 (1 + 7 + 1 + 7 + 26 + 22).

| Slot | Flash offset | Position | Grade |
| --- | --- | --- | --- |
| 0 | 0x9e0100 | B | observed |
| 1 | 0x9e0140 | D | observed |
| 2 | 0x9e0180 | the third absent position | inferred (offset extrapolated from the stride) |

Slots 0 and 1 are observed from a captured Origin 300 boot's environment store, including the
byte layout. The PROM writes these records after its failed-start recovery has given up on an
empty position; that is observed PROM behaviour. Pre-seeding a fresh store with them is emulator
policy, not hardware.

## Not imported

- The PROM's own probe of the flash and the way the PROM erases and programs the flash. These
  need the PROM image itself to re-derive (the CPU PROM payload
  `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`, described in
  [ip35-prom-md-config.md](prom-md-config.md)). The configuration block and the environment
  records are covered above.
- The per-position command state. It does not appear in the patent text. The write stride is
  eight HSPEC bytes per PROM byte (see the table above).
