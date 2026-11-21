<!-- generated from devices/router_origin3000/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 f05ec3257a5dd901126db53badb95885bd988bb22c6f7690f241e3c347fa3a6a -->

# network router as the Origin 3000 kernel reaches it (register numbers of a vector access)

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout.

Unit `router_origin3000`, macro prefix `ROUTER_ORIGIN3000`.
Default source: census: loads and stores in the shipped binaries; names from the register names of the public Linux router header, matched by offset (comparison names: the offsets, widths and roles were read from the shipped routines first).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `status_rev_id` | 0x0 | r | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `port_status_error` | 0x8 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `prot_conf` | 0x10 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `port_reset_mask` | 0x18 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `global_parms0` | 0x20 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `global_parms1` | 0x28 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `port_error_clear` | 0x88 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `jbus0_0` | 0x200 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |

### Register `status_rev_id`

### Register `port_status_error`

### Register `prot_conf`

### Register `port_reset_mask`

### Register `global_parms0`

### Register `global_parms1`

### Register `port_error_clear`

### Register `jbus0_0`
