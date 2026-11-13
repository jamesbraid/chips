<!-- generated from devices/r10000_fpu/registers.toml by defs-gen - do not edit, change the source -->

# R10000 family floating-point control register cause bits

Constants for the floating-point control register (FCSR, the NEC manual's FSR) of the MIPS R10000 family, for the Cause E bit that reports an unimplemented operation. The FS and rounding fields are not here: their bit positions were not read for this unit. This unit holds constants only; the rule that sets E is in devices/r10000_fpu/README.md. Grades: established means the processor manual states it; inferred means a reasoned reading of the manual; unknown items are listed in the page.

Unit `r10000_fpu`, macro prefix `R10K`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `R10K_FCSR_CAUSE_E_BIT` | 0x11 | established |  | Bit 17 of the floating-point control register, the Cause E bit for an unimplemented operation. The Cause field is bits 17:12, and E is its first listed bit. E has no enable bit and is always enabled. |
| `R10K_FCSR_CAUSE_E_MASK` | 0x20000 | established |  | Mask for the Cause E bit, bit 17 of the floating-point control register. |
