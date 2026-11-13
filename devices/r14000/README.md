# R14000

This page covers the MIPS R14000 processor as the public sources describe it: the identity word, the Config register's reset and write rules, the big-endian narrow store lanes, the partial LWR result, and what is unknown. The R14000 is the processor in the Origin 300 and Fuel systems. The constants for the Config fields are in [devices/r10000_config/registers.toml](../r10000_config/registers.toml), generated to [devices/r10000_config/registers.md](../r10000_config/registers.md). The identity word is in [devices/r10000_identity/README.md](../r10000_identity/README.md), the performance counters in [devices/r14000_perf_counters/README.md](../r14000_perf_counters/README.md).

No R14000 processor manual was read for this page. The published manuals cover the R10000 and R12000 members of the family, not the R14000. So each fact below is one of two things. Either a manual states it for a part the R14000 is not, and the page says the R14000 use is inferred, or the fact is about the R14000 itself and comes from a public driver.

## Sources and grades

- NEC, *VR10000 Series 64-/32-bit Microprocessor User's Manual*, fourth edition, March 2001, U10278EJ4V0UM00. Its preface says the R12000 in the manual stands for the VR12000, VR12000A and VR12000L, so its processor scope is the R10000 and the R12000 family. Cited below as "the VR10000 manual".
- NEC, *VR5000, VR10000 64-Bit Microprocessor Instruction User's Manual*, first edition, August 2000, U12754EJ1V0UMJ1. Cited below as "the instruction manual".
- Linux 6.6 processor identity and cache-setup files, cited in [devices/r10000_identity/README.md](../r10000_identity/README.md).

Established means the cited manual states the fact for the processor it names. Inferred means the fact is applied to the R14000 from the family, or it is a reasoned reading the manual does not state in those words. Unknown means the fact is not settled. Unknown items are listed at the end with what would settle them.

## Config register

The Config layout is the one the VR10000 manual gives for the R10000 and R12000 columns of its field table. Its constants are in [devices/r10000_config/registers.toml](../r10000_config/registers.toml). The R14000 use of that layout is inferred.

- **Reset load.** A power-on or cold reset takes Config bits 24:0 from the mode word. The manual says so in the Config register section (printed page 230). Established for the R10000 and R12000. Inferred for the R14000.
- **Hardwired fields.** The primary cache size fields, IC at bits 31:29 and DC at bits 28:26, are hardwired to binary 011, which is 32 Kbytes. The reserved fields read as zero. Established for the R10000 and R12000 (printed page 230). Inferred for the R14000.
- **Bit 24.** On the R12000 this bit is the delayed speculative dirty mode bit, DSD. The manual makes it read-only and settable only at boot. Established for the R12000 (printed page 182, footnote to Table 8-1, and page 230). On the R10000 the bit is reserved. Whether the R14000 has the bit is unknown.
- **Secondary-cache fields.** Bits 18:16 (SS) and bit 13 (SB) are in [devices/r10000_identity/README.md](../r10000_identity/README.md), with the Linux reading of them.
- **Write rule.** The manual names bit 24 as read-only and the hardwired fields as fixed. It gives no full write mask for the other fields. So the set of bits that software may change after reset is not established for any family member, the R14000 included.
- **Soft reset.** A soft reset does not reinitialize the general purpose, CP0 and CP1 registers, or the primary and secondary caches. The manual gives this in its soft reset section (printed page 179). Established for the R10000 and R12000. Inferred for the R14000. A soft reset is a different entry from a cold reset, so a cold reset value does not settle this.

## Uncached narrow stores, big-endian

For uncached stores of one byte or one halfword, the valid SysAD lanes depend on the address and on the MemEnd mode bit, which is Config bit 15. With MemEnd set, the byte or halfword is placed at its big-endian lane. The manual gives the data-cycle lane rule, with an example at address offset 1, in its system interface encoding (printed pages 119 and 120). The instruction manual gives the Store Byte and Store Halfword pseudocode, which takes the low 8 or 16 bits of the source register. Combining the two gives this table, for big-endian mode.

| Address modulo 8 | SB valid lane | SH valid lanes |
|---:|---:|---|
| 0 | 63:56 | 63:48 |
| 1 | 55:48 | unaligned, not a valid halfword access |
| 2 | 47:40 | 47:32 |
| 3 | 39:32 | unaligned |
| 4 | 31:24 | 31:16 |
| 5 | 23:16 | unaligned |
| 6 | 15:8 | 15:0 |
| 7 | 7:0 | unaligned |

The SB lane carries the source register's bits 7:0. The SH lanes carry bits 15:8 and then 7:0. Established for the R10000 and R12000 family. Inferred for the R14000. No R14000 bus capture was checked.

## Partial LWR in 64-bit mode

LWR loads the high part of an unaligned word. When the word's sign bit (bit 31) is not among the loaded bytes, the manual leaves bits 63:32 implementation specific. Those bits are either unchanged or take the value of the unloaded bit 31 (instruction manual, LWR section and Table 1-36, printed page 126). In big-endian mode this happens at address offsets 0 to 2. In little-endian mode it happens at offsets 1 to 3.

The manual permits both results and names neither as the R14000's. Established that the manual permits both. The R14000 choice is unknown.

## Unknown, and what would settle it

- **R14000 Config write mask.** The VR10000 manual gives the read-only bit and the hardwired fields, and no full write mask. Settled by an R14000 processor manual, or by a write test on a part that writes each field and reads it back after a cold reset.
- **Whether the R14000 has Config bit 24 as DSD.** Settled by an R14000 processor manual, or a boot-mode test on a part.
- **Soft reset preservation on the R14000.** The manual's rule is for the R10000 and R12000. Settled by an R14000 manual, or by reading the Config and CP0 registers after a soft reset (not after a cold reset) on a part.
- **R14000 narrow big-endian store lanes.** The table above is the family rule. Settled by an R14000 manual, or a bus capture of an uncached byte or halfword store on a part with MemEnd set.
- **R14000 partial LWR upper word.** The manual permits both results. Settled by an R14000 manual's instruction description, or a register test on a part that loads a partial word with bit 31 clear and reads bits 63:32 before and after.

These unknowns are also listed in [questions/README.md](../../questions/README.md).
