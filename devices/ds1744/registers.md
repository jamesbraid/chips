<!-- generated from devices/ds1744/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 b5d17eac59842695d624daaad596f06b877f17bfefcdbbe686446be878c5d4fe -->

# Dallas DS1744 nonvolatile timekeeping SRAM (32 KiB, byte-wide, with clock)

The 32 KiB battery-backed SRAM with a clock in its top eight bytes. The register contract here covers what the sources state: the clock bytes at the top of the address range and the remaining bytes as RAM. Grades say how each item was derived: established means the manufacturer specification as the source records it, inferred means arithmetic on an established fact. The clock byte order and bit meanings, the reset state and the RAM layout are not stated by the sources and are not listed.

Unit `ds1744`, macro prefix `DS1744`.
Default source: Analog Devices/Maxim DS1744 nonvolatile timekeeping SRAM datasheet, document 19-5502, revision 6/13.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| chip1744 | byte | The whole 32 KiB chip. Fifteen address inputs select a byte, so offsets run from 0x0000 to 0x7fff. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `ram` | 0x0 | rw | 8 | 32760 | chip1744 | unknown | inferred |  |
| `clock` | 0x7ff8 | rw | 8 | 8 | chip1744 | unknown | established |  |

### Register `ram`

Battery-backed RAM below the clock bytes. The sources give no layout inside it. The 32,760 is inferred from the clock placement, not stated by a source.

Array of 32760 registers, stride 1.

### Register `clock`

The eight clock and calendar bytes at the top of the chip. The sources give their order and bit meanings only through the chip's own register page, which this import did not read, so each byte is named here by position only.

Array of 8 registers, stride 1.
