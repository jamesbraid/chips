# Readings: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`

One entry per routine, filed here from the reading batches by binary.

- `a3_probe` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x0-0x138 (312 bytes).
  It occupies 312 bytes.
  The `sw` at 0xec stores 4 bytes to ret(kmem_alloc) +0x770.
  The `sw` at 0xf0 stores 4 bytes to ret(kmem_alloc) +0x980.
  The `sw` at 0xf4 stores 4 bytes to ret(kmem_alloc) +0xb90.
  The `sw` at 0x108 stores 4 bytes to ret(kmem_alloc) +0x150.
  The `jal` at 0x10 calls pciio_pio_read64 with a0=0xffffffffbf300000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c calls pciio_pio_write64 with a0=0x1, a1=0xffffffffbf300000, a2=?, a3=?.
  The `jal` at 0x34 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x40 calls pciio_pio_write64 with a0=0x0, a1=0xffffffffbf300000, a2=?, a3=?.
  The `jal` at 0x50 calls pciio_pio_write64 with a0=0x10000, a1=0xffffffffbf300008, a2=?, a3=?.
  The `jal` at 0x58 calls wbflush with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x60 calls us_delay with a0=0xa8, a1=?, a2=?, a3=?.
  The `jal` at 0x6c calls pciio_pio_read64 with a0=0xffffffffbf300018, a1=?, a2=?, a3=?.
  The `jal` at 0x7c calls kmem_alloc with a0=0x1728, a1=0x0, a2=?, a3=?.
  The `jal` at 0x98 calls bcopy with a0=sym(.data), a1=ret(kmem_alloc), a2=0x1728, a3=?.
  The `jal` at 0xc4 calls kdsp_init_resource with a0=ret(kmem_alloc), a1=0x2000001f, a2=sym(.rodata)+48, a3=0x0, a4=0x0, a5=sym(.data), a6=0x1728.
  The `jal` at 0xe4 calls add_to_inventory with a0=0xa, a1=0x4, a2=0x0, a3=0x0.
  The `jal` at 0x104 calls kdsp_add_subsys with a0=ret(kmem_alloc), a1=0x0, a2=?, a3=?.
  The `jal` at 0x128 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x20 targets 0x110, is taken when (at(=(ret(pciio_pio_read64) << 0x0)) & 0x2) == 0, and falls through when (at(=(ret(pciio_pio_read64) << 0x0)) & 0x2) != 0.
  The `beq` branch at 0x84 targets 0x120, is taken when v0(=ret(kmem_alloc)) == 0, and falls through when v0(=ret(kmem_alloc)) != 0.
  The `beq` branch at 0x130 targets 0x110 and is always taken.
  The return at 0x118 has v0 = one of 0x0, 0x1.

- `a3_start_subsys` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x138 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x138-0x448 (784 bytes).
  It occupies 784 bytes.
  The `sw` at 0x150 stores 4 bytes to sym(.bss) +0x0.
  The `sw` at 0x15c stores 4 bytes to sym(.bss) +0x18.
  The `sw` at 0x164 stores 4 bytes to sym(.bss) +0x10.
  The `sw` at 0x170 stores 4 bytes to sym(.bss) +0x8.
  The `lw` at 0x1b4 loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `sw` at 0x1c4 stores 4 bytes to a0 (arg0 at entry) +0x6fc.
  The `sw` at 0x1d0 stores 4 bytes to a0 (arg0 at entry) +0x598.
  The `sw` at 0x1f4 stores 4 bytes to (a0 + (one of 0x0, 0x1 << 0x2)) +0x5a8.
  The `sw` at 0x200 stores 4 bytes to (a0 + (one of 0x0, 0x1 << 0x2)) +0x5a4.
  The `sw` at 0x20c stores 4 bytes to (a0 + (one of 0x0, 0x1 << 0x2)) +0x59c.
  The `sw` at 0x218 stores 4 bytes to (a0 + (one of 0x0, 0x1 << 0x2)) +0x5a0.
  The `sw` at 0x224 stores 4 bytes to (a0 + (one of 0x0, 0x1 << 0x2)) +0x598.
  The `sw` at 0x240 stores 4 bytes to a0 (arg0 at entry) +0x7ac.
  The `sw` at 0x24c stores 4 bytes to a0 (arg0 at entry) +0x7a8.
  The `sw` at 0x264 stores 4 bytes to a0 (arg0 at entry) +0x90c.
  The `sw` at 0x270 stores 4 bytes to a0 (arg0 at entry) +0xb1c.
  The `sw` at 0x278 stores 4 bytes to a0 (arg0 at entry) +0x9b8.
  The `sw` at 0x284 stores 4 bytes to a0 (arg0 at entry) +0x9bc.
  The `sw` at 0x2f4 stores 4 bytes to a0 (arg0 at entry) +0x138.
  The `sw` at 0x2fc stores 4 bytes to a0 (arg0 at entry) +0x13c.
  The `lw` at 0x324 loads 4 bytes from a0 (arg0 at entry) +0x1f4.
  The `sw` at 0x370 stores 4 bytes to a0 (arg0 at entry) +0x1f8.
  The `sw` at 0x37c stores 4 bytes to a0 (arg0 at entry) +0x1fc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e0, including `lw` at 0x3a4, `lw` at 0x420.
  The `sw` at 0x430 stores 4 bytes to a0 (arg0 at entry) +0x1e0.
  The `jal` at 0x144 calls a3_idbg_addfuncs with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16c calls a3_init_codec with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x17c calls a3_check_for_video with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1a4 calls a3_create_device with a0=a0 at entry (arg0), a1=a0+1384, a2=0x0, a3=0x0, a4=sym(.rodata), a5=sym(.rodata).
  The `jal` at 0x220 calls a3_create_device with a0=a0 at entry (arg0), a1=a0+1912, a2=0x1, a3=0x1, a4=sym(.rodata), a5=sym(.rodata), a6=a0+4600, a7=a0+5224.
  The `jal` at 0x260 calls a3_create_device with a0=a0 at entry (arg0), a1=a0+2440, a2=0x1, a3=0x2, a4=sym(.rodata), a5=sym(.rodata), a6=a0+4872.
  The `jal` at 0x288 calls a3_create_mclks with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a7=a0+5576.
  The `jal` at 0x2a0 calls a3_create_clockgen with a0=a0+5224, a1=a0+1384, a2=0x13, a3=a0+520.
  The `jal` at 0x2b8 calls a3_create_clockgen with a0=a0+4872, a1=a0+1912, a2=0x10, a3=a0+520.
  The `jal` at 0x2d0 calls a3_create_clockgen with a0=a0+5576, a1=a0+2440, a2=0x16, a3=a0+520.
  The `jal` at 0x2e0 calls a3_create_ifs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2ec calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x300 calls pciio_pio_write64 with a0=0x0, a1=0xffffffffbf300000, a2=?, a3=?.
  The `jal` at 0x308 calls pciio_pio_read64 with a0=0xffffffffbf300000, a1=?, a2=?, a3=?.
  The `jal` at 0x378 calls setcrimevector with a0=0x6, a1=0x2, a2=sym(a3_err_intr), a3=a0 at entry (arg0), a4=0x1.
  The `jal` at 0x388 calls splhi with a0=?, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x39c calls pciio_pio_read64 with a0=0xffffffffbf310018, a1=?, a2=?, a3=?.
  The `jal` at 0x3b8 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf310018, a2=?, a3=?.
  The `jal` at 0x3c0 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x418 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x438 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(setcrimevector), a3=?.
  The `beq` branch at 0x1ac targets 0x408, is taken when v0(=ret(a3_create_device)) == 0, and falls through when v0(=ret(a3_create_device)) != 0.
  The `beq` branch at 0x1c0 targets 0x1d4, is taken when t9(=[a0+488]) == 0, and falls through when t9(=[a0+488]) != 0.
  The `beq` branch at 0x228 targets 0x3e8, is taken when v0(=ret(a3_create_device)) == 0, and falls through when v0(=ret(a3_create_device)) != 0.
  The `beq` branch at 0x268 targets 0x3f0, is taken when v0(=ret(a3_create_device)) == 0, and falls through when v0(=ret(a3_create_device)) != 0.
  The `beq` branch at 0x2a8 targets 0x3f8, is taken when v0(=ret(a3_create_clockgen)) == 0, and falls through when v0(=ret(a3_create_clockgen)) != 0.
  The `beq` branch at 0x2c0 targets 0x400, is taken when v0(=ret(a3_create_clockgen)) == 0, and falls through when v0(=ret(a3_create_clockgen)) != 0.
  The `beq` branch at 0x2d8 targets 0x410, is taken when v0(=ret(a3_create_clockgen)) == 0, and falls through when v0(=ret(a3_create_clockgen)) != 0.
  The `bne` branch at 0x31c targets 0x418, is taken when (t2(=(ret(pciio_pio_read64) << 0x0)) & t3(=0x1800000)) != 0, and falls through when (t2(=(ret(pciio_pio_read64) << 0x0)) & t3(=0x1800000)) == 0.
  The `bne` branch at 0x380 targets 0x434, is taken when v0(=ret(setcrimevector)) != 0, and falls through when v0(=ret(setcrimevector)) == 0.
  The `beq` branch at 0x3e8 targets 0x3cc and is always taken.
  The `beq` branch at 0x3f0 targets 0x3cc and is always taken.
  The `beq` branch at 0x3f8 targets 0x3cc and is always taken.
  The `beq` branch at 0x400 targets 0x3cc and is always taken.
  The `beq` branch at 0x408 targets 0x3cc and is always taken.
  The `beq` branch at 0x410 targets 0x3cc and is always taken.
  The `beq` branch at 0x42c targets 0x3c8 and is always taken.
  The `beq` branch at 0x440 targets 0x3cc and is always taken.
  The return at 0x3e0 has v0 = one of 0x0, 0x1.

- `a3_create_ifs` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x448 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x448-0x8a4 (1116 bytes).
  It occupies 1116 bytes.
  The `sw` at 0x4b0 stores 4 bytes to a0 (arg0 at entry) +0x10e0.
  The `sw` at 0x4b8 stores 4 bytes to a0 (arg0 at entry) +0x10e4.
  The `sw` at 0x4c4 stores 4 bytes to a0 (arg0 at entry) +0x106c.
  The `sw` at 0x4d4 stores 4 bytes to a0 (arg0 at entry) +0xfdc.
  The `sw` at 0x4e0 stores 4 bytes to a0 (arg0 at entry) +0xfe0.
  The `sw` at 0x4f0 stores 4 bytes to a0 (arg0 at entry) +0xfe8.
  The `sw` at 0x530 stores 4 bytes to a0 (arg0 at entry) +0xf5c.
  The `sw` at 0x538 stores 4 bytes to a0 (arg0 at entry) +0xed8.
  The `sw` at 0x53c stores 4 bytes to a0 (arg0 at entry) +0xed0.
  The `sw` at 0x540 stores 4 bytes to a0 (arg0 at entry) +0xecc.
  The `sw` at 0x544 stores 4 bytes to a0 (arg0 at entry) +0xfd4.
  The `sw` at 0x54c stores 4 bytes to a0 (arg0 at entry) +0xfd0.
  The `sd` at 0x568 stores 8 bytes to sym(.bss) +0xe8.
  The `sd` at 0x570 stores 8 bytes to sym(.bss) +0xa8.
  The `sd` at 0x574 stores 8 bytes to sym(.bss) +0xa0.
  The `sd` at 0x57c stores 8 bytes to sym(.bss) +0xd0.
  The `sd` at 0x584 stores 8 bytes to sym(.bss) +0xb0.
  The `sd` at 0x588 stores 8 bytes to sym(.bss) +0xb8.
  The `sw` at 0x590 stores 4 bytes to sym(.bss) +0xc0.
  The `sd` at 0x59c stores 8 bytes to sym(.bss) +0xe0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e8, including `lw` at 0x5b4, `lw` at 0x6b8, `lw` at 0x7e0.
  The `sw` at 0x5ec stores 4 bytes to a0 (arg0 at entry) +0xd3c.
  The `sw` at 0x5f4 stores 4 bytes to a0 (arg0 at entry) +0xcb8.
  The `sw` at 0x5f8 stores 4 bytes to a0 (arg0 at entry) +0xdb4.
  The `sw` at 0x5fc stores 4 bytes to a0 (arg0 at entry) +0xdb0.
  The `sw` at 0x60c stores 4 bytes to a0 (arg0 at entry) +0xcb0.
  The `sw` at 0x614 stores 4 bytes to a0 (arg0 at entry) +0xcac.
  The `sw` at 0x628 stores 4 bytes to sym(.bss) +0x70.
  The `sw` at 0x634 stores 4 bytes to sym(.bss) +0x88.
  The `sd` at 0x63c stores 8 bytes to sym(.bss) +0x68.
  The `sd` at 0x640 stores 8 bytes to sym(.bss) +0x60.
  The `sd` at 0x64c stores 8 bytes to sym(.bss) +0x50.
  The `sd` at 0x658 stores 8 bytes to sym(.bss) +0x90.
  The `sd` at 0x670 stores 8 bytes to sym(.bss) +0x98.
  The `sd` at 0x67c stores 8 bytes to sym(.bss) +0x80.
  The `sd` at 0x694 stores 8 bytes to sym(.bss) +0x78.
  The `sd` at 0x6a0 stores 8 bytes to sym(.bss) +0x58.
  The `sw` at 0x6a8 stores 4 bytes to a0 (arg0 at entry) +0xc2c.
  The `sw` at 0x6b0 stores 4 bytes to a0 (arg0 at entry) +0xba8.
  The `sw` at 0x6b4 stores 4 bytes to a0 (arg0 at entry) +0xba0.
  The `sw` at 0x6bc stores 4 bytes to a0 (arg0 at entry) +0xb9c.
  The `sw` at 0x6c0 stores 4 bytes to a0 (arg0 at entry) +0xca4.
  The `sw` at 0x6c8 stores 4 bytes to a0 (arg0 at entry) +0xca0.
  The `sw` at 0x728 stores 4 bytes to a0 (arg0 at entry) +0xe4c.
  The `sw` at 0x734 stores 4 bytes to a0 (arg0 at entry) +0xdc8.
  The `sw` at 0x73c stores 4 bytes to a0 (arg0 at entry) +0xdc0.
  The `sw` at 0x744 stores 4 bytes to a0 (arg0 at entry) +0xdbc.
  The `sw` at 0x75c stores 4 bytes to a0 (arg0 at entry) +0xec4.
  The `sw` at 0x768 stores 4 bytes to a0 (arg0 at entry) +0xec0.
  The `sw` at 0x780 stores 4 bytes to a0 (arg0 at entry) +0x10f0.
  The `sw` at 0x78c stores 4 bytes to a0 (arg0 at entry) +0x10ec.
  The `sw` at 0x790 stores 4 bytes to a0 (arg0 at entry) +0x11f4.
  The `sw` at 0x79c stores 4 bytes to a0 (arg0 at entry) +0x10f8.
  The `sw` at 0x7a8 stores 4 bytes to a0 (arg0 at entry) +0x117c.
  The `sw` at 0x7c0 stores 4 bytes to a0 (arg0 at entry) +0x11f0.
  The `sw` at 0x7d0 stores 4 bytes to a0 (arg0 at entry) +0x128c.
  The `sw` at 0x7d8 stores 4 bytes to a0 (arg0 at entry) +0x1208.
  The `sw` at 0x7dc stores 4 bytes to a0 (arg0 at entry) +0x1200.
  The `sw` at 0x7e4 stores 4 bytes to a0 (arg0 at entry) +0x11fc.
  The `sw` at 0x7e8 stores 4 bytes to a0 (arg0 at entry) +0x1300.
  The `sw` at 0x7f0 stores 4 bytes to a0 (arg0 at entry) +0x1304.
  The `jal` at 0x4a4 calls kdsp_init_resource with a0=a0+4056, a1=0x2000000e, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x4ec calls kdsp_add_subresource with a0=a0+2440, a1=a0+4056, a2=?, a3=?.
  The `jal` at 0x4fc calls a3_write_output_gain with a0=a0 at entry (arg0), a1=0xa, a2=a0+380, a3=?.
  The `jal` at 0x528 calls kdsp_init_resource with a0=a0+3784, a1=0x20000021, a2=sym(.rodata)+376, a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x598 calls kdsp_add_subresource with a0=a0+1912, a1=a0+3784, a2=?, a3=0xaaaaaaab, a4=sym(.bss), a5=0x3, a6=0x180000000, a7=0xe55ffbcf5.
  The `jal` at 0x5ac calls a3_write_output_gain with a0=a0 at entry (arg0), a1=0x9, a2=a0+372, a3=?.
  The `jal` at 0x5e0 calls kdsp_init_resource with a0=a0+3240, a1=0x2000000d, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x69c calls kdsp_init_resource with a0=a0+2968, a1=0x2000000d, a2=sym(.rodata), a3=0x0, a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x6d0 calls kdsp_select_interface with a0=a0+1384, a1=a0+3240, a2=?, a3=?.
  The `jal` at 0x6dc calls a3_write_input_source with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x6e8 calls a3_write_input_gain with a0=a0 at entry (arg0), a1=a0+356, a2=?, a3=?.
  The `jal` at 0x71c calls kdsp_init_resource with a0=a0+3512, a1=0x2000000e, a2=sym(.rodata)+384, a3=sym(.rodata)+392, a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x76c calls kdsp_init_resource with a0=a0+4328, a1=0x20000020, a2=sym(.rodata)+400, a3=sym(.rodata)+408, a4=a0 at entry (arg0), a5=0x0, a6=0x110, a7=sym(.data).
  The `jal` at 0x7c4 calls kdsp_init_resource with a0=a0+4600, a1=0x20000020, a2=sym(.rodata)+416, a3=sym(.rodata)+424, a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x7f8 calls kdsp_map_resource with a0=a0+3240, a1=0x0, a2=?, a3=?, a4=[a0+488], a5=sym(.data), a6=0x8.
  The `jal` at 0x81c calls kdsp_map_resource with a0=a0+2968, a1=0x0, a2=?, a3=?.
  The `jal` at 0x828 calls kdsp_map_resource with a0=a0+3512, a1=0x0, a2=?, a3=?.
  The `jal` at 0x838 calls kdsp_map_resource with a0=a0+3784, a1=0x0, a2=?, a3=?.
  The `jal` at 0x844 calls kdsp_map_resource with a0=a0+4056, a1=0x0, a2=?, a3=?.
  The `jal` at 0x854 calls kdsp_map_resource with a0=a0+4328, a1=0x0, a2=?, a3=?.
  The `jal` at 0x860 calls kdsp_map_resource with a0=a0+4600, a1=0x0, a2=?, a3=?.
  The `jal` at 0x87c calls kdsp_select_interface with a0=a0+1384, a1=a0+2968, a2=?, a3=?.
  The `jal` at 0x888 calls a3_write_input_source with a0=a0 at entry (arg0), a1=0x2020, a2=?, a3=?.
  The `jal` at 0x894 calls a3_write_input_gain with a0=a0 at entry (arg0), a1=a0+348, a2=?, a3=?.
  The `beq` branch at 0x5c0 targets 0x618, is taken when a6(=[a0+488]) == 0, and falls through when a6(=[a0+488]) != 0.
  The `beq` branch at 0x6c4 targets 0x878, is taken when ra(=[a0+488]) == 0, and falls through when ra(=[a0+488]) != 0.
  The `beq` branch at 0x7ec targets 0x800, is taken when a4(=[a0+488]) == 0, and falls through when a4(=[a0+488]) != 0.
  The `beq` branch at 0x89c targets 0x6f4 and is always taken.
  The return at 0x870 has v0 = 0x1.

- `a3_create_mclks` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x8a4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x8a4-0x9f8 (340 bytes).
  It occupies 340 bytes.
  The `sw` at 0x8f8 stores 4 bytes to a0 (arg0 at entry) +0x324.
  The `sw` at 0x908 stores 4 bytes to a0 (arg0 at entry) +0x29c.
  The `sd` at 0x914 stores 8 bytes to a0 (arg0 at entry) +0x310.
  The `sw` at 0x924 stores 4 bytes to a0 (arg0 at entry) +0x218.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e8, including `lw` at 0x928, `lw` at 0x980.
  The `sw` at 0x95c stores 4 bytes to a0 (arg0 at entry) +0x444.
  The `sd` at 0x960 stores 8 bytes to a0 (arg0 at entry) +0x430.
  The `sw` at 0x968 stores 4 bytes to a0 (arg0 at entry) +0x338.
  The `sw` at 0x974 stores 4 bytes to a0 (arg0 at entry) +0x3bc.
  The `sw` at 0x9b4 stores 4 bytes to a0 (arg0 at entry) +0x564.
  The `sd` at 0x9b8 stores 8 bytes to a0 (arg0 at entry) +0x550.
  The `sw` at 0x9c0 stores 4 bytes to a0 (arg0 at entry) +0x458.
  The `sw` at 0x9c8 stores 4 bytes to a0 (arg0 at entry) +0x4dc.
  The `jal` at 0x8ec calls kdsp_init_resource with a0=a0+520, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x120.
  The `jal` at 0x920 calls kdsp_map_resource with a0=a0+520, a1=0x0, a2=?, a3=?.
  The `jal` at 0x950 calls kdsp_init_resource with a0=a0+808, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x120.
  The `jal` at 0x978 calls kdsp_map_resource with a0=a0+808, a1=0x0, a2=0x2, a3=sym(.data), a4=0x1.
  The `jal` at 0x9a8 calls kdsp_init_resource with a0=a0+1096, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x120.
  The `jal` at 0x9cc calls kdsp_map_resource with a0=a0+1096, a1=0x0, a2=0x2, a3=sym(.data).
  The `beq` branch at 0x92c targets 0x9d4, is taken when t8(=[a0+488]) == 0, and falls through when t8(=[a0+488]) != 0.
  The `beq` branch at 0x984 targets 0x9d4, is taken when a5(=[a0+488]) == 0, and falls through when a5(=[a0+488]) != 0.
  The return at 0x9f0 has v0 = 0x1.

- `a3_create_clockgen` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x9f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x9f8-0xbb8 (448 bytes).
  It occupies 448 bytes.
  The `lw` at 0xa28 loads 4 bytes from a1 (arg1 at entry) +0x1d0.
  The `sw` at 0xa74 stores 4 bytes to a0 (arg0 at entry) +0x13c.
  The `sw` at 0xa78 stores 4 bytes to a0 (arg0 at entry) +0x130.
  The `sw` at 0xa80 stores 4 bytes to a0 (arg0 at entry) +0x12c.
  The `sw` at 0xa84 stores 4 bytes to a0 (arg0 at entry) +0x124.
  The `sw` at 0xa88 stores 4 bytes to a0 (arg0 at entry) +0x128.
  The `sw` at 0xa8c stores 4 bytes to a0 (arg0 at entry) +0x120.
  The `sw` at 0xa90 stores 4 bytes to a0 (arg0 at entry) +0x138.
  The `sw` at 0xa94 stores 4 bytes to a0 (arg0 at entry) +0x134.
  The `sw` at 0xa9c stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sd` at 0xaa8 stores 8 bytes to a0 (arg0 at entry) +0x118.
  The `sd` at 0xab0 stores 8 bytes to a0 (arg0 at entry) +0x110.
  The `sw` at 0xabc stores 4 bytes to a0 (arg0 at entry) +0xc.
  The `sw` at 0xac8 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0xad0 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `lw` at 0xad4 loads 4 bytes from a1 (arg1 at entry) +0x1a4.
  The `sw` at 0xaf4 stores 4 bytes to a0 (arg0 at entry) +0x144.
  The `sw` at 0xafc stores 4 bytes to a0 (arg0 at entry) +0x30.
  The `sw` at 0xb00 stores 4 bytes to a0 (arg0 at entry) +0x108.
  The `sw` at 0xb0c stores 4 bytes to a0 (arg0 at entry) +0x148.
  2 such `lw` accesses load 4 bytes from [a1+464] +0x1e8, including `lw` at 0xb18, `lw` at 0xba4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x34, including `sw` at 0xb24, `sw` at 0xbb4.
  The `sw` at 0xb28 stores 4 bytes to a0 (arg0 at entry) +0x158.
  The `sw` at 0xb2c stores 4 bytes to a0 (arg0 at entry) +0x150.
  The `sw` at 0xb38 stores 4 bytes to a0 (arg0 at entry) +0x15c.
  The `sw` at 0xb60 stores 4 bytes to a0 (arg0 at entry) +0x154.
  The `jal` at 0xa30 calls sprintf with a0=sp-112, a1=sym(.rodata)+528, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa44 calls sprintf with a0=sp-80, a1=sym(.rodata)+536, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa68 calls kdsp_init_resource with a0=a0 at entry (arg0), a1=0x20000004, a2=sp-112, a3=sp-80, a4=[a1+464], a5=0x0, a6=0x160.
  The `jal` at 0xb3c calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=a0 at entry (arg0), a2=?, a3=0x60, a4=0xbb8000000000, a5=sym(a3_commit_clockgen_params), a6=0x5, a7=sym(.data)+6392.
  The `jal` at 0xb58 calls kdsp_add_subresource with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0xb64 calls a3_calculate_rate_frac with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb74 calls a3_set_clockgen with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0xb80 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0xaec targets 0xb9c, is taken when (a2(=[a1+420]) & 0x1) == 0, and falls through when (a2(=[a1+420]) & 0x1) != 0.
  The `beq` branch at 0xb08 targets 0xba4, is taken when s2(=a2) == t2(=0x10), and falls through when s2(=a2) != t2(=0x10).
  The `bne` branch at 0xb10 targets 0xb28, is taken when s2(=a2) != a1(=0x13), and falls through when s2(=a2) == a1(=0x13).
  The `beq` branch at 0xb1c targets 0xb28, is taken when t9(=[[a1+464]+488]) == 0, and falls through when t9(=[[a1+464]+488]) != 0.
  The `beq` branch at 0xb9c targets 0xaf4 and is always taken.
  The `beq` branch at 0xba8 targets 0xb28, is taken when at(=[[a1+464]+488]) == 0, and falls through when at(=[[a1+464]+488]) != 0.
  The `beq` branch at 0xbb0 targets 0xb28 and is always taken.
  The return at 0xb94 has v0 = 0x1.

- `a3_create_device` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0xbb8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0xbb8-0xdf8 (576 bytes).
  It occupies 576 bytes.
  The `sw` at 0xc98 stores 4 bytes to a1 (arg1 at entry) +0x1d0.
  The `sw` at 0xca0 stores 4 bytes to a1 (arg1 at entry) +0x1cc.
  The `sw` at 0xca4 stores 4 bytes to a1 (arg1 at entry) +0x1e0.
  The `sw` at 0xca8 stores 4 bytes to a1 (arg1 at entry) +0x1f4.
  The `sw` at 0xcac stores 4 bytes to a1 (arg1 at entry) +0x1e4.
  The `sw` at 0xcb0 stores 4 bytes to a1 (arg1 at entry) +0x1e8.
  The `sw` at 0xcb4 stores 4 bytes to a1 (arg1 at entry) +0x1ec.
  The `sw` at 0xcb8 stores 4 bytes to a1 (arg1 at entry) +0x208.
  The `sw` at 0xcc8 stores 4 bytes to a1 (arg1 at entry) +0x94.
  The `sw` at 0xcd8 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `sw` at 0xce4 stores 4 bytes to a1 (arg1 at entry) +0xc.
  The `sw` at 0xcf0 stores 4 bytes to a1 (arg1 at entry) +0x10.
  The `sw` at 0xcfc stores 4 bytes to a1 (arg1 at entry) +0x1b8.
  The `sw` at 0xd08 stores 4 bytes to a1 (arg1 at entry) +0x1bc.
  The `sw` at 0xd14 stores 4 bytes to a1 (arg1 at entry) +0x1c0.
  The `sw` at 0xd20 stores 4 bytes to a1 (arg1 at entry) +0x1c4.
  The `sw` at 0xd2c stores 4 bytes to a1 (arg1 at entry) +0x14c.
  The `sw` at 0xd38 stores 4 bytes to a1 (arg1 at entry) +0x154.
  The `sw` at 0xd44 stores 4 bytes to a1 (arg1 at entry) +0x158.
  The `jal` at 0xc0c calls a3_get_dma_rb_addr with a0=a3 at entry (arg3), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc64 calls kdsp_init_resource with a0=a1 at entry (arg1), a1=one of 0x2000001b, 0x2000001c, a2=a4 at entry (arg4), a3=a5 at entry (arg5), a4=a0 at entry (arg0), a5=0x0, a6=0x210.
  The `jal` at 0xc88 calls kdsp_create_device with a0=a1 at entry (arg1), a1=0x400, a2=(a2 | 0x40), a3=0x0, a4=ret(a3_get_dma_rb_addr), a5=0x2, a6=0x0.
  The `jal` at 0xd40 calls kdsp_add_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=sym(a3_get_rb_mscust), a4=sym(a3_cg_update_hrb), a5=sym(a3_pre_connect), a6=sym(a3_stop_dma), a7=sym(a3_start_dma).
  The `jal` at 0xd78 calls a3_destroy_devices with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xdcc calls cmn_err with a0=0x4, a1=sym(.rodata)+544, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xde8 calls cmn_err with a0=0x4, a1=sym(.rodata)+544, a2=a3 at entry (arg3), a3=?.
  The `beq` branch at 0xc00 targets 0xd88, is taken when a2 == t1(=0x1), and falls through when a2 != t1(=0x1).
  The `beq` branch at 0xc1c targets 0xdc0, is taken when v0(=ret(a3_get_dma_rb_addr)) == 0, and falls through when v0(=ret(a3_get_dma_rb_addr)) != 0.
  The `beq` branch at 0xc24 targets 0xd90, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `beq` branch at 0xc30 targets 0xda8, is taken when s0(=a3) == v0(=0x1), and falls through when s0(=a3) != v0(=0x1).
  The `bne` branch at 0xc38 targets 0xddc, is taken when s0(=a3) != a0(=0x2), and falls through when s0(=a3) == a0(=0x2).
  The `beq` branch at 0xc90 targets 0xd78, is taken when v0(=ret(kdsp_create_device)) == 0, and falls through when v0(=ret(kdsp_create_device)) != 0.
  The `beq` branch at 0xd80 targets 0xd4c and is always taken.
  The `beq` branch at 0xd88 targets 0xc0c and is always taken.
  The `beq` branch at 0xda0 targets 0xc4c and is always taken.
  The `beq` branch at 0xdb8 targets 0xc4c and is always taken.
  The `beq` branch at 0xdd4 targets 0xd4c and is always taken.
  The `beq` branch at 0xdf0 targets 0xd4c and is always taken.
  The return at 0xd70 has v0 = one of -0x1, 0x0, 0x1.

- `a3_destroy_devices` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0xdf8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0xdf8-0xed8 (224 bytes).
  It occupies 224 bytes.
  The `lw` at 0xdf8 loads 4 bytes from a0 (arg0 at entry) +0x738.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x948, including `lw` at 0xe10, `lw` at 0xe7c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xb58, including `lw` at 0xe1c, `lw` at 0xea4.
  The `lw` at 0xeac loads 4 bytes from a0 (arg0 at entry) +0xab8.
  The `lw` at 0xebc loads 4 bytes from a0 (arg0 at entry) +0x698.
  The `lw` at 0xecc loads 4 bytes from a0 (arg0 at entry) +0x8a8.
  The `jal` at 0xe28 calls get_cpu_irr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xe40 calls kdsp_destroy_device with a0=a0+2440, a1=?, a2=?, a3=?.
  The `jal` at 0xe58 calls get_cpu_irr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe70 calls kdsp_destroy_device with a0=a0+1384, a1=?, a2=?, a3=?.
  The `jal` at 0xe80 calls get_cpu_irr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xe98 calls kdsp_destroy_device with a0=a0+1912, a1=?, a2=?, a3=?.
  The `jal` at 0xea8 calls page_mapout with a0=[a0+2744], a1=?, a2=?, a3=?.
  The `jal` at 0xeb8 calls page_mapout with a0=[a0+1688], a1=?, a2=?, a3=?.
  The `jal` at 0xec8 calls page_mapout with a0=[a0+2216], a1=?, a2=?, a3=?.
  The `bne` branch at 0xe08 targets 0xe58, is taken when at(=[a0+1848]) != 0, and falls through when at(=[a0+1848]) == 0.
  The `bne` branch at 0xe14 targets 0xe80, is taken when v0(=[a0+2376]) != 0, and falls through when v0(=[a0+2376]) == 0.
  The `beq` branch at 0xe20 targets 0xe4c, is taken when v1(=[a0+2904]) == 0, and falls through when v1(=[a0+2904]) != 0.
  The `bne` branch at 0xe38 targets 0xea8, is taken when a0(?) < 0x23 (signed), and falls through when a0(?) >= 0x23 (signed).
  The `bne` branch at 0xe68 targets 0xeb8, is taken when a1(?) < 0x23 (signed), and falls through when a1(?) >= 0x23 (signed).
  The `beq` branch at 0xe78 targets 0xe14 and is always taken.
  The `bne` branch at 0xe90 targets 0xec8, is taken when a2(?) < 0x23 (signed), and falls through when a2(?) >= 0x23 (signed).
  The `beq` branch at 0xea0 targets 0xe20 and is always taken.
  The `beq` branch at 0xeb0 targets 0xe40 and is always taken.
  The `beq` branch at 0xec0 targets 0xe70 and is always taken.
  The `beq` branch at 0xed0 targets 0xe98 and is always taken.
  The return at 0xe50 has v0 = one of ?, ret(kdsp_destroy_device).

- `a3_edtinit` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0xed8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0xed8-0xef4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xee0 calls a3_probe with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xeec has v0 = ret(a3_probe).

- `a3_init_codec` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0xef4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0xef4-0x112c (568 bytes).
  It occupies 568 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1d8, including `sw` at 0xf34, `sw` at 0xfd4.
  The `lhu` at 0xf98 loads 2 bytes from a0 (arg0 at entry) +0x1c8.
  The `lw` at 0xfb0 loads 4 bytes from a0 (arg0 at entry) +0x1d8.
  2 such `lhu` accesses load 2 bytes from a0 (arg0 at entry) +0x1cc, including `lhu` at 0xfc4, `lhu` at 0x1078.
  The `lhu` at 0x102c loads 2 bytes from a0 (arg0 at entry) +0x1ca.
  The `sw` at 0x1064 stores 4 bytes to a0 (arg0 at entry) +0x1d4.
  The `lhu` at 0x10a0 loads 2 bytes from a0 (arg0 at entry) +0x1a6.
  The `lhu` at 0x10c0 loads 2 bytes from a0 (arg0 at entry) +0x1a8.
  The `jal` at 0xf08 calls pciio_pio_write64 with a0=0x1, a1=0xffffffffbf300000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf10 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0xf1c calls pciio_pio_write64 with a0=0x0, a1=0xffffffffbf300000, a2=?, a3=?.
  The `jal` at 0xf38 calls bcopy with a0=sym(codec_reset_default), a1=a0+404, a2=0x40, a3=0x2a.
  The `jal` at 0xf44 calls do_read_codec_reg with a0=0x0, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xf58 calls us_delay with a0=0x1f4, a1=?, a2=?, a3=?.
  The `jal` at 0xf64 calls do_read_codec_reg with a0=0x0, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xf78 calls us_delay with a0=0x12c, a1=?, a2=?, a3=?.
  The `jal` at 0xf84 calls do_read_codec_reg with a0=0x0, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xfa8 calls do_write_codec_reg with a0=0x1a, a1=?, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0xfb8 calls us_delay with a0=?, a1=[a0+472], a2=?, a3=?.
  The `jal` at 0xfe0 calls do_write_codec_reg with a0=0x1c, a1=?, a2=a0 at entry (arg0), a3=-0x8001.
  The `jal` at 0xfec calls us_delay with a0=0x75300, a1=?, a2=?, a3=?.
  The `jal` at 0xff8 calls do_read_codec_reg with a0=0x0, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x100c calls us_delay with a0=0x186a0, a1=?, a2=?, a3=?.
  The `jal` at 0x1018 calls do_read_codec_reg with a0=0x0, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x103c calls do_write_codec_reg with a0=0x1b, a1=?, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x1048 calls is_specified with a0=sym(arg_audiopass), a1=?, a2=?, a3=?.
  The `jal` at 0x1058 calls atoi with a0=sym(arg_audiopass), a1=?, a2=?, a3=?.
  The `jal` at 0x1070 calls do_write_codec_reg with a0=0x4, a1=0x808, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x1088 calls do_write_codec_reg with a0=0x1c, a1=?, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x1098 calls do_write_codec_reg with a0=0xf, a1=0xd0a, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x10b8 calls do_write_codec_reg with a0=0x9, a1=?, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x10d8 calls do_write_codec_reg with a0=0xa, a1=?, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x10e8 calls do_write_codec_reg with a0=0x8, a1=0x0, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x1108 calls cmn_err with a0=0x1, a1=sym(.rodata)+640, a2=?, a3=?.
  The `jal` at 0x111c calls cmn_err with a0=0x4, a1=sym(.rodata)+592, a2=?, a3=?.
  The `beq` branch at 0xf50 targets 0xf98, is taken when (v0(=ret(do_read_codec_reg)) & 0x8000) == 0, and falls through when (v0(=ret(do_read_codec_reg)) & 0x8000) != 0.
  The `beq` branch at 0xf70 targets 0xf98, is taken when (v0(=ret(do_read_codec_reg)) & 0x8000) == 0, and falls through when (v0(=ret(do_read_codec_reg)) & 0x8000) != 0.
  The `bne` branch at 0xf90 targets 0x1118, is taken when (v0(=ret(do_read_codec_reg)) & 0x8000) != 0, and falls through when (v0(=ret(do_read_codec_reg)) & 0x8000) == 0.
  The `beq` branch at 0x1004 targets 0x102c, is taken when (v0(=ret(do_read_codec_reg)) & 0x4000) == 0, and falls through when (v0(=ret(do_read_codec_reg)) & 0x4000) != 0.
  The `bne` branch at 0x1024 targets 0x1104, is taken when (v0(=ret(do_read_codec_reg)) & 0x4000) != 0, and falls through when (v0(=ret(do_read_codec_reg)) & 0x4000) == 0.
  The `beq` branch at 0x1050 targets 0x1078, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x1060 targets 0x1078, is taken when v0(=ret(atoi)) == 0, and falls through when v0(=ret(atoi)) != 0.
  The `beq` branch at 0x1110 targets 0x10f4 and is always taken.
  The `beq` branch at 0x1124 targets 0x10f4 and is always taken.
  The return at 0x10fc has v0 = one of 0x0, 0x1.

- `a3_get_dma_rb_addr` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x112c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x112c-0x1220 (244 bytes).
  It occupies 244 bytes.
  The `jal` at 0x1138 calls get_cpu_irr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1150 calls get_isa_dma_buf_addr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x117c calls get_isa_dma_buf_addr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11d4 calls page_mapin_pfn with a0=0x0, a1=0x0, a2=-0x1, a3=?.
  The `jal` at 0x11f0 calls page_mapin_pfn with a0=0x0, a1=0x0, a2=-0x1, a3=?.
  The `jal` at 0x1210 calls page_mapin_pfn with a0=0x0, a1=0x0, a2=-0x1, a3=?.
  The `beq` branch at 0x1148 targets 0x117c, is taken when at(?) >= 0x23 (signed), and falls through when at(?) < 0x23 (signed).
  The `beq` branch at 0x1158 targets 0x11e4, is taken when s0(=a0) == 0, and falls through when s0(=a0) != 0.
  The `beq` branch at 0x1164 targets 0x1200, is taken when s0(=a0) == v1(=0x1), and falls through when s0(=a0) != v1(=0x1).
  The `beq` branch at 0x116c targets 0x11c8, is taken when s0(=a0) == a0(=0x2), and falls through when s0(=a0) != a0(=0x2).
  The `beq` branch at 0x1174 targets 0x11ac and is always taken.
  The `beq` branch at 0x118c targets 0x11ac, is taken when s0(=a0) == 0, and falls through when s0(=a0) != 0.
  The `beq` branch at 0x1198 targets 0x11c0, is taken when s0(=a0) == a1(=0x1), and falls through when s0(=a0) != a1(=0x1).
  The `beq` branch at 0x11a0 targets 0x11ac, is taken when s0(=a0) == a3(=0x2), and falls through when s0(=a0) != a3(=0x2).
  The `beq` branch at 0x11c0 targets 0x11ac and is always taken.
  The `beq` branch at 0x11dc targets 0x11ac and is always taken.
  The `beq` branch at 0x11f8 targets 0x11ac and is always taken.
  The `beq` branch at 0x1218 targets 0x11ac and is always taken.
  The return at 0x11b8 has v0 = one of 0x0, (ret(get_isa_dma_buf_addr) | 0xffffffff80000000), ((ret(get_isa_dma_buf_addr) | 0xffffffff80000000) | 0x2000), ((ret(get_isa_dma_buf_addr) | 0xffffffff80000000) | 0x1000), ret(page_mapin_pfn).

- `a3_write_input_source` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1220 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1220-0x129c (124 bytes).
  It occupies 124 bytes.
  The `lhu` at 0x1224 loads 2 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x1254 loads 4 bytes from a0 (arg0 at entry) +0x740.
  The `lw` at 0x1264 loads 4 bytes from [a0+1856] +0x9c.
  The `jal` at 0x124c calls write_codec_reg with a0=0x2, a1=?, a2=a0 at entry (arg0), a3=-0xe0e1.
  The `jal` at 0x1260 calls kdsp_is_subtype with a0=0x2000000d, a1=[[a0+1856]+156], a2=?, a3=?.
  The `jal` at 0x1278 calls connlist_reconfig with a0=a0+1384, a1=-0x1, a2=0x303, a3=one of 0x0, 0x4.
  The `beq` branch at 0x1268 targets 0x1290, is taken when v0(=ret(kdsp_is_subtype)) == 0, and falls through when v0(=ret(kdsp_is_subtype)) != 0.
  The `beq` branch at 0x1294 targets 0x1270 and is always taken.
  The return at 0x1288 has v0 = ret(connlist_reconfig).

- `a3_write_input_gain` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x129c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x129c-0x1320 (132 bytes).
  It occupies 132 bytes.
  The `lw` at 0x129c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x12a0 loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lhu` at 0x12ac loads 2 bytes from a0 (arg0 at entry) +0x198.
  The `jal` at 0x12e4 calls write_codec_reg with a0=0x2, a1=?, a2=a0 at entry (arg0), a3=a3 at entry (arg3), a7=0x3f.
  The `beq` branch at 0x12b8 targets 0x12f8, is taken when at(=[a1]) == a7(=0x3f), and falls through when at(=[a1]) != a7(=0x3f).
  The `beq` branch at 0x12d0 targets 0x130c, is taken when a5(=[a1+4]) == a7(=0x3f), and falls through when a5(=[a1+4]) != a7(=0x3f).
  The `beq` branch at 0x1304 targets 0x12cc and is always taken.
  The `beq` branch at 0x1318 targets 0x12e0 and is always taken.
  The return at 0x12f0 has v0 = ret(write_codec_reg).

- `a3_write_output_gain` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1320 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1320-0x136c (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0x1320 loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `lw` at 0x1330 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lhu` at 0x1338 loads 2 bytes from (a0 + (a1 + a1)) +0x194.
  The `jal` at 0x1358 calls write_codec_reg with a0=?, a1=?, a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0x1364 has v0 = ret(write_codec_reg).

- `a3_initial_val` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x136c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x136c-0x1440 (212 bytes).
  It occupies 212 bytes.
  The `lw` at 0x1370 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `lw` at 0x1380 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x13b0 loads 4 bytes from [a0+144] +0x2a0.
  The `lw` at 0x13cc loads 4 bytes from [a0+144] +0x1e8.
  The `lw` at 0x13d8 loads 4 bytes from [a0+144] +0xd40.
  The `lw` at 0x13fc loads 4 bytes from [a0+144] +0x1500.
  The `lw` at 0x1414 loads 4 bytes from [a0+144] +0x13a0.
  The `lw` at 0x1428 loads 4 bytes from [a0+144] +0x1660.
  The `lw` at 0x1434 loads 4 bytes from [a0+144] +0xc30.
  The `beq` branch at 0x1394 targets 0x13c0, is taken when a5(=[a1]) == at(=0x10000002), and falls through when a5(=[a1]) != at(=0x10000002).
  The `beq` branch at 0x139c targets 0x13f4, is taken when a5(=[a1]) == a6(=0x10000003), and falls through when a5(=[a1]) != a6(=0x10000003).
  The `bne` branch at 0x13a4 targets 0x13ec, is taken when a5(=[a1]) != a7(=0x10000011), and falls through when a5(=[a1]) == a7(=0x10000011).
  The `beq` branch at 0x13b8 targets 0x13ec and is always taken.
  The `bne` branch at 0x13c4 targets 0x13e4, is taken when a0 != t0(=[a0+144]+1384), and falls through when a0 == t0(=[a0+144]+1384).
  The `beq` branch at 0x13d0 targets 0x1434, is taken when a0(=[[a0+144]+488]) == 0, and falls through when a0(=[[a0+144]+488]) != 0.
  The `beq` branch at 0x13dc targets 0x13e8 and is always taken.
  The `bne` branch at 0x13f4 targets 0x140c, is taken when a0 != t0(=[a0+144]+1384), and falls through when a0 == t0(=[a0+144]+1384).
  The `beq` branch at 0x1404 targets 0x13ec and is always taken.
  The `bne` branch at 0x140c targets 0x1420, is taken when a0 != t1(=[a0+144]+1912), and falls through when a0 == t1(=[a0+144]+1912).
  The `beq` branch at 0x1418 targets 0x1404 and is always taken.
  The `bne` branch at 0x1420 targets 0x1404, is taken when a0 != t2(=[a0+144]+2440), and falls through when a0 == t2(=[a0+144]+2440).
  The `beq` branch at 0x142c targets 0x1404 and is always taken.
  The `beq` branch at 0x1438 targets 0x13e8 and is always taken.
  The return at 0x13ec has v0 = one of 0x0, [[a0+144]+672], ?.

- `a3_set_device_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1440 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1440-0x1628 (488 bytes).
  It occupies 488 bytes.
  The `lw` at 0x1448 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x1450 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `sh` at 0x1494 stores 2 bytes to a1 (arg1 at entry) +0x14.
  2 such `lw` accesses load 4 bytes from [a0+464] +0x1e8, including `lw` at 0x14bc, `lw` at 0x1550.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1508, `sw` at 0x150c, `sw` at 0x1510.
  The `lw` at 0x1524 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `jal` at 0x1520 calls kdsp_find_resource_in_list with a0=[a1+8], a1=sp-96, a2=one of 0x4, 0x5, a3=?, a4=[a0+464]+4328, a5=[a0+464]+2968, a6=[a0+464]+3512.
  The `jal` at 0x1534 calls kdsp_select_interface with a0=a0 at entry (arg0), a1=ret(kdsp_find_resource_in_list), a2=?, a3=?.
  The `jal` at 0x1560 calls a3_write_input_source with a0=[a0+464], a1=0x0, a2=?, a3=?, a4=[a0+464]+3240, a5=[[a0+464]+488].
  The `jal` at 0x156c calls a3_write_input_gain with a0=[a0+464], a1=[a0+464]+356, a2=?, a3=?.
  The `jal` at 0x15b0 calls a3_write_input_source with a0=[a0+464], a1=0xe0e0, a2=?, a3=?, a4=[a0+464]+3240.
  The `jal` at 0x15bc calls a3_write_input_gain with a0=[a0+464], a1=[a0+464]+340, a2=?, a3=?.
  The `jal` at 0x15d4 calls a3_write_input_source with a0=[a0+464], a1=0x4040, a2=?, a3=?, a4=[a0+464]+3240.
  The `jal` at 0x15e0 calls a3_write_input_gain with a0=[a0+464], a1=[a0+464]+340, a2=?, a3=?.
  The `jal` at 0x15f0 calls a3_write_input_source with a0=[a0+464], a1=0x2020, a2=?, a3=?, a4=[a0+464]+3240.
  The `jal` at 0x15fc calls a3_write_input_gain with a0=[a0+464], a1=[a0+464]+348, a2=?, a3=?.
  The `jal` at 0x160c calls a3_write_input_source with a0=[a0+464], a1=0xc0c0, a2=?, a3=?, a4=[a0+464]+3240.
  The `jal` at 0x1618 calls a3_write_input_gain with a0=[a0+464], a1=[a0+464]+340, a2=?, a3=?.
  The `beq` branch at 0x145c targets 0x1498, is taken when a4(=[a1]) == at(=0x10000005), and falls through when a4(=[a1]) != at(=0x10000005).
  The `beq` branch at 0x1468 targets 0x14b0, is taken when a4(=[a1]) == v1(=0x10000002), and falls through when a4(=[a1]) != v1(=0x10000002).
  The `beq` branch at 0x1474 targets 0x1584, is taken when a4(=[a1]) == a0(=0x10000004), and falls through when a4(=[a1]) != a0(=0x10000004).
  The `beq` branch at 0x147c targets 0x157c, is taken when a4(=[a1]) == a1(=0x10000003), and falls through when a4(=[a1]) != a1(=0x10000003).
  The `beq` branch at 0x1484 targets 0x14a0 and is always taken.
  The `bne` branch at 0x14b4 targets 0x149c, is taken when a0 != a4(=[a0+464]+1384), and falls through when a0 == a4(=[a0+464]+1384).
  The `beq` branch at 0x14c8 targets 0x15cc, is taken when a5(=[[a0+464]+488]) == 0, and falls through when a5(=[[a0+464]+488]) != 0.
  The `beq` branch at 0x1528 targets 0x148c, is taken when v0(=ret(kdsp_find_resource_in_list)) == 0, and falls through when v0(=ret(kdsp_find_resource_in_list)) != 0.
  The `bne` branch at 0x1548 targets 0x158c, is taken when s1(=ret(kdsp_find_resource_in_list)) != a4(=[a0+464]+3240), and falls through when s1(=ret(kdsp_find_resource_in_list)) == a4(=[a0+464]+3240).
  The `beq` branch at 0x1554 targets 0x1590, is taken when a5(=[[a0+464]+488]) == 0, and falls through when a5(=[[a0+464]+488]) != 0.
  The `beq` branch at 0x1574 targets 0x149c and is always taken.
  The `beq` branch at 0x157c targets 0x149c and is always taken.
  The `beq` branch at 0x1584 targets 0x149c and is always taken.
  The `beq` branch at 0x1590 targets 0x15d4, is taken when s1(=ret(kdsp_find_resource_in_list)) == a6(?), and falls through when s1(=ret(kdsp_find_resource_in_list)) != a6(?).
  The `beq` branch at 0x1598 targets 0x15f0, is taken when s1(=ret(kdsp_find_resource_in_list)) == a7(?), and falls through when s1(=ret(kdsp_find_resource_in_list)) != a7(?).
  The `beq` branch at 0x15a0 targets 0x160c, is taken when s1(=ret(kdsp_find_resource_in_list)) == t0(?), and falls through when s1(=ret(kdsp_find_resource_in_list)) != t0(?).
  The `bne` branch at 0x15a8 targets 0x1498, is taken when s1(=ret(kdsp_find_resource_in_list)) != t1(?), and falls through when s1(=ret(kdsp_find_resource_in_list)) == t1(?).
  The `beq` branch at 0x15c4 targets 0x149c and is always taken.
  The `beq` branch at 0x15cc targets 0x14e0 and is always taken.
  The `beq` branch at 0x15e8 targets 0x149c and is always taken.
  The `beq` branch at 0x1604 targets 0x149c and is always taken.
  The `beq` branch at 0x1620 targets 0x149c and is always taken.
  The return at 0x14a8 has v0 = one of 0x0, 0x1.

- `a3_cg_update_hrb` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1628 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1628-0x1630 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1628 has v0 = ?.

- `a3_set_analog_in_if_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1630 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1630-0x1870 (576 bytes).
  It occupies 576 bytes.
  The `lw` at 0x163c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x1648 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x1664 loads 4 bytes from [a0+264] +0x1d0.
  3 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x14, including `lh` at 0x16e4, `lh` at 0x170c, `lh` at 0x1774.
  The `sw` at 0x1708 stores 4 bytes to ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x172c, `ld` at 0x17b8.
  The `lw` at 0x1740 loads 4 bytes from ?.
  The `lhu` at 0x1780 loads 2 bytes from [[a0+264]+464] +0x198.
  The `lw` at 0x17bc loads 4 bytes from [[a0+264]+464] +0x740.
  The `lw` at 0x17f8 loads 4 bytes from [[a0+264]+464] +0x1e8.
  2 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x14, including `sh` at 0x1838, `sh` at 0x1864.
  The `jal` at 0x1694 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-112, a2=0x2, a3=0x8, a4=a2 at entry (arg2).
  The `jal` at 0x16b8 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=0x1, a3=?.
  The `jal` at 0x175c calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x179c calls write_codec_reg with a0=0x2, a1=?, a2=[[a0+264]+464], a3=?, a4=-0x1.
  The `jal` at 0x1848 calls a3_write_input_gain with a0=[[a0+264]+464], a1=([[a0+264]+464] + one of 0x154, 0x15c, 0x164, 0x16c), a2=[[[a0+264]+464]+1856], a3=?.
  The `beq` branch at 0x1660 targets 0x1688, is taken when at(=[a1]) == v0(=0x10000019), and falls through when at(=[a1]) != v0(=0x10000019).
  The `bne` branch at 0x16a0 targets 0x16b0, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x16a8 targets 0x1670 and is always taken.
  The `beq` branch at 0x16c8 targets 0x1834, is taken when v0(=ret(kdsp_find_param_info)) == 0, and falls through when v0(=ret(kdsp_find_param_info)) != 0.
  The `bne` branch at 0x16dc targets 0x17dc, is taken when s1(=a0) != a2(=[[a0+264]+464]+3512), and falls through when s1(=a0) == a2(=[[a0+264]+464]+3512).
  The `blez` branch at 0x16f0 targets 0x17bc, is taken when a2(=[a1+20]:2) <= 0 (signed), and falls through when a2(=[a1+20]:2) > 0 (signed).
  The `beq` branch at 0x1700 targets 0x172c and is always taken.
  The `beq` branch at 0x1724 targets 0x17bc, is taken when a3(?) >= a2(=[a1+20]:2) (signed), and falls through when a3(?) < a2(=[a1+20]:2) (signed).
  The `beq` branch at 0x1738 targets 0x1710, is taken when a4(=-0x1) == a0(?), and falls through when a4(=-0x1) != a0(?).
  The `beq` branch at 0x1748 targets 0x1778, is taken when v1(?) == a2(=0x3f), and falls through when v1(?) != a2(=0x3f).
  The `beq` branch at 0x1750 targets 0x170c, is taken when a0(?) == a1(=0x8000000000000000), and falls through when a0(?) != a1(=0x8000000000000000).
  The `bgez` branch at 0x1768 targets 0x1708, is taken when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed).
  The `beq` branch at 0x1770 targets 0x1710 and is always taken.
  The `beq` branch at 0x1778 targets 0x170c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x17ac targets 0x170c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x17b4 targets 0x1750 and is always taken.
  The `beq` branch at 0x17c8 targets 0x1844, is taken when a2(=[[[a0+264]+464]+1856]) == s1(=a0), and falls through when a2(=[[[a0+264]+464]+1856]) != s1(=a0).
  The `beq` branch at 0x17d4 targets 0x166c and is always taken.
  The `bne` branch at 0x17dc targets 0x17f0, is taken when s1(=a0) != a3(=[[a0+264]+464]+2968), and falls through when s1(=a0) == a3(=[[a0+264]+464]+2968).
  The `beq` branch at 0x17e8 targets 0x16e4 and is always taken.
  The `bne` branch at 0x17f0 targets 0x1814, is taken when s1(=a0) != a4(=[[a0+264]+464]+3240), and falls through when s1(=a0) == a4(=[[a0+264]+464]+3240).
  The `beq` branch at 0x17fc targets 0x1814, is taken when a5(=[[[a0+264]+464]+488]) == 0, and falls through when a5(=[[[a0+264]+464]+488]) != 0.
  The `beq` branch at 0x1808 targets 0x16e4 and is always taken.
  The `bne` branch at 0x1814 targets 0x1824, is taken when s1(=a0) != a6(=[[a0+264]+464]+4328), and falls through when s1(=a0) == a6(=[[a0+264]+464]+4328).
  The `beq` branch at 0x181c targets 0x182c and is always taken.
  The `bne` branch at 0x1824 targets 0x1858, is taken when s1(=a0) != a7(=[[a0+264]+464]+4600), and falls through when s1(=a0) == a7(=[[a0+264]+464]+4600).
  The `beq` branch at 0x182c targets 0x16e4 and is always taken.
  The `beq` branch at 0x183c targets 0x166c and is always taken.
  The `beq` branch at 0x1850 targets 0x17d4 and is always taken.
  The `beq` branch at 0x1868 targets 0x166c and is always taken.
  The return at 0x1680 has v0 = one of 0x0, 0x1.
  The instructions from 0x1810 to 0x1810 are not reached by any path from the entry, and their branches are not listed.

- `a3_get_analog_in_if_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1870 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1870-0x1a28 (440 bytes).
  It occupies 440 bytes.
  The `lw` at 0x1898 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x18a4 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x18c0 loads 4 bytes from [a0+264] +0x1d0.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x193c, `sd` at 0x1960.
  The `lw` at 0x1940 loads 4 bytes from ?.
  2 such `lw` accesses load 4 bytes from [[a0+264]+464] +0x1e8, including `lw` at 0x19c8, `lw` at 0x19e4.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x19d8, `sw` at 0x19fc, `sw` at 0x1a1c.
  The `jal` at 0x1920 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x1974 calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-96, a2=0x2, a3=0x8, a4=a2 at entry (arg2).
  The `beq` branch at 0x18bc targets 0x18f0, is taken when v0(=[a1]) == at(=0x10000019), and falls through when v0(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x18d8 targets 0x19b8, is taken when v0(=[a1]) == t2(=0x10000004), and falls through when v0(=[a1]) != t2(=0x10000004).
  The `beq` branch at 0x18e0 targets 0x19f8, is taken when v0(=[a1]) == a0(=0x1000001c), and falls through when v0(=[a1]) != a0(=0x1000001c).
  The `beq` branch at 0x18e8 targets 0x1988 and is always taken.
  The `bne` branch at 0x190c targets 0x19a8, is taken when s3(=a0) != t3(=[[a0+264]+464]+3512), and falls through when s3(=a0) == t3(=[[a0+264]+464]+3512).
  The `beq` branch at 0x1918 targets 0x1940 and is always taken.
  The `beq` branch at 0x1938 targets 0x1964, is taken when s2(?) >= 0x2 (signed), and falls through when s2(?) < 0x2 (signed).
  The `bne` branch at 0x1944 targets 0x1920, is taken when a0(?) != s5(=0x3f), and falls through when a0(?) == s5(=0x3f).
  The `bne` branch at 0x195c targets 0x1940, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `bne` branch at 0x19a8 targets 0x19dc, is taken when s3(=a0) != a0(=[[a0+264]+464]+2968), and falls through when s3(=a0) == a0(=[[a0+264]+464]+2968).
  The `beq` branch at 0x19b0 targets 0x1918 and is always taken.
  The `beq` branch at 0x19b8 targets 0x19d4, is taken when s3(=a0) == a1(=[[a0+264]+464]+2968), and falls through when s3(=a0) != a1(=[[a0+264]+464]+2968).
  The `bne` branch at 0x19c0 targets 0x1a18, is taken when s3(=a0) != a2(=[[a0+264]+464]+3240), and falls through when s3(=a0) == a2(=[[a0+264]+464]+3240).
  The `beq` branch at 0x19cc targets 0x1a18, is taken when at(=[[[a0+264]+464]+488]) == 0, and falls through when at(=[[[a0+264]+464]+488]) != 0.
  The `beq` branch at 0x19d4 targets 0x1984 and is always taken.
  The `bne` branch at 0x19dc targets 0x1a00, is taken when s3(=a0) != a1(=[[a0+264]+464]+3240), and falls through when s3(=a0) == a1(=[[a0+264]+464]+3240).
  The `beq` branch at 0x19e8 targets 0x1a00, is taken when v1(=[[[a0+264]+464]+488]) == 0, and falls through when v1(=[[[a0+264]+464]+488]) != 0.
  The `beq` branch at 0x19f0 targets 0x1918 and is always taken.
  The `beq` branch at 0x19f8 targets 0x1984 and is always taken.
  The `beq` branch at 0x1a00 targets 0x1a10, is taken when s3(=a0) == a7(=[[a0+264]+464]+4328), and falls through when s3(=a0) != a7(=[[a0+264]+464]+4328).
  The `bne` branch at 0x1a08 targets 0x1a20, is taken when s3(=a0) != t0(=[[a0+264]+464]+4600), and falls through when s3(=a0) == t0(=[[a0+264]+464]+4600).
  The `beq` branch at 0x1a10 targets 0x1918 and is always taken.
  The `beq` branch at 0x1a18 targets 0x1984 and is always taken.
  The `beq` branch at 0x1a20 targets 0x1988 and is always taken.
  The return at 0x19a0 has v0 = one of -0x2, 0x0, 0x1.

- `a3_set_analog_out_if_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1a28 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1a28-0x1c48 (544 bytes).
  It occupies 544 bytes.
  The `lw` at 0x1a34 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x1a40 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x1a5c loads 4 bytes from [a0+264] +0x1d0.
  The `lw` at 0x1a78 loads 4 bytes from a1 (arg1 at entry) +0x8.
  2 such `lhu` accesses load 2 bytes from [[a0+264]+464] +0x1a4, including `lhu` at 0x1a84, `lhu` at 0x1b34.
  2 such `sw` accesses store 4 bytes to [[a0+264]+464] +0x184, including `sw` at 0x1a88, `sw` at 0x1b3c.
  2 such `lhu` accesses load 2 bytes from [[a0+264]+464] +0x1a8, including `lhu` at 0x1ab0, `lhu` at 0x1af4.
  2 such `sw` accesses store 4 bytes to [[a0+264]+464] +0x188, including `sw` at 0x1ab4, `sw` at 0x1b00.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1bd0, `sw` at 0x1c08.
  The `ld` at 0x1be8 loads 8 bytes from ?.
  The `sh` at 0x1c3c stores 2 bytes to a1 (arg1 at entry) +0x14.
  The `jal` at 0x1a98 calls write_codec_reg with a0=0x8, a1=?, a2=[[a0+264]+464], a3=a3 at entry (arg3), a4=a2 at entry (arg2), a6=[a1].
  The `jal` at 0x1ac4 calls write_codec_reg with a0=0xa, a1=?, a2=[[a0+264]+464], a3=a3 at entry (arg3), a4=a2 at entry (arg2), a6=[a1].
  The `jal` at 0x1b18 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-96, a2=0x2, a3=0x8, a4=a2 at entry (arg2), a6=[a1].
  The `jal` at 0x1b50 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=0x1, a3=?.
  The `jal` at 0x1ba8 calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x1, a3=?, a6=0x8000000000000000, a7=-0x1.
  The `jal` at 0x1c20 calls a3_write_output_gain with a0=[[a0+264]+464], a1=?, a2=?, a3=?, a6=0x8000000000000000, a7=-0x1.
  The `beq` branch at 0x1a58 targets 0x1b0c, is taken when a6(=[a1]) == at(=0x10000019), and falls through when a6(=[a1]) != at(=0x10000019).
  The `bne` branch at 0x1a6c targets 0x1aec, is taken when a6(=[a1]) != t8(=0x1000001d), and falls through when a6(=[a1]) == t8(=0x1000001d).
  The `bne` branch at 0x1a74 targets 0x1aa8, is taken when s1(=a0) != a0(=[[a0+264]+464]+3784), and falls through when s1(=a0) == a0(=[[a0+264]+464]+3784).
  The `beq` branch at 0x1a7c targets 0x1b34, is taken when v0(=[a1+8]) == 0, and falls through when v0(=[a1+8]) != 0.
  The `beq` branch at 0x1aa0 targets 0x1ad0 and is always taken.
  The `beq` branch at 0x1aa8 targets 0x1af4, is taken when v0(=[a1+8]) == 0, and falls through when v0(=[a1+8]) != 0.
  The `beq` branch at 0x1aec targets 0x1ad4 and is always taken.
  The `beq` branch at 0x1b04 targets 0x1abc and is always taken.
  The `bne` branch at 0x1b24 targets 0x1b48, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x1b2c targets 0x1ad4 and is always taken.
  The `beq` branch at 0x1b40 targets 0x1a90 and is always taken.
  The `beq` branch at 0x1b58 targets 0x1c38, is taken when v0(=ret(kdsp_find_param_info)) == 0, and falls through when v0(=ret(kdsp_find_param_info)) != 0.
  The `bne` branch at 0x1b60 targets 0x1b78, is taken when s1(=a0) != a2(=[[a0+264]+464]+3784), and falls through when s1(=a0) == a2(=[[a0+264]+464]+3784).
  The `beq` branch at 0x1b70 targets 0x1b88 and is always taken.
  The `bne` branch at 0x1b78 targets 0x1c30, is taken when s1(=a0) != a3(=[[a0+264]+464]+4056), and falls through when s1(=a0) == a3(=[[a0+264]+464]+4056).
  The `beq` branch at 0x1b9c targets 0x1be8 and is always taken.
  The `bltz` branch at 0x1bc8 targets 0x1bd4, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x1be0 targets 0x1c20, is taken when a0(?) >= 0x2 (signed), and falls through when a0(?) < 0x2 (signed).
  The `beq` branch at 0x1bec targets 0x1c0c, is taken when a7(=-0x1) == a0(?), and falls through when a7(=-0x1) != a0(?).
  The `bne` branch at 0x1bfc targets 0x1ba4, is taken when a0(?) != a6(=0x8000000000000000), and falls through when a0(?) == a6(=0x8000000000000000).
  The `bne` branch at 0x1c18 targets 0x1be8, is taken when a4(?) < 0x2 (signed), and falls through when a4(?) >= 0x2 (signed).
  The `beq` branch at 0x1c28 targets 0x1acc and is always taken.
  The `beq` branch at 0x1c30 targets 0x1ad0 and is always taken.
  The `beq` branch at 0x1c40 targets 0x1ad0 and is always taken.
  The return at 0x1ae4 has v0 = one of -0x2, 0x0, 0x1.

- `a3_get_analog_out_if_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1c48 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1c48-0x1d9c (340 bytes).
  It occupies 340 bytes.
  The `lw` at 0x1c58 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x1c6c loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x1c88 loads 4 bytes from [a0+264] +0x1d0.
  The `lw` at 0x1cac loads 4 bytes from [[a0+264]+464] +0x184.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x1cb4, `sw` at 0x1cb8, `sw` at 0x1cdc.
  The `lw` at 0x1cd4 loads 4 bytes from [[a0+264]+464] +0x188.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1d0c, `lw` at 0x1d44.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1d34, `sd` at 0x1d6c.
  The `jal` at 0x1cec calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1000001d, a7=0x1000001c.
  The `jal` at 0x1d18 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x1, a3=?.
  The `jal` at 0x1d80 calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-96, a2=0x2, a3=0x8, a4=a2 at entry (arg2).
  The `beq` branch at 0x1c84 targets 0x1ce0, is taken when v0(=[a1]) == t1(=0x10000019), and falls through when v0(=[a1]) != t1(=0x10000019).
  The `beq` branch at 0x1c8c targets 0x1ca4, is taken when v0(=[a1]) == a6(=0x1000001d), and falls through when v0(=[a1]) != a6(=0x1000001d).
  The `beq` branch at 0x1c94 targets 0x1cb8, is taken when v0(=[a1]) == a7(=0x1000001c), and falls through when v0(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x1c9c targets 0x1cc0 and is always taken.
  The `bne` branch at 0x1ca4 targets 0x1cd4, is taken when s2(=a0) != a0(=[[a0+264]+464]+3784), and falls through when s2(=a0) == a0(=[[a0+264]+464]+3784).
  The `beq` branch at 0x1cb0 targets 0x1cbc and is always taken.
  The `beq` branch at 0x1cd8 targets 0x1cbc and is always taken.
  The `beq` branch at 0x1d04 targets 0x1d38 and is always taken.
  The `beq` branch at 0x1d10 targets 0x1d50, is taken when a0(?) == s0(=0x3f), and falls through when a0(?) != s0(=0x3f).
  The `beq` branch at 0x1d30 targets 0x1d70, is taken when s5(?) >= 0x2 (signed), and falls through when s5(?) < 0x2 (signed).
  The `beq` branch at 0x1d3c targets 0x1d0c, is taken when v0(?) == s2(=a0), and falls through when v0(?) != s2(=a0).
  The `bne` branch at 0x1d48 targets 0x1d18, is taken when a0(?) != s0(=0x3f), and falls through when a0(?) == s0(=0x3f).
  The `bne` branch at 0x1d68 targets 0x1d38, is taken when s5(?) < 0x2 (signed), and falls through when s5(?) >= 0x2 (signed).
  The `beq` branch at 0x1d94 targets 0x1cbc and is always taken.
  The return at 0x1ccc has v0 = one of 0x0, 0x1.

- `a3_set_clockgen_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1d9c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1d9c-0x1f40 (420 bytes).
  It occupies 420 bytes.
  The `lw` at 0x1da4 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x1da8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  5 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x110, including `sd` at 0x1df8, `sd` at 0x1e28, `sd` at 0x1e88.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x1dfc, `lw` at 0x1e2c, `lw` at 0x1e94.
  The `sw` at 0x1e08 stores 4 bytes to a0 (arg0 at entry) +0x120.
  The `sw` at 0x1e3c stores 4 bytes to a0 (arg0 at entry) +0x128.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x8, including `ld` at 0x1e48, `ld` at 0x1f24.
  3 such `lw` accesses load 4 bytes from ret(kdsp_find_param_info) +0x20, including `lw` at 0x1e5c, `lw` at 0x1e7c, `lw` at 0x1f00.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+32] +0x0, including `ld` at 0x1e68, `ld` at 0x1e80.
  The `ld` at 0x1e74 loads 8 bytes from a0 (arg0 at entry) +0x110.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x118, including `sd` at 0x1e78, `sd` at 0x1efc, `sd` at 0x1f20.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x154, including `sw` at 0x1ea8, `sw` at 0x1ecc, `sw` at 0x1f30.
  2 such `lw` accesses load 4 bytes from [a0+336] +0x1e8, including `lw` at 0x1eac, `lw` at 0x1ec0.
  6 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x14, including `sh` at 0x1ed8, `sh` at 0x1ee0, `sh` at 0x1ee8.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+32] +0x8, including `ld` at 0x1eec, `ld` at 0x1f04.
  The `jal` at 0x1e40 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=[a1], a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x10000000.
  The `jal` at 0x1e90 calls kdsp_find_resource_in_list with a0=[a1+8], a1=a0+48, a2=0x3, a3=a3 at entry (arg3), a4=0x10000000.
  The `beq` branch at 0x1dc4 targets 0x1e40, is taken when v0(=[a1]) == at(=0x1000000d), and falls through when v0(=[a1]) != at(=0x1000000d).
  The `beq` branch at 0x1dd0 targets 0x1e8c, is taken when v0(=[a1]) == v1(=0x10000011), and falls through when v0(=[a1]) != v1(=0x10000011).
  The `beq` branch at 0x1ddc targets 0x1df8, is taken when v0(=[a1]) == a0(=0x1000000e), and falls through when v0(=[a1]) != a0(=0x1000000e).
  The `beq` branch at 0x1de8 targets 0x1e28, is taken when v0(=[a1]) == a1(=0x1000000f), and falls through when v0(=[a1]) != a1(=0x1000000f).
  The `beq` branch at 0x1df0 targets 0x1e10 and is always taken.
  The `blez` branch at 0x1e00 targets 0x1f10, is taken when v0(=[a1+8]) <= 0 (signed), and falls through when v0(=[a1+8]) > 0 (signed).
  The `blez` branch at 0x1e30 targets 0x1f18, is taken when v0(=[a1+8]) <= 0 (signed), and falls through when v0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x1e38 targets 0x1e0c and is always taken.
  The `blez` branch at 0x1e4c targets 0x1edc, is taken when a1(=[a1+8]:8) <= 0 (signed), and falls through when a1(=[a1+8]:8) > 0 (signed).
  The `beq` branch at 0x1e54 targets 0x1edc, is taken when v0(=ret(kdsp_find_param_info)) == 0, and falls through when v0(=ret(kdsp_find_param_info)) != 0.
  The `beq` branch at 0x1e60 targets 0x1edc, is taken when a4(=[ret(kdsp_find_param_info)+32]) == 0, and falls through when a4(=[ret(kdsp_find_param_info)+32]) != 0.
  The `beq` branch at 0x1e70 targets 0x1eec, is taken when a1(=[a1+8]:8) >= a2(=[[ret(kdsp_find_param_info)+32]]:8) (signed), and falls through when a1(=[a1+8]:8) < a2(=[[ret(kdsp_find_param_info)+32]]:8) (signed).
  The `beq` branch at 0x1e84 targets 0x1e0c and is always taken.
  The `beq` branch at 0x1e9c targets 0x1ee4, is taken when v0(=ret(kdsp_find_resource_in_list)) == 0, and falls through when v0(=ret(kdsp_find_resource_in_list)) != 0.
  The `bne` branch at 0x1ea4 targets 0x1eb4, is taken when v0(=ret(kdsp_find_resource_in_list)) != a0(=[a0+336]+808), and falls through when v0(=ret(kdsp_find_resource_in_list)) == a0(=[a0+336]+808).
  The `beq` branch at 0x1eb0 targets 0x1f30, is taken when a4(=[[a0+336]+488]) == 0, and falls through when a4(=[[a0+336]+488]) != 0.
  The `bne` branch at 0x1eb8 targets 0x1e10, is taken when v0(=ret(kdsp_find_resource_in_list)) != a5(=[a0+336]+1096), and falls through when v0(=ret(kdsp_find_resource_in_list)) == a5(=[a0+336]+1096).
  The `bne` branch at 0x1ec4 targets 0x1e10, is taken when a6(=[[a0+336]+488]) != 0, and falls through when a6(=[[a0+336]+488]) == 0.
  The `beq` branch at 0x1ed4 targets 0x1e0c and is always taken.
  The `beq` branch at 0x1edc targets 0x1e0c and is always taken.
  The `beq` branch at 0x1ee4 targets 0x1e0c and is always taken.
  The `beq` branch at 0x1ef4 targets 0x1f20, is taken when t0(=[[ret(kdsp_find_param_info)+32]+8]:8) >= a1(=[a1+8]:8) (signed), and falls through when t0(=[[ret(kdsp_find_param_info)+32]+8]:8) < a1(=[a1+8]:8) (signed).
  The `beq` branch at 0x1f08 targets 0x1e0c and is always taken.
  The `beq` branch at 0x1f10 targets 0x1e0c and is always taken.
  The `beq` branch at 0x1f18 targets 0x1e0c and is always taken.
  The `beq` branch at 0x1f28 targets 0x1e0c and is always taken.
  The `beq` branch at 0x1f38 targets 0x1e0c and is always taken.
  The return at 0x1e20 has v0 = one of 0x0, 0x1.

- `a3_commit_device_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1f40 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1f40-0x1f48 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1f40 has v0 = ?.

- `a3_calculate_rate_frac` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x1f48 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x1f48-0x2050 (264 bytes).
  It occupies 264 bytes.
  The `lw` at 0x1f48 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x1f4c loads 4 bytes from a0 (arg0 at entry) +0x154.
  The `ld` at 0x1f50 loads 8 bytes from a0 (arg0 at entry) +0x110.
  2 such `ld` accesses load 8 bytes from [a0+340] +0x108, including `ld` at 0x1f70, `ld` at 0x1f88.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x110, including `sd` at 0x1f80, `sd` at 0x1fc8.
  The `ld` at 0x1fe4 loads 8 bytes from [a0+336] +0x310.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x120, including `sw` at 0x1ff0, `sw` at 0x2020.
  The `sw` at 0x1ffc stores 4 bytes to a0 (arg0 at entry) +0x154.
  The `sw` at 0x2004 stores 4 bytes to a0 (arg0 at entry) +0x128.
  The `lw` at 0x2008 loads 4 bytes from a0 (arg0 at entry) +0x128.
  The `lw` at 0x200c loads 4 bytes from a0 (arg0 at entry) +0x120.
  The `jal` at 0x1f98 calls kdsp_reduce_frac with a0=?, a1=[[a0+340]+264]:8, a2=a0+288, a3=a0+296, a4=0xffff.
  The `jal` at 0x1fe0 calls kdsp_reduce_frac with a0=?, a1=[[a0+336]+784]:8, a2=sp-32, a3=sp-28, a4=0xffff.
  The `jal` at 0x2040 calls kdsp_reduce_frac with a0=?, a1=[a0+296], a2=a0+288, a3=a0+296, a4=0xffff.
  The `beq` branch at 0x1f60 targets 0x1fb0, is taken when a3(=[a0+340]) == 0, and falls through when a3(=[a0+340]) != 0.
  The `beq` branch at 0x1f68 targets 0x2008, is taken when a6(=[a0+272]:8) == 0, and falls through when a6(=[a0+272]:8) != 0.
  The `beq` branch at 0x1f78 targets 0x1f8c, is taken when a0(=[[a0+340]+264]:8) >= a6(=[a0+272]:8) (signed), and falls through when a0(=[[a0+340]+264]:8) < a6(=[a0+272]:8) (signed).
  The `beq` branch at 0x1fbc targets 0x1fcc, is taken when a0(=0xbb8000000000) >= a6(=[a0+272]:8) (signed), and falls through when a0(=0xbb8000000000) < a6(=[a0+272]:8) (signed).
  The `beq` branch at 0x2000 targets 0x1fa0 and is always taken.
  The `beq` branch at 0x2014 targets 0x2024, is taken when a1(=[a0+296]) >= a0(=[a0+288]) (signed), and falls through when a1(=[a0+296]) < a0(=[a0+288]) (signed).
  The `bne` branch at 0x2028 targets 0x2038, is taken when a4(=0xffff) < a0(?) (signed), and falls through when a4(=0xffff) >= a0(?) (signed).
  The `beq` branch at 0x2030 targets 0x1fa4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x2048 targets 0x1fa4 and is always taken.
  The return at 0x1fa8 has v0 = one of ret(kdsp_reduce_frac), ?.

- `a3_commit_clockgen_params` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2050 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2050-0x20c0 (112 bytes).
  It occupies 112 bytes.
  The `lw` at 0x2064 loads 4 bytes from a0 (arg0 at entry) +0x154.
  The `lw` at 0x2070 loads 4 bytes from a0 (arg0 at entry) +0x134.
  The `lw` at 0x20a8 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `jal` at 0x205c calls a3_calculate_rate_frac with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x207c calls kdsp_select_mclk with a0=a0 at entry (arg0), a1=[a0+340], a2=?, a3=?.
  The `jal` at 0x2088 calls a3_set_clockgen with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2090 calls kdsp_update_cg_users with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x20b0 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x2068 targets 0x20a8, is taken when a1(=[a0+340]) == 0, and falls through when a1(=[a0+340]) != 0.
  The `beq` branch at 0x2074 targets 0x20a8, is taken when at(=[a0+308]) == a1(=[a0+340]), and falls through when at(=[a0+308]) != a1(=[a0+340]).
  The `beq` branch at 0x20b8 targets 0x2084 and is always taken.
  The return at 0x20a0 has v0 = ret(kdsp_update_cg_users).

- `a3_do_volume` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x20c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x20c0-0x2528 (1128 bytes).
  It occupies 1128 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1f0, including `lw` at 0x2144, `lw` at 0x2290, `lw` at 0x2378.
  The `lw` at 0x2164 loads 4 bytes from a0 (arg0 at entry) +0x1f4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1f0, including `sw` at 0x2170, `sw` at 0x2190.
  9 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x200, including `sw` at 0x218c, `sw` at 0x21f8, `sw` at 0x2224.
  6 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1ec, including `sw` at 0x2194, `sw` at 0x2390, `sw` at 0x23b0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1ec, including `lw` at 0x21dc, `lw` at 0x2294.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x200, including `lw` at 0x21ec, `lw` at 0x22b4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1fc, including `lw` at 0x21fc, `lw` at 0x22c4.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2238, `lw` at 0x22fc, `lw` at 0x2414.
  4 such `ld` accesses load 8 bytes from sym(.bss) +0xb0, including `ld` at 0x223c, `ld` at 0x2304, `ld` at 0x2418.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2270, `sd` at 0x2324, `sd` at 0x244c.
  2 such `ld` accesses load 8 bytes from sym(.bss) +0xa0, including `ld` at 0x2308, `ld` at 0x24b4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1f8, including `lw` at 0x237c, `lw` at 0x239c.
  The `jal` at 0x20d4 calls pciio_pio_read64 with a0=0xffffffffbf300000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20e4 calls pciio_pio_write64 with a0=0x0, a1=0xffffffffbf300000, a2=?, a3=?.
  The `jal` at 0x2168 calls itimeout with a0=sym(a3_do_volume), a1=a0 at entry (arg0), a2=[a0+500], a3=[sym(pltimeout)], a4=0x0, a5=0x0, a6=0x0.
  The `jal` at 0x2198 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x21ac calls pciio_pio_read64 with a0=0xffffffffbf310018, a1=?, a2=?, a3=?.
  The `jal` at 0x21c4 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf310018, a2=?, a3=?.
  The `jal` at 0x21cc calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x2234 calls kdsp_regval_to_db_gain with a0=?, a1=a0+3784, a2=0x1, a3=?.
  The `jal` at 0x2284 calls kdsp_pv_list_op with a0=a0+3784, a1=sp-208, a2=0x2, a3=0x18, a4=0x0.
  The `jal` at 0x22f8 calls kdsp_regval_to_db_gain with a0=?, a1=a0+3784, a2=0x1, a3=?.
  The `jal` at 0x236c calls kdsp_pv_list_op with a0=a0+3784, a1=sp-208, a2=0x2, a3=0x18, a4=0x0.
  The `jal` at 0x23d0 calls kdsp_pv_list_op with a0=a0+3784, a1=sp-184, a2=0x1, a3=0x18, a4=0x0, a5=0x800000.
  The `jal` at 0x2410 calls kdsp_regval_to_db_gain with a0=?, a1=a0+3784, a2=0x1, a3=?.
  The `jal` at 0x2460 calls kdsp_pv_list_op with a0=a0+3784, a1=sp-208, a2=0x2, a3=0x18, a4=0x0.
  The `jal` at 0x24a4 calls kdsp_regval_to_db_gain with a0=?, a1=a0+3784, a2=0x1, a3=?.
  The `jal` at 0x2518 calls kdsp_pv_list_op with a0=a0+3784, a1=sp-208, a2=0x2, a3=0x18, a4=0x0.
  The `beq` branch at 0x2120 targets 0x218c, is taken when (v0(=0x1800000) & a0(=(ret(pciio_pio_read64) << 0x0))) == 0, and falls through when (v0(=0x1800000) & a0(=(ret(pciio_pio_read64) << 0x0))) != 0.
  The `beq` branch at 0x212c targets 0x21dc, is taken when a4(=0x1000000) == a0(?), and falls through when a4(=0x1000000) != a0(?).
  The `beq` branch at 0x2134 targets 0x2294, is taken when a5(=0x800000) == a0(?), and falls through when a5(=0x800000) != a0(?).
  The `beq` branch at 0x213c targets 0x23bc, is taken when v0(=0x1800000) == a0(?), and falls through when v0(=0x1800000) != a0(?).
  The `beq` branch at 0x2148 targets 0x2198, is taken when v0(=[a0+496]) == 0, and falls through when v0(=[a0+496]) != 0.
  The `beq` branch at 0x21d4 targets 0x2178 and is always taken.
  The `bgez` branch at 0x21e4 targets 0x23e0, is taken when a2(=([a0+492] << 0x27)) >= 0 (signed), and falls through when a2(=([a0+492] << 0x27)) < 0 (signed).
  The `beq` branch at 0x21f4 targets 0x237c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x2210 targets 0x237c, is taken when v0(=[a0+512]+1) < t8(=[a0+508]) (unsigned), and falls through when v0(=[a0+512]+1) >= t8(=[a0+508]) (unsigned).
  The `bne` branch at 0x226c targets 0x2228, is taken when a3(?) < 0x2 (signed), and falls through when a3(?) >= 0x2 (signed).
  The `beq` branch at 0x228c targets 0x2148 and is always taken.
  The `bgez` branch at 0x22ac targets 0x2470, is taken when a6(=([a0+492] << 0x28)) >= 0 (signed), and falls through when a6(=([a0+492] << 0x28)) < 0 (signed).
  The `beq` branch at 0x22bc targets 0x239c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x22d0 targets 0x239c, is taken when v0(=[a0+512]+1) < v1(=[a0+508]) (unsigned), and falls through when v0(=[a0+512]+1) >= v1(=[a0+508]) (unsigned).
  The `beq` branch at 0x2328 targets 0x2334, is taken when a2(?) >= a3(=[sym(.bss)+160]:8) (signed), and falls through when a2(?) < a3(=[sym(.bss)+160]:8) (signed).
  The `bne` branch at 0x2340 targets 0x22ec, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x234c targets 0x2358, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `beq` branch at 0x2374 targets 0x2148 and is always taken.
  The `bne` branch at 0x2388 targets 0x228c, is taken when v0(=[a0+512]+1) < a5(=[a0+504]) (unsigned), and falls through when v0(=[a0+512]+1) >= a5(=[a0+504]) (unsigned).
  The `beq` branch at 0x2394 targets 0x228c and is always taken.
  The `bne` branch at 0x23a8 targets 0x2374, is taken when v0(=[a0+512]+1) < a6(=[a0+504]) (unsigned), and falls through when v0(=[a0+512]+1) >= a6(=[a0+504]) (unsigned).
  The `beq` branch at 0x23b4 targets 0x2374 and is always taken.
  The `beq` branch at 0x23d8 targets 0x2148 and is always taken.
  The `bne` branch at 0x2448 targets 0x2404, is taken when a3(?) < 0x2 (signed), and falls through when a3(?) >= 0x2 (signed).
  The `beq` branch at 0x2468 targets 0x228c and is always taken.
  The `beq` branch at 0x24d4 targets 0x24e0, is taken when a2(?) >= a3(=[sym(.bss)+160]:8) (signed), and falls through when a2(?) < a3(=[sym(.bss)+160]:8) (signed).
  The `bne` branch at 0x24ec targets 0x2498, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x24f8 targets 0x2504, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `beq` branch at 0x2520 targets 0x2374 and is always taken.
  The return at 0x2184 has v0 = one of ret(itimeout), ret(splx).

- `a3_timewrap_watchdog` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2528 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2528-0x25c4 (156 bytes).
  It occupies 156 bytes.
  The `lbu` at 0x253c loads 1 byte from a0 (arg0 at entry) +0x718.
  The `lbu` at 0x2550 loads 1 byte from a0 (arg0 at entry) +0x928.
  The `lbu` at 0x2564 loads 1 byte from a0 (arg0 at entry) +0xb38.
  The `lw` at 0x2580 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `sw` at 0x25b0 stores 4 bytes to a0 (arg0 at entry) +0x1e4.
  The `jal` at 0x2534 calls splprof with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2548 calls a3_update_timestamp_offsets with a0=a0+1384, a1=?, a2=?, a3=?.
  The `jal` at 0x255c calls a3_update_timestamp_offsets with a0=a0+1912, a1=?, a2=?, a3=?.
  The `jal` at 0x2570 calls a3_update_timestamp_offsets with a0=a0+2440, a1=?, a2=?, a3=?.
  The `jal` at 0x2578 calls splx with a0=ret(splprof), a1=?, a2=?, a3=?.
  The `jal` at 0x25a8 calls itimeout with a0=sym(a3_timewrap_watchdog), a1=a0 at entry (arg0), a2=0xea60, a3=[sym(pltimeout)], a4=0x0, a5=0x0, a6=0x0.
  The `beq` branch at 0x2540 targets 0x2550, is taken when at(=[a0+1816]:1) == 0, and falls through when at(=[a0+1816]:1) != 0.
  The `beq` branch at 0x2554 targets 0x2564, is taken when v0(=[a0+2344]:1) == 0, and falls through when v0(=[a0+2344]:1) != 0.
  The `beq` branch at 0x2568 targets 0x2578, is taken when v1(=[a0+2872]:1) == 0, and falls through when v1(=[a0+2872]:1) != 0.
  The `beq` branch at 0x2584 targets 0x25b8, is taken when a0(=[a0+484]) == 0, and falls through when a0(=[a0+484]) != 0.
  The return at 0x25bc has v0 = one of ret(splx), ret(itimeout).

- `a3_update_timestamp_offsets` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x25c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x25c4-0x2618 (84 bytes).
  It occupies 84 bytes.
  The `lw` at 0x25d8 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x25dc loads 4 bytes from a0 (arg0 at entry) +0x1fc.
  The `ld` at 0x25f8 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `sd` at 0x2604 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `sw` at 0x2608 stores 4 bytes to a0 (arg0 at entry) +0x1fc.
  The `jal` at 0x25d4 calls pciio_pio_read64 with a0=[a0+484], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x25f0 targets 0x2608, is taken when a2(?) >= at(=[a0+508]) (unsigned), and falls through when a2(?) < at(=[a0+508]) (unsigned).
  The return at 0x2610 has v0 = one of ret(pciio_pio_read64), [a0+512]:8+0x100000000.

- `a3_err_intr` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2618 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2618-0x26a8 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x267c loads 4 bytes from a1 (arg1 at entry) +0x1f4.
  The `sw` at 0x2694 stores 4 bytes to a1 (arg1 at entry) +0x1f0.
  The `jal` at 0x262c calls pciio_pio_read64 with a0=0xffffffffbf310010, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2648 calls pciio_pio_read64 with a0=0xffffffffbf310018, a1=?, a2=?, a3=?.
  The `jal` at 0x2668 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf310018, a2=?, a3=?.
  The `jal` at 0x268c calls itimeout with a0=sym(a3_do_volume), a1=a1 at entry (arg1), a2=[a1+500], a3=[sym(pltimeout)], a4=0x0, a5=0x0, a6=0x0.
  The `beq` branch at 0x263c targets 0x269c, is taken when (a1(=(ret(pciio_pio_read64) << 0x0)) & 0x2) == 0, and falls through when (a1(=(ret(pciio_pio_read64) << 0x0)) & 0x2) != 0.
  The return at 0x26a0 has v0 = one of ret(pciio_pio_read64), ret(itimeout).

- `a3_shutdown` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x26a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x26a8-0x2770 (200 bytes).
  It occupies 200 bytes.
  The `lw` at 0x26a8 loads 4 bytes from a0 (arg0 at entry) +0x1f0.
  The `sw` at 0x26c8 stores 4 bytes to a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x26cc loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `sw` at 0x26e0 stores 4 bytes to a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x26f0 loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  The `lw` at 0x2738 loads 4 bytes from ?.
  The `jal` at 0x26c0 calls untimeout with a0=[a0+496], a1=[a0+496], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x26d8 calls untimeout with a0=[a0+484], a1=?, a2=?, a3=?.
  The `jal` at 0x26e8 calls pciio_pio_read64 with a0=0xffffffffbf310018, a1=?, a2=?, a3=?.
  The `jal` at 0x270c calls pciio_pio_write64 with a0=?, a1=0xffffffffbf310018, a2=?, a3=?.
  The `jal` at 0x2724 calls unsetcrimevector with a0=0x6, a1=sym(a3_err_intr), a2=?, a3=?.
  The `jal` at 0x2734 calls kdsp_unmap_resource with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x274c calls a3_destroy_devices with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x275c calls a3_idbg_delfuncs with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x26b8 targets 0x26cc, is taken when a1(=[a0+496]) == 0, and falls through when a1(=[a0+496]) != 0.
  The `beq` branch at 0x26d0 targets 0x26e4, is taken when a0(=[a0+484]) == 0, and falls through when a0(=[a0+484]) != 0.
  The `bne` branch at 0x2744 targets 0x2734, is taken when s2(?) < 0x3 (signed), and falls through when s2(?) >= 0x3 (signed).
  The return at 0x2768 has v0 = ret(a3_idbg_delfuncs).

- `do_read_codec_reg` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2770 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2770-0x2804 (148 bytes).
  It occupies 148 bytes.
  The `lhu` at 0x2774 loads 2 bytes from a1 (arg1 at entry) +0x204.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x1d8, including `lw` at 0x2790, `lw` at 0x27c4.
  The `sh` at 0x27d0 stores 2 bytes to a1 (arg1 at entry) +0x204.
  The `sh` at 0x27f8 stores 2 bytes to (a1 + (a0 + a0)) +0x194.
  The `jal` at 0x2794 calls us_delay with a0=([a1+472] + [a1+472]), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x27b4 calls pciio_pio_write64 with a0=((a0 << 0x11) | 0x10000), a1=0xffffffffbf300008, a2=0x10000, a3=a3 at entry (arg3).
  The `jal` at 0x27bc calls wbflush with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x27c8 calls us_delay with a0=([a1+472] << 0x2), a1=?, a2=?, a3=?.
  The `jal` at 0x27d8 calls pciio_pio_read64 with a0=0xffffffffbf300018, a1=?, a2=?, a3=?.
  The `bne` branch at 0x2788 targets 0x27a4, is taken when a0 != at(=[a1+516]:2), and falls through when a0 == at(=[a1+516]:2).
  The `beq` branch at 0x279c targets 0x27d8 and is always taken.
  The return at 0x27fc has v0 = ?.

- `write_codec_reg` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2804 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2804-0x2888 (132 bytes).
  It occupies 132 bytes.
  The `lhu` at 0x2864 loads 2 bytes from a2 (arg2 at entry) +0x1dc.
  The `jal` at 0x2820 calls spltimeout with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2834 calls pciio_pio_write64 with a0=0x0, a1=0xffffffffbf300010, a2=?, a3=?.
  The `jal` at 0x2844 calls do_write_codec_reg with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2858 calls do_read_codec_reg with a0=0x1, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x2868 calls pciio_pio_write64 with a0=[a2+476]:2, a1=0xffffffffbf300010, a2=?, a3=?.
  The `jal` at 0x2874 calls splx with a0=ret(spltimeout), a1=?, a2=?, a3=?.
  The return at 0x2880 has v0 = ret(splx).

- `do_write_codec_reg` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2888 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2888-0x28e8 (96 bytes).
  It occupies 96 bytes.
  The `sh` at 0x2894 stores 2 bytes to a2 (arg2 at entry) +0x204.
  The `sh` at 0x28b8 stores 2 bytes to (a2 + (a0 + a0)) +0x194.
  The `lw` at 0x28cc loads 4 bytes from a2 (arg2 at entry) +0x1d8.
  The `jal` at 0x28bc calls pciio_pio_write64 with a0=?, a1=0xffffffffbf300008, a2=a2 at entry (arg2), a3=(a0 << 0x11).
  The `jal` at 0x28c4 calls wbflush with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x28d0 calls us_delay with a0=([a2+472] + [a2+472]), a1=?, a2=?, a3=?.
  The return at 0x28e0 has v0 = ret(us_delay).

- `a3_start_dma` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x28e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x28e8-0x2ab8 (464 bytes).
  It occupies 464 bytes.
  The `lw` at 0x28f0 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `lw` at 0x28f8 loads 4 bytes from [a0+464] +0x1d4.
  The `lw` at 0x28fc loads 4 bytes from a0 (arg0 at entry) +0x1f4.
  The `sw` at 0x2920 stores 4 bytes to [a0+464] +0x1d4.
  The `lbu` at 0x2924 loads 1 byte from a0 (arg0 at entry) +0x1b0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x128, including `lw` at 0x295c, `lw` at 0x296c, `lw` at 0x29e8.
  2 such `sw` accesses store 4 bytes to [a0+296] +0x0, including `sw` at 0x2964, `sw` at 0x29ec.
  2 such `sw` accesses store 4 bytes to [a0+296] +0x4, including `sw` at 0x2978, `sw` at 0x29fc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e8, including `lw` at 0x2984, `lw` at 0x2a14.
  The `lw` at 0x2998 loads 4 bytes from a0 (arg0 at entry) +0x144.
  The `lw` at 0x299c loads 4 bytes from a0 (arg0 at entry) +0x178.
  The `lw` at 0x29a0 loads 4 bytes from [a0+324] +0x13c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x130, including `lw` at 0x29a8, `lw` at 0x29b8.
  The `lw` at 0x29cc loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e0, including `lw` at 0x29d0, `lw` at 0x2a08, `lw` at 0x2a38.
  The `sw` at 0x29d4 stores 4 bytes to a0 (arg0 at entry) +0x1fc.
  The `ld` at 0x29d8 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `sd` at 0x29e4 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0x2a20 loads 4 bytes from [a0+464] +0x1e4.
  The `lw` at 0x2a2c loads 4 bytes from a0 (arg0 at entry) +0x1ec.
  The `sb` at 0x2a48 stores 1 byte to a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x2a64 loads 4 bytes from a0 (arg0 at entry) +0x1a4.
  The `sw` at 0x2ab4 stores 4 bytes to [a0+464] +0x1e4.
  The `jal` at 0x2918 calls write_codec_reg with a0=0x4, a1=0x8888, a2=[a0+464], a3=a3 at entry (arg3).
  The `jal` at 0x2930 calls pciio_pio_read64 with a0=0xffffffffbf300000, a1=?, a2=?, a3=?.
  The `jal` at 0x2954 calls splprof with a0=(ret(pciio_pio_read64) << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x2980 calls pciio_pio_write64 with a0=?, a1=[a0+488], a2=[a0+296], a3=?.
  The `jal` at 0x2988 calls splx with a0=ret(splprof), a1=?, a2=?, a3=?.
  The `jal` at 0x29b0 calls bzero with a0=[a0+304], a1=?, a2=?, a3=?.
  The `jal` at 0x29bc calls dki_dcache_wb with a0=[a0+304], a1=?, a2=?, a3=?.
  The `jal` at 0x29c8 calls pciio_pio_write64 with a0=0x0, a1=[a0+484], a2=?, a3=?.
  The `jal` at 0x29e0 calls pciio_pio_write64 with a0=0x400, a1=[a0+480], a2=?, a3=?.
  The `jal` at 0x29f8 calls us_delay with a0=0x5, a1=?, a2=?, a3=?.
  The `jal` at 0x2a04 calls pciio_pio_write64 with a0=0x0, a1=[a0+480], a2=?, a3=?.
  The `jal` at 0x2a18 calls pciio_pio_write64 with a0=?, a1=[a0+488], a2=?, a3=?.
  The `jal` at 0x2a3c calls pciio_pio_write64 with a0=?, a1=[a0+480], a2=?, a3=?.
  The `jal` at 0x2aa8 calls itimeout with a0=sym(a3_timewrap_watchdog), a1=[a0+464], a2=0xea60, a3=[sym(pltimeout)], a4=0x0, a5=0x0, a6=0x0.
  The `beq` branch at 0x2908 targets 0x2924, is taken when at(=[[a0+464]+468]) == 0, and falls through when at(=[[a0+464]+468]) != 0.
  The `beq` branch at 0x2928 targets 0x2a64, is taken when v0(=[a0+432]:1) == 0, and falls through when v0(=[a0+432]:1) != 0.
  The `beq` branch at 0x2938 targets 0x2a7c, is taken when s2(=[a0+500]) == 0, and falls through when s2(=[a0+500]) != 0.
  The `beq` branch at 0x294c targets 0x2a88, is taken when s2(=[a0+500]) == v1(=0x1), and falls through when s2(=[a0+500]) != v1(=0x1).
  The `beq` branch at 0x2990 targets 0x2a4c and is always taken.
  The `beq` branch at 0x2a24 targets 0x2a90, is taken when a1(=[[a0+464]+484]) == 0, and falls through when a1(=[[a0+464]+484]) != 0.
  The `bne` branch at 0x2a6c targets 0x2998, is taken when (a1(=[a0+420]) & 0x1) != 0, and falls through when (a1(=[a0+420]) & 0x1) == 0.
  The `beq` branch at 0x2a74 targets 0x29c8 and is always taken.
  The `beq` branch at 0x2a80 targets 0x2954 and is always taken.
  The `beq` branch at 0x2a88 targets 0x2954 and is always taken.
  The `beq` branch at 0x2ab0 targets 0x2a2c and is always taken.
  The return at 0x2a5c has v0 = 0x1.

- `a3_stop_dma` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2ab8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2ab8-0x2ae8 (48 bytes).
  It occupies 48 bytes.
  The `lw` at 0x2ad0 loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  The `sb` at 0x2ad8 stores 1 byte to a0 (arg0 at entry) +0x1b0.
  The `jal` at 0x2acc calls pciio_pio_write64 with a0=0x0, a1=[a0+480], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2ae0 has v0 = ret(pciio_pio_write64).

- `a3_pre_connect` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2ae8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2ae8-0x2b1c (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x2ae8 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `lw` at 0x2af8 loads 4 bytes from [a0+464] +0x740.
  The `lw` at 0x2b00 loads 4 bytes from [[a0+464]+1856] +0x9c.
  The `bne` branch at 0x2af0 targets 0x2b10, is taken when a0 != at(=[a0+464]+1384), and falls through when a0 == at(=[a0+464]+1384).
  The `beq` branch at 0x2b08 targets 0x2b14, is taken when v1(=[[[a0+464]+1856]+156]) == a0(=0x2000000d), and falls through when v1(=[[[a0+464]+1856]+156]) != a0(=0x2000000d).
  The return at 0x2b14 has v0 = one of 0x0, 0x4.

- `a3_set_clockgen` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2b1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2b1c-0x2cd8 (444 bytes).
  It occupies 444 bytes.
  The `lw` at 0x2b24 loads 4 bytes from a0 (arg0 at entry) +0x150.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x2b28, `lw` at 0x2b94, `lw` at 0x2c68.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x154, including `lw` at 0x2b4c, `lw` at 0x2bac.
  The `lw` at 0x2b50 loads 4 bytes from [a0+340] +0x11c.
  The `lhu` at 0x2b64 loads 2 bytes from (([a0+344] + [a0+344]) + [a0+336]) +0x194.
  The `sw` at 0x2bb0 stores 4 bytes to a0 (arg0 at entry) +0x154.
  The `sw` at 0x2bb4 stores 4 bytes to a0 (arg0 at entry) +0x134.
  3 such `lw` accesses load 4 bytes from [a0+336] +0x1e8, including `lw` at 0x2bd8, `lw` at 0x2c6c, `lw` at 0x2c90.
  The `lw` at 0x2be4 loads 4 bytes from a0 (arg0 at entry) +0x134.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x2bf8, `lw` at 0x2c30.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x110, including `ld` at 0x2c00, `ld` at 0x2c38.
  2 such `lhu` accesses load 2 bytes from ([a0+336] + ([a0+348] + [a0+348])) +0x194, including `lhu` at 0x2c08, `lhu` at 0x2c40.
  The `lw` at 0x2c7c loads 4 bytes from sym(mvpaudio_input_timing) +0x0.
  The `lw` at 0x2ca0 loads 4 bytes from sym(mvpaudio_output_timing) +0x0.
  The `lhu` at 0x2cbc loads 2 bytes from ([a0+336] + ([a0+344] + [a0+344])) +0x194.
  The `jal` at 0x2b8c calls a3_set_video_rate with a0=a0 at entry (arg0), a1=?, a2=?, a3=a3 at entry (arg3), a4=[(([a0+344] + [a0+344]) + [a0+336])+404]:2, a5=[a0+344], a6=0x1, a7=0x2.
  The `jal` at 0x2ba4 calls write_codec_reg with a0=?, a1=?, a2=[a0+336], a3=?, a5=[a0+344].
  The `jal` at 0x2c20 calls write_codec_reg with a0=?, a1=?, a2=[a0+336], a3=a3 at entry (arg3), a5=[a0+344], a6=[a0+348], a7=[([a0+336] + ([a0+348] + [a0+348]))+404]:2.
  The `jal` at 0x2c5c calls write_codec_reg with a0=?, a1=?, a2=[a0+336], a3=a3 at entry (arg3), a4=[(([a0+344] + [a0+344]) + [a0+336])+404]:2, a5=[a0+344], a6=[a0+348].
  The `jal` at 0x2cc8 calls a3_set_video_rate with a0=a0 at entry (arg0), a1=?, a2=[a0+340], a3=a3 at entry (arg3), a4=[[a0+336]+488], a5=[a0+344], a6=[a0+336]+1096, a7=0x2.
  The `beq` branch at 0x2b40 targets 0x2bb8, is taken when a5(=[a0+344]) == 0, and falls through when a5(=[a0+344]) != 0.
  The `beq` branch at 0x2b48 targets 0x2bd0, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2b60 targets 0x2c30, is taken when a0(=[[a0+340]+284]) == 0, and falls through when a0(=[[a0+340]+284]) != 0.
  The `beq` branch at 0x2b68 targets 0x2c6c, is taken when a0(=[[a0+340]+284]) == a6(=0x1), and falls through when a0(=[[a0+340]+284]) != a6(=0x1).
  The `beq` branch at 0x2b70 targets 0x2c90, is taken when a0(=[[a0+340]+284]) == a7(=0x2), and falls through when a0(=[[a0+340]+284]) != a7(=0x2).
  The `bne` branch at 0x2bd0 targets 0x2b50, is taken when a2(=[a0+340]) != 0, and falls through when a2(=[a0+340]) == 0.
  The `beq` branch at 0x2bdc targets 0x2bf8, is taken when a4(=[[a0+336]+488]) == 0, and falls through when a4(=[[a0+336]+488]) != 0.
  The `beq` branch at 0x2be8 targets 0x2cb4, is taken when a1(=[a0+308]) == a0(=[a0+336]+808), and falls through when a1(=[a0+308]) != a0(=[a0+336]+808).
  The `beq` branch at 0x2bf0 targets 0x2cb8, is taken when a1(=[a0+308]) == a6(=[a0+336]+1096), and falls through when a1(=[a0+308]) != a6(=[a0+336]+1096).
  The `beq` branch at 0x2c10 targets 0x2bbc, is taken when a4(?) == a7(=[([a0+336] + ([a0+348] + [a0+348]))+404]:2), and falls through when a4(?) != a7(=[([a0+336] + ([a0+348] + [a0+348]))+404]:2).
  The `beq` branch at 0x2c28 targets 0x2bbc and is always taken.
  The `beq` branch at 0x2c4c targets 0x2b9c, is taken when a7(?) == t8(=[([a0+336] + ([a0+348] + [a0+348]))+404]:2), and falls through when a7(?) != t8(=[([a0+336] + ([a0+348] + [a0+348]))+404]:2).
  The `beq` branch at 0x2c64 targets 0x2b9c and is always taken.
  The `beq` branch at 0x2c74 targets 0x2b70, is taken when t9(=[[a0+336]+488]) == 0, and falls through when t9(=[[a0+336]+488]) != 0.
  The `bne` branch at 0x2c80 targets 0x2b70, is taken when ra(=[sym(mvpaudio_input_timing)]) != at(=0x3), and falls through when ra(=[sym(mvpaudio_input_timing)]) == at(=0x3).
  The `beq` branch at 0x2c88 targets 0x2b78 and is always taken.
  The `beq` branch at 0x2c98 targets 0x2b78, is taken when v0(=[[a0+336]+488]) == 0, and falls through when v0(=[[a0+336]+488]) != 0.
  The `bne` branch at 0x2ca4 targets 0x2b78, is taken when v1(=[sym(mvpaudio_output_timing)]) != a1(=0x3), and falls through when v1(=[sym(mvpaudio_output_timing)]) == a1(=0x3).
  The `beq` branch at 0x2cac targets 0x2b78 and is always taken.
  The `beq` branch at 0x2cd0 targets 0x2bbc and is always taken.
  The return at 0x2bc8 has v0 = one of ?, ret(write_codec_reg), ret(a3_set_video_rate).

- `a3_set_video_rate` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2cd8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2cd8-0x2df8 (288 bytes).
  It occupies 288 bytes.
  The `ld` at 0x2cdc loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `lw` at 0x2ce4 loads 4 bytes from sym(.data) +0x1d20.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2d2c, `lw` at 0x2d38.
  3 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2d64, `lhu` at 0x2dc0, `lhu` at 0x2dd0.
  The `lhu` at 0x2d78 loads 2 bytes from sym(.data) +0x1d24.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x110, including `sd` at 0x2d84, `sd` at 0x2de4.
  The `lw` at 0x2d9c loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lbu` at 0x2da8 loads 1 byte from a0 (arg0 at entry) +0x15b.
  The `lw` at 0x2df4 loads 4 bytes from sym(.data) +0x1d28.
  The `jal` at 0x2da4 calls write_codec_reg with a0=[a0+347]:1, a1=?, a2=[a0+336], a3=a3 at entry (arg3).
  The `beq` branch at 0x2d04 targets 0x2d78, is taken when a5(=[sym(.data)+7456]) >= a4(?) (signed), and falls through when a5(=[sym(.data)+7456]) < a4(?) (signed).
  The `beq` branch at 0x2d0c targets 0x2de8 and is always taken.
  The `beq` branch at 0x2d24 targets 0x2d8c, is taken when a6(?) >= 0x7 (signed), and falls through when a6(?) < 0x7 (signed).
  The `beq` branch at 0x2d30 targets 0x2dc0, is taken when t2(?) == a4(?), and falls through when t2(?) != a4(?).
  The `beq` branch at 0x2d40 targets 0x2d18, is taken when t3(?) >= a4(?) (signed), and falls through when t3(?) < a4(?) (signed).
  The `beq` branch at 0x2d48 targets 0x2d14, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x2d5c targets 0x2dd0, is taken when ra(?) >= a4(?) (signed), and falls through when ra(?) < a4(?) (signed).
  The `beq` branch at 0x2d70 targets 0x2ddc and is always taken.
  The `beq` branch at 0x2d90 targets 0x2d9c, is taken when (s0(?) & 0xc0) == 0, and falls through when (s0(?) & 0xc0) != 0.
  The `beq` branch at 0x2dc8 targets 0x2d8c and is always taken.
  The `beq` branch at 0x2de0 targets 0x2d8c and is always taken.
  The `beq` branch at 0x2df0 targets 0x2d30 and is always taken.
  The return at 0x2db8 has v0 = ?.

- `a3_update_subsys` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2df8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2df8-0x2e6c (116 bytes).
  It occupies 116 bytes.
  The `lw` at 0x2df8 loads 4 bytes from a0 (arg0 at entry) +0x770.
  The `lbu` at 0x2e1c loads 1 byte from a0 (arg0 at entry) +0x718.
  The `sw` at 0x2e38 stores 4 bytes to a0 (arg0 at entry) +0x758.
  The `lbu` at 0x2e3c loads 1 byte from a0 (arg0 at entry) +0x928.
  The `sw` at 0x2e48 stores 4 bytes to a0 (arg0 at entry) +0x968.
  The `lbu` at 0x2e4c loads 1 byte from a0 (arg0 at entry) +0xb38.
  The `sw` at 0x2e5c stores 4 bytes to a0 (arg0 at entry) +0xb78.
  The `jal` at 0x2e10 calls pciio_pio_read64 with a0=0xffffffffbf300000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x2e08 targets 0x2e60, is taken when at(=[a0+1904]) == 0, and falls through when at(=[a0+1904]) != 0.
  The `beq` branch at 0x2e30 targets 0x2e3c, is taken when v1(=[a0+1816]:1) == 0, and falls through when v1(=[a0+1816]:1) != 0.
  The `beq` branch at 0x2e40 targets 0x2e4c, is taken when a7(=[a0+2344]:1) == 0, and falls through when a7(=[a0+2344]:1) != 0.
  The `beq` branch at 0x2e50 targets 0x2e60, is taken when t0(=[a0+2872]:1) == 0, and falls through when t0(=[a0+2872]:1) != 0.
  The return at 0x2e64 has v0 = one of ?, ret(pciio_pio_read64).

- `a3_update_dev` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2e6c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2e6c-0x2f4c (224 bytes).
  It occupies 224 bytes.
  The `lbu` at 0x2e70 loads 1 byte from a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x2e88 loads 4 bytes from a0 (arg0 at entry) +0x1a4.
  The `lw` at 0x2e8c loads 4 bytes from a0 (arg0 at entry) +0x128.
  The `lw` at 0x2e90 loads 4 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x2e94 loads 4 bytes from [a0+296] +0x0.
  The `sw` at 0x2eac stores 4 bytes to [a0+296] +0x0.
  The `lw` at 0x2eb0 loads 4 bytes from a0 (arg0 at entry) +0x178.
  The `ld` at 0x2ebc loads 8 bytes from a0 (arg0 at entry) +0x118.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x2ec0, `lw` at 0x2f28.
  The `sd` at 0x2ed4 stores 8 bytes to a0 (arg0 at entry) +0x118.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x130, including `lw` at 0x2ee4, `lw` at 0x2f2c.
  4 such `lw` accesses load 4 bytes from [a0+296] +0x4, including `lw` at 0x2ef0, `lw` at 0x2f04, `lw` at 0x2f24.
  The `sw` at 0x2f0c stores 4 bytes to [a0+296] +0x4.
  The `jal` at 0x2efc calls dki_dcache_inval with a0=([a0+304] + ([[a0+296]+4] << 0x2)), a1=?, a2=a2 at entry (arg2), a3=?, a4=[a0+304].
  The `jal` at 0x2f1c calls dki_dcache_inval with a0=[a0+304], a1=?, a2=a2 at entry (arg2), a3=?, a4=[a0+304].
  The `jal` at 0x2f3c calls dki_dcache_inval with a0=([a0+304] + ([[a0+296]+4] << 0x2)), a1=?, a2=([[a0+296]+4] << 0x2), a3=?.
  The `beq` branch at 0x2e80 targets 0x2ed8, is taken when at(=[a0+432]:1) == 0, and falls through when at(=[a0+432]:1) != 0.
  The `beq` branch at 0x2ea0 targets 0x2ee4, is taken when (a4(=[a0+420]) & 0x1) == 0, and falls through when (a4(=[a0+420]) & 0x1) != 0.
  The `bgez` branch at 0x2eb8 targets 0x2ec8, is taken when a0(?) >= 0 (signed), and falls through when a0(?) < 0 (signed).
  The `bltz` branch at 0x2ee8 targets 0x2f18, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `beq` branch at 0x2f10 targets 0x2eb0 and is always taken.
  The `beq` branch at 0x2f44 targets 0x2f08 and is always taken.
  The return at 0x2edc has v0 = ?.

- `a3_writeback_rb` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2f4c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2f4c-0x2fa4 (88 bytes).
  It occupies 88 bytes.
  The `lbu` at 0x2f4c loads 1 byte from a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x2f64 loads 4 bytes from a0 (arg0 at entry) +0x1a4.
  The `lw` at 0x2f7c loads 4 bytes from a0 (arg0 at entry) +0x168.
  The `lw` at 0x2f88 loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `jal` at 0x2f74 calls kdsp_writeback_rb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2f8c calls pciio_pio_write64 with a0=?, a1=[a0+488], a2=?, a3=?.
  The `beq` branch at 0x2f5c targets 0x2f94, is taken when at(=[a0+432]:1) == 0, and falls through when at(=[a0+432]:1) != 0.
  The `beq` branch at 0x2f6c targets 0x2f7c, is taken when (v0(=[a0+420]) & 0x1) == 0, and falls through when (v0(=[a0+420]) & 0x1) != 0.
  The return at 0x2f9c has v0 = one of ?, ret(pciio_pio_write64).

- `a3_get_rb_mscust` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x2fa4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x2fa4-0x3040 (156 bytes).
  It occupies 156 bytes.
  The `lw` at 0x2fc4 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `ld` at 0x2fdc loads 8 bytes from a0 (arg0 at entry) +0x120.
  The `lw` at 0x2fe8 loads 4 bytes from a0 (arg0 at entry) +0x1fc.
  The `ld` at 0x3008 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `sd` at 0x3018 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0x301c loads 4 bytes from a0 (arg0 at entry) +0x194.
  The `sd` at 0x302c stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x3030 stores 4 bytes to a0 (arg0 at entry) +0x1fc.
  The `jal` at 0x2fc0 calls pciio_pio_read64 with a0=[a0+484], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2fd4 calls fill_ust_highbits with a0=?, a1=a0+288, a2=?, a3=?.
  The `jal` at 0x2fe0 calls ust_to_nano with a0=[a0+288]:8, a1=a2 at entry (arg2), a2=?, a3=?.
  The `beq` branch at 0x300c targets 0x301c, is taken when a3(=ret(pciio_pio_read64)) >= a4(=[a0+508]) (unsigned), and falls through when a3(=ret(pciio_pio_read64)) < a4(=[a0+508]) (unsigned).
  The return at 0x3038 has v0 = ret(ust_to_nano).

- `a3_idbg_dump_codec_regs` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3040 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3040-0x30b4 (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0x3060 calls qprintf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3068 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3078 calls do_read_codec_reg with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x3088 calls qprintf with a0=sym(.rodata), a1=?, a2=ret(do_read_codec_reg), a3=?.
  The `bne` branch at 0x3098 targets 0x3074, is taken when s0(?) < 0x1d (signed), and falls through when s0(?) >= 0x1d (signed).
  The return at 0x30ac has v0 = ret(qprintf).

- `a3_idbg_dump_subsys` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x30b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x30b4-0x31b0 (252 bytes).
  It occupies 252 bytes.
  The `lw` at 0x30b4 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x30e0 loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `lw` at 0x30e4 loads 4 bytes from a0 (arg0 at entry) +0x154.
  The `lw` at 0x30f0 loads 4 bytes from a0 (arg0 at entry) +0x160.
  The `lw` at 0x30f4 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `lw` at 0x3100 loads 4 bytes from a0 (arg0 at entry) +0x168.
  The `lw` at 0x3104 loads 4 bytes from a0 (arg0 at entry) +0x164.
  The `lw` at 0x3110 loads 4 bytes from a0 (arg0 at entry) +0x184.
  The `lw` at 0x3114 loads 4 bytes from a0 (arg0 at entry) +0x178.
  The `lw` at 0x3118 loads 4 bytes from a0 (arg0 at entry) +0x174.
  The `lw` at 0x3124 loads 4 bytes from a0 (arg0 at entry) +0x180.
  The `lw` at 0x3128 loads 4 bytes from a0 (arg0 at entry) +0x17c.
  The `lhu` at 0x3134 loads 2 bytes from a0 (arg0 at entry) +0x204.
  The `lhu` at 0x3138 loads 2 bytes from a0 (arg0 at entry) +0x1dc.
  The `lw` at 0x313c loads 4 bytes from a0 (arg0 at entry) +0x1d8.
  The `lw` at 0x3148 loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `lw` at 0x3154 loads 4 bytes from sym(mvpaudio_output_timing) +0x0.
  The `lw` at 0x3160 loads 4 bytes from sym(mvpaudio_input_timing) +0x0.
  The `jal` at 0x30d8 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=[a0+336], a3=a3 at entry (arg3).
  The `jal` at 0x30e8 calls qprintf with a0=sym(.rodata), a1=[a0+340], a2=[a0+344], a3=?.
  The `jal` at 0x30f8 calls qprintf with a0=sym(.rodata), a1=[a0+348], a2=[a0+352], a3=?.
  The `jal` at 0x3108 calls qprintf with a0=sym(.rodata), a1=[a0+356], a2=[a0+360], a3=?.
  The `jal` at 0x311c calls qprintf with a0=sym(.rodata), a1=[a0+372], a2=[a0+376], a3=[a0+388].
  The `jal` at 0x312c calls qprintf with a0=sym(.rodata), a1=[a0+380], a2=[a0+384], a3=?.
  The `jal` at 0x3140 calls qprintf with a0=sym(.rodata), a1=[a0+472], a2=[a0+476]:2, a3=[a0+516]:2.
  The `jal` at 0x315c calls qprintf with a0=sym(.rodata), a1=[a0+488], a2=[sym(mvpaudio_input_timing)], a3=[sym(mvpaudio_output_timing)].
  The `jal` at 0x3164 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3178 calls qprintf with a0=sym(.rodata), a1=a0+1384, a2=a0+1912, a3=a0+2440.
  The `jal` at 0x3180 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3194 calls qprintf with a0=sym(.rodata), a1=a0+2968, a2=a0+3240, a3=a0+3512.
  The return at 0x31a8 has v0 = ret(qprintf).

- `a3_idbg_dump_device` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x31b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x31b0-0x3210 (96 bytes).
  It occupies 96 bytes.
  The `lw` at 0x31d8 loads 4 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x31dc loads 4 bytes from a0 (arg0 at entry) +0x1f4.
  The `lw` at 0x31e8 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x31ec loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `lw` at 0x31f0 loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  The `jal` at 0x31d0 calls qprintf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x31e0 calls qprintf with a0=sym(.rodata), a1=[a0+500], a2=[a0+496], a3=?.
  The `jal` at 0x31f4 calls qprintf with a0=sym(.rodata), a1=[a0+480], a2=[a0+488], a3=[a0+484].
  The return at 0x3208 has v0 = ret(qprintf).

- `a3_idbg_dump_clockgen` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3210 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3210-0x3218 (8 bytes).
  It occupies 8 bytes.
  The return at 0x3210 has v0 = ?.

- `a3_idbg_dump_hw` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3218 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3218-0x3410 (504 bytes).
  It occupies 504 bytes.
  The `jal` at 0x3224 calls pciio_pio_read64 with a0=0xffffffffbf300000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3238 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x3244 calls pciio_pio_read64 with a0=0xffffffffbf300008, a1=?, a2=?, a3=?.
  The `jal` at 0x3250 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x325c calls pciio_pio_read64 with a0=0xffffffffbf300010, a1=?, a2=?, a3=?.
  The `jal` at 0x3268 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x3274 calls pciio_pio_read64 with a0=0xffffffffbf300018, a1=?, a2=?, a3=?.
  The `jal` at 0x3280 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x328c calls pciio_pio_read64 with a0=0xffffffffbf300020, a1=?, a2=?, a3=?.
  The `jal` at 0x3298 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x32a4 calls pciio_pio_read64 with a0=0xffffffffbf300028, a1=?, a2=?, a3=?.
  The `jal` at 0x32b0 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x32bc calls pciio_pio_read64 with a0=0xffffffffbf300030, a1=?, a2=?, a3=?.
  The `jal` at 0x32c8 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x32d4 calls pciio_pio_read64 with a0=0xffffffffbf300038, a1=?, a2=?, a3=?.
  The `jal` at 0x32e0 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x32ec calls pciio_pio_read64 with a0=0xffffffffbf300040, a1=?, a2=?, a3=?.
  The `jal` at 0x3300 calls qprintf with a0=sym(.rodata), a1=0xffffffffbf300040, a2=(ret(pciio_pio_read64) << 0x0), a3=?.
  The `jal` at 0x330c calls pciio_pio_read64 with a0=0xffffffffbf300048, a1=?, a2=?, a3=?.
  The `jal` at 0x3320 calls qprintf with a0=sym(.rodata), a1=0xffffffffbf300048, a2=(ret(pciio_pio_read64) << 0x0), a3=?.
  The `jal` at 0x332c calls pciio_pio_read64 with a0=0xffffffffbf300050, a1=?, a2=?, a3=?.
  The `jal` at 0x3338 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x3344 calls pciio_pio_read64 with a0=0xffffffffbf300058, a1=?, a2=?, a3=?.
  The `jal` at 0x3350 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x335c calls pciio_pio_read64 with a0=0xffffffffbf300060, a1=?, a2=?, a3=?.
  The `jal` at 0x3368 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x3374 calls pciio_pio_read64 with a0=0xffffffffbf300068, a1=?, a2=?, a3=?.
  The `jal` at 0x3380 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x338c calls pciio_pio_read64 with a0=0xffffffffbf300070, a1=?, a2=?, a3=?.
  The `jal` at 0x3398 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x33a4 calls pciio_pio_read64 with a0=0xffffffffbf300078, a1=?, a2=?, a3=?.
  The `jal` at 0x33b0 calls qprintf with a0=sym(.rodata), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x33bc calls pciio_pio_read64 with a0=0xffffffffbf340020, a1=?, a2=?, a3=?.
  The `jal` at 0x33c8 calls qprintf with a0=sym(.rodata), a1=ret(pciio_pio_read64), a2=?, a3=?.
  The `jal` at 0x33d4 calls pciio_pio_read64 with a0=0xffffffffbf340028, a1=?, a2=?, a3=?.
  The `jal` at 0x33e0 calls qprintf with a0=sym(.rodata), a1=ret(pciio_pio_read64), a2=?, a3=?.
  The `jal` at 0x33ec calls pciio_pio_read64 with a0=0xffffffffbf340030, a1=?, a2=?, a3=?.
  The `jal` at 0x33f8 calls qprintf with a0=sym(.rodata), a1=ret(pciio_pio_read64), a2=?, a3=?.
  The return at 0x3408 has v0 = ret(qprintf).

- `a3_idbg_addfuncs` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3410 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3410-0x34e8 (216 bytes).
  It occupies 216 bytes.
  The `jal` at 0x3448 calls idbg_addfunc with a0=sym(.rodata)+1936, a1=sym(a3_idbg_dump_codec_regs), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3468 calls idbg_addfunc with a0=sym(.rodata)+1952, a1=sym(a3_idbg_dump_subsys), a2=?, a3=?.
  The `jal` at 0x3488 calls idbg_addfunc with a0=sym(.rodata)+1960, a1=sym(a3_idbg_dump_device), a2=?, a3=?.
  The `jal` at 0x34a8 calls idbg_addfunc with a0=sym(.rodata)+1968, a1=sym(a3_idbg_dump_clockgen), a2=?, a3=?.
  The `jal` at 0x34c8 calls idbg_addfunc with a0=sym(.rodata)+1976, a1=sym(a3_idbg_dump_hw), a2=?, a3=?.
  The `bne` branch at 0x3424 targets 0x343c, is taken when v0(=[sym(.sdata)+40]) < 0x1 (signed), and falls through when v0(=[sym(.sdata)+40]) >= 0x1 (signed).
  The `beq` branch at 0x3450 targets 0x3460, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x3458 targets 0x3434 and is always taken.
  The `beq` branch at 0x3470 targets 0x3480, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x3478 targets 0x3434 and is always taken.
  The `beq` branch at 0x3490 targets 0x34a0, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x3498 targets 0x3434 and is always taken.
  The `beq` branch at 0x34b0 targets 0x34c0, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x34b8 targets 0x3434 and is always taken.
  The `beq` branch at 0x34d0 targets 0x34e0, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x34d8 targets 0x3434 and is always taken.
  The `beq` branch at 0x34e0 targets 0x3430 and is always taken.
  The return at 0x3434 has v0 = one of 0x0, ret(idbg_addfunc).

- `a3_idbg_delfuncs` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x34e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x34e8-0x354c (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x350c calls idbg_delfunc with a0=sym(a3_idbg_dump_codec_regs), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3518 calls idbg_delfunc with a0=sym(a3_idbg_dump_subsys), a1=?, a2=?, a3=?.
  The `jal` at 0x3524 calls idbg_delfunc with a0=sym(a3_idbg_dump_device), a1=?, a2=?, a3=?.
  The `jal` at 0x3530 calls idbg_delfunc with a0=sym(a3_idbg_dump_clockgen), a1=?, a2=?, a3=?.
  The `jal` at 0x353c calls idbg_delfunc with a0=sym(a3_idbg_dump_hw), a1=?, a2=?, a3=?.
  The `blez` branch at 0x34f8 targets 0x3508, is taken when at(=[sym(.sdata)+40]-1) <= 0 (signed), and falls through when at(=[sym(.sdata)+40]-1) > 0 (signed).
  The `beq` branch at 0x3544 targets 0x3500 and is always taken.
  The return at 0x3500 has v0 = one of ?, ret(idbg_delfunc).

- `_mvpi2c_wait_for_xfer_done` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x354c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x354c-0x3584 (56 bytes).
  It occupies 56 bytes.
  The `ld` at 0x3558 loads 8 bytes from abs 0xffffffffbf330010.
  The `bgez` branch at 0x3560 targets 0x357c, is taken when a3(=([0xffffffffbf330010]:8 << 0x3b)) >= 0 (signed), and falls through when a3(=([0xffffffffbf330010]:8 << 0x3b)) < 0 (signed).
  The `bgtz` branch at 0x3568 targets 0x3558, is taken when v0(?) > 0 (signed), and falls through when v0(?) <= 0 (signed).
  The return at 0x3574 has v0 = 0x5.
  The return at 0x357c has v0 = 0x0.

- `_mvpi2c_wait_for_ack` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3584 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3584-0x360c (136 bytes).
  It occupies 136 bytes.
  3 such `ld` accesses load 8 bytes from abs 0xffffffffbf330010, including `ld` at 0x3590, `ld` at 0x35b4, `ld` at 0x3608.
  The `jal` at 0x35ec calls _mvpi2c_wait_for_xfer_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[0xffffffffbf330010]:8.
  The `beq` branch at 0x3594 targets 0x35a8, is taken when a1 == 0, and falls through when a1 != 0.
  The `bltz` branch at 0x35a0 targets 0x35ec, is taken when t8(=([0xffffffffbf330010]:8 << 0x3b)) < 0 (signed), and falls through when t8(=([0xffffffffbf330010]:8 << 0x3b)) >= 0 (signed).
  The `bgez` branch at 0x35ac targets 0x35d4, is taken when t9(=([0xffffffffbf330010]:8 << 0x3a)) >= 0 (signed), and falls through when t9(=([0xffffffffbf330010]:8 << 0x3a)) < 0 (signed).
  The `bgez` branch at 0x35bc targets 0x35e4, is taken when at(=([0xffffffffbf330010]:8 << 0x3a)) >= 0 (signed), and falls through when at(=([0xffffffffbf330010]:8 << 0x3a)) < 0 (signed).
  The `bne` branch at 0x35c4 targets 0x35b4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x35cc targets 0x35d8 and is always taken.
  The `beq` branch at 0x35e4 targets 0x35d8 and is always taken.
  The `beq` branch at 0x35f4 targets 0x3604, is taken when v0(=ret(_mvpi2c_wait_for_xfer_done)) == 0, and falls through when v0(=ret(_mvpi2c_wait_for_xfer_done)) != 0.
  The `beq` branch at 0x35fc targets 0x35d8 and is always taken.
  The `beq` branch at 0x3604 targets 0x35a8 and is always taken.
  The return at 0x35dc has v0 = one of -0x1, 0x0, 0x5.

- `_mvpi2c_force_bus_idle` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x360c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x360c-0x3688 (124 bytes).
  It occupies 124 bytes.
  3 such `ld` accesses load 8 bytes from abs 0xffffffffbf330010, including `ld` at 0x3610, `ld` at 0x3638, `ld` at 0x3664.
  2 such `sd` accesses store 8 bytes to abs 0xffffffffbf330010, including `sd` at 0x3630, `sd` at 0x3684.
  The `beq` branch at 0x3620 targets 0x3680, is taken when (at(=[0xffffffffbf330010]:8) & 0x1) == 0, and falls through when (at(=[0xffffffffbf330010]:8) & 0x1) != 0.
  The `beq` branch at 0x3640 targets 0x365c, is taken when (v1(=[0xffffffffbf330010]:8) & 0x1) == 0, and falls through when (v1(=[0xffffffffbf330010]:8) & 0x1) != 0.
  The `bne` branch at 0x364c targets 0x3638, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x365c targets 0x3654, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x3670 targets 0x3654, is taken when a0(?) == a1(=0x1), and falls through when a0(?) != a1(=0x1).
  The return at 0x3654 has v0 = 0x5.
  The return at 0x3678 has v0 = 0x0.
  The return at 0x3680 has v0 = 0x0.

- `mvpi2c_read_reg` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3688 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3688-0x3818 (400 bytes).
  It occupies 400 bytes.
  The `lh` at 0x36a4 loads 2 bytes from a0 (arg0 at entry) +0x8.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x2, including `lbu` at 0x36f8, `lbu` at 0x3718, `lbu` at 0x37c8.
  4 such `sd` accesses store 8 bytes to abs 0xffffffffbf330018, including `sd` at 0x3704, `sd` at 0x372c, `sd` at 0x375c.
  4 such `sd` accesses store 8 bytes to abs 0xffffffffbf330010, including `sd` at 0x3748, `sd` at 0x377c, `sd` at 0x37bc.
  The `lbu` at 0x3750 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `ld` at 0x37b8 loads 8 bytes from abs 0xffffffffbf330018.
  The `jal` at 0x36b4 calls _mvpi2c_force_bus_idle with a0=a0 at entry (arg0), a1=0x5, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x36d8 calls _mvpi2c_force_bus_idle with a0=a0 at entry (arg0), a1=0x5, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3700 calls _mvpi2c_wait_for_ack with a0=a0 at entry (arg0), a1=0x1, a2=[a0+2]:1, a3=0xffffffffbf330000.
  The `jal` at 0x3728 calls _mvpi2c_wait_for_ack with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?, a4=([a0+2]:1 | 0x1), a5=0xffffffffbf330000.
  The `jal` at 0x3758 calls _mvpi2c_wait_for_ack with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?, a5=[a1]:1, a6=0xffffffffbf330018.
  The `jal` at 0x3778 calls _mvpi2c_wait_for_xfer_done with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a7=0x3.
  The `jal` at 0x3790 calls _mvpi2c_force_bus_idle with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x37dc calls _mvpi2c_wait_for_ack with a0=a0 at entry (arg0), a1=0x1, a2=0xffffffffbf330018, a3=?.
  The `jal` at 0x3800 calls _mvpi2c_wait_for_xfer_done with a0=a0 at entry (arg0), a1=0xffffffffbf330010, a2=?, a3=?.
  The `beq` branch at 0x369c targets 0x36d4, is taken when a1 == at(=-0x2), and falls through when a1 != at(=-0x2).
  The `beq` branch at 0x36ac targets 0x36d4, is taken when (v1(=[a0+8]:2) & 0x2) == 0, and falls through when (v1(=[a0+8]:2) & 0x2) != 0.
  The `beq` branch at 0x36bc targets 0x36f0, is taken when v0(=ret(_mvpi2c_force_bus_idle)) == 0, and falls through when v0(=ret(_mvpi2c_force_bus_idle)) != 0.
  The `beq` branch at 0x36e0 targets 0x3718, is taken when v0(=ret(_mvpi2c_force_bus_idle)) == 0, and falls through when v0(=ret(_mvpi2c_force_bus_idle)) != 0.
  The `beq` branch at 0x36e8 targets 0x36c4 and is always taken.
  The `beq` branch at 0x3708 targets 0x3740, is taken when v0(=ret(_mvpi2c_wait_for_ack)) == 0, and falls through when v0(=ret(_mvpi2c_wait_for_ack)) != 0.
  The `beq` branch at 0x3710 targets 0x36c4 and is always taken.
  The `beq` branch at 0x3730 targets 0x3770, is taken when v0(=ret(_mvpi2c_wait_for_ack)) == 0, and falls through when v0(=ret(_mvpi2c_wait_for_ack)) != 0.
  The `beq` branch at 0x3738 targets 0x36c4 and is always taken.
  The `beq` branch at 0x3760 targets 0x3790, is taken when v0(=ret(_mvpi2c_wait_for_ack)) == 0, and falls through when v0(=ret(_mvpi2c_wait_for_ack)) != 0.
  The `beq` branch at 0x3768 targets 0x36c4 and is always taken.
  The `beq` branch at 0x3780 targets 0x37a8, is taken when v0(=ret(_mvpi2c_wait_for_xfer_done)) == 0, and falls through when v0(=ret(_mvpi2c_wait_for_xfer_done)) != 0.
  The `beq` branch at 0x3788 targets 0x36c8 and is always taken.
  The `beq` branch at 0x3798 targets 0x37c8, is taken when v0(=ret(_mvpi2c_force_bus_idle)) == 0, and falls through when v0(=ret(_mvpi2c_force_bus_idle)) != 0.
  The `beq` branch at 0x37a0 targets 0x36c4 and is always taken.
  The `beq` branch at 0x37c0 targets 0x36c4 and is always taken.
  The `beq` branch at 0x37e4 targets 0x37f4, is taken when v0(=ret(_mvpi2c_wait_for_ack)) == 0, and falls through when v0(=ret(_mvpi2c_wait_for_ack)) != 0.
  The `beq` branch at 0x37ec targets 0x36c4 and is always taken.
  The `beq` branch at 0x3808 targets 0x37a8, is taken when v0(=ret(_mvpi2c_wait_for_xfer_done)) == 0, and falls through when v0(=ret(_mvpi2c_wait_for_xfer_done)) != 0.
  The `beq` branch at 0x3810 targets 0x36c8 and is always taken.
  The return at 0x36cc has v0 = one of ?, ret(_mvpi2c_wait_for_xfer_done).

- `mvp_i2c_reg` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3818 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3818-0x3878 (96 bytes).
  It occupies 96 bytes.
  The `lbu` at 0x3818 loads 1 byte from a0 (arg0 at entry) +0x3.
  The `lw` at 0x381c loads 4 bytes from a0 (arg0 at entry) +0xc.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x382c, `lbu` at 0x384c.
  The `lbu` at 0x3838 loads 1 byte from a0 (arg0 at entry) +0x4.
  The `beq` branch at 0x3830 targets 0x3870, is taken when a1 == at(?), and falls through when a1 != at(?).
  The `bne` branch at 0x3840 targets 0x3864, is taken when a5(=[a0+4]:1) < a4(=[a0+3]:1) (signed), and falls through when a5(=[a0+4]:1) >= a4(=[a0+3]:1) (signed).
  The `beq` branch at 0x3854 targets 0x3868, is taken when a1 == a7(?), and falls through when a1 != a7(?).
  The `beq` branch at 0x385c targets 0x3848, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The return at 0x3868 has v0 = one of ?, 0x0.
  The return at 0x3870 has v0 = ?.

- `a3_mvp_probe` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x3878 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x3878-0x38e0 (104 bytes).
  It occupies 104 bytes.
  The `lh` at 0x3878 loads 2 bytes from a0 (arg0 at entry) +0x6.
  The `jal` at 0x3894 calls mvp_i2c_reg with a0=a0 at entry (arg0), a1=[a0+6]:2, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x38a0 calls mvpi2c_read_reg with a0=a0 at entry (arg0), a1=ret(mvp_i2c_reg), a2=?, a3=?.
  The `jal` at 0x38c8 calls mvpi2c_read_reg with a0=a0 at entry (arg0), a1=-0x2, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x388c targets 0x38c8, is taken when a1(=[a0+6]:2) == at(=-0x2), and falls through when a1(=[a0+6]:2) != at(=-0x2).
  The `beq` branch at 0x38d8 targets 0x38b4 and is always taken.
  The return at 0x38c0 has v0 = ?.

- `a3_check_for_video` in `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o` at 0x38e0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/a3_dd.o`.
  Range: 0x38e0-0x3928 (72 bytes).
  It occupies 72 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1e8, including `sw` at 0x38e4, `sw` at 0x3924.
  The `lw` at 0x390c loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `jal` at 0x38fc calls a3_mvp_probe with a0=sym(.data)+7640, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x3904 targets 0x391c, is taken when v0(=ret(a3_mvp_probe)) == 0, and falls through when v0(=ret(a3_mvp_probe)) != 0.
  The `beq` branch at 0x3920 targets 0x3910 and is always taken.
  The return at 0x3914 has v0 = one of [a0+488], 0x0.
