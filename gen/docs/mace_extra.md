# MACE register bits the census does not name

<!-- generated from defs/mace_extra.toml by defs-gen - do not edit, change the source -->

Unit `mace_extra`, macro prefix `MACE`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `ISA_MISC_FLASH_WRITE_ENABLE` | 0x1 | established |  | Bit 0 of the miscellaneous control register (ISA_MISC), read/write, reset 0. Set to 1, writes to the Flash-ROM are enabled. Clear, a write is discarded into a bit bucket and does not reach the device. Specification section 5.1.2, table 54, p. 124, titled Flash-ROM/NIC control register. Section 5.5, p. 133, says software must enable this bit before writing the Flash-ROM, and that the Flash-ROM interface takes single-byte writes only. |
