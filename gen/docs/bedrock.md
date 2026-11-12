# Bedrock (node controller), Origin 3000 family

<!-- generated from defs/bedrock.toml by defs-gen - do not edit, change the source -->

Offsets and widths are established: a load or store in the cited routine reaches that offset with that width. Names are inferred from the accessor routine names the shipped objects carry. Constants are masks and values the code applies; their meaning is not read. Reset values are unknown throughout. Bedrock offsets: bits 23:0 of the window address the code forms; the window literals sit 0x1000000 above them, so add 0x1000000 for the offset the kernel uses. Offsets with bit 23 set come through the node-indexed alias (the code adds the node number << 33); the same register is at offset - 0x800000 in the local alias [I]. Example: 0xe80100, the network-interface error word, is 0x680100 in the local alias, where the code reads its neighbours (0x680108 to 0x680120) directly.

Unit `bedrock`, macro prefix `BEDROCK`.
Default source: census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names).

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| bedrock_boot_space | byte | Registers reached through the boot-space window. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `handle_cac_buserr` | 0x18 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_1bcf0` | 0x20 | rw | 64 |  |  | unknown | established | census: 115 sites, 24 routines |
| `memory_iscalias` | 0x28 | rw | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `reg_000040` | 0x40 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `sub_20ee0` | 0x90 | w | 64 |  |  | unknown | established | census: 9 sites, 7 routines |
| `sub_200f0` | 0x98 | r | 64 |  |  | unknown | established | census: 12 sites, 7 routines |
| `sub_20250` | 0xa0 | r | 64 |  |  | unknown | established | census: 5 sites, 3 routines |
| `reg_000108` | 0x108 | w | 64 |  |  | unknown | established | census: 24 sites, 2 routines |
| `startkgclock` | 0x118 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `acktmoclock` | 0x120 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `acktmoclock_128` | 0x128 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ackkgclock` | 0x130 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ackkgclock_138` | 0x138 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `startkgclock_150` | 0x150 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `startkgclock_158` | 0x158 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `hubpi_eint_handler` | 0x400 | rw | 64 |  |  | unknown | established | census: 14 sites, 4 routines |
| `err_int_block_mask` | 0x408 | rw | 64 |  |  | unknown | established | census: 10 sites, 6 routines |
| `err_int_block_mask_410` | 0x410 | rw | 64 |  |  | unknown | established | census: 10 sites, 6 routines |
| `hubpi_spool_get_next` | 0x418 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hubpi_spool_get_next_420` | 0x420 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `hubpi_spool_get_next_430` | 0x430 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hubpi_spool_get_next_440` | 0x440 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hubpi_spool_get_next_448` | 0x448 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hubpi_spool_get_next_450` | 0x450 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hubpi_spool_get_next_460` | 0x460 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hubpi_spool_get_next_468` | 0x468 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hubpi_eint_handler_4c8` | 0x4c8 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hubpi_eint_handler_4d0` | 0x4d0 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `restore_hub_err` | 0x30100 | rw | 64 |  |  | unknown | established | census: 103 sites, 56 routines |
| `reg_400110` | 0x400110 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `reg_400128` | 0x400128 | rw | 64 |  |  | unknown | established | census: 3 sites, 1 routines |
| `ii_llp_error_monitor` | 0x400130 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `sub_3d1d8` | 0x4001f8 | w | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `sub_1bcf0_600000` | 0x600000 | r | 64 |  |  | unknown | established | census: 16 sites, 13 routines |
| `sub_1bcf0_604020` | 0x604020 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_1bcf0_604028` | 0x604028 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_28e3c` | 0x604200 | rw | 64 |  |  | unknown | established | census: 67 sites, 36 routines |
| `reg_608000` | 0x608000 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `reg_608008` | 0x608008 | rw | 64 |  |  | unknown | established | census: 17 sites, 5 routines |
| `reg_608010` | 0x608010 | rw | 64 |  |  | unknown | established | census: 3 sites, 1 routines |
| `sub_11984` | 0x680000 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `sub_10c0` | 0x680008 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `sub_10c0_680010` | 0x680010 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `sub_18a24` | 0x680108 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_18a24_680110` | 0x680110 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_18a24_680118` | 0x680118 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `ni_llp_error_monitor` | 0x680120 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_discovery` | 0x681000 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `part_discovery_681008` | 0x681008 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_discovery_681010` | 0x681010 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_discovery_681018` | 0x681018 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_discovery_682000` | 0x682000 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_discovery_682008` | 0x682008 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_1bcf0_780000` | 0x780000 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `mdir_xlate_addr_mem` | 0x780008 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `reg_790010` | 0x790010 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `reg_7a0000` | 0x7a0000 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `reg_7a0008` | 0x7a0008 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `doacvec` | 0x7a0038 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `reg_7c0018` | 0x7c0018 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `reg_7e0018` | 0x7e0018 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_dumpvec` | 0x800000 | rw | 64 |  |  | unknown | established | census: 19 sites, 16 routines |
| `part_init_node` | 0x800010 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_terminate` | 0x800018 | rw | 64 |  |  | unknown | established | census: 8 sites, 5 routines |
| `save_hub_err` | 0x800020 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `mlreset` | 0x800028 | rw | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `per_hub_init` | 0x800038 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `reg_800040` | 0x800040 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `reg_800048` | 0x800048 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_800050` | 0x800050 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_800058` | 0x800058 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_1bcf0_800090` | 0x800090 | w | 64 |  |  | unknown | established | census: 9 sites, 8 routines |
| `brl1_intr_poll` | 0x800098 | r | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `sub_18a24_8000a0` | 0x8000a0 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `intr_clear_all` | 0x8000a8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_clear_all_8000b0` | 0x8000b0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_clear_all_8000b8` | 0x8000b8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `do_intr_block_bit` | 0x8000c0 | rw | 64 |  |  | unknown | established | census: 5 sites, 2 routines |
| `part_activate` | 0x8000c8 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `part_activate_8000d0` | 0x8000d0 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `part_init_node_8000e8` | 0x8000e8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_8000f0` | 0x8000f0 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `set_timer_intr` | 0x800108 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `set_timer_intr_800110` | 0x800110 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `hub_rtc_init` | 0x800140 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_rtc_init_800148` | 0x800148 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_rtc_init_800150` | 0x800150 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_rtc_init_800158` | 0x800158 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_3ec6c` | 0x800400 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `hub_error_init_800408` | 0x800408 | rw | 64 |  |  | unknown | established | census: 5 sites, 1 routines |
| `hub_error_init_800410` | 0x800410 | rw | 64 |  |  | unknown | established | census: 5 sites, 1 routines |
| `hub_error_init_800418` | 0x800418 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_800420` | 0x800420 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `show_hub_pi_err` | 0x800428 | r | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `hub_error_clear` | 0x800438 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_800448` | 0x800448 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_800458` | 0x800458 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_800468` | 0x800468 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_8004c8` | 0x8004c8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_8004d0` | 0x8004d0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_init_node_a00000` | 0xa00000 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_init_node_a00010` | 0xa00010 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `mlreset_a00018` | 0xa00018 | w | 64 |  |  | unknown | established | census: 5 sites, 5 routines |
| `mlreset_a00028` | 0xa00028 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `per_hub_init_a00038` | 0xa00038 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_a00040` | 0xa00040 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hub_error_init_a00048` | 0xa00048 | r | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hub_error_init_a00050` | 0xa00050 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_a00058` | 0xa00058 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_1bcf0_a00090` | 0xa00090 | w | 64 |  |  | unknown | established | census: 7 sites, 6 routines |
| `intr_connect_level` | 0xa00098 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_clear_all_a000a8` | 0xa000a8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_clear_all_a000b0` | 0xa000b0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `intr_clear_all_a000b8` | 0xa000b8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `do_intr_block_bit_a000c0` | 0xa000c0 | rw | 64 |  |  | unknown | established | census: 5 sites, 2 routines |
| `part_init_node_a000e8` | 0xa000e8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_a000f0` | 0xa000f0 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `set_timer_intr_a00108` | 0xa00108 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `set_timer_intr_a00110` | 0xa00110 | w | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `hub_rtc_init_a00140` | 0xa00140 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_rtc_init_a00148` | 0xa00148 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_rtc_init_a00150` | 0xa00150 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_rtc_init_a00158` | 0xa00158 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_3ec6c_a00400` | 0xa00400 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `hub_error_init_a00408` | 0xa00408 | rw | 64 |  |  | unknown | established | census: 5 sites, 1 routines |
| `hub_error_init_a00410` | 0xa00410 | rw | 64 |  |  | unknown | established | census: 5 sites, 1 routines |
| `hub_error_init_a00418` | 0xa00418 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_a00420` | 0xa00420 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `show_hub_pi_err_a00428` | 0xa00428 | r | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `hub_error_clear_a00438` | 0xa00438 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_a00448` | 0xa00448 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_a00458` | 0xa00458 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_init_a00468` | 0xa00468 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_a004c8` | 0xa004c8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_a004d0` | 0xa004d0 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `md_perf_start_count` | 0xa10000 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `hubii_check_widget_disabled` | 0xc00008 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `hub_widget_id` | 0xc00020 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `hub_set_piomode` | 0xc00110 | rw | 64 |  |  | unknown | established | census: 6 sites, 3 routines |
| `hub_device_inquiry` | 0xc00118 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `hub_widgetdev_enable` | 0xc00120 | rw | 64 |  |  | unknown | established | census: 5 sites, 3 routines |
| `hubii_eint_init` | 0xc00128 | rw | 64 |  |  | unknown | established | census: 6 sites, 5 routines |
| `capture_hub_stats` | 0xc00130 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `hub_error_clear_c00138` | 0xc00138 | rw | 64 |  |  | unknown | established | census: 7 sites, 4 routines |
| `hub_piomap_alloc` | 0xc00160 | rw | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `mlreset_c00190` | 0xc00190 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_c00198` | 0xc00198 | rw | 64 |  |  | unknown | established | census: 7 sites, 4 routines |
| `bte_error_handler` | 0xc001e8 | rw | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `bte_error_handler_c001f8` | 0xc001f8 | rw | 64 |  |  | unknown | established | census: 5 sites, 4 routines |
| `sub_3dbbc` | 0xc00200 | rw | 64 |  |  | unknown | established | census: 5 sites, 3 routines |
| `bte_error_handler_c00220` | 0xc00220 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `bte_error_handler_c00228` | 0xc00228 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_devenable` | 0xc002c8 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_widget_reset` | 0xc00308 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hub_widget_reset_c00388` | 0xc00388 | rw | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `hubiio_crb_free` | 0xc00390 | rw | 64 |  |  | unknown | established | census: 3 sites, 1 routines |
| `per_hub_init_c003a8` | 0xc003a8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `bte_crb_error_handler` | 0xc003b0 | rw | 64 |  |  | unknown | established | census: 7 sites, 1 routines |
| `per_hub_init_c003b8` | 0xc003b8 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `per_hub_init_c003c0` | 0xc003c0 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `hubiio_crb_free_c00400` | 0xc00400 | rw | 64 |  |  | unknown | established | census: 8 sites, 6 routines |
| `hubiio_crb_error_handler` | 0xc00408 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `hubiio_crb_error_handler_c00410` | 0xc00410 | r | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `dump_crb` | 0xc00418 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `io_perf_start_count` | 0xc30000 | rw | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `io_perf_start_count_c30008` | 0xc30008 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `get_hub_chiprev` | 0xe00000 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_init_node_e04000` | 0xe04000 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_init_node_e04010` | 0xe04010 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `part_init_node_e04020` | 0xe04020 | w | 64 |  |  | unknown | established | census: 4 sites, 4 routines |
| `nic_access_hub` | 0xe04030 | rw | 64 |  |  | unknown | established | census: 6 sites, 1 routines |
| `bte_error_handler_e04040` | 0xe04040 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_e04048` | 0xe04048 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `hub_error_clear_e04050` | 0xe04050 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `bte_error_handler_e04058` | 0xe04058 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `bte_error_handler_e04060` | 0xe04060 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_10c0_e08010` | 0xe08010 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `vector_write_node` | 0xe0c000 | rw | 64 |  |  | unknown | established | census: 6 sites, 2 routines |
| `vector_write_node_e0c008` | 0xe0c008 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `vector_write_node_e0c010` | 0xe0c010 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `vector_write_node_e0c020` | 0xe0c020 | r | 64 |  |  | unknown | established | census: 4 sites, 2 routines |
| `vector_read_node` | 0xe0c030 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `vector_write_node_e0c038` | 0xe0c038 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `ni_port_down_reset` | 0xe80000 | r | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `sub_18a24_e80010` | 0xe80010 | r | 64 |  |  | unknown | established | census: 3 sites, 2 routines |
| `sub_18a24_e80100` | 0xe80100 | rw | 64 |  |  | unknown | established | census: 8 sites, 4 routines |
| `sub_18a24_e80120` | 0xe80120 | r | 64 |  |  | unknown | established | census: 13 sites, 6 routines |
| `hub_error_clear_f00120` | 0xf00120 | w | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `memory_read_accessible` | 0xf80000 | rw | 64 |  |  | unknown | established | census: 3 sites, 3 routines |
| `part_init_node_f80008` | 0xf80008 | rw | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `fetchop_flush` | 0xf80020 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `fetchop_flush_f80028` | 0xf80028 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `log_md_errors` | 0xf80040 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `hub_error_clear_f80058` | 0xf80058 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `cpuprom_map` | 0xfa0008 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `per_hub_init_fa0038` | 0xfa0038 | w | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `show_dir_state` | 0xfc0000 | r | 64 |  |  | unknown | established | census: 30 sites, 18 routines |
| `memerror_sbe_intr` | 0xfc0010 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `memerror_sbe_intr_fc0018` | 0xfc0018 | r | 64 |  |  | unknown | established | census: 4 sites, 3 routines |
| `hub_error_clear_fc0028` | 0xfc0028 | r | 64 |  |  | unknown | established | census: 2 sites, 2 routines |
| `migr_effthreshold_diff` | 0xfc0040 | w | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `sub_1242c` | 0xfc0050 | rw | 64 |  |  | unknown | established | census: 2 sites, 1 routines |
| `memerror_sbe_intr_fe0010` | 0xfe0010 | r | 64 |  |  | unknown | established | census: 1 sites, 1 routines |
| `memerror_sbe_intr_fe0018` | 0xfe0018 | r | 64 |  |  | unknown | established | census: 5 sites, 3 routines |
| `boot_space_off_000064` | 0x64 | r | 32 |  | bedrock_boot_space | unknown | established | census: 2 sites, 1 routines |
| `boot_space_nic_get_phase_bits` | 0x78 | r | 64 |  | bedrock_boot_space | unknown | established | census: 2 sites, 2 routines |
| `boot_space_off_000080` | 0x80 | r | 64 |  | bedrock_boot_space | unknown | established | census: 1 sites, 1 routines |
| `boot_space_off_00008c` | 0x8c | r | 32 |  | bedrock_boot_space | unknown | established | census: 1 sites, 1 routines |
| `boot_space_off_00009c` | 0x9c | r | 32 |  | bedrock_boot_space | unknown | established | census: 1 sites, 1 routines |
| `boot_space_cpuprom_detailed_inventory_info_add` | 0xa0 | r | 32 |  | bedrock_boot_space | unknown | established | census: 2 sites, 2 routines |
| `boot_space_cpuprom_detailed_inventory_info_add_a4` | 0xa4 | r | 32 |  | bedrock_boot_space | unknown | established | census: 2 sites, 2 routines |

### Register `handle_cac_buserr`

### Register `sub_1bcf0`

### Register `memory_iscalias`

### Register `reg_000040`

### Register `sub_20ee0`

### Register `sub_200f0`

### Register `sub_20250`

### Register `reg_000108`

### Register `startkgclock`

### Register `acktmoclock`

### Register `acktmoclock_128`

### Register `ackkgclock`

### Register `ackkgclock_138`

### Register `startkgclock_150`

### Register `startkgclock_158`

### Register `hubpi_eint_handler`

### Register `err_int_block_mask`

### Register `err_int_block_mask_410`

### Register `hubpi_spool_get_next`

### Register `hubpi_spool_get_next_420`

### Register `hubpi_spool_get_next_430`

### Register `hubpi_spool_get_next_440`

### Register `hubpi_spool_get_next_448`

### Register `hubpi_spool_get_next_450`

### Register `hubpi_spool_get_next_460`

### Register `hubpi_spool_get_next_468`

### Register `hubpi_eint_handler_4c8`

### Register `hubpi_eint_handler_4d0`

### Register `restore_hub_err`

### Register `reg_400110`

### Register `reg_400128`

### Register `ii_llp_error_monitor`

### Register `sub_3d1d8`

### Register `sub_1bcf0_600000`

### Register `sub_1bcf0_604020`

### Register `sub_1bcf0_604028`

### Register `sub_28e3c`

### Register `reg_608000`

### Register `reg_608008`

### Register `reg_608010`

### Register `sub_11984`

### Register `sub_10c0`

### Register `sub_10c0_680010`

### Register `sub_18a24`

### Register `sub_18a24_680110`

### Register `sub_18a24_680118`

### Register `ni_llp_error_monitor`

### Register `part_discovery`

### Register `part_discovery_681008`

### Register `part_discovery_681010`

### Register `part_discovery_681018`

### Register `part_discovery_682000`

### Register `part_discovery_682008`

### Register `sub_1bcf0_780000`

### Register `mdir_xlate_addr_mem`

### Register `reg_790010`

### Register `reg_7a0000`

### Register `reg_7a0008`

### Register `doacvec`

### Register `reg_7c0018`

### Register `reg_7e0018`

### Register `intr_dumpvec`

### Register `part_init_node`

### Register `part_terminate`

### Register `save_hub_err`

### Register `mlreset`

### Register `per_hub_init`

### Register `reg_800040`

### Register `reg_800048`

### Register `hub_error_init_800050`

### Register `hub_error_init_800058`

### Register `sub_1bcf0_800090`

### Register `brl1_intr_poll`

### Register `sub_18a24_8000a0`

### Register `intr_clear_all`

### Register `intr_clear_all_8000b0`

### Register `intr_clear_all_8000b8`

### Register `do_intr_block_bit`

### Register `part_activate`

### Register `part_activate_8000d0`

### Register `part_init_node_8000e8`

### Register `hub_error_init_8000f0`

### Register `set_timer_intr`

### Register `set_timer_intr_800110`

### Register `hub_rtc_init`

### Register `hub_rtc_init_800148`

### Register `hub_rtc_init_800150`

### Register `hub_rtc_init_800158`

### Register `sub_3ec6c`

### Register `hub_error_init_800408`

### Register `hub_error_init_800410`

### Register `hub_error_init_800418`

### Register `hub_error_init_800420`

### Register `show_hub_pi_err`

### Register `hub_error_clear`

### Register `hub_error_init_800448`

### Register `hub_error_clear_800458`

### Register `hub_error_init_800468`

### Register `hub_error_clear_8004c8`

### Register `hub_error_clear_8004d0`

### Register `part_init_node_a00000`

### Register `part_init_node_a00010`

### Register `mlreset_a00018`

### Register `mlreset_a00028`

### Register `per_hub_init_a00038`

### Register `hub_error_init_a00040`

### Register `hub_error_init_a00048`

### Register `hub_error_init_a00050`

### Register `hub_error_init_a00058`

### Register `sub_1bcf0_a00090`

### Register `intr_connect_level`

### Register `intr_clear_all_a000a8`

### Register `intr_clear_all_a000b0`

### Register `intr_clear_all_a000b8`

### Register `do_intr_block_bit_a000c0`

### Register `part_init_node_a000e8`

### Register `hub_error_init_a000f0`

### Register `set_timer_intr_a00108`

### Register `set_timer_intr_a00110`

### Register `hub_rtc_init_a00140`

### Register `hub_rtc_init_a00148`

### Register `hub_rtc_init_a00150`

### Register `hub_rtc_init_a00158`

### Register `sub_3ec6c_a00400`

### Register `hub_error_init_a00408`

### Register `hub_error_init_a00410`

### Register `hub_error_init_a00418`

### Register `hub_error_init_a00420`

### Register `show_hub_pi_err_a00428`

### Register `hub_error_clear_a00438`

### Register `hub_error_init_a00448`

### Register `hub_error_clear_a00458`

### Register `hub_error_init_a00468`

### Register `hub_error_clear_a004c8`

### Register `hub_error_clear_a004d0`

### Register `md_perf_start_count`

### Register `hubii_check_widget_disabled`

### Register `hub_widget_id`

### Register `hub_set_piomode`

### Register `hub_device_inquiry`

### Register `hub_widgetdev_enable`

### Register `hubii_eint_init`

### Register `capture_hub_stats`

### Register `hub_error_clear_c00138`

### Register `hub_piomap_alloc`

### Register `mlreset_c00190`

### Register `hub_error_clear_c00198`

### Register `bte_error_handler`

### Register `bte_error_handler_c001f8`

### Register `sub_3dbbc`

### Register `bte_error_handler_c00220`

### Register `bte_error_handler_c00228`

### Register `hub_error_devenable`

### Register `hub_widget_reset`

### Register `hub_widget_reset_c00388`

### Register `hubiio_crb_free`

### Register `per_hub_init_c003a8`

### Register `bte_crb_error_handler`

### Register `per_hub_init_c003b8`

### Register `per_hub_init_c003c0`

### Register `hubiio_crb_free_c00400`

### Register `hubiio_crb_error_handler`

### Register `hubiio_crb_error_handler_c00410`

### Register `dump_crb`

### Register `io_perf_start_count`

### Register `io_perf_start_count_c30008`

### Register `get_hub_chiprev`

### Register `part_init_node_e04000`

### Register `part_init_node_e04010`

### Register `part_init_node_e04020`

### Register `nic_access_hub`

### Register `bte_error_handler_e04040`

### Register `hub_error_clear_e04048`

### Register `hub_error_clear_e04050`

### Register `bte_error_handler_e04058`

### Register `bte_error_handler_e04060`

### Register `sub_10c0_e08010`

### Register `vector_write_node`

### Register `vector_write_node_e0c008`

### Register `vector_write_node_e0c010`

### Register `vector_write_node_e0c020`

### Register `vector_read_node`

### Register `vector_write_node_e0c038`

### Register `ni_port_down_reset`

### Register `sub_18a24_e80010`

### Register `sub_18a24_e80100`

### Register `sub_18a24_e80120`

### Register `hub_error_clear_f00120`

### Register `memory_read_accessible`

### Register `part_init_node_f80008`

### Register `fetchop_flush`

### Register `fetchop_flush_f80028`

### Register `log_md_errors`

### Register `hub_error_clear_f80058`

### Register `cpuprom_map`

### Register `per_hub_init_fa0038`

### Register `show_dir_state`

### Register `memerror_sbe_intr`

### Register `memerror_sbe_intr_fc0018`

### Register `hub_error_clear_fc0028`

### Register `migr_effthreshold_diff`

### Register `sub_1242c`

### Register `memerror_sbe_intr_fe0010`

### Register `memerror_sbe_intr_fe0018`

### Register `boot_space_off_000064`

### Register `boot_space_nic_get_phase_bits`

### Register `boot_space_off_000080`

### Register `boot_space_off_00008c`

### Register `boot_space_off_00009c`

### Register `boot_space_cpuprom_detailed_inventory_info_add`

### Register `boot_space_cpuprom_detailed_inventory_info_add_a4`

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BOOT_SPACE_OFF_000064_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BOOT_SPACE_OFF_000064_B_8_0` | 0x1ff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BRL1_INTR_POLL_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_CRB_ERROR_HANDLER_V_800` | 0x800 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_ERROR_HANDLER_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_ERROR_HANDLER_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_ERROR_HANDLER_B_4_0` | 0x11 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_ERROR_HANDLER_B_8` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_ERROR_HANDLER_C001F8_V_FF0000` | 0xff0000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_ERROR_HANDLER_C001F8_V_FFFF` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `BTE_ERROR_HANDLER_V_101` | 0x101 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `CAPTURE_HUB_STATS_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `DOACVEC_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `GET_HUB_CHIPREV_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBIIO_CRB_ERROR_HANDLER_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBIIO_CRB_FREE_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBIIO_CRB_FREE_C00400_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBIIO_CRB_FREE_C00400_B_2_0` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBIIO_CRB_FREE_C00400_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBIIO_CRB_FREE_C00400_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBIIO_CRB_FREE_V_10` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBII_EINT_INIT_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBII_EINT_INIT_B_10_0` | 0x7ff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBII_EINT_INIT_B_13` | 0x2000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUBPI_EINT_HANDLER_4C8_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_ERROR_CLEAR_C00138_V_1000000` | 0x1000000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_4_0` | 0x1f | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_PIOMAP_ALLOC_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_PIOMAP_ALLOC_V_300` | 0x300 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_WIDGET_ID_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_WIDGET_RESET_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `HUB_WIDGET_RESET_C00388_B_4` | 0x10 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `II_LLP_ERROR_MONITOR_B_15_0` | 0xffff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `MDIR_XLATE_ADDR_MEM_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `MEMERROR_SBE_INTR_FE0018_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `MEMORY_ISCALIAS_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `NIC_ACCESS_HUB_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `NIC_ACCESS_HUB_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `NI_LLP_ERROR_MONITOR_B_3_0` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `NI_PORT_DOWN_RESET_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `NI_PORT_DOWN_RESET_B_2_1` | 0x6 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `PER_HUB_INIT_C003A8_V_F0` | 0xf0 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `PER_HUB_INIT_C003B8_V_FF` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `PER_HUB_INIT_V_200000` | 0x200000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_2` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_2A` | 0x2a | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_2B` | 0x2b | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_3` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_35` | 0x35 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_36` | 0x36 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_4` | 0x4 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_5` | 0x5 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_5D` | 0x5d | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_5E` | 0x5e | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_5F` | 0x5f | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_60` | 0x60 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_81` | 0x81 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_83` | 0x83 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_84` | 0x84 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_A` | 0xa | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_B` | 0xb | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_B4` | 0xb4 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_C` | 0xc | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_E` | 0xe | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_000108_V_F` | 0xf | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_400110_V_FF01` | 0xff01 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_400128_B_13` | 0x2000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_400128_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_608008_V_7F80000` | 0x7f80000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_608010_B_8` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_608010_V_7` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `REG_7A0000_B_11_0` | 0xfff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SHOW_DIR_STATE_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_10C0_680010_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_11984_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_18A24_E80120_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_600000_B_1_0` | 0x3 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_600000_B_6_0` | 0x7f | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_600000_B_7_0` | 0xff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_800090_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_800090_V_64` | 0x64 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_A00090_V_100` | 0x100 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_A00090_V_64` | 0x64 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_B_1` | 0x2 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_1BCF0_V_CAFE` | 0xcafe | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_20250_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_20EE0_B_0` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_20EE0_V_40` | 0x40 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_20EE0_V_64` | 0x64 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_20EE0_V_6B` | 0x6b | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_20EE0_V_7` | 0x7 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_28E3C_B_13_4` | 0x3ff0 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_28E3C_B_9_0` | 0x3ff | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_3D1D8_V_1` | 0x1 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_3D1D8_V_10000` | 0x10000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
| `SUB_3D1D8_V_20000` | 0x20000 | inferred | census: loads and stores in the shipped binaries; names from the shipped diagnostic or monitor name, or the public Linux driver name where none is printed (config register_names) |  |
