# Readings: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`

One entry per routine, filed here from the reading batches by binary.

- `ef_txfree_len` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
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

- `ef_setstate` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x98-0xc4 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x98 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `lw` at 0xa0 loads 4 bytes from [a0+272]:8 +0x358.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x358, including `sw` at 0xa8, `sw` at 0xc0.
  The `beq` branch at 0x9c targets 0xb4, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0xac has v0 = ?.
  The return at 0xbc has v0 = ?.

- `ef_ps_register` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0xc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
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

- `if_efopen` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x168 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
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

- `ef_ifattach` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1e4-0x2d0 (236 bytes).
  It occupies 236 bytes.
  The `sh` at 0x1e4 stores 2 bytes to a0 (arg0 at entry) +0x1a.
  The `ld` at 0x200 loads 8 bytes from a0 (arg0 at entry) +0x3a8.
  The `ld` at 0x218 loads 8 bytes from (sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4)) +0x8.
  The `lw` at 0x21c loads 4 bytes from [(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8 +0x740.
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
  The `bne` branch at 0x230 targets 0x244, is taken when v0(=[[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1856]) < 0x7e (signed), and falls through when v0(=[[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1856]) >= 0x7e (signed).
  The `beq` branch at 0x238 targets 0x244, is taken when a6(=[sym(ef_delaydiv)]) == 0, and falls through when a6(=[sym(ef_delaydiv)]) != 0.
  The `beq` branch at 0x244 targets 0x26c, is taken when a5(=[a0+916]) == a0(=-0x1), and falls through when a5(=[a0+916]) != a0(=-0x1).
  The `beq` branch at 0x274 targets 0x280, is taken when (a3(=[sym(if_efdevflag)]) & 0x1000) == 0, and falls through when (a3(=[sym(if_efdevflag)]) & 0x1000) != 0.
  The return at 0x2c8 has v0 = ret(ef_ps_register).

- `if_efinit` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x2d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x2d0-0x2fc (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x2e8 calls pciio_driver_register with a0=0x10a9, a1=0x3, a2=sym(.rodata), a3=0x0.
  The return at 0x2f4 has v0 = ret(pciio_driver_register).

- `if_efattach` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x2fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x2fc-0x614 (792 bytes).
  It occupies 792 bytes.
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
  The `sd` at 0x540 stores 8 bytes to ret(kmem_zalloc) +0x340.
  The `lw` at 0x55c loads 4 bytes from ret(kmem_zalloc) +0x3a0.
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
  The `jal` at 0x538 calls pciio_dmamap_alloc with a0=a0 at entry (arg0), a1=?, a2=0x4, a3=0x2000061.
  The `jal` at 0x560 calls device_inventory_add with a0=?, a1=0x8, a2=0x0, a3=0x13, a4=-0x1, a5=[ret(kmem_zalloc)+928].
  The `jal` at 0x570 calls idbg_addfunc with a0=sym(.rodata), a1=sym(ef_dump), a2=?, a3=?.
  The `jal` at 0x588 calls init_bitlock with a0=ret(kmem_zalloc)+856, a1=0x1000, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x5a4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=ret(hwgraph_char_device_add), a3=?.
  The `jal` at 0x5c0 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x5d0 calls ether_sprintf with a0=sp-56, a1=?, a2=?, a3=?, a4=[sym(showconfig)].
  The `jal` at 0x5e8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=ret(ether_sprintf).
  The `jal` at 0x604 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x310 targets 0x4e8, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `bne` branch at 0x344 targets 0x598, is taken when v0(=ret(hwgraph_char_device_add)) != 0, and falls through when v0(=ret(hwgraph_char_device_add)) == 0.
  The `beq` branch at 0x354 targets 0x4cc, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x394 targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `beq` branch at 0x3bc targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `bne` branch at 0x3d8 targets 0x5b4, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beq` branch at 0x428 targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `beq` branch at 0x454 targets 0x4cc, is taken when v0(=ret(pciio_piotrans_addr)) == 0, and falls through when v0(=ret(pciio_piotrans_addr)) != 0.
  The `bne` branch at 0x48c targets 0x4cc, is taken when v0(=ret(ef_ioc3eaddr)) != 0, and falls through when v0(=ret(ef_ioc3eaddr)) == 0.
  The `bne` branch at 0x4b4 targets 0x5d0, is taken when a4(=[sym(showconfig)]) != 0, and falls through when a4(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x4c4 targets 0x4f0, is taken when v0(=ret(ef_allocef)) == 0, and falls through when v0(=ret(ef_allocef)) != 0.
  The `beq` branch at 0x4e8 targets 0x4d8 and is always taken.
  The `beq` branch at 0x544 targets 0x5f8, is taken when v0(=ret(pciio_dmamap_alloc)) == 0, and falls through when v0(=ret(pciio_dmamap_alloc)) != 0.
  The `beq` branch at 0x590 targets 0x4d8 and is always taken.
  The `beq` branch at 0x5ac targets 0x34c and is always taken.
  The `beq` branch at 0x5c8 targets 0x4cc and is always taken.
  The `beq` branch at 0x5f0 targets 0x4bc and is always taken.
  The `beq` branch at 0x60c targets 0x4cc and is always taken.
  The return at 0x4e0 has v0 = one of -0x1, 0x0, 0xc.

- `ef_detach` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x614 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x614-0x68c (120 bytes).
  It occupies 120 bytes.
  The `jal` at 0x624 calls idbg_delfunc with a0=sym(ef_dump), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x63c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x658 calls hwgraph_fastinfo_set with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x660 calls ef_deallocef with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x66c calls kmem_free with a0=ret(hwgraph_fastinfo_get), a1=0x430, a2=?, a3=?.
  The `beq` branch at 0x634 targets 0x678, is taken when s0(=a0) == at(=-0x1), and falls through when s0(=a0) != at(=-0x1).
  The `bne` branch at 0x644 targets 0x654, is taken when v0(=ret(hwgraph_fastinfo_get)) != 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) == 0.
  The `beq` branch at 0x64c targets 0x678 and is always taken.
  The return at 0x684 has v0 = 0x0.

- `mactoh` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x68c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x68c-0x73c (176 bytes).
  It occupies 176 bytes.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x698, `sb` at 0x6cc, `sb` at 0x6e0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x6b0, `lbu` at 0x6ec.
  The `beq` branch at 0x690 targets 0x72c and is always taken.
  The `beq` branch at 0x6a4 targets 0x724, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0x6bc targets 0x6d0, is taken when a5(?) < 0x61 (signed), and falls through when a5(?) >= 0x61 (signed).
  The `beq` branch at 0x6c8 targets 0x6ec and is always taken.
  The `bne` branch at 0x6d4 targets 0x6e4, is taken when a5(?) < 0x41 (signed), and falls through when a5(?) >= 0x41 (signed).
  The `beq` branch at 0x6dc targets 0x6ec and is always taken.
  The `bne` branch at 0x700 targets 0x710, is taken when t1(?) < 0x61 (signed), and falls through when t1(?) >= 0x61 (signed).
  The `beq` branch at 0x708 targets 0x69c and is always taken.
  The `bne` branch at 0x714 targets 0x698, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x71c targets 0x69c and is always taken.
  The `beq` branch at 0x734 targets 0x6b0 and is always taken.
  The return at 0x724 has v0 = ?.

- `ef_ioc3eaddr` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x73c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x73c-0x790 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x740 loads 8 bytes from a0 (arg0 at entry) +0x398.
  The `lw` at 0x77c loads 4 bytes from a0 (arg0 at entry) +0x38c.
  The `jal` at 0x754 calls nic_get_eaddr with a0=[a0+920]:8+48, a1=[a0+920]:8+52, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x780 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+908], a3=?.
  The `bne` branch at 0x75c targets 0x774, is taken when v0(=ret(nic_get_eaddr)) != 0, and falls through when v0(=ret(nic_get_eaddr)) == 0.
  The `beq` branch at 0x788 targets 0x768 and is always taken.
  The return at 0x76c has v0 = one of 0x0, 0x5.

- `ssram_discovery` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x790 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x790-0x804 (116 bytes).
  It occupies 116 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x790, `ld` at 0x7e0.
  2 such `lw` accesses load 4 bytes from [a0+816]:8 +0x0, including `lw` at 0x794, `lw` at 0x7e8.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x0, including `sw` at 0x7a0, `sw` at 0x7f0.
  The `sw` at 0x7ac stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x7b4 stores 4 bytes to a1 (arg1 at entry) +0x20000.
  The `lw` at 0x7b8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x7d0 loads 4 bytes from a1 (arg1 at entry) +0x20000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3d0, including `sw` at 0x7e4, `sw` at 0x800.
  The `bne` branch at 0x7c8 targets 0x7e0, is taken when at(=0x5555) != v0(?), and falls through when at(=0x5555) == v0(?).
  The `beq` branch at 0x7d8 targets 0x7fc, is taken when a4(=0xaaaa) == a5(?), and falls through when a4(=0xaaaa) != a5(?).
  The return at 0x7f4 has v0 = ?.
  The return at 0x7fc has v0 = ?.

- `ef_allocef` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x804 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x804-0x8c0 (188 bytes).
  It occupies 188 bytes.
  The `ld` at 0x804 loads 8 bytes from a0 (arg0 at entry) +0x338.
  The `sd` at 0x860 stores 8 bytes to a0 (arg0 at entry) +0x338.
  The `sd` at 0x868 stores 8 bytes to a0 (arg0 at entry) +0x350.
  The `sd` at 0x894 stores 8 bytes to a0 (arg0 at entry) +0x368.
  The `sd` at 0x8a4 stores 8 bytes to a0 (arg0 at entry) +0x380.
  The `jal` at 0x838 calls contig_memalloc with a0=0x4, a1=0x4, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0x85c calls kmem_zalloc with a0=0x1000, a1=0x0, a2=?, a3=?.
  The `jal` at 0x874 calls contig_memalloc with a0=0x1, a1=0x1, a2=0x100, a3=?.
  The `jal` at 0x898 calls kmem_zalloc with a0=0x1000, a1=0x0, a2=?, a3=?.
  The `jal` at 0x8b0 calls ef_deallocef with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x818 targets 0x830, is taken when at(=[a0+824]:8) == 0, and falls through when at(=[a0+824]:8) != 0.
  The `beq` branch at 0x840 targets 0x8b0, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0x864 targets 0x8b0, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x87c targets 0x8b0, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0x8a0 targets 0x8b0, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x8a8 targets 0x820 and is always taken.
  The `beq` branch at 0x8b8 targets 0x820 and is always taken.
  The return at 0x828 has v0 = one of 0x0, 0xc.

- `ef_deallocef` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x8c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x8c0-0x904 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0x8c0 loads 8 bytes from a0 (arg0 at entry) +0x350.
  The `ld` at 0x8e4 loads 8 bytes from a0 (arg0 at entry) +0x380.
  The `jal` at 0x8d8 calls kmem_free with a0=[a0+848]:8, a1=0x1000, a2=a2 at entry (arg2), a3=[a0+848]:8.
  The `jal` at 0x8f0 calls kmem_free with a0=[a0+896]:8, a1=0x1000, a2=?, a3=?.
  The `beq` branch at 0x8cc targets 0x8e0, is taken when a3(=[a0+848]:8) == 0, and falls through when a3(=[a0+848]:8) != 0.
  The `beq` branch at 0x8e8 targets 0x8fc, is taken when a0(=[a0+896]:8) == 0, and falls through when a0(=[a0+896]:8) != 0.
  The return at 0x8fc has v0 = one of ?, ret(kmem_free).

- `ef_reclaim` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x904 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x904-0x988 (132 bytes).
  It occupies 132 bytes.
  The `ld` at 0x904 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x908 loads 4 bytes from [a0+816]:8 +0x40.
  The `lw` at 0x910 loads 4 bytes from a0 (arg0 at entry) +0x34c.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x930, `sd` at 0x948, `sd` at 0x95c.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x350, including `ld` at 0x934, `ld` at 0x94c, `ld` at 0x960.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x93c, `ld` at 0x958, `ld` at 0x974.
  The `sw` at 0x984 stores 4 bytes to a0 (arg0 at entry) +0x34c.
  The `beq` branch at 0x91c targets 0x980, is taken when a4(=[a0+844]) == t0(?), and falls through when a4(=[a0+844]) != t0(?).
  The `beq` branch at 0x928 targets 0x94c and is always taken.
  The `beq` branch at 0x944 targets 0x980, is taken when a4(?) == t0(?), and falls through when a4(?) != t0(?).
  The `bne` branch at 0x970 targets 0x930, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x978 targets 0x940 and is always taken.
  The return at 0x980 has v0 = one of 0x0, ?.

- `ef_xinit` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x988 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x988-0x9ec (100 bytes).
  It occupies 100 bytes.
  The `ld` at 0x998 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `jal` at 0x9a8 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x9bc calls ef_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x9d0 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The return at 0x9e4 has v0 = ret(ef_init).

- `ef_init` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x9ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x9ec-0xba8 (444 bytes).
  It occupies 444 bytes.
  The `ld` at 0x9f4 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `sw` at 0xa18 stores 4 bytes to [a0+272]:8 +0x388.
  The `ld` at 0xa24 loads 8 bytes from [a0+272]:8 +0x338.
  The `ld` at 0xa28 loads 8 bytes from [a0+272]:8 +0x368.
  The `sw` at 0xa2c stores 4 bytes to [a0+272]:8 +0x348.
  The `sw` at 0xa38 stores 4 bytes to [a0+272]:8 +0x34c.
  The `sw` at 0xa3c stores 4 bytes to [a0+272]:8 +0x374.
  The `sw` at 0xa48 stores 4 bytes to [a0+272]:8 +0x370.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa90, `ld` at 0xb48, `ld` at 0xb60.
  The `lh` at 0xac0 loads 2 bytes from [a0+272]:8 +0x1a.
  The `lw` at 0xad4 loads 4 bytes from [a0+272]:8 +0x3a0.
  The `lw` at 0xad8 loads 4 bytes from [a0+272]:8 +0x358.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x358, including `sw` at 0xaf8, `sw` at 0xba4.
  The `lw` at 0xb04 loads 4 bytes from [a0+272]:8 +0x20.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x20, including `sw` at 0xb0c, `sw` at 0xb94.
  The `lwu` at 0xb1c loads 4 bytes from [a0+272]:8 +0x374.
  2 such `ld` accesses load 8 bytes from [a0+272]:8 +0x330, including `ld` at 0xb20, `ld` at 0xb74.
  The `sw` at 0xb30 stores 4 bytes to [[a0+272]:8+816]:8 +0x20.
  The `lw` at 0xb34 loads 4 bytes from [a0+272]:8 +0x370.
  The `ld` at 0xb38 loads 8 bytes from [a0+272]:8 +0x380.
  2 such `sd` accesses store 8 bytes to [a0+272]:8 +0x378, including `sd` at 0xb6c, `sd` at 0xb70.
  The `lw` at 0xb78 loads 4 bytes from [[a0+272]:8+816]:8 +0x0.
  The `sw` at 0xb80 stores 4 bytes to [[a0+272]:8+816]:8 +0x0.
  The `sh` at 0xb88 stores 2 bytes to [a0+272]:8 +0x1c.
  The `jal` at 0xa0c calls ef_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa20 calls bzero with a0=[[a0+272]:8+824]:8, a1=0x10000, a2=?, a3=?.
  The `jal` at 0xa34 calls bzero with a0=[[a0+272]:8+872]:8, a1=0x1000, a2=?, a3=?.
  The `jal` at 0xa4c calls ef_ioc3init with a0=[a0+272]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa74 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa8c calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xaa4 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0xacc calls ef_ps_register with a0=[a0+272]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0xb10 calls ef_fill with a0=[a0+272]:8, a1=[[a0+272]:8+32], a2=[[a0+272]:8+928], a3=-0x4.
  The `beq` branch at 0xa60 targets 0xac0, is taken when v0(=ret(ef_ioc3init)) == 0, and falls through when v0(=ret(ef_ioc3init)) != 0.
  The `beq` branch at 0xa80 targets 0xa9c, is taken when s0(=ret(ef_reset)) == 0, and falls through when s0(=ret(ef_reset)) != 0.
  The `bne` branch at 0xa94 targets 0xa8c, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xac4 targets 0xad4, is taken when a0(=[[a0+272]:8+26]:2) == a1(=-0x1), and falls through when a0(=[[a0+272]:8+26]:2) != a1(=-0x1).
  The `blez` branch at 0xaf4 targets 0xb98, is taken when a2(=[[a0+272]:8+928]) <= 0 (signed), and falls through when a2(=[[a0+272]:8+928]) > 0 (signed).
  The `beq` branch at 0xb00 targets 0xb8c, is taken when (a0(?) & 0x2) == 0, and falls through when (a0(?) & 0x2) != 0.
  The `beq` branch at 0xb58 targets 0xb70, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xb68 targets 0xb74 and is always taken.
  The `beq` branch at 0xb84 targets 0xa68 and is always taken.
  The `beq` branch at 0xb90 targets 0xb10 and is always taken.
  The `beq` branch at 0xba0 targets 0xafc and is always taken.
  The return at 0xab8 has v0 = ret(ef_ioc3init).

- `ef_ioc3init` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0xba8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0xba8-0xeb0 (776 bytes).
  It occupies 776 bytes.
  The `ld` at 0xbc8 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0xbf4 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x360, including `sw` at 0xc28, `sw` at 0xc34, `sw` at 0xe24.
  The `lw` at 0xc2c loads 4 bytes from a0 (arg0 at entry) +0x30.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0xc44, `sw` at 0xe38.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3cc, including `lw` at 0xc48, `lw` at 0xda4.
  The `lw` at 0xc50 loads 4 bytes from a0 (arg0 at entry) +0x20.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0xc5c, `sw` at 0xdec.
  The `lw` at 0xc60 loads 4 bytes from sym(ef_fullduplex_ipg) +0x8.
  The `lw` at 0xc64 loads 4 bytes from sym(ef_fullduplex_ipg) +0x4.
  The `lw` at 0xc6c loads 4 bytes from sym(ef_fullduplex_ipg) +0x0.
  The `sw` at 0xc84 stores 4 bytes to [a0+816]:8 +0x28.
  The `sw` at 0xc8c stores 4 bytes to [a0+816]:8 +0x2c.
  The `sw` at 0xc94 stores 4 bytes to [a0+816]:8 +0x18.
  The `lw` at 0xc9c loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `sw` at 0xcac stores 4 bytes to [a0+816]:8 +0xc.
  The `sw` at 0xcb0 stores 4 bytes to [a0+816]:8 +0x24.
  The `lbu` at 0xcb4 loads 1 byte from a0 (arg0 at entry) +0xf1.
  The `lbu` at 0xcb8 loads 1 byte from a0 (arg0 at entry) +0xf3.
  The `lbu` at 0xcbc loads 1 byte from a0 (arg0 at entry) +0xf2.
  The `lbu` at 0xcc4 loads 1 byte from a0 (arg0 at entry) +0xf0.
  The `sw` at 0xce0 stores 4 bytes to [a0+816]:8 +0x4c.
  The `lbu` at 0xce4 loads 1 byte from a0 (arg0 at entry) +0xf5.
  The `lbu` at 0xcf0 loads 1 byte from a0 (arg0 at entry) +0xf4.
  The `sw` at 0xd04 stores 4 bytes to [a0+816]:8 +0x48.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x54, including `sw` at 0xd08, `sw` at 0xe64.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x50, including `sw` at 0xd0c, `sw` at 0xe94.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x38c, including `lw` at 0xd28, `lw` at 0xd4c, `lw` at 0xd7c.
  The `ld` at 0xd38 loads 8 bytes from a0 (arg0 at entry) +0x368.
  The `sw` at 0xd58 stores 4 bytes to [a0+816]:8 +0x14.
  The `sw` at 0xd60 stores 4 bytes to [a0+816]:8 +0x10.
  The `ld` at 0xd68 loads 8 bytes from a0 (arg0 at entry) +0x338.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x3c, including `sw` at 0xd88, `sw` at 0xda0.
  The `sw` at 0xd90 stores 4 bytes to [a0+816]:8 +0x38.
  The `lw` at 0xd94 loads 4 bytes from [a0+816]:8 +0x3c.
  The `lw` at 0xdb4 loads 4 bytes from a0 (arg0 at entry) +0x3d0.
  The `sw` at 0xdc4 stores 4 bytes to [a0+816]:8 +0x0.
  The `sw` at 0xdd0 stores 4 bytes to [a0+816]:8 +0x8.
  The `lw` at 0xdf4 loads 4 bytes from sym(ef_halfduplex_ipg) +0x4.
  The `lw` at 0xdf8 loads 4 bytes from sym(ef_halfduplex_ipg) +0x8.
  The `lw` at 0xe00 loads 4 bytes from sym(ef_halfduplex_ipg) +0x0.
  The `lbu` at 0xe3c loads 1 byte from a0 (arg0 at entry) +0x3bd.
  The `lbu` at 0xe40 loads 1 byte from a0 (arg0 at entry) +0x3be.
  The `lbu` at 0xe48 loads 1 byte from a0 (arg0 at entry) +0x3bf.
  The `lbu` at 0xe50 loads 1 byte from a0 (arg0 at entry) +0x3bc.
  The `lbu` at 0xe68 loads 1 byte from a0 (arg0 at entry) +0x3c1.
  The `lbu` at 0xe6c loads 1 byte from a0 (arg0 at entry) +0x3c2.
  The `lbu` at 0xe74 loads 1 byte from a0 (arg0 at entry) +0x3c3.
  The `lbu` at 0xe7c loads 1 byte from a0 (arg0 at entry) +0x3c0.
  The `lh` at 0xe9c loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `jal` at 0xbc4 calls ef_phyinit with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbe8 calls ef_phyerr with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xc80 calls microtime with a0=sp-80, a1=?, a2=?, a3=?, a7=0x5f50000.
  The `jal` at 0xd24 calls pcibr_rrb_alloc with a0=[a0+908], a1=sp-64, a2=sp-60, a3=?, a4=([a0+244]:1 | ([a0+245]:1 << 0x8)), a6=([a0+245]:1 << 0x8).
  The `jal` at 0xd34 calls kvtophys with a0=[a0+872]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xd50 calls pciio_dmatrans_addr with a0=[a0+908], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000050.
  The `jal` at 0xd64 calls kvtophys with a0=[a0+824]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xd80 calls pciio_dmatrans_addr with a0=[a0+908], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000050.
  The `jal` at 0xdcc calls flushbus with a0=?, a1=?, a2=?, a3=?, a4=([[a0+816]:8+60] | 0x1), a6=0x7fe003f.
  The `jal` at 0xea0 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `beq` branch at 0xbcc targets 0xbe8, is taken when v0(=ret(ef_phyinit)) == 0, and falls through when v0(=ret(ef_phyinit)) != 0.
  The `beq` branch at 0xc18 targets 0xe14, is taken when (at(=a1) & 0x100) == 0, and falls through when (at(=a1) & 0x100) != 0.
  The `beq` branch at 0xc38 targets 0xe28, is taken when v0(=[a0+968]) == 0, and falls through when v0(=[a0+968]) != 0.
  The `beq` branch at 0xc4c targets 0xddc, is taken when a0(=[a0+972]) == 0, and falls through when a0(=[a0+972]) != 0.
  The `beq` branch at 0xc58 targets 0xdf0, is taken when a0(=[a0+972]) == 0, and falls through when a0(=[a0+972]) != 0.
  The `beq` branch at 0xd00 targets 0xe3c, is taken when (a5(=a1) & 0x200) == 0, and falls through when (a5(=a1) & 0x200) != 0.
  The `bltz` branch at 0xd2c targets 0xe98, is taken when v0(=ret(pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0xda8 targets 0xdb4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xdd4 targets 0xbd4 and is always taken.
  The `bne` branch at 0xde8 targets 0xc60, is taken when a0(=[a0+972]) != 0, and falls through when a0(=[a0+972]) == 0.
  The `beq` branch at 0xe0c targets 0xc7c and is always taken.
  The `beq` branch at 0xe20 targets 0xc2c and is always taken.
  The `beq` branch at 0xe34 targets 0xc48 and is always taken.
  The `beq` branch at 0xe90 targets 0xd10 and is always taken.
  The `beq` branch at 0xea8 targets 0xd34 and is always taken.
  The return at 0xbe0 has v0 = one of ret(ef_phyinit), 0x0.

- `ef_phyunreset` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0xeb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0xeb0-0xf20 (112 bytes).
  It occupies 112 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x398, including `ld` at 0xeb0, `ld` at 0xebc, `ld` at 0xed4.
  2 such `sw` accesses store 4 bytes to [a0+920]:8 +0x54, including `sw` at 0xeb4, `sw` at 0xef8.
  2 such `lw` accesses load 4 bytes from [a0+920]:8 +0x54, including `lw` at 0xec4, `lw` at 0xf00.
  The `sw` at 0xed0 stores 4 bytes to [a0+920]:8 +0x34.
  The `lw` at 0xee0 loads 4 bytes from [a0+920]:8 +0x34.
  The `jal` at 0xee8 calls us_delay with a0=0xa, a1=[[a0+920]:8+84], a2=[a0+920]:8, a3=a3 at entry (arg3).
  The `jal` at 0xf08 calls us_delay with a0=0x1f4, a1=?, a2=?, a3=[[a0+920]:8+84], a4=0x1, a5=[a0+920]:8.
  The return at 0xf18 has v0 = ret(us_delay).

- `ef_phyprobe` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0xf20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0xf20-0x1054 (308 bytes).
  It occupies 308 bytes.
  The `lw` at 0xf40 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `lw` at 0xf5c loads 4 bytes from a0 (arg0 at entry) +0x3b0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3b4, including `sw` at 0xfd4, `sw` at 0x1040.
  The `sw` at 0x1028 stores 4 bytes to a0 (arg0 at entry) +0x3b8.
  The `sw` at 0x1030 stores 4 bytes to a0 (arg0 at entry) +0x3b0.
  The `lh` at 0x1034 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `jal` at 0xfd0 calls ef_phyget with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0xfe0 calls ef_phyget with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x1044 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=-0x1, a4=(ret(ef_phyget) << 0xc).
  The `beq` branch at 0xf54 targets 0xf94, is taken when at(=[a0+948]) == v0(=-0x1), and falls through when at(=[a0+948]) != v0(=-0x1).
  The `beq` branch at 0xfb8 targets 0xfc8 and is always taken.
  The `beq` branch at 0xfc0 targets 0x1034, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xff8 targets 0x1024, is taken when a3(?) == s3(=0x15f41), and falls through when a3(?) != s3(=0x15f41).
  The `beq` branch at 0x1000 targets 0x1028, is taken when a3(?) == s4(=0x15f42), and falls through when a3(?) != s4(=0x15f42).
  The `beq` branch at 0x1008 targets 0x1028, is taken when a3(?) == s5(=0x15f43), and falls through when a3(?) != s5(=0x15f43).
  The `beq` branch at 0x1010 targets 0x1028, is taken when a3(?) == s6(=0x181441), and falls through when a3(?) != s6(=0x181441).
  The `beq` branch at 0x1018 targets 0x1028, is taken when a3(?) == s7(=0x20005c0), and falls through when a3(?) != s7(=0x20005c0).
  The `bne` branch at 0x1020 targets 0xfc0, is taken when a3(?) != s8(=0x20005c1), and falls through when a3(?) == s8(=0x20005c1).
  The `beq` branch at 0x102c targets 0xf60 and is always taken.
  The `beq` branch at 0x104c targets 0xf60 and is always taken.
  The return at 0xf8c has v0 = one of [a0+944], ?, -0x1.

- `ef_phymode` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1054 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1054-0x1334 (736 bytes).
  It occupies 736 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3b0, including `lw` at 0x10c0, `lw` at 0x11d0.
  13 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x1140, `sw` at 0x117c, `sw` at 0x11bc.
  13 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x1148, `sw` at 0x1180, `sw` at 0x11c4.
  The `jal` at 0x1078 calls ef_phyget with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1088 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x1098 calls ef_phyget with a0=a0 at entry (arg0), a1=0x6, a2=?, a3=?.
  The `jal` at 0x1108 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1f, a2=0x20005c1, a3=0x15f41, a4=0x15f42, a5=0x15f43, a6=0x181441.
  The `jal` at 0x114c calls ef_phyget with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0x115c calls ef_phyget with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x11a8 calls ef_phyget with a0=a0 at entry (arg0), a1=0x11, a2=0x20005c1, a3=0x15f41, a4=0x15f42.
  The `jal` at 0x11e4 calls ef_phyget with a0=a0 at entry (arg0), a1=0x11, a2=?, a3=?.
  The `jal` at 0x1234 calls ef_phyget with a0=a0 at entry (arg0), a1=0x19, a2=0x20005c1, a3=?.
  The `jal` at 0x1274 calls ef_phyget with a0=a0 at entry (arg0), a1=0x10, a2=0x20005c1, a3=?.
  The `jal` at 0x128c calls ef_phyget with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `jal` at 0x1314 calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0xefff, a3=?.
  The `jal` at 0x1324 calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0x1000, a3=?.
  The `beq` branch at 0x10a4 targets 0x1250, is taken when (s3(=ret(ef_phyget)) & 0x1000) == 0, and falls through when (s3(=ret(ef_phyget)) & 0x1000) != 0.
  The `beq` branch at 0x10b0 targets 0x11d0, is taken when (v1(=ret(ef_phyget)) & 0x20) == 0, and falls through when (v1(=ret(ef_phyget)) & 0x20) != 0.
  The `bne` branch at 0x10b8 targets 0x114c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x10cc targets 0x1230, is taken when v0(=[a0+944]) == a1(=0x20005c0), and falls through when v0(=[a0+944]) != a1(=0x20005c0).
  The `beq` branch at 0x10d4 targets 0x1270, is taken when v0(=[a0+944]) == a2(=0x20005c1), and falls through when v0(=[a0+944]) != a2(=0x20005c1).
  The `beq` branch at 0x10e0 targets 0x11a4, is taken when v0(=[a0+944]) == a3(=0x15f41), and falls through when v0(=[a0+944]) != a3(=0x15f41).
  The `beq` branch at 0x10e8 targets 0x11a4, is taken when v0(=[a0+944]) == a4(=0x15f42), and falls through when v0(=[a0+944]) != a4(=0x15f42).
  The `beq` branch at 0x10f0 targets 0x11a8, is taken when v0(=[a0+944]) == a5(=0x15f43), and falls through when v0(=[a0+944]) != a5(=0x15f43).
  The `bne` branch at 0x1100 targets 0x11c8, is taken when v0(=[a0+944]) != a6(=0x181441), and falls through when v0(=[a0+944]) == a6(=0x181441).
  The `beq` branch at 0x1120 targets 0x12e4, is taken when a0(?) == a7(=0x4), and falls through when a0(?) != a7(=0x4).
  The `beq` branch at 0x1128 targets 0x12f0, is taken when a0(?) == a2(=0x8), and falls through when a0(?) != a2(=0x8).
  The `beq` branch at 0x1130 targets 0x12fc, is taken when a0(?) == a4(=0x14), and falls through when a0(?) != a4(=0x14).
  The `bne` branch at 0x1138 targets 0x11c8, is taken when a0(?) != a5(=0x18), and falls through when a0(?) == a5(=0x18).
  The `beq` branch at 0x1144 targets 0x11c8 and is always taken.
  The `beq` branch at 0x1168 targets 0x120c, is taken when (s3(=ret(ef_phyget)) & 0x100) == 0, and falls through when (s3(=ret(ef_phyget)) & 0x100) != 0.
  The `beq` branch at 0x1170 targets 0x1210, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x11c8 targets 0x1188 and is always taken.
  The `bne` branch at 0x11dc targets 0x11f8, is taken when ra(=[a0+944]) != at(=0x15f42), and falls through when ra(=[a0+944]) == at(=0x15f42).
  The `beq` branch at 0x11f4 targets 0x130c, is taken when v0(?) == v1(=0x1000), and falls through when v0(?) != v1(=0x1000).
  The `beq` branch at 0x1204 targets 0x1188 and is always taken.
  The `beq` branch at 0x1210 targets 0x12a4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x121c targets 0x12a0, is taken when (v0(=ret(ef_phyget)) & 0x80) == 0, and falls through when (v0(=ret(ef_phyget)) & 0x80) != 0.
  The `beq` branch at 0x1228 targets 0x1184 and is always taken.
  The `beq` branch at 0x1248 targets 0x11c8 and is always taken.
  The `beq` branch at 0x1268 targets 0x1188 and is always taken.
  The `beq` branch at 0x1298 targets 0x11c8 and is always taken.
  The `beq` branch at 0x12a8 targets 0x12c4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x12b0 targets 0x12c8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x12bc targets 0x1184 and is always taken.
  The `beq` branch at 0x12c8 targets 0x1184, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x12d0 targets 0x1188, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x12dc targets 0x1184 and is always taken.
  The `beq` branch at 0x12e8 targets 0x11c8 and is always taken.
  The `beq` branch at 0x12f4 targets 0x11c8 and is always taken.
  The `beq` branch at 0x1304 targets 0x11c8 and is always taken.
  The `beq` branch at 0x132c targets 0x11fc and is always taken.
  The return at 0x119c has v0 = one of 0x0, 0x10.

- `ef_phyreset` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1334 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1334-0x136c (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0x133c calls ef_phyprobe with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1350 calls ef_phyerrat with a0=a0 at entry (arg0), a1=?, a2=?, a3=-0x1.
  The `beq` branch at 0x1348 targets 0x135c, is taken when v0(=ret(ef_phyprobe)) == at(=-0x1), and falls through when v0(=ret(ef_phyprobe)) != at(=-0x1).
  The return at 0x1364 has v0 = one of -0x1, 0x0.

- `ef_phyinit` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x136c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x136c-0x14bc (336 bytes).
  It occupies 336 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0x136c, `lh` at 0x1418.
  The `lw` at 0x13dc loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x13ec loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x13f8, `lw` at 0x1430.
  The `sw` at 0x1464 stores 4 bytes to a0 (arg0 at entry) +0x3c8.
  The `sw` at 0x1470 stores 4 bytes to a0 (arg0 at entry) +0x3cc.
  The `jal` at 0x1380 calls ef_phyreset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x13b0 calls ef_phymode with a0=a0 at entry (arg0), a1=a0+968, a2=a0+972, a3=?.
  The `jal` at 0x13c4 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0x13d0 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x1420 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=one of 0xa, 0x64, a3=sym(.rodata).
  The `jal` at 0x1448 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a6=[a0+968].
  The `jal` at 0x1458 calls ef_phyput with a0=a0 at entry (arg0), a1=0x0, a2=0x1000, a3=?.
  The `jal` at 0x1480 calls us_delay with a0=0x64, a1=?, a2=?, a3=?.
  The `jal` at 0x14a0 calls ef_phymode with a0=a0 at entry (arg0), a1=a0+968, a2=a0+972, a3=?.
  The `beq` branch at 0x1388 targets 0x13a0, is taken when v0(=ret(ef_phyreset)) == 0, and falls through when v0(=ret(ef_phyreset)) != 0.
  The `beq` branch at 0x13bc targets 0x147c, is taken when v0(=ret(ef_phymode)) == a0(=0x10), and falls through when v0(=ret(ef_phymode)) != a0(=0x10).
  The `beq` branch at 0x13e4 targets 0x1430, is taken when a6(=[a0+968]) == a1(=-0x1), and falls through when a6(=[a0+968]) != a1(=-0x1).
  The `beq` branch at 0x13f0 targets 0x1430, is taken when a0(=[a0+972]) == a1(=-0x1), and falls through when a0(=[a0+972]) != a1(=-0x1).
  The `beq` branch at 0x1400 targets 0x1428, is taken when (v0(=[a0+32]) & 0x4) == 0, and falls through when (v0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1408 targets 0x1474, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1428 targets 0x1390 and is always taken.
  The `beq` branch at 0x1438 targets 0x1454, is taken when (a0(=[a0+32]) & 0x4) == 0, and falls through when (a0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x146c targets 0x13f8 and is always taken.
  The `beq` branch at 0x1474 targets 0x1410 and is always taken.
  The `bltz` branch at 0x1490 targets 0x13c4, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `beq` branch at 0x14ac targets 0x1480, is taken when v0(=ret(ef_phymode)) == a3(=0x10), and falls through when v0(=ret(ef_phymode)) != a3(=0x10).
  The `beq` branch at 0x14b4 targets 0x13c4 and is always taken.
  The return at 0x1398 has v0 = one of 0x0, 0x5.

- `ef_phyupdate` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x14bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x14bc-0x1520 (100 bytes).
  It occupies 100 bytes.
  The `lw` at 0x14e4 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x14f0 loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  The `lw` at 0x1508 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x14d4 calls ef_phymode with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=a3 at entry (arg3).
  The `jal` at 0x1510 calls ef_init with a0=a0 at entry (arg0), a1=[a0+32], a2=a1 at entry (arg1), a3=?.
  The `bne` branch at 0x14dc targets 0x14f8, is taken when v0(=ret(ef_phymode)) != 0, and falls through when v0(=ret(ef_phymode)) == 0.
  The `bne` branch at 0x14e8 targets 0x1508, is taken when at(=[a0+968]) != v0(?), and falls through when at(=[a0+968]) == v0(?).
  The `bne` branch at 0x14f4 targets 0x1508, is taken when v1(=[a0+972]) != a0(?), and falls through when v1(=[a0+972]) == a0(?).
  The `beq` branch at 0x1518 targets 0x14fc and is always taken.
  The return at 0x1500 has v0 = one of ?, ret(ef_init).

- `ef_phyerr` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1520 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1520-0x16fc (476 bytes).
  It occupies 476 bytes.
  The `lh` at 0x1528 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x1554 loads 4 bytes from a0 (arg0 at entry) +0x3dc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3dc, including `sw` at 0x1560, `sw` at 0x1610.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x358, including `lw` at 0x1570, `lw` at 0x15a8, `lw` at 0x1688.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3e0, including `lw` at 0x1580, `lw` at 0x1630.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x158c, `lw` at 0x15f0, `lw` at 0x167c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3e0, including `sw` at 0x15ac, `sw` at 0x1644.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x358, including `sw` at 0x15cc, `sw` at 0x1620, `sw` at 0x16a4.
  The `lw` at 0x1624 loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0x1698, `sw` at 0x16dc.
  The `jal` at 0x1540 calls ef_phyget with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x15a0 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x1604 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x1654 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x1670 calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x16a0 calls ef_phyupdate with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=[a0+856], a5=0xfffffffffff7ffff.
  The `jal` at 0x16c0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x16e8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=[a0+968], a4=[a0+992].
  The `beq` branch at 0x1550 targets 0x15e8, is taken when (v0(=ret(ef_phyget)) & 0x10) == 0, and falls through when (v0(=ret(ef_phyget)) & 0x10) != 0.
  The `beq` branch at 0x1558 targets 0x1648, is taken when a0(=[a0+988]) == 0, and falls through when a0(=[a0+988]) != 0.
  The `beq` branch at 0x1568 targets 0x1580, is taken when (s2(=ret(ef_phyget)) & 0x2) == 0, and falls through when (s2(=ret(ef_phyget)) & 0x2) != 0.
  The `beq` branch at 0x1578 targets 0x1624, is taken when (a0(=[a0+856]) & 0x4) == 0, and falls through when (a0(=[a0+856]) & 0x4) != 0.
  The `beq` branch at 0x1584 targets 0x15a8, is taken when a0(=[a0+992]) == 0, and falls through when a0(=[a0+992]) != 0.
  The `beq` branch at 0x1594 targets 0x15a8, is taken when (a1(=[a0+32]) & 0x4) == 0, and falls through when (a1(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x15b8 targets 0x1614, is taken when (s2(=ret(ef_phyget)) & 0x4) == 0, and falls through when (s2(=ret(ef_phyget)) & 0x4) != 0.
  The `bne` branch at 0x15c0 targets 0x1664, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x15e8 targets 0x160c, is taken when a0(=[a0+988]) == 0, and falls through when a0(=[a0+988]) != 0.
  The `beq` branch at 0x15f8 targets 0x160c, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x160c targets 0x1564 and is always taken.
  The `beq` branch at 0x1614 targets 0x16b4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x161c targets 0x15d0 and is always taken.
  The `bne` branch at 0x1628 targets 0x1580, is taken when a3(=[a0+968]) != 0, and falls through when a3(=[a0+968]) == 0.
  The `beq` branch at 0x1634 targets 0x16e0, is taken when a4(=[a0+992]) == 0, and falls through when a4(=[a0+992]) != 0.
  The `beq` branch at 0x1640 targets 0x15b4 and is always taken.
  The `beq` branch at 0x165c targets 0x1560 and is always taken.
  The `beq` branch at 0x16ac targets 0x15c8 and is always taken.
  The `beq` branch at 0x16d8 targets 0x1618 and is always taken.
  The `beq` branch at 0x16f4 targets 0x163c and is always taken.
  The return at 0x15e0 has v0 = one of -0x5, ?.

- `ef_phyget` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x16fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x16fc-0x1794 (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x1704 loads 8 bytes from a0 (arg0 at entry) +0x330.
  4 such `lw` accesses load 4 bytes from [a0+816]:8 +0x58, including `lw` at 0x1708, `lw` at 0x172c, `lw` at 0x1750.
  The `lw` at 0x173c loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `sw` at 0x174c stores 4 bytes to [a0+816]:8 +0x58.
  The `lw` at 0x1780 loads 4 bytes from [a0+816]:8 +0x5c.
  The `jal` at 0x1724 calls us_delaybus with a0=0x1, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1760 calls us_delaybus with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x171c targets 0x173c, is taken when (at(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (at(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x1734 targets 0x1724, is taken when (v0(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (v0(=[[a0+816]:8+88]) & 0x800) == 0.
  The `beq` branch at 0x1758 targets 0x177c, is taken when (v1(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (v1(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x1770 targets 0x1760, is taken when (a1(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (a1(=[[a0+816]:8+88]) & 0x800) == 0.
  The return at 0x178c has v0 = ?.

- `ef_phyput` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1794 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1794-0x182c (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x179c loads 8 bytes from a0 (arg0 at entry) +0x330.
  4 such `lw` accesses load 4 bytes from [a0+816]:8 +0x58, including `lw` at 0x17a0, `lw` at 0x17c8, `lw` at 0x17f0.
  The `sw` at 0x17dc stores 4 bytes to [a0+816]:8 +0x60.
  The `lw` at 0x17e0 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `sw` at 0x17ec stores 4 bytes to [a0+816]:8 +0x58.
  The `jal` at 0x17c0 calls us_delaybus with a0=0x1, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1800 calls us_delaybus with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x17b8 targets 0x17dc, is taken when (at(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (at(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x17d0 targets 0x17c0, is taken when (v0(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (v0(=[[a0+816]:8+88]) & 0x800) == 0.
  The `beq` branch at 0x17f8 targets 0x181c, is taken when (v1(=[[a0+816]:8+88]) & 0x800) == 0, and falls through when (v1(=[[a0+816]:8+88]) & 0x800) != 0.
  The `bne` branch at 0x1810 targets 0x1800, is taken when (a1(=[[a0+816]:8+88]) & 0x800) != 0, and falls through when (a1(=[[a0+816]:8+88]) & 0x800) == 0.
  The return at 0x1824 has v0 = one of ?, ret(us_delaybus).

- `ef_phyrmw` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x182c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x182c-0x1884 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x1844 calls ef_phyget with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x186c calls ef_phyput with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=a3 at entry (arg3).
  The return at 0x187c has v0 = ret(ef_phyput).

- `ef_phyerrat` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1884 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1884-0x1964 (224 bytes).
  It occupies 224 bytes.
  The `lw` at 0x1898 loads 4 bytes from sym(ef_phyerrata) +0x4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3b0, including `lw` at 0x18c4, `lw` at 0x18dc.
  The `lw` at 0x18d0 loads 4 bytes from sym(ef_phyerrata) +0x14.
  2 such `lh` accesses load 2 bytes from sym(ef_phyerrata) +0x8, including `lh` at 0x18e8, `lh` at 0x1960.
  The `lw` at 0x18f4 loads 4 bytes from a0 (arg0 at entry) +0x3b8.
  The `lw` at 0x1900 loads 4 bytes from sym(ef_phyerrata) +0x0.
  The `lh` at 0x190c loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lhu` at 0x1918 loads 2 bytes from sym(ef_phyerrata) +0xa.
  The `lhu` at 0x191c loads 2 bytes from sym(ef_phyerrata) +0xc.
  The `lhu` at 0x1928 loads 2 bytes from sym(ef_phyerrata) +0xe.
  The `jal` at 0x1924 calls ef_phyrmw with a0=a0 at entry (arg0), a1=[sym(ef_phyerrata)+10]:2, a2=[sym(ef_phyerrata)+12]:2, a3=[sym(ef_phyerrata)+14]:2.
  The `beq` branch at 0x18b8 targets 0x1938, is taken when a2(=[sym(ef_phyerrata)+4]) == 0, and falls through when a2(=[sym(ef_phyerrata)+4]) != 0.
  The `beq` branch at 0x18c0 targets 0x18e0 and is always taken.
  The `beq` branch at 0x18c8 targets 0x1954, is taken when s2(=0x15f42) == a2(?), and falls through when s2(=0x15f42) != a2(?).
  The `beq` branch at 0x18d4 targets 0x1938, is taken when a2(=[sym(ef_phyerrata)+20]) == 0, and falls through when a2(=[sym(ef_phyerrata)+20]) != 0.
  The `bne` branch at 0x18e0 targets 0x18c8, is taken when a2(?) != a0(=[a0+944]), and falls through when a2(?) == a0(=[a0+944]).
  The `beq` branch at 0x18ec targets 0x1900, is taken when a0(=[sym(ef_phyerrata)+8]:2) == s3(=-0x1), and falls through when a0(=[sym(ef_phyerrata)+8]:2) != s3(=-0x1).
  The `bne` branch at 0x18f8 targets 0x18d0, is taken when a0(=[sym(ef_phyerrata)+8]:2) != at(=[a0+952]), and falls through when a0(=[sym(ef_phyerrata)+8]:2) == at(=[a0+952]).
  The `beq` branch at 0x1904 targets 0x1918, is taken when a0(=[sym(ef_phyerrata)]) == s3(=-0x1), and falls through when a0(=[sym(ef_phyerrata)]) != s3(=-0x1).
  The `bne` branch at 0x1910 targets 0x18d0, is taken when v0(=[a0+26]:2) != a0(=[sym(ef_phyerrata)]), and falls through when v0(=[a0+26]:2) == a0(=[sym(ef_phyerrata)]).
  The `beq` branch at 0x1930 targets 0x18d0 and is always taken.
  The `bne` branch at 0x1954 targets 0x18d0, is taken when a3(=0x15f43) != a0(=[a0+944]), and falls through when a3(=0x15f43) == a0(=[a0+944]).
  The `beq` branch at 0x195c targets 0x18ec and is always taken.
  The return at 0x194c has v0 = ?.

- `ef_fill` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1964 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1964-0x1a70 (268 bytes).
  It occupies 268 bytes.
  The `lw` at 0x1964 loads 4 bytes from a0 (arg0 at entry) +0x370.
  The `lw` at 0x1970 loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x1978 loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `ld` at 0x19bc loads 8 bytes from ret(m_vget) +0x8.
  The `sw` at 0x19c4 stores 4 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x0.
  The `sw` at 0x19c8 stores 4 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x4.
  The `ld` at 0x19cc loads 8 bytes from a0 (arg0 at entry) +0x380.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x19dc, `sd` at 0x1a0c.
  The `ld` at 0x19e4 loads 8 bytes from a0 (arg0 at entry) +0x340.
  The `ld` at 0x19f0 loads 8 bytes from a0 (arg0 at entry) +0x368.
  The `ld` at 0x1a10 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `sw` at 0x1a14 stores 4 bytes to a0 (arg0 at entry) +0x374.
  The `sw` at 0x1a20 stores 4 bytes to [a0+816]:8 +0x20.
  The `lw` at 0x1a44 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lh` at 0x1a54 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x1a60 loads 4 bytes from a0 (arg0 at entry) +0x420.
  The `sw` at 0x1a6c stores 4 bytes to a0 (arg0 at entry) +0x420.
  The `jal` at 0x19ac calls m_vget with a0=0x0, a1=0x800, a2=0x1, a3=?.
  The `jal` at 0x19d8 calls kvtophys with a0=([ret(m_vget)+8]:8 + ret(m_vget)), a1=?, a2=?, a3=?.
  The `jal` at 0x19e8 calls pciio_dmamap_addr with a0=[a0+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x1a1c calls flushbus with a0=?, a1=?, a2=?, a3=[a0+816]:8.
  The `jal` at 0x1a58 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `blez` branch at 0x199c targets 0x1a10, is taken when s4(?) <= 0 (signed), and falls through when s4(?) > 0 (signed).
  The `beq` branch at 0x19b4 targets 0x1a44, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `bne` branch at 0x1a08 targets 0x19a4, is taken when s2(?) < s4(?) (signed), and falls through when s2(?) >= s4(?) (signed).
  The `beq` branch at 0x1a4c targets 0x1a60, is taken when (a4(=[a0+32]) & 0x4) == 0, and falls through when (a4(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x1a68 targets 0x1a10 and is always taken.
  The return at 0x1a3c has v0 = ret(flushbus).

- `ef_xreset` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1a70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1a70-0x1aec (124 bytes).
  It occupies 124 bytes.
  The `ld` at 0x1a78 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x1ad0 loads 8 bytes from ?.
  The `jal` at 0x1a94 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1aa0 calls ef_reset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1ab4 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1acc calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1ac0 targets 0x1adc, is taken when s0(=ret(ef_reset)) == 0, and falls through when s0(=ret(ef_reset)) != 0.
  The `bne` branch at 0x1ad4 targets 0x1acc, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1ae4 has v0 = one of ret(mutex_bitunlock), ret(m_freem).

- `ef_reset` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1aec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1aec-0x1bec (256 bytes).
  It occupies 256 bytes.
  The `ld` at 0x1af4 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `sh` at 0x1af8 stores 2 bytes to a0 (arg0 at entry) +0x1c.
  The `sw` at 0x1b1c stores 4 bytes to [a0+272]:8 +0x34c.
  6 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1b28, `sd` at 0x1b3c, `sd` at 0x1b60.
  3 such `ld` accesses load 8 bytes from [a0+272]:8 +0x350, including `ld` at 0x1b2c, `ld` at 0x1b48, `ld` at 0x1b64.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1b34, `ld` at 0x1b50, `ld` at 0x1b70.
  3 such `ld` accesses load 8 bytes from [a0+272]:8 +0x380, including `ld` at 0x1b88, `ld` at 0x1ba4, `ld` at 0x1bc0.
  The `sd` at 0x1bdc stores 8 bytes to [a0+272]:8 +0x378.
  The `jal` at 0x1b00 calls ef_getcdc with a0=[a0+272]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b08 calls ef_ioc3reset with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1b20 targets 0x1b44 and is always taken.
  The `beq` branch at 0x1b40 targets 0x1b7c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1b58 targets 0x1b40, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1b6c targets 0x1b28, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1b74 targets 0x1b38 and is always taken.
  The `beq` branch at 0x1b7c targets 0x1ba0 and is always taken.
  The `beq` branch at 0x1b9c targets 0x1bd8, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1bb4 targets 0x1b9c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1bc8 targets 0x1b84, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1bd0 targets 0x1b94 and is always taken.
  The return at 0x1be4 has v0 = ?.

- `ef_ioc3reset` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1bec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1bec-0x1cbc (208 bytes).
  It occupies 208 bytes.
  8 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x1bec, `ld` at 0x1bf8, `ld` at 0x1c2c.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x0, including `sw` at 0x1bf4, `sw` at 0x1c28.
  3 such `lw` accesses load 4 bytes from [a0+816]:8 +0x0, including `lw` at 0x1bfc, `lw` at 0x1c04, `lw` at 0x1c8c.
  The `sw` at 0x1c30 stores 4 bytes to [a0+816]:8 +0x40.
  The `sw` at 0x1c38 stores 4 bytes to [a0+816]:8 +0x1c.
  The `sw` at 0x1c44 stores 4 bytes to [a0+816]:8 +0x44.
  The `sw` at 0x1c54 stores 4 bytes to [a0+816]:8 +0x20.
  The `lh` at 0x1ca8 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `jal` at 0x1c50 calls flushbus with a0=?, a1=?, a2=[a0+816]:8, a3=[a0+816]:8, a4=[a0+816]:8, a5=[a0+816]:8.
  The `jal` at 0x1c70 calls us_delay with a0=0x1, a1=?, a2=[a0+816]:8, a3=?.
  The `jal` at 0x1cac calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `bgez` branch at 0x1c20 targets 0x1c68, is taken when at(=([[a0+816]:8] << 0x2a)) >= 0 (signed), and falls through when at(=([[a0+816]:8] << 0x2a)) < 0 (signed).
  The `beq` branch at 0x1c80 targets 0x1ca4, is taken when s1(?) == a0(=-0x1), and falls through when s1(?) != a0(=-0x1).
  The `beq` branch at 0x1c94 targets 0x1c70, is taken when (s2(=0x200000) & t8(=[[a0+816]:8])) == 0, and falls through when (s2(=0x200000) & t8(=[[a0+816]:8])) != 0.
  The `beq` branch at 0x1c9c targets 0x1c28 and is always taken.
  The `beq` branch at 0x1cb4 targets 0x1c28 and is always taken.
  The return at 0x1c60 has v0 = ret(flushbus).

- `ef_watchdog` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1cbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1cbc-0x1de8 (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0x1cc4 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x1cd0 loads 8 bytes from [a0+272]:8 +0x3a8.
  The `ld` at 0x1d0c loads 8 bytes from (sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4)) +0x8.
  The `ld` at 0x1d10 loads 8 bytes from [(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8 +0x508.
  The `lw` at 0x1d14 loads 4 bytes from [a0+272]:8 +0x34.
  The `lw` at 0x1d18 loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1288]:8 +0x4.
  The `lw` at 0x1d1c loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1288]:8 +0x8.
  The `lw` at 0x1d20 loads 4 bytes from [[(sym(pdaindr) + (ret(cpuvertex_to_cpuid) << 0x4))+8]:8+1288]:8 +0x14.
  The `sw` at 0x1d24 stores 4 bytes to [a0+272]:8 +0x3d4.
  The `sw` at 0x1d38 stores 4 bytes to [a0+272]:8 +0x3d8.
  The `ld` at 0x1d54 loads 8 bytes from [a0+272]:8 +0x378.
  The `lwu` at 0x1d60 loads 4 bytes from [a0+272]:8 +0x370.
  The `ld` at 0x1d64 loads 8 bytes from [a0+272]:8 +0x380.
  The `ld` at 0x1d70 loads 8 bytes from ([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3)) +0x0.
  The `ld` at 0x1d7c loads 8 bytes from [([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8 +0x8.
  The `sd` at 0x1d84 stores 8 bytes to [a0+272]:8 +0x378.
  The `sh` at 0x1d90 stores 2 bytes to [a0+272]:8 +0x1c.
  The `ld` at 0x1dc0 loads 8 bytes from ?.
  The `jal` at 0x1ccc calls pciio_intr_cpu_get with a0=[[a0+272]:8+936]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1cdc calls cpuvertex_to_cpuid with a0=ret(pciio_intr_cpu_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1cf4 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x1d34 calls ef_getcdc with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1d3c calls ef_reclaim with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1d48 calls ef_fill with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1d94 calls ef_phyerr with a0=[a0+272]:8, a1=ret(mutex_bitlock), a2=?, a3=?.
  The `jal` at 0x1da4 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1dbc calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1dd0 calls ef_intr with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x1d58 targets 0x1d8c, is taken when v1(=[[a0+272]:8+888]:8) != a0(=sym(.bss)), and falls through when v1(=[[a0+272]:8+888]:8) == a0(=sym(.bss)).
  The `beq` branch at 0x1d74 targets 0x1d8c, is taken when v0(=[([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8) == 0, and falls through when v0(=[([[a0+272]:8+896]:8 + ([[a0+272]:8+880] << 0x3))]:8) != 0.
  The `beq` branch at 0x1db0 targets 0x1dcc, is taken when s0(=ret(ef_reclaim)) == 0, and falls through when s0(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x1dc4 targets 0x1dbc, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1de0 has v0 = ret(ef_intr).

- `ef_getcdc` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1de8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1de8-0x1e14 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x1de8 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x1dec loads 4 bytes from [a0+816]:8 +0x30.
  The `lw` at 0x1df0 loads 4 bytes from a0 (arg0 at entry) +0x3e4.
  The `lw` at 0x1df4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `sw` at 0x1e04 stores 4 bytes to a0 (arg0 at entry) +0x3e4.
  The `sw` at 0x1e10 stores 4 bytes to a0 (arg0 at entry) +0x44.
  The return at 0x1e0c has v0 = ?.

- `ef_intr` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x1e14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x1e14-0x2364 (1360 bytes).
  It occupies 1360 bytes.
  The `lh` at 0x1e20 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x1e48 loads 4 bytes from a0 (arg0 at entry) +0x388.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x388, including `sw` at 0x1e60, `sw` at 0x1f8c.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0x1e64, `ld` at 0x1ecc, `ld` at 0x1fb4.
  The `lw` at 0x1e68 loads 4 bytes from [a0+816]:8 +0x4.
  The `sw` at 0x1e6c stores 4 bytes to [a0+816]:8 +0x4.
  The `ld` at 0x1e70 loads 8 bytes from a0 (arg0 at entry) +0x338.
  11 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x1e7c, `lw` at 0x1fc8, `lw` at 0x2010.
  The `lwu` at 0x1ec0 loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `sw` at 0x1edc stores 4 bytes to [a0+816]:8 +0x20.
  The `ld` at 0x1ee0 loads 8 bytes from a0 (arg0 at entry) +0x378.
  The `lw` at 0x1ee4 loads 4 bytes from [a0+888]:8 +0x0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1f5c, `ld` at 0x21f8.
  The `ld` at 0x1f90 loads 8 bytes from abs 0x9200000001030100.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x38, including `lw` at 0x1fcc, `lw` at 0x2014, `lw` at 0x22a4.
  The `lw` at 0x1fd0 loads 4 bytes from a0 (arg0 at entry) +0x3f8.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x38, including `sw` at 0x1fdc, `sw` at 0x2024, `sw` at 0x22bc.
  The `sw` at 0x1fe8 stores 4 bytes to a0 (arg0 at entry) +0x3f8.
  The `lw` at 0x2018 loads 4 bytes from a0 (arg0 at entry) +0x3fc.
  The `sw` at 0x2030 stores 4 bytes to a0 (arg0 at entry) +0x3fc.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x40, including `lw` at 0x2064, `lw` at 0x20a0, `lw` at 0x20dc.
  The `lw` at 0x2068 loads 4 bytes from a0 (arg0 at entry) +0x40c.
  7 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x40, including `sw` at 0x2074, `sw` at 0x20b0, `sw` at 0x20ec.
  The `sw` at 0x2080 stores 4 bytes to a0 (arg0 at entry) +0x40c.
  The `lw` at 0x20a4 loads 4 bytes from a0 (arg0 at entry) +0x410.
  The `sw` at 0x20bc stores 4 bytes to a0 (arg0 at entry) +0x410.
  The `lw` at 0x20e0 loads 4 bytes from a0 (arg0 at entry) +0x414.
  The `sw` at 0x20f8 stores 4 bytes to a0 (arg0 at entry) +0x414.
  The `lw` at 0x211c loads 4 bytes from a0 (arg0 at entry) +0x418.
  The `sw` at 0x2134 stores 4 bytes to a0 (arg0 at entry) +0x418.
  The `lw` at 0x2158 loads 4 bytes from a0 (arg0 at entry) +0x400.
  The `sw` at 0x2170 stores 4 bytes to a0 (arg0 at entry) +0x400.
  The `lw` at 0x2190 loads 4 bytes from a0 (arg0 at entry) +0x358.
  The `lw` at 0x21c0 loads 4 bytes from a0 (arg0 at entry) +0x34c.
  The `lw` at 0x21c4 loads 4 bytes from a0 (arg0 at entry) +0x348.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x404, including `lw` at 0x22b0, `lw` at 0x2310.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x404, including `sw` at 0x22c8, `sw` at 0x2328.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x408, including `lw` at 0x22e0, `lw` at 0x2340.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x408, including `sw` at 0x22f8, `sw` at 0x2358.
  The `jal` at 0x1e3c calls mutex_bitlock with a0=a0+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e94 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1ed8 calls flushbus with a0=a0+856, a1=?, a2=(([a0+884] << 0x3) | 0x80000000), a3=[a0+816]:8, a4=0x80000000.
  The `jal` at 0x1ef8 calls ef_recv with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0xffffffff80000000.
  The `jal` at 0x1f24 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x1f48 calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1f68 calls ether_input with a0=a0 at entry (arg0), a1=one of 0x0, 0x1000, a2=?, a3=?.
  The `jal` at 0x1fa8 calls randproc_input with a0=?, a1=0x500000000, a2=0xffffffff, a3=?.
  The `jal` at 0x1ff4 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=[a0+1016]+1, a4=[a0+56]+1.
  The `jal` at 0x2038 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=[a0+1020]+1, a3=?, a4=[a0+56]+1.
  The `jal` at 0x2088 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a6=([[a0+816]:8+4] << 0x2e), a7=[a0+1036]+1.
  The `jal` at 0x20c4 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x2100 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x213c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x2178 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=[a0+64]+1.
  The `jal` at 0x21a0 calls ef_reclaim with a0=a0 at entry (arg0), a1=?, a2=?, a3=([[a0+816]:8+4] << 0x29).
  The `jal` at 0x21b8 calls mutex_bitunlock with a0=a0+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x21dc calls ps_txq_stat with a0=a0 at entry (arg0), a1=?, a2=?, a3=[a0+844].
  The `jal` at 0x21f4 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2208 calls mutex_bitlock with a0=a0+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x2224 calls ef_getcdc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a6=([[a0+816]:8+4] << 0x26).
  The `jal` at 0x223c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?.
  The `jal` at 0x2268 calls ef_init with a0=a0 at entry (arg0), a1=[a0+32], a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2288 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=([[a0+816]:8+4] << 0x29).
  The `jal` at 0x22c4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?.
  The `jal` at 0x22f4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a6=([[a0+816]:8+4] << 0x2e).
  The `jal` at 0x2324 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a6=([[a0+816]:8+4] << 0x26), a7=([[a0+816]:8+4] << 0x25).
  The `jal` at 0x2354 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+26]:2, a3=?, a7=([[a0+816]:8+4] << 0x25).
  The `beq` branch at 0x1e5c targets 0x1f88, is taken when v0(=[a0+904]+1) >= 0x63 (unsigned), and falls through when v0(=[a0+904]+1) < 0x63 (unsigned).
  The `beq` branch at 0x1e74 targets 0x1e90, is taken when v1(=[a0+824]:8) == 0, and falls through when v1(=[a0+824]:8) != 0.
  The `beq` branch at 0x1e88 targets 0x1ec0, is taken when a1(?) == a2(=0x41), and falls through when a1(?) != a2(=0x41).
  The `beq` branch at 0x1ef0 targets 0x1f04, is taken when (a3(=[[a0+888]:8]) & a4(=0xffffffff80000000)) == 0, and falls through when (a3(=[[a0+888]:8]) & a4(=0xffffffff80000000)) != 0.
  The `bne` branch at 0x1f10 targets 0x1fb8, is taken when (s2(=[[a0+816]:8+4]) & a4(=0x7fe003c)) != 0, and falls through when (s2(=[[a0+816]:8+4]) & a4(=0x7fe003c)) == 0.
  The `beq` branch at 0x1f2c targets 0x1ea0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1f40 targets 0x1f54 and is always taken.
  The `beq` branch at 0x1f50 targets 0x1f80, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x1f58 targets 0x1f48, is taken when s2(=one of 0x0, 0x1) != 0, and falls through when s2(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x1f78 targets 0x1f50 and is always taken.
  The `beq` branch at 0x1f80 targets 0x1ea0 and is always taken.
  The `beq` branch at 0x1fb0 targets 0x1e68 and is always taken.
  The `beq` branch at 0x1fbc targets 0x2298, is taken when (s2(=[[a0+816]:8+4]) & 0x4) == 0, and falls through when (s2(=[[a0+816]:8+4]) & 0x4) != 0.
  The `beq` branch at 0x1fe4 targets 0x1ffc, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2008 targets 0x2048, is taken when (s2(=[[a0+816]:8+4]) & 0x8) == 0, and falls through when (s2(=[[a0+816]:8+4]) & 0x8) != 0.
  The `beq` branch at 0x202c targets 0x2040, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `bne` branch at 0x2048 targets 0x22a4, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x2050 targets 0x22d4, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bgez` branch at 0x2058 targets 0x2094, is taken when a6(=([[a0+816]:8+4] << 0x2e)) >= 0 (signed), and falls through when a6(=([[a0+816]:8+4] << 0x2e)) < 0 (signed).
  The `beq` branch at 0x207c targets 0x2090, is taken when (t0(=[a0+32]) & 0x4) == 0, and falls through when (t0(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2094 targets 0x20d0, is taken when t1(=([[a0+816]:8+4] << 0x2d)) >= 0 (signed), and falls through when t1(=([[a0+816]:8+4] << 0x2d)) < 0 (signed).
  The `beq` branch at 0x20b8 targets 0x20cc, is taken when (t3(=[a0+32]) & 0x4) == 0, and falls through when (t3(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x20d0 targets 0x210c, is taken when t8(=([[a0+816]:8+4] << 0x2c)) >= 0 (signed), and falls through when t8(=([[a0+816]:8+4] << 0x2c)) < 0 (signed).
  The `beq` branch at 0x20f4 targets 0x2108, is taken when (ra(=[a0+32]) & 0x4) == 0, and falls through when (ra(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x210c targets 0x2148, is taken when at(=([[a0+816]:8+4] << 0x2b)) >= 0 (signed), and falls through when at(=([[a0+816]:8+4] << 0x2b)) < 0 (signed).
  The `beq` branch at 0x2130 targets 0x2144, is taken when (v1(=[a0+32]) & 0x4) == 0, and falls through when (v1(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2148 targets 0x2188, is taken when a0(=([[a0+816]:8+4] << 0x2a)) >= 0 (signed), and falls through when a0(=([[a0+816]:8+4] << 0x2a)) < 0 (signed).
  The `beq` branch at 0x216c targets 0x2180, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `bgez` branch at 0x2188 targets 0x2218, is taken when a3(=([[a0+816]:8+4] << 0x29)) >= 0 (signed), and falls through when a3(=([[a0+816]:8+4] << 0x29)) < 0 (signed).
  The `beq` branch at 0x2198 targets 0x2278, is taken when (a4(=[a0+856]) & 0x10) == 0, and falls through when (a4(=[a0+856]) & 0x10) != 0.
  The `beq` branch at 0x21e4 targets 0x2208, is taken when s7(=ret(ef_reclaim)) == 0, and falls through when s7(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x21fc targets 0x21f4, is taken when s7(?) != 0, and falls through when s7(?) == 0.
  The `beq` branch at 0x221c targets 0x2248, is taken when (s2(=[[a0+816]:8+4]) & a4(=0x1800000)) == 0, and falls through when (s2(=[[a0+816]:8+4]) & a4(=0x1800000)) != 0.
  The `beq` branch at 0x2234 targets 0x2244, is taken when (a5(=[a0+32]) & 0x4) == 0, and falls through when (a5(=[a0+32]) & 0x4) != 0.
  The `bltz` branch at 0x2248 targets 0x2304, is taken when a6(=([[a0+816]:8+4] << 0x26)) < 0 (signed), and falls through when a6(=([[a0+816]:8+4] << 0x26)) >= 0 (signed).
  The `bltz` branch at 0x2250 targets 0x2334, is taken when a7(=([[a0+816]:8+4] << 0x25)) < 0 (signed), and falls through when a7(=([[a0+816]:8+4] << 0x25)) >= 0 (signed).
  The `beq` branch at 0x2258 targets 0x1f18, is taken when s5(=one of 0x0, 0x1) == 0, and falls through when s5(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2270 targets 0x1f1c and is always taken.
  The `beq` branch at 0x2280 targets 0x2214, is taken when (t0(=[a0+32]) & 0x4) == 0, and falls through when (t0(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2290 targets 0x2218 and is always taken.
  The `beq` branch at 0x229c targets 0x2004 and is always taken.
  The `beq` branch at 0x22cc targets 0x204c and is always taken.
  The `beq` branch at 0x22fc targets 0x2054 and is always taken.
  The `beq` branch at 0x232c targets 0x224c and is always taken.
  The `beq` branch at 0x235c targets 0x2258 and is always taken.
  The return at 0x1eb8 has v0 = one of ret(mutex_bitunlock), ?.

- `ef_recv` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x2364 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x2364-0x2868 (1284 bytes).
  It occupies 1284 bytes.
  The `lh` at 0x2364 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x236c loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x2390 loads 4 bytes from a0 (arg0 at entry) +0x370.
  9 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x23c8, `lhu` at 0x2400, `lhu` at 0x2404.
  7 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x23d8, `lbu` at 0x2444, `lbu` at 0x2484.
  The `lw` at 0x23f0 loads 4 bytes from a0 (arg0 at entry) +0x358.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2464, `lw` at 0x2478, `lw` at 0x2544.
  The `sb` at 0x250c stores 1 byte to ?.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x380, including `ld` at 0x252c, `ld` at 0x256c, `ld` at 0x2620.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2538, `ld` at 0x253c, `ld` at 0x2578.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2574, `sd` at 0x2580, `sd` at 0x258c.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2584, `sh` at 0x25c8, `sh` at 0x2798.
  The `lw` at 0x2598 loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x25a4 loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `sw` at 0x25b4 stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `sw` at 0x25c4 stores 4 bytes to a0 (arg0 at entry) +0x48.
  The `sw` at 0x25fc stores 4 bytes to a0 (arg0 at entry) +0x370.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x378, including `sd` at 0x264c, `sd` at 0x2668.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x26a4, `lw` at 0x26f8, `lw` at 0x2744.
  The `lw` at 0x26a8 loads 4 bytes from a0 (arg0 at entry) +0x3e8.
  The `sw` at 0x26bc stores 4 bytes to a0 (arg0 at entry) +0x3e8.
  The `lw` at 0x26fc loads 4 bytes from a0 (arg0 at entry) +0x3ec.
  The `sw` at 0x2714 stores 4 bytes to a0 (arg0 at entry) +0x3ec.
  The `lw` at 0x2748 loads 4 bytes from a0 (arg0 at entry) +0x3f0.
  The `sw` at 0x2760 stores 4 bytes to a0 (arg0 at entry) +0x3f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3f4, including `lw` at 0x27d0, `lw` at 0x2818.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3f4, including `sw` at 0x27e0, `sw` at 0x2828.
  The `jal` at 0x2510 calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2550 calls us_delay with a0=[sym(.sdata)+16], a1=?, a2=?, a3=?.
  The `jal` at 0x2600 calls ef_fill with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x26c8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=?, a3=?, a4=[a0+1000]+1.
  The `jal` at 0x2718 calls ether_sprintf with a0=?, a1=?, a2=?, a3=[a0+1004]+1.
  The `jal` at 0x272c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `jal` at 0x276c calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=[a0+1008]+1, a3=?.
  The `jal` at 0x2780 calls network_drop with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x27a0 calls ether_input with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x27e4 calls ether_sprintf with a0=?, a1=0x30, a2=0x5fc, a3=?, a4=[a0+1012]+1.
  The `jal` at 0x27f8 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `jal` at 0x282c calls ether_sprintf with a0=?, a1=[a0+1012]+1, a2=?, a3=?.
  The `jal` at 0x2840 calls printf with a0=sym(.rodata), a1=[a0+26]:2, a2=ret(ether_sprintf), a3=?.
  The `beq` branch at 0x23a8 targets 0x25f4, is taken when at(=[a0+880]) == v1(=[a0+884]), and falls through when at(=[a0+880]) != v1(=[a0+884]).
  The `beq` branch at 0x23b8 targets 0x285c and is always taken.
  The `bne` branch at 0x23c0 targets 0x25d8, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x23d0 targets 0x25d8, is taken when (a0(?) & 0x3fff) != 0, and falls through when (a0(?) & 0x3fff) == 0.
  The `beq` branch at 0x23e0 targets 0x23f0, is taken when a1(=0x6) == a2(?), and falls through when a1(=0x6) != a2(?).
  The `bne` branch at 0x23e8 targets 0x25d8, is taken when a3(=0x11) != a2(?), and falls through when a3(=0x11) == a2(?).
  The `beq` branch at 0x23f8 targets 0x25d8, is taken when (a4(=[a0+856]) & 0x1) == 0, and falls through when (a4(=[a0+856]) & 0x1) != 0.
  The `beq` branch at 0x24ac targets 0x266c, is taken when (s7(?) & 0x1) == 0, and falls through when (s7(?) & 0x1) != 0.
  The `bne` branch at 0x24f8 targets 0x25d8, is taken when a2(=0xffff) != a3(?), and falls through when a2(=0xffff) == a3(?).
  The `beq` branch at 0x2508 targets 0x25dc, is taken when s8(=one of 0x0, 0x1) == 0, and falls through when s8(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2524 targets 0x25f8, is taken when a6(=[a0+884]) == s3(?), and falls through when a6(=[a0+884]) != s3(?).
  The `beq` branch at 0x2548 targets 0x2558, is taken when s4(=[sym(.sdata)+12]) == 0, and falls through when s4(=[sym(.sdata)+12]) != 0.
  The `beq` branch at 0x2564 targets 0x25fc, is taken when (s4(?) & t8(=0xffffffff80000000)) == 0, and falls through when (s4(?) & t8(=0xffffffff80000000)) != 0.
  The `beq` branch at 0x25c0 targets 0x2698, is taken when (s6(?) & v0(=0x40000000)) == 0, and falls through when (s6(?) & v0(=0x40000000)) != 0.
  The `beq` branch at 0x25d0 targets 0x23c0, is taken when t0(=0x800) == a5(?), and falls through when t0(=0x800) != a5(?).
  The `bne` branch at 0x25d8 targets 0x2510, is taken when s8(=one of 0x0, 0x1) != 0, and falls through when s8(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x25e0 targets 0x265c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x25ec targets 0x2518 and is always taken.
  The `beq` branch at 0x263c targets 0x2664, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x265c targets 0x25ec and is always taken.
  The `beq` branch at 0x2664 targets 0x2650 and is always taken.
  The `beq` branch at 0x2690 targets 0x24dc and is always taken.
  The `beq` branch at 0x269c targets 0x26e8, is taken when a5(?) >= 0x40 (signed), and falls through when a5(?) < 0x40 (signed).
  The `beq` branch at 0x26b8 targets 0x26d0, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x26d4 targets 0x280c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x26e0 targets 0x26f8 and is always taken.
  The `beq` branch at 0x26e8 targets 0x27c0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x26f0 targets 0x2814, is taken when s7(?) == a2(=0x5fc), and falls through when s7(?) != a2(=0x5fc).
  The `beq` branch at 0x2710 targets 0x2738, is taken when (a4(=[a0+32]) & 0x4) == 0, and falls through when (a4(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x273c targets 0x2778, is taken when (s6(?) & 0x4) == 0, and falls through when (s6(?) & 0x4) != 0.
  The `beq` branch at 0x275c targets 0x2778, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2778 targets 0x2790, is taken when s8(=one of 0x0, 0x1) == 0, and falls through when s8(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2788 targets 0x251c and is always taken.
  The `beq` branch at 0x27b8 targets 0x2518 and is always taken.
  The `bne` branch at 0x27c4 targets 0x2854, is taken when a5(?) < 0x5ef (signed), and falls through when a5(?) >= 0x5ef (signed).
  The `beq` branch at 0x27dc targets 0x2800, is taken when (a5(=[a0+32]) & 0x4) == 0, and falls through when (a5(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x2804 targets 0x2738 and is always taken.
  The `beq` branch at 0x280c targets 0x2738 and is always taken.
  The `beq` branch at 0x2824 targets 0x2848, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0x284c targets 0x2738 and is always taken.
  The `beq` branch at 0x2854 targets 0x2738 and is always taken.
  The `beq` branch at 0x2860 targets 0x2530 and is always taken.
  The return at 0x2654 has v0 = ?.

- `ef_transmit` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x2868 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x2868-0x3074 (2060 bytes).
  It occupies 2060 bytes.
  The `ld` at 0x2870 loads 8 bytes from a0 (arg0 at entry) +0x110.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x28b4, `ld` at 0x28e8, `ld` at 0x2c80.
  The `lhu` at 0x28b8 loads 2 bytes from ?.
  2 such `lbu` accesses load 1 byte from a4 (arg4 at entry) +0x1a, including `lbu` at 0x28fc, `lbu` at 0x2a80.
  5 such `ld` accesses load 8 bytes from a4 (arg4 at entry) +0x8, including `ld` at 0x290c, `ld` at 0x2d1c, `ld` at 0x2d50.
  The `lbu` at 0x2914 loads 1 byte from ([a4+8]:8 + a4) +0x9.
  The `lbu` at 0x291c loads 1 byte from ([a4+8]:8 + a4) +0x0.
  The `lhu` at 0x2930 loads 2 bytes from a1 (arg1 at entry) +0x2.
  The `lhu` at 0x2934 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `lhu` at 0x2938 loads 2 bytes from a2 (arg2 at entry) +0x4.
  The `lhu` at 0x293c loads 2 bytes from ([a4+8]:8 + a4) +0x2.
  The `lhu` at 0x2940 loads 2 bytes from a2 (arg2 at entry) +0x0.
  The `lhu` at 0x2948 loads 2 bytes from a2 (arg2 at entry) +0x2.
  The `lhu` at 0x2954 loads 2 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0x2960 loads 4 bytes from ([a4+8]:8 + a4) +0xc.
  The `lw` at 0x2984 loads 4 bytes from ([a4+8]:8 + a4) +0x10.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x29e0, `sh` at 0x2a78.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x358, including `lw` at 0x29f8, `lw` at 0x2bb8.
  3 such `lw` accesses load 4 bytes from [a0+272]:8 +0x34c, including `lw` at 0x2a08, `lw` at 0x2c3c, `lw` at 0x2f80.
  5 such `lw` accesses load 4 bytes from [a0+272]:8 +0x348, including `lw` at 0x2a0c, `lw` at 0x2bc8, `lw` at 0x2c18.
  The `ld` at 0x2a24 loads 8 bytes from [a0+272]:8 +0x338.
  The `lwl` at 0x2a38 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lwr` at 0x2a40 loads 4 bytes from a1 (arg1 at entry) +0x3.
  14 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2a44, `sw` at 0x2b4c, `sw` at 0x2b70.
  The `lbu` at 0x2a48 loads 1 byte from a1 (arg1 at entry) +0x4.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x2a4c, `sb` at 0x2a54, `sb` at 0x2a70.
  The `lbu` at 0x2a50 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lwl` at 0x2a58 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lwr` at 0x2a60 loads 4 bytes from a2 (arg2 at entry) +0x3.
  The `swl` at 0x2a64 stores 4 bytes to ?.
  The `swr` at 0x2a68 stores 4 bytes to ?.
  The `lbu` at 0x2a6c loads 1 byte from a2 (arg2 at entry) +0x4.
  The `lbu` at 0x2a74 loads 1 byte from a2 (arg2 at entry) +0x5.
  6 such `lhu` accesses load 2 bytes from a4 (arg4 at entry) +0x18, including `lhu` at 0x2ac4, `lhu` at 0x2b58, `lhu` at 0x2d40.
  2 such `ld` accesses load 8 bytes from a4 (arg4 at entry) +0x0, including `ld` at 0x2ac8, `ld` at 0x2d84.
  The `ld` at 0x2ad4 loads 8 bytes from [a4]:8 +0x0.
  5 such `ld` accesses load 8 bytes from [a4]:8 +0x8, including `ld` at 0x2aec, `ld` at 0x2b74, `ld` at 0x2d9c.
  4 such `lhu` accesses load 2 bytes from [a4]:8 +0x18, including `lhu` at 0x2b00, `lhu` at 0x2b54, `lhu` at 0x2ddc.
  2 such `ld` accesses load 8 bytes from [[a4]:8]:8 +0x8, including `ld` at 0x2b14, `ld` at 0x2b98.
  The `lhu` at 0x2b50 loads 2 bytes from [[a4]:8]:8 +0x18.
  7 such `ld` accesses load 8 bytes from [a0+272]:8 +0x340, including `ld` at 0x2b90, `ld` at 0x2bb0, `ld` at 0x2d68.
  7 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2b94, `sd` at 0x2bb4, `sd` at 0x2d70.
  The `lw` at 0x2bcc loads 4 bytes from [a0+272]:8 +0x35c.
  The `lw` at 0x2bdc loads 4 bytes from ?.
  The `lbu` at 0x2be8 loads 1 byte from [a0+272]:8 +0x1de.
  The `lwu` at 0x2c04 loads 4 bytes from [a0+272]:8 +0x348.
  The `ld` at 0x2c08 loads 8 bytes from [a0+272]:8 +0x350.
  The `sd` at 0x2c14 stores 8 bytes to ([[a0+272]:8+848]:8 + ([[a0+272]:8+840] << 0x3)) +0x0.
  The `ld` at 0x2c24 loads 8 bytes from [a0+272]:8 +0x330.
  The `sw` at 0x2c2c stores 4 bytes to [a0+272]:8 +0x348.
  The `sw` at 0x2c34 stores 4 bytes to [[a0+272]:8+816]:8 +0x44.
  The `lw` at 0x2c48 loads 4 bytes from [a0+272]:8 +0x4c.
  The `sw` at 0x2c58 stores 4 bytes to [a0+272]:8 +0x4c.
  2 such `ld` accesses load 8 bytes from ret(m_vget) +0x8, including `ld` at 0x2ea0, `ld` at 0x2ee4.
  The `sh` at 0x2eb4 stores 2 bytes to ret(m_vget) +0x18.
  The `lhu` at 0x2ed4 loads 2 bytes from ret(m_vget) +0x18.
  The `lw` at 0x2f0c loads 4 bytes from [a0+272]:8 +0x41c.
  The `sw` at 0x2f1c stores 4 bytes to [a0+272]:8 +0x41c.
  The `lw` at 0x2f98 loads 4 bytes from [a0+272]:8 +0x424.
  The `sw` at 0x2fa0 stores 4 bytes to [a0+272]:8 +0x424.
  3 such `lw` accesses load 4 bytes from [a0+272]:8 +0x20, including `lw` at 0x2fac, `lw` at 0x3000, `lw` at 0x303c.
  3 such `lh` accesses load 2 bytes from [a0+272]:8 +0x1a, including `lh` at 0x2fc0, `lh` at 0x3014, `lh` at 0x3050.
  The `lw` at 0x2fec loads 4 bytes from [a0+272]:8 +0x428.
  The `sw` at 0x2ffc stores 4 bytes to [a0+272]:8 +0x428.
  The `lw` at 0x3028 loads 4 bytes from [a0+272]:8 +0x420.
  The `sw` at 0x3038 stores 4 bytes to [a0+272]:8 +0x420.
  The `jal` at 0x29f0 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2b30 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=[a4+24]:2, a3=?.
  The `jal` at 0x2b78 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=((([[a4]:8+24]:2 << 0x8) | ([[[a4]:8]:8+24]:2 << 0x14)) | [a4+24]:2+14), a2=[a4+24]:2+14, a3=([[[a4]:8]:8+24]:2 << 0x14).
  The `jal` at 0x2b8c calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2b9c calls kvtophys with a0=([[[a4]:8]:8+8]:8 + [[a4]:8]:8), a1=?, a2=?, a3=?.
  The `jal` at 0x2bac calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2bfc calls ef_selfsnoop with a0=[a0+272]:8, a1=?, a2=?, a3=?, a4=[[a0+272]:8+478]:1.
  The `jal` at 0x2c30 calls flushbus with a0=?, a1=?, a2=?, a3=?, a7=[[a0+272]:8+816]:8.
  The `jal` at 0x2c68 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2c7c calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2cc0 calls ef_reclaim with a0=[a0+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x2cdc calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2d54 calls kvtophys with a0=([a4+8]:8 + a4), a1=(([a4+24]:2 << 0x8) | 0xe), a2=?, a3=?.
  The `jal` at 0x2d64 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2dc8 calls bcopy with a0=([a4+8]:8 + a4), a1=?, a2=[a4+24]:2, a3=?.
  The `jal` at 0x2df8 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=(([[a4]:8+24]:2 << 0x8) | [a4+24]:2+14), a2=[a4+24]:2+14, a3=?.
  The `jal` at 0x2e08 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2e44 calls kvtophys with a0=([a4+8]:8 + a4), a1=((([[a4]:8+24]:2 << 0x14) | ([a4+24]:2 << 0x8)) | 0xe), a2=([a4+24]:2 << 0x8), a3=?.
  The `jal` at 0x2e54 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2e64 calls kvtophys with a0=([[a4]:8+8]:8 + [a4]:8), a1=?, a2=?, a3=?.
  The `jal` at 0x2e74 calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2e8c calls m_vget with a0=0x0, a1=?, a2=0x1, a3=?.
  The `jal` at 0x2eac calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=?, a3=([ret(m_vget)+8]:8 + ret(m_vget)).
  The `jal` at 0x2eb8 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2eec calls kvtophys with a0=([ret(m_vget)+8]:8 + ret(m_vget)), a1=(([ret(m_vget)+24]:2 << 0x8) | 0xe), a2=?, a3=?.
  The `jal` at 0x2efc calls pciio_dmamap_addr with a0=[[a0+272]:8+832]:8, a1=ret(kvtophys), a2=0x4, a3=?.
  The `jal` at 0x2f18 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2f28 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2f38 calls ef_reclaim with a0=[a0+272]:8, a1=[[a0+272]:8+840], a2=?, a3=?.
  The `jal` at 0x2f4c calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2f60 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2f74 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=?, a3=?.
  The `jal` at 0x2fa4 calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+840], a2=?, a3=?.
  The `jal` at 0x2fc4 calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x2fd4 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x2ff8 calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+1064]+1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3018 calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x3034 calls m_freem with a0=a4 at entry (arg4), a1=[[a0+272]:8+1056]+1, a2=?, a3=?.
  The `jal` at 0x3054 calls printf with a0=sym(.rodata), a1=[[a0+272]:8+26]:2, a2=?, a3=?.
  The `jal` at 0x3064 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `beq` branch at 0x28a4 targets 0x2d00, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x28cc targets 0x28e8, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x28dc targets 0x28e8, is taken when a4(?) == a5(?), and falls through when a4(?) != a5(?).
  The `bne` branch at 0x28ec targets 0x28b4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x28f4 targets 0x2fec, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2904 targets 0x2d0c, is taken when (a7(=[a4+26]:1) & 0x2) == 0, and falls through when (a7(=[a4+26]:1) & 0x2) != 0.
  The `beq` branch at 0x2924 targets 0x2d14, is taken when a1(=[([a4+8]:8 + a4)+9]:1) == v1(=0x6), and falls through when a1(=[([a4+8]:8 + a4)+9]:1) != v1(=0x6).
  The `bne` branch at 0x2a00 targets 0x2f0c, is taken when (a6(=[[a0+272]:8+856]) & 0x4) != 0, and falls through when (a6(=[[a0+272]:8+856]) & 0x4) == 0.
  The `beq` branch at 0x2a30 targets 0x2f38, is taken when a0(=[[a0+272]:8+844]) == t9(?), and falls through when a0(=[[a0+272]:8+844]) != t9(?).
  The `beq` branch at 0x2a88 targets 0x2aa4, is taken when (ra(=[a4+26]:1) & 0x2) == 0, and falls through when (ra(=[a4+26]:1) & 0x2) != 0.
  The `bne` branch at 0x2aa4 targets 0x2cd0, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x2aac targets 0x2d1c, is taken when s3(?) == t9(=0x1), and falls through when s3(?) != t9(=0x1).
  The `beq` branch at 0x2ab4 targets 0x2d74, is taken when s3(?) == ra(=0x2), and falls through when s3(?) != ra(=0x2).
  The `bne` branch at 0x2abc targets 0x2e88, is taken when s3(?) != at(=0x3), and falls through when s3(?) == at(=0x3).
  The `beq` branch at 0x2ad0 targets 0x2e84, is taken when a2(=[a4+24]:2) >= 0x59 (signed), and falls through when a2(=[a4+24]:2) < 0x59 (signed).
  The `blez` branch at 0x2ad8 targets 0x2e88, is taken when a2(=[a4+24]:2) <= 0 (signed), and falls through when a2(=[a4+24]:2) > 0 (signed).
  The `bne` branch at 0x2ae4 targets 0x2e88, is taken when (a2(=[a4+24]:2) & 0x1) != 0, and falls through when (a2(=[a4+24]:2) & 0x1) == 0.
  The `bne` branch at 0x2af8 targets 0x2e88, is taken when (a0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) != 0, and falls through when (a0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) == 0.
  The `blez` branch at 0x2b04 targets 0x2e84, is taken when a0(=[[a4]:8+24]:2) <= 0 (signed), and falls through when a0(=[[a4]:8+24]:2) > 0 (signed).
  The `bne` branch at 0x2b0c targets 0x2e88, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x2b20 targets 0x2e84, is taken when (a3(=([[[a4]:8]:8+8]:8 + [[a4]:8]:8)) & 0x7f) != 0, and falls through when (a3(=([[[a4]:8]:8+8]:8 + [[a4]:8]:8)) & 0x7f) == 0.
  The `beq` branch at 0x2bc0 targets 0x2bdc, is taken when (a1(=[[a0+272]:8+856]) & 0x10) == 0, and falls through when (a1(=[[a0+272]:8+856]) & 0x10) != 0.
  The `beq` branch at 0x2bd4 targets 0x2fe4, is taken when (a2(=[[a0+272]:8+840]) & a3(=[[a0+272]:8+860])) == 0, and falls through when (a2(=[[a0+272]:8+840]) & a3(=[[a0+272]:8+860])) != 0.
  The `beq` branch at 0x2bec targets 0x2c04, is taken when a4(=[[a0+272]:8+478]:1) == 0, and falls through when a4(=[[a0+272]:8+478]:1) != 0.
  The `beq` branch at 0x2c54 targets 0x2cc0, is taken when t8(?) >= 0x15 (unsigned), and falls through when t8(?) < 0x15 (unsigned).
  The `beq` branch at 0x2c70 targets 0x2c90, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x2c84 targets 0x2c7c, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x2cc8 targets 0x2c60 and is always taken.
  The `beq` branch at 0x2cf8 targets 0x2bb8 and is always taken.
  The `beq` branch at 0x2d04 targets 0x28fc and is always taken.
  The `beq` branch at 0x2d0c targets 0x29e4 and is always taken.
  The `beq` branch at 0x2d14 targets 0x2930 and is always taken.
  The `bne` branch at 0x2d28 targets 0x2e84, is taken when (v0(=([a4+8]:8 + a4)) & 0x1) != 0, and falls through when (v0(=([a4+8]:8 + a4)) & 0x1) == 0.
  The `beq` branch at 0x2d6c targets 0x2bb8 and is always taken.
  The `bne` branch at 0x2d80 targets 0x2e84, is taken when (a0(=([a4+8]:8 + a4)) & 0x1) != 0, and falls through when (a0(=([a4+8]:8 + a4)) & 0x1) == 0.
  The `blez` branch at 0x2d8c targets 0x2e84, is taken when a2(=[a4+24]:2) <= 0 (signed), and falls through when a2(=[a4+24]:2) > 0 (signed).
  The `bne` branch at 0x2d94 targets 0x2e84, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x2da8 targets 0x2e84, is taken when (v0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) != 0, and falls through when (v0(=([[a4]:8+8]:8 + [a4]:8)) & 0x1) == 0.
  The `beq` branch at 0x2db0 targets 0x2dbc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2db8 targets 0x2e84, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x2dc0 targets 0x2e18, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2e10 targets 0x2bb8 and is always taken.
  The `beq` branch at 0x2e7c targets 0x2bb8 and is always taken.
  The `beq` branch at 0x2e94 targets 0x3028, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `beq` branch at 0x2f04 targets 0x2bb8 and is always taken.
  The `beq` branch at 0x2f30 targets 0x2c90 and is always taken.
  The `beq` branch at 0x2f54 targets 0x2f74, is taken when s0(=ret(ef_reclaim)) == 0, and falls through when s0(=ret(ef_reclaim)) != 0.
  The `bne` branch at 0x2f68 targets 0x2f60, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0x2f90 targets 0x2a18, is taken when a0(=[[a0+272]:8+844]) != t9(?), and falls through when a0(=[[a0+272]:8+844]) == t9(?).
  The `beq` branch at 0x2fb4 targets 0x2fd0, is taken when (at(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (at(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x2fdc targets 0x2c90 and is always taken.
  The `beq` branch at 0x2fe4 targets 0x2bdc and is always taken.
  The `beq` branch at 0x3008 targets 0x3020, is taken when (a2(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (a2(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x3020 targets 0x2c90 and is always taken.
  The `beq` branch at 0x3044 targets 0x3060, is taken when (a2(=[[a0+272]:8+32]) & 0x4) == 0, and falls through when (a2(=[[a0+272]:8+32]) & 0x4) != 0.
  The `beq` branch at 0x306c targets 0x2c90 and is always taken.
  The return at 0x2cb8 has v0 = one of 0x0, 0x7, 0x7f, 0x84.

- `ef_selfsnoop` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x3074 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x3074-0x31c8 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0x3124 loads 8 bytes from ret(m_vget) +0x8.
  The `sh` at 0x3140 stores 2 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x8.
  The `sd` at 0x314c stores 8 bytes to ([ret(m_vget)+8]:8 + ret(m_vget)) +0x0.
  The `ldl` at 0x3150 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `ldr` at 0x3158 loads 8 bytes from a1 (arg1 at entry) +0x7.
  The `sdl` at 0x315c stores 8 bytes to ?.
  The `sdr` at 0x3160 stores 8 bytes to ?.
  The `lwl` at 0x3164 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lwr` at 0x3170 loads 4 bytes from a1 (arg1 at entry) +0xb.
  The `swl` at 0x317c stores 4 bytes to ?.
  The `swr` at 0x3188 stores 4 bytes to ?.
  The `lhu` at 0x3194 loads 2 bytes from a1 (arg1 at entry) +0xc.
  The `sh` at 0x31a0 stores 2 bytes to ?.
  The `jal` at 0x30ac calls bcopy with a0=a1 at entry (arg1), a1=sp-110, a2=0xe, a3=a3 at entry (arg3).
  The `jal` at 0x30c4 calls m_datacopy with a0=a2 at entry (arg2), a1=0x0, a2=0x14, a3=sp-96.
  The `jal` at 0x30d8 calls snoop_match with a0=a0+400, a1=sp-110, a2=0x24, a3=?.
  The `jal` at 0x30f4 calls m_vget with a0=0x0, a1=(a3+48 << 0x0), a2=0x1, a3=?.
  The `jal` at 0x3114 calls snoop_drop2 with a0=a0+400, a1=0x8000, a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=ret(snoop_match).
  The `jal` at 0x3148 calls m_datacopy with a0=a2 at entry (arg2), a1=0x0, a2=a3 at entry (arg3), a3=([ret(m_vget)+8]:8 + ret(m_vget))+48, a4=([ret(m_vget)+8]:8 + ret(m_vget)), a5=0x30.
  The `jal` at 0x319c calls snoop_input2 with a0=a0+400, a1=0x8000, a2=?, a3=?, a5=ret(snoop_match), a6=[a1+12]:2.
  The `beq` branch at 0x30e0 targets 0x31a4, is taken when v0(=ret(snoop_match)) == 0, and falls through when v0(=ret(snoop_match)) != 0.
  The `bne` branch at 0x30fc targets 0x3124, is taken when v0(=ret(m_vget)) != 0, and falls through when v0(=ret(m_vget)) == 0.
  The `beq` branch at 0x311c targets 0x31a8 and is always taken.
  The return at 0x31c0 has v0 = one of ret(snoop_drop2), ?.

- `ef_ioctl` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x31c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x31c8-0x337c (436 bytes).
  It occupies 436 bytes.
  The `ld` at 0x31e4 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `ld` at 0x321c loads 8 bytes from a2 (arg2 at entry) +0x0.
  The `sh` at 0x3280 stores 2 bytes to a2 (arg2 at entry) +0x8.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3290, `lbu` at 0x3328.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x8, including `lhu` at 0x32b4, `lhu` at 0x3310.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x32e4, `sb` at 0x3334.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x3c4, including `lw` at 0x32e8, `lw` at 0x3338.
  2 such `lw` accesses load 4 bytes from [a0+272]:8 +0x20, including `lw` at 0x32f0, `lw` at 0x3340.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x3c4, including `sw` at 0x32fc, `sw` at 0x3348.
  2 such `sw` accesses store 4 bytes to [a0+272]:8 +0x20, including `sw` at 0x3368, `sw` at 0x3378.
  The `jal` at 0x3204 calls mutex_bitlock with a0=[a0+272]:8+856, a1=0x1000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3248 calls mutex_bitunlock with a0=[a0+272]:8+856, a1=0x1000, a2=ret(mutex_bitlock), a3=?.
  The `jal` at 0x3270 calls ef_lafhash with a0=[a2]:8+2, a1=0x6, a2=[a2]:8, a3=?.
  The `jal` at 0x32ac calls ef_lafhash with a0=[a2]:8+2, a1=0x6, a2=[a2]:8, a3=?.
  The `jal` at 0x32c8 calls mfhasvalue with a0=a0+296, a1=[a2+8]:2, a2=?, a3=?.
  The `jal` at 0x3300 calls ef_init with a0=a0 at entry (arg0), a1=?, a2=ret(mutex_bitlock), a3=?, a4=[[a0+272]:8+964]+1.
  The `jal` at 0x3350 calls ef_init with a0=a0 at entry (arg0), a1=?, a2=ret(mutex_bitlock), a3=?, a5=[[a0+272]:8+964]-1.
  The `beq` branch at 0x3220 targets 0x326c, is taken when s3(=a1) == a1(=0xffffffff80206931), and falls through when s3(=a1) != a1(=0xffffffff80206931).
  The `beq` branch at 0x3228 targets 0x32ac, is taken when s3(=a1) == a0(=0xffffffff80206932), and falls through when s3(=a1) != a0(=0xffffffff80206932).
  The `beq` branch at 0x329c targets 0x32e0, is taken when (a5(?) & a0(?)) == 0, and falls through when (a5(?) & a0(?)) != 0.
  The `beq` branch at 0x32a4 targets 0x3234 and is always taken.
  The `beq` branch at 0x32b8 targets 0x32c8, is taken when v0(=ret(ef_lafhash)) == a1(=[a2+8]:2), and falls through when v0(=ret(ef_lafhash)) != a1(=[a2+8]:2).
  The `beq` branch at 0x32c0 targets 0x3234 and is always taken.
  The `beq` branch at 0x32d0 targets 0x3310, is taken when v0(=ret(mfhasvalue)) == 0, and falls through when v0(=ret(mfhasvalue)) != 0.
  The `beq` branch at 0x32d8 targets 0x3234 and is always taken.
  The `beq` branch at 0x32ec targets 0x3360, is taken when v0(=[[a0+272]:8+964]) == 0, and falls through when v0(=[[a0+272]:8+964]) != 0.
  The `beq` branch at 0x3308 targets 0x3230 and is always taken.
  The `beq` branch at 0x3344 targets 0x336c, is taken when a5(=[[a0+272]:8+964]-1) == 0, and falls through when a5(=[[a0+272]:8+964]-1) != 0.
  The `beq` branch at 0x3358 targets 0x3230 and is always taken.
  The `beq` branch at 0x3364 targets 0x32f4 and is always taken.
  The `beq` branch at 0x3374 targets 0x334c and is always taken.
  The return at 0x3264 has v0 = ?.

- `ef_lafhash` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x337c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x337c-0x3430 (180 bytes).
  It occupies 180 bytes.
  The `lbu` at 0x33b0 loads 1 byte from ?.
  The `blez` branch at 0x3384 targets 0x33e4, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x3394 targets 0x33a0 and is always taken.
  The `bltz` branch at 0x339c targets 0x33e4, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `beq` branch at 0x33ac targets 0x3424 and is always taken.
  The `bltz` branch at 0x33bc targets 0x339c, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `bne` branch at 0x33d4 targets 0x33b4, is taken when (at(?) & 0x1) != 0, and falls through when (at(?) & 0x1) == 0.
  The `beq` branch at 0x33dc targets 0x33b8 and is always taken.
  The `bltz` branch at 0x3400 targets 0x341c, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `bgez` branch at 0x3414 targets 0x33ec, is taken when t1(?) >= 0 (signed), and falls through when t1(?) < 0 (signed).
  The `beq` branch at 0x3428 targets 0x33c8 and is always taken.
  The return at 0x341c has v0 = ?.

- `ef_phystr` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x3430 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x3430-0x34c0 (144 bytes).
  It occupies 144 bytes.
  The `beq` branch at 0x3448 targets 0x34a0, is taken when a0 == at(=0x181441), and falls through when a0 != at(=0x181441).
  The `beq` branch at 0x3458 targets 0x34ac, is taken when a0 == v0(=0x15f41), and falls through when a0 != v0(=0x15f41).
  The `beq` branch at 0x3474 targets 0x34a4, is taken when a0 == v1(=0x15f42), and falls through when a0 != v1(=0x15f42).
  The `beq` branch at 0x347c targets 0x34b4, is taken when a0 == a7(=0x15f43), and falls through when a0 != a7(=0x15f43).
  The `beq` branch at 0x3484 targets 0x34a4, is taken when a0 == t0(=0x20005c0), and falls through when a0 != t0(=0x20005c0).
  The `beq` branch at 0x348c targets 0x34a4, is taken when a0 == t2(=0x20005c1), and falls through when a0 != t2(=0x20005c1).
  The return at 0x3498 has v0 = sym(.rodata).
  The return at 0x34a4 has v0 = sym(.rodata).
  The return at 0x34ac has v0 = sym(.rodata).
  The return at 0x34b8 has v0 = sym(.rodata).

- `ef_dump` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x34c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x34c0-0x356c (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0x3514 loads 8 bytes from ret(ifunit) +0x110.
  The `jal` at 0x34e4 calls sprintf with a0=sp-144, a1=sym(.rodata), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x34ec calls ifunit with a0=sp-144, a1=?, a2=?, a3=?.
  The `jal` at 0x3504 calls qprintf with a0=sym(.rodata), a1=sp-144, a2=?, a3=?.
  The `jal` at 0x3518 calls ef_dumpif with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3524 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x352c calls ef_dumpei with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3538 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3540 calls ef_dumpregs with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x354c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3554 calls ef_dumpphy with a0=[ret(ifunit)+272]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x34f4 targets 0x3514, is taken when v0(=ret(ifunit)) != 0, and falls through when v0(=ret(ifunit)) == 0.
  The `beq` branch at 0x350c targets 0x3560 and is always taken.
  The return at 0x3564 has v0 = one of ret(qprintf), ret(ef_dumpphy).

- `ef_dumpif` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x356c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x356c-0x35fc (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0x356c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x3570 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lw` at 0x3574 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `lw` at 0x3578 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x35a0 loads 4 bytes from a0 (arg0 at entry) +0xb0.
  The `lw` at 0x35a4 loads 4 bytes from a0 (arg0 at entry) +0xac.
  The `lw` at 0x35a8 loads 4 bytes from a0 (arg0 at entry) +0xa8.
  The `lh` at 0x35ac loads 2 bytes from a0 (arg0 at entry) +0x1c.
  The `lw` at 0x35b8 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x35bc loads 4 bytes from a0 (arg0 at entry) +0x3c.
  The `lw` at 0x35c0 loads 4 bytes from a0 (arg0 at entry) +0x38.
  The `lw` at 0x35c4 loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x35d0 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `lw` at 0x35d4 loads 4 bytes from a0 (arg0 at entry) +0x4c.
  The `lw` at 0x35d8 loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `lw` at 0x35dc loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `jal` at 0x3598 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=[a0]:8, a3=[a0+26]:2, a4=[a0+40], a5=[a0+32].
  The `jal` at 0x35b0 calls qprintf with a0=sym(.rodata), a1=[a0+28]:2, a2=[a0+168], a3=[a0+172], a4=[a0+176].
  The `jal` at 0x35c8 calls qprintf with a0=sym(.rodata), a1=[a0+52], a2=[a0+56], a3=[a0+60], a4=[a0+64].
  The `jal` at 0x35e0 calls qprintf with a0=sym(.rodata), a1=[a0+68], a2=[a0+72], a3=[a0+76], a4=[a0+92].
  The return at 0x35f4 has v0 = ret(qprintf).

- `ef_dumpei` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x35fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x35fc-0x3744 (328 bytes).
  It occupies 328 bytes.
  The `lw` at 0x3628 loads 4 bytes from a0 (arg0 at entry) +0x3a0.
  The `lw` at 0x3638 loads 4 bytes from a0 (arg0 at entry) +0x3b0.
  The `lw` at 0x3640 loads 4 bytes from a0 (arg0 at entry) +0x3b4.
  The `lw` at 0x364c loads 4 bytes from a0 (arg0 at entry) +0x3b8.
  The `lw` at 0x3650 loads 4 bytes from a0 (arg0 at entry) +0x358.
  The `ld` at 0x3654 loads 8 bytes from a0 (arg0 at entry) +0x350.
  The `lw` at 0x3658 loads 4 bytes from a0 (arg0 at entry) +0x34c.
  The `lw` at 0x365c loads 4 bytes from a0 (arg0 at entry) +0x348.
  The `ld` at 0x3660 loads 8 bytes from a0 (arg0 at entry) +0x338.
  The `ld` at 0x366c loads 8 bytes from a0 (arg0 at entry) +0x380.
  The `ld` at 0x3670 loads 8 bytes from a0 (arg0 at entry) +0x378.
  The `lw` at 0x3674 loads 4 bytes from a0 (arg0 at entry) +0x374.
  The `lw` at 0x3678 loads 4 bytes from a0 (arg0 at entry) +0x370.
  The `ld` at 0x367c loads 8 bytes from a0 (arg0 at entry) +0x368.
  The `lw` at 0x3680 loads 4 bytes from a0 (arg0 at entry) +0x360.
  The `lw` at 0x368c loads 4 bytes from a0 (arg0 at entry) +0x3d0.
  The `lw` at 0x3690 loads 4 bytes from a0 (arg0 at entry) +0x3c4.
  The `lw` at 0x36b0 loads 4 bytes from a0 (arg0 at entry) +0x3e0.
  The `lw` at 0x36b4 loads 4 bytes from a0 (arg0 at entry) +0x3dc.
  The `lw` at 0x36b8 loads 4 bytes from a0 (arg0 at entry) +0x3cc.
  The `lw` at 0x36bc loads 4 bytes from a0 (arg0 at entry) +0x3c8.
  The `lw` at 0x36c8 loads 4 bytes from a0 (arg0 at entry) +0x3f0.
  The `lw` at 0x36cc loads 4 bytes from a0 (arg0 at entry) +0x3f4.
  The `lw` at 0x36d0 loads 4 bytes from a0 (arg0 at entry) +0x3ec.
  The `lw` at 0x36d4 loads 4 bytes from a0 (arg0 at entry) +0x3e8.
  The `lw` at 0x36d8 loads 4 bytes from a0 (arg0 at entry) +0x3e4.
  The `lw` at 0x36e4 loads 4 bytes from a0 (arg0 at entry) +0x404.
  The `lw` at 0x36e8 loads 4 bytes from a0 (arg0 at entry) +0x400.
  The `lw` at 0x36ec loads 4 bytes from a0 (arg0 at entry) +0x3fc.
  The `lw` at 0x36f0 loads 4 bytes from a0 (arg0 at entry) +0x3f8.
  The `lw` at 0x36fc loads 4 bytes from a0 (arg0 at entry) +0x41c.
  The `lw` at 0x3700 loads 4 bytes from a0 (arg0 at entry) +0x418.
  The `lw` at 0x3704 loads 4 bytes from a0 (arg0 at entry) +0x414.
  The `lw` at 0x3708 loads 4 bytes from a0 (arg0 at entry) +0x410.
  The `lw` at 0x370c loads 4 bytes from a0 (arg0 at entry) +0x40c.
  The `lw` at 0x3710 loads 4 bytes from a0 (arg0 at entry) +0x408.
  The `lw` at 0x371c loads 4 bytes from a0 (arg0 at entry) +0x428.
  The `lw` at 0x3720 loads 4 bytes from a0 (arg0 at entry) +0x424.
  The `lw` at 0x3724 loads 4 bytes from a0 (arg0 at entry) +0x420.
  The `jal` at 0x3610 calls ether_sprintf with a0=a0+240, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x362c calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=ret(ether_sprintf), a3=[a0+928], a4=a0+400.
  The `jal` at 0x3634 calls ef_phystr with a0=[a0+944], a1=?, a2=?, a3=?.
  The `jal` at 0x3648 calls qprintf with a0=sym(.rodata), a1=[a0+948], a2=ret(ef_phystr), a3=[a0+952].
  The `jal` at 0x3664 calls qprintf with a0=sym(.rodata), a1=[a0+824]:8, a2=[a0+840], a3=[a0+844], a4=[a0+848]:8, a5=[a0+856].
  The `jal` at 0x3684 calls qprintf with a0=sym(.rodata), a1=[a0+864], a2=[a0+872]:8, a3=[a0+880], a4=[a0+884], a5=[a0+888]:8, a6=[a0+896]:8.
  The `jal` at 0x3694 calls qprintf with a0=sym(.rodata), a1=[a0+964], a2=[a0+976], a3=?.
  The `jal` at 0x36a8 calls ef_hexdump with a0=sym(.rodata), a1=a0+956, a2=0x8, a3=?.
  The `jal` at 0x36c0 calls qprintf with a0=sym(.rodata), a1=[a0+968], a2=[a0+972], a3=[a0+988], a4=[a0+992].
  The `jal` at 0x36dc calls qprintf with a0=sym(.rodata), a1=[a0+996], a2=[a0+1000], a3=[a0+1004], a4=[a0+1012], a5=[a0+1008].
  The `jal` at 0x36f4 calls qprintf with a0=sym(.rodata), a1=[a0+1016], a2=[a0+1020], a3=[a0+1024], a4=[a0+1028].
  The `jal` at 0x3714 calls qprintf with a0=sym(.rodata), a1=[a0+1032], a2=[a0+1036], a3=[a0+1040], a4=[a0+1044], a5=[a0+1048], a6=[a0+1052].
  The `jal` at 0x3728 calls qprintf with a0=sym(.rodata), a1=[a0+1056], a2=[a0+1060], a3=[a0+1064].
  The return at 0x373c has v0 = ret(qprintf).

- `ef_dumpregs` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x3744 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x3744-0x3804 (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0x3758 loads 8 bytes from a0 (arg0 at entry) +0x330.
  The `lw` at 0x3774 loads 4 bytes from [a0+816]:8 +0x0.
  The `lw` at 0x3778 loads 4 bytes from [a0+816]:8 +0x4.
  The `lw` at 0x377c loads 4 bytes from [a0+816]:8 +0x8.
  The `lw` at 0x3788 loads 4 bytes from [a0+816]:8 +0xc.
  The `lw` at 0x378c loads 4 bytes from [a0+816]:8 +0x14.
  The `lw` at 0x3790 loads 4 bytes from [a0+816]:8 +0x10.
  The `lw` at 0x3794 loads 4 bytes from [a0+816]:8 +0x18.
  The `lw` at 0x37a0 loads 4 bytes from [a0+816]:8 +0x1c.
  The `lw` at 0x37a4 loads 4 bytes from [a0+816]:8 +0x20.
  The `lw` at 0x37a8 loads 4 bytes from [a0+816]:8 +0x24.
  The `lw` at 0x37ac loads 4 bytes from [a0+816]:8 +0x28.
  The `lw` at 0x37b0 loads 4 bytes from [a0+816]:8 +0x30.
  The `lw` at 0x37bc loads 4 bytes from [a0+816]:8 +0x3c.
  The `lw` at 0x37c0 loads 4 bytes from [a0+816]:8 +0x38.
  The `lw` at 0x37c4 loads 4 bytes from [a0+816]:8 +0x40.
  The `lw` at 0x37c8 loads 4 bytes from [a0+816]:8 +0x44.
  The `lw` at 0x37d4 loads 4 bytes from [a0+816]:8 +0x34.
  The `lw` at 0x37d8 loads 4 bytes from [a0+816]:8 +0x4c.
  The `lw` at 0x37dc loads 4 bytes from [a0+816]:8 +0x48.
  The `lw` at 0x37e0 loads 4 bytes from [a0+816]:8 +0x54.
  The `lw` at 0x37e4 loads 4 bytes from [a0+816]:8 +0x50.
  The `jal` at 0x3760 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x376c calls qprintf with a0=sym(.rodata), a1=[a0+816]:8, a2=?, a3=?.
  The `jal` at 0x3780 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8], a2=[[a0+816]:8+4], a3=[[a0+816]:8+8].
  The `jal` at 0x3798 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+12], a2=[[a0+816]:8+20], a3=[[a0+816]:8+16], a4=[[a0+816]:8+24].
  The `jal` at 0x37b4 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+28], a2=[[a0+816]:8+32], a3=[[a0+816]:8+36], a4=[[a0+816]:8+40], a5=[[a0+816]:8+48].
  The `jal` at 0x37cc calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+60], a2=[[a0+816]:8+56], a3=[[a0+816]:8+64], a4=[[a0+816]:8+68].
  The `jal` at 0x37e8 calls qprintf with a0=sym(.rodata), a1=[[a0+816]:8+52], a2=[[a0+816]:8+76], a3=[[a0+816]:8+72], a4=[[a0+816]:8+84], a5=[[a0+816]:8+80].
  The return at 0x37fc has v0 = ret(qprintf).

- `ef_dumpphy` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x3804 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x3804-0x38a8 (164 bytes).
  It occupies 164 bytes.
  The `jal` at 0x3840 calls ef_phyget with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3850 calls qprintf with a0=sym(.rodata), a1=?, a2=ret(ef_phyget), a3=?.
  The `jal` at 0x3868 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3884 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3828 targets 0x383c and is always taken.
  The `beq` branch at 0x3838 targets 0x3878, is taken when s0(?) >= 0x20 (signed), and falls through when s0(?) < 0x20 (signed).
  The `bne` branch at 0x3860 targets 0x3830, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `beq` branch at 0x3870 targets 0x3830 and is always taken.
  The `beq` branch at 0x3878 targets 0x3890, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The return at 0x38a0 has v0 = one of ?, ret(qprintf).

- `ef_hexdump` in `IP27/usr/cpu/sysgen/IP27boot/if_ef.o` at 0x38a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/if_ef.o`.
  Range: 0x38a8-0x39a8 (256 bytes).
  It occupies 256 bytes.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x38e8, `lbu` at 0x38fc, `lbu` at 0x396c.
  2 such `lbu` accesses load 1 byte from table(sym(.data)) +0x28, including `lbu` at 0x38f4, `lbu` at 0x3914.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x38f8, `sb` at 0x391c, `sb` at 0x3928.
  The `jal` at 0x3980 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=sp-528, a3=?, a7=sp-528.
  The `blez` branch at 0x38d4 targets 0x3994, is taken when t0(?) <= 0 (signed), and falls through when t0(?) > 0 (signed).
  The `beq` branch at 0x38e0 targets 0x399c and is always taken.
  The `beq` branch at 0x3924 targets 0x3970, is taken when a5(?) >= t0(?) (signed), and falls through when a5(?) < t0(?) (signed).
  The `bne` branch at 0x3948 targets 0x38e8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x3950 targets 0x3968, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3960 targets 0x38e8 and is always taken.
  The `beq` branch at 0x3968 targets 0x38ec and is always taken.
  The `beq` branch at 0x3994 targets 0x3974 and is always taken.
  The `beq` branch at 0x39a0 targets 0x3930 and is always taken.
  The return at 0x398c has v0 = ret(qprintf).
