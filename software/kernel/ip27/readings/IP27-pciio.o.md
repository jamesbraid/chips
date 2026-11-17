# Readings: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`

One entry per routine, filed here from the reading batches by binary.

- `pciio_piomap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x0-0x1c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x8 calls pcibr_piomap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14 has v0 = ret(pcibr_piomap_alloc).

- `pciio_piomap_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1c-0x38 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x24 calls pcibr_piomap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x30 has v0 = ret(pcibr_piomap_free).

- `pciio_piomap_addr` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x38-0x60 (40 bytes).
  It occupies 40 bytes.
  The `sd` at 0x50 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `jal` at 0x44 calls pcibr_piomap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x58 has v0 = ret(pcibr_piomap_addr).

- `pciio_piomap_done` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x60-0x7c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x68 calls pcibr_piomap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x74 has v0 = ret(pcibr_piomap_done).

- `pciio_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x7c-0x98 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x84 calls pcibr_piotrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x90 has v0 = ret(pcibr_piotrans_addr).

- `pciio_pio_addr` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x98-0x1c4 (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0xe4 loads 8 bytes from a5 (arg5 at entry) +0x0.
  2 such `sd` accesses store 8 bytes to a5 (arg5 at entry) +0x0, including `sd` at 0xe8, `sd` at 0x154.
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

- `pciio_piospace_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1c4-0x1e8 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x1d4 calls pcibr_piospace_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1e0 has v0 = ret(pcibr_piospace_alloc).

- `pciio_piospace_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1e8-0x204 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1f0 calls pcibr_piospace_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1fc has v0 = ret(pcibr_piospace_free).

- `pciio_pio_flush_read` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x204 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x204-0x220 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x20c calls pcibr_pio_flush_read with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x218 has v0 = ret(pcibr_pio_flush_read).

- `pciio_pio_flush_del` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x220-0x23c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x228 calls pcibr_pio_flush_del with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x234 has v0 = ret(pcibr_pio_flush_del).

- `pciio_pio_flush_init` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x23c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x23c-0x258 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x244 calls pcibr_pio_flush_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x250 has v0 = ret(pcibr_pio_flush_init).

- `pciio_dmamap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x258 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x258-0x274 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x260 calls pcibr_dmamap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x26c has v0 = ret(pcibr_dmamap_alloc).

- `pciio_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x274 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x274-0x290 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x27c calls pcibr_dmamap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x288 has v0 = ret(pcibr_dmamap_free).

- `pciio_dmamap_addr` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x290 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x290-0x2ac (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x298 calls pcibr_dmamap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2a4 has v0 = ret(pcibr_dmamap_addr).

- `pciio_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x2ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x2ac-0x2c8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2b4 calls pcibr_dmamap_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2c0 has v0 = ret(pcibr_dmamap_list).

- `pciio_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x2c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x2c8-0x2e4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2d0 calls pcibr_dmamap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2dc has v0 = ret(pcibr_dmamap_done).

- `pciio_dmatrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x2e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x2e4-0x300 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2ec calls pcibr_dmatrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2f8 has v0 = ret(pcibr_dmatrans_addr).

- `pciio_dmatrans_list` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x300 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x300-0x31c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x308 calls pcibr_dmatrans_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x314 has v0 = ret(pcibr_dmatrans_list).

- `pciio_dma_addr` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x31c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x31c-0x438 (284 bytes).
  It occupies 284 bytes.
  The `ld` at 0x35c loads 8 bytes from a4 (arg4 at entry) +0x0.
  2 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0x364, `sd` at 0x3e8.
  The `jal` at 0x380 calls pciio_dmatrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a5 at entry (arg5).
  The `jal` at 0x3d0 calls pciio_dmamap_addr with a0=?, a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x400 calls pciio_dmamap_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x418 calls pciio_dmamap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a5 at entry (arg5).
  The `beq` branch at 0x354 targets 0x368, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x360 targets 0x36c and is always taken.
  The `beq` branch at 0x388 targets 0x3bc, is taken when v0(=ret(pciio_dmatrans_addr)) == 0, and falls through when v0(=ret(pciio_dmatrans_addr)) != 0.
  The `beq` branch at 0x3bc targets 0x410, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3d8 targets 0x3f8, is taken when v0(=ret(pciio_dmamap_addr)) == 0, and falls through when v0(=ret(pciio_dmamap_addr)) != 0.
  The `beq` branch at 0x3e0 targets 0x3f0, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0x3f0 targets 0x394 and is always taken.
  The `beq` branch at 0x3f8 targets 0x408, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x408 targets 0x390 and is always taken.
  The `beq` branch at 0x420 targets 0x430, is taken when v0(=ret(pciio_dmamap_alloc)) == 0, and falls through when v0(=ret(pciio_dmamap_alloc)) != 0.
  The `beq` branch at 0x428 targets 0x3c8 and is always taken.
  The `beq` branch at 0x430 targets 0x390 and is always taken.
  The return at 0x3b4 has v0 = one of ?, ret(pciio_dmamap_addr).

- `pciio_dmamap_drain` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x438 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x438-0x454 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x440 calls pcibr_dmamap_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x44c has v0 = ret(pcibr_dmamap_drain).

- `pciio_dmaaddr_drain` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x454 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x454-0x470 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x45c calls pcibr_dmaaddr_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x468 has v0 = ret(pcibr_dmaaddr_drain).

- `pciio_dmalist_drain` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x470 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x470-0x48c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x478 calls pcibr_dmalist_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x484 has v0 = ret(pcibr_dmalist_drain).

- `pciio_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x48c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x48c-0x4f4 (104 bytes).
  It occupies 104 bytes.
  The `lw` at 0x4b0 loads 4 bytes from ret(pciio_info_get) +0xc.
  The `lw` at 0x4b4 loads 4 bytes from ret(pciio_info_get) +0x8.
  The `jal` at 0x4a8 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4c0 calls pciio_ppb_intr_map with a0=ret(pciio_info_get), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x4d8 calls pcibr_intr_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `beq` branch at 0x4b8 targets 0x4cc, is taken when at(=[ret(pciio_info_get)+8]) == v1(=[ret(pciio_info_get)+12]), and falls through when at(=[ret(pciio_info_get)+8]) != v1(=[ret(pciio_info_get)+12]).
  The return at 0x4ec has v0 = ret(pcibr_intr_alloc).

- `pciio_intr_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x4f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x4f4-0x510 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4fc calls pcibr_intr_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x508 has v0 = ret(pcibr_intr_free).

- `pciio_intr_setmustrun` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x510 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x510-0x52c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x518 calls pcibr_intr_setmustrun with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x524 has v0 = ret(pcibr_intr_setmustrun).

- `pciio_intr_connect` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x52c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x52c-0x548 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x534 calls pcibr_intr_connect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x540 has v0 = ret(pcibr_intr_connect).

- `pciio_intr_disconnect` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x548 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x548-0x564 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x550 calls pcibr_intr_disconnect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x55c has v0 = ret(pcibr_intr_disconnect).

- `pciio_intr_cpu_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x564 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x564-0x580 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x56c calls pcibr_intr_cpu_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x578 has v0 = ret(pcibr_intr_cpu_get).

- `pciio_slot_func_to_name` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x580 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x580-0x5e4 (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x5a8 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=a2+97, a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `jal` at 0x5c4 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `jal` at 0x5d4 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `beq` branch at 0x590 targets 0x5d4, is taken when a4(=0xff) == a1, and falls through when a4(=0xff) != a1.
  The `beq` branch at 0x598 targets 0x5bc, is taken when a4(=0xff) == a2, and falls through when a4(=0xff) != a2.
  The `beq` branch at 0x5cc targets 0x5b4 and is always taken.
  The `beq` branch at 0x5dc targets 0x5b4 and is always taken.
  The return at 0x5b4 has v0 = ret(sprintf).

- `pciio_cardinfo_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x5e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x5e4-0x684 (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x5fc calls pciio_slot_func_to_name with a0=sp-64, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x60c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-64, a2=sp-48, a3=?.
  The `jal` at 0x644 calls pciio_info_chk with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x650 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x664 calls pciio_slot_func_to_name with a0=sp-64, a1=a1 at entry (arg1), a2=0xff, a3=?.
  The `jal` at 0x674 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-64, a2=sp-48, a3=?.
  The `beq` branch at 0x618 targets 0x628, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x620 targets 0x660, is taken when at(=a2) == 0, and falls through when at(=a2) != 0.
  The `beq` branch at 0x628 targets 0x644, is taken when a0(=ret(hwgraph_traverse)) == 0, and falls through when a0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x658 targets 0x634 and is always taken.
  The `beq` branch at 0x67c targets 0x628 and is always taken.
  The return at 0x63c has v0 = one of 0x0, ret(pciio_info_chk).

- `pciio_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x684 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x684-0x804 (384 bytes).
  It occupies 384 bytes.
  4 such `ld` accesses load 8 bytes from ret(pciio_cardinfo_get) +0x38, including `ld` at 0x6c4, `ld` at 0x718, `ld` at 0x770.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x6d0, `lw` at 0x70c.
  2 such `ld` accesses load 8 bytes from ret(pciio_cardinfo_get) +0x40, including `ld` at 0x72c, `ld` at 0x798.
  The `lh` at 0x744 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `ld` at 0x7d4 loads 8 bytes from a3 (arg3 at entry) +0x28.
  The `jal` at 0x6b0 calls pciio_cardinfo_get with a0=a0 at entry (arg0), a1=0xff, a2=0xff, a3=a3 at entry (arg3).
  The `jal` at 0x710 calls pciio_info_dev_get with a0=ret(pciio_cardinfo_get), a1=?, a2=?, a3=?.
  The `jalr` at 0x728 calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+64]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x75c calls pciio_cardinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x77c calls pciio_info_dev_get with a0=ret(pciio_cardinfo_get), a1=?, a2=[ret(pciio_cardinfo_get)+56]:8, a3=?.
  The `jalr` at 0x794 calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+64]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[ret(pciio_cardinfo_get)+56]:8.
  The `jal` at 0x7b0 calls pciio_info_dev_get with a0=ret(pciio_cardinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7c4 calls hwgraph_traverse with a0=ret(pciio_info_dev_get), a1=sym(.rodata), a2=sp-64, a3=?.
  The `jal` at 0x7dc calls usrpci_error_handler with a0=?, a1=a1 at entry (arg1), a2=[a3+40]:8, a3=?.
  The `jal` at 0x7e8 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x6b8 targets 0x704, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `bne` branch at 0x6c8 targets 0x710, is taken when at(=[ret(pciio_cardinfo_get)+56]:8) != 0, and falls through when at(=[ret(pciio_cardinfo_get)+56]:8) == 0.
  The `bltz` branch at 0x6d8 targets 0x744, is taken when v0(=([a3] << 0x2)) < 0 (signed), and falls through when v0(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0x708 targets 0x6d4 and is always taken.
  The `beq` branch at 0x734 targets 0x6d0, is taken when v0(=ret(?)) == a0(=0x9), and falls through when v0(=ret(?)) != a0(=0x9).
  The `beq` branch at 0x73c targets 0x6ec and is always taken.
  The `beq` branch at 0x768 targets 0x6dc, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `beq` branch at 0x774 targets 0x7b0, is taken when a2(=[ret(pciio_cardinfo_get)+56]:8) == 0, and falls through when a2(=[ret(pciio_cardinfo_get)+56]:8) != 0.
  The `beq` branch at 0x7a0 targets 0x7b0, is taken when v0(=ret(?)) == a5(=0x9), and falls through when v0(=ret(?)) != a5(=0x9).
  The `beq` branch at 0x7a8 targets 0x6ec and is always taken.
  The `bne` branch at 0x7cc targets 0x6dc, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beq` branch at 0x7f4 targets 0x6e0, is taken when s0(=ret(usrpci_error_handler)) == a0(=0x9), and falls through when s0(=ret(usrpci_error_handler)) != a0(=0x9).
  The `beq` branch at 0x7fc targets 0x6e8 and is always taken.
  The return at 0x6fc has v0 = one of ?, ret(?).

- `pciio_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x804 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x804-0x820 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x80c calls pcibr_error_devenable with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x818 has v0 = ret(pcibr_error_devenable).

- `pciio_provider_startup` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x820 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x820-0x83c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x828 calls pcibr_provider_startup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x834 has v0 = ret(pcibr_provider_startup).

- `pciio_provider_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x83c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x83c-0x858 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x844 calls pcibr_provider_shutdown with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x850 has v0 = ret(pcibr_provider_shutdown).

- `pciio_endian_set` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x858 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x858-0x874 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x860 calls pcibr_endian_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x86c has v0 = ret(pcibr_endian_set).

- `pciio_priority_set` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x874 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x874-0x890 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x87c calls pcibr_priority_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x888 has v0 = ret(pcibr_priority_set).

- `pciio_config_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x890 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x890-0x948 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x8f0 calls pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x8c8 targets 0x91c, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x914 targets 0x8d8, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0x940 has v0 = one of 0x0, ?.

- `pciio_config_get_safe` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x948 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x948-0xa00 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x9a8 calls pcibr_config_get_safe with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x980 targets 0x9d4, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x9cc targets 0x990, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0x9f8 has v0 = one of 0x0, ?.

- `pciio_config_set` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xa00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xa00-0xa98 (152 bytes).
  It occupies 152 bytes.
  The `jal` at 0xa58 calls pcibr_config_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa34 targets 0xa74, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa6c targets 0xa3c, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The return at 0xa90 has v0 = one of ?, ret(pcibr_config_set).

- `pciio_error_extract` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xa98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xa98-0xab4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xaa0 calls pcibr_error_extract with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xaac has v0 = ret(pcibr_error_extract).

- `pciio_reset` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xab4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xab4-0xad0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xabc calls pcibr_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xac8 has v0 = ret(pcibr_reset).

- `pciio_write_gather_flush` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xad0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xad0-0xaec (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xad8 calls pcibr_write_gather_flush with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xae4 has v0 = ret(pcibr_write_gather_flush).

- `pciio_intr_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xaec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xaec-0xaf4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xaf0 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xaec has v0 = [a0+4].

- `pciio_pio_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xaf4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xaf4-0xafc (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xaf8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xaf4 has v0 = [a0+4].

- `pciio_pio_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xafc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xafc-0xb04 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xb00 loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xafc has v0 = [a0+8]:1.

- `pciio_pio_space_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb04-0xb0c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xb08 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xb04 has v0 = [a0+12].

- `pciio_pio_pciaddr_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb0c-0xb14 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xb10 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0xb0c has v0 = [a0+16]:8.

- `pciio_pio_mapsz_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb14-0xb1c (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xb18 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xb14 has v0 = [a0+24]:8.

- `pciio_pio_kvaddr_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb1c-0xb24 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xb20 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The return at 0xb1c has v0 = [a0+32]:8.

- `pciio_dma_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb24-0xb2c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xb28 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xb24 has v0 = [a0+4].

- `pciio_dma_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb2c-0xb34 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xb30 loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xb2c has v0 = [a0+8]:1.

- `pciio_info_chk` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb34-0xb60 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xb48 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xb58 has v0 = ?.

- `pciio_info_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xb60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xb60-0xbb8 (88 bytes).
  It occupies 88 bytes.
  The `ld` at 0xb7c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `jal` at 0xb6c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xba8 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `beq` branch at 0xb74 targets 0xb88, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xb84 targets 0xb9c, is taken when at(=[ret(hwgraph_fastinfo_get)]:8) != v0(=sym(pciio_info_fingerprint)), and falls through when at(=[ret(hwgraph_fastinfo_get)]:8) == v0(=sym(pciio_info_fingerprint)).
  The `beq` branch at 0xbb0 targets 0xb8c and is always taken.
  The return at 0xb94 has v0 = ret(hwgraph_fastinfo_get).

- `pciio_hostinfo_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xbb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xbb8-0xbfc (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xbd0 loads 4 bytes from ret(pciio_info_get) +0xc.
  The `lw` at 0xbd4 loads 4 bytes from ret(pciio_info_get) +0x8.
  The `jal` at 0xbc0 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbec calls pciio_info_get with a0=[ret(pciio_info_get)+12], a1=?, a2=?, a3=ret(pciio_info_get).
  The `beq` branch at 0xbc8 targets 0xbdc, is taken when v0(=ret(pciio_info_get)) == 0, and falls through when v0(=ret(pciio_info_get)) != 0.
  The `bne` branch at 0xbd8 targets 0xbec, is taken when at(=[ret(pciio_info_get)+8]) != a0(=[ret(pciio_info_get)+12]), and falls through when at(=[ret(pciio_info_get)+8]) == a0(=[ret(pciio_info_get)+12]).
  The `beq` branch at 0xbf4 targets 0xbdc and is always taken.
  The return at 0xbe4 has v0 = ret(pciio_info_get).

- `pciio_info_set` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xbfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xbfc-0xc54 (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0xc1c stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0xc24 calls hwgraph_fastinfo_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sym(pciio_info_fingerprint), a3=a3 at entry (arg3).
  The `jal` at 0xc38 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=?.
  The `beq` branch at 0xc14 targets 0xc20, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0xc4c has v0 = ret(hwgraph_info_add_LBL).

- `pciio_info_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xc54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xc54-0xc5c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc58 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xc54 has v0 = [a0+8].

- `pciio_info_hostdev_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xc5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xc5c-0xc64 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc60 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xc5c has v0 = [a0+12].

- `pciio_info_bus_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xc64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xc64-0xc6c (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc68 loads 1 byte from a0 (arg0 at entry) +0x10.
  The return at 0xc64 has v0 = [a0+16]:1.

- `pciio_info_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xc6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xc6c-0xc74 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc70 loads 1 byte from a0 (arg0 at entry) +0x11.
  The return at 0xc6c has v0 = [a0+17]:1.

- `pciio_info_hostslot_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xc74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xc74-0xca0 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xc7c calls pciio_info_hostdev_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc84 calls pciio_info_get with a0=ret(pciio_info_hostdev_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc8c calls pciio_info_slot_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The return at 0xc98 has v0 = ret(pciio_info_slot_get).

- `pciio_info_function_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xca0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xca0-0xca8 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xca4 loads 1 byte from a0 (arg0 at entry) +0x12.
  The return at 0xca0 has v0 = [a0+18]:1.

- `pciio_info_vendor_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xca8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xca8-0xcb0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcac loads 4 bytes from a0 (arg0 at entry) +0x14.
  The return at 0xca8 has v0 = [a0+20].

- `pciio_info_device_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xcb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xcb0-0xcb8 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcb4 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xcb0 has v0 = [a0+24].

- `pciio_info_master_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xcb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xcb8-0xcc0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcbc loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The return at 0xcb8 has v0 = [a0+28].

- `pciio_info_mfast_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xcc0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xcc0-0xcc8 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xcc4 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The return at 0xcc0 has v0 = [a0+40]:8.

- `pciio_info_pops_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xcc8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xcc8-0xcd0 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xccc loads 8 bytes from a0 (arg0 at entry) +0x30.
  The return at 0xcc8 has v0 = [a0+48]:8.

- `pciio_info_efunc_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xcd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xcd0-0xcd8 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xcd4 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The return at 0xcd0 has v0 = [a0+56]:8.

- `pciio_info_einfo_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xcd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xcd8-0xce0 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xcdc loads 8 bytes from a0 (arg0 at entry) +0x40.
  The return at 0xcd8 has v0 = [a0+64]:8.

- `pciio_info_bar_space_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xce0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xce0-0xcf8 (24 bytes).
  It occupies 24 bytes.
  The `lw` at 0xcf4 loads 4 bytes from ?.
  The return at 0xcf0 has v0 = ?.

- `pciio_info_bar_base_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xcf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xcf8-0xd10 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0xd0c loads 8 bytes from ?.
  The return at 0xd08 has v0 = ?.

- `pciio_info_bar_size_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd10-0xd28 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0xd24 loads 8 bytes from ?.
  The return at 0xd20 has v0 = ?.

- `pciio_info_rom_base_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd28-0xd30 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xd2c loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  The return at 0xd28 has v0 = [a0+416]:8.

- `pciio_info_rom_size_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd30-0xd38 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xd34 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The return at 0xd30 has v0 = [a0+424]:8.

- `pciio_businfo_multi_master_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd38-0xd40 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd3c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0xd38 has v0 = [a0].

- `pciio_businfo_asic_type_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd40-0xd48 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd44 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xd40 has v0 = [a0+4].

- `pciio_businfo_bus_type_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd48-0xd50 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd4c loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xd48 has v0 = [a0+8].

- `pciio_businfo_bus_speed_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd50-0xd58 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xd54 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xd50 has v0 = [a0+12].

- `pciio_init` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xd58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xd58-0xdb0 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0xd74 calls cdl_new with a0=sym(.rodata), a1=sym(.rodata), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0xd88 calls compare_and_swap_ptr with a0=sym(pciio_registry), a1=0x0, a2=ret(cdl_new), a3=?.
  The `jal` at 0xda0 calls cdl_del with a0=ret(cdl_new), a1=?, a2=?, a3=?.
  The `bne` branch at 0xd60 targets 0xd94, is taken when at(=[sym(pciio_registry)]:8) != 0, and falls through when at(=[sym(pciio_registry)]:8) == 0.
  The `beq` branch at 0xd90 targets 0xda0, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0xda8 targets 0xd98 and is always taken.
  The return at 0xd98 has v0 = one of ret(compare_and_swap_ptr), ?, ret(cdl_del).

- `pciio_attach` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xdb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xdb0-0xdb8 (8 bytes).
  It occupies 8 bytes.
  The return at 0xdb0 has v0 = 0x0.

- `pciio_provider_register` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xdb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xdb8-0xddc (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xdc8 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0xdd4 has v0 = ret(hwgraph_info_add_LBL).

- `pciio_provider_unregister` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xddc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xddc-0xe00 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xdec calls hwgraph_info_remove_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xdf8 has v0 = ret(hwgraph_info_remove_LBL).

- `pciio_provider_fns_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xe00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xe00-0xe2c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xe14 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xe24 has v0 = ?.

- `pciio_driver_register` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xe2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xe2c-0xea0 (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0xe6c calls cdl_add_driver with a0=[sym(pciio_registry)]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=sym(pciio_driver_reg_callback), a7=a1 at entry (arg1).
  The `jal` at 0xe84 calls pciio_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `beq` branch at 0xe54 targets 0xe84, is taken when t1(=[sym(pciio_registry)]:8) == 0, and falls through when t1(=[sym(pciio_registry)]:8) != 0.
  The `beq` branch at 0xe98 targets 0xe5c and is always taken.
  The return at 0xe7c has v0 = ret(cdl_add_driver).

- `pciio_driver_unregister` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xea0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xea0-0xec4 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xeb0 calls cdl_del_driver with a0=[sym(pciio_registry)]:8, a1=a0 at entry (arg0), a2=sym(pciio_driver_unreg_callback), a3=a3 at entry (arg3).
  The return at 0xebc has v0 = ret(cdl_del_driver).

- `pciio_driver_reg_callback` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xec4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xec4-0xee0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xecc calls pcibr_driver_reg_callback with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xed8 has v0 = ret(pcibr_driver_reg_callback).

- `pciio_driver_unreg_callback` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xee0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xee0-0xefc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xee8 calls pcibr_driver_unreg_callback with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xef4 has v0 = ret(pcibr_driver_unreg_callback).

- `pciio_iterate` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xefc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xefc-0xf4c (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xf20 calls cdl_iterate with a0=[sym(pciio_registry)]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=?, a4=[sym(pciio_registry)]:8.
  The `jal` at 0xf38 calls pciio_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=[sym(pciio_registry)]:8.
  The `beq` branch at 0xf14 targets 0xf38, is taken when a4(=[sym(pciio_registry)]:8) == 0, and falls through when a4(=[sym(pciio_registry)]:8) != 0.
  The `beq` branch at 0xf44 targets 0xf1c and is always taken.
  The return at 0xf30 has v0 = ret(cdl_iterate).

- `pciio_device_register` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xf4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xf4c-0xf80 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0xf5c calls pciio_device_info_new with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf68 calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pciio_device_info_new), a2=?, a3=?.
  The return at 0xf78 has v0 = ret(pciio_device_info_register).

- `pciio_device_unregister` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xf80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xf80-0xf9c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xf88 calls pcibr_device_unregister with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xf94 has v0 = ret(pcibr_device_unregister).

- `pciio_device_info_new` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0xf9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0xf9c-0x1054 (184 bytes).
  It occupies 184 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xfe8, `sb` at 0xfec.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0xff0, `sw` at 0xff4, `sw` at 0xff8.
  8 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1008, `sd` at 0x1018, `sd` at 0x101c.
  The `jal` at 0xfd0 calls kmem_zalloc with a0=0x200, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xffc calls hwgraph_fastinfo_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x100c calls pciio_provider_fns_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `bne` branch at 0xfc4 targets 0xfe8, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0x104c has v0 = ?.

- `pciio_device_info_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1054 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1054-0x1070 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x105c calls bzero with a0=a0 at entry (arg0), a1=0x8, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1068 has v0 = ret(bzero).

- `pciio_device_info_register` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1070 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1070-0x1128 (184 bytes).
  It occupies 184 bytes.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x11, including `lbu` at 0x107c, `lbu` at 0x10f4.
  The `lbu` at 0x1094 loads 1 byte from a1 (arg1 at entry) +0x12.
  The `sw` at 0x10c8 stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `sw` at 0x10d0 stores 4 bytes to a1 (arg1 at entry) +0xc.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x1c, including `lw` at 0x10e0, `lw` at 0x1114.
  The `jal` at 0x1090 calls pciio_slot_func_to_name with a0=sp-64, a1=[a1+17]:1, a2=[a1+18]:1, a3=a3 at entry (arg3).
  The `jal` at 0x10a0 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0x10d8 calls pciio_info_set with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x10e4 calls device_master_set with a0=?, a1=[a1+28], a2=?, a3=?.
  The `jal` at 0x10ec calls pciio_info_bus_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1118 calls usrpci_device_register with a0=?, a1=[a1+28], a2=[a1+17]:1, a3=?.
  The `beq` branch at 0x10ac targets 0x10c8, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x10fc targets 0x110c, is taken when a2(=[a1+17]:1) == v1(=0xff), and falls through when a2(=[a1+17]:1) != v1(=0xff).
  The `beq` branch at 0x1104 targets 0x1114, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x110c targets 0x10b8 and is always taken.
  The `beq` branch at 0x1120 targets 0x110c and is always taken.
  The return at 0x10c0 has v0 = ?.

- `pciio_device_info_unregister` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1128 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1128-0x11a4 (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0x1144 loads 1 byte from a1 (arg1 at entry) +0x12.
  The `lbu` at 0x1148 loads 1 byte from a1 (arg1 at entry) +0x11.
  The `jal` at 0x114c calls pciio_slot_func_to_name with a0=sp-64, a1=[a1+17]:1, a2=[a1+18]:1, a3=a3 at entry (arg3), a4=a1 at entry (arg1).
  The `jal` at 0x115c calls hwgraph_edge_remove with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0x1168 calls pciio_info_set with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1170 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1184 calls hwgraph_edge_remove with a0=?, a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0x118c calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1194 calls hwgraph_vertex_destroy with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x1134 targets 0x1144, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x119c targets 0x113c and is always taken.
  The return at 0x113c has v0 = one of ?, ret(hwgraph_vertex_destroy).

- `pciio_device_inventory_add` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x11a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x11a4-0x11f0 (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0x11b4 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0x11c4 loads 4 bytes from ret(pciio_info_get) +0x18.
  The `lbu` at 0x11d8 loads 1 byte from ret(pciio_info_get) +0x11.
  The `jal` at 0x11ac calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11dc calls device_inventory_add with a0=a0 at entry (arg0), a1=0xb, a2=0x4, a3=[ret(pciio_info_get)+20], a4=[ret(pciio_info_get)+24], a5=[ret(pciio_info_get)+17]:1.
  The `beq` branch at 0x11bc targets 0x11e8, is taken when a3(=[ret(pciio_info_get)+20]) == a5(=-0x1), and falls through when a3(=[ret(pciio_info_get)+20]) != a5(=-0x1).
  The `beq` branch at 0x11c8 targets 0x11e8, is taken when a4(=[ret(pciio_info_get)+24]) == a5(=-0x1), and falls through when a4(=[ret(pciio_info_get)+24]) != a5(=-0x1).
  The return at 0x11e8 has v0 = one of ret(pciio_info_get), ret(device_inventory_add).

- `pciio_device_inventory_remove` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x11f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x11f0-0x121c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x1208 calls hwgraph_inventory_remove with a0=a0 at entry (arg0), a1=-0x1, a2=-0x1, a3=-0x1, a4=-0x1, a5=-0x1.
  The return at 0x1214 has v0 = ret(hwgraph_inventory_remove).

- `pciio_device_attach` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x121c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x121c-0x126c (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x1244 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0x124c loads 4 bytes from ret(pciio_info_get) +0x18.
  The `jal` at 0x1230 calls pciio_device_inventory_add with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1238 calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1250 calls cdl_add_connpt with a0=[sym(pciio_registry)]:8, a1=[ret(pciio_info_get)+20], a2=[ret(pciio_info_get)+24], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0x1264 has v0 = ret(cdl_add_connpt).

- `pciio_device_detach` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x126c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x126c-0x12bc (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x1294 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0x129c loads 4 bytes from ret(pciio_info_get) +0x18.
  The `jal` at 0x1280 calls pciio_device_inventory_remove with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1288 calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x12a0 calls cdl_del_connpt with a0=[sym(pciio_registry)]:8, a1=[ret(pciio_info_get)+20], a2=[ret(pciio_info_get)+24], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0x12b4 has v0 = ret(cdl_del_connpt).

- `pciio_device_win_map_new` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x12bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x12bc-0x1330 (116 bytes).
  It occupies 116 bytes.
  The `sw` at 0x1310 stores 4 bytes to ?.
  The `sd` at 0x131c stores 8 bytes to ?.
  The `jal` at 0x12e4 calls kmem_zalloc with a0=0x10, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1304 calls rmallocmap with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x12d8 targets 0x12f0, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0x1328 has v0 = ?.

- `pciio_device_win_map_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1330 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1330-0x1364 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x1344 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x1340 calls rmfreemap with a0=[a0]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x134c calls bzero with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The return at 0x135c has v0 = ret(bzero).

- `pciio_device_win_populate` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1364 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1364-0x13a8 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x1364 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x1380 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x1394 calls rmfree with a0=[a0]:8, a1=?, a2=?, a3=a3 at entry (arg3).
  The return at 0x13a0 has v0 = ret(rmfree).

- `pciio_device_win_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x13a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x13a8-0x1494 (236 bytes).
  It occupies 236 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x13a8, `lw` at 0x1420, `lw` at 0x1488.
  The `ld` at 0x13b8 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x1414 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `sd` at 0x1418 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `sd` at 0x141c stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x1404 calls rmalloc_reserve with a0=[a0]:8, a1=?, a2=?, a3=0x0, a7=[a0+8].
  The `jal` at 0x1468 calls rmalloc_align with a0=[a0]:8, a1=?, a2=?, a3=0x1, a7=[a0+8].
  The `beq` branch at 0x13e0 targets 0x144c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x140c targets 0x1420, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0x1474 targets 0x148c, is taken when v0(=ret(rmalloc_align)) == a5(=-0x1), and falls through when v0(=ret(rmalloc_align)) != a5(=-0x1).
  The `bne` branch at 0x147c targets 0x1414, is taken when s1(=a1) != 0, and falls through when s1(=a1) == 0.
  The `beq` branch at 0x1484 targets 0x1424 and is always taken.
  The `beq` branch at 0x148c targets 0x1434 and is always taken.
  The return at 0x1444 has v0 = one of ?, 0x0.

- `pciio_device_win_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1494 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1494-0x14c4 (48 bytes).
  It occupies 48 bytes.
  The `ld` at 0x1494 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x14a8 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x14ac loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x14b4 loads 8 bytes from [a0]:8 +0x0.
  The `jal` at 0x14b0 calls rmfree with a0=[[a0]:8]:8, a1=[a0+16]:8, a2=[a0+8]:8, a3=a3 at entry (arg3), a4=a0 at entry (arg0).
  The `beq` branch at 0x14a0 targets 0x14b8, is taken when a1(=[a0+16]:8) == 0, and falls through when a1(=[a0+16]:8) != 0.
  The return at 0x14bc has v0 = one of ?, ret(rmfree).

- `pciio_error_register` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x14c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x14c4-0x14f8 (52 bytes).
  It occupies 52 bytes.
  The `sd` at 0x14dc stores 8 bytes to ret(pciio_info_get) +0x38.
  The `sd` at 0x14f4 stores 8 bytes to ret(pciio_info_get) +0x40.
  The `jal` at 0x14d4 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14f0 has v0 = ret(pciio_info_get).

- `pciio_slot_inuse` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x14f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x14f8-0x152c (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x1508 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `jal` at 0x1500 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1510 targets 0x1524, is taken when at(=[ret(pciio_info_get)+20]) == 0, and falls through when at(=[ret(pciio_info_get)+20]) != 0.
  The `beq` branch at 0x1524 targets 0x151c and is always taken.
  The return at 0x151c has v0 = one of 0x0, 0x1.

- `pciio_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x152c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x152c-0x1548 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1534 calls pcibr_dma_enabled with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1540 has v0 = ret(pcibr_dma_enabled).

- `pciio_info_type1_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1548 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1548-0x1550 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0x154c loads 4 bytes from a0 (arg0 at entry) +0x1f8.
  The return at 0x1548 has v0 = [a0+504].

- `pciio_businfo_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x1550 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x1550-0x15a0 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x1564 loads 8 bytes from ret(pciio_info_get) +0x1f0.
  The `jal` at 0x155c calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1570 calls pciio_ppb_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1580 calls pcibr_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1568 targets 0x1580, is taken when at(=[ret(pciio_info_get)+496]:8) == 0, and falls through when at(=[ret(pciio_info_get)+496]:8) != 0.
  The `beq` branch at 0x1578 targets 0x158c and is always taken.
  The return at 0x1598 has v0 = one of ret(pciio_ppb_businfo_get), ret(pcibr_businfo_get).

- `pciio_latency_set` in `IP27/usr/cpu/sysgen/IP27boot/pciio.o` at 0x15a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio.o`.
  Range: 0x15a0-0x1694 (244 bytes).
  It occupies 244 bytes.
  The `ld` at 0x15d8 loads 8 bytes from ret(pciio_info_get) +0x1f0.
  The `ld` at 0x15ec loads 8 bytes from [ret(pciio_info_get)+496]:8 +0x8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1610, `ld` at 0x161c, `ld` at 0x1678.
  The `jal` at 0x15b8 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x15d0 calls pciio_config_set with a0=a0 at entry (arg0), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x15f8 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=?.
  The `jal` at 0x1620 calls pciio_info_dev_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1634 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=?.
  The `jal` at 0x1654 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x166c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=a1 at entry (arg1).
  The `beq` branch at 0x15e0 targets 0x167c, is taken when s1(=[ret(pciio_info_get)+496]:8) == 0, and falls through when s1(=[ret(pciio_info_get)+496]:8) != 0.
  The `beq` branch at 0x15e8 targets 0x1620 and is always taken.
  The `bne` branch at 0x1608 targets 0x1664, is taken when at(?) < s0(=a1) (signed), and falls through when at(?) >= s0(=a1) (signed).
  The `beq` branch at 0x1614 targets 0x167c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1644 targets 0x15f0, is taken when v0(?) >= s0(=a1) (signed), and falls through when v0(?) < s0(=a1) (signed).
  The `beq` branch at 0x165c targets 0x15f4 and is always taken.
  The `beq` branch at 0x1674 targets 0x1614 and is always taken.
  The return at 0x168c has v0 = one of ret(pciio_config_set), ?.
