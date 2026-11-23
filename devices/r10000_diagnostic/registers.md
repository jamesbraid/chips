<!-- generated from devices/r10000_diagnostic/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 651edc565a4b7f3c622ffdd35f85c717e6bef176606d4da7a24c00089762d871 -->

# R10000 family CP0 Diagnostic register (branch diagnostic): field positions

Constants for the CP0 register 22 Diagnostic register of the MIPS R10000 family, as the NEC VR10000 and VR12000 manual lays it out: the branch-table operation and index fields, the branch state and mode fields, the branch return cache disable, the R12000 global-history and branch-target-cache bits. The R14000 and R16000 layouts are not in any cited manual; the R12000 layout is applied to them as an inferred assumption, stated in devices/r10000_diagnostic/README.md.

Unit `r10000_diagnostic`, macro prefix `R10KDIAG`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R10KDIAG_BPIDX_R10K_MASK` | 0xff8 | established |  | Mask for the R10000 branch-table index, bits 11:3 of the Diagnostic register (BPIdx). The manual gives the index as the virtual address bits 11:3. |
| `R10KDIAG_BPIDX_R12K_MASK` | 0x3ff8 | established | NEC VR10000 Series user's manual, U10278EJ4V0UM00, fourth edition, printed pages 235-237 | Mask for the R12000 branch-table index, bits 13:3 of the Diagnostic register (BPIdx), widened from the R10000 field. |
| `R10KDIAG_BPMODE_MASK` | 0x30000 | established |  | Mask for the two-bit branch mode field, bits 17:16 of the Diagnostic register (BPMode). Read-write, reset to 00. |
| `R10KDIAG_BPOP_MASK` | 0x3 | established |  | Mask for the two-bit branch-table operation field, bits 1:0 of the Diagnostic register (BPOp). Read-write. |
| `R10KDIAG_BPSTATE_MASK` | 0xc000 | established |  | Mask for the two-bit branch state field, bits 15:14 of the Diagnostic register (BPState). Read and written through the branch-table operation. |
| `R10KDIAG_DBRC_BIT` | 0x16 | established |  | Bit 22 of the Diagnostic register, DBRC: set disables the branch return cache. |
| `R10KDIAG_DBRC_MASK` | 0x400000 | established |  | Mask for bit 22, the branch return cache disable. |
| `R10KDIAG_R12K_BTAC_DIS_BIT` | 0x1b | established | NEC VR10000 Series user's manual, U10278EJ4V0UM00, fourth edition, printed pages 235-237 | R12000 only: bit 27 of the Diagnostic register disables the branch target address cache. The Linux header names it R10K_DIAG_D_BTAC. |
| `R10KDIAG_R12K_BTAC_DIS_MASK` | 0x8000000 | established | NEC VR10000 Series user's manual, U10278EJ4V0UM00, fourth edition, printed pages 235-237 | Mask for bit 27, the R12000 branch target address cache disable. |
| `R10KDIAG_R12K_GHIST_ALL_BIT` | 0x1a | established | NEC VR10000 Series user's manual, U10278EJ4V0UM00, fourth edition, printed pages 235-237 | R12000 only: bit 26 of the Diagnostic register selects all eight global-history bits. The Linux header names it R10K_DIAG_E_GHIST. |
| `R10KDIAG_R12K_GHIST_COUNT_MASK` | 0x3800000 | established | NEC VR10000 Series user's manual, U10278EJ4V0UM00, fourth edition, printed pages 235-237 | R12000 only: bits 25:23 give the global-history count when bit 26 is clear. |
