# Bedrock

Mode: **no-spec** (no specification is held for Bedrock; the system-architecture document that was reviewed has no
register content). Evidence: the IP35 kernel object `kernel.o` and the IP35 boot-directory objects named below,
IRIX 6.5.30. The IP35 CPU PROM image is in the census since the 2026-11-10 rerun (see "What the PROM adds" below).
Census: [census/](census/census.md).
Start-up of several processors by the IP35 PROM (presence bits, rendezvous waits, memory configuration): [docs/questions/ip35-prom-mp-presence-poll.md](../../docs/questions/ip35-prom-mp-presence-poll.md).
The memory-controller configuration word (bank decode, bank select, size probe) as the PROM and kernel use it: [docs/questions/ip35-prom-memory-bank-config.md](../../docs/questions/ip35-prom-memory-bank-config.md). The reset barrier on local-block scratch 1, the boot-master election, the progress registers and the PROM's check that pending bits reach the processor's interrupt lines: [docs/questions/ip35-prom-reset-barrier.md](../../docs/questions/ip35-prom-reset-barrier.md).
The board-identification register at `+0x4000000`, the PROM's processor table and flash configuration block, and the network-interface port status bits the PROM and kernel read: [docs/questions/ip35-board-word-and-config-block.md](../../docs/questions/ip35-board-word-and-config-block.md).

## Window and how it is reached

The kernel object keeps 64-bit literals in its literal pool. The census reads them (`.lit8`, gp 0x7ff0 for
`kernel.o`; the other objects carry gp 0x7800 in their own options section, and the census's `auto-min` rule, which
takes the lowest literal displacement as offset 0, gives the same base in all eleven objects checked (established by
audit: gp read from each object, and each object's literal pool size equals eight bytes times its distinct
displacements, so no literal is skipped)). Literals with top byte 0x92 and low 24 bits below 0x1ffffff are the base
of the register space: 61 of the 119 literals in `kernel.o` (the first draft said 71; recounted from the pool). Other objects that hold such literals: `partition_part.o` (loaded as
`partition.o`), `hubspc.o`, `nic.o`, `l1.o`, `l1_command.o`, `eeprom.o`, `klconfig.o`, `numa_hw.o`, `pda.o`,
`vmdump.o`, `syssgi.o`, and graphics objects (not counted). The register offsets below are the low 24 bits of
the literal plus the displacement of the load or store; a second window with literals starting 0x90000000_18
(`hubspc.o`, `nic.o`) is recorded in the census as `window-18`. It is the local boot space, not a second register block
(next paragraph).
**The `window-18` space (IP35 `hubspc.o`, `nic.o`).** The node address map in the system headers shipped with IRIX 6.5.30 (read for facts, nothing copied) lays out the uncached window with the 0x90 top byte, per node, in 128 MB
pieces for the layout this build matches: the position-independent memory alias at +0x0, the local register space at
+0x10000000, the local boot space at +0x18000000 (the local node's boot PROM and the other devices on the node's directory bus; two PROMs at a 32 MB stride), and for another node `n` the remote register space at +0x30000000 and its boot
space at +0x38000000, all under the node's address bits. So `window-18` is the local boot space (established from the
header; that the IP35 objects follow its second, wider layout rather than the first is inferred from the literal values: the
same code reads +0x10000000 offsets in the IP27 `hubspc.o` and `nic.o`, which the header's first layout puts at the start of the
boot space of that board). The 0x92 literals are a different, smaller alias of the local registers (8 MB, widget 1). Two uses are
read in full:
- `nic_get_phase_bits` (`nic.o` 0x68, 52 bytes) reads the doubleword at boot space +0x78, divides it by 1,000,000, halves
  the quotient, subtracts one and returns the result in two copies, at bit 20 and at bit 27. `nic_access_hub` (0x17c4, 260
  bytes) calls it, ORs it with `(a1 << 10) | (a2 << 2)` and stores the whole word to the doubleword at +0x4030 of the Hub
  register literal (the node picked by a shift of 33), then reads that word back until bit 1 is set (five reads, then
  `us_delay` with its fourth argument, repeated) and returns bit 0. Established. Inferred: the word at +0x78 is a clock
  rate in hertz and the two fields are timing counts of the Hub's MicroLAN (serial-number chip) interface, from the divisor and
  from bit 1 being waited on as "done" and bit 0 returned as "data". Unknown: who writes the word at +0x78 (it is read from
  the boot space of a node; no held routine writes it).
- `cpuprom_detailed_inventory_info_add` (`hubspc.o`) copies the words at boot space +0xa0 and +0xa4 into an inventory
  record; the contents are firmware-supplied and unknown (the Hub page, `hubspc.o` routines).
`per_hub_init`'s store of 15 at `0x9000000030000000` plus the node bits plus `8 * slice + 192` is in the remote register
space of the header (+0x30000000): a register at offset 0xc0 to 0xd8 of the node's registers, reached through the remote
alias (established from the header; the register's role is not read).

That 0x92... is the node-local register space and that the low 24 bits are the register offset: inferred from the
clustering (no named source). Many accesses add a node index (`ld` of the literal, `daddu` with a
per-node value): the table marks those `+ unseen index`; the offset is then the base of an array of per-node
or per-block registers.

## Register inventory (accesses in the IP35 kernel and boot-directory objects)

Generated by `retools/tools/chips/entries.py`. Offsets are shown as the low 24 bits of the physical address (`+0x1xxxxxx`).
Access widths: every access in this table is a 64-bit doubleword except where listed. Block membership
(which of the processor interface, memory, I/O interface, network interface or local block a register belongs to) is
inferred from the prefixes of the routine names that touch it (`hub_`, `hubii_`/`hubiio_`, `md_`/`mdir_`,
`ni_`, `bte_`, `intr_`, `part_`, `nic_`); unknown otherwise.

**Grade of the table.** Established: each offset, width, access direction and site count (a load or store in the cited routine reaches that offset with that width; the generated `include/bedrock.h` carries the same label). Inferred: every name, the role column and the block membership, from routine-name prefixes. Unknown wherever the role column says so.

| register | widths | access | sites | accessors and callers (names from the binary) | field evidence | role (inferred from the names) |
|---|---|---|---:|---|---|---|
| `+0x1000018` | 8 | r | 1 | `handle_cac_buserr` | the routine shifts 1 left by the faulting address's region number (`nasid_to_region` of address bits 47:33, sign-extended from 15 bits) and ANDs the result with this register; a nonzero result sends the error to `nasid_to_partid` and `partition_handle_error`, a zero result (when the mode is not 3) logs an error line | established for that access pattern (IP35 `kernel.o`, sha256 `2e847fdcadfdb958f84acf54ac91325980a0bfcce282f89b6df70da1043b47c4`, load at 0x1d9b4, re-read); inferred that it is a per-region bitmask (one bit per region, the shipped partition logic's input); the register is in `include/bedrock_extra.h` |
| `+0x1000020` | 8 | r | 10 | `sub_1bcf0`, `get_slice`, `getcpuid`, `save_cache_error`, `hubpi_eint_handler`, `klsave_spool_registers` (+2) | load mask 0 (2 sites); load shift shift 0 (4 sites); load shift shift 1 (1 sites) | unknown unless the names say: see the entry |
| `+0x1000028` | 8 | r | 2 | `memory_iscalias`, `page_local_calias` | load shift shift 0 (2 sites) | unknown unless the names say: see the entry |
| `+0x1000078` | 8 | r | 1 | `nic_get_phase_bits` |  | unknown unless the names say: see the entry |
| `+0x1000090` | 8 | w | 7 | `sub_20ee0`, `sub_200f0`, `sub_20250`, `sub_20710`, `sub_20884`, `sub_20988` | store const 0x40 (1 sites); store const 0x64 (1 sites); store const 0x6b (1 sites); store const 0x7 (1 sites) | unknown unless the names say: see the entry |
| `+0x1000098` | 8 | r | 9 | `sub_200f0`, `sub_20ee0`, `sub_20250`, `sub_20710`, `sub_20884`, `sub_20988` |  | unknown unless the names say: see the entry |
| `+0x10000a0` | 4,8 | r | 6 | `cpuprom_detailed_inventory_info_add`, `prom_has_vga_support`, `sub_20250`, `chkdebug` |  | unknown unless the names say: see the entry |
| `+0x1000118` | 8 | w | 2 | `startkgclock`, `prof_intr` |  | unknown unless the names say: see the entry |
| `+0x1000120` to `+0x1000128` (2 slots) | 8 | w | 2 | `acktmoclock` |  | unknown unless the names say: see the entry |
| `+0x1000130` to `+0x1000138` (2 slots) | 8 | w | 2 | `ackkgclock` |  | unknown unless the names say: see the entry |
| `+0x1000150` to `+0x1000158` (2 slots) | 8 | w | 4 | `startkgclock`, `slowkgclock` |  | unknown unless the names say: see the entry |
| `+0x1000400` | 8 | rw | 14 | `hubpi_eint_handler`, `handle_uncac_buserr`, `handle_io_buserr`, `err_int_unblock_mask` |  | unknown unless the names say: see the entry |
| `+0x1000408` to `+0x1000410` (2 slots) | 8 | rw | 20 | `err_int_block_mask`, `err_int_unblock_mask`, `md_int_block`, `md_int_unblock`, `hubpi_eint_handler`, `sub_1bcf0` |  | unknown unless the names say: see the entry |
| `+0x1000418` to `+0x1000420` (2 slots) | 8 | r | 2 | `hubpi_spool_get_next` |  | unknown unless the names say: see the entry |
| `+0x1000430` | 8 | r | 1 | `hubpi_spool_get_next` |  | unknown unless the names say: see the entry |
| `+0x1000440` | 8 | r | 1 | `hubpi_spool_get_next` |  | unknown unless the names say: see the entry |
| `+0x1000448` | 8 | w | 1 | `hubpi_spool_get_next` |  | unknown unless the names say: see the entry |
| `+0x1000450` | 8 | r | 1 | `hubpi_spool_get_next` |  | unknown unless the names say: see the entry |
| `+0x1000460` | 8 | r | 1 | `hubpi_spool_get_next` |  | unknown unless the names say: see the entry |
| `+0x1000468` | 8 | w | 1 | `hubpi_spool_get_next` |  | unknown unless the names say: see the entry |
| `+0x10004c8` to `+0x10004d0` (2 slots) | 8 | rw | 4 | `hubpi_eint_handler` | load mask 7:0 (1 sites); load shift shift 17 (1 sites); load shift shift 63 (1 sites) | unknown unless the names say: see the entry |
| `+0x1030100` | 8 | r | 96 | `restore_hub_err`, `sub_2973c`, `us_delay`, `clear_hub_md_error`, `klsave_md_registers`, `bte_copy` (+44) |  | unknown unless the names say: see the entry |
| `+0x1400130` | 8 | rw | 2 | `ii_llp_error_monitor` | load mask 15:0 (2 sites); load shift shift 16 (1 sites) | unknown unless the names say: see the entry |
| `+0x14001f8` | 8 | w | 2 | `sub_3d1d8` | store const 0x20000 (1 sites) | unknown unless the names say: see the entry |
| `+0x1600000` | 8 | r | 4 | `sub_1bcf0`, `get_nasid`, `is_fine_dirmode` | load mask 1:0 (2 sites); load mask 7:0 (2 sites); load shift shift 46 (2 sites); load shift shift 48 (4 sites) | unknown unless the names say: see the entry |
| `+0x1604020` to `+0x1604028` (2 slots) | 8 | r | 2 | `sub_1bcf0` |  | unknown unless the names say: see the entry |
| `+0x1604200` | 8 | r | 58 | `sub_28e3c`, `nanotime_syscall`, `init_timebase`, `doadjtime`, `nanotime`, `startkgclock` (+27) | load mask 9:0 (58 sites); load shift shift 1 (57 sites); load shift shift 2 (58 sites); load shift shift 4 (58 sites) | unknown unless the names say: see the entry |
| `+0x1680000` | 8 | r | 2 | `sub_11984`, `part_discovery` | load mask 0 (1 sites); load shift shift 1 (1 sites) | unknown unless the names say: see the entry |
| `+0x1680008` to `+0x1680010` (2 slots) | 8 | w | 4 | `sub_10c0`, `ni_reset_port` |  | unknown unless the names say: see the entry |
| `+0x1680108` to `+0x1680118` (3 slots) | 8 | r | 3 | `sub_18a24` |  | unknown unless the names say: see the entry |
| `+0x1680120` | 8 | r | 1 | `ni_llp_error_monitor` | load mask 3:0 (3 sites); load shift shift 11 (1 sites); load shift shift 16 (1 sites); load shift shift 24 (1 sites); load shift shift 40 (1 sites) | unknown unless the names say: see the entry |
| `+0x1681000` + unseen index | 8 | r | 5 | `part_discovery` |  | unknown unless the names say: see the entry |
| `+0x1681008` to `+0x1681018` (3 slots) | 8 | r | 3 | `part_discovery` |  | unknown unless the names say: see the entry |
| `+0x1682000` + unseen index | 8 | r | 3 | `part_discovery` |  | unknown unless the names say: see the entry |
| `+0x1682008` | 8 | r | 1 | `part_discovery` |  | unknown unless the names say: see the entry |
| `+0x1780000` | 8 | r | 1 | `sub_1bcf0` | load shift shift 48 (1 sites) | unknown unless the names say: see the entry |
| `+0x1780008` | 8 | r | 3 | `mdir_xlate_addr_mem`, `mdir_xlate_addr_pdir`, `mdir_xlate_addr_sdir` | load mask 1:0 (3 sites); load shift shift 30 (3 sites) | unknown unless the names say: see the entry |
| `+0x17a0038` | 8 | r | 1 | `doacvec` | load mask 0 (1 sites) | unknown unless the names say: see the entry |
| `+0x1800000` + unseen index | 8 | rw | 19 | `intr_dumpvec`, `part_interrupt`, `timeout_poll`, `show_hub_pi_err`, `dump_error_spool`, `intr_connect_level` (+10) | load shift shift 1 (1 sites) | unknown unless the names say: see the entry |
| `+0x1800010` + unseen index | 8 | w | 1 | `part_init_node` |  | unknown unless the names say: see the entry |
| `+0x1800018` + unseen index | 8 | rw | 8 | `part_terminate`, `part_add_regions`, `part_rm_regions`, `mlreset`, `part_init_node` |  | unknown unless the names say: see the entry |
| `+0x1800020` + unseen index | 8 | r | 1 | `save_hub_err` | load shift shift 62 (1 sites) | unknown unless the names say: see the entry |
| `+0x1800028` + unseen index | 8 | rw | 2 | `mlreset`, `move_buffer` | load shift shift 0 (1 sites) | unknown unless the names say: see the entry |
| `+0x1800038` + unseen index | 8 | w | 1 | `per_hub_init` | store const 0x200000 (1 sites) | unknown unless the names say: see the entry |
| `+0x1800040` to `+0x1800058` (4 slots) | 8 | r | 6 | `hub_error_init` | load shift shift 0 (1 sites) | unknown unless the names say: see the entry |
| `+0x1800090` + unseen index | 8 | w | 8 | `sub_1bcf0`, `cleanup_remote_pi`, `intr_connect_level`, `sendintr`, `debug_stop_all_cpus`, `sendgroupintr` (+1) | store const 0x100 (2 sites); store const 0x64 (1 sites) | unknown unless the names say: see the entry |
| `+0x1800098` + unseen index | 8 | r | 3 | `brl1_intr_poll`, `intr_connect_level` | load mask 4 (1 sites) | unknown unless the names say: see the entry |
| `+0x18000a0` + unseen index | 8 | r | 2 | `sub_18a24`, `hubii_eint_handler` |  | unknown unless the names say: see the entry |
| `+0x18000a8` to `+0x18000b8` (3 slots) | 8 | w | 3 | `intr_clear_all` |  | unknown unless the names say: see the entry |
| `+0x18000c0` + unseen index | 8 | rw | 5 | `do_intr_block_bit`, `intr_clear_all` |  | unknown unless the names say: see the entry |
| `+0x18000c8` to `+0x18000d0` (2 slots) | 8 | w | 4 | `part_activate`, `part_heartbeat` |  | unknown unless the names say: see the entry |
| `+0x18000e8` + unseen index | 8 | w | 1 | `part_init_node` |  | unknown unless the names say: see the entry |
| `+0x18000f0` + unseen index | 8 | rw | 2 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1800108` to `+0x1800110` (2 slots) | 8 | w | 6 | `set_timer_intr`, `timein_body`, `migrate_timeouts` |  | unknown unless the names say: see the entry |
| `+0x1800140` to `+0x1800158` (4 slots) | 8 | w | 4 | `hub_rtc_init` |  | unknown unless the names say: see the entry |
| `+0x1800400` + unseen index | 8 | rw | 3 | `sub_3ec6c`, `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1800408` to `+0x1800410` (2 slots) | 8 | rw | 10 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1800418` to `+0x1800420` (2 slots) | 8 | r | 2 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1800428` + unseen index | 8 | r | 6 | `show_hub_pi_err`, `hub_error_init`, `dump_error_spool` | load shift shift 0 (3 sites) | unknown unless the names say: see the entry |
| `+0x1800438` + unseen index | 8 | w | 1 | `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1800448` + unseen index | 8 | w | 1 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1800458` + unseen index | 8 | w | 1 | `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1800468` + unseen index | 8 | w | 1 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x18004c8` to `+0x18004d0` (2 slots) | 8 | w | 2 | `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1a00000` to `+0x1a00010` (2 slots) | 8 | w | 2 | `part_init_node` |  | unknown unless the names say: see the entry |
| `+0x1a00018` + unseen index | 8 | w | 5 | `mlreset`, `part_init_node`, `part_terminate`, `part_add_regions`, `part_rm_regions` |  | unknown unless the names say: see the entry |
| `+0x1a00028` + unseen index | 8 | w | 1 | `mlreset` |  | unknown unless the names say: see the entry |
| `+0x1a00038` + unseen index | 8 | w | 1 | `per_hub_init` |  | unknown unless the names say: see the entry |
| `+0x1a00040` to `+0x1a00058` (4 slots) | 8 | r | 6 | `hub_error_init` | load shift shift 0 (1 sites) | unknown unless the names say: see the entry |
| `+0x1a00090` + unseen index | 8 | w | 7 | `sub_1bcf0`, `cleanup_remote_pi`, `intr_connect_level`, `sendintr`, `debug_stop_all_cpus`, `sendgroupintr` | store const 0x100 (2 sites); store const 0x64 (1 sites) | unknown unless the names say: see the entry |
| `+0x1a00098` + unseen index | 8 | r | 1 | `intr_connect_level` |  | unknown unless the names say: see the entry |
| `+0x1a000a8` to `+0x1a000b8` (3 slots) | 8 | w | 3 | `intr_clear_all` |  | unknown unless the names say: see the entry |
| `+0x1a000c0` + unseen index | 8 | rw | 5 | `do_intr_block_bit`, `intr_clear_all` |  | unknown unless the names say: see the entry |
| `+0x1a000e8` + unseen index | 8 | w | 1 | `part_init_node` |  | unknown unless the names say: see the entry |
| `+0x1a000f0` + unseen index | 8 | rw | 2 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1a00108` to `+0x1a00110` (2 slots) | 8 | w | 6 | `set_timer_intr`, `timein_body`, `migrate_timeouts` |  | unknown unless the names say: see the entry |
| `+0x1a00140` to `+0x1a00158` (4 slots) | 8 | w | 4 | `hub_rtc_init` |  | unknown unless the names say: see the entry |
| `+0x1a00400` + unseen index | 8 | rw | 3 | `sub_3ec6c`, `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1a00408` to `+0x1a00410` (2 slots) | 8 | rw | 10 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1a00418` to `+0x1a00420` (2 slots) | 8 | r | 2 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1a00428` + unseen index | 8 | r | 4 | `show_hub_pi_err`, `dump_error_spool` | load shift shift 0 (2 sites) | unknown unless the names say: see the entry |
| `+0x1a00438` + unseen index | 8 | w | 1 | `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1a00448` + unseen index | 8 | w | 1 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1a00458` + unseen index | 8 | w | 1 | `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1a00468` + unseen index | 8 | w | 1 | `hub_error_init` |  | unknown unless the names say: see the entry |
| `+0x1a004c8` to `+0x1a004d0` (2 slots) | 8 | w | 2 | `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1a10000` + unseen index | 8 | w | 2 | `md_perf_start_count`, `md_perf_stop_count` |  | unknown unless the names say: see the entry |
| `+0x1c00008` + unseen index | 8 | r | 2 | `hubii_check_widget_disabled`, `hubii_eint_handler` | load shift shift 31 (1 sites); load shift shift 54 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00020` + unseen index | 8 | r | 2 | `hub_widget_id`, `hub_set_piomode` | load mask 3:0 (1 sites); load shift shift 46 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00110` + unseen index | 8 | rw | 6 | `hub_set_piomode`, `hub_device_inquiry`, `is_widget_pio_enabled` |  | unknown unless the names say: see the entry |
| `+0x1c00118` + unseen index | 8 | r | 2 | `hub_device_inquiry`, `hub_dma_enabled` |  | unknown unless the names say: see the entry |
| `+0x1c00120` + unseen index | 8 | rw | 5 | `hub_widgetdev_enable`, `hub_widgetdev_shutdown`, `hub_device_inquiry` |  | unknown unless the names say: see the entry |
| `+0x1c00128` + unseen index | 8 | rw | 6 | `hubii_eint_init`, `sub_b91c`, `per_hub_init`, `hub_xtalk_link_up`, `capture_hub_stats` | load mask 1 (3 sites); load mask 10:0 (1 sites); load mask 13 (2 sites); load shift shift 12 (3 sites) | unknown unless the names say: see the entry |
| `+0x1c00130` + unseen index | 8 | rw | 3 | `capture_hub_stats`, `init_hub_stats` | load mask 15:0 (2 sites); load shift shift 16 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00138` + unseen index | 8 | rw | 7 | `hub_error_clear`, `hubii_eint_handler`, `bte_error_handler`, `hubii_eint_init` | store const 0x1000000 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00160` + unseen index | 8 | rw | 5 | `hub_piomap_alloc`, `sub_21f34`, `hub_piomap_free`, `hub_ioerror_handler` | load mask 3:0 (1 sites); load mask 4:0 (1 sites); load mask 7:0 (1 sites); load shift shift 29 (1 sites); load shift shift 48 (2 sites) | unknown unless the names say: see the entry |
| `+0x1c00190` + unseen index | 8 | w | 1 | `mlreset` |  | unknown unless the names say: see the entry |
| `+0x1c00198` + unseen index | 8 | rw | 7 | `hub_error_clear`, `hubiio_prb_error_handler`, `hub_setup_prb`, `hubii_check_widget_disabled` | load shift shift 15 (2 sites) | unknown unless the names say: see the entry |
| `+0x1c001e8` + unseen index | 8 | rw | 4 | `bte_error_handler`, `hubii_eint_handler`, `hub_xp_error_handler` | load mask 0 (1 sites); load mask 4 (1 sites); load mask 4,0 (1 sites); load mask 8 (1 sites); store const 0x101 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c001f8` + unseen index | 8 | rw | 5 | `bte_error_handler`, `hub_error_clear`, `sub_1aee8`, `hubii_eint_handler` | store const 0xff0000 (1 sites); store const 0xffff (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00200` + unseen index | 8 | rw | 5 | `sub_3dbbc`, `bte_error_handler`, `per_hub_init` |  | unknown unless the names say: see the entry |
| `+0x1c00220` + unseen index | 8 | rw | 2 | `bte_error_handler` |  | unknown unless the names say: see the entry |
| `+0x1c00228` + unseen index | 8 | w | 1 | `bte_error_handler` |  | unknown unless the names say: see the entry |
| `+0x1c002c8` + unseen index | 8 | r | 1 | `hub_error_devenable` | load shift shift 63 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00308` + unseen index | 8 | rw | 2 | `hub_widget_reset` | load mask 7:0 (1 sites); load shift shift 24 (1 sites); load shift shift 3 (2 sites); load shift shift 63 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00388` + unseen index | 8 | rw | 3 | `hub_widget_reset`, `hub_error_devenable` | load mask 4 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00390` + unseen index | 8 | rw | 3 | `hubiio_crb_free` | load mask 4 (2 sites); store const 0x10 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c003a8` + unseen index | 8 | w | 1 | `per_hub_init` | store const 0xf0 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c003b0` + unseen index | 8 | rw | 7 | `bte_crb_error_handler` | load shift shift 47 (1 sites); store const 0x800 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c003b8` to `+0x1c003c0` (2 slots) | 8 | w | 3 | `per_hub_init` | store const 0xff (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00400` + unseen index | 8 | rw | 8 | `hubiio_crb_free`, `bte_crb_error_handler`, `hubiio_crb_error_handler`, `dump_crb`, `crbx`, `hub_widgetdev_shutdown` | load mask 0 (1 sites); load mask 2:0 (1 sites); load mask 3:0 (1 sites); load mask 4:0 (1 sites); load shift shift 13 (3 sites) | unknown unless the names say: see the entry |
| `+0x1c00408` to `+0x1c00410` (2 slots) | 8 | r | 6 | `hubiio_crb_error_handler`, `dump_crb`, `crbx` | load mask 1:0 (1 sites); load shift shift 25 (1 sites); load shift shift 41 (1 sites) | unknown unless the names say: see the entry |
| `+0x1c00418` + unseen index | 8 | r | 2 | `dump_crb`, `crbx` |  | unknown unless the names say: see the entry |
| `+0x1c30000` + unseen index | 8 | rw | 4 | `io_perf_start_count`, `io_perf_stop_count` |  | unknown unless the names say: see the entry |
| `+0x1c30008` + unseen index | 8 | r | 2 | `io_perf_start_count`, `io_perf_update_count` | load shift shift 2 (1 sites) | unknown unless the names say: see the entry |
| `+0x1e00000` + unseen index | 8 | r | 1 | `get_hub_chiprev` | load mask 3:0 (1 sites); load shift shift 28 (1 sites) | unknown unless the names say: see the entry |
| `+0x1e04000` to `+0x1e04010` (2 slots) | 8 | w | 2 | `part_init_node` |  | unknown unless the names say: see the entry |
| `+0x1e04020` + unseen index | 8 | w | 4 | `part_init_node`, `part_terminate`, `part_add_regions`, `part_rm_regions` |  | unknown unless the names say: see the entry |
| `+0x1e04030` + unseen index | 8 | rw | 6 | `nic_access_hub` | load mask 0 (1 sites); load mask 1 (5 sites) | unknown unless the names say: see the entry |
| `+0x1e04040` + unseen index | 8 | r | 1 | `bte_error_handler` |  | unknown unless the names say: see the entry |
| `+0x1e04048` to `+0x1e04050` (2 slots) | 8 | w | 4 | `hub_error_clear`, `bte_error_handler` |  | unknown unless the names say: see the entry |
| `+0x1e04058` to `+0x1e04060` (2 slots) | 8 | w | 2 | `bte_error_handler` |  | unknown unless the names say: see the entry |
| `+0x1e08010` + unseen index | 8 | w | 2 | `sub_10c0` |  | unknown unless the names say: see the entry |
| `+0x1e0c000` + unseen index | 8 | rw | 6 | `vector_write_node`, `vector_read_node` |  | unknown unless the names say: see the entry |
| `+0x1e0c008` + unseen index | 8 | w | 2 | `vector_write_node`, `vector_read_node` |  | unknown unless the names say: see the entry |
| `+0x1e0c010` + unseen index | 8 | w | 1 | `vector_write_node` |  | unknown unless the names say: see the entry |
| `+0x1e0c020` + unseen index | 8 | r | 4 | `vector_write_node`, `vector_read_node` |  | unknown unless the names say: see the entry |
| `+0x1e0c030` + unseen index | 8 | rw | 2 | `vector_read_node` |  | unknown unless the names say: see the entry |
| `+0x1e0c038` + unseen index | 8 | r | 2 | `vector_write_node`, `vector_read_node` |  | unknown unless the names say: see the entry |
| `+0x1e80000` + unseen index | 8 | r | 4 | `ni_port_down_reset`, `sub_18a24`, `init_hub_stats` | load mask 1 (1 sites); load mask 2:1 (1 sites) | unknown unless the names say: see the entry |
| `+0x1e80010` + unseen index | 8 | r | 3 | `sub_18a24`, `sub_18d20` |  | unknown unless the names say: see the entry |
| `+0x1e80100` + unseen index | 8 | rw | 8 | `sub_18a24`, `ni_port_down_reset`, `hubni_print_state`, `sub_18d20` |  | unknown unless the names say: see the entry |
| `+0x1e80120` + unseen index | 8 | r | 13 | `sub_18a24`, `ni_port_down_reset`, `sub_18d20`, `hub_error_clear`, `capture_hub_stats`, `init_hub_stats` | load mask 7:0 (2 sites); load shift shift 16 (1 sites); load shift shift 8 (1 sites) | unknown unless the names say: see the entry |
| `+0x1f00120` + unseen index | 8 | w | 2 | `hub_error_clear` |  | unknown unless the names say: see the entry |
| `+0x1f80000` to `+0x1f80008` (2 slots) | 8 | rw | 7 | `memory_read_accessible`, `memory_write_accessible`, `part_init_node` |  | unknown unless the names say: see the entry |
| `+0x1f80020` to `+0x1f80028` (2 slots) | 8 | r | 2 | `fetchop_flush` |  | unknown unless the names say: see the entry |
| `+0x1f80040` + unseen index | 8 | r | 1 | `log_md_errors` |  | unknown unless the names say: see the entry |
| `+0x1f80058` + unseen index | 8 | r | 2 | `hub_error_clear`, `log_md_errors` |  | unknown unless the names say: see the entry |
| `+0x1fa0008` + unseen index | 8 | rw | 2 | `cpuprom_map` |  | unknown unless the names say: see the entry |
| `+0x1fa0038` + unseen index | 8 | w | 2 | `per_hub_init`, `sub_1bcf0` |  | unknown unless the names say: see the entry |
| `+0x1fc0000` + unseen index | 8 | r | 30 | `show_dir_state`, `part_init_node`, `part_pfdat_permit`, `part_export_page_perms`, `part_unexport_page_nocheck`, `adjust_nmi_handler` (+12) | load mask 0 (28 sites) | unknown unless the names say: see the entry |
| `+0x1fc0010` + unseen index | 8 | r | 1 | `memerror_sbe_intr` | load shift shift 63 (1 sites) | unknown unless the names say: see the entry |
| `+0x1fc0018` + unseen index | 8 | r | 4 | `memerror_sbe_intr`, `hub_error_clear`, `log_md_errors` | load shift shift 1 (1 sites); load shift shift 2 (1 sites); load shift shift 63 (2 sites) | unknown unless the names say: see the entry |
| `+0x1fc0028` + unseen index | 8 | r | 2 | `hub_error_clear`, `log_md_errors` | load shift shift 63 (1 sites) | unknown unless the names say: see the entry |
| `+0x1fc0040` + unseen index | 8 | w | 1 | `migr_effthreshold_diff_set` |  | unknown unless the names say: see the entry |
| `+0x1fc0050` + unseen index | 8 | rw | 2 | `sub_1242c` |  | unknown unless the names say: see the entry |
| `+0x1fe0010` + unseen index | 8 | r | 1 | `memerror_sbe_intr` | load shift shift 3 (1 sites) | unknown unless the names say: see the entry |
| `+0x1fe0018` + unseen index | 8 | r | 5 | `memerror_sbe_intr`, `hub_error_clear`, `log_md_errors` | load mask 0 (3 sites); load shift shift 11 (3 sites); load shift shift 3 (2 sites); load shift shift 52 (3 sites) | unknown unless the names say: see the entry |

## Views of one register (offsets in this table, the header and other documents)

The same register can appear under three offsets, and none of them is a conflict.

- **Local and node-indexed aliases.** The kernel reaches a hub register through the local alias (`+0x1000000` plus the
  hub register offset, with the node implied) or through the node-indexed alias (`+0x1800000` plus the hub register
  offset, with the node number shifted left 33 added). `include/bedrock.h` keeps bits 23:0 only, so a node-indexed
  register is listed 0x800000 above its local-alias offset and the `+0x1000000` base is not shown. Established for the
  window literals and the shift (`check_ni_errors_nasid` in the IP35 `unix`, `0xc000000000058ba4`); the equivalence of
  the two alias offsets is inferred from the two pairs of accesses below.
- **Network-interface error word.** `0xe80100` in `bedrock.h` (`+0x1e80100` here, rw) is the word a document that names
  the hub register offset calls `0x680100`. `check_ni_errors_nasid` reads it at `0xc000000000058bc4`, reads the clear
  word `0x680120` (`0xe80120` in `bedrock.h`) and stores zero to it at `0xc000000000058bfc`, `0xc000000000058c8c` and
  `0xc000000000058e54`. Nothing in the kernel stores to the local alias of that word (`0x680100` in `bedrock.h`), so the
  header has no row there. The three words at `0x680108`, `0x680110` and `0x680118` of the local alias are read directly
  (absolute addresses, `0xc000000000058de8` to `0xc000000000058e10`) and printed in the link-level error report; their
  roles are not read. Established for the accesses.
- **Migration threshold.** `0xfc0040` in `bedrock.h` is `+0x1fc0040`, which by the alias rule above is hub register offset
  `0x7c0040` (inferred), and `+0x40` of the block that starts at `+0x1fc0000`. `migr_effthreshold_diff_set` stores one doubleword
  there (`sd` at `0xc00000000032b5f0` in the IP35 `unix`) and the census has no load of it, so the kernel's access is
  write-only. Whether the hardware register reads back is unknown: no shipped software depends on it.

## What the PROM adds to the census

The census config lists the IP35 CPU PROM (`ip35prom.img`, unpacked to a flat image at `0xc00000001fc00000`; the
scanner cuts it into pseudo-functions after each `jr $31`). The 2026-11-10 rerun adds 17 rows and removes none, and
changes five. The earlier note that the PROM's window base is built at run time does not hold for these sites: the PROM
builds the window literal with `lui`/`daddiu`/`dsll`/`ori` sequences, which `retools/tools/hostfacts.py` resolves
to a constant (for example `0x9200000001000000` plus the displacement). That is established from the instructions.
Every PROM row is reached only from such constant-built bases, except the `window-18` sites listed after the table.

Each changed row, checked by running `hostfacts.py` over the unpacked PROM segment (`--flat --load
0xc00000001fc00000`) and, where the routine is entered by a register jump so the tool does not reach it from its entry,
by reading the instruction words around the site:

| row | change | evidence (PROM address, instruction, resolved target) | status |
|---|---|---|---|
| `0x20` | r to rw | 22 doubleword stores (`sd`) in three pseudo-functions. Read from the instruction words: `k0` is built as `0x9200000001000020` (`0xc00000001fc020e4` to `0xc00000001fc020f4`, and the same sequence at `0xc00000001fc024b4`), then the CP0 words read by `mfc0`/`dmfc0` are stored there in turn (`0xc00000001fc020fc`, `0xc00000001fc02104`, `0xc00000001fc0210c`, `0xc00000001fc024cc` and others), and a fixed marker doubleword is stored at `0xc00000001fc02a90`. 83 PROM loads by `ld` (hostfacts: `abs 0x9200000001000020` at `0xc00000001fc01c54`, `0xc00000001fc01d74` and others). | established; what the stores mean is unknown |
| `0x28` | r to rw | `sd` of 1 at `0xc00000001fc009ac`, `0x28(v0)` with `v0` = `0x9200000001000000` (hostfacts: `abs 0x9200000001000028`, value `0x1`) | established |
| `0x30100` | r to rw | `sd` of zero at `0xc00000001fc6b648` through `a2` = `0x9200000001030100`; `0xc00000001fc6b600` is a short routine that also stores 1 in bit 32 of the word at `0x604200` first | established |
| `0x604200` | r to rw | `sd` at `0xc00000001fc6b644` (value `0x100000000`) and `0xc00000001fc6b688` (a count built from two window-18 reads, below), and a read-modify-write that clears bit 0 (`0xc00000001fc6b6a4` to `0xc00000001fc6b6b0`) and one that sets bit 0 (`0xc00000001fc6b6c8` to `0xc00000001fc6b6d4`); base `0x9200000001604200` | established |
| `0x98` | r w8 unchanged | the one 4-byte access is `lwu` at `0xc00000001fc00b8c` through `0x900000001800009c`, which is the `window-18` boot space, not the `0x92...` register window; it is the separate boot-space row `0x9c`. The register row keeps its 8-byte width (`0xc00000001fc04564` and two more, `0x92...` base). | established |

`window-18` accesses used to be folded into register rows because the join keyed a row by offset only. The census now keys
a row by address space as well as offset (the config's `address_spaces`): the 11 `window-18` sites are seven `boot-space`
rows in `census.tsv` (offsets `0x64`, `0x78`, `0x80`, `0x8c`, `0x9c`, `0xa0`, `0xa4`, folded to 4-byte slots), and none of
them merges with a register row. The register rows that remain are what the `0x92...` window reaches: the `0x98` row is
8 bytes wide (its one 4-byte access was the boot-space `lwu` at `0xc00000001fc00b8c`), and the `0xa0` row is the register
read by `sub_20250` and `chkdebug`. The rows `0x60`, `0x80`, `0x88` and `0x78` no longer exist as register rows.
`include/bedrock.h` carries the boot-space rows in their own section, prefixed `BEDROCK_BOOT_SPACE_`, and the two
register-row names that were really boot-space reads (`BEDROCK_NIC_GET_PHASE_BITS` at `0x78` and
`BEDROCK_CPUPROM_DETAILED_INVENTORY_INFO_ADD` at `0xa0`, with its `_B_0` mask) stay as deprecated aliases of the boot-space
defines (the config's `deprecated_defines`). The `header_skip` entries are gone: the three boot-space-only slots now have
defines in the boot-space section.

Names. A PROM has no symbols, so its pseudo-function names carry an address and never name a define. A register that
only the PROM reaches is `BEDROCK_REG_<offset>` (for example `BEDROCK_REG_608008`); the other defines keep the names the
named kernel routines gave them, so no existing define changed.

## Groups by routine names (inferred)

- `+0x1000000` to `+0x10004d0`, `+0x1030100`: processor-interface-like registers (audit correction on the `+0x1000090` store: none of its three census sites is in the routine it is credited to.
The named routine `sendintr` stores to a computed address, `+0x1800090` or `+0x1a00090` chosen by a slice bit (the second is 0x200000 above the first: `lui` 0x20 gives 0x200000, so a `+0x1820090` reading drops a digit; derived from `sendintr` at 0x206a4 to 0x20700 and the literal at `.lit8`+0x268, which is minus 0x9200000001800000 and is subtracted), with
0x100 plus 107 or, for one caller argument, 0x100 plus 7; the `+0x1000090` stores of 7, 100 and 107 plus the slice
are in routines with no symbol (the census now names them `sub_<address>`: `sub_20710`, `sub_20884`, `sub_20988`) that follow `sendintr`, `install_cpuintr` and `install_dbgintr` in the object, so the
listing labels them with the preceding name): `md_int_block`,
  `get_myid`/`get_slice`/`getcpuid` (read `+0x1000020`), interrupt send and cause (`sendintr`,
  `install_cpuintr`, `cause_intr_disconnect`: `+0x1000090` write, `+0x1000098` read), clock acknowledge and start
  (`acktmoclock`, `ackkgclock`, `startkgclock`: `+0x1000118` to `+0x1000158`), error interrupt masks
  (`err_int_unblock_mask`, `hubpi_eint_handler`: `+0x1000400` to `+0x10004d0`). `+0x1030100` is read at 91 sites
  by time-keeping and statistics routines (`callout_time_to_hz`, `bte_copy`, `capture_hub_stats`): a counter
  or clock (inferred from names). `md_int_block` makes no call and returns no value. It loads the doubleword at
  0x9200000001000000 plus the offset 1032 or 1040, clears bit 24 (`lui 0x100`, then `nor`) and stores it back from
  the delay slot of `jr ra`. The offset is 1040 when bit 0 of the byte at +1320 of the pointer at +8 in the table
  entry is 1, and 1032 when it is 0. That table entry is indexed by the halfword at `lh` offset -15320 from `zero`,
  shifted left 4. On return `v0` still holds the address it used.
- `+0x1600000` to `+0x1681xxx`, `+0x168e7xx`: `+0x1604200` is read at 52 sites by timer routines
  (`counter_intr`, `doadjtime`, `init_timebase`, `generate_unique_id`). The first draft called it a free-running
  counter; the audit found all 52 sites extract bits 13:4 and multiply by five (shift right 4, mask 0x3ff, then
  `sll 2` and add), which reads as a configuration value such as a clock ratio, not a counter (still inferred);
  `+0x1680000` and following: network-interface-like (`ni_reset_port` writes +0x1680008 and +0x1680010;
  `ni_port_down_reset` reads +0x1680110 and +0x1680118; `part_discovery` reads a table at `+0x1681000`: the loop checks 128
  entries of 8 bytes, `+0x1681000` to `+0x16813f8`, and the census's 94 slots and the offset it prints for the
  individual sites are one loop iteration each, an artifact of the scanner unrolling a constant counter, not a measured extent).
- `+0x1780008`, `+0x17a0038`: directory translation (`mdir_xlate_addr_*`) and a vector read (`doacvec`).
- `+0x1800000` and up (80 sites at the base): processor-interface-like again at a second alias (dump and error
  routines, `intr_connect_level`, `do_intr_block_bit`); `+0x1800018` is read by the partition routines. Audit
  correction: the 80 sites at the bare base are not all the base. Many add a displacement the scanner dropped
  (`dump_error_spool` reads `+0x1800428` or `+0x1a00428`, chosen with a slice bit by `movz` between 0x428 and 0x200428 added to the literal 0x9200000001800000; `+0x1820428` would need 0x20428, but the code builds 0x20 << 16; `hub_error_clear` writes
  `+0x1800400`, `+0x1800438`, `+0x1800458`, `+0x18004c8`, `+0x18004d0` and their `+0x1a00000` aliases (0x200000 above, same arithmetic)), so treat that row
  as unresolved sites, not as an array base.
- `+0x1c00000` and up: I/O-interface-like (`hub_widget_id` at `+0x1c00020`, `hubii_*`, `hub_widgetdev_*`,
  `bte_error_handler`, CRB routines `crbx`/`dump_crb`/`hubiio_crb_*` at `+0x1c00400` to `+0x1c00418`);
  `+0x1c30000` performance counters (`io_perf_*`).
- `+0x1e00000` (`get_hub_chiprev`), `+0x1e04000` to `+0x1e04060` (partition and BTE error clear),
  `+0x1e0c000` to `+0x1e0c038` (`vector_read_node`, `vector_write_node`), `+0x1e80000` to `+0x1e80120` (network
  state: `hubni_print_state`, `ni_port_down_reset`).
  `hubni_print_state`: the branch at 0x188d8 (`beq a0,zero`) is never taken, because `a0` is set to the constant
  1000000 by the `lui` at 0x188c0 (0xf) and the `ori` at 0x188c8 (0x4240), and nothing changes it before the branch.
- `+0x1f80000` to `+0x1fe0018`: memory and directory (`memory_read_accessible`, `fetchop_flush`,
  `log_md_errors`, `memerror_sbe_intr`, `check_dir_access`, `get_dir_ent`).

## Access sequences (from the call-site context of each store, inferred unless noted)

**Error clear (`hub_error_clear`; established by audit, read in full, 0x1a0 bytes).** For each of two
processor-interface aliases (`+0x1800000` and `+0x1820000`) it writes all-ones to `+0x400`, `+0x438` and `+0x458`
and zero to `+0x4c8` and `+0x4d0`. It reads and discards the memory error log registers (`+0x1fc0018`, `+0x1fe0018`,
`+0x1f80058`, `+0x1fc0028`; a read with a possible clear-on-read effect is inferred, nothing tests the values).
Nine registers at `+0x1c00198 + 8i` (i from 0 to 8) are each read, ANDed with 0xffff07ffffffffff, ORed with bit 43,
ANDed with 0xffffffc000c00000 and ORed with 3; all-ones goes to `+0x1c001f8`; `+0x1c00138` is read and bit 28 cleared;
`+0x1e04048` gets all-ones and `+0x1e04050` zero (the first draft said these were zero-fills); last, zero is written
to 15 registers at `+0x1f00120 + 8i` (i from 0 to 14; the first draft said 14). Everything is indexed by the node
number shifted left 33.

**Widget reset handshake (`hub_widget_reset`; established by audit, read in full).** `+0x1c00308` is the base of
eight registers, `+0x1c00308 + 8i`. For i from 0 to 7 it reads the register and skips it unless bit 63 is set and
bits 31:24 equal the widget number passed in. For the matching entry it writes zero to that register, writes
0x10 plus i to the single register `+0x1c00388`, reads `+0x1c00388` back once, and if bit 4 is set reports an
error through an assertion call; it then goes on with the next i. There is no polling loop (the first draft said
there was one). The meaning of the registers is unknown.

**Node initialisation (`per_hub_init`).** Stores 240 (0xf0) at `+0x1c003a8`, reads `+0x1c00128` and tests bit 13
to choose 4 (bit clear) or 8 (bit set) for `+0x1c00200`, writes 0xfffe or 0xfffffe (depending on a global compared with 33) at
`+0x1c003c0`, 255 at `+0x1c003b8`, and 0x200000 at `+0x1800038` and `+0x1a00038`, zero at `+0x1fa0038` (established by audit, read in full). It also stores
15 at `0x9000000030000000` plus the node offset plus `8 * slice + 192` for each of the four processor slices
that `cpu_enabled` reports as absent, in the remote register space (`0x9000000030000000`, see "The `window-18` space"); the first draft did not list it.

**Network port reset (`ni_reset_port`, read in full: 8 instructions).** Writes 1 to `+0x1680010` and 6 to
`+0x1680008`. (established; roles unknown)

**Interrupt connect (`intr_connect_level`).** Stores into `+0x1800000` plus an index, ORs a bit into a
per-CPU mask `1 << level`; the register offsets are indexed and not resolved (inferred from context).

## Error registers: refused or timed-out writes and failed reads

Read from `kernel.o` of the IP35 boot directory (IRIX 6.5.30): `hub_error_init`, `hub_error_clear`,
`hubpi_eint_handler`, `handle_uncac_buserr`, `get_matching_spool_addr`, `save_hub_pi_error`, `save_hub_io_error`,
`show_hub_pi_err`, `show_pi_error_spool_entry`, `hubii_eint_init`, `hubii_eint_handler`,
`hubiio_crb_error_handler`, `hubiio_prb_error_handler`, `dump_crb` and the message tables they print from. No
Bedrock specification is held, so the binaries are the evidence and the public Linux Hub headers are compared
afterwards (below), never used to fill a field. Offsets are within a block. The processor interface (PI) block is
at the alias base, the I/O interface (II) block at alias base `+0x400000`. The kernel reaches the blocks at a
local alias (`+0x1000000`, II at `+0x1400000`) and at a node-indexed alias (`+0x1800000`, II at `+0x1c00000`);
`hub_error_init`, `hub_error_clear` and `save_hub_err` visit a second PI register file at `+0x200000` above the
first (established: the 0x200000 addend is in each routine). That there are two PIs, each with a CPU A and a CPU B
side, is established by the table strings ("Processor interface 0", "Processor interface 1", "CPU A", "CPU B") and
by the `BEDROCK PI %d ... %c` print formats. All registers are read and written as 64-bit doublewords.

### Graded register table

Grade is of the role and fields: **E** established (the routine read in full, or an arithmetic the code performs,
or a field range the binary prints), **I** inferred, **U** unknown. Names are descriptive, taken from the message
tables and routine names; they are not specification names.

| block offset | register | access seen | who touches it (`kernel.o`) | what the code does | grade |
|---|---|---|---|---|---|
| PI `0x040`, `0x048` | CPU present A, B | r | `hub_error_init` | read per PI and combined with the enable word of the same side | inferred |
| PI `0x050`, `0x058` | CPU enable A, B | r | `hub_error_init`, `save_hub_pi_error` | when the A word is zero the saved pending word has every CPU A bit cleared (mask `0xfffffffaab555555`), when the B word is zero every CPU B bit (mask `0xfffffffd55aaaaaa`) | established |
| PI `0x400` | error interrupt pending | rw | `hubpi_eint_handler`, `hub_error_clear`, `handle_uncac_buserr`, `save_hub_pi_error` | bits 0 to 34 named below; handler writes the one bit it handled; `hub_error_clear` writes all ones | established (bits; that a write of one clears is inferred) |
| PI `0x408`, `0x410` | error interrupt mask A, B | rw | `hubpi_eint_handler`, `hub_error_init` | handler ANDs pending with the mask of its own CPU side (side from bit 0 of a per-CPU slice byte); init stores fatal or miscellaneous masks and clears bit 21 in A and bit 20 in B | established |
| PI `0x418`, `0x420` | error spool address A, B | r | `hub_error_init`, `show_hub_pi_err` | read per side and kept in the per-node record; `show_hub_pi_err` walks 8-byte entries from it | inferred |
| PI `0x428` | error spool size | r | `hub_error_init`, `show_hub_pi_err` | when nonzero the spool size is `4096 << (value - 1)` bytes | established (the byte unit follows from the pointer wrap in `hubpi_spool_get_next`) |
| PI `0x430`, `0x450` | error status 0 A, B | r | `save_hub_pi_error`, `show_hub_pi_err` | saved only when bit 63 is set; fields below | established |
| PI `0x438`, `0x458` | status 0 A, B, second address | w | `hub_error_clear` | all ones written, in the same routine and at the same step as the writes that re-arm the pending register and the spurious message headers; no held routine reads the alias back | unknown (role). Settled by: a published Bedrock register list (none held), or on a node controller a read of status 0 before and after a write to the alias; no further binary route, since no held code reads it |
| PI `0x440`, `0x460` | error status 1 A, B | r | `save_hub_pi_error`, `show_hub_pi_err` | fields below | established |
| PI `0x448`, `0x468` | status 1 A, B, second address | w | `hub_error_init`, `hubpi_spool_get_next` | zero written for every node's A and B pair at init (a loop in `hub_error_init`), and zero written again by `hubpi_spool_get_next` after it has read status 0 and 1 (re-read in the kernel object: in address order the store comes after the two status loads) | unknown (role); inferred only that the second write releases the latched status. Settled by: a published Bedrock register list (none held), or a hardware read of status 1 before and after a write to the alias |
| PI `0x4c8` | spurious message header 0 | rw | `hubpi_eint_handler`, `save_hub_pi_error`, `hub_error_clear` | fields below; zero written to re-arm | established |
| PI `0x4d0` | spurious message header 1 | rw | same | bits 63:53 message source; zero written to re-arm | established |
| II `0x008` | widget status | r | `hubii_eint_handler`, `save_hub_io_error`, `hubii_check_widget_disabled` | bit 32 error ("crazy"); with it set, bit 9 retry timeout, bit 5 tail timeout, bit 4 credit timeout name the reason | established |
| II `0x138` | interrupt destination | rw | `hubii_eint_init`, `hubii_eint_handler`, `hub_error_clear` | bits 6:0 level, bit 8 PI side, bits 16:9 node, bit 24 set at init, bit 28 cleared by the handler and by `hub_error_clear` | established (fields; the enable and sent meaning of bits 24 and 28 is inferred) |
| II `0x198 + 8i`, i = 0 to 8 | pending request buffer entries (PRB) | rw | `hubiio_prb_error_handler`, `hub_error_clear`, `dump_crb` | entry 0 is widget 0, entries 1 to 8 widgets 8 to 15; only bit 48 is tested; bits 48 to 51 named below | established |
| II `0x1e8` | shutdown status | r | `hubii_eint_handler`, `bte_error_handler`, `hub_xp_error_handler` | bit 0 widget 0 shut down, bit 4 BTE 0, bit 8 BTE 1 | established |
| II `0x1f8` | error clear | w | `hubii_eint_handler`, `hub_error_clear` | `0xffffff` after the buffers are handled; `hub_error_clear` writes all ones | established (the per-source meaning of the bits is inferred) |
| II `0x220`, `0x228` | error header 1, 2 | r | `save_hub_io_ieph`, `show_hub_io_ieph` | fields below; saved raw | established |
| II `0x400 + 0x20i`, i = 0 to 14 | CRB entry A | r | `hubiio_crb_error_handler`, `save_hub_io_crb`, `dump_crb` | fields below | established |
| II `0x408 + 0x20i` | CRB entry B | r | same | bits 32:30 and 41:40 are compared with constants to tell a BTE entry from a processor one; fields not named in the dump | inferred |
| II `0x410 + 0x20i` | CRB entry C | r | same | bit 48 chooses which bit of entry B is handed to the BTE handler | inferred |
| II `0x10000`, `0x20000` | BTE 0, BTE 1 status | r | `save_hub_io_error` | bits 15:0 length in cache lines, bit 16 error | established |

Totals: 22 rows, graded **16 established, 4 inferred, 2 unknown**. The sub-items inside established rows that are only inferred or unknown are listed in the open questions.

**PI error status 0** (the binary prints these ranges): bits 2:0 error type; 5:3 request-buffer number; 16:6
message supplemental; 24:17 message command (name table indexed 0 to 255); 61:25 error address, printed
as `value << 3`; bit 62 overrun; bit 63 valid. The type is named from one of two tables chosen by bit 42 of status 1
(0 read buffer, 1 write buffer). Read: 0 access error, 1 uncached partial error, 2 directory error, 3 timeout error,
4 poisoned access violation, 5 too many NACKs, 6 response data error, 7 packet length error. Write: 0 access
error, 1 uncached partial error, 3 timeout error, 6 response data error, 7 packet length error; 2, 4 and 5 are
"undefined". (Established: both tables dumped from the data section.)

**PI error status 1**: 20:0 spool count; 28:21 CRB timeout counter; 38:29 invalidate counter; 41:39 read or write
buffer number; 42 write-buffer flag (selects the type table above and "WRB" or "RRB" in the print); 52:43 CRB status;
63:53 message source. (Established.)

**PI spurious header 0**: bit 0 error status B was valid, bit 1 error status A was valid, 16:6 message supplemental,
24:17 message command, 61:25 address (`<< 3`), 62 tail bit, 63 valid. (Established.)

**Pending bits (`+0x400`), named by the kernel's table**, B side at even bit numbers 0 to 24 and A side at the odd:
0/1 spool count compare; 2/3 spurious message; **4/5 CPU write timeout error**; **6/7 CPU write error response
(a WERR or PWERR reply)**; 8/9 SysState parity; 10/11 SysAD ECC during data cycle; 12/13 SysAD ECC during address
cycle; 14/15 SysCmd parity during data cycle; 16/17 SysCmd parity during address cycle; 18/19 WERR or TERR during
spool; **20/21 CPU received an uncorrectable error during an uncached load**; 22/23 SysState tag error; 24
memory/directory uncorrectable error; 25/26 SysAD data quality bad (B at 25, A at 26); 27/28 uncorrectable error
during a cached load (B 27, A 28); 29/30 data from the crossbar with the wrong number of cycles (B 29, A 30);
31/32 illegal intervention or invalidate type and state response (B 31, A 32); 33/34 timeout waiting for the
head of the state-pending FIFO (B 33, A 34). Bits 25 to 34 alternate B, A starting at B. The kernel's fatal masks
are `0x5408aaa00` (A) and `0x2a0455500` (B), its miscellaneous masks `0x142000aa` (A) and `0xa100055` (B): fatal A
is bits 9, 11, 13, 15, 17, 19, 23, 30, 32, 34; miscellaneous A is bits 1, 3, 5, 7, 21, 26, 28 (established:
initialised words in the small-data section).

**How `hub_error_init` builds the two error masks (established, `kernel.o` `hub_error_init`, read in full; the pairing is inferred).**
It runs the same step for each of the node's two processor-interface blocks (window offsets `0x1800000` and `0x1a00000`), and
tests each side with the words at `+0x40`/`+0x50` (side A) and `+0x48`/`+0x58` (side B): a side counts as present when the AND of
its two words is nonzero. With both sides present it stores into the A mask (`+0x408`) the B fatal mask OR the A miscellaneous
mask, and into the B mask (`+0x410`) the A fatal mask OR the B miscellaneous mask, so a fatal error of one CPU side interrupts
the other side. With only one side present its mask is its own fatal OR its own miscellaneous mask. Bit 24 (memory or directory
uncorrectable error), which has no A and B pair, is ORed into the first mask the routine actually stores (a local starts at
`0x1000000` and is cleared after the first store, `hub_error_init` `0x17bd4`, `0x17e60`, `0x17e78`): that is the A mask of the first
processor-interface block that has side A present, else its B mask, else the same choice in the second block. So exactly one
mask in the node enables bit 24, which keeps the error from interrupting two CPUs at once (the reason is the structure; no
string states it, inferred). Afterwards it clears bit 21 in each A mask and bit 20 in each B mask (`0xffdf....` and
`0xffef....` ANDs) and zeroes the `+0x448` and `+0x468` families.

**II CRB entry A** (printed by `dump_crb`): bit 0 I/O write operation; bit 1 valid; 39:2 network address (`<< 2`);
44:40 transaction number of the Crosstalk request; 48:45 source id; 49 error set in the incoming Crosstalk request;
50 entry has been marked; 51 uncorrectable error on incoming data from the network; 54:52 error code; 55 entry has an
error. **PRB bits**: 48 write response packet error; 49 read response timeout; 50 spurious write response; 51
spurious read response. **Error header 1**: 6:0 command, 18:8 supplemental, 30:20 source, 35:32 error type
(long or short, request or reply packet), 40 overrun. **Error header 2**: 37:0 address, 40 tail. (Established.)

### What sets each bit and what is latched

1. **Failed or timed-out uncached write.** The PI sets pending bit 4/5 (timeout) or 6/7 (a WERR or PWERR reply was
   received) for the CPU side that issued it, and latches status 0 (type, command, address) and status 1 for that
   side if its valid bit is clear; a second error sets overrun instead (established for the field layout and
   names, from the print code). The kernel's handler for these four bits calls `process_error_spool` and then
   writes only the handled bit back to `+0x400`. That the hardware latches at the moment of the refusal rather than
   later is inferred; the order of the pending bit and the status valid bit is unknown.
2. **Failed uncached read.** Pending bit 20/21 (uncorrectable error during an uncached load) is what
   `handle_uncac_buserr` tests, for its own CPU side, after the bus-error exception; if it is set and the faulting
   address belongs to another partition the error is passed to `partition_handle_error` and the bit is written
   back. A read that gets a timeout reply is recorded with type 3 (timeout) in a status 0 and in the in-memory
   spool, not in a pending bit of its own (inferred: no read-timeout bit exists in the table; the type names are
   established). `hub_error_init` clears bit 21 in mask A and bit 20 in mask B at init, so the uncorrectable-read
   interrupt is masked by the kernel (established: the AND constants are in `hub_error_init`); that the bus-error
   exception is then the report path is inferred.
3. **Error spool.** `get_matching_spool_addr` compares the faulting physical address and access size with the
   spooled address (status 0 bits 61:25 `<< 3`) of each 8-byte entry to decide whether the exception is the one it
   is looking at (established: the routine's compares). The entry layout is established from the kernel's printer
   and differs from status 0: type 2:0, supplemental 5:3, T5 request 8:6, CRB number 11:9, write-buffer flag 12, CRB
   status 22:13, command 30:23, cache line address 63:31 (shifted left 7); see chips/hub/README.md, "Error stack entry
   layout". The ring size register counts bytes (`4096 << (n - 1)`), the ring is aligned to its size and the read
   pointer wraps by subtracting the size. That the hardware writes the entries is inferred (no kernel store reaches
   the ring).
4. **I/O writes and reads that leave the node (II).** A failed or timed-out PIO request sets the error bit in the
   CRB entry (bit 55) with a code in bits 54:52; the kernel's table names the eight codes: 0 directory error,
   1 poison error, 2 write error, 3 access error, 4 partial write error, 5 partial read error, 6 timeout error, 7
   Crosstalk error packet. `hubiio_crb_error_handler` treats 0, 5, 6 and 7 as fatal (error dump and a "Fatal ... on hub" message) and
   1 to 4 as recoverable (the recoverable arm frees the entry with `hubiio_crb_free`; message "PIO Write error from
   widget %d, cleaning up and continuing" for the write case). Established from the jump table and both message
   paths. Its continuation into `hub_ioerror_handler` is inferred: the table targets are not dumped, and the routine
   has no direct call to that name.
   Which CRB error code a refused write to a nonexistent widget, to a protected region or to a full request buffer
   produces: unknown.
5. **Protected-region replies.** The strings "Protection error response" and "Vector response timeout" are not Bedrock
   error texts: they are entries of the table of return-code texts for the router vector routines (return codes -6 and -7;
   see the Hub page, "The texts for the vector routines' return codes"; established). The kernel also prints protection-index,
   protection-value and protection-rights ECC fields in its memory/directory error decode (strings only; those routines were
   not read). Which of the status 0 types a protection violation of memory sets, and whether it is the same as the poisoned
   access violation (type 4) or the access error (type 0): unknown.

### Interrupts

- **PI error interrupt.** `hub_error_init` connects `hubpi_eint_handler` with `cause_intr_connect(6, handler, 1)`,
  a table indexed by CPU cause line (the routine refuses 2, 3 and anything above 7). That the line is Cause IP6
  and that all four pending-bit pairs share it: inferred (the kernel handles the vector in one handler and tests
  all 35 bits there).
- **II error interrupt.** `hubii_eint_init` reserves a level at run time (`intr_heuristic`, name "HUB IO error
  interrupt"), connects `hubii_eint_handler` and stores level, PI side, node and bit 24 in `+0x138`. The level
  number is chosen at run time: unknown from the object. The handler reads status (`+0x8`) first: bit 32 set means
  the link failed (reason from bits 9, 5, 4 or from `+0x1e8`), otherwise it processes the CRB and PRB entries, writes
  `0xffffff` to `+0x1f8` and clears bit 28 of `+0x138`.
- **Network interface error interrupt.** `hubni_eint_init` connects the handler with vector 126 (established: the
  constant is in the call). The handler is shared with the remote-partition cleanup path.

### Against the public Linux Hub headers (v6.6; reported after the reading above)

Hub is the previous node controller, a sibling, so agreement is a hypothesis check and disagreement a finding.

- **Agree.** PI registers `0x400` to `0x468` have the same offsets and the same order as the Hub headers (pending,
  mask A and B, spool address A and B, spool size, status 0 and 1 for A and B, each followed by an eighth-byte
  neighbour). Pending bits 0 to 24 are the same events in the same positions. Linux's fatal and miscellaneous
  masks for CPU A are bit-for-bit the Bedrock masks restricted to bits 24 and below. Status 0 and 1 field
  ranges are identical (type 2:0, request 5:3, supplemental 16:6, command 24:17, address 61:25, overrun 62, valid
  63; spool 20:0, timeout count 28:21, invalidate count 38:29, buffer number 41:39, write-buffer flag 42, CRB
  status 52:43, source 63:53). Error types agree by number (read 1, 2, 3; write 0, 1, 3). II widget status
  error bit 32 and retry timeout bit 9, the interrupt destination enable bit 24 and sent bit 28, the clear
  register at II `0x1f8` and the CRB error codes 0 to 5 and 7 agree.
- **Disagree.** The Hub destination register has a six-bit level and an eight-bit node at bit 8; the Bedrock code
  masks seven bits of level, puts a PI-side bit at bit 8 and the node at bits 16:9. Pending bits 25 to 34 and the
  PRB-bit-48 handler are not in the Hub header. Linux names `0x438` and the three like it "clear on read"; the
  Bedrock kernel only writes them, so whether a read clears is unknown for Bedrock.
- **Not comparable.** The Hub headers have no Bedrock-style second PI register file.

## Register walk of the crash dump (`dump_hub_registers`, IP35 kernel)

Image: `6.5.30/unix.IP35` (13,104,040 bytes, sha256 `412a1aae553a348376bc30cacbaf65044de1745d30222f02ec5f88297dcb1dfa`). The
other linked 6.5.30 IP35 kernel in the workspace (14,238,624 bytes, sha256 `8404e226a649c622ebefe452a234566d74cbb81e802d793f22acdcbab518b9a8`)
carries the same table byte for byte, with the routine at `0xc0000000002e70dc`.

**What it reads.** The crash dump driver prints "Dumping hub information ..." and calls `dump_hub_data`
(`0xc0000000002c90e4`). That routine tests the tunable `dump_hub_info` (a word at `0xc00000000163c64c`, initial value 2):
above 0 it calls `dump_hub_registers` (`0xc0000000002c956c`, 944 bytes, read in full); 2 or more also calls
`dump_hub_dir_mem` (`0xc0000000002c9144`). The next word, `dump_level` (`0xc00000000163c650`), starts at 4. Established.

`dump_hub_registers` walks a table of 67 `{first, last}` offset pairs (16 bytes each, `last` inclusive, ended by a pair
whose first word is negative) at `0xc000000001597388`, in 8-byte steps: 521 registers. For each node in the node list it
forms `0x9200000001800000` (the pool word at gp+0x8f0) plus the node's NASID shifted left 33 plus the offset. That is the
node-named form of the 8 MB register window (bit 23 set); the local alias is `0x9200000001000000`. Every read is a plain
64-bit `ld` (the load is at `0xc0000000002c97e0`; `0xc0000000002e7350` in the other kernel) with no fault guard and no value check. The value goes into slot `(offset >> 3) & 0x7ff` of a 16 KB staging
buffer on the stack, pre-filled with `0x5555555555555555`. The buffer goes to the block writer
(`compress_and_write_block`, `0xc0000000002c8f6c`) whenever the 16 KB page number or offset bits 23:20 change, so the dump
holds a sparse image of the window. The node count is the word at gp+0x2824, plus 4 when a word at +0x184 of a node
structure equals `0x5045626b`; the NASIDs come from a halfword table at gp-0x1cc8. Established for the loop; what the
`0x5045626b` word marks is unknown. The table is the same for every node and covers the second processor interface at
`+0x200000`.

The 67 pairs, as offsets from the window base. Names are from the public SN1 register headers (Linux v2.5.40 `hubpi.h`,
`hubio.h`, `hublb.h`, `hubni.h`, `hubxb.h`, `hubmd.h`); the second interface repeats the first interface's names:

**Grade of the table.** Established: the 67 offset pairs and their counts, which are the table the shipped kernel's dump routine walks (read above; not re-read for this grade). Inferred: the names, matched by offset from the public SN1 headers, and the block label of each row.

| # | offsets | count | block | public names |
|---|---|---:|---|---|
| 1 | `0x0` to `0x58` | 12 | PI interface 0 | PI_CPU_PROTECT to PI_CPU_ENABLE_B |
| 2 | `0x98` to `0xc0` | 6 | PI interface 0 | PI_INT_PEND0 to PI_INT_MASK1_B |
| 3 | `0xd8` to `0xf0` | 4 | PI interface 0 | PI_CC_PEND_CLR_A to PI_INT_PEND1_REMAP |
| 4 | `0x108` to `0x160` | 12 | PI interface 0 | PI_RT_COMPARE_A to PI_DEBUG_SEL |
| 5 | `0x300` to `0x348` | 10 | PI interface 0 | PI_GFX_PAGE_A to PI_GFX_INT_CMP_B |
| 6 | `0x3f8` to `0x430` | 8 | PI interface 0 | PI_ERR_INT_PEND_WR to PI_ERR_STATUS0_A |
| 7 | `0x440` | 1 | PI interface 0 | PI_ERR_STATUS1_A |
| 8 | `0x450` | 1 | PI interface 0 | PI_ERR_STATUS0_B |
| 9 | `0x460` | 1 | PI interface 0 | PI_ERR_STATUS1_B |
| 10 | `0x470` to `0x4d8` | 14 | PI interface 0 | PI_SPOOL_CMP_A to PI_ERR_INJECT |
| 11 | `0x10060` | 1 | PI interface 0 | PI_REPLY_LEVEL |
| 12 | `0x20068` | 1 | PI interface 0 | PI_GFX_CREDIT_MODE |
| 13 | `0x30100` | 1 | PI interface 0 | PI_RT_COUNTER |
| 14 | `0x40200` to `0x40210` | 3 | PI interface 0 | PI_PERF_CNTL_A to PI_PERF_CNTR1_A |
| 15 | `0x50200` to `0x50210` | 3 | PI interface 0 | PI_PERF_CNTL_B to PI_PERF_CNTR1_B |
| 16 | `0x200000` to `0x200058` | 12 | PI interface 1 | PI_CPU_PROTECT to PI_CPU_ENABLE_B |
| 17 | `0x200098` to `0x2000c0` | 6 | PI interface 1 | PI_INT_PEND0 to PI_INT_MASK1_B |
| 18 | `0x2000d8` to `0x2000f0` | 4 | PI interface 1 | PI_CC_PEND_CLR_A to PI_INT_PEND1_REMAP |
| 19 | `0x200108` to `0x200160` | 12 | PI interface 1 | PI_RT_COMPARE_A to PI_DEBUG_SEL |
| 20 | `0x200300` to `0x200348` | 10 | PI interface 1 | PI_GFX_PAGE_A to PI_GFX_INT_CMP_B |
| 21 | `0x2003f8` to `0x200430` | 8 | PI interface 1 | PI_ERR_INT_PEND_WR to PI_ERR_STATUS0_A |
| 22 | `0x200440` | 1 | PI interface 1 | PI_ERR_STATUS1_A |
| 23 | `0x200450` | 1 | PI interface 1 | PI_ERR_STATUS0_B |
| 24 | `0x200460` | 1 | PI interface 1 | PI_ERR_STATUS1_B |
| 25 | `0x200470` to `0x2004d8` | 14 | PI interface 1 | PI_SPOOL_CMP_A to PI_ERR_INJECT |
| 26 | `0x210060` | 1 | PI interface 1 | PI_REPLY_LEVEL |
| 27 | `0x220068` | 1 | PI interface 1 | PI_GFX_CREDIT_MODE |
| 28 | `0x230100` | 1 | PI interface 1 | PI_RT_COUNTER |
| 29 | `0x240200` to `0x240210` | 3 | PI interface 1 | PI_PERF_CNTL_A to PI_PERF_CNTR1_A |
| 30 | `0x250200` to `0x250210` | 3 | PI interface 1 | PI_PERF_CNTL_B to PI_PERF_CNTR1_B |
| 31 | `0x400000` to `0x400008` | 2 | I/O | IIO_WID to IIO_WSTAT |
| 32 | `0x400020` | 1 | I/O | IIO_WCR |
| 33 | `0x400100` to `0x400228` | 38 | I/O | IIO_ILAPR to IIO_IIEPH2 |
| 34 | `0x400300` to `0x400340` | 9 | I/O | IIO_IPCA to IIO_IPRTE7 |
| 35 | `0x400388` to `0x4003c0` | 8 | I/O | IIO_IPDR to IIO_ICTP |
| 36 | `0x400400` to `0x4005d8` | 60 | I/O | IIO_ICRB0_A to IIO_ICRBE_D |
| 37 | `0x400600` to `0x400610` | 3 | I/O | IIO_ICSML to IIO_IDBSS |
| 38 | `0x410000` to `0x410028` | 6 | I/O | IIO_IBLS0 to IIO_IBIA0 |
| 39 | `0x420000` to `0x420028` | 6 | I/O | IIO_IBLS1 to IIO_IBIA1 |
| 40 | `0x430000` to `0x430008` | 2 | I/O | IIO_IPCR to IIO_IPPR |
| 41 | `0x600000` | 1 | local block | LB_REV_ID |
| 42 | `0x604000` to `0x604030` | 7 | local block | LB_CPU_PERMISSION to LB_MICROLAN_CTL |
| 43 | `0x604040` to `0x604060` | 5 | local block | LB_ERROR_BITS to LB_ERROR_DATA |
| 44 | `0x604100` to `0x604108` | 2 | local block | LB_DEBUG_SELECT to LB_DEBUG_PINS |
| 45 | `0x604200` to `0x604208` | 2 | local block | LB_RT_LOCAL_CTRL to LB_RT_FILTER_CTRL |
| 46 | `0x608000` to `0x608020` | 5 | local block | LB_SCRATCH_REG0 to LB_SCRATCH_REG4 |
| 47 | `0x60c000` to `0x60c010` | 3 | local block | LB_VECTOR_PARMS to LB_VECTOR_DATA |
| 48 | `0x60c020` to `0x60c030` | 3 | local block | LB_VECTOR_STATUS to LB_VECTOR_READ_DATA |
| 49 | `0x680000` to `0x680038` | 8 | network | NI_PORT_STATUS to NI_CHANNEL_AGE |
| 50 | `0x680100` to `0x680118` | 4 | network | NI_PORT_ERRORS to NI_PORT_SIDEBAND |
| 51 | `0x681000` to `0x6813f8` | 128 | network | NI_LOCAL_TABLE_0 to NI_LOCAL_TABLE_127 |
| 52 | `0x682000` | 1 | network | NI_GLOBAL_TABLE |
| 53 | `0x700000` to `0x7000a0` | 21 | crossbar | XB_PARMS to XB_DEBUG_ARB_CTL |
| 54 | `0x780000` to `0x780028` | 6 | memory/directory | MD_CURRENT_CELL to MD_FANDOP_CAC_STAT1 |
| 55 | `0x780040` to `0x780048` | 2 | memory/directory | MD_MISC0_ERROR to MD_MISC1_ERROR |
| 56 | `0x780060` | 1 | memory/directory | MD_OUTGOING_RP_QUEUE_SIZE |
| 57 | `0x790000` to `0x790018` | 4 | memory/directory | MD_PERF_SEL0 to MD_PERF_CNT1 |
| 58 | `0x7a0000` to `0x7a0048` | 10 | memory/directory | MD_REFRESH_CONTROL to MD_BIST_STATUS |
| 59 | `0x7a0060` | 1 | memory/directory | MD_IB_DEBUG |
| 60 | `0x7c0000` | 1 | memory/directory | MD_DIR_CONFIG |
| 61 | `0x7c0010` | 1 | memory/directory | MD_DIR_ERROR |
| 62 | `0x7c0020` | 1 | memory/directory | MD_PROTOCOL_ERROR |
| 63 | `0x7c0030` | 1 | memory/directory | MD_MIG_CANDIDATE |
| 64 | `0x7c0040` to `0x7c0060` | 5 | memory/directory | MD_MIG_DIFF_THRESH to MD_DB_DEBUG |
| 65 | `0x7e0000` | 1 | memory/directory | MD_MB_ECC_CONFIG |
| 66 | `0x7e0010` | 1 | memory/directory | MD_MEM_ERROR |
| 67 | `0x7e0020` to `0x7e0040` | 5 | memory/directory | MD_BIST_MB_ERR_DATA_0 to MD_MB_DEBUG |

Pairs 1 to 13 and 16 to 28 are the processor interface's identity, protection, interrupt, timer, graphics, error-status and
real-time-counter registers, including debug-select, spool-compare, error-injection and reply-level registers. Pairs 14,
15, 29 and 30 are the six performance registers of each processor interface: `+0x40200` to `+0x40210` (processor A) and
`+0x50200` to `+0x50210` (processor B). The unit boundaries agree with the bases used elsewhere in this document (I/O
`0x400000`, local block `0x600000`, network `0x680000`, crossbar `0x700000`, memory/directory `0x780000`). Established.

**The first pair outside the ordinary registers.** `+0x40200` is `PI_PERF_CNTL_A` in the public SN1 header, `+0x40208` and
`+0x40210` are `PI_PERF_CNTR0_A` and `PI_PERF_CNTR1_A`, and the B set repeats at `+0x50200`. The header gives names only: no
fields, reset value or access note. Role: a performance-counter control register and two counters per processor, inferred
from the names. Width: 8 bytes (established; the walk's `ld`). The dump stores whatever comes back and tests nothing. This
walk is the only reader found; the rest of the kernel was not searched for others (unknown). What a real Bedrock returns
after a normal boot is unknown: no capture, document or shipped code in this workspace states it. That a shipped default
(`dump_hub_info` 2) walks them on every crash implies the read completes on hardware (inferred).

**What happens when a walk read fails.** The load raises a data bus error. `dobuserre` (`0xc00000000005c2a0`) classifies the
faulting address by its extended-physical bits (uncached attribute 2, space bits 58:57 equal to 1) and calls
`handle_io_buserr` (`0xc00000000005cedc`, call at `0xc00000000005c6bc`) with the address reduced to its low 40 bits. That
routine looks for a matching entry in the processor-interface error spool (`get_matching_spool_addr`,
`0xc00000000005aa14`); for match results 0, 1 and 2 it calls `kl_ioerror_handler` (`0xc00000000005e4dc`, error kind 5), and
for -1 it only logs. Its third argument selects a mode: 0 gives mode 1, 1 gives mode 0, anything else mode 2. The record's
address field is the 40-bit address, with a flag marking it valid. `hub_ioerror_handler` (`0xc000000000077ccc`) sends a
record whose widget number is 1 (the Hub itself) to `hub_ioerror_local` (`0xc000000000077a80`). Modes 0, 2 and 3 return
without a message. Any other mode (the bus-error path produces only 0, 1 and 2, so mode 1) reads the
doubleword at `+0x0` of one node's window, tests the bit numbered by the other node's NASID (both come from halfwords of the
record), and prints one of two messages through `cmn_err` level 4, each
followed by `kl_panic`. Bit set: "Error accessing Hub Register %x on node (%d/%d) from (%d/%d), with access permission",
then "Hub Register Access error". Bit clear: the "No permission" message and "Hub Register Access Permission error". The
printed number is the faulting address, so a register at node 0 prints as `0x1800000` plus its offset: "Error accessing
Hub Register 1840200" is `+0x40200`. Established for the code path; that the register at `+0x0` is `PI_CPU_PROTECT` is inferred from the public header
(the offset is established from the code; the name is not). During a crash dump the kernel is already panicking,
so the second `kl_panic` is the "DOUBLE PANIC" and the machine restarts with the dump unfinished. Inferred: the walk's
reads before `+0x40200` completed, because the walk is in ascending order and stops at the first failure.

**The rest of `dump_hub_info` 2.** `dump_hub_dir_mem` reads the doubleword at `0x9200000001fc0000` plus the node bits
(`+0x7c0000`, a memory/directory register in the table) and uses its bit 0, then reads two consecutive doublewords per
128-byte line of every dumpable page from the directory back door at `0x90000001c0000000` (pool word gp+0x950) plus an
address-derived index. Established; the meaning of bit 0 is unknown here.

*Open:* the reset value and fields of `PI_PERF_CNTL_A`, `PI_PERF_CNTR0_A`, `PI_PERF_CNTR1_A` and the B set. Route: a
Bedrock hardware reference, or a read on a running Origin 300; neither is held.

## Reset expectations

Unknown for every register; `per_hub_init` and `hub_error_init` write fixed values (above) without reading
first, which is the only reset-related evidence, and states what the driver sets, not what the chip powers up with.
Settling test: in the IP35 PROM image (unpack it with `retools/tools/chips/promgen64.py`), list each routine that loads a Bedrock
register before any store to the same register in the same routine, using `hostfacts.py` on the unpacked segments; a first load
before a write is the only software-visible trace of a reset value. A register with no such load ends as unknown with no software
dependency. A hardware reference or a read on a node controller before the PROM runs would settle the rest.

## Open

See docs/open-questions.md: block boundaries, indexed families, the PROM window base, the `window-18` space, and the error-register questions listed there (what a refused widget read latches, the clear semantics of the status registers, the error spool entry layout, the protection-reply types, the interrupt level numbers).
