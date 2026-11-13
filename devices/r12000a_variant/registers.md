<!-- generated from devices/r12000a_variant/registers.toml by defs-gen - do not edit, change the source -->

# R12000A mode-bit fields and performance control 0 syndrome field

Constants for the NEC VR12000A variant of the R12000 as its user's manual describes the differences from the R12000: the SysClkDiv and SCClkDiv fields of the boot mode word, the HSTL output mode field, and the 9-bit read-only syndrome that the variant places in bits 31:23 of CP0 register 25 performance control 0. This unit holds constants only. The capture rule and the open questions are in docs/r12000a_variant.md. Grades: established means the processor manual states it; inferred means a reasoned reading of the manual; unknown items are listed in the page.

Unit `r12000a_variant`, macro prefix `R12KA`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R12KA_MODE_HSTL_MASK` | 0x60000000 | established |  | Mask for the two-bit HSTL output mode field, bits 30:29 of the boot mode word. |
| `R12KA_MODE_HSTL_SHIFT` | 0x1d | established |  | Lowest bit of the two-bit HSTL output mode field, bits 30:29 of the boot mode word. It selects the HSTL level of the system interface outputs and the secondary cache interface outputs. |
| `R12KA_MODE_SCCLKDIV_MASK` | 0x380000 | established |  | Mask for the three-bit SCClkDiv field, bits 21:19 of the boot mode word. |
| `R12KA_MODE_SCCLKDIV_SHIFT` | 0x13 | established |  | Lowest bit of the three-bit SCClkDiv field, bits 21:19 of the boot mode word. |
| `R12KA_MODE_SCCLKDIV_TEST_CODE` | 0x7 | established |  | SCClkDiv code 111, a divisor of 4 that the manual says was added for testing silicon. |
| `R12KA_MODE_SYSCLKDIV_CODE_A_ONLY` | 0xc | established |  | SysClkDiv code 1100, the only code the variant's table adds. It selects a divisor of 7 between PClk and SysClk. The common R12000 has no entry for it, which the table's title, a change list, implies. The rejection is inferred. |
| `R12KA_MODE_SYSCLKDIV_MASK` | 0x1e00 | established |  | Mask for the four-bit SysClkDiv field, bits 12:9 of the boot mode word. |
| `R12KA_MODE_SYSCLKDIV_SHIFT` | 0x9 | established |  | Lowest bit of the four-bit SysClkDiv field, bits 12:9 of the boot mode word. |
| `R12KA_PERF_CTL0_SYNDROME_MASK` | 0xff800000 | established |  | Mask for the nine-bit syndrome field, bits 31:23 of CP0 register 25 performance control 0. |
| `R12KA_PERF_CTL0_SYNDROME_SHIFT` | 0x17 | established |  | Lowest bit of the nine-bit read-only syndrome, bits 31:23 of CP0 register 25 performance control 0. On the R12000 and R12000L these bits are unused and read as zero. |
