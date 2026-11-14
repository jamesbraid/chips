<!-- generated from devices/hub_windows/registers.toml by defs-gen - do not edit, change the source -->

# Hub register arrays whose extent is a fact of its own

Runs of consecutive Hub registers seen as one array each, so that the end of the run is data. Each entry overlaps the registers listed one by one in the other Hub units, which carry the individual names; the two views describe the same storage. The offsets, names and counts come from the IRIX register headers and register table named in each entry.

Unit `hub_windows`, macro prefix `HUB_WIN`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `pi_gfx_window` | 0x300 | rw | 64 | 10 |  | 0x0 (established) | established |  |
| `md_ureg1` | 0x220080 | rw | 64 | 16 |  | unknown | established |  |

### Register `pi_gfx_window`

The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then the same five for slot B. The source gives the distance between the two sets as the offset of the slot B page from the slot A page. The entries are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data.

Array of 10 registers, stride 8.

### Register `md_ureg1`

The sixteen microcontroller and UART 1 registers as one array. They are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data. On the Origin 200 (the SN00 variant) the kernel's per-processor LED macro writes the LED of slice 0 at element 0 and the LED of slice 1 at element 4, a spacing of four elements per slice; other Hub variants use the separate LED registers. The IRIX register table gives read and write access for the entries it lists (0, 1 and 15) and the header gives all sixteen the same description.

Array of 16 registers, stride 8.
