<!-- generated from devices/r10000_identity/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 d2842a5c402c77293eed3a25235d7f9e4e9e93075e76f5b4f972fabfc15d48aa -->

# R10000 family processor identity and secondary-cache configuration fields

Constants for the MIPS R10000 processor family as the public Linux kernel identifies it: the implementation and revision fields of the PRId register, the revision split that separates the R16000 from the R14000, and the Config fields that set the secondary cache size and line. This unit holds constants only; the processor's register layouts are in devices/r10000_identity/README.md. Grades: established means a public driver file says it; inferred means a reasoned reading; unknown items are listed in the page.

Unit `r10000_identity`, macro prefix `R10K`.
Default source: Linux v6.6 MIPS headers and CPU driver.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R10K_CONF_SB_BIT` | 0xd | established | Linux 6.6 MIPS Config register definitions | Config bit 13, the secondary cache line-size bit. Clear selects 64-byte lines and set selects 128-byte lines. |
| `R10K_CONF_SB_MASK` | 0x2000 | established | Linux 6.6 MIPS Config register definitions | Mask for Config bit 13, the secondary cache line-size bit. |
| `R10K_CONF_SS_MASK` | 0x70000 | established | Linux 6.6 MIPS Config register definitions | Mask for the three-bit Config secondary cache size field, bits 18:16. |
| `R10K_CONF_SS_SHIFT` | 0x10 | established | Linux 6.6 MIPS Config register definitions | Lowest bit of the three-bit Config secondary cache size field, bits 18:16. |
| `R10K_IMP_R10000` | 0x9 | established | Linux 6.6 MIPS processor identity definitions | Implementation byte of the R10000. The driver's R10000 case covers this value. |
| `R10K_IMP_R12000` | 0xe | established | Linux 6.6 MIPS processor identity definitions | Implementation byte of the R12000. The driver's R12000 case covers this value. |
| `R10K_IMP_R14000` | 0xf | established | Linux 6.6 MIPS processor identity definitions | Implementation byte shared by the R14000 and the R16000. The driver's comment says the two share the value; the revision split below tells them apart. |
| `R10K_PRID_IMP_MASK` | 0xff00 | established | Linux 6.6 MIPS processor identity definitions | Mask for the implementation byte of PRId, bits 15:8. |
| `R10K_PRID_IMP_SHIFT` | 0x8 | established | Linux 6.6 MIPS processor identity definitions | The implementation byte of PRId is bits 15:8. The revision byte is bits 7:0. |
| `R10K_PRID_REV_MASK` | 0xff | established | Linux 6.6 MIPS processor identity definitions | Mask for the revision byte of PRId, bits 7:0, printed as major and minor nibbles. |
| `R10K_R16000_DISPLAY_MAJOR_OFFSET` | 0x2 | inferred | Linux v6.6 MIPS headers and CPU driver | OpenBSD subtracts two from the major revision nibble when it prints an R16000. The printed revision is therefore the raw major nibble minus two: the printed 3.0 of a 1.0 GHz part is raw major 5, and a printed 2.1 is raw major 4. Read from a driver's print code, so it is a software convention, not a register value. |
| `R10K_R16000_PRID_1GHZ` | 0xf50 | inferred | Linux v6.6 MIPS headers and CPU driver | CP0 PRId low 16 bits of the 1.0 GHz R16000 that prints as revision 3.0. Inferred, not read: the PROM banner prints f50 for four processors, and the link from that print to a raw PRId read depends on a review of a PROM image that is not public. No raw read on a part exists. |
| `R10K_R16000_REV_MAJOR_MIN` | 0x3 | established | Linux 6.6 MIPS CPU probe | For implementation 0x0f, a revision whose major nibble is 3 or more is an R16000. The driver's test is major nibble greater than 2. Revisions 1.x and 2.x are R14000 by the same test. |
| `R10K_R16000_TLB_ENTRIES` | 0x40 | inferred | Linux v6.6 MIPS headers and CPU driver | TLB entry count the driver sets for implementation 0x0f. This is what software expects, not a count read from a part. |
| `R10K_SCACHE_LINE_BASE_BYTES` | 0x40 | established | Linux 6.6 MIPS R4K cache setup | The driver's secondary cache line size: 64 bytes shifted left by Config bit 13 (SB). SB 0 gives 64 bytes and SB 1 gives 128 bytes. |
| `R10K_SCACHE_SIZE_UNIT` | 0x80000 | established | Linux 6.6 MIPS R4K cache setup | The driver's secondary cache size: this unit shifted left by the Config SS field. SS 0 is 512 KB, SS 1 is 1 MB, SS 2 is 2 MB, SS 3 is 4 MB and so on. |
| `R10K_SCACHE_WAYS` | 0x2 | established | Linux 6.6 MIPS R4K cache setup | The driver's secondary cache associativity for every R10000-family part: two ways. |
