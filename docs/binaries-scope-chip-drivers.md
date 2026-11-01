# Chip driver objects in the kernel builds

Each entry classifies one shipped object of the IP27, IP30, IP32 or IP35 kernel build that the function scope keeps
in the table, or that keeps some of its routines there. It says what the object is, which chips its routines drive or
report on, and how the scope pass treated it. Routine names, sizes and undefined symbols come from the object's own
symbol table, read from the file under `root/`. The chip named for each object follows from those names and imports,
and from the chip pages that cite the same file.

Labels: every entry here is inferred. It classifies from symbol names, sizes and imports. No routine body was read in
full. "In scope" means no exclusion rule of the scope list in `scripts/inventory-config.json` removes the object's
routines. The rule texts are in the [function scope section](inventory/README.md#function-scope).

## IP27 build

- `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` (inferred): the Ethernet driver for the IOC3 Ethernet port. `if_efattach`
  (792 bytes) and `ef_ifattach` (236 bytes) attach the interface, and `if_efinit` and `ef_detach` handle setup and
  teardown. It claims its IOC3 part with `ioc3_subdev_enabled`, reserves Bridge read-response buffers through
  `pcibr_rrb_alloc`, and reads the station address with `nic_get_eaddr`. It imports the duplex helpers
  `ef_fullduplex_ipg` and `ef_halfduplex_ipg`. The chips are the IOC3 and the Bridge behind it. All 47 rows stay in
  the table.
- `IP27/usr/cpu/sysgen/IP27boot/ioc3_pckm.o` (inferred): the keyboard and mouse streams driver on the IOC3. `pckm_attach`
  (1332 bytes) is the attach routine, with `ioc3_pckm_mlreset` (76 bytes) and `pckminit` (8 bytes) for reset and
  start-up. It connects the chip interrupt with `ioc3_intr_connect`, writes the interrupt register through
  `ioc3_write_ireg`, and checks for the console with `ioc3_is_console`. Its `putnext`, `qreply` and `canput` imports
  place it in a STREAMS queue. The chip is the IOC3, and the keyboard and mouse ports are the ones its page describes.
  All 34 rows stay in.
- `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` (inferred): the IOC3 external interrupt driver. Its chip page names the
  register it drives, the external interrupt output at offset 0x2c, and `eiattach` writes it. `eiattach` (420 bytes)
  and `eiioctl` (1236 bytes) are the attach and control entries. `ioc3_ei_intr` (308 bytes) is the interrupt handler,
  `eimap` and `eiunmap` are the map pair, and `irix5_to_eiargs_xlate` and `eiargs_to_irix5_xlate` convert argument
  records between ABIs. The chip is the IOC3. The scope pass keeps all 19 rows.
- `IP27/usr/cpu/sysgen/IP27boot/kernel.o` (inferred): the machine-dependent kernel object of the IP27 build, one of the
  objects linked into `unix`. It holds 1361 function rows, 1216 of them global, in 1248568 bytes. The scope pass keeps
  279 rows: the router routines (`router_init` at 1196 bytes, `router_set_fences`, `router_nic_probe`, and the port
  and error helpers), `hub_vector_read` (224 bytes), `hub_ioerror_handler` (1028 bytes), and the Crosstalk and Bridge
  glue its imports show, such as `pcibr_hints_subdevs`, `xtalk_provider_register` and `xswitch_info_get`. The other
  1082 rows fall under the linked-kernel rule (rule 6), which removes routines whose names carry no chip or
  chip-error word and that hold no register access site.
- `IP27/usr/cpu/sysgen/IP27boot/nic.o` (inferred): the board identity reader. `nic_read_mfg` (788 bytes) and
  `nic_read_one_page` (400 bytes) read the manufacturing record from the board's one-wire memory, and `nic_next`
  (400 bytes) walks its records. `nic_access_mcr32` (136 bytes) drives the IOC3 one-wire control register at offset
  0x30, as the IOC3 page states. The `nic_*_vertex_info` routines publish a record for each vertex type: Hub,
  Bridge, IOC3 and an HQ4 part. Its chips are the IOC3 one-wire port and the Hub and Bridge vertices. Under the
  controller and EEPROM clause of the scope rule, all 32 rows stay in.
- `IP27/usr/cpu/sysgen/IP27boot/partition.o` (inferred): the partition support object for a system split into
  partitions. `part_init` (1372 bytes) and `part_init_node` (652 bytes) start the subsystem and its per-node state.
  `part_activate` (964 bytes) and `part_terminate` (796 bytes) bring a partition up and take it down, and
  `part_permit_page` (200 bytes) sets page permissions across partitions. It uses the Hub block-transfer engine
  through `bte_poison_range`. No exclusion rule names the object, so all 70 rows stay in, and the census holds no
  register access site in it.
- `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` (inferred): the PCI provider for the Bridge, the Crosstalk device driver that
  owns the Bridge's PCI side. `pcibr_error_dump` (4268 bytes) and `pcibr_pioerror` (3404 bytes) decode Bridge errors.
  `pcibr_rrb_alloc` (1028 bytes) and `pcibr_alloc_all_rrbs` (980 bytes) assign read-response buffers to slots, and
  `pcibr_dmamap_alloc` (1276 bytes) with `ate_write` (784 bytes) program the address translation entries. The
  interrupt ATE accessors `pcireg_int_ate_set` and `pcireg_int_ate_get` are 620 bytes each. The chip is the Bridge,
  and all 259 rows stay in the table.
- `IP27/usr/cpu/sysgen/IP27boot/pciio.o` (inferred): the PCI I/O layer above the Bridge provider. It is not a chip. Its
  device-facing entries are `pciio_driver_register`, `pciio_config_get` (184 bytes), `pciio_dma_addr` (284 bytes) and
  `pciio_intr_alloc` (104 bytes). It forwards to the Bridge through 42 `pcibr_*` imports, and it keeps device
  connection points through the `cdl_*` calls. The Bridge is the chip it drives, through those routines. All 108 rows
  stay in, because the object attaches and enumerates devices behind the Bridge.
- `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` (inferred): the driver for a PCI-to-PCI bridge below a Bridge slot.
  `pciio_ppb_attach` (228 bytes) attaches it, `pciio_ppb_intr_map` (224 bytes) maps its interrupts, and `pciio_ppb_init`
  and `pciio_ppb_detach` (116 bytes each) bring it up and down. It attaches devices through `pciio_device_attach` and
  reserves PIO space with `pciio_piospace_alloc`. The object names no chip of its own, so the bridge it drives is
  identified only by its position under the Bridge. The scope pass keeps all 18 rows.
- `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` (inferred): the RAD board driver. Its `kdsp_*` routines select clock
  generators, device interfaces and subsystems, as `kdsp_select_clockgen` and `kdsp_select_interface` show. The
  largest routine is `rad_start_subsys` (2212 bytes), with `rad_ioctl` (1688 bytes) as the control entry and
  `rad_attach` (180 bytes) as the attach routine. Its board access runs through PCI configuration and the Bridge,
  so the imports `pciio_config_get` and `pcibr_rrb_alloc` appear. The MACE page reads the IP32 copy of this object for
  its own chip. All 84 rows stay in the table.
