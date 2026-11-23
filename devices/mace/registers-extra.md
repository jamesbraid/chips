<!-- generated from devices/mace/registers-extra.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 490c88a36f70908dd2b884bf6a6cb452f78c4406765832d4e82eb4098f24c841 -->

# MACE register bits the census does not name

Unit `mace_extra`, macro prefix `MACE`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ISA_MISC_FLASH_WRITE_ENABLE` | 0x1 | established |  | Bit 0 of the miscellaneous control register (ISA_MISC), read/write, reset 0. Set to 1, writes to the Flash-ROM are enabled. Clear, a write is discarded into a bit bucket and does not reach the device. Specification section 5.1.2, table 54, p. 124, titled Flash-ROM/NIC control register. Section 5.5, p. 133, says software must enable this bit before writing the Flash-ROM, and that the Flash-ROM interface takes single-byte writes only. |
| `ISA_MISC_NIC_DEASSERT` | 0x4 | established |  | Bit 2 of the miscellaneous control register (ISA_MISC), read/write, reset 0. Clear holds the NIC bidirectional interface low; set releases it and the bit then does nothing. This is the drive side of the one-wire Number-In-a-Can interface the specification's feature list names. Specification section 5.1.2, table 54, p. 124. |
| `ISA_MISC_NIC_SAMPLE` | 0x8 | established |  | Bit 3 of the miscellaneous control register (ISA_MISC), read-only, reset 0. It reads the level now on the NIC interface signal: 0 when the signal is low, 1 when it is high. This is the sample side of the same interface as ISA_MISC_NIC_DEASSERT. Specification section 5.1.2, table 54, p. 124. |
