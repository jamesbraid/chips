<!-- generated from devices/ns-pc87307/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 76cde275bc5d5315ccc6348402124412d364c8bfe4d70fc6d57910902abc382f -->

# National Semiconductor PC87307 Super I/O (marked NS87307) as wired in the Visual Workstation 320 and 540

Register contract of the PC87307 Super I/O: its configuration protocol, the nine logical devices' configuration registers, the GPIO ports and the power management block, from the published datasheet, with the board's use taken from the system firmware, the Windows NT hardware abstraction layer and the Linux Visual Workstation code. Every register is eight bits wide. Grades: established means a datasheet page states it (the page is cited) or the shipped firmware and HAL do it in a routine read in full, which is a software expectation and not a measurement; inferred means a reasoned reading; unknown means no held source settles it. The configuration registers are addressed by an index written to an index port, so the offsets of the card, logical-device, chip-select and power management spaces are indexes, not bus addresses. The part has two variants: the PC87307 reads 0xc0 in its identification register and the PC97307 0xcf, and the PC97307 adds a stepping register; which one the board carries is not known. Not listed: the keyboard, mouse, real-time clock and advanced power control function registers, the floppy controller, UART and parallel port function registers, which are standard PC parts at the bases the logical devices select.

Unit `ns_pc87307`, macro prefix `PC87307`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| pc87307_cfgport | byte | The configuration port pair, offsets from the index port. In PnP motherboard mode the index port is 0x2e and the data port 0x2f, both read/write; other straps give 0x15c and 0x15d, or the full Plug and Play ISA write-only ports 0x279 and 0xa79. The firmware, the HAL and Linux use 0x2e and 0x2f. |
| pc87307_card | byte | Card-level configuration registers, selected by index on the data port (first-level indexes 0x00 to 0x27). |
| pc87307_ld0 | byte | Logical device 0 (keyboard controller) configuration registers, selected by index after writing 0 to the logical device number register (index 0x07). |
| pc87307_ld1 | byte | Logical device 1 (mouse controller) configuration registers, selected by index after writing 1 to the logical device number register (index 0x07). |
| pc87307_ld2 | byte | Logical device 2 (real-time clock and advanced power control) configuration registers, selected by index after writing 2 to the logical device number register (index 0x07). |
| pc87307_ld3 | byte | Logical device 3 (floppy disk controller) configuration registers, selected by index after writing 3 to the logical device number register (index 0x07). |
| pc87307_ld4 | byte | Logical device 4 (parallel port) configuration registers, selected by index after writing 4 to the logical device number register (index 0x07). |
| pc87307_ld5 | byte | Logical device 5 (second UART with infrared) configuration registers, selected by index after writing 5 to the logical device number register (index 0x07). |
| pc87307_ld6 | byte | Logical device 6 (first UART) configuration registers, selected by index after writing 6 to the logical device number register (index 0x07). |
| pc87307_ld7 | byte | Logical device 7 (general-purpose I/O) configuration registers, selected by index after writing 7 to the logical device number register (index 0x07). |
| pc87307_ld8 | byte | Logical device 8 (power management) configuration registers, selected by index after writing 8 to the logical device number register (index 0x07). |
| pc87307_cs | byte | Programmable chip select registers, second-level indexes written to the chip select index register (card index 0x23) and read or written through the chip select data register (card index 0x24). |
| pc87307_gpio0 | byte | GPIO block, bank 0, byte offsets from the logical device 7 base (the board puts it at 0xfc0). Selected while SuperI/O configuration 2 bit 7 is 0. |
| pc87307_gpio1 | byte | GPIO block, bank 1, byte offsets from the logical device 7 base. Selected while SuperI/O configuration 2 bit 7 is 1. |
| pc87307_pmport | byte | Power management index and data ports, offsets from the logical device 8 base (the board puts it at 0xfc8). |
| pc87307_pm | byte | Power management registers, selected by index through the power management index port. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pnp_rd_data` | 0x0 | w | 8 |  | pc87307_card | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 |
| `pnp_isolation` | 0x1 | r | 8 |  | pc87307_card | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 |
| `cfg_control` | 0x2 | w | 8 |  | pc87307_card | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 |
| `pnp_wake` | 0x3 | w | 8 |  | pc87307_card | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 |
| `pnp_resource` | 0x4 | r | 8 |  | pc87307_card | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 |
| `pnp_status` | 0x5 | r | 8 |  | pc87307_card | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27 |
| `csn` | 0x6 | rw | 8 |  | pc87307_card | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 |
| `ldn` | 0x7 | rw | 8 |  | pc87307_card | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 |
| `sid` | 0x20 | r | 8 |  | pc87307_card | 0xc0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 |
| `sioc1` | 0x21 | rw | 8 |  | pc87307_card | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 |
| `sioc2` | 0x22 | rw | 8 |  | pc87307_card | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 |
| `cs_index` | 0x23 | rw | 8 |  | pc87307_card | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35-36 |
| `cs_data` | 0x24 | rw | 8 |  | pc87307_card | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36 |
| `srid` | 0x27 | r | 8 |  | pc87307_card | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36 |
| `cfg_index` | 0x0 | rw | 8 |  | pc87307_cfgport | 0x0 (inferred) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.24-25 |
| `cfg_data` | 0x1 | rw | 8 |  | pc87307_cfgport | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.24-25 |
| `cs_base_msb` | 0x0 | rw | 8 | 3 | pc87307_cs | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 |
| `cs_base_lsb` | 0x1 | rw | 8 | 3 | pc87307_cs | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 |
| `cs_config` | 0x2 | rw | 8 | 3 | pc87307_cs | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 |
| `p1_data` | 0x0 | rw | 8 |  | pc87307_gpio0 | 0xff (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170 |
| `p1_dir` | 0x1 | rw | 8 |  | pc87307_gpio0 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 |
| `p1_otype` | 0x2 | rw | 8 |  | pc87307_gpio0 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 |
| `p1_pullup` | 0x3 | rw | 8 |  | pc87307_gpio0 | 0xff (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 |
| `p2_data` | 0x4 | rw | 8 |  | pc87307_gpio0 | 0xff (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 |
| `p2_dir` | 0x5 | rw | 8 |  | pc87307_gpio0 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 |
| `p2_otype` | 0x6 | rw | 8 |  | pc87307_gpio0 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 |
| `p2_pullup` | 0x7 | rw | 8 |  | pc87307_gpio0 | 0xff (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170-171 |
| `p1_lock` | 0x0 | rw | 8 |  | pc87307_gpio1 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.171) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.171 |
| `ld0_activate` | 0x30 | rw | 8 |  | pc87307_ld0 | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_iorc` | 0x31 | rw | 8 |  | pc87307_ld0 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_base_msb` | 0x60 | rw | 8 |  | pc87307_ld0 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld0 | 0x60 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_cmd_base_msb` | 0x62 | rw | 8 |  | pc87307_ld0 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_cmd_base_lsb` | 0x63 | rw | 8 |  | pc87307_ld0 | 0x64 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_irq` | 0x70 | rw | 8 |  | pc87307_ld0 | 0x1 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_irq_type` | 0x71 | rw | 8 |  | pc87307_ld0 | 0x2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_dma0` | 0x74 | r | 8 |  | pc87307_ld0 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_dma1` | 0x75 | r | 8 |  | pc87307_ld0 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 |
| `ld0_config` | 0xf0 | rw | 8 |  | pc87307_ld0 | 0x40 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36 |
| `ld1_activate` | 0x30 | rw | 8 |  | pc87307_ld1 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 |
| `ld1_irq` | 0x70 | rw | 8 |  | pc87307_ld1 | 0xc (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 |
| `ld1_irq_type` | 0x71 | rw | 8 |  | pc87307_ld1 | 0x2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 |
| `ld1_dma0` | 0x74 | r | 8 |  | pc87307_ld1 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 |
| `ld1_dma1` | 0x75 | r | 8 |  | pc87307_ld1 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 |
| `ld2_activate` | 0x30 | rw | 8 |  | pc87307_ld2 | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld2_iorc` | 0x31 | rw | 8 |  | pc87307_ld2 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld2_base_msb` | 0x60 | rw | 8 |  | pc87307_ld2 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld2_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld2 | 0x70 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld2_irq` | 0x70 | rw | 8 |  | pc87307_ld2 | 0x8 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld2_irq_type` | 0x71 | rw | 8 |  | pc87307_ld2 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld2_dma0` | 0x74 | r | 8 |  | pc87307_ld2 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld2_dma1` | 0x75 | r | 8 |  | pc87307_ld2 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 |
| `ld3_activate` | 0x30 | rw | 8 |  | pc87307_ld3 | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_iorc` | 0x31 | rw | 8 |  | pc87307_ld3 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_base_msb` | 0x60 | rw | 8 |  | pc87307_ld3 | 0x3 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld3 | 0xf2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_irq` | 0x70 | rw | 8 |  | pc87307_ld3 | 0x6 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_irq_type` | 0x71 | rw | 8 |  | pc87307_ld3 | 0x3 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_dma0` | 0x74 | rw | 8 |  | pc87307_ld3 | 0x2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_dma1` | 0x75 | r | 8 |  | pc87307_ld3 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 |
| `ld3_config` | 0xf0 | rw | 8 |  | pc87307_ld3 | 0x20 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36-37 |
| `ld3_drive_id` | 0xf1 | rw | 8 |  | pc87307_ld3 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37 |
| `ld4_activate` | 0x30 | rw | 8 |  | pc87307_ld4 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_iorc` | 0x31 | rw | 8 |  | pc87307_ld4 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_base_msb` | 0x60 | rw | 8 |  | pc87307_ld4 | 0x2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld4 | 0x78 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_irq` | 0x70 | rw | 8 |  | pc87307_ld4 | 0x7 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_irq_type` | 0x71 | rw | 8 |  | pc87307_ld4 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_dma0` | 0x74 | rw | 8 |  | pc87307_ld4 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_dma1` | 0x75 | r | 8 |  | pc87307_ld4 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 |
| `ld4_config` | 0xf0 | rw | 8 |  | pc87307_ld4 | 0xf2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37-38 |
| `ld5_activate` | 0x30 | rw | 8 |  | pc87307_ld5 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_iorc` | 0x31 | rw | 8 |  | pc87307_ld5 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_base_msb` | 0x60 | rw | 8 |  | pc87307_ld5 | 0x2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld5 | 0xf8 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_irq` | 0x70 | rw | 8 |  | pc87307_ld5 | 0x3 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_irq_type` | 0x71 | rw | 8 |  | pc87307_ld5 | 0x3 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_dma0` | 0x74 | rw | 8 |  | pc87307_ld5 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_dma1` | 0x75 | rw | 8 |  | pc87307_ld5 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 |
| `ld5_config` | 0xf0 | rw | 8 |  | pc87307_ld5 | 0x2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 |
| `ld6_activate` | 0x30 | rw | 8 |  | pc87307_ld6 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_iorc` | 0x31 | rw | 8 |  | pc87307_ld6 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_base_msb` | 0x60 | rw | 8 |  | pc87307_ld6 | 0x3 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld6 | 0xf8 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_irq` | 0x70 | rw | 8 |  | pc87307_ld6 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_irq_type` | 0x71 | rw | 8 |  | pc87307_ld6 | 0x3 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_dma0` | 0x74 | r | 8 |  | pc87307_ld6 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_dma1` | 0x75 | r | 8 |  | pc87307_ld6 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 |
| `ld6_config` | 0xf0 | rw | 8 |  | pc87307_ld6 | 0x2 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 |
| `ld7_activate` | 0x30 | rw | 8 |  | pc87307_ld7 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 |
| `ld7_iorc` | 0x31 | rw | 8 |  | pc87307_ld7 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 |
| `ld7_base_msb` | 0x60 | rw | 8 |  | pc87307_ld7 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 |
| `ld7_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld7 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 |
| `ld7_dma0` | 0x74 | r | 8 |  | pc87307_ld7 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 |
| `ld7_dma1` | 0x75 | r | 8 |  | pc87307_ld7 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 |
| `ld8_activate` | 0x30 | rw | 8 |  | pc87307_ld8 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 |
| `ld8_iorc` | 0x31 | rw | 8 |  | pc87307_ld8 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 |
| `ld8_base_msb` | 0x60 | rw | 8 |  | pc87307_ld8 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 |
| `ld8_base_lsb` | 0x61 | rw | 8 |  | pc87307_ld8 | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 |
| `ld8_dma0` | 0x74 | r | 8 |  | pc87307_ld8 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 |
| `ld8_dma1` | 0x75 | r | 8 |  | pc87307_ld8 | 0x4 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 |
| `fer1` | 0x0 | rw | 8 |  | pc87307_pm | 0xff (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 |
| `fer2` | 0x1 | rw | 8 |  | pc87307_pm | 0xff (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.177) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173-174 |
| `pmc1` | 0x2 | rw | 8 |  | pc87307_pm | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 |
| `pmc2` | 0x3 | rw | 8 |  | pc87307_pm | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 |
| `pmc3` | 0x4 | rw | 8 |  | pc87307_pm | 0xe (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 |
| `wdto` | 0x5 | rw | 8 |  | pc87307_pm | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 |
| `wdcf` | 0x6 | rw | 8 |  | pc87307_pm | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.176) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175-176 |
| `wdst` | 0x7 | r | 8 |  | pc87307_pm | 0x1 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.176) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.176 |
| `pm_index` | 0x0 | rw | 8 |  | pc87307_pmport | 0x0 (National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.172) | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.172 |
| `pm_data` | 0x1 | rw | 8 |  | pc87307_pmport | unknown | established | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.172-173 |

### Register `pnp_rd_data`

Plug and Play set RD_DATA port, used only by the Plug and Play ISA protocol. Bits 1 and 0 are fixed at 11.

### Register `pnp_isolation`

Plug and Play serial isolation, used only by the Plug and Play ISA protocol.

### Register `cfg_control`

Configuration control, write only, self-clearing. Bit 0 resets all logical devices and restores the configuration registers to their reset values (the soft reset); bit 1 returns the cards to the Wait for Key state and bit 2 resets the card select number, both only meaningful in Plug and Play ISA mode.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `reset_csn` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 | Reset the card select number to 0. |
| 1 | `wait_key` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 | Return to the Wait for Key state. |
| 0 | `reset` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.27, 30 | Soft reset of the logical devices and configuration registers. |

### Register `pnp_wake`

Plug and Play Wake[CSN], write only.

### Register `pnp_resource`

Plug and Play resource data, read only.

### Register `pnp_status`

Plug and Play status, read only.

### Register `csn`

Card select number, used by the Plug and Play ISA protocol.

### Register `ldn`

Logical device number: selects which logical device's registers the indexes 0x30 to 0xff address. The HAL writes 0, 5, 6, 3, 4 and 1 to steer IRQs 1, 3, 4, 6, 7 and 12; the PROM and Linux write 7 and 8 to set the GPIO and power management bases.

### Register `sid`

Identification. In the PC87307 bits 7:5 are the chip identification and bits 4:0 the revision, and the register reads 0xc0. In the PC97307 all eight bits are the chip identification and it reads 0xcf. Reset 0xc0 is the PC87307's.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:5 | `chip_id` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 | Chip identification (PC87307 reading). |
| 4:0 | `revision` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 | Revision (PC87307 reading; the PC97307 uses these bits for its chip identification). |

### Register `sioc1`

SuperI/O configuration 1. Reset is 0x04, 0x06, 0x14 or 0x16 depending on the SELCS and CFG1 straps, whose board settings are not known. A soft reset has no effect.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `scratch` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 | General purpose scratch bits. |
| 5 | `lock_scratch` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 | 1 makes bits 7:6 read only until a hardware reset. |
| 4 | `xdb_sel` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 | X-bus data buffer select, read only, from the CFG1 strap. |
| 2 | `pcat_mode` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 | 1 PC-AT drive mode (reset), 0 PS/2 drive mode. |
| 1 | `cs0_sel` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 | 0 selects the NSC test output on the CS0 pin, 1 selects CS0; initialised from the SELCS strap. |
| 0 | `zws_en` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34-35 | ZWS (zero wait state) enable, any host access except configuration and parallel port. |

### Register `sioc2`

SuperI/O configuration 2. Reset is 0x00 to 0x03: bits 1:0 reflect the base address straps (11 is the 0x2e pair). The datasheet says the BIOS may switch the index and data ports to the Plug and Play addresses by changing these bits. A soft reset has no effect.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `gpio_bank` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 | Active GPIO register bank: 0 bank 0, 1 bank 1. |
| 6 | `wdo_sel` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 | 0 GPIO17 uses the pin, 1 the watchdog output. |
| 5 | `gpio20_pin` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 | 0 GPIO20, 1 IRSL1/ID1. |
| 4:3 | `gpio21_sel` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 | Pin function of GPIO21, IRSL2/ID2 or IRSL0. |
| 2 | `gpio22_pin` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 | 0 GPIO22, 1 power-on-reset output. |
| 1:0 | `baddr` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.35 | Base address strap value. |

### Register `cs_index`

Programmable chip select configuration index: the second-level index of the chip select register that the data register reaches. Bits 7:4 read 0.

### Register `cs_data`

Programmable chip select configuration data: the register named by the index above.

### Register `srid`

Chip revision identification, PC97307 only: incremented on each tapeout.

### Register `cfg_index`

Configuration index register. A write selects the configuration register the data port then reaches; a read returns the last index written. Reset: the part wakes in the Config state in PnP motherboard mode, so no key sequence is needed. The PROM and Linux write ports 0x2e and 0x2f directly.

### Register `cfg_data`

Configuration data register: reads and writes the register selected by the index. Reserved bits must be preserved, so software uses read-modify-write.

### Register `cs_base_msb`

CS0, CS1 and CS2 base address, most significant byte (second-level indexes 0x00, 0x04 and 0x08).

Array of 3 registers, stride 4.

### Register `cs_base_lsb`

CS0, CS1 and CS2 base address, least significant byte (indexes 0x01, 0x05, 0x09).

Array of 3 registers, stride 4.

### Register `cs_config`

CS0, CS1 and CS2 configuration (indexes 0x02, 0x06, 0x0a). The board's use of the chip selects is not known.

Array of 3 registers, stride 4.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `mask_a11_0` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 ignores address bits A11 to A0 (only A15 to A12 decode). |
| 6 | `ignore_rdwr` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 asserts on address match regardless of read or write and bits 5:4. |
| 5 | `on_read` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 asserts the chip select on a matching read. |
| 4 | `on_write` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 asserts the chip select on a matching write. |
| 3 | `mask_a3` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 ignores A3. |
| 2 | `mask_a2` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 ignores A2. |
| 1 | `mask_a1` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 ignores A1. |
| 0 | `mask_a0` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.39-40 | 1 ignores address bit A0. |

### Register `p1_data`

Port 1 data. A read returns the pin for an input bit and the latch for an output bit; a write latches the value and drives output pins only. The write latch resets to 0xff. The firmware and Linux read this byte at the GPIO base after enabling the block.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6:0 | `board_rev` | inferred |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.170 | Board revision: Linux and the PROM read the byte at the GPIO base and keep these seven bits (below 6 is revision 4, below 12 revision 5, otherwise 6 on a 320; the registry export of one 320 reports 0x11). That the pins carry the revision is the software's reading; the board's wiring is not known. |

### Register `p1_dir`

Port 1 direction: 0 input, 1 output.

### Register `p1_otype`

Port 1 output type: 0 open-drain, 1 push-pull.

### Register `p1_pullup`

Port 1 pull-up control: 0 none, 1 internal pull-up.

### Register `p2_data`

Port 2 data, as port 1.

### Register `p2_dir`

Port 2 direction.

### Register `p2_otype`

Port 2 output type.

### Register `p2_pullup`

Port 2 pull-up control.

### Register `p1_lock`

Port 1 lock. Bits 7 and 6 lock the direction and pull-up bits of GPIO17 and GPIO16, and for outputs the pin value and buffer type. Only a hardware (master) reset clears them. Bits 5:0 are reserved; offsets 0x01 to 0x07 of this bank are reserved.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `lock17` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.171 | Lock GPIO17. |
| 6 | `lock16` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.171 | Lock GPIO16. |

### Register `ld0_activate`

Activate (bit 0). The PROM activates it; the HAL selects it to steer IRQ 1. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); the device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 | 1 activates the device on the ISA bus. |

### Register `ld0_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld0_base_msb`

Base address bits 15:8.

### Register `ld0_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld0_cmd_base_msb`

Command window base address bits 15:8.

### Register `ld0_cmd_base_lsb`

Command window base address bits 7:0; bit 2 reads 1. The reset reads 0x64 (the table prints it as 64).

### Register `ld0_irq`

Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `line` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 | IRQ line. |

### Register `ld0_irq_type`

Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `polarity` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 | 1 high (push-pull), 0 low (open-drain). |
| 0 | `level` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.30 Table 2-12 | 1 level, 0 edge. |

### Register `ld0_dma0`

DMA channel select 0: bits 2:0, 4 means none. Read only.

### Register `ld0_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `ld0_config`

Keyboard controller configuration: bits 7:6 pick the clock source (00 8 MHz, 01 12 MHz, 10 16 MHz, only with the keyboard controller inactive).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `clk` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36 | Clock source. |

### Register `ld1_activate`

Activate (bit 0). The HAL selects it to steer IRQ 12. The device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 | 1 activates the device on the ISA bus. |

### Register `ld1_irq`

Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `line` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 | IRQ line. |

### Register `ld1_irq_type`

Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `polarity` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 | 1 high (push-pull), 0 low (open-drain). |
| 0 | `level` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-13 | 1 level, 0 edge. |

### Register `ld1_dma0`

DMA channel select 0: bits 2:0, 4 means none. Read only.

### Register `ld1_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `ld2_activate`

Activate (bit 0). The PROM activates it. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); the device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 | 1 activates the device on the ISA bus. |

### Register `ld2_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld2_base_msb`

Base address bits 15:8.

### Register `ld2_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld2_irq`

Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `line` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 | IRQ line. |

### Register `ld2_irq_type`

Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `polarity` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 | 1 high (push-pull), 0 low (open-drain). |
| 0 | `level` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.31 Table 2-14 | 1 level, 0 edge. |

### Register `ld2_dma0`

DMA channel select 0: bits 2:0, 4 means none. Read only.

### Register `ld2_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `ld3_activate`

Activate (bit 0). The PROM activates it and its ARC tree lists a floppy controller at the usual 0x3f2 window; the HAL selects it to steer IRQ 6. Reset 0 or 1 according to the CFG0 strap (the board's strap is not known); the device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 | 1 activates the device on the ISA bus. |

### Register `ld3_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld3_base_msb`

Base address bits 15:8.

### Register `ld3_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld3_irq`

Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `line` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 | IRQ line. |

### Register `ld3_irq_type`

Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `polarity` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 | 1 high (push-pull), 0 low (open-drain). |
| 0 | `level` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-15 | 1 level, 0 edge. |

### Register `ld3_dma0`

DMA channel select 0: bits 2:0, 4 means none.

### Register `ld3_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `ld3_config`

Floppy configuration: tri-state, DENSEL polarity, TDR mode and four-drive encode.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `four_drive` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36-37 | Four-drive encode. |
| 6 | `tdr_enh` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36-37 | Enhanced TDR mode. |
| 5 | `densel_pol` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36-37 | DENSEL active high (1, default) or low for 500 kbit/s and 1 Mbit/s. |
| 0 | `tristate` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.36-37 | Tri-state the floppy pins when inactive. |

### Register `ld3_drive_id`

Drive ID register: drive 0 and drive 1 identification bits reflected in the tape drive register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:2 | `drive1` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37 | Drive 1 ID. |
| 1:0 | `drive0` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37 | Drive 0 ID. |

### Register `ld4_activate`

Activate (bit 0). The PROM activates it. Its ARC tree lists the parallel port at the PC's first address 0x378, not the reset base 0x278, so the PROM's configuration writes the base (inferred: the 26 Super I/O writes are not decoded). The device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 | 1 activates the device on the ISA bus. |

### Register `ld4_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld4_base_msb`

Base address bits 15:8.

### Register `ld4_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld4_irq`

Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `line` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 | IRQ line. |

### Register `ld4_irq_type`

Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `polarity` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 | 1 high (push-pull), 0 low (open-drain). |
| 0 | `level` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.32 Table 2-16 | 1 level, 0 edge. |

### Register `ld4_dma0`

DMA channel select 0: bits 2:0, 4 means none.

### Register `ld4_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `ld4_config`

Parallel port configuration. Bits 7:4 must not be changed for normal operation. Reset 0xf2: mode select 111 (IEEE 1284 with EPP selectable), configuration bits in the port accessible, clock enabled.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:5 | `mode` | established | spp=0, spp_ext=1, epp17=2, epp19=3, ieee1284=4, ieee1284_epp=7 | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37-38 | Mode select (bit 5 is the least significant). |
| 4 | `cfg_regs` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37-38 | 1 makes the three configuration registers that follow the ECP register block accessible in ECP mode. |
| 3 | `pnp_spp` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37-38 | Plug and Play resource data reports 0 ECP, 1 SPP. |
| 1 | `clk_en` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37-38 | Parallel port clock enable, ANDed with PMC3 bit 1. |
| 0 | `tristate` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.37-38 | Tri-state the port pins when inactive. |

### Register `ld5_activate`

Activate (bit 0). COM2 at 0x2f8, IRQ 3 (the reset values); the PROM activates it. The device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 | 1 activates the device on the ISA bus. |

### Register `ld5_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld5_base_msb`

Base address bits 15:8.

### Register `ld5_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld5_irq`

Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `line` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 | IRQ line. |

### Register `ld5_irq_type`

Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `polarity` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 | 1 high (push-pull), 0 low (open-drain). |
| 0 | `level` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-17 | 1 level, 0 edge. |

### Register `ld5_dma0`

DMA channel select 0: bits 2:0, 4 means none.

### Register `ld5_dma1`

DMA channel select 1: bits 2:0, 4 means none.

### Register `ld5_config`

UART configuration. The datasheet gives reset 0x02 in Sections 2.8.1 and 2.9.1 and 0x00 in its bitmap summary; this unit takes 0x02 (the tables and sections agree).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `bank_en` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | Bank select enable: when clear, the extended registers are ignored. |
| 3 | `ring_pin` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | 0 the RI input uses the RI pin, 1 the RING pin. |
| 2 | `busy` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | Transfer in progress, read only. |
| 1 | `power` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | 1 normal power mode (clock enabled), 0 low power. |
| 0 | `tristate` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | Tri-state the UART signals when inactive. |

### Register `ld6_activate`

Activate (bit 0). COM1 at 0x3f8, IRQ 4 (the reset values); the PROM's serial console, activated by the boot block and again by the self-test. The device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 | 1 activates the device on the ISA bus. |

### Register `ld6_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld6_base_msb`

Base address bits 15:8.

### Register `ld6_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld6_irq`

Interrupt select: bits 3:0 give the IRQ line, 1 to 15, 0 means none. The part offers IRQ 1, 3 to 12, 14 and 15. The HAL writes the interrupt type register only; Linux 2.2 writes this one on a 320 revision 5 board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:0 | `line` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 | IRQ line. |

### Register `ld6_irq_type`

Interrupt type: bit 0 edge (0) or level (1), bit 1 polarity, low with an open-drain output (0) or high with a push-pull output (1). Which bits are writable depends on the device. The HAL's steering writes bits 0 and 1 of this register for IRQs 1, 3, 4, 6, 7 and 12, and only on the no-8259 route table and the 540 revision 0 table.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `polarity` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 | 1 high (push-pull), 0 low (open-drain). |
| 0 | `level` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-18 | 1 level, 0 edge. |

### Register `ld6_dma0`

DMA channel select 0: bits 2:0, 4 means none. Read only.

### Register `ld6_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `ld6_config`

UART configuration. The datasheet gives reset 0x02 in Sections 2.8.1 and 2.9.1 and 0x00 in its bitmap summary; this unit takes 0x02 (the tables and sections agree).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `bank_en` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | Bank select enable: when clear, the extended registers are ignored. |
| 3 | `ring_pin` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | 0 the RI input uses the RI pin, 1 the RING pin. |
| 2 | `busy` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | Transfer in progress, read only. |
| 1 | `power` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | 1 normal power mode (clock enabled), 0 low power. |
| 0 | `tristate` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.38 | Tri-state the UART signals when inactive. |

### Register `ld7_activate`

Activate (bit 0). The PROM and Linux write the base 0xfc0 and activate it; the board revision is read from its data byte. The device is active only when its function enable bit in the power management block is also set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 | 1 activates the device on the ISA bus. |

### Register `ld7_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.33 Table 2-19 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld7_base_msb`

Base address bits 15:8.

### Register `ld7_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld7_dma0`

DMA channel select 0: bits 2:0, 4 means none. Read only.

### Register `ld7_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `ld8_activate`

Activate (bit 0). The PROM and Linux write the base 0xfc8 and activate it; Linux and the PROM then write function enable register 2. When clear, the power management registers are not accessible but are kept.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `active` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 | 1 activates the device on the ISA bus. |

### Register `ld8_iorc`

I/O range check: bit 0 chooses the byte the device drives (0xaa or 0x55) and bit 1 enables the check, valid only while the device is inactive. Bits 7:2 read 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `enable` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 | Enable the check. |
| 0 | `value` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.34 Table 2-20 | 0 drives 0xaa, 1 drives 0x55. |

### Register `ld8_base_msb`

Base address bits 15:8.

### Register `ld8_base_lsb`

Base address bits 7:0; the low bits are read only and the decoder ignores them.

### Register `ld8_dma0`

DMA channel select 0: bits 2:0, 4 means none. Read only.

### Register `ld8_dma1`

DMA channel select 1: bits 2:0, 4 means none. Read only.

### Register `fer1`

Function enable register 1. A logical device is active only while its activate bit and its enable bit here are both set. Hardware resets it to 0xff.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `uart1` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 | First UART. |
| 5 | `uart2` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 | Second UART and infrared. |
| 4 | `pp` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 | Parallel port. |
| 3 | `fdc` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 | Floppy controller. |
| 2 | `rtc` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 | Real-time clock. |
| 0 | `kbc` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173 | Keyboard controller. |

### Register `fer2`

Function enable register 2. Linux and the PROM write bit 7 set (Linux's comment: it enables access to the GPIO registers). Hardware resets it to 0xff according to Table 9-1's bitmap and the text of 9.2.4; the text for bit 7 marks the cleared state as the default, which contradicts that. The PC87317 sibling datasheet resets the bit to 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `gpio` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173-174 | GPIO ports 1 and 2 enabled. |
| 2 | `cs2` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173-174 | Programmable chip select 2. |
| 1 | `cs1` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173-174 | Programmable chip select 1. |
| 0 | `cs0` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.173-174 | Programmable chip select 0. |

### Register `pmc1`

Power management control 1: tri-state controls for the floppy, parallel and UART pins, ORed with the logical devices' own bits.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `uart1_tri` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 | UART1 pins. |
| 5 | `uart2_tri` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 | UART2 and infrared pins. |
| 4 | `pp_tri` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 | Parallel port pins. |
| 3 | `fdc_tri` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 | Floppy pins. |

### Register `pmc2`

Power management control 2: clock source and clock multiplier. Bits 2:0 follow the CFG3 and CFG2 straps at reset, whose board settings are not known.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `mult_valid` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 | Multiplier clock stable, read only. |
| 2 | `mult_en` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 | Clock multiplier enable. |
| 1:0 | `clk_src` | established | x1_24mhz=0, x1_48mhz=2, multiplier=3 | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.174 | Clock source: 00 24 MHz on X1, 10 48 MHz on X1, 11 on-chip multiplier. |

### Register `pmc3`

Power management control 3: parallel port, UART2 and UART1 clock enables (ANDed with the devices' own bits) and read-only busy flags.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `uart1_busy` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 | UART1 busy. |
| 6 | `uart2_busy` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 | UART2 busy. |
| 3 | `uart1_clk` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 | UART1 clock. |
| 2 | `uart2_clk` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 | UART2 clock. |
| 1 | `pp_clk` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175 | Parallel port clock. |

### Register `wdto`

Watchdog time-out in minutes; 0 stops the watchdog. Also cleared when the power management device is activated.

### Register `wdcf`

Watchdog configuration: which interrupts reload the timer.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `uart2` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175-176 | UART2 IRQ. |
| 2 | `uart1` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175-176 | UART1 IRQ. |
| 1 | `mouse` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175-176 | Mouse IRQ. |
| 0 | `kbc` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.175-176 | Keyboard IRQ. |

### Register `wdst`

Watchdog status. Bit 0 is the watchdog output (1 inactive). Section 9.1.2 says bit 1; the register description and bitmap say bit 0. Whether the output reaches anything on the board is not known.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `wdo` | established |  | National Semiconductor PC87307/PC97307 datasheet (Preliminary, March 1998) p.176 | Watchdog output value, 0 active. |

### Register `pm_index`

Power management index register: selects the register the data port reaches. Bits 7:3 read 0.

### Register `pm_data`

Power management data register.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `CFG_DATA_PORT` | 0x2f | established |  | Configuration data port. |
| `CFG_INDEX_PORT` | 0x2e | established |  | Configuration index port, PnP motherboard mode (software expectation: the PROM and Linux write it directly). |
| `GPIO_BASE` | 0xfc0 | established |  | Base the PROM and Linux program for logical device 7 (software expectation). |
| `PM_BASE` | 0xfc8 | established |  | Base the PROM and Linux program for logical device 8 (software expectation). |

## Test vectors

A vector is a value recorded from a source. An example only shows the layout.

| Target | Value | Kind | Decoded |
|---|---|---|---|
| `sid` | 0xc0 | vector | chip_id=6, revision=0 |
| `ld4_config` | 0xf2 | vector | tristate=0, clk_en=1, pnp_spp=0, cfg_regs=1, mode=7 |
