# R10000 family CP0 CacheErr fields for secondary-cache errors

<!-- generated from defs/r10000_secondary_cache_ecc.toml by defs-gen - do not edit, change the source -->

Constants for the CP0 CacheErr register as the R10000 reports a secondary-cache error: the unit select in bits 31:30, the uncorrectable data-error way field, the tag-error field and the secondary block index. This unit holds constants only. The delivery rule, the check matrix and the syndrome classification are in docs/r10000_secondary_cache_ecc.md. Grades: established means the processor manual states it; inferred means a reasoned reading of the manual; unknown items are listed in the page.

Unit `r10000_secondary_cache_ecc`, macro prefix `R10K`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R10K_CACHEERR_D_MASK` | 0xc000000 | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Mask for the two-bit D field, bits 27:26 of CP0 CacheErr. |
| `R10K_CACHEERR_D_SHIFT` | 0x1a | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Lowest bit of the two-bit D field, bits 27:26, which identifies an uncorrectable secondary data error by way. |
| `R10K_CACHEERR_SIDX_MASK` | 0x7fffc0 | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Mask for the 17-bit secondary block index, bits 22:6 of CP0 CacheErr. The index is PA[22:6] for a 64-byte block and PA[22:7] for a 128-byte block. |
| `R10K_CACHEERR_SIDX_SHIFT` | 0x6 | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Lowest bit of the secondary block index, bits 22:6 of CP0 CacheErr. |
| `R10K_CACHEERR_TA_MASK` | 0x3000000 | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Mask for the two-bit TA field, bits 25:24 of CP0 CacheErr. |
| `R10K_CACHEERR_TA_SHIFT` | 0x18 | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Lowest bit of the two-bit TA field, bits 25:24, which identifies a secondary tag error. |
| `R10K_CACHEERR_UNIT_SECONDARY` | 0x2 | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Unit select value for a secondary-cache error, binary 10 in bits 31:30. |
| `R10K_CACHEERR_UNIT_SHIFT` | 0x1e | established | MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 274-276 | Lowest bit of the two-bit CacheErr unit select, bits 31:30. |
