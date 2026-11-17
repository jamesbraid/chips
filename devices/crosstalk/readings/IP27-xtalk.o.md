# Readings: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`

One entry per routine, filed here from the reading batches by binary.

- `xtalk_piomap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x0-0x1c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x8 calls hub_piomap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14 has v0 = ret(hub_piomap_alloc).

- `xtalk_piomap_free` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x1c-0x38 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x24 calls hub_piomap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x30 has v0 = ret(hub_piomap_free).

- `xtalk_piomap_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x38-0x54 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x40 calls hub_piomap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4c has v0 = ret(hub_piomap_addr).

- `xtalk_piomap_done` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x54-0x70 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x5c calls hub_piomap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x68 has v0 = ret(hub_piomap_done).

- `xtalk_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x70-0x8c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x78 calls hub_piotrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x84 has v0 = ret(hub_piotrans_addr).

- `xtalk_pio_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x8c-0x184 (248 bytes).
  It occupies 248 bytes.
  2 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0xc8, `sd` at 0x164.
  The `jal` at 0xe0 calls xtalk_piotrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a5 at entry (arg5).
  The `jal` at 0x12c calls xtalk_piomap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a3 at entry (arg3).
  The `jal` at 0x14c calls xtalk_piomap_addr with a0=ret(xtalk_piomap_alloc), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x174 calls xtalk_piomap_free with a0=ret(xtalk_piomap_alloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0xc0 targets 0xcc, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xe8 targets 0x118, is taken when v0(=ret(xtalk_piotrans_addr)) == 0, and falls through when v0(=ret(xtalk_piotrans_addr)) != 0.
  The `bne` branch at 0x134 targets 0x144, is taken when v0(=ret(xtalk_piomap_alloc)) != 0, and falls through when v0(=ret(xtalk_piomap_alloc)) == 0.
  The `beq` branch at 0x13c targets 0xf0 and is always taken.
  The `beq` branch at 0x154 targets 0x174, is taken when v0(=ret(xtalk_piomap_addr)) == 0, and falls through when v0(=ret(xtalk_piomap_addr)) != 0.
  The `beq` branch at 0x15c targets 0x16c, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0x16c targets 0xf4 and is always taken.
  The `beq` branch at 0x17c targets 0xf0 and is always taken.
  The return at 0x110 has v0 = one of ?, ret(xtalk_piomap_addr).

- `xtalk_set_early_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x184 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x184-0x18c (8 bytes).
  It occupies 8 bytes.
  The return at 0x184 has v0 = ?.

- `xtalk_early_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x18c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x18c-0x1ac (32 bytes).
  It occupies 32 bytes.
  The `jalr` at 0x198 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1a4 has v0 = ret(?).

- `null_xtalk_early_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x1ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x1ac-0x1b4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1ac has v0 = 0x0.

- `xtalk_dmamap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x1b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x1b4-0x1d0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1bc calls hub_dmamap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1c8 has v0 = ret(hub_dmamap_alloc).

- `xtalk_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x1d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x1d0-0x1ec (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1d8 calls hub_dmamap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1e4 has v0 = ret(hub_dmamap_free).

- `xtalk_dmamap_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x1ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x1ec-0x208 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1f4 calls hub_dmamap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x200 has v0 = ret(hub_dmamap_addr).

- `xtalk_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x208 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x208-0x224 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x210 calls hub_dmamap_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x21c has v0 = ret(hub_dmamap_list).

- `xtalk_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x224 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x224-0x240 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x22c calls hub_dmamap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x238 has v0 = ret(hub_dmamap_done).

- `xtalk_dmatrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x240 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x240-0x25c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x248 calls hub_dmatrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x254 has v0 = ret(hub_dmatrans_addr).

- `xtalk_dmatrans_list` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x25c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x25c-0x278 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x264 calls hub_dmatrans_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x270 has v0 = ret(hub_dmatrans_list).

- `xtalk_dmamap_drain` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x278 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x278-0x294 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x280 calls hub_dmamap_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x28c has v0 = ret(hub_dmamap_drain).

- `xtalk_dmaaddr_drain` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x294 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x294-0x2b0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x29c calls hub_dmaaddr_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2a8 has v0 = ret(hub_dmaaddr_drain).

- `xtalk_dmalist_drain` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x2b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x2b0-0x2cc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2b8 calls hub_dmalist_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2c4 has v0 = ret(hub_dmalist_drain).

- `xtalk_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x2cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x2cc-0x2e8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2d4 calls hub_intr_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2e0 has v0 = ret(hub_intr_alloc).

- `xtalk_intr_alloc_nothd` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x2e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x2e8-0x304 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2f0 calls hub_intr_alloc_nothd with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2fc has v0 = ret(hub_intr_alloc_nothd).

- `xtalk_intr_free` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x304 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x304-0x320 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x30c calls hub_intr_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x318 has v0 = ret(hub_intr_free).

- `xtalk_intr_connect` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x320 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x320-0x33c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x328 calls hub_intr_connect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x334 has v0 = ret(hub_intr_connect).

- `xtalk_intr_disconnect` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x33c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x33c-0x358 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x344 calls hub_intr_disconnect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x350 has v0 = ret(hub_intr_disconnect).

- `xtalk_intr_cpu_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x358 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x358-0x374 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x360 calls hub_intr_cpu_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x36c has v0 = ret(hub_intr_cpu_get).

- `xtalk_intr_cpuid_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x374 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x374-0x390 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x37c calls hub_intr_cpuid_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x388 has v0 = ret(hub_intr_cpuid_get).

- `xtalk_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x390 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x390-0x43c (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0x3b8 loads 8 bytes from ret(xwidget_info_get) +0x28.
  The `ld` at 0x3c4 loads 8 bytes from ret(xwidget_info_get) +0x30.
  The `jal` at 0x3a8 calls xwidget_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3d0 calls (unknown callee) with a0=[ret(xwidget_info_get)+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x3, a6=[ret(xwidget_info_get)+40]:8.
  The `jal` at 0x414 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?, a5=0x3.
  The `jal` at 0x42c calls ioerror_dump with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x3b0 targets 0x3e0, is taken when v0(=ret(xwidget_info_get)) == 0, and falls through when v0(=ret(xwidget_info_get)) != 0.
  The `beq` branch at 0x3bc targets 0x3e0, is taken when a6(=[ret(xwidget_info_get)+40]:8) == 0, and falls through when a6(=[ret(xwidget_info_get)+40]:8) != 0.
  The `beq` branch at 0x3d8 targets 0x3f8 and is always taken.
  The `beq` branch at 0x3e0 targets 0x3f4, is taken when s0(=a2) == 0, and falls through when s0(=a2) != 0.
  The `beq` branch at 0x3e8 targets 0x3f8, is taken when s0(=a2) == at(=0x2), and falls through when s0(=a2) != at(=0x2).
  The `bne` branch at 0x3f0 targets 0x40c, is taken when s0(=a2) != a5(=0x3), and falls through when s0(=a2) == a5(=0x3).
  The `beq` branch at 0x434 targets 0x3f8 and is always taken.
  The return at 0x404 has v0 = one of ret(?), 0x0, 0x9.

- `xtalk_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x43c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x43c-0x458 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x444 calls hub_error_devenable with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x450 has v0 = ret(hub_error_devenable).

- `xtalk_provider_startup` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x458 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x458-0x474 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x460 calls hub_provider_startup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x46c has v0 = ret(hub_provider_startup).

- `xtalk_provider_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x474 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x474-0x490 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x47c calls hub_provider_shutdown with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x488 has v0 = ret(hub_provider_shutdown).

- `xtalk_widgetdev_enable` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x490 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x490-0x4ac (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x498 calls hub_widgetdev_enable with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4a4 has v0 = ret(hub_widgetdev_enable).

- `xtalk_widgetdev_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x4ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x4ac-0x4c8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4b4 calls hub_widgetdev_shutdown with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4c0 has v0 = ret(hub_widgetdev_shutdown).

- `xtalk_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x4c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x4c8-0x4e4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4d0 calls hub_dma_enabled with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4dc has v0 = ret(hub_dma_enabled).

- `xtalk_intr_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x4e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x4e4-0x4ec (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0x4e8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0x4e4 has v0 = [a0].

- `xtalk_intr_target_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x4ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x4ec-0x4f4 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0x4f0 loads 1 byte from a0 (arg0 at entry) +0x4.
  The return at 0x4ec has v0 = [a0+4]:1.

- `xtalk_intr_vector_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x4f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x4f4-0x4fc (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0x4f8 loads 1 byte from a0 (arg0 at entry) +0x5.
  The return at 0x4f4 has v0 = [a0+5]:1.

- `xtalk_intr_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x4fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x4fc-0x504 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x500 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The return at 0x4fc has v0 = [a0+8]:8.

- `xtalk_intr_sfarg_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x504 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x504-0x50c (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x508 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0x504 has v0 = [a0+16]:8.

- `xtalk_pio_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x50c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x50c-0x514 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0x510 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0x50c has v0 = [a0].

- `xtalk_pio_target_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x514 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x514-0x51c (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0x518 loads 1 byte from a0 (arg0 at entry) +0x4.
  The return at 0x514 has v0 = [a0+4]:1.

- `xtalk_pio_xtalk_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x51c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x51c-0x524 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x520 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The return at 0x51c has v0 = [a0+8]:8.

- `xtalk_pio_mapsz_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x524 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x524-0x52c (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x528 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0x524 has v0 = [a0+16]:8.

- `xtalk_pio_kvaddr_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x52c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x52c-0x534 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x530 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The return at 0x52c has v0 = [a0+24]:8.

- `xtalk_dma_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x534 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x534-0x53c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0x538 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0x534 has v0 = [a0].

- `xtalk_dma_target_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x53c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x53c-0x544 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0x540 loads 1 byte from a0 (arg0 at entry) +0x4.
  The return at 0x53c has v0 = [a0+4]:1.

- `xtalk_init` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x78c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x78c-0x7e4 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x7a8 calls cdl_new with a0=sym(.rodata), a1=sym(.rodata), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0x7bc calls compare_and_swap_ptr with a0=sym(xtalk_registry), a1=0x0, a2=ret(cdl_new), a3=?.
  The `jal` at 0x7d4 calls cdl_del with a0=ret(cdl_new), a1=?, a2=?, a3=?.
  The `bne` branch at 0x794 targets 0x7c8, is taken when at(=[sym(xtalk_registry)]:8) != 0, and falls through when at(=[sym(xtalk_registry)]:8) == 0.
  The `beq` branch at 0x7c4 targets 0x7d4, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7dc targets 0x7cc and is always taken.
  The return at 0x7cc has v0 = one of ret(compare_and_swap_ptr), ?, ret(cdl_del).

- `xtalk_provider_register` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x7e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x7e4-0x800 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7ec calls hwgraph_fastinfo_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7f8 has v0 = ret(hwgraph_fastinfo_set).

- `xtalk_provider_unregister` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x800 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x800-0x81c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x808 calls hwgraph_fastinfo_set with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x814 has v0 = ret(hwgraph_fastinfo_set).

- `xtalk_provider_fns_get` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x81c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x81c-0x838 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x824 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x830 has v0 = ret(hwgraph_fastinfo_get).

- `xtalk_iterate` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0x8d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0x8d0-0x8f8 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x8e4 calls cdl_iterate with a0=[sym(xtalk_registry)]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0x8f0 has v0 = ret(cdl_iterate).

- `xtalk_device_powerup` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0xbc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0xbc4-0xc04 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0xbd4 calls hwgraph_connectpt_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbe8 calls io_xswitch_widget_init with a0=a0 at entry (arg0), a1=ret(hwgraph_connectpt_get), a2=a1 at entry (arg1), a3=0x0.
  The return at 0xbfc has v0 = 0x0.

- `xtalk_device_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0xc04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0xc04-0xc60 (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0xc20 calls sprintf with a0=sp-32, a1=sym(.rodata), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0xc30 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-32, a2=sp-24, a3=?.
  The `jal` at 0xc50 calls xwidget_unregister with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xc38 targets 0xc50, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xc58 targets 0xc44 and is always taken.
  The return at 0xc48 has v0 = one of 0x0, 0x1.

- `xtalk_device_inquiry` in `IP27/usr/cpu/sysgen/IP27boot/xtalk.o` at 0xc60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xtalk.o`.
  Range: 0xc60-0xc80 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xc68 calls hub_device_inquiry with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xc78 has v0 = 0x0.
