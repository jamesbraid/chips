# PIC bits outside the census

<!-- generated from defs/pic_extra.toml by defs-gen - do not edit, change the source -->

Unit `pic_extra`, macro prefix `PIC`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `DEVICE_SWAP_DIRECT` | 0x80000 | inferred |  | bit 19 of the device register (0x200 plus 8n), named swap_direct in the public PIC header. Set selects the address-preserving byte map for the 32-bit direct window; clear selects the lane-preserving map. The bit position comes from the public SN2 driver's byte-stream flag mapping onto this bit; no PIC measurement confirms the lane sense (open question in open-questions.md) |
| `INTR_PCIX_MASTER_TIMEOUT` | 0x400000000 | established |  | bit 34 of the interrupt status register (0x100), the PCI-X master timeout. Which bit a bus in PCI-X mode sets for an unclaimed configuration cycle is not stated by any source read (unknown) |
| `INTR_PCI_MASTER_TIMEOUT` | 0x800 | established |  | bit 11 of the interrupt status register (0x100) and of the error view (0x170). The view records a master timeout whether or not the enable bit is set; status records it only when bit 11 of the enable register (0x108) is also set. An unclaimed configuration cycle is the usual source (inferred, see docs/pic.md) |
| `INTR_RESET_MULTIPLE_CLEAR` | 0x40 | established |  | bit 6 of the reset register (0x110), the multiple-error clear. Bits 8:7 and 5:0 have no PIC field. A one written at an error bit's own position clears that bit and rearms the error registers, and any write to 0x110 also clears the error view |
