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
- `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` (inferred): the serial driver for the IOC3's two serial lines,
  which the IOC3 page calls ports A and B. `ioc3_serial_attach` (1212 bytes) attaches a port, `ioc3_serial_kill`
  (276 bytes) takes one down, `ring_dmatrans` (76 bytes) is its DMA ring translation helper, and `ioc3_sio_mlreset`
  (44 bytes) runs at reset. It writes the chip through `ioc3_write_ireg` and connects the interrupt with
  `ioc3_intr_connect`, and `sio_console_register` makes a port the console. The chip is the IOC3. Its 35 rows are
  all in the table.
- `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` (inferred): the ioctl driver for the IP27 router and node board. It exposes
  router registers and the node's NVRAM to tools. `sn0drv_ioctl` (2252 bytes) dispatches the requests, and
  `do_router_op`, `do_reg_op` and `rou_fence_op` (268, 196 and 196 bytes) read and write router registers through
  `router_reg_read` and `router_reg_write`. `router_port_map_get` (292 bytes) and `check_router` (176 bytes) look up
  ports. Its `elsc_nvram_read` and `elsc_nvram_write` imports reach the system controller's NVRAM, and
  `hub_vector_read` reads the Hub vector. It drives the router, the Hub and the system controller, and keeps 11 rows.
- `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` (inferred): the crossbar monitor device. It gives tools a view of the Xbow
  registers and a trace buffer. `xbmon_ioctl` (1176 bytes) is the control entry, `xbtrace` (84 bytes) records trace
  entries, and `xbmon_map` (80 bytes) and `xbmon_read` (52 bytes) reach the register window. It attaches to the Xbow
  widget with `xwidget_driver_register` and reads through `xtalk_piotrans_addr`. The chip is the Xbow crossbar, and
  the 18 rows are in the table.
- `IP27/usr/cpu/sysgen/IP27boot/xbow.o` (inferred): the Xbow crossbar driver. `xbow_attach` (796 bytes) attaches each
  crossbar, and `xbow_get_bridge_pointers` (628 bytes) finds the Bridge pointers behind its ports.
  `xbow_prio_bw_alloc` (372 bytes) allocates bandwidth priority, and `xbow_reset_link` (260 bytes) resets one link.
  `xbow_xmit_retry_error` (260 bytes) and `xbow_update_llp_status` (276 bytes) handle link errors, and
  `xbow_enable_perf_counter` (460 bytes) turns a counter on. The chip is the Xbow, and 33 rows stay in.
- `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` (inferred): the Crosstalk widget layer that every widget on the Crosstalk bus
  uses. `xwidget_register` (292 bytes) and `xwidget_driver_register` (116 bytes) record widgets and their drivers,
  `xtalk_pio_addr` (248 bytes) builds a PIO address, and `xtalk_error_handler` (172 bytes) routes bus errors. It calls
  the Hub provider through 30 imports beginning `hub_` (`hub_piomap_alloc`, `hub_dmamap_alloc`, `hub_intr_connect`
  and so on), and it keeps device connection points through the `cdl_*` calls. The widgets it serves are the Bridge
  and the Xbow, and the object itself is not a chip. It keeps 71 rows.

## IP30 build

- `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` (inferred): the same Ethernet driver as the IP27 copy, built for the IP30
  kernel. `if_efattach` (788 bytes) and `ef_ifattach` (236 bytes) attach the interface, and it claims its IOC3 part
  through `ioc3_subdev_enabled`. Its imports add `heart_invalidate_war`, a HEART workaround, to the IOC3 and Bridge
  calls of the IP27 copy. The chips are the IOC3 and the Bridge behind it, with the HEART workaround. All 47 rows of
  the object are in the table.
- `IP30/usr/cpu/sysgen/IP30boot/io6.o` (inferred): the init for the IO6 I/O board, one routine, `io6_init` (64 bytes).
  It calls the Bridge hint routines `pcibr_hints_dualslot`, `pcibr_hints_fix_rrbs` and `pcibr_hints_subdevs`, adds a
  NIC vertex record with `nic_vmc_add`, and maps a PIO window through `xtalk_piotrans_addr`. The Bridge page covers
  the chip it configures. Both rows of the object are in the table.
- `IP30/usr/cpu/sysgen/IP30boot/ioc3.o` (inferred): the IOC3 core driver for the IP30 kernel. `ioc3_attach` (1196 bytes)
  attaches the chip, `ioc3_intr_connect` (632 bytes) and `ioc3_intr_disconnect` (356 bytes) manage its interrupt,
  and `ioc3_intr` (396 bytes) is the handler. `ioc3_subdev_enable`, `ioc3_subdev_disable` and `ioc3_subdev_enables`
  switch its sub-devices, and `ioc3_is_io7` tests the board variant. It hands the serial part
  on to `ioc3_serial_attach`, and it also imports `ioc3_sio_mlreset`. The chip is the IOC3, and 24 rows stay in.
- `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` (inferred): the IP30 copy of the IOC3 keyboard and mouse driver.
  `pckm_attach` (1332 bytes) is the attach routine, and `ioc3_pckm_mlreset` (76 bytes) and `pckminit` (8 bytes) are
  the reset and start-up entries. It connects the interrupt with `ioc3_intr_connect` and tests the console with
  `ioc3_is_console`. The chip is the IOC3, and its 34 rows are in.
- `IP30/usr/cpu/sysgen/IP30boot/kernel.o` (inferred): the machine-dependent kernel object of the IP30 build, with 726
  function rows and 577112 bytes. Only 15 rows stay in the table. These are HEART-facing routines: the cache flush
  helpers `heart_dcache_inval`, `heart_dcache_wb_inval` and `heart_need_flush`, the HEART interrupt entries
  `heart_intr_low`, `heart_intr_med`, `heart_intr_hi` and `heart_intr_err`, `heart_set_cpu_intr`, and
  `heart_invalidate_war`, plus `nmi_dump` (212 bytes), `early_nic_access_mcr32` (256 bytes),
  `intr_spray_heuristic` (192 bytes) and `heartclock_intr` (20 bytes). The other 711 rows fall under the
  linked-kernel rule (rule 8). The imports also reach the IOC3 (`ioc3_mlreset`), the Bridge (`pcibr_error_init`) and
  the Xbow (`xbow_mlreset`). The chip is the HEART, and the other chips are reached through it.
- `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` (inferred): the Bridge PCI provider for the IP30 kernel, the same Crosstalk
  driver as the IP27 copy at a different size, 286600 bytes. `pcibr_error_dump` (4188 bytes) and `pcibr_pioerror`
  (3400 bytes) decode errors, `pcibr_intr_alloc` (1580 bytes) allocates interrupts, `pcibr_dmamap_alloc` (1148 bytes)
  maps DMA, and `pcibr_rrb_alloc` (1028 bytes) assigns read-response buffers. Its interrupt set-up calls
  `heart_set_cpu_intr`, so on this build the Bridge's interrupts are routed through the HEART. The chip is the Bridge,
  and its 259 rows stay in.
- `IP30/usr/cpu/sysgen/IP30boot/pciio.o` (inferred): the PCI I/O layer over the Bridge for the IP30 kernel. Like the
  IP27 copy it is not a chip. It exports `pciio_pio_addr` (300 bytes), `pciio_dma_addr` (284 bytes) and
  `pciio_error_handler` (384 bytes), and it calls 42 `pcibr_*` routines. The Bridge is the chip under it. Its 108
  rows are in the table.
- `IP30/usr/cpu/sysgen/IP30boot/pciio_ppb.o` (inferred): the PCI-to-PCI bridge driver, IP30 copy. `pciio_ppb_attach`
  (228 bytes) and `pciio_ppb_intr_map` (224 bytes) match the IP27 routines in name and size. The object names no chip
  of its own, and it reaches the bridge only through `pciio_device_attach` and `pciio_piospace_alloc`. Scope keeps
  its 18 rows.
- `IP30/usr/cpu/sysgen/IP30boot/pciiox.o` (inferred): the one-routine init for the extended PCI layer, `pciiox_init`
  (32 bytes). It imports `pcibr_hints_fix_rrbs`, a Bridge hint routine, `nic_vmc_add` for a vertex record, and
  `xtalk_piotrans_addr`. The Bridge is the chip it configures. Both rows of the object stay in.
- `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` (inferred): the RAD board driver for the IP30 kernel. Its largest routines are
  `rad_start_subsys` (2048 bytes), `rad_ioctl` (1564 bytes) and `rad_update_dev` (1344 bytes). The `kdsp_*` imports
  select clock generators and interfaces, and `pciio_*` and `pcibr_rrb_alloc` show that it reaches the board through
  the PCI layer and the Bridge. Its 84 rows are in the table.
- `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` (inferred): the IOC3 serial driver, IP30 copy. Five routines:
  `ioc3_serial_attach` (1212 bytes), `ioc3_serial_kill` (64 bytes), `ring_dmatrans` (76 bytes), `ioc3_sio_mlreset`
  (44 bytes) and `get_cons_dev` (20 bytes). `get_cons_dev` reads the console option through `kopt` and `atoi`, which
  picks the port used as console. The chip is the IOC3, and 36 rows stay in.
- `IP30/usr/cpu/sysgen/IP30boot/xbmon.o` (inferred): the crossbar monitor device, IP30 copy. `xbmon_ioctl` (1164 bytes)
  is the control entry and `xbmon_open` (464 bytes) opens the device. It attaches to the Xbow with
  `xwidget_driver_register` and reads through `xtalk_piotrans_addr`. The chip is the Xbow, and 18 rows stay in.
- `IP30/usr/cpu/sysgen/IP30boot/xbow.o` (inferred): the Xbow crossbar driver, IP30 copy. `xbow_attach` (796 bytes)
  attaches the crossbar, `xbow_enable_perf_counter` (460 bytes) enables a counter, `xbow_enable_llp_monitor` (76
  bytes) enables link monitoring, and `xbow_widget_present` and `xbow_bytes_to_gbr` (100 bytes each) answer presence
  and bandwidth questions. It works through the `xswitch_*` vertex calls and the `xtalk_intr_*` interrupt calls. The
  chip is the Xbow, and 30 rows stay in.
- `IP30/usr/cpu/sysgen/IP30boot/xbridge.o` (inferred): the XBridge driver, which attaches the XBridge chip with the
  Bridge routines. `xbridge_attach` (2496 bytes) is its only large routine, with `xbridge_init` (84 bytes) beside it.
  Its 60 `pcibr_*` imports and 16 `pcireg_*` imports show that it reuses the Bridge code, and `nic_bridge_vertex_info`
  adds the vertex record. The chip is the XBridge. Both rows stay in.
- `IP30/usr/cpu/sysgen/IP30boot/xconn.o` (inferred): the crossbar connection device. Its routines are the open, close,
  poll and ioctl entries (`xconn_open` at 256 bytes, `xconn_poll` at 360 bytes, `xconn_ioctl` at 764 bytes) and
  helpers that lock a connection pair. The [IP27 note on this object](ip27-xconn.md) reads its copy in full and finds
  that it reaches no hardware register. This copy is classified by its imports, which hold only
  `kmem_alloc` from the chip-named set, and the census holds no site in it. All 9 rows stay in the table.
- `IP30/usr/cpu/sysgen/IP30boot/xswitch.o` (inferred): the crossbar switch vertex layer. `xswitch_info_new` (152 bytes),
  `xswitch_info_vhdl_get` (96 bytes), `xswitch_info_get` (84 bytes) and `xswitch_provider_register` (40 bytes) keep
  the switch's vertex and provider records. `xswitch_reset_link` calls `xbow_reset_link` in the Xbow driver. The chip
  under it is the Xbow, and its 13 rows are in the table.
- `IP30/usr/cpu/sysgen/IP30boot/xtalk.o` (inferred): the Crosstalk widget layer for the IP30 kernel. `xwidget_register`
  (292 bytes), `xtalk_pio_addr` (248 bytes) and `xtalk_error_handler` (172 bytes) match the IP27 copy. Its 28 `heart_*`
  imports, such as `heart_dmamap_alloc`, `heart_intr_connect` and `heart_piomap_alloc`, make HEART the provider it
  calls, where the IP27 copy calls the Hub. The widgets it serves are the Bridge and the Xbow. All 71 rows stay in.
