<!-- generated from devices/ds1742/registers.toml by defs-gen - do not edit, change the source -->

# Dallas DS1742W nonvolatile timekeeping RAM (Fuel L1 storage part, 3.3 V, 2 KiB)

The 2,048-byte battery-backed SRAM and clock part identified on a revision B Fuel board. The register contract here covers what the sources state: the clock bytes at the top of the address range and the remaining bytes as RAM. Grades say how each item was derived: established means the manufacturer specification as the source records it, inferred means a public driver, a board marking or arithmetic on an established fact. The clock byte meanings, the reset state and the RAM layout are not stated by the sources and are not listed.

Unit `ds1742`, macro prefix `DS1742`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| chip | byte | The whole 2,048-byte chip. Eleven address pins A0 to A10 select a byte, so offsets run from 0x000 to 0x7ff. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `ram` | 0x0 | rw | 8 | 2040 | chip | unknown | inferred |  |
| `clock` | 0x7f8 | rw | 8 | 8 | chip | unknown | established | Dallas DS1742 datasheet, address map (the chip places the clock bytes at offsets 0x7f8 to 0x7ff) |

### Register `ram`

Battery-backed RAM below the clock bytes. The sources give no RAM count and no layout inside it. The 2,040 is inferred from the clock placement, not stated by a source.

Array of 2040 registers, stride 1.

### Register `clock`

The eight clock and calendar bytes at the top of the chip. The sources give their order and bit meanings only through the chip's own register page, which this import did not read, so each byte is named here by offset only.

Array of 8 registers, stride 1.
