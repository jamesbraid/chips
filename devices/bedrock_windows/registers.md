<!-- generated from devices/bedrock_windows/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 4ce22aad6bef30dbc9d45d94765826ca9936e0ce29420eac7da13078ea7efa6d -->

# Bedrock register arrays whose extent is a fact of its own

Runs of consecutive Bedrock registers seen as one array each, so that the end of the run is data. Each entry overlaps the registers listed one by one in the other Bedrock units, which carry the individual names; the two views describe the same storage. The offsets, names and counts come from the IRIX register headers named in each entry.

Unit `bedrock_windows`, macro prefix `BEDROCK_WIN`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `gfx_window` | 0x300 | rw | 64 | 10 |  | unknown | established |  |

### Register `gfx_window`

The graphics registers of both processor slots as one window: page, credit counter, bias, interrupt counter and interrupt comparator for slot A, then the same five for slot B. The entries are also listed one by one under their own names; this is the same storage seen as an array, so that its extent is data. The entries have different reset values, so the window has none.

Array of 10 registers, stride 8.
