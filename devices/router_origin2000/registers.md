<!-- generated from devices/router_origin2000/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 55acab457ef018bc4853a2b04d093f28069ad2bb79ae1b72e1c51ad76c5c6feb -->

# network router as the Origin 2000 kernel reaches it (register numbers of a vector access)

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout.

Unit `router_origin2000`, macro prefix `ROUTER_ORIGIN2000`.
Default source: census: loads and stores in the shipped binaries; names from the register names of the public Linux router header, matched by offset (comparison names: the offsets, widths and roles were read from the shipped routines first).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `status_rev_id_led_write_path` | 0x0 | rw | 64 |  |  | unknown | established | census: 6 sites, 6 routines |
| `port_status_error` | 0x8 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `prot_conf` | 0x10 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `global_port_def` | 0x18 | rw | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `nic_access` | 0x38 | rw | 64 |  |  | unknown | established | census: 3 sites, 1 routines |
| `port_error_clear` | 0x88 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |

### Register `status_rev_id_led_write_path`

### Register `port_status_error`

### Register `prot_conf`

### Register `global_port_def`

### Register `nic_access`

### Register `port_error_clear`
