# Readings: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`

One entry per routine, filed here from the reading batches by binary.

- `pciio_piomap_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x0-0x1c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x8 calls pcibr_piomap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14 has v0 = ret(pcibr_piomap_alloc).

- `pciio_piomap_free` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1c-0x38 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x24 calls pcibr_piomap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x30 has v0 = ret(pcibr_piomap_free).

- `pciio_piomap_addr` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x38-0x60 (40 bytes).
  It occupies 40 bytes.
  The `sd` at 0x50 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `jal` at 0x44 calls pcibr_piomap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x58 has v0 = ret(pcibr_piomap_addr).

- `pciio_piomap_done` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x60-0x7c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x68 calls pcibr_piomap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x74 has v0 = ret(pcibr_piomap_done).

- `pciio_piotrans_addr` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x7c-0x98 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x84 calls pcibr_piotrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x90 has v0 = ret(pcibr_piotrans_addr).

- `pciio_pio_addr` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
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

- `pciio_piospace_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1c4-0x1e8 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x1d4 calls pcibr_piospace_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1e0 has v0 = ret(pcibr_piospace_alloc).

- `pciio_piospace_free` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1e8-0x204 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1f0 calls pcibr_piospace_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1fc has v0 = ret(pcibr_piospace_free).

- `pciio_pio_flush_read` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x204 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x204-0x220 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x20c calls pcibr_pio_flush_read with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x218 has v0 = ret(pcibr_pio_flush_read).

- `pciio_pio_flush_del` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x220-0x23c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x228 calls pcibr_pio_flush_del with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x234 has v0 = ret(pcibr_pio_flush_del).

- `pciio_pio_flush_init` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x23c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x23c-0x258 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x244 calls pcibr_pio_flush_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x250 has v0 = ret(pcibr_pio_flush_init).

- `pciio_dmamap_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x258 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x258-0x274 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x260 calls pcibr_dmamap_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x26c has v0 = ret(pcibr_dmamap_alloc).

- `pciio_dmamap_free` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x274 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x274-0x290 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x27c calls pcibr_dmamap_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x288 has v0 = ret(pcibr_dmamap_free).

- `pciio_dmamap_addr` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x290 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x290-0x2ac (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x298 calls pcibr_dmamap_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2a4 has v0 = ret(pcibr_dmamap_addr).

- `pciio_dmamap_list` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x2ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x2ac-0x2c8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2b4 calls pcibr_dmamap_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2c0 has v0 = ret(pcibr_dmamap_list).

- `pciio_dmamap_done` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x2c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x2c8-0x2e4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2d0 calls pcibr_dmamap_done with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2dc has v0 = ret(pcibr_dmamap_done).

- `pciio_dmatrans_addr` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x2e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x2e4-0x300 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2ec calls pcibr_dmatrans_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2f8 has v0 = ret(pcibr_dmatrans_addr).

- `pciio_dmatrans_list` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x300 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x300-0x31c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x308 calls pcibr_dmatrans_list with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x314 has v0 = ret(pcibr_dmatrans_list).

- `pciio_dma_addr` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x31c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
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

- `pciio_dmamap_drain` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x438 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x438-0x454 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x440 calls pcibr_dmamap_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x44c has v0 = ret(pcibr_dmamap_drain).

- `pciio_dmaaddr_drain` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x454 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x454-0x470 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x45c calls pcibr_dmaaddr_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x468 has v0 = ret(pcibr_dmaaddr_drain).

- `pciio_dmalist_drain` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x470 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x470-0x48c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x478 calls pcibr_dmalist_drain with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x484 has v0 = ret(pcibr_dmalist_drain).

- `pciio_intr_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x48c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x48c-0x4f4 (104 bytes).
  It occupies 104 bytes.
  The `lw` at 0x4b0 loads 4 bytes from ret(pciio_info_get) +0xc.
  The `lw` at 0x4b4 loads 4 bytes from ret(pciio_info_get) +0x8.
  The `jal` at 0x4a8 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4c0 calls pciio_ppb_intr_map with a0=ret(pciio_info_get), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x4d8 calls pcibr_intr_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `beq` branch at 0x4b8 targets 0x4cc, is taken when at(=[ret(pciio_info_get)+8]) == v1(=[ret(pciio_info_get)+12]), and falls through when at(=[ret(pciio_info_get)+8]) != v1(=[ret(pciio_info_get)+12]).
  The return at 0x4ec has v0 = ret(pcibr_intr_alloc).

- `pciio_intr_free` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x4f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x4f4-0x510 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4fc calls pcibr_intr_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x508 has v0 = ret(pcibr_intr_free).

- `pciio_intr_setmustrun` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x510 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x510-0x52c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x518 calls pcibr_intr_setmustrun with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x524 has v0 = ret(pcibr_intr_setmustrun).

- `pciio_intr_connect` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x52c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x52c-0x548 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x534 calls pcibr_intr_connect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x540 has v0 = ret(pcibr_intr_connect).

- `pciio_intr_disconnect` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x548 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x548-0x564 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x550 calls pcibr_intr_disconnect with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x55c has v0 = ret(pcibr_intr_disconnect).

- `pciio_intr_cpu_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x564 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x564-0x580 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x56c calls pcibr_intr_cpu_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x578 has v0 = ret(pcibr_intr_cpu_get).

- `pciio_slot_func_to_name` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x580 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
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

- `pciio_cardinfo_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x5e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
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

- `pciio_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x684 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x684-0x7ac (296 bytes).
  It occupies 296 bytes.
  4 such `ld` accesses load 8 bytes from ret(pciio_cardinfo_get) +0x38, including `ld` at 0x6c0, `ld` at 0x710, `ld` at 0x764.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x6cc, `lw` at 0x704.
  2 such `ld` accesses load 8 bytes from ret(pciio_cardinfo_get) +0x40, including `ld` at 0x724, `ld` at 0x794.
  The `lh` at 0x73c loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0x6ac calls pciio_cardinfo_get with a0=a0 at entry (arg0), a1=0xff, a2=0xff, a3=a3 at entry (arg3).
  The `jal` at 0x708 calls pciio_info_dev_get with a0=ret(pciio_cardinfo_get), a1=?, a2=0x9, a3=?.
  The `jalr` at 0x720 calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+64]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x754 calls pciio_cardinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x774 calls pciio_info_dev_get with a0=ret(pciio_cardinfo_get), a1=?, a2=0x9, a3=[ret(pciio_cardinfo_get)+56]:8.
  The `jalr` at 0x790 calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+64]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[ret(pciio_cardinfo_get)+56]:8.
  The `beq` branch at 0x6b4 targets 0x6fc, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `bne` branch at 0x6c4 targets 0x708, is taken when at(=[ret(pciio_cardinfo_get)+56]:8) != 0, and falls through when at(=[ret(pciio_cardinfo_get)+56]:8) == 0.
  The `bltz` branch at 0x6d4 targets 0x73c, is taken when v0(=([a3] << 0x2)) < 0 (signed), and falls through when v0(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0x700 targets 0x6d0 and is always taken.
  The `beq` branch at 0x72c targets 0x6cc, is taken when v0(=ret(?)) == a2(=0x9), and falls through when v0(=ret(?)) != a2(=0x9).
  The `beq` branch at 0x734 targets 0x6e8 and is always taken.
  The `beq` branch at 0x75c targets 0x6d8, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `beq` branch at 0x768 targets 0x6d8, is taken when a3(=[ret(pciio_cardinfo_get)+56]:8) == 0, and falls through when a3(=[ret(pciio_cardinfo_get)+56]:8) != 0.
  The `beq` branch at 0x79c targets 0x6d8, is taken when v0(=ret(?)) == a2(=0x9), and falls through when v0(=ret(?)) != a2(=0x9).
  The `beq` branch at 0x7a4 targets 0x6e8 and is always taken.
  The return at 0x6f4 has v0 = one of 0x0, 0x9, ret(?).

- `pciio_error_devenable` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x7ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x7ac-0x7c8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7b4 calls pcibr_error_devenable with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7c0 has v0 = ret(pcibr_error_devenable).

- `pciio_provider_startup` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x7c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x7c8-0x7e4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7d0 calls pcibr_provider_startup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7dc has v0 = ret(pcibr_provider_startup).

- `pciio_provider_shutdown` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x7e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x7e4-0x800 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7ec calls pcibr_provider_shutdown with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7f8 has v0 = ret(pcibr_provider_shutdown).

- `pciio_endian_set` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x800 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x800-0x81c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x808 calls pcibr_endian_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x814 has v0 = ret(pcibr_endian_set).

- `pciio_priority_set` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x81c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x81c-0x838 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x824 calls pcibr_priority_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x830 has v0 = ret(pcibr_priority_set).

- `pciio_config_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x838 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x838-0x8f0 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x898 calls pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x870 targets 0x8c4, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x8bc targets 0x880, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0x8e8 has v0 = one of 0x0, ?.

- `pciio_config_get_safe` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x8f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x8f0-0x9a8 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x950 calls pcibr_config_get_safe with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x928 targets 0x97c, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x974 targets 0x938, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0x9a0 has v0 = one of 0x0, ?.

- `pciio_config_set` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x9a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x9a8-0xa40 (152 bytes).
  It occupies 152 bytes.
  The `jal` at 0xa00 calls pcibr_config_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x9dc targets 0xa1c, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa14 targets 0x9e4, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The return at 0xa38 has v0 = one of ?, ret(pcibr_config_set).

- `pciio_error_extract` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xa40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xa40-0xa5c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa48 calls pcibr_error_extract with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa54 has v0 = ret(pcibr_error_extract).

- `pciio_reset` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xa5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xa5c-0xa78 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa64 calls pcibr_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa70 has v0 = ret(pcibr_reset).

- `pciio_write_gather_flush` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xa78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xa78-0xa94 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80 calls pcibr_write_gather_flush with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa8c has v0 = ret(pcibr_write_gather_flush).

- `pciio_intr_dev_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xa94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xa94-0xa9c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa98 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xa94 has v0 = [a0+4].

- `pciio_pio_dev_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xa9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xa9c-0xaa4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xaa0 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xa9c has v0 = [a0+4].

- `pciio_pio_slot_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xaa4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xaa4-0xaac (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xaa8 loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xaa4 has v0 = [a0+8]:1.

- `pciio_pio_space_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xaac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xaac-0xab4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xab0 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xaac has v0 = [a0+12].

- `pciio_pio_pciaddr_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xab4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xab4-0xabc (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xab8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0xab4 has v0 = [a0+16]:8.

- `pciio_pio_mapsz_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xabc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xabc-0xac4 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xac0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xabc has v0 = [a0+24]:8.

- `pciio_pio_kvaddr_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xac4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xac4-0xacc (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xac8 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The return at 0xac4 has v0 = [a0+32]:8.

- `pciio_dma_dev_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xacc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xacc-0xad4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xad0 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xacc has v0 = [a0+4].

- `pciio_dma_slot_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xad4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xad4-0xadc (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xad8 loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xad4 has v0 = [a0+8]:1.

- `pciio_info_chk` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xadc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xadc-0xb08 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xaf0 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xb00 has v0 = ?.

- `pciio_info_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xb08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xb08-0xb60 (88 bytes).
  It occupies 88 bytes.
  The `ld` at 0xb24 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `jal` at 0xb14 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb50 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `beq` branch at 0xb1c targets 0xb30, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xb2c targets 0xb44, is taken when at(=[ret(hwgraph_fastinfo_get)]:8) != v0(=sym(pciio_info_fingerprint)), and falls through when at(=[ret(hwgraph_fastinfo_get)]:8) == v0(=sym(pciio_info_fingerprint)).
  The `beq` branch at 0xb58 targets 0xb34 and is always taken.
  The return at 0xb3c has v0 = ret(hwgraph_fastinfo_get).

- `pciio_hostinfo_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xb60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xb60-0xba4 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xb78 loads 4 bytes from ret(pciio_info_get) +0xc.
  The `lw` at 0xb7c loads 4 bytes from ret(pciio_info_get) +0x8.
  The `jal` at 0xb68 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb94 calls pciio_info_get with a0=[ret(pciio_info_get)+12], a1=?, a2=?, a3=ret(pciio_info_get).
  The `beq` branch at 0xb70 targets 0xb84, is taken when v0(=ret(pciio_info_get)) == 0, and falls through when v0(=ret(pciio_info_get)) != 0.
  The `bne` branch at 0xb80 targets 0xb94, is taken when at(=[ret(pciio_info_get)+8]) != a0(=[ret(pciio_info_get)+12]), and falls through when at(=[ret(pciio_info_get)+8]) == a0(=[ret(pciio_info_get)+12]).
  The `beq` branch at 0xb9c targets 0xb84 and is always taken.
  The return at 0xb8c has v0 = ret(pciio_info_get).

- `pciio_info_set` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xba4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xba4-0xbfc (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0xbc4 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0xbcc calls hwgraph_fastinfo_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sym(pciio_info_fingerprint), a3=a3 at entry (arg3).
  The `jal` at 0xbe0 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=?.
  The `beq` branch at 0xbbc targets 0xbc8, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0xbf4 has v0 = ret(hwgraph_info_add_LBL).

- `pciio_info_dev_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xbfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xbfc-0xc04 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc00 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xbfc has v0 = [a0+8].

- `pciio_info_hostdev_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc04-0xc0c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc08 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xc04 has v0 = [a0+12].

- `pciio_info_bus_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc0c-0xc14 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc10 loads 1 byte from a0 (arg0 at entry) +0x10.
  The return at 0xc0c has v0 = [a0+16]:1.

- `pciio_info_slot_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc14-0xc1c (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc18 loads 1 byte from a0 (arg0 at entry) +0x11.
  The return at 0xc14 has v0 = [a0+17]:1.

- `pciio_info_hostslot_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc1c-0xc48 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xc24 calls pciio_info_hostdev_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc2c calls pciio_info_get with a0=ret(pciio_info_hostdev_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc34 calls pciio_info_slot_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The return at 0xc40 has v0 = ret(pciio_info_slot_get).

- `pciio_info_function_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc48-0xc50 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xc4c loads 1 byte from a0 (arg0 at entry) +0x12.
  The return at 0xc48 has v0 = [a0+18]:1.

- `pciio_info_vendor_id_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc50-0xc58 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc54 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The return at 0xc50 has v0 = [a0+20].

- `pciio_info_device_id_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc58-0xc60 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc5c loads 4 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xc58 has v0 = [a0+24].

- `pciio_info_master_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc60-0xc68 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xc64 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The return at 0xc60 has v0 = [a0+28].

- `pciio_info_mfast_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc68-0xc70 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xc6c loads 8 bytes from a0 (arg0 at entry) +0x28.
  The return at 0xc68 has v0 = [a0+40]:8.

- `pciio_info_pops_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc70-0xc78 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xc74 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The return at 0xc70 has v0 = [a0+48]:8.

- `pciio_info_efunc_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc78-0xc80 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xc7c loads 8 bytes from a0 (arg0 at entry) +0x38.
  The return at 0xc78 has v0 = [a0+56]:8.

- `pciio_info_einfo_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc80-0xc88 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xc84 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The return at 0xc80 has v0 = [a0+64]:8.

- `pciio_info_bar_space_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xc88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xc88-0xca0 (24 bytes).
  It occupies 24 bytes.
  The `lw` at 0xc9c loads 4 bytes from ?.
  The return at 0xc98 has v0 = ?.

- `pciio_info_bar_base_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xca0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xca0-0xcb8 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0xcb4 loads 8 bytes from ?.
  The return at 0xcb0 has v0 = ?.

- `pciio_info_bar_size_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xcb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xcb8-0xcd0 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0xccc loads 8 bytes from ?.
  The return at 0xcc8 has v0 = ?.

- `pciio_info_rom_base_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xcd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xcd0-0xcd8 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xcd4 loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  The return at 0xcd0 has v0 = [a0+416]:8.

- `pciio_info_rom_size_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xcd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xcd8-0xce0 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xcdc loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The return at 0xcd8 has v0 = [a0+424]:8.

- `pciio_businfo_multi_master_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xce0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xce0-0xce8 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xce4 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0xce0 has v0 = [a0].

- `pciio_businfo_asic_type_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xce8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xce8-0xcf0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcec loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xce8 has v0 = [a0+4].

- `pciio_businfo_bus_type_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xcf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xcf0-0xcf8 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcf4 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xcf0 has v0 = [a0+8].

- `pciio_businfo_bus_speed_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xcf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xcf8-0xd00 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xcfc loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xcf8 has v0 = [a0+12].

- `pciio_init` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xd00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xd00-0xd58 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0xd1c calls cdl_new with a0=sym(.rodata), a1=sym(.rodata), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0xd30 calls compare_and_swap_ptr with a0=sym(pciio_registry), a1=0x0, a2=ret(cdl_new), a3=?.
  The `jal` at 0xd48 calls cdl_del with a0=ret(cdl_new), a1=?, a2=?, a3=?.
  The `bne` branch at 0xd08 targets 0xd3c, is taken when at(=[sym(pciio_registry)]:8) != 0, and falls through when at(=[sym(pciio_registry)]:8) == 0.
  The `beq` branch at 0xd38 targets 0xd48, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0xd50 targets 0xd40 and is always taken.
  The return at 0xd40 has v0 = one of ret(compare_and_swap_ptr), ?, ret(cdl_del).

- `pciio_attach` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xd58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xd58-0xd60 (8 bytes).
  It occupies 8 bytes.
  The return at 0xd58 has v0 = 0x0.

- `pciio_provider_register` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xd60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xd60-0xd84 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xd70 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0xd7c has v0 = ret(hwgraph_info_add_LBL).

- `pciio_provider_unregister` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xd84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xd84-0xda8 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xd94 calls hwgraph_info_remove_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xda0 has v0 = ret(hwgraph_info_remove_LBL).

- `pciio_provider_fns_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xda8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xda8-0xdd4 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xdbc calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xdcc has v0 = ?.

- `pciio_driver_register` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xdd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xdd4-0xe48 (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0xe14 calls cdl_add_driver with a0=[sym(pciio_registry)]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=sym(pciio_driver_reg_callback), a7=a1 at entry (arg1).
  The `jal` at 0xe2c calls pciio_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `beq` branch at 0xdfc targets 0xe2c, is taken when t1(=[sym(pciio_registry)]:8) == 0, and falls through when t1(=[sym(pciio_registry)]:8) != 0.
  The `beq` branch at 0xe40 targets 0xe04 and is always taken.
  The return at 0xe24 has v0 = ret(cdl_add_driver).

- `pciio_driver_unregister` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xe48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xe48-0xe6c (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xe58 calls cdl_del_driver with a0=[sym(pciio_registry)]:8, a1=a0 at entry (arg0), a2=sym(pciio_driver_unreg_callback), a3=a3 at entry (arg3).
  The return at 0xe64 has v0 = ret(cdl_del_driver).

- `pciio_driver_reg_callback` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xe6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xe6c-0xe88 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xe74 calls pcibr_driver_reg_callback with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xe80 has v0 = ret(pcibr_driver_reg_callback).

- `pciio_driver_unreg_callback` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xe88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xe88-0xea4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xe90 calls pcibr_driver_unreg_callback with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xe9c has v0 = ret(pcibr_driver_unreg_callback).

- `pciio_iterate` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xea4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xea4-0xef4 (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xec8 calls cdl_iterate with a0=[sym(pciio_registry)]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=?, a4=[sym(pciio_registry)]:8.
  The `jal` at 0xee0 calls pciio_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=[sym(pciio_registry)]:8.
  The `beq` branch at 0xebc targets 0xee0, is taken when a4(=[sym(pciio_registry)]:8) == 0, and falls through when a4(=[sym(pciio_registry)]:8) != 0.
  The `beq` branch at 0xeec targets 0xec4 and is always taken.
  The return at 0xed8 has v0 = ret(cdl_iterate).

- `pciio_device_register` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xef4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xef4-0xf28 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0xf04 calls pciio_device_info_new with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf10 calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pciio_device_info_new), a2=?, a3=?.
  The return at 0xf20 has v0 = ret(pciio_device_info_register).

- `pciio_device_unregister` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xf28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xf28-0xf44 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xf30 calls pcibr_device_unregister with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xf3c has v0 = ret(pcibr_device_unregister).

- `pciio_device_info_new` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xf44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xf44-0xffc (184 bytes).
  It occupies 184 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xf90, `sb` at 0xf94.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0xf98, `sw` at 0xf9c, `sw` at 0xfa0.
  8 such `sd` accesses store 8 bytes to ?, including `sd` at 0xfb0, `sd` at 0xfc0, `sd` at 0xfc4.
  The `jal` at 0xf78 calls kmem_zalloc with a0=0x200, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xfa4 calls hwgraph_fastinfo_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0xfb4 calls pciio_provider_fns_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `bne` branch at 0xf6c targets 0xf90, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0xff4 has v0 = ?.

- `pciio_device_info_free` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0xffc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0xffc-0x1018 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1004 calls bzero with a0=a0 at entry (arg0), a1=0x8, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1010 has v0 = ret(bzero).

- `pciio_device_info_register` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1018 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1018-0x109c (132 bytes).
  It occupies 132 bytes.
  The `lbu` at 0x1024 loads 1 byte from a1 (arg1 at entry) +0x11.
  The `lbu` at 0x103c loads 1 byte from a1 (arg1 at entry) +0x12.
  The `sw` at 0x1070 stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `sw` at 0x1078 stores 4 bytes to a1 (arg1 at entry) +0xc.
  The `lw` at 0x1088 loads 4 bytes from a1 (arg1 at entry) +0x1c.
  The `jal` at 0x1038 calls pciio_slot_func_to_name with a0=sp-64, a1=[a1+17]:1, a2=[a1+18]:1, a3=a3 at entry (arg3).
  The `jal` at 0x1048 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0x1080 calls pciio_info_set with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x108c calls device_master_set with a0=?, a1=[a1+28], a2=?, a3=?.
  The `beq` branch at 0x1050 targets 0x106c, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x1094 targets 0x105c and is always taken.
  The return at 0x1064 has v0 = ?.

- `pciio_device_info_unregister` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x109c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x109c-0x1118 (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0x10b8 loads 1 byte from a1 (arg1 at entry) +0x12.
  The `lbu` at 0x10bc loads 1 byte from a1 (arg1 at entry) +0x11.
  The `jal` at 0x10c0 calls pciio_slot_func_to_name with a0=sp-64, a1=[a1+17]:1, a2=[a1+18]:1, a3=a3 at entry (arg3), a4=a1 at entry (arg1).
  The `jal` at 0x10d0 calls hwgraph_edge_remove with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0x10dc calls pciio_info_set with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x10e4 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x10f8 calls hwgraph_edge_remove with a0=?, a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0x1100 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1108 calls hwgraph_vertex_destroy with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x10a8 targets 0x10b8, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x1110 targets 0x10b0 and is always taken.
  The return at 0x10b0 has v0 = one of ?, ret(hwgraph_vertex_destroy).

- `pciio_device_inventory_add` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1118 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1118-0x1164 (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0x1128 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0x1138 loads 4 bytes from ret(pciio_info_get) +0x18.
  The `lbu` at 0x114c loads 1 byte from ret(pciio_info_get) +0x11.
  The `jal` at 0x1120 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1150 calls device_inventory_add with a0=a0 at entry (arg0), a1=0xb, a2=0x4, a3=[ret(pciio_info_get)+20], a4=[ret(pciio_info_get)+24], a5=[ret(pciio_info_get)+17]:1.
  The `beq` branch at 0x1130 targets 0x115c, is taken when a3(=[ret(pciio_info_get)+20]) == a5(=-0x1), and falls through when a3(=[ret(pciio_info_get)+20]) != a5(=-0x1).
  The `beq` branch at 0x113c targets 0x115c, is taken when a4(=[ret(pciio_info_get)+24]) == a5(=-0x1), and falls through when a4(=[ret(pciio_info_get)+24]) != a5(=-0x1).
  The return at 0x115c has v0 = one of ret(pciio_info_get), ret(device_inventory_add).

- `pciio_device_inventory_remove` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1164 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1164-0x1190 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x117c calls hwgraph_inventory_remove with a0=a0 at entry (arg0), a1=-0x1, a2=-0x1, a3=-0x1, a4=-0x1, a5=-0x1.
  The return at 0x1188 has v0 = ret(hwgraph_inventory_remove).

- `pciio_device_attach` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1190 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1190-0x11e0 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x11b8 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0x11c0 loads 4 bytes from ret(pciio_info_get) +0x18.
  The `jal` at 0x11a4 calls pciio_device_inventory_add with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11ac calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x11c4 calls cdl_add_connpt with a0=[sym(pciio_registry)]:8, a1=[ret(pciio_info_get)+20], a2=[ret(pciio_info_get)+24], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0x11d8 has v0 = ret(cdl_add_connpt).

- `pciio_device_detach` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x11e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x11e0-0x1230 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x1208 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0x1210 loads 4 bytes from ret(pciio_info_get) +0x18.
  The `jal` at 0x11f4 calls pciio_device_inventory_remove with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11fc calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1214 calls cdl_del_connpt with a0=[sym(pciio_registry)]:8, a1=[ret(pciio_info_get)+20], a2=[ret(pciio_info_get)+24], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0x1228 has v0 = ret(cdl_del_connpt).

- `pciio_device_win_map_new` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1230 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1230-0x12a4 (116 bytes).
  It occupies 116 bytes.
  The `sw` at 0x1284 stores 4 bytes to ?.
  The `sd` at 0x1290 stores 8 bytes to ?.
  The `jal` at 0x1258 calls kmem_zalloc with a0=0x10, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1278 calls rmallocmap with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x124c targets 0x1264, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0x129c has v0 = ?.

- `pciio_device_win_map_free` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x12a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x12a4-0x12d8 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x12b8 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x12b4 calls rmfreemap with a0=[a0]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12c0 calls bzero with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The return at 0x12d0 has v0 = ret(bzero).

- `pciio_device_win_populate` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x12d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x12d8-0x131c (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x12d8 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x12f4 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x1308 calls rmfree with a0=[a0]:8, a1=?, a2=?, a3=a3 at entry (arg3).
  The return at 0x1314 has v0 = ret(rmfree).

- `pciio_device_win_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x131c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x131c-0x1408 (236 bytes).
  It occupies 236 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x131c, `lw` at 0x1394, `lw` at 0x13fc.
  The `ld` at 0x132c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x1388 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `sd` at 0x138c stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `sd` at 0x1390 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x1378 calls rmalloc_reserve with a0=[a0]:8, a1=?, a2=?, a3=0x0, a7=[a0+8].
  The `jal` at 0x13dc calls rmalloc_align with a0=[a0]:8, a1=?, a2=?, a3=0x1, a7=[a0+8].
  The `beq` branch at 0x1354 targets 0x13c0, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x1380 targets 0x1394, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0x13e8 targets 0x1400, is taken when v0(=ret(rmalloc_align)) == a5(=-0x1), and falls through when v0(=ret(rmalloc_align)) != a5(=-0x1).
  The `bne` branch at 0x13f0 targets 0x1388, is taken when s1(=a1) != 0, and falls through when s1(=a1) == 0.
  The `beq` branch at 0x13f8 targets 0x1398 and is always taken.
  The `beq` branch at 0x1400 targets 0x13a8 and is always taken.
  The return at 0x13b8 has v0 = one of ?, 0x0.

- `pciio_device_win_free` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1408 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1408-0x1438 (48 bytes).
  It occupies 48 bytes.
  The `ld` at 0x1408 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x141c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x1420 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x1428 loads 8 bytes from [a0]:8 +0x0.
  The `jal` at 0x1424 calls rmfree with a0=[[a0]:8]:8, a1=[a0+16]:8, a2=[a0+8]:8, a3=a3 at entry (arg3), a4=a0 at entry (arg0).
  The `beq` branch at 0x1414 targets 0x142c, is taken when a1(=[a0+16]:8) == 0, and falls through when a1(=[a0+16]:8) != 0.
  The return at 0x1430 has v0 = one of ?, ret(rmfree).

- `pciio_error_register` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1438 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1438-0x146c (52 bytes).
  It occupies 52 bytes.
  The `sd` at 0x1450 stores 8 bytes to ret(pciio_info_get) +0x38.
  The `sd` at 0x1468 stores 8 bytes to ret(pciio_info_get) +0x40.
  The `jal` at 0x1448 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1464 has v0 = ret(pciio_info_get).

- `pciio_slot_inuse` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x146c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x146c-0x14a0 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x147c loads 4 bytes from ret(pciio_info_get) +0x14.
  The `jal` at 0x1474 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1484 targets 0x1498, is taken when at(=[ret(pciio_info_get)+20]) == 0, and falls through when at(=[ret(pciio_info_get)+20]) != 0.
  The `beq` branch at 0x1498 targets 0x1490 and is always taken.
  The return at 0x1490 has v0 = one of 0x0, 0x1.

- `pciio_dma_enabled` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x14a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x14a0-0x14bc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x14a8 calls pcibr_dma_enabled with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14b4 has v0 = ret(pcibr_dma_enabled).

- `pciio_info_type1_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x14bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x14bc-0x14c4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0x14c0 loads 4 bytes from a0 (arg0 at entry) +0x1f8.
  The return at 0x14bc has v0 = [a0+504].

- `pciio_businfo_get` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x14c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x14c4-0x1514 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x14d8 loads 8 bytes from ret(pciio_info_get) +0x1f0.
  The `jal` at 0x14d0 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14e4 calls pciio_ppb_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x14f4 calls pcibr_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x14dc targets 0x14f4, is taken when at(=[ret(pciio_info_get)+496]:8) == 0, and falls through when at(=[ret(pciio_info_get)+496]:8) != 0.
  The `beq` branch at 0x14ec targets 0x1500 and is always taken.
  The return at 0x150c has v0 = one of ret(pciio_ppb_businfo_get), ret(pcibr_businfo_get).

- `pciio_latency_set` in `IP35/usr/cpu/sysgen/IP35boot/pciio.o` at 0x1514 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pciio.o`.
  Range: 0x1514-0x160c (248 bytes).
  It occupies 248 bytes.
  The `ld` at 0x154c loads 8 bytes from ret(pciio_info_get) +0x1f0.
  The `ld` at 0x1560 loads 8 bytes from [ret(pciio_info_get)+496]:8 +0x8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1584, `ld` at 0x1590, `ld` at 0x15f0.
  The `jal` at 0x152c calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1544 calls pciio_config_set with a0=a0 at entry (arg0), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x156c calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=?.
  The `jal` at 0x1594 calls pciio_info_dev_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x15a8 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=?.
  The `jal` at 0x15cc calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x15e4 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=a1 at entry (arg1).
  The `beq` branch at 0x1554 targets 0x15f4, is taken when s1(=[ret(pciio_info_get)+496]:8) == 0, and falls through when s1(=[ret(pciio_info_get)+496]:8) != 0.
  The `beq` branch at 0x155c targets 0x1594 and is always taken.
  The `bne` branch at 0x157c targets 0x15dc, is taken when at(?) < s0(=a1) (signed), and falls through when at(?) >= s0(=a1) (signed).
  The `beq` branch at 0x1588 targets 0x15f4, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x15b8 targets 0x1568, is taken when v0(?) >= s0(=a1) (signed), and falls through when v0(?) < s0(=a1) (signed).
  The `beq` branch at 0x15d4 targets 0x1568 and is always taken.
  The `beq` branch at 0x15ec targets 0x1588 and is always taken.
  The return at 0x1604 has v0 = one of ret(pciio_config_set), ?.
  The instructions from 0x1564 to 0x1564 are not reached by any path from the entry, and their branches are not listed.
