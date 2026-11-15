# Synergy (Itanium processor-bus ASIC, SN1 IA-64 node)

Mode: **no-spec**. No Synergy specification is held; every fact is from SGI's own Linux platform code for the SN1 IA-64
node, so offsets and access sequences are `established` as software expectations and meanings are graded where each is
stated. The chip's role, placement and the platform around it are in
[platforms/sn1-ia64/synergy.md](../../platforms/sn1-ia64/synergy.md); the register table is
[registers.md](registers.md), generated from `registers.toml`.

## What is known in one place

- One Synergy per Itanium front-side bus, two per node, each between one Bedrock processor interface and two Itanium slots.
- Reached at physical `0xe0000000000` plus the offset by a processor on its bus (one 64-bit store), and from any node through
  the Bedrock's hub special space at the remote register window plus `0x04000000` or `0x05000000` (a write is four 64-bit
  stores of 16 bits each at offset times four; a read is one load at the plain offset).
- Registers the software touches: eight interrupt vector masks (A and B per 64 vectors), `FSB_CONFIG` (`0x450`), a cache-way
  disable mask for its L4 (`0xae0`), two registers polled as a PIO write barrier (`0x330`, `0x338`), and eight performance
  registers.
- Nothing is known of resets or of any register outside those 20 offsets. The questions page lists the routes tried.

## Unknowns and why

See [questions/sn1-ia64-synergy-registers.md](../../questions/sn1-ia64-synergy-registers.md).
