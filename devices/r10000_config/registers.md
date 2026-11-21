<!-- generated from devices/r10000_config/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 362dcb7df00a43068f61a7a68c09c0919ae82e712b4e06d619267bedd01d0bee -->

# R10000 family CP0 Config register field positions and hardwired primary-cache codes

Constants for the CP0 Config register as the NEC VR10000 and VR12000 user's manual lays it out: the field positions for the boot-loaded clock, endian, reset-mode and secondary-cache fields, the R12000 delayed-speculative-dirty bit, the hardwired primary-cache size codes, and the bits that a reset loads from the mode word. The secondary-cache size and line fields are in the r10000_identity unit. This unit holds constants only; the reset and write rules, and what is unknown for the R14000, are in devices/r14000/README.md. Grades: established means the processor manual states it for the R10000 and R12000 columns it names; the R14000 is not checked against a processor manual, so its use there is inferred in the page.

Unit `r10000_config`, macro prefix `R10KCFG`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R10KCFG_BE_BIT` | 0xf | established |  | Config bit 15, MemEnd. Set selects big-endian memory and device byte lanes; clear selects little-endian. |
| `R10KCFG_BE_MASK` | 0x8000 | established |  | Mask for Config bit 15, MemEnd. |
| `R10KCFG_CACHE_32K_CODE` | 0x3 | established |  | Binary 011 in the DC and IC fields: the primary caches are hardwired to 32 Kbytes. The manual gives this code for both fields. |
| `R10KCFG_DC_MASK` | 0x1c000000 | established |  | Mask for the three-bit DC field, bits 28:26 of Config. |
| `R10KCFG_DC_SHIFT` | 0x1a | established |  | Lowest bit of the three-bit DC field, bits 28:26, the primary data cache size. The field is hardwired, not loaded from the mode word. |
| `R10KCFG_DSD_BIT` | 0x18 | established |  | Config bit 24. On the R10000 it is reserved and reads zero. On the R12000 it is the delayed speculative dirty (DSD) mode bit, read-only and settable only at boot. The R14000 state is unknown. |
| `R10KCFG_DSD_MASK` | 0x1000000 | established |  | Mask for Config bit 24, the R12000 DSD bit. |
| `R10KCFG_EC_MASK` | 0x1e00 | established |  | Mask for the four-bit EC field, bits 12:9 of Config. |
| `R10KCFG_EC_SHIFT` | 0x9 | established |  | Lowest bit of the four-bit EC field, bits 12:9, SysClkDiv. Its value comes from the mode word at reset. |
| `R10KCFG_IC_MASK` | 0xe0000000 | established |  | Mask for the three-bit IC field, bits 31:29 of Config. |
| `R10KCFG_IC_SHIFT` | 0x1d | established |  | Lowest bit of the three-bit IC field, bits 31:29, the primary instruction cache size. The field is hardwired, not loaded from the mode word. |
| `R10KCFG_MODE_BITS_MASK` | 0x1ffffff | established |  | Bits 24:0 of Config. A power-on or cold reset loads them from the mode bits, and the rest of the register is not loaded this way. |
| `R10KCFG_PM_MASK` | 0x180 | established |  | Mask for the two-bit PM field, bits 8:7 of Config. |
| `R10KCFG_PM_SHIFT` | 0x7 | established |  | Lowest bit of the two-bit PM field, bits 8:7, PrcReqMax. The R10000 and R12000 columns both name it. |
| `R10KCFG_SC_MASK` | 0x380000 | established |  | Mask for the three-bit SC field, bits 21:19 of Config. |
| `R10KCFG_SC_SHIFT` | 0x13 | established |  | Lowest bit of the three-bit SC field, bits 21:19, SCClkDiv. Its value comes from the mode word at reset. |
| `R10KCFG_SK_BIT` | 0xe | established |  | Config bit 14, SCCorEn, the secondary-cache correction enable. |
| `R10KCFG_SK_MASK` | 0x4000 | established |  | Mask for Config bit 14, SCCorEn. |
