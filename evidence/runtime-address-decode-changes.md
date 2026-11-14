# Hub and Bedrock: what changes the meaning of an address after boot, under IRIX 6.5.22 and 6.5.30

Question. Besides the node-number, cached-alias, region-present and memory-configuration writes that
[hub-bedrock-config-write-timing.md](hub-bedrock-config-write-timing.md) covers, does anything in the Hub, Bedrock,
network interface, processor interface or memory controller change what an address shows at run time, after boot or
under IRIX 6.5.22 or 6.5.30? Candidates: memory hot-plug, partitioning (region, partition, protection and firewall
registers), error-driven bank disable, directory or ECC mode changes, processor-interface or memory-controller
remapping, and any kernel routine that writes these registers after `mlreset`. For each: register, routine, address,
and whether it runs by default.

Grades: **E** established (routine read in full, or every store site and caller enumerated), **I** inferred (reasoning
given), **U** unknown. Builds and the method are in the first sections of the companion page; addresses below are link
addresses, written "6.5.30 / 6.5.22". "IP27" is the Hub platform, "IP35" the Bedrock platform.

## Answer

1. After `mlreset` there is **no IRIX store, in either kernel on either platform, to the node number, region present,
   cached-alias size, local-block region-present, nodes-absent, permission or current-cell registers, nor to the memory
   controller's bank sizes or directory configuration.** E for every store site the census resolves in all four
   kernels; a store with a computed base and offset would not be listed (**I** that none exists).
2. What does change at run time is: the I/O block's big-window translation entries and widget access masks (every PIO
   map or widget attach), per-page directory state (poison, on memory errors and block-transfer copies), and, on the
   Hub only, per-region page protection of the first two pages of each node (once per node at boot). **E.**
3. Partitioning, memory hot-plug and error-driven bank disable are not implemented in the shipped kernels in a way that
   writes hardware: the partition entry points are stubs, there is no hot-plug routine, and the one bank-disable routine
   (IP27 only) records an environment variable for the next PROM run. **E.**
4. Two routines rewrite memory-controller timing at run time, only when a program maps the PROM space. **E.**

## Registers that never change after `mlreset` (E)

Census store sites, 6.5.22 and 6.5.30, all four kernels, listed by register. Every register in the first column has
zero resolved stores outside the routine named in the second.

| Register (Hub offset or Bedrock offset) | Only store in the kernel |
|---|---|
| Hub `NI_STATUS_REV_ID` 0x600000 (node number, region size) | none |
| Bedrock local-block `rev_id` 0x600000 (node number, region size) | none |
| Hub `PI_REGION_PRESENT` 0x18, `PI_CALIAS_SIZE` 0x28 | `mlreset`: 6.5.30 `0x2638c`, `0x26394`; 6.5.22 `0x26138`, `0x26140` |
| Bedrock PI `region_present`, `calias_size` (PI0 0x18, 0x28; PI1 0x200018, 0x200028) | `mlreset`: 6.5.30 `0x4dc80`, `0x4dc88`; 6.5.22 `0x4e5b8`, `0x4e5c0` |
| Bedrock local-block `region_present` 0x604020, `nodes_absent` 0x604028, `cpu_permission` 0x604000, `io_permission` 0x604010 | none |
| Bedrock memory `current_cell` 0x780000, `dir_config` 0x7c0000, `memory_config` 0x780008 | none |
| Hub `PI_CPU_PROTECT`, `PI_IO_PROTECT` (PI 0x0, 0x10 per the header), `NI_PROTECTION` 0x600010 (read in `check_ni_errors`) | none |
| Hub `MD_MEMORY_CONFIG` 0x200018 | `cpuprom_map`: 6.5.30 `0x6bb3c`; 6.5.22 `0x6d484` (timing fields only, below) |

(`mlreset` itself is the boot-time write; see the companion page.)

## Register-level changes under IRIX

### 1. I/O block big-window translation, widget access, device enables

| Register | Routine | Address 6.5.30 / 6.5.22 | What | Default? | Grade |
|---|---|---|---|---|---|
| Hub I/O offset 0x400160 + 8 per window slot (big-window entries; Bedrock alias 0xc00160, I/O 0x400160) | `hub_piomap_alloc` | Hub `0x3b7f0` / `0x3b4b4`; Bedrock `0x62464` / `0x62c98` | writes `((widget & 0xf) << 8) \| (address >> 29 & 0x1f)` into entry `slot` (`sd ...,352(base)`, 352 = 0x160) after building the base from the node's number shifted left 32 (Hub) or 33 (Bedrock); the same form in both | yes, whenever a driver allocates a large PIO map (every Crosstalk widget with big-window mappings) | E for the store form on both chips; the entry layout is E for the Hub ([devices/hub/README.md](../devices/hub/README.md) `0x400160`), I for Bedrock (same code, layout not otherwise read) |
| same | `hub_piomap_free` | Hub `0x3b950` / `0x3b640`; Bedrock `0x625c4` / `0x62e24` | stores 0x300 (Hub, read in full); Bedrock store at that address not value-checked | yes, on unmap | E (Hub), I (Bedrock) |
| same | `hubio_init` (Hub, unnamed in 6.5.22: `0x3b21c`) | Hub `0x3b538` | initial entry store; Bedrock: unnamed routine at `0x621ac` / `0x62a00` | yes, at boot | E for site, I for value |
| I/O 0x400190 (entry 6) | `mlreset` | see companion page | zeroed per node | yes, boot | E |
| Hub I/O 0x400110 `IIO_IOWA` (outbound widget access mask, header name inferred) | `hub_set_piomode` (called from `hubio_init`) | Hub `0x3c40c`, `0x3c45c` / `0x3c0fc`, `0x3c150`; Bedrock `0x62fb0`, `0x63000` / `0x63810`, `0x63864` | which widgets the processor may reach by PIO | yes, boot (`hub_set_piomode`) | E for sites; I for the field meaning |
| Hub I/O 0x400120 `IIO_IIDEM` (inbound device error mask) | `hub_widgetdev_enable`, `hub_widgetdev_shutdown` | Hub `0x27b20`, `0x2795c` / `0x2786c`, `0x276a8`; Bedrock `0x78ea8`, `0x78f68` | read-modify-write, one bit per device | yes, per widget attach and shutdown | E for sites, I for meaning |
| Hub I/O 0x400198 `IIO_IOPRB_0` (PIO read buffer entry) | `hub_setup_prb` | Hub `0x3c3c8` / `0x3c0b8`; Bedrock `0x62f6c` / `0x637cc` | programs read-buffer entries | yes, per widget attach | E for site |

These change which crossbar window an address reaches (big windows) or whether a widget is reachable at all; none
changes the node's own memory decode. No `sync` lies in any of the routines (E, address-range scan of all four kernels).

### 2. Memory-controller timing, only when the PROM space is mapped

| Chip | Routine | Address 6.5.30 / 6.5.22 | What | Default? | Grade |
|---|---|---|---|---|---|
| Hub | `cpuprom_map` (device map entry of the node-board special space, `hubspc_map`) | `ld` `0x6bb28`, `sd` `0x6bb3c` / `0x6d484` | read-modify-write of `MD_MEMORY_CONFIG` of the target node (base `0x9200000001a00000` plus node shifted left 32): clears bits 53:44 (mask `0xffc00fffffffffff`) and ors in `121 << 46` or `257 << 44` depending on a byte at `0xffffffffffffc423` (nonzero: write field 4, cycle field 15; zero: write 1, cycle 8). Those are the boot-flash write and cycle timing fields (bits 48:44 and 53:49). The bank size bits 23:0 and the directory-format bit 28 are preserved | no: reached only from `hubspc_map` (`0x6bd0c`), the map entry of the hub special-space device, so when a program maps a node's PROM space (**I**: flash and diagnostic tools) | E for the stores and masks; I for the meaning of the byte at `0xffffffffffffc423` |
| Bedrock | `cpuprom_map` | `sd` `0x96dd8` / `0x990e0` | read-modify-write of word `+8` of a base held in the kernel's data (`ld ...,2360($28)`) plus the node number shifted left 33: low halfword replaced by `0x1010` (`lui 0xffff` mask, `ori 0x1010`) | no, same condition | E for the stores; I for the register, from the PROM's own `+0x7a0008` flash timing word whose low half is `0x1010` ([ip35-prom-poll-timing.md](../questions/ip35-prom-poll-timing.md)) and the census name `+0xfa0008` of the alias; U for the base value (a data slot, not a literal) |

Neither changes what an address decodes to; both change how fast the flash answers.

### 3. Network interface

| Register | Routine | Address 6.5.30 | What | Default? | Grade |
|---|---|---|---|---|---|
| Hub `NI_PORT_RESET` 0x600008; Bedrock NI 0x680008, 0x680010 | `ni_reset_port` (0xc bytes; stores 0x81 to the Hub register), `hubni_error_handler`, `llp_pfail_intr`, `force_system_shutdown` | Hub `ni_reset_port` store `0x1d76c` / `0x1d53c`; Bedrock `0x4154c` / `0x4131c` | resets a network port | the error handlers store on link errors; `he_arcs_set_vectors` also calls `ni_reset_port` (`0x29904`), and `mlreset` (`0x26488`), `he_arcs_restart` and `he_arcs_reboot` call that, under a condition not traced: **U** whether it runs at every boot | E for the stores and call edges |
| Hub NI vector registers 0x600200 to 0x600510; Bedrock alias `0xe0c000` to `0xe0c038` | `vector_write_node`, `vector_read_node`, `vector_exch_node` (callers: `hub_vector_write`, `vector_write`, `get_L1_baud`, `save_router_err`) | Hub `0x1ccf0` to `0x1d130`; Bedrock `0x46e08`, `0x46e10` | remote register read and write by node | on demand, for L1 baud queries and a diagnostic call | E for callers; I that no routing-table store happens through them (not traced to the argument) |
| Bedrock NI `ni_port_down_reset` 0x680100 | `ni_port_down_reset` | `0x58b40`, `0x58b58`, `0x58bfc`, `0x58c8c`, `0x58e54` | port down reset | link error paths | E for sites |

No store to the routing (local or meta) table registers exists in either IRIX kernel except through the generic
vector-write path above. **E** for resolved stores; routing is programmed by the PROM. **I** (from the absence).

### 4. Memory-controller thresholds and two unnamed registers

`migr_effthreshold_diff_set` (Hub `0x200030` / `0x200038`; Bedrock `+0x7c0040`, alias `0xfc0040`, store `0x32b5f0` / `0x2f2750`)
sets page-migration thresholds, which decide when an interrupt asks the kernel to move a page; no address meaning
changes in hardware. **E** for sites, **I** for the effect. Whether it runs by default is **U**: the Hub registers are
also stored by `migr_refcnt_init` and `numa_tune` (census), the callers of `migr_effthreshold_diff_set` were not
traced.

Hub `per_hub_init` (6.5.30 `0x26acc`; 6.5.22 `0x26878`) also stores to two memory-controller offsets the census cannot name:
`0x2000c8` (`0x26ca8`: the value is the data word `0xfe00000000` as it sits in the image, loaded from gp-30128) and
`0x2000e0` (bits 12:8 cleared and set to 1, `0x26d4c` to `0x26d5c`, only for chip revisions below 5, or 5 with a flag
set). Both run once per node at boot. What they control is **U**: no held source names them, and the values do not
decode as a bank or region field by inspection. Route: a Hub specification, or the IP27 PROM's use of the same offsets.

## Changes that are not register writes

### 5. Per-region page protection of the first two pages (Hub only, default)

`protect_hub_calias(nasid)`, called by `per_hub_init` for every node (6.5.30 call at `0x26dcc`, routine `0x2695c`;
6.5.22 call at `0x26b78`, routine `0x26708`). For each of 64 regions other than the node's own it stores 0 to two
doublewords in the protection space at `0x90000000c0000000`: one for physical offset 0 of the node and one for offset
4096, at the entry for that region (`region << 3` added to an address-derived index). **E** for the routine (read in
full, 0xb8 bytes). Effect: those two pages, the cached-alias pages, become inaccessible to other regions (**I**: the
protection space and entry layout are the directory-protection words the header names; the code writes zero). The
Bedrock kernel's `protect_hub_calias` (`0x4e29c` / `0x4ebf4`, 0x40 bytes) calls `nasid_to_region` 64 times and stores
nothing. **E**: on Bedrock IRIX writes no such protection.

### 6. Directory state: poison, protection access, memory-error policy

| Routine | Address 6.5.30 | What | Default? | Grade |
|---|---|---|---|---|
| `set_dir_state_POISONED`, `set_dir_state_UNOWNED` -> `set_dir_state` | `0x2ae38`, `0x2ae84` -> `0x2ad84` (Hub); the same routines exist in Bedrock | write a directory entry's state in the directory space; `set_dir_state` loads `MD_MEMORY_CONFIG` (census), I to choose the directory format | yes, runtime | E for the routines' existence and callers; I for the effect on a later access (an error response) |
| callers of poison | `memerror_handle_uce` (from `ecc_handler`, call at `0x567bc`), `poison_page`, `poison_state_alter_range` (callers `bte_poison_range`, `contmemall_node`, `poison_state_clear`, `poison_state_set`), `poison_state_clear` (callers `bte_copy`, `lpage_alloc_contig_physmem`, `page_unpoison`, `phead_unpoison`), `sn0_error_reclaim_page` | uncorrectable memory error handling, block-transfer copies and contiguous-memory allocation poison and clear pages | yes (on a memory error, a block transfer or a contiguous allocation) | E for the call edges |
| `memory_set_access` -> `set_dir_access` | `0x2a52c`, `0x2a490` (Hub; Bedrock `0x4f9b8`, `0x4f928`) | sets a page's access bit in the directory (the bit position depends on `MD_MEMORY_CONFIG` bit 28) | **no**: its only caller is `page_allow_access`, whose only callers are `dump_hub_registers` (6.5.30 `0x21ac38`, `0x21ac50`; Bedrock `+0x994`, `+0x9ac`) | E |

### 7. Partitioning, firewalls, hot-plug (stubs and absences)

| What | Finding | Grade |
|---|---|---|
| `part_*` entry points (`part_init`, `part_add_regions`, `part_rm_regions`, `part_register_page`, `part_permit_page`, `part_export_page`, `part_export_page_perms`, `part_unexport_page`, `part_page_allocate`, `part_poison_page`, `part_deactivate`, `part_set_var`, `part_operation`) and `xpc_init` | IP27 6.5.30 `0x3c2210` to `0x3c249c` and `xpc_init` `0x3c20a0`; IP35 6.5.30 `0x4963f0` to `0x496674` and `xpc_init` `0x496280`. The 8-byte ones are stubs (`part_init`, `part_add_regions`, `xpc_init`: `jr ra`; `part_rm_regions`: returns 0); the 0x20-byte ones call `panic` with the routine's own name as the message (`part_permit_page` and `part_page_allocate` read in full; the others have the same size and shape, **I**). So the partition calls do nothing in hardware, and a call that expects a result panics | E for the stubs named, I for the rest |
| `partition_handle_error` | `0x37de0` / `0x5ecfc`: calls a hook pointer if one is installed, otherwise prints an error | E |
| `error_check_part_page` | `0x37d60` / `0x5ec7c`: reads a page's directory state and flag only | E |
| Hot-plug of memory or nodes | no routine named for it (hot-plug, node add or remove) exists in any of the four symbol tables; the hardware inventory is built once at boot from the PROM's records | E for the absence of a named routine; I for the absence of any such function (an unnamed routine would not be found by name) |
| Hub firewall registers (`PI_CPU_PROTECT`, `PI_IO_PROTECT`, `PI_PROT_OVRRD`) | no kernel store | E (census) |
| Bedrock permission, firewall registers | no kernel store (table above) | E (census) |

### 8. Error-driven bank disable (Hub only; effect at the next boot)

`kf_memory_bank_disable` (6.5.30 `0x15361c`, 0x294 bytes; 6.5.22 `0x1570b8`) is the one routine that decides to turn a
memory bank off. It reads `MD_MEMORY_CONFIG` of the node (`ld 24($19)` at `0x15364c`; the register word is passed through
`translate_hub_mcreg` when a flag byte read with `get_nvreg(14468)` is 121), then reads and rewrites the PROM
environment variables `DisableMemSz`, `MemDisReason` and `DisableMemMask` (and `SwapBank` for the swap case) through
`ip27log_getenv` and `ip27log_setenv` (`0x153674`, `0x1537f4` onward). **E** that it writes no hardware register and
that it stores the decision in the PROM's variables. Its only caller is `kf_memory_analysis_print` (`0x152b44`), reached
from `kf_hub_analysis_print`, `kf_analysis_print` and `kf_analysis_tab_print`: the kernel's fault analysis after a
hardware error, not a normal boot path. **E** for the chain; **I** for "after a hardware error" (the callers of
`kf_analysis_tab_print` were not traced). Both PROMs carry the names `DisableMemMask` (IP27 `0x1fc5e5a8`, IP35
`0x1fc6f650`), `DisableMemSz`, `MemDisReason` and `SwapBank`. **E** for the strings; **I** that the PROM applies the
variables on its next run, since the code that reads them was not read.

The IP35 kernels have no `kf_memory_bank_disable` (their `kf_*` set has 16 entries and none writes variables). The
names `DisableMemMask` and `DisableMemSz` appear once each in the IP35 kernel, in `klhwg_mem_invent_info`
(`0x72784`, `0x727a8`), which reads them to build the hardware inventory. **E** for both. IP35 has no kernel writer of
these variables found.

### 9. Directory mode and ECC mode

| What | Finding | Grade |
|---|---|---|
| Directory region size (fine or coarse) | read at boot by `is_fine_dirmode` (Hub bit 17 of `NI_STATUS_REV_ID`, `0x1d690`; Bedrock region size in `rev_id` 47:46 equal to zero, `0x41460`) and kept in a kernel variable (Hub `0x26294` call, stored at `0x262a4`); no kernel store ever changes it; only the PROM sets it ("force_coarse", "Setting region size to %d (%s mode)", "Set coarse mode at Hub") | E |
| `MD_MEMORY_CONFIG` directory-format bit 28 and ignore-ECC bit 29 | read by `set_dir_access` (bit 28, `0x2a4d0`), `check_dir_access`, `mdir_xlate_addr_mem` (`0x49990`), `memerror_sbe_intr` (`0x49fe0`) and others; no kernel store changes either | E |
| ECC interrupt setup | `install_eccintr` (called from `per_hub_init`, `0x26dc4` / Bedrock `0x4e540`): installs the memory-error interrupt handler; no register in the table above | E for the call; I for the contents |
| ECC thresholds and cache ECC | `ecc_init` (called from `cboot`, `0x449c8`), `ecc_handler`, `ecc_force_cache_line_invalid`: processor cache ECC, not the memory controller's | I |

## Things I looked for and did not find

- A store to a region-present, nodes-absent, cached-alias or node-number register after `mlreset`, in either kernel.
- A routine that adds or removes a node, a memory bank or a region after boot.
- Any non-stub partition code (`part_*`, `xpc_*`) that touches hardware. Names exist; bodies are stubs.
- A kernel writer of the PROM's `DisableMem*` variables on IP35.
- Stores to the memory controller's bank-size or directory configuration registers other than the timing fields above.

Limit: all of the above is the census of stores whose base resolves to a literal and an offset known at the site.
A kernel store through a base computed at run time from a data structure (for example a per-node register pointer table)
is invisible to it. The routines named above were read to confirm their own stores; routines that call a function pointer
could not be followed.
