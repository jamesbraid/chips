# Xbow registers outside the census

<!-- generated from defs/xbow_extra.toml by defs-gen - do not edit, change the source -->

Unit `xbow_extra`, macro prefix `XBOW`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `perf_a` | 0x60 | rw | 32 |  |  | unknown | established |  |
| `perf_b` | 0x68 | rw | 32 |  |  | unknown | established |  |
| `link_f_arb_upper` | 0x2d8 | rw | 32 |  |  | unknown | inferred |  |

### Register `perf_a`

### Register `perf_b`

### Register `link_f_arb_upper`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `FENCE_LINK_8` | 0x80 | inferred |  | offsets 0x80 to 0xb8 step 8 are the reset fences for links 8 to F; xbow.h carries the same slots as XBOW_RESERVED_* with write sites [E] |
| `FENCE_LINK_9` | 0x88 | inferred |  | as above |
| `FENCE_LINK_A` | 0x90 | inferred |  | as above |
| `FENCE_LINK_B` | 0x98 | inferred |  | as above |
| `FENCE_LINK_C` | 0xa0 | inferred |  | as above |
| `FENCE_LINK_D` | 0xa8 | inferred |  | as above |
| `FENCE_LINK_E` | 0xb0 | inferred |  | as above |
| `FENCE_LINK_F` | 0xb8 | inferred |  | as above |
| `FENCE_WIDGET_0` | 0x78 | inferred |  | existence and read value 0xf7 measured on one Octane2 [E as an observation only]; role inferred; reset value [U] |
| `FLUSH_LINK_8` | 0x100 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `FLUSH_LINK_9` | 0x140 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `FLUSH_LINK_A` | 0x180 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `FLUSH_LINK_B` | 0x1c0 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `FLUSH_LINK_C` | 0x200 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `FLUSH_LINK_D` | 0x240 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `FLUSH_LINK_E` | 0x280 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `FLUSH_LINK_F` | 0x2c0 | established |  | offset and read-only access from the specification; width 4 byte(s) [I] |
| `ID_MFR_MASK` | 0xffe | established |  | manufacturer field, bits 11:1 |
| `ID_PART_MASK` | 0xffff000 | established |  | part field, bits 27:12 |
| `ID_REV_MASK` | 0xf0000000 | established |  | revision field, bits 31:28 |
| `PART_PXBOW` | 0xd100 | established |  | part value in the same three sources; "the crossbar face of the PIC" is [I] |
| `PART_XBOW` | 0x0 | established |  | Crossbow; manufacturer 0 |
| `PART_XXBOW` | 0xd000 | established |  | part value in the shipped crossbar header, the public Linux crossbar probe file and OpenBSD; "the crossbar of the Xbridge" is [I] (Linux comment only) |
| `PERF_A_B_19_0` | 0xfffff | established |  | count field |
| `PERF_A_B_22_20` | 0x700000 | established |  | link select field |
| `PERF_B_B_19_0` | 0xfffff | established |  | count field |
| `PERF_B_B_22_20` | 0x700000 | established |  | link select field |
| `PROM_CROSSBAR_LOCK_BIT` | 0x2 | inferred |  | bit 1 of the link F arbitration-upper word, the crossbar lock the stock PROM takes on every revision; the PROM uses it as a lock, not as bandwidth |
| `RESOURCE_LOCK` | 0xc0 | inferred |  | read value 0 measured on one Octane2 after the PROM ran; acquire and release behaviour [I]; reset value [U] |
| `RESOURCE_LOCK_CLEAR` | 0xc8 | inferred |  | lock clear, as above |
| `REV_CODE_1` | 0x1 | established |  | header name 1.0 |
| `REV_CODE_2` | 0x2 | established |  | header name 1.1; no name-table entry in the kernel object. Origin 300 and Fuel captures print revision 2 beside part 0xd000 [E] |
| `REV_CODE_3` | 0x3 | established |  | header name 1.2. Origin 350 captures print "XBOW Rev 3" [E]; which part that unit reports is [I] (captures do not print it) |
| `REV_CODE_4` | 0x4 | established |  | header name 1.3 |
| `REV_CODE_5` | 0x5 | established |  | header name 2.0; the Octane2 PROM labels it 1.4 |
