# Readings: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`

One entry per routine, filed here from the reading batches by binary.

- `pciio_piomap_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x0-0x1c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x8 calls pcimh_piomap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14 has v0 = ret(pcimh_piomap_alloc).

- `pciio_piomap_free` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1c-0x38 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x24 calls pcimh_piomap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x30 has v0 = ret(pcimh_piomap_free).

- `pciio_piomap_addr` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x38 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x38-0x60 (40 bytes).
  It occupies 40 bytes.
  The `sw` at 0x50 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `jal` at 0x44 calls pcimh_piomap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x58 has v0 = ret(pcimh_piomap_addr).

- `pciio_piomap_done` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x60 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x60-0x7c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x68 calls pcimh_piomap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x74 has v0 = ret(pcimh_piomap_done).

- `pciio_piotrans_addr` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x7c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x7c-0x98 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x84 calls pcimh_piotrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x90 has v0 = ret(pcimh_piotrans_addr).

- `pciio_pio_addr` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x98 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x98-0x1c4 (300 bytes).
  It occupies 300 bytes.
  The `lw` at 0xe4 loads 4 bytes from a5 (arg5 at entry) +0x0.
  2 such `sw` accesses store 4 bytes to a5 (arg5 at entry) +0x0, including `sw` at 0xe8, `sw` at 0x154.
  The `jal` at 0x100 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a6 at entry (arg6).
  The `jal` at 0x124 calls pciio_piomap_addr with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0x13c calls pciio_piomap_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a0 calls pciio_piomap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a4 at entry (arg4).
  The `beq` branch at 0xdc targets 0xec, is taken when a5 == 0, and falls through when a5 != 0.
  The `bne` branch at 0x108 targets 0x15c, is taken when v0(=ret(pciio_piotrans_addr)) != 0, and falls through when v0(=ret(pciio_piotrans_addr)) == 0.
  The `beq` branch at 0x110 targets 0x188, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x12c targets 0x14c, is taken when v0(=ret(pciio_piomap_addr)) != 0, and falls through when v0(=ret(pciio_piomap_addr)) == 0.
  The `beq` branch at 0x134 targets 0x144, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x144 targets 0x15c and is always taken.
  The `beq` branch at 0x14c targets 0x15c, is taken when s3(=a5) == 0, and falls through when s3(=a5) != 0.
  The `beq` branch at 0x1ac targets 0x1bc, is taken when v0(=ret(pciio_piomap_alloc)) == 0, and falls through when v0(=ret(pciio_piomap_alloc)) != 0.
  The `beq` branch at 0x1b4 targets 0x120 and is always taken.
  The `beq` branch at 0x1bc targets 0x15c and is always taken.
  The return at 0x180 has v0 = one of ret(pciio_piotrans_addr), ret(pciio_piomap_addr).

- `pciio_piospace_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1c4-0x1ec (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x1d8 calls pcimh_piospace_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1cc targets 0x1d8, is taken when a4 >= 0x1000 (unsigned), and falls through when a4 < 0x1000 (unsigned).
  The return at 0x1e4 has v0 = ret(pcimh_piospace_alloc).

- `pciio_piospace_free` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1ec-0x208 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1f4 calls pcimh_piospace_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x200 has v0 = ret(pcimh_piospace_free).

- `pciio_pio_flush_read` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x208 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x208-0x224 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x210 calls pcimh_pio_flush_read with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x21c has v0 = ret(pcimh_pio_flush_read).

- `pciio_pio_flush_del` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x224 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x224-0x240 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x22c calls pcimh_pio_flush_del with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x238 has v0 = ret(pcimh_pio_flush_del).

- `pciio_pio_flush_init` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x240 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x240-0x25c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x248 calls pcimh_pio_flush_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x254 has v0 = ret(pcimh_pio_flush_init).

- `pciio_dmamap_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x25c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x25c-0x278 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x264 calls pcimh_dmamap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x270 has v0 = ret(pcimh_dmamap_alloc).

- `pciio_dmamap_free` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x278 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x278-0x294 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x280 calls pcimh_dmamap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x28c has v0 = ret(pcimh_dmamap_free).

- `pciio_dmamap_addr` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x294 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x294-0x2b0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x29c calls pcimh_dmamap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2a8 has v0 = ret(pcimh_dmamap_addr).

- `pciio_dmamap_list` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x2b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x2b0-0x2cc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2b8 calls pcimh_dmamap_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2c4 has v0 = ret(pcimh_dmamap_list).

- `pciio_dmamap_done` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x2cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x2cc-0x2e8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2d4 calls pcimh_dmamap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2e0 has v0 = ret(pcimh_dmamap_done).

- `pciio_dmatrans_addr` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x2e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x2e8-0x304 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2f0 calls pcimh_dmatrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2fc has v0 = ret(pcimh_dmatrans_addr).

- `pciio_dmatrans_list` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x304 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x304-0x320 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x30c calls pcimh_dmatrans_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x318 has v0 = ret(pcimh_dmatrans_list).

- `pciio_dma_addr` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x320 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x320-0x43c (284 bytes).
  It occupies 284 bytes.
  The `lw` at 0x360 loads 4 bytes from a4 (arg4 at entry) +0x0.
  2 such `sw` accesses store 4 bytes to a4 (arg4 at entry) +0x0, including `sw` at 0x368, `sw` at 0x3ec.
  The `jal` at 0x384 calls pciio_dmatrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a5 at entry (arg5).
  The `jal` at 0x3d4 calls pciio_dmamap_addr with a0=?, a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x404 calls pciio_dmamap_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x41c calls pciio_dmamap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a5 at entry (arg5).
  The `beq` branch at 0x358 targets 0x36c, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x364 targets 0x370 and is always taken.
  The `beq` branch at 0x38c targets 0x3c0, is taken when v0(=ret(pciio_dmatrans_addr)) == 0, and falls through when v0(=ret(pciio_dmatrans_addr)) != 0.
  The `beq` branch at 0x3c0 targets 0x414, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3dc targets 0x3fc, is taken when v0(=ret(pciio_dmamap_addr)) == 0, and falls through when v0(=ret(pciio_dmamap_addr)) != 0.
  The `beq` branch at 0x3e4 targets 0x3f4, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0x3f4 targets 0x398 and is always taken.
  The `beq` branch at 0x3fc targets 0x40c, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x40c targets 0x394 and is always taken.
  The `beq` branch at 0x424 targets 0x434, is taken when v0(=ret(pciio_dmamap_alloc)) == 0, and falls through when v0(=ret(pciio_dmamap_alloc)) != 0.
  The `beq` branch at 0x42c targets 0x3cc and is always taken.
  The `beq` branch at 0x434 targets 0x394 and is always taken.
  The return at 0x3b8 has v0 = one of ?, ret(pciio_dmamap_addr).

- `pciio_dmamap_drain` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x43c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x43c-0x458 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x444 calls pcimh_dmamap_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x450 has v0 = ret(pcimh_dmamap_drain).

- `pciio_dmaaddr_drain` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x458 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x458-0x474 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x460 calls pcimh_dmaaddr_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x46c has v0 = ret(pcimh_dmaaddr_drain).

- `pciio_dmalist_drain` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x474 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x474-0x490 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x47c calls pcimh_dmalist_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x488 has v0 = ret(pcimh_dmalist_drain).

- `pciio_intr_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x490 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x490-0x4f8 (104 bytes).
  It occupies 104 bytes.
  The `lw` at 0x4b4 loads 4 bytes from ret(pciio_info_get) +0x8.
  The `lw` at 0x4b8 loads 4 bytes from ret(pciio_info_get) +0x4.
  The `jal` at 0x4ac calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4c4 calls pciio_ppb_intr_map with a0=ret(pciio_info_get), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x4dc calls pcimh_intr_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `beq` branch at 0x4bc targets 0x4d0, is taken when at(=[ret(pciio_info_get)+4]) == v1(=[ret(pciio_info_get)+8]), and falls through when at(=[ret(pciio_info_get)+4]) != v1(=[ret(pciio_info_get)+8]).
  The return at 0x4f0 has v0 = ret(pcimh_intr_alloc).

- `pciio_intr_free` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x4f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x4f8-0x514 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x500 calls pcimh_intr_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x50c has v0 = ret(pcimh_intr_free).

- `pciio_intr_setmustrun` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x514 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x514-0x530 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x51c calls pcimh_intr_setmustrun with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x528 has v0 = ret(pcimh_intr_setmustrun).

- `pciio_intr_connect` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x530 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x530-0x54c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x538 calls pcimh_intr_connect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x544 has v0 = ret(pcimh_intr_connect).

- `pciio_intr_disconnect` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x54c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x54c-0x568 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x554 calls pcimh_intr_disconnect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x560 has v0 = ret(pcimh_intr_disconnect).

- `pciio_intr_cpu_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x568 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x568-0x584 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x570 calls pcimh_intr_cpu_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x57c has v0 = ret(pcimh_intr_cpu_get).

- `pciio_slot_func_to_name` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x584 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x584-0x5ec (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0x5ac calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+16, a2=a1 at entry (arg1), a3=a2+97, a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `jal` at 0x5c8 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+8, a2=a1 at entry (arg1), a3=a2+97, a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `jal` at 0x5dc calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `beq` branch at 0x594 targets 0x5d8, is taken when a4(=0xff) == a1, and falls through when a4(=0xff) != a1.
  The `beq` branch at 0x59c targets 0x5c0, is taken when a4(=0xff) == a2, and falls through when a4(=0xff) != a2.
  The `beq` branch at 0x5d0 targets 0x5b8 and is always taken.
  The `beq` branch at 0x5e4 targets 0x5b8 and is always taken.
  The return at 0x5b8 has v0 = ret(sprintf).

- `pciio_cardinfo_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x5ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x5ec-0x68c (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x604 calls pciio_slot_func_to_name with a0=sp-64, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x614 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-64, a2=sp-48, a3=?.
  The `jal` at 0x64c calls pciio_info_chk with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x658 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x66c calls pciio_slot_func_to_name with a0=sp-64, a1=a1 at entry (arg1), a2=0xff, a3=?.
  The `jal` at 0x67c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-64, a2=sp-48, a3=?.
  The `beq` branch at 0x620 targets 0x630, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x628 targets 0x668, is taken when at(=a2) == 0, and falls through when at(=a2) != 0.
  The `beq` branch at 0x630 targets 0x64c, is taken when a0(=ret(hwgraph_traverse)) == 0, and falls through when a0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x660 targets 0x63c and is always taken.
  The `beq` branch at 0x684 targets 0x630 and is always taken.
  The return at 0x644 has v0 = one of 0x0, ret(pciio_info_chk).

- `pciio_error_handler` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x68c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x68c-0x7b0 (292 bytes).
  It occupies 292 bytes.
  4 such `lw` accesses load 4 bytes from ret(pciio_cardinfo_get) +0x28, including `lw` at 0x6c4, `lw` at 0x708, `lw` at 0x768.
  The `lw` at 0x6d0 loads 4 bytes from a3 (arg3 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from ret(pciio_cardinfo_get) +0x2c, including `lw` at 0x71c, `lw` at 0x798.
  The `lh` at 0x740 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0x6b4 calls pciio_cardinfo_get with a0=a0 at entry (arg0), a1=0xff, a2=0xff, a3=a3 at entry (arg3).
  The `jal` at 0x700 calls pciio_info_dev_get with a0=ret(pciio_cardinfo_get), a1=?, a2=?, a3=?.
  The `jalr` at 0x718 calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+44], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x758 calls pciio_cardinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x778 calls pciio_info_dev_get with a0=ret(pciio_cardinfo_get), a1=?, a2=[ret(pciio_cardinfo_get)+40], a3=?.
  The `jalr` at 0x794 calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+44], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[ret(pciio_cardinfo_get)+40].
  The `beq` branch at 0x6bc targets 0x6d0, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `bne` branch at 0x6c8 targets 0x700, is taken when at(=[ret(pciio_cardinfo_get)+40]) != 0, and falls through when at(=[ret(pciio_cardinfo_get)+40]) == 0.
  The `bltz` branch at 0x6d8 targets 0x740, is taken when v0(=([a3] << 0x2)) < 0 (signed), and falls through when v0(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0x6e0 targets 0x734, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x724 targets 0x6d0, is taken when v0(=ret(?)) == a0(=0x9), and falls through when v0(=ret(?)) != a0(=0x9).
  The `beq` branch at 0x72c targets 0x6ec and is always taken.
  The `beq` branch at 0x738 targets 0x6e8 and is always taken.
  The `beq` branch at 0x760 targets 0x6e0, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `beq` branch at 0x76c targets 0x6e0, is taken when a2(=[ret(pciio_cardinfo_get)+40]) == 0, and falls through when a2(=[ret(pciio_cardinfo_get)+40]) != 0.
  The `beq` branch at 0x7a0 targets 0x6e0, is taken when v0(=ret(?)) == a5(=0x9), and falls through when v0(=ret(?)) != a5(=0x9).
  The `beq` branch at 0x7a8 targets 0x6ec and is always taken.
  The return at 0x6f8 has v0 = one of 0x0, 0x9, ret(?).

- `pciio_error_devenable` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x7b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x7b0-0x7cc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7b8 calls pcimh_error_devenable with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7c4 has v0 = ret(pcimh_error_devenable).

- `pciio_provider_startup` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x7cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x7cc-0x7e8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7d4 calls pcimh_provider_startup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7e0 has v0 = ret(pcimh_provider_startup).

- `pciio_provider_shutdown` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x7e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x7e8-0x804 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7f0 calls pcimh_provider_shutdown with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7fc has v0 = ret(pcimh_provider_shutdown).

- `pciio_endian_set` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x804 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x804-0x820 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x80c calls pcimh_endian_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x818 has v0 = ret(pcimh_endian_set).

- `pciio_priority_set` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x820 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x820-0x83c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x828 calls pcimh_priority_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x834 has v0 = ret(pcimh_priority_set).

- `pciio_config_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x83c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x83c-0x904 (200 bytes).
  It occupies 200 bytes.
  The `jal` at 0x8a4 calls pcimh_config_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x874 targets 0x8d8, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x890 targets 0x8a0, is taken when s1(?) >= s2(?) (unsigned), and falls through when s1(?) < s2(?) (unsigned).
  The `bne` branch at 0x8d0 targets 0x88c, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0x8fc has v0 = one of 0x0, ?.

- `pciio_config_get_safe` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x904 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x904-0x9cc (200 bytes).
  It occupies 200 bytes.
  The `jal` at 0x96c calls pcimh_config_get_safe with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x93c targets 0x9a0, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x958 targets 0x968, is taken when s1(?) >= s2(?) (unsigned), and falls through when s1(?) < s2(?) (unsigned).
  The `bne` branch at 0x998 targets 0x954, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0x9c4 has v0 = one of 0x0, ?.

- `pciio_config_set` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x9cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x9cc-0xa74 (168 bytes).
  It occupies 168 bytes.
  The `jal` at 0xa2c calls pcimh_config_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa00 targets 0xa50, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xa14 targets 0xa24, is taken when s1(?) >= s2(?) (unsigned), and falls through when s1(?) < s2(?) (unsigned).
  The `bne` branch at 0xa48 targets 0xa10, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0xa6c has v0 = one of ?, ret(pcimh_config_set).

- `pciio_error_extract` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xa74 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xa74-0xa90 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa7c calls pcimh_error_extract with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa88 has v0 = ret(pcimh_error_extract).

- `pciio_reset` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xa90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xa90-0xaac (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa98 calls pcimh_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xaa4 has v0 = ret(pcimh_reset).

- `pciio_write_gather_flush` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xaac (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xaac-0xac8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xab4 calls pcimh_write_gather_flush with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xac0 has v0 = ret(pcimh_write_gather_flush).

- `pciio_intr_dev_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xac8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xac8-0xad0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xacc loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xac8 has v0 = [a0+4].

- `pciio_pio_dev_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xad0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xad0-0xad8 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xad4 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xad0 has v0 = [a0+4].

- `pciio_pio_slot_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xad8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xad8-0xae0 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xadc loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xad8 has v0 = [a0+8]:1.

- `pciio_pio_space_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xae0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xae0-0xae8 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xae4 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xae0 has v0 = [a0+12].

- `pciio_pio_pciaddr_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xae8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xae8-0xaf0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xaec loads 4 bytes from a0 (arg0 at entry) +0x10.
  The return at 0xae8 has v0 = [a0+16].

- `pciio_pio_mapsz_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xaf0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xaf0-0xaf8 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xaf4 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The return at 0xaf0 has v0 = [a0+20].

- `pciio_pio_kvaddr_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xaf8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xaf8-0xb00 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xafc loads 4 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xaf8 has v0 = [a0+24].

- `pciio_dma_dev_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xb00 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xb00-0xb08 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xb04 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xb00 has v0 = [a0+4].

- `pciio_dma_slot_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xb08 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xb08-0xb10 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xb0c loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xb08 has v0 = [a0+8]:1.

- `pciio_info_chk` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xb10 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xb10-0xb3c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xb24 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+24, a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xb34 has v0 = ?.

- `pciio_info_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xb3c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xb3c-0xb98 (92 bytes).
  It occupies 92 bytes.
  The `lw` at 0xb58 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `jal` at 0xb48 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb88 calls cmn_err with a0=0x0, a1=sym(.rodata)+32, a2=a0 at entry (arg0), a3=?.
  The `beq` branch at 0xb50 targets 0xb68, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xb64 targets 0xb7c, is taken when at(=[ret(hwgraph_fastinfo_get)]) != v0(=sym(pciio_info_fingerprint)), and falls through when at(=[ret(hwgraph_fastinfo_get)]) == v0(=sym(pciio_info_fingerprint)).
  The `beq` branch at 0xb90 targets 0xb6c and is always taken.
  The return at 0xb74 has v0 = ret(hwgraph_fastinfo_get).

- `pciio_hostinfo_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xb98 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xb98-0xbdc (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xbb0 loads 4 bytes from ret(pciio_info_get) +0x8.
  The `lw` at 0xbb4 loads 4 bytes from ret(pciio_info_get) +0x4.
  The `jal` at 0xba0 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbcc calls pciio_info_get with a0=[ret(pciio_info_get)+8], a1=?, a2=?, a3=ret(pciio_info_get).
  The `beq` branch at 0xba8 targets 0xbbc, is taken when v0(=ret(pciio_info_get)) == 0, and falls through when v0(=ret(pciio_info_get)) != 0.
  The `bne` branch at 0xbb8 targets 0xbcc, is taken when at(=[ret(pciio_info_get)+4]) != a0(=[ret(pciio_info_get)+8]), and falls through when at(=[ret(pciio_info_get)+4]) == a0(=[ret(pciio_info_get)+8]).
  The `beq` branch at 0xbd4 targets 0xbbc and is always taken.
  The return at 0xbc4 has v0 = ret(pciio_info_get).

- `pciio_info_set` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xbdc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xbdc-0xc38 (92 bytes).
  It occupies 92 bytes.
  The `sw` at 0xc00 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0xc08 calls hwgraph_fastinfo_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sym(pciio_info_fingerprint), a3=a3 at entry (arg3).
  The `jal` at 0xc1c calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+24, a2=a1 at entry (arg1), a3=?.
  The `beq` branch at 0xbf4 targets 0xc04, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0xc30 has v0 = ret(hwgraph_info_add_LBL).

- `pciio_info_dev_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc38 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc38-0xc40 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc3c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xc38 has v0 = [a0+4].

- `pciio_info_hostdev_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc40 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc40-0xc48 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc44 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xc40 has v0 = [a0+8].

- `pciio_info_bus_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc48 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc48-0xc50 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc4c loads 1 byte from a0 (arg0 at entry) +0xc.
  The return at 0xc48 has v0 = [a0+12]:1.

- `pciio_info_slot_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc50 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc50-0xc58 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc54 loads 1 byte from a0 (arg0 at entry) +0xd.
  The return at 0xc50 has v0 = [a0+13]:1.

- `pciio_info_hostslot_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc58 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc58-0xc84 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xc60 calls pciio_info_hostdev_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc68 calls pciio_info_get with a0=ret(pciio_info_hostdev_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc70 calls pciio_info_slot_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The return at 0xc7c has v0 = ret(pciio_info_slot_get).

- `pciio_info_function_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc84 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc84-0xc8c (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc88 loads 1 byte from a0 (arg0 at entry) +0xe.
  The return at 0xc84 has v0 = [a0+14]:1.

- `pciio_info_vendor_id_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc8c-0xc94 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc90 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The return at 0xc8c has v0 = [a0+16].

- `pciio_info_device_id_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc94 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc94-0xc9c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc98 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The return at 0xc94 has v0 = [a0+20].

- `pciio_info_master_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xc9c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xc9c-0xca4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xca0 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xc9c has v0 = [a0+24].

- `pciio_info_mfast_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xca4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xca4-0xcac (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xca8 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The return at 0xca4 has v0 = [a0+32].

- `pciio_info_pops_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xcac (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xcac-0xcb4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcb0 loads 4 bytes from a0 (arg0 at entry) +0x24.
  The return at 0xcac has v0 = [a0+36].

- `pciio_info_efunc_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xcb4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xcb4-0xcbc (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcb8 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The return at 0xcb4 has v0 = [a0+40].

- `pciio_info_einfo_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xcbc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xcbc-0xcc4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcc0 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The return at 0xcbc has v0 = [a0+44].

- `pciio_info_bar_space_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xcc4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xcc4-0xcd4 (16 bytes).
  It occupies 16 bytes.
  The `lw` at 0xcd0 loads 4 bytes from (a0 + (a1 << 0x5)) +0x30.
  The return at 0xccc has v0 = [(a0 + (a1 << 0x5))+48].

- `pciio_info_bar_base_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xcd4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xcd4-0xce4 (16 bytes).
  It occupies 16 bytes.
  The `lw` at 0xce0 loads 4 bytes from (a0 + (a1 << 0x5)) +0x38.
  The return at 0xcdc has v0 = [(a0 + (a1 << 0x5))+56].

- `pciio_info_bar_size_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xce4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xce4-0xcf4 (16 bytes).
  It occupies 16 bytes.
  The `lw` at 0xcf0 loads 4 bytes from (a0 + (a1 << 0x5)) +0x3c.
  The return at 0xcec has v0 = [(a0 + (a1 << 0x5))+60].

- `pciio_info_rom_base_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xcf4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xcf4-0xcfc (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcf8 loads 4 bytes from a0 (arg0 at entry) +0xf8.
  The return at 0xcf4 has v0 = [a0+248].

- `pciio_info_rom_size_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xcfc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xcfc-0xd04 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd00 loads 4 bytes from a0 (arg0 at entry) +0xfc.
  The return at 0xcfc has v0 = [a0+252].

- `pciio_businfo_multi_master_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xd04 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xd04-0xd0c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd08 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0xd04 has v0 = [a0].

- `pciio_businfo_asic_type_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xd0c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xd0c-0xd14 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd10 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xd0c has v0 = [a0+4].

- `pciio_businfo_bus_type_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xd14 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xd14-0xd1c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd18 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xd14 has v0 = [a0+8].

- `pciio_businfo_bus_speed_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xd1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xd1c-0xd24 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd20 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xd1c has v0 = [a0+12].

- `pciio_init` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xd24 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xd24-0xd84 (96 bytes).
  It occupies 96 bytes.
  The `jal` at 0xd48 calls cdl_new with a0=sym(.rodata)+64, a1=sym(.rodata)+72, a2=sym(.rodata)+80, a3=a3 at entry (arg3).
  The `jal` at 0xd5c calls compare_and_swap_ptr with a0=sym(pciio_registry), a1=0x0, a2=ret(cdl_new), a3=?.
  The `jal` at 0xd74 calls cdl_del with a0=ret(cdl_new), a1=?, a2=?, a3=?.
  The `bne` branch at 0xd2c targets 0xd68, is taken when at(=[sym(pciio_registry)]) != 0, and falls through when at(=[sym(pciio_registry)]) == 0.
  The `beq` branch at 0xd64 targets 0xd74, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0xd7c targets 0xd6c and is always taken.
  The return at 0xd6c has v0 = one of ret(compare_and_swap_ptr), ?, ret(cdl_del).

- `pciio_attach` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xd84 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xd84-0xd8c (8 bytes).
  It occupies 8 bytes.
  The return at 0xd84 has v0 = 0x0.

- `pciio_provider_register` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xd8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xd8c-0xdb0 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xd9c calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+88, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0xda8 has v0 = ret(hwgraph_info_add_LBL).

- `pciio_provider_unregister` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xdb0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xdb0-0xdd4 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xdc0 calls hwgraph_info_remove_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+88, a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xdcc has v0 = ret(hwgraph_info_remove_LBL).

- `pciio_provider_fns_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xdd4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xdd4-0xe00 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xde8 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+88, a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xdf8 has v0 = ?.

- `pciio_driver_register` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xe00 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xe00-0xe78 (120 bytes).
  It occupies 120 bytes.
  The `jal` at 0xe44 calls cdl_add_driver with a0=[sym(pciio_registry)], a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=sym(pciio_driver_reg_callback), a7=a1 at entry (arg1).
  The `jal` at 0xe5c calls pciio_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `beq` branch at 0xe28 targets 0xe5c, is taken when t1(=[sym(pciio_registry)]) == 0, and falls through when t1(=[sym(pciio_registry)]) != 0.
  The `beq` branch at 0xe70 targets 0xe30 and is always taken.
  The return at 0xe54 has v0 = ret(cdl_add_driver).

- `pciio_driver_unregister` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xe78 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xe78-0xea0 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0xe8c calls cdl_del_driver with a0=[sym(pciio_registry)], a1=a0 at entry (arg0), a2=sym(pciio_driver_unreg_callback), a3=a3 at entry (arg3).
  The return at 0xe98 has v0 = ret(cdl_del_driver).

- `pciio_driver_reg_callback` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xea0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xea0-0xebc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xea8 calls pcimh_driver_reg_callback with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xeb4 has v0 = ret(pcimh_driver_reg_callback).

- `pciio_driver_unreg_callback` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xebc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xebc-0xed8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xec4 calls pcimh_driver_unreg_callback with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xed0 has v0 = ret(pcimh_driver_unreg_callback).

- `pciio_iterate` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xed8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xed8-0xf28 (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xefc calls cdl_iterate with a0=[sym(pciio_registry)], a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=?, a4=[sym(pciio_registry)].
  The `jal` at 0xf14 calls pciio_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=[sym(pciio_registry)].
  The `beq` branch at 0xef0 targets 0xf14, is taken when a4(=[sym(pciio_registry)]) == 0, and falls through when a4(=[sym(pciio_registry)]) != 0.
  The `beq` branch at 0xf20 targets 0xef8 and is always taken.
  The return at 0xf0c has v0 = ret(cdl_iterate).

- `pciio_device_register` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xf28 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xf28-0xf5c (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0xf38 calls pciio_device_info_new with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf44 calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pciio_device_info_new), a2=?, a3=?.
  The return at 0xf54 has v0 = ret(pciio_device_info_register).

- `pciio_device_unregister` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xf5c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xf5c-0xf78 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xf64 calls pcimh_device_unregister with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xf70 has v0 = ret(pcimh_device_unregister).

- `pciio_device_info_new` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0xf78 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0xf78-0x1030 (184 bytes).
  It occupies 184 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xfc4, `sb` at 0xfc8.
  13 such `sw` accesses store 4 bytes to ?, including `sw` at 0xfcc, `sw` at 0xfd0, `sw` at 0xfd4.
  The `jal` at 0xfac calls kmem_zalloc with a0=0x128, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xfd8 calls hwgraph_fastinfo_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0xfe8 calls pciio_provider_fns_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `bne` branch at 0xfa0 targets 0xfc4, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0x1028 has v0 = ?.

- `pciio_device_info_free` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1030 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1030-0x104c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1038 calls bzero with a0=a0 at entry (arg0), a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1044 has v0 = ret(bzero).

- `pciio_device_info_register` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x104c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x104c-0x10d0 (132 bytes).
  It occupies 132 bytes.
  The `lbu` at 0x1058 loads 1 byte from a1 (arg1 at entry) +0xd.
  The `lbu` at 0x1070 loads 1 byte from a1 (arg1 at entry) +0xe.
  The `sw` at 0x10a4 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `sw` at 0x10ac stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `lw` at 0x10bc loads 4 bytes from a1 (arg1 at entry) +0x18.
  The `jal` at 0x106c calls pciio_slot_func_to_name with a0=sp-64, a1=[a1+13]:1, a2=[a1+14]:1, a3=a3 at entry (arg3).
  The `jal` at 0x107c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0x10b4 calls pciio_info_set with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x10c0 calls device_master_set with a0=?, a1=[a1+24], a2=?, a3=?.
  The `beq` branch at 0x1084 targets 0x10a0, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x10c8 targets 0x1090 and is always taken.
  The return at 0x1098 has v0 = ?.

- `pciio_device_info_unregister` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x10d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x10d0-0x114c (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0x10ec loads 1 byte from a1 (arg1 at entry) +0xe.
  The `lbu` at 0x10f0 loads 1 byte from a1 (arg1 at entry) +0xd.
  The `jal` at 0x10f4 calls pciio_slot_func_to_name with a0=sp-64, a1=[a1+13]:1, a2=[a1+14]:1, a3=a3 at entry (arg3), a4=a1 at entry (arg1).
  The `jal` at 0x1104 calls hwgraph_edge_remove with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0x1110 calls pciio_info_set with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1118 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x112c calls hwgraph_edge_remove with a0=?, a1=sym(.rodata)+104, a2=0x0, a3=?.
  The `jal` at 0x1134 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x113c calls hwgraph_vertex_destroy with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x10dc targets 0x10ec, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x1144 targets 0x10e4 and is always taken.
  The return at 0x10e4 has v0 = one of ?, ret(hwgraph_vertex_destroy).

- `pciio_device_inventory_add` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x114c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x114c-0x1194 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x115c loads 4 bytes from ret(pciio_info_get) +0x10.
  The `lw` at 0x116c loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lbu` at 0x117c loads 1 byte from ret(pciio_info_get) +0xd.
  The `jal` at 0x1154 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1180 calls device_inventory_add with a0=a0 at entry (arg0), a1=0xb, a2=0x4, a3=[ret(pciio_info_get)+16], a4=[ret(pciio_info_get)+20], a5=[ret(pciio_info_get)+13]:1.
  The `beq` branch at 0x1164 targets 0x118c, is taken when a3(=[ret(pciio_info_get)+16]) == a5(=-0x1), and falls through when a3(=[ret(pciio_info_get)+16]) != a5(=-0x1).
  The `beq` branch at 0x1170 targets 0x1188, is taken when a4(=[ret(pciio_info_get)+20]) == a5(=-0x1), and falls through when a4(=[ret(pciio_info_get)+20]) != a5(=-0x1).
  The return at 0x118c has v0 = one of ret(pciio_info_get), ?.

- `pciio_device_inventory_remove` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1194 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1194-0x11c0 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x11ac calls hwgraph_inventory_remove with a0=a0 at entry (arg0), a1=-0x1, a2=-0x1, a3=-0x1, a4=-0x1, a5=-0x1.
  The return at 0x11b8 has v0 = ret(hwgraph_inventory_remove).

- `pciio_device_attach` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x11c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x11c0-0x1210 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x11e8 loads 4 bytes from ret(pciio_info_get) +0x10.
  The `lw` at 0x11f0 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `jal` at 0x11d4 calls pciio_device_inventory_add with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11dc calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x11f4 calls cdl_add_connpt with a0=[sym(pciio_registry)], a1=[ret(pciio_info_get)+16], a2=[ret(pciio_info_get)+20], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0x1208 has v0 = ret(cdl_add_connpt).

- `pciio_device_detach` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1210 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1210-0x1260 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x1238 loads 4 bytes from ret(pciio_info_get) +0x10.
  The `lw` at 0x1240 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `jal` at 0x1224 calls pciio_device_inventory_remove with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x122c calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1244 calls cdl_del_connpt with a0=[sym(pciio_registry)], a1=[ret(pciio_info_get)+16], a2=[ret(pciio_info_get)+20], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0x1258 has v0 = ret(cdl_del_connpt).

- `pciio_device_win_map_new` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1260 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1260-0x12d4 (116 bytes).
  It occupies 116 bytes.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x12b4, `sw` at 0x12c0.
  The `jal` at 0x1288 calls kmem_zalloc with a0=0x8, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12a8 calls rmallocmap with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x127c targets 0x1294, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0x12cc has v0 = ?.

- `pciio_device_win_map_free` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x12d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x12d4-0x1308 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x12e8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x12e4 calls rmfreemap with a0=[a0], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12f0 calls bzero with a0=a0 at entry (arg0), a1=0x8, a2=?, a3=?.
  The return at 0x1300 has v0 = ret(bzero).

- `pciio_device_win_populate` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1308 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1308-0x134c (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x1308 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x1324 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x1338 calls rmfree with a0=[a0], a1=?, a2=?, a3=a3 at entry (arg3).
  The return at 0x1344 has v0 = ret(rmfree).

- `pciio_device_win_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x134c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x134c-0x1434 (232 bytes).
  It occupies 232 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x134c, `lw` at 0x13c8.
  The `lw` at 0x135c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x13bc stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `sw` at 0x13c0 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `sw` at 0x13c4 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x13a8 calls rmalloc_reserve with a0=[a0], a1=?, a2=?, a3=0x0, a7=[a0+4].
  The `jal` at 0x1418 calls rmalloc_align with a0=[a0], a1=?, a2=?, a3=0x1, a7=[a0+4].
  The `beq` branch at 0x1384 targets 0x13f4, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x13b4 targets 0x13c8, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0x1400 targets 0x140c, is taken when a4(?) >= s0(?) (unsigned), and falls through when a4(?) < s0(?) (unsigned).
  The `bne` branch at 0x1424 targets 0x13b4, is taken when v0(=ret(rmalloc_align)) != a1(=-0x1), and falls through when v0(=ret(rmalloc_align)) == a1(=-0x1).
  The `beq` branch at 0x142c targets 0x13dc and is always taken.
  The return at 0x13ec has v0 = one of ?, 0x0.

- `pciio_device_win_free` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1434 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1434-0x1464 (48 bytes).
  It occupies 48 bytes.
  The `lw` at 0x1434 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x1448 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x144c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x1454 loads 4 bytes from [a0] +0x0.
  The `jal` at 0x1450 calls rmfree with a0=[[a0]], a1=[a0+8], a2=[a0+4], a3=a3 at entry (arg3), a4=a0 at entry (arg0).
  The `beq` branch at 0x1440 targets 0x1458, is taken when a1(=[a0+8]) == 0, and falls through when a1(=[a0+8]) != 0.
  The return at 0x145c has v0 = one of ?, ret(rmfree).

- `pciio_error_register` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1464 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1464-0x1498 (52 bytes).
  It occupies 52 bytes.
  The `sw` at 0x147c stores 4 bytes to ret(pciio_info_get) +0x28.
  The `sw` at 0x1494 stores 4 bytes to ret(pciio_info_get) +0x2c.
  The `jal` at 0x1474 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1490 has v0 = ret(pciio_info_get).

- `pciio_slot_inuse` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1498 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1498-0x14cc (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x14a8 loads 4 bytes from ret(pciio_info_get) +0x10.
  The `jal` at 0x14a0 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x14b0 targets 0x14c4, is taken when at(=[ret(pciio_info_get)+16]) == 0, and falls through when at(=[ret(pciio_info_get)+16]) != 0.
  The `beq` branch at 0x14c4 targets 0x14bc and is always taken.
  The return at 0x14bc has v0 = one of 0x0, 0x1.

- `pciio_dma_enabled` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x14cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x14cc-0x14e8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x14d4 calls pcimh_dma_enabled with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14e0 has v0 = ret(pcimh_dma_enabled).

- `pciio_info_type1_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x14e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x14e8-0x14f0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0x14ec loads 4 bytes from a0 (arg0 at entry) +0x124.
  The return at 0x14e8 has v0 = [a0+292].

- `pciio_businfo_get` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x14f0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x14f0-0x1540 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x1504 loads 4 bytes from ret(pciio_info_get) +0x120.
  The `jal` at 0x14fc calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1510 calls pciio_ppb_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1520 calls pcimh_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1508 targets 0x1520, is taken when at(=[ret(pciio_info_get)+288]) == 0, and falls through when at(=[ret(pciio_info_get)+288]) != 0.
  The `beq` branch at 0x1518 targets 0x152c and is always taken.
  The return at 0x1538 has v0 = one of ret(pciio_ppb_businfo_get), ret(pcimh_businfo_get).

- `pciio_latency_set` in `IP32/usr/cpu/sysgen/IP32boot/pciio.o` at 0x1540 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pciio.o`.
  Range: 0x1540-0x1638 (248 bytes).
  It occupies 248 bytes.
  The `lw` at 0x1578 loads 4 bytes from ret(pciio_info_get) +0x120.
  The `lw` at 0x158c loads 4 bytes from [ret(pciio_info_get)+288] +0x4.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x15b0, `lw` at 0x15bc, `lw` at 0x161c.
  The `jal` at 0x1558 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1570 calls pciio_config_set with a0=a0 at entry (arg0), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x1598 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=?.
  The `jal` at 0x15c0 calls pciio_info_dev_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x15d4 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=?.
  The `jal` at 0x15f8 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x1610 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=a1 at entry (arg1).
  The `beq` branch at 0x1580 targets 0x1620, is taken when s1(=[ret(pciio_info_get)+288]) == 0, and falls through when s1(=[ret(pciio_info_get)+288]) != 0.
  The `beq` branch at 0x1588 targets 0x15c0 and is always taken.
  The `bne` branch at 0x15a8 targets 0x1608, is taken when at(?) < s0(=a1) (signed), and falls through when at(?) >= s0(=a1) (signed).
  The `beq` branch at 0x15b4 targets 0x1620, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x15e4 targets 0x1594, is taken when v0(?) >= s0(=a1) (signed), and falls through when v0(?) < s0(=a1) (signed).
  The `beq` branch at 0x1600 targets 0x1594 and is always taken.
  The `beq` branch at 0x1618 targets 0x15b4 and is always taken.
  The return at 0x1630 has v0 = one of ret(pciio_config_set), ?.
  The instructions from 0x1590 to 0x1590 are not reached by any path from the entry, and their branches are not listed.
