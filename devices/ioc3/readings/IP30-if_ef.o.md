# Readings: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`

One entry per routine, filed here from the reading batches by binary.

- `ef_txfree_len` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x0-0x98 (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x8 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x60 loads 8 bytes from ?.
  The `lw` at 0x70 loads 4 bytes from [a0+272]:8 +0x348.
  The `lw` at 0x74 loads 4 bytes from [a0+272]:8 +0x34c.
  The `jal` at 0x20 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x30 calls ef_reclaim with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x44 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x5c calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x50 targets 0x6c, is taken when s0(=ret(ef_reclaim)) == 0, and falls through when s0(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x64 targets 0x5c, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x90 has v0 = ?.

- `ef_setstate` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x98-0xc4 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x98 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `lw` at 0xa0 loads 4 bytes from [a0+272]:8 +0x358.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x358, including `sw` at 0xa8, `sw` at 0xc0.
  The `beq` branch at 0x9c targets 0xb4, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0xac has v0 = ?.
  The return at 0xbc has v0 = ?.

- `ef_ps_register` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0xc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0xc4-0x168 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0xc8 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x30, including `lw` at 0xe8, `lw` at 0x13c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x35c, including `sw` at 0xec, `sw` at 0x144.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0xf8, `sw` at 0x154.
  The `jal` at 0x11c calls ps_reinit with a0=a0 at entry (arg0), a1=sp-48, a2=a2 at entry (arg2), a3=0xfffffffff0000000, a4=0x5f5e100, a5=0x200, a6=[a0+968].
  The `jal` at 0x158 calls ps_init with a0=a0 at entry (arg0), a1=sp-48, a2=a2 at entry (arg2), a3=0xfffffffff0000000, a4=0x5f5e100, a5=0x200, a6=[a0+968].
  The `beq` branch at 0xdc targets 0x130, is taken when a6(=[a0+968]) == 0, and falls through when a6(=[a0+968]) != 0.
  The `beq` branch at 0x114 targets 0x158, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x150 targets 0xfc and is always taken.
  The `beq` branch at 0x160 targets 0x128 and is always taken.
  The return at 0x128 has v0 = one of ret(ps_reinit), ret(ps_init).

- `if_efopen` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x168 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x168-0x1e4 (124 bytes).
  It occupies 124 bytes.
  The `lw` at 0x16c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x18c loads 2 bytes from ret(hwgraph_fastinfo_get) +0x1a.
  The `jal` at 0x178 calls hwgraph_fastinfo_get with a0=[a0], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b0 calls device_controller_num_get with a0=[a0], a1=0x0, a2=?, a3=?.
  The `jal` at 0x1c0 calls ef_ifattach with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get), a2=?, a3=?.
  The `jal` at 0x1d4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x184 targets 0x19c, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x194 targets 0x1b0, is taken when at(=[ret(hwgraph_fastinfo_get)+26]:2) == v0(=-0x1), and falls through when at(=[ret(hwgraph_fastinfo_get)+26]:2) != v0(=-0x1).
  The `bltz` branch at 0x1b8 targets 0x1d0, is taken when v0(=ret(device_controller_num_get)) < 0 (signed), and falls through when v0(=ret(device_controller_num_get)) >= 0 (signed).
  The `beq` branch at 0x1c8 targets 0x19c and is always taken.
  The `beq` branch at 0x1dc targets 0x19c and is always taken.
  The return at 0x1a8 has v0 = one of 0x0, 0x5.

- `ef_ifattach` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1e4-0x2d0 (236 bytes).
  It occupies 236 bytes.
  The `sh` at 0x1e4 stores 2 bytes to a0 (arg0 at entry) +0x1a.
  The `ld` at 0x200 loads 8 bytes from a0 (arg0 at entry) +0x3a8.
  The `ld` at 0x218 loads 8 bytes from (sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4)) +0x8.
  The `lw` at 0x21c loads 4 bytes from [(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8 +0x6f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x394, including `lw` at 0x224, `lw` at 0x268.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0x27c, `sw` at 0x2bc.
  The `lh` at 0x280 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x29c loads 4 bytes from a0 (arg0 at entry) +0x3a0.
  The `lw` at 0x2a8 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x1fc calls pciio_intr_cpu_get with a0=[a0+936]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x204 calls cpuvertex_to_cpuid with a0=ret(pciio_intr_cpu_get), a1=?, a2=?, a3=?.
  The `jal` at 0x258 calls sprintf with a0=sp-32, a1=sym(.rodata), a2=sym(.rodata), a3=a1 at entry (arg1), a5=[a0+916], a6=[sym(ef_delaydiv)], a7=0x1.
  The `jal` at 0x264 calls if_hwgraph_alias_add with a0=[a0+916], a1=sp-32, a2=?, a3=?.
  The `jal` at 0x2a0 calls ether_attach with a0=a0 at entry (arg0), a1=sym(.rodata), a2=[a0+26]:2, a3=a0 at entry (arg0), a4=sym(.data), a5=a0+288, a6=0x13, a7=[a0+928].
  The `jal` at 0x2b8 calls ef_ps_register with a0=a0 at entry (arg0), a1=0x0, a2=([a0+32] | 0x4000), a3=?.
  The `bne` branch at 0x230 targets 0x244, is taken when v0(=[[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1776]) < 0x7e (signed), and falls through when v0(=[[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1776]) >= 0x7e (signed).
  The `beq` branch at 0x238 targets 0x244, is taken when a6(=[sym(ef_delaydiv)]) == 0, and falls through when a6(=[sym(ef_delaydiv)]) != 0.
  The `beq` branch at 0x244 targets 0x26c, is taken when a5(=[a0+916]) == a0(=-0x1), and falls through when a5(=[a0+916]) != a0(=-0x1).
  The `beq` branch at 0x274 targets 0x280, is taken when (a3(=[sym(if_efdevflag)]) & 0x1000) == 0, and falls through when (a3(=[sym(if_efdevflag)]) & 0x1000) != 0.
  The return at 0x2c8 has v0 = ret(ef_ps_register).

- `if_efinit` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x2d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x2d0-0x2fc (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x2e8 calls pciio_driver_register with a0=0x10a9, a1=0x3, a2=sym(.rodata), a3=0x0.
  The return at 0x2f4 has v0 = ret(pciio_driver_register).

- `if_efattach` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x2fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x2fc-0x610 (788 bytes).
  It occupies 788 bytes.
  The `sw` at 0x360 stores 4 bytes to ret(kmem_zalloc) +0x38c.
  The `sw` at 0x368 stores 4 bytes to ret(kmem_zalloc) +0x394.
  The `sd` at 0x398 stores 8 bytes to ret(kmem_zalloc) +0x330.
  The `sd` at 0x3c0 stores 8 bytes to ret(kmem_zalloc) +0x398.
  The `sw` at 0x3e0 stores 4 bytes to ret(kmem_zalloc) +0x390.
  The `lw` at 0x45c loads 4 bytes from ret(pciio_piotrans_addr) +0x8.
  The `sh` at 0x464 stores 2 bytes to ret(kmem_zalloc) +0x1a.
  The `sw` at 0x474 stores 4 bytes to ret(kmem_zalloc) +0x3a0.
  The `sw` at 0x4f0 stores 4 bytes to ret(kmem_zalloc) +0x3b4.
  The `sw` at 0x4f4 stores 4 bytes to ret(kmem_zalloc) +0x3cc.
  The `sw` at 0x4f8 stores 4 bytes to ret(kmem_zalloc) +0x3c8.
  The `sd` at 0x514 stores 8 bytes to ret(kmem_zalloc) +0x3a8.
  The `sd` at 0x53c stores 8 bytes to ret(kmem_zalloc) +0x340.
  The `lw` at 0x558 loads 4 bytes from ret(kmem_zalloc) +0x3a0.
  The `jal` at 0x308 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x324 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-12, a3=?.
  The `jal` at 0x33c calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-64.
  The `jal` at 0x34c calls kmem_zalloc with a0=0x430, a1=0x0, a2=?, a3=?.
  The `jal` at 0x370 calls hwgraph_fastinfo_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=a0 at entry (arg0).
  The `jal` at 0x38c calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0xf0, a4=0x64, a5=0x0.
  The `jal` at 0x3b4 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x20180, a5=0x0.
  The `jal` at 0x3d0 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-60, a3=?.
  The `jal` at 0x3e4 calls device_desc_dup with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3f8 calls device_desc_intr_name_set with a0=ret(device_desc_dup), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x404 calls device_desc_default_set with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x420 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x40000, a4=0x20000, a5=0x0.
  The `jal` at 0x430 calls ssram_discovery with a0=ret(kmem_zalloc), a1=ret(pciio_piotrans_addr), a2=?, a3=?.
  The `jal` at 0x44c calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x7, a3=0x0, a4=0x48, a5=0x0.
  The `jal` at 0x470 calls ef_phyunreset with a0=ret(kmem_zalloc), a1=?, a2=?, a3=-0x1.
  The `jal` at 0x478 calls ef_ioc3reset with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x484 calls ef_ioc3eaddr with a0=ret(kmem_zalloc), a1=sp-56, a2=?, a3=?.
  The `jal` at 0x498 calls bcopy with a0=sp-56, a1=ret(kmem_zalloc)+288, a2=0x6, a3=?.
  The `jal` at 0x4a8 calls bcopy with a0=sp-56, a1=ret(kmem_zalloc)+240, a2=0x6, a3=?.
  The `jal` at 0x4bc calls ef_allocef with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x4cc calls ef_detach with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x508 calls pciio_intr_alloc with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?, a5=-0x1.
  The `jal` at 0x520 calls pciio_intr_connect with a0=ret(pciio_intr_alloc), a1=sym(ef_intr), a2=ret(kmem_zalloc), a3=0x0.
  The `jal` at 0x534 calls pciio_dmamap_alloc with a0=a0 at entry (arg0), a1=?, a2=0x4, a3=0x61.
  The `jal` at 0x55c calls device_inventory_add with a0=?, a1=0x8, a2=0x0, a3=0x13, a4=-0x1, a5=[ret(kmem_zalloc)+928].
  The `jal` at 0x56c calls idbg_addfunc with a0=sym(.rodata), a1=sym(ef_dump), a2=?, a3=?.
  The `jal` at 0x584 calls init_bitlock with a0=ret(kmem_zalloc)+856, a1=0x1000, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x5a0 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=ret(hwgraph_char_device_add), a3=?.
  The `jal` at 0x5bc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x5cc calls ether_sprintf with a0=sp-56, a1=?, a2=?, a3=?, a4=[sym(showconfig)].
  The `jal` at 0x5e4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=ret(ether_sprintf).
  The `jal` at 0x600 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x310 targets 0x4e8, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `bne` branch at 0x344 targets 0x594, is taken when v0(=ret(hwgraph_char_device_add)) != 0, and falls through when v0(=ret(hwgraph_char_device_add)) == 0.
  The `beq` branch at 0x354 targets 0x4cc, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x394 targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `beq` branch at 0x3bc targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `bne` branch at 0x3d8 targets 0x5b0, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beq` branch at 0x428 targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `beq` branch at 0x454 targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `bne` branch at 0x48c targets 0x4cc, is taken when v0(=ret(ef_ioc3eaddr)) != 0, and falls through when v0(=ret(ef_ioc3eaddr)) == 0.
  The `bne` branch at 0x4b4 targets 0x5cc, is taken when a4(=[sym(showconfig)]) != 0, and falls through when a4(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x4c4 targets 0x4f0, is taken when v0(=ret(ef_allocef)) == 0, and falls through when v0(=ret(ef_allocef)) != 0.
  The `beq` branch at 0x4e8 targets 0x4d8 and is always taken.
  The `beq` branch at 0x540 targets 0x5f4, is taken when v0(=ret(pciio_dmamap_alloc)) == 0, and falls through when v0(=ret(pciio_dmamap_alloc)) != 0.
  The `beq` branch at 0x58c targets 0x4d8 and is always taken.
  The `beq` branch at 0x5a8 targets 0x34c and is always taken.
  The `beq` branch at 0x5c4 targets 0x4cc and is always taken.
  The `beq` branch at 0x5ec targets 0x4bc and is always taken.
  The `beq` branch at 0x608 targets 0x4cc and is always taken.
  The return at 0x4e0 has v0 = one of -0x1, 0x0, 0xc.

- `ef_detach` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x610 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x610-0x688 (120 bytes).
  It occupies 120 bytes.
  The `jal` at 0x620 calls idbg_delfunc with a0=sym(ef_dump), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x638 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x654 calls hwgraph_fastinfo_set with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x65c calls ef_deallocef with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x668 calls kmem_free with a0=ret(hwgraph_fastinfo_get), a1=0x430, a2=?, a3=?.
  The `beq` branch at 0x630 targets 0x674, is taken when s0(=a0) == at(=-0x1), and falls through when s0(=a0) != at(=-0x1).
  The `bne` branch at 0x640 targets 0x650, is taken when v0(=ret(hwgraph_fastinfo_get)) != 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) == 0.
  The `beq` branch at 0x648 targets 0x674 and is always taken.
  The return at 0x680 has v0 = 0x0.

- `mactoh` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x688 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x688-0x738 (176 bytes).
  It occupies 176 bytes.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x694, `sb` at 0x6c8, `sb` at 0x6dc.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x6ac, `lbu` at 0x6e8.
  The `beq` branch at 0x68c targets 0x728 and is always taken.
  The `beq` branch at 0x6a0 targets 0x720, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0x6b8 targets 0x6cc, is taken when a5(?) < 0x61 (signed), and falls through when a5(?) >= 0x61 (signed).
  The `beq` branch at 0x6c4 targets 0x6e8 and is always taken.
  The `bne` branch at 0x6d0 targets 0x6e0, is taken when a5(?) < 0x41 (signed), and falls through when a5(?) >= 0x41 (signed).
  The `beq` branch at 0x6d8 targets 0x6e8 and is always taken.
  The `bne` branch at 0x6fc targets 0x70c, is taken when t1(?) < 0x61 (signed), and falls through when t1(?) >= 0x61 (signed).
  The `beq` branch at 0x704 targets 0x698 and is always taken.
  The `bne` branch at 0x710 targets 0x694, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x718 targets 0x698 and is always taken.
  The `beq` branch at 0x730 targets 0x6ac and is always taken.
  The return at 0x720 has v0 = ?.

- `ef_ioc3eaddr` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x738 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x738-0x78c (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x73c loads 8 bytes from a0 (arg0 at entry) +0x398.
  The `lw` at 0x778 loads 4 bytes from a0 (arg0 at entry) +0x38c.
  The `jal` at 0x750 calls nic_get_eaddr with a0=[a0+920]:8+48, a1=[a0+920]:8+52, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x77c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+908], a3=?.
  The `bne` branch at 0x758 targets 0x770, is taken when v0(=ret(nic_get_eaddr)) != 0, and falls through when v0(=ret(nic_get_eaddr)) == 0.
  The `beq` branch at 0x784 targets 0x764 and is always taken.
  The return at 0x768 has v0 = one of 0x0, 0x5.

- `ssram_discovery` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x78c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x78c-0x800 (116 bytes).
  It occupies 116 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x78c, `ld` at 0x7dc.
  2 such `lw` accesses load 4 bytes from [a0+816]:8 +0x0, including `lw` at 0x790, `lw` at 0x7e4.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x0, including `sw` at 0x79c, `sw` at 0x7ec.
  The `sw` at 0x7a8 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x7b0 stores 4 bytes to a1 (arg1 at entry) +0x20000.
  The `lw` at 0x7b4 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x7cc loads 4 bytes from a1 (arg1 at entry) +0x20000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3d0, including `sw` at 0x7e0, `sw` at 0x7fc.
  The `bne` branch at 0x7c4 targets 0x7dc, is taken when at(=0x5555) != v0(?), and falls through when at(=0x5555) == v0(?).
  The `beq` branch at 0x7d4 targets 0x7f8, is taken when a4(=0xaaaa) == a5(?), and falls through when a4(=0xaaaa) != a5(?).
  The return at 0x7f0 has v0 = ?.
  The return at 0x7f8 has v0 = ?.

- `ef_allocef` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x800 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x800-0x8bc (188 bytes).
  It occupies 188 bytes.
  The `ld` at 0x800 loads 8 bytes from a0 (arg0 at entry) +0x338.
  The `sd` at 0x85c stores 8 bytes to a0 (arg0 at entry) +0x338.
  The `sd` at 0x864 stores 8 bytes to a0 (arg0 at entry) +0x350.
  The `sd` at 0x890 stores 8 bytes to a0 (arg0 at entry) +0x368.
  The `sd` at 0x8a0 stores 8 bytes to a0 (arg0 at entry) +0x380.
  The `jal` at 0x834 calls contig_memalloc with a0=0x4, a1=0x4, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0x858 calls kmem_zalloc with a0=0x1000, a1=0x0, a2=?, a3=?.
  The `jal` at 0x870 calls contig_memalloc with a0=0x1, a1=0x1, a2=0x100, a3=?.
  The `jal` at 0x894 calls kmem_zalloc with a0=0x1000, a1=0x0, a2=?, a3=?.
  The `jal` at 0x8ac calls ef_deallocef with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x814 targets 0x82c, is taken when at(=[a0+824]:8) == 0, and falls through when at(=[a0+824]:8) != 0.
  The `beq` branch at 0x83c targets 0x8ac, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0x860 targets 0x8ac, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x878 targets 0x8ac, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0x89c targets 0x8ac, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x8a4 targets 0x81c and is always taken.
  The `beq` branch at 0x8b4 targets 0x81c and is always taken.
  The return at 0x824 has v0 = one of 0x0, 0xc.

- `ef_deallocef` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x8bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x8bc-0x900 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0x8bc loads 8 bytes from a0 (arg0 at entry) +0x350.
  The `ld` at 0x8e0 loads 8 bytes from a0 (arg0 at entry) +0x380.
  The `jal` at 0x8d4 calls kmem_free with a0=[a0+848]:8, a1=0x1000, a2=a2 at entry (arg2), a3=[a0+848]:8.
  The `jal` at 0x8ec calls kmem_free with a0=[a0+896]:8, a1=0x1000, a2=?, a3=?.
  The `beq` branch at 0x8c8 targets 0x8dc, is taken when a3(=[a0+848]:8) == 0, and falls through when a3(=[a0+848]:8) != 0.
  The `beq` branch at 0x8e4 targets 0x8f8, is taken when a0(=[a0+896]:8) == 0, and falls through when a0(=[a0+896]:8) != 0.
  The return at 0x8f8 has v0 = one of ?, ret(kmem_free).

- `ef_reclaim` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x900 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x900-0x984 (132 bytes).
  It occupies 132 bytes.
  The `ld` at 0x900 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x904 loads 4 bytes from [a0+816]:8 +0x40.
  The `lw` at 0x90c loads 4 bytes from a0 (arg0 at entry) +0x34c.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x92c, `sd` at 0x944, `sd` at 0x958.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x350, including `ld` at 0x930, `ld` at 0x948, `ld` at 0x95c.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x938, `ld` at 0x954, `ld` at 0x970.
  The `sw` at 0x980 stores 4 bytes to a0 (arg0 at entry) +0x34c.
  The `beq` branch at 0x918 targets 0x97c, is taken when a4(=[a0+844]) == t0(?), and falls through when a4(=[a0+844]) != t0(?).
  The `beq` branch at 0x924 targets 0x948 and is always taken.
  The `beq` branch at 0x940 targets 0x97c, is taken when a4(?) == t0(?), and falls through when a4(?) != t0(?).
  The `bne` branch at 0x96c targets 0x92c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x974 targets 0x93c and is always taken.
  The return at 0x97c has v0 = one of 0x0, ?.

- `ef_xinit` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x984 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x984-0x9e8 (100 bytes).
  It occupies 100 bytes.
  The `ld` at 0x994 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `jal` at 0x9a4 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x9b8 calls ef_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x9cc calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The return at 0x9e0 has v0 = ret(ef_init).

- `ef_init` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x9e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x9e8-0xba4 (444 bytes).
  It occupies 444 bytes.
  The `ld` at 0x9f0 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `sw` at 0xa14 stores 4 bytes to [a0+272]:8 +0x388.
  The `ld` at 0xa20 loads 8 bytes from [a0+272]:8 +0x338.
  The `ld` at 0xa24 loads 8 bytes from [a0+272]:8 +0x368.
  The `sw` at 0xa28 stores 4 bytes to [a0+272]:8 +0x348.
  The `sw` at 0xa34 stores 4 bytes to [a0+272]:8 +0x34c.
  The `sw` at 0xa38 stores 4 bytes to [a0+272]:8 +0x374.
  The `sw` at 0xa44 stores 4 bytes to [a0+272]:8 +0x370.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa8c, `ld` at 0xb44, `ld` at 0xb5c.
  The `lh` at 0xabc loads 2 bytes from [a0+272]:8 +0x1a.
  The `lw` at 0xad0 loads 4 bytes from [a0+272]:8 +0x3a0.
  The `lw` at 0xad4 loads 4 bytes from [a0+272]:8 +0x358.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x358, including `sw` at 0xaf4, `sw` at 0xba0.
  The `lw` at 0xb00 loads 4 bytes from [a0+272]:8 +0x20.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x20, including `sw` at 0xb08, `sw` at 0xb90.
  The `lwu` at 0xb18 loads 4 bytes from [a0+272]:8 +0x374.
  2 such `ld` accesses load 8 bytes from [a0+272]:8 +0x330, including `ld` at 0xb1c, `ld` at 0xb70.
  The `sw` at 0xb2c stores 4 bytes to [[a0+272]:8+816]:8 +0x20.
  The `lw` at 0xb30 loads 4 bytes from [a0+272]:8 +0x370.
  The `ld` at 0xb34 loads 8 bytes from [a0+272]:8 +0x380.
  2 such `sd` accesses store 8 bytes to [a0+272]:8 +0x378, including `sd` at 0xb68, `sd` at 0xb6c.
  The `lw` at 0xb74 loads 4 bytes from [[a0+272]:8+816]:8 +0x0.
  The `sw` at 0xb7c stores 4 bytes to [[a0+272]:8+816]:8 +0x0.
  The `sh` at 0xb84 stores 2 bytes to [a0+272]:8 +0x1c.
  The `jal` at 0xa08 calls ef_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa1c calls bzero with a0=[[a0+272]:8+824]:8, a1=0x10000, a2=?, a3=?.
  The `jal` at 0xa30 calls bzero with a0=[[a0+272]:8+872]:8, a1=0x1000, a2=?, a3=?.
  The `jal` at 0xa48 calls ef_ioc3init with a0=[a0+272]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa70 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa88 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xaa0 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0xac8 calls ef_ps_register with a0=[a0+272]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0xb0c calls ef_fill with a0=[a0+272]:8, a1=[[a0+272]:8+32], a2=[[a0+272]:8+928], a3=-0x4.
  The `beq` branch at 0xa5c targets 0xabc, is taken when v0(=ret(ef_ioc3init)) == 0, and falls through when v0(=ret(ef_ioc3init)) != 0.
  The `beq` branch at 0xa7c targets 0xa98, is taken when s0(=ret(ef_reset)) == 0, and falls through when s0(=ret(ef_reset)) != 0.
  The `bne` branch at 0xa90 targets 0xa88, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xac0 targets 0xad0, is taken when a0(=[[a0+272]:8+26]:2) == a1(=-0x1), and falls through when a0(=[[a0+272]:8+26]:2) != a1(=-0x1).
  The `blez` branch at 0xaf0 targets 0xb94, is taken when a2(=[[a0+272]:8+928]) <= 0 (signed), and falls through when a2(=[[a0+272]:8+928]) > 0 (signed).
  The `beq` branch at 0xafc targets 0xb88, is taken when (a0(?) & 0x2) == 0, and falls through when (a0(?) & 0x2) != 0.
  The `beq` branch at 0xb54 targets 0xb6c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xb64 targets 0xb70 and is always taken.
  The `beq` branch at 0xb80 targets 0xa64 and is always taken.
  The `beq` branch at 0xb8c targets 0xb0c and is always taken.
  The `beq` branch at 0xb9c targets 0xaf8 and is always taken.
  The return at 0xab4 has v0 = ret(ef_ioc3init).

- `ef_ioc3init` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0xba4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0xba4-0xe68 (708 bytes).
  It occupies 708 bytes.
  The `ld` at 0xbc4 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0xc00 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x360, including `sw` at 0xc20, `sw` at 0xc2c, `sw` at 0xdf4.
  The `lw` at 0xc24 loads 4 bytes from a0 (arg0 at entry) +0x30.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0xc3c, `sw` at 0xe08.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3cc, including `lw` at 0xc40, `lw` at 0xd74.
  The `lw` at 0xc4c loads 4 bytes from a0 (arg0 at entry) +0x20.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0xc58, `sw` at 0xdbc.
  The `lw` at 0xc5c loads 4 bytes from sym(ef_fullduplex_ipg) +0x8.
  The `lw` at 0xc60 loads 4 bytes from sym(ef_fullduplex_ipg) +0x4.
  The `lw` at 0xc68 loads 4 bytes from sym(ef_fullduplex_ipg) +0x0.
  The `sw` at 0xc80 stores 4 bytes to [a0+816]:8 +0x28.
  The `sw` at 0xc88 stores 4 bytes to [a0+816]:8 +0x2c.
  The `sw` at 0xc90 stores 4 bytes to [a0+816]:8 +0x18.
  The `lw` at 0xc98 loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `sw` at 0xca8 stores 4 bytes to [a0+816]:8 +0xc.
  The `sw` at 0xcac stores 4 bytes to [a0+816]:8 +0x24.
  The `lbu` at 0xcb0 loads 1 byte from a0 (arg0 at entry) +0xf1.
  The `lbu` at 0xcb4 loads 1 byte from a0 (arg0 at entry) +0xf3.
  The `lbu` at 0xcb8 loads 1 byte from a0 (arg0 at entry) +0xf2.
  The `lbu` at 0xcc0 loads 1 byte from a0 (arg0 at entry) +0xf0.
  The `sw` at 0xcdc stores 4 bytes to [a0+816]:8 +0x4c.
  The `lbu` at 0xce0 loads 1 byte from a0 (arg0 at entry) +0xf5.
  The `lbu` at 0xcec loads 1 byte from a0 (arg0 at entry) +0xf4.
  The `sw` at 0xd00 stores 4 bytes to [a0+816]:8 +0x48.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x54, including `sw` at 0xd04, `sw` at 0xe34.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x50, including `sw` at 0xd08, `sw` at 0xe64.
  The `ld` at 0xd10 loads 8 bytes from a0 (arg0 at entry) +0x368.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x38c, including `lw` at 0xd20, `lw` at 0xd4c.
  The `sw` at 0xd2c stores 4 bytes to [a0+816]:8 +0x14.
  The `sw` at 0xd34 stores 4 bytes to [a0+816]:8 +0x10.
  The `ld` at 0xd3c loads 8 bytes from a0 (arg0 at entry) +0x338.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x3c, including `sw` at 0xd58, `sw` at 0xd70.
  The `sw` at 0xd60 stores 4 bytes to [a0+816]:8 +0x38.
  The `lw` at 0xd64 loads 4 bytes from [a0+816]:8 +0x3c.
  The `lw` at 0xd84 loads 4 bytes from a0 (arg0 at entry) +0x3d0.
  The `sw` at 0xd94 stores 4 bytes to [a0+816]:8 +0x0.
  The `sw` at 0xda0 stores 4 bytes to [a0+816]:8 +0x8.
  The `lw` at 0xdc4 loads 4 bytes from sym(ef_halfduplex_ipg) +0x4.
  The `lw` at 0xdc8 loads 4 bytes from sym(ef_halfduplex_ipg) +0x8.
  The `lw` at 0xdd0 loads 4 bytes from sym(ef_halfduplex_ipg) +0x0.
  The `lbu` at 0xe0c loads 1 byte from a0 (arg0 at entry) +0x3bd.
  The `lbu` at 0xe10 loads 1 byte from a0 (arg0 at entry) +0x3be.
  The `lbu` at 0xe18 loads 1 byte from a0 (arg0 at entry) +0x3bf.
  The `lbu` at 0xe20 loads 1 byte from a0 (arg0 at entry) +0x3bc.
  The `lbu` at 0xe38 loads 1 byte from a0 (arg0 at entry) +0x3c1.
  The `lbu` at 0xe3c loads 1 byte from a0 (arg0 at entry) +0x3c2.
  The `lbu` at 0xe44 loads 1 byte from a0 (arg0 at entry) +0x3c3.
  The `lbu` at 0xe4c loads 1 byte from a0 (arg0 at entry) +0x3c0.
  The `jal` at 0xbc0 calls ef_phyinit with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbe4 calls ef_phyerr with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xc7c calls microtime with a0=sp-64, a1=0xfffffffff0000000, a2=?, a3=?, a5=0x10000, a6=sym(ef_fullduplex_ipg).
  The `jal` at 0xd0c calls kvtophys with a0=[a0+872]:8, a1=?, a2=?, a3=?, a4=([a0+244]:1 | ([a0+245]:1 << 0x8)), a6=([a0+245]:1 << 0x8).
  The `jal` at 0xd24 calls pciio_dmatrans_addr with a0=[a0+908], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x50.
  The `jal` at 0xd38 calls kvtophys with a0=[a0+824]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xd50 calls pciio_dmatrans_addr with a0=[a0+908], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x50.
  The `jal` at 0xd9c calls flushbus with a0=?, a1=?, a2=?, a3=?, a4=([[a0+816]:8+60] | 0x1), a6=0x7fe003f.
  The `beq` branch at 0xbc8 targets 0xbe4, is taken when v0(=ret(ef_phyinit)) == 0, and falls through when v0(=ret(ef_phyinit)) != 0.
  The `beq` branch at 0xc14 targets 0xde4, is taken when (at(=a1) & 0x100) == 0, and falls through when (at(=a1) & 0x100) != 0.
  The `beq` branch at 0xc30 targets 0xdf8, is taken when v0(=[a0+968]) == 0, and falls through when v0(=[a0+968]) != 0.
  The `beq` branch at 0xc48 targets 0xdac, is taken when a0(=[a0+972]) == 0, and falls through when a0(=[a0+972]) != 0.
  The `beq` branch at 0xc54 targets 0xdc0, is taken when a0(=[a0+972]) == 0, and falls through when a0(=[a0+972]) != 0.
  The `beq` branch at 0xcfc targets 0xe0c, is taken when (a5(=a1) & 0x200) == 0, and falls through when (a5(=a1) & 0x200) != 0.
  The `beq` branch at 0xd78 targets 0xd84, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xda4 targets 0xbd0 and is always taken.
  The `bne` branch at 0xdb8 targets 0xc5c, is taken when a0(=[a0+972]) != 0, and falls through when a0(=[a0+972]) == 0.
  The `beq` branch at 0xddc targets 0xc78 and is always taken.
  The `beq` branch at 0xdf0 targets 0xc24 and is always taken.
  The `beq` branch at 0xe04 targets 0xc40 and is always taken.
  The `beq` branch at 0xe60 targets 0xd0c and is always taken.
  The return at 0xbdc has v0 = one of ret(ef_phyinit), 0x0.

- `ef_phyunreset` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0xe68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0xe68-0xed8 (112 bytes).
  It occupies 112 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x398, including `ld` at 0xe68, `ld` at 0xe74, `ld` at 0xe8c.
  2 such `sw` accesses store 4 bytes to [a0+920]:8 +0x54, including `sw` at 0xe6c, `sw` at 0xeb0.
  2 such `lw` accesses load 4 bytes from [a0+920]:8 +0x54, including `lw` at 0xe7c, `lw` at 0xeb8.
  The `sw` at 0xe88 stores 4 bytes to [a0+920]:8 +0x34.
  The `lw` at 0xe98 loads 4 bytes from [a0+920]:8 +0x34.
  The `jal` at 0xea0 calls us_delay with a0=0xa, a1=[[a0+920]:8+84], a2=[a0+920]:8, a3=a3 at entry (arg3).
  The `jal` at 0xec0 calls us_delay with a0=0x1f4, a1=?, a2=?, a3=[[a0+920]:8+84], a4=0x1, a5=[a0+920]:8.
  The return at 0xed0 has v0 = ret(us_delay).

- `ef_phyprobe` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0xed8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0xed8-0x100c (308 bytes).
  It occupies 308 bytes.
  The `lw` at 0xef8 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `lw` at 0xf14 loads 4 bytes from a0 (arg0 at entry) +0x3b0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3b4, including `sw` at 0xf88, `sw` at 0xff8.
  The `sw` at 0xfdc stores 4 bytes to a0 (arg0 at entry) +0x3b8.
  The `sw` at 0xfe4 stores 4 bytes to a0 (arg0 at entry) +0x3b0.
  The `lh` at 0xfec loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `jal` at 0xf84 calls ef_phyget with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0xf94 calls ef_phyget with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0xffc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=-0x1, a4=(ret(ef_phyget) << 0xc).
  The `beq` branch at 0xf0c targets 0xf4c, is taken when at(=[a0+948]) == v0(=-0x1), and falls through when at(=[a0+948]) != v0(=-0x1).
  The `beq` branch at 0xf70 targets 0xf7c and is always taken.
  The `beq` branch at 0xf78 targets 0xfe8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xfac targets 0xfd8, is taken when a3(?) == s3(=0x15f41), and falls through when a3(?) != s3(=0x15f41).
  The `beq` branch at 0xfb4 targets 0xfdc, is taken when a3(?) == s4(=0x15f42), and falls through when a3(?) != s4(=0x15f42).
  The `beq` branch at 0xfbc targets 0xfdc, is taken when a3(?) == s5(=0x15f43), and falls through when a3(?) != s5(=0x15f43).
  The `beq` branch at 0xfc4 targets 0xfdc, is taken when a3(?) == s6(=0x181441), and falls through when a3(?) != s6(=0x181441).
  The `beq` branch at 0xfcc targets 0xfdc, is taken when a3(?) == s7(=0x20005c0), and falls through when a3(?) != s7(=0x20005c0).
  The `bne` branch at 0xfd4 targets 0xf78, is taken when a3(?) != s8(=0x20005c1), and falls through when a3(?) == s8(=0x20005c1).
  The `beq` branch at 0xfe0 targets 0xf18 and is always taken.
  The `beq` branch at 0x1004 targets 0xf18 and is always taken.
  The return at 0xf44 has v0 = one of [a0+944], ?, -0x1.

- `ef_phymode` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x100c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x100c-0x12ec (736 bytes).
  It occupies 736 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3b0, including `lw` at 0x1078, `lw` at 0x1184.
  13 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x10f4, `sw` at 0x1130, `sw` at 0x1170.
  13 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x10fc, `sw` at 0x1134, `sw` at 0x1178.
  The `jal` at 0x1030 calls ef_phyget with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1040 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x1050 calls ef_phyget with a0=a0 at entry (arg0), a1=0x6, a2=?, a3=?.
  The `jal` at 0x10bc calls ef_phyget with a0=a0 at entry (arg0), a1=0x1f, a2=0x20005c1, a3=0x15f41, a4=0x15f42, a5=0x15f43, a6=0x181441.
  The `jal` at 0x1100 calls ef_phyget with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0x1110 calls ef_phyget with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x115c calls ef_phyget with a0=a0 at entry (arg0), a1=0x11, a2=0x20005c1, a3=0x15f41, a4=0x15f42.
  The `jal` at 0x119c calls ef_phyget with a0=a0 at entry (arg0), a1=0x11, a2=?, a3=?.
  The `jal` at 0x11ec calls ef_phyget with a0=a0 at entry (arg0), a1=0x19, a2=0x20005c1, a3=?.
  The `jal` at 0x122c calls ef_phyget with a0=a0 at entry (arg0), a1=0x10, a2=0x20005c1, a3=?.
  The `jal` at 0x1244 calls ef_phyget with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `jal` at 0x12cc calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0xefff, a3=?.
  The `jal` at 0x12dc calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0x1000, a3=?.
  The `beq` branch at 0x105c targets 0x1208, is taken when (s3(=ret(ef_phyget)) & 0x1000) == 0, and falls through when (s3(=ret(ef_phyget)) & 0x1000) != 0.
  The `beq` branch at 0x1068 targets 0x1184, is taken when (v1(=ret(ef_phyget)) & 0x20) == 0, and falls through when (v1(=ret(ef_phyget)) & 0x20) != 0.
  The `bne` branch at 0x1070 targets 0x1100, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x1084 targets 0x11e8, is taken when v0(=[a0+944]) == a1(=0x20005c0), and falls through when v0(=[a0+944]) != a1(=0x20005c0).
  The `beq` branch at 0x108c targets 0x1228, is taken when v0(=[a0+944]) == a2(=0x20005c1), and falls through when v0(=[a0+944]) != a2(=0x20005c1).
  The `beq` branch at 0x1098 targets 0x1158, is taken when v0(=[a0+944]) == a3(=0x15f41), and falls through when v0(=[a0+944]) != a3(=0x15f41).
  The `beq` branch at 0x10a0 targets 0x1158, is taken when v0(=[a0+944]) == a4(=0x15f42), and falls through when v0(=[a0+944]) != a4(=0x15f42).
  The `beq` branch at 0x10a8 targets 0x1158, is taken when v0(=[a0+944]) == a5(=0x15f43), and falls through when v0(=[a0+944]) != a5(=0x15f43).
  The `bne` branch at 0x10b4 targets 0x117c, is taken when v0(=[a0+944]) != a6(=0x181441), and falls through when v0(=[a0+944]) == a6(=0x181441).
  The `beq` branch at 0x10d4 targets 0x129c, is taken when a0(?) == a7(=0x4), and falls through when a0(?) != a7(=0x4).
  The `beq` branch at 0x10dc targets 0x12a8, is taken when a0(?) == a2(=0x8), and falls through when a0(?) != a2(=0x8).
  The `beq` branch at 0x10e4 targets 0x12b4, is taken when a0(?) == a4(=0x14), and falls through when a0(?) != a4(=0x14).
  The `bne` branch at 0x10ec targets 0x117c, is taken when a0(?) != a5(=0x18), and falls through when a0(?) == a5(=0x18).
  The `beq` branch at 0x10f8 targets 0x117c and is always taken.
  The `beq` branch at 0x111c targets 0x11c4, is taken when (s3(=ret(ef_phyget)) & 0x100) == 0, and falls through when (s3(=ret(ef_phyget)) & 0x100) != 0.
  The `beq` branch at 0x1124 targets 0x11c8, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x117c targets 0x113c and is always taken.
  The `bne` branch at 0x1190 targets 0x11b4, is taken when ra(=[a0+944]) != at(=0x15f42), and falls through when ra(=[a0+944]) == at(=0x15f42).
  The `beq` branch at 0x11ac targets 0x12c4, is taken when v0(?) == v1(=0x1000), and falls through when v0(?) != v1(=0x1000).
  The `beq` branch at 0x11bc targets 0x113c and is always taken.
  The `beq` branch at 0x11c8 targets 0x125c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x11d4 targets 0x1258, is taken when (v0(=ret(ef_phyget)) & 0x80) == 0, and falls through when (v0(=ret(ef_phyget)) & 0x80) != 0.
  The `beq` branch at 0x11e0 targets 0x1138 and is always taken.
  The `beq` branch at 0x1200 targets 0x117c and is always taken.
  The `beq` branch at 0x1220 targets 0x113c and is always taken.
  The `beq` branch at 0x1250 targets 0x117c and is always taken.
  The `beq` branch at 0x1260 targets 0x127c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1268 targets 0x1280, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1274 targets 0x1138 and is always taken.
  The `beq` branch at 0x1280 targets 0x1138, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x1288 targets 0x113c, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x1294 targets 0x1138 and is always taken.
  The `beq` branch at 0x12a0 targets 0x117c and is always taken.
  The `beq` branch at 0x12ac targets 0x117c and is always taken.
  The `beq` branch at 0x12bc targets 0x117c and is always taken.
  The `beq` branch at 0x12e4 targets 0x11b4 and is always taken.
  The return at 0x1150 has v0 = one of 0x0, 0x10.

- `ef_phyreset` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x12ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x12ec-0x1324 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0x12f4 calls ef_phyprobe with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1308 calls ef_phyerrat with a0=a0 at entry (arg0), a1=?, a2=?, a3=-0x1.
  The `beq` branch at 0x1300 targets 0x1314, is taken when v0(=ret(ef_phyprobe)) == at(=-0x1), and falls through when v0(=ret(ef_phyprobe)) != at(=-0x1).
  The return at 0x131c has v0 = one of -0x1, 0x0.

- `ef_phyinit` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1324 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1324-0x1474 (336 bytes).
  It occupies 336 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0x1324, `lh` at 0x13d0.
  The `lw` at 0x1394 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x13a4 loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x13b0, `lw` at 0x13e8.
  The `sw` at 0x141c stores 4 bytes to a0 (arg0 at entry) +0x3c8.
  The `sw` at 0x1428 stores 4 bytes to a0 (arg0 at entry) +0x3cc.
  The `jal` at 0x1338 calls ef_phyreset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1368 calls ef_phymode with a0=a0 at entry (arg0), a1=a0+968, a2=a0+972, a3=?.
  The `jal` at 0x137c calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0x1388 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x13d8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=one of 0xa, 0x64, a3=sym(.rodata).
  The `jal` at 0x1400 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a6=[a0+968].
  The `jal` at 0x1410 calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0x1000, a3=?.
  The `jal` at 0x1438 calls us_delay with a0=0x64, a1=?, a2=?, a3=?.
  The `jal` at 0x1458 calls ef_phymode with a0=a0 at entry (arg0), a1=a0+968, a2=a0+972, a3=?.
  The `beq` branch at 0x1340 targets 0x135c, is taken when v0(=ret(ef_phyreset)) == 0, and falls through when v0(=ret(ef_phyreset)) != 0.
  The `beq` branch at 0x1374 targets 0x1434, is taken when v0(=ret(ef_phymode)) == a0(=0x10), and falls through when v0(=ret(ef_phymode)) != a0(=0x10).
  The `beq` branch at 0x139c targets 0x13e8, is taken when a6(=[a0+968]) == a1(=-0x1), and falls through when a6(=[a0+968]) != a1(=-0x1).
  The `beq` branch at 0x13a8 targets 0x13e8, is taken when a0(=[a0+972]) == a1(=-0x1), and falls through when a0(=[a0+972]) != a1(=-0x1).
  The `beq` branch at 0x13b8 targets 0x13e0, is taken when (v0(=[a0+32]) & 0x4) == 0, and falls through when (v0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x13c0 targets 0x142c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x13e0 targets 0x134c and is always taken.
  The `beq` branch at 0x13f0 targets 0x140c, is taken when (a0(=[a0+32]) & 0x4) == 0, and falls through when (a0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1424 targets 0x13b0 and is always taken.
  The `beq` branch at 0x142c targets 0x13c8 and is always taken.
  The `bltz` branch at 0x1448 targets 0x137c, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `beq` branch at 0x1464 targets 0x1438, is taken when v0(=ret(ef_phymode)) == a3(=0x10), and falls through when v0(=ret(ef_phymode)) != a3(=0x10).
  The `beq` branch at 0x146c targets 0x137c and is always taken.
  The return at 0x1354 has v0 = one of 0x0, 0x5.

- `ef_phyupdate` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1474 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1474-0x14d8 (100 bytes).
  It occupies 100 bytes.
  The `lw` at 0x149c loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x14a8 loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  The `lw` at 0x14c0 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x148c calls ef_phymode with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=a3 at entry (arg3).
  The `jal` at 0x14c8 calls ef_init with a0=a0 at entry (arg0), a1=[a0+32], a2=a1 at entry (arg1), a3=?.
  The `bne` branch at 0x1494 targets 0x14b0, is taken when v0(=ret(ef_phymode)) != 0, and falls through when v0(=ret(ef_phymode)) == 0.
  The `bne` branch at 0x14a0 targets 0x14c0, is taken when at(=[a0+968]) != v0(?), and falls through when at(=[a0+968]) == v0(?).
  The `bne` branch at 0x14ac targets 0x14c0, is taken when v1(=[a0+972]) != a0(?), and falls through when v1(=[a0+972]) == a0(?).
  The `beq` branch at 0x14d0 targets 0x14b4 and is always taken.
  The return at 0x14b8 has v0 = one of ?, ret(ef_init).

- `ef_phyerr` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x14d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x14d8-0x16b4 (476 bytes).
  It occupies 476 bytes.
  The `lh` at 0x14e0 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x150c loads 4 bytes from a0 (arg0 at entry) +0x3dc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3dc, including `sw` at 0x1518, `sw` at 0x15c8.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x358, including `lw` at 0x1528, `lw` at 0x1560, `lw` at 0x1640.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3e0, including `lw` at 0x1538, `lw` at 0x15e8.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x1544, `lw` at 0x15a8, `lw` at 0x1634.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3e0, including `sw` at 0x1564, `sw` at 0x15fc.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x358, including `sw` at 0x1584, `sw` at 0x15d8, `sw` at 0x165c.
  The `lw` at 0x15dc loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0x1650, `sw` at 0x1694.
  The `jal` at 0x14f8 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1558 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x15bc calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x160c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x1628 calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x1658 calls ef_phyupdate with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=[a0+856], a5=0xfffffffffff7ffff.
  The `jal` at 0x1678 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x16a0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=[a0+968], a4=[a0+992].
  The `beq` branch at 0x1508 targets 0x15a0, is taken when (v0(=ret(ef_phyget)) & 0x10) == 0, and falls through when (v0(=ret(ef_phyget)) & 0x10) != 0.
  The `beq` branch at 0x1510 targets 0x1600, is taken when a0(=[a0+988]) == 0, and falls through when a0(=[a0+988]) != 0.
  The `beq` branch at 0x1520 targets 0x1538, is taken when (s2(=ret(ef_phyget)) & 0x2) == 0, and falls through when (s2(=ret(ef_phyget)) & 0x2) != 0.
  The `beq` branch at 0x1530 targets 0x15dc, is taken when (a0(=[a0+856]) & 0x4) == 0, and falls through when (a0(=[a0+856]) & 0x4) != 0.
  The `beq` branch at 0x153c targets 0x1560, is taken when a0(=[a0+992]) == 0, and falls through when a0(=[a0+992]) != 0.
  The `beq` branch at 0x154c targets 0x1560, is taken when (a1(=[a0+32]) & 0x4) == 0, and falls through when (a1(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1570 targets 0x15cc, is taken when (s2(=ret(ef_phyget)) & 0x4) == 0, and falls through when (s2(=ret(ef_phyget)) & 0x4) != 0.
  The `bne` branch at 0x1578 targets 0x161c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x15a0 targets 0x15c4, is taken when a0(=[a0+988]) == 0, and falls through when a0(=[a0+988]) != 0.
  The `beq` branch at 0x15b0 targets 0x15c4, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x15c4 targets 0x151c and is always taken.
  The `beq` branch at 0x15cc targets 0x166c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x15d4 targets 0x1588 and is always taken.
  The `bne` branch at 0x15e0 targets 0x1538, is taken when a3(=[a0+968]) != 0, and falls through when a3(=[a0+968]) == 0.
  The `beq` branch at 0x15ec targets 0x1698, is taken when a4(=[a0+992]) == 0, and falls through when a4(=[a0+992]) != 0.
  The `beq` branch at 0x15f8 targets 0x156c and is always taken.
  The `beq` branch at 0x1614 targets 0x1518 and is always taken.
  The `beq` branch at 0x1664 targets 0x1580 and is always taken.
  The `beq` branch at 0x1690 targets 0x15d0 and is always taken.
  The `beq` branch at 0x16ac targets 0x15f4 and is always taken.
  The return at 0x1598 has v0 = one of -0x5, ?.

- `ef_phyget` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x16b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x16b4-0x174c (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x16bc loads 8 bytes from a0 (arg0 at entry) +0x330.
  4 such `lw` accesses load 4 bytes from [a0+816]:8 +0x58, including `lw` at 0x16c0, `lw` at 0x16e4, `lw` at 0x1708.
  The `lw` at 0x16f4 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `sw` at 0x1704 stores 4 bytes to [a0+816]:8 +0x58.
  The `lw` at 0x1738 loads 4 bytes from [a0+816]:8 +0x5c.
  The `jal` at 0x16dc calls us_delaybus with a0=0x1, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1718 calls us_delaybus with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x16d4 targets 0x16f4, is taken when (at(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (at(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x16ec targets 0x16dc, is taken when (v0(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (v0(=[[a0+816]:8+88]) & 0x800) == 0.
  The `beq` branch at 0x1710 targets 0x1734, is taken when (v1(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (v1(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x1728 targets 0x1718, is taken when (a1(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (a1(=[[a0+816]:8+88]) & 0x800) == 0.
  The return at 0x1744 has v0 = ?.

- `ef_phyput` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x174c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x174c-0x17e4 (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x1754 loads 8 bytes from a0 (arg0 at entry) +0x330.
  4 such `lw` accesses load 4 bytes from [a0+816]:8 +0x58, including `lw` at 0x1758, `lw` at 0x1780, `lw` at 0x17a8.
  The `sw` at 0x1794 stores 4 bytes to [a0+816]:8 +0x60.
  The `lw` at 0x1798 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `sw` at 0x17a4 stores 4 bytes to [a0+816]:8 +0x58.
  The `jal` at 0x1778 calls us_delaybus with a0=0x1, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x17b8 calls us_delaybus with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1770 targets 0x1794, is taken when (at(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (at(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x1788 targets 0x1778, is taken when (v0(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (v0(=[[a0+816]:8+88]) & 0x800) == 0.
  The `beq` branch at 0x17b0 targets 0x17d4, is taken when (v1(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (v1(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x17c8 targets 0x17b8, is taken when (a1(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (a1(=[[a0+816]:8+88]) & 0x800) == 0.
  The return at 0x17dc has v0 = one of ?, ret(us_delaybus).

- `ef_phyrmw` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x17e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x17e4-0x183c (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x17fc calls ef_phyget with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1824 calls ef_phyput with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=a3 at entry (arg3).
  The return at 0x1834 has v0 = ret(ef_phyput).

- `ef_phyerrat` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x183c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x183c-0x191c (224 bytes).
  It occupies 224 bytes.
  The `lw` at 0x1850 loads 4 bytes from sym(ef_phyerrata) +0x4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3b0, including `lw` at 0x187c, `lw` at 0x1894.
  The `lw` at 0x1888 loads 4 bytes from sym(ef_phyerrata) +0x14.
  2 such `lh` accesses load 2 bytes from sym(ef_phyerrata) +0x8, including `lh` at 0x18a0, `lh` at 0x1918.
  The `lw` at 0x18ac loads 4 bytes from a0 (arg0 at entry) +0x3b8.
  The `lw` at 0x18b8 loads 4 bytes from sym(ef_phyerrata) +0x0.
  The `lh` at 0x18c4 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lhu` at 0x18d0 loads 2 bytes from sym(ef_phyerrata) +0xa.
  The `lhu` at 0x18d4 loads 2 bytes from sym(ef_phyerrata) +0xc.
  The `lhu` at 0x18e0 loads 2 bytes from sym(ef_phyerrata) +0xe.
  The `jal` at 0x18dc calls ef_phyrmw with a0=a0 at entry (arg0), a1=[sym(ef_phyerrata)+10]:2, a2=[sym(ef_phyerrata)+12]:2, a3=[sym(ef_phyerrata)+14]:2.
  The `beq` branch at 0x1870 targets 0x18f0, is taken when a2(=[sym(ef_phyerrata)+4]) == 0, and falls through when a2(=[sym(ef_phyerrata)+4]) != 0.
  The `beq` branch at 0x1878 targets 0x1898 and is always taken.
  The `beq` branch at 0x1880 targets 0x190c, is taken when s2(=0x15f42) == a2(?), and falls through when s2(=0x15f42) != a2(?).
  The `beq` branch at 0x188c targets 0x18f0, is taken when a2(=[sym(ef_phyerrata)+20]) == 0, and falls through when a2(=[sym(ef_phyerrata)+20]) != 0.
  The `bne` branch at 0x1898 targets 0x1880, is taken when a2(?) != a0(=[a0+944]), and falls through when a2(?) == a0(=[a0+944]).
  The `beq` branch at 0x18a4 targets 0x18b8, is taken when a0(=[sym(ef_phyerrata)+8]:2) == s3(=-0x1), and falls through when a0(=[sym(ef_phyerrata)+8]:2) != s3(=-0x1).
  The `bne` branch at 0x18b0 targets 0x1888, is taken when a0(=[sym(ef_phyerrata)+8]:2) != at(=[a0+952]), and falls through when a0(=[sym(ef_phyerrata)+8]:2) == at(=[a0+952]).
  The `beq` branch at 0x18bc targets 0x18d0, is taken when a0(=[sym(ef_phyerrata)]) == s3(=-0x1), and falls through when a0(=[sym(ef_phyerrata)]) != s3(=-0x1).
  The `bne` branch at 0x18c8 targets 0x1888, is taken when v0(=[a0+26]:2) != a0(=[sym(ef_phyerrata)]), and falls through when v0(=[a0+26]:2) == a0(=[sym(ef_phyerrata)]).
  The `beq` branch at 0x18e8 targets 0x1888 and is always taken.
  The `bne` branch at 0x190c targets 0x1888, is taken when a3(=0x15f43) != a0(=[a0+944]), and falls through when a3(=0x15f43) == a0(=[a0+944]).
  The `beq` branch at 0x1914 targets 0x18a4 and is always taken.
  The return at 0x1904 has v0 = ?.

- `ef_fill` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x191c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x191c-0x1a40 (292 bytes).
  It occupies 292 bytes.
  The `lw` at 0x1924 loads 4 bytes from a0 (arg0 at entry) +0x370.
  The `lw` at 0x192c loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x1934 loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `ld` at 0x1978 loads 8 bytes from ret(m_vget) +0x8.
  The `sw` at 0x1980 stores 4 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x0.
  The `sw` at 0x1984 stores 4 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x4.
  The `ld` at 0x1988 loads 8 bytes from a0 (arg0 at entry) +0x380.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x199c, `sd` at 0x19c4.
  The `ld` at 0x19a4 loads 8 bytes from a0 (arg0 at entry) +0x340.
  The `ld` at 0x19b0 loads 8 bytes from a0 (arg0 at entry) +0x368.
  The `ld` at 0x19dc loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `sw` at 0x19e0 stores 4 bytes to a0 (arg0 at entry) +0x374.
  The `sw` at 0x19ec stores 4 bytes to [a0+816]:8 +0x20.
  The `lw` at 0x1a14 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lh` at 0x1a24 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x1a30 loads 4 bytes from a0 (arg0 at entry) +0x420.
  The `sw` at 0x1a3c stores 4 bytes to a0 (arg0 at entry) +0x420.
  The `jal` at 0x1968 calls m_vget with a0=0x0, a1=0x800, a2=0x1, a3=?.
  The `jal` at 0x1998 calls kvtophys with a0=([ret(m_vget)+8]:8 + ret(m_vget)), a1=?, a2=?, a3=?.
  The `jal` at 0x19a8 calls pciio_dmamap_addr with a0=[a0+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x19c0 calls heart_invalidate_war with a0=([ret(m_vget)+8]:8 + ret(m_vget)), a1=0x8, a2=?, a3=?.
  The `jal` at 0x19e8 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a28 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `blez` branch at 0x1954 targets 0x19dc, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `beq` branch at 0x1970 targets 0x1a14, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `bne` branch at 0x19d4 targets 0x1960, is taken when s2(?) < s5(?) (signed), and falls through when s2(?) >= s5(?) (signed).
  The `beq` branch at 0x1a1c targets 0x1a30, is taken when (v0(=[a0+32]) & 0x4) == 0, and falls through when (v0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1a38 targets 0x19dc and is always taken.
  The return at 0x1a0c has v0 = ret(flushbus).

- `ef_xreset` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1a40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1a40-0x1abc (124 bytes).
  It occupies 124 bytes.
  The `ld` at 0x1a48 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x1aa0 loads 8 bytes from ?.
  The `jal` at 0x1a64 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a70 calls ef_reset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1a84 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1a9c calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1a90 targets 0x1aac, is taken when s0(=ret(ef_reset)) == 0, and falls through when s0(=ret(ef_reset)) != 0.
  The `bne` branch at 0x1aa4 targets 0x1a9c, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1ab4 has v0 = one of ret(mutex_bitunlock), ret(m_freem).

- `ef_reset` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1abc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1abc-0x1bbc (256 bytes).
  It occupies 256 bytes.
  The `ld` at 0x1ac4 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `sh` at 0x1ac8 stores 2 bytes to a0 (arg0 at entry) +0x1c.
  The `sw` at 0x1aec stores 4 bytes to [a0+272]:8 +0x34c.
  6 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1af8, `sd` at 0x1b0c, `sd` at 0x1b30.
  3 such `ld` accesses load 8 bytes from [a0+272]:8 +0x350, including `ld` at 0x1afc, `ld` at 0x1b18, `ld` at 0x1b34.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1b04, `ld` at 0x1b20, `ld` at 0x1b40.
  3 such `ld` accesses load 8 bytes from [a0+272]:8 +0x380, including `ld` at 0x1b58, `ld` at 0x1b74, `ld` at 0x1b90.
  The `sd` at 0x1bac stores 8 bytes to [a0+272]:8 +0x378.
  The `jal` at 0x1ad0 calls ef_getcdc with a0=[a0+272]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1ad8 calls ef_ioc3reset with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1af0 targets 0x1b14 and is always taken.
  The `beq` branch at 0x1b10 targets 0x1b4c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1b28 targets 0x1b10, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1b3c targets 0x1af8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1b44 targets 0x1b08 and is always taken.
  The `beq` branch at 0x1b4c targets 0x1b70 and is always taken.
  The `beq` branch at 0x1b6c targets 0x1ba8, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1b84 targets 0x1b6c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1b98 targets 0x1b54, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1ba0 targets 0x1b64 and is always taken.
  The return at 0x1bb4 has v0 = ?.

- `ef_ioc3reset` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1bbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1bbc-0x1c8c (208 bytes).
  It occupies 208 bytes.
  8 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x1bbc, `ld` at 0x1bc8, `ld` at 0x1bfc.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x0, including `sw` at 0x1bc4, `sw` at 0x1bf8.
  3 such `lw` accesses load 4 bytes from [a0+816]:8 +0x0, including `lw` at 0x1bcc, `lw` at 0x1bd4, `lw` at 0x1c5c.
  The `sw` at 0x1c00 stores 4 bytes to [a0+816]:8 +0x40.
  The `sw` at 0x1c08 stores 4 bytes to [a0+816]:8 +0x1c.
  The `sw` at 0x1c14 stores 4 bytes to [a0+816]:8 +0x44.
  The `sw` at 0x1c24 stores 4 bytes to [a0+816]:8 +0x20.
  The `lh` at 0x1c78 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `jal` at 0x1c20 calls flushbus with a0=?, a1=?, a2=[a0+816]:8, a3=[a0+816]:8, a4=[a0+816]:8, a5=[a0+816]:8.
  The `jal` at 0x1c40 calls us_delay with a0=0x1, a1=?, a2=[a0+816]:8, a3=?.
  The `jal` at 0x1c7c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `bgez` branch at 0x1bf0 targets 0x1c38, is taken when at(=([[a0+816]:8] << 0x2a)) >= 0 (signed), and falls through when at(=([[a0+816]:8] << 0x2a)) < 0 (signed).
  The `beq` branch at 0x1c50 targets 0x1c74, is taken when s1(?) == a0(=-0x1), and falls through when s1(?) != a0(=-0x1).
  The `beq` branch at 0x1c64 targets 0x1c40, is taken when (s2(=0x200000) & t8(=[[a0+816]:8])) == 0, and falls through when (s2(=0x200000) & t8(=[[a0+816]:8])) != 0.
  The `beq` branch at 0x1c6c targets 0x1bf8 and is always taken.
  The `beq` branch at 0x1c84 targets 0x1bf8 and is always taken.
  The return at 0x1c30 has v0 = ret(flushbus).

- `ef_watchdog` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1c8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1c8c-0x1db8 (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0x1c94 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x1ca0 loads 8 bytes from [a0+272]:8 +0x3a8.
  The `ld` at 0x1cdc loads 8 bytes from (sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4)) +0x8.
  The `ld` at 0x1ce0 loads 8 bytes from [(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8 +0x488.
  The `lw` at 0x1ce4 loads 4 bytes from [a0+272]:8 +0x34.
  The `lw` at 0x1ce8 loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1160]:8 +0x4.
  The `lw` at 0x1cec loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1160]:8 +0x8.
  The `lw` at 0x1cf0 loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1160]:8 +0x14.
  The `sw` at 0x1cf4 stores 4 bytes to [a0+272]:8 +0x3d4.
  The `sw` at 0x1d08 stores 4 bytes to [a0+272]:8 +0x3d8.
  The `ld` at 0x1d24 loads 8 bytes from [a0+272]:8 +0x378.
  The `lwu` at 0x1d30 loads 4 bytes from [a0+272]:8 +0x370.
  The `ld` at 0x1d34 loads 8 bytes from [a0+272]:8 +0x380.
  The `ld` at 0x1d40 loads 8 bytes from ([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3)) +0x0.
  The `ld` at 0x1d4c loads 8 bytes from [([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8 +0x8.
  The `sd` at 0x1d54 stores 8 bytes to [a0+272]:8 +0x378.
  The `sh` at 0x1d60 stores 2 bytes to [a0+272]:8 +0x1c.
  The `ld` at 0x1d90 loads 8 bytes from ?.
  The `jal` at 0x1c9c calls pciio_intr_cpu_get with a0=[[a0+272]:8+936]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1cac calls cpuvertex_to_cpuid with a0=ret(pciio_intr_cpu_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1cc4 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x1d04 calls ef_getcdc with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1d0c calls ef_reclaim with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1d18 calls ef_fill with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1d64 calls ef_phyerr with a0=[a0+272]:8, a1=ret(mutex_bitlock), a2=?, a3=?.
  The `jal` at 0x1d74 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1d8c calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1da0 calls ef_intr with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x1d28 targets 0x1d5c, is taken when v1(=[[a0+272]:8+888]:8) != a0(=sym(.bss)), and falls through when v1(=[[a0+272]:8+888]:8) == a0(=sym(.bss)).
  The `beq` branch at 0x1d44 targets 0x1d5c, is taken when v0(=[([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8) == 0, and falls through when v0(=[([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8) != 0.
  The `beq` branch at 0x1d80 targets 0x1d9c, is taken when s0(=ret(ef_reclaim)) == 0, and falls through when s0(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x1d94 targets 0x1d8c, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1db0 has v0 = ret(ef_intr).

- `ef_getcdc` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1db8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1db8-0x1de4 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x1db8 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x1dbc loads 4 bytes from [a0+816]:8 +0x30.
  The `lw` at 0x1dc0 loads 4 bytes from a0 (arg0 at entry) +0x3e4.
  The `lw` at 0x1dc4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `sw` at 0x1dd4 stores 4 bytes to a0 (arg0 at entry) +0x3e4.
  The `sw` at 0x1de0 stores 4 bytes to a0 (arg0 at entry) +0x44.
  The return at 0x1ddc has v0 = ?.

- `ef_intr` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x1de4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x1de4-0x233c (1368 bytes).
  It occupies 1368 bytes.
  The `lh` at 0x1df0 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x1e18 loads 4 bytes from a0 (arg0 at entry) +0x388.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x388, including `sw` at 0x1e30, `sw` at 0x1f64.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x1e34, `ld` at 0x1e9c, `ld` at 0x1f8c.
  The `lw` at 0x1e38 loads 4 bytes from [a0+816]:8 +0x4.
  The `sw` at 0x1e3c stores 4 bytes to [a0+816]:8 +0x4.
  The `ld` at 0x1e40 loads 8 bytes from a0 (arg0 at entry) +0x338.
  11 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x1e4c, `lw` at 0x1fa0, `lw` at 0x1fe8.
  The `lwu` at 0x1e90 loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `sw` at 0x1eac stores 4 bytes to [a0+816]:8 +0x20.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x378, including `ld` at 0x1eb8, `ld` at 0x1ebc.
  The `lw` at 0x1ec0 loads 4 bytes from [a0+888]:8 +0x0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1f34, `ld` at 0x21d0.
  The `ld` at 0x1f68 loads 8 bytes from abs 0xffffffffaff20000.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x38, including `lw` at 0x1fa4, `lw` at 0x1fec, `lw` at 0x227c.
  The `lw` at 0x1fa8 loads 4 bytes from a0 (arg0 at entry) +0x3f8.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x38, including `sw` at 0x1fb4, `sw` at 0x1ffc, `sw` at 0x2294.
  The `sw` at 0x1fc0 stores 4 bytes to a0 (arg0 at entry) +0x3f8.
  The `lw` at 0x1ff0 loads 4 bytes from a0 (arg0 at entry) +0x3fc.
  The `sw` at 0x2008 stores 4 bytes to a0 (arg0 at entry) +0x3fc.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x40, including `lw` at 0x203c, `lw` at 0x2078, `lw` at 0x20b4.
  The `lw` at 0x2040 loads 4 bytes from a0 (arg0 at entry) +0x40c.
  7 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x40, including `sw` at 0x204c, `sw` at 0x2088, `sw` at 0x20c4.
  The `sw` at 0x2058 stores 4 bytes to a0 (arg0 at entry) +0x40c.
  The `lw` at 0x207c loads 4 bytes from a0 (arg0 at entry) +0x410.
  The `sw` at 0x2094 stores 4 bytes to a0 (arg0 at entry) +0x410.
  The `lw` at 0x20b8 loads 4 bytes from a0 (arg0 at entry) +0x414.
  The `sw` at 0x20d0 stores 4 bytes to a0 (arg0 at entry) +0x414.
  The `lw` at 0x20f4 loads 4 bytes from a0 (arg0 at entry) +0x418.
  The `sw` at 0x210c stores 4 bytes to a0 (arg0 at entry) +0x418.
  The `lw` at 0x2130 loads 4 bytes from a0 (arg0 at entry) +0x400.
  The `sw` at 0x2148 stores 4 bytes to a0 (arg0 at entry) +0x400.
  The `lw` at 0x2168 loads 4 bytes from a0 (arg0 at entry) +0x358.
  The `lw` at 0x2198 loads 4 bytes from a0 (arg0 at entry) +0x34c.
  The `lw` at 0x219c loads 4 bytes from a0 (arg0 at entry) +0x348.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x404, including `lw` at 0x2288, `lw` at 0x22e8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x404, including `sw` at 0x22a0, `sw` at 0x2300.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x408, including `lw` at 0x22b8, `lw` at 0x2318.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x408, including `sw` at 0x22d0, `sw` at 0x2330.
  The `jal` at 0x1e0c calls mutex_bitlock with a0=a0+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e64 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1ea8 calls flushbus with a0=a0+856, a1=?, a2=(([a0+884] << 0x3) | 0x80000000), a3=[a0+816]:8, a4=0x80000000.
  The `jal` at 0x1eb4 calls heart_invalidate_war with a0=[a0+888]:8, a1=0x80, a2=?, a3=?.
  The `jal` at 0x1ed4 calls ef_recv with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0xffffffff80000000.
  The `jal` at 0x1f00 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1f20 calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1f40 calls ether_input with a0=a0 at entry (arg0), a1=one of 0x0, 0x1000, a2=?, a3=?.
  The `jal` at 0x1f80 calls randproc_input with a0=?, a1=0x500000000, a2=0xffffffff, a3=?.
  The `jal` at 0x1fcc calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=[a0+1016]+1, a4=[a0+56]+1.
  The `jal` at 0x2010 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=[a0+1020]+1, a3=?, a4=[a0+56]+1.
  The `jal` at 0x2060 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a6=([[a0+816]:8+4] << 0x2e), a7=[a0+1036]+1.
  The `jal` at 0x209c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x20d8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x2114 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x2150 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=[a0+64]+1.
  The `jal` at 0x2178 calls ef_reclaim with a0=a0 at entry (arg0), a1=?, a2=?, a3=([[a0+816]:8+4] << 0x29).
  The `jal` at 0x2190 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x21b4 calls ps_txq_stat with a0=a0 at entry (arg0), a1=?, a2=?, a3=[a0+844].
  The `jal` at 0x21cc calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x21e0 calls mutex_bitlock with a0=a0+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x21fc calls ef_getcdc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a6=([[a0+816]:8+4] << 0x26).
  The `jal` at 0x2214 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x2240 calls ef_init with a0=a0 at entry (arg0), a1=[a0+32], a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2260 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=([[a0+816]:8+4] << 0x29).
  The `jal` at 0x229c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x22cc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a6=([[a0+816]:8+4] << 0x2e).
  The `jal` at 0x22fc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a6=([[a0+816]:8+4] << 0x26), a7=([[a0+816]:8+4] << 0x25).
  The `jal` at 0x232c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a7=([[a0+816]:8+4] << 0x25).
  The `beq` branch at 0x1e2c targets 0x1f60, is taken when v0(=[a0+904]+1) >= 0x63 (unsigned), and falls through when v0(=[a0+904]+1) < 0x63 (unsigned).
  The `beq` branch at 0x1e44 targets 0x1e60, is taken when v1(=[a0+824]:8) == 0, and falls through when v1(=[a0+824]:8) != 0.
  The `beq` branch at 0x1e58 targets 0x1e90, is taken when a1(?) == a2(=0x41), and falls through when a1(?) != a2(=0x41).
  The `beq` branch at 0x1ecc targets 0x1ee0, is taken when (a3(=[[a0+888]:8]) & a4(=0xffffffff80000000)) == 0, and falls through when (a3(=[[a0+888]:8]) & a4(=0xffffffff80000000)) != 0.
  The `bne` branch at 0x1eec targets 0x1f90, is taken when (s2(=[[a0+816]:8+4]) & a4(=0x7fe003c)) != 0, and falls through when (s2(=[[a0+816]:8+4]) & a4(=0x7fe003c)) == 0.
  The `beq` branch at 0x1f08 targets 0x1e6c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1f18 targets 0x1f2c and is always taken.
  The `beq` branch at 0x1f28 targets 0x1f58, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x1f30 targets 0x1f20, is taken when s2(=one of 0x0, 0x1) != 0, and falls through when s2(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x1f50 targets 0x1f28 and is always taken.
  The `beq` branch at 0x1f58 targets 0x1e70 and is always taken.
  The `beq` branch at 0x1f88 targets 0x1e38 and is always taken.
  The `beq` branch at 0x1f94 targets 0x2270, is taken when (s2(=[[a0+816]:8+4]) & 0x4) == 0, and falls through when (s2(=[[a0+816]:8+4]) & 0x4) != 0.
  The `beq` branch at 0x1fbc targets 0x1fd4, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1fe0 targets 0x2020, is taken when (s2(=[[a0+816]:8+4]) & 0x8) == 0, and falls through when (s2(=[[a0+816]:8+4]) & 0x8) != 0.
  The `beq` branch at 0x2004 targets 0x2018, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `bne` branch at 0x2020 targets 0x227c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x2028 targets 0x22ac, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bgez` branch at 0x2030 targets 0x206c, is taken when a6(=([[a0+816]:8+4] << 0x2e)) >= 0 (signed), and falls through when a6(=([[a0+816]:8+4] << 0x2e)) < 0 (signed).
  The `beq` branch at 0x2054 targets 0x2068, is taken when (t0(=[a0+32]) & 0x4) == 0, and falls through when (t0(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x206c targets 0x20a8, is taken when t1(=([[a0+816]:8+4] << 0x2d)) >= 0 (signed), and falls through when t1(=([[a0+816]:8+4] << 0x2d)) < 0 (signed).
  The `beq` branch at 0x2090 targets 0x20a4, is taken when (t3(=[a0+32]) & 0x4) == 0, and falls through when (t3(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x20a8 targets 0x20e4, is taken when t8(=([[a0+816]:8+4] << 0x2c)) >= 0 (signed), and falls through when t8(=([[a0+816]:8+4] << 0x2c)) < 0 (signed).
  The `beq` branch at 0x20cc targets 0x20e0, is taken when (ra(=[a0+32]) & 0x4) == 0, and falls through when (ra(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x20e4 targets 0x2120, is taken when at(=([[a0+816]:8+4] << 0x2b)) >= 0 (signed), and falls through when at(=([[a0+816]:8+4] << 0x2b)) < 0 (signed).
  The `beq` branch at 0x2108 targets 0x211c, is taken when (v1(=[a0+32]) & 0x4) == 0, and falls through when (v1(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2120 targets 0x2160, is taken when a0(=([[a0+816]:8+4] << 0x2a)) >= 0 (signed), and falls through when a0(=([[a0+816]:8+4] << 0x2a)) < 0 (signed).
  The `beq` branch at 0x2144 targets 0x2158, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2160 targets 0x21f0, is taken when a3(=([[a0+816]:8+4] << 0x29)) >= 0 (signed), and falls through when a3(=([[a0+816]:8+4] << 0x29)) < 0 (signed).
  The `beq` branch at 0x2170 targets 0x2250, is taken when (a4(=[a0+856]) & 0x10) == 0, and falls through when (a4(=[a0+856]) & 0x10) != 0.
  The `beq` branch at 0x21bc targets 0x21e0, is taken when s7(=ret(ef_reclaim)) == 0, and falls through when s7(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x21d4 targets 0x21cc, is taken when s7(?) != 0, and falls through when s7(?) == 0.
  The `beq` branch at 0x21f4 targets 0x2220, is taken when (s2(=[[a0+816]:8+4]) & a4(=0x1800000)) == 0, and falls through when (s2(=[[a0+816]:8+4]) & a4(=0x1800000)) != 0.
  The `beq` branch at 0x220c targets 0x221c, is taken when (a5(=[a0+32]) & 0x4) == 0, and falls through when (a5(=[a0+32]) & 0x4) != 0.
  The `bltz` branch at 0x2220 targets 0x22dc, is taken when a6(=([[a0+816]:8+4] << 0x26)) < 0 (signed), and falls through when a6(=([[a0+816]:8+4] << 0x26)) >= 0 (signed).
  The `bltz` branch at 0x2228 targets 0x230c, is taken when a7(=([[a0+816]:8+4] << 0x25)) < 0 (signed), and falls through when a7(=([[a0+816]:8+4] << 0x25)) >= 0 (signed).
  The `beq` branch at 0x2230 targets 0x1ef4, is taken when s5(=one of 0x0, 0x1) == 0, and falls through when s5(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2248 targets 0x1ef8 and is always taken.
  The `beq` branch at 0x2258 targets 0x21ec, is taken when (t0(=[a0+32]) & 0x4) == 0, and falls through when (t0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2268 targets 0x21f0 and is always taken.
  The `beq` branch at 0x2274 targets 0x1fdc and is always taken.
  The `beq` branch at 0x22a4 targets 0x2024 and is always taken.
  The `beq` branch at 0x22d4 targets 0x202c and is always taken.
  The `beq` branch at 0x2304 targets 0x2224 and is always taken.
  The `beq` branch at 0x2334 targets 0x2230 and is always taken.
  The return at 0x1e88 has v0 = one of ret(mutex_bitunlock), ?.

- `ef_recv` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x233c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x233c-0x2858 (1308 bytes).
  It occupies 1308 bytes.
  The `lh` at 0x233c loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x2360 loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x2364 loads 4 bytes from a0 (arg0 at entry) +0x370.
  The `sw` at 0x23a0 stores 4 bytes to a0 (arg0 at entry) +0x370.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x380, including `ld` at 0x23c4, `ld` at 0x256c, `ld` at 0x25c0.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x23d4, `ld` at 0x23e8, `ld` at 0x2578.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x378, including `sd` at 0x23f0, `sd` at 0x2670.
  9 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2408, `lhu` at 0x2440, `lhu` at 0x2444.
  7 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2418, `lbu` at 0x2484, `lbu` at 0x24c4.
  The `lw` at 0x2430 loads 4 bytes from a0 (arg0 at entry) +0x358.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x24a4, `lw` at 0x24b8, `lw` at 0x2594.
  The `sb` at 0x254c stores 1 byte to ?.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0x25e4, `sd` at 0x25fc, `sd` at 0x2608.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2604, `sh` at 0x263c, `sh` at 0x2790.
  The `lw` at 0x260c loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x2618 loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `sw` at 0x2628 stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `sw` at 0x2638 stores 4 bytes to a0 (arg0 at entry) +0x48.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x26b4, `lw` at 0x2704, `lw` at 0x2748.
  The `lw` at 0x26b8 loads 4 bytes from a0 (arg0 at entry) +0x3e8.
  The `sw` at 0x26cc stores 4 bytes to a0 (arg0 at entry) +0x3e8.
  The `lw` at 0x2708 loads 4 bytes from a0 (arg0 at entry) +0x3ec.
  The `sw` at 0x271c stores 4 bytes to a0 (arg0 at entry) +0x3ec.
  The `lw` at 0x274c loads 4 bytes from a0 (arg0 at entry) +0x3f0.
  The `sw` at 0x2760 stores 4 bytes to a0 (arg0 at entry) +0x3f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3f4, including `lw` at 0x27c8, `lw` at 0x2814.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3f4, including `sw` at 0x27d8, `sw` at 0x2824.
  The `jal` at 0x23a4 calls ef_fill with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2550 calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2588 calls heart_invalidate_war with a0=?, a1=0x80, a2=?, a3=?.
  The `jal` at 0x25a0 calls us_delay with a0=[sym(.sdata)+16], a1=?, a2=?, a3=?.
  The `jal` at 0x25e8 calls heart_invalidate_war with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x26d8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a4=[a0+1000]+1, a6=0x30.
  The `jal` at 0x2720 calls ether_sprintf with a0=?, a1=?, a2=?, a3=[a0+1004]+1.
  The `jal` at 0x2734 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `jal` at 0x276c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=[a0+1008]+1, a3=?.
  The `jal` at 0x277c calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2798 calls ether_input with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x27dc calls ether_sprintf with a0=?, a1=0x40000000, a2=0x5fc, a3=?, a4=[a0+1012]+1, a6=0x30.
  The `jal` at 0x27f0 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `jal` at 0x2828 calls ether_sprintf with a0=?, a1=[a0+1012]+1, a2=?, a3=?, a6=0x30.
  The `jal` at 0x283c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `beq` branch at 0x237c targets 0x2398, is taken when at(=[a0+880]) == a1(=[a0+884]), and falls through when at(=[a0+880]) != a1(=[a0+884]).
  The `beq` branch at 0x2390 targets 0x256c and is always taken.
  The `beq` branch at 0x23e0 targets 0x266c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x2400 targets 0x2650, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x2410 targets 0x2650, is taken when (a2(?) & 0x3fff) != 0, and falls through when (a2(?) & 0x3fff) == 0.
  The `beq` branch at 0x2420 targets 0x2430, is taken when a3(=0x6) == a2(?), and falls through when a3(=0x6) != a2(?).
  The `bne` branch at 0x2428 targets 0x2650, is taken when a4(=0x11) != a2(?), and falls through when a4(=0x11) == a2(?).
  The `beq` branch at 0x2438 targets 0x2650, is taken when (a6(=[a0+856]) & 0x1) == 0, and falls through when (a6(=[a0+856]) & 0x1) != 0.
  The `beq` branch at 0x24ec targets 0x267c, is taken when (s4(?) & 0x1) == 0, and falls through when (s4(?) & 0x1) != 0.
  The `bne` branch at 0x2538 targets 0x2650, is taken when a2(=0xffff) != a3(?), and falls through when a2(=0xffff) == a3(?).
  The `beq` branch at 0x2548 targets 0x2654, is taken when s8(=one of 0x0, 0x1) == 0, and falls through when s8(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2564 targets 0x23a0, is taken when a6(=[a0+884]) == s3(?), and falls through when a6(=[a0+884]) != s3(?).
  The `beq` branch at 0x2598 targets 0x25a8, is taken when s6(=[sym(.sdata)+12]) == 0, and falls through when s6(=[sym(.sdata)+12]) != 0.
  The `beq` branch at 0x25b0 targets 0x23a0, is taken when (s6(?) & t8(=0xffffffff80000000)) == 0, and falls through when (s6(?) & t8(=0xffffffff80000000)) != 0.
  The `beq` branch at 0x2634 targets 0x26a8, is taken when (s7(?) & a1(=0x40000000)) == 0, and falls through when (s7(?) & a1(=0x40000000)) != 0.
  The `beq` branch at 0x2648 targets 0x2400, is taken when v0(=0x800) == a5(?), and falls through when v0(=0x800) != a5(?).
  The `bne` branch at 0x2650 targets 0x2550, is taken when s8(=one of 0x0, 0x1) != 0, and falls through when s8(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x2658 targets 0x2674, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x2664 targets 0x2558 and is always taken.
  The `beq` branch at 0x266c targets 0x23f4 and is always taken.
  The `beq` branch at 0x2674 targets 0x2664 and is always taken.
  The `beq` branch at 0x26a0 targets 0x251c and is always taken.
  The `beq` branch at 0x26ac targets 0x26f4, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `beq` branch at 0x26c8 targets 0x26e0, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x26e4 targets 0x2804, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x26ec targets 0x2704 and is always taken.
  The `beq` branch at 0x26f4 targets 0x27b8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x26fc targets 0x2810, is taken when s4(?) == a2(=0x5fc), and falls through when s4(?) != a2(=0x5fc).
  The `beq` branch at 0x2718 targets 0x273c, is taken when (a4(=[a0+32]) & 0x4) == 0, and falls through when (a4(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2740 targets 0x2774, is taken when (s7(?) & 0x4) == 0, and falls through when (s7(?) & 0x4) != 0.
  The `beq` branch at 0x275c targets 0x2774, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2774 targets 0x278c, is taken when s8(=one of 0x0, 0x1) == 0, and falls through when s8(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2784 targets 0x255c and is always taken.
  The `beq` branch at 0x27b0 targets 0x2558 and is always taken.
  The `bne` branch at 0x27bc targets 0x2850, is taken when s4(?) < 0x5eb (signed), and falls through when s4(?) >= 0x5eb (signed).
  The `beq` branch at 0x27d4 targets 0x27f8, is taken when (a5(=[a0+32]) & 0x4) == 0, and falls through when (a5(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x27fc targets 0x273c and is always taken.
  The `beq` branch at 0x2808 targets 0x273c and is always taken.
  The `beq` branch at 0x2820 targets 0x2844, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2848 targets 0x273c and is always taken.
  The `beq` branch at 0x2850 targets 0x273c and is always taken.
  The return at 0x23f8 has v0 = ?.

- `ef_transmit` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x2858 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x2858-0x306c (2068 bytes).
  It occupies 2068 bytes.
  The `ld` at 0x2860 loads 8 bytes from a0 (arg0 at entry) +0x110.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x28a4, `ld` at 0x28d8, `ld` at 0x2c78.
  The `lhu` at 0x28a8 loads 2 bytes from ?.
  2 such `lbu` accesses load 1 byte from a4 (arg4 at entry) +0x1a, including `lbu` at 0x28ec, `lbu` at 0x2a70.
  5 such `ld` accesses load 8 bytes from a4 (arg4 at entry) +0x8, including `ld` at 0x28fc, `ld` at 0x2d10, `ld` at 0x2d48.
  The `lbu` at 0x2904 loads 1 byte from ([a4+8]:8 + a4) +0x9.
  The `lbu` at 0x290c loads 1 byte from ([a4+8]:8 + a4) +0x0.
  The `lhu` at 0x2920 loads 2 bytes from a1 (arg1 at entry) +0x2.
  The `lhu` at 0x2924 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `lhu` at 0x2928 loads 2 bytes from a2 (arg2 at entry) +0x4.
  The `lhu` at 0x292c loads 2 bytes from ([a4+8]:8 + a4) +0x2.
  The `lhu` at 0x2930 loads 2 bytes from a2 (arg2 at entry) +0x0.
  The `lhu` at 0x2938 loads 2 bytes from a2 (arg2 at entry) +0x2.
  The `lhu` at 0x2944 loads 2 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0x2950 loads 4 bytes from ([a4+8]:8 + a4) +0xc.
  The `lw` at 0x2974 loads 4 bytes from ([a4+8]:8 + a4) +0x10.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x29d0, `sh` at 0x2a68.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x358, including `lw` at 0x29e8, `lw` at 0x2bb0.
  3 such `lw` accesses load 4 bytes from [a0+272]:8 +0x34c, including `lw` at 0x29f8, `lw` at 0x2c34, `lw` at 0x2f78.
  5 such `lw` accesses load 4 bytes from [a0+272]:8 +0x348, including `lw` at 0x29fc, `lw` at 0x2bc0, `lw` at 0x2c10.
  The `ld` at 0x2a14 loads 8 bytes from [a0+272]:8 +0x338.
  The `lwl` at 0x2a28 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lwr` at 0x2a30 loads 4 bytes from a1 (arg1 at entry) +0x3.
  14 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2a34, `sw` at 0x2b44, `sw` at 0x2b68.
  The `lbu` at 0x2a38 loads 1 byte from a1 (arg1 at entry) +0x4.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x2a3c, `sb` at 0x2a44, `sb` at 0x2a60.
  The `lbu` at 0x2a40 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lwl` at 0x2a48 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lwr` at 0x2a50 loads 4 bytes from a2 (arg2 at entry) +0x3.
  The `swl` at 0x2a54 stores 4 bytes to ?.
  The `swr` at 0x2a58 stores 4 bytes to ?.
  The `lbu` at 0x2a5c loads 1 byte from a2 (arg2 at entry) +0x4.
  The `lbu` at 0x2a64 loads 1 byte from a2 (arg2 at entry) +0x5.
  6 such `lhu` accesses load 2 bytes from a4 (arg4 at entry) +0x18, including `lhu` at 0x2ab8, `lhu` at 0x2b50, `lhu` at 0x2d38.
  2 such `ld` accesses load 8 bytes from a4 (arg4 at entry) +0x0, including `ld` at 0x2abc, `ld` at 0x2d7c.
  The `ld` at 0x2ac8 loads 8 bytes from [a4]:8 +0x0.
  5 such `ld` accesses load 8 bytes from [a4]:8 +0x8, including `ld` at 0x2ae0, `ld` at 0x2b6c, `ld` at 0x2d94.
  4 such `lhu` accesses load 2 bytes from [a4]:8 +0x18, including `lhu` at 0x2af4, `lhu` at 0x2b4c, `lhu` at 0x2dd4.
  2 such `ld` accesses load 8 bytes from [[a4]:8]:8 +0x8, including `ld` at 0x2b08, `ld` at 0x2b90.
  The `lhu` at 0x2b48 loads 2 bytes from [[a4]:8]:8 +0x18.
  7 such `ld` accesses load 8 bytes from [a0+272]:8 +0x340, including `ld` at 0x2b88, `ld` at 0x2ba8, `ld` at 0x2d60.
  7 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2b8c, `sd` at 0x2bac, `sd` at 0x2d68.
  The `lw` at 0x2bc4 loads 4 bytes from [a0+272]:8 +0x35c.
  The `lw` at 0x2bd4 loads 4 bytes from ?.
  The `lbu` at 0x2be0 loads 1 byte from [a0+272]:8 +0x1de.
  The `lwu` at 0x2bfc loads 4 bytes from [a0+272]:8 +0x348.
  The `ld` at 0x2c00 loads 8 bytes from [a0+272]:8 +0x350.
  The `sd` at 0x2c0c stores 8 bytes to ([[a0+272]:8+848]:8 + ([[a0+272]:8+840] << 0x3)) +0x0.
  The `ld` at 0x2c1c loads 8 bytes from [a0+272]:8 +0x330.
  The `sw` at 0x2c24 stores 4 bytes to [a0+272]:8 +0x348.
  The `sw` at 0x2c2c stores 4 bytes to [[a0+272]:8+816]:8 +0x44.
  The `lw` at 0x2c40 loads 4 bytes from [a0+272]:8 +0x4c.
  The `sw` at 0x2c50 stores 4 bytes to [a0+272]:8 +0x4c.
  2 such `ld` accesses load 8 bytes from ret(m_vget) +0x8, including `ld` at 0x2e98, `ld` at 0x2edc.
  The `sh` at 0x2eac stores 2 bytes to ret(m_vget) +0x18.
  The `lhu` at 0x2ecc loads 2 bytes from ret(m_vget) +0x18.
  The `lw` at 0x2f04 loads 4 bytes from [a0+272]:8 +0x41c.
  The `sw` at 0x2f14 stores 4 bytes to [a0+272]:8 +0x41c.
  The `lw` at 0x2f90 loads 4 bytes from [a0+272]:8 +0x424.
  The `sw` at 0x2f98 stores 4 bytes to [a0+272]:8 +0x424.
  3 such `lw` accesses load 4 bytes from [a0+272]:8 +0x20, including `lw` at 0x2fa4, `lw` at 0x2ff8, `lw` at 0x3034.
  3 such `lh` accesses load 2 bytes from [a0+272]:8 +0x1a, including `lh` at 0x2fb8, `lh` at 0x300c, `lh` at 0x3048.
  The `lw` at 0x2fe4 loads 4 bytes from [a0+272]:8 +0x428.
  The `sw` at 0x2ff4 stores 4 bytes to [a0+272]:8 +0x428.
  The `lw` at 0x3020 loads 4 bytes from [a0+272]:8 +0x420.
  The `sw` at 0x3030 stores 4 bytes to [a0+272]:8 +0x420.
  The `jal` at 0x29e0 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2b28 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=[a4+24]:2, a3=?.
  The `jal` at 0x2b70 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=((([[a4]:8+24]:2 << 0x8) | ([[[a4]:8]:8+24]:2 << 0x14)) | [a4+24]:2+14), a2=[a4+24]:2+14, a3=([[[a4]:8]:8+24]:2 << 0x14).
  The `jal` at 0x2b84 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2b94 calls kvtophys with a0=([[[a4]:8]:8+8]:8 + [[a4]:8]:8), a1=?, a2=?, a3=?.
  The `jal` at 0x2ba4 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2bf4 calls ef_selfsnoop with a0=[a0+272]:8, a1=?, a2=?, a3=?, a4=[[a0+272]:8+478]:1.
  The `jal` at 0x2c28 calls flushbus with a0=?, a1=?, a2=?, a3=?, a7=[[a0+272]:8+816]:8.
  The `jal` at 0x2c60 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2c74 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2cb8 calls ef_reclaim with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x2cd0 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2d4c calls kvtophys with a0=([a4+8]:8 + a4), a1=(([a4+24]:2 << 0x8) | 0xe), a2=?, a3=?.
  The `jal` at 0x2d5c calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2dc0 calls bcopy with a0=([a4+8]:8 + a4), a1=?, a2=[a4+24]:2, a3=?.
  The `jal` at 0x2df0 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=(([[a4]:8+24]:2 << 0x8) | [a4+24]:2+14), a2=[a4+24]:2+14, a3=?.
  The `jal` at 0x2e00 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2e3c calls kvtophys with a0=([a4+8]:8 + a4), a1=((([[a4]:8+24]:2 << 0x14) | ([a4+24]:2 << 0x8)) | 0xe), a2=([a4+24]:2 << 0x8), a3=?.
  The `jal` at 0x2e4c calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2e5c calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=?, a2=?, a3=?.
  The `jal` at 0x2e6c calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2e84 calls m_vget with a0=0x0, a1=?, a2=0x1, a3=?.
  The `jal` at 0x2ea4 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=?, a3=([ret(m_vget)+8]:8 + ret(m_vget)).
  The `jal` at 0x2eb0 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2ee4 calls kvtophys with a0=([ret(m_vget)+8]:8 + ret(m_vget)), a1=(([ret(m_vget)+24]:2 << 0x8) | 0xe), a2=?, a3=?.
  The `jal` at 0x2ef4 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2f10 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2f20 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2f30 calls ef_reclaim with a0=[a0+272]:8, a1=[[a0+272]:8+840], a2=?, a3=?.
  The `jal` at 0x2f44 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2f58 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2f6c calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x2f9c calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+840], a2=?, a3=?.
  The `jal` at 0x2fbc calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x2fcc calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2ff0 calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+1064]+1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3010 calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x302c calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+1056]+1, a2=?, a3=?.
  The `jal` at 0x304c calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x305c calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `beq` branch at 0x2894 targets 0x2cf4, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x28bc targets 0x28d8, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x28cc targets 0x28d8, is taken when a4(?) == a5(?), and falls through when a4(?) != a5(?).
  The `bne` branch at 0x28dc targets 0x28a4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x28e4 targets 0x2fe4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x28f4 targets 0x2d00, is taken when (a7(=[a4+26]:1) & 0x2) == 0, and falls through when (a7(=[a4+26]:1) & 0x2) != 0.
  The `beq` branch at 0x2914 targets 0x2d08, is taken when a1(=[([a4+8]:8 + a4)+9]:1) == v1(=0x6), and falls through when a1(=[([a4+8]:8 + a4)+9]:1) != v1(=0x6).
  The `bne` branch at 0x29f0 targets 0x2f04, is taken when (a6(=[[a0+272]:8+856]) & 0x4) != 0, and falls through when (a6(=[[a0+272]:8+856]) & 0x4) == 0.
  The `beq` branch at 0x2a20 targets 0x2f30, is taken when a0(=[[a0+272]:8+844]) == t9(?), and falls through when a0(=[[a0+272]:8+844]) != t9(?).
  The `beq` branch at 0x2a78 targets 0x2a94, is taken when (ra(=[a4+26]:1) & 0x2) == 0, and falls through when (ra(=[a4+26]:1) & 0x2) != 0.
  The `bne` branch at 0x2a94 targets 0x2cc8, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x2aa0 targets 0x2d10, is taken when s3(?) == t9(=0x1), and falls through when s3(?) != t9(=0x1).
  The `beq` branch at 0x2aa8 targets 0x2d6c, is taken when s3(?) == ra(=0x2), and falls through when s3(?) != ra(=0x2).
  The `bne` branch at 0x2ab0 targets 0x2e80, is taken when s3(?) != at(=0x3), and falls through when s3(?) == at(=0x3).
  The `beq` branch at 0x2ac4 targets 0x2e7c, is taken when a2(=[a4+24]:2) >= 0x59 (signed), and falls through when a2(=[a4+24]:2) < 0x59 (signed).
  The `blez` branch at 0x2acc targets 0x2e80, is taken when a2(=[a4+24]:2) <= 0 (signed), and falls through when a2(=[a4+24]:2) > 0 (signed).
  The `bne` branch at 0x2ad8 targets 0x2e80, is taken when (a2(=[a4+24]:2) & 0x1) != 0, and falls through when (a2(=[a4+24]:2) & 0x1) == 0.
  The `bne` branch at 0x2aec targets 0x2e80, is taken when (a0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) != 0, and falls through when (a0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) == 0.
  The `blez` branch at 0x2af8 targets 0x2e7c, is taken when a0(=[[a4]:8+24]:2) <= 0 (signed), and falls through when a0(=[[a4]:8+24]:2) > 0 (signed).
  The `bne` branch at 0x2b00 targets 0x2e80, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x2b14 targets 0x2e80, is taken when (a3(=([[[a4]:8]:8+8]:8 + [[a4]:8]:8)) & 0x7f) != 0, and falls through when (a3(=([[[a4]:8]:8+8]:8 + [[a4]:8]:8)) & 0x7f) == 0.
  The `beq` branch at 0x2bb8 targets 0x2bd4, is taken when (a1(=[[a0+272]:8+856]) & 0x10) == 0, and falls through when (a1(=[[a0+272]:8+856]) & 0x10) != 0.
  The `beq` branch at 0x2bcc targets 0x2fdc, is taken when (a2(=[[a0+272]:8+840]) & a3(=[[a0+272]:8+860])) == 0, and falls through when (a2(=[[a0+272]:8+840]) & a3(=[[a0+272]:8+860])) != 0.
  The `beq` branch at 0x2be4 targets 0x2bfc, is taken when a4(=[[a0+272]:8+478]:1) == 0, and falls through when a4(=[[a0+272]:8+478]:1) != 0.
  The `beq` branch at 0x2c4c targets 0x2cb8, is taken when t8(?) >= 0x15 (unsigned), and falls through when t8(?) < 0x15 (unsigned).
  The `beq` branch at 0x2c68 targets 0x2c88, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x2c7c targets 0x2c74, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x2cc0 targets 0x2c58 and is always taken.
  The `beq` branch at 0x2cec targets 0x2bb0 and is always taken.
  The `beq` branch at 0x2cf8 targets 0x28ec and is always taken.
  The `beq` branch at 0x2d00 targets 0x29d4 and is always taken.
  The `beq` branch at 0x2d08 targets 0x2920 and is always taken.
  The `bne` branch at 0x2d1c targets 0x2e80, is taken when (v0(=([a4+8]:8 + a4)) & 0x1) != 0, and falls through when (v0(=([a4+8]:8 + a4)) & 0x1) == 0.
  The `beq` branch at 0x2d64 targets 0x2bb0 and is always taken.
  The `bne` branch at 0x2d78 targets 0x2e7c, is taken when (a0(=([a4+8]:8 + a4)) & 0x1) != 0, and falls through when (a0(=([a4+8]:8 + a4)) & 0x1) == 0.
  The `blez` branch at 0x2d84 targets 0x2e7c, is taken when a2(=[a4+24]:2) <= 0 (signed), and falls through when a2(=[a4+24]:2) > 0 (signed).
  The `bne` branch at 0x2d8c targets 0x2e7c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x2da0 targets 0x2e7c, is taken when (v0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) != 0, and falls through when (v0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) == 0.
  The `beq` branch at 0x2da8 targets 0x2db4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2db0 targets 0x2e7c, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x2db8 targets 0x2e10, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2e08 targets 0x2bb0 and is always taken.
  The `beq` branch at 0x2e74 targets 0x2bb0 and is always taken.
  The `beq` branch at 0x2e8c targets 0x3020, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `beq` branch at 0x2efc targets 0x2bb0 and is always taken.
  The `beq` branch at 0x2f28 targets 0x2c88 and is always taken.
  The `beq` branch at 0x2f4c targets 0x2f6c, is taken when s0(=ret(ef_reclaim)) == 0, and falls through when s0(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x2f60 targets 0x2f58, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0x2f88 targets 0x2a08, is taken when a0(=[[a0+272]:8+844]) != t9(?), and falls through when a0(=[[a0+272]:8+844]) == t9(?).
  The `beq` branch at 0x2fac targets 0x2fc8, is taken when (at(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (at(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x2fd4 targets 0x2c88 and is always taken.
  The `beq` branch at 0x2fdc targets 0x2bd4 and is always taken.
  The `beq` branch at 0x3000 targets 0x3018, is taken when (a2(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (a2(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x3018 targets 0x2c88 and is always taken.
  The `beq` branch at 0x303c targets 0x3058, is taken when (a2(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (a2(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x3064 targets 0x2c88 and is always taken.
  The return at 0x2cb0 has v0 = one of 0x0, 0x7, 0x7f, 0x84.

- `ef_selfsnoop` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x306c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x306c-0x31c0 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0x311c loads 8 bytes from ret(m_vget) +0x8.
  The `sh` at 0x3138 stores 2 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x8.
  The `sd` at 0x3144 stores 8 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x0.
  The `ldl` at 0x3148 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `ldr` at 0x3150 loads 8 bytes from a1 (arg1 at entry) +0x7.
  The `sdl` at 0x3154 stores 8 bytes to ?.
  The `sdr` at 0x3158 stores 8 bytes to ?.
  The `lwl` at 0x315c loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lwr` at 0x3168 loads 4 bytes from a1 (arg1 at entry) +0xb.
  The `swl` at 0x3174 stores 4 bytes to ?.
  The `swr` at 0x3180 stores 4 bytes to ?.
  The `lhu` at 0x318c loads 2 bytes from a1 (arg1 at entry) +0xc.
  The `sh` at 0x3198 stores 2 bytes to ?.
  The `jal` at 0x30a4 calls bcopy with a0=a1 at entry (arg1), a1=sp-110, a2=0xe, a3=a3 at entry (arg3).
  The `jal` at 0x30bc calls m_datacopy with a0=a2 at entry (arg2), a1=0x0, a2=0x14, a3=sp-96.
  The `jal` at 0x30d0 calls snoop_match with a0=a0+400, a1=sp-110, a2=0x24, a3=?.
  The `jal` at 0x30ec calls m_vget with a0=0x0, a1=(a3+48 << 0x0), a2=0x1, a3=?.
  The `jal` at 0x310c calls snoop_drop2 with a0=a0+400, a1=0x8000, a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=ret(snoop_match).
  The `jal` at 0x3140 calls m_datacopy with a0=a2 at entry (arg2), a1=0x0, a2=a3 at entry (arg3), a3=([ret(m_vget)+8]:8 + ret(m_vget))+48, a4=([ret(m_vget)+8]:8 + ret(m_vget)), a5=0x30.
  The `jal` at 0x3194 calls snoop_input2 with a0=a0+400, a1=0x8000, a2=?, a3=?, a5=ret(snoop_match), a6=[a1+12]:2.
  The `beq` branch at 0x30d8 targets 0x319c, is taken when v0(=ret(snoop_match)) == 0, and falls through when v0(=ret(snoop_match)) != 0.
  The `bne` branch at 0x30f4 targets 0x311c, is taken when v0(=ret(m_vget)) != 0, and falls through when v0(=ret(m_vget)) == 0.
  The `beq` branch at 0x3114 targets 0x31a0 and is always taken.
  The return at 0x31b8 has v0 = one of ret(snoop_drop2), ?.

- `ef_ioctl` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x31c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x31c0-0x3374 (436 bytes).
  It occupies 436 bytes.
  The `ld` at 0x31dc loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x3214 loads 8 bytes from a2 (arg2 at entry) +0x0.
  The `sh` at 0x3278 stores 2 bytes to a2 (arg2 at entry) +0x8.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3288, `lbu` at 0x3320.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x8, including `lhu` at 0x32ac, `lhu` at 0x3308.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x32dc, `sb` at 0x332c.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x3c4, including `lw` at 0x32e0, `lw` at 0x3330.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x20, including `lw` at 0x32e8, `lw` at 0x3338.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x3c4, including `sw` at 0x32f4, `sw` at 0x3340.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x20, including `sw` at 0x3360, `sw` at 0x3370.
  The `jal` at 0x31fc calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3240 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x3268 calls ef_lafhash with a0=[a2]:8+2, a1=0x6, a2=[a2]:8, a3=?.
  The `jal` at 0x32a4 calls ef_lafhash with a0=[a2]:8+2, a1=0x6, a2=[a2]:8, a3=?.
  The `jal` at 0x32c0 calls mfhasvalue with a0=a0+296, a1=[a2+8]:2, a2=?, a3=?.
  The `jal` at 0x32f8 calls ef_init with a0=a0 at entry (arg0), a1=?, a2=ret(mutex_bitlock), a3=?, a4=[[a0+272]:8+964]+1.
  The `jal` at 0x3348 calls ef_init with a0=a0 at entry (arg0), a1=?, a2=ret(mutex_bitlock), a3=?, a5=[[a0+272]:8+964]-1.
  The `beq` branch at 0x3218 targets 0x3264, is taken when s3(=a1) == a1(=0xffffffff80206931), and falls through when s3(=a1) != a1(=0xffffffff80206931).
  The `beq` branch at 0x3220 targets 0x32a4, is taken when s3(=a1) == a0(=0xffffffff80206932), and falls through when s3(=a1) != a0(=0xffffffff80206932).
  The `beq` branch at 0x3294 targets 0x32d8, is taken when (a5(?) & a0(?)) == 0, and falls through when (a5(?) & a0(?)) != 0.
  The `beq` branch at 0x329c targets 0x322c and is always taken.
  The `beq` branch at 0x32b0 targets 0x32c0, is taken when v0(=ret(ef_lafhash)) == a1(=[a2+8]:2), and falls through when v0(=ret(ef_lafhash)) != a1(=[a2+8]:2).
  The `beq` branch at 0x32b8 targets 0x322c and is always taken.
  The `beq` branch at 0x32c8 targets 0x3308, is taken when v0(=ret(mfhasvalue)) == 0, and falls through when v0(=ret(mfhasvalue)) != 0.
  The `beq` branch at 0x32d0 targets 0x322c and is always taken.
  The `beq` branch at 0x32e4 targets 0x3358, is taken when v0(=[[a0+272]:8+964]) == 0, and falls through when v0(=[[a0+272]:8+964]) != 0.
  The `beq` branch at 0x3300 targets 0x3228 and is always taken.
  The `beq` branch at 0x333c targets 0x3364, is taken when a5(=[[a0+272]:8+964]-1) == 0, and falls through when a5(=[[a0+272]:8+964]-1) != 0.
  The `beq` branch at 0x3350 targets 0x3228 and is always taken.
  The `beq` branch at 0x335c targets 0x32ec and is always taken.
  The `beq` branch at 0x336c targets 0x3344 and is always taken.
  The return at 0x325c has v0 = ?.

- `ef_lafhash` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x3374 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x3374-0x3428 (180 bytes).
  It occupies 180 bytes.
  The `lbu` at 0x33a8 loads 1 byte from ?.
  The `blez` branch at 0x337c targets 0x33dc, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x338c targets 0x3398 and is always taken.
  The `bltz` branch at 0x3394 targets 0x33dc, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `beq` branch at 0x33a4 targets 0x341c and is always taken.
  The `bltz` branch at 0x33b4 targets 0x3394, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `bne` branch at 0x33cc targets 0x33ac, is taken when (at(?) & 0x1) != 0, and falls through when (at(?) & 0x1) == 0.
  The `beq` branch at 0x33d4 targets 0x33b0 and is always taken.
  The `bltz` branch at 0x33f8 targets 0x3414, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `bgez` branch at 0x340c targets 0x33e4, is taken when t1(?) >= 0 (signed), and falls through when t1(?) < 0 (signed).
  The `beq` branch at 0x3420 targets 0x33c0 and is always taken.
  The return at 0x3414 has v0 = ?.

- `ef_phystr` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x3428 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x3428-0x34b8 (144 bytes).
  It occupies 144 bytes.
  The `beq` branch at 0x3440 targets 0x3498, is taken when a0 == at(=0x181441), and falls through when a0 != at(=0x181441).
  The `beq` branch at 0x3450 targets 0x34a4, is taken when a0 == v0(=0x15f41), and falls through when a0 != v0(=0x15f41).
  The `beq` branch at 0x346c targets 0x349c, is taken when a0 == v1(=0x15f42), and falls through when a0 != v1(=0x15f42).
  The `beq` branch at 0x3474 targets 0x34ac, is taken when a0 == a7(=0x15f43), and falls through when a0 != a7(=0x15f43).
  The `beq` branch at 0x347c targets 0x349c, is taken when a0 == t0(=0x20005c0), and falls through when a0 != t0(=0x20005c0).
  The `beq` branch at 0x3484 targets 0x349c, is taken when a0 == t2(=0x20005c1), and falls through when a0 != t2(=0x20005c1).
  The return at 0x3490 has v0 = sym(.rodata).
  The return at 0x349c has v0 = sym(.rodata).
  The return at 0x34a4 has v0 = sym(.rodata).
  The return at 0x34b0 has v0 = sym(.rodata).

- `ef_dump` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x34b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x34b8-0x3564 (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0x350c loads 8 bytes from ret(ifunit) +0x110.
  The `jal` at 0x34dc calls sprintf with a0=sp-144, a1=sym(.rodata), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x34e4 calls ifunit with a0=sp-144, a1=?, a2=?, a3=?.
  The `jal` at 0x34fc calls qprintf with a0=sym(.rodata), a1=sp-144, a2=?, a3=?.
  The `jal` at 0x3510 calls ef_dumpif with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x351c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3524 calls ef_dumpei with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3530 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3538 calls ef_dumpregs with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3544 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x354c calls ef_dumpphy with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x34ec targets 0x350c, is taken when v0(=ret(ifunit)) != 0, and falls through when v0(=ret(ifunit)) == 0.
  The `beq` branch at 0x3504 targets 0x3558 and is always taken.
  The return at 0x355c has v0 = one of ret(qprintf), ret(ef_dumpphy).

- `ef_dumpif` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x3564 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x3564-0x35f4 (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0x3564 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x3568 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x356c loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `lw` at 0x3570 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x3598 loads 4 bytes from a0 (arg0 at entry) +0xb0.
  The `lw` at 0x359c loads 4 bytes from a0 (arg0 at entry) +0xac.
  The `lw` at 0x35a0 loads 4 bytes from a0 (arg0 at entry) +0xa8.
  The `lh` at 0x35a4 loads 2 bytes from a0 (arg0 at entry) +0x1c.
  The `lw` at 0x35b0 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x35b4 loads 4 bytes from a0 (arg0 at entry) +0x3c.
  The `lw` at 0x35b8 loads 4 bytes from a0 (arg0 at entry) +0x38.
  The `lw` at 0x35bc loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x35c8 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `lw` at 0x35cc loads 4 bytes from a0 (arg0 at entry) +0x4c.
  The `lw` at 0x35d0 loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `lw` at 0x35d4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `jal` at 0x3590 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=[a0]:8, a3=[a0+26]:2, a4=[a0+40], a5=[a0+32].
  The `jal` at 0x35a8 calls qprintf with a0=sym(.rodata), a1=[a0+28]:2, a2=[a0+168], a3=[a0+172], a4=[a0+176].
  The `jal` at 0x35c0 calls qprintf with a0=sym(.rodata), a1=[a0+52], a2=[a0+56], a3=[a0+60], a4=[a0+64].
  The `jal` at 0x35d8 calls qprintf with a0=sym(.rodata), a1=[a0+68], a2=[a0+72], a3=[a0+76], a4=[a0+92].
  The return at 0x35ec has v0 = ret(qprintf).

- `ef_dumpei` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x35f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x35f4-0x373c (328 bytes).
  It occupies 328 bytes.
  The `lw` at 0x3620 loads 4 bytes from a0 (arg0 at entry) +0x3a0.
  The `lw` at 0x3630 loads 4 bytes from a0 (arg0 at entry) +0x3b0.
  The `lw` at 0x3638 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `lw` at 0x3644 loads 4 bytes from a0 (arg0 at entry) +0x3b8.
  The `lw` at 0x3648 loads 4 bytes from a0 (arg0 at entry) +0x358.
  The `ld` at 0x364c loads 8 bytes from a0 (arg0 at entry) +0x350.
  The `lw` at 0x3650 loads 4 bytes from a0 (arg0 at entry) +0x34c.
  The `lw` at 0x3654 loads 4 bytes from a0 (arg0 at entry) +0x348.
  The `ld` at 0x3658 loads 8 bytes from a0 (arg0 at entry) +0x338.
  The `ld` at 0x3664 loads 8 bytes from a0 (arg0 at entry) +0x380.
  The `ld` at 0x3668 loads 8 bytes from a0 (arg0 at entry) +0x378.
  The `lw` at 0x366c loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x3670 loads 4 bytes from a0 (arg0 at entry) +0x370.
  The `ld` at 0x3674 loads 8 bytes from a0 (arg0 at entry) +0x368.
  The `lw` at 0x3678 loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `lw` at 0x3684 loads 4 bytes from a0 (arg0 at entry) +0x3d0.
  The `lw` at 0x3688 loads 4 bytes from a0 (arg0 at entry) +0x3c4.
  The `lw` at 0x36a8 loads 4 bytes from a0 (arg0 at entry) +0x3e0.
  The `lw` at 0x36ac loads 4 bytes from a0 (arg0 at entry) +0x3dc.
  The `lw` at 0x36b0 loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  The `lw` at 0x36b4 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x36c0 loads 4 bytes from a0 (arg0 at entry) +0x3f0.
  The `lw` at 0x36c4 loads 4 bytes from a0 (arg0 at entry) +0x3f4.
  The `lw` at 0x36c8 loads 4 bytes from a0 (arg0 at entry) +0x3ec.
  The `lw` at 0x36cc loads 4 bytes from a0 (arg0 at entry) +0x3e8.
  The `lw` at 0x36d0 loads 4 bytes from a0 (arg0 at entry) +0x3e4.
  The `lw` at 0x36dc loads 4 bytes from a0 (arg0 at entry) +0x404.
  The `lw` at 0x36e0 loads 4 bytes from a0 (arg0 at entry) +0x400.
  The `lw` at 0x36e4 loads 4 bytes from a0 (arg0 at entry) +0x3fc.
  The `lw` at 0x36e8 loads 4 bytes from a0 (arg0 at entry) +0x3f8.
  The `lw` at 0x36f4 loads 4 bytes from a0 (arg0 at entry) +0x41c.
  The `lw` at 0x36f8 loads 4 bytes from a0 (arg0 at entry) +0x418.
  The `lw` at 0x36fc loads 4 bytes from a0 (arg0 at entry) +0x414.
  The `lw` at 0x3700 loads 4 bytes from a0 (arg0 at entry) +0x410.
  The `lw` at 0x3704 loads 4 bytes from a0 (arg0 at entry) +0x40c.
  The `lw` at 0x3708 loads 4 bytes from a0 (arg0 at entry) +0x408.
  The `lw` at 0x3714 loads 4 bytes from a0 (arg0 at entry) +0x428.
  The `lw` at 0x3718 loads 4 bytes from a0 (arg0 at entry) +0x424.
  The `lw` at 0x371c loads 4 bytes from a0 (arg0 at entry) +0x420.
  The `jal` at 0x3608 calls ether_sprintf with a0=a0+240, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3624 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=ret(ether_sprintf), a3=[a0+928], a4=a0+400.
  The `jal` at 0x362c calls ef_phystr with a0=[a0+944], a1=?, a2=?, a3=?.
  The `jal` at 0x3640 calls qprintf with a0=sym(.rodata), a1=[a0+948], a2=ret(ef_phystr), a3=[a0+952].
  The `jal` at 0x365c calls qprintf with a0=sym(.rodata), a1=[a0+824]:8, a2=[a0+840], a3=[a0+844], a4=[a0+848]:8, a5=[a0+856].
  The `jal` at 0x367c calls qprintf with a0=sym(.rodata), a1=[a0+864], a2=[a0+872]:8, a3=[a0+880], a4=[a0+884], a5=[a0+888]:8, a6=[a0+896]:8.
  The `jal` at 0x368c calls qprintf with a0=sym(.rodata), a1=[a0+964], a2=[a0+976], a3=?.
  The `jal` at 0x36a0 calls ef_hexdump with a0=sym(.rodata), a1=a0+956, a2=0x8, a3=?.
  The `jal` at 0x36b8 calls qprintf with a0=sym(.rodata), a1=[a0+968], a2=[a0+972], a3=[a0+988], a4=[a0+992].
  The `jal` at 0x36d4 calls qprintf with a0=sym(.rodata), a1=[a0+996], a2=[a0+1000], a3=[a0+1004], a4=[a0+1012], a5=[a0+1008].
  The `jal` at 0x36ec calls qprintf with a0=sym(.rodata), a1=[a0+1016], a2=[a0+1020], a3=[a0+1024], a4=[a0+1028].
  The `jal` at 0x370c calls qprintf with a0=sym(.rodata), a1=[a0+1032], a2=[a0+1036], a3=[a0+1040], a4=[a0+1044], a5=[a0+1048], a6=[a0+1052].
  The `jal` at 0x3720 calls qprintf with a0=sym(.rodata), a1=[a0+1056], a2=[a0+1060], a3=[a0+1064].
  The return at 0x3734 has v0 = ret(qprintf).

- `ef_dumpregs` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x373c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x373c-0x37fc (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0x3750 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x376c loads 4 bytes from [a0+816]:8 +0x0.
  The `lw` at 0x3770 loads 4 bytes from [a0+816]:8 +0x4.
  The `lw` at 0x3774 loads 4 bytes from [a0+816]:8 +0x8.
  The `lw` at 0x3780 loads 4 bytes from [a0+816]:8 +0xc.
  The `lw` at 0x3784 loads 4 bytes from [a0+816]:8 +0x14.
  The `lw` at 0x3788 loads 4 bytes from [a0+816]:8 +0x10.
  The `lw` at 0x378c loads 4 bytes from [a0+816]:8 +0x18.
  The `lw` at 0x3798 loads 4 bytes from [a0+816]:8 +0x1c.
  The `lw` at 0x379c loads 4 bytes from [a0+816]:8 +0x20.
  The `lw` at 0x37a0 loads 4 bytes from [a0+816]:8 +0x24.
  The `lw` at 0x37a4 loads 4 bytes from [a0+816]:8 +0x28.
  The `lw` at 0x37a8 loads 4 bytes from [a0+816]:8 +0x30.
  The `lw` at 0x37b4 loads 4 bytes from [a0+816]:8 +0x3c.
  The `lw` at 0x37b8 loads 4 bytes from [a0+816]:8 +0x38.
  The `lw` at 0x37bc loads 4 bytes from [a0+816]:8 +0x40.
  The `lw` at 0x37c0 loads 4 bytes from [a0+816]:8 +0x44.
  The `lw` at 0x37cc loads 4 bytes from [a0+816]:8 +0x34.
  The `lw` at 0x37d0 loads 4 bytes from [a0+816]:8 +0x4c.
  The `lw` at 0x37d4 loads 4 bytes from [a0+816]:8 +0x48.
  The `lw` at 0x37d8 loads 4 bytes from [a0+816]:8 +0x54.
  The `lw` at 0x37dc loads 4 bytes from [a0+816]:8 +0x50.
  The `jal` at 0x3758 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3764 calls qprintf with a0=sym(.rodata), a1=[a0+816]:8, a2=?, a3=?.
  The `jal` at 0x3778 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8], a2=[[a0+816]:8+4], a3=[[a0+816]:8+8].
  The `jal` at 0x3790 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+12], a2=[[a0+816]:8+20], a3=[[a0+816]:8+16], a4=[[a0+816]:8+24].
  The `jal` at 0x37ac calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+28], a2=[[a0+816]:8+32], a3=[[a0+816]:8+36], a4=[[a0+816]:8+40], a5=[[a0+816]:8+48].
  The `jal` at 0x37c4 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+60], a2=[[a0+816]:8+56], a3=[[a0+816]:8+64], a4=[[a0+816]:8+68].
  The `jal` at 0x37e0 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+52], a2=[[a0+816]:8+76], a3=[[a0+816]:8+72], a4=[[a0+816]:8+84], a5=[[a0+816]:8+80].
  The return at 0x37f4 has v0 = ret(qprintf).

- `ef_dumpphy` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x37fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x37fc-0x38a0 (164 bytes).
  It occupies 164 bytes.
  The `jal` at 0x3838 calls ef_phyget with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3848 calls qprintf with a0=sym(.rodata), a1=?, a2=ret(ef_phyget), a3=?.
  The `jal` at 0x3860 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x387c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3820 targets 0x3834 and is always taken.
  The `beq` branch at 0x3830 targets 0x3870, is taken when s0(?) >= 0x20 (signed), and falls through when s0(?) < 0x20 (signed).
  The `bne` branch at 0x3858 targets 0x3828, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `beq` branch at 0x3868 targets 0x3828 and is always taken.
  The `beq` branch at 0x3870 targets 0x3888, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The return at 0x3898 has v0 = one of ?, ret(qprintf).

- `ef_hexdump` in `IP30/usr/cpu/sysgen/IP30boot/if_ef.o` at 0x38a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/if_ef.o`.
  Range: 0x38a0-0x39a0 (256 bytes).
  It occupies 256 bytes.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x38e0, `lbu` at 0x38f4, `lbu` at 0x3964.
  2 such `lbu` accesses load 1 byte from table(sym(.data)) +0x28, including `lbu` at 0x38ec, `lbu` at 0x390c.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x38f0, `sb` at 0x3914, `sb` at 0x3920.
  The `jal` at 0x3978 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=sp-528, a3=?, a7=sp-528.
  The `blez` branch at 0x38cc targets 0x398c, is taken when t0(?) <= 0 (signed), and falls through when t0(?) > 0 (signed).
  The `beq` branch at 0x38d8 targets 0x3994 and is always taken.
  The `beq` branch at 0x391c targets 0x3968, is taken when a5(?) >= t0(?) (signed), and falls through when a5(?) < t0(?) (signed).
  The `bne` branch at 0x3940 targets 0x38e0, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x3948 targets 0x3960, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3958 targets 0x38e0 and is always taken.
  The `beq` branch at 0x3960 targets 0x38e4 and is always taken.
  The `beq` branch at 0x398c targets 0x396c and is always taken.
  The `beq` branch at 0x3998 targets 0x3928 and is always taken.
  The return at 0x3984 has v0 = ret(qprintf).
