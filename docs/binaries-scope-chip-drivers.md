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

- `IP27/usr/cpu/sysgen/IP27boot/elsc.o` (inferred): the driver for the system controller (ELSC) on the IP27 build.
  `elsc_init` (68 bytes) starts it, `elsc_command` (400 bytes) and `elsc_process` (468 bytes) carry requests and
  replies, and `elsc_nvram_read` (236 bytes) and `elsc_nvram_write` (252 bytes) reach its NVRAM. The power and reset
  entries are `elsc_power_down`, `elsc_power_cycle` and `elsc_system_reset`, and the display entries are
  `elsc_display_char` (116 bytes) and `elsc_display_mesg` (184 bytes). The object talks to the controller over the I2C
  master routines `i2c_master_xmit`, `i2c_master_recv` and `i2c_master_xmit_recv`, and it reads board records through
  `nic_info_get`, `nic_next` and `nic_setup`. No chip page in this repository covers the controller, so no chip is
  recorded for it. The scope list puts all 64 rows under rule 3, the process and memory core rule, which does not
  describe a controller driver. The function-scope section keeps the controller objects on the same buses, so this row
  is flagged for the scope list.
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
- `IP27/usr/cpu/sysgen/IP27boot/pciba.o` (inferred): a driver that gives user programs PCI access through the
  user-level interface (ULI) calls, with 25 routines. `pciba_attach` (2116 bytes) and `pciba_sub_attach2` (560 bytes)
  bring an adapter up, and `pciba_detach` (1148 bytes) takes it down. `pciba_ioctl` (3548 bytes) is the largest
  routine and the control entry, and `pciba_map` (824 bytes) and `pciba_unmap` (420 bytes) map device space.
  `pciba_intr` (112 bytes) is the interrupt handler. The object imports `new_uli`, `uli_callup` and `free_uli`, and
  the argument conversions `uliargs_to_uliargs32` and `uliargs32_to_uliargs`. Its PCI access goes through the PCI I/O
  layer (`pciio_config_get`, `pciio_piomap_free`, `pciio_intr_connect` and `pciio_dmamap_alloc`), so the Bridge is the
  chip beneath it. Its 25 rows fall to rule 4 and stay out of the function table.
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
- `IP27/usr/cpu/sysgen/IP27boot/universe.o` (inferred): the driver for the Universe VME bridge part, with 67 routines.
  Its largest are `universe_pci_addr` (1340 bytes), `universe_intr_setup` (1308 bytes), `universe_pio_setup` (924
  bytes) and `universe_attach` (780 bytes). `universe_intr_handler` (512 bytes) and `universe_vmebus_intr_handler`
  (312 bytes) take its interrupts, `universe_dma_engine_setup` (396 bytes) sets up its DMA engine, and
  `universe_pio_bcopyin` and `universe_pio_bcopyout` (328 bytes each) move PIO data. Its imports reach both sides:
  `pciio_driver_register` and `pciio_pio_addr` on the PCI side, and `vmeio_provider_register` and
  `vmeio_error_handler` on the VME side. Rule 4 excludes its 67 routines, and the rule names VME outright.
- `IP27/usr/cpu/sysgen/IP27boot/usrpci.o` (inferred): a user-level PCI access driver with 16 routines. `usrpci_open`
  (208 bytes) and `usrpci_close` (32 bytes) open and close the device, and `usrpci_ioctl` (388 bytes) is the control
  entry. `usrpci_map` (1428 bytes) and `usrpci_unmap` (348 bytes) map PCI space into a process, `usrpci_hwgraph_add`
  (636 bytes) adds the device to the hardware graph, and `pciuli_intr` (48 bytes) is its interrupt entry. The PCI I/O
  layer carries the accesses: the object imports `pciio_piomap_alloc`, `pciio_piomap_addr`, `pciio_intr_connect` and
  `pciio_error_devenable` from it. Its only chip path runs through that layer to the Bridge. The 16 routines are
  excluded under rule 4.
- `IP27/usr/cpu/sysgen/IP27boot/vmeio.o` (inferred): the VME I/O layer, with 55 routines. `vmeio_init` (88 bytes)
  starts it, `vmeio_probe` (72 bytes) and `vmeio_edtscan` (424 bytes) look for VME devices, and `vmeio_piomap_addr`
  (152 bytes) builds a VME address for a PIO map. `vmeio_driver_register` (248 bytes) and `vmeio_device_register` (56
  bytes) register drivers and devices. The provider beneath it is the Universe: its imports `universe_piomap_addr`,
  `universe_intr_connect`, `universe_dmamap_alloc` and `universe_provider_startup` are the Universe entries it uses.
  `iospace_to_vmeioam` maps an I/O space address to a VME address modifier. Its 55 rows fall under the VME clause of
  rule 4.
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
- `IP27/usr/cpu/sysgen/IP27boot/xioba.o` (inferred): a character-device driver for a Crosstalk bus adapter, with 13
  routines. `xioba_attach` (188 bytes) and `xioba_detach` (256 bytes) bind it to a widget, and `xioba_reg` (92 bytes)
  and `xioba_unreg` (120 bytes) add and remove its registration. `xioba_map` (188 bytes) and `xioba_unmap` (8 bytes)
  handle the mapping, and `xioba_open`, `xioba_close`, `xioba_read`, `xioba_write` and `xioba_ioctl` (12 bytes) are
  the device entries. Its imports are the widget calls `xtalk_pio_addr`, `xwidget_driver_register` and
  `xwidget_driver_unregister`, plus `v_mapphys` for the mapping and `hwgraph_char_device_add` for the device node. The
  object names no chip of its own, and the widget it attaches to is the chip it reaches. Rule 4 removes all 13 rows,
  and nothing in the object reaches a chip except through the widget layer.
- `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` (inferred): the Crosstalk widget layer that every widget on the Crosstalk bus
  uses. `xwidget_register` (292 bytes) and `xwidget_driver_register` (116 bytes) record widgets and their drivers,
  `xtalk_pio_addr` (248 bytes) builds a PIO address, and `xtalk_error_handler` (172 bytes) routes bus errors. It calls
  the Hub provider through 30 imports beginning `hub_` (`hub_piomap_alloc`, `hub_dmamap_alloc`, `hub_intr_connect`
  and so on), and it keeps device connection points through the `cdl_*` calls. The widgets it serves are the Bridge
  and the Xbow, and the object itself is not a chip. It keeps 71 rows.

## IP30 build

- `IP30/usr/cpu/sysgen/IP30boot/giobr.o` (inferred): the Bridge provider for the GIO side of the Bridge on the IP30
  build, with 55 routines. `giobr_attach` (740 bytes) is the attach routine, `do_giobr_hw_init` (392 bytes) and
  `giobr_setup_SSRAM` (296 bytes) set the hardware up, and `giobr_error_dump` (444 bytes) and `giobr_pioerror` (248
  bytes) decode its errors. The read-response buffers and translation entries are handled by `giobr_rrb_alloc` (184
  bytes) and `giobr_ate_free` (40 bytes). `giobr_setgioint` (100 bytes) and `giobr_setwidint` (148 bytes) set its
  interrupt routing. The Bridge page gives the MODE bit the values GIO and PCI, so this object serves the GIO value of
  that field (inferred from the page's field table). Its entries register with the GIO layer through
  `gioio_provider_register`, and it imports `nic_bridge_vertex_info` and the Crosstalk provider calls. The scope list
  puts all 55 rows under rule 4, but the first criterion of the function-scope section keeps Bridge driver objects, so
  the rule 4 exclusion conflicts with it. This row is flagged for the scope list.
- `IP30/usr/cpu/sysgen/IP30boot/gioio.o` (inferred): the GIO I/O layer on the IP30 build, with 53 routines. Its PIO,
  DMA and interrupt entries, such as `gioio_piomap_alloc`, `gioio_dmamap_alloc` and `gioio_intr_connect`, are 28-byte
  routines (`gioio_piomap_alloc` is 28 bytes in the symbol table). The object imports the matching `giobr_` routine
  for each of them, such as `giobr_piomap_alloc`, `giobr_dmamap_alloc` and `giobr_intr_connect`.
  `gioio_device_register` (220 bytes) and `gioio_error_handler` (216 bytes) are the largest of the rest, with
  `gioio_cardinfo_get` (108 bytes) and `gioio_driver_register` (116 bytes) beside them. The device layer is the
  `cdl_*` set (`cdl_add_connpt`, `cdl_add_driver` and `cdl_iterate`), and the hardware graph calls are
  `hwgraph_info_add_LBL` and `hwgraph_traverse`. The chip beneath it is the Bridge, reached through `giobr`. Its 53
  rows are excluded by rule 4 as well, although the Bridge behind it is a system chip.
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
- `IP30/usr/cpu/sysgen/IP30boot/pciba.o` (inferred): the IP30 copy of the PCI bus-adapter driver that gives user
  programs PCI access. Its 25 routine names and sizes and its imports are those of the IP27 copy. `pciba_ioctl` (3548
  bytes) is the control entry, `pciba_attach` (2116 bytes) and `pciba_detach` (1148 bytes) attach and release
  adapters, and `pciba_map` (824 bytes) maps device space. The user-level interface calls `new_uli`, `uli_callup` and
  `free_uli` are imported, and the PCI layer under it is `pciio`. Its 25 rows are out under rule 4, as in the IP27
  copy.
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
- `IP30/usr/cpu/sysgen/IP30boot/usrpci.o` (inferred): the IP30 copy of the user-level PCI access driver. Its 16
  routine names and sizes and its imports match the IP27 copy. `usrpci_map` (1428 bytes) is its largest routine,
  `usrpci_ioctl` (388 bytes) the control entry, and `usrpci_open` (208 bytes) opens the device. Its PCI accesses go
  through the PCI I/O layer. Rule 4 keeps its 16 rows out of the table.
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

## IP32 build

- `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_zbuf.o)` (inferred): the Z-buffer pair of the CRIME graphics memory
  layer, `crmAddZ` (772 bytes) and `crmSubtractZ` (376 bytes). Its imports `crmAllocTiles`, `crmFreeTiles` and
  `crmNextIncarnation` are tile routines of the same layer, and the two `kern_*` imports are kernel services. The
  chip is the CRIME, and both rows stay in.
- `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tiles.o)` (inferred): the tile allocator for the CRIME graphics
  memory. `crmDefineTex` (1112 bytes), `crmResizeFb` (892 bytes), `crmAllocTex` (520 bytes), `crmLoadTlbABC` (432
  bytes) and `crmAllocZbuffer` (264 bytes) allocate texture, frame, overlay, Z and CID tiles. The imports
  `crimeBoards`, `gfxdd_mmap_mem` and five `dms` routines tie it to the CRIME boards and the tile pool. The chip is the
  CRIME, and 33 rows are in the table.
- `IP32/usr/cpu/sysgen/IP32boot/kernel.o` (inferred): the machine-dependent kernel object of the IP32 build, 811 rows
  in 504132 bytes. The scope pass keeps 61 rows, and the linked-kernel rule (rule 9) removes the other 750. The kept
  rows carry chip words: the CRIME interrupt entries `crime_intr` (the `crime_intr_enable` and `crime_intr_disable`
  pair, 64 and 68 bytes), `crimegang` (108 bytes) and `crimevec_thread_setup` (88 bytes), `crimestray`, the MACE
  vertex lookup `mace_hwgraph_lookup` (88 bytes), and `early_gbe_stop` (564 bytes), which stops the GBE chip. It also
  keeps `mlreset` (672 bytes), `early_ecc_init` and `ecc_enable` and `ecc_disable`. Its imports include the
  `pciio_pio_read*` and `pciio_pio_write*` accessors, so the PCI side reaches the chips through the PCI layer.
- `IP32/usr/cpu/sysgen/IP32boot/pciio.o` (inferred): the PCI I/O layer on the IP32 build. It calls 42 `pcimh_*`
  routines where the IP27 copy calls `pcibr_*`, so the bus under it is the one the MACE page covers through `pcimh.o`.
  Its entries are `pciio_pio_addr` (300 bytes), `pciio_error_handler` (292 bytes) and `pciio_dma_addr` (284 bytes).
  The MACE is the chip it drives, and its 108 rows stay in.
- `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` (inferred): the RAD board driver for the IP32 kernel. `rad_start_subsys`
  (2272 bytes), `rad_start_dma` (1404 bytes) and `rad_update_dev` (1304 bytes) are its largest routines. The `kdsp_*`
  imports select clock generators and interfaces, and nine `pciio_*` imports reach the board through the PCI layer.
  The MACE page lists this object among the IP32 files it read. All 84 rows stay in the table.

## IP35 build

- `IP35/usr/cpu/sysgen/IP35boot/hubspc.o` (inferred): the node PROM and inventory device for the IP35 build. Its
  routines map the PROM, `cpuprom_map` (188 bytes) and `hubspc_map` (156 bytes), and record inventory,
  `prominfo_add` (100 bytes) and `cpuprom_detailed_inventory_info_add` (132 bytes). It registers with the node
  device layer through `hubdev_register` and reads the PROM base and node number through `hubdev_prombase_get` and
  `hubdev_cnodeid_get`. The Bedrock page lists it among the IP35 objects it covers. Its 13 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` (inferred): the Ethernet driver on the IP35 build, with the same routines as
  the IP27 copy. Its extra import `iobrick_get_sys_snum` reads the system serial number from the I/O brick. It claims
  the IOC3 part through `ioc3_subdev_enabled`, and it reaches the Bridge through `pcibr_rrb_alloc`. The chips are the
  IOC3 and the Bridge, and 47 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/io6.o` (inferred): the init routine of the IO6 board, `io6_init` (64 bytes). Its eight
  imports include three Bridge hint routines (`pcibr_hints_dualslot`, `pcibr_hints_fix_rrbs` and
  `pcibr_hints_subdevs`), the NIC vertex calls `nic_vertex_info_match` and `nic_vmc_add`, and `xtalk_piotrans_addr`.
  The Bridge is the chip it configures, and both rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/ioc3.o` (inferred): the IOC3 core driver for the IP35 build. `ioc3_attach` (1340
  bytes) attaches the chip, `ioc3_intr_connect` (632 bytes) connects its interrupt, `ioc3_handle_intr` (468 bytes) is
  the handler, `ioc3_write_ireg` (408 bytes) writes an interrupt register, and `ioc3_mlreset` (116 bytes) runs at
  reset. It also imports `hub_check_pci_equiv`, the node-side PCI check. The chip is the IOC3, and its 27 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` (inferred): the IOC3 keyboard and mouse driver for the IP35 build.
  `pckm_attach` (1444 bytes) is the attach routine, with `ioc_pckm_add_hwgraph_alias` (276 bytes) and
  `ioc3_pckm_rmalias` (196 bytes) for the hardware-graph names. It also imports `ioc4_pckm_rmalias`, so the IOC4
  keyboard path shares this object's naming. The chips are the IOC3 and the IOC4, and 36 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/ioc3ei.o` (inferred): the IOC3 external interrupt driver, the same object as the IP27
  copy. `eiattach` (420 bytes) writes the external interrupt output the IOC3 page lists at offset 0x2c, `eiioctl`
  (1236 bytes) is the control entry, and `ioc3_ei_intr` (308 bytes) is the handler. The chip is the IOC3, and 19 rows
  stay in.
- `IP35/usr/cpu/sysgen/IP35boot/kernel.o` (inferred): the machine-dependent kernel object of the IP35 build, 1318 rows in
  1288752 bytes. The scope pass keeps 367 of them under the rule for linked kernels (rule 11), which removes 951. The
  kept rows are the router routines (`router_reg_read` and `router_reg_write` at 48 bytes each, `router_acquire_port_info`
  at 608 bytes, `router_decode_port_errors` at 176 bytes, `capture_router_stats` at 196 bytes), the node identity
  helpers `hub_widget_id`, `get_hub_chiprev` and `ni_reset_port`, and the I/O brick, serial-controller and console
  calls its imports show: `elsc_*` system controller routines, `iobrick_*` lookups, `ioc3_console_vhdl_get`,
  `ioc4_console_vhdl_get` and `pcibr_alloc_all_rrbs`. The node chip is the one the Bedrock page covers.
- `IP35/usr/cpu/sysgen/IP35boot/nic.o` (inferred): the board identity reader on the IP35 build, the same routines as
  the IP27 copy. `nic_read_mfg` (788 bytes) reads the manufacturing record, `nic_access_mcr32` drives the IOC3 one-wire
  control register at offset 0x30, and the `nic_*_vertex_info` routines publish a record for each vertex type. The
  chips are the IOC3 one-wire port and the node and Bridge vertices. All 32 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/numa.a(numa_hw.o)` (inferred): a two-routine member of the NUMA support library. One
  routine stays in: `migr_effthreshold_diff_set` is named as an exception in the rule for objects that are not chip
  drivers, and `migr_pageref_disable` (132 bytes) is removed by rule 12. The census records no register access in the
  member, and it imports one symbol from outside.
- `IP35/usr/cpu/sysgen/IP35boot/os.a(pda.o)` (inferred): the per-processor data member of the IP35 kernel library.
  Of its 42 rows, two stay in: `doacvec` (116 bytes) and `enter_panic_mode` (192 bytes), both kept by the exception
  list of rule 13. The other 40 are removed by that rule. Among chip-named symbols, the member imports only
  `kmem_zalloc_node`, and the census holds no register access site in it.
- `IP35/usr/cpu/sysgen/IP35boot/os.a(vmdump.o)` (inferred): the crash dump writer. Of 25 rows, four stay: `real_dumpsys`
  (1056 bytes), `dump_hub_registers` (944 bytes), `write_hub_dir_mem` (404 bytes) and `move_buffer` (1884 bytes). The
  first three read and write the node's directory memory and registers, which the Bedrock page covers. Rule 14 removes
  the other 21 rows.
- `IP35/usr/cpu/sysgen/IP35boot/partition.o` (inferred): the partition support object on the IP35 build. `part_init`
  (1648 bytes) and `part_init_node` (1076 bytes) start the subsystem, `part_export_page_perms` (600 bytes) sets page
  permissions, and `part_add_regions` and `part_rm_regions` (212 and 236 bytes) change the memory regions it owns. It
  calls `bte_poison_range`, which is the node's block-transfer engine. None of its 72 rows is removed.
- `IP35/usr/cpu/sysgen/IP35boot/pciba.o` (inferred): the IP35 copy of the PCI bus-adapter driver. It has the 25
  routine names, sizes and imports of the IP27 copy, so `pciba_ioctl` (3548 bytes) is again the largest routine and
  the control entry, and `pciba_attach` (2116 bytes) is the attach routine. Its PCI access runs through the PCI I/O
  layer over the Bridge. The 25 rows are out of the function table under rule 4.
- `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` (inferred): the Bridge PCI provider on the IP35 build, the largest of the
  Bridge copies at 300848 bytes. `pcibr_error_dump` (4268 bytes), `pcibr_pioerror` (3408 bytes) and
  `pcibr_slot_info_init` (2868 bytes) are its largest routines. Its imports `iobrick_pci_slot_pwr` and
  `iobrick_pci_slot_rst` power and reset a PCI slot through the I/O brick, and `hubii_check_widget_disabled` checks a
  widget on the node side. The chip is the Bridge, and its 265 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/pciio.o` (inferred): the PCI I/O layer over the Bridge on the IP35 build. Its entries are
  `pciio_pio_addr` (300 bytes), `pciio_error_handler` (296 bytes) and `pciio_dma_addr` (284 bytes), and it forwards to
  the `pcibr_*` provider routines. The Bridge is the chip under it, and 108 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/pciio_ppb.o` (inferred): the PCI-to-PCI bridge driver on the IP35 build. Its routines
  match the IP27 copy: `pciio_ppb_attach` (228 bytes) and `pciio_ppb_intr_map` (224 bytes). It names no chip of its
  own, and reaches the bridge through the `pciio_*` attach and PIO calls. The scope pass keeps its 18 rows.
- `IP35/usr/cpu/sysgen/IP35boot/pciiox.o` (inferred): the one-routine init of the extended PCI layer on the IP35 build,
  `pciiox_init` (32 bytes). Its imports are `pcibr_hints_fix_rrbs`, `nic_vmc_add` and `xtalk_piotrans_addr`, the same
  three as the IP30 copy. The Bridge is the chip it configures, and both rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` (inferred): the RAD board driver on the IP35 build. Its largest routines are
  `rad_start_subsys` (2048 bytes), `rad_ioctl` (1688 bytes) and `rad_update_dev` (1556 bytes). Its `kdsp_*` imports
  select clock generators and interfaces, and `iobrick_real_l1type_get_nasid` reads the board type through the I/O
  brick. It reaches the board through the PCI layer. All 84 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` (inferred): the serial port driver for the L1 controller, the
  module's system controller. `l1_attach` (560 bytes) attaches it, `early_brl1_port_init` (148 bytes) sets up the port
  before the kernel is running, and `l1_mlreset` (124 bytes) resets it. It uses the same `sio_*` console calls as the
  IOC3 serial ports, and no chip of its own appears in its imports. All 19 rows stay in the table.
- `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` (inferred): the IOC3 serial driver on the IP35 build. Its two
  large routines are `ioc3_serial_attach` (1300 bytes) and `ioc3_serial_kill` (280 bytes). `ring_dmatrans` (76 bytes)
  and `ioc3_sio_mlreset` (44 bytes) complete the set. It uses `ioc3_write_ireg`, `ioc3_intr_connect` and the
  `pciio_*` DMA and PIO translation calls. The chip is the IOC3, and 35 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/universe.o` (inferred): the Universe VME bridge driver on the IP35 build. Its 67
  routine names, sizes and imports are those of the IP27 copy, and `universe_pci_addr` (1340 bytes),
  `universe_intr_setup` (1308 bytes) and `universe_attach` (780 bytes) are its largest routines. The PCI and VME sides
  meet in it as on the IP27 build. Rule 4 excludes the 67 rows of the object.
- `IP35/usr/cpu/sysgen/IP35boot/vmeio.o` (inferred): the VME I/O layer on the IP35 build, with the same 55 routines,
  sizes and imports as the IP27 copy. Its provider is the Universe, and `vmeio_edtscan` (424 bytes) is the device scan
  routine. Its 55 rows fall under the VME clause of rule 4.
- `IP35/usr/cpu/sysgen/IP35boot/xbmon.o` (inferred): the crossbar monitor device on the IP35 build. `xbmon_ioctl`
  (1264 bytes) is its largest routine. It attaches to the Xbow with `xwidget_driver_register`, and it reads the
  switch through `xswitch_id_get` and `xtalk_piotrans_addr`. The chip is the Xbow, and 18 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/xbow.o` (inferred): the Xbow crossbar driver on the IP35 build. `xbow_attach` (776 bytes)
  attaches the crossbar, `xbow_enable_perf_counter` (460 bytes) enables a counter, `xbow_prio_bw_alloc` (372 bytes)
  allocates bandwidth priority, and `xbow_widget_num_get` (196 bytes) reports the widget count. It uses the
  `xswitch_info_*` vertex calls and `xtalk_intr_*` interrupt calls. The chip is the Xbow, and 30 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/xbridge.o` (inferred): the XBridge driver on the IP35 build. `xbridge_attach` (3484
  bytes) is the large routine, with `xbridge_init` (84 bytes). It reads and writes the node's interrupt translation
  table through `hubii_ixtt_get` and `hubii_ixtt_set`, and it reuses the `pcibr_*` routines for the bridge work. The chip
  is the XBridge, and both rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/xconn.o` (inferred): the crossbar connection device on the IP35 build. Its routines are
  the open, close, poll and ioctl entries, with `xconn_ioctl` (764 bytes) the largest. The [IP27 note on this object](ip27-xconn.md)
  finds that its copy reaches no hardware register. This copy has the same routine names, and its only chip-named
  import is `kmem_alloc`, so it is classified by its imports alone. The census holds no site in it. All 9 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/xswitch.o` (inferred): the crossbar switch vertex layer on the IP35 build. Its routines
  `xswitch_info_new` (152 bytes), `xswitch_info_vhdl_get` (96 bytes), `xswitch_info_get` (84 bytes) and
  `xswitch_provider_register` (40 bytes) keep the switch records, and `xswitch_reset_link` calls `xbow_reset_link` in
  the Xbow driver. The chip under it is the Xbow, and 13 rows stay in.
- `IP35/usr/cpu/sysgen/IP35boot/xtalk.o` (inferred): the Crosstalk widget layer on the IP35 build. `xwidget_register`
  (292 bytes), `xtalk_pio_addr` (248 bytes) and `xtalk_device_powerup` (64 bytes) are among its 70 routines, and its
  30 `hub_*` imports are the provider calls the IP27 copy also makes. The widgets it serves are the Bridge and the
  Xbow. All 71 rows stay in.
