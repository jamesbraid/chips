<!-- generated from devices/ics1890/registers.toml by defs-gen - do not edit, change the source -->

# ICS1890 10Base-T/100Base-TX PHYceiver, MII management registers (Octane base I/O)

The MII management registers of the ICS1890 Integrated PHYceiver, the Ethernet transceiver on the Octane and Octane2 base I/O board. The IOC3 Ethernet controller reaches the part through its MII port. Only the registers and bits the ICS1890 revision G datasheet describes here are transcribed: the identifier registers 2 and 3, and bits of the extended control register 16. Offsets are MII register numbers, one per 16-bit register. Grades say how each item was derived from the datasheet; none of it was measured on a board. Reset values are the datasheet's default column.

Unit `ics1890`, macro prefix `ICS1890`.
Default source: ICS1890 revision G datasheet.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| mii | register index | MII management registers, addressed by register number through the controller's MII port. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `phy_id1` | 0x2 | rw | 16 |  | mii | 0x15 | established | ICS1890 revision G datasheet, PHY identifier register (register 2), PDF p. 23 (printed p. 23) |
| `phy_id2` | 0x3 | rw | 16 |  | mii | 0xf423 | established | ICS1890 revision G datasheet, PHY identifier register (register 3), PDF p. 24 (printed p. 24) |
| `ext_ctrl` | 0x10 | rw | 16 |  | mii | unknown | established | ICS1890 revision G datasheet, extended control register (register 16), PDF p. 29 (printed p. 29) |

### Register `phy_id1`

PHY identifier, first word: the low 16 bits of the 24-bit OUI. The part resets to the Integrated Circuit Systems OUI. Writes take effect only after the command override bit of register 16 is set, so each write needs that bit set first.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:0 | `oui_low` | established |  | ICS1890 revision G datasheet, PDF p. 23 (printed p. 23) | OUI bits 3 to 18, in the order the datasheet's bit map gives them. The datasheet shows the full OUI as octets 00 A0 BE. |

### Register `phy_id2`

PHY identifier, second word: OUI bits 19 to 24, the model number and the revision number. Reset value is the ICS1890 identity. Writes need the command override bit of register 16, as for register 2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:10 | `oui_high` | established |  | ICS1890 revision G datasheet, PDF p. 24 (printed p. 24) | OUI bits 19 to 24. Bit 19 of the OUI is bit 15 of the register. |
| 9:4 | `model` | established | model (ics1889=1, ics1890=2) | ICS1890 revision G datasheet, PDF p. 24 (printed p. 24) | Manufacturer's model number. Value 2 is the ICS1890 and value 1 is the ICS1889, a different part. |
| 3:0 | `revision` | established | revision (internal=0, alpha=1, general=2, j_or_later=3) | ICS1890 revision G datasheet, PDF p. 24 (printed p. 24) | Revision number, incremented on each significant silicon revision. |

### Register `ext_ctrl`

Extended control. Pre-programs the part; reset loads the defaults from the datasheet's table. Only the bits below are transcribed here. Other bits (for example the stream cipher and scrambler controls) are in the datasheet's full table and are not part of this unit yet, so the reset value of the whole register is unknown here.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `command_override` | established |  | ICS1890 revision G datasheet, PDF p. 29 (printed p. 29) | Command override. Set to one, it lets the next write to any command-writeable bit in any register take effect. Any later write to any register clears it, so each command-writeable write needs the bit set again. |
| 10:6 | `phy_address` | established |  | ICS1890 revision G datasheet, PDF p. 29 (printed p. 29) | Read only: the five-bit MII address of the part (0 to 31). The LED pin connections set it. A write is ignored. |
| 4 | `reserved_ics_4` | established |  | ICS1890 revision G datasheet, PDF p. 29 (printed p. 29), reserved bits note | Reserved for ICS use. Read value unspecified: the datasheet says it may be zero or one. Write zero; writing one may stop the part operating correctly. |

## Enums

### Enum `model`

| Label | Value | Grade | Source |
|---|---|---|---|
| `ics1889` | 1 | established | ICS1890 revision G datasheet |
| `ics1890` | 2 | established | ICS1890 revision G datasheet |

### Enum `revision`

| Label | Value | Grade | Source |
|---|---|---|---|
| `internal` | 0 | established | ICS1890 revision G datasheet |
| `alpha` | 1 | established | ICS1890 revision G datasheet |
| `general` | 2 | established | ICS1890 revision G datasheet |
| `j_or_later` | 3 | established | ICS1890 revision G datasheet |
