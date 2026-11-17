# Readings: `IP30/unix`

One entry per routine, filed here from the reading batches by binary.

- `dummy_func` in `IP30/unix` at 0xa800000020011300 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020011300-0xa800000020011308 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa800000020011300 has v0 = ?.

- `dummyret0_func` in `IP30/unix` at 0xa800000020011320 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020011320-0xa800000020011328 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa800000020011320 has v0 = 0x0.

- `_get_timestamp` in `IP30/unix` at 0xa800000020011328 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020011328-0xa800000020011334 (12 bytes).
  It occupies 12 bytes.
  The `lwu` at 0xa800000020011330 loads 4 bytes from abs 0xffffffffaff20004.
  The return at 0xa80000002001132c has v0 = [0xffffffffaff20004].

- `getcpuid` in `IP30/unix` at 0xa800000020011334.
  The routine is a leaf: it loads a doubleword from the uncached address 0xffffffffaff50000 (0xa80000002001133c) and returns
  it. The name suggests a processor id, but the facts show only a read of that address. Grade: inferred.
  Reviewed: 2026-11-12

- `_ticksper1024inst` in `IP30/unix` at 0xa8000000200115f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200115f0-0xa800000020011624 (52 bytes).
  It occupies 52 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0xa800000020011600, `ld` at 0xa800000020011618.
  The `bgtz` branch at 0xa800000020011608 targets 0xa800000020011608, is taken when t1(?) > 0 (signed), and falls through when t1(?) <= 0 (signed).
  The `bgtz` branch at 0xa800000020011610 targets 0xa800000020011604, is taken when a0(?) > 0 (signed), and falls through when a0(?) <= 0 (signed).
  The return at 0xa80000002001161c has v0 = ?.

- `heart_intr_low` in `IP30/unix` at 0xa80000002001167c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002001167c-0xa8000000200116ac (48 bytes).
  It occupies 48 bytes.
  Calls heart_intr [0xa80000002003fe98] via direct with a0=a0 at entry (arg0), a1=0xffff, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0xa80000002001167c).
  The instructions from 0xa800000020011684 to 0xa8000000200116a8 are not reached by any path from the entry, and their branches are not listed.

- `heart_intr_med` in `IP30/unix` at 0xa800000020011684 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020011684-0xa800000020011690 (12 bytes).
  It occupies 12 bytes.
  Calls heart_intr [0xa80000002003fe98] via direct with a0=a0 at entry (arg0), a1=0xffff0000, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0xa800000020011688).

- `heart_intr_hi` in `IP30/unix` at 0xa800000020011690 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020011690-0xa8000000200116a0 (16 bytes).
  It occupies 16 bytes.
  Calls heart_intr [0xa80000002003fe98] via direct with a0=a0 at entry (arg0), a1=0x3ffff00000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0xa800000020011698).

- `heart_intr_err` in `IP30/unix` at 0xa8000000200116a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200116a0-0xa8000000200116ac (12 bytes).
  It occupies 12 bytes.
  Calls heart_intr [0xa80000002003fe98] via direct with a0=a0 at entry (arg0), a1=0xfff8000000000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0xa8000000200116a4).

- `cpu_disable` in `IP30/unix` at 0xa800000020012a04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020012a04-0xa800000020012a34 (48 bytes).
  It occupies 48 bytes.
  The `ld` at 0xa800000020012a14 loads 8 bytes from abs 0xffffffffaff00000.
  The `sd` at 0xa800000020012a28 stores 8 bytes to abs 0xffffffffaff00000.
  The `sw` at 0xa800000020012a30 stores 4 bytes to table(0xa8000000204ae380) +0x0.
  The return at 0xa800000020012a2c has v0 = ?.

- `cpu_exists` in `IP30/unix` at 0xa800000020012a34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020012a34-0xa800000020012a54 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0xa800000020012a40 loads 8 bytes from abs 0xffffffffaff00080.
  The return at 0xa800000020012a4c has v0 = ?.

- `ip30_early_piotrans_addr` in `IP30/unix` at 0xa8000000200136b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200136b4-0xa800000020013808 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0xa8000000200136b8 loads 8 bytes from abs 0xffffffffaff00080.
  The `lw` at 0xa8000000200136d8 loads 4 bytes from (0x9000000000000000 | table(0x10000000)) +0x4.
  The `lw` at 0xa800000020013714 loads 4 bytes from abs 0x9000000010000004.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa800000020013754, `lw` at 0xa80000002001376c.
  The `jal` at 0xa80000002001379c calls heart_addr_xio_to_kva [0xa80000002003f290] with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200137e0 calls heart_addr_xio_to_kva [0xa80000002003f290] with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200137f8 calls heart_addr_xio_to_kva [0xa80000002003f290] with a0=0x0, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `bne` branch at 0xa8000000200136fc targets 0xa800000020013714, is taken when a0 != at(?), and falls through when a0 == at(?).
  The `bne` branch at 0xa800000020013704 targets 0xa800000020013714, is taken when a1 != a7(?), and falls through when a1 == a7(?).
  The `beq` branch at 0xa80000002001370c targets 0xa8000000200137d8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa800000020013724 targets 0xa800000020013744, is taken when a0 != t9(?), and falls through when a0 == t9(?).
  The `beq` branch at 0xa80000002001372c targets 0xa8000000200137c0 and is always taken.
  The `bne` branch at 0xa80000002001373c targets 0xa8000000200137ac, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa800000020013744 targets 0xa800000020013734, is taken when v0(?) == t0(?), and falls through when v0(?) != t0(?).
  The `beq` branch at 0xa80000002001375c targets 0xa800000020013734, is taken when (at(?) & 0x20) == 0, and falls through when (at(?) & 0x20) != 0.
  The `bne` branch at 0xa80000002001377c targets 0xa800000020013734, is taken when a0 != t8(?), and falls through when a0 == t8(?).
  The `bne` branch at 0xa800000020013784 targets 0xa800000020013734, is taken when a1 != a7(?), and falls through when a1 == a7(?).
  The `bne` branch at 0xa80000002001378c targets 0xa800000020013734, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xa8000000200137a4 targets 0xa8000000200137b0 and is always taken.
  The `bne` branch at 0xa8000000200137c0 targets 0xa800000020013744, is taken when a1 != a7(?), and falls through when a1 == a7(?).
  The `beq` branch at 0xa8000000200137c8 targets 0xa8000000200137f0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa8000000200137d0 targets 0xa800000020013744 and is always taken.
  The `beq` branch at 0xa8000000200137e8 targets 0xa8000000200137b0 and is always taken.
  The `beq` branch at 0xa800000020013800 targets 0xa8000000200137b0 and is always taken.
  The return at 0xa8000000200137b8 has v0 = one of ret(heart_addr_xio_to_kva), 0x0.

- `sendintr` in `IP30/unix` at 0xa800000020013a2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020013a2c-0xa800000020013a48 (28 bytes).
  It occupies 28 bytes.
  The `sd` at 0xa800000020013a3c stores 8 bytes to abs 0xffffffffaff10020.
  The return at 0xa800000020013a40 has v0 = 0x0.

- `intr_spray_heuristic` in `IP30/unix` at 0xa800000020013e50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020013e50-0xa800000020013f10 (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0xa800000020013ecc loads 8 bytes from table(0xa8000000204b0388) +0x0.
  The `lw` at 0xa800000020013ed0 loads 4 bytes from entry(0xa8000000204b0388) +0x48.
  The `lw` at 0xa800000020013ef4 loads 4 bytes from table(0xa8000000204a6850) +0x0.
  The `sw` at 0xa800000020013f0c stores 4 bytes to table(0xa8000000204a6850) +0x0.
  The `jal` at 0xa800000020013e60 calls device_desc_intr_target_get [0xa80000002013ead8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020013e74 calls cpuvertex_to_cpuid [0xa80000002023e298] with a0=ret(device_desc_intr_target_get), a1=[0xa8000000204a6850], a2=?, a3=?.
  The `jal` at 0xa800000020013e84 calls cpu_enabled [0xa800000020012a54] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020013eb4 calls cpu_enabled [0xa800000020012a54] with a0=?, a1=[0xa8000000204a6850], a2=?, a3=?.
  The `beq` branch at 0xa800000020013e58 targets 0xa800000020013ea8, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0xa800000020013e6c targets 0xa800000020013eac, is taken when v0(=ret(device_desc_intr_target_get)) == at(=-0x1), and falls through when v0(=ret(device_desc_intr_target_get)) != at(=-0x1).
  The `beq` branch at 0xa800000020013ea0 targets 0xa800000020013ee4 and is always taken.
  The `beq` branch at 0xa800000020013ebc targets 0xa800000020013ee0, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0xa800000020013ed8 targets 0xa800000020013ee8, is taken when (a2(=[entry(0xa8000000204b0388)+72]) & 0x80) == 0, and falls through when (a2(=[entry(0xa8000000204b0388)+72]) & 0x80) != 0.
  The return at 0xa800000020013f08 has v0 = ?.

- `heart_set_cpu_intr` in `IP30/unix` at 0xa800000020013f10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020013f10-0xa800000020013f24 (20 bytes).
  It occupies 20 bytes.
  The `sd` at 0xa800000020013f20 stores 8 bytes to abs 0xffffffffaff10020.
  The return at 0xa800000020013f1c has v0 = 0xffffffffaff10000.

- `heart_invalidate_war` in `IP30/unix` at 0xa8000000200140a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200140a4-0xa800000020014138 (148 bytes).
  It occupies 148 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0xa8000000200140b4, `ld` at 0xa8000000200140ec.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffffffc04f, including `lbu` at 0xa8000000200140c8, `lbu` at 0xa8000000200140f8.
  The `jal` at 0xa8000000200140d4 calls spl1 [0xa80000002001ba7c] with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200140e4 calls __heart_invalidate_war [0xa80000002001e3ec] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa800000020014104 calls splx [0xa80000002001bb64] with a0=?, a1=[-0x3fe0]:8, a2=?, a3=0x2.
  The `jal` at 0xa800000020014118 calls rt_unpin_thread [0xa80000002015e874] with a0=?, a1=[-0x3fe0]:8, a2=[-0x3fb1]:1, a3=0x2.
  The `jal` at 0xa800000020014128 calls rt_pin_thread [0xa80000002015e808] with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa8000000200140ac targets 0xa80000002001410c, is taken when at(=[0xa8000000204a6810]) == 0, and falls through when at(=[0xa8000000204a6810]) != 0.
  The `beq` branch at 0xa8000000200140c0 targets 0xa8000000200140d4, is taken when v0(=[-0x3fe0]:8) == 0, and falls through when v0(=[-0x3fe0]:8) != 0.
  The `beq` branch at 0xa8000000200140cc targets 0xa800000020014128, is taken when v1(=[-0x3fb1]:1) == a0(=0x2), and falls through when v1(=[-0x3fb1]:1) != a0(=0x2).
  The `beq` branch at 0xa8000000200140f0 targets 0xa800000020014104, is taken when a1(=[-0x3fe0]:8) == 0, and falls through when a1(=[-0x3fe0]:8) != 0.
  The `beq` branch at 0xa8000000200140fc targets 0xa800000020014118, is taken when a2(=[-0x3fb1]:1) == a3(=0x2), and falls through when a2(=[-0x3fb1]:1) != a3(=0x2).
  The `beq` branch at 0xa800000020014120 targets 0xa800000020014110 and is always taken.
  The `beq` branch at 0xa800000020014130 targets 0xa8000000200140e0 and is always taken.
  The return at 0xa800000020014110 has v0 = one of ?, ret(rt_unpin_thread).

- `tick_maint` in `IP30/unix` at 0xa800000020014fb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020014fb4-0xa800000020015018 (100 bytes).
  It occupies 100 bytes.
  The `lh` at 0xa800000020014fe0 loads 2 bytes from abs 0xffffffffffffc3a0.
  The `ld` at 0xa800000020014ff4 loads 8 bytes from abs 0xffffffffaff20000.
  The `jal` at 0xa800000020015008 calls (unnamed) [0xa800000020016030] with a0=?, a1=[0xa8000000204ae408], a2=0x1, a3=?.
  The `beq` branch at 0xa800000020014fc0 targets 0xa800000020014fe0, is taken when at(=[0xa8000000204af18c]) == a2(=0x1), and falls through when at(=[0xa8000000204af18c]) != a2(=0x1).
  The `beq` branch at 0xa800000020014fd0 targets 0xa800000020015008, is taken when v0(=[0xa8000000204ae408]-1) == 0, and falls through when v0(=[0xa8000000204ae408]-1) != 0.
  The `bne` branch at 0xa800000020014fe4 targets 0xa800000020014fcc, is taken when v1(=[-0x3c60]:2) != 0, and falls through when v1(=[-0x3c60]:2) == 0.
  The `beq` branch at 0xa800000020015000 targets 0xa800000020014fc8 and is always taken.
  The `beq` branch at 0xa800000020015010 targets 0xa800000020014fd8 and is always taken.
  The return at 0xa800000020014fd8 has v0 = one of [0xa8000000204ae408]-1, ret(0xa800000020016030).

- `__nanotime` in `IP30/unix` at 0xa800000020016030.
  This has the same shape as the IP27 `__nanotime` above, in the IP30 kernel. It takes a spinlock at
  0xa8000000204ae3d4 through mutex_spinlock_spl (0xa80000002001603c), reads the counter at the uncached address
  0xffffffffaff20000, and compares it with bases held in the words from 0xa8000000204ae3e8 to 0xa8000000204ae400. It
  compares values with 0x3b9aca00, which suggests the same seconds and sub-second split. It releases the lock with
  mutex_spinunlock at 0xa8000000200161cc and 0xa800000020016244. Grade: inferred.
  Reviewed: 2026-11-12

- `tstoclock` in `IP30/unix` at 0xa8000000200166a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200166a0-0xa8000000200166ec (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0xa8000000200166a0 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xa8000000200166b0 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xa8000000200166e0 loads 8 bytes from abs 0xffffffffaff20000.
  The `beq` branch at 0xa8000000200166cc targets 0xa8000000200166dc, is taken when a1 == v1(=0x1), and falls through when a1 != v1(=0x1).
  The return at 0xa8000000200166d4 has v0 = ?.
  The return at 0xa8000000200166e4 has v0 = ?.

- `tvtoclock` in `IP30/unix` at 0xa8000000200166ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200166ec-0xa80000002001674c (96 bytes).
  It occupies 96 bytes.
  The `lw` at 0xa8000000200166ec loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xa8000000200166fc loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xa800000020016740 loads 8 bytes from abs 0xffffffffaff20000.
  The `beq` branch at 0xa80000002001672c targets 0xa80000002001673c, is taken when a1 == v1(=0x1), and falls through when a1 != v1(=0x1).
  The return at 0xa800000020016734 has v0 = ?.
  The return at 0xa800000020016744 has v0 = ?.

- `find_pclk_freq` in `IP30/unix` at 0xa800000020018014 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020018014-0xa800000020018134 (288 bytes).
  It occupies 288 bytes.
  11 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0xa80000002001803c, `ld` at 0xa800000020018040, `ld` at 0xa80000002001804c.
  The `jal` at 0xa800000020018030 calls spl65 [0xa80000002001bb14] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020018070 calls _get_count [0xa800000020026a90] with a0=?, a1=?, a2=?, a3=[0xffffffffaff20000]:8.
  The `jal` at 0xa8000000200180e0 calls _get_count [0xa800000020026a90] with a0=?, a1=?, a2=?, a3=[0xffffffffaff20000]:8+12500.
  The `jal` at 0xa8000000200180ec calls splx [0xa80000002001bb64] with a0=ret(spl65), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002001801c targets 0xa80000002001802c, is taken when v0(=[0xa8000000204ae430]) == 0, and falls through when v0(=[0xa8000000204ae430]) != 0.
  The `bne` branch at 0xa800000020018044 targets 0xa800000020018070, is taken when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8).
  The `bne` branch at 0xa800000020018050 targets 0xa800000020018070, is taken when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8).
  The `bne` branch at 0xa80000002001805c targets 0xa800000020018070, is taken when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8).
  The `beq` branch at 0xa800000020018068 targets 0xa80000002001804c, is taken when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8).
  The `beq` branch at 0xa800000020018084 targets 0xa8000000200180dc, is taken when at(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when at(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa800000020018094 targets 0xa8000000200180dc, is taken when v0(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when v0(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa8000000200180a4 targets 0xa8000000200180dc, is taken when v1(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when v1(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa8000000200180b4 targets 0xa8000000200180dc, is taken when a0(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when a0(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa8000000200180c4 targets 0xa8000000200180dc, is taken when a1(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when a1(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `bne` branch at 0xa8000000200180d4 targets 0xa80000002001808c, is taken when a2(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when a2(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa80000002001812c targets 0xa800000020018024 and is always taken.
  The return at 0xa800000020018024 has v0 = one of [0xa8000000204ae430], ?.

- `heartclock_intr` in `IP30/unix` at 0xa80000002001823c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002001823c-0xa800000020018250 (20 bytes).
  It occupies 20 bytes.
  The `sd` at 0xa80000002001824c stores 8 bytes to abs 0xffffffffaff10028.
  The return at 0xa800000020018248 has v0 = 0xffffffffaff10000.

- `update_ust` in `IP30/unix` at 0xa80000002001a3c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002001a3c0-0xa80000002001a3d4 (20 bytes).
  It occupies 20 bytes.
  The `ld` at 0xa80000002001a3c8 loads 8 bytes from abs 0xffffffffaff20000.
  The `sd` at 0xa80000002001a3d0 stores 8 bytes to abs 0xa8000000204a68c0 (ust_val).
  The return at 0xa80000002001a3cc has v0 = [0xffffffffaff20000]:8.

- `flushbus` in `IP30/unix` at 0xa80000002001c1c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002001c1c4-0xa80000002001c1e4 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0xa80000002001c1c8 loads 8 bytes from abs 0xffffffffaff50000.
  The `ld` at 0xa80000002001c1d0 loads 8 bytes from abs 0xffffffffb8000000.
  The return at 0xa80000002001c1dc has v0 = ?.

- `baerror` in `IP30/unix` at 0xa80000002001c908 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002001c908-0xa80000002001c964 (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0xa80000002001c90c loads 8 bytes from abs 0xffffffffb8000060.
  The `sd` at 0xa80000002001c910 stores 8 bytes to abs 0xffffffffb8000040.
  The `ld` at 0xa80000002001c914 loads 8 bytes from abs 0xffffffffb8000000.
  The `sd` at 0xa80000002001c918 stores 8 bytes to abs 0xffffffffb8000060.
  The `ld` at 0xa80000002001c924 loads 8 bytes from abs 0xffffffffaff10040.
  The `sd` at 0xa80000002001c928 stores 8 bytes to abs 0xffffffffaff10040.
  The `ld` at 0xa80000002001c930 loads 8 bytes from abs 0xffffffffaff50000.
  The `ld` at 0xa80000002001c938 loads 8 bytes from abs 0xffffffffffffc020.
  The `sh` at 0xa80000002001c944 stores 2 bytes to [-0x3fe0]:8 +0xf6.
  The `sw` at 0xa80000002001c950 stores 4 bytes to abs 0xffffffffffffc404.
  The `beq` branch at 0xa80000002001c93c targets 0xa80000002001c950, is taken when t2(=[-0x3fe0]:8) == 0, and falls through when t2(=[-0x3fe0]:8) != 0.
  The `beq` branch at 0xa80000002001c948 targets 0xa80000002001c954 and is always taken.
  The return at 0xa80000002001c95c has v0 = 0x1.

- `earlybaerror` in `IP30/unix` at 0xa80000002001c964 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002001c964-0xa80000002001c9c4 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0xa80000002001c968 loads 8 bytes from abs 0xffffffffb8000060.
  The `sd` at 0xa80000002001c96c stores 8 bytes to abs 0xffffffffb8000040.
  The `ld` at 0xa80000002001c970 loads 8 bytes from abs 0xffffffffb8000000.
  The `sd` at 0xa80000002001c974 stores 8 bytes to abs 0xffffffffb8000060.
  The `ld` at 0xa80000002001c980 loads 8 bytes from abs 0xffffffffaff10040.
  The `sd` at 0xa80000002001c984 stores 8 bytes to abs 0xffffffffaff10040.
  The `ld` at 0xa80000002001c98c loads 8 bytes from abs 0xffffffffaff50000.
  The `sw` at 0xa80000002001c9b0 stores 4 bytes to abs 0xa8000000204af10c (nofault).
  The return at 0xa80000002001c9bc has v0 = 0x1.

- `_ecc_errorvec` in `IP30/unix` at 0xa80000002001dd30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002001dd30-0xa80000002001dd98 (104 bytes).
  It occupies 104 bytes.
  The `ld` at 0xa80000002001dd4c loads 8 bytes from abs 0xffffffffaff50000.
  The `ld` at 0xa80000002001dd54 loads 8 bytes from ([0xffffffffaff50000]:8 << 0x3) +0xff0.
  The `sd` at 0xa80000002001dd58 stores 8 bytes to [([0xffffffffaff50000]:8 << 0x3)+4080]:8 +0xc8.
  The `sd` at 0xa80000002001dd5c stores 8 bytes to [([0xffffffffaff50000]:8 << 0x3)+4080]:8 +0x0.
  Calls (unnamed) [0x900000002001a3e0] via register-constant with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`jr` at 0xa80000002001dd90).

- `VEC_dbe` in `IP30/unix` at 0xa800000020026960 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020026960-0xa8000000200269b8 (88 bytes).
  It occupies 88 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffaff50000, including `ld` at 0xa800000020026964, `ld` at 0xa80000002002699c.
  The `ld` at 0xa800000020026980 loads 8 bytes from ([0xffffffffaff50000]:8 << 0x3) -0x500f0000.
  The `sd` at 0xa800000020026994 stores 8 bytes to ([0xffffffffaff50000]:8 << 0x3) -0x500f0000.
  The `ld` at 0xa8000000200269a4 loads 8 bytes from abs 0xffffffffb8000000.
  The `lh` at 0xa8000000200269ac loads 2 bytes from abs 0xffffffffffffc3a0.
  The `sd` at 0xa8000000200269b4 stores 8 bytes to a0 (arg0 at entry) +0x140.
  Calls VEC_trap [0xa80000002001b9d0] via direct with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0xa8000000200269b0).

- `VEC_ibe` in `IP30/unix` at 0xa80000002002bf70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002002bf70-0xa80000002002bfe0 (112 bytes).
  It occupies 112 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002002bf70, `ld` at 0xa80000002002bf74.
  The `sd` at 0xa80000002002bf88 stores 8 bytes to ?.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffaff50000, including `ld` at 0xa80000002002bf90, `ld` at 0xa80000002002bfc4.
  The `ld` at 0xa80000002002bfa8 loads 8 bytes from ([0xffffffffaff50000]:8 << 0x3) -0x500f0000.
  The `sd` at 0xa80000002002bfbc stores 8 bytes to ([0xffffffffaff50000]:8 << 0x3) -0x500f0000.
  The `ld` at 0xa80000002002bfcc loads 8 bytes from abs 0xffffffffb8000000.
  The `lh` at 0xa80000002002bfd4 loads 2 bytes from abs 0xffffffffffffc3a0.
  The `sd` at 0xa80000002002bfdc stores 8 bytes to a0 (arg0 at entry) +0x140.
  Calls VEC_trap [0xa80000002001b9d0] via direct with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3) (`j` at 0xa80000002002bfd8).
  The `bgez` branch at 0xa80000002002bf78 targets 0xa80000002002bf84, is taken when ra(?) >= 0 (signed), and falls through when ra(?) < 0 (signed).

- `intr_mark_inuse_urb` in `IP30/unix` at 0xa800000020030db4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020030db4-0xa800000020030e34 (128 bytes).
  It occupies 128 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xa800000020030dc4, `lw` at 0xa800000020030ddc, `lw` at 0xa800000020030df0.
  The `jal` at 0xa800000020030df8 calls compare_and_swap_int [0xa800000020016c08] with a0=a0 at entry (arg0), a1=?, a2=([a0] | 0x10), a3=a3 at entry (arg3).
  The `beq` branch at 0xa800000020030dcc targets 0xa800000020030e18, is taken when (at(=[a0]) & 0x1) == 0, and falls through when (at(=[a0]) & 0x1) != 0.
  The `beq` branch at 0xa800000020030e00 targets 0xa800000020030e18, is taken when v0(=ret(compare_and_swap_int)) == 0, and falls through when v0(=ret(compare_and_swap_int)) != 0.
  The `beq` branch at 0xa800000020030e10 targets 0xa800000020030e20 and is always taken.
  The return at 0xa800000020030e2c has v0 = one of 0x0, 0x1.

- `nic_setup` in `IP30/unix` at 0xa800000020039218 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020039218-0xa800000020039240 (40 bytes).
  It occupies 40 bytes.
  The `sd` at 0xa800000020039218 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `sd` at 0xa80000002003921c stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sw` at 0xa800000020039220 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0xa800000020039230 stores 4 bytes to a0 (arg0 at entry) +0x14.
  The `jal` at 0xa80000002003922c calls (unnamed) [0xa800000020038ec0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020039238 has v0 = ret(0xa800000020038ec0).

- `nic_next` in `IP30/unix` at 0xa800000020039240 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020039240-0xa8000000200393d0 (400 bytes).
  It occupies 400 bytes.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0xa80000002003929c, `sb` at 0xa8000000200392b0, `sb` at 0xa8000000200392c8.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa8000000200392e4, `lbu` at 0xa8000000200392f0, `lbu` at 0xa800000020039320.
  The `lw` at 0xa800000020039334 loads 4 bytes from ?.
  The `sb` at 0xa800000020039378 stores 1 byte to a1 (arg1 at entry) +0x4.
  The `sb` at 0xa80000002003937c stores 1 byte to a1 (arg1 at entry) +0x0.
  The `sb` at 0xa800000020039390 stores 1 byte to a1 (arg1 at entry) +0x1.
  The `sb` at 0xa800000020039394 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `sb` at 0xa800000020039398 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `sb` at 0xa8000000200393a0 stores 1 byte to a1 (arg1 at entry) +0x5.
  The `sb` at 0xa8000000200393ac stores 1 byte to a3 (arg3 at entry) +0x0.
  The `sb` at 0xa8000000200393c4 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `jal` at 0xa800000020039260 calls (unnamed) [0xa800000020039034] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa80000002003926c targets 0xa800000020039288, is taken when v0(=ret(0xa800000020039034)) == 0, and falls through when v0(=ret(0xa800000020039034)) != 0.
  The `beq` branch at 0xa8000000200392a0 targets 0xa8000000200392cc, is taken when a6(?) >= 0x8 (signed), and falls through when a6(?) < 0x8 (signed).
  The `beq` branch at 0xa8000000200392b4 targets 0xa8000000200392cc, is taken when a6(?) >= 0x8 (signed), and falls through when a6(?) < 0x8 (signed).
  The `bne` branch at 0xa8000000200392c4 targets 0xa800000020039290, is taken when a6(?) < 0x8 (signed), and falls through when a6(?) >= 0x8 (signed).
  The `bne` branch at 0xa800000020039304 targets 0xa8000000200392d0, is taken when a6(?) < 0x40 (signed), and falls through when a6(?) >= 0x40 (signed).
  The `bne` branch at 0xa800000020039350 targets 0xa80000002003931c, is taken when a7(?) < 0x8 (signed), and falls through when a7(?) >= 0x8 (signed).
  The `beq` branch at 0xa800000020039358 targets 0xa800000020039368, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa800000020039360 targets 0xa800000020039278 and is always taken.
  The `beq` branch at 0xa80000002003936c targets 0xa8000000200393b8, is taken when t8(=a1) == 0, and falls through when t8(=a1) != 0.
  The `bne` branch at 0xa80000002003939c targets 0xa8000000200393c0, is taken when s2(=a2) != 0, and falls through when s2(=a2) == 0.
  The `beq` branch at 0xa8000000200393a4 targets 0xa8000000200393b0, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0xa8000000200393b0 targets 0xa800000020039274 and is always taken.
  The `beq` branch at 0xa8000000200393b8 targets 0xa8000000200393a4, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0xa8000000200393c0 targets 0xa8000000200393a8, is taken when s1(=a3) != 0, and falls through when s1(=a3) == 0.
  The `beq` branch at 0xa8000000200393c8 targets 0xa8000000200393b0 and is always taken.
  The return at 0xa800000020039280 has v0 = one of ?, 0x3.

- `nic_read_one_page` in `IP30/unix` at 0xa80000002003950c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003950c-0xa80000002003969c (400 bytes).
  It occupies 400 bytes.
  The `lbu` at 0xa800000020039524 loads 1 byte from (a4 + a5) +0x0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa800000020039560, `lbu` at 0xa80000002003961c.
  The `lbu` at 0xa8000000200395dc loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0xa800000020039604 stores 1 byte to ?.
  The `jal` at 0xa800000020039570 calls (unnamed) [0xa8000000200393d0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003959c calls (unnamed) [0xa800000020038f5c] with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0xa8000000200395b4 calls (unnamed) [0xa800000020038f5c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200395cc calls (unnamed) [0xa800000020038f5c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200395e8 calls (unnamed) [0xa800000020038fd0] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020039618 calls (unnamed) [0xa800000020038e58] with a0=?, a1=sp-64, a2=?, a3=?.
  The `jal` at 0xa80000002003964c calls printf [0xa8000000201c78ec] with a0=0xa8000000203aef18, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003966c calls (unnamed) [0xa800000020038fd0] with a0=a0 at entry (arg0), a1=?, a2=[a1]:1, a3=0x9.
  The `beq` branch at 0xa800000020039544 targets 0xa80000002003956c, is taken when t1(=0xff) == t2(=[(a4 + a5)]:1), and falls through when t1(=0xff) != t2(=[(a4 + a5)]:1).
  The `beq` branch at 0xa800000020039554 targets 0xa800000020039648, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xa800000020039564 targets 0xa800000020039550, is taken when t1(=0xff) != t0(?), and falls through when t1(=0xff) == t0(?).
  The `beq` branch at 0xa800000020039578 targets 0xa80000002003959c, is taken when v0(=ret(0xa8000000200393d0)) == 0, and falls through when v0(=ret(0xa8000000200393d0)) != 0.
  The `bltz` branch at 0xa8000000200395a4 targets 0xa80000002003965c, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `bltz` branch at 0xa8000000200395bc targets 0xa800000020039664, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `bltz` branch at 0xa8000000200395d4 targets 0xa800000020039694, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `beq` branch at 0xa8000000200395e0 targets 0xa80000002003966c, is taken when a2(=[a1]:1) == a3(=0x9), and falls through when a2(=[a1]:1) != a3(=0x9).
  The `bltz` branch at 0xa8000000200395f0 targets 0xa800000020039684, is taken when v0(=ret(0xa800000020038fd0)) < 0 (signed), and falls through when v0(=ret(0xa800000020038fd0)) >= 0 (signed).
  The `bne` branch at 0xa800000020039600 targets 0xa8000000200395e8, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `bne` branch at 0xa800000020039628 targets 0xa800000020039614, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `beq` branch at 0xa800000020039638 targets 0xa80000002003968c, is taken when a2(?) == a3(=0xb001), and falls through when a2(?) != a3(=0xb001).
  The `beq` branch at 0xa800000020039640 targets 0xa800000020039584 and is always taken.
  The `beq` branch at 0xa800000020039654 targets 0xa800000020039580 and is always taken.
  The `beq` branch at 0xa80000002003965c targets 0xa800000020039584 and is always taken.
  The `beq` branch at 0xa800000020039664 targets 0xa800000020039584 and is always taken.
  The `bgez` branch at 0xa800000020039674 targets 0xa8000000200395e8, is taken when v0(=ret(0xa800000020038fd0)) >= 0 (signed), and falls through when v0(=ret(0xa800000020038fd0)) < 0 (signed).
  The `beq` branch at 0xa80000002003967c targets 0xa800000020039584 and is always taken.
  The `beq` branch at 0xa800000020039684 targets 0xa800000020039584 and is always taken.
  The `beq` branch at 0xa80000002003968c targets 0xa800000020039580 and is always taken.
  The `beq` branch at 0xa800000020039694 targets 0xa800000020039584 and is always taken.
  The return at 0xa800000020039594 has v0 = one of ?, 0x3, ret(0xa800000020038f5c), ret(0xa800000020038fd0).

- `nic_read_mfg` in `IP30/unix` at 0xa80000002003969c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003969c-0xa8000000200399b0 (788 bytes).
  It occupies 788 bytes.
  The `lbu` at 0xa8000000200396c0 loads 1 byte from a1 (arg1 at entry) +0x0.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0xa800000020039700, `sb` at 0xa800000020039718, `sb` at 0xa800000020039730.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa800000020039844, `lbu` at 0xa800000020039888, `lbu` at 0xa8000000200398a8.
  The `jal` at 0xa80000002003974c calls nic_read_one_page [0xa80000002003950c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x0, a5=sp-208, a6=a4 at entry (arg4).
  The `jal` at 0xa80000002003978c calls (unnamed) [0xa8000000200393d0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200397bc calls nic_read_one_page [0xa80000002003950c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1, a5=sp-208, a6=a5 at entry (arg5).
  The `jal` at 0xa8000000200397d4 calls (unnamed) [0xa800000020038f5c] with a0=a0 at entry (arg0), a1=0xaa, a2=?, a3=?.
  The `jal` at 0xa8000000200397e8 calls (unnamed) [0xa800000020038f5c] with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xa8000000200397fc calls (unnamed) [0xa800000020038f5c] with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0xa800000020039820 calls (unnamed) [0xa800000020038e58] with a0=0x0, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xa80000002003982c calls (unnamed) [0xa800000020038e58] with a0=0x1, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xa800000020039840 calls (unnamed) [0xa800000020038e58] with a0=?, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xa8000000200398cc calls (unnamed) [0xa800000020038fd0] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020039900 calls (unnamed) [0xa800000020038e58] with a0=0xaa, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xa800000020039930 calls printf [0xa8000000201c78ec] with a0=0xa8000000203aef48, a1=?, a2=0xb001, a3=?.
  The `jal` at 0xa800000020039958 calls nic_read_one_page [0xa80000002003950c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x0, a5=sp-208, a6=a4 at entry (arg4).
  The `jal` at 0xa800000020039980 calls nic_read_one_page [0xa80000002003950c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1, a5=sp-208, a6=a5 at entry (arg5).
  The `bne` branch at 0xa8000000200396e0 targets 0xa80000002003978c, is taken when at(=[a1]:1) != v0(=0x9), and falls through when at(=[a1]:1) == v0(=0x9).
  The `beq` branch at 0xa800000020039704 targets 0xa800000020039738, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `beq` branch at 0xa80000002003971c targets 0xa800000020039734, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `bne` branch at 0xa80000002003972c targets 0xa8000000200396f4, is taken when v0(?) < 0x40 (signed), and falls through when v0(?) >= 0x40 (signed).
  The `beq` branch at 0xa800000020039754 targets 0xa8000000200397a4, is taken when v0(=ret(nic_read_one_page)) == 0, and falls through when v0(=ret(nic_read_one_page)) != 0.
  The `beq` branch at 0xa800000020039794 targets 0xa8000000200397d0, is taken when v0(=ret(0xa8000000200393d0)) == 0, and falls through when v0(=ret(0xa8000000200393d0)) != 0.
  The `beq` branch at 0xa80000002003979c targets 0xa800000020039760 and is always taken.
  The `beq` branch at 0xa8000000200397c8 targets 0xa80000002003975c and is always taken.
  The `bltz` branch at 0xa8000000200397dc targets 0xa800000020039918, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `bltz` branch at 0xa8000000200397f0 targets 0xa800000020039920, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `bltz` branch at 0xa800000020039808 targets 0xa800000020039998, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `beq` branch at 0xa800000020039818 targets 0xa8000000200398c8 and is always taken.
  The `bne` branch at 0xa800000020039850 targets 0xa800000020039838, is taken when s2(?) < 0xa (signed), and falls through when s2(?) >= 0xa (signed).
  The `bne` branch at 0xa80000002003985c targets 0xa800000020039928, is taken when a2(=0xb001) != a3(?), and falls through when a2(=0xb001) == a3(?).
  The `beq` branch at 0xa800000020039894 targets 0xa8000000200398b8, is taken when v0(?) >= 0x8 (signed), and falls through when v0(?) < 0x8 (signed).
  The `bne` branch at 0xa8000000200398b0 targets 0xa800000020039878, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa8000000200398c0 targets 0xa800000020039940, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0xa8000000200398d8 targets 0xa800000020039910, is taken when v0(=ret(0xa800000020038fd0)) < 0 (signed), and falls through when v0(=ret(0xa800000020038fd0)) >= 0 (signed).
  The `bne` branch at 0xa8000000200398e8 targets 0xa8000000200398cc, is taken when s2(?) < 0xa (signed), and falls through when s2(?) >= 0xa (signed).
  The `bne` branch at 0xa8000000200398f4 targets 0xa800000020039834, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xa800000020039908 targets 0xa800000020039820 and is always taken.
  The `beq` branch at 0xa800000020039910 targets 0xa800000020039760 and is always taken.
  The `beq` branch at 0xa800000020039918 targets 0xa800000020039760 and is always taken.
  The `beq` branch at 0xa800000020039920 targets 0xa800000020039760 and is always taken.
  The `beq` branch at 0xa800000020039938 targets 0xa80000002003975c and is always taken.
  The `bltz` branch at 0xa800000020039960 targets 0xa8000000200399a0, is taken when v0(=ret(nic_read_one_page)) < 0 (signed), and falls through when v0(=ret(nic_read_one_page)) >= 0 (signed).
  The `bltz` branch at 0xa800000020039988 targets 0xa8000000200399a8, is taken when v0(=ret(nic_read_one_page)) < 0 (signed), and falls through when v0(=ret(nic_read_one_page)) >= 0 (signed).
  The `beq` branch at 0xa800000020039990 targets 0xa80000002003975c and is always taken.
  The `beq` branch at 0xa800000020039998 targets 0xa800000020039760 and is always taken.
  The `beq` branch at 0xa8000000200399a0 targets 0xa800000020039760 and is always taken.
  The `beq` branch at 0xa8000000200399a8 targets 0xa800000020039760 and is always taken.
  The return at 0xa800000020039784 has v0 = one of ?, ret(0xa8000000200393d0), ret(0xa800000020038fd0), ret(0xa800000020038f5c), ret(nic_read_one_page).

- `nic_eaddr` in `IP30/unix` at 0xa800000020039bc8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020039bc8-0xa800000020039e3c (628 bytes).
  It occupies 628 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xa800000020039d0c, `sb` at 0xa800000020039dc0.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa800000020039d28, `lbu` at 0xa800000020039d7c, `lbu` at 0xa800000020039db8.
  The `jal` at 0xa800000020039bec calls nic_setup [0xa800000020039218] with a0=sp-176, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a5=a1 at entry (arg1).
  The `jal` at 0xa800000020039c04 calls printf [0xa8000000201c78ec] with a0=0xa8000000203aefc8, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020039c0c calls printf [0xa8000000201c78ec] with a0=0xa8000000203aeff0, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020039c30 calls printf [0xa8000000201c78ec] with a0=0xa8000000203aefa0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a1 at entry (arg1).
  The `jal` at 0xa800000020039c4c calls nic_next [0xa800000020039240] with a0=sp-176, a1=sp-48, a2=sp-42, a3=sp-41.
  The `jal` at 0xa800000020039cbc calls (unnamed) [0xa800000020038f5c] with a0=sp-176, a1=0xf0, a2=?, a3=?.
  The `jal` at 0xa800000020039ccc calls (unnamed) [0xa800000020038f5c] with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020039cdc calls (unnamed) [0xa800000020038f5c] with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020039cec calls (unnamed) [0xa800000020038fd0] with a0=sp-176, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020039d24 calls (unnamed) [0xa800000020038e58] with a0=?, a1=sp-40, a2=?, a3=?.
  The `jal` at 0xa800000020039d78 calls (unnamed) [0xa800000020038e58] with a0=?, a1=sp-40, a2=?, a3=?.
  The `beq` branch at 0xa800000020039bdc targets 0xa800000020039c2c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xa800000020039bf4 targets 0xa800000020039c40, is taken when v0(=ret(nic_setup)) == 0, and falls through when v0(=ret(nic_setup)) != 0.
  The `blez` branch at 0xa800000020039bfc targets 0xa800000020039c18, is taken when v0(=ret(nic_setup)) <= 0 (signed), and falls through when v0(=ret(nic_setup)) > 0 (signed).
  The `beq` branch at 0xa800000020039c38 targets 0xa800000020039c1c and is always taken.
  The `beq` branch at 0xa800000020039c54 targets 0xa800000020039c64, is taken when v0(=ret(nic_next)) == 0, and falls through when v0(=ret(nic_next)) != 0.
  The `beq` branch at 0xa800000020039c5c targets 0xa800000020039c20 and is always taken.
  The `bne` branch at 0xa800000020039c6c targets 0xa800000020039c9c, is taken when v0(?) < 0xa (signed), and falls through when v0(?) >= 0xa (signed).
  The `bne` branch at 0xa800000020039c74 targets 0xa800000020039cb8, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0xa800000020039c7c targets 0xa800000020039de8, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xa800000020039c84 targets 0xa800000020039cb8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xa800000020039c8c targets 0xa800000020039c44, is taken when a5(=0x91) != v0(?), and falls through when a5(=0x91) == v0(?).
  The `beq` branch at 0xa800000020039c94 targets 0xa800000020039cbc and is always taken.
  The `bne` branch at 0xa800000020039ca0 targets 0xa800000020039dcc, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `bne` branch at 0xa800000020039ca8 targets 0xa800000020039cb8, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xa800000020039cb0 targets 0xa800000020039c44, is taken when t0(=0x9) != v0(?), and falls through when t0(=0x9) == v0(?).
  The `bltz` branch at 0xa800000020039cc4 targets 0xa800000020039e24, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `bltz` branch at 0xa800000020039cd4 targets 0xa800000020039e2c, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `bltz` branch at 0xa800000020039ce4 targets 0xa800000020039e34, is taken when v0(=ret(0xa800000020038f5c)) < 0 (signed), and falls through when v0(=ret(0xa800000020038f5c)) >= 0 (signed).
  The `bltz` branch at 0xa800000020039cf8 targets 0xa800000020039e1c, is taken when v0(=ret(0xa800000020038fd0)) < 0 (signed), and falls through when v0(=ret(0xa800000020038fd0)) >= 0 (signed).
  The `bne` branch at 0xa800000020039d08 targets 0xa800000020039cec, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xa800000020039d34 targets 0xa800000020039d1c, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xa800000020039d44 targets 0xa800000020039c44, is taken when a2(=0x8d) != a3(?), and falls through when a2(=0x8d) == a3(?).
  The `bne` branch at 0xa800000020039d54 targets 0xa800000020039c40, is taken when a4(=0xb001) != a5(?), and falls through when a4(=0xb001) == a5(?).
  The `bne` branch at 0xa800000020039d60 targets 0xa800000020039c40, is taken when a6(=0xa) != a7(?), and falls through when a6(=0xa) == a7(?).
  The `bne` branch at 0xa800000020039d88 targets 0xa800000020039d6c, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xa800000020039d94 targets 0xa800000020039c44, is taken when a2(=0xb001) != a3(?), and falls through when a2(=0xb001) == a3(?).
  The `bne` branch at 0xa800000020039dbc targets 0xa800000020039da0, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `beq` branch at 0xa800000020039dc4 targets 0xa800000020039c1c and is always taken.
  The `bne` branch at 0xa800000020039dd0 targets 0xa800000020039e08, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `beq` branch at 0xa800000020039dd8 targets 0xa800000020039c44, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xa800000020039de0 targets 0xa800000020039cbc and is always taken.
  The `bne` branch at 0xa800000020039dec targets 0xa800000020039c44, is taken when v0(?) < 0xc (signed), and falls through when v0(?) >= 0xc (signed).
  The `beq` branch at 0xa800000020039df8 targets 0xa800000020039c44, is taken when v0(?) >= 0xd (signed), and falls through when v0(?) < 0xd (signed).
  The `beq` branch at 0xa800000020039e00 targets 0xa800000020039cbc and is always taken.
  The `bne` branch at 0xa800000020039e0c targets 0xa800000020039c44, is taken when t2(=0x4) != v0(?), and falls through when t2(=0x4) == v0(?).
  The `beq` branch at 0xa800000020039e14 targets 0xa800000020039cbc and is always taken.
  The `beq` branch at 0xa800000020039e1c targets 0xa800000020039c20 and is always taken.
  The `beq` branch at 0xa800000020039e24 targets 0xa800000020039c20 and is always taken.
  The `beq` branch at 0xa800000020039e2c targets 0xa800000020039c20 and is always taken.
  The `beq` branch at 0xa800000020039e34 targets 0xa800000020039c20 and is always taken.
  The return at 0xa800000020039c24 has v0 = one of ?, ret(nic_next), ret(0xa800000020038fd0), ret(0xa800000020038f5c).

- `nic_get_eaddr` in `IP30/unix` at 0xa800000020039ec4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020039ec4-0xa800000020039f7c (184 bytes).
  It occupies 184 bytes.
  The `sw` at 0xa800000020039ef4 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0xa800000020039f0c calls nic_eaddr [0xa800000020039bc8] with a0=0xa800000020039e3c, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa800000020039f30 calls printf [0xa8000000201c78ec] with a0=0xa8000000203af050, a1=ret(nic_eaddr), a2=?, a3=?.
  The `jal` at 0xa800000020039f64 calls printf [0xa8000000201c78ec] with a0=0xa8000000203af020, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x200000.
  The `beq` branch at 0xa800000020039eec targets 0xa800000020039f60, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xa800000020039f18 targets 0xa800000020039f74, is taken when v0(=ret(nic_eaddr)) == 0, and falls through when v0(=ret(nic_eaddr)) != 0.
  The `bne` branch at 0xa800000020039f20 targets 0xa800000020039f08, is taken when s0(?) != s5(=-0x1), and falls through when s0(?) == s5(=-0x1).
  The `beq` branch at 0xa800000020039f6c targets 0xa800000020039efc and is always taken.
  The `beq` branch at 0xa800000020039f74 targets 0xa800000020039f3c and is always taken.
  The return at 0xa800000020039f58 has v0 = ret(nic_eaddr).

- `nic_info_get` in `IP30/unix` at 0xa80000002003a420 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a420-0xa80000002003a478 (88 bytes).
  It occupies 88 bytes.
  The `sb` at 0xa80000002003a428 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `jal` at 0xa80000002003a444 calls nic_setup [0xa800000020039218] with a0=sp-112, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003a458 calls (unnamed) [0xa800000020039f7c] with a0=sp-112, a1=a2 at entry (arg2), a2=?, a3=?.
  The `bltz` branch at 0xa80000002003a44c targets 0xa80000002003a468, is taken when v0(=ret(nic_setup)) < 0 (signed), and falls through when v0(=ret(nic_setup)) >= 0 (signed).
  The `beq` branch at 0xa80000002003a460 targets 0xa80000002003a458, is taken when v0(=ret(0xa800000020039f7c)) == 0, and falls through when v0(=ret(0xa800000020039f7c)) != 0.
  The return at 0xa80000002003a470 has v0 = one of ret(nic_setup), ret(0xa800000020039f7c).

- `nic_vertex_info_get` in `IP30/unix` at 0xa80000002003a478 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a478-0xa80000002003a4a4 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xa80000002003a48c calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=a0 at entry (arg0), a1=0xa8000000203af298, a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xa80000002003a49c has v0 = ?.

- `nic_vertex_info_set` in `IP30/unix` at 0xa80000002003a4a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a4a4-0xa80000002003a5b0 (268 bytes).
  It occupies 268 bytes.
  The `jal` at 0xa80000002003a4bc calls nic_vertex_info_get [0xa80000002003a478] with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003a4e4 calls kern_malloc [0xa800000020148768] with a0=0x800, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003a508 calls nic_info_get [0xa80000002003a420] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=ret(kern_malloc), a3=?.
  The `jal` at 0xa80000002003a510 calls strlen [0xa8000000200178e0] with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003a520 calls kern_malloc [0xa800000020148768] with a0=(ret(strlen)+1 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003a544 calls hwgraph_info_add_LBL [0xa80000002023c80c] with a0=a2 at entry (arg2), a1=0xa8000000203af298, a2=ret(kern_malloc), a3=?.
  The `jal` at 0xa80000002003a54c calls nic_vertex_info_get [0xa80000002003a478] with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003a55c calls kern_free [0xa8000000201488f0] with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003a578 calls hwgraph_info_export_LBL [0xa80000002023c970] with a0=a2 at entry (arg2), a1=0xa8000000203af298, a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0xa80000002003a584 calls nic_vmc_check [0xa80000002003a6c0] with a0=a2 at entry (arg2), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0xa80000002003a598 calls strcpy [0xa80000002012895c] with a0=ret(kern_malloc), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0xa80000002003a5a0 calls kern_free [0xa8000000201488f0] with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002003a4c4 targets 0xa80000002003a4e0, is taken when v0(=ret(nic_vertex_info_get)) == 0, and falls through when v0(=ret(nic_vertex_info_get)) != 0.
  The `bne` branch at 0xa80000002003a4ec targets 0xa80000002003a500, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0xa80000002003a4f8 targets 0xa80000002003a4cc and is always taken.
  The `bne` branch at 0xa80000002003a528 targets 0xa80000002003a594, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0xa80000002003a554 targets 0xa80000002003a56c, is taken when v0(=ret(nic_vertex_info_get)) == s0(=ret(kern_malloc)), and falls through when v0(=ret(nic_vertex_info_get)) != s0(=ret(kern_malloc)).
  The `beq` branch at 0xa80000002003a564 targets 0xa80000002003a4cc and is always taken.
  The `beq` branch at 0xa80000002003a58c targets 0xa80000002003a4cc and is always taken.
  The `beq` branch at 0xa80000002003a5a8 targets 0xa80000002003a538 and is always taken.
  The return at 0xa80000002003a4d8 has v0 = one of ret(nic_vertex_info_get), 0x0, ret(kern_malloc).

- `nic_vertex_info_match` in `IP30/unix` at 0xa80000002003a5b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a5b0-0xa80000002003a5ec (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0xa80000002003a5b8 calls nic_vertex_info_get [0xa80000002003a478] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003a5dc calls strstr [0xa800000020128af8] with a0=ret(nic_vertex_info_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `bne` branch at 0xa80000002003a5c0 targets 0xa80000002003a5dc, is taken when v0(=ret(nic_vertex_info_get)) != 0, and falls through when v0(=ret(nic_vertex_info_get)) == 0.
  The `beq` branch at 0xa80000002003a5e4 targets 0xa80000002003a5cc and is always taken.
  The return at 0xa80000002003a5d4 has v0 = one of 0x0, ?.

- `nic_bridge_vertex_info` in `IP30/unix` at 0xa80000002003a5ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a5ec-0xa80000002003a60c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xa80000002003a5f8 calls nic_vertex_info_set [0xa80000002003a4a4] with a0=0xa800000020039e3c, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0xa80000002003a604 has v0 = ret(nic_vertex_info_set).

- `nic_hq4_vertex_info` in `IP30/unix` at 0xa80000002003a60c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a60c-0xa80000002003a62c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xa80000002003a618 calls nic_vertex_info_set [0xa80000002003a4a4] with a0=0xa800000020039e3c, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0xa80000002003a624 has v0 = ret(nic_vertex_info_set).

- `nic_ioc3_vertex_info` in `IP30/unix` at 0xa80000002003a62c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a62c-0xa80000002003a65c (48 bytes).
  It occupies 48 bytes.
  The `sw` at 0xa80000002003a640 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0xa80000002003a648 calls nic_vertex_info_set [0xa80000002003a4a4] with a0=0xa800000020039e3c, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3), a4=a0 at entry (arg0), a5=0x200000.
  The `beq` branch at 0xa80000002003a638 targets 0xa80000002003a644, is taken when a2 == 0, and falls through when a2 != 0.
  The return at 0xa80000002003a654 has v0 = ret(nic_vertex_info_set).

- `nic_vmc_add` in `IP30/unix` at 0xa80000002003a65c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a65c-0xa80000002003a6b4 (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0xa80000002003a67c stores 8 bytes to ret(kern_malloc) +0x0.
  The `sd` at 0xa80000002003a680 stores 8 bytes to ret(kern_malloc) +0x8.
  The `sd` at 0xa80000002003a694 stores 8 bytes to ret(kern_malloc) +0x10.
  The `sd` at 0xa80000002003a6a8 stores 8 bytes to ret(swap_int64) +0x0.
  The `jal` at 0xa80000002003a670 calls kern_malloc [0xa800000020148768] with a0=0x18, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003a690 calls swap_int64 [0xa800000020016e70] with a0=0xa8000000204a76f0, a1=ret(kern_malloc), a2=?, a3=?.
  The return at 0xa80000002003a6ac has v0 = ret(kern_malloc).

- `nic_vmc_del` in `IP30/unix` at 0xa80000002003a6b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a6b4-0xa80000002003a6c0 (12 bytes).
  It occupies 12 bytes.
  The `sd` at 0xa80000002003a6b4 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0xa80000002003a6bc stores 8 bytes to a0 (arg0 at entry) +0x8.
  The return at 0xa80000002003a6b8 has v0 = ?.

- `nic_vmc_check` in `IP30/unix` at 0xa80000002003a6c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a6c0-0xa80000002003a760 (160 bytes).
  It occupies 160 bytes.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002003a704, `ld` at 0xa80000002003a710, `ld` at 0xa80000002003a71c.
  The `jal` at 0xa80000002003a6f4 calls strstr [0xa800000020128af8] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jalr` at 0xa80000002003a750 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xa80000002003a6e4 targets 0xa80000002003a710, is taken when at(=[0xa8000000204a76e8]:8) != 0, and falls through when at(=[0xa8000000204a76e8]:8) == 0.
  The `beq` branch at 0xa80000002003a6ec targets 0xa80000002003a734 and is always taken.
  The `bne` branch at 0xa80000002003a6fc targets 0xa80000002003a750, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0xa80000002003a708 targets 0xa80000002003a734, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa80000002003a714 targets 0xa80000002003a728, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0xa80000002003a720 targets 0xa80000002003a6f4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0xa80000002003a72c targets 0xa80000002003a710, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xa80000002003a758 targets 0xa80000002003a708 and is always taken.
  The return at 0xa80000002003a748 has v0 = ?.

- `xtalk_piomap_alloc` in `IP30/unix` at 0xa80000002003a760 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a760-0xa80000002003a77c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a768 calls heart_piomap_alloc [0xa80000002003f2c8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a774 has v0 = ret(heart_piomap_alloc).

- `xtalk_piomap_free` in `IP30/unix` at 0xa80000002003a77c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a77c-0xa80000002003a798 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a784 calls heart_piomap_free [0xa80000002003f388] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a790 has v0 = ret(heart_piomap_free).

- `xtalk_piomap_addr` in `IP30/unix` at 0xa80000002003a798 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a798-0xa80000002003a7b4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a7a0 calls heart_piomap_addr [0xa80000002003f3a4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a7ac has v0 = ret(heart_piomap_addr).

- `xtalk_piomap_done` in `IP30/unix` at 0xa80000002003a7b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a7b4-0xa80000002003a7d0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a7bc calls heart_piomap_done [0xa80000002003f3b8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a7c8 has v0 = ret(heart_piomap_done).

- `xtalk_piotrans_addr` in `IP30/unix` at 0xa80000002003a7d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a7d0-0xa80000002003a7ec (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a7d8 calls heart_piotrans_addr [0xa80000002003f3c0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a7e4 has v0 = ret(heart_piotrans_addr).

- `xtalk_pio_addr` in `IP30/unix` at 0xa80000002003a7ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a7ec-0xa80000002003a8e4 (248 bytes).
  It occupies 248 bytes.
  2 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0xa80000002003a828, `sd` at 0xa80000002003a8c4.
  The `jal` at 0xa80000002003a840 calls xtalk_piotrans_addr [0xa80000002003a7d0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a5 at entry (arg5).
  The `jal` at 0xa80000002003a88c calls xtalk_piomap_alloc [0xa80000002003a760] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a3 at entry (arg3).
  The `jal` at 0xa80000002003a8ac calls xtalk_piomap_addr [0xa80000002003a798] with a0=ret(xtalk_piomap_alloc), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xa80000002003a8d4 calls xtalk_piomap_free [0xa80000002003a77c] with a0=ret(xtalk_piomap_alloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002003a820 targets 0xa80000002003a82c, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xa80000002003a848 targets 0xa80000002003a878, is taken when v0(=ret(xtalk_piotrans_addr)) == 0, and falls through when v0(=ret(xtalk_piotrans_addr)) != 0.
  The `bne` branch at 0xa80000002003a894 targets 0xa80000002003a8a4, is taken when v0(=ret(xtalk_piomap_alloc)) != 0, and falls through when v0(=ret(xtalk_piomap_alloc)) == 0.
  The `beq` branch at 0xa80000002003a89c targets 0xa80000002003a850 and is always taken.
  The `beq` branch at 0xa80000002003a8b4 targets 0xa80000002003a8d4, is taken when v0(=ret(xtalk_piomap_addr)) == 0, and falls through when v0(=ret(xtalk_piomap_addr)) != 0.
  The `beq` branch at 0xa80000002003a8bc targets 0xa80000002003a8cc, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0xa80000002003a8cc targets 0xa80000002003a854 and is always taken.
  The `beq` branch at 0xa80000002003a8dc targets 0xa80000002003a850 and is always taken.
  The return at 0xa80000002003a870 has v0 = one of ?, ret(xtalk_piomap_addr).

- `xtalk_set_early_piotrans_addr` in `IP30/unix` at 0xa80000002003a8e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a8e4-0xa80000002003a8ec (8 bytes).
  It occupies 8 bytes.
  The return at 0xa80000002003a8e4 has v0 = ?.

- `xtalk_early_piotrans_addr` in `IP30/unix` at 0xa80000002003a8ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a8ec-0xa80000002003a90c (32 bytes).
  It occupies 32 bytes.
  The `jalr` at 0xa80000002003a8f8 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a904 has v0 = ret(?).

- `xtalk_dmamap_alloc` in `IP30/unix` at 0xa80000002003a914 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a914-0xa80000002003a930 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a91c calls heart_dmamap_alloc [0xa80000002003f41c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a928 has v0 = ret(heart_dmamap_alloc).

- `xtalk_dmamap_free` in `IP30/unix` at 0xa80000002003a930 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a930-0xa80000002003a94c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a938 calls heart_dmamap_free [0xa80000002003f478] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a944 has v0 = ret(heart_dmamap_free).

- `xtalk_dmamap_addr` in `IP30/unix` at 0xa80000002003a94c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a94c-0xa80000002003a968 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a954 calls heart_dmamap_addr [0xa80000002003f494] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a960 has v0 = ret(heart_dmamap_addr).

- `xtalk_dmamap_list` in `IP30/unix` at 0xa80000002003a968 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a968-0xa80000002003a984 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a970 calls heart_dmamap_list [0xa80000002003f4b4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a97c has v0 = ret(heart_dmamap_list).

- `xtalk_dmamap_done` in `IP30/unix` at 0xa80000002003a984 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a984-0xa80000002003a9a0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a98c calls heart_dmamap_done [0xa80000002003f620] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a998 has v0 = ret(heart_dmamap_done).

- `xtalk_dmatrans_addr` in `IP30/unix` at 0xa80000002003a9a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a9a0-0xa80000002003a9bc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a9a8 calls heart_dmatrans_addr [0xa80000002003f628] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a9b4 has v0 = ret(heart_dmatrans_addr).

- `xtalk_dmatrans_list` in `IP30/unix` at 0xa80000002003a9bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a9bc-0xa80000002003a9d8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a9c4 calls heart_dmatrans_list [0xa80000002003f648] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a9d0 has v0 = ret(heart_dmatrans_list).

- `xtalk_dmamap_drain` in `IP30/unix` at 0xa80000002003a9d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a9d8-0xa80000002003a9f4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a9e0 calls heart_dmamap_drain [0xa80000002003f7b4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003a9ec has v0 = ret(heart_dmamap_drain).

- `xtalk_dmaaddr_drain` in `IP30/unix` at 0xa80000002003a9f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003a9f4-0xa80000002003aa10 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003a9fc calls heart_dmaaddr_drain [0xa80000002003f7bc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aa08 has v0 = ret(heart_dmaaddr_drain).

- `xtalk_dmalist_drain` in `IP30/unix` at 0xa80000002003aa10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aa10-0xa80000002003aa2c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aa18 calls heart_dmalist_drain [0xa80000002003f7c4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aa24 has v0 = ret(heart_dmalist_drain).

- `xtalk_intr_alloc` in `IP30/unix` at 0xa80000002003aa2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aa2c-0xa80000002003aa48 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aa34 calls heart_intr_alloc [0xa80000002003fa54] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aa40 has v0 = ret(heart_intr_alloc).

- `xtalk_intr_alloc_nothd` in `IP30/unix` at 0xa80000002003aa48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aa48-0xa80000002003aa64 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aa50 calls heart_intr_alloc_nothd [0xa80000002003fa70] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aa5c has v0 = ret(heart_intr_alloc_nothd).

- `xtalk_intr_free` in `IP30/unix` at 0xa80000002003aa64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aa64-0xa80000002003aa80 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aa6c calls heart_intr_free [0xa80000002003fa8c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aa78 has v0 = ret(heart_intr_free).

- `xtalk_intr_connect` in `IP30/unix` at 0xa80000002003aa80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aa80-0xa80000002003aa9c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aa88 calls heart_intr_connect [0xa80000002003fac8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aa94 has v0 = ret(heart_intr_connect).

- `xtalk_intr_disconnect` in `IP30/unix` at 0xa80000002003aa9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aa9c-0xa80000002003aab8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aaa4 calls heart_intr_disconnect [0xa80000002003fb9c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aab0 has v0 = ret(heart_intr_disconnect).

- `xtalk_intr_cpu_get` in `IP30/unix` at 0xa80000002003aab8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aab8-0xa80000002003aad4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aac0 calls heart_intr_cpu_get [0xa80000002003fc0c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aacc has v0 = ret(heart_intr_cpu_get).

- `xtalk_intr_cpuid_get` in `IP30/unix` at 0xa80000002003aad4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aad4-0xa80000002003aaf0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aadc calls heart_intr_cpuid_get [0xa80000002003fc28] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003aae8 has v0 = ret(heart_intr_cpuid_get).

- `xtalk_error_handler` in `IP30/unix` at 0xa80000002003aaf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aaf0-0xa80000002003ab9c (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0xa80000002003ab18 loads 8 bytes from ret(xwidget_info_get) +0x28.
  The `ld` at 0xa80000002003ab24 loads 8 bytes from ret(xwidget_info_get) +0x30.
  The `jal` at 0xa80000002003ab08 calls xwidget_info_get [0xa80000002003acd0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xa80000002003ab30 calls (unknown callee) with a0=[ret(xwidget_info_get)+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x3, a6=[ret(xwidget_info_get)+40]:8.
  The `jal` at 0xa80000002003ab74 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203af2a0, a2=a0 at entry (arg0), a3=?, a5=0x3.
  The `jal` at 0xa80000002003ab8c calls ioerror_dump [0xa80000002001d2f0] with a0=0xa8000000203af2c8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa80000002003ab10 targets 0xa80000002003ab40, is taken when v0(=ret(xwidget_info_get)) == 0, and falls through when v0(=ret(xwidget_info_get)) != 0.
  The `beq` branch at 0xa80000002003ab1c targets 0xa80000002003ab40, is taken when a6(=[ret(xwidget_info_get)+40]:8) == 0, and falls through when a6(=[ret(xwidget_info_get)+40]:8) != 0.
  The `beq` branch at 0xa80000002003ab38 targets 0xa80000002003ab58 and is always taken.
  The `beq` branch at 0xa80000002003ab40 targets 0xa80000002003ab54, is taken when s0(=a2) == 0, and falls through when s0(=a2) != 0.
  The `beq` branch at 0xa80000002003ab48 targets 0xa80000002003ab58, is taken when s0(=a2) == at(=0x2), and falls through when s0(=a2) != at(=0x2).
  The `bne` branch at 0xa80000002003ab50 targets 0xa80000002003ab6c, is taken when s0(=a2) != a5(=0x3), and falls through when s0(=a2) == a5(=0x3).
  The `beq` branch at 0xa80000002003ab94 targets 0xa80000002003ab58 and is always taken.
  The return at 0xa80000002003ab64 has v0 = one of ret(?), 0x0, 0x9.

- `xtalk_error_devenable` in `IP30/unix` at 0xa80000002003ab9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ab9c-0xa80000002003abb8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003aba4 calls heart_error_devenable [0xa800000020040004] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003abb0 has v0 = ret(heart_error_devenable).

- `xtalk_provider_startup` in `IP30/unix` at 0xa80000002003abb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003abb8-0xa80000002003abd4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003abc0 calls heart_provider_startup [0xa80000002003fc30] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003abcc has v0 = ret(heart_provider_startup).

- `xtalk_provider_shutdown` in `IP30/unix` at 0xa80000002003abd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003abd4-0xa80000002003abf0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003abdc calls heart_provider_shutdown [0xa80000002003fc38] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003abe8 has v0 = ret(heart_provider_shutdown).

- `xtalk_widgetdev_enable` in `IP30/unix` at 0xa80000002003abf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003abf0-0xa80000002003ac0c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003abf8 calls heart_widgetdev_enable [0xa80000002004036c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003ac04 has v0 = ret(heart_widgetdev_enable).

- `xtalk_widgetdev_shutdown` in `IP30/unix` at 0xa80000002003ac0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac0c-0xa80000002003ac28 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003ac14 calls heart_widgetdev_shutdown [0xa800000020040374] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003ac20 has v0 = ret(heart_widgetdev_shutdown).

- `xtalk_dma_enabled` in `IP30/unix` at 0xa80000002003ac28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac28-0xa80000002003ac44 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003ac30 calls heart_dma_enabled [0xa80000002004037c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003ac3c has v0 = ret(heart_dma_enabled).

- `xtalk_intr_dev_get` in `IP30/unix` at 0xa80000002003ac44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac44-0xa80000002003ac4c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002003ac48 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0xa80000002003ac44 has v0 = [a0].

- `xtalk_intr_target_get` in `IP30/unix` at 0xa80000002003ac4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac4c-0xa80000002003ac54 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002003ac50 loads 1 byte from a0 (arg0 at entry) +0x4.
  The return at 0xa80000002003ac4c has v0 = [a0+4]:1.

- `xtalk_intr_vector_get` in `IP30/unix` at 0xa80000002003ac54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac54-0xa80000002003ac5c (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002003ac58 loads 1 byte from a0 (arg0 at entry) +0x5.
  The return at 0xa80000002003ac54 has v0 = [a0+5]:1.

- `xtalk_intr_addr_get` in `IP30/unix` at 0xa80000002003ac5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac5c-0xa80000002003ac64 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002003ac60 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xa80000002003ac5c has v0 = [a0+8]:8.

- `xtalk_intr_sfarg_get` in `IP30/unix` at 0xa80000002003ac64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac64-0xa80000002003ac6c (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002003ac68 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0xa80000002003ac64 has v0 = [a0+16]:8.

- `xtalk_pio_dev_get` in `IP30/unix` at 0xa80000002003ac6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac6c-0xa80000002003ac74 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002003ac70 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0xa80000002003ac6c has v0 = [a0].

- `xtalk_pio_target_get` in `IP30/unix` at 0xa80000002003ac74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac74-0xa80000002003ac7c (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002003ac78 loads 1 byte from a0 (arg0 at entry) +0x4.
  The return at 0xa80000002003ac74 has v0 = [a0+4]:1.

- `xtalk_pio_xtalk_addr_get` in `IP30/unix` at 0xa80000002003ac7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac7c-0xa80000002003ac84 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002003ac80 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xa80000002003ac7c has v0 = [a0+8]:8.

- `xtalk_pio_mapsz_get` in `IP30/unix` at 0xa80000002003ac84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac84-0xa80000002003ac8c (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002003ac88 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0xa80000002003ac84 has v0 = [a0+16]:8.

- `xtalk_pio_kvaddr_get` in `IP30/unix` at 0xa80000002003ac8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac8c-0xa80000002003ac94 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002003ac90 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xa80000002003ac8c has v0 = [a0+24]:8.

- `xtalk_dma_dev_get` in `IP30/unix` at 0xa80000002003ac94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac94-0xa80000002003ac9c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002003ac98 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0xa80000002003ac94 has v0 = [a0].

- `xtalk_dma_target_get` in `IP30/unix` at 0xa80000002003ac9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003ac9c-0xa80000002003aca4 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002003aca0 loads 1 byte from a0 (arg0 at entry) +0x4.
  The return at 0xa80000002003ac9c has v0 = [a0+4]:1.

- `xtalk_init` in `IP30/unix` at 0xa80000002003aeec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003aeec-0xa80000002003af44 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0xa80000002003af08 calls cdl_new [0xa800000020096f58] with a0=0xa8000000203af438, a1=0xa8000000203af440, a2=0xa8000000203af448, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003af1c calls compare_and_swap_int64 [0xa800000020016e8c] with a0=0xa8000000204a76f8, a1=0x0, a2=ret(cdl_new), a3=?.
  The `jal` at 0xa80000002003af34 calls cdl_del [0xa800000020096fc4] with a0=ret(cdl_new), a1=?, a2=?, a3=?.
  The `bne` branch at 0xa80000002003aef4 targets 0xa80000002003af28, is taken when at(=[0xa8000000204a76f8]:8) != 0, and falls through when at(=[0xa8000000204a76f8]:8) == 0.
  The `beq` branch at 0xa80000002003af24 targets 0xa80000002003af34, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `beq` branch at 0xa80000002003af3c targets 0xa80000002003af2c and is always taken.
  The return at 0xa80000002003af2c has v0 = one of ret(compare_and_swap_int64), ?, ret(cdl_del).

- `xtalk_provider_register` in `IP30/unix` at 0xa80000002003af44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003af44-0xa80000002003af60 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003af4c calls hwgraph_fastinfo_set [0xa80000002023d608] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003af58 has v0 = ret(hwgraph_fastinfo_set).

- `xtalk_provider_unregister` in `IP30/unix` at 0xa80000002003af60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003af60-0xa80000002003af7c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003af68 calls hwgraph_fastinfo_set [0xa80000002023d608] with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003af74 has v0 = ret(hwgraph_fastinfo_set).

- `xtalk_provider_fns_get` in `IP30/unix` at 0xa80000002003af7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003af7c-0xa80000002003af98 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002003af84 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002003af90 has v0 = ret(hwgraph_fastinfo_get).

- `xtalk_iterate` in `IP30/unix` at 0xa80000002003b030 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003b030-0xa80000002003b058 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0xa80000002003b044 calls cdl_iterate [0xa800000020097eec] with a0=[0xa8000000204a76f8]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0xa80000002003b050 has v0 = ret(cdl_iterate).

- `xtalk_device_powerup` in `IP30/unix` at 0xa80000002003b2f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003b2f8-0xa80000002003b300 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa80000002003b2f8 has v0 = 0x0.

- `xtalk_device_shutdown` in `IP30/unix` at 0xa80000002003b300 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003b300-0xa80000002003b35c (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0xa80000002003b31c calls sprintf [0xa8000000201c784c] with a0=sp-32, a1=0xa8000000203af478, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003b32c calls hwgraph_traverse [0xa80000002023cd3c] with a0=a0 at entry (arg0), a1=sp-32, a2=sp-24, a3=?.
  The `jal` at 0xa80000002003b34c calls xwidget_unregister [0xa80000002003b17c] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002003b334 targets 0xa80000002003b34c, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xa80000002003b354 targets 0xa80000002003b340 and is always taken.
  The return at 0xa80000002003b344 has v0 = one of 0x0, 0x1.

- `xtalk_device_inquiry` in `IP30/unix` at 0xa80000002003b35c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003b35c-0xa80000002003b364 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa80000002003b35c has v0 = 0x0.

- `xbow_widget_num_get` in `IP30/unix` at 0xa80000002003b9f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003b9f0-0xa80000002003badc (236 bytes).
  It occupies 236 bytes.
  The `jal` at 0xa80000002003ba04 calls vertex_to_name [0xa80000002023e0dc] with a0=a0 at entry (arg0), a1=sp-288, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003ba18 calls hwgraph_edge_get [0xa80000002023c560] with a0=a0 at entry (arg0), a1=0xa8000000203af5c0, a2=sp-32, a3=?.
  The `jal` at 0xa80000002003ba2c calls strstr [0xa800000020128af8] with a0=sp-288, a1=0xa8000000203af5e0, a2=?, a3=?.
  The `jal` at 0xa80000002003ba44 calls strstr [0xa800000020128af8] with a0=sp-288, a1=0xa8000000203af5d0, a2=?, a3=0xff.
  The `jal` at 0xa80000002003ba68 calls hwgraph_edge_get [0xa80000002023c560] with a0=a0 at entry (arg0), a1=0xa8000000203af5e4, a2=sp-32, a3=?.
  The `jal` at 0xa80000002003baac calls xwidget_info_chk [0xa80000002003aca4] with a0=a0 at entry (arg0), a1=0xa8000000203af4e8, a2=?, a3=?.
  The `jal` at 0xa80000002003bacc calls xwidget_info_id_get [0xa80000002003adb4] with a0=ret(xwidget_info_chk), a1=?, a2=?, a3=0xff.
  The `beq` branch at 0xa80000002003ba20 targets 0xa80000002003bac4, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xa80000002003ba34 targets 0xa80000002003ba84, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0xa80000002003ba4c targets 0xa80000002003ba84, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0xa80000002003ba70 targets 0xa80000002003ba98, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xa80000002003ba78 targets 0xa80000002003ba84 and is always taken.
  The `bne` branch at 0xa80000002003baa4 targets 0xa80000002003ba60, is taken when a2(?) < 0x2 (signed), and falls through when a2(?) >= 0x2 (signed).
  The `bne` branch at 0xa80000002003bab4 targets 0xa80000002003bacc, is taken when v0(=ret(xwidget_info_chk)) != 0, and falls through when v0(=ret(xwidget_info_chk)) == 0.
  The `beq` branch at 0xa80000002003babc targets 0xa80000002003ba88 and is always taken.
  The `beq` branch at 0xa80000002003bac4 targets 0xa80000002003ba84 and is always taken.
  The `beq` branch at 0xa80000002003bad4 targets 0xa80000002003ba84 and is always taken.
  The return at 0xa80000002003ba90 has v0 = one of ?, 0xff.
  The instructions from 0xa80000002003ba80 to 0xa80000002003ba80 are not reached by any path from the entry, and their branches are not listed.

- `xbow_ioctl` in `IP30/unix` at 0xa80000002003badc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003badc-0xa80000002003be48 (876 bytes).
  It occupies 876 bytes.
  The `sw` at 0xa80000002003badc stores 4 bytes to a5 (arg5 at entry) +0x0.
  The `jal` at 0xa80000002003bb7c calls xbow_get_perf_counters [0xa80000002003d07c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa80000002003bb94 calls copyout [0xa80000002001709c] with a0=ret(xbow_get_perf_counters), a1=a2 at entry (arg2), a2=0x100, a3=?.
  The `jal` at 0xa80000002003bbc0 calls cap_able_cred [0xa80000002022e8f0] with a0=a4 at entry (arg4), a1=0x2000000000, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003bbdc calls copyin [0xa800000020017010] with a0=a2 at entry (arg2), a1=sp-64, a2=0xc, a3=?.
  The `jal` at 0xa80000002003bc04 calls xbow_get_llp_status [0xa80000002003d268] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0xa80000002003bc1c calls copyout [0xa80000002001709c] with a0=ret(xbow_get_llp_status), a1=a2 at entry (arg2), a2=0x80, a3=?.
  The `jal` at 0xa80000002003bc44 calls cap_able_cred [0xa80000002022e8f0] with a0=a4 at entry (arg4), a1=0x2000000000, a2=?, a3=?, a5=0x4.
  The `jal` at 0xa80000002003bc74 calls cap_able_cred [0xa80000002022e8f0] with a0=a4 at entry (arg4), a1=0x2000000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003bc8c calls xbow_disable_llp_monitor [0xa80000002003d39c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003bca0 calls cap_able [0xa80000002022e9bc] with a0=0x2000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0xa80000002003bcb4 calls copyin [0xa800000020017010] with a0=a2 at entry (arg2), a1=sp-96, a2=0x10, a3=?.
  The `jal` at 0xa80000002003bce0 calls cap_able [0xa80000002022e9bc] with a0=0x2000000000, a1=0x6702, a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0xa80000002003bcf4 calls copyin [0xa800000020017010] with a0=a2 at entry (arg2), a1=sp-80, a2=0x10, a3=?.
  The `jal` at 0xa80000002003bd28 calls xbow_enable_perf_counter [0xa80000002003d09c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003bd3c calls xbow_enable_llp_monitor [0xa80000002003d3e4] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003bd68 calls xbow_widget_num_get [0xa80000002003b9f0] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003bd74 calls xbow_widget_num_get [0xa80000002003b9f0] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003bd94 calls xbow_prio_bw_alloc [0xa80000002003d67c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0xa80000002003bdac calls xbow_prio_bw_alloc [0xa80000002003d67c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0xa80000002003bdbc calls xbow_widget_num_get [0xa80000002003b9f0] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003bdc8 calls xbow_widget_num_get [0xa80000002003b9f0] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003bde8 calls xbow_prio_bw_alloc [0xa80000002003d67c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003be00 calls xbow_prio_bw_alloc [0xa80000002003d67c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003be1c calls assfail [0xa80000002001bc94] with a0=0xa8000000203af610, a1=0xa8000000203af600, a2=0x264, a3=?.
  The `jal` at 0xa80000002003be38 calls assfail [0xa80000002001bc94] with a0=0xa8000000203af5e8, a1=0xa8000000203af600, a2=0x28c, a3=?.
  The `bne` branch at 0xa80000002003bb08 targets 0xa80000002003bb5c, is taken when a1 < 0x5 (signed), and falls through when a1 >= 0x5 (signed).
  The `bne` branch at 0xa80000002003bb14 targets 0xa80000002003bc6c, is taken when a1 < 0x6 (signed), and falls through when a1 >= 0x6 (signed).
  The `bne` branch at 0xa80000002003bb1c targets 0xa80000002003bbf4, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `bne` branch at 0xa80000002003bb28 targets 0xa80000002003bca0, is taken when a1 < 0x6702 (signed), and falls through when a1 >= 0x6702 (signed).
  The `beq` branch at 0xa80000002003bb34 targets 0xa80000002003bcdc, is taken when s0(=a1) == a1(=0x6702), and falls through when s0(=a1) != a1(=0x6702).
  The `bne` branch at 0xa80000002003bb60 targets 0xa80000002003bba8, is taken when a1 < 0x3 (signed), and falls through when a1 >= 0x3 (signed).
  The `beq` branch at 0xa80000002003bb6c targets 0xa80000002003bc30, is taken when a1 >= 0x4 (signed), and falls through when a1 < 0x4 (signed).
  The `beq` branch at 0xa80000002003bb74 targets 0xa80000002003bccc, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xa80000002003bb84 targets 0xa80000002003be10, is taken when v0(=ret(xbow_get_perf_counters)) == 0, and falls through when v0(=ret(xbow_get_perf_counters)) != 0.
  The `beq` branch at 0xa80000002003bba0 targets 0xa80000002003bb3c and is always taken.
  The `bne` branch at 0xa80000002003bba8 targets 0xa80000002003bc5c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xa80000002003bbb0 targets 0xa80000002003bb3c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002003bbc8 targets 0xa80000002003bd58, is taken when v0(=ret(cap_able_cred)) == 0, and falls through when v0(=ret(cap_able_cred)) != 0.
  The `beq` branch at 0xa80000002003bbd0 targets 0xa80000002003bcd4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa80000002003bbe4 targets 0xa80000002003bd14, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0xa80000002003bbec targets 0xa80000002003bb3c and is always taken.
  The `bne` branch at 0xa80000002003bbf4 targets 0xa80000002003bb38, is taken when a1 != a3(=0x6), and falls through when a1 == a3(=0x6).
  The `beq` branch at 0xa80000002003bbfc targets 0xa80000002003bd0c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa80000002003bc0c targets 0xa80000002003be2c, is taken when v0(=ret(xbow_get_llp_status)) == 0, and falls through when v0(=ret(xbow_get_llp_status)) != 0.
  The `beq` branch at 0xa80000002003bc28 targets 0xa80000002003bb3c and is always taken.
  The `bne` branch at 0xa80000002003bc34 targets 0xa80000002003bb3c, is taken when a1 != a5(=0x4), and falls through when a1 == a5(=0x4).
  The `bne` branch at 0xa80000002003bc4c targets 0xa80000002003bd3c, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0xa80000002003bc54 targets 0xa80000002003bb3c and is always taken.
  The `bne` branch at 0xa80000002003bc5c targets 0xa80000002003bb3c, is taken when a1 != a2(=0x1), and falls through when a1 == a2(=0x1).
  The `beq` branch at 0xa80000002003bc64 targets 0xa80000002003bbbc and is always taken.
  The `bne` branch at 0xa80000002003bc7c targets 0xa80000002003bc8c, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0xa80000002003bc84 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bc98 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bca8 targets 0xa80000002003bd50, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0xa80000002003bcbc targets 0xa80000002003bd68, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0xa80000002003bcc4 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bccc targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bcd4 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bce8 targets 0xa80000002003bd60, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0xa80000002003bcfc targets 0xa80000002003bdbc, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0xa80000002003bd04 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bd0c targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bd34 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bd48 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bd50 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bd58 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bd60 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003bdb4 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003be08 targets 0xa80000002003bb3c and is always taken.
  The `beq` branch at 0xa80000002003be24 targets 0xa80000002003bb90 and is always taken.
  The `beq` branch at 0xa80000002003be40 targets 0xa80000002003bc18 and is always taken.
  The return at 0xa80000002003bb54 has v0 = one of 0x0, 0xe, 0x1, ?, 0x9.

- `xbow_widget_lookup` in `IP30/unix` at 0xa80000002003bec4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003bec4-0xa80000002003bef4 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0xa80000002003bed0 calls xswitch_info_get [0xa80000002003b364] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003bedc calls xswitch_info_vhdl_get [0xa80000002003b3d4] with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?.
  The return at 0xa80000002003beec has v0 = ret(xswitch_info_vhdl_get).

- `xbow_intr_preset` in `IP30/unix` at 0xa80000002003bf60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003bf60-0xa80000002003bf94 (52 bytes).
  It occupies 52 bytes.
  The `sw` at 0xa80000002003bf88 stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `sw` at 0xa80000002003bf90 stores 4 bytes to a0 (arg0 at entry) +0x3c.
  The return at 0xa80000002003bf8c has v0 = ?.

- `xbow_xmit_retry_error` in `IP30/unix` at 0xa80000002003c1c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003c1c8-0xa80000002003c2cc (260 bytes).
  It occupies 260 bytes.
  The `ld` at 0xa80000002003c1d8 loads 8 bytes from (a0 + (a1 << 0x3)) +0x188.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002003c1ec, `lw` at 0xa80000002003c24c, `lw` at 0xa80000002003c25c.
  The `sw` at 0xa80000002003c250 stores 4 bytes to ?.
  The `lw` at 0xa80000002003c264 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0xa80000002003c2b8 stores 8 bytes to (a0 + (a1 << 0x3)) +0x188.
  The `jal` at 0xa80000002003c260 calls xswitch_info_get [0xa80000002003b364] with a0=[a0+8], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[(a0 + (a1 << 0x3))+392]:8.
  The `jal` at 0xa80000002003c280 calls xswitch_info_vhdl_get [0xa80000002003b3d4] with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?, a4=0x1.
  The `jal` at 0xa80000002003c2a0 calls xtalk_piotrans_addr [0xa80000002003a7d0] with a0=ret(xswitch_info_vhdl_get), a1=0x0, a2=0x0, a3=0x58, a4=0x0.
  The `beq` branch at 0xa80000002003c1e4 targets 0xa80000002003c260, is taken when a5(=[(a0 + (a1 << 0x3))+392]:8) == 0, and falls through when a5(=[(a0 + (a1 << 0x3))+392]:8) != 0.
  The `beq` branch at 0xa80000002003c200 targets 0xa80000002003c230, is taken when a0(?) == a7(=0xc002), and falls through when a0(?) != a7(=0xc002).
  The `bne` branch at 0xa80000002003c208 targets 0xa80000002003c220, is taken when a0(?) != a1(=0xd002), and falls through when a0(?) == a1(=0xd002).
  The `beq` branch at 0xa80000002003c218 targets 0xa80000002003c244, is taken when a1(?) == a2(=0x24), and falls through when a1(?) != a2(=0x24).
  The `bne` branch at 0xa80000002003c23c targets 0xa80000002003c208, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0xa80000002003c258 targets 0xa80000002003c220 and is always taken.
  The `bne` branch at 0xa80000002003c268 targets 0xa80000002003c278, is taken when v0(=ret(xswitch_info_get)) != 0, and falls through when v0(=ret(xswitch_info_get)) == 0.
  The `beq` branch at 0xa80000002003c270 targets 0xa80000002003c224 and is always taken.
  The `beq` branch at 0xa80000002003c28c targets 0xa80000002003c2bc, is taken when v0(=ret(xswitch_info_vhdl_get)) == a2(=-0x1), and falls through when v0(=ret(xswitch_info_vhdl_get)) != a2(=-0x1).
  The `beq` branch at 0xa80000002003c2ac targets 0xa80000002003c2c4, is taken when v0(=ret(xtalk_piotrans_addr)) == 0, and falls through when v0(=ret(xtalk_piotrans_addr)) != 0.
  The `beq` branch at 0xa80000002003c2b4 targets 0xa80000002003c1ec and is always taken.
  The `beq` branch at 0xa80000002003c2bc targets 0xa80000002003c220 and is always taken.
  The `beq` branch at 0xa80000002003c2c4 targets 0xa80000002003c220 and is always taken.
  The return at 0xa80000002003c228 has v0 = one of 0x0, 0x1.

- `xbow_update_perf_counters` in `IP30/unix` at 0xa80000002003cf74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003cf74-0xa80000002003d07c (264 bytes).
  It occupies 264 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002003cfc0, `ld` at 0xa80000002003cff8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002003cfc4, `lw` at 0xa80000002003cfd0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa80000002003cfc8, `lbu` at 0xa80000002003d028.
  The `sd` at 0xa80000002003d008 stores 8 bytes to ?.
  The `sw` at 0xa80000002003d014 stores 4 bytes to ?.
  The `jal` at 0xa80000002003cf94 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003cfb8 calls mutex_spinlock [0xa80000002022d954] with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003d010 calls mutex_spinunlock [0xa80000002022d9a0] with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xa80000002003d050 calls timeout [0xa800000020177568] with a0=0xa80000002003cf74, a1=?, a2=0x4, a3=?.
  The `beq` branch at 0xa80000002003cfb0 targets 0xa80000002003d028 and is always taken.
  The `beq` branch at 0xa80000002003d020 targets 0xa80000002003d044, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `bne` branch at 0xa80000002003d02c targets 0xa80000002003cfb8, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `bne` branch at 0xa80000002003d03c targets 0xa80000002003d028, is taken when s1(?) < 0x2 (signed), and falls through when s1(?) >= 0x2 (signed).
  The return at 0xa80000002003d074 has v0 = ret(timeout).

- `xbow_enable_perf_counter` in `IP30/unix` at 0xa80000002003d09c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003d09c-0xa80000002003d268 (460 bytes).
  It occupies 460 bytes.
  The `ld` at 0xa80000002003d0dc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lbu` at 0xa80000002003d154 loads 1 byte from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa80000002003d190, `lbu` at 0xa80000002003d19c.
  The `sb` at 0xa80000002003d1bc stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x27.
  The `sb` at 0xa80000002003d1c0 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  The `sb` at 0xa80000002003d1c8 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x26.
  The `sb` at 0xa80000002003d1d0 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x24.
  The `lw` at 0xa80000002003d1dc loads 4 bytes from ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `sw` at 0xa80000002003d1f4 stores 4 bytes to ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `ld` at 0xa80000002003d1fc loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x28.
  The `lw` at 0xa80000002003d214 loads 4 bytes from [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0xa80000002003d234 stores 4 bytes to [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0xa80000002003d240 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x20.
  The `jal` at 0xa80000002003d0c0 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003d140 calls mutex_spinlock [0xa80000002022d954] with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?, a6=[ret(hwgraph_fastinfo_get)+16]:8.
  The `jal` at 0xa80000002003d1ac calls mutex_spinunlock [0xa80000002022d9a0] with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a7=a1-8.
  The `jal` at 0xa80000002003d23c calls timeout [0xa800000020177568] with a0=0xa80000002003cf74, a1=?, a2=0x4, a3=([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)), a6=0xfffff.
  The `jal` at 0xa80000002003d248 calls mutex_spinunlock [0xa80000002022d9a0] with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xa80000002003d258 calls mutex_spinunlock [0xa80000002022d9a0] with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a6=0x0, a7=a1-8.
  The `bne` branch at 0xa80000002003d0e0 targets 0xa80000002003d114, is taken when s3(=a1) < 0x8 (signed), and falls through when s3(=a1) >= 0x8 (signed).
  The `beq` branch at 0xa80000002003d0e8 targets 0xa80000002003d114, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bltz` branch at 0xa80000002003d0f0 targets 0xa80000002003d134, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0xa80000002003d0f8 targets 0xa80000002003d134, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0xa80000002003d100 targets 0xa80000002003d110, is taken when s0(=a3) < 0 (signed), and falls through when s0(=a3) >= 0 (signed).
  The `bne` branch at 0xa80000002003d108 targets 0xa80000002003d13c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0xa80000002003d134 targets 0xa80000002003d114 and is always taken.
  The `beq` branch at 0xa80000002003d15c targets 0xa80000002003d184, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) != 0.
  The `beq` branch at 0xa80000002003d164 targets 0xa80000002003d184, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `beq` branch at 0xa80000002003d16c targets 0xa80000002003d258 and is always taken.
  The `beq` branch at 0xa80000002003d17c targets 0xa80000002003d1bc, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `beq` branch at 0xa80000002003d184 targets 0xa80000002003d174, is taken when s0(=a3) == a6(?), and falls through when s0(=a3) != a6(?).
  The `bne` branch at 0xa80000002003d194 targets 0xa80000002003d174, is taken when a7(=a1-8) != t2(?), and falls through when a7(=a1-8) == t2(?).
  The `beq` branch at 0xa80000002003d1a0 targets 0xa80000002003d178, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa80000002003d1b4 targets 0xa80000002003d114 and is always taken.
  The `beq` branch at 0xa80000002003d250 targets 0xa80000002003d114 and is always taken.
  The `beq` branch at 0xa80000002003d260 targets 0xa80000002003d114 and is always taken.
  The return at 0xa80000002003d12c has v0 = one of -0x1, 0x0.

- `xbow_update_llp_status` in `IP30/unix` at 0xa80000002003d288 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003d288-0xa80000002003d39c (276 bytes).
  It occupies 276 bytes.
  The `ld` at 0xa80000002003d2c0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lw` at 0xa80000002003d2cc loads 4 bytes from ret(hwgraph_fastinfo_get) +0x8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002003d2e8, `lw` at 0xa80000002003d2ec.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002003d304, `ld` at 0xa80000002003d30c.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa80000002003d314, `sd` at 0xa80000002003d320.
  The `lw` at 0xa80000002003d338 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0xa80000002003d2a8 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003d2d0 calls xbow_widget_lookup [0xa80000002003bec4] with a0=[ret(hwgraph_fastinfo_get)+8], a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003d2d8 calls xwidget_name_get [0xa80000002003b2bc] with a0=ret(xbow_widget_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003d350 calls timeout [0xa800000020177568] with a0=0xa80000002003d288, a1=?, a2=0x64, a3=?.
  The `jal` at 0xa80000002003d38c calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203afc50, a2=?, a3=ret(xwidget_name_get).
  The `beq` branch at 0xa80000002003d2fc targets 0xa80000002003d324, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0xa80000002003d31c targets 0xa80000002003d37c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0xa80000002003d330 targets 0xa80000002003d2cc, is taken when s0(?) < 0x8 (signed), and falls through when s0(?) >= 0x8 (signed).
  The `beq` branch at 0xa80000002003d33c targets 0xa80000002003d358, is taken when t3(=[ret(hwgraph_fastinfo_get)+452]) == 0, and falls through when t3(=[ret(hwgraph_fastinfo_get)+452]) != 0.
  The `beq` branch at 0xa80000002003d394 targets 0xa80000002003d328 and is always taken.
  The return at 0xa80000002003d374 has v0 = one of ?, ret(timeout).

- `xbow_disable_llp_monitor` in `IP30/unix` at 0xa80000002003d39c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003d39c-0xa80000002003d3e4 (72 bytes).
  It occupies 72 bytes.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa80000002003d3c8, `sd` at 0xa80000002003d3d0.
  The `sw` at 0xa80000002003d3d8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0xa80000002003d3a4 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0xa80000002003d3cc targets 0xa80000002003d3b8, is taken when a2(?) < 0x8 (signed), and falls through when a2(?) >= 0x8 (signed).
  The return at 0xa80000002003d3dc has v0 = 0x0.

- `xbow_enable_llp_monitor` in `IP30/unix` at 0xa80000002003d3e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003d3e4-0xa80000002003d430 (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0xa80000002003d42c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0xa80000002003d3f0 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003d408 calls timeout [0xa800000020177568] with a0=0xa80000002003d288, a1=?, a2=0x64, a3=?.
  The return at 0xa80000002003d428 has v0 = 0x0.

- `xbow_bytes_to_gbr` in `IP30/unix` at 0xa80000002003d600 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003d600-0xa80000002003d664 (100 bytes).
  It occupies 100 bytes.
  The `beq` branch at 0xa80000002003d628 targets 0xa80000002003d634, is taken when at(?) >= a0 (signed), and falls through when at(?) < a0 (signed).
  The `bne` branch at 0xa80000002003d650 targets 0xa80000002003d65c, is taken when a7(?) < a5(=(a0 + a1)) (signed), and falls through when a7(?) >= a5(=(a0 + a1)) (signed).
  The return at 0xa80000002003d65c has v0 = ?.

- `xbow_gbr_to_bytes` in `IP30/unix` at 0xa80000002003d664 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003d664-0xa80000002003d67c (24 bytes).
  It occupies 24 bytes.
  The return at 0xa80000002003d674 has v0 = ?.

- `xbow_prio_bw_alloc` in `IP30/unix` at 0xa80000002003d67c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003d67c-0xa80000002003d7f0 (372 bytes).
  It occupies 372 bytes.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xa80000002003d6ec, `ld` at 0xa80000002003d6f0.
  The `ld` at 0xa80000002003d734 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `ld` at 0xa80000002003d73c loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x1d0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002003d740, `lw` at 0xa80000002003d74c.
  The `sw` at 0xa80000002003d7e0 stores 4 bytes to ?.
  The `sd` at 0xa80000002003d7e4 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `jal` at 0xa80000002003d6a8 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003d6bc calls mutex_spinlock [0xa80000002022d954] with a0=ret(hwgraph_fastinfo_get)+520, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003d70c calls xbow_bytes_to_gbr [0xa80000002003d600] with a0=a3 at entry (arg3), a1=a4 at entry (arg4), a2=one of 0x1c, 0x24, a3=?.
  The `jal` at 0xa80000002003d720 calls xbow_gbr_to_bytes [0xa80000002003d664] with a0=ret(xbow_bytes_to_gbr), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003d790 calls mutex_spinunlock [0xa80000002022d9a0] with a0=ret(hwgraph_fastinfo_get)+520, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xa80000002003d7b4 calls xbow_gbr_to_bytes [0xa80000002003d664] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003d7dc calls xbow_gbr_to_bytes [0xa80000002003d664] with a0=?, a1=?, a2=?, a3=?, a4=(ret(hwgraph_fastinfo_get) + (a2 << 0x3)).
  The `bne` branch at 0xa80000002003d6d4 targets 0xa80000002003d6f0, is taken when s0(=a1) < 0x8 (signed), and falls through when s0(=a1) >= 0x8 (signed).
  The `beq` branch at 0xa80000002003d6dc targets 0xa80000002003d6f0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002003d6e8 targets 0xa80000002003d6f4 and is always taken.
  The `bltz` branch at 0xa80000002003d718 targets 0xa80000002003d7b4, is taken when v0(=ret(xbow_bytes_to_gbr)) < 0 (signed), and falls through when v0(=ret(xbow_bytes_to_gbr)) >= 0 (signed).
  The `bne` branch at 0xa80000002003d760 targets 0xa80000002003d778, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) < a0(?) (unsigned), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) >= a0(?) (unsigned).
  The `bne` branch at 0xa80000002003d770 targets 0xa80000002003d7c4, is taken when a0(?) < 0x20 (signed), and falls through when a0(?) >= 0x20 (signed).
  The `beq` branch at 0xa80000002003d7bc targets 0xa80000002003d72c and is always taken.
  The `beq` branch at 0xa80000002003d7e8 targets 0xa80000002003d77c and is always taken.
  The return at 0xa80000002003d7ac has v0 = one of 0x0, 0x1.

- `heart_cpu_intr` in `IP30/unix` at 0xa80000002003ec64.
  The routine reads a halfword at 0xffffffffffffc3a0 and calls doacvec (0xa80000002003ec80) with its own four arguments.
  A doubleword store to the uncached address 0xffffffffaff10028 sits in the delay slot of that call (0xa80000002003ec84),
  and the routine then calls doactions (0xa80000002003ec88) and returns its result. The name suggests a HEART interrupt
  entry, but the facts do not say which device owns the store target. Grade: inferred.
  Reviewed: 2026-11-12

- `chkdebug` in `IP30/unix` at 0xa80000002003ecd4.
  The routine reads the same halfword at 0xffffffffffffc3a0 and a doubleword at the uncached address
  0xffffffffaff10030. It tests register a2 against that word (beq at 0xa80000002003ecf4). The routine computes a2
  itself, shifted by an amount taken from the halfword, so it is not the incoming a2 argument; the facts leave its
  value unresolved. Only when the result is nonzero does it store to 0xffffffffaff10028 (0xa80000002003ed00) and call
  debug (0xa80000002003ed04), with a0 = 0xa8000000203afe98, its arg1 as a1, a3 = 0xffffffffaff10000 and a4 = a
  halfword from -0x3c60 plus 42. Grade: inferred. The purpose of the test is unknown.
  Reviewed: 2026-11-12

- `heart_addr_phys_to_xio` in `IP30/unix` at 0xa80000002003f0cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003f0cc-0xa80000002003f1ec (288 bytes).
  It occupies 288 bytes.
  The `beq` branch at 0xa80000002003f0d8 targets 0xa80000002003f0e4, is taken when a0 >= 0x4000 (unsigned), and falls through when a0 < 0x4000 (unsigned).
  The `beq` branch at 0xa80000002003f0f4 targets 0xa80000002003f12c, is taken when v0(?) >= a3(=0x20000000) (unsigned), and falls through when v0(?) < a3(=0x20000000) (unsigned).
  The `bne` branch at 0xa80000002003f10c targets 0xa80000002003f134, is taken when v0(?) < a4(=0x10000000) (unsigned), and falls through when v0(?) >= a4(=0x10000000) (unsigned).
  The `beq` branch at 0xa80000002003f120 targets 0xa80000002003f1dc, is taken when a6(?) == a3(=0x8), and falls through when a6(?) != a3(=0x8).
  The `bne` branch at 0xa80000002003f14c targets 0xa80000002003f188, is taken when v0(?) < a1(=0x800000000) (unsigned), and falls through when v0(?) >= a1(=0x800000000) (unsigned).
  The `beq` branch at 0xa80000002003f15c targets 0xa80000002003f194, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa80000002003f178 targets 0xa80000002003f1e4, is taken when a3(?) == a4(=0x8), and falls through when a3(?) != a4(=0x8).
  The `bne` branch at 0xa80000002003f18c targets 0xa80000002003f1d4, is taken when v0(?) < a0(=0x1000000000) (unsigned), and falls through when v0(?) >= a0(=0x1000000000) (unsigned).
  The `beq` branch at 0xa80000002003f194 targets 0xa80000002003f1d4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xa80000002003f1c4 targets 0xa80000002003f12c, is taken when a3(?) == a4(=0x8), and falls through when a3(?) != a4(=0x8).
  The return at 0xa80000002003f12c has v0 = ?.
  The return at 0xa80000002003f180 has v0 = ?.
  The return at 0xa80000002003f1cc has v0 = ?.
  The return at 0xa80000002003f1d4 has v0 = -0x1.
  The return at 0xa80000002003f1dc has v0 = ?.
  The return at 0xa80000002003f1e4 has v0 = ?.

- `heart_addr_xio_to_phys` in `IP30/unix` at 0xa80000002003f1ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003f1ec-0xa80000002003f290 (164 bytes).
  It occupies 164 bytes.
  The `beq` branch at 0xa80000002003f200 targets 0xa80000002003f210, is taken when (a1 & v1(=0xf000000000000000)) == 0, and falls through when (a1 & v1(=0xf000000000000000)) != 0.
  The `beq` branch at 0xa80000002003f228 targets 0xa80000002003f25c, is taken when a3(=0x1000000) >= a5(?) (unsigned), and falls through when a3(=0x1000000) < a5(?) (unsigned).
  The `beq` branch at 0xa80000002003f23c targets 0xa80000002003f274, is taken when a4(=0x80000000) >= a5(?) (unsigned), and falls through when a4(=0x80000000) < a5(?) (unsigned).
  The `bne` branch at 0xa80000002003f244 targets 0xa80000002003f254, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The return at 0xa80000002003f24c has v0 = ?.
  The return at 0xa80000002003f254 has v0 = 0x0.
  The return at 0xa80000002003f26c has v0 = table(0x10000000).
  The return at 0xa80000002003f288 has v0 = table(0x800000000).

- `heart_piomap_alloc` in `IP30/unix` at 0xa80000002003f2c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003f2c8-0xa80000002003f388 (192 bytes).
  It occupies 192 bytes.
  The `sd` at 0xa80000002003f348 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0xa80000002003f34c stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0xa80000002003f350 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sw` at 0xa80000002003f354 stores 4 bytes to ret(kmem_zalloc) +0x20.
  The `sw` at 0xa80000002003f358 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sb` at 0xa80000002003f360 stores 1 byte to ret(kmem_zalloc) +0x4.
  The `jal` at 0xa80000002003f2e8 calls (unnamed) [0xa80000002003f0a4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003f300 calls heart_addr_xio_to_kva [0xa80000002003f290] with a0=?, a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xa80000002003f31c calls kmem_zalloc [0xa8000000201486a4] with a0=0x28, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002003f30c targets 0xa80000002003f380, is taken when v0(=ret(heart_addr_xio_to_kva)) == 0, and falls through when v0(=ret(heart_addr_xio_to_kva)) != 0.
  The `beq` branch at 0xa80000002003f328 targets 0xa80000002003f380, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0xa80000002003f330 targets 0xa80000002003f348, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xa80000002003f380 targets 0xa80000002003f364 and is always taken.
  The return at 0xa80000002003f378 has v0 = one of ret(kmem_zalloc), 0x0.

- `heart_dmamap_list` in `IP30/unix` at 0xa80000002003f4b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003f4b4-0xa80000002003f620 (364 bytes).
  It occupies 364 bytes.
  The `jal` at 0xa80000002003f4dc calls alenlist_cursor_init [0xa80000002013e26c] with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003f504 calls alenlist_get [0xa80000002013e4d4] with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xa80000002003f548 calls heart_addr_phys_to_xio [0xa80000002003f0cc] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003f574 calls alenlist_replace [0xa80000002013e1c0] with a0=?, a1=0x0, a2=sp-64, a3=sp-72.
  The `jal` at 0xa80000002003f5a8 calls alenlist_append [0xa80000002013e060] with a0=?, a1=ret(heart_addr_phys_to_xio), a2=?, a3=?.
  The `jal` at 0xa80000002003f5c8 calls alenlist_get [0xa80000002013e4d4] with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xa80000002003f5e4 calls alenlist_create [0xa80000002013ddf8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003f600 calls alenlist_done [0xa80000002013e044] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003f610 calls alenlist_destroy [0xa80000002013dfec] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002003f4e8 targets 0xa80000002003f5e0, is taken when (s3(=a2) & 0x4) == 0, and falls through when (s3(=a2) & 0x4) != 0.
  The `beq` branch at 0xa80000002003f50c targets 0xa80000002003f53c, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xa80000002003f514 targets 0xa80000002003f600, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002003f550 targets 0xa80000002003f59c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002003f55c targets 0xa80000002003f5b8, is taken when v1(?) == v0(=ret(heart_addr_phys_to_xio)), and falls through when v1(?) != v0(=ret(heart_addr_phys_to_xio)).
  The `beq` branch at 0xa80000002003f57c targets 0xa80000002003f5b8, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0xa80000002003f584 targets 0xa80000002003f594, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xa80000002003f58c targets 0xa80000002003f610, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002003f594 targets 0xa80000002003f51c and is always taken.
  The `bne` branch at 0xa80000002003f5b0 targets 0xa80000002003f584, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0xa80000002003f5d0 targets 0xa80000002003f548, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xa80000002003f5d8 targets 0xa80000002003f514 and is always taken.
  The `beq` branch at 0xa80000002003f5f0 targets 0xa80000002003f4f0, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0xa80000002003f5f8 targets 0xa80000002003f584 and is always taken.
  The `beq` branch at 0xa80000002003f608 targets 0xa80000002003f51c and is always taken.
  The `beq` branch at 0xa80000002003f618 targets 0xa80000002003f594 and is always taken.
  The return at 0xa80000002003f534 has v0 = one of ?, 0x0.

- `heart_dmatrans_list` in `IP30/unix` at 0xa80000002003f648 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003f648-0xa80000002003f7b4 (364 bytes).
  It occupies 364 bytes.
  The `jal` at 0xa80000002003f670 calls alenlist_cursor_init [0xa80000002013e26c] with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002003f698 calls alenlist_get [0xa80000002013e4d4] with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xa80000002003f6dc calls heart_addr_phys_to_xio [0xa80000002003f0cc] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003f708 calls alenlist_replace [0xa80000002013e1c0] with a0=?, a1=0x0, a2=sp-64, a3=sp-72.
  The `jal` at 0xa80000002003f73c calls alenlist_append [0xa80000002013e060] with a0=?, a1=ret(heart_addr_phys_to_xio), a2=?, a3=?.
  The `jal` at 0xa80000002003f75c calls alenlist_get [0xa80000002013e4d4] with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xa80000002003f778 calls alenlist_create [0xa80000002013ddf8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003f794 calls alenlist_done [0xa80000002013e044] with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002003f7a4 calls alenlist_destroy [0xa80000002013dfec] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002003f67c targets 0xa80000002003f774, is taken when (s3(=a3) & 0x4) == 0, and falls through when (s3(=a3) & 0x4) != 0.
  The `beq` branch at 0xa80000002003f6a0 targets 0xa80000002003f6d0, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xa80000002003f6a8 targets 0xa80000002003f794, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002003f6e4 targets 0xa80000002003f730, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002003f6f0 targets 0xa80000002003f74c, is taken when v1(?) == v0(=ret(heart_addr_phys_to_xio)), and falls through when v1(?) != v0(=ret(heart_addr_phys_to_xio)).
  The `beq` branch at 0xa80000002003f710 targets 0xa80000002003f74c, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0xa80000002003f718 targets 0xa80000002003f728, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xa80000002003f720 targets 0xa80000002003f7a4, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002003f728 targets 0xa80000002003f6b0 and is always taken.
  The `bne` branch at 0xa80000002003f744 targets 0xa80000002003f718, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0xa80000002003f764 targets 0xa80000002003f6dc, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xa80000002003f76c targets 0xa80000002003f6a8 and is always taken.
  The `beq` branch at 0xa80000002003f784 targets 0xa80000002003f684, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0xa80000002003f78c targets 0xa80000002003f718 and is always taken.
  The `beq` branch at 0xa80000002003f79c targets 0xa80000002003f6b0 and is always taken.
  The `beq` branch at 0xa80000002003f7ac targets 0xa80000002003f728 and is always taken.
  The return at 0xa80000002003f6c8 has v0 = one of ?, 0x0.

- `heart_intr_connect` in `IP30/unix` at 0xa80000002003fac8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003fac8-0xa80000002003fb9c (212 bytes).
  It occupies 212 bytes.
  The `lbu` at 0xa80000002003fad0 loads 1 byte from a0 (arg0 at entry) +0x5.
  The `lh` at 0xa80000002003fae0 loads 2 bytes from a0 (arg0 at entry) +0x24.
  The `sd` at 0xa80000002003fae8 stores 8 bytes to table(0xa80000002043cfe0) +0x0.
  The `sd` at 0xa80000002003faec stores 8 bytes to table(0xa80000002043cfd8) +0x0.
  The `sd` at 0xa80000002003faf0 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0xa80000002003faf4 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `lw` at 0xa80000002003faf8 loads 4 bytes from table(0xa80000002043cff0) +0x0.
  The `sh` at 0xa80000002003fb20 stores 2 bytes to table(0xa80000002043cfe8) +0x0.
  The `ll` at 0xa80000002003fb24 loads 4 bytes from table(0xa80000002043cff0) +0x0.
  The `sc` at 0xa80000002003fb2c stores 4 bytes to table(0xa80000002043cff0) +0x0.
  The `lw` at 0xa80000002003fb4c loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0xa80000002003fb48 calls heart_ithread_setup [0xa8000000200400bc] with a0=[a0+36]:2, a1=[a0+5]:1, a2=[a0+32], a3=a3 at entry (arg3), a6=table(0xa80000002043cfd8), a7=table(0xa80000002043cff0).
  The `jal` at 0xa80000002003fb6c calls heart_imr_bits_rmw [0xa80000002003e868] with a0=[a0+36]:2, a1=0x0, a2=?, a3=?.
  The `jalr` at 0xa80000002003fb8c calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002003fb18 targets 0xa80000002003fb50, is taken when (at(=entry(0xa80000002043cff0)) & 0x100) == 0, and falls through when (at(=entry(0xa80000002043cff0)) & 0x100) != 0.
  The `beql` branch at 0xa80000002003fb30 targets 0xa80000002003fb24, is taken when t3(=(entry(0xa80000002043cff0) | 0x200)) == 0, and falls through when t3(=(entry(0xa80000002043cff0) | 0x200)) != 0; its branch-likely delay slot `nop` at 0xa80000002003fb34 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa80000002003fb3c targets 0xa80000002003fb50, is taken when t1(=[0xa8000000204a7768]) == 0, and falls through when t1(=[0xa8000000204a7768]) != 0.
  The `bne` branch at 0xa80000002003fb50 targets 0xa80000002003fb8c, is taken when s2(=a3) != 0, and falls through when s2(=a3) == 0.
  The `beq` branch at 0xa80000002003fb94 targets 0xa80000002003fb5c and is always taken.
  The return at 0xa80000002003fb84 has v0 = 0x0.

- `heart_paddr_to_port` in `IP30/unix` at 0xa80000002003fc54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003fc54-0xa80000002003fd70 (284 bytes).
  It occupies 284 bytes.
  The `sd` at 0xa80000002003fcac stores 8 bytes to a1 (arg1 at entry) +0x0.
  3 such `sd` accesses store 8 bytes to a2 (arg2 at entry) +0x0, including `sd` at 0xa80000002003fcdc, `sd` at 0xa80000002003fd20, `sd` at 0xa80000002003fd58.
  The `bne` branch at 0xa80000002003fc64 targets 0xa80000002003fca4, is taken when a0 < 0x4000 (unsigned), and falls through when a0 >= 0x4000 (unsigned).
  The `bne` branch at 0xa80000002003fc8c targets 0xa80000002003fcbc, is taken when a0 < v1(=0x20004000) (unsigned), and falls through when a0 >= v1(=0x20004000) (unsigned).
  The `beq` branch at 0xa80000002003fc9c targets 0xa80000002003fcbc, is taken when a0 >= a3(=0x800000000) (unsigned), and falls through when a0 < a3(=0x800000000) (unsigned).
  The `beq` branch at 0xa80000002003fca4 targets 0xa80000002003fcb4, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0xa80000002003fcc0 targets 0xa80000002003fcec, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa80000002003fcc8 targets 0xa80000002003fcf0, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa80000002003fcd4 targets 0xa80000002003fce0, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002003fd04 targets 0xa80000002003fd38, is taken when a0 < v1(=0x800000000) (unsigned), and falls through when a0 >= v1(=0x800000000) (unsigned).
  The `beq` branch at 0xa80000002003fd10 targets 0xa80000002003fd44, is taken when a0 >= v0(=0x1000000000) (unsigned), and falls through when a0 < v0(=0x1000000000) (unsigned).
  The `beq` branch at 0xa80000002003fd18 targets 0xa80000002003fd28, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002003fd3c targets 0xa80000002003fd68, is taken when a0 < v0(=0x1000000000) (unsigned), and falls through when a0 >= v0(=0x1000000000) (unsigned).
  The `beq` branch at 0xa80000002003fd48 targets 0xa80000002003fd68, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xa80000002003fd50 targets 0xa80000002003fd5c, is taken when a2 == 0, and falls through when a2 != 0.
  The return at 0xa80000002003fcb4 has v0 = 0xfe.
  The return at 0xa80000002003fce4 has v0 = ?.
  The return at 0xa80000002003fd30 has v0 = ?.
  The return at 0xa80000002003fd60 has v0 = ?.
  The return at 0xa80000002003fd68 has v0 = 0xff.

- `heart_error_refine` in `IP30/unix` at 0xa80000002003fd70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002003fd70-0xa80000002003fe64 (244 bytes).
  It occupies 244 bytes.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xa80000002003fd70, `lw` at 0xa80000002003fe00.
  The `lbu` at 0xa80000002003fd98 loads 1 byte from a3 (arg3 at entry) +0x7.
  The `ld` at 0xa80000002003fde8 loads 8 bytes from a3 (arg3 at entry) +0x10.
  3 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xa80000002003fe10, `sw` at 0xa80000002003fe24, `sw` at 0xa80000002003fe58.
  The `sh` at 0xa80000002003fe14 stores 2 bytes to a3 (arg3 at entry) +0x6.
  The `sd` at 0xa80000002003fe2c stores 8 bytes to a3 (arg3 at entry) +0x18.
  The `sd` at 0xa80000002003fe60 stores 8 bytes to a3 (arg3 at entry) +0x38.
  The `jal` at 0xa80000002003fde4 calls heart_paddr_to_port [0xa80000002003fc54] with a0=[a3+16]:8, a1=sp-48, a2=sp-40, a3=a3 at entry (arg3), a5=[a3].
  The `jal` at 0xa80000002003fe40 calls xtalk_error_handler [0xa80000002003aaf0] with a0=[0xa8000000204a7750], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bltz` branch at 0xa80000002003fd88 targets 0xa80000002003fdc0, is taken when at(=([a3] << 0x6)) < 0 (signed), and falls through when at(=([a3] << 0x6)) >= 0 (signed).
  The `bgez` branch at 0xa80000002003fd90 targets 0xa80000002003fda8, is taken when v0(?) >= 0 (signed), and falls through when v0(?) < 0 (signed).
  The `bne` branch at 0xa80000002003fda0 targets 0xa80000002003fe40, is taken when v0(=[a3+7]:1) < 0x10 (signed), and falls through when v0(=[a3+7]:1) >= 0x10 (signed).
  The `bgez` branch at 0xa80000002003fdc4 targets 0xa80000002003fddc, is taken when v0(=([a3] << 0x1)) >= 0 (signed), and falls through when v0(=([a3] << 0x1)) < 0 (signed).
  The `bltz` branch at 0xa80000002003fdd4 targets 0xa80000002003fd90, is taken when v1(=([a3] << 0x7)) < 0 (signed), and falls through when v1(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0xa80000002003fe04 targets 0xa80000002003fe30, is taken when a3(?) >= 0x10 (signed), and falls through when a3(?) < 0x10 (signed).
  The `beq` branch at 0xa80000002003fe28 targets 0xa80000002003fe38 and is always taken.
  The `beq` branch at 0xa80000002003fe30 targets 0xa80000002003fe50, is taken when a3(?) == a6(=0xfe), and falls through when a3(?) != a6(=0xfe).
  The `beq` branch at 0xa80000002003fe38 targets 0xa80000002003fd90 and is always taken.
  The `beq` branch at 0xa80000002003fe48 targets 0xa80000002003fdac and is always taken.
  The `beq` branch at 0xa80000002003fe5c targets 0xa80000002003fe38 and is always taken.
  The return at 0xa80000002003fdb8 has v0 = one of 0x9, ret(xtalk_error_handler).

- `pcibr_release_device` in `IP30/unix` at 0xa800000020042fe4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020042fe4-0xa800000020043094 (176 bytes).
  It occupies 176 bytes.
  The `lw` at 0xa800000020043040 loads 4 bytes from (a0 + (a1 << 0x7)) +0x144.
  The `sw` at 0xa800000020043048 stores 4 bytes to (a0 + (a1 << 0x7)) +0x144.
  The `lw` at 0xa800000020043054 loads 4 bytes from (a0 + (a1 << 0x7)) +0x148.
  The `sw` at 0xa80000002004305c stores 4 bytes to (a0 + (a1 << 0x7)) +0x148.
  The `lw` at 0xa800000020043068 loads 4 bytes from (a0 + (a1 << 0x7)) +0x14c.
  The `sw` at 0xa800000020043070 stores 4 bytes to (a0 + (a1 << 0x7)) +0x14c.
  The `jal` at 0xa800000020043004 calls mutex_spinlock [0xa80000002022d954] with a0=a0+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020043080 calls mutex_io_spinunlock [0xa80000002022d860] with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=a0+128, a3=?, a5=0x8f8000, a6=(a0 + (a1 << 0x7)), a7=(a0 + (a1 << 0x7)).
  The `bne` branch at 0xa800000020043038 targets 0xa80000002004304c, is taken when s0(=a2) != at(=0x1100000), and falls through when s0(=a2) == at(=0x1100000).
  The `bne` branch at 0xa80000002004304c targets 0xa800000020043060, is taken when s0(=a2) != a5(=0x8f8000), and falls through when s0(=a2) == a5(=0x8f8000).
  The `bne` branch at 0xa800000020043060 targets 0xa800000020043078, is taken when s0(=a2) != a1(=0x898000), and falls through when s0(=a2) == a1(=0x898000).
  The return at 0xa80000002004308c has v0 = ret(mutex_io_spinunlock).

- `pcibr_close` in `IP30/unix` at 0xa8000000200430e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200430e4-0xa8000000200430ec (8 bytes).
  It occupies 8 bytes.
  The return at 0xa8000000200430e4 has v0 = 0x0.

- `pcibr_map` in `IP30/unix` at 0xa8000000200430ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200430ec-0xa8000000200431b8 (204 bytes).
  It occupies 204 bytes.
  The `ld` at 0xa800000020043128 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lh` at 0xa800000020043158 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `jal` at 0xa80000002004310c calls hwgraph_connectpt_get [0xa80000002023de6c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004311c calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043130 calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043150 calls v_mapphys [0xa8000000201a8698] with a0=a1 at entry (arg1), a1=(a2 + [ret(hwgraph_fastinfo_get)+8]:8), a2=?, a3=-0x4000.
  The `jal` at 0xa8000000200431a8 calls pcireg_control_bit_set [0xa800000020050f88] with a0=ret(hwgraph_fastinfo_get), a1=0x80000000, a2=[ret(hwgraph_fastinfo_get)+114]:2, a3=?.
  The `bne` branch at 0xa800000020043164 targets 0xa800000020043184, is taken when a2(=[ret(hwgraph_fastinfo_get)+114]:2) != 0, and falls through when a2(=[ret(hwgraph_fastinfo_get)+114]:2) == 0.
  The `bne` branch at 0xa80000002004316c targets 0xa800000020043184, is taken when v0(=ret(v_mapphys)) != 0, and falls through when v0(=ret(v_mapphys)) == 0.
  The `beq` branch at 0xa800000020043178 targets 0xa8000000200431a0, is taken when v0(=0xc00000) == s1(=a2), and falls through when v0(=0xc00000) != s1(=a2).
  The `bne` branch at 0xa800000020043180 targets 0xa8000000200431a0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa8000000200431b0 targets 0xa800000020043188 and is always taken.
  The return at 0xa800000020043198 has v0 = ret(v_mapphys).

- `pcibr_unmap` in `IP30/unix` at 0xa8000000200431b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200431b8-0xa800000020043230 (120 bytes).
  It occupies 120 bytes.
  The `lh` at 0xa8000000200431e4 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `jal` at 0xa8000000200431c0 calls hwgraph_connectpt_get [0xa80000002023de6c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200431d0 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200431dc calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043204 calls pcireg_control_get [0xa800000020050aec] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043220 calls pcireg_control_bit_clr [0xa800000020050ddc] with a0=ret(hwgraph_fastinfo_get), a1=0x80000000, a2=?, a3=?.
  The `beq` branch at 0xa8000000200431e8 targets 0xa800000020043204, is taken when at(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when at(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `beq` branch at 0xa800000020043218 targets 0xa8000000200431f4, is taken when (a1(=0x80000000) & v0(=ret(pcireg_control_get))) == 0, and falls through when (a1(=0x80000000) & v0(=ret(pcireg_control_get))) != 0.
  The `beq` branch at 0xa800000020043228 targets 0xa8000000200431f4 and is always taken.
  The return at 0xa8000000200431fc has v0 = 0x0.

- `pcibr_device_slot_get` in `IP30/unix` at 0xa800000020043230 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020043230-0xa8000000200432b8 (136 bytes).
  It occupies 136 bytes.
  The `lbu` at 0xa800000020043274 loads 1 byte from ret(pciio_info_chk) +0x21c.
  The `jal` at 0xa800000020043248 calls vertex_to_name [0xa80000002023e0dc] with a0=a0 at entry (arg0), a1=sp-288, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0xa800000020043250 calls hwgraph_connectpt_get [0xa80000002023de6c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043264 calls pciio_info_chk [0xa80000002005fcd8] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043278 calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043298 calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200432a0 calls hwgraph_connectpt_get [0xa80000002023de6c] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004325c targets 0xa8000000200432b0, is taken when s1(=-0x1) == v0(=ret(hwgraph_connectpt_get)), and falls through when s1(=-0x1) != v0(=ret(hwgraph_connectpt_get)).
  The `beq` branch at 0xa80000002004326c targets 0xa800000020043298, is taken when v0(=ret(pciio_info_chk)) == 0, and falls through when v0(=ret(pciio_info_chk)) != 0.
  The `bne` branch at 0xa8000000200432a8 targets 0xa800000020043264, is taken when s1(=-0x1) != v0(=ret(hwgraph_connectpt_get)), and falls through when s1(=-0x1) == v0(=ret(hwgraph_connectpt_get)).
  The `beq` branch at 0xa8000000200432b0 targets 0xa800000020043278 and is always taken.
  The return at 0xa800000020043290 has v0 = ?.

- `pcibr_ioctl` in `IP30/unix` at 0xa8000000200432b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200432b8-0xa800000020043428 (368 bytes).
  It occupies 368 bytes.
  The `jal` at 0xa8000000200432cc calls hwgraph_connectpt_get [0xa80000002023de6c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200432d8 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200432e4 calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043350 calls cap_able [0xa80000002022e9bc] with a0=0x2000000000, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043364 calls copyin [0xa800000020017010] with a0=a2 at entry (arg2), a1=sp-64, a2=0x10, a3=?.
  The `jal` at 0xa80000002004337c calls cap_able [0xa80000002022e9bc] with a0=0x2000000000, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043390 calls copyin [0xa800000020017010] with a0=a2 at entry (arg2), a1=sp-80, a2=0x10, a3=?.
  The `jal` at 0xa8000000200433b8 calls pcibr_device_slot_get [0xa800000020043230] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200433d8 calls pcibr_priority_bits_set [0xa80000002004652c] with a0=?, a1=?, a2=0x1, a3=?.
  The `jal` at 0xa8000000200433e8 calls pcibr_device_slot_get [0xa800000020043230] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043408 calls pcibr_priority_bits_set [0xa80000002004652c] with a0=?, a1=?, a2=0x0, a3=0xff.
  The `beq` branch at 0xa8000000200432f0 targets 0xa80000002004334c, is taken when s0(=a1) == at(=0x6701), and falls through when s0(=a1) != at(=0x6701).
  The `beq` branch at 0xa8000000200432fc targets 0xa80000002004337c, is taken when s0(=a1) == v0(=0x6702), and falls through when s0(=a1) != v0(=0x6702).
  The `beq` branch at 0xa800000020043308 targets 0xa80000002004333c, is taken when s0(=a1) == v1(=0x7001), and falls through when s0(=a1) != v1(=0x7001).
  The `beq` branch at 0xa800000020043310 targets 0xa800000020043344, is taken when s0(=a1) == a0(=0x7002), and falls through when s0(=a1) != a0(=0x7002).
  The `beq` branch at 0xa80000002004331c targets 0xa800000020043334, is taken when s0(=a1) == a1(=0x7003), and falls through when s0(=a1) != a1(=0x7003).
  The `beq` branch at 0xa800000020043334 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa80000002004333c targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa800000020043344 targets 0xa800000020043328 and is always taken.
  The `beq` branch at 0xa800000020043358 targets 0xa8000000200433a8, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0xa80000002004336c targets 0xa8000000200433b8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0xa800000020043374 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa800000020043384 targets 0xa8000000200433b0, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0xa800000020043398 targets 0xa8000000200433e8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0xa8000000200433a0 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa8000000200433a8 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa8000000200433b0 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa8000000200433c4 targets 0xa800000020043418, is taken when v0(=ret(pcibr_device_slot_get)) == a1(=0xff), and falls through when v0(=ret(pcibr_device_slot_get)) != a1(=0xff).
  The `beq` branch at 0xa8000000200433cc targets 0xa8000000200433e0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa8000000200433e0 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa8000000200433f4 targets 0xa800000020043420, is taken when v0(=ret(pcibr_device_slot_get)) == a3(=0xff), and falls through when v0(=ret(pcibr_device_slot_get)) != a3(=0xff).
  The `beq` branch at 0xa8000000200433fc targets 0xa800000020043410, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa800000020043410 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa800000020043418 targets 0xa800000020043324 and is always taken.
  The `beq` branch at 0xa800000020043420 targets 0xa800000020043324 and is always taken.
  The return at 0xa80000002004332c has v0 = one of 0x0, 0x1, 0x5, 0xe.

- `pcibr_info_get` in `IP30/unix` at 0xa800000020043428 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020043428-0xa800000020043444 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa800000020043430 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002004343c has v0 = ret(pciio_hostinfo_get).

- `pcibr_device_info_new` in `IP30/unix` at 0xa800000020043444 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020043444-0xa80000002004355c (280 bytes).
  It occupies 280 bytes.
  The `lh` at 0xa800000020043494 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0xa8000000200434ac loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sb` at 0xa8000000200434c4 stores 1 byte to ret(kmem_zalloc) +0x10.
  The `sb` at 0xa8000000200434d0 stores 1 byte to ret(kmem_zalloc) +0x21c.
  The `sw` at 0xa8000000200434f8 stores 4 bytes to ?.
  The `lw` at 0xa80000002004350c loads 4 bytes from ((a1 << 0x7) + a0) +0x110.
  The `ld` at 0xa800000020043520 loads 8 bytes from ((a1 << 0x7) + a0) +0x118.
  The `sd` at 0xa80000002004352c stores 8 bytes to ?.
  The `jal` at 0xa800000020043478 calls kmem_zalloc [0xa8000000201486a4] with a0=0x228, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200434b0 calls pciio_device_info_new [0xa800000020060140] with a0=ret(kmem_zalloc), a1=[a0+4], a2=?, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4).
  The `beq` branch at 0xa80000002004348c targets 0xa80000002004354c, is taken when at(=0xff) == s1(=a1), and falls through when at(=0xff) != s1(=a1).
  The `beq` branch at 0xa800000020043498 targets 0xa800000020043554, is taken when v0(=[a0+114]:2) == v1(=0x2), and falls through when v0(=[a0+114]:2) != v1(=0x2).
  The `beq` branch at 0xa8000000200434d4 targets 0xa800000020043530, is taken when a3(=0xff) == s1(=a1), and falls through when a3(=0xff) != s1(=a1).
  The `bne` branch at 0xa8000000200434f4 targets 0xa8000000200434dc, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `beq` branch at 0xa800000020043518 targets 0xa800000020043530, is taken when v0(?) >= v1(=[((a1 << 0x7) + a0)+272]) (signed), and falls through when v0(?) < v1(=[((a1 << 0x7) + a0)+272]) (signed).
  The `beq` branch at 0xa80000002004354c targets 0xa8000000200434a0 and is always taken.
  The `beq` branch at 0xa800000020043554 targets 0xa8000000200434a0 and is always taken.
  The return at 0xa800000020043544 has v0 = ret(kmem_zalloc).

- `pcibr_device_unregister` in `IP30/unix` at 0xa80000002004355c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004355c-0xa800000020043694 (312 bytes).
  It occupies 312 bytes.
  The `lbu` at 0xa800000020043590 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0xa800000020043594 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `ld` at 0xa80000002004359c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5e8, including `lw` at 0xa8000000200435c0, `lw` at 0xa800000020043620.
  The `lw` at 0xa8000000200435d4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `lw` at 0xa8000000200435d8 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x574.
  The `lw` at 0xa8000000200435dc loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0xa8000000200435ec loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528.
  The `lw` at 0xa8000000200435f4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `sw` at 0xa800000020043614 stores 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528.
  The `lw` at 0xa800000020043628 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5ec.
  The `jal` at 0xa80000002004356c calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004357c calls pciio_info_master_get [0xa80000002005fe5c] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004358c calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200435a4 calls xtalk_widgetdev_shutdown [0xa80000002003ac0c] with a0=[ret(hwgraph_fastinfo_get)], a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `jal` at 0xa8000000200435b0 calls pcibr_rrb_flush [0xa800000020048458] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200435cc calls mutex_spinlock [0xa80000002022d954] with a0=ret(hwgraph_fastinfo_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043610 calls do_pcibr_rrb_free_all [0xa800000020047ef4] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=[ret(pciio_hostinfo_get)+540]:1, a3=?.
  The `jal` at 0xa800000020043630 calls mutex_io_spinunlock [0xa80000002022d860] with a0=?, a1=?, a2=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512], a3=?.
  The `jal` at 0xa800000020043640 calls pcibr_rrb_alloc [0xa800000020048610] with a0=a0 at entry (arg0), a1=sp-80, a2=sp-76, a3=?.
  The `jal` at 0xa80000002004364c calls pcibr_wrb_flush [0xa8000000200485d4] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043660 calls pcibr_slot_info_free [0xa80000002004eeb0] with a0=?, a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `bltz` branch at 0xa8000000200435c4 targets 0xa800000020043648, is taken when v0(=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed), and falls through when v0(=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed).
  The return at 0xa80000002004368c has v0 = ?.

- `pcibr_driver_reg_callback` in `IP30/unix` at 0xa800000020043694 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020043694-0xa80000002004373c (168 bytes).
  It occupies 168 bytes.
  The `lbu` at 0xa8000000200436dc loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `sw` at 0xa8000000200436fc stores 4 bytes to ret(pcibr_info_get) +0x218.
  The `lw` at 0xa800000020043704 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c.
  3 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c, including `sw` at 0xa800000020043718, `sw` at 0xa800000020043720, `sw` at 0xa800000020043738.
  The `jal` at 0xa8000000200436b8 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1.
  The `jal` at 0xa8000000200436c4 calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200436d0 calls pciio_info_master_get [0xa80000002005fe5c] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200436e4 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa8000000200436a4 targets 0xa800000020043724, is taken when a1 == a6(=-0x1), and falls through when a1 != a6(=-0x1).
  The `beq` branch at 0xa8000000200436b0 targets 0xa800000020043724, is taken when a2 == a6(=-0x1), and falls through when a2 != a6(=-0x1).
  The `beq` branch at 0xa800000020043714 targets 0xa800000020043730, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `beq` branch at 0xa800000020043734 targets 0xa800000020043724 and is always taken.
  The return at 0xa800000020043728 has v0 = one of a3, ret(hwgraph_fastinfo_get).

- `pcibr_driver_unreg_callback` in `IP30/unix` at 0xa80000002004373c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004373c-0xa8000000200437e4 (168 bytes).
  It occupies 168 bytes.
  The `lbu` at 0xa800000020043784 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `sw` at 0xa8000000200437a4 stores 4 bytes to ret(pcibr_info_get) +0x218.
  The `lw` at 0xa8000000200437ac loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c.
  3 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c, including `sw` at 0xa8000000200437c0, `sw` at 0xa8000000200437c8, `sw` at 0xa8000000200437e0.
  The `jal` at 0xa800000020043760 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1.
  The `jal` at 0xa80000002004376c calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043778 calls pciio_info_master_get [0xa80000002005fe5c] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004378c calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004374c targets 0xa8000000200437cc, is taken when a1 == a6(=-0x1), and falls through when a1 != a6(=-0x1).
  The `beq` branch at 0xa800000020043758 targets 0xa8000000200437cc, is taken when a2 == a6(=-0x1), and falls through when a2 != a6(=-0x1).
  The `beq` branch at 0xa8000000200437bc targets 0xa8000000200437d8, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `beq` branch at 0xa8000000200437dc targets 0xa8000000200437cc and is always taken.
  The return at 0xa8000000200437d0 has v0 = one of a3, ret(hwgraph_fastinfo_get).

- `pcibr_detach` in `IP30/unix` at 0xa8000000200437e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200437e4-0xa800000020043974 (400 bytes).
  It occupies 400 bytes.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xa800000020043870, `lbu` at 0xa8000000200438a0.
  The `lbu` at 0xa800000020043874 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `ld` at 0xa8000000200438c0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0xf8.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xa8000000200438d8, `ld` at 0xa8000000200438e4.
  The `ld` at 0xa8000000200438e8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x60.
  The `ld` at 0xa8000000200438fc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x68.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x828, including `ld` at 0xa800000020043914, `ld` at 0xa80000002004391c.
  The `jal` at 0xa8000000200437fc calls pcibr_debug [0xa800000020046990] with a0=0x8, a1=a0 at entry (arg0), a2=0xa8000000203b09d8, a3=a3 at entry (arg3).
  The `jal` at 0xa800000020043810 calls hwgraph_traverse [0xa80000002023cd3c] with a0=a0 at entry (arg0), a1=0xa8000000203b0a08, a2=sp-64, a3=?.
  The `jal` at 0xa800000020043834 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043844 calls mutex_spinlock [0xa80000002022d954] with a0=ret(hwgraph_fastinfo_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043854 calls pcireg_intr_enable_set [0xa80000002005532c] with a0=ret(hwgraph_fastinfo_get), a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020043868 calls mutex_io_spinunlock [0xa80000002022d860] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043898 calls pcibr_slot_detach [0xa80000002004ffb8] with a0=?, a1=?, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0xa8000000200438c4 calls pciio_device_info_unregister [0xa8000000200602cc] with a0=?, a1=[ret(hwgraph_fastinfo_get)+248]:8, a2=?, a3=?.
  The `jal` at 0xa8000000200438cc calls spinlock_destroy [0xa80000002022d734] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200438d4 calls strlen [0xa8000000200178e0] with a0=[ret(hwgraph_fastinfo_get)+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200438e0 calls kmem_free [0xa800000020148710] with a0=[ret(hwgraph_fastinfo_get)+16]:8, a1=ret(strlen), a2=?, a3=?.
  The `jal` at 0xa8000000200438f4 calls rmfreemap [0xa80000002016a5dc] with a0=[ret(hwgraph_fastinfo_get)+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043908 calls rmfreemap [0xa80000002016a5dc] with a0=[ret(hwgraph_fastinfo_get)+104]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043910 calls xtalk_intr_disconnect [0xa80000002003aa9c] with a0=[ret(hwgraph_fastinfo_get)+2088]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043918 calls xtalk_intr_free [0xa80000002003aa64] with a0=[ret(hwgraph_fastinfo_get)+2088]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043924 calls kmem_free [0xa800000020148710] with a0=ret(hwgraph_fastinfo_get), a1=0xab8, a2=?, a3=?.
  The `jal` at 0xa800000020043938 calls hwgraph_info_remove_LBL [0xa80000002023c840] with a0=?, a1=0xa8000000203b09e8, a2=0x0, a3=?.
  The `jal` at 0xa800000020043950 calls hwgraph_edge_remove [0xa80000002023c494] with a0=?, a1=0xa8000000203b09f8, a2=0x0, a3=?.
  The `jal` at 0xa800000020043964 calls hwgraph_edge_remove [0xa80000002023c494] with a0=a0 at entry (arg0), a1=0xa8000000203b0a08, a2=0x0, a3=?.
  The `beq` branch at 0xa800000020043818 targets 0xa800000020043830, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xa800000020043880 targets 0xa8000000200438bc, is taken when s2(=[ret(hwgraph_fastinfo_get)+56]:1) >= a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=[ret(hwgraph_fastinfo_get)+56]:1) < a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0xa8000000200438b4 targets 0xa80000002004388c, is taken when s2(?) < a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) >= a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa8000000200438ec targets 0xa8000000200438fc, is taken when a0(=[ret(hwgraph_fastinfo_get)+96]:8) == 0, and falls through when a0(=[ret(hwgraph_fastinfo_get)+96]:8) != 0.
  The `beq` branch at 0xa800000020043900 targets 0xa800000020043910, is taken when a0(=[ret(hwgraph_fastinfo_get)+104]:8) == 0, and falls through when a0(=[ret(hwgraph_fastinfo_get)+104]:8) != 0.
  The `beq` branch at 0xa80000002004396c targets 0xa800000020043820 and is always taken.
  The return at 0xa800000020043828 has v0 = one of 0x0, 0x1.

- `pcibr_directmap_init` in `IP30/unix` at 0xa800000020043974 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020043974-0xa800000020043a08 (148 bytes).
  It occupies 148 bytes.
  The `lw` at 0xa800000020043984 loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x30, including `lbu` at 0xa8000000200439b8, `lbu` at 0xa8000000200439c0.
  The `sb` at 0xa8000000200439c8 stores 1 byte to a0 (arg0 at entry) +0x58.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x50, including `sd` at 0xa8000000200439dc, `sd` at 0xa800000020043a04.
  The `jal` at 0xa800000020043998 calls xtalk_dmatrans_addr [0xa80000002003a9a0] with a0=[a0], a1=0x0, a2=0x0, a3=0x4000, a4=0x0.
  The `jal` at 0xa8000000200439a8 calls pcireg_dirmap_diroff_set [0xa8000000200534b8] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200439b4 calls pcireg_dirmap_wid_set [0xa80000002005331c] with a0=a0 at entry (arg0), a1=[a0+48]:1, a2=?, a3=?.
  The `jal` at 0xa8000000200439cc calls pcireg_dirmap_add512_clr [0xa800000020053828] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200439f4 calls pcireg_dirmap_add512_set [0xa8000000200536a8] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa8000000200439c4 targets 0xa8000000200439f4, is taken when v0(=0x20000000) == s1(=ret(xtalk_dmatrans_addr)), and falls through when v0(=0x20000000) != s1(=ret(xtalk_dmatrans_addr)).
  The `beq` branch at 0xa800000020043a00 targets 0xa8000000200439e0 and is always taken.
  The return at 0xa8000000200439ec has v0 = one of ret(pcireg_dirmap_add512_clr), ret(pcireg_dirmap_add512_set).

- `pcibr_asic_rev` in `IP30/unix` at 0xa800000020043a08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020043a08-0xa800000020043a70 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0xa800000020043a18 calls hwgraph_traverse [0xa80000002023cd3c] with a0=a0 at entry (arg0), a1=0xa8000000203b0a10, a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0xa800000020043a40 calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=?, a1=0xa8000000203b09e8, a2=sp-24, a3=?.
  The `jal` at 0xa800000020043a4c calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa800000020043a20 targets 0xa800000020043a38, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xa800000020043a58 targets 0xa800000020043a68, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa800000020043a60 targets 0xa800000020043a30 and is always taken.
  The `beq` branch at 0xa800000020043a68 targets 0xa800000020043a2c and is always taken.
  The return at 0xa800000020043a30 has v0 = one of ?, -0x1.

- `pcibr_write_gather_flush` in `IP30/unix` at 0xa800000020043a70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020043a70-0xa800000020043aac (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0xa800000020043a94 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0xa800000020043a78 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020043a84 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020043a90 calls (unnamed) [0xa800000020043094] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0xa800000020043aa4 has v0 = 0x0.

- `pcibr_piomap_alloc` in `IP30/unix` at 0xa80000002004437c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004437c-0xa8000000200445c4 (584 bytes).
  It occupies 584 bytes.
  The `lbu` at 0xa8000000200443c4 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lw` at 0xa8000000200443dc loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0xa800000020044434 loads 8 bytes from ret(pcibr_info_get) +0x210.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa800000020044444, `ld` at 0xa800000020044450, `ld` at 0xa8000000200444dc.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004447c, `sw` at 0xa800000020044498, `sw` at 0xa8000000200444a8.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0xa800000020044488, `lh` at 0xa8000000200444b8.
  9 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa80000002004449c, `sd` at 0xa8000000200444a0, `sd` at 0xa8000000200444a4.
  The `sb` at 0xa8000000200444ac stores 1 byte to ?.
  The `jal` at 0xa8000000200443b8 calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200443cc calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020044404 calls pcibr_addr_pci_to_xio [0xa800000020043aac] with a0=a0 at entry (arg0), a1=[ret(pcibr_info_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a6 at entry (arg6).
  The `jal` at 0xa800000020044428 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004445c calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa800000020044468 calls kmem_zalloc [0xa8000000201486a4] with a0=0x60, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa8000000200444cc calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=ret(mutex_spinlock), a2=?, a3=0x2.
  The `jal` at 0xa8000000200444f0 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa800000020044510 calls xtalk_piomap_alloc [0xa80000002003a760] with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `jal` at 0xa800000020044598 calls pcibr_debug [0xa800000020046990] with a0=0x8000000, a1=a0 at entry (arg0), a2=0xa8000000203b0b78, a3=?.
  The `jal` at 0xa8000000200445b4 calls pcibr_debug [0xa800000020046990] with a0=0x8000000, a1=a0 at entry (arg0), a2=0xa8000000203b0bb0, a3=?.
  The `beq` branch at 0xa8000000200443d8 targets 0xa80000002004458c, is taken when s1(=a4) == 0, and falls through when s1(=a4) != 0.
  The `beq` branch at 0xa8000000200443e0 targets 0xa80000002004458c, is taken when s7(=a5) == 0, and falls through when s7(=a5) != 0.
  The `beq` branch at 0xa800000020044410 targets 0xa8000000200445a8, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == at(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != at(=-0x1).
  The `beq` branch at 0xa80000002004443c targets 0xa800000020044458, is taken when s0(=[ret(pcibr_info_get)+528]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+528]:8) != 0.
  The `beq` branch at 0xa800000020044448 targets 0xa800000020044560, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0xa800000020044454 targets 0xa800000020044444, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xa800000020044480 targets 0xa800000020044498, is taken when s2(=[ret(pcibr_info_get)+540]:1) == ra(=0xff), and falls through when s2(=[ret(pcibr_info_get)+540]:1) != ra(=0xff).
  The `beq` branch at 0xa80000002004448c targets 0xa800000020044498, is taken when at(=[ret(pciio_info_mfast_get)+114]:2) == a3(=0x2), and falls through when at(=[ret(pciio_info_mfast_get)+114]:2) != a3(=0x2).
  The `beq` branch at 0xa8000000200444bc targets 0xa80000002004457c, is taken when v0(=[ret(pciio_info_mfast_get)+114]:2) == a3(=0x2), and falls through when v0(=[ret(pciio_info_mfast_get)+114]:2) != a3(=0x2).
  The `beq` branch at 0xa8000000200444c4 targets 0xa8000000200444ec, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0xa8000000200444f8 targets 0xa80000002004452c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa800000020044518 targets 0xa800000020044570, is taken when v0(=ret(xtalk_piomap_alloc)) == 0, and falls through when v0(=ret(xtalk_piomap_alloc)) != 0.
  The `beq` branch at 0xa800000020044560 targets 0xa80000002004445c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa800000020044568 targets 0xa800000020044474 and is always taken.
  The `beq` branch at 0xa800000020044574 targets 0xa80000002004452c and is always taken.
  The `beq` branch at 0xa800000020044584 targets 0xa8000000200444c4 and is always taken.
  The `beq` branch at 0xa8000000200445a0 targets 0xa80000002004452c and is always taken.
  The `beq` branch at 0xa8000000200445bc targets 0xa80000002004452c and is always taken.
  The return at 0xa800000020044558 has v0 = one of ?, 0x0.

- `pcibr_piomap_free` in `IP30/unix` at 0xa8000000200445c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200445c4-0xa800000020044614 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xa8000000200445d8 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `sd` at 0xa8000000200445dc stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `ld` at 0xa8000000200445e0 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sd` at 0xa8000000200445e4 stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `lh` at 0xa8000000200445e8 loads 2 bytes from [a0+64]:8 +0x72.
  The `sw` at 0xa800000020044604 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `sw` at 0xa800000020044608 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `sd` at 0xa800000020044610 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0xa8000000200445d4 calls xtalk_piomap_free [0xa80000002003a77c] with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa8000000200445f0 targets 0xa800000020044604, is taken when at(=[[a0+64]:8+114]:2) == v0(=0x2), and falls through when at(=[[a0+64]:8+114]:2) != v0(=0x2).
  The `beq` branch at 0xa80000002004460c targets 0xa8000000200445f8 and is always taken.
  The return at 0xa8000000200445fc has v0 = 0x2.

- `pcibr_piomap_addr` in `IP30/unix` at 0xa800000020044614 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020044614-0xa800000020044640 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0xa800000020044614 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0xa800000020044618 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xa80000002004461c loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0xa80000002004462c calls xtalk_piomap_addr [0xa80000002003a798] with a0=[a0+48]:8, a1=?, a2=a2 at entry (arg2), a3=[a0+16]:8, a4=[a0+40]:8.
  The return at 0xa800000020044638 has v0 = ret(xtalk_piomap_addr).

- `pcibr_piomap_done` in `IP30/unix` at 0xa800000020044640 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020044640-0xa80000002004465c (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0xa80000002004464c loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0xa800000020044648 calls xtalk_piomap_done [0xa80000002003a7b4] with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020044654 has v0 = ret(xtalk_piomap_done).

- `pcibr_piotrans_addr` in `IP30/unix` at 0xa80000002004465c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004465c-0xa800000020044728 (204 bytes).
  It occupies 204 bytes.
  The `lbu` at 0xa800000020044690 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0xa8000000200446b4 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xa800000020044688 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020044698 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200446bc calls pcibr_addr_pci_to_xio [0xa800000020043aac] with a0=a0 at entry (arg0), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200446dc calls xtalk_piotrans_addr [0xa80000002003a7d0] with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4).
  The `jal` at 0xa800000020044718 calls pcibr_debug [0xa800000020046990] with a0=0x10000000, a1=a0 at entry (arg0), a2=0xa8000000203b0be0, a3=?.
  The `beq` branch at 0xa8000000200446c8 targets 0xa80000002004470c, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == v1(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != v1(=-0x1).
  The `beq` branch at 0xa800000020044720 targets 0xa8000000200446e8 and is always taken.
  The return at 0xa800000020044704 has v0 = one of ret(xtalk_piotrans_addr), 0x0.

- `pcibr_piospace_alloc` in `IP30/unix` at 0xa800000020044728 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020044728-0xa80000002004491c (500 bytes).
  It occupies 500 bytes.
  2 such `ld` accesses load 8 bytes from ret(pcibr_info_get) +0x1d0, including `ld` at 0xa800000020044780, `ld` at 0xa8000000200448b0.
  The `lbu` at 0xa8000000200447a0 loads 1 byte from [ret(pcibr_info_get)+464]:8 +0x8.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa8000000200447a4, `ld` at 0xa8000000200447c8, `ld` at 0xa8000000200447d8.
  The `lbu` at 0xa8000000200447b0 loads 1 byte from ?.
  The `lw` at 0xa8000000200447bc loads 4 bytes from ?.
  The `sb` at 0xa8000000200447f4 stores 1 byte to ?.
  The `sd` at 0xa8000000200448a0 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0xa8000000200448a4 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0xa8000000200448a8 stores 4 bytes to ret(kmem_zalloc) +0xc.
  The `sb` at 0xa8000000200448ac stores 1 byte to ret(kmem_zalloc) +0x8.
  The `sd` at 0xa8000000200448b8 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0xa8000000200448c4 stores 8 bytes to ret(pcibr_info_get) +0x1d0.
  The `jal` at 0xa800000020044750 calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020044760 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020044778 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200447f0 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0xa80000002004481c calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0xa800000020044834 calls pcibr_debug [0xa800000020046990] with a0=0x8000000, a1=a0 at entry (arg0), a2=0xa8000000203b0c10, a3=a2 at entry (arg2).
  The `jal` at 0xa800000020044880 calls pcibr_bus_addr_alloc [0xa80000002005060c] with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x5, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `jal` at 0xa800000020044898 calls kmem_zalloc [0xa8000000201486a4] with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa8000000200448c0 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=[ret(pcibr_info_get)+464]:8.
  The `jal` at 0xa8000000200448d4 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa8000000200448ec calls pcibr_debug [0xa800000020046990] with a0=0x8000000, a1=a0 at entry (arg0), a2=0xa8000000203b0c38, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004490c calls pcibr_bus_addr_alloc [0xa80000002005060c] with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x2, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `beq` branch at 0xa800000020044794 targets 0xa800000020044800, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0xa80000002004479c targets 0xa8000000200447b4 and is always taken.
  The `beq` branch at 0xa8000000200447a8 targets 0xa800000020044800, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa8000000200447b4 targets 0xa8000000200447a4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xa8000000200447c0 targets 0xa8000000200447a4, is taken when v1(?) != s1(=a2), and falls through when v1(?) == s1(=a2).
  The `bne` branch at 0xa8000000200447d0 targets 0xa8000000200447a4, is taken when a0(?) < s2(=a3) (unsigned), and falls through when a0(?) >= s2(=a3) (unsigned).
  The `bnel` branch at 0xa8000000200447e0 targets 0xa8000000200447a8, is taken when (a5(?) & a2(=a4-1)) != 0, and falls through when (a5(?) & a2(=a4-1)) == 0; its branch-likely delay slot `ld s0,0(s0)` at 0xa8000000200447e4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa8000000200447f8 targets 0xa800000020044840 and is always taken.
  The `beq` branch at 0xa800000020044800 targets 0xa8000000200448fc, is taken when s1(=a2) == a1(=0x2), and falls through when s1(=a2) != a1(=0x2).
  The `beq` branch at 0xa800000020044808 targets 0xa800000020044870, is taken when s1(=a2) == a3(=0x4), and falls through when s1(=a2) != a3(=0x4).
  The `beq` branch at 0xa800000020044810 targets 0xa800000020044870, is taken when s1(=a2) == a4(=0x5), and falls through when s1(=a2) != a4(=0x5).
  The `beq` branch at 0xa80000002004488c targets 0xa8000000200448d0, is taken when s0(=ret(pcibr_bus_addr_alloc)) == 0, and falls through when s0(=ret(pcibr_bus_addr_alloc)) != 0.
  The `beq` branch at 0xa8000000200448c8 targets 0xa800000020044840 and is always taken.
  The `beq` branch at 0xa8000000200448f4 targets 0xa800000020044840 and is always taken.
  The `beq` branch at 0xa800000020044914 targets 0xa80000002004488c and is always taken.
  The return at 0xa800000020044864 has v0 = one of ?, 0x0, ret(pcibr_bus_addr_alloc).
  The instructions from 0xa80000002004486c to 0xa80000002004486c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_piospace_free` in `IP30/unix` at 0xa80000002004491c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004491c-0xa800000020044a4c (304 bytes).
  It occupies 304 bytes.
  The `ld` at 0xa800000020044944 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xa80000002004495c loads 8 bytes from ret(pcibr_info_get) +0x1d0.
  The `ld` at 0xa80000002004496c loads 8 bytes from [ret(pcibr_info_get)+464]:8 +0x10.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa800000020044970, `ld` at 0xa80000002004497c, `ld` at 0xa800000020044988.
  The `sb` at 0xa8000000200449a8 stores 1 byte to ?.
  The `jal` at 0xa80000002004493c calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020044954 calls mutex_spinlock [0xa80000002022d954] with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200449ac calls mutex_io_spinunlock [0xa80000002022d860] with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?, a6=0xa8000000203b09d8.
  The `jal` at 0xa8000000200449e0 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b0ce8, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0xa8000000203b09d8.
  The `jal` at 0xa8000000200449ec calls mutex_io_spinunlock [0xa80000002022d860] with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020044a04 calls hwgraph_vertex_name_get [0xa80000002023decc] with a0=a0 at entry (arg0), a1=sp-1088, a2=0x400, a3=?.
  The `jal` at 0xa800000020044a14 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b0c68, a2=?, a3=?.
  The `jal` at 0xa800000020044a2c calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b0c88, a2=sp-1088, a3=a3 at entry (arg3).
  The `jal` at 0xa800000020044a3c calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b0cd0, a2=?, a3=?.
  The `beq` branch at 0xa800000020044960 targets 0xa800000020044998, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0xa800000020044968 targets 0xa800000020044980 and is always taken.
  The `beq` branch at 0xa800000020044974 targets 0xa800000020044998, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xa800000020044980 targets 0xa800000020044970, is taken when t8(?) != s1(=a2), and falls through when t8(?) == s1(=a2).
  The `bne` branch at 0xa80000002004498c targets 0xa8000000200449fc, is taken when t9(?) != s2(=a3), and falls through when t9(?) == s2(=a3).
  The `beq` branch at 0xa800000020044998 targets 0xa8000000200449d4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa8000000200449f4 targets 0xa8000000200449b8 and is always taken.
  The `beq` branch at 0xa800000020044a44 targets 0xa800000020044994 and is always taken.
  The return at 0xa8000000200449cc has v0 = ret(mutex_io_spinunlock).

- `pcibr_dmamap_alloc` in `IP30/unix` at 0xa800000020044c00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020044c00-0xa80000002004507c (1148 bytes).
  It occupies 1148 bytes.
  The `lw` at 0xa800000020044c40 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0xa800000020044c50 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0xa800000020044cc4 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0xa800000020044ccc loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sw` at 0xa800000020044cd4 stores 4 bytes to ret(kmem_zalloc) +0x4.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0xa800000020044cd8, `lh` at 0xa800000020044f7c.
  The `sb` at 0xa800000020044ce8 stores 1 byte to ret(kmem_zalloc) +0x28.
  The `sd` at 0xa800000020044cec stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0xa800000020044cf0 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0xa800000020044cf8 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0xa800000020044d00 stores 1 byte to ret(kmem_zalloc) +0x8.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0xa800000020044d34, `lh` at 0xa800000020044ed0.
  3 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x0, including `sw` at 0xa800000020044d84, `sw` at 0xa800000020044ecc, `sw` at 0xa800000020044f68.
  The `ld` at 0xa800000020044d88 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  6 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x38, including `sd` at 0xa800000020044d94, `sd` at 0xa800000020044ec4, `sd` at 0xa800000020044f78.
  3 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x30, including `sd` at 0xa800000020044d9c, `sd` at 0xa800000020044ec8, `sd` at 0xa800000020044fe4.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x51c, including `lw` at 0xa800000020044ee0, `lw` at 0xa800000020045008.
  The `lw` at 0xa800000020044f10 loads 4 bytes from ?.
  The `ld` at 0xa800000020044fac loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0xa800000020044ff0 stores 8 bytes to ret(kmem_zalloc) +0x50.
  The `sw` at 0xa800000020044ff4 stores 4 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0xa800000020044ff8 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sw` at 0xa800000020045000 stores 4 bytes to ret(kmem_zalloc) +0x44.
  The `lw` at 0xa800000020045020 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `jal` at 0xa800000020044c24 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020044c38 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020044c5c calls kmem_zalloc [0xa8000000201486a4] with a0=0x60, a1=?, a2=[ret(pciio_info_mfast_get)], a3=[ret(pciio_info_mfast_get)+124].
  The `jal` at 0xa800000020044cb0 calls xtalk_dmamap_alloc [0xa80000002003a914] with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa800000020044d14 calls pcibr_try_set_device [0xa800000020042b40] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000, a4=0xff.
  The `jal` at 0xa800000020044d2c calls pcibr_debug [0xa800000020046990] with a0=0x60000000, a1=a0 at entry (arg0), a2=0xa8000000203b0da8, a3=?.
  The `jal` at 0xa800000020044d48 calls kmem_free [0xa800000020148710] with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?, a4=-0x41.
  The `jal` at 0xa800000020044d74 calls pcibr_try_set_device [0xa800000020042b40] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000, a4=one of -0x41, 0xff.
  The `jal` at 0xa800000020044dc0 calls pcibr_ate_alloc [0xa8000000200472a0] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?, a4=one of -0x41, 0xff.
  The `jal` at 0xa800000020044de0 calls pcibr_try_set_device [0xa800000020042b40] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x1100000.
  The `jal` at 0xa800000020044e00 calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=a0 at entry (arg0), a2=0xa8000000203b0e08, a3=ret(pcibr_ate_alloc).
  The `jal` at 0xa800000020044e10 calls pcibr_ate_free [0xa8000000200472ec] with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?.
  The `jal` at 0xa800000020044e28 calls pcibr_debug [0xa800000020046990] with a0=0x60000000, a1=a0 at entry (arg0), a2=0xa8000000203b0dd8, a3=?.
  The `jal` at 0xa800000020044e30 calls xtalk_dmamap_free [0xa80000002003a930] with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020044e3c calls kmem_free [0xa800000020148710] with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0xa800000020044e5c calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=a0 at entry (arg0), a2=0xa8000000203b0e40, a3=?.
  The `jal` at 0xa800000020044e64 calls xtalk_dmamap_free [0xa80000002003a930] with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020044e70 calls kmem_free [0xa800000020148710] with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0xa800000020044e9c calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=a0 at entry (arg0), a2=0xa8000000203b0d78, a3=?.
  The `jal` at 0xa800000020044ea8 calls kmem_free [0xa800000020148710] with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0xa800000020044ebc calls pcibr_flags_to_d64 [0xa800000020044a4c] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=0xa8000000203b09d8, a3=?.
  The `jal` at 0xa800000020044f60 calls pcibr_flags_to_ate [0xa800000020047330] with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xa800000020044fe8 calls pcibr_ate_addr [0xa8000000200473e4] with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?, a6=0x40000000, a7=[ret(pciio_info_mfast_get)+114]:2.
  The `jal` at 0xa800000020045054 calls pcibr_rrb_alloc_more [0xa800000020048304] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a5=0x1, a7=one of 0x1, 0x2.
  The `jal` at 0xa80000002004506c calls pcibr_rrb_alloc_more [0xa800000020048304] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a6=one of 0x1, 0x2.
  The `bne` branch at 0xa800000020044c6c targets 0xa800000020044ca4, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0xa800000020044cb8 targets 0xa800000020044e90, is taken when v0(=ret(xtalk_dmamap_alloc)) == 0, and falls through when v0(=ret(xtalk_dmamap_alloc)) != 0.
  The `beq` branch at 0xa800000020044cd0 targets 0xa800000020044e80, is taken when s3(=[ret(pciio_hostinfo_get)+540]:1) == a4(=0xff), and falls through when s3(=[ret(pciio_hostinfo_get)+540]:1) != a4(=0xff).
  The `beq` branch at 0xa800000020044ce0 targets 0xa800000020044e88, is taken when t8(=[ret(pciio_info_mfast_get)+114]:2) == t9(=0x2), and falls through when t8(=[ret(pciio_info_mfast_get)+114]:2) != t9(=0x2).
  The `beq` branch at 0xa800000020044cfc targets 0xa800000020044d5c, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0xa800000020044d1c targets 0xa800000020044eb8, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0xa800000020044d3c targets 0xa800000020044d58, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xa800000020044d50 targets 0xa800000020044c78 and is always taken.
  The `beq` branch at 0xa800000020044d60 targets 0xa800000020044da0, is taken when (s0(?) & 0x1) == 0, and falls through when (s0(?) & 0x1) != 0.
  The `bne` branch at 0xa800000020044d7c targets 0xa800000020044e20, is taken when v0(=ret(pcibr_try_set_device)) != 0, and falls through when v0(=ret(pcibr_try_set_device)) == 0.
  The `beq` branch at 0xa800000020044d98 targets 0xa800000020044c78 and is always taken.
  The `beq` branch at 0xa800000020044da4 targets 0xa800000020044f48, is taken when (s0(?) & 0x8000) == 0, and falls through when (s0(?) & 0x8000) != 0.
  The `beq` branch at 0xa800000020044dcc targets 0xa800000020044e4c, is taken when v0(=ret(pcibr_ate_alloc)) == t0(=-0x1), and falls through when v0(=ret(pcibr_ate_alloc)) != t0(=-0x1).
  The `beq` branch at 0xa800000020044de8 targets 0xa800000020044f60, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0xa800000020044e18 targets 0xa800000020044e54 and is always taken.
  The `beq` branch at 0xa800000020044e44 targets 0xa800000020044c78 and is always taken.
  The `beq` branch at 0xa800000020044e78 targets 0xa800000020044c78 and is always taken.
  The `beq` branch at 0xa800000020044e80 targets 0xa800000020044ce8 and is always taken.
  The `beq` branch at 0xa800000020044e88 targets 0xa800000020044ce8 and is always taken.
  The `beq` branch at 0xa800000020044eb0 targets 0xa800000020044c78 and is always taken.
  The `bne` branch at 0xa800000020044ed8 targets 0xa800000020044f40, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0.
  The `bne` branch at 0xa800000020044ef0 targets 0xa800000020044f40, is taken when (a4(=[ret(pciio_info_mfast_get)+1308]) & a5(?)) != 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+1308]) & a5(?)) == 0.
  The `beq` branch at 0xa800000020044f18 targets 0xa800000020044f40, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `bne` branch at 0xa800000020044f38 targets 0xa800000020045050, is taken when a6(?) < a7(=one of 0x1, 0x2) (signed), and falls through when a6(?) >= a7(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0xa800000020044f40 targets 0xa800000020044c7c and is always taken.
  The `beq` branch at 0xa800000020044f58 targets 0xa800000020044dbc and is always taken.
  The `beq` branch at 0xa800000020044f80 targets 0xa800000020044fe0, is taken when a7(=[ret(pciio_info_mfast_get)+114]:2) == 0, and falls through when a7(=[ret(pciio_info_mfast_get)+114]:2) != 0.
  The `beq` branch at 0xa800000020044f8c targets 0xa800000020044fa8, is taken when (s0(?) & 0x1000) == 0, and falls through when (s0(?) & 0x1000) != 0.
  The `bgez` branch at 0xa800000020044fb4 targets 0xa800000020044fcc, is taken when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8 << 0x2b)) >= 0 (signed), and falls through when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8 << 0x2b)) < 0 (signed).
  The `beq` branch at 0xa800000020044fcc targets 0xa800000020044fe0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa800000020045014 targets 0xa800000020045048, is taken when (a6(=[ret(pciio_info_mfast_get)+1308]) & a7(?)) != 0, and falls through when (a6(=[ret(pciio_info_mfast_get)+1308]) & a7(?)) == 0.
  The `beq` branch at 0xa800000020045028 targets 0xa800000020045048, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= 0x2 (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < 0x2 (signed).
  The `bne` branch at 0xa800000020045040 targets 0xa800000020045064, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < a6(=one of 0x1, 0x2) (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= a6(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0xa800000020045048 targets 0xa800000020044c7c and is always taken.
  The `beq` branch at 0xa80000002004505c targets 0xa800000020044f40 and is always taken.
  The `beq` branch at 0xa800000020045074 targets 0xa800000020045048 and is always taken.
  The return at 0xa800000020044c9c has v0 = one of ?, ret(kmem_zalloc).

- `pcibr_dmamap_free` in `IP30/unix` at 0xa80000002004507c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004507c-0xa800000020045130 (180 bytes).
  It occupies 180 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xa800000020045084, `ld` at 0xa8000000200450f0.
  The `lbu` at 0xa800000020045088 loads 1 byte from a0 (arg0 at entry) +0x8.
  The `lh` at 0xa8000000200450ac loads 2 bytes from [a0+16]:8 +0x72.
  The `ld` at 0xa8000000200450c0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0xa8000000200450c4 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0xa8000000200450e4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0xa8000000200450f8 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `jal` at 0xa8000000200450bc calls xtalk_dmamap_free [0xa80000002003a930] with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=[a0+8]:1, a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200450dc calls pcibr_release_device [0xa800000020042fe4] with a0=[a0+16]:8, a1=?, a2=0x898000, a3=?.
  The `jal` at 0xa8000000200450f4 calls pcibr_ate_free [0xa8000000200472ec] with a0=[a0+16]:8, a1=[a0+64], a2=[a0+68], a3=?.
  The `jal` at 0xa800000020045104 calls pcibr_release_device [0xa800000020042fe4] with a0=[a0+16]:8, a1=?, a2=0x1100000, a3=?.
  The `jal` at 0xa800000020045118 calls kmem_free [0xa800000020148710] with a0=a0 at entry (arg0), a1=0x60, a2=?, a3=?.
  The `beq` branch at 0xa8000000200450a4 targets 0xa8000000200450bc, is taken when a2(=[a0+8]:1) == at(=0xff), and falls through when a2(=[a0+8]:1) != at(=0xff).
  The `beq` branch at 0xa8000000200450b0 targets 0xa8000000200450bc, is taken when v0(=[[a0+16]:8+114]:2) == v1(=0x2), and falls through when v0(=[[a0+16]:8+114]:2) != v1(=0x2).
  The `beq` branch at 0xa8000000200450cc targets 0xa8000000200450e4, is taken when (a0(=[a0]) & 0x40) == 0, and falls through when (a0(=[a0]) & 0x40) != 0.
  The `beq` branch at 0xa8000000200450e8 targets 0xa80000002004510c, is taken when a2(=[a0+68]) == 0, and falls through when a2(=[a0+68]) != 0.
  The return at 0xa800000020045128 has v0 = ret(kmem_free).

- `pcibr_dmamap_addr` in `IP30/unix` at 0xa8000000200453b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200453b8-0xa8000000200455a4 (492 bytes).
  It occupies 492 bytes.
  The `ld` at 0xa8000000200453c0 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0xa8000000200453c8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xa8000000200453ec loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lbu` at 0xa800000020045418 loads 1 byte from [a0+16]:8 +0x28.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0xa800000020045438, `ld` at 0xa800000020045518, `ld` at 0xa800000020045560.
  The `lbu` at 0xa800000020045478 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `lbu` at 0xa800000020045488 loads 1 byte from [a0+16]:8 +0x58.
  The `ld` at 0xa800000020045498 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0xa8000000200454f4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `ld` at 0xa8000000200454fc loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0xa80000002004554c loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0xa800000020045590 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0xa8000000200453e8 calls xtalk_dmamap_addr [0xa80000002003a94c] with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200454d4 calls (unnamed) [0xa800000020045130] with a0=[a0+16]:8, a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa800000020045550 calls ate_write [0xa800000020047424] with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=[a0+64], a3=?, a6=[a0+68].
  The `jal` at 0xa800000020045594 calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=[a0+4], a2=0xa8000000203b0e68, a3=a1 at entry (arg1), a4=(a1 + a2)-1, a6=[a0+68].
  The `beq` branch at 0xa800000020045404 targets 0xa800000020045474, is taken when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) != 0.
  The `beq` branch at 0xa800000020045428 targets 0xa8000000200454cc, is taken when t3(=[[a0+16]:8+40]:1) == t2(?), and falls through when t3(=[[a0+16]:8+40]:1) != t2(?).
  The `beq` branch at 0xa800000020045430 targets 0xa80000002004547c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa800000020045474 targets 0xa800000020045418 and is always taken.
  The `beq` branch at 0xa800000020045480 targets 0xa8000000200454f4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0xa800000020045490 targets 0xa8000000200454e4, is taken when v0(=[[a0+16]:8+88]:1) != t2(?), and falls through when v0(=[[a0+16]:8+88]:1) == t2(?).
  The `bne` branch at 0xa8000000200454a0 targets 0xa8000000200454ec, is taken when t1(?) < v0(=[a0+48]:8) (unsigned), and falls through when t1(?) >= v0(=[a0+48]:8) (unsigned).
  The `bne` branch at 0xa8000000200454b4 targets 0xa800000020045570, is taken when a3(=[a0+48]:8+0x80000000) < a1(?) (unsigned), and falls through when a3(=[a0+48]:8+0x80000000) >= a1(?) (unsigned).
  The `bne` branch at 0xa8000000200454bc targets 0xa800000020045560, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xa8000000200454c4 targets 0xa800000020045454 and is always taken.
  The `beq` branch at 0xa8000000200454dc targets 0xa800000020045450 and is always taken.
  The `beq` branch at 0xa8000000200454e4 targets 0xa800000020045454 and is always taken.
  The `beq` branch at 0xa8000000200454ec targets 0xa800000020045450 and is always taken.
  The `bgez` branch at 0xa800000020045508 targets 0xa800000020045518, is taken when a1(=([a0] << 0x2c)) >= 0 (signed), and falls through when a1(=([a0] << 0x2c)) < 0 (signed).
  The `bne` branch at 0xa80000002004552c targets 0xa800000020045578, is taken when a6(=[a0+68]) < a5(?) (signed), and falls through when a6(=[a0+68]) >= a5(?) (signed).
  The `beq` branch at 0xa800000020045558 targets 0xa800000020045454 and is always taken.
  The `beq` branch at 0xa800000020045568 targets 0xa800000020045450 and is always taken.
  The `beq` branch at 0xa800000020045570 targets 0xa800000020045450 and is always taken.
  The `beq` branch at 0xa80000002004559c targets 0xa800000020045450 and is always taken.
  The return at 0xa80000002004546c has v0 = one of ?, 0x0.

- `pcibr_dmamap_list` in `IP30/unix` at 0xa8000000200455a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200455a4-0xa800000020045944 (928 bytes).
  It occupies 928 bytes.
  The `ld` at 0xa8000000200455ac loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xa8000000200455b8 loads 8 bytes from a0 (arg0 at entry) +0x18.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xa800000020045600, `lw` at 0xa800000020045748, `lw` at 0xa800000020045844.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xa800000020045668, `lw` at 0xa8000000200458e0.
  The `ld` at 0xa800000020045694 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `lbu` at 0xa8000000200456f0 loads 1 byte from [a0+16]:8 +0x28.
  The `lw` at 0xa8000000200457d4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0xa800000020045870 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xa800000020045874 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lbu` at 0xa800000020045884 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `jal` at 0xa8000000200455d4 calls xtalk_dmamap_list [0xa80000002003a968] with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0xa800000020045604 calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=[a0+4], a2=0xa8000000203b0ee8, a3=a0 at entry (arg0).
  The `jal` at 0xa80000002004564c calls alenlist_cursor_init [0xa80000002013e26c] with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0xa800000020045698 calls alenlist_get [0xa80000002013e4d4] with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0xa800000020045730 calls alenlist_append [0xa80000002013e060] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004574c calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=[a0+4], a2=0xa8000000203b1088, a3=a0 at entry (arg0).
  The `jal` at 0xa800000020045770 calls alenlist_get [0xa80000002013e4d4] with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0xa80000002004578c calls alenlist_cursor_init [0xa80000002013e26c] with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0xa8000000200457fc calls ate_write [0xa800000020047424] with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=?, a3=?, a6=[a0+68].
  The `jal` at 0xa80000002004582c calls alenlist_replace [0xa80000002013e1c0] with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0xa800000020045848 calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=[a0+4], a2=0xa8000000203b1040, a3=a0 at entry (arg0).
  The `jal` at 0xa800000020045860 calls alenlist_destroy [0xa80000002013dfec] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020045890 calls (unnamed) [0xa800000020045130] with a0=[a0+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200458ac calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=[a0+4], a2=0xa8000000203b0f78, a3=a0 at entry (arg0).
  The `jal` at 0xa8000000200458c0 calls alenlist_create [0xa80000002013ddf8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200458e4 calls alenlist_done [0xa80000002013e044] with a0=ret(xtalk_dmamap_list), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020045908 calls pcibr_debug [0xa800000020046990] with a0=0x10, a1=[a0+4], a2=0xa8000000203b0fc0, a3=?, a6=[a0+68].
  The `jal` at 0xa800000020045934 calls pcibr_debug [0xa800000020046990] with a0=0x20000000, a1=[a0+4], a2=0xa8000000203b0f30, a3=a0 at entry (arg0).
  The `bne` branch at 0xa8000000200455ec targets 0xa800000020045644, is taken when v0(=ret(xtalk_dmamap_list)) != 0, and falls through when v0(=ret(xtalk_dmamap_list)) == 0.
  The `beq` branch at 0xa80000002004565c targets 0xa8000000200458bc, is taken when (s8(=a2) & 0x4) == 0, and falls through when (s8(=a2) & 0x4) != 0.
  The `beq` branch at 0xa800000020045670 targets 0xa800000020045870, is taken when (t8(=[a0]) & 0x40) == 0, and falls through when (t8(=[a0]) & 0x40) != 0.
  The `bne` branch at 0xa8000000200456a0 targets 0xa800000020045780, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0xa8000000200456d8 targets 0xa800000020045880, is taken when (a3(?) & a0(=0xf000000000000000)) == 0, and falls through when (a3(?) & a0(=0xf000000000000000)) != 0.
  The `beq` branch at 0xa8000000200456f4 targets 0xa800000020045888, is taken when a0(=[[a0+16]:8+40]:1) == v0(?), and falls through when a0(=[[a0+16]:8+40]:1) != v0(?).
  The `beq` branch at 0xa8000000200456fc targets 0xa80000002004579c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xa80000002004570c targets 0xa800000020045814, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0xa80000002004571c targets 0xa80000002004581c, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0xa800000020045738 targets 0xa800000020045760, is taken when v0(=ret(alenlist_append)) == 0, and falls through when v0(=ret(alenlist_append)) != 0.
  The `beq` branch at 0xa800000020045754 targets 0xa800000020045850 and is always taken.
  The `beq` branch at 0xa800000020045778 targets 0xa8000000200456bc, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xa800000020045780 targets 0xa8000000200458e4, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0xa800000020045794 targets 0xa800000020045614 and is always taken.
  The `beq` branch at 0xa8000000200457bc targets 0xa800000020045918, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa8000000200457e8 targets 0xa8000000200458f4, is taken when a6(=[a0+68]) < a7(?) (signed), and falls through when a6(=[a0+68]) >= a7(?) (signed).
  The `beq` branch at 0xa800000020045814 targets 0xa800000020045728, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0xa800000020045834 targets 0xa800000020045760, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0xa800000020045850 targets 0xa80000002004560c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0xa800000020045858 targets 0xa80000002004560c, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0xa800000020045868 targets 0xa800000020045610 and is always taken.
  The `beq` branch at 0xa800000020045878 targets 0xa800000020045680 and is always taken.
  The `beq` branch at 0xa800000020045880 targets 0xa8000000200456f0 and is always taken.
  The `bne` branch at 0xa800000020045898 targets 0xa800000020045814, is taken when v0(=ret(0xa800000020045130)) != 0, and falls through when v0(=ret(0xa800000020045130)) == 0.
  The `beq` branch at 0xa8000000200458b4 targets 0xa800000020045850 and is always taken.
  The `beq` branch at 0xa8000000200458cc targets 0xa800000020045924, is taken when v0(=ret(alenlist_create)) == 0, and falls through when v0(=ret(alenlist_create)) != 0.
  The `bne` branch at 0xa8000000200458d4 targets 0xa800000020045850, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0xa8000000200458dc targets 0xa80000002004566c and is always taken.
  The `beq` branch at 0xa8000000200458ec targets 0xa800000020045788 and is always taken.
  The `beq` branch at 0xa800000020045910 targets 0xa800000020045850 and is always taken.
  The `beq` branch at 0xa80000002004591c targets 0xa8000000200457c4 and is always taken.
  The `beq` branch at 0xa80000002004593c targets 0xa8000000200458d4 and is always taken.
  The return at 0xa80000002004563c has v0 = one of 0x0, ?.
  The instructions from 0xa80000002004575c to 0xa80000002004575c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmamap_done` in `IP30/unix` at 0xa800000020045944 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020045944-0xa800000020045960 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0xa800000020045950 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0xa80000002004594c calls xtalk_dmamap_done [0xa80000002003a984] with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020045958 has v0 = ret(xtalk_dmamap_done).

- `pcibr_get_dmatrans_node` in `IP30/unix` at 0xa800000020045960 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020045960-0xa800000020045968 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa800000020045960 has v0 = 0x0.

- `pcibr_dmatrans_addr` in `IP30/unix` at 0xa800000020045968 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020045968-0xa800000020045d14 (940 bytes).
  It occupies 940 bytes.
  The `lw` at 0xa8000000200459ac loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0xa8000000200459bc loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0xa8000000200459c4 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0xa800000020045a10 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `ld` at 0xa800000020045a3c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `lw` at 0xa800000020045a4c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0xa800000020045ab0, `lh` at 0xa800000020045bf0.
  The `ld` at 0xa800000020045adc loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lbu` at 0xa800000020045b04 loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `ld` at 0xa800000020045b20 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `lw` at 0xa800000020045b2c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `lbu` at 0xa800000020045b6c loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sd` at 0xa800000020045be8 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `sw` at 0xa800000020045bec stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `sw` at 0xa800000020045c10 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `sd` at 0xa800000020045c14 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x51c, including `lw` at 0xa800000020045c18, `lw` at 0xa800000020045c70.
  The `lw` at 0xa800000020045c34 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `ld` at 0xa800000020045c44 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `lw` at 0xa800000020045cc4 loads 4 bytes from ?.
  The `jal` at 0xa80000002004598c calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200459a0 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200459c8 calls xtalk_dmatrans_addr [0xa80000002003a9a0] with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020045aa0 calls (unnamed) [0xa800000020042b40] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x898000.
  The `jal` at 0xa800000020045b50 calls (unnamed) [0xa800000020042b40] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000.
  The `jal` at 0xa800000020045b80 calls (unnamed) [0xa800000020045130] with a0=ret(pciio_info_mfast_get), a1=?, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xa800000020045bac calls pcibr_debug [0xa800000020046990] with a0=0x40000000, a1=a0 at entry (arg0), a2=0xa8000000203b10d0, a3=a2 at entry (arg2), a4=(a2 + a3)-1, a5=ret(xtalk_dmatrans_addr).
  The `jal` at 0xa800000020045bd0 calls pcibr_debug [0xa800000020046990] with a0=0x40000000, a1=a0 at entry (arg0), a2=0xa8000000203b1130, a3=a2 at entry (arg2), a4=(a2 + a3)-1.
  The `jal` at 0xa800000020045be0 calls (unnamed) [0xa800000020044a4c] with a0=?, a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0xa800000020045ca0 calls pcibr_rrb_alloc_more [0xa800000020048304] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384], a7=0x1.
  The `jal` at 0xa800000020045d04 calls pcibr_rrb_alloc_more [0xa800000020048304] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a6=0x1.
  The `beq` branch at 0xa8000000200459d8 targets 0xa800000020045b90, is taken when v0(=ret(xtalk_dmatrans_addr)) == 0, and falls through when v0(=ret(xtalk_dmatrans_addr)) != 0.
  The `beq` branch at 0xa8000000200459ec targets 0xa800000020045b68, is taken when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) != 0.
  The `beq` branch at 0xa8000000200459f4 targets 0xa800000020045bbc, is taken when v0(=ret(xtalk_dmatrans_addr)) == a0(=-0x1), and falls through when v0(=ret(xtalk_dmatrans_addr)) != a0(=-0x1).
  The `beq` branch at 0xa800000020045a14 targets 0xa800000020045b7c, is taken when t8(=[ret(pciio_info_mfast_get)+40]:1) == s5(?), and falls through when t8(=[ret(pciio_info_mfast_get)+40]:1) != s5(?).
  The `beq` branch at 0xa800000020045a20 targets 0xa800000020045ad0, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) != 0.
  The `bgez` branch at 0xa800000020045a38 targets 0xa800000020045b70, is taken when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) >= 0 (signed), and falls through when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) < 0 (signed).
  The `beq` branch at 0xa800000020045a44 targets 0xa800000020045a94, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) == t8(=-0x1), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) != t8(=-0x1).
  The `bne` branch at 0xa800000020045a50 targets 0xa800000020045a90, is taken when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) != s0(?), and falls through when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) == s0(?).
  The `beq` branch at 0xa800000020045aa8 targets 0xa800000020045be0, is taken when v0(=ret(0xa800000020042b40)) == 0, and falls through when v0(=ret(0xa800000020042b40)) != 0.
  The `beq` branch at 0xa800000020045ab8 targets 0xa800000020045ac8, is taken when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xa800000020045ac0 targets 0xa800000020045a60 and is always taken.
  The `bne` branch at 0xa800000020045ad8 targets 0xa800000020045b60, is taken when s7(=0x80000000) < s4(=a3) (unsigned), and falls through when s7(=0x80000000) >= s4(=a3) (unsigned).
  The `bne` branch at 0xa800000020045ae4 targets 0xa800000020045b60, is taken when s3(?) < v0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned), and falls through when s3(?) >= v0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned).
  The `beq` branch at 0xa800000020045afc targets 0xa800000020045b60, is taken when t9(?) >= s7(=0x80000000) (unsigned), and falls through when t9(?) < s7(=0x80000000) (unsigned).
  The `bne` branch at 0xa800000020045b08 targets 0xa800000020045b60, is taken when ra(=[ret(pciio_info_mfast_get)+88]:1) != s5(?), and falls through when ra(=[ret(pciio_info_mfast_get)+88]:1) == s5(?).
  The `bne` branch at 0xa800000020045b18 targets 0xa800000020045b60, is taken when s7(=0x80000000) < at(?) (unsigned), and falls through when s7(=0x80000000) >= at(?) (unsigned).
  The `beq` branch at 0xa800000020045b24 targets 0xa800000020045b40, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) == a1(=0xffffffff), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) != a1(=0xffffffff).
  The `bne` branch at 0xa800000020045b30 targets 0xa800000020045b40, is taken when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) != s0(?), and falls through when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) == s0(?).
  The `beq` branch at 0xa800000020045b38 targets 0xa800000020045a64 and is always taken.
  The `beq` branch at 0xa800000020045b58 targets 0xa800000020045c10, is taken when v0(=ret(0xa800000020042b40)) == 0, and falls through when v0(=ret(0xa800000020042b40)) != 0.
  The `beq` branch at 0xa800000020045b60 targets 0xa800000020045a60 and is always taken.
  The `beq` branch at 0xa800000020045b68 targets 0xa800000020045a10 and is always taken.
  The `beq` branch at 0xa800000020045b74 targets 0xa800000020045a40 and is always taken.
  The `beq` branch at 0xa800000020045b88 targets 0xa800000020045a60 and is always taken.
  The `beq` branch at 0xa800000020045bb4 targets 0xa800000020045a60 and is always taken.
  The `beq` branch at 0xa800000020045bd8 targets 0xa800000020045a60 and is always taken.
  The `beq` branch at 0xa800000020045bf8 targets 0xa800000020045c70, is taken when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xa800000020045c08 targets 0xa800000020045a60 and is always taken.
  The `bne` branch at 0xa800000020045c28 targets 0xa800000020045c68, is taken when (t8(=[ret(pciio_info_mfast_get)+1308]) & t9(?)) != 0, and falls through when (t8(=[ret(pciio_info_mfast_get)+1308]) & t9(?)) == 0.
  The `beq` branch at 0xa800000020045c3c targets 0xa800000020045c68, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= 0x2 (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < 0x2 (signed).
  The `bne` branch at 0xa800000020045c60 targets 0xa800000020045c98, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < v0(=one of 0x1, 0x2) (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0xa800000020045c68 targets 0xa800000020045a60 and is always taken.
  The `beq` branch at 0xa800000020045c80 targets 0xa800000020045cb0, is taken when (t0(=[ret(pciio_info_mfast_get)+1308]) & t1(?)) == 0, and falls through when (t0(=[ret(pciio_info_mfast_get)+1308]) & t1(?)) != 0.
  The `beq` branch at 0xa800000020045c90 targets 0xa800000020045c08 and is always taken.
  The `beq` branch at 0xa800000020045ca8 targets 0xa800000020045c68 and is always taken.
  The `beq` branch at 0xa800000020045cd4 targets 0xa800000020045c08, is taken when a4(?) >= 0x2 (signed), and falls through when a4(?) < 0x2 (signed).
  The `beq` branch at 0xa800000020045cf8 targets 0xa800000020045c08, is taken when a4(?) >= v0(=one of 0x1, 0x2) (signed), and falls through when a4(?) < v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0xa800000020045d0c targets 0xa800000020045c08 and is always taken.
  The return at 0xa800000020045a88 has v0 = ?.

- `pcibr_dmatrans_list` in `IP30/unix` at 0xa800000020045d14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020045d14-0xa8000000200460dc (968 bytes).
  It occupies 968 bytes.
  The `lw` at 0xa800000020045d54 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lbu` at 0xa800000020045d5c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0xa800000020045d64 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0xa800000020045d84 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `lw` at 0xa800000020045d94 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `lbu` at 0xa800000020045eb0 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `sd` at 0xa800000020045f28 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `sw` at 0xa800000020045f2c stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `ld` at 0xa800000020045f84 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `ld` at 0xa800000020045f94 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lw` at 0xa800000020045fa4 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `sd` at 0xa800000020046020 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `sw` at 0xa800000020046028 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `lbu` at 0xa800000020046030 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `lbu` at 0xa80000002004605c loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `jal` at 0xa800000020045d28 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020045d40 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020045db8 calls xtalk_dmatrans_list [0xa80000002003a9bc] with a0=?, a1=0x0, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa800000020045dd8 calls pcibr_release_device [0xa800000020042fe4] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=one of 0x0, 0x898000, 0x8f8000, a3=?.
  The `jal` at 0xa800000020045e30 calls alenlist_cursor_init [0xa80000002013e26c] with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0xa800000020045e6c calls alenlist_get [0xa80000002013e4d4] with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0xa800000020045ee4 calls alenlist_replace [0xa80000002013e1c0] with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0xa800000020045f04 calls alenlist_get [0xa80000002013e4d4] with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0xa800000020045f3c calls alenlist_cursor_init [0xa80000002013e26c] with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0xa800000020045f5c calls (unnamed) [0xa800000020042b40] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000.
  The `jal` at 0xa800000020045f6c calls (unnamed) [0xa800000020044a4c] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0xa800000020045fc8 calls (unnamed) [0xa800000020042b40] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x8f8000.
  The `jal` at 0xa800000020045ff0 calls alenlist_destroy [0xa80000002013dfec] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046004 calls (unnamed) [0xa800000020045130] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046090 calls alenlist_append [0xa80000002013e060] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200460a8 calls alenlist_create [0xa80000002013ddf8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200460c4 calls alenlist_done [0xa80000002013e044] with a0=ret(xtalk_dmatrans_list), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa800000020045d7c targets 0xa800000020045f84, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0xa800000020045d8c targets 0xa800000020045f50, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) == ra(=-0x1), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) != ra(=-0x1).
  The `bne` branch at 0xa800000020045d98 targets 0xa800000020045f4c, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `bne` branch at 0xa800000020045dc0 targets 0xa800000020045e28, is taken when v0(=ret(xtalk_dmatrans_list)) != 0, and falls through when v0(=ret(xtalk_dmatrans_list)) == 0.
  The `beq` branch at 0xa800000020045dcc targets 0xa800000020045de0, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0xa800000020045de0 targets 0xa800000020045df0, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xa800000020045de8 targets 0xa800000020045ff0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xa800000020045e4c targets 0xa8000000200460a8, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) != 0.
  The `bne` branch at 0xa800000020045e74 targets 0xa800000020045f14, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0xa800000020045e98 targets 0xa80000002004602c, is taken when (a1(?) & v0(=0xf000000000000000)) == 0, and falls through when (a1(?) & v0(=0xf000000000000000)) != 0.
  The `beq` branch at 0xa800000020045ea0 targets 0xa8000000200460d4, is taken when v1(=-0x1) == a1(?), and falls through when v1(=-0x1) != a1(?).
  The `beq` branch at 0xa800000020045eb8 targets 0xa800000020046000, is taken when a0(=[ret(pciio_info_mfast_get)+40]:1) == v0(?), and falls through when a0(=[ret(pciio_info_mfast_get)+40]:1) != v0(?).
  The `beq` branch at 0xa800000020045ec0 targets 0xa800000020046034, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xa800000020045ed0 targets 0xa800000020046084, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0xa800000020045eec targets 0xa800000020045dcc, is taken when v0(=ret(alenlist_replace)) != 0, and falls through when v0(=ret(alenlist_replace)) == 0.
  The `beq` branch at 0xa800000020045f0c targets 0xa800000020045e80, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xa800000020045f14 targets 0xa800000020045f30, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0xa800000020045f20 targets 0xa800000020046020, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xa800000020045f30 targets 0xa8000000200460c4, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xa800000020045f44 targets 0xa800000020045df8 and is always taken.
  The `bltz` branch at 0xa800000020045f64 targets 0xa800000020045df0, is taken when v0(=ret(0xa800000020042b40)) < 0 (signed), and falls through when v0(=ret(0xa800000020042b40)) >= 0 (signed).
  The `beq` branch at 0xa800000020045f7c targets 0xa800000020045da0 and is always taken.
  The `beq` branch at 0xa800000020045f9c targets 0xa800000020045fb8, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) == s7(=0xffffffff), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) != s7(=0xffffffff).
  The `bne` branch at 0xa800000020045fa8 targets 0xa800000020045fbc, is taken when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `beq` branch at 0xa800000020045fb0 targets 0xa800000020045db0 and is always taken.
  The `bltz` branch at 0xa800000020045fd0 targets 0xa800000020045df0, is taken when v0(=ret(0xa800000020042b40)) < 0 (signed), and falls through when v0(=ret(0xa800000020042b40)) >= 0 (signed).
  The `beq` branch at 0xa800000020045fe8 targets 0xa800000020045dac and is always taken.
  The `beq` branch at 0xa800000020045ff8 targets 0xa800000020045df4 and is always taken.
  The `bne` branch at 0xa800000020046010 targets 0xa800000020045ecc, is taken when v0(=ret(0xa800000020045130)) != 0, and falls through when v0(=ret(0xa800000020045130)) == 0.
  The `beq` branch at 0xa800000020046018 targets 0xa800000020045dcc and is always taken.
  The `beq` branch at 0xa800000020046024 targets 0xa800000020045f30 and is always taken.
  The `beq` branch at 0xa80000002004602c targets 0xa800000020045eb0 and is always taken.
  The `bne` branch at 0xa80000002004603c targets 0xa800000020045dcc, is taken when s7(=one of 0x80000000, 0x1000000000000) < a2(?) (unsigned), and falls through when s7(=one of 0x80000000, 0x1000000000000) >= a2(?) (unsigned).
  The `beq` branch at 0xa800000020046048 targets 0xa800000020045dcc, is taken when t9(?) >= s7(=one of 0x80000000, 0x1000000000000) (unsigned), and falls through when t9(?) < s7(=one of 0x80000000, 0x1000000000000) (unsigned).
  The `bne` branch at 0xa800000020046054 targets 0xa800000020045dcc, is taken when a1(?) < ra(?) (unsigned), and falls through when a1(?) >= ra(?) (unsigned).
  The `bne` branch at 0xa800000020046060 targets 0xa800000020045dcc, is taken when at(=[ret(pciio_info_mfast_get)+88]:1) != v0(?), and falls through when at(=[ret(pciio_info_mfast_get)+88]:1) == v0(?).
  The `bne` branch at 0xa800000020046074 targets 0xa800000020045dcc, is taken when s7(=one of 0x80000000, 0x1000000000000) < v1(?) (unsigned), and falls through when s7(=one of 0x80000000, 0x1000000000000) >= v1(?) (unsigned).
  The `beq` branch at 0xa80000002004607c targets 0xa800000020045ecc and is always taken.
  The `bne` branch at 0xa800000020046098 targets 0xa800000020045dcc, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0xa8000000200460a0 targets 0xa800000020045ef4 and is always taken.
  The `beq` branch at 0xa8000000200460b4 targets 0xa800000020045e58, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0xa8000000200460bc targets 0xa800000020045dcc and is always taken.
  The `beq` branch at 0xa8000000200460cc targets 0xa800000020045f38 and is always taken.
  The `beq` branch at 0xa8000000200460d4 targets 0xa800000020045df4 and is always taken.
  The return at 0xa800000020045e20 has v0 = one of 0x0, ?.

- `pcibr_dmamap_drain` in `IP30/unix` at 0xa8000000200460dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200460dc-0xa8000000200460f8 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0xa8000000200460e8 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0xa8000000200460e4 calls xtalk_dmamap_drain [0xa80000002003a9d8] with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa8000000200460f0 has v0 = ret(xtalk_dmamap_drain).

- `pcibr_dmaaddr_drain` in `IP30/unix` at 0xa8000000200460f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200460f8-0xa800000020046138 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0xa800000020046118 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xa800000020046108 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020046110 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046120 calls xtalk_dmaaddr_drain [0xa80000002003a9f4] with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0xa800000020046130 has v0 = ret(xtalk_dmaaddr_drain).

- `pcibr_dmalist_drain` in `IP30/unix` at 0xa800000020046138 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046138-0xa800000020046170 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0xa800000020046154 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xa800000020046144 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004614c calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046158 calls xtalk_dmalist_drain [0xa80000002003aa10] with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=?, a3=?.
  The return at 0xa800000020046168 has v0 = ret(xtalk_dmalist_drain).

- `pcibr_dmamap_pciaddr_get` in `IP30/unix` at 0xa800000020046170 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046170-0xa800000020046178 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa800000020046174 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The return at 0xa800000020046170 has v0 = [a0+56]:8.

- `pcibr_provider_startup` in `IP30/unix` at 0xa800000020046178 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046178-0xa800000020046180 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa800000020046178 has v0 = ?.

- `pcibr_provider_shutdown` in `IP30/unix` at 0xa800000020046180 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046180-0xa800000020046188 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa800000020046180 has v0 = ?.

- `pcibr_reset` in `IP30/unix` at 0xa800000020046188 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046188-0xa800000020046444 (700 bytes).
  It occupies 700 bytes.
  The `lbu` at 0xa80000002004619c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0xa8000000200461b0 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `lbu` at 0xa8000000200461b4 loads 1 byte from ret(pciio_info_mfast_get) +0x31.
  The `lw` at 0xa8000000200461c4 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x100.
  The `lbu` at 0xa8000000200461dc loads 1 byte from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x104.
  The `lbu` at 0xa8000000200461ec loads 1 byte from ret(pciio_info_mfast_get) +0x33.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa800000020046218, `lw` at 0xa80000002004638c.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa800000020046230, `ld` at 0xa800000020046258, `ld` at 0xa800000020046304.
  The `sw` at 0xa800000020046278 stores 4 bytes to ?.
  3 such `ld` accesses load 8 bytes from table(0x0) +0x0, including `ld` at 0xa800000020046418, `ld` at 0xa80000002004642c, `ld` at 0xa800000020046440.
  The `jal` at 0xa800000020046194 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200461a8 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046208 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)), a3=a0 at entry (arg0).
  The `jal` at 0xa80000002004626c calls pcibr_func_config_get [0xa80000002004de64] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0xa80000002004629c calls pcireg_control_bit_clr [0xa800000020050ddc] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200462a4 calls nano_delay [0xa8000000201788b8] with a0=sp-128, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200462b0 calls pcireg_control_bit_set [0xa800000020050f88] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200462b8 calls nano_delay [0xa8000000201788b8] with a0=sp-128, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200462dc calls pcibr_func_config_set [0xa80000002004defc] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046390 calls pcibr_func_config_set [0xa80000002004defc] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0xa8000000200463b0 calls mutex_io_spinunlock [0xa80000002022d860] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200463d4 calls pcibr_debug [0xa800000020046990] with a0=0x8, a1=a0 at entry (arg0), a2=0xa8000000203b1190, a3=a0 at entry (arg0).
  The `beq` branch at 0xa8000000200461d4 targets 0xa8000000200461e0, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+256]) == 0, and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+256]) != 0.
  The `bne` branch at 0xa8000000200461e4 targets 0xa8000000200463c4, is taken when s3(?) < a0(=[ret(pciio_info_mfast_get)+49]:1) (signed), and falls through when s3(?) >= a0(=[ret(pciio_info_mfast_get)+49]:1) (signed).
  The `bne` branch at 0xa8000000200461f4 targets 0xa8000000200463c4, is taken when a4(=[ret(pciio_info_mfast_get)+51]:1) < s3(?) (signed), and falls through when a4(=[ret(pciio_info_mfast_get)+51]:1) >= s3(?) (signed).
  The `blez` branch at 0xa80000002004622c targets 0xa80000002004627c, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0xa800000020046234 targets 0xa800000020046408 and is always taken.
  The `beq` branch at 0xa800000020046250 targets 0xa80000002004627c, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0xa80000002004625c targets 0xa80000002004623c, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xa800000020046274 targets 0xa80000002004623c and is always taken.
  The `blez` branch at 0xa8000000200462c0 targets 0xa8000000200463a0, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0xa8000000200462c8 targets 0xa80000002004641c and is always taken.
  The `beq` branch at 0xa8000000200462ec targets 0xa800000020046320, is taken when s0(?) >= 0x6 (signed), and falls through when s0(?) < 0x6 (signed).
  The `bne` branch at 0xa800000020046308 targets 0xa8000000200462d0, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xa800000020046318 targets 0xa8000000200462f4, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0xa800000020046330 targets 0xa800000020046354, is taken when s7(?) >= s6(?) (signed), and falls through when s7(?) < s6(?) (signed).
  The `beq` branch at 0xa800000020046344 targets 0xa800000020046320, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002004634c targets 0xa8000000200462f8 and is always taken.
  The `beq` branch at 0xa800000020046354 targets 0xa800000020046430 and is always taken.
  The `beq` branch at 0xa80000002004636c targets 0xa8000000200463a0, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0xa800000020046378 targets 0xa80000002004635c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa800000020046398 targets 0xa800000020046360 and is always taken.
  The `beq` branch at 0xa8000000200463b8 targets 0xa8000000200463e0 and is always taken.
  The `beq` branch at 0xa800000020046414 targets 0xa80000002004625c and is always taken.
  The `beq` branch at 0xa800000020046428 targets 0xa80000002004633c and is always taken.
  The `beq` branch at 0xa80000002004643c targets 0xa800000020046378 and is always taken.
  The return at 0xa800000020046400 has v0 = one of -0x1, 0x0.
  The instructions from 0xa8000000200463c0 to 0xa8000000200463c0 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_endian_set` in `IP30/unix` at 0xa800000020046444 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046444-0xa80000002004652c (232 bytes).
  It occupies 232 bytes.
  The `lbu` at 0xa800000020046468 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0xa80000002004649c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0xa800000020046520 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `jal` at 0xa800000020046460 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020046470 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046480 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200464c0 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa8000000200464e0 calls pcibr_debug [0xa800000020046990] with a0=0x4000000, a1=a0 at entry (arg0), a2=0xa8000000203b11b8, a3=[ret(pciio_hostinfo_get)+540]:1, a5=0xa80000002043ef58.
  The `jal` at 0xa80000002004650c calls pcireg_device_set [0xa800000020058294] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8, a4=0x180000, a7=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `jal` at 0xa80000002004651c calls pcireg_tflush_get [0xa800000020052634] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `beq` branch at 0xa800000020046498 targets 0xa8000000200464a8, is taken when s0(=a1) == s2(=a2), and falls through when s0(=a1) != s2(=a2).
  The `beq` branch at 0xa8000000200464a0 targets 0xa8000000200464ac and is always taken.
  The `bne` branch at 0xa8000000200464b0 targets 0xa800000020046504, is taken when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) != s0(?), and falls through when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) == s0(?).
  The `beq` branch at 0xa800000020046524 targets 0xa8000000200464b8 and is always taken.
  The return at 0xa8000000200464fc has v0 = a2.

- `pcibr_priority_bits_set` in `IP30/unix` at 0xa80000002004652c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004652c-0xa800000020046688 (348 bytes).
  It occupies 348 bytes.
  The `lw` at 0xa800000020046550 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `ld` at 0xa800000020046598 loads 8 bytes from (a0 + (a1 << 0x7)) +0x138.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x140, including `lw` at 0xa8000000200465f8, `lw` at 0xa800000020046638.
  2 such `sw` accesses store 4 bytes to (a0 + (a1 << 0x7)) +0x140, including `sw` at 0xa800000020046608, `sw` at 0xa800000020046650.
  The `sd` at 0xa800000020046624 stores 8 bytes to (a0 + (a1 << 0x7)) +0x138.
  The `jal` at 0xa800000020046584 calls mutex_spinlock [0xa80000002022d954] with a0=a0+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200465d8 calls mutex_io_spinunlock [0xa80000002022d860] with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa80000002004661c calls pcireg_device_set [0xa800000020058294] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa800000020046628 calls pcireg_tflush_get [0xa800000020052634] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004656c targets 0xa800000020046578, is taken when a2 == v0(=0x2), and falls through when a2 != v0(=0x2).
  The `beq` branch at 0xa8000000200465a0 targets 0xa8000000200465f8, is taken when s2(=a2) == a0(=0x1), and falls through when s2(=a2) != a0(=0x1).
  The `beq` branch at 0xa8000000200465a8 targets 0xa8000000200465f8, is taken when s2(=a2) == t8(=0x2), and falls through when s2(=a2) != t8(=0x2).
  The `beq` branch at 0xa8000000200465b0 targets 0xa800000020046638, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0xa8000000200465b8 targets 0xa800000020046614, is taken when a2(=[(a0 + (a1 << 0x7))+312]:8) != s3(?), and falls through when a2(=[(a0 + (a1 << 0x7))+312]:8) == s3(?).
  The `bne` branch at 0xa800000020046604 targets 0xa8000000200465b8, is taken when t9(=[(a0 + (a1 << 0x7))+320]+1) != a0(=0x1), and falls through when t9(=[(a0 + (a1 << 0x7))+320]+1) == a0(=0x1).
  The `beq` branch at 0xa80000002004660c targets 0xa80000002004665c and is always taken.
  The `beq` branch at 0xa800000020046630 targets 0xa8000000200465c0 and is always taken.
  The `blez` branch at 0xa800000020046640 targets 0xa8000000200465b8, is taken when a0(=[(a0 + (a1 << 0x7))+320]) <= 0 (signed), and falls through when a0(=[(a0 + (a1 << 0x7))+320]) > 0 (signed).
  The `bne` branch at 0xa80000002004664c targets 0xa8000000200465b8, is taken when a0(=[(a0 + (a1 << 0x7))+320]-1) != 0, and falls through when a0(=[(a0 + (a1 << 0x7))+320]-1) == 0.
  The `beq` branch at 0xa800000020046654 targets 0xa80000002004666c and is always taken.
  The `beq` branch at 0xa80000002004665c targets 0xa800000020046680, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa800000020046664 targets 0xa8000000200465b8 and is always taken.
  The `beq` branch at 0xa80000002004666c targets 0xa8000000200465b8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa800000020046678 targets 0xa8000000200465b8 and is always taken.
  The `beq` branch at 0xa800000020046680 targets 0xa8000000200465b8 and is always taken.
  The return at 0xa8000000200465f0 has v0 = one of -0x1, 0x0.

- `pcibr_priority_set` in `IP30/unix` at 0xa800000020046688 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046688-0xa8000000200466d4 (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0xa8000000200466a8 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0xa800000020046698 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200466a4 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200466b4 calls pcibr_priority_bits_set [0xa80000002004652c] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The return at 0xa8000000200466cc has v0 = a1.

- `pcibr_device_flags_set` in `IP30/unix` at 0xa8000000200466d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200466d4-0xa8000000200468d4 (512 bytes).
  It occupies 512 bytes.
  The `lbu` at 0xa8000000200466f0 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lh` at 0xa8000000200467cc loads 2 bytes from ret(pciio_info_mfast_get) +0x72.
  The `ld` at 0xa800000020046804 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0xa800000020046890 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `lw` at 0xa8000000200468b4 loads 4 bytes from ret(pciio_info_mfast_get) +0x78.
  The `jal` at 0xa8000000200466e8 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020046700 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200467f0 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=(a1 << 0x2c), a2=?, a3=(a1 << 0x2b), a7=(a1 << 0x25).
  The `jal` at 0xa800000020046828 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa800000020046848 calls pcibr_debug [0xa800000020046990] with a0=0x4000000, a1=a0 at entry (arg0), a2=0xa8000000203b11e0, a3=[ret(pciio_hostinfo_get)+540]:1, a5=0xa80000002043ef58.
  The `jal` at 0xa80000002004687c calls pcireg_device_set [0xa800000020058294] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `jal` at 0xa80000002004688c calls pcireg_tflush_get [0xa800000020052634] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `bgez` branch at 0xa800000020046734 targets 0xa80000002004689c, is taken when v0(=(a1 << 0x2f)) >= 0 (signed), and falls through when v0(=(a1 << 0x2f)) < 0 (signed).
  The `bgez` branch at 0xa80000002004673c targets 0xa800000020046748, is taken when a3(=(a1 << 0x2e)) >= 0 (signed), and falls through when a3(=(a1 << 0x2e)) < 0 (signed).
  The `bgez` branch at 0xa80000002004674c targets 0xa800000020046758, is taken when v1(=(a1 << 0x2d)) >= 0 (signed), and falls through when v1(=(a1 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0xa80000002004675c targets 0xa80000002004676c, is taken when a1(=(a1 << 0x2c)) >= 0 (signed), and falls through when a1(=(a1 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0xa80000002004676c targets 0xa80000002004677c, is taken when a3(=(a1 << 0x2b)) >= 0 (signed), and falls through when a3(=(a1 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0xa80000002004677c targets 0xa80000002004678c, is taken when a4(=(a1 << 0x2a)) >= 0 (signed), and falls through when a4(=(a1 << 0x2a)) < 0 (signed).
  The `bgez` branch at 0xa80000002004678c targets 0xa800000020046798, is taken when a5(=(a1 << 0x29)) >= 0 (signed), and falls through when a5(=(a1 << 0x29)) < 0 (signed).
  The `beq` branch at 0xa80000002004679c targets 0xa8000000200467ac, is taken when (s2(=a1) & a0(=0x800000)) == 0, and falls through when (s2(=a1) & a0(=0x800000)) != 0.
  The `bgez` branch at 0xa8000000200467b0 targets 0xa8000000200467bc, is taken when a7(=(a1 << 0x25)) >= 0 (signed), and falls through when a7(=(a1 << 0x25)) < 0 (signed).
  The `bgez` branch at 0xa8000000200467c0 targets 0xa8000000200467cc, is taken when t0(=(a1 << 0x24)) >= 0 (signed), and falls through when t0(=(a1 << 0x24)) < 0 (signed).
  The `beq` branch at 0xa8000000200467d4 targets 0xa8000000200468ac, is taken when t1(=[ret(pciio_info_mfast_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(pciio_info_mfast_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0xa8000000200467dc targets 0xa8000000200467f0, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xa8000000200467e4 targets 0xa800000020046854, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0xa800000020046814 targets 0xa800000020046874, is taken when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) != s2(?), and falls through when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) == s2(?).
  The `beq` branch at 0xa800000020046894 targets 0xa80000002004681c and is always taken.
  The `bltz` branch at 0xa80000002004689c targets 0xa800000020046744, is taken when a3(=(a1 << 0x2e)) < 0 (signed), and falls through when a3(=(a1 << 0x2e)) >= 0 (signed).
  The `beq` branch at 0xa8000000200468a4 targets 0xa80000002004674c and is always taken.
  The `beq` branch at 0xa8000000200468ac targets 0xa8000000200467dc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa8000000200468c0 targets 0xa8000000200467dc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa8000000200468cc targets 0xa8000000200467dc and is always taken.
  The return at 0xa80000002004686c has v0 = 0x1.

- `pcibr_pcix_rbars_calc` in `IP30/unix` at 0xa8000000200468d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200468d4-0xa800000020046964 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0xa8000000200468d4 loads 4 bytes from a0 (arg0 at entry) +0x508.
  The `lw` at 0xa800000020046908 loads 4 bytes from a0 (arg0 at entry) +0x50c.
  The `ld` at 0xa800000020046948 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `jal` at 0xa800000020046950 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b1208, a2=[a0+16]:8, a3=0x10, a4=[a0+1288], a7=a0 at entry (arg0).
  The `beq` branch at 0xa8000000200468e8 targets 0xa800000020046938, is taken when a4(=[a0+1288]) == 0, and falls through when a4(=[a0+1288]) != 0.
  The `beq` branch at 0xa8000000200468f4 targets 0xa800000020046940, is taken when a4(=[a0+1288]) >= 0x11 (signed), and falls through when a4(=[a0+1288]) < 0x11 (signed).
  The `bne` branch at 0xa800000020046920 targets 0xa800000020046930, is taken when v0(?) < 0x65 (signed), and falls through when v0(?) >= 0x65 (signed).
  The `beq` branch at 0xa800000020046928 targets 0xa800000020046934 and is always taken.
  The `beq` branch at 0xa80000002004695c targets 0xa800000020046938 and is always taken.
  The return at 0xa800000020046938 has v0 = one of 0x13, ?, 0x0.

- `pcibr_dma_enabled` in `IP30/unix` at 0xa800000020046964 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046964-0xa800000020046990 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0xa800000020046980 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xa80000002004696c calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020046974 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004697c calls xtalk_dma_enabled [0xa80000002003ac28] with a0=[ret(pciio_info_mfast_get)], a1=?, a2=?, a3=?.
  The return at 0xa800000020046988 has v0 = ret(xtalk_dma_enabled).

- `pcibr_debug` in `IP30/unix` at 0xa800000020046990 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046990-0xa800000020046bc0 (560 bytes).
  It occupies 560 bytes.
  The `lh` at 0xa800000020046b7c loads 2 bytes from abs 0xffffffffffffc3a0.
  The `jal` at 0xa8000000200469c4 calls blkclr [0xa80000002001738c] with a0=sp-624, a1=0x100, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200469fc calls hwgraph_vertex_name_get [0xa80000002023decc] with a0=a1 at entry (arg1), a1=sp-624, a2=0x100, a3=?.
  The `jal` at 0xa800000020046a30 calls strcmp [0xa800000020128838] with a0=?, a1=[0xa8000000204a7790]:8, a2=?, a3=?.
  The `jal` at 0xa800000020046a50 calls kmem_zalloc [0xa8000000201486a4] with a0=0x400, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020046a94 calls strcmp [0xa800000020128838] with a0=0xa8000000203b12a0, a1=[0xa8000000204a7790]:8, a2=?, a3=?.
  The `jal` at 0xa800000020046aa4 calls strcpy [0xa80000002012895c] with a0=sp-368, a1=sp-624, a2=?, a3=?.
  The `jal` at 0xa800000020046ab4 calls strstr [0xa800000020128af8] with a0=sp-368, a1=0xa8000000203b1278, a2=?, a3=?.
  The `jal` at 0xa800000020046ad8 calls strstr [0xa800000020128af8] with a0=sp-624, a1=0xa8000000203b12a8, a2=?, a3=?.
  The `jal` at 0xa800000020046af8 calls strstr [0xa800000020128af8] with a0=sp-624, a1=0xa8000000203b12b0, a2=[0xa8000000204a779c], a3=?.
  The `jal` at 0xa800000020046b2c calls atoi [0xa800000020128cfc] with a0=ret(strstr)+7, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046b40 calls atoi [0xa800000020128cfc] with a0=ret(strstr)+5, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020046b64 calls strtok_r [0xa800000020128c54] with a0=ret(strstr)+7, a1=0xa8000000203b12a4, a2=sp-112, a3=?.
  The `jal` at 0xa800000020046b80 calls printf [0xa8000000201c78ec] with a0=0xa8000000203b1288, a1=[-0x3c60]:2, a2=sp-624, a3=?.
  The `jal` at 0xa800000020046b90 calls vsprintf [0xa8000000201c781c] with a0=ret(kmem_zalloc), a1=a2 at entry (arg2), a2=sp-40, a3=?.
  The `jal` at 0xa800000020046ba4 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b12b8, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa800000020046bb0 calls kmem_free [0xa800000020148710] with a0=ret(kmem_zalloc), a1=0x400, a2=?, a3=?.
  The `beq` branch at 0xa8000000200469e4 targets 0xa800000020046a60, is taken when (v1(=[0xa8000000204a7788]) & a0) == 0, and falls through when (v1(=[0xa8000000204a7788]) & a0) != 0.
  The `beq` branch at 0xa8000000200469ec targets 0xa800000020046a7c, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0xa800000020046a04 targets 0xa800000020046a90, is taken when v0(=ret(hwgraph_vertex_name_get)) == 0, and falls through when v0(=ret(hwgraph_vertex_name_get)) != 0.
  The `beq` branch at 0xa800000020046a24 targets 0xa800000020046a50, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0xa800000020046a38 targets 0xa800000020046a60, is taken when v0(=ret(strcmp)) != 0, and falls through when v0(=ret(strcmp)) == 0.
  The `bne` branch at 0xa800000020046a40 targets 0xa800000020046a60, is taken when t9(=[0xa8000000204a7798]) != s2(?), and falls through when t9(=[0xa8000000204a7798]) == s2(?).
  The `bne` branch at 0xa800000020046a48 targets 0xa800000020046a60, is taken when ra(=[0xa8000000204a779c]) != s3(?), and falls through when ra(=[0xa8000000204a779c]) == s3(?).
  The `bne` branch at 0xa800000020046a58 targets 0xa800000020046b74, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0xa800000020046a88 targets 0xa800000020046a1c and is always taken.
  The `beq` branch at 0xa800000020046a9c targets 0xa800000020046b10, is taken when v0(=ret(strcmp)) == 0, and falls through when v0(=ret(strcmp)) != 0.
  The `bne` branch at 0xa800000020046abc targets 0xa800000020046b54, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0xa800000020046acc targets 0xa800000020046b1c, is taken when t8(=[0xa8000000204a7798]) == s3(=-0x1), and falls through when t8(=[0xa8000000204a7798]) != s3(=-0x1).
  The `bne` branch at 0xa800000020046ae0 targets 0xa800000020046b2c, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0xa800000020046aec targets 0xa800000020046b24, is taken when a2(=[0xa8000000204a779c]) == s3(=-0x1), and falls through when a2(=[0xa8000000204a779c]) != s3(=-0x1).
  The `bne` branch at 0xa800000020046b00 targets 0xa800000020046b40, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0xa800000020046b08 targets 0xa800000020046a1c and is always taken.
  The `beq` branch at 0xa800000020046b14 targets 0xa800000020046ac8 and is always taken.
  The `beq` branch at 0xa800000020046b1c targets 0xa800000020046ae8 and is always taken.
  The `beq` branch at 0xa800000020046b24 targets 0xa800000020046a1c and is always taken.
  The `beq` branch at 0xa800000020046b38 targets 0xa800000020046ae8 and is always taken.
  The `beq` branch at 0xa800000020046b4c targets 0xa800000020046a1c and is always taken.
  The `beq` branch at 0xa800000020046b6c targets 0xa800000020046ac8 and is always taken.
  The `beq` branch at 0xa800000020046bb8 targets 0xa800000020046a64 and is always taken.
  The return at 0xa800000020046a74 has v0 = one of ?, ret(kmem_free).

- `pcibr_businfo_get` in `IP30/unix` at 0xa800000020046bc0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046bc0-0xa800000020046c00 (64 bytes).
  It occupies 64 bytes.
  The `sw` at 0xa800000020046bd8 stores 4 bytes to ret(pciio_info_mfast_get) +0xaa0.
  The `sw` at 0xa800000020046be4 stores 4 bytes to ret(pciio_info_mfast_get) +0xaa4.
  The `sw` at 0xa800000020046bec stores 4 bytes to ret(pciio_info_mfast_get) +0xaa8.
  The `sw` at 0xa800000020046bf4 stores 4 bytes to ret(pciio_info_mfast_get) +0xaac.
  The `jal` at 0xa800000020046bc8 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020046bd0 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The return at 0xa800000020046bf8 has v0 = ret(pciio_info_mfast_get)+2720.

- `pcibr_pio_flush_read` in `IP30/unix` at 0xa800000020046cac (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046cac-0xa800000020046d18 (108 bytes).
  It occupies 108 bytes.
  The `lbu` at 0xa800000020046ce0 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0xa800000020046ce4 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `ld` at 0xa800000020046cf4 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `sd` at 0xa800000020046cfc stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `lhu` at 0xa800000020046d00 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `sh` at 0xa800000020046d08 stores 2 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0xa800000020046d0c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `sw` at 0xa800000020046d14 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `beq` branch at 0xa800000020046cb8 targets 0xa800000020046ce0, is taken when a3 == at(=0x1), and falls through when a3 != at(=0x1).
  The `beq` branch at 0xa800000020046cc0 targets 0xa800000020046d00, is taken when a3 == v0(=0x2), and falls through when a3 != v0(=0x2).
  The `beq` branch at 0xa800000020046cc8 targets 0xa800000020046d0c, is taken when a3 == a5(=0x4), and falls through when a3 != a5(=0x4).
  The `bne` branch at 0xa800000020046cd0 targets 0xa800000020046cec, is taken when a3 != a6(=0x8), and falls through when a3 == a6(=0x8).
  The `beq` branch at 0xa800000020046cd8 targets 0xa800000020046cf4 and is always taken.
  The `beq` branch at 0xa800000020046cf8 targets 0xa800000020046ce8 and is always taken.
  The `beq` branch at 0xa800000020046d04 targets 0xa800000020046ce8 and is always taken.
  The `beq` branch at 0xa800000020046d10 targets 0xa800000020046ce8 and is always taken.
  The return at 0xa800000020046cec has v0 = one of 0x0, 0x1.

- `pcibr_pio_flush_del` in `IP30/unix` at 0xa800000020046d18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046d18-0xa800000020046d20 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa800000020046d18 has v0 = ?.

- `pcibr_pio_flush_init` in `IP30/unix` at 0xa800000020046d20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020046d20-0xa800000020046d28 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa800000020046d20 has v0 = 0x0.

- `pcibr_init_ext_ate_ram` in `IP30/unix` at 0xa800000020047140 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020047140-0xa8000000200472a0 (352 bytes).
  It occupies 352 bytes.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa800000020047180, `lw` at 0xa8000000200471a8, `lw` at 0xa8000000200471cc.
  The `lw` at 0xa800000020047214 loads 4 bytes from table(0xa80000002043eac0) +0x0.
  The `ld` at 0xa800000020047218 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0xa800000020047220 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0xa80000002004718c calls pcireg_ext_ate_set [0xa80000002005a55c] with a0=a0 at entry (arg0), a1=?, a2=0x123456789abcdef, a3=?.
  The `jal` at 0xa8000000200471b4 calls pcireg_ext_ate_set [0xa80000002005a55c] with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0xa8000000200471d4 calls pcireg_ext_ate_get [0xa80000002005a390] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200471f8 calls pcireg_ssram_size_set [0xa800000020051124] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004722c calls pcibr_debug [0xa800000020046990] with a0=0x10, a1=[a0+4], a2=0xa8000000203b1648, a3=[a0+8]:8, a4=entry(0xa80000002043eac0).
  The `jal` at 0xa80000002004724c calls pcireg_ext_ate_set [0xa80000002005a55c] with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0xa800000020047290 calls pcibr_debug [0xa800000020046990] with a0=0x10, a1=[a0+4], a2=0xa8000000203b1678, a3=[a0+8]:8.
  The `bne` branch at 0xa800000020047198 targets 0xa8000000200471cc, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `bne` branch at 0xa8000000200471c4 targets 0xa8000000200471a4, is taken when s4(?) < s0(?) (signed), and falls through when s4(?) >= s0(?) (signed).
  The `bne` branch at 0xa8000000200471f0 targets 0xa800000020047178, is taken when s0(?) < 0x4 (unsigned), and falls through when s0(?) >= 0x4 (unsigned).
  The `beq` branch at 0xa800000020047210 targets 0xa800000020047234, is taken when (t8(=[0xa8000000204a7788]) & 0x10) == 0, and falls through when (t8(=[0xa8000000204a7788]) & 0x10) != 0.
  The `beq` branch at 0xa80000002004721c targets 0xa800000020047288, is taken when s2(=entry(0xa80000002043eac0)) == 0, and falls through when s2(=entry(0xa80000002043eac0)) != 0.
  The `blez` branch at 0xa80000002004723c targets 0xa800000020047264, is taken when s2(=entry(0xa80000002043eac0)) <= 0 (signed), and falls through when s2(=entry(0xa80000002043eac0)) > 0 (signed).
  The `bne` branch at 0xa80000002004725c targets 0xa800000020047248, is taken when s0(?) < s2(=entry(0xa80000002043eac0)) (signed), and falls through when s0(?) >= s2(=entry(0xa80000002043eac0)) (signed).
  The `beq` branch at 0xa800000020047298 targets 0xa800000020047238 and is always taken.
  The return at 0xa800000020047280 has v0 = entry(0xa80000002043eac0).

- `pcibr_ate_alloc` in `IP30/unix` at 0xa8000000200472a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200472a0-0xa8000000200472ec (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0xa8000000200472b4 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0xa8000000200472c4 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0xa8000000200472b0 calls rmalloc [0xa80000002016abb0] with a0=[a0+96]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200472d0 calls rmalloc [0xa80000002016abb0] with a0=[a0+104]:8, a1=a1 at entry (arg1), a2=?, a3=?, a4=(ret(rmalloc) << 0x0).
  The `bne` branch at 0xa8000000200472bc targets 0xa8000000200472dc, is taken when a4(=(ret(rmalloc) << 0x0)) != 0, and falls through when a4(=(ret(rmalloc) << 0x0)) == 0.
  The `beq` branch at 0xa8000000200472c8 targets 0xa8000000200472e0, is taken when a0(=[a0+104]:8) == 0, and falls through when a0(=[a0+104]:8) != 0.
  The return at 0xa8000000200472e4 has v0 = (ret(rmalloc) << 0x0)-1.

- `pcibr_ate_free` in `IP30/unix` at 0xa8000000200472ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200472ec-0xa800000020047330 (68 bytes).
  It occupies 68 bytes.
  The `lh` at 0xa8000000200472ec loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `ld` at 0xa80000002004730c loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0xa800000020047310 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0xa80000002004731c calls rmfree [0xa80000002016ade8] with a0=?, a1=a2 at entry (arg2), a2=a1+1, a3=a3 at entry (arg3), a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `beq` branch at 0xa800000020047300 targets 0xa800000020047310, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0xa800000020047308 targets 0xa800000020047314 and is always taken.
  The return at 0xa800000020047328 has v0 = ret(rmfree).

- `pcibr_flags_to_ate` in `IP30/unix` at 0xa800000020047330 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020047330-0xa8000000200473e4 (180 bytes).
  It occupies 180 bytes.
  The `beq` branch at 0xa800000020047344 targets 0xa800000020047358, is taken when (a0 & 0x10) == 0, and falls through when (a0 & 0x10) != 0.
  The `beq` branch at 0xa800000020047360 targets 0xa80000002004736c, is taken when (a0 & 0x400) == 0, and falls through when (a0 & 0x400) != 0.
  The `beq` branch at 0xa80000002004736c targets 0xa80000002004737c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bgez` branch at 0xa800000020047380 targets 0xa80000002004738c, is taken when a2(=(a0 << 0x29)) >= 0 (signed), and falls through when a2(=(a0 << 0x29)) < 0 (signed).
  The `bgez` branch at 0xa80000002004738c targets 0xa800000020047398, is taken when a3(=(a0 << 0x28)) >= 0 (signed), and falls through when a3(=(a0 << 0x28)) < 0 (signed).
  The `bgez` branch at 0xa8000000200473a8 targets 0xa8000000200473b4, is taken when a5(=(a0 << 0x2d)) >= 0 (signed), and falls through when a5(=(a0 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0xa8000000200473b4 targets 0xa8000000200473c0, is taken when a4(=(a0 << 0x2c)) >= 0 (signed), and falls through when a4(=(a0 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0xa8000000200473c4 targets 0xa8000000200473d0, is taken when a6(=(a0 << 0x2b)) >= 0 (signed), and falls through when a6(=(a0 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0xa8000000200473d0 targets 0xa8000000200473dc, is taken when a3(=(a0 << 0x2a)) >= 0 (signed), and falls through when a3(=(a0 << 0x2a)) < 0 (signed).
  The return at 0xa8000000200473dc has v0 = ?.

- `pcibr_ate_addr` in `IP30/unix` at 0xa8000000200473e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200473e4-0xa800000020047424 (64 bytes).
  It occupies 64 bytes.
  The `lh` at 0xa8000000200473e4 loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0xa8000000200473f8 calls pcireg_int_ate_addr [0xa80000002005adcc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020047408 calls pcireg_ext_ate_addr [0xa80000002005a728] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa8000000200473f0 targets 0xa800000020047408, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0xa800000020047400 targets 0xa800000020047414 and is always taken.
  The return at 0xa80000002004741c has v0 = one of ret(pcireg_int_ate_addr), ret(pcireg_ext_ate_addr).

- `pcibr_rrb_alloc_init` in `IP30/unix` at 0xa800000020048134 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020048134-0xa800000020048304 (464 bytes).
  It occupies 464 bytes.
  The `ld` at 0xa800000020048144 loads 8 bytes from a0 (arg0 at entry) +0x8.
  3 such `lw` accesses load 4 bytes from (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x568, including `lw` at 0xa800000020048170, `lw` at 0xa8000000200481d8, `lw` at 0xa800000020048248.
  The `sw` at 0xa8000000200481b4 stores 4 bytes to ((a1 << 0x2) + a0) +0x528.
  2 such `sw` accesses store 4 bytes to (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x568, including `sw` at 0xa8000000200481ec, `sw` at 0xa80000002004825c.
  The `lw` at 0xa8000000200481f0 loads 4 bytes from ((a1 << 0x2) + a0) +0x528.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa8000000200481fc, `lw` at 0xa800000020048234.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004820c, `sw` at 0xa80000002004823c.
  The `lh` at 0xa800000020048298 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0xa8000000200482cc loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0xa8000000200481c4 calls do_pcibr_rrb_alloc [0xa800000020047a18] with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0xa800000020048258 calls do_pcibr_rrb_free [0xa800000020047c4c] with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0xa8000000200482d0 calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=[a0+4], a2=0xa8000000203b1758, a3=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384], a5=a3 at entry (arg3), a7=a2 at entry (arg2).
  The `jal` at 0xa8000000200482ec calls pcibr_rrb_debug [0xa800000020049628] with a0=0xa8000000203b17b8, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0xa80000002004819c targets 0xa800000020048210, is taken when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384]) >= a3 (signed), and falls through when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384]) < a3 (signed).
  The `beq` branch at 0xa8000000200481ac targets 0xa8000000200481f0 and is always taken.
  The `bltz` branch at 0xa8000000200481cc targets 0xa800000020048214, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0xa8000000200481e8 targets 0xa800000020048214, is taken when s1(?) >= s2(=a3) (signed), and falls through when s1(?) < s2(=a3) (signed).
  The `bgtz` branch at 0xa8000000200481f4 targets 0xa8000000200481b4, is taken when a2(=[((a1 << 0x2) + a0)+1320]) > 0 (signed), and falls through when a2(=[((a1 << 0x2) + a0)+1320]) <= 0 (signed).
  The `blez` branch at 0xa800000020048200 targets 0xa800000020048214, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0xa800000020048208 targets 0xa8000000200481b8 and is always taken.
  The `beq` branch at 0xa80000002004822c targets 0xa800000020048270, is taken when s2(=a3) >= s1(?) (signed), and falls through when s2(=a3) < s1(?) (signed).
  The `bne` branch at 0xa800000020048268 targets 0xa800000020048234, is taken when s2(=a3) < s1(?) (signed), and falls through when s2(=a3) >= s1(?) (signed).
  The `beq` branch at 0xa80000002004828c targets 0xa8000000200482ac, is taken when at(=a1) == v0(=0xff), and falls through when at(=a1) != v0(=0xff).
  The `beq` branch at 0xa8000000200482a0 targets 0xa8000000200482ac, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The return at 0xa8000000200482fc has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_alloc_more` in `IP30/unix` at 0xa800000020048304 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020048304-0xa800000020048458 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0xa80000002004830c loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0xa800000020048378 stores 4 bytes to ((a1 << 0x2) + a0) +0x528.
  The `lw` at 0xa80000002004839c loads 4 bytes from (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x568.
  The `sw` at 0xa8000000200483ac stores 4 bytes to (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x568.
  The `lw` at 0xa8000000200483b0 loads 4 bytes from ((a1 << 0x2) + a0) +0x528.
  The `lw` at 0xa8000000200483c0 loads 4 bytes from ?.
  The `sw` at 0xa8000000200483d4 stores 4 bytes to ?.
  The `lh` at 0xa8000000200483ec loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0xa800000020048418 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0xa800000020048388 calls do_pcibr_rrb_alloc [0xa800000020047a18] with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1, a5=[((a1 << 0x2) + a0)+1320]-1.
  The `jal` at 0xa80000002004841c calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=[a0+4], a2=0xa8000000203b17d0, a3=?, a4=a3 at entry (arg3), a6=a2 at entry (arg2).
  The `jal` at 0xa80000002004842c calls pcibr_rrb_debug [0xa800000020049628] with a0=0xa8000000203b1820, a1=a0 at entry (arg0), a2=?, a3=?.
  The `blez` branch at 0xa800000020048348 targets 0xa8000000200483d8, is taken when a3 <= 0 (signed), and falls through when a3 > 0 (signed).
  The `beq` branch at 0xa800000020048370 targets 0xa8000000200483b0 and is always taken.
  The `bltz` branch at 0xa800000020048390 targets 0xa8000000200483e0, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0xa8000000200483a8 targets 0xa8000000200483dc, is taken when s0(?) >= s3(=a3) (signed), and falls through when s0(?) < s3(=a3) (signed).
  The `bgtz` branch at 0xa8000000200483b4 targets 0xa800000020048378, is taken when a5(=[((a1 << 0x2) + a0)+1320]) > 0 (signed), and falls through when a5(=[((a1 << 0x2) + a0)+1320]) <= 0 (signed).
  The `blez` branch at 0xa8000000200483c8 targets 0xa8000000200483dc, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `beq` branch at 0xa8000000200483d0 targets 0xa80000002004837c and is always taken.
  The `beq` branch at 0xa8000000200483e4 targets 0xa8000000200483fc, is taken when s8(=a1) == a2(=0xff), and falls through when s8(=a1) != a2(=0xff).
  The `beq` branch at 0xa8000000200483f0 targets 0xa8000000200483fc, is taken when a3(=[a0+114]:2) == a4(=0x2), and falls through when a3(=[a0+114]:2) != a4(=0x2).
  The return at 0xa800000020048450 has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_flush` in `IP30/unix` at 0xa800000020048458 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020048458-0xa8000000200485d4 (380 bytes).
  It occupies 380 bytes.
  The `ld` at 0xa800000020048480 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0xa800000020048484, `lw` at 0xa8000000200484b0, `lw` at 0xa800000020048594.
  The `lbu` at 0xa800000020048490 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0xa800000020048460 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020048478 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200484d0 calls pcireg_rrb_get [0xa800000020058b74] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200484e8 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020048538 calls do_pcibr_rrb_flush [0xa800000020048094] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020048564 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `beq` branch at 0xa8000000200484a8 targets 0xa800000020048594, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0xa8000000200484bc targets 0xa8000000200485b4, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0xa800000020048510 targets 0xa80000002004852c and is always taken.
  The `beq` branch at 0xa800000020048524 targets 0xa800000020048554, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0xa800000020048530 targets 0xa800000020048518, is taken when s3(?) != t9(?), and falls through when s3(?) == t9(?).
  The `bne` branch at 0xa80000002004854c targets 0xa80000002004852c, is taken when s2(?) < 0x8 (signed), and falls through when s2(?) >= 0x8 (signed).
  The `bne` branch at 0xa8000000200485a4 targets 0xa8000000200484b0, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0xa8000000200485ac targets 0xa8000000200485cc and is always taken.
  The `bne` branch at 0xa8000000200485c4 targets 0xa8000000200484c4, is taken when a3(?) != a4(=0x24), and falls through when a3(?) == a4(=0x24).
  The `beq` branch at 0xa8000000200485cc targets 0xa8000000200484c4 and is always taken.
  The return at 0xa80000002004858c has v0 = ret(mutex_io_spinunlock).

- `pcibr_wrb_flush` in `IP30/unix` at 0xa8000000200485d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200485d4-0xa800000020048610 (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0xa8000000200485ec loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0xa8000000200485f0 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `jal` at 0xa8000000200485dc calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200485e8 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200485f4 calls pcireg_wrb_flush_get [0xa800000020058920] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0xa800000020048608 has v0 = 0x0.

- `pcibr_rrb_alloc` in `IP30/unix` at 0xa800000020048610 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020048610-0xa800000020048a14 (1028 bytes).
  It occupies 1028 bytes.
  The `lbu` at 0xa800000020048634 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0xa800000020048648 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0xa80000002004865c, `lw` at 0xa800000020048690, `lw` at 0xa8000000200486fc.
  2 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5e8, including `lw` at 0xa8000000200486b0, `lw` at 0xa800000020048720.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa8000000200486d8, `lw` at 0xa800000020048764, `lw` at 0xa8000000200488d4.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa8000000200486e0, `sw` at 0xa8000000200488e4, `sw` at 0xa800000020048960.
  3 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528, including `lw` at 0xa8000000200486ec, `lw` at 0xa800000020048730, `lw` at 0xa8000000200488d0.
  The `sw` at 0xa8000000200486f4 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x548.
  The `lw` at 0xa800000020048738 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `lw` at 0xa80000002004873c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0xa800000020048750 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0xa80000002004879c loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `sw` at 0xa800000020048890 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0xa8000000200488a4 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0xa8000000200488b0 loads 4 bytes from ret(pciio_info_mfast_get) +0x51c.
  The `sw` at 0xa8000000200488c4 stores 4 bytes to ret(pciio_info_mfast_get) +0x51c.
  The `sw` at 0xa8000000200488c8 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `sw` at 0xa8000000200488cc stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0xa8000000200488e8 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x548.
  2 such `sw` accesses store 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528, including `sw` at 0xa8000000200488f0, `sw` at 0xa800000020048954.
  The `jal` at 0xa80000002004862c calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004863c calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020048650 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004885c calls do_pcibr_rrb_alloc [0xa800000020047a18] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0xa800000020048878 calls do_pcibr_rrb_alloc [0xa800000020047a18] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?, a6=[ret(pciio_info_mfast_get)+8]:8.
  The `jal` at 0xa80000002004896c calls pcibr_rrb_debug [0xa800000020049628] with a0=0xa8000000203b1838, a1=ret(pciio_info_mfast_get), a2=?, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2))+1320], a5=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)).
  The `jal` at 0xa8000000200489a0 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa8000000200489ec calls do_pcibr_rrb_free [0xa800000020047c4c] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0xa800000020048a04 calls do_pcibr_rrb_free [0xa800000020047c4c] with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?.
  The `beq` branch at 0xa800000020048684 targets 0xa8000000200489c4, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0xa8000000200486a0 targets 0xa8000000200486f8, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `bgez` branch at 0xa8000000200486b4 targets 0xa80000002004872c, is taken when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed), and falls through when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed).
  The `bne` branch at 0xa8000000200486dc targets 0xa8000000200486c4, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0xa8000000200486f0 targets 0xa800000020048734 and is always taken.
  The `bne` branch at 0xa80000002004870c targets 0xa8000000200486a8, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `bltz` branch at 0xa800000020048724 targets 0xa8000000200486bc, is taken when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed), and falls through when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed).
  The `beq` branch at 0xa800000020048744 targets 0xa800000020048790, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0xa80000002004874c targets 0xa800000020048798, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `bne` branch at 0xa800000020048780 targets 0xa8000000200487b8, is taken when a1(?) < t1(?) (signed), and falls through when a1(?) >= t1(?) (signed).
  The `beq` branch at 0xa800000020048788 targets 0xa800000020048818 and is always taken.
  The `beq` branch at 0xa800000020048790 targets 0xa800000020048754, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0xa800000020048798 targets 0xa800000020048754 and is always taken.
  The `beq` branch at 0xa8000000200487b0 targets 0xa800000020048818, is taken when a1(?) >= v1(?) (signed), and falls through when a1(?) < v1(?) (signed).
  The `beq` branch at 0xa8000000200487b8 targets 0xa8000000200487dc, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0xa8000000200487c0 targets 0xa8000000200487d0, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0xa8000000200487c8 targets 0xa8000000200487dc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa8000000200487d4 targets 0xa8000000200487e4 and is always taken.
  The `beq` branch at 0xa8000000200487ec targets 0xa800000020048818, is taken when a1(?) >= a4(?) (signed), and falls through when a1(?) < a4(?) (signed).
  The `beq` branch at 0xa8000000200487f4 targets 0xa8000000200487a0, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0xa8000000200487fc targets 0xa80000002004880c, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0xa800000020048804 targets 0xa8000000200487a0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xa800000020048810 targets 0xa8000000200487a8 and is always taken.
  The `beq` branch at 0xa800000020048818 targets 0xa800000020048828, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xa800000020048824 targets 0xa8000000200489bc, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa80000002004882c targets 0xa80000002004883c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa800000020048834 targets 0xa8000000200489bc, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bltz` branch at 0xa80000002004883c targets 0xa8000000200489e4, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `bltz` branch at 0xa800000020048844 targets 0xa8000000200489fc, is taken when s0(?) < 0 (signed), and falls through when s0(?) >= 0 (signed).
  The `blez` branch at 0xa80000002004884c targets 0xa800000020048864, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `blez` branch at 0xa800000020048864 targets 0xa800000020048880, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0xa800000020048884 targets 0xa80000002004889c, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0xa80000002004888c targets 0xa8000000200488a4, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `beq` branch at 0xa800000020048894 targets 0xa8000000200488ac and is always taken.
  The `beq` branch at 0xa80000002004889c targets 0xa8000000200488ac, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `blez` branch at 0xa8000000200488ec targets 0xa800000020048948, is taken when s6(=one of 0x2, 0x4) <= 0 (signed), and falls through when s6(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0xa80000002004891c targets 0xa800000020048948, is taken when a1(?) >= s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) < s6(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0xa800000020048940 targets 0xa8000000200488f8, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0xa800000020048948 targets 0xa800000020048968, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0xa8000000200489bc targets 0xa800000020048978 and is always taken.
  The `bne` branch at 0xa8000000200489d4 targets 0xa800000020048690, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0xa8000000200489dc targets 0xa800000020048718 and is always taken.
  The `beq` branch at 0xa8000000200489f4 targets 0xa800000020048844 and is always taken.
  The `beq` branch at 0xa800000020048a0c targets 0xa80000002004884c and is always taken.
  The return at 0xa8000000200489b4 has v0 = one of -0x1, 0x0.

- `pcibr_rrb_check` in `IP30/unix` at 0xa800000020048a14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020048a14-0xa800000020048b48 (308 bytes).
  It occupies 308 bytes.
  The `lbu` at 0xa800000020048a64 loads 1 byte from ret(pciio_info_mfast_get) +0x39.
  The `lbu` at 0xa800000020048a68 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0xa800000020048ab0 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `sw` at 0xa800000020048ab8 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0xa800000020048ac4 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528.
  The `sw` at 0xa800000020048acc stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `lw` at 0xa800000020048b04 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `sw` at 0xa800000020048b0c stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0xa800000020048b20 loads 4 bytes from ?.
  The `sw` at 0xa800000020048b24 stores 4 bytes to a4 (arg4 at entry) +0x0.
  The `jal` at 0xa800000020048a38 calls pciio_hostinfo_get [0xa80000002005fd5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020048a50 calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0xa800000020048a88 calls mutex_spinlock [0xa80000002022d954] with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0xa800000020048b28 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=([ret(pciio_hostinfo_get)+540]:1 << 0x4), a3=([ret(pciio_hostinfo_get)+540]:1 << 0x2).
  The `beq` branch at 0xa800000020048a48 targets 0xa800000020048ad8, is taken when v0(=ret(pciio_hostinfo_get)) == 0, and falls through when v0(=ret(pciio_hostinfo_get)) != 0.
  The `beq` branch at 0xa800000020048a5c targets 0xa800000020048b40, is taken when v0(=ret(pciio_info_mfast_get)) == 0, and falls through when v0(=ret(pciio_info_mfast_get)) != 0.
  The `beq` branch at 0xa800000020048a78 targets 0xa800000020048b38, is taken when at(=[ret(pciio_hostinfo_get)+540]:1) >= v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed), and falls through when at(=[ret(pciio_hostinfo_get)+540]:1) < v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed).
  The `beq` branch at 0xa800000020048aa4 targets 0xa800000020048afc, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `bne` branch at 0xa800000020048ab4 targets 0xa800000020048b00, is taken when s4(=a2) != 0, and falls through when s4(=a2) == 0.
  The `beq` branch at 0xa800000020048abc targets 0xa800000020048b10, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `bne` branch at 0xa800000020048ac8 targets 0xa800000020048b14, is taken when s2(=a4) != 0, and falls through when s2(=a4) == 0.
  The `beq` branch at 0xa800000020048ad0 targets 0xa800000020048b28 and is always taken.
  The `beq` branch at 0xa800000020048afc targets 0xa800000020048abc, is taken when s4(=a2) == 0, and falls through when s4(=a2) != 0.
  The `bne` branch at 0xa800000020048b08 targets 0xa800000020048ac0, is taken when s3(=a3) != 0, and falls through when s3(=a3) == 0.
  The `beq` branch at 0xa800000020048b10 targets 0xa800000020048b28, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0xa800000020048b30 targets 0xa800000020048ad8 and is always taken.
  The `beq` branch at 0xa800000020048b38 targets 0xa800000020048adc and is always taken.
  The `beq` branch at 0xa800000020048b40 targets 0xa800000020048adc and is always taken.
  The return at 0xa800000020048af4 has v0 = one of -0x1, 0x0.

- `pcibr_slot_initial_rrb_alloc` in `IP30/unix` at 0xa800000020048f1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020048f1c-0xa8000000200492d0 (948 bytes).
  It occupies 948 bytes.
  The `lbu` at 0xa800000020048f5c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0xa800000020048f70 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0xa800000020048f74, `lw` at 0xa800000020048f8c, `lw` at 0xa800000020049148.
  8 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa800000020048fd0, `sw` at 0xa80000002004909c, `sw` at 0xa8000000200490c8.
  3 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xa800000020048fd4, `lh` at 0xa80000002004904c, `lh` at 0xa8000000200491a0.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x78, including `lw` at 0xa800000020049028, `lw` at 0xa800000020049144.
  The `ld` at 0xa80000002004903c loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xa800000020049048 loads 8 bytes from [(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8 +0x0.
  2 such `lw` accesses load 4 bytes from [[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8 +0x14, including `lw` at 0xa80000002004905c, `lw` at 0xa80000002004920c.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa800000020049098, `lw` at 0xa8000000200490c0.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100, including `lw` at 0xa800000020049188, `lw` at 0xa80000002004921c.
  The `sw` at 0xa800000020049274 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x4)) +0x574.
  The `jal` at 0xa800000020048f34 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020048fbc calls do_pcibr_rrb_count_valid [0xa800000020047734] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa800000020049020 calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=a0 at entry (arg0), a2=0xa8000000203b1850, a3=?.
  The `jal` at 0xa800000020049138 calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=a0 at entry (arg0), a2=0xa8000000203b1890, a3=?.
  The `jal` at 0xa800000020049198 calls do_pcibr_rrb_free_all [0xa800000020047ef4] with a0=ret(hwgraph_fastinfo_get), a1=[ret(hwgraph_fastinfo_get)+8]:8, a2=a1 at entry (arg1), a3=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20], a4=-0x1, a5=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256].
  The `jal` at 0xa80000002004923c calls do_pcibr_rrb_free [0xa800000020047c4c] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=0x8.
  The `beq` branch at 0xa800000020048f54 targets 0xa8000000200490d0, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa800000020048f68 targets 0xa800000020049100, is taken when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa800000020048f84 targets 0xa800000020049148, is taken when v0(?) == v1(=0xc002), and falls through when v0(?) != v1(=0xc002).
  The `beq` branch at 0xa800000020048f9c targets 0xa800000020049168, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `bne` branch at 0xa800000020048fcc targets 0xa800000020048fac, is taken when s3(?) < s2(=one of 0x2, 0x4) (signed), and falls through when s3(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0xa800000020048fd8 targets 0xa800000020049108, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `beq` branch at 0xa800000020048fe0 targets 0xa80000002004910c, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == s3(=0x1), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != s3(=0x1).
  The `beq` branch at 0xa800000020048fec targets 0xa800000020049278, is taken when s1(=a1) == t9(=0xff), and falls through when s1(=a1) != t9(=0xff).
  The `beq` branch at 0xa800000020048ff8 targets 0xa800000020049004, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == ra(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != ra(=0x2).
  The `beq` branch at 0xa800000020049044 targets 0xa80000002004905c, is taken when (v1(?) & 0x2) == 0, and falls through when (v1(?) & 0x2) != 0.
  The `beq` branch at 0xa800000020049054 targets 0xa8000000200491fc, is taken when a2(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a2(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xa800000020049064 targets 0xa800000020049188, is taken when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) == a4(=-0x1), and falls through when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) != a4(=-0x1).
  The `blez` branch at 0xa80000002004906c targets 0xa8000000200490d0, is taken when s2(=one of 0x2, 0x4) <= 0 (signed), and falls through when s2(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0xa8000000200490a0 targets 0xa8000000200490cc, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0xa8000000200490c4 targets 0xa80000002004907c, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0xa800000020049100 targets 0xa8000000200490d0 and is always taken.
  The `beq` branch at 0xa80000002004910c targets 0xa800000020049124, is taken when s1(=a1) == t0(=0xff), and falls through when s1(=a1) != t0(=0xff).
  The `beq` branch at 0xa800000020049118 targets 0xa800000020049124, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == t1(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != t1(=0x2).
  The `beq` branch at 0xa800000020049140 targets 0xa80000002004902c and is always taken.
  The `bne` branch at 0xa800000020049158 targets 0xa800000020048f8c, is taken when a3(?) != a4(=0x36), and falls through when a3(?) == a4(=0x36).
  The `beq` branch at 0xa800000020049160 targets 0xa800000020049180 and is always taken.
  The `bne` branch at 0xa800000020049178 targets 0xa800000020048fa4, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0xa800000020049180 targets 0xa800000020048fa4 and is always taken.
  The `bne` branch at 0xa80000002004918c targets 0xa80000002004906c, is taken when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0, and falls through when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0.
  The `beq` branch at 0xa8000000200491a8 targets 0xa800000020049280, is taken when a6(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when a6(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `bne` branch at 0xa8000000200491b0 targets 0xa8000000200491f4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa8000000200491d0 targets 0xa8000000200491f4, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0xa8000000200491ec targets 0xa8000000200491bc, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0xa8000000200491f4 targets 0xa8000000200490d0 and is always taken.
  The `beq` branch at 0xa8000000200491fc targets 0xa80000002004920c, is taken when a1(=0x2) == s1(=a1), and falls through when a1(=0x2) != s1(=a1).
  The `bne` branch at 0xa800000020049204 targets 0xa80000002004905c, is taken when s1(=a1) != t1(=0x3), and falls through when s1(=a1) == t1(=0x3).
  The `bne` branch at 0xa800000020049214 targets 0xa80000002004906c, is taken when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) != t3(=-0x1), and falls through when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) == t3(=-0x1).
  The `bne` branch at 0xa800000020049220 targets 0xa80000002004906c, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0, and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0.
  The `bne` branch at 0xa800000020049258 targets 0xa800000020049230, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `beq` branch at 0xa800000020049270 targets 0xa8000000200490d0 and is always taken.
  The `beq` branch at 0xa800000020049278 targets 0xa800000020049008 and is always taken.
  The `bne` branch at 0xa800000020049280 targets 0xa8000000200491f4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa8000000200492a4 targets 0xa8000000200491f4, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0xa8000000200492c0 targets 0xa800000020049290, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0xa8000000200492c8 targets 0xa8000000200491f4 and is always taken.
  The return at 0xa8000000200490f8 has v0 = one of 0x0, 0x13, 0x16.

- `pcibr_initial_rrb` in `IP30/unix` at 0xa8000000200492d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200492d0-0xa800000020049628 (856 bytes).
  It occupies 856 bytes.
  The `ld` at 0xa800000020049318 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0xa800000020049320, `lw` at 0xa80000002004935c, `lw` at 0xa8000000200495dc.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xa800000020049330, `lbu` at 0xa8000000200495a0.
  The `lbu` at 0xa800000020049338 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0xa8000000200493a4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x520.
  The `sw` at 0xa8000000200493bc stores 4 bytes to ret(hwgraph_fastinfo_get) +0x524.
  9 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa8000000200493d8, `lw` at 0xa8000000200493dc, `lw` at 0xa8000000200493e8.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004941c, `sw` at 0xa800000020049454, `sw` at 0xa800000020049488.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x34, including `lw` at 0xa8000000200494a8, `lw` at 0xa800000020049624.
  The `jal` at 0xa8000000200492f8 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049390 calls do_pcibr_rrb_count_avail [0xa800000020047904] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa8000000200493a0 calls do_pcibr_rrb_count_avail [0xa800000020047904] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0xa8000000200494fc calls pcibr_rrb_debug [0xa800000020049628] with a0=0xa8000000203b18d0, a1=ret(hwgraph_fastinfo_get), a2=?, a3=?, a5=0x1, a7=sp-88.
  The `jal` at 0xa800000020049594 calls pcibr_slot_initial_rrb_alloc [0xa800000020048f1c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa800000020049354 targets 0xa8000000200495dc, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0xa800000020049368 targets 0xa8000000200495fc, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0xa800000020049374 targets 0xa800000020049384, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002004937c targets 0xa800000020049594 and is always taken.
  The `bne` branch at 0xa800000020049414 targets 0xa800000020049448, is taken when t0(?) < v1(?) (signed), and falls through when t0(?) >= v1(?) (signed).
  The `bne` branch at 0xa800000020049428 targets 0xa8000000200493cc, is taken when a0(?) < 0x2 (signed), and falls through when a0(?) >= 0x2 (signed).
  The `bne` branch at 0xa800000020049434 targets 0xa8000000200494ec, is taken when s3(=a2) < a2(?) (signed), and falls through when s3(=a2) >= a2(?) (signed).
  The `beq` branch at 0xa800000020049440 targets 0xa80000002004961c and is always taken.
  The `bne` branch at 0xa800000020049448 targets 0xa800000020049524, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa800000020049450 targets 0xa800000020049420 and is always taken.
  The `bne` branch at 0xa800000020049474 targets 0xa80000002004945c, is taken when a1(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s1(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0xa800000020049480 targets 0xa800000020049498, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0xa8000000200494a0 targets 0xa8000000200494ec, is taken when s3(=a2) < v0(?) (signed), and falls through when s3(=a2) >= v0(?) (signed).
  The `bne` branch at 0xa8000000200494b0 targets 0xa800000020049498, is taken when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) != 0, and falls through when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) == 0.
  The `bne` branch at 0xa8000000200494d0 targets 0xa800000020049458, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `blez` branch at 0xa8000000200494d8 targets 0xa800000020049498, is taken when a6(?) <= 0 (signed), and falls through when a6(?) > 0 (signed).
  The `beq` branch at 0xa8000000200494e4 targets 0xa800000020049484 and is always taken.
  The `bne` branch at 0xa800000020049524 targets 0xa8000000200495d4, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xa80000002004952c targets 0xa800000020049420 and is always taken.
  The `bne` branch at 0xa800000020049550 targets 0xa800000020049538, is taken when a2(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a2(?) >= s1(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0xa80000002004955c targets 0xa800000020049584, is taken when v0(?) >= 0x3 (signed), and falls through when v0(?) < 0x3 (signed).
  The `beq` branch at 0xa80000002004958c targets 0xa800000020049384, is taken when s2(?) >= a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) < a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0xa8000000200495b0 targets 0xa800000020049584, is taken when s2(?) < s4(=a1) (signed), and falls through when s2(?) >= s4(=a1) (signed).
  The `bne` branch at 0xa8000000200495b8 targets 0xa800000020049584, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0xa8000000200495c0 targets 0xa800000020049534, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0xa8000000200495cc targets 0xa800000020049564 and is always taken.
  The `beq` branch at 0xa8000000200495d4 targets 0xa800000020049420 and is always taken.
  The `bne` branch at 0xa8000000200495ec targets 0xa80000002004935c, is taken when t3(?) != t8(=0x36), and falls through when t3(?) == t8(=0x36).
  The `beq` branch at 0xa8000000200495f4 targets 0xa800000020049614 and is always taken.
  The `bne` branch at 0xa80000002004960c targets 0xa800000020049370, is taken when t8(?) != t9(=0x24), and falls through when t8(?) == t9(=0x24).
  The `beq` branch at 0xa800000020049614 targets 0xa800000020049370 and is always taken.
  The `beq` branch at 0xa800000020049620 targets 0xa8000000200494ac and is always taken.
  The return at 0xa80000002004951c has v0 = 0x0.

- `pcibr_rrb_debug` in `IP30/unix` at 0xa800000020049628 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049628-0xa8000000200497fc (468 bytes).
  It occupies 468 bytes.
  The `lw` at 0xa80000002004965c loads 4 bytes from a1 (arg1 at entry) +0x524.
  The `lw` at 0xa800000020049668 loads 4 bytes from a1 (arg1 at entry) +0x520.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0xa80000002004966c, `lw` at 0xa80000002004968c, `lw` at 0xa800000020049704.
  3 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x72, including `lh` at 0xa800000020049678, `lh` at 0xa8000000200496b4, `lh` at 0xa80000002004972c.
  3 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x39, including `lbu` at 0xa800000020049698, `lbu` at 0xa800000020049710, `lbu` at 0xa8000000200497f8.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa8000000200496c0, `lw` at 0xa8000000200496c8, `lw` at 0xa8000000200496d4.
  The `jal` at 0xa800000020049670 calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=[a1+4], a2=0xa8000000203b18e8, a3=a0 at entry (arg0), a4=[a1+1312], a5=[a1+1316].
  The `jal` at 0xa800000020049690 calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=[a1+4], a2=0xa8000000203b1930, a3=?.
  The `jal` at 0xa8000000200496f0 calls sprintf [0xa8000000201c784c] with a0=sp-320, a1=0xa8000000203b1960, a2=?, a3=?.
  The `jal` at 0xa800000020049708 calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=[a1+4], a2=0xa8000000203b1998, a3=sp-320.
  The `jal` at 0xa800000020049794 calls sprintf [0xa8000000201c784c] with a0=sp-320, a1=0xa8000000203b1980, a2=?, a3=?.
  The `jal` at 0xa8000000200497ec calls pcibr_debug [0xa800000020046990] with a0=0x20, a1=[a1+4], a2=0xa8000000203b1910, a3=?.
  The `beq` branch at 0xa800000020049654 targets 0xa8000000200497a4, is taken when (at(=[0xa8000000204a7788]) & 0x20) == 0, and falls through when (at(=[0xa8000000204a7788]) & 0x20) != 0.
  The `beq` branch at 0xa80000002004967c targets 0xa8000000200497e4, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0xa800000020049684 targets 0xa8000000200497e4, is taken when a0(=[a1+114]:2) == a1(=0x1), and falls through when a0(=[a1+114]:2) != a1(=0x1).
  The `bltz` branch at 0xa8000000200496a8 targets 0xa8000000200497a4, is taken when v0(=[a1+57]:1) < 0 (signed), and falls through when v0(=[a1+57]:1) >= 0 (signed).
  The `beq` branch at 0xa8000000200496b0 targets 0xa800000020049730 and is always taken.
  The `beq` branch at 0xa800000020049724 targets 0xa8000000200497a4, is taken when s0(?) >= a3(=[a1+57]:1+1) (signed), and falls through when s0(?) < a3(=[a1+57]:1+1) (signed).
  The `beq` branch at 0xa800000020049730 targets 0xa80000002004975c, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0xa800000020049738 targets 0xa80000002004975c, is taken when a0(=[a1+114]:2) == s5(=0x1), and falls through when a0(=[a1+114]:2) != s5(=0x1).
  The `beq` branch at 0xa800000020049740 targets 0xa8000000200497c8, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `bne` branch at 0xa800000020049748 targets 0xa8000000200496b8, is taken when a0(=[a1+114]:2) != s4(=0x2), and falls through when a0(=[a1+114]:2) == s4(=0x2).
  The `beq` branch at 0xa800000020049754 targets 0xa8000000200496b8 and is always taken.
  The `beq` branch at 0xa80000002004975c targets 0xa8000000200497d0, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `beq` branch at 0xa800000020049764 targets 0xa8000000200497d8, is taken when a0(=[a1+114]:2) == s4(=0x2), and falls through when a0(=[a1+114]:2) != s4(=0x2).
  The `beq` branch at 0xa80000002004979c targets 0xa8000000200496fc and is always taken.
  The `beq` branch at 0xa8000000200497c8 targets 0xa8000000200496b8 and is always taken.
  The `beq` branch at 0xa8000000200497d0 targets 0xa80000002004976c and is always taken.
  The `beq` branch at 0xa8000000200497dc targets 0xa80000002004976c and is always taken.
  The `beq` branch at 0xa8000000200497f4 targets 0xa80000002004969c and is always taken.
  The return at 0xa8000000200497c0 has v0 = one of ?, [a1+57]:1, ret(pcibr_debug).

- `pcibr_hints_get` in `IP30/unix` at 0xa8000000200497fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200497fc-0xa800000020049904 (264 bytes).
  It occupies 264 bytes.
  The `sd` at 0xa800000020049840 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0xa800000020049848 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `jal` at 0xa800000020049818 calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=a0 at entry (arg0), a1=0xa8000000203b19a0, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049834 calls kmem_zalloc [0xa8000000201486a4] with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020049850 calls hwgraph_info_add_LBL [0xa80000002023c80c] with a0=a0 at entry (arg0), a1=0xa8000000203b19a0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa800000020049894 calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=a0 at entry (arg0), a1=0xa8000000203b19a0, a2=sp-48, a3=?.
  The `jal` at 0xa8000000200498e8 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b19b0, a2=?, a3=?.
  The `jal` at 0xa8000000200498f4 calls kmem_free [0xa800000020148710] with a0=?, a1=0x20, a2=?, a3=?.
  The `beq` branch at 0xa800000020049820 targets 0xa800000020049884, is taken when s3(=a1) == 0, and falls through when s3(=a1) != 0.
  The `beq` branch at 0xa800000020049828 targets 0xa80000002004987c, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0xa80000002004985c targets 0xa80000002004988c, is taken when v0(=ret(hwgraph_info_add_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) != 0.
  The `beq` branch at 0xa800000020049864 targets 0xa8000000200498e0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002004987c targets 0xa80000002004986c and is always taken.
  The `beq` branch at 0xa800000020049884 targets 0xa80000002004986c and is always taken.
  The `beq` branch at 0xa8000000200498a0 targets 0xa8000000200498c0, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0xa8000000200498a8 targets 0xa8000000200498e4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0xa8000000200498b0 targets 0xa8000000200498e4, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xa8000000200498b8 targets 0xa80000002004986c and is always taken.
  The `beq` branch at 0xa8000000200498cc targets 0xa8000000200498e0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0xa8000000200498d4 targets 0xa8000000200498e4, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xa8000000200498dc targets 0xa80000002004986c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xa8000000200498fc targets 0xa80000002004986c and is always taken.
  The return at 0xa800000020049874 has v0 = one of ?, 0x0.

- `pcibr_hints_fix_some_rrbs` in `IP30/unix` at 0xa800000020049904 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049904-0xa800000020049950 (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0xa800000020049924 stores 4 bytes to ret(pcibr_hints_get) +0x8.
  The `jal` at 0xa800000020049914 calls pcibr_hints_get [0xa8000000200497fc] with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049940 calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b19d8, a3=?.
  The `beq` branch at 0xa80000002004991c targets 0xa800000020049934, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0xa800000020049948 targets 0xa80000002004992c and is always taken.
  The return at 0xa80000002004992c has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_fix_rrbs` in `IP30/unix` at 0xa800000020049950 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049950-0xa80000002004996c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa800000020049958 calls pcibr_hints_fix_some_rrbs [0xa800000020049904] with a0=a0 at entry (arg0), a1=0xff, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020049964 has v0 = ret(pcibr_hints_fix_some_rrbs).

- `pcibr_hints_dualslot` in `IP30/unix` at 0xa80000002004996c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004996c-0xa8000000200499c8 (92 bytes).
  It occupies 92 bytes.
  The `sb` at 0xa8000000200499a0 stores 1 byte to (a2 + ret(pcibr_hints_get)) +0x0.
  The `jal` at 0xa800000020049980 calls pcibr_hints_get [0xa8000000200497fc] with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200499b8 calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b1a08, a3=?.
  The `beq` branch at 0xa800000020049988 targets 0xa8000000200499b0, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0xa8000000200499c0 targets 0xa8000000200499a8 and is always taken.
  The return at 0xa8000000200499a8 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_intr_bits` in `IP30/unix` at 0xa8000000200499c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200499c8-0xa800000020049a14 (76 bytes).
  It occupies 76 bytes.
  The `sd` at 0xa8000000200499ec stores 8 bytes to ret(pcibr_hints_get) +0x18.
  The `jal` at 0xa8000000200499d8 calls pcibr_hints_get [0xa8000000200497fc] with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049a04 calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b1a38, a3=?.
  The `beq` branch at 0xa8000000200499e0 targets 0xa8000000200499fc, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0xa800000020049a0c targets 0xa8000000200499f4 and is always taken.
  The return at 0xa8000000200499f4 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_set_rrb_callback` in `IP30/unix` at 0xa800000020049a14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049a14-0xa800000020049a40 (44 bytes).
  It occupies 44 bytes.
  The `sd` at 0xa800000020049a34 stores 8 bytes to ret(pcibr_hints_get) +0x10.
  The `jal` at 0xa800000020049a20 calls pcibr_hints_get [0xa8000000200497fc] with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa800000020049a28 targets 0xa800000020049a38, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The return at 0xa800000020049a38 has v0 = ret(pcibr_hints_get).

- `pcibr_hints_handsoff` in `IP30/unix` at 0xa800000020049a40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049a40-0xa800000020049a88 (72 bytes).
  It occupies 72 bytes.
  The `sw` at 0xa800000020049a5c stores 4 bytes to ret(pcibr_hints_get) +0xc.
  The `jal` at 0xa800000020049a4c calls pcibr_hints_get [0xa8000000200497fc] with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049a78 calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b1a68, a3=0x1.
  The `beq` branch at 0xa800000020049a54 targets 0xa800000020049a6c, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0xa800000020049a80 targets 0xa800000020049a64 and is always taken.
  The return at 0xa800000020049a64 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_subdevs` in `IP30/unix` at 0xa800000020049a88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049a88-0xa800000020049bdc (340 bytes).
  It occupies 340 bytes.
  The `sd` at 0xa800000020049afc stores 8 bytes to ?.
  The `sd` at 0xa800000020049b2c stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `jal` at 0xa800000020049abc calls sprintf [0xa8000000201c784c] with a0=sp-48, a1=0xa8000000203b1b60, a2=0xa8000000203b1b68, a3=a1 at entry (arg1), a4=-0x1.
  The `jal` at 0xa800000020049acc calls hwgraph_path_add [0xa80000002023cbbc] with a0=a0 at entry (arg0), a1=sp-48, a2=sp-56, a3=?.
  The `jal` at 0xa800000020049ae8 calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=?, a1=0xa8000000203b1ad0, a2=sp-64, a3=?, a5=-0x1.
  The `jal` at 0xa800000020049b14 calls kmem_zalloc [0xa8000000201486a4] with a0=0x8, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020049b34 calls hwgraph_info_add_LBL [0xa80000002023c80c] with a0=?, a1=0xa8000000203b1ad0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa800000020049b48 calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=?, a1=0xa8000000203b1ad0, a2=sp-64, a3=?.
  The `jal` at 0xa800000020049b60 calls kmem_free [0xa800000020148710] with a0=?, a1=0x8, a2=?, a3=?.
  The `jal` at 0xa800000020049b7c calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b1b38, a3=?.
  The `jal` at 0xa800000020049b98 calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b1a98, a3=?, a5=-0x1.
  The `jal` at 0xa800000020049bb4 calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b1ae0, a3=?.
  The `jal` at 0xa800000020049bcc calls pcibr_debug [0xa800000020046990] with a0=0x2, a1=a0 at entry (arg0), a2=0xa8000000203b1b10, a3=?.
  The `beq` branch at 0xa800000020049adc targets 0xa800000020049b8c, is taken when a5(=-0x1) == a0(?), and falls through when a5(=-0x1) != a0(?).
  The `beq` branch at 0xa800000020049af4 targets 0xa800000020049b14, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa800000020049b1c targets 0xa800000020049ba8, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0xa800000020049b58 targets 0xa800000020049b00, is taken when a2(?) == a3(?), and falls through when a2(?) != a3(?).
  The `beq` branch at 0xa800000020049b6c targets 0xa800000020049bc4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa800000020049b84 targets 0xa800000020049afc and is always taken.
  The `beq` branch at 0xa800000020049ba0 targets 0xa800000020049b04 and is always taken.
  The `beq` branch at 0xa800000020049bbc targets 0xa800000020049b04 and is always taken.
  The `beq` branch at 0xa800000020049bd4 targets 0xa800000020049b04 and is always taken.
  The return at 0xa800000020049b0c has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_bits` in `IP30/unix` at 0xa800000020049bdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049bdc-0xa800000020049c28 (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0xa800000020049bdc loads 1 byte from a0 (arg0 at entry) +0x21c.
  The `beq` branch at 0xa800000020049bf0 targets 0xa800000020049c18, is taken when a6(=[a0+540]:1) >= a2 (signed), and falls through when a6(=[a0+540]:1) < a2 (signed).
  The `beq` branch at 0xa800000020049bf8 targets 0xa800000020049c20, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa800000020049c20 targets 0xa800000020049c00 and is always taken.
  The return at 0xa800000020049c10 has v0 = ?.
  The return at 0xa800000020049c18 has v0 = 0x0.

- `pcibr_wrap_get` in `IP30/unix` at 0xa800000020049c28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049c28-0xa800000020049c8c (100 bytes).
  It occupies 100 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0xa800000020049c28, `lw` at 0xa800000020049c88.
  The `lw` at 0xa800000020049c2c loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0xa800000020049c54, `sw` at 0xa800000020049c64.
  The `ld` at 0xa800000020049c5c loads 8 bytes from (a0 + ([a0+8]+1 << 0x3)) +0x8.
  The `jal` at 0xa800000020049c78 calls panic [0xa8000000201c7be8] with a0=0xa8000000203b1b70, a1=a0 at entry (arg0), a2=[a0+8], a3=a3 at entry (arg3).
  The `beq` branch at 0xa800000020049c3c targets 0xa800000020049c74, is taken when at(=[a0+4]) == a2(=[a0+8]), and falls through when at(=[a0+4]) != a2(=[a0+8]).
  The `beq` branch at 0xa800000020049c84 targets 0xa800000020049c44 and is always taken.
  The return at 0xa800000020049c6c has v0 = [(a0 + ([a0+8]+1 << 0x3))+8]:8.

- `pcibr_wrap_put` in `IP30/unix` at 0xa800000020049c8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049c8c-0xa800000020049d20 (148 bytes).
  It occupies 148 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0xa800000020049cac, `lw` at 0xa800000020049d1c.
  The `lw` at 0xa800000020049cbc loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `sd` at 0xa800000020049cdc stores 8 bytes to (a1 + ([a1+4] << 0x3)) +0x10.
  The `sw` at 0xa800000020049ce0 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `jal` at 0xa800000020049ca4 calls mutex_spinlock [0xa80000002022d954] with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049ce4 calls mutex_spinunlock [0xa80000002022d9a0] with a0=a1 at entry (arg1), a1=ret(mutex_spinlock), a2=[a1+4], a3=?.
  The `jal` at 0xa800000020049d08 calls panic [0xa8000000201c7be8] with a0=0xa8000000203b1bb0, a1=a1 at entry (arg1), a2=[a1+4], a3=?.
  The `beq` branch at 0xa800000020049cc8 targets 0xa800000020049d00, is taken when at(=[a1+8]) == a5(?), and falls through when at(=[a1+8]) != a5(?).
  The `beq` branch at 0xa800000020049d18 targets 0xa800000020049cd0 and is always taken.
  The return at 0xa800000020049cf8 has v0 = ret(mutex_spinunlock).

- `pcibr_force_interrupt` in `IP30/unix` at 0xa800000020049d20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049d20-0xa800000020049da8 (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0xa800000020049d28 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0xa800000020049d2c loads 2 bytes from [a0]:8 +0x72.
  The `lw` at 0xa800000020049d34 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xa800000020049d90 loads 8 bytes from ?.
  The `jal` at 0xa800000020049d44 calls pcireg_force_intr_set [0xa800000020057e54] with a0=[a0]:8, a1=[a0+8], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049d60 calls pcireg_intr_status_get [0xa800000020055060] with a0=[a0]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049d8c calls xtalk_intr_vector_get [0xa80000002003ac54] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020049d98 calls heart_set_cpu_intr [0xa800000020013f10] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa800000020049d38 targets 0xa800000020049d60, is taken when at(=[[a0]:8+114]:2) == 0, and falls through when at(=[[a0]:8+114]:2) != 0.
  The `beq` branch at 0xa800000020049d74 targets 0xa800000020049d50, is taken when (v0(=ret(pcireg_intr_status_get)) & v1(?)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & v1(?)) != 0.
  The `beq` branch at 0xa800000020049da0 targets 0xa800000020049d50 and is always taken.
  The return at 0xa800000020049d58 has v0 = one of ret(pcireg_force_intr_set), ?, ret(heart_set_cpu_intr).

- `pcibr_intr_alloc` in `IP30/unix` at 0xa800000020049f14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020049f14-0xa80000002004a540 (1580 bytes).
  It occupies 1580 bytes.
  The `lbu` at 0xa800000020049f58 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `ld` at 0xa800000020049f5c loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `lw` at 0xa800000020049f68 loads 4 bytes from [ret(pcibr_info_get)+40]:8 +0x0.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x70, including `sw` at 0xa80000002004a014, `sw` at 0xa80000002004a028.
  The `sw` at 0xa80000002004a02c stores 4 bytes to ret(kmem_zalloc) +0x6c.
  The `sd` at 0xa80000002004a030 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0xa80000002004a034 stores 8 bytes to ret(kmem_zalloc) +0x18.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x58, including `sw` at 0xa80000002004a038, `sw` at 0xa80000002004a0f8.
  The `sd` at 0xa80000002004a03c stores 8 bytes to ret(kmem_zalloc) +0x60.
  3 such `sh` accesses store 2 bytes to ret(kmem_zalloc) +0x50, including `sh` at 0xa80000002004a044, `sh` at 0xa80000002004a0d8, `sh` at 0xa80000002004a228.
  The `sw` at 0xa80000002004a04c stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0xa80000002004a058 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0xa80000002004a068 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `ld` at 0xa80000002004a06c loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x500.
  The `lbu` at 0xa80000002004a070 loads 1 byte from [ret(pcibr_info_get)+40]:8 +0x39.
  2 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x58, including `lw` at 0xa80000002004a0e4, `lw` at 0xa80000002004a514.
  The `sd` at 0xa80000002004a0fc stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0xa80000002004a104 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0xa80000002004a110 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0xa80000002004a128 stores 1 byte to ret(kmem_zalloc) +0x18.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004a198, `ld` at 0xa80000002004a1d8, `ld` at 0xa80000002004a260.
  The `sw` at 0xa80000002004a29c stores 4 bytes to ?.
  The `ld` at 0xa80000002004a330 loads 8 bytes from a1 (arg1 at entry) +0x10.
  The `lh` at 0xa80000002004a350 loads 2 bytes from ret(kmem_zalloc) +0x50.
  2 such `ld` accesses load 8 bytes from [ret(pcibr_info_get)+40]:8 +0x10, including `ld` at 0xa80000002004a4b4, `ld` at 0xa80000002004a518.
  The `jal` at 0xa800000020049f34 calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020049fc4 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1c10, a3=one of 0xa8000000203b1c00, 0xa8000000203b1f70, a4=one of 0xa8000000203b1f70, 0xa8000000203b1f78, a5=one of 0xa8000000203b1f70, 0xa8000000203b1f80, a6=one of 0xa8000000203b1f70, 0xa8000000203b1f88, a7=one of 0xa8000000203b1f70, 0xa8000000203b1f90.
  The `jal` at 0xa800000020049fd0 calls kmem_zalloc [0xa8000000201486a4] with a0=0xa0, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020049ff0 calls device_desc_flags_get [0xa80000002013eaf8] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a5=[0xa8000000204a70dc].
  The `jal` at 0xa80000002004a064 calls spinlock_init [0xa80000002022d728] with a0=ret(kmem_zalloc)+104, a1=0xa8000000203b1c30, a2=?, a3=?.
  The `jalr` at 0xa80000002004a07c calls (unknown callee) with a0=?, a1=a2 at entry (arg2), a2=[[ret(pcibr_info_get)+40]:8+57]:1+1, a3=[[ret(pcibr_info_get)+40]:8+1280]:8.
  The `jal` at 0xa80000002004a094 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1c40, a3=ret(?).
  The `jal` at 0xa80000002004a0f4 calls kmem_zalloc [0xa8000000201486a4] with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa80000002004a124 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1e10, a3=?.
  The `jal` at 0xa80000002004a134 calls compare_and_swap_int64 [0xa800000020016e8c] with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa80000002004a150 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1e30, a3=ret(?).
  The `jal` at 0xa80000002004a1b0 calls xtalk_intr_cpuid_get [0xa80000002003aad4] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a1e8 calls compare_and_swap_int64 [0xa800000020016e8c] with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa80000002004a1fc calls kmem_free [0xa800000020148710] with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0xa80000002004a214 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1e60, a3=ret(?).
  The `jal` at 0xa80000002004a234 calls xtalk_intr_alloc_nothd [0xa80000002003aa48] with a0=?, a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xa80000002004a250 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1c68, a3=ret(xtalk_intr_alloc_nothd).
  The `jal` at 0xa80000002004a278 calls compare_and_swap_int64 [0xa800000020016e8c] with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa80000002004a2a0 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1e90, a3=ret(?).
  The `jal` at 0xa80000002004a2b4 calls compare_and_swap_int64 [0xa800000020016e8c] with a0=?, a1=0x0, a2=ret(xtalk_intr_alloc_nothd), a3=?.
  The `jal` at 0xa80000002004a2cc calls pcireg_intr_device_bit_clr [0xa800000020056430] with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a2e0 calls pcireg_intr_device_bit_set [0xa8000000200562bc] with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a2f4 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1cd0, a3=?.
  The `jal` at 0xa80000002004a318 calls pcibr_thread_setup [0xa800000020049e9c] with a0=ret(kmem_zalloc), a1=ret(?), a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0xa80000002004a338 calls xtalk_intr_cpuid_get [0xa80000002003aad4] with a0=?, a1=?, a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0xa80000002004a368 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1f10, a3=ret(kmem_zalloc), a4=a1 at entry (arg1), a6=ret(xtalk_intr_cpuid_get).
  The `jal` at 0xa80000002004a3ac calls compare_and_swap_int64 [0xa800000020016e8c] with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa80000002004a3c0 calls kmem_free [0xa800000020148710] with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0xa80000002004a3d8 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1eb8, a3=ret(?).
  The `jal` at 0xa80000002004a3ec calls compare_and_swap_int64 [0xa800000020016e8c] with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa80000002004a410 calls xtalk_intr_free [0xa80000002003aa64] with a0=ret(xtalk_intr_alloc_nothd), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a45c calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=a0 at entry (arg0), a2=0xa8000000203b1ee8, a3=ret(?).
  The `jal` at 0xa80000002004a46c calls device_desc_intr_target_get [0xa80000002013ead8] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a480 calls cpuvertex_to_cpuid [0xa80000002023e298] with a0=ret(device_desc_intr_target_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a4a0 calls device_desc_intr_swlevel_get [0xa80000002013eae8] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a4b8 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b1cf8, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?, a5=-0x1.
  The `jal` at 0xa80000002004a4d0 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b1d30, a2=?, a3=?.
  The `jal` at 0xa80000002004a4e8 calls vertex_to_name [0xa80000002023e0dc] with a0=a3 at entry (arg3), a1=sp-440, a2=0x100, a3=?, a5=-0x1.
  The `jal` at 0xa80000002004a508 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b1d58, a2=?, a3=?, a5=sp-440, a6=a3 at entry (arg3).
  The `jal` at 0xa80000002004a51c calls cmn_err [0xa8000000201c6b00] with a0=0x1, a1=0xa8000000203b1c90, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?.
  The `beq` branch at 0xa800000020049f6c targets 0xa80000002004a424, is taken when (s0(=a2) & 0xf) == 0, and falls through when (s0(=a2) & 0xf) != 0.
  The `beq` branch at 0xa800000020049f80 targets 0xa80000002004a430, is taken when (s0(=a2) & 0x1) == 0, and falls through when (s0(=a2) & 0x1) != 0.
  The `beq` branch at 0xa800000020049f90 targets 0xa80000002004a438, is taken when (s0(=a2) & 0x2) == 0, and falls through when (s0(=a2) & 0x2) != 0.
  The `beq` branch at 0xa800000020049fa0 targets 0xa80000002004a440, is taken when (s0(=a2) & 0x4) == 0, and falls through when (s0(=a2) & 0x4) != 0.
  The `beq` branch at 0xa800000020049fb0 targets 0xa80000002004a448, is taken when (s0(=a2) & 0x8) == 0, and falls through when (s0(=a2) & 0x8) != 0.
  The `beq` branch at 0xa800000020049fdc targets 0xa80000002004a408, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0xa800000020049fe8 targets 0xa80000002004a018, is taken when t0(=a1) == 0, and falls through when t0(=a1) != 0.
  The `beq` branch at 0xa80000002004a008 targets 0xa80000002004a46c, is taken when (v0(=ret(device_desc_flags_get)) & 0x4) == 0, and falls through when (v0(=ret(device_desc_flags_get)) & 0x4) != 0.
  The `beq` branch at 0xa80000002004a010 targets 0xa80000002004a02c and is always taken.
  The `beq` branch at 0xa80000002004a0ac targets 0xa80000002004a52c and is always taken.
  The `bne` branch at 0xa80000002004a0bc targets 0xa80000002004a4b0, is taken when a6(?) != a1(?), and falls through when a6(?) == a1(?).
  The `beq` branch at 0xa80000002004a0c8 targets 0xa80000002004a224, is taken when a7(?) == a5(=-0x1), and falls through when a7(?) != a5(=-0x1).
  The `bne` branch at 0xa80000002004a0dc targets 0xa80000002004a4e0, is taken when t1(?) != t0(?), and falls through when t1(?) == t0(?).
  The `beq` branch at 0xa80000002004a13c targets 0xa80000002004a1d8, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `beq` branch at 0xa80000002004a174 targets 0xa80000002004a304, is taken when s0(?) >= 0x8 (unsigned), and falls through when s0(?) < 0x8 (unsigned).
  The `beq` branch at 0xa80000002004a188 targets 0xa80000002004a158, is taken when (s5(?) & s3(=ret(?))) == 0, and falls through when (s5(?) & s3(=ret(?))) != 0.
  The `beq` branch at 0xa80000002004a19c targets 0xa80000002004a22c, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xa80000002004a1a8 targets 0xa80000002004a0e4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0xa80000002004a1c0 targets 0xa80000002004a0b4, is taken when a1(?) != a5(=-0x1), and falls through when a1(?) == a5(=-0x1).
  The `beq` branch at 0xa80000002004a1d0 targets 0xa80000002004a0c4 and is always taken.
  The `beq` branch at 0xa80000002004a1f0 targets 0xa80000002004a274, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `beq` branch at 0xa80000002004a21c targets 0xa80000002004a15c and is always taken.
  The `beq` branch at 0xa80000002004a224 targets 0xa80000002004a0e4 and is always taken.
  The `bne` branch at 0xa80000002004a258 targets 0xa80000002004a2b0, is taken when s7(=ret(xtalk_intr_alloc_nothd)) != 0, and falls through when s7(=ret(xtalk_intr_alloc_nothd)) == 0.
  The `bne` branch at 0xa80000002004a264 targets 0xa80000002004a1a8, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0xa80000002004a26c targets 0xa80000002004a518 and is always taken.
  The `beq` branch at 0xa80000002004a280 targets 0xa80000002004a3a4, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `beq` branch at 0xa80000002004a2a8 targets 0xa80000002004a15c and is always taken.
  The `beq` branch at 0xa80000002004a2bc targets 0xa80000002004a410, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `beq` branch at 0xa80000002004a2fc targets 0xa80000002004a1a8 and is always taken.
  The `beq` branch at 0xa80000002004a308 targets 0xa80000002004a324, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xa80000002004a324 targets 0xa80000002004a334, is taken when a4(=a1) == 0, and falls through when a4(=a1) != 0.
  The `beq` branch at 0xa80000002004a32c targets 0xa80000002004a338 and is always taken.
  The `beq` branch at 0xa80000002004a348 targets 0xa80000002004a354, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xa80000002004a3b4 targets 0xa80000002004a3e8, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `beq` branch at 0xa80000002004a3e0 targets 0xa80000002004a15c and is always taken.
  The `bne` branch at 0xa80000002004a3f4 targets 0xa80000002004a450, is taken when v0(=ret(compare_and_swap_int64)) != 0, and falls through when v0(=ret(compare_and_swap_int64)) == 0.
  The `beq` branch at 0xa80000002004a400 targets 0xa80000002004a3a4 and is always taken.
  The `beq` branch at 0xa80000002004a408 targets 0xa80000002004a370 and is always taken.
  The `beq` branch at 0xa80000002004a41c targets 0xa80000002004a1a4 and is always taken.
  The `beq` branch at 0xa80000002004a428 targets 0xa800000020049f7c and is always taken.
  The `beq` branch at 0xa80000002004a430 targets 0xa800000020049f8c and is always taken.
  The `beq` branch at 0xa80000002004a438 targets 0xa800000020049f9c and is always taken.
  The `beq` branch at 0xa80000002004a440 targets 0xa800000020049fac and is always taken.
  The `beq` branch at 0xa80000002004a448 targets 0xa800000020049fbc and is always taken.
  The `beq` branch at 0xa80000002004a464 targets 0xa80000002004a15c and is always taken.
  The `beq` branch at 0xa80000002004a478 targets 0xa80000002004a498, is taken when ra(=-0x1) == v0(=ret(device_desc_intr_target_get)), and falls through when ra(=-0x1) != v0(=ret(device_desc_intr_target_get)).
  The `beq` branch at 0xa80000002004a490 targets 0xa80000002004a4a0 and is always taken.
  The `beq` branch at 0xa80000002004a4a8 targets 0xa80000002004a028 and is always taken.
  The `beq` branch at 0xa80000002004a4d8 targets 0xa80000002004a0c4 and is always taken.
  The `beq` branch at 0xa80000002004a510 targets 0xa80000002004a0e8 and is always taken.
  The `beq` branch at 0xa80000002004a524 targets 0xa80000002004a370 and is always taken.
  The `beq` branch at 0xa80000002004a538 targets 0xa80000002004a180 and is always taken.
  The return at 0xa80000002004a39c has v0 = one of ret(kmem_zalloc), 0x0.

- `pcibr_intr_setmustrun` in `IP30/unix` at 0xa80000002004a540 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004a540-0xa80000002004a584 (68 bytes).
  It occupies 68 bytes.
  The `sh` at 0xa80000002004a564 stores 2 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0xa80000002004a550 calls spl1 [0xa80000002001ba7c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004a560 calls setmustrun [0xa80000002015b284] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a570 calls splx [0xa80000002001bb64] with a0=(ret(spl1) << 0x0), a1=?, a2=?, a3=?.
  The return at 0xa80000002004a57c has v0 = ret(splx).

- `pcibr_intr_free` in `IP30/unix` at 0xa80000002004a584 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004a584-0xa80000002004a77c (504 bytes).
  It occupies 504 bytes.
  The `lw` at 0xa80000002004a58c loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0xa80000002004a594 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `sd` at 0xa80000002004a5dc stores 8 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004a620, `ld` at 0xa80000002004a654, `ld` at 0xa80000002004a66c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xa80000002004a648, `lw` at 0xa80000002004a6c0.
  The `lw` at 0xa80000002004a660 loads 4 bytes from ?.
  The `lw` at 0xa80000002004a680 loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0xa80000002004a690, `lw` at 0xa80000002004a730.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0xa80000002004a6a4, `ld` at 0xa80000002004a6cc.
  The `jal` at 0xa80000002004a5d0 calls xtalk_intr_free [0xa80000002003aa64] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a5e4 calls pcireg_intr_device_bit_clr [0xa800000020056430] with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a634 calls compare_and_swap_int64 [0xa800000020016e8c] with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0xa80000002004a64c calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=[a0+4], a2=0xa8000000203b1f98, a3=?.
  The `jal` at 0xa80000002004a6b0 calls xthread_set_func [0xa800000020191584] with a0=[a0+64]:8, a1=0xa800000020191500, a2=0x0, a3=[a0+64]:8.
  The `jal` at 0xa80000002004a6b8 calls vsema [0xa8000000201504d8] with a0=a0+48, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a6d0 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=[a0+4], a2=0xa8000000203b1fc8, a3=[a0+64]:8.
  The `jal` at 0xa80000002004a6dc calls kmem_free [0xa800000020148710] with a0=a0 at entry (arg0), a1=0xa0, a2=?, a3=?.
  The `jal` at 0xa80000002004a728 calls nano_delay [0xa8000000201788b8] with a0=sp-96, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a75c calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b2008, a2=[a0+64]:8, a3=[a0+64]:8.
  The `beq` branch at 0xa80000002004a5c8 targets 0xa80000002004a76c and is always taken.
  The `beq` branch at 0xa80000002004a5fc targets 0xa80000002004a680, is taken when s2(?) >= 0x8 (unsigned), and falls through when s2(?) < 0x8 (unsigned).
  The `beq` branch at 0xa80000002004a60c targets 0xa80000002004a5ec, is taken when (s6(=[a0+88]) & a3(?)) == 0, and falls through when (s6(=[a0+88]) & a3(?)) != 0.
  The `beq` branch at 0xa80000002004a624 targets 0xa80000002004a660, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa80000002004a63c targets 0xa80000002004a654, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `bne` branch at 0xa80000002004a658 targets 0xa80000002004a630, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0xa80000002004a664 targets 0xa80000002004a5ec, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0xa80000002004a670 targets 0xa80000002004a5d0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0xa80000002004a678 targets 0xa80000002004a5f0 and is always taken.
  The `bne` branch at 0xa80000002004a688 targets 0xa80000002004a6dc, is taken when (t9(=[a0]) & 0x2) != 0, and falls through when (t9(=[a0]) & 0x2) == 0.
  The `beq` branch at 0xa80000002004a698 targets 0xa80000002004a714, is taken when (a1(=[a0+40]) & 0x400) == 0, and falls through when (a1(=[a0+40]) & 0x400) != 0.
  The `beq` branch at 0xa80000002004a6a0 targets 0xa80000002004a754, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0xa80000002004a738 targets 0xa80000002004a6a0, is taken when (a1(=[a0+40]) & 0x400) != 0, and falls through when (a1(=[a0+40]) & 0x400) == 0.
  The `bne` branch at 0xa80000002004a744 targets 0xa80000002004a720, is taken when s0(?) < 0x3e8 (signed), and falls through when s0(?) >= 0x3e8 (signed).
  The `beq` branch at 0xa80000002004a74c targets 0xa80000002004a6a0 and is always taken.
  The `beq` branch at 0xa80000002004a764 targets 0xa80000002004a6dc and is always taken.
  The `beq` branch at 0xa80000002004a774 targets 0xa80000002004a608 and is always taken.
  The return at 0xa80000002004a70c has v0 = ret(kmem_free).

- `pcibr_setpciint` in `IP30/unix` at 0xa80000002004a77c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004a77c-0xa80000002004a824 (168 bytes).
  It occupies 168 bytes.
  2 such `lw` accesses load 4 bytes from ret(xtalk_intr_sfarg_get) +0x0, including `lw` at 0xa80000002004a7c0, `lw` at 0xa80000002004a7d0.
  The `jal` at 0xa80000002004a788 calls xtalk_intr_addr_get [0xa80000002003ac5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004a798 calls xtalk_intr_vector_get [0xa80000002003ac54] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a7a8 calls xtalk_intr_dev_get [0xa80000002003ac44] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a7b8 calls xtalk_intr_sfarg_get [0xa80000002003ac64] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a7c8 calls xtalk_intr_sfarg_get [0xa80000002003ac64] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a7e0 calls pcibr_bridge_ptr_get [0xa800000020046c00] with a0=ret(xtalk_intr_dev_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a7f8 calls pcireg_intr_addr_vect_set [0xa80000002005709c] with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a80c calls pcireg_intr_addr_addr_set [0xa800000020057508] with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=ret(xtalk_intr_addr_get), a3=?.
  The return at 0xa80000002004a81c has v0 = ret(pcireg_intr_addr_addr_set).

- `pcibr_intr_connect` in `IP30/unix` at 0xa80000002004a824 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004a824-0xa80000002004a9c8 (420 bytes).
  It occupies 420 bytes.
  The `lw` at 0xa80000002004a82c loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0xa80000002004a834 loads 8 bytes from a0 (arg0 at entry) +0x60.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xa80000002004a864, `lw` at 0xa80000002004a9a4.
  The `sd` at 0xa80000002004a888 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `lw` at 0xa80000002004a88c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0xa80000002004a894 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sw` at 0xa80000002004a8a0 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0xa80000002004a8c8 loads 4 bytes from ?.
  The `ld` at 0xa80000002004a8d0 loads 8 bytes from ?.
  The `lw` at 0xa80000002004a94c loads 4 bytes from [a0+96]:8 +0x48.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004a970, `sw` at 0xa80000002004a984.
  The `jal` at 0xa80000002004a880 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=[a0+4], a2=0xa8000000203b2050, a3=a1 at entry (arg1), a4=a2 at entry (arg2).
  The `jal` at 0xa80000002004a8e4 calls mutex_spinlock [0xa80000002022d954] with a0=[a0+96]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a900 calls pcireg_intr_enable_bit_set [0xa800000020055604] with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a908 calls pcireg_tflush_get [0xa800000020052634] with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a914 calls mutex_io_spinunlock [0xa80000002022d860] with a0=[a0+96]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa80000002004a944 calls pcireg_intr_addr_addr [0xa800000020056c8c] with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a974 calls xtalk_intr_connect [0xa80000002003aa80] with a0=?, a1=0xa80000002004ad50, a2=?, a3=0xa80000002004a77c, a5=0x0.
  The `jal` at 0xa80000002004a988 calls pcireg_intr_addr_get [0xa800000020056870] with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004a9a8 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=[a0+4], a2=0xa8000000203b2088, a3=ret(pcireg_intr_addr_addr), a4=ret(pcireg_intr_addr_get).
  The `bne` branch at 0xa80000002004a854 targets 0xa80000002004a864, is taken when a0 != 0, and falls through when a0 == 0.
  The `beq` branch at 0xa80000002004a85c targets 0xa80000002004a928 and is always taken.
  The `beq` branch at 0xa80000002004a8b4 targets 0xa80000002004a8d4, is taken when (s2(=[a0+88]) & a5(?)) == 0, and falls through when (s2(=[a0+88]) & a5(?)) != 0.
  The `beq` branch at 0xa80000002004a8cc targets 0xa80000002004a940, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0xa80000002004a8dc targets 0xa80000002004a8a4, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `bne` branch at 0xa80000002004a9b8 targets 0xa80000002004a8a8, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `beq` branch at 0xa80000002004a9c0 targets 0xa80000002004a8e4 and is always taken.
  The return at 0xa80000002004a938 has v0 = one of -0x1, 0x0.

- `pcibr_intr_disconnect` in `IP30/unix` at 0xa80000002004a9c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004a9c8-0xa80000002004aba4 (476 bytes).
  It occupies 476 bytes.
  The `sd` at 0xa80000002004a9c8 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0xa80000002004a9cc stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `ld` at 0xa80000002004a9d8 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `lw` at 0xa80000002004a9e0 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `lw` at 0xa80000002004a9ec loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0xa80000002004aa04 stores 4 bytes to a0 (arg0 at entry) +0x0.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004aa34, `lw` at 0xa80000002004aad8, `lw` at 0xa80000002004ab3c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xa80000002004aaa4, `lw` at 0xa80000002004ab30, `lw` at 0xa80000002004ab80.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004ab1c, `ld` at 0xa80000002004ab54.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004ab2c, `sw` at 0xa80000002004ab68.
  The `lw` at 0xa80000002004ab48 loads 4 bytes from [a0+96]:8 +0x48.
  The `jal` at 0xa80000002004aa68 calls mutex_spinlock [0xa80000002022d954] with a0=[a0+96]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004aa7c calls pcireg_intr_enable_bit_clr [0xa800000020055484] with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004aa84 calls pcireg_tflush_get [0xa800000020052634] with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004aa90 calls mutex_io_spinunlock [0xa80000002022d860] with a0=[a0+96]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa80000002004aaa8 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=[a0+4], a2=0xa8000000203b20d0, a3=?.
  The `jal` at 0xa80000002004ab18 calls xtalk_intr_disconnect [0xa80000002003aa9c] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004ab34 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=[a0+4], a2=0xa8000000203b2100, a3=?.
  The `jal` at 0xa80000002004ab6c calls xtalk_intr_connect [0xa80000002003aa80] with a0=?, a1=0xa80000002004ad50, a2=?, a3=0xa80000002004a77c, a5=0x0.
  The `jal` at 0xa80000002004ab84 calls pcibr_debug [0xa800000020046990] with a0=0x1000, a1=[a0+4], a2=0xa8000000203b2138, a3=?.
  The `beq` branch at 0xa80000002004aa20 targets 0xa80000002004aa44, is taken when (a6(?) & s0(?)) == 0, and falls through when (a6(?) & s0(?)) != 0.
  The `beq` branch at 0xa80000002004aa38 targets 0xa80000002004aa48, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0xa80000002004aa4c targets 0xa80000002004aa10, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0xa80000002004aa5c targets 0xa80000002004aaf4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa80000002004aac4 targets 0xa80000002004aae4, is taken when (s0(?) & a2(?)) == 0, and falls through when (s0(?) & a2(?)) != 0.
  The `beq` branch at 0xa80000002004aadc targets 0xa80000002004ab18, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xa80000002004aaec targets 0xa80000002004aab8, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0xa80000002004ab40 targets 0xa80000002004ab8c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xa80000002004ab94 targets 0xa80000002004aab8, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0xa80000002004ab9c targets 0xa80000002004aaf8 and is always taken.
  The return at 0xa80000002004ab10 has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_cpu_get` in `IP30/unix` at 0xa80000002004aba4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004aba4-0xa80000002004ac1c (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0xa80000002004aba8 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0xa80000002004abfc loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0xa80000002004ac10 loads 8 bytes from ?.
  The `jal` at 0xa80000002004ac0c calls xtalk_intr_cpu_get [0xa80000002003aab8] with a0=?, a1=?, a2=?, a3=[a0+88], a4=0x1, a5=a0 at entry (arg0).
  The `bne` branch at 0xa80000002004abc4 targets 0xa80000002004abf4, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0xa80000002004abd8 targets 0xa80000002004abc4, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0xa80000002004ac14 targets 0xa80000002004abe4 and is always taken.
  The return at 0xa80000002004abec has v0 = one of 0x0, ret(xtalk_intr_cpu_get).

- `pcibr_setwidint` in `IP30/unix` at 0xa80000002004ac1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004ac1c-0xa80000002004aca0 (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0xa80000002004ac2c calls xtalk_intr_target_get [0xa80000002003ac4c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004ac3c calls xtalk_intr_addr_get [0xa80000002003ac5c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004ac48 calls xtalk_intr_vector_get [0xa80000002003ac54] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004ac54 calls xtalk_intr_sfarg_get [0xa80000002003ac64] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004ac64 calls pcireg_intr_dst_target_id_set [0xa800000020051cfc] with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004ac74 calls pcireg_intr_dst_addr_set [0xa800000020052018] with a0=ret(xtalk_intr_sfarg_get), a1=ret(xtalk_intr_addr_get), a2=?, a3=?.
  The `jal` at 0xa80000002004ac88 calls pcireg_intr_host_err_set [0xa800000020056714] with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The return at 0xa80000002004ac98 has v0 = ret(pcireg_intr_host_err_set).

- `pcibr_xintr_preset` in `IP30/unix` at 0xa80000002004aca0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004aca0-0xa80000002004ad50 (176 bytes).
  It occupies 176 bytes.
  The `jal` at 0xa80000002004acd0 calls pcireg_intr_dst_target_id_set [0xa800000020051cfc] with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004acdc calls pcireg_intr_dst_addr_set [0xa800000020052018] with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0xa80000002004ace8 calls pcireg_intr_host_err_set [0xa800000020056714] with a0=a0 at entry (arg0), a1=a4 at entry (arg4), a2=?, a3=?.
  The `jal` at 0xa80000002004acf4 calls pcireg_intr_enable_bit_set [0xa800000020055604] with a0=a0 at entry (arg0), a1=-0x100, a2=?, a3=?.
  The `jal` at 0xa80000002004ad04 calls pcireg_intr_addr_addr_set [0xa800000020057508] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004ad14 calls pcireg_intr_addr_vect_set [0xa80000002005709c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0xa80000002004ad24 calls pcireg_intr_enable_bit_set [0xa800000020055604] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004ad38 calls pcireg_tflush_get [0xa800000020052634] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xa80000002004acc8 targets 0xa80000002004ad04, is taken when a1 != at(=-0x1), and falls through when a1 == at(=-0x1).
  The `beq` branch at 0xa80000002004acfc targets 0xa80000002004ad2c and is always taken.
  The return at 0xa80000002004ad48 has v0 = ret(pcireg_tflush_get).

- `pcibr_intr_func` in `IP30/unix` at 0xa80000002004ad50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004ad50-0xa80000002004af9c (588 bytes).
  It occupies 588 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0xa80000002004ad50, `lw` at 0xa80000002004aecc.
  The `ld` at 0xa80000002004ad68 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0xa80000002004ad70 loads 2 bytes from [a0]:8 +0x72.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0xa80000002004ad90, `lw` at 0xa80000002004aeb8, `lw` at 0xa80000002004af88.
  The `ld` at 0xa80000002004adcc loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xa80000002004addc loads 8 bytes from [a0+16]:8 +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1c, including `lw` at 0xa80000002004adf8, `lw` at 0xa80000002004ae64.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa80000002004ae04, `lbu` at 0xa80000002004ae70.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004ae0c, `ld` at 0xa80000002004ae10, `ld` at 0xa80000002004ae18.
  The `lw` at 0xa80000002004ae38 loads 4 bytes from ?.
  The `ll` at 0xa80000002004ae88 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sc` at 0xa80000002004ae94 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `lw` at 0xa80000002004af30 loads 4 bytes from [a0]:8 +0x78.
  The `jal` at 0xa80000002004ae08 calls pcireg_wrb_flush_get [0xa800000020058920] with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xa80000002004ae14 calls (unknown callee) with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004ae74 calls pcireg_wrb_flush_get [0xa800000020058920] with a0=?, a1=?, a2=a0+24, a3=?.
  The `jal` at 0xa80000002004aea0 calls pcibr_wrap_put [0xa800000020049c8c] with a0=a0 at entry (arg0), a1=?, a2=a0+24, a3=0x1, a4=[a0+24]+1.
  The `jal` at 0xa80000002004aea8 calls vsema [0xa8000000201504d8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004aed4 calls mutex_spinlock [0xa80000002022d954] with a0=[a0]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004aee4 calls pcireg_intr_enable_bit_clr [0xa800000020055484] with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004aeec calls pcireg_tflush_get [0xa800000020052634] with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004aef8 calls mutex_io_spinunlock [0xa80000002022d860] with a0=[a0]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa80000002004af50 calls mutex_spinlock [0xa80000002022d954] with a0=[a0]:8+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004af64 calls pcireg_intr_enable_bit_clr [0xa800000020055484] with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004af70 calls pcireg_intr_enable_bit_set [0xa800000020055604] with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004af7c calls mutex_io_spinunlock [0xa80000002022d860] with a0=[a0]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa80000002004af8c calls pcibr_force_interrupt [0xa800000020049d20] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+24].
  The `beq` branch at 0xa80000002004ad88 targets 0xa80000002004af30, is taken when at(=[[a0]:8+114]:2) == v1(=0x2), and falls through when at(=[[a0]:8+114]:2) != v1(=0x2).
  The `bne` branch at 0xa80000002004ada8 targets 0xa80000002004af00, is taken when a0(=[a0+24]) != 0, and falls through when a0(=[a0+24]) == 0.
  The `beq` branch at 0xa80000002004adb4 targets 0xa80000002004adcc and is always taken.
  The `beq` branch at 0xa80000002004adbc targets 0xa80000002004aeb8, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xa80000002004adc4 targets 0xa80000002004aec4, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xa80000002004add0 targets 0xa80000002004adbc, is taken when s0(=[a0+16]:8) == 0, and falls through when s0(=[a0+16]:8) != 0.
  The `beq` branch at 0xa80000002004add8 targets 0xa80000002004ae30 and is always taken.
  The `bne` branch at 0xa80000002004ade0 targets 0xa80000002004ae5c, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0xa80000002004ade8 targets 0xa80000002004ae20, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0xa80000002004adf0 targets 0xa80000002004ae20, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa80000002004adfc targets 0xa80000002004ae10, is taken when a1(=[a0+28]) == 0, and falls through when a1(=[a0+28]) != 0.
  The `beq` branch at 0xa80000002004ae24 targets 0xa80000002004adbc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa80000002004ae30 targets 0xa80000002004ae20, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xa80000002004ae44 targets 0xa80000002004ae20, is taken when (v0(?) & 0x1) == 0, and falls through when (v0(?) & 0x1) != 0.
  The `bne` branch at 0xa80000002004ae4c targets 0xa80000002004ade0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0xa80000002004ae54 targets 0xa80000002004ade8, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xa80000002004ae5c targets 0xa80000002004ade8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002004ae68 targets 0xa80000002004ae80, is taken when v1(=[a0+28]) == 0, and falls through when v1(=[a0+28]) != 0.
  The `beql` branch at 0xa80000002004ae98 targets 0xa80000002004ae88, is taken when a4(=[a0+24]+1) == 0, and falls through when a4(=[a0+24]+1) != 0; its branch-likely delay slot `nop` at 0xa80000002004ae9c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa80000002004aeb0 targets 0xa80000002004ae20 and is always taken.
  The `beq` branch at 0xa80000002004aebc targets 0xa80000002004af8c, is taken when a5(=[a0+24]) == 0, and falls through when a5(=[a0+24]) != 0.
  The `beq` branch at 0xa80000002004aec4 targets 0xa80000002004af00, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xa80000002004af40 targets 0xa80000002004ad90, is taken when (t8(?) & 0x2) == 0, and falls through when (t8(?) & 0x2) != 0.
  The `beq` branch at 0xa80000002004af84 targets 0xa80000002004ad94 and is always taken.
  The `beq` branch at 0xa80000002004af94 targets 0xa80000002004aec4 and is always taken.
  The return at 0xa80000002004af28 has v0 = one of a0+24, ?, ret(mutex_io_spinunlock).

- `pcibr_errintr_group` in `IP30/unix` at 0xa80000002004c028 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004c028-0xa80000002004c0ac (132 bytes).
  It occupies 132 bytes.
  The `beq` branch at 0xa80000002004c044 targets 0xa80000002004c054, is taken when (a0 & a1(=0x40010000)) == 0, and falls through when (a0 & a1(=0x40010000)) != 0.
  The `beq` branch at 0xa80000002004c06c targets 0xa80000002004c078, is taken when (a3(=a0) & v1(=0x3e0000)) == 0, and falls through when (a3(=a0) & v1(=0x3e0000)) != 0.
  The `beq` branch at 0xa80000002004c078 targets 0xa80000002004c084, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa80000002004c08c targets 0xa80000002004c098, is taken when (a3(=a0) & a0(=0x14000200)) == 0, and falls through when (a3(=a0) & a0(=0x14000200)) != 0.
  The `beq` branch at 0xa80000002004c098 targets 0xa80000002004c0a4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0xa80000002004c0a4 has v0 = ?.

- `pcibr_error_intr_handler` in `IP30/unix` at 0xa80000002004c214 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004c214-0xa80000002004c778 (1380 bytes).
  It occupies 1380 bytes.
  The `lw` at 0xa80000002004c22c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0xa80000002004c258 loads 1 byte from a0 (arg0 at entry) +0x28.
  8 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xa80000002004c2dc, `lh` at 0xa80000002004c370, `lh` at 0xa80000002004c488.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004c314, `lw` at 0xa80000002004c318, `lw` at 0xa80000002004c31c.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004c324, `sw` at 0xa80000002004c3c4, `sw` at 0xa80000002004c3cc.
  The `lw` at 0xa80000002004c328 loads 4 bytes from a0 (arg0 at entry) +0x48.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0xa80000002004c3d8, `lw` at 0xa80000002004c4e4, `lw` at 0xa80000002004c5ac.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004c640, `ld` at 0xa80000002004c6bc, `ld` at 0xa80000002004c6f4.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xa80000002004c64c, `ld` at 0xa80000002004c6c8, `ld` at 0xa80000002004c6fc.
  The `jal` at 0xa80000002004c224 calls pcireg_intr_status_get [0xa800000020055060] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004c248 calls pcibr_debug [0xa800000020046990] with a0=0x100, a1=[a0], a2=0xa8000000203b2640, a3=ret(pcireg_intr_status_get).
  The `jal` at 0xa80000002004c29c calls pcibr_pioerr_check [0xa80000002004c0ac] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c410 calls mutex_spinlock [0xa80000002022d954] with a0=a0+128, a1=0x1, a2=0xa80000002043ead0, a3=0x2.
  The `jal` at 0xa80000002004c420 calls pcireg_intr_enable_bit_clr [0xa800000020055484] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c42c calls mutex_io_spinunlock [0xa80000002022d860] with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa80000002004c448 calls pcireg_bus_err_get [0xa80000002005097c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x2.
  The `jal` at 0xa80000002004c4bc calls pcireg_intr_reset_set [0xa800000020055778] with a0=a0 at entry (arg0), a1=(ret(pcireg_intr_status_get) | 0x40), a2=?, a3=?, a7=0x1.
  The `jal` at 0xa80000002004c504 calls pcireg_arbitration_bit_set [0xa800000020053f64] with a0=a0 at entry (arg0), a1=0xf00000, a2=[a0+114]:2, a3=0x2.
  The `jal` at 0xa80000002004c510 calls test_and_set_int64 [0xa800000020016bd0] with a0=a0+2112, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa80000002004c55c calls pcibr_errintr_group [0xa80000002004c028] with a0=(ret(pcireg_intr_status_get) << 0x0), a1=?, a2=?, a3=?, a7=0x1.
  The `jal` at 0xa80000002004c56c calls pcireg_intr_reset_set [0xa800000020055778] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c584 calls pcireg_intr_enable_bit_clr [0xa800000020055484] with a0=a0 at entry (arg0), a1=0x80, a2=?, a3=[a0+40]:1, a4=0xf.
  The `jal` at 0xa80000002004c58c calls powerfail [0xa800000020018540] with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c5ec calls pcireg_cmdword_err_get [0xa8000000200521bc] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x2.
  The `jal` at 0xa80000002004c650 calls cmn_err [0xa8000000201c6b00] with a0=0x5, a1=0xa8000000203b26a0, a2=[a0+16]:8, a3=?.
  The `jal` at 0xa80000002004c684 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b26f8, a2=?, a3=0x2.
  The `jal` at 0xa80000002004c68c calls pcibr_error_dump [0xa80000002004afcc] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c69c calls machine_error_dump [0xa800000020187420] with a0=0xa8000000203b2638, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c6a8 calls panic [0xa8000000201c7be8] with a0=0xa8000000203b2718, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c6cc calls cmn_err [0xa8000000201c6b00] with a0=0x5, a1=0xa8000000203b26c0, a2=[a0+16]:8, a3=?.
  The `jal` at 0xa80000002004c708 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b2670, a2=[a0+16]:8, a3=?.
  The `jal` at 0xa80000002004c734 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b26f8, a2=?, a3=0x2, a5=[a0+114]:2, a6=0x22133fc06000.
  The `jal` at 0xa80000002004c73c calls pcibr_error_dump [0xa80000002004afcc] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c748 calls machine_error_dump [0xa800000020187420] with a0=0xa8000000203b2638, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004c754 calls panic [0xa8000000201c7be8] with a0=0xa8000000203b2718, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004c278 targets 0xa80000002004c57c, is taken when a3(=[a0+40]:1) == a4(=0xf), and falls through when a3(=[a0+40]:1) != a4(=0xf).
  The `beq` branch at 0xa80000002004c288 targets 0xa80000002004c518, is taken when (s1(=ret(pcireg_intr_status_get)) & t8(=-0x100)) == 0, and falls through when (s1(=ret(pcireg_intr_status_get)) & t8(=-0x100)) != 0.
  The `beq` branch at 0xa80000002004c294 targets 0xa80000002004c2a4, is taken when (v0(=0x4400008800) & s1(=ret(pcireg_intr_status_get))) == 0, and falls through when (v0(=0x4400008800) & s1(=ret(pcireg_intr_status_get))) != 0.
  The `beq` branch at 0xa80000002004c2a4 targets 0xa80000002004c62c, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0xa80000002004c2d4 targets 0xa80000002004c764 and is always taken.
  The `beq` branch at 0xa80000002004c2e0 targets 0xa80000002004c3d0, is taken when t3(=[a0+114]:2) == a3(=0x2), and falls through when t3(=[a0+114]:2) != a3(=0x2).
  The `beq` branch at 0xa80000002004c2fc targets 0xa80000002004c400, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `beq` branch at 0xa80000002004c30c targets 0xa80000002004c2e8, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0xa80000002004c338 targets 0xa80000002004c380, is taken when t8(=[a0+72]) == 0, and falls through when t8(=[a0+72]) != 0.
  The `beq` branch at 0xa80000002004c340 targets 0xa80000002004c2dc, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0xa80000002004c364 targets 0xa80000002004c2dc, is taken when s1(?) < 0x65 (unsigned), and falls through when s1(?) >= 0x65 (unsigned).
  The `bnel` branch at 0xa80000002004c36c targets 0xa80000002004c2e0, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `lh t3,114(s3)` at 0xa80000002004c370 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa80000002004c378 targets 0xa80000002004c63c and is always taken.
  The `beq` branch at 0xa80000002004c380 targets 0xa80000002004c548, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xa80000002004c390 targets 0xa80000002004c35c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa80000002004c39c targets 0xa80000002004c360, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa80000002004c3a4 targets 0xa80000002004c360, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `bne` branch at 0xa80000002004c3bc targets 0xa80000002004c6f4, is taken when t8(=[0xa8000000204ae49c]) < a4(?) (unsigned), and falls through when t8(=[0xa8000000204ae49c]) >= a4(?) (unsigned).
  The `beq` branch at 0xa80000002004c3c8 targets 0xa80000002004c360 and is always taken.
  The `bne` branch at 0xa80000002004c3d0 targets 0xa80000002004c2e8, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0xa80000002004c3e8 targets 0xa80000002004c2e8, is taken when (t9(?) & 0x2) == 0, and falls through when (t9(?) & 0x2) != 0.
  The `bnel` branch at 0xa80000002004c3f0 targets 0xa80000002004c2ec, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `addiu s0,s0,1` at 0xa80000002004c3f4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa80000002004c3f8 targets 0xa80000002004c6b8 and is always taken.
  The `beq` branch at 0xa80000002004c404 targets 0xa80000002004c43c, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `bgez` branch at 0xa80000002004c440 targets 0xa80000002004c464, is taken when at(=(ret(pcireg_intr_status_get) << 0x27)) >= 0 (signed), and falls through when at(=(ret(pcireg_intr_status_get) << 0x27)) < 0 (signed).
  The `beq` branch at 0xa80000002004c45c targets 0xa80000002004c5ec, is taken when v0(?) == v1(=0xc00000), and falls through when v0(?) != v1(=0xc00000).
  The `beq` branch at 0xa80000002004c468 targets 0xa80000002004c59c, is taken when a1(=[0xa8000000204a71ac]) == 0, and falls through when a1(=[0xa8000000204a71ac]) != 0.
  The `bne` branch at 0xa80000002004c480 targets 0xa80000002004c67c, is taken when (s4(?) & a0(?)) != 0, and falls through when (s4(?) & a0(?)) == 0.
  The `beq` branch at 0xa80000002004c48c targets 0xa80000002004c5ac, is taken when a5(=[a0+114]:2) == a3(=0x2), and falls through when a5(=[a0+114]:2) != a3(=0x2).
  The `bne` branch at 0xa80000002004c498 targets 0xa80000002004c69c, is taken when (s4(?) & a6(=0x22133fc06000)) != 0, and falls through when (s4(?) & a6(=0x22133fc06000)) == 0.
  The `beq` branch at 0xa80000002004c4a4 targets 0xa80000002004c558, is taken when a0(=[a0+114]:2) == 0, and falls through when a0(=[a0+114]:2) != 0.
  The `beq` branch at 0xa80000002004c4ac targets 0xa80000002004c55c, is taken when a0(=[a0+114]:2) == a7(=0x1), and falls through when a0(=[a0+114]:2) != a7(=0x1).
  The `bne` branch at 0xa80000002004c4cc targets 0xa80000002004c50c, is taken when a2(=[a0+114]:2) != a3(=0x2), and falls through when a2(=[a0+114]:2) == a3(=0x2).
  The `beq` branch at 0xa80000002004c4dc targets 0xa80000002004c510, is taken when (s4(?) & a4(=0x10000000000)) == 0, and falls through when (s4(?) & a4(=0x10000000000)) != 0.
  The `beq` branch at 0xa80000002004c4f8 targets 0xa80000002004c510, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `bne` branch at 0xa80000002004c548 targets 0xa80000002004c5dc, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xa80000002004c550 targets 0xa80000002004c2e0 and is always taken.
  The `beq` branch at 0xa80000002004c574 targets 0xa80000002004c4c4 and is always taken.
  The `beq` branch at 0xa80000002004c57c targets 0xa80000002004c280, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002004c594 targets 0xa80000002004c284 and is always taken.
  The `beq` branch at 0xa80000002004c5a4 targets 0xa80000002004c47c and is always taken.
  The `beq` branch at 0xa80000002004c5c4 targets 0xa80000002004c490, is taken when (a1(?) & 0x6) == 0, and falls through when (a1(?) & 0x6) != 0.
  The `beq` branch at 0xa80000002004c5cc targets 0xa80000002004c494, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002004c5d4 targets 0xa80000002004c72c and is always taken.
  The `beq` branch at 0xa80000002004c5dc targets 0xa80000002004c620, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa80000002004c5e4 targets 0xa80000002004c2e0 and is always taken.
  The `bne` branch at 0xa80000002004c610 targets 0xa80000002004c464, is taken when a1(?) != a2(=0x402000), and falls through when a1(?) == a2(=0x402000).
  The `beq` branch at 0xa80000002004c618 targets 0xa80000002004c464 and is always taken.
  The `beq` branch at 0xa80000002004c624 targets 0xa80000002004c2dc and is always taken.
  The `beq` branch at 0xa80000002004c634 targets 0xa80000002004c438 and is always taken.
  The `beq` branch at 0xa80000002004c674 targets 0xa80000002004c2dc and is always taken.
  The `beq` branch at 0xa80000002004c694 targets 0xa80000002004c488 and is always taken.
  The `beq` branch at 0xa80000002004c6b0 targets 0xa80000002004c4a4 and is always taken.
  The `beq` branch at 0xa80000002004c6ec targets 0xa80000002004c2e8 and is always taken.
  The `beq` branch at 0xa80000002004c724 targets 0xa80000002004c3c4 and is always taken.
  The `beq` branch at 0xa80000002004c75c targets 0xa80000002004c494 and is always taken.
  The `beq` branch at 0xa80000002004c770 targets 0xa80000002004c308 and is always taken.
  The return at 0xa80000002004c540 has v0 = one of 0x4400008800, ret(test_and_set_int64).

- `pcibr_addr_toslot` in `IP30/unix` at 0xa80000002004c778 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004c778-0xa80000002004ca5c (740 bytes).
  It occupies 740 bytes.
  The `lbu` at 0xa80000002004c7b4 loads 1 byte from a0 (arg0 at entry) +0x38.
  The `lbu` at 0xa80000002004c7b8 loads 1 byte from a0 (arg0 at entry) +0x39.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004c7dc, `lw` at 0xa80000002004c834, `lw` at 0xa80000002004c934.
  13 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004c7ec, `ld` at 0xa80000002004c804, `ld` at 0xa80000002004c840.
  4 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0xa80000002004c870, `sw` at 0xa80000002004c8f0, `sw` at 0xa80000002004c9b8.
  2 such `sb` accesses store 1 byte to a4 (arg4 at entry) +0x0, including `sb` at 0xa80000002004c87c, `sb` at 0xa80000002004c8fc.
  4 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x0, including `sd` at 0xa80000002004c894, `sd` at 0xa80000002004c8d4, `sd` at 0xa80000002004c9d4.
  The `bne` branch at 0xa80000002004c780 targets 0xa80000002004c7b4, is taken when a1 < v0(=0x20000) (unsigned), and falls through when a1 >= v0(=0x20000) (unsigned).
  The `beq` branch at 0xa80000002004c790 targets 0xa80000002004c7b4, is taken when a1 >= v1(=0x30000) (unsigned), and falls through when a1 < v1(=0x30000) (unsigned).
  The `bne` branch at 0xa80000002004c7a0 targets 0xa80000002004c8a0, is taken when a1 < a0(=0x28000) (unsigned), and falls through when a1 >= a0(=0x28000) (unsigned).
  The `beq` branch at 0xa80000002004c7ac targets 0xa80000002004c8a8 and is always taken.
  The `bne` branch at 0xa80000002004c7cc targets 0xa80000002004c920, is taken when a6(=[a0+57]:1) < v0(=[a0+56]:1) (signed), and falls through when a6(=[a0+57]:1) >= v0(=[a0+56]:1) (signed).
  The `blez` branch at 0xa80000002004c7e0 targets 0xa80000002004c908, is taken when t9(?) <= 0 (signed), and falls through when t9(?) > 0 (signed).
  The `beq` branch at 0xa80000002004c7e8 targets 0xa80000002004ca4c and is always taken.
  The `beq` branch at 0xa80000002004c7fc targets 0xa80000002004c908, is taken when t3(?) >= t9(?) (signed), and falls through when t3(?) < t9(?) (signed).
  The `beq` branch at 0xa80000002004c808 targets 0xa80000002004c7f0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xa80000002004c810 targets 0xa80000002004ca40 and is always taken.
  The `beq` branch at 0xa80000002004c824 targets 0xa80000002004c7f0, is taken when a7(?) >= 0x6 (signed), and falls through when a7(?) < 0x6 (signed).
  The `beq` branch at 0xa80000002004c838 targets 0xa80000002004c818, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0xa80000002004c848 targets 0xa80000002004c818, is taken when a1 < t1(?) (unsigned), and falls through when a1 >= t1(?) (unsigned).
  The `beql` branch at 0xa80000002004c85c targets 0xa80000002004c81c, is taken when a1 >= v1(?) (unsigned), and falls through when a1 < v1(?) (unsigned); its branch-likely delay slot `addiu a7,a7,1` at 0xa80000002004c860 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa80000002004c864 targets 0xa80000002004c888, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002004c86c targets 0xa80000002004c88c, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa80000002004c874 targets 0xa80000002004c880, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xa80000002004c888 targets 0xa80000002004c874, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0xa80000002004c890 targets 0xa80000002004c87c, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0xa80000002004c898 targets 0xa80000002004c880 and is always taken.
  The `beq` branch at 0xa80000002004c8b0 targets 0xa80000002004c8e0, is taken when a4 == 0, and falls through when a4 != 0.
  The `bne` branch at 0xa80000002004c8c0 targets 0xa80000002004c8e8, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0xa80000002004c8c8 targets 0xa80000002004c8f4, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0xa80000002004c8d0 targets 0xa80000002004c8fc, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0xa80000002004c8d8 targets 0xa80000002004c880 and is always taken.
  The `beq` branch at 0xa80000002004c8e0 targets 0xa80000002004c8c8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002004c8ec targets 0xa80000002004c8d0, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa80000002004c8f4 targets 0xa80000002004c880, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xa80000002004c900 targets 0xa80000002004c880 and is always taken.
  The `beq` branch at 0xa80000002004c918 targets 0xa80000002004c7dc, is taken when t9(=[a0+57]:1) >= v0(?) (signed), and falls through when t9(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0xa80000002004c924 targets 0xa80000002004c9f8, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `blez` branch at 0xa80000002004c938 targets 0xa80000002004c9e0, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0xa80000002004c940 targets 0xa80000002004c94c and is always taken.
  The `beq` branch at 0xa80000002004c948 targets 0xa80000002004c9e0, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa80000002004c95c targets 0xa80000002004c948, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xa80000002004c968 targets 0xa80000002004c948, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa80000002004c970 targets 0xa80000002004c988 and is always taken.
  The `beq` branch at 0xa80000002004c97c targets 0xa80000002004c948, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa80000002004c98c targets 0xa80000002004c978, is taken when a1 < a7(?) (unsigned), and falls through when a1 >= a7(?) (unsigned).
  The `beq` branch at 0xa80000002004c9a0 targets 0xa80000002004c978, is taken when a1 >= t9(?) (unsigned), and falls through when a1 < t9(?) (unsigned).
  The `beq` branch at 0xa80000002004c9a8 targets 0xa80000002004c9c4, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002004c9b4 targets 0xa80000002004c9cc, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa80000002004c9bc targets 0xa80000002004c880 and is always taken.
  The `beq` branch at 0xa80000002004c9c4 targets 0xa80000002004c880, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0xa80000002004c9d8 targets 0xa80000002004c880 and is always taken.
  The `beq` branch at 0xa80000002004c9f0 targets 0xa80000002004c934, is taken when a4(=[a0+57]:1) >= v0(?) (signed), and falls through when a4(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0xa80000002004c9f8 targets 0xa80000002004ca2c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xa80000002004ca04 targets 0xa80000002004ca14, is taken when a1 >= a5(=0x40000000) (unsigned), and falls through when a1 < a5(=0x40000000) (unsigned).
  The `beq` branch at 0xa80000002004ca0c targets 0xa80000002004ca28 and is always taken.
  The `beq` branch at 0xa80000002004ca2c targets 0xa80000002004ca38, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0xa80000002004ca38 targets 0xa80000002004c880 and is always taken.
  The `beq` branch at 0xa80000002004ca44 targets 0xa80000002004c830 and is always taken.
  The `beq` branch at 0xa80000002004ca54 targets 0xa80000002004c808 and is always taken.
  The return at 0xa80000002004c880 has v0 = one of ?, 0xff.

- `pcibr_error_cleanup` in `IP30/unix` at 0xa80000002004ca5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004ca5c-0xa80000002004cab0 (84 bytes).
  It occupies 84 bytes.
  The `lh` at 0xa80000002004ca5c loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `jal` at 0xa80000002004ca84 calls pcireg_intr_reset_set [0xa800000020055778] with a0=a0 at entry (arg0), a1=one of 0x41, 0x3cff00000041, a2=a2 at entry (arg2), a3=0x1, a4=[a0+114]:2.
  The `jal` at 0xa80000002004ca8c calls pcireg_tflush_get [0xa800000020052634] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004ca74 targets 0xa80000002004ca84, is taken when a4(=[a0+114]:2) == 0, and falls through when a4(=[a0+114]:2) != 0.
  The `beq` branch at 0xa80000002004ca7c targets 0xa80000002004caa4, is taken when a4(=[a0+114]:2) == a3(=0x1), and falls through when a4(=[a0+114]:2) != a3(=0x1).
  The `beq` branch at 0xa80000002004caa8 targets 0xa80000002004ca84 and is always taken.
  The return at 0xa80000002004ca9c has v0 = ret(pcireg_tflush_get).

- `pcibr_error_extract` in `IP30/unix` at 0xa80000002004cab0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004cab0-0xa80000002004cb28 (120 bytes).
  It occupies 120 bytes.
  The `jal` at 0xa80000002004cacc calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=a0 at entry (arg0), a1=0xa8000000203b2748, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004cae8 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004cafc calls pcireg_pci_bus_addr_get [0xa800000020054d70] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?, a5=0xff.
  The `jal` at 0xa80000002004cb14 calls pcibr_addr_toslot [0xa80000002004c778] with a0=?, a1=ret(pcireg_pci_bus_addr_get), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `beq` branch at 0xa80000002004cad4 targets 0xa80000002004cae8, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0xa80000002004caf4 targets 0xa80000002004cb20, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa80000002004cb20 targets 0xa80000002004cadc and is always taken.
  The return at 0xa80000002004cae0 has v0 = one of 0xff, ?.

- `pcibr_device_disable` in `IP30/unix` at 0xa80000002004cb28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004cb28-0xa80000002004cb30 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa80000002004cb28 has v0 = ?.

- `pcibr_pioerror` in `IP30/unix` at 0xa80000002004cb30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004cb30-0xa80000002004d878 (3400 bytes).
  It occupies 3400 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xa80000002004cb48, `lw` at 0xa80000002004d01c.
  The `lw` at 0xa80000002004cb50 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xa80000002004cb6c loads 8 bytes from a3 (arg3 at entry) +0x18.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xa80000002004cba0, `lh` at 0xa80000002004d040, `lh` at 0xa80000002004d0f8.
  The `lw` at 0xa80000002004cba8 loads 4 bytes from a0 (arg0 at entry) +0x48.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004ccf4, `lw` at 0xa80000002004ced8, `lw` at 0xa80000002004cf80.
  21 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004cd00, `ld` at 0xa80000002004cee4, `ld` at 0xa80000002004cf18.
  12 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0xa80000002004cd84, `lbu` at 0xa80000002004ce04, `lbu` at 0xa80000002004ce54.
  10 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x38, including `lbu` at 0xa80000002004cd88, `lbu` at 0xa80000002004ce0c, `lbu` at 0xa80000002004ce58.
  The `ll` at 0xa80000002004cf30 loads 4 bytes from ?.
  The `sc` at 0xa80000002004cf3c stores 4 bytes to ?.
  5 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xa80000002004d03c, `lw` at 0xa80000002004d0dc, `lw` at 0xa80000002004d630.
  3 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xa80000002004d064, `sw` at 0xa80000002004d090, `sw` at 0xa80000002004d244.
  2 such `sh` accesses store 2 bytes to a3 (arg3 at entry) +0x8, including `sh` at 0xa80000002004d074, `sh` at 0xa80000002004d254.
  The `sd` at 0xa80000002004d078 stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `sd` at 0xa80000002004d080 stores 8 bytes to a3 (arg3 at entry) +0x20.
  5 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0x8, including `lh` at 0xa80000002004d0d8, `lh` at 0xa80000002004d6b8, `lh` at 0xa80000002004d764.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xa80000002004d604, `ld` at 0xa80000002004d624.
  The `lw` at 0xa80000002004d778 loads 4 bytes from a3 (arg3 at entry) +0x24.
  4 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x28, including `ld` at 0xa80000002004d7cc, `ld` at 0xa80000002004d804, `ld` at 0xa80000002004d82c.
  The `lw` at 0xa80000002004d874 loads 4 bytes from (a0 + ([a0+56]:1 << 0x7)) +0x110.
  The `jal` at 0xa80000002004cb84 calls pcibr_debug [0xa800000020046990] with a0=0x200, a1=[a0], a2=0xa8000000203b2758, a3=a0 at entry (arg0), a4=[a3+24]:8.
  The `jal` at 0xa80000002004d020 calls pcibr_debug [0xa800000020046990] with a0=0x200, a1=[a0], a2=0xa8000000203b2790, a3=?.
  The `jal` at 0xa80000002004d0b0 calls pciio_error_handler [0xa80000002005f828] with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004d3f4 calls pcibr_error_cleanup [0xa80000002004ca5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa80000002004d414 calls pciio_error_handler [0xa80000002005f828] with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004d428 calls pcibr_device_disable [0xa80000002004cb28] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xa80000002004d438 calls pcibr_error_cleanup [0xa80000002004ca5c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa80000002004d610 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b27d0, a2=[a0+16]:8, a3=[a3+24]:8.
  The `jal` at 0xa80000002004d628 calls cmn_err [0xa8000000201c6b00] with a0=0x1, a1=0xa8000000203b2830, a2=[a0+16]:8, a3=?.
  The `jal` at 0xa80000002004d650 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2970, a2=0xa8000000203b28e8, a3=?.
  The `jal` at 0xa80000002004d658 calls pcireg_intr_status_get [0xa800000020055060] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004d670 calls pcibr_error_dump [0xa80000002004afcc] with a0=a0 at entry (arg0), a1=0xa8000000203b2170, a2=?, a3=?.
  The `jal` at 0xa80000002004d694 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2910, a2=0xa8000000203b2920, a3=?.
  The `jal` at 0xa80000002004d6ac calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2930, a2=0xa8000000203b2940, a3=?.
  The `jal` at 0xa80000002004d700 calls pcireg_device_get [0xa800000020058074] with a0=a0 at entry (arg0), a1=?, a2=[a3+8]:2, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xa80000002004d71c calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2930, a2=0xa8000000203b2978, a3=?.
  The `jal` at 0xa80000002004d738 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2930, a2=0xa8000000203b2980, a3=?.
  The `jal` at 0xa80000002004d758 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2950, a2=0xa8000000203b2960, a3=ret(pcireg_device_get), a4=0xa80000002043ef58.
  The `jal` at 0xa80000002004d7d0 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2848, a2=?, a3=?, a4=[a3+36]-8, a5=[a3+40]:8, a6=0x4, a7=0x5.
  The `jal` at 0xa80000002004d808 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2878, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4, a7=0x5.
  The `jal` at 0xa80000002004d830 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b28b8, a2=?, a3=?, a4=[a3+40]:8, a5=0x7.
  The `jal` at 0xa80000002004d84c calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203b2898, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4.
  The `beq` branch at 0xa80000002004cbb8 targets 0xa80000002004d190, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa80000002004cbe8 targets 0xa80000002004cc38, is taken when s2(=[a3+24]:8) < t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned).
  The `beq` branch at 0xa80000002004cbf0 targets 0xa80000002004cc20, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xa80000002004cbf8 targets 0xa80000002004d448, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `beq` branch at 0xa80000002004cc18 targets 0xa80000002004cc28 and is always taken.
  The `bne` branch at 0xa80000002004cc28 targets 0xa80000002004cc50, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0xa80000002004cc30 targets 0xa80000002004cc78 and is always taken.
  The `bne` branch at 0xa80000002004cc38 targets 0xa80000002004d258, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0xa80000002004cc64 targets 0xa80000002004cc78, is taken when s2(=[a3+24]:8) >= a2(=one of 0x29000, 0x829000) (unsigned), and falls through when s2(=[a3+24]:8) < a2(=one of 0x29000, 0x829000) (unsigned).
  The `bne` branch at 0xa80000002004cc84 targets 0xa80000002004cd08, is taken when s2(=[a3+24]:8) < t3(=one of 0x200000, 0xa00000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x200000, 0xa00000) (unsigned).
  The `beq` branch at 0xa80000002004cc98 targets 0xa80000002004cd08, is taken when s2(=[a3+24]:8) >= t2(=one of 0xc00000, 0x1400000) (unsigned), and falls through when s2(=[a3+24]:8) < t2(=one of 0xc00000, 0x1400000) (unsigned).
  The `beq` branch at 0xa80000002004ccbc targets 0xa80000002004d264, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa80000002004ccc8 targets 0xa80000002004d264, is taken when v0(?) == v1(=0x3), and falls through when v0(?) != v1(=0x3).
  The `blez` branch at 0xa80000002004ccd0 targets 0xa80000002004cce0, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `bne` branch at 0xa80000002004cce0 targets 0xa80000002004ccf0, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xa80000002004ccf8 targets 0xa80000002004d454, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa80000002004cd08 targets 0xa80000002004d1a8, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa80000002004cd14 targets 0xa80000002004cda8, is taken when s2(=[a3+24]:8) < t8(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x40000000) (unsigned).
  The `bne` branch at 0xa80000002004cd28 targets 0xa80000002004cda8, is taken when t9(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa80000002004cd44 targets 0xa80000002004cd58, is taken when s2(=[a3+24]:8) < ra(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x80000000) (unsigned).
  The `beq` branch at 0xa80000002004cd54 targets 0xa80000002004cdc4, is taken when at(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when at(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa80000002004cd64 targets 0xa80000002004cd7c, is taken when s2(=[a3+24]:8) < v0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x100000000) (unsigned).
  The `beq` branch at 0xa80000002004cd74 targets 0xa80000002004ce44, is taken when v1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa80000002004cd7c targets 0xa80000002004d510, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004cd9c targets 0xa80000002004ce94 and is always taken.
  The `bne` branch at 0xa80000002004cdb0 targets 0xa80000002004ce1c, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xa80000002004cdbc targets 0xa80000002004ce20, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa80000002004cdd8 targets 0xa80000002004cdf4, is taken when s2(=[a3+24]:8) < t0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t0(=0x100000000) (unsigned).
  The `beq` branch at 0xa80000002004cdec targets 0xa80000002004ce44, is taken when t1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa80000002004cdf4 targets 0xa80000002004d490, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004ce14 targets 0xa80000002004ce94 and is always taken.
  The `bne` branch at 0xa80000002004ce28 targets 0xa80000002004ce78, is taken when s2(=[a3+24]:8) < t3(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=0x100000000) (unsigned).
  The `bne` branch at 0xa80000002004ce3c targets 0xa80000002004ce74, is taken when t8(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t8(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa80000002004ce4c targets 0xa80000002004d474, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004ce6c targets 0xa80000002004ce94 and is always taken.
  The `beq` branch at 0xa80000002004ce78 targets 0xa80000002004d270, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `bne` branch at 0xa80000002004ce9c targets 0xa80000002004cff0, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0xa80000002004ceb0 targets 0xa80000002004d868 and is always taken.
  The `bne` branch at 0xa80000002004ced0 targets 0xa80000002004cff0, is taken when t1(=[a0+57]:1) < a4(?) (signed), and falls through when t1(=[a0+57]:1) >= a4(?) (signed).
  The `blez` branch at 0xa80000002004cee0 targets 0xa80000002004cebc, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0xa80000002004cee8 targets 0xa80000002004d85c and is always taken.
  The `beq` branch at 0xa80000002004cef0 targets 0xa80000002004cfdc, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa80000002004cef8 targets 0xa80000002004cf84, is taken when v0(?) == s1(=0x5), and falls through when v0(?) != s1(=0x5).
  The `beq` branch at 0xa80000002004cf00 targets 0xa80000002004cf84, is taken when v0(?) == s4(=0x6), and falls through when v0(?) != s4(=0x6).
  The `bne` branch at 0xa80000002004cf08 targets 0xa80000002004cf8c, is taken when v0(?) != s0(?), and falls through when v0(?) == s0(?).
  The `bne` branch at 0xa80000002004cf10 targets 0xa80000002004cf8c, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0xa80000002004cf24 targets 0xa80000002004cf8c, is taken when s3(?) >= v0(?) (unsigned), and falls through when s3(?) < v0(?) (unsigned).
  The `beql` branch at 0xa80000002004cf40 targets 0xa80000002004cf30, is taken when t2(=table(0x1)) == 0, and falls through when t2(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0xa80000002004cf44 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa80000002004cf48 targets 0xa80000002004d14c, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004cf5c targets 0xa80000002004ceb8, is taken when t9(?) >= s6(?) (signed), and falls through when t9(?) < s6(?) (signed).
  The `beq` branch at 0xa80000002004cf68 targets 0xa80000002004cf50, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002004cf74 targets 0xa80000002004cf50, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xa80000002004cf7c targets 0xa80000002004cf9c and is always taken.
  The `beq` branch at 0xa80000002004cf84 targets 0xa80000002004cf10, is taken when s0(?) == s7(=0x4), and falls through when s0(?) != s7(=0x4).
  The `beq` branch at 0xa80000002004cf90 targets 0xa80000002004cf50, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0xa80000002004cfa8 targets 0xa80000002004cef0, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa80000002004cfb0 targets 0xa80000002004cef0, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0xa80000002004cfd4 targets 0xa80000002004cef8, is taken when v0(?) != ra(=0x1), and falls through when v0(?) == ra(=0x1).
  The `bne` branch at 0xa80000002004cfe0 targets 0xa80000002004cf8c, is taken when s0(?) != s7(=0x4), and falls through when s0(?) == s7(=0x4).
  The `beq` branch at 0xa80000002004cfe8 targets 0xa80000002004cf10 and is always taken.
  The `beq` branch at 0xa80000002004d030 targets 0xa80000002004d094, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002004d038 targets 0xa80000002004d078, is taken when s6(=0xff) == s2(?), and falls through when s6(=0xff) != s2(?).
  The `beq` branch at 0xa80000002004d044 targets 0xa80000002004d23c, is taken when a3(=[a0+114]:2) == s7(=0x2), and falls through when a3(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xa80000002004d058 targets 0xa80000002004d244, is taken when s6(=0xff) == a6(?), and falls through when s6(=0xff) != a6(?).
  The `beq` branch at 0xa80000002004d094 targets 0xa80000002004d3f0, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0xa80000002004d09c targets 0xa80000002004d604, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002004d0b8 targets 0xa80000002004d118, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The `beq` branch at 0xa80000002004d0c4 targets 0xa80000002004d620, is taken when v0(=ret(pciio_error_handler)) == t1(=0x9), and falls through when v0(=ret(pciio_error_handler)) != t1(=0x9).
  The `bne` branch at 0xa80000002004d0d0 targets 0xa80000002004d648, is taken when t2(=[0xa8000000204a80da]:2) != 0, and falls through when t2(=[0xa8000000204a80da]:2) == 0.
  The `beq` branch at 0xa80000002004d0f0 targets 0xa80000002004d22c, is taken when s6(=0xff) == v0(?), and falls through when s6(=0xff) != v0(?).
  The `beq` branch at 0xa80000002004d0fc targets 0xa80000002004d234, is taken when a1(=[a0+114]:2) == s7(=0x2), and falls through when a1(=[a0+114]:2) != s7(=0x2).
  The `bltz` branch at 0xa80000002004d108 targets 0xa80000002004d428, is taken when a4(=([a3] << 0x2)) < 0 (signed), and falls through when a4(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0xa80000002004d110 targets 0xa80000002004d438, is taken when s5(=a2) == s7(=0x2), and falls through when s5(=a2) != s7(=0x2).
  The `bltz` branch at 0xa80000002004d158 targets 0xa80000002004cf50, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `beq` branch at 0xa80000002004d164 targets 0xa80000002004cf50, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002004d188 targets 0xa80000002004cf50 and is always taken.
  The `beq` branch at 0xa80000002004d1a0 targets 0xa80000002004cbcc and is always taken.
  The `beq` branch at 0xa80000002004d1a8 targets 0xa80000002004d49c, is taken when a4(=[a0+72]) == 0, and falls through when a4(=[a0+72]) != 0.
  The `bne` branch at 0xa80000002004d1b4 targets 0xa80000002004cd0c, is taken when a4(=[a0+72]) != t9(=0x1), and falls through when a4(=[a0+72]) == t9(=0x1).
  The `bne` branch at 0xa80000002004d1c4 targets 0xa80000002004d570, is taken when s2(=[a3+24]:8) < ra(=0xc0000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0xc0000000) (unsigned).
  The `bne` branch at 0xa80000002004d1d8 targets 0xa80000002004d56c, is taken when at(=0xffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0xffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa80000002004d1ec targets 0xa80000002004d204, is taken when s2(=[a3+24]:8) < t8(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x100000000) (unsigned).
  The `beq` branch at 0xa80000002004d1fc targets 0xa80000002004d58c, is taken when t9(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x13fffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa80000002004d204 targets 0xa80000002004d5f8, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004d224 targets 0xa80000002004ce94 and is always taken.
  The `beq` branch at 0xa80000002004d22c targets 0xa80000002004d108 and is always taken.
  The `beq` branch at 0xa80000002004d234 targets 0xa80000002004d104 and is always taken.
  The `beq` branch at 0xa80000002004d23c targets 0xa80000002004d04c and is always taken.
  The `beq` branch at 0xa80000002004d250 targets 0xa80000002004d078 and is always taken.
  The `beq` branch at 0xa80000002004d25c targets 0xa80000002004cc74 and is always taken.
  The `beq` branch at 0xa80000002004d268 targets 0xa80000002004ccd0 and is always taken.
  The `beq` branch at 0xa80000002004d270 targets 0xa80000002004d5bc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xa80000002004d284 targets 0xa80000002004d480, is taken when t1(=[a0+57]:1) < a4(=[a0+56]:1) (signed), and falls through when t1(=[a0+57]:1) >= a4(=[a0+56]:1) (signed).
  The `beq` branch at 0xa80000002004d2a0 targets 0xa80000002004d2bc and is always taken.
  The `bne` branch at 0xa80000002004d2b0 targets 0xa80000002004ce98, is taken when t1(=[a0+57]:1) < t2(?) (signed), and falls through when t1(=[a0+57]:1) >= t2(?) (signed).
  The `bne` branch at 0xa80000002004d2b8 targets 0xa80000002004ce94, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `blez` branch at 0xa80000002004d2c8 targets 0xa80000002004d2a8, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `bne` branch at 0xa80000002004d2d0 targets 0xa80000002004d2a8, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa80000002004d2d8 targets 0xa80000002004d2f8 and is always taken.
  The `beq` branch at 0xa80000002004d2ec targets 0xa80000002004d2a8, is taken when v0(?) >= s5(?) (signed), and falls through when v0(?) < s5(?) (signed).
  The `bne` branch at 0xa80000002004d2f4 targets 0xa80000002004d2a8, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa80000002004d304 targets 0xa80000002004d2e4, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `bne` branch at 0xa80000002004d30c targets 0xa80000002004d2e4, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa80000002004d318 targets 0xa80000002004d344 and is always taken.
  The `beq` branch at 0xa80000002004d334 targets 0xa80000002004d2e0, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0xa80000002004d33c targets 0xa80000002004d2e4, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa80000002004d35c targets 0xa80000002004d334, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xa80000002004d36c targets 0xa80000002004d334, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002004d384 targets 0xa80000002004d334, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0xa80000002004d398 targets 0xa80000002004d334, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xa80000002004d3a0 targets 0xa80000002004d334, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0xa80000002004d3a8 targets 0xa80000002004d334, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xa80000002004d3b0 targets 0xa80000002004d320, is taken when t3(?) == a3(?), and falls through when t3(?) != a3(?).
  The `beq` branch at 0xa80000002004d3b8 targets 0xa80000002004d3d0, is taken when t3(?) == s7(=0x4), and falls through when t3(?) != s7(=0x4).
  The `beq` branch at 0xa80000002004d3c0 targets 0xa80000002004d3d0, is taken when t3(?) == s1(=0x5), and falls through when t3(?) != s1(=0x5).
  The `bne` branch at 0xa80000002004d3c8 targets 0xa80000002004d334, is taken when t3(?) != s4(=0x6), and falls through when t3(?) == s4(=0x6).
  The `beq` branch at 0xa80000002004d3d0 targets 0xa80000002004d320, is taken when a3(?) == s7(=0x4), and falls through when a3(?) != s7(=0x4).
  The `beq` branch at 0xa80000002004d3d8 targets 0xa80000002004d320, is taken when a3(?) == s1(=0x5), and falls through when a3(?) != s1(=0x5).
  The `bne` branch at 0xa80000002004d3e0 targets 0xa80000002004d334, is taken when a3(?) != s4(=0x6), and falls through when a3(?) == s4(=0x6).
  The `beq` branch at 0xa80000002004d3e8 targets 0xa80000002004d324 and is always taken.
  The `bne` branch at 0xa80000002004d3fc targets 0xa80000002004d40c, is taken when s6(=0xff) != s2(?), and falls through when s6(=0xff) == s2(?).
  The `beq` branch at 0xa80000002004d404 targets 0xa80000002004d420 and is always taken.
  The `beq` branch at 0xa80000002004d420 targets 0xa80000002004d11c and is always taken.
  The `beq` branch at 0xa80000002004d430 targets 0xa80000002004d110 and is always taken.
  The `beq` branch at 0xa80000002004d440 targets 0xa80000002004d11c and is always taken.
  The `beq` branch at 0xa80000002004d44c targets 0xa80000002004cc08 and is always taken.
  The `beq` branch at 0xa80000002004d46c targets 0xa80000002004cd08 and is always taken.
  The `beq` branch at 0xa80000002004d478 targets 0xa80000002004d278 and is always taken.
  The `beq` branch at 0xa80000002004d488 targets 0xa80000002004ce94 and is always taken.
  The `beq` branch at 0xa80000002004d494 targets 0xa80000002004d278 and is always taken.
  The `bne` branch at 0xa80000002004d4a0 targets 0xa80000002004d520, is taken when s2(=[a3+24]:8) < ra(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x40000000) (unsigned).
  The `bne` branch at 0xa80000002004d4b4 targets 0xa80000002004d520, is taken when at(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa80000002004d4d0 targets 0xa80000002004d4e8, is taken when s2(=[a3+24]:8) < v0(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x80000000) (unsigned).
  The `beq` branch at 0xa80000002004d4e0 targets 0xa80000002004d540, is taken when v1(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa80000002004d4e8 targets 0xa80000002004d5ec, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004d508 targets 0xa80000002004ce94 and is always taken.
  The `beq` branch at 0xa80000002004d514 targets 0xa80000002004d278 and is always taken.
  The `bne` branch at 0xa80000002004d528 targets 0xa80000002004ce78, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xa80000002004d538 targets 0xa80000002004ce74, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa80000002004d544 targets 0xa80000002004d5d4, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004d564 targets 0xa80000002004ce94 and is always taken.
  The `bne` branch at 0xa80000002004d578 targets 0xa80000002004ce74, is taken when s2(=[a3+24]:8) < a4(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x100000000) (unsigned).
  The `bne` branch at 0xa80000002004d584 targets 0xa80000002004ce74, is taken when a7(=0x13fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa80000002004d594 targets 0xa80000002004d5e0, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa80000002004d5b4 targets 0xa80000002004ce94 and is always taken.
  The `beq` branch at 0xa80000002004d5cc targets 0xa80000002004ce94 and is always taken.
  The `beq` branch at 0xa80000002004d5d8 targets 0xa80000002004d278 and is always taken.
  The `beq` branch at 0xa80000002004d5e4 targets 0xa80000002004d278 and is always taken.
  The `beq` branch at 0xa80000002004d5f0 targets 0xa80000002004d278 and is always taken.
  The `beq` branch at 0xa80000002004d5fc targets 0xa80000002004d278 and is always taken.
  The `beq` branch at 0xa80000002004d618 targets 0xa80000002004d11c and is always taken.
  The `bltz` branch at 0xa80000002004d638 targets 0xa80000002004d778, is taken when a2(=([a3] << 0x8)) < 0 (signed), and falls through when a2(=([a3] << 0x8)) >= 0 (signed).
  The `beq` branch at 0xa80000002004d640 targets 0xa80000002004d0cc and is always taken.
  The `beq` branch at 0xa80000002004d668 targets 0xa80000002004d67c, is taken when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) != 0.
  The `bgez` branch at 0xa80000002004d6c4 targets 0xa80000002004d0ec, is taken when a4(=([a3] << 0x2)) >= 0 (signed), and falls through when a4(=([a3] << 0x2)) < 0 (signed).
  The `beq` branch at 0xa80000002004d6cc targets 0xa80000002004d7e0, is taken when s6(=0xff) == a0(?), and falls through when s6(=0xff) != a0(?).
  The `beq` branch at 0xa80000002004d6d8 targets 0xa80000002004d7f4, is taken when a5(=[a0+114]:2) == s7(=0x2), and falls through when a5(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xa80000002004d6ec targets 0xa80000002004d0f0, is taken when s0(?) >= a6(=[a0+57]:1+1) (signed), and falls through when s0(?) < a6(=[a0+57]:1+1) (signed).
  The `beq` branch at 0xa80000002004d770 targets 0xa80000002004d0ec and is always taken.
  The `beq` branch at 0xa80000002004d780 targets 0xa80000002004d818, is taken when v0(=[a3+36]) == a5(=0x7), and falls through when v0(=[a3+36]) != a5(=0x7).
  The `beq` branch at 0xa80000002004d788 targets 0xa80000002004d840, is taken when s7(=0x2) == v0(=[a3+36]), and falls through when s7(=0x2) != v0(=[a3+36]).
  The `beq` branch at 0xa80000002004d790 targets 0xa80000002004d7fc, is taken when v0(=[a3+36]) == a6(=0x4), and falls through when v0(=[a3+36]) != a6(=0x4).
  The `beq` branch at 0xa80000002004d798 targets 0xa80000002004d800, is taken when v0(=[a3+36]) == a7(=0x5), and falls through when v0(=[a3+36]) != a7(=0x5).
  The `beq` branch at 0xa80000002004d7a4 targets 0xa80000002004d7fc, is taken when v0(=[a3+36]) == t0(=0x6), and falls through when v0(=[a3+36]) != t0(=0x6).
  The `beq` branch at 0xa80000002004d7b0 targets 0xa80000002004d640, is taken when a4(=[a3+36]-8) >= 0x6 (unsigned), and falls through when a4(=[a3+36]-8) < 0x6 (unsigned).
  The `beq` branch at 0xa80000002004d7d8 targets 0xa80000002004d640 and is always taken.
  The `bne` branch at 0xa80000002004d7e4 targets 0xa80000002004d0f0, is taken when t1(=[a0+57]:1) < 0xff (signed), and falls through when t1(=[a0+57]:1) >= 0xff (signed).
  The `beq` branch at 0xa80000002004d7ec targets 0xa80000002004d6f4 and is always taken.
  The `beq` branch at 0xa80000002004d7f4 targets 0xa80000002004d6e0 and is always taken.
  The `beq` branch at 0xa80000002004d810 targets 0xa80000002004d640 and is always taken.
  The `beq` branch at 0xa80000002004d838 targets 0xa80000002004d640 and is always taken.
  The `beq` branch at 0xa80000002004d854 targets 0xa80000002004d640 and is always taken.
  The `beq` branch at 0xa80000002004d860 targets 0xa80000002004cf68 and is always taken.
  The `beq` branch at 0xa80000002004d870 targets 0xa80000002004cedc and is always taken.
  The return at 0xa80000002004d144 has v0 = one of ?, 0x7.
  The instructions from 0xa80000002004cda4 to 0xa80000002004cda4 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa80000002004d51c to 0xa80000002004d51c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmard_error` in `IP30/unix` at 0xa80000002004d878 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004d878-0xa80000002004d9a0 (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0xa80000002004d878 loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xa80000002004d8bc, `lw` at 0xa80000002004d8d8.
  The `sh` at 0xa80000002004d8c0 stores 2 bytes to a3 (arg3 at entry) +0x8.
  2 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xa80000002004d8d4, `sw` at 0xa80000002004d8ec.
  The `sd` at 0xa80000002004d8dc stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `lh` at 0xa80000002004d908 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xa80000002004d8a4 calls pcireg_resp_err_buf_get [0xa800000020052c18] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004d8b0 calls pcireg_resp_err_dev_get [0xa800000020052d8c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004d8d0 calls pcireg_resp_err_get [0xa800000020052928] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004d8f8 calls pciio_error_handler [0xa80000002005f828] with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004d914 calls pcibr_device_disable [0xa80000002004cb28] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004d928 calls pcireg_intr_reset_set [0xa800000020055778] with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `jal` at 0xa80000002004d944 calls pcireg_rrb_get [0xa800000020058b74] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004d970 calls pcireg_rrb_set [0xa800000020058d84] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004d980 calls pcireg_rrb_set [0xa800000020058d84] with a0=a0 at entry (arg0), a1=?, a2=ret(pcireg_rrb_get), a3=?.
  The `beq` branch at 0xa80000002004d900 targets 0xa80000002004d91c, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xa80000002004d998 has v0 = ret(pciio_error_handler).

- `pcibr_dmawr_error` in `IP30/unix` at 0xa80000002004d9a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004d9a0-0xa80000002004d9e8 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xa80000002004d9b4 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xa80000002004d9c4 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xa80000002004d9b0 calls pciio_error_handler [0xa80000002005f828] with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004d9d0 calls pcibr_device_disable [0xa80000002004cb28] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004d9b8 targets 0xa80000002004d9d8, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xa80000002004d9e0 has v0 = ret(pciio_error_handler).

- `pcibr_error_handler` in `IP30/unix` at 0xa80000002004d9e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004d9e8-0xa80000002004dab4 (204 bytes).
  It occupies 204 bytes.
  The `lw` at 0xa80000002004da1c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0xa80000002004da20 calls pcibr_debug [0xa800000020046990] with a0=0x200, a1=[a0], a2=0xa8000000203b2988, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xa80000002004da40 calls pcibr_pioerror [0xa80000002004cb30] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004da6c calls pcibr_dmard_error [0xa80000002004d878] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004da8c calls pcibr_dmawr_error [0xa80000002004d9a0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `beq` branch at 0xa80000002004da2c targets 0xa80000002004da4c, is taken when (s0(=a1) & 0x4) == 0, and falls through when (s0(=a1) & 0x4) != 0.
  The `beq` branch at 0xa80000002004da50 targets 0xa80000002004da98, is taken when (s0(=a1) & 0x8) == 0, and falls through when (s0(=a1) & 0x8) != 0.
  The `beq` branch at 0xa80000002004da58 targets 0xa80000002004da7c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002004da7c targets 0xa80000002004da98, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0xa80000002004daac has v0 = one of ?, ret(pcibr_dmawr_error).

- `pcibr_error_handler_wrapper` in `IP30/unix` at 0xa80000002004dab4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004dab4-0xa80000002004dcfc (584 bytes).
  It occupies 584 bytes.
  The `lw` at 0xa80000002004dac4 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xa80000002004db28 loads 8 bytes from a3 (arg3 at entry) +0x18.
  The `ld` at 0xa80000002004db94 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lh` at 0xa80000002004dc74 loads 2 bytes from a3 (arg3 at entry) +0x50.
  The `lw` at 0xa80000002004dc7c loads 4 bytes from a3 (arg3 at entry) +0x0.
  The `sw` at 0xa80000002004dc90 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `sh` at 0xa80000002004dc9c stores 2 bytes to a3 (arg3 at entry) +0x8.
  The `ld` at 0xa80000002004dca4 loads 8 bytes from ?.
  The `jal` at 0xa80000002004db04 calls pcibr_debug [0xa800000020046990] with a0=0x200, a1=[a0], a2=0xa8000000203b29c0, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xa80000002004dc2c calls pcibr_error_handler [0xa80000002004d9e8] with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004dc4c calls pcibr_error_handler [0xa80000002004d9e8] with a0=[a0+64]:8, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004dca8 calls pcibr_error_handler [0xa80000002004d9e8] with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xa80000002004dccc calls pcibr_error_handler [0xa80000002004d9e8] with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xa80000002004dce8 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b2a00, a2=[a3+24]:8, a3=?.
  The `beq` branch at 0xa80000002004db20 targets 0xa80000002004dc5c, is taken when (s1(=a1) & 0x4) == 0, and falls through when (s1(=a1) & 0x4) != 0.
  The `beq` branch at 0xa80000002004db48 targets 0xa80000002004dc1c, is taken when a4(=0x7fffff) >= a2(=[a3+24]:8) (unsigned), and falls through when a4(=0x7fffff) < a2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa80000002004db60 targets 0xa80000002004db6c, is taken when a2(=[a3+24]:8) < a5(=0x40000000) (unsigned), and falls through when a2(=[a3+24]:8) >= a5(=0x40000000) (unsigned).
  The `beq` branch at 0xa80000002004db68 targets 0xa80000002004dc1c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa80000002004db74 targets 0xa80000002004db84, is taken when a2(=[a3+24]:8) < a6(=0x800000) (unsigned), and falls through when a2(=[a3+24]:8) >= a6(=0x800000) (unsigned).
  The `beq` branch at 0xa80000002004db7c targets 0xa80000002004db94, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xa80000002004db84 targets 0xa80000002004dce4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0xa80000002004db8c targets 0xa80000002004dce4, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xa80000002004db98 targets 0xa80000002004dc40, is taken when s3(=[a0+64]:8) != 0, and falls through when s3(=[a0+64]:8) == 0.
  The `beq` branch at 0xa80000002004dbac targets 0xa80000002004dc74, is taken when a7(?) == t0(=0xa), and falls through when a7(?) != t0(=0xa).
  The `beq` branch at 0xa80000002004dbc0 targets 0xa80000002004dc64, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xa80000002004dbc8 targets 0xa80000002004dc04, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002004dbd0 targets 0xa80000002004dc04, is taken when a0(?) == s5(=-0x1), and falls through when a0(?) != s5(=-0x1).
  The `beq` branch at 0xa80000002004dc04 targets 0xa80000002004dcbc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa80000002004dc0c targets 0xa80000002004dcbc, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xa80000002004dc14 targets 0xa80000002004dbdc and is always taken.
  The `beq` branch at 0xa80000002004dc38 targets 0xa80000002004dba4 and is always taken.
  The `beq` branch at 0xa80000002004dc54 targets 0xa80000002004dba0 and is always taken.
  The `beq` branch at 0xa80000002004dc5c targets 0xa80000002004dba8 and is always taken.
  The `bne` branch at 0xa80000002004dc64 targets 0xa80000002004dbc8, is taken when a0(?) != s5(=-0x1), and falls through when a0(?) == s5(=-0x1).
  The `beq` branch at 0xa80000002004dc6c targets 0xa80000002004dbd8 and is always taken.
  The `beq` branch at 0xa80000002004dc98 targets 0xa80000002004dcc4, is taken when (a4(=[a3+80]:2) & 0x4) == 0, and falls through when (a4(=[a3+80]:2) & 0x4) != 0.
  The `beq` branch at 0xa80000002004dcb4 targets 0xa80000002004dbb4 and is always taken.
  The `beq` branch at 0xa80000002004dcbc targets 0xa80000002004dbd8 and is always taken.
  The `beq` branch at 0xa80000002004dcd8 targets 0xa80000002004dbb4 and is always taken.
  The `beq` branch at 0xa80000002004dcf4 targets 0xa80000002004dba4 and is always taken.
  The return at 0xa80000002004dbfc has v0 = ?.
  The instructions from 0xa80000002004dce0 to 0xa80000002004dce0 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_error_devenable` in `IP30/unix` at 0xa80000002004dcfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004dcfc-0xa80000002004dd78 (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0xa80000002004dd14 loads 1 byte from ret(pciio_info_get) +0x21c.
  The `lw` at 0xa80000002004dd34 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xa80000002004dd08 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004dd1c calls pciio_info_mfast_get [0xa80000002005fe64] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004dd3c calls xtalk_error_devenable [0xa80000002003ab9c] with a0=[ret(pciio_info_mfast_get)], a1=[ret(pciio_info_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0xa80000002004dd58 calls pcibr_error_cleanup [0xa80000002004ca5c] with a0=ret(pciio_info_mfast_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `bne` branch at 0xa80000002004dd2c targets 0xa80000002004dd58, is taken when (s0(=a1) & 0x2) != 0, and falls through when (s0(=a1) & 0x2) == 0.
  The `beq` branch at 0xa80000002004dd44 targets 0xa80000002004dd58, is taken when v0(=ret(xtalk_error_devenable)) == 0, and falls through when v0(=ret(xtalk_error_devenable)) != 0.
  The `beq` branch at 0xa80000002004dd4c targets 0xa80000002004dd68 and is always taken.
  The return at 0xa80000002004dd70 has v0 = one of ret(xtalk_error_devenable), 0x0.
  The instructions from 0xa80000002004dd54 to 0xa80000002004dd54 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_func_config_addr` in `IP30/unix` at 0xa80000002004dd78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004dd78-0xa80000002004ddfc (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0xa80000002004ddac calls pcireg_type1_cntr_set [0xa800000020054c18] with a0=a0 at entry (arg0), a1=((a1 << 0x10) | (a2 << 0xb)), a2=(a2 << 0xb), a3=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `jal` at 0xa80000002004ddbc calls pcireg_type1_cfg_addr [0xa80000002005a1bc] with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0xa80000002004ddec calls pcireg_type0_cfg_addr [0xa800000020059f0c] with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=a4 at entry (arg4), a7=a1 at entry (arg1).
  The `blez` branch at 0xa80000002004dd9c targets 0xa80000002004dde4, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0xa80000002004ddf4 targets 0xa80000002004ddc8 and is always taken.
  The return at 0xa80000002004dddc has v0 = one of ret(pcireg_type1_cfg_addr), ret(pcireg_type0_cfg_addr).

- `pcibr_slot_config_addr` in `IP30/unix` at 0xa80000002004ddfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004ddfc-0xa80000002004de28 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xa80000002004de14 calls pcibr_func_config_addr [0xa80000002004dd78] with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=0x0, a4=a2 at entry (arg2).
  The return at 0xa80000002004de20 has v0 = ret(pcibr_func_config_addr).

- `pcibr_slot_config_get` in `IP30/unix` at 0xa80000002004de28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004de28-0xa80000002004de64 (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0xa80000002004de38 calls pcibr_slot_config_addr [0xa80000002004ddfc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004de48 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xa80000002004de5c has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_func_config_get` in `IP30/unix` at 0xa80000002004de64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004de64-0xa80000002004deb4 (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xa80000002004de88 calls pcibr_func_config_addr [0xa80000002004dd78] with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xa80000002004de98 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xa80000002004deac has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_slot_config_set` in `IP30/unix` at 0xa80000002004deb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004deb4-0xa80000002004defc (72 bytes).
  It occupies 72 bytes.
  The `jal` at 0xa80000002004dec8 calls pcibr_slot_config_addr [0xa80000002004ddfc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004dee4 calls do_pcibr_config_set [0xa80000002004e170] with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xa80000002004def4 has v0 = ret(do_pcibr_config_set).

- `pcibr_func_config_set` in `IP30/unix` at 0xa80000002004defc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004defc-0xa80000002004df58 (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0xa80000002004df24 calls pcibr_func_config_addr [0xa80000002004dd78] with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xa80000002004df40 calls do_pcibr_config_set [0xa80000002004e170] with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xa80000002004df50 has v0 = ret(do_pcibr_config_set).

- `pcibr_config_addr` in `IP30/unix` at 0xa80000002004df58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004df58-0xa80000002004e04c (244 bytes).
  It occupies 244 bytes.
  The `ld` at 0xa80000002004dfc0 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xa80000002004dfd0 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `lbu` at 0xa80000002004dff4 loads 1 byte from ret(pciio_info_get) +0x12.
  The `lbu` at 0xa80000002004dff8 loads 1 byte from ret(pciio_info_get) +0x11.
  The `lbu` at 0xa80000002004e000 loads 1 byte from ret(pciio_info_get) +0x10.
  The `lbu` at 0xa80000002004e010 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lbu` at 0xa80000002004e018 loads 1 byte from ret(pcibr_info_get) +0x12.
  The `jal` at 0xa80000002004df70 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004df80 calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004df8c calls pciio_info_type1_get [0xa8000000200606ec] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004dfcc calls pcibr_func_config_addr [0xa80000002004dd78] with a0=[[ret(pcibr_info_get)+40]:8+8]:8, a1=?, a2=?, a3=?, a4=0x0.
  The `jal` at 0xa80000002004dfe4 calls pciio_info_hostdev_get [0xa80000002005fe00] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004df94 targets 0xa80000002004dfe4, is taken when v0(=ret(pciio_info_type1_get)) == 0, and falls through when v0(=ret(pciio_info_type1_get)) != 0.
  The `beq` branch at 0xa80000002004dfec targets 0xa80000002004e010, is taken when v0(=ret(pciio_info_hostdev_get)) == s2(=a0), and falls through when v0(=ret(pciio_info_hostdev_get)) != s2(=a0).
  The `beq` branch at 0xa80000002004e008 targets 0xa80000002004dfb8 and is always taken.
  The `beq` branch at 0xa80000002004e014 targets 0xa80000002004e02c, is taken when a0(=0xff) == a2(=[ret(pcibr_info_get)+540]:1), and falls through when a0(=0xff) != a2(=[ret(pcibr_info_get)+540]:1).
  The `beq` branch at 0xa80000002004e01c targets 0xa80000002004e03c, is taken when a0(=0xff) == a3(=[ret(pcibr_info_get)+18]:1), and falls through when a0(=0xff) != a3(=[ret(pcibr_info_get)+18]:1).
  The `beq` branch at 0xa80000002004e024 targets 0xa80000002004dfbc and is always taken.
  The `beq` branch at 0xa80000002004e034 targets 0xa80000002004e01c and is always taken.
  The `beq` branch at 0xa80000002004e044 targets 0xa80000002004e020 and is always taken.
  The return at 0xa80000002004dfdc has v0 = ret(pcibr_func_config_addr).

- `pcibr_config_get` in `IP30/unix` at 0xa80000002004e04c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004e04c-0xa80000002004e084 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0xa80000002004e05c calls pcibr_config_addr [0xa80000002004df58] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004e06c calls do_pcibr_config_get [0xa80000002004e0e4] with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=?.
  The return at 0xa80000002004e07c has v0 = ret(do_pcibr_config_get).

- `pcibr_config_get_safe` in `IP30/unix` at 0xa80000002004e084 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004e084-0xa80000002004e0e4 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0xa80000002004e09c loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xa80000002004e0a4 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `jal` at 0xa80000002004e094 calls pcibr_info_get [0xa800000020043428] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004e0ac calls pcibr_config_addr [0xa80000002004df58] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa80000002004e0c0 calls pcibr_probe_slot [0xa8000000200501a8] with a0=?, a1=ret(pcibr_config_addr), a2=sp-48, a3=?.
  The `beq` branch at 0xa80000002004e0c8 targets 0xa80000002004e0dc, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xa80000002004e0dc targets 0xa80000002004e0d4 and is always taken.
  The return at 0xa80000002004e0d4 has v0 = one of -0x1, ?.

- `pcibr_config_set` in `IP30/unix` at 0xa80000002004e130 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004e130-0xa80000002004e170 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0xa80000002004e144 calls pcibr_config_addr [0xa80000002004df58] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004e158 calls do_pcibr_config_set [0xa80000002004e170] with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002004e168 has v0 = ret(do_pcibr_config_set).

- `pcibr_slot_info_init` in `IP30/unix` at 0xa80000002004e2a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004e2a8-0xa80000002004edd8 (2864 bytes).
  It occupies 2864 bytes.
  The `lbu` at 0xa80000002004e2e0 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0xa80000002004e2f0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xa80000002004e300 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004e38c, `lw` at 0xa80000002004e48c, `lw` at 0xa80000002004eb30.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004e394, `sw` at 0xa80000002004e4f0, `sw` at 0xa80000002004e6c4.
  6 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xa80000002004e3b8, `lh` at 0xa80000002004e59c, `lh` at 0xa80000002004e658.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa80000002004e4e4, `sd` at 0xa80000002004e6b8, `sd` at 0xa80000002004e6bc.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x74, including `lh` at 0xa80000002004e600, `lh` at 0xa80000002004e628, `lh` at 0xa80000002004eabc.
  The `sd` at 0xa80000002004e95c stores 8 bytes to ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xa80000002004e960 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x508.
  The `sw` at 0xa80000002004e968 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x508.
  The `ld` at 0xa80000002004e96c loads 8 bytes from ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xa80000002004e970 loads 4 bytes from [ret(pcibr_device_info_new)+544]:8 +0x4.
  The `lw` at 0xa80000002004e988 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x50c.
  The `lw` at 0xa80000002004e98c loads 4 bytes from table(0xa80000002043f3c0) +0x0.
  The `sw` at 0xa80000002004e994 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x50c.
  3 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x878, including `lw` at 0xa80000002004ea34, `lw` at 0xa80000002004ea60, `lw` at 0xa80000002004ed50.
  The `lbu` at 0xa80000002004ea3c loads 1 byte from ret(hwgraph_fastinfo_get) +0x28.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x878, including `sw` at 0xa80000002004ea6c, `sw` at 0xa80000002004ed5c.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xa80000002004ed7c, `ld` at 0xa80000002004edac.
  The `jal` at 0xa80000002004e2c8 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004e33c calls pcibr_is_slot_sys_critical [0xa800000020050098] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x16, a3=?.
  The `jal` at 0xa80000002004e35c calls pcibr_slot_config_addr [0xa80000002004ddfc] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xa80000002004e370 calls pcibr_probe_slot [0xa8000000200501a8] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_slot_config_addr), a2=sp-608, a3=?.
  The `jal` at 0xa80000002004e3d4 calls pcibr_debug [0xa800000020046990] with a0=0x80, a1=a0 at entry (arg0), a2=0xa8000000203b3380, a3=?.
  The `jal` at 0xa80000002004e3f0 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=ret(pcibr_slot_config_addr), a1=0xe, a2=0x1, a3=?, a5=0xffff.
  The `jal` at 0xa80000002004e46c calls pcibr_func_config_addr [0xa80000002004dd78] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xa80000002004e47c calls pcibr_probe_slot [0xa8000000200501a8] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_func_config_addr), a2=?, a3=?.
  The `jal` at 0xa80000002004e4b4 calls pcibr_slot_config_addr [0xa80000002004ddfc] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xa80000002004e4d0 calls kmem_zalloc [0xa8000000201486a4] with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa80000002004e5c0 calls pcibr_debug [0xa800000020046990] with a0=0x400, a1=a0 at entry (arg0), a2=0xa8000000203b3400, a3=?.
  The `jal` at 0xa80000002004e5dc calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=0xd, a2=0x1, a3=?.
  The `jal` at 0xa80000002004e5ec calls pcireg_device_get [0xa800000020058074] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa80000002004e618 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=0xc, a2=0x1, a3=?.
  The `jal` at 0xa80000002004e63c calls pcibr_find_capability [0xa80000002004edd8] with a0=?, a1=0x7, a2=?, a3=?.
  The `jal` at 0xa80000002004e680 calls pcibr_debug [0xa800000020046990] with a0=0x400, a1=a0 at entry (arg0), a2=0xa8000000203b3518, a3=ret(pcibr_find_capability).
  The `jal` at 0xa80000002004e6f4 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=?, a2=0x4, a3=0x0, a6=0x4.
  The `jal` at 0xa80000002004e730 calls sprintf [0xa8000000201c784c] with a0=sp-568, a1=0xa8000000203b3560, a2=?, a3=?.
  The `jal` at 0xa80000002004e748 calls pcibr_debug [0xa800000020046990] with a0=0x800, a1=a0 at entry (arg0), a2=0xa8000000203b35c8, a3=sp-568.
  The `jal` at 0xa80000002004e78c calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xa80000002004e824 calls pcibr_bus_addr_alloc [0xa80000002005060c] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=one of 0x2, 0x4, 0x5, a3=?, a5=0x0.
  The `jal` at 0xa80000002004e8b0 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=?, a2=0x4, a3=-0x1.
  The `jal` at 0xa80000002004e8c0 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xa80000002004e94c calls pcibr_device_info_new [0xa800000020043444] with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa80000002004e99c calls pciio_device_info_register [0xa800000020060214] with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?.
  The `jal` at 0xa80000002004e9b0 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xa80000002004ea58 calls pciio_device_win_populate [0xa800000020060508] with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=?.
  The `jal` at 0xa80000002004eab4 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=0x3e, a2=0x1, a3=?.
  The `jal` at 0xa80000002004eb38 calls pcibr_func_config_addr [0xa80000002004dd78] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xa80000002004eb58 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xa80000002004ebd4 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xa80000002004ebf8 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=0xc, a2=0x1, a3=0x20.
  The `jal` at 0xa80000002004ec2c calls pcibr_debug [0xa800000020046990] with a0=0x400, a1=a0 at entry (arg0), a2=0xa8000000203b3480, a3=?.
  The `jal` at 0xa80000002004ec50 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=0xd, a2=0x1, a3=?, a6=one of 0x8, 0x10, 0x18, 0x20, a7=0x5.
  The `jal` at 0xa80000002004ec88 calls pcibr_debug [0xa800000020046990] with a0=0x400, a1=a0 at entry (arg0), a2=0xa8000000203b3438, a3=?.
  The `jal` at 0xa80000002004ed48 calls pciio_device_win_populate [0xa800000020060508] with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=0x10a9.
  The `jal` at 0xa80000002004ed8c calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b33c0, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xa80000002004edb0 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b34c8, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xa80000002004edc8 calls pcibr_device_info_new [0xa800000020043444] with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1.
  The `beq` branch at 0xa80000002004e2d8 targets 0xa80000002004e310, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa80000002004e2ec targets 0xa80000002004e334, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa80000002004e304 targets 0xa80000002004e33c, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xa80000002004e334 targets 0xa80000002004e310 and is always taken.
  The `beq` branch at 0xa80000002004e344 targets 0xa80000002004e354, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xa80000002004e34c targets 0xa80000002004e310 and is always taken.
  The `beq` branch at 0xa80000002004e378 targets 0xa80000002004e38c, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xa80000002004e384 targets 0xa80000002004e310 and is always taken.
  The `beq` branch at 0xa80000002004e3b0 targets 0xa80000002004eb8c, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xa80000002004e3c0 targets 0xa80000002004ebbc, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2).
  The `beq` branch at 0xa80000002004e3e4 targets 0xa80000002004eb74, is taken when a5(=0xffff) == a6(?), and falls through when a5(=0xffff) != a6(?).
  The `beq` branch at 0xa80000002004e408 targets 0xa80000002004eb94, is taken when (a7(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) == 0, and falls through when (a7(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) != 0.
  The `beq` branch at 0xa80000002004e428 targets 0xa80000002004e44c and is always taken.
  The `beq` branch at 0xa80000002004e444 targets 0xa80000002004e4ac, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0xa80000002004e484 targets 0xa80000002004e430, is taken when v0(=ret(pcibr_probe_slot)) != 0, and falls through when v0(=ret(pcibr_probe_slot)) == 0.
  The `beq` branch at 0xa80000002004e498 targets 0xa80000002004ebac, is taken when ra(?) == at(=0xffff), and falls through when ra(?) != at(=0xffff).
  The `beq` branch at 0xa80000002004e4a4 targets 0xa80000002004e43c and is always taken.
  The `blez` branch at 0xa80000002004e4ec targets 0xa80000002004e9f8, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0xa80000002004e514 targets 0xa80000002004e540 and is always taken.
  The `bne` branch at 0xa80000002004e524 targets 0xa80000002004e6cc, is taken when a6(?) != a7(=0x3), and falls through when a6(?) == a7(=0x3).
  The `beq` branch at 0xa80000002004e538 targets 0xa80000002004e9f8, is taken when s2(?) >= t0(?) (signed), and falls through when s2(?) < t0(?) (signed).
  The `beq` branch at 0xa80000002004e540 targets 0xa80000002004e568, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa80000002004e558 targets 0xa80000002004eb14, is taken when (s3(?) & t8(?)) == 0, and falls through when (s3(?) & t8(?)) != 0.
  The `bne` branch at 0xa80000002004e560 targets 0xa80000002004e530, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0xa80000002004e570 targets 0xa80000002004ea10, is taken when (t9(?) & 0x7f) == 0, and falls through when (t9(?) & 0x7f) != 0.
  The `bne` branch at 0xa80000002004e580 targets 0xa80000002004ed78, is taken when ra(=0x1) != at(?), and falls through when ra(=0x1) == at(?).
  The `beq` branch at 0xa80000002004e594 targets 0xa80000002004ea1c, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xa80000002004e5a4 targets 0xa80000002004eb0c, is taken when a0(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a0(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xa80000002004e5d0 targets 0xa80000002004ea24, is taken when a2(?) == a3(=0x10a9), and falls through when a2(?) != a3(=0x10a9).
  The `beq` branch at 0xa80000002004e5f8 targets 0xa80000002004ea70, is taken when a4(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a4(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xa80000002004e608 targets 0xa80000002004e93c, is taken when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xa80000002004e620 targets 0xa80000002004ebf0, is taken when v0(=ret(do_pcibr_config_get)) == 0, and falls through when v0(=ret(do_pcibr_config_get)) != 0.
  The `beq` branch at 0xa80000002004e630 targets 0xa80000002004e93c, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xa80000002004e644 targets 0xa80000002004ed9c, is taken when v0(=ret(pcibr_find_capability)) == 0, and falls through when v0(=ret(pcibr_find_capability)) != 0.
  The `beq` branch at 0xa80000002004e650 targets 0xa80000002004ebc4, is taken when t0(=0xff) == s0(=a1), and falls through when t0(=0xff) != s0(=a1).
  The `beq` branch at 0xa80000002004e660 targets 0xa80000002004ebe8, is taken when t1(=[ret(hwgraph_fastinfo_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(hwgraph_fastinfo_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0xa80000002004e68c targets 0xa80000002004e52c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xa80000002004e694 targets 0xa80000002004e940 and is always taken.
  The `beq` branch at 0xa80000002004e6c0 targets 0xa80000002004e51c, is taken when a5(?) == a6(=0x10a9), and falls through when a5(?) != a6(=0x10a9).
  The `bne` branch at 0xa80000002004e6d0 targets 0xa80000002004e760, is taken when a6(=0x4) != a7(?), and falls through when a6(=0x4) == a7(?).
  The `beq` branch at 0xa80000002004e6fc targets 0xa80000002004e764 and is always taken.
  The `beq` branch at 0xa80000002004e758 targets 0xa80000002004e69c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xa80000002004e77c targets 0xa80000002004e52c, is taken when s6(?) >= a4(?) (signed), and falls through when s6(?) < a4(?) (signed).
  The `beq` branch at 0xa80000002004e7a8 targets 0xa80000002004e860, is taken when (v0(=ret(do_pcibr_config_get)) & 0x1) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x1) != 0.
  The `beq` branch at 0xa80000002004e7c0 targets 0xa80000002004e7d0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa80000002004e7d4 targets 0xa80000002004e8a4, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xa80000002004e7f0 targets 0xa80000002004e8e8, is taken when t2(=one of 0x2, 0x4) == t3(=0x4), and falls through when t2(=one of 0x2, 0x4) != t3(=0x4).
  The `beq` branch at 0xa80000002004e83c targets 0xa80000002004e750, is taken when (a5(=[0xa8000000204a7788]) & 0x800) == 0, and falls through when (a5(=[0xa8000000204a7788]) & 0x800) != 0.
  The `beq` branch at 0xa80000002004e844 targets 0xa80000002004e900, is taken when a6(=0xff) == s0(=a1), and falls through when a6(=0xff) != s0(=a1).
  The `bne` branch at 0xa80000002004e850 targets 0xa80000002004e704, is taken when a7(=[ret(hwgraph_fastinfo_get)+114]:2) != t0(=0x2), and falls through when a7(=[ret(hwgraph_fastinfo_get)+114]:2) == t0(=0x2).
  The `beq` branch at 0xa80000002004e858 targets 0xa80000002004e708 and is always taken.
  The `beq` branch at 0xa80000002004e880 targets 0xa80000002004e914, is taken when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) != 0.
  The `beq` branch at 0xa80000002004e888 targets 0xa80000002004e924, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xa80000002004e898 targets 0xa80000002004e908, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa80000002004e8e0 targets 0xa80000002004e750 and is always taken.
  The `beq` branch at 0xa80000002004e8f0 targets 0xa80000002004e7f8, is taken when v0(=0x2) == v1(?), and falls through when v0(=0x2) != v1(?).
  The `beq` branch at 0xa80000002004e8f8 targets 0xa80000002004e7f8 and is always taken.
  The `beq` branch at 0xa80000002004e900 targets 0xa80000002004e708 and is always taken.
  The `beq` branch at 0xa80000002004e90c targets 0xa80000002004ebcc, is taken when a1(=0x4) == t2(?), and falls through when a1(=0x4) != t2(?).
  The `beq` branch at 0xa80000002004e91c targets 0xa80000002004e7d0 and is always taken.
  The `beq` branch at 0xa80000002004e934 targets 0xa80000002004e8a4 and is always taken.
  The `beq` branch at 0xa80000002004e958 targets 0xa80000002004e998, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xa80000002004e9a4 targets 0xa80000002004eb80, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0xa80000002004e9bc targets 0xa80000002004e530, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0xa80000002004e9f0 targets 0xa80000002004e784 and is always taken.
  The `beq` branch at 0xa80000002004ea08 targets 0xa80000002004e310 and is always taken.
  The `beq` branch at 0xa80000002004ea14 targets 0xa80000002004e590 and is always taken.
  The `beq` branch at 0xa80000002004ea1c targets 0xa80000002004e5ac and is always taken.
  The `bne` branch at 0xa80000002004ea2c targets 0xa80000002004e5d8, is taken when ra(?) != at(=0x2), and falls through when ra(?) == at(=0x2).
  The `beq` branch at 0xa80000002004ea40 targets 0xa80000002004ed40, is taken when (v0(=[ret(hwgraph_fastinfo_get)+2168]) & 0x1) == 0, and falls through when (v0(=[ret(hwgraph_fastinfo_get)+2168]) & 0x1) != 0.
  The `bne` branch at 0xa80000002004ea4c targets 0xa80000002004e5d4, is taken when (v0(?) & 0x2) != 0, and falls through when (v0(?) & 0x2) == 0.
  The `beq` branch at 0xa80000002004ea68 targets 0xa80000002004e5d4 and is always taken.
  The `bne` branch at 0xa80000002004ea74 targets 0xa80000002004e600, is taken when (at(=0x200000) & v0(=ret(pcireg_device_get))) != 0, and falls through when (at(=0x200000) & v0(=ret(pcireg_device_get))) == 0.
  The `bne` branch at 0xa80000002004ea80 targets 0xa80000002004eab0, is taken when v0(?) != v1(=0x10a9), and falls through when v0(?) == v1(=0x10a9).
  The `beq` branch at 0xa80000002004ea90 targets 0xa80000002004e600, is taken when a0(?) == a1(=0x3), and falls through when a0(?) != a1(=0x3).
  The `beq` branch at 0xa80000002004ea9c targets 0xa80000002004e600, is taken when a2(?) == a3(=0x2), and falls through when a2(?) != a3(=0x2).
  The `beq` branch at 0xa80000002004eaa8 targets 0xa80000002004e600, is taken when a4(?) == a5(=0x5), and falls through when a4(?) != a5(=0x5).
  The `beq` branch at 0xa80000002004eac4 targets 0xa80000002004ecc8, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a6(=0x7), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a6(=0x7).
  The `beq` branch at 0xa80000002004eacc targets 0xa80000002004ecf8, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a7(=0x5), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a7(=0x5).
  The `beq` branch at 0xa80000002004ead4 targets 0xa80000002004eca8, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t0(=0x2), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t0(=0x2).
  The `beq` branch at 0xa80000002004eadc targets 0xa80000002004eca8, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t1(=0x3), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t1(=0x3).
  The `beq` branch at 0xa80000002004eae4 targets 0xa80000002004ed28, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xa80000002004eaf0 targets 0xa80000002004ec3c, is taken when t2(=(ret(do_pcibr_config_get) << 0x3)) >= 0x100 (unsigned), and falls through when t2(=(ret(do_pcibr_config_get) << 0x3)) < 0x100 (unsigned).
  The `beq` branch at 0xa80000002004eb04 targets 0xa80000002004ec44 and is always taken.
  The `beq` branch at 0xa80000002004eb0c targets 0xa80000002004e5ac and is always taken.
  The `beq` branch at 0xa80000002004eb6c targets 0xa80000002004e560 and is always taken.
  The `beq` branch at 0xa80000002004eb78 targets 0xa80000002004e310 and is always taken.
  The `beq` branch at 0xa80000002004eb84 targets 0xa80000002004e9a8 and is always taken.
  The `beq` branch at 0xa80000002004eb8c targets 0xa80000002004e3c8 and is always taken.
  The `beq` branch at 0xa80000002004eba4 targets 0xa80000002004e4c4 and is always taken.
  The `beq` branch at 0xa80000002004ebb4 targets 0xa80000002004e43c and is always taken.
  The `beq` branch at 0xa80000002004ebbc targets 0xa80000002004e3c8 and is always taken.
  The `beq` branch at 0xa80000002004ebc4 targets 0xa80000002004e668 and is always taken.
  The `beq` branch at 0xa80000002004ebe0 targets 0xa80000002004e914 and is always taken.
  The `beq` branch at 0xa80000002004ebe8 targets 0xa80000002004e668 and is always taken.
  The `beq` branch at 0xa80000002004ec04 targets 0xa80000002004ec98, is taken when a3(=0xff) == s0(=a1), and falls through when a3(=0xff) != s0(=a1).
  The `beq` branch at 0xa80000002004ec14 targets 0xa80000002004eca0, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == a5(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != a5(=0x2).
  The `beq` branch at 0xa80000002004ec34 targets 0xa80000002004e62c and is always taken.
  The `beq` branch at 0xa80000002004ec5c targets 0xa80000002004ece8, is taken when a4(=0xff) == s0(=a1), and falls through when a4(=0xff) != s0(=a1).
  The `beq` branch at 0xa80000002004ec6c targets 0xa80000002004ecf0, is taken when a5(=[ret(hwgraph_fastinfo_get)+114]:2) == a6(=0x2), and falls through when a5(=[ret(hwgraph_fastinfo_get)+114]:2) != a6(=0x2).
  The `beq` branch at 0xa80000002004ec90 targets 0xa80000002004e604 and is always taken.
  The `beq` branch at 0xa80000002004ec98 targets 0xa80000002004ec1c and is always taken.
  The `beq` branch at 0xa80000002004eca0 targets 0xa80000002004ec1c and is always taken.
  The `beq` branch at 0xa80000002004ecac targets 0xa80000002004ed60, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xa80000002004ecb8 targets 0xa80000002004ed20, is taken when a3(=(ret(do_pcibr_config_get) << 0x4)) >= 0x100 (unsigned), and falls through when a3(=(ret(do_pcibr_config_get) << 0x4)) < 0x100 (unsigned).
  The `beq` branch at 0xa80000002004ecc0 targets 0xa80000002004eafc and is always taken.
  The `beq` branch at 0xa80000002004eccc targets 0xa80000002004ed68, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xa80000002004ecd8 targets 0xa80000002004ed30, is taken when a4(=(ret(do_pcibr_config_get) << 0x5)) >= 0x100 (unsigned), and falls through when a4(=(ret(do_pcibr_config_get) << 0x5)) < 0x100 (unsigned).
  The `beq` branch at 0xa80000002004ece0 targets 0xa80000002004eafc and is always taken.
  The `beq` branch at 0xa80000002004ece8 targets 0xa80000002004ec74 and is always taken.
  The `beq` branch at 0xa80000002004ecf0 targets 0xa80000002004ec74 and is always taken.
  The `beq` branch at 0xa80000002004ecfc targets 0xa80000002004ed70, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xa80000002004ed10 targets 0xa80000002004ed38, is taken when a5(?) >= 0x100 (unsigned), and falls through when a5(?) < 0x100 (unsigned).
  The `beq` branch at 0xa80000002004ed18 targets 0xa80000002004eafc and is always taken.
  The `beq` branch at 0xa80000002004ed20 targets 0xa80000002004ec3c and is always taken.
  The `beq` branch at 0xa80000002004ed28 targets 0xa80000002004ec3c and is always taken.
  The `beq` branch at 0xa80000002004ed30 targets 0xa80000002004ec3c and is always taken.
  The `beq` branch at 0xa80000002004ed38 targets 0xa80000002004ec3c and is always taken.
  The `beq` branch at 0xa80000002004ed58 targets 0xa80000002004ea48 and is always taken.
  The `beq` branch at 0xa80000002004ed60 targets 0xa80000002004ec3c and is always taken.
  The `beq` branch at 0xa80000002004ed68 targets 0xa80000002004ec3c and is always taken.
  The `beq` branch at 0xa80000002004ed70 targets 0xa80000002004ec3c and is always taken.
  The `beq` branch at 0xa80000002004ed94 targets 0xa80000002004e58c and is always taken.
  The `beq` branch at 0xa80000002004edd0 targets 0xa80000002004e68c and is always taken.
  The return at 0xa80000002004e32c has v0 = one of 0x0, 0x1, 0x13, 0x16.

- `pcibr_find_capability` in `IP30/unix` at 0xa80000002004edd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004edd8-0xa80000002004eeb0 (216 bytes).
  It occupies 216 bytes.
  The `jal` at 0xa80000002004edf4 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=a0 at entry (arg0), a1=0x6, a2=0x2, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004ee18 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=a0 at entry (arg0), a1=0x34, a2=0x1, a3=?.
  The `jal` at 0xa80000002004ee40 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `jal` at 0xa80000002004ee68 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `beq` branch at 0xa80000002004ee08 targets 0xa80000002004eea8, is taken when (v0(=ret(do_pcibr_config_get)) & 0x10) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x10) != 0.
  The `beq` branch at 0xa80000002004ee28 targets 0xa80000002004eea0, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xa80000002004ee30 targets 0xa80000002004ee64 and is always taken.
  The `beq` branch at 0xa80000002004ee50 targets 0xa80000002004eea0, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xa80000002004ee5c targets 0xa80000002004eea0, is taken when s2(?) >= 0x31 (signed), and falls through when s2(?) < 0x31 (signed).
  The `bne` branch at 0xa80000002004ee74 targets 0xa80000002004ee38, is taken when s3(=a1) != t9(=(ret(do_pcibr_config_get) << 0x0)), and falls through when s3(=a1) == t9(=(ret(do_pcibr_config_get) << 0x0)).
  The `beq` branch at 0xa80000002004eea0 targets 0xa80000002004ee84 and is always taken.
  The `beq` branch at 0xa80000002004eea8 targets 0xa80000002004ee88 and is always taken.
  The return at 0xa80000002004ee98 has v0 = one of ?, 0x0.

- `pcibr_slot_info_free` in `IP30/unix` at 0xa80000002004eeb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004eeb0-0xa80000002004ef38 (136 bytes).
  It occupies 136 bytes.
  The `lbu` at 0xa80000002004eed0 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xa80000002004ef08 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xa80000002004ef28 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xa80000002004ef2c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `jal` at 0xa80000002004eec0 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004ef10 calls pcibr_device_info_free [0xa8000000200503d4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=0x16.
  The `jal` at 0xa80000002004ef24 calls kmem_free [0xa800000020148710] with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8, a1=([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272] << 0x3), a2=?, a3=?.
  The `beq` branch at 0xa80000002004eec8 targets 0xa80000002004eee4, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xa80000002004eedc targets 0xa80000002004eef8, is taken when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa80000002004ef30 targets 0xa80000002004eee4 and is always taken.
  The return at 0xa80000002004eef0 has v0 = one of 0x0, 0x16.

- `pcibr_slot_pcix_rbar_init` in `IP30/unix` at 0xa80000002004ef38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004ef38-0xa80000002004f2b0 (888 bytes).
  It occupies 888 bytes.
  The `lbu` at 0xa80000002004ef50 loads 1 byte from a0 (arg0 at entry) +0x39.
  The `lw` at 0xa80000002004ef8c loads 4 bytes from (a0 + (a1 << 0x7)) +0x110.
  The `ld` at 0xa80000002004ef98 loads 8 bytes from (a0 + (a1 << 0x7)) +0x118.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xa80000002004efb0, `lh` at 0xa80000002004f1cc.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xa80000002004efcc, `lw` at 0xa80000002004efdc, `lw` at 0xa80000002004f064.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x518, including `lw` at 0xa80000002004f01c, `lw` at 0xa80000002004f16c, `lw` at 0xa80000002004f1fc.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x514, including `lw` at 0xa80000002004f028, `lw` at 0xa80000002004f178, `lw` at 0xa80000002004f208.
  5 such `lw` accesses load 4 bytes from table(0xa80000002043f3c0) +0x0, including `lw` at 0xa80000002004f048, `lw` at 0xa80000002004f054, `lw` at 0xa80000002004f0dc.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004f084, `ld` at 0xa80000002004f0a4.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004f098, `lw` at 0xa80000002004f0b8, `lw` at 0xa80000002004f104.
  3 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0xa80000002004f0b0, `lhu` at 0xa80000002004f190, `lhu` at 0xa80000002004f220.
  The `lw` at 0xa80000002004f0b4 loads 4 bytes from a0 (arg0 at entry) +0x510.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0xa80000002004f164, `sh` at 0xa80000002004f1ac, `sh` at 0xa80000002004f1f4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x518, including `sw` at 0xa80000002004f180, `sw` at 0xa80000002004f210.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x514, including `sw` at 0xa80000002004f188, `sw` at 0xa80000002004f218.
  The `ld` at 0xa80000002004f2ac loads 8 bytes from [(a0 + (a1 << 0x7))+280]:8 +0x0.
  The `jal` at 0xa80000002004efd0 calls pcibr_debug [0xa800000020046990] with a0=0x40, a1=[a0+4], a2=0xa8000000203b35d0, a3=?.
  The `jal` at 0xa80000002004efe0 calls pcibr_debug [0xa800000020046990] with a0=0x40, a1=[a0+4], a2=0xa8000000203b35f8, a3=?.
  The `jal` at 0xa80000002004f050 calls sprintf [0xa8000000201c784c] with a0=sp-352, a1=0xa8000000203b3620, a2=?, a3=?, a4=entry(0xa80000002043f3c0), a5=entry(0xa80000002043f3c0), a6=[a0+1300], a7=[a0+1304].
  The `jal` at 0xa80000002004f068 calls pcibr_debug [0xa800000020046990] with a0=0x40, a1=[a0+4], a2=0xa8000000203b35c8, a3=sp-352.
  The `beq` branch at 0xa80000002004ef84 targets 0xa80000002004f280, is taken when a1 >= at(=[a0+57]:1+1) (signed), and falls through when a1 < at(=[a0+57]:1+1) (signed).
  The `blez` branch at 0xa80000002004ef90 targets 0xa80000002004f290, is taken when s6(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa80000002004ef9c targets 0xa80000002004f298, is taken when s3(=[(a0 + (a1 << 0x7))+280]:8) == 0, and falls through when s3(=[(a0 + (a1 << 0x7))+280]:8) != 0.
  The `beq` branch at 0xa80000002004efa8 targets 0xa80000002004f288, is taken when v0(=0xff) == a1, and falls through when v0(=0xff) != a1.
  The `beq` branch at 0xa80000002004efb8 targets 0xa80000002004efc4, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The `blez` branch at 0xa80000002004efe8 targets 0xa80000002004f250, is taken when s6(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa80000002004f008 targets 0xa80000002004f2a0 and is always taken.
  The `beq` branch at 0xa80000002004f07c targets 0xa80000002004f24c, is taken when s2(?) >= s6(=[(a0 + (a1 << 0x7))+272]) (signed), and falls through when s2(?) < s6(=[(a0 + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xa80000002004f090 targets 0xa80000002004f070, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002004f09c targets 0xa80000002004f070, is taken when a5(?) == s5(=-0x1), and falls through when a5(?) != s5(=-0x1).
  The `beq` branch at 0xa80000002004f0a8 targets 0xa80000002004f070, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002004f0c8 targets 0xa80000002004f1e0, is taken when a7(=[a0+1296]) >= 0x64 (signed), and falls through when a7(=[a0+1296]) < 0x64 (signed).
  The `bne` branch at 0xa80000002004f10c targets 0xa80000002004f150, is taken when a2(?) < a6(?) (signed), and falls through when a2(?) >= a6(?) (signed).
  The `beq` branch at 0xa80000002004f120 targets 0xa80000002004f14c, is taken when v0(?) >= 0x7 (signed), and falls through when v0(?) < 0x7 (signed).
  The `bne` branch at 0xa80000002004f130 targets 0xa80000002004f150, is taken when a2(?) < t0(?) (signed), and falls through when a2(?) >= t0(?) (signed).
  The `bne` branch at 0xa80000002004f144 targets 0xa80000002004f104, is taken when v0(?) < 0x7 (signed), and falls through when v0(?) >= 0x7 (signed).
  The `beq` branch at 0xa80000002004f1bc targets 0xa80000002004f070, is taken when (v0(=[0xa8000000204a7788]) & 0x40) == 0, and falls through when (v0(=[0xa8000000204a7788]) & 0x40) != 0.
  The `beq` branch at 0xa80000002004f1c4 targets 0xa80000002004f244, is taken when v1(=0xff) == s4(=a1), and falls through when v1(=0xff) != s4(=a1).
  The `bne` branch at 0xa80000002004f1d0 targets 0xa80000002004f010, is taken when a0(=[a0+114]:2) != a1(=0x2), and falls through when a0(=[a0+114]:2) == a1(=0x2).
  The `beq` branch at 0xa80000002004f1d8 targets 0xa80000002004f014 and is always taken.
  The `beq` branch at 0xa80000002004f23c targets 0xa80000002004f1b0 and is always taken.
  The `beq` branch at 0xa80000002004f244 targets 0xa80000002004f014 and is always taken.
  The `beq` branch at 0xa80000002004f280 targets 0xa80000002004f254 and is always taken.
  The `beq` branch at 0xa80000002004f288 targets 0xa80000002004efc4 and is always taken.
  The `beq` branch at 0xa80000002004f290 targets 0xa80000002004f254 and is always taken.
  The `beq` branch at 0xa80000002004f298 targets 0xa80000002004f254 and is always taken.
  The `beq` branch at 0xa80000002004f2a8 targets 0xa80000002004f088 and is always taken.
  The return at 0xa80000002004f278 has v0 = one of 0x0, 0x16.

- `pcibr_slot_addr_space_init` in `IP30/unix` at 0xa80000002004f2b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004f2b0-0xa80000002004f914 (1636 bytes).
  It occupies 1636 bytes.
  The `lbu` at 0xa80000002004f2d8 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xa80000002004f2f8 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `ld` at 0xa80000002004f300 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xa80000002004f340 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xa80000002004f368 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xa80000002004f3c4, `lh` at 0xa80000002004f508, `lh` at 0xa80000002004f5e8.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004f3f8, `lw` at 0xa80000002004f484, `lw` at 0xa80000002004f5a4.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa80000002004f400, `sd` at 0xa80000002004f408, `sd` at 0xa80000002004f62c.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004f474, `ld` at 0xa80000002004f58c, `ld` at 0xa80000002004f590.
  2 such `ld` accesses load 8 bytes from table(0xa80000002043ed98) +0x0, including `ld` at 0xa80000002004f544, `ld` at 0xa80000002004f660.
  The `jal` at 0xa80000002004f2c4 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004f3b0 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=0x0, a2=0x4, a3=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xa80000002004f3f0 calls pcibr_debug [0xa800000020046990] with a0=0x800, a1=a0 at entry (arg0), a2=0xa8000000203b37c8, a3=?, a5=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xa80000002004f418 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=0x4, a2=0x4, a3=?, a4=0x9004.
  The `jal` at 0xa80000002004f450 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xa80000002004f4a0 calls pcibr_func_config_addr [0xa80000002004dd78] with a0=?, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xa80000002004f4b8 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xa80000002004f540 calls sprintf [0xa8000000201c784c] with a0=sp-464, a1=0xa8000000203b3650, a2=?, a3=?, a5=entry(0xa80000002043ed98).
  The `jal` at 0xa80000002004f558 calls pcibr_debug [0xa800000020046990] with a0=0x800, a1=a0 at entry (arg0), a2=0xa8000000203b35c8, a3=sp-464.
  The `jal` at 0xa80000002004f60c calls pcibr_debug [0xa800000020046990] with a0=0x800, a1=a0 at entry (arg0), a2=0xa8000000203b36b8, a3=?, a6=0x4, a7=0xff.
  The `jal` at 0xa80000002004f628 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xa80000002004f69c calls sprintf [0xa8000000201c784c] with a0=sp-464, a1=0xa8000000203b3700, a2=?, a3=?, a5=entry(0xa80000002043ed98).
  The `jal` at 0xa80000002004f6b4 calls pcibr_debug [0xa800000020046990] with a0=0x800, a1=a0 at entry (arg0), a2=0xa8000000203b35c8, a3=sp-464.
  The `jal` at 0xa80000002004f6f4 calls sprintf [0xa8000000201c784c] with a0=sp-464, a1=0xa8000000203b3768, a2=?, a3=?, a6=entry(0xa80000002043ed98), a7=0xff.
  The `jal` at 0xa80000002004f70c calls pcibr_debug [0xa800000020046990] with a0=0x800, a1=a0 at entry (arg0), a2=0xa8000000203b35c8, a3=sp-464.
  The `jal` at 0xa80000002004f760 calls do_pcibr_config_set [0xa80000002004e170] with a0=?, a1=0x0, a2=0x4, a3=0xfffff000, a4=one of 0x3, 0x10a9.
  The `jal` at 0xa80000002004f770 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=0x0, a2=0x4, a3=?.
  The `jal` at 0xa80000002004f79c calls pcibr_bus_addr_alloc [0xa80000002005060c] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xa80000002004f7f8 calls pcibr_bus_addr_alloc [0xa80000002005060c] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x2, a3=0x0, a6=0x4, a7=0xff.
  The `jal` at 0xa80000002004f824 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=?, a1=?, a2=0x4, a3=0xff, a4=[0xa8000000204a7788], a6=0x4, a7=0xff.
  The `jal` at 0xa80000002004f84c calls pcibr_bus_addr_alloc [0xa80000002005060c] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xa80000002004f89c calls pcibr_bus_addr_alloc [0xa80000002005060c] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x4, a3=0x0.
  The `beq` branch at 0xa80000002004f2d0 targets 0xa80000002004f8c0, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa80000002004f2e4 targets 0xa80000002004f328, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa80000002004f304 targets 0xa80000002004f330, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xa80000002004f328 targets 0xa80000002004f314 and is always taken.
  The `blez` branch at 0xa80000002004f360 targets 0xa80000002004f8d0, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa80000002004f36c targets 0xa80000002004f8c8, is taken when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8) == 0, and falls through when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8) != 0.
  The `blez` branch at 0xa80000002004f378 targets 0xa80000002004f8dc, is taken when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa80000002004f39c targets 0xa80000002004f908 and is always taken.
  The `beq` branch at 0xa80000002004f3bc targets 0xa80000002004f3d4, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xa80000002004f3c8 targets 0xa80000002004f3d4, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xa80000002004f404 targets 0xa80000002004f7d0, is taken when a3(?) == a4(=0x9004), and falls through when a3(?) != a4(=0x9004).
  The `beq` branch at 0xa80000002004f434 targets 0xa80000002004f458, is taken when (a5(?) & a6(?)) == 0, and falls through when (a5(?) & a6(?)) != 0.
  The `beq` branch at 0xa80000002004f464 targets 0xa80000002004f870, is taken when s4(?) >= a4(?) (signed), and falls through when s4(?) < a4(?) (signed).
  The `beq` branch at 0xa80000002004f47c targets 0xa80000002004f458, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0xa80000002004f488 targets 0xa80000002004f45c, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `blez` branch at 0xa80000002004f4e0 targets 0xa80000002004f71c, is taken when t1(=one of 0x2, 0x6) <= 0 (signed), and falls through when t1(=one of 0x2, 0x6) > 0 (signed).
  The `beq` branch at 0xa80000002004f4f0 targets 0xa80000002004f8f8 and is always taken.
  The `beq` branch at 0xa80000002004f4f8 targets 0xa80000002004f564, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa80000002004f500 targets 0xa80000002004f7b8, is taken when t3(=0xff) == s3(=a1), and falls through when t3(=0xff) != s3(=a1).
  The `beq` branch at 0xa80000002004f50c targets 0xa80000002004f518, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xa80000002004f580 targets 0xa80000002004f71c, is taken when s0(?) >= a3(?) (signed), and falls through when s0(?) < a3(?) (signed).
  The `beq` branch at 0xa80000002004f5a8 targets 0xa80000002004f560, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xa80000002004f5b4 targets 0xa80000002004f4f8, is taken when a6(?) >= s1(?) (unsigned), and falls through when a6(?) < s1(?) (unsigned).
  The `beq` branch at 0xa80000002004f5d0 targets 0xa80000002004f7e8, is taken when s2(?) == s7(=0x2), and falls through when s2(?) != s7(=0x2).
  The `beq` branch at 0xa80000002004f5d8 targets 0xa80000002004f81c, is taken when s2(?) == a6(=0x4), and falls through when s2(?) != a6(=0x4).
  The `beq` branch at 0xa80000002004f5e0 targets 0xa80000002004f5f8, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xa80000002004f5ec targets 0xa80000002004f5f8, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xa80000002004f654 targets 0xa80000002004f560, is taken when (a6(=[0xa8000000204a7788]) & 0x800) == 0, and falls through when (a6(=[0xa8000000204a7788]) & 0x800) != 0.
  The `bne` branch at 0xa80000002004f65c targets 0xa80000002004f6c4, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xa80000002004f664 targets 0xa80000002004f7c0, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xa80000002004f670 targets 0xa80000002004f67c, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xa80000002004f6bc targets 0xa80000002004f564 and is always taken.
  The `beq` branch at 0xa80000002004f6c4 targets 0xa80000002004f7c8, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xa80000002004f6d0 targets 0xa80000002004f6dc, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xa80000002004f714 targets 0xa80000002004f564 and is always taken.
  The `bne` branch at 0xa80000002004f734 targets 0xa80000002004f748, is taken when a3(?) != a4(=0x10a9), and falls through when a3(?) == a4(=0x10a9).
  The `beq` branch at 0xa80000002004f744 targets 0xa80000002004f3f8, is taken when a3(?) == a4(=0x3), and falls through when a3(?) != a4(=0x3).
  The `beq` branch at 0xa80000002004f77c targets 0xa80000002004f3f8, is taken when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) != 0.
  The `bne` branch at 0xa80000002004f7a4 targets 0xa80000002004f3a4, is taken when v0(=ret(pcibr_bus_addr_alloc)) != 0, and falls through when v0(=ret(pcibr_bus_addr_alloc)) == 0.
  The `beq` branch at 0xa80000002004f7b0 targets 0xa80000002004f3f8 and is always taken.
  The `beq` branch at 0xa80000002004f7b8 targets 0xa80000002004f518 and is always taken.
  The `beq` branch at 0xa80000002004f7c0 targets 0xa80000002004f67c and is always taken.
  The `beq` branch at 0xa80000002004f7c8 targets 0xa80000002004f6dc and is always taken.
  The `bne` branch at 0xa80000002004f7d8 targets 0xa80000002004f40c, is taken when t9(?) != ra(=0x1160), and falls through when t9(?) == ra(=0x1160).
  The `beq` branch at 0xa80000002004f7e0 targets 0xa80000002004f414 and is always taken.
  The `beq` branch at 0xa80000002004f814 targets 0xa80000002004f614 and is always taken.
  The `beq` branch at 0xa80000002004f83c targets 0xa80000002004f894, is taken when s7(=0x2) == a6(?), and falls through when s7(=0x2) != a6(?).
  The `beq` branch at 0xa80000002004f868 targets 0xa80000002004f614 and is always taken.
  The `beq` branch at 0xa80000002004f88c targets 0xa80000002004f310 and is always taken.
  The `beq` branch at 0xa80000002004f8b8 targets 0xa80000002004f614 and is always taken.
  The `beq` branch at 0xa80000002004f8c0 targets 0xa80000002004f314 and is always taken.
  The `beq` branch at 0xa80000002004f8c8 targets 0xa80000002004f310 and is always taken.
  The `beq` branch at 0xa80000002004f8d4 targets 0xa80000002004f310 and is always taken.
  The `beq` branch at 0xa80000002004f8f0 targets 0xa80000002004f870 and is always taken.
  The `beq` branch at 0xa80000002004f900 targets 0xa80000002004f58c and is always taken.
  The `beq` branch at 0xa80000002004f90c targets 0xa80000002004f470 and is always taken.
  The return at 0xa80000002004f320 has v0 = one of ?, 0x16.

- `pcibr_slot_device_init` in `IP30/unix` at 0xa80000002004f914 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004f914-0xa80000002004fa08 (244 bytes).
  It occupies 244 bytes.
  The `lbu` at 0xa80000002004f93c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lh` at 0xa80000002004f974 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `sd` at 0xa80000002004f9a8 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x138.
  The `lw` at 0xa80000002004f9e0 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x78.
  The `jal` at 0xa80000002004f928 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004f96c calls pcireg_device_get [0xa800000020058074] with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa80000002004f9ac calls pcireg_device_set [0xa800000020058294] with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?, a7=0x8000000.
  The `jal` at 0xa80000002004f9cc calls pcibr_debug [0xa800000020046990] with a0=0x4000000, a1=a0 at entry (arg0), a2=0xa8000000203b3820, a3=a1 at entry (arg1), a5=0xa80000002043ef58.
  The `beq` branch at 0xa80000002004f934 targets 0xa80000002004f950, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xa80000002004f948 targets 0xa80000002004f968, is taken when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa80000002004f98c targets 0xa80000002004f9e0, is taken when v1(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when v1(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xa80000002004f9d8 targets 0xa80000002004f950 and is always taken.
  The `beq` branch at 0xa80000002004f9f8 targets 0xa80000002004f994, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `beq` branch at 0xa80000002004fa00 targets 0xa80000002004f998 and is always taken.
  The return at 0xa80000002004f960 has v0 = one of 0x0, 0x16.

- `pcibr_slot_guest_info_init` in `IP30/unix` at 0xa80000002004fa08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004fa08-0xa80000002004fb1c (276 bytes).
  It occupies 276 bytes.
  The `lbu` at 0xa80000002004fa34 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xa80000002004fa50 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  3 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100, including `lw` at 0xa80000002004fa5c, `lw` at 0xa80000002004faf8, `lw` at 0xa80000002004fb10.
  The `lbu` at 0xa80000002004fa68 loads 1 byte from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x104.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108, including `lw` at 0xa80000002004fa74, `lw` at 0xa80000002004fa8c.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7)) +0x108, including `lw` at 0xa80000002004fa84, `lw` at 0xa80000002004fa90.
  The `sd` at 0xa80000002004fae8 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xa80000002004faf4 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `sw` at 0xa80000002004fb18 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108.
  The `jal` at 0xa80000002004fa1c calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004fa80 calls hwgraph_edge_add [0xa80000002023c3c8] with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264], a1=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7))+264], a2=0xa8000000203b3848, a3=?, a4=0x0.
  The `jal` at 0xa80000002004fa94 calls hwgraph_edge_add [0xa80000002023c3c8] with a0=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7))+264], a1=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264], a2=0xa8000000203b3850, a3=?.
  The `jal` at 0xa80000002004facc calls kmem_zalloc [0xa8000000201486a4] with a0=0x8, a1=0x0, a2=?, a3=?, a4=0x16.
  The `jal` at 0xa80000002004faf0 calls pcibr_device_info_new [0xa800000020043444] with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1, a5=0x1.
  The `jal` at 0xa80000002004fb08 calls pciio_device_info_register [0xa800000020060214] with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?, a4=0x0, a6=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256].
  The `beq` branch at 0xa80000002004fa2c targets 0xa80000002004fac4, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa80000002004fa40 targets 0xa80000002004fabc, is taken when s2(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xa80000002004fa54 targets 0xa80000002004facc, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa80000002004fa60 targets 0xa80000002004faa0, is taken when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xa80000002004fabc targets 0xa80000002004faa4 and is always taken.
  The `beq` branch at 0xa80000002004fac4 targets 0xa80000002004faa4 and is always taken.
  The `beq` branch at 0xa80000002004fafc targets 0xa80000002004faa0, is taken when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xa80000002004fb14 targets 0xa80000002004fa60 and is always taken.
  The return at 0xa80000002004fab4 has v0 = one of 0x0, 0x16.

- `pcibr_slot_call_device_attach` in `IP30/unix` at 0xa80000002004fb1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004fb1c-0xa80000002004fd58 (572 bytes).
  It occupies 572 bytes.
  The `lbu` at 0xa80000002004fb4c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xa80000002004fb68 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `lw` at 0xa80000002004fb9c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `lw` at 0xa80000002004fbac loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xa80000002004fbb0 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa80000002004fc08, `sw` at 0xa80000002004fcec, `sw` at 0xa80000002004fd18.
  The `ld` at 0xa80000002004fc30 loads 8 bytes from ?.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004fc40, `lw` at 0xa80000002004fc50, `lw` at 0xa80000002004fce0.
  The `lh` at 0xa80000002004fc98 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `jal` at 0xa80000002004fb34 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004fb98 calls async_attach_get_info [0xa8000000200980fc] with a0=[ret(hwgraph_fastinfo_get)], a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004fbf8 calls pcibr_debug [0xa800000020046990] with a0=0x2000, a1=a0 at entry (arg0), a2=0xa8000000203b3888, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_attach).
  The `jal` at 0xa80000002004fc58 calls device_admin_info_get [0xa80000002013ed58] with a0=?, a1=0xa8000000203b38f0, a2=?, a3=?.
  The `jal` at 0xa80000002004fc74 calls async_attach_add_info [0xa800000020098130] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002004fc80 calls pciio_device_attach [0xa8000000200603c0] with a0=?, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xa80000002004fd28 calls vertex_to_name [0xa80000002023e0dc] with a0=?, a1=sp-384, a2=0x100, a3=?.
  The `jal` at 0xa80000002004fd3c calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b3858, a2=sp-384, a3=?.
  The `beq` branch at 0xa80000002004fb44 targets 0xa80000002004fb74, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa80000002004fb58 targets 0xa80000002004fb90, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa80000002004fb6c targets 0xa80000002004fb98, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xa80000002004fb90 targets 0xa80000002004fb78 and is always taken.
  The `blez` branch at 0xa80000002004fbc4 targets 0xa80000002004fd1c, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa80000002004fbd4 targets 0xa80000002004fd4c and is always taken.
  The `beq` branch at 0xa80000002004fc20 targets 0xa80000002004fcac, is taken when s2(?) >= a4(?) (signed), and falls through when s2(?) < a4(?) (signed).
  The `beq` branch at 0xa80000002004fc38 targets 0xa80000002004fc14, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xa80000002004fc44 targets 0xa80000002004fc18, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `bne` branch at 0xa80000002004fc60 targets 0xa80000002004fd24, is taken when v0(=ret(device_admin_info_get)) != 0, and falls through when v0(=ret(device_admin_info_get)) == 0.
  The `beq` branch at 0xa80000002004fc6c targets 0xa80000002004fc7c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa80000002004fc90 targets 0xa80000002004fbdc, is taken when a0(=0xff) == s0(=a1), and falls through when a0(=0xff) != s0(=a1).
  The `bne` branch at 0xa80000002004fc9c targets 0xa80000002004fbdc, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2).
  The `beq` branch at 0xa80000002004fca4 targets 0xa80000002004fbdc and is always taken.
  The `beq` branch at 0xa80000002004fcb0 targets 0xa80000002004fcfc, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xa80000002004fcc0 targets 0xa80000002004fcf4, is taken when s3(?) == a5(=0x13), and falls through when s3(?) != a5(=0x13).
  The `beq` branch at 0xa80000002004fcc8 targets 0xa80000002004fcf4, is taken when s3(?) == v0(=0x2a), and falls through when s3(?) != v0(=0x2a).
  The `beq` branch at 0xa80000002004fcd4 targets 0xa80000002004fcf4, is taken when s3(?) == a6(=0x1), and falls through when s3(?) != a6(=0x1).
  The `beq` branch at 0xa80000002004fcf4 targets 0xa80000002004fb74 and is always taken.
  The `beq` branch at 0xa80000002004fd14 targets 0xa80000002004fcf0 and is always taken.
  The `beq` branch at 0xa80000002004fd1c targets 0xa80000002004fcf0 and is always taken.
  The `beq` branch at 0xa80000002004fd44 targets 0xa80000002004fc18 and is always taken.
  The `beq` branch at 0xa80000002004fd50 targets 0xa80000002004fc2c and is always taken.
  The return at 0xa80000002004fb88 has v0 = one of ?, 0x16.

- `pcibr_slot_call_device_detach` in `IP30/unix` at 0xa80000002004fd58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004fd58-0xa80000002004ffb8 (608 bytes).
  It occupies 608 bytes.
  The `lbu` at 0xa80000002004fd90 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xa80000002004fdac loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `lw` at 0xa80000002004fdec loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xa80000002004fdf0 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xa80000002004fe4c stores 4 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002004fe74, `ld` at 0xa80000002004fea0, `ld` at 0xa80000002004feb8.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa80000002004fe84, `lw` at 0xa80000002004febc, `lw` at 0xa80000002004fee0.
  The `lh` at 0xa80000002004fe90 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `lw` at 0xa80000002004feac loads 4 bytes from ret(hwgraph_fastinfo_get) +0x508.
  The `sw` at 0xa80000002004feb4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x508.
  The `lw` at 0xa80000002004fecc loads 4 bytes from ret(hwgraph_fastinfo_get) +0x50c.
  The `lw` at 0xa80000002004fed4 loads 4 bytes from table(0xa80000002043f3c0) +0x0.
  The `sw` at 0xa80000002004fedc stores 4 bytes to ret(hwgraph_fastinfo_get) +0x50c.
  The `lh` at 0xa80000002004ff04 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x10c, including `lw` at 0xa80000002004ff4c, `lw` at 0xa80000002004ff88.
  2 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x10c, including `sw` at 0xa80000002004ff58, `sw` at 0xa80000002004ff9c.
  The `jal` at 0xa80000002004fd74 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004fe40 calls pcibr_debug [0xa800000020046990] with a0=0x4000, a1=a0 at entry (arg0), a2=0xa8000000203b38f8, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_detach).
  The `jal` at 0xa80000002004fee8 calls pciio_device_detach [0xa800000020060410] with a0=?, a1=a2 at entry (arg2), a2=?, a3=?, a5=-0x1.
  The `jal` at 0xa80000002004ff7c calls pcibr_device_unregister [0xa80000002004355c] with a0=?, a1=-0x1, a2=?, a3=?.
  The `beq` branch at 0xa80000002004fd88 targets 0xa80000002004fdb8, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa80000002004fd9c targets 0xa80000002004fddc, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xa80000002004fdb0 targets 0xa80000002004fde4, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xa80000002004fddc targets 0xa80000002004fdbc and is always taken.
  The `blez` branch at 0xa80000002004fe04 targets 0xa80000002004ffa0, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa80000002004fe20 targets 0xa80000002004ffa8 and is always taken.
  The `beq` branch at 0xa80000002004fe64 targets 0xa80000002004ff18, is taken when s0(?) >= a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) < a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xa80000002004fe7c targets 0xa80000002004fe54, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xa80000002004fe88 targets 0xa80000002004fe58, is taken when a4(?) == a5(=-0x1), and falls through when a4(?) != a5(=-0x1).
  The `beq` branch at 0xa80000002004fe98 targets 0xa80000002004fee0, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xa80000002004fea4 targets 0xa80000002004fee0, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xa80000002004fefc targets 0xa80000002004fe2c, is taken when a0(=0xff) == s3(=a1), and falls through when a0(=0xff) != s3(=a1).
  The `bne` branch at 0xa80000002004ff08 targets 0xa80000002004fe28, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != t9(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == t9(=0x2).
  The `beq` branch at 0xa80000002004ff10 targets 0xa80000002004fe2c and is always taken.
  The `beq` branch at 0xa80000002004ff1c targets 0xa80000002004ff64, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xa80000002004ff34 targets 0xa80000002004ff5c, is taken when s4(?) == ra(=0x13), and falls through when s4(?) != ra(=0x13).
  The `beq` branch at 0xa80000002004ff3c targets 0xa80000002004ff5c, is taken when s4(?) == v0(=0x2a), and falls through when s4(?) != v0(=0x2a).
  The `beq` branch at 0xa80000002004ff44 targets 0xa80000002004ff5c, is taken when s4(?) == at(=0x1), and falls through when s4(?) != at(=0x1).
  The `beq` branch at 0xa80000002004ff5c targets 0xa80000002004fdb8 and is always taken.
  The `beq` branch at 0xa80000002004ff74 targets 0xa80000002004ff84, is taken when a1(=-0x1) == s8(?), and falls through when a1(=-0x1) != s8(?).
  The `beq` branch at 0xa80000002004ff98 targets 0xa80000002004ff5c and is always taken.
  The `beq` branch at 0xa80000002004ffa0 targets 0xa80000002004ff5c and is always taken.
  The `beq` branch at 0xa80000002004ffb0 targets 0xa80000002004fe70 and is always taken.
  The return at 0xa80000002004fdd4 has v0 = one of ?, 0x16.

- `pcibr_slot_detach` in `IP30/unix` at 0xa80000002004ffb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002004ffb8-0xa800000020050098 (224 bytes).
  It occupies 224 bytes.
  The `sw` at 0xa800000020050030 stores 4 bytes to a4 (arg4 at entry) +0x0.
  The `lh` at 0xa80000002005003c loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `sw` at 0xa80000002005004c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x518.
  The `sw` at 0xa800000020050050 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x514.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xa80000002005005c, `lbu` at 0xa80000002005007c.
  The `lbu` at 0xa800000020050060 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0xa80000002005006c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x510.
  The `jal` at 0xa80000002004ffd8 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002004ffe8 calls pcibr_is_slot_sys_critical [0xa800000020050098] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa800000020050018 calls pcibr_slot_call_device_detach [0xa80000002004fd58] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa800000020050054 calls pcibr_pcix_rbars_calc [0xa8000000200468d4] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020050074 calls pcibr_slot_pcix_rbar_init [0xa80000002004ef38] with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002004fff0 targets 0xa800000020050014, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xa800000020050020 targets 0xa80000002005003c, is taken when v0(=ret(pcibr_slot_call_device_detach)) == 0, and falls through when v0(=ret(pcibr_slot_call_device_detach)) != 0.
  The `beq` branch at 0xa800000020050028 targets 0xa800000020050034, is taken when a0(=a4) == 0, and falls through when a0(=a4) != 0.
  The `beq` branch at 0xa800000020050034 targets 0xa80000002004fffc and is always taken.
  The `beq` branch at 0xa800000020050044 targets 0xa800000020050090, is taken when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `bne` branch at 0xa800000020050068 targets 0xa800000020050090, is taken when v1(=[ret(hwgraph_fastinfo_get)+57]:1) < s1(=[ret(hwgraph_fastinfo_get)+56]:1) (signed), and falls through when v1(=[ret(hwgraph_fastinfo_get)+57]:1) >= s1(=[ret(hwgraph_fastinfo_get)+56]:1) (signed).
  The `beq` branch at 0xa800000020050088 targets 0xa800000020050074, is taken when a0(=[ret(hwgraph_fastinfo_get)+57]:1) >= s1(?) (signed), and falls through when a0(=[ret(hwgraph_fastinfo_get)+57]:1) < s1(?) (signed).
  The `beq` branch at 0xa800000020050090 targets 0xa80000002004fffc and is always taken.
  The return at 0xa80000002005000c has v0 = one of 0x0, 0x4, 0x1a.

- `pcibr_is_slot_sys_critical` in `IP30/unix` at 0xa800000020050098 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020050098-0xa8000000200501a8 (272 bytes).
  It occupies 272 bytes.
  The `lbu` at 0xa8000000200500cc loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xa8000000200500e4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xa8000000200500ec loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xa80000002005010c loads 8 bytes from ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa800000020050118, `lw` at 0xa800000020050124.
  The `jal` at 0xa8000000200500a4 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020050130 calls vertex_to_name [0xa80000002023e0dc] with a0=?, a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0xa800000020050138 calls is_sys_critical_vertex [0xa800000020141c4c] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020050198 calls cmn_err [0xa8000000201c6b00] with a0=0x4, a1=0xa8000000203b3960, a2=sp-304, a3=?.
  The `beq` branch at 0xa8000000200500c4 targets 0xa800000020050184, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa8000000200500dc targets 0xa80000002005017c, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xa8000000200500e8 targets 0xa800000020050154, is taken when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa8000000200500f0 targets 0xa800000020050104 and is always taken.
  The `beq` branch at 0xa800000020050100 targets 0xa800000020050154, is taken when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xa800000020050110 targets 0xa8000000200500f8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa80000002005011c targets 0xa8000000200500f8, is taken when v1(?) == s4(=-0x1), and falls through when v1(?) != s4(=-0x1).
  The `bne` branch at 0xa800000020050140 targets 0xa80000002005018c, is taken when v0(=ret(is_sys_critical_vertex)) != 0, and falls through when v0(=ret(is_sys_critical_vertex)) == 0.
  The `bne` branch at 0xa80000002005014c targets 0xa800000020050108, is taken when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xa80000002005017c targets 0xa80000002005015c and is always taken.
  The `beq` branch at 0xa800000020050184 targets 0xa80000002005015c and is always taken.
  The `beq` branch at 0xa8000000200501a0 targets 0xa800000020050158 and is always taken.
  The return at 0xa800000020050174 has v0 = one of 0x0, 0x1, 0x16.

- `pcibr_probe_slot` in `IP30/unix` at 0xa8000000200501a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200501a8-0xa8000000200501c8 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xa8000000200501b4 calls (unnamed) [0xa800000020050218] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=a2 at entry (arg2).
  The return at 0xa8000000200501c0 has v0 = ret(0xa800000020050218).

- `pcibr_piomap_probe` in `IP30/unix` at 0xa8000000200501c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200501c8-0xa800000020050218 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xa8000000200501c8 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xa8000000200501f8 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xa8000000200501fc loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xa800000020050200 loads 8 bytes from [a0+64]:8 +0x8.
  The `jal` at 0xa800000020050204 calls (unnamed) [0xa800000020050218] with a0=[[a0+64]:8+8]:8, a1=(a1 + [a0+32]:8), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1, a7=a0 at entry (arg0).
  The `beq` branch at 0xa8000000200501e4 targets 0xa8000000200501f8, is taken when at(=[a0+24]:8) >= v1(=(a2 + a1)) (unsigned), and falls through when at(=[a0+24]:8) < v1(=(a2 + a1)) (unsigned).
  The `beq` branch at 0xa800000020050210 targets 0xa8000000200501ec and is always taken.
  The return at 0xa8000000200501f0 has v0 = one of -0x1, ret(0xa800000020050218).

- `pcibr_disable_mst_timeout` in `IP30/unix` at 0xa8000000200502e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200502e4-0xa800000020050308 (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xa8000000200502f8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xa8000000200502ec calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200502f4 calls (unnamed) [0xa80000002005032c] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xa800000020050300 has v0 = ret(0xa80000002005032c).

- `pcibr_enable_mst_timeout` in `IP30/unix` at 0xa800000020050308 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020050308-0xa80000002005032c (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xa80000002005031c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xa800000020050310 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020050318 calls (unnamed) [0xa800000020050380] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xa800000020050324 has v0 = ret(0xa800000020050380).

- `pcibr_device_info_free` in `IP30/unix` at 0xa8000000200503d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200503d4-0xa80000002005060c (568 bytes).
  It occupies 568 bytes.
  The `lw` at 0xa800000020050414 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xa800000020050424 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa800000020050448, `ld` at 0xa800000020050454, `ld` at 0xa8000000200504c0.
  3 such `ld` accesses load 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118, including `ld` at 0xa800000020050478, `ld` at 0xa8000000200504b8, `ld` at 0xa800000020050608.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa80000002005048c, `sd` at 0xa800000020050580, `sd` at 0xa800000020050594.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa800000020050530, `lw` at 0xa80000002005053c, `lw` at 0xa80000002005056c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa800000020050554, `sw` at 0xa800000020050588.
  The `sw` at 0xa8000000200505b8 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x144.
  The `sw` at 0xa8000000200505bc stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x148.
  The `sw` at 0xa8000000200505c0 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x14c.
  The `sd` at 0xa8000000200505c8 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x150.
  The `sw` at 0xa8000000200505cc stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x158.
  The `sw` at 0xa8000000200505d0 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x168.
  The `sw` at 0xa8000000200505d4 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x16c.
  The `sd` at 0xa8000000200505d8 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x170.
  The `sw` at 0xa8000000200505e0 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x178.
  The `sd` at 0xa8000000200505ec stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x160.
  The `jal` at 0xa8000000200503f0 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020050460 calls pcibr_bus_addr_free [0xa80000002005069c] with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xa800000020050470 calls mutex_io_spinunlock [0xa80000002022d860] with a0=ret(hwgraph_fastinfo_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xa800000020050488 calls pciio_device_info_unregister [0xa8000000200602cc] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020050490 calls pciio_device_info_free [0xa8000000200601f8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005049c calls kmem_free [0xa800000020148710] with a0=?, a1=0x228, a2=?, a3=?.
  The `jal` at 0xa8000000200504cc calls mutex_spinlock [0xa80000002022d954] with a0=ret(hwgraph_fastinfo_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200504e8 calls pcibr_func_config_addr [0xa80000002004dd78] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xa800000020050500 calls do_pcibr_config_get [0xa80000002004e0e4] with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xa800000020050518 calls do_pcibr_config_set [0xa80000002004e170] with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xa800000020050528 calls pcibr_bus_addr_free [0xa80000002005069c] with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xa80000002005042c targets 0xa8000000200505fc, is taken when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xa800000020050434 targets 0xa800000020050604 and is always taken.
  The `bne` branch at 0xa800000020050440 targets 0xa800000020050560, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0xa80000002005044c targets 0xa80000002005046c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0xa800000020050458 targets 0xa80000002005046c, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0xa8000000200504b0 targets 0xa800000020050598, is taken when s3(?) >= s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s3(?) < s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xa8000000200504c4 targets 0xa8000000200504a4, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa800000020050520 targets 0xa80000002005055c and is always taken.
  The `beq` branch at 0xa800000020050550 targets 0xa800000020050580, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa800000020050558 targets 0xa800000020050448, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xa800000020050570 targets 0xa800000020050528, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xa800000020050578 targets 0xa80000002005043c and is always taken.
  The `beq` branch at 0xa800000020050590 targets 0xa800000020050558 and is always taken.
  The `beq` branch at 0xa8000000200505fc targets 0xa80000002005059c and is always taken.
  The `beq` branch at 0xa800000020050604 targets 0xa8000000200504bc and is always taken.
  The return at 0xa8000000200505f4 has v0 = one of ?, ret(hwgraph_fastinfo_get).

- `pcibr_bus_addr_alloc` in `IP30/unix` at 0xa80000002005060c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005060c-0xa80000002005069c (144 bytes).
  It occupies 144 bytes.
  The `jal` at 0xa800000020050660 calls pciio_device_win_alloc [0xa80000002006054c] with a0=(a0 + one of 0x848, 0x858, 0x868), a1=?, a2=a3 at entry (arg3), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `beq` branch at 0xa800000020050624 targets 0xa80000002005067c, is taken when a2 == at(=0x2), and falls through when a2 != at(=0x2).
  The `beq` branch at 0xa80000002005062c targets 0xa800000020050694, is taken when a2 == t0(=0x4), and falls through when a2 != t0(=0x4).
  The `beq` branch at 0xa800000020050634 targets 0xa800000020050644, is taken when a2 == t1(=0x5), and falls through when a2 != t1(=0x5).
  The `beq` branch at 0xa80000002005063c targets 0xa800000020050670 and is always taken.
  The `bne` branch at 0xa800000020050644 targets 0xa800000020050688, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0xa800000020050680 targets 0xa80000002005064c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xa80000002005068c targets 0xa800000020050650 and is always taken.
  The `beq` branch at 0xa800000020050694 targets 0xa800000020050680 and is always taken.
  The return at 0xa800000020050674 has v0 = one of 0x0, ret(pciio_device_win_alloc).

- `pcibr_bus_addr_free` in `IP30/unix` at 0xa80000002005069c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005069c-0xa8000000200506b8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa8000000200506a4 calls pciio_device_win_free [0xa800000020060638] with a0=a0+32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa8000000200506b0 has v0 = ret(pciio_device_win_free).

- `pciio_ppb_intr_map` in `IP30/unix` at 0xa80000002005ec84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005ec84-0xa80000002005ed64 (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0xa80000002005ecac loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0xa80000002005ed00 loads 4 bytes from table(0xa80000002043f448) +0x0.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa80000002005ed2c, `ld` at 0xa80000002005ed30, `ld` at 0xa80000002005ed34.
  The `jal` at 0xa80000002005eca4 calls pciio_info_slot_get [0xa80000002005fe10] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005ed28 calls pciio_info_slot_get [0xa80000002005fe10] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002005ecb8 targets 0xa80000002005ed40, is taken when s1(=[a0+496]:8) == 0, and falls through when s1(=[a0+496]:8) != 0.
  The `beq` branch at 0xa80000002005ece0 targets 0xa80000002005ed08, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0xa80000002005ed20 targets 0xa80000002005ece0, is taken when a2(?) < 0x4 (signed), and falls through when a2(?) >= 0x4 (signed).
  The `bne` branch at 0xa80000002005ed38 targets 0xa80000002005ecc0, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0xa80000002005ed5c has v0 = one of a1, ?.

- `pciio_ppb_init` in `IP30/unix` at 0xa80000002005eec8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005eec8-0xa80000002005ef3c (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0xa80000002005eee4 calls init_sema [0xa80000002014fdd4] with a0=0xa8000000204c8770, a1=0x1, a2=0xa8000000203b5b20, a3=-0x1.
  The `jal` at 0xa80000002005eef0 calls (unnamed) [0xa80000002005ee24] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005ef0c calls (unnamed) [0xa80000002005ee24] with a0=0xff, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005ef28 calls pciio_driver_register [0xa80000002005ffd0] with a0=-0x1, a1=-0x1, a2=0xa8000000203b5b30, a3=0x0.
  The `bne` branch at 0xa80000002005ef04 targets 0xa80000002005eef0, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The return at 0xa80000002005ef34 has v0 = ret(pciio_driver_register).

- `pciio_ppb_attach` in `IP30/unix` at 0xa80000002005ef3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005ef3c-0xa80000002005f020 (228 bytes).
  It occupies 228 bytes.
  The `jal` at 0xa80000002005ef4c calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005ef58 calls pciio_info_slot_get [0xa80000002005fe10] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005ef74 calls pciio_config_get [0xa80000002005fa34] with a0=a0 at entry (arg0), a1=0xb, a2=0x1, a3=?.
  The `jal` at 0xa80000002005ef88 calls pciio_config_get [0xa80000002005fa34] with a0=a0 at entry (arg0), a1=0xa, a2=0x1, a3=?.
  The `jal` at 0xa80000002005efd8 calls (unnamed) [0xa80000002005d3fc] with a0=a0 at entry (arg0), a1=0x6, a2=?, a3=0x4.
  The `jal` at 0xa80000002005eff0 calls (unnamed) [0xa80000002005e0f4] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005f008 calls (unnamed) [0xa80000002005e6b8] with a0=ret(pciio_info_get), a1=0xa8000000203b5b40, a2=?, a3=?.
  The `jal` at 0xa80000002005f010 calls (unnamed) [0xa80000002005f020] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002005ef68 targets 0xa80000002005efd0, is taken when at(?) == v0(=0xff), and falls through when at(?) != v0(=0xff).
  The `bne` branch at 0xa80000002005efa4 targets 0xa80000002005efbc, is taken when v1(?) != a1(=0x6), and falls through when v1(?) == a1(=0x6).
  The `beq` branch at 0xa80000002005efac targets 0xa80000002005efd8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002005efb4 targets 0xa80000002005efd8, is taken when a0(?) == a3(=0x4), and falls through when a0(?) != a3(=0x4).
  The `beq` branch at 0xa80000002005efd0 targets 0xa80000002005efbc and is always taken.
  The `beq` branch at 0xa80000002005efe0 targets 0xa80000002005eff0, is taken when v0(=ret(0xa80000002005d3fc)) == 0, and falls through when v0(=ret(0xa80000002005d3fc)) != 0.
  The `beq` branch at 0xa80000002005efe8 targets 0xa80000002005efc0 and is always taken.
  The `beq` branch at 0xa80000002005effc targets 0xa80000002005f010, is taken when a0(=[0xa8000000204af7f0]) == 0, and falls through when a0(=[0xa8000000204af7f0]) != 0.
  The `beq` branch at 0xa80000002005f018 targets 0xa80000002005efbc and is always taken.
  The return at 0xa80000002005efc8 has v0 = one of 0x0, ret(0xa80000002005d3fc).

- `pciio_ppb_detach` in `IP30/unix` at 0xa80000002005f094 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f094-0xa80000002005f108 (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0xa80000002005f0a8 calls pciio_config_get [0xa80000002005fa34] with a0=a0 at entry (arg0), a1=0xb, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005f0bc calls pciio_config_get [0xa80000002005fa34] with a0=a0 at entry (arg0), a1=0xa, a2=0x1, a3=?.
  The `bne` branch at 0xa80000002005f0e0 targets 0xa80000002005f0f4, is taken when at(?) != v0(=0x6), and falls through when at(?) == v0(=0x6).
  The `beq` branch at 0xa80000002005f0e8 targets 0xa80000002005f100, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa80000002005f0f0 targets 0xa80000002005f100, is taken when a0(?) == a3(=0x4), and falls through when a0(?) != a3(=0x4).
  The `beq` branch at 0xa80000002005f100 targets 0xa80000002005f0f8 and is always taken.
  The return at 0xa80000002005f0f8 has v0 = one of 0x0, 0x1.

- `pciio_ppb_businfo_get` in `IP30/unix` at 0xa80000002005f15c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f15c-0xa80000002005f1a4 (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0xa80000002005f174 loads 8 bytes from ret(pciio_info_get) +0x1e8.
  The `sw` at 0xa80000002005f180 stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x78.
  The `sw` at 0xa80000002005f184 stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x74.
  The `sw` at 0xa80000002005f188 stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x70.
  The `sw` at 0xa80000002005f190 stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x6c.
  The `jal` at 0xa80000002005f164 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa80000002005f16c targets 0xa80000002005f19c, is taken when v0(=ret(pciio_info_get)) == 0, and falls through when v0(=ret(pciio_info_get)) != 0.
  The `beq` branch at 0xa80000002005f178 targets 0xa80000002005f19c, is taken when a2(=[ret(pciio_info_get)+488]:8) == 0, and falls through when a2(=[ret(pciio_info_get)+488]:8) != 0.
  The `beq` branch at 0xa80000002005f19c targets 0xa80000002005f194 and is always taken.
  The return at 0xa80000002005f194 has v0 = one of [ret(pciio_info_get)+488]:8+108, 0x0.

- `pciio_piomap_alloc` in `IP30/unix` at 0xa80000002005f1a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f1a4-0xa80000002005f1c0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f1ac calls pcibr_piomap_alloc [0xa80000002004437c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f1b8 has v0 = ret(pcibr_piomap_alloc).

- `pciio_piomap_free` in `IP30/unix` at 0xa80000002005f1c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f1c0-0xa80000002005f1dc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f1c8 calls pcibr_piomap_free [0xa8000000200445c4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f1d4 has v0 = ret(pcibr_piomap_free).

- `pciio_piomap_addr` in `IP30/unix` at 0xa80000002005f1dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f1dc-0xa80000002005f204 (40 bytes).
  It occupies 40 bytes.
  The `sd` at 0xa80000002005f1f4 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `jal` at 0xa80000002005f1e8 calls pcibr_piomap_addr [0xa800000020044614] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f1fc has v0 = ret(pcibr_piomap_addr).

- `pciio_piomap_done` in `IP30/unix` at 0xa80000002005f204 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f204-0xa80000002005f220 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f20c calls pcibr_piomap_done [0xa800000020044640] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f218 has v0 = ret(pcibr_piomap_done).

- `pciio_piotrans_addr` in `IP30/unix` at 0xa80000002005f220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f220-0xa80000002005f23c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f228 calls pcibr_piotrans_addr [0xa80000002004465c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f234 has v0 = ret(pcibr_piotrans_addr).

- `pciio_pio_addr` in `IP30/unix` at 0xa80000002005f23c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f23c-0xa80000002005f368 (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0xa80000002005f288 loads 8 bytes from a5 (arg5 at entry) +0x0.
  2 such `sd` accesses store 8 bytes to a5 (arg5 at entry) +0x0, including `sd` at 0xa80000002005f28c, `sd` at 0xa80000002005f2f8.
  The `jal` at 0xa80000002005f2a4 calls pciio_piotrans_addr [0xa80000002005f220] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a6 at entry (arg6).
  The `jal` at 0xa80000002005f2c8 calls pciio_piomap_addr [0xa80000002005f1dc] with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0xa80000002005f2e0 calls pciio_piomap_free [0xa80000002005f1c0] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005f344 calls pciio_piomap_alloc [0xa80000002005f1a4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a4 at entry (arg4).
  The `beq` branch at 0xa80000002005f280 targets 0xa80000002005f290, is taken when a5 == 0, and falls through when a5 != 0.
  The `bne` branch at 0xa80000002005f2ac targets 0xa80000002005f300, is taken when v0(=ret(pciio_piotrans_addr)) != 0, and falls through when v0(=ret(pciio_piotrans_addr)) == 0.
  The `beq` branch at 0xa80000002005f2b4 targets 0xa80000002005f32c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xa80000002005f2d0 targets 0xa80000002005f2f0, is taken when v0(=ret(pciio_piomap_addr)) != 0, and falls through when v0(=ret(pciio_piomap_addr)) == 0.
  The `beq` branch at 0xa80000002005f2d8 targets 0xa80000002005f2e8, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xa80000002005f2e8 targets 0xa80000002005f300 and is always taken.
  The `beq` branch at 0xa80000002005f2f0 targets 0xa80000002005f300, is taken when s3(=a5) == 0, and falls through when s3(=a5) != 0.
  The `beq` branch at 0xa80000002005f350 targets 0xa80000002005f360, is taken when v0(=ret(pciio_piomap_alloc)) == 0, and falls through when v0(=ret(pciio_piomap_alloc)) != 0.
  The `beq` branch at 0xa80000002005f358 targets 0xa80000002005f2c4 and is always taken.
  The `beq` branch at 0xa80000002005f360 targets 0xa80000002005f300 and is always taken.
  The return at 0xa80000002005f324 has v0 = one of ret(pciio_piotrans_addr), ret(pciio_piomap_addr).

- `pciio_piospace_alloc` in `IP30/unix` at 0xa80000002005f368 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f368-0xa80000002005f38c (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xa80000002005f378 calls pcibr_piospace_alloc [0xa800000020044728] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f384 has v0 = ret(pcibr_piospace_alloc).

- `pciio_piospace_free` in `IP30/unix` at 0xa80000002005f38c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f38c-0xa80000002005f3a8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f394 calls pcibr_piospace_free [0xa80000002004491c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f3a0 has v0 = ret(pcibr_piospace_free).

- `pciio_pio_flush_read` in `IP30/unix` at 0xa80000002005f3a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f3a8-0xa80000002005f3c4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f3b0 calls pcibr_pio_flush_read [0xa800000020046cac] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f3bc has v0 = ret(pcibr_pio_flush_read).

- `pciio_pio_flush_del` in `IP30/unix` at 0xa80000002005f3c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f3c4-0xa80000002005f3e0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f3cc calls pcibr_pio_flush_del [0xa800000020046d18] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f3d8 has v0 = ret(pcibr_pio_flush_del).

- `pciio_pio_flush_init` in `IP30/unix` at 0xa80000002005f3e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f3e0-0xa80000002005f3fc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f3e8 calls pcibr_pio_flush_init [0xa800000020046d20] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f3f4 has v0 = ret(pcibr_pio_flush_init).

- `pciio_dmamap_alloc` in `IP30/unix` at 0xa80000002005f3fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f3fc-0xa80000002005f418 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f404 calls pcibr_dmamap_alloc [0xa800000020044c00] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f410 has v0 = ret(pcibr_dmamap_alloc).

- `pciio_dmamap_free` in `IP30/unix` at 0xa80000002005f418 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f418-0xa80000002005f434 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f420 calls pcibr_dmamap_free [0xa80000002004507c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f42c has v0 = ret(pcibr_dmamap_free).

- `pciio_dmamap_addr` in `IP30/unix` at 0xa80000002005f434 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f434-0xa80000002005f450 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f43c calls pcibr_dmamap_addr [0xa8000000200453b8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f448 has v0 = ret(pcibr_dmamap_addr).

- `pciio_dmamap_list` in `IP30/unix` at 0xa80000002005f450 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f450-0xa80000002005f46c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f458 calls pcibr_dmamap_list [0xa8000000200455a4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f464 has v0 = ret(pcibr_dmamap_list).

- `pciio_dmamap_done` in `IP30/unix` at 0xa80000002005f46c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f46c-0xa80000002005f488 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f474 calls pcibr_dmamap_done [0xa800000020045944] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f480 has v0 = ret(pcibr_dmamap_done).

- `pciio_dmatrans_addr` in `IP30/unix` at 0xa80000002005f488 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f488-0xa80000002005f4a4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f490 calls pcibr_dmatrans_addr [0xa800000020045968] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f49c has v0 = ret(pcibr_dmatrans_addr).

- `pciio_dmatrans_list` in `IP30/unix` at 0xa80000002005f4a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f4a4-0xa80000002005f4c0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f4ac calls pcibr_dmatrans_list [0xa800000020045d14] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f4b8 has v0 = ret(pcibr_dmatrans_list).

- `pciio_dma_addr` in `IP30/unix` at 0xa80000002005f4c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f4c0-0xa80000002005f5dc (284 bytes).
  It occupies 284 bytes.
  The `ld` at 0xa80000002005f500 loads 8 bytes from a4 (arg4 at entry) +0x0.
  2 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0xa80000002005f508, `sd` at 0xa80000002005f58c.
  The `jal` at 0xa80000002005f524 calls pciio_dmatrans_addr [0xa80000002005f488] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a5 at entry (arg5).
  The `jal` at 0xa80000002005f574 calls pciio_dmamap_addr [0xa80000002005f434] with a0=?, a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xa80000002005f5a4 calls pciio_dmamap_free [0xa80000002005f418] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005f5bc calls pciio_dmamap_alloc [0xa80000002005f3fc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a5 at entry (arg5).
  The `beq` branch at 0xa80000002005f4f8 targets 0xa80000002005f50c, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xa80000002005f504 targets 0xa80000002005f510 and is always taken.
  The `beq` branch at 0xa80000002005f52c targets 0xa80000002005f560, is taken when v0(=ret(pciio_dmatrans_addr)) == 0, and falls through when v0(=ret(pciio_dmatrans_addr)) != 0.
  The `beq` branch at 0xa80000002005f560 targets 0xa80000002005f5b4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa80000002005f57c targets 0xa80000002005f59c, is taken when v0(=ret(pciio_dmamap_addr)) == 0, and falls through when v0(=ret(pciio_dmamap_addr)) != 0.
  The `beq` branch at 0xa80000002005f584 targets 0xa80000002005f594, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0xa80000002005f594 targets 0xa80000002005f538 and is always taken.
  The `beq` branch at 0xa80000002005f59c targets 0xa80000002005f5ac, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xa80000002005f5ac targets 0xa80000002005f534 and is always taken.
  The `beq` branch at 0xa80000002005f5c4 targets 0xa80000002005f5d4, is taken when v0(=ret(pciio_dmamap_alloc)) == 0, and falls through when v0(=ret(pciio_dmamap_alloc)) != 0.
  The `beq` branch at 0xa80000002005f5cc targets 0xa80000002005f56c and is always taken.
  The `beq` branch at 0xa80000002005f5d4 targets 0xa80000002005f534 and is always taken.
  The return at 0xa80000002005f558 has v0 = one of ?, ret(pciio_dmamap_addr).

- `pciio_dmamap_drain` in `IP30/unix` at 0xa80000002005f5dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f5dc-0xa80000002005f5f8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f5e4 calls pcibr_dmamap_drain [0xa8000000200460dc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f5f0 has v0 = ret(pcibr_dmamap_drain).

- `pciio_dmaaddr_drain` in `IP30/unix` at 0xa80000002005f5f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f5f8-0xa80000002005f614 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f600 calls pcibr_dmaaddr_drain [0xa8000000200460f8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f60c has v0 = ret(pcibr_dmaaddr_drain).

- `pciio_dmalist_drain` in `IP30/unix` at 0xa80000002005f614 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f614-0xa80000002005f630 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f61c calls pcibr_dmalist_drain [0xa800000020046138] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f628 has v0 = ret(pcibr_dmalist_drain).

- `pciio_intr_alloc` in `IP30/unix` at 0xa80000002005f630 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f630-0xa80000002005f698 (104 bytes).
  It occupies 104 bytes.
  The `lw` at 0xa80000002005f654 loads 4 bytes from ret(pciio_info_get) +0xc.
  The `lw` at 0xa80000002005f658 loads 4 bytes from ret(pciio_info_get) +0x8.
  The `jal` at 0xa80000002005f64c calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005f664 calls pciio_ppb_intr_map [0xa80000002005ec84] with a0=ret(pciio_info_get), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xa80000002005f67c calls pcibr_intr_alloc [0xa800000020049f14] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `beq` branch at 0xa80000002005f65c targets 0xa80000002005f670, is taken when at(=[ret(pciio_info_get)+8]) == v1(=[ret(pciio_info_get)+12]), and falls through when at(=[ret(pciio_info_get)+8]) != v1(=[ret(pciio_info_get)+12]).
  The return at 0xa80000002005f690 has v0 = ret(pcibr_intr_alloc).

- `pciio_intr_free` in `IP30/unix` at 0xa80000002005f698 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f698-0xa80000002005f6b4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f6a0 calls pcibr_intr_free [0xa80000002004a584] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f6ac has v0 = ret(pcibr_intr_free).

- `pciio_intr_setmustrun` in `IP30/unix` at 0xa80000002005f6b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f6b4-0xa80000002005f6d0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f6bc calls pcibr_intr_setmustrun [0xa80000002004a540] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f6c8 has v0 = ret(pcibr_intr_setmustrun).

- `pciio_intr_connect` in `IP30/unix` at 0xa80000002005f6d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f6d0-0xa80000002005f6ec (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f6d8 calls pcibr_intr_connect [0xa80000002004a824] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f6e4 has v0 = ret(pcibr_intr_connect).

- `pciio_intr_disconnect` in `IP30/unix` at 0xa80000002005f6ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f6ec-0xa80000002005f708 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f6f4 calls pcibr_intr_disconnect [0xa80000002004a9c8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f700 has v0 = ret(pcibr_intr_disconnect).

- `pciio_intr_cpu_get` in `IP30/unix` at 0xa80000002005f708 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f708-0xa80000002005f724 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f710 calls pcibr_intr_cpu_get [0xa80000002004aba4] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f71c has v0 = ret(pcibr_intr_cpu_get).

- `pciio_slot_func_to_name` in `IP30/unix` at 0xa80000002005f724 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f724-0xa80000002005f788 (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0xa80000002005f74c calls sprintf [0xa8000000201c784c] with a0=a0 at entry (arg0), a1=0xa8000000203b5b70, a2=a1 at entry (arg1), a3=a2+97, a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `jal` at 0xa80000002005f768 calls sprintf [0xa8000000201c784c] with a0=a0 at entry (arg0), a1=0xa8000000203b5b68, a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `jal` at 0xa80000002005f778 calls sprintf [0xa8000000201c784c] with a0=a0 at entry (arg0), a1=0xa8000000203b5b60, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0xff, a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `beq` branch at 0xa80000002005f734 targets 0xa80000002005f778, is taken when a4(=0xff) == a1, and falls through when a4(=0xff) != a1.
  The `beq` branch at 0xa80000002005f73c targets 0xa80000002005f760, is taken when a4(=0xff) == a2, and falls through when a4(=0xff) != a2.
  The `beq` branch at 0xa80000002005f770 targets 0xa80000002005f758 and is always taken.
  The `beq` branch at 0xa80000002005f780 targets 0xa80000002005f758 and is always taken.
  The return at 0xa80000002005f758 has v0 = ret(sprintf).

- `pciio_error_handler` in `IP30/unix` at 0xa80000002005f828 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f828-0xa80000002005f9a8 (384 bytes).
  It occupies 384 bytes.
  4 such `ld` accesses load 8 bytes from ret(pciio_cardinfo_get) +0x38, including `ld` at 0xa80000002005f868, `ld` at 0xa80000002005f8bc, `ld` at 0xa80000002005f914.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xa80000002005f874, `lw` at 0xa80000002005f8b0.
  2 such `ld` accesses load 8 bytes from ret(pciio_cardinfo_get) +0x40, including `ld` at 0xa80000002005f8d0, `ld` at 0xa80000002005f93c.
  The `lh` at 0xa80000002005f8e8 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `ld` at 0xa80000002005f978 loads 8 bytes from a3 (arg3 at entry) +0x28.
  The `jal` at 0xa80000002005f854 calls pciio_cardinfo_get [0xa80000002005f788] with a0=a0 at entry (arg0), a1=0xff, a2=0xff, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005f8b4 calls pciio_info_dev_get [0xa80000002005fdf8] with a0=ret(pciio_cardinfo_get), a1=?, a2=?, a3=?.
  The `jalr` at 0xa80000002005f8cc calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+64]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005f900 calls pciio_cardinfo_get [0xa80000002005f788] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005f920 calls pciio_info_dev_get [0xa80000002005fdf8] with a0=ret(pciio_cardinfo_get), a1=?, a2=[ret(pciio_cardinfo_get)+56]:8, a3=?.
  The `jalr` at 0xa80000002005f938 calls (unknown callee) with a0=[ret(pciio_cardinfo_get)+64]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[ret(pciio_cardinfo_get)+56]:8.
  The `jal` at 0xa80000002005f954 calls pciio_info_dev_get [0xa80000002005fdf8] with a0=ret(pciio_cardinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005f968 calls hwgraph_traverse [0xa80000002023cd3c] with a0=ret(pciio_info_dev_get), a1=0xa8000000203b5b78, a2=sp-64, a3=?.
  The `jal` at 0xa80000002005f980 calls usrpci_error_handler [0xa80000002005cef4] with a0=?, a1=a1 at entry (arg1), a2=[a3+40]:8, a3=?.
  The `jal` at 0xa80000002005f98c calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002005f85c targets 0xa80000002005f8a8, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `bne` branch at 0xa80000002005f86c targets 0xa80000002005f8b4, is taken when at(=[ret(pciio_cardinfo_get)+56]:8) != 0, and falls through when at(=[ret(pciio_cardinfo_get)+56]:8) == 0.
  The `bltz` branch at 0xa80000002005f87c targets 0xa80000002005f8e8, is taken when v0(=([a3] << 0x2)) < 0 (signed), and falls through when v0(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0xa80000002005f8ac targets 0xa80000002005f878 and is always taken.
  The `beq` branch at 0xa80000002005f8d8 targets 0xa80000002005f874, is taken when v0(=ret(?)) == a0(=0x9), and falls through when v0(=ret(?)) != a0(=0x9).
  The `beq` branch at 0xa80000002005f8e0 targets 0xa80000002005f890 and is always taken.
  The `beq` branch at 0xa80000002005f90c targets 0xa80000002005f880, is taken when v0(=ret(pciio_cardinfo_get)) == 0, and falls through when v0(=ret(pciio_cardinfo_get)) != 0.
  The `beq` branch at 0xa80000002005f918 targets 0xa80000002005f954, is taken when a2(=[ret(pciio_cardinfo_get)+56]:8) == 0, and falls through when a2(=[ret(pciio_cardinfo_get)+56]:8) != 0.
  The `beq` branch at 0xa80000002005f944 targets 0xa80000002005f954, is taken when v0(=ret(?)) == a5(=0x9), and falls through when v0(=ret(?)) != a5(=0x9).
  The `beq` branch at 0xa80000002005f94c targets 0xa80000002005f890 and is always taken.
  The `bne` branch at 0xa80000002005f970 targets 0xa80000002005f880, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beq` branch at 0xa80000002005f998 targets 0xa80000002005f884, is taken when s0(=ret(usrpci_error_handler)) == a0(=0x9), and falls through when s0(=ret(usrpci_error_handler)) != a0(=0x9).
  The `beq` branch at 0xa80000002005f9a0 targets 0xa80000002005f88c and is always taken.
  The return at 0xa80000002005f8a0 has v0 = one of ?, ret(?).

- `pciio_error_devenable` in `IP30/unix` at 0xa80000002005f9a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f9a8-0xa80000002005f9c4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f9b0 calls pcibr_error_devenable [0xa80000002004dcfc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f9bc has v0 = ret(pcibr_error_devenable).

- `pciio_provider_startup` in `IP30/unix` at 0xa80000002005f9c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f9c4-0xa80000002005f9e0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f9cc calls pcibr_provider_startup [0xa800000020046178] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f9d8 has v0 = ret(pcibr_provider_startup).

- `pciio_provider_shutdown` in `IP30/unix` at 0xa80000002005f9e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f9e0-0xa80000002005f9fc (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005f9e8 calls pcibr_provider_shutdown [0xa800000020046180] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005f9f4 has v0 = ret(pcibr_provider_shutdown).

- `pciio_endian_set` in `IP30/unix` at 0xa80000002005f9fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005f9fc-0xa80000002005fa18 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005fa04 calls pcibr_endian_set [0xa800000020046444] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005fa10 has v0 = ret(pcibr_endian_set).

- `pciio_priority_set` in `IP30/unix` at 0xa80000002005fa18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fa18-0xa80000002005fa34 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005fa20 calls pcibr_priority_set [0xa800000020046688] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005fa2c has v0 = ret(pcibr_priority_set).

- `pciio_config_get` in `IP30/unix` at 0xa80000002005fa34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fa34-0xa80000002005faec (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0xa80000002005fa94 calls pcibr_config_get [0xa80000002004e04c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002005fa6c targets 0xa80000002005fac0, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002005fab8 targets 0xa80000002005fa7c, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0xa80000002005fae4 has v0 = one of 0x0, ?.

- `pciio_config_get_safe` in `IP30/unix` at 0xa80000002005faec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005faec-0xa80000002005fba4 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0xa80000002005fb4c calls pcibr_config_get_safe [0xa80000002004e084] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002005fb24 targets 0xa80000002005fb78, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002005fb70 targets 0xa80000002005fb34, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0xa80000002005fb9c has v0 = one of 0x0, ?.

- `pciio_config_set` in `IP30/unix` at 0xa80000002005fba4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fba4-0xa80000002005fc3c (152 bytes).
  It occupies 152 bytes.
  The `jal` at 0xa80000002005fbfc calls pcibr_config_set [0xa80000002004e130] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002005fbd8 targets 0xa80000002005fc18, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa80000002005fc10 targets 0xa80000002005fbe0, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The return at 0xa80000002005fc34 has v0 = one of ?, ret(pcibr_config_set).

- `pciio_error_extract` in `IP30/unix` at 0xa80000002005fc3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fc3c-0xa80000002005fc58 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005fc44 calls pcibr_error_extract [0xa80000002004cab0] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005fc50 has v0 = ret(pcibr_error_extract).

- `pciio_reset` in `IP30/unix` at 0xa80000002005fc58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fc58-0xa80000002005fc74 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005fc60 calls pcibr_reset [0xa800000020046188] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005fc6c has v0 = ret(pcibr_reset).

- `pciio_write_gather_flush` in `IP30/unix` at 0xa80000002005fc74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fc74-0xa80000002005fc90 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002005fc7c calls pcibr_write_gather_flush [0xa800000020043a70] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002005fc88 has v0 = ret(pcibr_write_gather_flush).

- `pciio_intr_dev_get` in `IP30/unix` at 0xa80000002005fc90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fc90-0xa80000002005fc98 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fc94 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xa80000002005fc90 has v0 = [a0+4].

- `pciio_pio_dev_get` in `IP30/unix` at 0xa80000002005fc98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fc98-0xa80000002005fca0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fc9c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xa80000002005fc98 has v0 = [a0+4].

- `pciio_pio_slot_get` in `IP30/unix` at 0xa80000002005fca0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fca0-0xa80000002005fca8 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002005fca4 loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xa80000002005fca0 has v0 = [a0+8]:1.

- `pciio_pio_space_get` in `IP30/unix` at 0xa80000002005fca8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fca8-0xa80000002005fcb0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fcac loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xa80000002005fca8 has v0 = [a0+12].

- `pciio_pio_pciaddr_get` in `IP30/unix` at 0xa80000002005fcb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fcb0-0xa80000002005fcb8 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fcb4 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0xa80000002005fcb0 has v0 = [a0+16]:8.

- `pciio_pio_mapsz_get` in `IP30/unix` at 0xa80000002005fcb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fcb8-0xa80000002005fcc0 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fcbc loads 8 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xa80000002005fcb8 has v0 = [a0+24]:8.

- `pciio_pio_kvaddr_get` in `IP30/unix` at 0xa80000002005fcc0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fcc0-0xa80000002005fcc8 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fcc4 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The return at 0xa80000002005fcc0 has v0 = [a0+32]:8.

- `pciio_dma_dev_get` in `IP30/unix` at 0xa80000002005fcc8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fcc8-0xa80000002005fcd0 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fccc loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xa80000002005fcc8 has v0 = [a0+4].

- `pciio_dma_slot_get` in `IP30/unix` at 0xa80000002005fcd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fcd0-0xa80000002005fcd8 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002005fcd4 loads 1 byte from a0 (arg0 at entry) +0x8.
  The return at 0xa80000002005fcd0 has v0 = [a0+8]:1.

- `pciio_info_chk` in `IP30/unix` at 0xa80000002005fcd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fcd8-0xa80000002005fd04 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xa80000002005fcec calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=a0 at entry (arg0), a1=0xa8000000203b5b80, a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xa80000002005fcfc has v0 = ?.

- `pciio_info_get` in `IP30/unix` at 0xa80000002005fd04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fd04-0xa80000002005fd5c (88 bytes).
  It occupies 88 bytes.
  The `ld` at 0xa80000002005fd20 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `jal` at 0xa80000002005fd10 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005fd4c calls cmn_err [0xa8000000201c6b00] with a0=0x0, a1=0xa8000000203b5b88, a2=a0 at entry (arg0), a3=?.
  The `beq` branch at 0xa80000002005fd18 targets 0xa80000002005fd2c, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xa80000002005fd28 targets 0xa80000002005fd40, is taken when at(=[ret(hwgraph_fastinfo_get)]:8) != v0(=0xa80000002043f488), and falls through when at(=[ret(hwgraph_fastinfo_get)]:8) == v0(=0xa80000002043f488).
  The `beq` branch at 0xa80000002005fd54 targets 0xa80000002005fd30 and is always taken.
  The return at 0xa80000002005fd38 has v0 = ret(hwgraph_fastinfo_get).

- `pciio_hostinfo_get` in `IP30/unix` at 0xa80000002005fd5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fd5c-0xa80000002005fda0 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xa80000002005fd74 loads 4 bytes from ret(pciio_info_get) +0xc.
  The `lw` at 0xa80000002005fd78 loads 4 bytes from ret(pciio_info_get) +0x8.
  The `jal` at 0xa80000002005fd64 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005fd90 calls pciio_info_get [0xa80000002005fd04] with a0=[ret(pciio_info_get)+12], a1=?, a2=?, a3=ret(pciio_info_get).
  The `beq` branch at 0xa80000002005fd6c targets 0xa80000002005fd80, is taken when v0(=ret(pciio_info_get)) == 0, and falls through when v0(=ret(pciio_info_get)) != 0.
  The `bne` branch at 0xa80000002005fd7c targets 0xa80000002005fd90, is taken when at(=[ret(pciio_info_get)+8]) != a0(=[ret(pciio_info_get)+12]), and falls through when at(=[ret(pciio_info_get)+8]) == a0(=[ret(pciio_info_get)+12]).
  The `beq` branch at 0xa80000002005fd98 targets 0xa80000002005fd80 and is always taken.
  The return at 0xa80000002005fd88 has v0 = ret(pciio_info_get).

- `pciio_info_set` in `IP30/unix` at 0xa80000002005fda0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fda0-0xa80000002005fdf8 (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0xa80000002005fdc0 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0xa80000002005fdc8 calls hwgraph_fastinfo_set [0xa80000002023d608] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0xa80000002043f488, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005fddc calls hwgraph_info_add_LBL [0xa80000002023c80c] with a0=a0 at entry (arg0), a1=0xa8000000203b5b80, a2=a1 at entry (arg1), a3=?.
  The `beq` branch at 0xa80000002005fdb8 targets 0xa80000002005fdc4, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0xa80000002005fdf0 has v0 = ret(hwgraph_info_add_LBL).

- `pciio_info_dev_get` in `IP30/unix` at 0xa80000002005fdf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fdf8-0xa80000002005fe00 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fdfc loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xa80000002005fdf8 has v0 = [a0+8].

- `pciio_info_hostdev_get` in `IP30/unix` at 0xa80000002005fe00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe00-0xa80000002005fe08 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fe04 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xa80000002005fe00 has v0 = [a0+12].

- `pciio_info_bus_get` in `IP30/unix` at 0xa80000002005fe08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe08-0xa80000002005fe10 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002005fe0c loads 1 byte from a0 (arg0 at entry) +0x10.
  The return at 0xa80000002005fe08 has v0 = [a0+16]:1.

- `pciio_info_slot_get` in `IP30/unix` at 0xa80000002005fe10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe10-0xa80000002005fe18 (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002005fe14 loads 1 byte from a0 (arg0 at entry) +0x11.
  The return at 0xa80000002005fe10 has v0 = [a0+17]:1.

- `pciio_info_hostslot_get` in `IP30/unix` at 0xa80000002005fe18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe18-0xa80000002005fe44 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xa80000002005fe20 calls pciio_info_hostdev_get [0xa80000002005fe00] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005fe28 calls pciio_info_get [0xa80000002005fd04] with a0=ret(pciio_info_hostdev_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa80000002005fe30 calls pciio_info_slot_get [0xa80000002005fe10] with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The return at 0xa80000002005fe3c has v0 = ret(pciio_info_slot_get).

- `pciio_info_function_get` in `IP30/unix` at 0xa80000002005fe44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe44-0xa80000002005fe4c (8 bytes).
  It occupies 8 bytes.
  The `lbu` at 0xa80000002005fe48 loads 1 byte from a0 (arg0 at entry) +0x12.
  The return at 0xa80000002005fe44 has v0 = [a0+18]:1.

- `pciio_info_vendor_id_get` in `IP30/unix` at 0xa80000002005fe4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe4c-0xa80000002005fe54 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fe50 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The return at 0xa80000002005fe4c has v0 = [a0+20].

- `pciio_info_device_id_get` in `IP30/unix` at 0xa80000002005fe54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe54-0xa80000002005fe5c (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fe58 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The return at 0xa80000002005fe54 has v0 = [a0+24].

- `pciio_info_master_get` in `IP30/unix` at 0xa80000002005fe5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe5c-0xa80000002005fe64 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fe60 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The return at 0xa80000002005fe5c has v0 = [a0+28].

- `pciio_info_mfast_get` in `IP30/unix` at 0xa80000002005fe64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe64-0xa80000002005fe6c (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fe68 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The return at 0xa80000002005fe64 has v0 = [a0+40]:8.

- `pciio_info_pops_get` in `IP30/unix` at 0xa80000002005fe6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe6c-0xa80000002005fe74 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fe70 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The return at 0xa80000002005fe6c has v0 = [a0+48]:8.

- `pciio_info_efunc_get` in `IP30/unix` at 0xa80000002005fe74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe74-0xa80000002005fe7c (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fe78 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The return at 0xa80000002005fe74 has v0 = [a0+56]:8.

- `pciio_info_einfo_get` in `IP30/unix` at 0xa80000002005fe7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe7c-0xa80000002005fe84 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fe80 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The return at 0xa80000002005fe7c has v0 = [a0+64]:8.

- `pciio_info_bar_space_get` in `IP30/unix` at 0xa80000002005fe84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe84-0xa80000002005fe9c (24 bytes).
  It occupies 24 bytes.
  The `lw` at 0xa80000002005fe98 loads 4 bytes from ?.
  The return at 0xa80000002005fe94 has v0 = ?.

- `pciio_info_bar_base_get` in `IP30/unix` at 0xa80000002005fe9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fe9c-0xa80000002005feb4 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0xa80000002005feb0 loads 8 bytes from ?.
  The return at 0xa80000002005feac has v0 = ?.

- `pciio_info_bar_size_get` in `IP30/unix` at 0xa80000002005feb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005feb4-0xa80000002005fecc (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0xa80000002005fec8 loads 8 bytes from ?.
  The return at 0xa80000002005fec4 has v0 = ?.

- `pciio_info_rom_base_get` in `IP30/unix` at 0xa80000002005fecc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fecc-0xa80000002005fed4 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fed0 loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  The return at 0xa80000002005fecc has v0 = [a0+416]:8.

- `pciio_info_rom_size_get` in `IP30/unix` at 0xa80000002005fed4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fed4-0xa80000002005fedc (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0xa80000002005fed8 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The return at 0xa80000002005fed4 has v0 = [a0+424]:8.

- `pciio_businfo_multi_master_get` in `IP30/unix` at 0xa80000002005fedc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fedc-0xa80000002005fee4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fee0 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The return at 0xa80000002005fedc has v0 = [a0].

- `pciio_businfo_asic_type_get` in `IP30/unix` at 0xa80000002005fee4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fee4-0xa80000002005feec (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fee8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xa80000002005fee4 has v0 = [a0+4].

- `pciio_businfo_bus_type_get` in `IP30/unix` at 0xa80000002005feec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005feec-0xa80000002005fef4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fef0 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The return at 0xa80000002005feec has v0 = [a0+8].

- `pciio_businfo_bus_speed_get` in `IP30/unix` at 0xa80000002005fef4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fef4-0xa80000002005fefc (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa80000002005fef8 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The return at 0xa80000002005fef4 has v0 = [a0+12].

- `pciio_init` in `IP30/unix` at 0xa80000002005fefc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005fefc-0xa80000002005ff54 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0xa80000002005ff18 calls cdl_new [0xa800000020096f58] with a0=0xa8000000203b5ba8, a1=0xa8000000203b5bb0, a2=0xa8000000203b5bb8, a3=a3 at entry (arg3).
  The `jal` at 0xa80000002005ff2c calls compare_and_swap_int64 [0xa800000020016e8c] with a0=0xa8000000204a77e8, a1=0x0, a2=ret(cdl_new), a3=?.
  The `jal` at 0xa80000002005ff44 calls cdl_del [0xa800000020096fc4] with a0=ret(cdl_new), a1=?, a2=?, a3=?.
  The `bne` branch at 0xa80000002005ff04 targets 0xa80000002005ff38, is taken when at(=[0xa8000000204a77e8]:8) != 0, and falls through when at(=[0xa8000000204a77e8]:8) == 0.
  The `beq` branch at 0xa80000002005ff34 targets 0xa80000002005ff44, is taken when v0(=ret(compare_and_swap_int64)) == 0, and falls through when v0(=ret(compare_and_swap_int64)) != 0.
  The `beq` branch at 0xa80000002005ff4c targets 0xa80000002005ff3c and is always taken.
  The return at 0xa80000002005ff3c has v0 = one of ret(compare_and_swap_int64), ?, ret(cdl_del).

- `pciio_attach` in `IP30/unix` at 0xa80000002005ff54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005ff54-0xa80000002005ff5c (8 bytes).
  It occupies 8 bytes.
  The return at 0xa80000002005ff54 has v0 = 0x0.

- `pciio_provider_register` in `IP30/unix` at 0xa80000002005ff5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005ff5c-0xa80000002005ff80 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xa80000002005ff6c calls hwgraph_info_add_LBL [0xa80000002023c80c] with a0=a0 at entry (arg0), a1=0xa8000000203b5bc0, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0xa80000002005ff78 has v0 = ret(hwgraph_info_add_LBL).

- `pciio_provider_unregister` in `IP30/unix` at 0xa80000002005ff80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005ff80-0xa80000002005ffa4 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xa80000002005ff90 calls hwgraph_info_remove_LBL [0xa80000002023c840] with a0=a0 at entry (arg0), a1=0xa8000000203b5bc0, a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xa80000002005ff9c has v0 = ret(hwgraph_info_remove_LBL).

- `pciio_provider_fns_get` in `IP30/unix` at 0xa80000002005ffa4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005ffa4-0xa80000002005ffd0 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xa80000002005ffb8 calls hwgraph_info_get_LBL [0xa80000002023c8b0] with a0=a0 at entry (arg0), a1=0xa8000000203b5bc0, a2=sp-16, a3=a3 at entry (arg3).
  The return at 0xa80000002005ffc8 has v0 = ?.

- `pciio_driver_register` in `IP30/unix` at 0xa80000002005ffd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002005ffd0-0xa800000020060044 (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0xa800000020060010 calls cdl_add_driver [0xa80000002009706c] with a0=[0xa8000000204a77e8]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=0xa800000020060068, a7=a1 at entry (arg1).
  The `jal` at 0xa800000020060028 calls pciio_init [0xa80000002005fefc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `beq` branch at 0xa80000002005fff8 targets 0xa800000020060028, is taken when t1(=[0xa8000000204a77e8]:8) == 0, and falls through when t1(=[0xa8000000204a77e8]:8) != 0.
  The `beq` branch at 0xa80000002006003c targets 0xa800000020060000 and is always taken.
  The return at 0xa800000020060020 has v0 = ret(cdl_add_driver).

- `pciio_driver_unregister` in `IP30/unix` at 0xa800000020060044 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060044-0xa800000020060068 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0xa800000020060054 calls cdl_del_driver [0xa8000000200973b0] with a0=[0xa8000000204a77e8]:8, a1=a0 at entry (arg0), a2=0xa800000020060084, a3=a3 at entry (arg3).
  The return at 0xa800000020060060 has v0 = ret(cdl_del_driver).

- `pciio_driver_reg_callback` in `IP30/unix` at 0xa800000020060068 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060068-0xa800000020060084 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa800000020060070 calls pcibr_driver_reg_callback [0xa800000020043694] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002006007c has v0 = ret(pcibr_driver_reg_callback).

- `pciio_driver_unreg_callback` in `IP30/unix` at 0xa800000020060084 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060084-0xa8000000200600a0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002006008c calls pcibr_driver_unreg_callback [0xa80000002004373c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020060098 has v0 = ret(pcibr_driver_unreg_callback).

- `pciio_iterate` in `IP30/unix` at 0xa8000000200600a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200600a0-0xa8000000200600f0 (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xa8000000200600c4 calls cdl_iterate [0xa800000020097eec] with a0=[0xa8000000204a77e8]:8, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=?, a4=[0xa8000000204a77e8]:8.
  The `jal` at 0xa8000000200600dc calls pciio_init [0xa80000002005fefc] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a4=[0xa8000000204a77e8]:8.
  The `beq` branch at 0xa8000000200600b8 targets 0xa8000000200600dc, is taken when a4(=[0xa8000000204a77e8]:8) == 0, and falls through when a4(=[0xa8000000204a77e8]:8) != 0.
  The `beq` branch at 0xa8000000200600e8 targets 0xa8000000200600c0 and is always taken.
  The return at 0xa8000000200600d4 has v0 = ret(cdl_iterate).

- `pciio_device_register` in `IP30/unix` at 0xa8000000200600f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200600f0-0xa800000020060124 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0xa800000020060100 calls pciio_device_info_new [0xa800000020060140] with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002006010c calls pciio_device_info_register [0xa800000020060214] with a0=a0 at entry (arg0), a1=ret(pciio_device_info_new), a2=?, a3=?.
  The return at 0xa80000002006011c has v0 = ret(pciio_device_info_register).

- `pciio_device_unregister` in `IP30/unix` at 0xa800000020060124 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060124-0xa800000020060140 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa80000002006012c calls pcibr_device_unregister [0xa80000002004355c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020060138 has v0 = ret(pcibr_device_unregister).

- `pciio_device_info_new` in `IP30/unix` at 0xa800000020060140 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060140-0xa8000000200601f8 (184 bytes).
  It occupies 184 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xa80000002006018c, `sb` at 0xa800000020060190.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa800000020060194, `sw` at 0xa800000020060198, `sw` at 0xa80000002006019c.
  8 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa8000000200601ac, `sd` at 0xa8000000200601bc, `sd` at 0xa8000000200601c0.
  The `jal` at 0xa800000020060174 calls kmem_zalloc [0xa8000000201486a4] with a0=0x200, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200601a0 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=a1 at entry (arg1), a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200601b0 calls pciio_provider_fns_get [0xa80000002005ffa4] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `bne` branch at 0xa800000020060168 targets 0xa80000002006018c, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0xa8000000200601f0 has v0 = ?.

- `pciio_device_info_free` in `IP30/unix` at 0xa8000000200601f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200601f8-0xa800000020060214 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa800000020060200 calls blkclr [0xa80000002001738c] with a0=a0 at entry (arg0), a1=0x8, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa80000002006020c has v0 = ret(blkclr).

- `pciio_device_info_register` in `IP30/unix` at 0xa800000020060214 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060214-0xa8000000200602cc (184 bytes).
  It occupies 184 bytes.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x11, including `lbu` at 0xa800000020060220, `lbu` at 0xa800000020060298.
  The `lbu` at 0xa800000020060238 loads 1 byte from a1 (arg1 at entry) +0x12.
  The `sw` at 0xa80000002006026c stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `sw` at 0xa800000020060274 stores 4 bytes to a1 (arg1 at entry) +0xc.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x1c, including `lw` at 0xa800000020060284, `lw` at 0xa8000000200602b8.
  The `jal` at 0xa800000020060234 calls pciio_slot_func_to_name [0xa80000002005f724] with a0=sp-64, a1=[a1+17]:1, a2=[a1+18]:1, a3=a3 at entry (arg3).
  The `jal` at 0xa800000020060244 calls hwgraph_path_add [0xa80000002023cbbc] with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0xa80000002006027c calls pciio_info_set [0xa80000002005fda0] with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa800000020060288 calls device_master_set [0xa80000002023e1c0] with a0=?, a1=[a1+28], a2=?, a3=?.
  The `jal` at 0xa800000020060290 calls pciio_info_bus_get [0xa80000002005fe08] with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200602bc calls usrpci_device_register [0xa80000002005d23c] with a0=?, a1=[a1+28], a2=[a1+17]:1, a3=?.
  The `beq` branch at 0xa800000020060250 targets 0xa80000002006026c, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0xa8000000200602a0 targets 0xa8000000200602b0, is taken when a2(=[a1+17]:1) == v1(=0xff), and falls through when a2(=[a1+17]:1) != v1(=0xff).
  The `beq` branch at 0xa8000000200602a8 targets 0xa8000000200602b8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xa8000000200602b0 targets 0xa80000002006025c and is always taken.
  The `beq` branch at 0xa8000000200602c4 targets 0xa8000000200602b0 and is always taken.
  The return at 0xa800000020060264 has v0 = ?.

- `pciio_device_info_unregister` in `IP30/unix` at 0xa8000000200602cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200602cc-0xa800000020060348 (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0xa8000000200602e8 loads 1 byte from a1 (arg1 at entry) +0x12.
  The `lbu` at 0xa8000000200602ec loads 1 byte from a1 (arg1 at entry) +0x11.
  The `jal` at 0xa8000000200602f0 calls pciio_slot_func_to_name [0xa80000002005f724] with a0=sp-64, a1=[a1+17]:1, a2=[a1+18]:1, a3=a3 at entry (arg3), a4=a1 at entry (arg1).
  The `jal` at 0xa800000020060300 calls hwgraph_edge_remove [0xa80000002023c494] with a0=a0 at entry (arg0), a1=sp-64, a2=sp-32, a3=?.
  The `jal` at 0xa80000002006030c calls pciio_info_set [0xa80000002005fda0] with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020060314 calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020060328 calls hwgraph_edge_remove [0xa80000002023c494] with a0=?, a1=0xa8000000203b5bd0, a2=0x0, a3=?.
  The `jal` at 0xa800000020060330 calls hwgraph_vertex_unref [0xa80000002023c3a8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020060338 calls hwgraph_vertex_destroy [0xa80000002023c264] with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0xa8000000200602d8 targets 0xa8000000200602e8, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0xa800000020060340 targets 0xa8000000200602e0 and is always taken.
  The return at 0xa8000000200602e0 has v0 = one of ?, ret(hwgraph_vertex_destroy).

- `pciio_device_attach` in `IP30/unix` at 0xa8000000200603c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200603c0-0xa800000020060410 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0xa8000000200603e8 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0xa8000000200603f0 loads 4 bytes from ret(pciio_info_get) +0x18.
  The `jal` at 0xa8000000200603d4 calls (unnamed) [0xa800000020060348] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200603dc calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200603f4 calls cdl_add_connpt [0xa8000000200975a8] with a0=[0xa8000000204a77e8]:8, a1=[ret(pciio_info_get)+20], a2=[ret(pciio_info_get)+24], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0xa800000020060408 has v0 = ret(cdl_add_connpt).

- `pciio_device_detach` in `IP30/unix` at 0xa800000020060410 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060410-0xa800000020060460 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0xa800000020060438 loads 4 bytes from ret(pciio_info_get) +0x14.
  The `lw` at 0xa800000020060440 loads 4 bytes from ret(pciio_info_get) +0x18.
  The `jal` at 0xa800000020060424 calls (unnamed) [0xa800000020060394] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002006042c calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020060444 calls cdl_del_connpt [0xa800000020097b98] with a0=[0xa8000000204a77e8]:8, a1=[ret(pciio_info_get)+20], a2=[ret(pciio_info_get)+24], a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The return at 0xa800000020060458 has v0 = ret(cdl_del_connpt).

- `pciio_device_win_map_new` in `IP30/unix` at 0xa800000020060460 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060460-0xa8000000200604d4 (116 bytes).
  It occupies 116 bytes.
  The `sw` at 0xa8000000200604b4 stores 4 bytes to ?.
  The `sd` at 0xa8000000200604c0 stores 8 bytes to ?.
  The `jal` at 0xa800000020060488 calls kmem_zalloc [0xa8000000201486a4] with a0=0x10, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200604a8 calls rmallocmap [0xa80000002016a51c] with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0xa80000002006047c targets 0xa800000020060494, is taken when a0 != 0, and falls through when a0 == 0.
  The return at 0xa8000000200604cc has v0 = ?.

- `pciio_device_win_map_free` in `IP30/unix` at 0xa8000000200604d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200604d4-0xa800000020060508 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0xa8000000200604e8 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0xa8000000200604e4 calls rmfreemap [0xa80000002016a5dc] with a0=[a0]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200604f0 calls blkclr [0xa80000002001738c] with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The return at 0xa800000020060500 has v0 = ret(blkclr).

- `pciio_device_win_populate` in `IP30/unix` at 0xa800000020060508 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060508-0xa80000002006054c (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0xa800000020060508 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xa800000020060524 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0xa800000020060538 calls rmfree [0xa80000002016ade8] with a0=[a0]:8, a1=?, a2=?, a3=a3 at entry (arg3).
  The return at 0xa800000020060544 has v0 = ret(rmfree).

- `pciio_device_win_alloc` in `IP30/unix` at 0xa80000002006054c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002006054c-0xa800000020060638 (236 bytes).
  It occupies 236 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0xa80000002006054c, `lw` at 0xa8000000200605c4, `lw` at 0xa80000002006062c.
  The `ld` at 0xa80000002006055c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0xa8000000200605b8 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `sd` at 0xa8000000200605bc stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `sd` at 0xa8000000200605c0 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0xa8000000200605a8 calls rmalloc_reserve [0xa80000002016a9b8] with a0=[a0]:8, a1=?, a2=?, a3=0x0, a7=[a0+8].
  The `jal` at 0xa80000002006060c calls rmalloc_align [0xa80000002016a738] with a0=[a0]:8, a1=?, a2=?, a3=0x1, a7=[a0+8].
  The `beq` branch at 0xa800000020060584 targets 0xa8000000200605f0, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xa8000000200605b0 targets 0xa8000000200605c4, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0xa800000020060618 targets 0xa800000020060630, is taken when v0(=ret(rmalloc_align)) == a5(=-0x1), and falls through when v0(=ret(rmalloc_align)) != a5(=-0x1).
  The `bne` branch at 0xa800000020060620 targets 0xa8000000200605b8, is taken when s1(=a1) != 0, and falls through when s1(=a1) == 0.
  The `beq` branch at 0xa800000020060628 targets 0xa8000000200605c8 and is always taken.
  The `beq` branch at 0xa800000020060630 targets 0xa8000000200605d8 and is always taken.
  The return at 0xa8000000200605e8 has v0 = one of ?, 0x0.

- `pciio_device_win_free` in `IP30/unix` at 0xa800000020060638 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060638-0xa800000020060668 (48 bytes).
  It occupies 48 bytes.
  The `ld` at 0xa800000020060638 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xa80000002006064c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xa800000020060650 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xa800000020060658 loads 8 bytes from [a0]:8 +0x0.
  The `jal` at 0xa800000020060654 calls rmfree [0xa80000002016ade8] with a0=[[a0]:8]:8, a1=[a0+16]:8, a2=[a0+8]:8, a3=a3 at entry (arg3), a4=a0 at entry (arg0).
  The `beq` branch at 0xa800000020060644 targets 0xa80000002006065c, is taken when a1(=[a0+16]:8) == 0, and falls through when a1(=[a0+16]:8) != 0.
  The return at 0xa800000020060660 has v0 = one of ?, ret(rmfree).

- `pciio_error_register` in `IP30/unix` at 0xa800000020060668 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060668-0xa80000002006069c (52 bytes).
  It occupies 52 bytes.
  The `sd` at 0xa800000020060680 stores 8 bytes to ret(pciio_info_get) +0x38.
  The `sd` at 0xa800000020060698 stores 8 bytes to ret(pciio_info_get) +0x40.
  The `jal` at 0xa800000020060678 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020060694 has v0 = ret(pciio_info_get).

- `pciio_slot_inuse` in `IP30/unix` at 0xa80000002006069c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002006069c-0xa8000000200606d0 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0xa8000000200606ac loads 4 bytes from ret(pciio_info_get) +0x14.
  The `jal` at 0xa8000000200606a4 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa8000000200606b4 targets 0xa8000000200606c8, is taken when at(=[ret(pciio_info_get)+20]) == 0, and falls through when at(=[ret(pciio_info_get)+20]) != 0.
  The `beq` branch at 0xa8000000200606c8 targets 0xa8000000200606c0 and is always taken.
  The return at 0xa8000000200606c0 has v0 = one of 0x0, 0x1.

- `pciio_dma_enabled` in `IP30/unix` at 0xa8000000200606d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200606d0-0xa8000000200606ec (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xa8000000200606d8 calls pcibr_dma_enabled [0xa800000020046964] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa8000000200606e4 has v0 = ret(pcibr_dma_enabled).

- `pciio_info_type1_get` in `IP30/unix` at 0xa8000000200606ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200606ec-0xa8000000200606f4 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0xa8000000200606f0 loads 4 bytes from a0 (arg0 at entry) +0x1f8.
  The return at 0xa8000000200606ec has v0 = [a0+504].

- `pciio_businfo_get` in `IP30/unix` at 0xa8000000200606f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200606f4-0xa800000020060744 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xa800000020060708 loads 8 bytes from ret(pciio_info_get) +0x1f0.
  The `jal` at 0xa800000020060700 calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020060714 calls pciio_ppb_businfo_get [0xa80000002005f15c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020060724 calls pcibr_businfo_get [0xa800000020046bc0] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002006070c targets 0xa800000020060724, is taken when at(=[ret(pciio_info_get)+496]:8) == 0, and falls through when at(=[ret(pciio_info_get)+496]:8) != 0.
  The `beq` branch at 0xa80000002006071c targets 0xa800000020060730 and is always taken.
  The return at 0xa80000002006073c has v0 = one of ret(pciio_ppb_businfo_get), ret(pcibr_businfo_get).

- `pciio_latency_set` in `IP30/unix` at 0xa800000020060744 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020060744-0xa800000020060838 (244 bytes).
  It occupies 244 bytes.
  The `ld` at 0xa80000002006077c loads 8 bytes from ret(pciio_info_get) +0x1f0.
  The `ld` at 0xa800000020060790 loads 8 bytes from [ret(pciio_info_get)+496]:8 +0x8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa8000000200607b4, `ld` at 0xa8000000200607c0, `ld` at 0xa80000002006081c.
  The `jal` at 0xa80000002006075c calls pciio_info_get [0xa80000002005fd04] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020060774 calls pciio_config_set [0xa80000002005fba4] with a0=a0 at entry (arg0), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0xa80000002006079c calls pciio_config_get [0xa80000002005fa34] with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=?.
  The `jal` at 0xa8000000200607c4 calls pciio_info_dev_get [0xa80000002005fdf8] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000200607d8 calls pciio_config_get [0xa80000002005fa34] with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=?.
  The `jal` at 0xa8000000200607f8 calls pciio_config_set [0xa80000002005fba4] with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0xa800000020060810 calls pciio_config_set [0xa80000002005fba4] with a0=ret(pciio_info_dev_get), a1=0x1b, a2=0x1, a3=a1 at entry (arg1).
  The `beq` branch at 0xa800000020060784 targets 0xa800000020060820, is taken when s1(=[ret(pciio_info_get)+496]:8) == 0, and falls through when s1(=[ret(pciio_info_get)+496]:8) != 0.
  The `beq` branch at 0xa80000002006078c targets 0xa8000000200607c4 and is always taken.
  The `bne` branch at 0xa8000000200607ac targets 0xa800000020060808, is taken when at(?) < s0(=a1) (signed), and falls through when at(?) >= s0(=a1) (signed).
  The `beq` branch at 0xa8000000200607b8 targets 0xa800000020060820, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xa8000000200607e8 targets 0xa800000020060794, is taken when v0(?) >= s0(=a1) (signed), and falls through when v0(?) < s0(=a1) (signed).
  The `beq` branch at 0xa800000020060800 targets 0xa800000020060798 and is always taken.
  The `beq` branch at 0xa800000020060818 targets 0xa8000000200607b8 and is always taken.
  The return at 0xa800000020060830 has v0 = one of ret(pciio_config_set), ?.

- `ioc3_pckm_mlreset` in `IP30/unix` at 0xa800000020061a48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020061a48-0xa800000020061a94 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0xa800000020061a80 calls pckm_console_register [0xa80000002006a1ec] with a0=sp-64, a1=0xa800000020063334, a2=0xa800000020061a94, a3=a3 at entry (arg3).
  The return at 0xa800000020061a8c has v0 = ret(pckm_console_register).

- `intr_currently_using_urb` in `IP30/unix` at 0xa80000002006426c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002006426c-0xa800000020064278 (12 bytes).
  It occupies 12 bytes.
  The `lw` at 0xa80000002006426c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The return at 0xa800000020064270 has v0 = ?.

- `intr_is_done_using_urb` in `IP30/unix` at 0xa800000020064278 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020064278-0xa80000002006429c (36 bytes).
  It occupies 36 bytes.
  The `ll` at 0xa800000020064280 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sc` at 0xa800000020064288 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `beql` branch at 0xa80000002006428c targets 0xa800000020064280, is taken when (at(=[a0+4]) & v1(=-0x11)) == 0, and falls through when (at(=[a0+4]) & v1(=-0x11)) != 0; its branch-likely delay slot `nop` at 0xa800000020064290 runs only when taken and is annulled on fall-through.
  The return at 0xa800000020064294 has v0 = a0+4.

- `tg_free` in `IP30/unix` at 0xa8000000200b37c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200b37c4-0xa8000000200b3990 (460 bytes).
  It occupies 460 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x74, including `lw` at 0xa8000000200b37d0, `lw` at 0xa8000000200b38f4.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x100, including `ld` at 0xa8000000200b3804, `ld` at 0xa8000000200b3830.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa8000000200b3818, `ld` at 0xa8000000200b386c, `ld` at 0xa8000000200b38c0.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa8000000200b3848, `sd` at 0xa8000000200b389c, `sd` at 0xa8000000200b38f0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x90, including `ld` at 0xa8000000200b3858, `ld` at 0xa8000000200b3884.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x98, including `ld` at 0xa8000000200b38ac, `ld` at 0xa8000000200b38d8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x58, including `ld` at 0xa8000000200b3944, `ld` at 0xa8000000200b3978.
  The `jal` at 0xa8000000200b3828 calls m_freem [0xa80000002014bae4] with a0=?, a1=?, a2=?, a3=?, a5=[a0+256]:8.
  The `jal` at 0xa8000000200b387c calls m_freem [0xa80000002014bae4] with a0=?, a1=?, a2=?, a3=?, a6=[a0+144]:8.
  The `jal` at 0xa8000000200b38d0 calls m_freem [0xa80000002014bae4] with a0=?, a1=?, a2=?, a3=?, a7=[a0+152]:8.
  The `jal` at 0xa8000000200b394c calls ftrc_event [0xa8000000200b72ac] with a0=[a0+88]:8, a1=0x3, a2=0xa8000000203c0f68, a3=?, a6=0x0, a7=0x0.
  The `jal` at 0xa8000000200b3980 calls ftrc_event [0xa8000000200b72ac] with a0=[a0+88]:8, a1=0x0, a2=0xa8000000203c0f50, a3=0x0, a4=0x0, a5=0x0, a6=0x0, a7=0x0.
  The `beq` branch at 0xa8000000200b37ec targets 0xa8000000200b395c, is taken when at(=0x40) == v0(?), and falls through when at(=0x40) != v0(?).
  The `beq` branch at 0xa8000000200b3800 targets 0xa8000000200b3810 and is always taken.
  The `beq` branch at 0xa8000000200b3808 targets 0xa8000000200b384c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa8000000200b3820 targets 0xa8000000200b3808, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa8000000200b3844 targets 0xa8000000200b3800, is taken when s0(?) < 0x200 (signed), and falls through when s0(?) >= 0x200 (signed).
  The `beq` branch at 0xa8000000200b3854 targets 0xa8000000200b3864 and is always taken.
  The `beq` branch at 0xa8000000200b385c targets 0xa8000000200b38a0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xa8000000200b3874 targets 0xa8000000200b385c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa8000000200b3898 targets 0xa8000000200b3854, is taken when s0(?) < 0x200 (signed), and falls through when s0(?) >= 0x200 (signed).
  The `beq` branch at 0xa8000000200b38a8 targets 0xa8000000200b38b8 and is always taken.
  The `beq` branch at 0xa8000000200b38b0 targets 0xa8000000200b38f4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa8000000200b38c8 targets 0xa8000000200b38b0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa8000000200b38ec targets 0xa8000000200b38a8, is taken when s0(?) < 0x100 (signed), and falls through when s0(?) >= 0x100 (signed).
  The `beq` branch at 0xa8000000200b3900 targets 0xa8000000200b392c, is taken when a2(=0x40) == a3(?), and falls through when a2(=0x40) != a3(?).
  The `beq` branch at 0xa8000000200b3954 targets 0xa8000000200b390c and is always taken.
  The `beq` branch at 0xa8000000200b3988 targets 0xa8000000200b37f8 and is always taken.
  The return at 0xa8000000200b3924 has v0 = one of ?, ret(ftrc_event).

- `eg_st_bid_notify` in `IP30/unix` at 0xa8000000200b99e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200b99e8-0xa8000000200b9b14 (300 bytes).
  It occupies 300 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0xa8000000200b99f8, `ld` at 0xa8000000200b9a24.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x67c, including `sw` at 0xa8000000200b9a10, `sw` at 0xa8000000200b9a4c.
  The `lw` at 0xa8000000200b9a40 loads 4 bytes from [a0+816]:8 +0x67c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4cc, including `lw` at 0xa8000000200b9a50, `lw` at 0xa8000000200b9abc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4d0, including `lw` at 0xa8000000200b9a60, `lw` at 0xa8000000200b9acc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0xa8000000200b9a70, `lw` at 0xa8000000200b9adc.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0xa8000000200b9a84, `lh` at 0xa8000000200b9af0.
  The `jal` at 0xa8000000200b9a0c calls eg_docmd [0xa8000000200bcea4] with a0=a0 at entry (arg0), a1=0xf1, a2=a1 at entry (arg1), a3=0x0.
  The `jal` at 0xa8000000200b9a88 calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3478, a1=[a0+26]:2, a2=?, a3=?, a4=[[a0+816]:8+1660].
  The `jal` at 0xa8000000200b9a9c calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3730, a1=?, a2=[[a0+816]:8+1660], a3=?.
  The `jal` at 0xa8000000200b9af4 calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3478, a1=[a0+26]:2, a2=?, a3=?, a4=[[a0+816]:8+1660].
  The `jal` at 0xa8000000200b9b04 calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3700, a1=a1 at entry (arg1), a2=?, a3=?.
  The `beq` branch at 0xa8000000200b9a14 targets 0xa8000000200b9a24, is taken when v0(=ret(eg_docmd)) == 0, and falls through when v0(=ret(eg_docmd)) != 0.
  The `beq` branch at 0xa8000000200b9a1c targets 0xa8000000200b9aa8 and is always taken.
  The `beq` branch at 0xa8000000200b9a28 targets 0xa8000000200b9a40 and is always taken.
  The `beq` branch at 0xa8000000200b9a38 targets 0xa8000000200b9abc, is taken when s1(?) >= 0x2711 (signed), and falls through when s1(?) < 0x2711 (signed).
  The `beq` branch at 0xa8000000200b9a44 targets 0xa8000000200b9a30, is taken when a4(=[[a0+816]:8+1660]) == 0, and falls through when a4(=[[a0+816]:8+1660]) != 0.
  The `beq` branch at 0xa8000000200b9a58 targets 0xa8000000200b9aa8, is taken when (a0(=[a0+1228]) & 0x20) == 0, and falls through when (a0(=[a0+1228]) & 0x20) != 0.
  The `bne` branch at 0xa8000000200b9a68 targets 0xa8000000200b9aa8, is taken when a1(=[a0+1232]) < 0x9 (unsigned), and falls through when a1(=[a0+1232]) >= 0x9 (unsigned).
  The `beq` branch at 0xa8000000200b9a78 targets 0xa8000000200b9aa4, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0xa8000000200b9ac4 targets 0xa8000000200b9b0c, is taken when (a1(=[a0+1228]) & 0x20) == 0, and falls through when (a1(=[a0+1228]) & 0x20) != 0.
  The `bne` branch at 0xa8000000200b9ad4 targets 0xa8000000200b9b0c, is taken when a2(=[a0+1232]) < 0x4 (unsigned), and falls through when a2(=[a0+1232]) >= 0x4 (unsigned).
  The `beq` branch at 0xa8000000200b9ae4 targets 0xa8000000200b9b0c, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0xa8000000200b9b0c targets 0xa8000000200b9aa8 and is always taken.
  The return at 0xa8000000200b9ab4 has v0 = one of 0x0, 0x1.

- `ioc3_sio_mlreset` in `IP30/unix` at 0xa800000020142310 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020142310-0xa80000002014233c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xa800000020142328 calls sio_console_register [0xa80000002006a32c] with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa800000020142334 has v0 = ret(sio_console_register).

- `ioc3_serial_attach` in `IP30/unix` at 0xa800000020142a5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020142a5c-0xa800000020142f18 (1212 bytes).
  It occupies 1212 bytes.
  The `sd` at 0xa800000020142bb4 stores 8 bytes to ret(kmem_zalloc) +0x70.
  The `ld` at 0xa800000020142bb8 loads 8 bytes from ret(kmem_zalloc) +0x50.
  4 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x58, including `ld` at 0xa800000020142bbc, `ld` at 0xa800000020142be0, `ld` at 0xa800000020142c78.
  The `ld` at 0xa800000020142bc0 loads 8 bytes from ret(kmem_zalloc) +0x38.
  The `sd` at 0xa800000020142bc8 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sd` at 0xa800000020142bd4 stores 8 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0xa800000020142bec stores 8 bytes to ret(kmem_zalloc) +0x68.
  The `sd` at 0xa800000020142bf8 stores 8 bytes to ret(kmem_zalloc) +0x60.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x34, including `lw` at 0xa800000020142c04, `lw` at 0xa800000020142c18, `lw` at 0xa800000020142c24.
  The `sd` at 0xa800000020142c74 stores 8 bytes to ret(kmem_zalloc) +0x118.
  The `sd` at 0xa800000020142c7c stores 8 bytes to ret(kmem_zalloc) +0x100.
  The `ld` at 0xa800000020142c80 loads 8 bytes from ret(kmem_zalloc) +0xe0.
  The `ld` at 0xa800000020142c84 loads 8 bytes from ret(kmem_zalloc) +0xf8.
  The `sd` at 0xa800000020142c8c stores 8 bytes to ret(kmem_zalloc) +0xe8.
  The `sd` at 0xa800000020142c98 stores 8 bytes to ret(kmem_zalloc) +0xf0.
  The `sd` at 0xa800000020142ca4 stores 8 bytes to ret(kmem_zalloc) +0x108.
  The `sd` at 0xa800000020142cb0 stores 8 bytes to ret(kmem_zalloc) +0x110.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0xdc, including `lw` at 0xa800000020142cbc, `lw` at 0xa800000020142cd0, `lw` at 0xa800000020142cec.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa800000020142d38, `sw` at 0xa800000020142dc0, `sw` at 0xa800000020142dc8.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa800000020142d64, `sd` at 0xa800000020142d70, `sd` at 0xa800000020142d80.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa800000020142d98, `ld` at 0xa800000020142da0.
  The `lw` at 0xa800000020142df4 loads 4 bytes from ?.
  2 such `sb` accesses store 1 byte to ret(kmem_zalloc) +0x1d, including `sb` at 0xa800000020142e1c, `sb` at 0xa800000020142ea0.
  The `sd` at 0xa800000020142f04 stores 8 bytes to ret(kmem_zalloc) +0x58.
  The `jal` at 0xa800000020142a68 calls ioc3_subdev_enabled [0xa8000000200618e4] with a0=a0 at entry (arg0), a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020142a90 calls ioc3_subdev_enabled [0xa8000000200618e4] with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xa800000020142ab4 calls ioc3_subdev_enabled [0xa8000000200618e4] with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xa800000020142af4 calls pciio_piotrans_addr [0xa80000002005f220] with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x20180, a5=0x0.
  The `jal` at 0xa800000020142b00 calls ioc3_is_console [0xa8000000200613d0] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020142b18 calls hwgraph_traverse [0xa80000002023cd3c] with a0=a0 at entry (arg0), a1=0xa8000000203cb018, a2=sp-12, a3=?.
  The `jal` at 0xa800000020142b2c calls hwgraph_traverse [0xa80000002023cd3c] with a0=a0 at entry (arg0), a1=0xa8000000203cb020, a2=sp-176, a3=?.
  The `jal` at 0xa800000020142b34 calls hwgraph_fastinfo_get [0xa80000002023d638] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020142b44 calls kmem_zalloc [0xa8000000201486a4] with a0=0x150, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020142ba4 calls ioc3_subdev_enabled [0xa8000000200618e4] with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xa800000020142bd8 calls blkclr [0xa80000002001738c] with a0=?, a1=0x4000, a2=?, a3=?.
  The `jal` at 0xa800000020142bf4 calls (unnamed) [0xa80000002014288c] with a0=ret(kmem_zalloc), a1=ret(ioc3_is_console), a2=?, a3=?, a6=[ret(kmem_zalloc)+88]:8+4096.
  The `jal` at 0xa800000020142c08 calls hwgraph_edge_get [0xa80000002023c560] with a0=[ret(kmem_zalloc)+52], a1=0xa8000000203cb028, a2=sp-140, a3=?.
  The `jal` at 0xa800000020142c34 calls ioc3_intr_connect [0xa800000020060e68] with a0=a0 at entry (arg0), a1=0x1ff, a2=0xa800000020142454, a3=ret(kmem_zalloc), a4=[ret(kmem_zalloc)+52], a6=0x0.
  The `jal` at 0xa800000020142c44 calls device_controller_num_set [0xa80000002018ca48] with a0=[ret(kmem_zalloc)+52], a1=0x1, a2=?, a3=?.
  The `jal` at 0xa800000020142c4c calls sio_make_hwgraph_nodes [0xa80000002014622c] with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020142c60 calls ioc3_subdev_enabled [0xa8000000200618e4] with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xa800000020142cac calls (unnamed) [0xa80000002014288c] with a0=?, a1=0x0, a2=[ret(kmem_zalloc)+88]:8+8192, a3=[ret(kmem_zalloc)+88]:8+12288, a4=[ret(kmem_zalloc)+248]:8+368, a5=[ret(kmem_zalloc)+224]:8+212, a6=0xa80000002046a08c.
  The `jal` at 0xa800000020142cc0 calls hwgraph_edge_get [0xa80000002023c560] with a0=[ret(kmem_zalloc)+220], a1=0xa8000000203cb028, a2=sp-140, a3=?.
  The `jal` at 0xa800000020142cf0 calls ioc3_intr_connect [0xa800000020060e68] with a0=a0 at entry (arg0), a1=0x3fe00, a2=0xa800000020142454, a3=?, a4=[ret(kmem_zalloc)+220], a6=0x0.
  The `jal` at 0xa800000020142d00 calls device_controller_num_set [0xa80000002018ca48] with a0=[ret(kmem_zalloc)+220], a1=0x2, a2=?, a3=?.
  The `jal` at 0xa800000020142d08 calls sio_make_hwgraph_nodes [0xa80000002014622c] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa800000020142d5c calls device_inventory_add [0xa80000002018ca10] with a0=?, a1=0x4, a2=0x10, a3=-0x1, a4=0x0, a5=0x0.
  The `jal` at 0xa800000020142db4 calls hwgraph_path_add [0xa80000002023cbbc] with a0=a0 at entry (arg0), a1=?, a2=sp-148, a3=?.
  The `jal` at 0xa800000020142dd4 calls hwgraph_fastinfo_set [0xa80000002023d608] with a0=?, a1=?, a2=?, a3=a0 at entry (arg0).
  The `jal` at 0xa800000020142df8 calls sio_initport [0xa800000020144ba4] with a0=?, a1=?, a2=0x1ff, a3=one of 0x0, 0x1.
  The `jal` at 0xa800000020142e04 calls kmem_zalloc [0xa8000000201486a4] with a0=0x28, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa800000020142e20 calls sio_init_locks [0xa8000000201442e0] with a0=ret(kmem_zalloc), a1=?, a2=one of 0x2, 0x3, a3=?.
  The `jal` at 0xa800000020142e44 calls hwgraph_edge_get [0xa80000002023c560] with a0=?, a1=0xa8000000203cb028, a2=sp-144, a3=?, a4=0x2580.
  The `jal` at 0xa800000020142e68 calls kopt_find [0xa8000000201d7804] with a0=one of 0xa8000000203cb030, 0xa8000000203cb038, a1=?, a2=?, a3=0x1.
  The `jal` at 0xa800000020142e78 calls atoi [0xa800000020128cfc] with a0=ret(kopt_find), a1=?, a2=0x1, a3=?.
  The `jal` at 0xa800000020142eb4 calls ioc3_subdev_enabled [0xa8000000200618e4] with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xa800000020142edc calls printf [0xa8000000201c78ec] with a0=0xa8000000203cafd8, a1=?, a2=0x1, a3=?.
  The `jal` at 0xa800000020142ef4 calls kvpalloc [0xa80000002017086c] with a0=0x1, a1=0x100, a2=0x0, a3=?, a4=[ret(kmem_zalloc)+56]:8+184, a5=[ret(kmem_zalloc)+80]:8+376.
  The `jal` at 0xa800000020142f08 calls panic [0xa8000000201c7be8] with a0=0xa8000000203caff0, a1=?, a2=?, a3=?.
  The `beq` branch at 0xa800000020142a84 targets 0xa800000020142eb0, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xa800000020142aa0 targets 0xa800000020142ecc, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xa800000020142abc targets 0xa800000020142adc, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `bne` branch at 0xa800000020142b64 targets 0xa800000020142b88, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(=one of -0x1, 0x0, 0x1) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(=one of -0x1, 0x0, 0x1) (signed).
  The `beq` branch at 0xa800000020142b80 targets 0xa800000020142d84 and is always taken.
  The `beq` branch at 0xa800000020142bac targets 0xa800000020142c5c, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xa800000020142bd0 targets 0xa800000020142eec, is taken when a0(=[ret(kmem_zalloc)+88]:8) == 0, and falls through when a0(=[ret(kmem_zalloc)+88]:8) != 0.
  The `beq` branch at 0xa800000020142c10 targets 0xa800000020142c20, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xa800000020142c3c targets 0xa800000020142c58, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xa800000020142c68 targets 0xa800000020142d14, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xa800000020142cc8 targets 0xa800000020142cd8, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xa800000020142cf8 targets 0xa800000020142d10, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xa800000020142d40 targets 0xa800000020142ed4, is taken when s0(?) == a2(=0x1), and falls through when s0(?) != a2(=0x1).
  The `bne` branch at 0xa800000020142d7c targets 0xa800000020142b88, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(?) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(?) (signed).
  The `beq` branch at 0xa800000020142ddc targets 0xa800000020142df0, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xa800000020142de4 targets 0xa800000020142e90, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa800000020142e0c targets 0xa800000020142e18, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xa800000020142e14 targets 0xa800000020142e98, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa800000020142e30 targets 0xa800000020142d48, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xa800000020142e54 targets 0xa800000020142ea4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xa800000020142e5c targets 0xa800000020142d48, is taken when s0(?) != a3(=0x1), and falls through when s0(?) == a3(=0x1).
  The `beq` branch at 0xa800000020142e70 targets 0xa800000020142d40, is taken when v0(=ret(kopt_find)) == 0, and falls through when v0(=ret(kopt_find)) != 0.
  The `bgtz` branch at 0xa800000020142e80 targets 0xa800000020142d38, is taken when v0(=ret(atoi)) > 0 (signed), and falls through when v0(=ret(atoi)) <= 0 (signed).
  The `beq` branch at 0xa800000020142e88 targets 0xa800000020142d40 and is always taken.
  The `beq` branch at 0xa800000020142e90 targets 0xa800000020142df4 and is always taken.
  The `beq` branch at 0xa800000020142e9c targets 0xa800000020142e20 and is always taken.
  The `beq` branch at 0xa800000020142ea8 targets 0xa800000020142e68 and is always taken.
  The `bne` branch at 0xa800000020142ebc targets 0xa800000020142a90, is taken when v0(=ret(ioc3_subdev_enabled)) != 0, and falls through when v0(=ret(ioc3_subdev_enabled)) == 0.
  The `beq` branch at 0xa800000020142ec4 targets 0xa800000020142d14 and is always taken.
  The `beq` branch at 0xa800000020142ecc targets 0xa800000020142ab0 and is always taken.
  The `beq` branch at 0xa800000020142ed4 targets 0xa800000020142ee4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xa800000020142ee4 targets 0xa800000020142d48 and is always taken.
  The `bne` branch at 0xa800000020142f00 targets 0xa800000020142bd8, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0xa800000020142f10 targets 0xa800000020142bd8 and is always taken.
  The return at 0xa800000020142d30 has v0 = one of -0x1, 0x0.

- `ioc3_serial_kill` in `IP30/unix` at 0xa800000020142f18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020142f18-0xa800000020142f58 (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0xa800000020142f18 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xa800000020142f30 loads 8 bytes from [a0+8]:8 +0x28.
  The `ld` at 0xa800000020142f3c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0xa800000020142f44 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0xa800000020142f48 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `jalr` at 0xa800000020142f34 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `beq` branch at 0xa800000020142f28 targets 0xa800000020142f3c, is taken when a2(=[a0+8]:8) == 0, and falls through when a2(=[a0+8]:8) != 0.
  The return at 0xa800000020142f50 has v0 = [a0+64]:8.

- `random_write_internal` in `IP30/unix` at 0xa800000020156254 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020156254-0xa800000020156334 (224 bytes).
  It occupies 224 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0xa800000020156298, `ld` at 0xa8000000201562f8.
  The `jal` at 0xa80000002015629c calls random_harvest_internal [0xa80000002015612c] with a0=[0xffffffffaff20000]:8, a1=?, a2=0x10, a3=0x10, a4=0x0, a5=0x0.
  The `jal` at 0xa8000000201562f4 calls random_harvest_internal [0xa80000002015612c] with a0=[0xffffffffaff20000]:8, a1=?, a2=?, a3=0x0, a4=0x0, a5=0x0.
  The `blez` branch at 0xa800000020156278 targets 0xa800000020156318, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `bne` branch at 0xa8000000201562ac targets 0xa80000002015628c, is taken when s0(?) < s2(=a1) (signed), and falls through when s0(?) >= s2(=a1) (signed).
  The `beq` branch at 0xa8000000201562b8 targets 0xa8000000201562c8, is taken when s2(=a1) >= s0(?) (signed), and falls through when s2(=a1) < s0(?) (signed).
  The `beq` branch at 0xa8000000201562dc targets 0xa8000000201562fc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0xa800000020156318 targets 0xa800000020156328, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0xa800000020156320 targets 0xa8000000201562c8 and is always taken.
  The `beq` branch at 0xa80000002015632c targets 0xa8000000201562c4 and is always taken.
  The return at 0xa800000020156310 has v0 = one of ?, ret(random_harvest_internal).

- `do_mprboot` in `IP30/unix` at 0xa8000000201c8f44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000201c8f44-0xa8000000201c9060 (284 bytes).
  It occupies 284 bytes.
  2 such `lw` accesses load 4 bytes from abs 0xa8000000204fe5f0, including `lw` at 0xa8000000201c8f84, `lw` at 0xa8000000201c8fe8.
  The `sw` at 0xa8000000201c8f94 stores 4 bytes to abs 0xa8000000204fe5f0.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc3a0, including `lh` at 0xa8000000201c8f9c, `lh` at 0xa8000000201c904c.
  The `lh` at 0xa8000000201c8fa0 loads 2 bytes from [0xa8000000204af8c0]:8 +0x3a0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0xa8000000201c8fc4, `ld` at 0xa8000000201c9010.
  The `ld` at 0xa8000000201c9020 loads 8 bytes from abs 0xa8000000204fe5f8.
  The `jal` at 0xa8000000201c8f78 calls mutex_spinlock [0xa80000002022d954] with a0=0xa8000000204fe600, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000201c8f90 calls mutex_spinunlock [0xa80000002022d9a0] with a0=0xa8000000204fe600, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xa8000000201c8fe0 calls us_delay [0xa800000020011640] with a0=0x186a0, a1=?, a2=?, a3=?, a6=[0xffffffffaff20000]:8.
  The `jal` at 0xa8000000201c9000 calls conbuf_flush [0xa8000000201c8af4] with a0=0x3, a1=?, a2=?, a3=?, a4=[0xa8000000204a81e4].
  The `jalr` at 0xa8000000201c9028 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a7=[0xa8000000204fe5f8]:8.
  The `jal` at 0xa8000000201c9050 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203d5cf8, a2=[-0x3c60]:2, a3=a3 at entry (arg3).
  The `bne` branch at 0xa8000000201c8f64 targets 0xa8000000201c8f70, is taken when at(=[0xa8000000204a6814]) < 0x2 (signed), and falls through when at(=[0xa8000000204a6814]) >= 0x2 (signed).
  The `beq` branch at 0xa8000000201c8f6c targets 0xa8000000201c9044, is taken when a2(=[0xa8000000204afb30]) == 0, and falls through when a2(=[0xa8000000204afb30]) != 0.
  The `bne` branch at 0xa8000000201c8fb0 targets 0xa8000000201c9020, is taken when v1(=[-0x3c60]:2) != a1(=[[0xa8000000204af8c0]:8+928]:2), and falls through when v1(=[-0x3c60]:2) == a1(=[[0xa8000000204af8c0]:8+928]:2).
  The `beq` branch at 0xa8000000201c8fd8 targets 0xa8000000201c8ff4 and is always taken.
  The `beq` branch at 0xa8000000201c8fec targets 0xa8000000201c9020, is taken when a3(=[0xa8000000204fe5f0]) == 0, and falls through when a3(=[0xa8000000204fe5f0]) != 0.
  The `beq` branch at 0xa8000000201c8ff8 targets 0xa8000000201c900c, is taken when a4(=[0xa8000000204a81e4]) == 0, and falls through when a4(=[0xa8000000204a81e4]) != 0.
  The `beq` branch at 0xa8000000201c9018 targets 0xa8000000201c8fe0, is taken when a5(?) >= a6(=[0xffffffffaff20000]:8) (unsigned), and falls through when a5(?) < a6(=[0xffffffffaff20000]:8) (unsigned).
  The `beq` branch at 0xa8000000201c9058 targets 0xa8000000201c8f74 and is always taken.
  The return at 0xa8000000201c903c has v0 = ret(?).

- `ktimer_init` in `IP30/unix` at 0xa8000000201fc4b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000201fc4b8-0xa8000000201fc4d0 (24 bytes).
  It occupies 24 bytes.
  The `sw` at 0xa8000000201fc4b8 stores 4 bytes to a0 (arg0 at entry) +0x2e0.
  The `ld` at 0xa8000000201fc4c0 loads 8 bytes from abs 0xffffffffaff20000.
  The `sw` at 0xa8000000201fc4c4 stores 4 bytes to a0 (arg0 at entry) +0x2e4.
  The `sd` at 0xa8000000201fc4cc stores 8 bytes to a0 (arg0 at entry) +0x2d8.
  The return at 0xa8000000201fc4c8 has v0 = ?.

- `ktimer_switch` in `IP30/unix` at 0xa8000000201fc4d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000201fc4d0-0xa8000000201fc508 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0xa8000000201fc4d0 loads 4 bytes from a0 (arg0 at entry) +0x2e0.
  The `ld` at 0xa8000000201fc4d4 loads 8 bytes from a0 (arg0 at entry) +0x2d8.
  The `ld` at 0xa8000000201fc4dc loads 8 bytes from abs 0xffffffffaff20000.
  The `sw` at 0xa8000000201fc4e4 stores 4 bytes to a0 (arg0 at entry) +0x2e4.
  The `ld` at 0xa8000000201fc4ec loads 8 bytes from (a0 + ([a0+736] << 0x3)) +0x280.
  The `sd` at 0xa8000000201fc4f8 stores 8 bytes to (a0 + ([a0+736] << 0x3)) +0x280.
  The `sd` at 0xa8000000201fc4fc stores 8 bytes to a0 (arg0 at entry) +0x2d8.
  The `sw` at 0xa8000000201fc504 stores 4 bytes to a0 (arg0 at entry) +0x2e0.
  The return at 0xa8000000201fc500 has v0 = ?.

- `ktimer_readticks` in `IP30/unix` at 0xa8000000201fc508 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000201fc508-0xa8000000201fc56c (100 bytes).
  It occupies 100 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2d8, including `ld` at 0xa8000000201fc51c, `ld` at 0xa8000000201fc534.
  The `ld` at 0xa8000000201fc520 loads 8 bytes from (a0 + (a1 << 0x3)) +0x280.
  The `lw` at 0xa8000000201fc524 loads 4 bytes from a0 (arg0 at entry) +0x2e0.
  The `ld` at 0xa8000000201fc530 loads 8 bytes from abs 0xffffffffaff20000.
  The `lw` at 0xa8000000201fc538 loads 4 bytes from a0 (arg0 at entry) +0x2e4.
  The `bne` branch at 0xa8000000201fc528 targets 0xa8000000201fc564, is taken when t0(=[a0+736]) != a1, and falls through when t0(=[a0+736]) == a1.
  The `bne` branch at 0xa8000000201fc54c targets 0xa8000000201fc51c, is taken when a4(=[a0+728]:8) != t1(?), and falls through when a4(=[a0+728]:8) == t1(?).
  The return at 0xa8000000201fc55c has v0 = ?.
  The return at 0xa8000000201fc564 has v0 = [(a0 + (a1 << 0x3))+640]:8.

- `ktimer_slptime` in `IP30/unix` at 0xa8000000201fc608 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000201fc608-0xa8000000201fc650 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xa8000000201fc608 loads 4 bytes from a0 (arg0 at entry) +0x2e0.
  The `ld` at 0xa8000000201fc62c loads 8 bytes from a0 (arg0 at entry) +0x2d8.
  The `ld` at 0xa8000000201fc630 loads 8 bytes from abs 0xffffffffaff20000.
  The `beq` branch at 0xa8000000201fc614 targets 0xa8000000201fc648, is taken when v0(=[a0+736]) == 0, and falls through when v0(=[a0+736]) != 0.
  The `beq` branch at 0xa8000000201fc61c targets 0xa8000000201fc648, is taken when v0(=[a0+736]) == a3(=0x1), and falls through when v0(=[a0+736]) != a3(=0x1).
  The `beq` branch at 0xa8000000201fc624 targets 0xa8000000201fc648, is taken when v0(=[a0+736]) == a4(=0x2), and falls through when v0(=[a0+736]) != a4(=0x2).
  The return at 0xa8000000201fc640 has v0 = ?.
  The return at 0xa8000000201fc648 has v0 = 0x0.

- `gfx_flow_init` in `IP30/unix` at 0xa80000002038f230 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002038f230-0xa80000002038f270 (64 bytes).
  It occupies 64 bytes.
  The `sd` at 0xa80000002038f258 stores 8 bytes to abs 0xffffffffaff00040.
  The `jal` at 0xa80000002038f23c calls kmem_zalloc [0xa8000000201486a4] with a0=0x18, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002038f25c calls spinlock_init [0xa80000002022d728] with a0=0xa8000000204b0024, a1=0xa80000002041c9b0, a2=0x45, a3=0xffffffffaff00000.
  The return at 0xa80000002038f268 has v0 = ret(spinlock_init).

- `gfx_flow_pipe_head_init` in `IP30/unix` at 0xa80000002038f270 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002038f270-0xa80000002038f318 (168 bytes).
  It occupies 168 bytes.
  The `lh` at 0xa80000002038f278 loads 2 bytes from abs 0xffffffffffffc3a0.
  The `sw` at 0xa80000002038f27c stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `sd` at 0xa80000002038f290 stores 8 bytes to ([0xa8000000204a8620]:8 + ([-0x3c60]:2 << 0x3)) +0x0.
  The `lwu` at 0xa80000002038f298 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `sd` at 0xa80000002038f2a0 stores 8 bytes to abs 0xffffffffaff00048.
  The `lwu` at 0xa80000002038f2a8 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `sd` at 0xa80000002038f2ac stores 8 bytes to ([-0x3c60]:2 << 0x3) -0x500fffa0.
  The `ld` at 0xa80000002038f2b4 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xa80000002038f2bc loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0xa80000002038f2dc stores 8 bytes to ([-0x3c60]:2 << 0x3) -0x500fffb0.
  The `ld` at 0xa80000002038f2f0 loads 8 bytes from abs 0xffffffffaff00040.
  The `sd` at 0xa80000002038f304 stores 8 bytes to abs 0xffffffffaff00040.
  The `jal` at 0xa80000002038f2d8 calls mutex_spinlock [0xa80000002022d954] with a0=0xa8000000204b0024, a1=0xffffffff80, a2=0xffffe0, a3=[a0+28], a4=([0xa8000000204a8620]:8 + ([-0x3c60]:2 << 0x3)).
  The `jal` at 0xa80000002038f300 calls mutex_spinunlock [0xa80000002022d9a0] with a0=0xa8000000204b0024, a1=ret(mutex_spinlock), a2=?, a3=?, a6=0xffffffffaff00000.
  The return at 0xa80000002038f310 has v0 = ret(mutex_spinunlock).

- `gfx_flow_credit_count_get` in `IP30/unix` at 0xa80000002038f684 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002038f684-0xa80000002038f6a8 (36 bytes).
  It occupies 36 bytes.
  The `lwu` at 0xa80000002038f684 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0xa80000002038f698 loads 8 bytes from ([a0+88] << 0x3) -0x500fffa0.
  The return at 0xa80000002038f6a0 has v0 = (([([a0+88] << 0x3)-1343225760]:8 << 0x3) << 0x0).

- `gfx_flow_credit_count_set` in `IP30/unix` at 0xa80000002038f6a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002038f6a8-0xa80000002038f6d4 (44 bytes).
  It occupies 44 bytes.
  The `sw` at 0xa80000002038f6ac stores 4 bytes to a0 (arg0 at entry) +0x1c.
  The `lh` at 0xa80000002038f6b0 loads 2 bytes from abs 0xffffffffffffc3a0.
  The `sd` at 0xa80000002038f6d0 stores 8 bytes to ([-0x3c60]:2 << 0x3) -0x500fffa0.
  The return at 0xa80000002038f6cc has v0 = ([-0x3c60]:2 << 0x3)+0xffffffffaff00060.
