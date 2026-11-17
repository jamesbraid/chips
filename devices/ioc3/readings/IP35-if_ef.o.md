# Readings: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`

One entry per routine, filed here from the reading batches by binary.

- `ef_txfree_len` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
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

- `ef_setstate` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x98-0xc4 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x98 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `lw` at 0xa0 loads 4 bytes from [a0+272]:8 +0x358.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x358, including `sw` at 0xa8, `sw` at 0xc0.
  The `beq` branch at 0x9c targets 0xb4, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0xac has v0 = ?.
  The return at 0xbc has v0 = ?.

- `ef_ps_register` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0xc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
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

- `if_efopen` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x168 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
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

- `ef_ifattach` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1e4-0x2d0 (236 bytes).
  It occupies 236 bytes.
  The `sh` at 0x1e4 stores 2 bytes to a0 (arg0 at entry) +0x1a.
  The `ld` at 0x200 loads 8 bytes from a0 (arg0 at entry) +0x3a8.
  The `ld` at 0x218 loads 8 bytes from (sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4)) +0x8.
  The `lw` at 0x21c loads 4 bytes from [(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8 +0x748.
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
  The `bne` branch at 0x230 targets 0x244, is taken when v0(=[[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1864]) < 0x7e (signed), and falls through when v0(=[[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1864]) >= 0x7e (signed).
  The `beq` branch at 0x238 targets 0x244, is taken when a6(=[sym(ef_delaydiv)]) == 0, and falls through when a6(=[sym(ef_delaydiv)]) != 0.
  The `beq` branch at 0x244 targets 0x26c, is taken when a5(=[a0+916]) == a0(=-0x1), and falls through when a5(=[a0+916]) != a0(=-0x1).
  The `beq` branch at 0x274 targets 0x280, is taken when (a3(=[sym(if_efdevflag)]) & 0x1000) == 0, and falls through when (a3(=[sym(if_efdevflag)]) & 0x1000) != 0.
  The return at 0x2c8 has v0 = ret(ef_ps_register).

- `if_efinit` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x2d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x2d0-0x2fc (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x2e8 calls pciio_driver_register with a0=0x10a9, a1=0x3, a2=sym(.rodata), a3=0x0.
  The return at 0x2f4 has v0 = ret(pciio_driver_register).

- `if_efattach` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x2fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
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

- `ef_detach` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x610 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
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

- `mactoh` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x688 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
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

- `ef_ioc3eaddr` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x738 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x738-0x94c (532 bytes).
  It occupies 532 bytes.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x38c, including `lw` at 0x758, `lw` at 0x8b0, `lw` at 0x8cc.
  2 such `ld` accesses load 8 bytes from abs 0x9000000014000000, including `ld` at 0x790, `ld` at 0x7cc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x398, including `ld` at 0x7a4, `ld` at 0x7ec.
  The `lbu` at 0x888 loads 1 byte from ?.
  The `sb` at 0x890 stores 1 byte to ?.
  The `jal` at 0x75c calls sprintf with a0=sp-192, a1=sym(.rodata), a2=[a0+908], a3=a3 at entry (arg3).
  The `jal` at 0x76c calls strstr with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x780 calls strstr with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x7b8 calls ibrick_mac_addr_get with a0=?, a1=sp-64, a2=0x4000, a3=?.
  The `jal` at 0x7dc calls mactoh with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x7f8 calls nic_get_eaddr with a0=[a0+920]:8+48, a1=[a0+920]:8+52, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x820 calls get_elsc with a0=sp-64, a1=0x9000000014000000, a2=0x4000, a3=?.
  The `jal` at 0x82c calls iobrick_get_sys_snum with a0=ret(get_elsc), a1=sp-48, a2=?, a3=?.
  The `jal` at 0x8b4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+908], a3=?.
  The `jal` at 0x8d0 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+908], a3=?.
  The `jal` at 0x8dc calls kopt_find with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x8f8 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+908], a3=?.
  The `jal` at 0x914 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+908], a3=?.
  The `jal` at 0x920 calls kopt_find with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x93c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+908], a3=?.
  The `beq` branch at 0x774 targets 0x7ec, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x788 targets 0x7ec, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x79c targets 0x7cc, is taken when a2(=0x4000) == a3(?), and falls through when a2(=0x4000) != a3(?).
  The `bne` branch at 0x7c4 targets 0x8c4, is taken when v0(=ret(ibrick_mac_addr_get)) != 0, and falls through when v0(=ret(ibrick_mac_addr_get)) == 0.
  The `beq` branch at 0x7d4 targets 0x820, is taken when a2(=0x4000) == a3(?), and falls through when a2(=0x4000) != a3(?).
  The `beq` branch at 0x7e4 targets 0x80c and is always taken.
  The `bne` branch at 0x800 targets 0x8ac, is taken when v0(=ret(nic_get_eaddr)) != 0, and falls through when v0(=ret(nic_get_eaddr)) == 0.
  The `bltz` branch at 0x834 targets 0x908, is taken when v0(=ret(iobrick_get_sys_snum)) < 0 (signed), and falls through when v0(=ret(iobrick_get_sys_snum)) >= 0 (signed).
  The `beq` branch at 0x854 targets 0x8a4, is taken when a2(?) == a3(=0x3a), and falls through when a2(?) != a3(=0x3a).
  The `beq` branch at 0x87c targets 0x894, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x894 targets 0x868, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x89c targets 0x7dc and is always taken.
  The `beq` branch at 0x8a4 targets 0x864 and is always taken.
  The `beq` branch at 0x8bc targets 0x80c and is always taken.
  The `bne` branch at 0x8e4 targets 0x7dc, is taken when v0(=ret(kopt_find)) != 0, and falls through when v0(=ret(kopt_find)) == 0.
  The `beq` branch at 0x900 targets 0x80c and is always taken.
  The `bne` branch at 0x928 targets 0x7dc, is taken when v0(=ret(kopt_find)) != 0, and falls through when v0(=ret(kopt_find)) == 0.
  The `beq` branch at 0x944 targets 0x80c and is always taken.
  The return at 0x818 has v0 = one of 0x0, 0x5.

- `ssram_discovery` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x94c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x94c-0x9c0 (116 bytes).
  It occupies 116 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x94c, `ld` at 0x99c.
  2 such `lw` accesses load 4 bytes from [a0+816]:8 +0x0, including `lw` at 0x950, `lw` at 0x9a4.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x0, including `sw` at 0x95c, `sw` at 0x9ac.
  The `sw` at 0x968 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x970 stores 4 bytes to a1 (arg1 at entry) +0x20000.
  The `lw` at 0x974 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x98c loads 4 bytes from a1 (arg1 at entry) +0x20000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3d0, including `sw` at 0x9a0, `sw` at 0x9bc.
  The `bne` branch at 0x984 targets 0x99c, is taken when at(=0x5555) != v0(?), and falls through when at(=0x5555) == v0(?).
  The `beq` branch at 0x994 targets 0x9b8, is taken when a4(=0xaaaa) == a5(?), and falls through when a4(=0xaaaa) != a5(?).
  The return at 0x9b0 has v0 = ?.
  The return at 0x9b8 has v0 = ?.

- `ef_allocef` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x9c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x9c0-0xa7c (188 bytes).
  It occupies 188 bytes.
  The `ld` at 0x9c0 loads 8 bytes from a0 (arg0 at entry) +0x338.
  The `sd` at 0xa1c stores 8 bytes to a0 (arg0 at entry) +0x338.
  The `sd` at 0xa24 stores 8 bytes to a0 (arg0 at entry) +0x350.
  The `sd` at 0xa50 stores 8 bytes to a0 (arg0 at entry) +0x368.
  The `sd` at 0xa60 stores 8 bytes to a0 (arg0 at entry) +0x380.
  The `jal` at 0x9f4 calls contig_memalloc with a0=0x4, a1=0x4, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0xa18 calls kmem_zalloc with a0=0x1000, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa30 calls contig_memalloc with a0=0x1, a1=0x1, a2=0x100, a3=?.
  The `jal` at 0xa54 calls kmem_zalloc with a0=0x1000, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa6c calls ef_deallocef with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x9d4 targets 0x9ec, is taken when at(=[a0+824]:8) == 0, and falls through when at(=[a0+824]:8) != 0.
  The `beq` branch at 0x9fc targets 0xa6c, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0xa20 targets 0xa6c, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0xa38 targets 0xa6c, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0xa5c targets 0xa6c, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0xa64 targets 0x9dc and is always taken.
  The `beq` branch at 0xa74 targets 0x9dc and is always taken.
  The return at 0x9e4 has v0 = one of 0x0, 0xc.

- `ef_deallocef` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0xa7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0xa7c-0xac0 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0xa7c loads 8 bytes from a0 (arg0 at entry) +0x350.
  The `ld` at 0xaa0 loads 8 bytes from a0 (arg0 at entry) +0x380.
  The `jal` at 0xa94 calls kmem_free with a0=[a0+848]:8, a1=0x1000, a2=a2 at entry (arg2), a3=[a0+848]:8.
  The `jal` at 0xaac calls kmem_free with a0=[a0+896]:8, a1=0x1000, a2=?, a3=?.
  The `beq` branch at 0xa88 targets 0xa9c, is taken when a3(=[a0+848]:8) == 0, and falls through when a3(=[a0+848]:8) != 0.
  The `beq` branch at 0xaa4 targets 0xab8, is taken when a0(=[a0+896]:8) == 0, and falls through when a0(=[a0+896]:8) != 0.
  The return at 0xab8 has v0 = one of ?, ret(kmem_free).

- `ef_reclaim` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0xac0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0xac0-0xb44 (132 bytes).
  It occupies 132 bytes.
  The `ld` at 0xac0 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0xac4 loads 4 bytes from [a0+816]:8 +0x40.
  The `lw` at 0xacc loads 4 bytes from a0 (arg0 at entry) +0x34c.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xaec, `sd` at 0xb04, `sd` at 0xb18.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x350, including `ld` at 0xaf0, `ld` at 0xb08, `ld` at 0xb1c.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xaf8, `ld` at 0xb14, `ld` at 0xb30.
  The `sw` at 0xb40 stores 4 bytes to a0 (arg0 at entry) +0x34c.
  The `beq` branch at 0xad8 targets 0xb3c, is taken when a4(=[a0+844]) == t0(?), and falls through when a4(=[a0+844]) != t0(?).
  The `beq` branch at 0xae4 targets 0xb08 and is always taken.
  The `beq` branch at 0xb00 targets 0xb3c, is taken when a4(?) == t0(?), and falls through when a4(?) != t0(?).
  The `bne` branch at 0xb2c targets 0xaec, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xb34 targets 0xafc and is always taken.
  The return at 0xb3c has v0 = one of 0x0, ?.

- `ef_xinit` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0xb44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0xb44-0xba8 (100 bytes).
  It occupies 100 bytes.
  The `ld` at 0xb54 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `jal` at 0xb64 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb78 calls ef_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0xb8c calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The return at 0xba0 has v0 = ret(ef_init).

- `ef_init` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0xba8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0xba8-0xd64 (444 bytes).
  It occupies 444 bytes.
  The `ld` at 0xbb0 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `sw` at 0xbd4 stores 4 bytes to [a0+272]:8 +0x388.
  The `ld` at 0xbe0 loads 8 bytes from [a0+272]:8 +0x338.
  The `ld` at 0xbe4 loads 8 bytes from [a0+272]:8 +0x368.
  The `sw` at 0xbe8 stores 4 bytes to [a0+272]:8 +0x348.
  The `sw` at 0xbf4 stores 4 bytes to [a0+272]:8 +0x34c.
  The `sw` at 0xbf8 stores 4 bytes to [a0+272]:8 +0x374.
  The `sw` at 0xc04 stores 4 bytes to [a0+272]:8 +0x370.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc4c, `ld` at 0xd04, `ld` at 0xd1c.
  The `lh` at 0xc7c loads 2 bytes from [a0+272]:8 +0x1a.
  The `lw` at 0xc90 loads 4 bytes from [a0+272]:8 +0x3a0.
  The `lw` at 0xc94 loads 4 bytes from [a0+272]:8 +0x358.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x358, including `sw` at 0xcb4, `sw` at 0xd60.
  The `lw` at 0xcc0 loads 4 bytes from [a0+272]:8 +0x20.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x20, including `sw` at 0xcc8, `sw` at 0xd50.
  The `lwu` at 0xcd8 loads 4 bytes from [a0+272]:8 +0x374.
  2 such `ld` accesses load 8 bytes from [a0+272]:8 +0x330, including `ld` at 0xcdc, `ld` at 0xd30.
  The `sw` at 0xcec stores 4 bytes to [[a0+272]:8+816]:8 +0x20.
  The `lw` at 0xcf0 loads 4 bytes from [a0+272]:8 +0x370.
  The `ld` at 0xcf4 loads 8 bytes from [a0+272]:8 +0x380.
  2 such `sd` accesses store 8 bytes to [a0+272]:8 +0x378, including `sd` at 0xd28, `sd` at 0xd2c.
  The `lw` at 0xd34 loads 4 bytes from [[a0+272]:8+816]:8 +0x0.
  The `sw` at 0xd3c stores 4 bytes to [[a0+272]:8+816]:8 +0x0.
  The `sh` at 0xd44 stores 2 bytes to [a0+272]:8 +0x1c.
  The `jal` at 0xbc8 calls ef_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbdc calls bzero with a0=[[a0+272]:8+824]:8, a1=0x10000, a2=?, a3=?.
  The `jal` at 0xbf0 calls bzero with a0=[[a0+272]:8+872]:8, a1=0x1000, a2=?, a3=?.
  The `jal` at 0xc08 calls ef_ioc3init with a0=[a0+272]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xc30 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xc48 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc60 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0xc88 calls ef_ps_register with a0=[a0+272]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0xccc calls ef_fill with a0=[a0+272]:8, a1=[[a0+272]:8+32], a2=[[a0+272]:8+928], a3=-0x4.
  The `beq` branch at 0xc1c targets 0xc7c, is taken when v0(=ret(ef_ioc3init)) == 0, and falls through when v0(=ret(ef_ioc3init)) != 0.
  The `beq` branch at 0xc3c targets 0xc58, is taken when s0(=ret(ef_reset)) == 0, and falls through when s0(=ret(ef_reset)) != 0.
  The `bne` branch at 0xc50 targets 0xc48, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xc80 targets 0xc90, is taken when a0(=[[a0+272]:8+26]:2) == a1(=-0x1), and falls through when a0(=[[a0+272]:8+26]:2) != a1(=-0x1).
  The `blez` branch at 0xcb0 targets 0xd54, is taken when a2(=[[a0+272]:8+928]) <= 0 (signed), and falls through when a2(=[[a0+272]:8+928]) > 0 (signed).
  The `beq` branch at 0xcbc targets 0xd48, is taken when (a0(?) & 0x2) == 0, and falls through when (a0(?) & 0x2) != 0.
  The `beq` branch at 0xd14 targets 0xd2c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xd24 targets 0xd30 and is always taken.
  The `beq` branch at 0xd40 targets 0xc24 and is always taken.
  The `beq` branch at 0xd4c targets 0xccc and is always taken.
  The `beq` branch at 0xd5c targets 0xcb8 and is always taken.
  The return at 0xc74 has v0 = ret(ef_ioc3init).

- `ef_ioc3init` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0xd64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0xd64-0x1028 (708 bytes).
  It occupies 708 bytes.
  The `ld` at 0xd84 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0xdc0 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x360, including `sw` at 0xde0, `sw` at 0xdec, `sw` at 0xfb4.
  The `lw` at 0xde4 loads 4 bytes from a0 (arg0 at entry) +0x30.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0xdfc, `sw` at 0xfc8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3cc, including `lw` at 0xe00, `lw` at 0xf34.
  The `lw` at 0xe0c loads 4 bytes from a0 (arg0 at entry) +0x20.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0xe18, `sw` at 0xf7c.
  The `lw` at 0xe1c loads 4 bytes from sym(ef_fullduplex_ipg) +0x8.
  The `lw` at 0xe20 loads 4 bytes from sym(ef_fullduplex_ipg) +0x4.
  The `lw` at 0xe28 loads 4 bytes from sym(ef_fullduplex_ipg) +0x0.
  The `sw` at 0xe40 stores 4 bytes to [a0+816]:8 +0x28.
  The `sw` at 0xe48 stores 4 bytes to [a0+816]:8 +0x2c.
  The `sw` at 0xe50 stores 4 bytes to [a0+816]:8 +0x18.
  The `lw` at 0xe58 loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `sw` at 0xe68 stores 4 bytes to [a0+816]:8 +0xc.
  The `sw` at 0xe6c stores 4 bytes to [a0+816]:8 +0x24.
  The `lbu` at 0xe70 loads 1 byte from a0 (arg0 at entry) +0xf1.
  The `lbu` at 0xe74 loads 1 byte from a0 (arg0 at entry) +0xf3.
  The `lbu` at 0xe78 loads 1 byte from a0 (arg0 at entry) +0xf2.
  The `lbu` at 0xe80 loads 1 byte from a0 (arg0 at entry) +0xf0.
  The `sw` at 0xe9c stores 4 bytes to [a0+816]:8 +0x4c.
  The `lbu` at 0xea0 loads 1 byte from a0 (arg0 at entry) +0xf5.
  The `lbu` at 0xeac loads 1 byte from a0 (arg0 at entry) +0xf4.
  The `sw` at 0xec0 stores 4 bytes to [a0+816]:8 +0x48.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x54, including `sw` at 0xec4, `sw` at 0xff4.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x50, including `sw` at 0xec8, `sw` at 0x1024.
  The `ld` at 0xed0 loads 8 bytes from a0 (arg0 at entry) +0x368.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x38c, including `lw` at 0xee0, `lw` at 0xf0c.
  The `sw` at 0xeec stores 4 bytes to [a0+816]:8 +0x14.
  The `sw` at 0xef4 stores 4 bytes to [a0+816]:8 +0x10.
  The `ld` at 0xefc loads 8 bytes from a0 (arg0 at entry) +0x338.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x3c, including `sw` at 0xf18, `sw` at 0xf30.
  The `sw` at 0xf20 stores 4 bytes to [a0+816]:8 +0x38.
  The `lw` at 0xf24 loads 4 bytes from [a0+816]:8 +0x3c.
  The `lw` at 0xf44 loads 4 bytes from a0 (arg0 at entry) +0x3d0.
  The `sw` at 0xf54 stores 4 bytes to [a0+816]:8 +0x0.
  The `sw` at 0xf60 stores 4 bytes to [a0+816]:8 +0x8.
  The `lw` at 0xf84 loads 4 bytes from sym(ef_halfduplex_ipg) +0x4.
  The `lw` at 0xf88 loads 4 bytes from sym(ef_halfduplex_ipg) +0x8.
  The `lw` at 0xf90 loads 4 bytes from sym(ef_halfduplex_ipg) +0x0.
  The `lbu` at 0xfcc loads 1 byte from a0 (arg0 at entry) +0x3bd.
  The `lbu` at 0xfd0 loads 1 byte from a0 (arg0 at entry) +0x3be.
  The `lbu` at 0xfd8 loads 1 byte from a0 (arg0 at entry) +0x3bf.
  The `lbu` at 0xfe0 loads 1 byte from a0 (arg0 at entry) +0x3bc.
  The `lbu` at 0xff8 loads 1 byte from a0 (arg0 at entry) +0x3c1.
  The `lbu` at 0xffc loads 1 byte from a0 (arg0 at entry) +0x3c2.
  The `lbu` at 0x1004 loads 1 byte from a0 (arg0 at entry) +0x3c3.
  The `lbu` at 0x100c loads 1 byte from a0 (arg0 at entry) +0x3c0.
  The `jal` at 0xd80 calls ef_phyinit with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xda4 calls ef_phyerr with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xe3c calls microtime with a0=sp-64, a1=0xfffffffff0000000, a2=?, a3=?, a5=0x10000, a6=sym(ef_fullduplex_ipg).
  The `jal` at 0xecc calls kvtophys with a0=[a0+872]:8, a1=?, a2=?, a3=?, a4=([a0+244]:1 | ([a0+245]:1 << 0x8)), a6=([a0+245]:1 << 0x8).
  The `jal` at 0xee4 calls pciio_dmatrans_addr with a0=[a0+908], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x50.
  The `jal` at 0xef8 calls kvtophys with a0=[a0+824]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xf10 calls pciio_dmatrans_addr with a0=[a0+908], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x50.
  The `jal` at 0xf5c calls flushbus with a0=?, a1=?, a2=?, a3=?, a4=([[a0+816]:8+60] | 0x1), a6=0x7fe003f.
  The `beq` branch at 0xd88 targets 0xda4, is taken when v0(=ret(ef_phyinit)) == 0, and falls through when v0(=ret(ef_phyinit)) != 0.
  The `beq` branch at 0xdd4 targets 0xfa4, is taken when (at(=a1) & 0x100) == 0, and falls through when (at(=a1) & 0x100) != 0.
  The `beq` branch at 0xdf0 targets 0xfb8, is taken when v0(=[a0+968]) == 0, and falls through when v0(=[a0+968]) != 0.
  The `beq` branch at 0xe08 targets 0xf6c, is taken when a0(=[a0+972]) == 0, and falls through when a0(=[a0+972]) != 0.
  The `beq` branch at 0xe14 targets 0xf80, is taken when a0(=[a0+972]) == 0, and falls through when a0(=[a0+972]) != 0.
  The `beq` branch at 0xebc targets 0xfcc, is taken when (a5(=a1) & 0x200) == 0, and falls through when (a5(=a1) & 0x200) != 0.
  The `beq` branch at 0xf38 targets 0xf44, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xf64 targets 0xd90 and is always taken.
  The `bne` branch at 0xf78 targets 0xe1c, is taken when a0(=[a0+972]) != 0, and falls through when a0(=[a0+972]) == 0.
  The `beq` branch at 0xf9c targets 0xe38 and is always taken.
  The `beq` branch at 0xfb0 targets 0xde4 and is always taken.
  The `beq` branch at 0xfc4 targets 0xe00 and is always taken.
  The `beq` branch at 0x1020 targets 0xecc and is always taken.
  The return at 0xd9c has v0 = one of ret(ef_phyinit), 0x0.

- `ef_phyunreset` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1028 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1028-0x1098 (112 bytes).
  It occupies 112 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x398, including `ld` at 0x1028, `ld` at 0x1034, `ld` at 0x104c.
  2 such `sw` accesses store 4 bytes to [a0+920]:8 +0x54, including `sw` at 0x102c, `sw` at 0x1070.
  2 such `lw` accesses load 4 bytes from [a0+920]:8 +0x54, including `lw` at 0x103c, `lw` at 0x1078.
  The `sw` at 0x1048 stores 4 bytes to [a0+920]:8 +0x34.
  The `lw` at 0x1058 loads 4 bytes from [a0+920]:8 +0x34.
  The `jal` at 0x1060 calls us_delay with a0=0xa, a1=[[a0+920]:8+84], a2=[a0+920]:8, a3=a3 at entry (arg3).
  The `jal` at 0x1080 calls us_delay with a0=0x1f4, a1=?, a2=?, a3=[[a0+920]:8+84], a4=0x1, a5=[a0+920]:8.
  The return at 0x1090 has v0 = ret(us_delay).

- `ef_phyprobe` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1098 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1098-0x11cc (308 bytes).
  It occupies 308 bytes.
  The `lw` at 0x10b8 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `lw` at 0x10d4 loads 4 bytes from a0 (arg0 at entry) +0x3b0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3b4, including `sw` at 0x114c, `sw` at 0x11b8.
  The `sw` at 0x11a0 stores 4 bytes to a0 (arg0 at entry) +0x3b8.
  The `sw` at 0x11a8 stores 4 bytes to a0 (arg0 at entry) +0x3b0.
  The `lh` at 0x11ac loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `jal` at 0x1148 calls ef_phyget with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0x1158 calls ef_phyget with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x11bc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=-0x1, a4=(ret(ef_phyget) << 0xc).
  The `beq` branch at 0x10cc targets 0x110c, is taken when at(=[a0+948]) == v0(=-0x1), and falls through when at(=[a0+948]) != v0(=-0x1).
  The `beq` branch at 0x1130 targets 0x1140 and is always taken.
  The `beq` branch at 0x1138 targets 0x11ac, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1170 targets 0x119c, is taken when a3(?) == s3(=0x15f41), and falls through when a3(?) != s3(=0x15f41).
  The `beq` branch at 0x1178 targets 0x11a0, is taken when a3(?) == s4(=0x15f42), and falls through when a3(?) != s4(=0x15f42).
  The `beq` branch at 0x1180 targets 0x11a0, is taken when a3(?) == s5(=0x15f43), and falls through when a3(?) != s5(=0x15f43).
  The `beq` branch at 0x1188 targets 0x11a0, is taken when a3(?) == s6(=0x181441), and falls through when a3(?) != s6(=0x181441).
  The `beq` branch at 0x1190 targets 0x11a0, is taken when a3(?) == s7(=0x20005c0), and falls through when a3(?) != s7(=0x20005c0).
  The `bne` branch at 0x1198 targets 0x1138, is taken when a3(?) != s8(=0x20005c1), and falls through when a3(?) == s8(=0x20005c1).
  The `beq` branch at 0x11a4 targets 0x10d8 and is always taken.
  The `beq` branch at 0x11c4 targets 0x10d8 and is always taken.
  The return at 0x1104 has v0 = one of [a0+944], ?, -0x1.

- `ef_phymode` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x11cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x11cc-0x14b0 (740 bytes).
  It occupies 740 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3b0, including `lw` at 0x1238, `lw` at 0x1348.
  13 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x12b8, `sw` at 0x12f4, `sw` at 0x1334.
  13 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x12c0, `sw` at 0x12f8, `sw` at 0x133c.
  The `jal` at 0x11f0 calls ef_phyget with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1200 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x1210 calls ef_phyget with a0=a0 at entry (arg0), a1=0x6, a2=?, a3=?.
  The `jal` at 0x1280 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1f, a2=0x20005c1, a3=0x15f41, a4=0x15f42, a5=0x15f43, a6=0x181441.
  The `jal` at 0x12c4 calls ef_phyget with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0x12d4 calls ef_phyget with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x1320 calls ef_phyget with a0=a0 at entry (arg0), a1=0x11, a2=0x20005c1, a3=0x15f41, a4=0x15f42.
  The `jal` at 0x135c calls ef_phyget with a0=a0 at entry (arg0), a1=0x11, a2=?, a3=?.
  The `jal` at 0x13b4 calls ef_phyget with a0=a0 at entry (arg0), a1=0x19, a2=0x20005c1, a3=?.
  The `jal` at 0x13f4 calls ef_phyget with a0=a0 at entry (arg0), a1=0x10, a2=0x20005c1, a3=?.
  The `jal` at 0x140c calls ef_phyget with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `jal` at 0x1490 calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0xefff, a3=?.
  The `jal` at 0x14a0 calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0x1000, a3=?.
  The `beq` branch at 0x121c targets 0x13d0, is taken when (s3(=ret(ef_phyget)) & 0x1000) == 0, and falls through when (s3(=ret(ef_phyget)) & 0x1000) != 0.
  The `beq` branch at 0x1228 targets 0x1348, is taken when (v1(=ret(ef_phyget)) & 0x20) == 0, and falls through when (v1(=ret(ef_phyget)) & 0x20) != 0.
  The `bne` branch at 0x1230 targets 0x12c4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x1244 targets 0x13b0, is taken when v0(=[a0+944]) == a1(=0x20005c0), and falls through when v0(=[a0+944]) != a1(=0x20005c0).
  The `beq` branch at 0x124c targets 0x13f0, is taken when v0(=[a0+944]) == a2(=0x20005c1), and falls through when v0(=[a0+944]) != a2(=0x20005c1).
  The `beq` branch at 0x1258 targets 0x131c, is taken when v0(=[a0+944]) == a3(=0x15f41), and falls through when v0(=[a0+944]) != a3(=0x15f41).
  The `beq` branch at 0x1260 targets 0x131c, is taken when v0(=[a0+944]) == a4(=0x15f42), and falls through when v0(=[a0+944]) != a4(=0x15f42).
  The `beq` branch at 0x1268 targets 0x1320, is taken when v0(=[a0+944]) == a5(=0x15f43), and falls through when v0(=[a0+944]) != a5(=0x15f43).
  The `bne` branch at 0x1278 targets 0x1340, is taken when v0(=[a0+944]) != a6(=0x181441), and falls through when v0(=[a0+944]) == a6(=0x181441).
  The `beq` branch at 0x1298 targets 0x1464, is taken when a0(?) == a7(=0x4), and falls through when a0(?) != a7(=0x4).
  The `beq` branch at 0x12a0 targets 0x1470, is taken when a0(?) == a2(=0x8), and falls through when a0(?) != a2(=0x8).
  The `beq` branch at 0x12a8 targets 0x147c, is taken when a0(?) == a4(=0x14), and falls through when a0(?) != a4(=0x14).
  The `bne` branch at 0x12b0 targets 0x1340, is taken when a0(?) != a5(=0x18), and falls through when a0(?) == a5(=0x18).
  The `beq` branch at 0x12bc targets 0x1340 and is always taken.
  The `beq` branch at 0x12e0 targets 0x1388, is taken when (s3(=ret(ef_phyget)) & 0x100) == 0, and falls through when (s3(=ret(ef_phyget)) & 0x100) != 0.
  The `beq` branch at 0x12e8 targets 0x138c, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x1340 targets 0x1300 and is always taken.
  The `bne` branch at 0x1354 targets 0x1374, is taken when ra(=[a0+944]) != at(=0x15f42), and falls through when ra(=[a0+944]) == at(=0x15f42).
  The `beq` branch at 0x136c targets 0x148c, is taken when v0(?) == v1(=0x1000), and falls through when v0(?) != v1(=0x1000).
  The `beq` branch at 0x1380 targets 0x1300 and is always taken.
  The `beq` branch at 0x138c targets 0x1424, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1398 targets 0x1424, is taken when (v0(=ret(ef_phyget)) & 0x80) == 0, and falls through when (v0(=ret(ef_phyget)) & 0x80) != 0.
  The `beq` branch at 0x13a8 targets 0x12fc and is always taken.
  The `beq` branch at 0x13c8 targets 0x1340 and is always taken.
  The `beq` branch at 0x13e8 targets 0x1300 and is always taken.
  The `beq` branch at 0x1418 targets 0x1340 and is always taken.
  The `beq` branch at 0x1428 targets 0x1444, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1430 targets 0x1448, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x143c targets 0x12fc and is always taken.
  The `beq` branch at 0x1448 targets 0x12fc, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x1450 targets 0x1300, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x145c targets 0x12fc and is always taken.
  The `beq` branch at 0x1468 targets 0x1340 and is always taken.
  The `beq` branch at 0x1474 targets 0x1340 and is always taken.
  The `beq` branch at 0x1484 targets 0x1340 and is always taken.
  The `beq` branch at 0x14a8 targets 0x1378 and is always taken.
  The return at 0x1314 has v0 = one of 0x0, 0x10.
  The instructions from 0x1420 to 0x1420 are not reached by any path from the entry, and their branches are not listed.

- `ef_phyreset` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x14b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x14b0-0x14e8 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0x14b8 calls ef_phyprobe with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14cc calls ef_phyerrat with a0=a0 at entry (arg0), a1=?, a2=?, a3=-0x1.
  The `beq` branch at 0x14c4 targets 0x14d8, is taken when v0(=ret(ef_phyprobe)) == at(=-0x1), and falls through when v0(=ret(ef_phyprobe)) != at(=-0x1).
  The return at 0x14e0 has v0 = one of -0x1, 0x0.

- `ef_phyinit` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x14e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x14e8-0x1638 (336 bytes).
  It occupies 336 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0x14e8, `lh` at 0x1594.
  The `lw` at 0x1558 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x1568 loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x1574, `lw` at 0x15ac.
  The `sw` at 0x15e0 stores 4 bytes to a0 (arg0 at entry) +0x3c8.
  The `sw` at 0x15ec stores 4 bytes to a0 (arg0 at entry) +0x3cc.
  The `jal` at 0x14fc calls ef_phyreset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x152c calls ef_phymode with a0=a0 at entry (arg0), a1=a0+968, a2=a0+972, a3=?.
  The `jal` at 0x1540 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0x154c calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x159c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=one of 0xa, 0x64, a3=sym(.rodata).
  The `jal` at 0x15c4 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a6=[a0+968].
  The `jal` at 0x15d4 calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0x1000, a3=?.
  The `jal` at 0x15fc calls us_delay with a0=0x64, a1=?, a2=?, a3=?.
  The `jal` at 0x161c calls ef_phymode with a0=a0 at entry (arg0), a1=a0+968, a2=a0+972, a3=?.
  The `beq` branch at 0x1504 targets 0x1520, is taken when v0(=ret(ef_phyreset)) == 0, and falls through when v0(=ret(ef_phyreset)) != 0.
  The `beq` branch at 0x1538 targets 0x15f8, is taken when v0(=ret(ef_phymode)) == a0(=0x10), and falls through when v0(=ret(ef_phymode)) != a0(=0x10).
  The `beq` branch at 0x1560 targets 0x15ac, is taken when a6(=[a0+968]) == a1(=-0x1), and falls through when a6(=[a0+968]) != a1(=-0x1).
  The `beq` branch at 0x156c targets 0x15ac, is taken when a0(=[a0+972]) == a1(=-0x1), and falls through when a0(=[a0+972]) != a1(=-0x1).
  The `beq` branch at 0x157c targets 0x15a4, is taken when (v0(=[a0+32]) & 0x4) == 0, and falls through when (v0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1584 targets 0x15f0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x15a4 targets 0x1510 and is always taken.
  The `beq` branch at 0x15b4 targets 0x15d0, is taken when (a0(=[a0+32]) & 0x4) == 0, and falls through when (a0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x15e8 targets 0x1574 and is always taken.
  The `beq` branch at 0x15f0 targets 0x158c and is always taken.
  The `bltz` branch at 0x160c targets 0x1540, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `beq` branch at 0x1628 targets 0x15fc, is taken when v0(=ret(ef_phymode)) == a3(=0x10), and falls through when v0(=ret(ef_phymode)) != a3(=0x10).
  The `beq` branch at 0x1630 targets 0x1540 and is always taken.
  The return at 0x1518 has v0 = one of 0x0, 0x5.

- `ef_phyupdate` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1638 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1638-0x169c (100 bytes).
  It occupies 100 bytes.
  The `lw` at 0x1660 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x166c loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  The `lw` at 0x1684 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x1650 calls ef_phymode with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=a3 at entry (arg3).
  The `jal` at 0x168c calls ef_init with a0=a0 at entry (arg0), a1=[a0+32], a2=a1 at entry (arg1), a3=?.
  The `bne` branch at 0x1658 targets 0x1674, is taken when v0(=ret(ef_phymode)) != 0, and falls through when v0(=ret(ef_phymode)) == 0.
  The `bne` branch at 0x1664 targets 0x1684, is taken when at(=[a0+968]) != v0(?), and falls through when at(=[a0+968]) == v0(?).
  The `bne` branch at 0x1670 targets 0x1684, is taken when v1(=[a0+972]) != a0(?), and falls through when v1(=[a0+972]) == a0(?).
  The `beq` branch at 0x1694 targets 0x1678 and is always taken.
  The return at 0x167c has v0 = one of ?, ret(ef_init).

- `ef_phyerr` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x169c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x169c-0x1878 (476 bytes).
  It occupies 476 bytes.
  The `lh` at 0x16a4 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x16d0 loads 4 bytes from a0 (arg0 at entry) +0x3dc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3dc, including `sw` at 0x16dc, `sw` at 0x178c.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x358, including `lw` at 0x16ec, `lw` at 0x1724, `lw` at 0x1800.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3e0, including `lw` at 0x16fc, `lw` at 0x17ac.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x1708, `lw` at 0x176c, `lw` at 0x17f4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3e0, including `sw` at 0x1728, `sw` at 0x17bc.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x358, including `sw` at 0x1748, `sw` at 0x179c, `sw` at 0x181c.
  The `lw` at 0x17a0 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0x1810, `sw` at 0x1854.
  The `jal` at 0x16bc calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x171c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x1780 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x17cc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x17e8 calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x1818 calls ef_phyupdate with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=[a0+856], a5=0xfffffffffff7ffff.
  The `jal` at 0x1838 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x1864 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=[a0+968], a4=[a0+992], a5=0x1.
  The `beq` branch at 0x16cc targets 0x1764, is taken when (v0(=ret(ef_phyget)) & 0x10) == 0, and falls through when (v0(=ret(ef_phyget)) & 0x10) != 0.
  The `beq` branch at 0x16d4 targets 0x17c0, is taken when a0(=[a0+988]) == 0, and falls through when a0(=[a0+988]) != 0.
  The `beq` branch at 0x16e4 targets 0x16fc, is taken when (s2(=ret(ef_phyget)) & 0x2) == 0, and falls through when (s2(=ret(ef_phyget)) & 0x2) != 0.
  The `beq` branch at 0x16f4 targets 0x17a0, is taken when (a0(=[a0+856]) & 0x4) == 0, and falls through when (a0(=[a0+856]) & 0x4) != 0.
  The `beq` branch at 0x1700 targets 0x1724, is taken when a0(=[a0+992]) == 0, and falls through when a0(=[a0+992]) != 0.
  The `beq` branch at 0x1710 targets 0x1724, is taken when (a1(=[a0+32]) & 0x4) == 0, and falls through when (a1(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1734 targets 0x1790, is taken when (s2(=ret(ef_phyget)) & 0x4) == 0, and falls through when (s2(=ret(ef_phyget)) & 0x4) != 0.
  The `bne` branch at 0x173c targets 0x17dc, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x1764 targets 0x1788, is taken when a0(=[a0+988]) == 0, and falls through when a0(=[a0+988]) != 0.
  The `beq` branch at 0x1774 targets 0x1788, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1788 targets 0x16e0 and is always taken.
  The `beq` branch at 0x1790 targets 0x182c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1798 targets 0x174c and is always taken.
  The `bne` branch at 0x17a4 targets 0x16fc, is taken when a3(=[a0+968]) != 0, and falls through when a3(=[a0+968]) == 0.
  The `beq` branch at 0x17b0 targets 0x1858, is taken when a4(=[a0+992]) == 0, and falls through when a4(=[a0+992]) != 0.
  The `beq` branch at 0x17b8 targets 0x1730 and is always taken.
  The `beq` branch at 0x17d4 targets 0x16dc and is always taken.
  The `beq` branch at 0x1824 targets 0x1744 and is always taken.
  The `beq` branch at 0x1850 targets 0x1794 and is always taken.
  The `beq` branch at 0x1870 targets 0x17b4 and is always taken.
  The return at 0x175c has v0 = one of -0x5, ?.

- `ef_phyget` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1878 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1878-0x1910 (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x1880 loads 8 bytes from a0 (arg0 at entry) +0x330.
  4 such `lw` accesses load 4 bytes from [a0+816]:8 +0x58, including `lw` at 0x1884, `lw` at 0x18a8, `lw` at 0x18cc.
  The `lw` at 0x18b8 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `sw` at 0x18c8 stores 4 bytes to [a0+816]:8 +0x58.
  The `lw` at 0x18fc loads 4 bytes from [a0+816]:8 +0x5c.
  The `jal` at 0x18a0 calls us_delaybus with a0=0x1, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x18dc calls us_delaybus with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1898 targets 0x18b8, is taken when (at(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (at(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x18b0 targets 0x18a0, is taken when (v0(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (v0(=[[a0+816]:8+88]) & 0x800) == 0.
  The `beq` branch at 0x18d4 targets 0x18f8, is taken when (v1(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (v1(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x18ec targets 0x18dc, is taken when (a1(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (a1(=[[a0+816]:8+88]) & 0x800) == 0.
  The return at 0x1908 has v0 = ?.

- `ef_phyput` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1910 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1910-0x19a8 (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x1918 loads 8 bytes from a0 (arg0 at entry) +0x330.
  4 such `lw` accesses load 4 bytes from [a0+816]:8 +0x58, including `lw` at 0x191c, `lw` at 0x1944, `lw` at 0x196c.
  The `sw` at 0x1958 stores 4 bytes to [a0+816]:8 +0x60.
  The `lw` at 0x195c loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `sw` at 0x1968 stores 4 bytes to [a0+816]:8 +0x58.
  The `jal` at 0x193c calls us_delaybus with a0=0x1, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x197c calls us_delaybus with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1934 targets 0x1958, is taken when (at(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (at(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x194c targets 0x193c, is taken when (v0(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (v0(=[[a0+816]:8+88]) & 0x800) == 0.
  The `beq` branch at 0x1974 targets 0x1998, is taken when (v1(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (v1(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x198c targets 0x197c, is taken when (a1(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (a1(=[[a0+816]:8+88]) & 0x800) == 0.
  The return at 0x19a0 has v0 = one of ?, ret(us_delaybus).

- `ef_phyrmw` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x19a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x19a8-0x1a00 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x19c0 calls ef_phyget with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x19e8 calls ef_phyput with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=a3 at entry (arg3).
  The return at 0x19f8 has v0 = ret(ef_phyput).

- `ef_phyerrat` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1a00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1a00-0x1ae0 (224 bytes).
  It occupies 224 bytes.
  The `lw` at 0x1a14 loads 4 bytes from sym(ef_phyerrata) +0x4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3b0, including `lw` at 0x1a40, `lw` at 0x1a58.
  The `lw` at 0x1a4c loads 4 bytes from sym(ef_phyerrata) +0x14.
  2 such `lh` accesses load 2 bytes from sym(ef_phyerrata) +0x8, including `lh` at 0x1a64, `lh` at 0x1adc.
  The `lw` at 0x1a70 loads 4 bytes from a0 (arg0 at entry) +0x3b8.
  The `lw` at 0x1a7c loads 4 bytes from sym(ef_phyerrata) +0x0.
  The `lh` at 0x1a88 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lhu` at 0x1a94 loads 2 bytes from sym(ef_phyerrata) +0xa.
  The `lhu` at 0x1a98 loads 2 bytes from sym(ef_phyerrata) +0xc.
  The `lhu` at 0x1aa4 loads 2 bytes from sym(ef_phyerrata) +0xe.
  The `jal` at 0x1aa0 calls ef_phyrmw with a0=a0 at entry (arg0), a1=[sym(ef_phyerrata)+10]:2, a2=[sym(ef_phyerrata)+12]:2, a3=[sym(ef_phyerrata)+14]:2.
  The `beq` branch at 0x1a34 targets 0x1ab4, is taken when a2(=[sym(ef_phyerrata)+4]) == 0, and falls through when a2(=[sym(ef_phyerrata)+4]) != 0.
  The `beq` branch at 0x1a3c targets 0x1a5c and is always taken.
  The `beq` branch at 0x1a44 targets 0x1ad0, is taken when s2(=0x15f42) == a2(?), and falls through when s2(=0x15f42) != a2(?).
  The `beq` branch at 0x1a50 targets 0x1ab4, is taken when a2(=[sym(ef_phyerrata)+20]) == 0, and falls through when a2(=[sym(ef_phyerrata)+20]) != 0.
  The `bne` branch at 0x1a5c targets 0x1a44, is taken when a2(?) != a0(=[a0+944]), and falls through when a2(?) == a0(=[a0+944]).
  The `beq` branch at 0x1a68 targets 0x1a7c, is taken when a0(=[sym(ef_phyerrata)+8]:2) == s3(=-0x1), and falls through when a0(=[sym(ef_phyerrata)+8]:2) != s3(=-0x1).
  The `bne` branch at 0x1a74 targets 0x1a4c, is taken when a0(=[sym(ef_phyerrata)+8]:2) != at(=[a0+952]), and falls through when a0(=[sym(ef_phyerrata)+8]:2) == at(=[a0+952]).
  The `beq` branch at 0x1a80 targets 0x1a94, is taken when a0(=[sym(ef_phyerrata)]) == s3(=-0x1), and falls through when a0(=[sym(ef_phyerrata)]) != s3(=-0x1).
  The `bne` branch at 0x1a8c targets 0x1a4c, is taken when v0(=[a0+26]:2) != a0(=[sym(ef_phyerrata)]), and falls through when v0(=[a0+26]:2) == a0(=[sym(ef_phyerrata)]).
  The `beq` branch at 0x1aac targets 0x1a4c and is always taken.
  The `bne` branch at 0x1ad0 targets 0x1a4c, is taken when a3(=0x15f43) != a0(=[a0+944]), and falls through when a3(=0x15f43) == a0(=[a0+944]).
  The `beq` branch at 0x1ad8 targets 0x1a68 and is always taken.
  The return at 0x1ac8 has v0 = ?.

- `ef_fill` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1ae0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1ae0-0x1bec (268 bytes).
  It occupies 268 bytes.
  The `lw` at 0x1ae0 loads 4 bytes from a0 (arg0 at entry) +0x370.
  The `lw` at 0x1aec loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x1af4 loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `ld` at 0x1b38 loads 8 bytes from ret(m_vget) +0x8.
  The `sw` at 0x1b40 stores 4 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x0.
  The `sw` at 0x1b44 stores 4 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x4.
  The `ld` at 0x1b48 loads 8 bytes from a0 (arg0 at entry) +0x380.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1b58, `sd` at 0x1b88.
  The `ld` at 0x1b60 loads 8 bytes from a0 (arg0 at entry) +0x340.
  The `ld` at 0x1b6c loads 8 bytes from a0 (arg0 at entry) +0x368.
  The `ld` at 0x1b8c loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `sw` at 0x1b90 stores 4 bytes to a0 (arg0 at entry) +0x374.
  The `sw` at 0x1b9c stores 4 bytes to [a0+816]:8 +0x20.
  The `lw` at 0x1bc0 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lh` at 0x1bd0 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x1bdc loads 4 bytes from a0 (arg0 at entry) +0x420.
  The `sw` at 0x1be8 stores 4 bytes to a0 (arg0 at entry) +0x420.
  The `jal` at 0x1b28 calls m_vget with a0=0x0, a1=0x800, a2=0x1, a3=?.
  The `jal` at 0x1b54 calls kvtophys with a0=([ret(m_vget)+8]:8 + ret(m_vget)), a1=?, a2=?, a3=?.
  The `jal` at 0x1b64 calls pciio_dmamap_addr with a0=[a0+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x1b98 calls flushbus with a0=?, a1=?, a2=?, a3=[a0+816]:8.
  The `jal` at 0x1bd4 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `blez` branch at 0x1b18 targets 0x1b8c, is taken when s4(?) <= 0 (signed), and falls through when s4(?) > 0 (signed).
  The `beq` branch at 0x1b30 targets 0x1bc0, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `bne` branch at 0x1b84 targets 0x1b20, is taken when s2(?) < s4(?) (signed), and falls through when s2(?) >= s4(?) (signed).
  The `beq` branch at 0x1bc8 targets 0x1bdc, is taken when (a4(=[a0+32]) & 0x4) == 0, and falls through when (a4(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1be4 targets 0x1b8c and is always taken.
  The return at 0x1bb8 has v0 = ret(flushbus).

- `ef_xreset` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1bec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1bec-0x1c68 (124 bytes).
  It occupies 124 bytes.
  The `ld` at 0x1bf4 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x1c4c loads 8 bytes from ?.
  The `jal` at 0x1c10 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c1c calls ef_reset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1c30 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1c48 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1c3c targets 0x1c58, is taken when s0(=ret(ef_reset)) == 0, and falls through when s0(=ret(ef_reset)) != 0.
  The `bne` branch at 0x1c50 targets 0x1c48, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1c60 has v0 = one of ret(mutex_bitunlock), ret(m_freem).

- `ef_reset` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1c68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1c68-0x1d68 (256 bytes).
  It occupies 256 bytes.
  The `ld` at 0x1c70 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `sh` at 0x1c74 stores 2 bytes to a0 (arg0 at entry) +0x1c.
  The `sw` at 0x1c98 stores 4 bytes to [a0+272]:8 +0x34c.
  6 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1ca4, `sd` at 0x1cb8, `sd` at 0x1cdc.
  3 such `ld` accesses load 8 bytes from [a0+272]:8 +0x350, including `ld` at 0x1ca8, `ld` at 0x1cc4, `ld` at 0x1ce0.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1cb0, `ld` at 0x1ccc, `ld` at 0x1cec.
  3 such `ld` accesses load 8 bytes from [a0+272]:8 +0x380, including `ld` at 0x1d04, `ld` at 0x1d20, `ld` at 0x1d3c.
  The `sd` at 0x1d58 stores 8 bytes to [a0+272]:8 +0x378.
  The `jal` at 0x1c7c calls ef_getcdc with a0=[a0+272]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c84 calls ef_ioc3reset with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1c9c targets 0x1cc0 and is always taken.
  The `beq` branch at 0x1cbc targets 0x1cf8, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1cd4 targets 0x1cbc, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1ce8 targets 0x1ca4, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1cf0 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1cf8 targets 0x1d1c and is always taken.
  The `beq` branch at 0x1d18 targets 0x1d54, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1d30 targets 0x1d18, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1d44 targets 0x1d00, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1d4c targets 0x1d10 and is always taken.
  The return at 0x1d60 has v0 = ?.

- `ef_ioc3reset` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1d68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1d68-0x1e38 (208 bytes).
  It occupies 208 bytes.
  8 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x1d68, `ld` at 0x1d74, `ld` at 0x1da8.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x0, including `sw` at 0x1d70, `sw` at 0x1da4.
  3 such `lw` accesses load 4 bytes from [a0+816]:8 +0x0, including `lw` at 0x1d78, `lw` at 0x1d80, `lw` at 0x1e08.
  The `sw` at 0x1dac stores 4 bytes to [a0+816]:8 +0x40.
  The `sw` at 0x1db4 stores 4 bytes to [a0+816]:8 +0x1c.
  The `sw` at 0x1dc0 stores 4 bytes to [a0+816]:8 +0x44.
  The `sw` at 0x1dd0 stores 4 bytes to [a0+816]:8 +0x20.
  The `lh` at 0x1e24 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `jal` at 0x1dcc calls flushbus with a0=?, a1=?, a2=[a0+816]:8, a3=[a0+816]:8, a4=[a0+816]:8, a5=[a0+816]:8.
  The `jal` at 0x1dec calls us_delay with a0=0x1, a1=?, a2=[a0+816]:8, a3=?.
  The `jal` at 0x1e28 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `bgez` branch at 0x1d9c targets 0x1de4, is taken when at(=([[a0+816]:8] << 0x2a)) >= 0 (signed), and falls through when at(=([[a0+816]:8] << 0x2a)) < 0 (signed).
  The `beq` branch at 0x1dfc targets 0x1e20, is taken when s1(?) == a0(=-0x1), and falls through when s1(?) != a0(=-0x1).
  The `beq` branch at 0x1e10 targets 0x1dec, is taken when (s2(=0x200000) & t8(=[[a0+816]:8])) == 0, and falls through when (s2(=0x200000) & t8(=[[a0+816]:8])) != 0.
  The `beq` branch at 0x1e18 targets 0x1da4 and is always taken.
  The `beq` branch at 0x1e30 targets 0x1da4 and is always taken.
  The return at 0x1ddc has v0 = ret(flushbus).

- `ef_watchdog` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1e38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1e38-0x1f64 (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0x1e40 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x1e4c loads 8 bytes from [a0+272]:8 +0x3a8.
  The `ld` at 0x1e88 loads 8 bytes from (sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4)) +0x8.
  The `ld` at 0x1e8c loads 8 bytes from [(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8 +0x510.
  The `lw` at 0x1e90 loads 4 bytes from [a0+272]:8 +0x34.
  The `lw` at 0x1e94 loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1296]:8 +0x4.
  The `lw` at 0x1e98 loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1296]:8 +0x8.
  The `lw` at 0x1e9c loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1296]:8 +0x14.
  The `sw` at 0x1ea0 stores 4 bytes to [a0+272]:8 +0x3d4.
  The `sw` at 0x1eb4 stores 4 bytes to [a0+272]:8 +0x3d8.
  The `ld` at 0x1ed0 loads 8 bytes from [a0+272]:8 +0x378.
  The `lwu` at 0x1edc loads 4 bytes from [a0+272]:8 +0x370.
  The `ld` at 0x1ee0 loads 8 bytes from [a0+272]:8 +0x380.
  The `ld` at 0x1eec loads 8 bytes from ([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3)) +0x0.
  The `ld` at 0x1ef8 loads 8 bytes from [([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8 +0x8.
  The `sd` at 0x1f00 stores 8 bytes to [a0+272]:8 +0x378.
  The `sh` at 0x1f0c stores 2 bytes to [a0+272]:8 +0x1c.
  The `ld` at 0x1f3c loads 8 bytes from ?.
  The `jal` at 0x1e48 calls pciio_intr_cpu_get with a0=[[a0+272]:8+936]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e58 calls cpuvertex_to_cpuid with a0=ret(pciio_intr_cpu_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1e70 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x1eb0 calls ef_getcdc with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1eb8 calls ef_reclaim with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1ec4 calls ef_fill with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1f10 calls ef_phyerr with a0=[a0+272]:8, a1=ret(mutex_bitlock), a2=?, a3=?.
  The `jal` at 0x1f20 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1f38 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1f4c calls ef_intr with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x1ed4 targets 0x1f08, is taken when v1(=[[a0+272]:8+888]:8) != a0(=sym(.bss)), and falls through when v1(=[[a0+272]:8+888]:8) == a0(=sym(.bss)).
  The `beq` branch at 0x1ef0 targets 0x1f08, is taken when v0(=[([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8) == 0, and falls through when v0(=[([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8) != 0.
  The `beq` branch at 0x1f2c targets 0x1f48, is taken when s0(=ret(ef_reclaim)) == 0, and falls through when s0(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x1f40 targets 0x1f38, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1f5c has v0 = ret(ef_intr).

- `ef_getcdc` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1f64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1f64-0x1f90 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x1f64 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x1f68 loads 4 bytes from [a0+816]:8 +0x30.
  The `lw` at 0x1f6c loads 4 bytes from a0 (arg0 at entry) +0x3e4.
  The `lw` at 0x1f70 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `sw` at 0x1f80 stores 4 bytes to a0 (arg0 at entry) +0x3e4.
  The `sw` at 0x1f8c stores 4 bytes to a0 (arg0 at entry) +0x44.
  The return at 0x1f88 has v0 = ?.

- `ef_intr` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x1f90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x1f90-0x24dc (1356 bytes).
  It occupies 1356 bytes.
  The `lh` at 0x1f9c loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x1fc4 loads 4 bytes from a0 (arg0 at entry) +0x388.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x388, including `sw` at 0x1fdc, `sw` at 0x2108.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x1fe0, `ld` at 0x2048, `ld` at 0x2130.
  The `lw` at 0x1fe4 loads 4 bytes from [a0+816]:8 +0x4.
  The `sw` at 0x1fe8 stores 4 bytes to [a0+816]:8 +0x4.
  The `ld` at 0x1fec loads 8 bytes from a0 (arg0 at entry) +0x338.
  11 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x1ff8, `lw` at 0x2144, `lw` at 0x218c.
  The `lwu` at 0x203c loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `sw` at 0x2058 stores 4 bytes to [a0+816]:8 +0x20.
  The `ld` at 0x205c loads 8 bytes from a0 (arg0 at entry) +0x378.
  The `lw` at 0x2060 loads 4 bytes from [a0+888]:8 +0x0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x20d8, `ld` at 0x2370.
  The `ld` at 0x210c loads 8 bytes from abs 0x9200000001030100.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x38, including `lw` at 0x2148, `lw` at 0x2190, `lw` at 0x241c.
  The `lw` at 0x214c loads 4 bytes from a0 (arg0 at entry) +0x3f8.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x38, including `sw` at 0x2158, `sw` at 0x21a0, `sw` at 0x2434.
  The `sw` at 0x2164 stores 4 bytes to a0 (arg0 at entry) +0x3f8.
  The `lw` at 0x2194 loads 4 bytes from a0 (arg0 at entry) +0x3fc.
  The `sw` at 0x21ac stores 4 bytes to a0 (arg0 at entry) +0x3fc.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x40, including `lw` at 0x21e0, `lw` at 0x221c, `lw` at 0x2258.
  The `lw` at 0x21e4 loads 4 bytes from a0 (arg0 at entry) +0x40c.
  7 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x40, including `sw` at 0x21f0, `sw` at 0x222c, `sw` at 0x2268.
  The `sw` at 0x21fc stores 4 bytes to a0 (arg0 at entry) +0x40c.
  The `lw` at 0x2220 loads 4 bytes from a0 (arg0 at entry) +0x410.
  The `sw` at 0x2238 stores 4 bytes to a0 (arg0 at entry) +0x410.
  The `lw` at 0x225c loads 4 bytes from a0 (arg0 at entry) +0x414.
  The `sw` at 0x2274 stores 4 bytes to a0 (arg0 at entry) +0x414.
  The `lw` at 0x2298 loads 4 bytes from a0 (arg0 at entry) +0x418.
  The `sw` at 0x22b0 stores 4 bytes to a0 (arg0 at entry) +0x418.
  The `lw` at 0x22d4 loads 4 bytes from a0 (arg0 at entry) +0x400.
  The `sw` at 0x22ec stores 4 bytes to a0 (arg0 at entry) +0x400.
  The `lw` at 0x230c loads 4 bytes from a0 (arg0 at entry) +0x358.
  The `lw` at 0x233c loads 4 bytes from a0 (arg0 at entry) +0x34c.
  The `lw` at 0x2340 loads 4 bytes from a0 (arg0 at entry) +0x348.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x404, including `lw` at 0x2428, `lw` at 0x2488.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x404, including `sw` at 0x2440, `sw` at 0x24a0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x408, including `lw` at 0x2458, `lw` at 0x24b8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x408, including `sw` at 0x2470, `sw` at 0x24d0.
  The `jal` at 0x1fb8 calls mutex_bitlock with a0=a0+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2010 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2054 calls flushbus with a0=a0+856, a1=?, a2=(([a0+884] << 0x3) | 0x80000000), a3=[a0+816]:8, a4=0x80000000.
  The `jal` at 0x2074 calls ef_recv with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0xffffffff80000000.
  The `jal` at 0x20a0 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x20c4 calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x20e4 calls ether_input with a0=a0 at entry (arg0), a1=one of 0x0, 0x1000, a2=?, a3=?.
  The `jal` at 0x2124 calls randproc_input with a0=?, a1=0x500000000, a2=0xffffffff, a3=?.
  The `jal` at 0x2170 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=[a0+1016]+1, a4=[a0+56]+1.
  The `jal` at 0x21b4 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=[a0+1020]+1, a3=?, a4=[a0+56]+1.
  The `jal` at 0x2204 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a6=([[a0+816]:8+4] << 0x2e), a7=[a0+1036]+1.
  The `jal` at 0x2240 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x227c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x22b8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x22f4 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=[a0+64]+1.
  The `jal` at 0x231c calls ef_reclaim with a0=a0 at entry (arg0), a1=?, a2=?, a3=([[a0+816]:8+4] << 0x29).
  The `jal` at 0x2334 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2358 calls ps_txq_stat with a0=a0 at entry (arg0), a1=?, a2=?, a3=[a0+844].
  The `jal` at 0x236c calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2380 calls mutex_bitlock with a0=a0+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x239c calls ef_getcdc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a6=([[a0+816]:8+4] << 0x26).
  The `jal` at 0x23b4 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x23e0 calls ef_init with a0=a0 at entry (arg0), a1=[a0+32], a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2400 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=([[a0+816]:8+4] << 0x29).
  The `jal` at 0x243c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x246c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a6=([[a0+816]:8+4] << 0x2e).
  The `jal` at 0x249c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a6=([[a0+816]:8+4] << 0x26), a7=([[a0+816]:8+4] << 0x25).
  The `jal` at 0x24cc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a7=([[a0+816]:8+4] << 0x25).
  The `beq` branch at 0x1fd8 targets 0x2104, is taken when v0(=[a0+904]+1) >= 0x63 (unsigned), and falls through when v0(=[a0+904]+1) < 0x63 (unsigned).
  The `beq` branch at 0x1ff0 targets 0x200c, is taken when v1(=[a0+824]:8) == 0, and falls through when v1(=[a0+824]:8) != 0.
  The `beq` branch at 0x2004 targets 0x203c, is taken when a1(?) == a2(=0x41), and falls through when a1(?) != a2(=0x41).
  The `beq` branch at 0x206c targets 0x2080, is taken when (a3(=[[a0+888]:8]) & a4(=0xffffffff80000000)) == 0, and falls through when (a3(=[[a0+888]:8]) & a4(=0xffffffff80000000)) != 0.
  The `bne` branch at 0x208c targets 0x2134, is taken when (s2(=[[a0+816]:8+4]) & a4(=0x7fe003c)) != 0, and falls through when (s2(=[[a0+816]:8+4]) & a4(=0x7fe003c)) == 0.
  The `beq` branch at 0x20a8 targets 0x201c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x20bc targets 0x20d0 and is always taken.
  The `beq` branch at 0x20cc targets 0x20fc, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x20d4 targets 0x20c4, is taken when s2(=one of 0x0, 0x1) != 0, and falls through when s2(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x20f4 targets 0x20cc and is always taken.
  The `beq` branch at 0x20fc targets 0x201c and is always taken.
  The `beq` branch at 0x212c targets 0x1fe4 and is always taken.
  The `beq` branch at 0x2138 targets 0x2410, is taken when (s2(=[[a0+816]:8+4]) & 0x4) == 0, and falls through when (s2(=[[a0+816]:8+4]) & 0x4) != 0.
  The `beq` branch at 0x2160 targets 0x2178, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2184 targets 0x21c4, is taken when (s2(=[[a0+816]:8+4]) & 0x8) == 0, and falls through when (s2(=[[a0+816]:8+4]) & 0x8) != 0.
  The `beq` branch at 0x21a8 targets 0x21bc, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `bne` branch at 0x21c4 targets 0x241c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x21cc targets 0x244c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bgez` branch at 0x21d4 targets 0x2210, is taken when a6(=([[a0+816]:8+4] << 0x2e)) >= 0 (signed), and falls through when a6(=([[a0+816]:8+4] << 0x2e)) < 0 (signed).
  The `beq` branch at 0x21f8 targets 0x220c, is taken when (t0(=[a0+32]) & 0x4) == 0, and falls through when (t0(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2210 targets 0x224c, is taken when t1(=([[a0+816]:8+4] << 0x2d)) >= 0 (signed), and falls through when t1(=([[a0+816]:8+4] << 0x2d)) < 0 (signed).
  The `beq` branch at 0x2234 targets 0x2248, is taken when (t3(=[a0+32]) & 0x4) == 0, and falls through when (t3(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x224c targets 0x2288, is taken when t8(=([[a0+816]:8+4] << 0x2c)) >= 0 (signed), and falls through when t8(=([[a0+816]:8+4] << 0x2c)) < 0 (signed).
  The `beq` branch at 0x2270 targets 0x2284, is taken when (ra(=[a0+32]) & 0x4) == 0, and falls through when (ra(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2288 targets 0x22c4, is taken when at(=([[a0+816]:8+4] << 0x2b)) >= 0 (signed), and falls through when at(=([[a0+816]:8+4] << 0x2b)) < 0 (signed).
  The `beq` branch at 0x22ac targets 0x22c0, is taken when (v1(=[a0+32]) & 0x4) == 0, and falls through when (v1(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x22c4 targets 0x2304, is taken when a0(=([[a0+816]:8+4] << 0x2a)) >= 0 (signed), and falls through when a0(=([[a0+816]:8+4] << 0x2a)) < 0 (signed).
  The `beq` branch at 0x22e8 targets 0x22fc, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2304 targets 0x2390, is taken when a3(=([[a0+816]:8+4] << 0x29)) >= 0 (signed), and falls through when a3(=([[a0+816]:8+4] << 0x29)) < 0 (signed).
  The `beq` branch at 0x2314 targets 0x23f0, is taken when (a4(=[a0+856]) & 0x10) == 0, and falls through when (a4(=[a0+856]) & 0x10) != 0.
  The `beq` branch at 0x2360 targets 0x237c, is taken when s7(=ret(ef_reclaim)) == 0, and falls through when s7(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x2374 targets 0x236c, is taken when s7(?) != 0, and falls through when s7(?) == 0.
  The `beq` branch at 0x2394 targets 0x23c0, is taken when (s2(=[[a0+816]:8+4]) & a4(=0x1800000)) == 0, and falls through when (s2(=[[a0+816]:8+4]) & a4(=0x1800000)) != 0.
  The `beq` branch at 0x23ac targets 0x23bc, is taken when (a5(=[a0+32]) & 0x4) == 0, and falls through when (a5(=[a0+32]) & 0x4) != 0.
  The `bltz` branch at 0x23c0 targets 0x247c, is taken when a6(=([[a0+816]:8+4] << 0x26)) < 0 (signed), and falls through when a6(=([[a0+816]:8+4] << 0x26)) >= 0 (signed).
  The `bltz` branch at 0x23c8 targets 0x24ac, is taken when a7(=([[a0+816]:8+4] << 0x25)) < 0 (signed), and falls through when a7(=([[a0+816]:8+4] << 0x25)) >= 0 (signed).
  The `beq` branch at 0x23d0 targets 0x2094, is taken when s5(=one of 0x0, 0x1) == 0, and falls through when s5(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x23e8 targets 0x2098 and is always taken.
  The `beq` branch at 0x23f8 targets 0x238c, is taken when (t0(=[a0+32]) & 0x4) == 0, and falls through when (t0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2408 targets 0x2390 and is always taken.
  The `beq` branch at 0x2414 targets 0x2180 and is always taken.
  The `beq` branch at 0x2444 targets 0x21c8 and is always taken.
  The `beq` branch at 0x2474 targets 0x21d0 and is always taken.
  The `beq` branch at 0x24a4 targets 0x23c4 and is always taken.
  The `beq` branch at 0x24d4 targets 0x23d0 and is always taken.
  The return at 0x2034 has v0 = one of ret(mutex_bitunlock), ?.

- `ef_recv` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x24dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x24dc-0x29e0 (1284 bytes).
  It occupies 1284 bytes.
  The `lh` at 0x24dc loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x24e4 loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x2508 loads 4 bytes from a0 (arg0 at entry) +0x370.
  9 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2540, `lhu` at 0x2578, `lhu` at 0x257c.
  7 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2550, `lbu` at 0x25bc, `lbu` at 0x25fc.
  The `lw` at 0x2568 loads 4 bytes from a0 (arg0 at entry) +0x358.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x25dc, `lw` at 0x25f0, `lw` at 0x26bc.
  The `sb` at 0x2684 stores 1 byte to ?.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x380, including `ld` at 0x26a4, `ld` at 0x26e4, `ld` at 0x2798.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x26b0, `ld` at 0x26b4, `ld` at 0x26f0.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0x26ec, `sd` at 0x26f8, `sd` at 0x2704.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0x26fc, `sh` at 0x2740, `sh` at 0x2914.
  The `lw` at 0x2710 loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x271c loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `sw` at 0x272c stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `sw` at 0x273c stores 4 bytes to a0 (arg0 at entry) +0x48.
  The `sw` at 0x2774 stores 4 bytes to a0 (arg0 at entry) +0x370.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x378, including `sd` at 0x27c4, `sd` at 0x27e0.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x281c, `lw` at 0x2874, `lw` at 0x28c0.
  The `lw` at 0x2820 loads 4 bytes from a0 (arg0 at entry) +0x3e8.
  The `sw` at 0x2834 stores 4 bytes to a0 (arg0 at entry) +0x3e8.
  The `lw` at 0x2878 loads 4 bytes from a0 (arg0 at entry) +0x3ec.
  The `sw` at 0x2890 stores 4 bytes to a0 (arg0 at entry) +0x3ec.
  The `lw` at 0x28c4 loads 4 bytes from a0 (arg0 at entry) +0x3f0.
  The `sw` at 0x28dc stores 4 bytes to a0 (arg0 at entry) +0x3f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3f4, including `lw` at 0x2948, `lw` at 0x2990.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3f4, including `sw` at 0x2958, `sw` at 0x29a0.
  The `jal` at 0x2688 calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x26c8 calls us_delay with a0=[sym(.sdata)+16], a1=?, a2=?, a3=?.
  The `jal` at 0x2778 calls ef_fill with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2840 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a4=[a0+1000]+1.
  The `jal` at 0x2894 calls ether_sprintf with a0=?, a1=?, a2=?, a3=[a0+1004]+1.
  The `jal` at 0x28a8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `jal` at 0x28e8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=[a0+1008]+1, a3=?.
  The `jal` at 0x28fc calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x291c calls ether_input with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x295c calls ether_sprintf with a0=?, a1=0x30, a2=?, a3=?, a4=[a0+1012]+1.
  The `jal` at 0x2970 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `jal` at 0x29a4 calls ether_sprintf with a0=?, a1=[a0+1012]+1, a2=?, a3=?.
  The `jal` at 0x29b8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `beq` branch at 0x2520 targets 0x276c, is taken when at(=[a0+880]) == v1(=[a0+884]), and falls through when at(=[a0+880]) != v1(=[a0+884]).
  The `beq` branch at 0x2530 targets 0x29d4 and is always taken.
  The `bne` branch at 0x2538 targets 0x2750, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x2548 targets 0x2750, is taken when (a0(?) & 0x3fff) != 0, and falls through when (a0(?) & 0x3fff) == 0.
  The `beq` branch at 0x2558 targets 0x2568, is taken when a1(=0x6) == a2(?), and falls through when a1(=0x6) != a2(?).
  The `bne` branch at 0x2560 targets 0x2750, is taken when a3(=0x11) != a2(?), and falls through when a3(=0x11) == a2(?).
  The `beq` branch at 0x2570 targets 0x2750, is taken when (a4(=[a0+856]) & 0x1) == 0, and falls through when (a4(=[a0+856]) & 0x1) != 0.
  The `beq` branch at 0x2624 targets 0x27e4, is taken when (s7(?) & 0x1) == 0, and falls through when (s7(?) & 0x1) != 0.
  The `bne` branch at 0x2670 targets 0x2750, is taken when a2(=0xffff) != a3(?), and falls through when a2(=0xffff) == a3(?).
  The `beq` branch at 0x2680 targets 0x2754, is taken when s8(=one of 0x0, 0x1) == 0, and falls through when s8(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x269c targets 0x2770, is taken when a6(=[a0+884]) == s3(?), and falls through when a6(=[a0+884]) != s3(?).
  The `beq` branch at 0x26c0 targets 0x26d0, is taken when s4(=[sym(.sdata)+12]) == 0, and falls through when s4(=[sym(.sdata)+12]) != 0.
  The `beq` branch at 0x26dc targets 0x2774, is taken when (s4(?) & t8(=0xffffffff80000000)) == 0, and falls through when (s4(?) & t8(=0xffffffff80000000)) != 0.
  The `beq` branch at 0x2738 targets 0x2810, is taken when (s6(?) & v0(=0x40000000)) == 0, and falls through when (s6(?) & v0(=0x40000000)) != 0.
  The `beq` branch at 0x2748 targets 0x2538, is taken when t0(=0x800) == a5(?), and falls through when t0(=0x800) != a5(?).
  The `bne` branch at 0x2750 targets 0x2688, is taken when s8(=one of 0x0, 0x1) != 0, and falls through when s8(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x2758 targets 0x27d4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x2764 targets 0x2690 and is always taken.
  The `beq` branch at 0x27b4 targets 0x27dc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x27d4 targets 0x2764 and is always taken.
  The `beq` branch at 0x27dc targets 0x27c8 and is always taken.
  The `beq` branch at 0x2808 targets 0x2654 and is always taken.
  The `beq` branch at 0x2814 targets 0x2860, is taken when a5(?) >= 0x40 (signed), and falls through when a5(?) < 0x40 (signed).
  The `beq` branch at 0x2830 targets 0x2848, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x284c targets 0x2984, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2858 targets 0x2874 and is always taken.
  The `beq` branch at 0x2860 targets 0x293c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x286c targets 0x298c, is taken when s7(?) == a2(=0x5fc), and falls through when s7(?) != a2(=0x5fc).
  The `beq` branch at 0x288c targets 0x28b4, is taken when (a4(=[a0+32]) & 0x4) == 0, and falls through when (a4(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x28b8 targets 0x28f4, is taken when (s6(?) & 0x4) == 0, and falls through when (s6(?) & 0x4) != 0.
  The `beq` branch at 0x28d8 targets 0x28f4, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x28f4 targets 0x290c, is taken when s8(=one of 0x0, 0x1) == 0, and falls through when s8(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2904 targets 0x2694 and is always taken.
  The `beq` branch at 0x2934 targets 0x2690 and is always taken.
  The `bne` branch at 0x293c targets 0x29cc, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x2954 targets 0x2978, is taken when (a5(=[a0+32]) & 0x4) == 0, and falls through when (a5(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x297c targets 0x28b4 and is always taken.
  The `beq` branch at 0x2984 targets 0x28b4 and is always taken.
  The `beq` branch at 0x299c targets 0x29c0, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x29c4 targets 0x28b4 and is always taken.
  The `beq` branch at 0x29cc targets 0x28b4 and is always taken.
  The `beq` branch at 0x29d8 targets 0x26a8 and is always taken.
  The return at 0x27cc has v0 = ?.

- `ef_transmit` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x29e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x29e0-0x31f0 (2064 bytes).
  It occupies 2064 bytes.
  The `ld` at 0x29e8 loads 8 bytes from a0 (arg0 at entry) +0x110.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2a2c, `ld` at 0x2a60, `ld` at 0x2df8.
  The `lhu` at 0x2a30 loads 2 bytes from ?.
  2 such `lbu` accesses load 1 byte from a4 (arg4 at entry) +0x1a, including `lbu` at 0x2a74, `lbu` at 0x2bf8.
  5 such `ld` accesses load 8 bytes from a4 (arg4 at entry) +0x8, including `ld` at 0x2a84, `ld` at 0x2e94, `ld` at 0x2ecc.
  The `lbu` at 0x2a8c loads 1 byte from ([a4+8]:8 + a4) +0x9.
  The `lbu` at 0x2a94 loads 1 byte from ([a4+8]:8 + a4) +0x0.
  The `lhu` at 0x2aa8 loads 2 bytes from a1 (arg1 at entry) +0x2.
  The `lhu` at 0x2aac loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `lhu` at 0x2ab0 loads 2 bytes from a2 (arg2 at entry) +0x4.
  The `lhu` at 0x2ab4 loads 2 bytes from ([a4+8]:8 + a4) +0x2.
  The `lhu` at 0x2ab8 loads 2 bytes from a2 (arg2 at entry) +0x0.
  The `lhu` at 0x2ac0 loads 2 bytes from a2 (arg2 at entry) +0x2.
  The `lhu` at 0x2acc loads 2 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0x2ad8 loads 4 bytes from ([a4+8]:8 + a4) +0xc.
  The `lw` at 0x2afc loads 4 bytes from ([a4+8]:8 + a4) +0x10.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2b58, `sh` at 0x2bf0.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x358, including `lw` at 0x2b70, `lw` at 0x2d30.
  3 such `lw` accesses load 4 bytes from [a0+272]:8 +0x34c, including `lw` at 0x2b80, `lw` at 0x2db4, `lw` at 0x30fc.
  5 such `lw` accesses load 4 bytes from [a0+272]:8 +0x348, including `lw` at 0x2b84, `lw` at 0x2d40, `lw` at 0x2d90.
  The `ld` at 0x2b9c loads 8 bytes from [a0+272]:8 +0x338.
  The `lwl` at 0x2bb0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lwr` at 0x2bb8 loads 4 bytes from a1 (arg1 at entry) +0x3.
  14 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2bbc, `sw` at 0x2cc4, `sw` at 0x2ce8.
  The `lbu` at 0x2bc0 loads 1 byte from a1 (arg1 at entry) +0x4.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x2bc4, `sb` at 0x2bcc, `sb` at 0x2be8.
  The `lbu` at 0x2bc8 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lwl` at 0x2bd0 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lwr` at 0x2bd8 loads 4 bytes from a2 (arg2 at entry) +0x3.
  The `swl` at 0x2bdc stores 4 bytes to ?.
  The `swr` at 0x2be0 stores 4 bytes to ?.
  The `lbu` at 0x2be4 loads 1 byte from a2 (arg2 at entry) +0x4.
  The `lbu` at 0x2bec loads 1 byte from a2 (arg2 at entry) +0x5.
  6 such `lhu` accesses load 2 bytes from a4 (arg4 at entry) +0x18, including `lhu` at 0x2c3c, `lhu` at 0x2cd0, `lhu` at 0x2ebc.
  2 such `ld` accesses load 8 bytes from a4 (arg4 at entry) +0x0, including `ld` at 0x2c40, `ld` at 0x2f00.
  The `ld` at 0x2c4c loads 8 bytes from [a4]:8 +0x0.
  5 such `ld` accesses load 8 bytes from [a4]:8 +0x8, including `ld` at 0x2c64, `ld` at 0x2cec, `ld` at 0x2f18.
  4 such `lhu` accesses load 2 bytes from [a4]:8 +0x18, including `lhu` at 0x2c78, `lhu` at 0x2ccc, `lhu` at 0x2f58.
  2 such `ld` accesses load 8 bytes from [[a4]:8]:8 +0x8, including `ld` at 0x2c8c, `ld` at 0x2d10.
  The `lhu` at 0x2cc8 loads 2 bytes from [[a4]:8]:8 +0x18.
  7 such `ld` accesses load 8 bytes from [a0+272]:8 +0x340, including `ld` at 0x2d08, `ld` at 0x2d28, `ld` at 0x2ee4.
  7 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2d0c, `sd` at 0x2d2c, `sd` at 0x2eec.
  The `lw` at 0x2d44 loads 4 bytes from [a0+272]:8 +0x35c.
  The `lw` at 0x2d54 loads 4 bytes from ?.
  The `lbu` at 0x2d60 loads 1 byte from [a0+272]:8 +0x1de.
  The `lwu` at 0x2d7c loads 4 bytes from [a0+272]:8 +0x348.
  The `ld` at 0x2d80 loads 8 bytes from [a0+272]:8 +0x350.
  The `sd` at 0x2d8c stores 8 bytes to ([[a0+272]:8+848]:8 + ([[a0+272]:8+840] << 0x3)) +0x0.
  The `ld` at 0x2d9c loads 8 bytes from [a0+272]:8 +0x330.
  The `sw` at 0x2da4 stores 4 bytes to [a0+272]:8 +0x348.
  The `sw` at 0x2dac stores 4 bytes to [[a0+272]:8+816]:8 +0x44.
  The `lw` at 0x2dc0 loads 4 bytes from [a0+272]:8 +0x4c.
  The `sw` at 0x2dd0 stores 4 bytes to [a0+272]:8 +0x4c.
  2 such `ld` accesses load 8 bytes from ret(m_vget) +0x8, including `ld` at 0x301c, `ld` at 0x3060.
  The `sh` at 0x3030 stores 2 bytes to ret(m_vget) +0x18.
  The `lhu` at 0x3050 loads 2 bytes from ret(m_vget) +0x18.
  The `lw` at 0x3088 loads 4 bytes from [a0+272]:8 +0x41c.
  The `sw` at 0x3098 stores 4 bytes to [a0+272]:8 +0x41c.
  The `lw` at 0x3114 loads 4 bytes from [a0+272]:8 +0x424.
  The `sw` at 0x311c stores 4 bytes to [a0+272]:8 +0x424.
  3 such `lw` accesses load 4 bytes from [a0+272]:8 +0x20, including `lw` at 0x3128, `lw` at 0x317c, `lw` at 0x31b8.
  3 such `lh` accesses load 2 bytes from [a0+272]:8 +0x1a, including `lh` at 0x313c, `lh` at 0x3190, `lh` at 0x31cc.
  The `lw` at 0x3168 loads 4 bytes from [a0+272]:8 +0x428.
  The `sw` at 0x3178 stores 4 bytes to [a0+272]:8 +0x428.
  The `lw` at 0x31a4 loads 4 bytes from [a0+272]:8 +0x420.
  The `sw` at 0x31b4 stores 4 bytes to [a0+272]:8 +0x420.
  The `jal` at 0x2b68 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2ca8 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=[a4+24]:2, a3=?.
  The `jal` at 0x2cf0 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=((([[a4]:8+24]:2 << 0x8) | ([[[a4]:8]:8+24]:2 << 0x14)) | [a4+24]:2+14), a2=[a4+24]:2+14, a3=([[[a4]:8]:8+24]:2 << 0x14).
  The `jal` at 0x2d04 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2d14 calls kvtophys with a0=([[[a4]:8]:8+8]:8 + [[a4]:8]:8), a1=?, a2=?, a3=?.
  The `jal` at 0x2d24 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2d74 calls ef_selfsnoop with a0=[a0+272]:8, a1=?, a2=?, a3=?, a4=[[a0+272]:8+478]:1.
  The `jal` at 0x2da8 calls flushbus with a0=?, a1=?, a2=?, a3=?, a7=[[a0+272]:8+816]:8.
  The `jal` at 0x2de0 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2df4 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2e38 calls ef_reclaim with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x2e54 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2ed0 calls kvtophys with a0=([a4+8]:8 + a4), a1=(([a4+24]:2 << 0x8) | 0xe), a2=?, a3=?.
  The `jal` at 0x2ee0 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2f44 calls bcopy with a0=([a4+8]:8 + a4), a1=?, a2=[a4+24]:2, a3=?.
  The `jal` at 0x2f74 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=(([[a4]:8+24]:2 << 0x8) | [a4+24]:2+14), a2=[a4+24]:2+14, a3=?.
  The `jal` at 0x2f84 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2fc0 calls kvtophys with a0=([a4+8]:8 + a4), a1=((([[a4]:8+24]:2 << 0x14) | ([a4+24]:2 << 0x8)) | 0xe), a2=([a4+24]:2 << 0x8), a3=?.
  The `jal` at 0x2fd0 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2fe0 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=?, a2=?, a3=?.
  The `jal` at 0x2ff0 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x3008 calls m_vget with a0=0x0, a1=?, a2=0x1, a3=?.
  The `jal` at 0x3028 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=?, a3=([ret(m_vget)+8]:8 + ret(m_vget)).
  The `jal` at 0x3034 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x3068 calls kvtophys with a0=([ret(m_vget)+8]:8 + ret(m_vget)), a1=(([ret(m_vget)+24]:2 << 0x8) | 0xe), a2=?, a3=?.
  The `jal` at 0x3078 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x3094 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x30a4 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x30b4 calls ef_reclaim with a0=[a0+272]:8, a1=[[a0+272]:8+840], a2=?, a3=?.
  The `jal` at 0x30c8 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x30dc calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x30f0 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x3120 calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+840], a2=?, a3=?.
  The `jal` at 0x3140 calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x3150 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x3174 calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+1064]+1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3194 calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x31b0 calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+1056]+1, a2=?, a3=?.
  The `jal` at 0x31d0 calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x31e0 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `beq` branch at 0x2a1c targets 0x2e78, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x2a44 targets 0x2a60, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x2a54 targets 0x2a60, is taken when a4(?) == a5(?), and falls through when a4(?) != a5(?).
  The `bne` branch at 0x2a64 targets 0x2a2c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2a6c targets 0x3168, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2a7c targets 0x2e84, is taken when (a7(=[a4+26]:1) & 0x2) == 0, and falls through when (a7(=[a4+26]:1) & 0x2) != 0.
  The `beq` branch at 0x2a9c targets 0x2e8c, is taken when a1(=[([a4+8]:8 + a4)+9]:1) == v1(=0x6), and falls through when a1(=[([a4+8]:8 + a4)+9]:1) != v1(=0x6).
  The `bne` branch at 0x2b78 targets 0x3088, is taken when (a6(=[[a0+272]:8+856]) & 0x4) != 0, and falls through when (a6(=[[a0+272]:8+856]) & 0x4) == 0.
  The `beq` branch at 0x2ba8 targets 0x30b4, is taken when a0(=[[a0+272]:8+844]) == t9(?), and falls through when a0(=[[a0+272]:8+844]) != t9(?).
  The `beq` branch at 0x2c00 targets 0x2c1c, is taken when (ra(=[a4+26]:1) & 0x2) == 0, and falls through when (ra(=[a4+26]:1) & 0x2) != 0.
  The `bne` branch at 0x2c1c targets 0x2e48, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x2c24 targets 0x2e94, is taken when s3(?) == t9(=0x1), and falls through when s3(?) != t9(=0x1).
  The `beq` branch at 0x2c2c targets 0x2ef0, is taken when s3(?) == ra(=0x2), and falls through when s3(?) != ra(=0x2).
  The `bne` branch at 0x2c34 targets 0x3004, is taken when s3(?) != at(=0x3), and falls through when s3(?) == at(=0x3).
  The `beq` branch at 0x2c48 targets 0x3000, is taken when a2(=[a4+24]:2) >= 0x59 (signed), and falls through when a2(=[a4+24]:2) < 0x59 (signed).
  The `blez` branch at 0x2c50 targets 0x3004, is taken when a2(=[a4+24]:2) <= 0 (signed), and falls through when a2(=[a4+24]:2) > 0 (signed).
  The `bne` branch at 0x2c5c targets 0x3004, is taken when (a2(=[a4+24]:2) & 0x1) != 0, and falls through when (a2(=[a4+24]:2) & 0x1) == 0.
  The `bne` branch at 0x2c70 targets 0x3004, is taken when (a0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) != 0, and falls through when (a0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) == 0.
  The `blez` branch at 0x2c7c targets 0x3000, is taken when a0(=[[a4]:8+24]:2) <= 0 (signed), and falls through when a0(=[[a4]:8+24]:2) > 0 (signed).
  The `bne` branch at 0x2c84 targets 0x3004, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x2c98 targets 0x3000, is taken when (a3(=([[[a4]:8]:8+8]:8 + [[a4]:8]:8)) & 0x7f) != 0, and falls through when (a3(=([[[a4]:8]:8+8]:8 + [[a4]:8]:8)) & 0x7f) == 0.
  The `beq` branch at 0x2d38 targets 0x2d54, is taken when (a1(=[[a0+272]:8+856]) & 0x10) == 0, and falls through when (a1(=[[a0+272]:8+856]) & 0x10) != 0.
  The `beq` branch at 0x2d4c targets 0x3160, is taken when (a2(=[[a0+272]:8+840]) & a3(=[[a0+272]:8+860])) == 0, and falls through when (a2(=[[a0+272]:8+840]) & a3(=[[a0+272]:8+860])) != 0.
  The `beq` branch at 0x2d64 targets 0x2d7c, is taken when a4(=[[a0+272]:8+478]:1) == 0, and falls through when a4(=[[a0+272]:8+478]:1) != 0.
  The `beq` branch at 0x2dcc targets 0x2e38, is taken when t8(?) >= 0x15 (unsigned), and falls through when t8(?) < 0x15 (unsigned).
  The `beq` branch at 0x2de8 targets 0x2e08, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x2dfc targets 0x2df4, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x2e40 targets 0x2dd8 and is always taken.
  The `beq` branch at 0x2e70 targets 0x2d30 and is always taken.
  The `beq` branch at 0x2e7c targets 0x2a74 and is always taken.
  The `beq` branch at 0x2e84 targets 0x2b5c and is always taken.
  The `beq` branch at 0x2e8c targets 0x2aa8 and is always taken.
  The `bne` branch at 0x2ea0 targets 0x3004, is taken when (v0(=([a4+8]:8 + a4)) & 0x1) != 0, and falls through when (v0(=([a4+8]:8 + a4)) & 0x1) == 0.
  The `beq` branch at 0x2ee8 targets 0x2d30 and is always taken.
  The `bne` branch at 0x2efc targets 0x3000, is taken when (a0(=([a4+8]:8 + a4)) & 0x1) != 0, and falls through when (a0(=([a4+8]:8 + a4)) & 0x1) == 0.
  The `blez` branch at 0x2f08 targets 0x3000, is taken when a2(=[a4+24]:2) <= 0 (signed), and falls through when a2(=[a4+24]:2) > 0 (signed).
  The `bne` branch at 0x2f10 targets 0x3000, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x2f24 targets 0x3000, is taken when (v0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) != 0, and falls through when (v0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) == 0.
  The `beq` branch at 0x2f2c targets 0x2f38, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2f34 targets 0x3000, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x2f3c targets 0x2f94, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2f8c targets 0x2d30 and is always taken.
  The `beq` branch at 0x2ff8 targets 0x2d30 and is always taken.
  The `beq` branch at 0x3010 targets 0x31a4, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `beq` branch at 0x3080 targets 0x2d30 and is always taken.
  The `beq` branch at 0x30ac targets 0x2e08 and is always taken.
  The `beq` branch at 0x30d0 targets 0x30f0, is taken when s0(=ret(ef_reclaim)) == 0, and falls through when s0(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x30e4 targets 0x30dc, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0x310c targets 0x2b90, is taken when a0(=[[a0+272]:8+844]) != t9(?), and falls through when a0(=[[a0+272]:8+844]) == t9(?).
  The `beq` branch at 0x3130 targets 0x314c, is taken when (at(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (at(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x3158 targets 0x2e08 and is always taken.
  The `beq` branch at 0x3160 targets 0x2d54 and is always taken.
  The `beq` branch at 0x3184 targets 0x319c, is taken when (a2(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (a2(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x319c targets 0x2e08 and is always taken.
  The `beq` branch at 0x31c0 targets 0x31dc, is taken when (a2(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (a2(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x31e8 targets 0x2e08 and is always taken.
  The return at 0x2e30 has v0 = one of 0x0, 0x7, 0x7f, 0x84.

- `ef_selfsnoop` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x31f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x31f0-0x3344 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0x32a0 loads 8 bytes from ret(m_vget) +0x8.
  The `sh` at 0x32bc stores 2 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x8.
  The `sd` at 0x32c8 stores 8 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x0.
  The `ldl` at 0x32cc loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `ldr` at 0x32d4 loads 8 bytes from a1 (arg1 at entry) +0x7.
  The `sdl` at 0x32d8 stores 8 bytes to ?.
  The `sdr` at 0x32dc stores 8 bytes to ?.
  The `lwl` at 0x32e0 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lwr` at 0x32ec loads 4 bytes from a1 (arg1 at entry) +0xb.
  The `swl` at 0x32f8 stores 4 bytes to ?.
  The `swr` at 0x3304 stores 4 bytes to ?.
  The `lhu` at 0x3310 loads 2 bytes from a1 (arg1 at entry) +0xc.
  The `sh` at 0x331c stores 2 bytes to ?.
  The `jal` at 0x3228 calls bcopy with a0=a1 at entry (arg1), a1=sp-110, a2=0xe, a3=a3 at entry (arg3).
  The `jal` at 0x3240 calls m_datacopy with a0=a2 at entry (arg2), a1=0x0, a2=0x14, a3=sp-96.
  The `jal` at 0x3254 calls snoop_match with a0=a0+400, a1=sp-110, a2=0x24, a3=?.
  The `jal` at 0x3270 calls m_vget with a0=0x0, a1=(a3+48 << 0x0), a2=0x1, a3=?.
  The `jal` at 0x3290 calls snoop_drop2 with a0=a0+400, a1=0x8000, a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=ret(snoop_match).
  The `jal` at 0x32c4 calls m_datacopy with a0=a2 at entry (arg2), a1=0x0, a2=a3 at entry (arg3), a3=([ret(m_vget)+8]:8 + ret(m_vget))+48, a4=([ret(m_vget)+8]:8 + ret(m_vget)), a5=0x30.
  The `jal` at 0x3318 calls snoop_input2 with a0=a0+400, a1=0x8000, a2=?, a3=?, a5=ret(snoop_match), a6=[a1+12]:2.
  The `beq` branch at 0x325c targets 0x3320, is taken when v0(=ret(snoop_match)) == 0, and falls through when v0(=ret(snoop_match)) != 0.
  The `bne` branch at 0x3278 targets 0x32a0, is taken when v0(=ret(m_vget)) != 0, and falls through when v0(=ret(m_vget)) == 0.
  The `beq` branch at 0x3298 targets 0x3324 and is always taken.
  The return at 0x333c has v0 = one of ret(snoop_drop2), ?.

- `ef_ioctl` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x3344 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x3344-0x34f8 (436 bytes).
  It occupies 436 bytes.
  The `ld` at 0x3360 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x3398 loads 8 bytes from a2 (arg2 at entry) +0x0.
  The `sh` at 0x33fc stores 2 bytes to a2 (arg2 at entry) +0x8.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x340c, `lbu` at 0x34a4.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x8, including `lhu` at 0x3430, `lhu` at 0x348c.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x3460, `sb` at 0x34b0.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x3c4, including `lw` at 0x3464, `lw` at 0x34b4.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x20, including `lw` at 0x346c, `lw` at 0x34bc.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x3c4, including `sw` at 0x3478, `sw` at 0x34c4.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x20, including `sw` at 0x34e4, `sw` at 0x34f4.
  The `jal` at 0x3380 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x33c4 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x33ec calls ef_lafhash with a0=[a2]:8+2, a1=0x6, a2=[a2]:8, a3=?.
  The `jal` at 0x3428 calls ef_lafhash with a0=[a2]:8+2, a1=0x6, a2=[a2]:8, a3=?.
  The `jal` at 0x3444 calls mfhasvalue with a0=a0+296, a1=[a2+8]:2, a2=?, a3=?.
  The `jal` at 0x347c calls ef_init with a0=a0 at entry (arg0), a1=?, a2=ret(mutex_bitlock), a3=?, a4=[[a0+272]:8+964]+1.
  The `jal` at 0x34cc calls ef_init with a0=a0 at entry (arg0), a1=?, a2=ret(mutex_bitlock), a3=?, a5=[[a0+272]:8+964]-1.
  The `beq` branch at 0x339c targets 0x33e8, is taken when s3(=a1) == a1(=0xffffffff80206931), and falls through when s3(=a1) != a1(=0xffffffff80206931).
  The `beq` branch at 0x33a4 targets 0x3428, is taken when s3(=a1) == a0(=0xffffffff80206932), and falls through when s3(=a1) != a0(=0xffffffff80206932).
  The `beq` branch at 0x3418 targets 0x345c, is taken when (a5(?) & a0(?)) == 0, and falls through when (a5(?) & a0(?)) != 0.
  The `beq` branch at 0x3420 targets 0x33b0 and is always taken.
  The `beq` branch at 0x3434 targets 0x3444, is taken when v0(=ret(ef_lafhash)) == a1(=[a2+8]:2), and falls through when v0(=ret(ef_lafhash)) != a1(=[a2+8]:2).
  The `beq` branch at 0x343c targets 0x33b0 and is always taken.
  The `beq` branch at 0x344c targets 0x348c, is taken when v0(=ret(mfhasvalue)) == 0, and falls through when v0(=ret(mfhasvalue)) != 0.
  The `beq` branch at 0x3454 targets 0x33b0 and is always taken.
  The `beq` branch at 0x3468 targets 0x34dc, is taken when v0(=[[a0+272]:8+964]) == 0, and falls through when v0(=[[a0+272]:8+964]) != 0.
  The `beq` branch at 0x3484 targets 0x33ac and is always taken.
  The `beq` branch at 0x34c0 targets 0x34e8, is taken when a5(=[[a0+272]:8+964]-1) == 0, and falls through when a5(=[[a0+272]:8+964]-1) != 0.
  The `beq` branch at 0x34d4 targets 0x33ac and is always taken.
  The `beq` branch at 0x34e0 targets 0x3470 and is always taken.
  The `beq` branch at 0x34f0 targets 0x34c8 and is always taken.
  The return at 0x33e0 has v0 = ?.

- `ef_lafhash` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x34f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x34f8-0x35ac (180 bytes).
  It occupies 180 bytes.
  The `lbu` at 0x352c loads 1 byte from ?.
  The `blez` branch at 0x3500 targets 0x3560, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x3510 targets 0x351c and is always taken.
  The `bltz` branch at 0x3518 targets 0x3560, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `beq` branch at 0x3528 targets 0x35a0 and is always taken.
  The `bltz` branch at 0x3538 targets 0x3518, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `bne` branch at 0x3550 targets 0x3530, is taken when (at(?) & 0x1) != 0, and falls through when (at(?) & 0x1) == 0.
  The `beq` branch at 0x3558 targets 0x3534 and is always taken.
  The `bltz` branch at 0x357c targets 0x3598, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `bgez` branch at 0x3590 targets 0x3568, is taken when t1(?) >= 0 (signed), and falls through when t1(?) < 0 (signed).
  The `beq` branch at 0x35a4 targets 0x3544 and is always taken.
  The return at 0x3598 has v0 = ?.

- `ef_phystr` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x35ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x35ac-0x363c (144 bytes).
  It occupies 144 bytes.
  The `beq` branch at 0x35c4 targets 0x361c, is taken when a0 == at(=0x181441), and falls through when a0 != at(=0x181441).
  The `beq` branch at 0x35d4 targets 0x3628, is taken when a0 == v0(=0x15f41), and falls through when a0 != v0(=0x15f41).
  The `beq` branch at 0x35f0 targets 0x3620, is taken when a0 == v1(=0x15f42), and falls through when a0 != v1(=0x15f42).
  The `beq` branch at 0x35f8 targets 0x3630, is taken when a0 == a7(=0x15f43), and falls through when a0 != a7(=0x15f43).
  The `beq` branch at 0x3600 targets 0x3620, is taken when a0 == t0(=0x20005c0), and falls through when a0 != t0(=0x20005c0).
  The `beq` branch at 0x3608 targets 0x3620, is taken when a0 == t2(=0x20005c1), and falls through when a0 != t2(=0x20005c1).
  The return at 0x3614 has v0 = sym(.rodata).
  The return at 0x3620 has v0 = sym(.rodata).
  The return at 0x3628 has v0 = sym(.rodata).
  The return at 0x3634 has v0 = sym(.rodata).

- `ef_dump` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x363c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x363c-0x36e8 (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0x3690 loads 8 bytes from ret(ifunit) +0x110.
  The `jal` at 0x3660 calls sprintf with a0=sp-144, a1=sym(.rodata), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x3668 calls ifunit with a0=sp-144, a1=?, a2=?, a3=?.
  The `jal` at 0x3680 calls qprintf with a0=sym(.rodata), a1=sp-144, a2=?, a3=?.
  The `jal` at 0x3694 calls ef_dumpif with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x36a0 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x36a8 calls ef_dumpei with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x36b4 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x36bc calls ef_dumpregs with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x36c8 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x36d0 calls ef_dumpphy with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x3670 targets 0x3690, is taken when v0(=ret(ifunit)) != 0, and falls through when v0(=ret(ifunit)) == 0.
  The `beq` branch at 0x3688 targets 0x36dc and is always taken.
  The return at 0x36e0 has v0 = one of ret(qprintf), ret(ef_dumpphy).

- `ef_dumpif` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x36e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x36e8-0x3778 (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0x36e8 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x36ec loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x36f0 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `lw` at 0x36f4 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x371c loads 4 bytes from a0 (arg0 at entry) +0xb0.
  The `lw` at 0x3720 loads 4 bytes from a0 (arg0 at entry) +0xac.
  The `lw` at 0x3724 loads 4 bytes from a0 (arg0 at entry) +0xa8.
  The `lh` at 0x3728 loads 2 bytes from a0 (arg0 at entry) +0x1c.
  The `lw` at 0x3734 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x3738 loads 4 bytes from a0 (arg0 at entry) +0x3c.
  The `lw` at 0x373c loads 4 bytes from a0 (arg0 at entry) +0x38.
  The `lw` at 0x3740 loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x374c loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `lw` at 0x3750 loads 4 bytes from a0 (arg0 at entry) +0x4c.
  The `lw` at 0x3754 loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `lw` at 0x3758 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `jal` at 0x3714 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=[a0]:8, a3=[a0+26]:2, a4=[a0+40], a5=[a0+32].
  The `jal` at 0x372c calls qprintf with a0=sym(.rodata), a1=[a0+28]:2, a2=[a0+168], a3=[a0+172], a4=[a0+176].
  The `jal` at 0x3744 calls qprintf with a0=sym(.rodata), a1=[a0+52], a2=[a0+56], a3=[a0+60], a4=[a0+64].
  The `jal` at 0x375c calls qprintf with a0=sym(.rodata), a1=[a0+68], a2=[a0+72], a3=[a0+76], a4=[a0+92].
  The return at 0x3770 has v0 = ret(qprintf).

- `ef_dumpei` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x3778 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x3778-0x38c0 (328 bytes).
  It occupies 328 bytes.
  The `lw` at 0x37a4 loads 4 bytes from a0 (arg0 at entry) +0x3a0.
  The `lw` at 0x37b4 loads 4 bytes from a0 (arg0 at entry) +0x3b0.
  The `lw` at 0x37bc loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `lw` at 0x37c8 loads 4 bytes from a0 (arg0 at entry) +0x3b8.
  The `lw` at 0x37cc loads 4 bytes from a0 (arg0 at entry) +0x358.
  The `ld` at 0x37d0 loads 8 bytes from a0 (arg0 at entry) +0x350.
  The `lw` at 0x37d4 loads 4 bytes from a0 (arg0 at entry) +0x34c.
  The `lw` at 0x37d8 loads 4 bytes from a0 (arg0 at entry) +0x348.
  The `ld` at 0x37dc loads 8 bytes from a0 (arg0 at entry) +0x338.
  The `ld` at 0x37e8 loads 8 bytes from a0 (arg0 at entry) +0x380.
  The `ld` at 0x37ec loads 8 bytes from a0 (arg0 at entry) +0x378.
  The `lw` at 0x37f0 loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x37f4 loads 4 bytes from a0 (arg0 at entry) +0x370.
  The `ld` at 0x37f8 loads 8 bytes from a0 (arg0 at entry) +0x368.
  The `lw` at 0x37fc loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `lw` at 0x3808 loads 4 bytes from a0 (arg0 at entry) +0x3d0.
  The `lw` at 0x380c loads 4 bytes from a0 (arg0 at entry) +0x3c4.
  The `lw` at 0x382c loads 4 bytes from a0 (arg0 at entry) +0x3e0.
  The `lw` at 0x3830 loads 4 bytes from a0 (arg0 at entry) +0x3dc.
  The `lw` at 0x3834 loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  The `lw` at 0x3838 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x3844 loads 4 bytes from a0 (arg0 at entry) +0x3f0.
  The `lw` at 0x3848 loads 4 bytes from a0 (arg0 at entry) +0x3f4.
  The `lw` at 0x384c loads 4 bytes from a0 (arg0 at entry) +0x3ec.
  The `lw` at 0x3850 loads 4 bytes from a0 (arg0 at entry) +0x3e8.
  The `lw` at 0x3854 loads 4 bytes from a0 (arg0 at entry) +0x3e4.
  The `lw` at 0x3860 loads 4 bytes from a0 (arg0 at entry) +0x404.
  The `lw` at 0x3864 loads 4 bytes from a0 (arg0 at entry) +0x400.
  The `lw` at 0x3868 loads 4 bytes from a0 (arg0 at entry) +0x3fc.
  The `lw` at 0x386c loads 4 bytes from a0 (arg0 at entry) +0x3f8.
  The `lw` at 0x3878 loads 4 bytes from a0 (arg0 at entry) +0x41c.
  The `lw` at 0x387c loads 4 bytes from a0 (arg0 at entry) +0x418.
  The `lw` at 0x3880 loads 4 bytes from a0 (arg0 at entry) +0x414.
  The `lw` at 0x3884 loads 4 bytes from a0 (arg0 at entry) +0x410.
  The `lw` at 0x3888 loads 4 bytes from a0 (arg0 at entry) +0x40c.
  The `lw` at 0x388c loads 4 bytes from a0 (arg0 at entry) +0x408.
  The `lw` at 0x3898 loads 4 bytes from a0 (arg0 at entry) +0x428.
  The `lw` at 0x389c loads 4 bytes from a0 (arg0 at entry) +0x424.
  The `lw` at 0x38a0 loads 4 bytes from a0 (arg0 at entry) +0x420.
  The `jal` at 0x378c calls ether_sprintf with a0=a0+240, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x37a8 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=ret(ether_sprintf), a3=[a0+928], a4=a0+400.
  The `jal` at 0x37b0 calls ef_phystr with a0=[a0+944], a1=?, a2=?, a3=?.
  The `jal` at 0x37c4 calls qprintf with a0=sym(.rodata), a1=[a0+948], a2=ret(ef_phystr), a3=[a0+952].
  The `jal` at 0x37e0 calls qprintf with a0=sym(.rodata), a1=[a0+824]:8, a2=[a0+840], a3=[a0+844], a4=[a0+848]:8, a5=[a0+856].
  The `jal` at 0x3800 calls qprintf with a0=sym(.rodata), a1=[a0+864], a2=[a0+872]:8, a3=[a0+880], a4=[a0+884], a5=[a0+888]:8, a6=[a0+896]:8.
  The `jal` at 0x3810 calls qprintf with a0=sym(.rodata), a1=[a0+964], a2=[a0+976], a3=?.
  The `jal` at 0x3824 calls ef_hexdump with a0=sym(.rodata), a1=a0+956, a2=0x8, a3=?.
  The `jal` at 0x383c calls qprintf with a0=sym(.rodata), a1=[a0+968], a2=[a0+972], a3=[a0+988], a4=[a0+992].
  The `jal` at 0x3858 calls qprintf with a0=sym(.rodata), a1=[a0+996], a2=[a0+1000], a3=[a0+1004], a4=[a0+1012], a5=[a0+1008].
  The `jal` at 0x3870 calls qprintf with a0=sym(.rodata), a1=[a0+1016], a2=[a0+1020], a3=[a0+1024], a4=[a0+1028].
  The `jal` at 0x3890 calls qprintf with a0=sym(.rodata), a1=[a0+1032], a2=[a0+1036], a3=[a0+1040], a4=[a0+1044], a5=[a0+1048], a6=[a0+1052].
  The `jal` at 0x38a4 calls qprintf with a0=sym(.rodata), a1=[a0+1056], a2=[a0+1060], a3=[a0+1064].
  The return at 0x38b8 has v0 = ret(qprintf).

- `ef_dumpregs` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x38c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x38c0-0x3980 (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0x38d4 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x38f0 loads 4 bytes from [a0+816]:8 +0x0.
  The `lw` at 0x38f4 loads 4 bytes from [a0+816]:8 +0x4.
  The `lw` at 0x38f8 loads 4 bytes from [a0+816]:8 +0x8.
  The `lw` at 0x3904 loads 4 bytes from [a0+816]:8 +0xc.
  The `lw` at 0x3908 loads 4 bytes from [a0+816]:8 +0x14.
  The `lw` at 0x390c loads 4 bytes from [a0+816]:8 +0x10.
  The `lw` at 0x3910 loads 4 bytes from [a0+816]:8 +0x18.
  The `lw` at 0x391c loads 4 bytes from [a0+816]:8 +0x1c.
  The `lw` at 0x3920 loads 4 bytes from [a0+816]:8 +0x20.
  The `lw` at 0x3924 loads 4 bytes from [a0+816]:8 +0x24.
  The `lw` at 0x3928 loads 4 bytes from [a0+816]:8 +0x28.
  The `lw` at 0x392c loads 4 bytes from [a0+816]:8 +0x30.
  The `lw` at 0x3938 loads 4 bytes from [a0+816]:8 +0x3c.
  The `lw` at 0x393c loads 4 bytes from [a0+816]:8 +0x38.
  The `lw` at 0x3940 loads 4 bytes from [a0+816]:8 +0x40.
  The `lw` at 0x3944 loads 4 bytes from [a0+816]:8 +0x44.
  The `lw` at 0x3950 loads 4 bytes from [a0+816]:8 +0x34.
  The `lw` at 0x3954 loads 4 bytes from [a0+816]:8 +0x4c.
  The `lw` at 0x3958 loads 4 bytes from [a0+816]:8 +0x48.
  The `lw` at 0x395c loads 4 bytes from [a0+816]:8 +0x54.
  The `lw` at 0x3960 loads 4 bytes from [a0+816]:8 +0x50.
  The `jal` at 0x38dc calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x38e8 calls qprintf with a0=sym(.rodata), a1=[a0+816]:8, a2=?, a3=?.
  The `jal` at 0x38fc calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8], a2=[[a0+816]:8+4], a3=[[a0+816]:8+8].
  The `jal` at 0x3914 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+12], a2=[[a0+816]:8+20], a3=[[a0+816]:8+16], a4=[[a0+816]:8+24].
  The `jal` at 0x3930 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+28], a2=[[a0+816]:8+32], a3=[[a0+816]:8+36], a4=[[a0+816]:8+40], a5=[[a0+816]:8+48].
  The `jal` at 0x3948 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+60], a2=[[a0+816]:8+56], a3=[[a0+816]:8+64], a4=[[a0+816]:8+68].
  The `jal` at 0x3964 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+52], a2=[[a0+816]:8+76], a3=[[a0+816]:8+72], a4=[[a0+816]:8+84], a5=[[a0+816]:8+80].
  The return at 0x3978 has v0 = ret(qprintf).

- `ef_dumpphy` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x3980 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x3980-0x3a24 (164 bytes).
  It occupies 164 bytes.
  The `jal` at 0x39bc calls ef_phyget with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x39cc calls qprintf with a0=sym(.rodata), a1=?, a2=ret(ef_phyget), a3=?.
  The `jal` at 0x39e4 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3a00 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x39a4 targets 0x39b8 and is always taken.
  The `beq` branch at 0x39b4 targets 0x39f4, is taken when s0(?) >= 0x20 (signed), and falls through when s0(?) < 0x20 (signed).
  The `bne` branch at 0x39dc targets 0x39ac, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `beq` branch at 0x39ec targets 0x39ac and is always taken.
  The `beq` branch at 0x39f4 targets 0x3a0c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The return at 0x3a1c has v0 = one of ?, ret(qprintf).

- `ef_hexdump` in `IP35/usr/cpu/sysgen/IP35boot/if_ef.o` at 0x3a24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/if_ef.o`.
  Range: 0x3a24-0x3b24 (256 bytes).
  It occupies 256 bytes.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3a64, `lbu` at 0x3a78, `lbu` at 0x3ae8.
  2 such `lbu` accesses load 1 byte from table(sym(.data)) +0x28, including `lbu` at 0x3a70, `lbu` at 0x3a90.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x3a74, `sb` at 0x3a98, `sb` at 0x3aa4.
  The `jal` at 0x3afc calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=sp-528, a3=?, a7=sp-528.
  The `blez` branch at 0x3a50 targets 0x3b10, is taken when t0(?) <= 0 (signed), and falls through when t0(?) > 0 (signed).
  The `beq` branch at 0x3a5c targets 0x3b18 and is always taken.
  The `beq` branch at 0x3aa0 targets 0x3aec, is taken when a5(?) >= t0(?) (signed), and falls through when a5(?) < t0(?) (signed).
  The `bne` branch at 0x3ac4 targets 0x3a64, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x3acc targets 0x3ae4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3adc targets 0x3a64 and is always taken.
  The `beq` branch at 0x3ae4 targets 0x3a68 and is always taken.
  The `beq` branch at 0x3b10 targets 0x3af0 and is always taken.
  The `beq` branch at 0x3b1c targets 0x3aac and is always taken.
  The return at 0x3b08 has v0 = ret(qprintf).
