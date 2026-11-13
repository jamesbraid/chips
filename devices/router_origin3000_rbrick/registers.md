<!-- generated from devices/router_origin3000_rbrick/registers.toml by defs-gen - do not edit, change the source -->

# Origin 3000 R-brick router registers outside the census (vector space)

Router register fields and link addresses that the shipped firmware and kernel use, and that the census of the router's vector accesses does not give. Every item here is a software expectation read from shipped code or a public header, not a hardware measurement. The register space is named apart from the census so that offsets which the census already names (the status word, the protection configuration) are not claimed twice.

Unit `router_origin3000_rbrick`, macro prefix `RBRICK_ROUTER`.
Default source: shipped kernel and firmware readings; names from the public Linux SN1 router header.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| vector | byte | Router registers reached through the vector path, one offset per register. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `status` | 0x0 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `prot_conf` | 0x10 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `position` | 0x50 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `scratch3` | 0x118 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `scratch3_setzero` | 0x518 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link1` | 0x10008 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link1` | 0x10018 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link2` | 0x10808 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link2` | 0x10818 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link3` | 0x20008 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link3` | 0x20018 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link4` | 0x20808 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link4` | 0x20818 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link5` | 0x30008 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link5` | 0x30018 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link6` | 0x30808 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link6` | 0x30818 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link7` | 0x40008 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link7` | 0x40018 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `error_link8` | 0x40808 | r | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `reset_mask_link8` | 0x40818 | rw | 64 |  | vector | unknown | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |

### Register `status`

Status word. The kernel refuses a chip whose part field is not the router part, reads the revision from the top nibble, and treats a port as active when its link-working bit is set. Each link has a two-bit state. The census names the same word as the status and revision register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 51:50 | `link8_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 8. |
| 49:48 | `link7_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 7. |
| 47:46 | `link6_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 6. |
| 45:44 | `link5_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 5. |
| 43:42 | `link4_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 4. |
| 41:40 | `link3_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 3. |
| 39:38 | `link2_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 2. |
| 37:36 | `link1_state` | inferred | link_state (wentdown=0, resetfail=1, linkup=2, notused=3) | shipped kernel and firmware readings; names from the public Linux SN1 router header | Two-bit state of link 1: its reset-failed bit is the low bit and its link-working bit the high bit. |
| 31:28 | `rev` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Chip revision, as the kernel reports it. |
| 27:12 | `chip` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Chip part field. The kernel accepts only the router part. |

### Register `prot_conf`

Protection configuration. Each low bit lets a reset arriving on that link through. The census gives the access and offset of the same word; the field names come from the public header. Reset value unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13 | `dir_compare_off` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Disables the directory compare. Its effect is not read. |
| 12 | `force_local` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Force-local flag. Its effect is not read. |
| 11:8 | `meta_id` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Meta identifier. Its use is not read. |
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | One permit bit per link, bit n-1 for link n. A clear bit blocks a reset arriving on that link. |

### Register `position`

Position word that discovery reads to classify a router. A clear bit marks a metarouter or a repeat router. The census does not name this offset.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `repeater_flag` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Clear for a repeat router. Discovery inverts both bits before it tests them. |
| 20 | `meta_flag` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Clear for a metarouter. |

### Register `scratch3`

Scratch register 3. Bit 0 is the router lock: writing 0 releases it. The header names this word as the scratch register itself.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `lock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `scratch3_setzero`

Set-if-zero alias of scratch register 3. A read returns the old lock bit and sets it, so the firmware takes the lock by reading it until the read returns 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `lock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link1`

Error status of link 1. The layout is the one the public header gives and the firmware's error decoder prints. The order of the three low flags is not given.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | The far end reports no power. |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Output port deadlocked. |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | A warm reset was received on this link. |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | A link reset was received on this link. |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header | Three flags for retry timeout, receiver overflow and illegal port. The decoder lists them in that order, but which bit is which is not settled. |

### Register `reset_mask_link1`

Reset mask of link 1. Bit n-1 names a link n. The direction in which the mask applies is inferred, not established.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link2`

Error status of link 2. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `reset_mask_link2`

Reset mask of link 2. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link3`

Error status of link 3. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `reset_mask_link3`

Reset mask of link 3. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link4`

Error status of link 4. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `reset_mask_link4`

Reset mask of link 4. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link5`

Error status of link 5. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `reset_mask_link5`

Reset mask of link 5. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link6`

Error status of link 6. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `reset_mask_link6`

Reset mask of link 6. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link7`

Error status of link 7. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `reset_mask_link7`

Reset mask of link 7. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `error_link8`

Error status of link 8. Same layout as link 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 38 | `power_not_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 37 | `deadlock` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 36 | `warm_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 35 | `link_reset_rx` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |
| 34:32 | `retry_rx_illegal` | unknown |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

### Register `reset_mask_link8`

Reset mask of link 8. Same layout as link 1. The eight mask addresses are not linear: links come in pairs 64 KiB apart, with the second link of a pair 0x800 above the first.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:0 | `reset_ok` | inferred |  | shipped kernel and firmware readings; names from the public Linux SN1 router header |  |

## Enums

### Enum `link_state`

| Label | Value | Grade | Source |
|---|---|---|---|
| `wentdown` | 0 | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `resetfail` | 1 | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `linkup` | 2 | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |
| `notused` | 3 | inferred | shipped kernel and firmware readings; names from the public Linux SN1 router header |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `L1_ROUTER_TYPE_META` | 0xe | inferred | shipped firmware reading of the L1 persistent settings | Router-type nibble for a metarouter. |
| `L1_ROUTER_TYPE_ORDINARY` | 0xf | inferred | shipped firmware reading of the L1 persistent settings | Router-type nibble for an ordinary router. |
| `L1_ROUTER_TYPE_REPEATER` | 0xc | inferred | shipped firmware reading of the L1 persistent settings | Router-type nibble for a repeat router. |
| `L1_SETTING_ROUTER_TYPE` | 0x3c | inferred | shipped firmware reading of the L1 persistent settings | Persistent L1 setting that holds the router type. The type sits in the upper nibble of the setting. |
| `ROUTER_CHIP_PART` | 0x3017 | inferred | shipped kernel reading of the status word part field | Part value the kernel requires in the status word's chip field before it accepts a router. |
| `ROUTER_DEST_IDS` | 0x200 | established | SGI Origin 3000 System Architecture, 108-0240-002, pp. 2-18 to 2-22 | Destination IDs the header's destination field can name. |
| `ROUTER_ENABLED_PORTS_SIX` | 0x6 | established | SGI Origin 3000 Series Service Procedures, 108-0301-001, pp. 3-1 and 3-2 | Ports enabled on a vendor-shipped six-port R-brick. Two ports are switched off by L1 command. |
| `ROUTER_LOCAL_TABLE_ENTRIES` | 0x10 | established | SGI Origin 3000 System Architecture, 108-0240-002, p. 2-22 | Entries in the local routing table, indexed by the low four bits of the destination. |
| `ROUTER_PORTS` | 0x8 | established | SGI Origin 3000 Series Owner's Guide, 007-4240-002, pp. 194-196 | NUMAlink 3 ports on the R-brick's rear panel, lettered A to H. |
| `ROUTER_REMOTE_TABLE_ENTRIES` | 0x20 | established | SGI Origin 3000 System Architecture, 108-0240-002, p. 2-22 | Entries in the remote routing table, indexed by the upper five bits of the destination. |
| `ROUTER_USB_PORT_FIRST` | 0x2 | established | SGI Origin 3000 Series Technical Configuration Owner's Guide, 007-4311-002, p. 36 | First rear port that carries the USB signals to a C-brick's L1. |
| `ROUTER_USB_PORT_LAST` | 0x5 | established | SGI Origin 3000 Series Technical Configuration Owner's Guide, 007-4311-002, p. 36 | Last rear port that carries the USB signals to a C-brick's L1. |
| `ROUTER_VCS_PER_PORT` | 0x4 | established | SGI Origin 3000 System Architecture, 108-0240-002, pp. 2-18 to 2-22 | Virtual channels per port. Requests use channels 0 and 1, responses 2 and 3. |
