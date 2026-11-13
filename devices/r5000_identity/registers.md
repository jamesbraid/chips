<!-- generated from devices/r5000_identity/registers.toml by defs-gen - do not edit, change the source -->

# MIPS R5000 family processor identity, reset entries, cache geometry and TLB size

Constants for the R5000 processor line as the NEC VR5000 user's manual and the MIPS R5000 overview describe it: the PRId and FCR0 identity words, the reset vector and the register values a cold reset and a warm entry set, the primary and secondary cache geometry, the joint TLB size and the physical and user address widths. This unit holds constants only; the CP0 and FCR31 field layouts are in the r5000_cp0 unit and the prose is in devices/r5000/README.md. Grades: established means the cited manual or overview states it; inferred means a value taken from public owner reports rather than a manual; unknown items are listed in the page.

Unit `r5000_identity`, macro prefix `R5K`.
Default source: NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R5K_COLD_RANDOM` | 0x2f | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Random is initialised to its upper bound, 47, by a cold reset. This is the 48-entry TLB's last index. |
| `R5K_COLD_WIRED` | 0x0 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Wired is initialised to zero by a cold reset. |
| `R5K_FCR0_OBSERVED` | 0x2310 | inferred | Public owner reports of O2 PRId and FCR0 words (Usenet) | Complete FCR0 word reported for O2 systems by their owners. The packet calls FCR0 the read-only floating-point identity register. Graded inferred for the same reason as the PRId word. No field layout for FCR0 is taken from this source. |
| `R5K_IMP_VR5000` | 0x23 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Implementation byte the manual gives for this processor line, bits 15:8 of PRId. It names the line, not a revision. |
| `R5K_PHYS_ADDR_BITS` | 0x24 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Physical address width of the NEC part. |
| `R5K_PRID_IMP_MASK` | 0xff00 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the implementation byte of PRId, bits 15:8. |
| `R5K_PRID_IMP_SHIFT` | 0x8 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | The implementation byte of PRId is bits 15:8. The revision byte is bits 7:0, read as a major nibble in bits 7:4 and a minor nibble in bits 3:0. The manual reserves the high halfword, bits 31:16, and this unit defines nothing there. |
| `R5K_PRID_OBSERVED` | 0x2321 | inferred | Public owner reports of O2 PRId and FCR0 words (Usenet) | Complete PRId word reported for O2 systems by their owners. It is graded inferred because the packet records it from owner reports, not from a manual or a documented capture, and the message identifiers are not recorded here. Bits 15:8 agree with the manual's implementation byte. This is one observed tuple, not a promise for every part. |
| `R5K_PRID_REV_MASK` | 0xff | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Mask for the revision byte of PRId, bits 7:0. |
| `R5K_PRIMARY_CACHE_BYTES` | 0x8000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Size of each primary cache, instruction and data. The manual and the overview agree. |
| `R5K_PRIMARY_LINE_BYTES` | 0x20 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Line size of each primary cache. |
| `R5K_PRIMARY_SETS` | 0x200 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Sets per primary cache: 32768 bytes divided by two ways and 32-byte lines. |
| `R5K_PRIMARY_WAYS` | 0x2 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Associativity of each primary cache. |
| `R5K_RESET_VECTOR` | 0xffffffffbfc00000 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Cold reset address. It is unmapped and uncached. Soft reset and NMI also enter at this vector. |
| `R5K_SECONDARY_LINE_BYTES` | 0x20 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Secondary block size: eight words, or 32 bytes, for SB code 1. That is the only SB code the manual defines for this part. |
| `R5K_SECONDARY_WAYS` | 0x1 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | The secondary cache is direct-mapped. |
| `R5K_SYSCLK_MAX_MHZ` | 0x64 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Maximum system interface clock the overview gives. The overview describes a 200 MHz core. This is a processor interface limit, not an O2 bus clock. |
| `R5K_TLB_ENTRIES` | 0x30 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Entries in the joint TLB. Each entry maps an even and an odd page. |
| `R5K_USER_ADDR_BITS` | 0x28 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Extended user address width. With extended addressing off, the 32-bit segment view applies. |
| `R5K_WARM_STATUS_SET` | 0x500004 | established | NEC VR5000/VR5000A 64-/32-bit Microprocessor User's Manual, U11761EJ6V0UM00, sixth edition, April 2001 | Status bits that a soft reset or NMI sets: ERL (bit 2), BEV (bit 22) and SR (bit 20). Those are the only Status bits a warm entry changes. The warm entry ORs this mask into the previous Status value. |
